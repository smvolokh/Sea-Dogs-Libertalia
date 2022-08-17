
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Локации
	Основано на меню дебаггера от boal
*/

int iSND = 0;
bool bExit = true;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Локации' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sTaboo = "\n\nВ данный момент этого нельзя делать!";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_towns";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(4); // Warship. Статистика - сколько читов юзали
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
	if (!CheckAttribute(pchar, "reload_edit.str")) pchar.reload_edit.str = "Пример ручного тп: FortFrance_town, reload, reload1";
	GameInterface.reload_edit.str = pchar.reload_edit.str;
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
		totalInfo = "\n" + csmMenuText(1) + "\n\n" +
					"********** ТЕЛЕПОРТ В АНГЛИЙСКУЮ КОЛОНИЮ **********" + NewStr() +
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() +
					"\n\n********** ТЕЛЕПОРТ В ГОЛЛАНДСКУЮ КОЛОНИЮ **********"	+ NewStr() +
					"<  6 > " + descF6 + NewStr() + "<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "\n\n********** ТЕЛЕПОРТ В ИСПАНСКУЮ КОЛОНИЮ **********" + NewStr() + "<  9 > " + descF9 + NewStr() + "< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() + "< 13 > " + descF13 + NewStr() +
					"< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() + "< 16 > " + descF16 + NewStr() +
					"< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() + "< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "\n\n********** ТЕЛЕПОРТ ВО ФРАНЦУЗСКУЮ КОЛОНИЮ **********" + NewStr() + "< 21 > " + descF21 + NewStr() + "< 22 > " + descF22 + NewStr() +
					"< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() + "< 25 > " + descF25 + NewStr() + "\n\n********** ТЕЛЕПОРТ В ПИРАТСКУЮ КОЛОНИЮ **********" + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() + "< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() + "< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() + "< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "\n\n********** ТЕЛЕПОРТ НА ВАЖНЫЕ МАЯКИ **********" + NewStr() + "< 36 > " + descF36 + NewStr() + "< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() + "< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "\n\n********** ТЕЛЕПОРТ НА НЕОБИТАЕМЫЙ ОСТРОВ **********" + NewStr() + "< 42 > " + descF42 + NewStr() + "< 43 > " + descF43 + NewStr() + "\n\n********** ТЕЛЕПОРТ В БУХТУ **********" + NewStr() + "Случайная бухта у английского поселения" + NewStr() +
					"-------------------------------------------------------" + NewStr() +
					"< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() + "< 46 > " + descF46 + NewStr() +
					"< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() +
					"\n\nСлучайная бухта у голландского поселения" + NewStr() +
					"---------------------------------------------------------" + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() +
					"\n\nСлучайная бухта у испанского поселения" + NewStr() +
					"------------------------------------------------------" + NewStr() +
					"< 51 > " + descF51 + NewStr() + "< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() +
					"< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + NewStr() +
					"< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() + "< 58 > " + descF58 + NewStr() +
					"< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() +
					"\n\nСлучайная бухта у французского поселения" + NewStr() +
					"---------------------------------------------------------" + NewStr() +
					"< 61 > " + descF61 + NewStr() + "< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() +
					"< 64 > " + descF64 + NewStr() + "< 65 > " + descF65 + NewStr() +
					"\n\nСлучайная бухта у пиратского поселения" + NewStr() +
					"------------------------------------------------------" + NewStr() +
					"< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() + 
					"\n\n********** СОБСТВЕННАЯ БАЗА **********" + NewStr() +
					"< 68 > " + descF68 + NewStr() +
					"\n\n********** ПРОЧЕЕ **********" + NewStr() +
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
		case "B_RELOAD": if(comName=="activate" || comName=="click") {ReloadByStr();} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(4); // Статистика по читам
}

string descF1 = "Сент-Джонс (Антигуа)";
void CalculateInfoDataF1()
{
	CommonActions();
	totalInfo = "#1 " + descF1;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SentJons_town");
			setWDMPointXZ("SentJons_town");
		}
		DoQuestReloadToLocation("SentJons_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F1", 1);
}

string descF2 = "Бриджтаун (Барбадос)";
void CalculateInfoDataF2()
{
	CommonActions();
	totalInfo = "#2 " + descF2;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Bridgetown_town");
			setWDMPointXZ("Bridgetown_town");
		}
		DoQuestReloadToLocation("Bridgetown_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F2", 1);
}

string descF3 = "Белиз (Юкатан)";
void CalculateInfoDataF3()
{
	CommonActions();
	totalInfo = "#3 " + descF3;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Beliz_town");
			setWDMPointXZ("Beliz_town");
		}
		DoQuestReloadToLocation("Beliz_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F3", 1);
}

string descF4 = "Порт Рояль (Ямайка)";
void CalculateInfoDataF4()
{
	CommonActions();
	totalInfo = "#4 " + descF4;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortRoyal_town");
			setWDMPointXZ("PortRoyal_town");
		}
		DoQuestReloadToLocation("PortRoyal_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F4", 1);
}

string descF5 = "Блуфилдс (Мэйн)";
void CalculateInfoDataF5()
{
	CommonActions();
	totalInfo = "#5 " + descF5;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SantaCatalina_town");
			setWDMPointXZ("SantaCatalina_town");
		}
		DoQuestReloadToLocation("SantaCatalina_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F5", 1);
}

string descF6 = "Филипсбург (Синт-Маартен)";
void CalculateInfoDataF6()
{
	CommonActions();
	totalInfo = "#6 " + descF6;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Marigo_town");
			setWDMPointXZ("Marigo_town");
		}
		DoQuestReloadToLocation("Marigo_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F6", 1);
}

string descF7 = "Виллемстад (Кюрасао)";
void CalculateInfoDataF7()
{
	CommonActions();
	totalInfo = "#7 " + descF7;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Villemstad_town");
			setWDMPointXZ("Villemstad_town");
		}
		DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F7", 1);
}

string descF8 = "Форт Оранж (Ямайка)";
void CalculateInfoDataF8()
{
	CommonActions();
	totalInfo = "#8 " + descF8;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortAntonio_town");
			setWDMPointXZ("PortAntonio_town");
		}
		DoQuestReloadToLocation("PortAntonio_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F8", 1);
}

string descF9 = "Сантьяго (Куба)";
void CalculateInfoDataF9()
{
	CommonActions();
	totalInfo = "#9 " + descF9;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Santiago_town");
			setWDMPointXZ("Santiago_town");
		}
		DoQuestReloadToLocation("Santiago_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F9", 1);
}

string descF10 = "Гавана (Куба)";
void CalculateInfoDataF10()
{
	CommonActions();
	totalInfo = "#10 " + descF10;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Havana_town");
			setWDMPointXZ("Havana_town");
		}
		DoQuestReloadToLocation("Havana_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F10", 1);
}

string descF11 = "Сан-Хосе (Тринидад и Тобаго)";
void CalculateInfoDataF11()
{
	CommonActions();
	totalInfo = "#11 " + descF11;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortSpein_town");
			setWDMPointXZ("PortSpein_town");
		}
		DoQuestReloadToLocation("PortSpein_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F11", 1);
}

string descF12 = "Картахена (Мэйн)";
void CalculateInfoDataF12()
{
	CommonActions();
	totalInfo = "#12 " + descF12;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Cartahena_town");
			setWDMPointXZ("Cartahena_town");
		}
		DoQuestReloadToLocation("Cartahena_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F12", 1);
}

string descF13 = "Кумана (Мэйн)";
void CalculateInfoDataF13()
{
	CommonActions();
	totalInfo = "#13 " + descF13;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Cumana_town");
			setWDMPointXZ("Cumana_town");
		}
		DoQuestReloadToLocation("Cumana_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F13", 1);
}

string descF14 = "Каракас (Мэйн)";
void CalculateInfoDataF14()
{
	CommonActions();
	totalInfo = "#14 " + descF14;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Caracas_town");
			setWDMPointXZ("Caracas_town");
		}
		DoQuestReloadToLocation("Caracas_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F14", 1);
}

string descF15 = "Санто-Доминго (Эспаньола)";
void CalculateInfoDataF15()
{
	CommonActions();
	totalInfo = "#15 " + descF15;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SantoDomingo_town");
			setWDMPointXZ("SantoDomingo_town");
		}
		DoQuestReloadToLocation("SantoDomingo_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F15", 1);
}

string descF16 = "Маракайбо (Мэйн)";
void CalculateInfoDataF16()
{
	CommonActions();
	totalInfo = "#16 " + descF16;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Maracaibo_town");
			setWDMPointXZ("Maracaibo_town");
		}
		DoQuestReloadToLocation("Maracaibo_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F16", 1);
}

string descF17 = "Сан-Хуан (Пуэрто-Рико)";
void CalculateInfoDataF17()
{
	CommonActions();
	totalInfo = "#17 " + descF17;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SanJuan_town");
			setWDMPointXZ("SanJuan_town");
		}
		DoQuestReloadToLocation("SanJuan_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F17", 1);
}

string descF18 = "Вилья Алегрия (Пуэрто-Рико)";
void CalculateInfoDataF18()
{
	CommonActions();
	totalInfo = "#18 " + descF18;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "VillaAlegria_town");
			setWDMPointXZ("VillaAlegria_town");
		}
		DoQuestReloadToLocation("VillaAlegria_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F18", 1);
}

string descF19 = "Порто Белло (Мэйн)";
void CalculateInfoDataF19()
{
	CommonActions();
	totalInfo = "#19 " + descF19;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortoBello_town");
			setWDMPointXZ("PortoBello_town");
		}
		DoQuestReloadToLocation("PortoBello_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F19", 1);
}

string descF20 = "Панама (Панама)";
void CalculateInfoDataF20()
{
	CommonActions();
	totalInfo = "#20 " + descF20;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortoBello_town");
			setWDMPointXZ("PortoBello_town");
			Log_info("Корабль поставлен в порт колонии Порто Белло!");
		}
		DoQuestReloadToLocation("Panama_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F20", 1);
}


string descF21 = "Бас-Тер (Гваделупа)";
void CalculateInfoDataF21()
{
	CommonActions();
	totalInfo = "#21 " + descF21;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "BasTer_town");
			setWDMPointXZ("BasTer_town");
		}
		DoQuestReloadToLocation("BasTer_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F21", 1);
}

string descF22 = "Порт-о-Пренс (Эспаньола)";
void CalculateInfoDataF22()
{
	CommonActions();
	totalInfo = "#22 " + descF22;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PortPax_town");
			setWDMPointXZ("PortPax_town");
		}
		DoQuestReloadToLocation("PortPax_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F22", 1);
}

string descF23 = "Форт де Франс (Мартиника)";
void CalculateInfoDataF23()
{
	CommonActions();
	totalInfo = "#23 " + descF23;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "FortFrance_town");
			setWDMPointXZ("FortFrance_town");
		}
		DoQuestReloadToLocation("FortFrance_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F23", 1);
}

string descF24 = "Капстервиль (Сент-Кристофер)";
void CalculateInfoDataF24()
{
	CommonActions();
	totalInfo = "#24 " + descF24;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Charles_town");
			setWDMPointXZ("Charles_town");
		}
		DoQuestReloadToLocation("Charles_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F24", 1);
}

string descF25 = "Тортуга (Тортуга)";
void CalculateInfoDataF25()
{
	CommonActions();
	totalInfo = "#25 " + descF25;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Tortuga_town");
			setWDMPointXZ("Tortuga_town");
		}
		DoQuestReloadToLocation("Tortuga_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F25", 1);
}

string descF26 = "Шарптаун (Исла-Тесоро)";
void CalculateInfoDataF26()
{
	CommonActions();
	totalInfo = "#26 " + descF26;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Pirates_town");
			setWDMPointXZ("Pirates_town");
		}
		DoQuestReloadToLocation("Pirates_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F26", 1);
}

string descF27 = "Сан-Андрес (Провиденсия)";
void CalculateInfoDataF27()
{
	CommonActions();
	totalInfo = "#27 " + descF27;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SanAndres_town");
			setWDMPointXZ("SanAndres_town");
		}
		DoQuestReloadToLocation("SanAndres_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	Log_info("Выйдя в море с этого порта, не пугайтесь xD");
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F27", 1);
}

string descF28 = "Пуэрто-Принсипе (Куба)";
void CalculateInfoDataF28()
{
	CommonActions();
	totalInfo = "#28 " + descF28;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "PuertoPrincipe_port");
			setWDMPointXZ("PuertoPrincipe_port");
		}
		DoQuestReloadToLocation("PuertoPrincipe_port", "reload", "reload1_back", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F28", 1);
}

string descF29 = "Ла Вега (Эспаньола)";
void CalculateInfoDataF29()
{
	CommonActions();
	totalInfo = "#29 " + descF29;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "LaVega_port");
			setWDMPointXZ("LaVega_port");
		}
		DoQuestReloadToLocation("LaVega_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F29", 1);
}

string descF30 = "Ле-Ке (Эспаньола)";
void CalculateInfoDataF30()
{
	CommonActions();
	totalInfo = "#30 " + descF30;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "LeKe_town");
			setWDMPointXZ("LeKe_town");
		}
		DoQuestReloadToLocation("LeKe_town", "reload", "reload2_back", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F30", 1);
}

string descF31 = "Ле Франсуа (Мартиника)";
void CalculateInfoDataF31()
{
	CommonActions();
	totalInfo = "#31 " + descF31;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "LeFransua_port");
			setWDMPointXZ("LeFransua_port");
		}
		DoQuestReloadToLocation("LeFransua_port", "reload", "reload2", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F31", 1);
}

string descF32 = "Саванна-ла-Мар (Ямайка)";
void CalculateInfoDataF32()
{
	CommonActions();
	totalInfo = "#32 " + descF32;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "FortOrange_port");
			setWDMPointXZ("FortOrange_port");
		}
		DoQuestReloadToLocation("FortOrange_port", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F32", 1);
}

string descF33 = "Шарлотт-Таун (Доминика)";
void CalculateInfoDataF33()
{
	CommonActions();
	totalInfo = "#33 " + descF33;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Roseau_port");
			setWDMPointXZ("Roseau_port");
		}
		DoQuestReloadToLocation("Roseau_port", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F33", 1);
}

string descF34 = "Вестпунт (Кюрасао)";
void CalculateInfoDataF34()
{
	CommonActions();
	totalInfo = "#34 " + descF34;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Vestpunt_Port");
			setWDMPointXZ("Vestpunt_Port");
		}
		DoQuestReloadToLocation("Vestpunt_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F34", 1);
}

string descF35 = "Сент-Луи (Гваделупа)";
void CalculateInfoDataF35()
{
	CommonActions();
	totalInfo = "#35 " + descF35;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "SantLous_Port");
			setWDMPointXZ("SantLous_Port");
		}
		DoQuestReloadToLocation("SantLous_town", "reload", "reload1", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F35", 1);
}

string descF36 = "Маяк Тринидада и Тобаго";
void CalculateInfoDataF36()
{
	CommonActions();
	totalInfo = "#36 " + descF36;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak1");
			setWDMPointXZ("Mayak1");
		}
		DoQuestReloadToLocation("Mayak1", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F36", 1);
}

string descF37 = "Маяк Порт-Рояля";
void CalculateInfoDataF37()
{
	CommonActions();
	totalInfo = "#37 " + descF37;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak3");
			setWDMPointXZ("Mayak3");
		}
		DoQuestReloadToLocation("Mayak3", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F37", 1);
}

string descF38 = "Маяк Сантьяго";
void CalculateInfoDataF38()
{
	CommonActions();
	totalInfo = "#38 " + descF38;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak9");
			setWDMPointXZ("Mayak9");
		}
		DoQuestReloadToLocation("Mayak9", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F38", 1);
}

string descF39 = "Маяк Гваделупы";
void CalculateInfoDataF39()
{
	CommonActions();
	totalInfo = "#39 " + descF39;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak4");
			setWDMPointXZ("Mayak4");
		}
		DoQuestReloadToLocation("Mayak4", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F39", 1);
}

string descF40 = "Маяк Картахены";
void CalculateInfoDataF40()
{
	CommonActions();
	totalInfo = "#40 " + descF40;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak11");
			setWDMPointXZ("Mayak11");
		}
		DoQuestReloadToLocation("Mayak11", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F40", 1);
}

string descF41 = "Маяк Бриджтауна";
void CalculateInfoDataF41()
{
	CommonActions();
	totalInfo = "#41 " + descF41;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Mayak2");
			setWDMPointXZ("Mayak2");
		}
		DoQuestReloadToLocation("Mayak2", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F41", 1);
}


string descF42 = "Теркс (Теркс)";
void CalculateInfoDataF42()
{
	CommonActions();
	totalInfo = "#42 " + descF42;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore56");
					setWDMPointXZ("Shore56");
				}
				DoQuestReloadToLocation("Shore56", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore57");
					setWDMPointXZ("Shore57");
				}
				DoQuestReloadToLocation("Shore57", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F42", 1);
}

string descF43 = "Кайман (Кайман)";
void CalculateInfoDataF43()
{
	CommonActions();
	totalInfo = "#43 " + descF43;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore16");
					setWDMPointXZ("Shore16");
				}
				DoQuestReloadToLocation("Shore16", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore17");
					setWDMPointXZ("Shore17");
				}
				DoQuestReloadToLocation("Shore17", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F43", 1);
}

string descF44 = "Белиз (Юкатан)";
void CalculateInfoDataF44()
{
	CommonActions();
	totalInfo = "#44 " + descF44;
	if (CheckRestrictors())
	{
		switch (rand(5))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore6");
					setWDMPointXZ("Shore6");
				}
				DoQuestReloadToLocation("Shore6", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore7");
					setWDMPointXZ("Shore7");
				}
				DoQuestReloadToLocation("Shore7", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore8");
					setWDMPointXZ("Shore8");
				}
				DoQuestReloadToLocation("Shore8", "reload", "sea", "");
			break;
			case 3:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore9");
					setWDMPointXZ("Shore9");
				}
				DoQuestReloadToLocation("Shore9", "reload", "sea", "");
			break;
			case 4:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore10");
					setWDMPointXZ("Shore10");
				}
				DoQuestReloadToLocation("Shore10", "reload", "sea", "");
			break;
			case 5:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore_ship2");
					setWDMPointXZ("Shore_ship2");
				}
				DoQuestReloadToLocation("Shore_ship2", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F44", 1);
}

string descF45 = "Блуфилдс (Мэйн)";
void CalculateInfoDataF45()
{
	CommonActions();
	totalInfo = "#45 " + descF45;
	if (CheckRestrictors())
	{
		switch (rand(2))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore53");
					setWDMPointXZ("Shore53");
				}
				DoQuestReloadToLocation("Shore53", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore54");
					setWDMPointXZ("Shore54");
				}
				DoQuestReloadToLocation("Shore54", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore55");
					setWDMPointXZ("Shore55");
				}
				DoQuestReloadToLocation("Shore55", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F45", 1);
}

string descF46 = "Порт Рояль (Ямайка)";
void CalculateInfoDataF46()
{
	CommonActions();
	totalInfo = "#46 " + descF46;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Shore36");
			setWDMPointXZ("Shore36");
		}
		DoQuestReloadToLocation("Shore36", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F46", 1);
}

string descF47 = "Сент-Джонс (Антигуа)";
void CalculateInfoDataF47()
{
	CommonActions();
	totalInfo = "#47 " + descF47;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore1");
					setWDMPointXZ("Shore1");
				}
				DoQuestReloadToLocation("Shore1", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore2");
					setWDMPointXZ("Shore2");
				}
				DoQuestReloadToLocation("Shore2", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F47", 1);
}

string descF48 = "Бриджтаун (Барбадос)";
void CalculateInfoDataF48()
{
	CommonActions();
	totalInfo = "#48 " + descF48;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore4");
					setWDMPointXZ("Shore4");
				}
				DoQuestReloadToLocation("Shore4", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore5");
					setWDMPointXZ("Shore5");
				}
				DoQuestReloadToLocation("Shore5", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F48", 1);
}

string descF49 = "Филипсбург (Синт-Маартен)";
void CalculateInfoDataF49()
{
	CommonActions();
	totalInfo = "#49 " + descF49;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore40");
					setWDMPointXZ("Shore40");
				}
				DoQuestReloadToLocation("Shore40", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore41");
					setWDMPointXZ("Shore41");
				}
				DoQuestReloadToLocation("Shore41", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F49", 1);
}

string descF50 = "Виллемстад (Кюрасао)";
void CalculateInfoDataF50()
{
	CommonActions();
	totalInfo = "#50 " + descF50;
	if (CheckRestrictors())
	{
		switch (rand(2))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore22");
					setWDMPointXZ("Shore22");
				}
				DoQuestReloadToLocation("Shore22", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore23");
					setWDMPointXZ("Shore23");
				}
				DoQuestReloadToLocation("Shore23", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore24");
					setWDMPointXZ("Shore24");
				}
				DoQuestReloadToLocation("Shore24", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F50", 1);
}

string descF51 = "Гавана (Куба)";
void CalculateInfoDataF51()
{
	CommonActions();
	totalInfo = "#51 " + descF51;
	if (CheckRestrictors())
	{
		switch (rand(2))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore13");
					setWDMPointXZ("Shore13");
				}
				DoQuestReloadToLocation("Shore13", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore14");
					setWDMPointXZ("Shore14");
				}
				DoQuestReloadToLocation("Shore14", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore15");
					setWDMPointXZ("Shore15");
				}
				DoQuestReloadToLocation("Shore15", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F51", 1);
}

string descF52 = "Сантьяго (Куба)"
void CalculateInfoDataF52()
{
	CommonActions();
	totalInfo = "#52 " + descF52;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore11");
					setWDMPointXZ("Shore11");
				}
				DoQuestReloadToLocation("Shore11", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore12");
					setWDMPointXZ("Shore12");
				}
				DoQuestReloadToLocation("Shore12", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F52", 1);
}

string descF53 = "Сан-Хуан (Пуэрто-Рико)";
void CalculateInfoDataF53()
{
	CommonActions();
	totalInfo = "#53 " + descF53;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore44");
					setWDMPointXZ("Shore44");
				}
				DoQuestReloadToLocation("Shore44", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore45");
					setWDMPointXZ("Shore45");
				}
				DoQuestReloadToLocation("Shore45", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F53", 1);
}

string descF54 = "Санто-Доминго (Эспаньола)";
void CalculateInfoDataF54()
{
	CommonActions();
	totalInfo = "#54 " + descF54;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore32");
					setWDMPointXZ("Shore32");
				}
				DoQuestReloadToLocation("Shore32", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore33");
					setWDMPointXZ("Shore33");
				}
				DoQuestReloadToLocation("Shore33", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F54", 1);
}

string descF55 = "Сан-Хосе (Тринидад и Тобаго)";
void CalculateInfoDataF55()
{
	CommonActions();
	totalInfo = "#55 " + descF55;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore59");
					setWDMPointXZ("Shore59");
				}
				DoQuestReloadToLocation("Shore59", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore60");
					setWDMPointXZ("Shore60");
				}
				DoQuestReloadToLocation("Shore60", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F55", 1);
}

string descF56 = "Порто Белло (Мейн)";
void CalculateInfoDataF56()
{
	CommonActions();
	totalInfo = "#56 " + descF56;
	if (CheckRestrictors())
	{
		switch (rand(2))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore46");
					setWDMPointXZ("Shore46");
				}
				DoQuestReloadToLocation("Shore46", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore47");
					setWDMPointXZ("Shore47");
				}
				DoQuestReloadToLocation("Shore47", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore48");
					setWDMPointXZ("Shore48");
				}
				DoQuestReloadToLocation("Shore48", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F56", 1);
}

string descF57 = "Картахена (Мэйн)";
void CalculateInfoDataF57()
{
	CommonActions();
	totalInfo = "#57 " + descF57;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Shore25");
			setWDMPointXZ("Shore25");
		}
		DoQuestReloadToLocation("Shore25", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F57", 1);
}

string descF58 = "Маракайбо (Мейн)";
void CalculateInfoDataF58()
{
	CommonActions();
	totalInfo = "#58 " + descF58;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore37");
					setWDMPointXZ("Shore37");
				}
				DoQuestReloadToLocation("Shore37", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore_ship3");
					setWDMPointXZ("Shore_ship3");
				}
				DoQuestReloadToLocation("Shore_ship3", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F58", 1);
}

string descF59 = "Каракас (Мэйн)";
void CalculateInfoDataF59()
{
	CommonActions();
	totalInfo = "#59 " + descF59;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Shore21");
			setWDMPointXZ("Shore21");
		}
		DoQuestReloadToLocation("Shore21", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F59", 1);
}

string descF60 = "Кумана (Мэйн)";
void CalculateInfoDataF60()
{
	CommonActions();
	totalInfo = "#60 " + descF60;
	if (CheckRestrictors())
	{
		switch (rand(2))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore18");
					setWDMPointXZ("Shore18");
				}
				DoQuestReloadToLocation("Shore18", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore19");
					setWDMPointXZ("Shore19");
				}
				DoQuestReloadToLocation("Shore19", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore20");
					setWDMPointXZ("Shore20");
				}
				DoQuestReloadToLocation("Shore20", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F60", 1);
}

string descF61 = "Порт-о-Пренс (Эспаньола)";
void CalculateInfoDataF61()
{
	CommonActions();
	totalInfo = "#61 " + descF61;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Shore34");
			setWDMPointXZ("Shore34");
		}
		DoQuestReloadToLocation("Shore34", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F61", 1);
}

string descF62 = "Тортуга (Тортуга)";
void CalculateInfoDataF62()
{
	CommonActions();
	totalInfo = "#62 " + descF62;
	if (CheckRestrictors())
	{
		if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			setCharacterShipLocation(pchar, "Shore58");
			setWDMPointXZ("Shore58");
		}
		DoQuestReloadToLocation("Shore58", "reload", "sea", "");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F62", 1);
}

string descF63 = "Капстервиль (Сент-Кристофер)";
void CalculateInfoDataF63()
{
	CommonActions();
	totalInfo = "#63 " + descF63;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore42");
					setWDMPointXZ("Shore42");
				}
				DoQuestReloadToLocation("Shore42", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore43");
					setWDMPointXZ("Shore43");
				}
				DoQuestReloadToLocation("Shore43", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F63", 1);
}

string descF64 = "Бас-Тер (Гваделупа)";
void CalculateInfoDataF64()
{
	CommonActions();
	totalInfo = "#64 " + descF64;
	if (CheckRestrictors())
	{
		switch (rand(3))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore28");
					setWDMPointXZ("Shore28");
				}
				DoQuestReloadToLocation("Shore28", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore29");
					setWDMPointXZ("Shore29");
				}
				DoQuestReloadToLocation("Shore29", "reload", "sea", "");
			break;
			case 2:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore30");
					setWDMPointXZ("Shore30");
				}
				DoQuestReloadToLocation("Shore30", "reload", "sea", "");
			break;
			case 3:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore31");
					setWDMPointXZ("Shore31");
				}
				DoQuestReloadToLocation("Shore31", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F64", 1);
}

string descF65 = "Форт де Франс (Мартиника)";
void CalculateInfoDataF65()
{
	CommonActions();
	totalInfo = "#65 " + descF65;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore38");
					setWDMPointXZ("Shore38");
				}
				DoQuestReloadToLocation("Shore38", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore39");
					setWDMPointXZ("Shore39");
				}
				DoQuestReloadToLocation("Shore39", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F65", 1);
}

string descF66 = "Шарптаун (Исла-Тесоро)";
void CalculateInfoDataF66()
{
	CommonActions();
	totalInfo = "#66 " + descF66;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore3");
					setWDMPointXZ("Shore3");
				}
				DoQuestReloadToLocation("Shore3", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore_ship1");
					setWDMPointXZ("Shore_ship1");
				}
				DoQuestReloadToLocation("Shore_ship1", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F66", 1);
}

string descF67 = "Сан-Андрес (Провиденсия)";
void CalculateInfoDataF67()
{
	CommonActions();
	totalInfo = "#67 " + descF67;
	if (CheckRestrictors())
	{
		switch (rand(1))
		{
			case 0:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore68");
					setWDMPointXZ("Shore68");
				}
				DoQuestReloadToLocation("Shore68", "reload", "sea", "");
			break;
			case 1:
				if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
				{
					setCharacterShipLocation(pchar, "Shore69");
					setWDMPointXZ("Shore69");
				}
				DoQuestReloadToLocation("Shore69", "reload", "sea", "");
			break;
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F67", 1);
}

string descF68 = "Телепорт на собственную базу (Исла-Мона)";
void CalculateInfoDataF68()
{
	CommonActions();
	totalInfo = "#68 " + descF68;
	ref rXep;
	if (CheckRestrictors())
	{
		rXep = characterFromID("Islamona_carpenter");
		if (rXep.id != -1 && rXep.dialog.currentnode == "carpenter_17")
		{
			if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
			{
				switch (rand(1))
				{
					case 0: setCharacterShipLocation(pchar, "Shore75"); setWDMPointXZ("Shore75"); Log_info("Корабль стоит в бухте Губернатора (напрямую от выхода с базы)"); break;
					case 1: setCharacterShipLocation(pchar, "Shore77"); setWDMPointXZ("Shore77"); Log_info("Корабль стоит в бухте Вьекес (налево от выхода с базы)"); break;
				}
			}
			DoQuestReloadToLocation("IslaMona_fort", "reload", "reload1", "");
		}
		else
		{
			bExit = false;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info("Требуется завершение квеста 'Под флагом Веселого Роджера. Сокровища свободного ярла.'");
			totalInfo += NewStr() + "Требуется завершение квеста 'Под флагом Веселого Роджера. Сокровища свободного ярла.'";
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F68", 1);
}

string descF69 = "Телепорт по тавернам";
void CalculateInfoDataF69()
{
	CommonActions();
	totalInfo = "#69 " + descF69;
	ref ch;
	int n, idx;
	idx = GetCharIDXByParam("TavernMan", "location", pchar.location);
	bool ok = true;
	if (CheckRestrictors())
	{
		while (ok)
		{
			for (n=0; n<MAX_CHARACTERS; n++)
			{
				makeref(ch,Characters[n]);
				if (CheckAttribute(ch, "TavernMan"))
				{
					if (ch.location == "none") continue;
					if (n > idx)
					{
						ok = false;
						if (GetCityFrom_Sea(ch.City) != "")
						{
							if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
							{
								setCharacterShipLocation(pchar, GetCityFrom_Sea(ch.City));
								setWDMPointXZ(GetCityFrom_Sea(ch.City));
							}
						}
						DoQuestReloadToLocation(ch.location,"reload","reload1", "");
						break;
					}
				}
			}
			idx = -1;
		}
		iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
		Log_info("Локация " + ch.location + " успешно загружена!");
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
	Statistic_AddValue(PChar, "Cheats.CSM5.F69", 1);
}

string descF70 = "Включить \ отключить отображение локаторов";
void CalculateInfoDataF70()
{
	CommonActions();
	totalInfo = "#70 " + descF70;
	if (bLocatorShow == true)
	{
		bLocatorShow = false;
		HideAllLocators();
		worldMap.debug = "false";
		worldMap.evwin = "false";
		Log_info("Отображение локаторов отключено.");
		totalInfo += NewStr() + "Отображение локаторов отключено.";
	}
	else
	{
		bLocatorShow = true;
		ShowAllLocators();
		worldMap.debug = "true";
		worldMap.evwin = "true";
		Log_info("Отображение локаторов включено!");
		totalInfo += NewStr() + "Отображение локаторов включено!";
	}
	totalInfo += NewStr() + back2totalInfo;
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM5.F70", 1);
}

void ReloadByStr()
{
	// разбор строки
	string sloc = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 0));
	string sgrp = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 1));
	string sltr = stripblank(GetSubStringByNum(GameInterface.reload_edit.str, 2));
	if (sgrp == sloc) sgrp = "reload";
	if (sltr == sloc) sltr = "reload1";
	pchar.reload_edit.str = GameInterface.reload_edit.str;
	int i = FindLocation(sloc);
	if (CheckRestrictors())
	{
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
					setCharacterShipLocation(pchar, sloc);
					setWDMPointXZ(sloc);
				}
			}
			DoQuestReloadToLocation(sloc, sgrp, sltr, "");
			Log_Info(sloc + " " + sgrp + " " + sltr);
			// Статистика по читам
			// Statistic_AddValue(PChar, "Cheats.ReloadByStr", 1);
		}
		else
		{
			bExit = false;
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			Log_Info("Такой локации нет!");
			totalInfo = NewStr() + "Такой локации нет!";
		}
	}
	else
	{
		bExit = false;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo = NewStr() + sTaboo;
	}
	totalInfo += NewStr() + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) { ProcessCancelExit(); }
}

bool CheckRestrictors()
{
	if (CheckAttribute(pchar, "chr_ai.type") && pchar.chr_ai.type != LAI_TYPE_PLAYER) { return false; }
	if (chrDisableReloadToLocation == true || bQuestDisableMapEnter == true || bDisableFastReload == true) { return false; }
	return true;
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
			sHeader = "Описание меню 'Локации'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Локации' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Локации'";
			sText1 = "Перезапуск меню 'Локации'";
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
			sHeader = "Меню 'Товары'";
			sText1 = "Запуск меню 'Товары'";
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
		case "RELOAD_EDIT":
			sHeader = "Ручное перемещение";
			sText1 = "Введите координаты для ручного перемещения";
		break;
		case "B_RELOAD":
			sHeader = "Ручное перемещение";
			sText1 = "Нажимать для подтверждения перемещения в указанную локацию";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
