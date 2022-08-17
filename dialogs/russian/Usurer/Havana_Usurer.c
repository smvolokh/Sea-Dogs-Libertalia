// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "����������, � ��� �� ��������� ������� �� ����� ������ ��������? ��������� ������, ����������, ����� ��� � ����������, � ������������� ��������? �����, ����� ����� ������, ��� � ���� ��������?";
				link.l1.go = "caleuche";
			}
		break;
		
		// �������
		case "caleuche":
			dialog.text = "�����, ��� ����� �� ����� ������ ���, ������� �������. � ������������� �� ���� ��������, � ������� �� �����������.";
			link.l1 = "����. ����. ���� ������ ������...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

