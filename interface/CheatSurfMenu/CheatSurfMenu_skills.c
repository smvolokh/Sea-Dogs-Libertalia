
/*
	CheatSurfMenu by Cheatsurfer �� 07.01.2018 ��� ��� 1.6.0 (18.12.17)
	������
	�������� �� ���� ��������� �� boal
	18.04.2018
*/

int iSND = 0;

string totalInfo;
string back2totalInfo = "\n\n*** �������� �� ������ '������' ������, ����� ����� ���������� �������� ������ ������� ���� ***";

string sSkillInc = "�� 1 ��������� ������ ";
string sSkillDec = "�� 1 ��������� ������ ";
string sMaxValue = "������ �������� ������������� ��������!";
string sMinValue = "������ �������� ������������ ��������!";
string sCurValue = "������� ��������: ";
string sGlobal = "��� ���������� ��������, � ������ ����������� � �� ���� NPC � ������� ��.";
string sDefault = "����� ��� ������� ��������� ����: ";

void InitInterface(string iniName)
{
 	StartAboveForm(true);
	GameInterface.title = "CSM_title_skills";
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CalculateInfoData();
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(1); // Warship. ���������� - ������� ����� �����
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
					"<  1 > " + descF1 + NewStr() + "<  2 > " + descF2 + NewStr() + "<  3 > " + descF3 + NewStr() +
					"<  4 > " + descF4 + NewStr() + "<  5 > " + descF5 + NewStr() + "<  6 > " + descF6 + NewStr() +
					"<  7 > " + descF7 + NewStr() + "<  8 > " + descF8 + NewStr() + "<  9 > " + descF9 + NewStr() +
					"< 10 > " + descF10 + NewStr() + "< 11 > " + descF11 + NewStr() + "< 12 > " + descF12 + NewStr() +
					"< 13 > " + descF13 + NewStr() + "< 14 > " + descF14 + NewStr() + "< 15 > " + descF15 + NewStr() +
					"< 16 > " + descF16 + NewStr() + "< 17 > " + descF17 + NewStr() + "< 18 > " + descF18 + NewStr() +
					"< 19 > " + descF19 + NewStr() + "< 20 > " + descF20 + NewStr() + "< 21 > " + descF21 + NewStr() +
					"< 22 > " + descF22 + NewStr() + "< 23 > " + descF23 + NewStr() + "< 24 > " + descF24 + NewStr() +
					"< 25 > " + descF25 + NewStr() + "< 26 > " + descF26 + NewStr() + "< 27 > " + descF27 + NewStr() +
					"< 28 > " + descF28 + NewStr() + "< 29 > " + descF29 + NewStr() +
					"\n\n********** ������ ������ **********" + NewStr() +
					"< 30 > " + descF30 + NewStr() + "< 31 > " + descF31 + NewStr() +
					"< 32 > " + descF32 + NewStr() + "< 33 > " + descF33 + NewStr() + "< 34 > " + descF34 + NewStr() +
					"< 35 > " + descF35 + NewStr() + "< 36 > " + descF36 + NewStr() + "< 37 > " + descF37 + NewStr() +
					"< 38 > " + descF38 + NewStr() + "< 39 > " + descF39 + NewStr() + "< 40 > " + descF40 + NewStr() +
					"< 41 > " + descF41 + NewStr() + "< 42 > " + descF42 + NewStr() + "< 43 > " + descF43 + NewStr() +
					"\n\n********** ����������� ������ **********" + NewStr() +
					"< 44 > " + descF44 + NewStr() + "< 45 > " + descF45 + NewStr() +
					"< 46 > " + descF46 + NewStr() + "< 47 > " + descF47 + NewStr() + "< 48 > " + descF48 + NewStr() +
					"< 49 > " + descF49 + NewStr() + "< 50 > " + descF50 + NewStr() + "< 51 > " + descF51 + NewStr() +
					"< 52 > " + descF52 + NewStr() + "< 53 > " + descF53 + NewStr() + "< 54 > " + descF54 + NewStr() +
					"< 55 > " + descF55 + NewStr() + "< 56 > " + descF56 + NewStr() + "< 57 > " + descF57 + NewStr() +
					"\n\n********** ������ **********" + NewStr() +
					"< 58 > " + descF58 + NewStr() + "< 59 > " + descF59 + NewStr() + "< 60 > " + descF60 + NewStr() + "< 61 > " + descF61 + NewStr() +
					"< 62 > " + descF62 + NewStr() + "< 63 > " + descF63 + NewStr() + "< 64 > " + descF64 + NewStr() +
					"< 65 > " + descF65 + NewStr() + "< 66 > " + descF66 + NewStr() + "< 67 > " + descF67 + NewStr() +
					"< 68 > " + descF68 + NewStr() + "< 69 > " + descF69 + NewStr() + "< 70 > " + descF70;
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
	if (!CheckAttribute(pchar, "CSM.CMStatsOff")) csmCheatsInfo(1); // ���������� �� �����
}

string descF1 = "��������� ���� ����� � ������� ��� \ �� ���������";
void CalculateInfoDataF1()
{
	totalInfo = "#1 " + descF1;
	CommonActions();
	string sDmgC = "��������� ������ ���� �������� � ������������� ������� �������� � ";
	string sDmgN = "��������� ���: ���������� ����� � ";
	if (!CheckAttribute(pchar, "MultiFighter")) pchar.MultiFighter = 1.0;
	if (!CheckAttribute(pchar, "MultiShooter")) pchar.MultiShooter = 1.0;
	switch (stf(pchar.MultiFighter))
	{
		case 1.0:
			pchar.MultiFighter = 2.0;
			pchar.MultiShooter = 2.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "2 ����!");
			totalInfo += sDmgC + "2 ����!" + NewStr() + sDmgN + "3 ����.";
		break;
		case 2.0:
			pchar.MultiFighter = 3.0;
			pchar.MultiShooter = 3.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "3 ����!");
			totalInfo += sDmgC + "3 ����!" + NewStr() + sDmgN + "4 ����.";
		break;
		case 3.0:
			pchar.MultiFighter = 4.0;
			pchar.MultiShooter = 4.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "4 ����!");
			totalInfo += sDmgC + "4 ����!" + NewStr() + sDmgN + "5 ���.";
		break;
		case 4.0:
			pchar.MultiFighter = 5.0;
			pchar.MultiShooter = 5.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "5 ���!");
			totalInfo += sDmgC + "5 ���!" + NewStr() + sDmgN + "10 ���.";
		break;
		case 5.0:
			pchar.MultiFighter = 10.0;
			pchar.MultiShooter = 10.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "10 ���!");
			totalInfo += sDmgC + "10 ���!" + NewStr() + sDmgN + "100 ���.";
		break;
		case 10.0:
			pchar.MultiFighter = 100.0;
			pchar.MultiShooter = 100.0;
			iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
			Log_info(sDmgC + "100 ���!");
			totalInfo += sDmgC + "100 ���!" + NewStr() + "��������� ���: ���� �� ���������.";
		break;
		case 100.0:
			pchar.MultiFighter = 1.0;
			pchar.MultiShooter = 1.0;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info("��������� ������ ���� ��������� �� ���������.");
			totalInfo += "��������� ������ ���� ��������� �� ���������." + NewStr() + sDmgN + "2 ����.";
		break;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F1", 1);
}

string descF2 = "����� �� � ��� ������ ������ ��������� ���� ���������� \ �� ���������";
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
		totalInfo += "����� �� � ��� ������ �� ����������� �����������!";
	}
	else
	{
		DeleteAttribute(pchar, "animal");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "���� �� �������� ����� ���������� � �� � ��� ������ ��������� �� ���������.";
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

string descF3 = "������� \ ������ ��� ����� (����� �������)";
void CalculateInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.DeletePerks"))
	{
		DeleteAttribute(pchar, "CSM.DeletePerks");
		SelAllPerksToChar(pchar, false);
		iSND = PlaySound("_CheatSurfMenu_\Master.wav");
		Log_info("��� ����� �������!");
		totalInfo += "��� ����� �������!" + NewStr();
	}
	else
	{
		pchar.CSM.DeletePerks = true;
		DeleteAttribute(pchar, "perks.list");
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("��� ����� ��������...");
		totalInfo += "��� ����� ��������..." + NewStr();
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

string descF4 = "�������� �� 1 ���������� ����� � ������ � ����������� �����������";
void CalculateInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	CommonActions();
	bool bSnd = false;
	if (sti(PChar.Perks.FreePoints_Self) < 19)
	{
		PChar.Perks.FreePoints_Self = sti(PChar.Perks.FreePoints_Self) + 1;
		bSnd = true;
		Log_info("������� 1 ��������� ������ ����!");
		totalInfo += "������� 1 ��������� ������ ����!" + NewStr() + "������ ������: " + sti(PChar.Perks.FreePoints_Self);
	}
	else
	{
		Log_info("���������� ������������ ����� ��������� ������ ������!");
		totalInfo += "���������� ������������ ����� ��������� ������ ������!" + NewStr() + "������ ������: " + sti(PChar.Perks.FreePoints_Self);
	}
	totalInfo += "\n\n";
	if (sti(PChar.Perks.FreePoints_Ship) < 38)
	{
		PChar.Perks.FreePoints_Ship = sti(PChar.Perks.FreePoints_Ship) + 1;
		bSnd = true;
		Log_info("������� 1 ��������� ����������� ����!");
		totalInfo += "������� 1 ��������� ����������� ����!" + NewStr() + "����������� ������: " + sti(PChar.Perks.FreePoints_Ship);
	}
	else
	{
		Log_info("���������� ������������ ����� ��������� ����������� ������!");
		totalInfo += "���������� ������������ ����� ��������� ����������� ������!" + NewStr() + "����������� ������: " + sti(PChar.Perks.FreePoints_Ship);
	}
	if (bSnd) iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	else iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F4", 1);
}

string descF5 = "�������� ��� ��������� ���� ������";
void CalculateInfoDataF5()
{
	totalInfo = "#5 " + descF5;
	CommonActions();
	if (sti(PChar.Perks.FreePoints_Self) > 0 || sti(PChar.Perks.FreePoints_Ship) > 0)
	{
		PChar.Perks.FreePoints_Self = 0;
		PChar.Perks.FreePoints_Ship = 0;
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		Log_info("��������� ���� ������ � ����������� ������ �������...");
		totalInfo += "��������� ���� ������ � ����������� ������ �������...";
	}
	else
	{
		iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		Log_info("��� ��������� ����� ������.");
		totalInfo += "��� ��������� ����� ������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F5", 1);
}

string descF6 = "��� ������ ������ �� 10";
void CalculateInfoDataF6()
{
	totalInfo = "#6 " + descF6;
	CommonActions();
	SetRandSelfSkill(pchar, 10, 10);
	iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	Log_info("��� ���������� ������ ������ ���������� �� 10!");
	totalInfo += "��� ���������� ������ ������ ���������� �� 10!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F6", 1);
}

string descF7 = "��� ������ ������ �� 100";
void CalculateInfoDataF7()
{
	totalInfo = "#7 " + descF7;
	CommonActions();
	SetRandSelfSkill(pchar, 100, 100);
	iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	Log_info("��� ���������� ������ ������ ���������� �� 100!");
	totalInfo += "��� ���������� ������ ������ ���������� �� 100!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F7", 1);
}

string descF8 = "��� ����������� ������ �� 10";
void CalculateInfoDataF8()
{
	totalInfo = "#8 " + descF8;
	CommonActions();
	SetRandShipSkill(pchar, 10, 10);
	iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
	Log_info("��� ���������� ����������� ������ ���������� �� 10!");
	totalInfo += "��� ���������� ����������� ������ ���������� �� 10!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F8", 1);
}

string descF9 = "��� ����������� ������ �� 100";
void CalculateInfoDataF9()
{
	totalInfo = "#9 " + descF9;
	CommonActions();
	SetRandShipSkill(pchar, 100, 100);
	iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
	Log_info("��� ���������� ����������� ������ ���������� �� 100!");
	totalInfo += "��� ���������� ����������� ������ ���������� �� 100!" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F9", 1);
}

string descF10 = "������������ ������ �� ������� \ ������� ��������� ���� ������";
void CalculateInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	CommonActions();
	if (sti(pchar.Skill.FreeSkill) < 1)
	{
		pchar.Skill.FreeSkill = 99;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "��������� 99 ��������� ����� ������!" + NewStr() + "\n\n�������� ��� ����, ������� F2, �������� ������� '���������' � ��������� ������ �� �������." + NewStr() + "��������� ������������� ���� ������� ������ ��� ��������� ���� ������ ��.";
	}
	else
	{
		pchar.Skill.FreeSkill = 0;
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		totalInfo += "��� ��������� ���� ������ ���� �������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F10", 1);
}

string descF11 = "P.I.R.A.T.E.S. �� �� 10 \ �� ���������";
void CalculateInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	CommonActions();
	string sHT = "������� ��� �����: ";
	string sDef = "�������� P.I.R.A.T.E.S. ����������� �� ���������!";
	if (!CheckAttribute(pchar, "CSM.SPECIALmaxValue"))
	{
		pchar.CSM.SPECIALmaxValue = true;
		SetSPECIAL(pchar, 10, 10, 10, 10, 10, 10, 10);
		iSND = PlaySound("_CheatSurfMenu_\IamLegend.wav");
		Log_info("��� �������� P.I.R.A.T.E.S. ����� 10!");
		totalInfo += "��� �������� P.I.R.A.T.E.S. ����� 10!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SPECIALmaxValue");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sDef);
		if (pchar.HeroParam.HeroType == "HeroType_1")
		{
			SetSPECIAL(pchar, 5, 6, 6, 5, 7, 7, 6);
			Log_info(sHT + "���������� � ��������� ����������.");
			totalInfo += sHT + "���������� � ��������� ����������." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_2")
		{
			SetSPECIAL(pchar, 7, 4, 7, 6, 6, 7, 5);
			Log_info(sHT + "����� ������������ � ��������.");
			totalInfo += sHT + "����� ������������ � ��������." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_3")
		{
			SetSPECIAL(pchar, 10, 3, 8, 5, 4, 8, 4);
			Log_info(sHT + "�������� � ������ ��� �� �����.");
			totalInfo += sHT + "�������� � ������ ��� �� �����." + NewStr() + sDef;
		}
		if (pchar.HeroParam.HeroType == "HeroType_4")
		{
			SetSPECIAL(pchar, 4, 9, 6, 4, 5, 5, 9);
			Log_info(sHT + "��������� � ���������� ����.");
			totalInfo += sHT + "��������� � ���������� ����." + NewStr() + sDef;
		}
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F11", 1);
}

string descF12 = "��������� P.I.R.A.T.E.S. ������� ����� \ �� ����� ������ �� ������� ���������� ������";
void CalculateInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.SPECIALsimpleValue"))
	{
		pchar.CSM.SPECIALsimpleValue = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info("��������� �������� P.I.R.A.T.E.S. ������� �� ����� ������ �� ������� ���������� ������!");
		totalInfo += "��������� �������� P.I.R.A.T.E.S. ������� �� ����� ������ �� ������� ���������� ������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SPECIALsimpleValue");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("��������� �������� P.I.R.A.T.E.S. ������� ����� ������ ������� ���������� ������.");
		totalInfo += "��������� �������� P.I.R.A.T.E.S. ������� ����� ������ ������� ���������� ������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F12", 1);
}

string descF13 = "�������� \ ��������� ���������� ������� � ������ � P.I.R.A.T.E.S. �� ������ ��� �������";
void CalculateInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.CuirassNoPenalty"))
	{
		pchar.CSM.CuirassNoPenalty = true;
		totalInfo += "�������� � P.I.R.A.T.E.S. � ������� �� ����� ����������� �� ������� ������ ��� �������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.CuirassNoPenalty");
		totalInfo += "�������� �� ������� ������ ��� ������� ����� ����������� � P.I.R.A.T.E.S. � �������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F13", 1);
}

string descF14 = "��������� ����� ������� �� �� 999 \ �� ���������";
void CalculateInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.EnergyBonus"))
	{
		pchar.CSM.EnergyBonus = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "������������ ����� ������� ����� 999 ��������!";
	}
	else
	{
		DeleteAttribute(pchar, "CSM.EnergyBonus");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "����� ������� ��������� �� ���������.";
	}	
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F14", 1);
}

string descF15 = "�������� \ ��������� ������ ������� � ��� ��� �� � ������������";
void CalculateInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoEnergyDrain"))
	{
		pchar.CSM.NoEnergyDrain = true;
		totalInfo += "������� �� � ������������ �� ����� ������������� � ���!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoEnergyDrain");
		totalInfo += "������� �� � ������������ ����� ������������� � ���.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F15", 1);
}

string descF16 = "�������� \ ��������� ��� � ���������� ������� (��������� ������� ���, ���� �� ��������)";
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
			totalInfo += "��� � ���������� ������� ��������!\n";
		}
		else
		{
			DeleteAttribute(pchar, "CSM.FreeRun");
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			totalInfo += "��� � ���������� ������� ��������.\n";
		}
		bSnd = false;
	}
	if (CheckAttribute(pchar, "GenQuest.CantRun"))
	{
		DeleteAttribute(pchar, "GenQuest.CantRun");
		if (bSnd) iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "������� ��� ��������!";
	}
	else
	{
		if (bSnd) iSND = PlaySound("_CheatSurfMenu_\WTF.wav");
		totalInfo += "������� ��� �� ��������.";
	}
	CheckAndSetOverloadMode(GetMainCharacter());
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F16", 1);
}

string descF17 = "�������� \ ��������� ����������� �������� ��� ����������� ������ ������� ��� �����";
void CalculateInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.KillEmAll"))
	{
		DeleteAttribute(pchar, "CSM.KillEmAll");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		totalInfo += "������� ������� ��������.";
	}
	else
	{
		pchar.CSM.KillEmAll = true;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		totalInfo += "������� ������� �������!\n\n�������������: � ���� ������ 'Enter', ������� ������ ����������� ����� � ������� ���� ��������.";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F17", 1);
}

string descF18 = "�������� \ ��������� �������� �� ����� ��� ����� � ����� ���������";
void CalculateInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.FreeSailing") || !CheckAttribute(pchar, "CSM.SailToEffectRadius"))
	{
		pchar.CSM.FreeSailing = true;
		pchar.CSM.SailToEffectRadius = true;
		totalInfo += "�������� ����������� ������� �� ����� ��� ����� � ����� ���������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.FreeSailing");
		DeleteAttribute(pchar, "CSM.SailToEffectRadius");
		totalInfo += "��������� ����������� ������� �� ����� ��� ����� � ����� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F18", 1);
}

string descF19 = "�������� \ ��������� ����������� 100% ���������� ��� �� ���������� �����";
void CalculateInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.SkipShips"))
	{
		pchar.CSM.SkipShips = true;
		// ������� ���: ���� ����� ��������� �������� ����� ������� � ����, ��� ���������� ����� ������.
		totalInfo += "�������� 100% ����������� ���������� ��� � ������ ��������� �� ���������� �����!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.SkipShips");
		totalInfo += "��������� 100% ����������� ���������� ��� � ������ ��������� �� ���������� �����.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F19", 1);
}

string descF20 = "�������� \ ��������� ������������ ����������� ������ �� ������� ��";
void CalculateInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.MachineGunCannons"))
	{
		pchar.CSM.MachineGunCannons = true;
		totalInfo += "�������� ������������ ����������� ������ �� ������� ��!";
		iSND = PlaySound("_CheatSurfMenu_\SeaDogs.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.MachineGunCannons");
		totalInfo += "��������� ������������ ����������� ������ �� ������� ��.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F20", 1);
}

string descF21 = "�������� \ ��������� ���������� ���������� ������� ��";
void CalculateInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.BoardingCrewGodMode"))
	{
		DeleteAttribute(pchar, "CSM.BoardingCrewGodMode");
		Log_info("���������� ���������� ������� �� ���������.");
		totalInfo += "���������� ���������� ������� �� ���������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	else
	{
		pchar.CSM.BoardingCrewGodMode = true;
		Log_info("�������� ���������� ���������� ������� ��!");
		totalInfo += "�������� ���������� ���������� ������� ��!" + NewStr() + "�������� �����, ��� � ��� ��������� ������� ��: �������, ��� � ������ �����, ������ ������ � ���� � �.�.";
		iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F21", 1);
}

string descF22 = "�������� ������� �������� (������� ����: ������ �������, ������ ���������, �� ���������)";
void CalculateInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.BoardingProcess")) { pchar.CSM.BoardingProcess = 0; }
	if (sti(pchar.CSM.BoardingProcess) < 0) { pchar.CSM.BoardingProcess = 0; }
	if (sti(pchar.CSM.BoardingProcess) > 2) { pchar.CSM.BoardingProcess = 2; }
	string sNext = "��������� �������: ";
	string sLog = "�������� ��������� �������� ������ ����� ";
	string sDef = "���� ����� � ���� ��������� ��������� ��������� �� ���������.";
	TestRansackCaptain = false;
	switch (sti(pchar.CSM.BoardingProcess))
	{
		case 0:
			pchar.CSM.BoardingProcess = 1;
			TestRansackCaptain = true;
			iSND = PlaySound("_CheatSurfMenu_\IamLegend.wav");
			Log_info(sLog + "��������� � ����!");
			totalInfo += sLog + "��������� � ����!" + NewStr() + sNext + "������ ���������";
		break;
		case 1:
			pchar.CSM.BoardingProcess = 2;
			iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
			Log_info(sLog + "���������!");
			totalInfo += sLog + "���������!" + NewStr() + sNext + "�� ���������";
		break;
		case 2:
			pchar.CSM.BoardingProcess = 0;
			iSND = PlaySound("_CheatSurfMenu_\Default.wav");
			Log_info(sDef);
			totalInfo += sDef + NewStr() + sNext + "������ �������";
		break;
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F22", 1);
}

string descF23 = "������� �� ���� � �� ���� ���, �� ������� ��� ���� \ �� ���������";
void CalculateInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	CommonActions();
	if (bNoEatNoRats)
	{
		bNoEatNoRats = false;
		totalInfo += "������� ����� ���� � ���� ���, � �� ������� ����� �������� �����.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	else
	{
		bNoEatNoRats = true;
		totalInfo += "������� �������� �������� � �� ������� ���, ��� ����� ��������!";
		iSND = PlaySound("_CheatSurfMenu_\CrewMorale.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F23", 1);
}

string descF24 = "������� � ������� �� �������� \ �� �������� ���� � ������";
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
		totalInfo += "������� � ������� �� ����� �������� ����������� � �������.";
	}
	else
	{
		pchar.DontHitInStorm = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		totalInfo += "������� � ������� �� �� ����� �������� ����������� � �������!";
	}
	// ����������
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

string descF25 = "��������� ����������� �������� ������ ����� (����� �����)";
void CalculateInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	CommonActions();
	int exprate = 0;
	string sResult = "����������� �������� ������ ����� ��������!";
	string sValue = "����������� �������� ������ ����� ������ ������������� ������!";
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate = 105;
	if (MOD_SKILL_ENEMY_RATE < 10) exprate = 75;
	if (MOD_SKILL_ENEMY_RATE < 8) exprate = 50;
	if (MOD_SKILL_ENEMY_RATE < 6) exprate = 30;
	if (MOD_SKILL_ENEMY_RATE < 3) exprate = 15;
	if (MOD_EXP_RATE < 150)
	{
		MOD_EXP_RATE += 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sResult);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += "\n\n" + sResult + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + "��� ���� ��� ��������, ��� ������ �������� ������." + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate);
	}
	else
	{
		if(MOD_EXP_RATE > 150) MOD_EXP_RATE = 150;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sValue);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += sValue + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate);
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F25", 1);
}

string descF26 = "��������� ����������� �������� ������ ����� (����� �����)";
void CalculateInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	CommonActions();
	int exprate = 0;
	string sResult = "����������� �������� ������ ����� ��������!";
	string sValue = "����������� �������� ������ ����� ������ ������������ ������!";
	if (MOD_SKILL_ENEMY_RATE >= 10) exprate = 105;
	if (MOD_SKILL_ENEMY_RATE < 10) exprate = 75;
	if (MOD_SKILL_ENEMY_RATE < 8) exprate = 50;
	if (MOD_SKILL_ENEMY_RATE < 6) exprate = 30;
	if (MOD_SKILL_ENEMY_RATE < 3) exprate = 15;
	if (MOD_EXP_RATE > 10)
	{
		MOD_EXP_RATE -= 1;
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
		Log_info(sResult);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += "\n\n" + sResult + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + "��� ���� ��� ��������, ��� ������� �������� ������." + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate);
	}
	else
	{
		if(MOD_EXP_RATE < 10) MOD_EXP_RATE = 10;
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info(sValue);
		Log_info(sCurValue + MOD_EXP_RATE);
		totalInfo += sValue + NewStr() + sCurValue + MOD_EXP_RATE + NewStr() + sGlobal + NewStr() + sDefault + sti(exprate);
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F26", 1);
}

string descF27 = "��� ���������� �������� ��������� \ �� ��������� ���������";
void CalculateInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	CommonActions();
	if (CheckAttribute(pchar, "NoNavyPenalty"))
	{
		DeleteAttribute(pchar, "NoNavyPenalty");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("��������� ����� ����������� ��� ���������� ��������.");
		totalInfo += "��������� ����� ����������� ��� ���������� ��������.";
	}
	else
	{
		pchar.NoNavyPenalty = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		Log_info("��������� �� ����������� ��� ���������� ��������!");
		totalInfo += "��������� �� ����������� ��� ���������� ��������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F27", 1);
}

string descF28 = "�������� \ ��������� ���������� ������������� HP ������� ��� ����������� �������";
void CalculateInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	CommonActions();
	if (CheckAttribute(pchar, "CSM.NoShipHullPenalty"))
	{
		DeleteAttribute(pchar, "CSM.NoShipHullPenalty");
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
		Log_info("���������� ������������� HP ������� ��� ����������� ������� ��������.");
		totalInfo += "���������� ������������� HP ������� ��� ����������� ������� ��������.";
	}
	else
	{
		pchar.CSM.NoShipHullPenalty = true;
		iSND = PlaySound("_CheatSurfMenu_\CrewExp.wav");
		Log_info("��������� ���������� ������������� HP ������� ��� ����������� �������!");
		totalInfo += "��������� ���������� ������������� HP ������� ��� ����������� �������!";
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F28", 1);
}

string descF29 = "�������� \ ��������� ����������� ����� �� ������� ��";
void CalculateInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	CommonActions();
	if (!CheckAttribute(pchar, "CSM.NoShipMutinies"))
	{
		pchar.CSM.NoShipMutinies = true;
		totalInfo += "������� � ���� �� ������ ���������!";
		iSND = PlaySound("_CheatSurfMenu_\Ahha.wav");
	}
	else
	{
		DeleteAttribute(pchar, "CSM.NoShipMutinies");
		totalInfo += "������� � ���� ����� �������� ���� �� �������.";
		iSND = PlaySound("_CheatSurfMenu_\Default.wav");
	}
	totalInfo += back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F29", 1);
}

string descF30 = "������� +1";
void CalculateInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	CommonActions();
	if (sti(pchar.skill.Leadership) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Leadership = sti(pchar.skill.Leadership) + 1;
		Log_info(sSkillInc + "�������!");
		totalInfo += sSkillInc + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Leadership);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F30", 1);
}

string descF31 = "������� -1";
void CalculateInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	CommonActions();
	if (sti(pchar.skill.Leadership) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Leadership = sti(pchar.skill.Leadership) - 1;
		Log_info(sSkillDec + "�������!");
		totalInfo += sSkillDec + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Leadership);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F31", 1);
}

string descF32 = "������ \ ����� +1";
void CalculateInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	CommonActions();
	if (sti(pchar.skill.FencingL) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingL = sti(pchar.skill.FencingL) + 1;
		Log_info(sSkillInc + "������ \ �����!");
		totalInfo += sSkillInc + "������ \ �����!" + NewStr() + sCurValue + sti(pchar.skill.FencingL);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F32", 1);
}

string descF33 = "������ \ ����� -1";
void CalculateInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	CommonActions();
	if (sti(pchar.skill.FencingL) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingL = sti(pchar.skill.FencingL) - 1;
		Log_info(sSkillDec + "������ \ �����!");
		totalInfo += sSkillDec + "������ \ �����!" + NewStr() + sCurValue + sti(pchar.skill.FencingL);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F33", 1);
}

string descF34 = "����� \ ������ +1";
void CalculateInfoDataF34()
{
	totalInfo = "#34 " + descF34;
	CommonActions();
	if (sti(pchar.skill.FencingS) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingS = sti(pchar.skill.FencingS) + 1;
		Log_info(sSkillInc + "����� \ ������!");
		totalInfo += sSkillInc + "����� \ ������!" + NewStr() + sCurValue + sti(pchar.skill.FencingS);
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

string descF35 = "����� \ ������ -1";
void CalculateInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	CommonActions();
	if (sti(pchar.skill.FencingS) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingS = sti(pchar.skill.FencingS) - 1;
		Log_info(sSkillDec + "����� \ ������!");
		totalInfo += sSkillDec + "����� \ ������!" + NewStr() + sCurValue + sti(pchar.skill.FencingS);
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

string descF36 = "������ \ ������ +1";
void CalculateInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	CommonActions();
	if (sti(pchar.skill.FencingH) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.FencingH = sti(pchar.skill.FencingH) + 1;
		Log_info(sSkillInc + "������ \ ������!");
		totalInfo += sSkillInc + "������ \ ������!" + NewStr() + sCurValue + sti(pchar.skill.FencingH);
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

string descF37 = "������ \ ������ -1";
void CalculateInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	CommonActions();
	if (sti(pchar.skill.FencingH) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.FencingH = sti(pchar.skill.FencingH) - 1;
		Log_info(sSkillDec + "������ \ ������!");
		totalInfo += sSkillDec + "������ \ ������!" + NewStr() + sCurValue + sti(pchar.skill.FencingH);
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

string descF38 = "������� \ ������� +1";
void CalculateInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	CommonActions();
	if (sti(pchar.skill.Pistol) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Pistol = sti(pchar.skill.Pistol) + 1;
		Log_info(sSkillInc + "������� \ �������!");
		totalInfo += sSkillInc + "������� \ �������!" + NewStr() + sCurValue + sti(pchar.skill.Pistol);
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

string descF39 = "������� \ ������� -1";
void CalculateInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	CommonActions();
	if (sti(pchar.skill.Pistol) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Pistol = sti(pchar.skill.Pistol) - 1;
		Log_info(sSkillDec + "������� \ �������!");
		totalInfo += sSkillDec + "������� \ �������!" + NewStr() + sCurValue + sti(pchar.skill.Pistol);
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

string descF40 = "������� +1";
void CalculateInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	CommonActions();
	if (sti(pchar.skill.Fortune) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Fortune = sti(pchar.skill.Fortune) + 1;
		Log_info(sSkillInc + "�������!");
		totalInfo += sSkillInc + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Fortune);
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

string descF41 = "������� -1";
void CalculateInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	CommonActions();
	if (sti(pchar.skill.Fortune) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Fortune = sti(pchar.skill.Fortune) - 1;
		Log_info(sSkillDec + "�������!");
		totalInfo += sSkillDec + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Fortune);
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

string descF42 = "���������� +1";
void CalculateInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	CommonActions();
	if (sti(pchar.skill.Sneak) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Sneak = sti(pchar.skill.Sneak) + 1;
		Log_info(sSkillInc + "����������!");
		totalInfo += sSkillInc + "����������!" + NewStr() + sCurValue + sti(pchar.skill.Sneak);
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

string descF43 = "���������� -1";
void CalculateInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	CommonActions();
	if (sti(pchar.skill.Sneak) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Sneak = sti(pchar.skill.Sneak) - 1;
		Log_info(sSkillDec + "����������!");
		totalInfo += sSkillDec + "����������!" + NewStr() + sCurValue + sti(pchar.skill.Sneak);
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

string descF44 = "��������� +1";
void CalculateInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	CommonActions();
	if (sti(pchar.skill.Sailing) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Sailing = sti(pchar.skill.Sailing) + 1;
		Log_info(sSkillInc + "���������!");
		totalInfo += sSkillInc + "���������!" + NewStr() + sCurValue + sti(pchar.skill.Sailing);
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

string descF45 = "��������� -1";
void CalculateInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	CommonActions();
	if (sti(pchar.skill.Sailing) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Sailing = sti(pchar.skill.Sailing) - 1;
		Log_info(sSkillDec + "���������!");
		totalInfo += sSkillDec + "���������!" + NewStr() + sCurValue + sti(pchar.skill.Sailing);
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

string descF46 = "�������� +1";
void CalculateInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	CommonActions();
	if (sti(pchar.skill.Accuracy) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Accuracy = sti(pchar.skill.Accuracy) + 1;
		Log_info(sSkillInc + "��������!");
		totalInfo += sSkillInc + "��������!" + NewStr() + sCurValue + sti(pchar.skill.Accuracy);
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

string descF47 = "�������� -1";
void CalculateInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	CommonActions();
	if (sti(pchar.skill.Accuracy) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Accuracy = sti(pchar.skill.Accuracy) - 1;
		Log_info(sSkillDec + "��������!");
		totalInfo += sSkillDec + "��������!" + NewStr() + sCurValue + sti(pchar.skill.Accuracy);
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

string descF48 = "������ +1";
void CalculateInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	CommonActions();
	if (sti(pchar.skill.Cannons) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Cannons = sti(pchar.skill.Cannons) + 1;
		Log_info(sSkillInc + "������!");
		totalInfo += sSkillInc + "������!" + NewStr() + sCurValue + sti(pchar.skill.Cannons);
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

string descF49 = "������ -1";
void CalculateInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	CommonActions();
	if (sti(pchar.skill.Cannons) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Cannons = sti(pchar.skill.Cannons) - 1;
		Log_info(sSkillDec + "������!");
		totalInfo += sSkillDec + "������!" + NewStr() + sCurValue + sti(pchar.skill.Cannons);
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
	Statistic_AddValue(PChar, "Cheats.CSM2.F49", 1);
}

string descF50 = "������� +1";
void CalculateInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	CommonActions();
	if (sti(pchar.skill.Grappling) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Grappling = sti(pchar.skill.Grappling) + 1;
		Log_info(sSkillInc + "�������!");
		totalInfo += sSkillInc + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Grappling);
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

string descF51 = "������� -1";
void CalculateInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	CommonActions();
	if (sti(pchar.skill.Grappling) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Grappling = sti(pchar.skill.Grappling) - 1;
		Log_info(sSkillDec + "�������!");
		totalInfo += sSkillDec + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Grappling);
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

string descF52 = "������ +1";
void CalculateInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	CommonActions();
	if (sti(pchar.skill.Defence) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Defence = sti(pchar.skill.Defence) + 1;
		Log_info(sSkillInc + "������!");
		totalInfo += sSkillInc + "������!" + NewStr() + sCurValue + sti(pchar.skill.Defence);
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

string descF53 = "������ -1";
void CalculateInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	CommonActions();
	if (sti(pchar.skill.Defence) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Defence = sti(pchar.skill.Defence) - 1;
		Log_info(sSkillDec + "������!");
		totalInfo += sSkillDec + "������!" + NewStr() + sCurValue + sti(pchar.skill.Defence);
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

string descF54 = "������� +1";
void CalculateInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	CommonActions();
	if (sti(pchar.skill.Repair) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Repair = sti(pchar.skill.Repair) + 1;
		Log_info(sSkillInc + "�������!");
		totalInfo += sSkillInc + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Repair);
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

string descF55 = "������� -1";
void CalculateInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	CommonActions();
	if (sti(pchar.skill.Repair) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Repair = sti(pchar.skill.Repair) - 1;
		Log_info(sSkillDec + "�������!");
		totalInfo += sSkillDec + "�������!" + NewStr() + sCurValue + sti(pchar.skill.Repair);
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

string descF56 = "�������� +1";
void CalculateInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	CommonActions();
	if (sti(pchar.skill.Commerce) < 100)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksAdd.wav");
		pchar.skill.Commerce = sti(pchar.skill.Commerce) + 1;
		Log_info(sSkillInc + "��������!");
		totalInfo += sSkillInc + "��������!" + NewStr() + sCurValue + sti(pchar.skill.Commerce);
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

string descF57 = "�������� -1";
void CalculateInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	CommonActions();
	if (sti(pchar.skill.Commerce) > 1)
	{
		iSND = PlaySound("_CheatSurfMenu_\PerksClr.wav");
		pchar.skill.Commerce = sti(pchar.skill.Commerce) - 1;
		Log_info(sSkillDec + "��������!");
		totalInfo += sSkillDec + "��������!" + NewStr() + sCurValue + sti(pchar.skill.Commerce);
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

string descF58 = "! ����� !";
void CalculateInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F58", 1);
}

string descF59 = "! ����� !";
void CalculateInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F59", 1);
}

string descF60 = "! ����� !";
void CalculateInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F60", 1);
}

string descF61 = "! ����� !";
void CalculateInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F61", 1);
}

string descF62 = "! ����� !";
void CalculateInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F62", 1);
}

string descF63 = "! ����� !";
void CalculateInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F63", 1);
}

string descF64 = "! ����� !";
void CalculateInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F64", 1);
}

string descF65 = "! ����� !";
void CalculateInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F65", 1);
}

string descF66 = "! ����� !";
void CalculateInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F66", 1);
}

string descF67 = "! ����� !";
void CalculateInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F67", 1);
}

string descF68 = "! ����� !";
void CalculateInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F68", 1);
}

string descF69 = "! ����� !";
void CalculateInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
	SetFormatedText("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
	Statistic_AddValue(PChar, "Cheats.CSM2.F69", 1);
}

string descF70 = "! ����� !";
void CalculateInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	CommonActions();
	iSND = PlaySound("Interface\sobitie_na_karte_001.wav");
	totalInfo += "! ����� !" + back2totalInfo;
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
			sHeader = "���� '��������'";
			sText1 = "������ ���� '��������'";
		break;
		case "B_M3":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M4":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M5":
			sHeader = "���� '������'";
			sText1 = "������ ���� '������'";
		break;
		case "B_M6":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M7":
			sHeader = "���� '�������'";
			sText1 = "������ ���� '�������'";
		break;
		case "B_M8":
			sHeader = "���� '������'";
			sText1 = "������ ���� '������'";
		break;
	}
	CreateTooltip("#" + sHeader, sText1, argb(255,255,255,255), sText2, argb(255,255,192,192), sText3, argb(255,255,255,255), "", argb(255,255,255,255), sPicture, sGroup, sGroupPicture, 64, 64);
}

void HideInfo()
{
	CloseTooltip();
	SetCurrentNode("INFO_TEXT");
}
