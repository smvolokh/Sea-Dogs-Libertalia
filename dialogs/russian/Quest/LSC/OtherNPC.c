// ������� ������ ��� �� ������ LSC
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//-----------------------------------������� ����� � ����� � ���������--------------------------------------
		case "PantryGuard":
			dialog.text = "�-��-��, ����������-�� ������, ��� � ��� ���������! �� �����, ��� ���, �������� �������� �� ����� ��������! ����, ������! � ��, ��������, ���� �� ������� �������� � ��������� �� ���� ������� - � ������ ���������� � �� ����������... ��� ����� ����� ��� ���� ������!";
			link.l1 = "�� �... � ������ ����� ����!..";
			link.l1.go = "PantryGuard_1";
		break;
		
		case "PantryGuard_1":
			dialog.text = "��� ��� �� ����, ��-��! ����� �� ���������, ������... ��� �����, ��� ��������, ��� �� ����������. � ��, ���� ������ � ���� ������! ������ �� '���������' ����� ���� ���������, ������!";
			link.l1 = "...";
			link.l1.go = "PantryGuard_2";
		break;
		
		case "PantryGuard_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			SetLaunchFrameFormParam("������ ��������� �����...", "", 0, 3);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 7, 10); //������ �����
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_GotoPrison", 3.0);
		break;
		
		case "CommonGuard":
			dialog.text = "�� ������� ������� ���-������ ������. � ���� ������������� �� �����.";
			link.l1 = "�� ����������, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CommonGuard";
		break;
		
		case "ChadGuard":
			dialog.text = "��� � ����� ��, ��� ���� ��� ������. ������ ��� ������ �������!";
			link.l1 = "��, ���, ���...";
			link.l1.go = "exit";
			NextDiag.TempNode = "ChadGuard";
		break;
		
		case "ChadGuard_Attack":
			dialog.text = "��! �� ���� ��� ���, � ������ �����, ��� ��? �� ��, ��������! ��, ������ ���� �����!";
			link.l1 = "...";
			link.l1.go = "ChadGuard_Attack_1";
		break;
		
		case "ChadGuard_Attack_1":
			DialogExit();
			sld = characterFromId("Chimiset");
			LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "afraid", "", -1);
			for(i = 1; i <= 3; i++)
			{				
				sld = CharacterFromID("ChadGuard_"+i);
				LAi_RemoveCheckMinHP(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			sld = characterFromId("Capper");
			LAi_SetWarriorType(sld);
			ChangeCharacterAddressGroup(sld, "Tartarusprison", "goto", "goto8");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_ChadGuard_Die");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Notsearchbody = true; // ������ ������ ������
		break;
		
		// ----------------------------------�������� ������--------------------------------
		// ���� ����� � �����
		case "Cabin":
			dialog.text = "��, �� ��� ����� �������, ���� �� ���� ������? ��� ������?";
			link.l1 = "��� ���� ������� �������... �������. �� �� ���� ������ �� �������, ��� � �������� ���� �������� � ���� � ����� � ��������� ���.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_A":
			dialog.text = "��, ���� ���� ����� ����, ���� �� ���� ������?";
			link.l1 = "��� ���� ������� �������... �������. �� �� ���� ������ �� �������, ��� � �������� ����, ��� ������, ��������� ���.";
			link.l1.go = "Cabin_1";
		break;
		
		case "Cabin_1":
			dialog.text = "������� ��� ���... � ���� ��� ���������� ������ - � ����� �������.";
			link.l1 = "�� �� �� ������, ��� ��� ������. ��������� ������� ��������� - � ���...";
			link.l1.go = "Cabin_2";
		break;
		
		case "Cabin_2":
			dialog.text = "��, � �� �������� �� ��� ���� ����. ����� �� ���. ������ ������ �� �� ������� ��� �������. ������, ��������, ��� �� � ��� ������, � ��� ��?";
			link.l1 = "������, �� ���� �� ��������, ���� ���. � �� ���� ������, ��� ������ �������. �� ���, �����, ��� �� ������� � ������� ����? �� ������ ��� �������� ��� ����, �...";
			link.l1.go = "Cabin_3";
		break;
		
		case "Cabin_3":
			DialogExit();
			sld = characterFromId("Mary");
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		// �� ����� ����� - ������� ����
		case "mary":
			dialog.text = "���� ������! ��������...";
			link.l1 = "��, ������� ������! ������ ���� �����!";
			link.l1.go = "mary_1";
		break;
		
		case "mary_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LSC_KillCyclop_CS");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// ��������� �� ����� �� �������� N
		case "SharkCureer":
			dialog.text = "���� ��� �� �� - "+GetFullName(pchar)+"?";
			link.l1 = "��, �. � � ��� ����?";
			link.l1.go = "SharkCureer_1";
		break;
		
		case "SharkCureer_1":
			dialog.text = "���� ������ �����. �� ������ ���� ��� ����� ������ ������� � ���� - �����-�� ������ ����.";
			link.l1 = "��� �� ������?.. ������, � ���������� ����������� �� '���-��������'.";
			link.l1.go = "SharkCureer_2";
		break;
		
		case "SharkCureer_2":
			// ���� ����� ��������� ������ �� ������ �����, ���� �� ������ �� ����� �����
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_20"; // ���� �����
		break;
		
		// ��������� �� ����� �� �������� M
		case "SharkCureer_3":
			dialog.text = "���� ��� �� �� - "+GetFullName(pchar)+"?";
			link.l1 = "��, �. � � ��� ����?";
			link.l1.go = "SharkCureer_4";
		break;
		
		case "SharkCureer_4":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie"))
			{
				dialog.text = "��, ��� � ��� ������ ���� �������... ���� ������� ����� � ������ �������. ��� ������ ���� ��� ����� ������ ������� � ��� �� ���������. �������� ����� ������, ��� ��� �������.";
				link.l1 = "��� ���? ������, � ���������� ����������� �� '���-��������'.";
				link.l1.go = "SharkCureer_6";
			}
			else
			{
				dialog.text = "��, ��� � ��� ������ ���� �������... ���� ������ �������, ������ �������. �� ������ ���� ��� ����� ������ ������� � ���� �� ���������. �������� ����� ������, ��� ��� �������.";
				link.l1 = "������ ������� - �������?";
				link.l1.go = "SharkCureer_5";
			}
		break;
		
		case "SharkCureer_5":
			dialog.text = "�� ��. ��� ��� �������, ����� ������ ����� �� ������������� ���� ���������.";
			link.l1 = "�������. ������, � ���������� ����������� �� '���-��������'.";
			link.l1.go = "SharkCureer_6";
		break;
		
		case "SharkCureer_6":
			DialogExit();
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
		break;
		
		// �������� ������ �������
		case "Prisonboss":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "�-�, ��� ��... � ����� ���� - �� ���������, ��� ������������ � ���������. �� �� �� ��������� �������, �?";
				link.l1 = "�� ���� ������. �� ��������� ������, ��� �� �. �����, �� �������������, ��� ������.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "��, �� ����� �� ������� ����� ���� ����! �������, ������ �� �� ����, ������ ���� - ������� ��...";
				link.l1 = "������, ��������, ������� ���. �����, �����.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "meeting":
			dialog.text = "������������-�� �����������, �� ������ ������� ���. ����� �� �����, ��� ����� �����������. ������ �� ������� �������� �����, ��� ������������ � �������� ������ ��, ���� �����, � ��� ������ ��� �����-�� ������� �� ������� ������� ��������. ��������, � ��� ������ �������? ��� ��� ����� � ������� �� ����� ��� ������� �������������, �������� ������ - ��� ��� �����.";
			link.l1 = "������. � ����� ��� � ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss";
		break;
		
		case "Prisonboss_M":
			dialog.text = "��, �� ����� �� ������� ����� ���� ����! �������, ������ �� �� ����, ������ ���� - ������� ��...";
			link.l1 = "������, ��������, ������� ���. �����, �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Prisonboss_M";
		break;
		
		// ����������� ������ � ��������
		case "AxelHelper":
			dialog.text = "���� ����, ��������?";
			link.l1 = "��. � ��� �� ����� �������? ��� ������?";
			link.l1.go = "AxelHelper_1";
		break;
		
		case "AxelHelper_1":
			dialog.text = "������ �����. �� ������ � �������� �������, � �������� � ���� �� ����. ��� ��� ���� �� ����� ���-�� ������ - ������ ���� ������� �� ����������� ����. � � ����� ������������ �� ���������, ����� ����� ������ �� �����, ��� ��� ������...";
			link.l1 = "�������. � ���� ��� ������ ������� ����������? �����, ����� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "AxelHelper_2";
		break;
		
		case "AxelHelper_2":
			dialog.text = NPCStringReactionRepeat("� ���� ��� ��� ������. ������� ������.", 
				"�� ������� ����, ��������. ����������!", 
				"�� ��� ����, ���������!",
				"����� ���!!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������.", 
				"�� ����� �, �����.",
				"�� ������...", 
				"���?!", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		// ���� ������ �������� - ����� �����������
		case "agnes":
			dialog.text = "��� ��� ������, ������?";
			link.l1 = "��... ��������, �������. �� ������� �� �������� ��� ������������, �� � ���� � ��� ��������: ��� �� ������ ������� �� ����� ��� �����������?";
			link.l1.go = "agnes_1";
		break;
		
		case "agnes_1":
			dialog.text = "��������� ��� ���, ��� �� ������ �������... ��� �����������? ���?!";
			link.l1 = "�� ��. ��� ��� �������� '����� �������', ��-�� ���������� �������� ����� ��� �����. ��� �� ��� ������?";
			link.l1.go = "agnes_2";
		break;
		
		case "agnes_2":
			dialog.text = "���� �� � ���?! ��� ��� ���, ��������� ��� ����� ����� �������� ������� ��� �����! �� ������ ��� ��, ������? �� ������� �� ��� - ��� ��, ��� � ���?!";
			link.l1 = "����, ����, �������, �� ���������� ���. � ��� ��� ������. �� � ���� �� �������. ��� ��� ��� ���������� ������ ����� �� ����� � ������ ����.";
			link.l1.go = "agnes_3";
		break;
		
		case "agnes_3":
			dialog.text = "��... ������, ������� ������� ��� ������� � ������ ��� �������� �� �������� ���! �� �� �������������, ��� � ����������, ����� �� �����! ���� ��� �, � ���� �� ���� ��������! ��� �� ��� �����? �� ���� �� ������� �������, ��... ��, ��, ��������, ���������, � ��� �.";
			link.l1 = "�������. ��, �� ���������. � � ������, ������, �� ���������. ���� �� �����, �� ��� � ������� � ����� �������. ����� � ��� �� ����� �������. �� �������� �����������. �� �������� � ���� ����� �������... ���� �� ����!.. ��� ������ �� ����� ��� �� �������� - ���������.";
			link.l1.go = "agnes_4";
		break;
		
		case "agnes_4":
			dialog.text = "���������? �, ����! ���� ��� ��-�� ��� ��� ������� �����, ��-�� ���� ������������ ���������� ��������, ������� ��� ��������!";
			link.l1 = "��� ������, ��� ���... ���� �� ����, ��-�� ����, ��� ������ ���� ����� � ��������?.. �������, ����, ������ �� �������!";
			link.l1.go = "agnes_5";
		break;
		
		case "agnes_5":
			dialog.text = "��, ��� ������. ��� ������ ��� ��������, ����� �� �����, � ���� ������ ���� � ����. � ��� ������ �������� �� ����, � ��� ��������... ������� ��������. � ��� ����� �� ��������� ����. �� �� �������������, ��� � ���� ������� �� ���!..";
			link.l1 = "��� ��� ��� ���� ������� ���������. �� �������� �� ������ ���������. ������� �� ��� ���, ����� �������. �, �������, ������, � �������� ������� ��� �����. ������� ������, ����� ����, ��� ��� ����, �� ���� ��, ������ � ���� � ������� ������ - �� ����. �� ���-���� ��� ������� ����� ���.";
			link.l1.go = "agnes_6";
		break;
		
		case "agnes_6":
			dialog.text = "�� ������� ������?! �, �������! ��� �� � ����� ��� ��������, ����� ���� ���������� ���������! �... � �� - ������� ���������! ��!";
			link.l1 = "�������, � �����, ����� ����� �����, ���� � ����� ������ �� ����� �����. �� ����� ����� ��������� � ���. �� ������, ��� �� �����������, ����� ������� ������. �� � �����, ��� ���������� �� ������ ����� �� ��-�� �����.";
			link.l1.go = "agnes_7";
		break;
		
		case "agnes_7":
			dialog.text = "������... ������ ��� �����. ��������� �� ��� ����� ���. � ��� ���� ������ ��� � ��������� ��������...";
			link.l1 = "�������, �������. ������ ��� ��������.";
			link.l1.go = "agnes_8";
		break;
		
		case "agnes_8":
			DialogExit();
			SetLaunchFrameFormParam("������ ���...", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 1, 10); //������ �����
			RecalculateJumpTable();
			DoQuestFunctionDelay("LSC_OleGoHome", 5.0);
		break;
		
		case "agnes_9":
			dialog.text = "";
			link.l1 = "�� ���, �������, ��� ��� - ��� �����������. �� ��� �������?..";
			link.l1.go = "agnes_10";
		break;
		
		case "agnes_10": // ������������ pchar
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Agnes"));
			ChangeShowIntarface();
			SetMainCharacterIndex(GetCharacterIndex("Agnes"));
			PChar = GetMainCharacter();			
			LAi_SetPlayerType(PChar);
			sld = characterFromId("Ole");
			sld.dialog.currentnode = "home";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "agnes_11":
			dialog.text = "������... ��������, � �� �������� ������ �����... "+pchar.name+"?";
			link.l1 = ""+GetFullName(pchar)+", �������. ������� "+GetFullName(pchar)+".";
			link.l1.go = "agnes_12";
		break;
		
		case "agnes_12":
			dialog.text = "�������, �� �� �������������, ��� � ��� ���������� �� ����� ����! �� ��, ��� ������� ���, �� ������� ��� � ������� �����. �� ������� ���� � �����! ������ � ��� ������ ��� ������ ��������, ����� ��� ��� ������, ������� �� ����������� �� ��� ����.";
			link.l1 = "� ��� �� ���, �������. � �� ��� ����. �� ������� ������, � ����� ��� � ������� ��������. � ���� ������ ������. � ����� ���� ��������, �������� �� ���� �� ���������� ������.";
			link.l1.go = "agnes_13";
		break;
		
		case "agnes_13":
			dialog.text = "������, � ���������, ����� �� ������ �� ��� ������, ��� � ����� ������� ��� ��� ����. � ���� ������������� ��� �� ������ ����. ������ ������ ��� �������... ��, �� ���������.";
			link.l1 = "� �������, �������.";
			link.l1.go = "agnes_14";
		break;
		
		case "agnes_14":
			dialog.text = "��������� ������. � ����� �������� ������������ ��� �� �� �����, ��� �� ������� ��� ����� ���� � ��� ����.";
			link.l1 = "������. � ����������� ������ ���!";
			link.l1.go = "agnes_15";
		break;
		
		case "agnes_15":
			DialogExit();
			bDisableCharacterMenu = false;//������� ����������
			chrDisableReloadToLocation = false;//������� �������
			LAi_SetOwnerType(npchar);
			LocatorReloadEnterDisable("Marigo_town", "houseSp2", true);
			NextDiag.CurrentNode = "agnes_16";
			pchar.quest.LSC_Ole_return.win_condition.l1 = "Timer";
			pchar.quest.LSC_Ole_return.win_condition.l1.date.hour  = 8.0;
			pchar.quest.LSC_Ole_return.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.LSC_Ole_return.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.LSC_Ole_return.function = "LSC_OleAgnesRegard";
			// ������� ��� �� ����������
			sld = characterFromId("Ole");
			RemovePassenger(Pchar, sld);
			DeleteAttribute(pchar, "GenQuest.Ole");
			DoQuestReloadToLocation("Marigo_town", "reload", "houseSp2", "");
		break;
		
		case "agnes_16":
			dialog.text = "��, ��� � ��, ������ "+GetFullName(pchar)+"! ���������, ��������������...";
			link.l1 = "�������! ��� ���?";
			link.l1.go = "agnes_17";
		break;
		
		case "agnes_17":
			dialog.text = "��, �� �� �������������, ��� �� �������! ����� ������� �� ������� �� �������������� ����������� ������... ���� �� �������������! � � ���������� ����� ����� ����, � ���� �������� �� ���� ������� �� ����� ����� ����.";
			link.l1 = "�� �������� ���� � ������, ��������...";
			link.l1.go = "agnes_18";
		break;
		
		case "agnes_18":
			dialog.text = "� ������ �����, ��� ���������� - ������������� ����� ����������� �����... � ����������� ��� ������� � ������������� �� ��� ��������. ��, ��! � �� ������ ������������! ���, ������... ��-������, ��� ���� �������� � ���������. ��-������ - ��� ���� ������������ ������, ��� ��������� '��������'\n�� ����������� ����� ����, � �� ��� �� ��� ������, ��� ��� �������� ���������� �� ����-������, � ������������ ��������, ���������� ��� ����. ��� ��� ��� ���������, � ������� �� ����������� � ���� ��������. ��� �� ������� - '������ �������� ����� �������, ���� �� ����� ����� ��������'\n�������, ���� �������� ������ ����� � ������� �������� ���, ��� ������ �����-�� ����� ��������� �������. �� �������� ������� �� �� �����!.. � �-������� - ��� ���������� �����. ����� ������� �����! � ��� ������� �� ������ ������� ��� ������ � �������, � �����.";
			link.l1 = "�! ��� ������������� ����� ������ ������� ��� ��������! ���������, �������.";
			link.l1.go = "agnes_19";
		break;
		
		case "agnes_19":
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ������ � ���������");
			Log_Info("�� �������� ������ '��������'");
			Log_Info("�� �������� ���������� �����");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "talisman7");
			GiveItem2Character(pchar, "tailor_tool");
			dialog.text = "� � ����, ����� �� ����� - ����� ����� ���� ������ ������� ��� ���, � ����� ����� ��� � ����. �� ������ ������� ����� ������� ������� ������� ���, ������� ������� ���� � ���, ��� � ��� ������ ����� ��� ��� �������.";
			link.l1 = "������� �� ������ �����, �������. ���� ��� ����� � ��� � �����, ����� � ��������� ��� ������ ����-�������.";
			link.l1.go = "agnes_20";
		break;
		
		case "agnes_20":
			dialog.text = "����������� ��������!";
			link.l1 = "� ������ ��� ����. ��������� �����������. �� �������� � ����� ���!";
			link.l1.go = "agnes_21";
		break;
		
		case "agnes_21":
			DialogExit();
			NextDiag.CurrentNode = "agnes_22";
			AddCharacterExpToSkill(pchar, "Fortune", 350);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterComplexReputation(pchar, "authority", 4);
		break;
		
		case "agnes_22":
			dialog.text = "��, ������� "+GetFullName(pchar)+"! ��� � ���� ��� ������! ���������, ��������������, ������ � ��� ����-������ �����...";
			link.l1 = "�������! � ����� ������ � ���� �������������, ������, ��� ����. ���, ��� � ��� � ��� ��� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "agnes_22";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}