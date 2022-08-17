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
			link.l1.go = "exit";
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_8")
			{
				link.l1 = "���� ���������, � ���� �������� ���������� � ������������ �� ������ ������������� �������.";
                link.l1.go = "Mtraxx";
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_12")
			{
				link.l1 = "� �� ����� ������ ���������� ����� �������� �� ������ ����������� ������������ �����.";
                link.l1.go = "Mtraxx_4";
			}
			// Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_10_continue" && !CheckAttribute(npchar, "quest.slaveships"))
			{
				link.l1 = "� ������ �� ������� �������-����������� ������� �� ������. � ��� ������ ������� ��������� ��� ������������� � ���������� �����, ��� �����?";
                link.l1.go = "patria_Sl";
			}
			if (CheckAttribute(npchar, "quest.slaveships.wait") && GetSquadronGoods(pchar, GOOD_SLAVES) >= 3000)
			{
				link.l1 = "� ������ ��� ��� �����, ��� ��������������.";
                link.l1.go = "patria_Sl_2";
			}
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_11_start" && CheckAttribute(pchar, "questTemp.Patria.Curacao.DoilyReady"))
			{
				link.l1 = "� ������ �� ������� �������-����������� ������� �� ������ ��� ������� � ���������� ���������� �� ������� ������ ����������.";
                link.l1.go = "patria_Sl_4";
			}
			if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria == "epizode_11_wait" && GetCompanionQuantity(pchar) < 5)
			{
				link.l1 = "��� ������� ���������, ����� ������������ � ����.";
                link.l1.go = "patria_Sl_6";
			}
		break;
		
		// Addon 2016-1 Jason ��������� �������
		case "Mtraxx":
            dialog.text = "����� ���������. �� ��� ��, ������� ���������.";
			link.l1 = "�� ������������ ��������� ��� ����� ��������, ��� ��� � ������� ����, � �� � ������, ��������������, ����������, ����� 10 � 15 ������, �����, � ����� ��������, ����� ����������� ���������� '������' ��� ���������� ������ �������� ������������ ����������� ���� �������� ��������.";
			link.l1.go = "Mtraxx_1";
		break;
		
		case "Mtraxx_1":
            dialog.text = "�� �������, ��� ������ ��������� ������������� ����� ������?";
			link.l1 = "� ��������� �� ������ ���� � ����, �� �������, ������������ ��� �� ����, ������ ����������� �������, �, � ���� ��, �� ���� ������ �����.";
			link.l1.go = "Mtraxx_2";
		break;
		
		case "Mtraxx_2":
			string sTemp = "�����";
			if (sti(pchar.questTemp.Mtraxx.month == 1)) sTemp = "����������";
            dialog.text = "������, �������. ��, ��� �� ���������� - ������ � ������ ��������, � � ������ ��� ���������, ���� ���� ��� ���������� ������ ��� ������ ��������. � ����� ��������� ������� � ��������� ���� �����. � ���� ���� ���������� ������������ - �� ������ ������������ �� ��������������, ��� ������ ���� ������ ���� ���������� ������� ���������.";
			link.l1 = "� ������� � ��� 16 ����� "+sTemp+" ������. ����� ��� ��������� ��� ����������.";
			link.l1.go = "Mtraxx_3";
		break;
		
		case "Mtraxx_3":
            DialogExit();
			pchar.questTemp.Mtraxx = "silk_11";
			int month = sti(pchar.questTemp.Mtraxx.month);
			pchar.quest.mtr_silk_smuggler.over = "yes";
			pchar.quest.mtr_silk_smuggler_over.over = "yes";
			pchar.quest.mtr_silk_smuggler_patrol.win_condition.l1 = "Timer";
			pchar.quest.mtr_silk_smuggler_patrol.win_condition.l1.date.hour  = 6;
			pchar.quest.mtr_silk_smuggler_patrol.win_condition.l1.date.day   = 16;
			pchar.quest.mtr_silk_smuggler_patrol.win_condition.l1.date.month = GetAddingDataMonth(0, month, 0);
			pchar.quest.mtr_silk_smuggler_patrol.win_condition.l1.date.year  = GetAddingDataYear(0, month, 0);
			pchar.quest.mtr_silk_smuggler_patrol.function = "Mtraxx_SilkSmugglerPatrol";
			AddQuestRecord("Roger_2", "19");
			sTemp = "�����";
			if (sti(pchar.questTemp.Mtraxx.month == 1)) sTemp = "����������";
			AddQuestUserData("Headhunt", "sDate", sTemp);
		break;
		
		case "Mtraxx_4":
            dialog.text = "���������� ���� ���������� ��������� ������. �� ������� ������������ �� �������. ���������� '������' ���������� � ���� ����, �� ���� ��������� ����� ���������� ��������. ���������� ������ - �� ���� ������� - ������� �������������, ���� ��� ����, ����� ������� ������� � �������. ���� ���� ����������� - 80 ������� ������������ ����� - ��� ������� � ����� ����-������\n� ���� ��� �� ������� ��������, ��� �� ������� ����-������ ����� �� ���� ���� - ������� �� ��������, � �������� ��� � �� ����� - � ������ �������� ��������� ��������. ������ �� �������� ��������� ����� ������� ���� �������. �� ������� ��� ������� ������, �������, ������� �������������� � ����� ����������. ��� �� ��� ���������� �������������� � ������� 10 000 ����. �����, �������� ���� ������.";
			link.l1 = "���������, ���� ���������. ���, ��� ��� ������ ��� ���� � ������� �������� �� ��������. � ������ ��������� �����������.";
			link.l1.go = "Mtraxx_5";
		break;
		
		case "Mtraxx_5":
            DialogExit();
			pchar.questTemp.Mtraxx = "silk_13";
			AddQuestRecord("Roger_2", "20");
			AddMoneyToCharacter(pchar, 10000);
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterNationReputation(pchar, ENGLAND, 5);
			AddCharacterExpToSkill(pchar, "Leadership", 200);
		break;
		
		// Jason ���
		case "patria_Sl":
			if (GetSquadronGoods(pchar, GOOD_SLAVES) < 500)
			{
				dialog.text = "���������� �����, �������. ������� ����� �� ��������?";
				link.l1 = "� ��� ���� ��� ��������, ������ ����� ��������, ��� �� �����. ����� ������� � ������������.";
				link.l1.go = "patria_Sl_wait";
				break;
			}
			dialog.text = "���������� �����, �������. ������� ����� �� ��������?";
			link.l1 = ""+FindRussianQtyString(GetSquadronGoods(pchar, GOOD_SLAVES))+".";
			if (GetSquadronGoods(pchar, GOOD_SLAVES) >= 3000) link.l1.go = "patria_Sl_2";
			else link.l1.go = "patria_Sl_1";
		break;
		
		case "patria_Sl_wait":
			DialogExit();
			npchar.quest.slaveships.wait = "true";
		break;
		
		case "patria_Sl_1":
			dialog.text = "��, ������� �� ������ ������, ��� ����� ����� �� ������ 3000 ����...";
			link.l1 = "��� �����. ��� ��� ����: ����� ����������� ������� ��� �������� ���������� �������, ��������� ������ � ����. � �������� ���� ���������� � ������� � ���. ��� ����� ������� �� ��������.";
			link.l1.go = "patria_Sl_wait";
		break;
		
		case "patria_Sl_2":
			DeleteAttribute(npchar, "quest.slaveships.wait");
			dialog.text = "�������! � ������� �� ������ ������������� ����� ����� ����. ��������� �������-�����������, ��� ��� ������� ��� ����� ������� ����� ������ ����� �����. ��� �����, �� �� ������, ���� ����� ��� �������. ������, ��� �� �������� �� ��� ��� ��� ����� ������, ��� ��� ����� ��������, ����� �� ���.";
			link.l1 = "���� ��� ��������� �������, ���������. � ������ ��������� �����������.";
			link.l1.go = "patria_Sl_3";
		break;
		
		case "patria_Sl_3":
			DialogExit();
			npchar.quest.slaveships = "true";
			RemoveCharacterGoods(pchar, GOOD_SLAVES, GetSquadronGoods(pchar, GOOD_SLAVES));
			AddQuestRecord("Patria", "57");
			pchar.questTemp.Patria = "epizode_10_return";
			pchar.quest.Patria_SlaveShipsJamaicaTimeOver.over = "yes"; //����� ������ �� �������� �����
			SetFunctionTimerCondition("Patria_CuracaoDoilyReady", 0, 0, 30, false); // ������ �� 1 ����� �� ���������� ������� �����
			SetFunctionTimerCondition("Patria_CuracaoTimeOver", 0, 0, 62, false); // ������ �� 2 ������ �� ����-������� � ������
			SaveCurrentQuestDateParam("questTemp.Patria.Curacao.Date"); // ���������� ����
			// ������ ��������� �����
			pchar.questTemp.Patria.Friend = "true";
			LaunchNationLegend();
			DeleteAttribute(pchar, "questTemp.Patria.Friend");
			DoQuestCheckDelay("sea_victory", 0.2);
		break;
		
		case "patria_Sl_4":
			dialog.text = "� ���� �� ����������, ��� ��� ������ ��. ��� �����! ���� ������� ������. �������� ������� 1 ����� � ��� ������� 4 �����. ������������ ������ ���� ������� �� ������ ��������� ������ ��������.";
			if (GetCompanionQuantity(pchar) > 5)
			{
				link.l1 = "����� � �������� ������ ������� �� �������.";
				link.l1.go = "patria_Sl_5";
			}
			else
			{
				link.l1 = "�������! ����� ������������ � ����.";
				link.l1.go = "patria_Sl_6";
			}
		break;
		
		case "patria_Sl_5":
			DialogExit();
			pchar.questTemp.Patria = "epizode_11_wait";
		break;
		
		case "patria_Sl_6":
			dialog.text = "�������. ������ � ������� ��� ����, �� �������� �� ����� �����������: ��������, �� �������� ���-�� �������� ��� ��������, ����� �� ��� �������.";
			link.l1 = "������ ��� �����������, ���������.";
			link.l1.go = "patria_Sl_7";
		break;
		
		case "patria_Sl_7":
			dialog.text = "����������� ������� ��� ������: ��� �������� ������� ���������� �� ����������, � ���� ���� �� ������ �� ���� � ����� ����������� � �������� ���������� ��� �����������, �������� ������ ����� ����� ������: ��������� ������ �������� ��� �� ���� �������, ��������� ������� �������. � �����, ������ ���������������, �� � �� �����. ��� ����� ��������� ����������� ��������� ������� �� �������� ��� ��� � ��� ��������, � ��� ����� ���������� ����� ���������� �������� �������� ���� ����� � ��������� ���������� ����� ������� ������� ����������� ������� ����������.";
			link.l1 = "��� ��� ����� �� �������?";
			link.l1.go = "patria_Sl_8";
		break;
		
		case "patria_Sl_8":
			dialog.text = "������� ��� ��������� ��������� ���� � ������� �� ������. �� �������� ��������� �������� ��������, ����������� '�������� �����' ����� ��������� � �������, ����� ����������� �� ����� ���������� �� ������ ����-������� � ������ �������������� ��� ��� ������������ ������.";
			link.l1 = "����.";
			link.l1.go = "patria_Sl_9";
		break;
		
		case "patria_Sl_9":
			dialog.text = "����������� ����� ���: ������� ����� ������ ������������ �� ���� � ���������� ���. ��������� ����� ������� ������� �������, �� �� ����� ������ �� ������ - ����� ������� ������ ������ ��� ������ �������� � ����. ������ ����� �� ������� ��������� ���� � ���� ������ �������: �� ���� �����-����� � � ������ ������, � �������� �� ���� � ��������� ������� �����������. � �������� ����� � ����� �� ������� ������� ���������� - �� ������� ��� ���������������� ��������, � �� ��� ������� ����� ������ ������ ����� �� ������� �� �����\n���� ��������� ����� ����������, ��� �� ���, �� ������� ����� ��� ������ �� ������� �������� � ������� ����������� �������� ������������ �� ����� �� ����. ����� ����� ���������� ���������� ����� ������ ����. ��������� �������� ����� ���������� ���������, �� ������ ������� ����� � ����� ���������� ��� ������ �� ������ �������, � ���� �������� ������, ���� ����� ���� � ��������� � ���, ��� �� ������ ���������� � �������\n����� ����, ���� ������� ���������� ���������� � ������� ������� � ���� - ������� ������ �� ����������. ����� ��������� �����, ����� ��������� ��������� �������� ���� ��������� ���������, �� �������� ������������� ��� �����������. ���� ������, �������?";
			link.l1 = "�������� ����! ������� - �� ����������� ������ ������ ��� ������� ��������.";
			link.l1.go = "patria_Sl_10";
		break;
		
		case "patria_Sl_10":
			dialog.text = "� ���, ��� ��� ���� ��� �����������. ����� ���������!";
			link.l1 = "������!";
			link.l1.go = "patria_Sl_11";
		break;
		
		case "patria_Sl_11":
			DialogExit();
			chrDisableReloadToLocation = true;
			pchar.questTemp.Patria = "epizode_11_continue";
			AddQuestRecord("Patria", "60");
			pchar.quest.Patria_CuracaoTimeOver.over = "yes"; // ����� ������ 2 ������
			LAi_SetActorType(npchar);
			ChangeCharacterAddressGroup(npchar, "PortRoyal_townhall", "goto", "goto4");
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "OpenTheDoors", 7.0);
			Patria_CuracaoSail();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

