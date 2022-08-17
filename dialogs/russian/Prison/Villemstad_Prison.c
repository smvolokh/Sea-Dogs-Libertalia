// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "��������, � ������.";
			link.l1 = "� ������. ��������.";
			link.l1.go = "Exit";
			//����������
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "������, � ��� ���������� ������� - ���������� ����������...";
                link.l1.go = "Portugal";
            }
		break;
		
		//����������
		case "Portugal":
			dialog.text = "����������. � ��� ����� ����? � ���� ����������� ������ ������������� ����������� ����-������� ��������, � �� - ������ � ����������� ���������� �����������. ���� �� �������� �������� ��� ��� ����������� ����� ������. ��� ��� ���� �� �������, ����� ��� ������� - ��� ����� ����, � ���������.";
			link.l1 = "� ������ �� ��� ����, ����� ��� �������.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "� ��� ���� ��, ��������� ��������?";
			link.l1 = "��� ����, ����� ������� ���!";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			pchar.quest.InMarigoResidenceOver.over = "yes"; //����� ������
			InterfaceStates.Buttons.Save.enable = false;//��������� �����������
		break;

//-------------------------------------------------------------------------------
//	�������� ������
//-------------------------------------------------------------------------------
		case "PrisonEscort_1":
			dialog.text = "����������, ������, �� � ��� �� ����� ��������� ��� ���������� �������.";
			link.l1 = "� ����� �����, ��������.";
			link.l1.go = "Exit";
			link.l2 = "�����, ��� �� ���, � ��� �������� ���� ������� ��� �����, ������ �� �� ���������� ��� �� ���� �����...";
			link.l2.go = "PrisonEscort_2";
			
			LAi_SetPlayerType(pchar);
			DeleteAttribute(pchar, "questTemp.PrisonEscort_quest");
			LAi_LocationDisableOfficersGen("Villemstad_prison", false);
		break;
		
		case "PrisonEscort_2":
			dialog.text = "���������, ���� � ���, ��� � ��������� ����� ���������� ��������� �� �������, ���������������� ����������� � �����. ���� �� ��������, ������ � ��������� ������ � ���, � ������ - ��, ��� � ��� �������, ������ ��� ������ ������� ���������, �� ������� ���� ��� ��������� ���� �������, ��-��-��-��, ������� �� ���� ���������?";
			link.l1 = "�� ������ ��������� ����, ����� �����, ������� ���� ����������?";
			link.l1.go = "PrisonEscort_3";
		break;
		
		case "PrisonEscort_3":
			dialog.text = "��� ������! ���������� �������� � �������� ���������� �� ������ ���� ������, �� ����������� ��� �� ����. ��������� ��� �������� ������ '�� �����', �� ��������������. ���������� ������ ������� �������, ������� ��������� ����� � �����������, �� �� �����.";
			link.l1 = "� ������ ��� ��� ��� �������? ��, ���������, �������� ����-������ ����� ��� �����������, ���-��, ��� � �����?";
			link.l1.go = "PrisonEscort_4";
		break;
		
		case "PrisonEscort_4":
			dialog.text = "������, ���� ��������� ���, ��� ����������� - �����! ��������, � ���� ���� ���������� �������� ��� �������� �������� ������� '������'...";
			link.l1 = "��� �������, ������ ������ �� ����������. � ���� ������� ����� ���� ������ - ������.";
			link.l1.go = "PrisonEscort_5";
		break;
		
		case "PrisonEscort_5":
			dialog.text = "���� ���������� ��� 15000 ����.";
			link.l1 = "� ��������. ��� ������ ���-���� ����� - ����� �� ������.";
			link.l1.go = "PrisonEscort_6";
			link.l2 = "�������� ��� ��������. �� ����� ��������� ����� � �� ������� ���������� �� ��� ��������, ��������.";
			link.l2.go = "Exit";
		break;
		
		case "PrisonEscort_6":
			dialog.text = "��� � �������! ���� ����� ��� � �������� ���������, �������.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("PrisonEscort_SartSearch");
		break;
		
		case "PrisonEscort_6a":
			dialog.text = "������������, ��� ��� � ���.";
			if(pchar.questTemp.PrisonEscort_quest == "sink_ship")
			{
				link.l1 = "������, � ���������� � ����� �� ���������� �������. ���, ��� ������ � ��������� � ����� ������ ��������...";
				link.l1.go = "PrisonEscort_8";

			}
			else
			{
			if(pchar.questTemp.PrisonEscort_quest == "Capture_ship")
				{
					link.l1 = "� ���������� � ����� �� ���������� �������. ������ ��� ������� ����� �� ��� � ��� ������ ������ �� ������� ��������...";
					link.l1.go = "PrisonEscort_7";
				}

			}
		break;
		
		case "PrisonEscort_7":
		dialog.text = "����, ����� ����... �����, ��� �� ���� ��� ������ �� �����, ��� ��� �������, � ���������, � ��� �� �������, ����� �������.";
		link.l1 = "�� �, � �����-��, �� ����� �� ��� � �����������, �� ��������.";
		link.l1.go = "Exit";			
		AddDialogExitQuest("PrisonEscort_failed");
		break;
		
		case "PrisonEscort_8":
		dialog.text = "��-��, ��-��... ��� ����� ���������� �������� �� ���� �����������! �� ��, ���� �� �����, ��� ���� ��������� 15000 ����, ����� �������.";
		link.l1 = "�� �������.";
		link.l1.go = "PrisonEscort_Exit";			
		break;

		case "PrisonEscort_Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();		
		AddDialogExitQuest("PrisonEscort_complette");					break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
