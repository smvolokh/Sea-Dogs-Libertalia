// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��� �� "+ GetSexPhrase("�������","��������") +" ��� ������� ���� � �� ��...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, ����� ���-��...",
                      "�� ��, ������������� � ������ ���...", "�� ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "�� �� ������, ��� � ���� ����� ������� ��������?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// ����� ������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "��������, �� ��������� �� � ��� � ������ ������-�������, ������? �� ���������, ��� ��������, ����� ����� ��������. �� ������ � �����?";
				link.l1.go = "guardoftruth";
			}

            // ==> ����� ���.�������, ���������� ���� ��������
            if (pchar.questTemp.GothicLee == "ThreeCorsairs_toSeek")
			{
                link.l1 = "��� � ���� ����� �������� ������? � ���� � ���� ������ ����.";
                link.l1.go = "Gothic_6_1";
			}

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Oliver" && !CheckAttribute(npchar, "quest.RevengeCorsair_Oliver"))
			{
				link.l1 = "�� ������ ������ ��� ���������� �����?";
				link.l1.go = "RevengeCorsair_Oliver";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("��� ��������� �������. � ������ ������� ����� ��� ���.", "�� ��� "+ GetSexPhrase("���������","����������") +" �� ����, � ���� �������.", "� �� ������ ����, �� ��� "+ GetSexPhrase("���������","����������") +" �� ���� ��������.", "��������, ������ � �� �����! ������ ��� �� ����� �������?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� ��� ��, ����� ������.", "��, �� ��...", "��, �����, "+ GetSexPhrase("���������","����������") +"...", "������, " + npchar.name + "...", npchar, Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("���, �� ������. ���� � ��� ��������, � ������ - �� �� ������ � ����� ������.","������� ����� ������ ��� �����. ���, ����� � ��� �������� �� ��������.","�� � ��� � ����� ������� ��������� ���. ������ ����, �� �� ������ � ����� ������ ������.");
			link.l1 = "����. ����. ���� ������ ������!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;

		//********************* ����� ������� *********************

   		case "RevengeCorsair_Oliver":
			dialog.text = "� ���� ��� ��������, ����� ���������, ���������������.";
			link.l1 = "�������, �� �����, ��� ��������� ���� � ��� ����?";
			link.l1.go = "RevengeCorsair_Oliver_1";
		break;

   		case "RevengeCorsair_Oliver_1":
		dialog.text = "�� ��� �� ��� ������ - ��������...";
		link.l1 = "�������, ��� ����.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Oliver = "true";
		pchar.questTemp.RevengeCorsair_Oliver = sti(pchar.questTemp.RevengeCorsair_Oliver)+1;
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_3");
		break;

		//**********************������� �� **********************
        case "Gothic_6_1":
			dialog.text = NPCStringReactionRepeat("�������� ������? ��� ������ �����. �� ������� � ���� �������, � ������� ��� �� �������, ��� ��� �� ��� ��� ����������� �������.", 
				          "� ��� ��� ������...", "�� � ��� ��������...", ""+ GetSexPhrase("���","����") +", ����� ��� ����������� ���������� ������ ������!", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������, �������...", ""+ GetSexPhrase("�����","������") +", ������...", "��, �� ��...", "��, ��, ������, ��������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

