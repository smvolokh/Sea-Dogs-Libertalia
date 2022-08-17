// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("��� ������� ������ "+ GetCityName(npchar.city) +" � ����� �������. ��� �� �� ������ ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��� �� �������"+ GetSexPhrase("","�") +" ��� ������� ���� � �� ��...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "�� ��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// ����� ������
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "��������, �� ��������� �� � ��� � ������ ������-�������, ������? �� ���������, ��� ��������, ����� ����� ��������. �� ������ � �����?";
				link.l1.go = "guardoftruth";
			}
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "hunting" && !CheckAttribute(npchar, "quest.Caleuche"))
			{
				link.l1 = "��������, ��� ����� ������� �� ����� ������ �����. ��� �������, ��� �� � ������ �����. ��� � ���� ��� �����?";
				link.l1.go = "caleuche";
			}
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("���, �� ������. ���� � ��� ��������, � ������ - �� �� ������ � ����� ������.","������� ����� ������ ��� �����. ���, ����� � ��� �������� �� ��������.","�� � ��� � ����� ������� ��������� ���. ������ ����, �� �� ������ � ����� ������ ������.");
			link.l1 = "����. ����. ���� ������ ������!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;
		
		// �������
		case "caleuche":
			dialog.text = "������? �� � ���� ��������� ������. �� ������ ��� ��� - ���� � ������ �� �����, ��� �����. �� �� �� ���������, ������ �� �������, ��� �� ����� ����� ������ � ���� �� ��������, ���� ��� � ������ ���� �������� � ����� ������� �����������. ���� ������� �� �������, �� �����. ����� ����� ���� �� ����� ������ ����.";
			link.l1 = "����? ��. ��� ����� ��� ���������� � ����, ����� ������� �������?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "��, ������ ��� ����� ��� ��� ��� �� ���. ����� ���������. ������ ����, ��� �� ������ ����� ���, � ������� �� �������� ������ ����� ������, � ������ ����� �� ����� ������.";
			link.l1 = "��� �� ��������? � �� � �� ���� ��� �� �����.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "��������� �����, ������� ���, ����� ������ � ���������� �������, ����� � �������.";
			link.l1 = "�������! �� ��� ����� �����, �������. �� �������!";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			DialogExit();
			AddQuestRecord("Caleuche", "8");
			int iTerms = sti(pchar.questTemp.Caleuche.Belizterms);
			SetFunctionTimerCondition("Caleuche_FergusCome", 0, 0, iTerms, false);
			npchar.quest.Caleuche = "true";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

