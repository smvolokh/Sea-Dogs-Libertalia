// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� �� ������? �����������.", "� ������ ���, ��� �� ������?"), "������ ��� �� ���� �� ��������� ������ ������...", "� ������ ��� �� ���� �� ����� ��������� ������ ������...",
                          "�� ����� �� ��� ��������?! � ���� ��� ����� �� ���������� ������ ������, � �� ��� ������� ��������� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "�� ������, �� ����� � �� �����..."), "��, �����... �� �� ������, �����...",
                      "�����, �����... ������ �����...", "��������, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//����������
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad"))
			{
				link.l1 = "� ����, ��� ����������� ����-������� �������� �������� ��������� ������� ���� �� ������ ������ ������, � ������ - ���������� �����������. ��� ������� �������� ���. ������ �� ��������� � ����� ����� ������� � � ����� ������ ��� �������.";
                link.l1.go = "Portugeze";
			}

			if (pchar.questTemp.LSCC == "toTalkStuvesant")
			{
				link.l1 = "� ���� �������� �� ����� ��������. �� �������� � ���������� �������� ���.";
				link.l1.go = "TizerFind";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("�� ��� ��� �������. ��� ��� ��� �����?", "������� �������� ��� ���-��, ��� �� �� ����������?");
            link.l1 = RandPhraseSimple("������������ ����������...", "��������, ����� �����"+ GetSexPhrase("","�") +" ��� �������...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//����������
		case "Portugeze":
			dialog.text = "���� ����������?! �� � ���? �����?";
			link.l1 = "� � �����, ��� ������� �� ��� �� �����. �����. � ��� �������� ��������� ������ ������, ���� ������, ����� �� ����� �� ����� ���!";
			link.l1.go = "Portugeze_1";
		break;
		
		case "Portugeze_1":
			dialog.text = "�����������! ������ �� �� ���������... ������, ������������� ����������� �������� � ��������� �� �����. �� ���������� ������� ������� ����� � ����� ������ �����.";
			link.l1 = "� �� ����� ������� �������� ������ ���� �������, ������... ���� �� �� ����������.";
			link.l1.go = "Portugeze_2";
		break;
		
		case "Portugeze_2":
			dialog.text = "������, �� ������ �� ����������� - ������� �� ��������. �� ������ ���������� ����������� �� ���������� ������� - ������� ������ ������� ��������. ���������! �������� ��������� �������� ��� ��������������!";
			link.l1 = "��... ������, ����� ������ ��� � ���� ������� ��������... �����, ������� - ������, �������.";
			link.l1.go = "Portugeze_3";
		break;
		
		case "Portugeze_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("�� �������� 1500 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ������ ������ ��� �������, �������, �������� �������� �����������. ��� ������ �� �������� ������ � ��� ������.";
			link.l1 = "�������, ������. ����������� ����� � ��������� � ����� �������.";
			link.l1.go = "Portugeze_4";
		break;
		
		case "Portugeze_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+20;
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;

		// --------------------- ������� ���, ������ � ������ ---------------------
		case "TizerFind":
			dialog.text = "���� � ���� ����� ��������, ��, ��� ��������, ������ ���, �������.";
			link.l1 = "���� ���������� ����� ���, ������.";
			link.l1.go = "TizerFind_1";
		break;
		case "TizerFind_1":
			dialog.text = "����� �������, ��� ��� ���������� ����� �������, ��������� � ������ ���!";
			link.l1 = "���������?";
			link.l1.go = "TizerFind_2";
		break;
		case "TizerFind_2":
			dialog.text = "������ ���! �� ������� � ����� �� ��� ����� ���� ����������� ����������� � ������ �� �������. ������, �������, �� ������� ��� ����������, ��� �������� ��������, � ��� ���� ����� ��� ������ ��� � �������...";
			link.l1 = "���� ������, ����� ���������� ������!";
			link.l1.go = "TizerFind_3";
		break;
		case "TizerFind_3":
			dialog.text = "�� ���� ������ �����������! � ������ ��� �� ������������� �������������?";
			link.l1 = "������, ���� ��� � ���, ���... � �����, � ��� ��������"+ GetSexPhrase("��","���") +" ��������������� �������� ��������� ����������. ����, ������ ��, �� ����������� � ������ ���� �������� ����� � ����� ������������ � �����. ��� ���-�... � ����� - ����� ���������� ������!";
			link.l1.go = "TizerFind_4";
		break;
		case "TizerFind_4":
			dialog.text = "�� ���, �������� �� ���� ��������?";
			link.l1 = "���������. ��� �������� ������ �� ������� ������ ������ � ��� ������, ������� ����� ����������� ��������. ����� ���������, ������ ��... �, �������, �������, ��� ��� ��� �����, �� ����� �������������! ��������� �������� ��� �����.";
			link.l1.go = "TizerFind_5";
		break;
		case "TizerFind_5":
			dialog.text = "��, � ������� ��������������. ��� ����� �����, ����� �����, ����� ��������� ����������� �������� ������... �-��, ����� ���������. �� �� ���, �������, � ����� �� ������ ����� ������������!";
			link.l1 = "������, �� ��� ������� ��� ��� �� ������.";
			link.l1.go = "TizerFind_6";
		break;
		case "TizerFind_6":
			dialog.text = "�������. �� ��� �, � ��� �� ��� ��� ������ ������������ ������ ����, �� � �� ���� ��� ��. � �� ���� �� ��������� �������������. ���� � ���, ��� ���� ������� �� ��� ������� ������������ �������, � � �������� ��� ��������� � ���� ������������ ����. �������, ��� �� ���� � �������.";
			link.l1 = "��������... � � ��� �����"+ GetSexPhrase("","�") +", ��� �� �� ������ ����.";
			link.l1.go = "TizerFind_7";
		break;
		case "TizerFind_7":
			dialog.text = "� ��� ������, ��� �� ���� �� ��������� �������. � ��������� ��� ������� ������� ��� ����, ��� ��������� ������� ������� ����. �������� ���, �� ����� ���� ��������� ������ ��������.";
			link.l1 = "�� ��� ��, � ����� �������� �� ����� �������. ������� ���!";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toLicencer";
			AddQuestRecord("ISS_PoorsMurder", "9");
			AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("��","���"));
			AddQuestUserData("ISS_PoorsMurder", "sSex1", GetSexPhrase("","�"));

				sld = GetCharacter(NPC_GenerateCharacter("PoorKillSponsor", "smuggler_boss", "man", "man", 30, PIRATE, -1, true, "quest"));
				sld.name = "������";
				sld.lastname = "�����";
				FantomMakeCoolFighter(sld, 70, 90, 90, "blade43", "pistol5", "bullet", 12);
				sld.SaveItemsForDead = true;
				sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
				sld.dialog.currentnode = "Begin_PoorKill";
				sld.nation = HOLLAND;
				sld.city = "Marigo_town";
				sld.location = "Marigo_houseH2";
				sld.location.group = "sit";
				sld.location.locator = "sit1";
				sld.dialog.currentnode = "PKInMarigo";
	                                                          LAi_SetCharacterUseBullet(sld, "cartridge");
                                                                             TakeNItems(sld, "grapeshot", 16);
	                                                          TakeNItems(sld, "bullet", 14);
	                                                          TakeNItems(sld, "cartridge", 21);
	                                                          TakeNItems(sld, "GunPowder", 18);
				LAi_CharacterEnableDialog(sld);
				LAi_RemoveLoginTime(sld);
				sld.standUp = true; //�������� � �������� �� �����
				LAi_SetHuberType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}