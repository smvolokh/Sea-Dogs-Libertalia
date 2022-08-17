// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//--> ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Junglejew") && !CheckAttribute(npchar, "quest.junglejew"))
			{
				link.l1 = "��������� �� ��� ������, �����. � ����� �� � ������� �������� ������� � ��������. ��� ���� ������ �������� �������, �������� � ���� ����� � ���� �� �����. ������ ���-������ ������� � ���?";
                link.l1.go = "Sharlie_junglejew";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskiper")
			{
				link.l1 = "� ����, ��� � ��� ���� ������� �� ����� ��������� ���������. �������, ��������� ������ ���... �����������?";
                link.l1.go = "Sharlie";
			}	
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskipermoney")
			{
				link.l1 = "� �� ������ ����� ��������� ���������.";
                link.l1.go = "Sharlie_repeat";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "bankskipercaptive")
			{
				link.l1 = "� �������� ���� �������, �����. ��� ���... ��������� ����.";
                link.l1.go = "Sharlie_14";
			}
			//<-- ����� ��������

			if (pchar.questTemp.piratesLine == "KillLoy_toSeek")
			{
				link.l1 = "�������, � ��� ������ ��� ���������� ������ ���, � ��� ���.";
				link.l1.go = "PL_Q3_1";
			}
		break;
		
		case "Sharlie":
			dialog.text = "� ���-�� ����� ���� �� �����, ������� ���� ��������?";
			link.l1 = "��� ����� ���� �������. ������ �� �������, � �� �� ��������. � ��������� � ������ ��� ��������, ��� ���� ���� �� ����� ��������� ���, �� ��� �� ��������, � ������������� � ��������� ����� �����.";
			link.l1.go = "Sharlie_1";
		break;
		
		case "Sharlie_1":
			dialog.text = "�-�, ��� ������ ����. � ���� �������������, ����� ��� ������ ��������� �� ���... ���� ��������� ��������� - �������� ���. �� ���� � ���� ������������ ��������� ����� ����� - ���� ����� ����. ������� �� �� �� ������ � ���� ����������. � ����� - ��������� �������� ��� �� ������ ����� ��������� �����, � ��� � ������ ������.";
			link.l1 = "����� ����, �� ��� ���� ��� ���� ���������� ������ �����?";
			link.l1.go = "Sharlie_2";
		break;
		
		case "Sharlie_2":
			dialog.text = "������ ����� ��������� ��������� ����, ���� ���� ������, �����. ��� ��� ��� ������� ����������� ������ � ��� �����. �� ������ �������� ��� ��? �, �������, �������...";
			if (sti(pchar.money) >= 10450)
			{
				link.l1 = "�� �����������. ��� ������.";
				link.l1.go = "Sharlie_3";
			}
			link.l2 = "��... ����� � ������ ���������. ����������, �����, �����, �� ��������� � ���� ������������? ��, ��������, � ��� ���� �����-�� ����, ������� � �� ���� ���������, � �� �� ������� ��� ������ � ��� ������ � ��������� �����...";
			link.l2.go = "Sharlie_5";
			else link.l2.go = "Sharlie_5"; // Addon 2016-1 Jason ��������� ������� 1
		break;
		
		case "Sharlie_3":
			AddMoneyToCharacter(pchar, -10450);
			dialog.text = "��, ������ ���� ����� ��� ������������� �����, ��� �� ������ �������� �� ���� ����� ����� �����. �������, ��� �� ��� ����, ���� ���, �����? �������� ��� �������� - ������ �� ��������� ������ �� ��� ���� � ������ ��������� ���� ������ � ����. �� �, �������, ��������������� � ��� ������������ �� ������.";
			link.l1 = "������ ����� � � �����. �� ��������, "+npchar.name+"!";
			link.l1.go = "Sharlie_4";
		break;
		
		case "Sharlie_4":
			DialogExit();
			Log_Info("�� �������� �������� ��������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "letter_open");
			ChangeItemDescribe("letter_open", "itmdescr_letter_open_usurer");
			pchar.questTemp.Sharlie = "freeskiper";
		break;
		
		case "Sharlie_5x": // Addon 2016-1 Jason ��������� ������� 1
			dialog.text = "������? ���, �� � �� �������� � ����� �������, �� ������� ���� - ������.";
			link.l1 = "����. ��� ��, ����� � ������� ������ �� ���������. �� �������!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;

		case "Sharlie_5":
			dialog.text = "������? ��... ������, �����, ��� ����� �� � ������� ������������, �� ������... ��, � ���� ���� ����, ���������� �������� � �� ������ � ��� �����, �� ������������: ��� ������.";
			link.l1 = "������ ��� ����?";
			link.l1.go = "Sharlie_6";
		break;
		
		case "Sharlie_6":
			dialog.text = "��� ����� ����������� �����, �������. ��� ��� ���������, ����� ��� ��� ���� ��������, ������ �� �� � ������.";
			link.l1 = "������, ��� �� ������� �������� � ����� ���������� ������� ����. ��� ��� ������� �������� � �������� ������������, � ���� ��� ����� �� ����� ����� � �������� �������� �������� �����, ��������, � ����� ��������� ��, � ��� �� ������ ��� ��������� ���������.";
			link.l1.go = "Sharlie_7";
		break;
		
		case "Sharlie_7":
			dialog.text = "������. ����� ��������. ������� ������� �� ���������� ������ �� �������, ��� ��������� � ��������� ����� ������ �������, ������ ��������� ������� � ���������� � ����� �� �����. � ���� ����� ������� - ��������� ������, �������� ��� ���������� ����� �� ����� ����������\n���� ��������� ������ - ������������� ���������� � ���������������� ����, � ��������� �������� ������������ ��� ������� � ����� �����. �� ��� ���������� � ����� �� ����� ��������� ������� ������� �� ����-�����\n������ - ��� ��������� ��������, � � �� �� �����, ����� �� ����� � ���� � ����������. ��� �� ���������, � ����������� ������� ������� � ���������� �� ����, ��������� �� � �������� ��������� � ��������� ������\n���� � ���� �������� ������� - � ��, �������, ����� ��������������� ����� ��� ��������� �������... ���, ����� ���������, �� ���! ��� ������� ������ ���������� ��� ���� ���, � ������: ����������� � ����� �� ����� �... ������� ������� ������ ��� ��������\n�� �����, ��� ��� �������� ������������, ��� ��� - �������.";
			link.l1 = "������� ����� ������� � ������ �������?";
			link.l1.go = "Sharlie_8";
		break;
		
		case "Sharlie_8":
			dialog.text = "�� ����. �����, �������� ���, � ����� - ��� ��� ������. ��, ��� ��� �������?";
			link.l1 = "� ��� ������ ��� - ��� �� ��������� �������� � ���� ���������, � � ����, � ����� ������� ������� �����.";
			link.l1.go = "Sharlie_10";
			link.l2 = "��. �� ����� - ���� �������. �� ���� � � �������� �������� �� ����� �������.";
			link.l2.go = "Sharlie_9";
		break;
		
		case "Sharlie_9":
			dialog.text = "���� ����. ���� ����������, ��� �� �� ����� ���� - �� ����� ����� ����������. ����� ��� ��� � �������� � �������� ������ ����� �������.";
			link.l1 = "������. � ������� ������ �� ����. �� �������!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;
		
		case "Sharlie_10":
			dialog.text = "����� ������. ��� ������� ���. ����� ��� ������� ������������ � ����� �� ����� - ������ ����� ��� �������������� � ������ ������ � �� ��������. �� ���������� ��! � �� ��������� ���� � ����� �� ������� - �������� ��������. ������ �� ���� ����� �������!\n����� ���������� ��������, ��������� ��� �� ��� - ����� ����� ������� ���� �����. ������ ��������� � ����� ���!";
			link.l1 = "�������! ����� ��� ����� �����������...";
			if (CheckCharacterItem(pchar, "pistol_01")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol1")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_02")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol11")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol6")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_06")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol9")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol5")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_05")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol4")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol3")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_03")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_08")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol_04")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol2")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol02")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol8")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol7")) link.l1.go = "Sharlie_13";
			if (CheckCharacterItem(pchar, "pistol10")) link.l1.go = "Sharlie_13";
		else link.l1.go = "Sharlie_13";
		break;
		
		case "Sharlie_11":
			dialog.text = "���� ������! ����, � ��� ��� ���� �������. �������� ���� �� ����, � ��������� ������� � ����. �����, ��� ��� ����������.";
			link.l1 = "��, ��� ������ ���������� ����� ������������. ��������� ���, ������.";
			link.l1.go = "Sharlie_12";
		break;
		
		case "Sharlie_12":
			Log_Info("�� �������� �������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "pistol_01");
			TakeNItems(pchar, "bullet", 20);
			TakeNItems(pchar, "gunpowder", 20);
			dialog.text = "� ������ ��������, � �� ������� ��� ���!";
			link.l1 = "...";
			link.l1.go = "Sharlie_13";
		break;
		
		case "Sharlie_13":
			DialogExit();
			pchar.quest.Sharlie_captive.win_condition.l1 = "HardHour";
			pchar.quest.Sharlie_captive.win_condition.l1.hour = 21.00;
			pchar.quest.Sharlie_captive.function = "Captive_Timer";
			SetFunctionTimerCondition("Captive_CreatePiratesOver", 0, 0, 1, false);
			AddQuestRecord("SharlieD", "1");
			pchar.questTemp.Sharlie = "bankskiperfight";
			pchar.questTemp.Sharlie.Captive = "true";
			pchar.questTemp.Sharlie.Captive.Name = GetFullName(npchar);
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
		break;
		
		case "Sharlie_14":
			pchar.quest.Sharlie_captive1.over = "yes";
			pchar.quest.Sharlie_captive2.over = "yes";
			ref sld = characterFromId("CaptiveSpain");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", 5.0);
			sld.lifeday = 0;
			SetNationRelation2MainCharacter(FRANCE, RELATION_FRIEND);
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
			dialog.text = "������������! ����� ���, ��� ��� ������� ������� � ���� ����������. ����������� ����, ���, �������, ����� �� �����, ���� ���? ��, � ��� ������� ��������� ����� ����� ����������� ���� � ���� ���� � ������������...";
			link.l1 = "��� ������ ����� ��������� ���������?";
			link.l1.go = "Sharlie_15";
		break;
		
		case "Sharlie_15":
			dialog.text = "��, �������. �������� ��� �������� - ������ �� ��������� ������ �� ��� ���� � ������ ��������� ���� ������ � ����. �� �, �������, ��������������� � ��� ������������ �� ������. � �� ������, ��� ������?";
			link.l1 = "��, �����. ��� ������ �������� ��������. � ������ ��������� �����������.";
			link.l1.go = "Sharlie_4";
			AddQuestRecord("SharlieD", "7");
			CloseQuestHeader("SharlieD");
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
		break;
		
		case "Sharlie_repeat":
			dialog.text = "����, �� ������ ��������� �� ���� ����?";
			if (sti(pchar.money) >= 10450)
			{
				link.l1 = "��. ��� ������.";
				link.l1.go = "Sharlie_3";
			}
			link.l2 = "� ���������, � ��� �� ������ ������ �����...";
			link.l2.go = "exit";
		break;
		
		case "Sharlie_junglejew":
			dialog.text = "��. ������, �� ����� - ��� ������� ������, � ������� � ������ �����, ����������... ��� � ���� �������? � ���� ���� ��� �� ��� ��������... ���, ���� �������� ���� ������� ��������. ������������, ������ ��� �� �� �������.";
			link.l1 = "�������� ���� ��������? �������� ����. � ��������. ���������.";
			link.l1.go = "Sharlie_junglejew_1";
			link.l2 = "���. ����� � ������� ��� ������������� ����.";
			link.l2.go = "exit";
			npchar.quest.junglejew = "true";
		break;
		
		case "Sharlie_junglejew_1":
			DialogExit();
			PlaySound("interface\important_item.wav");
			Log_Info("�� ������ ������");
			RemoveItems(pchar, "jewelry25", 1);
			TakeNItems(pchar, "gold_dublon", 35);
			AddQuestRecord("SharlieE", "3");
			CloseQuestHeader("SharlieE");
			DeleteAttribute(pchar, "questTemp.Sharlie.Junglejew");
		break;

		case "PL_Q3_1":
			dialog.text = NPCStringReactionRepeat("�� �������� �� ���, ������ �����. �� ���. ����� ��������� ���, ������ ��� � ������, ���� ����������� ���� ����. �, ���� ��������, � ����� ������ ����������.", 
				"� ��� ��� ������ �� ��� ����, ����� ����.", 
				"�����?",
                "����������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("� ����...", 
				"�������.",
                "���, ��������...", 
				"�������, �����.", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("PL_Q3_2", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "PL_Q3_2":
			dialog.text = "� �� ���� �� ��������� �������������, ���� �� ��� �����.";
			link.l1 = "����...";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "5");
			AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","�"));
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

