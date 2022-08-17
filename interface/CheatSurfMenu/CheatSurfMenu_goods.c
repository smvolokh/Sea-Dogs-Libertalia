
/*
	CheatSurfMenu by Cheatsurfer	
	Корабельные товары
	Основано на меню дебаггера от boal
	09.07.19  //  Пират Либерталии
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Товары' вверху, чтобы вновь отобразить описание перечня команд данного меню ***";

string sAdded = "В трюм корабля добавлено 100 единиц ";
string sCannon = "В трюм корабля добавлено 10 ";
string sTotal = "Кол-во данного товара в трюме: ";
string sFull = "Капитан, в трюме нет свободного места!";
string sNoShip = "А где же Ваш корабль, капитан?!";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_goods";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(5); // Warship. Статистика - сколько читов юзали
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
		totalInfo = csmMenuText(1) +
					"\nДобавляемые товары требуют определенное наличие свободного места в трюме корабля героя!\n\n" +
					"********** ДОБАВИТЬ В ТРЮМ КОРАБЛЯ **********" + NewStr() +
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "\n\n< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() +
					"< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() +
					"< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() +
					"< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "\n\n< 36 > " + descF36 + NewStr() +
					"< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() +
					"< 43 > " + descF43 + NewStr() + "< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() + "< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() + "< 52 > " + descF52 + NewStr() + "\n\n< 53 > " + descF53 + NewStr() + "< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + NewStr() + 
					"< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() + "< 58 > " + descF58 + NewStr() +
					"< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() + "< 61 > " + descF61 + NewStr() + "< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() + "\n\n ********** ИЗМЕНИТЬ РАЗМЕР СКЛАДОВ **********" + NewStr() + "< 65 > " + descF65 + NewStr() +
					"\n\n ********** ПРОЧЕЕ **********" + NewStr() + "< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() + "< 68 > " + descF68 + NewStr() +
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(5); // Статистика по читам
}

string descF1 = "100 единиц ядер";
void CalculateInfoDataF1()
{
	totalInfo = "#1 Добавить " + descF1;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_BALLS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_BALLS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "ядер!");
			totalInfo += sAdded + "ядер!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_BALLS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F1", 1);
}

string descF2 = "100 единиц картечи";
void CalculateInfoDataF2()
{
	totalInfo = "#2 Добавить " + descF2;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_GRAPES].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_GRAPES, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "картечи!");
			totalInfo += sAdded + "картечи!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_GRAPES));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F2", 1);
}

string descF3 = "100 единиц книппелей";
void CalculateInfoDataF3()
{
	totalInfo = "#3 Добавить " + descF3;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_KNIPPELS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_KNIPPELS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "книппелей!");
			totalInfo += sAdded + "книппелей!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_KNIPPELS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F3", 1);
}

string descF4 = "100 единиц бомб";
void CalculateInfoDataF4()
{
	totalInfo = "#4 Добавить " + descF4;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_BOMBS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_BOMBS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "бобм!");
			totalInfo += sAdded + "бомб!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_BOMBS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F4", 1);
}

string descF5 = "100 единиц пороха";
void CalculateInfoDataF5()
{
	totalInfo = "#5 Добавить " + descF5;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_POWDER].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_POWDER, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "пороха!");
			totalInfo += sAdded + "пороха!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_POWDER));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F5", 1);
}

string descF6 = "100 единиц провианта";
void CalculateInfoDataF6()
{
	totalInfo = "#6 Добавить " + descF6;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_FOOD].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_FOOD, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "провианта!");
			totalInfo += sAdded + "провианта!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_FOOD));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F6", 1);
}

string descF7 = "100 единиц оружия";
void CalculateInfoDataF7()
{
	totalInfo = "#7 Добавить " + descF7;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_WEAPON].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_WEAPON, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "оружия!");
			totalInfo += sAdded + "оружия!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_WEAPON));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F7", 1);
}

string descF8 = "100 единиц лекарств";
void CalculateInfoDataF8()
{
	totalInfo = "#8 Добавить " + descF8;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_MEDICAMENT].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_MEDICAMENT, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "лекарств!");
			totalInfo += sAdded + "лекарств!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_MEDICAMENT));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F8", 1);
}

string descF9 = "100 единиц рома";
void CalculateInfoDataF9()
{
	totalInfo = "#9 Добавить " + descF9;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_RUM].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_RUM, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "рома!");
			totalInfo += sAdded + "рома!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_RUM));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F9", 1);
}

string descF10 = "100 единиц парусины";
void CalculateInfoDataF10()
{
	totalInfo = "#10 Добавить " + descF10;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SAILCLOTH].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SAILCLOTH, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "парусины!");
			totalInfo += sAdded + "парусины!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SAILCLOTH));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F10", 1);
}

string descF11 = "100 единиц досок";
void CalculateInfoDataF11()
{
	totalInfo = "#11 Добавить " + descF11;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_PLANKS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_PLANKS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "досок!");
			totalInfo += sAdded + "досок!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_PLANKS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F11", 1);
}

string descF12 = "100 единиц корабельного шелка";
void CalculateInfoDataF12()
{
	totalInfo = "#12 Добавить " + descF12;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SHIPSILK].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SHIPSILK, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "корабельного шелка!");
			totalInfo += sAdded + "корабельного шелка!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SHIPSILK));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F12", 1);
}

string descF13 = "100 единиц каната";
void CalculateInfoDataF13()
{
	totalInfo = "#13 Добавить " + descF13;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_ROPES].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_ROPES, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "каната!");
			totalInfo += sAdded + "каната!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_ROPES));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F13", 1);
}

string descF14 = "100 единиц бакаута";
void CalculateInfoDataF14()
{
	totalInfo = "#14 Добавить " + descF14;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SANDAL].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SANDAL, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "бакаута!");
			totalInfo += sAdded + "бакаута!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SANDAL));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F14", 1);
}

string descF15 = "100 единиц смол";
void CalculateInfoDataF15()
{
	totalInfo = "#15 Добавить " + descF15;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_OIL].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_OIL, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "смол!");
			totalInfo += sAdded + "смол!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_OIL));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F15", 1);
}

string descF16 = "100 единиц эля";
void CalculateInfoDataF16()
{
	totalInfo = "#16 Добавить " + descF16;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_ALE].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_ALE, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "эля!");
			totalInfo += sAdded + "эля!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_ALE));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F16", 1);
}

string descF17 = "100 единиц пшеницы";
void CalculateInfoDataF17()
{
	totalInfo = "#17 Добавить " + descF17;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_WHEAT].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_WHEAT, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "пшеницы!");
			totalInfo += sAdded + "пшеницы!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_WHEAT));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F17", 1);
}

string descF18 = "100 единиц одежды";
void CalculateInfoDataF18()
{
	totalInfo = "#18 Добавить " + descF18;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CLOTHES].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CLOTHES, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "одежды!");
			totalInfo += sAdded + "одежды!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CLOTHES));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F18", 1);
}

string descF19 = "100 единиц фруктов";
void CalculateInfoDataF19()
{
	totalInfo = "#19 Добавить " + descF19;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_FRUITS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_FRUITS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "фруктов!");
			totalInfo += sAdded + "фруктов!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_FRUITS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F19", 1);
}

string descF20 = "100 единиц кофе";
void CalculateInfoDataF20()
{
	totalInfo = "#20 Добавить " + descF20;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_COFFEE].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_COFFEE, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "кофе!");
			totalInfo += sAdded + "кофе!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_COFFEE));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F20", 1);
}

string descF21 = "100 единиц какао";
void CalculateInfoDataF21()
{
	totalInfo = "#21 Добавить " + descF21;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CHOCOLATE].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "какао!");
			totalInfo += sAdded + "какао!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CHOCOLATE));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F21", 1);
}

string descF22 = "100 единиц табака";
void CalculateInfoDataF22()
{
	totalInfo = "#22 Добавить " + descF22;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_TOBACCO].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_TOBACCO, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "табака!");
			totalInfo += sAdded + "табака!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_TOBACCO));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F22", 1);
}

string descF23 = "100 единиц сахара";
void CalculateInfoDataF23()
{
	totalInfo = "#23 Добавить " + descF23;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SUGAR].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SUGAR, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "сахара!");
			totalInfo += sAdded + "сахара!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SUGAR));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F23", 1);
}

string descF24 = "100 единиц хлопка";
void CalculateInfoDataF24()
{
	totalInfo = "#24 Добавить " + descF24;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_COTTON].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_COTTON, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "хлопка!");
			totalInfo += sAdded + "хлопка!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_COTTON));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F24", 1);
}

string descF25 = "100 единиц кожи";
void CalculateInfoDataF25()
{
	totalInfo = "#25 Добавить " + descF25;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_LEATHER].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_LEATHER, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "кожи!");
			totalInfo += sAdded + "кожи!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_LEATHER));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F25", 1);
}

string descF26 = "100 единиц чёрного дерева";
void CalculateInfoDataF26()
{
	totalInfo = "#26 Добавить " + descF26;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_EBONY].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_EBONY, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "чёрного дерева!");
			totalInfo += sAdded + "чёрного дерева!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_EBONY));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F26", 1);
}

string descF27 = "100 единиц красного дерева";
void CalculateInfoDataF27()
{
	totalInfo = "#27 Добавить " + descF27;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_MAHOGANY].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_MAHOGANY, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "красного дерева!");
			totalInfo += sAdded + "красного дерева!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_MAHOGANY));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F27", 1);
}

string descF28 = "100 единиц ванили";
void CalculateInfoDataF28()
{
	totalInfo = "#28 Добавить " + descF28;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CINNAMON].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CINNAMON, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "ванили!");
			totalInfo += sAdded + "ванили!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CINNAMON));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F28", 1);
}

string descF29 = "100 единиц копры";
void CalculateInfoDataF29()
{
	totalInfo = "#29 Добавить " + descF29;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_COPRA].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_COPRA, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "копры!");
			totalInfo += sAdded + "копры!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_COPRA));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F29", 1);
}

string descF30 = "100 единиц паприки";
void CalculateInfoDataF30()
{
	totalInfo = "#30 Добавить " + descF30;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_PAPRIKA].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_PAPRIKA, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "паприки!");
			totalInfo += sAdded + "паприки!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_PAPRIKA));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F30", 1);
}

string descF31 = "100 единиц вина";
void CalculateInfoDataF31()
{
	totalInfo = "#31 Добавить " + descF31;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_WINE].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_WINE, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "вина!");
			totalInfo += sAdded + "вина!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_WINE));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F31", 1);
}

string descF32 = "100 единиц кирпича";
void CalculateInfoDataF32()
{
	totalInfo = "#32 Добавить " + descF32;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_BRICK].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_BRICK, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "кирпича!");
			totalInfo += sAdded + "кирпича!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_BRICK));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F32", 1);
}

string descF33 = "100 единиц рабов";
void CalculateInfoDataF33()
{
	totalInfo = "#33 Добавить " + descF33;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SLAVES].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SLAVES, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "рабов!");
			totalInfo += sAdded + "рабов!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SLAVES));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F33", 1);
}

string descF34 = "100 единиц золота";
void CalculateInfoDataF34()
{
	totalInfo = "#34 Добавить " + descF34;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_GOLD].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_GOLD, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "золота!");
			totalInfo += sAdded + "золота!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_GOLD));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F34", 1);
}

string descF35 = "100 единиц серебра";
void CalculateInfoDataF35()
{
	totalInfo = "#35 Добавить " + descF35;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SILVER].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SILVER, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "серебра!");
			totalInfo += sAdded + "серебра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SILVER));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F35", 1);
}

string descF36 = "100 единиц лесоматериалов";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_TIMBERS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_TIMBERS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "лесоматериалов!");
			totalInfo += sAdded + "лесоматериалов!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_TIMBERS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F36", 1);
}

string descF37 = "100 единиц масел";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_PITCH].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_PITCH, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "масел!");
			totalInfo += sAdded + "масел!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_PITCH));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F37", 1);
}

string descF38 = "100 единиц чая";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_TEA].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_TEA, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "чая!");
			totalInfo += sAdded + "чая!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_TEA));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F38", 1);
}

string descF39 = "100 единиц керамики";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_POTTERY].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_POTTERY, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "керамики!");
			totalInfo += sAdded + "керамики!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_POTTERY));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F39", 1);
}

string descF40 = "100 единиц слоновой кости";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_IVORY].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_IVORY, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "слоновой кости!");
			totalInfo += sAdded + "слоновой кости!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_IVORY));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F40", 1);
}

string descF41 = "100 единиц инструментов";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_TOOLS].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_TOOLS, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "инструментов!");
			totalInfo += sAdded + "инструментов!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_TOOLS));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F41", 1);
}

string descF42 = "100 единиц красителей";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_DYES].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_DYES, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "красителей!");
			totalInfo += sAdded + "красителей!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_DYES));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F42", 1);
}

string descF43 = "100 единиц овощей";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_vegetables].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_vegetables, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "овощей!");
			totalInfo += sAdded + "овощей!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_vegetables));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F43", 1);
}

string descF44 = "100 единиц пеньки";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_HEMP].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_HEMP, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "пеньки!");
			totalInfo += sAdded + "пеньки!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_HEMP));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F44", 1);
}

string descF45 = "100 единиц бумаги";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_PAPER].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_PAPER, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "бумаги!");
			totalInfo += sAdded + "бумаги!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_PAPER));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F45", 1);
}

string descF46 = "100 единиц мыла";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SOAP].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SOAP, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "мыла!");
			totalInfo += sAdded + "мыла!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SOAP));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F46", 1);
}

string descF47 = "100 единиц меди";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_Copper].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_Copper, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "меди!");
			totalInfo += sAdded + "меди!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_Copper));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F47", 1);
}

string descF48 = "100 единиц железа";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_Iron].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_Iron, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "железа!");
			totalInfo += sAdded + "железа!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_Iron));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F48", 1);
}

string descF49 = "100 единиц соли";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_Salt].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_Salt, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "соли!");
			totalInfo += sAdded + "соли!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_Salt));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F49", 1);
}

string descF50 = "100 единиц рыбы";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_Fish].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_Fish, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "рыбы!");
			totalInfo += sAdded + "рыбы!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_Fish));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F50", 1);
}

string descF51 = "100 единиц шелка";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_SILK].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_SILK, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "шелка!");
			totalInfo += sAdded + "шелка!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_SILK));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F51", 1);
}

string descF52 = "100 единиц уксуса";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_Vinegar].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_Vinegar, 100);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sAdded + "уксуса!");
			totalInfo += sAdded + "уксуса!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_Vinegar));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F52", 1);
}

string descF53 = "10 пушек 3-го калибра";
void CalculateInfoDataF53()
{
	totalInfo = "#53 Добавить " + descF53;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_3].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_3, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 3-го калибра!");
			totalInfo += sCannon + "пушек 3-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_3));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F53", 1);
}

string descF54 = "10 пушек 6-го калибра";
void CalculateInfoDataF54()
{
	totalInfo = "#54 Добавить " + descF54;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_6].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_6, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 6-го калибра!");
			totalInfo += sCannon + "пушек 6-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_6));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F54", 1);
}

string descF55 = "10 пушек 12-го калибра";
void CalculateInfoDataF55()
{
	totalInfo = "#55 Добавить " + descF55;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_12].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_12, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 12-го калибра!");
			totalInfo += sCannon + "пушек 12-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_12));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F55", 1);
}

string descF56 = "10 пушек 16-го калибра";
void CalculateInfoDataF56()
{
	totalInfo = "#56 Добавить " + descF56;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_16].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_16, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 16-го калибра!");
			totalInfo += sCannon + "пушек 16-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_16));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F56", 1);
}

string descF57 = "10 пушек 20-го калибра";
void CalculateInfoDataF57()
{
	totalInfo = "#57 Добавить " + descF57;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_20].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_20, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 20-го калибра!");
			totalInfo += sCannon + "пушек 20-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_20));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F57", 1);
}

string descF58 = "10 пушек 24-го калибра";
void CalculateInfoDataF58()
{
	totalInfo = "#58 Добавить " + descF58;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_24].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_24, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 24-го калибра!");
			totalInfo += sCannon + "пушек 24-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_24));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F58", 1);
}

string descF59 = "10 пушек 32-го калибра";
void CalculateInfoDataF59()
{
	totalInfo = "#59 Добавить " + descF59;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_32].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_32, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 32-го калибра!");
			totalInfo += sCannon + "пушек 32-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_32));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F59", 1);
}

string descF60 = "10 пушек 36-го калибра";
void CalculateInfoDataF60()
{
	totalInfo = "#60 Добавить " + descF60;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_36].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_36, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 36-го калибра!");
			totalInfo += sCannon + "пушек 36-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_36));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F60", 1);
}

string descF61 = "10 пушек 42-го калибра";
void CalculateInfoDataF61()
{
	totalInfo = "#61 Добавить " + descF61;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CANNON_42].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CANNON_42, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "пушек 42-го калибра!");
			totalInfo += sCannon + "пушек 42-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CANNON_42));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F61", 1);
}

string descF62 = "10 кулеврин 8-го калибра";
void CalculateInfoDataF62()
{
	totalInfo = "#62 Добавить " + descF62;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CULVERINE_8].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CULVERINE_8, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "кулеврин 8-го калибра!");
			totalInfo += sCannon + "кулеврин 8-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CULVERINE_8));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F62", 1);
}

string descF63 = "10 кулеврин 18-го калибра";
void CalculateInfoDataF63()
{
	totalInfo = "#63 Добавить " + descF63;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CULVERINE_18].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CULVERINE_18, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "кулеврин 18-го калибра!");
			totalInfo += sCannon + "кулеврин 18-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CULVERINE_18));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F63", 1);
}

string descF64 = "10 кулеврин 36-го калибра";
void CalculateInfoDataF64()
{
	totalInfo = "#64 Добавить " + descF64;
	CommonActions();
	float fFS;
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		fFS = stf(Goods[GOOD_CULVERINE_36].Weight);
		if (GetCargoFreeSpace(pchar) >= fFS)
		{
			AddCharacterGoods(Pchar, GOOD_CULVERINE_36, 10);
			iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
			Log_info(sCannon + "кулеврин 36-го калибра!");
			totalInfo += sCannon + "кулеврин 36-го калибра!" + NewStr() + sTotal + sti(GetCargoGoods(pchar, GOOD_CULVERINE_36));
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += sFull;
		}
	}
	else
	{
		Log_info(sNoShip);
		totalInfo += sNoShip;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F64", 1);
}

string descF65 = "Изменить размер складов";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();

	if (!CheckAttribute(pchar, "CSM.StorageCapacity"))
	{
		pchar.CSM.StorageCapacity = true;
		totalInfo += "Вместимость складов увеличена до 999.999!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.StorageCapacity");
		totalInfo += "Вместимость складов выставлена по-умолчанию в 50.000\nЕсли товаров оказалось больше этого значения, то их можно будет только забирать.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM6.F65", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM6.F66", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM6.F67", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM6.F68", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM6.F69", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM6.F70", 1);
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
			sHeader = "Описание меню 'Товары'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Товары' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Товары'";
			sText1 = "Перезапуск меню 'Товары'";
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
			sHeader = "Меню 'Прочее'";
			sText1 = "Запуск меню 'Прочее'";
		break;
		case "B_M7":
			sHeader = "Меню 'Офицеры'";
			sText1 = "Запуск меню 'Офицеры'";
		break;
		case "B_M8":
			sHeader = "Меню 'Корабли'";
			sText1 = "Запуск меню 'Корабли'";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
