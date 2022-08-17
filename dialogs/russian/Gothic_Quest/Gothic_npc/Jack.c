// ���� ���������� �����
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int poison_price;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Lighthouse\" + NPChar.City + "_Lighthouse.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
    int iTest, iTemp;
	string sTemp;
	bool ok;
    iTest = FindColony(NPChar.City); // �����
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                                PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_00.wav");
			dialog.text = "������ ���������� �����, ������ ������ �� �� ����?";
			link.l1 = "����������, ��������.";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JACKSettlement" && !CheckAttribute(npchar, "quest.JACKSettlement"))
			{
				link.l1 = "";
				link.l1.go = "Jack_meeting";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "�������� ��� � �����.";
				link.l1.go = "ChaniSettlementGoJack";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "MayakNoDieenemy" && !CheckAttribute(npchar, "quest.MayakNoDieenemy"))
			{
				link.l1 = "� ������ ���, � ��������� �����.";
				link.l1.go = "MayakNoDieenemy";
			}

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JackMayak" && !CheckAttribute(npchar, "quest.JackMayak"))
			{
				link.l1 = "";
				link.l1.go = "JackMayak";
			}
		break;

/// ********************** ���� ���������� �����  ***********************************

		case "Jack_meeting":
			dialog.text = "";
			link.l1 = "������ �� ��� �����?";
			link.l1.go = "Jack_meeting_2";
		break;

	case "Jack_meeting_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_01.wav");
            	dialog.text = "� ���� ����� �����-�� �������.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_3";
		break;

	case "Jack_meeting_3":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_GREET_14_02.wav");
            	dialog.text = "�� ���� � ������ " + GetSexPhrase("������","��������") + ", �� ��� ���� ����� ��� ������� ������� ����.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_4";
		break;

	case "Jack_meeting_4":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_15_00.wav");
            	dialog.text = "";
        	link.l1 = "�� ����� ������� � ������?";
        	link.l1.go = "Jack_meeting_5";
		break;

 	case "Jack_meeting_5":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_01.wav");
            	dialog.text = "� ������ ������, ����� ��������� �����, �� ������� ����� ��� ����.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_6";
		break;

 	case "Jack_meeting_6":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_02.wav");
            	dialog.text = "���� - ��� ������ � ���, ����� ��� ����������� � �� ���������� �����!!!";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_7";
		break;

 	case "Jack_meeting_7":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_CITY_14_03.wav");
            	dialog.text = "� ����� � ����� ����� ���������� - ����� ��������� ��� �� �� ������.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_8";
		break;

 	case "Jack_meeting_8":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_15_00.wav");
            	dialog.text = "";
        	link.l1 = "�������� ��� �� ���� �����?";
        	link.l1.go = "Jack_meeting_9";
		break;

 	case "Jack_meeting_9":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_14_02.wav");
            	dialog.text = "����� ������ �� ��������, ����� ����������������� ������, ������� ���� ������ �� ������� � �������� ������ � ������, ����� �����, ������, ����� ����� �����.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_10";
		break;

 	case "Jack_meeting_10":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_15_00.wav");
            	dialog.text = "";
        	link.l1 = "��� �� ������ ����� ��� �������?";
        	link.l1.go = "Jack_meeting_11";
		break;

 	case "Jack_meeting_11":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_14_01.wav");
            	dialog.text = "�������� �� ���, ��� �� ������� ������� ����������� �� ��� ���� �� �����, ��� ����� ������. ��� ������ � ������, ��� ���� ��� ��� ������� � ������� ���� ��������� ����� � �������.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_12";
		break;

 	case "Jack_meeting_12":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_ROGUE_14_02.wav");
            	dialog.text = "������ ����, ������� �� ��� ��������!!!";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_13";
		break;

 	case "Jack_meeting_13":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_15_00.wav");
            	dialog.text = "";
        	link.l1 = "��� ������ �� �� ������ ������?";
        	link.l1.go = "Jack_meeting_14";
		break;

 	case "Jack_meeting_14":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_01.wav");
            	dialog.text = "������� ����� �� ������ �� ������� ������� �������� ����� ����� ����.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_15";
		break;

 	case "Jack_meeting_15":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_02.wav");
            	dialog.text = "����������� ��������, ��� ������ ���� �� �� ��� �� �����, � ��� ��� ������ ����� ��������� �������.";
        	link.l1 = "";
        	link.l1.go = "Jack_meeting_16";
		break;

 	case "Jack_meeting_16":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_15_03.wav");
            	dialog.text = "";
        	link.l1 = "�, ��� �����?";
        	link.l1.go = "Jack_meeting_17";
		break;

 	case "Jack_meeting_17":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_HARBOR_LEAVE_14_04.wav");
            	dialog.text = "�����, ��� ������ � ����� ���������� ��� ������ ������ ������ � ��� ���� ������ �� ���� ��������� �����!!!";
        	link.l1 = "�� ������ ��������������� �� ������� � ���� �������� ���� ������ �� �������?";
        	link.l1.go = "Jack_meeting_18";
		break;

 	case "Jack_meeting_18":
            	dialog.text = "� ���� �����, ��� �� ������ ������� ������� ���� ����.";
        	link.l1 = "����? � ������ ��� ����?";
        	link.l1.go = "Jack_meeting_19";
		break;

 	case "Jack_meeting_19":
            	dialog.text = "�� ���������, ��� ����, �� ������ ���� ��������� ��� ������� � ���� ����� � �������� ����� ������ � �����, � ��� ����� - ������, ��� � ����� ����� �����.";
        	link.l1 = "������, � �� ���, ����� �������� ������, ������ ��������������� �� �������.";
        	link.l1.go = "Jack_meeting_20";
		break;

 	case "Jack_meeting_20":
            	dialog.text = "���, ������, �� � ������������ ����� ������, �� �� �������, ��������� ������ �� ������, ������� ��� �� �������������, � �� �������� ���� ����� � �������� ���� ��������!!!";
        	link.l1 = "� ����� ����� �� ������������ ������?";
        	link.l1.go = "Jack_meeting_21";
		break;

 	case "Jack_meeting_21":
            	dialog.text = "��, ��� ���� ����� ���������� ����.";
        	link.l1 = "������� �� �������, ��� ����.";
        	link.l1.go = "exit_1";
		break;

		case "Exit_1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.JACKSettlement = "true";
		pchar.questTemp.JACKSettlement = sti(pchar.questTemp.JACKSettlement)+1;
		if (sti(pchar.questTemp.JACKSettlement) == 2) 
		{
		AddDialogExitQuestFunction("JACK_SettlementOver");
		}
		else
		{
		AddDialogExitQuestFunction("JACK_Settlement_0");
		}
		break;


 	case "ChaniSettlementGoJack":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_03.wav");
            	dialog.text = "� ���� ��� ������ �������� ������, �� ���� ������ ���� ���� ��� ������ �����.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_1";
		break;

 	case "ChaniSettlementGoJack_1":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_04.wav");
            	dialog.text = "�� � ��� ����� �� ��� � ��.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_2";
		break;

 	case "ChaniSettlementGoJack_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_JOB_14_06.wav");
            	dialog.text = "� ��� ��� ��� ��� ������� ��������� ��� ����, � �� ����������� ��������� ����� ��� �� �������� �����, ��� ����� ������ ����.";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_3";
		break;

 	case "ChaniSettlementGoJack_3":
            	dialog.text = "";
        	link.l1 = "������ �� ���� ����� �� ���� � ������, � ���� �������, ���� �� �� ���������� ��� ������� ��� ��������� � �������, �� �� � ����� ������ �� �������������. � ���� ���� ������������, ��� �� �� �������� �������� �� �������, �� ��� ��� ���� �� �� ������� ���� ���� �� ���� �������.";
        	link.l1.go = "ChaniSettlementGoJack_4";
		break;

 	case "ChaniSettlementGoJack_4":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_00.wav");
            	dialog.text = "�������, �� ������, ��� ������� ��������?";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_5";
		break;

 	case "ChaniSettlementGoJack_5":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_15_01.wav");
            	dialog.text = "";
        	link.l1 = "�� ��� �� ���� ����� �������.";
        	link.l1.go = "ChaniSettlementGoJack_6";
		break;

 	case "ChaniSettlementGoJack_6":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_02.wav");
            	dialog.text = "���� ��������� � ����������� ����� ����� � ����������!";
        	link.l1 = "";
        	link.l1.go = "ChaniSettlementGoJack_7";
		break;

 	case "ChaniSettlementGoJack_7":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_04.wav");
            	dialog.text = "���� �� ��� ����� ��������� ���� �� � ����� ������� ������, � ����� ��� ��� ����, �� ������!";
        	link.l1 = "";
        	link.l1.go = "exit_2";
		break;

 	case "Exit_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_15_05.wav");
	DialogExit();
	NextDiag.CurrentNode = NextDiag.TempNode;
	npchar.quest.ChaniSettlementGoTorus = "true";
	pchar.questTemp.ChaniSettlementGoTorus = sti(pchar.questTemp.ChaniSettlementGoTorus)+1;
	if (sti(pchar.questTemp.ChaniSettlementGoTorus) == 2) 
	{
	AddDialogExitQuestFunction("PRESENT");
	}
	break;


 	case "MayakNoDieenemy":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_UNDEADDRAGONDEAD_15_00.wav");
            	dialog.text = "";
        	link.l1 = "� ������ ���, � ��������� �����.";
        	link.l1.go = "MayakNoDieenemy_1";
		break;

 	case "MayakNoDieenemy_1":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_BANDITENWEG_14_01.wav");
            	dialog.text = "��� ������! ������� - �� � ����� ����� ��������� � ����� ������.";
        	link.l1 = "";
        	link.l1.go = "MayakNoDieenemy_2";
		break;

 	case "MayakNoDieenemy_2":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_BANDITENWEG_14_02.wav");
            	dialog.text = "����� �� ���� � �����, ������ �� ������� ����������� ����������� ����� �� ����.";
        	link.l1 = "";
        	link.l1.go = "MayakNoDieenemy_3";
		break;

 	case "MayakNoDieenemy_3":
	PlaySound("VOICE\Russian\GOTHIC\GG\GG_6.wav");
            	dialog.text = "";
        	link.l1 = "������...";
        	link.l1.go = "exit_3";
		break;

		case "Exit_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.MayakNoDieenemy = "true";
	                   LAi_SetPlayerType(Pchar);
                                      pchar.GenQuest.CantRun = true;//������ ����
	                   AddDialogExitQuestFunction("MayakNoDieenemy_1");
		break;


	case "JackMayak":
	PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_LIGHTHOUSEFREE_14_01.wav");
            	dialog.text = "�������, ��������� �� �������� �� ����, �� ���� ����������� ����� ����������� ���. �������� ���� ����� ��� ����.";
        	link.l1 = "������.";
        	link.l1.go = "Exit_JackMayak";
		break;

		case "Exit_JackMayak":
		npchar.quest.JackMayak = "true";
	                   PlaySound("VOICE\Russian\gotica\JACK\DIA_JACK_DI_GREET_14_02.wav");
		ChangeCharacterComplexReputation(pchar, "nobility", 10);
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                   AddDialogExitQuestFunction("Jack_Golighthouse_6");
		break;


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;



	}
}


