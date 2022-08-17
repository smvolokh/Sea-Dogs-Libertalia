// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "��������, � ������.";
			link.l1 = "� "+ GetSexPhrase("������","��������") +". ��������.";
			link.l1.go = "Exit";
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_4")
			{
				link.l1 = "������, � �����, ��� � ��� � ������ ���������� ������������ ������ � ����� '��������'. ��� ���?";
                link.l1.go = "Mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_8")
			{
				link.l1 = "� ����� �� ������ ���� ����, ������. ������ � ��� ������������ ��� ��������?";
                link.l1.go = "Mtraxx_5";
			}
		break;
		
		// Addon 2016-1 Jason ��������� �������
		case "Mtraxx":
            dialog.text = "������ �� ����� '��������'? ��� ���� �������? ��, �� ���������� � ��� ��� �������. � ���-�� ��� �� ����?";
			link.l1 = "� ����� ��������� ��� ��������� ��� ���������� � ���.";
			link.l1.go = "Mtraxx_1";
		break;
		
		case "Mtraxx_1":
            dialog.text = "��������, �� �� ����� ���������?";
			link.l1 = "�� ��������� ������ �������. �� � ���� ����������� ��� � ������, � � ��� ������� �������� � ���, ��� ��� ������ �� �������, � � ���, ����� ����� �������������� � ��� � ������. � ���� � ��� ������������.";
			link.l1.go = "Mtraxx_2";
		break;
		
		case "Mtraxx_2":
            dialog.text = "���...";
			link.l1 = "������, �����, � ���� �� ���-��... ������������� ��� �� ���� �����?";
			link.l1.go = "Mtraxx_3";
		break;
		
		case "Mtraxx_3":
            dialog.text = "�� ���� ������� ����������. � �������� ��� ������ � ���� �������. ��������, ������ ��� ���������.";
			link.l1 = "�������!";
			link.l1.go = "Mtraxx_4";
		break;
		
		case "Mtraxx_4":
			DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_5";
		break;
		
		case "Mtraxx_5":
            dialog.text = "�������������, ��� ���������� �������� ���� ���� ������� � ���� ���������� �����. ������, ��������-������ ��������� ��� ��� �� �� ��������. ���� ������ - ������ ������ � ����, �� ��� �����.";
			link.l1 = "�������, ������, ������ ��� � � ���� �������.";
			link.l1.go = "Mtraxx_6";
		break;
		
		case "Mtraxx_6":
            DialogExit();
            pchar.questTemp.jailCanMove = true;
			pchar.questTemp.Mtraxx = "jewelry_9";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
