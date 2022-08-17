// �������� ���� - ������ � ���������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	string sTemp;
	float locx, locy, locz;

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
		
		// ��� �� ����
		case "reef":
			PlaySound("VOICE\Russian\saga\Jessica Rose-06.wav");
			dialog.text = "��! �� ������ �� ����! ��� - ��� ����� � �����! ��� - �� ����� � �����! ���� ��������� ����� ������� �� ������ ����� ������! ��� �����! � �� �� ������� �������� �����! �� ���� �� ���� ��������! �� ��������� �����!";
			link.l1 = "...";
			link.l1.go = "reef_1";
		break;
		
		case "reef_1":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "stage_1":
			PlaySound("VOICE\Russian\saga\Jessica Rose-07.wav");
			dialog.text = "��-��-��-��! ���� �� ������� ����!\n������, ����, ����� � ����� - �������� ��� ���� � ������!\n�� ���������� �������� � ������� �����, �� ��������� ��� ������� ����� �������, �� ������� ���� �� ������ � �����, �� ��������� ���� ����� �� ������ ����, � �� �������� ���� ����� ������� �������!\n�������, ��-��-��!!!";
			link.l1 = "...";
			link.l1.go = "stage_1_exit";
		break;
		
		case "stage_1_exit":
			DialogExit();
			LAi_SetActorType(pchar);
			CreateLocationParticles("blast_inv", "quest", "top", 1.6, 0, 0, "");
			PlaySound("Sea Battles_01\Bomb_Explosion_03.wav");
			PlaySound("People Fight\Death_NPC_08.wav");
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(pchar, "shore67", "goto", LAi_FindFarFreeLocator("goto", locx, locy, locz));
			LAi_ActorAnimation(Pchar, "Ground_sitting", "", 3.5);
			DoQuestCheckDelay("Saga_JessikaFirstKick_2", 3.5);
		break;
		
		case "stage_2":
			PlaySound("VOICE\Russian\saga\Jessica Rose-07.wav");
			dialog.text = "��-��-��-��! ���� �� ������� ����!\n������ ������� �� ����� � �� ������ � �����, �� �������� ����� ��� ������, �� ��������� ���� ����� ������ ����� � �� �������� ����� ���� ���� ������� ��������!\n�������, ��-��-��!!!";
			link.l1 = "...";
			link.l1.go = "stage_2_exit";
		break;
		
		case "stage_2_exit":
			DialogExit();
			LAi_SetActorType(pchar);
			CreateLocationParticles("blast_inv", "quest", "rock", 1.6, 0, 0, "");
			PlaySound("Sea Battles_01\Bomb_Explosion_03.wav");
			PlaySound("People Fight\Death_NPC_08.wav");
			pchar.GenQuest.BladePenalty = 30;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(pchar, "shore67", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_ActorAnimation(Pchar, "Ground_sitting", "", 3.5);
			DoQuestCheckDelay("Saga_JessikaSecondKick_2", 3.5);
		break;
		
		case "stage_3":
			PlaySound("VOICE\Russian\saga\Jessica Rose-07.wav");
			dialog.text = "��-��-��-��! ���� �� ������� ����!\n��� �������� �� ��������� ����, �� ������� ���� ����� � ������� ����, �� �������� ���� ���� �������� ������� ���������!\n�������, ��-��-��!!!";
			link.l1 = "...";
			link.l1.go = "stage_3_exit";
		break;
		
		case "stage_3_exit":
			DialogExit();
			npchar.viper = true;
			TakeNItems(npchar, "potion2", 3);
			LAi_SetActorType(pchar);
			PlaySound("Sea Battles_01\Bomb_Explosion_03.wav");
			PlaySound("People Fight\Death_NPC_08.wav");
			pchar.GenQuest.EnergyPenalty = 2;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(pchar, "shore67", "quest", "bridge2");
			LAi_ActorTurnToLocator(pchar, "quest", "bridge1");
			LAi_ActorAnimation(Pchar, "Ground_sitting", "", 3.5);
			DoQuestCheckDelay("Saga_JessikaThirdKick_2", 3.5);
		break;
		
		case "stage_4":
			PlayStereoOGG("music_shore");
			sld = characterFromId("Svenson");
			dialog.text = "��������... � ���� ��� ������ ���. � ���������... ������� ���� �� ��� ������� ���������� ��������!";
			link.l1 = "�������... � �������� ���� ������ ���� �� ����� ����� �������� ����!";
			link.l1.go = "exit_battle";
			if (CheckAttribute(sld, "quest.jessika_peace")) // �������� ������� ��������
			{
				link.l2 = "� ���� ���� �������, ��������. � ��� ����, ��� ����� ���� ��������� ��� ������� � ����������� ��� ������. � ����, �� ������ ����������? ��� ��, � ���������� ������ � ���, ��� �� ������ ��� ���� �� ����� ����, � ��������, ���� ��� ��� � ��������...";
				link.l2.go = "exit_talk";
			}
		break;
		
		case "exit_battle":
			DialogExit();
			SetMusic("music_teleport");
			DeleteAttribute(npchar, "viper");
			LAi_SetImmortal(npchar, false);
			npchar.chr_ai.hp = stf(npchar.chr_ai.hp)+100;
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Saga_JessikaDie");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.Saga.JessSeekTreatment = 0;
			LAi_LocationDisableOfficersGen(pchar.location, false);//�������� �������
		break;
		
		case "exit_talk":
			dialog.text = "�������... �� ��� ������ � �������� ���� � ��������... ���� ��������. � ��� ��������� ����� ��, �� ��� - �� ������. ��� ���� ��������, � ��� - ���. �������� �������...";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("Video_Reef");
			NextDiag.TempNode = "exit_talk_0";
		break;
		
		case "exit_talk_0":
			dialog.text = "... �� ����, �������� � ��������� �������� �������, ������� �� �����������. ���� ����� ����� � ��������� � ��������� ��������� ������� ������� ���� �� ������\n��������� ���������� ��� ���� � �������. ���, ��� �������� �� ���� ��� �����, ���� ����� ����, � �� ������� ���� ����������� ���. ������ ����, ��� ���� �������� ����, ���� � ������� � ������...";
			link.l1 = "�� ��� �� � ���� ��� ���� �������? ������������ - ��� ���������� �� ���������...";
			link.l1.go = "exit_talk_1";
		break;
		
		case "exit_talk_1":
			PlaySound("VOICE\Russian\saga\Jessica Rose-03.wav");
			dialog.text = "������ ���... ������ ���� � ����.";
			link.l1 = "� �������� ��������? �� ��� �� � ��� ������? ��� ������� ��� ����������, ������� ����, ��� �������� �� ������ ��� �����������. �� � �� ������ ���������� ���� �����, � ����� '��������� �� ����'...";
			link.l1.go = "exit_talk_2";
		break;
		
		case "exit_talk_2":
			dialog.text = "���� ����� �� ������. ����� ����. �� ������ ��� ��� ������, ��� ��� �������� ��, ���� ������� �� ������ ������� �����. �� � �� ����� ��������� �� ���� ������� ��� ������ ��������. ������ ���� � ����! ������ �� ������ ��������� ���� ����\n� ������� ���� ����� ���������. ����� ����� � �� �����. ������ ���� � ������� � ����� ��������, � � ��������� ���� �� ����� ����������, � �� �������� ��, �� ��� ���� ������.";
			link.l1 = "������ �� ������, ������ � �����?";
			link.l1.go = "exit_talk_3";
		break;
		
		case "exit_talk_3":
			PlaySound("VOICE\Russian\saga\Jessica Rose-01.wav");
			dialog.text = "� ���� ������. ������, ��� ��, �����. � � ������ ��... ���� ����� ���� ������, ��� ���, � �� �� ��������. �� �������� ������ - � ��� ���� ��� ���-���. ������...";
			link.l1 = "��. ��� ����� �� �������� ���� ����������� ��������� � ��������� �����. �� ���� �� �������. � ����� ������, ��� �� ����� ����� �� ���� ����.";
			link.l1.go = "exit_talk_4";
		break;
		
		case "exit_talk_4":
			dialog.text = "�� ������� ����. � �� ����� ��... � ������.";
			link.l1 = "��� �� ���. �� ����������� ������� � ���� ��������, �������� ��� ������� ���������? ���������, ��� �� �� �������� �� ����� ���� ����� �������� � ����� ����, � ������� �� ���� �������...";
			link.l1.go = "exit_talk_5";
		break;
		
		case "exit_talk_5":
			dialog.text = "��� �� ��� ������... ����� �� ���������� � ����� � ����� ��������, ����� ����, ��� �... � �������� ����, ��� ����������.";
			link.l1 = "����� ����, ��� ��?.. ��� ������?";
			link.l1.go = "exit_talk_6";
		break;
		
		case "exit_talk_6":
			dialog.text = "����� ����, ��� � ��������� � ���.";
			link.l1 = "��, �� ����� ����� ���. ���� �����������. �����, �������� �����: �� ��������, ��� ����� ���� �� ������ - ���, ��� �� �� ������� ��� ������� - ���, ��� �� �������� ���� ������ ��� ����� - ���, ������ ��� ��, ��� � ��� - ������, � �������� �� ������ ���������� - ����. ���?";
			link.l1.go = "exit_talk_7";
		break;
		
		case "exit_talk_7":
			dialog.text = "�����. � �� ������. � �����, ��� ����������. �� �������� ��� ���.";
			link.l1 = "������. ����� ������������. � �������� ���� ������ �� ��� �������...";
			link.l1.go = "exit_talk_8";
		break;
		
		case "exit_talk_8":
			PlaySound("Ambient\Teno_inside\teleporter.wav");
			ChangeCharacterAddressGroup(npchar, "none", "", "");
			dialog.text = "";
			link.l1 = "��! �� ���? ������ ����������...";
			link.l1.go = "exit_talk_9";
		break;
		
		case "exit_talk_9":
			DialogExit();
			LAi_group_Delete("EnemyFight");
			pchar.quest.Saga_JessFire.over = "yes"; 
			pchar.quest.Saga_JessFire1.over = "yes"; 
			pchar.quest.Saga_JessFire2.over = "yes";
			ref chr = &Locations[FindLocation(pchar.location)];
			DeleteAttribute(chr, "hell_fire_1");
			DeleteAttribute(chr, "hell_fire_2");
			DeleteAttribute(chr, "hell_fire_3");
			chrDisableReloadToLocation = false;//������� �������
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			AddQuestRecord("Shadows", "9");
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			pchar.questTemp.Saga.JessOnShip = "true"; // ������� �� ������������� �����������
			pchar.quest.Saga_Jessika_Travel.win_condition.l1 = "Hour";
			pchar.quest.Saga_Jessika_Travel.win_condition.l1.start.hour = 0.00;
			pchar.quest.Saga_Jessika_Travel.win_condition.l1.finish.hour = 2.00;
			pchar.quest.Saga_Jessika_Travel.win_condition.l2 = "location";
			pchar.quest.Saga_Jessika_Travel.win_condition.l2.location = "shore36";
			pchar.quest.Saga_Jessika_Travel.function = "Saga_JessikaOnJamaica";
			NextDiag.CurrentNode = "shore";
			npchar.greeting = "jessika_2";
			LAi_LocationDisableOfficersGen(pchar.location, false);//�������� �������
			LAi_LocationDisableOfficersGen("shore36", true);//�������� �� ������� � ����� ��������
		break;
		
		case "shore":
			dialog.text = "�� ������� ����� - �� �� ������. ������� ���� ������ ����� - � ������� ���� ��������. �� �������.";
			link.l1 = "�� �������...";
			link.l1.go = "shore_1";
		break;
		
		case "shore_1":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.Saga.JessOnShip");
			DeleteAttribute(npchar, "SaveItemsForDead");
			DeleteAttribute(npchar, "DontClearDead");
			LAi_SetActorType(npchar);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			AddQuestRecord("Shadows", "10");
			SetFunctionTimerCondition("Saga_JessikaShoreWait", 0, 0, 1, false);
			NextDiag.CurrentNode = "shore_2";
			npchar.greeting = "jessika_3";
		break;
		
		case "shore_2":
			dialog.text = "��� � ��, "+pchar.name+"...";
			link.l1 = "��� - ��?";
			link.l1.go = "shore_3";
		break;
		
		case "shore_3":
			dialog.text = "�� - ��� ��... ���, ����� ��, ��� �� �����. ��� ������ ���� ���������, ������������ ������ � ���. ��� ������ �����������. ������ � �������� ��, � � ���� ���� ��� ����� ���������.";
			link.l1 = "��... ����������� � ���? � ���������?";
			link.l1.go = "shore_4";
		break;
		
		case "shore_4":
			GiveItem2Character(pchar, "letter_beatriss"); // ���� ������
			AddQuestRecordInfo("Letter_beatriss", "1");
			dialog.text = "��. ���������, ��� �� ������� � ����� ����� - ��� ����. ��� �� ���� ���.";
			link.l1 = "������ ������� ��� ������� ����... �����, ��� � �� �������� ��� � ��� ����������.";
			link.l1.go = "shore_5";
		break;
		
		case "shore_5":
			dialog.text = "�� ������ �� ������� �� ����, ��� �� ������ ���. �� ����� ������ �������. � ������ ����� ��������� - ���� ������ ����� ����� �� ������. ���� ��������, �������� �������� ����. � ������� ���� �������. ���. ��� ��� ��������. ��� �� ������ �� �����. ��� ���������� ������, ������� ������ ��� �� �����.";
			link.l1 = "�������...";
			link.l1.go = "shore_6";
		break;
		
		case "shore_6":
			RemoveAllCharacterItems(npchar, true);
			GiveItem2Character(pchar, "blade_25");
			PlaySound("interface\important_item.wav");
			dialog.text = "������ � ����. ����� ����� ��� ��������, ����������� � ���������, � ������� �������. ��� ������� ����������. �� ���� ���� �����. �������� � ���� - �� ������, ��� ������. �������� ������� ����� ��������� �������� ������ - ��� ���� �����������.";
			link.l1 = "�� ����� ������� ����?";
			link.l1.go = "shore_7";
		break;
		
		case "shore_7":
			dialog.text = "�� ��� �������� ���. ������� ������� ����. ���� ������. ��� ����� ������.";
			link.l1 = "�����, � ���������� ���������� �� ��������. � ��� ������?";
			link.l1.go = "shore_8";
		break;
		
		case "shore_8":
			PlaySound("VOICE\Russian\saga\Jessica Rose-04.wav");
			dialog.text = "� ������ � ���� � ���� ��������� �������: �������� ��� ���� � ���� �����, � ����. � ��� ����. �����, �����-������ ��������� ������� ���������� ��������. ������, "+pchar.name+", � �������� �� ����...";
			link.l1 = "�����?..";
			link.l1.go = "shore_9";
		break;
		
		case "shore_9":
			DialogExit();
			LAi_KillCharacter(npchar);
			bQuestDisableMapEnter = false;
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
			chrDisableReloadToLocation = false;
			LAi_LocationDisableOfficersGen("shore36", false);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			AddQuestRecord("Shadows", "11");
			pchar.questTemp.Saga.JessTreatment = "true";
			// �������� ��������
			sld = characterFromId("Beltrop");
			sld.lifeday = 0;
			pchar.questTemp.Saga.Beltrop_die = "true"; // ������� ����
			sld = ItemsFromID("letter_jess");
			sld.price = 1; // �������� ����� ����������� 270912 
		break;
		
		case "soul":
			dialog.text = "�� �� ����� ����, �������?";
			link.l1 = "���... ��� ��? �� ���?";
			link.l1.go = "soul_1";
		break;
		
		case "soul_1":
			dialog.text = "��, "+pchar.name+", ��� �, ��������! �� ������� ����, ����� � ���� �������� ��� �����.";
			link.l1 = "����������... � ���� ����? �� ����� �� � �����? ��� ��� ���������?";
			link.l1.go = "soul_2";
		break;
		
		case "soul_2":
			dialog.text = "�� �� ����, "+pchar.name+". ������ �� ���������� � ������ ����������. �� ������... �����.";
			link.l1 = "� �� ��� ��������? ���-�� �� ����� �������...";
			link.l1.go = "soul_3";
		break;
		
		case "soul_3":
			dialog.text = "��� ������, "+pchar.name+". ������� ������� ����. ���� ������� �� ������ �������� ����, �� � �������� ��� ���� �� �������. ������� ���� �������, "+pchar.name+"! � � ���� ��������� � ���� �������� �� ��, ��� ��������� �� ����. ���... � �����, ������ ������ ����. � �� ����� ����, �� �������� ������ ��������.";
			link.l1 = "� ������ ����, ��������. � � ����� ���?";
			link.l1.go = "soul_4";
		break;
		
		case "soul_4":
			dialog.text = "�����... �� ���������. ����� �� ����������. � ������ ������ � ����� ����������.";
			link.l1 = "����� ��... ��������!";
			link.l1.go = "soul_5";
		break;
		
		case "soul_5":
			dialog.text = "��������? ��, �����-�� �� ���� ������ ������ ������ ����� �����, � ������ ������ ����� � ���� ������ ��� ����� ������� �� ���� �� �����.";
			link.l1 = "�� ���� ��� ����� ������ ����... ��, ����� ��������! �� ��� �� ���� ���?..";
			link.l1.go = "soul_6";
		break;
		
		case "soul_6":
			dialog.text = "�� �����. �� ���������. �� ������������� ������, �������� � ������. � ����� ������ ����� �����, �� ��������� ��������� ���� ������ � ������������� �����. � ���� �������� �������� �����. �� ���� ���������� ����. ������� ����, "+pchar.name+"...";
			link.l1 = "��� ������������� ����, ��� � ���� ��� ��� �����...";
			link.l1.go = "soul_7";
		break;
		
		// ����� ��������� ����
		case "soul_7":
			if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1)
			{ // ����-������
				dialog.text = "�� �����... � ����, ������, ���� ���� ����� ��������...";
				link.l1 = "��? � ��� �� ���?";
				link.l1.go = "mary_1";
				break;
			}
			if (!CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && CheckAttribute(pchar, "questTemp.LSC.marywait"))
			{ // ���� �������� �� �������
				dialog.text = "�� �����... � ����, ������, ���� ���� ����� ��������...";
				link.l1 = "��? � ��� �� ���?";
				link.l1.go = "mary_3";
				break;
			}
			dialog.text = "�� �����... ����� ���� ��� ������� ���� � �� ������� ��������� � ����� �����. � �� ������� ��������� �������� ���� ��������.";
			link.l1 = "� ����. � ����������� ��� ����...";
			link.l1.go = "soul_8";
		break;
		
		case "mary_1":
			dialog.text = "������� �������. ��� � ���� �� �������.";
			link.l1 = "����?!";
			link.l1.go = "mary_2";
		break;
		
		case "mary_2":
			dialog.text = "��. ��� - ������, ��� ����, � ��� ����� � ���� � �����. ������� ���. �� ������ �����, �� ����������� �����������. ��� �����, ��������, �� ������ � ��������, � ������� �� ��������. �������� � ���, ������ ��, �� ������� ������ ������ ����� ����. ��� - ���� ��������...";
			link.l1 = "� ����. � ����������� ��� ����...";
			link.l1.go = "soul_8";
		break;
		
		case "mary_3":
			dialog.text = "��� �� �������� ������� �� �������� �������� ������� ����... ��� ��� �� ����, �� ��� �������. ������ �� ���� ���������� � ����� � ����, ������ ���� ��� �������� ������� ������� �� ����, � �� ����� � �� ����� �� ������ ����, � ������� �� ����� �� ����...";
			link.l1 = "����...";
			link.l1.go = "mary_4";
		break;
		
		case "mary_4":
			dialog.text = "����� ��� � ����� ����� ���� ���, ������� ������ �����-�� ����� ���� � ���������. ������ ������ ��������� � ����� �����. ��� �� ������ �������������� ������, ����� ��� ��, ��� � � ��������.";
			link.l1 = "������ �� ���� ��� ��������?";
			link.l1.go = "mary_5";
		break;
		
		case "mary_5":
			dialog.text = "���... ��� ���������� �������� ������. �����, �� �����: ���� - ������, ��� ����, � ��� ����� � ���� � �����. �� ������ �����, �� ����������� �����������. ��� �����, ��������, �� ������ � ��������, � ������� �� ��������. �� ����� ���� ������, ���� ������ � ���� ������. ��� - ���� ��������.";
			link.l1 = "� ����. � ����������� ��� ����...";
			link.l1.go = "soul_8";
		break;
		
		case "soul_8":
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_friend")) sTemp = "";
			else sTemp = "��� �� �������� ������ ��������, �� ���� ����������� �������� � �� ��������� ��� � ��������� ������������. ����� �� � ���� ���������. ���� � ��� ���������. �� � ������\n";
			dialog.text = ""+sTemp+"��� ���� �������. ������ ����� ����������... �� ���� ��� - ��������. �� ������� ��������, � ���� �� ������� ������� �� �������... ���� ������ �� ���� ������, ��� ���.";
			link.l1 = "�����������, �����. � � ������, � �������� �� ����.";
			link.l1.go = "soul_9";
		break;
		
		case "soul_9":
			dialog.text = "�������. ������, "+pchar.name+"! ������!";
			link.l1 = "������, ��������...";
			link.l1.go = "soul_10";
		break;
		
		case "soul_10":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "Saga_JessikaSoul_4", -1);
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}