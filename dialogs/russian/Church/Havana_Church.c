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
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "havana")
			{
				ref sld = characterFromId("Villemstad_Priest");
				link.l1 = "���� ������� ���� "+sld.name+", ��� ���������� ������ �����������. �� �������� ��� � ���, ��� � ������ �� ���� ���� ��������...";
				link.l1.go = "caleuche";
			}
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "havana1")
			{
				link.l1 = "� ������� ������ � ��������, ������ ����.";
				link.l1.go = "caleuche_4";
			}
		break;
		
		case "caleuche":
			dialog.text = "����� ����, ��� �� ����������� �� ���! ���� ����� �� ������� ��������� �������� ���� ����, � �������� � ����������� ��� ���������� ���� ��������, ����������� ��������. �� ������ �����������, �� �� ��� ��� �� ���� ����������� ������� ��������! �����, ��� � ��� ������������ ����� ������ ����...";
			link.l1 = "� ������� ���� �����. ��������, ��� ��� ����� - �� �����, ��� ��������� ����������� ���������, ������� ���������� � �� ���������� �� �������. � ����� ���������� � ������� � �������� �� ��� ������������ �������.";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "������ ����, ��� ���, ��� �� �����! �������, ������� ������� ��� � ������� ���������, ����������� ������ ������� �������!";
			link.l1 = "������. � ���� ����� � �������. � ���� ������� ������������� ����������� � ������ - � ����� �� ������.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "�� �������� � ����� ���� ������� ������! ���, ������ ���� ���������� ������. �� ������� ���� � �������. �������� ����������� �������!";
			link.l1 = "�� �������, ���� "+npchar.name+". �� ����������� ����� � ���������� ����� � ���.";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			DialogExit();
			AddQuestRecord("Caleuche", "27");
			pchar.questTemp.Caleuche = "cave";
			Log_Info("�� �������� ��������� ������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "amulet_7"); 
			if (GetCharacterIndex("cavehunter") != -1)
			{
				sld = characterFromId("cavehunter");
				sld.dialog.currentnode = "cavehunter_5";
				LAi_SetGuardianType(sld);
				sld.protector = true;
				LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
			}
			LocatorReloadEnterDisable("Cuba_Jungle_07", "reload2_back", false);
			pchar.quest.Caleuche_cuba_caveentrance.win_condition.l1 = "location";
			pchar.quest.Caleuche_cuba_caveentrance.win_condition.l1.location = "Cuba_CaveEntrance";
			pchar.quest.Caleuche_cuba_caveentrance.function = "Caleuche_CubaCaveEntrance";
		break;
		
		case "caleuche_4":
			dialog.text = "��� �� ��� �����, ��� ���? ���� �����, ���� ������ ���� ��������?";
			link.l1 = "���, �� ��������. ������ ��������� ������ ��������. � ������ ������� � ��������� ���� ������� ���������. ������ ��� �� ����� ���������� �����.";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "����� ����������! �� �������� �������� ��� ���������, ��� ���! ������� �������� ���� �������� ��������������� �� ����� ������� ������, � ����� ��� �������: ��� ��� ���������� �������. ��� ��������� ���������� ���� � ����� �������� �����������.";
			link.l1 = "�������, ���� "+npchar.name+".";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "amulet_3"); 
			GiveItem2Character(pchar, "amulet_9"); 
			GiveItem2Character(pchar, "obereg_7"); 
			GiveItem2Character(pchar, "obereg_11"); 
			dialog.text = "����� � ����������, ����� � ����� ������� ������ � ������� ��������, � ������ �����������. � ���� ��������� �������� �� ����.";
			link.l1 = "���������, ������ ����. �� � ���� ���� ��� ������ � ���.";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "���������, ��� ���.";
			link.l1 = "�������, ���� "+npchar.name+", � ��� � ����� �� �������� ������� �� ����� ������ ��������? ��������� ������, ����������, ����� ��� � ����������, � ������������� ��������?";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			sld = characterFromId("Villemstad_Priest");
			dialog.text = "��� ���, ��� � ��������, ������ �� ������� ���. � ��� �� �����, ���� �������?";
			link.l1 = "�������� - ������, �������� ��� ����� ��� ���������� ����������. � � ���� "+sld.name+" �����������, ��� ��������� �� ���� ������� ��������� - ��� ��� ����. �� �� ��� ����� �������� � �����������, ����� �����, � �������, ��������� ��� �������, ����� ��������� ����� ������������ � ������� ������� ������.";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "����� ������! � ���������� ������ � ����������, ������ ���� ��������! �� ������ �����, ��� � ��� ����������! �����, ��� ���, �� ������������, ��� ��������� � �������� ����...";
			link.l1 = "��! � �����, ��� ��������, ������� � ������ - ��� ��, �� ��� ������������ ���� ����������� ��������. � ���� ���������� �������� �� ���� ����� �����������. �������� ��������� � ���� ���� ������� ��������� ��������, ���������� ����� �� ������. �����, ��� � ��� ������� � ������� ���������� ����������, �������� �������� ��� ������ ���, ���� ��� �� ����������.";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			dialog.text = "�� ������ �������, ��� ������� � ���������� ������ �������� ����� �����������?";
			link.l1 = "� ����� ������ � ����. �� ����, ��� ������ �������� ����������, �� ��� ������� ������ �� ��������������.";
			link.l1.go = "caleuche_11";
		break;
		
		case "caleuche_11":
			dialog.text = "�� ��������� ��� ���� ���������! ���, ��� ���, ������������ ���� � �������� ����� �������� �� ��� ����� ������! � � ���������� ��������� ����� � �������� � ������� � ���� ��������.";
			link.l1 = "�����������. ����� �������, ���� "+npchar.name+".";
			link.l1.go = "caleuche_12";
		break;
		
		case "caleuche_12":
			DialogExit();
			AddQuestRecord("Caleuche", "29");
			pchar.questTemp.Caleuche = "graveyard";
			AddCharacterMaxHealth(pchar, 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterComplexReputation(pchar, "authority", 2);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			ChangeCharacterNationReputation(pchar, SPAIN, 10);
			AddCharacterExpToSkill(pchar, "Leadership", 500);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}



