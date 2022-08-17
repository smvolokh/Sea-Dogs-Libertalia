// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������, " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Jason, ��� �� ��������
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin"))
			{
				link.l1 = "� ��� ������ ������� �������� ������� ����. � ���� � ���� ���� ���� ��������. ������, �� ��� ������� �������� ����� ������ �����...";
				link.l1.go = "terrapin";
			}
		break;
		
		//��� �� ��������
		case "terrapin":
			dialog.text = "��������, �� � ������ ��� ������� ��������, ������ � ��������� ������. ������ ����� ���� ��������. ��� ��� �� ������� ���������, �������. ��� ��� ��������, �� ����� ������� ��������, ������� ��� ��������, ���� ������� ���, ��� �� � ���� �� ��������. �� ������ ���� � ���� ����������. ��� ����� ����� ������, ���� ������, ������ ������ ��� ���� �������. ";
			link.l1 = "�������, ��������. �����, �������� � ����� �������. ������ �� ������ ���� ����������� ����...";
			link.l1.go = "terrapin_1";
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_1":
			DialogExit();
			AddQuestRecord("Terrapin", "4");
			pchar.questTemp.Terrapin = "rober";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

