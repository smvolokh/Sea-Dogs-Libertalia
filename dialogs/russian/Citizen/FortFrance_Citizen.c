// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������");
		    link.l1.go = "exit";
			//����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Citcount") && !CheckAttribute(npchar, "quest.Sharlie"))
			{
				link.l1 = "��������, "+GetAddress_FormToNPC(NPChar)+" �� �� ������, ��� � ���� ����� �������� - ������ �� �����? �� ������ ���� ���-�� � ��� � ������.";
                link.l1.go = "Sharlie";
			}	
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "findskiper" && !CheckAttribute(npchar, "quest.Sharlie1"))
			{
				link.l1 = "����������, "+GetAddress_FormToNPC(NPChar)+", ��� ����� ����... � ��� �������� �� ���� ������� - �����, ������ ����������� �������� � ����� ������?";
                link.l1.go = "Sharlie_1";
			}
			//����� ��������
		break;
		
		case "info":
        // �������� �� �������� ����� ���, �� �������
			dialog.text = "� ���, ������� �� ������ ���������� ���� ��� "+NationNameGenitive(sti(NPChar.nation))+"?";
			link.l1 = "�� �����... ����� ����.";
			link.l1.go = "exit";
			link.l2 = "����� ������ ������";
			link.l2.go = "new question";
		break;
		
		case "town":
        // �������� �� �������� ��� ������, �� �������
			dialog.text = "� ��� ��� ����������? �� ����. ������ �� �����.";

            link.l1 = "��� ���������! ����.";
			link.l1.go = "exit";
			link.l2 = "����� ������ ������";
			link.l2.go = "new question";
		break;
		
		//--> ����� ��������
		case "Sharlie":
			if (sti(pchar.questTemp.Sharlie.Citcount) == 3)
			{
				dialog.text = "��... ����, �� � ����� ������ ��������, ��� ���������� ��� ������ ������ �������� ���������... � ������� ��� �� ����������, �� �� ��������� ���� �� ���� ������. � ������ ������ �������... ���������� � ������� �����. �� ������� ����� ��� � ������.";
				link.l1 = "�������!";
				link.l1.go = "exit";
				AddDialogExitQuest("Sharlie_SetBenua");
			}
			else
			{
				dialog.text = LinkRandPhrase("���, ��� ��� ��� ������ �� �������.","����� �� ���� ��� ������. ��� ���� ����, �� ��������.","���, �� � ������� ����� ��� ���. ��� ���...");
				link.l1 = "�������... ����� �������� �� ������������.";
				link.l1.go = "exit";
				pchar.questTemp.Sharlie.Citcount = sti(pchar.questTemp.Sharlie.Citcount)+1;
				npchar.quest.Sharlie = "true";
			}
		break;
		
		case "Sharlie_1":
			dialog.text = LinkRandPhrase("���, ������� ��������� � �� ����.","��� ��������� �������. ��� ���� ����, �� ��������.","���, �� ����� �� ���� ������. ��� ���...");
			link.l1 = "�������. ��������...";
			link.l1.go = "exit";
			npchar.quest.Sharlie1 = "true";
			npchar.dialog.currentnode = "first time";
		break;
		//<-- ����� ��������
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}