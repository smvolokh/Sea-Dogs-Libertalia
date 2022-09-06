
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Тюнинг кораблей
	Основано на меню дебаггера от boal
	15.06.18
*/

int iSND = 0;
int iShipType;
ref ms, rRealShip, rBaseShip;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке ''Корабль'' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sNoShip = "А где же Ваш корабль, капитан?!";
string sCrewNow = "Текущая численность команды: ";
string sCrewMax = "Текущая численность максимальной команды: ";
string sCrewMin = "Текущая численность минимальной команды: ";
string sCrewOpt = "Текущая численность оптимальной команды: ";
string sCurrVal = "Текущее значение: ";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_shipstuning";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(3); // Warship. Статистика - сколько читов юзали
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
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"\n\n********** ПРОЧНОСТЬ КОРПУСА **********" + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() +
					"\n\n********** ВМЕСТИМОСТЬ ТРЮМА **********" + NewStr() +
					"< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() + "< 16 > " + descF16 + NewStr() +
					"< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() + "< 19 > " + descF19 + NewStr() +
					"< 20 > " + descF20 + NewStr() +
					"\n\n********** СКОРОСТЬ КОРАБЛЯ **********" + NewStr() +
					"< 21 > " + descF21 + NewStr() + "< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() +
					"< 24 > " + descF24 + NewStr() + "< 25 > " + descF25 + NewStr() +
					"\n\n********** МАНЕВРЕННОСТЬ КОРАБЛЯ **********" + NewStr() +
					"< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() +
					"\n\n********** КУРСОВОЙ УГОЛ **********" + NewStr() +
					"< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() +
					"\n\n********** УРОВЕНЬ ВАТЕРЛИНИИ **********" + NewStr() +
					"< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() +
					"\n\n********** ЧИСЛЕННОСТЬ КОМАНДЫ **********" + NewStr() +
					"---------- Минимальная команда ----------" + NewStr() +
					"< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() +
					"< 43 > " + descF43 + NewStr() +
					"---------- Оптимальная команда ----------" + NewStr() +
					"< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() + "< 46 > " + descF46 + NewStr() +
					"< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() + "< 49 > " + descF49 + NewStr() +
					"< 50 > " + descF50 + NewStr() +
					"---------- Максимальная команда ----------" + NewStr() +
					"< 51 > " + descF51 + NewStr() + "< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() +
					"< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + NewStr() + "< 56 > " + descF56 + NewStr() +
					"< 57 > " + descF57 + NewStr() +
					"---------- Общее ----------" + NewStr() +
					"< 58 > " + descF58 + NewStr() + "< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() +
					"\n\n********** ПРОЧЕЕ **********" + NewStr() +
					"< 61 > " + descF61 + NewStr() +
					"< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() +
					"< 65 > " + descF65 + NewStr() + "\n\n---------- Фишки от Sticksъ ----------" + NewStr() + "< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() + "< 68 > " + descF68 + NewStr() + "< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(3); // Статистика по читам
}

string descF1 = "Ремонт всех кораблей в эскадре";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	ref sld, ship;
	int ic, icn;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ProcessHullRepair(pchar, 100.0);
		ProcessSailRepair(pchar, 100.0);
		DeleteAttribute(pchar, "Ship.Blots");
		DeleteAttribute(pchar, "Ship.Hulls");
		DeleteAttribute(pchar, "Ship.Masts");
		DeleteAttribute(pchar, "Ship.Sails");
		RefreshShipsCannonsCond(pchar);
		// by Sticksъ -->
		// Аналог бермудского ремонта
        ship = &RealShips[sti(Pchar.Ship.Type)];
        ship.HP = sti(RealShips[sti(pchar.Ship.Type)].BaseHP);
		// by Sticksъ <--
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				ProcessHullRepair(sld, 100.0);
				ProcessSailRepair(sld, 100.0);
				DeleteAttribute(sld, "Ship.Blots");
				DeleteAttribute(sld, "Ship.Hulls");
				DeleteAttribute(sld, "Ship.Masts");
				DeleteAttribute(sld, "Ship.Sails");
				RefreshShipsCannonsCond(sld);
				// by Sticksъ -->
				// Аналог бермудского ремонта
                ship = &RealShips[sti(sld.Ship.Type)];
                ship.HP = sti(RealShips[sti(sld.Ship.Type)].BaseHP);
				// by Sticksъ <--
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		Log_info("Все корабли в эскадре ГГ полностью отремонтированы!");
		totalInfo += "Все корабли в эскадре ГГ полностью отремонтированы!";
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F1", 1);
}

string descF2 = "Пополнение команды на всех кораблях эскадры";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	ref sld;
	int ic, icn;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		SetCrewQuantityFull(pchar);
		SeaDogsCrew(pchar);
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				SetCrewQuantityFull(sld);
				SeaDogsCrew(sld);
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\SeaDogs.wav");
		Log_info("На всех кораблях эскадры ГГ, команда пополнена морскими волками!");
		totalInfo += "На всех кораблях эскадры ГГ, команда пополнена морскими волками!" + NewStr() + "Опыт и мораль всем матросам выставлены на максимум!";
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F2", 1);
}

string descF3 = "Комплексное пополнение боеприпасов и провианта на всех кораблях эскадры";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	ref sld;
	int ic, icn;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		AddCharacterGoods(Pchar, GOOD_BALLS, 500);
		AddCharacterGoods(Pchar, GOOD_BOMBS, 500);
		AddCharacterGoods(Pchar, GOOD_GRAPES, 500);
		AddCharacterGoods(Pchar, GOOD_KNIPPELS, 500);
		AddCharacterGoods(Pchar, GOOD_POWDER, 500);
		AddCharacterGoods(Pchar, GOOD_FOOD, 500);
		AddCharacterGoods(Pchar, GOOD_WEAPON, 500);
		AddCharacterGoods(Pchar, GOOD_MEDICAMENT, 500);
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				AddCharacterGoods(sld, GOOD_BALLS, 500);
				AddCharacterGoods(sld, GOOD_BOMBS, 500);
				AddCharacterGoods(sld, GOOD_GRAPES, 500);
				AddCharacterGoods(sld, GOOD_KNIPPELS, 500);
				AddCharacterGoods(sld, GOOD_POWDER, 500);
				AddCharacterGoods(sld, GOOD_FOOD, 500);
				AddCharacterGoods(sld, GOOD_WEAPON, 500);
				AddCharacterGoods(sld, GOOD_MEDICAMENT, 500);
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
		Log_info("Боеприпасы, оружие, продовольствие и медикаменты добавлены в трюмы всех кораблей в эскадре!");
		totalInfo += "Боеприпасы, оружие, продовольствие и медикаменты добавлены в трюмы всех кораблей в эскадре!" + NewStr() + "Каждое нажатие добавляет по 500 единиц перечисленного товара.";
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F3", 1);
}

string descF4 = "Произвести полный апгрейд всех кораблей в эскадре";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	ref sld;
	int ic, icn;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		// Флагман
		ms = GetRealShip(sti(pchar.Ship.Type));
		UpgradeShipParameter(pchar, "Cannons");
		UpgradeShipParameter(pchar, "Capacity");
		UpgradeShipParameter(pchar, "HP");
		// UpgradeShipParameter(pchar, "MinCrew");
		UpgradeShipParameter(pchar, "MaxCrew");
		UpgradeShipParameter(pchar, "SpeedRate");
		UpgradeShipParameter(pchar, "TurnRate");
		UpgradeShipParameter(pchar, "WindAgainstSpeed");
		ProcessHullRepair(pchar, 100.0);
		ProcessSailRepair(pchar, 100.0);
		DeleteAttribute(pchar, "Ship.Blots");
		DeleteAttribute(pchar, "Ship.Hulls");
		DeleteAttribute(pchar, "Ship.Masts");
		DeleteAttribute(pchar, "Ship.Sails");
		SetCrewQuantityFull(pchar);
		SeaDogsCrew(pchar);
		if (sti(ms.HP) > 999999) { ms.HP = 999999; pchar.ship.hp = sti(ms.HP); }
		if (sti(ms.BaseHP) > 999999) { ms.BaseHP = 999999; }
		if (sti(ms.Capacity) > 999999) { ms.Capacity = 999999; }
		if (stf(ms.SpeedRate) > 99.99) { ms.SpeedRate = 99.99; }
		if (stf(ms.TurnRate) > 99.99) { ms.TurnRate = 99.99; }
		if (sti(ms.MinCrew) > 999) { ms.MinCrew = 999; }
		if (sti(ms.OptCrew) > 7777) { ms.OptCrew = 7777; }
		if (sti(ms.MaxCrew) > 9999) { ms.MaxCrew = 9999; }
		ms.BaseHP = sti(ms.HP); // fix by Sticksъ: учтено BaseHP
		PlaySound("_CheatSurfMenu_\Repair.wav");
		iSND = PlaySound("_CheatSurfMenu_\SailsUp.wav");
		Log_info("Полный апгрейд всех кораблей в эскадре произведен!");
		totalInfo += "Полный апгрейд всех кораблей в эскадре произведен!";
		// Прочие корабли в эскадре
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				ms = GetRealShip(sti(sld.Ship.Type));
				UpgradeShipParameter(sld, "Cannons");
				UpgradeShipParameter(sld, "Capacity");
				UpgradeShipParameter(sld, "HP");
				UpgradeShipParameter(sld, "MaxCrew");
				UpgradeShipParameter(sld, "SpeedRate");
				UpgradeShipParameter(sld, "TurnRate");
				UpgradeShipParameter(sld, "WindAgainstSpeed");
				ProcessHullRepair(sld, 100.0);
				ProcessSailRepair(sld, 100.0);
				DeleteAttribute(sld, "Ship.Blots");
				DeleteAttribute(sld, "Ship.Hulls");
				DeleteAttribute(sld, "Ship.Masts");
				DeleteAttribute(sld, "Ship.Sails");
				SetCrewQuantityFull(sld);
				SeaDogsCrew(sld);
				if (sti(ms.HP) > 999999) { ms.HP = 999999; sld.ship.hp = sti(ms.HP); }
				if (sti(ms.BaseHP) > 999999) { ms.BaseHP = 999999; }
				if (sti(ms.Capacity) > 999999) { ms.Capacity = 999999; }
				if (stf(ms.SpeedRate) > 99.99) { ms.SpeedRate = 99.99; }
				if (stf(ms.TurnRate) > 99.99) { ms.TurnRate = 99.99; }
				if (sti(ms.MinCrew) > 999) { ms.MinCrew = 999; }
				if (sti(ms.OptCrew) > 7777) { ms.OptCrew = 7777; }
				if (sti(ms.MaxCrew) > 9999) { ms.MaxCrew = 9999; }
				ms.BaseHP = sti(ms.HP); // fix by Sticksъ: учтено BaseHP
			}
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F4", 1);
}

string descF5 = "Установить на корабль нужный тип и калибр вооружения";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	string sGunsA = "На корабль установлены пушки калибра: ";
	string sGunsB = "На корабль установлены кулеврины калибра: ";
	string sNextA = "Следующим нажатием будут установлены пушки калибра: ";
	string sNextB = "Следующим нажатием будут установлены кулеврины калибра: ";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		if (GetCannonsNum(pchar) > 0)
		{
			switch(sti(pchar.ship.cannons.type))
			{
				case CANNON_TYPE_CANNON_LBS3:
					pchar.ship.cannons.type = 1;
					Log_info(sGunsA + "6!");
					totalInfo += sGunsA + "6!" + NewStr() + sNextA + "12.";
				break;
				case CANNON_TYPE_CANNON_LBS6:
					pchar.ship.cannons.type = 2;
					Log_info(sGunsA + "12!");
					totalInfo += sGunsA + "12!" + NewStr() + sNextA + "16.";
				break;
				case CANNON_TYPE_CANNON_LBS12:
					pchar.ship.cannons.type = 3;
					Log_info(sGunsA + "16!");
					totalInfo += sGunsA + "16!" + NewStr() + sNextA + "20.";
				break;
				case CANNON_TYPE_CANNON_LBS16:
					pchar.ship.cannons.type = 4;
					Log_info(sGunsA + "20!");
					totalInfo += sGunsA + "20!" + NewStr() + sNextA + "24.";
				break;
				case CANNON_TYPE_CANNON_LBS20:
					pchar.ship.cannons.type = 5;
					Log_info(sGunsA + "24!");
					totalInfo += sGunsA + "24!" + NewStr() + sNextA + "32.";
				break;
				case CANNON_TYPE_CANNON_LBS24:
					pchar.ship.cannons.type = 6;
					Log_info(sGunsA + "32!");
					totalInfo += sGunsA + "32!" + NewStr() + sNextA + "36.";
				break;
				case CANNON_TYPE_CANNON_LBS32:
					pchar.ship.cannons.type = 7;
					Log_info(sGunsA + "36!");
					totalInfo += sGunsA + "36!" + NewStr() + sNextA + "42.";
				break;
				case CANNON_TYPE_CANNON_LBS36:
					pchar.ship.cannons.type = 8;
					Log_info(sGunsA + "42!");
					totalInfo += sGunsA + "42" + NewStr() + sNextA + "48.";
				break;
				case CANNON_TYPE_CANNON_LBS42:
					pchar.ship.cannons.type = 9;
					Log_info(sGunsA + "48!");
					totalInfo += sGunsA + "48!" + NewStr() + sNextB + "8.";
				break;
				case CANNON_TYPE_CANNON_LBS48:
					pchar.ship.cannons.type = 10;
					Log_info(sGunsB + "8!");
					totalInfo += sGunsB + "8!" + NewStr() + sNextB + "18.";
				break;
				case CANNON_TYPE_CULVERINE_LBS8:
					pchar.ship.cannons.type = 11;
					Log_info(sGunsB + "18!");
					totalInfo += sGunsB + "18!" + NewStr() + sNextB + "36.";
				break;
				case CANNON_TYPE_CULVERINE_LBS18:
					pchar.ship.cannons.type = 12;
					Log_info(sGunsB + "36!");
					totalInfo += sGunsB + "36!" + NewStr() + sNextA + "3.";
				break;
				case CANNON_TYPE_CULVERINE_LBS36:
					pchar.ship.cannons.type = 0;
					Log_info(sGunsA + "3!");
					totalInfo += sGunsA + "3!" + NewStr() + sNextA + "6.";
				break;
			}
			iSND = PlaySound("_CheatSurfMenu_\Cannons.wav");
		}
		else
		{
			Log_info("Сперва следует установить на корабль хоть какие-нибудь пушки!");
			totalInfo += "Сперва следует установить на корабль хоть какие-нибудь пушки!";
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F5", 1);
}

string descF6 = "Видеть \ не видеть матросов на палубе от 1-го лица";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	if (bSeePeoplesOnDeck == true)
	{
		bSeePeoplesOnDeck = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Отображение матросов на палубе отключено.");
		totalInfo += "Отображение матросов на палубе отключено.";
	}
	else
	{
		bSeePeoplesOnDeck = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		Log_info("Отображение матросов на палубе включено!");
		totalInfo += "Отображение матросов на палубе включено!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F6", 1);
}

string descF7 = "Увеличить корпус на 1";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.HP = sti(ms.HP) + 1;
		if (sti(ms.HP) < 999999)
		{
			Log_info("Прочность корпуса корабля увеличена на 1 единицу!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля увеличена на 1 единицу!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		else
		{
			ms.HP = 999999; // Чтобы в 1 строку в меню помещалось, а то как-то не ok
			Log_info("Прочность корпуса корабля достигла максимального показателя!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля достигла максимального показателя!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
		pchar.ship.hp = sti(ms.HP);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F7", 1);
}

string descF8 = "Увеличить корпус на 100";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.HP = sti(ms.HP) + 100;
		if (sti(ms.HP) < 999999)
		{
			Log_info("Прочность корпуса корабля увеличена на 100 единиц!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля увеличена на 100 единиц!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		else
		{
			ms.HP = 999999; // Чтобы в 1 строку в меню помещалось, а то как-то не ок
			Log_info("Прочность корпуса корабля достигла максимального показателя!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля достигла максимального показателя!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
		pchar.ship.hp = sti(ms.HP);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F8", 1);
}

string descF9 = "Увеличить корпус на 1000";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.HP = sti(ms.HP) + 1000;
		if (sti(ms.HP) < 999999)
		{
			Log_info("Прочность корпуса корабля увеличена на 1.000 единиц!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля увеличена на 1.000 единиц!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		else
		{
			ms.HP = 999999; // Чтобы в 1 строку в меню помещалось, а то как-то не ок
			Log_info("Прочность корпуса корабля достигла максимального показателя!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля достигла максимального показателя!" + NewStr() + sCurrVal + sti(ms.HP);
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
		pchar.ship.hp = sti(ms.HP);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F9", 1);
}

string descF10 = "Уменьшить корпус на 1";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.HP) > 100)
		{
			ms.HP = sti(ms.HP) - 1;
			if (sti(ms.HP) < 100) { ms.HP = 100; }
			pchar.ship.hp = sti(ms.HP);
			Log_info("Прочность корпуса корабля уменьшена на 1 единицу!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля уменьшена на 1 единицу!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше прочность уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Дальше прочность уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F10", 1);
}

string descF11 = "Уменьшить корпус на 100";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.HP) > 100)
		{
			ms.HP = sti(ms.HP) - 100;
			if (sti(ms.HP) < 100) { ms.HP = 100; }
			pchar.ship.hp = sti(ms.HP);
			Log_info("Прочность корпуса корабля уменьшена на 100 единиц!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля уменьшена на 100 единиц!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше прочность уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Дальше прочность уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F11", 1);
}

string descF12 = "Уменьшить корпус на 1000";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.HP) > 1000)
		{
			ms.HP = sti(ms.HP) - 1000;
			if (sti(ms.HP) < 100) { ms.HP = 100; }
			pchar.ship.hp = sti(ms.HP);
			Log_info("Прочность корпуса корабля уменьшена на 1.000 единиц!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Прочность корпуса корабля уменьшена на 1.000 единиц!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше прочность уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.HP));
			totalInfo += "Дальше прочность уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.HP);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		ms.BaseHP = sti(ms.HP); // by Sticksъ
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F12", 1);
}

string descF13 = "Выставить прочность корпуса по умолчанию";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.HP = sti(rBaseShip.HP);
		rRealShip.BaseHP = sti(rBaseShip.HP);
		RemoveShipsUpgrade(0);
		pchar.ship.hp = sti(rRealShip.HP);
		Log_info("Прочность корпуса корабля выставлена по умолчанию!");
		Log_info(sCurrVal + sti(rRealShip.HP));
		totalInfo += "Прочность корпуса корабля выставлена по умолчанию!" + NewStr() + sCurrVal + sti(rRealShip.HP);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F13", 1);
}

string descF14 = "Увеличить трюм на 1";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.Capacity	= sti(ms.Capacity) + 1;
		if (sti(ms.Capacity) > 999999)
		{
			ms.Capacity = 999999;
			Log_info("Вместимость трюма корабля предельно увеличена!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Вместимость трюма корабля предельно увеличена!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		else
		{
			Log_info("Трюм корабля увеличен на 1 единицу!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля увеличен на 1 единицу!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F14", 1);
}

string descF15 = "Увеличить трюм на 100";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.Capacity	= sti(ms.Capacity) + 100;
		if (sti(ms.Capacity) > 999999)
		{
			ms.Capacity = 999999;
			Log_info("Вместимость трюма корабля предельно увеличена!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Вместимость трюма корабля предельно увеличена!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		else
		{
			Log_info("Трюм корабля увеличен на 100 единиц!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля увеличен на 100 единиц!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F15", 1);
}

string descF16 = "Увеличить трюм на 1000";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.Capacity	= sti(ms.Capacity) + 1000;
		if (sti(ms.Capacity) > 999999)
		{
			ms.Capacity = 999999;
			Log_info("Вместимость трюма корабля предельно увеличена!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Вместимость трюма корабля предельно увеличена!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		else
		{
			Log_info("Трюм корабля увеличен на 1.000 единиц!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля увеличен на 1.000 единиц!" + NewStr() + sCurrVal + sti(ms.Capacity);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F16", 1);
}

string descF17 = "Уменьшить трюм на 1";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.Capacity) > 100)
		{
			ms.Capacity	= sti(ms.Capacity) - 1;
			if (sti(ms.Capacity) < 80) { ms.Capacity = 80; }
			Log_info("Трюм корабля уменьшен на 1 единицу!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля уменьшен на 1 единицу!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше вместимость уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Дальше вместимость уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F17", 1);
}

string descF18 = "Уменьшить трюм на 100";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.Capacity) > 100)
		{
			ms.Capacity	= sti(ms.Capacity) - 100;
			if (sti(ms.Capacity) < 80) { ms.Capacity = 80; }
			Log_info("Трюм корабля уменьшен на 100 единиц!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля уменьшен на 100 единиц!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше вместимость уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Дальше вместимость уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F18", 1);
}

string descF19 = "Уменьшить трюм на 1000";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.Capacity) > 1000)
		{
			ms.Capacity	= sti(ms.Capacity) - 1000;
			if (sti(ms.Capacity) < 80) { ms.Capacity = 80; }
			Log_info("Трюм корабля уменьшен на 1.000 единиц!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Трюм корабля уменьшен на 1.000 единиц!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Дальше вместимость уменьшать не стоит!");
			Log_info(sCurrVal + sti(ms.Capacity));
			totalInfo += "Дальше вместимость уменьшать не стоит!" + NewStr() + sCurrVal + sti(ms.Capacity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F19", 1);
}

string descF20 = "Выставить вместимость трюма по умолчанию";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.Capacity = sti(rBaseShip.Capacity);
		RemoveShipsUpgrade(4);
		Log_info("Вместимость трюма корабля выставлена по умолчанию!");
		Log_info(sCurrVal + sti(rRealShip.Capacity));
		totalInfo += "Вместимость трюма корабля выставлена по умолчанию!" + NewStr() + sCurrVal + sti(rRealShip.Capacity);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F20", 1);
}

string descF21 = "Увеличить скорость на 1";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.SpeedRate = stf(ms.SpeedRate) + 1.0;
		if (stf(ms.SpeedRate) > 99.99)
		{
			ms.SpeedRate = 99.99;
			Log_info("Возможная скорость корабля предельно увеличена!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля предельно увеличена!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
		}
		else
		{
			Log_info("Возможная скорость корабля увеличена на 1 единицу!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля увеличена на 1 единицу!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F21", 1);
}

string descF22 = "Увеличить скорость на 10";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.SpeedRate = stf(ms.SpeedRate) + 10.0;
		if (stf(ms.SpeedRate) > 99.99)
		{
			ms.SpeedRate = 99.99;
			Log_info("Возможная скорость корабля предельно увеличена!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля предельно увеличена!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
		}
		else
		{
			Log_info("Возможная скорость корабля увеличена на 10 единиц!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля увеличена на 10 единиц!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F22", 1);
}

string descF23 = "Уменьшить скорость на 1";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.SpeedRate) > 1.0 )
		{
			ms.SpeedRate = stf(ms.SpeedRate) - 1.0;
			if (stf(ms.SpeedRate) < 1.0) { ms.SpeedRate = 1.0; }
			Log_info("Скорость корабля уменьшена на 1 единицу!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля уменьшена на 1 единицу!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Скорость корабля достигла предельного допустимого минимума!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля достигла предельного допустимого минимума!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F23", 1);
}

string descF24 = "Уменьшить скорость на 10";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.SpeedRate) > 10.0 )
		{
			ms.SpeedRate = stf(ms.SpeedRate) - 10.0;
			if (stf(ms.SpeedRate) < 1.0) { ms.SpeedRate = 1.0; }
			Log_info("Скорость корабля уменьшена на 10 единиц!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля уменьшена на 10 единиц!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Скорость корабля достигла предельного допустимого минимума!");
			Log_info(sCurrVal + stf(ms.SpeedRate));
			totalInfo += "Скорость корабля достигла предельного допустимого минимума!" + NewStr() + sCurrVal + stf(ms.SpeedRate);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F24", 1);
}

string descF25 = "Выставить максимально возможную скорость по умолчанию";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.SpeedRate = stf(rBaseShip.SpeedRate);
		RemoveShipsUpgrade(1);
		Log_info("Максимально возможная скорость корабля выставлена по умолчанию!");
		Log_info(sCurrVal + stf(rRealShip.SpeedRate));
		totalInfo += "Максимально возможная скорость корабля выставлена по умолчанию!" + NewStr() + sCurrVal + stf(rRealShip.SpeedRate);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F25", 1);
}

string descF26 = "Увеличить маневренность на 1";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.TurnRate = stf(ms.TurnRate) + 1.0;
		if (stf(ms.TurnRate) > 99.99)
		{
			ms.TurnRate = 99.99;
			Log_info("Возможная маневренность корабля предельно увеличена!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля предельно увеличена!" + NewStr() + sCurrVal + stf(ms.TurnRate);
		}
		else
		{
			Log_info("Возможная маневренность корабля увеличена на 1 единицу!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля увеличена на 1 единицу!" + NewStr() + sCurrVal + stf(ms.TurnRate);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F26", 1);
}

string descF27 = "Увеличить маневренность на 10";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.TurnRate = stf(ms.TurnRate) + 10.0;
		if (stf(ms.TurnRate) > 99.99)
		{
			ms.TurnRate = 99.99;
			Log_info("Возможная маневренность корабля предельно увеличена!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля предельно увеличена!" + NewStr() + sCurrVal + stf(ms.TurnRate);
		}
		else
		{
			Log_info("Возможная маневренность корабля увеличена на 10 единиц!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля увеличена на 10 единиц!" + NewStr() + sCurrVal + stf(ms.TurnRate);
		}
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F27", 1);
}

string descF28 = "Уменьшить маневренность на 1";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.TurnRate) > 1.0 )
		{
			ms.TurnRate = stf(ms.TurnRate) - 1.0;
			if (stf(ms.TurnRate) < 1.0) { ms.TurnRate = 1.0; }
			Log_info("Маневренность корабля уменьшена на 1 единицу!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля уменьшена на 1 единицу!" + NewStr() + sCurrVal + stf(ms.TurnRate);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Маневренность корабля достигла предельного допустимого минимума!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля достигла предельно допустимого минимума!" + NewStr() + sCurrVal + stf(ms.TurnRate);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F28", 1);
}

string descF29 = "Уменьшить маневренность на 10";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.TurnRate) > 10.0 )
		{
			ms.TurnRate = stf(ms.TurnRate) - 10.0;
			if (stf(ms.TurnRate) < 1.0) { ms.TurnRate = 1.0; }
			Log_info("Маневренность корабля уменьшена на 10 единиц!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля уменьшена на 10 единиц!" + NewStr() + sCurrVal + stf(ms.TurnRate);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Маневренность корабля достигла предельного допустимого минимума!");
			Log_info(sCurrVal + stf(ms.TurnRate));
			totalInfo += "Маневренность корабля достигла предельно допустимого минимума!" + NewStr() + sCurrVal + stf(ms.TurnRate);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F29", 1);
}

string descF30 = "Выставить максимально возможную маневренность по умолчанию";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.TurnRate = stf(rBaseShip.TurnRate);
		RemoveShipsUpgrade(2);
		Log_info("Максимально возможная маневренность корабля выставлена по умолчанию!");
		Log_info(sCurrVal + stf(rRealShip.TurnRate));
		totalInfo += "Максимально возможная маневренность корабля выставлена по умолчанию!" + NewStr() + sCurrVal + stf(rRealShip.TurnRate);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F30", 1);
}

string descF31 = "Увеличить курсовой угол на 0.1";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.WindAgainstSpeed) < 2.0)
		{
			ms.WindAgainstSpeed = stf(ms.WindAgainstSpeed) + 0.1;
			if (stf(ms.WindAgainstSpeed) > 2.0) { ms.WindAgainstSpeed = 2.0; }
			Log_info("Курсовой угол корабля увеличен!");
			Log_info(sCurrVal + stf(ms.WindAgainstSpeed));
			totalInfo += "Курсовой угол корабля увеличен!" + NewStr() + sCurrVal + stf(ms.WindAgainstSpeed);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Курсовой угол корабля достиг максимального значения!");
			Log_info(sCurrVal + stf(ms.WindAgainstSpeed));
			totalInfo += "Курсовой угол корабля достиг максимального значения!" + NewStr() + sCurrVal + stf(ms.WindAgainstSpeed);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F31", 1);
}

string descF32 = "Уменьшить курсовой угол на 0.1";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (stf(ms.WindAgainstSpeed) > 0.0)
		{
			ms.WindAgainstSpeed = stf(ms.WindAgainstSpeed) - 0.1;
			if (stf(ms.WindAgainstSpeed) < 0.0) { ms.WindAgainstSpeed = 0.0; }
			Log_info("Курсовой угол корабля уменьшен!");
			Log_info(sCurrVal + stf(ms.WindAgainstSpeed));
			totalInfo += "Курсовой угол корабля уменьшен!" + NewStr() + sCurrVal + stf(ms.WindAgainstSpeed);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Курсовой угол корабля достиг минимального значения!");
			Log_info(sCurrVal + stf(ms.WindAgainstSpeed));
			totalInfo += "Курсовой угол корабля достиг минимального значения!" + NewStr() + sCurrVal + stf(ms.WindAgainstSpeed);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F32", 1);
}

string descF33 = "Выставить курсовой угол по умолчанию";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.WindAgainstSpeed = stf(rBaseShip.WindAgainstSpeed);
		RemoveShipsUpgrade(3);
		Log_info("Курсовой угол корабля выставлен по умолчанию!");
		Log_info(sCurrVal + stf(rBaseShip.WindAgainstSpeed));
		totalInfo += "Курсовой угол корабля выставлен по умолчанию!" + NewStr() + sCurrVal + stf(rBaseShip.WindAgainstSpeed);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F33", 1);
}

string descF34 = "Повысить ватерлинию на 0.1";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.WaterLine = stf(ms.WaterLine) + 0.1;
		Log_info("Ватерлиния корабля увеличена! Визуально результат будет виден только после перезагрузки локации!");
		Log_info(sCurrVal + stf(ms.WaterLine));
		totalInfo += "Ватерлиния корабля увеличена!" + NewStr() + sCurrVal + stf(ms.WaterLine);
		totalInfo += "\n\nВизуально результат будет виден только после перезагрузки локации!";
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F34", 1);
}

string descF35 = "Понизить ватерлинию на 0.1";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		ms.WaterLine = stf(ms.WaterLine) - 0.1;
		Log_info("Ватерлиния корабля уменьшена! Визуально результат будет виден только после перезагрузки локации!");
		Log_info(sCurrVal + stf(ms.WaterLine));
		totalInfo += "Ватерлиния корабля уменьшена!" + NewStr() + sCurrVal + stf(ms.WaterLine);
		totalInfo += "\n\nВизуально результат будет виден только после перезагрузки локации!";
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F35", 1);
}

string descF36 = "Выставить значение ватерлинии по умолчанию";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.WaterLine = stf(rBaseShip.WaterLine);
		Log_info("Ватерлиния для корабля выставлена по умолчанию!");
		Log_info(sCurrVal + stf(rRealShip.WaterLine));
		totalInfo += "Ватерлиния для корабля выставлена по умолчанию!" + NewStr() + sCurrVal + stf(rRealShip.WaterLine);
		totalInfo += "\n\nВизуально результат будет виден только после перезагрузки локации!";
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F36", 1);
}

string descF37 = "Увеличить минимальную команду на 1";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) < 999)
		{
			ms.MinCrew = sti(ms.MinCrew) + 1;
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Минимальная команда для управления кораблем увеличена на 1!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем увеличена на 1!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Численность минимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F37", 1);
}

string descF38 = "Увеличить минимальную команду на 10";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) < 999)
		{
			ms.MinCrew = sti(ms.MinCrew) + 10;
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Минимальная команда для управления кораблем увеличена на 10!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем увеличена на 10!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Численность минимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F38", 1);
}

string descF39 = "Увеличить минимальную команду на 100";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) < 999)
		{
			ms.MinCrew = sti(ms.MinCrew) + 100;
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Минимальная команда для управления кораблем увеличена на 100!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем увеличена на 100!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) > 999) ms.MinCrew = 999;
			Log_info("Численность минимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F39", 1);
}

string descF40 = "Уменьшить минимальную команду на 1";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) > 1)
		{
			ms.MinCrew = sti(ms.MinCrew) - 1;
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Минимальная команда для управления кораблем уменьшена на 1!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем уменьшена на 1!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Численность минимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F40", 1);
}

string descF41 = "Уменьшить минимальную команду на 10";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) > 10)
		{
			ms.MinCrew = sti(ms.MinCrew) - 10;
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Минимальная команда для управления кораблем уменьшена на 10!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем уменьшена на 10!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Численность минимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F41", 1);
}

string descF42 = "Уменьшить минимальную команду на 100";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MinCrew) > 100)
		{
			ms.MinCrew = sti(ms.MinCrew) - 100;
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Минимальная команда для управления кораблем уменьшена на 100!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Минимальная команда для управления кораблем уменьшена на 100!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MinCrew) < 1) ms.MinCrew = 1;
			Log_info("Численность минимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMin + sti(ms.MinCrew));
			totalInfo += "Численность минимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMin + sti(ms.MinCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F42", 1);
}

string descF43 = "Выставить минимальную команду по умолчанию";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.MinCrew = sti(rBaseShip.MinCrew);
		Log_info("Минимальная команда корабля выставлена по умолчанию!");
		Log_info(sCurrVal + sti(rRealShip.MinCrew));
		totalInfo += "Минимальная команда корабля корабля выставлена по умолчанию!" + NewStr() + sCurrVal + sti(rRealShip.MinCrew);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F43", 1);
}

string descF44 = "Увеличить оптимальную команду на 1";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) < 7777)
		{
			ms.OptCrew = sti(ms.OptCrew) + 1;
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Оптимальная команда для управления кораблем увеличена на 1!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем увеличена на 1!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Численность оптимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F44", 1);
}

string descF45 = "Увеличить оптимальную команду на 10";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) < 7777)
		{
			ms.OptCrew = sti(ms.OptCrew) + 10;
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Оптимальная команда для управления кораблем увеличена на 10!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем увеличена на 10!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Численность оптимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F45", 1);
}

string descF46 = "Увеличить оптимальную команду на 100";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) < 7777)
		{
			ms.OptCrew = sti(ms.OptCrew) + 100;
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Оптимальная команда для управления кораблем увеличена на 100!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем увеличена на 100!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) > 7777) ms.OptCrew = 7777;
			Log_info("Численность оптимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F46", 1);
}

string descF47 = "Уменьшить оптимальную команду на 1";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) > 1)
		{
			ms.OptCrew = sti(ms.OptCrew) - 1;
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Оптимальная команда для управления кораблем уменьшена на 1!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем уменьшена на 1!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Численность оптимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F47", 1);
}

string descF48 = "Уменьшить оптимальную команду на 10";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) > 10)
		{
			ms.OptCrew = sti(ms.OptCrew) - 10;
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Оптимальная команда для управления кораблем уменьшена на 10!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем уменьшена на 10!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Численность оптимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F48", 1);
}

string descF49 = "Уменьшить оптимальную команду на 100";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.OptCrew) > 100)
		{
			ms.OptCrew = sti(ms.OptCrew) - 100;
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Оптимальная команда для управления кораблем уменьшена на 100!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Оптимальная команда для управления кораблем уменьшена на 100!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.OptCrew) < 1) ms.OptCrew = 1;
			Log_info("Численность оптимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewOpt + sti(ms.OptCrew));
			totalInfo += "Численность оптимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewOpt + sti(ms.OptCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F49", 1);
}

string descF50 = "Выставить оптимальную команду по умолчанию";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.OptCrew = sti(rBaseShip.OptCrew);
		Log_info("Оптимальная команда корабля выставлена по умолчанию!");
		Log_info(sCurrVal + sti(rRealShip.OptCrew));
		totalInfo += "Оптимальная команда корабля выставлена по умолчанию!" + NewStr() + sCurrVal + sti(rRealShip.OptCrew);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F50", 1);
}

string descF51 = "Увеличить максимальную команду на 1";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) < 9999)
		{
			ms.MaxCrew = sti(ms.MaxCrew) + 1;
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Максимальная команда для управления кораблем увеличена на 1!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем увеличена на 1!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Численность максимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F51", 1);
}

string descF52 = "Увеличить максимальную команду на 10";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) < 9999)
		{
			ms.MaxCrew = sti(ms.MaxCrew) + 10;
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Максимальная команда для управления кораблем увеличена на 10!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем увеличена на 10!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Численность максимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F52", 1);
}

string descF53 = "Увеличить максимальную команду на 100";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) < 9999)
		{
			ms.MaxCrew = sti(ms.MaxCrew) + 100;
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Максимальная команда для управления кораблем увеличена на 100!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем увеличена на 100!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) > 9999) ms.MaxCrew = 9999;
			Log_info("Численность максимальной команды корабля достигла предельно высокого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно высокого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F53", 1);
}

string descF54 = "Уменьшить максимальную команду на 1";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) > 1)
		{
			ms.MaxCrew = sti(ms.MaxCrew) - 1;
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Максимальная команда для управления кораблем уменьшена на 1!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем уменьшена на 1!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Численность максимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F54", 1);
}

string descF55 = "Уменьшить максимальную команду на 10";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) > 10)
		{
			ms.MaxCrew = sti(ms.MaxCrew) - 10;
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Максимальная команда для управления кораблем уменьшена на 10!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем уменьшена на 10!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Численность максимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F55", 1);
}

string descF56 = "Уменьшить максимальную команду на 100";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (sti(ms.MaxCrew) > 100)
		{
			ms.MaxCrew = sti(ms.MaxCrew) - 100;
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Максимальная команда для управления кораблем уменьшена на 100!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Максимальная команда для управления кораблем уменьшена на 100!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			if (sti(ms.MaxCrew) < 1) ms.MaxCrew = 1;
			Log_info("Численность максимальной команды корабля достигла предельно низкого значения!");
			Log_info(sCrewMax + sti(ms.MaxCrew));
			totalInfo += "Численность максимальной команды корабля достигла предельно низкого значения!" + NewStr() + sCrewMax + sti(ms.MaxCrew);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F56", 1);
}

string descF57 = "Выставить максимальную команду по умолчанию";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		iShipType = sti(pchar.ship.type);
		rRealShip = GetRealShip(iShipType);
		rBaseShip = GetShipByType(sti(rRealShip.BaseType));
		rRealShip.MaxCrew = sti(rBaseShip.MaxCrew);
		RemoveShipsUpgrade(5);
		Log_info("Максимальная команда корабля выставлена по умолчанию!");
		Log_info(sCurrVal + sti(rRealShip.MaxCrew));
		totalInfo += "Максимальная команда корабля выставлена по умолчанию!" + NewStr() + sCurrVal + sti(rRealShip.MaxCrew);
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F57", 1);
}

string descF58 = "Минимизировать численность команды на корабле";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (PChar.Ship.Crew.Quantity != ms.MinCrew)
		{
			PChar.Ship.Crew.Quantity = sti(ms.MinCrew);
			Log_info("Численность команды на корабле минимизирована!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды на корабле минимизирована!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Численность команды корабля предельно минимизирована!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды корабля предельно минимизирована!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		SeaDogsCrew(pchar);
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F58", 1);
}

string descF59 = "Оптимизировать численность команды на корабле";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (PChar.Ship.Crew.Quantity != ms.OptCrew)
		{
			PChar.Ship.Crew.Quantity = sti(ms.OptCrew);
			Log_info("Численность команды на корабле оптимизирована!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды на корабле оптимизирована!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Численность команды корабля максимально оптимизирована!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды корабля максимально оптимизирована!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		SeaDogsCrew(pchar);
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F59", 1);
}

string descF60 = "Максимизировать численность команды на корабле";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (PChar.Ship.Crew.Quantity != ms.MaxCrew)
		{
			PChar.Ship.Crew.Quantity = sti(ms.MaxCrew);
			Log_info("Численность команды на корабле максимизирована!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды на корабле максимизирована!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		}
		else
		{
			Log_info("Численность команды корабля максимально увеличена!");
			Log_info(sCrewNow + sti(PChar.Ship.Crew.Quantity));
			totalInfo += "Численность команды корабля максимально увеличена!" + NewStr() + sCrewNow + sti(PChar.Ship.Crew.Quantity);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		}
		SeaDogsCrew(pchar);
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F60", 1);
}

string descF61 = "Сменить тип каюты на корабле (9 вариантов)";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	int n;
	int iChangeModel = 0;
	string sC;
	string sLoot = "\nВещи из различных сундуков в каюте будут перенесены в единый.";
	string sModer = "\nАвтор(ы) мода: Orazio";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		ms = GetRealShip(sti(pchar.Ship.Type));
		if (!CheckAttribute(pchar, "CSM.ChangeShipsCabin")) { pchar.CSM.ChangeShipsCabin = 0; }
		switch (sti(pchar.CSM.ChangeShipsCabin))
		{
			case 0: ms.CabinType = "Cabin_Medium"; totalInfo += "Выбран 1-ый средний тип каюты! (2/9)" + sLoot; break;
			case 1: ms.CabinType = "Cabin_Medium2"; totalInfo += "Выбран 2-ой средний тип каюты! (3/9)" + sLoot; break;
			case 2: ms.CabinType = "Cabin"; totalInfo += "Выбран большой тип каюты! (4/9)" + sLoot; break;
			case 3: ms.CabinType = "Cabin_Huge"; totalInfo += "Выбран огромный тип каюты! (5/9)" + sLoot; break;
			case 4: ms.CabinType = "CabineFDM"; totalInfo += "Выбран проклятый тип каюты! (6/9)" + sLoot; break;
			case 5: ms.CabinType = "Cabin_Quest"; totalInfo += "Выбран просторный тип каюты! (7/9)" + sLoot; iChangeModel = 1; break;
			case 6: ms.CabinType = "Cabin_Quest"; totalInfo += "Выбран компактный тип каюты! (8/9)" + sModer + sLoot; iChangeModel = 2; break;
			case 7: ms.CabinType = "Cabin_Quest"; totalInfo += "Выбран элитный тип каюты! (9/9)" + sModer + sLoot; iChangeModel = 3; break;
			case 8: ms.CabinType = "Cabin_Small"; totalInfo += "Выбран малый тип каюты! (1/9)" + sLoot; break;
		}
		pchar.CSM.ChangeShipsCabin = sti(pchar.CSM.ChangeShipsCabin) + 1;
		if (sti(pchar.CSM.ChangeShipsCabin) > 8) pchar.CSM.ChangeShipsCabin = 0;
		//
		if (iChangeModel > 0)
		{
			n = FindLocation("My_Cabin_Quest");
			DeleteAttribute(&Locations[n], "models"); // трем прежнюю геометрию
			switch (iChangeModel)
			{
				case 1:
					Locations[n].filespath.models = "locations\decks\capquest\";
					// Always
					Locations[n].models.always.locators = "capquest_l";
					Locations[n].models.always.l1 = "capquest";
					locations[n].models.always.l1.level = 65538;
					Locations[n].models.always.window = "capquest_w";
					Locations[n].models.always.window.tech = "LocationWindows";
					locations[n].models.always.window.level = 65539;
					// Day
					Locations[n].models.day.charactersPatch = "capquest_pd";
					Locations[n].models.day.fonar = "capquest_fd";
					// Night
					Locations[n].models.night.charactersPatch = "capquest_pd";
					Locations[n].models.night.fonar = "capquest_fn";
				break;
				case 2:
					Locations[n].filespath.models = "locations\decks\newCabins\1\";
					// Always
					Locations[n].models.always.locators = "nc_cabin1_l";
					Locations[n].models.always.l1 = "nc_cabin1";
					// Day
					Locations[n].models.day.window = "nc_cabin1_wd";
					Locations[n].models.day.window.tech = "LocationWindows";
					Locations[n].models.day.window.level = 65531;
					Locations[n].models.day.charactersPatch = "nc_cabin1_p";
					Locations[n].models.day.fonar = "nc_cabin1_fd";
					// Night
					Locations[n].models.night.window = "nc_cabin1_wn";
					Locations[n].models.night.window.tech = "LocationWindows";
					Locations[n].models.night.window.level = 65533;
					Locations[n].models.night.charactersPatch = "nc_cabin1_p";
					Locations[n].models.night.fonar = "nc_cabin1_fn";
				break;
				case 3:
					Locations[n].filespath.models = "locations\decks\newCabins\2\";
					// Always
					Locations[n].models.always.locators = "nc_cabin2_l";
					Locations[n].models.always.l1 = "nc_cabin2";
					//Day
					Locations[n].models.day.window = "nc_cabin2_wd";
					Locations[n].models.day.window.tech = "LocationWindows";
					Locations[n].models.day.window.level = 65531;
					Locations[n].models.day.charactersPatch = "nc_cabin2_pd";
					Locations[n].models.day.fonar = "nc_cabin2_fd";
					//Night
					Locations[n].models.night.window = "nc_cabin2_wn";
					Locations[n].models.night.window.tech = "LocationWindows";
					Locations[n].models.night.window.level = 65533;
					Locations[n].models.night.charactersPatch = "nc_cabin2_pn";
					Locations[n].models.night.fonar = "nc_cabin2_fn";
				break;
			}
		}
		//
		iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		totalInfo += "\n\nСовет:\nХраните вещи в сундуках на орудийной палубе, там сортировка не нарушается сменой корабля или каюты.";
	}
	else
	{
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F61", 1);
}

string descF62 = "Освятить корабль";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	if (!CheckAttribute(pchar, "GenQuest.Shipshine"))
	{
		pchar.GenQuest.Shipshine = true;
		iSND = PlaySound("Voice\Russian\priest_bead.wav");
		totalInfo += "Корабль был освящен! Число матросов для найма в тавернах увеличилось вдвое!";
	}
	else
	{
		DeleteAttribute(Pchar, "GenQuest.Shipshine");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Освящение утратило свою силу...";
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F62", 1);
}

string descF63 = "Удалить \ добавить кораблю статус ''ворованный'' (влияет на его стоимость)";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	ref rMS = GetRealShip(sti(pchar.Ship.Type));
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		if (rMS.Stolen == true)
		{
			rMS.Stolen = false;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Корабль теперь не ''ворованный''!";
		}
		else
		{
			rMS.Stolen = true;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Корабль имеет статус ''ворованный''...";
		}
	}
	else
	{
		Log_info("А где же Ваш корабль, капитан?!");
		totalInfo += "А где же Ваш корабль, капитан?!";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F63", 1);
}

string descF64 = "Включить \ отключить выход из строя орудий на корабле Вашего персонажа";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoCannonsBoom"))
	{
		pchar.CSM.NoCannonsBoom = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Орудия на корабле Вашего персонажа не будут получать никаких повреждений!");
		totalInfo += "Орудия на корабле Вашего персонажа не будут получать никаких повреждений!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoCannonsBoom");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Орудия на корабле Вашего персонажа будут повреждаться при стрельбе и от попаданий по ним вражеских снарядов.");
		totalInfo += "Орудия на корабле Вашего персонажа будут повреждаться при стрельбе и от попаданий по ним вражеских снарядов.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F64", 1);
}

string descF65 = "Включить \ отключить возможность определения нациями своих флагманских кораблей";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	string sRefresh = "Изменение вступит в силу только после смены игровых суток.";
	if (!CheckAttribute(pchar, "CSM.NoCheckAndIdentifyShips"))
	{
		pchar.CSM.NoCheckAndIdentifyShips = true;
		iSND = PlaySound("_CheatSurfMenu_\Medic.wav");
		Log_info("Нации не будут опознавать свои флагманские корабли и трубить тревогу!");
		totalInfo += "Нации не будут опознавать свои флагманские корабли и трубить тревогу!" + NewStr() + sRefresh;
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoCheckAndIdentifyShips");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Нации опознают свои флагманские корабли и будут трубить тревогу.");
		totalInfo += "Нации опознают свои флагманские корабли и будут трубить тревогу." + NewStr() + sRefresh;
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F65", 1);
}

// by Sticksъ -->
string descF66 = "Изменить максимальный калибр орудий";
void CalculateInfoDataF66()
{
    totalInfo = "#66 " + descF66;
	CommonActions();
    string log;
	string sNext = "Следующим нажатием максимальный калибр будет равен ";
    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
    {
        ms = GetRealShip(sti(pchar.Ship.Type));
        if (ms.CannonsQuantityMin != 0) // если предусмотрена установка орудий
        {
            int totalUniqueCalibers = CANNON_TYPES_QUANTITY - 1; // чтоб не конфликтили 36 пушки и 36 кулеврины
            for (int i = 0; i < totalUniqueCalibers; i++)
            {
                if (Cannon[i].caliber == ms.MaxCaliber)
                {
                    if (i < totalUniqueCalibers - 1)
                    {
                        if (Cannon[i + 1].caliber == 48) // 48-х нет в товарах оригинальной игры, пушки-призраки
                            i++;

                        log = "Максимальный калибр орудий теперь равен " + Cannon[i + 1].caliber + " фунтам!";
                        Log_info(log);

                        if (i < totalUniqueCalibers - 2)
                        {
                            if (Cannon[i + 2].caliber == 48) // fix для 48х
                            {
                                if (i < totalUniqueCalibers - 3)
                                    totalInfo += NewStr() + log + NewStr() + sNext + Cannon[i + 3].caliber + " фунтам";
                                else
                                    totalInfo += NewStr() + log + NewStr() + sNext + Cannon[0].caliber + " фунтам";
                            }
                            else
                                totalInfo += NewStr() + log + NewStr() + sNext + Cannon[i + 2].caliber + " фунтам";
                        }
                        else
                            totalInfo += NewStr() + log + NewStr() + sNext + Cannon[0].caliber + " фунтам";

                        ms.MaxCaliber = Cannon[i + 1].caliber;
                        break;
                    }

                    // откатываемся обратно на начало списка
                    log = "Максимальный калибр орудий теперь равен " + Cannon[0].caliber + " фунтам!";
                    Log_info(log);
                    totalInfo += NewStr() + log + NewStr() + sNext + Cannon[1].caliber + " фунтам";
                    ms.MaxCaliber = Cannon[0].caliber;
                    break;
                }
            }

            iSND = PlaySound("_CheatSurfMenu_\Cannons.wav");
        }
        else
        {
            Log_info("Установка орудий не предусмотрена на такую лохань!");
            totalInfo += "Установка орудий не предусмотрена на такую лохань!";
            iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
        }
		totalInfo += NewStr() + "Автор: Sticksъ";
    }
    else
    {
        totalInfo += sNoShip;
        iSND = PlaySound("_CheatSurfMenu_\Default.wav");
    }
    totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM4.F66", 1);
}

string descF67 = "Увеличить количество орудийных портов до максимума";
void CalculateInfoDataF67()
{
    totalInfo = "#67 " + descF67;
	CommonActions();
    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
    {
        ms = GetRealShip(sti(pchar.Ship.Type));
		if (!CheckAttribute(ms, "QuestShip"))
		{
			if (ms.CannonsQuantityMin != 0) // если предусмотрена установка орудий
			{
				aref refShip;
				makearef(refShip, pchar.Ship);

				string attr;
				int i;
				for (i = 0; i < sti(ms.cannonr); i++)
				{
					attr = "c" + i;
					if (i < (sti(ms.cannonr)))
					{
						if (stf(refShip.Cannons.Borts.cannonr.damages.(attr)) > 1.0)
						{
							refShip.Cannons.Borts.cannonr.damages.(attr) = 1.0;
						}
					}
				}
				for (i = 0; i < sti(ms.cannonl); i++)
				{
					attr = "c" + i;
					if (i < (sti(ms.cannonl)))
					{
						if (stf(refShip.Cannons.Borts.cannonl.damages.(attr)) > 1.0)
						{
							refShip.Cannons.Borts.cannonl.damages.(attr) = 1.0;
						}
					}
				}

				if (CheckAttribute(ms, "CannonsQuantityMax"))
					ms.Cannons = sti(ms.CannonsQuantityMax);
				else
					ms.Cannons = sti(ms.CannonsQuantity);

				ms.CannonsQuantity = sti(ms.Cannons);
				refShip.Cannons = sti(ms.Cannons);
				// нужна ль метка отбермудки сего пункта?

				Log_info("Количество орудийных портов на судне максимальное!");
				totalInfo += NewStr() + "Количество орудийных портов на судне максимальное!";

				iSND = PlaySound("_CheatSurfMenu_\Cannons.wav");
			}
			else
			{
				Log_info("Установка орудий не предусмотрена на такую лохань!");
				totalInfo += NewStr() + "Установка орудий не предусмотрена на такую лохань!";
				iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			}
		}
		else
		{
			Log_info("Уникальные корабли изначально имеют максимальное кол-во орудийных портов!");
			totalInfo += "Уникальные корабли изначально имеют максимальное кол-во орудийных портов!";
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
		totalInfo += NewStr() + "Автор: Sticksъ";
    }
    else
    {
        totalInfo += sNoShip;
        iSND = PlaySound("_CheatSurfMenu_\Default.wav");
    }
    totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM4.F67", 1);
}

string descF68 = "Перекрасить корпус корабля";
void CalculateInfoDataF68()
{
    totalInfo = "#68 " + descF68;
	CommonActions();
	int colors = 1;
	string sShipName = "";

    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
    {
        ms = GetRealShip(sti(pchar.Ship.Type));
		sShipName = ms.name;
        colors = ms.ship.upgrades.hull;
        colors++;

		// Cheatsurfer --> По сути, только у корвета действительно 4 разные шкурки, но тем не менее
		if (sShipName == "Corvette1" || HasSubStr(sShipName, "Luggerr"))
		{
			if (colors > 4)
				colors = 1;
		}
		else
		{
			if (sShipName == "Essex1")
			{
				if (colors > 2)
				{
					colors = 1;
					totalInfo += "У корабля " + pchar.ship.name + " только два варианта окраски корпуса!\n\n";
				}
			}
			else
			{
				if (colors > 3)
					colors = 1;
			}
		}

        ms.ship.upgrades.hull = colors;

        Log_info("Корпус корабля перекрашен! (Вариант hull" + colors + ")");
        totalInfo += "Корпус корабля перекрашен! (Вариант hull" + colors + ")";

        iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		totalInfo += "\nАвтор: Sticksъ";
    }
    else
    {
        totalInfo += sNoShip;
        iSND = PlaySound("_CheatSurfMenu_\Default.wav");
    }
    totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM4.F68", 1);
}

string descF69 = "Выбрать текстуру парусов (53 варианта)";
void CalculateInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	CommonActions();

	int index = 0;
	int maxSailsCount = 53;
	string sSailTex = "";

    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
    {
        ms = GetRealShip(sti(pchar.Ship.Type));

		if (!CheckAttribute(ms, "CM_sailsIndex"))
		{
			ms.CM_sailsIndex = 0;
		}

		index = ms.CM_sailsIndex;
		index++;

		if (index > maxSailsCount) // если все, то откатываемся на то, что было до читов
		{
			index = 0;
			DeleteAttribute(ms, "CM_sailsIndex");

			RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails = ms.ship.upgrades.sails;
			DeleteAttribute(ms, "EmblemedSails.normalTex");

			Log_info("На судно ГГ установлена исходная текстура паруса.");
			totalInfo += NewStr() + "На судно ГГ установлена исходная текстура паруса.";
		}
		else
		{
			sSailTex = "Ships\AdvancedSails_CM\sails_" + index + ".tga";
			SetShipSailsFromFile(pchar, sSailTex);
			SetNewPicture("CSMPICTURE", sSailTex);

			Log_info("На судно ГГ установлена новая текстура паруса: " + sSailTex);
			totalInfo += NewStr() + "На судно ГГ установлена новая текстура паруса: " + sSailTex + NewStr() + "Чтобы вернуть возможность перекрашиваться на верфях, следует дощелкать до ''исходной текстуры''.";

			ms.CM_sailsIndex = index;
		}
        iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		totalInfo += NewStr() + "Автор: Sticksъ";
    }
    else
    {
        totalInfo += sNoShip;
        iSND = PlaySound("_CheatSurfMenu_\Default.wav");
    }
    totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F69", 1);
}

string descF70 = "Выбрать текстуру герба";
void CalculateInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	CommonActions();

	int maxGeraldsCount = 71; // 30 гербов позаимствовано у тов. Nordik (с http://corsairs-harbour.ru)
	int index = 0;
	string sGerTex = "";

	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
    {
		ms = GetRealShip(sti(pchar.Ship.Type));

		if (!CheckAttribute(ms, "CM_geraldIndex"))
		{
			ms.CM_geraldIndex = 0;
			ms.ShipSails.oldGeraldName = ms.ShipSails.Gerald_Name;
		}

		index = ms.CM_geraldIndex;
		index++;

		if (index > maxGeraldsCount) // если все, то откатываемся на то, что было до читов
		{
			index = 0;
			DeleteAttribute(ms, "CM_geraldIndex");

			ms.ShipSails.Gerald_Name = ms.ShipSails.oldGeraldName;
			DeleteAttribute(ms, "ShipSails.oldGeraldName");

			Log_info("На судно ГГ установлен исходный герб.");
			totalInfo += NewStr() + "На судно ГГ установлен исходный герб.";
		}
		else
		{
			ms.ShipSails.gerald_name = "gr_" + index;
			sGerTex = "Ships\Gerald\gr_" + index + ".tga";
			SetNewPicture("CSMPICTURE", sGerTex);

			Log_info("На судно ГГ установлена новая текстура герба: " + sGerTex);
			totalInfo += NewStr() + "На судно ГГ установлена новая текстура герба: " + sGerTex;

			totalInfo += NewStr() + "Если у некоторых гербов нет изображения - значит это свободные слоты, можно по подобию туда добавить свои текстуры.";

			ms.CM_geraldIndex = index;
		}

        iSND = PlaySound("_CheatSurfMenu_\Repair.wav");
		totalInfo += NewStr() + "Автор: Sticksъ" + NewStr() + "Автор текстур: Nordik";
    }
    else
    {
        totalInfo += sNoShip;
        iSND = PlaySound("_CheatSurfMenu_\Default.wav");
    }
    totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM4.F70", 1);
}
// by Sticksъ <--

void SeaDogsCrew(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;
	AddCrewMorale(rChar, 100);
	ChangeCrewExp(rChar, "Sailors", 100);
	ChangeCrewExp(rChar, "Cannoners", 100);
	ChangeCrewExp(rChar, "Soldiers", 100);
}

void RemoveShipsUpgrade(int iType)
{
	ref rShip;
	rShip = &RealShips[sti(Pchar.Ship.Type)];
	if (iType < 0) iType = 0;
	if (iType > 7) iType = 7;
	switch (iType)
	{
		case 0: DeleteAttribute(rShip, "Tuning.HP"); break;
		case 1: DeleteAttribute(rShip, "Tuning.SpeedRate"); break;
		case 2: DeleteAttribute(rShip, "Tuning.TurnRate"); break;
		case 3: DeleteAttribute(rShip, "Tuning.WindAgainst"); break;
		case 4: DeleteAttribute(rShip, "Tuning.Capacity"); break;
		case 5: DeleteAttribute(rShip, "Tuning.MaxCrew"); break;
		case 6: DeleteAttribute(rShip, "Tuning.MinCrew"); break;
		case 7: DeleteAttribute(rShip, "Tuning.Cannon"); break;
	}
}

void RefreshShipsCannonsCond(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;
	ref rShip;
	int i;
	string attr;
	if (sti(rChar.Ship.Type) != SHIP_NOTUSED)
	{
		rShip = &RealShips[sti(rChar.Ship.Type)];
		if (GetCannonsNum(rChar) > 0)
		{
			if (sti(rShip.cannonr) > 0)
			{
				for (i = 0; i < sti(rShip.cannonr); i++)
				{
					attr = "c" + i;
					if (rChar.ship.Cannons.Borts.cannonr.damages.(attr) > 0.0) rChar.ship.Cannons.Borts.cannonr.damages.(attr) = 0.0;
				}
			}
			if (sti(rShip.cannonl) > 0)
			{
				for (i = 0; i < sti(rShip.cannonl); i++)
				{
					attr = "c" + i;
					if (rChar.ship.Cannons.Borts.cannonl.damages.(attr) > 0.0) rChar.ship.Cannons.Borts.cannonl.damages.(attr) = 0.0;
				}
			}
			if (sti(rShip.cannonf) > 0)
			{
				for (i = 0; i < sti(rShip.cannonf); i++)
				{
					attr = "c" + i;
					if (rChar.ship.Cannons.Borts.cannonf.damages.(attr) > 0.0) rChar.ship.Cannons.Borts.cannonf.damages.(attr) = 0.0;
				}
			}
			if (sti(rShip.cannonb) > 0)
			{
				for (i = 0; i < sti(rShip.cannonb); i++)
				{
					attr = "c" + i;
					if (rChar.ship.Cannons.Borts.cannonb.damages.(attr) > 0.0) rChar.ship.Cannons.Borts.cannonb.damages.(attr) = 0.0;
				}
			}
		}
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
			sHeader = "Описание меню ''Корабль''";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке ''Корабль'' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню ''Корабль''";
			sText1 = "Перезапуск меню ''Корабль''";
		break;
		case "B_M1":
			sHeader = "Меню ''Персонаж''";
			sText1 = "Запуск меню ''Персонаж''";
		break;
		case "B_M2":
			sHeader = "Меню ''Умения''";
			sText1 = "Запуск меню ''Умения''";
		break;
		case "B_M3":
			sHeader = "Меню ''Предметы''";
			sText1 = "Запуск меню ''Предметы''";
		break;
		case "B_M4":
			sHeader = "Меню ''Локации''";
			sText1 = "Запуск меню ''Локации''";
		break;
		case "B_M5":
			sHeader = "Меню ''Товары''";
			sText1 = "Запуск меню ''Товары''";
		break;
		case "B_M6":
			sHeader = "Меню ''Офицеры''";
			sText1 = "Запуск меню ''Офицеры''";
		break;
		case "B_M7":
			sHeader = "Меню ''Корабли''";
			sText1 = "Запуск меню 'Корабли'";
		break;
		case "B_M8":
			sHeader = "Меню ''Прочее''";
			sText1 = "Запуск меню ''Прочее''";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
