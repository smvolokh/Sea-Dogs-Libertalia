// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "?", "���������, � ������ ����..."), "� ������ ����, ������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "� � ������ ��� ������ ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "�� ������, " + GetSexPhrase("�����","������") + "..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, " + GetSexPhrase("�����","������") + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�������, " + GetSexPhrase("������ ����","������") + ", � ��� '����' ��� ���-������ �������?";
				link.l1.go = "Consumption";
			}
		
		break;

		//���� �������
		case "Consumption":
			dialog.text = "���, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ". � ����� ������ ����� �������� � ����� ������.";
			link.l1 = "����. �������� �� ������������, " + GetSexPhrase("�����","������") + "...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
