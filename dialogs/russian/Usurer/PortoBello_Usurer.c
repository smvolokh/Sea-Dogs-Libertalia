// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			// ���������� ����

			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerPortoBello" && !CheckAttribute(npchar, "quest.APS_usurerPortoBello"))
			{
				link.l2 = "���� �������� ���� �������, � ��� ������ ��������, �� ������ ���� ������� � ���������� �� ��������.";
				link.l2.go = "ApostatesAPS_1";
			}
			
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerPortoBelloOver" && !CheckAttribute(npchar, "quest.APS_usurerPortoBelloOver"))
			{
				dialog.text = ""+pchar.lastname+", �� ��������! ���� ������� ��� �������� � ���� �� ������ ����������, � ������� �� ����...";
				link.l3 = "...";
				link.l3.go = "Exit";
								 npchar.quest.APS_usurerPortoBelloOver = "true";
				AddDialogExitQuestFunction("GothicApostatesAPSCPortoBelloEND");
			}
			
			if(CheckAttribute(pchar, "ChurchQuest") && pchar.ChurchQuest == "to_PortoBello_Usurer")
	        {
				link.l4 = "�� ������ �������� �� ����� �������� �������, �� ��� ��?";
				link.l4.go = "ChurchQuest_3";
			}

			
			
		break;
		
		// ********************* ���������� ���� ******************

		case "ApostatesAPS_1":
			dialog.text = "����� ������, �������. �� �����, ��� ������� ����� � ���� �������� �������� ���������� � ��������. � �������� ����� ��������, ��� �� �� ����� � ������, ���� �������� �����.";
			link.l1 = "�������� �������! ������, � ������" + GetSexPhrase("","�") + " �������.";
			link.l1.go = "ApostatesAPS_2";
		break;
		
		case "ApostatesAPS_2":
			dialog.text = "��, �������, ������ �������� ���� ��������� � ������������ � �������. ��������� �����, ������ ���� ����� �����.";
			link.l1 = "������, ������, ��� ������� ������, ��� � ���� �������� � ���� 15000 ����.";
			link.l1.go = "ApostatesAPS_3";
		break;
		
		case "ApostatesAPS_3":
		    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			AddMoneyToCharacter(pchar, 15000);
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			dialog.text = "�������-�������, ��� ���� ������. ������, �� ������ ������ ������������ �� ������� ���� � ���� ��� �������� ��������, ��-��.";
			link.l1 = "���� � ���� ��������� ��������... �����, �� ������.";
			link.l1.go = "Exit";
			npchar.quest.APS_usurerPortoBello = "true";
			AddDialogExitQuest("GothicApostates_APS_wait");
		break;
		
		case "ChurchQuest_3":
		    dialog.text = "� � ���� �� ��� �����������?";
		    link.l1 = "�� ���, ����� � ��� ������������.";
		    link.l1.go = "ChurchQuest_5_1";
	    break;

	    case "ChurchQuest_5_1":
		    dialog.text = "� ��� ��?";
		    link.l1 = "�������, �� �������� ������ � ����� ��� �����-��, � �������, ��� �� ������� � ���� �������.";
		    link.l1.go = "ChurchQuest_5_2";
	    break;

	    case "ChurchQuest_5_2":
			dialog.text = "��� �� � ����� ��������?";
			link.l1 = "�, � ��� �������, ������ ������ ��������� � �������� ��������� ������ ����� �� ������ �� �������� �������.";
			link.l1.go = "ChurchQuest_5_3";
	    break;

		case "ChurchQuest_5_3":
			dialog.text = "���, � �-�� ��� ������?";
			link.l1 = "� ����, �� ����� ���. ����� ����, �� � �����, ��� � ���� ����� ���.";
			link.l1.go = "ChurchQuest_5_4";
		break;

		case "ChurchQuest_5_4":
			dialog.text = "�� ������ ����� �� ��� ������� �����, ������ ��� ���������.";
			link.l1 = "�������, � ��� �������.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_on_Beliz_search_Apius2");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

