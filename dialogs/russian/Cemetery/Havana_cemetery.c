// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("��� ��� ������?", "��� �� ������ ������?"), "��� �������, ��� �� ��� ����������, " + GetAddress_Form(NPChar) + "?", "������ ��� �� ������� �� ��������� ������ ������...", "��, �� ���� �������. �������� ��� ���!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � �����������. ��������...",
                      "�� ��, ������������� � ������ ���...", "���������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche") && pchar.questTemp.Caleuche == "graveyard" && !CheckAttribute(npchar, "quest.caleuche"))
			{
				link.l1 = "��������, �� �� �������� � ������ ��� ������������ �������� �� ����� ������ ��������? ��������� ������, ����������, ����� ��� � ����������, � ������������� ��������? � ������, � ��������? �� ����� ������?";
				link.l1.go = "caleuche";
			}
		break;
		
		// �������
		case "caleuche":
			dialog.text = "�-���, �����, �-�����, ���. �����, ������ ��, ������ ���� ��� ������, � ������ ���� � �� �����...";
			link.l1 = "��. � ���� ��� �� ����� ��������� ����, ��������? � ������ �� ������� � ������� ��������... ������� ���, ��� �� �����. ��-��, �����������: �� ����� ����� ��������?";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "�-������ �� ���, ������, �� ����� � �-������! � �-�������� � � �������, �-���...";
			link.l1 = "�� �����. � �� ������ ����. ��� ��������?! �������!";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			dialog.text = "�� ���� � �������� ���������! � ���� �� ���� ������� - �� ��������� ��� �������� � �����, ������ ��� � ����!";
			link.l1 = "��, ��� ���! �� �����... ������ ������ ����������� � ������: ������ �������� - ������. ��� ������ ���������� ��������� ����������. ��� ����� ��� �����, ��� � ������, ����������� � �������� �� ������������ �����, ��������������� ��� ������� � ����������. � ����� ����, ��� �� �������� � ������������ ������...";
			link.l1.go = "caleuche_3";
		break;
		
		case "caleuche_3":
			dialog.text = "";
			link.l1 = "...� ������� �������� ������, ���, ��������, �� �����. � � ����, ���� ��� ��� ����. ��! �������, ���� �� ��� ����� ��������, ��� �� �� ��������! �� ������, ��� ��. ��� ���: � ���� ������� �� �����, ���� ����� ������ ���������� � �������� � ���������� � ������ ���� ��������, ��� ������ �������� ���������� �� �������� ������, � � ���������� � ���� ������������� ������...";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "";
			link.l1 = "... ��� �� ��� ���������? � ��� ���� ����� ���������, ��� � ��� �� ������� ����� ����� �������, ��� ����� ����� ��� ������ ���������� ���������, � ��, ���������� �� ����, ������ ������������, ��� �������� ������. � ����� ������� ������ � ��� �� ������ ��� ����������. � � ����� ���������� �� ��������. ��� ���� �����������?";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "���������, ���������, ������! � �� �������� �� ���� ����, �������! � ������... � ������ ������ �� ���... ��� � ���� ������������� ���? �� ������� �������, �� �����... �� �� �������������, ��� �� �����! ��������!";
			link.l1 = "� ����, ��� �� �����. ������ ������� �����. ��? ��� ��? ���������� ��� - ��� �����, ��� �� ���� ��������� ���� � ��� ����.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			dialog.text = "��... �� ���������� � ������ ��� ���������. ���� ����� ������� ������ ����� ����� � �������. ����� �� ������� ������, � ������� � ����� ���� � ���� �� ����. �� �� �������������, ��� � ����� �� ���������� �� ����� �����!\n�� � �� ���� ���� ������������ � ����. � �����... ��� �� �������� ������ ������, ������� ������ ����, � ����� ���� ���� ����� �� �������� ��� ����! � ����� ���� ������� �� �������. �������� �������� ��� �������. ������, ��� ���� � ������ ���������� �� ���� ��� ���������� ���� �� ������, �� �� ���� ������ � ���������... ��� � ���, � ������ �������!";
			link.l1 = "��� ����� �� ������� �� ������ ������?";
			link.l1.go = "caleuche_7";
		break;
		
		case "caleuche_7":
			dialog.text = "� ������� ��� �� ������ ���, �������� ����� � ��, ��� �� ���������. ��� �� ������� �����, �� ���� ���� ��� ���� � �����... ����� �� ���� ������ ����. �� ��������� ������� � �����, � ������� ���������, ��� ��� �����, � �������, ������ � �����, � �� ����� ��������.";
			link.l1 = "����. ��� ����� � ��� ������ - ��� �������?";
			link.l1.go = "caleuche_8";
		break;
		
		case "caleuche_8":
			dialog.text = "������ �������, ����� ������, � � �������� ������.";
			link.l1 = "��. �������� �� ����� - ��������� � ��� ������� ���� �������� �����, ��� � ��� ����������� ����. ������ ������ ����� - �� ������, � ���-����� �����. ���� ��������...";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "������, �� ���������, ��� �� �������� ���� ����������?";
			link.l1 = "� ���� ��� �����, � ����� ��������� - ��������. �������, ��� �� ����� ����.";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			dialog.text = "� ����, ��� ������� ����. ���� ������ ����... �� � ����. �������� �� ����, ��� � ����� ��� �����. ��� �� � ������� �� ��������� ����� ����, �� ���...";
			link.l1 = "��� ��� ���� ����, � � ������� ���� ����� �� �������.";
			link.l1.go = "caleuche_11";
		break;
		
		case "caleuche_11":
			GiveItem2Character(pchar, "kaleuche_key");
			ChangeItemDescribe("kaleuche_key", "itmdescr_kaleuche_key_crypt");
			dialog.text = "��������, ������. �� ����������� ����� ����?";
			link.l1 = "������. ������� � ���� � �� �����������, ����� � ���� �����. ���� � �� ������� - ���� �� ���� ���� ��� �������.";
			link.l1.go = "caleuche_12";
		break;
		
		case "caleuche_12":
			dialog.text = "������ ���������, ������. �� ��� ������ ��������� ����� �������� �����, ��� � ���� ����� �����������, ��� ��� ��� ��� �����. �� �������� ��� �� ����, ��� �����.";
			link.l1 = "� ����� ��� ��������� ����.";
			link.l1.go = "caleuche_13";
		break;
		
		case "caleuche_13":
			DialogExit();
			AddQuestRecord("Caleuche", "30");
			pchar.questTemp.Caleuche = "merriman";
			pchar.quest.caleuche_merriman_cave.win_condition.l1 = "locator";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.location = "Havana_CryptBig2";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.locator_group = "reload";
			pchar.quest.caleuche_merriman_cave.win_condition.l1.locator = "reload2";
			pchar.quest.caleuche_merriman_cave.function = "Caleuche_OpenMerrimanCave";
			pchar.quest.caleuche_merriman_cave1.win_condition.l1 = "location";
			pchar.quest.caleuche_merriman_cave1.win_condition.l1.location = "Havana_CryptDungeon";
			pchar.quest.caleuche_merriman_cave1.function = "Caleuche_InMerrimanCave";
			SetFunctionTimerCondition("Caleuche_MerrimanCaveOver", 0, 0, 3, false); // ������
			npchar.quest.caleuche = "true";
			// ������ ���������
			int n = Findlocation("Havana_CryptDungeon");
			locations[n].id.label = "Merrimancave";
		break;
	}
	UnloadSegment(NPChar.FileDialog2); 
}

