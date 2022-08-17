// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "����� �������, " + GetAddress_Form(NPChar) + "...", "�������, �������... ����� ��������� ��������, " + GetAddress_Form(NPChar) + "?",
                          "����������, �� ������� ����� ������ ��������� �����?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("��� ��������...", "������ ��� �� � ��� ��������"), "��, �����...",
                      "��, ������������� ����� �����������...", "��, ������, ��������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "Killwork" && !CheckAttribute(npchar, "quest.Killwork"))
			{
				link.l1 = "�� ������ ������� ������������ - ����?";
				link.l1.go = "Killwork";
			}
		break;
		
			// ���� ��� �������-����
 		case "Killwork":
        	                  dialog.text = "�������, ���� �������� �� �����!";
		link.l1 = "�� �� ������� - ���������? ������� ������ � �����, ������ �� �����, ��� ���������� � �������� ����?";
    		link.l1.go = "Killwork_1";
		break;

                                      case "Killwork_1":
		dialog.text = "�, ������� - �� ������ �� �����!";
		link.l1 = "����� ����� ��� ������� ��� ������ ������ � �������?";
		link.l1.go = "Killwork_2";
  		break;

                                      case "Killwork_2":
		dialog.text = "��� ��� �� ����? � ��� ���� ��������, � ������ ����� ������ ��� � ����� ����� �� ������ �����������, ����� ���� ��� �������.";
		link.l1 = "�������, ��� ����.";
		link.l1.go = "exit";
		npchar.quest.Killwork = "true";
		AddDialogExitQuestFunction("KillworkRoseaugirl_1");
  		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

