// ������� ��� �� ������ �������� ������ ��������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, n;

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
		
		// �������-������ �����-��������
		case "SQC_skeletcap":
			PlaySound("Types\skel.wav");
			dialog.text = "����... ��� �����... ��������... �������. �� ������... � ����� ����... ��� ���� ���� ���... ��� ���� ���� ���...";
			link.l1 = "���? ��� ��? ��� �����?";
			link.l1.go = "SQC_skeletcap_1";
		break;
		
		case "SQC_skeletcap_1":
			PlaySound("Types\skel.wav");
			dialog.text = "�� �������... �� ��������... �� �������... �� ����� ����. � ������ ����� ����... ���� � ���� ���� - �� �� �������, ��� ��... �� �� ���������... �� ��� ����� ������ �� ��� ����... ������������ � ������, ��� ��... ��� ��� �� �����-��������...";
			link.l1 = "�� �� ���!";
			link.l1.go = "SQC_skeletcap_2";
		break;
		
		case "SQC_skeletcap_2":
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_SetCurHPMax(npchar);
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for(i=2; i<=3; i++)
			{
				sld = characterFromId("SQI_skelet_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Ksochitam_SQCskeletcapdie");
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		// ����� ����� ����������
		case "guardmask":
			PlaySound("VOICE\Russian\sharlie\Hranitel Maski Kukulkana.wav");
			dialog.text = "��� ����� � ���� ����!..";
			link.l1 = "�!.. � ��� �����... ��� ��� ���������!";
			link.l1.go = "guardmask_1";
		break;
		
		case "guardmask_1":
			dialog.text = "� ���� ��... � �������� ��... �� ������ ���... ��� ������������...";
			link.l1 = "� ��� �� ������ ��������? ��� ��?!";
			link.l1.go = "guardmask_2";
		break;
		
		case "guardmask_2":
			dialog.text = "� - ����� ���������, ��������� ����� ����������... � ���� ���������� ������!..";
			link.l1 = "...";
			link.l1.go = "guardmask_3";
		break;
		
		case "guardmask_3":
			PlaySound("Ambient\Teno_inside\big_ring.wav");
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "KSOCHITAM_MONSTERS");
			LAi_group_FightGroups("KSOCHITAM_MONSTERS", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestFunctionDelay("Terrapin_SetMusic", 1.2);
			n = Findlocation("Shore_mask");
			locations[n].type = "seashore";
			pchar.questTemp.Ksochitam.GuardMaskFight = "true";
			for (i=1; i<=4; i++)
			{
				CreateLocationParticles("fire_incas_Simple", "fire_incas", "fire_incas"+i, 1, 0, 0, "fortfire");
				CreateLocationParticles("fire_incas_Simple", "fire_incas", "fire_incas"+i, 2.5, 0, 0, "fortfire");
			}
		break;
		
		case "guardmask_4":
			PlaySound("VOICE\Russian\sharlie\Hranitel Maski Kukulkana.wav");
			dialog.text = "����������...";
			link.l1 = "� ����� �� ��� ��� ������, �? �� �� ��������� ���������, ����� ������?";
			link.l1.go = "guardmask_5";
		break;
		
		case "guardmask_5":
			dialog.text = "���. �� �� ������� ���� ����������, �������. ���� ���� ���������� ��������. ��� �������� ����� ������ ����� �����, ���� �� �� ��������� ��� ���� � �� ������.";
			link.l1 = "�� ��? � ������ �� ����� �� ����� �� ������ ���� ������?";
			link.l1.go = "guardmask_6";
		break;
		
		case "guardmask_6":
			dialog.text = "�� �������� � ������� ����, � �� ������ ���� '������ �����'. � ������ ��������� ���� �����, ��� ��������� ��� ����� � �������� �������� ������ ���� � ��� �������� ��, �� ��� ������.";
			link.l1 = "��� ��? ��� �� �� ����� ����, �����?";
			link.l1.go = "guardmask_7";
		break;
		
		case "guardmask_7":
			dialog.text = "�����-�� ���� ����� �������� ������. � ��� �������� � ������ ������ �� ����������. �� ����� ������� ��������, �� ���� �������� � ��������� � ������. ����, �� ��� ���� � ����, ������� ����� ���������� � ������ ���������, ��������� ����� ����������. ���, ��� ������ �� ��������, ���� ������� � ����� ����, � ����� ���������� � ������\n�� ���� ����� ��� ������ ���� '������ �����' ���� ������� �����, �� ������� �������� ���� ���� �� �������� ��������. �� ��� ���, ���� � �� ������ � ���� ���� ����, � ���� ����� ������� ������������ �����, �� ������ ���������.";
			link.l1 = "���� ����� '������ �����'?";
			link.l1.go = "guardmask_8";
		break;
		
		case "guardmask_8":
			dialog.text = "��. ��� �� ��� ���� ����� �����. ����� ��� ����, � � ����� ������������ ���������, � �� �������� �����. � ������� ����, ��� �� ������� �� ������� � �������� �������� �����.";
			link.l1 = "� �������� ���� �����������, �����. � ����� ����� �� ���������� �� ������� � ��������. ��� ���?";
			link.l1.go = "guardmask_9";
		break;
		
		case "guardmask_9":
			dialog.text = "��, ��� ���. ��� �������������� �������� ������ ��������� ����, ����������. ����� ����, ��� �� �������� ��������, �� ������� ����� � ������� ��.";
			link.l1 = "�� ��� ��, � �������, �� �������� �����, �����...";
			link.l1.go = "guardmask_10";
		break;
		
		case "guardmask_10":
			dialog.text = "� ��� ������...";
			link.l1 = "����� ������ '������ �����'. �������, �� �������� ����� ����� ����.";
			link.l1.go = "guardmask_11";
		break;
		
		case "guardmask_11":
			RemoveItems(pchar, "knife_01", 1);
			AddItems(pchar, "blade_33", 1); 
			PlaySound("interface\important_item.wav");
			Log_Info("�� ������ ���� '������ �����'");
			Log_Info("�� �������� '��� ������'");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			dialog.text = "��� ����� � ���� ����� �������! ������ � ���� �������... �� �� �������� � ���� �������� ���� ���� ��� � ������� ����� ����. ��� ����� ��������� �������, ������� �����-���� ����� �������� ������.";
			link.l1 = "...";
			link.l1.go = "guardmask_12";
		break;
		
		case "guardmask_12":
			DialogExit();
			LAi_SetActorType(pchar);
			DoQuestCheckDelay("Ksochitam_GuardMaskGift", 1.5);
		break;
		
		case "guardmask_13":
			dialog.text = "� ������ ��� ���� �������. �� ���� �� ������������ �� ��������� - ��� ������ ������ � ����� ���������� ������ ������ �������� ������.";
			link.l1 = "������ �� � ���. ����� ��������� ������ �� ����� ������ ������... �� ������, �����! �� ��� � ��������! �������� - ��� ��� �� �����?";
			link.l1.go = "guardmask_14";
		break;
		
		case "guardmask_14":
			dialog.text = "��� ������ ����� �������� ����. �� �������� ���� ������� � ��� ������, ����� ��� ��� �������� ���� �����. �������������� �����, ������� ��������... ������ ��� �������� ���, ��������� ���� ������� ��������� ����. ��� ��������� �� ���� ��������� �� - � �������, �������� � ����.";
			link.l1 = "��� ��� ������� � ����?";
			link.l1.go = "guardmask_15";
		break;
		
		case "guardmask_15":
			dialog.text = "���� ���� ��� ��������, ������ �� ����������. �� ������ ��������� �� ��� ����� ������. � ����� ���� ��, ��� �� ���������� �� ������ ��������, ��� �������� ���� ������, � ��������� � ����� ������ �� �����.";
			link.l1 = "��� ��������������� ���� � ��������?";
			link.l1.go = "guardmask_16";
		break;
		
		case "guardmask_16":
			dialog.text = "��� ������������� ���. ��������� ���. �� ��� ������������ ���� ��������� ����. � �� ����� ��. �� ����������� �� ���, � � ����� - � �����������. �� ������ � �������-�� ��������!";
			link.l1 = "��� ����� �����, ����������� � ��������?";
			link.l1.go = "guardmask_17";
		break;
		
		case "guardmask_17":
			dialog.text = "��� ������ � �������. ��� ��������� ����� �����, ���������� �� �� ��������������, � ��������� ���������� ������ ������, ����������� �� �� �����������. ������� ����� ��� �� ����� �������� �� � ����� ����������, � ��� ����� ��� ��� ��� ������, ������ �����... ��������. ���� �� ����� ������� ��������� �� �������� - ��� ������� ���. �� ��� ������� �� �� ������ ����...";
			link.l1 = "����� �������� � ������ ���� ����� �����, �������� � ��������?";
			link.l1.go = "guardmask_18";
		break;
		
		case "guardmask_18":
			dialog.text = "� ������� - ��. �� ��������, ��������� ����� ���������� ��� �� ��������.";
			link.l1 = "����. ���� �� ��� ������������.";
			link.l1.go = "guardmask_19";
		break;
		
		case "guardmask_19":
			dialog.text = "������, ������. �������, �� ����������� ���� ����� � ���������� �����.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("Ksochitam_GuardMaskGoAway");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}