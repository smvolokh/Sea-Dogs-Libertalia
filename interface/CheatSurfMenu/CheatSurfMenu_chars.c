
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Персонаж(и)
	Основано на меню дебаггера от boal
	11.06.19
*/

int iSND = 0;

bool bShowArrows = false;
bool bNoSound = false;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Персонаж' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sRank = "Текущий уровень: ";
string sMyHP = "Текущее значение HP: ";
string sValue = "Текущее значение: ";
string sNation = "Текущая нация главного героя - ";
string sRelation = "Состояние отношений между нациями на архипелаге: ";
string sRelEng = "Отношения с Англией: ";
string sRelHol = "Отношения с Голландией: ";
string sRelFra = "Отношения с Францией: ";
string sRelSpa = "Отношения с Испанией: ";
string sRepEng = "Репутация героя у Англии: ";
string sRepHol = "Репутация героя у Голландии: ";
string sRepFra = "Репутация героя у Франции: ";
string sRepSpa = "Репутация героя у Испании: ";
string sOfficerF = " зачислена в команду!";
string sOfficerM = " зачислен в команду!";
string sOfficerX = " зачислены в команду!";
string sClon = " - на квесты никак не повлияет!";
string sModelA = "Выбран #1 вариант модели ";
string sModelB = "Выбран #2 вариант модели ";
string sModelC = "Выбран #3 вариант модели ";
string sModelD = "Выбран #4 вариант модели ";
string sNextC = "Следующий выбор: ";
string sModel = "Выбранная модель: ";
string sSuitY = "Есть костюмы: да";
string sSuitN = "Есть костюмы: нет";
string sMushY = "Пользуется мушкетом: да";
string sMushN = "Пользуется мушкетом: нет";
string sMushO = "\n\nЭтот офицер умеет пользоваться мушкетом.";
string sFaces = "interfaces\portraits\256\face_";
string sModer = "Автор(ы) мода: ";
string sWpnOff = "\nДля корректной работы функции спрячьте шпагу в ножны, дождитесь окончания сопутствующей анимации и лишь потом меняйте модель!";
string sArrows = " (используйте стрелочки у портрета, для выбора следующего или предыдущего варианта)";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_chars";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(0); // Warship. Статистика - сколько читов юзали
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

void OnStartEndActions()
{
	if (!CheckAttribute(pchar, "CSM.Welcome")) pchar.CSM.Welcome = true;
	if (!CheckAttribute(pchar, "CSM.AddOfficersVar")) pchar.CSM.AddOfficersVar = 0;
	if (!CheckAttribute(pchar, "CSM.ChangeModelM")) pchar.CSM.ChangeModelM = 0;
	if (!CheckAttribute(pchar, "CSM.ChangeModelW")) pchar.CSM.ChangeModelW = 0;
	DeleteAttribute(pchar, "CSM.ArrowsType");
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
					"Имя ГГ и NPC меняйте в интерфейсе 'Персонажи' (F2), дважды кликнув по имени над портретом в центре" + NewStr() +
					"----------" + NewStr() +
					"********** ГЛАВНЫЙ ГЕРОЙ **********" + NewStr() +
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"\n\n********** НАЦИИ **********" + NewStr() +
					"< 22 > " + descF22 + NewStr() +
					"---------- отношения между нациями ----------" + NewStr() +
					"< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() +
					"< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() +
					"< 27 > " + descF27 + NewStr() +
					"---------- прочее ----------" + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() +
					"< 30 > " + descF30 + NewStr() + "< 31 > " + descF31 + NewStr() +
					"\n\n********** НАГРАДА ЗА ГОЛОВУ **********" + NewStr() +
					"---------- увеличить ----------" + NewStr() +
					"< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() + "< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() +
					"---------- уменьшить ----------" + NewStr() +
					"< 36 > " + descF36 + NewStr() + "< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"\n\n********** ДОБАВИТЬ В ОФИЦЕРЫ **********" + NewStr() +
					"< 40 > " + descF40 + GetAddOfficersVar(false) + NewStr() +
					"< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() + "< 43 > " + descF43 + NewStr() +
					"< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() + "< 46 > " + descF46 + NewStr() +
					"< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() + "< 49 > " + descF49 + NewStr() +
					"< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() + "< 52 > " + descF52 + NewStr() +
					"< 53 > " + descF53 + NewStr() + "< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + NewStr() +
					"< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() + "< 58 > " + descF58 + NewStr() +
					"< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() + "< 61 > " + descF61 + NewStr() +
					"< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() +
					"\n\n********** МОДЕЛИ ГГ **********" + NewStr() +
					"< 65 > " + descF65 + NewStr() + "< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() +
					"< 68 > " + descF68 + NewStr() + "< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
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
	switch (nodName)
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
		case "B_ClickLeft": if (comName == "activate" || comName == "click") {csmArrowLeft();} break;
		case "B_ClickRight": if (comName == "activate" || comName == "click") {csmArrowRight();} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(0); // Статистика по читам
}

string descF1 = "Включить \ отключить бессмертие";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	string sTXT = "Бессмертие протагониста и его корабля ";
	if (LAi_IsImmortal(pchar))
	{
		LAi_SetImmortal(pchar, 0);
		SM_DisableSailsAutorepairing();
		iSND = PlaySound("_CheatSurfMenu_\GodModeOff.wav");
		ClearAllLogStrings();
		Log_info(sTXT + "отключено");
		Log_info("Автопочинка парусов и мачт отключена");
		totalInfo += sTXT + "отключено.\nАвтопочинка парусов и мачт отключена.";
	}
	else
	{
		LAi_SetImmortal(pchar, 1);
		SM_EnableSailsAutorepairing();
		iSND = PlaySound("_CheatSurfMenu_\GodModeOn.wav");
		ClearAllLogStrings();
		Log_info(sTXT + "включено!");
		Log_info("Автопочинка парусов и мачт включена");
		totalInfo += sTXT + "включено!\nАвтопочинка парусов и мачт включена.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F1", 1);
}

string descF2 = "Получить 1 000 000 песо";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	pchar.money = sti(pchar.money) + 1000000;
	Log_info("Добавлено 1 000 000 песо!");
	totalInfo += "Добавлено 1 000 000 песо!" + NewStr() + "Всего денег у протагониста: " + sti(pchar.money) + back2totalInfo;
	iSND = PlaySound("_CheatSurfMenu_\Gold.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F2", 1);
}

string descF3 = "Получить 1 000 дублонов";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	AddItems(pchar, "gold_dublon", 1000);
	Log_info("Добавлено 1 000 дублонов!");
	totalInfo += "Добавлено 1 000 дублонов!" + NewStr() + "Кол-во дублонов у протагониста: " + sti(pchar.dublon) + back2totalInfo;
	iSND = PlaySound("Interface\took_item.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F3", 1);
}

string descF4 = "Повысить уровень";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	if (sti(pchar.rank) > 99) { pchar.rank = 99; }
	int iErs = GetCharacterSPECIALSimple(pchar, SPECIAL_E);
	int iRet = makeint(2 + iErs * 0.55 + 0.5);
	string sHP = "Кол-во HP увеличилось на ";
	string sLvlUp = "Уровень протагониста повышен!";
	if (sti(pchar.rank) < 99)
	{
		pchar.rank = sti(pchar.rank) + 1;
		if (CheckCharacterPerk(pchar, "HPPlus")) { iRet = iRet + 1; }
		pchar.chr_ai.hp_max = stf(pchar.chr_ai.hp_max) + iRet;
		LAi_SetCurHPMax(pchar);
		Log_info(sLvlUp);
		Log_info(sRank + sti(pchar.rank));
		Log_info(sHP + sti(iRet) + " единиц!");
		Log_info(sMyHP + sti(pchar.chr_ai.hp));
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sLvlUp + NewStr() + sRank + sti(pchar.rank) + NewStr() + sHP + sti(iRet) + " единиц!" + NewStr() + sMyHP + sti(pchar.chr_ai.hp);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		Log_info("Уровень протагониста достиг максимального значения!");
		totalInfo += "Уровень протагониста достиг максимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F4", 1);
}

string descF5 = "Понизить уровень";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	if (sti(pchar.rank) < 1) { pchar.rank = 1; }
	int iErs = GetCharacterSPECIALSimple(pchar, SPECIAL_E);
	int iRet = makeint(2 + iErs * 0.55 + 0.5);
	string sHP = "Кол-во HP уменьшилось на ";
	string sLvlUp = "Уровень протагониста понижен.";
	if (sti(pchar.rank) > 1)
	{
		pchar.rank = sti(pchar.rank) - 1;
		if (CheckCharacterPerk(pchar, "HPPlus")) { iRet = iRet + 1; }
		pchar.chr_ai.hp_max = stf(pchar.chr_ai.hp_max) - iRet;
		LAi_SetCurHPMax(pchar);
		Log_info(sLvlUp);
		Log_info(sRank + sti(pchar.rank));
		Log_info(sHP + sti(iRet) + " единиц");
		Log_info(sMyHP + sti(pchar.chr_ai.hp));
		totalInfo += sLvlUp + NewStr() + sRank + sti(pchar.rank) + NewStr() + sHP + sti(iRet) + " единиц." + NewStr() + sMyHP + sti(pchar.chr_ai.hp);
		if (pchar.sex == "man") iSND = PlaySound("_CheatSurfMenu_\Decrease_Rank.wav");
		else iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		Log_info("Уровень протагониста достиг минимального значения!");
		totalInfo += "Уровень протагониста достиг минимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F5", 1);
}

string descF6 = "Повысить запас HP";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	string sHP = "Кол-во HP протагониста увеличилось на ";
	string sHPMax = "Кол-во HP протагониста достигло максимального значения!";
	if (sti(pchar.chr_ai.hp_max) < 999)
	{
		pchar.chr_ai.hp_max = stf(pchar.chr_ai.hp_max) + 5;
		if (sti(pchar.chr_ai.hp_max) > 999) pchar.chr_ai.hp_max = 999;
		LAi_SetCurHPMax(pchar);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sHP + "5 единиц!");
		Log_info(sMyHP + sti(pchar.chr_ai.hp_max));
		totalInfo += sHP + "5 единиц!" + NewStr() + sMyHP + sti(pchar.chr_ai.hp_max);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		Log_info(sHPMax);
		Log_info(sMyHP + sti(pchar.chr_ai.hp_max));
		totalInfo += sHPMax + NewStr() + sMyHP + sti(pchar.chr_ai.hp_max);
	}
	totalInfo += back2totalInfo;
	// ProcessCancelExit();
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM1.F6", 1);
}

string descF7 = "Понизить запас HP";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	string sHP = "Кол-во HP протагониста уменьшилось на ";
	string sHPMin = "Дальше уменьшать не стоит!";
	if (sti(pchar.chr_ai.hp_max) > 50)
	{
		pchar.chr_ai.hp_max = stf(pchar.chr_ai.hp_max) - 5;
		if (sti(pchar.chr_ai.hp_max) < 50) pchar.chr_ai.hp_max = 50;
		LAi_SetCurHPMax(pchar);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sHP + "5 единиц");
		Log_info(sMyHP + sti(pchar.chr_ai.hp_max));
		totalInfo += sHP + "5 единиц." + NewStr() + sMyHP + sti(pchar.chr_ai.hp_max);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		Log_info(sHPMin);
		Log_info(sMyHP + sti(pchar.chr_ai.hp_max));
		totalInfo += sHPMin + NewStr() + sMyHP + sti(pchar.chr_ai.hp_max);
	}
	totalInfo += back2totalInfo;
	// ProcessCancelExit();
	SetFormatedText("INFO_TEXT", totalInfo);
	Statistic_AddValue(PChar, "Cheats.CSM1.F7", 1);
}

string descF8 = "Повысить авторитет";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	pchar.reputation.authority = sti(pchar.reputation.authority) + 10;
	if (sti(pchar.reputation.authority) > 100)
	{
		pchar.reputation.authority = 100;
		totalInfo += "Авторитет протагониста достиг максимального значения!";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.authority));
	totalInfo += NewStr() + sValue + sti(pchar.reputation.authority) + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F8", 1);
}

string descF9 = "Понизить авторитет";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	pchar.reputation.authority = sti(pchar.reputation.authority) - 10;
	if (sti(pchar.reputation.authority) < 1)
	{
		pchar.reputation.authority = 1;
		totalInfo += "Авторитет протагониста достиг минимального значения!";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.authority));
	totalInfo += NewStr() + sValue + sti(pchar.reputation.authority) + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F9", 1);
}

string descF10 = "Повысить репутацию";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	string sRepN;
	pchar.reputation.nobility = sti(pchar.reputation.nobility) + 10;
	if (sti(pchar.reputation.nobility) > 100)
	{
		pchar.reputation.nobility = 100;
		totalInfo += "Репутация протагониста достигла максимального значения!";
	}
	sRepN = XI_ConvertString(GetReputationComplexName(sti(pchar.reputation.nobility), "nobility"));
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.nobility));
	totalInfo += NewStr() + sValue + sRepN + NewStr() + "Числовое значение: " + sti(pchar.reputation.nobility) + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F10", 1);
}

string descF11 = "Понизить репутацию";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	string sRepN;
	pchar.reputation.nobility = sti(pchar.reputation.nobility) - 10;
	if (sti(pchar.reputation.nobility) < 1)
	{
		pchar.reputation.nobility = 1;
		totalInfo += "Репутация протагониста достигла минимального значения!";
	}
	sRepN = XI_ConvertString(GetReputationComplexName(sti(pchar.reputation.nobility), "nobility"));
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.nobility));
	totalInfo += NewStr() + sValue + sRepN + NewStr() + "Числовое значение: " + sti(pchar.reputation.nobility) + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F11", 1);
}

string descF12 = "Повысить известность";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	pchar.reputation.fame = sti(pchar.reputation.fame) + 10;
	string sRepF = XI_ConvertString(GetReputationComplexName(sti(pchar.reputation.fame), "fame"));
	if (sti(pchar.reputation.fame) > 100)
	{
		pchar.reputation.fame = 100;
		totalInfo += "Известность протагониста достигла максимального значения!";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.fame));
	totalInfo += NewStr() + sValue + sRepF + NewStr() + "Числовое значение: " + sti(pchar.reputation.fame) + "\n\nP.S.: Параметр 'Известность' в игре бесполезен.\nКроме как в качестве текстовой надписи в меню персонажа, нигде не используется и ни на что не влияет.";
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F12", 1);
}

string descF13 = "Понизить известность";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	pchar.reputation.fame = sti(pchar.reputation.fame) - 10;
	string sRepF = XI_ConvertString(GetReputationComplexName(sti(pchar.reputation.fame), "fame"));
	if (sti(pchar.reputation.fame) < 1)
	{
		pchar.reputation.fame = 1;
		totalInfo += "Известность протагониста достигла минимального значения!";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info(sValue + sti(pchar.reputation.fame));
	totalInfo += NewStr() + sValue + sRepF + NewStr() + "Числовое значение: " + sti(pchar.reputation.fame) + "\n\nP.S.: Параметр 'Известность' в игре бесполезен.\nКроме как в качестве текстовой надписи в меню персонажа, нигде не используется и ни на что не влияет.";
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F13", 1);
}

string descF14 = "Выставить переносимый вес для ГГ на 10 000 \ по умолчанию";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	string sWeight = "Максимальный переносимый вес ";
	if (!CheckAttribute(pchar, "CSM.CargoTank"))
	{
		pchar.CSM.CargoTank = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sWeight + "увеличен до 10 000!");
		totalInfo += sWeight + "увеличен до 10 000!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CargoTank");
		iSND = PlaySound("_CheatSurfMenu_\Sign.wav");
		Log_info(sWeight + "установлен по умолчанию.");
		totalInfo += sWeight + "установлен по умолчанию.";
	}
	CheckAndSetOverloadMode(GetMainCharacter());
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F14", 1);
}

string descF15 = "Выставить переносимый вес для абордажников на 10 000 \ по умолчанию";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	ref sld;
	int iOff, iOffn;
	bool bOff = false;
	string sWeight = "Максимальный переносимый вес абордажников ";
	if (!CheckAttribute(pchar, "CSM.CargoTankFighters"))
	{
		pchar.CSM.CargoTankFighters = true;
		for (iOff = 1; iOff < 4; iOff++)
		{
			iOffn = GetOfficersIndex(pchar, iOff);
			if (iOffn != -1)
			{
				sld = GetCharacter(iOffn);
				sld.CSM.CargoTank = true;
				bOff = true;
				CheckAndSetOverloadMode(sld);
			}
		}
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CargoTankFighters");
		iSND = PlaySound("_CheatSurfMenu_\Sign.wav");
		totalInfo += sWeight + "установлен по умолчанию.";
	}
	if (bOff)
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sWeight + "увеличен до 10 000!";
	}
	else
	{
		for (iOff = 0; iOff < GetPassengersQuantity(pchar); iOff++)
		{
			iOffn = GetPassenger(pchar, iOff);
			if (iOffn != -1)
			{
				sld = GetCharacter(iOffn);
				DeleteAttribute(sld, "CSM.CargoTank");
			}
		}
		if (CheckAttribute(pchar, "CSM.CargoTankFighters"))
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			totalInfo += "У вас нет абордажников!";
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F15", 1);
}

string descF16 = "Получить стартовые бонусы всех типов героя";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	int i;
	if (!CheckAttribute(pchar, "CSM.GotAllHidePerks"))
	{
		// Нахер всю эту писанину
		pchar.CSM.GotAllHidePerks = true;
		for (i = 1; i <= 5; i++)
		{
			if (!CheckCharacterPerk(pchar, "HT" + i)) { SetCharacterPerk(pchar, "HT" + i); }
SetCharacterPerk(pchar, "Trustworthy");
SetCharacterPerk(pchar, "SeaWolf");
pchar.CSM.FreeSmuggling = true;
pchar.CSM.NoCannonsBoom = true;
pchar.CSM.TreasureMapTrader = true;	
pchar.questTemp.ShipCapellan = "true";
pchar.questTemp.ShipCapellan.id = chr.id;
pchar.questTemp.ShipCapellan.Yes = "true";
pchar.questTemp.Inquisitor.AveMaria = "true"; 
		}
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Получены бонусы всех прочих типов героя!");
		totalInfo += "Получены бонусы всех прочих типов героя!";
	}
	else
	{
		// На всякий ^^
		for (i = 1; i <= 4; i++)
		{
			if (!CheckCharacterPerk(pchar, "HT" + i)) { SetCharacterPerk(pchar, "HT" + i); }
SetCharacterPerk(pchar, "Trustworthy");
		}
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Все бонусы прочих типов героя уже получены.");
		totalInfo += "Все бонусы прочих типов героя уже получены.";
	}
	if (!CheckCharacterPerk(pchar, "Energaiser")) { SetCharacterPerk(pchar, "Energaiser"); }
	if (CheckAttribute(pchar, "MapsAtlasCount"))
	{
		if (sti(pchar.MapsAtlasCount) == MAPS_IN_ATLAS && !CheckCharacterPerk(pchar, "MapMaker"))
		{
			SetCharacterPerk(pchar, "MapMaker");
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F16", 1);
}

string descF17 = "Протрезветь или убрать головокружение";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (CheckAttribute(pchar, "chr_ai.drunk") || CheckAttribute(pchar, "questTemp.Rum") || CheckAttribute(pchar, "GenQuest.CamShuttle"))
	{
		LAi_SetAlcoholNormal(pchar);
		iSND = PlaySound("Voice\Russian\pirat_guard_1.wav");
		Log_info(pchar.name + " протрезвел" + GetSexPhrase("", "а") + "!");
		totalInfo += pchar.name + " протрезвел" + GetSexPhrase("", "а") + "!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(pchar.name + " не пьян" + GetSexPhrase("", "а") + ".");
		totalInfo += pchar.name + " не пьян" + GetSexPhrase("", "а") + ".";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F17", 1);
}

string descF18 = "Сменить пол";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	string sHSex = "Пол главного персонажа - ";
	if (pchar.sex != "man" && pchar.sex != "woman") pchar.sex = "man";
	switch (pchar.sex)
	{
		case "man":
			pchar.sex = "woman";
			iSND = PlaySound("Voice\Russian\whore_beatrice_" + (rand(1) + 1) + ".wav");
			Log_info(sHSex + "женский.");
			totalInfo += sHSex + "женский.";
		break;
		case "woman":
			pchar.sex = "man";
			iSND = PlaySound("Voice\Russian\whore_blaze_1.wav");
			Log_info(sHSex + "мужской.");
			totalInfo += sHSex + "мужской.";
		break;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F18", 1);
}

// 2do: вынести изменение рожи в интерфейс персонажей по F2
string descF19 = "Изменить портрет (предыдущий вариант)";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	bShowArrows = true;
	pchar.CSM.ArrowsType = 0;
	CreateImage("CSM_ArrowLeft", "icons", "left arrow", 156, 248, 224, 312);
	CreateImage("CSM_ArrowRight", "icons", "right arrow", 416, 248, 484, 312);
	int iFacePic = sti(pchar.FaceId);
	iFacePic--;
	if (iFacePic < 4) iFacePic = 733;
	if (iFacePic == 90) iFacePic = 89;
	if (iFacePic == 193) iFacePic = 176;
	if (iFacePic == 200) iFacePic = 199;
	if (iFacePic == 258) iFacePic = 256;
	if (iFacePic == 280) iFacePic = 278;
	if (iFacePic == 300) iFacePic = 293;
	if (iFacePic == 328) iFacePic = 309;
	if (iFacePic == 333) iFacePic = 332;
	if (iFacePic == 360) iFacePic = 359;
	if (iFacePic == 413) iFacePic = 390;
	if (iFacePic == 490) iFacePic = 425;
	if (iFacePic == 554) iFacePic = 520;
	if (iFacePic == 699) iFacePic = 556;
	if (iFacePic > 733) iFacePic = 4;
	pchar.FaceId = iFacePic;
	if (!bNoSound) iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
	bNoSound = false;
	totalInfo += "# " + sti(pchar.FaceId) + sArrows + "\nПортрет героя изменён!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F19", 1);
}

string descF20 = "Изменить портрет (следующий вариант)";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	bShowArrows = true;
	pchar.CSM.ArrowsType = 0;
	CreateImage("CSM_ArrowLeft", "icons", "left arrow", 156, 248, 224, 312);
	CreateImage("CSM_ArrowRight", "icons", "right arrow", 416, 248, 484, 312);
	int iFacePic = sti(pchar.FaceId);
	iFacePic++;
	if (iFacePic < 4) iFacePic = 4;
	if (iFacePic == 90) iFacePic = 91;
	if (iFacePic == 177) iFacePic = 194;
	if (iFacePic == 200) iFacePic = 201;
	if (iFacePic == 257) iFacePic = 259;
	if (iFacePic == 279) iFacePic = 281;
	if (iFacePic == 294) iFacePic = 301;
	if (iFacePic == 310) iFacePic = 329;
	if (iFacePic == 333) iFacePic = 334;
	if (iFacePic == 360) iFacePic = 361;
	if (iFacePic == 391) iFacePic = 414;
	if (iFacePic == 426) iFacePic = 491;
	if (iFacePic == 521) iFacePic = 555;
	if (iFacePic == 557) iFacePic = 700;
	if (iFacePic > 733) iFacePic = 4;
	pchar.FaceId = iFacePic;
	if (!bNoSound) iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
	bNoSound = false;
	totalInfo += "# " + sti(pchar.FaceId) + sArrows + "\nПортрет героя изменён!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F20", 1);
}

string descF21 = "Вернуть портрет Шарля де Мора";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	if (sti(pchar.FaceId) != 201)
	{
		pchar.FaceId = 201;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Возвращен оригинальный портрет Шарля де Мора!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "Портрет Шарля де Мора не требует восстановления...";
	}
	SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F21", 1);
}

string descF22 = "Сменить нацию протагониста";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	string sNext = "\nСледующий выбор: ";
	string sFlag = "INTERFACES\_CheatSurfMenu_\Flags\flag_";
	switch (sti(pchar.nation))
	{
		case FRANCE:
			pchar.nation = ENGLAND;
			pchar.BaseNation = ENGLAND;
			SetNewPicture("CSMPICTURE", sFlag + "eng.tga");
			iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav");
			Log_info(sNation + "Англия!");
			totalInfo += sNation + "Англия!" + sNext + "Голландия";
		break;
		case ENGLAND:
			pchar.nation = HOLLAND;
			pchar.BaseNation = HOLLAND;
			SetNewPicture("CSMPICTURE", sFlag + "hol.tga");
			iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav");
			Log_info(sNation + "Голландия!");
			totalInfo += sNation + "Голландия!" + sNext + "Испания";
		break;
		case HOLLAND:
			pchar.nation = SPAIN;
			pchar.BaseNation = SPAIN;
			SetNewPicture("CSMPICTURE", sFlag + "spa.tga");
			iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav");
			Log_info(sNation + "Испания!");
			totalInfo += sNation + "Испания!" + sNext + "Береговое братство";
		break;
		case SPAIN:
			pchar.nation = PIRATE;
			pchar.BaseNation = PIRATE;
			SetNewPicture("CSMPICTURE", sFlag + "pir.tga");
			iSND = PlaySound("_CheatSurfMenu_\Nation_Pir.wav");
			Log_info(sNation + "Береговое братство!");
			totalInfo += sNation + "Береговое братство!" + sNext + "Франция";
		break;
		case PIRATE:
			pchar.nation = FRANCE;
			pchar.BaseNation = FRANCE;
			SetNewPicture("CSMPICTURE", sFlag + "fra.tga");
			iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav");
			Log_info(sNation + "Франция!");
			totalInfo += sNation + "Франция!" + sNext + "Англия.";
		break;
	}
	// if (!CheckCharacterPerk(pchar, "Flag" + NationShortName(sti(pchar.nation)))) SetCharacterPerk(pchar, "Flag" + NationShortName(sti(pchar.nation)));
	UpdateRelations();
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F22", 1);
}

string descF23 = "Стандарт";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	SetNationRelations();
	UpdateRelations();
	iSND = PlaySound("_CheatSurfMenu_\Sign.wav");
	Log_info(sRelation + "по умолчанию.");
	totalInfo += sRelation + "по умолчанию." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F23", 1);
}

string descF24 = "Нейтралитет";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	for (int i=0;i<MAX_NATIONS_SQR;i++)
	{
		NationsRelations[i] = RELATION_NEUTRAL;
	}
	SetNationRelation2MainCharacter(ENGLAND, GetNationRelation(sti(pchar.nation), ENGLAND));
	SetNationRelation2MainCharacter(FRANCE,	GetNationRelation(sti(pchar.nation), FRANCE));
	SetNationRelation2MainCharacter(HOLLAND, GetNationRelation(sti(pchar.nation), HOLLAND));
	SetNationRelation2MainCharacter(SPAIN,	GetNationRelation(sti(pchar.nation), SPAIN));
	SetNationRelation2MainCharacter(PIRATE,	GetNationRelation(sti(pchar.nation), PIRATE));
	UpdateRelations();
	iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
	Log_info(sRelation + "нейтралитет.");
	totalInfo += sRelation + "нейтралитет." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F24", 1);
}

string descF25 = "Война";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	for (int i=0;i<MAX_NATIONS_SQR;i++)
	{
		NationsRelations[i] = RELATION_ENEMY;
	}
	SetNationRelation2MainCharacter(ENGLAND, GetNationRelation(sti(pchar.nation), ENGLAND));
	SetNationRelation2MainCharacter(FRANCE,	GetNationRelation(sti(pchar.nation), FRANCE));
	SetNationRelation2MainCharacter(HOLLAND, GetNationRelation(sti(pchar.nation), HOLLAND));
	SetNationRelation2MainCharacter(SPAIN,	GetNationRelation(sti(pchar.nation), SPAIN));
	SetNationRelation2MainCharacter(PIRATE,	GetNationRelation(sti(pchar.nation), PIRATE));
	UpdateRelations();
	iSND = PlaySound("_CheatSurfMenu_\Chaos.wav");
	Log_info(sRelation + "война.");
	totalInfo += sRelation + "война." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F25", 1);
}

string descF26 = "Мир";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	Nations_SetAllFriends();
	UpdateRelations();
	iSND = PlaySound("_CheatSurfMenu_\NationRelationPeace.wav");
	Log_info(sRelation + "мир.");
	totalInfo += sRelation + "мир." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F26", 1);
}

string descF27 = "Альянс против пиратов";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	Nations_SetAllFriends();
	SetNationRelationBoth(ENGLAND, PIRATE, RELATION_ENEMY);
	SetNationRelationBoth(HOLLAND, PIRATE, RELATION_ENEMY);
	SetNationRelationBoth(FRANCE, PIRATE, RELATION_ENEMY);
	SetNationRelationBoth(SPAIN, PIRATE, RELATION_ENEMY);
	UpdateRelations();
	iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
	Log_info(sRelation + "альянс против пиратов.");
	totalInfo += sRelation + "альянс против пиратов." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F27", 1);
}

string descF28 = "Запустить рулетку случайного изменения отношений между нациями";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	DoQuestCheckDelay("Nation_Legend_Map", 0.5);
	iSND = PlaySound("_CheatSurfMenu_\NationRelationChange.wav");
	Log_info("Смена отношений между нациями активирована!");
	totalInfo += "Смена отношений между нациями активирована!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F28", 1);
}

string descF29 = "Максимально хорошие отношения со всеми нациями";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	string sRelE, sRelH, sRelS, sRelF;
	pchar.reputation.enghunter = -100;
	pchar.reputation.frahunter = -100;
	pchar.reputation.holhunter = -100;
	pchar.reputation.spahunter = -100;
	UpdateRelations();
	sRelE = sRelEng + GetNationReputation(pchar, ENGLAND);
	sRelH = sRelHol + GetNationReputation(pchar, HOLLAND);
	sRelS = sRelSpa + GetNationReputation(pchar, SPAIN);
	sRelF = sRelFra + GetNationReputation(pchar, FRANCE);
	iSND = PlaySound("_CheatSurfMenu_\Hero.wav");
	Log_info("Отношения со всеми нациями лучше некуда!");
	totalInfo += sRelE + NewStr() + sRelH + NewStr() + sRelS + NewStr() + sRelF + NewStr() + "Отношения со всеми нациями лучше некуда!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F29", 1);
}

string descF30 = "Максимально плохие отношения со всеми нациями";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	string sRelE, sRelH, sRelS, sRelF;
	pchar.reputation.enghunter = 100;
	pchar.reputation.frahunter = 100;
	pchar.reputation.holhunter = 100;
	pchar.reputation.spahunter = 100;
	UpdateRelations();
	sRelE = sRelEng + GetNationReputation(pchar, ENGLAND);
	sRelH = sRelHol + GetNationReputation(pchar, HOLLAND);
	sRelS = sRelSpa + GetNationReputation(pchar, SPAIN);
	sRelF = sRelFra + GetNationReputation(pchar, FRANCE);
	iSND = PlaySound("_CheatSurfMenu_\FamousPirate.wav");
	Log_info("Отношения со всеми нациями хуже некуда!");
	totalInfo += sRelE + NewStr() + sRelH + NewStr() + sRelS + NewStr() + sRelF + NewStr() + "Отношения со всеми нациями хуже некуда!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F30", 1);
}

string descF31 = "Наладить отношения с контрабандистами и индейцами";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	pchar.questTemp.Contraband.relation = 99;
	pchar.questTemp.Indian.relation = 99;
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info("Отношения с индейцами и контрабандистами предельно хорошие!");
	totalInfo += "Отношения с индейцами и контрабандистами предельно хорошие!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F31", 1);
}

string descF32 = "НЗГ от Англии +10 000";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.enghunter) < 100)
	{
		ChangeCharacterHunterScore(pchar, "enghunter", 10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepEng + GetNationReputation(pchar, ENGLAND);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.enghunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\FamousPirate.wav");
		sRelCurr = sRepEng + GetNationReputation(pchar, ENGLAND);
		Log_info(sRelCurr);
		Log_info("НЗГ от Англии достигла максимального значения.");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.enghunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Англии достигла минимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F32", 1);
}

string descF33 = "НЗГ от Голландии +10 000";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.holhunter) < 100)
	{
		ChangeCharacterHunterScore(pchar, "holhunter", 10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepHol + GetNationReputation(pchar, HOLLAND);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.holhunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\FamousPirate.wav");
		sRelCurr = sRepHol + GetNationReputation(pchar, HOLLAND);
		Log_info(sRelCurr);
		Log_info("НЗГ от Голландии достигла максимального значения.");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.holhunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Голландии достигла минимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F33", 1);
}

string descF34 = "НЗГ от Испании +10 000";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.spahunter) < 100)
	{
		ChangeCharacterHunterScore(pchar, "spahunter", 10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepSpa + GetNationReputation(pchar, SPAIN);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.spahunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\FamousPirate.wav");
		sRelCurr = sRepSpa + GetNationReputation(pchar, SPAIN);
		Log_info(sRelCurr);
		Log_info("НЗГ от Испании достигла максимального значения.");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.spahunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Испании достигла минимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F34", 1);
}

string descF35 = "НЗГ от Франции +10 000";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.frahunter) < 100)
	{
		ChangeCharacterHunterScore(pchar, "frahunter", 10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepFra + GetNationReputation(pchar, FRANCE);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.frahunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\FamousPirate.wav");
		sRelCurr = sRepFra + GetNationReputation(pchar, FRANCE);
		Log_info(sRelCurr);
		Log_info("НЗГ от Франции достигла максимального значения.");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.frahunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Франции достигла минимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F35", 1);
}

string descF36 = "НЗГ от Англии -10 000";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.enghunter) > -100)
	{
		ChangeCharacterHunterScore(pchar, "enghunter", -10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepEng + GetNationReputation(pchar, ENGLAND);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.enghunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
		sRelCurr = sRepEng + GetNationReputation(pchar, ENGLAND);
		Log_info(sRelCurr);
		Log_info("Репутация героя у Англии достигла максимального значения!");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.enghunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Англии достигла максимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F36", 1);
}

string descF37 = "НЗГ от Голландии -10 000";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.holhunter) > -100)
	{
		ChangeCharacterHunterScore(pchar, "holhunter", -10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepHol + GetNationReputation(pchar, HOLLAND);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.holhunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
		sRelCurr = sRepHol + GetNationReputation(pchar, HOLLAND);
		Log_info(sRelCurr);
		Log_info("Репутация героя у Голландии достигла максимального значения!");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.holhunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Голландии достигла максимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F37", 1);
}

string descF38 = "НЗГ от Испании -10 000";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.spahunter) > -100)
	{
		ChangeCharacterHunterScore(pchar, "spahunter", -10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepSpa + GetNationReputation(pchar, SPAIN);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.spahunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
		sRelCurr = sRepSpa + GetNationReputation(pchar, SPAIN);
		Log_info(sRelCurr);
		Log_info("Репутация героя у Испании достигла максимального значения!");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.spahunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Испании достигла максимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F38", 1);
}

string descF39 = "НЗГ от Франции -10 000";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	string sRelCurr;
	if (sti(pchar.reputation.frahunter) > -100)
	{
		ChangeCharacterHunterScore(pchar, "frahunter", -10);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		sRelCurr = sRepFra + GetNationReputation(pchar, FRANCE);
		Log_info(sRelCurr);
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.frahunter) + NewStr() + sRelCurr;
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
		sRelCurr = sRepFra + GetNationReputation(pchar, FRANCE);
		Log_info(sRelCurr);
		Log_info("Репутация героя у Франции достигла максимального значения!");
		totalInfo += "Числовое значение НЗГ: " + sti(pchar.reputation.frahunter) + NewStr() + sRelCurr + NewStr() + "Репутация героя у Франции достигла максимального значения!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F39", 1);
}

string descF40 = "Указать, какими будут офицеры";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40 + GetAddOfficersVar(true);
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AddOfficersVar")) { pchar.CSM.AddOfficersVar = 0; }
	if (sti(pchar.CSM.AddOfficersVar) < 0 || sti(pchar.CSM.AddOfficersVar) > 2) { pchar.CSM.AddOfficersVar = 0; }
	string sTxt = "Все добавляемые в ЧМ офицеры, будут:\n\n";
	switch (sti(pchar.CSM.AddOfficersVar))
	{
		case 0:
			pchar.CSM.AddOfficersVar = 1;
			iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
			totalInfo += sTxt + NewStr() + " * иметь ранг, HP, умения и перки в точности как у ГГ!\n\n";
			totalInfo += sNextC + "55-ый ранг, 555 HP и предельная прокачка";
		break;
		case 1:
			pchar.CSM.AddOfficersVar = 2;
			iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
			totalInfo += sTxt + NewStr() + " * иметь 55-ый ранг, 555 HP и предельную прокачку!\n\n";
			totalInfo += sNextC + "1-ый ранг, 80 HP, все умения по 10 и 0 изученных перков (исключая скрытые)";
		break;
		case 2:
			pchar.CSM.AddOfficersVar = 0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += sTxt + NewStr() + " * иметь 1-ый ранг, 80 HP, умения по 10 и никаких изученных перков (кроме скрытых)!\n\n";
			totalInfo += sNextC + "ранг, HP, умения и перки в точности как у ГГ";
		break;
	}
	totalInfo += "\n\nЗначения P.I.R.A.T.E.S. у всех будут по 10" + NewStr() + "Характеристики офицеров можно настроить по своему усмотрению в меню 'Офицеры'";
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F40", 1);
}

// 2do: запилить интерфейс полного редактора NPC
string descF41 = "Офицер с моделькой кэпов флагманов нац-ых кораблей + мальтийцы (26 вариантов)";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	ref chr;
	int iPic = 5;
	int iNat = 1;
	string itm;
	string sVM = "off_fra_1";
	string sW = "морской офицер #";
	string sN1 = " (Франция)";
	string sN2 = " (Англия)";
	string sN3 = " (Испания)";
	string sN4 = " (Голландия)";
	string sNC = "\nСледующий выбор: ";
	if (!CheckAttribute(pchar, "CSM.ChangeModels.NavalOfficer")) pchar.CSM.ChangeModels.NavalOfficer = 0;
	if (sti(pchar.CSM.ChangeModels.NavalOfficer) < 0 || sti(pchar.CSM.ChangeModels.NavalOfficer) > 25) pchar.CSM.ChangeModels.NavalOfficer = 0;
	switch (sti(pchar.CSM.ChangeModels.NavalOfficer))
	{
		// Французы
		case 0: totalInfo += sModel + sW + "1" + sN1 + sNC + sW + "2" + sN1; break;
		case 1: sVM = "off_fra_2"; totalInfo += sModel +sW + "2" + sN1 + sNC + sW + "3" + sN1; break;
		case 2: sVM = "off_fra_3"; totalInfo += sModel + sW + "3" + sN1 + sNC + sW + "4" + sN1; break;
		case 3: sVM = "off_fra_4"; totalInfo += sModel + sW + "4" + sN1 + sNC + sW + "5" + sN1; break;
		case 4: sVM = "off_fra_5"; totalInfo += sModel + sW + "5" + sN1 + sNC + sW + "6" + sN1; break;
		case 5: sVM = "off_fra_6"; totalInfo += sModel + sW + "6" + sN1 + sNC + sW + "1" + sN2; break;
		// Англичане
		case 6: sVM = "off_eng_1"; totalInfo += sModel + sW + "1" + sN2 + sNC + sW + "2" + sN2; break;
		case 7: sVM = "off_eng_2"; totalInfo += sModel + sW + "2" + sN2 + sNC + sW + "3" + sN2; break;
		case 8: sVM = "off_eng_3"; totalInfo += sModel + sW + "3" + sN2 + sNC + sW + "4" + sN2; break;
		case 9: sVM = "off_eng_4"; totalInfo += sModel + sW + "4" + sN2 + sNC + sW + "5" + sN2; break;
		case 10: sVM = "off_eng_5"; totalInfo += sModel + sW + "5" + sN2 + sNC + sW + "6" + sN2; break;
		case 11: sVM = "off_eng_6"; totalInfo += sModel + sW + "6" + sN2 + sNC + sW + "1" + sN4; break;
		// Голландцы
		case 12: sVM = "off_hol_1"; totalInfo += sModel + sW + "1" + sN4 + sNC + sW + "2" + sN4; break;
		case 13: sVM = "off_hol_2"; totalInfo += sModel + sW + "2" + sN4 + sNC + sW + "3" + sN4; break;
		case 14: sVM = "off_hol_3"; totalInfo += sModel + sW + "3" + sN4 + sNC + sW + "4" + sN4; break;
		case 15: sVM = "off_hol_4"; totalInfo += sModel + sW + "4" + sN4 + sNC + sW + "5" + sN4; break;
		case 16: sVM = "off_hol_5"; totalInfo += sModel + sW + "5" + sN4 + sNC + sW + "6" + sN4; break;
		case 17: sVM = "off_hol_6"; totalInfo += sModel + sW + "6" + sN4 + sNC + sW + "1" + sN3; break;
		// ИСПА-А-АНЦЫ-Ы-Ы!!!11
		case 18: sVM = "off_spa_1"; totalInfo += sModel + sW + "1" + sN3 + sNC + sW + "2" + sN3; break;
		case 19: sVM = "off_spa_2"; totalInfo += sModel + sW + "2" + sN3 + sNC + sW + "3" + sN3; break;
		case 20: sVM = "off_spa_3"; totalInfo += sModel + sW + "3" + sN3 + sNC + sW + "4" + sN3; break;
		case 21: sVM = "off_spa_4"; totalInfo += sModel + sW + "4" + sN3 + sNC + sW + "5" + sN3; break;
		case 22: sVM = "off_spa_5"; totalInfo += sModel + sW + "5" + sN3 + sNC + sW + "6" + sN3; break;
//		case 23: sVM = "off_spa_6"; totalInfo += sModel + sW + "6" + sN3 + sNC + sW + "1" + sN1; break;
		case 23: sVM = "off_spa_6"; totalInfo += sModel + sW + "6" + sN3 + sNC + "офицер Мальтийского ордена #1"; break;
		// Мальтийцы (до кучи)
		case 24: iPic = 271; sVM = "off_Malt_1"; totalInfo += sModel + "офицер Мальтийского ордена #1!" + sNC + "офицер Мальтийского ордена #2"; break;
		case 25: iPic = 271; sVM = "off_Malt_2"; totalInfo += sModel + "офицер Мальтийского ордена #2!" + sNC + sW + "1" + sN1; break;
	}
	iPic += sti(pchar.CSM.ChangeModels.NavalOfficer);
	pchar.CSM.ChangeModels.NavalOfficer = sti(pchar.CSM.ChangeModels.NavalOfficer) + 1;
	if (iPic > 10) iNat = 0;
	if (iPic > 16) iNat = 3;
	if (iPic > 22) iNat = 2;
	if (iPic > 28) iNat = rand(3);
	SetNewPicture("CSMPICTURE", sFaces + iPic + ".tga");
	chr = GetCharacter(NPC_GenerateCharacter("CSMNavalOfficer", sVM, "man", "man", 1, iNat, -1, false, "quest"));
	SetRandomNameToCharacter(chr);
	chr.FaceId = iPic;
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_26");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("CSMNavalOfficer"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	totalInfo += "\n\nОфицер " + GetFullName(chr) + sOfficerM + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F41", 1);
}

string descF42 = "Клон Жана Пикара (2 модели)";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "311.tga");
	ref chr;
	string itm, sM;
	string sVM = "Jan_Pikar";
	if (!CheckAttribute(pchar, "CSM.ChangeModels.JanPikar")) pchar.CSM.ChangeModels.JanPikar = "vA";
	switch (pchar.CSM.ChangeModels.JanPikar)
	{
		case "vA": totalInfo += sModelA + "Жана Пикара!" + NewStr() + sNextC + "вариант #2 (раб)"; sM = "vB"; break;
		case "vB": sVM = "Jan_Slave"; totalInfo += sModelB + "Жана Пикара!" + NewStr() + sNextC + "вариант #1 (обычный)"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.JanPikar = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSM_JanPikar", sVM, "man", "man", 1, FRANCE, -1, false, "quest"));
	chr.name = "Жан";
	chr.lastname = "Пикар";
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	SetCharacterPerk(chr, "HT1");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_13");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("CSM_JanPikar"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_5.wav");
	totalInfo += "\nОфицер " + GetFullName(chr) + sOfficerM + NewStr() + "\n\nЭто ненастоящий " + GetFullName(chr) + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F42", 1);
}

string descF43 = "Клон Элизы Мак Артур (3 модели)";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "250.tga");
	ref chr;
	string itm, sM;
	string sVM = "Rumba";
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Rumba")) pchar.CSM.ChangeModels.Rumba = "vA";
	switch (pchar.CSM.ChangeModels.Rumba)
	{
		case "vA": totalInfo += sModel + "обычная Элен Мак Артур!" + NewStr() + sNextC + "Элен Мак Артур (новое лицо)"; sM = "vB"; break;
		case "vB": sVM = "Rumba_nohat"; totalInfo += sModel + "Элен Мак Артур (новое лицо)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "Элен Мак Артур в шляпе (новое лицо)"; sM = "vC"; break;
		case "vC": sVM = "Rumba_hat"; totalInfo += sModel + "Элен Мак Артур в шляпе (новое лицо)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "обычная Элен Мак Артур"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.Rumba = sM;
	chr = GetCharacter(NPC_GenerateCharacter("HelenaClon", sVM, "woman", "_CheatSurfMenu_\MaryPlayer", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Элиза";
	chr.lastname = "Мак Артур";
	chr.greeting = "helena_hire";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_26");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("HelenaClon"));
	iSND = PlaySound("Voice\Russian\saga\Elen McArtur-05.wav");
	Log_info("Офицер Элиза Мак Артур" + sOfficerF);
	Log_info("Это ненастоящая Элиза Мак Артур" + sClon);
	totalInfo += "\nОфицер Элиза Мак Артур" + sOfficerF + NewStr() + "\n\nЭто ненастоящая Элиза Мак Артур" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F43", 1);
}

string descF44 = "Клон Мэри Каспер (8 моделей)";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "267.tga");
	ref chr;
	string itm, sM;
	string sVM = "Mary";
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Mary")) pchar.CSM.ChangeModels.Mary = 0;
	if (sti(pchar.CSM.ChangeModels.Mary) < 0 || sti(pchar.CSM.ChangeModels.Mary) > 7) pchar.CSM.ChangeModels.Mary = 0;
	sM = sti(pchar.CSM.ChangeModels.Mary) + 1 + "/8 ";
	switch (sti(pchar.CSM.ChangeModels.Mary))
	{
		case 0: totalInfo += sModel + sM + "обычная Мэри Каспер!" + NewStr() + sNextC + "Мэри Каспер в шляпе"; break;
		case 1: sVM = "MaryHat"; totalInfo += sModel + sM + "Мэри Каспер в шляпе!" + NewStr() + sModer + "NikK" + NewStr() + sNextC + "Мэри Каспер (новое лицо, вариант #1)"; break;
		case 2: sVM = "Mary_a_nohat"; totalInfo += sModel + sM + "Мэри Каспер (новое лицо, вариант #1)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "Мэри Каспер в шляпе (новое лицо, вариант #1)"; break;
		case 3: sVM = "Mary_a_hat"; totalInfo += sModel + sM + "Мэри Каспер в шляпе (новое лицо, вариант #1)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "Мэри Каспер (новое лицо, вариант #2)"; break;
		case 4: sVM = "Mary_b_nohat"; totalInfo += sModel + sM + "Мэри Каспер (новое лицо, вариант #2)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "Мэри Каспер в шляпе (новое лицо, вариант #2)"; break;
		case 5: sVM = "Mary_b_hat"; totalInfo += sModel + sM + "Мэри Каспер в шляпе (новое лицо, вариант #2)!" + NewStr() + sModer + "ZM500" + NewStr() + sNextC + "Мэри Каспер в шляпе (вариант #3)"; break;
		case 6: sVM = "Mary_b_hat_alt2"; totalInfo += sModel + sM + "Мэри Каспер в шляпе (вариант #3)!" + NewStr() + sModer + "модель - ZM500, текстура одежды - kucha" + NewStr() + sNextC + "Мэри Каспер в шляпе (вариант #3, другое лицо)"; break;
		case 7: sVM = "Mary_b_hat_alt"; totalInfo += sModel + sM + "Мэри Каспер в шляпе (вариант #3, другое лицо)!" + NewStr() + sModer + "модель - ZM500, текстура одежды - kucha, текстура лица - Cuauhtemoc" + NewStr() + sNextC + "обычная Мэри Каспер"; break;
	}
	pchar.CSM.ChangeModels.Mary = sti(pchar.CSM.ChangeModels.Mary) + 1;
	chr = GetCharacter(NPC_GenerateCharacter("MaryClon", sVM, "woman", "_CheatSurfMenu_\MaryPlayer", 1, PIRATE, -1, false, "quest"));
	chr.FaceId = 267;
	chr.name = "Мэри";
	chr.lastname = "Каспер";
	chr.greeting = "mary_hire";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_31");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("MaryClon"));
	iSND = PlaySound("Voice\Russian\LSC\Mary Casper-05.wav");
	Log_info("Офицер Мэри Каспер" + sOfficerF);
	Log_info("Это ненастоящая Мэри Каспер" + sClon);
	totalInfo += "\nОфицер Мэри Каспер" + sOfficerF + NewStr() + "\n\nЭто ненастоящая Мэри Каспер" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F44", 1);
}

string descF45 = "Клон Даниэль Хоук (2 модели)";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	ref chr;
	string itm, sM;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Danny")) pchar.CSM.ChangeModels.Danny = "vA";
	switch (pchar.CSM.ChangeModels.Danny)
	{
		case "vA":
			SetNewPicture("CSMPICTURE", sFaces + "253.tga");
			chr = GetCharacter(NPC_GenerateCharacter("DanielleClon", "Danny", "woman", "danny", 1, ENGLAND, -1, false, "quest"));
			totalInfo += sModel + "пожилая Даниэль Хоук!" + NewStr() + sNextC + "Даниэль Хоук (молодая)"; sM = "vB";
		break;
		case "vB":
			SetNewPicture("CSMPICTURE", sFaces + "709.tga");
			chr = GetCharacter(NPC_GenerateCharacter("DanielleClon", "Danielle", "woman", "Danielle", 1, ENGLAND, -1, false, "quest"));
			chr.FaceId = 709;
			totalInfo += sModel + "молодая Даниэль Хоук!" + NewStr() + sNextC + "Даниэль Хоук (пожилая)"; sM = "vA";
		break;
	}
	pchar.CSM.ChangeModels.Danny = sM;
	chr.name = "Даниэль";
	chr.lastname = "Хоук";
	chr.greeting = "danny_1";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_20");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("DanielleClon"));
	iSND = PlaySound("Voice\Russian\saga\Denny Hawk-05.wav");
	Log_info("Офицер Даниэль Хоук" + sOfficerF);
	Log_info("Это ненастоящая Данни" + sClon);
	totalInfo += "\nОфицер Даниэль Хоук" + sOfficerF + NewStr() + "\n\nЭто ненастоящая Данни" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F45", 1);
}

string descF46 = "Клоны Чарли Книппеля и Ричарда Флитвуда";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	switch (rand(1))
	{
		case 0: SetNewPicture("CSMPICTURE", sFaces + "222.tga"); iSND = PlaySound("_CheatSurfMenu_\Officer_Charlie.wav"); break;
		case 1: SetNewPicture("CSMPICTURE", sFaces + "217.tga"); iSND = PlaySound("Voice\Russian\hambit\Richard Flitwood-01.wav"); break;
	}
	ref chr;
	string itm;
	// Книппель
	chr = GetCharacter(NPC_GenerateCharacter("KnippelClon", "Kneepel", "man", "man_B", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Чарли";
	chr.lastname = "Книппель";
	chr.greeting = "knippel_hire";
	SetCharacterPerk(chr, "HT4");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_19");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("KnippelClon"));
	// Флитвуд
	chr = GetCharacter(NPC_GenerateCharacter("FleetwoodClon", "Fleetwood", "man", "man", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Ричард";
	chr.lastname = "Флитвуд";
	chr.greeting = "_CheatSurfMenu_\Officer_Fleetwood.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_13");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("FleetwoodClon"));
	Log_info("Офицеры Чарли Книппель и Ричард Флитвуд" + sOfficerX);
	totalInfo += "Офицеры Чарли Книппель и Ричард Флитвуд" + sOfficerX + NewStr() + "\n\nЭто ненастоящие Книппель и Флитвуд" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F46", 1);
}

string descF47 = "Клоны Лонгвэя и Эркюля Тонзага";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "220.tga");
	ref chr;
	string itm;
	// Лонгвэй
	chr = GetCharacter(NPC_GenerateCharacter("LongwayClon", "Longway", "man", "man", 1, HOLLAND, -1, false, "quest"));
	chr.name = "Лонгвэй";
	chr.lastname = "";
	chr.greeting = "longway";
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_19");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("LongwayClon"));
	// Эркюль
	chr = GetCharacter(NPC_GenerateCharacter("TonzagClon", "Tonzag", "man", "man", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Эркюль";
	chr.lastname = "Тонзаг";
	chr.greeting = "tonzag_hire";
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_29");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("TonzagClon"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_" + (1 + rand(1)) + ".wav");
	Log_info("Офицеры Лонгвэй и Эркюль Тонзаг" + sOfficerX);
	Log_info("Это ненастоящие Лонгвей и Эркюль" + sClon);
	totalInfo += "Офицеры Лонгвэй и Эркюль Тонзаг" + sOfficerX + NewStr() + "\n\nЭто ненастоящие Лонгвей и Эркюль" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F47", 1);
}

string descF48 = "Клон Тичингиту (мушкетер)";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "205.tga");
	ref chr;
	string itm;
	chr = GetCharacter(NPC_GenerateCharacter("TichingituClon", "maskog", "man", "man", 1, FRANCE, -1, false, "quest"));
	chr.name = "Тичингиту";
	chr.lastname = "";
	chr.greeting = "Tichingitu";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "maskog";
		chr.model.animation = "man";
	}
	if (!CheckCharacterItem(chr, "mushket2")) GiveItem2Character(chr, "mushket2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_17");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("TichingituClon"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_3.wav");
	Log_info("Офицер Тичингиту" + sOfficerM);
	Log_info("Это ненастоящий Тичингиту" + sClon);
	totalInfo += "Офицер Тичингиту" + sOfficerM + NewStr() + "В инвентаре у него лежит мушкет, экипируйте, если нужно." + NewStr() + "\n\nЭто ненастоящий Тичингиту" + sClon + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F48", 1);
}

string descF49 = "Цири (4 варианта)";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	ref chr;
	string itm, sM;
	SetNewPicture("CSMPICTURE", sFaces + "721.tga");
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Ciri")) pchar.CSM.ChangeModels.Ciri = "vA";
	switch (pchar.CSM.ChangeModels.Ciri)
	{
		case "vA":
			chr = GetCharacter(NPC_GenerateCharacter("CSMCiri", "Cirilla", "woman", "_CheatSurfMenu_\Ciri", 1, PIRATE, -1, false, "quest"));
			totalInfo += sModel + "Цирилла Рианнон, вариант #1!" + NewStr() + sNextC + "Цири, вариант #1 (другие сапоги)"; sM = "vB";
		break;
		case "vB":
			chr = GetCharacter(NPC_GenerateCharacter("CSMCiri", "Cirilla_boots", "woman", "_CheatSurfMenu_\Ciri", 1, PIRATE, -1, false, "quest"));
			totalInfo += sModel + "Цирилла Рианнон, вариант #1 (другие сапоги)!" + NewStr() + sNextC + "Цири, вариант #2"; sM = "vC";
		break;
		case "vC":
			chr = GetCharacter(NPC_GenerateCharacter("CSMCiri", "Cirilla_h2", "woman", "_CheatSurfMenu_\Ciri", 1, PIRATE, -1, false, "quest"));
			totalInfo += sModel + "Цирилла Рианнон, вариант #2!" + NewStr() + sNextC + "Цири, вариант #2 (другие сапоги)"; sM = "vD";
		break;
		case "vD":
			chr = GetCharacter(NPC_GenerateCharacter("CSMCiri", "Cirilla_h2_boots", "woman", "_CheatSurfMenu_\Ciri", 1, PIRATE, -1, false, "quest"));
			totalInfo += sModel + "Цирилла Рианнон, вариант #2 (другие сапоги)!" + NewStr() + sNextC + "Цири, вариант #1"; sM = "vA";
		break;

	}
	pchar.CSM.ChangeModels.Ciri = sM;
	chr.name = "Цирилла";
	chr.lastname = "Рианнон";
	chr.greeting = "Voice\Russian\Danielle02";
	chr.FaceId = 721;
	SetCharacterPerk(chr, "HT1");
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_29");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("CSMCiri"));
	iSND = PlaySound("_CheatSurfMenu_\OfficerGirl_1.wav");
	Log_info("Офицер Цирилла Рианнон" + sOfficerF);
	totalInfo += "\nОфицер Цирилла Рианнон" + sOfficerF + NewStr() + sModer + "DeathDaisy" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F49", 1);
}

string descF50 = "Стимпанк-девушка и Чани";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + RandPhraseSimple("706.tga", "720.tga"));
	ref chr;
	string itm;
	// Стимпанк-девушка
	chr = GetCharacter(NPC_GenerateCharacter("SteampunkGirl", "SteampunkGirl", "woman", "_CheatSurfMenu_\MaryPlayer", 1, PIRATE, -1, false, "quest"));
	chr.FaceId = 706;
	chr.name = "Мелин";
	chr.lastname = "Фермар";
	chr.greeting = "Voice\Russian\Danielle03.wav";
	SetCharacterPerk(chr, "HT2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("SteampunkGirl"));
	// Чани
	chr = GetCharacter(NPC_GenerateCharacter("CSMChani", "Chani", "woman", "_CheatSurfMenu_\Chani", 1, PIRATE, -1, false, "quest"));
	chr.name = "Чани";
	chr.lastname = "";
	chr.FaceId = 720;
	chr.greeting = "Voice\Russian\Danielle04.wav";
	SetCharacterPerk(chr, "HT2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("CSMChani"));
	iSND = PlaySound("_CheatSurfMenu_\OfficerGirl_1.wav");
	Log_info("Офицеры Мелин Фермар и Чани" + sOfficerX);
	totalInfo += "Офицеры Мелин Фермар и Чани" + sOfficerX + NewStr() + sModer + "NikK (стимпанк), reboroda (Чани)" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F50", 1);
}

string descF51 = "Анжелика Шарп и Йоко Диаз";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "70" + (rand(1) + 7) + ".tga");
	ref chr;
	string itm;
	// Анжелика
	chr = GetCharacter(NPC_GenerateCharacter("Angellica", "Angellica", "woman", "_CheatSurfMenu_\MaryPlayer", 1, PIRATE, -1, false, "quest"));
	chr.name = "Анжелика";
	chr.lastname = "Шарп";
	chr.FaceId = 707;
	chr.greeting = "_CheatSurfMenu_\OfficerGirl_2.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_25");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("Angellica"));
	// Йоко
	chr = GetCharacter(NPC_GenerateCharacter("Yoko", "YokoDias", "woman", "_CheatSurfMenu_\MaryPlayer", 1, PIRATE, -1, false, "quest"));
	chr.name = "Йоко";
	chr.lastname = "Диаз";
	chr.FaceId = 708;
	chr.greeting = "Voice\Russian\Danielle01.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_28");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("Yoko"));
	iSND = PlaySound("_CheatSurfMenu_\OfficerGirl_2.wav");
	Log_info("Офицеры Анжелика Шарп и Йоко Диаз" + sOfficerX);
	totalInfo += "Офицеры Анжелика Шарп и Йоко Диаз" + sOfficerX + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F51", 1);
}

string descF52 = "Джа Престон и Маска";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + RandPhraseSimple("290.tga", "734.tga"));
	ref chr;
	string itm;
	// Престон
	chr = GetCharacter(NPC_GenerateCharacter("JaPreston", "QuestCaptain", "man", "man", 1, PIRATE, -1, false, "quest"));
	chr.name = "Джа";
	chr.lastname = "Престон";
	chr.FaceId = 290;
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_28");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("JaPreston"));
	// Маска
	chr = GetCharacter(NPC_GenerateCharacter("csmMaska", "Maska", "man", "_CheatSurfMenu_\BlazeKCM", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Доминик";
	chr.lastname = "Мортонс";
	chr.FaceId = 734;
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_25");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("csmMaska"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицеры Джа Престон и Доминик Мортонс" + sOfficerX);
	totalInfo += "Офицеры Джа Престон и Доминик Мортонс" + sOfficerX + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F52", 1);
}

string descF53 = "Хемфри Дуглас (мушкетер) и Джон Уоркман";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + RandPhraseSimple("425.tga", "555.tga"));
	ref chr;
	string itm;
	// Дуглас
	chr = GetCharacter(NPC_GenerateCharacter("Douglas", "MusketeerEnglish_1", "man", "man", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Хемфри";
	chr.lastname = "Дуглас";
	chr.FaceId = 425;
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "MusketeerEnglish_1";
		chr.model.animation = "man";
	}
	if (!CheckCharacterItem(chr, "mushket2x2")) GiveItem2Character(chr, "mushket2x2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_18");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("Douglas"));
	// Уоркман
	chr = GetCharacter(NPC_GenerateCharacter("CSMJWorkman", "Dragoon_1", "man", "man", 1, PIRATE, -1, false, "quest"));
	chr.name = "Джон";
	chr.lastname = "Уоркман";
	chr.FaceId = 555;
	chr.greeting = "_CheatSurfMenu_\Officer_5.wav";
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("topor_04");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("CSMJWorkman"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицеры Хемфри Дуглас и Джон Уоркман" + sOfficerX);
	totalInfo += "Офицеры Хемфри Дуглас и Джон Уоркман" + sOfficerX + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F53", 1);
}

string descF54 = "Магнус фон Коккай и Николя Рималье (мушкетеры)";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "29" + (rand(1) + 2) + ".tga");
	ref chr;
	string itm;
	// Магнус
	chr = GetCharacter(NPC_GenerateCharacter("Magnus", "MagnusM", "man", "man", 1, SPAIN, -1, false, "quest"));
	chr.name = "Магнус";
	chr.lastname = "фон Коккай";
	chr.FaceId = 292;
	chr.greeting = "_CheatSurfMenu_\Officer_3.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "MagnusM";
		chr.model.animation = "man";
	}
	if (!CheckCharacterItem(chr, "mushket2")) GiveItem2Character(chr, "mushket2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_17");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("Magnus"));
	// Николя
	chr = GetCharacter(NPC_GenerateCharacter("Nicolas", "NicolasM", "man", "man", 1, PIRATE, -1, false, "quest"));
	chr.name = "Николя";
	chr.lastname = "Рималье";
	chr.FaceId = 293;
	chr.greeting = "_CheatSurfMenu_\Officer_3.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "NicolasM";
		chr.model.animation = "man";
	}
	if (!CheckCharacterItem(chr, "mushket2")) GiveItem2Character(chr, "mushket2");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		itm = GetBestGeneratedItem("blade_18");
		TakenItems(chr, itm, 1);
		EquipCharacterbyItem(chr, itm);
	}
	CommonAttributes(characterFromID("Nicolas"));
	// Общее
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицеры Магнус фон Коккай и Николя Рималье" + sOfficerX);
	totalInfo += "Офицеры Магнус фон Коккай и Николя Рималье" + sOfficerX + NewStr() + "В инвентаре у них лежат мушкеты, экипируйте, если нужно." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F54", 1);
}

string descF55 = "Джереми Питт и Нед Огл";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "71" + rand(1) + ".tga");
	ref chr;
	string itm;
	// Питт
	chr = GetCharacter(NPC_GenerateCharacter("CSMPitt", "Pitt", "man", "man", 1, ENGLAND, -1, false, "quest"));
	chr.name = "Джереми";
	chr.lastname = "Питт";
	chr.FaceId = 710;
	chr.greeting = "Voice\Russian\YoungMan01.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("CSMPitt"));
	// Нед
	chr = GetCharacter(NPC_GenerateCharacter("CSMOgl", "Chard3a", "man", "man", 1, ENGLAND, -1, false, "quest"));
	chr.FaceId = 711;
	chr.name = "Нед";
	chr.lastname = "Огл";
	chr.greeting = "Voice\Russian\Ogl03.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("CSMOgl"));
	// Общее
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицеры Джереми Питт и Нед Огл" + sOfficerX);
	totalInfo += "Офицеры Джереми Питт и Нед Огл" + sOfficerX + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F55", 1);
}

string descF56 = "Питер Блад (4 модели)";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "421.tga");
	ref chr;
	string itm, sM;
	string sVM = "blad_0";
	bool bCuirass = false;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Blood")) pchar.CSM.ChangeModels.Blood = "vA";
	switch (pchar.CSM.ChangeModels.Blood)
	{
		case "vA": totalInfo += sModelA + "Питера Блада!" + NewStr() + sNextC + "вариант #2"; sM = "vB"; bCuirass = true; break;
		case "vB": sVM = "blad_6"; totalInfo += sModelB + "Питера Блада!" + NewStr() + sNextC + "вариант #3"; sM = "vC"; break;
		case "vC": sVM = "blad_7"; totalInfo += sModelC + "Питера Блада!" + NewStr() + sNextC + "вариант #4"; sM = "vD"; break;
		case "vD": sVM = "blad_8"; totalInfo += sModelD + "Питера Блада!" + NewStr() + sNextC + "вариант #1"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.Blood = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSMPiterBlood", sVM, "man", "man", 1, ENGLAND, -1, false, "quest"));
	if (bCuirass) chr.HeroModel = sVM + ",blad_2,blad_3,blad_4,blad_5,protocusto,blad_1,blad_9";
	else chr.HeroModel = sVM;
	chr.name = "Питер";
	chr.lastname = "Блад";
	chr.FaceId = 421;
	chr.greeting = "_CheatSurfMenu_\Officer_3.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMPiterBlood"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_3.wav");
	Log_info("Офицер Питер Блад" + sOfficerM);
	totalInfo += "\nОфицер Питер Блад" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F56", 1);
}

string descF57 = "Мишель де Граммон (4 модели)";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "415.tga");
	ref chr;
	string itm, sM;
	string sVM = "Resc_0";
	bool bCuirass = false;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.DeGrammont")) pchar.CSM.ChangeModels.DeGrammont = "vA";
	switch (pchar.CSM.ChangeModels.DeGrammont)
	{
		case "vA": totalInfo += sModelA + "Мишеля де Граммона!" + NewStr() + sNextC + "вариант #2"; sM = "vB"; bCuirass = true; break;
		case "vB": sVM = "Resc_6"; totalInfo += sModelB + "Мишеля де Граммона!" + NewStr() + sNextC + "вариант #3"; sM = "vC"; break;
		case "vC": sVM = "Resc_7"; totalInfo += sModelC + "Мишеля де Граммона!" + NewStr() + sNextC + "вариант #4"; sM = "vD"; break;
		case "vD": sVM = "Resc_8"; totalInfo += sModelD + "Мишеля де Граммона!" + NewStr() + sNextC + "вариант #1"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.DeGrammont = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSMMichelDeGrammont", sVM, "man", "man", 1, FRANCE, -1, false, "quest"));
	if (bCuirass) chr.HeroModel = sVM + ",Resc_2,Resc_3,Resc_4,Resc_5,protocusto,Resc_9,Resc_1";
	else chr.HeroModel = sVM;
	chr.name = "Мишель";
	chr.lastname = "де Граммон";
	chr.FaceId = 415;
	chr.greeting = "Voice\Russian\officer01.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMMichelDeGrammont"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Мишель де Граммон" + sOfficerM);
	totalInfo += "\nОфицер Мишель де Граммон" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F57", 1);
}

string descF58 = "Вильям Патерсон (4 модели)";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "414.tga");
	ref chr;
	string itm, sM;
	string sVM = "Pat_0";
	bool bCuirass = false;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Patterson")) pchar.CSM.ChangeModels.Patterson = "vA";
	switch (pchar.CSM.ChangeModels.Patterson)
	{
		case "vA": totalInfo += sModelA + "Вильяма Патерсона!" + NewStr() + sNextC + "вариант #2"; sM = "vB"; bCuirass = true; break;
		case "vB": sVM = "Pat_6"; totalInfo += sModelB + "Вильяма Патерсона!" + NewStr() + sNextC + "вариант #3"; sM = "vC"; break;
		case "vC": sVM = "Pat_7"; totalInfo += sModelC + "Вильяма Патерсона!" + NewStr() + sNextC + "вариант #4"; sM = "vD"; break;
		case "vD": sVM = "Pat_8"; totalInfo += sModelD + "Вильяма Патерсона!" + NewStr() + sNextC + "вариант #1"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.Patterson = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSMWillaimPatterson", sVM, "man", "man", 1, ENGLAND, -1, false, "quest"));
	if (bCuirass) chr.HeroModel = sVM + ",Pat_2,Pat_3,Pat_4,Pat_5,protocusto,Pat_9,Pat_1";
	else chr.HeroModel = sVM;
	chr.name = "Вильям";
	chr.lastname = "Патерсон";
	chr.FaceId = 414;
	chr.greeting = "Voice\Russian\officer02.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMWillaimPatterson"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Вильям Патерсон" + sOfficerM);
	totalInfo += "\nОфицер Вильям Патерсон" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F58", 1);
}

string descF59 = "Барт Португалец (4 модели)";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "289.tga");
	ref chr;
	string itm, sM;
	string sVM = "Port_0";
	bool bCuirass = false;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Portugal")) pchar.CSM.ChangeModels.Portugal = "vA";
	switch (pchar.CSM.ChangeModels.Portugal)
	{
		case "vA": totalInfo += sModelA + "Барта Португалеца!" + NewStr() + sNextC + "вариант #2"; sM = "vB"; bCuirass = true; break;
		case "vB": sVM = "Port_6"; totalInfo += sModelB + "Барта Португалеца!" + NewStr() + sNextC + "вариант #3"; sM = "vC"; break;
		case "vC": sVM = "Port_7"; totalInfo += sModelC + "Барта Португалеца!" + NewStr() + sNextC + "вариант #4"; sM = "vD"; break;
		case "vD": sVM = "Port_A"; totalInfo += sModelD + "Барта Португалеца!" + NewStr() + sNextC + "вариант #1"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.Portugal = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSMBartPortugal", sVM, "man", "man", 1, PIRATE, -1, false, "quest"));
	if (bCuirass) chr.HeroModel = sVM + ",Port_2,Port_3,Port_4,Port_5,protocusto,Port_8,Port_1";
	else chr.HeroModel = sVM;
	chr.name = "Барт";
	chr.lastname = "Португалец";
	chr.FaceId = 289;
	chr.greeting = "Voice\Russian\officer06.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMBartPortugal"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Барт Португалец" + sOfficerM);
	totalInfo += "\nОфицер Барт Португалец" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F59", 1);
}

string descF60 = "Диего Эспиноза (4 модели)";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "702.tga");
	ref chr;
	string itm, sM;
	string sVM = "Espinosa_0";
	bool bCuirass = false;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Espinosa")) pchar.CSM.ChangeModels.Espinosa = "vA";
	switch (pchar.CSM.ChangeModels.Espinosa)
	{
		case "vA": totalInfo += sModelA + "Диего Эспинозы!" + NewStr() + sNextC + "вариант #2"; sM = "vB"; bCuirass = true; break;
		case "vB": sVM = "Espinosa_1"; totalInfo += sModelB + "Диего Эспинозы!" + NewStr() + sNextC + "вариант #3"; sM = "vC"; break;
		case "vC": sVM = "Espinosa_6"; totalInfo += sModelC + "Диего Эспинозы!" + NewStr() + sNextC + "вариант #4"; sM = "vD"; break;
		case "vD": sVM = "Espinosa_7"; totalInfo += sModelD + "Диего Эспинозы!" + NewStr() + sNextC + "вариант #1"; sM = "vA"; break;
	}
	pchar.CSM.ChangeModels.Espinosa = sM;
	chr = GetCharacter(NPC_GenerateCharacter("CSMDiegoEspinosa", sVM, "man", "man", 1, SPAIN, -1, false, "quest"));
	if (bCuirass) chr.HeroModel = sVM + ",Espinosa_2,Espinosa_3,Espinosa_4,Espinosa_5,protocusto,Espinosa_8,Espinosa_9";
	else chr.HeroModel = sVM;
	chr.name = "Диего";
	chr.lastname = "Эспиноза";
	chr.FaceId = 702;
	chr.greeting = "Voice\Russian\officer03.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = sVM;
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMDiegoEspinosa"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Диего Эспиноза" + sOfficerM);
	totalInfo += "\nОфицер Диего Эспиноза" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F60", 1);
}

string descF61 = "Беатрис Шарп (2 модели) и Делвин Блейз";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	switch (rand(1))
	{
		case 0:
			SetNewPicture("CSMPICTURE", sFaces + "700.tga");
			iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
		break;
		case 1:
			SetNewPicture("CSMPICTURE", sFaces + "701.tga");
			iSND = PlaySound("Voice\Russian\Danielle05.wav");
		break;
	}
	ref chr;
	string itm, sM;
	// Блейз
	chr = GetCharacter(NPC_GenerateCharacter("CSMDevlinBlaze", "BSharp_0", "man", "man", 1, SPAIN, -1, false, "quest"));
	chr.HeroModel = "BSharp_0,BSharp_2,BSharp_3,BSharp_4,BSharp_5,protocusto,BSharp_6,Sharle_8";
	chr.name = "Делвин";
	chr.lastname = "Блейз";
	chr.FaceId = 700;
	chr.greeting = "Voice\Russian\officer04.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT1");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "BSharp_0";
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMDevlinBlaze"));
	// Беатрис
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Beatrice")) pchar.CSM.ChangeModels.Beatrice = "vA";
	switch (pchar.CSM.ChangeModels.Beatrice)
	{
		case "vA":
			chr = GetCharacter(NPC_GenerateCharacter("CSMBeatriceSharp", "Beatrice_a", "woman", "_CheatSurfMenu_\MaryPlayer", 1, ENGLAND, -1, false, "quest"));
			chr.HeroModel = "Beatrice_a";
			totalInfo += sModel + "Беатрис Шарп пиратка!" + NewStr() + sNextC + "Беатрис Шарп (капер)"; sM = "vB";
		break;
		case "vB":
			chr = GetCharacter(NPC_GenerateCharacter("CSMBeatriceSharp", "Beatrice_b", "woman", "_CheatSurfMenu_\MaryPlayer", 1, ENGLAND, -1, false, "quest"));
			chr.HeroModel = "Beatrice_b";
			totalInfo += sModel + "Беатрис Шарп капер!" + NewStr() + sNextC + "Беатрис Шарп (пиратка)"; sM = "vA";
		break;
	}
	pchar.CSM.ChangeModels.Beatrice = sM;
	chr.FaceId = 701;
	chr.name = "Беатрис";
	chr.lastname = "Шарп";
	chr.greeting = "_CheatSurfMenu_\OfficerGirl_2.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("CSMBeatriceSharp"));
	Log_info("Офицеры Беатрис Шарп и Делвин Блейз" + sOfficerX);
	totalInfo += "\nОфицеры Беатрис Шарп и Делвин Блейз (умеет пользоваться мушкетом)" + sOfficerX + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F61", 1);
}

string descF62 = "Черная Борода";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	SetNewPicture("CSMPICTURE", sFaces + "705.tga");
	ref chr;
	string itm;
	chr = GetCharacter(NPC_GenerateCharacter("CSMBlackBeard", "BlackBeard", "man", "man", 1, PIRATE, -1, false, "quest"));
	chr.name = "Черная Борода";
	chr.lastname = "";
	chr.FaceId = 705;
	chr.greeting = "_CheatSurfMenu_\Officer_2.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		chr.model = "BlackBeard";
		chr.model.animation = "man";
	}
	CommonAttributes(characterFromID("CSMBlackBeard"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Черная Борода" + sOfficerM);
	totalInfo += "Офицер Черная Борода" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F62", 1);
}

string descF63 = "Лоренс Белтроп (6 моделей)";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	ref chr;
	string itm, sM;
	int iType = 0;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Balthrop")) pchar.CSM.ChangeModels.Balthrop = "vA";
	switch (pchar.CSM.ChangeModels.Balthrop)
	{
		case "vA":
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "BeltropGPK", "man", "man", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 704;
			sM = "vB";
			totalInfo += sModel + "Лоренс Белтроп с текстурой из КСМ и анимацией из ГПК!\n" + sNextC + "Лоренс Белтроп (текстура из ККС, анимация из КСМ)";
		break;
		case "vB":
			iType = 1;
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "Balthrop", "man", "_CheatSurfMenu_\BalthropPlayer", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 249;
			sM = "vC";
			totalInfo += sModel + "Лоренс Белтроп с текстурой из ККС и анимацией из КСМ!\n" + sNextC + "Лоренс Белтроп (текстура из ККС, анимация из ГПК)";
		break;
		case "vC":
			iType = 2;
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "BaltropGPK", "man", "man", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 249;
			sM = "vD";
			totalInfo += sModel + "Лоренс Белтроп с текстурой из ККС и анимацией из ГПК!\n" + sNextC + "Лоренс Белтроп (текстура и анимация из KCM)";
		break;
		case "vD":
			iType = 3;
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "BalthropKCM", "man", "_CheatSurfMenu_\BalthropPlayer", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 704;
			sM = "vE";
			totalInfo += sModel + "Лоренс Белтроп с текстурой и анимацией из KCM!\n" + sNextC + "Лоренс Белтроп (анимация из KCM, альтернативная текстура)";
		break;
		case "vE":
			iType = 4;
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "Balthrop_alt", "man", "_CheatSurfMenu_\BalthropPlayer", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 726;
			sM = "vF";
			totalInfo += sModel + "Лоренс Белтроп анимацией из KCM и альтернативной текстурой!\n" + sNextC + "Лоренс Белтроп (анимация из ГПК, альтернативная текстура)";
		break;
		case "vF":
			iType = 5;
			chr = GetCharacter(NPC_GenerateCharacter("CSMLawrenceBeltrop", "Beltrop_alt", "man", "man", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 726;
			sM = "vA";
			totalInfo += sModel + "Лоренс Белтроп анимацией из ГПК и альтернативной текстурой!\n" + sNextC + "Лоренс Белтроп (текстура из КСМ, анимация из ГПК)";
		break;
	}
	pchar.CSM.ChangeModels.Balthrop = sM;
	SetNewPicture("CSMPICTURE", sFaces + sti(chr.FaceId) + ".tga");
	chr.name = "Лоренс";
	chr.lastname = "Белтроп";
	chr.greeting = "_CheatSurfMenu_\Officer_4.wav";
	chr.CanTakeMushket = true;
	SetCharacterPerk(chr, "HT3");
	SetCharacterPerk(chr, "HT4");
	itm = GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE);
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	if (CheckAttribute(chr, "IsMushketer"))
	{
		if (itm != "")
		{
			if (HasSubStr(itm, "mushket"))
			{
				SetOfficerToMushketer(chr, itm, false);
			}
		}
		switch (iType)
		{
			case 0:
				chr.model = "BeltropGPK";
				chr.model.animation = "man";
			break;
			case 1:
				chr.model = "Balthrop";
				chr.model.animation = "_CheatSurfMenu_\BalthropPlayer";
			break;
			case 2:
				chr.model = "BaltropGPK";
				chr.model.animation = "man";
			break;
			case 3:
				chr.model = "BalthropKCM";
				chr.model.animation = "_CheatSurfMenu_\BalthropPlayer";
			break;
			case 4:
				chr.model = "Balthrop_alt";
				chr.model.animation = "_CheatSurfMenu_\BalthropPlayer";
			break;
			case 5:
				chr.model = "Beltrop_alt";
				chr.model.animation = "man";
			break;
		}
	}
	CommonAttributes(characterFromID("CSMLawrenceBeltrop"));
	iSND = PlaySound("_CheatSurfMenu_\Officer_1.wav");
	Log_info("Офицер Лоренс Белтроп" + sOfficerM);
	totalInfo += "\nОфицер Лоренс Белтроп" + sOfficerM + sMushO + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F63", 1);
}

string descF64 = "Джессика Брэдфорд (3 модели)";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	ref chr;
	string itm, sM;
	if (!CheckAttribute(pchar, "CSM.ChangeModels.Jess")) pchar.CSM.ChangeModels.Jess = "vA";
	switch (pchar.CSM.ChangeModels.Jess)
	{
		case "vA":
			chr = GetCharacter(NPC_GenerateCharacter("CSMJessikaBradford", "jessika", "woman", "Jessika", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 703;
			SetNewPicture("CSMPICTURE", sFaces + "703.tga");
			sM = "vB";
			totalInfo += sModel + "Джессика Брэдфорд - живая!" + NewStr() + sNextC + "Джессики Брэдфорд (альтернативная текстура)";
		break;
		case "vB":
			chr = GetCharacter(NPC_GenerateCharacter("CSMJessikaBradford", "Jessika_alt", "woman", "Jessika", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 727;
			SetNewPicture("CSMPICTURE", sFaces + "727.tga");
			sM = "vC";
			totalInfo += sModel + "Джессика Брэдфорд - нежить!" + NewStr() + sNextC + "Джессики Брэдфорд (нежить)";
		break;
		case "vC":
			chr = GetCharacter(NPC_GenerateCharacter("CSMJessikaBradford", "Ghost_1", "woman", "Jess", 1, PIRATE, -1, false, "quest"));
			chr.FaceId = 259;
			SetNewPicture("CSMPICTURE", sFaces + "259.tga");
			sM = "vA";
			totalInfo += sModel + "Джессика Брэдфорд - нежить!" + NewStr() + sNextC + "Джессики Брэдфорд (живая)";
		break;
	}
	pchar.CSM.ChangeModels.Jess = sM;
	chr.name = "Джессика";
	chr.lastname = "Брэдфорд";
	chr.greeting = "_CheatSurfMenu_\OfficerGirl_2.wav";
	SetCharacterPerk(chr, "HT1");
	if (GetCharacterEquipByGroup(chr, BLADE_ITEM_TYPE) == "")
	{
		GiveItem2Character(chr, "q_blade_19");
		EquipCharacterbyItem(chr, "q_blade_19");
	}
	CommonAttributes(characterFromID("CSMJessikaBradford"));
	iSND = PlaySound("_CheatSurfMenu_\OfficerGirl_2.wav");
	Log_info("Офицер Джессика Брэдфорд" + sOfficerF);
	totalInfo += "\nОфицер Джессика Брэдфорд" + sOfficerF + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F64", 1);
}

string descF65 = "Вернуть модель, анимацию, имя и нацию Шарля";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	if (SendMessage(pchar, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		RemoveMushket(pchar);
		pchar.FaceId = 201;
		pchar.model = "Sharle_1";
		pchar.HeroModel = "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8";
		pchar.name = "Шарль"; pchar.lastname = "де Мор";
		pchar.nameGen = "Шарля"; pchar.lastnameGen = "де Мора";
		pchar.nameDat = "Шарлю"; pchar.lastnameDat = "де Мору";
		pchar.sex = "man";
		pchar.model.animation = "man_A";
		pchar.defaultanimation = "man_A";
		pchar.nation = FRANCE;
		pchar.BaseNation = FRANCE;
		Characters_RefreshModel(pchar);
		EquipVisualRefresh(pchar);
		SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
		iSND = PlaySound("_CheatSurfMenu_\Sign.wav");
		Log_info("Имя, нация, портрет, модель и анимация выставлены под оригинального Шарля!");
		totalInfo += "Имя, нация, портрет, модель и анимация выставлены под оригинального Шарля!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sWpnOff;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F65", 1);
}

string descF66 = "Сменить модель персонажа (мужские модели, 110 вариантов)";
void CalculateInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	CommonActions();
	bool bCommonAni = true;
	bool bProto = true;
	if (sti(pchar.CSM.ChangeModelM) < 0 || sti(pchar.CSM.ChangeModelM) > 109) pchar.CSM.ChangeModelM = 0;
	if (SendMessage(pchar, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		if (!HasSubStr(pchar.model.animation, "swim"))
		{
			bShowArrows = true;
			pchar.CSM.ArrowsType = 1;
			CreateImage("CSM_ArrowLeft", "icons", "left arrow", 156, 248, 224, 312);
			CreateImage("CSM_ArrowRight", "icons", "right arrow", 416, 248, 484, 312);
			totalInfo += sti(pchar.CSM.ChangeModelM) + 1 + "/109" + sArrows + "\n";
			RemoveMushket(pchar);
			switch (sti(pchar.CSM.ChangeModelM))
			{
				case 0:
					pchar.FaceId = 526;
					pchar.model = "blad_0";
					pchar.HeroModel = "blad_0,blad_2,blad_3,blad_4,blad_5,protocusto,blad_9,blad_1";
					bProto = false;
					totalInfo += sModel + "Питер Блад из ГПК 1.3.2! (1\4)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "модель Питера Блада из ГПК 1.3.2, вариант 2";
				break;
				case 1:
					pchar.FaceId = 526;
					pchar.model = "blad_6";
					totalInfo += sModel + "Питер Блад из ГПК 1.3.2! (2\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Питера Блада из ГПК 1.3.2, вариант 3";
				break;
				case 2:
					pchar.FaceId = 526;
					pchar.model = "blad_7";
					totalInfo += sModel + "Питер Блад из ГПК 1.3.2! (3\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Питера Блада из ГПК 1.3.2, вариант 4";
				break;
				case 3:
					pchar.FaceId = 526;
					pchar.model = "blad_8";
					totalInfo += sModel + "Питер Блад из ГПК 1.3.2! (4\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Мишель де Граммон из ГПК 1.3.2";
				break;
				case 4:
					pchar.FaceId = 415;
					pchar.model = "Resc_0";
					pchar.HeroModel = "Resc_0,Resc_2,Resc_3,Resc_4,Resc_5,protocusto,Resc_9,Resc_7";
					bProto = false;
					totalInfo += sModel + "Мишель де Граммон из ГПК 1.3.2! (1\4)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "модель Мишеля де Граммона из ГПК 1.3.2, вариант 2";
				break;
				case 5:
					pchar.FaceId = 415;
					pchar.model = "Resc_1";
					totalInfo += sModel + "Мишель де Граммон из ГПК 1.3.2! (2\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Мишеля де Граммона из ГПК 1.3.2, вариант 3";
				break;
				case 6:
					pchar.FaceId = 415;
					pchar.model = "Resc_6";
					totalInfo += sModel + "Мишель де Граммон из ГПК 1.3.2! (3\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Мишеля де Граммона из ГПК 1.3.2, вариант 4";
				break;
				case 7:
					pchar.FaceId = 415;
					pchar.model = "Resc_8";
					totalInfo += sModel + "Мишель де Граммон из ГПК 1.3.2! (4\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Вильям Патерсон из ГПК 1.3.2";
				break;
				case 8:
					pchar.FaceId = 414;
					pchar.model = "Pat_0";
					pchar.HeroModel = "Pat_0,Pat_2,Pat_3,Pat_4,Pat_5,protocusto,Pat_9,Pat_1";
					bProto = false;
					totalInfo += sModel + "Вильям Патерсон из ГПК 1.3.2! (1\4)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "модель Вильяма Патерсона из ГПК 1.3.2, вариант 2";
				break;
				case 9:
					pchar.FaceId = 414;
					pchar.model = "Pat_8";
					totalInfo += sModel + "Вильям Патерсон из ГПК 1.3.2! (2\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Вильяма Патерсона из ГПК 1.3.2, вариант 3";
				break;
				case 10:
					pchar.FaceId = 414;
					pchar.model = "Pat_7";
					totalInfo += sModel + "Вильям Патерсон из ГПК 1.3.2! (3\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Вильяма Патерсона из ГПК 1.3.2, вариант 4";
				break;
				case 11:
					pchar.FaceId = 414;
					pchar.model = "Pat_6";
					totalInfo += sModel + "Вильям Патерсон из ГПК 1.3.2! (4\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Барт Португалец из ГПК 1.3.2!";
				break;
				case 12:
					pchar.FaceId = 289;
					pchar.model = "Port_0";
					pchar.HeroModel = "Port_0,Port_2,Port_3,Port_4,Port_5,protocusto,Port_8,Port_1";
					bProto = false;
					totalInfo += sModel + "Барт Португалец из ГПК 1.3.2! (1\4)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "модель Барта Португалеца из ГПК 1.3.2, вариант 2";
				break;
				case 13:
					pchar.FaceId = 289;
					pchar.model = "Port_6";
					totalInfo += sModel + "Барт Португалец из ГПК 1.3.2! (2\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Барта Португалеца из ГПК 1.3.2, вариант 3";
				break;
				case 14:
					pchar.FaceId = 289;
					pchar.model = "Port_7";
					totalInfo += sModel + "Барт Португалец из ГПК 1.3.2! (3\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "модель Барта Португалеца из ГПК 1.3.2, вариант 4";
				break;
				case 15:
					pchar.FaceId = 289;
					pchar.model = "Port_A";
					totalInfo += sModel + "Барт Португалец из ГПК 1.3.2! (4\4)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Диего Эспиноза из ГПК 1.3.2";
				break;
				case 16:
					pchar.FaceId = 702;
					pchar.model = "Espinosa_0";
					pchar.HeroModel = "Espinosa_0,Espinosa_2,Espinosa_3,Espinosa_4,Espinosa_5,protocusto,Espinosa_8,Espinosa_9";
					bProto = false;
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.3.2! (1\5)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sModer + "Metazot(BMS) и Джон Дэвис" + NewStr() + sNextC + "модель Диего Эспинозы из ГПК 1.3.2, вариант 2";
				break;
				case 17:
					pchar.FaceId = 702;
					pchar.model = "Espinosa_1";
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.3.2! (2\5)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Metazot(BMS) и Джон Дэвис" + NewStr() + sNextC + "модель Диего Эспинозы из ГПК 1.3.2, вариант 3";
				break;
				case 18:
					pchar.FaceId = 702;
					pchar.model = "Espinosa_6";
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.3.2! (3\5)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Metazot(BMS) и Джон Дэвис" + NewStr() + sNextC + "модель Диего Эспинозы из ГПК 1.3.2, вариант 4";
				break;
				case 19:
					pchar.FaceId = 702;
					pchar.model = "Espinosa_7";
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.3.2! (4\5)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Metazot(BMS) и Джон Дэвис" + NewStr() + sNextC + "модель Диего Эспинозы из ГПК 1.3.2, вариант 5";
				break;
				case 20:
					pchar.FaceId = 728;
					pchar.model = "Espinosa_alt";
					pchar.HeroModel = "Espinosa_alt,Espinosa_alt_Cirass1,Espinosa_alt_Cirass2,Espinosa_alt_Cirass3,Espinosa_alt_Cirass4,protocusto,Espinosa_alt_hat,Espinosa_alt_hat";
					bProto = false;
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.3.2! (5\5)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sModer + "Metazot" + NewStr() + sNextC + "Питер Блад из ГПК 1.2.12";
				break;
				case 21:
					pchar.FaceId = 716;
					pchar.model = "Blood5";
					pchar.HeroModel = "Blood5,Blood5_Cirass,Blood5_Cirass1,Blood5_Cirass2,Blood5_Cirass3,protocusto,Blood5,Blood5";
					bProto = false;
					totalInfo += sModel + "Питер Блад из ГПК 1.2.12!" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "Ян Стейс из ГПК 1.2.12";
				break;
				case 22:
					pchar.FaceId = 717;
					pchar.model = "Hero1";
					pchar.HeroModel = "Hero1,Hero1_Cirass,Hero1_Cirass1,Hero1_Cirass2,Hero1_Cirass3,protocusto,Hero1,Hero1";
					bProto = false;
					totalInfo += sModel + "Ян Стейс из ГПК 1.2.12!" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "Диего Эспиноза из ГПК 1.2.12";
				break;
				case 23:
					pchar.FaceId = 718;
					pchar.model = "Ezpinoza_0";
					pchar.HeroModel = "Ezpinoza_0,Ezpinoza_1,Ezpinoza_2,Ezpinoza_3,Ezpinoza_4,protocusto,Ezpinoza_0,Ezpinoza_0";
					bProto = false;
					totalInfo += sModel + "Диего Эспиноза из ГПК 1.2.12!" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "Делвин Блейз из ГПК";
				break;
				case 24:
					pchar.FaceId = 700;
					pchar.model = "BSharp_0";
					pchar.HeroModel = "BSharp_0,BSharp_2,BSharp_3,BSharp_4,BSharp_5,protocusto,BSharp_6,Sharle_8";
					bProto = false;
					totalInfo += sModel + "Делвин Блейз с анимацией из ГПК! (1\2)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sModer + "VVV100 (отображение кирас) и Nathaniel (возможность ношения мушкета)" + NewStr() + sNextC + "Делвин Блейз из К3";
				break;
				case 25:
					pchar.FaceId = 700;
					pchar.model = "DevlinK3";
					pchar.model.animation = "_CheatSurfMenu_\BlazeKCM";
					bCommonAni = false;
					totalInfo += sModel + "Делвин Блейз с анимацией из К3! (2\2)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Лоренс Белтроп";
				break;
				case 26:
					pchar.FaceId = 704;
					pchar.model = "BeltropGPK";
					totalInfo += sModel + "Лоренс Белтроп из КСМ с анимацией из ГПК! (1\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "NikK и BoriS" + NewStr() + sNextC + "Лоренс Белтроп с анимацией из КСМ и текстурой из ККС";
				break;
				case 27:
					pchar.FaceId = 249;
					pchar.model = "Balthrop";
					pchar.model.animation = "_CheatSurfMenu_\BalthropPlayer";
					bCommonAni = false;
					totalInfo += sModel + "Лоренс Белтроп с анимацией из КСМ и текстурой из ККС! (2\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Лоренс Белтроп с анимацией из ГПК и текстурой из ККС";
				break;
				case 28:
					pchar.FaceId = 249;
					pchar.model = "BaltropGPK";
					totalInfo += sModel + "Лоренс Белтроп с анимацией из ГПК и текстурой из ККС! (3\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Лоренс Белтроп с анимацией из КСМ и альтернативной текстурой";
				break;
				case 29:
					pchar.FaceId = 726;
					pchar.model = "Balthrop_alt";
					pchar.model.animation = "_CheatSurfMenu_\BalthropPlayer";
					bCommonAni = false;
					totalInfo += sModel + "Лоренс Белтроп с анимацией из КСМ и альтернативной текстурой! (4\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Metazot" + NewStr() + sNextC + "Лоренс Белтроп с анимацией из ГПК и альтернативной текстурой";
				break;
				case 30:
					pchar.FaceId = 726;
					pchar.model = "Beltrop_alt";
					totalInfo += sModel + "Лоренс Белтроп с анимацией из ГПК и альтернативной текстурой! (5\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Metazot" + NewStr() + sNextC + "Лоренс Белтроп с анимацией и текстурой из КСМ";
				break;
				case 31:
					pchar.FaceId = 704;
					pchar.model = "BalthropKCM";
					pchar.model.animation = "_CheatSurfMenu_\BalthropPlayer";
					bCommonAni = false;
					totalInfo += sModel + "Лоренс Белтроп с анимацией и текстурой из КСМ! (6\6)" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "молодой Натаниэль Хоук";
				break;
				case 32:
					pchar.FaceId = 524;
					pchar.model = "Hawk_3";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "Натаниэль Хоук (молодой)!" + NewStr() + sNextC + "пожилой Натаниэль Хоук";
				break;
				case 33:
					pchar.FaceId = 209;
					pchar.model = "Hawk_2";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "Натаниэль Хоук (пожилой)!" + NewStr() + sNextC + "Джек Воробей";
				break;
				case 34:
					pchar.FaceId = 723;
					pchar.model = "Jack_Sparrow_a";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "капитан Джек Воробей! (1\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джек Воробей (вариант #2)";
				break;
				case 35:
					pchar.FaceId = 724;
					pchar.model = "Jack_Sparrow_b";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "капитан Джек Воробей! (2\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Уилл Тернер";
				break;
				case 36:
					pchar.FaceId = 729;
					pchar.model = "WillTurner";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "Уилл Тернер!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Гектор Барбосса";
				break;
				case 37:
					pchar.FaceId = 730;
					pchar.model = "HectorBarbossa";
					pchar.model.animation = "_CheatSurfMenu_\man_K2";
					bCommonAni = false;
					totalInfo += sModel + "Гектор Барбосса!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Акула Додсон";
				break;
				case 38:
					pchar.FaceId = 238;
					pchar.model = "Shark";
					totalInfo += sModel + "Акула Додсон!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Маска";
				break;
				case 39:
					pchar.FaceId = 734;
					pchar.model = "Maska";
					pchar.model.animation = "_CheatSurfMenu_\BlazeKCM";
					bCommonAni = false;
					totalInfo += sModel + "Маска!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "Kopcapkz" + NewStr() + sNextC + "Ричард Флитвуд";
				break;
				case 40:
					pchar.FaceId = 217;
					pchar.model = "Fleetwood";
					totalInfo += sModel + "Ричард Флитвуд!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "полковник Фокс";
				break;
				case 41:
					pchar.FaceId = 244;
					pchar.model = "Fox";
					totalInfo += sModel + "полковник Фокс!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джино Гвинейли";
				break;
				case 42:
					pchar.FaceId = 226;
					pchar.model = "Gino";
					totalInfo += sModel + "Джино Гвинейли!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Лысый, но уверенный в себе тип";
				break;
				case 43:
					pchar.FaceId = 713;
					pchar.model = "Chard";
					totalInfo += sModel + "Лысый, но уверенный в себе тип!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Сутенерского вида парень";
				break;
				case 44:
					pchar.FaceId = 714;
					pchar.model = "Chard2";
					totalInfo += sModel + "Сутенерского вида парень!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Нед Огл";
				break;
				case 45:
					pchar.FaceId = 711;
					pchar.model = "Chard3a";
					totalInfo += sModel + "Нед Огл!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джереми Питт";
				break;
				case 46:
					pchar.FaceId = 710;
					pchar.model = "Pitt";
					totalInfo += sModel + "Джереми Питт!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Хьюго Авенделл";
				break;
				case 47:
					pchar.FaceId = 228;
					pchar.model = "Hugh";
					totalInfo += sModel + "Хьюго Авенделл!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Лукас Роденбург";
				break;
				case 48:
					pchar.FaceId = 216;
					pchar.model = "Lucas";
					totalInfo += sModel + "Лукас Роденбург!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Якоб Ван Берг";
				break;
				case 49:
					pchar.FaceId = 219;
					pchar.model = "VanBerg";
					totalInfo += sModel + "Якоб Ван Берг!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Ришард Шамбон";
				break;
				case 50:
					pchar.FaceId = 282;
					pchar.model = "Shambone";
					totalInfo += sModel + "Ришард Шамбон!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Гай Марше";
				break;
				case 51:
					pchar.FaceId = 148;
					pchar.model = "GayMarshe";
					totalInfo += sModel + "Гай Марше!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Дональд Гринспи";
				break;
				case 52:
					pchar.FaceId = 962;
					pchar.model = "Donald";
					totalInfo += sModel + "Дональд Гринспи!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Франсуа Гонтьер";
				break;
				case 53:
					pchar.FaceId = 284;
					pchar.model = "Gontier";
					totalInfo += sModel + "Франсуа Гонтьер!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Остин";
				break;
				case 54:
					pchar.FaceId = 525;
					pchar.model = "Ostin";
					totalInfo += sModel + "Остин!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Хуан Чахотка";
				break;
				case 55:
					pchar.FaceId = 150;
					pchar.model = "HuanTubercul";
					totalInfo += sModel + "Хуан Чахотка!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мигель Дичозо";
				break;
				case 56:
					pchar.FaceId = 204;
					pchar.model = "Migel_2";
					totalInfo += sModel + "Мигель Дичозо!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Лонгвэй";
				break;
				case 57:
					pchar.FaceId = 220;
					pchar.model = "Longway";
					totalInfo += sModel + "Лонгвэй!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Эркюль Тонзаг";
				break;
				case 58:
					pchar.FaceId = 221;
					pchar.model = "Tonzag";
					totalInfo += sModel + "Эркюль Тонзаг!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Тичингиту";
				break;
				case 59:
					pchar.FaceId = 205;
					pchar.model = "Maskog";
					totalInfo += sModel + "Тичингиту!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Эрнандо Васкес";
				break;
				case 60:
					pchar.FaceId = 230;
					pchar.model = "Vasces";
					totalInfo += sModel + "Эрнандо Васкес!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Анри Тибо";
				break;
				case 61:
					pchar.FaceId = 273;
					pchar.model = "Tibo";
					totalInfo += sModel + "Анри Тибо!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Зикомо";
				break;
				case 62:
					pchar.FaceId = 242;
					pchar.model = "Zikomo";
					totalInfo += sModel + "Зикомо!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Канек";
				break;
				case 63:
					pchar.FaceId = 231;
					pchar.model = "Itza_Kanek";
					totalInfo += sModel + "Канек!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Уракан";
				break;
				case 64:
					pchar.FaceId = 232;
					pchar.model = "Itza_Urakan";
					totalInfo += sModel + "Уракан!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Туттуатхапак";
				break;
				case 65:
					pchar.FaceId = 241;
					pchar.model = "Tuttuathapack";
					totalInfo += sModel + "Туттуатхапак!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Дэви Джонс";
				break;
				case 66:
					pchar.FaceId = 715;
					pchar.model = "PotCMobCap";
					pchar.HeroModel = "PotCMobCap";
					bProto = false;
					totalInfo += sModel + "Дэви Джонс!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Матрос Джонса #1";
				break;
				case 67:
					pchar.FaceId = 552;
					pchar.model = "VaterSkel_1";
					pchar.HeroModel = "VaterSkel_1";
					bProto = false;
					totalInfo += sModel + "Матрос Дэви Джонса #1!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Матрос Джонса #2";
				break;
				case 68:
					pchar.FaceId = 553;
					pchar.model = "VaterSkel_2";
					pchar.HeroModel = "VaterSkel_2";
					bProto = false;
					totalInfo += sModel + "Матрос Дэви Джонса #2!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Матрос Джонса #3";
				break;
				case 69:
					pchar.FaceId = 554;
					pchar.model = "VaterSkel_3";
					pchar.HeroModel = "VaterSkel_3";
					bProto = false;
					totalInfo += sModel + "Матрос Дэви Джонса #3!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Матрос Джонса #4";
				break;
				case 70:
					pchar.FaceId = 551;
					pchar.model = "VaterSkel_4";
					pchar.HeroModel = "VaterSkel_4";
					bProto = false;
					totalInfo += sModel + "Матрос Дэви Джонса #4!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Чавинави";
				break;
				case 71:
					pchar.FaceId = 961;
					pchar.model = "Chavinavi_1";
					pchar.HeroModel = "Chavinavi_1";
					bProto = false;
					totalInfo += sModel + "Чавинави!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Страж Маски";
				break;
				case 72:
					pchar.FaceId = 522;
					pchar.model = "Giant";
					pchar.HeroModel = "Giant";
					pchar.model.animation = "giant";
					bCommonAni = false;
					bProto = false;
					totalInfo += sModel + "Страж Маски!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Миктлантекутли";
				break;
				case 73:
					pchar.FaceId = 523;
					pchar.model = "mictlantecuhtli";
					pchar.HeroModel = "mictlantecuhtli";
					bProto = false;
					totalInfo += sModel + "Миктлантекутли!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Капитан Калеуче";
				break;
				case 74:
					pchar.FaceId = 556;
					pchar.model = "skeletcap";
					pchar.HeroModel = "skeletcap";
					bProto = false;
					totalInfo += sModel + "Капитан Калеуче!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Бенджамин Джонс";
				break;
				case 75:
					pchar.FaceId = 719;
					pchar.model = "Addington";
					totalInfo += sModel + "Бенджамин Джонс!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Адольф Барбье";
				break;
				case 76:
					pchar.FaceId = 821;
					pchar.model = "officer_16";
					totalInfo += sModel + "Адольф Барбье!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Билли Пирт";
				break;
				case 77:
					pchar.FaceId = 310;
					pchar.model = "Billy_Pirt";
					totalInfo += sModel + "Билли Пирт!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Ноэль Форже";
				break;
				case 78:
					pchar.FaceId = 331;
					pchar.model = "Boss_1";
					totalInfo += sModel + "Ноэль Форже!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "начальник рудника Синт-Маартена";
				break;
				case 79:
					pchar.FaceId = 334;
					pchar.model = "Boss_2";
					totalInfo += sModel + "начальник рудника Синт-Маартена!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Артур Донован";
				break;
				case 80:
					pchar.FaceId = 252;
					pchar.model = "Donovan";
					totalInfo += sModel + "Артур Донован!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "капитан Гобарт";
				break;
				case 81:
					pchar.FaceId = 555;
					pchar.model = "Dragoon_1";
					totalInfo += sModel + "капитан Гобарт!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Генри Морган";
				break;
				case 82:
					pchar.FaceId = 417;
					pchar.model = "Morgan";
					totalInfo += sModel + "Генри Морган!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "кэп галеона по 'Ложному следу'";
				break;
				case 83:
					pchar.FaceId = 146;
					pchar.model = "q_eng_Cap_1";
					totalInfo += sModel + "кэп галеона по 'Ложному следу'!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Каспар Грэттон (англ.)";
				break;
				case 84:
					pchar.FaceId = 304;
					pchar.model = "quest_off_eng";
					totalInfo += sModel + "Каспар Грэттон (англ.)!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Каспар Грэттон (голл.)";
				break;
				case 85:
					pchar.FaceId = 20;
					pchar.model = "quest_off_holl";
					totalInfo += sModel + "Каспар Грэттон (голл.)!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Жан Дено";
				break;
				case 86:
					pchar.FaceId = 302;
					pchar.model = "quest_off_franc";
					totalInfo += sModel + "Жан Дено!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Хуан Дено";
				break;
				case 87:
					pchar.FaceId = 303;
					pchar.model = "quest_off_spain";
					totalInfo += sModel + "Хуан Дено!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Фернандо Родригес";
				break;
				case 88:
					pchar.FaceId = 286;
					pchar.model = "Rodriges";
					totalInfo += sModel + "Фернандо Родригес!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Михаэль Розенкрафт";
				break;
				case 89:
					pchar.FaceId = 288;
					pchar.model = "Rozencraft";
					totalInfo += sModel + "Михаэль Розенкрафт!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Бывалый матрос";
				break;
				case 90:
					pchar.FaceId = 145;
					pchar.model = "AdamRainer";
					totalInfo += sModel + "Бывалый матрос!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мастер Алексус";
				break;
				case 91:
					pchar.FaceId = 235;
					pchar.model = "Alexus";
					totalInfo += sModel + "Мастер Алексус!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Офицер";
				break;
				case 92:
					pchar.FaceId = 207;
					pchar.model = "Alonso";
					totalInfo += sModel + "Офицер!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Арчибальд Колхаун";
				break;
				case 93:
					pchar.FaceId = 206;
					pchar.model = "Archy";
					totalInfo += sModel + "Арчибальд Колхаун!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Аззи";
				break;
				case 94:
					pchar.FaceId = 527;
					pchar.model = "Azzy";
					totalInfo += sModel + "Аззи!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Жак Барбазон";
				break;
				case 95:
					pchar.FaceId = 212;
					pchar.model = "Barbazon";
					totalInfo += sModel + "Жак Барбазон!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Захария Марлоу";
				break;
				case 96:
					pchar.FaceId = 210;
					pchar.model = "Marlow";
					totalInfo += sModel + "Захария Марлоу!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Маркус Тиракс";
				break;
				case 97:
					pchar.FaceId = 211;
					pchar.model = "Terrax";
					totalInfo += sModel + "Маркус Тиракс!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джеймс Норрингтон";
				break;
				case 98:
					pchar.FaceId = 725;
					pchar.model = "Norrington";
					totalInfo += sModel + "Джеймс Норрингтон" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "spacecrack" + NewStr() + sNextC + "Чёрная Борода";
				break;
				case 99:
					pchar.FaceId = 705;
					pchar.model = "BlackBeard";
					totalInfo += sModel + "Чёрная Борода!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sModer + "Джон Дэвис" + NewStr() + sNextC + "Контрабандист";
				break;
				case 100:
					pchar.FaceId = 712;
					pchar.model = "BigPirate";
					totalInfo += sModel + "Контрабандист!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Ян Свенсон";
				break;
				case 101:
					pchar.FaceId = 213;
					pchar.model = "Svenson";
					totalInfo += sModel + "Ян Свенсон!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Чёрный Эдди";
				break;
				case 102:
					pchar.FaceId = 260;
					pchar.model = "Black";
					totalInfo += sModel + "Чёрный Эдди!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Алехандро Пистолето";
				break;
				case 103:
					pchar.FaceId = 947;
					pchar.model = "DeLuck";
					pchar.HeroModel = "DeLuck,DeLuck_1,DeLuck_2,DeLuck_3,DeLuck_4,protocusto,DeLuck,DeLuck";
					bProto = false;
					totalInfo += sModel + "Алехандро Пистолето!" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sNextC + "Терминатор";
				break;
				case 104:
					pchar.FaceId = 795;
					pchar.model = "Terminator";
					pchar.HeroModel = "Terminator";
					bProto = false;
					totalInfo += sModel + "Терминатор!" + NewStr() + sSuitN + " | " + sMushY + NewStr() + sNextC + "Шарль де Мор адмирал (вариант #1)";
				break;
				case 104:
					pchar.FaceId = 201;
					pchar.model = "Sharle_7";
					pchar.HeroModel = "Sharle_7,Sharle_7,Sharle_7,Sharle_7,Sharle_7,protocusto,Sharle_7,Sharle_8";
					bProto = false;
					totalInfo += sModel + "Шарль де Мор адмирал (#1)! (1\4)" + NewStr() + "Костюмы: нет кирас" + NewStr() + "Мушкеты: да, но чуть другая модель (от BigMan)" + NewStr() + sNextC + "Шарль де Мор адмирал (вариант #2)";
				break;
				case 105:
					pchar.FaceId = 201;
					pchar.model = "Sharle_7_alt";
					pchar.HeroModel = "Sharle_7_alt,Sharle_7_alt,Sharle_7_alt,Sharle_7_alt,Sharle_7_alt,protocusto,Sharle_7_alt,Sharle_8";
					bProto = false;
					totalInfo += sModel + "Шарль де Мор адмирал (#2)! (2\4)" + NewStr() + "Костюмы: нет кирас" + " | " + sMushY + NewStr() + sModer + "BigMan" + NewStr() + sNextC + "Шарль де Мор пират";
				break;
				case 106:
					pchar.FaceId = 201;
					pchar.model = "Sharle_9";
					pchar.HeroModel = "Sharle_9,Sharle_9,Sharle_9,Sharle_9,Sharle_9,protocusto,Sharle_7,Sharle_8";
					bProto = false;
					totalInfo += sModel + "Шарль де Мор пират! (3\4)" + NewStr() + "Костюмы: нет кирас" + " | " + sMushY + NewStr() + sModer + "KlaxON" + NewStr() + sNextC + "Шарль де Мор от Sith";
				break;
				case 107:
					pchar.FaceId = 201;
					pchar.model = "Sharle_sith_1";
					pchar.HeroModel = "Sharle_sith_1,Sharle_sith_2,Sharle_sith_3,Sharle_sith_4,Sharle_sith_5,protocusto,Sharle_6,Sharle_8";
					bProto = false;
					totalInfo += sModel + "Шарль де Мор от Sith! (4\4)" + NewStr() + sSuitY + " | " + sMushY + NewStr() + sModer + "Sith" + NewStr() + sNextC + "оригинальный Шарль де Мор";
				break;
				case 108:
					pchar.FaceId = 201;
					pchar.model = "Sharle_1";
					pchar.HeroModel = "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8";
					bProto = false;
					totalInfo += sModel + "оригинальный Шарль де Мор!" + NewStr() + sNextC + "Питер Блад из ГПК 1.3.2";
				break;
			}
			if (bCommonAni)
			{
				pchar.model.animation = "man_A";
			}
			if (bProto)
			{
				pchar.HeroModel = pchar.model + "," + pchar.model + "," + pchar.model + "," + pchar.model + "," + pchar.model + ",protocusto," + pchar.model + "," + pchar.model;
			}
			pchar.defaultanimation = pchar.model.animation;
			SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
			pchar.sex = "man";
			Characters_RefreshModel(pchar);
			EquipVisualRefresh(pchar);
			pchar.CSM.ChangeModelM = sti(pchar.CSM.ChangeModelM) + 1;
			totalInfo += sChangeName;
			if (!bNoSound) iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			totalInfo += "Персонажу из воды бы сначала выбраться...";
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sWpnOff;
	}
	bNoSound = false;
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F66", 1);
}

string descF67 = "Сменить модель персонажа (женские модели, 30 вариантов)";
void CalculateInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	CommonActions();
	if (sti(pchar.CSM.ChangeModelW) < 0 || sti(pchar.CSM.ChangeModelW) > 29) pchar.CSM.ChangeModelW = 0;
	bool bCommonAni = true;
	bool bProto = true;
	if (SendMessage(pchar, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		if (!HasSubStr(pchar.model.animation, "swim"))
		{
			bShowArrows = true;
			pchar.CSM.ArrowsType = 2;
			CreateImage("CSM_ArrowLeft", "icons", "left arrow", 156, 248, 224, 312);
			CreateImage("CSM_ArrowRight", "icons", "right arrow", 416, 248, 484, 312);
			totalInfo += sti(pchar.CSM.ChangeModelW) + 1 + "/30" + sArrows + "\n";
			RemoveMushket(pchar);
			switch (sti(pchar.CSM.ChangeModelW))
			{
				case 0:
					pchar.model = "Beatrice_a";
					totalInfo += sModel + "Беатрис Шарп (пират) из К3! (1\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Беатрис Шарп вариант #2 (капер) из К3";
				break;
				case 1:
					pchar.model = "Beatrice_b";
					totalInfo += sModel + "Беатрис Шарп (капер)! (2\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Даниэль Хоук (пожилая)";
				break;
				case 2:
					pchar.FaceId = 253;
					pchar.model = "Danny";
					totalInfo += sModel + "Даниэль Хоук (пожилая)! (1\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Даниэль Грин (молодая)";
				break;
				case 3:
					pchar.FaceId = 732;
					pchar.model = "DanielleK2";
					totalInfo += sModel + "Даниэль Грин (молодая)! (2\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Даниэль Шеппард";
				break;
				case 4:
					pchar.FaceId = 733;
					pchar.model = "DanielleGPK";
					totalInfo += sModel + "Даниэль Шеппард! (1\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Даниэль Шеппард (альтернативная текстура)";
				break;
				case 5:
					pchar.FaceId = 709;
					pchar.model = "Danielle";
					totalInfo += sModel + "Даниэль Шеппард (альтернативная текстура)! (2\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джессика Брэдфорд (живая)";
				break;
				case 6:
					pchar.FaceId = 703;
					pchar.model = "jessika";
					totalInfo += sModel + "Джессика Брэдфорд (живая)! (1\3)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джессика Брэдфорд (альтернативная текстура)";
				break;
				case 7:
					pchar.FaceId = 727;
					pchar.model = "Jessika_alt";
					totalInfo += sModel + "Джессика Брэдфорд (альтернативная текстура)! (2\3)" + NewStr() + sModer + "kucha" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Джессика Брэдфорд (нежить)";
				break;
				case 8:
					pchar.FaceId = 259;
					pchar.model = "Ghost_1";
					pchar.HeroModel = "Ghost_1";
					bProto = false;
					totalInfo += sModel + "Джессика Брэдфорд (нежить)! (3\3)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер";
				break;
				case 9:
					pchar.model = "Mary";
					totalInfo += sModel + "Мэри Каспер! (1\8)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер в шляпе";
				break;
				case 10:
					pchar.model = "MaryHat";
					totalInfo += sModel + "Мэри Каспер в шляпе! (2\8)" + NewStr() + sModer + "NikK" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер (новое лицо, вариант #1)";
				break;
				case 11:
					pchar.model = "Mary_a_nohat";
					totalInfo += sModel + "Мэри Каспер (новое лицо, вариант #1) (3\8)!" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер в шляпе (новое лицо, вариант #1)";
				break;
				case 12:
					pchar.model = "Mary_a_hat";
					totalInfo += sModel + "Мэри Каспер в шляпе (новое лицо, вариант #1) (4\8)!" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер (новое лицо, вариант #2)";
				break;
				case 13:
					pchar.model = "Mary_b_nohat";
					totalInfo += sModel + "Мэри Каспер (новое лицо, вариант #2) (5\8)!" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер в шляпе (новое лицо, вариант #2)";
				break;
				case 14:
					pchar.model = "Mary_b_hat";
					totalInfo += sModel + "Мэри Каспер в шляпе (новое лицо, вариант #2)! (6\8)" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер в шляпе (вариант #3)";
				break;
				case 15:
					pchar.model = "Mary_b_hat_alt2";
					totalInfo += sModel + "Мэри Каспер в шляпе (вариант #3)! (7\8)" + NewStr() + sModer + "модель - ZM500, текстура одежды - kucha" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мэри Каспер в шляпе (вариант #3, другое лицо)";
				break;
				case 16:
					pchar.model = "Mary_b_hat_alt";
					totalInfo += sModel + "Мэри Каспер в шляпе (вариант #3, другое лицо)! (8\8)" + NewStr() + sModer + "модель - ZM500, текстура одежды - kucha, текстура лица - Cuauhtemoc" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Элен Мак Артур";
				break;
				case 17:
					pchar.model = "Rumba";
					totalInfo += sModel + "Элен Мак Артур! (1\3)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Элен Мак Артур (новое лицо)";
				break;
				case 18:
					pchar.model = "Rumba_nohat";
					totalInfo += sModel + "Элен Мак Артур (новое лицо)! (2\3)" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Элен Мак Артур в шляпе (новое лицо)";
				break;
				case 19:
					pchar.model = "Rumba_hat";
					totalInfo += sModel + "Элен Мак Артур в шляпе (новое лицо)! (3\3)" + NewStr() + sModer + "ZM500" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Анжелика Шарп";
				break;
				case 20:
					pchar.FaceId = 707;
					pchar.model = "Angellica";
					totalInfo += sModel + "Анжелика Шарп! (1\2)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Анжелика Шарп, вариант 2";
				break;
				case 21:
					pchar.FaceId = 731;
					pchar.model = "Angellica_b";
					totalInfo += sModel + "Анжелика Шарп (вариант 2)! (2\2)" + NewStr() + sModer + "kucha" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Йоко Диаз";
				break;
				case 22:
					pchar.FaceId = 708;
					pchar.model = "YokoDias";
					pchar.name = "Йоко"; pchar.lastname = "Диаз";
					pchar.nameGen = "Йоко"; pchar.lastnameGen = "Диаз";
					pchar.nameDat = "Йоко"; pchar.lastnameDat = "Диаз";
					totalInfo += sModel + "Йоко Диаз!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sNextC + "Мелин Фермар";
				break;
				case 23:
					pchar.FaceId = 706;
					pchar.model = "SteampunkGirl";
					pchar.name = "Мелин"; pchar.lastname = "Фермар";
					pchar.nameGen = "Мелин"; pchar.lastnameGen = "Фермар";
					pchar.nameDat = "Мелин"; pchar.lastnameDat = "Фермар";
					totalInfo += sModel + "Мелин Фермар!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "NikK" + NewStr() + sNextC + "Чани";
				break;
				case 24:
					pchar.FaceId = 1337;
					pchar.model = "Chani";
					pchar.name = "Чани"; pchar.lastname = "";
					pchar.nameGen = "Чани"; pchar.lastnameGen = "";
					pchar.nameDat = "Чани"; pchar.lastnameDat = "";
					pchar.model.animation = "_CheatSurfMenu_\Chani";
					bCommonAni = false;
					totalInfo += sModel + "Чани!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "reboroda" + NewStr() + sNextC + "Цирилла Фиона Элен Рианнон";
				break;
				case 25:
					pchar.FaceId = 1337;
					pchar.model = "Cirilla";
					pchar.name = "Цирилла"; pchar.lastname = "Рианнон";
					pchar.nameGen = "Цириллы"; pchar.lastnameGen = "Рианнон";
					pchar.nameDat = "Цирилле"; pchar.lastnameDat = "Рианнон";
					pchar.model.animation = "_CheatSurfMenu_\Ciri";
					totalInfo += sModel + "Цири! (1\4)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "DeathDaisy" + NewStr() + sNextC + "Цири (другие сапоги)";
				break;
				case 26:
					pchar.model = "Cirilla_boots";
					pchar.name = "Цирилла"; pchar.lastname = "Рианнон";
					pchar.nameGen = "Цириллы"; pchar.lastnameGen = "Рианнон";
					pchar.nameDat = "Цирилле"; pchar.lastnameDat = "Рианнон";
					pchar.model.animation = "_CheatSurfMenu_\Ciri";
					totalInfo += sModel + "Цири! (2\4)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "DeathDaisy" + NewStr() + sNextC + "Цири (альтернативная прическа)";
				break;
				case 27:
					pchar.model = "Cirilla_h2";
					pchar.name = "Цирилла"; pchar.lastname = "Рианнон";
					pchar.nameGen = "Цириллы"; pchar.lastnameGen = "Рианнон";
					pchar.nameDat = "Цирилле"; pchar.lastnameDat = "Рианнон";
					pchar.model.animation = "_CheatSurfMenu_\Ciri";
					totalInfo += sModel + "Цири! (3\4)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "DeathDaisy" + NewStr() + sNextC + "Цири (другие сапоги)";
				break;
				case 28:
					pchar.model = "Cirilla_h2_boots";
					pchar.name = "Цирилла"; pchar.lastname = "Рианнон";
					pchar.nameGen = "Цириллы"; pchar.lastnameGen = "Рианнон";
					pchar.nameDat = "Цирилле"; pchar.lastnameDat = "Рианнон";
					pchar.model.animation = "_CheatSurfMenu_\Ciri";
					totalInfo += sModel + "Цири! (4\4)" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "DeathDaisy" + NewStr() + sNextC + "Ведьма";
				break;
				case 29:
					pchar.FaceId = 722;
					pchar.model = "WitchGirl";
					pchar.name = "Ведьма"; pchar.lastname = "";
					pchar.nameGen = "Ведьма"; pchar.lastnameGen = "";
					pchar.nameDat = "Ведьма"; pchar.lastnameDat = "";
					pchar.model.animation = "_CheatSurfMenu_\Witch";
					bCommonAni = false;
					totalInfo += sModel + "Ведьма!" + NewStr() + sSuitN + " | " + sMushN + NewStr() + sModer + "DeathDaisy" + NewStr() + sNextC + "Беатрис Шарп вариант #1 (пират)";
				break;
			}
			if (HasSubStr(pchar.model, "Mary"))
			{
				pchar.FaceId = 267;
				pchar.name = "Мэри"; pchar.lastname = "Каспер";
				pchar.nameGen = "Мэри"; pchar.lastnameGen = "Каспер";
				pchar.nameDat = "Мэри"; pchar.lastnameDat = "Каспер";
			}
			else
			{
				if (HasSubStr(pchar.model, "Rumba"))
				{
					pchar.FaceId = 250;
					pchar.name = "Элен"; pchar.lastname = "Мак Артур";
					pchar.nameGen = "Элен"; pchar.lastnameGen = "Мак Артур";
					pchar.nameDat = "Элен"; pchar.lastnameDat = "Мак Артур";
				}
				else
				{
					if (HasSubStr(pchar.model, "Cirilla"))
					{
						pchar.FaceId = 1337;
						pchar.HeroModel = "Cirilla_boots,protocusto,Cirilla_boots,Cirilla_boots_mush"
						pchar.name = "Цирилла"; pchar.lastname = "Рианнон";
						pchar.nameGen = "Цириллы"; pchar.lastnameGen = "Рианнон";
						pchar.nameDat = "Цирилле"; pchar.lastnameDat = "Рианнон";
						pchar.model.animation = "_CheatSurfMenu_\Ciri";
						bCommonAni = false;
					}
					else
					{
						if (HasSubStr(pchar.model, "Beatrice"))
						{
							pchar.FaceId = 701;
							pchar.name = "Беатрис"; pchar.lastname = "Шарп";
							pchar.nameGen = "Беатрис"; pchar.lastnameGen = "Шарп";
							pchar.nameDat = "Беатрис"; pchar.lastnameDat = "Шарп";
						}
						else
						{
							if (HasSubStr(pchar.model, "Danny") || HasSubStr(pchar.model, "Danielle"))
							{
								pchar.name = "Даниэль"; pchar.lastname = "Хоук";
								pchar.nameGen = "Даниэль"; pchar.lastnameGen = "Хоук";
								pchar.nameDat = "Даниэль"; pchar.lastnameDat = "Хоук";
								if (HasSubStr(pchar.model, "DanielleK2")) pchar.model.animation = "_CheatSurfMenu_\Ciri";
								else pchar.model.animation = "_CheatSurfMenu_\DannyPlayer";
								bCommonAni = false;
							}
							else
							{
								if (HasSubStr(pchar.model, "jessika") || HasSubStr(pchar.model, "Ghost_1") || HasSubStr(pchar.model, "Jessika_alt"))
								{
									pchar.name = "Джессика"; pchar.lastname = "Брэдфорд";
									pchar.nameGen = "Джессики"; pchar.lastnameGen = "Брэдфорд";
									pchar.nameDat = "Джессике"; pchar.lastnameDat = "Брэдфорд";
									pchar.model.animation = "_CheatSurfMenu_\JessikaPlayer";
									bCommonAni = false;
								}
								else
								{
									if (HasSubStr(pchar.model, "Angellica"))
									{
										pchar.name = "Анжелика"; pchar.lastname = "Шарп";
										pchar.nameGen = "Анжелики"; pchar.lastnameGen = "Шарп";
										pchar.nameDat = "Анжелике"; pchar.lastnameDat = "Шарп";
									}
								}
							}
						}
					}
				}
			}
			if (bCommonAni)
			{
				pchar.model.animation = "_CheatSurfMenu_\MaryPlayer";
			}
			if (bProto)
			{
				pchar.HeroModel = pchar.model + "," + pchar.model + "," + pchar.model + "," + pchar.model + "," + pchar.model + ",protocusto," + pchar.model + "," + pchar.model;
			}
			pchar.sex = "woman";
			pchar.defaultanimation = pchar.model.animation;
			SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
			pchar.CSM.ChangeModelW = sti(pchar.CSM.ChangeModelW) + 1;
			Characters_RefreshModel(pchar);
			EquipVisualRefresh(pchar);
			if (!bNoSound) iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			totalInfo += "Персонажу из воды бы сначала выбраться...";
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sWpnOff;
	}
	bNoSound = false;
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F67", 1);
}

string descF68 = "Вернуть анимацию для текущей модели ГГ (если её 'перекосило' после некоторых локаций)";
void CalculateInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	CommonActions();
	string sCorrect = "Модель не нуждается в смене анимации!";
	string sMushket = "Модель имеет статус мушкетера и не нуждается в смене анимации!";
	string sOrig = "Модели возвращена оригинальная анимация - ";
	bool bOKi = false;
	bool bReAni = false;
	bool bMushket = false;
	if (!HasSubStr(pchar.model.animation, "swim"))
	{
		if (HasSubStr(pchar.model, "Sharle") || HasSubStr(pchar.model, "blad") || HasSubStr(pchar.model, "Resc") ||
			HasSubStr(pchar.model, "BSharp") || HasSubStr(pchar.model, "Port") || HasSubStr(pchar.model, "Espinosa_") ||
			HasSubStr(pchar.model, "Pat") || HasSubStr(pchar.model, "BaltropGPK") || HasSubStr(pchar.model, "Migel_2") ||
			HasSubStr(pchar.model, "Alonso") || HasSubStr(pchar.model, "Maskog") || HasSubStr(pchar.model, "Archy") ||
			HasSubStr(pchar.model, "Beltrop") || HasSubStr(pchar.model, "BlackBeard") || HasSubStr(pchar.model, "Addington") ||
			HasSubStr(pchar.model, "Ezpinoza") || HasSubStr(pchar.model, "Hero1") || HasSubStr(pchar.model, "Blood5") ||
			HasSubStr(pchar.model, "Gino") || HasSubStr(pchar.model, "PotCMobCap") || HasSubStr(pchar.model, "skeletcap") ||
			HasSubStr(pchar.model, "VaterSkel_1") || HasSubStr(pchar.model, "VaterSkel_2") || HasSubStr(pchar.model, "PotCMob2") ||
			HasSubStr(pchar.model, "VaterSkel_3") || HasSubStr(pchar.model, "VaterSkel_4") || HasSubStr(pchar.model, "Terminator") ||
			HasSubStr(pchar.model, "AdamRainer") || HasSubStr(pchar.model, "Alexus") || HasSubStr(pchar.model, "Azzy") ||
			HasSubStr(pchar.model, "Barbazon") || HasSubStr(pchar.model, "Marlow") || HasSubStr(pchar.model, "Terrax") ||
			HasSubStr(pchar.model, "Svenson") || HasSubStr(pchar.model, "BigPirate") || HasSubStr(pchar.model, "quest_off_franc") ||
			HasSubStr(pchar.model, "DeLuck") || HasSubStr(pchar.model, "Shark") || HasSubStr(pchar.model, "Fleetwood") ||
			HasSubStr(pchar.model, "Itza_Urakan") || HasSubStr(pchar.model, "Chard2") || HasSubStr(pchar.model, "Tibo") ||
			HasSubStr(pchar.model, "VanBerg") || HasSubStr(pchar.model, "Shambone") || HasSubStr(pchar.model, "Lucas") ||
			HasSubStr(pchar.model, "Black") || HasSubStr(pchar.model, "Chard") || HasSubStr(pchar.model, "HuanTubercul") ||
			HasSubStr(pchar.model, "Hugh") || HasSubStr(pchar.model, "Pitt") || HasSubStr(pchar.model, "Tuttuathapack") ||
			HasSubStr(pchar.model, "GayMarshe") || HasSubStr(pchar.model, "Ostin") || HasSubStr(pchar.model, "Chard3a") ||
			HasSubStr(pchar.model, "Donald") || HasSubStr(pchar.model, "Gontier") || HasSubStr(pchar.model, "Vasces") ||
			HasSubStr(pchar.model, "Itza_Kanek") || HasSubStr(pchar.model, "Tonzag") || HasSubStr(pchar.model, "Zikomo") ||
			HasSubStr(pchar.model, "Fox") || HasSubStr(pchar.model, "Longway") || HasSubStr(pchar.model, "Chavinavi_1") ||
			HasSubStr(pchar.model, "mictlantecuhtli") || HasSubStr(pchar.model, "Adolf") || HasSubStr(pchar.model, "Billy_Pirt") ||
			HasSubStr(pchar.model, "Boss_1") || HasSubStr(pchar.model, "Boss_2") || HasSubStr(pchar.model, "Donovan") ||
			HasSubStr(pchar.model, "Dragoon_1") || HasSubStr(pchar.model, "Morgan") || HasSubStr(pchar.model, "q_eng_Cap_1") ||
			HasSubStr(pchar.model, "quest_off_eng") || HasSubStr(pchar.model, "quest_off_holl") || HasSubStr(pchar.model, "quest_off_spain") ||
			HasSubStr(pchar.model, "Rodriges") || HasSubStr(pchar.model, "Rozencraft") || HasSubStr(pchar.model, "Norrington"))
		{
			if (CheckAttribute(pchar, "IsMushketer") || pchar.model.animation == "mushketer")
			{
				bMushket = true;
			}
			else
			{
				if (pchar.model.animation != "man_A")
				{
					pchar.model.animation = "man_A";
					bReAni = true;
				}
				else
				{
					bOKi = true;
				}
			}
		}
		else
		{
			if (HasSubStr(pchar.model, "Giant"))
			{
				if (CheckAttribute(pchar, "IsMushketer") || pchar.model.animation == "mushketer")
				{
					bMushket = true;
				}
				else
				{
					if (pchar.model.animation != "giant")
					{
						pchar.model.animation = "giant";
						bReAni = true;
					}
					else
					{
						bOKi = true;
					}
				}
			}
			else
			{
				if (HasSubStr(pchar.model, "Balthrop"))
				{
					if (CheckAttribute(pchar, "IsMushketer") || pchar.model.animation == "mushketer")
					{
						bMushket = true;
					}
					else
					{
						if (pchar.model.animation != "_CheatSurfMenu_\BalthropPlayer")
						{
							pchar.model.animation = "_CheatSurfMenu_\BalthropPlayer";
							bReAni = true;
						}
						else
						{
							bOKi = true;
						}
					}
				}
				else
				{
					if (HasSubStr(pchar.model, "DevlinK3") || pchar.model == "Maska")
					{
						if (CheckAttribute(pchar, "IsMushketer") || pchar.model.animation == "mushketer")
						{
							bMushket = true;
						}
						else
						{
							if (pchar.model.animation != "_CheatSurfMenu_\BlazeKCM")
							{
								pchar.model.animation = "_CheatSurfMenu_\BlazeKCM";
								bReAni = true;
							}
							else
							{
								bOKi = true;
							}
						}
					}
					else
					{
						if (HasSubStr(pchar.model, "Mary") || HasSubStr(pchar.model, "Beatrice") || HasSubStr(pchar.model, "Rumba") || HasSubStr(pchar.model, "Angellica") || HasSubStr(pchar.model, "YokoDias") || HasSubStr(pchar.model, "SteampunkGirl"))
						{
							if (pchar.model.animation != "_CheatSurfMenu_\MaryPlayer")
							{
								pchar.model.animation = "_CheatSurfMenu_\MaryPlayer";
								bReAni = true;
							}
							else
							{
								bOKi = true;
							}
						}
						else
						{
							if (HasSubStr(pchar.model, "Danny") || HasSubStr(pchar.model, "Danielle"))
							{
								if (pchar.model.animation != "_CheatSurfMenu_\DannyPlayer")
								{
									pchar.model.animation = "_CheatSurfMenu_\DannyPlayer";
									bReAni = true;
								}
								else
								{
									bOKi = true;
								}
							}
							else
							{
								if (HasSubStr(pchar.model, "jessika") || HasSubStr(pchar.model, "Ghost_1"))
								{
									if (pchar.model.animation != "_CheatSurfMenu_\JessikaPlayer")
									{
										pchar.model.animation = "_CheatSurfMenu_\JessikaPlayer";
										bReAni = true;
									}
									else
									{
										bOKi = true;
									}
								}
								else
								{
									if (HasSubStr(pchar.model, "Chani"))
									{
										if (pchar.model.animation != "_CheatSurfMenu_\Chani")
										{
											pchar.model.animation = "_CheatSurfMenu_\Chani";
											bReAni = true;
										}
										else
										{
											bOKi = true;
										}
									}
									else
									{
										if (HasSubStr(pchar.model, "Cirilla"))
										{
											if (pchar.model.animation != "_CheatSurfMenu_\Ciri")
											{
												pchar.model.animation = "_CheatSurfMenu_\Ciri";
												bReAni = true;
											}
											else
											{
												bOKi = true;
											}
										}
										else
										{
											if (HasSubStr(pchar.model, "WitchGirl"))
											{
												if (pchar.model.animation != "_CheatSurfMenu_\Witch")
												{
													pchar.model.animation = "_CheatSurfMenu_\Witch";
													bReAni = true;
												}
												else
												{
													bOKi = true;
												}
											}
											else
											{
												if (HasSubStr(pchar.model, "Hawk_"))
												{
													if (pchar.model.animation != "_CheatSurfMenu_\man_K2")
													{
														pchar.model.animation = "_CheatSurfMenu_\man_K2";
														bReAni = true;
													}
													else
													{
														bOKi = true;
													}
												}
												else
												{
													if (pchar.model == "protocusto")
													{
														if (pchar.model.animation != "man" && pchar.model.animation != "man_A" && pchar.model.animation != "_CheatSurfMenu_\man_N")
														{
															pchar.model.animation = "man_A";
															bReAni = true;
														}
														else
														{
															bOKi = true;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (bReAni)
		{
			pchar.defaultanimation = pchar.model.animation;
			Characters_RefreshModel(pchar);
			EquipVisualRefresh(pchar);
			CheckAndSetOverloadMode(pchar);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sOrig + "'" + pchar.model.animation + "'!");
			totalInfo += sOrig + "'" + pchar.model.animation + "'!";
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			if (bOKi)
			{
				Log_info(sCorrect);
				totalInfo += sCorrect;
			}
			if (bMushket)
			{
				Log_info(sMushket);
				totalInfo += sMushket;
			}
		}
	}
	else
	{
		if (loadedlocation.type == "underwater")
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			totalInfo += "ГГ под водой!\nЕсли в смене анимации все же будет нужда, активируйте эту опцию как выберитесь на сушу.";
		}
		else
		{
			pchar.model.animation = "man";
			CalculateInfoDataF68();
			return;
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F68", 1);
}

string descF69 = "Модели Шарля с 3d кирасами";
void CalculateInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	CommonActions();
	if (SendMessage(pchar, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		RemoveMushket(pchar);
		pchar.FaceId = 201;
		pchar.model = "Sharle_1";
		pchar.HeroModel = "Sharle_1,Sharle_visual_cirass_2,Sharle_visual_cirass_3,Sharle_visual_cirass_4,Sharle_visual_cirass_5,protocusto,Sharle_6,Sharle_8";
		pchar.name = "Шарль"; pchar.lastname = "де Мор";
		pchar.nameGen = "Шарля"; pchar.lastnameGen = "де Мора";
		pchar.nameDat = "Шарлю"; pchar.lastnameDat = "де Мору";
		pchar.sex = "man";
		pchar.model.animation = "man_A";
		pchar.defaultanimation = "man_A";
		pchar.nation = FRANCE;
		pchar.BaseNation = FRANCE;
		Characters_RefreshModel(pchar);
		EquipVisualRefresh(pchar);
		SetNewPicture("CSMPICTURE", sFaces + sti(pchar.FaceId) + ".tga");
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "На Шарле будут видны надетые тяжелые кирасы!" + NewStr() + sModer + "Mett (на основе мода 'Делвин Блейз' от VVV100)";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sWpnOff;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F69", 1);
}

string descF70 = "Смена анимации блока для героя ('восьмерка' или статичный блок)";
void CalculateInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	CommonActions();
	bool bCommon = false;
	if (SendMessage(pchar, "ls", MSG_CHARACTER_EX_MSG, "IsFightMode") == 0)
	{
		RemoveMushket(pchar);
		if (pchar.model.animation == "man" || pchar.model.animation == "man_N") pchar.model.animation = "man_A";
		if (pchar.model.animation == "man_A" || pchar.model.animation == "_CheatSurfMenu_\man_N")
		{
			switch (pchar.model.animation)
			{
				case "man_A":
					pchar.model.animation = "_CheatSurfMenu_\man_N";
					pchar.defaultanimation = "_CheatSurfMenu_\man_N";
					bCommon = true;
					totalInfo += "Выбрана анимация со статичным блоком!";
				break;
				case "_CheatSurfMenu_\man_N":
					pchar.model.animation = "man_A";
					pchar.defaultanimation = "man_A";
					bCommon = true;
					totalInfo += "Выбрана анимация с блоком 'восьмеркой' (оригинальная анимация для ККС)!";
				break;
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			totalInfo += "Данная опция работает только для мужских моделей с анимацией из К:ГПК!";
		}
		if (bCommon)
		{
			Characters_RefreshModel(pchar);
			EquipVisualRefresh(pchar);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += sWpnOff;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM1.F70", 1);
}

// 2do: проинитить офов
void CommonAttributes(ref rChar)
{
	if (rChar.id == -1) { return; }
	string itm;
	FaceMaker(rChar);
	rChar.CSM.NPC = true;
	rChar.Dialog.Filename = "Enc_Officer_dialog.c";
	rChar.dialog.currentnode = "hired";
	if (!CheckAttribute(rChar, "defaultanimation")) { rChar.defaultanimation = rChar.model.animation; }
	if (!CheckAttribute(pchar, "CSM.AddOfficersVar")) { pchar.CSM.AddOfficersVar = 0; }
	SetSPECIAL(rChar, 10, 10, 10, 10, 10, 10, 10);
	switch (sti(pchar.CSM.AddOfficersVar))
	{
		case 0:
			rChar.rank = 1;
			DeleteAttribute(rChar, "perks.list");
			LAi_SetHP(rChar, 80.0, 80.0);
			SetRandSelfSkill(rChar, 10, 10);
			SetRandShipSkill(rChar, 10, 10);
		break;
		case 1:
			rChar.rank = sti(pchar.rank);
			if (sti(rChar.rank) < 1) { rChar.rank = 1; }
			LAi_SetHP(rChar, stf(pchar.chr_ai.hp_max), stf(pchar.chr_ai.hp_max));
			if (stf(rChar.chr_ai.hp_max) < 80.0) { LAi_SetHP(rChar, 80.0, 80.0); }
			DeleteAttribute(rChar, "perks.list");
			SetPcharSelfSkills2NPC(rChar);
			SetPcharShipSkills2NPC(rChar);
			SetPcharPerks2NPC(rChar);
		break;
		case 2:
			rChar.rank = 55;
			LAi_SetHP(rChar, 555.0, 555.0);
			SelAllPerksToChar(rChar, true);
			SetRandSelfSkill(rChar, 100, 100);
			SetRandShipSkill(rChar, 100, 100);
		break;
	}
	SetBasePerks(rChar);
	rChar.quest.OfficerPrice = sti(pchar.rank)*500;
	LAi_SetImmortal(rChar, false);
	rChar.HalfImmortal = true;
	rChar.OfficerWantToGo.DontGo = true;
	rChar.CompanionDisable = false;
	rChar.loyality = MAX_LOYALITY;
	SetCharacterRemovable(rChar, true);
	rChar.Payment = true;
	rChar.DontClearDead = true;
	DeleteAttribute(rChar, "HoldEquip");
	if (!CheckAttribute(rChar, "CSM.CommonAttributes"))
	{
		AddPassenger(pchar, rChar, false);
		LAi_SetOfficerType(rChar);
		LAi_group_MoveCharacter(rChar, LAI_GROUP_PLAYER);
		SaveCurrentNpcQuestDateParam(rChar, "HiredDate");
	}
	if (!CheckAttribute(rChar, "IsMushketer") || rChar.model.animation != "mushketer") // на всякий случай
	{
		if (!CheckCharacterItem(rChar, "pistol5"))
		{
			GiveItem2Character(rChar, "pistol5");
			if (GetCharacterEquipByGroup(rChar, GUN_ITEM_TYPE) == "") EquipCharacterbyItem(rChar, "pistol5");
		}
		if (!CheckCharacterItem(rChar, "cirass4"))
		{
			GiveItem2Character(rChar, "cirass4");
			if (GetCharacterEquipByGroup(rChar, CIRASS_ITEM_TYPE) == "") EquipCharacterbyItem(rChar, "cirass4");
		}
	}
	else
	{
		if (!CheckCharacterItem(rChar, "pistol5") || !CheckCharacterItem(rChar, "cirass4"))
		{
			itm = GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE);
			if (itm != "") { SetOfficerToMushketer(rChar, itm, false); }
			if (!CheckCharacterItem(rChar, "pistol5"))
			{
				GiveItem2Character(rChar, "pistol5");
				if (GetCharacterEquipByGroup(rChar, GUN_ITEM_TYPE) == "") EquipCharacterbyItem(rChar, "pistol5");
			}
			if (!CheckCharacterItem(rChar, "cirass4"))
			{
				GiveItem2Character(rChar, "cirass4");
				if (GetCharacterEquipByGroup(rChar, CIRASS_ITEM_TYPE) == "") EquipCharacterbyItem(rChar, "cirass4");
			}
			if (itm != "") { SetOfficerToMushketer(rChar, itm, true); }
		}
	}
	if (!CheckCharacterItem(rChar, "potion4")) TakeNItems(rChar, "potion4", 10);
	if (!CheckCharacterItem(rChar, "cartridge")) TakeNItems(rChar, "cartridge", 50);
	LAi_SetCharacterUseBullet(rChar, "cartridge");
	Characters_RefreshModel(rChar);
	EquipVisualRefresh(rChar);
	rChar.CSM.CommonAttributes = true;
}

// Отображение экипировки после смены модели -->
void EquipVisualRefresh(ref rChar)
{
	if (rChar.id == -1) { return; }
	// LAi_SetFightMode(rChar, false);
	string sCirass = GetCharacterEquipByGroup(rChar, CIRASS_ITEM_TYPE);
/*
	string sBlade;
	string sBladeE = GetCharacterEquipByGroup(rChar, BLADE_ITEM_TYPE);
	if (sBladeE != "")
	{
		sBlade = sBladeE;
		RemoveCharacterEquip(rChar, BLADE_ITEM_TYPE);
		EquipCharacterbyItem(rChar, sBlade);
	}
*/
	SetNewModelToChar(rChar);
	if (sCirass != "")
	{
		RemoveCharacterEquip(rChar, CIRASS_ITEM_TYPE);
		EquipCharacterbyItem(rChar, sCirass);
		// if (HasSubStr(sCirass, "cirass")) Log_info("Кираса снята с персонажа и помещена в инвентарь.");
		// else Log_info("Костюм снят с персонажа и помещен в инвентарь.");
	}
}
// <--

void SetPcharSelfSkills2NPC(ref rChar)
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

void SetPcharShipSkills2NPC(ref rChar)
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

void SetPcharPerks2NPC(ref rChar)
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

// Снятие с перса мушкета (и водолазного костюма) для корректной смены модели -->
void RemoveMushket(ref rChar)
{
	if (rChar.id == -1) { return; }
//	LAi_SetFightMode(rChar, false);

	string sMushket = GetCharacterEquipByGroup(rChar, GUN_ITEM_TYPE);
	string sCirass = GetCharacterEquipByGroup(rChar, CIRASS_ITEM_TYPE);

	if (sMushket != "")
	{
		if (HasSubStr(sMushket, "mushket"))
		{
			if (rChar.id == pchar.id)
			{
				SetMainCharacterToMushketer(sMushket, false);
			}
			else
			{
				SetOfficerToMushketer(rChar, sMushket, false);
			}
			Log_info("Мушкет снят с персонажа и помещен в инвентарь.");
		}
	}

	if (sCirass != "")
	{
		if (HasSubStr(sCirass, "underwater"))
		{
			RemoveCharacterEquip(rChar, CIRASS_ITEM_TYPE);
			CheckAndSetOverloadMode(rChar);
		}
	}
}
// <--

string GetAddOfficersVar(bool AddOffVarNext)
{
	string sAddOfficersVar;
	if (!CheckAttribute(pchar, "CSM.AddOfficersVar")) { pchar.CSM.AddOfficersVar = 0; }
	switch (sti(pchar.CSM.AddOfficersVar))
	{
		case 0:
			if (AddOffVarNext) sAddOfficersVar = " (вариант 2 из 3: ранг, HP, умения и перки как у ГГ)"; // чтобы поспевала функция #41
			else sAddOfficersVar = " (вариант 1 из 3: 1-ый ранг и ничему не обучены)";
		break;
		case 1:
			if (AddOffVarNext) sAddOfficersVar = " (вариант 3 из 3: 55-ый ранг и полная прокачка)";
			else sAddOfficersVar = " (вариант 2 из 3: ранг, HP, умения и перки как у ГГ)";
		break;
		case 2:
			if (AddOffVarNext) sAddOfficersVar = " (вариант 1 из 3: 1-ый ранг и ничему не обучены)";
			else sAddOfficersVar = " (вариант 3 из 3: 55-ый ранг и полная прокачка)";
		break;
	}
	return sAddOfficersVar;
}

// от сих -->
void csmArrowLeft()
{
	if (!bShowArrows || !CheckAttribute(pchar, "CSM.ArrowsType")) return;

	bNoSound = true; // или все же оставить звуки?

	switch (sti(pchar.CSM.ArrowsType))
	{
		case 0: CalculateInfoDataF20(); break;
		case 1:
			if (sti(pchar.CSM.ChangeModelM) <= 1) pchar.CSM.ChangeModelM = 110;
			pchar.CSM.ChangeModelM = sti(pchar.CSM.ChangeModelM) - 2;
			CalculateInfoDataF66();
		break;
		case 2:
			if (sti(pchar.CSM.ChangeModelW) <= 1) pchar.CSM.ChangeModelW = 31;
			pchar.CSM.ChangeModelW = sti(pchar.CSM.ChangeModelW) - 2;
			CalculateInfoDataF67();
		break;
	}
}

void csmArrowRight()
{
	if (!bShowArrows || !CheckAttribute(pchar, "CSM.ArrowsType")) return;

	bNoSound = true; // или все же оставить звуки?

	switch (sti(pchar.CSM.ArrowsType))
	{
		case 0: CalculateInfoDataF21(); break;
		case 1: CalculateInfoDataF66(); break;
		case 2: CalculateInfoDataF67(); break;
	}
}

void csmHideImages()
{
	SetNewPicture("CSMPICTURE", "Blank.tga");
	DeleteAttribute(pchar, "CSM.ArrowsType");
	CreateImage("CSM_ArrowLeft", "icons", "left arrow", 0, 0, 0, 0);
	CreateImage("CSM_ArrowRight", "icons", "right arrow", 0, 0, 0, 0);
/*
	//Для след. dlc
	CreateImage("CSM_ArrowLeft", "icons", "left arrow green", 0, 0, 0, 0);
	CreateImage("CSM_ArrowRight", "icons", "right arrow green", 0, 0, 0, 0);
	CreateImage("CSM_ArrowLeft", "icons", "left arrow red", 0, 0, 0, 0);
	CreateImage("CSM_ArrowRight", "icons", "right arrow red", 0, 0, 0, 0);
*/
}
// до сих потом перекинуть в CheatSurfMenu.c <--

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

	switch (sNode)
	{
		case "INFO_TEXT":
			sHeader = "Описание меню 'Персонаж'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Персонаж' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Персонаж'";
			sText1 = "Перезапуск меню 'Персонаж'";
		break;
		case "B_M1":
			sHeader = "Меню 'Умения'";
			sText1 = "Запуск меню 'Умения'";
		break;
		case "B_M2":
			sHeader = "Меню 'Предметы'";
			sText1 = "Запуск меню 'Предметы'";
		break;
		case "B_M3":
			sHeader = "Меню 'Корабль'";
			sText1 = "Запуск меню 'Корабль'";
		break;
		case "B_M4":
			sHeader = "Меню 'Локации'";
			sText1 = "Запуск меню 'Локации'";
		break;
		case "B_M5":
			sHeader = "Меню 'Товары'";
			sText1 = "Запуск меню 'Товары'";
		break;
		case "B_M6":
			sHeader = "Меню 'Офицеры'";
			sText1 = "Запуск меню 'Офицеры'";
		break;
		case "B_M7":
			sHeader = "Меню 'Корабли'";
			sText1 = "Запуск меню 'Корабли'";
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
