
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sGem, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//--------------------------- ������� ��� --------------------------------
		//�������� ���������� ���� �����
		case "Begin_PoorKill":
			dialog.text = "������ ����, �������. �� ���������� ������������ �� ���� �� ����� ����?";
			link.l1 = "������ �� ����������? � �������������!";
			link.l1.go = "Begin_PoorKill_1";
		break;

		case "Begin_PoorKill_close":
			dialog.text = "��, �������... �� ��� ��, ����� ����.";
			link.l1 = "...";
			link.l1.go = "Exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			ChangeCharacterComplexReputation(pchar, "nobility", 15);
			pchar.questTemp.LSCC = "PoorIsGood";
			SetQuestHeader("ISS_PoorsMurder");
			AddQuestRecord("ISS_PoorsMurder", "12");
			AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("��","��"));
		break;

		case "Begin_PoorKill_1":
			dialog.text = "���������! ����� ����� �������� ��������.";
			link.l1 = "����� � ����, ��������.";
			link.l1.go = "Begin_PoorKill_2";
		break;
		case "Begin_PoorKill_2":
			dialog.text = "��-��, ��� �������� ���� ������!\n�� ��� ��, ��� ������ ��������� �������������. ���� ����� " + GetFullName(npchar) + ". ��������, �� � ����� ������� � ��� � ����, ��� �� - ������� " + GetFullName(pchar) + ". ����� ��� ��������, ��� �� �����. ��� ���?";
			link.l1 = "�����. ��� ��� �� ����������� ������. � ��� �� �� �� ���� ����� ������������?";
			link.l1.go = "Begin_PoorKill_3";
		break;
		case "Begin_PoorKill_3":
			dialog.text = "� - ������� �������, ������ ���.";
			link.l1 = "���������. � ��� �� ���� � ��� �� ���?";
			link.l1.go = "Begin_PoorKill_4";
		break;
		case "Begin_PoorKill_4":
			dialog.text = "��, ����������, ������ ��� "+ GetSexPhrase("������ �������� ��������","����� ������� �������") +", ��� ��. ���� � ���, ��� ��� ������������ ������� ���������� ���������� ������ � �������������� �� �������� ���������� ����. ��-��, ������ ���!";
			link.l1 = "���"+ GetSexPhrase("","�") +" �� ������ ������������. ������ �������� �� ���� ��������...";
			link.l1.go = "Begin_PoorKill_5";
		break;
		case "Begin_PoorKill_5":
			dialog.text = "���� '������� ����' ����� ����������!";
			link.l1 = "� ��� ��� ��? ���������: ����� � ����, ��������...";
			link.l1.go = "Begin_PoorKill_6";
		break;
		case "Begin_PoorKill_6":
			dialog.text = "��, ������. ��� �����, ����� �� �������� ��� �� ����� � ��������� � �������. ������ �����, � ������ ������, ���������� �� ������������ ��������������. �� ��� ������ �� ������ ��� ��������� ������� ����!";
			link.l1 = "�� �� ���� ���� ����������? �� �����"+ GetSexPhrase("���","��") +" ������?! ����-�� ������, ��������, ���� ���...";
			link.l1.go = "Begin_PoorKill_close";
		break;
		//������� ����� 
		case "GiveKeyMan":
			dialog.text = "���?";
			link.l1 = "��, ��������, ��� �� ������ ������?";
			link.l1.go = "GiveKeyMan_1";
		break;
		case "GiveKeyMan_1":
			dialog.text = "�. � �� ��� ���"+ GetSexPhrase("��","��") +"?";
			link.l1 = "���� ����� ������� " + GetFullName(pchar) + ".";
			link.l1.go = "GiveKeyMan_2";
		break;
		case "GiveKeyMan_2":
			dialog.text = "� ��� ���� �����, ������� " + GetFullName(pchar) + "?";
			link.l1 = "��������, ��� �� ����� ������� � ���� ����������� ������� ����? ���� �������� ���� ����� ��, � ������.";
			link.l1.go = "GiveKeyMan_3";
		break;
		case "GiveKeyMan_3":
			dialog.text = "���, ��� � ������, ����� �. � ���� ������� ��� �������������, ��� �� �������"+ GetSexPhrase("��","���") +" �� ������. � ����� ��������� ������ ������! ����, ������, ����� � ���� - ���������� �����, �� �� ��� � � �������� �� �������. ��� ��� ������ � � ���� ��������� ������ ������!";
			link.l1 = "��, �������! ������, ��� ��� � �����. ��� ����� ����� ����� �� ������, ��� � �������-�����������.";
			link.l1.go = "GiveKeyMan_4";
		break;
		case "GiveKeyMan_4":
			dialog.text = "���, ���������� ������� � �� ����� - �� �����������, ������ ��! � ���� ������ ������� - ������� ������. �� � ��� ��� ������, ���������� ����� �������? ���� ����� ����� ���������.";
			link.l1 = "������, ��������, ��� ��� � ���� �� �����, � ��� � ���� ����...";
			link.l1.go = "GiveKeyMan_5";
		break;
		case "GiveKeyMan_5":
			dialog.text = "��! �� �� "+ GetSexPhrase("��������� ��������","��������� ���������") +", ��� � �������...";
			link.l1 = "��� ������, �������!!! �� ��������� ����� - ��������� �������...";
			link.l1.go = "GiveKeyMan_6";
		break;
		case "GiveKeyMan_6":
			dialog.text = "��������� �������, ��������?.. � ��� �������, ��� ���� ����� ������ ����.";
			link.l1 = "������ ���.";
			link.l1.go = "GiveKeyMan_7";
		break;
		case "GiveKeyMan_7":
			npchar.quest.price = makeint((sti(pchar.money)/4*3)/1000)*1000;
			if (sti(npchar.quest.price) > 10000)
			{
				dialog.text = "�-�... ������! � ���� �� ���� ���� " + FindRussianMoneyString(sti(npchar.quest.price)) + ".";
				link.l1 = "��������, �������� ����!";
				link.l1.go = "GiveKeyMan_10";
			}
			else
			{
				dialog.text = "��-�-�, "+ GetSexPhrase("��������, �� �� ����������","�������, �� �� ����������") +"!!! � ����� ��������� � ����� ����� ��������?! ������, � ���� ����� � �������� ������, ��� ���� �������� �� ��������. � ���� � ������ �������?";
				link.l1 = "��� ��� ������?!";
				link.l1.go = "GiveKeyMan_8";
			}
		break;
		case "GiveKeyMan_8":
			dialog.text = "��� ������, "+ GetSexPhrase("��������","�������") +", ��� ���� ��� ������� ������ ���� �� �� �������, �� ������ ��� � �����������. �������, ��� ����������� ��������, � ������ �� ���� �� ���.";
			link.l1 = "�����, ����� ���� �����...";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toMasterKeysNoMoney";
			NextDiag.TempNode = "GiveKeyMan_NoMoney";
		break;
		case "GiveKeyMan_NoMoney":
			if (sti(pchar.money) >= 20000)
			{
				npchar.quest.price = makeint((sti(pchar.money)/5*4)/1000)*1000;
				dialog.text = "�� ���, ��� �����, ��� ���������... ����� �������� � ������ ��������� � �����. � �����, � ����� ��� ���� �������, �����������, �� " + FindRussianMoneyString(sti(npchar.quest.price)) + ".";
				link.l1 = "��-��, �������!!";
				link.l1.go = "GiveKeyMan_10";
			}
			else
			{
				dialog.text = "���� � �� ���� �� ��� �� ������ �������������. �� ��� ���"+ GetSexPhrase("","�") +" ��� ����� � �������, ��� � �����"+ GetSexPhrase("��","���") +". ����� ������� ��� �� �����.";
				link.l1 = "��, ��������� ��� �������.";
				link.l1.go = "exit";
			}
		break;
		case "GiveKeyMan_10":
			dialog.text = "���������� �� ������. ���"+ GetSexPhrase("","�") +" ���������, � �� ������ ������! � �����, �������������� � ���� � ������. ����� �����!";
			link.l1 = "��, ������, ��� �������� ����� ������... ������, � �����, ������� ����?";
			link.l1.go = "GiveKeyMan_11";
		break;
		case "GiveKeyMan_11":
			dialog.text = "���, "+ GetSexPhrase("��������","�������") +". �� �� ���"+ GetSexPhrase("","�") +" ���������, � ��� �������...";
			link.l1 = "�������. ��� ��� ����?";
			link.l1.go = "GiveKeyMan_12";
			AddMoneyToCharacter(pchar, -sti(npchar.quest.price));
		break;
		case "GiveKeyMan_12":
			dialog.text = "��� ���� ����������. ������� �� ��� ������ ����� ���. � ���� � ���� �������� �� �������� � �������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			SetTimerFunction("LSCC_openMasterHouse", 0, 0, 2);
			LocatorReloadEnterDisable("Villemstad_town", "houseSp5", true);
			npchar.location = "none";
			AddQuestRecord("ISS_PoorsMurder", "6");
		break;

		case "GiveKeyManInside":
			dialog.text = "���, ��� � ��!";
			link.l1 = "���, ��� � �! ��� ��� ����?";
			link.l1.go = "GiveKeyManInside_1";
		break;
		case "GiveKeyManInside_1":
			dialog.text = "����?.. ��, �� ������, ��� ��������� ��� ��������, �� � ����� ����� ������ ������������ �������-����������.";
			link.l1 = "�� ��� ��, ��������, ��������?!";
			link.l1.go = "GiveKeyManInside_2";
		break;
		case "GiveKeyManInside_2":
			dialog.text = "� ��� �� �����"+ GetSexPhrase("","�") +"? � �� �� ���� ��� ����... � �����, ��� �������, ��� ���� ��������...";
			link.l1 = "�� ��, �������! ��� � �� ����� ������ ����?!";
			link.l1.go = "GiveKeyManInside_3";
		break;
		case "GiveKeyManInside_3":
			dialog.text = "�� ������. ����-�� � ������, ��� � ������. � ����� ���� �����!";
			link.l1 = "��-��...";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			AddDialogExitQuestFunction("LSCC_enterSoldiers");			
		break;
		//�������������� ������
		case "MK_HollOfficer":
			dialog.text = "��������� �� ����, �������!";
			link.l1 = "���� ���?";
			link.l1.go = "MK_HollOfficer_1";
		break;
		case "MK_HollOfficer_1":
			dialog.text = "� �������� ���������� ����������. �� ���������, ��� �������... � �� ��������� ������, ����� � ���� �������� ��������� ����!";
			link.l1 = "��, ������, ��� ���� � ���, ��� � � ���� ��������"+ GetSexPhrase("","�") +" ��������� ����...";
			link.l1.go = "MK_HollOfficer_2";
		break;
		case "MK_HollOfficer_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Villemstad_houseSp5")], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//�������� ����� � ������
		case "PKInMarigo":
			dialog.text = "��, � �� ���������� ����������� � ���� ��� ���! �� ��� ��������� �������? �������� � ���������?";
			link.l1 = "�� ���, � ��������� ��� � �������. �� ������, ���� � ���, ��� � ����� �� ���� ����� ������ ������� - ������ ����.";
			link.l1.go = "PKInMarigo_1";
		break;
		case "PKInMarigo_1":
			dialog.text = "� ��� ������ �� ����������, �� ��� ��� �� �������. ������������ �� ���������.";
			link.l1 = "�������... �� � ���-����, ��� �����?";
			link.l1.go = "PKInMarigo_2";
		break;
		case "PKInMarigo_2":
			dialog.text = "� ���, ������ ������? ����� ��� � ��������� ������ �� ������. �� ��������� ����?";
			link.l1 = "�������, �������. �� ���-����, ����� �������� �� ������, ��� ��.";
			link.l1.go = "PKInMarigo_3";
		break;
		case "PKInMarigo_3":
			dialog.text = "���-�� ��� �� �������� ���� �������������. ���� ������ ���������� � ��� �� ����, �� ���������� �������� �� �������.";
			link.l1 = "������, �� �����...";
			link.l1.go = "PKInMarigo_4";
		break;
		case "PKInMarigo_4":
			dialog.text = "������� �� ������. � ������ �������� ����������� ������������ ������ �����������!";
			link.l1 = "������. � ����, ��� �� ��������� �������������� ����������� ����-������� �������� � ��������� ����. ���� �����, ��� �� ������ ���� � ������������ �������� �����. � ��� � ���� �����, ������ ����� ��� �� ������� ������� �������.";
			link.l1.go = "PKInMarigo_5";
		break;
		case "PKInMarigo_5":
			dialog.text = "� �� ������� �� ����� �� ������?";
			link.l1 = "��� ��� �� ��� ��� ������� � ���. � ���� ����� �� �������!";
			link.l1.go = "PKInMarigo_6";
		break;
		case "PKInMarigo_6":
			dialog.text = "�� ���� ���������, �� ��� ������, �������? �������� ���� �� ��������, ������� ��������� ��������� - ��� �� �������. �� ��� ����� � ���� ��������, ������� ����������� ����� ��������� ����� - ��� �������.\n"+
				"���������� ������ �� ���� �������������, �������� ������� - � ����������� ���������� �� ��������, ����� ��� ������� �� ������. � ��� ���� ����������� ����� ������ ������ ��� � ������. � ��� ��� ��������� ����, �������, ���� ������ � �����.";
			link.l1 = "�������, ��� ���� ������ � ������������ �� ����. � ���� ����� ��� ��� � � ��������� �������, ������� ��� �� ������� �� ��� ����������...";
			link.l1.go = "PKInMarigo_7";
		break;
		case "PKInMarigo_7":
			dialog.text = "�-�-�, �������, �����, ��� ���� ������� �����. ��� ������� ���� ��� ��������, ���� ��������: '� ������� ����� ����...'.";
			link.l1 = "�� � ��� �� ��������, ���� ����-�������?";
			link.l1.go = "PKInMarigo_8";
		break;
		case "PKInMarigo_8":

			dialog.text = "����. ������ ����� ������!";
			link.l1 = "��������� �� �������, ����� ������� ������...";
			link.l1.go = "PKInMarigo_9";
		break;
		case "PKInMarigo_9":
			chrDisableReloadToLocation = true; 
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_group_Attack(npchar, pchar);
			pchar.quest.PQ8_afterFight.win_condition.l1 = "NPC_Death";
			pchar.quest.PQ8_afterFight.win_condition.l1.character = "PoorKillSponsor";
			pchar.quest.PQ8_afterFight.win_condition = "OpenTheDoors";
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//���� � ����������
		case "LSCCQuestMent":
			dialog.text = "��, ������, ��� ��� � ���� �� �������?";
			link.l1 = "�� ��� � ���?";
			link.l1.go = "LSCCQuestMent_1";
		break;
		case "LSCCQuestMent_1":
			dialog.text = "������ �������������! ����� ��� ��� ��������� � ����� �������.";
			link.l1 = "��� �����!..";
			link.l1.go = "LSCCQuestMent_2";
		break;
		case "LSCCQuestMent_2":
			dialog.text = "����� ����� � ��������������� ��������� ������. � ��� ���� �������� ��� ��� ���������� � ������ ����, ����� ������ ����� ����� ���������� �������.";
			link.l1 = "��� �� ��� �� �����? �� ���� ��� �� ���������!.. ��, �����, ���� �������� �������.";
			link.l1.go = "LSCCQuestMent_3";
		break;
		case "LSCCQuestMent_3":
			dialog.text = "���?!! �����, �� ���!";
			link.l1 = "��, ��� ������� �� ������? � ��� ���� �����������!";
			link.l1.go = "LSCCQuestMent_4";
		break;
		case "LSCCQuestMent_4":
			AddQuestRecord("ISS_MainLine", "9");
			pchar.questTemp.LSCC = "afterFightInProtector";
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_SetWarriorTypeNoGroup(npchar);
			sld = characterFromId("AndreLabor");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//��������� ������, �������� ���� ��������
		case "LSCCQuestNarval":
			dialog.text = "��� �� ��� �������?!";
			link.l1 = "�? ��, ��� ���� �������...";
			link.l1.go = "LSCCQuestNarval_1";
		break;
		case "LSCCQuestNarval_1":
			dialog.text = "�� ���, "+ GetSexPhrase("��������","������") +", �� ������, ��� ��� - ���������� '��������'?";
			link.l1 = "�� ����...";
			link.l1.go = "LSCCQuestNarval_2";
		break;
		case "LSCCQuestNarval_2":
			dialog.text = "�� ���, "+ GetSexPhrase("��������","��������") +", ������ �����?";
			link.l1 = "��, ��... ������ ����� ������. ������, ��������, �� ��� �������� ���� �����.";
			link.l1.go = "LSCCQuestNarval_3";
		break;
		case "LSCCQuestNarval_3":
			AddQuestRecord("ISS_MainLine", "11");
			AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("��","���"));
			pchar.questTemp.LSCC = "toAdmNarvalRing";
			LAi_LocationFightDisable(loadedLocation, false);
			LAi_SetWarriorTypeNoGroup(npchar);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		//--------------------------- ���� ����� ������ �������� --------------------------------
		//������� ����� ������ ��������
		case "BlueBirdCapitain":
			dialog.text = "����� �� � �����, ��� �� ���"+ GetSexPhrase("��","��") +"...";
			link.l1 = "���� ����� " + GetFullName(pchar) + ". � - �����.";
			link.l1.go = "BlueBirdCapitain_1";
		break;
		case "BlueBirdCapitain_1":
			dialog.text = "� ������ ������� �� �����"+ GetSexPhrase("","�") +" �� ��� ����?!!";
			link.l1 = "��� �����, � ����"+ GetSexPhrase("��","��") +" ������� ��� �� ���. �� ������� �� ��������� ��������� � ����������...";
			link.l1.go = "BlueBirdCapitain_2";
		break;
		case "BlueBirdCapitain_2":
			dialog.text = "� ��� ����� �������?! ���"+ GetSexPhrase("","�") +"-�� �� ����, ������, ��������� �� �������...";
			link.l1 = "��� ������, ��������, ������ �������. �� ��� ��� ��� ����� �����, ��� �� � �������� ����� �������������? ��� ������ ���������, �� ����� ������ ������ ��� ����.";
			link.l1.go = "BlueBirdCapitain_3";
		break;
		case "BlueBirdCapitain_3":
			dialog.text = "�� ���� ����, ��������! �� ��������� ��������� ���� �������, � ������ ���������!";
			link.l1 = "��, ������...";
			link.l1.go = "BlueBirdCapitain_4";
		break;		
		case "BlueBirdCapitain_4":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogExitWithBattle(""); 
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;	
		//�������� ������� ���������
		case "BlueBirdTrader":
			dialog.text = "���� ������, ������ �� ������ �� ���?!!";
			link.l1 = "��� ��������� ������ �������, ��������. ������ ���� � ������ �� ����.";
			link.l1.go = "BlueBirdTrader_1";
		break;
		case "BlueBirdTrader_1":
			dialog.text = "������� �������...";
			link.l1 = "������ ������ ������, � � ��������� ������� ������ ������������ � �������. �����, ��� " + GetFullName(pchar) + " �������� ��� ������.";
			link.l1.go = "BlueBirdTrader_2";
		break;
		case "BlueBirdTrader_2":
			dialog.text = "������ ������� �����������.";
			link.l1 = "����� �� ���� ���. ���� ����...";
			link.l1.go = "BlueBirdTrader_3";
		break;
		case "BlueBirdTrader_3":
			QuestAboardCabinDialogNotBattle(); 
            DialogExit();
		break;	
		//--------------------------- ��������� ��������, ���� --------------------------------
		//������� ����, ������ ����� �� ������
		case "DeckSharp":	//�� ������
			dialog.text = ""+ GetSexPhrase("����������, ��������. ���� ������ �� ������������ ������ ���� �� ���� �����","��-�, ����� � ��� �����! ���� ������ �� ������������ ������ ���� �� ���� �����, ���������� ��������") +"?";
			link.l1 = "����������� �������� ���������� �����! � ������ ��������"+ GetSexPhrase("","�") +" ����...";
			link.l1.go = "DeckSharp_1";
			npchar.quest.meeting = true;
			//���������� ����������, ���� ���� ������ �� �������
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("��������","�������") +", � ������ �����! ����� ���� ������ �� ����. ��� ����...";
				link.l1 = "�� �����, �������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //����� �������� � ��������
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "DeckSharp_1":
			dialog.text = "��, ��� �������... ��� ��� ������� ���� �� ���"+ GetSexPhrase("",", ���������") +"?";
			link.l1 = "�� ������, ��������, � ���� �� ��������� �������� ����������. �������������, ��� �������...";
			link.l1.go = "DeckSharp_2";
		break;
		case "DeckSharp_2":
			dialog.text = "�-�-�, ����������� ����!!! ��� ����� ��������? �����������!";
			link.l1 = "�������� � ���, ��� � �� ����, ��� ��� �������� �����. ��� �� ����� �������� � ������������ ���������! ���, ����"+ GetSexPhrase("��","��") +" � ���� �� ������� ��� � ����������� � ���� ����.";
			link.l1.go = "DeckSharp_3";
		break;
		case "DeckSharp_3":
			dialog.text = "��, �� ��, ����� ������� ����� ������ �����, ������ ������ �� �� ��������\n�� ��� ��, ������ ���� ��� ������� ����, ��� ������� �� ��������.";
			link.l1 = "��, ����, �������, ������� ����!";
			link.l1.go = "DeckSharp_4";
		break;
		case "DeckSharp_4":
			dialog.text = "�� ���� �� ���, �� ����� ��������������\n� �����, ������ ��������� ������ ����. ����, ����� ������� ����� ���� ����� ���������, ���������� ������ � ����������� �������� ��� �������� �� ����������, ��� �������\n������� ���������� ����� �� �����������, ��� ���, ����� ��� � ���� � ���������!";
			link.l1 = "������, � ��� �� �������, ��� ��� ����� � ������ ������?";
			link.l1.go = "DeckSharp_5";
		break;		
		case "DeckSharp_5":
			dialog.text = "��� ��� ������� ������. �� ����� ������"+ GetSexPhrase("",", ���� ����� �������, ��� ��") +", ���� �� �����!";
			link.l1 = "��, �� �����, ��� ������...";
			link.l1.go = "DeckSharp_6";
		break;
		case "DeckSharp_6":
			GetPerlShore(); //��� �������� �������
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.Sharp.PearlAreal.add")) sTemp = pchar.questTemp.Sharp.PearlAreal.add; 
			dialog.text = "������, ������. ���� �� " + XI_ConvertString(pchar.questTemp.Sharp.PearlAreal + "Dat") + " �����, ��� ��������� " + GetConvertStr(pchar.questTemp.Sharp.PearlAreal.Shore, "LocLables.txt") +
				sTemp + ". ���� �� ������� ���� �� " + FindRussianDaysString(sti(pchar.questTemp.Sharp.PearlAreal.terms)) + ", �� ����� ������� ����� ���.";
			link.l1 = "�����"+ GetSexPhrase("","�") +". ������� ����, ����������.";
			link.l1.go = "DeckSharp_7";
		break;
		case "DeckSharp_7":
			dialog.text = RandPhraseSimple(""+ GetSexPhrase("���� ���� ������� ����! ��� ��� ������ ��������","��� ���� - ������ �����, ���������") +".", ""+ GetSexPhrase("� �����������, ����� ���� �������� ������� ����","��� ����� �������, ��� �� - ������ �����") +"!");
			link.l1 = "��, ����. ������� ����, "+ GetSexPhrase("������� ����","�����") +". �� ��� ������� �����!";
			link.l1.go = "DeckSharp_8";
		break;
		case "DeckSharp_8":
			dialog.text = RandPhraseSimple(""+ GetSexPhrase("�� �� �� ���, ��������, ����� ��� - ���������...","��������� ���, ��� ���������. � �����, ���-������ ����������, ��� �������, � ������������� ����������?") +"",""+ GetSexPhrase("�������� �������� - ��������� ����, ��� �������... ������ ���, ��� ����� - ������!","������ ���, ��� ����� - ������. " + pchar.name + ", � �����, ��������� ���� �������...� ������, ����� ������ �����?") +"");
			link.l1 = ""+ GetSexPhrase("�������������, ������� ����!!","�� ������������ �������, �����. ��� ��������!") +"";
			link.l1.go = "DeckSharp_8exit";
		break;	
		case "DeckSharp_8exit":
			sTemp = "";
			if (CheckAttribute(pchar, "questTemp.Sharp.PearlAreal.add")) sTemp = pchar.questTemp.Sharp.PearlAreal.add; 
			NextDiag.TempNode = "DeckSharp_over";
			npchar.DeckDialogNode = "NewDeckSharp"; //����� ���� �� ������
			pchar.questTemp.Sharp = "toPearl"; //���� ������ - �� ��������!!!
			AddQuestRecord("SharpPearl", "5");
			AddQuestUserData("SharpPearl", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("SharpPearl", "sSex1", GetSexPhrase("��, �������� �����!","�������� �����..."));
			AddQuestUserData("SharpPearl", "iDay", FindRussianDaysString(sti(pchar.questTemp.Sharp.PearlAreal.terms)));
			AddQuestUserData("SharpPearl", "sAreal", XI_ConvertString(pchar.questTemp.Sharp.PearlAreal + "Dat"));
			AddQuestUserData("SharpPearl", "sTarget", GetConvertStr(pchar.questTemp.Sharp.PearlAreal.Shore, "LocLables.txt") + sTemp);
			pchar.quest.SeaPearl_login.win_condition.l1 = "location";
			pchar.quest.SeaPearl_login.win_condition.l1.location = pchar.questTemp.Sharp.PearlAreal.Island;
			pchar.quest.SeaPearl_login.function = "SeaPearl_login";
			SetTimerFunction("SeaPearl_Late", 0, 0, sti(pchar.questTemp.Sharp.PearlAreal.terms));
			if (pchar.location != "Deck_Near_Ship")
			{
				LAi_SetActorTypeNoGroup(npchar);
				LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 15.0);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//������� ����, ����������� ��������� �� ������
		case "NewDeckSharp":
			dialog.text = "�-�-�, ���� � ����?! ����������� "+ GetSexPhrase("���������������","����, ���������") +"!";
			link.l1 = "����������, ������� ����. ��� ���������?";
			link.l1.go = "NewDeckSharp_1";
			//���������� ����������, ���� ���� ������ �� �������
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("��������","�������") +", � ������ �����! ����� ���� ������ �� ����. ��� ����...";
				link.l1 = "�� �����, �������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //����� �������� � ��������
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "NewDeckSharp_1":
			dialog.text = "�� ��� �����, "+ GetSexPhrase("��������","��������") +", ���������� ����\n��, �����������, ����� ���������"+ GetSexPhrase("","�") +" �� ���� ���?";
			link.l1 = "�� ��� �� ��� ��, ��������, �� �������� �� ��������...";
			link.l1.go = "NewDeckSharp_2";
		break;
		case "NewDeckSharp_2":
			if (pchar.questTemp.Sharp.SeekSpy == "alwaysKnow" || pchar.questTemp.Sharp.SeekSpy == "over")
			{
				dialog.text = "�� ������, "+ GetSexPhrase("��������","��������") +", � ���� � ���� ����� ��������. ������ � ���� ���� ���������� ������� �� �������, � � ���... ��, � �����, �� ���� �, ��� �����.";
				link.l1 = "�-��, ��������... �� ��� ��, ������ �����. ������, ����.";
				link.l1.go = "exit";
				CloseQuestHeader("SharpPearl");
				NextDiag.TempNode = "DeckSharp_noWork";
				pchar.questTemp.Sharp = "over";
			}
			else
			{
				dialog.text = "��, ���� ���, �������, �������. �� � �� ���� ������������ ���� ������ �� ����,  "+ GetSexPhrase("��������,","��������,") +" ��� ������ ���� ����!";
				link.l1 = "����� ������ ������������?";
				link.l1.go = "NewDeckSharp_3";
			}
		break;
		case "NewDeckSharp_3":
			dialog.text = "������������. "+ GetSexPhrase("�� ���� ����, ����������","�� ������������, ��� ����� �� �����") +".\n� �����, � ���� ������� ���� ����, �� �� ������ ���. �� ����"+ GetSexPhrase("��","��") +" ������ ��� �������������� ��������� ������, "+ GetSexPhrase("��������","��������") +".";
			link.l1 = "��, �� � ������� �� ������?";
			link.l1.go = "NewDeckSharp_4";
		break;
		case "NewDeckSharp_4":
			dialog.text = "��, �������, ��� ����� � " + FindRussianMoneyString(sti(pchar.questTemp.Sharp.price)) + " ���� �������.";
			link.l1 = "��, ���� ������� ����, ��� �� ����? ��� ������� ����� ��� ���� �� ������ ������! ���� ������, ������ ����.";
			link.l1.go = "NewDeckSharp_noMoney";
			if (sti(pchar.money) >= sti(pchar.questTemp.Sharp.price))
			{
				link.l2 = "�� ��� ��, � ������"+ GetSexPhrase("��","��") +", ��������. ������� ���� �����������!";
				link.l2.go = "NewDeckSharp_GiveMoney";
			}
		break;

		case "NewDeckSharp_GiveMoney":
			dialog.text = "��, ��� � �������! ����� ������ ��� �� ����, "+ GetSexPhrase("��������","��������") +".";
			link.l1 = "��� �������. ��� ��� ��� � ��������?";
			link.l1.go = "DeckSharp_6";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharp.price));
		break;
		case "NewDeckSharp_noMoney":
			if ((sti(pchar.questTemp.Sharp.price)*10) < sti(pchar.money))
			{
				if (pchar.location == "Deck_Near_Ship")
				{			
					dialog.text = ""+ GetSexPhrase("���� ������! �� ����, " + pchar.name + ", ���� �����?! � �� �� ����� �����, � ������� ����!! ������ �����, �����?! �������, � �� ����, ��� ����� � ���� �������� �������? ����, ��������, ��� ��� ��������� ��������. ��� ���, �����, �������������� ��� ���� � ���� ������ �� ��� ������ ������� ������������ ����-�����!","���� ������! " + pchar.name + ", ��, �������, ������ �������� � ������, ������ � � �� ����� �����, � ������� ����! ������ �����! �������, � �� ����, ��� ����� � ���� �������� �������? ����, ��������, ��� ��� ��������� ��������. � ��� � ����� ������� ���������...���, ����, ������, ��� ������ �������. � �����, ��� ��������������, ��� ��� ����������� ��������������") +"..";
					link.l1 = ""+ GetSexPhrase("����������, �� ���� �������?! ��������, ��� �������... � � ���� �� ������ ������ �������� � �� ����� ������. ��� ��� �� ���������� � ����������. �����, � ��� ��������������","����������, �� ���� ������������? �� ���, ���������� � ����������, � ���� �� �����-������ ��� ����� ����������, �� ������� �����") +"...";
				}
				else
				{
					dialog.text = ""+ GetSexPhrase("��-�� � �� �����, �� ���� �� ���� �������? �� ���� ���� ������, �������, � �� ����, ��� ����� � ���� �������� �������? ����, ��������, ��� ��� ��������� ��������. ��� ���, �����, �������������� ��� ��� ������ ������� ���-������ �� ����-����-��� ������, � �������","��, " + pchar.name + ", �� ���, ���� �������� ���������? �� ���, �������, � �� ����, ��� ����� � ���� �������� �������? ����, ���������, ��� ��� ��������� ��������. � ��� � ����� ������� ���������... �� ������� ����, ����. ��� ���, ��� ������ �� ����, ��� ������ ������� ���-������ �� ����-����-��� ������, � �������") +"...";
					link.l1 = "����������, �� �� ��������, � �� ��������, ��� �������. �����, � ��� ��������������...";
				}
				link.l1.go = "NewDeckSharp_5";
			}
			else
			{
				if (sti(pchar.questTemp.Sharp.price.evil))
				{	//���� �� � ����������
					dialog.text = "���, "+ GetSexPhrase("��������","��������") +", ������ �� �������! � ���� ������ ���� ���� �������, � ��� ��� �� �� ������ ���������. � �������� � �� �����������. ������ �� �����, � �����...";
					link.l1 = "�-��, ����, ����, ����� ����. � �����"+ GetSexPhrase("","�") +", �� ��������� ����...";
					link.l1.go = "NewDeckSharp_7";
					if (sti(pchar.money) >= sti(pchar.questTemp.Sharp.price))
					{
						link.l2 = "��, �������� ������. �� �� ������ ��� ������� �� ������� ��� ������� ���������� �������... ������� ���� �����������!";
						link.l2.go = "NewDeckSharp_GiveMoney";
					}
				}
				else
				{
					dialog.text = "�� �����, ��� �� � ����, ������� � ������ ����-�� �� � ����... ������ ����!";
					link.l1 = "��� ��� ���������! ��� ��� ��-��������-�������!.. ��� ��� ��� � ��������, ����������� ����?";
					link.l1.go = "DeckSharp_6";
				}
			}
		break;
		case "NewDeckSharp_5":
			dialog.text = "�����, ������, �����������. ������, ��� ���� ���� �� ������. �� ���� ���� ���"+ GetSexPhrase("��","��") +" �������, " + pchar.name + ", ��� ����� ���������� �� ����� ����... � �����, ������ �� �����, ��� ������� �� �� ��������.";
			link.l1 = "�� ������, ������� ���� �����������!";
			link.l1.go = "NewDeckSharp_6";
			link.l2 = "��-�, ������� � �� ����� ����. ����� ���-������...";
			link.l2.go = "NewDeckSharp_7";
		break;
		case "NewDeckSharp_6":
			dialog.text = "�� ���, ��� ������ ����! ������ ��������, ������� � �������"+ GetSexPhrase("��","��") +"!"+ GetSexPhrase(""," � ������, ������ ������������� �������!") +"";
			link.l1 = "�������, ����, �������. ��, ��� ��� ��� � ��������?";
			link.l1.go = "DeckSharp_6";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharp.price));
		break;
		case "NewDeckSharp_7":
			dialog.text = "��, ��� ������. ������!";
			link.l1 = "����� ��������...";
			link.l1.go = "NewDeckSharp_7exit";
		break;
		case "NewDeckSharp_7exit":
			AddQuestRecord("SharpPearl", "10");
			CloseQuestHeader("SharpPearl");
			pchar.questTemp.Sharp = "seekSharp"; //����� �������� � ��������
			pchar.questTemp.Sharp.brothelChance = rand(10);
			NextDiag.TempNode = "DeckSharp_overBad";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			if (pchar.location != "Deck_Near_Ship")
			{
				LAi_SetActorTypeNoGroup(npchar);
				LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 15.0);
			}
		break;

		case "DeckSharp_over":
			dialog.text = "�� ��� ��������, "+ GetSexPhrase("��������","�������") +". �� ����� ����� � �� �� ���� ������ �������.";
			link.l1 = "��, ������� ����.";
			link.l1.go = "exit";
		break;
		case "DeckSharp_overBad":
			dialog.text = "���������� ���...";
			link.l1 = "�� ��...";
			link.l1.go = "exit";
		break;
		case "DeckSharp_noWork":
			dialog.text = "����� �� ���� ������, "+ GetSexPhrase("�������","��������") +". ��� ������� ��� ����. ������ �������� ����� �� ��������� ��������...";
			link.l1 = "��, � ������������, ��������!";
			link.l1.go = "exit";
			CloseQuestHeader("SharpPearl");
		break;
		//������� ����, ������ �������� � ������ �� �����
		case "CitySharp":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "�-�-�, ������� " + pchar.lastname + "! ������ ���� �����������.";
				link.l1 = "����������, � ��� ���"+ GetSexPhrase("","�") +" �������! �������� ���� ��������, �� � ���� ������ �������...";
				link.l1.go = "CitySharp_1";
				npchar.quest.meeting = true;
			}
			else
			{
				dialog.text = "��, ���� � ���� � ���� ������?! ��� �� "+ GetSexPhrase("������� " + pchar.lastname + ", ��� �������� � ��������������","" + pchar.name + ", ��� ��������� � ���������������! �� ���������, ��� �������") +"!";
				link.l1 = "��, ����������, ��� �"+ GetSexPhrase(" ����������� ��������",". ������� �� ����������") +".";
				link.l1.go = "CitySharp_2";
			}
		break;

		case "CitySharp_1":
			dialog.text = "���, ���� ������ �� ����� ��������?";
			link.l1 = "���������, � ��� ������"+ GetSexPhrase("��","���") +" ���������� �� ��������� ��������, � �� � ���� ���� ���������� ����������.";
			link.l1.go = "DeckSharp_2";
		break;
		case "CitySharp_2":
			dialog.text = ""+ GetSexPhrase("��, �������, ��� ���� ������! �� ���, ������, �������... ������� � �����, ����� �� ������. �� ����� �������������, ������� ��� �����? � ���� ��� ����� ����� - �����������","�-�-�, " + pchar.name + ", ����� � ���� ����, � ���� ������ �� ��������") +"!";
			link.l1 = "������, "+ GetSexPhrase("����","����������") +", ��� ������ �� �� "+ GetSexPhrase("�����","������") +", ������. � �� ���� � ����.";
			link.l1.go = "CitySharp_3";
			//���������� ����������, ���� ���� ������ �� �������
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("��������","��������") +", � ������ �����! ����� ���� ������ �� ����. ��� ����...";
				link.l1 = "�� �����, �������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //����� �������� � ��������
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "CitySharp_3":
			dialog.text = "��-�-�, "+ GetSexPhrase("��� �� ���������","��� ��� ������") +"... � ��� �� ����?";
			link.l1 = "�� ���, �����"+ GetSexPhrase("","�") +" �������� ������ ������� �� �������...";
			link.l1.go = "NewDeckSharp_2";
		break;
		//������� ���� � �������
		case "BrothelSharp":
			dialog.text = ""+ GetSexPhrase("�-�-�, " + pchar.lastname + ", �������!! ������ �� ���� ������, ��� ��� ������!!!","�-�-�, " + pchar.name + ", ��� ��, ���������? �� ���, ������ � ����� ���� ����� ������ ������ ������ � ����...") +"";
			link.l1 = ""+ GetSexPhrase("���, ��������, ������ �� ����, �����.","�� ����� ����, ����������, ������ �� ������ �����..") +". � � ���� �� ����";
			link.l1.go = "BrothelSharp_1";
			//���������� ����������, ���� ���� ������ �� �������
			if (pchar.questTemp.piratesLine == "PearlQ4_toTerks")
			{
				dialog.text = ""+ GetSexPhrase("��������","��������") +", � ������ �����! ����� ���� ������ �� ����. ��� ����...";
				link.l1 = "�� �����, �������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "DeckSharp_overBad";
				pchar.questTemp.Sharp = "seekSharp"; //����� �������� � ��������
				pchar.questTemp.Sharp.brothelChance = rand(10);
				DeleteAttribute(pchar, "questTemp.Sharp.PearlAreal");
				AddQuestRecord("SharpPearl", "13");
				CloseQuestHeader("SharpPearl");
			}
		break;
		case "BrothelSharp_1":
			dialog.text = ""+ GetSexPhrase("������...","��, ������ ���� ������, " + pchar.name + ". �� �����, ��� ��� � ����?") +"";
			link.l1 = "���� ����� ���������� � ������ �������, �������� �� �������.";
			link.l1.go = "NewDeckSharp_2";
		break;
		//������ ������. � ����� ���-���� ���� �����
		case "SharpSeekSpy_Emi":
			dialog.text = "������, ��� ������������!!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog");
		break;
		case "SharpSeekSpy_fri":
			dialog.text = "�-�-�, �� ��� �� ������� " + pchar.lastname + "! ��� �� �� ������ ��� ����� �������...";
			link.l1 = "���, �������! � � ���� ����, ��������?";
			link.l1.go = "SharpSeekSpy_fri_1";
		break;
		case "SharpSeekSpy_fri_1":
			dialog.text = "��, ��� �������... ��, ����� ����, ���� �� �����������, �� � ��� �������� ������, ����� �� �������� ��� ���� '����������'.";
			link.l1 = "��! ��� �� �� ������� �����?! ������, � ������"+ GetSexPhrase("","�") +" ����� �� ������.";
			link.l1.go = "SharpSeekSpy_fri_2";
		break;
		case "SharpSeekSpy_fri_2":
			dialog.text = "�� ������� ������ ����������, �������.";
			link.l1 = "���������, ��������, ��� ���� ����� ��������� ������, ��� �� ���� ������� ����� �� ������� ������. ������ �����"+ GetSexPhrase("","�") +".";
			link.l1.go = "SharpSeekSpy_fri_3";
		break;
		case "SharpSeekSpy_fri_3":
			dialog.text = "�������, �� ��� ����� ���� ����� � �����...";
			link.l1 = "���, � ��� � "+ GetSexPhrase("������� � �����","����������") +". � ���� �� ��� ����� ����� ����� ����� ���-��� �� ��������� ���������...";
			link.l1.go = "SharpSeekSpy_fri_4";
		break;
		case "SharpSeekSpy_fri_4":
			dialog.text = "� ��� �� ���� �������� ����?";
			link.l1 = "�-�-�...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog_2");
		break;
		case "SharpSeekSpy_Emi_1":
			dialog.text = "� ���, �� ����? �������, ���-�� �� ��������!\n������, ���� ������ "+ GetSexPhrase("���","��") +". �� ����...";
			link.l1 = "��, ����������...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SharpSeekSpy_caveDialog_3");
		break;


		//���������� ��������
		case "OffMushketer":
			dialog.text = "����������� "+ GetSexPhrase("�����","���������� ������") +" � ���� ����. ��� �� ������ �����?";
			link.l1 = "�������������. ���� ����� ������� " + GetFullName(pchar) + ".";
			link.l1.go = "OffM_1";
		break;
		case "OffM_1":
			dialog.text = "��� ����������, �������. ��� � ���� ��� ������?";
			link.l1 = "�� ���, ����� ���������... � �� �� ���� ������� �������. ��� �� ������ ��������?";
			link.l1.go = "OffM_2";
		break;
		case "OffM_2":
			dialog.text = "��� ���, ������.";
			link.l1 = "�������. � ��� ���� � �����?";
			link.l1.go = "OffM_4";
		break;
		case "OffM_4":
			dialog.text = "����������. � ��� ������ �������� � �����!";
			link.l1 = "��, ����� ���� ��� �����. �� ������� ����� ������� �������� �� ��� � �������?";
			link.l1.go = "OffM_5";
		break;
		case "OffM_5":
			dialog.text = "������� �� �����������, �� �������� ����������.";
			link.l1 = "�������, � ������? ���� �� ������, �������...";
			link.l1.go = "OffM_6";
		break;
		case "OffM_6":
			dialog.text = "��� ���� � ����������� ������. �� ���� ����� � ���� ������!";
			link.l1 = "������� ��� ���. � ��� �� �� ������� � �����?";
			link.l1.go = "OffM_7";
		break;
		case "OffM_7":
			dialog.text = "���������, ��� � ���� ����� �������� ���������� ��������, ����� ����. ��� ������, ������������������� �������� �����, ����������� �������� �������. � �����, ��������� ������������ ���������, ������ �������.\n"+
				"� ��� � � ����� ������ ����������, ��� ������� ������ �� �������.";
			link.l1 = "� ��� ���� ����-�������� ������?";
			link.l1.go = "OffM_8";
		break;
		case "OffM_8":
			dialog.text = "��-�, ���� ���������� ������... ����� � ���� ���� �� ������� �����, �� ��� ������ ������. � ����� ������� �� ��� �����, � �������� ���, ������ �� ������ ���� �����������. �� ���� �� ������� ����������� �� ���� � ��������!..";
			link.l1 = "������ ���, ��� ��������� ���������. �� ���� �� �������� ����.";
			link.l1.go = "OffM_9";
		break;
		case "OffM_9":
			dialog.text = "���, �� ��� ����� ���������! � ��� ��� �� �����!..";
			link.l1 = "��, ����� ������ ��������, ��������...";
			link.l1.go = "OffM_10";
		break;
		case "OffM_10":
			dialog.text = "��������?.. ��, ����������, ���� �� ������� ��� ������������ ��������, �� � ����� � ��� � �������. ������.";
			link.l1 = "�� ��� ��, � ��� �����"+ GetSexPhrase("","�") +". � ��� �������� ��� �������, ����� ��� ����?";
			link.l1.go = "OffM_11";
		break;
		case "OffM_11":
			dialog.text = "���� ��� ��� ���� ��� �����, � ��� ��� � �����. ��� ���� �� ������ - � �� �����, ����� ��������� � ������ �� ������. ������� � �����-�� ������ ������, �� ��� ��� ����� - ��� �� ��������.";
			link.l1 = "�-��, ��������... �� ��� ��, ��� ���������, ����� ������. ���� ��� ��� �������� ���������, �� ����������� ������� ��� ����.";
			link.l1.go = "OffM_12";
		break;
		case "OffM_12":
			dialog.text = "������� ���. ���� ����� � �����������.";
			link.l1 = "������.";
			link.l1.go = "exit";
		                sld = characterFromId("Torus");
		                sld.dialog.currentnode = "Mushket";
			pchar.questTemp.mushkett2x2 = true;
			AddQuestRecord("SeekDoubleMushket", "1");
			NextDiag.TempNode = "OffM_result";	
		break;

		case "OffM_result":
			dialog.text = "�� ����� ��� ��������?";
			if (CheckCharacterItem(pchar, "mushkett2x2"))
			{
				link.l1 = "��...? ���...?, �������, ���"+ GetSexPhrase("��","��") +". ��, ��� ����, ������������� ������, ���� �� ������?";
				link.l1.go = "OffM_result_1";
			}
			else
			{
				link.l1 = "��� ���. �� � ��������� ����.";
				link.l1.go = "exit";
			}
		break;

		case "OffM_result_1":
			dialog.text = "��, �����!";
			link.l1 = "��� ������ ��������� ������. ������ � ��� ���������� ������ �������� ����� ���� ��������.";
			link.l1.go = "mushket1";
			link.l2 = "��� ������ ���� ��������. ������ � ��� ���������� ������ �������� ����� ���� ��������.";
			link.l2.go = "mushkett2x2";
		break;

		case "mushket1":
			dialog.text = "��...";
			link.l1 = "���-�� �� ���?";
			link.l1.go = "exit_hire1";
			PlaySound("interface\important_item.wav");
			TakeItemFromCharacter(pchar, "mushket1");
			Npchar.quest.OfficerPrice = sti(pchar.rank)*300;
		break;

		case "mushkett2x2":
			dialog.text = "��, ��� ��! �������, ���!";
	link.l1 = "����������, ��� ������ ����������� �� ������?";
			link.l1.go = "OffM_result_2";
			PlaySound("interface\important_item.wav");
			TakeItemFromCharacter(pchar, "mushkett2x2");
			Npchar.quest.OfficerPrice = sti(pchar.rank)*300;
		break;

		case "exit_hire1":
			dialog.text = "���, � ����� ������� � ������� �� ����, ��� ��� ����� ���� � �� ������� ��������� ������ �� �����.";
			link.l1 = "���� ���, ���� �� ����������.";
			link.l1.go = "exit_hire2";
		break;

		case "exit_hire2":
			AddQuestRecord("SeekDoubleMushket", "3_1");
			CloseQuestHeader("SeekDoubleMushket");
			dialog.text = "����� ��������.";
			link.l1 = "� ���� �� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "OffM_result_2":
			dialog.text = "��� ����� ��������. � �����. ������ ������� ������� ������ ����� ��������. �� ���� ������ ������ � ���� �������� " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " � �����.";
			link.l1 = "� ��� �� �������, ��� ��� ��������?";
			link.l1.go = "OffM_trade";
			link.l1 = "��, ������, � ������"+ GetSexPhrase("��","��") +".";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_trade":
			dialog.text = "���, � ���� ������� ������.";
			link.l1 = "��, ������, � ������"+ GetSexPhrase("��","��") +".";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_Ok":
			Npchar.quest.OfficerPrice.add = sti(pchar.rank)*1000;
			dialog.text = "������. �� ��� ��� �� ���. � ������ ��������������� �������, ��� �������. ������������ ��� ������, ��� � ���� �������� �����. �����, ��� " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " ���� �������.";
			link.l1 = "����?!!";
			link.l1.go = "OffM_Ok_1";
		break;
		case "OffM_Ok_1":
			dialog.text = "����! � ����� �����... � �����, �������.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "��� � ���� ����� �����.";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "��� ����� ������ ��� ����.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "������, � ������"+ GetSexPhrase("��","��") +".";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
		case "OffM_noMoney":
			dialog.text = "������, ���������, ��� ������������. �����.";
			link.l1 = "�������...";
			link.l1.go = "exit";
		break;
		case "OffM_Ok_3":
			dialog.text = "���, ������ ������ ������ ����! � ����� ��� ������� ����� � �������.";
			link.l1 = "�������. ����� ���������� � �������.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			AddQuestRecord("SeekDoubleMushket", "3");
			CloseQuestHeader("SeekDoubleMushket");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "MusketeerEnglish_2";
			npchar.model.animation = "mushketer";
			npchar.MusketerDistance = 5;
			npchar.greeting = "Gr_questOfficer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;

			GiveItem2Character(npchar, "mushkett2x2");
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			GiveItem2Character(npchar, "spyglass1");
			EquipCharacterByItem(npchar, "spyglass1");
			GiveItem2Character(npchar, "cirass6");
			EquipCharacterByItem(npchar, "cirass6");
			AddItems(chr, "grapeshot", 	100);
			AddItems(chr, "gunpowder", 	100);
			LAi_SetCharacterUseBullet(npchar, "grapeshot");  
			TakeNItems(npchar, "potion2", 5);

			DialogExit();
		break;
		case "OffM_TWO":
			dialog.text = "�� ���, ��� ��� � ��� ���� � ���������? �������, ��� � ���� " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " ��������������� ������� � " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " ������������ ���������.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "���, �� ������ ����...";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "��� ����� ������ ��� ����.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "������, � ������"+ GetSexPhrase("��","��") +".";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
	}
}


void GetPerlShore()
{	
	switch (rand(4))
	{
		case 0:
			pchar.questTemp.Sharp.PearlAreal = "Mein";
			pchar.questTemp.Sharp.PearlAreal.Island = "Beliz";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore_ship2";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_8";
			pchar.questTemp.Sharp.PearlAreal.add = ". ��� ����� � �������";
			break;
		case 1:
			pchar.questTemp.Sharp.PearlAreal = "Mein";
			pchar.questTemp.Sharp.PearlAreal.Island = "Cumana";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore18";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_8";
			pchar.questTemp.Sharp.PearlAreal.add = ". ��� ����� � �������";
			break;
		case 2:
			pchar.questTemp.Sharp.PearlAreal = "Dominica";
			pchar.questTemp.Sharp.PearlAreal.Island = "Dominica";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore26";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_3";
			break;
		case 3:
			pchar.questTemp.Sharp.PearlAreal = "Terks";
			pchar.questTemp.Sharp.PearlAreal.Island = "Terks";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore56";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_1";
			break;
		case 4:
			pchar.questTemp.Sharp.PearlAreal = "Caiman";
			pchar.questTemp.Sharp.PearlAreal.Island = "Caiman";
			pchar.questTemp.Sharp.PearlAreal.Shore = "Shore17";
			pchar.questTemp.Sharp.PearlAreal.locator = "Quest_ship_1";
			break;
	}
	pchar.questTemp.Sharp.PearlAreal.terms = rand(5) + 5; //�����
	pchar.questTemp.Sharp.PearlAreal.qtyShips = rand(6) + 6; //���-�� ������ ������
	pchar.questTemp.Sharp.PearlAreal.SmallPearlQty = 0; //��� ��������� ��������
	pchar.questTemp.Sharp.PearlAreal.BigPearlQty = 0;
}

void SetSeekCapCitizenParam(ref npchar, int iNation)
{
	//������� �����
	int Rank = sti(pchar.rank) + 5;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("SeekCitizCap_" + npchar.index, "", "man", "man", Rank, iNation, -1, true));
	switch (npchar.quest.SeekCap)
	{
		case "manSlave": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "CitizCap";
			sld.DeckDialogNode = "CitizCap_inDeck";
		break;
		case "manRapeWife": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "RapeWifeCap";
			sld.DeckDialogNode = "RapeWifeCap_inDeck";
		break;
		case "manFriend": 
			SetCaptanModelByEncType(sld, "trade");
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			sld.dialog.currentnode = "FriendCap";
			sld.DeckDialogNode = "FriendCap_inDeck";
		break;
		case "womanHasband": 
			SetCaptanModelByEncType(sld, "trade");
			SetShipToFantom(sld, "trade", true);
			sld.Ship.Mode = "trade";
			sld.dialog.currentnode = "HasbandCap";
			sld.DeckDialogNode = "HasbandCap_inDeck";
		break;
		case "womanRevenge": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "RevengeCap";
			sld.DeckDialogNode = "RevengeCap_inDeck";
		break;
		case "womanPirates": 
			SetCaptanModelByEncType(sld, "pirate");
			SetShipToFantom(sld, "pirate", true);
			sld.Ship.Mode = "pirate";
			sld.dialog.currentnode = "PiratesCap";
			sld.DeckDialogNode = "PiratesCap_inDeck";
		break;
	}
	sld.dialog.filename = "Quest\ForAll_dialog.c";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	sld.DontRansackCaptain = true; //�� ���������
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	//� ������� ������ ����
	string sGroup = "SeekCapShip_" + sld.index;
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	//���������� ������ � ��������� �������� � ����
	npchar.quest.SeekCap.capId = sld.id //Id �������� ����
	npchar.quest.SeekCap.capName = GetFullName(sld); //��� �������� ����
	npchar.quest.SeekCap.shipName = sld.Ship.name; //��� ����������� �������
	npchar.quest.SeekCap.shipTapeName = RealShips[sti(sld.Ship.Type)].BaseName; //�������� ����������� �������
	npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1) * 1000) + (sti(pchar.rank)*500); //��������������
	npchar.quest.gem = GenQuestCitizen_GenerateGem(); //�������
	sld.quest = "InMap"; //������ ���� �������� ����
	sld.quest.SeekCap = npchar.quest.SeekCap; //������� ���� ���� ������
	sld.quest.nation = iNation; //�������� ������� ����� ����
	sld.city = SelectAnyColony(npchar.city); //��������� �������, ������ ���-��� ������
	sld.quest.targetCity = SelectAnyColony2(npchar.city, sld.city); //��������� �������, ���� �� ������
	Log_TestInfo("������������� ��� " + sld.id + " ����� ��: " + sld.city + " � ���������� �: " + sld.quest.targetCity);
	sld.quest.cribCity = npchar.city; //�����, ��� ��������� ������������
	//==> �� �����
	sld.mapEnc.type = "trade";
	//����� ���� ��������� �� �����
	switch (npchar.quest.SeekCap)
	{
		case "manSlave":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manRapeWife":	 sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "manFriend":	 sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanHasband": sld.mapEnc.worldMapShip = "ranger";	  break;
		case "womanRevenge": sld.mapEnc.worldMapShip = "Galleon_red"; break;
		case "womanPirates": sld.mapEnc.worldMapShip = "Galleon_red"; break;
	}
	sld.mapEnc.Name = XI_ConvertString(npchar.quest.SeekCap.shipTapeName) + " '" + npchar.quest.SeekCap.shipName + "'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+5; //���� ������� ���� � �������
	Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, daysQty);
	//���������� �� ������ ����
	string sTemp = "SCQ_" + sld.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = sld.id;
	pchar.quest.(sTemp).function = "SCQ_seekCapIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	//���������� �� ������ ������������
	sTemp = "SCQ_" + npchar.index;
	pchar.quest.(sTemp).win_condition.l1 = "NPC_Death";
	pchar.quest.(sTemp).win_condition.l1.character = npchar.id;
	pchar.quest.(sTemp).function = "SCQ_CitizenIsDeath";
	pchar.quest.(sTemp).CapId = sld.id;
	pchar.quest.(sTemp).CitizenId = npchar.id;
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "citizen"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = npchar.id; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = sld.quest.cribCity + "SCQ_" + npchar.quest.SeekCap; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "SCQ_" + npchar.quest.SeekCap; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

string GenQuestCitizen_GenerateGem() // �����
{
	string itemID;
	switch(rand(5))
	{
		case 0:
			itemID = "jewelry1";	
		break;
		case 1:
			itemID = "jewelry2"; 
		break;
		case 2:
			itemID = "jewelry3"; 
		break;
		case 3:
			itemID = "jewelry4"; 
		break;
		case 4:
			itemID = "jewelry5"; 
		break;
		case 5:
			itemID = "jewelry17"; 
		break;
	}
	return itemID;
}