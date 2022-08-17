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
			if (CheckAttribute(PChar, "questTemp.Guardoftruth.Archy") && pchar.questTemp.Guardoftruth.Archy == "islatesorotavern")
			{
				link.l1 = "��������, "+npchar.name+", �� ������ �� ������ ��� �������� �� ����� ������ ������? �������, ��� ������� ������ � ���� ������...";
				link.l1.go = "guardoftruth";
			}
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "��������, "+npchar.name+", �� �� ����� � ��������� ����� �� ���� ������ ������ ������?";
				link.l1.go = "tieyasal";
			}
			if (pchar.questTemp.piratesLine == "PL5Hunter_toBermudes")
			{
				link.l1 = "� ���� � �������, ���� ������ �� �������?";
				link.l1.go = "StepPL5Berm_1";
			}

			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "��������, ��������, ������ �� ������ � ������� ����������� ��� ���� '������ ��������'?";
				link.l1.go = "BlueBird_1";
			}
                                                          // ������� ��� �������
			if(PChar.Gothic_Delivery == "12")
			{
				link.l1 = "������, � ��� ��� ������ ��������, ��� ��� ����, �� �� ��������� �����?";
				link.l1.go = "GothicLine_Delivery_1";
			}
		break;

		// ������� ��� ������� -->
		case "GothicLine_Delivery_1":
			dialog.text = "��. ��� ���������. ���, �� ����������. ����� ����, �������, �� ������ ������ ��� ����� ���� ����������� ���� �������. ��� �� ��� �� ��������������, ����� ���� ������.";
			link.l1 = "��, �����. �����, ����� ������.";
			link.l1.go = "GothicLine_Delivery_2";
		break;
		
		case "GothicLine_Delivery_2":
			dialog.text = "� ����� �� ���� �����-��?";
			link.l1 = "� ���� � ���� ���� �������.";
			link.l1.go = "GothicLine_Delivery_3";
		break;
		
		case "GothicLine_Delivery_3":
			dialog.text = "�������, ��������? ��, ���� ������ ���, ��� ������� ��������.";
			link.l1 = "���-���, � ��� � ����. �����, �� �������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithBermudesBarmen");
		break;
		// ������� ��� ������� <--

		//���� ������ ��������
		case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("������-�� ����� �������. � �������� �������, ��� ������� ����� �������. ������� ��������, �� ���� ���...", 
				"�� ��� �������� �� ����.", 
				"�����? ��� ��� ��������.",
                "��������, ���� ��� ������ ������ �� ����, ��, �������, ������� ������� ���������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("� ��� ������� �������?", 
				"��, �����...",
                "��, �����.", 
				"������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
		break;

		case "BlueBird_2":
			dialog.text = "������ ��������, �� ����������, ��-��!!";
			link.l1 = "� ���-������ ������ ���� ��������? ��� �� ����� �����, � �������.";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "��� ����� � �����, � ����-������. �� �������� � ����� ����� '������ ��������' ������ ���, �� ��� � ������ �� ��� ������� �� ������� ������ - � �������� �� ���!";
			link.l1 = "��� ������ ���... �� ��� ��, ����� ������. ������, � ������ �������� �������, �� ��� �� �������?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "������������ ������, ��������� ����� ���������.";
			link.l1 = "�������... � ���� �������, ������� � ��� �� � ����� ������� ����������?";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "����������� ������ � ���� ���. �� ��� ������ ������ ��������, �����, ��� �� ���� �����, ��-��...";
			link.l1 = "�� ���������� �� ��, ��������, ���� ���������� ���� ������ ������ ��������?";
			link.l1.go = "BlueBird_6";
		break;
		case "BlueBird_6":
			dialog.text = "������ �, ��� �� ���������� � ������-��������, ������� ��� ���� ���������� � ������ �� ������������.";
			link.l1 = "������� ���� �������, ��������. �� - ������� ����������.";
			link.l1.go = "BlueBird_7";
		break;
		case "BlueBird_7":
			dialog.text = "������� �� ����������, " + GetAddress_Form(NPChar) + ". ����� ���!";
			link.l1 = "� ���� ����� ��������, ��������.";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "3");
			pchar.questTemp.BlueBird = "toPuertoPrincipe";
		break;
		
		case "guardoftruth":
			dialog.text = "������. ���� ��������� ��� ������ ����� �������, ����� ��� ��� ��� ������, ������������� �������, ������. ��, ����� �������� ���� - ����������...";
			link.l1 = "��� ������: ���������� �� ������� ������� � ��������� ��������� �������� �� ����������� �����? � ��������� �� '�����-��������'?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "������ ������� � �������� �� ���������� ����, � ��� ��������� �� ��-�������: '���-������'. ����� ����� ���� ������ �� ���� ������� ����� ����������.";
			link.l1 = "�� ������, ��� '���-������', � �� '�����-��������'? � ����� ���� ��������� ������? � ������ �� ������ ������ �����������?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "���������� ������, ��� '���-������', ������ ��� � ����� ����� �� ����� �������� � �����, ��� ��� ��������� �������� ����� � ���� ���������� ������ �� �����. ����� ������ ������ ���� ������ '�������' - ���� ����� ���������� ��� ������ ��������\n����� �� ��� ��������� �� ����, ��� ��� ���� ����� ����, ����� 1654 ����. � ������ � ������ ���� ������ �����������? �� ������ ��� ���� ������� �� ����� � ���������� �������� �����, � ���� �����������. ������ �������� ����� ��������� � ������� � ����� �� ������ � ����� ���-����, �� ��� ��� �� ����� �����������\n����� ����������� ���� ������� ��������, ������� ���� � �������, ���������� ��� � ��������. � ��� ���������� ������� - ������� '���-������' �� ���� ������. ����� ������� �������, � ������ - ������. � ���������� ��� ������� ������ ����������, ��� ������ ��� �������� � ��� � ��������, ��� ���������� ��������� ����� ���-����.";
			link.l1 = "��� ��� ��������� ���� �������� ���� �������! ����� ���������! �����, � ��� ����� ��������� ����� 1654 ����? �����, ���-���� ������? � �� ���� �� ���� ������ ������ ������������� �������?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "����� �����... �� ���� ��� �����, �����, � ������. � ����� �� �����. � ����������� ������ �� ��� - ������ ���������, � ��������.";
			link.l1 = "� ��� ���� ��������-������ ������?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "��� ������ �������... ����� ����� ������, ��� ���������� ���� �� �����: �� ����� ����� ��� �������� - ������ ���, �������, ����������, � �������� �����, � ��� �� ����-������ ����� �����, ��� ������� ������ � �� ���� � ���������� ������\n�����, �� ��������� ������ �����, ����� �� ���� � ������� �������, ������� � ���� ���� ������ �� ���� � ������ �������� ����. �� ��� ��� � ��� �� �����, �� ����. � ������ ��� ������� ����� ������ ������� ���������.";
			link.l1 = "� ��� ����� ���� ��������?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "�� ���, ������� �� ������ ��� ����� ���������? ���������, ������� ������ �� ������, ������� �����, ������� ������������ �����, ������� ������ ���������� �����. ������, �� ��� � � ��������� ������� �����-�� ������. � �����, ����� �������� ������. ����� � ������� ������ �������, � ������� � ���� - �� ����� '�������'.";
			link.l1 = "����. �� �� ������, ��� ������ ������?";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "������� �� ����. ����� ��� ��������� � '��������' � ������ ��� �� ���� ������ �� ����� � ������ � ��� �� ������.";
			link.l1 = "�����, "+npchar.name+", ������� �� ��������� ����������! �� ������������� ���������! �������� �� ����� �����... �����!";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "�����, "+pchar.name+"!";
			link.l1 = "...";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			DialogExit();
			AddQuestRecord("Guardoftruth", "60_1");
			pchar.questTemp.Guardoftruth.Archy = "guadeloupe";
			// ��������� ����������
			pchar.quest.GuardOT_cabinattack.win_condition.l1 = "EnterToSea";
			pchar.quest.GuardOT_cabinattack.function = "GuardOT_PrepareCreateBandosInCabin";
		break;
		
		case "tieyasal":
			dialog.text = "�� ��, ������, ���� �� ������� ���������, ��������. ��, ������ ��� ���, �����, ��� ��� �� ������ ������. � ����� ��� �� ���������� � ���� - ����� �� � ��������� ��� ��� � ���������.";
			link.l1 = "���� ������! ��� ��� �������... � ��� ������ ������?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "������� �� ����. �� ���� � ����, � ����... �� ����� ���-�� ������� � ��������. ��������, �� ����� ����������, �� �����.";
			link.l1 = "��� �� �� ��� � �������� ��������?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "���. � ����� ���� ������� ���, ��� ����� ���� �� �����.";
			link.l1 = "����. �� ��� ��, �������, �������!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			AddQuestRecord("Tieyasal", "3");
			npchar.quest.tieyasal = "true";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
		break;

		//�������, ����� �5, ���
		case "StepPL5Berm_1":
			dialog.text = "�� ���, ������ ��� � �������. �������, ��� ����� ���� ����, � ����. ";
			link.l1 = "� ��� �� ���� ���� ���� �������?";
			link.l1.go = "StepPL5Berm_2";
		break;
		case "StepPL5Berm_2":
			dialog.text = "���, � ����������� ���� � �������� ������� �� �����. ��� ������� �� �������, ������ ������ ���. ��� � �������...";
			link.l1 = "�������, �� ��� ������� �����!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_5_Hunter", "10");
			pchar.questTemp.piratesLine = "PL5Hunter_toOrryHouse";
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}