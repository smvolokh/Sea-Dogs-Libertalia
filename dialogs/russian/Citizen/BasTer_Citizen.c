// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������");
		    link.l1.go = "exit";
		break;
		
		case "info":
			dialog.text = LinkRandPhrase("��� ��� ����������?","��� ��� �����?","� ��� ������ ����?");
			link.l1 = "� ���� ������ � ����� ���������.";
			link.l1.go = "fadey";
			link.l2 = "����� ������� ��������� � ���-������ ������...";
			link.l2.go = "new question";
		break;
		
		case "town":
			dialog.text = LinkRandPhrase("���� ��� ����� �������?","��� �� �����?","���� �� ������ ������?");
            link.l1 = "��� ��������� ��� ����� ���������?";
			link.l1.go = "fadey_house";
			link.l2 = "����� ������� ��������� � ���-������ ������...";
			link.l2.go = "new question";
		break;
		
		case "fadey":
			dialog.text = RandPhraseSimple("������ �������. ��������� ���������, ������� � ������ ������ ���-����. �� ��� ������������� ���-�� �������, � ������ �����... �� ������� �� �������.","������� �����, ���� ������ �����������. ����������� ���������. ������ �� �����-�� ������� �������� ������, � ���� �������� ����� �� ����. ������ � ����� �� ���� ����������, � ������ ����� ����� ���� ���� � �� ���������!");
			link.l1 = "�������!";
			link.l1.go = "exit";
		break;
		
		case "fadey_house":
			dialog.text = RandPhraseSimple("����� �� ����� �����, ���� �� ������� �������, ��� ����� � ���� ������� �����.","�� ���������� ����������� ����������� ������� �� ���� � �����, ������ - ��� �����.");
			link.l1 = "�������!";
			link.l1.go = "exit";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

