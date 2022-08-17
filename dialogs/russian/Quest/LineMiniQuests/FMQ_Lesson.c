// Addon-2016 Jason, ����������� ���������� (���) ��������� ����
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
		
		case "greguar":
			PlaySound("VOICE\Russian\QuestMan03.wav");
			pchar.quest.FMQL_delete_guide.over = "yes";
			if (CheckAttribute(pchar, "questTemp.HWIC") || pchar.Ship.Type == SHIP_NOTUSED)
			{
				dialog.text = "�, "+GetFullName(pchar)+"! ��� �� ������ � �� ������� ������! ��������, ����� ��������. �� ������ �������, �����, ������� ������, ����� ���� ����� �� ��������� �����. ������� ��� � ������, ��� ��� ����������!";
				link.l1 = "����� �������, ����� �������! ��� �������� ������ - ����� �� ���� �������, ��� � ���. ��� ���� ����� ������� ������ ��� � ���� �� ������. �����!";
				link.l1.go = "greguar_exit_1";
			}
			else
			{
				dialog.text = "�, "+GetFullName(pchar)+"! � ��� ����! ��� �� ������ � �� ������� ������! ��������, ����� ��������. �� ������ �������, �����, ������� ������, ����� ���� ����� �� ��������� �����.";
				link.l1 = "����� �������, ����� �������! ��� �������� ������ - ����� �� ���� �������, ��� � ���. �� ���� �����? ����� ��������� - � ��� �� ��� ������� �����������?";
				link.l1.go = "greguar_1";
			}
		break;
		
		case "greguar_1":
			dialog.text = "�����. ���� ������, ��������� ����� �� ������. ����: ����������� �������� �������, ����������� �� �������� �� ������� � ������ �������������� ������� ��� ����-������� �������� ��������, ������ � ������ �������� ����� ���������� � ���������. ���� ����� �������� ����� ������������ �� ��� � ��������� � ������ � ����� ���� �� �� ������, � ��� ����� ���� ���� ����. ���������. �� ��������� ������� ����� ��������\n�� ���� ����������, ���������� ���� ��������, � ���� ��� ������ � �������. ������� ��������� ����������� ������, �� ������� ��������� ������. ��� ��� ����! ��������� � ����������� �� ��� �������� ���� � ������ � ��� ������, � �� �� �� ����������� ������. ���� ���... � ��� ���� ������� � ����. �� ����� ����������, ���������� � ������ ��������. ���� ������ ����� � ��� ��������� ����������\n� ������� ��� ��������� ���������� ��� �������� - ��� �� �� �������� � ��������, � �� ������� � �� ���� �������� ��������. � ���� ���� �������� ����������, � ����� ������� ��� ����� � ����� ��������� �� ������. ������ ����� �������. � ��� ���� ������. �� � ����?";
			link.l1 = "�������� ����, �����, �� � �� �����. � ������ ��� �� �������� ������ � �� ����� ������������� �� ����� �������� ����. ���� � ���� ����� ������� ������� ������� �� ����� ����� ��.";
			link.l1.go = "greguar_exit";
			link.l2 = "������, ��� ��������� ����, ������� ������������� ������! � � ����. �� ����� �������!";
			link.l2.go = "greguar_2";
		break;
		
		case "greguar_exit":
			dialog.text = "����. �� ���� ����. ����� ���, �����, � � ���-���� ���������� ����. ���� ���� ����������, �����? ��������.";
			link.l1 = "�����, ����� �������!";
			link.l1.go = "greguar_exit_1";
		break;
		
		case "greguar_exit_1":
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload5_back", "none", "", "", "", 20.0);
		break;
		
		case "greguar_2":
			dialog.text = "���������� �������, ��� ����! ������, ������ ��� �� ��������, �����? ������, ��� �������� ��� ����?";
			link.l1 = "������ ������� �� ��������, ��� �����. ������? ��� ���� ������, �� �������. ������� ��� ������... ���������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQL_Begin");
		break;
		
		case "greguar_3":
			PlaySound("VOICE\Russian\QuestMan02.wav");
			dialog.text = "��� ���� ������! ������, ��������� ����� ����� � �����������. ���� ������������ ������ ��������, ��� ����� ���-�� ���!";
			link.l1 = "������� ������... �� ������� ����������, ����� �������. ����� ���������� ��-�� ����...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQL_SecondCoastBattle");
		break;
		
		case "greguar_4":
			dialog.text = "���� �� �� ������ ���� �����������! ��� ��� ���� �� �����! �� ������ �� �����, � ��� � ������� �������� ������ ������� � ����! ������!";
			link.l1 = "� �� �� ��� ��� ������ � ����... �����������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQL_GoToJungle");
		break;
		
		case "greguar_5":
			PlaySound("VOICE\Russian\MiddPirate04.wav");
			dialog.text = "�� ����? �� � ����������� ������ ���� �������� �� ����!";
			link.l1 = "";
			link.l1.go = "greguar_6";
		break;
		
		case "greguar_6":
			DialogExit();
			if (CheckAttribute(pchar, "questTemp.Prosper_fmql")) sld = CharacterFromID("FMQL_Prosper");
			else sld = CharacterFromID("FMQL_mercen");
			sld.dialog.currentnode = "prosper_3";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "greguar_7":
			dialog.text = "������? �� � ��� �����! �� �� ����� � ����! �� ���������� ����� ������������ �������?";
			link.l1 = "";
			link.l1.go = "greguar_8";
		break;
		
		case "greguar_8":
			DialogExit();
			if (CheckAttribute(pchar, "questTemp.Prosper_fmql")) sld = CharacterFromID("FMQL_Prosper");
			else sld = CharacterFromID("FMQL_mercen");
			sld.dialog.currentnode = "prosper_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "greguar_9":
			dialog.text = "��������� ����, �������. � ����������� ��������� � ������. � �����������! � ���, � ���� ��������� ���������� � � ���� ��������� �����!";
			link.l1 = "...";
			link.l1.go = "greguar_10";
		break;
		
		case "greguar_10":
			DialogExit();
			DoQuestReloadToLocation("shore18", "goto", "goto8", "FMQL_JungleExit");
		break;
		
		case "greguar_11":
			PlaySound("VOICE\Russian\MiddPirate04.wav");
			dialog.text = "���! �� ������� ���!";
			link.l1 = "�� ����� �����! �� ���������� - ������� ����� ��� �� ������ ������. ���� �������, �������, ��� ������� ��������, ��� � ������ ������� ��� �� ���� ��� �����. �� � ��� �����, ����� ������� ����. ";
			link.l1.go = "greguar_12";
		break;
		
		case "greguar_12":
			dialog.text = "�������!! ��� ��� �� ��������, �� �� �����, "+pchar.name+": ���� ���� ������� ������ ���, �� �� ������ ���� �� ������� ���������� ��� ��������. � ��� ������ ��� ����������! ������! ���� ������� ���� ����������� �����!";
			link.l1 = "...";
			link.l1.go = "greguar_10";
		break;
		
		case "greguar_13":
			PlaySound("VOICE\Russian\QuestMan02.wav");
			dialog.text = "���! �� ������� ���! �������� ������, "+pchar.name+"! ������ ������, � �������� �������, �� ��������! ������ ��� ��� ����� �� ���������!";
			link.l1 = "�����������! ��������� � ��������� ����� �������, ��� �� ��� �������, � ����� ��� ������������. ������!";
			link.l1.go = "greguar_14";
		break;
		
		case "greguar_14":
			DialogExit();
			DoQuestCheckDelay("FMQL_RunToGrabbing", 1.0);
		break;
		
		case "greguar_15":
			PlaySound("VOICE\Russian\QuestMan01.wav");
			dialog.text = "�� ������ �����������, "+pchar.name+". ������ ���� �� ����� - ������� ������� �����, �� ���, ����� ������� ������ �� �����������. � ���� ���� ������ ����������, �� ����� ����� ��� ������� �� ����� �������� � �������. �������� �� ������, � ������ �������� ��� �� ����������: ���������� - ������� �������.";
			link.l1 = "���� ��� ����... ���� ���� ���������, � ������ ��� ���������, ����� �� ����������� ��� ���� ������ ��� ��������. ������, ���� ������� � ������� � ��������� �����.";
			link.l1.go = "greguar_16";
		break;
		
		case "greguar_16":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload3_back", "none", "", "", "OpenTheDoors", 10.0);
			pchar.quest.FMQL_goods_timer.win_condition.l1 = "Timer";
			pchar.quest.FMQL_goods_timer.win_condition.l1.date.hour  = 0.0;
			pchar.quest.FMQL_goods_timer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.FMQL_goods_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.FMQL_goods_timer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.FMQL_goods_timer.function = "FMQL_MeetingOnLamanten";
			AddQuestRecord("FMQ_Lesson", "7");
			LAi_LocationDisableOfficersGen("Shore38", true); // may-16
			LAi_LocationFightDisable(&Locations[FindLocation("Shore38")], true);
			locations[FindLocation("Shore38")].DisableEncounters = true;
		break;
		
		case "greguar_17":
			PlaySound("VOICE\Russian\Master_01.wav");
			dialog.text = "��� ������, ������ ��������, ��������� ������� �������. ������ ��������������.";
			link.l1 = "...";
			link.l1.go = "greguar_18";
		break;
		
		case "greguar_18":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			for (i=1; i<=3; i++)
			{
				sld = CharacterFromID("FMQL_contra_"+i);
				if (i == 2) LAi_CharacterEnableDialog(sld);
			}
		break;
		
		case "greguar_19":
			dialog.text = "�������, �������!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQL_LookOnGuards");
		break;
		
		case "greguar_20":
			PlaySound("VOICE\Russian\OliverTrast01.wav");
			dialog.text = "�� �� ������, �� �������! �������! �� ���-�� ������ �������, "+pchar.name+"?";
			link.l1 = "���. ������, ��! ������ �����?!";
			link.l1.go = "greguar_21";
		break;
		
		case "greguar_21":
			dialog.text = "�� ��������������� ���������, �����. ��� ���� ������?.. ������ ��������, ���� ��� ��� � ���� �������. � �� ���� �� �������� �� ��� ����, ��� ���� �� ����������������. �������� �������� ���� ������. ���� ��� ����������� ������ � ���������� � �����. ������ �� ����� ����� ��� �����, ������ ��.";
			link.l1 = "���... � ��� ������? ������ � ����?";
			link.l1.go = "greguar_22";
		break;
		
		case "greguar_22":
			dialog.text = "������ ��. �� � �������������. ������� � ������ �������� �����. ���� � ��� ��������� �������� ��� ���. � �� ��������� ������ � �����, ��� �� �� ������� �� ��������. ������ � ��� ���.";
			link.l1 = "� ���� ������ ���� ������������ � ������? �� ������ �� ��� ������, �������. � �����, �� ��� ���� ����� �����������.";
			link.l1.go = "greguar_23";
			link.l2 = "� ����� ������ �� ����. � ������ ��� ���� ����. ���� ������, ����� �������� � ������������, � ����� � ���� �������.";
			link.l2.go = "greguar_25";
		break;
		
		case "greguar_23":
			dialog.text = "�� ���� ����� ��� �� �����������, �� ��������, �����! ���� ������ ���� �������, ������� ����� � ������. ����� ����� ���������� ���������, �� �� ������� ������������ ���������� �����. ��� ��������. � �� ������, ��� �� ����� ����� ����� �� ���� ��� ������ ��������? ����� ����� ��, ��� ��? �� �� �����, � ��� ���, � ��� �������, ��� ��� �������� ��-�� �����.";
			link.l1 = "� �� �������...";
			link.l1.go = "greguar_24";
		break;
		
		case "greguar_24":
			dialog.text = "����� �������. ��� �� �������� ���� ��������� ����. � �� - ��. � �� �����������. ��������, �����. ����� ���������� �� ������!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQL_PeaceFinal");
		break;
		
		case "greguar_25":
			dialog.text = "�� �� ����� ��������� ������. �� ��� ��... ������� - ����.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("FMQL_BattleOnBeach");
		break;
		
		case "mercen":
			PlaySound("VOICE\Russian\pirat_guard_4.wav");
			dialog.text = "�� ��������� �������! �� ��� �������� ���� �������, ��� ������ � ����� ����������� �, ���� �� ������ ����, �� � ���� ��� �������������. ������ ������� � ���� �����, �� ���� �������� ������ ����������.";
			link.l1 = "";
			link.l1.go = "prosper_2";
		break;
		
		case "prosper":
			PlaySound("VOICE\Russian\pirat_guard_4.wav");
			dialog.text = ""+GetFullName(pchar)+"! � �� �����! � ������ � �� �������! �� ��������� �������, ��� ����. �� ��� �������� ���� �������, ��� ������ � ����� ����������� �, ���� �� ������ ����, �� � ���� ��� �������������.";
			link.l1 = "�������! � ��� � �������! ����� �������� ��������? �������, � ������ �� ������?";
			link.l1.go = "prosper_1";
		break;
		
		case "prosper_1":
			dialog.text = "���� ���� ������ ��������� � ��� ������� - �� ����, ������ �� ���� ��� ���� �����. ������? ����� ���� � �� �������� � ���! � ������ � ���������, ������, ������ ��� ���� ������... �� ������, � ���� ��� �� �����, ��� ����� ���� ������. ������� ����, ��������. � ������ ����� ������������� � ���������������� �����������, ����, � ����� ����������, ��� ����� ���� ����� ����������������. ������ ������� � ���� �����, �� ���� �������� ������ ����������.";
			link.l1 = "";
			link.l1.go = "prosper_2";
		break;
		
		case "prosper_2":
			DialogExit();
			sld = CharacterFromID("Guide_y");
			sld.dialog.currentnode = "greguar_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "prosper_3":
			dialog.text = "����� ����. ��� ��������� ������ ����, �� �������� �� ������� �������. ���� ���� ����� �� ����� �������! � � ��� ����������� �������. �� ������ ���, � ��� � ������. ����� - ������ ���� �������, � ��� ���� - �� ��� �������. ���� ������ ������, ��� ������: ���� ��� ��� ������. ������ ��� �������� ������, ���� ���� �������.";
			link.l1 = "";
			link.l1.go = "prosper_4";
		break;
		
		case "prosper_4":
			DialogExit();
			sld = CharacterFromID("Guide_y");
			sld.dialog.currentnode = "greguar_7";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "prosper_5":
			dialog.text = "�� �� ������ ��, ���������! � ���� '�������' - �������, � ��� �� ��������� ������ ��� ����������! �� ���� � ���� ����� ���-�� ������! �� ��� �������� ��� � ��������!";
			link.l1 = "���, ������� ��� ���������� � �����, ��� ������. ����� ��� ����.";
			link.l1.go = "prosper_6";
		break;
		
		case "prosper_6":
			int n = 0;
			for (i=1; i<=5; i++)
			{
				if (GetCharacterIndex("FMQL_sailor_"+i) != -1) n++;
			}
			dialog.text = "������ ���� �����������, "+pchar.name+".";
			if (n > 2 && GetSummonSkillFromName(pchar, SKILL_SNEAK) > 30)
			{
				link.l1 = "�� ����� ���, �����! ���, �� ������, ��� ���� ������ � ������! �� ����� ���� ���, � �� �� �����. �����-�� ����� ����������� �������, ����� ���� � ���������, ��� �� ���������! ������� ��������� ���� �������� � �������� ������! � ��� ���������� �����, � � ��� ���� ���� ������� �� ��������. ������� ������. ������� ������ �������� �� ����� � ������� �� �������, � �� ������� ���. �������� �� � ������. ����� � ��� ������!";
				link.l1.go = "prosper_8";
			}
			else
			{
				if (n > 0)
				{
					link.l1 = "�� ����� ���, �����! ���, �� ������, ��� ���� ������ � ������! �� ����� ���� ���, � �� �� �����. �����-�� ����� ����������� �������, ����� ���� � ���������, ��� �� ���������! ������� ��������� ���� �������� � �������� ������!";
					link.l1.go = "prosper_7";
				}
				else
				{
					link.l1 = "���� ������� �������, � �� ������ ��� ��������� � ���������. �� ������ ������� - �� ���� ������ ������� ����� ������. � ��������� ��� ���� ����� ����. �� ��������� ����� ��!";
					link.l1.go = "prosper_9";
				}
			}
		break;
		
		case "prosper_9":
			DialogExit();
			sld = CharacterFromID("Guide_y");
			sld.dialog.currentnode = "greguar_9";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "prosper_7":
			DialogExit();
			pchar.questTemp.FMQL = "battle";
			AddDialogExitQuestFunction("FMQL_PrepareAttack");
		break;
		
		case "prosper_8":
			DialogExit();
			pchar.questTemp.FMQL = "sneak";
			AddDialogExitQuestFunction("FMQL_PrepareSneakAttack");
		break;
		
		case "prosper_9x":
			PlaySound("VOICE\Russian\pirat_guard_2.wav");
			dialog.text = "�� ���� � �� ����! �������, c ���� ������ �����������... �� ���� �������, ��-��! ����� � ����� ������, ������������ � ���, "+pchar.name+". � �������� - ������ ����������.";
			link.l1 = "�� ���� �������, ��� �������, �������. �� ���� ������� ���� ����������. �����!";
			link.l1.go = "prosper_10";
		break;
		
		case "prosper_10":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 10.0);
		break;
		
		case "prosper_11":
			pchar.quest.FMQL_prosper_dead.over = "yes";
			LAi_RemoveCheckMinHP(npchar);
			PlaySound("VOICE\Russian\pirat_guard_4.wav");
			dialog.text = "� �� ������������ ���, �������: ������ ���������! � ����������, ��� ���� ������� �������� ��������.";
			link.l1 = "�������! �������! ��� �� �����?";
			link.l1.go = "prosper_12";
		break;
		
		case "prosper_12":
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.FMQL.PirateDead")) sTemp = "���� ����� �����, ���� � �����.";
			dialog.text = "������ �����������. ��� ��� ����������� �� �����. �� ����� � ������� � ��������� ����� �����. ��� ��������, �� �� � ����� �����, ���, ����� ����� �����, ������ ������� ������ � ������� � � �������� ������� ������-�� ��������. � ��� ����� ����� � �������� � ������ �������, ������� ���� ����� ������������ �� ���� �����. "+sTemp+" � � ��� � �����, "+pchar.name+", ��� ��� �� �����������.";
			link.l1 = "� ��� �� ��������� ����, �������! ��� ���� ������� �����... ������ ����� �� ��� � �������? ��� ����� ����� ������, ��� ��. ������ ����� ������ �����, � ������ �������� ��� �������.";
			link.l1.go = "prosper_13";
		break;
		
		case "prosper_13":
			dialog.text = "���, ���� ���. � ���� ���� ������������� ����� �������. ��� ��������� ���� ����������, ��� � ������ � ����� ����������. ��� ���� ���������. ����, ���� ������, �� ���� ���� � ����� ������ ����� �� �����. ��������, "+pchar.name+". �... ������ � ��� ��������� �������. �����, ������� � ��� ���-������?";
			link.l1 = "����� � �����, ��� �����... ��������, �������! ��� ������ ����... (��� ����) ���� ������, ����� �������. ��� �� ��� ������? ������� - ����? ���� ���������.";
			link.l1.go = "prosper_14";
		break;
		
		case "prosper_14":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 15.0);
			chrDisableReloadToLocation = false;
			InterfaceStates.Buttons.Save.enable = true; // �������� �����������
			AddQuestRecord("FMQ_Lesson", "15");
			CloseQuestHeader("FMQ_Lesson");
			pchar.questTemp.FMQL = "end";
		break;
		
		case "contra":
			dialog.text = "�� ��� �����, ���� ������?!";
			link.l1 = "�� � �������. �� ���������?";
			link.l1.go = "contra_1";
		break;
		
		case "contra_1":
			dialog.text = "��-��. ����� ���������. ����� ��������� ��� ��������. ����� ����?";
			link.l1 = ""+FindRussianQtyString(sti(pchar.questTemp.FMQL.Sanl))+" �������, "+FindRussianQtyString(sti(pchar.questTemp.FMQL.Silk))+" �����, "+FindRussianQtyString(sti(pchar.questTemp.FMQL.Rope))+" ������� � "+FindRussianQtyString(sti(pchar.questTemp.FMQL.Oil))+" ����.";
			link.l1.go = "contra_2";
		break;
		
		case "contra_2":// Addon 2016-1 Jason ��������� �������
			iTotalTemp = 2200*sti(pchar.questTemp.FMQL.Sanl)+1600*sti(pchar.questTemp.FMQL.Silk)+1000*sti(pchar.questTemp.FMQL.Rope)+900*sti(pchar.questTemp.FMQL.Oil);
			dialog.text = "�������. ������ - 2200 ���� �� �����, ����� - 900 ���� �� �������, ���� - 1600 ���� �� �����, ������ - 1000 ���� �� �����. ����� ��� ����������... ���-���... "+iTotalTemp+" ����. �� �����?";
			link.l1 = "�� �����!";
			link.l1.go = "contra_3";
		break;
		
		case "contra_3":
			LAi_Fade("", "");
			FMQL_CreateGuidesWarriors();
			dialog.text = "�����������! ��������� ���. ��������� ������ ����� ���� ���������� ����������� ��� �������... � ��� ��� ��� �� �����? ������ �����?!";
			link.l1 = "";
			link.l1.go = "contra_4";
		break;
		
		case "contra_4":
			DialogExit();
			sld = CharacterFromID("Guide_y");
			sld.dialog.currentnode = "greguar_19";
			AddMoneyToCharacter(sld, iTotalTemp);
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.0);
		break;
		
		case "FMQL_beach":
			pchar.quest.FMQL_pirate_dead.over = "yes";
			LAi_RemoveCheckMinHP(npchar);
			dialog.text = "��, ���. �� ��� � ������ ��������.";
			link.l1 = "��? ������?! ���?!";
			link.l1.go = "FMQL_beach_1";
		break;
		
		case "FMQL_beach_1":
			dialog.text = "��������, ���. ����� ���� ������� � ��������� ��� ���� ���� ������. � ��� ��� ���� ��� �����, �� ��� ���� � ���� �������, � ���, ���...";
			link.l1 = "������� ���� ������?";
			link.l1.go = "FMQL_beach_2";
		break;
		
		case "FMQL_beach_2":
			sld = CharacterFromID("FMQL_Prosper");
			dialog.text = "���! ���������! ���������, ���� ���� ������ ������! �� ��� ��������� ��� �������� � ����, ��� ��� ������, ��������� ������, ����� ��� ���������� � ��������.";
			if (LAi_GetCharacterHP(sld) > 0)
			{
				link.l1 = "���������, �������...";
				link.l1.go = "FMQL_beach_3";
			}
			else
			{
				link.l1 = "�������... ������ ����. � ���������� � ����� ������. ���� ������, ����� �������... ��� �� ��� ������? ������� - ����? ���� ���������.";
				link.l1.go = "FMQL_beach_3";
			}
		break;
		
		case "FMQL_beach_3":
			dialog.text = "������, ���?";
			link.l1 = "��. ������� �� ������. ������ �� ���, �� ������ ���� �� ��� ��������. ������.";
			if (CheckAttribute(pchar, "questTemp.FMQL.ProsperDead")) link.l1.go = "FMQL_beach_5";
			else link.l1.go = "FMQL_beach_4";
		break;
		
		case "FMQL_beach_4": // ������� ���
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload_sea", "none", "", "", "FMQL_PirateNormal", 10.0);
			sld = CharacterFromID("FMQL_Prosper");
			sld.Dialog.currentnode = "prosper_11";
			sld.MusketerDistance = 20;
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0); 
		break;
		
		case "FMQL_beach_5":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "sea", "none", "", "", "FMQL_PirateNormal", 10.0);
			if (sti(pchar.money) >= 20000) DoQuestFunctionDelay("FMQL_MoneyForSelina", 0.5);
			else
			{
				pchar.quest.FMQL_money_20k.win_condition.l1 = "Money";
				pchar.quest.FMQL_money_20k.win_condition.l1.value = 20000;
				pchar.quest.FMQL_money_20k.win_condition.l1.operation = ">=";
				pchar.quest.FMQL_money_20k.function = "FMQL_MoneyForSelina";
			}
			chrDisableReloadToLocation = false;
			InterfaceStates.Buttons.Save.enable = true; // �������� �����������
			AddQuestRecord("FMQ_Lesson", "10");
			CloseQuestHeader("FMQ_Lesson");
			pchar.questTemp.FMQL = "end";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
