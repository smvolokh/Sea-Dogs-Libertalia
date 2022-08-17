// Warship -->
// Выставлялка рандомных скиллов
void SetRandSelfSkill(ref _ch, int _min, int _max)
{
	int iDelta = _max-_min;
	_ch.skill.Leadership 	= _min + rand(iDelta);
	_ch.skill.FencingL 		= _min + rand(iDelta);
	_ch.skill.FencingS 		= _min + rand(iDelta);
	_ch.skill.FencingH 		= _min + rand(iDelta);
	_ch.skill.Pistol 		= _min + rand(iDelta);
	_ch.skill.Fortune 		= _min + rand(iDelta);
	_ch.skill.Sneak 		= _min + rand(iDelta);
}

void SetRandShipSkill(ref _ch, int _min, int _max)
{
	int iDelta = _max-_min;
	_ch.skill.Sailing = _min + rand(iDelta);
	_ch.skill.Commerce = _min + rand(iDelta);
	_ch.skill.Accuracy = _min + rand(iDelta);
	_ch.skill.Cannons = _min + rand(iDelta);
	_ch.skill.Repair = _min + rand(iDelta);
	_ch.skill.Grappling = _min + rand(iDelta);
	_ch.skill.Defence = _min + rand(iDelta);
}

// Установить персу все перки
void SelAllPerksToChar(ref _ch, bool _isOfficer)
{
	_ch.perks.list.BasicDefense = "1";
	_ch.perks.list.AdvancedDefense = "1";
	_ch.perks.list.ProfessionalDefense = "1";
	_ch.perks.list.CriticalHit = "1";
	_ch.perks.list.SwordplayProfessional = "1";
	_ch.perks.list.Grus = "1";
	_ch.perks.list.Rush = "1";
	_ch.perks.list.Tireless = "1";
	_ch.perks.list.HardHitter = "1";
	_ch.perks.list.BladeDancer = "1";
	_ch.perks.list.Sliding = "1";
	_ch.perks.list.Gunman = "1";
	_ch.perks.list.GunProfessional = "1";
	_ch.perks.list.Sniper = "1";
	_ch.perks.list.IronWill = "1";
	_ch.perks.list.SharedExperience = "1";
	_ch.perks.list.Medic = "1";
	_ch.perks.list.HPPlus = "1";
	_ch.perks.list.EnergyPlus = "1";
	_ch.perks.list.ShipEscape = "1";
	_ch.perks.list.Alchemy = "1";
	
	_ch.perks.list.FlagPir = "1";
	_ch.perks.list.FlagEng = "1";
	_ch.perks.list.FlagFra = "1";
	_ch.perks.list.FlagSpa = "1";
	_ch.perks.list.FlagHol = "1";
	_ch.perks.list.FastReload = "1";
	_ch.perks.list.ImmediateReload = "1";
	_ch.perks.list.HullDamageUp = "1";
	_ch.perks.list.SailsDamageUp = "1";
	_ch.perks.list.CrewDamageUp = "1";
	_ch.perks.list.CriticalShoot = "1";
	_ch.perks.list.LongRangeShoot = "1";
	_ch.perks.list.CannonProfessional = "1";
	_ch.perks.list.LongRangeGrappling = "1";
	_ch.perks.list.MusketsShoot = "1";
	_ch.perks.list.GrapplingProfessional = "1";
	_ch.perks.list.BasicBattleState = "1";
	_ch.perks.list.AdvancedBattleState = "1";
	_ch.perks.list.ShipDefenseProfessional = "1";
	_ch.perks.list.LightRepair = "1";
	_ch.perks.list.InstantRepair = "1";
	_ch.perks.list.ShipSpeedUp = "1";
	_ch.perks.list.ShipTurnRateUp = "1";
	_ch.perks.list.StormProfessional = "1";
	_ch.perks.list.Turn180 = "1";
	_ch.perks.list.SeaDogProfessional = "1";
	_ch.perks.list.SailingProfessional = "1";
	_ch.perks.list.Brander = "1";
	_ch.perks.list.Troopers = "1";
	_ch.perks.list.BasicCommerce = "1";
	_ch.perks.list.AdvancedCommerce = "1";
	_ch.perks.list.ProfessionalCommerce = "1";	
	_ch.perks.list.Carpenter = "1";
	_ch.perks.list.Builder = "1";
	_ch.perks.list.SelfRepair = "1";
	_ch.perks.list.WindCatcher = "1";
	_ch.perks.list.SailsMan = "1";
	_ch.perks.list.Doctor1 = "1";
	_ch.perks.list.Doctor2 = "1";
	_ch.perks.list.Doctor3 = "1";
	
	if(_isOfficer) // У офов есть доп. перки
	{
		_ch.perks.list.ByWorker = "1";
		_ch.perks.list.ByWorker2 = "1";
	}
}

// Установить персу половину перков
void SetHalfPerksToChar(ref _ch, bool _isOfficer)
{
	_ch.perks.list.BasicDefense = "1";
	_ch.perks.list.AdvancedDefense = "1";
	_ch.perks.list.CriticalHit = "1";
	_ch.perks.list.ProfessionalDefense = "1";
	_ch.perks.list.Gunman = "1";
	_ch.perks.list.SharedExperience = "1";
	
	_ch.perks.list.FlagPir = "1";
	_ch.perks.list.FlagEng = "1";
	_ch.perks.list.FlagFra = "1";
	_ch.perks.list.FlagSpa = "1";
	_ch.perks.list.FlagHol = "1";
	_ch.perks.list.HullDamageUp = "1";
	_ch.perks.list.SailsDamageUp = "1";
	_ch.perks.list.CrewDamageUp = "1";
	_ch.perks.list.CriticalShoot = "1";
	_ch.perks.list.LongRangeShoot = "1";
	_ch.perks.list.LongRangeGrappling = "1";
	_ch.perks.list.GrapplingProfessional = "1";
	_ch.perks.list.BasicBattleState = "1";
	_ch.perks.list.AdvancedBattleState = "1";
	_ch.perks.list.ShipSpeedUp = "1";
	_ch.perks.list.ShipTurnRateUp = "1";
	_ch.perks.list.StormProfessional = "1";
	_ch.perks.list.Turn180 = "1";
	_ch.perks.list.SailingProfessional = "1";
	_ch.perks.list.WindCatcher = "1";
	_ch.perks.list.SailsMan = "1";
	
	if(_isOfficer) // У офов есть доп. перки
	{
		_ch.perks.list.ByWorker = "1";
		_ch.perks.list.ByWorker2 = "1";
	}
}

// Отобрать все предметы (кроме квестовых) у выбранного персонажа
void RemoveAllCharacterItems(ref _ch, bool _removemoney)
{
	// сносим нафик всю экипировку
	if(_ch == GetMainCharacter())
	{
		StoreEquippedMaps(_ch);
		_ch.MapsAtlasCount = 0;
	}	
	RemoveCharacterEquip(_ch, BLADE_ITEM_TYPE);
	RemoveCharacterEquip(_ch, GUN_ITEM_TYPE);
	RemoveCharacterEquip(_ch, SPYGLASS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, PATENT_ITEM_TYPE);
	RemoveCharacterEquip(_ch, CIRASS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, MAPS_ITEM_TYPE);
	RemoveCharacterEquip(_ch, TOOL_ITEM_TYPE);
	RemoveCharacterEquip(_ch, BACKPACK_ITEM_TYPE);
	RemoveCharacterEquip(_ch, TALISMAN_ITEM_TYPE);
	
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT1_TYPE);
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT2_TYPE);
	RemoveCharacterArtefactEquip(_ch, ITEM_SLOT3_TYPE);
	
	//сносим все предметы, кроме квестовых -->
	aref arItems;
	string sName;
	ref rLoc;
	makearef(arItems, _ch.items);
	int	Qty = GetAttributesNum(arItems);
	for (int a=0; a<Qty; a++)
	{
		sName = GetAttributeName(GetAttributeN(arItems, a));
		rLoc = ItemsFromID(sName);
		if (rLoc.ItemType == "QUESTITEMS")
		{
			_ch.questTemp.items.(sName) = _ch.items.(sName);
		}
	}			
	DeleteAttribute(_ch, "items");
	_ch.items = "";
	makearef(arItems, _ch.questTemp.items);
	Qty = GetAttributesNum(arItems);
	for (a=0; a<Qty; a++)
	{		
		sName = GetAttributeName(GetAttributeN(arItems, a));
		TakeNItems(_ch, sName, sti(arItems.(sName)));
	}		
	DeleteAttribute(_ch, "questTemp.items");
	
	_ch.SystemInfo.itemsCRC = CheckItemsCRC(_ch); // заново пересчитаем контрольную сумму
	
	if(_removemoney)
	{
		_ch.money = 0;
	}
}

// снести всех пассажиров и компаньонов ГГ
void RemoveAllPassengersAndCompanions()
{
    int iDay = GetPassengersQuantity(pchar);
    int i = 0;
    int n = 0;
	int idx;
	ref ch;
	
 	while (i < iDay)
	{
		i++;
		idx = GetPassenger(pchar, n); // всегда первый в массиве со смещением, если не трем
		if (idx == -1) break;
		ch = GetCharacter(idx);
		if (GetRemovable(ch)) // квестовых не трогаем
		{
		    ch.LifeDay = 1; // чтоб не сразу потерся
		    RemovePassenger(pchar, ch);
			ChangeCharacterAddress(ch,"none","");
		}
		else
		{
		    n++;
		}
	}
    for (i=0; i<COMPANION_MAX; i++)
	{
		idx = GetCompanionIndex(pchar, i);
		if (idx != -1)
		{
            ch = GetCharacter(idx);
			if (GetShipRemovable(ch) && GetRemovable(ch))  // не трогаем квестовых и ПГГ
			{
			    ch.LifeDay = 1; // чтоб не сразу потерся
			    RemoveCharacterCompanion(pchar, ch);
			}
		}
	}
}

void CleanAllCabinBoxes()
{
	ref loc;
	int n;
	string sTemp;
	
    if (Pchar.SystemInfo.CabinType != "")
    {
	    loc = &locations[FindLocation(Pchar.SystemInfo.CabinType)]; //"My_Cabin"

	    for (n = 1; n <= 4; n++)
	    {
	        sTemp = "box" + n;
			DeleteAttribute(loc, sTemp + ".items");
		    loc.(sTemp).items = "";
		    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
		    loc.(sTemp).money = 0;
	    }
    }
    loc = &locations[FindLocation("My_Deck")];
    for (n = 1; n <= 4; n++)
    {
        sTemp = "box" + n;
		DeleteAttribute(loc, sTemp + ".items");
	    loc.(sTemp).items = "";
	    loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
	    loc.(sTemp).money = 0;
    }
}

// Метод вернет случайный тип корабля, который зависит от класса шипа персонажа
int RandShipFromShipClass(ref _ch)
{
	int iShipClass = sti(RealShips[sti(_ch.Ship.Type)].Class);
	int iShipType;
	switch(iShipClass)
	{
		case 1:
			iShipType = SHIP_LINESHIP + rand(4);
			break;
			
		case 2:
			iShipType = SHIP_HEAVYGALEON + rand(12);
			break;
		
		case 3:
			iShipType = SHIP_GALEON_L + rand(13);
			break;
			
		case 4:
			iShipType = SHIP_BRIGANTINE + rand(12);
			break;
			
		case 5:
			iShipType = SHIP_GALIOT + rand(11);
			break;
			
		case 6:
			iShipType = SHIP_WAR_TARTANE;
			break;
			
	}
	return iShipType;
}

// Проверка, есть ли у ГГ казначей
bool IsPCharHaveTreasurer()
{
	ref rOfficer;

	for(int i=0; i<MAX_CHARACTERS; i++)
	{
		rOfficer = &characters[i];
		if(CheckAttribute(rOfficer, "treasurer") && sti(rOfficer.Treasurer) == 1)
		{
			return true; // Казначей есть
		}
		
	}
	
	return false;
}

// Метод вернет ссылку на казначея
ref GetPCharTreasurerRef()
{
	if(!IsPCharHaveTreasurer()) return &NullCharacter;
	for(int i=0; i<MAX_CHARACTERS; i++)
	{
		if(CheckAttribute(&characters[i], "treasurer") && sti(characters[i].Treasurer) == 1)
		{
			return &characters[i];
		}
	}
	
	return &NullCharacter;
}

// Метод вернет значение атрибута
string GetAttrValue(ref _rChar, string _sAttr)
{
	string sTemp;
	if(!CheckAttribute(_rChar, _sAttr)) _rChar.(_sAttr) = "";
	
	sTemp = _rChar.(_sAttr);
	return sTemp;
}

// Получить рандомную локацию с указанным типом на заданном острове
string IslandGetLocationFromType(string _island, string _type)
{
	ref rLoc;
	int i, iMaxLoc[MAX_LOCATIONS];
	int iRandLoc = 0;
	for(i=1; i<MAX_LOCATIONS; i++)
	{
		makeref(rLoc, locations[i]);
		if(findsubstr(rLoc.id, _type, 0) != -1 && rLoc.islandId == _island)
		{
			iMaxLoc[iRandLoc] = i;
			iRandLoc++;
		}
	}
	
	if(iRandLoc == 0)
		return "none";
	
	i = iMaxLoc[rand(iRandLoc-1)];
	return locations[i].id;
}

// Просто сокращение -->
void DisableAllExits(bool _truefalse)
{
	chrDisableReloadToLocation = _truefalse;
	bDisableFastReload         = _truefalse;
}
// Просто сокращение <--

// Warship <--

void LockQuestLine(ref refChar) // Лочим квестовую линейку
{
	refChar.notQuestLine = true;
}

string QuestGetGangLocation(string _areal)	// Получить локацию для генерации банд и т.д.
{
	int n;
	string island = GetArealByCityName(_areal);
	string LocationId, sAreal;
	int storeArray[MAX_LOCATIONS];
	int howStore = 0;

	for(n=0; n<MAX_LOCATIONS; n++)
	{				
		if(GiveArealByLocation(&locations[n]) == island)
		{			
			//==> на всякий случай
			if(CheckAttribute(&locations[n], "DisableEncounters") && locations[n].DisableEncounters == true) continue;
			LocationId = locations[n].id;
			if(findsubstr(LocationId, "jungle" , 0) != -1 || findsubstr(LocationId, "Shore" , 0) != -1 || findsubstr(LocationId, "CaveEntrance" , 0) != -1)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	n = storeArray[rand(howStore-1)];
	return locations[n].id;
}

string QuestGetColony(string _city) // Получить рандомную колонию по аттрибуту NPChar.city, не равную _city
{
    int storeArray[MAX_COLONIES];
    int howStore = 0;
	string sChrId;

	for(int n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetRelation2BaseNation(sti(colonies[n].nation)) != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "VillaAlegria" && colonies[n].id != _city)
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	return colonies[storeArray[rand(howStore-1)]].id;
}

string GetColonyExpect2Colonies(string _city1, string _city2) // Исключая две колонии
{
	int storeArray[MAX_COLONIES];
	int howStore = 0;
	string sChrId;
	ref rColony;

	for(int n=0; n<MAX_COLONIES; n++)
	{
		makeref(rColony, colonies[n]);
		if(!CheckAttribute(rColony, "HasNoFort") && rColony.nation != "none" && sti(rColony.nation) != PIRATE && GetRelation2BaseNation(sti(rColony.nation)) != RELATION_ENEMY && rColony.id != "Panama" && colonies[n].id != "Minentown"&& colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && rColony.id != _city1 && rColony.id != _city2)
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	return colonies[storeArray[rand(howStore-1)]].id;
}

// инициализация мультиобъектов - по дефолту рецепты ГГ не доступны
void InitAlchemy()
{
	ref item;		
	for(int n = 0; n < ITEMS_QUANTITY; n++)
	{
		item = &Items[n];
		if( CheckAttribute(item,"multiobject") )
		{
			string sGood = item.id;
			pchar.alchemy.(sGood).isKnown = false;
			// Jason: закомментировал, т.к. мешает работать. Вынес в дебагер на F22.
			//if (MOD_BETTATESTMODE == "On")		pchar.alchemy.(sGood).isKnown = true;
			//else								pchar.alchemy.(sGood).isKnown = false;
		}
	}
}

// проверка - знает ли ГГ рецепт мультиобъекта
bool isMultiObjectKnown(string itemId)
{
	ref item;		
	for(int n = 0; n < ITEMS_QUANTITY; n++)
	{
		item = &Items[n];
		if( CheckAttribute(item,"multiobject") )
		{
			string sGood = item.id;
			if(sGood == itemId && pchar.alchemy.(sGood).isKnown == true) return true;
		}
	}
	return false;
}

void SetAlchemyRecipeKnown(string Recipe)
{
	pchar.alchemy.(Recipe).isKnown = true;
}

void initStartState2Character(ref ch)
{// метод вызывается в момент новой игры, заполняет главного героя атрибутами, чтоб убрать лишние проверки в if
    NullCharacter.Siege = "";
    
	ch.SystemInfo.SaveCount = 0;
    ch.SystemInfo.LoadCount = 0;
    ch.SystemInfo.DeadCount = 0;

    ch.SystemInfo.CabinType          = ""; // boal 28.03.05 каюты нет  My_Cabin_Small
    
    ch.questTemp.Contraband.relation = 60;
	ch.questTemp.Indian.relation = 15; // репа у индейцев, от 0 до 100, выше 60 - друг, ниже 20 - враг
    DeleteAttribute(ch, "quest.meeting");
    ch.ShipInStock = 0; // кораблей в порту
	ch.questTemp.abordage = 0;   // двойной абордаж
	ch.questTemp.donate   = 0; // пожертвование церкви

	ch.questTemp.friend_in_tavern = ""; // оптимизация boal
	ch.questTemp.RelationAgentMet = "0"; // оптимизация boal

	ch.questTemp.NationQuest = ""; // взятая линейка квестов

	ch.GenQuest.BrothelCount = "0"; // счетчик посещений девочек
	//ch.GenQuest.Hunter2Pause   = false; // признак бойни в форте на суше - не делать ОЗГов
	ch.I_MAP_SHOW = false;  // boal карты смотрим из предметов
	ch.CameraHoldPos = false;
	ch.CameraShipNPC = 0;// номер компаньона для камеры 0 - ГГ
	ch.GenQuestFort.FarLocator = true; // для методов пихания фантомов в город
    
    ch.GenQuest.Find_Merchant.lastspeak_date = "";
    ch.GenQuest.ConvoyPassenger = ""; //структура недовольных по квесту доставки пассажира

	// ==> состояние квеста текущей линейки
	ch.questTemp.State = "";
	// ==> кол-во дней ожидания выдачи следующего квеста губером, стандарт - два дня
	ch.questTemp.Waiting_time = "2";
	// ==> номер текущего квеста, присваиваем сразу второй, т.к. первый берется на момент первого обращения к губеру.
	ch.questTemp.CurQuestNumber = "2";
	//параметры островов и бухт для корсарского метро, ПГГ, и много еще чего :)
	InitTravelMap();
	// ==> проверка не посещение борделей после свадьбы
	pchar.RomanticQuest.HorseCheck = -1;
	// ==> Количество карт в навигационном атласе
	ch.MapsAtlasCount = 0;
	// ==> Номер пиратского флага (берется из текстуры персональных флагов ГГ)
	ch.Flags.Pirate = 7;
	// ==> работорговец
	ch.questTemp.Slavetrader = "canTakeQuest"; //сюда же пихаем флаг
	// ==> выбор ростовщика-работорговца
	SelectSlavetraderRendom(); //это непосредственно выбор
	// ==>  нищие
	PoormansInit();
	// ==>  кол-во лута, отданного шлюхами
	pchar.questTemp.HorseLoot = 0;
	// ==>  кол-во перетраха со шлюхами
	pchar.questTemp.HorseQty = 0;
	// ==>  установим счетчик для фрахтов
	pchar.questTemp.WPU.Fraht.count = 0;
	pchar.questTemp.WPU.Postcureer.count = 0;
	pchar.questTemp.WPU.Escort.count = 0;
	// ==> тюремный флаг на проход внутрь
	ch.questTemp.jailCanMove = false;
	// ==> набор мелких квестов, дается по одному до закрытия
	ch.questTemp.different = "free";
	ch.questTemp.WPU = "0";
	//ситуации в море
	ch.CanGenerateShipSituation = true;
	// ==> установка алхимии (знакомы рецепты или нет - по умолчанию на начало новой игры все рецепты не знакомы)
	InitAlchemy();
	//==> Голландский гамбит - ключевые персонажи
	HollandGambitNpcInit();
	//==> Бремя Гасконца - ключевые персонажи
	SharlieNpcInit();
	//==> Пиратская Сага - ключевые персонажи
	SagaNpcInit();
	//==> основные НПС LSC
	LSC_NpcInit();
	//--> Мини-квесты, инициализирующиеся по достижении ранга
	pchar.quest.Red_Chieftain.win_condition.l1 = "Rank";
	pchar.quest.Red_Chieftain.win_condition.l1.value = 8; // 280313
	pchar.quest.Red_Chieftain.win_condition.l1.operation = ">=";
	pchar.quest.Red_Chieftain.function = "RedChieftain_Prepare";
	pchar.quest.False_Trace.win_condition.l1 = "Rank";
	pchar.quest.False_Trace.win_condition.l1.value = 15; // may-16
	pchar.quest.False_Trace.win_condition.l1.operation = ">=";
	pchar.quest.False_Trace.function = "FalseTrace_Prepare";
	// --> мангароса
	pchar.quest.Mangarosa.win_condition.l1 = "item";
	pchar.quest.Mangarosa.win_condition.l1.item = "cannabis7";
	pchar.quest.Mangarosa.function = "Mangarosa_Start";
	// --> пиратский антикач
	pchar.GenQuest.Piratekill = 0;
	// --> счетчики посещений таверн и верфей - ugeen 2016, нужно для ачивок
	pchar.questTemp.TavernVisit.counter = 0;
	pchar.questTemp.ShipyardVisit.counter = 0;

	//==> Готика - ключевые персонажи
	GothicNpcInit();
	// ==> офицеры тёлы
	OfficerGirlInit();
	// ==> мушкетеры
	OfficerMushketerInit();
	// ==>  флаги и иниты бергларов 
	BerglarsInit();
	// <==
	// ==> линейка ГПК
	LSCCNpcInit();
	ch.questTemp.LSCC = false;
	ch.questTemp.LSCC.checkBoxes = false; //флаг проверки сундуков в полночь	
	pchar.quest.FirstLoginLostShipsCityy.win_condition.l1 = "location";
	pchar.quest.FirstLoginLostShipsCityy.win_condition.l1.location = "LostShipsCityy_town";
	pchar.quest.FirstLoginLostShipsCityy.function = "FirstLoginLostShipsCityy";

	// ==> линейка Монбара homo
	ch.questTemp.GothicMonbar = true;

	// ==> линейка Теночтитлана
	ch.questTemp.Tenoc = "begin";
	pchar.quest.Tenoc_startInShore.win_condition.l1 = "location";
	pchar.quest.Tenoc_startInShore.win_condition.l1.location = "Bel_jungle_02";
	pchar.quest.Tenoc_startInShore.function = "Tenoc_startInShore";
	//зачарованный город
	LocatorReloadEnterDisable("Shore_ship3", "reload1", true);
	ch.questTemp.MC = "begin"; //флаг квеста	
	pchar.quest.MC_startInCaracas.win_condition.l1 = "location";
	pchar.quest.MC_startInCaracas.win_condition.l1.location = "Caracas_town";
	pchar.quest.MC_startInCaracas.function = "MC_startInCaracas";
	// ==> квест получения Черной Горгульи
	ch.questTemp.BlueBird = "begin";
	ch.questTemp.BlueBird.City = "SantLous_town";
	ch.questTemp.BlueBird.count = 0;
	// ==> Квест Аскольда.
                    //ch.questTemp.Ascold = "canTakeQuest"; // состояние, если равен "", то пока не даем квест.
	// ==> выбор хозяна магазина и уличного торговца по Аскольду.
	SelectAscoldRendom();
	SelectAscoldRendom();
	// ==> генератор Шарпа по жемчугу
	ch.questTemp.Sharp = "begin";
	ch.questTemp.Sharp.City = "";
	ch.questTemp.Sharp.count = 0; //счетчик кол-ва поисков
	ch.questTemp.Sharp.brothelChance = 1; //античит, шанс встретить Шарпа прямо в борделе
	ch.questTemp.Sharp.SeekSpy = "begin"; //состояние квест на поиски информатора Шарпа
	// ==> пиратская линейка
	// Летучий Голландец
	ch.GenQuest.GhostShip.DeadByMe       = 0;
	ch.GenQuest.GhostShip.KillMe         = 0;
	ch.GenQuest.GhostShip.AskAbout       = 0; // в таверне три раза спросить до появления
	ch.GenQuest.GhostShip.lastspeak_date = "";
    GhostShipInit();
	// ==> прерывания на ход к жемчужному промыслу
	DestinyGiftPearlGen_SetSantaCatalina("none");

}

//==> eddy. квестовая обработка 'ноль часов'.
void QuestActions()
{
	ref sld;
	int i;
	CompanionTravel_ProcessAllTravellers(); // Warship. Процессирование компаньонов-путешественников
	// забираем просроченные лицензии
	for (i=0; i<4; i++)
	{
		if (CheckCharacterItem(pchar, NationShortName(i)+"TradeLicence") && GetDaysContinueNationLicence(i) == -1)
		{
			TakeNationLicence(i);
		}		
	}
	//Если идет линейка ГПК, то шмаляем открытые сундуки. Все, кроме Диффиндура.
	if (sti(pchar.questTemp.LSCC.checkBoxes))
	{
		LSCC_checkBoxes();
	}

	//************** квест. открываем двери дома коменданта Гаваны *******************
	if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_WaitMidnight")
	{
	LocatorReloadEnterDisable("Havana_town", "houseS1", false);
                Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition.l1 = "location";
                Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition.l1.location = "Havana_houseS1";
               Pchar.quest.GothicLeeTakeAnna_FightInHouse.win_condition = "GothicLeeTakeAnna_FightInHouse";
		pchar.questTemp.GothicLee = "GothicLeeTakeAnna_DoorIsOpen";
	}

	//************** линейка ГПК, переход в погребок таверны *******************
	if (pchar.questTemp.LSCC == "toWineCellar")
	{
		if (GetHour() < 1)
		{
			pchar.questTemp.LSCC = "toWineCellarGone";
			sld = characterFromId("LSCCBarmen");
			LAi_SetStayTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "FleuronTavernn", "rld", "stay1");
			PChar.quest.LSCC_returnBarmen.win_condition.l1            = "Timer";
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.hour  = 1;
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			PChar.quest.LSCC_returnBarmen.function = "LSCC_returnBarmen";
		}
		else pchar.questTemp.LSCC = "toWineCellarLate";
	}
	//************** линейка ГПК, переход в погребок для подслушивания *******************
	if (pchar.questTemp.LSCC == "toInterception")
	{
		if (pchar.location == "FleuronTavernn" && pchar.location.locator == "reload2")
		{
			DoQuestFunctionDelay("LSCC_scriptInterception", 10.0 + frand(20));
		}
		else
		{
			pchar.questTemp.LSCC = "InterceptionLate";
			AddQuestRecord("ISS_MainLine", "19");
		}
	}
	//************** линейка ГПК, завал первого каспера с помощь Армо *******************
	if (CheckAttribute (pchar, "questTemp.LSCC.Armo"))
	{
		//первый каспер пошел
		if (sti(pchar.questTemp.LSCC.Armo) == 1 || sti(pchar.questTemp.LSCC.Armo) == 3 || sti(pchar.questTemp.LSCC.Armo) == 5)
		{
			if (pchar.location == "LostShipsCityy_town" && GetHour() < 2)
			{
				LAi_group_Delete("EnemyFight"); 
				sld = characterFromId("Casper_" + pchar.questTemp.LSCC.Armo);
				sld.BreakTmplAndFight = true; //проверять на атаку
				sld.reactionOnFightModeOn = true; //проверять на вытаскивание оружия
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
				ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "reload", "reload55");
				LAi_ActorGoToLocator(sld, "reload", "reload65", "LSCC_casperIsGone", -1.0);
				pchar.questTemp.LSCC.Armo.casperIdx = sld.index; //запомним индекс, пригодится на выходе
				//таймер на проверку, убит ли каспер
				pchar.quest.LSCC_checkCasperDead.win_condition.l1               = "Location_Type";
				pchar.quest.LSCC_checkCasperDead.win_condition.l1.location_type = "LSCC_insidee";
				pchar.quest.LSCC_checkCasperDead.win_condition.l2            = "Timer";
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.hour  = 2;
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.day   = GetAddingDataDay(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.month = GetAddingDataMonth(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.win_condition.l2.date.year  = GetAddingDataYear(0, 0, 0);
				pchar.quest.LSCC_checkCasperDead.function = "LSCC_checkCasperDead";	
				pchar.quest.LSCC_checkCasperDead.casperIdx = sld.index;
			}
			else
			{
				pchar.questTemp.LSCC.Armo = 11; //профукал каспера
			}
		}
	}

	//************** генератор "Продажный патруль" *********************************
	if(CheckAttribute(pchar, "questTemp.ReasonToFast"))
	{
		if(pchar.questTemp.ReasonToFast == "SpeakHorse") // не пришел в бухту
		{
			AddQuestRecord("ReasonToFast", "2");	
			AddQuestUserData("ReasonToFast", "sSex", GetSexPhrase("","а"));			
			CloseQuestHeader("ReasonToFast");
			pchar.questTemp.ReasonToFast.end = true;
		}
		if(pchar.questTemp.ReasonToFast == "MeetPatrolFail") // в бухту пришел не один или удачи не хватило
		{
			AddQuestRecord("ReasonToFast", "3");		
			AddQuestUserData("ReasonToFast", "sSex", GetSexPhrase("ся","ась"));		
			CloseQuestHeader("ReasonToFast");
			pchar.questTemp.ReasonToFast.end = true;
		}
		if(CheckAttribute(pchar, "questTemp.ReasonToFast.PatrolLocation"))
		{
			if(CheckAttribute(Locations[FindLocation(pchar.questTemp.ReasonToFast.PatrolLocation)],"DisableEncounters"))
			{
				DeleteAttribute(Locations[FindLocation(pchar.questTemp.ReasonToFast.PatrolLocation)], "DisableEncounters");
			}
		}	
		if(CheckAttribute(pchar, "questTemp.ReasonToFast.end"))
		{
			DeleteAttribute(pchar, "questTemp.ReasonToFast");
		}	
	}
	//************** генератор "Эпидемия на вражеском корабле" **********************
	if(CheckAttribute(pchar,"GenQuest.ShipSituation.Epidemy"))
	{
		ShipSituation_CheckConsequence(sti(pchar.GenQuest.ShipSituation.Epidemy));
	}
	//************** поверка нпс-кэпов 5 и 20 числа каждого месяца *******************
	if (GetDataDay() == 5 || GetDataDay() == 20)
	{
		if (CheckAttribute(NullCharacter, "capitainBase"))
		{
			string sName;
			int capIndex, a;
			aref arCapBase, arBase;
    		makearef(arBase, NullCharacter.capitainBase);
    		int	Qty = GetAttributesNum(arBase);
    		for (a=0; a<Qty; a++)
    		{
    			arCapBase = GetAttributeN(arBase, a);
				sName = GetAttributeName(arCapBase); //Id кэпа
				capIndex = GetCharacterIndex(sName);
    			//---------- мертв ------------
				if (capIndex == -1)
    			{	
					//страховка. если квест еще открыт - закрываем его
					/*if (CheckActiveQuest(arCapBase.Tilte1))
					{
						CitizCapIsDead_CloseQuest(arCapBase, sName);
					}*/
					DeleteAttribute(arBase, sName);
					Qty --; //для корректной работы цикла при удалении записи в базе
					a--;
				}
				//---------- жив ------------
				else
				{
					if (GetNpcQuestPastDayParam(arCapBase, "checkTime") >= sti(arCapBase.checkTime))
					{
						//if (characters[capIndex].location == "none" && characters[capIndex].quest == "InMap")
						//{
							Cap_SetMapAgain(&characters[capIndex], arCapBase);
						//}
					}
				}		
    		}
		}
	}
}

//снятие квеста, если энкаунтер кэпа исчез на карте
void CitizCapIsDead_CloseQuest(aref arCapBase, string capId)
{
	ref sld;
	string sTemp;
	//снимаем установленный таймер
	sTemp = "SecondTimer_" + capId;
	if (capId == "MushketCap") sTemp = "MushketTimer";
	if (capId == "Danielle")   sTemp = "DanielleTimer";
	pchar.quest.(sTemp).over = "yes";
	//---------- нпс-квестодатель -------------
	int iTemp = GetCharacterIndex(arCapBase.questGiver);
	if (iTemp != -1)
	{
		//снимаем прерывание на смерть квестодателя
		ref npchar = &characters[iTemp];
		if (CheckAttribute(npchar, "quest.PortmansSeekShip") || CheckAttribute(npchar, "quest.PortmansJornal"))
		{
			DeleteAttribute(npchar, "quest.PortmansSeekShip");
			DeleteAttribute(npchar, "quest.PortmansJornal");
			npchar.quest = ""; //освобождаем личный флаг квеста для портмана
		}
		else
		{
			sTemp = "SCQ_" + iTemp;
			pchar.quest.(sTemp).over = "yes"; 
			characters[iTemp].lifeDay = 0;
		}
	}
	string sTitle1 = arCapBase.Tilte1;
	string sTitle2 = arCapBase.Tilte2;
}

//переустанавливаем на карте живого, но потерянного кэпа
void Cap_SetMapAgain(ref sld, aref arCapBase) 
{
	//в морскую группу кэпа
	string sGroup = "SeekCapShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	switch (arCapBase.quest)
	{
	case "mushket": 
		if (sld.cityShore == sld.quest.targetShore)
		{
			sld.quest.targetShore = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "citizen": 
		if (sld.city == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.city);
		}
		Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "robber": 
		if (sld.city == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.city);
		}
		Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "jornal": 
		if (sld.quest.baseShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.quest.baseShore);
		}
		Map_CreateTrader(sld.quest.baseShore, sld.quest.targetCity, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "Danielle": 
		if (sld.cityShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break
	case "Avrora": 
		if (sld.cityShore == sld.quest.targetCity)
		{
			sld.quest.targetCity = SelectAnyColony(sld.cityShore);
		}
		Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, sti(arCapBase.checkTime)-5);
		break

	}
	//меняем сроки проверки по Id кэпа в базе нпс-кэпов
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = iTemp + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

// -- нищие --
void PoormansInit()
{
	ref sld;
	//нищий в Сент-Джонсе
	sld = GetCharacter(NPC_GenerateCharacter("SentJons_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "SentJons";	
	sld.location	= "SentJons_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto15";
	sld.forSit.locator1 = "goto17"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto4";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//нищий в Бриджтауне
	sld = GetCharacter(NPC_GenerateCharacter("Bridgetown_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "Bridgetown";
	sld.location	= "Bridgetown_town";
	sld.location.group = "goto";
	sld.location.locator = "goto12";
	sld.forStay.locator = "goto12"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto19"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto4";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//нищий в Белизе
	sld = GetCharacter(NPC_GenerateCharacter("Beliz_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "Beliz";
	sld.location	= "Beliz_town";
	sld.location.group = "goto";
	sld.location.locator = "goto9";
	sld.forStay.locator = "goto9"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto7";
	sld.forSit.locator1 = "goto19"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto3";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//нищий в Каракасе
	sld = GetCharacter(NPC_GenerateCharacter("Caracas_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Caracas";
	sld.location	= "Caracas_town";
	sld.location.group = "goto";
	sld.location.locator = "goto20";
	sld.forStay.locator = "goto20"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto1";
	sld.forSit.locator1 = "goto21"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto23";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Картахене
	sld = GetCharacter(NPC_GenerateCharacter("Cartahena_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Cartahena";
	sld.location	= "Cartahena_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto18";
	sld.forSit.locator1 = "goto14"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto6";
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Кумане
	sld = GetCharacter(NPC_GenerateCharacter("Cumana_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Cumana";
	sld.location	= "Cumana_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto13";
	sld.forSit.locator1 = "goto15"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");	
	//нищий в Бас-Тере, Гваделупа
	
	sld = GetCharacter(NPC_GenerateCharacter("BasTer_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "BasTer";
	sld.location	= "BasTer_town";
	sld.location.group = "goto";
	sld.location.locator = "goto18";
	sld.forStay.locator = "goto18"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto24";
	sld.forSit.locator1 = "goto16"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto17";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	
	//нищий в Гаване
	sld = GetCharacter(NPC_GenerateCharacter("Havana_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Havana";
	sld.location	= "Havana_town";
	sld.location.group = "goto";
	sld.location.locator = "goto12";
	sld.forStay.locator = "goto12"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto22"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto23";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Порт Рояле
	sld = GetCharacter(NPC_GenerateCharacter("PortRoyal_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, ENGLAND, -1, false, "slave"));
	sld.city = "PortRoyal";
	sld.location	= "PortRoyal_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15";
	sld.forStay.locator = "goto15"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto28"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto7";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
	//нищий в Форт де Франсе, Мартиника
	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "goto";
	sld.location.locator = "goto4";
	sld.forStay.locator = "goto4"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto14";
	sld.forSit.locator1 = "goto10"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//нищий на Сент-Кристофере
	sld = GetCharacter(NPC_GenerateCharacter("Charles_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "Charles";
	sld.location	= "Charles_town";
	sld.location.group = "goto";
	sld.location.locator = "goto5";
	sld.forStay.locator = "goto5"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto19";
	sld.forSit.locator1 = "goto13"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//нищий в Порто Белло
	sld = GetCharacter(NPC_GenerateCharacter("PortoBello_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "PortoBello";
	sld.location	= "PortoBello_town";
	sld.location.group = "goto";
	sld.location.locator = "goto15";
	sld.forStay.locator = "goto15"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto3";
	sld.forSit.locator1 = "goto25"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto12";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Порт-о-Принс, Эспаньола
	sld = GetCharacter(NPC_GenerateCharacter("PortPax_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "PortPax";
	sld.location	= "PortPax_town";
	sld.location.group = "goto";
	sld.location.locator = "goto14";
	sld.forStay.locator = "goto14"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto25";
	sld.forSit.locator1 = "goto13"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto11";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//нищий в Сантьяго
	sld = GetCharacter(NPC_GenerateCharacter("Santiago_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "Santiago";
	sld.location	= "Santiago_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto3";
	sld.forSit.locator1 = "goto15"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto28";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Мариго, Сан Мартин
	sld = GetCharacter(NPC_GenerateCharacter("Marigo_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, HOLLAND, -1, false, "slave"));
	sld.city = "Marigo";
	sld.location	= "Marigo_town";
	sld.location.group = "goto";
	sld.location.locator = "goto16";
	sld.forStay.locator = "goto16"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto1";
	sld.forSit.locator1 = "goto4"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto9";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
	//нищий в Тортуге
	sld = GetCharacter(NPC_GenerateCharacter("Tortuga_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, FRANCE, -1, false, "slave"));
	sld.city = "Tortuga";
	sld.location	= "Tortuga_town";
	sld.location.group = "goto";
	sld.location.locator = "goto23";
	sld.forStay.locator = "goto23"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto16";
	sld.forSit.locator1 = "goto18"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
	//нищий в Сан-Хосе, Тринидад
	sld = GetCharacter(NPC_GenerateCharacter("PortSpein_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "PortSpein";
	sld.location	= "PortSpein_town";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto14"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	//нищий в Вилья Алегрии, Пуэрто-Рико
	sld = GetCharacter(NPC_GenerateCharacter("VillaAlegria_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "VillaAlegria";
	sld.location	= "VillaAlegria_town2";
	sld.location.group = "goto";
	sld.location.locator = "goto6";
	sld.forStay.locator = "goto6"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto9";
	sld.forSit.locator1 = "goto14"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
	//нищий в Сент-Луисе
	sld = GetCharacter(NPC_GenerateCharacter("SantLous_Poorman", "panhandler_"+(rand(5)+1), "man", "man", 5, SPAIN, -1, false, "slave"));
	sld.city = "SantLous";
	sld.location	= "SantLous_town";
	sld.location.group = "goto";
	sld.location.locator = "goto13";
	sld.forStay.locator = "goto13"; //где генеримся в случае стояния
	sld.forSit.locator0 = "goto17";
	sld.forSit.locator1 = "goto15"; //три локатора, где генеримся в случае сидения
	sld.forSit.locator2 = "goto11";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Gothic_Quest\npc\Common_poorman.c";
	LAi_SetPoorType(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "poorman_male";
	LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");

	//несчастный мушкетер
	sld = GetCharacter(NPC_GenerateCharacter("OffMushketer", "MusketeerEnglish_1", "man", "man", 25, ENGLAND, -1, false, "quest"));
	sld.name = "Хемфри";
	sld.lastname = "Дуглас";
	sld.location	= "SantLous_PirateHouse";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "OffMushketer";
	SetSelfSkill(sld, 80, 10, 2, 100, 80);
	SetShipSkill(sld, 5, 5, 2, 10, 5, 20, 10, 10, 70);
	SetSPECIAL(sld, 7, 4, 9, 3, 8, 7, 9);
	LAi_SetLoginTime(sld, 9.0, 21.99);
	LAi_SetSitType(sld);
	sld.greeting = "cit_common";
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "HPPlus");
	SetCharacterPerk(sld, "Medic");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	DeleteAttribute(sld, "Items");
	LAi_SetLoginTime(sld, 0.0, 23.99);
	sld.HoldEquip = true; //удерживать оружие при обмене предметами


	//горожане сидячие в городах Форт де Франсе, Мартиника
	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty1", "Women_24", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit7";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty2", "Women_25", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit10";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty3", "Women_26", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit1";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty4", "Women_23", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit3";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

	sld = GetCharacter(NPC_GenerateCharacter("FortFrance_CitizQty5", "Women_21", "woman", "woman", 5, FRANCE, -1, false, ""));
	sld.city = "FortFrance";
	sld.location	= "FortFrance_town";
	sld.location.group = "sit";
	sld.location.locator = "sit5";
	LAi_SetLoginTime(sld, 9.0, 21.99);
	sld.Dialog.Filename = "Population\Towngirl.c";
	LAi_SetSitTypeNoGroup(sld);
	LAi_SetHP(sld, 50.0, 50.0);
	sld.greeting = "citizen_female";
	LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");


}

//ищем город определенной нации, проверять наличие ростовщика и тавернщика
string GetQuestNationsCity(int _nation) 
{
	int n, iRes;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation != "none"  && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].id != "VillaAlegria" && sti(colonies[n].nation) == _nation && GiveArealByLocation(loadedLocation) != colonies[n].island) //не на свой остров
		{
			if (GetCharacterIndex(colonies[n].id + "_tavernkeeper") > 0 && GetCharacterIndex(colonies[n].id + "_usurer") > 0)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	iRes = storeArray[dRand(howStore-1)];
	return colonies[iRes].id;
}

//ищем не вражескую колонию, куда можно доплыть
string SelectNotEnemyColony(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (nation != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //не на свой остров
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

//ищем любую национальную колонию, куда можно доплыть
string SelectAnyColony(string _City)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "SanAndres" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetIslandByCityName(_City) != colonies[n].islandLable) //не на свой остров
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}

string SelectAnyColony2(string _City1, string _City2)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "SanAndres" && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetIslandByCityName(_City1) != colonies[n].islandLable && GetIslandByCityName(_City2) != colonies[n].islandLable) //не на свой остров
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}



//=============== капитан Шарп ====================
string Sharp_choiceAction()
{
	string sBack;
	ref sld;
	//удалим Шарпа с карты, если он плывет еще где-то
	Map_ReleaseQuestEncounter("Sharp");
	group_DeleteGroup("Sharp_Group");
	if (rand(3) != 2 && sti(pchar.questTemp.Sharp.count) < 5)
	{	//еще динамим, отправляем ГГ в другой город
		string sCity = pchar.questTemp.Sharp.City; //предыдущая цель, запомним для СЖ
		pchar.questTemp.Sharp.City.rumour = true; //флаг дать слух в городе
		pchar.questTemp.Sharp.City = GetSharpCity(); //новый город 
		sBack = GetSharpRumour_toCityTarget();
		pchar.questTemp.Sharp.count = sti(pchar.questTemp.Sharp.count) + 1; //счетчик
		AddQuestRecord("SharpPearl", "2");
		AddQuestUserData("SharpPearl", "sOldTarget", XI_ConvertString("Colony" + sCity + "Dat"));
		AddQuestUserData("SharpPearl", "sTarget", XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc"));
		if (GetIslandByCityName(pchar.questTemp.Sharp.City) != pchar.questTemp.Sharp.City)
		{
			AddQuestUserData("SharpPearl", "sAreal", ", что находится на " + XI_ConvertString(GetIslandByCityName(pchar.questTemp.Sharp.City) + "Dat"));
		}
		//запускаем опять Шарпа на карту
		sld = characterFromId("Sharp");
		string sGroup = "Sharp_Group";
		Group_FindOrCreateGroup(sGroup);
		Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
		Group_LockTask(sGroup);
		Group_AddCharacter(sGroup, sld.id);
		Group_SetGroupCommander(sGroup, sld.id);
		sld.mapEnc.type = "trade";
		sld.mapEnc.worldMapShip = "quest_ship";
		sld.mapEnc.Name = "бриг 'Шарпоносец'";
		string sColony= SelectAnyColony(sCity); //колония, откуда плывет Шарп
		int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sColony), GetArealByCityName(pchar.questTemp.Sharp.City))+3; //дней доехать даем с запасом
		Map_CreateTrader(sColony, pchar.questTemp.Sharp.City, sld.id, daysQty);
	}
	else
	{
		if (rand(5) < 4)
		{
			sBack = GetSharpRumour_inIsland();
			pchar.questTemp.Sharp.Island = GiveArealByLocation(loadedLocation);
			pchar.questTemp.Sharp.count = 0; //счетчик нулим для след. раза
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //цена за наводку
			pchar.questTemp.Sharp.price.evil = rand(1); //добрый или злой, для скидки
			Pchar.quest.Sharp_loginNearIsland.win_condition.l1 = "location";
			Pchar.quest.Sharp_loginNearIsland.win_condition.l1.location = pchar.questTemp.Sharp.Island;
			Pchar.quest.Sharp_loginNearIsland.function = "Sharp_loginNearIsland";
			AddQuestRecord("SharpPearl", "3");
			SaveCurrentQuestDateParam("questTemp.Sharp");
			Log_QuestInfo("Сработало на остров.");
		}
		else
		{
			sBack = GetSharpRumour_inCity();
			pchar.questTemp.Sharp.count = 0; //счетчик нулим для след. раза
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //цена за наводку
			pchar.questTemp.Sharp.price.evil = rand(1); //добрый или злой, для скидки
			float locx, locy, locz;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			sld = &characters[GetCharacterIndex("Sharp")];
			sld.dialog.currentnode = "CitySharp";
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			ChangeCharacterAddressGroup(sld, pchar.location, "patrol", LAi_FindFarLocator("patrol", locx, locy, locz));
			AddQuestRecord("SharpPearl", "11");
			Log_QuestInfo("Сработало на город.");
		}
	}
	return sBack;
}

//ищем новый город 
string GetSharpCity()
{
	int n, iRes;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	if (GetBaseHeroNation() != PIRATE)
	{
	for(n=0; n<MAX_COLONIES; n++)
	{
	if (colonies[n].nation != "none" && GetRelation2BaseNation(sti(colonies[n].nation)) != RELATION_ENEMY && GiveArealByLocation(loadedLocation) != colonies[n].island && colonies[n].id != "Panama") //не на свой остров
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	}
	else
	{
		for(n=0; n<MAX_COLONIES; n++)
		{
			if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GiveArealByLocation(loadedLocation) != colonies[n].island && colonies[n].id != "Panama") //не на свой остров
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	iRes = storeArray[rand(howStore-1)];
	return colonies[iRes].id;
}
//фразы по умолчанию
string GetSharpRumour_default()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "Капитан Шарп был здесь, я его видел. Но сейчас его в городе нет, а куда ушел - не знаю."; break;
        case 1: sRumour = "Капитан Шарп заходил в наш город. Где он сейчас я не знаю, у нас его точно нет."; break;
        case 2:	sRumour = "Капитан Барталомью Шарп ушел из города буквально на днях..."; break;
    }
	return sRumour;
}
//фразы в другой город
string GetSharpRumour_toCityTarget()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "Капитан Бартоломью Шарп был у нас в городе и, как всегда, умудрился 'отметиться'... Но сейчас его здесь нет. По слухам он ушел в " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + "."; break;
        case 1: sRumour = "Знаете, капитан Шарп был в городе недавно. Веселый пират, этот Барталомью... Хорошо, однако, что он покинул наш город. Кажется он ушел в " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + "."; break;
        case 2:	sRumour = "Вы знаете, недавно нас почтил своим присутствием капитан Шарп. Но, к нашему большому разочарованию, нового карибского анекдота 'от Шарпа' не случилось. Жаль... А сейчас его нет у нас в городе. Говорят, он ушел в " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + ". Может им повезет..."; break;
    }
	return sRumour;
}
//фразы у осрова
string GetSharpRumour_inIsland()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "Вы знаете, капитан Шарп только что вышел из города на своем бриге. Если бы вы прибыли с пол часа назад, то увидели бы его прямо в порту."; break;
        case 1: sRumour = "Капитан Шарп... Да уже, тот еще капитан. Знаете, он только что покинул наш город. Если вы поторопитесь, то сможете его застать в окрестных водах."; break;
        case 2:	sRumour = "Бартоломью Шарп буквально с час назад вышел из нашего порта в море."; break;
    }
	return sRumour;
}
//фразы в городе
string GetSharpRumour_inCity()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "Пару минут назад капитан Шарп столкнулся со мной лицом к лицу. Ходит здесь по улицам, странно, что не в борделе..."; break;
        case 1: sRumour = "Только что на улице довелось поговорить с капитаном Шарпом. Занятный, знаете ли, тип..."; break;
        case 2:	sRumour = "Капитан Шарп сейчас гуляет по улицам. А мы все ждем, чего же он выкинет в очередной раз..."; break;
    }
	return sRumour;
}

//=============== бриг Черная Горгулья.  ====================
string BlueBurd_setTradeShip()
{
	pchar.questTemp.BlueBird.Island = GiveArealByLocation(loadedLocation);
	Pchar.quest.BlueBird_loginFleut.win_condition.l1 = "location";
	Pchar.quest.BlueBird_loginFleut.win_condition.l1.location = pchar.questTemp.BlueBird.Island;
	Pchar.quest.BlueBird_loginFleut.function = "BlueBird_loginFleut";
	pchar.questTemp.BlueBird.nation = colonies[FindColony(pchar.questTemp.BlueBird.City)].nation; //нация колонии, откуда кораблик
	aref aName;
	makearef(aName, pchar.questTemp.BlueBird);
	SetRandomNameToShip(aName);
	AddQuestRecord("Xebeca_BlueBird", "10");
	AddQuestUserData("Xebeca_BlueBird", "sCity", XI_ConvertString("Colony" + pchar.questTemp.BlueBird.City + "Dat"));
	AddQuestUserData("Xebeca_BlueBird", "sShipName", "'" + aName.Ship.Name + "'");
	AddQuestUserData("Xebeca_BlueBird", "sCity_2", XI_ConvertString("Colony" + pchar.questTemp.BlueBird.City + "Gen"));
	AddQuestUserData("Xebeca_BlueBird", "sTradeName", GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")));
	AddQuestUserData("Xebeca_BlueBird", "sIsland", XI_ConvertString(pchar.questTemp.BlueBird.Island + "Gen"));
	SaveCurrentQuestDateParam("questTemp.BlueBird");
	return GetBlueBirdRumour_Ship(); //текст слуха
}
//фразы по слухам, наводки на корабли тоговцев
string GetBlueBirdRumour_Ship()
{
	string sRumour;
	switch (rand(2))
    {
        case 0: sRumour = "Вы знаете, местный торговец, " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + ", опять отправляет собственный флейт '" + pchar.questTemp.BlueBird.Ship.Name + "' в Старый Свет за товаром. Недавно флейт вышел из порта."; break;
		case 1: sRumour = "Хм, а дела у нашего негоцианта доморощенного идут неплохо! " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + " вновь отправил собственный флейт '" + pchar.questTemp.BlueBird.Ship.Name + "' за товаром, тот только что вышел из нашего порта."; break;
        case 2:	sRumour = "М-да, а " + GetFullName(characterFromId(pchar.questTemp.BlueBird.City + "_trader")) + " все богатеет и богатеет. Только вчера его парусник стоял под разгрузкой в порту, а сегодня порт уже попрощался с ним. Флейт '" + pchar.questTemp.BlueBird.Ship.Name + "' ушел опять за товаром, так то!"; break;
    }
	return sRumour;
}

//отдать забытый судовой журнал. помещаем в город кэпа, который приплыл к назначенной колонии
void SetCapitainFromSeaToCity(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InCity"; //флаг в городе
	sld.City = sld.quest.targetCity; //аттрибут текущего города пропишем
	sld.location	= sld.City + "_PortOffice";
	sld.location.group = "goto";
	sld.location.locator = "goto"+(rand(2)+1);
	LAi_SetCitizenType(sld);

	/*int iColony = FindColony(sld.City);
	string sGroup = "PorpmansShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
	Group_SetTaskNone(sGroup);*/

	//таймер через сколько опять выйти в море
	int Qty = rand(4)+3;
	string name = "Timer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetCapitainFromCityToSea";
	pchar.quest.(name).CapId = sld.id; //в прерывании запомним Id кэпа
	//обновим дату в базе для контроля кэпов на суше
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
	//даем слух, что кэп в городе
	AddSimpleRumourCity(LinkRandPhrase("Капитан " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' сейчас в городе. Кажется, его зовут " + GetFullName(sld) + ". Он сейчас должнен быть у начальника порта.", 
		"Вы знаете, капитана " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' сейчас можно застать у начальника порта.", 
		"Если вы хотите пообщаться с капитаном " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', то идите прямоком к начальнику порта. " + GetFullName(sld) + " сейчас там..."), sld.City, Qty, 1, "none");
}
//отдать забытый судовой журнал. записть в квестбук из слухов
void PortmansBook_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;	
		string sTitle = characters[GetCharacterIndex(sld.quest.firstCity + "_PortMan")].id + "PortmansBook_Delivery";
		AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "4");
		AddQuestUserData(sTitle, "sCapName", GetFullName(sld));
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", что находится на " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//разыскать кэпа-вора. помещаем в город кэпа, который приплыл к назначенной колонии
void SetRobberFromMapToSea(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InPort"; //флаг кэпа стоит в порту
	sld.City = sld.quest.targetCity; //аттрибут текущего города пропишем
	int iColony = FindColony(sld.City);
	sld.nation = colonies[iColony].nation; //нацию дадим, что и у города

	string sGroup = "SeekCapShip_" + sld.index;
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
	Group_SetTaskNone(sGroup);

	//таймер через сколько опять выйти на карту
	int Qty = rand(5)+4;
	string name = "SecondTimer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetRobberFromSeaToMap";
	pchar.quest.(name).CapId = sld.id; //в прерывании запомним Id кэпа
	//обновим дату в базе для контроля кэпов на суше
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
	//даем слух, что кэп на рейде
	AddSimpleRumourCity(LinkRandPhrase("Капитан " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' стоит в порту на рейде. Кажется, его зовут " + GetFullName(sld) + ". Странный тип, скажу я вам, на берег не сходит вообще.", 
		"Вы знаете, капитана " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' сейчас можно встретить, только если выйти на шлюпке в порт. Корабль стоит на рейде, но капитан в город не выходит, предпочитает оставаться на корабле. И и недоело ему?..", 
		"Если вы хотите пообщаться с капитаном " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', то выходите в порт. " + GetFullName(sld) + " вроде бы его зовут... В общем, он бросил якорь в порту, но на берег не сходит. Настоящий морской волк, даже с палубной качкой расставаться не хочет."), sld.City, Qty, 1, "none");
}
//разыскать кэпа-вора. запись в квестбук из слухов
void PortmansSeekShip_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;	
		ref npchar = &characters[GetCharacterIndex(sld.quest.firstCity + "_PortMan")];
		string sTitle = npchar.id + "Portmans_SeekShip";
		AddQuestRecordEx(sTitle, "Portmans_SeekShip", "3");
		AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName)));
		AddQuestUserData(sTitle, "sShipName", sld.Ship.name);
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		iTemp = RealShips[sti(sld.Ship.Type)].basetype;
		AddQuestUserData(sTitle, "sSexWord", GetShipSexWord(ShipsTypes[iTemp].name, "ушел", "ушла"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", что находится на " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//розыск кэпов горожанами
void CitizCapFromMapToCity(string sChar)
{
	ref sld = &characters[GetCharacterIndex(sChar)];
	sld.quest = "InCity"; //флаг кэпа ходит по городу
	sld.City = sld.quest.targetCity; //аттрибут текущего города пропишем
	int iColony = FindColony(sld.City);
	sld.nation = colonies[iColony].nation; //нацию дадим, что и у города
	if (rand(1))
	{	//ходит в городе
		sld.location	= sld.City + "_town";
		sld.location.group = "goto";
		sld.location.locator = "goto"+(rand(5)+1);
		LAi_SetCitizenType(sld);
		string slai_group = GetNationNameByType(sti(colonies[iColony].nation))  + "_citizens";
		LAi_group_MoveCharacter(sld, slai_group);
		//даем слух, что кэп на рейде
		AddSimpleRumourCity(LinkRandPhrase("Капитан " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' в городе. Кажется, его зовут " + GetFullName(sld) + ".", 
			"Вы знаете, капитана " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' сейчас можно застать в городе.", 
			"Если вы хотите пообщаться с капитаном " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', то поищите его в на улицах. " + GetFullName(sld) + " вроде бы его зовут..."), sld.City, Qty, 1, "none");
	}
	else
	{	//стоит на рейде в порту
		string sGroup = "SeekCapShip_" + sld.index;
		group_DeleteGroup(sGroup);
		Group_AddCharacter(sGroup, sld.id);			
		Group_SetGroupCommander(sGroup, sld.id);
		Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+1));
		Group_SetTaskNone(sGroup);
		//даем слух, что кэп на рейде
		AddSimpleRumourCity(LinkRandPhrase("Капитан " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' находится в порту на рейде. Кажется, его зовут " + GetFullName(sld) + ".", 
			"Вы знаете, капитана " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "' сейчас можно застать в нашем порту. Его корабль стоит на рейде.", 
			"Если вы хотите пообщаться с капитаном " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "', то поищите его корабль в нашем порту. " + GetFullName(sld) + " вроде бы его зовут..."), sld.City, Qty, 1, "none");
	}
	//таймер через сколько опять выйти на карту
	int Qty = rand(7)+5; //через сколько дней выйдем на карту
	string name = "SecondTimer_" + sld.id;
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "CitizCapFromSeaToMap";
	pchar.quest.(name).CapId = sld.id; //в прерывании запомним Id кэпа
	//обновим дату в базе для контроля кэпов на суше
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

//разыск кэпа от горожан. запись в квестбук из слухов
void CitizSeekCap_writeQuestBook(ref rid)
{
	int iTemp = GetCharacterIndex(rid.addString)
	if (iTemp != -1)
	{
		ref sld = &characters[iTemp];
		if (LAi_IsDead(sld)) return;
		ref npchar = &characters[GetCharacterIndex("QuestCitiz_" + sld.quest.cribCity)];
		string sTitle = sld.quest.cribCity + "SCQ_" + npchar.quest.SeekCap;
		AddQuestRecordEx(sTitle, "SCQ_" + npchar.quest.SeekCap, "3");
		AddQuestUserData(sTitle, "sCapName", GetFullName(sld));
		AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + rid.city + "Gen"));
		AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + sld.quest.targetCity + "Acc"));
		if (GetIslandByCityName(sld.quest.targetCity) != sld.quest.targetCity)
		{
			AddQuestUserData(sTitle, "sAreal", ", что находится на " + XI_ConvertString(GetIslandByCityName(sld.quest.targetCity) + "Dat"));
		}
	}
}

//таймер
void SetShowTimer(float time)
{
	pchar.showTimer = time + 0.99;
	pchar.quest.ClearTimer.win_condition.l1 = "ExitFromLocation";
	pchar.quest.ClearTimer.win_condition.l1.location = pchar.location;
	pchar.quest.ClearTimer.function = "ClearTimer";
}

void ClearTimer(string qName)
{
	DeleteAttribute(pchar, "showTimer");
	ClearAllLogStrings();
}

//создание резервной базы на абордажников для юза нефритового черепа
void CopyPassForAztecSkull()
{
	if (CheckCharacterItem(pchar, "SkullAztecs"))
	{	
        //сносим старую базу
		DeleteAttribute(pchar, "AztecSkull");
		pchar.AztecSkull = "";
		//заполняем архивную базу 
		string sTemp,;
		aref	arFromBox, arToBox;
    	makearef(arFromBox, pchar.fellows.passengers.officers);
		makearef(arToBox, pchar.AztecSkull);
		CopyAttributes(arToBox, arFromBox);
	}
}

bool IsAztecSkullOfficer(ref sld)
{
	if (!CheckAttribute(pchar, "AztecSkull.id1")) return false;
	string sTemp;
	aref arOfficer;
    makearef(arOfficer, pchar.AztecSkull);
    for (i=1; i<=3; i++)
    {
		sTemp = "id" + i;
		if (arOfficer.(sTemp) == sld.index)
		{
			return true;
		}
	}
	return false;
}

void SetAztecUsedTotem(ref _location, string _itemId, string _locator)
{
	//-----------------------------------------
	if (_itemId == "Totem_0011")    //снимаем огонь
	{
		DeleteAttribute(_location, "gotoFire"); 
		Log_SetStringToLog("Заклятие огня снято");
		pchar.questTemp.Tenoc == "takeFire";
	}
	//-----------------------------------------
	if (_itemId == "Totem_0012") //открываем каменный сундук в большом храме (с кинжалом)
	{
		DeleteAttribute(_location, "private1.closed"); 
		Log_SetStringToLog("Открыт каменный сундук");
	}	
	//-----------------------------------------
	if (_itemId == "Totem_0013") //снимаем огонь 2х
	{
		_location.lockFire.button02.active = true;
		if (CheckAttribute(_location, "lockFire.button02.active") && CheckAttribute(_location, "lockFire.button03.active"))
		{
			DeleteAttribute(_location, "gotoFire"); 
			Log_SetStringToLog("Заклятие огня снято");
			pchar.questTemp.Tenoc == "takeFire";
		}
	}
	if (_itemId == "Totem_0014") //снимаем огонь 2х
	{
		_location.lockFire.button03.active = true;
		if (CheckAttribute(_location, "lockFire.button02.active") && CheckAttribute(_location, "lockFire.button03.active"))
		{
			DeleteAttribute(_location, "gotoFire"); 
			Log_SetStringToLog("Заклятие огня снято");
			pchar.questTemp.Tenoc == "takeFire";
		}
	}
	//-----------------------------------------
	if (_itemId == "Totem_0015") //открываем каменный сундук в большом храме
	{
		DeleteAttribute(_location, "private2.closed"); 
		Log_SetStringToLog("Открыт каменный сундук");
	}
	//-----------------------------------------
	if (_itemId == "Totem_001" || _itemId == "Totem_002" || _itemId == "Totem_003" || _itemId == "Totem_004" || _itemId == "Totem_005" ||
		_itemId == "Totem_006" || _itemId == "Totem_007" || _itemId == "Totem_008" || _itemId == "Totem_009" || _itemId == "Totem_0010")
	{
		int n;
		int num = 0;
		int locIndex = sti(_location.idxTenoc); //индекс Теночтитлана
		string sTemp;
		_location.openGreatTemplee = true;
		for (int i=1 ; i<=10; i++)
		{
			sTemp = "idx" + i;
			n = sti(locations[locIndex].temples.(sTemp));
			if (CheckAttribute(locations[n], "openGreatTemplee")) num++;
		}
		if (num >= 10)
		{
			DeleteAttribute(&locations[locIndex], "reload.l32.disable");
			DeleteAttribute(&locations[locIndex], "reload.l33.disable");
			DeleteAttribute(&locations[locIndex], "reload.l34.disable");
			AddQuestRecord("Tenochtitlan", "7");
			pchar.questTemp.Teno = "takeSkull";			
	                                   //делаем видимым череп
	                                   sld = ItemsFromID("SkullAztecs");
	                                   sld.shown = true; 
	                                   sld.startLocation = "Templee_great_1";
	                                   sld.startLocator = "item1";
	                                   BackItemDescribe("SkullAztecs");
	                                   BackItemName("SkullAztecs");

		}		
	}
}


//проверка на наличие тотемов в ГГ и их использование ранее
bool CheckMainHeroTotem(string itemName)
{
    if( CheckAttribute(pchar,"Items."+itemName) && sti(pchar.Items.(itemName))>0 )	
	{
		return true;
	}
	else
	{
		for (int i=Totems_start; i<Totems_end; i++)
		{			
			if (Items[i].id == itemName)
			{
				if (CheckAttribute(&Items[i], "shown.used"))
				{
					return true;	
				}
				break;
			}
		}
	}
	return false;	
}


// --> ugeen 20.06.09 - проверка на наличие карт у ГГ
bool CheckMainHeroMap(string itemName)
{
    if( CheckAttribute(pchar,"Items."+itemName) && sti(pchar.Items.(itemName))>0 )	
	{
		return true;
	}
	return false;	
}
// <-- ugeen

// Инициализация прочих квестов. Warship
void OtherQuestCharactersInit()
{
	ref sld;
	
	// Квест "Помощь Андрэ Абелю"
	sld = GetCharacter(NPC_GenerateCharacter("Andre_Abel" , "Andre_Abel", "man", "man", 10, FRANCE, -1, true, "quest"));
	FantomMakeCoolFighter(sld, 10, 30, 35, "blade14", "pistol2", "grapeshot", 10);
	FantomMakeCoolSailor(sld, SHIP_FLEUT, "Орион", CANNON_TYPE_CANNON_LBS16, 30, 30, 30);
	sld.name = "Андрэ";
	sld.lastname = "Абель";
	sld.SaveItemsForDead = true; // сохранять на трупе вещи
	sld.DontClearDead = true; // не убирать труп через 200с
	sld.dialog.FileName = "Gothic_Quest\Andre_Abel_Dialog.c";
	sld.greeting = "cit_quest";
	LAi_SetSitType(sld);
	LAi_SetImmortal(sld, true);	// До поры нельзя убить
	SetCharacterGoods(sld, GOOD_SHIPSILK, 700);
	SetCharacterGoods(sld, GOOD_TOBACCO, 500);
	ChangeCharacterAddressGroup(sld, "FortOrange_tavern", "sit", "sit_front4");
}

//плавание мушкетерского кэпа
void SetMushketFromMapToSea()
{
	ref sld = characterFromId("MushketCap");
	sld.quest = "InShore"; //флаг кэпа стоит в порту
	sld.City = sld.quest.targetCity; //аттрибут текущего города пропишем
	int iColony = FindColony(sld.City);

	string sGroup = "MushketCapShip";
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+5));
	Group_SetTaskNone(sGroup);
	//таймер через сколько опять выйти на карту
	int Qty = rand(2)+3;
	string name = "MushketTimer";
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetMushketFromSeaToMap";
	//обновим дату в базе для контроля кэпов на суше
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

//плавание Даньки
void SetAvroraFromMapToSea()
{
	ref sld = characterFromId("Avrora");
	sld.quest = "InShore"; //флаг кэпа стоит в порту
	sld.City = sld.quest.targetCity; //аттрибут текущего города пропишем
	int iColony = FindColony(sld.City);

	string sGroup = "AvroraGroup";
	group_DeleteGroup(sGroup);
	Group_AddCharacter(sGroup, sld.id);			
	Group_SetGroupCommander(sGroup, sld.id);
	Group_SetAddress(sGroup, colonies[iColony].island, "quest_ships", "Quest_ship_"+(rand(2)+3));
	Group_SetTaskNone(sGroup);
	//таймер через сколько опять выйти на карту
	int Qty = rand(5)+7;
	string name = "AvroraTimer";
	PChar.quest.(name).win_condition.l1            = "Timer";
    PChar.quest.(name).win_condition.l1.date.day   = GetAddingDataDay(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.month = GetAddingDataMonth(0, 0, Qty);
    PChar.quest.(name).win_condition.l1.date.year  = GetAddingDataYear(0, 0, Qty);
    PChar.quest.(name).function					= "SetAvroraFromSeaToMap";
	//обновим дату в базе для контроля кэпов на суше
	string sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).checkTime = Qty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

// Warship 07.07.09 Пасхалка - бригантина "Мэри Селест"
void MaryCelesteInit()
{
	ref character, realShip;
	String capID = "MaryCelesteCapitan";
	String seaGroup = "MaryCelesteGroup";
	int good;
	
	// Сцуко.. В функции низя делать как generableGoods[15] = { GOOD_FOOD, GOOD_WEAPON, ... }; - дает ошибку
	// Если вынести из функции, то все норм
	/*int generableGoods[15] = { GOOD_FOOD, GOOD_WEAPON, GOOD_MAHOGANY, GOOD_MEDICAMENT, GOOD_ROPES,
		GOOD_SANDAL, GOOD_COFFEE, GOOD_CLOTHES, GOOD_EBONY, GOOD_TOBACCO,
		GOOD_CHOCOLATE, GOOD_WINE, GOOD_RUM, GOOD_CINNAMON, GOOD_LEATHER };*/
	
	int generableGoods[15];
	
	generableGoods[0] = GOOD_FOOD;
	generableGoods[1] = GOOD_WEAPON;
	generableGoods[2] = GOOD_MAHOGANY;
	generableGoods[3] = GOOD_MEDICAMENT;
	generableGoods[4] = GOOD_PAPRIKA;
	generableGoods[5] = GOOD_COPRA;
	generableGoods[6] = GOOD_COFFEE;
	generableGoods[7] = GOOD_CLOTHES;
	generableGoods[8] = GOOD_EBONY;
	generableGoods[9] = GOOD_TOBACCO;
	generableGoods[10] = GOOD_CHOCOLATE;
	generableGoods[11] = GOOD_WINE;
	generableGoods[12] = GOOD_RUM;
	generableGoods[13] = GOOD_CINNAMON;
	generableGoods[14] = GOOD_LEATHER;
	
	character = GetCharacter(NPC_GenerateCharacter(capID , "citiz_45", "man", "man", 50, ENGLAND, -1, true, "citizen"));
	FantomMakeCoolSailor(character, SHIP_BRIGANTINE, "Мэри Селест", CANNON_TYPE_CANNON_LBS16, 50, 50, 50);
	character.name = "Корабль пуст";
	character.lastname = "";
	character.mapEnc.type = "trade";
	character.mapEnc.Name = "бригантина 'Мэри Селест'";
	LAi_SetImmortal(character, true);
	SetCharacterGoods(character, GOOD_RUM, 700);
	Character_SetAbordageEnable(character, false); // Низя абордировать
	
	SetCrewQuantityOverMax(character, 0); // Никого живого
	
	realShip = GetRealShip(GetCharacterShipType(character));
	
	PChar.QuestTemp.MaryCeleste = "NotFind";
	PChar.QuestTemp.MaryCeleste.TurnRate = realShip.TurnRate; // Запомним, потом восстановим для интерфейса
	
	realShip.lowpolycrew = 0; // Нету никого на палубе
	realShip.TurnRate = 1; // Чтоб не особо изворотливым был
	realShip.capacity = 2820;
	
	NullCharacterGoods(character); // Нулим товары в трюме
	
	AddCharacterGoodsSimple(character, GOOD_BALLS, 		200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_GRAPES, 	200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_KNIPPELS, 	200 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_BOMBS, 		100 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_POWDER, 	500 + rand(50));
	AddCharacterGoodsSimple(character, GOOD_FOOD, 		50  + rand(50));
	AddCharacterGoodsSimple(character, GOOD_WEAPON, 	20  + rand(30));
	AddCharacterGoodsSimple(character, GOOD_MEDICAMENT, 10  + rand(20));
	AddCharacterGoodsSimple(character, GOOD_SAILCLOTH,  50  + rand(50));
	AddCharacterGoodsSimple(character, GOOD_PLANKS,     20  + rand(30));
	
	good = generableGoods[rand(14)];
	// GetCharacterFreeSpace(ref _refCharacter,int _Goods) - вернет сколько можно положить данного товара в трюм персонажу
	AddCharacterGoodsSimple(character, good, GetCharacterFreeSpace(character, good) - 1);
	
	character.AlwaysFriend = true; // Друзья навек
	character.ShipEnemyDisable = true; // Флаг не обижаться на выстрелы
	character.CanDropSails = false; // Низя спускать паруса
	
	Group_FindOrCreateGroup(seaGroup);
	Group_SetTaskAttackInMap(seaGroup, PLAYER_GROUP);
	Group_LockTask(seaGroup);
	Group_AddCharacter(seaGroup, capID);
	Group_SetGroupCommander(seaGroup, capID);
	SetRandGeraldSail(character, ENGLAND);
	
	character.fromCity = SelectAnyColony(""); // Колония, из бухты которой выйдет
	character.fromShore = GetIslandRandomShoreId(GetArealByCityName(character.fromCity));
	character.toCity = SelectAnyColony(character.fromCity); // Колония, в бухту которой придет
	character.toShore = GetIslandRandomShoreId(GetArealByCityName(character.toCity));
	
	Map_CreateTrader(character.fromShore, character.toShore, capID, GetMaxDaysFromIsland2Island(GetArealByCityName(character.toCity), GetArealByCityName(character.fromCity)));
	
	//trace("Бригантина Мэри Селест вышла из " + character.fromCity + " и направилась в " + character.toShore);
}

/// -------------------------------------------- для тестовых нужд ! не вытирать !!! --------------------------
void TestShipInCurrentSea()
{
	ref sld;

	int iRank = sti(PChar.rank) + 7;

    Group_FindOrCreateGroup("Pirate_Attack");
	Group_SetType("Pirate_Attack", "war");
	
	sld = GetCharacter(NPC_GenerateCharacter("CaptainAttack_1", "mercen_"+(rand(14)+14), "man", "man", 10, PIRATE, 3, true, "quest"));
	FantomMakeSmallSailor(sld, SHIP_VALCIRIA, "Валькирия", CANNON_TYPE_CANNON_LBS20, 60+rand(10), 55+rand(20), 55+rand(20), 50+rand(15), 55+rand(25));
	FantomMakeCoolFighter(sld, iRank, 60, 60, "blade_14", "pistol3", "grapeshot", 100);

	Group_AddCharacter("Pirate_Attack", "CaptainAttack_1");
		
	sld.SuperShooter  = true;

	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterPerk(sld, "MusketsShoot");
	
	sld.ship.Crew.Morale = 50 + rand(30);
	ChangeCrewExp(sld, "Sailors", 70 + rand(10));
	ChangeCrewExp(sld, "Cannoners", 70 + rand(10));
	ChangeCrewExp(sld, "Soldiers", 70 + rand(10));
    	
	Group_SetGroupCommander("Pirate_Attack", "CaptainAttack_1");
	Group_SetAddress("Pirate_Attack", "Cuba2", "", "");
	Group_SetTaskAttack("Pirate_Attack", PLAYER_GROUP);
	Group_LockTask("Pirate_Attack");
	SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_ENEMY);
	
	Sea_LoginGroupCurrentSea("Pirate_Attack");
	log_info("Валькирия на горизонте!");
	PlaySound("interface\_EvEnemy1.wav");
}


void SelectAscoldRendom()
{
	if (CheckAttribute(&colonies[1], "nation"))
	{
		int n, nation;
		int storeArray[MAX_COLONIES];
		int howStore = 0;
		for(n=0; n<MAX_COLONIES; n++)
		{			
			if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && colonies[n].id != "FortOrange" && colonies[n].id != "VillaAlegria" && colonies[n].id != "Minentown")
			{           
				storeArray[howStore] = n;
				howStore++;
			}
		}
		nation = storeArray[rand(howStore-1)];
		pchar.questTemp.Ascold.TraderId = colonies[nation].id + "_trader";
		nation = storeArray[rand(howStore-1)];
		pchar.questTemp.Ascold.MerchantColony = colonies[nation].id; 
		nation = storeArray[rand(howStore-1)];
		while (colonies[nation].id == "Panama")
		{
			nation = storeArray[rand(howStore-1)];
		}
		pchar.questTemp.Ascold.ShipyarderId = colonies[nation].id + "_shipyarder"; 
		pchar.questTemp.Ascold.ShipyarderColony = colonies[nation].id;
		items[GetItemIndex("Azzy_bottle")].useLocation = colonies[nation].id + "_Shipyard";
	}
}


//------------------- линейка ГПК ----------------------

ref CheckLSCCCitizen()
{
	ref rCharacter;
	string sTemp, sSeeked;
	sSeeked = GetStrSmallRegister(dialogEditStrings[3]);
	if (sSeeked == "адмирал" || sSeeked == "адмиралa")
	{
		return characterFromId("LSCCMayor");
	}
	if (sSeeked == "трактирщик" || sSeeked == "трактирщика" || sSeeked == "тавернщик"|| sSeeked == "тавернщика" || sSeeked == "хозяин таверны" || sSeeked == "хозяина таверны")
	{
		return characterFromId("LSCCBarmen");
	}
	if (sSeeked == "официантка" || sSeeked == "официантку")
	{
		return characterFromId("LSCCwaitress");
	}
	if (sSeeked == "механика" || sSeeked == "механик")
	{
		return characterFromId("LSCC_Mechanic");
	}
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(rCharacter, Characters[n]);
		if (CheckAttribute(rCharacter, "city") && rCharacter.city == "LostShipsCityy")
		{
			sTemp = GetStrSmallRegister(rCharacter.name + " " + rCharacter.lastname);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
			{
				return rCharacter;			
			}
			sTemp = GetStrSmallRegister(rCharacter.lastname);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
			{
				return rCharacter;			
			}
			else
			{
				sTemp = GetStrSmallRegister(rCharacter.name);
				if (findsubstr(sSeeked, sTemp , 0) != -1)
				{
					return rCharacter;			
				}
			}
		}
	}
	return &NullCharacter;
}

string WhereLSCCCitizen(ref rCharacter)
{
	string sShip = "none";
	string sTemp;
	if (rCharacter.location	== "LostShipsCityy_town")
	{
		sTemp = rCharacter.location.locator;
		sTemp = strcut(sTemp, 4, 5);
		switch (sTemp)
		{
			case "01": sShip = "на бэттлшипе 'Тартарус', где тюрьма"; break;
			case "02": sShip = "на фрегате 'Каролина'"; break;
			case "03": sShip = "на флейте 'Церес Смити'"; break;
			case "04": sShip = "на галеоне 'Эсмеральда', где магазин"; break;
			case "05": sShip = "на каравелле 'Флерон', где таверна"; break;
			case "06": sShip = "на пинасе 'Фурия', в носовой части"; break;
			case "07": sShip = "на пинасе 'Фурия', в кормовой части"; break;
			case "08": sShip = "на галеоне 'Глория', где церковь"; break;
			case "09": sShip = "на флейте 'Плуто'"; break;
			case "10": sShip = "на корвете 'Протектор'"; break;
			case "11": sShip = "на варшипе 'Сан Августин', где резиденция адмирала"; break;
			case "12": sShip = "на барке 'Сан Габриель', в носовой части"; break;
			case "13": sShip = "на барке 'Сан Габриель', в кормовой части"; break;
			case "14": sShip = "на бриге 'Санта Флорентина'"; break;
			case "15": sShip = "на галеоне 'Эва'"; break;
			case "16": sShip = "на галеоне 'Веласко'"; break;
		}
	}
	else
	{
		switch (rCharacter.location)
		{
			case "AvaShipInside33": sShip = "в галеоне 'Эва'"; break;
			case "CarolineBankk": sShip = "в фрегате 'Каролина'"; break;
			case "CeresSmithyy": sShip = "во флейте 'Церес Смити'"; break;
			case "EsmeraldaStoreBigg": sShip = "в галеоне 'Эсмеральда', в магазине"; break;
			case "FenixPlatformm": sShip = "в платформе 'Феникс'"; break;
			case "FernandaDiffIndoorr": sShip = "во флейте 'Фернандо Диффиндур'"; break;
			case "FleuronTavernn": sShip = "в каравелле 'Флерон', в таверне"; break;
			case "FurieShipInside22": sShip = "в пинасе 'Фурия'"; break;
			case "GloriaChurchh": sShip = "в галеоне 'Глория', в церкви"; break;
			case "PlutoStoreSmalll": sShip = "во флете 'Плуто'"; break;
			case "ProtectorFisherr": sShip = "в корвете 'Протектор'"; break;
			case "SanAugustineResidencee": sShip = "в варшипе 'Сан Августин', в резиденции адмирала"; break;
			case "SanGabrielMechanicc": sShip = "в барке 'Сан Габриель'"; break;
			case "SantaFlorentinaShipInside44": sShip = "в бриге 'Санта Флорентина'"; break;
			case "TartarusPrisonn": sShip = "в бэттлшипе 'Тартарус', в тюрьме"; break;
			case "VelascoShipInside11": sShip = "в галеоне 'Веласко'"; break;
		}
	}
	return sShip;
}

//пробежаться по сундукам
void LSCC_checkBoxes()
{
	ref loc;
	aref arBox;
	string sName;
	for(int i=0; i<MAX_LOCATIONS; i++)
	{				
		loc = &locations[i];
		if (CheckAttribute(loc, "fastreload") && loc.fastreload == "LostShipsCityy" && loc.id != "FernandaDiffIndoorr")
		{	
			for(int n=1; n<=MAX_HANDLED_BOXES; n++)
			{
				sName = "private" + n;
				if (CheckAttribute(loc, sName) && sName != "private11")
				{					
					makearef(arBox, loc.(sName));
					if (CheckAttribute(arBox, "equip") && rand(1))
					{
						DeleteAttribute(arBox, "items");
						arBox.items = "";
					}
				}
				else break;
			}
		}
	}
}

//линейка ГПК. проверить дистанцию до своих во время атаки
void LSCC_CheckCasperDistance(ref sld)
{
	if (!CheckAttribute(pchar, "questTemp.LSCC.Armo.Interrapt"))
	{
		sld.quest.checkCasper = true; //для обработки в АИ warrior
		pchar.quest.LSCC_KillOneCasper.win_condition.l1 = "NPC_Death";
		pchar.quest.LSCC_KillOneCasper.win_condition.l1.character = sld.id;
		pchar.quest.LSCC_KillOneCasper.function= "LSCC_KillOneCasper";
		pchar.quest.LSCC_KillOneCasper.casperIdx = sld.index;
		pchar.questTemp.LSCC.Armo.Interrapt = true; //чтобы не вызывать больше прерывания
	}
	float dist;
	if (GetCharacterDistByLoc(sld, "goto", "goto12_4", &dist))
	{
		if (dist < 40.0) 
		{
			LSCC_CasperIsHelp();
		}		
	}
}
//клан ломится на выручку
void LSCC_CasperIsHelp()
{
	Log_SetStringToLog("Звуки борьбы были услышаны на барке 'Сан Габриэль'.");
	chrDisableReloadToLocation = true;
	pchar.questTemp.LSCC = "toSeekMechanikCasperOff";
	//если пошел навал, то чистим квест Армо
	pchar.questTemp.LSCC.Armo = 15; //завязываем с дачей квестов от Армо
	pchar.quest.LSCC_KillOneCasper.over = "yes"; 
	pchar.quest.LSCC_checkCasperDead.over = "yes"; 
	//бойцов в подмогу
	int iTemp = GetCharacterIndex("Casper_head");
	if (iTemp != -1) ChangeCharacterAddressGroup(&characters[iTemp], "LostShipsCityy_town", "reload", "reload55");
	for (int i=1; i<=11; i++)
	{
		iTemp = GetCharacterIndex("Casper_"+i);
		if (iTemp != -1)
		{
			if (characters[iTemp].location != "LostShipsCityy_town")
			{
				ChangeCharacterAddressGroup(&characters[iTemp], "LostShipsCityy_town", "reload", "reload55");
			}
			else
			{
				if (!LAi_IsDead(&characters[iTemp]))
				{
					LAi_group_MoveCharacter(&characters[iTemp], "PearlGroup_2");
					DeleteAttribute(&characters[iTemp], "quest.checkCasper"); //сносим флаги на проверку расстояния до базы
				}
			}
		}
	}
	//мушкетеров ставим
	sld = GetCharacter(NPC_GenerateCharacter("CasperMush_1", "mush_ctz_11", "man", "mushketer", 30, PIRATE, -1, false, "quest"));
	SetCharacterPerk(sld, "GunMan");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.MusketerDistance = 0;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "quest", "mushketer1");

	sld = GetCharacter(NPC_GenerateCharacter("CasperMush_2", "mush_ctz_12", "man", "mushketer", 30, PIRATE, -1, false, "quest"));
	SetCharacterPerk(sld, "GunMan");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	sld.MusketerDistance = 0;
	LAi_SetWarriorType(sld);
	LAi_group_MoveCharacter(sld, "PearlGroup_2");
	ChangeCharacterAddressGroup(sld, "LostShipsCityy_town", "quest", "mushketer2");
	//дополнительно, на всякий случай
	//LAi_group_SetRelation("PearlGroup_2", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
	//LAi_group_FightGroups("PearlGroup_2", LAI_GROUP_PLAYER, true);
	LAi_group_SetCheck("PearlGroup_2", "OpenTheDoors");
}

//квест на мужа Элис Тейлор, после получения слуха
void LSCC_rumourElisHusband()
{
	if (!CheckActiveQuest("ISS_ElisHusband"))
	{
		pchar.questTemp.LSCC.ElisHusband = "begin";
		AddQuestRecord("ISS_ElisHusband", "1");
	}
}
//начало сразу, после первого базара с адмиралом
void LSCC_beginElisHusband()
{	
	// муж Элис Тейлор
	ref sld = GetCharacter(NPC_GenerateCharacter("MaximTailor", "shipowner_10", "man", "man", 10, PIRATE, -1, false, "quest"));
	sld.name = "Максим";
	sld.lastname = "Тейлор";
	sld.rank = 10;
	sld.city = "LostShipsCityy";
	sld.location	= "TartarusPrisonn";
	sld.location.group = "quest";
	sld.location.locator = "prison4";
	sld.dialog.filename   = "Gothic_Quest\LostShipsCity\MaximTailor.c";
	sld.dialog.currentnode   = "InPrison";
	sld.cityTape = "quest"; //тип нпс
	sld.greeting = "pirat_common";
	sld.location.hours = 4; //передвижения через .. часов
	LAi_SetGroundSitType(sld);
	LAi_group_MoveCharacter(sld, "TmpEnemy");
}

//квест со скелетом Лейтона Декстера
void LSCC_rumourLostDecster()
{
	if (!CheckActiveQuest("LSCC_findDekster"))
		AddQuestRecord("LSCC_findDekster", "1");
}
void LSCC_enterAdmiralBox()
{
	if (!CheckAttribute(pchar, "questTemp.LSCC.private10"))
	{
		if (CheckAttribute(pchar, "questTemp.LSCC.lostDecster"))
		{
			if (pchar.questTemp.LSCC.lostDecster == "seekBox")
			{
				AddQuestRecord("LSCC_findDekster", "6");	
				AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("ел","ла"));
			}
			else
			{
				iTemp = GetCharacterIndex("LSCC_Prisoner1");
				if (iTemp != 1 && CheckAttribute(&characters[iTemp], "quest.decster"))
				{
					AddQuestRecord("LSCC_findDekster", "7");	
				}
				else
				{
					AddQuestRecord("LSCC_findDekster", "9");
					AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("ел","ла"));
				}
			}		
		}
		else
		{
			AddQuestRecord("LSCC_findDekster", "8");
			AddQuestUserData("LSCC_findDekster", "sSex", GetSexPhrase("ел","ла"));
		}
		pchar.questTemp.LSCC.lostDecster = "foundAdmiralBox";
		AddSimpleRumourCityTip("Вы слышали, что Чад Каппер потерял какой-то важный для него ключ. Теперь бегает по всему Городу, ищет...", "LostShipsCityy", 10, 1, "LSCC", "LSCC_rumourAdmiralLostKey");
		pchar.questTemp.LSCC.private10 = true; //чтобы больше не срабатывало
	}
}
void LSCC_rumourAdmiralLostKey()
{
	//делаем видимым ключ
	ref sld = ItemsFromID("keyPanama");
	sld.shown = true; 
	sld.startLocation = "LostShipsCityy_town";
	sld.startLocator = "item" + (rand(4)+2);
	ChangeItemName("keyPanama", "itmname_keyPanama_LSCC");
	ChangeItemDescribe("keyPanama", "itmdescr_keyPanama_LSCC");
	SetTimerFunction("LSCC_admiralFoundOwnKey", 0, 0, 2); //таймер на снятие ключа из локатора
	pchar.questTemp.LSCC.lostDecster = "admiralLostKey";
	AddQuestRecord("LSCC_findDekster", "10");
}




