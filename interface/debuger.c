//  boal 14.02.06 меню дебугера
string totalInfo;
int idLngFile = -1;
int remInt = 0;

void InitInterface(string iniName)
{
 	StartAboveForm(true);
 	//SetTimeScale(0.0);
	//locCameraSleep(true);

	//EngineLayersOffOn(true);
	
	GameInterface.title = "titleBoal_Debug";
	
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	
	CalculateInfoData();

	CalculateCheatsInfo(); // Warship. Статистика - сколько читов юзали

	SetFormatedText("INFO_TEXT",totalInfo);//"Информация отладчика");
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0); 
	SetEventHandler("exitCancel","ProcessCancelExit",0); 
	SetEventHandler("evntDoPostExit","DoPostExit",0); 
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);

    GameInterface.reload_edit.str = "Roseau_Shipyard, reload, reload1";//"Pearl_town_1, reload, reload1";
	// Pirates_Shipyard, reload, reload1
	// boarding_cargohold, rld, loc0
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_QUICK_SAVE );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_QUICK_SAVE );
}

void IDoExit(int exitCode)
{
    EndAboveForm(true);
    //SetTimeScale(1.0);
	//locCameraSleep(false);
	
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("evntDoPostExit","DoPostExit");
	DelEventHandler("ievnt_command","ProcCommand");
 	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("ScrollTopChange","ProcScrollChange");

	if(bSeaActive)
    {
        RefreshBattleInterface();
    }
	
	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
}


void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CalculateInfoData()
{
	// тут высчитываем нужную информацию и выводим в totalInfo - Инициализация -->
	totalInfo = "Это отладчик. Позволяет выполнять заданные скриптологом функции. Кнопки: "+NewStr();
	totalInfo = totalInfo + "F1 - " + descF1 + NewStr() +
	                        "F2 - " + descF2 + NewStr() +
	                        "F3 - " + descF3 + NewStr() +
	                        "F4 - " + descF4 + NewStr() +
	                        "F5 - " + descF5 + NewStr() +
	                        "F6 - " + descF6 + NewStr() +
	                        "F7 - " + descF7 + NewStr() +
	                        "F8 - " + descF8 + NewStr() +
	                        "F9 - " + descF9 + NewStr() +
	                        "F10 - " + descF10 + NewStr() +
	                        "F11 - " + descF11 + NewStr() +
	                        "F12 - " + descF12 + NewStr() +
	                        "F13 - " + descF13 + NewStr() +
	                        "F14 - " + descF14 + NewStr() +
	                        "F15 - " + descF15 + NewStr() +
	                        "F16 - " + descF16 + NewStr() +
	                        "F17 - " + descF17 + NewStr() +
	                        "F18 - " + descF18 + NewStr() +
                            "F19 - " + descF19 + NewStr() +
                            "F20 - " + descF20 + NewStr() +
                            "F21 - " + descF21 + NewStr() +
                            "F22 - " + descF22 + NewStr() +
                            "F23 - " + descF23 + NewStr() +
	                        "F24 - " + descF24 + NewStr() +
	                        "F25 - " + descF25 + NewStr() +
	                        "F26 - " + descF26 + NewStr() +
	                        "F27 - " + descF27 + NewStr() +
	                        "F28 - " + descF28 + NewStr() +
	                        "F29 - " + descF29 + NewStr() +
	                        "F30 - " + descF30 + NewStr() +
		         "F31 - " + descF31 + NewStr() +
	                        "F32 - " + descF32 + NewStr() +
	                        "F33 - " + descF33 + NewStr() +
	                        "F34 - " + descF34 + NewStr() +
	                        "F35 - " + descF35 + NewStr() +
	                        "F36 - " + descF36 + NewStr() +
	                        "F37 - " + descF37 + NewStr() +
	                        "F38 - " + descF38 + NewStr() +
	                        "F39 - " + descF39 + NewStr() +
	                        "F40 - " + descF40 + NewStr() +
	                        "F41 - " + descF41 + NewStr() +
	                        "F42 - " + descF42 + NewStr() +
	                        "F43 - " + descF43 + NewStr() +
		         "F44 - " + descF44;
	// перевод строки (по другому у меня не вышло) +LanguageConvertString(idLngFile,"new_string");
    // тут высчитываем нужную информацию и выводим в totalInfo <--
}
void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{
	    case "B_F1":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF1();
		  }
	    break;
	    case "B_F2":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF2();
		  }
	    break;
	    case "B_F3":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF3();
		  }
	    break;
	    case "B_F4":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF4();
		  }
	    break;
	    case "B_F5":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF5();
		  }
	    break;

	    case "B_F6":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF6();
		  }
	    break;

	    case "B_F7":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF7();
		  }
	    break;

	    case "B_F8":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF8();
		  }
	    break;

	    case "B_F9":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF9();
		  }
	    break;

	    case "B_F10":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF10();
		  }
	    break;

	    case "B_F11":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF11();
		  }
	    break;

	    case "B_F12":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF12();
		  }
	    break;

	    case "B_F13":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF13();
		  }
	    break;

	    case "B_F14":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF14();
		  }
	    break;

	    case "B_F15":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF15();
		  }
	    break;

	    case "B_F16":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF16();
		  }
	    break;

	    case "B_F17":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF17();
		  }
	    break;

	    case "B_F18":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF18();
		  }
	    break;
	    
	    case "B_F19":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF19();
		  }
	    break;

        case "B_F20":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF20();
		  }
	    break;
	    
	    case "B_F21":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF21();
		  }
	    break;
	    case "B_F22":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF22();
		  }
	    break;
	    case "B_F23":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF23();
		  }
	    break;
	    case "B_F24":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF24();
		  }
	    break;
	    case "B_F25":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF25();
		  }
	    break;
	    case "B_F26":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF26();
		  }
	    break;
	    case "B_F27":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF27();
		  }
	    break;
	    case "B_F28":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF28();
		  }
	    break;
	    case "B_F29":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF29();
		  }
	    break;
	    case "B_F30":
		  if(comName=="activate" || comName=="click")
		  {
		      CalculateInfoDataF30();
		  }
	    break;
	    case "B_31":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF31();
		}
	    break;
	    case "B_32":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF32();
		}
	    break;		
		case "B_33":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF33();
		}
	    break;	
		case "B_34":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF34();
		}
	    break;
		case "B_35":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF35();
		}
	    break;
		case "B_36":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF36();
		}
	    break;
		case "B_37":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF37();
		}
	    break;
		case "B_38":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF38();
		}
	    break;
		case "B_39":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF39();
		}
	    break;	
		case "B_40":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF40();
		}
	    break;	
		case "B_41":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF41();
		}
	    break;
		case "B_42":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF42();
		}
	    break;
		case "B_43":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF43();
		}
	    break;	
		case "B_44":
		if(comName=="activate" || comName=="click")
		{
			CalculateInfoDataF44();
		}
	    break;												

	
	    case "B_BETA":
		  if(comName=="activate" || comName=="click")
		  {
              IDoExit(RC_INTERFACE_DO_BOAL_BETA);
		  }
	    break;
	    case "B_RELOAD":
		  if(comName=="activate" || comName=="click")
		  {
              ReloadByStr();
		  }
	    break;
	}
	
	CalculateCheatsInfo(); // Статистика по читам
}
/*
float GetShipMaxNeededValue(int iShipType, string _param)
{
	float NeededValue = makefloat(GetBaseShipParamFromType(iShipType, _param));
	switch (_param)
	{
		case "speedrate":
			NeededValue += ((0.77 + frandSmall(0.3)) * (NeededValue/10.0)); 
		break;
		case "turnrate":
			NeededValue += ((0.77 + frandSmall(0.3)) * (NeededValue/10.0)); 
		break;
		case "capacity":
			NeededValue += ((0.77 + frandSmall(0.3)) * (NeededValue/8.0)); 
		break;
	}
	return NeededValue;
}
*/

////////////////////////////////////////////////////////////////////////
string descF1 = "Песо + 50 000, дублоны + 100";

void CalculateInfoDataF1()
{
	// тут высчитываем нужную информацию и выводим в totalInfo - Инициализация -->
	totalInfo = descF1;
	Pchar.money = sti(Pchar.money) + 50000;
	AddItems(pchar, "gold_dublon", 100);
	
	float MaxSpeed 			= 0.0;
	float fWindAgainstSpeed = 1.2;
	float fWindDotShip 		= 0.0; 
	float angY				= 0.0;
	for(int i = 0; i < 36; i++)
	{
		angY = (i * 5)/180.0 * 3.1415926;
		fWindDotShip = GetDotProduct( 0.0, angY);	
		MaxSpeed = GetMaxSpeedZ(fWindAgainstSpeed, fWindDotShip);
		trace("MaxSpeed " + MaxSpeed + " angY " + (i*5)); 
	}
*/	
	//DumpAttributes(showWindow);

	totalInfo = totalInfo + GetAssembledString(" Денег у #sName#а теперь #dmoney#",	Pchar);
    // тут высчитываем нужную информацию и выводим в totalInfo <--
	
	//totalInfo = totalInfo + NewStr() + NewStr() + GetBestGeneratedItem("blade_32");
	
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F1", 1);
}
////////////////////////////////////////////////////////////////////////
string descF2 = "Начать тест Пиратской Саги";

void CalculateInfoDataF2()
{
	// -->
	totalInfo = descF2;
	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	pchar.questTemp.Sharlie = "saga";//флаг на Пиратскую Сагу
	DoQuestReloadToLocation("Fortfrance_dungeon", "quest", "quest5", "");
	setCharacterShipLocation(pchar, "Fortfrance_town"));
	setWDMPointXZ("Fortfrance_town");
	sld = characterFromId("Mishelle");
	sld.dialog.currentnode = "saga_5";
	LAi_SetStayType(sld);
	ChangeCharacterAddressGroup(sld, "FortFrance_Dungeon", "quest", "quest1");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Черная Жемчужина";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 5000000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F2", 1);
}
////////////////////////////////////////////////////////////////////////
string descF3 = "ID текущей локации +коорд     ";

void CalculateInfoDataF3()
{
	// -->
	totalInfo = descF3;
	ref mc;
	mc = GetMainCharacter();

	float locx, locy, locz;
	if (bSeaActive && !bAbordageStarted)
	{
	    if (CheckAttribute(mc, "Ship.pos.x"))
		{
		    totalInfo = totalInfo + NewStr() + mc.location + "     ship(x,z,y)= "+mc.Ship.pos.x +", "+mc.Ship.pos.z + ", "+mc.Ship.Ang.y;
			totalInfo = totalInfo + NewStr() + " Sea_Coord.X " + Sea_GetRealCoordX(makefloat(mc.Ship.pos.x)) + " Sea_Coord.Z " + Sea_GetRealCoordZ(makefloat(mc.Ship.pos.z));
			
		    if (false)//CheckAttribute(mc, "WMShip.Pos.x") && worldMap.island != "")
	        {
	            string sTemp = mc.curIslandId;
	            float r1 = stf(worldMap.islands.(sTemp).GoMapRadius);

				r1 *= WDM_MAP_TO_SEA_SCALE;
	            float d2 = GetDistance2D(stf(mc.Ship.Pos.x),
	                              stf(mc.Ship.Pos.z),
	                              stf(worldMap.islands.(sTemp).position.rx),
	                              stf(worldMap.islands.(sTemp).position.rz));

	            totalInfo = totalInfo + "         Координаты для карты radius= " + r1 + "   GetDistance2D= " + d2 + "      ";
	        }
		}
	}
	else
	{
  		if (IsEntity(loadedLocation))
  		{
			GetCharacterPos(GetMainCharacter(), &locx, &locy, &locz);
			totalInfo = totalInfo + "id = " + mc.location + " (x,y,z)= "+locx + ", " +locy + ", "+locz;
			totalInfo = totalInfo + NewStr() + "filespath.models = " + loadedLocation.filespath.models;
			totalInfo = totalInfo + NewStr() + "image = " + loadedLocation.image;
			totalInfo = totalInfo + NewStr() + "models.locators = " + loadedLocation.models.always.locators;
			int attrName = locations[reload_location_index].index;
			totalInfo = totalInfo + NewStr() + "locationIDX = " + attrName;
			
			if(CheckAttribute(LoadedLocation, "islandId"))
			{
				totalInfo = totalInfo + NewStr() + "islandId = " + LoadedLocation.islandId;
			}
			
			if(CheckAttribute(LoadedLocation, "townsack"))
			{
				totalInfo = totalInfo + NewStr() + "townsack = " + LoadedLocation.townsack;
			}
		}
	}
/*	
	aref rootItems;
    makearef(rootItems, worldMap);  //Islands[0]
	DumpAttributes(rootItems);
*/	
	totalInfo = totalInfo + NewStr() + " MapShipX " +	worldMap.playerShipX + " MapShipZ " + worldMap.playerShipZ + " X " + worldMap.island.x + " Z " + worldMap.island.z;
	
	totalInfo = totalInfo + NewStr() + " Map_Coord.X " + Map_GetRealCoordX(makefloat(worldMap.playerShipX)) + " Map_Coord.Z " + Map_GetRealCoordZ(makefloat(worldMap.playerShipZ));
	
	totalInfo = totalInfo + NewStr() + " Zero_Point_X " + makefloat(worldMap.zeroX) + " Zero_Point_Z " + makefloat(worldMap.zeroZ);
    // <
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	GetRealCoordsObjects();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F3", 1);
}
////////////////////////////////////////////////////////////////////////
string descF4 = "Опыт команды +10";

void CalculateInfoDataF4()
{
	// -->
	totalInfo = descF4;
	
    ChangeCrewExp(pchar, "Sailors", 10);
	ChangeCrewExp(pchar, "Cannoners", 10);
	ChangeCrewExp(pchar, "Soldiers", 10);
/*
	int i;
	for(i = 0; i < 200; i++)
		UpdateStore(&Stores[Villemstad_STORE]);
		
	for(i = 0; i < 200; i++)
		UpdateStore(&Stores[Tortuga_STORE]);	
*/
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F4", 1);
}
////////////////////////////////////////////////////////////////////////
string descF5 = "Ранг +1 (35 скилов)";
int BOAL_debug_num = 1;
void CalculateInfoDataF5()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF5;
  
    pchar.Skill.FreeSkill = sti(pchar.Skill.FreeSkill) + 35;
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F5", 1);
}
////////////////////////////////////////////////////////////////////////
string descF6 = "Начать тест квеста LSC";

void CalculateInfoDataF6()
{
	// шаман
	ref sld;

	Saga_CreateSnakeEye();
	sld = characterFromId("SnakeEye");
	sld.dialog.currentnode = "First time";
	// Элиза:
	sld = characterFromId("Helena");
	sld.HeroModel = "Eliza_0,Eliza_1,Eliza_2,Eliza_3,Eliza_4,protocusto,Eliza_0,Eliza_0";
	LAi_SetImmortal(sld, false);
	sld.quest.OfficerPrice = sti(pchar.rank)*500;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.CompanionDisable = true; //нельзя в компаньоны - чтобы не утонула
	sld.HalfImmortal = true; //чтобы не убили в сухопутном бою
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	sld.dialog.currentnode = "Helena_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	pchar.questTemp.Saga.Helena_friend = "true"; // друг
	// Даниэль
	sld = characterFromId("Danielle");
	sld.quest.OfficerPrice = sti(pchar.rank)*700;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.CompanionDisable = true; //нельзя в компаньоны - чтобы не утонула
	LAi_SetImmortal(sld, false);
	sld.HalfImmortal = true; //чтобы не убили в сухопутном бою
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	sld.dialog.currentnode = "Danielle_officer";
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	// атрибуты
	pchar.questTemp.Saga = "baronsquests_1";
	pchar.questTemp.Saga.BaronReturn = "first_teleport";
	pchar.questTemp.Saga.SharkHunt = "LSC";
	pchar.questTemp.Dolly = true; // телепорты работают!
	LAi_LocationDisableOfficersGen("Pearl_jungle_03", true); // не пускать офицеров в локу телепорта
	AddQuestRecord("BaronReturn", "1");
	AddQuestRecord("BaronReturn", "4");
	LocatorReloadEnterDisable("SantaCatalina_houseS1", "reload2", false);
	// предметы
	TakeNItems(pchar, "ultimate_potion", 3);
	TakeNItems(pchar, "potion2", 5);
	TakeNItems(pchar, "potion3", 3);
	GiveItem2Character(pchar, "letter_svenson");
	// прерывание
	sld = characterFromId("Danielle");
	sld.quest.talk = "teleport";
	pchar.quest.BaronReturn_out1.win_condition.l1 = "location";
	pchar.quest.BaronReturn_out1.win_condition.l1.location = "Miskito_village";
	pchar.quest.BaronReturn_out1.function = "Saga_DannyTalk";
	// установка
	DoQuestReloadToLocation("Miskito_village", "reload", "reload3", "");
	setCharacterShipLocation(pchar, "Shore9"));
	setWDMPointXZ("Shore9");
 	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F6", 1);
}
////////////////////////////////////////////////////////////////////////
string descF7 = "Начать тест квеста Голландский Гамбит";

void CalculateInfoDataF7()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF7;
                   chrDisableReloadToLocation = false;   
	//SetRandSelfSkill(PChar, 1, 1);
	// дага
	AddItems(pchar, "knife_01", 1);
	ref sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Гамбита - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	pchar.questTemp.Sharlie = "gambitstage"; // флаг на Гамбит
	DoQuestReloadToLocation("Fortfrance_dungeon", "quest", "quest5", "");
	setCharacterShipLocation(pchar, "Fortfrance_town"));
	setWDMPointXZ("Fortfrance_town");
	sld = characterFromId("Mishelle");
	sld.dialog.currentnode = "First time";
	LAi_SetStayType(sld);
	ChangeCharacterAddressGroup(sld, "FortFrance_Dungeon", "quest", "quest1");
	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetSelfSkill(mc, 30, 30, 30, 30, 30);
	SetShipSkill(mc, 45, 45, 45, 45, 45, 45, 45, 45, 45);
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 8;
	LAi_SetHP(mc, 130.0, 130.0);
	mc.Ship.Type = GenerateShipExt(SHIP_VALCIRIA_QUEST, true, mc);
	mc.Ship.name = "Черная Горгулья";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 50;
	mc.Ship.Crew.Exp.Sailors = 50;
	mc.Ship.Crew.Exp.Cannoners = 50;
	mc.Ship.Crew.Exp.Soldiers = 50;

	SetCharacterGoods(mc, GOOD_BALLS, 300);
	SetCharacterGoods(mc, GOOD_GRAPES, 300);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 300);
	SetCharacterGoods(mc, GOOD_BOMBS, 300);
	SetCharacterGoods(mc, GOOD_FOOD, 700);
	SetCharacterGoods(mc, GOOD_POWDER, 700);
	SetCharacterGoods(mc, GOOD_WEAPON, 250);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 200);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 50000);
	AddItems(mc, "spyglass6", 1);
	AddItems(mc, "pistol10", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade301");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass1", 1);
	EquipCharacterbyItem(mc, "spyglass6");
	EquipCharacterbyItem(mc, "pistol10");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass1");
	AddItems(mc, "cartridge", 20);
	AddItems(mc, "bullet", 20);
	AddItems(mc, "gunpowder", 20);
	AddItems(mc, "potion1", 10);
	AddItems(mc, "potion2", 5);
	AddItems(mc, "minepick", 1);
	LAi_SetCharacterUseBullet(mc, "cartridge");
 	
    
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F7", 1);
}
////////////////////////////////////////////////////////////////////////
string descF8 = "телепорт по тавернам";

void CalculateInfoDataF8()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF8;
	ref mc, ch;
	int n, idx;
	mc = GetMainCharacter();
    idx = GetCharIDXByParam("TavernMan", "location", mc.location);
    bool ok = true;
    while (ok)
    {
        for(n=0; n<MAX_CHARACTERS; n++)
    	{
    		makeref(ch,Characters[n]);
    		if (CheckAttribute(ch, "TavernMan"))
    		{
                if (ch.location == "none") continue; // фикс для новых, невидимых до поры островов
                if (n > idx)
                {
                    ok = false;
                    if (GetCityFrom_Sea(ch.City) != "")
                    {
                        setCharacterShipLocation(mc, GetCityFrom_Sea(ch.City));
                        setWDMPointXZ(GetCityFrom_Sea(ch.City));
                    }
                    DoQuestReloadToLocation(ch.location,"reload","reload1", "");
                    Log_Info(ch.location);
                    break;
                }
    		}
        }
        idx = -1;
    }
	// <
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F8", 1);
}
////////////////////////////////////////////////////////////////////////
string descF9 = "Ветер == 14.5 + Добавить настоящую маску Кукулькана";

void CalculateInfoDataF9()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF9;
    Weather.Wind.Speed = 14.5;
	pchar.wind.speed = Weather.Wind.Speed;
	fWeatherSpeed = stf(Weather.Wind.Speed);
	// маска
	GiveItem2Character(pchar, "mask_true");
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F9", 1);
}
////////////////////////////////////////////////////////////////////////
string descF10 = "Бессмертие вкл/выкл";

void CalculateInfoDataF10()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF10;
	ref mc;
	mc = GetMainCharacter();
			if(LAi_IsImmortal(mc))
			{
				LAi_SetImmortal(mc, false);
				Log_SetStringToLog("God mode OFF");
			}else{
				LAi_SetImmortal(mc, true);
				Log_SetStringToLog("God mode ON");
			}
    // <--
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F10", 1);
}
////////////////////////////////////////////////////////////////////////
string descF11 = "Начать тест квеста 'Суп из черепахи'";

void CalculateInfoDataF11()
{
	ref sld;
	pchar.questTemp.Terrapin = "islatesoro";
	// Додсон
	sld = characterFromId("Dodson");
	ChangeCharacterAddressGroup(sld, "Pirates_townhall", "sit", "sit1");
	LAi_SetHuberType(sld);
	sld.dialog.currentnode = "First time";
	LocatorReloadEnterDisable("Pirates_town", "reload3_back", false);
	LocatorReloadEnterDisable("SantaCatalina_houseS1", "reload2", false);
	// Мэри:
	pchar.questTemp.LSC.Mary_officer = "true";
	sld = characterFromId("Mary");
	sld.quest.OfficerPrice = sti(pchar.rank)*500;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.CompanionDisable = true; //нельзя в компаньоны
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	sld.dialog.currentnode = "Mary_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	// местоположение
	DoQuestReloadToLocation("Pirates_town", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "Pirates_town"));
	setWDMPointXZ("Pirates_town");
	pchar.rank = 25;
	LAi_SetHP(pchar, 250.0, 250.0);
	SetSelfSkill(pchar, 70, 70, 70, 70, 70);
	SetShipSkill(pchar, 70, 70, 70, 70, 70, 70, 70, 70, 70);

	totalInfo = descF11;
	
	totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
	    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F11", 1);
}
////////////////////////////////////////////////////////////////////////
string descF12 = "НЗГ у всех наций +50";

void CalculateInfoDataF12()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF12;
    for (int j=0; j< MAX_NATIONS; j++)
	{
        ChangeCharacterNationReputation(pchar, j, -50);
    }
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно! ";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F12", 1);
}

/*string descF13 = "Worldmap encounters ON/OFF";

void CalculateInfoDataF13()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF13;

    ref mc;
	mc = GetMainCharacter();
    if(CheckAttribute(mc,"worldmapencountersoff") == 0)
	{
		mc.worldmapencountersoff = "1";
		Log_SetStringToLog("Worldmap encounters OFF");
	}
	else
	{
		if(mc.worldmapencountersoff == "1")
		{
			mc.worldmapencountersoff = "0";
			Log_SetStringToLog("Worldmap encounters ON");
		}
		else
		{
			mc.worldmapencountersoff = "1";
			Log_SetStringToLog("Worldmap encounters OFF");
		}
	}
    // <--
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F13", 1);
}*/

string descF13 = "Начать тест квеста 'Калеуче' - вариант 1";
void CalculateInfoDataF13()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF13;
	ref sld;
        DoQuestFunctionDelay("Caleuche_FindFirstAmulet", 10.1);
        DoQuestFunctionDelay("Gothic_Baltram_Caleuche", 2.5);// ставим клон Бальтрама
	pchar.questTemp.Caleuche = "Start";
	pchar.questTemp.Caleuche = "amulet"; 
	Log_Info("Вы получили странный амулет");
	PlaySound("interface\important_item.wav");
	GiveItem2Character(pchar, "kaleuche_amulet1");  
	pchar.questTemp.HWIC.Detector = "holl_win"; // знаем про Мерримана
	// Сага еще не пройдена, Натан на Острове, Элиза временный офицер:
	sld = characterFromId("Helena");
	sld.HeroModel = "Eliza_0,Eliza_1,Eliza_2,Eliza_3,Eliza_4,protocusto,Eliza_0,Eliza_0";
	LAi_SetImmortal(sld, false);
	sld.quest.OfficerPrice = sti(pchar.rank)*500;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.CompanionDisable = true; //нельзя в компаньоны - чтобы не утонула
	sld.HalfImmortal = true; //чтобы не убили в сухопутном бою
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	sld.dialog.currentnode = "Helena_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	pchar.questTemp.Saga.Helena_friend = "true"; // друг
	// Тичингиту
	sld = GetCharacter(NPC_GenerateCharacter("Tichingitu", "maskog", "man", "man", 5, FRANCE, -1, false, "quest"));
	sld.name = "Тиничгиту";
	sld.lastname = "";
	sld.greeting = "Tichingitu";
    sld.Dialog.Filename = "Quest\Sharlie\Tichingitu.c";
	sld.dialog.currentnode = "Tichingitu";
	sld.rank = 20;
	LAi_SetHP(sld, 200.0, 200.0);
	SetSPECIAL(sld, 4, 9, 5, 5, 10, 8, 8);
	SetSelfSkill(sld, 50, 50, 50, 50, 50);
    SetShipSkill(sld, 30, 30, 30, 30, 50, 30, 50, 50, 30);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	GiveItem2Character(sld, "blade_10");
	sld.equip.blade = "blade_10";
	GiveItem2Character(sld, "pistol5");
	sld.equip.gun = "pistol5";
	sld.quest.OfficerPrice = sti(pchar.rank)*20;
	sld.OfficerWantToGo.DontGo = true;
	sld.CanTakeMushket = true;
	sld.CompanionDisable = true;
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	LAi_SetOfficerType(sld);
	sld.dialog.currentnode = "Tichingitu_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
    
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F13", 1);
}

string descF14 = "Начать тест квеста 'Калеуче' - вариант 2";

void CalculateInfoDataF14()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF14;
	sld = characterFromId("Sh_startsailor");
	LAi_SetActorType(sld);
	LAi_ActorRunToLocation(sld, "reload", "reload5", "none", "", "", "FortFrance_Graveyard", 10.0);
        DoQuestFunctionDelay("Gothic_Baltram_Caleuche", 2.5);// ставим клон Бальтрама
        DoQuestFunctionDelay("Caleuche_FindFirstAmulet", 10.1);
	pchar.questTemp.Caleuche = "Start";
	pchar.questTemp.Caleuche = "amulet";  
	Log_Info("Вы получили странный амулет");
	PlaySound("interface\important_item.wav");
	GiveItem2Character(pchar, "kaleuche_amulet1"); 
	pchar.questTemp.HWIC.Detector = "eng_win"; // не знаем про Мерримана
	// Сага пройдена, Натан в Саванна-ла-Мар, Элиза постоянный офицер:
	sld = characterFromId("Helena");
	sld.HeroModel = "Eliza_0,Eliza_1,Eliza_2,Eliza_3,Eliza_4,protocusto,Eliza_0,Eliza_0";
	LAi_SetImmortal(sld, false);
	sld.quest.OfficerPrice = sti(pchar.rank)*500;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	LAi_SetHP(sld, 280.0, 280.0);
	sld.dialog.currentnode = "Helena_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	pchar.questTemp.Saga.Helena_officer = "true"; // друг
	// Тичингиту
	sld = GetCharacter(NPC_GenerateCharacter("Tichingitu", "maskog", "man", "man", 5, FRANCE, -1, false, "quest"));
	sld.name = "Тиничгиту";
	sld.lastname = "";
	sld.greeting = "Tichingitu";
    sld.Dialog.Filename = "Quest\Sharlie\Tichingitu.c";
	sld.dialog.currentnode = "Tichingitu";
	sld.rank = 20;
	LAi_SetHP(sld, 200.0, 200.0);
	SetSPECIAL(sld, 4, 9, 5, 5, 10, 8, 8);
	SetSelfSkill(sld, 50, 50, 50, 50, 50);
    SetShipSkill(sld, 30, 30, 30, 30, 50, 30, 50, 50, 30);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	GiveItem2Character(sld, "blade_10");
	sld.equip.blade = "blade_10";
	GiveItem2Character(sld, "pistol5");
	sld.equip.gun = "pistol5";
	sld.quest.OfficerPrice = sti(pchar.rank)*20;
	sld.OfficerWantToGo.DontGo = true;
	sld.CompanionDisable = true;
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.CanTakeMushket = true;
	sld.Payment = true;
	LAi_SetOfficerType(sld);
	sld.dialog.currentnode = "Tichingitu_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	// Саванна-ла-Мар
	sld = characterFromId("Jackman");
	ChangeCharacterAddressGroup(sld, "none", "", "");
	pchar.questTemp.NatanStory = "true";
	sld = characterFromId("Nathaniel");
	sld.model = "Hawk_2";
	Characters_RefreshModel(sld); // наверно не нужно
	sld.greeting = "nathaniel_2";
	sld.dialog.currentnode = "marun_town_4";
	ChangeCharacterAddressGroup(sld, "FortOrange_townhall", "sit", "sit1");
	LAi_SetHuberType(sld);
	LocatorReloadEnterDisable("FortOrange_town", "reload6", false); // открыть резиденцию Хоука
	
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    ProcessCancelExit();
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F14", 1);
}

string descF15 = "Начать тест квеста 'Калеуче' - вариант 3";

void CalculateInfoDataF15()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF15;
        DoQuestFunctionDelay("Caleuche_FindFirstAmulet", 10.1);
        DoQuestFunctionDelay("Gothic_Baltram_Caleuche", 2.5);// ставим клон Бальтрама
	pchar.questTemp.Caleuche = "Start";
	pchar.questTemp.Caleuche = "amulet";  
	Log_Info("Вы получили странный амулет");
	PlaySound("interface\important_item.wav");
	GiveItem2Character(pchar, "kaleuche_amulet1"); 
	pchar.questTemp.HWIC.Detector = "self_win"; // знаем про Мерримана
	// Сага пройдена, Натан в Саванне-ла-Мар, Мэри офицер:
	sld = characterFromId("Mary");
	sld.rank = 25;
	LAi_SetHP(sld, 320.0, 320.0);
	sld.quest.OfficerPrice = sti(pchar.rank)*500;
	sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
	sld.CompanionDisable = true; //нельзя в компаньоны
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	sld.DontClearDead = true;
	sld.dialog.currentnode = "Mary_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	pchar.questTemp.LSC.Mary_officer = "true";
	// Тичингиту
	sld = GetCharacter(NPC_GenerateCharacter("Tichingitu", "Maskog_mush", "man", "mushketer", 5, FRANCE, -1, false, "quest"));
	sld.name = "Тиничгиту";
	sld.lastname = "";
	sld.greeting = "Tichingitu";
    sld.Dialog.Filename = "Quest\Sharlie\Tichingitu.c";
	sld.dialog.currentnode = "Tichingitu";
	sld.rank = 20;
	LAi_SetHP(sld, 200.0, 200.0);
	SetSPECIAL(sld, 4, 9, 5, 5, 10, 8, 8);
	SetSelfSkill(sld, 50, 50, 50, 50, 50);
    SetShipSkill(sld, 30, 30, 30, 30, 50, 30, 50, 50, 30);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	GiveItem2Character(sld, "mushkett2x2");
	sld.equip.gun = "mushkett2x2";
	sld.quest.OfficerPrice = sti(pchar.rank)*20;
	sld.OfficerWantToGo.DontGo = true;
	sld.CompanionDisable = true;
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.CanTakeMushket = true;
	sld.Payment = true;
	LAi_SetOfficerType(sld);
	sld.dialog.currentnode = "Tichingitu_officer";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	// Саванна-ла-Мар
	sld = characterFromId("Jackman");
	ChangeCharacterAddressGroup(sld, "none", "", "");
	pchar.questTemp.NatanStory = "true";
	sld = characterFromId("Nathaniel");
	sld.model = "Hawk_2";
	Characters_RefreshModel(sld); // наверно не нужно
	sld.greeting = "nathaniel_2";
	sld.dialog.currentnode = "marun_town_4";
	ChangeCharacterAddressGroup(sld, "FortOrange_townhall", "sit", "sit1");
	LAi_SetHuberType(sld);
	LocatorReloadEnterDisable("FortOrange_town", "reload6", false); // открыть резиденцию Хоука
	
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    ProcessCancelExit();
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F15", 1);
}

string descF16 = "+5 дней";

void CalculateInfoDataF16()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF16;
	
    LAi_Fade("", "");
    for (int i = 1; i<=5; i++)
    {
		AddDataToCurrent(0, 0, 1);
	}
    // <
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F16", 1);
}

string descF17 = "Список квестов в pchar";

void CalculateInfoDataF17()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF17;

    aref  curItem;
	aref  arItem;
	aref rootItems;
	int i, j, n;
	string attributeName;
	ref ch;
    makearef(rootItems, pchar.quest);

    trace("=================================================");
    DumpAttributes(PChar);//&GameInterface);
    trace("=================================================");
    Log_Info("DumpAttributes");
   
    remInt++;
    totalInfo = totalInfo + " page " + remInt;
    for(i=0; i<GetAttributesNum(rootItems); i++)
    {
        if (i > remInt*60 || i < (remInt-1)*60) continue;

        curItem = GetAttributeN(rootItems, i);
		j = sti(GetAttributeValue(curItem));
		totalInfo = totalInfo+"   "+i+"= "+//LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
        GetAttributeName(curItem);// + " : " + GetAttributeValue(curItem);

    }
    if (i <= remInt*60) remInt = 0;
    // <
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F17", 1);
}

string descF18 = "ChangeShowIntarface - для скринов без надписей";

void CalculateInfoDataF18()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF18;

	ChangeShowIntarface();
    // <
    totalInfo = totalInfo + LanguageConvertString(idLngFile,"new_string") + LanguageConvertString(idLngFile,"new_string") +
                "Команда отработала успешно!";
    LanguageCloseFile(idLngFile);
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F18", 1);
}

string descF19 = "Офицеру-шкиперу +1 ранг (35 очков скилов)";
void CalculateInfoDataF19()
{
    totalInfo = descF19;
	// -->
    if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
	    ref chr = GetCharacter(sti(pchar.Fellows.Passengers.navigator));

    	chr.Skill.FreeSkill  = sti(chr.Skill.FreeSkill) + 35;
    }
    else
    {
        totalInfo = "Нет офицера";
    }
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F19", 1);
}

string descF20 = "Вызвать в текущей сухопутной локации шторм";
void CalculateInfoDataF20()
{
    totalInfo = descF20;
	// -->
	if(!bSeaActive && !IsEntity(worldMap))
	{
		ref location = &Locations[FindLocation(pchar.location)];
		if (CheckAttribute(location, "alwaysStorm"))
		{
			DeleteAttribute(location, "alwaysStorm");
			DeleteAttribute(location, "storm");
			DeleteAttribute(location, "tornado");
			DeleteAttribute(location, "QuestlockWeather");
		}
		else
		{
		location.alwaysStorm = true; 
		location.storm = true;
		location.tornado = true;
	}
	}
	DoQuestReloadToLocation(pchar.location, pchar.location.group, pchar.location.locator, "");
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F20", 1);
}

string descF21 = "Свободный полет камеры";
void CalculateInfoDataF21()
{
    totalInfo = descF21;
	// -->
	//locCameraLockNearHero(-5.0, 2.0, -5.0, 200, true);
	SendMessage(&locCamera, "l", MSG_CAMERA_FREE);
	locCameraCurMode = LOCCAMERA_FREE;
	
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F21", 1);
}

string descF22 = "Сделать доступными все возможные рецепты алхимии";
void CalculateInfoDataF22()
{
	pchar.alchemy.known = 1;
	SetCharacterPerk(pchar, "Alchemy");
	ref item;		
	for(int n = 0; n < ITEMS_QUANTITY; n++)
	{
		item = &Items[n];
		if( CheckAttribute(item,"multiobject") )
		{
			string sGood = item.id;
			pchar.alchemy.(sGood).isKnown = true;
		}
	}
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F22", 1);
}

string descF23 = "Дамп аттрибутов камеры";
void CalculateInfoDataF23()
{
	float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    totalInfo = descF23;
	// -->
    DumpAttributes(&Camera);
	
	float sinAx = sin(stf(Camera.ang.x));
	float cosAx = cos(stf(Camera.ang.x));
	float sinAy = sin(stf(Camera.ang.y));
	float cosAy = cos(stf(Camera.ang.y));
	float sinAz = sin(stf(Camera.ang.z));
	float cosAz = cos(stf(Camera.ang.z));	
	
	xx = cosAz*cosAy + sinAz*sinAx*sinAy;  		
	xy = sinAz*cosAx;  		
	xz = cosAz*(-sinAy) + sinAz*sinAx*cosAy; 
	
	zx = cosAx*sinAy;	
	zy = -sinAx; 
	zz = cosAx*cosAy;			
	
	yx = -sinAz*cosAy + cosAz*sinAx*sinAy;  		
	yy = cosAz*cosAx;  		
	yz = -sinAz* (-sinAy) + cosAz*sinAx*cosAy;
	

	totalInfo += "\n\nCamera.pos.x == " + Camera.pos.x +
		"\nCamera.pos.y = " + Camera.pos.y +
		"\nCamera.pos.z == " + Camera.pos.z +
		"\n\nCamera.ang.z == " + Camera.ang.z +
		"\nCamera.ang.y == " + Camera.ang.y +
		"\nCamera.ang.x == " + Camera.ang.x + 
		"\n XX == " + xx +
		"\n XY == " + xy +
		"\n XZ == " + xz +
		"\n YX == " + yx +
		"\n YY == " + yy +
		"\n YZ == " + yz +
		"\n ZX == " + zx +
		"\n ZX == " + zy +
		"\n ZZ == " + zz +
		"\n\n";
    // <--
	DoQuestFunctionDelay("Norman_ChangeUsualFace", 0.5);
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F23", 1);
}

string descF24 = "Специальный чит";
void CalculateInfoDataF24()
{
    totalInfo = descF24;
	ref sld;
	int i, n;
	string sTemp;
	
	//pchar.questTemp.Sharlie.DelTerGuard = "true"; // убираем пиратскую эскадру
	//DeleteAttribute(pchar, "questTemp.Sharlie.DelTerGuard");
	//chrDisableReloadToLocation = false;//открыть локацию
	//sld = characterFromId("Jino");
	//LAi_SetOwnerType(sld);
	//sld.dialog.currentnode = "First time";
	//ChangeCharacterComplexReputation(pchar, "authority", 50);
	//AddMoneyToCharacter(pchar, 650000);
	//GiveItem2Character(pchar, "Drugstore_keys");
	//LocatorReloadEnterDisable("sentjons_town", "houseF3", false);
	//GiveItem2Character(pchar, "talisman3");
	//GiveItem2Character(pchar, "spyglass5");
	
	// CloseQuestHeader("ReasonToFast");
	// DeleteAttribute(pchar, "questTemp.ReasonToFast");
	
	// CloseQuestHeader("CaptainComission2");
	// DeleteAttribute(pchar, "GenQuest.CaptainComission");
	
	// DeleteAttribute(pchar, "GenQuest.ShipWreck");
	
	// bDisableLandEncounters = false;	
	//EnemyNationHunterOnMap(true);
	//DeleteAttribute(pchar, "GenQuest.EncGirl");
	//LAi_SetPlayerType(pchar);
	//chrDisableReloadToLocation = false;
	//ChangeCharacterComplexReputation(pchar, "fame", 4);
	//DeleteAttribute(pchar, "GenQuest.CannotWait");
	
	
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F24", 1);
}

//string descF25 = "Перегруз локации - для КОЛОВ";
string descF25 = "Специальный чит";
void CalculateInfoDataF25()
{
    totalInfo = descF25;
	// -->
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
    ProcessCancelExit();
    /*if( bSeaActive && !bAbordageStarted )
    {
    	Sea_ReloadStart();
	}
	else
	{
	    DoQuestReloadToLocation(pchar.location, pchar.location.group, pchar.location.locator, "");
	}*/
	ref sld;
	int i, n;
	string sTemp;
	
	pchar.Ship.Type = GenerateShipExt(SHIP_MIRAGE, true, pchar);
	SetBaseShipData(pchar);
	RealShips[sti(pchar.Ship.Type)].ship.upgrades.hull = 1;//чистый корпус
	SetShipSailsFromFile(pchar, "ships/parus_silk.tga");
	SetSailsColor(pchar, 0);//белый хлопковый парус
	
	GiveItem2Character(pchar, "cirass8");
	
	sTemp = GetBestGeneratedItem("blade_30");
	GiveItem2Character(pchar, sTemp);
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F25", 1);
}

string descF26 = "Дамп атрибутов ГГ";
void CalculateInfoDataF26()
{
	totalInfo = descF26;
	// -->
    ref characterRef = GetMainCharacter();
	float sdp = 0.0;
		
	if(shipType != SHIP_NOTUSED) sdp = GetAllSailsDamagePercent(characterRef);
	trace(" spd = " + sdp);
	trace(" sailpercent = " + GetSailPercent(characterRef));
	
	trace("==================== " + characterRef.ID + " ====================");
	DumpAttributes(characterRef);
	trace("========================================");

	ref realShip;
	int shipType = sti(characterRef.Ship.Type);

	if(shipType != SHIP_NOTUSED) // Есть ли корабль вообще
	{
		realShip = GetRealShip(shipType);	
		DumpAttributes(realShip);
		trace("========================================");
	}
	
	string sGun = GetCharacterEquipByGroup(characterRef, GUN_ITEM_TYPE);
	if(sGun != "") 
	{
		ref rItm = ItemsFromID(sGun); 
		trace("==================== " + rItm.ID + " ====================");
		DumpAttributes(rItm);
		trace("========================================");
	}	
	
	Log_Info("Дамп аттрибутов ГГ");			
	// <--
	totalInfo = totalInfo + NewStr() + NewStr() +
		"Команда отработала успешно!";
	SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.26", 1);
}

string descF27 = "Репутация ГГ в минус";
void CalculateInfoDataF27()
{
    totalInfo = descF27;
	// -->
	if ( sti(pchar.reputation.nobility) > 1)
	{
	   pchar.reputation.nobility = sti(pchar.reputation.nobility) - 10;
	   if (sti(pchar.reputation.nobility) < 1)
	   {
	       pchar.reputation.nobility = 1;
	   }
	}
	
	trace(" -- reputation " + sti(pchar.reputation.nobility));
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F27", 1);
}

string descF28 = "Репутация ГГ в плюс";
void CalculateInfoDataF28()
{
    totalInfo = descF28;
	// -->
	if ( sti(pchar.reputation.nobility) > 1 && sti(pchar.reputation.nobility) < 100)
	{
	   pchar.reputation.nobility = sti(pchar.reputation.nobility) + 10;
	   if (sti(pchar.reputation.nobility) > 100)
	   {
	       pchar.reputation.nobility = 100;
	   }
	}
	trace(" ++ reputation " + sti(pchar.reputation.nobility));
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F28", 1);

}

string descF29 = "Декстер";
void CalculateInfoDataF29()
{
	// -->
                   chrDisableReloadToLocation = false;   
	ref mc;
	string sEquipItem;
	totalInfo = descF29;
	mc = GetMainCharacter();
	SetRandSelfSkill(mc, 100, 100);
	SetRandShipSkill(mc, 100, 100);
	mc.rank = 20;
	LAi_SetHP(mc, 250.0, 250.0);

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
                LocatorReloadEnterDisable("VillaAlegria_prison", "reload30", false);
	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "church IM";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "Quest";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "LLquest6";
	pchar.quest.Berglars_Dexter.function = "BerglarsDexter";

	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "VillaAlegria_prison";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "reload";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "reload1";
	pchar.quest.Berglars_Dexter.function = "Birglars_Info_Inquisition";

	DoQuestReloadToLocation("VillaAlegria_town2", "reload", "reload_jail", "");
	//DoQuestReloadToLocation("Xsardas_Dungeon", "quest", "quest2", "");
                   //DoQuestReloadToLocation("Xsardas_Dungeon", "goto", "goto38", "");
	//setCharacterShipLocation(pchar, "Shore98"));
	//setWDMPointXZ("Shore98");
	setCharacterShipLocation(pchar, "VillaAlegria_town"));
	setWDMPointXZ("VillaAlegria_town");

	mc.Ship.Type = GenerateShipExt(SHIP_BRIGARROW, true, mc);
	mc.Ship.name = "Стрела";
	SetBaseShipData(mc);
		
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 100);
	ChangeCrewExp(mc, "Sailors", 100);
	ChangeCrewExp(mc, "Cannoners", 100);
	ChangeCrewExp(mc, "Soldiers", 100);

	SetCharacterGoods(mc, GOOD_BALLS, 700);
	SetCharacterGoods(mc, GOOD_GRAPES, 700);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 700);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1200);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 500);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 1000000);
	AddItems(mc, "spyglass5", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass4", 1);

	EquipCharacterbyItem(mc, "spyglass5");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass4");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "gunpowder", 50);
	
	AddItems(mc, "amulet_7", 1);
	
	LAi_SetCharacterUseBullet(mc, "cartridge");

 	SelAllPerksToChar(mc, false);
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F29", 1);
}

string descF30 = "+20 дней";
void CalculateInfoDataF30()
{
    totalInfo = descF30;
	// -->
	LAi_Fade("", "");
	AddDataToCurrent(0, 0, 20);
    // <--
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
    
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F30", 1);
}

string descF31 = "Супер корабль, полная прокачка ГГ, все перки, предметы";
void CalculateInfoDataF31()
{
	ref mc;
	string sEquipItem;
	totalInfo = descF31;
	mc = GetMainCharacter();
	SetRandSelfSkill(mc, 100, 100);
	SetRandShipSkill(mc, 100, 100);
	mc.rank = 20;
	LAi_SetHP(mc, 250.0, 250.0);

	mc.Ship.Type = GenerateShipExt(SHIP_SOLEYPIR, true, mc);
	SetBaseShipData(mc);
	
//	mc.Ship.Masts.mast1   = 1;
//	mc.Ship.Masts.mast101 = 1;
	
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 100);
	ChangeCrewExp(mc, "Sailors", 100);
	ChangeCrewExp(mc, "Cannoners", 100);
	ChangeCrewExp(mc, "Soldiers", 100);

	SetCharacterGoods(mc, GOOD_BALLS, 3000);
	SetCharacterGoods(mc, GOOD_GRAPES, 3000);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 3000);
	SetCharacterGoods(mc, GOOD_BOMBS, 3000);
	SetCharacterGoods(mc, GOOD_FOOD, 2500);
	SetCharacterGoods(mc, GOOD_POWDER, 15000);
	SetCharacterGoods(mc, GOOD_WEAPON, 1200);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 600); 
	SetCharacterGoods(mc, GOOD_RUM, 300);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 10000000);
	AddItems(mc, "spyglass5", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass4", 1);
	AddItems(mc, "BackPack4", 1);

	EquipCharacterbyItem(mc, "spyglass5");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass4");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "gunpowder", 50);
	
	AddItems(mc, "amulet_7", 1);
	
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
 	SelAllPerksToChar(mc, false);
	 	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
		
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F31", 1);
}

string descF32 = "Простой корабль, неполная прокачка ГГ";
void CalculateInfoDataF32()
{
	ref mc;
	string sEquipItem;
	totalInfo = descF32;
	mc = GetMainCharacter();
	SetRandSelfSkill(mc, 50, 85);
	SetRandShipSkill(mc, 50, 85);
	mc.rank = 15;
	LAi_SetHP(mc, 250.0, 250.0);
/*
	//mc.Ship.Type = GenerateShipHand(SHIP_CAREERLUGGER, 12, 580, 30, 800, 20000, 16.5, 65.5, 1.6);
	mc.Ship.Type = GenerateShipHand(pchar, SHIP_LUGGER, 6, 700, 40, 610, 16000, 15.2, 58.8, 1.42);
	mc.Ship.name = "Сумрак";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 90;
	mc.Ship.Crew.Exp.Cannoners = 70;
	mc.Ship.Crew.Exp.Soldiers = 70;
	SetCharacterGoods(mc, GOOD_BALLS, 100);
	SetCharacterGoods(mc, GOOD_GRAPES, 100);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 100);
	SetCharacterGoods(mc, GOOD_BOMBS, 100);
	SetCharacterGoods(mc, GOOD_FOOD, 100);
	SetCharacterGoods(mc, GOOD_POWDER, 300);
	SetCharacterGoods(mc, GOOD_WEAPON, 60);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 60); 
*/
	
	//mc.Ship.Type = GenerateShipExt(SHIP_XebekVML, true, mc);	
	mc.Ship.Type = GenerateShipExt(SHIP_VALCIRIA, true, mc);	
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;

//	mc.Ship.Masts.mast2   = 1;
//	mc.Ship.Masts.mast201 = 1;
/*	
	mc.Ship.Masts.mast2   = 1;
	mc.Ship.Masts.mast201 = 1;
	mc.Ship.Masts.mast3   = 1;
	mc.Ship.Masts.mast301 = 1;
	mc.Ship.Masts.mast4   = 1;
	mc.Ship.Masts.mast401 = 1;
	mc.Ship.Masts.mast5   = 1;
*/	
	//mc.ship.SP = CalculateShipSP(mc);

//	trace("fail masts " + GetShipFallMastsQuantity(mc) + " ship.sp " + mc.ship.SP);
	mc.ship.HP = sti(mc.ship.HP) - makeint(sti(mc.ship.HP)/2);
	
//	ShipRepair(mc);
	
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 80);	
	ChangeCrewExp(mc, "Sailors", 50);
	ChangeCrewExp(mc, "Cannoners", 50);
	ChangeCrewExp(mc, "Soldiers", 50);

	SetCharacterGoods(mc, GOOD_BALLS, 300);
	SetCharacterGoods(mc, GOOD_GRAPES, 300);
	SetCharacterGoods(mc, GOOD_KNIPPELS,300);
	SetCharacterGoods(mc, GOOD_BOMBS, 300);
	SetCharacterGoods(mc, GOOD_FOOD, 300);
	SetCharacterGoods(mc, GOOD_POWDER, 700);
	SetCharacterGoods(mc, GOOD_WEAPON, 300);

	SetCharacterGoods(mc, GOOD_PLANKS, 300);
	SetCharacterGoods(mc, GOOD_SAILCLOTH, 50);
	
	// для отладки контрабаса
	//SetCharacterGoods(mc, GOOD_SLAVES, 50);
/*	
	SetCharacterGoods(mc, GOOD_SHIPSILK, 30);
	SetCharacterGoods(mc, GOOD_ROPES, 30);
	SetCharacterGoods(mc, GOOD_SANDAL, 30);
	SetCharacterGoods(mc, GOOD_OIL, 30);
*/	
	
	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 1000000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	
	AddItems(mc, "cirass3", 1);

	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass3");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "talisman7", 1);
	AddItems(mc, "amulet_7", 2);
	
	
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
// 	SetHalfPerksToChar(mc, false);
	SelAllPerksToChar(mc, false);
	
	ref realShip;
	int shipType = sti(mc.Ship.Type);

	if(shipType != SHIP_NOTUSED) // Есть ли корабль вообще
	{
		realShip = GetRealShip(shipType);
//		realShip.HP = sti(realShip.HP) - makeint(sti(realShip.HP)/5);
	}	

	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F32", 1);
}

string descF33 = "Апгрейд-тестирование";
void CalculateInfoDataF33()
{
	ref mc;
	string sEquipItem;
	totalInfo = descF33;
	mc = GetMainCharacter();
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	/*SetRandSelfSkill(mc, 50, 85);
	SetRandShipSkill(mc, 50, 85);
	mc.rank = 15;
	LAi_SetHP(mc, 250.0, 250.0);
	mc.Ship.Type = GenerateShipExt(SHIP_CORVETTE, true, mc);	
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 100);	
	ChangeCrewExp(mc, "Sailors", 100);
	ChangeCrewExp(mc, "Cannoners", 100);
	ChangeCrewExp(mc, "Soldiers", 100);

	SetCharacterGoods(mc, GOOD_BALLS, 700);
	SetCharacterGoods(mc, GOOD_GRAPES, 700);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 700);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 500);
	SetCharacterGoods(mc, GOOD_POWDER, 2000);
	SetCharacterGoods(mc, GOOD_WEAPON, 500);
	
	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 5000000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	
	AddItems(mc, "cirass3", 1);

	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass3");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	SelAllPerksToChar(mc, false);*/
	SetCharacterGoods(mc, GOOD_SHIPSILK, 1000);
	SetCharacterGoods(mc, GOOD_ROPES, 1000);
	SetCharacterGoods(mc, GOOD_SANDAL, 1000);
	SetCharacterGoods(mc, GOOD_OIL, 1000);
	
	AddItems(mc, "chest", 10);
	AddItems(mc, "icollection", 1);
	AddItems(mc, "jewelry1", 50);
	AddItems(mc, "jewelry2", 50);
	AddItems(mc, "jewelry3", 50);
	AddItems(mc, "jewelry4", 50);
	AddItems(mc, "jewelry5", 50);
	AddItems(mc, "jewelry6", 50);
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F32", 1);
}

string descF34 = "Тест оконцовки на Декстора";
void CalculateInfoDataF34()
{
	// -->
                   chrDisableReloadToLocation = false;   
	ref mc;
	string sEquipItem;
	totalInfo = descF34;
	mc = GetMainCharacter();
	SetRandSelfSkill(mc, 100, 100);
	SetRandShipSkill(mc, 100, 100);
	mc.rank = 20;
	LAi_SetHP(mc, 250.0, 250.0);

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
                LocatorReloadEnterDisable("VillaAlegria_prison", "reload30", false);
	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "church IM";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "Quest";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "LLquest6";
	pchar.quest.Berglars_Dexter.function = "BerglarsDexter";

	pchar.quest.Berglars_Dexter.win_condition.l1 = "locator";
	pchar.quest.Berglars_Dexter.win_condition.l1.location = "VillaAlegria_prison";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator_group = "reload";
	pchar.quest.Berglars_Dexter.win_condition.l1.locator = "reload1";
	pchar.quest.Berglars_Dexter.function = "Birglars_Info_Inquisition";

	DoQuestReloadToLocation("VillaAlegria_town2", "reload", "reload_jail", "");
	//DoQuestReloadToLocation("Xsardas_Dungeon", "quest", "quest2", "");
                   //DoQuestReloadToLocation("Xsardas_Dungeon", "goto", "goto38", "");
	//setCharacterShipLocation(pchar, "Shore98"));
	//setWDMPointXZ("Shore98");
	setCharacterShipLocation(pchar, "VillaAlegria_town"));
	setWDMPointXZ("VillaAlegria_town");

	mc.Ship.Type = GenerateShipExt(SHIP_BRIGARROW, true, mc);
	mc.Ship.name = "Стрела";
	SetBaseShipData(mc);
		
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 100);
	ChangeCrewExp(mc, "Sailors", 100);
	ChangeCrewExp(mc, "Cannoners", 100);
	ChangeCrewExp(mc, "Soldiers", 100);

	SetCharacterGoods(mc, GOOD_BALLS, 700);
	SetCharacterGoods(mc, GOOD_GRAPES, 700);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 700);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1200);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 500);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 1000000);
	AddItems(mc, "spyglass5", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass4", 1);

	EquipCharacterbyItem(mc, "spyglass5");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass4");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "gunpowder", 50);
	
	AddItems(mc, "amulet_7", 1);
	
	LAi_SetCharacterUseBullet(mc, "cartridge");

 	SelAllPerksToChar(mc, false);
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F34", 1);
}

string descF35 = "Аскольд инфо";

void CalculateInfoDataF35()
{
	ref sld = ItemsFromID("Rock_letter");
	totalInfo = descF35;

	totalInfo = "Рендомный хозяин магаза: " + pchar.questTemp.Ascold.TraderId + NewStr() +
	"Рендомный мерчант(колония): " + pchar.questTemp.Ascold.MerchantColony + NewStr() +
	"Рендомный верфист: " + pchar.questTemp.Ascold.ShipyarderId + NewStr() +
	"Скрижали: " + sld.startLocation;
	if (pchar.questTemp.BlueBird.City != "")
	{
		totalInfo = totalInfo + NewStr()+ "Где будут слухи по флейту торговца: " + pchar.questTemp.BlueBird.City;
	}
	else
	{
		totalInfo = totalInfo + NewStr()+ "Слухи по флейтам торговцев еще не активированы.";
	}
    totalInfo = totalInfo + NewStr() + NewStr() +
                "Команда отработала успешно!";
    SetFormatedText("INFO_TEXT",totalInfo);
 			
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F35", 1);
}

string descF36 = "Начать тест Аскольда, поиски гробницы";

void CalculateInfoDataF36()
{
	// -->
	totalInfo = descF36;
                   chrDisableReloadToLocation = false;   
	// Аскольд
	ref sld = characterFromId("Ascold");
	//sld.dialog.currentnode = "Step_31A";
	sld.dialog.currentnode = "Step_7";
	//sld = characterFromId("Roseau_trader");
	//sld.dialog.currentnode = "Gothic_FISK";

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("BasTer_town", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "BasTer_town"));
	setWDMPointXZ("BasTer_town");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_VALCIRIA_QUEST, true, mc);
	mc.Ship.name = "Черная Горгулья";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F36", 1);
}

string descF37 = "Тест города ГПК";

void CalculateInfoDataF37()
{
	totalInfo = descF37;
                   chrDisableReloadToLocation = false;   
	pchar.questTemp.LSCC = "AdmiralIsWaiting";
	bDisableFastReload = true; //закроем фастрелоады
	//из письма делаем посление Тизера Дэна -->
	TakeItemFromCharacter(pchar, "letter_LSCC");
	ChangeItemName("letter_LSCC", "itmname_letter_LSCC_2");
	ChangeItemDescribe("letter_LSCC", "itmdescr_letter_LSCC_2");
	i = FindLocation("LostShipsCityy_town");
	locations[i].private11.items.letter_LSCC = 1;

	ChangeItemName("keyQuestLSCC", "itmname_keyQuestLSCC_Tizer");
	ChangeItemDescribe("keyQuestLSCC", "itmdescr_keyQuestLSCC_Tizer");
	sld = ItemsFromID("keyQuestLSCC");
	DeleteAttribute(sld, "shown");
	GiveItem2Character(pchar, "keyQuestLSCC");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
	//LocatorReloadEnterDisable("SanGabrielMechanicc", "reload2", false);
	//LocatorReloadEnterDisable("LostShipsCityy_town", "reload55", false);
	//LocatorReloadEnterDisable("LostShipsCityy_town", "reload73", false);
	LocatorReloadEnterDisable("LostShipsCityy_town", "reload1_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("LostShipsCityy_town", "quest", "quest1", "FirstLoginLostShipsCityy");
	setCharacterShipLocation(pchar, "LostShipsCityy_town"));
	setWDMPointXZ("LostShipsCityy_town");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Черная Жемчужина";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 5000000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F37", 1);
}

string descF38 = "Начать тест Моргана, сорвать операцию Ричарда.С";

void CalculateInfoDataF38()
{
	// -->
	totalInfo = descF38;
                   chrDisableReloadToLocation = false;   
	//Морган 
	ref sld = characterFromId("Henry Morgan");
	//sld.dialog.currentnode = "PL_Q7_afterLeon";
	 sld.dialog.currentnode = "PL_Q4_1";

	//sld = characterFromId("Roseau_trader");
	//sld.dialog.currentnode = "Gothic_FISK";

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("PortRoyal_houseS1", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "PortRoyal_town"));
	setWDMPointXZ("PortRoyal_town");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_ROSSIYA, true, mc);
	mc.Ship.name = "Черный медведь";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	AddItems(mc, "jewelry8", 3);
	AddItems(mc, "jewelry7", 3);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F38", 1);
}

string descF39 = "Начать тест поход на Панаму";

void CalculateInfoDataF39()
{
	// -->
	totalInfo = descF39;
                   chrDisableReloadToLocation = false;   
	// Морган
	ref sld = characterFromId("Henry Morgan");
	sld.dialog.currentnode = "PL_Q8_1";
	LAi_SetHuberType(sld);
	ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	pchar.questTemp.Sharlie = "piratesLine";//флаг на Пиратку
	pchar.questTemp.State = "PortRoyal";
	DoQuestReloadToLocation("PortRoyal_houseS1", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "PortRoyal_town"));
	setWDMPointXZ("PortRoyal_town");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATEQVEENT, true, mc);
	mc.Ship.name = "Месть королевы Анны";
	SetBaseShipData(mc);
	
//	mc.Ship.Masts.mast1   = 1;
//	mc.Ship.Masts.mast101 = 1;
	
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	SetCrewQuantityFull(mc);
	AddCrewMorale(mc, 100);
	ChangeCrewExp(mc, "Sailors", 100);
	ChangeCrewExp(mc, "Cannoners", 100);
	ChangeCrewExp(mc, "Soldiers", 100);

	SetCharacterGoods(mc, GOOD_BALLS, 700);
	SetCharacterGoods(mc, GOOD_GRAPES, 700);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 700);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1200);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 500);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 1000000);
	AddItems(mc, "spyglass5", 1);
	AddItems(mc, "pistol5", 1);
	
	sEquipItem = GetGeneratedItem("blade_25");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass4", 1);

	EquipCharacterbyItem(mc, "spyglass5");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass4");
 	
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "gunpowder", 50);
	
	AddItems(mc, "amulet_7", 1);	
	LAi_SetCharacterUseBullet(mc, "cartridge");	
 	SelAllPerksToChar(mc, false);
	 		
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F39", 1);
}

string descF40 = "Начать тест поимки Черной бороды";

void CalculateInfoDataF40()
{
	// -->
	totalInfo = descF40;
                   chrDisableReloadToLocation = false;   
	//Морган 
	ref sld = characterFromId("LeFransua_tavernkeeper");
	sld.dialog.currentnode = "Endtaskhunt_4";

	//sld = characterFromId("Roseau_trader");
	//sld.dialog.currentnode = "Gothic_FISK";

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("LeFransua_Tavern", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "LeFransua_port"));
	setWDMPointXZ("LeFransua_port");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Черная Жемчужина";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	AddItems(mc, "jewelry8", 3);
	AddItems(mc, "jewelry7", 3);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F40", 1);
}

string descF41 = "Начать тест роджер";

void CalculateInfoDataF41()
{
	// -->
	totalInfo = descF41;
                   chrDisableReloadToLocation = false;   

	sld = characterFromId("Terrax");
	sld.dialog.currentnode = "mtraxx_71";
                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";

	sld = GetCharacter(NPC_GenerateCharacter("Mrt_Rocur", "Jan_Pikar", "man", "man", 20, PIRATE, -1, false, "quest"));
	FantomMakeCoolFighter(sld, 30, 80, 80, "blade_10", "pistol6", "bullet", 150);
	sld.name = "Жан";
	sld.lastname = "Пикар";
	sld.Dialog.Filename = "Quest\Roger.c";
	sld.Dialog.currentnode = "rocur_48";
	sld.model = "Jan_Pikar";
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "GunProfessional");
	RemoveCharacterEquip(sld, BLADE_ITEM_TYPE);
	RemoveCharacterEquip(sld, GUN_ITEM_TYPE);
	GiveItem2Character(sld, "blade_17");
	EquipCharacterbyItem(sld, "blade_17");
	GiveItem2Character(sld, "pistol6");
	EquipCharacterbyItem(sld, "pistol6");
	TakeNItems(sld, "cartridge", 40);
	LAi_SetCharacterUseBullet(sld, "cartridge");
	GiveItem2Character(sld, "cirass7");
	EquipCharacterbyItem(sld, "cirass7");
	Characters_RefreshModel(sld);
	LAi_SetCheckMinHP(sld, 10, true, "");
	TakeNItems(sld, "potion2", 7);
	TakeNItems(sld, "potion3", 7);
	TakeNItems(sld, "potion4", 7);
	ChangeCharacterAddressGroup(sld, "LaVega_exittown", "reload", "reload2_back");
	LAi_SetActorType(sld);
	LAi_ActorDialog(sld, pchar, "", -1, 0);
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	// корвет Пикара в бухту для антуража
	Group_FindOrCreateGroup("RocurSeaGroup");
	FantomMakeCoolSailor(sld, SHIP_CORVETTE, "Грифон", CANNON_TYPE_CULVERINE_LBS18, 90, 90, 90);
	sld.nation = PIRATE;
	sld.Abordage.Enable = false;
	sld.AlwaysFriend = true;
	sld.ShipEnemyDisable = true; 
	LAi_SetImmortal(sld, true); // сплошная защита от дурака
	sld.DontDeskTalk = true;
	Group_AddCharacter("RocurSeaGroup", "Mrt_Rocur");
	Group_SetGroupCommander("RocurSeaGroup", "Mrt_Rocur");
	Group_SetTaskNone("RocurSeaGroup");
	Group_SetAddress("RocurSeaGroup", "Hispaniola1", "quest_ships", "quest_ship_4");
	Group_LockTask("RocurSeaGroup");



	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("LaVega_Tavern", "reload", "reload1_back", "");
	setCharacterShipLocation(pchar, "LaVega_port"));
	setWDMPointXZ("LaVega_port");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Черная Жемчужина";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	AddItems(mc, "jewelry8", 3);
	AddItems(mc, "jewelry7", 3);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F41", 1);
}

string descF42 = "Тест локации острова Ксочитэм";
void CalculateInfoDataF42()
{
	// -->
	totalInfo = descF42;
                   chrDisableReloadToLocation = false;   

                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	AddItems(pchar, "blade300", 1);
	sld = ItemsFromID("blade300");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}

	i = FindIsland("Ksochitam");
	Islands[i].visible = true;
	Islands[i].reload_enable = true;

	DoQuestReloadToLocation("Shore65", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "Shore65"));
	setWDMPointXZ("Ksochitam");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Черная Жемчужина";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass6", 1);
	AddItems(mc, "pistol11", 1);
	AddItems(mc, "skullaztecs", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade300");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass4", 1);
	EquipCharacterbyItem(mc, "spyglass6");
	EquipCharacterbyItem(mc, "pistol11");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass4");
	EquipCharacterbyItem(mc, "skullaztecs");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");

	// Джино
	sld = GetCharacter(NPC_GenerateCharacter("Jino", "Gino", "man", "man", 20, ENGLAND, -1, false, "quest"));
	sld.name = "Джино";
	sld.lastname = "Гвинейли";
	sld.greeting = "Jino";
	sld.Dialog.Filename = "Quest\HollandGambit\Jino.c";
	sld.rank = 20;
	LAi_SetHP(sld, 200.0, 200.0);
	SetSPECIAL(sld, 4, 9, 5, 5, 10, 8, 8);
	SetSelfSkill(sld, 50, 50, 50, 50, 50);
    SetShipSkill(sld, 30, 30, 30, 30, 50, 30, 50, 50, 30);
	SetCharacterPerk(sld, "Energaiser");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "BladeDancer");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	GiveItem2Character(sld, "blade_10");
	sld.equip.blade = "blade_10";
	GiveItem2Character(sld, "pistol5");
	sld.equip.gun = "pistol5";
	sld.quest.OfficerPrice = sti(pchar.rank)*20;
	sld.OfficerWantToGo.DontGo = true;
	sld.CompanionDisable = true;
	sld.loyality = MAX_LOYALITY;
	AddPassenger(pchar, sld, false);
	SetCharacterRemovable(sld, true);
	sld.Payment = true;
	LAi_SetOfficerType(sld);
	sld.dialog.currentnode = "ksochitam_35";
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
	SaveCurrentNpcQuestDateParam(sld, "HiredDate");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F42", 1);
}

string descF43 = "Тест. Оконцовка Роджерс и продолжение - разбор полётов.";
void CalculateInfoDataF43()
{
	idLngFile = LanguageOpenFile("ItemsDescribe.txt");
	// -->
	totalInfo = descF43;
                   chrDisableReloadToLocation = false;   
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);//кабинет откроем

	DeleteAttribute(pchar, "GenQuest.Hotwater");
	AddCharacterHealth(pchar, -5);
	AddQuestRecord("Roger_10", "15");
	pchar.quest.mtraxx_retribution_shore.win_condition.l1 = "location";
	pchar.quest.mtraxx_retribution_shore.win_condition.l1.location = "Carataska_jungle_01";
	pchar.quest.mtraxx_retribution_shore.function = "Mtraxx_RetributionJungle";

	log_Testinfo("Отработал багфиксер PirateLine");
	pchar.questTemp.Mtraxx.BugsFixer = "true";
	if (pchar.questTemp.Mtraxx == "full_complete" || pchar.questTemp.Mtraxx == "fail")
	{
		LocatorReloadEnterDisable("LaVega_port", "reload1_back", false);
	}
	sld = characterFromId("Mishelle");
	sld.dialog.currentnode = "First time";
	LAi_SetStayType(sld);
	ChangeCharacterAddressGroup(sld, "FortFrance_Dungeon", "quest", "quest1");

	// продублируем Мирабель
	sld = GetCharacter(NPC_GenerateCharacter("Mirabella", "Mirabelle", "woman", "towngirl", 1, PIRATE, -1, false, "quest"));
	SetFantomParamFromRank(sld, 1, true);
	sld.name = "Мирабель";
	sld.lastname = "";
	sld.Dialog.Filename = "Quest\Roger.c";
	sld.dialog.currentnode = "mirabelle_29";
	LAi_SetOwnerType(sld);
	LAi_SetImmortal(sld, true);
	LAi_ActorDialog(sld, pchar, "", -1, 0);	
	ChangeCharacterAddressGroup(sld, "IslaMona_TwoFloorRoom", "goto", "goto2");

                   // Замена тела
                  pchar.questTemp.GothicAztec = "AztecShaman";
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	ref sld = characterFromId("Marigo_Hostess");
	sld.dialog.currentnode = "Portugal_3";
	//pchar.questTemp.HWIC.Detector = "holl_win"; // знаем про Мерримана
	//pchar.questTemp.HWIC.Detector = "eng_win";
	//pchar.questTemp.HWIC.Detector = "self_win";
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Villemstad_town", "reload1_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("SentJons_town", "HouseF3", false);
                   LocatorReloadEnterDisable("SentJons_town", "SentJons_HouseF3_Room", false);
                   LocatorReloadEnterDisable("SentJons_town", "SentJons_HouseF2_Room", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("Carataska_jungle_01", "goto", "goto8", "");

	setCharacterShipLocation(pchar, "shore10"));
	setWDMPointXZ("shore10");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 20;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_FRIGATE_QUEST, true, mc);
	mc.Ship.name = "Посейдон";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	AddItems(mc, "jewelry8", 3);
	AddItems(mc, "jewelry7", 3);
	AddItems(mc, "skullaztecs", 1);
	AddItems(mc, "sextant3", 1);
	AddItems(mc, "JacobVanBerg_Journal", 1);
	pchar.questTemp.HWIC.Holl.Width = "true";// нашли широту острова
	pchar.questTemp.HWIC.Holl.Longitude = "true";//нашли долготу острова
	sEquipItem = GetGeneratedItem("blade301");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F43", 1);
}

string descF44 = "Начать тест мини квестов одержимые";

void CalculateInfoDataF44()
{
	// -->
	totalInfo = descF44;
                   chrDisableReloadToLocation = false;   
                 // Одержимые
                  SetTimerFunction("Gothic_Obsession", 0, 0, 10);
                  LocatorReloadEnterDisable("SantLous_town", "reload10", false);//откроем резеденцию Ли
                  pchar.questTemp.GothicLee = "Start_Lee";

	pchar.alchemy.known = 1;
	AddQuestRecordInfo("Recipe", "cartridge");
	SetAlchemyRecipeKnown("cartridge");
	// дага
	AddItems(pchar, "knife_01", 1);
	sld = ItemsFromID("knife_01");
	sld.Weight = 1.5;
	sld.price = 0;
	//Jason: перескок на тестирование Саги - все атрибуты
	bDisableFastReload = false;//открыть переход
	DeleteAttribute(pchar, "GenQuest.CannotWait");//можно мотать время
	bQuestDisableMapEnter = false;//открыть карту
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Temple", "reload2", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	LocatorReloadEnterDisable("SantLous_town", "reload10", false);
	LocatorReloadEnterDisable("LeFransua_town", "reload3_back", false);
                   LocatorReloadEnterDisable("FortFrance_Graveyard", "reload2_back", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	// открываем все острова
	for (i=0; i<MAX_ISLANDS; i++)
	{				
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	DoQuestReloadToLocation("BasTer_town", "reload", "reload1", "");
	setCharacterShipLocation(pchar, "BasTer_town"));
	setWDMPointXZ("BasTer_town");
	// ранг+прокачка+экипировка+корабль
	ref mc = GetMainCharacter();
	string sEquipItem;
	SetCharacterPerk(mc, "HullDamageUp");
	SetCharacterPerk(mc, "SailsDamageUp");
	SetCharacterPerk(mc, "CrewDamageUp");
	SetCharacterPerk(mc, "CriticalShoot");
	SetCharacterPerk(mc, "BasicBattleState");
	SetCharacterPerk(mc, "AdvancedBattleState");
	SetCharacterPerk(mc, "ShipSpeedUp");
	SetCharacterPerk(mc, "ShipTurnRateUp");
	SetCharacterPerk(mc, "StormProfessional");
	SetCharacterPerk(mc, "Doctor1");
	SetCharacterPerk(mc, "BasicCommerce");
	SetCharacterPerk(mc, "MusketsShoot");
	SetCharacterPerk(mc, "LongRangeGrappling");
	SetCharacterPerk(mc, "BasicDefense");
	SetCharacterPerk(mc, "AdvancedDefense");
	SetCharacterPerk(mc, "ProfessionalDefense");
	SetCharacterPerk(mc, "CriticalHit");
	SetCharacterPerk(mc, "Tireless");
	SetCharacterPerk(mc, "Sliding");
	SetCharacterPerk(mc, "Gunman");
	mc.rank = 21;
	LAi_SetHP(mc, 230.0, 230.0);
	SetSelfSkill(mc, 60, 60, 70, 60, 80);
	SetShipSkill(mc, 70, 70, 60, 60, 80, 70, 60, 80, 60);
	mc.Ship.Type = GenerateShipExt(SHIP_VALCIRIA_QUEST, true, mc);
	mc.Ship.name = "Черная Горгулья";
	SetBaseShipData(mc);
	mc.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	SetCrewQuantityFull(mc);
	mc.Ship.Crew.Morale = 80;
	mc.Ship.Crew.Exp.Sailors = 60;
	mc.Ship.Crew.Exp.Cannoners = 60;
	mc.Ship.Crew.Exp.Soldiers = 60;

	SetCharacterGoods(mc, GOOD_BALLS, 500);
	SetCharacterGoods(mc, GOOD_GRAPES, 500);
	SetCharacterGoods(mc, GOOD_KNIPPELS, 500);
	SetCharacterGoods(mc, GOOD_BOMBS, 700);
	SetCharacterGoods(mc, GOOD_FOOD, 1000);
	SetCharacterGoods(mc, GOOD_POWDER, 1000);
	SetCharacterGoods(mc, GOOD_WEAPON, 350);
	SetCharacterGoods(mc, GOOD_MEDICAMENT, 350);

	sEquipItem = GetCharacterEquipByGroup(mc, BLADE_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, GUN_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, SPYGLASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);
	sEquipItem = GetCharacterEquipByGroup(mc, CIRASS_ITEM_TYPE);
	RemoveItems(mc, sEquipItem, 1);

	AddMoneyToCharacter(mc, 500000);
	AddItems(mc, "spyglass3", 1);
	AddItems(mc, "pistol5", 1);
	AddItems(mc, "gold_dublon", 100);
	sEquipItem = GetGeneratedItem("blade_15");
	AddItems(mc, sEquipItem, 1);
	AddItems(mc, "cirass2", 1);
	EquipCharacterbyItem(mc, "spyglass3");
	EquipCharacterbyItem(mc, "pistol5");
 	EquipCharacterbyItem(mc, sEquipItem);
 	EquipCharacterbyItem(mc, "cirass2");
	AddItems(mc, "cartridge", 50);
	AddItems(mc, "bullet", 50);
	AddItems(mc, "gunpowder", 50);
	AddItems(mc, "grapeshot", 20);
	AddItems(mc, "potion2", 10);
	LAi_SetCharacterUseBullet(mc, "cartridge");
	
	totalInfo = totalInfo + NewStr() + NewStr() + "Команда отработала успешно!";
	
	SetFormatedText("INFO_TEXT", totalInfo);
	
	ProcessCancelExit();
	
	// Статистика по читам
	Statistic_AddValue(PChar, "Cheats.F44", 1);
}


void ShipRepair(ref chr)
{
	int hp = MakeInt(GetHullPercent(chr));
	int sp = MakeInt(GetSailPercent(chr));	
	trace("hp " + hp + " sp " + sp);
	
	// процент ремонта в день (при ремонте на глобальной карте)
	float sail_RPD = GetSailRPD(chr);
	float hull_RPD = GetHullRPD(chr);	
	trace("hull_RPD " + hull_RPD + " sail_RPD " + sail_RPD);
	
	float timeHull, timeSail, timeMast;
	
	timeHull  = 0.0;
	timeSail  = 0.0;
	timeMast  = 0.0;
	
	float SailDamagePercent = 100.0 - GetSailPercent(chr);
	float HullDamagePercent = 100.0 - GetHullPercent(chr);
	
	if(HullDamagePercent > 0.0)
	{
		timeHull = HullDamagePercent * (8-GetCharacterShipClass(chr));
	}
	if(SailDamagePercent > 0.0)
	{
		timeSail  = SailDamagePercent * (8-GetCharacterShipClass(chr));
	}	
	
	// кол-во материала на один процент ремонта
	float sail_SPP = GetSailSPP(chr);
	float hull_PPP = GetHullPPP(chr);
	trace("hull_PPP " + hull_PPP + " sail_SPP " + sail_SPP);
	
	float matQ;	
	int shMastFall = GetShipFallMastsQuantity(chr);
	
	trace("timeHull " + timeHull + " timeSail " + timeSail + " time (hours) : " + makeint( (timeHull/4.0 + timeSail/6.0)) );
	
	
	if(shMastFall > 0)
	{
		matQ = 15.0*GetHullPPP(chr);		
	}

}

float GetMaxSpeedZ(float fWindAgainstSpeed, float fWindDotShip)
{
    float fMaxSpeedZ 	= 10.0;
	float BtWindR 		= 1.0 - fWindAgainstSpeed;
	float fkoeff 		= fWindAgainstSpeed; 
	if(fkoeff < 1.0) fkoeff = 1.0;
	
	if(fWindDotShip < BtWindR) // по ветру
	{
		fMaxSpeedZ = fMaxSpeedZ * (1.0 + 0.974 * (fWindDotShip - BtWindR) / (1.0 + BtWindR));
	}
	else // против ветра
	{
		fMaxSpeedZ = fkoeff*fMaxSpeedZ * (1.0  - (fWindDotShip - BtWindR)/ 2.0);
	}	
	return fMaxSpeedZ;
}


void ReloadByStr()
{
	// разбор строки
	string  loc = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 0));
	string  grp = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 1));
	string  ltr = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 2));

    int i = FindLocation(loc);
    if (i != -1)
    {
        if(CheckAttribute(&locations[i],"fastreload"))
        {
			if (GetCityFrom_Sea(locations[i].fastreload) != "")
		    {
		        setCharacterShipLocation(pchar, GetCityFrom_Sea(locations[i].fastreload));
		        setWDMPointXZ(GetCityFrom_Sea(locations[i].fastreload));
		    }
	    }
	    else
	    {
	        if (locations[i].type == "seashore" || locations[i].type == "mayak")
	        {
	            setCharacterShipLocation(pchar, loc));
		        setWDMPointXZ(loc);
	        }
	    }
	    DoQuestReloadToLocation(loc, grp, ltr, "");
	    Log_Info(loc);
	    
		// Статистика по читам
		Statistic_AddValue(PChar, "Cheats.ReloadByStr", 1);
    }
    else
    {
        Log_Info("Нет локации");
    }
}

void XI_SetScroller(float pos)
{
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"QUESTSCROLL",pos);
}

void SetScrollerPos()
{
	string nodName = GetEventData();
	float pos = GetEventData();
	XI_SetScroller(pos);
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
    SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",2, newPos);
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	string controlNode = "";
	if( GetSelectable("INFO_TEXT") ) controlNode = "INFO_TEXT";
	
	if(controlNode!="")
	{
		if(changeNum>0) {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		} else {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}


void GetRealCoordsObjects()
{
	trace("---------");
	trace("Barbados (island)					: " + Map_GetRealCoordX(946.0062) + " " + Map_GetRealCoordZ(-486.9014));
	trace("Бриджтаун 							: " + Map_GetRealCoordX(903.6217) + " " + Map_GetRealCoordZ(-522.2799));
	trace("Mayak2 (маяк Барбадоса)				: " + Map_GetRealCoordX(918.619) + " " + Map_GetRealCoordZ(-506.827));
	trace("Shore4 (мыс Гаррисон)				: " + Map_GetRealCoordX(919.808) + " " + Map_GetRealCoordZ(-448.061));
	trace("Shore5 (мыс Раггед Пойнт)			: " + Map_GetRealCoordX(983.787) + " " + Map_GetRealCoordZ(-518.14));	
	trace("---------");
	trace("Antigua (island)						: " + Map_GetRealCoordX(903.9222) + " " + Map_GetRealCoordZ(109.0605));
	trace("Сент-Джонс 							: " + Map_GetRealCoordX(852.4083) + " " + Map_GetRealCoordZ(128.9092));
	trace("Shore1 (мыс Бун)						: " + Map_GetRealCoordX(880.892) + " " + Map_GetRealCoordZ(148.897));
	trace("Shore2 (залив Уиллогби)				: " + Map_GetRealCoordX(931.028) + " " + Map_GetRealCoordZ(74.5353));
	trace("Shore91 (бухта Норт)				: " + Map_GetRealCoordX(932.911) + " " + Map_GetRealCoordZ(139.498));
	trace("Shore92 (залив Кайрал-Бей)				: " + Map_GetRealCoordX(899.583) + " " + Map_GetRealCoordZ(63.5302));
	trace("Shore93 (залив Вэлли-Черч)				: " + Map_GetRealCoordX(853.093) + " " + Map_GetRealCoordZ(98.8799));
	trace("---------");
	trace("Curacao (island) 					: " + Map_GetRealCoordX(383.4142) + " " + Map_GetRealCoordZ(-691.11));
	trace("Виллемстадт 							: " + Map_GetRealCoordX(396.1) + " " + Map_GetRealCoordZ(-722.8));	
	trace("Shore22 (берег Ван Хато)			: " + Map_GetRealCoordX(354.604) + " " + Map_GetRealCoordZ(-678.54));
	trace("Shore23 (мыс Нордпунт)			: " + Map_GetRealCoordX(260.755) + " " + Map_GetRealCoordZ(-618.715));
	trace("Shore24 (лагуна Бланка)	: " + Map_GetRealCoordX(455.427) + " " + Map_GetRealCoordZ(-740.655));
	trace("---------");
	trace("SentMartin (island)					: " + Map_GetRealCoordX(921.559) + " " + Map_GetRealCoordZ(523.596));
	trace("Мариго 								: " + Map_GetRealCoordX(900.0994) + " " + Map_GetRealCoordZ(501.6531));	
	trace("Shore40 (пляж Гранд Кейс)				: " + Map_GetRealCoordX(924.442) + " " + Map_GetRealCoordZ(554.385));	
	trace("Shore41 (залив Симпсон)		: " + Map_GetRealCoordX(898.877) + " " + Map_GetRealCoordZ(522.703));
	trace("Shore103 (залив Грейт)		: " + Map_GetRealCoordX(919.765) + " " + Map_GetRealCoordZ(472.331));
	trace("Shore104 (залив Бэк)		: " + Map_GetRealCoordX(943.784) + " " + Map_GetRealCoordZ(492.408));
	trace("Shore105 (залив Гвана)		: " + Map_GetRealCoordX(947.41) + " " + Map_GetRealCoordZ(526.58));	
	trace("---------");
	trace("Guadeloupe (island)					: " + Map_GetRealCoordX(537.114) + " " + Map_GetRealCoordZ(-25.3853));	
	trace("Бас-Тер 								: " + Map_GetRealCoordX(462.2107) + " " + Map_GetRealCoordZ(-73.0837));		
	trace("Mayak4 (маяк Гваделупы)				: " + Map_GetRealCoordX(465.076) + " " + Map_GetRealCoordZ(-38.9423));		
	trace("Shore28 (бухта Морн л'О)				: " + Map_GetRealCoordX(536.636) + " " + Map_GetRealCoordZ(26.1279));		
	trace("Shore29 (пляж Капстер)				: " + Map_GetRealCoordX(507.669) + " " + Map_GetRealCoordZ(-75.4176));		
	trace("Shore30 (бухта Гран Бур)				: " + Map_GetRealCoordX(549.807) + " " + Map_GetRealCoordZ(-69.7107));		
	trace("Shore31 (мыс Недоступный)			: " + Map_GetRealCoordX(589.889) + " " + Map_GetRealCoordZ(-65.0601));
	trace("Сент-Луи 							: " + Map_GetRealCoordX(596.108) + " " + Map_GetRealCoordZ(-64.8827));
	trace("Shore83 (бухта Новая) 				: " + Map_GetRealCoordX(527.794) + " " + Map_GetRealCoordZ(-17.8862));
	trace("Shore80 (бухта Калуакаэра) 				: " + Map_GetRealCoordX(584.749) + " " + Map_GetRealCoordZ(27.088));		
	trace("---------");
	trace("Martinique (island) 					: " + Map_GetRealCoordX(538.524) + " " + Map_GetRealCoordZ(-385.567));		
	trace("Форт де Франс 						    : " + Map_GetRealCoordX(513.51) + " " + Map_GetRealCoordZ(-397.645));		
	trace("Ле-Франсуа 							: " + Map_GetRealCoordX(559.008) + " " + Map_GetRealCoordZ(-368.16));		
	trace("Shore38 (пляж Ламантен)				: " + Map_GetRealCoordX(481.181) + " " + Map_GetRealCoordZ(-340.832));		
	trace("Shore39 (бухта Ле Марен)				: " + Map_GetRealCoordX(557.181) + " " + Map_GetRealCoordZ(-422.987));
	trace("Shore89 (залив Сент-Мари)				: " + Map_GetRealCoordX(544.468) + " " + Map_GetRealCoordZ(-338.818));			
	trace("---------");
	trace("Bermudes (island)					: " + Map_GetRealCoordX(920.738) + " " + Map_GetRealCoordZ(920.767));		
	trace("Шарптаун     					    : " + Map_GetRealCoordX(931.059) + " " + Map_GetRealCoordZ(928.281));		
	trace("Shore3 (залив Руны)					: " + Map_GetRealCoordX(915.745) + " " + Map_GetRealCoordZ(966.469));		
	trace("Shore_ship1 (бухта Разбитого Корыта) : " + Map_GetRealCoordX(968.947) + " " + Map_GetRealCoordZ(923.636));		
	trace("---------");
	trace("Maracaibo (areal) 					: " + Map_GetRealCoordX(178.51) + " " + Map_GetRealCoordZ(-870.37));		
	trace("Маракайбо 							: " + Map_GetRealCoordX(134.82) + " " + Map_GetRealCoordZ(-939.65));		
	trace("Shore37 (бухта Гуахира)				: " + Map_GetRealCoordX(140.753) + " " + Map_GetRealCoordZ(-828.99));
	trace("Shore106 (залив Каухарито)				: " + Map_GetRealCoordX(209.124) + " " + Map_GetRealCoordZ(-957.927));
	trace("Shore107 (бухта Эль Мембрильо)				: " + Map_GetRealCoordX(219.093) + " " + Map_GetRealCoordZ(-867.788));		
	trace("Shore_ship3 (мыс Несбывшихся Надежд)	: " + Map_GetRealCoordX(198.162) + " " + Map_GetRealCoordZ(-994.035));		
	trace("---------");
	trace("Beliz (areal) 						: " + Map_GetRealCoordX(-896.084) + " " + Map_GetRealCoordZ(230.227));		
	trace("Shore_ship2 (залив Гибели)			: " + Map_GetRealCoordX(-1022.94) + " " + Map_GetRealCoordZ(629.355));		
	trace("Shore6 (мыс Каточе)					: " + Map_GetRealCoordX(-909.655) + " " + Map_GetRealCoordZ(629.079));		
	trace("Shore7 (залив Косумель)				: " + Map_GetRealCoordX(-915.581) + " " + Map_GetRealCoordZ(409.002));		
	trace("Shore8 (бухта Четумаль)				: " + Map_GetRealCoordX(-963.489) + " " + Map_GetRealCoordZ(281.628));
	trace("Shore118 (лагуна Бисмуна-Рейя)				: " + Map_GetRealCoordX(-885.887) + " " + Map_GetRealCoordZ(-543.16));		
	trace("Белиз 								: " + Map_GetRealCoordX(-978.396) + " " + Map_GetRealCoordZ(158.751));		
	trace("Shore9 (бухта Аматике)				: " + Map_GetRealCoordX(-1017.2) + " " + Map_GetRealCoordZ(-33.7293));		
	trace("Shore10 (лагуна Каратаска)			: " + Map_GetRealCoordX(-818.198) + " " + Map_GetRealCoordZ(-177.208));
	trace("Shore117 (лагуна Ауловер)			: " + Map_GetRealCoordX(-967.48) + " " + Map_GetRealCoordZ(-96.936));		
	trace("---------");
	trace("Jamaica (island)						: " + Map_GetRealCoordX(-298.0) + " " + Map_GetRealCoordZ(-128.0));		
	trace("Порт-Ройал 							: " + Map_GetRealCoordX(-250.157) + " " + Map_GetRealCoordZ(-150.839));		
	trace("Shore35 (бухта Блэк-Ривер)					: " + Map_GetRealCoordX(-446.951) + " " + Map_GetRealCoordZ(-107.118));			
	trace("Shore36 (бухта Портленд)				: " + Map_GetRealCoordX(-281.543) + " " + Map_GetRealCoordZ(-164.245));			
	trace("Mayak3 (маяк Порт Рояля)				: " + Map_GetRealCoordX(-224.127) + " " + Map_GetRealCoordZ(-163.435));
	trace("Shore84 (мыс Саут-Негрил)				: " + Map_GetRealCoordX(-462.332) + " " + Map_GetRealCoordZ(-90.2574));
	trace("Shore85 (залив Монтего-Бей)				: " + Map_GetRealCoordX(-432.584) + " " + Map_GetRealCoordZ(-61.3437));
	trace("Shore86 (бухта Фалмут)				: " + Map_GetRealCoordX(-401.783) + " " + Map_GetRealCoordZ(-57.3384));
	trace("Shore87 (бухта Аннотто-Бей)				: " + Map_GetRealCoordX(-211.188) + " " + Map_GetRealCoordZ(-93.6436));
	trace("Shore88 (залив Очо-Риос)				: " + Map_GetRealCoordX(-270.137) + " " + Map_GetRealCoordZ(-69.6396));
	trace("Shore90 (мыс Морант)				: " + Map_GetRealCoordX(-152.439) + " " + Map_GetRealCoordZ(-160.916));
	trace("Порт-Антонио 								: " + Map_GetRealCoordX(-158.585) + " " + Map_GetRealCoordZ(-118.477));			
	trace("---------");
	trace("PuertoRico (island) 					: " + Map_GetRealCoordX(506.489) + " " + Map_GetRealCoordZ(460.815));			
	trace("Сан-Хуан 							: " + Map_GetRealCoordX(528.645) + " " + Map_GetRealCoordZ(484.18));				
	trace("Shore44 (бухта Маягуэс)			: " + Map_GetRealCoordX(392.82) + " " + Map_GetRealCoordZ(501.808));				
	trace("Shore45 (пляж Фахардо)				: " + Map_GetRealCoordX(602.049) + " " + Map_GetRealCoordZ(458.322));
	trace("Shore81 (бухта Понсе)				: " + Map_GetRealCoordX(449.547) + " " + Map_GetRealCoordZ(424.37));
	trace("Shore82 (лагуна Аресибо)				: " + Map_GetRealCoordX(454.396) + " " + Map_GetRealCoordZ(509.846));
	trace("Shore94 (бухта Агуадилья)				: " + Map_GetRealCoordX(406.107) + " " + Map_GetRealCoordZ(517.714));
	trace("Shore95 (бухта Гуаяма)				: " + Map_GetRealCoordX(521.497) + " " + Map_GetRealCoordZ(413.641));
	trace("Вилья-Аллегрия 							: " + Map_GetRealCoordX(392.82) + " " + Map_GetRealCoordZ(501.808));				
	trace("---------");
	trace("Cuba1 (areal) 						: " + Map_GetRealCoordX(-358.027) + " " + Map_GetRealCoordZ(819.223));				
	trace("Сантьяго 							: " + Map_GetRealCoordX(-339.796) + " " + Map_GetRealCoordZ(771.839));					
	trace("Пуэрто-Принсипе 						: " + Map_GetRealCoordX(-282.032) + " " + Map_GetRealCoordZ(839.056));					
	trace("Shore11 (мыс Камагуэй)				: " + Map_GetRealCoordX(-386.907) + " " + Map_GetRealCoordZ(883.044));				
	trace("Shore12 (залив Анна Мария)			: " + Map_GetRealCoordX(-468.486) + " " + Map_GetRealCoordZ(838.497));				
	trace("Mayak9 (маяк Сантьяго)				: " + Map_GetRealCoordX(-333.295) + " " + Map_GetRealCoordZ(723.486));
	trace("Shore125 (мыс Кемадо)				: " + Map_GetRealCoordX(-242.198) + " " + Map_GetRealCoordZ(784.498));				
	trace("---------");
	trace("Cuba2 (areal) 						: " + Map_GetRealCoordX(-640.61) + " " + Map_GetRealCoordZ(870.058));					
	trace("Гавана 								: " + Map_GetRealCoordX(-663.685) + " " + Map_GetRealCoordZ(913.862));					
	trace("Shore13 (залив Батабано)				: " + Map_GetRealCoordX(-613.56) + " " + Map_GetRealCoordZ(886.009));				
	trace("Shore14 (бухта Хувентуд)				: " + Map_GetRealCoordX(-653.269) + " " + Map_GetRealCoordZ(871.013));				
	trace("Shore15 (мыс Сан Антонио)			: " + Map_GetRealCoordX(-715.129) + " " + Map_GetRealCoordZ(797.212));				
	trace("Mayak10 (маяк Гаваны)				: " + Map_GetRealCoordX(-647.18) + " " + Map_GetRealCoordZ(925.046));
	trace("Shore123 (мыс Пунта-Горда)			: " + Map_GetRealCoordX(-616.065) + " " + Map_GetRealCoordZ(854.219));
	trace("Shore124 (бухта Плайя-Хирон)			: " + Map_GetRealCoordX(-540.192) + " " + Map_GetRealCoordZ(843.269));				
	trace("---------");
	trace("Tortuga (island) 					: " + Map_GetRealCoordX(102.328) + " " + Map_GetRealCoordZ(852.912));				
	trace("Тортуга 								: " + Map_GetRealCoordX(116.875) + " " + Map_GetRealCoordZ(817.942));				
	trace("Shore58 (пляж Глаз Рыбы)				: " + Map_GetRealCoordX(131.064) + " " + Map_GetRealCoordZ(849.44));				
	trace("Mayak6 (маяк Тортуги)				: " + Map_GetRealCoordX(103.23) + " " + Map_GetRealCoordZ(812.356));
	trace("Shore126 (остров Флинт)				: " + Map_GetRealCoordX(72.9146) + " " + Map_GetRealCoordZ(889.649));					
	trace("---------");
	trace("Trinidad (island)					: " + Map_GetRealCoordX(889.76) + " " + Map_GetRealCoordZ(-774.746));				
	trace("Сан-Хосе 						: " + Map_GetRealCoordX(848.282) + " " + Map_GetRealCoordZ(-822.588));				
	trace("Shore59 (бухта Скарборо)				: " + Map_GetRealCoordX(937.322) + " " + Map_GetRealCoordZ(-737.478));				
	trace("Shore60 (мыс Галера)					: " + Map_GetRealCoordX(906.25) + " " + Map_GetRealCoordZ(-757.928));				
	trace("Mayak1 (маяк Тринидада и Тобаго)		: " + Map_GetRealCoordX(821.24) + " " + Map_GetRealCoordZ(-847.69));
	trace("Shore127 (залив Маяро)					: " + Map_GetRealCoordX(890.341) + " " + Map_GetRealCoordZ(-848.948));
	trace("Shore128 (залив Кокос)					: " + Map_GetRealCoordX(941.306) + " " + Map_GetRealCoordZ(-822.883));
	trace("Shore129 (бухта Бланшиссез)					: " + Map_GetRealCoordX(832.338) + " " + Map_GetRealCoordZ(-764.32));
	trace("Shore130 (пляж Шарлотвилл)					: " + Map_GetRealCoordX(931.557) + " " + Map_GetRealCoordZ(-704.765));				
	trace("---------");
	trace("Nevis (island)						: " + Map_GetRealCoordX(681.595) + " " + Map_GetRealCoordZ(256.013));				
	trace("Капстервиль 							: " + Map_GetRealCoordX(658.918) + " " + Map_GetRealCoordZ(241.972));				
	trace("Shore42 (бухта Ньюкасл)				: " + Map_GetRealCoordX(690.047) + " " + Map_GetRealCoordZ(291.621));					
	trace("Shore43 (пляж Бат)					: " + Map_GetRealCoordX(684.026) + " " + Map_GetRealCoordZ(212.793));					
	trace("Mayak5 (маяк Сент-Кристофера)					: " + Map_GetRealCoordX(663.418) + " " + Map_GetRealCoordZ(228.281));					
	trace("---------");
	trace("Hispaniola1 (areal) 					: " + Map_GetRealCoordX(198.977) + " " + Map_GetRealCoordZ(588.696));					
	trace("Санто-Доминго 						: " + Map_GetRealCoordX(198.683) + " " + Map_GetRealCoordZ(547.97));					
	trace("Ла-Вега 								: " + Map_GetRealCoordX(166.708) + " " + Map_GetRealCoordZ(662.952));					
	trace("Shore32 (мыс Исабела)				: " + Map_GetRealCoordX(130.591) + " " + Map_GetRealCoordZ(682.362));						
	trace("Shore33 (бухта Самана)				: " + Map_GetRealCoordX(229.081) + " " + Map_GetRealCoordZ(593.727));
						
	trace("Mayak8 (маяк Санто-Доминго)			: " + Map_GetRealCoordX(168.314) + " " + Map_GetRealCoordZ(520.218));
	trace("Shore100 (мыс Энганьо)				: " + Map_GetRealCoordX(278.905) + " " + Map_GetRealCoordZ(588.696));
	trace("Shore101 (бухта Бараона)				: " + Map_GetRealCoordX(117.579) + " " + Map_GetRealCoordZ(535.305));
	trace("Shore102 (бухта Баия-Эскосеса)				: " + Map_GetRealCoordX(223.595) + " " + Map_GetRealCoordZ(616.891));						
	trace("---------");
	trace("Hispaniola2 (areal) 					: " + Map_GetRealCoordX(-47.1762) + " " + Map_GetRealCoordZ(625.596));					
	trace("Порт-о-Пренс 						: " + Map_GetRealCoordX(22.521) + " " + Map_GetRealCoordZ(592.233));					
	trace("Shore34 (бухта Гонаив)				: " + Map_GetRealCoordX(0.999614) + " " + Map_GetRealCoordZ(643.122));
	trace("Shore96 (мыс Дам-Мари)				: " + Map_GetRealCoordX(-154.483) + " " + Map_GetRealCoordZ(618.662));
	trace("Shore97 (мыс Абаку)				: " + Map_GetRealCoordX(-101.015) + " " + Map_GetRealCoordZ(561.493));
	trace("Shore98 (мыс Беата)				: " + Map_GetRealCoordX(72.8103) + " " + Map_GetRealCoordZ(490.696));
	trace("Shore99 (мыс Звезды)				: " + Map_GetRealCoordX(-48.2268) + " " + Map_GetRealCoordZ(703.264));
	trace("Ле-Ке 						: " + Map_GetRealCoordX(-71.3135) + " " + Map_GetRealCoordZ(570.688));							
	trace("Mayak7 (маяк Порт-о-Пренса)			: " + Map_GetRealCoordX(-14.9756) + " " + Map_GetRealCoordZ(606.258));						
	trace("---------");
	trace("Dominica 							: " + Map_GetRealCoordX(783.057) + " " + Map_GetRealCoordZ(-256.833));					
	trace("Shore27 (мыс Скотс Хед)				: " + Map_GetRealCoordX(779.89) + " " + Map_GetRealCoordZ(-295.002));						trace("Шарлотт-Таун 						: " + Map_GetRealCoordX(806.778) + " " + Map_GetRealCoordZ(-247.06));			
	trace("Shore26 (пляж Касл Брус)				: " + Map_GetRealCoordX(810.894) + " " + Map_GetRealCoordZ(-247.646));								
	trace("---------");
	trace("Теркс 								: " + Map_GetRealCoordX(443.257) + " " + Map_GetRealCoordZ(939.102));						
	trace("Shore57 (залив Южный)				: " + Map_GetRealCoordX(434.944) + " " + Map_GetRealCoordZ(923.524));								
	trace("Shore56 (залив Северный)				: " + Map_GetRealCoordX(444.298) + " " + Map_GetRealCoordZ(954.975));								
	trace("---------");
	trace("Кайман 								: " + Map_GetRealCoordX(-489.6) + " " + Map_GetRealCoordZ(362.455));						
	trace("Shore17 (залив Эсмеральды)			: " + Map_GetRealCoordX(-505.038) + " " + Map_GetRealCoordZ(348.115));									
	trace("Shore16 (Пустынный пляж)				: " + Map_GetRealCoordX(-449.837) + " " + Map_GetRealCoordZ(366.308));
	trace("---------");
	trace("Panama (areal) 						: " + Map_GetRealCoordX(-395.198) + " " + Map_GetRealCoordZ(-972.801));							
	trace("Панама 								: " + Map_GetRealCoordX(-389.965) + " " + Map_GetRealCoordZ(-949.118));							
	trace("Shore63 (залив Сан Мигель) 			: " + Map_GetRealCoordX(-328.166) + " " + Map_GetRealCoordZ(-1023.72));
	trace("---------");
	trace("PortoBello (areal) 					: " + Map_GetRealCoordX(-435.73) + " " + Map_GetRealCoordZ(-895.763));							
	trace("Порто-Белло 							: " + Map_GetRealCoordX(-427.183) + " " + Map_GetRealCoordZ(-907.277));
	trace("Shore46 (лагуна Чирики)				: " + Map_GetRealCoordX(-627.474) + " " + Map_GetRealCoordZ(-940.853));
	trace("Shore47 (залив Москитос)				: " + Map_GetRealCoordX(-486.49) + " " + Map_GetRealCoordZ(-976.966));
	trace("Shore48 (Дарьенский залив)			: " + Map_GetRealCoordX(-279.316) + " " + Map_GetRealCoordZ(-1005.49));
	trace("Shore114 (бухта Чирики-Гранте)			: " + Map_GetRealCoordX(-570.056) + " " + Map_GetRealCoordZ(-957.361));
	trace("Shore115 (бухта Бокас-дель-Торо)			: " + Map_GetRealCoordX(-664.356) + " " + Map_GetRealCoordZ(-908.161));
	trace("---------");
	trace("Cartahena (areal) 					: " + Map_GetRealCoordX(-51.2104) + " " + Map_GetRealCoordZ(-851.77));								
	trace("Картахена 							: " + Map_GetRealCoordX(-26.7669) + " " + Map_GetRealCoordZ(-872.535));								
	trace("Shore25 (бухта Ковеньяс)				: " + Map_GetRealCoordX(-115.589) + " " + Map_GetRealCoordZ(-937.387));
	trace("Mayak11 (маяк Картахены)				: " + Map_GetRealCoordX(-65.6347) + " " + Map_GetRealCoordZ(-842.072));
	trace("Shore108 (бухта Манауре)				: " + Map_GetRealCoordX(63.1393) + " " + Map_GetRealCoordZ(-764.193));
	trace("Shore109 (бухта Санта-Марта)				: " + Map_GetRealCoordX(-7.8008) + " " + Map_GetRealCoordZ(-804.915));
	trace("---------");
	trace("Caracas (areal) 						: " + Map_GetRealCoordX(435.126) + " " + Map_GetRealCoordZ(-936.197));								
	trace("Каракас 								: " + Map_GetRealCoordX(440.684) + " " + Map_GetRealCoordZ(-960.339));
	trace("Shore21 (мыс Аруба)					: " + Map_GetRealCoordX(410.688) + " " + Map_GetRealCoordZ(-913.531));
	trace("---------");
	trace("Cumana (areal) 						: " + Map_GetRealCoordX(767.999) + " " + Map_GetRealCoordZ(-936.266));								
	trace("Кумана 								: " + Map_GetRealCoordX(691.343) + " " + Map_GetRealCoordZ(-896.619));								
	trace("Shore20 (пляж Лос Текес)				: " + Map_GetRealCoordX(574.327) + " " + Map_GetRealCoordZ(-929.042));
	trace("Shore19 (бухта Карупано)				: " + Map_GetRealCoordX(768.622) + " " + Map_GetRealCoordZ(-914.469));
	trace("Shore18 (берег Бока де ла Сьерпе)	: " + Map_GetRealCoordX(924.423) + " " + Map_GetRealCoordZ(-969.921));
	trace("---------");
	trace("SantaCatalina (areal) 				: " + Map_GetRealCoordX(-742.269) + " " + Map_GetRealCoordZ(-563.205));									
	trace("Блуфилдс 						: " + Map_GetRealCoordX(-769.375) + " " + Map_GetRealCoordZ(-537.051));
	trace("Shore53 (Берег Москитов)				: " + Map_GetRealCoordX(-792.718) + " " + Map_GetRealCoordZ(-331.728));
	trace("Shore54 (мыс Перлас)					: " + Map_GetRealCoordX(-760.343) + " " + Map_GetRealCoordZ(-484.106));
	trace("Shore55 (залив Сан Хуан дель Норте)	: " + Map_GetRealCoordX(-736.763) + " " + Map_GetRealCoordZ(-756.295));
	trace("Shore116 (бухта Грей)	: " + Map_GetRealCoordX(-737.646) + " " + Map_GetRealCoordZ(-750.14));
	trace("---------");
	trace("ГПК							: " + Map_GetRealCoordX(-938.667) + " " + Map_GetRealCoordZ(938.654));
	trace("ГПК2							: " + Map_GetRealCoordX(685.007) + " " + Map_GetRealCoordZ(915.654));										
	trace("---------");
	trace("Tenoc (areal)							: " + Map_GetRealCoordX(-966.062) + " " + Map_GetRealCoordZ(-294.232));										
	trace("Теночтитлан 							: " + Map_GetRealCoordX(-969.194) + " " + Map_GetRealCoordZ(-305.237));										
	trace("Shore61 (Тепейакак) 					: " + Map_GetRealCoordX(-955.553) + " " + Map_GetRealCoordZ(-281.197));
	trace("Shore62 (Истапалапу)					: " + Map_GetRealCoordX(-935.811) + " " + Map_GetRealCoordZ(-316.162));
	trace("---------");
	trace("Ксочитэм								: " + Map_GetRealCoordX(-597.3333) + " " + Map_GetRealCoordZ(85.3333));										
	trace("---------");	
	trace("RockIsland							: " + Map_GetRealCoordX(-511.9965) + " " + Map_GetRealCoordZ(554.6586));										
	trace("---------");	
	trace("KhaelRoa								: " + Map_GetRealCoordX(810.6678) + " " + Map_GetRealCoordZ(298.6671));										
	trace("---------");	
	trace("Providence							: " + Map_GetRealCoordX(-512.0) + " " + Map_GetRealCoordZ(-426.6667));										
	trace("---------");	
	trace("SantaQuiteria						: " + Map_GetRealCoordX(-213.3336) + " " + Map_GetRealCoordZ(-512.0));										
	trace("---------");	
	trace("IslaDeVieques						: " + Map_GetRealCoordX(85.3334) + " " + Map_GetRealCoordZ(-70.6667));										
	trace("---------");	
	trace("IslaMona								: " + Map_GetRealCoordX(0) + " " + Map_GetRealCoordZ(170.6669));										
	trace("---------");	
	trace("IslaDeCoche							: " + Map_GetRealCoordX(640.0) + " " + Map_GetRealCoordZ(-640.0));										
	trace("---------");		
}