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

			//�������, ����� �7
			if (pchar.questTemp.piratesLine == "Soukins_toLaVega")
			{
				link.l1 = "������, � ��� ����� ������, �� ����������, ������� �� �� � ����?";
				link.l1.go = "PL_Q7_1";
			}
			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toLaVegaTavern" && !CheckAttribute(npchar, "quest.RevengeCorsair_toLaVegaTavern"))
			{
				link.l1 = "�� ���������� ���� ��������� ������?";
				link.l1.go = "RevengeCorsair";
			}
		break;

		case "PL_Q7_1":
			dialog.text = "���. ��� �� ����� ��������� ����� ��������� ������������. ��������� ��� ���, � ����� ��� �� �������... �������� ��� ������� �� ������� �� ����� �������, ���� ������������, �� ������� � ���� �����������. � ���� � ��������, ��� ������ ������.";
			link.l1 = "�������!";
			link.l1.go = "exit";
			pchar.questTemp.piratesLine = "Soukins_toLaVegaSea";
			SaveCurrentQuestDateParam("questTemp.piratesLine");
			AddQuestRecord("Pir_Line_7_Soukins", "2");
			pchar.quest.PQ7_FriendLinney.win_condition.l1 = "location";
			pchar.quest.PQ7_FriendLinney.win_condition.l1.location = "Hispaniola1";
			pchar.quest.PQ7_FriendLinney.function = "PQ7_FriendLinney";	
		break;

//********************** ����� ������� **********************

		case "RevengeCorsair":
			dialog.text = "�� ���� � ���� ��������� ���� �����, ������ ��� ������ ��������.";
			link.l1 = "���� ���� ��� � ���-��?";
			link.l1.go = "RevengeCorsair_1";

		break;

		case "RevengeCorsair_1":
			dialog.text = "��� ��� ��������� ��������� ��������, ��� ������ ������ � ��� ������ � ����. � ���� - ����������.";
			link.l1 = "�������!";
			link.l1.go = "exit";
		                  npchar.quest.RevengeCorsair_toLaVegaTavern = "true";
                                                      DoQuestFunctionDelay("Gothic_RevengeCorsair_1", 1.0);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

