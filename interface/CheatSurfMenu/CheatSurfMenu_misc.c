
/*
	CheatSurfMenu by Cheatsurfer �� 07.01.2018 ��� ��� 1.6.0 (18.12.17)
	������
	�������� �� ���� ��������� �� boal
	09.07.19  //  ����� ����������
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** �������� �� ������ '������' ������, ����� ����� ���������� �������� ������ ������� ���� ***";

string sNoShip = "� ��� �� ��� �������, �������?!";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_misc";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(8); // Warship. ���������� - ������� ����� �����
	SetFormatedText("INFO_TEXT", totalInfo); //"���������� ���������";
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
		// ��� ����������� ������ ���������� � ������� � totalInfo - ������������� -->
		totalInfo = csmMenuText(1) + "\n\n" +
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() +
					"\n\n********** ��������� ���� **********" + NewStr() +
					"<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"\n\n********** ����������� **********" + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() +
					"\n\n********** ���������� **********" + NewStr() +
					"< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() +
					"\n\n< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() + "< 30 > " + descF30 + NewStr() +
					"< 31 > " + descF31 + NewStr() + "< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() +
					"< 34 > " + descF34 + NewStr() + "< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() +
					"< 37 > " + descF37 + NewStr() + "< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() +
					"< 40 > " + descF40 + NewStr() + "< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() +
					"< 43 > " + descF43 + NewStr() + "< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() +
					"< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() +  "< 53 > " + descF53 + NewStr() +
					"\n\n********** �������� ���� �� ������� (����� ������������� ������) **********" + NewStr() + "< 54 > " + descF54 + NewStr() + "< 55 > " + descF55 + GetCompanionName(1) + NewStr() + "< 56 > " + descF56 + GetCompanionName(2) + NewStr() + 
					"< 57 > " + descF57 + GetCompanionName(3) + NewStr() + "< 58 > " + descF58 + GetCompanionName(4) + NewStr() + "< 59 > " + descF59 + GetCompanionName(5) + NewStr() + 
					"< 60 > " + descF60 + GetCompanionName(6) + NewStr() + "< 61 > " + descF61 + GetCompanionName(7) + NewStr() + "\n\n ********** ������ ********** " + NewStr() + " < 62 > " + descF63 + NewStr() +
				"< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() + "< 65 > " + descF65 + NewStr() + "< 66 > " + descF66 + NewStr() +
					"< 67 > " + descF67 + NewStr() + "< 68 > " + descF68 + NewStr() + "< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
		// ������� ������ (�� ������� � ���� �� �����) +LanguageConvertString(idLngFile,"new_string");
		// ��� ����������� ������ ���������� � ������� � totalInfo <--
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
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(8); // ���������� �� �����
}

string descF1 = "�������� ���� ������ �� 1 ���� ������";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	LAi_Fade("", "");
	AddDataToCurrent(0, 0, 1);
	PlaySound("Interface\sobitie_na_karte_001.wav");
	Log_info("���� �������� ������ �������� �� 1 ���� ������.");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	ProcessCancelExit(); // ����������� �� �����, �� ��������� �����
	Statistic_AddValue(PChar, "Cheats.CSM9.F1", 1);
}

string descF2 = "�������� ���� ������ �� 1 ���� �����";
void CalculateInfoDataF2()
{
	totalInfo = "#2 " + descF2;
	CommonActions();
	bool bExit = false;
	if (GetDataDay() != 1)
	{
		bExit = true;
		LAi_Fade("", "");
		AddDataToCurrent(0, 0, -1);
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("���� �������� ������ �������� �� 1 ���� �����.");
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("� 1-�� ���� ������ ����� ������� ������...");
		totalInfo += "� 1-�� ���� ������ ����� ������� ������...";
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	if (bExit) ProcessCancelExit(); // ����������� �� �����, �� ��������� �����
	Statistic_AddValue(PChar, "Cheats.CSM9.F2", 1);
}

string descF3 = "�������� ��������� ����";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	string sLvl = XI_ConvertString("m_Complexity") + ": ";
	string sLvlCur = "��������� ��������� ����: ";
	string sExp = XI_ConvertString("Exp_Rate_Speed") + " (��� ������ ��� ��������, ��� ������� ������ ������): ";
	string sNext = "��������� �����: ";
	string sLvlN, sLvlX;
	string sLvlA = XI_ConvertString("m_Complexity_1");
	string sLvlB = XI_ConvertString("m_Complexity_3");
	string sLvlC = XI_ConvertString("m_Complexity_5");
	string sLvlD = XI_ConvertString("m_Complexity_7");
	string sLvlE = XI_ConvertString("m_Complexity_9");
	string sLvl1 = " (����� �����)!";
	string sLvl2 = " (�����)!";
	string sLvl3 = " (������)!";
	string sLvl4 = " (������)!";
	string sLvl5 = " (����� ������)!";
	switch (MOD_SKILL_ENEMY_RATE)
	{
		case 2: MOD_EXP_RATE = 30; MOD_SKILL_ENEMY_RATE = 4; sLvlX = sLvlB + sLvl2; sLvlN = sLvlC + sLvl3; break;
		case 4: MOD_EXP_RATE = 50; MOD_SKILL_ENEMY_RATE = 6; sLvlX = sLvlC + sLvl3; sLvlN = sLvlD + sLvl4; break;
		case 6: MOD_EXP_RATE = 75; MOD_SKILL_ENEMY_RATE = 8; sLvlX = sLvlD + sLvl4; sLvlN = sLvlE + sLvl5; break;
		case 8: MOD_EXP_RATE = 105; MOD_SKILL_ENEMY_RATE = 10; sLvlX = sLvlE + sLvl5; sLvlN = sLvlA + sLvl1; break;
		case 10: MOD_EXP_RATE = 15; MOD_SKILL_ENEMY_RATE = 2; sLvlX = sLvlA + sLvl1; sLvlN = sLvlB + sLvl2; break;
	}
	iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
	Log_info(sLvl + sLvlX);
	totalInfo += sLvlCur + sLvlX + NewStr() + sExp + MOD_EXP_RATE + NewStr() + sNext + sLvlN + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F3", 1);
}

string descF4 = "������� ��� �������� �������� (�������� ��� �������)";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	if (iArcadeSails == 1)
	{
		iArcadeSails = 0;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������� ����� ������������ �������� ���.");
		totalInfo += "������� ����� ������������ �������� ���." + NewStr() + "\n\n��������!\n��� ������� �����:" + NewStr() + "1) ������� ����� ������������" + NewStr() + "2) ������ ������������ ������ � �������� � ��������";
	}
	else
	{
		iArcadeSails = 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������� ����� ������������� �������� ��� (�� ���������)!");
		totalInfo += "������� ����� ������������� �������� ��� (�� ���������)!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F4", 1);
}

string descF5 = "��� \ ���� ��������� �������������� ������";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	if (bRechargePistolOnLine == true)
	{
		bRechargePistolOnLine = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("��������� �������������� ������ ���������.");
		totalInfo += "��������� �������������� ������ ���������.";
	}
	else
	{
		bRechargePistolOnLine = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("��������� �������������� ������ ��������!");
		totalInfo += "��������� �������������� ������ ��������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F5", 1);
}

string descF6 = "��� \ ���� ������ ������";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	if (bPartitionSet == true)
	{
		bPartitionSet = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������ ������ ��������.");
		totalInfo += "������ ������ ��������.";
	}
	else
	{
		bPartitionSet = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������ ������ �������!");
		totalInfo += "������ ������ �������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F6", 1);
}

string descF7 = "��� \ ���� ����������� ������";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	if (bRains == true)
	{
		bRains = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("����������� ������ ���������.");
		totalInfo += "����������� ������ ���������.";
	}
	else
	{
		bRains = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("����������� ������ ��������!");
		totalInfo += "����������� ������ ��������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F7", 1);
}

string descF8 = "��� \ ���� ����������� ������� �������";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	bool bEnable = true;
	if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd") || bEnable)
	{
		if (bWorldAlivePause == true)
		{
			bWorldAlivePause = false;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "������� ����� �����������!" + NewStr() + "����� ���� ������ ����������� ����� ������� � ���� ��������.\n\n�����!\n��� ���������� ������� ����� ���������� �������, � �� ����� ��������� ��������!\n������ ����� ����� ������������ ����� ���������� ��������� ������ ����.";
		}
		else
		{
			bWorldAlivePause = true;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "������� ����� ������ �������.";
		}
	}
	else
	{
		if (!bWorldAlivePause) bWorldAlivePause = true;
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("�� ��������� ��������� �������, ��� ����� �������� ���� ����� ���������� ��������� ������ ����.");
		totalInfo += "�� ��������� ��������� �������, ��� ����� �������� ���� ����� ���������� ��������� ������ ����.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F8", 1);
}

string descF9 = "��� \ ���� ����� Hardcore";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	if (bHardcoreGame == true)
	{
		bHardcoreGame = false;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("����� Hardcore ��������. ����������� ����� ��� ������.");
		totalInfo += "����� Hardcore ��������. ����������� ����� ��� ������.";
	}
	else
	{
		bHardcoreGame = true;
		iSND = PlaySound("_CheatSurfMenu_\Hardcore.wav");
		Log_info("������� ����� Hardcore! ����������� ����� ������ � �������!");
		totalInfo += "��������!" + NewStr() + "������� ����� Hardcore! ����������� ����� ������ � �������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F9", 1);
}

// ����������� ���������� Sticks� -->
string descF10 = "�������� ����� �������� �� ������� �� (33 ��������)";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	string message;
	string sMSGe = "���������� ������� �����";
	string sMSGf = "����������� ������� �����";
	string sMSGs = "��������� ������� �����";
	string sMSGh = "����������� ������� �����";
	string sMSGc = "�������+�������+�������";
	string sTXTa = "�������";
	string sTXTb = "�������";
	string sTXTc = "�������";

	if (!CheckAttribute(pchar, "GenQuest.BoardCrewType")) // ������� �������� ��� ������������ ����� ������
		pchar.GenQuest.BoardCrewType = 0; // 0 - ����� ����� ������

	int type = pchar.GenQuest.BoardCrewType;
	type++;

	if (type > 33)
		type = 0;

	totalInfo += type + "/33\n\n";

	switch (type)
	{
		case 0:	message = "������� ���������� �����"; iSND = PlaySound("_CheatSurfMenu_\Matrosi.wav"); break;
		// ������
		case 1: message = "���������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 2: message = "���������� ����� (�����)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 3: message = "���������� ����� (�������)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 4: message = "���������� ����� (�������+�����+�������)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 5: message = "���������� ����� (�������+�����+�������+�������)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		case 6: message = "���������� ����� (�������+����� ����, ��� � ���3)";  iSND = PlaySound("_CheatSurfMenu_\Nation_Eng.wav"); break;
		// �������
		case 7: message = "����������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav");break;
		case 8: message = "����������� ����� (�����)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 9: message = "����������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 10: message = "����������� ����� (�������+�����+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 11: message = "����������� ����� (�������+�����+�������+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		case 12: message = "����������� ����� (������������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Fra.wav"); break;
		// �������
		case 13: message = "��������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 14: message = "��������� ����� (�����)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 15: message = message = "��������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 16: message = "��������� ����� (�������+�����+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 17: message = "��������� ����� (�������+�����+�������+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		case 18: message = "����������� �����"; iSND = PlaySound("_CheatSurfMenu_\Nation_Spa.wav"); break;
		// ���������
		case 19: message = "����������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 20: message = "����������� ����� (�����)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 21: message = "����������� ����� (�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 22: message = "����������� ����� (�������+�����+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		case 23: message = "����������� ����� (�������+�����+�������+�������)"; iSND = PlaySound("_CheatSurfMenu_\Nation_Hol.wav"); break;
		// ������
		case 24: message = "����� ������� �����"; iSND = PlaySound("_CheatSurfMenu_\Delo.wav"); break;
		case 25: message = "������ �����"; iSND = PlaySound("_CheatSurfMenu_\Church.wav"); break;
		case 26: message = "��������� �����"; iSND = PlaySound("_CheatSurfMenu_\Nation_Pir.wav"); break;
		case 27: message = "�����"; iSND = PlaySound("_CheatSurfMenu_\poorman.wav"); break;
		case 28: message = "����� ��������"; iSND = PlaySound("_CheatSurfMenu_\Iroquois.wav"); break;
		case 29: message = "��������� � ���������� �����"; iSND = PlaySound("_CheatSurfMenu_\Montesuma.wav"); break;
		case 30: message = "������������ �����"; iSND = PlaySound("_CheatSurfMenu_\US_ready.mp3"); break;
		case 31: message = "��������� �����"; iSND = PlaySound("Types\skel.wav"); break;
		case 32: message = "����� �����"; iSND = PlaySound("_CheatSurfMenu_\DavyJones.wav"); break;
		case 33: message = "��������� � ����� �����"; iSND = PlaySound("_CheatSurfMenu_\DavyJones.wav"); break;
	}
	pchar.GenQuest.BoardCrewType = type;
	Log_info("������� �� ������� �� ������ " + message + "!");
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "������� �� ������� �� ������ " + message + "!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F10", 1);
}
// <--

string descF11 = "��� \ ���� ������� �������� �� ������ � �������������� ��������";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllCannonsShipyardShip"))
	{
		pchar.CSM.AllCannonsShipyardShip = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������� �� ������ ��������� � �������������� ��������!");
		totalInfo += "������� �� ������ ��������� � �������������� ��������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllCannonsShipyardShip");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������� �� ������ ��������� ��� �����.");
		totalInfo += "������� �� ������ ��������� ��� �����.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F11", 1);
}

string descF12 = "��� \ ���� ����� �� ����� ������ �� ������� ��";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoCannonsBoom"))
	{
		pchar.CSM.NoCannonsBoom = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������ �� ������� �� �� ����� �������� ������� �����������!");
		totalInfo += "������ �� ������� �� �� ����� �������� ������� �����������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoCannonsBoom");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������ �� ������� �� ����� ������������ ��� �������� � �� ��������� �� ��� ��������� ��������.");
		totalInfo += "������ �� ������� �� ����� ������������ ��� �������� � �� ��������� �� ��� ��������� ��������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F12", 1);
}

string descF13 = "��� \ ���� ��������� ������� � �������� �� ��������� �������� � ����";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.ShipSituationsOff"))
	{
		pchar.CSM.ShipSituationsOff = true;
		bSeaCanGenerateShipSituation = false;
		pchar.CanGenerateShipSituation = false;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "��������� ������� � �������� �� ��������� �������� � ���� ���������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.ShipSituationsOff");
		bSeaCanGenerateShipSituation = true;
		pchar.CanGenerateShipSituation = true;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "��������� ������� � �������� �� ��������� �������� � ���� ���������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F13", 1);
}

string descF14 = "��� \ ���� ����������� ����������� ������� ����� ����������� ��������";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	string sRefresh = "��������� ������� � ���� ������ ����� ����� ������� �����.";
	if (!CheckAttribute(pchar, "CSM.NoCheckAndIdentifyShips"))
	{
		pchar.CSM.NoCheckAndIdentifyShips = true;
		iSND = PlaySound("_CheatSurfMenu_\Medic.wav");
		Log_info("����� �� ����� ���������� ���� ����������� ������� � ������� �������!");
		totalInfo += "����� �� ����� ���������� ���� ����������� ������� � ������� �������!" + NewStr() + sRefresh;
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoCheckAndIdentifyShips");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("����� �������� ���� ����������� ������� � ����� ������� �������.");
		totalInfo += "����� �������� ���� ����������� ������� � ����� ������� �������." + NewStr() + sRefresh;
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F14", 1);
}

string descF15 = "��� \ ���� ������� �������� �� �� ������� ��� ������������ �������";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NotDeleteShipsInStock"))
	{
		pchar.CSM.NotDeleteShipsInStock = true;
		totalInfo += "���� ������� ������� �� ������� �� ����� ��������� ����� ������������ �������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NotDeleteShipsInStock");
		totalInfo += "���� ������� ������� �� ������� ����� ��������� ��� ������������ �������...";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F15", 1);
}

string descF16 = "������� \ �������� ������� ������ '����������' (������ �� ��� ���������)";
void CalculateInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	CommonActions();
	ref rMS = GetRealShip(sti(pchar.Ship.Type));
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		if (rMS.Stolen == true)
		{
			rMS.Stolen = false;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			totalInfo += "������� ������ �� ����������!";
		}
		else
		{
			rMS.Stolen = true;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "������� ����� ������ '����������'...";
		}
	}
	else
	{
		Log_info("� ��� �� ��� �������, �������?!");
		totalInfo += "� ��� �� ��� �������, �������?!";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F16", 1);
}

string descF17 = "��� \ ���� �������� ���� � ���-�� �������� ��� ������ �� ������ ��������������";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.LSCFreeArrival"))
	{
		pchar.CSM.LSCFreeArrival = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("�� ������ �������������� ����� ���������� �� ����� ������� � ���� ��� ������ �������!");
		totalInfo += "�� ������ �������������� ����� ���������� �� ����� ������� � ���� ��� ������ �������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.LSCFreeArrival");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("�� ������ �������������� ������ ����� �� ������� ������� ��� � ������� �������.");
		totalInfo += "�� ������ �������������� ������ ����� �� ������� ������� ��� � ������� �������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F17", 1);
}

string descF18 = "��� \ ���� ����������� ���������� ������������ �� ����� �������";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.FreeSmuggling"))
	{
		pchar.CSM.FreeSmuggling = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("�������� ��������� �����������!");
		Log_info("�� ������ ����� ���������� �� ����� ������� � ���� ��� ������ �������!");
		totalInfo += "�������� ��������� �����������!" + NewStr() + "�� ������ ����� ���������� �� ����� ������� � ���� ��� ������ �������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FreeSmuggling");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("����������� ���������� �� ���������.");
		totalInfo += "����������� ���������� �� ���������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F18", 1);
}

string descF19 = "�������� �������";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	if (!CheckAttribute(pchar, "GenQuest.Shipshine"))
	{
		pchar.GenQuest.Shipshine = true;
		iSND = PlaySound("Voice\Russian\priest_bead.wav");
		totalInfo += "������� ��� �������! ����� �������� ��� ����� � �������� ����������� �����!";
	}
	else
	{
		DeleteAttribute(Pchar, "GenQuest.Shipshine");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "��������� �������� ���� ����...";
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F19", 1);
}

// by Sticks� -->
string descF20 = "�������� �������� ����������� ���� �������� �� ���������� �����";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
    string message = "�������� ���� ���������� �� ���������� �����: ";

	if (!CheckAttribute(pchar, "CSM.FastTravelMode"))
	{
		pchar.CSM.FastTravelMode = true;
		worldMap.shipSpeedOppositeWind = 3.0;   // ������ �����
		worldMap.shipSpeedOverWind = 3.0;       // �� �����
		message = message + "�����";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FastTravelMode");
		worldMap.shipSpeedOppositeWind = 0.3;   // ��� � ���������
		worldMap.shipSpeedOverWind = 0.8;       // ��� � ���������
		message = message + "����������";
	}
	iSND = PlaySound("Interface\abordage_wining.wav");
	Log_info(message);
	totalInfo += message + NewStr() + "�����: Sticks�";
	if (IsEntity(&worldMap)) { totalInfo += "\n\n����� ��������� �������� � ����, ���������� ����� ����� �������������!"; }
	totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM9.F20", 1);
}
// by Sticks� <--

string descF21 = "��������� \ ��������������� �������� ������� ������� �� ���������� �����";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	string sDef = " (����� 1.5)";
	string sReduced = "�������� ������� ������� �� ���������� ����� ��������� � �����: ";
	string sNext = "��������� �������� ���������� ��������: ";
	string sNormal = "�������� ������� ������� �� ���������� ����� ���������������, ������� ��������: ";
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
	if (IsEntity(&worldMap)) { totalInfo += "\n\n����� ��������� �������� � ����, ���������� ����� ����� �������������!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F21", 1);
}

string descF22 = "��� \ ���� '������ ���������� �����' (����� ��������� ��������)";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	string sLogA = "��� ������� �������, �����, ������� � ����� �� ���������� ����� ���������!";
	string sLogB = "��������� ���������� ����� ��������� � �������� ���������.";
	if (!CheckAttribute(pchar, "CSM.WorldMapEncountersOff"))
	{
		pchar.CSM.WorldMapEncountersOff = true;
		iEncountersRate = 0;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sLogA);
		totalInfo += sLogA + NewStr() + "��������� �������� ��� �� ��������.";
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
	if (IsEntity(&worldMap)) { totalInfo += "\n\n����� ��������� �������� � ����, ���������� ����� ����� �������������!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F22", 1);
}

string descF23 = "��� \ ���� ���������� ������� � ����� �� ���������� �����";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	string sLog = "���������� ������� � ����� �� ���������� ����� ";
	string sLogQ = "��������� �������� ��� �� ��������.";
	if (CheckAttribute(pchar, "worldmapencountersoff") == 0)
	{
		pchar.worldmapencountersoff = "1";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sLog + "���������!");
		totalInfo += sLog + "���������!" + NewStr() + sLogQ;
	}
	else
	{
		if (pchar.worldmapencountersoff == "1")
		{
			pchar.worldmapencountersoff = "0";
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sLog + "��������.");
			totalInfo += sLog + "��������.";
		}
		else
		{
			pchar.worldmapencountersoff = "1";
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sLog + "���������!");
			totalInfo += sLog + "���������!" + NewStr() + sLogQ;
		}
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap) && !CheckAttribute(pchar, "CSM.WorldMapEncountersOff")) { totalInfo += "\n\n����� ��������� �������� � ����, ���������� ����� ����� �������������!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F23", 1);
}

string descF24 = "��������� \ �� ��������� ��������� ��������� �������� �� ���������� �����";
void CalculateInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	CommonActions();
	string sLog = "��������� ��������� ���� �������� �� ���������� ����� ";
	if (!CheckAttribute(pchar, "CSM.MapShipDistView"))
	{
		pchar.CSM.MapShipDistView = true;
		worldMap.enemyshipViewDistMin = 980.0;
		worldMap.enemyshipViewDistMax = 999.0;
		sLog = sLog + "���������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MapShipDistView");
		worldMap.enemyshipViewDistMin = 60.0;
		worldMap.enemyshipViewDistMax = 120.0;
		sLog = sLog + "���������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	Log_info(sLog);
	totalInfo += sLog;
	PlaySound("Interface\sobitie_na_karte_001.wav");
	if (IsEntity(&worldMap)) { totalInfo += "\n\n����� ��������� �������� � ����, ���������� ����� ����� �������������!"; }
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F24", 1);
}

string descF25 = "������ ������� ���� �� ������ �� ���� ��������� ����������";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	bBettaTestMode = true;
	int iC;
	ref rC, rXep;
	rC = GetColonyByIndex(FindColony("Pirates"));
	if (rC != -1) SetPriceListByStoreMan(rC);
/*
	// ������ �� ���� �� ���� ��������� ���
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
	totalInfo += "���������� �� ����� �� ������ �� ���� ��������� ���������� ���������!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F25", 1);
}

string descF26 = "��� \ ���� 100% ���� ��������� � ������� �������� ������ ��������";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.TreasureMapTrader"))
	{
		pchar.CSM.TreasureMapTrader = true;
		totalInfo += "���� ��������� � ������� �������� ������ �������� 100%!" + NewStr() + "���� ��� ���� ���� ��������� �����, �������.";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.TreasureMapTrader");
		totalInfo += "���� ��������� � ������� �������� ������ �������� ��������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F26", 1);
}

string descF27 = "��� \ ���� ����������� ������ ��� ����� ���������� ����� ������� � ��������";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.JungleContinuousMusic"))
	{
		pchar.CSM.JungleContinuousMusic = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������ �� ����� ������������ ��� ����� ���������� ����� ������� � ��������!");
		totalInfo += "������ �� ����� ������������ ��� ����� ���������� ����� ������� � ��������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.JungleContinuousMusic");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������ ����� ������������ ��� ����� ���������� ����� ������� � ��������.");
		totalInfo += "������ ����� ������������ ��� ����� ���������� ����� ������� � ��������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F27", 1);
}

string descF28 = "��� \ ���� ������� ������� �� ��������� ��������";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.FastTravelEnemy"))
	{
		DeleteAttribute(pchar, "CSM.FastTravelEnemy");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("������� ������� �� ��������� ���������� ��������...");
		totalInfo += "������� ������� �� ��������� ���������� ��������...";
	}
	else
	{
		pchar.CSM.FastTravelEnemy = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("�������� ������� ������� �� ���� ��������� ����������!");
		totalInfo += "�������� ������� ������� �� ���� ��������� ����������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F28", 1);
}

string descF29 = "��� \ ���� ��������� �� ��������";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	if (!CheckAttribute(pchar, "GenQuest.HunterLongPause"))
	{
		pchar.GenQuest.HunterLongPause = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("��� ���������!");
		totalInfo += "��� ���������!";
	}
	else
	{
		DeleteAttribute(pchar, "GenQuest.HunterLongPause");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("��� ���������.");
		totalInfo += "��� ���������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F29", 1);
}

string descF30 = "������ ����� ������ � ������ (�� ������� � �.�.)";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	if (CheckAttribute(pchar, "showTimer"))
	{
		DeleteAttribute(pchar, "showTimer");
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������ ��� �����!");
		totalInfo += "������ ��� �����!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("��� �������� ������� - ������� ������...");
		totalInfo += "��� �������� ������� - ������� ������...";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F30", 1);
}

string descF31 = "��� \ ���� � ���������� ��� �������� � �������";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllItemsInTrade"))
	{
		pchar.CSM.AllItemsInTrade = true;
		totalInfo += "� ���������� � ������� ��������� ��� ��������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllItemsInTrade");
		totalInfo += "����������� ������� � ���������� ��������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F31", 1);
}

string descF32 = "��� \ ���� ��� ������� � ������� �� ������";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.AllShipsInTrade"))
	{
		pchar.CSM.AllShipsInTrade = true;
		totalInfo += "� ��������� � ������� ��������� ��� �������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.AllShipsInTrade");
		totalInfo += "����������� �������� � ��������� ��������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F32", 1);
}

string descF33 = "��� \ ���� ����������� �������� �������������� ����� � ��";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff"))
	{
		pchar.CSM.CMStatsOff = true;
		Log_info("����������� �������� �������������� ����� � �� ������.");
		totalInfo += "����������� �������� �������������� ����� � �� ������.";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CMStatsOff");
		Log_info("������� �������������� ����� � �� ���������.");
		totalInfo += "������� �������������� ����� � �� ���������.";
	}
	iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F33", 1);
}

// by Sticks� -->
string descF34 = "�������� ����������� ����� �� ���� (������������ ������ ������� ���)";
void CalculateInfoDataF34()
{
    totalInfo = "#34 " + descF34;
	CommonActions();
	if (!IsEntity(&worldMap))
	{
		// 0Pi ��� 2Pi - ����� �����, 0.5Pi - ��������, Pi - ��������, 1.5Pi - ���������
		Weather.Wind.Angle = stf(Weather.Wind.Angle) + 0.785; // ������ ��� ��������� �������� ��
		if (stf(Weather.Wind.Angle) > 6.28)
			Weather.Wind.Angle = 0;
		pchar.wind.angle = Weather.Wind.Angle;
		fWeatherAngle = stf(Weather.Wind.Angle);

		string windDirection;
		float cut = 0.25; // ��� ����� ������� ��������� � ��������

		if (fWeatherAngle > 5.495 + cut || fWeatherAngle < 0.785 - cut)
		{
			windDirection = "�����";
			SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\0_n.tga");
		}
		else
		{
			if (fWeatherAngle > 0.0 + cut && fWeatherAngle < 1.57 - cut)
			{
				windDirection = "���-��������";
				SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\1_ne.tga");
			}
			else
			{
				if (fWeatherAngle > 0.78 + cut && fWeatherAngle < 2.355 - cut)
				{
					windDirection = "��������";
					SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\2_e.tga");
				}
				else
				{
					if (fWeatherAngle > 1.57 + cut && fWeatherAngle < 3.14 - cut)
					{
						windDirection = "������-��������";
						SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\3_se.tga");
					}
					else
					{
						if (fWeatherAngle > 2.355 + cut && fWeatherAngle < 3.925 - cut)
						{
							windDirection = "��������";
							SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\4_s.tga");
						}
						else
						{
							if (fWeatherAngle > 3.14 + cut && fWeatherAngle < 4.71 - cut)
							{
								windDirection = "������-���������";
								SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\5_sw.tga");
							}
							else
							{
								if (fWeatherAngle > 3.925 + cut && fWeatherAngle < 5.495 - cut)
								{
									windDirection = "���������";
									SetNewPicture("CSMPICTURE", "INTERFACES\_CheatSurfMenu_\Compass\6_w.tga");
								}
								else
								{
									if (fWeatherAngle > 4.71 + cut && fWeatherAngle < 6.28 - cut)
									{
										windDirection = "���-���������";
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
		Log_info("����� ����������� �� " + windDirection + "!");
		totalInfo += "����� ����������� �� " + windDirection + "!" + NewStr() + "�� ������� ����, ������� ������, ������� ����������� �����." + NewStr() + "�����: Sticks�";
	}
    else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("�� ���������� ����� �� ��������...");
		totalInfo += "�� ���������� ����� �� ��������...";
	}
	totalInfo += back2totalInfo;
    SetFormatedText("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
    Statistic_AddValue(PChar, "Cheats.CSM9.F34", 1);
}
// by Sticks� <--

string descF35 = "������� ����� �� ���� (������������ ������ ������� ���)";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	if (!IsEntity(&worldMap))
	{
		Weather.Wind.Speed = 16.0;
		pchar.wind.speed = Weather.Wind.Speed;
		fWeatherSpeed = stf(Weather.Wind.Speed);
		iSND = PlaySound("Interface\abordage_wining.wav");
		Log_info("������ ����� �� ���� ����������: " + stf(fWeatherSpeed));
		totalInfo += "������ ����� �� ���� ����������: " + stf(fWeatherSpeed);
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("�� ���������� ����� �� ��������...");
		totalInfo += "�� ���������� ����� �� ��������...";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F35", 1);
}

string descF36 = "��������� �������� � ������� (������� ����, ���� � �.�., ��������� ����� ������������)";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	PauseParticles(true);
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "�������� � ������� ������� ���������!" + NewStr() + "��� ����� ���������� �� ������ �������." + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F36", 1);
}

string descF37 = "������� ��� �������, ����� � ����, ������� �������� � �.�. (������������ � ������� �������!)";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
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
	Log_info("��� ����������� �����!");
	totalInfo += "��� ����������� �����!" + back2totalInfo;
	iSND = PlaySound("_CheatSurfMenu_\ReputationGood.wav");
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F37", 1);
}

string descF38 = "��� \ ���� �������� ������ ������ ��� ������������ �������";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();

	if (!CheckAttribute(pchar, "CSM.DontClearDead"))
	{
		pchar.CSM.DontClearDead = true;
		totalInfo += "����� ���� ������ ������ �� ����� �������� �� ��������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.DontClearDead");
		totalInfo += "������� �������� ������ ��������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F38", 1);
}

string descF39 = "������� ������ �� ��������� (+1 ���)";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	CSM_LoadNextWeather();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "������ ��������!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F39", 1);
}

string descF40 = "������� ������ �� ���������� (-1 ���)";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	CSM_LoadPrevWeather();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "������ ��������!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F40", 1);
}

string descF41 = "����� �������� ������ ������� � ����������";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	if (sti(pchar.GenQuest.Piratekill) > 0)
	{
		pchar.GenQuest.Piratekill = 0;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("������� ������ ������� � ���������� ������� �� 0!");
		totalInfo += "������� ������ ������� � ���������� ������� �� 0!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("���� ������ ������� � ���������� ����� 0, ���������� ��� �������.");
		totalInfo += "���� ������ ������� � ���������� ����� 0, ���������� ��� �������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F41", 1);
}

string descF42 = "������� ������� ����";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	isGoldFleet = true;
	GoldMonth = XI_ConvertString("target_month_" + GetAddingDataMonth(0, 0, 0));
	AddTemplRumour("Init_GoldFleet", id_counter + 1);
	StartGoldFleet("");
	PlayStereoSound("notebook");
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	Log_info("������� ���� ����� �� ����� ����� (����) � ���� ���� �� ������ (����)!");
	totalInfo += "������� ���� ����� �� ����� ����� (����) � ���� ���� �� ������ (����)!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F42", 1);
}

string descF43 = "������� ������ � �����, ���� ����� ������� ��� �� ����-�� '����������'";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	if (CheckAttribute(pchar, "chr_ai.type") && pchar.chr_ai.type == LAI_TYPE_PLAYER)
	{
		locCameraTarget(pchar);
		locCameraFollow();
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "������ ���������� �� ����� �������� �����!";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "������� ����� �� ��������� ��� ����������� ������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F43", 1);
}

string descF44 = "������ \ ��������� ������� ������ � �������";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	ref rXep;
	string sLogA = "��������� ������� � ���� ��� ����� �����.";
	string sLogB = "������� ������ � ������� ";
	rXep = characterFromId("Tortuga_Mayor");
	if (rXep.name == "�������" && rXep.lastname == "��������")
	{
		if (CheckAttribute(pchar, "questTemp.Sharlie.DelTerGuard"))
		{
			DeleteAttribute(pchar, "questTemp.Sharlie.DelTerGuard");
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sLogB + "���������� �������.");
			Log_info(sLogA);
			totalInfo += sLogB + "���������� �������." + NewStr() + sLogA;
		}
		else
		{
			pchar.questTemp.Sharlie.DelTerGuard = "true";
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sLogB + "������!");
			Log_info(sLogA);
			totalInfo += sLogB + "������!" + NewStr() + sLogA;
		}
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "� ������ ����� ��� ��� ����������!";
		if (!CheckAttribute(pchar, "questTemp.Sharlie.DelTerGuard")) pchar.questTemp.Sharlie.DelTerGuard = "true";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F44", 1);
}

string descF45 = "���������� \ �� ���������� ���� �� �������, ��������� ����� � �������� ��������� �����";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	if (!bExpLogShow || !bPGGLogShow || !bQuestLogShow)
	{
		bExpLogShow = true; bPGGLogShow = true; bQuestLogShow = true;
		totalInfo += "�������� ������� ����� �� �������, ����������� ����� � �������� ��������� ���������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		bExpLogShow = false; bPGGLogShow = false; bQuestLogShow = false;
		totalInfo += "��������� ������� ����� �� �������, ����������� ����� � �������� ��������� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F45", 1);
}

string descF46 = "��� \ ���� �������������� ����";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();

	string message = "������� ���� ������� �� ";
	string sMod = "\n\n����� �������� ��� �������� ���� �� Sergg (��� SkyBox).\n�� '������' �������� ����� ���������� �� ����������.";

	if (!CheckAttribute(pchar, "CSM.WavesType"))
	{
		pchar.CSM.WavesType = -1; // ������ ����, ��������� ������, � ������ ������� �� ���� �����
		SM_WavesEnable();
		message = message + "����������������.\n����� ������������� ���� �����." + sMod;
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
			message = message + "������������.";
		}
		else
		{
			message = message + "����������������.\n����� �� ������� �� ���� �����. ";
			if (type == 0) // ��������� ��� ����� ��� ���������� ���������
				message = message + "�������� ��� ����� �������.";
			else
				message = message + "��� ����� : " + type + ".";
			message += sMod;
		}

	}

	Whr_UpdateWeather();

	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += message + "\n\n�����: Sticks�" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F46", 1);
}

string descF47 = "��� \ ���� ��������� � ���������� ������� ������ � �����";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.TimeScaleEnable"))
	{
		pchar.CSM.TimeScaleEnable = true;
		totalInfo += "��������� � ���������� ������� �������� ������ � �����!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.TimeScaleEnable");
		SetTimeScale(1.0);
		totalInfo += "����������� ��������� � ���������� ������� ���������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F47", 1);
}

string descF48 = "��� \ ���� ������ ��������, �������� � ��������, �������� � �������� � �.�.";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();

	string message = "";

	if (!CheckAttribute(pchar, "CSM.MoreBands"))
	{
		pchar.CSM.MoreBands = true;
		message = message + "���������� ���������� �����������.";
		iSND = PlaySound("Types\warrior02.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MoreBands");
		message = message + "������� ���������� �����������.";
		iSND = PlaySound("Types\warrior_dam02.wav");
	}
	Log_info(message);
	totalInfo += message + NewStr() + "�����: Sticks�" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F48", 1);
}

string descF49 = "��� \ ���� ��������� ������� ������ � �����";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.TimeScaleEnable"))
	{
		pchar.CSM.TimeScaleEnable = true;
		totalInfo += "��������� � ���������� ������� �������� ������ � �����!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.TimeScaleEnable");
		SetTimeScale(1.0);
		totalInfo += "����������� ��������� � ���������� ������� ���������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F49", 1);
}

string descF50 = "��� \ ���� ��������������� ������� � ��������� ��������";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.RelationAgent"))
	{
		pchar.CSM.RelationAgent = true;
		totalInfo += "� ��������� �������� ����� ����������� ��������������� ������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.RelationAgent");
		totalInfo += "��������������� ������ � ��������� �������� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F50", 1);
}

string descF51 = "��� \ ���� �������� ������� ������ � ��������� �������";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.Merchants"))
	{
		pchar.CSM.Merchants = true;
		totalInfo += "� ��������� ��������� ����� ��������� ������ ����!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.Merchants");
		totalInfo += "� ��������� ������� ������ ����� ������� ������ ����.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F51", 1);
}

string descF52 = "��� \ ���� �������������� ����� (3 ��������)";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();

	SM_PusherSwitch();

	if (CheckAttribute(pchar, "CSM.CrowdPusher"))
	{
		switch(sti(pchar.CSM.CrowdPusher))
		{
			case 1: totalInfo += "������ �����: ������"; break;
			case 2: totalInfo += "������ �����: ���������"; break;
			case 3: totalInfo += "������ �����: ���������"; break;
		}
		totalInfo += "\n\n���������� ����� ������������� ��� ����������� ���, �������� ����������� �� (����� � ������)\n����� ������� ������ ������������ ������ � ��������� �����.\n��������� ����������� �������� � �������� �������.";
		totalInfo += "\n\n���������, ��������� � ��������� ������ ��������� (��������, �����, ������ � ��) �� ������������.";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		totalInfo += "�������������� ����� ��������!";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F52", 1);
}

string descF53 = "������������� ��������� �� ����� �������� ������� ��������������";
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
		LAi_group_SetRelation("LSC_NARVAL", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// ����� � ���������
		LAi_group_SetRelation("LSC_RIVADOS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// ����� � �������
		LAi_group_SetRelation("LSC_SHARK", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// ����� � ��������
		LSC_OpenSanAvgustinDoors();//������� ���� � ����������
		LSC_OpenTartarusDoors();//������� ���� � ������
		LocatorReloadEnterDisable("LostShipsCity_town", "reload33", false);// ������� ���� � ����� �������
		LocatorReloadEnterDisable("LostShipsCity_town", "reload48", false);// ������� ���� � ����� ������
		WaitDate("", 0, 0, 0, 0, 5);
		totalInfo += "��� ��������� � ����������� ������� �������������� �������!" + NewStr() + "�����: Krizis";
		iSND = csmSound("Ahha", 0);
	}
	else
	{
		iSND = csmSound("WTF", 0);
		totalInfo += "�� ������ ���������� �� ������� ��������������!";
	}

	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM9.F53", 1);
}

string descF54 = "�������� �����";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
	{
		NullCharacterGoods(pchar);
		RecalculateCargoLoad(pchar);
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("���� ������ ������� ��������� ������, ���!");
		totalInfo += "���� ������ ������� ��������� ������, ���!";
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

string descF55 = "1-�� ����������";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 1-�� ���������� ��������� ������!";
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

string descF56 = "2-�� ����������";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 2-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 2-�� ���������� ��������� ������!";
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

string descF57 = "3-�� ����������";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 3-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 3-�� ���������� ��������� ������!";
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

string descF58 = "4-�� ����������";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 4-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 4-�� ���������� ��������� ������!";
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

string descF59 = "5-�� ����������";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 5-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 5-�� ���������� ��������� ������!";
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


string descF60 = "6-�� ����������";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 6-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 6-�� ���������� ��������� ������!";
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


string descF61 = "7-�� ����������";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	ref sld;
	int icn;
	string sNoCopm = "� ��� ��� 7-�� ����������...";
	string sNoCopms = "� ��� ��� �����������...";
	string sDone = "���� ������� 7-�� ���������� ��������� ������!";
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

string descF62 = "! ����� !";
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

string descF63 = "! ����� !";
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
string descF64 = "! ����� !";
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

string descF65 = "! ����� !";
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


string descF66 = "! ����� !";
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
string descF67 = "! ����� !";
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
string descF68 = "! ����� !";
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

string descF69 = "! ����� !";
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

string descF70 = "! ����� !";
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

// ����� ����� � �������� ���������. ������� ������. �����. ���� � ���������...
void ShowInfoWindow()
{
	return;
	string sHeader = "! ����� !";
	string sNode = GetCurrentNode();

	string sText1, sText2, sText3, sPicture, sGroup, sGroupPicture;
	sPicture = "none";
	sGroup = "none";
	sGroupPicture = "none";

	switch(sNode)
	{
		case "INFO_TEXT":
			sHeader = "�������� ���� '������'";
			sText1 = "����� ����� ���������� �������� ������ ������� ����, �������� �� ������ '������' ������";
		break;
		case "INFO_TEXT2":
			sHeader = "! ����� !";
			sText1 = "! ����� !";
		break;
		case "CSM_TITLE":
			sHeader = "���� '������'";
			sText1 = "���������� ���� '������'";
		break;
		case "B_M1":
			sHeader = "���� '��������'";
			sText1 = "������ ���� '��������'";
		break;
		case "B_M2":
			sHeader = "���� '������'";
			sText1 = "������ ���� '������'";
		break;
		case "B_M3":
			sHeader = "���� '��������'";
			sText1 = "������ ���� '��������'";
		break;
		case "B_M4":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M5":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M6":
			sHeader = "���� '������'";
			sText1 = "������ ���� '������'";
		break;
		case "B_M7":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M8":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
