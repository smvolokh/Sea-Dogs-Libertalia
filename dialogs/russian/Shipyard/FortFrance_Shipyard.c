// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "� ���� �� �����, � � ������ � ������, � ����� ����������� �������������� �� �����.",
                          "�� ��� �� �������? ��� ���� - ������� �������, ������� ���� � ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "��, ������...", "�������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "begin")
            {
                link.l1 = "��� ������� �������� ���� � ����� � �������, ��� �� ������� ���� ������. ������ ��� �����������.";
                link.l1.go = "FMQM";
            }
			if (CheckAttribute(pchar, "questTemp.FMQM") && pchar.questTemp.FMQM == "oil" && GetSquadronGoods(pchar, GOOD_OIL) >= 50)
            {
                link.l1 = "� �������� ���� �������. ����� � ���������� "+FindRussianQtyString(GetSquadronGoods(pchar, GOOD_OIL))+" ��������� � ���� � �����.";
                link.l1.go = "FMQM_9";
            }
		break;
		
		// Addon-2016 Jason ���-���������
		case "FMQM":
			pchar.quest.FMQM_Denial.over = "yes";
			dialog.text = "��-��, ������� "+GetFullName(pchar)+". � ������, ��� ��� ������� ������ � ����, � ����� �������� ������ �� ����� �����. ������� ����� � ����: �� ���� � ������� � ����� �����, �� ��� ����� �����, ��� �� ����� ������� �������, � ��� ����������� �����. ������� � ���� � ��� �����������.";
			link.l1 = "����� ���������! ��, �������, ������������.";
			link.l1.go = "FMQM_1";
		break;
		
		case "FMQM_1":
			dialog.text = "� ����������� ����, ��� �������� �������������� ��������� �������, ������������ �������� �������� ���������. ��� ����� ����������� ����������� ��������� �����, ������� ���������� �� ��������� ������� ��������. ����� ������� � ������, ��� ��� ������� ���������� �� ��� ������������ ������ �������� ����� � �� ����� �������� �������� � ���-����. �������� ������ ������� ��������� ��� ��������� ������������ ������� ���� ������, ����� ������ - ��������� ������ ��� ��������\n� ��� ���, ��� ���������� ������ ������������ ������, ����� ����� ��� �����. �����������, ��� ������� ��� �� �����������, �� � �� ������� ������� �� ���, ��� �� �������� ������� - ��� ��� �������... ����� ��, ��� ��� ��� ������ ���������� - ���, � ��, ��� � �����, ��� � ��� �� ����� ������� - ���. �� ��� ������� ������ ��������� �������, �� ����������� ���������� �������.";
			link.l1 = "�������, � ������� �������� ���� ������ �����������...";
			link.l1.go = "FMQM_2";
		break;
		
		case "FMQM_2":
			dialog.text = "���������. ������ � ����� ���-���� ����� ��������� �������� ������. � ������ ������ �� �������� ����� ���������� ��������� ������ ��� ������ ��� ����. ���� �� �� �������� ������ �������� � ���, ����� �������� ������ ����� ������� - � �������� ��� ��� �����������. ���� ��� - �� � ���� ���. ������ ����� �� ����.";
			link.l1 = "����������� ����������. � ����� ����������.";
			link.l1.go = "FMQM_3";
			link.l2 = "�������, � ��������, �����. ��� ������� � ������� ������ �� � ����� ������ ���������.";
			link.l2.go = "FMQM_exit";
		break;
		
		case "FMQM_exit":
			dialog.text = "��� ��, ��� ������. ��� ���� �����. ��������, ��� ����� ���� �����, �������.";
			link.l1 = "����� �������.";
			link.l1.go = "FMQM_exit_1";
		break;
		
		case "FMQM_exit_1":
			DialogExit();
			pchar.questTemp.FMQM = "fail";
			AddQuestRecord("FMQ_Martinique", "3");
			CloseQuestHeader("FMQ_Martinique");
		break;
		
		case "FMQM_3":
			string sTemp = "����������";
			if (MOD_SKILL_ENEMY_RATE < 7) sTemp = "���������-�������";// Addon 2016-1 Jason ��������� �������
			dialog.text = "����� �����������: ������ ������� �� ���� �����. ����� ����� ���������� ����� ������ ������� �� "+sTemp+" � ��������� '�������'. ��� � ���� ���� ����. ��� � ��� ������, ������� ������������ �� ���-����, ��� �� ���������. ����� �������� - ���-����, ��� �� ������-����. ������ ���������� � ���� ������ �� �������� - ��� ��� ���������, ��� ��� ������� ����� ����������� ���.";
			link.l1 = "����. ��� ������ ������?";
			link.l1.go = "FMQM_4";
		break;
		
		case "FMQM_4":
			dialog.text = "���� ���������� ������ �����. � � ������� �� ���������� ������� �������� �� ������ ������� ������. �� ���� ���������, �� '�������' �� ������ ����� ��������.";
			link.l1 = "���! ��� �������� ����� ����������!..";
			link.l1.go = "FMQM_5";
		break;
		
		case "FMQM_5":
			dialog.text = "��. � ������� ��� - ����� ������ � �������.";
			link.l1 = "�� �� ����� �������� � � ���, ��� ��������� ������ ����� ��������...";
			link.l1.go = "FMQM_6";
		break;
		
		case "FMQM_6":
			dialog.text = "�� �����������. �� �� �� �������� �� � ������� ��� ���������������. ����� �������� ������������� � ���� �� ����� � ������� ���� ����� �� ��� � ���� �� ������, �������. �� �������, ���� �� ���������� �������� ���������, ���� ���� ������ ����� ��������� ��� ����� � ������ ������� � �������� ����� �� �����. ����� ������ �� ����������.";
			link.l1 = "�� �����������������, ������. ������. ����� � �� ���� ������ ����� � ����������� �� ���� �����.";
			link.l1.go = "FMQM_7";
		break;
		
		case "FMQM_7":
			dialog.text = "����� ��� �����, �������.";
			link.l1 = "...";
			link.l1.go = "FMQM_8";
		break;
		
		case "FMQM_8":
			DialogExit();
			pchar.questTemp.FMQM = "convoy";
			AddQuestRecord("FMQ_Martinique", "4");
			SetFunctionTimerCondition("FMQM_ConvoyStart", 0, 0, 1, false);
		break;
		
		case "FMQM_9":
			dialog.text = "�����������! ������� �������� ���� ����� � ����, � � ������� �������� ����������, ��� � ��������������. �� ������������� �� �������, � � ���� ������ ������ � ���������� ���� �������.";
			link.l1 = "��� � ��������.";
			link.l1.go = "FMQM_10";
		break;
		
		case "FMQM_10":
			pchar.quest.FMQM_Late.over = "yes";
			DialogExit();
			InterfaceStates.Buttons.Save.enable = false;
			chrDisableReloadToLocation = true;
			pchar.GenQuest.FrameLockEsc = true;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
			pchar.questTemp.FMQM = "remove_oil";
			pchar.questTemp.FMQM.Oil = "true";
			pchar.questTemp.FMQM.Qty = GetSquadronGoods(pchar, GOOD_OIL);
			DoQuestFunctionDelay("FMQM_WaitTime", 1.0);
			RemoveCharacterGoods(pchar, GOOD_OIL, GetSquadronGoods(pchar, GOOD_OIL));
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}


