
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	bool bOk;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� � ��� ��������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		// ==> ����� � ���������
		case "PearlMan":
			NextDiag.TempNode = "PearlMan";
			dialog.text = NPCStringReactionRepeat("�����������! ���� ����� " + GetFullName(npchar) + ". ��� � ���� ���� ������?", 
				"����������� ��� ���!", 
				"� ����� ����� ����� ����� �����...",
                "��, ������� ��������� � ����� ���������! � �� ��� ����� ��� ����������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� ����� ���������...", 
				"� � ���� ����...",
                "�������.", 
				"���...", npchar, Dialog.CurrentNode);
			link.l1.go = "PearlMan_1";
		break;
		case "PearlMan_1":
			dialog.text = "�� ��� ������ ��������, ������ " + NationNameGenitive(sti(npchar.nation)) + ", ����� ��� ����...";
			link.l1 = "��, � � �����...";
			link.l1.go = "exit";
			link.l2 = "������, � ������ �� ��������� ������� ���� ���������� � �������������, ��� �������, �?";
			link.l2.go = "PearlMan_2";
		break;
		case "PearlMan_2":
			if (rand(10) < 9)
			{
				dialog.text = "�� ���, ��� ��! �� ����� ���� ����� ��������� ��������� - ������!";
				link.l1 = "���, ������� ��� � ��� ��������...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "� ��� � ���� ����� ������, ����� �������� �������� ������. � ���� �� ���������, �� ���� ������������ ���� ���������� � ������� ��������, ��� �������� ������ � ����. �� ���� ���� ������ � ������ ����, ��� �������� ��� �����...";
				link.l1 = "�������, �� ������� ����.";
				link.l1.go = "exit";
			}
		break;
		case "PearlMan_Sharp_1":
			dialog.text = LinkRandPhrase("�� ����, �� ������ "+ GetSexPhrase("�������? ��� ������, ��������","�������? ��� ������, ����") +"!", 
				""+ GetSexPhrase("����?!! ��, �����, ������ �� �������, �����","����?!! ��, �����, ������ �� ��������, ������") +"?! ���� ������ �� ������ ���������...", 
				""+ GetSexPhrase("�� � ����� ���, ������? ����� ������?! � ���?!! ��� �� �� ������, �����������","�� � ����� ���, ������? ����� ������?! � ���?!! ��� �� �� ������, �������") +"...");
			link.l1 = RandPhraseSimple("�� ���� ������...", "��� �� ���������?!");
			link.l1.go = "exit";
		break;

		// ==> ������� � ���������
		case "IndPearlMan":
			NextDiag.TempNode = "IndPearlMan";
			dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("�����������","����� ����") +" ����� ��������?", 
				"����� ��, "+ GetSexPhrase("�����������","����� ����") +".", 
				""+ GetSexPhrase("����������� ����� ��������. �� ����� �� ����.","����� ���� ����� ��������.") +"",
                "���� ������� �� ��� ���������"+ GetSexPhrase("��� �����","�� ������") +".", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��.", 
				"��, ����� �.",
                "����� ��������.", 
				"� ���� ���"+ GetSexPhrase("","�") +" ���� ������.", npchar, Dialog.CurrentNode);
			link.l1.go = "IndPearlMan_1";
		break;
		case "IndPearlMan_1":
			dialog.text = "������, ����� ����"+ GetSexPhrase("��","��") +".";
			link.l1 = "�� ������ ����������, ��������� ���� �����"+ GetSexPhrase("","�") +"...";
			link.l1.go = "exit";
		break;
		
				
		case "CitizenNotBlade":
			dialog.text = "�������, ��� �� ��������! ������� ������, ���� ��� �� ��������!";
			link.l1 = LinkRandPhrase("������.", "�����.", "�� ���������, ��� ������...");
			link.l1.go = "exit";
		break;  

	}
}
