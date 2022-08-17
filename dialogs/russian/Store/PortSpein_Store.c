// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("���������, ���� �� ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��������, ��� �������, ����� ���� �������� ���-��. �� �������� ����!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�����, ��� '����' ���� ���-������ �������?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "� ������ 1654 ���� � ��� ���� ������� ������ ��� ������������� �������� ������ ������. �� ����� �����. ������ �� ���������� � ���? �����, ������ ������� � ��� ������, ���-�� �������...";
				link.l1.go = "guardoftruth";
			}
		break;
		
		//���� �������
		case "Consumption":
			dialog.text = "��� �������, �������! �� � ���� ������ ������� � �������� ���� ��� �����, � ����� - ��� ����. � ���, ������� ���������� ������?";
			link.l1 = "����. ������ �� ������������...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "��, �������, �� �� ��� ����� � ���� ������� ���������� �������� � ��������, ������� � ��������...";
			link.l1 = "����. ����� ������ �� ������...";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

