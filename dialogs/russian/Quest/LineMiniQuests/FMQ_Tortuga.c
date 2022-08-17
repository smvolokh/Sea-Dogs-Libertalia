// Addon-2016 Jason, ����������� ���������� (���) �������
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "girl":
			PlaySound("VOICE\Russian\Girls_1.wav");
			dialog.text = "��, ������������, �����! ����� ���������� �� �������! ������� ��� �������� ����� ��������� ��������, ��� ��...";
			link.l1 = "����������, �����������. ������� �� ������ �����. �� ��� ���? ��� ��������, ��� ��������� �������� ������� ����������� ������ ������ ��������� ����������� ������� ���� ����� ��������� ����.";
			link.l1.go = "girl_1";
		break;
		
		case "girl_1":
			dialog.text = "��, �����... �� ������� � ����� �����, ���� ���? �� ��� ��� ��������, ����� ����������� �������, ��� �� ��� �� ������. �� ���� �� �������������, ��� ������ ���������� ��������� ������ �� ��� � �������������� ������. ����� �� ����� ��...";
			link.l1 = "��� ���� ������ ����� ���������� �������?";
			link.l1.go = "girl_2";
		break;
		
		case "girl_2":
			dialog.text = "��-��. ����� �� ��������� � ��� ����� � ����� ������ �������? � ������� ��� ���� ���� ����������� ��������� ���������� ������������ ������. ����� ����� ������� ���������� �� ����� ����� ����������� �����������. �� �������? ����������, ���������, �� ����� ��� ��� ����.";
			link.l1 = "����� �� �����, �����������. � ����������� ������� � ���.";
			link.l1.go = "girl_3";
			link.l2 = "����� ���� ��������, �����������, �� ������� ���� �� ��������� ��� ��������������� ����� ������������.";
			link.l2.go = "girl_exit";
		break;
		
		case "girl_exit":
			dialog.text = "����� ����. �������� ����� �������... �����������. ��������.";
			link.l1 = "����� �������.";
			link.l1.go = "girl_exit_1";
		break;
		
		case "girl_exit_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "none", "", "", "", 40.0);
			npchar.lifeday = 0;
			FMQT_ClearChest();
			SetFunctionTimerCondition("FMQL_Start", 0, 0, 5, false);
		break;
		
		case "girl_3":
			dialog.text = "�� ����� ��� ����! ������� ���! ������, ����� �� ������. ��-��. �� ������� � ����� ������!";
			link.l1 = "�� �������...";
			link.l1.go = "girl_4";
		break;
		
		case "girl_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "none", "", "", "", 40.0);
			npchar.lifeday = 0;
			pchar.questTemp.FMQT = "begin_serveroom";
			FMQT_Begin();
			AddQuestRecord("FMQ_Tortuga", "1");
			SetFunctionTimerCondition("FMQL_Start", 0, 0, 5, false);
		break;
		
		case "girl_5":
			PlaySound("VOICE\Russian\Girls_1.wav");
			dialog.text = "������, ���������! ����� ����� ������ ������� ������� � ��� ����.";
			link.l1 = "� ���� ������, ��������. ��� ������, ���� �� ��� ���-���� ��������. ��� - ����, �� ��� ���������� ������ ��������� ����� ���������� ���������� ������������ ��� �������� ����� ����� ����.";
			link.l1.go = "girl_6";
		break;
		
		case "girl_6":
			dialog.text = "��-��. �, ��. ������� ������ ���� ��� ����������. � ��� ����. ���� �����, ���, ���� �������, ��������� ��� �������, ��� ��� ������� �������� ������ ������ � ����, ������� ������� �������. ����� �������! � �� �� ����?";
			link.l1 = "��� �� ����?";
			link.l1.go = "girl_7";
		break;
		
		case "girl_7":
			dialog.text = "��-��. �������� ������� �������.";
			link.l1 = "����������. � �� �������. � ����. ����������?";
			link.l1.go = "girl_8";
		break;
		
		case "girl_8":
			dialog.text = "���� �����. � ������� ��������� �� ������ ������ �����������. ������� � ����� ������ � ������ �� ������ �����. ���������� ��� � �������� � ����� ������������, ������?";
			link.l1 = "��-��. � ���������� �������������, ������. � ������ � ��������. ���� � ����� ������ � ���.";
			link.l1.go = "girl_9";
			link.l2 = "� ������? � ����������� �� ������? � ���, ��������, ���� �������� ���� ��������, ����� ���� � �������.";
			link.l2.go = "girl_exit_2";
		break;
		
		case "girl_exit_2":
			dialog.text = "��-�. �� � �����, ����� ��� ������� ������������. ������, ������.";
			link.l1 = "���-���, ����...";
			link.l1.go = "girl_exit_1";
		break;
		
		case "girl_9":
			dialog.text = "����� ����� � �����������!";
			link.l1 = "...";
			link.l1.go = "girl_10";
		break;
		
		case "girl_10":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "none", "", "", "", 40.0);
			npchar.lifeday = 0;
			pchar.questTemp.FMQT = "begin_bedroom";
			FMQT_Begin();
			AddQuestRecord("FMQ_Tortuga", "2");
		break;
		
		case "wife":
			PlaySound("VOICE\Russian\Dama03.wav");
			dialog.text = "� ��� � ��! ������� "+GetFullName(pchar)+"! � ��� ���� ��� ������, ��, ����� � ���� � ������ �� ���� ������ ������������ � ���������� �������, ��� ��!";
			link.l1 = "���� ����� � ����� �������� - ������� ����� � ������������ ��� ����, �����. � ��� ��� ��������� �����? � ����?";
			link.l1.go = "wife_1";
		break;
		
		case "wife_1":
			dialog.text = "��� ����� � ������ ������ �������. ������� ���� ���� � ��������. ��, �� ������, ��� ������ � ������� ��� �����! ��� �� ������� � ��������! ��������! �������-�� � ����� ���� ������� � ���������� �������! ��, ���� �� ������ ��� ��� ��� ���� � ������ ����� �������� � ������ ������! ������ �����! � �� ������� � ����� ������, ������� ������ � ���� ��� ����� ��� ����������? ��� �� ������ �� ���� �������?";
			link.l1 = "� ��� ���������, ��������? � �������? ��� � �������?";
			link.l1.go = "wife_2";
		break;
		
		case "wife_2":
			dialog.text = "�� ��� ���� ���������! ���� �� �������. ������ ���� �����������, �� ��� ��� ���� ��� �� ����� ������ �����, ���� ��� ����� �� ����� ������� ��������! ������! � ��������� ���������� ������ ����� �����, � ���� ����, �� ����� ����� ���� ����� ������� ������ ��� ��������! ��� � ���� ������� ������ ��� ������ �� ������ ������! ��� �� �������, � ���� �� � ��� ���������?";
			link.l1 = "�� � ��� ���������, �����. ��� �� ����� ������ �� ������, ��� � ��� �������� ��� ���� ������ ����� �������������� �������.";
			link.l1.go = "wife_3";
		break;
		
		case "wife_3":
			dialog.text = "�� ��� ����� �� ���... �������, ��������� ��� ����������, �� � ���� ����. �� �� �������� ���������� �������, ������?";
			link.l1 = "�������, �����. ��, ��� ������.";
			link.l1.go = "wife_4";
		break;
		
		case "wife_4":
			PlaySound("VOICE\Russian\Dama02.wav");
			dialog.text = "������ ���������, ����� �������, � �� � ���� �������� ������. ��-��. ��� �� ��� �������... ��� ��� �� �������� ��� �� ������� ��������� �����, ���� �������� ����� � ���� ��������� ������ � ������ ����� ��� ����\n� ����� ����, ��� �� ������ ��������� ����� ����� �������� � ������� � ����� ��������. ��� � ��� ������. �� ����� ���� � �� ����� �������. �������� ��� �������� ��, ��� ��� ����������� � ������ �������������... ������� �... ��� �����.";
			link.l1 = "���... ���������� �����������. ������, �����, � ��� ������. ��� ���� ������ � ��� ��� �������?";
			link.l1.go = "wife_5";
			link.l2 = "������, ���������, � ������ ���������� �������. �� ������� ������ � ����� ������� �������� �����. ����� ������� �� ������ ���������? ��� ���� ������� � ��� ��� �������?";
			link.l2.go = "wife_6";
			link.l3 = "��������, �����, �� ����� �� �������� ��� ������� �����. � ��� ����������, �� ������������ ��������, �� ��� �������� ����� ���� ������� �����������.";
			link.l3.go = "wife_exit";
		break;
		
		case "wife_exit":
			dialog.text = "����. � ����� ������, ��� ������ �� � ��� ��������, �����. ������� � ���������: �� ������ ���������, ���� ���������� �� ���� ����� ����!";
			link.l1 = "����� �������.";
			link.l1.go = "wife_exit_1";
		break;
		
		case "wife_exit_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			DeleteAttribute(pchar, "questTemp.FMQT.Common");
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			pchar.questTemp.FMQT = "huber";
			pchar.quest.FMQT_late1.win_condition.l1 = "Timer";
			pchar.quest.FMQT_late1.win_condition.l1.date.hour  = 18.0;
			pchar.quest.FMQT_late1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQT_late1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQT_late1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQT_late1.function = "FMQT_HuberTime";
			AddQuestRecord("FMQ_Tortuga", "4");
		break;
		
		case "wife_5":
			pchar.questTemp.FMQT.Honour = "true"; // ��� 1
			dialog.text = "... � �� ������� �� ��� ������... ������... ��� �����, ������� ����� ������� �������� �����, ������� �������� � ����� �������� ������. �� ������ ����� � ������� ������� � ����������, ��� ��������. ������������ � ������� ��� ��������. � ���� ��� �����.";
			link.l1 = "����� �� ���� ������ �������!";
			link.l1.go = "wife_7";
		break;
		
		case "wife_6":
			pchar.questTemp.FMQT.Bed = "true"; // ��� 2 
			dialog.text = "�� �� ��������� �� ����, �������. � �� ���������� �����, ����� ������� �� ������ ���������? ������� ����� ������� �������� �����, ������� �������� � ����� �������� ������. �� ������ ����� � ������� ������� � ����������, ��� ��������. ������������ � ������� ��� ��������. � ���� ��� �����.";
			link.l1 = "����� �� ���� ������ �������!";
			link.l1.go = "wife_7";
		break;
		
		case "wife_7":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "FMQT_PirateInTavern", 10.0);
			pchar.quest.FMQT_late2.win_condition.l1 = "Timer";
			pchar.quest.FMQT_late2.win_condition.l1.date.hour  = 0.0;
			pchar.quest.FMQT_late2.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQT_late2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQT_late2.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQT_late2.function = "FMQT_TavernTime";
			AddQuestRecord("FMQ_Tortuga", "6");
		break;
		
		case "wife_8":
			PlaySound("VOICE\Russian\Dama03.wav");
			dialog.text = "������� "+GetFullName(pchar)+"! ����� ������� � � ���� � �������! ��������? ������ ������ �� ���������. ��-��.";
			link.l1 = "�������, �����. �� � ���������� �� ������. �����������? ��� � ��� �� ��� ���� ������� �����������?";
			link.l1.go = "wife_9";
		break;
		
		case "wife_9":
			dialog.text = "����� �����! ����� ������ ������. � ���� ���� � ��� �����������, �������. ���� ����������, �� � ����� ������ ��� �������������.";
			link.l1 = "�����������.";
			link.l1.go = "wife_10";
		break;
		
		case "wife_10":
			dialog.text = "��... � ����� ���� ���� ������ � �������� � ������� ������������. � �������� ��� � � ���������� ������ ����.";
			link.l1 = "�� � ��� ���������, �����. ��� �� ����� ������ �� ������, ��� � ��� �������� ��� ���� ������ ����� ����������� �������.";
			link.l1.go = "wife_11";
		break;
		
		case "wife_11":
			dialog.text = "�� ��� ����� �� ���... �������, ��������� ��� ����������, �� � ���� ����. �� �� �������� ���������� �������, ������?";
			link.l1 = "�������, �����. ��, ��� ������.";
			link.l1.go = "wife_12";
		break;
		
		case "wife_12":
			PlaySound("VOICE\Russian\Dama02.wav");
			dialog.text = "������ ���������, ����� �������, � �� � ���� �������� ������. ��-��. ��� �� ��� �������... ��� ��� �� �������� ��� �� ������� ��������� �����, ���� �������� ����� � ���� ��������� ������ � ������ ����� ��� ����\n� ����� ����, ��� �� ������ ��������� ����� ����� �������� � ������� � ����� ��������. ��� � ��� ������. �� ����� ���� � �� ����� �������. �������� ��� �������� ��, ��� ��� ����������� � ������ �������������... ������� �... ��� �����.";
			link.l1 = "������. ������. ��� ���� ������ � ��� ��� �������?";
			link.l1.go = "wife_13";
			link.l2 = "��! ���� ����� �������, � ������ ���. �� �� ���������, ��������. �� ������� ������ � ����� ������� �������� �����. ��� ���� ������� � ��� ��� �������?";
			link.l2.go = "wife_14";
			link.l3 = "���, ��������. ��������� �����������? � ����� �� ���������, � ���� � ���������, �� �� � ����� �����. ����� ���� ������� �����������.";
			link.l3.go = "wife_exit_2";
		break;
		
		case "wife_13":
			pchar.questTemp.FMQT.Honour = "true"; // ��� 1
			dialog.text = "��... �� ��� ��������� �� ������ � ������... ������� ����� ������� �������� �����, ������� �������� � ����� �������� ������. �� ������ ����� � ������� ������� � ����������, ��� ��������. ������������ � ������� ��� ��������. � ���� �����.";
			link.l1 = "����� �� ���� ������ ���� �� �����!";
			link.l1.go = "wife_7";
		break;
		
		case "wife_14":
			pchar.questTemp.FMQT.Bed = "true"; // ��� 2 
			dialog.text = "����� ���� � �����, �����. ��-��.  ������� ����� ������� �������� �����, ������� �������� � ����� �������� ������. �� ������ ����� � ������� ������� � ����������, ��� ��������. ������������ � ������� ��� ��������. ����������?";
			link.l1 = "������������? �� ������! � ��� �� ���� � �������.";
			link.l1.go = "wife_7";
		break;
		
		case "wife_exit_2":
			dialog.text = "�����! ����� � ���� ����! � ���� �� ����� ���������� �� ���� ����� ����! �� ���������!";
			link.l1 = "����, �����.";
			link.l1.go = "wife_exit_1";
		break;
		
		case "wife_15":
			PlaySound("VOICE\Russian\Dama03.wav");
			pchar.quest.FMQT_late3.over = "yes";
			dialog.text = "�������! �� ������� ��������?";
			link.l1 = "��. �� � ����. ��� ������?";
			link.l1.go = "wife_16";
		break;
		
		case "wife_16":
			dialog.text = "�, ����! ������� ���� �������� ������� �� ��������! �� ����������� �������, �������! � ��� ������� ������� �������, �� ���� ��� ������? �������� ��� ������. � ���� �� ������. ��������� ������ � ��� ���� �������. �� �� ���������, ��� �������...";
			link.l1 = "������. ���� �� ������. � ����������� ���� ����� ����������� ���.";
			link.l1.go = "wife_17";
			link.l2 = "���, � �� ���� �����, � ������� �������. �������, ��� ���� ������� � � ��� ������. � �� ���� ��������� ����� ��������� ������� ��������� ���� ���������� �����.";
			link.l2.go = "wife_18";
		break;
		
		case "wife_17":
			RemoveItems(pchar, "kaleuche_key", 1);
			ChangeItemDescribe("kaleuche_key", "itmdescr_kaleuche_key");
			dialog.text = "��������� ���� � ����� ������, ��� ������...";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQT_Deceive");
		break;
		
		case "wife_18":
			dialog.text = " �� �������? ��� ����� �����������. ����� ��� ����� ����, ��� �������? �����������, ���� ���!";
			link.l1 = "������. ���� �� ������. � ����������� ���� ����� ����������� ���.";
			link.l1.go = "wife_17";
			link.l2 = "� ������ �����. ��� ����� ������?";
			link.l2.go = "wife_19";
		break;
		
		case "wife_19":
			dialog.text = "�������!.. ����� � ������� ����� ����. � ��� � ������ �� �������� �������� ���� ��������. � �������� ������ �� �����. ���, � �������... ����������. �����... ��������� �� � ������������� �� ���. � ���� �����. �� �� �������� ������ �������, � ��� ����...";
			link.l1 = "� ����� �������.";
			link.l1.go = "wife_20";
		break;
		
		case "wife_20":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("FMQ_Tortuga", "11");
			sld = &Locations[FindLocation("Tortuga_townhallRoom")];
			sld.private2.key = "kaleuche_key"; // ������ � �������
			pchar.questTemp.FMQT = "chest";
		break;
		
		case "wife_21":
			pchar.quest.FMQT_GemsTimeOver.over = "yes";
			PlaySound("VOICE\Russian\Dama01.wav");
			dialog.text = "��, �������! �.. ��... �� ����������? �, � ��� ���?! �-�!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQT_MercenAttackRoom");
		break;
		
		case "wife_22":
			dialog.text = "�, ����! �������, �� ���� ������! ��... �� ��� �������! ��� ��� ��������� ����� ����, �� ����� ����� ����! � ������� ��� �� ������ �����! �� �����? �� ������ ����������?";
			link.l1 = "��. ���� ���? � ��� ��� �� �������� ���������� �������... �� � ���� � ���. ������� � ����.";
			link.l1.go = "wife_23";
		break;
		
		case "wife_21x":
			pchar.quest.FMQT_GemsTimeOver.over = "yes";
			PlaySound("VOICE\Russian\Dama01.wav");
			dialog.text = "��, �������! �.. ��... �� ����������?";
			link.l1 = "���� ���� ��������� �������������, �� ��� ���������. �� ���-�� ����������, �����. �� ������? ���������� � ����, ��� �������� ��� ����������, ���� ������?";
			link.l1.go = "wife_23";
		break;
		
		case "wife_23":
			dialog.text = "����� ����! � �������! ��� ������! ������� ��� ����?";
			if (GetCharacterItem(pchar, "jewelry2") >= 100)
			{
				link.l1 = "��� ������ �������� �� ������ � ������� �������. � �� ������� ����� ���� �������� �� ������ ������ �� ������, ��� � ������.";
				if (CheckAttribute(pchar, "questTemp.FMQT.Honour")) link.l1.go = "wife_25";
				else link.l1.go = "wife_26";
			}
			else
			{
				link.l1 = "��� ���� ��� ����� ��������� �������� - �������, �� �� �� �������� �� ������. �� ��������� �� ��� �������� ������, �����! � �� �������, � ����� � ����� ������ �������? � ��������� ��� - ���� ������� ����� ������, ��� �� ��������. ��� ��� ���� ����...";
				link.l1.go = "wife_24";
			}
		break;
		
		case "wife_24":
			dialog.text = "������! �������! ��� ���� ����� �� �������!";
			link.l1 = "��-��...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQT_FinalNoJewelry");
		break;
		
		case "wife_25":
			RemoveItems(pchar, "jewelry2", 100);
			Log_Info("�� ������ 100 �������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� �� ����� ���... ��� ���������. �� ����������� ����, ��� ������. � ��� �������� �������, ��� ���� �������, ��... �������� �� ���� ��� �������? ��� ����� �� ��������, ������.";
			link.l1 = "��� ����� ������� � ���� ������ ���� �����. ������� ����?..";
			link.l1.go = "wife_sex";
		break;
		
		case "wife_sex":
			DialogExit();
			pchar.questTemp.HorseQty = sti(pchar.questTemp.HorseQty) + 1;
			DoQuestCheckDelay("PlaySex_1", 1.0);
		break;
		
		case "wife_26":
			RemoveItems(pchar, "jewelry2", 100);
			Log_Info("�� ������ 100 �������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�����, � �������� � ��� ���. ����� ���� �� ��� ��������� ������. �� ������� ������� �������� � ��������� ������... ������� �� ��, �������. � �� ����� ��� ��� ����, ����� ��� ��� ��� ��������� � ������, ���� �� �� ����� ������ �������, �� �� ������? ��������.";
			link.l1 = "���� ���. �����������. ��������, �����, ������� ��� ���� �������, ������ ��� � �� ����� ������� �������. �� �� �� � ��� �� ���� ������?";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQT_FinalNoSex");
		break;
		
		case "wife_27":
			PlaySound("VOICE\Russian\Girls_2.wav");
			dialog.text = "��� �� ����� � ��� ��� ����� � ���� �������?";
			link.l1 = "��... �� �� �������������� � ���� � �������� �������, � �����...";
			link.l1.go = "wife_28";
		break;
		
		case "wife_28":
			dialog.text = "�� � ���, �����? � �������� �������, � ����������� �������� ������ �� ��������! ���������� �������� ��� ������, ����� � ������ ���� � ������!";
			link.l1 = "�� ��� ��� �� ������! �� ������, ���� ������� ��� ���� ������!";
			link.l1.go = "wife_29";
		break;
		
		case "wife_29":
			dialog.text = "���� �� ���������� �� ���������, ������, ��� �������� � ����� ����� � ������ ������ ���������� �� ����! � ���� ������ ���� �� �������. ���!!";
			link.l1 = "...";
			link.l1.go = "wife_30";
		break;
		
		case "wife_30":
			DialogExit();
			DoQuestReloadToLocation("Tortuga_town", "reload", "reload3", "FMQT_FinalFail");
		break;
		
		case "pirate":
			PlaySound("VOICE\Russian\tavern\Pyanici-03.wav");
			pchar.quest.FMQT_late2.over = "yes";
			FreeSitLocator("Tortuga_tavern", "sit_base1");
			dialog.text = "�� ���? �, �������. �� ���� �����, ��������. ���� ����� ����� �� ��� ����� ���� ������� �� ��� ������ ����-����-��-���������. ������, ������!";
			link.l1 = "� �������������!";
			link.l1.go = "pirate_1x";
		break;
		
		case "pirate_1x":
			DialogExit();
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "sit", "sit_base1");
			LAi_SetSitType(pchar);
			npchar.Dialog.currentnode = "pirate_1";
			LAi_SetActorType(npchar);
			LAi_ActorSetSitMode(npchar);
			LAi_ActorDialogDelay(npchar, pchar, "", 2.0);
		break;
		
		case "pirate_1":
			PlaySound("VOICE\Russian\tavern\Pyanici-05.wav");
			dialog.text = "���� ���������? �������!!";
			link.l1 = "�� ���� ��������!.. ��������, ��������, ������ �� ����. ��� ����� ��������, �� ��� ������ �����. ����� ��� ��� � ����������: �� ���������� ����, � � �������� �������� ����� � ����.";
			link.l1.go = "pirate_2";
		break;
		
		case "pirate_2":
			dialog.text = "�������, � �� ��������� �����, ��� ���� �� ����� ����. ��������� �� ��� ������? � �� ������, ��� � ���? � ���� �����, ��� ����. �������� ������� ������ ������ ���� ������� ������ ������-�� ���������� ������� �� ��, ��� ��� �� ������ �������� �������� ��� ����. � ��� ���� ���� �������� ������ ���������� � ��� ���������\n�������� ����������. � ��� �������� ������������� �� ������ � ������ ������ �����. ���� �� �� ����� ���������� �����... � �� ������� �� ���� �������. � �����!";
			link.l1 = "�� ��� ����� ��������, �� ����� � ����. ��� ��������?";
			link.l1.go = "pirate_3";
		break;
		
		case "pirate_3":
			dialog.text = "�� ���� �� ��������?! � ������ �� � ����! ��� ������� ��� ������, ��� ��� �� ����������! ����� ��� ������� ����� ����� � ��������, � ����� � ����� ������� ��������. ������ ��������? �������. � �� ��������, ����� ������, ��� ������ ���� ������ ����� �� �����������.";
			link.l1 = "������, � �� ����. �� ������� ��� ���� �������� �������. ������� �� �����, ����� � ����!";
			link.l1.go = "pirate_4";
			link.l2 = "�������? ����? �� ���� � ������ ���. ����� �� ������� ������ � ���� ���� �����. �������, ������� ��������� ���� �� ������� � �������� �� ����������� � ��� ��������. � � ���� �� �������. ������� ��������, ����� ����������.";
			link.l2.go = "pirate_5";
			link.l3 = "�������?";
			link.l3.go = "pirate_6";
		break;
		
		case "pirate_4":
			dialog.text = "���-���� ������� ���� ������� �� �������. ���������� �������, �������. �����. �������, �� ������� ������� ���� ���������, ������� �������.";
			link.l1 = "�����, ��������...";
			link.l1.go = "pirate_exit";
		break;
		
		case "pirate_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "tables", "stay3");
			LAi_SetPlayerType(pchar);
			pchar.questTemp.FMQT = "huber";
			pchar.quest.FMQT_late1.win_condition.l1 = "Timer";
			pchar.quest.FMQT_late1.win_condition.l1.date.hour  = 18.0;
			pchar.quest.FMQT_late1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQT_late1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQT_late1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQT_late1.function = "FMQT_HuberTime";
			AddQuestRecord("FMQ_Tortuga", "9");
		break;
		
		case "pirate_5":
			dialog.text = "��-�? ������!";
			link.l1 = "����!!";
			link.l1.go = "pirate_duel";
		break;
		
		case "pirate_duel":
			DialogExit();
			LAi_SetSitType(npchar);
			// ���� ��������� �� ������� - ������� �����
			GiveItem2Character(npchar, "kaleuche_key");
			ChangeItemDescribe("kaleuche_key", "itmdescr_kaleuche_key_FMQT");
			i = makeint(MOD_SKILL_ENEMY_RATE/4);
			pchar.questTemp.FMQT = "duel";
			PChar.questTemp.duel.enemy = NPChar.id;
			if (MOD_SKILL_ENEMY_RATE > 2) PChar.questTemp.duel.enemyQty = i;
			AddDialogExitQuestFunction("Duel_Prepare_Fight");
		break;
		
		case "pirate_6":
			dialog.text = "������� �� �������, ����� ���� �������... �����, � ���� � ���������. ��������� ��������. �� ����.";
			link.l1 = "��������� ��������? ����? ����������. ��������. �� ����.";
			link.l1.go = "pirate_7";
			if (GetCharacterItem(pchar, "gold_dublon") >= 50)
			{
				link.l2 = "���������... �����. �����.";
				link.l2.go = "pirate_8";
			}
			else
			{
				link.l2 = "���������... �����. ������ � �������. ����, ������ �� �����!";
				link.l2.go = "pirate_wait";
			}
		break;
		
		case "pirate_wait":
			DialogExit();
			LAi_SetSitType(npchar);
			npchar.Dialog.currentnode = "pirate_dublon";
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "tables", "stay3");
			LAi_SetPlayerType(pchar);
		break;
		
		case "pirate_dublon":
			dialog.text = "������ ��������� ��������?";
			link.l1 = "������, � �������, ��� �� ����������. ��������. �� ����.";
			link.l1.go = "pirate_7";
			if (GetCharacterItem(pchar, "gold_dublon") >= 50)
			{
				link.l2 = "��. �����.";
				link.l2.go = "pirate_8";
			}
			else
			{
				link.l2 = "��� ����!";
				link.l2.go = "exit";
			}
		break;
		
		case "pirate_7":
			dialog.text = "���������?";
			link.l1 = "...";
			link.l1.go = "pirate_duel";
		break;
		
		case "pirate_8":
			RemoveItems(pchar, "gold_dublon", 50);
			Log_Info("�� ������ 50 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�������. ���� ���� ����� �� ��������, �� ������� �� ����� ����� � � ��������. ����� �������� � �����. ����� ����������. ������� ������ ��������� ����, ��� ������, �� ������� ���� ������. �� ������� ��. ����� ���� � ����� � ����� �� ��������� � ������ ����. ��������� �� �� �������, ������ ���� ��������� � �� �������� � ����\n� ���, � �� � ������� ���� ������. ������� - ���� ��������. ��� �������� � ����������. �� ���� �������. ����� � ����, ����.";
			link.l1 = "�����, ��������...";
			link.l1.go = "pirate_9";
		break;
		
		case "pirate_9":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			LAi_Fade("", "");
			ChangeCharacterAddressGroup(pchar, "Tortuga_tavern", "tables", "stay3");
			LAi_SetPlayerType(pchar);
			pchar.questTemp.FMQT = "key";
			pchar.questTemp.FMQT.Caution = "true";
			FMQT_KeyNextDay();
			pchar.quest.FMQT_late3.win_condition.l1 = "Timer";
			pchar.quest.FMQT_late3.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.FMQT_late3.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQT_late3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQT_late3.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQT_late3.function = "FMQT_KeyTime";
			AddQuestRecord("FMQ_Tortuga", "10");
			// ���� ��������� �� ������� - ������� �����
			GiveItem2Character(pchar, "kaleuche_key");
			ChangeItemDescribe("kaleuche_key", "itmdescr_kaleuche_key_FMQT");
		break;
		
		case "mercen":
			PlaySound("VOICE\Russian\EvilPirates10.wav");
			dialog.text = "�������! �� ������... ������� ����! ������� ��� ��������� - �� ����������� � ������, ��� ���. �� ������ ���� ������. � ���� ��� �� �������!";
			link.l1 = "���-���, ��������... ������, ��� � ���� ������� ������, �� �����, ��� � �������. ����� ��� �������? ����� ������? ��� ����. ������ �� �������, ��� � ������� ����� �����. ����, �����, ��������� � ������� ���� ������. ��� �������?";
			if (sti(pchar.rank) > 5 && GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) > 15 && GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 15) link.l1.go = "mercen_1";
			else link.l1.go = "mercen_4";
		break;
		
		case "mercen_1":
			dialog.text = "� �� ���� ��� ��������� ������, �, ���? ���� � ���� ��������, ������ �� �������. �����, � � ����. ��� ���� �������� ����������?";
			link.l1 = ""+pchar.ship.name+". ����� ���������� �� ����!";
			link.l1.go = "mercen_2";
		break;
		
		case "mercen_2":
			dialog.text = "��-��. � ������ ������� ������������. ��� ���� ������ ����� �� ����, ���.";
			link.l1 = "...";
			link.l1.go = "mercen_3";
		break;
		
		case "mercen_3":
			DialogExit();
			LAi_group_Delete("EnemyFight");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "FMQT_MercenHire", 10.0);
			AddQuestRecord("FMQ_Tortuga", "17");
		break;
		
		case "mercen_4":
			dialog.text = "������ �����. �� ������������ ������ ��� ����, ����� �������� � ���� �� ������ �������������. ���� ��� � �������. ���� ��������.";
			link.l1 = "�� ��������. ������ ���������, � ���� �������� � �����.";
			link.l1.go = "mercen_5";
			link.l2 = "������� ����� �� �����. � ���� ��� ���� ���, ��� ��� ����� �� ����� ������ ������� ���. ���� �� ��������� ������ ������ �� ��� ������, ����� �������� ���� ������� �����. ��� ���� ��� ���� �� ���������?";
			link.l2.go = "mercen_6";
		break;
		
		case "mercen_5":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "FMQT_MercenDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "mercen_6":
			dialog.text = "��� �� ����. ���� ��� ��� ����� �� ������, � ���� ��� ���������. �����, ��� ������...";
			link.l1 = "...";
			link.l1.go = "mercen_7";
		break;
		
		case "mercen_7":
			DialogExit();
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_group_Delete("EnemyFight");
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 10.0);
			AddQuestRecord("FMQ_Tortuga", "18");
			pchar.questTemp.FMQT.Roomfight = "true";
			FMQT_WifeFinalTalk();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
