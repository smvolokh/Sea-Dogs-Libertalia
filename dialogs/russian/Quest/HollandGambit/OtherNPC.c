// ������� ������ ���
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ��� � ����. �������� �� ���� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			if (npchar.id == "HWICFernando") NextDiag.CurrentNode = "Fernando";
			DialogExit();
		break;
	
//---------------------------------------�� ���������--------------------------------------------------
		//����������� ��������
		case "Baltazar":
			pchar.quest.Create_BaltazarOver.over = "yes";//����� ����������
			dialog.text = "����� �����! �������, ��� ��� ��� ����� ������ �� �����������, ����� ������...";
			link.l1 = "�� - ��������� ���������?";
			link.l1.go = "Baltazar_1";			
		break;
		
		case "Baltazar_1":
			dialog.text = "�, ����, � ���������� ��������� ����-������! ��� ��? ��� ��� ������?";
			link.l1 = "� - ������� " + GetFullName(pchar) + ". ���� ������� ����� ���������. � ������ ����� ��� � ���� ����� ��� ������.";
			link.l1.go = "Baltazar_2";			
		break;
		
		case "Baltazar_2":
			dialog.text = "�, ������ ������ ��������� ���-���� ����������� � ���� ������� � ������! � ��, ���������, ������� �����-�� �����...";
			link.l1 = "������� ����������� ���� ������� - ��� ��� ��������.";
			link.l1.go = "Baltazar_3";			
		break;
		
		case "Baltazar_3":
			dialog.text = "�������! � � ��� ������� ������� ����� �������... ��� ���������� ���� � ����������� �� �������, ��� ����� ��� ������.";
			link.l1 = "����� ������������� �� ������� � �������� ����� � ��������. �� ���������� ����������!";
			link.l1.go = "Baltazar_4";			
		break;
		
		case "Baltazar_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", 4);
			SetCharacterRemovable(npchar, false);
			npchar.CompanionEnemyEnable = false; //������ ������
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.loyality = MAX_LOYALITY;
			AddQuestRecord("Holl_Gambit", "1-3");
			SetFunctionTimerCondition("Baltazar_ConvoyOver", 0, 0, 14, false); //������
			pchar.quest.BaltazarConvoy_fail.win_condition.l1 = "NPC_Death";//���������� �� ���������� ���������������
			pchar.quest.BaltazarConvoy_fail.win_condition.l1.character = "Baltazar";
			pchar.quest.BaltazarConvoy_fail.function = "Baltazar_fail";
			pchar.quest.BaltazarConvoy_complete.win_condition.l1 = "location";//���������� �� ����������
			pchar.quest.BaltazarConvoy_complete.win_condition.l1.location = "Marigo_town";
			pchar.quest.BaltazarConvoy_complete.function = "Baltazar_complete";
			if (rand(1) == 0)
			{
				BaltazarPirateGlobalCreate();
			}
			else
			{
				pchar.questTemp.HWIC.Holl.BaltazarAttack = "true";
				pchar.quest.BaltazarConvoy_Attack.win_condition.l1 = "location";//���������� �� ����������
				pchar.quest.BaltazarConvoy_Attack.win_condition.l1.location = "SentMartin";
				pchar.quest.BaltazarConvoy_Attack.function = "BaltazarPirateSeaCreate";
			}
		break;
		
		case "Baltazar_5":
			dialog.text = "������� �� ��� ����, �������! ��� � � ������ - ��������� " + GetName( NAMETYPE_ORIG, pchar.questTemp.HWIC.Holl.PirateName, NAME_NOM) + " ����� �� ����. � ���� ������ ��������� ��� ������ ������, � ������ ������� ��� ������������� � ��� 5 000 ����.";
			link.l1 = "��, �� ������� ������ ������� �� �����...";
			link.l1.go = "Baltazar_6";			
		break;
		
		case "Baltazar_6":
			dialog.text = "����� �����, � ����������� ��� ������ �������� ������� ���������� ������ � ��������� ������� ����� ��������. � ������ - ��� ����.";
			link.l1 = "�� ��� ��, ��������, ���������.";
			link.l1.go = "Baltazar_7";			
		break;
		
		case "Baltazar_7":
			DialogExit();
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload3_back", "none", "", "", "", 15.0);
			AddQuestRecord("Holl_Gambit", "1-6");
			AddMoneyToCharacter(pchar, 5000);
			ChangeCharacterComplexReputation(pchar,"nobility", 2); 
		ChangeCharacterNationReputation(pchar, HOLLAND, 10);
			ChangeOfficersLoyality("good_all", 1);
			pchar.questTemp.HWIC.Holl = "BaltazarCom";
		break;
		
		//������������ � ��������
		case "Santiago_Trip":
			dialog.text = "������! ���������... ��, �������, �������...";
			link.l1 = "���? �?!...";
			link.l1.go = "Santiago_Trip_1";
		break;
		
		case "Santiago_Trip_1":
			DialogExit();
			PlaySound("People Fight\Death_NPC_08.wav");
			SetLaunchFrameFormParam("��� �������� ������ �����", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 15, 10); //������ �����
			RecalculateJumpTable();
			DoQuestFunctionDelay("SantiagoTripInHouse", 5.0);
		break;
		
		case "Santiago_Trip_2":
			dialog.text = "������, ���� ��� � �������� ���� ������ ���������, ���� �� ����������. ������� � ������ �����. ������ � �������. ���� ������...";
			link.l1 = "��� ��, ������� ���� ����, � ��� ��� ��������?!";
			link.l1.go = "Santiago_Trip_3";
		break;
		
		case "Santiago_Trip_3":
			dialog.text = "������, ������, ���� � ����� �������� ���� ����� ���������. �� ���� �� �����, ����� ���� �������� ��� ������� ���������, ������ ������ ������� ����������, ���? ���� ����������, �������� � ��� ����.";
			link.l1 = "������� ��� ��� �����, ������, � �� � ���� ������������ ����������, ������� �����!";
			link.l1.go = "Santiago_Trip_4";
		break;
		
		case "Santiago_Trip_4":
			dialog.text = "������� �����... ��� ��, ��������� ��� ����� �� ���� ���. ���� ���������� ��� ��, ��� � ���� ����� � ��������, ������ ������ �� ����� �����. � ������ ������ ����, � ������ � �������� ��� ���� ����� ������ � �����. � ������� ��������? ��� ��� ����� ������, ��� �� ������ - ����������\n�������? ������... ������, �� ������������. ��� �� ��� �� ���������� � �������?";
			link.l1 = "������.";
			link.l1.go = "Santiago_Trip_5";
		break;
		
		case "Santiago_Trip_5":
			dialog.text = "����... � ����, ��� �� ����� ���������. ��� ���� � ������, ������?";
			link.l1 = "������ ��� �����? ����� �������� ��������. � �� ���� �������� ������ ���������� ��� ���������������.";
			link.l1.go = "Santiago_Trip_6";
		break;
		
		case "Santiago_Trip_6":
			dialog.text = "������� ������� � �������� � ���� �������� �����. ��� ���� ��� ����. � ��� ������ ���� ������ ������, ����� ������� �����? ��� � ���� �� ���� � �����������?";
			link.l1 = "������� ������������� �������� �� �������, �������... ��� ��������� �������� �������.";
			link.l1.go = "Santiago_Trip_7";
			link.l2 = "���� ��� � ����� ����������� �� ���-��. ��� ���, ��� ��� ��������.";
			link.l2.go = "Santiago_Trip_8";
		break;
		
		case "Santiago_Trip_7":
			dialog.text = "� �� ������ ������... ��� � � �������� �����. ���� ����� ���� �������. ������� �� �� ����������. �������, ������ ���� ���. ��� ����� ���-��� ���������, � ������ ���������, ����� �� �� �����, ���� ���� �� �����.";
			link.l1 = "�������, '���� ���', �� ���������!";
			link.l1.go = "Santiago_Trip_9";
		break;
		
		case "Santiago_Trip_8":
			dialog.text = "��� ��� � ���� �����... ������� �������, � ��� ������ ������� ����� ������� ������������. ��� � ��� �����-��? ��� �������� ���-��� ���������, � ����� � � �������, � �� ���������, ���� ����� � ���. ������ ���� ���, ������ ������ ������ � ���������, ����� �� �� �����, ���� ���� �� �����.";
			link.l1 = "�������, '���� ���', �� ���������!";
			link.l1.go = "Santiago_Trip_11";
		break;
		
		case "Santiago_Trip_9":
			dialog.text = "��-��. ���� ����, �����, � ����� ����, ��� ����� ������.";
			link.l1 = "...";
			link.l1.go = "Santiago_Trip_11";
		break;
		
		case "Santiago_Trip_10":
			dialog.text = "���� ��, � �������, ��� ���� �������������� �������� ���� ���������.";
			link.l1 = "...";
			link.l1.go = "Santiago_Trip_11";
		break;
		
		case "Santiago_Trip_11":
			DialogExit();
			AddQuestRecord("Holl_Gambit", "1-44");
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "Santiago_HouseSp2", "goto", "goto4", "", -1);
			pchar.quest.Santiago_Trip1.win_condition.l1 = "item";
			pchar.quest.Santiago_Trip1.win_condition.l1.item = "slave_01";
			pchar.quest.Santiago_Trip1.function = "SantiagoTrip_wait";
		break;
		
		case "Santiago_Trip_12":
			dialog.text = "��� �� ����?!";
			link.l1 = "��, �������, �������!";
			link.l1.go = "Santiago_Trip_13";
		break;
		
		case "Santiago_Trip_13":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "SantiagoTripExitFromRoom");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Santiago_Trip_14":
			dialog.text = "��� ��� ����... � � �����, ��� �� ���. ��� ������������ � �� ������ �����!";
			link.l1 = "������, ��� �� �������... ��, � ������ ���������, ��� �� ������ ������ ������������ ����������!";
			link.l1.go = "Santiago_Trip_15";
		break;
		
		case "Santiago_Trip_15":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "SantiagoTripExitHouse");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		//������-��������� �� 5 �������
		case "HollQuest_Officer":
			dialog.text = "��� ������ �������� ������ ����� ���������. ��������� � ���� ����������.";
			link.l1 = "������. � ��� ��� � ����.";
			link.l1.go = "HollQuest_Officer_exit";			
		break;
		
		case "HollQuest_Officer_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", -1);
			pchar.questTemp.HWIC.Holl = "MerdokStart";
			AddQuestRecord("Holl_Gambit", "1-36");
		break;
		
//---------------------------------------------������ ����----------------------------------------------
		//������ ���������� �������
		case "Fernando":
			dialog.text = "��� ��� �� ���� �����?";
			link.l1 = "���� ������, �������!";
			link.l1.go = "Fernando_fight";
			link.l2 = "�� ���, ������.";
			link.l2.go = "exit";	
			NextDiag.TempNode = "Fernando_repeat";
		break;
		
		case "Fernando_repeat":
			dialog.text = "��� ����� ��? ��� �� ������, ���������, �������!";
			link.l1 = "���� ������, �������!";
			link.l1.go = "Fernando_fight";
			link.l2 = "�� ���, ������.";
			link.l2.go = "exit";	
			NextDiag.TempNode = "Fernando_repeat";		
		break;
		
		case "Fernando_fight":
			chrDisableReloadToLocation = true;//������ �������
			LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "SPAIN_CITIZENS");
			LAi_group_Attack(NPChar, Pchar);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
			pchar.quest.HWIC_Fernando.win_condition.l1 = "NPC_Death";
			pchar.quest.HWIC_Fernando.win_condition.l1.character = "HWICFernando";
			pchar.quest.HWIC_Fernando.function = "Fernando_died";
		break;
		
		//� ���� ��������
		case "Fleetwood_soldier"://��� ��������� ������ ��� ���� �� ����
			if (CheckAttribute(npchar, "quest.talked"))
			{
			dialog.text = "����� ��? �� ��� �� �� ��� ��� �����������? �� �������� ��� ��� ���... ��� ���: � ��� �������, � �������� �� ��������������� � �����������. ������, ����� ����� ����!";
			link.l1 = "�� � ������ �����...";
			link.l1.go = "Fleetwood_soldier_4";	
			}
			else
			{
			dialog.text = "��� �� ����� � ��� ��� ����� ����? ���������� �����������!";
			link.l1 = "��������, ���, � �������, ����� �� � ��� ���. ����� ���� ��������.";
			link.l1.go = "Fleetwood_soldier_1";	
			link.l2 = "� ���� ������� ������� ��������.";
			link.l2.go = "Fleetwood_soldier_2";		
			}
		break;
		
		case "Fleetwood_soldier_1":
			dialog.text = "�����. �� ����� �� �� ������. ������ ����� �������� ���������!";
			link.l1 = "��, �������.";
			link.l1.go = "Fleetwood_soldier_3";			
		break;
		
		case "Fleetwood_soldier_2":
			dialog.text = "��� ���? � ��� �� ��� ������, ��� �� ����� �����? ������������� ��� ���... ��� ���: � ��� �������, � �������� �� ��������������� � �����������. ������, ����� ����� ����!";
			link.l1 = "�� � ������ ����� ������� �������...";
			link.l1.go = "Fleetwood_soldier_4";	
		break;
		
		case "Fleetwood_soldier_3":
			DialogExit();
			npchar.quest.talked = "true";
			DoQuestReloadToLocation("SentJons_town", "reload", "houseSP3", "");
			pchar.quest.Fleetwood_Soldier.win_condition.l1 = "location";
			pchar.quest.Fleetwood_Soldier.win_condition.l1.location = "SentJons_houseSP3";
			pchar.quest.Fleetwood_Soldier.function = "Fleetwood_Soldier";//��� ���������
		break;
		
		case "Fleetwood_soldier_4":
			DialogExit();
			GoToPrison("SentJons", 1000, 10);			
		break;
		
		case "Theft_soldier":
			dialog.text = "����! ���? �����? ��, �������, ��������!";
			link.l1 = "�-�-��!";
			link.l1.go = "Attack_Theft_soldier";			
		break;
		
		case "Attack_Theft_soldier":
			LAi_group_Delete("EnemyFight");
			LAi_SetHP(npchar, 500, 500);
			LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Attack_soldier":
			dialog.text = "����! ��� ���� ��� ��� ������? ������, ����� �����! � ������!";
			link.l1 = "�-�-��!";
			link.l1.go = "Attack_soldier_fight";			
		break;
		
		case "Attack_soldier_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//����� ������ �����
			LAi_group_Delete("EnemyFight");
			for (i=1; i<=4; i++)
			{
			sld = characterFromId("Attack_sold_"+i);	
			LAi_SetWarriorType(sld);
            LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "PrepareToStreetFight");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		//��������-������� � �����
		case "Sailor_deck":
			chrDisableReloadToLocation = true;
			dialog.text = "�������, �� ��������� ����� ��������, ��� �� � �������. �������� ������ ������� ���... ��� ��� ��������� ��� ��� ������. ������� ������� ��� ������, �� �� ������� �������� ��� ������. ��� �� � ������������ - ��� ���� ���� ������� �� ����������� ����� �������� ��� ������ ����.";
			link.l1 = "������? ����� ���������... ��, � ����� � ��� � ��� ��������.";
			link.l1.go = "Sailor_deck_1";			
		break;
		
		case "Sailor_deck_1":
			DialogExit();
			GiveItem2Character(pchar, "NPC_Letter");
			AddQuestRecordInfo("LetterToAbi", "1");
		break;
		
		case "Sailor_deck_2":
			dialog.text = "����� ����� ����������, �������?";
			link.l1 = "��������� ��� ������ �� ����. � ������������� � ������� �� �����!";
			link.l1.go = "Sailor_deck_3";			
		break;
		
		case "Sailor_deck_3":
			dialog.text = "����, �������!";
			link.l1 = "...";
			link.l1.go = "Sailor_deck_4";			
		break;
		
		case "Sailor_deck_4":
			DialogExit();
			chrDisableReloadToLocation = false;
			AddQuestRecord("Holl_Gambit", "3-21");
			LAi_SetActorType(pchar);
			sld = characterFromId("KnippelClone");
			ChangeCharacterAddressGroup(sld, "none", "", "");
			sld.lifeday = 0;
			for (i=1; i<=3; i++)
			{
				sld = characterFromId("Sailor_"+i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "ReturnMCPlayer", 3);
			}
			pchar.questTemp.HWIC.Self = "toVillemstad";
			sld = characterFromId("Solomon");
			sld.greeting = "solomon_2";
			LocatorReloadEnterDisable("Villemstad_town", "houseSP2", false);//������� ��� ���
			LocatorReloadEnterDisable("Villemstad_houseSP2", "reload2", true);//������� ������� ���
		break;
		
		//�������-������� � �����
		case "Sailor_deck_5":
			chrDisableReloadToLocation = true;
			dialog.text = "�� ����������� ������� � �������, ��� �� ���������, �������. ��� ��� ������ �� ����, ������� �����. ������� �������, ��������� � ����� ������ ���������.";
			link.l1 = "������, ������. �� ������ ��� �� ���������� �� ����, � �������� ���������� � ��� �� �����. �����, �� ����� ������������ �����������?";
			link.l1.go = "Sailor_deck_6";			
		break;
		
		case "Sailor_deck_6":
			dialog.text = "��� ���������, ���.";
			link.l1 = "...";
			link.l1.go = "exit";	
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
		break;
		
		case "Sailor_deck_7":
			dialog.text = "��, �������?";
			link.l1 = "�������� �� ���� ������� � ���� �� ��������, �� ����, �� �����, ���� �� �������� �� ��������. ���� ����� ���������� ��������� �����. ��������� �� ����.";
			link.l1.go = "Sailor_deck_8";			
		break;
		
		case "Sailor_deck_8":
			dialog.text = "����, �������!";
			link.l1 = "";
			link.l1.go = "Sailor_deck_9";			
		break;
		
		case "Sailor_deck_9":
			chrDisableReloadToLocation = false;
			AddQuestRecord("Holl_Gambit", "3-48");
			sld = characterFromId("LongwayClone");
			LAi_SetActorType(sld);
			LAi_SetGroundSitType(sld);
			DialogExit();
			pchar.quest.Longway_Shore.win_condition.l1 = "location";
			pchar.quest.Longway_Shore.win_condition.l1.location = "Roseau_port";
			pchar.quest.Longway_Shore.function = "LongwayInShore";
		break;
		
		//������� - �������� ������ ��������
		case "Drunkard":
			dialog.text = "�-��! ������ �����, ���! ��� ��� �� ���� �����? �����, ��������� �������� ������� ��������? � �...";
			link.l1 = "��� ���, ������ ��������... ��� �� - ���� ��������?";
			link.l1.go = "Drunkard_1";			
		break;
		
		case "Drunkard_1":
			dialog.text = "�! �� �������, ��� �. ��� �� ���? � ���? ��-�-����-�-�� ��-�-��� ����-�-��...";
			link.l1 = "��������� ����, ����� ��� ��������! ����� ������? �� � ���� �� ���� ��������, ��� �� ���������� �����... ���������� ������?";
			link.l1.go = "Drunkard_2";			
		break;
		
		case "Drunkard_2":
			dialog.text = "���������� ������ ����. � ��� ������-�� ����? ������ ������ ������� � �� ����. � ������ ����.";
			link.l1 = "������ ������� �� ����, �� � ���������� �, ��� �� �� ��� ��������. ���� �� ������ ������... ��� ��� ������. �� ��� ������ � �������� � ��� ����� �� ���������� �����������, ��� ������� ��������.";
			link.l1.go = "Drunkard_3";			
		break;
		
		case "Drunkard_3":
			dialog.text = "��� ������� ��������? ��-�... �� ���� ����� �� ��������, ���� � ������ ������ � ���� �� �����.";
			link.l1 = "�������� � ������. ����� ���� �� ��������. �������, ��� �� ������ �� ����� �������� �� ������ ��������. ���� ���������. �������, ��� � ���� ������.";
			link.l1.go = "Drunkard_4";			
		break;
		
		case "Drunkard_4":
			dialog.text = "� ��� ��� - ��������? �������� � ����...";
			link.l1 = "�� ���� ����. ������ ������ - ������ ������. ��, � ���. �������.";
			link.l1.go = "Drunkard_5";			
		break;
		
		case "Drunkard_5":
			dialog.text = "������ �� ����� �������� �� ���� �-�... ��������, ���.";
			link.l1 = "�������. �� ������ �������� 5 000 ����.";
			link.l1.go = "Drunkard_6";			
		break;
		
		case "Drunkard_6":
			if (makeint(Pchar.money) >= 5000)
			{
			dialog.text = "���� �����? �-��... ������ �������� ������?";
			link.l1 = "�� ������. ���� ����� ������ ������. � ��� ������� � ������� � ������ �� ��� �����. � � ���� ��� ������. �� ������� ��������, � ������ �� ����� - � �� ����� �������� � ���� �����. ����� ������ �������, ����� ���� ��������� ����.";
			link.l1.go = "Drunkard_7";	
			}
			else
			{
			dialog.text = "���� �����? � � ��� ���� ��� ������?";
			link.l1 = "��! �������, ����. ������ �������.";
			link.l1.go = "Drunkard_no_money";	
			NextDiag.CurrentNode = "Drunkard_no_money";
			}
		break;
		
		case "Drunkard_no_money":
			dialog.text = "�� �������� ���� �����?";
			if (makeint(Pchar.money) >= 5000)
			{
			link.l1 = "��. ��� ���, �� ���������. �����.";
			link.l1.go = "Drunkard_7";
			}
			else
			{
			link.l1 = "���, ���, ����� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Drunkard_no_money";
			}
		break;
		
		case "Drunkard_7":
			AddMoneyToCharacter(pchar, -5000);
			RemoveItems(PChar, "MC_Letter", 1);
			dialog.text = "��... ���� ����� ������, ���?";
			link.l1 = "���, � ������� � ����... ������� ������, ������! ������� ���� ��� � ����� ���� �� �����!";
			link.l1.go = "Drunkard_8";			
		break;
		
		case "Drunkard_8":
		DialogExit();
		AddQuestRecord("Holl_Gambit", "3-26");
		LAi_SetStayType(npchar);
		LAi_RemoveLoginTime(npchar);//������� ����� ��������
		GetCharacterPos(pchar, &locx, &locy, &locz);
		ChangeCharacterAddressGroup(npchar, "sentjons_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
		LAi_SetActorType(npchar);
		LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "sentjons_town", "reload", "reload4_back", "DrunkardGoTown", -1);
		chrDisableReloadToLocation = true;//������� �������
		LocatorReloadEnterDisable("SentJons_town", "reload1_back", true);
		LocatorReloadEnterDisable("SentJons_town", "reload2_back", true);
		LocatorReloadEnterDisable("SentJons_town", "gate_back", true);//����� �� ������
		break;
		
		case "Drunkard_9":
			dialog.text = "�, ��� � ��, ���... �����, ����� �� � ����� �� �����. ������ ������ � ������, ����� �������� ���� ������. � �����, �� ���� �����...";
			link.l1 = "�� �� ���� ��! �� ���������, �� �� ������ �� ����� ������� - �� ��� ����� ����� ��� � ��� ������, ��-��! �� ���� �� �������������, ���...";
			link.l1.go = "Drunkard_10";			
		break;
		
		case "Drunkard_10":
			dialog.text = "��� ���� ������... ��� ��� ����� ���.";
			link.l1 = "����� ����. � �� ������� �������!";
			link.l1.go = "Drunkard_11";			
		break;
		
		case "Drunkard_11":
			GiveItem2Character(pchar, "MC_Letter");
			ChangeItemDescribe("MC_Letter", "itmdescr_MC_Letter1");
			AddQuestRecordInfo("FleetwoodAnswer", "1");
			dialog.text = "� ��� ��� ��� � ������ ������������� ����... ��������... ��� �� ��� �� ������.";
			link.l1 = "�����, ������ ��������, ��-��-��! ����-�-��-�-�� ��-�-��� ����-�-��... ����� � ���������, �� ��� ������!";
			link.l1.go = "Drunkard_12";			
		break;
		
		case "Drunkard_12":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Holl_Gambit", "3-27");
			pchar.questTemp.HWIC.Self = "FleetwoodAgree";
			AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
		break;
		
		//��� ����������� �����
		case "Cureer_abordage":
			dialog.text = "����! ������ ����� �� ��������� ��� �������? � ���� ��� �� ���������, �� ����� - ���� ������, � ������� �� �� ����� �� �������!";
			link.l1 = "��������. �� �������� ���, ������� ������, ��� ���� ���� �������� �. ��� �� ����� ���� �������, � ���� ������ ����. ��� �����, ����� �� ������� ��� ��� �������� ������ ���� - ������� ����� ������ ����������. ��� ��� ������... �� �������� ��������.";
			link.l1.go = "Cureer_abordage_1";			
		break;
		
		case "Cureer_abordage_1":
			dialog.text = "�������� ��������? ��...";
			link.l1 = "��� �� ���������� ��� ������, ��� ��� ��������� ��� ������? � ���� �������� � ������� ��������� �� �������� - ������� ����� ���������� �������� � ������ �����������.";
			link.l1.go = "Cureer_abordage_2";			
		break;
		
		case "Cureer_abordage_2":
			dialog.text = "�������, ��� �������. �������.";
			link.l1 = "��� � ������������. � ������ �� ����� � ���� ����������, ������. ��������, ��� ��� ������� ������� �������. ��� ��� �� �������� ������� � ������� �� ��������!";
			link.l1.go = "Cureer_abordage_3";			
		break;
		
		case "Cureer_abordage_3":
			DialogExit();
			sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
			Lai_SetPlayerType(pchar);
			LAi_RemoveCheckMinHP(sld);
			LAi_SetImmortal(sld, true);
			sld.ShipEnemyDisable  = true;
			pchar.quest.HWICCureer_AfterBattle.over = "yes";
			pchar.quest.HWICCureerOnMapOver.over = "yes";
			AddQuestRecord("Holl_Gambit", "3-39");
			Log_TestInfo("������ ������!");
			RemoveItems(PChar, "MC_Letter", 1);
			pchar.questTemp.HWIC.Self = "LetterToLucasSent";
			pchar.quest.Curacao_exploring.win_condition.l1 = "location";
			pchar.quest.Curacao_exploring.win_condition.l1.location = "Curacao";
			pchar.quest.Curacao_exploring.function = "CuracaoExploring";
			DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
			AddComplexSeaExpToScill(50, 50, 50, 100, 50, 50, 0);
			AddComplexSelfExpToScill(30, 30, 30, 30);
		break;
		
		//������ ��� � ������
		case "MatiasBek"://�� ������ ���� ������ ������� ����������
			dialog.text = "���� ���������� ���������! � �� ���� � ���������� �������� ���������! ��� ��� ������� ����������. ������, �������� ����� ���������� - �� �� ���� ����������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "MatiasBek";
		break;
		
		//�������� � ����� � ����������
		case "QuestGuard":
			dialog.text = "�������� ����� ��������� ������ �� ���������. ������ ������� �������� ���������� ����������.";
			link.l1 = "��. �������. �������� ��������� ����� ��������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "QuestGuard";		
		break;
		
		//����� ����������
		case "Stivesant":
			dialog.text = "������������ � ����������, �������. � ��� ������ ����� ����� � ����, ����� �������� ���������� � ������� ����. ���� �� ������������� � ������, �� ������ ��� ��� ���������� � ������������ � �����. �������� �� ����!";
			link.l1 = "������, ������ ����������.";
			link.l1.go = "Stivesant_1";			
		break;
		
		case "Stivesant_1":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload3_back", "Villemstad_townhall", "goto", "goto2", "OpenVillemstadResidence", -1);
		break;
		
		case "Stivesant_2":
			dialog.text = "�����! ��� ����� ����������? ��� ������ ���? ��� ������, ��� �� ��������� ��� � ������?";
			link.l1 = "������������, ������ ����������. � ������� �������������� ��� ����� � ���������� ��������� � ��������������� � ��������� ���������. �� ��� ������� ��������� ���������� ����� �� ���� ���������� ���������� � ����� ��������� ��������� ���������� ��������.";
			link.l1.go = "Stivesant_3";			
		break;
		
		case "Stivesant_3":
			dialog.text = "������ � ��� ����� ��������?";
			link.l1 = "�� ���� ������������������ ������� ���������� ����������. ������ ������� ����������� ��� ������� � ����� ������, ����� ������� ��� �������. �����, ����� ����, ��� � ������� ���� �� ���� �� ��������, �� ������� �������� ����������.";
			link.l1.go = "Stivesant_4";			
		break;
		
		case "Stivesant_4":
			dialog.text = "� ������� �� ������, ��� �������� �� ���������� ����� ���? ��� �� �����? ������� - ������� �����, �� �������� ������ �� �������� �������. ����� ��� ������, � �������, ������, ������, ����� ������������� ��������, �� ����������?";
			link.l1 = "������, ����� ������� ������� ������ ��� � ����� ������ ��������� ��������. ��� ��� ������ � ����� � ��������. ������� � ������ ������� � �������� ���� � ��������� ��� ������.";
			link.l1.go = "Stivesant_5";			
		break;
		
		case "Stivesant_5":
			dialog.text = "���� ������! �� ��� �� ����� ��������� �������������! �� ������� ���� ����� � ����� ���������, �����? ��� ������� ���������� ����������?";
			link.l1 = "����� � ����������, ������.";
			link.l1.go = "Stivesant_6";			
		break;
		
		case "Stivesant_6":
			dialog.text = "���-���... � �������� ���������� ����. ������ ��� ���� ��������. ��������� ������...";
			link.l1 = "�� ��� ��, � �� ��������. ������, ��� ������.";
			link.l1.go = "Stivesant_7";			
		break;
		
		case "Stivesant_7":
			DialogExit();
			sld = characterFromId("Villemstad_Mayor");
			ChangeCharacterAddressGroup(sld, "Villemstad_townhall", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "goto", "governor1", "DoubleTalkWithLucas", -1.0);
		break;
		
		case "Bek":
			dialog.text = "�� ����������� �� ���� ��������, ���������! ���� ��������� �����������. �� ���� �� ��������� ��� ���������� � ��������� ����������! ��� ���� ��� ��������� ��������� �� ������� ����, �����, �� ������� ������� �������������\n����� ���, � ���������! � ���� ��� � �� ���� ������� ��������� � �����������!";
			link.l1 = "��� ���? � ������ �� ����� ������� ����� ��� ���� ����������, � ��� ��, ��� �� ��� ������������ �� ������ ������?";
			link.l1.go = "Bek_1";			
		break;
		
		case "Bek_1":
			DialogExit();
			sld = characterFromId("Blaze");
			sld.Dialog.Filename = "Quest\HollandGambit\OtherNPC.c";
			sld.dialog.currentnode = "MC_Diag";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
		break;
		
		case "MC_Diag":
			dialog.text = "��������� ����. ������ ������� �� ��� ������� �� ���������� ����������.";
			link.l1 = "� �� ��� �����, ������, ��������� ��������? � �� ����� ��������� ������� �������� ���������?";
			link.l1.go = "MC_Diag_1";			
		break;
		
		case "MC_Diag_1":
			sld = characterFromId("Blaze");
			LAi_ActorTurnToCharacter(characterFromID("Stivesant"), sld);
			LAi_ActorTurnToCharacter(characterFromID("Villemstad_Mayor"), sld);
			dialog.text = "��� ��� - " + GetFullName(sld) + ". � ����� ��������� �������� ��������, ����������� ������� �������. ������ ��� ������� ������� ����� �� ��������� ������ ������... � ��� ������� ����� ���������� ����� ��������, ��� ����������� ������ ��������� ���������� �������� ���, ����������� �������� ���������, �� ��� ���������. � ��������� ��� �� ����, ��� ���� ��������� ���������� ����������\n������� ������ �� ���� �� ����� �������, ��������� ��� ��� �����. ����� � ������� ����������� �� ������� � ������� ����������� �������, � ����� � ���, ��� ������ ��� ���������, � ����� ���������� �� ���� ����, ���, ��� ��� ���� ��������, ������ ��� - ������� ���������� ������ ���������\n��������� � ��������� � �����, � �����, ��� �� ��������������� � ����� ������ ���������� �������� � ������� ������� �� �������� ���� ������. � ���������� � ����, ��������� �� ����� ��������, �, ������ ������, �������� ���. ������� ����� ������� ���� �����������, � �������� ������� ������� - �������� ������. � ����� �� ������� �� ������� ��� ���� �����, ������ ���������\n�� ������ ������������ ������ �� �������, � ������� ��������� �������� ����� ������� �����������. ���� ���� ������, � ������, ��� ������� ���������� ����� �� � ����������, � �������� �� ���. ���� ��� �� ���� ������������ ��������� �� ���������� ��������, ����� ������� ���������, �� ��� ��? � ������� ��� ��� ������ ������ �������� ������ ����� ��� �����, � ������� ��� ����� ������� �������?";
			link.l1 = "���... ��� ������ ����! ��� �� ������, ������?! �� ��� ������ �����?!";
			link.l1.go = "MC_Diag_2";			
		break;
		
		case "MC_Diag_2":
			dialog.text = "� - ��������� �������, ������� ������� �������� ���� � ����� �� ������� ��������, � ����������� �������� � ���� ������������ �������! � ����������� ������� ����������� � �������� ��� ���������. � � �����, ����� ��������� � �������� ������� �������� ����� ����� ����������� �� �������!";
			link.l1 = "����� ��������! �� �������� �� ���� �����, ������ '��������� �������'! ��...";
			link.l1.go = "MC_Diag_3";			
		break;
		
		case "MC_Diag_3":
			DialogExit();
			sld = characterFromId("Stivesant");
			sld.Dialog.Filename = "Quest\HollandGambit\OtherNPC.c";
			sld.dialog.currentnode = "Stivesant_8";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);		
		break;
		
		case "Stivesant_8":
			dialog.text = "��������, �����. ��� �� �������� �� ���� ��������! ���������� � ����������� ��� ����������. ����� ���������, � ������� ��� �� ������� �������� ������� ������, �� ��������� �� �������� ��������� �������� � �� ���������� � �������� �������� ����������� �������\n����� ����, � �������� ������������� �� ��������� ������ � ������ �������� ����� ����� ���������. �� ������ �������� ��� ������ � ���������� � ���������, ��� ����������� ����� �����. ������ ���!";
			link.l1 = "��...";
			link.l1.go = "Stivesant_9";			
		break;
		
		case "Stivesant_9":
			DialogExit();
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			PChar = GetMainCharacter();
			PChar.Dialog.Filename = "MainHero_dialog.c";
			LAi_ActorTurnToCharacter(pchar, characterFromID("Lucas"));
			sld = characterFromId("Lucas");
			LAi_SetImmortal(sld, true);//������ �� �������
			LAi_SetActorType(sld);
			ChangeCharacterAddressGroup(sld, "Villemstad_townhall", "goto", "goto6");
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "LucasGoToPrison", -1);
			for (i=3; i<=5; i++)
			{
			sld = characterFromId("StivesantGuard_"+i);
			LAi_ActorFollow(sld, characterFromID("Lucas"), "", -1);
			}
			EndQuestMovie();
			ChangeShowIntarface();
			LAi_SetActorType(PChar);
			DoQuestFunctionDelay("SecondDayInVillemstad", 6.0);
		break;
		
		case "Stivesant_10":
			dialog.text = "������� " + GetFullName(pchar) + "! �� ���� ������������� ������� ���������� ����� ������� ���� ��������� ������������� �� ���� ��������, � ���������� ������� ��� ��������� ���� ������� ����������. ����� ���� ������������� ��� �� ���� ����� - ��������, � ������ ��� ������.";
			link.l1 = "� ������ ��� ���� ����� ����������� �������, ������.";
			link.l1.go = "Stivesant_11";			
		break;
		
		case "Stivesant_11":
			dialog.text = "���� ���������� ������� ��������, ���� ���. ������ � ����� �� ������� ��������� ������������: ��������� �� ��������� '�������' ������������� � ������ ����� � ����� �� ��� �� ������� �������������, ������� ��������� ���� �� �����. �� ���� ������� ����������� ��������, � � ����� ��� ��� �������.";
			link.l1 = "����������, ������.";
			link.l1.go = "Stivesant_12";			
		break;
		
		case "Stivesant_12":
		//������� �������
		DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//������� ������� ���������� �������
		if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_MAYFANG)
		{
			pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
			pchar.Ship.name = "�����";
			SetBaseShipData(pchar);
			SetCrewQuantityOverMax(PChar, 0);//������ �� �������
		}
		else
		{
			for(i = 1; i < COMPANION_MAX; i++)
			{
			int iTemp = GetCompanionIndex(PChar, i);
			if(iTemp > 0)
				{
				sld = GetCharacter(iTemp);
				if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MAYFANG)
					{
						pchar.questTemp.HWIC.Self.CompanionIndex = sld.Index;
						sld = GetCharacter(sti(pchar.questTemp.HWIC.Self.CompanionIndex));
						RemoveCharacterCompanion(PChar, sld);
						AddPassenger(PChar, sld, false);
					}
				}
			}
		}
			dialog.text = "� � ����� ��� ����� ������ � ���������� - �� ������ ���������� �� ���� ���������� ���������� ��������� �� ���� ������ � �� �����. ����� ��� �� �������� �����.";
			link.l1 = "������, ������. ���� � ��� �� ������ ������.";
			link.l1.go = "Stivesant_13";			
		break;
		
		case "Stivesant_13":
			DialogExit();
			sld = characterFromId("Villemstad_Mayor");
			sld.dialog.currentnode = "Bek_2";
			LAi_ActorDialog(sld, pchar, "", 0, 0);
		break;
		
		case "Bek_2":
			dialog.text = "� ���� ���� ������������� ���, �������, �� ���� ���������������� � �� �������� ����� ������������� ������. �� �������� ������ ������ ���� - � ���������� ��� ��� ������ �������.";
			link.l1 = "�������, ������ ���. ���� �����������!";
			link.l1.go = "Bek_3";			
		break;
		
		case "Bek_3":
			DialogExit();
			pchar.quest.Award_FromPiter.win_condition.l1 = "Timer";
			pchar.quest.Award_FromPiter.win_condition.l1.date.hour  = 9.0;
			pchar.quest.Award_FromPiter.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Award_FromPiter.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Award_FromPiter.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Award_FromPiter.function = "OpenResidenceDoor";
			bDisableFastReload = false;
			LocatorReloadEnterDisable("Villemstad_town", "reload5_back", false);
			LocatorReloadEnterDisable("Villemstad_town", "reload10_back", false);
			LocatorReloadEnterDisable("Villemstad_town", "reload3_back", true);//������� ���� � ����������
			LocatorReloadEnterDisable("Villemstad_town", "reloadR1", true);//������� ������� ���� � ����������
			AddQuestRecord("Holl_Gambit", "3-53");
			DoQuestReloadToLocation("Villemstad_prison", "goto", "goto23", "TalkWithLucasPrisoner");
			for (i=4; i<=5; i++)
			{
				sld = characterFromId("StivesantGuard_"+i);
				sld.lifeday = 0;//��������� ������
			}
		break;
		
		case "Stivesant_14":
			dialog.text = "" + GetFullName(pchar) + ", ������ ���������� ���������� ���������, �� ����������� ���������� � ����������� ����� ����������� �����, ���������������� ����������� ������� ��������, �� ������������� ������� ������� � �������� ������ � ������� 100 000 ����. ����������!";
			link.l1 = "���������, ������ ����������!";
			link.l1.go = "Stivesant_15";			
		break;
		
		case "Stivesant_15":
			dialog.text = "�����, �� ��������������� ������, �� ��������� ��������� �������� ������ �������� � ���������� � ������ ������� ����-��������� ��������, ����������� � ��������� ������, �� ������������� �������� ������� � ������� 150 000 ����. ����� �� ��������� ����� �� ���������� ���������� � ����������� ����-������� ���������\n������, ��� ����� ����-�������� ������ ������ ����� �������, ��������� ������ �������� ��������, � ����� �������� ���� ������.";
			link.l1 = "�������! ����� ��� �� ��������.";
			link.l1.go = "Stivesant_16";			
		break;
		
		case "Stivesant_16":
	AddMoneyToCharacter(pchar, 250000);
	GiveItem2Character(pchar, "newblade20");
	ChangeCharacterComplexReputation(pchar, "nobility", 5);
	ChangeCharacterNationReputation(pchar, HOLLAND, 25);
			dialog.text = "��, � �� ������ ������ ������������ �� ��� ���������� � ����� ��������, �� ��� ���, ���� ���������� �� ������� � � ��������� ���������. ����� ������������ ����� ����������� �����������, ������� ����.";
			link.l1 = "";
			link.l1.go = "Stivesant_17";			
		break;
		
		case "Stivesant_17":
			DialogExit();
			LAi_SetPlayerType(pchar);
			sld = characterFromId("Villemstad_Mayor");
			LAi_SetActorType(sld);
			sld.dialog.currentnode = "Bek_4";
			LAi_ActorDialog(sld, pchar, "", -1, 0);		
		break;
		
		case "Bek_4":
			dialog.text = "������� ��� ���� ��������� �������������, �������, �� ����������� ��������� � �������� � ��������� ���������������� ��������. � ���� �������� ��� ��� ���� ������ ������������� ������ - ����������� ��� �������� ������ ����.";
			link.l1 = "�������, ������ ���.";
			link.l1.go = "Bek_5";			
		break;
		
		case "Bek_5":
			GiveItem2Character(pchar, "bussol");
			dialog.text = "� ������: � ���� ���� �� ������ �����, � ��� ������ ������. �� ������ �������� ����� � ���� ����������. �������� � ����� �����, �� ����� �������� - � ���� ��� ������� ��� ����� ������, ������� �����������.";
			link.l1 = "��� ������� ���, ������!";
			link.l1.go = "Bek_6";			
		break;
		
		case "Bek_6"://������� ������� � ������
			DialogExit();
			AddQuestRecord("Holl_Gambit", "3-54");
			LAi_SetPlayerType(pchar);
			sld = characterFromId("Villemstad_Mayor");
			LAi_SetHuberStayType(sld);
			sld.Dialog.Filename = "Common_Mayor.c";//patch-8
			sld.dialog.currentnode = "First time";
			sld.quest.meeting = "1";
			for (i=1; i<=3; i++)
			{
				sld = characterFromId("StivesantGuard_"+i);
				sld.lifeday = 0;//��������� ������
			}
			sld = characterFromId("Stivesant");
			LAi_ActorGoToLocator(sld, "goto", "goto6", "StivesantSitDown", -1);
			bDisableFastReload = false;
			LocatorReloadEnterDisable("Villemstad_town", "reload1_back", false);
			LocatorReloadEnterDisable("Villemstad_town", "reload2_back", false);
			LocatorReloadEnterDisable("Villemstad_town", "gate_back", false);
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		break;
		
		case "Bek_7":
			dialog.text = "��������� �������� ����, ������. �� ����� ���������, ��� ��, � �������� ���� ������������ ����� � ��������� ��������. ����� ���, ��� ���� �������.";
			link.l1 = "���������, ������. ������ �� ����� ��������� - ����� ��� ����!";
			link.l1.go = "Bek_8";
		break;
		
		case "Bek_8":
			TakeNItems(pchar, "gold_dublon", 1000);
			ChangeCharacterComplexReputation(pchar,"authority", 5);
		ChangeCharacterNationReputation(pchar, HOLLAND, 50);
			DialogExit();
			sld = characterFromId("Lucas");
			LAi_SetActorType(sld);
			sld.dialog.currentnode = "LucasAward_2";
			LAi_ActorDialog(sld, pchar, "", -1, 0);
		break;
		
		case "Stivesant_18":
			dialog.text = "��� ��� ������. ��� � ��� ����?";
			link.l1 = "� ���� ��� ������. � ������ ����� ��� ���������.";
			link.l1.go = "exit";	
			NextDiag.TempNode = "Stivesant_18";
		break;
		
		// Jason ���
		case "Stivesant_19":
			if (ChangeCharacterHunterScore(pchar, "holhunter", 0) > 10)
			{
				dialog.text = "�! ��� ������! ��� �� ��� " + GetFullName(pchar) + ". �� ��� ��� ������� �������� ��������� �� ��������, ����� ��� ������� ��� ����. � ������, ��� ��� ������ ��� � ����������� �����.";
				link.l1 = "�... �������, ��� ����.";
				link.l1.go = "arest";
				break;
			}
			if (pchar.questTemp.Patria == "epizode_4")
			{
				dialog.text = "�� ������� ������-�������� ����� �������? ������, � ���� ���� � ��� ������� �� ����������� ����, � ��� ��������. ��� ������� ��� ����?";
				link.l1 = "������ ����������, � ������ � ����-���������� � ��������� �� �������-����������� ����������� ������� ������� ������� �� ������.";
				link.l1.go = "Stivesant_20";
			}
			else
			{
				dialog.text = "����� ��������, �������, �� � ������ ����� ����� � �� ���� ������� ��� �� ������ �������. ���������� � ������� ������� ����, ����� �� ��� ���������.";
				link.l1 = "��...";
				link.l1.go = "Stivesant_19_1";
			}
		break;
		
		case "Stivesant_19_1":
			DialogExit();
			npchar.dialog.currentnode = "Stivesant_19";
		break;
		
		case "Stivesant_20":
			sld = characterFromId("Patria_FlautCap");
			dialog.text = "�� ������� �� ������? ��� �� �� ������, ��� �� ���� ��� ��� ����... ���... ��� ���� � �������?";
			link.l1 = "��� ������, ������. ����� �� ������ ������� ��� �������� ��� ��� ��� ������ � ��������� ����� �� ����. ����� � ��� ������ ������� ����������� ����� '"+sld.ship.name+"' � ������ ��� ����� �������� � ���� �����������. ����� ����� �� �����, ���� � �������.";
			link.l1.go = "Stivesant_21";
		break;
		
		case "Stivesant_21":
			dialog.text = "����� � ������ ��� ��������? ��� ���������... � ������, �������?";
			link.l1 = "��� ���, ����������.";
			link.l1.go = "Stivesant_22";
		break;
		
		case "Stivesant_22":
			RemoveItems(pchar, "Reserve_item_01", 1);
			dialog.text = "���-���... (������). ��������� �� ����������, ������... ���... ��-��, ��-��... �������, ��-��... ������, �������, � ������, ������� ������ ����� ��������� ����� ������ ������� �� �������? ����� � ���������� ����� ���-����, ����������� ��������� ������� ������� � ���������� ��������� ����...";
			link.l1 = "� ��������� ��������� ��������� ������ ����-�-������, ������. � ����� ���-���� ������������ ����� �������� ������������ ���������� �� �������� �� ���������������� ��������� �� ���� �� �����. ���� ��������� � �������� ��� ����� �� ���������� �������� � �����������... ����� ��� ����� �� �������?";
			link.l1.go = "Stivesant_23";
		break;
		
		case "Stivesant_23":
			dialog.text = "� �� ���� ��� �����������, �������, �� �� ������� �������, � ��� ��������� ����� ���, �� � �������, ������, � ����������� ���� ������ �����������. ������ ��� ������� ��������� ����� �����, � ��������, ��� ����, � � ���������� ��� ����� �� ������. ���������, ���������, ������ ��� �������� ���� ��� ����, ��� ���������...";
			link.l1 = "���������, ������, ��������� ����� �������� ����...";
			link.l1.go = "Stivesant_24";
		break;
		
		case "Stivesant_24":
			chrDisableReloadToLocation = true;//������� �������
			pchar.quest.Patria_CureerTimeOver.over = "yes"; //����� ������
			pchar.quest.Patria_CureerFail.over = "yes"; //����� ����������
			sld = characterFromId("Patria_FlautCap");
			RemoveCharacterCompanion(pchar, sld);
			sld.lifeday = 0;
			DialogExit();
			npchar.dialog.currentnode = "Stivesant_25";
			LAi_SetActorType(npchar);
			ChangeCharacterAddressGroup(npchar, "Villemstad_townhall", "goto", "goto6");
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "Patria_StivesantWait", -1);
			pchar.questTemp.Patria = "epizode_4_return";
		break;
		
		case "Stivesant_25":
			GiveItem2Character(pchar, "Reserve_item_01");
			ChangeItemDescribe("Reserve_item_01", "itmdescr_Reserve_item_01_2");
			dialog.text = "����� ��� ����� �� ������ �����. ���, ��������, ����������... ����������� ����, �������.";
			link.l1 = "�������, ������. �� ��������!";
			link.l1.go = "Stivesant_26";
		break;
		
		case "Stivesant_26":
			DialogExit();
			npchar.dialog.currentnode = "Stivesant_19";
			chrDisableReloadToLocation = false;
			AddQuestRecord("Patria", "23");
			SetFunctionTimerCondition("Patria_CureerBackOver", 0, 0, 31, false);
		break;
		
		case "Stivesant_27":
			if (ChangeCharacterHunterScore(pchar, "holhunter", 0) > 10)
			{
				dialog.text = "�! ��� ������! ��� �� ��� " + GetFullName(pchar) + ". �� ��� ��� ������� �������� ��������� �� ��������, ����� ��� ������� ��� ����. � ������, ��� ��� ������ ��� � ����������� �����.";
				link.l1 = "�... �������, ��� ����.";
				link.l1.go = "arest";
				break;
			}
			if (pchar.questTemp.Patria == "epizode_6")
			{
				dialog.text = "�� ����� � ��������� �� �������-����������� ������� �� ������, ���?";
				link.l1 = "��, ������ ����������. � ������� ����-�������� ��������� ���������� ������������� - �������, �� ����� �������� ��� ��������� �� ������, ����� ����� �����, ��� ��������� ������ �����������, �...";
				link.l1.go = "Stivesant_28";
			}
			else
			{
				dialog.text = "����� ��������, �������, �� � ������ ����� ����� � �� ���� ������� ��� �� ������ �������. ���������� � ������� ������� ����, ����� �� ��� ���������.";
				link.l1 = "��...";
				link.l1.go = "Stivesant_27_1";
			}
		break;
		
		case "Stivesant_27_1":
			DialogExit();
			npchar.dialog.currentnode = "Stivesant_27";
		break;
		
		case "Stivesant_28":
			if (pchar.questTemp.HWIC.Detector == "holl_win" || pchar.questTemp.HWIC.Detector == "self_win")
			{
				dialog.text = "� ������� �� �����, �������. �� ���� ��������� � ��������������� ��������: ��������� �������, ��� �� ������ �� � ���� �� ����-��������. ������ � ����. � ���������� ��������� �� ���������� - ����� ��������� ���-������, ��� �� ������ ����������� ��� � ��� �� ������ ������� �� ���������� �����.";
				link.l1 = "��� � ��������?";
				link.l1.go = "Stivesant_29";
			}
			else
			{
				dialog.text = "� ������� �� �����, �������. �� ���� ��������� � ��������������� ��������: ��� ��� ��������� �������� �� ����-��������, ������� ������� ����� ������� ��� ���������� ��������. � �� ���, � �����, ��������� �����. � ���, ������� " + GetFullName(pchar) + ", � ��� ���� ���� ������� �� �������� ��������, ��������� � ���������� ����������� �������� ���������, ������� �� ����� ��������������\n�������! ������� ������ � �������� � ��������� � �����������!";
				link.l1 = "��� �������, ��� ����������� ������������ ������� �� ��� ���������� �� ���������� ����� �����������!";
				link.l1.go = "Stivesant_31";
			}
		break;
		
		case "Stivesant_29":
			dialog.text = "����� � �����, �������. ��� �������� ��� ������, � ��� ������� �������������, ��� ������ �� �������. ����� �������. �������, ��������� ����� " + GetFullName(pchar) + " � ������!";
			link.l1 = "...";
			link.l1.go = "Stivesant_30";
		break;
		
		case "Stivesant_30":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload3", "Patria_DiplomatGetOut");
		break;
		
		case "Stivesant_31":
			dialog.text = "� ���������, � ���� ������ ������. �������! � ������ ������������� ���������� ����!";
			link.l1 = "�� ������ ��� �� ������, � ��� ���������, ������...";
			link.l1.go = "Stivesant_32";
		break;
		
		case "Stivesant_32":
			DialogExit();
			Patria_DiplomatFight();
		break;
		
		case "Stivesant_33":
			dialog.text = "������� ������� ������ ���, ������� "+GetFullName(pchar)+", � ���� ����... �������, �� ������� ������������� ������������������ ���, ��������� � ��� �� ����������.";
			link.l1 = "������ ���� � ���� �������, ������ ����������.";
			link.l1.go = "Stivesant_34";
		break;
		
		case "Stivesant_34":
			dialog.text = "����, �� ������ ���� ��� ��� ��������� ����������, ������� �� �����������? � ��� �������, ��� ����� ��, ��� ����������� � ������?";
			link.l1 = "������, ������, ������ � ����������� �����. �� ������� ������� - �������������� ��������� �� �����������, ����� �� ����� ���������� �� ������ ����-�������. �� ������� ������ - ����������� �������� �����. ����������� ��� �������... �� �, �������, ���������, ��������� � ����������� ������, ������� �� ������� � ����� � ������������ ���� �������� ����������.";
			link.l1.go = "Stivesant_35";
		break;
		
		case "Stivesant_35":
			dialog.text = "������ ������� ���� ��� ���� ��������.";
			link.l1 = "����������.";
			link.l1.go = "Stivesant_36";
		break;
		
		case "Stivesant_36":
			dialog.text = "...(������)...";
			link.l1 = "...";
			link.l1.go = "Stivesant_37";
		break;
		
		case "Stivesant_37":
			LAi_Fade("", "");
			dialog.text = "��������� �� �� �������� ��� ������, � ����� ��������� ��� ����������. ����������� ����������� � ��� ������� ��� ���� ������� �����.";
			link.l1 = "����� ��������� ��� ��� ���������� ���������. � ����������� �������-������������ �������� �� ������ ������������ �������� �� ������� �������, ��������� ����� �������� �� ������� ������.";
			link.l1.go = "Stivesant_38";
		break;
		
		case "Stivesant_38":
			dialog.text = "...(�����������)...";
			link.l1 = "�������! ������ �������� ��...";
			link.l1.go = "Stivesant_39";
		break;
		
		case "Stivesant_39":
			LAi_Fade("", "");
			dialog.text = "������, � �������, �� ������� ����� � ������?";
			link.l1 = "��� ������� ��������. �������, ��� ��� ������ ���������� ����� ����������� ����������� �������� ��� ���������.";
			link.l1.go = "Stivesant_40";
		break;
		
		case "Stivesant_40":
			dialog.text = "���� �� ��������� ��������� �� ������� ������ ��� �������, �� �� ����� ��������� ������� ��������, �� ������������.";
			link.l1 = "��������� ������ �����, ��� �������, ������ ����������. � ������ ������ �������� ������������ � ����������. ����� ����� ����� � ���� ������� ������ ������� ���� �������.";
			link.l1.go = "Stivesant_41";
		break;
		
		case "Stivesant_41":
			DialogExit(); // ���������� ������, �������� �����
			Patria_CuracaoStivesantGo();
		break;
		
		case "Stivesant_42":
			dialog.text = "����, ��� �� - ����� ����� �����? ��, �� ��� ��� � ��� ����-������� ����������� ��������! ������������, ������������, ��������� ����� ����-�������! ������� ��� ��� ���� ����� ������ ������� ��������� ���������� - ������� �� ������, �� ���� �� ������� � ������ ������...";
			link.l1 = "� ������ ������ ����-������� �� ������� ������ ������� � ��� ��������� �������������, �� ���� ����.";
			link.l1.go = "Stivesant_43";
		break;
		
		case "Stivesant_43":
			dialog.text = "������ ������ ������, ��� � ��� �������, �����, � ��� ����-��������� � ������� ������ - ������. �������� ������ ����������� ������� ������ ��. ��-�����... �������, �� ����� �� ���, ����� �������� �����, ��������������� ������ � ������ �������� ��������?";
			link.l1 = "������, ������.";
			link.l1.go = "Stivesant_44";
		break;
		
		case "Stivesant_44":
			dialog.text = "����� ��������� � ���� ����. ��� ����� �������� � ����� � ������ ������������ �� ������� � ��������� ������ �����. ����� � ��� ���� ����� ����� �����, ����������� � ���� �����������, � ������ �������� ������� �� ������. � ��� ����������, ��� ���������� ���� ����� � ����� ����������������� �������� ������ ������� ������ ��� ���������� ����.";
			link.l1 = "��� �� ������ �� ���� ��������?";
			link.l1.go = "Stivesant_45";
		break;
		
		case "Stivesant_45":
			dialog.text = "�-�, ����� �������. ������� ���� ��������.";
			link.l1 = "������� ����?!!";
			link.l1.go = "Stivesant_46";
		break;
		
		case "Stivesant_46":
			dialog.text = "��� �����, �����. ��� ����� ���� �� �������� ������� ��� ������, ���������� �������� ������. � ��� ��� �����: ���������� � ������ �������� ����-��������... �� ����� ������ � ������ � ����... ������ ������, �� ��������� �������� �������� ���������, � ������� ������� �� ����� ��� ���� ������ ���������. � � ���� ����������� ������\n���� ��� ��� - ���� �����. �� ��������� ����� �������, ���� �� �� ��������� ��������� �����, � �������� ������ �������, � ������� ����� ����������� ������ ������ �� ���. ��� �� ���� ��������� - �������, �� �������������.";
			link.l1 = "��� ����� ������ �� ������! �� �� ���������, ��� � ���� �� ����� ���� � ����� � �������� ��������!";
			link.l1.go = "Stivesant_47";
		break;
		
		case "Stivesant_47":
			dialog.text = "�������, �������. ������� ����� ������ ��� ��������, � �������� ���� ������� ����. ���� �� ����� ����-������� ������� ���, �� ����� ����� ��� ���, �����, ����� ������ ������ � ������ ������, ��� ������� ������� ��� ������, ����� �� �������� �������� ����� ��������. �� � ��� ����-�������.... �������, �� ������� ������ ������������� ����, �� ����������... �, ��������, ���� ����������� ������ ������ ��������, ��� ���� ������ �������\n��, �������, �� ���� ��������. ��� ��� � ��������� � ������� ������ � ���� � ����������. ��������� ���� � ����� ����������. ����� �������!";
			link.l1 = "...";
			link.l1.go = "Stivesant_48";
		break;
		
		case "Stivesant_48":
			DialogExit();
			LAi_SetActorType(pchar);
			SetMainCharacterIndex(GetCharacterIndex("Blaze"));
			pchar = GetMainCharacter();			
			LAi_SetPlayerType(pchar);
			locCameraTarget(pchar);
			locCameraFollow();
			EndQuestMovie();
			InterfaceStates.Buttons.Save.enable = true;
			bDisableCharacterMenu = false;
			sld = CharacterFromID("Noel");
			sld.dialog.currentnode = "noel_84";
			LAi_SetActorType(sld);
			LAi_ActorDialogDelay(sld, pchar, "", 1.5);
			sld = CharacterFromID("Stivesant");
			LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "Patria_CondotierStivesantInHall", 12.0);
			for (i=1; i<=3; i++)
			{
				sld = CharacterFromID("Stivesant_sold_"+i);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
			}
		break;
		
		case "Stivesant_49":
			if (sti(pchar.money) >= 1000000)
			{
				dialog.text = "� ���� �� ����������, ����-������� "+GetFullName(pchar)+", ��� �� ��������� ��� ��� ������. �������, � ���� �������� � ��� ��������, �� �� �����... ����� - ���� ����� � ����� ��������� ����, ���? ���� � ����� ��� ������������, ������ �� ������� ������ ����� �� ������, � ����? �����������, ������� - �������� ����� �� ��������� �������-����������� ����������� �������! �� �������� �� �� �������� ������, �������� ���� �������� ������.";
				link.l1 = "�������� ��� �������, ������. � � �� ����� �������� �������� ��������.";
				link.l1.go = "Stivesant_50";
			}
			else
			{
				dialog.text = "��� ����� ��������������� �� ����� ��������, �����, � �� ������� ����� �� ������ ������.";
				link.l1 = "...";
				link.l1.go = "Stivesant_49_1";
			}
		break;
		
		case "Stivesant_49_1":
			DialogExit();
			npchar.dialog.currentnode = "Stivesant_49";
		break;
		
		case "Stivesant_50":
			pchar.quest.Patria_CondotierStivesantTimeOver.over = "yes"; // ����� ������
			AddMoneyToCharacter(pchar, -1000000);
			GiveItem2Character(pchar, "Reserve_item_01");
			ref itm = ItemsFromID("Reserve_item_01");
			itm.picIndex = 15;
			itm.picTexture = "ITEMS_26";
			itm.price = 0;
			itm.Weight = 2.0;
			itm.name = "itmname_Reserve_item_01_1";
			ChangeItemDescribe("Reserve_item_01", "itmdescr_Reserve_item_01_4");
			dialog.text = "�������, ����-�������. � �� ��������� ���: ����� �� ������� �������-������������, �� �������, ��� ����������� ����-������� �������� �������� - ����� �������� ������� �������, ��� ������ � ������������ ���������. �� ����� �� ������, ��� ���� ���� ����������� �����, �� ������� ��� ����? ���� ���, �� �������. ��� ��� � � ���� �� ��������. ������� ���� ������. �������, ��� ����� ����� ���������� �����������, ����� ���������� �������.";
			link.l1 = "���������. ����� �������, ������ ����������.";
			link.l1.go = "Stivesant_51";
		break;
		
		case "Stivesant_51":
			DialogExit();
			AddQuestRecord("Patria", "84");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "", -1);
			pchar.quest.Patria_CondotierCabin.win_condition.l1 = "location";
			pchar.quest.Patria_CondotierCabin.win_condition.l1.location = "Curacao";
			pchar.quest.Patria_CondotierCabin.function = "Patria_CondotierCabin";
		break;
		
		case "vanberg_sold":
			dialog.text = "��-��! �� ������ ����������! ���� ��� ����, ��� ������ - ���� ������ ���������� �� ������ �� ������ ���. ������, � ���� �������� ����� ���� ������. ����������� ���� � ����� �������, ��������, ������� ���� � ��������. �� �� �����, ��� ����� �����...";
			link.l1 = "���������, ����! �� ������... ��, ���, � ��� ��� ������ �� �����!";
			link.l1.go = "vanberg_sold_1";			
		break;
		
		case "vanberg_sold_1":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("vanberg_sold_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "PrepareMassakraInShore");
			AddDialogExitQuest("MainHeroFightModeOn");			
		break;
		
		case "Abihouselady":
			dialog.text = "�� ����-�� �����?";
			link.l1 = "��, ���. � ��� ������� � �������� �����?";
			link.l1.go = "Abihouselady_1";			
		break;
		
		case "Abihouselady_1":
			dialog.text = "��� ����� ������ �� �����. ���� ��� ���� �� �� �� �������, � ��� ��������� � ������ �� ������ ����. �������� �������� ��������� � �����������, � �������... ��, �� ������ ������ ����� ��� � �������. �� �� �������� ������� � �����\n�������� ��������, ��� �������� ������ �����, ����� ���������� �� ���� � �� ���������� ������ ����. � ���� �� ���� ��������� ��� ������ ���������... ���� ��� �� ����������. ��� ��� � ������� - ������...";
			link.l1 = "�� ��.. �����, ������� �� ����������. ��� ����.";
			link.l1.go = "Abihouselady_2";
		break;
		
		case "Abihouselady_2":
			DialogExit();
			NextDiag.CurrentNode = "Abihouselady_3";
		break;
		
		case "Abihouselady_3":
			dialog.text = "�� ��� ���-�� ������ ������, ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Abihouselady_3";
		break;
		
		//�������� ������� ��� ������� ������
		case "TempOffGuard":
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//������� ������� ���������� �������
			if(sti(RealShips[sti(pchar.ship.type)].basetype) == SHIP_MAYFANG)
			{
				pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);
				pchar.Ship.name = "�����";
				SetBaseShipData(pchar);
				SetCrewQuantityOverMax(PChar, 0);//������ �� �������
			}
			else
			{
				for(i = 1; i < COMPANION_MAX; i++)
				{
						iTemp = GetCompanionIndex(PChar, i);
					if(iTemp > 0)
					{
						sld = GetCharacter(iTemp);
						if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MAYFANG)
						{
							pchar.questTemp.HWIC.Self.CompanionIndex = sld.Index;
							sld = GetCharacter(sti(pchar.questTemp.HWIC.Self.CompanionIndex));
							RemoveCharacterCompanion(PChar, sld);
							AddPassenger(PChar, sld, false);
						}
					}
				}
			}
			dialog.text = "�������, �� ���������� �������� ��������� ���� ������� ����������� ����-������� ��������. � ����������� ������������ ��� � ���, � � ������ ������������� - ��������� ���� ��� ���������. ��� ������ ������ �����������.";
			link.l1 = "�� ��� ��, ��� ������ ������ �����������... � �� ���� ��������� � ���������� ��-�� ������-�� �������. ���������.";
			link.l1.go = "TempOffGuard_1";			
		break;
		
		case "TempOffGuard_1":
			dialog.text = "���, ��� �� �������� ���������� ������������.";
			link.l1 = "...";
			link.l1.go = "TempOffGuard_2";
		break;
		
		case "TempOffGuard_2":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 10.0);
			chrDisableReloadToLocation = false;//������� �������
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");
		break;
		
		// Jason ���
		case "arest":
			dialog.text = "������� ����, ��� ��������. ������! ����� ���!";
		    link.l1 = "��, �� ���!";
		    link.l1.go = "fight";
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
		
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
		break;
	}
}