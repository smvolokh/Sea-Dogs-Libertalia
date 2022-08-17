// ������� � ������ ��������������� �������
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
		// ----------------------------------- ������ ������ - ������ �������
		case "First time":
            dialog.text = "� ���� ���� �� ���? ���? ����� "+ GetSexPhrase("���� ������","������� �� ��������� ����.") +"";
			link.l1 = "��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			if (pchar.questTemp.piratesLine == "Soukins_toPuertoPrincipe")
			{
				link.l1 = "������, ������"+ GetSexPhrase("","�") +" �, ��� �� ��������� ����� ��� ����� ������ ��������. � �����"+ GetSexPhrase("","�") +" �� ������� � ���� �������.";
				link.l1.go = "PL_Q7_1";
			}
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		//�������, ����� �7
		case "PL_Q7_1":
			dialog.text = "������ ���� ���.";
			link.l1 = GetFullName(pchar) + ".";
			link.l1.go = "PL_Q7_2";
		break;
		case "PL_Q7_2":
			dialog.text = "��-��, � �� "+ GetSexPhrase("����������� �� �� �������, ��������","�� �� �������� �������, �") +"?";
			link.l1 = "� ������� �� �����, ��� ��� ��� "+ GetSexPhrase("�����������","'��������'") +"?";
			link.l1.go = "PL_Q7_3";
		break;
		case "PL_Q7_3":
			dialog.text = "� ��� ���, ��� �� ��� �� ���������. ��, �� �����! ��-��, ��� ����! ������ ��� ��������...";
			link.l1 = "�� ����� �� ���?..";
			link.l1.go = "fight";
			LAi_SetPlayerType(pchar);
			pchar.questTemp.piratesLine = "Soukins_FightinResidence";
			for (i=1; i<=5; i++)
			{
				iTemp = 10 + rand(10);
				sld = GetCharacter(NPC_GenerateCharacter("questPirate_"+i, "pirate_"+i, "man", "man", 25, PIRATE, 10, true, "quest"));
				FantomMakeCoolFighter(sld, 25, 70, 70, "blade_26", "pistol6", "bullet", 20);
				LAi_SetWarriorType(sld);
				LAi_warrior_SetStay(sld, true);
				LAi_group_MoveCharacter(sld, npchar.chr_ai.group);
				ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
			}
		break;
		case "PL_Q7_5":
			dialog.text = "������ ��� ������� �� ���� ������������ ��� �����������?!! �-�-�, �, �������, ���� ����... ��, �� �����, ��-��, ��� ����! ������ "+ GetSexPhrase("����� ����������","��� ���������� ���������") +"!";
			link.l1 = "��-��, ��� �� ����?!";
			link.l1.go = "fight";
			LAi_SetPlayerType(pchar);
			pchar.questTemp.piratesLine = "Soukins_FightinResidence";
			for (i=1; i<=5; i++)
			{
				iTemp = 10 + rand(10);
				sld = GetCharacter(NPC_GenerateCharacter("questPirate_"+i, "pirate_"+i, "man", "man", 25, PIRATE, 10, true, "quest"));
				FantomMakeCoolFighter(sld, 25, 70, 70, "blade_26", "pistol6", "bullet", 20);
				LAi_SetWarriorType(sld);
				LAi_warrior_SetStay(sld, true);
				LAi_group_MoveCharacter(sld, npchar.chr_ai.group);
				ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
			}
		break;
		//�������, ����� �8
		case "PL_Q8_deck":
			dialog.text = "� ��� ��� ������ ��������� ��������� "+ GetSexPhrase("������ ��������","�����") +" � ������������ ��������? ��� �� �������...";
			link.l1 = "��, ��� �� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;
		case "PL_Q8_deck_1":
			dialog.text = "�� ���, ����� ��. � ��� � � ������!";
			link.l1 = "�� �� ���� �� ���������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;

		case "PL_Q8_deck_2":
			dialog.text = "�� � ��� �� ����� ������� � ���� �� ������? �������, ���� �� ������ ������"+ GetSexPhrase("","�") +" ����� ����� �����, �� ������ ����� ���"+ GetSexPhrase("�����","��") +" ��� �����������?";
			link.l1 = "���"+ GetSexPhrase("����","�") +"-�� ��� ��� ���?..";
			link.l1.go = "PL_Q8_deck_3";
		break;
		case "PL_Q8_deck_3":
			dialog.text = "������, �"+ GetSexPhrase("��","��") +" �� �� ������... ��� � ����� �� � ��� ��������. ��� ������� � ������, ����� ������ ��� � �������, �� ��� �� ��������.";
			link.l1 = "�� ��� � ���?";
			link.l1.go = "PL_Q8_deck_4";
		break;
		case "PL_Q8_deck_4":
			dialog.text = "� ���� ������ ������ �� �������, �� ��� ������ �� ���������. ��� ��� �������� ������ � ������ ��������.";
			link.l1 = "�� �����, � ���"+ GetSexPhrase("��","��") +". �� ������ ������������� - ��� ������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_5";
			npchar.DeckDialogNode = "PL_Q8_deck_5";
		break;
		case "PL_Q8_deck_5":
			dialog.text = "� �� ����� � ����� ��������!";
			link.l1 = "��, �� ��� �������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_5";
			npchar.DeckDialogNode = "PL_Q8_deck_5";
		break;
		//� ����� ���������� �����
		case "Shore48":
			dialog.text = "�� ��� ��, �� ������ �� ���������. ������ ����� ��������� ����� �������. � � ��� ���� ������, ����� ���������.";
			link.l1 = "������, � �����"+ GetSexPhrase("","�") +" ����.";
			link.l1.go = "Shore48_1";
		break;
		case "Shore48_1":
			LAi_LocationFightDisable(&Locations[FindLocation("Shore48")], false); 
			chrDisableReloadToLocation = false; 
			LAi_SetWarriorTypeNoGroup(npchar);
			NextDiag.TempNode = "Shore48_over";
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Shore48_over":
			dialog.text = "���� �� ����? �����, ������ ���� ������� � ������!!";
			link.l1 = "��, ��� �������...";
			link.l1.go = "exit";
		break;
		//����� ������ � ���� ������
		case "PQ8_exitTown":
			dialog.text = "��� ���� �����?";
			link.l1 = "��������, � ����, ��� ���� ��������� ����� ��� ��������, �� ������ �������� ��� ����� ����, ����� �� ��� ����� �������.";
			link.l1.go = "PQ8_exitTown_1";
		break;
		case "PQ8_exitTown_1":
			dialog.text = "� �� ������� � ���� ������?";
			link.l1 = "������ �� ������, �� ��� ������.";
			link.l1.go = "PQ8_exitTown_2";
		break;
		case "PQ8_exitTown_2":
			dialog.text = "�� �� ��� ���"+ GetSexPhrase("","��") +" � ��� ����, ������"+ GetSexPhrase("","�") +" ��� �������. �� - "+ GetSexPhrase("��������","���������") +" �������. � ������ ������ ����������� �� ����, ��� ��?";
			link.l1 = "�� ����� ��, ������... �����!";
			link.l1.go = "PQ8_exitTown_3";
		break;
		case "PQ8_exitTown_3":
			dialog.text = "�-��, �������, �����... � ������. � ��� �� � ����� �� �������. ��� ��� ���� ������, ���� ���"+ GetSexPhrase("","�") +"...";
			link.l1 = "������!..";
			link.l1.go = "exit";
			LAi_warrior_DialogEnable(npchar, false);
		break;
	}
}
