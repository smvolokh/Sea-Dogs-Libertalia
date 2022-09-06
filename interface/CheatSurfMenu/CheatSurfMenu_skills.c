
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Умения
	Основано на меню дебаггера от boal
	18.04.2018
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке ''Умения'' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sSkillInc = "На 1 увеличено умение ";
string sSkillDec = "На 1 уменьшено умение ";
string sMaxValue = "Умение достигло максимального значения!";
string sMinValue = "Умение достигло минимального значения!";
string sCurValue = "Текущее значение: ";
string sGlobal = "Это глобальный параметр, а значит применяется и ко всем NPC в команде ГГ.";
string sDefault = "\n\nРекомендуемый модификатор для текущей сложности игры в мод-паке ''Либерталия'': ";
string sDefault1 = "\n\nПримерный модификатор для текущей сложности игры в оригинальных Корсарах Каждому Своё: ";
string sDefault2 = "\n\nПо сравнению с оригиналом модификатор набора опыта увеличен примерно в 2-2,5 раза из-за большего количества контента (новые квесты сюжетные и генераторные, новые возможности для прокачки в лице тренировок, банкетов, взяток, крабов, вольных капитанов и т.д.). Это необоходимо для того, чтобы прокачка была более плавной и равномерной в ходе игры в рамках выполнения всех квестов, но благодаря этой функции Вы всегда можете настроить сей модификатор под свои нужды и видение. :) ";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_skills";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(1); // Warship. Статистика - сколько читов юзали
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
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() + "< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() + "\n\n********** ЛИЧНЫЕ УМЕНИЯ **********" + NewStr() + "< 34 > " + descF34 + NewStr() +
					"< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() + "< 37 > " + descF37 + NewStr() +
					"< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() + "< 40 > " + descF40 + NewStr() +
					"< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() + "< 43 > " + descF43 + NewStr() + "< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "\n\n********** КОРАБЕЛЬНЫЕ УМЕНИЯ **********" + NewStr() + "< 48 > " + descF48 + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() +
					"< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() + "< 54 > " + descF54 + NewStr() +
					"< 55 > " + descF55 + NewStr() + "< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() + "< 58 > " + descF58 + NewStr() + "< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() + "< 61 > " + descF61 + NewStr() + "\n\n********** ПРОЧЕЕ **********" + NewStr() + "< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() +
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(1); // Статистика по читам
}

string descF1 = "Увеличить урон героя в ближнем бою \ по умолчанию";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	string sDmgC = "Наносимый героем урон холодным и огнестрельным оружием увеличен в ";
	string sDmgN = "Следующий шаг: увеличение урона в ";
	if (!CheckAttribute(pchar, "MultiFighter")) pchar.MultiFighter = 1.0;
	if (!CheckAttribute(pchar, "MultiShooter")) pchar.MultiShooter = 1.0;
	switch (stf(pchar.MultiFighter))
	{
		case 1.0:
			pchar.MultiFighter = 2.0;
			pchar.MultiShooter = 2.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "2 раза!");
			totalInfo += sDmgC + "2 раза!" + NewStr() + sDmgN + "3 раза.";
		break;
		case 2.0:
			pchar.MultiFighter = 3.0;
			pchar.MultiShooter = 3.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "3 раза!");
			totalInfo += sDmgC + "3 раза!" + NewStr() + sDmgN + "4 раза.";
		break;
		case 3.0:
			pchar.MultiFighter = 4.0;
			pchar.MultiShooter = 4.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "4 раза!");
			totalInfo += sDmgC + "4 раза!" + NewStr() + sDmgN + "5 раз.";
		break;
		case 4.0:
			pchar.MultiFighter = 5.0;
			pchar.MultiShooter = 5.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "5 раз!");
			totalInfo += sDmgC + "5 раз!" + NewStr() + sDmgN + "10 раз.";
		break;
		case 5.0:
			pchar.MultiFighter = 10.0;
			pchar.MultiShooter = 10.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "10 раз!");
			totalInfo += sDmgC + "10 раз!" + NewStr() + sDmgN + "100 раз.";
		break;
		case 10.0:
			pchar.MultiFighter = 100.0;
			pchar.MultiShooter = 100.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "100 раз!");
			totalInfo += sDmgC + "100 раз!" + NewStr() + "Следующий шаг: урон по умолчанию.";
		break;
		case 100.0:
			pchar.MultiFighter = 1.0;
			pchar.MultiShooter = 1.0;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info("Наносимый героем урон выставлен по умолчанию.");
			totalInfo += "Наносимый героем урон выставлен по умолчанию." + NewStr() + sDmgN + "2 раза.";
		break;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F1", 1);
}

string descF2 = "Удары ГГ и его бойцов всегда пробивают блок противника \ по умолчанию";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	ref sld;
	int ic, io, icn, ion;
	if (!CheckAttribute(pchar, "animal"))
	{
		pchar.animal = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Удары ГГ и его бойцов не блокируются противником!";
	}
	else
	{
		DeleteAttribute(pchar, "animal");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Шанс на пробитие блока противника у ГГ и его бойцов выставлен по умолчанию.";
	}
	for (io=1; io<4; io++)
	{
		ion = GetOfficersIndex(pchar, io);
		if (ion != -1)
		{
			sld = GetCharacter(ion);
			if (!CheckAttribute(pchar, "animal")) DeleteAttribute(sld, "animal");
			else sld.animal = true;
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F2", 1);
}

string descF3 = "Изучить \ забыть все перки (кроме скрытых)";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.DeletePerks"))
	{
		DeleteAttribute(pchar, "CSM.DeletePerks");
		SelAllPerksToChar(pchar, false);
		iSND = PlaySound("_CheatSurfMenu_\Master.wav");
		Log_info("Все перки изучены!");
		totalInfo += "Все перки изучены!" + NewStr();
	}
	else
	{
		pchar.CSM.DeletePerks = true;
		DeleteAttribute(pchar, "perks.list");
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("Все перки позабыты...");
		totalInfo += "Все перки позабыты..." + NewStr();
	}
	if (CheckAttribute(pchar, "CSM.GotAllHidePerks"))
	{
		for (i = 1; i <= 5; i++)
		{
			if (!CheckCharacterPerk(pchar, "HT" + i)) { SetCharacterPerk(pchar, "HT" + i); }
		}
	}
	else
	{
		switch(pchar.HeroParam.HeroType)
		{
			case "Adventurer": if (!CheckCharacterPerk(pchar, "HT1")) SetCharacterPerk(pchar, "HT1"); break;
			case "Merchant": if (!CheckCharacterPerk(pchar, "HT2")) SetCharacterPerk(pchar, "HT2"); break;
			case "Corsair": if (!CheckCharacterPerk(pchar, "HT3")) SetCharacterPerk(pchar, "HT3"); break;
			case "Master": if (!CheckCharacterPerk(pchar, "HT4")) SetCharacterPerk(pchar, "HT4"); break;
			case "Inquisitor": if (!CheckCharacterPerk(pchar, "HT4")) SetCharacterPerk(pchar, "HT5"); break;
			case "SecretAgent": if (!CheckCharacterPerk(pchar, "HT4")) SetCharacterPerk(pchar, "Trustworthy"); break;
		}
	}
	if (!CheckCharacterPerk(pchar, "Energaiser")) SetCharacterPerk(pchar, "Energaiser");
	if (!CheckCharacterPerk(pchar, "FlagPir")) SetCharacterPerk(pchar, "FlagPir");
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F3", 1);
}

string descF4 = "Получить по 1 свободному перку в личные и корабельные способности";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	bool bSnd = false;
	if (sti(PChar.Perks.FreePoints_Self) < 19)
	{
		PChar.Perks.FreePoints_Self = sti(PChar.Perks.FreePoints_Self) + 1;
		bSnd = true;
		Log_info("Получен 1 свободный личный перк!");
		totalInfo += "Получен 1 свободный личный перк!" + NewStr() + "Личных перков: " + sti(PChar.Perks.FreePoints_Self);
	}
	else
	{
		Log_info("Достигнуто максимальное число свободных личных перков!");
		totalInfo += "Достигнуто максимальное число свободных личных перков!" + NewStr() + "Личных перков: " + sti(PChar.Perks.FreePoints_Self);
	}
	totalInfo += "\n\n";
	if (sti(PChar.Perks.FreePoints_Ship) < 38)
	{
		PChar.Perks.FreePoints_Ship = sti(PChar.Perks.FreePoints_Ship) + 1;
		bSnd = true;
		Log_info("Получен 1 свободный корабельный перк!");
		totalInfo += "Получен 1 свободный корабельный перк!" + NewStr() + "Корабельных перков: " + sti(PChar.Perks.FreePoints_Ship);
	}
	else
	{
		Log_info("Достигнуто максимальное число свободных корабельных перков!");
		totalInfo += "Достигнуто максимальное число свободных корабельных перков!" + NewStr() + "Корабельных перков: " + sti(PChar.Perks.FreePoints_Ship);
	}
	if (bSnd) iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	else iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F4", 1);
}

string descF5 = "Очистить все свободные очки перков";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	if (sti(PChar.Perks.FreePoints_Self) > 0 || sti(PChar.Perks.FreePoints_Ship) > 0)
	{
		PChar.Perks.FreePoints_Self = 0;
		PChar.Perks.FreePoints_Ship = 0;
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("Свободные очки личных и корабельных перков очищены...");
		totalInfo += "Свободные очки личных и корабельных перков очищены...";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("Нет свободных очков перков.");
		totalInfo += "Нет свободных очков перков.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F5", 1);
}

string descF6 = "Все личные умения по 10";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	SetRandSelfSkill(pchar, 10, 10);
	iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	Log_info("Все показатели личных умений выставлены по 10!");
	totalInfo += "Все показатели личных умений выставлены по 10!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F6", 1);
}

string descF7 = "Все личные умения по 100";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	SetRandSelfSkill(pchar, 100, 100);
	iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	Log_info("Все показатели личных умений выставлены по 100!");
	totalInfo += "Все показатели личных умений выставлены по 100!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F7", 1);
}

string descF8 = "Все корабельные умения по 10";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	SetRandShipSkill(pchar, 10, 10);
	iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	Log_info("Все показатели корабельных умений выставлены по 10!");
	totalInfo += "Все показатели корабельных умений выставлены по 10!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F8", 1);
}

string descF9 = "Все корабельные умения по 100";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	SetRandShipSkill(pchar, 100, 100);
	iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	Log_info("Все показатели корабельных умений выставлены по 100!");
	totalInfo += "Все показатели корабельных умений выставлены по 100!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F9", 1);
}

string descF10 = "Распределить умения ГГ вручную \ удалить свободные очки умений";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	if (sti(pchar.Skill.FreeSkill) < 1)
	{
		pchar.Skill.FreeSkill = 99;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Добавлено 99 свободных очков умений!" + NewStr() + "\n\nЗакройте это меню, нажмите F2, выберите вкладку 'Персонажи' и настройте умения ГГ вручную." + NewStr() + "Повторное использование этой команды удалит все свободные очки умений ГГ.";
	}
	else
	{
		pchar.Skill.FreeSkill = 0;
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		totalInfo += "Все свободные очки умений были очищены!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F10", 1);
}

string descF11 = "P.I.R.A.T.E.S. всё по 10 \ по умолчанию";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	string sHT = "Текущий тип героя: ";
	string sDef = "Значения P.I.R.A.T.E.S. установлены по умолчанию!";
	if (!CheckAttribute(pchar, "CSM.SPECIALmaxValue"))
	{
		pchar.CSM.SPECIALmaxValue = true;
		SetSPECIAL(pchar, 10, 10, 10, 10, 10, 10, 10);
		iSND = PlaySound("_CheatSurfMenu_\IamLegend.wav");
		Log_info("Все значения P.I.R.A.T.E.S. равны 10!");
		totalInfo += "Все значения P.I.R.A.T.E.S. равны 10!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SPECIALmaxValue");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sDef);
		if (pchar.HeroParam.HeroType == "HeroType_1")
		{
			SetSPECIAL(pchar, 5, 6, 6, 5, 7, 7, 6);
			Log_info(sHT + "гимнастика и искусство фехтования.");
			totalInfo += sHT + "гимнастика и искусство фехтования." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_2")
		{
			SetSPECIAL(pchar, 7, 4, 7, 6, 6, 7, 5);
			Log_info(sHT + "общее счетоводство и риторика.");
			totalInfo += sHT + "общее счетоводство и риторика." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_3")
		{
			SetSPECIAL(pchar, 10, 3, 8, 5, 4, 8, 4);
			Log_info(sHT + "атлетика и основы боя на мечах.");
			totalInfo += sHT + "атлетика и основы боя на мечах." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_4")
		{
			SetSPECIAL(pchar, 4, 9, 6, 4, 5, 5, 9);
			Log_info(sHT + "оружейное и стрелковое дело.");
			totalInfo += sHT + "оружейное и стрелковое дело." + NewStr() + sDef;
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F11", 1);
}

string descF12 = "Изменения P.I.R.A.T.E.S. вручную будут \ не будут влиять на текущие показатели умений";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.SPECIALsimpleValue"))
	{
		pchar.CSM.SPECIALsimpleValue = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Изменение значений P.I.R.A.T.E.S. вручную не будут влиять на текущие показатели умений!");
		totalInfo += "Изменение значений P.I.R.A.T.E.S. вручную не будут влиять на текущие показатели умений!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SPECIALsimpleValue");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Изменение значений P.I.R.A.T.E.S. вручную будут менять текущие показатели умений.");
		totalInfo += "Изменение значений P.I.R.A.T.E.S. вручную будут менять текущие показатели умений.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F12", 1);
}

string descF13 = "Включить \ выключить назначение штрафов в умения и P.I.R.A.T.E.S. от кирасы или костюма";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.CuirassNoPenalty"))
	{
		pchar.CSM.CuirassNoPenalty = true;
		totalInfo += "Пенальти в P.I.R.A.T.E.S. и умениях не будут учитываться от надетой кирасы или костюма!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CuirassNoPenalty");
		totalInfo += "Пенальти от надетой кирасы или костюма будут учитываться в P.I.R.A.T.E.S. и умениях.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F13", 1);
}

string descF14 = "Увеличить запас энергии ГГ до 999 \ по умолчанию";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.EnergyBonus"))
	{
		pchar.CSM.EnergyBonus = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Максимальный запас энергии равен 999 единицам!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.EnergyBonus");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Запас энергии выставлен по умолчанию.";
	}	
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F14", 1);
}

string descF15 = "Включить \ отключить расход энергии в бою для ГГ и абордажников";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoEnergyDrain"))
	{
		pchar.CSM.NoEnergyDrain = true;
		totalInfo += "Энергия ГГ и абордажников не будет расходоваться в бою!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoEnergyDrain");
		totalInfo += "Энергия ГГ и абордажников будет расходоваться в бою.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F15", 1);
}

string descF16 = "Включить \ отключить бег в водолазном костюме (разрешить обычный бег, если он запрещен)";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	bool bSnd = true;
	if (pchar.model == "protocusto")
	{
		if (!CheckAttribute(pchar, "CSM.FreeRun"))
		{
			pchar.CSM.FreeRun = true;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Бег в водолазном костюме разрешен!\n";
		}
		else
		{
			DeleteAttribute(pchar, "CSM.FreeRun");
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Бег в водолазном костюме запрещен.\n";
		}
		bSnd = false;
	}
	if (CheckAttribute(pchar, "GenQuest.CantRun"))
	{
		DeleteAttribute(pchar, "GenQuest.CantRun");
		if (bSnd) iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Обычный бег разрешен!";
	}
	else
	{
		if (bSnd) iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "Обычный бег не запрещен.";
	}
	CheckAndSetOverloadMode(GetMainCharacter());
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F16", 1);
}

string descF17 = "Включить \ отключить возможность абордажа или уничтожения любого корабля или форта";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.KillEmAll"))
	{
		DeleteAttribute(pchar, "CSM.KillEmAll");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Читовый абордаж отключен.";
	}
	else
	{
		pchar.CSM.KillEmAll = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Читовый абордаж включен!\n\nИспользование: в море нажать 'Enter', выбрать значок абордажного крюка и указать цель абордажа.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F17", 1);
}

string descF18 = "Включить \ отключить доплытие до места или врага с любой дистанции";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.FreeSailing") || !CheckAttribute(pchar, "CSM.SailToEffectRadius"))
	{
		pchar.CSM.FreeSailing = true;
		pchar.CSM.SailToEffectRadius = true;
		totalInfo += "Включена возможность доплыть до места или врага с любой дистанции!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FreeSailing");
		DeleteAttribute(pchar, "CSM.SailToEffectRadius");
		totalInfo += "Отключена возможность доплыть до места или врага с любой дистанции.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F18", 1);
}

string descF19 = "Включить \ отключить возможность 100% пропустить бой на глобальной карте";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.SkipShips"))
	{
		pchar.CSM.SkipShips = true;
		// Имеется баг: если сразу несколько кораблей лезут драться с нами, бой пропустить никак нельзя.
		totalInfo += "Включена 100% возможность пропустить бой с любыми кораблями на глобальной карте!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SkipShips");
		totalInfo += "Отключена 100% возможность пропустить бой с любыми кораблями на глобальной карте.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F19", 1);
}

string descF20 = "Включить \ отключить моментальную перезарядку орудий на корабле ГГ";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.MachineGunCannons"))
	{
		pchar.CSM.MachineGunCannons = true;
		totalInfo += "Включена моментальная перезарядка орудий на корабле ГГ!";
		iSND = PlaySound("_CheatSurfMenu_\SeaDogs.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MachineGunCannons");
		totalInfo += "Отключена моментальная перезарядка орудий на корабле ГГ.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F20", 1);
}

string descF21 = "Включить \ отключить бессмертие абордажной команды ГГ";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.BoardingCrewGodMode"))
	{
		DeleteAttribute(pchar, "CSM.BoardingCrewGodMode");
		Log_info("Бессмертие абордажной команды ГГ отключено.");
		totalInfo += "Бессмертие абордажной команды ГГ отключено.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	else
	{
		pchar.CSM.BoardingCrewGodMode = true;
		Log_info("Включено бессмертие абордажной команды ГГ!");
		totalInfo += "Включено бессмертие абордажной команды ГГ!" + NewStr() + "Работает везде, где в бою участвуют матросы ГГ: абордаж, бой в стенах форта, захват города с суши и т.д.";
		iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F21", 1);
}

string descF22 = "Изменить процесс абордажа (обычные кэпы: всегда сдаются, всегда сражаются, по умолчанию)";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.BoardingProcess")) { pchar.CSM.BoardingProcess = 0; }
	if (sti(pchar.CSM.BoardingProcess) < 0) { pchar.CSM.BoardingProcess = 0; }
	if (sti(pchar.CSM.BoardingProcess) > 2) { pchar.CSM.BoardingProcess = 2; }
	string sNext = "Следующий вариант: ";
	string sLog = "Капитаны вражеских кораблей всегда будут ";
	string sDef = "Шанс сдачи в плен вражеских капитанов выставлен по умолчанию.";
	TestRansackCaptain = false;
	switch (sti(pchar.CSM.BoardingProcess))
	{
		case 0:
			pchar.CSM.BoardingProcess = 1;
			TestRansackCaptain = true;
			iSND = PlaySound("_CheatSurfMenu_\IamLegend.wav");
			Log_info(sLog + "сдаваться в плен!");
			totalInfo += sLog + "сдаваться в плен!" + NewStr() + sNext + "всегда сражаются";
		break;
		case 1:
			pchar.CSM.BoardingProcess = 2;
			iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
			Log_info(sLog + "сражаться!");
			totalInfo += sLog + "сражаться!" + NewStr() + sNext + "по умолчанию";
		break;
		case 2:
			pchar.CSM.BoardingProcess = 0;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sDef);
			totalInfo += sDef + NewStr() + sNext + "всегда сдаются";
		break;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F22", 1);
}

string descF23 = "Матросы не едят и не пьют ром, на корабле нет крыс \ по умолчанию";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	if (bNoEatNoRats)
	{
		bNoEatNoRats = false;
		totalInfo += "Матросы вновь едят и пьют ром, а на корабле опять завелись крысы.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	else
	{
		bNoEatNoRats = true;
		totalInfo += "Матросы питаются воздухом и не требуют ром, все крысы изведены!";
		iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F23", 1);
}

string descF24 = "Корабли в эскадре ГГ получают \ не получают урон в шторме";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();

	ref sld;
	int ic, icn;

	if (CheckAttribute(pchar, "DontHitInStorm"))
	{
		DeleteAttribute(pchar, "DontHitInStorm");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "Корабли в эскадре ГГ будут получать повреждения в штормах.";
	}
	else
	{
		pchar.DontHitInStorm = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		totalInfo += "Корабли в эскадре ГГ не будут получать повреждений в штормах!";
	}
	// Компаньоны
	for (ic = 1; ic < COMPANION_MAX; ic++)
	{
		icn = GetCompanionIndex(pchar, ic);
		if (icn != -1)
		{
			sld = GetCharacter(icn);
			if (CheckAttribute(pchar, "DontHitInStorm")) sld.DontHitInStorm = true;
			else DeleteAttribute(sld, "DontHitInStorm");
		}
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F24", 1);
}

string descF25 = "Увеличить модификатор скорости набора опыта (порог опыта)";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	int exprate = 0;
	int exprate1 = 0;
	string sResult = "Модификатор скорости набора опыта увеличен!";
	string sValue = "Модификатор скорости набора опыта достиг максимального уровня!";
	if (MOD_SKILL_ENEMY_RATE >= 1) exprate = 30;
	if (MOD_SKILL_ENEMY_RATE >= 2) exprate = 50;
	if (MOD_SKILL_ENEMY_RATE >= 3) exprate = 70;
	if (MOD_SKILL_ENEMY_RATE >= 4) exprate = 90;
	if (MOD_SKILL_ENEMY_RATE >= 5) exprate = 110;
	if (MOD_SKILL_ENEMY_RATE >= 6) exprate = 130;
	if (MOD_SKILL_ENEMY_RATE >= 7) exprate = 150;
	if (MOD_SKILL_ENEMY_RATE >= 8) exprate = 170;
	if (MOD_SKILL_ENEMY_RATE >= 9) exprate = 190;
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate = 210;
	if (MOD_SKILL_ENEMY_RATE >= 1) exprate1 = 15;
	if (MOD_SKILL_ENEMY_RATE >= 2) exprate1 = 24;
	if (MOD_SKILL_ENEMY_RATE >= 3) exprate1 = 30;
	if (MOD_SKILL_ENEMY_RATE >= 4) exprate1 = 36;
	if (MOD_SKILL_ENEMY_RATE >= 5) exprate1 = 43;
	if (MOD_SKILL_ENEMY_RATE >= 6) exprate1 = 50;
	if (MOD_SKILL_ENEMY_RATE >= 7) exprate1 = 63;
	if (MOD_SKILL_ENEMY_RATE >= 8) exprate1 = 75;
	if (MOD_SKILL_ENEMY_RATE >= 9) exprate1 = 90;
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate1 = 105;
	if (MOD_EXP_RATE < 250)
	{
		MOD_EXP_RATE += 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sResult);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += "\n\n" + sResult + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + "Чем выше это значение, тем дольше качаются умения." + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate) + NewStr() + sDefault1 + sti(exprate1) + NewStr() + sDefault2;
	}
	else
	{
		if(MOD_EXP_RATE > 250) MOD_EXP_RATE = 250;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sValue);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += sValue + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate) + NewStr() + sDefault1 + sti(exprate1)+ NewStr() + sDefault2;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F25", 1);
}

string descF26 = "Уменьшить модификатор скорости набора опыта (порог опыта)";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	int exprate = 0;
	int exprate1 = 0;
	string sResult = "Модификатор скорости набора опыта уменьшен!";
	string sValue = "Модификатор скорости набора опыта достиг минимального уровня!";
	if (MOD_SKILL_ENEMY_RATE >= 1) exprate = 30;
	if (MOD_SKILL_ENEMY_RATE >= 2) exprate = 50;
	if (MOD_SKILL_ENEMY_RATE >= 3) exprate = 70;
	if (MOD_SKILL_ENEMY_RATE >= 4) exprate = 90;
	if (MOD_SKILL_ENEMY_RATE >= 5) exprate = 110;
	if (MOD_SKILL_ENEMY_RATE >= 6) exprate = 130;
	if (MOD_SKILL_ENEMY_RATE >= 7) exprate = 150;
	if (MOD_SKILL_ENEMY_RATE >= 8) exprate = 170;
	if (MOD_SKILL_ENEMY_RATE >= 9) exprate = 190;
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate = 210;
	if (MOD_SKILL_ENEMY_RATE >= 1) exprate1 = 15;
	if (MOD_SKILL_ENEMY_RATE >= 2) exprate1 = 24;
	if (MOD_SKILL_ENEMY_RATE >= 3) exprate1 = 30;
	if (MOD_SKILL_ENEMY_RATE >= 4) exprate1 = 36;
	if (MOD_SKILL_ENEMY_RATE >= 5) exprate1 = 43;
	if (MOD_SKILL_ENEMY_RATE >= 6) exprate1 = 50;
	if (MOD_SKILL_ENEMY_RATE >= 7) exprate1 = 63;
	if (MOD_SKILL_ENEMY_RATE >= 8) exprate1 = 75;
	if (MOD_SKILL_ENEMY_RATE >= 9) exprate1 = 90;
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate1 = 105;
	if (MOD_EXP_RATE > 10)
	{
		MOD_EXP_RATE -= 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sResult);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += "\n\n" + sResult + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + "Чем ниже это значение, тем быстрее качаются скиллы." + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate) + NewStr() + sDefault1 + sti(exprate1) + NewStr() + sDefault2;
	}
	else
	{
		if(MOD_EXP_RATE < 10) MOD_EXP_RATE = 10;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sValue);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += sValue + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate) + NewStr() + sDefault1 + sti(exprate1) + NewStr() + sDefault2;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F26", 1);
} 

string descF27 = "Для управления кораблем требуется \ не требуется навигация";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	if (CheckAttribute(pchar, "NoNavyPenalty"))
	{
		DeleteAttribute(pchar, "NoNavyPenalty");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Навигация будет учитываться при управлении кораблем.");
		totalInfo += "Навигация будет учитываться при управлении кораблем.";
	}
	else
	{
		pchar.NoNavyPenalty = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		Log_info("Навигация не учитывается при управлении кораблем!");
		totalInfo += "Навигация не учитывается при управлении кораблем!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F27", 1);
}

string descF28 = "Включить \ выключить уменьшение максимального HP корабля при повреждении корпуса";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.NoShipHullPenalty"))
	{
		DeleteAttribute(pchar, "CSM.NoShipHullPenalty");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Уменьшение максимального HP корабля при повреждении корпуса включено.");
		totalInfo += "Уменьшение максимального HP корабля при повреждении корпуса включено.";
	}
	else
	{
		pchar.CSM.NoShipHullPenalty = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		Log_info("Отключено уменьшение максимального HP корабля при повреждении корпуса!");
		totalInfo += "Отключено уменьшение максимального HP корабля при повреждении корпуса!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F28", 1);
}

string descF29 = "Включить \ выключить вероятность бунта на корабле ГГ";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoShipMutinies"))
	{
		pchar.CSM.NoShipMutinies = true;
		totalInfo += "Матросы и рабы не станут бунтовать!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoShipMutinies");
		totalInfo += "Матросы и рабы могут устроить бунт на корабле.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F29", 1);
}


string descF30 = "Включить \ выключить возможность заниматься контрабандой на любом корабле";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.FreeSmuggling"))
	{
		pchar.CSM.FreeSmuggling = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Включена свободная контрабанда!");
		Log_info("На сделку можно заявляться на любом корабле и хоть при полной эскадре!");
		totalInfo += "Включена свободная контрабанда!" + NewStr() + "На сделку можно заявляться на любом корабле и хоть при полной эскадре!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FreeSmuggling");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Контрабанда выставлена по умолчанию.");
		totalInfo += "Контрабанда выставлена по умолчанию.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F30", 1);
}

string descF31 = "Включить \ выключить возможность быстрого перехода во вражеских колониях";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.FastTravelEnemy"))
	{
		DeleteAttribute(pchar, "CSM.FastTravelEnemy");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Быстрый переход во вражеских поселениях запрещен...");
		totalInfo += "Быстрый переход во вражеских поселениях запрещен...";
	}
	else
	{
		pchar.CSM.FastTravelEnemy = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Разрешен быстрый переход во всех вражеских поселениях!");
		totalInfo += "Разрешен быстрый переход во всех вражеских поселениях!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F31", 1);
}

string descF32 = "Включить \ выключить ускорение и замедление времени всегда и везде";
void CalculateInfoDataF32() - в умения
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.TimeScaleEnable"))
	{
		pchar.CSM.TimeScaleEnable = true;
		totalInfo += "Ускорение и замедление времени работает всегда и везде!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.TimeScaleEnable");
		SetTimeScale(1.0);
		totalInfo += "Возможность ускорения и замедления времени выставлена по умолчанию.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F32", 1);
}

string descF33 = "Включить \ выключить возможность расталкивать толпу (3 варианта)";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();

	SM_PusherSwitch();

	if (CheckAttribute(pchar, "CSM.CrowdPusher"))
	{
		switch(sti(pchar.CSM.CrowdPusher))
		{
			case 1: totalInfo += "Толкач толпы: слабый"; break;
			case 2: totalInfo += "Толкач толпы: умеренный"; break;
			case 3: totalInfo += "Толкач толпы: усиленный"; break;
		}
		totalInfo += "\n\nОтпихивает прочь дружественные или нейтральные НПС, мешающие перемещению Вашего персонажа (прочь с дороги)\nБолее плавную работу обеспечивает слабый и умеренный режим.\nУсиленный эффективнее работает с большими толпами.";
		totalInfo += "\n\nВражеские, квестовые и некоторые особые персонажи (грузчики, бомжи, спящие и пр) не отпихиваются.";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		totalInfo += "Расталкиватель толпы отключен!";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F33", 1);
}

string descF34 = "Харизма +1";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	if (sti(pchar.skill.Leadership) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Leadership = sti(pchar.skill.Leadership) + 1;
		Log_info(sSkillInc + "Харизма!");
		totalInfo += sSkillInc + "Харизма!" + NewStr() + sCurValue + sti(pchar.skill.Leadership);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F34", 1);
}

string descF35 = "Харизма -1";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	if (sti(pchar.skill.Leadership) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Leadership = sti(pchar.skill.Leadership) - 1;
		Log_info(sSkillDec + "Харизма!");
		totalInfo += sSkillDec + "Харизма!" + NewStr() + sCurValue + sti(pchar.skill.Leadership);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F35", 1);
}

string descF36 = "Рапиры \ Шпаги +1";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	if (sti(pchar.skill.FencingL) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingL = sti(pchar.skill.FencingL) + 1;
		Log_info(sSkillInc + "Рапиры \ Шпаги!");
		totalInfo += sSkillInc + "Рапиры \ Шпаги!" + NewStr() + sCurValue + sti(pchar.skill.FencingL);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F36", 1);
}

string descF37 = "Рапиры \ Шпаги -1";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	if (sti(pchar.skill.FencingL) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingL = sti(pchar.skill.FencingL) - 1;
		Log_info(sSkillDec + "Рапиры \ Шпаги!");
		totalInfo += sSkillDec + "Рапиры \ Шпаги!" + NewStr() + sCurValue + sti(pchar.skill.FencingL);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F37", 1);
}

string descF38 = "Сабли \ Тесаки +1";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	if (sti(pchar.skill.FencingS) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingS = sti(pchar.skill.FencingS) + 1;
		Log_info(sSkillInc + "Сабли \ Тесаки!");
		totalInfo += sSkillInc + "Сабли \ Тесаки!" + NewStr() + sCurValue + sti(pchar.skill.FencingS);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F38", 1);
}

string descF39 = "Сабли \ Тесаки -1";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	if (sti(pchar.skill.FencingS) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingS = sti(pchar.skill.FencingS) - 1;
		Log_info(sSkillDec + "Сабли \ Тесаки!");
		totalInfo += sSkillDec + "Сабли \ Тесаки!" + NewStr() + sCurValue + sti(pchar.skill.FencingS);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F39", 1);
}

string descF40 = "Палаши \ Топоры +1";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	if (sti(pchar.skill.FencingH) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingH = sti(pchar.skill.FencingH) + 1;
		Log_info(sSkillInc + "Палаши \ Топоры!");
		totalInfo += sSkillInc + "Палаши \ Топоры!" + NewStr() + sCurValue + sti(pchar.skill.FencingH);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F40", 1);
}

string descF41 = "Палаши \ Топоры -1";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	if (sti(pchar.skill.FencingH) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingH = sti(pchar.skill.FencingH) - 1;
		Log_info(sSkillDec + "Палаши \ Топоры!");
		totalInfo += sSkillDec + "Палаши \ Топоры!" + NewStr() + sCurValue + sti(pchar.skill.FencingH);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F41", 1);
}

string descF42 = "Пистоли \ Мушкеты +1";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	if (sti(pchar.skill.Pistol) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Pistol = sti(pchar.skill.Pistol) + 1;
		Log_info(sSkillInc + "Пистоли \ Мушкеты!");
		totalInfo += sSkillInc + "Пистоли \ Мушкеты!" + NewStr() + sCurValue + sti(pchar.skill.Pistol);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F42", 1);
}

string descF43 = "Пистоли \ Мушкеты -1";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	if (sti(pchar.skill.Pistol) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Pistol = sti(pchar.skill.Pistol) - 1;
		Log_info(sSkillDec + "Пистоли \ Мушкеты!");
		totalInfo += sSkillDec + "Пистоли \ Мушкеты!" + NewStr() + sCurValue + sti(pchar.skill.Pistol);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F43", 1);
}

string descF44 = "Везение +1";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	if (sti(pchar.skill.Fortune) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Fortune = sti(pchar.skill.Fortune) + 1;
		Log_info(sSkillInc + "Везение!");
		totalInfo += sSkillInc + "Везение!" + NewStr() + sCurValue + sti(pchar.skill.Fortune);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F44", 1);
}

string descF45 = "Везение -1";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	if (sti(pchar.skill.Fortune) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Fortune = sti(pchar.skill.Fortune) - 1;
		Log_info(sSkillDec + "Везение!");
		totalInfo += sSkillDec + "Везение!" + NewStr() + sCurValue + sti(pchar.skill.Fortune);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F45", 1);
}

string descF46 = "Скрытность +1";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	if (sti(pchar.skill.Sneak) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Sneak = sti(pchar.skill.Sneak) + 1;
		Log_info(sSkillInc + "Скрытность!");
		totalInfo += sSkillInc + "Скрытность!" + NewStr() + sCurValue + sti(pchar.skill.Sneak);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F46", 1);
}

string descF47 = "Скрытность -1";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	if (sti(pchar.skill.Sneak) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Sneak = sti(pchar.skill.Sneak) - 1;
		Log_info(sSkillDec + "Скрытность!");
		totalInfo += sSkillDec + "Скрытность!" + NewStr() + sCurValue + sti(pchar.skill.Sneak);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F47", 1);
}

string descF48 = "Навигация +1";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	if (sti(pchar.skill.Sailing) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Sailing = sti(pchar.skill.Sailing) + 1;
		Log_info(sSkillInc + "Навигация!");
		totalInfo += sSkillInc + "Навигация!" + NewStr() + sCurValue + sti(pchar.skill.Sailing);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F48", 1);
}

string descF49 = "Навигация -1";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	if (sti(pchar.skill.Sailing) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Sailing = sti(pchar.skill.Sailing) - 1;
		Log_info(sSkillDec + "Навигация!");
		totalInfo += sSkillDec + "Навигация!" + NewStr() + sCurValue + sti(pchar.skill.Sailing);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F45", 1);
}

string descF50 = "Меткость +1";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	if (sti(pchar.skill.Accuracy) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Accuracy = sti(pchar.skill.Accuracy) + 1;
		Log_info(sSkillInc + "Меткость!");
		totalInfo += sSkillInc + "Меткость!" + NewStr() + sCurValue + sti(pchar.skill.Accuracy);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F50", 1);
}

string descF51 = "Меткость -1";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	if (sti(pchar.skill.Accuracy) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Accuracy = sti(pchar.skill.Accuracy) - 1;
		Log_info(sSkillDec + "Меткость!");
		totalInfo += sSkillDec + "Меткость!" + NewStr() + sCurValue + sti(pchar.skill.Accuracy);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F51", 1);
}

string descF52 = "Орудия +1";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	if (sti(pchar.skill.Cannons) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Cannons = sti(pchar.skill.Cannons) + 1;
		Log_info(sSkillInc + "Орудия!");
		totalInfo += sSkillInc + "Орудия!" + NewStr() + sCurValue + sti(pchar.skill.Cannons);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F52", 1);
}

string descF53 = "Орудия -1";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	if (sti(pchar.skill.Cannons) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Cannons = sti(pchar.skill.Cannons) - 1;
		Log_info(sSkillDec + "Орудия!");
		totalInfo += sSkillDec + "Орудия!" + NewStr() + sCurValue + sti(pchar.skill.Cannons);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F53", 1);
}

string descF54 = "Абордаж +1";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	if (sti(pchar.skill.Grappling) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Grappling = sti(pchar.skill.Grappling) + 1;
		Log_info(sSkillInc + "Абордаж!");
		totalInfo += sSkillInc + "Абордаж!" + NewStr() + sCurValue + sti(pchar.skill.Grappling);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F54", 1);
}

string descF55 = "Абордаж -1";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	if (sti(pchar.skill.Grappling) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Grappling = sti(pchar.skill.Grappling) - 1;
		Log_info(sSkillDec + "Абордаж!");
		totalInfo += sSkillDec + "Абордаж!" + NewStr() + sCurValue + sti(pchar.skill.Grappling);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F55", 1);
}

string descF56 = "Защита +1";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	if (sti(pchar.skill.Defence) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Defence = sti(pchar.skill.Defence) + 1;
		Log_info(sSkillInc + "Защита!");
		totalInfo += sSkillInc + "Защита!" + NewStr() + sCurValue + sti(pchar.skill.Defence);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F56", 1);
}

string descF57 = "Защита -1";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	if (sti(pchar.skill.Defence) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Defence = sti(pchar.skill.Defence) - 1;
		Log_info(sSkillDec + "Защита!");
		totalInfo += sSkillDec + "Защита!" + NewStr() + sCurValue + sti(pchar.skill.Defence);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F57", 1);
}

string descF58 = "Починка +1";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	if (sti(pchar.skill.Repair) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Repair = sti(pchar.skill.Repair) + 1;
		Log_info(sSkillInc + "Починка!");
		totalInfo += sSkillInc + "Починка!" + NewStr() + sCurValue + sti(pchar.skill.Repair);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F58", 1);
}

string descF59 = "Починка -1";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	if (sti(pchar.skill.Repair) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Repair = sti(pchar.skill.Repair) - 1;
		Log_info(sSkillDec + "Починка!");
		totalInfo += sSkillDec + "Починка!" + NewStr() + sCurValue + sti(pchar.skill.Repair);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F59", 1);
}

string descF60 = "Торговля +1";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	if (sti(pchar.skill.Commerce) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Commerce = sti(pchar.skill.Commerce) + 1;
		Log_info(sSkillInc + "Торговля!");
		totalInfo += sSkillInc + "Торговля!" + NewStr() + sCurValue + sti(pchar.skill.Commerce);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMaxValue);
		totalInfo += sMaxValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F60", 1);
}

string descF61 = "Торговля -1";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	if (sti(pchar.skill.Commerce) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Commerce = sti(pchar.skill.Commerce) - 1;
		Log_info(sSkillDec + "Торговля!");
		totalInfo += sSkillDec + "Торговля!" + NewStr() + sCurValue + sti(pchar.skill.Commerce);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info(sMinValue);
		totalInfo += sMinValue;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F61", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F62", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F63", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F64", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F65", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F66", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F67", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F68", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F69", 1);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F70", 1);
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
			sHeader = "Описание меню 'Умения'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Умения' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Умения'";
			sText1 = "Перезапуск меню 'Умения'";
		break;
		case "B_M1":
			sHeader = "Меню 'Персонаж'";
			sText1 = "Запуск меню 'Персонаж'";
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
