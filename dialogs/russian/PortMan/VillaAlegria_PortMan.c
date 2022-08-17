// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����������, ���� �� �� �� ����� �����, �� �� ����� ���� ��������� ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������" + GetSexPhrase("","�") + "...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "��������, �� �������� ���� ���� ������ �� ����������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//���� �������
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "�������, ��� '����' ��� ���-������ �������?";
				link.l1.go = "Consumption";
			}
			if(PChar.SpanishGenerosity == "6")
			{
				link.l2 = "��� ����� ������, � ����� ���� ������ ���� ������� ������� ''���������''.";
				link.l2.go = "SpanishGenerosity_1";
			}
			
			if(PChar.SpanishGenerosity == "7")
			{
				link.l3 = "� �� ������ ''���������''...";
				link.l3.go = "SpanishGenerosity_5";
			}
		break;

		//���� �������
		case "Consumption":
			dialog.text = "����? � ���? ����� ��������� �������, ���, ���� ��, �������� �����? ����� �� ��������� �������, �������� � ������ � �������� ��� ��� ������� � ��������, � � ���� ������� ������ �� �� ������, ��� ���, ���� �� ����� ������ �� ������ � � ��� ������ �� �����.";
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

	
	        // ��������� �������� -->
		case "SpanishGenerosity_1":
			dialog.text = "��������, �������, �� � �� ���� ����� ���������� ������� �����.";
			link.l1 = "������� � ���� ���������� ���, ����� ���������� ������ ���� �����?";
			link.l1.go = "SpanishGenerosity_2";
		break;
		
		case "SpanishGenerosity_2":
			dialog.text = "50 000 ��������, �������, � �� �� �������.";
			
			if(sti(PChar.money) >= 50000)
			{
				link.l1 = "��� ������, �����������.";
				link.l1.go = "SpanishGenerosity_3";
			}
			else
			{
				link.l1 = "�-�... � �������, ������� �������.";
				link.l1.go = "SpanishGenerosity_4";
			}
			
			link.l2 = "����?! � ������� ���� �� ����?!";
			link.l2.go = "SpanishGenerosity_4";
		break;
		
		case "SpanishGenerosity_3":
			AddMoneyToCharacter(PChar, -50000);
			dialog.text = "''���������'' ������ ���� � ����� ��� ���� ���� �����.";
			link.l1 = "���������� ��������" + GetSexPhrase("��","��") + " ���.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SpanishGenerosityAlborettoInShore");
		break;
		
		case "SpanishGenerosity_4":
			PChar.SpanishGenerosity = "7";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "SpanishGenerosity_5":
			dialog.text = "����� ��? ���� �� ���������� - 50 000 ��������.";
			
			if(sti(PChar.money) >= 50000)
			{
				link.l1 = "��� ������, �����������.";
				link.l1.go = "SpanishGenerosity_3";
			}
			else
			{
				link.l1 = "�� ������ ������ � �� ���������� ����� ������.";
				link.l1.go = "SpanishGenerosity_4";
			}
			
			link.l2 = "�, �������, ���������" + GetSexPhrase("","�") + ".";
			link.l2.go = "SpanishGenerosity_4";
		break;
	        // <-- ��������� ��������

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

