// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "��������� ����� ���� �����, �������� � ���� � ��������, �� �������� ������ �����-�� ������...", "�� ������� ������ ������. ��� ��������� ����, � �� ������ ��������� �����...",
                          "����� �������? ����� ����� ��������� ��������?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "������ ��� �� � ��� ��������"), "��, �����, �������... �������� � ��������...",
                      "�� ��, ������������� � ������ ���...", "��, ����� � ���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			if(PChar.DestinyGift == "23" && PChar.DestinyGift.FindFiveChapter.Havana == false)
			{
				Link.l1 = "�������� ���� ���-������ �������� � ������������ ���������, �������� ''�����������''?";
				Link.l1.go = "DestinyGift_1";
			}

			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�����, ��� '����' ���� ���-������ �������?";
				link.l1.go = "Consumption";
			}
		
		break;
		
		
		// ר���� ������� - ������� ������ -->
		case "DestinyGift_1":
			dialog.Text = "��� �� ������? ������������ ���������?";
			Link.l1 = "��. ��� ��������, ��� �� ������ ���.";
			Link.l1.go = "DestinyGift_2";
		break;
		
		case "DestinyGift_2":
			dialog.Text = "�� ����. ������������ ����� ����� ��� ����� ���� � �����. ��� �������� � ����, ������� ���������, ��� ��������.";
			Link.l1 = "� ��� ������ ������������?";
			Link.l1.go = "DestinyGift_3";
		break;
		
		case "DestinyGift_3":
			dialog.Text = "׸�� ��� �����. ����� ��� �� ���������. � ���� ����� �� �����?";
			Link.l1 = "�� ������ ������ ��� ���� ����. ���� �� �����.";
			Link.l1.go = "DestinyGift_4";
		break;
		
		case "DestinyGift_4":
			PChar.DestinyGift.FindFiveChapter.Havana = true;
			dialog.Text = "�������. ������, �� ����� ������ �� ����, �� ���� �, ��� ��.";
			Link.l1 = "����. �� ��-���� �������.";
			Link.l1.go = "exit";
		break;
		// ר���� ������� - ������� ������ <--

		//���� �������
		case "Consumption":
			dialog.text = "�� ����. � �� ���� �����. � ��� �� �������. � ������, ����� ��������, �� ��� ����� ������������ � �����. � ���, ��������, ���� ���� ����? ��������� ���.";
			link.l1 = "����. �������� �� ������������...";
			link.l1.go = "exit";
			pchar.questTemp.Consumption.AskJuan = sti(pchar.questTemp.Consumption.AskJuan)+1;
			if(sti(pchar.questTemp.Consumption.AskJuan) == 3)
			{
				pchar.quest.Consumption2.win_condition.l1 = "location";
				pchar.quest.Consumption2.win_condition.l1.location = "VillaAlegria_town2";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption = "true";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);
}

