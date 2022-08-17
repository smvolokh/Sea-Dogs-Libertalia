
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		
		
		
		case "Start_GameMyCabin":
			dialog.text = "��-��-��. � ��� ����....";
			link.l1 = "�������!";
			link.l1.go = "Start_GameMyCabin_exit";
		break;
		
        case "Start_GameMyCabin_exit":
		if (pchar.quest.main_line == "Takhion_Q8Q2_Repeat")
		{	AddDialogExitQuest("quest_HeadOfState_8_ToFury");	}
		else
		{	AddDialogExitQuest("Start_GameMyCabin_Beatrice3");	}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	case "quest_OnStrangerTides_Flsb":
			dialog.text = "";
			link.l1 = "���� ��������� ������, ����. ��-��, �����...";
			link.l1.go = "quest_OnStrangerTides_Flsb_End";
		break;
		    case "quest_OnStrangerTides_Flsb_End":
			AddDialogExitQuest("quest_OnStrangerTides_1_DrFlshb_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;
			
	case "quest_OnStrangerTides_Flsb_2":
			dialog.text = "�������-�� �� ������ � ����. ��� ���� ����������?";
			link.l1 = "׸��... �-��� �... �-�-�-�-, ���-�-���� ����...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_1";
		break;	
		case "quest_OnStrangerTides_Flsb_2_1":
			dialog.text = "����, ����... �� � ������������. � ���� ���� ���, ����� ��� ����� �� �����. �� ��� �� �� �� ���� ���.";
			link.l1 = "��-�-���-���?";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_2";
		break;	
		case "quest_OnStrangerTides_Flsb_2_2":
			dialog.text = "��, ��, �! ׸��, ���� ������ ���������... ������...";
			link.l1 = "�-�-�-�... ��-�����... �-�-����...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_3";
		break;		
		case "quest_OnStrangerTides_Flsb_2_3":
			dialog.text = "�������� ��! ��, �������� �� �� ������, �� �� ������ ����������, ��� ������ ������� ���! � ��� � ������, ��� � �������� �� �����... � ���� � ��� ����� � �� �������, ����! �� ���������?";
			link.l1 = "�-��... ����-����, �-�-�����...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_4";
		break;	
		case "quest_OnStrangerTides_Flsb_2_4":
			dialog.text = "�� ����� ���, ����. ����� �� �����������, � �� ����������� �����������, �� � ����� ������� � ����. �� �������� ��������, ��������� ��� � �����!  ������� ����? �� �������� ���� ����� ������!";
			link.l1 = "�� ��-��-�����...";
			link.l1.go = "quest_OnStrangerTides_Flsb_2_Ext";
		break;		
		    case "quest_OnStrangerTides_Flsb_2_Ext":
			AddDialogExitQuest("quest_OnStrangerTides_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;		
	
	case "quest_HeadOfState_1":
			dialog.text = "�������-��! � ��� �������� ����. ������ �����, ��� �� ��������" + GetSexPhrase("","�") + "?";
			link.l1 = "���? �� ��� �����?";
			link.l1.go = "quest_HeadOfState_1_1";
		break;	
		case "quest_HeadOfState_1_1":
			dialog.text = "���?.. �� �� ������ ����?";
			link.l1 = "����� ���... � ������?";
			link.l1.go = "quest_HeadOfState_1_2";
		break;	
		case "quest_HeadOfState_1_2":
			dialog.text = "������! ��� �� ��� ��������� �����... � ������ �����.";
			link.l1 = "�, �����! � ������ � ����. �������, ����� �����?..";
			link.l1.go = "quest_HeadOfState_1_3";
		break;		
		case "quest_HeadOfState_1_3":
			dialog.text = "���?! ������ ���� ������, "+ GetFullName(Pchar)+", ����� � �������� ������ �����! � ���, ��� �� �����, ������, ���. � ����, ����� ���� �� �� ���� ������, ����� ������ ���������� ���������, �� ������ � ��, ��� ��� ����� � ��� ��������� ������. ��� ����� ����� �� ������� ����� ��� �����! ���������, ������� ������� � � � �������! � ����� �������� � �����. �� ���� ������ ������� �� �������. �� ������ ��� ����� ���� ������. ��� �������?";
			link.l1 = "������... �... � �� ������ ������� ����. ��� ����� �������?";
			link.l1.go = "quest_HeadOfState_1_4";
		break;		
		case "quest_HeadOfState_1_4":
			dialog.text = "׸��... �� ���" + GetSexPhrase("��","��") + " ��, ��� � ��� ��������! ׸��, �� ������ �-�� ������� ����� ��, ��� � ��� ���?! � ��, �� ��� ������ ��������, ������ � ������� �����!";
			link.l1 = "� ��� ��?";
			link.l1.go = "quest_HeadOfState_1_5";
		break;	
		case "quest_HeadOfState_1_5":
			dialog.text = "��������, ������: ���� ����� "+ GetFullName(Pchar)+". �� ���" + GetSexPhrase("","�") + " ��������� ���������, ��������� �������. �� ������� ������" + GetSexPhrase("","�") + " � ��������� ���� �� ������, �� ������ ���-���������, �� ������� ����������. ���� �������� ������ ����� ������, � ��� �����... ����� ����. ��, ��� ����� ��������. � ���� ���� ������� �������� � ������� . �� ���� �������? ����� �����, ������ �����.";
			link.l1 = "��... ����� ��������...";
			link.l1.go = "quest_HeadOfState_1_6";
		break;	
		case "quest_HeadOfState_1_6":
			dialog.text = "���, �������, ������� �� ������ ���� ������� ������. �� ��������� ��� ����� ��� �������� �����. ���� ��������� �� �����, � ���� �������, ������� � �������� ������� � ������� ��� �����. � ��� ��� �� �����" + GetSexPhrase("","�") + " � � ������ ������� � ����� ������ ������" + GetSexPhrase("��","���") + " �����.";
			link.l1 = "��� ������... ����������?..";
			link.l1.go = "quest_HeadOfState_1_7";
		break;	
		case "quest_HeadOfState_1_7":
			dialog.text = "��� � ����� �����. �� ��� ���� �� ������. ��, ������� �����. ��, ������� �� �����" + GetSexPhrase("","�") + " ��� ��� ����. �� ��������� � ������ �� ��. �� �� ��� �� ����� �� ���, ���� �� ���� ����� ��������!";
			link.l1 = "��������?";
			link.l1.go = "quest_HeadOfState_1_8";
		break;	
		case "quest_HeadOfState_1_8":
			dialog.text = "��� �������, " + PChar.name + ". � �� �� ����� ������ �, �� ����, ��� ������ ����� ���������, ���� ����� �� ������� ������� �� ������� � ���. ��� ������ �����������! �� ���������� ������ ����������. ��� ����� ��� �����������. ���� ������ �������� � ���� �����.";
			link.l1 = "������ �� ������ ���������?";
			link.l1.go = "quest_HeadOfState_1_9";
		break;	
		case "quest_HeadOfState_1_9":
			dialog.text = "������, �� ��� �� ����������� ���, " + PChar.name + "! ��� � ������. ������ ������ � ���� ������������. �� ����� ���������� �������, �� ����� ����������� ������, �� ��� ������� ��� ���� ������, �� ��� ������ ������... �� ��������� ����, ���������? �� ��������� ���� �������.";
			link.l1 = "���? ��� ��������� ����?";
			link.l1.go = "quest_HeadOfState_1_10";
		break;	
		case "quest_HeadOfState_1_10":
			dialog.text = "׸���� ��������, ��� ����� ����������, " + PChar.name + "! ����������! �� ���� ������ � ���?";
			link.l1 = "�, �������. � ��� ����������� � � ������� ����������. � �������� ��� ���� ��������� ���������... �� ��������� � ������ ���������.";
			link.l1.go = "quest_HeadOfState_1_11";
		break;	
		case "quest_HeadOfState_1_11":
			dialog.text = "���?!? " + PChar.name + ", ����� ��� ����������! � ����������, ��� �� ������������ �����, ��� ����� ���������� �� ����� ����, �� � �� ���� ����� ������������! � ���� ������ �������� ������! � ��� �� �� ��������� � ��������� � ��, � ��� ��� ������������ ����!";
			link.l1 = "������ �������, �� ��������� ����� ������ ���� ����� ������?..";
			link.l1.go = "quest_HeadOfState_1_12";
		break;	
		case "quest_HeadOfState_1_12":
			dialog.text = "������� �� ���� ������, " + PChar.name + ", ����� �����, ����� ׸����, ����� ������, ����� ��� �����������, ��� �� ������ �������, ��� ������ ����� �������� ������! ��, � � �������! �� ����, ������ ��� ����� ��� ����� ������. ������� ������� ����� ������� ����� �������, �� � ����, ��� � ���� ����� ������. Ÿ ����� ��� �� �� ����� ���������. ��� �������� ��� � �� ��� ����� ������� ����.";
			link.l1 = "������ � ������ ������ ����?";
			link.l1.go = "quest_HeadOfState_1_13";
		break;	
		case "quest_HeadOfState_1_13":
			dialog.text = "׸��... �� ������ ��� � ������ �����. ������ ��� � �������� �������, ������ ��� �� ������ ����! ������ ��� � ���� ��� ���������, ������ ��� ����� �� ���� �������, �� ������� ��� ���� ������ ����� �������?!?";
			link.l1 = "���� �� ���� �� ����� ������������. ������ ��, � ���� ��� ����������.";
			link.l1.go = "quest_HeadOfState_1_14";
		break;	
		case "quest_HeadOfState_1_14":
			dialog.text = "���������... �����, ������. ������, ��� ������ �� ����� ���� ������ �������? ���, ��� �� �� ��������, ��� ������ ��� ��� ������� �� ������! ��� � ������ ��, ��� ��� ���, �� � ��� ���! �� ����� ���� ��� �������� �� '���������'! ��� �� � ���� �������! ����������!";
			link.l1 = "��� �... � ����" + GetSexPhrase("��","��") + " ������� �.";
			link.l1.go = "quest_HeadOfState_1_15";
		break;	
		case "quest_HeadOfState_1_15":
			dialog.text = "���, ��� ����������! ���� �� ������ �� '��������'. ��� ����� ����� ������ ���������� �����������.";
			link.l1 = "��, ����� � ����� � ������ ���.";
			link.l1.go = "quest_HeadOfState_1_16";
		break;	
		case "quest_HeadOfState_1_16":
			dialog.text = "����, " + PChar.name + "! " + PChar.name + "! ׸��, ����!..";
			link.l1 = "";
			link.l1.go = "quest_HeadOfState_1_Ext";
		break;			
		    case "quest_HeadOfState_1_Ext":
			AddDialogExitQuest("quest_HeadOfState_4_VelRezakGoOut");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;
			
	case "quest_HeadOfState_2":
			dialog.text = "" + PChar.name + ", ������� �����! ��� �� '���������'! �� ������ ���������� � � ������� ������!";
			link.l1 = "���! �� ���� ���! ��� �������� ��� � �����!";
			link.l1.go = "quest_HeadOfState_2_1";
		break;
		case "quest_HeadOfState_2_1":
			dialog.text = "���? ��� �� ���� �� �����?!";
			link.l1 = "";
			link.l1.go = "quest_HeadOfState_2_Ext";
		break;	
		    case "quest_HeadOfState_2_Ext":
			AddDialogExitQuest("quest_HeadOfState_6_7thFightDlgHmslf2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;	

	case "quest_HeadOfState_3":
			dialog.text = "";
			link.l1 = "�� �������, �����! � �� ����, ��� �� �����, �� � ��� ��������!";
			link.l1.go = "quest_HeadOfState_3_1";
		break;	
		case "quest_HeadOfState_3_1":
			dialog.text = "�����" + GetSexPhrase("","��") + "... �� �����" + GetSexPhrase("","��") + "! �� �� ����� �� ���������!";
			link.l1 = "����������� � ��, ������!!!";
			link.l1.go = "quest_HeadOfState_3_Ext";
		break;	
		    case "quest_HeadOfState_3_Ext":
			AddDialogExitQuest("quest_HeadOfState_8_FuryShot");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;		
			
		
		
	}
}


