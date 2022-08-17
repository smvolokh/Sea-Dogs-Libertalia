// ���� ��� ���� - ������ � �����, ������� ������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobInRoom")
			{
				dialog.text = "����! �-��... �� ��� �����? ��� ���� ������ ������? � ���� ���������, �� ���, �����? �-��!";
				link.l1 = "� ���� ��������� �����, �� ���. ������� �� �����. � �� ����.";
				link.l1.go = "HollJacob_inRoom";
				break;
			}
			dialog.text = "����� ���. �������� �� ���� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "HollJacob_inRoom":
			dialog.text = "���? � �� ������ ��� �����? ������ ����� �� ������� �����? � ���� ���������, �������!";
			link.l1 = "���� ����� ����� �� �����. ��� ����� ���� �������.";
			link.l1.go = "HollJacob_inRoom_1";			
		break;
		
		case "HollJacob_inRoom_1":
			dialog.text = "����... ��� ��� ��������! ���... ������! �� - ��������� ���������� ������! ������! ���������, ������... ��, ��� ������ � �� �����!";
			link.l1 = "��, ��� �� ��� �������...";
			link.l1.go = "HollJacob_inRoom_fight";			
		break;
		
		case "HollJacob_inRoom_fight":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.questTemp.HWIC.Holl.JacobCity+"_tavern_upstairs")], false);
			pchar.quest.JacobOnMainOver.over = "yes";//����� ������
			chrDisableReloadToLocation = true;
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "HollJacob_dead");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "JacobBerg_abordage":
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				dialog.text = "����! ���������! ��� � ��� ��� ����� ���������! �� ���� �� ��������, �����?";
				link.l1 = "�����, �����. �����, �� ��� ��� ����� �� ���� ������� �� �������� ���������� ��������. �� � �������� ��������� ��������� ������� � ���������, � �� � �������. ���� ���������� ��������, �������!";
				link.l1.go = "JacobBerg_abordage_1";
			}
			else
			{
				dialog.text = "�� ��� � �����������, �������. � �� ������ �����... ��������� ��� �� ��������� ����� ��������� ���������.";
				link.l1 = "� ���� ��������� ���������, ����. ������ �� ����� �� ������.";
				link.l1.go = "JacobBerg_abordage_3";
			}
		break;
		
		case "JacobBerg_abordage_1":
			dialog.text = "������, ��� ���. ���� ������� ��������� ��� �������, � ������ ����� �� ����������. �� ������ ��� ���� ������ � ���� �� ������, � ����� ��������� ���� � ��! ��� ���� ������ ������� ���� �����!";
			link.l1 = "��� �� ��� �������. � � ������, ��� ���� ����� ��� �� ����� � �����. �������� ����, � ���!";
			link.l1.go = "JacobBerg_abordage_2";			
		break;
		
		case "JacobBerg_abordage_2":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "JacobBerg_abordage_3":
			dialog.text = "�� ��? ��� �� �� ������ �����. � ������ ����, ������� � �����-������. ��� ��� ����� ��� ������� - � ����, � ���, ������� �� ������.";
			link.l1 = "� �����, ��� �������� �� ���� ������ �� ����� �������. � ������ ���� ��������, �������� ���� �������, � ������ � ��������, � ����� ���������� �� �����������.";
			link.l1.go = "JacobBerg_abordage_4";			
		break;
		
		case "JacobBerg_abordage_4":
			dialog.text = "� � �����, ��� �������� ����, ����� ���������� � ���� � ������� �� ������, � ��������, ��� ��� ��� �������� ������� ���������� �� �����!";
			link.l1 = "�������� ��� ����?";
			link.l1.go = "JacobBerg_abordage_5";			
		break;
		
		case "JacobBerg_abordage_5":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle("PrepareToBoom2"); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.GenQuest.Detonation = true; // patch-4
		break;
}
}