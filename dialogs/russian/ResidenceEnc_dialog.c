
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, arRld, arDis;
	int i, Qty;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//--------------------------------- ���� � ���������� ---------------------------------
		case "ResWoman":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			NextDiag.TempNode = "ResWoman";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase("��� ��� ��! ������� �������� - � � ���� � ������! �������� ����������, �� �� ������ ������!", "������ �����-��... � ��� ��� ������� ������ ������� � ��� ���? �����, �������! ������ ����� �������! ����� ���!!", "�� � ������� �������. ������ �������� ����������� �� ��� ����� � �������! ���!!");
				link.l1 = RandPhraseSimple("�������...", "���������� � ����������...");
				link.l1.go = "exit";
			}
			else
			{
			if (CheckAttribute(pchar, "TorjestvaDa"))
			{
			link.l2 = RandPhraseSimple("�� ����������, ��������. � ����� �������� �� ��������� � ���� �����, �� ����� � ���� ����� ������, ����� �� ������ �������� ������������� ������ ��� �������� ������?", "����� ���� �������� �� ���������, ��������, �� � ���� ����� ������ �� ����������� �� ������� �� ������ �������� �����������?");
			link.l2.go = "Torjestva_1";
			}
			dialog.text = LinkRandPhrase("��� �� ��� �������? ������� ������ ����������!", "��� �� ������������! ������� ��� ���������� �������� ���������!", "��������, ������, �� ��� ���� �� ����������. ����������� �������� ���������!");
				link.l1 = RandPhraseSimple("��������... � ��� �����.", "��������, � ������ ������. �����.");
				link.l1.go = "exit";
				}
			break;
		case "Woman_FackYou":
			dialog.text = "��, ��� �� ��� ��������?! � �-��, ����, ����, ������ �� �������... ������!!!";
			link.l1 = "��������, ����...";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;
		//--------------------------------- ����� � ���������� ---------------------------------
		case "ResMan":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "ResMan";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase(""+ GetSexPhrase("����� ��� ������, ��������","����� ��� ������, ��������") +"!", "���������� �������� �� ���� �����������, "+ GetSexPhrase("�������","���������") +"!", "��� ��� ���� �� ����, ��� ���� ����� � ���� ����������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + ". �� ��� ���� ����� - �������� ������!");
				link.l1 = RandPhraseSimple("�������, ������...", "������, �� �������� ������ �������!");
				link.l1.go = "exit";
			}
			else
			{
			if (CheckAttribute(pchar, "TorjestvaDa"))
			{
			dialog.text = LinkRandPhrase("������������. � - ����� �����������. ���� ����� " + GetFullName(NPChar) + ".", "� ������������ ����� �� ��������, " + GetAddress_Form(NPChar) + ".", "�� ������, " + GetAddress_Form(NPChar) + ", ��� ���������� - ������� �������, � ������� ������ ��������...");
			link.l2 = RandPhraseSimple("������������! ��������� �������������: ������� " + GetFullName(pchar) + ". ��� �������� �� ������, �� ������������ �� ������� �� ������ ����������� �����-������ �������� ����?", "������������! �� ���: " + GetFullName(pchar) + ". �� ����������, ���������, � �� ����������� �� �� ������ ������� ����� ���������� ����� ��� ����?");
	link.l2.go = "Torjestva_1";
			}
			dialog.text = LinkRandPhrase("������������. � - ����� �����������. ���� ����� " + GetFullName(NPChar) + ".", "� ������������ ����� �� ��������, " + GetAddress_Form(NPChar) + ".", "�� ������, " + GetAddress_Form(NPChar) + ", ��� ���������� - ������� �������, � ������� ������ ��������...");
				link.l1 = RandPhraseSimple("����� ������.", "��, ���������...");
				link.l1.go = "exit";
				}
		break; //--------- �������� � ���������� �� ������ -----------
		
		case "Torjestva_1":
			if (drand(2) == 0)
			{
				dialog.text = "�� ��, �������������! ��� ��� � ��������� ���� �������� �������������� �����. ��� ������ ���������� ����� ������ ������ ��������! �� ���� ��� �������� ������� - 50000 �������. ������ ������ ������, ������ �� ������ �������� ��������� �����������. ";	
	Link.l1 = "�������! ��� �� ����� �������� �������������.";
	Link.l1.go = "Torjestva_0";
	link.l2 = "���������, �� ��� ������� ������.";
	link.l2.go = "exit";
			}
			else
			{	
			dialog.text = "������� ���������� �� ���������� ���������� ��������. �� ���� ��� ������, �������� ����� �� �������, �� ���������� ������ �������� �����.";	
				link.l2 = "��������� �� �����. ����������� ����� ��� ������.";
	SetTimerCondition("TorjestvaNet", 0, 0, 0, false);
				link.l2.go = "exit";
			}
		break;

	case "Torjestva_0":
	dialog.text = "�� ������ �������� ���� ������?";
	Link.l1 = "��, �������!";
	Link.l1.go = "Torjestva_2";		
	Link.l2 = "��, �� �������� ���� �����.";
	Link.l2.go = "Exit";		
		break;
		
        case "Torjestva_2":
			if(makeint(Pchar.money) >= 50000)
			{
                dialog.text = "������������! ��� ����� ���������� �����������!";
			link.l1 = "�����! �������, ��� ��� ����� �������������.";
			link.l1.go = "Torjestva_3";
			}
			else
			{
                dialog.text = "��������, �������, �� � ��� ��� ��� ���� ������ �����.";
link.l1 = "�����, � ����� ������ �� �������! � ����� �������!";
link.l1.go = "Exit";					
			}
		break;

		case "Torjestva_3":
			DialogExit();
			AddMoneyToCharacter(Pchar, -50000);
			DoQuestCheckDelay("Torjestva_dvorec", 1.0);
		SetTimerCondition("TorjestvaNet", 0, 0, 0, false);
		break;	

		case "Man_FackYou":
			dialog.text = "�� �� ����� "+ GetSexPhrase("�������","��������") +" ���������� �����������?! ������, ����� "+ GetSexPhrase("����","�������") +"!!";
			link.l1 = "������ �����...";
			link.l1.go = "fight";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;		
		//--------------------------------- ������ � ���������� ---------------------------------
		case "ResGuard":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "ResGuard";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase(""+ GetSexPhrase("��� �� ������, ��������","��� �� ������, �������") +"...", "���������� ������!", "��, �����, ������ �� "+ GetSexPhrase("������","��������") +"? ��� ��� ����������� " + XI_ConvertString("Colony" + npchar.city + "Gen") + ". ���� ����� ����!");
				link.l1 = RandPhraseSimple("����, ����� ������!", "�� ���� �� � ���� ����...");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = LinkRandPhrase("������� ���� ��������� � ����� � �����������. �������� �����...", "� ������� ��� �����������, " + GetAddress_Form(NPChar) + ".", "��� ������ - �������� ��� �����������.");
				link.l1 = RandPhraseSimple("�������.", "��, �������...");
				link.l1.go = "exit";
			}
		break;
	}
}
