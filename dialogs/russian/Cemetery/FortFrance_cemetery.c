// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� ��� ������?", "��� �� ������ ������?"), "��� �������, ��� �� ��� ����������, " + GetAddress_Form(NPChar) + "?", "������ ��� �� ������� �� ��������� ������ ������...", "��, �� ���� �������. �������� ��� ���!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � �����������. ��������...",
                      "�� ��, ������������� � ������ ���...", "���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.GothicLee") && pchar.questTemp.GothicLee == "SeekBible_crypt" && !CheckAttribute(npchar, "quest.SeekBible"))
			{
				dialog.text = "� ������ ���� ��� ����!";
				link.l1 = "��� ����� ������� � �����, ��� ��������� � �������?";
				link.l1.go = "Gothic_3_1";
			}

		break;

        //********************** ���. ������� ��***********************

 		case "Gothic_3_1":
			dialog.text = "";
			link.l1 = "��, ���, �� ��� ������ ������?";
			link.l1.go = "Gothic_3_2";
  		break;
 		case "Gothic_3_2":
			dialog.text = "�����, ����� ���� ���� �����!";
			link.l1 = "�� ��� ��� �����? ��������� ����� ��������� �����������, � ��� ����� �������?";
			link.l1.go = "Gothic_3_3";
  		break;
 		case "Gothic_3_3":
			dialog.text = "��, �� ������, ��� ����� ������� �������������� �������, ����� ������� ������ �� �������, ���� � �� � ��� ��� �� ���� �� ���, ���� ���� ��� ��������� ��� �� ������ �� ��������� �������, � ��� �����?";
			link.l1 = "���������?";
			link.l1.go = "Gothic_3_4";
  		break;

		case "Gothic_3_4":
			dialog.text = "������, � ������ ����, ������� ����� ����� ���������� ������ � �� ����� ����������, � �� ����� ���������� ���� ������ ������� ������� �� ��������, ������ ���������� ������� ��� ����.";
			link.l1 = "�������.";
			link.l1.go = "Gothic_3_5";
  		break;

 		case "Gothic_3_5":
			DialogExit();
			pchar.quest.SeekBiblehour.win_condition.l1 = "locator";
			pchar.quest.SeekBiblehour.win_condition.l1.location = "FortFrance_church IM";
			pchar.quest.SeekBiblehour.win_condition.l1.locator_group = "reload";
			pchar.quest.SeekBiblehour.win_condition.l1.locator = "reload3";

			pchar.quest.SeekBiblehour.win_condition.l2 = "HardHour";
			pchar.quest.SeekBiblehour.win_condition.l2.hour = 23.00;
			pchar.quest.SeekBiblehour.function = "SeekBible_hour";
			npchar.quest.SeekBible = "true";
  		break;

	}
	UnloadSegment(NPChar.FileDialog2); 
}


