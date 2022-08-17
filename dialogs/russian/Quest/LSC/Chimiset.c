// ������ ������� - �������
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
		
		//-------------------------------------� ������ �� ���������-----------------------------
		// ������� R
		case "KillChad":
			dialog.text = "����! ����������... �����, �������� ����, ������ ��� ��������� ������������.";
			link.l1 = "��� ����... �������, ��� ��, ��� �� �������, ����� ������������� ������� �������, �����...";
			link.l1.go = "KillChad_1";
			LAi_RemoveCheckMinHP(npchar); //������� ������������, ���� ��� ����
		break;
		
		case "KillChad_1":
			dialog.text = "����� �� ������� ����, �����? � ������ ��� �������� � ����� �������, � �� ���� ���� - �� ����� ����� ��� �������� ��, ��������, ������. �� �� ����������, ���� �������, ��� ��� ������� ���� � �����, ����� ���� ��� �� ������������ �� ����.";
			link.l1 = "��... ���������, � ������? ���� ��� � ���������� ���� ����: ���� � �� �������� ����, �� ���� ���� ����� ��������� �������.";
			link.l1.go = "KillChad_2";
		break;
		
		case "KillChad_2":
			dialog.text = "� ���� ������ �� ������ ��������, ���� �� ���� ������. ��������: ������� � ��� ����� ���������� �� ����, �� ����� ����� ����� ������������� ���������� �� �� ������� ��������� ��� ��������������� - ��������� ����� �� ��� ������ �� ������������ ������. ��� ��� � ������ ������� ��� ������ ������\n��� ��������� ����, ��� �� �� ������� - �� ���� ���� '�� �����'. ��� ������ �� ���� ������ - ��� ���������� ����������� � ����� � ����������� ������������ ����� ����� � �������� ��� ��� �����";
			link.l1 = "�����? ���� ������? ��� �� �����? � ������� �������, ��� ����� ��� �������?";
			link.l1.go = "KillChad_3";
		break;
		
		case "KillChad_3":
			dialog.text = "���, ������, �� � ������ �� ������... �� ������ �� ����� ��� �������. ���� ������� ���� �����. � ���� ���������� ����, ��� ��� �������.";
			link.l1 = "������ ���, ������, � ������ ��� �������� ���� ����� ������������ ������, ���-��� �����, ��� ��� ���� ��������� ���� �� ������. �������� � ���� ������ - ���� ���������� ����!";
			link.l1.go = "KillChad_fightfail";
			link.l2 = "������, � ���� ����. ��� �� �������?";
			link.l2.go = "KillChad_4";
		break;
		
		case "KillChad_fightfail":
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			LAi_SetActorType(npchar);
			LAi_ActorAnimation(npchar, "afraid", "", -1);
			LAi_SetImmortal(npchar, false);
			pchar.quest.LSC_fightfail.win_condition.l1 = "NPC_Death";
			pchar.quest.LSC_fightfail.win_condition.l1.character = "Chimiset";
			pchar.quest.LSC_fightfail.function = "LSC_Fightfail_Final";
		break;
		
		case "KillChad_4":
			dialog.text = "��� ���, � ����, ����� ������. � ��� ����� ��������� ������ � ������ ��������. ������ ������, �� ����� ��� ������ � �����������, ��� ����� ������� ���� ��������. �������, ������, ��� ���, �� ���� ���-��� �������: � �������� ������� ����� ��������� ������������� �����\n��-�� ���, ������? ������ ���, ������ ������ � �����, ������� �������� � ������ ����� ����. ����� ���������, �� ������ ������� ��� �� �����. ������ �� ������� ���, ��� ���� �����, � ������ � ��������. ��� ������� ������ �������� � ���������� ����, �� ������ ��� ���������� ������ �� ������ - �������� ������� ����\n�� �, �������, �� ������ �������� ������? ������ ��� � � ���� ���� ���� �� �������� - ���� � ���, �� � ����� ����� �������� ������ � ����� � �� ������. ���� ���� �������� ���������� ���������, � ���������� ���� ������ �������, ����� �����...";
			link.l1 = "������. �������� �� ���� ����� ����� - ����� ��������� ����������. ��� ����� ������� ��������� ����� ��� ��������.";
			link.l1.go = "KillChad_5";
		break;
		
		case "KillChad_5":
			DialogExit();
			pchar.quest.LSC_fightfail.over = "yes"; //����� ����������
			LAi_SetImmortal(npchar, true);
			ref location = &Locations[FindLocation(pchar.location)];
			location.private1.key = "crowbar";
			location.private1.key.delItem = true;
			NextDiag.CurrentNode = "KillChad_6";
		break;
		
		case "KillChad_6":
			dialog.text = "�� ����� �������! ������ ��������� ������...";
			link.l1 = "��-��, ��� ���.";
			link.l1.go = "exit";
			NextDiag.TempNode = "KillChad_6";
		break;
		
		case "Chad_die":
			dialog.text = "�������� ������! �� � ������ ��������� �������� �������. � � ����� ����� �����, ����������. �����, ��� ���� ���?";
			link.l1 = ""+pchar.name+". "+GetFullName(pchar)+" ���� �����. � ��?";
			link.l1.go = "Chad_die_1";
		break;
		
		case "Chad_die_1":
			dialog.text = "��� ��� - �������, � ����� ������� � �������� ������ ����� - ������� ����. �� ����� ��� ������ � ���, ��� �� ������� ���� ��-�� ������� � ���� �����. ������ �� ���� ��������, ������� ���� � ���� �������. �� ������ �������� ����� � ��� �� '����������'...";
			link.l1 = "������... �������, ���� �� ��� �� �����, �� � ������ ��������� ����� ����� ����� � ��� ������� �����. �� ������ ��� ��������� ���������, ��� �, ��� ����� �������, � ��� ��� ����� ����� �������?";
			link.l1.go = "Chad_die_2";
		break;
		
		case "Chad_die_2":
			dialog.text = "��� ����� ���������� ������ ��������������, ���� �������� ������ �������. ��������������� ����� � �� ������. ������, ��������� �� �������� ���������� �������� ��������. ����������� ����� ������������� ��� �����. ������ �������� ����� ����, ������� ������ ��������� ���� ����� ���������������\n������� - ��� ����, ������ �����, ��� ������ ���� ������� ������. ����� ������� �� ������� ���� ��� ���� ���� - �������, � �������� � ��� �������� ������, � ����� ������ ����� �������. ��, � ������ ������� ������. ����� - ������ �� �������� ������ �������, � �������� ���� ���������\n�� ������ �� ������ ������������ ������� � ������� ����� ��������� ���� ������. ����� �������� '���-��������', � ����� �������� ������������ �������� ������ �������������� �� �������, � �� ��������� ��� �������� �� �����, ������� �� ��� �������������. �� ����-�� �����, ������, �� � ��������\n��� ������ - ��� ������ �����, � ���� �������� � ��������� ������. ������ ������� - ������ ������� �����, ���� �� ��������� ���� �� �������. ��� ����, ������ �� ����� �������� �������, ����� ��������� ������� �� �������, �� ���� ������� � ������� �������� � �������.";
			link.l1 = "������ ���� ��� ������ �������� ��� ����� ����?";
			link.l1.go = "Chad_die_3";
		break;
		
		case "Chad_die_3":
			dialog.text = "��� �������� � ������ ������, ������ �������. � �� ������� �� ����������� ����� �����, ������ ������� ��������, � ������ ��� �����. � �������� ��� �� ��������, �� ������ �� ������������ �����. ��� ������, ��� ��� ���� �����, ���� ��� �� ���. � ����, ��� ��� ����. ��� ���. � ������������ ��������� ����� ���������\n������� ��� �� ��� ��������� ���� ������ �����, � ���������� ����� ������, ��� ��� ������ ������ � ��������, �� ����� ������ �������� ������ ��� ������ ���� ��������. ��� �� � ����� ������� ��� ������ ������. ��� � ������� ������ ���������� �����, � ���� ��������� �� �������.";
			link.l1 = "��� ���? �����, � ������...";
			link.l1.go = "Chad_die_4";
		break;
		
		case "Chad_die_4":
			dialog.text = ""+pchar.name+", ���� ���, ����� ���� ������� ��� ��������� � �������� �������� ������. � ����� ������ ���� ����� ��������� ������ �����, � ����� ��� ����� ������������. ����� ���� ���� � ����� ����� - ��� �������� ����� ������. �� ������ ����� ������ ����� �� ������ ����. �� ��������� ��������� ���� �����-�� ������ - ������, ��� ��� ����� ����� ���-�� ���������� ������ �������� �����\n����� ���������� ����������� � ����� �������. �� ������� ��� �� ������� '���-��������', �� ����� � ������� �� ������ � � ���� �� ������� �� ����� '�����' ����� ������� ����. �������� ���, ��� ��� �������� �������������, � �����, ��� �� ���� ���� ����� �������, � ��, �������, ��� �� ��� ���\n� ����� �������� �� ���� �������, � ����� ����� � ������ ������ � � ������������� ���� ��������, ����� �� ��������� � ���� ����������. ��� � ��� �������, ��� ��������� �� ������� '���������'. � ������ ����� �������� ���� ������!";
			link.l1 = "������, �������. � ����������� ����� ���� ����� �� ����... '����������'. ������!";
			link.l1.go = "Chad_die_5";
		break;
		
		case "Chad_die_5":
			dialog.text = "� ���. �� ���� �������, � ��� ����� � '���������', ������ ����������� ��������. ��� ������� ����� ��� ���� �������, ��� ����� ������. � �� ������ ���� ������, �� �� �� ������ �����������, � ��������� � ������ � ���������� ���������� �����, �� �������� ������ � �� ����\n������� ������ ����������� �� '���-��������', ��������� � ������, � � ��� �������� �������� �� ����� � �������� �������� � ����. ����� ����� �� ������� ��������� �� ���� ���������� ��������, ��� � ���� �������. �� �� ����� ���� ����� ������, ����� ���� ����: ���� ������ �� �����.";
			link.l1 = "�������. ����������� �� '���-��������'. �� �������!";
			link.l1.go = "Chad_die_6";
		break;
		
		case "Chad_die_6":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Notsearchbody");
			LAi_SetActorType(npchar);
			LAi_ActorFollow(npchar, pchar, "", -1);
			pchar.quest.LSC_LetterChad.win_condition.l1 = "item";
			pchar.quest.LSC_LetterChad.win_condition.l1.item = "letter_chad";
			pchar.quest.LSC_LetterChad.function = "LSC_LetterChad_Find";
			sld = characterFromId("SharkMush_17");
			sld.lifeday = 0;
			for (i=1; i<=2; i++)
			{
				sld = characterFromId("SharkSold_1"+(i+3));
				sld.lifeday = 0;
			}
			AddSimpleRumourCityTip("��, �������, ��� �� ����������� � ������ �������. ����������, ����� � ���. ����������...", "LostShipsCity", 5, 1, "LSC", "");
			AddSimpleRumourCityTip("����� �����, ��� �� �������� �� '���������' ������� ������� ��������. ������ �� � ��� �� �������� �������� �����.", "LostShipsCity", 5, 1, "LSC", "");
			AddSimpleRumourCityTip("��� ��� �� �������� �������� ��-�� �������! ����� ���������... ������ �� ���� �������, �� ���� ��������. �� ����, ���������� ���, ��� ���������������...", "LostShipsCity", 5, 1, "LSC", "");
		break;
		
		// ������� N
		case "prisoner":
			dialog.text = "��� �� ������ �� ����, ����������?";
			link.l1 = "���� ���� ����� �������, ���?";
			link.l1.go = "prisoner_1";
		break;
		
		case "prisoner_1":
			dialog.text = "��, ��� �. �� ������ �� ������-�� ����, ��� ������ ��� �������� ��������?";
			link.l1 = "�� ����. � ������ �� ��������, ����� �������. � ������ ��� ������ � ����� ������������, �� ��� ����� �������: �� ������ ������ �������� �� ��� ��������� �������.";
			link.l1.go = "prisoner_2";
		break;
		
		case "prisoner_2":
			dialog.text = "������ ����� ��������� ����? ����� ��� ��� �������. ������� ���� �������. �������, ��� ��� �������, ��� � ��������� ������ ��� ������� ���� ���������������.";
			link.l1 = "�������� �������, ��� ������ ����� ���� ������. �����, �������: ���� �� �� ������� �������� �������� ������� �������� � ���� ��������? � ������� �� �� ��������� ������������ � �������. ������ �� �� �������, ��� � ����� � ���...";
			link.l1.go = "Friend_2";
		break;
		
		case "prisoner_3":
			dialog.text = "� ���� ���� ��� �����-�� �������?";
			link.l1 = "��. �� �� ������ ������ �������� - ����� �������? ��� ���, ��� ��������...";
			link.l1.go = "prisoner_4";
		break;
		
		case "prisoner_4":
			dialog.text = "����� �������? �������, ����. ��� �������� � ������� ��� ������������, ������ ��������� �������, �� ��� ����� ������. ��� ��� �����, � ������ �� �������, ����... �� ��� - ������ �������.";
			link.l1 = "��� ���? �����, � ��� � ���� ����� ���?";
			link.l1.go = "prisoner_5";
		break;
		
		case "prisoner_5":
			dialog.text = "�� ��� ������ � ������. �� ����� ������ � ��������, ������� � ������ �� ������. ����� - �� ����� ������� ��� �� ����� �������.";
			link.l1 = "�������! � ��� ������: �� �� �������� ����� �������� �� ����� ��������� ����? �� ������ ��� ��������� �������, � �������� ������ �����.";
			link.l1.go = "prisoner_6";
		break;
		
		case "prisoner_6":
			dialog.text = "����� � ����� ���� ������ �� �����, ����������. ������� � ����� ������ ��� ��������. ���� � ������������ �������, ��� �� �������� ������� � � ����������� ���� ��� ���. � ��� ��� �������� ���������� �������� - �� ��� ��� �����... ��, �������, ��� �� ������.";
			link.l1 = "�� ��� ��, ������� � �� ����... �� ��� ����� �����, �������!";
			link.l1.go = "prisoner_7";
		break;
		
		case "prisoner_7":
			dialog.text = "� ��� ���? ������ ����� ���� ��������?";
			link.l1 = "��. ������ ��� ���������� ������. ��� ������ ��������� ����. ��, � ��� ����...";
			link.l1.go = "prisoner_8";
		break;
		
		case "prisoner_8":
			dialog.text = "����! ������... ������� �����.";
			link.l1 = "�� ���-�� ��������?";
			link.l1.go = "prisoner_9";
		break;
		
		case "prisoner_9":
			dialog.text = "�� ������ ���...(������� �����) � ����, �� �� �� ����� �������... �� ������� ����! ��� ������� ��������. �� ��� ����� �� ������������ ������� ������� ����������� ����� ������, ����� ����� ������, ������� ����� � �������� ������. ���� ��� ������ ������� �� �� ������� - ������ ������ � �����������\n� ���: ���� �����, � ������ ������� ����������, �� ������� � ���� ��������� ����� �������: �������� ���������� �����, ������ ���� �� ��� ���������� ���������. ������� ��� �����. ����� �����, ��� ��������� � �������� ������ ��� ������ �������.";
			link.l1 = "��. ������, � ����������� ������� �� ���� �������. ����!";
			link.l1.go = "prisoner_10";
		break;
		
		case "prisoner_10":
			DialogExit();
			sld = characterFromId("Capper");
			sld.quest.chimiset_talk = "true"; // �������� � ��������� ���������
			if (!CheckAttribute(npchar, "quest.capper_talk")) chrDisableReloadToLocation = true;//������� �������
			else chrDisableReloadToLocation = false;//������� �������
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "entrance_10"; // ���� �����
			LSC_SetWhiteBoy(); // �������� ������ ��������
			NextDiag.CurrentNode = "prisoner_11";
			AddQuestRecord("SharkHunt", "20");
		break;
		
		case "prisoner_11":
			dialog.text = "������ �������� � ����� � ������ ��� ���, ��� � ������. ��, ������� �� ������� ����� ���� ������...";
			link.l1 = "��-��, ��� ���.";
			link.l1.go = "exit";
			NextDiag.TempNode = "prisoner_11";
		break;
		
		//------------------------������ �� ����������, ���� ��� ����� ����� ��������-----------------
		case "Friend":
			dialog.text = "��� � ����� ��, ��� ������� ����. � ��� ��� ��������� ���� �� ������, � �� ��, ��� �� ������� ���, � �� ����� ������� �������. � ����� ��� ����� ������ ��� ������� ���, � ���� ���� ��� �������. � ������, ��� ��� ���� �����������.";
			link.l1 = "�������! �� ������...";
			link.l1.go = "Friend_1";
		break;
		
		case "Friend_1":
			GiveItem2Character(pchar, "indian_1");
			GiveItem2Character(pchar, "indian_11");
			GiveItem2Character(pchar, "amulet_1");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ������ � ����� ��������� ����. �� ���� ������ ������ ��� �������, � ����?";
			link.l1 = "�� ����, �������. ��� ����� ���� ������. �� ���� ��������������. ���� ����� ����� ������� ���������: ���� �� �� ������� �������� �������� ������� �������� � ���� ��������? � ������� �� �� ��������� ������������ � �������. ������ �� �� �������, ��� � ����� � ���...";
			link.l1.go = "Friend_2";
		break;
		
		// ���� �����������
		case "Friend_2":
			dialog.text = "� �����, � ��� �� ��������, ��� ����. � ��� ����� ��� ������ ���� ��������. ������ ������� ��� ���������� �� � �������, � ��� ������ ��������� ������... �� �� ��� ��������� � ������ ����������� �� ����� ������, � ��� ������� ��. ������ �� ��� ��� �� �������.";
			link.l1 = "��� ���?! �� ���� - ����-����, � �������� �� �����?!";
			link.l1.go = "Friend_3";
		break;
		
		case "Friend_3":
			dialog.text = "�� ������ ���. ��� ������ ���� �� ����� �� �������� ��� ��������� '���-��������'. ��������� ��� ����� ���� ������� ������� ������ �� �������.";
			link.l1 = "��� ���������! ����������, ��� ������ � ������� �� ���������... � ���� ��� ���� ������� ���-��?";
			link.l1.go = "Friend_4";
		break;
		
		case "Friend_4":
			dialog.text = "�������� �� �������� ��������, � ������� ������� ��� ��������� '������'. ���� �������� ��� �� ����� � ����� ��������� ������, �� ����� ������� ���� �������, ���������� �� ���.";
			link.l1 = "��! ��� �� ����� �� ����������? ����� �� ���� ����� ����������� ��������� ������...";
			link.l1.go = "Friend_5";
		break;
		
		case "Friend_5":
			dialog.text = "������ �� ���� �� ���������, ���� ���. ��-������, �� ����� ���������� �������, � ��-������, ��� ����� ���������� ������. ��� ���������� ���� ������ ��������, ������ ��� �� ������������ � '���-��������'.";
			link.l1 = "��. �����. � ������� ��� ����. ������� - ��� ������� ����������, � � ����, ��� ��� ������.";
			if (CheckAttribute(npchar, "quest.chimiset_die")) link.l1.go = "prisoner_3";
			else
			{	
				if (CheckAttribute(pchar, "questTemp.LSC.Mary")) link.l1.go = "freedom_1";
				else link.l1.go = "Friend_6";
			}
			AddQuestRecord("LSC", "4");
		break;
		// ���� �����������
		
		case "Friend_6":
			dialog.text = "����, � ���� ��� ���� �������. �������, ���� ���, �� ����������.";
			link.l1 = "����� ������ ��� ��� �������: ��������� ���������� ����, ��������� �� ���� ���������. � ������, ������� � ����� � ������� �������, ���������� ��� ������-�� �������� � �����-�� �����. ��������, ����� ���������� ����������� � ������� ���������. �� ������ ��������� �� ���� ���� ���� �����-�� �����������?";
			link.l1.go = "Friend_7";
		break;
		
		case "Friend_7":
			dialog.text = "��. �������� ���������� ����������? ���� ��������... ���� � ���, ��� ������� ����������� �� �������� ���� ���������� �� '���-���������', � ���� � �������, �� ������ � ������������� ���������� �������. �� � ���� ���� ���� �����������: �������� �������� �� ����� ����������� �� �������� ������� ������ �������\n��� ����������, � ��� �������� �������, ����� ����� ����� � ���� ����: � ������� ����� ������� '�����-����������', � � ������ ������� '�����', ���� ��������� �� ��������� �������� �������� �� �����. ������ ���� ���� ������� ������ ����� �� ���� �������, �� �� ������ ����� ��������, �� ������ ������, ���� ��������� �������: ������� ������� ����������\n� ������ ������ ����� ������� ���� � ������� ����� ����� �����-�� ����� ������ � ������������ ������. � ��� ��������� ��������� ������ ����� ��������, �� ����, �������, ������� �������� �� ������� ��������, � �������� �������� ������ ����.";
			link.l1 = "���, ������, �� �� ������ ����: � ������ ���������� ��� �����-�� �����... � �� �� ����� �� � ���� ��������� ������?";
			link.l1.go = "Friend_8";
		break;
		
		case "Friend_8":
			dialog.text = "���. ���, ��� � ����� �� ��� ���, �� ��� ���� �� �������. �����������, �����, ���-�� � ���������.";
			link.l1 = "������... � ����� ������, ���� ���������� ����� �����, �������! �� �, ��������, ��������� ������, ���� � �� �������, ��� �� �� ���� ��������... �� �� ������ ������ �������� - ����� �������?";
			link.l1.go = "Friend_9";
		break;
		
		case "Friend_9":
			dialog.text = "����� �������? �������, ����. ��� �������� � ������� ��� ������������, ������ ��������� �������, �� ��� ����� ������. ��� ��� �����, � ������ �� �������, ����... �� ��� - ������ �������.";
			link.l1 = "��� ���? �����, � ��� � ���� ����� ���?";
			link.l1.go = "Friend_10";
		break;
		
		case "Friend_10":
			dialog.text = "�� ��� ������ � ������. �� ����� ������ � ��������, ������� � ������ �� ������. ����� - �� ����� ������� ��� �� ����� �������.";
			link.l1 = "�������! �������, �������, �� ��� ����� �����!";
			link.l1.go = "Friend_11";
		break;
		
		case "Friend_11":
			dialog.text = "������ ���! ���� � ���� �������� ��� �����-�� ������� - �������, ������, ��� �����.";
			link.l1 = "�����������! � ������ ��� ����. ��� ��������!";
			if (CheckAttribute(pchar, "questTemp.LSC.Mary")) link.l1.go = "freedom_2";
			else link.l1.go = "Friend_12";
		break;
		
		case "Friend_12":
			DialogExit();
			NextDiag.CurrentNode = "Chimiset_wait";
			LSC_SetWhiteBoy(); // ������ ������ �������� � �������
			pchar.questTemp.Saga.SharkHunt = "search_mush_1"; // ���� �� ������� - ����� �������
			AddQuestRecord("SharkHunt", "11");
		break;
		
		case "freedom":
			dialog.text = "�, ��� � ��� ������� ����, �������� � ������ ��������, �, ��������, ������. ��������� ���� �� ��, ��� ����� ���� ������� �������� ���� �� ��� �������� �������. � ����� ��� ����� ������ ��� ������� ���, � ���� ���� ��� �������. � ������, ��� ��� ���� �����������.";
			link.l1 = "�������! �� ������...";
			link.l1.go = "Friend_1";
		break;
		
		case "freedom_1":
			dialog.text = "�� ��� ���-�� ������ ��������, ����� ����?";
			link.l1 = "����� ���, �������: �� ������ �� �� �� ������� �������� �� �������� ����� �������?";
			link.l1.go = "Friend_9";
		break;
		
		case "freedom_2":
			DialogExit();
			NextDiag.CurrentNode = "Chimiset_wait";
			LSC_SetWhiteBoy(); // ������ ������ �������� � �������
		break;
		
		//--> �������������� ����
		case "Chimiset_wait": // ���� ������
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "�! ��� ����� ���� "+pchar.name+"! ��� �� �� ������? ���� ������ ����, � ����...";
				link.l1 = "��� ������ - � ��� � ������, �������. ����? ��������, �� - ���� ��� ��� ��������� ��������� ����������...";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			dialog.text = "��� ������� ���� �� ��� �����, ��� ������ ����?";
			/*if (!CheckAttribute(npchar, "quest.story"))
			{
				link.l1 = "��������, ��� ����� ����� ��������? �� ������������, ��� ����� ���.";
				link.l1.go = "story";
			}*/
			if (!CheckAttribute(npchar, "quest.crab"))
			{
				link.l2 = "�� ������� � ������ �� ��� � ����������� '���-��������'. ������ ��������� ������� ���� ��������?";
				link.l2.go = "crab";
			}
			link.l9 = "������ ������, ����������, �������. ������ ����� ��������� ����.";
			link.l9.go = "exit";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		
		case "story":
			dialog.text = "����� ����� �������� ������� ������ ����� ������.";
			link.l1 = "��!";
			link.l1.go = "exit";
			npchar.quest.story = "true";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		
		case "crab":
			dialog.text = "������ ��� �������, � ������ �������� ����� ���������� �������� - ����� �� �����. �� ���� ���� ���� - ��� ����� ����������, � �� ������ ������ ������ �������. �������� �� ������� �� ��������� ����� �������� ��������� �������� - ������� �� ��� � �������� ������ �������, ������� ���� ���� ����������� �� ����, �� �, �������, �������� �� ���\n��� �������� ������������ �������� ������ - ����� ������� ����� ������� ����������� ������ ��������, ����� ����, � �� �������� ���������� ���������� ������� ��, ������ � ���� ������� ��� - ��� ��������� � �������� ��������, ��� ���������� �������, ����� �������� � ��������� ������������. ����� ����, ������ �������������� ������������ �� ������� ����\n���-�� ������ � ��� ��� ���� �������, ������������ ������ �� ���� ������. ����� �� ��������� �������� �� ����, ������� �� ��������� �������, �� ����� ������: �� ������� ������ ���� �������� � ������� � ���� - � �� ����������� ��� ����������� ��� ��������� �����. ����, ������, ����� ��� ��� �� ����� �� ��������...";
			link.l1 = "� ��� �� �� ������, ���� �������?";
			link.l1.go = "crab_1";
		break;
		
		case "crab_1":
			dialog.text = "� �� �� �������������? ����� ��������� �� ����� ������, ���� ���� ������� � ����, ��� ������� �� �������� ������������ � ������. ��� � ����� � ���� ���� - �� �� �������� �� ������. ������� � � ����������� ���� - ���� ���������� � ��������� � ����� ����������.";
			link.l1 = "�������...";
			link.l1.go = "exit";
			npchar.quest.crab = "true";
			NextDiag.TempNode = "Chimiset_wait";
		break;
		//<-- �������������� ����
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
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