// ����� �� �������
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
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "patrol":
			dialog.text = TimeGreeting()+", "+GetFullName(npchar)+", ��������� ������� �� ���-����. ��������� ��������� � �������������� ����� � ������������ ������. ������ ������� ���������, ��� �� � ��� ��� �������.";
			link.l1 = "������� "+GetFullName(pchar)+", ������ ������. � �������� ����� �� ��������� � ������� �������� ���� ��������, �����������. ��� ������, �������������� ��� ����������.";
			link.l1.go = "patrol_1";
		break;
		
		case "patrol_1":
			dialog.text = "���-���... ��� �����. ������� �� �������� ����������� � ������ �������. ����� �������� ��� ���������������� - ��� �� ������ �� �����?";
			link.l1 = "� �� ������ �������� �� �������� �������. ���� ��� ������������� ���������� ���� ���� ������ �� �����������, �� ��� ����� ���������� �� ������������� ����� � ����, � ��������. �� ������, � ������ � ������� � ��������� �����. ������������, ��� ���� ������� - � ��������� �������������� ������ ������ ���������� �����.";
			link.l1.go = "patrol_2";
		break;
		
		case "patrol_2":
			dialog.text = "��� ��� ������� ���� ���������, �����. �� ���� ��� �����������... ��, ���������! ��� ������������� ���, ��� ��� ����������? ����� � ��� ���������� ����! �� ��������?";
			link.l1 = "��������, ������ �� �������� �������. ��� ����� ������� ����.";
			link.l1.go = "patrol_3";
		break;
		
		case "patrol_3":
			dialog.text = "���� ������, � ����� �� ������� � ����� �� ���� � ����������! ��� �� ������ ������ �������! ��� � ������ �� ���... �����, �� �������� � ����������, �������� ��� ��� ����! � �������������� ������� � ������� ������, � ��� ������ ������������ ���������. � ������ �������.";
			link.l1 = "������, ��� ���� �� ���������. � ������� �� � ������� � �� ������� ������ ���������. ������� ��, ����������.";
			link.l1.go = "patrol_4";
		break;
		
		case "patrol_4":
			dialog.text = "���� ������� ������� �������� ��� �� �������? ��� �� ����� ���� �����, �� ��� ������� ����� ������!";
			link.l1 = "���. ������� � ���� ��� ����, � ��� ���� - ����. � �� �� ������.";
			link.l1.go = "patrol_5";
		break;
		
		case "patrol_5":
			dialog.text = "��, ����... �����, �������� ���� ��������. �� ���� ������ �����������. �����!";
			link.l1 = "����� �������, ������.";
			link.l1.go = "patrol_6";
		break;
		
		case "patrol_6":
			DialogExit();
			AddQuestRecord("Guardoftruth", "42");
			LAi_ActorGoToLocation(npchar, "reload", "reload2", "none", "", "", "GuardOT_ClearMayakPatrol", 12.0);
			for(i=1; i<=3; i++)
			{
				sld = characterFromId("GOT_spamayaksold_"+i);
				sld.lifeday = 0;
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 10.0);
			}
		break;
		
		case "shore":
			PlaySound("VOICE\Russian\Sharlie\Diego De Montoya.wav");
			dialog.text = "��������! � ���� �������� � ���...";
			link.l1 = "����, � ���� ����� ����� ������ ����� �� �������... �� ���������, ������, �� ���� � ���� ��� �����������? ��-��, �����. �� ����� ���������. ��� ������ ��� �� ������� ���� ���-�� ��-�������...";
			link.l1.go = "shore_1";
		break;
		
		case "shore_1":
			dialog.text = "� ��� ������� ������, ������. ��� �� �� ������� �� ����� - �� �� ���� ������ ������ ������� � ����� ���������� �����. � ������ ���������� � ����� �������� ������� ���� �������. ��� ��, ���� ������� �����������.";
			link.l1 = "������� �� ����� ������� � �����, ������.";
			link.l1.go = "shore_2";
		break;
		
		case "shore_2":
			dialog.text = "�� �� ����� ����������. �� � ��� �� ��� ��� ���� ���� ������ �����, ���� �� �������� ��� ���� ����.";
			link.l1 = "������� ������� � ������������������ ������ ��� ��������� ������, ���������, ��� �� ����������� ��� ���� ����� ����������� �������? � ���! ��� �� ���� ����� ����� ������, � ������?";
			link.l1.go = "shore_3";
		break;
		
		case "shore_3":
			dialog.text = "������� �� ����, � ��� �� ��� ��������. ���� ������ ��������� �� ���������� �� �����, � ��� ��, ��� ��� ���������� �����. �� �������� ���������� � ��� �� ������ - ������ ��������� �� ���� �����.";
			link.l1 = "� �� �������, ������, ��� � ������ ����� ������? �� ��� ����� ��� ���� ������, ��� �� ���� ����� � �� ����. ����� ���?";
			link.l1.go = "shore_4";
		break;
		
		case "shore_4":
			dialog.text = "� ���� � ��� �����?";
			link.l1 = "�����, ������ '�����������'? ��...";
			link.l1.go = "shore_5";
		break;
		
		case "shore_5":
			dialog.text = "�����, ��� ��� ��������� ����. ��� �� ���������� ���������� ��� ������������ ���� ����, ��� ����� �������� ����� � ���� ���������� ��� ����. �������������� ���������� - � ��� ����������� ��������� ������������.";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio")) link.l1 = "��, �����, ������� ����, ������. ������� �� � ������ ������, ��� � ����� ������� �����, ��� ������ � ����� � �����, �� ������������� ���������� � ����� ������? ����-��, � ���!";
			else link.l1 = "����� �� ������, � �������, ������!";
			link.l1.go = "shore_6";
		break;
		
		case "shore_6":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "goto", "goto5", "none", "", "", "", 10.0);
			if (CheckAttribute(pchar, "questTemp.Guardoftruth.SanAntonio"))
			{
				PlaySound("interface\abordage_wining.wav");
				PlaySound("interface\abordage_wining.wav");
				for(i=1; i<=10; i++)
				{
					sld = characterFromId("GuardOT_Oursoldier_"+i);
					LAi_SetWarriorType(sld);
					ChangeCharacterAddressGroup(sld, "Shore15", "reload", "reload1_back");
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
				}
			}
			sld = CharacterFromID("spa_baseprisoner");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "EnemyFight");
			for(i=1; i<=13; i++)
			{
				sld = characterFromId("GOT_spashore_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "GuardOT_DiegoShoreGuardDie");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}