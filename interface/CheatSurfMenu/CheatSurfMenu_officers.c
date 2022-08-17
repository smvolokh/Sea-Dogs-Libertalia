
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Редактирование офицеров
	Основано на меню дебаггера от boal
	08.06.19
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** Щелкните по кнопке 'Офицеры' вверху, чтобы вновь отобразить перечень команд данного меню ***";

string sTXT = "!";
string sName = "Имя офицера: ";
string sNoChar = "Нет офицера, назначенного на эту должность!";
string sRank = "Текущий ранг офицера: ";
string sRankMax = "Уровень офицера достиг максимального значения!";
string sRankMin = "Уровень офицера достиг минимального значения!";
string sHPMax = "Кол-во HP офицера достигло максимального значения!";
string sHPMin = "Кол-во HP офицера достигло минимального значения!";
string sHPNow = "Текущее кол-во HP офицера: ";
string sNewOffA = "С появлением каждого нового офицера в команде ГГ, данную опцию нужно задавать повторно.";
string sNewOffB = "Иначе, на новобранца эффект от нее распространяться не будет!";
string sFace = "interfaces\portraits\256\face_";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_officers";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(6); // Warship. Статистика - сколько читов юзали
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
					"********** ПОВЫШЕНИЕ УРОВНЯ **********" + NewStr() +
					"---------- Повысить уровень на 1 ----------" + NewStr() +
					"<  1 > " + descF1 + GetOfficerName(7) + NewStr() + "<  2 > " + descF2 + GetOfficerName(8) + NewStr() + "<  3 > " + descF3 + GetOfficerName(9) + NewStr() +
					"<  4 > " + descF4 + GetOfficerName(1) + NewStr() + "<  5 > " + descF5 + GetOfficerName(2) + NewStr() + "<  6 > " + descF6 + GetOfficerName(3) + NewStr() +
					"<  7 > " + descF7 + GetOfficerName(4) + NewStr() + "<  8 > " + descF8 + GetOfficerName(5) + NewStr() + "<  9 > " + descF9 + GetOfficerName(6) + NewStr() +
					"\n\n********** ПОНИЖЕНИЕ УРОВНЯ **********" + NewStr() +
					"---------- Понизить уровень на 1 ----------" + NewStr() +
					"< 10 > " + descF10 + GetOfficerName(7) + NewStr() + "< 11 > " + descF11 + GetOfficerName(8) + NewStr() + "< 12 > " + descF12 + GetOfficerName(9) + NewStr() +
					"< 13 > " + descF13 + GetOfficerName(1) + NewStr() + "< 14 > " + descF14 + GetOfficerName(2) + NewStr() + "< 15 > " + descF15 + GetOfficerName(3) + NewStr() +
					"< 16 > " + descF16 + GetOfficerName(4) + NewStr() + "< 17 > " + descF17 + GetOfficerName(5) + NewStr() + "< 18 > " + descF18 + GetOfficerName(6) + NewStr() +
					"\n\n********** ПОВЫШЕНИЕ HP **********" + NewStr() +
					"---------- Повысить HP на 5 единиц ----------" + NewStr() +
					"< 19 > " + descF19 + GetOfficerName(7) + NewStr() + "< 20 > " + descF20 + GetOfficerName(8) + NewStr() + "< 21 > " + descF21 + GetOfficerName(9) + NewStr() +
					"< 22 > " + descF22 + GetOfficerName(1) + NewStr() + "< 23 > " + descF23 + GetOfficerName(2) + NewStr() + "< 24 > " + descF24 + GetOfficerName(3) + NewStr() +
					"< 25 > " + descF25 + GetOfficerName(4) + NewStr() + "< 26 > " + descF26 + GetOfficerName(5) + NewStr() + "< 27 > " + descF27 + GetOfficerName(6) + NewStr() +
					"\n\n********** ПОНИЖЕНИЕ HP **********" + NewStr() +
					"---------- Понизить HP на 5 единиц ----------" + NewStr() +
					"< 28 > " + descF28 + GetOfficerName(7) + NewStr() + "< 29 > " + descF29 + GetOfficerName(8) + NewStr() + "< 30 > " + descF30 + GetOfficerName(9) + NewStr() +
					"< 31 > " + descF31 + GetOfficerName(1) + NewStr() + "< 32 > " + descF32 + GetOfficerName(2) + NewStr() + "< 33 > " + descF33 + GetOfficerName(3) + NewStr() +
					"< 34 > " + descF34 + GetOfficerName(4) + NewStr() + "< 35 > " + descF35 + GetOfficerName(5) + NewStr() + "< 36 > " + descF36 + GetOfficerName(6) + NewStr() +
					"\n\n********** ИЗМЕНЕНИЕ РЕПУТАЦИИ **********" + NewStr() +
					"---------- Изменить репутацию (плохиш или добряк) ----------" + NewStr() +
					"< 37 > " + descF37 + GetOfficerName(7) + NewStr() + "< 38 > " + descF38 + GetOfficerName(8) + NewStr() + "< 39 > " + descF39 + GetOfficerName(9) + NewStr() +
					"< 40 > " + descF40 + GetOfficerName(1) + NewStr() + "< 41 > " + descF41 + GetOfficerName(2) + NewStr() + "< 42 > " + descF42 + GetOfficerName(3) + NewStr() +
					"< 43 > " + descF43 + GetOfficerName(4) + NewStr() + "< 44 > " + descF44 + GetOfficerName(5) + NewStr() + "< 45 > " + descF45 + GetOfficerName(6) + NewStr() +
					"\n\n********** УДАЛЕНИЕ ПЕРКОВ **********" + NewStr() +
					"---------- Удалить все изученные перки (кроме скрытых и бонусных) ----------" + NewStr() +
					"< 46 > " + descF46 + GetOfficerName(7) + NewStr() + "< 47 > " + descF47 + GetOfficerName(8) + NewStr() + "< 48 > " + descF48 + GetOfficerName(9) + NewStr() +
					"< 49 > " + descF49 + GetOfficerName(1) + NewStr() + "< 50 > " + descF50 + GetOfficerName(2) + NewStr() + "< 51 > " + descF51 + GetOfficerName(3) + NewStr() +
					"< 52 > " + descF52 + GetOfficerName(4) + NewStr() + "< 53 > " + descF53 + GetOfficerName(5) + NewStr() + "< 54 > " + descF54 + GetOfficerName(6) + NewStr() +
					"\n\n********** ИЗМЕНЕНИЕ P.I.R.A.T.E.S. **********" + NewStr() +
					"---------- Добавить \ очистить свободные очки P.I.R.A.T.E.S. ----------" + NewStr() +
					"< 55 > " + descF55 + GetOfficerName(7) + NewStr() + "< 56 > " + descF56 + GetOfficerName(8) + NewStr() + "< 57 > " + descF57 + GetOfficerName(9) + NewStr() +
					"< 58 > " + descF58 + GetOfficerName(1) + NewStr() + "< 59 > " + descF59 + GetOfficerName(2) + NewStr() + "< 60 > " + descF60 + GetOfficerName(3) + NewStr() +
					"< 61 > " + descF61 + GetOfficerName(4) + NewStr() + "< 62 > " + descF62 + GetOfficerName(5) + NewStr() + "< 63 > " + descF63 + GetOfficerName(6) + NewStr() +
					"\n\n********** ПРОЧЕЕ **********" + NewStr() +
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
		case "CSM_TITLE": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_OFFICERS);} break;
		case "B_M1": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_CHARS);} break;
		case "B_M2": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SKILLS);} break;
		case "B_M3": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_ITEMS);} break;
		case "B_M4": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPSTUNING);} break;
		case "B_M5": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_TOWNS);} break;
		case "B_M6": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_GOODS);} break;
		case "B_M7": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_SHIPS);} break;
		case "B_M8": if(comName=="activate" || comName=="click") {IDoExit(RC_INTERFACE_RUN_CSM_MISC);} break;
	}
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(6); // Статистика по читам
}

string descF1 = "Абордажнику #1";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Первому абордажнику увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F1", 1);
}

string descF2 = "Абордажнику #2";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Второму абордажнику увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F2", 1);
}

string descF3 = "Абордажнику #3";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Третьему абордажнику увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F3", 1);
}

string descF4 = "Штурману";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Штурману увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F4", 1);
}

string descF5 = "Боцману";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Боцману увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F5", 1);
}

string descF6 = "Канониру";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Канониру увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F6", 1);
}

string descF7 = "Врачу";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Врачу увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F7", 1);
}

string descF8 = "Казначею";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Казначею увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F8", 1);
}

string descF9 = "Плотнику";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) < 99)
		{
			sld.rank = sti(sld.rank) + 1;
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Плотнику увеличен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) > 99) sld.rank = 99;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMax + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F9", 1);
}

string descF10 = "Абордажнику #1";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Первому абордажнику уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F10", 1);
}

string descF11 = "Абордажнику #2";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Второму абордажнику уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F11", 1);
}

string descF12 = "Абордажнику #3";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Третьему абордажнику уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F12", 1);
}

string descF13 = "Штурману";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Штурману уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F13", 1);
}

string descF14 = "Боцману";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Боцману уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F14", 1);
}

string descF15 = "Канониру";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Канониру уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F15", 1);
}

string descF16 = "Врачу";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Врачу уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F16", 1);
}

string descF17 = "Казначею";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Казначею уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F17", 1);
}

string descF18 = "Плотнику";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.rank) > 1)
		{
			sld.rank = sti(sld.rank) - 1;
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Плотнику уменьшен ранг!" + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
		else
		{
			if (sti(sld.rank) < 1) sld.rank = 1;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sRankMin + NewStr() + sName + GetFullName(sld) + NewStr() + sRank + sti(sld.rank);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F18", 1);
}

string descF19 = "Абордажнику #1";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Первому абордажнику увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F19", 1);
}

string descF20 = "Абордажнику #2";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Второму абордажнику увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F20", 1);
}

string descF21 = "Абордажнику #3";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Третьему абордажнику увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F21", 1);
}

string descF22 = "Штурману";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Штурману увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F22", 1);
}

string descF23 = "Боцману";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Боцману увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F23", 1);
}

string descF24 = "Канониру";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Канониру увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F24", 1);
}

string descF25 = "Врачу";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Врачу увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F25", 1);
}

string descF26 = "Казначею";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Казначею увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F26", 1);
}

string descF27 = "Плотнику";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) < 999.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) + 5.0;
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Плотнику увеличено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) > 999.0) sld.chr_ai.hp_max = 999.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMax + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F27", 1);
}

string descF28 = "Абордажнику #1";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Первому абордажнику уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F28", 1);
}

string descF29 = "Абордажнику #2";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Второму абордажнику уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F29", 1);
}

string descF30 = "Абордажнику #3";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Третьему абордажнику уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F30", 1);
}

string descF31 = "Штурману";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Штурману уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F31", 1);
}

string descF32 = "Боцману";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Боцману уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F32", 1);
}

string descF33 = "Канониру";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Канониру уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F33", 1);
}

string descF34 = "Врачу";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Врачу уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F34", 1);
}

string descF35 = "Казначею";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Казначею уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F35", 1);
}

string descF36 = "Плотнику";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (stf(sld.chr_ai.hp_max) > 50.0)
		{
			sld.chr_ai.hp_max = stf(sld.chr_ai.hp_max) - 5.0;
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			LAi_SetCurHPMax(sld);
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "Плотнику уменьшено кол-во HP!" + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
		else
		{
			if (stf(sld.chr_ai.hp_max) < 50.0) sld.chr_ai.hp_max = 50.0;
			iSND = PlaySound("_CheatSurfMenu_\WTH.wav");
			totalInfo += sHPMin + NewStr() + sName + GetFullName(sld) + NewStr() + sHPNow + sti(sld.chr_ai.hp_max);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F36", 1);
}

string descF37 = "Абордажнику #1";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация абордажника #1: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация абордажника #1: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F37", 1);
}

string descF38 = "Абордажнику #2";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация абордажника #2: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация абордажника #2: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F38", 1);
}

string descF39 = "Абордажнику #3";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация абордажника #3: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация абордажника #3: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F39", 1);
}

string descF40 = "Штурману";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация штурмана: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация штурмана: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F40", 1);
}

string descF41 = "Боцману";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация боцмана: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация боцмана: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F41", 1);
}

string descF42 = "Канониру";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация канонира: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация канонира: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F42", 1);
}

string descF43 = "Врачу";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация врача: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация врача: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F43", 1);
}

string descF44 = "Казначею";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация казначея: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация казначея: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F44", 1);
}

string descF45 = "Плотнику";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (CheckAttribute(sld, "alignment"))
		{
			if (sld.alignment == "good")
			{
				sld.alignment = "bad";
				iSND = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
				totalInfo += "Репутация плотника: 'плохиш'" + NewStr() + sName + GetFullName(sld);
			}
			else
			{
				sld.alignment = "good";
				iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
				totalInfo += "Репутация плотника: 'добряк'" + NewStr() + sName + GetFullName(sld);
			}
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "Этому офицеру все равно на действия ГГ!" + NewStr() + sName + GetFullName(sld);
		}
		if (CheckAttribute(sld, "loyality"))
		{
			GetCharacterLoyality(sld);
			sld.loyality = MAX_LOYALITY;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F45", 1);
}

string descF46 = "Абордажнику #1";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Первому абордажнику удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F46", 1);
}

string descF47 = "Абордажнику #2";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Второму абордажнику удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F47", 1);
}

string descF48 = "Абордажнику #3";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Третьему абордажнику удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F48", 1);
}

string descF49 = "Штурману";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Штурману удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F49", 1);
}

string descF50 = "Боцману";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Боцману удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F50", 1);
}

string descF51 = "Канониру";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Канониру удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F51", 1);
}

string descF52 = "Врачу";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Врачу удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F52", 1);
}

string descF53 = "Казначею";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Казначею удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F53", 1);
}

string descF54 = "Плотнику";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	ref sld;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		DeleteAttribute(sld, "perks.list");
		SetBasePerks(sld);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "Плотнику удалены все изученные перки!" + NewStr() + sName + GetFullName(sld);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F54", 1);
}

string descF55 = "Абордажнику #1";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 1);
	bool bToExit = false;
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Абордажнику #1 добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Абордажнику #1 добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESFighterA", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Абордажнику #1 очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F55", 1);
}

string descF56 = "Абордажнику #2";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 2);
	bool bToExit = false;
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Абордажнику #2 добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Абордажнику #2 добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESFighterB", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Абордажнику #2 очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F56", 1);
}

string descF57 = "Абордажнику #3";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	ref sld;
	int ion = GetOfficersIndex(pchar, 3);
	bool bToExit = false;
	if (ion != -1)
	{
		sld = GetCharacter(ion);
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Абордажнику #3 добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Абордажнику #3 добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESFighterC", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Абордажнику #3 очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F57", 1);
}

string descF58 = "Штурману";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Штурману добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Штурману добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESNavigator", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Штурману очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F58", 1);
}

string descF59 = "Боцману";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Боцману добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Боцману добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESBoatswain", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Боцману очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F59", 1);
}

string descF60 = "Канониру";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Канониру добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Канониру добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESCannoner", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Канониру очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F60", 1);
}

string descF61 = "Врачу";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Врачу добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Врачу добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESDoctor", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Врачу очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F61", 1);
}

string descF62 = "Казначею";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Казначею добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Казначею добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESTreasurer", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Казначею очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F62", 1);
}

string descF63 = "Плотнику";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	ref sld;
	bool bToExit = false;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		if (sti(sld.FaceId) >= 0) SetNewPicture("CSMPICTURE", sFace + sti(sld.FaceId) + ".tga");
		if (sti(sld.skill.freespecial) < 1)
		{
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			sld.skill.freespecial = 35;
			// Log_info("Плотнику добавлены свободные очки P.I.R.A.T.E.S.!");
			// Log_info(sName + GetFullName(sld));
			// totalInfo += "Плотнику добавлены свободные очки P.I.R.A.T.E.S.!" + NewStr() + sName + GetFullName(sld);
			DoQuestFunctionDelay("ChangePIRATESCarpenter", 0.35);
			bToExit = true;
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			sld.skill.freespecial = 0;
			totalInfo += "Плотнику очищены свободные очки P.I.R.A.T.E.S." + NewStr() + sName + GetFullName(sld);
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += sNoChar;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bToExit) ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F63", 1);
}

string descF64 = "Добавить \ очистить свободные очки умений должностным офицерам и компаньонам";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	ref sld;
	int iona = GetOfficersIndex(pchar, 1);
	int ionb = GetOfficersIndex(pchar, 2);
	int ionc = GetOfficersIndex(pchar, 3);
	int ic, icn;
	int iOffs = 0;
	bool bCompanions = false;
	string sSkillsAdd = "добавлены свободные очки умений!";
	string sSkillsDel = "очищены все свободные очки умений.";
	if (!CheckAttribute(pchar, "CSM.OfficersFreeSkill"))
	{
		pchar.CSM.OfficersFreeSkill = true;
		if (iona != -1)
		{
			iOffs++;
			sld = GetCharacter(iona);
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Абордажник #1 - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #1. " + sNoChar;
		}
		if (ionb != -1)
		{
			iOffs++;
			sld = GetCharacter(ionb);
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Абордажник #2 - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #2. " + sNoChar;
		}
		if (ionc != -1)
		{
			iOffs++;
			sld = GetCharacter(ionc);
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Абордажник #3 - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #3. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.navigator) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Штурман - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Штурман. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.boatswain) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Боцман - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Боцман. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.cannoner) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Канонир - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Канонир. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.doctor) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Врач - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Врач. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.treasurer) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Казначей - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Казначей. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.carpenter) != -1)
		{
			iOffs++;
			sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
			if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
			totalInfo += NewStr() + "Плотник - " + sSkillsAdd;
		}
		else
		{
			totalInfo += NewStr() + "Плотник. " + sNoChar;
		}
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				if (sti(sld.Skill.FreeSkill) < 99) sld.Skill.FreeSkill = 99;
				if (!bCompanions) bCompanions = true;
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		if (bCompanions) totalInfo += "\n\nВсем имеющимся компаньонам " + sSkillsAdd;
		if (iOffs > 0) totalInfo += "\n\nВойдите в меню персонажей (F2) и распределите умения своим должностным офицерам.";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.OfficersFreeSkill");
		if (iona != -1)
		{
			sld = GetCharacter(iona);
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Абордажник #1 - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #1. " + sNoChar;
		}
		if (ionb != -1)
		{
			sld = GetCharacter(ionb);
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Абордажник #2 - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #2. " + sNoChar;
		}
		if (ionc != -1)
		{
			sld = GetCharacter(ionc);
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Абордажник #3 - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Абордажник #3. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.navigator) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Штурман - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Штурман. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.boatswain) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Боцман - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Боцман. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.cannoner) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Канонир - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Канонир. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.doctor) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Врач - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Врач. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.treasurer) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Казначей - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Казначей. " + sNoChar;
		}
		if (sti(pchar.Fellows.Passengers.carpenter) != -1)
		{
			sld = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
			if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
			totalInfo += NewStr() + "Плотник - " + sSkillsDel;
		}
		else
		{
			totalInfo += NewStr() + "Плотник. " + sNoChar;
		}
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				if (sti(sld.Skill.FreeSkill) > 0) sld.Skill.FreeSkill = 0;
				if (!bCompanions) bCompanions = true;
			}
		}
		if (bCompanions) totalInfo += NewStr() + "Всем имеющимся компаньонам очищены свободные очки умений.";
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F64", 1);
}

string descF65 = "Добавить \ очистить свободные очки перков всем офицерам и компаньонам";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	ref sld;
	int ic, ip, icn, ipn;
	if (!CheckAttribute(pchar, "CSM.OfficersFreePerks"))
	{
		pchar.CSM.OfficersFreePerks = true;
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				sld.Perks.FreePoints_Self = 17;
				sld.Perks.FreePoints_Ship = 32;
			}
		}
		for (ip=0; ip<GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					sld.Perks.FreePoints_Self = 17;
					sld.Perks.FreePoints_Ship = 32;
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Officer_5.wav");
		Log_info("Все офицеры и компаньоны получили максимальное кол-во свободных очков перков!");
		totalInfo += "Все офицеры и компаньоны получили максимальное кол-во свободных очков перков!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.OfficersFreePerks");
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				sld.Perks.FreePoints_Self = 0;
				sld.Perks.FreePoints_Ship = 0;
			}
		}
		for (ip=0; ip<GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					sld.Perks.FreePoints_Self = 0;
					sld.Perks.FreePoints_Ship = 0;
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Всем офицерам и компаньонам очищены свободные очки перков.");
		totalInfo += "Всем офицерам и компаньонам очищены свободные очки перков.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F65", 1);
}

string descF66 = "Включить \ отключить бессмертие всем офицерам и компаньонам";
void CalculateInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	CommonActions();
	ref sld;
	int ic, io, icn, ion;
	if (!CheckAttribute(pchar, "CSM.OfficersGodMode"))
	{
		pchar.CSM.OfficersGodMode = true;
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);

			if (icn != -1)
			{
				sld = GetCharacter(icn);

				if (!HasSubStr(sld.id, "Guide"))
				{
					LAi_SetImmortal(sld, 1);
					sld.CSM.MastNoFall = true;
				}
			}
		}
/*
		// Только абордажникам
		for (io=1; io<4; io++)
		{
			ion = GetOfficersIndex(pchar, io);
			if (ion != -1)
			{
				sld = GetCharacter(ion);
				if (CheckAttribute(sld, "chr_ai.type") && sld.chr_ai.type == LAI_TYPE_OFFICER)
				{
					LAi_SetImmortal(sld, 1);
					sld.CSM.MastNoFall = true;
				}
			}
		}
*/
		for (io=0; io<GetPassengersQuantity(pchar); io++)
		{
			ion = GetPassenger(pchar, io);
			if (ion != -1)
			{
				sld = GetCharacter(ion);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					if (!HasSubStr(sld.id, "Guide"))
					{
						LAi_SetImmortal(sld, 1);
						sld.CSM.MastNoFall = true;
					}
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Все офицеры и компаньоны получили бессмертие!");
		totalInfo += "Все офицеры и компаньоны получили бессмертие!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.OfficersGodMode");
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				LAi_SetImmortal(sld, 0);
				DeleteAttribute(sld, "CSM.MastNoFall");
			}
		}
/*
		// Только абордажникам
		for (io=1; io<4; io++)
		{
			ion = GetOfficersIndex(pchar, io);
			if (ion != -1)
			{
				sld = GetCharacter(ion);
				if (CheckAttribute(sld, "chr_ai.type") && sld.chr_ai.type == LAI_TYPE_OFFICER)
				{
					LAi_SetImmortal(sld, 0);
					DeleteAttribute(sld, "CSM.MastNoFall");
				}
			}
		}
*/
		for (io=0; io<GetPassengersQuantity(pchar); io++)
		{
			ion = GetPassenger(pchar, io);
			if (ion != -1)
			{
				sld = GetCharacter(ion);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					LAi_SetImmortal(sld, 0);
					DeleteAttribute(sld, "CSM.MastNoFall");
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Все офицеры и компаньоны лишились бессмертия...");
		totalInfo += "Все офицеры и компаньоны лишились бессмертия...";
	}
	totalInfo += "\n\nВажно!" + NewStr() + sNewOffA + NewStr() + sNewOffB;
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F66", 1);
}

string descF67 = "Запретить \ разрешить офицерам и компаньонам уходить со службы";
void CalculateInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	CommonActions();
	ref sld;
	int ic, ip, icn, ipn;
	if (!CheckAttribute(pchar, "CSM.OfficersQuit"))
	{
		pchar.CSM.OfficersQuit = true;
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				sld.loyality = MAX_LOYALITY;
				sld.OfficerWantToGo.DontGo = true;
			}
		}
		for (ip=0; ip<GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					sld.loyality = MAX_LOYALITY;
					sld.OfficerWantToGo.DontGo = true;
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("Офицеры и компаньоны не могут уходить со службы!");
		totalInfo += "Офицеры и компаньоны не могут уходить со службы!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.OfficersQuit");
		for (ic=1; ic<COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				sld.loyality = MAX_LOYALITY;
				sld.OfficerWantToGo.DontGo = false;
				DeleteAttribute(sld, "OfficerWantToGo.DontGo");
			}
		}
		for (ip=0; ip<GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- психанул ^^
				{
					sld.loyality = MAX_LOYALITY;
					sld.OfficerWantToGo.DontGo = false;
					DeleteAttribute(sld, "OfficerWantToGo.DontGo");
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Офицеры и компаньоны могут уходить со службы.");
		totalInfo += "Офицеры и компаньоны могут уходить со службы.";
	}
	totalInfo += "\n\nВажно!" + NewStr() + sNewOffA + NewStr() + sNewOffB;
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F67", 1);
}

string descF68 = "Задать уровень зарплаты офицерам, компаньонам и матросам";
void CalculateInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	CommonActions();

	float fCP;
	string sNext = "\nСледующее нажатие: ";
	string message = "В эскадре ГГ зп всем офицерам, компаньонам и матросам ";

	if (!csmCA(pchar, "CSM.CrewPayment") || stf(pchar.CSM.CrewPayment) < 0.0 || stf(pchar.CSM.CrewPayment) > 1.0)
		pchar.CSM.CrewPayment = 1.0;

	fCP = stf(pchar.CSM.CrewPayment);

	switch (fCP)
	{
		case 1.0:
			fCP = 0.75;
			message += "снижена на 25%";
			sNext += "снижение зп на 50%";
			iSND = csmSound("Default", 0);
		break;
		case 0.75:
			fCP = 0.5;
			message += "снижена на 50%";
			sNext += "снижение зп на 75%";
			iSND = csmSound("Default", 0);
		break;
		case 0.5:
			fCP = 0.25;
			message += "снижена на 75%";
			sNext += "снижение зп на 100%";
			iSND = csmSound("Default", 0);
		break;
		case 0.25:
			fCP = 0.0;
			message += "не выплачивается совсем.";
			sNext += "по умолчанию";
			iSND = csmSound("Default", 0);
		break;
		case 0.0:
			fCP = 1.0;
			message += "выплачивается полностью!";
			sNext += "снижение зп на 25%";
			iSND = csmSound("Goods", 0);
		break;
	}

	pchar.CSM.CrewPayment = fCP;
	pchar.CSM.OfficersSalary = fCP;

	totalInfo += message + sNext + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM7.F68", 1);
}

// by Sticksъ -->
string descF69 = "Изъять экипированное оружие у абордажников";
void CalculateInfoDataF69()
{
    totalInfo = "#69 " + descF69;
	CommonActions();
    ref sld;
    int i, index, ioa, iob, ioc;
	string itm;

	ioa = GetOfficersIndex(pchar, 1);
	iob = GetOfficersIndex(pchar, 2);
	ioc = GetOfficersIndex(pchar, 3);

	if (ioa != -1 || iob != -1 || ioc != -1)
	{
		// Только абордажникам
		for (i = 1; i <= 3; i++)
		{
			index = GetOfficersIndex(pchar, i);
			if (index == -1)
				continue;
			sld = GetCharacter(index);

			if (CheckAttribute(sld, "HoldEquip"))
				DeleteAttribute(sld, "HoldEquip"); // как то эффетка не заметно

			// Cheatsurfer --> fix мушкетеров
			if (!CheckAttribute(sld, "IsMushketer") || sld.model.animation != "mushketer")
			{
				if (GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE) != "")
					RemoveOfficerEquip(sld, BLADE_ITEM_TYPE); // сабля -> инвентарь гг
				if (GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE) != "")
					RemoveOfficerEquip(sld, GUN_ITEM_TYPE); // пистоль -> инвентарь гг
			}
			else
			{
				itm = GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE);
				if (itm != "")
				{
					if (HasSubStr(itm, "mushket"))
					{
						SetOfficerToMushketer(sld, itm, false); // Снимаем мушкет
						if (GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE) != "")
							RemoveOfficerEquip(sld, BLADE_ITEM_TYPE); // сабля -> инвентарь гг
						if (GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE) != "")
							RemoveOfficerEquip(sld, GUN_ITEM_TYPE); // пистоль -> инвентарь гг
						SetOfficerToMushketer(sld, itm, true); // Цепляем мушкет
					}
				}
			}
		}
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("У всех абордажников изъяты экипированные сабли и пистоли, если таковые имелись!");
		totalInfo += "У всех абордажников изъяты экипированные сабли и пистоли, если таковые имелись!";
    }
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("Нет офицеров, назначенных на должность абордажников!");
		totalInfo += "Нет офицеров, назначенных на должность абордажников!";
	}
    totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM7.F69", 1);
}

string descF70 = "Нанять капеллана на корабль (офицер-поп)";
void CalculateInfoDataF70()
{
    totalInfo = "#70 " + descF70;
	CommonActions();
    ref chr;
	int ip, ipn;
    string itm, sCapellan;
	bool bVincentoOnShip = false;

	// Cheatsurfer --> fix если к этому моменту на корабле уже есть настоящий капеллан, удаляем его
	for (ip = 0; ip < GetPassengersQuantity(pchar); ip++)
	{
		ipn = GetPassenger(pchar, ip);
		if (ipn != -1)
		{
			chr = GetCharacter(ipn);
			if (CheckAttribute(chr, "prisoned")) continue;
			if (chr.id == "Vincento_Capellan" && pchar.questTemp.ShipCapellan.id == "Vincento_Capellan")
			{
				bVincentoOnShip = true;
				continue;
			}
			if (CheckAttribute(chr, "quest.capellan"))
			{
				sCapellan = GetFullName(chr);
				RemovePassenger(pchar, chr);
				chr.lifeday = 0;
				totalInfo += "Настоящий капеллан - " + sCapellan + " - покинул корабль!";
				break;
			}
		}
	}
	// <--

	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		if (!bVincentoOnShip)
		{
			SetNewPicture("CSMPICTURE", "interfaces\portraits\256\face_234.tga");
			chr = GetCharacter(NPC_GenerateCharacter("Vincento_Capellan", "vincento", "man", "man_B", 1, SPAIN, -1, true, "quest"));
			chr.name = "Отец";
			chr.lastname = "Винсенто";
			chr.greeting = "vincento_1";
			pchar.questTemp.ShipCapellan = "true"; // чтобы настоящий не приставал
			pchar.questTemp.ShipCapellan.id = chr.id;
			pchar.questTemp.ShipCapellan.Yes = "true";
			chr.city = "Santiago";
			chr.Dialog.Filename = "Population\Monk.c";
			chr.dialog.currentnode = "capellan_4";
			FaceMaker(chr);
			chr.rank = 1;
			LAi_SetHP(chr, 80.0, 80.0);
			SetSPECIAL(chr, 10, 10, 10, 10, 10, 10, 10);
			DeleteAttribute(chr, "perks.list");
//			SelAllPerksToChar(chr, true);
			SetRandSelfSkill(chr, 10, 10);
			SetRandShipSkill(chr, 10, 10);
			SetCharacterPerk(chr, "Energaiser");
			SetCharacterPerk(chr, "HT3");
			chr.quest.OfficerPrice = sti(pchar.rank)*500;
			LAi_SetImmortal(chr, false);
			chr.HalfImmortal = true;
			chr.OfficerWantToGo.DontGo = true;
			chr.CompanionDisable = true;
			chr.loyality = MAX_LOYALITY;
			AddPassenger(pchar, chr, false);
			DeleteAttribute(chr, "CityType");
			SetCharacterRemovable(chr, true);
			chr.Payment = true; // пусть на окладе сидит
			chr.DontClearDead = true;
			if (CheckAttribute(chr, "HoldEquip"))
				DeleteAttribute(chr, "HoldEquip");
			LAi_SetOfficerType(chr);
			LAi_group_MoveCharacter(chr, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(chr, "HiredDate");
			chr.reputation = 50;

			RemoveAllCharacterItems(chr, true);
			itm = GetBestGeneratedItem("blade_33");
			TakenItems(chr, itm, 1);
			EquipCharacterbyItem(chr, itm);
			GiveItem2Character(chr, "pistol2");
			if (GetCharacterEquipByGroup(chr, GUN_ITEM_TYPE) == "")
				EquipCharacterbyItem(chr, "pistol2");
			TakeNItems(chr, "grapeshot", 50);
			TakeNItems(chr, "GunPowder", 50);
			GiveItem2Character(chr, "cirass4");
			TakeNItems(chr, "potion4", 5);
			LAi_SetCharacterUseBullet(chr, "grapeshot");

			iSND = PlaySound("Voice\Russian\sharlie\Otec Vincento-03.wav");
			Log_info("Отец Винсенто теперь подрабатывает капелланом на корабле ГГ");
			totalInfo += NewStr() + "Отец Винсенто теперь подрабатывает капелланом на корабле ГГ!";
		}
		else
		{
			iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
			Log_info("Капеллан на корабле уже есть.");
			totalInfo += "Капеллан на корабле уже есть!";
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
    Statistic_AddValue(PChar, "Cheats.CSM7.F70", 1);
}
// by Sticksъ <--

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
			sHeader = "Описание меню 'Офицеры'";
			sText1 = "Чтобы вновь отобразить перечень команд данного меню, щелкните по кнопке 'Офицеры' вверху";
		break;
		case "INFO_TEXT2":
			sHeader = "! ПУСТО !";
			sText1 = "! ПУСТО !";
		break;
		case "CSM_TITLE":
			sHeader = "Меню 'Офицеры'";
			sText1 = "Перезапуск меню 'Офицеры'";
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
