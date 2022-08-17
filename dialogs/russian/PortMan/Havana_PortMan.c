// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����������, ���� �� �� �� ����� �����, �� �� ����� ���� ��������� ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "��������, �� �������� ���� ���� ������ �� ����������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatHavana")
            {
                link.l1 = "������������. � �� �����"+ GetSexPhrase("","�") +" ������, �� �������������� �� � ����� ����� ������ '" + pchar.questTemp.Slavetrader.ShipName + "', ��� ������������� ������� ��������?";
                link.l1.go = "Havana_ratP_1";
			}
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "����������, � ��� � ���� �� �������� ���������� ������� �� ����� ������ ��������? ��������� ������, ����������, ����� ��� � ����������, � ������������� ��������?";
				link.l1.go = "caleuche";
			}
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_3" && !CheckAttribute(npchar, "quest.Mtraxx"))
			{
				link.l1 = "���� ���������� ����� '��������'. � ��� ��� ��������, ������� ���������, �� ������� �������. �� ������ ��� ���-������ ������?";
				link.l1.go = "mtraxx";
			}
		break;
		
		case "Havana_ratP_1":
			dialog.text = NPCStringReactionRepeat("��, ��������������. �� ��� ���� �� ���. �������� � ��� ������ �����������, ������� ������� ������ � ���� ������� � �������.", "�� ��� "+ GetSexPhrase("����������","����������") +" �� ����, � ��� �������.", "� �� ������ ���, �� ��� "+ GetSexPhrase("����������","����������") +" �� ���� ��������.", "� ����� �� ������ ��� ��������!", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������! ��� � ��������.", "��, �� ��...", "��, �����, "+ GetSexPhrase("���������","����������") +"...", "��������, " + npchar.name + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		
		// �������
		case "caleuche":
			dialog.text = "�� ���� ������ �������� ��� �� ���� ��������. �����, � ��������, �� ����� �� ���������.";
			link.l1 = "����. ����. ���� ������ ������...";
			link.l1.go = "exit";
			npchar.quest.caleuche = "true";
		break;
		
		// Addon 2016-1 Jason ��������� �������
		case "mtraxx":
			dialog.text = "���������... ����� '��������' ������ � �������� ��� ��� �����. ���� - ��������������... � ��� ��� - �� �������. ������� �������, � ����� ���������� �������� ������ ���������� ������ � ������ ��������. ������� ������������ - ����������� � �����������, � ����, � � �������� �������� �� ���� - ���!";
			link.l1 = "����. ������� � �� ����...";
			link.l1.go = "exit";
			npchar.quest.Mtraxx = "true";
			AddQuestRecord("Roger_1", "5");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
