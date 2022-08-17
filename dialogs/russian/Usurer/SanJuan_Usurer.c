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
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurer" && !CheckAttribute(npchar, "quest.APS_usurer"))

			{
			link.l1 = "���� � ��� �������� �������� �������.";
			link.l1.go = "ApostatesAPS1";
			}
			break;

			// ���������� ����
			case "ApostatesAPS1":
			dialog.text = "�, ��� ��, ������� �����. �� ��� ������� �������! ������� �����, ��������� ������� �������� ���� �������� � ����� �� ���������, �������� ������� ������ �������� �� ���� �������, ������ ������� � �� ���� ���������, ����������� ������ ��������.";
			link.l1 = "�� ������ ��������� ��� ������� ����� � ����� �������? ��������� ��������� ���������� �� ��������.";
			link.l1.go = "ApostatesAPS2";
			break;
				
			case "ApostatesAPS2":
			dialog.text = "��������, ��� ��� ����������� ����� �������� � ������. ��������, ��� �� ��� ��� �� ��������, ����� ��� �� ������������, ������" + GetSexPhrase("","���") + " �������.";
			link.l1 = "����������, ��, � ������� �� ����������.";
			link.l1.go = "Exit";
			npchar.quest.APS_usurer = "true";
			AddDialogExitQuest("GothicApostates_APS_church");
			break;
					
			
		break;

	

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

