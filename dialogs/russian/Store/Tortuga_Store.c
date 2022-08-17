// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "� �������� ������� ����� �������� �� ���� �����...",
                          "�������, �������, ����� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "��, �� ���� - ��� �� ����.", "��-�-�-�����, ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "tortuga2")
			{
				link.l1 = "��������, ��� ����� ����� ��� �����. ��� ��� �������, �� ������� � ���������� � ���� ��������������� �����������, ����� � �������� �������� ������. �� ������� �� �� � ���� ����� ������� ��� �������?";
                link.l1.go = "guardoftruth";
			}
		break;
		
		case "guardoftruth":
			dialog.text = "��� �����? ��� ��, ��� ��, �����! ��� ������ ������ �� �� �������, � ����������� ���� ������� ��� ������. ��� ��� ��� ����� ���� ����� � �������� ������ - ������� ������ ����� ���.";
			link.l1 = "� ����� ��� ����� ��������?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "����������, ����-�������.";
			link.l1 = "����. �������, �� ��� ����� �����!";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "������ ����������, �������. ���� ��� ������ ��� � ����� �������� ���� ������ ����!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Guardoftruth", "10");
			pchar.questTemp.Guardoftruth = "maarten";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

