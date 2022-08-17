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
			// ����
			if(CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "valet")
			{
				link.l1 = "� ��� �������� �� ������ �����. �� ������ ������?";
				link.l1.go = "valet_1";
				link.l2 = "� ���������� �������� ������� '������'. �� ����������, ��� ��� �����?";
				link.l2.go = "valet_2";
			}
                                                          // ������������ �����
			if (pchar.questTemp.MC == "toSeekSister")
			{
				link.l1 = "�������, � ��� ���� ���� �� ����� �������� �������. �� � ����� �� ������?";
				link.l1.go = "MCLiz";
			}

			                    // ��������� -->

			if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "ObsessionTakeCoin" && !CheckAttribute(npchar, "quest.ObsessionTakeCoin"))
			                   {
			Link.l1 = "� ���������� ��������������� ������ ʸ���.";
			Link.l1.go = "ObsessionTakeCoin";
				break;
			                     }
			                    //<-- ���������
		break;
		
		case "valet_1":
			dialog.text = NPCStringReactionRepeat("���, �� ����, ��������. ��� ��� ����� ������ �� ����.", "� ���� ��� ������ - �� ����!", "�� ����, ��� �����������?", "�������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������. ����� ����...", "����. � �����, �� ���������...", "�� ������� �! ������ �����������...", "��...", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		case "valet_2":
			dialog.text = NPCStringReactionRepeat("�, ��� �� ������ ����� ������! �� ������� ��� �������� �� �����. ������� ��� ���.", "� ������ ��� ���� �������. ��� �� ��������?", "�� ����, ��� �����������?", "�������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������!", "��-��, ������.", "�� ������� �! ������ ������������...", "��...", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;

                                                          // ������������ �����

		case "MCLiz":
			dialog.text = "���������� ��� ������� - ���������� ������ ������. � ��� ��� ����� �� ���?";
			link.l1 = "���������, ��� ���-��� ������ � ������ ���������...";
			link.l1.go = "MCLiz_1";
		break;
		case "MCLiz_1":
			dialog.text = "��, ��� � ��������� ����� ���-�� ����� ����� ��������������. � ������ �� � �� �������.";
			link.l1 = "� ������ ��� ���?";
			link.l1.go = "MCLiz_2";
		break;
		case "MCLiz_2":
			dialog.text = "������ � ���� � ����.";
			link.l1 = "� ��� ����������� ���?";
			link.l1.go = "MCLiz_3";
		break;
		case "MCLiz_3":
			dialog.text = "��, ��� �� ����.";
			link.l1 = "� ��� �� ����?";
			link.l1.go = "MCLiz_4";
		break;
		case "MCLiz_4":
			dialog.text = "��, �� ���� ����� ���������������� �� �������, �� ��� � ��������.\n"+
				"������� �� � �������� ��������? ���? ��-��, ����� ������, ��� ������� ��������, ������� ��� ����� �� ����� ������� ������������, � ���� ���� ���. � ���� �����, ����� �� ��� ��� ���, ������� ����� ������ ��� �������� ������, ��� ��� ������ ����-���������� ��� �������.";
			link.l1 = "�������� ����� ������� �������.";
			link.l1.go = "MCLiz_5";
		break;
		case "MCLiz_5":
			dialog.text = "��� ������� ��� �����. ����� �� ��������� � ������ � ������, �� ���� ������ �������. ����� ��� ������� ������� ����� ������. ���, �� ������ ������...";
			link.l1 = "� ��� ������ ����� ����?";
			link.l1.go = "MCLiz_6";
		break;
		case "MCLiz_6":
			dialog.text = "��, �� ���� ���������� ����� ��, �� �������. ������� �����-�� ������ ��������� ���� �� ��� ����� � � ����� ������� �����. ����� ��� ��� ׸���� ������ ����� �������� ���... � ������� �������� ����� ����-�� ������ ����� � ������. �������, ��� ����� � ������ �����, � ��� ����� �����, ��� �� ������ ���� �����... ��� ����� ����... � ������, ����� ��� ����, �� ���������� ���� ��� ���� ���.";
			link.l1 = "������?";
			link.l1.go = "MCLiz_7";
		break;
		case "MCLiz_7":
			dialog.text = "������� ������ ���.";
			link.l1 = "�������. �� ��� ��, ������� ����, ��������.";
			link.l1.go = "MCLiz_8";
		break;
		case "MCLiz_8":
			dialog.text = "�� �� ���. �������, �� �������� ��� ������� �������. ��� ������� �������, �������...";
			link.l1 = "�� ������ ������, ������ �������. ��� �� �����.";
			link.l1.go = "exit";
			pchar.questTemp.MC = "toSeekSisterAT";
		break;

		//********************* ��������� *********************

		

		//********************* ��������� *********************

		case "ObsessionTakeCoin":
		dialog.text = "������ ʸ��� ���������� ��� ��� �����. � ��� �� ��� �����������!";
		 link.l1 = "��� ��� �����, �� ��� ���������, ��� ���?";
                                           link.l1.go = "ObsessionTakeCoin_1";
		 break;

		case "ObsessionTakeCoin_1":
                                          TakeNItems(pchar, "Grog", 1);
                                          Log_Info("�� �������� ������� �����");
                                          PlaySound("interface\important_item.wav");
		dialog.text = "��� ���, ��� ������� � �� �����. ����� ������ ������, ������ �� �������� �� ��������, ��� �� ��� � ������� ���������. ��� ������, ����� �� ������, ������ �������� ��������.";
		 link.l1 = "���������, ��������.";
                                           link.l1.go = "exit";
		 npchar.quest.ObsessionTakeCoin = "true";
		 AddDialogExitQuest("GothicObsession_cemeteryman");
		 break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

