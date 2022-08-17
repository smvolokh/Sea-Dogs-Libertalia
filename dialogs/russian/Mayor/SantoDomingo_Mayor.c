// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ��� ����� �� ���������� ������ ������, � �� ��� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "Gothic_10_1";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("�� ��� ��� �������. ��� ��� ��� �����?", "������� �������� ��� ���-��, ��� �� �� ����������?");
            link.l1 = RandPhraseSimple("������������ ����������...", "��������, ����� �����"+ GetSexPhrase("","�") +" ��� �������...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;

        //********************** ���.�������. �����. ������ �����-������� ************************

		case "Cupture_after_1":
            dialog.text = RandPhraseSimple("�� ���� ��� ��������, ���� ���������?", "������� �� �������?");
            link.l1 = RandPhraseSimple("� �� ������� ���������? �������� ���� �������...", "� �� �������� ��� ����, �������� ������ � ������ �������� �� �����...");
            link.l1.go = "Gothic_10_2";
		break;

		case "Quest_OccupySD":
            dialog.text = "�� ��������... � ��� ����� ������? �����?";
			link.l1 = "���, ������. �, " + GetFullName(pchar) + ", �������� ���� ����� ��������� ����������� ������. ��� ����� �������� ���������� ������� �� ���� ������� ������� ����-�-������.";
            link.l1.go = "Gothic_10_1";
			AfterTownBattle();
        break;

		case "Gothic_10_1":
            dialog.text = "��� �� �������� �����...";
			link.l1 = "�������, �� ����������, ������... �� � ������ ����� ���� ��������... ��, ������, � �� ����������� ��� �����, ����� ��� ���������� ������.";
		 link.l1.go = "exit";
                                       NextDiag.TempNode = "Cupture_after_1";
                                       PChar.questTemp.DontSetNewDialogToMayor = true; // ����� ����� ������� ������ � ��������
                                       DeleteAttribute(PChar, "questTemp.DontSetNewDialogToMayor");
                                        SetReturn_Gover_Dialog_Exit(NPChar);
                                         AddDialogExitQuestFunction("LaunchColonyInfoScreen"); // �������� 
                                        SetCaptureTownByNation(NPChar.City, sti(PChar.nation));
                                         UpdateRelations();
                                         Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_TakeTown", 1);
                                         PChar.questTemp.DontNullDeposit = true;    // ���� �� ������ ����������
                                          pchar.questTemp.GothicLee = "OccupySD_toWeWon";
        break;
		case "Gothic_10_2":
            dialog.text = "������ � ���� ��� ������, ��� � � ������ ���������� ��������� ����������!";
			link.l1 = "��������, �� ������������ ������ �� ����.";
			link.l1.go = "Gothic_10_3";
        break;

		case "Gothic_10_3":
                                                         dialog.text = "�� ������������ �������, � �� ��������� ����� ������.";
			link.l1 = "";
			link.l1.go = "Gothic_10_4";
        break;

		case "Gothic_10_4":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
                                       dialog.text = "";
		 link.l1 = "������.";
                                        DoQuestFunctionDelay("GothicLee_Mayor_death", 3.0);

        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

