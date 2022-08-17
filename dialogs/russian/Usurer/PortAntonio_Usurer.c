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

	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurerSavLaMar" && !CheckAttribute(npchar, "quest.APS_usurerSavLaMar"))
	{
		link.l1 = "�� �� � �����, ���� ��� ����������!";
		link.l1.go = "ApostatesAPS_1";
	}
	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_BankSavLaMar" && !CheckAttribute(npchar, "quest.APS_BankSavLaMar"))
	{
		link.l1 = "� ���� ������������, � ����� �������� ����� �����!";
		link.l1.go = "ApostatesAPS_4";
	}

		break;

	// ********************* ���������� ���� ******************

		case "ApostatesAPS_1":
		dialog.text = "�������, ���� �������� ������� �������� ����� �������, ������� �� ������ ������ ���� �� ����� ��������.";
		link.l1 = "�� ������ ���� ��� ����� ����!";
		link.l1.go = "ApostatesAPS_2";
		break;
		
		case "ApostatesAPS_2":
		dialog.text = "����, �� � �� ���� ��� ��� �������, �� ��������.";
		link.l1 = "������, �� ������ �� �� ���� � ����, ���� ���� �������� ������� ���� ����� ��� ������ �����.";
		link.l1.go = "ApostatesAPS_3";
		break;
		
		case "ApostatesAPS_3":
	                     ChangeCharacterComplexReputation(pchar, "nobility", 5);
		dialog.text = "��������, � �� �����. �� ����� ������ �� ��� ������� � ���� ��������� ���������� ���� �������. � ��� ���� ����� ������� ��� ����� ������.";
		link.l1 = "��... ������� �� �����.";
		link.l1.go = "Exit";
	                     npchar.quest.APS_usurerSavLaMar = "true";
		AddDialogExitQuest("GothicApostates_APS_SavLaMarfrom");
		break;

		case "ApostatesAPS_4":
		dialog.text = "�� ���� ��������, ��� �� ��������� ���� ���������, ������ � ��������� ������ ������� � �� � ��� �� �������.";
		link.l1 = "....";
		link.l1.go = "Exit";
	                     npchar.quest.APS_BankSavLaMar = "true";
		AddDialogExitQuest("GothicApostatesAPS_BankSavLaMar");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

