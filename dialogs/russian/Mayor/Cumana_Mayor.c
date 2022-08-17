// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	ref sld;
	int i;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ��� ����� �� ���������� ������ ������, � �� ��� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("�� ��� ��� �������. ��� ��� ��� �����?", "������� �������� ��� ���-��, ��� �� �� ����������?");
            link.l1 = RandPhraseSimple("������������ ����������...", "��������, ����� �����"+ GetSexPhrase("","�") +" ��� �������...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;

		//************************** ����� ������� ************************

        case "RevengeCorsairQuest_CumanaAttack":
			dialog.text = "���������! ��� ���� �����"+ GetSexPhrase(", ������ ����������","") +"?";
			link.l1 = "��������� � ���� ���.";
			link.l1.go = "Gothic_RevengeCorsair_1";
			AfterTownBattle();
        break;

        case "Gothic_RevengeCorsair_1":
            dialog.text = "������...";
			link.l1 = "��� ������, �� ��� ��� ������. �� �������� ������ � ������, � �� ��������� � �����... ��� ����� �������.";
			link.l1.go = "Gothic_RevengeCorsair_2";
        break;

        case "Gothic_RevengeCorsair_2":
            dialog.text = "����� �������?";
			link.l1 = "�� �������, ��� �������� ������, �������������� � �������� � �������.";
			link.l1.go = "Gothic_RevengeCorsair_3";
        break;

        case "Gothic_RevengeCorsair_3":
            dialog.text = "� ���� �� �����?";
			link.l1 = "��, ������� ���� ����� ����� �������, ����� ����� ������. � ����� �� ��� ����������, ������ ���� ����� ����� ����� �� ������� - ����� �� ��������� ����� ����������� �� ����� ����...";
			link.l1.go = "Gothic_RevengeCorsair_4";
        break;

        case "Gothic_RevengeCorsair_4":
            dialog.text = "�� ������� �� ����������, ��� ��� ��� ����� �����������. ��������...\n"+
                          "������ � �����. ������� ��� ��� ������� � ������� ��� �����.";
			link.l1 = "�� ������ ��� ��������� ���� ����� � ��������. ���������� � ����� ������������� ����� ������, ������.";
			link.l1.go = "Gothic_RevengeCorsair_5";
        break;

        case "Gothic_RevengeCorsair_5":
            NextDiag.CurrentNode = "Cupture_after";
			DialogExit();
			SetReturn_Gover_Dialog_Exit(NPChar);
            Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_GrabbingTown", 1);
			LAi_LoginInCaptureTown(&characters[GetCharacterIndex("Henry Morgan")], true); 
			LAi_LoginInCaptureTown(&characters[GetCharacterIndex("Torus")], true);
			LAi_LoginInCaptureTown(&characters[GetCharacterIndex("LeFransua_Mayor")], true);
            DoReloadCharacterToLocation("Cumana_fort",  "goto", "goto61");
            ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Henry Morgan")], "Cumana_fort", "goto", "goto13");
			LAi_SetStayType(characterFromID("Henry Morgan"));
			characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "Gold_found_in_fort";
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.Torus"))   // ��� ����� ����� ��� �����������, ���� �� �� ���� ������ �� ����. ���� ���, �� � �� � ����� �� �����.
            {
                ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Torus")], "Cumana_fort", "goto", "goto72");
                LAi_SetStayType(characterFromID("Torus"));
                characters[GetCharacterIndex("Torus")].dialog.currentnode = "Gold_found_in_fort";
            }
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.LeFransua_Mayor"))
            {
                ChangeCharacterAddressGroup(&characters[GetCharacterIndex("LeFransua_Mayor")], "Cumana_fort", "goto", "goto01");
                LAi_SetStayType(characterFromID("LeFransua_Mayor"));
                characters[GetCharacterIndex("LeFransua_Mayor")].dialog.currentnode = "Gold_found_in_fort";
            }     
            LAi_LocationFightDisable(&Locations[FindLocation("Cumana_fort")], true);
            // ==> ����� ������. ����� �� ����� ������ � �������� ������ � �������.
            // === ����� ����� ��������, � ������ �������� ��������������.
            pchar.questTemp.CumanaGoldQty = 3300 / sti(pchar.questTemp.CompanionQuantity);   // ����� ��� �������� ������ ������ �������, ���� �� ��������� �������� ��� ������������ � �� ������.
			// ������ �� � ��� ������� (�� ���������)
            SetCharacterGoods(pchar, GOOD_GOLD, GetCargoGoods(pchar, GOOD_GOLD) + sti(pchar.questTemp.CumanaGoldQty));// ��������
            if (IsCompanion(characterFromID("Henry Morgan")))   {AddCharacterGoodsSimple(characterFromID("Henry Morgan"), GOOD_GOLD, sti(pchar.questTemp.CumanaGoldQty));}
            if (IsCompanion(characterFromID("Torus")))        {AddCharacterGoodsSimple(characterFromID("Torus"), GOOD_GOLD, sti(pchar.questTemp.CumanaGoldQty));}
            if (IsCompanion(characterFromID("LeFransua_Mayor")))    {AddCharacterGoodsSimple(characterFromID("LeFransua_Mayor"), GOOD_GOLD, sti(pchar.questTemp.CumanaGoldQty));}
            Log_SetStringToLog("��������� ������ ����������� � ����� ��������.");
            InterfaceStates.Buttons.Save.enable = false;
            chrDisableReloadToLocation = true;
        break;

	}
    UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

