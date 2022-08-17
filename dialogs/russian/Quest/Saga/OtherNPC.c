// ������ ������ ��� �� ������ ����
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
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, �������, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
//-------------------------------������ � ���� � �������-��-���------------------------------------
		case "Jimmy":
			dialog.text = "���� ���� ����? �� ������ - ���� � ����! ����������, ���� � �� ������� ���� � ��������! ";
			link.l1 = "������� ���� ���� ��� ������, ��� � ���� ����, � ����� ��� � �������� �������, ����� ���������...";
			link.l1.go = "Jimmy_1_1";
			link.l2 = "��� ���� ��� ���������, ������? �� ���� ��� ������ ����, ���� � ���� �� �������� �����-������ ��������! ������ ��� ����� ��������� ������ �������� �����, ��� ��, ��������� �� ������ ������, ������ �� ���������...";
			link.l2.go = "Jimmy_1_2";
		break;
		
		case "Jimmy_1_1":
			dialog.text = "�������� ���������� ����� ����! ����� ��� ��������� ������ �����. ��� �� ���� ���������� ������ ��������, �� �� ���� � ��������� ������!";
			link.l1 = "...";
			link.l1.go = "Jimmy_fight";
		break;
		
		case "Jimmy_fight":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetImmortal(npchar, false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Saga_KillJimmy");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Jimmy_1_2":
			dialog.text = "��?! �� �������? ����, �� �����...";
			link.l1 = "�� ��� �� �, "+pchar.name+"! ������ �� �������� � ����� � �������� ����� ����, ��� �� ���� ���� �� ������� ����� ����� ������� � �������. ��� ��� �����, ������? �������� �� ������... ��������� �� ��� � ����, �� �������� �� ����� ��� �������!";
			link.l1.go = "Jimmy_2";
		break;
		
		case "Jimmy_2":
			dialog.text = "��� ����� �����! ����� �������, ������� ������� '�������'! ������� ��������! ��� �� ��������, ��� � ��� ���� �� �������� � �������?";
			link.l1 = "��� � ����! �� ���������� �� ���� ��� ������� �� ��������. � ���� �� ���� ������, ���� �� �� ��������� ���� ������. ������ ��, �� ������ �� ��������, ����� ���� �������� �� �������� �������� �������.";
			link.l1.go = "Jimmy_3";
		break;
		
		case "Jimmy_3":
			dialog.text = "����! ���� �� � ���� ��� �������! ����� �������� ����� ����� ����� �������... ��! ���� �� ��������� ��� �� ��� - � ���� �������!";
			link.l1 = "�� �����, ��-��! � ���, ����� ������������� ����� ����� ���������?";
			link.l1.go = "Jimmy_4";
		break;
		
		case "Jimmy_4":
			dialog.text = "��� ��! ����� ��� � �� �������� �� ��� ���. �� ��� ������ ������� ���� ����. �� ���� �������� ��� ������ �� ��������. ��� ��� �� �������� ������� �������, ��� ��� ���� ����������� �������, �� ���� �������� ������� �� ��� �����. � ���� ���� ��! ��� � ������ ���� ��������� ��� �������?";
			link.l1 = "����, ��������! � ���� ����� ���� ���... � � ���� �� ����, ��� ������� ���� ������ �����?";
			link.l1.go = "Jimmy_5";
		break;
		
		case "Jimmy_5":
			dialog.text = "�� ��� ��! �� ���� ������-�� ����� ����������, ������ ������� � ������� �� �������� �������� � �������� �������, �������� �������� ��� �� ����. �� ��������� ������ ���� ����� ������ ������� ����� �� ������. ��� ��������.";
			link.l1 = "������! � ������ �� ������ �������.";
			link.l1.go = "Jimmy_6";
		break;
		
		case "Jimmy_6":
			dialog.text = "������ ������! ��� �� ������ �� ���������! � ��� ����� ����� ������ �������� � ������� �������, ��� ������ ����� ����� �� ���� ��� ������ ��� ��� �������� ��� �����. � �� ����� ��� ���� � ������. � �� ������� ���� ����� ��� �������\n������� ���� ���-�� ����� �� �����. ������������, ��� ��� ��� ����� � �������� � ����� ����, ��������� ����� �� ��������� ������. ��� ����� ������ � ��������� �� �����. ��� ��� ������� ���� ��������� ������� ������ ������ � ����� �� ���������\n� ������ ������ � ����� ��������� � �������� � ����� ��������� �� �����, ������� �������� ��� ����� ��� ������. ����� ��� ������ ������ �������? ������?";
			link.l1 = "�� ����-������ ��� ��������� ��� ���?";
			link.l1.go = "Jimmy_7";
		break;
		
		case "Jimmy_7":
			dialog.text = "���� ���. ������, ����� ���� �� ������, � �� ��... �� ���� ������!";
			link.l1 = "���, ����. ��� ������� ����, ������� ����� ���������� ����� ����� ������� ����������. ��������� ����� ������� ���� ���� ��������, ������...";
			link.l1.go = "Jimmy_8_1";
			link.l2 = "� ��� ����! � ���� ���, ��� ������! � ������ ��� ����. ������, ������.";
			link.l2.go = "Jimmy_8_2";
		break;
		
		case "Jimmy_8_1":
			dialog.text = "���... ��� �� ������?!";
			link.l1 = "������ �� ��� ������ �� ����������...";
			link.l1.go = "Jimmy_fight";
			pchar.questTemp.Saga.Jimmysecret = "true";
		break;
		
		case "Jimmy_8_2":
			DialogExit();
			pchar.questTemp.Saga = "jackman";
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Saga", "4_1");
		break;
// <-- ������ 
		
//-------------------------------------------������ ��������, �������-----------------------------------------
		//�������
		case "Donovan_abordage":
			PlaySound("VOICE\Russian\saga\Artur Donovan.wav");
			dialog.text = "����, ������� ��������!";
			link.l1 = "��� ��� ��� �� ��� ��������, ������! ��� �����?";
			link.l1.go = "Donovan_abordage_1";
		break;
		
		case "Donovan_abordage_1":
			dialog.text = "����� ��� �����? � ���� ��� �� ������� ��������, ������������ �� ������. ��� ���������� ������� �����!";
			link.l1 = "�� ����, �������. �� ��������� ���������, � ��� � ������. ��� �������? ��� �����, � ���� ���������?";
			link.l1.go = "Donovan_abordage_2";
		break;
		
		case "Donovan_abordage_2":
			dialog.text = "�����? �� ���� ����� ��� �������� ����, ������� �������!";
			link.l1 = "���? � ��� � ��� �� ������, ������ ��� ���� �� ��� ����� ������ ����� ������ ����... �, ��� � ����, ���������� �������� �� ����� ������. ������, �����!";
			link.l1.go = "Donovan_abordage_3";
		break;
		
		case "Donovan_abordage_3":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Saga_AfterDonovanBoarding");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.Saga.Takehelen = "true";//�������, ��� ������������ �����
		break;
		
		//��� ������
		case "Tempsailor":
			dialog.text = "�������, �� �������� ����� � ����, ��� �� � ��������. � ����� ����� �������, ���������� � �������...";
			link.l1 = "��� ��������! � ��� � �����... ������� ����������?";
			link.l1.go = "Tempsailor_1";
		break;
		
		case "Tempsailor_1":
			dialog.text = "�������, �������. ��� ��� �� ����� �������, � ������������.";
			link.l1 = "�������! �������� �� �� ��� � �����, � ���� ���������� ������������ � ���.";
			link.l1.go = "Tempsailor_2";
		break;
		
		case "Tempsailor_2":
			dialog.text = "����, �������!";
			link.l1 = "...";
			link.l1.go = "Tempsailor_3";
		break;
		
		case "Tempsailor_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 10.0);
		break;
		//<-- ������� ������� ��������
		
//----------------------------------------����� ������ ���������, ���������----------------------------------
		//��������� �������� �1, ���
		case "GonsalesA":
			dialog.text = "��� ��� ������, �e����?";
			link.l1 = "�� ����������, ���������! ������ ���� �� �������� ������.";
			link.l1.go = "GonsalesA_1_1";
			link.l2 = "���� ����� "+GetFullName(pchar)+". � ���������� ���� �e����� �������� ������ �� ������� �� ������� �����. ��� �������, ��� ��� ��...";
			link.l2.go = "GonsalesA_2_1";
		break;
		
		case "GonsalesA_1_1":
			dialog.text = "������ �����! � �� ���� �������� ������!";
			link.l1 = "����� ����������, �����. �������� ���, ����� ���� ���� ������ ��������, � � �� ������ ���� ������.";
			link.l1.go = "GonsalesA_1_2";
		break;
		
		case "GonsalesA_1_2":
			dialog.text = "������! ������! �������!";
			link.l1 = "����, ��������! �� ���� ����� �������� ���������. ��, ��� �� ���?!";
			link.l1.go = "GonsalesA_1_fight";
		break;
		
		case "GonsalesA_1_fight":
			DialogExit();
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_MoveCharacter(NPChar, "EnemyFight");
			LAi_group_Attack(NPChar, Pchar);
			LAi_group_SetCheck("EnemyFight", "Saga_KillGonsalesA");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.Saga.Trap = "true";
		break;
		
		case "GonsalesA_2_1":
			dialog.text = "��... ��������, ��, ��������, ��������. � ������������ � ����� ����� � ���� ���� �� �����. � ���� ������� ������ �������. ������� ���� ������ ��� �� ��������. �� ���� �� ��� ���� ���� ��������. �� ������ ������� ��� ��� ������� � �����, �� � ����� �������� ������ ���������� ��� �����. ��� �������� ���� ��� ������� ���������, � ���� ��� ������� �� ��� �� ���� �� ����������, ��� ��� ����� ����� � ���� �� ����, �...";
			link.l1 = "��������. ������, � ������������� ������. ����� ��������.";
			link.l1.go = "GonsalesA_2_2";
		break;
		
		case "GonsalesA_2_2":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			chrDisableReloadToLocation = false;//������� �������
			AddQuestRecord("Saga", "17");
		break;
		
		// ��������� �������� �2, �����
		case "GonsalesB":
			PlaySound("VOICE\Russian\citizen\Pirati v Gorode-08.wav");
			dialog.text = "� �����, ���� ����� ��� �����������. ������, ������? ������ ��������, � �� ����� �����, � � ������� ������ ���� �� ������.";
			link.l1 = "�� ��� ��� �� ��� ������? ���� ������ �������� ���� ������ ������ ������.";
			link.l1.go = "GonsalesB_1_1";
			if (sti(pchar.money) >= 1000)
			{
				link.l2 = "�� ��. ����� � ���� �������. ������� ������ �� ����?";
				link.l2.go = "GonsalesB_2_1";
			}
		break;
		
		case "GonsalesB_1_1":
			dialog.text = "����� �� �� ������� ��� ���� ����� ����! ";
			link.l1 = "��� �� ������ ��������?";
			link.l1.go = "GonsalesB_1_2";
		break;
		
		case "GonsalesB_1_2":
			dialog.text = "�� ����� �� �� ����� ��������� � �������! ���� � �������, ���� � ��������. �� ������� ������ �������� �������� � ������ �����, ��� � ��� ���� ����� � ����� �������!";
			link.l1 = "��? �� �����, ���������, ��� �� ��� ��������, ����� ����!";
			link.l1.go = "GonsalesB_1_fight";
		break;
		
		case "GonsalesB_1_fight":
			chrDisableReloadToLocation = true;
			DialogExit();
			LAi_group_MoveCharacter(NPChar, "EnemyFight");
			LAi_group_Attack(NPChar, Pchar);
			LAi_group_SetCheck("EnemyFight", "Saga_KillGonsalesB");
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.Saga.Trap = "true";
		break;
		
		case "GonsalesB_2_1":
			dialog.text = "����� ����� �������� ��������! ������ ���� - � �� ����.";
			link.l1 = "��������!";
			link.l1.go = "GonsalesB_2_2";
		break;
		
		case "GonsalesB_2_2":
			AddMoneyToCharacter(pchar, -1000);
			GiveItem2Character(pchar, "blade_10");
			RemoveCharacterEquip(npchar, BLADE_ITEM_TYPE);
			dialog.text = "����� ����������� �� ���� ��������� ����� ��� � � ���� � ������� ��������� �� �����. �� ��� ���� ������ �� �� ��� �� �������. ���� �� � ������ �� ���� �������, �� � ������� ������ �� ���� �����. ���� ������ ��� ���� ������� ���������\n����� ����, ��� ��������� �������. ������� �� ������ ����� � ������� ������ - �� ����� ����� �������� ����� �� ����.";
			link.l1 = "� ��, � ������, ���� ������� ������� �����. �� ��� ���� �� ��� ������� ��� ��� ���������? �������, ��� ��������� � ��������� �����, ��������� ��� �� ���� ������ � ���� � �����.";
			link.l1.go = "GonsalesB_2_3";
		break;
		
		case "GonsalesB_2_3":
			dialog.text = "�������? �� ���� ������. ���� ����� ������ ��������. �� ���� � ������ �������� �������� ��� ���� ������� ����, �� � �������� ������ ��� ���� �����. ���� ���� ��������� ������, ������ � ����� �� ���. �� ���, �������?";
			link.l1 = "�� �������. ������� ������, � ������� �����. �� ������ ��� �������, ��� ��� �����, ������.";
			link.l1.go = "GonsalesB_2_4";
		break;
		
		case "GonsalesB_2_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			npchar.lifeday = 0;
			AddQuestRecord("Saga", "19");
			pchar.questTemp.Saga = "ortega";
			Saga_SetOrtega();
		break;
		
		//��������� �������� - ������, ����
		case "Ortega":
			dialog.text = "� �� ��� ������ �������, ���, �������, � � ����� ������ ����. ��� ���� �����?";
			link.l1 = "�� ����������, ���������. ���� ������ � ���� ������ ������. ������, ��� � ����� ����� ���� ������ ��������. ��� ���� ���� ���� �� ���� �������. �� ���� �������, �����, ������ ������� �����, ������ �� �����. �� �������� ������������ ����.";
			link.l1.go = "Ortega_1";
		break;
		
		case "Ortega_1":
			dialog.text = "��� ��� ��� ���... ����� ����, ������� �� ��� ��� ��� � �� ����� ������� �����. ������� ����� ������ � ��� ���, ����� � ������� ������ ��� ������� � ������������ �����... ��� ������ ��������� �����, � ��� ��� ������ ������� ��������\n�������� ������� ����� ������� �� ���� ������� �������� �� �����, � ������� � ����. �� ���� ������� ����� �������� �� �������, �� � ����� �� ���� �� �������. �������� � ��� ������� �� �� ����� ����. �� ��� ��� ������ �������\n������ � �� �����, � ����� ����. � ������� ������� ������ �� ���� �����. ��� ����� ����� �� ���� � ���� � ������ ������� � ������ ���������������.";
			link.l1 = "���� �� ��� ������, �� ��� �������� �������� ��� �����. ��� ��� ���� ���� ���������� ������. � ���� ������� ��������, ������ �������� ���� ���� ���. �����, ��� ������� � ��� ���������, � ���������� � ��� ������ ���� ���� �� ���.";
			link.l1.go = "Ortega_2";
		break;
		
		case "Ortega_2":
			dialog.text = "�����, ��� ������� �����, ���� �������� ���� ���. ������ ����� ����-������ ��� �� ���������� ����� ����������� � ���������, ������� ������������ � ���� �����. �������, ���� ������� �������� � �������� � � ���� �� ����, � ��� �� ��� � �� ��������� �� ����������� ��������.";
			link.l1 = "����� �� ����������� ��������?";
			link.l1.go = "Ortega_3";
		break;
		
		case "Ortega_3":
			dialog.text = "� ������ ��� �������� ������ ����� ����� �� ���������� ������ ������. � ��� �� ��� ��������? ��, � �������� ��������� �� ������ '�������' �������� ����. �� �� ���� �� ��� ��������� ������� � ������ ����, ����� � ����������� � ������� � �� ���������.";
			link.l1 = "��������� ����� ������ �������?";
			link.l1.go = "Ortega_4";
		break;
		
		case "Ortega_4":
			dialog.text = "�� ������������ ���������. ���� ������� ���� ����, ������, ��� ����� ���� ������, � �� ��� ������ ������. � �� ��������� ������, ��� ������ ���������� �� ���� ������� �� ����� ������ ����� �� ������ � �� ������������. ���� ������� �� ����, � ����� ���� � ���� ������.";
			link.l1 = "��� �� ������ ��� ������� ������?";
			link.l1.go = "Ortega_5";
		break;
		
		case "Ortega_5":
			dialog.text = "������. � ������ ��� �������� �� �������� ������. �� ���� ��� �������� �� ����, ��� ����� �� ��������. � ��� � ������ ��� �������� �� ������ � �������� ��������� �� ���������� ������. ����� ������� ���� �������� � ������ �������, ��� �������� ��� �����.��-�� ����� � ���������� �� ������� �� ����� �����\n� ����� ������� �������� �� ������ ������ � ���� �������, � ����� ����� � ������ ����� ������ ��������. ��� ������ ������� ���� ��� � ������� ����-�� ������ � ����� �������, ��������� ������� ����� � �����. �������, ��� ������������ � ���, � �� ������� ������� ��� � ������� �� ������.";
			link.l1 = "���� ������ ����� �����?";
			link.l1.go = "Ortega_6";
		break;
		
		case "Ortega_6":
			dialog.text = "������ ���. � ����� ������ ������. ���� �� �� ������� ����� ��������� � ������� � �������� �������, ��� � ����� �������� �����, � ���� ������ ���� �������� � ������. � �� ������ ���. � ������ �������, �� �� ������.  ����� ��� �������, ���� ������� ������. � ������ � ������� ��...";
			link.l1 = "��� � �����, �����?!";
			link.l1.go = "Ortega_7";
		break;
		
		case "Ortega_7":
			dialog.text = "��... ��... �����... ��!";
			link.l1 = "���!";
			link.l1.go = "Ortega_8";
		break;
		
		case "Ortega_8":
			DialogExit();
			LAi_SetImmortal(npchar, false);
			LAi_KillCharacter(npchar);
			AddQuestRecord("Saga", "20");
			pchar.questTemp.Saga = "svenson1";
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "bucher_ring"); //�������� ������
			//������ �� ������� ����������
			SetFunctionTimerCondition("Saga_LightmanReturn", 0, 0, 10, false);
			//������ ����������, ���� �� �������� � ������
			if (CheckAttribute(pchar, "questTemp.Saga.Trap"))
			{
				pchar.quest.Saga_Trap.win_condition.l1 = "location";
				pchar.quest.Saga_Trap.win_condition.l1.location = "Mayak11";
				pchar.quest.Saga_Trap.function = "Saga_CreateTrapBandos";
				CoolTraderHunterOnMap();
			}
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
		break;
		
		//������� � ������� ���������, ����
		case "saga_trap":
			dialog.text = "�-�, ��� � ��� ���������� ������! ����� ���� ��������� �� ���������? �������, ��� ����� ��� �� ����... ����� �� ��� �� �����. ������, ����� ����� ������!";
			link.l1 = "��, ���������, ������ �������!";
			link.l1.go = "saga_trap_1";
		break;
		
		case "saga_trap_1":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			int n = makeint(MOD_SKILL_ENEMY_RATE/3);
			for (i=1; i<=3+n; i++)
			{	
				sld = characterFromId("sagatrap_sold_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		//<-- ����� ���������, ���������
		
//--------------------------------------------��� �� ������ ����������� ������---------------------------------
		
		// ������������� �����
		case "DominicaHead":
			dialog.text = "����! ����! ������� ��������� ��������� ����� ������! �-��! ��� �������� ����� �������� ������ ��� �������, ���� ���� ����������� ������� ���������! �-��! ��� ���������� ����� ����� ������� ����!";
			link.l1 = "(�����) ���� ������, ���� � �����?";
			link.l1.go = "DominicaHead_1";
			NextDiag.TempNode = "DominicaHead";
		break;
		
		case "DominicaHead_1":
			dialog.text = "�-��! ������� ���� ������ ���� ������ ������� ���������! ������ ����������� ����, ���� ������! ������� ��������� ����� �������! �� ������� ���� � ����, � ������� ����, � �� ���������� ���� ���� �� ������ �������!";
			link.l1 = "(�����) �� � �����... ����� ���������? ��, �����, � ������ � �����! � ������...";
			link.l1.go = "DominicaHead_2";
		break;
		
		case "DominicaHead_2":
			dialog.text = "�-��! ������� ���� ������� ���, ��� ������ ���� ����������� � ������ ��������� �������. �, ������� ����! �� ����������� � ��������� ������ � �����, ����� ��� ��� ������� ���! �����! ��� ������� �������� ����� - �������� ��� ������ � ���������!";
			link.l1 = "(�����) ��� ������... �����, �������� ���� � ����. ������, ���� �� ������ ���� ������ - � ���� ��������� � �� �� ��� �� �������...";
			link.l1.go = "DominicaHead_3";
		break;
		
		case "DominicaHead_3":
			DialogExit();
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload1_back", "Saga_DominicaDollyReload", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
			for (i=2; i<=10; i++)
			{
				sld = characterFromId("Dominica_ind_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, npchar, "", -1);
			}
		break;
		
		case "DominicaHead_4":
			dialog.text = "�� ������ � ���������, ������� ��� ������. ����� ������ ���� ����, ���� �����, � ��������� ������� � ���. ���, ������� ����...";
			link.l1 = "(�����) ��� � ����� �������, ��������� ������������...";
			link.l1.go = "DominicaHead_5";
		break;
		
		case "DominicaHead_5":
			DialogExit();
			bDisableCharacterMenu = true;//����� �2
			npchar.quest.LSC_hello = "true";
			AddQuestRecord("BaronReturn", "7");
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Saga_DominicaDollyWait", 5.0);
			pchar.questTemp.Saga.BaronReturn = "third_teleport";
		break;
		
		case "DominicaHead_6":
			dialog.text = "��������� �����! ��������� � ����! ������� ���� ����� ���� �������� ������ ���������! �����, �������� ������ ����� ������� ��� ������!";
			link.l1 = "(�����) �� �����, �����. � ��� ������� ���� � ������ ����������. �� � ������ ���...";
			link.l1.go = "DominicaHead_7";
		break;
		
		case "DominicaHead_7":
			DialogExit();
			bDisableCharacterMenu = false;//�������� �2
			AddQuestRecord("BaronReturn", "8");
			for (i=2; i<=10; i++)
			{
				sld = characterFromId("Dominica_ind_"+i);
				LAi_SetActorType(sld);
			}
		break;
		
//----------------------------------------��� �� ������ ��������� ���������----------------------------------
		// ������� ����������� �������, ��������� ����, ����
		case "BarbCapBarkas":
			dialog.text = "��� ������ ������ ������, ������?";
			link.l1 = "���-���... ��, �����������, �������, ��� ��� �� ��� �������?";
			link.l1.go = "BarbCapBarkas_1";
		break;
		
		case "BarbCapBarkas_1":
			dialog.text = "��� �����? � �����, � ��������� ������ ����. � ������ ����� �� ��� ��� ����������� ������, �� ��� � ����� ����?";
			link.l1 = "�� ��� ���, ��������. �����, �� � �����, �� ������ ������ �� ����� ������ �� ����. �����, �� ���� �����, �� ������ ������� ��� �������� ������ �������� ����. � ���� ����������� ��� ������� ��� ������ ��������������.";
			link.l1.go = "BarbCapBarkas_2";
		break;
		
		case "BarbCapBarkas_2":
			dialog.text = "��� �� �����? ����� ��� ����?";
			link.l1 = "����� ����? ������� �� ����� ��������... �� ����� �� ���� ������! ������, ���: ��� �� ���������� �������� �� ����� ����� �������� ����������� ���� � ��������� ��� ���, ��� � ��� ��� ������. ������ ����� ���� ���� � ����� �������� ��� ���������� ���� ������ ������������ � ������. ��? ��� ����� ����� �����?";
			link.l1.go = "BarbCapBarkas_3";
		break;
		
		case "BarbCapBarkas_3":
			dialog.text = "���! ������, ������ �� � ��� �����... ������� ���� � ������� ����, ��� � � �����...";
			link.l1 = "���� �������� ���� �� ��� �������!";
			link.l1.go = "BarbCapBarkas_4";
		break;
		
		case "BarbCapBarkas_4":
			dialog.text = "��, ��, �������. ������ �� ��� �������, ������ �� �������� ��� �����!";
			link.l1 = "����� �������������! � ���� ���� �������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Saga_BarbBarkasSilk");
		break;
		
		case "BarbCapBarkas_5":
			dialog.text = "���, �� ��������� ���, ��� �������� � ����, ��� ������ �����. ������ �� ����, � �������...";
			link.l1 = "�����. ������ ���� ������ � ������ �� ������ �� �����!";
			link.l1.go = "BarbCapBarkas_6";
		break;
		
		case "BarbCapBarkas_6":
			DialogExit();
			npchar.DontDeskTalk = true;
			npchar.lifeday = 0;
			LAi_SetStayType(npchar);
			pchar.quest.BarbBarkas_Sink.over = "yes"; //����� ����������
			pchar.quest.BarbBarkas_Abordage.over = "yes"; //����� ����������
			NextDiag.CurrentNode = "BarbCapBarkas_7";
			AddQuestRecord("BarbTemptation", "6");
			pchar.questTemp.Saga.BarbTemptation = "give_silk";
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
		break;
		
		case "BarbCapBarkas_7":
			dialog.text = "�� ��� ��������, ��� ������. � ���� ������ ������ ���! ��� ��� ��� �� ���� ����?";
			link.l1 = "�� ���������, ��������. � ��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "BarbCapBarkas_7";
		break;
		
		// �������, ������� ������������ �����, ������
		case "Morelle":
			dialog.text = "���� �� �� ���������, �� ������� ���, ��� �� ����� ���� � �� ������ �� �����. � ����� ������� ����. ���� ����������� ������ �� ��� ����� ��� ����.";
			link.l1 = "�� ����� ������ ������ �������. ��� �� ���� ������ �������� ������� ���� ����������. �� ������ ���� ����������� ���� ����, ������� �� ����� ������� �� ����. ������� ��� ���� �� ����� ����� ����������?";
			link.l1.go = "Morelle_1";
		break;
		
		case "Morelle_1":
			dialog.text = "� ��� �� ���� �������, ��� �������. ������� ������� ��� ���������� ������ ����� �����. � �������� ��������� ���. �� ������ ��� � ��� �������� ����������. � ��� ������� ������� ��� ��� ����, ������� � ������ ��� ���� � ���������� � �������� �����. ��������, ��� ������� ��������\n��� ������ ���������, � � ���� '�������� ���' ���� ����������� �������, ���� �� �������� ��� ��� � �� �������. �� ������ ��������� ��� ����, � ������ ������� ������ ���� ����. ������ ��������� �� ����� ����� ����, ����� ������ � ������. ���-�� �� ������ ���� �� �����������.";
			link.l1 = "������. � �� ����� ���������, ��� �� ��� ���. ���� ��, ��� � ��� ������� ������, �� ���� � ������ ����� ���� ���������� �����������. � ����� ��� � �������� �����������.";
			link.l1.go = "Morelle_2";
		break;
		
		case "Morelle_2":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			// ������ - ������
			//int m = Findlocation("Shore40");
			//locations[m].models.always.Roll = "Roll_of_rolls";
			//Locations[m].models.always.Roll.locator.group = "quest";
			//Locations[m].models.always.Roll.locator.name = "quest1";
			pchar.quest.Saga_MorelGoods.win_condition.l1 = "locator";
			pchar.quest.Saga_MorelGoods.win_condition.l1.location = "Shore40";
			pchar.quest.Saga_MorelGoods.win_condition.l1.locator_group = "quest";
			pchar.quest.Saga_MorelGoods.win_condition.l1.locator = "quest1";
			pchar.quest.Saga_MorelGoods.function = "Saga_SetMorelGoods";
			AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 200);//����������
		break;
		
		// �����, ���� �������� � �����������
		case "valet":
			dialog.text = "� ��� ��������, ������� �����, ����� �������� ����� �� ����� �����.";
			link.l1 = "����� ��� ��������.";
			link.l1.go = "valet_1";
		break;
		
		case "valet_1":
			dialog.text = "�������-��! ������ ������ ���� �����������: ���� ����� ����������� � ����� � ������� ������� � �� ���� � �������� ���, ��� ���������� '����������' ���� ��������� � ������� ����� � �������� � ����� �����. �� ������� ������ �����, � �������  ���� ������. ��� �� ����� �� ���� ��������, �������� � ���� ������� � '����������'. ������ ����. ������ �� ������ �� ������. ��������?";
			link.l1 = "� ����� ��� ������ ������� ����� ������ �? ������ ����� ������� �������...";
			link.l1.go = "valet_2";
		break;
		
		case "valet_2":
			dialog.text = "���� ������ �� ��, ����� �� �������, � �� ������� �������. �������, �� ����. ��� ��� �� ���. ������ ���� ������������, ��� ������ ���� �� ���� ��������, ���� �� ��������, ��� �� �������� ������. ��, � ����� ��������, ����������� ���� �� ��������. ���� ������...";
			link.l1 = "���-�� �� �������, ������... � ������ �� ���� ������ �� ��������������� ��� ��������������?";
			link.l1.go = "valet_3";
		break;
		
		case "valet_3":
			dialog.text = "�������! ��� �� �� �� ���, �� ���� ����������� ��� �� ��������! ���� �������� ������� ������ ���� � ������.";
			link.l1 = "��, ��������� � ����� ������ ��������. ��������, ����� ����, ��� ���� ���������� ����������. ���, ������, ������ �� ����� �� ���� ��������. ��� ���� ������, ���� �� ���� ������? �������, ��� � ������ �� ���� ��� ��������!";
			link.l1.go = "valet_4";
		break;
		
		case "valet_4":
			dialog.text = "�� ��... ��������! ��, ��������� ��� ��������, � ���� ������� ���� ��������, ������!";
			link.l1 = "��! ������ ������� � � �� ������. �������, ��������!";
			link.l1.go = "valet_5";
		break;
		
		case "valet_5":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Saga_ValetDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "vensan":
			// Addon 2016-1 Jason ��������� ������� ���� 17/1
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")
			{
				dialog.text = "����� "+pchar.name+"? ��� �� ����� �������? �-����, ��� ������ ������, � �����! ��� �� ��� ������!";
				link.l1 = "������, �����. � �� ����� �������. ������ �� ������ ����������, ��� ��� ������ ����� � ���� ������ �� ��������, ����, �������, �� ����������� ������ �� ������.";
				link.l1.go = "vensan_8";
			}
			else
			{
				dialog.text = "���� ������, �� ���? ��� �� ���� ������? ������� ������� - ��� ������� �����������, � �������, �������� �� ������, ����� �������� ��� ����� ���������.";
				link.l1 = "�� ������������, ������. ������ �� ������ ����������. ������ ����� ������ �� ��������, ����, �������, �� ����������� ������ �� ������. ���� ���?";
				link.l1.go = "vensan_1";
			}
		break;
		
		case "vensan_1":
			dialog.text = "������. ������ ������. � ��?";
			link.l1 = "������� "+GetFullName(pchar)+". ������ � ������� ������� � �������� ���...";
			link.l1.go = "vensan_2";
		break;
		
		case "vensan_2":
			LAi_SetStayType(npchar);
			dialog.text = "��... �������. ��� ��� ������������� ���?";
			link.l1 = "��� �� ��� �����������, ������. � ��� ��� �������� ����� ���� �� �������?";
			link.l1.go = "vensan_3";
		break;
		
		case "vensan_3":
			dialog.text = "��� ������� �������� ������� � �����...";
			link.l1 = "���������� �� � ���������� ���������� ������.";
			link.l1.go = "vensan_4";
		break;
		
		case "vensan_4":
			dialog.text = "��...";
			link.l1 = "�� ������� �������, ������. ������������� ��������� �����, � �� ����, �... �������.";
			link.l1.go = "vensan_5";
		break;
		
		case "vensan_5":
			dialog.text = "��� �� ����� �� ��������? �� �����?";
			link.l1 = "��, �� ��������. ��� ������� �������� ��������� ��������, � ������� ������� ���� �������� ����������� ���������� �������. ��, � ������� ������� ������ �� �������������, ���� � �� ������ ��� ����� - ����� �������������� �� ����� �������� ��������.";
			link.l1.go = "vensan_6";
		break;
		
		case "vensan_6":
			dialog.text = "����������� �������! �� ��� �������?";
			link.l1 = "��. � �� ����������������.";
			link.l1.go = "vensan_7";
		break;
		
		case "vensan_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "goto", "goto2", "none", "", "", "", 5.0);
			Ship_SetTaskRunaway(SECONDARY_TASK, GetCharacterIndex("Cap_Vensan"), GetMainCharacterIndex());
			pchar.questTemp.Saga.BarbTemptation.Vensan_free = "true";
			if (!CheckAttribute(pchar, "questTemp.Saga.BarbTemptation.vensan_attack"))
			{
				if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer") && GetCharacterIndex("Mary") != -1) sld = characterFromId("Mary");
				else sld = characterFromId("Helena");
				sld.dialog.currentnode = "sea_bomb"; 
				LAi_SetActorType(sld);
				ChangeCharacterAddressGroup(sld, pchar.location, "goto", "goto6");
				LAi_ActorDialog(sld, pchar, "", -1, 0);
			}
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
			sld = characterFromId("Cap_Vensan");
			sld.lifeday = 1;
			sld.DontDeskTalk = true;
		break;
		
		// Addon 2016-1 Jason ��������� ������� ���� 17/1
		case "vensan_8":
			dialog.text = "��� ������? ������, ����, ������ �...";
			link.l1 = "���, ������. ������ � ������� ������� � �������� ����.";
			link.l1.go = "vensan_9";
		break;
		
		case "vensan_9":
			LAi_SetStayType(npchar);
			dialog.text = "��... ���� �������...";
			link.l1 = "�����, � ���� ��� �������� ����� ���� �� �������?";
			link.l1.go = "vensan_10";
		break;
		
		case "vensan_10":
			dialog.text = "��� ������� �������� ������� � �����...";
			link.l1 = "�������� �� � ���������� �������� ������.";
			link.l1.go = "vensan_11";
		break;
		
		case "vensan_11":
			dialog.text = "��...";
			link.l1 = "�� ������ ��� ������ ������, ���� ����������. ���� �������� ������, ���� � �� ���� � �������� ��� ���� �������.";
			link.l1.go = "vensan_12";
		break;
		
		case "vensan_12":
			dialog.text = "���� ������ ������?";
			link.l1 = "���. ������ ��� ������� �������� ��������� ������ ��������, � ������� ������� ��� ����������� ���������� �������. ��, � ������� ������� ������ �� �������������, ���� � ��� �� ������ ��� - ����� �������������� �� ����� �������� ������... ����� - ����� �����, ��� ������. � ��� ������� ���, ����� �� �������� �� ���� ������. ���, �����, �� ����� �������!";
			link.l1.go = "vensan_7";
		break;		
 //--------------------------------------��� �� ��������� �����--------------------------------------------------
		// �������, ���� ��������
		case "molligan":
			dialog.text = "��� ��� ����� �� ���� �����, ������?";
			link.l1 = "����������, ����. ���� ��� �� - ���� ��������?";
			link.l1.go = "molligan_0";
		break;
		
		case "molligan_0":
			dialog.text = "��, ��� �. ��� ������?";
			link.l1 = "� - "+GetFullName(pchar)+", � ���� ������ �� ����� �� �������.";
			link.l1.go = "molligan_1";
		break;
		
		case "molligan_1":
			dialog.text = "��? �-�, ���������� � ����. �����! �� � ��������� ����� ��������� ���������� � ��� ����. ��� ��� �� ��� ����� �� ����?";
			link.l1 = "�� ����������� ���� �� ���������. �� ����� ��������� ���� ��� ������ �������� �������� ������, ����� �� ������� ��� ����� �������� � ����������. ������ ����� ��� �������� - ��� ���� ��������� ���� � ����� ��������� � ����� �����.";
			link.l1.go = "molligan_2";
		break;
		
		case "molligan_2":
			dialog.text = "������� ������? ��� �� ��� ������? ��. � ������ �� ��� �� ������ ������� ��� �� ��������? ����� ��� ����� ����������� �?";
			link.l1 = "������ ��� �� ����� � ���������, � � - ���. � ���� ������� ������� �� ��������, � ��� ������� �������������. � ���� �� �� �� �������� ��� ����������� � ������ �������� � �������� ��� �� ����, �� �� ��������. ����� ���������, ��� ��� ����.";
			link.l1.go = "molligan_3";
		break;
		
		case "molligan_3":
			dialog.text = "��������, �� � ���� ��� ����� � ������. � �� ����� ��������� ������� ���, ��� �� ��� ���� �� ��������...";
			link.l1 = "��� �����? �������... � ��� �� ������, ��� � ���� ����� ��������� �� �������.";
			link.l1.go = "molligan_4";
		break;
		
		case "molligan_4":
			dialog.text = "��� ���, �� �� �� ����, ��� � �������� �� '�������' �����, ����� ������� ������. � �� ���� ��������� ����� ������, ��� � ���� ��� ����. ������ ��������� �� �������� ���, �, �������? ������� ���, ��� � �� ����. � � �������� ����� ������������� �� ����: ������, ���� ����, ������� �������� � ����. ������ ��������.";
			link.l1 = "��. ��� ������ �� ������� � ��� �����... �����, ��������� � �����, ������? ��� �������������� ������ ������ �������� - ��� ������ �����, ��� ��� � ����� ���������...";
			link.l1.go = "molligan_5";
		break;
		
		case "molligan_5":
			dialog.text = "��������, �� � ������������� �� ���� ����� ������ ����. ��� �� ������, ����� � �������� ��� ����� �� ���� ������ � ������� '�������' �����������?";
			link.l1 = "�����. ��, ��� �� ��� �����������... �� ��� ��� �� ����������, ����!";
			link.l1.go = "molligan_6";
		break;
		
		case "molligan_6":
			dialog.text = "� ������� ��������, �� ���������. � ����� ������, ������ ������ ��� ��� ��������, �� ����������������� �������, ����� �� � ���� �����.";
			link.l1 = "��, ���� ������ ��� ������ �� ���������, ���� ��� � ����� �����������... ����, ��������.";
			link.l1.go = "molligan_7";
		break;
		
		case "molligan_7":
			DialogExit();
			// ������ �������� ����������
			if (GetSummonSkillFromName(pchar, SKILL_SNEAK) > (10+drand(50)))
			{
				pchar.questTemp.Saga.Molligan.friend = "true"; // ����� ���� ������������ ����� ��������
				sTemp = "�������, ������, ������ �� ����������. ������� � ���� ������� � ������ ���� ��������: ����������� ��������� - ����� ������ � ����� �������. ";
				log_Testinfo("������");
				AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
				AddCharacterExpToSkill(pchar, "Sneak", 300);//����������
			}
			else
			{
				pchar.questTemp.Saga.Molligan.enemy = "true"; // �������
				sTemp = "";
				log_Testinfo("�����");
				AddCharacterExpToSkill(pchar, "Sneak", 150);//����������
			}
			AddQuestRecord("Testament", "7");
			AddQuestUserData("Saga", "sText", sTemp);
			NextDiag.CurrentNode = "molligan_8";
			npchar.DontDeskTalk = true; // patch-5
		break;
		
		case "molligan_8":
			dialog.text = "�� ��� ��������, �������, ����� ���?";
			link.l1 = "��, ��. � ��� ����������� �� ���� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "molligan_8";
		break;
		
	//-----------------------------------------��� �� ����� ��������--------------------------------------------
		// ���� ������, �������� �����
		case "benson":
			dialog.text = "����� � ��� �����������? � �� ����� ������� � �������� ����. � ��� ����������� ������� � �����������. � ���� �� � ���� ����� ����� ����� �������� �������� ����������.";
			link.l1 = "� ��� ������ ���������� ��������� � ���� �����?";
			link.l1.go = "benson_1";
		break;
		
		case "benson_1":
			dialog.text = "������� ��� ���� ������� ���������, � � ����� �� ������ � ������� � ������� ��� �� ����. �� �� ��, ����� �������, ��� �� ������ ������ � ����� �������������� ��������� ��� �����, ��, ����������, ���������.";
			link.l1 = "��� �� �� ����������, ���� ��������?";
			link.l1.go = "benson_2";
		break;
		
		case "benson_2":
			dialog.text = "� ��� ������� � ���� � ��� ������. �� � ����� ����� ������������ �������� ����������� ������, ������ �� ���� � ��� �������. ����� �� ������������ �������, �� ������ ��������� � ��� �� ������ ������� ������. ����� �� ����� ������������ ��� �������?\n���-��� ���������� ��������� ������. �� ������ �� �������� �� ������ ������. ��� ��� ���� ������  ������ ����� �� ��������, ��� ������� ��� ����, ��� ������� ������ ����� �� ���, ��� ��� �� ������ ����� � ����-�� ��� ����� �������\n��, ����� ����, ������� ��������. ��� ��� ���?! ����� �� ����� �� ��� � �������� �����! �� � � �������� ��� ����� ����� �� �����... �� � �������� ��� �������� ���, ��������. ��� �������, ������� ����� ������. �� �� ���� ��� ����� �����. ����� ����� �������, �� � ���� �� �� ����. ��� ��� �������� ��� ����� ����.";
			link.l1 = "���� ������! ��� ����� ������� ������, ����� ������ �����?";
			link.l1.go = "benson_3";
		break;
		
		case "benson_3":
			dialog.text = "��. ������ ���. � �� ������ ������? �� �� �� �� ������� �� ����?";
			link.l1 = "���, �� �. ��� ������ ����� ����� ���� ������� - ������� ������ ������ ���� � ����� �� �������. ��� �� ��� ��������?";
			link.l1.go = "benson_4";
		break;
		
		case "benson_4":
			dialog.text = "� ������� ��� � ������ 15 ��. 28' �������� ������ � 63 ��. 28' �������� �������. ������������, ������! �� ������ ���� ��� ���, � ���� �� ��� ������� - �� ������� ���� � ���� ����!";
			link.l1 = "��� �������� �����!";
			link.l1.go = "benson_5";
		break;
		
		case "benson_5":
			DialogExit();
			NextDiag.CurrentNode = "benson_6";
			AddQuestRecord("Shadows", "3");
			npchar.lifeday = 0;
			bQuestDisableMapEnter = false;
			pchar.quest.Saga_Shadows_Baker.win_condition.l1 = "location";
			pchar.quest.Saga_Shadows_Baker.win_condition.l1.location = "Dominica";
			pchar.quest.Saga_Shadows_Baker.function = "Saga_SetBakerBoat";
		break;
		
		case "benson_6":
			dialog.text = "�������, ���������! �� ������ ���� ��� ���!";
			link.l1 = "��-��, ����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "benson_6";
		break;
		
	//---------------------------------------������� � �������������� �������-------------------------------
		case "mine_bandit":
			if (CheckAttribute(pchar, "questTemp.Saga.MineAttack"))
			{
				dialog.text = "��! � �� ����, ��� ������! �� ���� ������! ��� ���������� - ��� �������!";
				link.l1 = "�� ���� ����� �����, �������! ����! �� �� ��������. ��� ����� ������ �� ������. ������ �������...";
				link.l1.go = "mine_attack";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "��! � �� ����, ��� ������! �� ���� ������! ��� ���������� - ��� �������!";
				link.l1 = "��. �� � ���� ������... � ����� ����� �� ��� ��� ����������?";
				link.l1.go = "mine_bandit_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� ����� ��?! ����, ��-�������� �� ���� �� �������... ������, ���!!";
				link.l1 = "...";
				link.l1.go = "mine_bandit_fire";
			}
		break;
		
		case "mine_bandit_0":
			dialog.text = "�����, �������, ������ ��� ������!";
			link.l1 = "������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "mine_bandit_0";
		break;
		
		case "mine_bandit_1":
			dialog.text = "� � �����, ��� ������ �� ���� ������ - ������� �������������, � � ����� ���� ��� ����, ����� �� ������� ���� ������ �����������, ����� ����. ����� �������������� � ����� � �����, ����������. ���� ����� �������� �������� - ��� ��������, ��� �� ���� ������ ������ ����� ���������.";
			link.l1 = "���, �������. ��������� � ������ ������� ������. ������, � �����.";
			link.l1.go = "mine_bandit_exit";
			link.l2 = "�� ��, ��������! �� ��� �� ������ ���������, �� ���� ��� ���������!";
			link.l2.go = "mine_bandit_2";
		break;
		
		case "mine_bandit_exit":
			DialogExit();
			LAi_SetGuardianType(npchar);
			LAi_group_MoveCharacter(npchar, "PIRATE_CITIZENS");
			chrDisableReloadToLocation = false;//������� �������
			DoQuestReloadToLocation("Mine_02", "reload", "reload3", "");
		break;
		
		case "mine_bandit_2":
			dialog.text = "��, �� ��� ����������... ������, ���!!";
			link.l1 = "...";
			link.l1.go = "mine_bandit_fire";
		break;
		
		case "mine_bandit_fire":
			DialogExit();
			DoQuestCheckDelay("Saga_MineBanditsFire", 1.5);
		break;
		
		case "mine_banditx":
			if (CheckAttribute(pchar, "questTemp.Saga.MineAttack"))
			{
				dialog.text = "��! � �� ����������� �����! ��� ���������� - ��� �������!";
				link.l1 = "���, �������, ��������! �� �� ��������. ��� ����� ������ �� ������. ������ �������...";
				link.l1.go = "mine_attackx";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "��! � �� ����������� �����! ��� ���������� - ��� �������!";
				link.l1 = "��. � ��� ��� �����?";
				link.l1.go = "mine_banditx_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�-�, ��� ����� ��?! ����, ��-�������� �� ���� �� �������... ������� �� ���������! ���!!";
				link.l1 = "...";
				link.l1.go = "mine_banditx_fire";
			}
		break;
		
		case "mine_banditx_1":
			dialog.text = "�� ���� ����. ��������, ��� �� ������� ���� �� �����, �������!";
			link.l1 = "�����, �� ��������. � ��� �����.";
			link.l1.go = "mine_banditx_exit";
			link.l2 = "�� ��, ��������! �� ��� �� ������ ���������, ��� ���� �������!";
			link.l2.go = "mine_banditx_2";
		break;
		
		case "mine_banditx_exit":
			DialogExit();
			LAi_SetGuardianType(npchar);
			LAi_group_MoveCharacter(npchar, "PIRATE_CITIZENS");
			DoQuestReloadToLocation("Mine_04", "reload", "reload3", "");
		break;
		
		case "mine_banditx_2":
			dialog.text = "��, �� ��� ����������... ������� �� ���������! ���!!";
			link.l1 = "...";
			link.l1.go = "mine_banditx_fire";
		break;
		
		case "mine_banditx_fire":
			DialogExit();
			DoQuestCheckDelay("Saga_MineBanditsxFire", 0.6);
		break;
		
		case "mine_attackx":
			dialog.text = "��� ���? �� ����� ���� ������ ���� �������� ������ ��� �����. ������ ���, � ���� �� ������ - ���� �������� �� ���� �� �������...";
			link.l1.edit = 5;
			link.l1 = "";
			link.l1.go = "mine_attackx_1";
		break;
		
		case "mine_attackx_1":
			sTemp = GetStrSmallRegister(dialogEditStrings[5]);
			if (sTemp == "������")
			{
				dialog.text = "��� �����. �� ��, ��������, ������ �� � ��� �������. ����� ���� �� ������������? ����� ����� �� �����, ����� �������� ���� ������ �������, �������� �����, �� �������� ������ ����� - ��� ���� �������� � ������������ �����.";
				link.l1 = "� ����� ������ ����� ������?";
				link.l1.go = "mine_attackx_2";
			}
			else
			{
				dialog.text = "������, � ��� ��� ����! ������� �� ���������! ���!!";
				link.l1 = "...";
				link.l1.go = "mine_banditx_fire";
			}
		break;
		
		case "mine_attackx_2":
			dialog.text = "���. ������ ����� ����������� ����.";
			link.l1 = "������, �������... ��! ������! ��� ��� �� ����� ������� ���������?";
			link.l1.go = "mine_attackx_3";
		break;
		
		case "mine_attackx_3":
			DialogExit();
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("Mine_banditx_"+i);
				LAi_RemoveCheckMinHP(sld);
			}
			sld = characterFromId("Svensons_sold_12");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "soldiers", "soldier1");
			LAi_ActorAnimation(sld, "shot", "Saga_MineBanditxDie", 1.0);
		break;
		
		case "mine_attack":
			dialog.text = "�� �������? �� ����� ���� ������ ���� �������� ������. ������ ���, � ������ �����, ����� � ������ ���������. ��, � ���� �� ������ ��������� �������� - �� ��� ���� ��������� ��������� ����� � ����� �����.";
			link.l1.edit = 5;
			link.l1 = "";
			link.l1.go = "mine_attack_1";
		break;
		
		case "mine_attack_1":
			sTemp = GetStrSmallRegister(dialogEditStrings[5]);
			if (sTemp == "������")
			{
				dialog.text = "�����. ������ ���������. ������� �� ������ ��������� � ���� ����� �� ����� � �����. ������� ����� � ����.";
				link.l1 = "������, ��������...";
				link.l1.go = "mine_attack_2";
			}
			else
			{
				dialog.text = "������, � ��� ��� ����! ������, ���!!";
				link.l1 = "...";
				link.l1.go = "mine_bandit_fire";
			}
		break;
		
		case "mine_attack_2":
			DialogExit();
			NextDiag.CurrentNode = "mine_attack_3";
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, npchar, "ActorDialog_Any2Pchar", -1);
			LAi_ActorTurnToCharacter(npchar, pchar);
			SetActorDialogAny2Pchar(npchar.id, "", 0.0, 0.0);
		break;
		
		case "mine_attack_3":
			dialog.text = "���� ���� ���? ����� ���-��?";
			link.l1 = "��. ���� ������� �������� ���� ������.";
			link.l1.go = "mine_attack_4";
		break;
		
		case "mine_attack_4":
			dialog.text = "���? ��-��! � �� ���� ��?";
			link.l1 = "�� ��� ��������, �����!";
			link.l1.go = "mine_attack_5";
		break;
		
		case "mine_attack_5":
			DialogExit();
			LAi_SetPlayerType(pchar);
			for (i=1; i<=6; i++)
			{
				sld = characterFromId("Mine_bandit_"+i);
				LAi_RemoveCheckMinHP(sld);
			}
			if (pchar.questTemp.Saga.MineAttack == "soldiers")
			{
				sld = characterFromId("Svensons_sold_12");
				LAi_SetActorType(sld);
				LAi_ActorTurnToLocator(sld, "soldiers", "soldier1");
				LAi_ActorAnimation(sld, "shot", "Saga_MineBanditDie", 1.0);
			}
			else
			{
				for (i=1; i<=6; i++)
				{
					sld = characterFromId("Mine_bandit_"+i);
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, "EnemyFight");
				}
				LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
				LAi_group_SetCheck("EnemyFight", "Saga_BanditsDestroyed");
				AddDialogExitQuest("MainHeroFightModeOn");	
			}
			pchar.quest.Saga_MineAttack_07.win_condition.l1 = "NPC_Death";
			pchar.quest.Saga_MineAttack_07.win_condition.l1.character = "Mine_bandit_1";
			pchar.quest.Saga_MineAttack_07.win_condition.l2 = "NPC_Death";
			pchar.quest.Saga_MineAttack_07.win_condition.l2.character = "Mine_bandit_2";
			pchar.quest.Saga_MineAttack_07.function = "Saga_SvensonMineexitAttack";
		break;
		
	// ----------------------------- ������� ��� ��� ������ ����������� ������� -------------------------------
		case "Svensons_off":
			dialog.text = LinkRandPhrase("�� ������ ���� ������� ��������, ��� ������ ������!","��� �� �������� ������� ��� ������� �� ��� ���� ���������!","��������� �������� �� ����� �� �������� �����! �� ������ ������ ��� ������!");
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Svensons_off";
		break;
		
		case "Svensons_sold":
			dialog.text = LinkRandPhrase("�� ������ � ���!","������� ���� ��������!","��� ��� �� �����, � ��� ���������!");
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Svensons_sold";
		break;
		
		case "gunner":
			PlaySound("Voice\russian\evilpirates01.wav");
			dialog.text = "��������, ������ � ��� ������. �������� ������, ��� �� ���������.";
			link.l1 = "������, ����� �� ���� ��� ��� � �����... ���� ������� � ����. �� ������, ��� ������ �������� �� ���� ������. �������� ����, ��� �������?";
			link.l1.go = "gunner_0_1";
		break;
		
		case "gunner_0_1":
			dialog.text = "��������, ��������. �������� ����� ������, � - � ����� ���... ��� ���\n��������!.. �����!!";
			link.l1 = "...";
			link.l1.go = "gunner_0_2";
			npchar.quest.canonada = "1";
		break;
		
		case "gunner_0_2":
			DialogExit();
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Saga_Gunfire", 3.0);
			LAi_ActorTurnToLocator(npchar, "goto", "goto14");
		break;
		
		case "gunner_1":
			dialog.text = "";
			link.l1 = "��. ��� �������, ��������, �� ���� ����-�� ������?";
			link.l1.go = "gunner_1_1";
		break;
		
		case "gunner_1_1":
			PlaySound("interface\_bombs_npc.wav");
			dialog.text = "��������, ����-�� �� ����� ������, �� ��� ����... �� ���� ��������� ������ �� ����� �� �����. ������ �������� ������� �������� ����\n��������! �����!";
			link.l1 = "...";
			link.l1.go = "gunner_0_2";
			npchar.quest.canonada = "2";
		break;
		
		case "gunner_2":
			PlaySound("interface\abordage_wining.wav");
			PlaySound("types\warrior03.wav");
			dialog.text = "��! ��������, ��������! ���������� ������ - ��� ���! ������� ���� �������, ���� �� �� ������� ������ � �����-�� ���������� �����! ���-�!";
			link.l1 = "����� - ���... ������������ ������ � ������� �� ����� - ������� ������, ������ � ��� �������� �����! �������� �� ��� �������!";
			link.l1.go = "gunner_2_1";
		break;
		
		case "gunner_2_1":
			PlaySound("interface\_bombs_npc.wav");
			dialog.text = "����, ��������! �������� ������! ������������� � ��������! ������! ����� �� ���� �������!";
			link.l1 = "...";
			link.l1.go = "gunner_2_2";
			npchar.quest.canonada = "3";
		break;
		
		case "gunner_2_2":
			DialogExit();
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Saga_LoginBandos_01", 6.0);
			LAi_ActorTurnToLocator(pchar, "goto", "goto14");
			LAi_ActorTurnToLocator(npchar, "goto", "goto14");
		break;
		
		case "gunner_3":
			PlaySound("interface\abordage_wining.wav");
			PlaySound("types\warrior03.wav");
			PlaySound("Voice\russian\evilpirates05.wav");
			dialog.text = "��-��, ��������, ������� �������!";
			link.l1 = "�� �������������! �������� ������! �� �����, ��� ��� �� ���������� - ������ �������� ���!";
			link.l1.go = "gunner_3_1";
		break;
		
		case "gunner_3_1":
			PlaySound("interface\_bombs_npc.wav");//
			dialog.text = "����, ��������! �������� ������! ��������! ����� �� ���� �������!";
			link.l1 = "...";
			link.l1.go = "gunner_3_2";
			npchar.quest.canonada = "4";
		break;
		
		case "gunner_3_2":
			DialogExit();
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Saga_LoginBandos_02", 5.0);
			LAi_ActorTurnToLocator(pchar, "goto", "goto14");
			LAi_ActorTurnToLocator(npchar, "goto", "goto14");
		break;
		
		case "gunner_5":
			PlaySound("types\warrior04.wav");
			PlaySound("Voice\russian\evilpirates06.wav");
			dialog.text = "��-��-��, �������� �������� �����! ������� ����! ������� � �������� ���������� - ������� �����! ������, ������� ��������� � ��� ��������!";
			link.l1 = "������ ���� ��� ����� � ����������. ��������, �� ��������� ����� ������. ��� ���� ��������� ������� � ����������� ����� �� ������, ����� ������ �� ��� - �������� �� ������ � ��������� ���������! ������ ��� �� ���������.";
			link.l1.go = "gunner_5_1";
		break;
		
		case "gunner_5_1":
			PlaySound("interface\_bombs_npc.wav");
			dialog.text = "����, ��������! ������ � ���! �������� ������!";
			link.l1 = "����-��! � ������! �� ����, � �����! ���-�!!";
			link.l1.go = "attack";
		break;
		
		case "attack":
			DialogExit();
			n = Findlocation("mine");
			Locations[n].hidden_fire = true;
			PlaySound("interface\abordage_wining.wav");
			PlaySound("interface\abordage_wining.wav");
			LAi_ActorTurnToLocator(npchar, "goto", "goto14");
			LAi_group_MoveCharacter(npchar, "TMP_FRIEND");
			if (GetCharacterIndex("Svensons_sold_12") != -1 && pchar.questTemp.Saga.MineAttack == "soldiers")
			{
				sld = characterFromId("Svensons_sold_12");
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			for (i=1; i<=8; i++)
			{
				if (GetCharacterIndex("Ourmine_sold_"+i) != -1)
				{
					sld = characterFromId("Ourmine_sold_"+i);
					if (i == 1) sld.MusketerDistance = 10; 
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				}
			}
			LAi_group_SetRelation("EnemyFight", "TMP_FRIEND", LAI_GROUP_NEITRAL);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Saga_MineBandos_05Die");
			AddDialogExitQuest("MainHeroFightModeOn");	
			DoQuestCheckDelay("Saga_MineSetMusic", 0.3);
			// ���������� ������������� �� 10 ���������
			iTotalTemp = 0;
			DoQuestCheckDelay("Saga_GunAutoFire", 7.0);
			bDisableCharacterMenu = false;//�������� ����������
			InterfaceStates.Buttons.Save.enable = true;//�������� �����������
		break;
		
		case "convict":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = LinkRandPhrase("�� �������� ����, � �� �� ���! ������ ��������!","�������� ���, �������! ������� ���������!","���� ��, ��������, ����! ���� ��� ��� ������, �������!");
				link.l1 = "��! �� ��������� - ������ ��� �� � ������!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = LinkRandPhrase("������� ������� ����������? �� ���������� ���?","���, ������� � ����� �� ����� ���?","�������� ������ �� ��� ��� �����...");
				link.l1 = "�����, ��������, �� ����� ������� ������������ ��������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "convict";
		break;
		
		// ���� ��� ��������
		case "js_girl":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "����� �� ��� �������� ������, ������. �� �� �������� ������������ � �� ����������� � �������� �������.";
				link.l1 = "������, � ��� �����...";
				link.l1.go = "exit";
				NextDiag.TempNode = "js_girl";
				break;
			}
			if(NPChar.quest.meeting == "0")
			{
				dialog.text = TimeGreeting()+", ���. ��, ��� � �������, � ���?";
				link.l1 = "������������. ������� �������������, ����?..";
				link.l1.go = "js_girl_1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "blueveld")
				{
					dialog.text = TimeGreeting()+", ������� "+GetFullName(pchar)+". ���� �� � ���, �� � ��������� ��� �������� - ��� ��� ����. �� ����� �� ������� �����.";
					link.l1 = "���� ������! � ��� ������ �����, ����� �� ��� ������ ����� �����! �������, ������ �������, � ����� ��� ��� �������� - �� �� ������?";
					link.l1.go = "js_girl_3";
					break;
				}
				dialog.text = "�-�, ��� ����� ��, ������� "+GetFullName(pchar)+"... ���������, �� ��� ������ - � ���� �� ������ �����.";
				link.l1 = "�������, ������ �������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "js_girl";
		break;
		
		case "js_girl_1":
			dialog.text = "������. ������ ������� �������.";
			link.l1 = "������� "+GetFullName(pchar)+".";
			link.l1.go = "js_girl_2";
		break;
		
		case "js_girl_2":
			if (CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "blueveld")
			{
				dialog.text = "���� �������? �� ��� ��, ���� �������������� ��� � ���� ����. �� ���� �� ������ � ��� - �� � ��������� ��� �������� - ��� ��� ����. �� ����� �� ������� �����.";
				link.l1 = "���� ������! � ��� ������ �����, ����� �� ��� ������ ����� �����! �������, ������ �������, � ����� ��� ��� �������� - �� �� ������?";
				link.l1.go = "js_girl_3";
				break;
			}
			dialog.text = "���� �������? �� ��� ��, ���� �������������� ��� � ���� ����. ��� �� ������ ����� � ����� ��������. ������������ ����� �� ��������.";
			link.l1 = "� �����, ������ �������...";
			link.l1.go = "exit";
			NPChar.quest.meeting = "1";
			NextDiag.TempNode = "js_girl";
		break;
		
		case "js_girl_3":
			dialog.text = "���. ������ ���� ����������� �� �� ������ ���� ���, ��������� � ��� �� �����, ������� ��������� ������.";
			link.l1 = "��������, ��� ���������� �� � ���� ����, �� ��� � ������ ����� ����� ��... ������ �������� �� �����, �� �������?";
			link.l1.go = "js_girl_4";
		break;
		
		case "js_girl_4":
			dialog.text = "�����, �������. ������� ��� �������� ����� �� �������� �����, ���� ������� �������� �� ����� ����� ���� ��� ������, ������ ������� ��� ����. �� ��������� � ���� ��������, ������ � ����� ������. ������ ��� �� ��������� ������ �� ��� ��������� ������, ����� �� �����������, ������, � ���� � ������� ��� �������������\n� ��� ������ ����� ��� ����� ������� ������ �� ����� ������ '�������' � ���� ��������. ��� ��� ����� ������ ����� �������� ����, � '������' ��������� �� � ����������. ��� ������ ��� � ������ � ��������...";
			link.l1 = "��� ����� � ��� ���������?";
			link.l1.go = "js_girl_5";
		break;
		
		case "js_girl_5":
			dialog.text = "��� �� �����... ������ � ���� ���������, �� ����� ��� ������ ������ �������, ��� � �� ������� ��������� ���-�� ��������, � ������ ������� � ���� ���. ��� ������ �� ���� ����� ����� � ��� ���������� �� ������, �� ���� ��������������. ���� ����� ��� ������ - ������ � ������ ��������� �� ���������, � �� ������ �������� ���� ���� ��������\n���������� ������� ������ �������� ������ � ����� �������. � �����, ������ �����, ������ ����������� � �����-������ ��������� �������� �������� �� ������� ����, � ���� ���. ���������� - ��������� �����.";
			link.l1 = "�������, ��� ��� ����� ��� ������? � ���� ���������� � ���...";
			link.l1.go = "js_girl_6";
		break;
		
		case "js_girl_6":
			dialog.text = "�� ��� ����� � ���������, ������ �� �������. �� ��� �� ������ ����� ���. ��� ������ ����� ������ �� ������ �����, ��� ������������ ���� ����������� �����.";
			link.l1 = "����. ������� �������� �� ����������!";
			link.l1.go = "js_girl_7";
		break;
		
		case "js_girl_7":
			DialogExit();
			NextDiag.CurrentNode = "js_girl_8";
			sld = characterFromId("Gladis"); //������������� ������ �� ����
			ChangeCharacterAddressGroup(sld, "SantaCatalina_fort", "goto", "goto53");
			LAi_SetStayType(sld);
			sld.dialog.currentnode = "FindHelena";
			pchar.questTemp.Saga = "gladis";
		break;
		
		case "js_girl_8":
			dialog.text = "�� ���� ��� �� �������� �� �������, �������, ��� ��� �������� �����.";
			link.l1 = "�������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "js_girl_8";
		break;
		
		// ��������� ������
		case "Alexs_bandos":
			dialog.text = "��! �� ���� ����� �����������, �?";
			link.l1 = "��� � ���� ����� �������� - ��� �� �� ������ �������� ����� � ���� ����������?!";
			link.l1.go = "Alexs_bandos_1";
		break;
		
		case "Alexs_bandos_1":
			dialog.text = "��! ���� ����������? ����� �� ��� ����� �����, �����?";
			link.l1 = "�����, ����� ���� ������ �������� ������, ����� � ����� �������.";
			link.l1.go = "Alexs_bandos_2";
		break;
		
		case "Alexs_bandos_2":
			dialog.text = "�����������, ��?";
			link.l1 = "������, ������: ��� ���� ���� ������� ������ �������-���������. ��� ��� ����������, � � �� ������� �� ���� ����������� �� ����� ����, ����? ����� ��� ��������� - � ����� ����� ������ ����� �������� ������� ���� ������.";
			link.l1.go = "Alexs_bandos_3";
		break;
		
		case "Alexs_bandos_3":
			dialog.text = "�� ��� ��, ����� �� ����������� �������� ���� ��� ���������, ����� �� �� �������!";
			link.l1 = "��-��! �� �����, ���������!";
			link.l1.go = "Alexs_bandos_4";
		break;
		
		case "Alexs_bandos_4":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation("Bermudes_Dungeon")], false);
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("Alexs_bandos_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			int iRank = sti(pchar.rank)+MOD_SKILL_ENEMY_RATE+5;
			int iScl = 25+2*sti(pchar.rank);
			sld = GetCharacter(NPC_GenerateCharacter("Alexs_bandos_5", "mush_ctz_8", "man", "mushketer", iRank, PIRATE, -1, false, "soldier"));
			FantomMakeCoolFighter(sld, iRank, iScl, iScl, "", "mushket1", "cartridge", iScl*2+50);
			ChangeCharacterAddressGroup(sld, "Bermudes_Dungeon", "monsters", "monster8");
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "AlexClock_BandosDie");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}