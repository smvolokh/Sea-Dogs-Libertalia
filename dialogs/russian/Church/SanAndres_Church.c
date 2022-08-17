// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������, "+ GetSexPhrase("��� ���","���� ���") +"?", "���������, � ������ ����..."), "� ������ ����, ������, "+ GetSexPhrase("��� ���","���� ���") +"...", "� � ������ ��� ������ ����, "+ GetSexPhrase("��� ���","���� ���") +": ������� ���� ������.",
                          "������� ������������ � �����������������, � ��� ��� � �� ���������, "+ GetSexPhrase("��� ���","���� ���") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "�� ������, �����..."), "��, ���� ����� � ������ �������...",
                      "�����, �����... ������ �����...", "��������, ������ ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		// ���������� ����
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_sailorSanAndresChurch" && !CheckAttribute(npchar, "quest.APS_SailorSanAndresChurch"))
		{
		link.l1 = "���� ��� � ���. � ����� �� ������ � ������������ � ����� �������� ������� - ��������� �������. ����� ������������ � ��� �������� ������� �� ��������� � ����� ������ �������� ���������.";
		link.l1.go = "SailorSanAndres";
		}
		break;

		case "SailorSanAndres":
		dialog.text = "� �������, � ��� ���� ����. � ����� ��������� ��� � ����, ���� ��� ����� ������ ���� ���� ������� ��� ���������, ���� ������������� � ��� ��������, � ������� �� ��������" + GetSexPhrase("","�") + ". � ������� �� ��� ���, �� �������� �� ���� ��� �� �������.";
		link.l1 = "� ��� �� ��� ������?";
		link.l1.go = "SailorSanAndres_1";
		break;
		
		case "SailorSanAndres_1":
		dialog.text = "�� ������� ��������, �������� �� ��������!";
		link.l1 = "�������, ������ ����, ��� ���� ������� ������ �� �������� ��� ����� �������?";
		link.l1.go = "SailorSanAndres_2";
		break;
		
		case "SailorSanAndres_2":
		dialog.text = "�� �������� � ����� �����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "? � ��������� ���� - ������ ������ ��� �� ���������. � � �� ����� ������ �� ������� ���� ����������� � ���� ��������!";
		link.l1 = "������ ����, � ���� ����������� � �����������.";
		link.l1.go = "SailorSanAndres_3";
		break;
		
		case "SailorSanAndres_3":
		dialog.text = "�� ��� �, � ���� - ��� �� ���������� ����. ���� ������" + GetSexPhrase("��","���") + ", " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", � �� ������� ������� ������! ������� � ��� ��������� ��� ���� �������.";
		link.l1 = "��� ���� �������! ��� ��� ��� �����, ��� ��������?";
		link.l1.go = "SailorSanAndres_4";
		break;

		case "SailorSanAndres_4":
		dialog.text = "����� �� ��� � ������, � �������� � �������� �������, ������ � ������� ������ � � ����� ������� �� ���� �������.";
		link.l1 = "�������, ������ ����!";
		link.l1.go = "exit";
	                     npchar.quest.APS_SailorSanAndresChurch = "true";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_14");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}



