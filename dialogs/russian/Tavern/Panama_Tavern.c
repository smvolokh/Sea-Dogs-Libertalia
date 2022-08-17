// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��� �� "+ GetSexPhrase("�������","��������") +" ��� ������� ���� � �� ��...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "�� ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatPanama")
            {
                link.l1 = "��������, �������, � ��� � ������ ��� ����� - ������� �������. �� ������, ��� ��� ��� ����� �����?";
                link.l1.go = "Panama_rat_1";
            }
			// Addon-2016 Jason ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_panama")
            {
                link.l1 = "��������, � ��� �������� �� ����� ������� ������, �� ������ � �����? �� ������� ������ � ������. �������� ����� ��������, � ������ ��������. �����, ������� � ����...";
                link.l1.go = "FMQG";
            }
		break;

		//-->������������
		case "Panama_rat_1":
			dialog.text = NPCStringReactionRepeat("��, ��� � ��� � ������ ���� ���. ��� �� ������ ����� ��������... ����� � ���� �������� �����-�� ������ - �� ��� - ��������� ����������, � �� � ���� �� ������.", "�� ��� "+ GetSexPhrase("���������","����������") +" �� ����, � ���� �������.", "� �� ������ ����, �� ��� "+ GetSexPhrase("���������","����������") +" �� ���� ��������.", "��������, ������ � �� �����! ������ ��� �� ����� �������?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("� ���� ����, �� ������?", "��, �� ��...", "��, �����, "+ GetSexPhrase("���������","����������") +"...", "������, " + npchar.name + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "Panama_rat_2";
		break;
		
		case "Panama_rat_2":
			dialog.text = "��, ������ ������ ������ ���� ������ - � ����� �����. � �� ������ � �����. ��� ��� ��� ��� ���.";
			link.l1 = "�������, �� ��� ������� �����!";
			link.l1.go = "exit";
			pchar.questTemp.Slavetrader = "FindRatPortobello";
			AddQuestRecord("Slavetrader", "21_1");
		break;
		//<--������������
		
		// Addon-2016 Jason ���-���������
		case "FMQG":
			dialog.text = "������� ������? �������? ������ ��� �����. ���, ��������, ��������� � ��� � ��������� ����� �� �����������.";
			link.l1 = "��� ��������... ����� �� �����? �� ���� ������ ������� �������, ���� ������� �� �������. ��� ������ ������ ���� ��������.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			dialog.text = "������� �� �������? ��� ������� ������ ������� � ��� �����, �� ������� ����������. � ��� ��� ������ �� ������ ����� � �����-�����. ������� ���� ��������� �����������.";
			link.l1 = "����. ������, � �������� �������� ���� ����� �������. �����, ������� � �� ���, ��������.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			DialogExit();
			pchar.questTemp.FMQG = "headhunter_portobello";
			AddQuestRecord("FMQ_Guadeloupe", "8");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

