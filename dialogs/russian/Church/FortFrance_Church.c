// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, "+ GetSexPhrase("��� ���","���� ���") +"?", "���������, � ������ ����..."), "� ������ ����, ������, "+ GetSexPhrase("��� ���","���� ���") +"...", "� � ������ ��� ������ ����, "+ GetSexPhrase("��� ���","���� ���") +": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, "+ GetSexPhrase("��� ���","���� ���") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason ����� � ���������
			if (CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "choose" && !CheckAttribute(npchar, "quest.LongHappy"))
			{
				link.l1 = "������ ����, � ��� ������ �����, � ���� � ���� ������ � ������� ����. �� ����������, ��� �� ����� ����?";
				link.l1.go = "LH_church";
			}
		break;
		
		// Jason ����� � ���������
		case "LH_church":
			dialog.text = "����� ����� �� ����� ������ � �������������� ��������� ������������ ������ � ����� �����. ������������ � �� ����, �� ���� ����� ��� ���������� �����, ����� �����������, ��� ���������� ����������, ��� - ��������� ���-�� � ����. �� ��� ������� �����������, �� ��� �������� ���� �������� � ����� ������.";
			link.l1 = "� � �� �����, ��� ��� ����� �����. ������ ����, �������, ���� ������ � ��������� �������� ���������� �����. ��� ���������� ��� ����� ��� ����� �������.";
			link.l1.go = "LH_church_1";
		break;
		
		case "LH_church_1":
			dialog.text = "������, ��� ���, �� � �� ����. ��������� ��� �������� - ����� ���������� �� ���������� � ��������� ����� ������� � �������� ���������� ����� �������� �������, �� ��� ����� ����������� ������� ������� ������ ������� ����� �� �������.";
			link.l1 = "����� ����������, ������ ����, �������. � ������... � ��������� ���� � ����� �������. �������� ��������� ���-������ � ��������.";
			link.l1.go = "LH_church_2";
		break;
		
		case "LH_church_2":
			DialogExit();
			npchar.quest.LongHappy = "true";
			LongHappy_GoToSantiago();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}



