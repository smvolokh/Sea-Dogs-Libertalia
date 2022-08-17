// ������� ��� �� ������ '� ������� ������ ������'
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "��� ��� ������?";
			link.l1 = "������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ������� �������
		case "spa_prisoner":
			PlaySound("VOICE\Russian\Ransack_1.wav");
			dialog.text = "��� ��� �� ���� �����? ����� ������?";
			link.l1 = "������, ��� ���� ���?";
			link.l1.go = "spa_prisoner_1";			
		break;
		
		case "spa_prisoner_1":
			dialog.text = "�� ����� � ����� ��� �������, ���� ��� ������������� ��� ������? � ���� �������������� ������� � ��� � ����, �...";
			link.l1 = "������, �������� ��� ���: �������� ���� ���. � �� ���� ������������� � ���������, �� ����, ��� ��� �����.";
			link.l1.go = "spa_prisoner_2";			
		break;
		
		case "spa_prisoner_2":
			dialog.text = "��� "+GetFullName(npchar)+". ��� ���������� ��� �����? � � ��� � ���� ����� ����� ������?";
			link.l1 = "���� ����� "+GetFullName(pchar)+". ������� ��� ��� �� �������?";
			link.l1.go = "spa_prisoner_3";			
		break;
		
		case "spa_prisoner_3":
			dialog.text = "���, ���� ������! � �� ������ ����� ����...";
			link.l1 = "��������. ��������� ��� ����������� � ����������� ����� ����, ��� ���������� ����. �� ����, ��� ������ �� ������� ��� ��������, ����� �������� ���� ������. ���� �� ������� ���� ���-�� ���� ������������ - � �������������� � ����� ������ � ��� ������������, � �� ������� �������� ��������� ��� ��������, ������� ��� ����.";
			link.l1.go = "spa_prisoner_4";			
		break;
		
		case "spa_prisoner_4":
			dialog.text = "�� ��� ��, ����� � �����. ��� ������ �� ������ ������, ������?";
			link.l1 = "��� � ����� ����������� ����� ���������� ��������� �� ���� �� �����?";
			link.l1.go = "spa_prisoner_5";			
		break;
		
		case "spa_prisoner_5":
			dialog.text = "������ ��� ����� ����� ������� ��-��������-�-����, ����������������� ���������� ������� �����������. �� �� ���� ��������� �������. ���� - ������ ������������ ��������� ����������� �������.";
			link.l1 = "������ ���� ���� ���������������� ������ ��� ������ ������? ����� ����?";
			link.l1.go = "spa_prisoner_6";			
		break;
		
		case "spa_prisoner_6":
			dialog.text = "� - �������� ������� ������, � ���� ������ ������ ������ ����� � ����������� ���������� ������� ������� � �����. ����� ��� ����� �������� ������� � ����� �� ��� �����.";
			link.l1 = "�� ���� ����������� � ���������, ����������� � ������? �� �� �������, ������������ �������?";
			link.l1.go = "spa_prisoner_7";			
		break;
		
		case "spa_prisoner_7":
			dialog.text = "������ �������� � ��� �� ����, �� ����� ��-�������-�-���� ���������, ��� � ����������� ����� �������� �������, � �� �������� ������� - �������������� �����: ������ � ����������� ����.";
			link.l1 = "�� ����� ��� ��������?";
			link.l1.go = "spa_prisoner_8";			
		break;
		
		case "spa_prisoner_8":
			dialog.text = "���. �� ����, �� ������� ���������� �� ����. ������ ���� ��������� ������� ������������ �������, � ���������� ����� - �������, ������� � ������������. �� �� �� ������ ���������� ���������� ������, ��� ��������� ������������ ��������� � �� ���� ��������� ������� ���.";
			link.l1 = "���������� ������ ������� ��� �� ���������� ��������?";
			link.l1.go = "spa_prisoner_9";			
		break;
		
		case "spa_prisoner_9":
			dialog.text = "����������, �� � �� ���� �������� ��������� �������.";
			link.l1 = "� ��� ����� ���������: � ����� ���� �� ������ ������� �� ���� �������, � �� ������� - ������� � �����. � ��� ������ ������ ���������, ������, ����� ��� ��� ��������, ��� ���� ��� ����� ��� �� ����������, � ���������� � ����, ������� ��� ����� ������... ������ ��������� ������.";
			link.l1.go = "spa_prisoner_10";			
		break;
		
		case "spa_prisoner_10":
			dialog.text = "� ��� ����������� ������.";
			link.l1 = "� �� ����, ��� ������������ ����� ������ ��� ��������� ������. ���� �� ����� - ������ �� ����� ������� �������, ����� ��������� ���� ������� �� ����� � �������� ��������. ��������� ��, ��� ��� ��������, ��� ���-�� ���, ���� �������������� ������� ��� ��������. ����� ������? ���������� ���������, ������ ��� ��������...";
			link.l1.go = "spa_prisoner_11";			
		break;
		
		case "spa_prisoner_11":
			dialog.text = "";
			link.l1 = "�������? ������. �������, � �������.";
			link.l1.go = "spa_prisoner_12";			
		break;
		
		case "spa_prisoner_12":
			dialog.text = "������, �� ����� ������ ����� �������� ��� ���������� ������?";
			link.l1 = "������!";
			link.l1.go = "spa_prisoner_13";			
		break;
		
		case "spa_prisoner_13":
			dialog.text = "� ���� ���� ���-���... �� �� ������ ���������� ���, ��� �������� ���� ������ � � ���������� ���������� �� ����� �������.";
			link.l1 = "���� �� ������� ����� ������������� �������� - �������, ��� �� ������ ���������� �� ���� ����� ������� � �������� �����.";
			link.l1.go = "spa_prisoner_14";			
		break;
		
		case "spa_prisoner_14":
			dialog.text = "������. ��� ����� �� ������� �������������� ��������� ����, ��� ����� � ������������ ������� ����� � ����� � ���� �������� �� ����� ������ ������, ������� ��������� ���-�� � ���� �� ������ ��� ������� �������.";
			link.l1 = "�����������. ��� ����� ����� �� �������?";
			link.l1.go = "spa_prisoner_15";			
		break;
		
		case "spa_prisoner_15":
			dialog.text = "���������������� ������������ ����������. �� ����� �������� ����� ������� �� ������ ����� �������...";
			link.l1 = "��� �� �����, ���� ��� �����?";
			link.l1.go = "spa_prisoner_16";			
		break;
		
		case "spa_prisoner_16":
			dialog.text = "� ���� ���� ��, ��� �� ���������� ���� ������ ��-�������-�-����, ��� ������ ���� � ����� �� ����� ������ ����������.";
			link.l1 = "���������... �� � ��� �� ���� ������ ������, ���� ��������, ���� �� �����, � ���� �������� ��� ��� ��������? ������, ������� �����?";
			link.l1.go = "spa_prisoner_17";			
		break;
		
		case "spa_prisoner_17":
			dialog.text = "�� ������� � ����� ������, ������?";
			link.l1 = "��. � �����������, ��� ���� �� ���������� ��� �������, �� ������ ���������� ��� ������ ��������� �� ��� �����, � � ����������... � �����, � ����� ������ ��������� ��� � ��������� ���������. �� �� ������, ��� �� ��������� ���, ��� ���� ����� ��������������.";
			link.l1.go = "spa_prisoner_18";			
		break;
		
		case "spa_prisoner_18":
			dialog.text = "������ ������ - ������ �������� ������, ������, ��� �������, �� ������ ���. ������ ��-�������-�-���� ����� ����� ���, ������ �����, ��� ��� ��� ����� ������ �� � ���� ������ �� ������� ������.";
			link.l1 = "������ - �������?";
			link.l1.go = "spa_prisoner_19";			
		break;
		
		case "spa_prisoner_19":
			dialog.text = "��. ��� ����� �� ������� ��� ��������������� �������� � ���������� ���� ����������� ��� ���� ��� ���������� ������ � ����. �� �� �� �����, ��� �� ���������� � ������, � ��� ���� �� ���� ������� ����������� ������.";
			link.l1 = "�� ����� ������ �����?";
			link.l1.go = "spa_prisoner_20";			
		break;
		
		case "spa_prisoner_20":
			dialog.text = "���. �� � ���� ������ ���� ����, ������� ��� � ����. ��� ��� ������.";
			link.l1 = "������ ���� ������������� �������� ������ � ��������� ������ ���� �������, ��� �� ������� �� ��� ����� �������? ��� ��� ��������?";
			link.l1.go = "spa_prisoner_21";			
		break;
		
		case "spa_prisoner_21":
			dialog.text = "� ����� ������ - ��. ����� ������ �� ������ �� ������ ������������ �������. � ��� ������ ������� ����������� ������������ ������������ ��������� �������� � ������� �������, ������ ������ ����� �� ������� �������� ��������� ��������. �� �����, ��� ���-�� � ������� ������� ��������� ������ ����� �������� ����-��� - ��������, � ������� ����� ������\n����� �������� ��������� ���������� �� ����� ����� ������, �� ��� ���, ��� ����, ������ ��������� � ����� ������. ��� ��������, �� ���� �������� ������������ ������� ���, ��������� � ��� �����\n� �����-������ ��� �������������� ������� � ������������� ������ ������ ������� ������������ ����������� - ���� ��������, � �� ������� �� ���� � ������. ������ ��������� ���������� �������� ����������� ������. ��� ���-�� � �������� ������ ������\n��� ������������ ����������, �� ����� �������, ��� ��� �� �������, ���� ������� ����� ������� ���������� ������ � ���� ������ � ����������� ������. ������ �� �������� ���� �� ���������� ������ ������� ��������\n����� ����� �������� �� ��� � ����� �� ���������, ������ ���, ����� ������, ������ - ������ �������� ���� ��������� �����-�� �������� ���� - ���� ��������� �������� ��������� ����� ��������� ���� � ������. ������ �� � ����������� �������� �� �����������\n��� ��� ���� ����! ����� ���������� ���������, �������� ������� ������ � ������ � ���� �������� � �������� - ����� ������� ����. ����� ��� �������� ������ � ����� ����������� ��� �������� � �������. ������������ ��������� ���������� ������ ������...";
			link.l1 = "� ��, �������, �� �� �����?";
			link.l1.go = "spa_prisoner_22";			
		break;
		
		case "spa_prisoner_22":
			dialog.text = "������! ������ ��������� ����� ������ �� ���� ������ � ��������, ������� ������, ��� � �� ����� �� �������. ����� ��� ������ � ������, ������ ��� �� ����� ���������� ����� ���������� �� ������� ���� ��������. �� ������... � �����, ������ ������ ���� ��� ���������� �����...";
			link.l1 = "��� ���� �����, ������ ������ ����� � ����� � ������? ��� �������� ��������?";
			link.l1.go = "spa_prisoner_23";			
		break;
		
		case "spa_prisoner_23":
			dialog.text = "����� � ������ ���-�� ���������, ��� ������ � ���, ��� ������ ��� ������. ������������ � �� ����. ����� �������� ��� ����� �� �������, �������, ��� � �������, � ������� ������, ��� ������ ������ ����� ���� � ���� �� ������.";
			link.l1 = "��. �������. ����� ��� ��������� ���������. ���-�� ��� ��� ������������� �� ��� ��������... ������, ������ ��� � �� �����?";
			link.l1.go = "spa_prisoner_24";			
		break;
		
		case "spa_prisoner_24":
			dialog.text = "���. � � �� ��������, ���� ��� ��� � �� ����. ����� ������ ������� ������ �������� ������, �� ���, ��� ����� ����� ����������� ���������.";
			link.l1 = "�������, "+npchar.name+", � ������ ��� ������� ����� ��� ����... ��� ���... ��������? �� �� �� �� ��� ��� ������, ���� ���? ���� �����-�� �����, ��� ���-�� ���?";
			link.l1.go = "spa_prisoner_25";			
		break;
		
		case "spa_prisoner_25":
			dialog.text = "� ����������������� ������������� �������� � ��������� �������� ������� � ������ ����������, ���� ��������. ������ ��� ��� ����� �������� - ������� �� ����. ��� ����� ��� ������ ����� � �������� ��� ����� �������, �� ���� ������...";
			link.l1 = "��������� ����������. ���� �������� ��� �������� ������ ������������ ��������, ��� ������� �� ���� � ������, � ��� �� ����� ��������� ����� � ������ ������, ������� � ��� ��������...";
			link.l1.go = "spa_prisoner_26";			
		break;
		
		case "spa_prisoner_26":
			dialog.text = "�� �� �� ������ ����� ���� ������ �����... �� �� �� ������ ��� ������� � ������. �����-�� ������ �� �����������, �� ������ ������ ������, �� ������ � ��� �����. �������, ��� �� ���� ������ �� ��������. ������� �� ���� ������� ����������� � �����������.";
			link.l1 = "������. �� ������� ����� �����������, "+npchar.name+", � � ��� ������� ������. �� ��� ��� �����������. � ����... ����� ������� �������� � ���������������� ���� �����...";
			link.l1.go = "spa_prisoner_27";			
		break;
		
		case "spa_prisoner_27":
			DialogExit();
			pchar.questTemp.Guardoftruth = "think";
			LAi_CharacterDisableDialog(npchar);//������ �������
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto3", "GuardOT_MCthink", -1);
		break;
		
		case "spa_prisoner_28":
			PlaySound("VOICE\Russian\Ransack_2.wav");
			dialog.text = "��� �������? �� ��������� ���� ��������?";
			link.l1 = "� ������ �������� ���� ��������. ������� ��� ���������� ����, "+npchar.name+". �� ������������� �� ���� �� ����, � ��������. ��������� � ������� ��� �� ��������. � ���� - ����� ���������� �� ����. ��� ����������� � ���� � �������� �� ��� �������.";
			link.l1.go = "spa_prisoner_29";			
		break;
		
		case "spa_prisoner_29":
			dialog.text = "���������, �������. ���, ��� �� ��������� ��������� �����.";
			link.l1 = "������������� ��������� �������. �� ����������� � ���� � �������� ���������, �� ��� ������: �� �� ����������, �� �� ��� ����� ������.";
			link.l1.go = "spa_prisoner_30";			
		break;
		
		case "spa_prisoner_30":
			dialog.text = "������ �� �����������, �������. ��� �����, ��� �� ����� ������� ������� � �������.";
			link.l1 = "���������� ��� �������. �������� �� �������.";
			link.l1.go = "spa_prisoner_31";			
		break;
		
		case "spa_prisoner_31":
			DialogExit();
			pchar.questTemp.Guardoftruth = "cuba";
			LAi_CharacterDisableDialog(npchar);//������ �������
			chrDisableReloadToLocation = false;//������� �������
			pchar.quest.GuardOT_exitbase.win_condition.l1 = "ExitFromLocation";
			pchar.quest.GuardOT_exitbase.win_condition.l1.location = pchar.location;
			pchar.quest.GuardOT_exitbase.function = "GuardOT_ExitFrombase";
			AddQuestRecord("Guardoftruth", "4");
		break;
		
		case "spa_prisoner_32":
			PlaySound("VOICE\Russian\Serve_senior.wav");
			dialog.text = "�������, � ����� ����� �� ������� �� ��������� ������? ������ ��� ����, ����� �������� ���� �����? �� ���� �� ��� ���������...";
			link.l1 = "������ ��� ����, ����� �������� ���. ������ ����� ����� �������� ���� ��������� ������, ��� ��� �������. �� ��� ��� ��� ������ ������� �� ��������. � ������ ��� ����� ������, ��� ������� ������, �� ��� ������� ����, ��� �� ����������� ��� � ���� �����.";
			link.l1.go = "spa_prisoner_33";			
		break;
		
		case "spa_prisoner_33":
			dialog.text = "� ��� ������ ����?";
			link.l1 = "������ - � ��� ��� ������������ ������, � �� ��������� ��� ����������� ��������, ���� ��������, ����� � ����. ���� �� �������, �� ���� � ��� ��� � ��� ������ - ����� �������� ������...";
			link.l1.go = "spa_prisoner_34";			
		break;
		
		case "spa_prisoner_34":
			dialog.text = "";
			link.l1 = "� ������ - �� �� ����������� ������� �������� ��� ����, ����� ���������� ����� ���� ��� ��������� ��� �������, �� ������� ����, ������. �� ��������?";
			link.l1.go = "spa_prisoner_35";			
		break;
		
		case "spa_prisoner_35":
			dialog.text = "� ��� ��?";
			link.l1 = "��, ��� ��. ��������� ��� ������� - � ��������� ��������.";
			link.l1.go = "spa_prisoner_36";			
		break;
		
		case "spa_prisoner_36":
			dialog.text = "� ������� ���, ������, ��� �������� ������ ���� �������� ����� � ����, � ����� � ���, ��� �� ����� ������������� ������� ��������, ������� ������ �������������� �������� ��������� �������� ������ ���. ������ �� ����������� - � ������ �����. � �������, � � ������ ������� � ����������� �����������.";
			link.l1 = "������, ��� "+GetFullName(npchar)+", � �������� ���� ������ � �������� ��� ����� ������. ���, �������� ������ ��� �����������. � ������ �� ��������.";
			link.l1.go = "spa_prisoner_37";			
		break;
		
		case "spa_prisoner_37":
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "��������, ������. �������, �� ����� ������� �� ���������� � ���� �� ���� �����. �������, ��� ��� ����� ������ ���������.";
			link.l1 = "��������, ������...";
			link.l1.go = "spa_prisoner_38";			
		break;
		
		case "spa_prisoner_38":
			DialogExit();
			RemovePassenger(pchar, npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			chrDisableReloadToLocation = false;//������� �������
			AddQuestRecord("Guardoftruth", "5");
			pchar.quest.GuardOT_mayak.win_condition.l1 = "Timer";
			pchar.quest.GuardOT_mayak.win_condition.l1.date.hour  = sti(GetTime()-(rand(4)));
			pchar.quest.GuardOT_mayak.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.GuardOT_mayak.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.GuardOT_mayak.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.GuardOT_mayak.win_condition.l2 = "location";
			pchar.quest.GuardOT_mayak.win_condition.l2.location = "mayak9";
			pchar.quest.GuardOT_mayak.function = "GuardOT_CreateVinsentoAgent";
			AddCharacterExpToSkill(pchar, "Leadership", 200);
		break;
		
		case "spa_prisoner_39":
			dialog.text = "�, ����� �������! ������������, ����� "+GetFullName(pchar)+"! ������, �� ����� �������� ������ � ��������. ��������� �� ��������� ����������?";
			link.l1 = "�����������, ������ "+npchar.name+". � �����, ��� �� ������ ������� �� ��������, � ��� - �� ����! ���, ������ ����� � ����� � ���� ��������. �� � �� ���? ������� ������ � ��������?";
			link.l1.go = "spa_prisoner_40";
		break;
		
		case "spa_prisoner_40":
			dialog.text = "����� ����, ��� �� ���������� ���� ��-��� ������, � ������������� ��� �������� ����������� � ��������... �� ��� ������, � ������� �����: ������� ������������� � ��� �����...";
			link.l1 = "��� ����� ���������, ��� �� ��������� ��������� �����.";
			link.l1.go = "spa_prisoner_41";
		break;
		
		case "spa_prisoner_41":
			dialog.text = "����������, �������, � �� ������ �� ����������, ��� ������� - �� �������? ������� �� �� �������, ��� ����� ���������� ����� ��������, �� �� - ����������.";
			link.l1 = "�� ���� ���������, � �� ������ �������� ��������� ����� �����. �������� � �������.";
			link.l1.go = "spa_prisoner_42";
		break;
		
		case "spa_prisoner_42":
			DialogExit();
			NextDiag.CurrentNode = "spa_prisoner_43"; 
			FreeSitLocator("Santiago_tavern", "sit_front4");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "Santiago_tavern", "sit", "sit_front4", "GuardOT_SpaOfficerInTavern", -1);
		break;
		
		case "spa_prisoner_43":
			LAi_SetSitType(Pchar);
			dialog.text = "��, �� �������, �������� ������, ����� �������!";
			link.l1 = "�� ��� ������, ������ ������?";
			link.l1.go = "spa_prisoner_44";
		break;
		
		case "spa_prisoner_44":
			dialog.text = "������� �� ���-������ �����������, �� ���������� ��� �����. ��������, �� ���������� � �������� ������ �������! ������� - �����!";
			link.l1 = "� ������� ��� �� ��, ����� ���� ������ �����-������ ������������ ���� � ������, � �������� � ��������� ���������� ������ �� ����������.";
			link.l1.go = "spa_prisoner_45";
		break;
		
		case "spa_prisoner_45":
			dialog.text = "������ �������, �������! �����!";
			link.l1 = "���... (����)";
			link.l1.go = "spa_prisoner_46";
		break;
		
		case "spa_prisoner_46":
			dialog.text = "���! �������� ����� � �������� ����������...";
			link.l1 = "��������. ����������, �� ������ �� ����������� �� ������ �� ���� �������� � ���� �� ������?";
			link.l1.go = "spa_prisoner_47";
		break;
		
		case "spa_prisoner_47":
			dialog.text = "���. ��� ��������� ������. � �����-������, ��� �� ���������� ������.";
			link.l1 = "� ��� ������ ��� ��������, ��� ���... �����, ��? ��� �� ��� ��������� ��������� �����? �����������?";
			link.l1.go = "spa_prisoner_48";
		break;
		
		case "spa_prisoner_48":
			dialog.text = "�, ���! ��� ������� ����� �� ������� �����������, ���� �� ��� ����� ��� ����� �� �������-�-����. ������, ��� ����� ������ ����� ��� � ��������. ������ �� ���-����.";
			link.l1 = "�� �� ���? �� ���� ��! ������, ��� �� �� ����������� - �����, ���� ����� �� ���������� ������� �� �����, ��-��!";
			link.l1.go = "spa_prisoner_49";
		break;
		
		case "spa_prisoner_49":
			dialog.text = "���� ����� ������ �� �� ���, �������. � ���� ���� ��������, ��� ��������� ������ �� �����. �� ������ � ������� ������ ���-�� �� �������� �����. � ������ �� ������ ������� � ������� � ��� �� ���� ������� �� �������.";
			link.l1 = "�� ���� � ��� �������?";
			link.l1.go = "spa_prisoner_50";
		break;
		
		case "spa_prisoner_50":
			dialog.text = "���. ������ � ������� � �������� ���-����, ��� �� ������-����. �� ����������� � ���� ������� � ����� �� � ������.";
			link.l1 = "��, ��� ������� ������ �� ���� ����� ����� ������, � ����� ��� ��� ����� ���� ������ �������.";
			link.l1.go = "spa_prisoner_51";
		break;
		
		case "spa_prisoner_51":
			dialog.text = "�������, �����. ��� ���� ��������� ����. �� �, �������, ��� ����. ������� - � �� �����.";
			link.l1 = "����������� ����, ������ "+npchar.name+". �����, ��� ���-������ ���������� � ����� ������ �����.";
			link.l1.go = "spa_prisoner_52";
		break;
		
		case "spa_prisoner_52":
			DialogExit();
			AddDialogExitQuest("GuardOT_SpaOfficerOutTavern");
		break;
		
		case "spa_prisoner_53":
			PlaySound("VOICE\Russian\other\OZGi-01.wav");
			dialog.text = "��� � ��� � �������, ��� �����: ����� ��������� ������� �������... ��� � ��� ��� �����������, �����. ������, �� � ������ ����������, ��� �� ������.";
			link.l1 = ""+npchar.name+"? �� ������, ������. � ������-�� �����, ��� �� ������� � ����������� ������. �������, ��������.";
			link.l1.go = "spa_prisoner_54";
		break;
		
		case "spa_prisoner_54":
			dialog.text = "������ �� ���������? � ���� ����� �������, � ��� � ������ ������ ��� �� ������. ������ �� ����������, ����� - �� ��-�������� ���� ������� � ��� ������ ����. ����� �� ��������, � ��� ��� ���� ��������, � ��� ������ ��� �� �������...";
			link.l1 = "��� ���? � ��� �� ��� �������, ��� ���� ��� �� ����� ������, ����� ��������� ������ � ��� ���� ������������ ���� �������� � ������� - ��� �������� �����, �� ��� �� ��������, ������ "+npchar.name+"?";
			link.l1.go = "spa_prisoner_55";
		break;
		
		case "spa_prisoner_55":
			dialog.text = "�� ������ �������� ���� ��������, ����������?!";
			link.l1 = "...";
			link.l1.go = "spa_prisoner_56";
		break;
		
		case "spa_prisoner_56":
			DialogExit();
			sld = CharacterFromID("Diego");
			sld.dialog.currentnode = "shore";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
		break;
		
		// �������� ��������
		case "vinsentoagent":
			PlaySound("VOICE\Russian\other\OZGi-02.wav");
			dialog.text = "��, ��! ��-��, ��! "+GetFullName(pchar)+"?";
			link.l1 = "� �����, ��������. ��� �.";
			link.l1.go = "vinsentoagent_1";			
		break;
		
		case "vinsentoagent_1":
			dialog.text = "���� ������ �� ������ ������� ��������. ��� ������, �� ����.";
			link.l1 = "����, ����. ����� ��� ����.";
			link.l1.go = "vinsentoagent_2";			
		break;
		
		case "vinsentoagent_2":
			GiveItem2Character(pchar, "specialletter");
			ChangeItemDescribe("specialletter", "itmdescr_specialletter_vinsento");
			sld = ItemsFromID("specialletter");
			sld.text = "Letter_Vincento";
			dialog.text = "�����. ��� ������ ���������� ����� �� �����?";
			if (sti(Pchar.money) >= 2000)
			{
				link.l1 = "������ ������� �������. �� ������ ��������� ���.";
				link.l1.go = "vinsentoagent_2_1";	
				AddCharacterExpToSkill(pchar, "Leadership", 50);
			}
			else
			{
				link.l1 = "�� ����, �������. ���� ��� ��������� �� ��� ��������.";
				link.l1.go = "vinsentoagent_2_2";
			}
		break;
		
		case "vinsentoagent_2_1":
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = "�������, �������. ������� ����� ���� � ������ ���������.";
			link.l1 = "���, ����� ����������, � �� ����� ������ � ���, ��� ����� ���������.";
			link.l1.go = "vinsentoagent_3";			
		break;
		
		case "vinsentoagent_2_2":
			dialog.text = "��������� ���� ���� �������...";
			link.l1 = "����? ��� �� �� ������...";
			link.l1.go = "vinsentoagent_3";			
		break;
		
		case "vinsentoagent_3":
			DialogExit();
			npchar.lifeday = 0;
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			chrDisableReloadToLocation = false;//������� �������
		break;
		
		// ������ ��� �����
		case "boatsvandega":
			dialog.text = "����������� �� ������ '���������������', ������� "+GetFullName(pchar)+"!";
			link.l1 = TimeGreeting()+"! ������� �� ������ - �� ���� ������?";
			link.l1.go = "boatsvandega_1";			
		break;
		
		case "boatsvandega_1":
			dialog.text = "�� ��� �� �� ����������� �������� �� ������ ��� �������� �� ����� "+GetFullName(pchar)+", ������������� �������� ��������� ������� �� ����� � �������� ��������, �������� �� ���� �� �����, � ����������� ���� ��������� ������! ��, ����� �������, ������������ �����!";
			link.l1 = "�� ����� ���, '�����'... � ������ ������, � �������� ���� ���� ����� ��������.";
			link.l1.go = "boatsvandega_2";
		break;
		
		case "boatsvandega_2":
			dialog.text = "����� �� ������ �������� �� �����, �, �������?.. ��, � �� � ������������� ������� �� ��� ����� � ����-��������, �� ��� ����: ������� �������� �������� ���� ����� ���� ��������, � � �� ���� ����� �������� ��������� ����������...";
			link.l1 = "��... ��� �� �� �������?";
			link.l1.go = "boatsvandega_3";
		break;
		
		case "boatsvandega_3":
			dialog.text = "� � ����� �� ��������? ��-��! ���, � ����� ���� ������, ���� ����. ��� ������� - ��� �����, ������ ����� ����� � �������, � �� ��� ������� ������ ����� �� �����, ������ ������� �����-�� '������'. ��� �������� ��������� ��������, �� � ��� ����, � ��� ������� ������ �� � ����... ���� ��� ������� ��� ������� ������!";
			link.l1 = "� ��� ����� ���������? ������� ��������� ������ � ������� ����� �� ����������, ����� ��� ��������?";
			link.l1.go = "boatsvandega_4";
		break;
		
		case "boatsvandega_4":
			dialog.text = "����� ��� - '��������'! ��� ������� � ����������, ��� ������ �������� � �������� ��� ���� ����� ������. � ��������� ��� ���: �� �������, ��� �� ��������� ����� �������� ���������� �������, ��������� � ������, � ��� ����� ���������� ��������. ��� �� � ����� ����� � ���������� ������� ���� �������! �����, ��� ������� �� ������ ���� �� ����, ���, ����� ������ ����!\n�������� ��������, �������, ���, ������ �� � ������� �������� ��������� ���������. ��� �� � ���� ���� '������', �������, ���������, �� ����� ��� ���� ���... ������ ����� ��� ����� � ������� � ������������� ���� ��������, ������ �������� �� ������� ��������. ��� ����� � �� ������ ���� �������, ���� �� ���� �������\n����� ��� - �� � ����� ������. ��������, ��� ��� � ��� ���� ������� ������� � ������� ������ �� ����� �� �������� ����... ������� ������, �� � ����� � ����.";
			link.l1 = "�� ��... � ���� �� ��� ������� ��� �����������?";
			link.l1.go = "boatsvandega_5";
		break;
		
		case "boatsvandega_5":
			dialog.text = "�� ������ ��� �� ������ - �� ������. ������ �� ��� ����������. ����� �� ��� ������ �����, ��� ��� �� - ���������� ���� ����������� �������������, ����� ��� � �����...";
			link.l1 = "��� ����, ����. �����, ������� - ��� � �������� ���... �������.";
			link.l1.go = "boatsvandega_6";
		break;
		
		case "boatsvandega_6":
			dialog.text = "��, �� ���� � � ������, �������. ��� �������? ��������, ���-������ ��� ����������, ������ ����... ��, ��� � ����� ���������!";
			link.l1 = "�����, ��������...";
			link.l1.go = "boatsvandega_7";
		break;
		
		case "boatsvandega_7":
			DialogExit();
			NextDiag.currentnode = "boatsvandega_8";
			npchar.DeckDialogNode = "boatsvandega_8";
			// ���������� �������
			sld = characterFromId("GOT_Gevarra");
			sld.Dialog.Filename = "Quest\Sharlie\Guardoftruth.c";
			sld.DeckDialogNode = "gevarra";
			AddQuestRecord("Guardoftruth", "16");
		break;
		
		case "boatsvandega_8":
			dialog.text = "��, �������, � ����� ������������� �� ����� �������� ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "boatsvandega_8";
		break;
		
		// ��� �����
		case "marshe_tavern":
			PlaySound("VOICE\Russian\tavern\Kontrabandisti-08.wav");
			dialog.text = NPCStringReactionRepeat("��! �� �������� �� �� ����������� ��������? ��, ��������, ������� ��, ���... ���������.", "� ���� ������ ��� ����������, �����, ��� ��� ������� ���� ������� �����������.", "��, ����� ��? �� ������� �� �����?!", "���...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� ������, �������, ������.", "����� ����, �������, � ���������� ����������...", "�� ���������, ��������, ��� ������ ��� ��������.", "�����-�����, �����.", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "marshe_tavern";
		break;
		
		case "marshe_lay":
			PlaySound("VOICE\Russian\citizen\convict-03.wav");
			dialog.text = "�-����... �-�... ���� ������, ��� �����?..";
			link.l1 = "����, ��������... �� ����...";
			link.l1.go = "marshe_lay_1";
		break;
		
		case "marshe_lay_1":
			PlaySound("VOICE\Russian\citizen\convict-02.wav");
			dialog.text = "�? ���?.. ���������!";
			link.l1 = "";
			link.l1.go = "marshe_lay_2";
		break;
		
		case "marshe_lay_2":
			DialogExit();
			LAi_SetgroundSitType(npchar);
			NextDiag.currentnode = "marshe_sitground";
		break;
		
		case "marshe_sitground":
			PlaySound("VOICE\Russian\EvilPirates07.wav");
			dialog.text = "�-���! ��� �� �����? ��� ���� �� ���� �����?";
			link.l1 = "������ ����� - ������ ������� �������� �� ������, ����? ��� ��������� ������, ������� �� ���������, ����� ����������� ���� �������?";
			link.l1.go = "marshe_sitground_1";
		break;
		
		case "marshe_sitground_1":
			dialog.text = "����� ������? � �� �������! ��� ��� �������!";
			link.l1 = "��� ��, ����... ��� �� ��� ����� �� ��� '����� ����������' � ����� ��� ��������� ������... ��� ��������� �������������, � ���� ���������? ������� ����������, ����� � ��������� � ������� ������? ���� �� �� ���? ������ ���, ������?";
			link.l1.go = "marshe_sitground_2";
		break;
		
		case "marshe_sitground_2":
			dialog.text = "���� �� ����... �� ��� �� -�������? � ���... �� �� �������! �� ��� ��� ����! �� �������� ������� ����������! ����� ����� ��� �������� ���� ���������? � ������ ���� �� �����, �� �������� �� ���� ��������� �������!";
			link.l1 = "�� �������? �� � ���� � �����, ��� �� ������ ����� ��� �������... ������ �� ������� ���� ��� ������, ����� �� ������, � ������ �� ��� � ������... �� ��� ����� ����������, ������. �� ��� ����������!";
			link.l1.go = "marshe_sitground_3";
		break;
		
		case "marshe_sitground_3":
			dialog.text = "��������� ����������! ���� ��...";
			link.l1 = "�������, ���... ��� ���. � ����� �� ���� ���, ����� ������ � �������� ����� ��� ������ �� ����.";
			link.l1.go = "marshe_sitground_4";
		break;
		
		case "marshe_sitground_4":
			DialogExit();
			RemoveAllCharacterItems(npchar, true);
			ChangeCharacterAddressGroup(npchar, "Deck_Galeon_Ship", "goto", "stand");
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			pchar.quest.GuardOT_marchfromgaleon.win_condition.l1 = "locator";
			pchar.quest.GuardOT_marchfromgaleon.win_condition.l1.location = "Deck_Galeon_Ship";
			pchar.quest.GuardOT_marchfromgaleon.win_condition.l1.locator_group = "reload";
			pchar.quest.GuardOT_marchfromgaleon.win_condition.l1.locator = "reload2";
			pchar.quest.GuardOT_marchfromgaleon.function = "GuardOT_ExitGaleon";
		break;
		
		// ������� ������� - ������ �������
		case "gevarra":
			dialog.text = "��� ��� ������, ������?";
			link.l1 = "��� ����, �������? ������ �������� � ���-����? ��, ��� � ������� - �������, ���� � ��� ����������� ������?";
			link.l1.go = "gevarra_1";			
		break;
		
		case "gevarra_1":
			dialog.text = "� � ��� ��������, ������? ��, � �������, ��� ����� ��������� �� ���� ����� ������� � �� ��������, �� � �������� ����� �� �������� ����������, � ���� ���� �������� ����������� ����-������� ��������, ��� ���...";
			link.l1 = "�� ��� �� �� ��� ����������, ������! ��� ��� ��� ����� ������, ��� �� �������... �������, �� ����� ��� ��������� ��� ���������?";
			link.l1.go = "gevarra_2";			
		break;
		
		case "gevarra_2":
			dialog.text = "� ������ �� ������ ����� � ������ ��� � ������� ��������. ������ ��� ��������� ������, ����� �� ���� ���������� �����.";
			link.l1 = "���� ������! ������, � ���� � ��� ������� �����������. �� ������ ����� ������� ����������, ���� �������� ���. �������? ������, ��� ���� ���?";
			link.l1.go = "gevarra_3";			
		break;
		
		case "gevarra_3":
			dialog.text = "������. ������� ������ �������. ����� �����������?";
			link.l1 = "��� ����� �������� ������� ������ ������ � ��������� �� �� ����, �������� �� ����� "+pchar.questTemp.Guardoftruth.LMname+", ��� ���������� ����� ��������. ������ � ���� � ���� �������� ��������� ���������. ��-������, ������� ������, ������� ��� �����, � �������� ���-���� ���...";
			link.l1.go = "gevarra_4";			
		break;
		
		case "gevarra_4":
			dialog.text = "";
			link.l1 = "��-������, ��� ����� ���������� ������������ �� ����-���������, � ����������, ������� � ��� �������. � ���� ��������� ���������, ���������? ������, ���� ������...";
			link.l1.go = "gevarra_5";			
		break;
		
		case "gevarra_5":
			dialog.text = "�������. ����� ������, ������. ���� ����� �� �����������. ��� ��� �� �� �� ���� ������?";
			link.l1 = "���������� ��� ����. ������ ��� ��� ������? � ���� ������ ����� ��� ������ ��� ������. �� ���� � ���, ��� ������� ������� �������� � ���� ������ ������, ��� ���� ����� �������� �������, ������� ������� ����� ��� ����, ���� �� �� �� ������ ����...";
			link.l1.go = "gevarra_6";			
		break;
		
		case "gevarra_6":
			dialog.text = "��, ������� ���� ��������� ���������� � ���� �����...";
			link.l1 = "������� - ��� ����, ��� ��� � �����! � �������� ������ � ���� ������ �� ������ ������ ���� - �� � ������-�� �� ������� � �������� - ��� �������������: �� ������ ���� � �����! ������, ��� ������� �� ������ ���������!";
			link.l1.go = "gevarra_7";			
		break;
		
		case "gevarra_7":
			dialog.text = "��-��-��! ��� ������ � ������������ ��������...";
			link.l1 = "���-���! � �������� ��� ��� � ������. ��, �������, ����������... �� ��� ����� ����� ��� ������! ������, � ���-���� �� ��������, � ��, ��� � ����, �� ���� ���� ������ �����, �� � ������� � ��� �������������...";
			link.l1.go = "gevarra_8";			
		break;
		
		case "gevarra_8":
			dialog.text = "";
			link.l1 = "��������� ����� ��������� ������ ������� ���� ��� - ��� �� ��� ��� ����� �� �������. � ����� ��������� �� ������ ������ ���� �� ����. ���� �� ������� ���� ���� - �������� ������� ����. � � �� ��� ��������� ���� ����� �� �������� - �� �������� ������ ���� � ���������� ����������...";
			link.l1.go = "gevarra_9";			
		break;
		
		case "gevarra_9":
			dialog.text = "������� �� ������ ��������� �� �����?";
			link.l1 = "� ������� �� ������?";
			link.l1.go = "gevarra_10";			
		break;
		
		case "gevarra_10":
			dialog.text = "�� �������� ��������� ����������... �������� ����� ����.";
			link.l1 = "��...";
			link.l1.go = "gevarra_11";			
		break;
		
		case "gevarra_11":
			dialog.text = "������, ��� ���� ���-���� �� ����... �������� ���� ����� � �� ������� ������.";
			link.l1 = "� ��������. �������� ������� ����� ��� �����, �� ��������� ���� ����� � �������. �������, ��� �������� ��������� ���.";
			link.l1.go = "gevarra_12";			
		break;
		
		case "gevarra_12":
			dialog.text = "� �� � ������ �������� ���� ����������� �����... � ��� � ������������ ��������, ��� � ��� ���� ���������� ����� � ���������, ���������� ������ �� ���������� �����... ����� ����� �� ������ ������� ���������� �� ������ �����.";
			link.l1 = "������, �� ������������?";
			link.l1.go = "gevarra_13";			
		break;
		
		case "gevarra_13":
			iTemp = sti(pchar.questTemp.Guardoftruth.VanilleQty)*210+25000;
			dialog.text = "�����������, ���� � ��� ���� ������ �� ������ ������ � �����. ��� � ��� � �����? ��������.";
			if (sti(Pchar.money) >= iTemp)
			{
				link.l1 = "���, ����������, ��������. ����� ������ �������. � �� ���������.";
				link.l1.go = "gevarra_14";
			}
			else
			{
				link.l1 = "��� � ���� � ������� �� �������. ������ �������!";
				link.l1.go = "gevarra_14_no";
			}
		break;
		
		case "gevarra_14_no":
			DialogExit();
			NextDiag.currentnode = "gevarra_wait";
			npchar.DeckDialogNode = "gevarra_wait";
		break;
		
		case "gevarra_wait":
			iTemp = sti(pchar.questTemp.Guardoftruth.VanilleQty)*210+25000;
			dialog.text = "�� �������� ������?";
			if (sti(Pchar.money) >= iTemp)
			{
				link.l1 = "���, ����������, ��������. ����� ������ �������. � �� ���������.";
				link.l1.go = "gevarra_14";
			}
			else
			{
				link.l1 = "��� ����!";
				link.l1.go = "exit";
			}	
		break;
		
		case "gevarra_14":
			if (stf(environment.time) < 24.0)
			{
				sTemp = "������";
				iTemp = 1;
			}
			else
			{
				sTemp = "�������";
				iTemp = 0;
			}
			if (stf(environment.time) > 21.0 && stf(environment.time) < 7.0)
			{
				dialog.text = "���������. ����� ����� ���� � ��������� ����������. ��������� "+sTemp+" ������� � ������ ���� - �����, � ����� ������� ��� ������ ��� '�������'.";
				link.l1 = "�������! �� �������!";
				link.l1.go = "gevarra_15";
				pchar.quest.GuardOT_tradetimer.win_condition.l1 = "Timer";
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.hour  = 10.0;
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, iTemp);
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, iTemp);
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, iTemp);
				pchar.quest.GuardOT_tradetimer.function = "GuardOT_PrepareTrade";
			}
			else
			{
				dialog.text = "���������. ����� ����� ���� � ��������� ����������. � ����������� �� �����. ��������� ���� ����� ��� - �����, � ����� ������� ��� ������ ��� '�������'.";
				link.l1 = "�������! �� �������!";
				link.l1.go = "gevarra_15";
				pchar.quest.GuardOT_tradetimer.win_condition.l1 = "Timer";
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.hour  = sti(GetTime()+3);
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
				pchar.quest.GuardOT_tradetimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
				pchar.quest.GuardOT_tradetimer.function = "GuardOT_PrepareTrade";
			}
		break;
		
		case "gevarra_15":
			iTemp = sti(pchar.questTemp.Guardoftruth.VanilleQty)*210+25000;
			DialogExit();
			NextDiag.currentnode = "gevarra_time";
			npchar.DeckDialogNode = "gevarra_time";
			AddMoneyToCharacter(pchar, -iTemp); // ������ ����� ���������
			bQuestDisableMapEnter = true;
			pchar.GenQuest.MapClosedNoBattle = true;
			AddQuestRecord("Guardoftruth", "17");
			AddCharacterExpToSkill(pchar, "Sneak", 50);
		break;
		
		case "gevarra_time":
			dialog.text = "������, � ��� �����. �� �����������, �������� �� ���� ������ � ���� ����-���������.";
			link.l1 = "������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "gevarra_time";
		break;
		
		case "gevarra_16":
			dialog.text = "�� �������, ������, ��� �� ���� � ������. ������� ��� ����� ���, ��� � ������ ���������� ������ ��� ������. � ���� �� ���� ��������, ����� � �������� ��� �����. ���������� ������ ��������� ������ � ������� � ����� ������� - ������, ��� ��� ����� �����, ���� �� ���������� ��������� �������� �������� �����\n��� ������ ���� ����� � ���� �� ����� - ����� �� ���� �� ���� ������� � ��������. � ��������� ������ ���������� � ������. ���-������ ��� ��������?";
			link.l1 = "��. ��� ��� ������. ��������, ������ ����� � ����� ������� ������ � �������? ������, � �� ������ ������ ���� ����������, � ���� ����������� �� ��������...";
			link.l1.go = "gevarra_17";
		break;
		
		case "gevarra_17":
			Log_Info("�� �������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "������ ��� ��������, ������. � ������ ���� ����. � � ���� �� � ���� ��� ������� � ���� ���������. �� ������ �������� - ��������, ��� ��������� �����.";
			link.l1 = "���������. � ����� ��� �����. ����� � ������ �������� �� �������, � ��� ������ �� ����������� � ���� - ���� �� ����� �����.";
			link.l1.go = "gevarra_18";
		break;
		
		case "gevarra_18":
			DialogExit();
			NextDiag.currentnode = "gevarra_exit";
			npchar.DeckDialogNode = "gevarra_exit";
			bQuestDisableMapEnter = true;
			pchar.GenQuest.MapClosedNoBattle = true;
			pchar.GenQuest.CannotWait = true;//������ ��������
			AddQuestRecord("Guardoftruth", "18");
			pchar.quest.GuardOT_gotoshore.win_condition.l1 = "ExitFromSea";
			pchar.quest.GuardOT_gotoshore.function = "GuardOT_TradeComplete";
		break;
		
		case "gevarra_exit":
			dialog.text = "�������, ������ ���� �������: � �� ������� � ������� ������� ������ �������� � ��������.";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "gevarra_exit";
		break;
		
		// ������� �����
		case "marshe_sailor":
			dialog.text = LinkRandPhrase("�-��! �-�����-��� �����-��� ���-��� ���������! ���!","� �-��� ������ �-�����... ��!","����� �� ����... ���� ��� �����... ��-��-��, � ������� ����-�!");
			link.l1 = LinkRandPhrase("�� ��... ��-��.","����... ���� ���������� � ���� �����, �� ��������?","������� ������...");
			link.l1.go = "exit";
		break;
		
		case "galeonguard":
			PlaySound("VOICE\Russian\EvilPirates01.wav");
			dialog.text = "����! ��� �� ��� �������? �������! �� ������ ����!";
			link.l1 = "...";
			link.l1.go = "galeonguard_1";
		break;
		
		case "galeonguard_1":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.CantRun");
			CheckAndSetOverloadMode(GetMainCharacter());
			DeleteAttribute(pchar, "questTemp.Guardoftruth.Attack");
			LAi_RemoveCheckMinHP(pchar);
			GuardOT_GaleonGuardFightAdd();
			for (i=1; i<=8; i++)
			{
				sld = characterFromId("GuardOT_galeonguard_"+i);
				LAi_SetWarriorTypeNoGroup(sld);
				LAi_group_MoveCharacter(sld, "GaleonFight");
			}
			LAi_group_FightGroups("GaleonFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		// ��������� � �����
		case "dominica_hunter":
			dialog.text = "��-��! �� ���� �� ������ ����� ������� ������? � �� �� ��� ������ ����, ����, ����� �� ������. � ���� �� ���� �� ���� ������� ��������� ������� � ����� �� �������!";
			link.l1 = "�� �� ����� ���������� �����, ���?";
			link.l1.go = "dominica_hunter_1";
		break;
		
		case "dominica_hunter_1":
			dialog.text = "������, � ���� ��������� � '������� �����'. �� ���� ��� ����� �������������, � ������ - �� � ����. ���� ��� ������ ������� ������ �� � ����. �� ����� ��� ���� ����, �� ��� ���� �� ������ ������ �������� �������...";
			link.l1 = "�� �� �� ������� ���, � ������ - ������� ���... ��� �����. ��� ���� �����?";
			link.l1.go = "dominica_hunter_2";
		break;
		
		case "dominica_hunter_2":
			dialog.text = "��, � �������, ��� � ������... �������!";
			link.l1 = "�������� ������� ������, �����?";
			link.l1.go = "dominica_hunter_3";
		break;
		
		case "dominica_hunter_3":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			for (i=1; i<=8; i++)
			{
				sld = characterFromId("GuardOT_DH_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_HuntersDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		// ������� ������
		case "belinda":
			dialog.text = TimeGreeting()+", ������. ��� ��� ������?";
			link.l1 = "�����������. ���� ��� �� - ����� ������� �� ������?";
			link.l1.go = "belinda_1";
		break;
		
		case "belinda_1":
			dialog.text = "��, ��� �. � ��� ���� ����� �������������?";
			link.l1 = "������� "+GetFullName(pchar)+", ��������. �� ����� ��� �� ��������� ��� �������������� - � ������ ������ � �������� ������� ��� ��������������, ����������� ��������, ���� ��������.";
			link.l1.go = "belinda_2";
		break;
		
		case "belinda_2":
			dialog.text = "��� ���������! � �������, ��� ����� ������� ������ ������ ���� ����� ������ ����, ���� �������� � ���������������, �� �� ��� ��� �� ���� �� ������������ �� � ��� �� ��� ��� ������. ��� ���� ������ ���, ������?";
			link.l1 = "� ��� ���� ����, ������� ����� ���������� ��� ��������������. ��� ������� ����������, ��������� �����, ������������� ���� ������� � ����� ���������� � �����������.";
			link.l1.go = "belinda_3";
		break;
		
		case "belinda_3":
			dialog.text = "�� ������ �����������, ������. �������, ����, ��� ��, ��� �� ������ ���� ��������. ��, � ��������� ���� ������ ����������, ��� ��� ������ �� ����� � ����� �������� ��������, ����������� �������� �������� ������� � ��������.";
			link.l1 = "����� � ���, ��������?";
			link.l1.go = "belinda_4";
		break;
		
		case "belinda_4":
			dialog.text = "��. � ������ �������� ��� � ��� ����� ������, �� ��� �� ���� ������� ����� ����������... � ��� � �� ������... ��, �������� ����...";
			link.l1 = "�� �������, ��������? ��� ����� ��� ���-�� ��������? ����� ���� ��������...";
			link.l1.go = "belinda_5";
		break;
		
		case "belinda_5":
			dialog.text = "�� ��� ��, ������... ������� �������� � ������ ���������. ��� � �������, ���� ���������� ����� ���� ��������? �� ������, ����� � ��� ��� ������?";
			link.l1 = "���� ����������� ����� �������������� ��� ������� ��������, �� ��� �������� ������� � ������ ���������� � ����������� ������� ���������� ��������� ������. ��� ������ - ������� ���������� ����, ��� ��� �������� ����. ����������, � ��������� ����������� ���� �������.";
			link.l1.go = "belinda_6";
		break;
		
		case "belinda_6":
			dialog.text = "��, ��������... ������� �� �������, ��� ��� ��� ������ ��� ������? � �������� ���, ����� ������ ������ ������, � ��� ��������� ������� ���� ����� �� �������������, ��� �����, ����� ������ ������, ��������� ���� ��������. ��... ���� �����, �� �� �������� ���� � ����?";
			link.l1 = "�� ����������� �������, ��������. ��� � ��� ���������?";
			link.l1.go = "belinda_7";
		break;
		
		case "belinda_7":
			dialog.text = "������ ���? ��, ������... � � �� ����� ��������� �� ������ �� ������ �����-�������...";
			link.l1 = "����������, ��� ��� ��������?";
			link.l1.go = "belinda_8";
		break;
		
		case "belinda_8":
			dialog.text = "�� ������ ��������� ���, ��� ������������� ������ ������, ��� ����� � ������� �� ������ ����, � ��� � ��� �������?";
			link.l1 = "��� �����, �������.";
			link.l1.go = "belinda_9";
		break;
		
		case "belinda_9":
			dialog.text = "������. � ���� ���. ��� ����� ������� ��������, ������� ����, ����� � ���� - ��� �������� ������� � ������� ����� � ��� ����� ����. � ���� ��� ����� �����, ��� ������� ������� ����� ���� ��������, � ������� ������ ��� �� � ����\n����� ����, � ����� ��������� ��... �����, � �������� ������� - �������, ������� �����, ��� ����� ����� ������������ � ���������, ���� �� �� ����� �� ����������. ���� �� ��, �������� �������, ���� ������ ������, ������ �� ���-�� ��������� �������� ������ �������� �� ��������� ����� � ����������, ����� �� ������� ���...";
			link.l1 = "����� � ��� ������ ���������� �����?";
			link.l1.go = "belinda_10";
		break;
		
		case "belinda_10":
			dialog.text = "�� ������� �� ������ ����� ������� ������, ��� ��� ����� ����� ������ �� �������� ������ ���� � ����������� ������ �� �������� � ����� � ������ � ��������...";
			link.l1 = "�����-�� ��������� �������...";
			link.l1.go = "belinda_11";
		break;
		
		case "belinda_11":
			dialog.text = "������, ��� ��������, ��� � �� ���� ������� ��� ����� ������, ������� � ��������� ������ ����� �������... �� � �� ����� ����� ����� �����, ������� �� �����!";
			link.l1 = "�� �������, ��������, � �������� ��� ������. ����� ������ ������ �� �������� ������� � ���� ������������� �������.";
			link.l1.go = "belinda_12";
		break;
		
		case "belinda_12":
			dialog.text = "� �� ����� �� ��� ���������... ��, �������, ����� ������� ����� ������, ��� ���� ��������� ������ �� ����, ��� � �������� � ���������� - �� ��� ���������� ����� ��������...";
			link.l1 = "� ���� ���.";
			link.l1.go = "belinda_13";
		break;
		
		case "belinda_13":
			dialog.text = "���, ��������. ����� ��������� �����. ��������� ���� �������� ����� ���� ���, �������, ��� � ���� ��� ������ �� ����! ������� ��������! � � � �������� ����� ��� ���������� ��� ���� ��������.";
			link.l1 = "� ������ ��� ���������, ��������. ����� ��������� �� ������.";
			link.l1.go = "belinda_14";
		break;
		
		case "belinda_14":
			dialog.text = "����� ��� �������, �������� �������!";
			link.l1 = "...";
			link.l1.go = "belinda_15";
		break;
		
		case "belinda_15":
			AddMoneyToCharacter(pchar, 50000);
			DialogExit();
			NextDiag.CurrentNode = "belinda_16";
			AddQuestRecord("Guardoftruth", "31");
			bQuestDisableMapEnter = true;//������� �����
			locations[FindLocation("Cumana_CaveEntrance")].DisableEncounters = true; //��������� �������
			LAi_LocationDisableOfficersGen("Cumana_CaveEntrance", true);
			LAi_LocationDisableOfficersGen("Cumana_Cave", true);
			pchar.quest.GuardOT_gotocave.win_condition.l1 = "location";
			pchar.quest.GuardOT_gotocave.win_condition.l1.location = "Cumana_CaveEntrance";
			pchar.quest.GuardOT_gotocave.win_condition.l2 = "HardHour";
			pchar.quest.GuardOT_gotocave.win_condition.l2.hour = 23.00;
			pchar.quest.GuardOT_gotocave.function = "GuardOT_InCaveEntrance";
		break;
		
		case "belinda_16":
			dialog.text = "� ��� ���� �����-������ �������, �������?";
			link.l1 = "���� ���. �����, �������, � �� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "belinda_16";
		break;
		
		case "belinda_17":
			dialog.text = "� ��� ���� �����-������ �������, �������?";
			link.l1 = "��, �������. � �����, ��� �� ����� ��� ��������.";
			link.l1.go = "belinda_18";
		break;
		
		case "belinda_18":
			dialog.text = "�������� ��, �� ������! �� ����������� � ���������?";
			if (sti(Pchar.money) >= 50000)
			{
				link.l1 = "�������� ����� ���� ��������� �����. ��� ��� �� ������������. � ����� ��� ���� ��������. �� ������ ���, ��� � �������?";
				link.l1.go = "belinda_19_1";
			}
			link.l2 = "�������� ��� ���� ��������, �������. �� ������ ���, ��� � �������?";
			link.l2.go = "belinda_19_2";
		break;
		
		case "belinda_19_1":
			RemoveItems(pchar, "jewelry29", 1);
			PlaySound("interface\important_item.wav");
			AddMoneyToCharacter(pchar, -50000);
			dialog.text = "���... ��, ������. ��� � ���������?";
			link.l1 = "� ���������� � ��������� � ������. ����� ������� � ������� ���� - ���� � �� �� ����. �� ������������ ���������, ����� �������� �� ��� ������. �� ��������� � �����... �����. ������ ����� � ��, ��� ����� �� ������ ��� ������. ������� � ����� �� ��� ���������. � ������ � ���� ���� �������� � �������� ��������������.";
			link.l1.go = "belinda_20";
		break;
		
		case "belinda_19_2":
			dialog.text = "���... ��, ������. ��� � ���������?";
			link.l1 = "� ���������� � ��������� � ������, ��� ��� �����������, �������� ���� � ������� ���� ������. ����� ������� � ������� ���� - ���� � �� �� ����. �� ��� ������������ ���������. �� ��������� � �����... �����. ������� �������� ���� � ����� ���� �������� ��� ��������������. �� ������, ��� ������ �� ������ ��� ������ � �����.";
			link.l1.go = "belinda_20";
			npchar.quest.nomoney = true;
		break;
		
		case "belinda_20":
			if (CheckAttribute(npchar, "quest.nomoney")) sTemp = "";
			else sTemp = "� ���������� ������� ���, �� ������� �� ����, �� �������� � ���.";
			dialog.text = "���� ���, ���� ���! � �� ���� ����� ����! �� ��� ��� ��� ���, �� ���? ��� � ��� �������, ��� �� ���...";
			link.l1 = "�������, � ����� ��� - �� ����������. ���� ������� �� ����� ���� ����� ����� ��������. "+sTemp+"";
			link.l1.go = "belinda_21";
		break;
		
		case "belinda_21":
			if (CheckAttribute(npchar, "quest.nomoney")) sTemp = "";
			else sTemp = "� ����� ����, ��� ���� ������� �� ���� ��������.";
			dialog.text = "��... � ���������� �����������. ������, � ������ ������������� ��� �� ���� ������. ���, �������� ��� ����������. "+sTemp+" ����� ��� ���.";
			link.l1 = "�������, �������. �� ������������: ��� ����, ��� ��������� � ������, ����� �� ������. ������ ������ ������ ������ ������ ���� �����. � ������ ��������� �����������.";
			link.l1.go = "belinda_22";
		break;
		
		case "belinda_22":
			DialogExit();
			AddQuestRecord("Guardoftruth", "33");
			bQuestDisableMapEnter = false;
			DeleteAttribute(pchar, "GenQuest.CannotWait");
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 3;
			GiveItem2Character(pchar, "jewelry33");
			Log_Info("�� �������� ������� ����������");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.nomoney"))
			{
				ChangeCharacterComplexReputation(pchar, "nobility", -3);
				OfficersReaction("bad");
			}
			else
			{
				Log_Info("�� �������� ������");
				GiveItem2Character(pchar, "amulet_7");
				ChangeCharacterComplexReputation(pchar, "nobility", 5);
				OfficersReaction("good");
				ChangeCharacterNationReputation(pchar, SPAIN, 3);
				AddCharacterExpToSkill(pchar, "Leadership", 300);
			}
		break;
		
		// ������ ��������
		case "bandos_mush":
			PlaySound("VOICE\Russian\other\OZGi-04.wav");
			dialog.text = "���� ��� ������, ��������!";
			link.l1 = "��� ����.";
			link.l1.go = "bandos_mush_1";
		break;
		
		case "bandos_mush_1":
			dialog.text = "������ ������?";
			link.l1 = "������ ������. ����� ����� � ���� ������, ��� �������?";
			link.l1.go = "bandos_mush_2";
		break;
		
		case "bandos_mush_2":
			dialog.text = "������� �� ���� ������, ������? ����� � ������, ����� ��� ��������.";
			link.l1 = "�� ������ � ������� ������? ������� �������... �����-�����, ��� ���.";
			link.l1.go = "bandos_mush_3";
		break;
		
		case "bandos_mush_3":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			LocatorReloadEnterDisable("Cumana_CaveEntrance", "reload2_back", true);
			LAi_SetWarriorType(npchar);
			LAi_CharacterDisableDialog(npchar);
			pchar.GenQuest.CannotWait = true;//������ ��������
			pchar.quest.GuardOT_incave.win_condition.l1 = "location";
			pchar.quest.GuardOT_incave.win_condition.l1.location = "Cumana_Cave";
			pchar.quest.GuardOT_incave.function = "GuardOT_InCumanaCave";
		break;
		
		// �������-�����
		case "barty":
			PlaySound("VOICE\Russian\other\OZGi-03.wav");
			dialog.text = "����� �� ���� ���������� ��������... ������ ��� ����?";
			link.l1 = "��� �� - ����� �������? ������ �� ����� �� �������� �������...";
			link.l1.go = "barty_1";
		break;
		
		case "barty_1":
			dialog.text = "���� ����, �� ���� � �����? ��� ������?";
			link.l1 = "� ��� �������?";
			link.l1.go = "barty_2";
		break;
		
		case "barty_2":
			dialog.text = "����� ���� �������. ����� ���� ������ � �� ��� ����!";
			link.l1 = "�����, � ���, ����� �� ������? ���� � �� ����� �������� ���� � ������ �������, ������� ����� �� �� �������. ��� ��?";
			link.l1.go = "barty_3";
		break;
		
		case "barty_3":
			dialog.text = "��, �� ��� �����������? �� �����, ������ �� ���� ���������� �������... ������, ������� ���� ����� ������!";
			link.l1 = "��� �����!..";
			link.l1.go = "barty_4";
		break;
		
		case "barty_4":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			GuardOT_InCumanaCaveEnemyAdd();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("GOT_bandos_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_CumanaCaveBandosDie");
			AddDialogExitQuest("MainHeroFightModeOn");
			// �������� ��������
			LAi_LocationDisableOfficersGen("Cumana_Cave", false); //�������� �������
			DoQuestFunctionDelay("GuardOT_SetOfficerCumanaCave", 3.0);
		break;
		
		case "barty_5":
			PlaySound("VOICE\Russian\other\Plennie-02.wav");
			dialog.text = "";
			link.l1 = "�� ���, �����, ����������? ��� ������� ����? ��, �������, ��� ���� ������ ���� � ����, ���� �� �������������!";
			link.l1.go = "barty_6";
		break;
		
		case "barty_6":
			dialog.text = "�� ������... �� ����. � � ���� ������� ����.";
			link.l1 = "���?..";
			link.l1.go = "barty_7";
		break;
		
		case "barty_7":
			dialog.text = "��-��, � ������� �� ����� �������. � ������...";
			link.l1 = "�� �� ��������! ������, �� ������ ����� �������� �� ������� ��� �����, '�������' ������ ����?";
			link.l1.go = "barty_8";
		break;
		
		case "barty_8":
			dialog.text = "����� ���� ��� ������� �������. �������... ��� ������������� ��� ����������� �� ����� �������, �� � �� ��� ����� ������������...";
			link.l1 = "��� ��� �����! �� ���������?";
			link.l1.go = "barty_9";
		break;
		
		case "barty_9":
			dialog.text = "��� ���. � ������ ������ �� ���.";
			link.l1 = "� ����� ������ ���������� ������� �� ������, ���? ��� ����. �� � ��� �� ��� � ����� �������? ������� � ���� ������ �� ��, ��� ������� ����� ����?";
			link.l1.go = "barty_10";
		break;
		
		case "barty_10":
			dialog.text = "� �� ����� �����, �������!";
			link.l1 = "� ������� �������� �� ���� ����� �����������?";
			link.l1.go = "barty_11";
		break;
		
		case "barty_11":
			dialog.text = "�� �� ������ ����������� ���� �������, � ���!";
			link.l1 = "������, ��� �� ���� ��� � ������ ��������� ���� �� ���� ��� ������ �������. �� �� �������� � ���������� �������, ������� ����� ��������� ��������� � �����, � ����� �� ������. � �������� ���� � ���, � ����� ��� �����������, ��� � ����� ������...";
			link.l1.go = "barty_12";
		break;
		
		case "barty_12":
			dialog.text = "������ �� ���! � �� ����� � ������!";
			link.l1 = "������������� ������� �������� � ���� ������?";
			link.l1.go = "barty_13";
		break;
		
		case "barty_13":
			dialog.text = "��������, ������! ��������� ����, � ������ ������ ������ � ������� ����� �� �������� � ������! � �� ��������� ����������, ���� ��� ������� ��������� ���� �� ����� ��� �������� �������� ������...";
			link.l1 = "�����. ���� ����� ����� �� ������� ������� � �� ������ ���� � ���. �� ���� �� �����, ��� � ������� ��� � ����� - ��� ������, � ����� ������ �� �������� ����������� � ���� �����. ��� � ���� ���� �� �����, ������� ��� ������ ��������?";
			link.l1.go = "barty_14";
		break;
		
		case "barty_14":
			dialog.text = "���... ��� ���� �������� � �������. ��� ���� �������� ��� ���.";
			link.l1 = "�����������. ����� ��� ���� � ���������� � ���� ����!";
			link.l1.go = "barty_15";
		break;
		
		case "barty_15":
			DialogExit();
			GiveItem2Character(pchar, "jewelry29");
			Log_Info("�� �������� �������� � �������");
			PlaySound("interface\important_item.wav");
			chrDisableReloadToLocation = false;//������� �������
			LAi_LocationDisableOfficersGen("Cumana_CaveEntrance", false);//�������� �������
			locations[FindLocation("Cumana_CaveEntrance")].DisableEncounters = false; //��������� �������
			locations[FindLocation("Cumana_Cave")].DisableEncounters = false; // patch
			LAi_LocationFightDisable(&Locations[FindLocation("Cumana_CaveEntrance")], false);//��������� �������
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			LocatorReloadEnterDisable("Cumana_CaveEntrance", "reload2_back", false);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", -1);
			npchar.lifeday = 0;
			sld = characterFromId("GOT_Belinda");
			sld.dialog.currentnode = "Belinda_17";
			AddQuestRecord("Guardoftruth", "32");
		break;
		
		// ��������
		case "spa_hunter":
			dialog.text = "� ���� ���� ��, ��� ��� �����, ��������...";
			link.l1 = "��. ���� ��... � ��� �� ��� ����� ����?";
			link.l1.go = "spa_hunter_1";
		break;
		
		case "spa_hunter_1":
			dialog.text = "�� � � ��� �� ����, ��������. ��� ������ ������ ������� ��� ���� ����, ��������� ���, ��� ������� ��� ����. ��� ������, ��� ��������� ������?";
			link.l1 = "�������. ������, �� ������������� �� ������, � ��� ��������. � ����� ��� �� �� ������� �� ��������� ������.";
			link.l1.go = "spa_hunter_2";
		break;
		
		case "spa_hunter_2":
			dialog.text = "�� �� ��������, ����������, ��? ��� ��, ������ ���������, ������ ����� ���� �������!";
			link.l1 = "������ ��, ��� � ����, �������... � ������ �� � ���� ���������.";
			link.l1.go = "spa_hunter_3";
		break;
		
		case "spa_hunter_3":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			for(i=1; i<=5; i++)
			{
				sld = characterFromID("GOT_santiagoband_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_SantiagoBandDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "cabin_hunter":
			dialog.text = "��-��, ��������, � ��� � ��... ���� ����������� �������! ������ �������� - ���������� ���. ��?";
			link.l1 = "�� ��� �� ��� �� ��������� �����! ���� ���� ���������... ��� ��� �����, ���� ������?!";
			link.l1.go = "cabin_hunter_1";
		break;
		
		case "cabin_hunter_1":
			dialog.text = "�� ���� ����. ������ �������� - ������� ������� � ������ �����. ��� ���� ����� �����������?";
			link.l1 = "� ��� ���� ����������� ������ ����� ������?";
			link.l1.go = "cabin_hunter_2";
		break;
		
		case "cabin_hunter_2":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			for(i=1; i<=2; i++)
			{
				sld = CharacterFromID("GOT_cabinband_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_CabinBandosDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		// �������� ������������
		case "batabano_officer":
			dialog.text = "���� ����� ����������, �������!";
			link.l1 = "������������ ����� ������� � ������� ���� ���-�������. �� ����� ������, ����� ��� ����� �����. ��������� � ������ � ����� ����� � ������ ��������. � ����������� ���� �����. ������� ������� ����������� �� �������?";
			link.l1.go = "batabano_officer_1";
		break;
		
		case "batabano_officer_1":
			dialog.text = "����� ����� ����� ����� ���, �������!";
			link.l1 = "������. ������!";
			link.l1.go = "batabano_officer_2";
		break;
		
		case "batabano_officer_2":
			DialogExit();
			LocatorReloadEnterDisable("Shore13", "boat", false);
			for(i=1; i<=10; i++)
			{
				sld = characterFromID("GuardOT_Oursoldier_"+i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "OpenTheDoors", 20.0);
			}
			AddQuestRecord("Guardoftruth", "48");
			// �� ���
			pchar.quest.GuardOT_sanantonio.win_condition.l1 = "Ship_location";
			pchar.quest.GuardOT_sanantonio.win_condition.l1.location = "Shore15";
			pchar.quest.GuardOT_sanantonio.function = "GuardOT_SanantonioArrive";
			// �� �����, ���������� ��� �������, �� �������� ������� � ��
			pchar.quest.GuardOT_sanantoniotimer.win_condition.l1 = "Timer";
			pchar.quest.GuardOT_sanantoniotimer.win_condition.l1.date.hour  = sti(GetTime()+6);
			pchar.quest.GuardOT_sanantoniotimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.GuardOT_sanantoniotimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.GuardOT_sanantoniotimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.GuardOT_sanantoniotimer.function = "GuardOT_SanAntonio_Timer";
		break;
		
		// ������� ���������
		case "housemercen":
			dialog.text = "��� ������� �������! �� ���� ���... ���� ���� �������� ������ ��������. �����, ������ � ���� ������, ���������...";
			link.l1 = "...";
			link.l1.go = "housemercen_1";
		break;
		
		case "housemercen_1":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			bDisableCharacterMenu = false;//�������� F2
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			if (MOD_SKILL_ENEMY_RATE < 5) LAi_group_SetCheck("EnemyFight", "GuardOT_HouseMercenDie");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}