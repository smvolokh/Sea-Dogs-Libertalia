
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Предметы
	Основано на меню дебаггера от boal
	03.06.2018
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Предметы' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sDrop = "\n\nЛишнее можно выкинуть, дважды кликнув по вещи в инвентаре.";
string sUnarmed = "Холодное оружие не экипированно!";
string sModer = "Автор(ы) мода: ";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_items";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(2); // Warship. Статистика - сколько читов юзали
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
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() +
					"< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() +
					"< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() +
					"\n\n< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() +
					"< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() +
					"< 43 > " + descF43 + NewStr() + "\n\n< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"\n\n< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() +
					"< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() + "< 54 > " + descF54 + NewStr() +
					"< 55 > " + descF55 + NewStr() + "< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() +
					"< 58 > " + descF58 + NewStr() + "< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() +
					"< 61 > " + descF61 + NewStr() + "< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() +
					"< 64 > " + descF64 + NewStr() + "< 65 > " + descF65 + NewStr() + "< 66 > " + descF66 + NewStr() +
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(2); // Статистика по читам
}

string descF1 = "Получить все зелья и напитки (по 10 штук)";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	for (int i=1; i<=7; i++)
	{
		TakenItems(pchar, "potion"+i, 10);
	}
	TakenItems(pchar, "potionrum", 10);
	TakenItems(pchar, "potionwine", 10);
	TakenItems(pchar, "Ultimate_potion", 10);
	TakenItems(pchar, "berserker_potion", 10);
	TakenItems(pchar, "mangarosapower", 10);
	TakenItems(pchar, "mangarosafast", 10);
	TakenItems(pchar, "mangarosatotal", 10);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все зелья и напитки получены!");
	totalInfo += "Все зелья и напитки получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F1", 1);
}

string descF2 = "Получить бумажные патроны и пули для револьвера (по 100 штук)";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	TakenItems(pchar, "cartridge", 100);
	TakenItems(pchar, "GunCap_colt", 100);
	TakenItems(pchar, "shotgun_cartridge", 100);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Бумажные патроны и пули для револьвера получены!");
	totalInfo += "Бумажные патроны и пули для револьвера получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F2", 1);
}

string descF3 = "Получить все прочие боеприпасы каждого типа (по 100 штук)";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	TakenItems(pchar, "bullet", 100);
	TakenItems(pchar, "grapeshot", 100);
	TakenItems(pchar, "powder_pellet", 100);
	TakenItems(pchar, "grenade", 100);
	TakenItems(pchar, "harpoon", 100);
	TakenItems(pchar, "GunPowder", 100);
	TakenItems(pchar, "GunEchin", 100);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все виды боеприпасов получены!");
	totalInfo += "Все виды боеприпасов получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F3", 1);
}

string descF4 = "Получить все Рапиры/Шпаги (легкое оружие)";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	ref rItem;
	string sBlade;
	TakenItems(pchar, "slave_01", 1);
	sBlade = GetBestGeneratedItem("blade_01"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_03"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_08"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_09"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_15"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_16"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_17"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_18"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_22"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_25"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_26"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_27"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade37"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade39"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade46"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade42"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade48"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade2"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade11"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade13"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade18"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade8"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade20"); TakenItems(pchar, sBlade, 1);
	rItem = ItemsFromID("knife_01");
	if (rItem.price > 0 && rItem.Weight == 1.5 && !CheckCharacterItem(pchar, "knife_01"))
	{
		TakenItems(pchar, "knife_01", 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Всё холодное оружие класса Рапиры/Шпаги получено!");
	totalInfo += "Всё холодное оружие класса Рапиры/Шпаги получено!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F4", 1);
}

string descF5 = "Получить все Сабли/Тесаки (среднее оружие)";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	string sBlade;
	sBlade = GetBestGeneratedItem("slave_02"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_02"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_04"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_05"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_10"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_11"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_12"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_19"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_20"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_23"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade38"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade41"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade50"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade51"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade49"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade1"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade3"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade4"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade23"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade24"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade25"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade26"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade27"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade6"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade10"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade16"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade17"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade28"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade52");
 TakenItems(pchar, sBlade, 1);
	{
		sBlade = GetBestGeneratedItem("blade_28"); TakenItems(pchar, sBlade, 1);
	}
	sBlade = GetBestGeneratedItem("blade_29"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_30"); TakenItems(pchar, sBlade, 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Всё холодное оружие класса Сабли/Тесаки получено!");
	totalInfo += "Всё холодное оружие класса Сабли/Тесаки получено!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F5", 1);
}

string descF6 = "Получить все Палаши/Топоры (тяжелое оружие)";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	ref rItem;
	string sBlade;
	sBlade = GetBestGeneratedItem("blade_06"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_07"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_13"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_14"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_21"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_24"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_31"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_32"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_33"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_36"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_01"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade29"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_02"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_03"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_04"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_05"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_012"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_07"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("Blade300"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("Blade301"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade40"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade43"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade44"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade45"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade47"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_011"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("Blade53"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_010"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_08"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade5"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade9"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_013"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_014"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade12"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade14"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade15"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_019"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_018"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_017"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_016"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_015"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_020"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("topor_021"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade19"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade21"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade22"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("newblade7"); TakenItems(pchar, sBlade, 1);
	;sBlade = GetBestGeneratedItem("topor_09"); TakenItems(pchar, sBlade, 1);
	{
		TakenItems(pchar, "topor_06", 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Всё холодное оружие класса Палаши/Топоры получено!");
	totalInfo += "Всё холодное оружие класса Палаши/Топоры получено!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F6", 1);
}

string descF7 = "Получить всё оружие мастера Юргена Шмидта";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	TakenItems(pchar, "q_blade_10", 1);
	TakenItems(pchar, "q_blade_13", 1);
	TakenItems(pchar, "q_blade_16", 1);
	TakenItems(pchar, "q_blade_18", 1);
	TakenItems(pchar, "q_blade_19", 1);
	TakenItems(pchar, "q_blade_21", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Всё холодное оружие мастера Юргена Шмидта получено!");
	totalInfo += "Всё холодное оружие мастера Юргена Шмидта получено!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F7", 1);
}

string descF8 = "Получить все пистолеты";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	for (int i=1; i<=9; i++)
	{
		TakenItems(pchar, "pistol"+i, 1);
	}
	TakenItems(pchar, "pistol9", 1);
	TakenItems(pchar, "pistol_01", 1);
	TakenItems(pchar, "pistol_03", 1);
	TakenItems(pchar, "pistol_05", 1);
	TakenItems(pchar, "pistol_02", 1);
	TakenItems(pchar, "pistol_04", 1);
	TakenItems(pchar, "pistol_06", 1);
	TakenItems(pchar, "pistol_08", 1);
	TakenItems(pchar, "pistol10", 1);
	TakenItems(pchar, "pistol11", 1);
	TakenItems(pchar, "pistol02", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все пистолеты получены!");
	totalInfo += "Все пистолеты получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F8", 1);
}

string descF9 = "Получить все мушкеты";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	for (int i=1; i<=6; i++)
	{
		if (i == 4) continue;
		TakenItems(pchar, "mushket"+i, 1);
	}
	TakenItems(pchar, "grape_mushket", 1);
	TakenItems(pchar, "mushket5", 1);
	TakenItems(pchar, "mushket6", 1);
	TakenItems(pchar, "mushket2x2", 1);
	TakenItems(pchar, "mushkett2x2", 1);
	TakenItems(pchar, "mushket_01", 1);
	TakenItems(pchar, "mushket_10", 1);
	TakenItems(pchar, "mushket_9", 1);
	TakenItems(pchar, "mushket_8", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все мушкеты получены!");
	totalInfo += "Все мушкеты получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F9", 1);
}

string descF10 = "Получить все кирасы, костюмы и сумки";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	for (int i=1; i<=8; i++)
	{
		TakenItems(pchar, "cirass"+i, 1);
	}
	TakenItems(pchar, "suit1", 1);
	TakenItems(pchar, "suit4", 1);
	TakenItems(pchar, "BackPack1", 1);
	TakenItems(pchar, "BackPack2", 1);
	TakenItems(pchar, "BackPack3", 1);
	TakenItems(pchar, "BackPack4", 1);
	if (CheckAttribute(pchar, "CSM.Test"))
	{
		if (!CheckCharacterItem(pchar, "underwater")) TakeNItems(pchar, "underwater", 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Получены все кирасы, костюмы и сумки!");
	totalInfo += "Получены все кирасы, костюмы и сумки!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F10", 1);
}

string descF11 = "Получить все подзорные трубы и навигационные приборы + лоцию ГПК (если её нет, а она нужна)";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	ref rXep, rItm;
	for (int i=1; i<=5; i++)
	{
		TakenItems(pchar, "spyglass"+i, 1);
	}
	TakenItems(pchar, "sextant2", 1);
	TakenItems(pchar, "clock2", 1);
	TakenItems(pchar, "bussol", 1);
	if (!CheckCharacterItem(pchar, "LSC_navigation_map"))
	{
		rItm = ItemsFromID("LSC_navigation_map");
		rXep = characterFromId("Pirates_shipyarder");
		if (CheckAttribute(rXep, "quest.sextant") || rItm.price > 0)
		{
			TakenItems(pchar, "LSC_navigation_map", 1);
			Log_info("Получена лоция острова Справедливости!");
			totalInfo += "Получена лоция острова Справедливости!\n";
		}
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все подзорные трубы и навигационные приборы получены!");
	totalInfo += "Все подзорные трубы и навигационные приборы получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F11", 1);
}

string descF12 = "Получить лучшую экипировку от подзорной трубы до кирасы";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	string sBlade;
	sBlade = GetBestGeneratedItem("blade_25"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_26"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_28"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_29"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_21"); TakenItems(pchar, sBlade, 1);
	sBlade = GetBestGeneratedItem("blade_24"); TakenItems(pchar, sBlade, 1);
	TakenItems(pchar, "q_blade_18", 1);
	TakenItems(pchar, "q_blade_19", 1);
	TakenItems(pchar, "q_blade_21", 1);
	TakenItems(pchar, "spyglass5", 1);
	TakenItems(pchar, "pistol5", 1);
	TakenItems(pchar, "pistol7", 1);
	TakenItems(pchar, "pistol10", 1);
	TakenItems(pchar, "pistol9", 1);
	TakenItems(pchar, "mushket2x2", 1);
	TakenItems(pchar, "cirass4", 1);
	TakenItems(pchar, "cartridge", 100);
	TakenItems(pchar, "GunCap_colt", 50);
	TakenItems(pchar, "shotgun_cartridge", 50);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Всё лучшее вооружение получено!");
	totalInfo += "Всё лучшее вооружение получено!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F12", 1);
}

string descF13 = "Получить все амулеты";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	int i;
	for (i=1; i<=11; i++)
	{
		TakenItems(pchar, "amulet_"+i, 1);
		TakenItems(pchar, "obereg_"+i, 1);
		TakenItems(pchar, "indian_"+i, 1);
	}
	// by Sticksъ -->
	// ============= калеучные шмотки. Как быть, если не установлено DLC Калеуче?
    // Добавки в инвентарь не достаточно, надо их сделать пригодными к использованию
    // один из амулетов в игре вроде как не используется, добавим только два
	ref kaleItem;
	for (i=2; i<=3; i++)
	{
		TakenItems(pchar, "kaleuche_amulet" + i, 1);
		kaleItem = ItemsFromID("kaleuche_amulet" + i);
		kaleItem.picTexture = "ITEMS_36";
		kaleItem.picIndex = 11 + i;
		kaleItem.groupID    = ITEM_SLOT_TYPE;
		kaleItem.ItemType = "ARTEFACT";
		kaleItem.Type = ITEM_AMULET;
		if (CheckAttribute(kaleItem, "time"))
		{
			if (kaleItem.time != -1)
			{
				kaleItem.time = 30;
			}
		}
		else
		{
			kaleItem.time = 30;
		}
		kaleItem.kind = "fighter";
		kaleItem.price = 5000;
		if (i == 2)
			ChangeItemDescribe("kaleuche_amulet" + i, "itmdescr_kaleuche_amulet2_sword"); // меняем описание на то, что должно появиться после отшаманивания
		if (i == 3)
			ChangeItemDescribe("kaleuche_amulet" + i, "itmdescr_kaleuche_amulet3_shield"); // меняем описание на то, что должно появиться после отшаманивания
		DeleteAttribute(kaleItem, "unique");
	}
	TakenItems(pchar, "KhaelRoa_item", 1);
	kaleItem = ItemsFromID("KhaelRoa_item");
	kaleItem.groupID    = ITEM_SLOT_TYPE;
	kaleItem.ItemType = "ARTEFACT";
	kaleItem.Type = ITEM_AMULET;
	if (CheckAttribute(kaleItem, "time"))
	{
		if (kaleItem.time != -1)
		{
			kaleItem.time = 2;
		}
	}
	else
	{
		kaleItem.time = 2;
	}
	kaleItem.kind = "fighter";
	kaleItem.price = 5000;
	kaleItem.Weight = 10.0;
    // ==============
	// by Sticksъ <--
	TakenItems(pchar, "indian_poison", 1);
	TakenItems(pchar, "clock2", 1);
	TakenItems(pchar, "rat_poison", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Получены все амулеты!");
	totalInfo += "Получены все амулеты!\nАмулеты по 'Калеуче' добавил Sticksъ" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F13", 1);
}

string descF14 = "Получить все обереги";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	for (int i = 1; i <= 8; i++)
	{
		if (i == 5) continue;
		TakenItems(pchar, "talisman" + i, 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Получены все обереги!");
	totalInfo += "Получены все обереги!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F14", 1);
}

string descF15 = "Получить все талисманы";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	for (int i = 1; i <= 13; i++)
	{
		if (i <= 9) TakenItems(pchar, "totem_0" + i, 1);
		else TakenItems(pchar, "totem_" + i, 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Получены все талисманы!");
	totalInfo += "Получены все талисманы!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F15", 1);
}

string descF16 = "Изменить срок службы всех амулетов и талисманов до бесконечности \ по умолчанию";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	ref iid, sld, rItem;
	sld = ItemsFromID("amulet_1");
	int i;
	if (!CheckAttribute(sld, "time") || sld.time == -1)
	{
		for (i=1; i<=7; i++)
		{
			iid = ItemsFromID("amulet_"+i); iid.time = 70;
		}
		for (i=8; i<=11; i++)
		{
			iid = ItemsFromID("amulet_"+i); iid.time = 50;
		}
		for (i=1; i<=7; i++)
		{
			iid = ItemsFromID("indian_"+i); iid.time = 70;
		}
		for (i=8; i<=11; i++)
		{
			iid = ItemsFromID("indian_"+i); iid.time = 50;
		}
		for (i=1; i<=5; i++)
		{
			iid = ItemsFromID("obereg_"+i); iid.time = 45;
		}
		for (i=6; i<=9; i++)
		{
			iid = ItemsFromID("obereg_"+i); iid.time = 30;
		}
		// by Sticksъ -->
		// =============== калеучные вещи (честные)
		for (i=2; i<=3; i++)
		{
			rItem = ItemsFromID("kaleuche_amulet" + i);
			if (CheckAttribute(rItem, "groupID") && rItem.groupID == TALISMAN_ITEM_TYPE) break;
			if (!CheckAttribute(rItem, "groupID") || rItem.groupID == ITEM_SLOT_TYPE || rItem.ItemType != "ARTEFACT" || !CheckAttribute(rItem, "time"))
			{
				rItem.picTexture = "ITEMS_36";
				rItem.picIndex = 8 + i;
				rItem.groupID = ITEM_SLOT_TYPE;
				rItem.ItemType = "ARTEFACT";
				rItem.Type = ITEM_AMULET;
				rItem.time = 30;
				rItem.price = 5000;
				rItem.kind = "fighter";
				DeleteAttribute(rItem, "unique");
			}
			else
			{
				rItem.time = 30;
			}
		}
		rItem = ItemsFromID("KhaelRoa_item");
		if (!CheckAttribute(rItem, "groupID") || rItem.ItemType != "ARTEFACT" || !CheckAttribute(rItem, "time"))
		{
			rItem.groupID = ITEM_SLOT_TYPE;
			rItem.ItemType = "ARTEFACT";
			rItem.Type = ITEM_AMULET;
			rItem.time = 2;
			rItem.price = 5000;
			rItem.Weight = 10.0;
			rItem.kind = "fighter";
		}
		else
		{
			rItem.time = 2;
		}
        // ===============
		// by Sticksъ <--
		iid = ItemsFromID("indian_poison"); iid.time = 2;
		iid = ItemsFromID("obereg_10"); iid.time = 45;
		iid = ItemsFromID("obereg_11"); iid.time = 30;
		iid = ItemsFromID("rat_poison"); iid.time = 60;
		iid = ItemsFromID("totem_01"); iid.time = 30;
		iid = ItemsFromID("totem_02"); iid.time = 90;
		iid = ItemsFromID("totem_03"); iid.time = 30;
		iid = ItemsFromID("totem_04"); iid.time = 90;
		iid = ItemsFromID("totem_05"); iid.time = 360;
		iid = ItemsFromID("totem_06"); iid.time = 120;
		iid = ItemsFromID("totem_07"); iid.time = 45;
		iid = ItemsFromID("totem_08"); iid.time = 45;
		iid = ItemsFromID("totem_09"); iid.time = 45;
		iid = ItemsFromID("totem_10"); iid.time = 45;
		iid = ItemsFromID("totem_11"); iid.time = 45;
		iid = ItemsFromID("totem_12"); iid.time = 90;
		iid = ItemsFromID("totem_13"); iid.time = 45;
		iid = ItemsFromID("clock2"); iid.time = 30;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Срок службы амулетов и талисманов: по умолчанию.");
		totalInfo += "Срок службы амулетов и талисманов: по умолчанию." + NewStr() + "Повторное нажатие увеличит срок службы побрякушек до бесконечности!";
	}
	else
	{
		for (i=1; i<=11; i++)
		{
			iid = ItemsFromID("amulet_"+i);
			iid.time = -1;
			iid = ItemsFromID("indian_"+i);
			iid.time = -1;
			iid = ItemsFromID("obereg_"+i);
			iid.time = -1;
		}
		for (i=1; i<=9; i++)
		{
			iid = ItemsFromID("totem_0"+i);
			iid.time = -1;
		}
		for (i=0; i<=3; i++)
		{
			iid = ItemsFromID("totem_1"+i);
			iid.time = -1;
		}
		// by Sticksъ -->
		// =============== калеучные вещи (вечные)
		for (i=2; i<=3; i++)
		{
			rItem = ItemsFromID("kaleuche_amulet" + i);
			if (CheckAttribute(rItem, "groupID") && rItem.groupID == TALISMAN_ITEM_TYPE) break;
			if (!CheckAttribute(rItem, "groupID") || rItem.groupID == ITEM_SLOT_TYPE || rItem.ItemType != "ARTEFACT" || !CheckAttribute(rItem, "time"))
			{
				rItem.picTexture = "ITEMS_36";
				rItem.picIndex = 8 + i;
				rItem.groupID = ITEM_SLOT_TYPE;
				rItem.ItemType = "ARTEFACT";
				rItem.Type = ITEM_AMULET;
				rItem.time = -1;
				rItem.price = 5000;
				rItem.kind = "fighter";
				DeleteAttribute(rItem, "unique");
			}
			else
			{
				rItem.time = -1;
			}
		}
		rItem = ItemsFromID("KhaelRoa_item");
		if (!CheckAttribute(rItem, "groupID") || rItem.ItemType != "ARTEFACT" || !CheckAttribute(rItem, "time"))
		{
			rItem.groupID = ITEM_SLOT_TYPE;
			rItem.ItemType = "ARTEFACT";
			rItem.Type = ITEM_AMULET;
			rItem.time = -1;
			rItem.price = 5000;
			rItem.Weight = 10.0;
			rItem.kind = "fighter";
		}
		else
		{
			rItem.time = -1;
		}
        // ===============
		// by Sticksъ <--
		iid = ItemsFromID("indian_poison"); iid.time = -1;
		iid = ItemsFromID("clock2"); iid.time = -1;
		iid = ItemsFromID("rat_poison"); iid.time = -1;
		Log_info("Срок службы амулетов и талисманов бесконечен! Они не пропадают при снятии!");
		totalInfo += "Срок службы амулетов и талисманов бесконечен! Они не пропадают при снятии!" + NewStr() + "Повторное нажатие выставит срок службы побрякушек (кроме экипированных) по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F16", 1);
}

string descF17 = "Все амулеты совместимы между собой \ по умолчанию";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllArtsCanBeEquipped"))
	{
		pchar.CSM.AllArtsCanBeEquipped = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Все группы амулетов совместимы друг с другом при экипировке!");
		totalInfo += "Все группы амулетов совместимы друг с другом при экипировке!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllArtsCanBeEquipped");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Совместимость побрякушек выставлена по умолчанию.");
		totalInfo += "Совместимость побрякушек выставлена по умолчанию.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F17", 1);
}

string descF18 = "Сменить тип побрякушек по 'Калеуче' (амулеты или талисманы)";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	int i;
	ref rItem, rAmul;
	bool bIsEquip = false;
	string sArtType = "амулеты! (3 слота, ограниченный срок действия)";
	for (i = 2; i <= 3; i++)
	{
		if (!IsEquipCharacterByArtefact(pchar, "kaleuche_amulet2") && !IsEquipCharacterByArtefact(pchar, "kaleuche_amulet3"))
		{
			rItem = ItemsFromID("kaleuche_amulet" + i);
			rItem.picTexture = "ITEMS_36";
			rItem.price = 5000;
			rItem.ItemType = "ARTEFACT";
			rItem.kind = "fighter";
			if (!CheckAttribute(rItem, "groupID")) { rItem.groupID = TALISMAN_ITEM_TYPE; }
			if (rItem.groupID == TALISMAN_ITEM_TYPE)
			{
				rItem.picIndex = 8 + i;
				rItem.groupID = ITEM_SLOT_TYPE;
				rItem.Type = ITEM_AMULET;
				rAmul = ItemsFromID("amulet_1");
				if (rAmul.time > 0) rItem.time = 30;
				else rItem.time = -1;
				DeleteAttribute(rItem, "unique");
			}
			else
			{
				sArtType = "талисманы! (1 слот, неограниченный срок действия)";
				rItem.picIndex = 11 + i;
				rItem.groupID = TALISMAN_ITEM_TYPE;
				rItem.unique = true;
				DeleteAttribute(rItem, "Type");
				DeleteAttribute(rItem, "time");
			}
//			TakenItems(pchar, "kaleuche_amulet" + i, 1);
		}
		else
		{
			bIsEquip = true;
		}
	}
	if (bIsEquip)
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "Перед процедурой смены типа, все данные предметы ('Индейский амулет') необходимо снять с персонажа!"
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		ChangeItemDescribe("kaleuche_amulet2", "itmdescr_kaleuche_amulet2_sword");
		ChangeItemDescribe("kaleuche_amulet3", "itmdescr_kaleuche_amulet3_shield");
		totalInfo += "Побрякушки по 'Калеуче' теперь " + sArtType + NewStr() + "\n\nВажно!" + NewStr() + "Если эти амулеты уже экипированы к моменту официального получения по квесту, не забудьте снять их!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F18", 1);
}

string descF19 = "Получить все обычные карты";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	int iMap;
	string sMap;
	for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
	{
		if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
		{
			sMap = Items[iMap].id;
			if (!CheckCharacterItem(pchar, sMap)) TakenItems(pchar, sMap, 1);
		}
	}
	if (!CheckCharacterItem(pchar, "map_LSC")) TakenItems(pchar, "map_LSC", 1);
	if (!CheckCharacterItem(pchar, "map_bad")) TakenItems(pchar, "map_bad", 1);
	if (!CheckCharacterItem(pchar, "map_normal")) TakenItems(pchar, "map_normal", 1);
	if (!CheckCharacterItem(pchar, "Map_Best")) TakenItems(pchar, "Map_Best", 1);
	RefreshEquippedMaps(pchar);
	ClearAllLogStrings();
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	if (sti(pchar.MapsAtlasCount) > MAPS_IN_ATLAS) pchar.MapsAtlasCount = 23;
	Log_info("Получены все отсутствующие обычные карты архипелага!");
	totalInfo += "Получены все отсутствующие обычные карты архипелага!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F19", 1);
}

string descF20 = "Получить все отличные карты";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	int iMap;
	string sMap;
	for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
	{
		if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
		{
			sMap = Items[iMap].id;
			if (HasSubStr(sMap, "A_map_"))
			{
				if (!CheckCharacterItem(pchar, sMap)) TakenItems(pchar, sMap, 1);
			}
		}
	}
	RefreshEquippedMaps(pchar);
	ClearAllLogStrings();
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	if (sti(pchar.MapsAtlasCount) > MAPS_IN_ATLAS) pchar.MapsAtlasCount = 23;
	Log_info("Получены все отсутствующие отличные карты архипелага!");
	totalInfo += "Получены все отсутствующие отличные карты архипелага!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F20", 1);
}

string descF21 = "Изменить тип хранимых карт в атласе (6 вариаций)";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	int iMap;
	string sMap, sLog, sLogN;
	string sLogE = "В атласе будут храниться ";
	if (!CheckAttribute(pchar, "CSM.AtlasType")) pchar.CSM.AtlasType = 0;
	if (sti(pchar.CSM.AtlasType) < 0 || sti(pchar.CSM.AtlasType) > 5) pchar.CSM.AtlasType = 0;
	RemoveCharacterEquip(pchar, MAPS_ITEM_TYPE);
	if (CheckCharacterItem(pchar, "MapsAtlas")) TakenItems(pchar, "MapsAtlas", -1);
	switch (sti(pchar.CSM.AtlasType))
	{
		case 0:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "";
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "";
					}
					if (HasSubStr(sMap, "A_map_"))
					{
						Items[iMap].MapType = "Special";
					}
				}
			}
			sLog = "обычные карты островов, карты архипелага и ГПК! (2\6)"; sLogN = "только отличные карты островов";
		break;
		case 1:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "Special";
					}
					if (HasSubStr(sMap, "A_map_"))
					{
						Items[iMap].MapType = "";
					}
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "Special";
				}
			}
			sLog = "только отличные карты островов! (3\6)"; sLogN = "отличные карты островов, карты архипелага и ГПК";
		break;
		case 2:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "A_map_") || HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "";
					}
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "Special";
				}
			}
			sLog = "отличные карты островов, карты архипелага и ГПК! (4\6)"; sLogN = "только обычные и отличные карты островов";
		break;
		case 3:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "Special";
					}
					if (HasSubStr(sMap, "A_map_"))
					{
						Items[iMap].MapType = "";
					}
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "";
				}
			}
			sLog = "только обычные и отличные карты островов! (5\6)"; sLogN = "абсолютно все карты архипелага";
		break;
		case 4:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "A_map_") || HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "";
					}
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "";
				}
			}
			sLog = "абсолютно все карты архипелага! (6\6)"; sLogN = "только обычные карты островов (по умолчанию)";
		break;
		case 5:
			for (iMap = 0; iMap < ITEMS_QUANTITY; iMap++)
			{
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 0)
				{
					sMap = Items[iMap].id;
					if (HasSubStr(sMap, "A_map_") || HasSubStr(sMap, "map_bad") || HasSubStr(sMap, "map_normal") || HasSubStr(sMap, "Map_Best") || HasSubStr(sMap, "map_LSC"))
					{
						Items[iMap].MapType = "Special";
					}
				}
				if (CheckAttribute(&Items[iMap], "Atlas") && Items[iMap].Atlas == 1)
				{
					Items[iMap].MapType = "";
				}
			}
			sLog = "только обычные карты островов (по умолчанию)! (1\6)"; sLogN = "обычные карты островов, карты архипелага и ГПК";
		break;
	}
	pchar.CSM.AtlasType = sti(pchar.CSM.AtlasType) + 1;
	RefreshEquippedMaps(pchar);
	ClearAllLogStrings();
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	if (sti(pchar.MapsAtlasCount) > MAPS_IN_ATLAS) pchar.MapsAtlasCount = 23;
	Log_info(sLogE + sLog);
	totalInfo += sLogE + sLog + "\n\nСледующий выбор: " + sLogN + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F21", 1);
}

string descF22 = "Изучить все рецепты для алхимии и обновить записи в журнале по ним";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	ref rItem;
	int iRecipe;
	string sGood;
	pchar.alchemy.known = 1;
	if (!CheckCharacterPerk(pchar, "Alchemy")) SetCharacterPerk(pchar, "Alchemy");
	if (CheckAttribute(pchar, "QuestInfo.Recipe")) { DeleteAttribute(pchar, "QuestInfo.Recipe"); }
	for (iRecipe = 0; iRecipe < ITEMS_QUANTITY; iRecipe++)
	{
		rItem = &Items[iRecipe];
		if (CheckAttribute(rItem, "multiobject"))
		{
			sGood = rItem.id;
			AddQuestRecordInfo("Recipe", sGood);
			if (!isMultiObjectKnown(sGood)) { pchar.alchemy.(sGood).isKnown = true; }
		}
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info("Все рецепты изучены!");
	totalInfo += "Все рецепты изучены!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F22", 1);
}

string descF23 = "Получить все инструменты для алхимии";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	if (!CheckCharacterItem(pchar, "alchemy_tool") || !CheckCharacterItem(pchar, "mechanic_tool") || !CheckCharacterItem(pchar, "tailor_tool") || !CheckCharacterItem(pchar, "tigel") || !CheckCharacterItem(pchar, "mineral1") || !CheckCharacterItem(pchar, "mineral5") || !CheckCharacterItem(pchar, "mineral6") || !CheckCharacterItem(pchar, "mineral10") || !CheckCharacterItem(pchar, "mineral11") || !CheckCharacterItem(pchar, "mineral16") || !CheckCharacterItem(pchar, "mineral19") || !CheckCharacterItem(pchar, "mineral20") || !CheckCharacterItem(pchar, "mineral21") || !CheckCharacterItem(pchar, "mineral27") || !CheckCharacterItem(pchar, "mineral32"))
	{
		if (!CheckCharacterItem(pchar, "alchemy_tool"))
		{
			TakenItems(pchar, "alchemy_tool", 1); totalInfo += "Получен сундук алхимика!";
		}
		if (!CheckCharacterItem(pchar, "mechanic_tool"))
		{
			TakenItems(pchar, "mechanic_tool", 1); totalInfo += NewStr() + "Получен слесарный инструмент!";
		}
		if (!CheckCharacterItem(pchar, "tailor_tool"))
		{
			TakenItems(pchar, "tailor_tool", 1); totalInfo += NewStr() + "Получен портняжный инструмент!";
		}
		if (!CheckCharacterItem(pchar, "tigel"))
		{
			TakenItems(pchar, "tigel", 1); totalInfo += NewStr() + "Получен тигель!";
		}
		if (!CheckCharacterItem(pchar, "mineral1"))
		{
			TakenItems(pchar, "mineral1", 1); totalInfo += NewStr() + "Получен медный кувшин!";
		}
		if (!CheckCharacterItem(pchar, "mineral5"))
		{
			TakenItems(pchar, "mineral5", 1); totalInfo += NewStr() + "Получена лампада!";
		}
		if (!CheckCharacterItem(pchar, "mineral6"))
		{
			TakenItems(pchar, "mineral6", 1); totalInfo += NewStr() + "Получено зеркальце!";
		}
		if (!CheckCharacterItem(pchar, "mineral10"))
		{
			TakenItems(pchar, "mineral10", 1); totalInfo += NewStr() + "Получено огниво!";
		}
		if (!CheckCharacterItem(pchar, "mineral11"))
		{
			TakenItems(pchar, "mineral11", 1); totalInfo += NewStr() + "Получена серебряный кувшин!";
		}
		if (!CheckCharacterItem(pchar, "mineral16"))
		{
			TakenItems(pchar, "mineral16", 1); totalInfo += NewStr() + "Получен оселок!";
		}
		if (!CheckCharacterItem(pchar, "mineral19"))
		{
			TakenItems(pchar, "mineral19", 1); totalInfo += NewStr() + "Получена серебряная ложка!";
		}
		if (!CheckCharacterItem(pchar, "mineral20"))
		{
			TakenItems(pchar, "mineral20", 1); totalInfo += NewStr() + "Получена деревянная ложка!";
		}
		if (!CheckCharacterItem(pchar, "mineral21"))
		{
			TakenItems(pchar, "mineral21", 1); totalInfo += NewStr() + "Получены письменные принадлежности!";
		}
		if (!CheckCharacterItem(pchar, "mineral27"))
		{
			TakenItems(pchar, "mineral27", 1); totalInfo += NewStr() + "Получена ступка с пестиком!";
		}
		if (!CheckCharacterItem(pchar, "mineral32"))
		{
			TakenItems(pchar, "mineral32", 1); totalInfo += NewStr() + "Получена пулелейка!";
		}
		Log_info("Получены все необходимые для алхимии предметы!");
		iSND = PlaySound("Interface\important_item.wav");
		totalInfo += NewStr() + "Получены недостающие инструменты!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Все предметы для занятия алхимией уже имеются!");
		totalInfo += "Все предметы для занятия алхимией уже имеются!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F23", 1);
}

// --> На данный момент, все прочие лицензии в ККС - мусор. Спасибо sads1k ^^
string descF24 = "Получить торговую лицензию Голландской Вест-Индской компании на год";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	string sLog = "Торговая лицензия Голландской Вест-Индской компании с годовым сроком действия получена!";
	GiveNationLicence(HOLLAND, 365);
	PlaySound("Interface\important_item.wav");
	iSND = PlaySound("_CheatSurfMenu_\TradeLicense.wav");
	Log_info(sLog);
	totalInfo += sLog + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F24", 1);
}

string descF25 = "Получить \ удалить патент";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	int iPat = 0;
	bool bNoPatent = false;
	if (isMainCharacterPatented())
	{
		switch (sti(Items[sti(pchar.EquipedPatentId)].Nation))
		{
			case 0: iPat = 1; break;
			case 1: iPat = 2; break;
			case 2: iPat = 3; break;
			case 3: iPat = 4; break;
			case 4: iPat = 0; break;
		}
	}
	switch (iPat)
	{
		case 0: RemovePatents(); GiveItem2Character(pchar, "patent_eng"); EquipCharacterbyItem(pchar, "patent_eng"); iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 1: RemovePatents(); GiveItem2Character(pchar, "patent_fra"); EquipCharacterbyItem(pchar, "patent_fra"); iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav");break;
		case 2: RemovePatents(); GiveItem2Character(pchar, "patent_spa"); EquipCharacterbyItem(pchar, "patent_spa"); iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 3: RemovePatents(); GiveItem2Character(pchar, "patent_hol"); EquipCharacterbyItem(pchar, "patent_hol"); iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 4: bNoPatent = true; break;
	}
	if (bNoPatent)
	{
		RemovePatents();
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		log_info("Патент аннулирован.");
		totalInfo += "Патент аннулирован.";
	}
	else
	{
		SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Flags\flag_" + NationShortName(sti(Items[sti(pchar.EquipedPatentId)].Nation)) + ".tga");
		Items[sti(pchar.EquipedPatentId)].TitulCur = 1;
		Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
		log_info("Получен патент " + NationNameGenitive(sti(Items[sti(pchar.EquipedPatentId)].Nation)) + "!");
		totalInfo += "Получен патент " + NationNameGenitive(sti(Items[sti(pchar.EquipedPatentId)].Nation)) + "!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F25", 1);
}

string descF26 = "Изменить текущее звание";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	bool bNoTitle = false;
	string sCurTitle = "Звание отсутствует.";
	if (isMainCharacterPatented())
	{
		SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Flags\flag_" + NationShortName(sti(Items[sti(pchar.EquipedPatentId)].Nation)) + ".tga");
		Items[sti(pchar.EquipedPatentId)].TitulCurNext = 0;
		if (sti(Items[sti(pchar.EquipedPatentId)].TitulCur) >= 5) { bNoTitle = true; }
		if (bNoTitle)
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Items[sti(pchar.EquipedPatentId)].TitulCur = 0;
			Log_info(sCurTitle);
			totalInfo += sCurTitle;
		}
		else
		{
			Items[sti(pchar.EquipedPatentId)].TitulCur = sti(Items[sti(pchar.EquipedPatentId)].TitulCur) + 1;
			iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
			sCurTitle = GetAddress_FormTitle(sti(Items[sti(pchar.EquipedPatentId)].Nation), sti(Items[sti(pchar.EquipedPatentId)].TitulCur));
			Log_info("Вам присвоено звание " + sCurTitle + "а!");
			totalInfo += "Вам присвоено звание " + sCurTitle + "а!";
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
		Log_info("У героя отсутствует патент!");
		totalInfo += "У героя отсутствует патент!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F26", 1);
}

string descF27 = "Получить случайную карту сокровищ";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	if (GetCharacterItem(pchar, "map_full") == 0)
	{
		GiveItem2Character(pchar, "map_full");
		iSND = PlaySound("Interface\important_item.wav");
		Log_info("Карта сокровищ получена!");
		totalInfo += "Карта сокровищ получена!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Карта сокровищ уже имеется на руках!");
		totalInfo += "Карта сокровищ уже имеется на руках!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F27", 1);
}

string descF28 = "Получить сундук с золотыми дублонами";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	TakenItems(pchar, "Chest", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Сундук с золотыми дублонами получен!");
	totalInfo += "Сундук с золотыми дублонами получен!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F28", 1);
}

string descF29 = "Получить сокровища";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	TakenItems(pchar, "icollection", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Сокровища получены!");
	totalInfo += "Сокровища получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F29", 1);
}

string descF30 = "Получить все драгоценные камни";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	for (int i=1; i<=23; i++)
	{
		TakenItems(pchar, "jewelry"+i, 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все драгоценные камни получены!");
	totalInfo += "Все драгоценные камни получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F30", 1);
}

string descF31 = "Получить все дешевые украшения";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	for (int i=40; i<=53; i++)
	{
		TakenItems(pchar, "jewelry"+i, 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все дешевые украшения получены!");
	totalInfo += "Все дешевые украшения получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F31", 1);
}

string descF32 = "Получить весь хлам";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	for (int i=1; i<=35; i++)
	{
		TakenItems(pchar, "mineral"+i, 1);
	}
	TakenItems(pchar, "crab_pincers", 1);
	TakenItems(pchar, "crab_jaw", 1);
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Весь хлам получен!");
	totalInfo += "Весь хлам получен!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F32", 1);
}

string descF33 = "Получить все травы";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	for (int i=1; i<=7; i++)
	{
		TakenItems(pchar, "cannabis"+i, 1);
	}
	iSND = PlaySound("Interface\important_item.wav");
	Log_info("Все травы получены!");
	totalInfo += "Все травы получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F33", 1);
}

string descF34 = "Увеличить вес клинка в руках";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	string sBW = "Вес холодного оружия в руках ";
	string sBWc = "Текущий вес хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Weight) < 10.0) // Хватит и 10ф
		{
			rIFID.Weight = stf(rIFID.Weight) + 0.1;
			if (stf(rIFID.Weight) > 10.0) { rIFID.Weight = 10.0; }
			Log_info(sBW + "увеличен!");
			totalInfo += sBW + "увеличен!" + NewStr() + sBWc + stf(rIFID.Weight);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "максимален!");
			totalInfo += sBW + "максимален!" + NewStr() + sBWc + stf(rIFID.Weight);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F34", 1);
}

string descF35 = "Уменьшить вес клинка в руках";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	string sBW = "Вес холодного оружия в руках ";
	string sBWc = "Текущий вес хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Weight) > 0.1)
		{
			rIFID.Weight = stf(rIFID.Weight) - 0.1;
			if (stf(rIFID.Weight) < 0.1) { rIFID.Weight = 0.1; }
			Log_info(sBW + "уменьшен!");
			totalInfo += sBW + "уменьшен!" + NewStr() + sBWc + stf(rIFID.Weight);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "минимален!");
			totalInfo += sBW + "минимален!" + NewStr() + sBWc + stf(rIFID.Weight);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F35", 1);
}

string descF36 = "Увеличить длину клинка в руках";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	string sBW = "Длина холодного оружия в руках ";
	string sBWc = "Текущая длина хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.lenght) < 2.0)
		{
			rIFID.lenght = stf(rIFID.lenght) + 0.1;
			if (stf(rIFID.lenght) > 2.0) { rIFID.lenght = 2.0; }
			Log_info(sBW + "увеличена!");
			totalInfo += sBW + "увеличена!" + NewStr() + sBWc + stf(rIFID.lenght);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "максимальна!");
			totalInfo += sBW + "максимальна!" + NewStr() + sBWc + stf(rIFID.lenght);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F36", 1);
}

string descF37 = "Уменьшить длину клинка в руках";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	string sBW = "Длина холодного оружия в руках ";
	string sBWc = "Текущая длина хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.lenght) > 0.1)
		{
			rIFID.lenght = stf(rIFID.lenght) - 0.1;
			if (stf(rIFID.lenght) < 0.1) { rIFID.lenght = 0.1; }
			Log_info(sBW + "уменьшена!");
			totalInfo += sBW + "уменьшена!" + NewStr() + sBWc + stf(rIFID.lenght);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "минимальна!");
			totalInfo += sBW + "минимальна!" + NewStr() + sBWc + stf(rIFID.lenght);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F37", 1);
}

string descF38 = "Увеличить изгиб клинка в руках";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	string sBW = "Изгиб холодного оружия в руках ";
	string sBWc = "Текущий изгиб хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.curve) < 2.0)
		{
			rIFID.curve = stf(rIFID.curve) + 0.1;
			if (stf(rIFID.curve) > 2.0) { rIFID.curve = 2.0; }
			Log_info(sBW + "увеличен!");
			totalInfo += sBW + "увеличен!" + NewStr() + sBWc + stf(rIFID.curve);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "максимален!");
			totalInfo += sBW + "максимален!" + NewStr() + sBWc + stf(rIFID.curve);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F38", 1);
}

string descF39 = "Уменьшить изгиб клинка в руках";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	string sBW = "Изгиб холодного оружия в руках ";
	string sBWc = "Текущий изгиб хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.curve) > 0.1)
		{
			rIFID.curve = stf(rIFID.curve) - 0.1;
			if (stf(rIFID.curve) < 0.1) { rIFID.curve = 0.1; }
			Log_info(sBW + "уменьшен!");
			totalInfo += sBW + "уменьшен!" + NewStr() + sBWc + stf(rIFID.curve);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "минимален!");
			totalInfo += sBW + "минимален!" + NewStr() + sBWc + stf(rIFID.curve);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F39", 1);
}

string descF40 = "Увеличить баланс клинка в руках";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	string sBW = "Баланс холодного оружия в руках ";
	string sBWc = "Текущий баланс хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Balance) < 2.0)
		{
			rIFID.Balance = stf(rIFID.Balance) + 0.1;
			if (stf(rIFID.Balance) > 2.0) { rIFID.Balance = 2.0; }
			Log_info(sBW + "увеличен!");
			totalInfo += sBW + "увеличен!" + NewStr() + sBWc + stf(rIFID.Balance);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "максимален!");
			totalInfo += sBW + "максимален!" + NewStr() + sBWc + stf(rIFID.Balance);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F40", 1);
}

string descF41 = "Уменьшить баланс клинка в руках";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	string sBW = "Баланс холодного оружия в руках ";
	string sBWc = "Текущий баланс хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Balance) > 0.1)
		{
			rIFID.Balance = stf(rIFID.Balance) - 0.1;
			if (stf(rIFID.Balance) < 0.1) { rIFID.Balance = 0.1; }
			Log_info(sBW + "уменьшен!");
			totalInfo += sBW + "уменьшен!" + NewStr() + sBWc + stf(rIFID.Balance);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "минимален!");
			totalInfo += sBW + "минимален!" + NewStr() + sBWc + stf(rIFID.Balance);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F41", 1);
}

// by Sticksъ -->
string descF42 = "Увеличить урон клинка в руках";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	string sBW = "Урон холодного оружия в руках ";
	string sBWc = "Текущий урон хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Attack) < 150.0)
		{
			rIFID.Attack = stf(rIFID.Attack) + 1.0;
			if (stf(rIFID.Attack) > 150.0) { rIFID.Attack = 150.0; }
			Log_info(sBW + "увеличен!");
			totalInfo += sBW + "увеличен!" + NewStr() + sBWc + stf(rIFID.Attack);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "максимален!");
			totalInfo += sBW + "максимален!" + NewStr() + sBWc + stf(rIFID.Attack);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F42", 1);
}

string descF43 = "Уменьшить урон клинка в руках";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	string sBW = "Урон холодного оружия в руках ";
	string sBWc = "Текущий урон хо в руках: ";
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);
	ref rIFID = ItemsFromID(sEBG);
	if (sEBG != "")
	{
		if (stf(rIFID.Attack) > 25.0)
		{
			rIFID.Attack = stf(rIFID.Attack) - 1.0;
			if (stf(rIFID.Attack) < 25.0) { rIFID.Attack = 25.0; }
			Log_info(sBW + "уменьшен!");
			totalInfo += sBW + "уменьшен!" + NewStr() + sBWc + stf(rIFID.Attack);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		}
		else
		{
			Log_info(sBW + "минимален!");
			totalInfo += sBW + "минимален!" + NewStr() + sBWc + stf(rIFID.Attack);
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		}
	}
	else
	{
		Log_info(sUnarmed);
		totalInfo += sUnarmed;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	//ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F43", 1);
}
// by Sticksъ <--

string descF44 = "Сменить внешний вид даги 'Коготь вождя' (3 варианта)";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();

	ref rItem = ItemsFromID("knife_01");
	string sEBG = GetCharacterEquipByGroup(pchar, BLADE_ITEM_TYPE);

	if (!CheckAttribute(rItem, "model")) rItem.model = "knife_01";

	switch (rItem.model)
	{
		case "knife_01": rItem.model = "w2_blade"; totalInfo += "2/3\nВнешний вид даги 'Коготь вождя' изменен на ведьмачий меч!\n" + sModer + "Mett"; break;
		case "w2_blade": rItem.model = "daga_aragorn"; totalInfo += "3/3\nВнешний вид даги 'Коготь вождя' изменен на альтернативный!\n" + sModer + "Lejito"; break;
		case "daga_aragorn": rItem.model = "knife_01"; totalInfo += "1/3\nДаге 'Коготь вождя' возвращен оригинальный облик."; break;
	}
	if (sEBG == rItem.id) SetNewModelToChar(pchar);
	if (!CheckCharacterItem(pchar, "knife_01")) TakenItems(pchar, "knife_01", 1);

	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F44", 1);
}

string descF45 = "Получить по 100 единиц патронов, пороха и картечи";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();

	TakenItems(pchar, "cartridge", 100);
	TakenItems(pchar, "GunPowder", 100);
	TakenItems(pchar, "grapeshot", 100);
	
	iSND = PlaySound("Interface\important_item.wav");
	totalInfo += "Бумажные патроны, порох и картечь получены!" + sDrop + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F45", 1);
}

string descF46 = "! ПУСТО !";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F46", 1);
}

string descF47 = "! ПУСТО !";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F47", 1);
}

string descF48 = "! ПУСТО !";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F48", 1);
}

string descF49 = "! ПУСТО !";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F49", 1);
}

string descF50 = "! ПУСТО !";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F50", 1);
}

string descF51 = "! ПУСТО !";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F51", 1);
}

string descF52 = "! ПУСТО !";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F52", 1);
}

string descF53 = "! ПУСТО !";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ПУСТО !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM3.F53", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F54", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F55", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F56", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F57", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F58", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F59", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F60", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F61", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F62", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F63", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F64", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F65", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F66", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F67", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F68", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F69", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM3.F70", 1);
}

// Перед выдачей или изъятием конкретного патента, проверяются и трутся все прочие, на всякий случай -->
void RemovePatents()
{
	int iDel = 0;
	int iNat = 0;
	RemoveCharacterEquip(pchar, "patent");
	for (iNat = 0; iNat <= 3; iNat++)
	{
		if (CheckCharacterItem(pchar, "patent_" + NationShortName(iNat)))
		{
			iDel = GetCharacterItem(pchar, "patent_" + NationShortName(iNat));
			if (iDel > 0) TakeNItems(pchar, "patent_" + NationShortName(iNat), -iDel);
		}
	}
}
// <--

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
			sHeader = "Описание меню 'Предметы'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Предметы' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Предметы'";
			sText1 = "Перезапуск меню 'Предметы'";
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
