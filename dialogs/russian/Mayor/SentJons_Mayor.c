// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ����� ������ �� ���������� ������ ������, � �� �� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Jason ������ ������
			if (CheckAttribute(pchar, "questTemp.GoldenGirl") && pchar.questTemp.GoldenGirl == "antigua")
			{
				link.l1 = "���� ���������, � ������ ��������, ��� ���������� ����������� � ������� ���������� '��������'.";
                link.l1.go = "G_Girl";
			}
		break;
		
		// Jason ������ ������
		case "G_Girl":
			dialog.text = "�����������? � �������, ��������, ����?";
			link.l1 = "����������, ���� ���������. ������������ ���... �����. ������ ���������. � ������, ������� �������������, �, ��� ������ ���� ���������� ������, �� ���� �� ���������� ������� ����������.";
			link.l1.go = "G_Girl_1";
		break;
		
		case "G_Girl_1":
			dialog.text = "������������! ������� ������ ����� ��� ����� ���! � ���������� ��������� �������.";
			link.l1 = "�������, ���. � ������� �����, ��� ��� ���� ����������, ���� ��� ������� ������.";
			link.l1.go = "G_Girl_2";
		break;
		
		case "G_Girl_2":
			dialog.text = "�� ����������, ������� � ��� ����� � ��������. ������! ����� ���!";
			link.l1 = "� ������ ���... ���, ��������? ��� ���, �����?!";
			link.l1.go = "G_Girl_3";
		break;
		
		case "G_Girl_3":
			DialogExit();
			GoldenGirl_AntiguaArest();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

