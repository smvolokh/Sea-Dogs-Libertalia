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
// ���������� ����
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_Tavern" && !CheckAttribute(npchar, "quest.APS_Tavern"))
			{
				link.l1 = "����� ��� ���-������ �� ������?";
				link.l1.go = "APS_1";
			}
		break;

		// ���������� ����
		case "APS_1":
		dialog.text = "�����, �� �������! ��� ��� �������� ���, ������� ������ - ������ �������.";
		link.l1 = "� �� ���� � �������...";
		link.l1.go = "Exit";
		npchar.quest.APS_Tavern = "true";
		AddDialogExitQuest("GothicApostates_APS_PuertoPrincipeTavern");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

