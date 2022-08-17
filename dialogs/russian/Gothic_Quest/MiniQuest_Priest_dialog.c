// boal 25/04/04 ����� ������ �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
	case "First time":
            	dialog.text = "������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ".";
        	link.l1 = "�����������.";
        	link.l1.go = "1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

		case "1":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "?", "���������, � ������ ����..."), "� ������ ����, ������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "� � ������ ��� ������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

   			link.l2 = RandPhraseSimple("� ���� ������ �������������.", "���� ������������ �� ������ ����.");
    			link.l2.go = "donation";

			link.l3 = "��������, ��� ���� ����.";
			link.l3.go = "exit";
		break;

		case "donation":
			dialog.Text = "�������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ". ������� �� ������� ������������ ������ ������?";
			Link.l1 = "��������, ������ ����, �� ������������� �� �����.";
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{
				Link.l2 = "� ���������, �������. 100 ��������.";
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = "1000 ��������. � �����, ����� ������.";
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{
				Link.l4 = "��� ����� � ��������, ������� � ��������� 5000 ��������.";
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			dialog.Text = "��... ��� ���� �������, � �� ������ ��� ��������. �� �� ��������� � ���, ��� ��� ��� �������� ��� ����� ������.";
			Link.l1 = "��� ��� ������ �� ������! ������� ����� ������ ����.";
			Link.l1.go = "2";
			Link.l2 = "��������, ������ ����, ��� ����.";
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			AddMoneyToCharacter(pchar, -100);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 100;
			dialog.Text = "�� ���� ������ ������ ��������� ���, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", �� ��� ���.";
			Link.l1 = "��� ���� ���������� � ����, ������ ����.";
			Link.l1.go = "ispoved";
			Link.l2 = "��������, ������ ����, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_1000":
			AddMoneyToCharacter(pchar, -1000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 1000;
			dialog.Text = "�� ���� ������ ������ ��������� ���, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", �� ��� ���.";
            Link.l1 = "��� ���� ���������� � ����, ������ ����.";
			Link.l1.go = "ispoved";
			Link.l2 = "��������, ������ ����, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_5000":
			AddMoneyToCharacter(pchar, -5000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 5000;
			dialog.Text = "�� ���� ������ ������ ��������� ���, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", �� ��� ���.";
            Link.l1 = "��� ���� ���������� � ����, ������ ����.";
			Link.l1.go = "ispoved";
			Link.l2 = "��������, ������ ����, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "2":
			dialog.Text = "��� �� �����, �� ���� ������ ������ ��������� ���, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", �� ���� ���������.";
			Link.l1 = "��������, ������ ����, ��� ����.";
			Link.l1.go = "exit";
		break;

		case "ispoved":
			dialog.text = "������� ��, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", � ���� ������.";
			link.l1 = "� ���������. ����� ���� � ������ ���.";
			link.l1.go = "exit";
			link.l2 = "� ��� ������, ������ ����...";
			link.l2.go = "ispoved_1";
		break;

		case "ispoved_1":
			dialog.text = "��� �� ������.";
			link.l1 = "��, �� �... � ����� � ������ �������, � ������...";
			link.l1.go = "ispoved_2";
		break;

		case "ispoved_2":
			dialog.text = "�� ���� ����� ��� �� ���� ���, ��� ������ ��� ������ " + NationNameGenitive(sti(NPChar.nation)) + "?";
			link.l1 = "���, �������, ������ ����.";
			link.l1.go = "ispoved_3";
			link.l2 = "���� � �����, ������ ����.";
			link.l2.go = "ispoved_4";
		break;

		case "ispoved_3":
			dialog.text = "����� ������� ������� ���� ���� �����.";
			link.l1 = "�������, ������ ����, � �����.";
			link.l1.go = "exit";
		break;

		case "ispoved_4":
			dialog.text = "������� ������� �� ������� ���� ���� ����!";
			link.l1 = "��������, ������ ����.";
			link.l1.go = "exit";		
		break;


	}
}

