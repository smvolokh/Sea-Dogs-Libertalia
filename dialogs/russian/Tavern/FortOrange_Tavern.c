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
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "� ��� � ������ �� ��������� ����� ������� �������? ��� �� ����� �����.";
                link.l1.go = "Jamaica_ratF_1";
            }

	// ==> ������ � ����� ����
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "SmithyTavern" && !CheckAttribute(npchar, "quest.SmithyTavern"))
			{
                link.l1 = "��� ����� ������ ������ ����, �� ������ ��� ����� ������� � ����� ������� �� ������ �����. ���� � ���������� � ���?";
                link.l1.go = "Smithy_1";
			}
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "SmithyTavern2" && !CheckAttribute(npchar, "quest.SmithyTavern2"))
			{
                link.l1 = "��� ����� ������ ������ ����, �� ������ ���� �����. ���� � ���������� � ���?";
                link.l1.go = "SmithyTavern2_1";
			}
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_4")
            {
                link.l1 = "��������, �������: ������� � ����-������ �������� ��� ����� ������������ ����������� ����... ������ ����� ����, ������ ��������. � ������������, ��� �������� ����� ����� ���������� � ����� ���������. �� ����������, ��� ��� �� ���������? � ���� � ���� ������� ����������� �������.";
                link.l1.go = "mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_5" && GetCharacterItem(pchar, "gold_dublon") >= 50)
            {
                link.l1 = "� ������ ���� ��������� ��������. ����� � �����������.";
                link.l1.go = "mtraxx_4_1";
			}
		break;

		case "Jamaica_ratF_1":
			dialog.text = "���������. ������ � ���� ������� ��������� ����. ���������������� ���, � ��� �����. � ����� ����, � ������ ������������� - ����� �������� � ����� ��������, ��� ��������. �� ���� �� �� ��� ������?";
			link.l1 = "���, �� ����. � ������ � ������� ������ �����, ��� ������. ��� ��� ��� �����? �� � ��� ������������ ����� �� ���� �����, � �� ��� ������ ����� ����������!";
			link.l1.go = "Jamaica_ratF_2";
		break;
		
		case "Jamaica_ratF_2":
			dialog.text = "���� � ���� �� ����� �������. � ���� - �� ����. �� ��� �� ����������.";
			link.l1 = "��, ����! ��� � � ������ ��� ������ ����?";
			link.l1.go = "Jamaica_ratF_3";
		break;
		
		case "Jamaica_ratF_3":
			dialog.text = "�� ����, "+ GetSexPhrase("�������","���") +". ���� - ��������� ��.";
			link.l1 = "�����, ��� �������. �����, � ���� ��� �����������...";
			link.l1.go = "exit";
			AddQuestRecord("Slavetrader", "21_4");
			pchar.questTemp.Slavetrader = "FindRatJamaica_H";
		break;

        //********************** ������ � ����� ���� **********************
                                                         case "Smithy_1":
			dialog.text = "�, ������ ����! �������, �� ������ ����� ��� �������. ������ ������, ��, �������, ��� ���. �� ���� ������� " + GetFullName(pchar) + ", �����? �� ��� ���.";
			link.l1 = "��, " + GetFullName(pchar) + ". ������� �� ������. ����� ��������.";
			link.l1.go = "exit";
		                   pchar.questTemp.GothicSmithy = "Smithy_DavidSmith";
		                   npchar.quest.SmithyTavern = "true";	                               
			AddDialogExitQuestFunction("Gothic_Smithy_Tavern_1");
LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2_back", false);
				LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2", false);
		                   break;

                                                         case "SmithyTavern2_1":
			dialog.text = "�, ������ ����! � ��� ���...";
			link.l1 = "��� ����, � ��� ��!";
			link.l1.go = "SmithyTavern2_2";
		                   break;

                                                         case "SmithyTavern2_2":
			dialog.text = "������� �� ����, ����� ���� ������ �� ������. ����� �������� � ���� ����� ���.";
			link.l1 = "...";
			link.l1.go = "SmithyTavern2_exit";
		                   break;

                                                         case "SmithyTavern2_exit":
		                   DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.GothicSmithy = "Smithy_DavidSmith";
		                   npchar.quest.SmithyTavern2 = "true";	                               
			AddDialogExitQuestFunction("Gothic_Smithy_Tavern_4");
		                   break;

		// Addon 2016-1 Jason ��������� �������
		case "mtraxx":
            dialog.text = "���, ���� �� ��������� �� ������ �����, ��� ������� �������� - �� ���������� ��������, � ����� ����, ��� �� ����������� ������ �� �������. ��������������� �  ��� ��� ������ ������, ���, ������� �� ������. �� � ������ ��������� � �������-��-��� ����� �� ���������� - ��� ����� ��������� ������ ��������, ��-��! ��� ��� ������ ����.";
			link.l1 = "�� ���-�� �� ��� ���� �������� � ����-������. ��� ����. ���� � ���� �����-�� ����� �� ���� ����, ��� ���� ����������?";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
            dialog.text = "��������, �������������� � ����-������? ��� ������ �������? ����������� ��������� � ����� �����������... ��! ������� � ���� ���� �����������, ��������. ���� ���� ��������� �� �������, ������� ����� ��, ��� �������� � ����� ���������� �����. ���� ��� � �� ���� �� ��������� - �� ������ � ��� �������� ��������.";
			link.l1 = "�������! � ����� ����� ����� ����� � ��� ��� ������?";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
            dialog.text = "���... ��� � ������� ��������� ��� ���, �� �� ����� �� ����������...";
			link.l1 = "�����, ������� ������� ������� ���� ������?";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "�������, ��... ���� �������� �������� ��������� ������� � ���� ��������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 50)
			{
				link.l1 = "�������. ���, �����.";
				link.l1.go = "mtraxx_4_1";
			}
			else
			{
				link.l1 = "�������. � ��� �������...";
				link.l1.go = "mtraxx_4_2";
			}
		break;
		
		case "mtraxx_4_1":
			RemoveItems(pchar, "gold_dublon", 50);
			Log_Info("�� ������ 50 ��������");
			PlaySound("interface\important_item.wav");
            dialog.text = "���� ����� ����� �������. �� ������ ��� ����� ������ �� ������, � ����-������ ������ ������ �����. ������ �����, ����� ����� �������� ����������, �� ��� ��� ��� ���� ������ �� ��� ����� ������� � ������ ���������� ������ ������, ������ �� ���� � ������ ������ �� ��������� ������. �� ������ ������� ������� �� ���� ������ ������ ������ �����, ����� ���������� ����� � ��������\n��� ��� � ���� � ������� ������. �� ����� ����� ����� ��������� ��������� �������, �� ����� ��������� �����, �� ������ �� ����� ���������� ����������� ������ - ������ �������, ����� ��������� � ���-�������� ����������� - � ������� ������ �� ������ ��������� � ����� ����-�����. ��� �������� ���������� '������� ����'.";
			link.l1 = "�������, ��������. �� ������ ��������� ���� ������.";
			link.l1.go = "mtraxx_5";
		break;
		
		case "mtraxx_5":
            dialog.text = "�����, �������. �������, �� ������� ��, ��� �����.";
			link.l1 = "...";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_4_2":
            DialogExit();
			AddQuestRecord("Roger_2", "6");
			pchar.questTemp.Mtraxx = "silk_5";
		break;
		
		case "mtraxx_6":
            DialogExit();
			AddQuestRecord("Roger_2", "7");
			pchar.questTemp.Mtraxx = "silk_6";
			pchar.quest.mtr_negril.win_condition.l1 = "Timer";
			pchar.quest.mtr_negril.win_condition.l1.date.hour  = 12+rand(12);
			pchar.quest.mtr_negril.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2+rand(3));
			pchar.quest.mtr_negril.function = "Mtraxx_CreateBilly";
			SetFunctionTimerCondition("Mtraxx_BillySeaTimeOver", 0, 0, 7, false);
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
