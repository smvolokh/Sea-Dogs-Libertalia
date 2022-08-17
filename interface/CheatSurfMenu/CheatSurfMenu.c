
/*
	CheatSurfMenu by Cheatsurfer �� 07.01.2018 ��� ��� 1.6.0 (18.12.17)
	root���
	09.07.19  //  ����� ����������
*/

#include "interface\CheatSurfMenu\CheatSurfMenu_hotkeys.c"

// ���������� Log_SetStringToLog
void vLog(string sStr)
{
	Log_SetStringToLog(sStr);
}

// ���������� CheckAttribute
int csmCA(object oChar, string sAttr)
{
	return CheckAttribute(&oChar, sAttr);
}

// ���������� DeleteAttribute
void csmDA(object oChar, string sAttr)
{
	DeleteAttribute(&oChar, sAttr);
}

// ��������� P.I.R.A.T.E.S. �������� -->
void ChangePIRATESNavigator(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.navigator) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESBoatswain(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.boatswain) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESCannoner(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.cannoner) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESDoctor(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.doctor) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESTreasurer(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.treasurer) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESCarpenter(string qName)
{
	ref rChar;
	if (sti(pchar.Fellows.Passengers.carpenter) != -1)
	{
		rChar = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterA(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 1);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterB(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 2);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}

void ChangePIRATESFighterC(string qName)
{
	ref rChar;
	int ion = GetOfficersIndex(pchar, 3);
	if (ion != -1)
	{
		rChar = GetCharacter(ion);
		pchar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(rChar);
	}
}
// <--

// ����� ������� ����� ������� -->
string GetOfficerName(int iOfficer)
{
	ref rChar;
	string sOffName = "";
	int ion;
	bool bContinue = false;
	if (iOfficer < 1 || iOfficer > 9)
	{
		iOfficer = 1;
	}

	switch (iOfficer)
	{
		case 1:
			if (sti(pchar.Fellows.Passengers.navigator) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
				bContinue = true;
			}
		break;
		case 2:
			if (sti(pchar.Fellows.Passengers.boatswain) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
				bContinue = true;
			}
		break;
		case 3:
			if (sti(pchar.Fellows.Passengers.cannoner) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
				bContinue = true;
			}
		break;
		case 4:
			if (sti(pchar.Fellows.Passengers.doctor) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
				bContinue = true;
			}
		break;
		case 5:
			if (sti(pchar.Fellows.Passengers.treasurer) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
				bContinue = true;
			}
		break;
		case 6:
			if (sti(pchar.Fellows.Passengers.carpenter) != -1)
			{
				rChar = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
				bContinue = true;
			}
		break;
		case 7:
			ion = GetOfficersIndex(pchar, 1);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
		case 8:
			ion = GetOfficersIndex(pchar, 2);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
		case 9:
			ion = GetOfficersIndex(pchar, 3);
			if (ion != -1)
			{
				rChar = GetCharacter(ion);
				bContinue = true;
			}
		break;
	}
	if (bContinue)
	{
		sOffName = " (" + GetFullName(rChar) + ")";
	}
	return sOffName;
}
// <--

// ����� ������� ����� ���������� -->
string GetCompanionName(int iCompanionIdx)
{
	ref rChar;
	string sCompName = "";
	int icn;
	bool bContinue = false;
	if (iCompanionIdx < 1 || iCompanionIdx > 8)
	{
		iCompanionIdx = 1;
	}

	switch (iCompanionIdx)
	{
		case 1:
			icn = GetCompanionIndex(pchar, 1);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 2:
			icn = GetCompanionIndex(pchar, 2);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 3:
			icn = GetCompanionIndex(pchar, 3);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;

		case 4:
			icn = GetCompanionIndex(pchar, 4);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 5:
			icn = GetCompanionIndex(pchar, 5);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 6:
			icn = GetCompanionIndex(pchar, 6);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
		case 7:
			icn = GetCompanionIndex(pchar, 7);
			if (icn != -1)
			{
				rChar = GetCharacter(icn);
				bContinue = true;
			}
		break;
	}
	if (bContinue)
	{
		sCompName = " (" + GetFullName(rChar) + ")";
	}
	return sCompName;
}
// <--

// ���� ���������� ������ � �������� ����� ����� ��������������� ����� � ���� -->
void CSMSoundFix(string qName)
{
	if (IsEntity(&worldMap))
	{
		ResetSound();
		SetSchemeForMap();
	}
	else
	{
		if (IsEntity(&AISea) && !IsEntity(loadedlocation))
		{
			ResetSound();
			SetSchemeForSea();
		}
		else
		{
			ResetSound();
			LoadSceneSound();
		}
	}
}
// <--

void CSM_OnNewGame()
{
	pchar.CSM.StartNewGame = true;
//	pchar.CSM.Test = true;
	//
	csmInitItems();
	//
	if (!CheckAttribute(pchar, "CSM.WavesType"))
	{
		pchar.CSM.WavesType = -1;
		SM_WavesEnable();
		Whr_UpdateWeather();
		DoQuestFunctionDelay("CSMEnhancedSea", 0.5);
	}
}

void CSM_OnSave()
{
//
}

void CSM_OnLoad()
{
	ref sld, rItm;
	int i, ic, ip, icn, ipn;
	string sCheat, sT;

	// ���������� ��������� -->
	csmDelAttrs();
	//
	ShipsInit();
	//
	if (!CheckAttribute(pchar, "CSM.ContinuousMusicReset"))
	{
		if (CheckAttribute(pchar, "CSM.JungleContinuousMusic") && pchar.CSM.JungleContinuousMusic == true)
		{
			if (CheckAttribute(loadedLocation, "type") && loadedLocation.type == "jungle")
			{
				if (loadedLocation.type == locations[reload_cur_location_index].type)
				{
					pchar.CSM.ContinuousMusicReset = true;
				}
			}
		}
	}
	//
	DoQuestFunctionDelay("CSMCheckUpdates", 1.0);
	// <--

	// AoE �������������� ��������� -->
	rItm = ItemsFromID("pistol2");
	rItm.type.t1.multidmg = true;

	// ���� ��������� �����������, ����� ��� ���
	if (!CheckAttribute(pchar, "CSM.WaitressVoiceFix")) DoQuestFunctionDelay("csmWaitressVoice", 0.1);

	// ���� ������������ ���� �� �� -->
	if (!CheckAttribute(pchar, "CSM.OfficersFix"))
	{
		for (ic = 1; ic < COMPANION_MAX; ic++)
		{
			icn = GetCompanionIndex(pchar, ic);
			if (icn != -1)
			{
				sld = GetCharacter(icn);
				csmFixOfficers(sld);
			}
		}
		for (ip = 0; ip < GetPassengersQuantity(pchar); ip++)
		{
			ipn = GetPassenger(pchar, ip);
			if (ipn != -1)
			{
				sld = GetCharacter(ipn);
				csmFixOfficers(sld);
			}
		}
		pchar.CSM.OfficersFix = true;
	}
	// <--

	// ������ ����� -->
	if (!CheckAttribute(pchar, "CSM.StartNewGame") && !CheckAttribute(pchar, "CSM.FirstLaunch"))
	{
		//
//		pchar.CSM.Test = true;
		//
		if (GetItemsWeight(pchar) > GetMaxItemsWeight(pchar))
		{
			pchar.CSM.CargoTank = true;
			CheckAndSetOverloadMode(GetMainCharacter());
		}
		//
		csmInitItems();
		//
		if (!CheckAttribute(pchar, "CSM.WavesType"))
		{
			pchar.CSM.WavesType = -1;
			SM_WavesEnable();
			Whr_UpdateWeather();
			DoQuestFunctionDelay("CSMEnhancedSea", 1.0);
		}
		if (CheckAttribute(pchar, "CSM.OfficersSalary"))
		{
			for (ic = 1; ic < COMPANION_MAX; ic++)
			{
				icn = GetCompanionIndex(pchar, ic);
				if (icn != -1)
				{
					sld = GetCharacter(icn);
					if (GetRemovable(sld))
					{
						sld.Payment = true;
					}
				}
			}
			for (ip = 0; ip < GetPassengersQuantity(pchar); ip++)
			{
				ipn = GetPassenger(pchar, ip);
				if (ipn != -1)
				{
					sld = GetCharacter(ipn);
					if (isOfficerInShip(sld, true) || CheckAttribute(sld, "HiredDate") || sld.dialog.filename == "Enc_Officer_dialog.c" || sld.Dialog.CurrentNode == "hired" || CheckAttribute(sld, "Payment") || CheckAttribute(sld, "quest.OfficerPrice") || CheckAttribute(sld, "OfficerWantToGo") || CheckAttribute(sld, "OfficerWantToGo.DontGo")) // <-- �������� ^^
					{
						sld.Payment = true;
					}
				}
			}
		}
/*
		for (i = 1; i <= 70; i++)
		{
			sCheat = ".F" + i;
			DeleteAttribute(pchar, "Statistic.Cheats" + (sCheat));
		}
*/
		//
		pchar.CSM.FirstLaunch = true;
	}
	// <--
}

void csmInitItems()
{
	if (CheckAttribute(pchar, "InitItemsDone")) return;
	ref rItem;
	//
	rItem = ItemsFromID("blade_36");
	if (CheckAttribute(rItem, "picIndex") && rItem.picIndex != 16)
	{
		rItem.picIndex = 16;
		rItem.picTexture = "ITEMS_17";
		rItem.price = 10000;
		rItem.Weight = 3.0;
		rItem.lenght = 1.05;
		rItem.curve = 1.0;
		rItem.balance = 1.9;
	}
	//
	pchar.CSM.InitItemsDone = true;
}

void CheatSurfMenuWelcome(string qName)
{
	ClearAllLogStrings();
	DoQuestFunctionDelay("csmWaitressVoice", 0.1);
	pchar.CSM.Welcome = true;
	PlaySound("_CheatSurfMenu_\Ahha.wav");
	Log_info("���-���� ������ � �������������!");
}

string csmMenuText(int iType)
{
	if (iType < 0 || iType > 1) iType = 0;

	string sText = "Hello, world!";

	switch (iType)
	{
		case 0:
			sText = "�����������, ������!" +
					"\n������ ���-���� (����� ��) �������� � ������������� �� ������� Steam-������ ���� �������: ������� ���, ������ 1.6.0 (18.12.17)" +
					"\n ������� �� �������� Cheatsurfer � ��� �������, � (����� ����������) ���� ����������� � ������������� ��� ���� ��� ����� �����, � ������ ������ ������� �� ��������� �� ��������� ����� ���� � ��� �������" +
					"\n������� 'Esc' (��� ���� �� '��������' ������ ������) � ��������� ����� ���� ��� ���." +
					"\n������� �� �������� � �������� ����!";
		break;
		case 1:
			sText = "����� ������� ���� ������ ������, ����������� ������ ���� (������� �� ������) ��� ������ ������." +
					"\n������ ������ ����� �������� ��� ���������� ��� ������ �������� ������� ������ ���. ����� �� 'Esc'." +
		break;
	}

	return sText;
}

void csmDelAttrs()
{
	DeleteAttribute(pchar, "CSM.ChangeModels");
	DeleteAttribute(pchar, "CSM.Test");
//	DeleteAttribute(pchar, "CSM.ChangeModelM");
//	DeleteAttribute(pchar, "CSM.ChangeModelW");
}

// ������������� CalculateCheatsInfo()
void csmCheatsInfo(int iMenu)
{
	int i;
	string sCheat;
	string sMenu = "CSM1";

	if (iMenu < 0 || iMenu > 8) iMenu = 0;

	switch (iMenu)
	{
		case 0: sMenu = "CSM1"; break;
		case 1: sMenu = "CSM2"; break;
		case 2: sMenu = "CSM3"; break;
		case 3: sMenu = "CSM4"; break;
		case 4: sMenu = "CSM5"; break;
		case 5: sMenu = "CSM6"; break;
		case 6: sMenu = "CSM7"; break;
		case 7: sMenu = "CSM8"; break;
		case 8: sMenu = "CSM9"; break;
	}

	for (i = 1; i <= 70; i++)
	{
		sCheat = (sMenu) + ".F" + i;
		if(Statistic_AddValue(PChar, "Cheats." + sCheat, 0) == 0)
			PChar.Statistic.Cheats.(sCheat) = 0;
	}

	aref arAllCheats;
	makearef(arAllCheats, PChar.Statistic.Cheats.(sMenu));
	int iAllCheats = GetAttributesNum(arAllCheats);
	int iAllCheatsCount = 0;

	SetFormatedText("INFO_TEXT2", "���������������� ����:");

	for (i = 0; i < iAllCheats; i++)
	{
		sCheat = GetAttributeName(GetAttributeN(arAllCheats, i));
		int iCurCheatCount = Statistic_AddValue(PChar, "Cheats." + (sMenu) + "." + sCheat, 0);
		if(iCurCheatCount == 0) continue; // ���� ��� �� ������ - ����������
		if(HasSubStr(sCheat, "F"))
			AddLineToFormatedText("INFO_TEXT2", XI_ConvertString("D_" + sCheat) + " - " + iCurCheatCount + " ���.");
		else
			AddLineToFormatedText("INFO_TEXT2", sCheat + " - " + iCurCheatCount + " ���.");
		iAllCheatsCount = iAllCheatsCount + iCurCheatCount;
	}

	PChar.Statistic.Cheats.(sMenu) = iAllCheatsCount;
	AddLineToFormatedText("INFO_TEXT2", XI_ConvertString("Total") + " " + iAllCheatsCount + " ���.");

	if(iAllCheatsCount == 0) // ���� 0, ������ ����� �� �����
		SetFormatedText("INFO_TEXT2", "\n\n����� �� ��������������!");
}



/* --> by Sticks� : ���� ��� � ����� ����� ���� + ����������� ��������� ����������

Example:

string  model;
string  ani;
bool sldIsMush;

sldIsMush = CSM_GetModelByCrewType(pChar.GenQuest.BoardCrewType, &model, &ani, false);
sld = GetCharacter(NPC_GenerateCharacter("newSld", model, "man", ani, iRank, PIRATE, -1, true, "soldier"));
*/
	
bool CSM_GetModelByCrewType(int crewType, ref model, ref ani, bool tryToFindMushketer)
{
	
	object models;
	int totalVars;
	int rndVar;
	
	// ���� tryToFindMushketer = true � ��� ���� ������� ������� ���������� ������ ���������, �� ����� �� ��� �������.
	if (tryToFindMushketer)
	{
		
		switch (crewType)
		{
			
			case 0:
			//   	 ������						   					 ��������
			//         v												v
				models.v0 = "mush_ctz_" + (rand(2) + 4);		models.a0 = "mushketer"; // ������ � ������
				break;
			
			// ������ ..............................................................................
			
			case 1:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				break;
			case 2:
				models.v0 = "shturm_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�������
				break;
			case 3:
				models.v0 = "guard_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-���������
				break;
			case 4:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_eng_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_eng_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				break;
			case 5:
				models.v0 = "mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_eng_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_eng_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // ������ � ������
				break;
			case 6:
				models.v0 = "guard_mush_eng_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-���������
				models.v1 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a1 = "mushketer"; // ����� ����
				break;
			// ������� .............................................................................
			
			case 7:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				break;
			case 8:
				models.v0 = "shturm_mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�������
				break;
			case 9:
				models.v0 = "guard_mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-���������
				break;
			case 10:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_fra_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_fra_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				break;
			case 11:
				models.v0 = "mush_fra_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_fra_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_fra_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // ������ � ������
				break;
			case 12:
				models.v0 = "mush_Malta_" + (rand(2) + 1);		models.a0 = "mushketer"; // ���������-��������
				break;
				
			// ������� .............................................................................
			
			case 13:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				break;
			case 14:
				models.v0 = "shturm_mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�������
				break;
			case 15:
				models.v0 = "guard_mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-���������
				break;
			case 16:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_spa_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_spa_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				break;
			case 17:
				models.v0 = "mush_spa_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_spa_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_spa_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // ������ � ������
				break;
			case 18:
				models.v0 = "mush_Catalan_" + (rand(2) + 1);		models.a0 = "mushketer"; // ���������-��������
				break;
			
			// ��������� ...........................................................................
			
			case 19:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				break;
			case 20:
				models.v0 = "shturm_mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�������
				break;
			case 21:
				models.v0 = "guard_mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-���������
				break;
			case 22:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_hol_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_hol_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				break;
			case 23:
				models.v0 = "mush_hol_" + (rand(2) + 1);		models.a0 = "mushketer"; // ��������-�����
				models.v1 = "shturm_mush_hol_" + (rand(2) + 1);		models.a1 = "mushketer"; // ��������-�������
				models.v2 = "guard_mush_hol_" + (rand(2) + 1);		models.a2 = "mushketer"; // ��������-���������
				models.v3 = "mush_ctz_" + (rand(2) + 4);		models.a3 = "mushketer"; // ������ � ������
				break;

				// ������� ���� ................................................................................
			
			case 24:
				//models.v0 = "mush_ctz_" + (rand(2) +  4);		models.a0 = "mushketer"; // ������ � ������
				//models.v1 = "mush_ctz_" + (rand(2) +  7);		models.a1 = "mushketer"; // ����� � ������
				models.v2 = "mush_ctz_" + (rand(2) +  1);		models.a2 = "mushketer"; // ������ � ������
				models.v3 = "mush_ctz_" + (rand(2) + 10);		models.a3 = "mushketer"; // ������ � ������
				break;
	
			// ���� ................................................................................
			
			case 25:
				/* � ����� ����� ��� ����������, ���� � ������� */
				models.v0 = "Priest_" + (rand(2) + 2) + "_mush";		models.a0 = "mushketer";
				break;
				
			// ������ ..............................................................................
			
			case 26:
				models.v0 = "mush_ctz_" + (rand(2) + 7);		models.a0 = "mushketer"; // ����� � ������
				break;
			
			// ������� ............................................................................
			
			case 27:
				/* ���� ��������, ���� �� ����� ��� ���� � �������.. ����� �� ������� ���� ������ �������� :) */
				models.v0 = "mush_ctz_" + (rand(2) + 7);		models.a0 = "mushketer"; // ����� � ������
				break;
			
			// ������� ..............................................
			
			case 28:
				models.v0 = "mush_iroquois_" + (rand(7) +  1);		models.a0 = "mushketer"; // �������-��������
				break;
				
			// ������� ............................................................................
			
			case 29:
				/* �� �������� ������ ��������� ����� ����� �����.. ���� ��� ���� "Canib_mush", ���� ��������� ��� ��� */
				models.v0 = "mush_cnb_" + (rand(2) + 1);		models.a0 = "mushketer";
				models.v1 = "mush_Itza_" + (rand(2) + 1);		models.a1 = "mushketer";
				models.v2 = "mush_msk_" + (rand(2) + 1);		models.a2 = "mushketer";
				break;
				
			//����������............................................................................
			
			case 30:
			models.v0 = "mush_usa_" + (rand(2) + 1);		
			models.a0 = "mushketer"; 
				break;	
				
			// ������� ............................................................................
			
			case 31:
				/* ���� ��������, ����� �� ������� �����... */
				models.v0 = "skel" + rand(4) + "_mush";					models.a0 = "mushketer";
				break;
			
			// ���� ...............................................................................
			
			case 32:
				/* ���� ��������, ����� �� ���� �����... */
				models.v0 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a0 = "mushketer"; // ����� �����, �� ����
				break;
			
			// ������� � ���� .....................................................................
			
			case 33:
				/* ���� ��������, ����� �� ������� ��� ���� �����... */
				models.v0 = "skel" + rand(4) + "_mush";					models.a0 = "mushketer";
				models.v1 = "VaterSkel_" + (rand(3) + 1) + "_mush";		models.a1 = "mushketer"; // ����� �����, �� ����
				break;
		}
		
		totalVars = GetAttributesNum(models);
		if (totalVars > 0)
		{
			GRMAF(models, totalVars, model, ani);
			return true; // ���� �������� �������, �� � ���
		}
	}
	
	// � ��� ����� ������� ��������
	
	switch (crewType)
	{
		
		case 0:
			models.v0 = "citiz_" + (rand(9) + 31);			models.a0 = "man"; // ������
			break;
		
		// ������ .................................................................................
		
		case 1:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 2:
			models.v0 = "shturm_eng_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 3:
			models.v0 = "guard_eng_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 4:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_eng_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_eng_" + (rand(7) + 1);		models.a2 = "man"; // �������
			break;
		case 5:
			models.v0 = "sold_eng_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_eng_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_eng_" + (rand(7) + 1);		models.a2 = "man"; // �������
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // ������
			break;
		case 6:
			models.v0 = "VaterSkel_" + (rand(3) + 1);			models.a0 = "man"; // ����� ������
			models.v1 = "guard_eng_" + (rand(7) + 1);		models.a1 = "man"; // �������
			break;

		// ������� ................................................................................
		
		case 7:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 8:
			models.v0 = "shturm_fra_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 9:
			models.v0 = "guard_fra_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 10:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_fra_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_fra_" + (rand(7) + 1);		models.a2 = "man"; // �������
			break;
		case 11:
			models.v0 = "sold_fra_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_fra_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_fra_" + (rand(7) + 1);		models.a2 = "man"; // �������
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // ������
			break;
		case 12:
			models.v0 = "Malta_" + (rand(7) + 1);		models.a0 = "man"; // ���������
			break;
			
		// ������� ................................................................................
		
		case 13:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 14:
			models.v0 = "shturm_spa_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 15:
			models.v0 = "guard_spa_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 16:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_spa_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_spa_" + (rand(7) + 1);		models.a2 = "man"; // �������
			break;
		case 17:
			models.v0 = "sold_spa_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_spa_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_spa_" + (rand(7) + 1);		models.a2 = "man"; // �������
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // ������
			break;
		case 18:
			models.v0 = "Catalan_" + (rand(7) + 1);		models.a0 = "man"; // ���������
			break;
			
		// ��������� ..............................................................................
		
		case 19:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 20:
			models.v0 = "shturm_hol_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 21:
			models.v0 = "guard_hol_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
		case 22:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_hol_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_hol_" + (rand(7) + 1);		models.a2 = "man"; // �������
			break;
		case 23:
			models.v0 = "sold_hol_" + (rand(7) + 1);		models.a0 = "man"; // �������
			models.v1 = "shturm_hol_" + (rand(7) + 1);		models.a1 = "man"; // �������
			models.v2 = "guard_hol_" + (rand(7) + 1);		models.a2 = "man"; // �������
			models.v3 = "citiz_" + (rand(9) + 31);			models.a3 = "man"; // ������
			break;

		// ������� ���� ..................................................

		case 24:
			models.v0 = "mercen_" + (rand(12) + 16);		models.a0 = "man"; // �����
			break;
		
		// ���� ...................................................................................
		
		case 25:
			models.v0 = "monk_" + (rand(5) + 1);			models.a0 = "man_B"; // �����
			// todo: ����� �������� ������������ � �����?
			break;
			
		// ������ .................................................................................
		
		case 26:
			models.v0 = "citiz_" + (rand(9) + 41);			models.a0 = "man"; // �����
			break;
		
		// ������� ................................................................................
		
		case 27:
			models.v0 = "panhandler_" + (rand(5) + 1);		models.a0 = "man"; // �����
			models.v1 = "prison_" + (rand(4) + 1);			models.a1 = "man_B"; // ���
			models.v2 = "prizon_" + (rand(7) + 1);			models.a2 = "man_B"; // ������
			break;

		// ������� ..................................................
		
		case 28:
			models.v0 = "Iroquois_" + (rand(7) + 1);		models.a0 = "man"; // �������
			break;
			
		// ������� ................................................................................
		
		case 29:
			models.v0 = "Canib_" + (1 + rand(5));			models.a0 = "man"; // ��������
			models.v1 = "Itza_" + (1 + rand(7));			models.a1 = "man"; // ���
			models.v2 = "AztecWarrior" + (1 + rand(4));		models.a2 = "man"; // �����
			models.v3 = "Miskito_" + (1 + rand(5));			models.a3 = "man"; // �������
			break;

		//����������................................................................................
		
		case 30:
		models.v0 = "sold_usa_" + (rand(7) + 1);					models.a0 = "man"; 
			break;

		// ������� ................................................................................
		
		case 31:
		models.v0 = "Skel" + rand(4);							models.a0 = "man"; // ������
		models.v1 = "SkelK2_" + rand(4);						models.a1 = "man_B"; // ������ �� �2
		break;
		
		// ���� ...................................................................................
		
		case 32:
		models.v0 = "VaterSkel_" + (rand(3) + 1);					models.a0 = "man"; // ����� ������
		break;
		
		// ������� � ���� .........................................................................
		
		case 33:
		models.v0 = "Skel" + rand(4);							models.a0 = "man"; // ������
		models.v1 = "SkelK2_" + rand(4);						models.a1 = "man_B"; // ������ �� �2
		models.v2 = "VaterSkel_" + (rand(3) + 1);					models.a2 = "man"; // ����� ������
		break;
	}
	
	totalVars = GetAttributesNum(models);
	if (totalVars > 0)
		GRMAF(models, totalVars, model, ani);
	
	return false;
}

// � ����������� ������ (get random model i animation from)
void GRMAF(object models, int totalVars, ref model, ref ani)
{
	aref aModels;
	makearef(aModels, models);
	int index = rand(totalVars / 2 - 1) * 2;
	model = GetAttributeValue(GetAttributeN(aModels, index));
	ani = GetAttributeValue(GetAttributeN(aModels, index + 1));
}

void CSM_LoadNextWeather()
{
    iCurWeatherNum++;
    if (iCurWeatherNum > 23)
        iCurWeatherNum = 0;
    CSM_LoadWeatherContinue();
}
 
void CSM_LoadPrevWeather()
{
    iCurWeatherNum--;
    if (iCurWeatherNum < 0)
        iCurWeatherNum = 23;
    CSM_LoadWeatherContinue();
}
 
void CSM_LoadWeatherContinue()
{
    if (!isEntity(&Weather)) return;
    iCurWeatherHour = iCurWeatherNum;
    SetCurrentTime(iCurWeatherNum, 0);
    Weather.Time.time = GetTime();
    CreateWeatherEnvironment();
    MoveWeatherToLayers(sNewExecuteLayer, sNewRealizeLayer);
}

// ����� ��������� ���� ��� ����� � �����-�� ��������
string CSM_GetRandomCannonSoundByCaliber(int caliber)
{
	if (caliber <= 8)
		return "asm_little_" + (rand(5) + 1);
	else if (caliber > 8 && caliber <= 20)
		return "asm_medium_" + (rand(5) + 1);
	else
		return "asm_heavy_" + (rand(5) + 1);
	
	return "";
}
// by Sticks� <--



void CSMAnimationFix(string qName)
{
	ClearAllLogStrings();
	Log_info("���� �������� ��������� '���������', � ����� ������������ � ���� '��������' (����� #65 � #68)!");
}

void CSMCheckUpdates(string qName)
{
	aref arFader;
	if (FindClass(arFader, "fader")) return;

	bool bTest = false;

	pchar.CSM.Version = "ver. 1.6.0 (18.12.17)";

	if (bTest)
	{
		pchar.CSM.Version = " " + VERSION_NUMBER2;
	}

	if (pchar.CSM.Version != VERSION_NUMBER2)
	{
		ClearAllLogStrings();
		log_info("������� ������ ����: " + VERSION_NUMBER2);
		log_info("������ ������ ���� ��� ��: " + pchar.CSM.Version);
		PlaySound("_CheatSurfMenu_\NationRelationChange.wav");
		pchar.CSM.ChangeName = "Update";
		CSMLaunchMenuName();
	}

	if (SHIP_TYPES_QUANTITY != 64) DoQuestFunctionDelay("CSMCheckSave", 0.25);
}

void CSMChangeName(string qName)
{
	CSMLaunchMenuName();
}

void CSMCheckSave(string qName)
{
	ClearAllLogStrings();
	PlaySound("_CheatSurfMenu_\WTF.wav");
	pchar.CSM.ChangeName = "Save";
	CSMLaunchMenuName();
}

void CSMEnhancedSea(string qName)
{
	ClearAllLogStrings();
	log_info("�������� ��������� ������ ����������� �� Sticks.");
	log_info("��� ����� ����� �������� \ ��������� � ���� '������', #46.");
}

void csmWaitressVoice(string qName)
{
	if (CheckAttribute(pchar, "CSM.WaitressVoiceFix")) return;

	ref rChar;
	int iChar;

	for (iChar = 0; iChar < TOTAL_CHARACTERS; iChar++)
	{
		rChar = GetCharacter(iChar);
		if (CheckAttribute(rChar, "chr_ai.type") && rChar.chr_ai.type == LAI_TYPE_WAITRESS)
		{
			rChar.greeting = "waitress_voice";
		}
	}

	pchar.CSM.WaitressVoiceFix = true;
}

void SetBasePerks(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;

	// ������� � �������� ����� ����������
	SetCharacterPerk(rChar, "Energaiser");
	switch (rChar.id)
	{
		case "HelenaClon": SetCharacterPerk(rChar, "HT1"); break;
		case "MaryClon": SetCharacterPerk(rChar, "HT1"); break;
		case "DanielleClon": SetCharacterPerk(rChar, "HT1"); break;
		case "KnippelClon": SetCharacterPerk(rChar, "HT4"); break;
		case "LongwayClon": SetCharacterPerk(rChar, "HT3"); break;
		case "TichingituClon": SetCharacterPerk(rChar, "HT4"); break;
		case "TonzagClon": SetCharacterPerk(rChar, "HT3"); break;
		case "SteampunkGirl": SetCharacterPerk(rChar, "HT2"); break;
		case "Angellica": SetCharacterPerk(rChar, "HT1"); break;
		case "Yoko": SetCharacterPerk(rChar, "HT1"); break;
		case "Douglas": SetCharacterPerk(rChar, "HT4"); break;
		case "JaPreston": SetCharacterPerk(rChar, "HT3"); break;
		case "Magnus": SetCharacterPerk(rChar, "HT4"); break;
		case "Nicolas": SetCharacterPerk(rChar, "HT4"); break;
		case "CSMDevlinBlaze": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMBeatriceSharp": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMJessikaBradford": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMPiterBlood": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMMichelDeGrammont": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMWillaimPatterson": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMBartPortugal": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMDiegoEspinosa": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMPitt": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMOgl": SetCharacterPerk(rChar, "HT1"); break;
		case "Vincento_Capellan": SetCharacterPerk(rChar, "HT3"); break;
		case "CSMBlackBeard": SetCharacterPerk(rChar, "HT3"); SetCharacterPerk(rChar, "HT4"); break;
		case "CSMLawrenceBeltrop": SetCharacterPerk(rChar, "HT3"); SetCharacterPerk(rChar, "HT4"); break;
		case "CSMJWorkman": SetCharacterPerk(rChar, "HT3"); break;
		case "FleetwoodClon": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMChani": SetCharacterPerk(rChar, "HT1"); break;
		case "CSMCiri": SetCharacterPerk(rChar, "HT1"); SetCharacterPerk(rChar, "HT3"); break;
		case "CSM_JanPikar": SetCharacterPerk(rChar, "HT1"); break;
	}
	if (HasSubStr(rChar.id, "CSMNavalOfficer")) SetCharacterPerk(rChar, "HT1");
}

// ���� ������������ ���� � ��
void csmFixOfficers(ref rChar)
{
	if (!CheckAttribute(rChar, "id")) return;

	if (rChar.id == "HelenaClon" || rChar.id == "MaryClon" || rChar.id == "DanielleClon" || rChar.id == "KnippelClon" || rChar.id == "LongwayClon" || rChar.id == "TichingituClon" || rChar.id == "TonzagClon" ||
		rChar.id == "SteampunkGirl" || rChar.id == "Angellica" || rChar.id == "Yoko" || rChar.id == "Douglas" || rChar.id == "JaPreston" || rChar.id == "Magnus" || rChar.id == "Nicolas" || rChar.id == "CSMDevlinBlaze" ||
		rChar.id == "CSMBeatriceSharp" || rChar.id == "CSMJessikaBradford" || rChar.id == "CSMPiterBlood" || rChar.id == "CSMMichelDeGrammont" || rChar.id == "CSMWillaimPatterson" || rChar.id == "CSMBartPortugal" ||
		rChar.id == "CSMDiegoEspinosa" || rChar.id == "CSMPitt" || rChar.id == "CSMOgl" || rChar.id == "Vincento_Capellan" || rChar.id == "CSMBlackBeard" || rChar.id == "CSMLawrenceBeltrop" || rChar.id == "CSMJWorkman" ||
		rChar.id == "FleetwoodClon" || rChar.id == "CSMChani" || rChar.id == "CSMCiri" || HasSubStr(rChar.id, "CSMNavalOfficer"))
	{
		rChar.CSM.NPC = true;
		rChar.CSM.CommonAttributes = true;
	}
}

// ���� �������� � ����������� "�����������", ���� � ����� �� ��� ������
void csm_EnemyNationHunterOnMap(bool _fast)//�������� ��������� �����
{
    ref  sld;
    int  i, iNation;
    string sCapId = "FollowerNation0"; // patch
    string sGroup = "Sea_" + sCapId + "1";
	Group_DeleteGroup(sGroup);
	Group_FindOrCreateGroup(sGroup);
	iNation = GetEnemyNationToMainCharacter();//��������� �����
	if (iNation < 0 || iNation > 4) iNation = PIRATE;
    for (i = 1; i <= GetCompanionQuantity(pchar); i++)
    {
        sld = GetCharacter(NPC_GenerateCharacter(sCapId + i, "off_" + NationShortName(iNation) + "_" + (rand(1) + 1), "man", "man", sti(PChar.rank) + 5, iNation, 6, true, "hunter"));
        SetShipHunter(sld);
        SetFantomParamHunter(sld);
        SetCaptanModelByEncType(sld, "war");
        sld.AlwaysEnemy = true;
        sld.DontRansackCaptain = true;
        sld.mapEnc.type = "war";
        sld.mapEnc.Name = "������������";
		sld.hunter = ""+iNation+"";
        Group_AddCharacter(sGroup, sCapId + i);
    }
    Group_SetGroupCommander(sGroup, sCapId+ "1");
    Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
    Group_LockTask(sGroup);
	if (_fast) Map_CreateCoolWarrior("", sCapId + "1", 6);
	else Map_CreateWarrior("", sCapId + "1", 6);
}

// --> ������� ����� �������. �� ������ ���� dolphin'� (����� ���)
#event_handler("csmEventSwapWeapon", "csmSwapWeapon");
void csmSwapWeapon()
{
	int i = 0;
	bool bBullet = false;
	ref rGun, rCharge;
	string sAttr, sCharge;
	string sMusket = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);

	LAi_LockFightMode(pchar, false);

	if (HasSubStr(sMusket, "mushket"))
	{
		SetMainCharacterToMushketer("", false);
		pchar.CSM.PrevMusket = sMusket;
	}
	else
	{
		if (csmCA(pchar, "CSM.PrevMusket"))
		{
			if (CheckCharacterItem(pchar, pchar.CSM.PrevMusket))
			{
				// 2do: ����� �� ������� ���� ��������� �, ���� ����, ������� ������ ������
				SetMainCharacterToMushketer(pchar.CSM.PrevMusket, true);

				rGun = ItemsFromID(pchar.CSM.PrevMusket);

				for (i = 1; i <= 2; i++)
				{
					sAttr = "t" + i;
					sCharge = rGun.type.(sAttr).bullet;

					if (CheckCharacterItem(pchar, sCharge))
					{
						bBullet = true;
						LAi_SetCharacterUseBullet(pchar, sCharge);
						LAi_GunSetUnload(pchar); // 2do: �� �������� ����������� �������
						rCharge = ItemsFromID(sCharge);
						vLog("������������ ��� ����������� ��� '" + GetConvertStr(rGun.name, "ItemsDescribe.txt") + "': " + GetConvertStr(rCharge.name, "ItemsDescribe.txt"));
						break;
					}
				}

				csmDA(pchar, "CSM.PrevMusket");
				csmSFM();

				if (!bBullet)
				{
					csmSound("WTF", 0);
					vLog("���������� ����������� ��� '" + GetConvertStr(rGun.name, "ItemsDescribe.txt") + "' �� �������!");
				}
			}

			return;
		}
		else
			return;
	}

	csmSFM();
}

void csmSFM()
{
	if (LAi_grp_playeralarm > 0)
	{
		if (!LAi_CheckFightMode(pchar))
			PostEvent("csmEventSwapWeaponFight", 100);
		else
			SendMessage(&pchar, "lsl", MSG_CHARACTER_EX_MSG, "SetFightMode", 1);
	}
}

#event_handler("csmEventSwapWeaponFight", "csmSwapWeaponFight");
void csmSwapWeaponFight()
{
	LAi_LockFightMode(pchar, false);
	LAi_SetFightMode(pchar, true);
}

void csmSwapWeaponBack()
{
	string sMusket = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);

	if (csmCA(pchar, "CSM.IsFireNow"))
	{
		vLog(PChar.name + " � ������ ������ �����" + GetSexPhrase("", "�") + " ���������!");
		return;
	}
	else
	{
		LAi_SetFightMode(pchar, false);
		LAi_LockFightMode(pchar, true);

		// "��������� �������", ����� ������ �� �������� ��� ����� ��������
		if (HasSubStr(sMusket, "mushket"))
			PostEvent("csmEventSwapWeapon", 500);
		else
			PostEvent("csmEventSwapWeapon", 1700);
	}
}

#event_handler("csmEventSwapWeaponIsFireNowDel", "csmSwapWeaponIsFireNowDel");
void csmSwapWeaponIsFireNowDel()
{
	csmDA(pchar, "CSM.IsFireNow");
}
// <-- ������� ����� �������

int csmSound(string sFile, int iType)
{
	string sType = ".wav";

	if (sFile == "")
		sFile = "WTF";

	if (iType < 0 || iType > 2)
		iType = 0;

	switch (iType)
	{
		case 0: sType = ".wav"; break;
		case 1: sType = ".ogg"; break;
		case 2: sType = ".mp3"; break;
	}

	return PlaySound("_CheatSurfMenu_\" + sFile + sType);
}

// 2do: 20may17 ������� ��� ��� ���� �����, ������ ����� �� �������, ��������� ��� ������������� ������ -->
bool bCSMSkipStartVids = true;
bool bCSMDeletePerks = false;
bool bCSMGotAllHidePerks = false;
bool bCSMShowHelpHints = false;
bool bCSMCheckAndIdentifyShips = true;
bool bCSMKillEmAll = false;
bool bCSMFreeSailing = false;
bool bCSMSailToEffectRadius = false;
bool bCSMAllItemsInTrade = false;
bool bCSMAllShipsInTrade = false;
bool bCSMSkipShips = false;
bool bCSMMachineGunCannons = false;
bool bCSMCirassPenalty = true;
bool bCSMDeleteShipsInStock = true;
bool bCSMEnergyDrain = true;
bool bCSMTreasureMapTrader = false;
bool bCSMShipHullPenalty = true;
bool bCSMBoardingCrewGodMode = false;
bool bCSMShipCapellanHatePirates = true;
bool bCSMShipInstantRepair = false;
bool bCSMShipMutinies = true;
int iCSMBaseWeight = 70;
float fCSMBonusEnergy = 1.0;
// <-- 2do: del