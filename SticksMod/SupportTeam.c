int SM_SupportTeamSkipFrame = 0;
int SM_totalFighters = 0;
int SM_ShipCrewBeforeBoarding = 0;
bool SM_battleActive = false;
bool SM_leftShip = false;
bool SM_landVisited = false; // для старых сейвов
bool SM_removeAfterUnload = false;
string SM_skippedLoc[15];



// инициализация
void SM_SupportTeamInit()
{
	
	// пропускаем некоторые локи, на которых солдатня не нужна
	SM_skippedLoc[0] = "Cabin"; // new!!! - по просьбе трудящихся, теперь в каюте кэпа 1х1
	SM_skippedLoc[1] = "My_Campus"; // new!!! - а тут игнорим только собственные каюты
	SM_skippedLoc[2] = "_store";
	SM_skippedLoc[3] = "_tavern_upstairs";
	SM_skippedLoc[4] = "_Bank";
	SM_skippedLoc[5] = "_TownhallRoom";
	SM_skippedLoc[6] = "_PortOffice";
	SM_skippedLoc[7] = "_Packhouse";
	SM_skippedLoc[8] = "_church";
	SM_skippedLoc[9] = "_prison";
	SM_skippedLoc[10] = "_KeepersHouse";
	SM_skippedLoc[11] = "_Lighthouseroom";
	SM_skippedLoc[12] = "_bedroom";
	SM_skippedLoc[13] = "_Brothel";
	SM_skippedLoc[14] = "_SecBrRoom";
	
}



// Загрузились с сэйва, повесим слушатели
void SM_SupportTeamOnLoad()
{
	
	if (!CheckAttribute(pchar, "SupportTeamType"))
		return;
	
	SM_SupportTeamSkipFrame = 50;
	SM_battleActive = false;
	
	//SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	SetEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad", 0);
	SetEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload", 0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState", 0);
	
	//Log_info("SM_OnGameLoad!");
}



// Генерация и привязка заданного числа нпс к гг (n - солдаты, m - мушкетеры)
void SM_AddSupportTeam(int n, int m)
{	
	if (SM_totalFighters)
		SM_RemoveSupportTeamImmediately(false); // на всякий случай, если остались гуляки от предыдущего отряда
	
	// количество до сбора отряда
	// SM_ShipCrewBeforeBoarding = GetCrewQuantity(pchar);
	
	SM_totalFighters = n + m;
	
	AddCharacterCrew(pchar, -SM_totalFighters);
	
	int crewType;
	string  smodel;
	string  ani;
	
	float locx, locy, locz;
	GetCharacterPos(pchar, &locx, &locy, &locz);
	
	int iRank = pchar.rank + 2; // ранг нпс
	
	int weaponQuantity = sti(GetCargoGoods(pchar, GOOD_WEAPON)); // считаем, скока единиц оружия в трюме
	int goodItemsMultipler = 1.0; // множитель для числа солдат, если единиц оружия в трюме больше произведения, то можем отыскать там хорошие вещи + легкие допехи
	int bestItemsMultipler = 2.0; // множитель для числа солдат, если единиц оружия в трюме больше произведения, то можем отыскать там отличные вещи + тяжелые доспехи
	bool mushketerSuccess; // удалось ли создать мушкетера
	
	int powderQuantity = sti(GetCargoGoods(pchar, GOOD_POWDER)); // ищем порох
	float powderPerSld = 10.0; // для пистоля или мушкета требуется порохъ
	int powderAndBullets = 10; // минимальное кол-во зарядов (далее увеличивается)
	
	object vpistols; // варианты пистолей
	object vmushkets; // варианты мушкетов
	object vcirasses; // варианты брони
	object vblades; // варианты сабель
	
	int crewQuantity = GetCrewQuantity(pchar); // текущая численность команды
	int medicamentQuantity = sti(GetCargoGoods(pchar, GOOD_MEDICAMENT)); // считаем, скока единиц лекарств в трюме
	int goodHpMultipler = 2; // множитель для числа матросов в команде, если лекарств в трюме больше произведения, то + к ХП + большие элексиры
	int bestIHpMultipler = 3; // множитель для числа матросов в команде, если лекарств в трюме больше произведения, то ++ к ХП + большие элексиры
	
	float bonusHpMultiper = 1; // бонус к ХП
	int potions = 0; // колво лечилок
	string potionType = ""; // тип лечилок
	int itemsPerSld = 0; // сколько единиц лекарств выделится на чел из трюма.
	
	int rumQuantity = sti(GetCargoGoods(pchar, GOOD_RUM)); // есть ли ром (для доп лечилок - ром)
	int rum = 0; // ром (доп лечилка)
	float rumPerSld = 0.5; // на 1 чел по 50% от бочки
	int wineQuantity = sti(GetCargoGoods(pchar, GOOD_WINE)); // есть ли вино (для доп лечилок - винище)
	int wine = 0; // вино (доп лечилка)
	float winePerSld = 0.5; // на 1 чел по 50% от бочки


	// 1. в трюме мало таблеток, выдаем всего 2 лечилки и штраф к ХП
	if (medicamentQuantity < crewQuantity)
	{
		bonusHpMultiper = 0.5;
		potions = 2;
		potionType = "potion1";
		itemsPerSld = 1;
	}
	
	// 2. таблетки есть на всех. даем лечилки и стандартное ХП
	if (medicamentQuantity >= crewQuantity)
	{
		bonusHpMultiper = 1.0;
		potions = 8;
		potionType = "potion1";
		itemsPerSld = 4;
	}
	
	// 3. лекарств много, сильные лечилки + бонус к ХП
	if (medicamentQuantity > crewQuantity * goodHpMultipler)
	{
		bonusHpMultiper = 2.0;
		potions = 8;
		potionType = "potion2";
		itemsPerSld = 8;
	}
	
	// 4. лекарств очень много, 
	if (medicamentQuantity > crewQuantity * bestIHpMultipler)
	{
		bonusHpMultiper = 3.0;
		potions = 16;
		potionType = "potion2";
		itemsPerSld = 16;
	}
	
	// 5. если есть ром, берем и его
	if (rumQuantity/crewQuantity * 10 > SM_totalFighters * rumPerSld)
	{
		rum = 5;
	}

	// 6. если есть вино, берем и его
	if (wineQuantity/crewQuantity * 10 > SM_totalFighters * winePerSld)
	{
		wine = 5;
	}
	
	// 7. проверяем порох, если нет, то выдаем лишь на несколько выстрелов, иначе на полсотни
	if (powderQuantity > crewQuantity * powderPerSld)
	{
		powderAndBullets = 50;
	}
	
	// 8. Нет снаряги
	if (weaponQuantity < SM_totalFighters)
	{
		vblades.b0 = "slave_01"; // гарпун
		vblades.b1 = "slave_02"; // мачете
		vblades.b2 = "topor_05"; // томагавк
		vmushkets.m0 = "mushket3"; vmushkets.b0 = "grapeshot"; // фитильный дробовик
		SM_RemoveSupportTeam();
		Log_info("Недостаточно припасов для сбора отряда!");
	}
	
	// 9. обычное оружие имеется
	if (weaponQuantity >= SM_totalFighters)
	{
		vblades.b0 = "blade_03"; // Стокката
		vblades.b1 = "newblade11"; // Кортик
		vblades.b2 = "newblade2"; // Венецианская шпага
		vblades.b3 = "newblade3"; // Кайман
		vblades.b4 = "newblade4"; // Пехотная сабля
		vblades.b5 = "newblade1"; // Канонирский тесак
		vblades.b6 = "topor_05"; // Томагавк
		vblades.b7 = "topor_07"; // Костолом
		vblades.b8 = "blade_07"; // Риттершверт
		vblades.b9 = "newblade23"; // Дюсак

		vcirasses.c0 = "cirass5"; // ремень

		vpistols.g0 = "pistol3"; vpistols.b0 = "grapeshot"; 			// картечница
		vmushkets.m0 = "mushket_01"; vmushkets.b0 = "grapeshot"; // карабин
	}
	
	// 10. нашли хорошее оружие и вещи
	if (weaponQuantity/crewQuantity * 6.5 > SM_totalFighters * goodItemsMultipler)
	{
		vblades.b0 = "blade_08"; // Бильбо
		vblades.b1 = "blade_09"; // Карцолета
		vblades.b2 = "newblade8"; // Сарагосса
		vblades.b3 = "blade_04"; // Госсемесер
		vblades.b4 = "blade_05"; // Катлас
		vblades.b5 = "blade_10"; // Корд
		vblades.b6 = "blade_11"; // Абордажный тесак
		vblades.b7 = "blade_12"; // Полусабля
		vblades.b8 = "blade50"; // Кривой Меч 
		vblades.b9 = "newblade6"; // Висельник
		vblades.b10 = "newblade7"; // Катцбальтер
		vblades.b11 = "newblade10"; // Кавалерийская сабля
		vblades.b12 = "topor_02"; // Бартакс
		vblades.b13 = "topor_03"; // Годендаг
		vblades.b14 = "topor_012"; // Морской топор
		vblades.b15 = "topor_013"; // Клевец
		vblades.b16 = "topor_014"; // Абордажный топор
		vblades.b17 = "blade_14"; // Валлонская шпага
		vblades.b18 = "newblade19"; // Эсток
		vblades.b19 = "newblade5"; // Кортелач
		vblades.b20 = "newblade9"; // Рейтарский палаш
		vblades.b21 = "newblade27"; // Малкус

		vcirasses.c0 = "cirass6"; // жилет бретера
		vcirasses.c1 = "cirass2"; // рейтарская кираса
		
		vpistols.g0 = "pistol_03"; vpistols.b0 = "grapeshot"; 		// тромбон
		vmushkets.m0 = "mushket3"; vmushkets.b0 = "grapeshot"; // аркебуза
	}
	
	// 11. нашли отличные шмотки
	if (weaponQuantity/crewQuantity * 9.0 > SM_totalFighters * bestItemsMultipler)
	{
		vblades.b0 = "blade_15"; // Маринера
		vblades.b1 = "blade_16"; // Смоллсворд
		vblades.b2 = "newblade13"; // Нобиль
		vblades.b3 = "topor_04"; // Секира
		vblades.b4 = "blade_13"; // Офицерский палаш
		vblades.b5 = "newblade12"; // Скаллоп
		vblades.b6 = "newblade14"; // Хаудеген
		vblades.b7 = "newblade15"; // Бастард
		vblades.b8 = "newblade24"; // Голландская сабля
		vblades.b9 = "newblade25"; // Испанская сабля
		vblades.b10 = "newblade26"; // Ятаган
		vblades.b11 = "newblade28"; // Самзир
		
		vcirasses.c0 = "cirass1"; // траншейный доспех
		vcirasses.c1 = "cirass7"; // бригант
		
		
		vpistols.g0 = "pistol2"; vpistols.b0 = "grapeshot"; 			// 3-х ствольный пистолет
		vpistols.g1 = "pistol02"; vpistols.b1 = "grapeshot"; 			// Гауда
		vpistols.g2 = "pistol_08"; vpistols.b2 = "grapeshot"; 		// Абордажный Мушкетон
		vmushkets.m0 = "Mushket_8"; vmushkets.b0 = "grapeshot"; // Дондербасс
	}
	
	// 12. тип абордажной команды (внешний вид матросов)
	crewType = 0;
	if (CheckAttribute(pchar, "GenQuest.BoardCrewType"))
		crewType = pchar.GenQuest.BoardCrewType;
	
	// 13. рукопашные солдаты
	for (i = 0; i < n; i++)
	{
		CSM_GetModelByCrewType(crewType, &smodel, &ani, false);
		sld = GetCharacter(NPC_GenerateCharacter("SM_Support_sold_"+ i, smodel, "man", ani, iRank, PIRATE, -1, true, "soldier"));
		sld.SuperShooter = true;
		SelAllPerksToChar(sld, false);
		
		SM_EquipSupport(sld, vblades, vcirasses, vpistols, powderAndBullets, bonusHpMultiper, potions, potionType, rum, wine, false);
		SM_ApplyFirstAISettings(sld);
		
		if (!SM_NeedToSkipLocation()) // если не в каюте
		{
			ChangeCharacterAddressGroup(sld, loadedLocation.id, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	// 14. мушкетеры
	for (i = n; i < SM_totalFighters; i++)
	{
		mushketerSuccess = CSM_GetModelByCrewType(crewType, &smodel, &ani, true);
		sld = GetCharacter(NPC_GenerateCharacter("SM_Support_sold_"+ i, smodel, "man", ani, iRank, PIRATE, -1, true, "soldier"));
		sld.SuperShooter = true;
		SelAllPerksToChar(sld, false);
	
		SM_EquipSupport(sld, vblades, vcirasses, vmushkets, powderAndBullets, bonusHpMultiper, potions, potionType, rum, wine, mushketerSuccess);
		SM_ApplyFirstAISettings(sld);
		
		if (!SM_NeedToSkipLocation()) // если не в каюте
		{
			ChangeCharacterAddressGroup(sld, loadedLocation.id, "reload", LAi_FindNearestFreeLocator("reload", locx, locy, locz));
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	// 15. расходы
	RemoveCharacterGoods(pchar, GOOD_WEAPON, SM_totalFighters); // каждый боец присвоил 1 ед. оружия, если столько нет, то и пофиг, все равно ломье найдут...
	RemoveCharacterGoods(pchar, GOOD_FOOD, SM_totalFighters); // берут с собой еду...
	RemoveCharacterGoods(pchar, GOOD_MEDICAMENT, itemsPerSld * SM_totalFighters); // таблетки, элексиры
	RemoveCharacterGoods(pchar, GOOD_RUM, rumPerSld * SM_totalFighters); // ром
	RemoveCharacterGoods(pchar, GOOD_WINE, winePerSld * SM_totalFighters); // вино
	RemoveCharacterGoods(pchar, GOOD_POWDER, powderPerSld * SM_totalFighters); // и порох, даже если стрелять нечем, пусть воруют
	
	RemoveCharacterCrew(pchar, 0); // и списываем часть команды на берег, или куда там надо...
	
	// 16. вешаем слушатели и понеслась
	if (!SM_NeedToSkipLocation())
		SM_MoveOfficersToPchar();
	
	//SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	SetEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad", 0);
	SetEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload", 0);
	SetEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState", 0);
	
	SM_leftShip = false; // еще не покидали судно
	
	PlaySound("interface\_GTTown2.wav");
	Log_info("Отряд собран и ожидает высадки!");
}

// Выдать вещи солдату
void SM_EquipSupport(ref curSld, object vblades, object vcirasses, object vguns, int powderAndBullets, float bonusHpMultiper, int potions, string potionType, int rum, int wine, bool isMushketer)
{
	int fightSkills = 100; // выучка
	
	string blade = SM_GetRandomItemFrom(vblades);
	
	string gun, bullet;
	if (GetAttributesNum(vguns) > 0)
		SM_GetGunAndBullets(vguns, &gun, &bullet);
	else
		gun = ""; bullet = "";
	if (findsubstr(gun, "mushket", 0) != -1 && !isMushketer) // если религия не позволяет брать мушкет
	{
		gun = "pistol8"; // бландербуз
		bullet = "grapeshot"; // гвозди
	}
	
	string cirass = SM_GetRandomItemFrom(vcirasses);
	
	// вооружаем
	FantomMakeCoolFighter(curSld, pchar.rank, fightSkills, fightSkills, blade, gun, "grapeshot", 0); // толковый борец
	float maxSldHp = LAi_GetCharacterHP(curSld) * bonusHpMultiper/2.0;
	SetPcharSelfSkills22NPC(curSld);
	SetPcharShipSkills22NPC(curSld);
	SetPcharPerks22NPC(curSld);
	curSld.rank = sti(pchar.rank);
	curSld.SuperShooter = true;
	LAi_SetHP(curSld, maxSldHp, maxSldHp);

	curSld.cirassId = Items_FindItemIdx(cirass);
	
	if (gun != "")
	{
		TakenItems(curSld, bullet, powderAndBullets);
		if (bullet != "cartridge" || bullet != "GunEchin")
			TakenItems(curSld, "GunPowder", powderAndBullets);
	}
	
	if (isMushketer)
		curSld.MusketerDistance = 2;
	
	TakenItems(curSld, potionType, potions); // выдаем лечилки
	TakenItems(curSld, "potionrum", rum); // ром
	TakenItems(curSld, "potionwine", wine); // вино
}



// Применяем к солдатам первичные настройки (диалоги, адрес, что делать и тп.)
void SM_ApplyFirstAISettings(ref curSld)
{
	// фразы диалога от Свенсонских солдат, тут к месту.
	curSld.dialog.FileName = "Quest\Saga\OtherNPC.c";
	curSld.dialog.currentnode = "Svensons_sold";
	switch(rand(3))
	{
		case 0: curSld.greeting = "Voice\Russian\pirat_guard_1.WAV"; break;
		case 1: curSld.greeting = "Voice\Russian\pirat_guard_2.WAV"; break;
		case 2: curSld.greeting = "Voice\Russian\pirat_guard_3.WAV"; break;
		case 3: curSld.greeting = "Voice\Russian\pirat_guard_4.WAV"; break;
	}
	
	if (!SM_NeedToSkipLocation()) // если не в каюте
	{
		LAi_ActorFollow(curSld, pchar, "", -1);
		LAi_Actor2WaitDialog(curSld, pchar);
	}
	
	LAi_SetActorType(curSld);
	LAi_Actor2WaitDialog(curSld, pchar);
	LAi_LoginInCaptureTown(curSld, true); // разрешение на участие в осадах
}	


// взять из кучи вещей одну вещь
string SM_GetRandomItemFrom(object items)
{
	aref aItems;
	makearef(aItems, items);
	return GetAttributeValue(GetAttributeN(aItems, rand(GetAttributesNum(items) - 1)));
}



// выбрать ствол и тип патрона к нему
void SM_GetGunAndBullets(object guns, string gun, string bullet)
{
	aref aGuns;
	makearef(aGuns, guns);
	int index = rand(GetAttributesNum(guns) / 2 - 1) * 2;
	gun = GetAttributeValue(GetAttributeN(aGuns, index));
	bullet = GetAttributeValue(GetAttributeN(aGuns, index + 1));
}

// роспуск отряда
void SM_RemoveSupportTeam()
{
	
	ref ms = GetRealShip(sti(pchar.Ship.Type));
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_"+ i);
		if (CheckAttribute(sld, "index") && sld.index != -1)
		{
			LAi_SetWarriorType(sld);
			LAi_type_warrior_SetWateState(sld); // гулять без дела
			sld.lifeday = 0;
		}
	}
	
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	DelEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad");
	
	SM_removeAfterUnload = true;

}

// мгновенный ремув всех оставшихся нпс от отряда
void SM_RemoveSupportTeamImmediately(bool removeAttribute)
{	
	
	if (removeAttribute)
		DeleteAttribute(pchar, "SupportTeamType");
	
	SM_removeAfterUnload = false;
	SM_leftShip = false;
	
	// fix для штурма или абордажа - предотвращает исчезновение команды
	if (SM_ShipCrewBeforeBoarding != 0)
	{
		SetCrewQuantity(pchar, SM_ShipCrewBeforeBoarding); // fix для модифицированного абордажа/штурма
		SM_ShipCrewBeforeBoarding = 0;
	}
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_"+ i);
		if (LAi_GetCharacterHP(sld) > 1)
		{
			ChangeCharacterAddress(sld, "none", "");
			if (GetCrewQuantity(pchar) < GetMaxCrewQuantity(pchar)) // если человек жив, возвращаем его в команду, при этом проверяем на свободное место...
				AddCharacterCrew(pchar, 1);
		}
	}
	
	SM_totalFighters = 0;
	
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	DelEventHandler(EVENT_LOCATION_LOAD, "SM_OnLocationLoad");
	DelEventHandler(EVENT_LOCATION_UNLOAD, "SM_OnLocationUnload");
	DelEventHandler(BI_EVENT_SET_SEA_STATE, "SM_OnSeaState");
	
	PlaySound("interface\notebook.wav");
	Log_info("Отряд был распущен!");
	AddCharacterCrew(pchar, 0);	
}



// TODO: ентерфрейм заменить на таймер с интервалом в несколько сек, если тут так можно...
void SM_ST_OnEnterFrame()
{
	SM_SupportTeamSkipFrame++;
	if (SM_SupportTeamSkipFrame < 100) // оптимизация на коленке (обрабатываем через каждые 100 кадров)
		return;
	else
		SM_SupportTeamSkipFrame = 0;
	
	if (SM_ScanForEnemyByRange(80)) // есть ли враг
	{ 
		
		if (!SM_battleActive) // если есть враги, и отряд спокоен
		{ 
			
			for (i = 0; i < SM_totalFighters; i++)
			{
				sld = characterFromId("SM_Support_sold_" + i);
				if (CheckAttribute(sld, "index") && sld.index != -1)
				{
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
					LAi_SetFightMode(sld, true);
					LAi_warrior_SetCommander(sld, pchar);
					if (!CheckAttribute(pchar, "CSM.BoardingCrewGodMode")) LAi_SetImmortal(sld, false);  // убираем бессмертие на время битвы
					if (CheckAttribute(pchar, "animal"))
						sld.animal = true;
					else
						DeleteAttribute(sld, "animal");
					//Log_info("LAi_SetWarriorType : " + i);
				}
			}
			
			LAi_CharacterPlaySound(pchar, "warrior"); // выругаться
			
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // начать бить врагов
			
			SM_battleActive = true;
			//Log_info("SM_battleActive : true");
			return;
		}
		
	}
	else
	{
		
		if (SM_battleActive) // если врагов нет, но отряд бесится
		{
			
			for (i = 0; i < SM_totalFighters; i++)
			{
				sld = characterFromId("SM_Support_sold_" + i);
				if (CheckAttribute(sld, "index") && sld.index != -1)
				{
					LAi_SetFightMode(sld, false);
					LAi_SetActorType(sld);
					LAi_ActorFollow(sld, pchar, "", -1); // LAi_ActorFollowEverywhere(sld, "", -1); тут не надо.. и вообще не надо. Телепортация лучше, т.к. куча проверок.
					LAi_Actor2WaitDialog(sld, pchar);
					LAi_SetImmortal(sld, true); // fix: своих актеров можем порешить, вне боя пусть будут бессмертны
					
					//Log_info("LAi_SetActorType : " + i);
				}
			}
			// компенсируем немного скиллы (за командирство авторитет, за битые морды +во все боевые навыки)
			// чем больше был отряд, тем больше бонус
			SM_ExpCompensator((rand(18) + SM_totalFighters) * pchar.rank);
			
			SM_battleActive = false;
			
			//Log_info("SM_battleActive : false");
			return;
		}
		
		// напоминаем солдатам, чтоб следовали за нами. иногда некоторые могут перестать ходить.
		for (i = 0; i < SM_totalFighters; i++)
		{
			sld = characterFromId("SM_Support_sold_" + i);
			if (CheckAttribute(sld, "index") && sld.index != -1)
			{
				LAi_type_actor_Reset(sld);
				LAi_ActorFollow(sld, pchar, "", -1);
				LAi_Actor2WaitDialog(sld, pchar);
			}
			
		}
		
	}
	
}



// после завершения драки добавляем немного экспы гг и офам в отряде.
void SM_ExpCompensator(int value)
{
	int index;
	
	AddCharacterExpToSkill(pchar, "Leadership", value); 
	AddComplexSelfExpToScill(value, value, value, value);
	
	for (i = 1; i < 4; i++)
	{
		index = GetOfficersIndex(pchar, i);
		
		if (index != -1)
		{
			sld = GetCharacter(index);
			AddCharacterExpToSkill(sld, "Leadership", value); 
			AddCharacterExpToSkill(sld, "FencingL", value);
			AddCharacterExpToSkill(sld, "FencingS", value);
			AddCharacterExpToSkill(sld, "FencingH", value);
			AddCharacterExpToSkill(sld, "Pistol", value);
			
			//Log_info("AddCharacterExpToSkill : " + value);
		}
	}

}



// При загрузке новой локации...
void SM_OnLocationLoad()
{
	// если пошли нырять, или телепортнулись на ОС... тут еще могут быть ситуации, о которых мне не известно
	if (pchar.location == "underwater" || pchar.location == "LostShipsCity_town")
	{
		SM_RemoveSupportTeamImmediately(true);
		return;
	}
	
	// если вернулись на судно, отряд распускаем автоматически. После абордажа в том числе.
	if (isShipInside(pchar.location))
	{
		
		if (SM_leftShip)
		{
			SM_leftShip = false;
			SM_RemoveSupportTeamImmediately(true);
			return;
		}
		
	}
	else
	{
		SM_leftShip = true; // побывали гдето не на корабле
		//Log_info("Покинули судно");
	}
	
	if (SM_NeedToSkipLocation()) // эти локации не в тему, делаем отсев. Но отряд не отпускаем...
		return;
	
	SetEventHandler("frame", "SM_ST_OnEnterFrame", 0);
	
	float locx, locy, locz;
	GetCharacterPos(pchar, &locx, &locy, &locz);
	
	string locator = "";
	if (CheckAttribute(loadedLocation, "locators.reload"))
		locator = "reload";
	if (CheckAttribute(loadedLocation, "locators.rld"))
		locator = "rld";
	
	for (i = 0; i < SM_totalFighters; i++)
	{
		sld = characterFromId("SM_Support_sold_" + i);
		if (CheckAttribute(sld, "index") && sld.index != -1 && LAi_GetCharacterHP(sld) > 0)
		{
			
			LAi_SetActorType(sld);
			
			ChangeCharacterAddressGroup(sld, loadedLocation.id, locator, LAi_FindNearestFreeLocator(locator, locx, locy, locz));
			
			LAi_ActorFollow(sld, pchar, "", -1);
			LAi_Actor2WaitDialog(sld, pchar);
			
			// здесь с 99% вероятностью все модели попадут в 1 точку, выглядит как баг. По сему, фиксим позиции
			SM_SeparateNPC(pchar, sld, i, SM_totalFighters);
		}
	}
	
	SM_MoveOfficersToPchar();
}



// Если не надо ставить отряд
bool SM_NeedToSkipLocation()
{
	
	/*int j; // i тут нельзя, конфликтит, т.к. во вложенном цикле
	
	if (CheckAttribute(pchar, "CSM.StartNewGame"))
	{
		for (j = 0; j < 15; j++)
			if (findsubstr(pchar.location, SM_skippedLoc[j], 0) != -1)
				return true;
	}
	else
	{*/
		if (HasSubStr(pchar.location, "Cabin") || // updated
			HasSubStr(pchar.location, "My_Campus") || // updated
			HasSubStr(pchar.location, "_store") ||
			HasSubStr(pchar.location, "_tavern_upstairs") ||
			HasSubStr(pchar.location, "_Bank") ||
			HasSubStr(pchar.location, "_TownhallRoom") ||
			HasSubStr(pchar.location, "_PortOffice") ||
			HasSubStr(pchar.location, "_Packhouse") ||
			HasSubStr(pchar.location, "_church") ||
			HasSubStr(pchar.location, "_prison") ||
			HasSubStr(pchar.location, "_KeepersHouse") ||
			HasSubStr(pchar.location, "_Lighthouseroom") ||
			HasSubStr(pchar.location, "_bedroom") ||
			HasSubStr(pchar.location, "_Brothel") ||
			HasSubStr(pchar.location, "_SecBrRoom") ||
			loadedLocation.type == "underwater" ||
			pchar.location == "Terrain")
			return true;
	//}

	return false;
}



// Если убежали с локации, надо забрать отряд ссобой
void SM_OnLocationUnload()
{
	DelEventHandler("frame", "SM_ST_OnEnterFrame");
	
	if (SM_removeAfterUnload) {
		SM_RemoveSupportTeamImmediately(true)
		SM_removeAfterUnload = false;
		return;
	}
	
	SM_battleActive = false;
	for (i = 0; i < SM_totalFighters; i++)
	{
		
		sld = characterFromId("SM_Support_sold_" + i);
		if (CheckAttribute(sld, "index") && sld.index != -1)
		{
			LAi_SetActorType(sld);
			LAi_SetImmortal(sld, true);
			//Log_info("SM_OnLocationUnload: LAi_SetActorType : " + i);
		}
		
	}
	
	//Log_info("SM_OnLocationUnload: " + pchar.location );
}



// вышли в море
void SM_OnSeaState()
{
	
	if (SM_leftShip)
	{
		SM_leftShip = false;
		SM_RemoveSupportTeamImmediately(true);
		return;
	}
	
	//Log_info("SM_OnSeaState");
}



// Ищем около ГГ подходящих врагов. Если есть, то true
bool SM_ScanForEnemyByRange(int value)
{
	if (!IsEntity(loadedLocation))
		return false;
	
	int n = FindNearCharacters(pchar, value, -1.0, -1.0, 0.001, false, true);
	
	for (i = 0; i < n; i++)
	{
		if (!CheckAttribute(chrFindNearCharacters[i], "index"))
			continue;
		
		sld = GetCharacter(sti(chrFindNearCharacters[i].index));
		if (LAi_group_IsEnemy(pchar, sld) && // если враг
			GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE) != "" && // вооружен чемто
			!CheckAttribute(sld, "chr_ai.hpchecker") && // что это, квестовой может?
			sld.chr_ai.type != LAI_TYPE_CARRY && // не я вляется грузчиком
			sld.chr_ai.type != LAI_TYPE_POOR && // не бомж
			sld.chr_ai.type != LAI_TYPE_SIT && // не сидит
			sld.chr_ai.type != LAI_TYPE_STUNNED && // не контужен
			sld.chr_ai.type != LAI_TYPE_LAY) // не спит
			return true;
	}
	
	return false;
}

// Метод немного смещает модель нпс от гг (при работе в цикле равномерно расставит их по окружности), чтоб исключить баг с коллизией, когда в точке спавнится несколько неписей 
void SM_SeparateNPC(ref leader, ref npc, int index, int total)
{	
	float locx, locy, locz, rezX, rezZ, distance = 0.001; // если сделать больше, будут застревать в таверне, во время дуэли, или на нек палубах
	
	GetCharacterPos(leader, &locx, &locy, &locz); 
	
	rezX = cos(6.28 * index / total) * distance + locx;
	rezZ = sin(6.28 * index / total) * distance + locz;
	
	TeleportCharacterToPos(npc, rezX, locy, rezZ);
}

void SetPcharSelfSkills22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	if (CheckAttribute(pchar, "skill.Leadership") > 0)	{ rChar.skill.Leadership = sti(pchar.skill.Leadership); }
	if (CheckAttribute(pchar, "skill.FencingL") > 0)	{ rChar.skill.FencingL	= sti(pchar.skill.FencingL); }
	if (CheckAttribute(pchar, "skill.FencingS") > 0)	{ rChar.skill.FencingS	= sti(pchar.skill.FencingS); }
	if (CheckAttribute(pchar, "skill.FencingH") > 0)	{ rChar.skill.FencingH	= sti(pchar.skill.FencingH); }
	if (CheckAttribute(pchar, "skill.Pistol") > 0)		{ rChar.skill.Pistol 	= sti(pchar.skill.Pistol); }
	if (CheckAttribute(pchar, "skill.Fortune") > 0)		{ rChar.skill.Fortune	= sti(pchar.skill.Fortune); }
	if (CheckAttribute(pchar, "skill.Sneak") > 0)		{ rChar.skill.Sneak		= sti(pchar.skill.Sneak); }
}

void SetPcharShipSkills22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	if (CheckAttribute(pchar, "skill.Sailing") > 0)		{ rChar.skill.Sailing	= sti(pchar.skill.Sailing); }
	if (CheckAttribute(pchar, "skill.Commerce") > 0)	{ rChar.skill.Commerce	= sti(pchar.skill.Commerce); }
	if (CheckAttribute(pchar, "skill.Accuracy") > 0)	{ rChar.skill.Accuracy 	= sti(pchar.skill.Accuracy); }
	if (CheckAttribute(pchar, "skill.Cannons") > 0)		{ rChar.skill.Cannons 	= sti(pchar.skill.Cannons); }
	if (CheckAttribute(pchar, "skill.Repair") > 0)		{ rChar.skill.Repair 	= sti(pchar.skill.Repair); }
	if (CheckAttribute(pchar, "skill.Grappling") > 0)	{ rChar.skill.Grappling = sti(pchar.skill.Grappling); }
	if (CheckAttribute(pchar, "skill.Defence") > 0)		{ rChar.skill.Defence 	= sti(pchar.skill.Defence); }
}

void SetPcharPerks22NPC(ref rChar)
{
	if (rChar.id == -1) { return; }
	DeleteAttribute(rChar, "perks.list");
	// Personal
	if (CheckAttribute(pchar, "perks.list.BasicDefense") > 0)			{ rChar.perks.list.BasicDefense = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedDefense") > 0)		{ rChar.perks.list.AdvancedDefense = "1"; }
if (CheckAttribute(pchar, "perks.list.ProfessionalDefense") > 0)		{ rChar.perks.list.ProfessionalDefense = "1"; }
	if (CheckAttribute(pchar, "perks.list.CriticalHit") > 0)			{ rChar.perks.list.CriticalHit = "1"; }
	if (CheckAttribute(pchar, "perks.list.HPPlus") > 0)					{ rChar.perks.list.HPPlus = "1"; }
	if (CheckAttribute(pchar, "perks.list.Tireless") > 0)				{ rChar.perks.list.Tireless = "1"; }
	if (CheckAttribute(pchar, "perks.list.EnergyPlus") > 0)				{ rChar.perks.list.EnergyPlus = "1"; }
	if (CheckAttribute(pchar, "perks.list.Sliding") > 0)				{ rChar.perks.list.Sliding = "1"; }
	if (CheckAttribute(pchar, "perks.list.SwordplayProfessional") > 0)	{ rChar.perks.list.SwordplayProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.HardHitter") > 0)				{ rChar.perks.list.HardHitter = "1"; }
	if (CheckAttribute(pchar, "perks.list.BladeDancer") > 0)			{ rChar.perks.list.BladeDancer = "1"; }
	if (CheckAttribute(pchar, "perks.list.Gunman") > 0)					{ rChar.perks.list.Gunman = "1"; }
	if (CheckAttribute(pchar, "perks.list.GunProfessional") > 0)		{ rChar.perks.list.GunProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Sniper") > 0)		{ rChar.perks.list.Sniper = "1"; }
	if (CheckAttribute(pchar, "perks.list.Grus") > 0)					{ rChar.perks.list.Grus = "1"; }
	if (CheckAttribute(pchar, "perks.list.IronWill") > 0)				{ rChar.perks.list.IronWill = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipEscape") > 0)				{ rChar.perks.list.ShipEscape = "1"; }
	// Ship
	if (CheckAttribute(pchar, "perks.list.Brander") > 0) 				{ rChar.perks.list.Brander = "1"; }
	if (CheckAttribute(pchar, "perks.list.Troopers") > 0) 				{ rChar.perks.list.Troopers = "1"; }
	if (CheckAttribute(pchar, "perks.list.LongRangeGrappling") > 0) 	{ rChar.perks.list.LongRangeGrappling = "1"; }
	if (CheckAttribute(pchar, "perks.list.GrapplingProfessional") > 0)	{ rChar.perks.list.GrapplingProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.MusketsShoot") > 0) 			{ rChar.perks.list.MusketsShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.BasicCommerce") > 0) 			{ rChar.perks.list.BasicCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedCommerce") > 0) 		{ rChar.perks.list.AdvancedCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.ProfessionalCommerce") > 0) 	{ rChar.perks.list.ProfessionalCommerce = "1"; }
	if (CheckAttribute(pchar, "perks.list.FastReload") > 0) 			{ rChar.perks.list.FastReload = "1"; }
	if (CheckAttribute(pchar, "perks.list.ImmediateReload") > 0) 		{ rChar.perks.list.ImmediateReload = "1"; }
	if (CheckAttribute(pchar, "perks.list.HullDamageUp") > 0) 			{ rChar.perks.list.HullDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailsDamageUp") > 0) 			{ rChar.perks.list.SailsDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.CrewDamageUp") > 0) 			{ rChar.perks.list.CrewDamageUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.CriticalShoot") > 0) 			{ rChar.perks.list.CriticalShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.LongRangeShoot") > 0) 		{ rChar.perks.list.LongRangeShoot = "1"; }
	if (CheckAttribute(pchar, "perks.list.CannonProfessional") > 0) 	{ rChar.perks.list.CannonProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Carpenter") > 0) 				{ rChar.perks.list.Carpenter = "1"; }
	if (CheckAttribute(pchar, "perks.list.LightRepair") > 0) 			{ rChar.perks.list.LightRepair = "1"; }
	if (CheckAttribute(pchar, "perks.list.Builder") > 0) 				{ rChar.perks.list.Builder = "1"; }
	if (CheckAttribute(pchar, "perks.list.BasicBattleState") > 0) 		{ rChar.perks.list.BasicBattleState = "1"; }
	if (CheckAttribute(pchar, "perks.list.AdvancedBattleState") > 0) 	{ rChar.perks.list.AdvancedBattleState = "1"; }
	if (CheckAttribute(pchar, "perks.list.SelfRepair") > 0) 			{ rChar.perks.list.SelfRepair = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipDefenseProfessional") > 0) { rChar.perks.list.ShipDefenseProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipSpeedUp") > 0) 			{ rChar.perks.list.ShipSpeedUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.ShipTurnRateUp") > 0) 		{ rChar.perks.list.ShipTurnRateUp = "1"; }
	if (CheckAttribute(pchar, "perks.list.StormProfessional") > 0) 		{ rChar.perks.list.StormProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.WindCatcher") > 0) 			{ rChar.perks.list.WindCatcher = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailsMan") > 0) 				{ rChar.perks.list.SailsMan = "1"; }
	if (CheckAttribute(pchar, "perks.list.Turn180") > 0) 				{ rChar.perks.list.Turn180 = "1"; }
	if (CheckAttribute(pchar, "perks.list.SailingProfessional") > 0) 	{ rChar.perks.list.SailingProfessional = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor1") > 0) 				{ rChar.perks.list.Doctor1 = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor2") > 0) 				{ rChar.perks.list.Doctor2 = "1"; }
	if (CheckAttribute(pchar, "perks.list.Doctor3") > 0) 				{ rChar.perks.list.Doctor3 = "1"; }
}

// чтоб офы не появлялись в гуще врагов и не дохли там
void SM_MoveOfficersToPchar()
{
	int i, index;
	float locx, locy, locz;
	ref of;
	string locator = "";
	
	GetCharacterPos(pchar, &locx, &locy, &locz);
	if (CheckAttribute(loadedLocation, "locators.reload"))
		locator = "reload";
	if (CheckAttribute(loadedLocation, "locators.rld"))
		locator = "rld";
	
	for (i = 1; i <= 3; i++)
	{
		index = GetOfficersIndex(pchar, i);
		if (index == -1)
			continue;
		of = GetCharacter(index);
		
		ChangeCharacterAddressGroup(of, loadedLocation.id, locator, LAi_FindNearestFreeLocator(locator, locx, locy, locz));
		
		SM_SeparateNPC(pchar, of, i, 3);
	}
}



