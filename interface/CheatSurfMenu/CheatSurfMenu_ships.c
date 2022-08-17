
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Генерация кораблей
	Основано на меню дебаггера от boal
	28.05.18
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Корабли' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sTextA = "получен и укомплектован морскими волками!";
string sTextB = "получена и укомплектована морскими волками!";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_ships";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(7); // Warship. Статистика - сколько читов юзали
	SetFormatedText("INFO_TEXT", totalInfo); //"Информация отладчика";
	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);
	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
	SetEventHandler("ScrollTopChange","ProcScrollChange",0);
	SetEventHandler("MouseRClickUP","HideInfo",0);
	SetEventHandler("ShowInfoWindow","ShowInfoWindow",0);
	PlaySound("Interface\s_korablami_001.wav");
}

void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_ANY_EXIT );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_ANY_EXIT );
}

void IDoExit(int exitCode)
{
	EndAboveForm(true);
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("evntDoPostExit","DoPostExit");
	DelEventHandler("ievnt_command","ProcCommand");
 	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("ScrollTopChange","ProcScrollChange");
	DelEventHandler("MouseRClickUP","HideInfo");
	DelEventHandler("ShowInfoWindow","ShowInfoWindow");
	if(bSeaActive) { RefreshBattleInterface(); }
	interfaceResultCommand = exitCode;
	EndCancelInterface(true);
	if (!CheckAttribute(pchar, "CSM.Welcome")) { pchar.CSM.Welcome = true; }
}

void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

void CommonActions()
{
	ClearAllLogStrings();
	SetNewPicture("CSMPICTURE", "Blank.tga");
	totalInfo += "\n\n";
	if (iSND != 0) StopSound(iSND, 0);
}

void CalculateInfoData()
{
	if (!CheckAttribute(pchar, "CSM.Welcome"))
	{
		PlaySound("_CheatSurfMenu_\Welcome_" + rand(3) + ".wav");
		PlaySound("interface\bort_jurnal_001.wav");
		totalInfo = csmMenuText(0);
	}
	else
	{
		// тут высчитываем нужную информацию и выводим в totalInfo - Инициализация -->
		totalInfo = csmMenuText(1) + "\n\n" +
					"********** ПОЛУЧИТЬ УНИКАЛЬНЫЙ КОРАБЛЬ **********" + NewStr() +
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() +
					"\n\n********** СГЕНЕРИРОВАТЬ КОРАБЛЬ **********" + NewStr() +
					"< 24 > " + descF24 + NewStr() + "< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() +
					"< 27 > " + descF27 + NewStr() + "< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() +
					"< 30 > " + descF30 + NewStr() + "< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() +
					"< 33 > " + descF33 + NewStr() + "< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() +
					"< 36 > " + descF36 + NewStr() + "< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() +
					"< 39 > " + descF39 + NewStr() + "< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() +
					"< 42 > " + descF42 + NewStr() + "< 43 > " + descF43 + NewStr() + "< 44 > " + descF44 + NewStr() +
					"< 45 > " + descF45 + NewStr() + "< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() +
					"< 48 > " + descF48 + NewStr() + "< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() +
					"< 51 > " + descF51 + NewStr() + "< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() +
					"\n\n********** ПРОЧЕЕ **********" + NewStr() +
					"< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + NewStr() + "< 56 > " + descF56 + NewStr() +
					"< 57 > " + descF57 + NewStr() + "< 58 > " + descF58 + NewStr() + "< 59 > " + descF59 + NewStr() +
					"< 60 > " + descF60 + NewStr() + "< 61 > " + descF61 + NewStr() + "< 62 > " + descF62 + NewStr() +
					"< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() + "< 65 > " + descF65 + NewStr() +
					"< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() + "< 68 > " + descF68 + NewStr() +
					"< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
		// перевод строки (по другому у меня не вышло) +LanguageConvertString(idLngFile,"new_string");
		// тут высчитываем нужную информацию и выводим в totalInfo <--
	}
}

void ProcCommand()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if (!CheckAttribute(pchar, "CSM.Welcome"))
	{
		DoQuestFunctionDelay("CheatSurfMenuWelcome", 0.1);
		return;
	}
	switch(nodName)
	{
		case "B_F1": if(comName=="activate" || comName=="click") {CalculateInfoDataF1();} break;
		case "B_F2": if(comName=="activate" || comName=="click") {CalculateInfoDataF2();} break;
		case "B_F3": if(comName=="activate" || comName=="click") {CalculateInfoDataF3();} break;
		case "B_F4": if(comName=="activate" || comName=="click") {CalculateInfoDataF4();} break;
		case "B_F5": if(comName=="activate" || comName=="click") {CalculateInfoDataF5();} break;
		case "B_F6": if(comName=="activate" || comName=="click") {CalculateInfoDataF6();} break;
		case "B_F7": if(comName=="activate" || comName=="click") {CalculateInfoDataF7();} break;
		case "B_F8": if(comName=="activate" || comName=="click") {CalculateInfoDataF8();} break;
		case "B_F9": if(comName=="activate" || comName=="click") {CalculateInfoDataF9();} break;
		case "B_F10": if(comName=="activate" || comName=="click") {CalculateInfoDataF10();} break;
		case "B_F11": if(comName=="activate" || comName=="click") {CalculateInfoDataF11();} break;
		case "B_F12": if(comName=="activate" || comName=="click") {CalculateInfoDataF12();} break;
		case "B_F13": if(comName=="activate" || comName=="click") {CalculateInfoDataF13();} break;
		case "B_F14": if(comName=="activate" || comName=="click") {CalculateInfoDataF14();} break;
		case "B_F15": if(comName=="activate" || comName=="click") {CalculateInfoDataF15();} break;
		case "B_F16": if(comName=="activate" || comName=="click") {CalculateInfoDataF16();} break;
		case "B_F17": if(comName=="activate" || comName=="click") {CalculateInfoDataF17();} break;
		case "B_F18": if(comName=="activate" || comName=="click") {CalculateInfoDataF18();} break;
		case "B_F19": if(comName=="activate" || comName=="click") {CalculateInfoDataF19();} break;
		case "B_F20": if(comName=="activate" || comName=="click") {CalculateInfoDataF20();} break;
		case "B_F21": if(comName=="activate" || comName=="click") {CalculateInfoDataF21();} break;
		case "B_F22": if(comName=="activate" || comName=="click") {CalculateInfoDataF22();} break;
		case "B_F23": if(comName=="activate" || comName=="click") {CalculateInfoDataF23();} break;
		case "B_F24": if(comName=="activate" || comName=="click") {CalculateInfoDataF24();} break;
		case "B_F25": if(comName=="activate" || comName=="click") {CalculateInfoDataF25();} break;
		case "B_F26": if(comName=="activate" || comName=="click") {CalculateInfoDataF26();} break;
		case "B_F27": if(comName=="activate" || comName=="click") {CalculateInfoDataF27();} break;
		case "B_F28": if(comName=="activate" || comName=="click") {CalculateInfoDataF28();} break;
		case "B_F29": if(comName=="activate" || comName=="click") {CalculateInfoDataF29();} break;
		case "B_F30": if(comName=="activate" || comName=="click") {CalculateInfoDataF30();} break;
		case "B_F31": if(comName=="activate" || comName=="click") {CalculateInfoDataF31();} break;
		case "B_F32": if(comName=="activate" || comName=="click") {CalculateInfoDataF32();} break;
		case "B_F33": if(comName=="activate" || comName=="click") {CalculateInfoDataF33();} break;
		case "B_F34": if(comName=="activate" || comName=="click") {CalculateInfoDataF34();} break;
		case "B_F35": if(comName=="activate" || comName=="click") {CalculateInfoDataF35();} break;
		case "B_F36": if(comName=="activate" || comName=="click") {CalculateInfoDataF36();} break;
		case "B_F37": if(comName=="activate" || comName=="click") {CalculateInfoDataF37();} break;
		case "B_F38": if(comName=="activate" || comName=="click") {CalculateInfoDataF38();} break;
		case "B_F39": if(comName=="activate" || comName=="click") {CalculateInfoDataF39();} break;
		case "B_F40": if(comName=="activate" || comName=="click") {CalculateInfoDataF40();} break;
		case "B_F41": if(comName=="activate" || comName=="click") {CalculateInfoDataF41();} break;
		case "B_F42": if(comName=="activate" || comName=="click") {CalculateInfoDataF42();} break;
		case "B_F43": if(comName=="activate" || comName=="click") {CalculateInfoDataF43();} break;
		case "B_F44": if(comName=="activate" || comName=="click") {CalculateInfoDataF44();} break;
		case "B_F45": if(comName=="activate" || comName=="click") {CalculateInfoDataF45();} break;
		case "B_F46": if(comName=="activate" || comName=="click") {CalculateInfoDataF46();} break;
		case "B_F47": if(comName=="activate" || comName=="click") {CalculateInfoDataF47();} break;
		case "B_F48": if(comName=="activate" || comName=="click") {CalculateInfoDataF48();} break;
		case "B_F49": if(comName=="activate" || comName=="click") {CalculateInfoDataF49();} break;
		case "B_F50": if(comName=="activate" || comName=="click") {CalculateInfoDataF50();} break;
		case "B_F51": if(comName=="activate" || comName=="click") {CalculateInfoDataF51();} break;
		case "B_F52": if(comName=="activate" || comName=="click") {CalculateInfoDataF52();} break;
		case "B_F53": if(comName=="activate" || comName=="click") {CalculateInfoDataF53();} break;
		case "B_F54": if(comName=="activate" || comName=="click") {CalculateInfoDataF54();} break;
		case "B_F55": if(comName=="activate" || comName=="click") {CalculateInfoDataF55();} break;
		case "B_F56": if(comName=="activate" || comName=="click") {CalculateInfoDataF56();} break;
		case "B_F57": if(comName=="activate" || comName=="click") {CalculateInfoDataF57();} break;
		case "B_F58": if(comName=="activate" || comName=="click") {CalculateInfoDataF58();} break;
		case "B_F59": if(comName=="activate" || comName=="click") {CalculateInfoDataF59();} break;
		case "B_F60": if(comName=="activate" || comName=="click") {CalculateInfoDataF60();} break;
		case "B_F61": if(comName=="activate" || comName=="click") {CalculateInfoDataF61();} break;
		case "B_F62": if(comName=="activate" || comName=="click") {CalculateInfoDataF62();} break;
		case "B_F63": if(comName=="activate" || comName=="click") {CalculateInfoDataF63();} break;
		case "B_F64": if(comName=="activate" || comName=="click") {CalculateInfoDataF64();} break;
		case "B_F65": if(comName=="activate" || comName=="click") {CalculateInfoDataF65();} break;
		case "B_F66": if(comName=="activate" || comName=="click") {CalculateInfoDataF66();} break;
		case "B_F67": if(comName=="activate" || comName=="click") {CalculateInfoDataF67();} break;
		case "B_F68": if(comName=="activate" || comName=="click") {CalculateInfoDataF68();} break;
		case "B_F69": if(comName=="activate" || comName=="click") {CalculateInfoDataF69();} break;
		case "B_F70": if(comName=="activate" || comName=="click") {CalculateInfoDataF70();} break;
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(7); // Статистика по читам
}

string descF1 = "'Чёрная Жемчужина'";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\BlackPearl.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BLACKPEARL, true, pchar);
	pchar.Ship.name = "Чёрная жемчужина";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Корабль 'Чёрная жемчужина' " + sTextA + GetShipInfo();
	totalInfo += "\nАвторы: Bonjourmonami (модель), Legendary Spider (текстуры). Адаптация и доработка: BiGPiMP, Layder";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Корабль 'Чёрная жемчужина' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F1", 1);
}

string descF2 = "'Летучий Голландец'";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\flyingdutchman_l.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FDM, true, pchar);
	pchar.Ship.name = "Летучий Голландец";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	ShipCargoAutoFill(5);
	totalInfo += "Корабль 'Летучий Голландец' " + sTextA + GetShipInfo();
	totalInfo += "\nАвтор: ZarethPL (модель). Адаптация для ГПК: BiGPiMP, остров, Prosto_pirat, Layder (иконка)";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Корабль 'Летучий Голландец' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F2", 1);
}

string descF3 = "'Калеуче'";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\flyingdutchman.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CURSED_FDM, true, pchar);
	pchar.Ship.name = "Калеуче";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS36;
	ShipCargoAutoFill(5);
	totalInfo += "Корабль 'Калеуче' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Корабль 'Калеуче' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F3", 1);
}

string descF4 = "'Месть Королевы Анны'";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\QAR.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_QAR, true, pchar);
	pchar.Ship.name = "Месть Королевы Анны";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Корабль 'Месть Королевы Анны' " + sTextA + GetShipInfo();
	totalInfo += "\nАвтор: Bonjourmonami (модель). Авторы сборки: Babb и BiGPiMP (адаптация к ГПК), Layder (иконка)";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Корабль 'Месть Королевы Анны' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F4", 1);
}

string descF5 = "Мановар 'Мортиферо'";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Santisima.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LSHIP_QUEST, true, pchar);
	pchar.Ship.name = "Мортиферо";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	ShipCargoAutoFill(10);
	totalInfo += "Быстрый мановар 'Мортиферо' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Быстрый мановар 'Мортиферо' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F5", 1);
}

string descF6 = "Королевский мановар 'Солей Руаяль'";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\SoleyRu.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SOLEYRU, true, pchar);
	pchar.Ship.name = "Солей Руаяль";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	ShipCargoAutoFill(10);
	totalInfo += "Королевский мановар 'Солей Руаяль' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Королевский мановар 'Солей Руаяль' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F6", 1);
}

string descF7 = "Линкор 'Виктори' или линкор 'Le Superbe'";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();

	ref ms, rBaseShip;
	string sShip, sShipName;
	string sNextShip = "\nСледующим нажатием будет выбран: ";
	string sPic = "INTERFACES\Ships";

	pchar.Ship.Type = GenerateShipExt(SHIP_MANOWARV, true, pchar);
	rBaseShip = GetShipByType(sti(RealShips[sti(pchar.Ship.Type)].BaseType));

	if (CheckAttribute(pchar, "CSM.SwapVictory"))
	{
		DeleteAttribute(pchar, "CSM.SwapVictory");
		DeleteAttribute(rBaseShip, "CSM.ChangeSkin");
		sPic += "\ManowarV.tga";
		sShip = "Линкор 1-го ранга 'Виктори' ";
		sShipName = "Виктори";
	}
	else
	{
		pchar.CSM.SwapVictory = true;
		rBaseShip.CSM.ChangeSkin = true;
		sPic += "\LeSuperbe.tga";
		sShip = "Линкор 3-го ранга 'Le Superbe' ";
		sShipName = "Le Superbe";
	}

	ShipsInit();

	pchar.Ship.Type = GenerateShipExt(SHIP_MANOWARV, true, pchar);
	pchar.Ship.name = sShipName;
	SetBaseShipData(pchar);
	ShipCargoAutoFill(10);

	totalInfo += sShip + sTextA + GetShipInfo();

	if (rBaseShip.name == "LeSuperbe")
	{
		pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
		sNextShip += "линкор 1-го ранга 'Виктори'";
	}
	else
	{
		pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
		sNextShip += "линкор 3-го ранга 'Le Superbe'";
		totalInfo += "\nАвтор: pgargon (модель). Адаптация для ГПК и текстуры: Stas_Beltrop";
	}

	SetNewPicture("CSMPICTURE", sPic);
	totalInfo += sNextShip + back2totalInfo;
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F7", 1);
}

string descF8 = "Быстрый фрегат 'Фортуна'";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\ArabellaShip.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FRIGATE_L, true, pchar);
	pchar.Ship.name = "Фортуна";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Быстрый фрегат 'Фортуна' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Быстрый фрегат 'Фортуна' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F8", 1);
}

string descF9 = "Малый фрегат 'Гриффондор'";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\corvette_quest.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CORVETTE_QUEST, true, pchar);
	pchar.Ship.name = "Гриффондор";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Малый фрегат 'Гриффондор' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Малый фрегат 'Гриффондор' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F9", 1);
}

string descF10 = "Патрульный бриг 'Валькирия'";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\valciria.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_VALCIRIA, true, pchar);
	pchar.Ship.name = "Валькирия";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Патрульный бриг 'Валькирия' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Патрульный бриг 'Валькирия' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F10", 1);
}

string descF11 = "Приватирский кеч 'Мираж'";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Mirage.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_MIRAGE, true, pchar);
	pchar.Ship.name = "Мираж";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Приватирский кеч 'Мираж' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Приватирский кеч 'Мираж' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F11", 1);
}

string descF12 = "Легкая шебека 'Мэйфэнг'";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Mayfang.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_MAYFANG, true, pchar);
	pchar.Ship.name = "Мэйфэнг";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Легкая шебека 'Мэйфэнг' " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Легкая шебека 'Мэйфэнг' " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F12", 1);
}

string descF13 = "Полакр 'Тореро'";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Polacre_q.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_POLACRE_QUEST, true, pchar);
	pchar.Ship.name = "Тореро";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Полакр 'Тореро' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Полакр 'Тореро' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F13", 1);
}

string descF14 = "Фрегат 'Россия'";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Rossiya.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_ROSSIYA, true, pchar);
	pchar.Ship.name = "Россия";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат 'Россия' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Фрегат 'Россия' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F14", 1);
}

string descF15 = "Фрегат 'Сюрприз'";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Surprise.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SURPRISE, true, pchar);
	pchar.Ship.name = "Сюрприз";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат 'Сюрприз' " + sTextA + GetShipInfo();
	totalInfo += "\nАвтор: Jack Harrison (модель). Автор сборки: Black-Max";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Фрегат 'Сюрприз' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F15", 1);
}

string descF16 = "Фрегат 'Конституция'";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Constitution.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CONSTITUTION, true, pchar);
	pchar.Ship.name = "Конституция";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат 'Конституция' " + sTextA + GetShipInfo();
	totalInfo += "\nАвтор: ZarethPL";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Фрегат 'Конституция' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F16", 1);
}

string descF17 = "Бриг 'Спиди'";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Speedy.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SPEEDY, true, pchar);
	pchar.Ship.name = "Спиди";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(3);
	totalInfo += "Бриг 'Спиди' " + sTextA + GetShipInfo();
	totalInfo += "\nАвтор: pgargon (модель). Авторы сборки: Gekkon, остров";
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Бриг 'Спиди' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F17", 1);
}

string descF18 = "Корвет 'Пёс войны' или фрегат 'Эссекс'";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();

	ref ms, rBaseShip;
	string sShip, sShipName;
	string sNextShip = "\nСледующим нажатием будет выбран: ";
	string sPic = "INTERFACES\Ships";

	pchar.Ship.Type = GenerateShipExt(SHIP_WARDOG, true, pchar);
	rBaseShip = GetShipByType(sti(RealShips[sti(pchar.Ship.Type)].BaseType));

	if (CheckAttribute(pchar, "CSM.SwapWarDog"))
	{
		DeleteAttribute(pchar, "CSM.SwapWarDog");
		DeleteAttribute(rBaseShip, "CSM.ChangeSkin");
		DeleteAttribute(rBaseShip, "CSM.MastNoFall");
		sPic += "\Corvette_questCoAS.tga";
		sShip = "Корвет 'Пёс войны' ";
		sShipName = "Пёс войны";
	}
	else
	{
		pchar.CSM.SwapWarDog = true;
		rBaseShip.CSM.ChangeSkin = true;
		rBaseShip.CSM.MastNoFall = true;
		sPic += "\Essex.tga";
		sShip = "Фрегат 'Эссекс' ";
		sShipName = "Эссекс";
	}

	ShipsInit();

	pchar.Ship.Type = GenerateShipExt(SHIP_WARDOG, true, pchar);
	pchar.Ship.name = sShipName;
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);

	if (rBaseShip.name == "Essex")
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.ship.upgrades.hull = 1 + rand(1);
		sNextShip += "корвет 'Пёс войны' ";
	}
	else
		sNextShip += "фрегат 'Эссекс' ";

	SetNewPicture("CSMPICTURE", sPic);
	totalInfo += sShip + sTextA + GetShipInfo() + sNextShip + back2totalInfo;
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F18", 1);
}

string descF19 = "Фрегат 'Арабелла'";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\ArabellaShipCoAS.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_ARABELLA, true, pchar);
	pchar.Ship.name = "Арабелла";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат 'Арабелла' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Фрегат 'Арабелла' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F19", 1);
}

string descF20 = "Фрегат 'Королева'";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\FrigateQueen.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FRIGATEQUEEN, true, pchar);
	pchar.Ship.name = "Королева";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат 'Королева' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Фрегат 'Королева' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F20", 1);
}

string descF21 = "Бриг 'Морской волк'";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\BrigSW.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BRIGSW, true, pchar);
	pchar.Ship.name = "Морской волк";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(3);
	totalInfo += "Бриг 'Морской волк' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Бриг 'Морской волк' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F21", 1);
}

string descF22 = "Бриг 'Королева'";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\BrigQueen.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BRIGQUEEN, true, pchar);
	pchar.Ship.name = "Королева";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(3);
	totalInfo += "Бриг 'Королева' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Бриг 'Королева' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F22", 1);
}

string descF23 = "Люггер 'Нормандия'";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Luggerr.tga");
	ref rShip;
	pchar.Ship.Type = GenerateShipExt(SHIP_LUGGERR, true, pchar);
	pchar.Ship.name = "Нормандия";
	rShip = &RealShips[sti(pchar.Ship.Type)];
	if (sti(rShip.Class) != 5) { rShip.Class = 5; }
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ShipCargoAutoFill(2);
	totalInfo += "Люггер 'Нормандия' " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipGood.wav");
	Log_info("Люггер 'Нормандия' " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F23", 1);
}

string descF24 = "Английский флагманский линкор";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\LSHIP_ENG.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LSHIP_ENG, true, pchar);
	pchar.Ship.name = "Виктори";
	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	ShipCargoAutoFill(10);
	totalInfo += "Английский линейный корабль " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Английский линейный корабль " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F24", 1);
}

string descF25 = "Испанский флагманский линкор";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\LSHIP_SPA.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LSHIP_SPA, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS42;
	ShipCargoAutoFill(10);
	totalInfo += "Испанский линейный корабль " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Испанский линейный корабль " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F25", 1);
}

string descF26 = "Голландский флагманский линкор";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\LSHIP_HOL.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LSHIP_HOL, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	ShipCargoAutoFill(10);
	totalInfo += "Голландский линейный корабль " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Голландский линейный корабль " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F26", 1);
}

string descF27 = "Французский флагманский линкор";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\LSHIP_FRA.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LSHIP_FRA, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	ShipCargoAutoFill(10);
	totalInfo += "Французский линейный корабль " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Французский линейный корабль " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F27", 1);
}

string descF28 = "Военный корабль";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\lineship.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LINESHIP, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS36;
	ShipCargoAutoFill(7);
	totalInfo += "Военный корабль " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Военный корабль " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F28", 1);
}

string descF29 = "Тяжелый фрегат";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Frigate_h.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FRIGATE_H, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Тяжелый фрегат " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Тяжелый фрегат " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F29", 1);
}

string descF30 = "Ост-Индец";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\eastindiaman.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_EASTINDIAMAN, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Ост-Индец " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Ост-Индец " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F30", 1);
}

string descF31 = "Навио";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\navio.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_NAVIO, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Навио " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Навио " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F31", 1);
}

string descF32 = "Фрегат";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\frigate.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FRIGATE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Фрегат " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Фрегат " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F32", 1);
}

string descF33 = "Тяжелый галеон";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\HeavyGaleon.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_HEAVYGALEON, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ShipCargoAutoFill(5);
	totalInfo += "Тяжелый галеон " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Тяжелый галеон " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F33", 1);
}

string descF34 = "Полакр";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Polacre.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_POLACRE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Полакр " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Полакр " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F34", 1);
}

string descF35 = "Щебека";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\XebekVML.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_XebekVML, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Щебека " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Щебека " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F35", 1);
}

string descF36 = "Корвет";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\corvette.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CORVETTE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Корвет " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Корвет " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F36", 1);
}

string descF37 = "Галеон";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\galeon_l.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_GALEON_L, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS20;
	ShipCargoAutoFill(5);
	totalInfo += "Галеон " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Галеон " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F37", 1);
}

string descF38 = "Пинас";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\pinnace.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_PINNACE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(4);
	totalInfo += "Пинас " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Пинас " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F38", 1);
}

string descF39 = "Каравелла";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\caravel.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CARAVEL, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(4);
	totalInfo += "Каравелла " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Каравелла " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F39", 1);
}

string descF40 = "Флейт";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\fleut.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_FLEUT, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ShipCargoAutoFill(4);
	totalInfo += "Флейт " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Флейт " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F40", 1);
}

string descF41 = "Шнява";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\shnyava.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SHNYAVA, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(4);
	totalInfo += "Шнява " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Шнява " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F41", 1);
}

string descF42 = "Каракка";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\caracca.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CARACCA, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(4);
	totalInfo += "Каракка " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Каракка " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F42", 1);
}

string descF43 = "Военная шхуна";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\schooner_w.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SCHOONER_W, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(3);
	totalInfo += "Военная шхуна " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Военная шхуна " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F43", 1);
}

string descF44 = "Бриг";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\brig.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BRIG, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(3);
	totalInfo += "Бриг " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Бриг " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F44", 1);
}

string descF45 = "Бригантина";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Brigantine.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BRIGANTINE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ShipCargoAutoFill(2);
	totalInfo += "Бригантина " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Бригантина " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F45", 1);
}

string descF46 = "Баркентина";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\barkentine.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BARKENTINE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ShipCargoAutoFill(2);
	totalInfo += "Баркентина " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Баркентина " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F46", 1);
}

string descF47 = "Торговая шхуна";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\schooner.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SCHOONER, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ShipCargoAutoFill(2);
	totalInfo += "Торговая шхуна " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Торговая шхуна " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F47", 1);
}

string descF48 = "Шлюп";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\sloop.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_SLOOP, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12;
	ShipCargoAutoFill(2);
	totalInfo += "Шлюп " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Шлюп " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F48", 1);
}

string descF49 = "Курьерский люггер";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\LuggerQuest.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_CAREERLUGGER, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
	ShipCargoAutoFill(1);
	totalInfo += "Курьерский люггер " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Курьерский люггер " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F49", 1);
}

string descF50 = "Люггер";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\lugger.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_LUGGER, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
	ShipCargoAutoFill(1);
	totalInfo += "Люггер " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Люггер " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F50", 1);
}

string descF51 = "Барк";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Barque.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_BARQUE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
	ShipCargoAutoFill(1);
	totalInfo += "Барк " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\Ship.wav");
	Log_info("Барк " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F51", 1);
}

string descF52 = "Тартана";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\WarTartane.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_WAR_TARTANE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
	ShipCargoAutoFill(1);
	totalInfo += "Тартана " + sTextB + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipBad.wav");
	Log_info("Тартана " + sTextB);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F52", 1);
}

string descF53 = "Баркас";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	SetNewPicture("CSMPICTURE", "INTERFACES\Ships\Tartane.tga");
	pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);
	SetCrewQuantityFull(pchar);
	AddCrewMorale(pchar, 100);
	ChangeCrewExp(pchar, "Sailors", 100);
	ChangeCrewExp(pchar, "Cannoners", 100);
	ChangeCrewExp(pchar, "Soldiers", 100);
	SetCharacterGoods(pchar, GOOD_FOOD, 50);
	SetCharacterGoods(pchar, GOOD_WEAPON, 25);
	SetCharacterGoods(pchar, GOOD_MEDICAMENT, 25);
	SetCharacterGoods(pchar, GOOD_RUM, 5);
	totalInfo += "Баркас " + sTextA + GetShipInfo();
	iSND = PlaySound("_CheatSurfMenu_\ShipBad.wav");
	Log_info("Баркас " + sTextA);
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM8.F53", 1);
}

string descF54 = "! ПУСТО !";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F54", 1);
}

string descF55 = "! ПУСТО !";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F55", 1);
}

string descF56 = "! ПУСТО !";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F56", 1);
}

string descF57 = "! ПУСТО !";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F57", 1);
}

string descF58 = "! ПУСТО !";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F58", 1);
}

string descF59 = "! ПУСТО !";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F59", 1);
}

string descF60 = "! ПУСТО !";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F60", 1);
}

string descF61 = "! ПУСТО !";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F61", 1);
}

string descF62 = "! ПУСТО !";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F62", 1);
}

string descF63 = "! ПУСТО !";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F63", 1);
}

string descF64 = "! ПУСТО !";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F64", 1);
}

string descF65 = "! ПУСТО !";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F65", 1);
}

string descF66 = "! ПУСТО !";
void CalculateInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F66", 1);
}

string descF67 = "! ПУСТО !";
void CalculateInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F67", 1);
}

string descF68 = "! ПУСТО !";
void CalculateInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F68", 1);
}

string descF69 = "! ПУСТО !";
void CalculateInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F69", 1);
}

string descF70 = "! ПУСТО !";
void CalculateInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM8.F70", 1);
}

void ShipCargoAutoFill(int iQty)
{
	if (iQty < 1 || iQty > 100) { iQty = 1; }
	SetCrewQuantityFull(pchar);
	AddCrewMorale(pchar, 100);
	ChangeCrewExp(pchar, "Sailors", 100);
	ChangeCrewExp(pchar, "Cannoners", 100);
	ChangeCrewExp(pchar, "Soldiers", 100);
	SetCharacterGoods(pchar, GOOD_BALLS, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_GRAPES, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_KNIPPELS, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_BOMBS, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_FOOD, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_POWDER, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_WEAPON, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_MEDICAMENT, 100 * iQty);
	SetCharacterGoods(pchar, GOOD_RUM, 10 * iQty);
}

string GetShipInfo()
{
	if (sti(pchar.Ship.Type) == SHIP_NOTUSED) { return "Нет корабля!"; }

	ref rShip;
	string sInfo;
	rShip = &RealShips[sti(pchar.Ship.Type)];

	sInfo = "\nКорпус: " + sti(rShip.HP) + " | Трюм: " + sti(rShip.Capacity) +
			"\nСкорость: " + stf(rShip.SpeedRate) + " | Маневренность: " + stf(rShip.TurnRate) +
			"\nКоманда: " + sti(rShip.OptCrew) + " (минимум " + sti(rShip.MinCrew) + " | максимум " + sti(rShip.MaxCrew) + ")";

	if (sti(rShip.CannonsQuantityMin) > 0)
	{
		sInfo += "\nПушек: " + sti(rShip.CannonsQuantity) + " | Калибр (установленный: " + GetCannonCaliber(sti(pchar.Ship.Cannons.Type)) + " | максимальный: " + sti(rShip.MaxCaliber) + ")";
	}
	else
	{
		sInfo += "\nНаличие пушек не предусмотрено";
	}

	return sInfo;
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
	if(GetSelectable("INFO_TEXT")) controlNode = "INFO_TEXT";
	if(controlNode!="")
	{
		if(changeNum>0)
		{
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		}
		else
		{
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}

// Пусть будет в качестве заготовки. Пропишу тексты. Потом. Кого я обманываю...
void ShowInfoWindow()
{
	return;
	string sHeader = "! ПУСТО !";
	string sNode = GetCurrentNode();

	string sText1, sText2, sText3, sPicture, sGroup, sGroupPicture;
	sPicture = "none";
	sGroup = "none";
	sGroupPicture = "none";

	switch(sNode)
	{
		case "INFO_TEXT":
			sHeader = "Описание меню 'Корабли'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Корабли' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Корабли'";
			sText1 = "Перезапуск меню 'Корабли'";
		break;
		case "B_M1":
			sHeader = "Меню 'Персонаж'";
			sText1 = "Запуск меню 'Персонаж'";
		break;
		case "B_M2":
			sHeader = "Меню 'Умения'";
			sText1 = "Запуск меню 'Умения'";
		break;
		case "B_M3":
			sHeader = "Меню 'Предметы'";
			sText1 = "Запуск меню 'Предметы'";
		break;
		case "B_M4":
			sHeader = "Меню 'Корабль'";
			sText1 = "Запуск меню 'Корабль'";
		break;
		case "B_M5":
			sHeader = "Меню 'Локации'";
			sText1 = "Запуск меню 'Локации'";
		break;
		case "B_M6":
			sHeader = "Меню 'Товары'";
			sText1 = "Запуск меню 'Товары'";
		break;
		case "B_M7":
			sHeader = "Меню 'Офицеры'";
			sText1 = "Запуск меню 'Офицеры'";
		break;
		case "B_M8":
			sHeader = "Меню 'Прочее'";
			sText1 = "Запуск меню 'Прочее'";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
