
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Разное
	Основано на меню дебаггера от boal
	09.07.19  //  Пират Либерталии
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке ''Прочее'' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sNoShip = "А где же Ваш корабль, капитан?!";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_misc";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(8); // Warship. Статистика - сколько читов юзали
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
					"********** УРОВЕНЬ СЛОЖНОСТИ **********" + NewStr() + "<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() + "< 10 > " + descF10 + NewStr() + 
			"\n\n********** НАСТРОЙКИ ИГРЫ **********" + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "\n\n********** ГЛОБАЛЬНОЕ **********" + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() + "< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() + "< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() + "< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() +
					"< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() +
					"< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() +
					"< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() +
					"< 43 > " + descF43 + NewStr() + "< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() +
					"< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() +
					"\n\n********** ОЧИСТИТЬ ТРЮМ НА КОРАБЛЕ (КРОМЕ УСТАНОВЛЕННЫХ ОРУДИЙ) **********" + NewStr() + "< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + GetCompanionName(1) + NewStr() + "< 56 > " + descF56 + GetCompanionName(2) + NewStr() + 
					"< 57 > " + descF57 + GetCompanionName(3) + NewStr() + "< 58 > " + descF58 + GetCompanionName(4) + NewStr() + "< 59 > " + descF59 + GetCompanionName(5) + NewStr() + 
					"< 60 > " + descF60 + GetCompanionName(6) + NewStr() + "< 61 > " + descF61 + GetCompanionName(7) + NewStr() + "\n\n ********** ПРОЧЕЕ ********** " + NewStr() + " < 62 > " + descF63 + NewStr() +
				"< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() + "< 65 > " + descF65 + NewStr() + "< 66 > " + descF66 + NewStr() +
					"< 67 > " + descF67 + NewStr() + "< 68 > " + descF68 + NewStr() + "< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(8); // Статистика по читам
}

string descF1 = "Поменять сложность игры на: Юнга (легкая)";
void CalculateInfoDataF1()
{
totalInfo = "#1 " + descF1;
CommonActions();
MOD_SKILL_ENEMY_RATE = 1;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Юнга (легкая)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Юнга (легкая)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F1", 1);
}

string descF2 = "Поменять сложность игры на: Матрос (легкая)";
void CalculateInfoDataF2()
{
totalInfo = "#2 " + descF2;
CommonActions();
MOD_SKILL_ENEMY_RATE = 2;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Матрос (легкая)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Матрос (легкая)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F2", 1);
}

string descF3 = "Поменять сложность игры на: Боцман (средняя)";
void CalculateInfoDataF3()
{
totalInfo = "#3 " + descF3;
CommonActions();
MOD_SKILL_ENEMY_RATE = 3;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Боцман (средняя)!";
Log_info("Выбранная сложность игры: Боцман (средняя)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F3", 1);
}


string descF4 = "Поменять сложность игры на: Старпом (средняя)";
void CalculateInfoDataF4()
{
totalInfo = "#4 " + descF4;
CommonActions();
MOD_SKILL_ENEMY_RATE = 4;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Старпом (средняя)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Старпом (средняя)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F4", 1);
}

string descF5 = "Поменять сложность игры на: Лейтенант (повышенная)";
void CalculateInfoDataF5()
{
totalInfo = "#5 " + descF5;
CommonActions();
MOD_SKILL_ENEMY_RATE = 5;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Лейтенант (повышенная)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Лейтенант (повышенная)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F5", 1);
}

string descF6 = "Поменять сложность игры на: Капитан (повышенная)";
void CalculateInfoDataF6()
{
totalInfo = "#6 " + descF6;
CommonActions();
MOD_SKILL_ENEMY_RATE = 6;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Капитан (повышенная)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Капитан (повышенная)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F6", 1);
}

string descF7 = "Поменять сложность игры на: Командор (высокая)";
void CalculateInfoDataF7()
{
totalInfo = "#7 " + descF7;
CommonActions();
MOD_SKILL_ENEMY_RATE = 7;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Командор (высокая)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Командор (высокая)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F7", 1);
}

string descF8 = "Поменять сложность игры на: Адмирал (высокая)";
void CalculateInfoDataF8()
{
totalInfo = "#8 " + descF8;
CommonActions();
MOD_SKILL_ENEMY_RATE = 8;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Адмирал (высокая)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Адмирал (высокая)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F8", 1);
}

string descF9 = "Поменять сложность игры на: Гроза Морей (максимальная)";
void CalculateInfoDataF9()
{
totalInfo = "#9 " + descF9;
CommonActions();
MOD_SKILL_ENEMY_RATE = 9;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Гроза Морей (максимальная)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Гроза Морей (максимальная)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F9", 1);
}

string descF10 = "Поменять сложность игры на: Морской Дьявол (максимальная)";
void CalculateInfoDataF10()
{
totalInfo = "#10 " + descF10;
CommonActions();
MOD_SKILL_ENEMY_RATE = 10;
iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
totalInfo += "Выбранная сложность игры: Морской Дьявол (максимальная)! \n\nРекомендуется переночевать в таверне 3-5 раз и лишь затем вновь контактировать с игровым миром. Это необоходимо, чтобы игровой мир ''перезагрузился'' сообразно выбранной Вами сложности. Учтите, что некоторые моменты могут не изменится, поскольку подгружаются исключительно при начале новой игры.";
Log_info("Выбранная сложность игры: Морской Дьявол (максимальная)!");
totalInfo += back2totalInfo;
SetFormatedText("INFO_TEXT", totalInfo);
// ProcessCancelExit();
Statistic_AddValue(PChar, "Cheats.CSM9.F10", 1);
}

string descF11 = "Сменить тип морского сражения (динамика или тактика)";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	if (iArcadeSails == 1)
	{
		iArcadeSails = 0;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Включен режим тактического морского боя.");
		totalInfo += "Включен режим тактического морского боя." + NewStr() + "\n\nВнимание!\nВсе корабли будут:" + NewStr() + "1) гораздо менее маневренными" + NewStr() + "2) дольше перезаряжать орудия и работать с парусами";
	}
	else
	{
		iArcadeSails = 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Включен режим динамического морского боя (по умолчанию)!");
		totalInfo += "Включен режим динамического морского боя (по умолчанию)!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F11", 1);
}

string descF12 = "Вкл \ откл дозарядку огнестрельного оружия";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	if (bRechargePistolOnLine == true)
	{
		bRechargePistolOnLine = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Дозарядка огнестрельного оружия отключена.");
		totalInfo += "Дозарядка огнестрельного оружия отключена.";
	}
	else
	{
		bRechargePistolOnLine = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Дозарядка огнестрельного оружия включена!");
		totalInfo += "Дозарядка огнестрельного оружия включена!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F12", 1);
}

string descF13 = "Вкл \ откл раздел добычи";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	if (bPartitionSet == true)
	{
		bPartitionSet = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Раздел добычи отключен.");
		totalInfo += "Раздел добычи отключен.";
	}
	else
	{
		bPartitionSet = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Раздел добычи включен!");
		totalInfo += "Раздел добычи включен!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F13", 1);
}

string descF14 = "Вкл \ откл вероятность дождей";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	if (bRains == true)
	{
		bRains = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Вероятность дождей отключена.");
		totalInfo += "Вероятность дождей отключена.";
	}
	else
	{
		bRains = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Вероятность дождей включена!");
		totalInfo += "Вероятность дождей включена!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F14", 1);
}

string descF15 = "Вкл \ откл возможность захвата колоний";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	bool bEnable = true;
	if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd") || bEnable)
	{
		if (bWorldAlivePause == true)
		{
			bWorldAlivePause = false;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Колонии можно захватывать!" + NewStr() + "Нации тоже станут захватывать чужие колонии в свои владения.\n\nВажно!\nПри выполнении квестов могут возникнуть нелепые, а то вовсе тупиковые ситуации!\nДанную опцию лучше активировать после завершения основного сюжета игры.";
		}
		else
		{
			bWorldAlivePause = true;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Колонии можно только грабить.";
		}
	}
	else
	{
		if (!bWorldAlivePause) bWorldAlivePause = true;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Во избежание возможных проблем, эта опция доступна лишь после завершения основного сюжета игры.");
		totalInfo += "Во избежание возможных проблем, эта опция доступна лишь после завершения основного сюжета игры.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F15", 1);
}

string descF16 = "Вкл \ откл режим Hardcore";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	if (bHardcoreGame == true)
	{
		bHardcoreGame = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Режим Hardcore отключен. Сохраняться можно где угодно.");
		totalInfo += "Режим Hardcore отключен. Сохраняться можно где угодно.";
	}
	else
	{
		bHardcoreGame = true;
		iSND = PlaySound("_CheatSurfMenu_\Hardcore.wav");
		Log_info("Включен режим Hardcore! Сохраняться можно только в церквях!");
		totalInfo += "Внимание!" + NewStr() + "Включен режим Hardcore! Сохраняться можно только в церквях!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F16", 1);
}

// Существенно рассширено Sticksъ -->
string descF17 = "Изменить форму матросов на корабле ГГ (33 варианта)";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	string message;
	string sMSGe = "английская военная форма";
	string sMSGf = "французская военная форма";
	string sMSGs = "испанская военная форма";
	string sMSGh = "голландская военная форма";
	string sMSGc = "Милиция+Солдаты+Гвардия";
	string sTXTa = "Милиция";
	string sTXTb = "Солдаты";
	string sTXTc = "Гвардия";

	if (!CheckAttribute(pchar, "GenQuest.BoardCrewType")) // добавим аттрибут для переключения типов команд
		pchar.GenQuest.BoardCrewType = 0; // 0 - пусть будет дефолт

	int type = pchar.GenQuest.BoardCrewType;
	type++;

	if (type > 33)
		type = 0;

	totalInfo += type + "/33\n\n";

	switch (type)
	{
		case 0:	message = "обычная матросская форма"; iSND = PlaySound("_CheatSurfMenu_\Matrosi.wav"); break;
		// Англия
		case 1: message = "английская форма (Милиция)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 2: message = "английская форма (Армия)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 3: message = "английская форма (Гвардия)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 4: message = "английская форма (Милиция+Армия+Гвардия)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 5: message = "английская форма (Милиция+Армия+Гвардия+Матросы)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 6: message = "английская форма (Гвардия+Рыбьи Хари, как в ПКМ3)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		// Франция
		case 7: message = "французская форма (Милиция)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav");break;
		case 8: message = "французская форма (Армия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 9: message = "французская форма (Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 10: message = "французская форма (Милиция+Армия+Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 11: message = "французская форма (Милиция+Армия+Гвардия+Матросы)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 12: message = "мальтийская форма (Госпитальеры)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		// Испания
		case 13: message = "испанская форма (Милиция)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 14: message = "испанская форма (Армия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 15: message = message = "испанская форма (Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 16: message = "испанская форма (Милиция+Армия+Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 17: message = "испанская форма (Милиция+Армия+Гвардия+Матросы)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 18: message = "каталонская форма"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		// Голландия
		case 19: message = "голландская форма (Милиция)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 20: message = "голландская форма (Армия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 21: message = "голландская форма (Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 22: message = "голландская форма (Милиция+Армия+Гвардия)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 23: message = "голландская форма (Милиция+Армия+Гвардия+Матросы)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		// Прочее
		case 24: message = "форма деловых людей"; iSND = PlaySound("_CheatSurfMenu_\Delo.wav"); break;
		case 25: message = "святая форма"; iSND = PlaySound("_CheatSurfMenu_\Church.wav"); break;
		case 26: message = "пиратская форма"; iSND = PlaySound("_CheatSurfMenu_\Nation_Pir.wav"); break;
		case 27: message = "рвань"; iSND = PlaySound("_CheatSurfMenu_\poorman.wav"); break;
		case 28: message = "форма ирокезов"; iSND = PlaySound("_CheatSurfMenu_\Iroquois.wav"); break;
		case 29: message = "индейская и людоедская форма"; iSND = PlaySound("_CheatSurfMenu_\Montesuma.wav"); break;
		case 30: message = "американская форма"; iSND = PlaySound("_CheatSurfMenu_\US_ready.mp3"); break;
		case 31: message = "загробная форма"; iSND = PlaySound("Types\skel.wav"); break;
		case 32: message = "рыбья форма"; iSND = PlaySound("_CheatSurfMenu_\DavyJones.wav"); break;
		case 33: message = "загробная и рыбья форма"; iSND = PlaySound("_CheatSurfMenu_\DavyJones.wav"); break;
	}
	pchar.GenQuest.BoardCrewType = type;
	Log_info("Команде на корабле ГГ выдана " + message + "!");
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "Команде на корабле ГГ выдана " + message + "!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F17", 1);
}
// <--

string descF18 = "Изменить дату месяца на 1 день вперед";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	LAi_Fade("", "");
	AddDataToCurrent(0, 0, 1);
	PlaySound("Interface\sobitie_na_karte_001.wav");
	Log_info("Дата текущего месяца изменена на 1 день вперед.");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	ProcessCancelExit(); // Закликивать не дадим, во избежание багов
	Statistic_AddValue(PChar, "Cheats.CSM9.F18", 1);
}

string descF19 = "Изменить дату месяца на 1 день назад";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	bool bExit = false;
	if (GetDataDay() != 1)
	{
		bExit = true;
		LAi_Fade("", "");
		AddDataToCurrent(0, 0, -1);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Дата текущего месяца изменена на 1 день назад.");
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("В 1-ый день месяца этого сделать нельзя...");
		totalInfo += "В 1-ый день месяца этого сделать нельзя...";
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) ProcessCancelExit(); // Закликивать не дадим, во избежание багов
	Statistic_AddValue(PChar, "Cheats.CSM9.F19", 1);
}

string descF20 = "Вкл \ откл продажу кораблей на верфях с установленными орудиями";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllCannonsShipyardShip"))
	{
		pchar.CSM.AllCannonsShipyardShip = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Корабли на верфях продаются с установленными орудиями!");
		totalInfo += "Корабли на верфях продаются с установленными орудиями!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllCannonsShipyardShip");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Корабли на верфях продаются без пушек.");
		totalInfo += "Корабли на верфях продаются без пушек.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F20", 1);
}

string descF21 = "Вкл \ откл генерацию взрывов и эпидемий на вражеских кораблях в море";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.ShipSituationsOff"))
	{
		pchar.CSM.ShipSituationsOff = true;
		bSeaCanGenerateShipSituation = false;
		pchar.CanGenerateShipSituation = false;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Генерация взрывов и эпидемий на вражеских кораблях в море запрещена!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.ShipSituationsOff");
		bSeaCanGenerateShipSituation = true;
		pchar.CanGenerateShipSituation = true;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Генерация взрывов и эпидемий на вражеских кораблях в море разрешена.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F21", 1);
}

string descF22 = "Вкл \ откл пропажу кораблей ГГ на приколе при разграблении колонии";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NotDeleteShipsInStock"))
	{
		pchar.CSM.NotDeleteShipsInStock = true;
		totalInfo += "Ваши корабли стоящие на приколе не будут пропадать после разграбления колонии!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NotDeleteShipsInStock");
		totalInfo += "Ваши корабли стоящие на приколе будут пропадать при разграблении колонии...";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F22", 1);
}

string descF23 = "Вкл \ откл проверку типа и кол-ва кораблей для захода на Остров Справедливости";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.LSCFreeArrival"))
	{
		pchar.CSM.LSCFreeArrival = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("На Остров Справедливости можно заявляться на любом корабле и хоть при полной эскадре!");
		totalInfo += "На Остров Справедливости можно заявляться на любом корабле и хоть при полной эскадре!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.LSCFreeArrival");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("На Остров Справедливости нельзя зайти на большом корабле или в составе эскадры.");
		totalInfo += "На Остров Справедливости нельзя зайти на большом корабле или в составе эскадры.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F23", 1);
}

// by Sticksъ -->
string descF24 = "Изменить скорость перемещения всех кораблей на глобальной карте";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
    string message = "Скорость всех корабликов на глобальной карте: ";

	if (!CheckAttribute(pchar, "CSM.FastTravelMode"))
	{
		pchar.CSM.FastTravelMode = true;
		worldMap.shipSpeedOppositeWind = 3.0;   // против ветра
		worldMap.shipSpeedOverWind = 3.0;       // по ветру
		message = message + "лютая";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FastTravelMode");
		worldMap.shipSpeedOppositeWind = 0.3;   // как в оригинале
		worldMap.shipSpeedOverWind = 0.8;       // как в оригинале
		message = message + "нормальная";
	}
	iSND = PlaySound("Interface\abordage_wining.wav");
	Log_info(message);
	totalInfo += message + NewStr() + "Автор: Sticksъ";
	if (IsEntity(&worldMap)) { totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!"; }
	totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM9.F24", 1);
}
// by Sticksъ <--

string descF25 = "Уменьшить \ нормализировать скорость течения времени на глобальной карте";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	string sDef = " (норма 1.5)";
	string sReduced = "Скорость течения времени на глобальной карте уменьшена и равна: ";
	string sNext = "Следующим нажатием выставится значение: ";
	string sNormal = "Скорость течения времени на глобальной карте нормализирована, текущее значение: ";
	switch (stf(worldMap.date.hourPerSec))
	{
		case 1.5:
			worldMap.date.hourPerSec = 1.0;
			Log_info(sReduced + stf(worldMap.date.hourPerSec) + sDef);
			totalInfo += sReduced + stf(worldMap.date.hourPerSec) + sDef + NewStr() + sNext + "0.5";
		break;
		case 1.0:
			worldMap.date.hourPerSec = 0.5;
			Log_info(sReduced + stf(worldMap.date.hourPerSec) + sDef);
			totalInfo += sReduced + stf(worldMap.date.hourPerSec) + sDef + NewStr() + sNext + "0.1";
		break;
		case 0.5:
			worldMap.date.hourPerSec = 0.1;
			Log_info(sReduced + stf(worldMap.date.hourPerSec) + sDef);
			totalInfo += sReduced + stf(worldMap.date.hourPerSec) + sDef + NewStr() + sNext + "1.5";
		break;
		case 0.1:
			worldMap.date.hourPerSec = 1.5;
			Log_info(sNormal + stf(worldMap.date.hourPerSec));
			totalInfo += sNormal + stf(worldMap.date.hourPerSec) + NewStr() + sNext + "1.0";
		break;
	}
	if (stf(worldMap.date.hourPerSec) < 0.1) worldMap.date.hourPerSec = 0.1;
	if (stf(worldMap.date.hourPerSec) > 1.5) worldMap.date.hourPerSec = 1.5;
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap)) { totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F25", 1);
}

string descF26 = "Вкл \ откл ''пустую глобальную карту'' (кроме квестовых кораблей)";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	string sLogA = "Все простые корабли, лодки, бочонки и шторм на глобальной карте отключены!";
	string sLogB = "Состояние глобальной карты приведено в исходное положение.";
	if (!CheckAttribute(pchar, "CSM.WorldMapEncountersOff"))
	{
		pchar.CSM.WorldMapEncountersOff = true;
		iEncountersRate = 0;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sLogA);
		totalInfo += sLogA + NewStr() + "Квестовых кораблей это не касается.";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.WorldMapEncountersOff");
		iEncountersRate = 1;
		pchar.worldmapencountersoff = "0";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sLogB);
		totalInfo += sLogB;
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap)) { totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F26", 1);
}

string descF27 = "Вкл \ откл враждебные корабли и шторм на глобальной карте";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	string sLog = "Враждебные корабли и шторм на глобальной карте ";
	string sLogQ = "Квестовых кораблей это не касается.";
	if (CheckAttribute(pchar, "worldmapencountersoff") == 0)
	{
		pchar.worldmapencountersoff = "1";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sLog + "отключены!");
		totalInfo += sLog + "отключены!" + NewStr() + sLogQ;
	}
	else
	{
		if (pchar.worldmapencountersoff == "1")
		{
			pchar.worldmapencountersoff = "0";
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sLog + "включены.");
			totalInfo += sLog + "включены.";
		}
		else
		{
			pchar.worldmapencountersoff = "1";
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sLog + "отключены!");
			totalInfo += sLog + "отключены!" + NewStr() + sLogQ;
		}
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap) && !CheckAttribute(pchar, "CSM.WorldMapEncountersOff")) { totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F27", 1);
}

string descF28 = "Увеличить \ по умолчанию дальность видимости кораблей на глобальной карте";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	string sLog = "Дальность видимости всех кораблей на глобальной карте ";
	if (!CheckAttribute(pchar, "CSM.MapShipDistView"))
	{
		pchar.CSM.MapShipDistView = true;
		worldMap.enemyshipViewDistMin = 980.0;
		worldMap.enemyshipViewDistMax = 999.0;
		sLog = sLog + "увеличена!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MapShipDistView");
		worldMap.enemyshipViewDistMin = 60.0;
		worldMap.enemyshipViewDistMax = 120.0;
		sLog = sLog + "выставлена по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	Log_info(sLog);
	totalInfo += sLog;
	PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap)) { totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F28", 1);
}

string descF29 = "Узнать текущие цены на товары во всех магазинах архипелага";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	bBettaTestMode = true;
	int iC;
	ref rC, rXep;
	rC = GetColonyByIndex(FindColony("Pirates"));
	if (rC != -1) SetPriceListByStoreMan(rC);
/*
	// Магаза на базе ГГ пока формально нет
	rXep = characterFromID("Islamona_carpenter");
	if (rXep.id != -1 && rXep.dialog.currentnode == "carpenter_17")
	{
		rC = GetColonyByIndex(FindColony("IslaMona"));
		if (rC != -1) SetPriceListByStoreMan(rC);
	}
*/
	for (iC = 0; iC < MAX_COLONIES; iC++)
	{
		if (CheckAttribute(&colonies[iC], "StoreNum") && colonies[iC].StoreNum != Pirates_STORE && colonies[iC].StoreNum != IslaMona_STORE)
		{
			SetPriceListByStoreMan(&Colonies[iC]);
		}
	}
	bBettaTestMode = false;
	PlayStereoSound("notebook");
	iSND = PlaySound("_CheatSurfMenu_\Goods.wav");
	totalInfo += "Информация по ценам на товары во всех магазинах архипелага обновлена!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F29", 1);
}

string descF30 = "Вкл \ откл 100% шанс встретить в таверне торговца картой сокровищ";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.TreasureMapTrader"))
	{
		pchar.CSM.TreasureMapTrader = true;
		totalInfo += "Шанс встретить в таверне торговца картой сокровищ 100%!" + NewStr() + "Если для него есть свободное место, конечно.";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.TreasureMapTrader");
		totalInfo += "Шанс встретить в таверне торговца картой сокровищ выставлен по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F30", 1);
}

string descF31 = "Вкл \ откл сбрасывание музыки при смене одинаковых типов локаций в джунглях";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.JungleContinuousMusic"))
	{
		pchar.CSM.JungleContinuousMusic = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Музыка не будет сбрасываться при смене одинаковых типов локаций в джунглях!");
		totalInfo += "Музыка не будет сбрасываться при смене одинаковых типов локаций в джунглях!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.JungleContinuousMusic");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Музыка будет сбрасываться при смене одинаковых типов локаций в джунглях.");
		totalInfo += "Музыка будет сбрасываться при смене одинаковых типов локаций в джунглях.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F31", 1);
}

string descF32 = "Вкл \ откл охотников за головами";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	if (!CheckAttribute(pchar, "GenQuest.HunterLongPause"))
	{
		pchar.GenQuest.HunterLongPause = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("ОЗГ запрещены!");
		totalInfo += "ОЗГ запрещены!";
	}
	else
	{
		DeleteAttribute(pchar, "GenQuest.HunterLongPause");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("ОЗГ разрешены.");
		totalInfo += "ОЗГ разрешены.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F32", 1);
}

string descF33 = "Убрать любой таймер с экрана (по квестам и т.д.)";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	if (CheckAttribute(pchar, "showTimer"))
	{
		DeleteAttribute(pchar, "showTimer");
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Таймер был убран!");
		totalInfo += "Таймер был убран!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Нет никакого таймера - убирать нечего...");
		totalInfo += "Нет никакого таймера - убирать нечего...";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F33", 1);
}

string descF34 = "Вкл \ откл у лоточников все предметы в продаже";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllItemsInTrade"))
	{
		pchar.CSM.AllItemsInTrade = true;
		totalInfo += "У лоточников в продаже появились все предметы!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllItemsInTrade");
		totalInfo += "Ассортимент товаров у лоточников выставлен по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F34", 1);
}

string descF35 = "Вкл \ откл все корабли в продаже на верфях";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllShipsInTrade"))
	{
		pchar.CSM.AllShipsInTrade = true;
		totalInfo += "У верфистов в продаже появились все корабли!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllShipsInTrade");
		totalInfo += "Ассортимент кораблей у верфистов выставлен по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F35", 1);
}

string descF36 = "Вкл \ откл отображение счетчика активированных опций в ЧМ";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff"))
	{
		pchar.CSM.CMStatsOff = true;
		Log_info("Отображение счётчика активированных опций в ЧМ убрано.");
		totalInfo += "Отображение счётчика активированных опций в ЧМ убрано.";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CMStatsOff");
		Log_info("Счётчик активированных опций в ЧМ возвращен.");
		totalInfo += "Счётчик активированных опций в ЧМ возвращен.";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F36", 1);
}

// by Sticksъ -->
string descF37 = "Изменить направление ветра на море (сбрасывается каждый игровой час)";
void CalculateInfoDataF37()
{
    totalInfo = "#37 " + descF37;
	CommonActions();
	if (!IsEntity(&worldMap))
	{
		// 0Pi или 2Pi - южный ветер, 0.5Pi - западный, Pi - северный, 1.5Pi - восточный
		Weather.Wind.Angle = stf(Weather.Wind.Angle) + 0.785; // каждый раз добавляем четверть пи
		if (stf(Weather.Wind.Angle) > 6.28)
			Weather.Wind.Angle = 0;
		pchar.wind.angle = Weather.Wind.Angle;
		fWeatherAngle = stf(Weather.Wind.Angle);

		string windDirection;
		float cut = 0.25; // для более точного попадания в диапазон

		if (fWeatherAngle > 5.495 + cut || fWeatherAngle < 0.785 - cut)
		{
			windDirection = "южный";
			SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\0_n.tga");
		}
		else
		{
			if (fWeatherAngle > 0.0 + cut && fWeatherAngle < 1.57 - cut)
			{
				windDirection = "юго-западный";
				SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\1_ne.tga");
			}
			else
			{
				if (fWeatherAngle > 0.78 + cut && fWeatherAngle < 2.355 - cut)
				{
					windDirection = "западный";
					SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\2_e.tga");
				}
				else
				{
					if (fWeatherAngle > 1.57 + cut && fWeatherAngle < 3.14 - cut)
					{
						windDirection = "северо-западный";
						SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\3_se.tga");
					}
					else
					{
						if (fWeatherAngle > 2.355 + cut && fWeatherAngle < 3.925 - cut)
						{
							windDirection = "северный";
							SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\4_s.tga");
						}
						else
						{
							if (fWeatherAngle > 3.14 + cut && fWeatherAngle < 4.71 - cut)
							{
								windDirection = "северо-восточный";
								SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\5_sw.tga");
							}
							else
							{
								if (fWeatherAngle > 3.925 + cut && fWeatherAngle < 5.495 - cut)
								{
									windDirection = "восточный";
									SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\6_w.tga");
								}
								else
								{
									if (fWeatherAngle > 4.71 + cut && fWeatherAngle < 6.28 - cut)
									{
										windDirection = "юго-восточный";
										SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\7_nw.tga");
									}
								}
							}
						}
					}
				}
			}
		}
		iSND = PlaySound("Interface\abordage_wining.wav");
		Log_info("Ветер переменился на " + windDirection + "!");
		totalInfo += "Ветер переменился на " + windDirection + "!" + NewStr() + "На компасе ниже, красным цветом, указано направление ветра." + NewStr() + "Автор: Sticksъ";
	}
    else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("На глобальной карте не работает...");
		totalInfo += "На глобальной карте не работает...";
	}
	totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM9.F37", 1);
}
// by Sticksъ <--

string descF38 = "Сильный ветер на море (сбрасывается каждый игровой час)";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	if (!IsEntity(&worldMap))
	{
		Weather.Wind.Speed = 16.0;
		pchar.wind.speed = Weather.Wind.Speed;
		fWeatherSpeed = stf(Weather.Wind.Speed);
		iSND = PlaySound("Interface\abordage_wining.wav");
		Log_info("Порывы ветра на море составляют: " + stf(fWeatherSpeed));
		totalInfo += "Порывы ветра на море составляют: " + stf(fWeatherSpeed);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("На глобальной карте не работает...");
		totalInfo += "На глобальной карте не работает...";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F35", 1);
}

string descF39 = "Отключить партиклы в локации (эффекты огня, дыма и т.д., включатся после перезагрузки)";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	PauseParticles(true);
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "Партиклы в текущей локации отключены!" + NewStr() + "Они снова заработают со сменой локации." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F39", 1);
}

string descF40 = "Открыть все острова, выход в море, быстрые переходы и т.д. (ИСПОЛЬЗОВАТЬ В КРАЙНИХ СЛУЧАЯХ!)";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	bDisableFastReload = false;
	bQuestDisableMapEnter = false;
	chrDisableReloadToLocation = false;
	bDisableCharacterMenu = false;
	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);
	DeleteAttribute(pchar, "questTemp.Sharlie.Lock");
	DeleteAttribute(pchar, "GenQuest.CannotWait");
	// DeleteAttribute(pchar, "NoNavyPenalty");
	int i = FindColony("Fortfrance");
	DeleteAttribute(colonies[i], "DontSetShipInPort");
	for (i=0; i<MAX_ISLANDS; i++)
	{
		if (!CheckAttribute(&Islands[i], "hidden")) Island_SetReloadEnableGlobal(Islands[i].id, true);
	}
	Log_info("Все ограничения сняты!");
	totalInfo += "Все ограничения сняты!" + back2totalInfo;
	iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F40", 1);
}

string descF41 = "Вкл \ откл удаление трупов только при перезагрузке локаций";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();

	if (!CheckAttribute(pchar, "CSM.DontClearDead"))
	{
		pchar.CSM.DontClearDead = true;
		totalInfo += "Трупы всех павших бойцов не будут исчезать со временем!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.DontClearDead");
		totalInfo += "Процесс удаления трупов выставлен по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F41", 1);
}

string descF42 = "Сменить погоду на следующую (+1 час)";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	CSM_LoadNextWeather();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "Погода изменена!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F42", 1);
}

string descF43 = "Сменить погоду на предыдущую (-1 час)";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	CSM_LoadPrevWeather();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "Погода изменена!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F43", 1);
}

string descF44 = "Сброс счетчика убитых пиратов в поселениях";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	if (sti(pchar.GenQuest.Piratekill) > 0)
	{
		pchar.GenQuest.Piratekill = 0;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Счётчик убитых пиратов в поселениях сброшен до 0!");
		totalInfo += "Счётчик убитых пиратов в поселениях сброшен до 0!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Счёт убитым пиратам в поселениях равен 0, сбрасывать его незачем.");
		totalInfo += "Счёт убитым пиратам в поселениях равен 0, сбрасывать его незачем.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F44", 1);
}

string descF45 = "Пустить Золотой флот";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	isGoldFleet = true;
	GoldMonth = XI_ConvertString("target_month_" + GetAddingDataMonth(0, 0, 0));
	AddTemplRumour("Init_GoldFleet", id_counter + 1);
	StartGoldFleet("");
	PlayStereoSound("notebook");
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	Log_info("Золотой флот вышел из Порто Белло (Мэйн) и взял курс на Гавану (Куба)!");
	totalInfo += "Золотой флот вышел из Порто Белло (Мэйн) и взял курс на Гавану (Куба)!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F45", 1);
}

string descF46 = "Вернуть камеру к герою, если после диалога она за кого-то ''зацепилась''";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	if (CheckAttribute(pchar, "chr_ai.type") && pchar.chr_ai.type == LAI_TYPE_PLAYER)
	{
		locCameraTarget(pchar);
		locCameraFollow();
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Камера возвращена за спину главного героя!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Главный герой не находится под управлением игрока.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F46", 1);
}

string descF47 = "Убрать \ поставить корабли охраны у Тортуги";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	ref rXep;
	string sLogA = "Изменение вступит в силу при смене суток.";
	string sLogB = "Корабли охраны у Тортуги ";
	rXep = characterFromId("Tortuga_Mayor");
	if (rXep.name == "Франсуа" && rXep.lastname == "Левассер")
	{
		if (CheckAttribute(pchar, "questTemp.Sharlie.DelTerGuard"))
		{
			DeleteAttribute(pchar, "questTemp.Sharlie.DelTerGuard");
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sLogB + "возвращены обратно.");
			Log_info(sLogA);
			totalInfo += sLogB + "возвращены обратно." + NewStr() + sLogA;
		}
		else
		{
			pchar.questTemp.Sharlie.DelTerGuard = "true";
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sLogB + "убраны!");
			Log_info(sLogA);
			totalInfo += sLogB + "убраны!" + NewStr() + sLogA;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "В данной опции уже нет надобности!";
		if (!CheckAttribute(pchar, "questTemp.Sharlie.DelTerGuard")) pchar.questTemp.Sharlie.DelTerGuard = "true";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F47", 1);
}

string descF48 = "Показывать \ не показывать логи по квестам, получению опыта и развитию свободных кэпов";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	if (!bExpLogShow || !bPGGLogShow || !bQuestLogShow)
	{
		bExpLogShow = true; bPGGLogShow = true; bQuestLogShow = true;
		totalInfo += "Включено ведение логов по квестам, получаемому опыту и развитию свободных капитанов!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		bExpLogShow = false; bPGGLogShow = false; bQuestLogShow = false;
		totalInfo += "Отключено ведение логов по квестам, получаемому опыту и развитию свободных капитанов.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F48", 1);
}

string descF49 = "Вкл \ откл альтернативное море";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();

	string message = "Вариант моря изменен на ";
	string sMod = "\n\nОпция заточена под текстуры неба от Sergg (мод SkyBox).\nНа 'ваниле' картинка может отличаться от задуманной.";

	if (!CheckAttribute(pchar, "CSM.WavesType"))
	{
		pchar.CSM.WavesType = -1; // Размер волн, плотность тумана, и прочее зависят от силы ветра
		SM_WavesEnable();
		message = message + "модифицированный.\nВолны соответствуют силе ветра." + sMod;
	}
	else
	{
		int type = pchar.CSM.WavesType;
		type++;
		pchar.CSM.WavesType = type;
		
		if (type > SM_TotalWaves)
		{
			DeleteAttribute(pchar, "CSM.WavesType");
			SM_WavesDisable();
			message = message + "оригинальный.";
		}
		else
		{
			message = message + "модифицированный.\nВолны не зависят от силы ветра. ";
			if (type == 0) // Случайный тип волны при генерациях окружения
				message = message + "Меняются при смене локаций.";
			else
				message = message + "Тип волны : " + type + ".";
			message += sMod;
		}

	}

	Whr_UpdateWeather();

	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += message + "\n\nАвтор: Sticksъ" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F49", 1);
}

string descF50 = "Вкл \ откл больше бандитов, индейцев в джунглях, драчунов в тавернах и т.д.";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();

	string message = "";

	if (!CheckAttribute(pchar, "CSM.MoreBands"))
	{
		pchar.CSM.MoreBands = true;
		message = message + "Повышенное количество противников.";
		iSND = PlaySound("Types\warrior02.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MoreBands");
		message = message + "Обычное количество противников.";
		iSND = PlaySound("Types\warrior_dam02.wav");
	}
	Log_info(message);
	totalInfo += message + NewStr() + "Автор: Sticksъ" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F50", 1);
}

string descF51 = "Вкл \ откл дипломатических агентов в пиратских тавернах";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.RelationAgent"))
	{
		pchar.CSM.RelationAgent = true;
		totalInfo += "В пиратских тавернах будут встречаться дипломатические агенты!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.RelationAgent");
		totalInfo += "Дипломатические агенты в пиратских тавернах отключены.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F51", 1);
}

string descF52 = "Вкл \ откл торговлю личными вещами в магазинах пиратов";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.Merchants"))
	{
		pchar.CSM.Merchants = true;
		totalInfo += "В пиратских магазинах можно продавать личные вещи!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.Merchants");
		totalInfo += "В магазинах пиратов нельзя будет продать личные вещи.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F52", 1);
}

string descF53 = "Урегулировать конфликты со всеми жителями Острова Справедливости";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();

	bool bA = CheckAttribute(loadedLocation, "type") && loadedLocation.type == "LostShipsCity";
	bool bB = CheckAttribute(loadedLocation, "type.LSC") && loadedLocation.type.LSC == true;
	bool bC = CheckAttribute(loadedLocation, "islandId") && loadedLocation.islandId == "LostShipsCity";

	if (bA || bB || bC)
	{
		pchar.GenQuest.NarvalConflict = 0;
		pchar.GenQuest.RivadosConflict = 0;
		pchar.GenQuest.SharkConflict = 0;
		pchar.GenQuest.CitizenConflict = 0;
		DeleteAttribute(pchar, "GenQuest.CitizenConflict");
		DeleteAttribute(pchar, "GenQuest.NarvalConflict");
		DeleteAttribute(pchar, "GenQuest.RivadosConflict");
		DeleteAttribute(pchar, "GenQuest.SharkConflict");
		LAi_group_SetRelation("LSC_NARVAL", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с нарвалами
		LAi_group_SetRelation("LSC_RIVADOS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с ривадос
		LAi_group_SetRelation("LSC_SHARK", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с пиратами
		LSC_OpenSanAvgustinDoors();//открыть вход в резиденцию
		LSC_OpenTartarusDoors();//открыть вход в тюрьму
		LocatorReloadEnterDisable("LostShipsCity_town", "reload33", false);// открыть вход к клану ривадос
		LocatorReloadEnterDisable("LostShipsCity_town", "reload48", false);// открыть вход к клану нарвал
		WaitDate("", 0, 0, 0, 0, 5);
		totalInfo += "Все конфликты с обитателями Острова Справедливости улажены!" + NewStr() + "Автор: Krizis";
		iSND = csmSound("Ahha", 0);
	}
	else
	{
		iSND = csmSound("WTF", 0);
		totalInfo += "Вы должны находиться на Острове Справедливости!";
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F53", 1);
}

string descF54 = "Главного героя";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		NullCharacterGoods(pchar);
		RecalculateCargoLoad(pchar);
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("Трюм Вашего корабля полностью очищен, кэп!");
		totalInfo += "Трюм Вашего корабля полностью очищен, кэп!";
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F54", 1);
}

string descF55 = "1-го компаньона";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 1-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 1);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			Log_info(sNoCopms);
			totalInfo += sNoCopms;
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F55", 1);
}

string descF56 = "2-го компаньона";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 2-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 2-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 2);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F56", 1);
}

string descF57 = "3-го компаньона";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 3-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 3-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 3);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F57", 1);
}

string descF58 = "4-го компаньона";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 4-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 4-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 4);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F58", 1);
}

string descF59 = "5-го компаньона";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 5-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 5-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 5);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F59", 1);
}


string descF60 = "6-го компаньона";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 6-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 6-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 6);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F60", 1);
}


string descF61 = "7-го компаньона";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "У Вас нет 7-го компаньона...";
	string sNoCopms = "У Вас нет компаньонов...";
	string sDone = "Трюм корабля 7-го компаньона полностью очищен!";
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		icn = GetCompanionIndex(pchar, 7);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			NullCharacterGoods(sld);
			RecalculateCargoLoad(sld);
			iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
			Log_info(sDone);
			totalInfo += sDone;
		}
		else
		{
			if (GetCompanionQuantity(pchar) > 1)
			{
				Log_info(sNoCopm);
				totalInfo += sNoCopm;
			}
			else
			{
				Log_info(sNoCopms);
				totalInfo += sNoCopms;
			}
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
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
	Statistic_AddValue(PChar, "Cheats.CSM9.F61", 1);
}

string descF62 = "! ПУСТО !";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F63", 1);
}

string descF63 = "! ПУСТО !";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F63", 1);
}
string descF64 = "! ПУСТО !";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F64", 1);
}

string descF65 = "! ПУСТО !";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F65", 1);
}


string descF66 = "! ПУСТО !";
void CalculateInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F66", 1);
}
string descF67 = "! ПУСТО !";
void CalculateInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F67", 1);
}
string descF68 = "! ПУСТО !";
void CalculateInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F68", 1);
}

string descF69 = "! ПУСТО !";
void CalculateInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F69", 1);
}

string descF70 = "! ПУСТО !";
void CalculateInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F70", 1);
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
			sHeader = "Описание меню 'Прочее'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Прочее' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Прочее'";
			sText1 = "Перезапуск меню 'Прочее'";
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
