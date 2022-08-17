void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, Diag;
	int i;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();			
		break;
		//----------------- ����������� ����� ----------------------
		case "DestroyGang_begin":
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); //������ �����
			DeleteAttribute(&locations[FindLocation(pchar.GenQuest.DestroyGang.Location)], "DisableEncounters"); //���������� ����� 
			for(i = 1; i <= 3; i++)
			{
				if (GetCharacterIndex("MayorQuestGang_" + i) == -1) continue;
				sld = CharacterFromID("MayorQuestGang_" + i);
				LAi_type_actor_Reset(sld);
				LAi_RemoveCheckMinHP(sld);
			}
			sTemp = GetFullName(&characters[GetCharacterIndex(pchar.GenQuest.DestroyGang.MayorId)]);
			dialog.text = LinkRandPhrase("������ �� ����� "+ GetSexPhrase("��������","�������") +"! ���� ����� " + GetFullName(npchar) + ", � � �� ������ ���������� � ���� �����...",
				"������-�� ��� ���������� ������ ��������, "+ GetSexPhrase("��������","�������") +", � ���������! ���� ����� " + GetFullName(npchar) + ", �, � �������, �� ������"+ GetSexPhrase("","�") +" ��� ���...",
				"���������� ��� ������, ��� � ���� ����, � ���������� ���������� ������ ��������. � ���������, ��� ��� �, " + GetFullName(npchar) + ", �� ����� ��������. �� ���� ������� ����������!");
			Link.l1 = LinkRandPhrase("���, ��� �� � ���� ��� ����� " + GetFullName(npchar) + ", � ������� ������� ���������� " + sTemp + " ������ � �������?",
				"�-�, ��� �� � ���� ��� ����� ������, �� ������� �������� ������� ���������� " + sTemp + " ?!", 
				"���"+ GetSexPhrase("","�") +" ������ ����, " + GetFullName(npchar) + ". ������� ����������, " + sTemp + ", ������ � ���� � �������...");
			Link.l1.go = "DestroyGang_1";
		break;		
		case "DestroyGang_1":
			dialog.text = LinkRandPhrase("��, � �������� � ���� �����, ��-��... ����, � �� �� "+ GetSexPhrase("��������� �� ���","��������� �� �����") +" �����������, "+ GetSexPhrase("��������","�������") +" �� �������� ��������� �� ����?",
				"���������� - ��� ������� ����, ���� ��������? ��, � �� "+ GetSexPhrase("��������� �� �� �����, ������������","�� ��������� �� �� �������, ������������") +", �� �� ���� �������?",
				"'���������' ������������ ����������� �� ��� - ����, ��-��. � �� ������ �� ���� ������? �����, �� ������ ���� �� ��� ����?");
			Link.l1 = LinkRandPhrase("����� ���, ��������. �������� � ������!", "���� ��, ����� �� ����������. �� ��� ��, ���� ���������� � ����� ����������. ����������, ������ ���...", "��, ��� � � ����. �������� ������, ��������! ���������, ������ ����� � ���� �����.");
			Link.l1.go = "DestroyGang_ExitFight";	
			Link.l2 = LinkRandPhrase("�� ���, ��� ��! ��� ��� �������� ���������� �� � ����...", "���, � �� ����� ���� �� ������, �� ����������, � �����...", "���-���, �� � ���� ����! ��� �������� �� � ����...");
			Link.l2.go = "DestroyGang_2";	
		break;
		case "DestroyGang_2":
			dialog.text = LinkRandPhrase("���-�� �����, "+ GetSexPhrase("�������","�������") +"... � ������ ����������!",
				"� ��� ���������� �������, ����"+ GetSexPhrase("","�") +" �� ��, ������� ������ � �������� �� ��� ����... �����, ������ ������. ���� ������, "+ GetSexPhrase("����� � �������","�����") +"!",
				"�������, �����! ����� ������ ��������� ������� - �� ����� ���� �� ������... �����, ����������, "+ GetSexPhrase("��������","�������") +".");
			Link.l1 = "�� ��������, ����� �������������...";
			Link.l1.go = "DestroyGang_ExitAfraid";	
		break;

		case "DestroyGang_ExitAfraid":
			pchar.GenQuest.DestroyGang = "Found"; //���� �����, �� �������
			npchar.money = AddMoneyToCharacter(npchar, sti(pchar.money));
			pchar.money = 0;
			LAi_SetWarriorType(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_SetCheckMinHP(npchar, LAi_GetCharacterHP(npchar)-1, false, "DestroyGang_SuddenAttack");
			for(i = 1; i < 4; i++)
			{
				if (GetCharacterIndex("MayorQuestGang_" + i) == -1) continue;	
				sld = CharacterFromID("MayorQuestGang_" + i);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, npchar, "", -1);
				LAi_SetImmortal(sld, true);
				LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, false, "DestroyGang_SuddenAttack");
			}
			DialogExit();
		break;

		case "DestroyGang_ExitFight":
			for(i = 0; i < 4; i++)
			{
				if (GetCharacterIndex("MayorQuestGang_" + i) == -1) continue;
				sld = CharacterFromID("MayorQuestGang_" + i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "DestroyGang_Afrer");
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		// ��� - ��������
		case "ContraPass_abordage":
			dialog.text = "����, ��������! ��� �� ������ ������� �� ��� �����?! ���� ��� ����� �� �������!";
			link.l1 = "�������, �� �������! ��� �� ��� ��������... � ���� �� ����� ���� ���� �������, "+pchar.GenQuest.TakePassenger.Name+" ��� �����. ��-�� ��� � �����.";
			link.l1.go = "ContraPass_abordage_1";
		break;
		
		case "ContraPass_abordage_1":
			dialog.text = "� ��� � ����, ��� ���� ���������� �������� �� ��� ����... �� � ��� ������ �� ������! �������, ������� �����!";
			link.l1 = "��� ������� � �� �����, ���!";
			link.l1.go = "ContraPass_abordage_2";
		break;
		
		case "ContraPass_abordage_2":
			DialogExit();
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogFree();
			LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "ContraPass_GivePrisoner");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Tempsailor":
			dialog.text = "�������, �� �������� ����� � ����, ��� �� � ��������. �������� ������� ����������, �� �� ��� �����.";
			link.l1 = "�������! ��� ��?";
			link.l1.go = "Tempsailor_1";
		break;
		
		case "Tempsailor_1":
			dialog.text = "��� �� � ��������� - ������ � ���� � ������ �������.";
			link.l1 = "�������! ������ ������ � ���� ��������. ��� ���� � �������� ����.";
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
			sld = GetCharacter(NPC_GenerateCharacter("ContraPass", "citiz_"+(rand(9)+11), "man", "man", 10, sti(pchar.GenQuest.TakePassenger.Nation), -1, true, "quest"));
			sld.name = pchar.GenQuest.TakePassenger.Name;
			sld.lastname = "";
			pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(sld);
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
			Pchar.GenQuest.TakePassenger.PrisonerIDX = sti(pchar.GenQuest.LastQuestPrisonerIdx);
		break;
		
		case "Fugitive_city": // ����� �� ������
			pchar.quest.AllMayorsQuests_Late.over = "yes"; //������� ����� ������
			dialog.text = "��� ��� ������, ������?";
			link.l1 = "���-���... ���� ��� �� - "+pchar.GenQuest.FindFugitive.Name+"? ����� ��� ��� ������...";
			link.l1.go = "Fugitive_city_1";
		break;
		
		case "Fugitive_city_1":
			dialog.text = "��, �������, ��� �. � ��� �� ������� ���� ������� �� ������� �� ����? � ��� ������� ����... ����������� �����������!";
			link.l1 = "�������. � ������ ���� �� "+XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.Startcity+"Gen")+", �� ������������ ��������� �����������. ���� ������� ������ ���������� ��� � ��������� � ��������� �����... �� ���������� �� ���� �����, ���������, ���� �����!";
			link.l1.go = "Fugitive_city_2";
		break;
		
		case "Fugitive_city_2":
			dialog.text = "������, �� ���-���� ����� ����... ������, ���������� ����, �, ��������, �� �������� ���� �������. ��, � ������������� ������������ �� ������. �� � ���� ������ ��� �� ���� ��� �������� �� ����������, ������� �������� � ����� ���������� ������!\n� ���� ����� � ������ �����, � �����, � ���� �������, � ����� ��. �������� ���� � �����, �������, ��� �� �����, ��� ��� � ������ � �������� � ����, � � ������ ����� ��� ��� ���� ������� � �������. ����� ������ ����, ����� ���...";
			link.l1 = "�� ��������� ���� ���������, ��������! ���������� ������ ������ � �������� �� ����!";
			link.l1.go = "Fugitive_city_fight";
			link.l2 = "��. ����������? ����� � ������ �����? ������... �������, � ����� ��� ���������. ��� ��� ������?";
			link.l2.go = "Fugitive_city_gift";
		break;
		
		case "Fugitive_city_fight":
			dialog.text = "����� ������ ���� ������, �������! ��� ������ � �� �����!";
			link.l1 = "��, ����� ���������, ���� �� ������!";
			link.l1.go = "Fugitive_fight_1";
		break;
		
		case "Fugitive_city_gift":
			TakeNItems(pchar, "jewelry8", 50+drand(25));
			TakeNItems(pchar, "jewelry7", 2+drand(5));
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ������");
			dialog.text = "���, �������... �������, � ������ ������� �� ����� �� ���, �� ������ '�����������'.";
			link.l1 = "�����, ��� �� �������. ��������, ������!";
			link.l1.go = "Fugitive_gift_exit";
		break;
		
		case "Fugitive_gift_exit":
			DialogExit();
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.GenQuest.FindFugitive = "Found"; //���� ��������
			AddQuestRecord("MayorsQuestsList", "12-4");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.Startcity));
		break;
		
		case "Fugitive_fight_1":// � ������ � �����
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			Diag.currentnode = "Fugitive_afterfight";
			LAi_SetImmortal(npchar, false);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(npchar, 10.0, true, "Fugitive_afterfight");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "Fugitive_afterfight":
			dialog.text = "����! � ������... ���� �����, ������� ���� ����...";
			link.l1 = "������� � �����������, ������! � ������ ������ ������� ���� �����... �������� �� ����, � ��� ���������!";
			link.l1.go = "Fugitive_afterfight_1";
		break;
		
		case "Fugitive_afterfight_1":
			DialogExit();
			RemoveAllCharacterItems(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			DeleteAttribute(npchar, "LifeDay");
			LAi_SetImmortal(npchar, true);
			pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(npchar);
			SetCharacterRemovable(&characters[sti(pchar.GenQuest.LastQuestPrisonerIdx)], false);
			Pchar.GenQuest.FindFugitive.PrisonerIDX = sti(pchar.GenQuest.LastQuestPrisonerIdx);
			pchar.GenQuest.FindFugitive = "Execute"; //���� �������� �������
			pchar.quest.FindFugitive1.win_condition.l1 = "location";
			pchar.quest.FindFugitive1.win_condition.l1.location = pchar.GenQuest.FindFugitive.Startcity+"_townhall";
			pchar.quest.FindFugitive1.function = "FindFugitive_inResidence";
			SetFunctionTimerCondition("FindFugitive_Over", 0, 0, 30, false);
		break;
		
		case "Fugitive_shore": // � �����
			pchar.quest.AllMayorsQuests_Late.over = "yes"; //������� ����� ������
			dialog.text = "������, � �� �������� � ���� �������������. ��� ���...";
			link.l1 = "��� �� ��� �� ����, � ���������� ���-���� ��������. �� - "+pchar.GenQuest.FindFugitive.Name+"? �����, ��� �� ����� �������� �����.";
			link.l1.go = "Fugitive_shore_1";
		break;
		
		case "Fugitive_shore_1":
			dialog.text = "� �� ���������. ��� ������������� �. ��� ��� ����?";
			link.l1 = "��� ���� ��������� ��� � "+XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.Startcity)+", ��� �����-���� ������ ������ �������� ����������. � ������� ��� ���������. ������ ������ � �������� �� ����!";
			link.l1.go = "Fugitive_shore_2";
		break;
		
		case "Fugitive_shore_2":
			dialog.text = "��� ��� ��� ���... ������, ������ ��� ������ ������, ����������, ��� � ��� �����. ��, � ������������� ������������ �� ���������. �� ������ ��� �� �� ������� �����. � ������ �� ���� ���������� �� ������� ������, ��� ����� ���� ���! ��������� - �� ��-��!\n� ���� ����� � ������ �����, � �����, � ���� �������, � ����� ��... �������� ���� � �����, �������, ��� �� �����, ��� ��� � ������ � �������� � ����, � � ������ ����� ��� ���� ��������� ���� �������. ��� ���, ��� � ���� ����.";
			link.l1 = "�� ��������� ���� ���������, ��������! ���������� ������ ������ � �������� �� ����!";
			link.l1.go = "Fugitive_city_fight";
			link.l2 = "��. ������ �� ������� ������? ������... �������, � ����� ��� ���������. ��� ��� ������?";
			link.l2.go = "Fugitive_shore_gift";
		break;
		
		case "Fugitive_shore_gift":
			TakeNItems(pchar, "jewelry52", 100+drand(40));
			TakeNItems(pchar, "jewelry53", 400+drand(100));
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ������");
			dialog.text = "���, �������... �������, � ������ ������� �� ����� �� ���, �� ������ '�����������'.";
			link.l1 = "�����, ��� �� �������. ��������, ������!";
			link.l1.go = "Fugitive_gift_exit";
		break;
		
		case "Fugitive_tavern": // � �������
			pchar.quest.AllMayorsQuests_Late.over = "yes"; //������� ����� ������
			dialog.text = "�-�... ��! ������, � �� ��� ��������, �������� � ����� ����. ������������!";
			link.l1 = "���� � ��� ����� ��������, "+pchar.GenQuest.FindFugitive.Name+". ������, �� ��� ����� �� ���������, ������ � ����� ����� �������. ��� ���� ���� � "+XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.Startcity)+", � ��������� �����������. �� ������ ������� �� ������� ��� �������.";
			link.l1.go = "Fugitive_tavern_1";
		break;
		
		case "Fugitive_tavern_1":
			dialog.text = "�-��!.."+RandSwear()+" �� ���-���� ������ ����! ��������, �������, �� �� ������ ����, ��� ���������... � �� ��� ����� ����� ���������� �� ������, �� ���! � �� ��� ��� ������ ����� ��������� � �������, ���� �� ������ �� ����\n��������, ����� �����������. �����, ��� �� ����� ����, ��� ��� � ������ � �������� � ����, � � ������ ����� ���� ���������, ������� � ����� � ������� ������. � ���� ������ ������ ���, � ��� ����� ����, ���� �� ������� ������ �� ������� "+XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.Startcity)+"...";
			link.l1 = "�� ��������� ���� ���������, ��������! ���������� ������ ������ � �������� �� ����!";
			link.l1.go = "Fugitive_tavern_fight";
			link.l2 = "��. ���������� �������? ������ �������, ��� �������? ������... �������, � ����� ��� ���������. ��� ���� ���������?";
			link.l2.go = "Fugitive_tavern_gift";
		break;
		
		case "Fugitive_tavern_gift":
			TakeNItems(pchar, "jewelry5", 50+drand(30));
			TakeNItems(pchar, "jewelry6", 100+drand(50));
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ���������");
			dialog.text = "���, �����... �������, � ������ ������� �� ����� �� ����, �� ������ '�����������'.";
			link.l1 = "�����, ��� �� �������. ��������, ������!";
			link.l1.go = "Fugitive_gift_exit";
		break;
		
		case "Fugitive_tavern_fight":
			dialog.text = "����� ������ ���� ������, �������! ��� ������ � �� �����!";
			link.l1 = "��, ����� ���������, ���� �� ������!";
			link.l1.go = "Fugitive_fight_2";
		break;
		
		case "Fugitive_fight_2":// � �������
			DialogExit();
			chrDisableReloadToLocation = true;//������� �������
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//��������� �������
			LAi_SetImmortal(npchar, false);
			LAi_SetStayType(npchar);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(npchar, pchar.location, "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			Diag.currentnode = "Fugitive_afterfight";
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(npchar, 10.0, true, "Fugitive_afterfight");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
	}
}
