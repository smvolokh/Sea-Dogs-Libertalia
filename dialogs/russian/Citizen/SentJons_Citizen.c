// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������");
		    link.l1.go = "exit";
			//Jason, ��� �� ��������
			if (CheckAttribute(PChar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "baster" && !CheckAttribute(npchar, "quest.terrapin") && CheckAttribute(PChar, "questTemp.Terrapin.SJ_count"))
			{
				link.l1 = "� ��� ��������� ������. �� ������ ������?";
				link.l1.go = "terrapin";
			}
		break;
		
		case "terrapin":
			if (sti(pchar.questTemp.Terrapin.SJ_count) == 5 || rand(9) == 1) // 10% ��� ������
			{
				dialog.text = "������-�� ������� � ��� ��� �����. �� ����� ��������� �� ���, ���� � ���� � ������ ���������� �����, ��������� �����. �� ������ ��������� ����������� � ����� �����.";
				link.l1 = "� � ���� ���� ������ �����?";
				link.l1.go = "terrapin_yes";
			}
			else
			{
				dialog.text = LinkRandPhrase("����� ������ ����� ��� �����? � ���� �� ����� ���� ��������.","� ��� �������, ��� ������ �������. �������� ������ �������?","�� ��� ������� �� ������, ��� ��������� ��� ���������. �����, ������� ����� ��������?");
				link.l1 = "� ���� ���� �������� ������ �����. �������, ������ ���������...";
				link.l1.go = "terrapin_no";
			}
			npchar.quest.terrapin = "true";
		break;
		
		case "terrapin_no":
			dialog.text = RandPhraseSimple(LinkRandPhrase("��. �����, ����� �� ����� ������.","�� ���� ������.","��, ���� �� ����� �����, ������� � ����, ������� ����������, �� ������ ���������� ����� ����� ������� ����������� ������."), LinkRandPhrase("� ���� ��������� ����� �����. � ����� �� ��� ������������� ���� ������, �� ��� �� ��, ���� �� �����. ������� ����� ���������� ����� ������ �������, ��� ����� ��������� ����� �������.","���, �� ��� ��� �������� ������ ������ �� �����.","����, �� ���������� �� ����. �������� � ����-������ ���."));
			link.l1 = "�������� �� ������������...";
			link.l1.go = "exit";
			pchar.questTemp.Terrapin.SJ_count = sti(pchar.questTemp.Terrapin.SJ_count)+1;
		break;
		
		case "terrapin_yes":
			dialog.text = "����, �� ����� �� �� ���� �������� ������. � ����� ����� ���� ������� ���� �� ������� ����� ���� ������.";
			link.l1 = "������� �� ������!";
			link.l1.go = "terrapin_yes_1";
		break;
		
		case "terrapin_yes_1":
			DialogExit();
			AddQuestRecord("Terrapin", "2");
			pchar.questTemp.Terrapin.Benjamin = true;
			DeleteAttribute(pchar, "questTemp.Terrapin.SJ_count");
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
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

