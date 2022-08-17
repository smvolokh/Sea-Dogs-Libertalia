// Addon-2016 Jason, ����������� ���������� (���) ����-���������
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
		
		case "seafox":
			PlaySound("VOICE\Russian\military01.wav");
			dialog.text = TimeGreeting()+", �������. ��������� ������������� - ��������� "+GetFullName(npchar)+", ������� ������, ����-�����, �������. ���� ���������� � ��� � �������� �� �������� ������.";
			link.l1 = "������������, ���������. ��� ��� "+GetFullName(pchar)+". ������ ���� ������ ��� ���������?";
			link.l1.go = "seafox_1";
		break;
		
		case "seafox_1":
			dialog.text = "��������� � ���� ������ ��������� ��������. � � ������� ���� ����������� ����������� �� ����-������ � ������� ������� ����-������� ��� ���������� �������. �� ���� �����, �� ����� ������� �� ����������, �������� �������� ���������� �����. � ���� ������ �� ������ �������, ������ ������� ���� ����, ���� ��������� �������� ���� � ������ ����� �����, � �����������. � ����� ������������, ��� �� ����� ������ �������� �������, � �� ������� ����� ������� ������ ����� ���� �������\n��� � ���� ����� ������ ������ ��������� ������� �� ����-�������, � ����� ����� ����. ������� ������, �������, ��������� ��� ����� � ��������� �����, � ��� ����� ������. ��� �� ������ �����, ��� ��� ����, ��� ���� ������� ��� �������� �����. ���� ������ ����� ����� ��������.";
			link.l1 = "������� ������� �� ����������� �������? ��...";
			link.l1.go = "seafox_2";
		break;
		
		case "seafox_2":
			dialog.text = "���������, ��� ��� ��������� �� ������. �� ������ �������� ��� � ����� � ���. �� ���, �� �����?";
			link.l1 = "������, � ��������, ����� ������������� ��������. ��� ������ ������?";
			link.l1.go = "seafox_3";
			link.l2 = "����� �������� ����, �� � ����������� ������ � ������ �������, � �� ����� ������.";
			link.l2.go = "seafox_exit";
		break;
		
		case "seafox_exit":
			dialog.text = "��� �������, �������. ���� ������ ������ �����. ����� �������!";
			link.l1 = "��������, ���������.";
			link.l1.go = "seafox_exit_1";
		break;
		
		case "seafox_exit_1":
			DialogExit();
			chrDisableReloadToLocation = false;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			npchar.lifeday = 0;
			SetFunctionTimerCondition("FMQP_Activation", 0, 0, 5, false);
		break;
		
		case "seafox_3":
			GiveItem2Character(pchar, "purse2"); 
			Log_Info("�� �������� ������ ��������");
			dialog.text = "������ ����� ����. ��� �������.";
			link.l1 = "������. ��������� ����� ����� � ������������ �� ���� - �� ����� �������.";
			link.l1.go = "seafox_4";
		break;
		
		case "seafox_4":
			dialog.text = "��� �����, �������!";
			link.l1 = "...";
			link.l1.go = "seafox_5";
		break;
		
		case "seafox_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "FMQN_SailMaarten", 10.0);
			AddQuestRecord("FMQ_Nevis", "1");
			pchar.questTemp.FMQN = "begin";
			SetFunctionTimerCondition("FMQP_Activation", 0, 0, 5, false);
		break;
		
		case "seafox_6":
			PlaySound("VOICE\Russian\QuestMan04.wav");
			dialog.text = "��������� �� ��������, �������! ������, � ���������, � �� ���� ������ � ���� ��������� ������������: � ������ ������� � ������� ����-�������� ������ �� ����-������, ��, ��� ������, ��� ���. �������� ��� ����� ������� � ������: ����������� �� ���-��� ��� � ���� �����, � ����� �� �������� - ��������� ��� �� �������. ��������� ���� �� ������ ��������� �� ������ ����� �����.";
			link.l1 = "��... �, �������, ����������� �� ������...";
			link.l1.go = "seafox_7";
		break;
		
		case "seafox_7":
			dialog.text = "� ������� ���, �������, �� ���: � ���� ��� ����� �����, ����� ���, ��� � ����� ���. ������, ��� �� ������� �� �������� ������ ������ �� ��� ����� � ������� � ������� ����-��������.";
			link.l1 = "����. ������ � ���� ���. ������, ���������...";
			link.l1.go = "seafox_8";
		break;
		
		case "seafox_8":
			dialog.text = "�������. �� ������������ � ����� �������. ���� �������� �� ��������� �����, ��� �� ��� ���.";
			link.l1 = "�����, ���...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_EnglishmanGo");
		break;
		
		case "seafox_9":
			PlaySound("VOICE\Russian\QuestMan04.wav");
			dialog.text = "���... ����������� �������! � �����, �� ������ ������ �� ����� � ����� ����� ����, �������...";
			link.l1 = "���� �� ������: ��������� ������ ������� � ������� ����������� ������������ �����!.. � ����� ���, ���.";
			link.l1.go = "seafox_10";
		break;
		
		case "seafox_10":
			dialog.text = "��� ������ - ��� ���������... ����� �� ������ ���, �������?";
			link.l1 = "����� �������� ��� �������. �� ����� ��������, ������.";
			link.l1.go = "seafox_11";
		break;
		
		case "seafox_11":
			dialog.text = "��������!";
			link.l1 = "����� ������ � ���� ����������� � ���������� � ���������� � ����������� � ��������. ��������� ����� � ���, ��� �� ����-������� ������ ������� ������������ ������ �������� ��� ����, ����� �������� �� ������ ���������� ������������������ ���������� ��������.";
			link.l1.go = "seafox_12";
		break;
		
		case "seafox_12":
			dialog.text = "������� ���� ����! ��� ��� ������ ������ �� ����?";
			link.l1 = "�������, ���� �� ����� ������� �����������. � ����� �� ������� �� ���� ��������� ���� ������. ������ � ����������� ��� ������������� � ��� ����. ���� ������� ����������� ������� ������. �� � ���������, ���������.";
			link.l1.go = "seafox_13";
		break;
		
		case "seafox_13":
			dialog.text = RandSwear()+"� ��� �� ��� ������ �����������?.. ��...";
			link.l1 = "��� �������, ����� ������ ����: ������������ ����� � ����� ����� ����, ������������ �� ���� ����� ������� � ������ ������.";
			link.l1.go = "seafox_14";
		break;
		
		case "seafox_14":
			dialog.text = "����, �� �������� �������? �, ���! �� ������ �� ������, �������, ��� ������ �� ��������� ������ ���������� �����!";
			link.l1 = "�� ����, ����� ������� �� ��������, ���?";
			link.l1.go = "seafox_15";
		break;
		
		case "seafox_15":
			dialog.text = "������... �������, ��� ����� ���� ������. ��� �� ��� ��������� � ����� ����� - ������� ������������ ������, ���� ���� ��������� ������� ���, �� � ��� ����� �� �������������, ��� �����������.";
			link.l1 = "����������� ��� ������.";
			link.l1.go = "seafox_16";
		break;
		
		case "seafox_16":
			dialog.text = "��������� ���� ����������. �� ��� ������������ � ���������� - ��� ����� ���� � ����������� �����. ���� �� �� �������������... �� �� �������� �������� � ������, ������� ������ � ��� ���� �� �������. �� � ������ ��������� ����� ������. ������� �������� ��������������� ��������������� ���������... �������, ��� ���� ���������� � ����������, � ������� �������, � ����� ��� ������ �� ����� ����� �������. ��� ���� ������� � ������ �� ������ ����, ��� ��� ����� � ������ ��� �� �����. ����� - ��� �������\n������� ��� ������: '����� �� ���� �������� ������� �������', ����� ��������� ��������, � �� ����� ����� ���������� ������. ����� ��������� ��� ����� ���. ��� ������ - ������ �������� ��� �������� ��� ���.";
			link.l1 = "����. ������, � ������ ���. �������, ���������, ��� �����... ����� � ������������ �������, �� �����?";
			link.l1.go = "seafox_17";
		break;
		
		case "seafox_17":
			dialog.text = "������.";
			link.l1 = "� ���� ��������� ���?";
			link.l1.go = "seafox_18";
		break;
		
		case "seafox_18":
			dialog.text = "����� �������� �� ������ � �������� ���������. � �������, ��� � ������ ���� ��� ����� ��������� ��� ���������.";
			link.l1 = "�������. �����, ����������� � �����. ����� ���� ��� � �� ������������� ����� - ��������� ��������� �� ������ ����, �� � �������.";
			link.l1.go = "seafox_19";
		break;
		
		case "seafox_19":
			dialog.text = "����������, �������!..";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_ToChurch");
		break;
		
		case "seafox_20":
			PlaySound("VOICE\Russian\soldier_common_4.wav");
			dialog.text = "�����? �������, �� ��� �� ��� ����������? ����� � �����, � ��� �� ������ �������� ���� �� ������� ����������...";
			link.l1 = "� ������ ��� �� ������. � ����� ���� �� �������?";
			link.l1.go = "seafox_21";
		break;
		
		case "seafox_21":
			dialog.text = "�� ����� - � ��� ��?";
			link.l1 = "� ������ - � ������ ��� �� ������. � ��� � ������. � ��� ��� ��������, ��� �������� ������ �� ����� ����� ������� � �� ������� ���.";
			link.l1.go = "seafox_22";
		break;
		
		case "seafox_22":
			dialog.text = "�� ��� ������ �� �����, � �� �������...";
			link.l1 = "�������! � ��� �������, ��� ��� ��� ���, �� �� �����, �� �� �������! "+RandSwear()+" � ����� � ������ �������� � ����! "+RandSwear()+"";
			link.l1.go = "seafox_23";
		break;
		
		case "seafox_23":
			dialog.text = "�� ��� �� ���������� ��� ���� ������, �������? ��������!";
			link.l1 = ""+RandSwear()+"";
			link.l1.go = "seafox_24";
		break;
		
		case "seafox_24":
			PlaySound("Ambient\Jail\chain.wav");
			PlaySound("Ambient\Land\door_001.wav");
			dialog.text = "�?! � ��, ����������! ��� ���, �� �������?..";
			link.l1 = "";
			link.l1.go = "seafox_25";
		break;
		
		case "seafox_25":
			PlaySound("Ambient\Land\cough_01.wav");
			dialog.text = "���� ������, ���-�� ����� ����!.. �� ������ ����������, �������! ���������!";
			link.l1 = ""+RandSwear()+"!!";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_HollandBattleFight");
		break;
		
		case "seafox_26":
			pchar.quest.FMQN_fail1.over = "yes";
			PlaySound("VOICE\Russian\QuestMan04.wav");
			dialog.text = "��� ������, �������?";
			link.l1 = "���������� � � ����� �������. �� ��� �����������: ������� ������� � ������ ����� ���������� ����, ������������ �����-�� ��������� ������, ���������� �������� ���. ��� ��� ����� ��� ����� ���� � ����� � ����������� ����� �������. ������, ������ ��� �������� � ��� � ��������� ������� �������� - �������, ��� ����� ������ ��� ������������� �������.";
			link.l1.go = "seafox_27";
		break;
		
		case "seafox_27":
			dialog.text = "�� ������ �� ����������. �������, � ������� ��� ������� ������� � ���� �������� - ����������� ��� �� ������. �� ��� �� ��� ������ � �����������, � ��������� ������ ������������ ������. � ���� ������ ������ �� ����� - �� ��� ������� ����. ������ �������� ����� ������.";
			link.l1 = "��... ��������� �� ���� ��� ���������, ���������! �� �����, ��� � ��� ����� ��� �������� - ������.";
			link.l1.go = "seafox_28";
		break;
		
		case "seafox_28":
			dialog.text = "�� �� ��������� �� ����. � ��� ������� ������ � ����� ����� ����?";
			if (pchar.location.from_sea == "Shore40")
			{
				link.l1 = "��.";
				link.l1.go = "seafox_29";
			}
			else
			{
				link.l1 = "���.";
				link.l1.go = "seafox_29x";
			}
		break;
		
		case "seafox_29":
			dialog.text = "�������. ����� ������������� � ������ � ���������� ��� � �������� � ��������� ����� � ����������� ������.";
			link.l1 = "������������. �� �������.";
			link.l1.go = "seafox_30";
		break;
		
		case "seafox_29x":
			dialog.text = "����� ��������� ����� �� ����� � ����� - ������� ����� �����, ����� ������� � ���� � �� ��� �������. ��������� �� ����� ��� ������ ������� ������ - ����� ������� ��� ����� �����, ���� ���������� �������. � ����� ������������� � ������ � ���������� ��� � �������� � ��������� ����� � ����������� ������.";
			link.l1 = "������������. �� �������.";
			link.l1.go = "seafox_30";
		break;
		
		case "seafox_30":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			AddDialogExitQuestFunction("FMQN_EnglandPrepare");
		break;
		
		case "seafox_31":
			PlaySound("VOICE\Russian\Gr_hovernor01.wav");
			dialog.text = "�� ������, �������?";
			link.l1 = "��.";
			link.l1.go = "seafox_32";
		break;
		
		case "seafox_32":
			dialog.text = "����� �� ����� ������ �������. ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_EnglandReload");
		break;
		
		case "seafox_33":
			dialog.text = "��-�-�-�... �������! ��-�-�... ���� �������! ������ ������ ������!..";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_EnglandRunToJungle");
		break;
		
		case "seafox_34":
			dialog.text = "��� ������ �������. �� �������, �������. ������ �������� ��������� - ������ ���� � ����� �������. ������� ������������ � ����� ����� ����!";
			link.l1 = "����!";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_EnglandRunToShore");
		break;
		
		case "seafox_35":
			PlaySound("VOICE\Russian\QuestMan05.wav");
			dialog.text = "������� �� ���� ������, �������! �� ���� ����, ��� ��������� �����! � ����� ��� ��������� ���� ���� � ����� �������, ���� � ������ ������ ���������� �����, � ������ ����� ��� ������� � ���� �� �����. ���� �� �� ������ - ����-�������� ���������� ����� ��������� � ���������� �����������, ������.";
			link.l1 = "������, ���������. �� �� ��� ������������... �� ���� ����� ����� �����������. ��-�� ��� ���� ��������� ������ �� ������";
			link.l1.go = "seafox_36";
		break;
		
		case "seafox_35x":
			PlaySound("VOICE\Russian\QuestMan05.wav");
			dialog.text = "������� �� ���� ������, �������! �� ���� ����, ��� ��������� �����! ����� ���� ���������� ������� ��������, �� �� �����, ��� ��������� ������ � ������� ������. � ����� ��� ��������� ���� ���� � ����� �������, ���� � ������ ������ ���������� �����, � ������ ����� ��� ������� � ���� �� �����. ���� �� �� ������ - ����-�������� ���������� ����� ��������� � ���������� �����������, ������.";
			link.l1 = "������, ���. �� �� ��� ������������... �� ���� ����� �������� ������. ��� ���� ������ �������� � ������������ �������� ������ ��������.";
			link.l1.go = "seafox_36";
		break;
		
		case "seafox_36":
			dialog.text = "�� ������������, � ����� ���� �������� � ������� � ����� ������ ����. ��� ��� ����������, ���!";
			link.l1 = "...";
			link.l1.go = "seafox_37";
		break;
		
		case "seafox_37":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "none", "", "", "", -1);
			pchar.quest.FMQN_eng_reward.win_condition.l1 = "Timer";
			pchar.quest.FMQN_eng_reward.win_condition.l1.date.hour  = 6.0;
			pchar.quest.FMQN_eng_reward.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQN_eng_reward.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQN_eng_reward.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQN_eng_reward.function = "FMQN_EnglandReward";
			AddQuestRecord("FMQ_Nevis", "28");
		break;
		
		case "soldier":
			PlaySound("VOICE\Russian\soldier_common_2.wav");
			dialog.text = "������� "+GetFullName(pchar)+"?";
			link.l1 = "���... ��, ��� �. ��� ���� �������?";
			link.l1.go = "soldier_1";
		break;
		
		case "soldier_1":
			dialog.text = "� �������� ���������� ��������, ��� ��� ������� ������� ������ � ����. ��� ��������� ���������� �����������, ������ ������ �����, ������ � ���� ������������.";
			link.l1 = "���-�� � �� �������... � ���������? � ����� �����?";
			link.l1.go = "soldier_2";
		break;
		
		case "soldier_2":
			dialog.text = "����� ���, ������ �������, �� �� ����������. ���������� ����� ������ ���������� � ���� ���� ��������� ��������, �������� ����� � ��� � �����, � ����� � ������ ���������. ���������!";
			link.l1 = "�, �� ����� ������... ���!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_ReloadToGovernor");
		break;
		
		case "hol_officer":
			PlaySound("VOICE\Russian\hol_gov_complete.wav");
			dialog.text = "����, ������, ����������� ������ ����, ��� �� ������ �������������� ���������.";
			link.l1 = "��� ���� � ������, ��� ��������� � ��������. ��� ���.";
			link.l1.go = "hol_officer_1";
		break;
		
		case "hol_officer_1":
			dialog.text = "�������� ������, �� �� ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_HollandBattleMarch");
		break;
		
		case "hol_officer_2":
			PlaySound("VOICE\Russian\hol_gov_quest.wav");
			dialog.text = "������, �������! ��������, ��� ��������� ������� ��� - � ����� � ������?";
			link.l1 = "��. �� � ����� ����� �����, ��� ��� ����� ������ �� ���� ����������� ������ ������.";
			link.l1.go = "hol_officer_3";
		break;
		
		case "hol_officer_3":
			dialog.text = "������ �����, ��� � ��� � ������. ���� �� ������� ���� ������� �� ����� - ��� ��������� �������, ������ ������� ������� � ����� �������� ������ � ��� ����� �������. ���� ������� �����. ��, �������, ����������� ���� ���� - ���������� �� �� ��������, � � � ������ ������ ������ ������� ������. ���, �� ��������� - ���� ����� �������, �� ����� �������� � ��� ������. �� ������� ������� ��� �� ������\n�� ������� � ������, � ���� ������ ��� - ��������� �� �������� �����-���� ������ ��������, � ����� ������ �����������, ��� ����� ������. ���� �� ��� ������� - ��� ��� �� �� ������� ������������� � ������� � ������� ���������. ��� �������� ������ �� ���� ������� �� ����� � ������ � ��������� ������� ���� � �������. ������� �� � �����.";
			link.l1 = "��... �������, ������ ������ � ������ ������� ������ ������ ����...";
			link.l1.go = "hol_officer_4";
		break;
		
		case "hol_officer_4":
			dialog.text = "�� �������, �������: ���� ������ - �������� �������� ��� ����������� �����������, ����� �� �������� �� �������. � ���� ��� ������� �� ��� - ������ �� ���� ��� � ����� �� ��� ������. �� ������������, ��� ���� ����� ���� ���� � ������ ����������.";
			link.l1 = "������. ��... � �����.";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_HollandBattlePosition");
		break;
		
		case "hol_officer_5":
			PlaySound("VOICE\Russian\hol_gov_common.wav");
			dialog.text = "�������, ��������, ���������... ������� ���������, �������! ����������. ���������� ������ �������������, ��������� � ���������� ����� ��������.";
			link.l1 = "���-�� �� ������� �����������, ������...";
			link.l1.go = "hol_officer_6";
		break;
		
		case "hol_officer_6":
			dialog.text = "������� ������ ������� �����, ����� ������ �����... ��-�� ����� � ����������� �������.";
			link.l1 = "�������� �� ������ ���-�� � �������� ����� ���� ����������. ������� �� - �����, ��� ����.";
			link.l1.go = "hol_officer_7";
		break;
		
		case "hol_officer_7":
			dialog.text = "� ������� ���� ����������. � �� ������������� � ����� � ���������. ������ ����� ��� ������ ����� ������ �� ����� � ����������� - ��������� � ���� �� ����� �� ������ ������������ ��������.";
			link.l1 = "�����������. �����, ������.";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQN_HollandBattleRest");
		break;
		
		case "monk":
			pchar.questTemp.FMQN = "way_eng_2";
			dialog.text = "��� � ���� ������ ����, ��� ���?";
			link.l1 = "� �� ����� ������, ����� �� ���� �������� ������� �������.";
			link.l1.go = "monk_1";
		break;
		
		case "monk_1":
			dialog.text = "��������� �������, ��� ���. �-�-�... ������ ����... (�������) �������, �� ��� � ����� � ���, ��� ���� ��������� �������������, � ��� ����?";
			link.l1 = "����������. ����� �� � ��� �� �����. ����� ���������� ������� �������� ������ ��������� � ��������. ��� ����� � ����� ����������� �������, �� � ������ ���� ������. ���� �������� �� ������� � ���.";
			link.l1.go = "monk_2";
		break;
		
		case "monk_2":
			dialog.text = "� ������� ��������� � ���, ����� ���� ��������� �� ������ ��� � �������. ���� � ���� ����� ������, �� ��� ��� ���������� ��� �� ������� �������: ����� ��� ������ ������� ��������.";
			link.l1 = "��� �� ���� - �� ��������� �� ���?";
			link.l1.go = "monk_3";
		break;
		
		case "monk_3":
			dialog.text = "�������. �������� � ������, � ����� � ��������� ���������� �������, �������� � ����������� ����������� ������ �������� ���� ��� ����������� ���������� ����. ��� ���������� �� ������, ���� � ���� ���� ������. � � �������-��������, ������� ��� ���-��� �������, � ���� ������� �����, ����������� ������������� � �������� ��� �� ��������� �����. � ������ ������ ��������� ������� �������� ����, ��������� � ��� ����� �������, � ����� ��������� ������� �� ������. ��� ��� ���� ��� ����� ������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 24)
			{
				link.l1 = "� ���� ���� � ����� ������ �����. �������.";
				link.l1.go = "monk_4";
			}
			else
			{
				link.l1 = "� ������� ��!..";
				link.l1.go = "monk_wait";
			}
		break;
		
		case "monk_wait":
			DialogExit();
			sld.dialog.currentnode = "monk_repeat";
		break;
		
		case "monk_repeat":
			dialog.text = "�� ������ ��� ������ ��������, ��� ���?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 24)
			{
				link.l1 = "��. �������.";
				link.l1.go = "monk_4";
			}
			else
			{
				link.l1 = "����� � ������ ������ ����������, �����...";
				link.l1.go = "monk_wait";
			}
		break;
		
		case "monk_4":
			RemoveItems(pchar, "gold_dublon", 24);
			Log_Info("�� ������ 24 �������");
			PlaySound("interface\important_item.wav");
			dialog.text = "���������. ��������� ������ � ��� �� ����� - � ������ ��� ����������.";
			link.l1 = "������...";
			link.l1.go = "monk_5";
		break;
		
		case "monk_5":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("FMQ_Nevis", "18");
			pchar.quest.FMQN_monk.win_condition.l1 = "Timer";
			pchar.quest.FMQN_monk.win_condition.l1.date.hour  = 6.0;
			pchar.quest.FMQN_monk.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQN_monk.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQN_monk.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQN_monk.function = "FMQN_EnglandMonkPlan";
			pchar.quest.FMQN_fail.win_condition.l1 = "Timer";
			pchar.quest.FMQN_fail.win_condition.l1.date.hour  = 11.0;
			pchar.quest.FMQN_fail.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQN_fail.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQN_fail.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQN_fail.function = "FMQN_EnglandFail";
			pchar.questTemp.FMQN = "way_eng_3";
		break;
		
		case "monk_6":
			pchar.quest.FMQN_fail.over = "yes";
			dialog.text = "����������� ����, ��� ���.";
			link.l1 = "� ��� ������� ����, ����. ���� � ��� �����-������ �������?";
			link.l1.go = "monk_6x";
		break;
		
		case "monk_6x":
			dialog.text = "��. ��� ������. ���� '��������' � ������ ������� ������� ������� ������� �������� ������. ���� � ��� � ������ ������, ��� ��� � �������� ��� ������ ��� ����� ����� ����� �� �����. ��� ���� ������������ ����������� ��������� ������: �� ���������� - ������� ����� �� �����. ������� ����� ��� �������. ������ ��������� - ���� � ��� � ����������� �������, �� � ������� �� �����. ��������� �� �������� � ������ ��������.";
			link.l1 = "��� ����. �� ���� ������ �������! �� ��������.";
			link.l1.go = "monk_7";
		break;
		
		case "monk_7":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("FMQ_Nevis", "20");
			sld = CharacterFromID("FMQN_seafox_1");
			sld.dialog.currentnode = "seafox_26";
			LAi_CharacterEnableDialog(sld);
			sld.talker = 9;
			pchar.quest.FMQN_fail1.win_condition.l1 = "Timer";
			pchar.quest.FMQN_fail1.win_condition.l1.date.hour  = 20.0;
			pchar.quest.FMQN_fail1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.FMQN_fail1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.FMQN_fail1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.FMQN_fail1.function = "FMQN_EnglandFail";
			pchar.questTemp.FMQN = "way_eng_4";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
