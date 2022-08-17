// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "��������, � ������.";
			link.l1 = "� "+ GetSexPhrase("������","��������") +". ��������.";
			link.l1.go = "Exit";
			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "������, � ��� ������������ ��������?";
				link.l1.go = "Consumption";
			}
		break;
		
		//--> ���� �������
		case "Consumption":
			dialog.text = "��, ��� ��� ��� ������� ����� � �������� ��������� �� �������, � ������ ��� ��� ����������?";
			link.l1 = "������ ���������... ���� ��� ������ ����������� �� ������ � �������� ��� �����, ����� ��������� ������ ��������?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "���� ��� �����, ������, �� ���, ���, �� ������. �������� ����� ����� � ��������, �� � ������ � ���� ������, �����. ������� - ������ ����� � ���� �����������. � ���� �������� ������������ ����� ������� �� ��, ����� ��� ��������� ��� � ������. � �� ������ � ������� ��� ������ � ��������� ���-�� ����� ��������� �����.";
			link.l1 = "����� ��������, � ������ ����� ������, ��������� ��� ��������?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "����� ���. � ��� ���� ������� ��� � ���� �� ���� �� ��������� �������. ������, ���� �������� ��������� ��������� ��� � ������ ����������� �������. �� ���� ����� ����, �� ���� ���������� � ������������?\n����������� �������, ��� ���� �� � ������, � � ���� ������ ���������.";
			link.l1 = "��� �������� � �������� �� ������, �� �������, ���� ������� � �����������, ���� �� ������� ����� � ��������� ���, ��� ������������ ��� ���� �������� � ������? ����� ������� �� ������ '�������' ������, ��� ���� ����?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "��� �� ����� ��������, �� �� �����, ��� ��� ������ � ���������� ��������, � ����� ������� ���������... �������������. � ������ ���� ��, ��� ������ ��� ������, ����� ��� ��� ��� �������� ������ � ���, � ��� ��������� ���� ����������� � ������. ����� ������� ����!";
			link.l1 = "� ����� �� ��, ��� ������ �����, �������� �� ����������� � �������������, � ������� �� ������ �����������?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "��������, ������! � �������, � ���, ��� � � ����, ���� ���� ��������, ��� ����������� � ���������. ����� ����� �� ���� � �����.";
			link.l1 = "��� ��, �������� ��� ������������, � ��� �����.";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			DialogExit();
			npchar.quest.Consumption = "true";
			pchar.questTemp.Consumption.Commandant = "true";
			AddQuestRecord("Consumption", "3");
			pchar.quest.Consumption.win_condition.l1 = "location";
			pchar.quest.Consumption.win_condition.l1.location = "PortSpein_houseF2";
			pchar.quest.Consumption.function = "Consumption_CommandantHouse";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
