// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� ������ ������� � �������?", "� ������� ����� ��������� - �������, �������... ��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "�� �������� ���������� � ������� � ������� ���������, " + GetAddress_Form(NPChar) + "...", "������ ��� �� ������� �� ��������� ������ ������...",
                          "���������� ���� � ��� ���� ��������, � ��� ��� � ��,"+ GetSexPhrase(" ���������, "," ") +"�������� �� ����...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "�� ��������...",
                      "�� ��, ������������� � ������ ���...", "���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�����, ��� '����' ���� ���-������ �������?";
				link.l1.go = "Consumption";
			}
		break;
		
		//���� �������
		case "Consumption":
			dialog.text = "���. ��� ��?";
			link.l1 = "��. ������ �� ������������, ��������...";
			link.l1.go = "exit";
			npchar.quest.Consumption = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

