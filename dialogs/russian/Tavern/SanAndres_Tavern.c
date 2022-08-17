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
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_sailorSanAndres" && !CheckAttribute(npchar, "quest.APS_SailorSanAndres"))
		{
		link.l1 = "��������, �������, �� ��� �� �� ���������� ��� ���-������ ��� ���� ������, � ������� � ������� �����" + GetSexPhrase("","�") + " �� ����� ��������?";
		link.l1.go = "SailorSanAndres";
		}
		break;
		case "SailorSanAndres":
		dialog.text = "�-�, �� � ��������� �������! �� ��� ��� ����������, �������� �������. ���� �������� ������ ����, � ��� �������� �� ��������, ��� �������, ��� ����� ������� � ��������� � ����� ������� � �������. ������ ���� ���� � ����!";
		if(sti(PChar.money) >= 1000)
		{
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneytoCharacter(PChar, -1000);
		link.l1 = "������� ����, " + NPChar.name + ", ������ �� ��� 1000 ����, � ���� ����� ����� ������������ ���� ��� �� - ������� ��������.";
		link.l1.go = "exit";			
		}
		else
		{
		link.l1 = "������� ����, " + NPChar.name + ".";
		link.l1.go = "exit";
		}
	                     npchar.quest.APS_SailorSanAndres = "true";
	                     sld = characterFromId("ApostatesRK");
	                     sld.Dialog.CurrentNode = "second_168";	
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

