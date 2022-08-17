void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "��� ��� ����?";
			link.l1 = "������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////----------------------------------------- ������������ -----------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//--> �����
		case "TakeShoreCap":
    		dialog.text = "�� �� �������! �� ������"+ GetSexPhrase("","�") +"?";
    		link.l1 = "�� ������"+ GetSexPhrase("","�") +" ����?";
    		link.l1.go = "Node_1";
		break;
		
		case "Node_1":
			dialog.text = "��-��! ����� ����� ���! �� ���� �� ���� ����"+ GetSexPhrase("��","���") +"?";
			link.l1 = "�� ��... � � � �����, ������ �� �������� ������ �������, �� ��� ��� �����... �������!!";
			link.l1.go = "Node_2";
		break;
		
 		case "Node_2":
			dialog.text = "��, ������"+ GetSexPhrase("��","��") +", ��� �������. � � �� ��������, � ������ ������! � ���� ��� �� �������"+ GetSexPhrase("","�") +", ���� ��� ����� �� ���� �� ����������.";
			link.l1 = "��� ������ ��? ������ ������� � �����, ���� ���� ������ �� ��� - � ����� ������ �� ������.";
			link.l1.go = "Node_3";
		break;
		
 		case "Node_3":
			dialog.text = "����������. ���� ������ ������� � ������� ����������� ��������. ����� �� ���� ������ �������-����������, � ��� �� ����������� �� ��������. �� � � �� ����������, ����� �� �� ��� �� �����"+ GetSexPhrase("","�") +".";
			link.l1 = "��������, ������ ��������������!";
			link.l1.go = "Node_4";
		break;
		
 		case "Node_4":
 		    pchar.questTemp.Slavetrader = "TakeShoreCap_end"; //��� ��������� ������ ��� �������� � ������������
            AddQuestRecord("Slavetrader", "13");
			AddQuestUserData("Slavetrader", "sShipName", pchar.questTemp.Slavetrader.ShipName);
            pchar.quest.Slavetrader_DieHard.over = "yes";
			pchar.quest.Slavetrader_AfterBattle.over = "yes";
			pchar.quest.Slavetrader_ShoreShipsOver.over = "yes";
            Island_SetReloadEnableGlobal(pchar.questTemp.Slavetrader.Island, true);
		    LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			
		break;
		
		case "Slave_arest":
			dialog.text = "" + GetFullName(pchar) + ", ������ ������ �� ����������! ���������� ������ ������ � �������� �� ����!";
			link.l1 = "��� ��� ������, ������? �� ����� ���������?";
			link.l1.go = "Slave_arest_1";
		break;
		
		case "Slave_arest_1":
			dialog.text = "�� �������������� �������, �������! ���� ������� ������� ��������. � �� �����, ��� �� �������, � �� ����������� ������� " + NationNameGenitive(sti(npchar.nation)) + ", �� ������ ��������� �� ���� ���!";
			link.l1 = "�� ��� ���... �� ��� ������ ��� ������, �� ��� ��? ���������, ���!";
			link.l1.go = "Slave_arest_2";
		break;
		
		case "Slave_arest_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		//--> ����� � ����
		case "Rat_bandos":
			dialog.text = "��! ��� �� ��� �����"+ GetSexPhrase("","�") +"? �����, ���� ������!";
    		link.l1 = "���-�� �� �� ����� �������, ��������. �� ����� �� �������� ��� ����� �������, �?";
    		link.l1.go = "Node_rat_1";
		break;
			
		case "Node_rat_1":
			dialog.text = "��� ����� �������� ��������! ���� ��� ���, ��� �� �����"+ GetSexPhrase("","�") +" ������ - ��������!";
			link.l1 = "������� ���, ��� �� �����. ������ �� ������ ��� � ���������...";
			link.l1.go = "Node_rat_2";
		break;
		
 		case "Node_rat_2":
			dialog.text = "�-���! �������! ����! ������, �� ���, �� ������!";
			link.l1 = "�� �� ���!";
			link.l1.go = "Node_rat_3";
		break;
		
		case "Node_rat_3":
            LAi_SetPlayerType(pchar);
            LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "EnemyFight");
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Slavetrader_findTortugaRat1");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Rat_lover":
			dialog.text = "��! �� �������� ����!";
    		link.l1 = "��� ������� �������? �������, ��������� �����, ��� ���������� �� ������ ��������!";
    		link.l1.go = "Rat_lover_1";
		break;
			
		case "Rat_lover_1":
			dialog.text = "���, ���, � ��� �����! �� ��������� � ���� � ������, ������, �� ���� �������.";
    		link.l1 = "����� �������? � ����� ��� ��� �������, � ��� ����. �� ��� ���, �������, ���� �����...";
    		link.l1.go = "Rat_lover_2";
		break;
			
		case "Rat_lover_2":
			dialog.text = "� �� ���, �������! �� �������, ��� �������������� � ���������� ��������, �� ������� ����, � �� ������ �������� �� ������... �� ���! �� �������� ����!";
    		link.l1 = "�����, ������ �� �� �����. ���� ���� � �� ��������. � ������, �������� ���� � ���� ��������. ����, ����� � ���� �� - �� ������ ����, ����-�����.";
    		link.l1.go = "Rat_lover_3";
			pchar.quest.Slavetrader_RatAttack.win_condition.l1 = "location";
            pchar.quest.Slavetrader_RatAttack.win_condition.l1.location = "Tortuga";//���������� � �������
            pchar.quest.Slavetrader_RatAttack.function = "Slavetrader_RatCorvette";//�������� �������
			SetFunctionTimerCondition("Slavetrader_RatCorvetteOver", 0, 0, 1, false);
		break;
			
		case "Rat_lover_3":
 		    LAi_SetPlayerType(pchar);
            SetCharacterRemovable(npchar, false);
            LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Slavetrader", "21_9");
            DialogExit();
		break;
		
		//--> ������ ����
		case "Slave_woman":
			dialog.text = "��������! ��������! �� �������!";
    		link.l1 = "��� ���? � ��, ��� ���� ���� �� ������� � �����! ��� ������� �������� �������� - ��������� �� �����!";
    		link.l1.go = "exit";
			AddDialogExitQuestFunction("Slavetrader_Slavewoman");
		break;
	//<--������������
			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////----------------------------------------- ���������� -----------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//--> Jason ------------------------ ������������ ����������� -------------------------------------------	
		int iCGood;
		case "Contraoffer_patrol":
			chrDisableReloadToLocation = false;
			iCGood = sti(pchar.GenQuest.Contraoffer.Trader.Goods);
			pchar.GenQuest.Contraoffer.Trader.PatrolSumm = sti(pchar.GenQuest.Contraoffer.Trader.Summ)/3;
			dialog.text = "���-���... ��� �� ��� � ��������, ���������. ����� �� �� � �����, ��� ������ " + GetGoodsNameAlt(iCGood)+ " �������� ������ � ����� ������� ��������? ��� ��� ��� ��������?";
			link.l1 = "������, ����� ��������? � ������� �� ���� �����, ������� �����. ��� ������������� ������� �������, ��������?";
			link.l1.go = "Contraoffer_patrol_1";
			link.l2 = "����� ������ " + GetGoodsNameAlt(iCGood)+ "? � �� ���� " + GetGoodsNameAlt(iCGood)+ ", ������! � ���� ������ ��� ��� ��������� ������... � �� ����� ������ ��������� ������. �����, �� � ���� ������� ���� ���������� �� ���� ������? � " + GetGoodsNameAlt(iCGood)+ " � ��� ���...";
			link.l2.go = "Contraoffer_patrol_pay1";
		break;
		
		case "Contraoffer_patrol_1":
			if (GetSummonSkillFromName(pchar, SKILL_SNEAK) > drand(120))
			{
				dialog.text = "�� ���� �� � �����? ��... ������, �� �� �����. �� ��� �� �����, ��� ���, � ������ ���������� �� �������� �����. � �� ���� ������������ ���, �� ����������� ���-���� ��������. ��, � ��� ������ � ������ - ��� ����� ������ �� ������ ���������� ������.";
				link.l1 = "� ����� ������ ������?";
				link.l1.go = "Contraoffer_patrol_pay2";
			}
			else
			{
				dialog.text = "�� ������ ������, �������! ��� �������� ���� � �����. � ������� ��� ����� �� �����������, � ����� ����� �����������.";
				link.l1 = "������, � �� �������� � ���������. � ����� ����... � ������ ������� � ���� �����. ��, ��������, ��� �������� ������� ����� ��� ����.";
				link.l1.go = "Contraoffer_patrol_fight";
				link.l2 = "��� ������ �� ��������, ��� �����������. �� � ������ �� ����!";
				link.l2.go = "Contraoffer_patrol_jail";
			}
		break;
		
		case "Contraoffer_patrol_pay1":
			iCGood = sti(pchar.GenQuest.Contraoffer.Trader.Goods);
			if (GetSummonSkillFromName(pchar, SKILL_FORTUNE) > drand(120))
			{
				dialog.text = "��� ���... �� ��� ��, ������� ��������� �� ���� ������... ��� ���������� ����� � " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.Summ)) + ". ��������� � ��� ������ �� �������������, � ������������� �������, �� � �� ����� ������� " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.PatrolSumm)) + ". ��� � ���. ������� �� � �� ������� ��������� ������.";
				link.l1 = "�������, ������. ��� ��� ��������� ������... � " + GetGoodsNameAlt(iCGood)+ " ��� ���, ��-��, � �� �������.";
				link.l1.go = "Contraoffer_patrol_complete1";
				link.l2 = "���! � ��� ����������� ��������, ������. �� ������� �� ������� ��������� '������� ����� ��� �����'? �������, ������� ����� ����������� ��� � ����� ����������� � ���� ������.";
				link.l2.go = "Contraoffer_patrol_fight";
			}
			else
			{
				dialog.text = "�� �����������, �������? ��� ��������� ���������� ��� ������? �� ����������! ����� ���!";
				link.l1 = "��, ��� �� ������ �� �������� �� ������, ����� ��������� �� ������ ���� �����!";
				link.l1.go = "Contraoffer_patrol_fight";
				link.l2 = "��� ������ �� �������� �������, ��� �����������. �� � �� �� ����...";
				link.l2.go = "Contraoffer_patrol_jail";
			}
		break;
		
		case "Contraoffer_patrol_complete1":
			dialog.text = "��, �������������, �� �����... ����� �����, � ��� � ������ ������ �� ����. �� ��������, �������, ��������, � �� ��������� � ����� ���������.";
			link.l1 = "����� �������, ������. �� �������� ����� �������.";
			link.l1.go = "Contraoffer_patrol_complete";
		break;
		
		case "Contraoffer_patrol_pay2":
			dialog.text = "" + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.PatrolSumm)) + ". � ������ ������, ��� � ������� ������.";
			link.l1 = "�������, ������. � ������ �� ����... ���, � ����� �������� �����.";
			link.l1.go = "Contraoffer_patrol_complete2";
			link.l2 = "������� ���, ������, ��� �� ������� �� ����. �� ������ ����� ����������� ���� �����. �����, ��� ��� ������� ������ ��������, ���� � ������� �� �� ������ �����������.";
			link.l2.go = "Contraoffer_patrol_fight";
		break;
		
		case "Contraoffer_patrol_complete2":
			dialog.text = "������. ������ ������ ����. � ������ ��� ���������, ������� ����������� �� ������� ����������� � ����� �������, ����� �������� ���������� ����������� ��������. ��������, ������ ��� ����� �������� ������ ���������� ������ - ��-�� ����� ��� � �����, ��� ����� ���������, � ��� ������.";
			link.l1 = "����� �������, ������.";
			link.l1.go = "Contraoffer_patrol_complete";
		break;
		
		case "Contraoffer_patrol_complete":
			AddMoneyToCharacter(pchar, -sti(pchar.GenQuest.Contraoffer.Trader.PatrolSumm));
			AddQuestRecord("Contraoffer", "6");
			CloseQuestHeader("Contraoffer");
			LAi_CharacterDisableDialog(npchar);
			DialogExit();
		break;
		
		case "Contraoffer_patrol_fight":
			AddQuestRecord("Contraoffer", "7");
			CloseQuestHeader("Contraoffer");
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), -5);
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Contraoffer_patrol_jail":
			dialog.text = "��������� ����������, ��� �� �����, � ���� �� �����. �������� �� ����!";
			link.l1 = "...";
			link.l1.go = "Contraoffer_patrol_jail_exit";
		break;
		
		case "Contraoffer_patrol_jail_exit":
			GoToPrison(pchar.GenQuest.Contraoffer.Trader.City, sti(pchar.GenQuest.Contraoffer.Trader.Summ), 7);
			DialogExit();
			AddQuestRecord("Contraoffer", "8");
			CloseQuestHeader("Contraoffer");
			pchar.GenQuest.Contraoffer.Jail = "true";
		break;
	//<-- ������������ �����������	
		
	//Jason --> ----------------------------------- ����������� ��� --------------------------------------------
		case "Device_poorman":
			dialog.text = "������ ����. �� ���-�� ������?";
			link.l1 = "��, ��������. �������, ��� �� � ���� ���, ��� ��� �����. ���� ��� �� ����� �� ������� ����� "+pchar.GenQuest.Device.Shipyarder.Type+"? ��� ����� ����� � ����, ��� ��� �� ���������.";
			link.l1.go = "Device_poorman_1";
		break;
		
		case "Device_poorman_1":
			switch (sti(pchar.GenQuest.Device.Shipyarder.Chance3))
			{
				case 0://��������
				if (sti(pchar.GenQuest.Device.Shipyarder.Chance2) != 1)
				{
					dialog.text = "���������, ��������! ��, � ������ �� ����� ��� �������� �������. �� � ���� �� ���� �� ������ ������� - ������ ��� ��������� �� �����. � �� � ��������. ��������, ������, � ������ ����� ����� ������... ��� �� � ������� �� ������� �� �����!";
					link.l1 = "��� ��������... �� ��-�� ��� ��� �� �����. ��� ����� ����� "+pchar.GenQuest.Device.Shipyarder.Type+". ������, ��� ��������?";
					link.l1.go = "Device_poorman_0_1";
				}
				else //������ ������
				{
					dialog.text = "���������, ��������! ��, � ������ �� ����� ��� �������� �������. �� � ���� �� ���� �� ������ ������� - ������ ��� ��������� �� �����. � ����� �� ���. ���, ������, ������ �� �������� ���� � �� �������� ��������!";
					link.l1 = "�����, ����, �������. �� ��� �� �����, ��� ����� ���� ����������. ���� ����� ��� ����, � ����� ������ ����������� �� ��� ������ ������!";
					link.l1.go = "Device_poorman_0_2";
				}
				break;
				case 1://���������, ������ ��� �������
					dialog.text = "� ��� �� ��������? ��� �� "+pchar.GenQuest.Device.Shipyarder.Type+"? �� �������!";
					link.l1 = "��� ������ ����� ����, ����� �������, � ��� � ������! ����� ����� �������-���������!";
					link.l1.go = "Device_poorman_1_1";
				break;
				case 2://���������
					dialog.text = "��... ��� �� "+pchar.GenQuest.Device.Shipyarder.Type+"? �... � ��� ��� ������ �����?";
					link.l1 = "�� ������������ �������� � �� ������� ���� ����, ��� ����� ������. � ������ �� �������� ��������� �����...";
					link.l1.go = "Device_poorman_2_1";
				break;
			}
		break;
		
		case "Device_poorman_0_1"://���� �� ������
			dialog.text = "�� ����� �� ���������� ��������, � ������ � �������. ���������, ������������ ��������! ���� ��� ��� ��� ����� - ��������� ��, ��� ��� ��� � ��������, � ������.";
			link.l1 = "���� ���� �� ��������� ���� ������ ����� ��������� � ��������, �� �����, ������ ����� ���� ������ ��������, ��� "+pchar.GenQuest.Device.Shipyarder.Type+". ��� �����. �� ������: ���� ������ - �� ��� ����� �������!";
			link.l1.go = "exit";
			AddQuestRecord("Device", "3");
			string sCity = pchar.GenQuest.Device.Shipyarder.City + "_ExitTown";
			ref rItm = ItemsFromID("Tool");
			rItm.shown = true;
			rItm.startLocation = sCity;
			rItm.startLocator = "item" + (rand(14)+1);
			Log_TestInfo("������ � �������� " + rItm.startLocator);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Device_poorman_0_2"://�������� ������
			dialog.text = "���, ���������. �������, ������������ ��������!";
			link.l1 = "���, ����� ���, ��-��. ��, ��������! �����. �� ������ � ��������� ���, ��� ������� �����������.";
			link.l1.go = "exit";
			TakeNItems(pchar, "Tool", 1);
			Log_Info("�� �������� ���������� ����������");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Device", "4");
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Device_poorman_1_1":
			pchar.GenQuest.Device.Shipyarder.Poorsumm = 1000+drand(1000);
			dialog.text = "����������, �� �������� �� �� ���� ����������� ���� ������? ���� �� ����, �� ��� ��� ����, � � �� �� ����! � �������� ��� �� ������ ��� ��� �� �������! ���� ������ �� �������� - ��������� ��� " + FindRussianMoneyString(sti(pchar.GenQuest.Device.Shipyarder.Poorsumm)) + ".";
			link.l1 = "��... ������. � ������� ����. ��� ������, � ����� ���� "+pchar.GenQuest.Device.Shipyarder.Type+"!";
			link.l1.go = "Device_poorman_1_2";
			link.l2 = "��� ���? �� ��� ��, ������ �������, �������, � ���� �������? � ��, ����� ���� "+pchar.GenQuest.Device.Shipyarder.Type+", ����, �� �� ������ ������ - � �� ��� ������ ������ �� ����� � ����������, ��� ��� ���������� �� ����� ����.";
			link.l2.go = "Device_poorman_1_3";
			link.l3 = "�� � ��������! ��� ���, ��������: ��� �� ���������� ������ ��� "+pchar.GenQuest.Device.Shipyarder.Type+", ��� � ������� ���� ����� ������ � ������ ���������� � ������ �����!";
			link.l3.go = "Device_poorman_1_4";
		break;
		
		case "Device_poorman_1_2":
			dialog.text = "�������� ������, �������! � �����, �� ��� � ������� �� ���������, ��-��... ���������.";
			link.l1 = "������ ������ ������, �������! �� �����, ��� � ���� �������, ������ ��� ������ ��������� �������. �� � ��� ����� ���� ��� ������ �� ����� �� ������. ��, ����������!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(pchar.GenQuest.Device.Shipyarder.Poorsumm));
			TakeNItems(pchar, "Tool", 1);
			Log_Info("�� �������� ���������� ����������");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Device", "5");
			AddQuestUserData("Device", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Device.Shipyarder.Poorsumm)));
			AddQuestUserData("Device", "sName", pchar.GenQuest.Device.Shipyarder.Type);
			npchar.lifeday = 0;
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Device_poorman_1_3":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance2) == 0)//���� �� � ������
			{
				dialog.text = "���! �� ���� ������! �... � ����� ��� ���� ��������� ����������. ���, ���������!";
				link.l1 = "���-�� �����! � ������ ������ �����������. ��� ����� ������ ���� ���� - �� ��������, ��� ���� ������ �������.";
				link.l1.go = "exit_device";
			}
			else//������� �������
			{
				dialog.text = "�������, ����� ������? ��� ������ �� � ����. ��, � ��� �� ��� ��������������, �� ��� �� �������� ������ �����, ��� �������� ��� ��������... ������ ����� ������.";
				link.l1 = "�� ������ ��� ��������, �����?";
				link.l1.go = "Device_poorman_fight";
			}
		break;
		
		case "Device_poorman_1_4":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance2) == 0)//���� �� � ������
			{
				dialog.text = "��! �������! �������!";
				link.l1 = "����, ������!";
			link.l1.go = "exit";
				sld = characterFromId("Device_poorman");
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", -1);
				sld.lifeday = 0;
				AddQuestRecord("Device", "7");
				CloseQuestHeader("Device");
				DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
			}
			else//������� �������
			{
				dialog.text = "��, �������, ��� �� ��� ���������, ��� ���� ��������!";
				link.l1 = "�� ������ ��� ��������, �����?";
				link.l1.go = "Device_poorman_fight";
			}
		break;
		
		case "Device_poorman_2_1":
			dialog.text = "����� ��� ����� �����? ���������, ����������� ��������!";
			link.l1 = "������ ���: ��� �� ��� ������ ����������� ������� ��, ��� ����� � �����, ��� � ������ ���� � �����������. ��� �� ��� ����� � ���� ����� ������������, ������, ����� ������� ���������� ����� ������� �������. � �����, ��� � �������� �����. ��� ��� �������.";
			link.l1.go = "Device_poorman_2_2";
			link.l2 = "���� ���� ���� ����������, �������, ��� � �������� ���� �� �����!";
			link.l2.go = "Device_poorman_2_3";
		break;
		
		case "Device_poorman_2_2":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) < 2)//��� �� ��� �������
			{
				dialog.text = "��, ����� ������� ���� � �����������, ���� ������� �������...";
				link.l1 = "����, ������!";
				link.l1.go = "exit";
				AddQuestRecord("Device", "7");
				sld = characterFromId("Device_poorman");
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", -1);
				sld.lifeday = 0;
				CloseQuestHeader("Device");
				DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
			}
			else
			{
				dialog.text = "�� ���� � �����������! � ��� �����. ���, �������, ��, �������, ��� �����. ��� ����� �� ������ �� �������...";
				link.l1 = "��, ������� �� ����, ����������, � ���� � ����� �������... �����, ����� ���� ���������� � ����������!";
				link.l1.go = "exit_device";
			}
		break;
		
		case "Device_poorman_2_3"://��������
			dialog.text = "��! �� �������� ����, � ��� �����! ���, ���������!";
			link.l1 = "��-�� ��! ������, � ���� � ���� ��� ���� ��� ����� � ���� ������ - ���� ����������. ����������!";
			link.l1.go = "exit_device";
		break;
		
		case "exit_device":
			npchar.lifeday = 0;
			TakeNItems(pchar, "Tool", 1);
			Log_Info("�� �������� ���������� ����������");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Device", "6");
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Device_poorman_fight":
			chrDisableReloadToLocation = true;
			sld = characterFromId("Device_poorman");
			TakeNItems(sld, "Tool", 1);
			sld.SaveItemsForDead = true; // ��������� �� ����� ����
            sld.DontClearDead = true; // �� ������� ���� ����� 200�
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			AddQuestRecord("Device", "8");
			AddComplexSelfExpToScill(30, 30, 30, 50);
		break;
	//<-- ����������� ���
//-------------------------------------------�������� ��������� 2 ������------------------------------------	
		case "PostGopHunters":
			dialog.text = "����, ��������! ��� ����� ����, ������� ������ � ����. ����� �� ��� �� �����, � ������ ����� �������.";
			link.l1 = "����� ����� ����? �� �������...";
			link.l1.go = "PostGopHunters_1";
			link.l2 = "������ ��������� ������� ���������... ��, ���������, �������!";
			link.l2.go = "PostHunters_fight";
		break;
		
		case "PostGopHunters_1":
			dialog.text = "�� ������������ ��������! ���� ���� �����, � ���������� ���. � �����... �� ������ ��� � ������ �����!";
			link.l1 = "���� �� �� ���� �������... ���������, �������, � ���� ��� ������.";
			link.l1.go = "PostGopHunters_2";
			link.l2 = "��������, ����� ���������!";
			link.l2.go = "PostHunters_fight";
		break;
		
		case "PostGopHunters_2":
			dialog.text = "������� � �����������, ��������... �������, ��� �� ���� ���������� ������. �����-�� ��� ����� ��� �� ����, ��-��! � ��� �������� ���... ��, �����.";
			link.l1 = "...";
			link.l1.go = "exit_gophunter";
		break;
		
		case "PostProfHunters":
			dialog.text = "��������, " + GetAddress_Form(NPChar) + ", �� �������. � ��� � ��� ����.";
			link.l1 = "����� ����? ��, �������, � ���� �� �������.";
			link.l1.go = "PostProfHunters_1";
		break;
		
		case "PostProfHunters_1":
			dialog.text = "��������, �������, ��� ��� �������������. ������ �� ����. �� ������ �������� � �������� ���������� "+pchar.questTemp.WPU.Current.Add+" "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+". �� ��������� ��������, ��� ��� ���������� �������� - �� ��� ��������� ���� ����� ����� ����� ���������.";
			link.l1 = "������ ����. � ���?";
			link.l1.go = "PostProfHunters_2";
		break;
		
		case "PostProfHunters_2":
			dialog.text = "������ �� �������� ��� ���� ����� � ���� �������������� ���������� ����������. � �� ��������� �������������, ���: �� �������� �������� ��� ������, ���� ���� ��� ����� ����������� ������� � ��������� ����������\n��� �� ���������, � ������ ����� �� ������ ������. ��� ��� ������� ��������� � ����������� ��������.";
			link.l1 = "���� �� �� ���� �������... ���������, ���������, � ���� ��� ������.";
			link.l1.go = "PostProfHunters_3";
			link.l2 = "��� �� �������� ���� - � �� ����� ������ � ���� ������! ������ �� �� ��������.";
			link.l2.go = "PostProfHunters_4";
		break;
		
		case "PostProfHunters_3":
			dialog.text = "� ���, ��� �� ������� �������� �������, �������. �� ��������� ���� ������� ���������, �������� �� ��� ����. �� � ������ ��������� �����������.";
			link.l1 = "...";
			link.l1.go = "exit_profhunter";
		break;
		
		case "PostProfHunters_4":
			dialog.text = "��, �� ��� ������ ���� ������...";
			link.l1 = "...";
			link.l1.go = "PostHunters_fight";
			TraderHunterOnMap();//���� ������� - ��������� �� ��������
		break;
		
		case "PostHunters_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_gophunter":
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			for (i=1; i<=4; i++)
			{
				sld = characterFromId("PostHunters"+i);	
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 5.0);
			}
			AddQuestRecord("Postcureer", "11");
			DialogExit();
		break;
		
		case "exit_profhunter":
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("PostHunters"+i);	
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 5.0);
			}
			AddQuestRecord("Postcureer", "12");
			pchar.questTemp.WPU.Postcureer.fail = "true";
			DialogExit();
		break;
		
		case "PostAgent":
			bDisableFastReload = true; 
			dialog.text = "��������, " + GetAddress_Form(NPChar) + ", �� �������. � ���� � ��� ����.";
			link.l1 = "����� ����? �������� �������, � �����.";
			link.l1.go = "PostAgent_1";
		break;
		
		case "PostAgent_1":
			dialog.text = "��, ��� �� ������� - ��� ��������. � ��� ��� ��������, ��� �� ������ �������� � �������� ���������� "+pchar.questTemp.WPU.Current.Add+" "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+". ��� �� ���� ������� � � ���� � ���� ����������.";
			link.l1 = "� ��� � ���� ��� ������� ��������� � ����������� ������ ��� ����. ��� �� ������� ��������� ��� ������? ���� �� ������ �����������...";
			link.l1.go = "PostAgent_2";
		break;
		
		case "PostAgent_2":
			dialog.text = "�������, �������! � ���, ����� �� ���������� ��������� � ������� ������? � ������� �������, � ����������� �������� " + NationNameGenitive(sti(pchar.questTemp.WPU.Postcureer.EnemyNation)) + ". � ���� ���������� ��� ������ �������� ������ - �� ������ �� �����. ������� ������� � ������� �������, � � ����� �� ����, � ��������� ���������� ��� �������. ��� �� ������ ����� �������.";
			link.l1 = "������������� �� ���... � �� ������� ����� ������� ��� � ����, ������! ����������!";
			link.l1.go = "PostAgent_getout";
			link.l2 = "��... ��, ������� ���������, ��� �� ������� ��� ����������. �� ���� � �� ��������� ������� �� ����. ��������, � ����� ���.";
			link.l2.go = "PostAgent_3";
		break;
		
		case "PostAgent_getout":
			dialog.text = "�� ������� � ����� �������, �������! � ��������� ��� ����������, �� ��������� � �������. � ��... �� ��� ��������� �� ����.";
			link.l1 = "����������!!";
			link.l1.go = "PostAgent_getout_exit";
		break;
	
		case "PostAgent_3":
			dialog.text = "������������! �������� �� ����.";
			link.l1 = "...";
			link.l1.go = "exit";
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			NextDiag.TempNode = "PostAgent_inTavern";
			sld = characterFromId("PostAgent");	
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload4_back", pchar.questTemp.WPU.Postcureer.StartCity +"_tavern_upstairs", "goto", "goto1", "PostAgent_inTavern_Room", -1);
		break;
		
		case "PostAgent_getout_exit":
			bDisableFastReload = false; 
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			sld = characterFromId("PostAgent");	
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10);
			pchar.questTemp.WPU.Postcureer.AgentIslandID = GetCharacterCurrentIslandId(pchar);
			pchar.quest.Postcureer_Hunter.win_condition.l1 = "Location";
			pchar.quest.Postcureer_Hunter.win_condition.l1.location = pchar.questTemp.WPU.Postcureer.AgentIslandID;
			pchar.quest.Postcureer_Hunter.function = "PostcureerAgent_ShipAttack";
			AddQuestRecord("Postcureer", "13");
			DialogExit();
		break;
		
		case "PostAgent_inTavern":
			dialog.text = "���, ��� ������ ����� �������� ����������.";
			link.l1 = "��, � ��� �� ��� ��������� ����������?";
			link.l1.go = "PostAgent_inTavern_1";
		break;
		
		case "PostAgent_inTavern_1":
			dialog.text = "��� � ��� ������, ���� ���� � �������, ������� �� �������� � �������� ����������. ��� ����� ����� ���� ����� � ��� ����� � ���� ���\n�������� ��������� � ���, �� ��� �������� �������� � �������� ���� �������. ����� �� � ��� �� ������, � �� ����������� ����� ����� ��������� � ��� ������� �������.";
			link.l1 = "���������... �� ����� ���������. �� �� ������� ����� �����, �� ������ ������!";
			link.l1.go = "PostAgent_inTavern_2";
		break;
		
		case "PostAgent_inTavern_2":
			dialog.text = "� ������ ����� �������. ������� ������ ������������� ��������, �� �� ������������ - � ����������� ��, ����� ���� ��� ����� �����. � ���� ���� �������� ������� �����, � ������, �������, ����. ����� � �� �������, ��� ����� ���������.";
			link.l1 = "� ��� ���� ���������� ����� ��������� ���������� " +XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+ "?";
			link.l1.go = "PostAgent_inTavern_3";
		break;
		
		case "PostAgent_inTavern_3":
			pchar.questTemp.WPU.Postcureer.AgentMoney = sti(pchar.rank)*3500;
			dialog.text = "�������, � ���� ��� �������? ��, ����, ��� �� �������, � ����� � ������� �����? � ��������� ��� "+ FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.AgentMoney))+" �� ����������� ���������� ��� ������, ���������� - �� ������ ���. ��, ��� �� ������ ������� ��� ���� �����?";
			link.l1 = "�������. ������ ������� ��� ���������!";
			link.l1.go = "PostAgent_inTavern_4";
			link.l2 = "������ ���, � �� ���� � ���� ������������. �� �������� ��� ��� ���.";
			link.l2.go = "PostAgent_inTavern_getout";
		break;
		
		case "PostAgent_inTavern_4":
			dialog.text = "�� �����������. ����� ���� �� ��������. ���������, ���������. ��� ��� ������ � ���� �������� ���.";
			link.l1 = "������.";
			link.l1.go = "PostAgent_inTavern_5";
		break;
		
		case "PostAgent_inTavern_5":
			NextDiag.currentnode = "PostAgent_inTavern_6";
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			pchar.questTemp.WPU.Postcureer.AgentChance = drand(4);//����, ��� �������� ����� - 20%
			DialogExit();
			AddDialogExitQuest("PostAgent_inTavern_Room_end");
		break;
		
		case "PostAgent_inTavern_getout":
			dialog.text = "��... �� ������. ��, ��� �� ����� �������, �������, ��� ������ �������� ����� ��� ����� ����� � ������� ����� ���������. ���������� ����������, ��� ������� � ������ �� ����, ��� ����������� �����.";
			link.l1 = "��� ���� ����� ����������, �����!";
			link.l1.go = "PostAgent_inTavern_fight";
		break;
		
		case "PostAgent_inTavern_6":
			dialog.text = "�� ��� � ���. ��� � � ������� - ��� ������� � ������ ����. �������� ��� ����� � ��������� "+ FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.AgentMoney))+". ��, � ������ ��� ���� ����������. ����� �������, �������, ���, ��� �� ����� ����� ����.";
			link.l1 = "��������...";
			link.l1.go = "PostAgent_inTavern_7";
		break;
		
		case "PostAgent_inTavern_7":
			DialogExit();
			bDisableFastReload = false;
			chrDisableReloadToLocation = false; 
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Postcureer.AgentMoney));
			GiveItem2Character(pchar, pchar.questTemp.WPU.Current.Item);
			sld = characterFromID("PostAgent");        
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 2);
			AddQuestRecord("Postcureer", "15");
			AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.AgentMoney)));
		break;
		
		case "PostAgent_inTavern_fight":
			bDisableFastReload = false;
			sld = characterFromID("PostAgent"); 
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			AddQuestRecord("Postcureer", "16");
		break;
	//<-- �������� ��������� 2 ������
		
	// --> --------------------------------- ������ 2 ������� --------------------------------------------------
		case "DisasterCap":
			dialog.text = "������������! ��� �� � ��� ��� ������, ��� � ���!";
			link.l1 = "������ ����. ��, �������, �� ������� �� � ������� ��� ��������� '"+pchar.questTemp.WPU.Escort.ShipName+"'?";
			link.l1.go = "DisasterCap_1";
		break;
		
		case "DisasterCap_1":
			dialog.text = "�! � ������ ��� �������� ��� '"+pchar.questTemp.WPU.Escort.ShipName+"'? ��, � ������� ����� �������. ������, ������ �������... ����� �������� �������� ������.";
			link.l1 = "�, �� ��� � � ����� ���... ��������� ������������� - " + GetFullName(pchar) + ". � ������ ���� �� ������� ���������� ��������� ���������� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+". �� ������� ��������� � ������������ ������ �������� � �������� ���� �� ������ ������ �������.";
			link.l1.go = "DisasterCap_2";
		break;
		
		case "DisasterCap_2":
			dialog.text = "��� �� - ������� ������������ ����������?";
			link.l1 = "��, ���-�� ����� ����. � ��� ������ ������� ������ ������ ������� ��� �������������� ������������� ��� ������. � ���������, � ������� �� �������, � ��������������, �� ��� ��� �������� ...�-�?";
			link.l1.go = "DisasterCap_3";
		break;
		
		case "DisasterCap_3":
			dialog.text = "��, ��������, � �� ������������. ��� ��� - " + GetFullName(npchar) + ". ��� ��� �������� ��������� �������������� ����, ��� �� ������ ����? ����� ����, ��� ���������� ����� �������� ���� ����� � ���������, ��� ������ ����� ����� �� ������ - ������� ��� �����������\n� ����� ������ ��� ��������� �� ���� �������� �� ���� �����. ����� �� �����������, � ������� ���������� � �������� ������. �������� ������� �� ����... ���� �������� ����� ��������� ������� ���� ������� ������ ������� ������������� ������. ��������� ����� ���, �� ���. �� ������ ���� ������� �� �� ����...";
			link.l1 = "������� ��� ��������������, ������� " + GetFullName(npchar) + ". ��� ������������� ����� ����.";
			link.l1.go = "DisasterCap_4";
		break;
		
		case "DisasterCap_4":
			dialog.text = "�������... ��, � ��, ��������, ������� �� ������ ������ � ����� ������. ������� ������� � ����� ����. � �� ������� ����� �������, �������! ������ ��� � ����� ��������� ��������� ������� ������������ ������� - �� ��� ������ �������� �� ����� �� ��� �����. �� ����� �� ������ ��� ������������ �� ������ �� - �� �����, � ��� ����� ���� ���� ��������\n����� ����, ��������� ����� ������ � � ���� - ��� �������� ��� ��� ��� ��������� �� ��������� ��������, ������������ � ��������� ������� - �� ���� ����������� ���� �����. �� �� ��������� ����� ������, �������, �� ���� ����?";
			link.l1 = "���, �� ��������.";
			link.l1.go = "DisasterCap_5";
		break;
		
		case "DisasterCap_5":
			dialog.text = "� ����� ����. ��� ���� �� ���, ��, ������� ������ ��� �����, �� ���� ���������� ������. ��, ��� �����, ����� �� �������� ���������� ������, � ������ ����� �� ���� ����, � ����� �������.";
			link.l1 = "����. ��, ������ ���� ������, ��� �� ����� ������.";
			link.l1.go = "DisasterCap_6";
		break;
		
		case "DisasterCap_6":
			dialog.text = "� ��� ��� ������, �������? �������� ��� � ���� �� ����, � �������� �� ����� �������� �����!";
			link.l1 = "����������. ��� ��� �� ������� ������ ������� - ���� �� ������� ���� ������ ��� �������. ������������ ������, � ������� �������� �� ����� ������ - � ����� ����������!";
			link.l1.go = "DisasterCap_7";
		break;
		
		case "DisasterCap_7":
			PlaySound("people fight\rifle_fire1.wav");
			PlaySound("people fight\player_man_shoot_01.wav");
			dialog.text = "�������, �������! ��� �� ����������� ����� �������. ��������... ��� ��� �� ����? �-���, ����� ��� ����������� �������! �������! � ���!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("DisasterShipCrew_IndianAttack");
		break;
		
		case "DisasterCap_8":
			dialog.text = "��, ��������... ������, �������, � ��� �������: ��� ����� - ����� ��. ��� ��� ������ ����� ��������� ������! ����� ��������� ������� ������ ����, ��� ���� ����� ��������� - � ��� ��� ����� ������ �������.";
			link.l1 = "�� ��, �� �����. ��������� ����, ��� ������� � ����� � ������ �� �������! � �����������, ����� ������ ������� ����������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("DisasterShipCrew_onBoard");
			AddQuestRecord("Escort", "38");
			AddQuestUserData("Escort", "sIsland", XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID));
			AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
			AddQuestUserData("Escort", "sShore", XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID.Shore));
		break;
	// <-- ������ 2 �������
		
	//Jason --> -------------------------- ���������� ���������� ------------------------------------------------
		case "Badboy":
			dialog.text = "��... ���� ���� �� ���� ����? ����������, � �� ����� � ����� �������������.";
			link.l1 = "�� - "+pchar.GenQuest.Badboy.Brothel.Name+"?";
			link.l1.go = "Badboy_1";
		break;
		
		case "Badboy_1":
			dialog.text = "��, ��� �. � ����� ���� ����?";
			link.l1 = "� ����� �������. ���� ������� ��� ������� ���-���� � ���� ������. ������ ������� �������. �, ����� ������ �� ����, � �������, ������. � �����, ��� ���� ����� ������ � ������� ������� �� �����, ��� ������, ��� �� ��������� ����� �������������. ����?";
			link.l1.go = "Badboy_2";
		break;
		
		case "Badboy_2":
			switch (sti(pchar.GenQuest.Badboy.Brothel.Type))
			{
				case 0://��� ����������, ��� ����� �������� - �� ����������
					if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < 30)
					{
						dialog.text = "����! ��... �� ������ ��� ��������, �������? �� � ���� ������ ������� �� ��� ����� � �������, ��� �� �������!";
						link.l1 = "��, �������, �������!";
						link.l1.go = "Badboy_fight_1";
						NextDiag.currentnode = "Badboy_after_fight";
					}
					else
					{
						dialog.text = "���? �� ����� �������? �� ���� ������� �������. �� �������, ������� � ������� ���� ���. � ��� �� ������... ������-������, �������� � ������ ��� �� �����. �� ��������? ��� �����.";
						link.l1 = "�������, �� ������� ����� ����� ������ � ������������, ������� ��������, ���� �� �������� ������ ��������. ���� ��� � ����. � ������ - ������.";
						link.l1.go = "exit";
						pchar.GenQuest.Badboy.Complete = "true";
						LAi_CharacterDisableDialog(npchar);
						npchar.lifeday = 0;
					}
				break;
				case 1://����� �� �������
					dialog.text = "�� ������ ������, ������! � �������, ��� ��� �� ������ ��� �������� ��� �������� �� ���� ������. � ������� ��� �� �����! �����, ����� �������� �� � ����� �� ����... � ����� �����. ������� �� ���������� �������� ��� ��� �������� - ���������� ����� ��� ����!";
					link.l1 = "�������� ����! �� ������� ����, ��� �� ���� ����� ������������, ���� ���� ���� ����.";
					link.l1.go = "Badboy_duel";
					NextDiag.currentnode = "Badboy_duel_1";
					break;
				case 2://�������� �� ������ �������
					dialog.text = "���? �� ����� �������? �� ���� ������� �������. �� �������, ������� � ������� ���� ���. � ��� �� ������... ������-������, �������� � ������ ��� �� �����. �� ��������? ��� �����.";
					link.l1 = "�������, �� ������� ����� ����� ������ � ������������, ������� ��������, ���� �� �������� ������ ��������. ���� ��� � ����. � ������ - ������.";
					link.l1.go = "exit_continue";
					pchar.GenQuest.Badboy.Continue = "true";
					NextDiag.currentnode = "Badboy_friends";
				break;
			}
		break;
		
		case "Badboy_fight_1":
			chrDisableReloadToLocation = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			sld = characterFromId("Badboy");
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.Badboy.Brothel.City + "_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			LAi_SetCheckMinHP(npchar, 10.0, true, "Badboy_capture");
			DialogExit();
		break;
		
		case "Badboy_after_fight":
			dialog.text = "����������! ����! � ������! ������!";
			link.l1 = "���, ��� ��� �� ������ ������!";
			link.l1.go = "Badboy_after_fight_1";
		break;
		
		case "Badboy_after_fight_1":
			dialog.text = "������, ������! � ������ ���, ��� �� �������! ������ � �� �������� � ���� ������� �������!";
			link.l1 = "����� ���� ������ �������� �����, �������� ����. �������, ��� �������� ���� ������ �� ��� ���������� �����. � ���� ���� � ���� ������ ���� ����, ���� �����.";
			link.l1.go = "Badboy_exit";
			link.l2 = "��� �����. ������ �� ��� �� ���������, ������ ��� ���� ���������� ���������� ����� � ������.";
			link.l2.go = "Badboy_killed";
			pchar.GenQuest.Badboy.Complete = "true";
		break;
		
		case "Badboy_exit":
			LAi_SetPlayerType(pchar);
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
			DialogExit();
		break;
		
		case "Badboy_killed":
		DialogExit();
		LAi_SetImmortal(npchar, false);
		LAi_ActorAnimation(pchar, "shot", "Badboy_killed_end", 2.2);
		break;
		
		case "Badboy_duel":
			chrDisableReloadToLocation = true;//������� �������
			LAi_LocationDisableOfficersGen(pchar.GenQuest.Badboy.Brothel.City + "_ExitTown", true);//�������� �� �������
			locations[FindLocation(pchar.GenQuest.Badboy.Brothel.City + "_ExitTown")].DisableEncounters = true; //��������� �������
			pchar.quest.BadboyDuelTimer.win_condition.l1 = "Timer";
			pchar.quest.BadboyDuelTimer.win_condition.l1.date.hour  = sti(GetTime() + 2);
			pchar.quest.BadboyDuelTimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.BadboyDuelTimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.BadboyDuelTimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.BadboyDuelTimer.function = "Badboy_duelstart";
			sld = characterFromId("Badboy");
			LAi_SetActorType(sld);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.Badboy.Brothel.City + "_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "OpenTheDoors", -1);
			TakeNItems(sld, "jewelry5", rand(10)); 
			TakeNItems(sld, "jewelry3", rand(10)); 
			TakeNItems(sld, "jewelry1", rand(10)); 
			sld.money = 24560;
			sld.SaveItemsForDead = true; // ��������� �� ����� ����
			sld.DontClearDead = true; // �� ������� ���� ����� 200�
			LAi_RemoveLoginTime(sld); //������� ����� ������
			SetFunctionTimerCondition("Badboy_duelOver", 0, 0, 1, false);
			DialogExit();
		break;
		
		case "Badboy_duel_1":
			dialog.text = "��, ���� ��������� ���� � ��, ������! �������� ����������, ������ �������...";
			link.l1 = "������ ����, ������ ����, ��������!";
			link.l1.go = "Badboy_duel_2";
		break;
		
		case "Badboy_duel_2":
			chrDisableReloadToLocation = true;
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "Badboy_die");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_continue":
			sld = characterFromID("Badboy");        
			LAi_RemoveLoginTime(sld); // patch-6
			LAi_SetActorType(sld);
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.Badboy.Brothel.City + "_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", -1);
			DialogExit();
		break;		
		
		case "Badboy_friends":
			dialog.text = "� ��� � ���� ������ ��������! ������� ���, ������, ��� � ���� ������ ��������� ������!";
			link.l1 = "�� ��, �������! ��, � ���� ������������. ������ �� � ��� ��� ����� ����������� � ��!";
			link.l1.go = "Badboy_friends_fight";
		break;
		
		case "Badboy_friends_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			DeleteAttribute(pchar, "GenQuest.Badboy");
		break;
	//Jason <-- ���������� ����������
		
	//Jason --> ------------------------------- ����� ��� ������� ----------------------------------------------
		case "Sunplace_Store":
			pchar.quest.SunplaceContinue_Over.over = "yes";
			dialog.text = "������������. ��� ��� �����?";
			link.l1 = "�� ���� "+pchar.GenQuest.Sunplace.Trader.Enemyname+"? �� �� ��������, ��-��. ��� ����� ���� ������.";
			link.l1.go = "Sunplace_Store_1";
			link.l2 = "��... �� ���... ���, ������. �, ��������, ������. ����� ���� �������� �� ������������.";
			link.l2.go = "Sunplace_Store_exit";
		break;
		
		case "Sunplace_Store_1":
			dialog.text = "��� �� �������� �����, ������? ������� �����������, ��� �...";
			link.l1 = "� ��� �� ��������, ��������� �������? �� ������� ������ �������� ��������, � �� ����� ���������. ��� ��� ������, �� ���������, ��� ������� � �� �������.";
			link.l1.go = "Sunplace_Store_3";
		break;
		
		case "Sunplace_Store_3":
			dialog.text = "�� ���... �� ���, ������! ��������! �� ������, ���-������! �������!";
			link.l1 = "����� �� �� ��������� - �������, � ��� ����� ��...";
			link.l1.go = "Sunplace_Store_fight";
		break;
		
		case "Sunplace_Store_exit":
			sld = CharacterFromID("SunplaceTrader");
			sld.lifeday = 0;
			AddQuestRecord("Sunplace", "9");
			CloseQuestHeader("Sunplace");
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Sunplace.Trader");
			NextDiag.currentnode = "Sunplace_Store_repeat";
		break;
		
		case "Sunplace_Store_repeat":
			dialog.text = "��� ����� ��? ����� �������, ��� �� �� ���� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
		break;
		
		case "Sunplace_Store_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			sld = CharacterFromID("SunplaceTrader");
			LAi_SetImmortal(sld, false);
			LAi_SetActorType(sld);
			LAi_ActorAfraid(sld, Pchar, true);
			sld = characterFromId(pchar.GenQuest.Sunplace.Trader.CityT + "_trader");
			LAi_group_Attack(sld, Pchar);
			pchar.quest.Kill_SunplaceTrader.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Kill_SunplaceTrader.win_condition.l1.location = pchar.location;
			pchar.quest.Kill_SunplaceTrader.function = "Kill_SunplaceTrader";
		break;
	// <-- ����� ��� �������
		
	//------------------------------------- ������� ����-------------------------------------------------------
		case "LigaHunters":
			dialog.text = "";
			link.l1 = "�?! ���? ��� �� ����� �������, ���� ������? ��� ��� ���� �������?";
			link.l1.go = "LigaHunters_1";
		break;
		
		case "LigaHunters_1":
			dialog.text = "���� ����� ���� �����, �������...";
			link.l1 = "���? �-���, ������!!";
			link.l1.go = "LigaHunters_2";
		break;
		
		case "LigaHunters_2":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("LigaHunter_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "LigaHunters_Dead");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
	// <-- ������� ����
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		case "Che_nado":
			Dialog.Text = "�������� �� ����, ���? ����� � ��� ������?";
			Link.l1 = "� ���� �������� ���� ��������� �� �����, ������.";
			Link.l1.go = "Che_nado2";
		break;		
		
		case "Che_nado2":
			if (rand(1) == 0)
			{
				Dialog.Text = LinkRandPhrase("��... �� �� ������ ��� ������� ����, ��� � ������ �� �����?","��, �� ��� �  ����� ������, �� ��� �� ����� ������ ���������!","� ��� ��� ������� �� ������ ����������, ����� ������ ������ ����, ���� � ����� �������?");
				Link.l1 = "���������, �������, �� � �� �� ����. � � ���, ��� �� ��������� ��������� ���������� � ������� �� �������!";
				Link.l1.go = "Che_nado3";
			}	
			else	
			{
				Dialog.Text = LinkRandPhrase("� ��� ��� � ����� �������������? �� �������� ��� ��������� - ��� � ������� ��� ���������.","���������? � ��� ��� ������ ����� ����������� �����, � �� �������? ���� ��� �������. ������ ��� �����.","��! �������, �� ��������. � ������ ���� ���� ��� ��� ����. � �� ��� �� ����, ����� �� � �������!");
				Link.l2 = "������ ��������. ���� �������� ������� ���� � ������, ������... ������ ���������� � ������, ��������.";
				Link.l2.go = "Gop_stope";
			}	
		break;
		
		case "Che_nado3":
			if (rand(1) == 0)
			{
				Dialog.Text = LinkRandPhrase("���, �� �� �� ����������� �����, � ����������� � �������� �� ��������. �� ������� ������, �������! � ������� ��� ��� �� ������ ����!","�������, ��, �����, ������� � ����� ������, �����? �� ����� ���� �� ������ ��� �� ���������. �� ������� ������, � �� ������� ������������ �����. ������ ����������, ������, ���������� - ��� �� � ���.","���, �� �� �� ����������� �����. � ������ ������� �� ������� ����� � ��� ��� ���������, ������ � ���� ��� � �������� �����! �� ��� ����� � ���� ������� �������, ����� ����� ���������� �����-�� ��� ���������� ��������.");
				Link.l1 = "���� ��� �� �������. ���� ��  ������ ���� ��� ������, ���� ������������� �� ��� ����.";
				Link.l1.go = "Che_nado4";
			}	
			else	
			{
				Dialog.Text = RandPhraseSimple("�������, ���. ����������! ������� �����, ������ ������ �� ����������!","��, ���. �� ���, ����������. �� �� ��������� �������, �������, �� ��� �� �� �� ����������� �����, � ������� ������, � ����������� � �������� ������ �� ��������.");
				Link.l2 = "�������. �������, ������ � ����!";
				Link.l2.go = "Che_nado_ispravilsya";
				Link.l3 = "������� ����� � ���� �� �����, � ���������... ���� ���� ��������� �������� �������!";
				Link.l3.go = "Gop_stope";
			}	
		break;		
		
		case "Che_nado_ispravilsya":
			Dialog.Text = RandPhraseSimple("����, ���! ���� ����� ���� ��� �������.","�� ����������, ������ ������ �� ���������!");
			Link.l2 = "����� �������. �� ��������, ������.";
			Link.l2.go = "Odumalsya_matros";
		break;		
		
		case "Che_nado4":
			if ((GetSummonSkillFromName(pchar, SKILL_FORTUNE) + (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP))) > 80)
			{
				Dialog.Text = RandPhraseSimple("��, �����... ������ ���� ����� ����������������, ���.","��� ���������, �������.");
				Link.l2 = "�� ��������, ������.";
				Link.l2.go = "Odumalsya_matros";
			}
			else
			{
				Dialog.Text = RandPhraseSimple("��, ����� � ���! ��� �� ��� �����-�� ����� �������!","�� ���� ������ �� ����� ����� �����-�� ���������?");
				Link.l2 = "���� ���� �� ������� � ����� ��������, �����!";
				Link.l2.go = "Gop_stope";	
			}
		break;
		
		case "Gop_stope":
			DialogExit();
			chrDisableReloadToLocation = false;
	SetTimerCondition("NETRazborkiNaKorable", 0, 0, 0, false);
			NextDiag.CurrentNode = "Zaplatka_matrosu";
			DeleteAttribute(pchar, "GenQuest.Boismatrosom");
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			for (i=1; i==1; i++)
			{
				sld = characterFromId("Bunt_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "Minus_1_v_komandu_sm_kvestReaktion");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;		

		case "Odumalsya_matros":
			DialogExit();
			NextDiag.CurrentNode = "Zaplatka_matrosu";
			LAi_group_SetCheck("EnemyFight", "Minus_0_v_komandu_sm_kvestReaktion");
			chrDisableReloadToLocation = false;
			DeleteAttribute(pchar, "GenQuest.Boismatrosom");
			LAi_SetFightMode(Pchar, false);
			ChangeOfficersLoyality("good_all", 15);
			AddCrewMorale(pchar, 25);
	SetTimerCondition("NETRazborkiNaKorable", 0, 0, 0, false);
			AddCharacterExpToSkill(PChar, "Leadership", 700); // ������� ���������� 
			ChangeCharacterComplexReputation(pchar, "authority", 20);
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			DoQuestReloadToLocation("", "rld", "loc1", "");
		break;
		
		case "Zaplatka_matrosu":
			Dialog.Text = "��������, �������.";
			Link.l1 = "������, ��� �� ��� �������?";
			Link.l1.go = "Zaplatka_matrosu2";
		break;

		case "Zaplatka_matrosu2":
			Dialog.Text = "��� ���, ���������� � ����� � ���.";
			Link.l1 = "������. ������, ����� ��� �� ����� ������ ����� ��������.";
			Link.l1.go = "exit";
		break;		
		
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
			dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "��������� �� ���������, "+ GetSexPhrase("��������","�������") +", ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� "+ GetSexPhrase("�������","������ ���") +" ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = LinkRandPhrase("������.", "�����.", "�� ���������, ��� ������...");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
			if (npchar.id == "Device_poorman") NextDiag.TempNode = "Device_poorman";
		break;
	}
}
