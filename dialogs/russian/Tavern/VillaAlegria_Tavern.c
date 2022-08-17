// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����� ������� ����� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "�� ���, ����� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin" && sti(pchar.money) >= 3000)
			{
				link.l1 = "� ������, ��� � ����� ����� ������������ �������, ��� �������, ��� �� ����������� �� �����?";
				link.l1.go = "Consumption";
			}
			if (CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.Commandant") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "� ��� �� ������ ������� � ���������� �����?";
				link.l1.go = "Consumption_8";
			}
			if (!CheckAttribute(npchar, "quest.Consumption_1") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�����, ��� '����' ���� ���-������ �������?";
				link.l1.go = "Consumption_12";
			}

			// ����� ��������
	                                                    if(CheckAttribute(pchar, "MonbarTrader") && pchar.MonbarTrader == "FindShip")
                                                                         {
                                                                                                  link.l1 = "�� �������� �� � ���� ���������� '������'?";
                                                                                                  link.l1.go = "MQ_Trader";
                                                                          }
            	                                                     if(PChar.SpanishGenerosity == "5")
            	                                                   {
			                           link.l2 = "��������, �� �� ������, ��� � ���� ����� ������ ����������?";
			                           link.l2.go = "SpanishGenerosity_1";
            	                                                    }
		break;


		//--> ���� �������
		case "Consumption":
			dialog.text = "��������� ����������, ��� ��������� ���. ����� ��� ������ ��� ���, ���� ���������� ������� � ��������, ��� � ��� ���, ��� ������� ���������. � �� �� �����, �� ��������.";
			link.l1 = "�� �������? ������ �������� ������� �� ������ �������������� � �������� � ��� ���-�� ���������! ����� ����, ���� ���� ������ ���� ����������������?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "�������, ���, �������, ���������, �� ����������� ����� ���-�� �����. ����� ���, �������� �������, � ��� ������ ������������? � �� �������� � �������� � ������ ���������!";
			link.l1 = "������, ��� ��� ������ �����... ������ � � ���� ������ ��� ������, � �� � ����� ���� ���������� � ������, �� �����?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			AddMoneyToCharacter(pchar, -3000);
			dialog.text = "�� � ����������� �� ��, ������. ������ ��������� � �� ���� ����� ���������.(������) � ��� �� ��� ������ �� ��������� ���, ��� ���� ������� �� ������� � ����� �������. ���-�� ����� ������, ���-�� ���� ��� �������, �� ����������� ���� ���� ������ � ��� ������ ������ ����� ��� ����������� �������. ������, ��������� �������� �������, � ����� ������-������ - �� � ��� ���. ���, � ���...";
			link.l1 = "������... ����� ���, ��������? � ���, ����� ������ ��� � �� ����������?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "� ���� ��� ���� ��, ������? �� ���, ��� � ������, ������ ���� �� � ��� � ������� ��������, ��� ������� ��������� � �������. ��� � ������ ���� ������, ��� � ������ ������� � ����� ��� ������� ���-�� ������ ���� ������, �� � ��� ������ ���� � ��������� ������ - � ���\n������ ��������� ������ ���� ������ �� �������, � ������� � ��������� � ������ �������� �� ��������.";
			link.l1 = "�������, �� ��� ��� �������, �������� �� ��������� �������, ���� ��� ������, ��� �� ������, ������ ������� � �������� �����?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "������ �������, �� ��� ��� ���� ���. ������������ ���������, � ������ � ����� ����� �� �������, ���� ��� �� �������� ������. ��, ������ - ��������� ���� ���� ��������, ���������, ������� �������, � ������ �����. �� ������ � ��� ��� �� ������� '�� � ���������' ���...";
			link.l1 = "�� ���� '���� �����������'?";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			dialog.text = "����� ���. �������� ����� � ���� ��� ������� �� ���� � ����� � ��������� ���� �� ����, ������ ������ ���-�� �����. � ��� ��������, ��� ��� ������ ��������, ������� ����� ���-�� ��� �������, �������, ���, ����� �������� � ������\n������ ��� - '�������� � ������', �� �������. �, �� ������ ���, ��������, ��� '�������' �� � ����� ������, ��� � ��������� � ������� ��������� �����.";
			link.l1 = "�� ��� ������� ������ ������, ��� � ��� ������?";
			link.l1.go = "Consumption_6";
		break;
		
		case "Consumption_6":
			if (CheckAttribute(pchar, "questTemp.Consumption.Commandant"))
			{
				dialog.text = "������, ���� �� �������� �� ��, ��� �� ���������� ������ � ������� ��� ����, � ����� � ���, � ���. ����� �� ����� � � ������... � ���, �� �� ��� � ��� �����������.";
				link.l1 = "� ��� �� ������ ������� � ����������?";
				link.l1.go = "Consumption_8";
			}
			else
			{
				dialog.text = "������, ���� �� �������� �� ��, ��� �� ���������� ������ � ������� ��� ����, � ����� � ���, � ���. ����� �� ����� � � ������... � ���, �� �� ��� � ��� �����������.(�������� �����) ��, ����� �� ��� ������, ������, ������� ���� � ��� � ������ �������� � ������� ����� � ��������� ��� - ���, � ���! ������� �����, ������, ������� ��� ����������!";
				link.l1 = "������... ��. � ���� �������.";
				link.l1.go = "Consumption_7";
			}
			pchar.questTemp.Consumption.Contra = "true";
		break;
		
		case "Consumption_7":
			DialogExit();
			npchar.quest.Consumption = "true";
			AddQuestRecord("Consumption", "2");
		break;
		
		case "Consumption_8":
			dialog.text = "� ��� � ��� ��������? ���������, ������ �� ������ ���� ��� �����, ������� ��� �����. ����� �� ��� ��� ������� ���, � ������ �����, �� �����-�� ���������. �� ����, ������ �� � �� ����� ������ ������ �����. �������, � ��� �� �� �����, ��?";
			link.l1 = "���������, ��������... ���������. ���-������ ���?";
			link.l1.go = "Consumption_9";
		break;
		
		case "Consumption_9":
			dialog.text = "��, ��� ��� �������... ��������� ���������� ����������� ��������, ������� ������������ ����������� �������������. � ���, �������, ����� �� ����� ����� � ������, ����������, �, ������, � ������� ��������� ����������� � �� ������ ��������� ������ �� ������� ��� ����-������ ������\n� ���� ���� �������, �����, � ������, ��������� � ��������� �������� � �������� ��� ��������, � ��������� �� ��������� ������.";
			link.l1 = "�� ���� ���� �� �� ������ � ������, ���?";
			link.l1.go = "Consumption_10";
		break;
		
		case "Consumption_10":
			dialog.text = "��, � ������� �����, ������ � �������� ����� ��� ���������. �������, ������ ��������� ������ �� ����� � ���� ������������ � ������, � ��������� �������� ��� ���������, ��-��.";
			link.l1 = "���������, �� ��� ����� �����. �� �������, "+npchar.name+"!";
			link.l1.go = "Consumption_11";
		break;
		
		case "Consumption_11":
			DialogExit();
			if (CheckAttribute(npchar, "quest.Consumption")) AddQuestRecord("Consumption", "4");
			else AddQuestRecord("Consumption", "5");
			DeleteAttribute(pchar, "questTemp.Consumption.Commandant");
			pchar.questTemp.Consumption = "current";
		break;
		
		case "Consumption_12":
			dialog.text = "����? ������� �� ���? ��� �� ����� � ������ � ����� ���������� �������, ���, ���� �� ��������...";
			link.l1 = "��� ������ ��� ����������... ��������, �������� ��� '�������', �� ������?";
			link.l1.go = "Consumption_13";
		break;
		
		case "Consumption_13":
			dialog.text = "���� ���, �� ����� �� ����! ���, ����� ����, �� ������, �������! � ������, ������� ������ ����, �����!";
			link.l1 = "������-������, ������ �� �������� �� ���...";
			link.l1.go = "exit";
			pchar.questTemp.Consumption.AskJuan = sti(pchar.questTemp.Consumption.AskJuan)+1;
			if(sti(pchar.questTemp.Consumption.AskJuan) == 3)
			{
				pchar.quest.Consumption2.win_condition.l1 = "location";
				pchar.quest.Consumption2.win_condition.l1.location = "VillaAlegria_town2";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption_1 = "true";

		break;
		//<-- ���� �������


		// ����� ��������
		 case "MQ_Trader":
            dialog.text = "��. �� ������ ���� �����, �� ������� ����� ������� ������ �, ����� ��, ���������� �� ����. ������� ��� �������� ��� �������� ����� ������� �������.";
            link.l1 = "������� �� �����.";
            link.l1.go = "Exit";
            AddDialogExitQuest("TraderQuestMonbar_ContinueSearch_3");
        break;


        // ��������� �������� -->
	case "SpanishGenerosity_1":
		dialog.text = "����� �� ���� ������. ���������� ������� ����-�� ����-������ ���� �����. ����, � �� ����.";
		link.l1 = "� ����� �������� � ������� ����������?";
		link.l1.go = "SpanishGenerosity_2";
	break;
		
	case "SpanishGenerosity_2":
		dialog.text = "� ���� ������� ������� ''���������''.";
		
		if(sti(PChar.money) >= 1000)
		{
			AddMoneyToCharacter(PChar, -1000);
			link.l1 = "�������, ��� ����� 1000 �������, �� �� ��������.";
		}
		else
		{
			link.l1 = "�������, � ��������� ��� ����� ���� ������������� - ������� ����� ��������, ������ ��-����...";
		}
		
		link.l1.go = "exit";
		PChar.SpanishGenerosity = "6";
	break;
        // <-- ��������� ��������



	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

