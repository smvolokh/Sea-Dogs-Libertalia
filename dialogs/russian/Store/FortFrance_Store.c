// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("���������, ���� �� ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��������, ��� �������, ����� ���� �������� ���-��. �� �������� ����!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//--> ����� ��������
			if (!CheckAttribute(npchar, "quest.storehelper") && pchar.questTemp.Sharlie == "ship")
			{
				Link.l1 = "����������, �����, � ��� ������. ��, �� ��, ����� �������� �������, ��� ��������� ����� �� ����� �������, � ��������� �����-������ ���������, ������. �� �� ���������� � ��������� ������?";
				Link.l1.go = "Sharlie_storehelper";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Storehelper") && pchar.questTemp.Sharlie.Storehelper == "return")
			{
				Link.l1 = "� �������� ���� ���������. ��� ������� �������� ������� �����.";
				Link.l1.go = "Sharlie_storehelper_2";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Storehelper") && pchar.questTemp.Sharlie.Storehelper == "choise")
			{
				Link.l1 = "��� ��� ����� ��������, �����. �����������.";
				Link.l1.go = "Sharlie_storehelper_11";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Storehelper") && pchar.questTemp.Sharlie.Storehelper == "final")
			{
				Link.l1 = "��� ����� �, �����. � ������ �� ����� ��������.";
				Link.l1.go = "Sharlie_storehelper_13";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Junglejew") && !CheckAttribute(npchar, "quest.junglejew"))
			{
				link.l1 = "���������� �� ��� ������, �����. � ����� �� �� ���� ������� ������� � ��������. ��� ���� ������ �������� �������, �������� � ���� ����� � ���� �� �����. ������ ���-������ ������� �� ���� �������?";
                link.l1.go = "Sharlie_junglejew";
			}
			//<-- ����� ��������
		break;
		
		//--> ����� ��������
		case "Sharlie_storehelper":
			dialog.text = "���������? ��. �������, � ���� ������������� ����� ��� ��� ������ ������ ����, ��� �� ������. � ���� ������ ��������, ���������� �� ������. ��� ��� ������ ��� ���, � ���, ���� ������, ������ ���������, ������ ��� ��� ���������� ������ ��� � ��� ������, � � ���������� �� �������\n� ��� �����, �������� ����� ������� � ��������, ������ ������ �� �������� ������, � ��� ����� - ��������� ��� �� ���. �� ������ � ������� ��� ������ ����.";
			link.l1 = "������, � ��������. ��� ����� ������ ��������� � ������� ��� ���������, � �����, ����� � ��� ����������� - ��� ��� ����� ����� c ���������� ������������?";
			link.l1.go = "Sharlie_storehelper_1";
			link.l2 = "������ �������� ������� ��� �� �����-�� ������ ������? �� ������ ����, ������!";
			link.l2.go = "Sharlie_storehelper_exit";
			npchar.quest.storehelper = "true";
		break;
		
		case "Sharlie_storehelper_exit":
			dialog.text = "��, �����, ��� �� �� ����� ������, � �� �? �� ������ - ��� ������, � ��� �� ���������. ����� �������.";
			link.l1 = "��...";
			link.l1.go = "exit";
		break;
		
		case "Sharlie_storehelper_1":
			dialog.text = "����� ��� ������ �����. ��� ��������? �������� ���� ��� �� ����, ����� ��� � ������, ������ �� ��� ������� ���������� ����� � ����� ������, � ����������� - ���������, ������� ������, ����� ��� � �����\n��� ����� ����? �� �� ����� �� � ���� �� ������ - ��� ��� � ������, � ��� ��� ���� ����, ������� � �������������� �������, ��� ��� ������ �� ������� ��� ����� ����������. � ������� �� ������� � ���� ��� �� �������, �� �������.";
			link.l1 = "����. ��������� � �������. ��� ������ ����� �����-�� ��������� - ���������� ������.";
			link.l1.go = "exit";
			AddQuestRecord("SharlieA", "1");
			pchar.questTemp.Sharlie.Storehelper = "true";
			pchar.questTemp.Sharlie.Storehelper.Chance = rand(2);
			AddDialogExitQuestFunction("Sharlie_CreateStorehelper");
		break;
		
		case "Sharlie_storehelper_2":
			dialog.text = "��? � ��� �� ��?";
			link.l1 = "� ����� ��� � �� �������. �� ������ �� ����� �������� �� ���. �� ��� � ������. � ����� ������� ��� ����� ���� � ��� �����... ��� ��������� ���������, ��� ������?";
			link.l1.go = "Sharlie_storehelper_3";
		break;
		
		case "Sharlie_storehelper_3":
			dialog.text = "���. �������� ���� �� �����... ��� ��������-�� �����! � ��� �� � ������ ���� ��� ���������?";
			link.l1 = "������� �������. ��� ��� ������������� ����� ��������, ��� ������ ������?";
			link.l1.go = "Sharlie_storehelper_4";
		break;
		
		case "Sharlie_storehelper_4":
			dialog.text = "��� ������������� ��������. � ��� �� ������, ���� ����������?";
			link.l1 = "��, ��������, ������ �� ���� �� �������������, ��-��. � ������ ��, ��� ����� �� ���� ���� �� ������ �� ������ � ��� �� ������, ������ ���... �� ������������ ������� ����� ����������. ��, ������, "+npchar.name+", � ��� ������ ����, ��� �� � �������.";
			link.l1.go = "Sharlie_storehelper_5";
		break;
		
		case "Sharlie_storehelper_5":
			AddMoneyToCharacter(pchar, 1000);
			dialog.text = "�� ����������, ������� ���� ������. ��! � ���� �����! �������, ������ ��� �������, ������ � ������ �� ���� ������ - ���� ������� ��������� �� ������ ������� ����� ��� ���. �� ��� �� ��� ������? � ���� �� ����������\n��� ����� �� ����� �������, ����� ��������� ���� �����, � ��� ��������� �������� ����, ����� ����� ������ �� ������, ������ ����, ����� ���������! ����� ������� �������� � ������������ ���� �������� ���� - � ������, ��� �������� '�� ������' ���������� ��...";
			link.l1 = "��, � �� ����, ��� ��� ������������. �����, ����� �������, ��� ����.";
			link.l1.go = "Sharlie_storehelper_6";
		break;
		
		case "Sharlie_storehelper_6":
			dialog.text = "������! � �����, �� ������� ������ ���. ��� �� ������ ��������� ����� ���������, ��, ������ ��������, � ��� ���������...";
			link.l1 = "���������, � ��� �� � ����� �������, ���� � ���� ������ ��� ����� �� �����? � ����� ������� �����, �...";
			link.l1.go = "Sharlie_storehelper_7";
		break;
		
		case "Sharlie_storehelper_7":
			dialog.text = "����� ��� �������, �����. �� ���� � �� �������. � ���� ��������� ��� ����������� ���� ��� ��� � ����������� ������ ��������� ��� �� ����� ���. ���� �����, � ���� ��������� ������� ������ ��� �� ����� �������� ��� ���\n������ ��������� - ������������� ����� ����������� �� �����, � �������� �� ������, � �������, ����� ����� ������ ������� �� ���������. ��, �����, ������ �� ��������� ��������, ���� ���� ���, �� ��� �� ��������� ������\n�������, ��� � ����������� ����� - ������� � ������ ����� ��������, � �������� � �������. ��������� - ������� ���� � ������. �����, � ��������� �����������, � ���� ������-������ ������ ������������ ����, � ��� ��������� ��� ����� ������, ���������?";
			link.l1 = "��. ����������� �����, ���� � �� ������... ������� �� ��� ��������� �� ������?";
			link.l1.go = "Sharlie_storehelper_8";
		break;
		
		case "Sharlie_storehelper_8":
			dialog.text = "��� ����� �������� �� ����, ������ ��������� �� �������. ��� ����� ������ �� �������� - ��� ������ � ������� �� ���� ������. ��� ����� �����������, �����������.";
			link.l1 = "� ��� �� �������, ��� �� ������ ����������� ���� ������ �������? ������ ��� �����, ��� �� ������� ���������? �� ������ ������ ���������������� ��� ������� �...";
			link.l1.go = "Sharlie_storehelper_9";
		break;
		
		case "Sharlie_storehelper_9":
			dialog.text = "�����! �, �������, � � ����� ���� ���� ��������� ����������, �� ���������� ���� ������� ����� �� ������! ���� � ������, ��� ������ ��� ���� �������� ���������� - ������, ��� � �����. ������� � ���� ���� - �� ���� ������ �������� ������-������ �������-�����������, ������� �� �� ��� �������� �� ������, �� ��� � ������� ���� �����!";
			link.l1 = "�����. � ��������. ���� ���������� �� ���� �����, "+npchar.name+". �� ����� ����� ������ ����� - ���, ��� �������� - ������.";
			link.l1.go = "Sharlie_storehelper_10";
		break;
		
		case "Sharlie_storehelper_10":
			DialogExit();
			AddQuestRecord("SharlieA", "3");
			pchar.quest.storehelper.win_condition.l1 = "Timer";
			pchar.quest.storehelper.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.storehelper.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 5);
			pchar.quest.storehelper.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 5);
			pchar.quest.storehelper.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 5);
			pchar.quest.storehelper.function = "StorehelperOver";
			pchar.questTemp.Sharlie.Storehelper = "hire";
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
		break;
		
		case "Sharlie_storehelper_11":
			dialog.text = "�� �������� ��� ���������? ���������. ��������� ��� ������������ � ���, � ������� ����� ����� �� ����� ���������.";
			link.l1 = "������. � ���� � ��� ����� ���� ���.";
			link.l1.go = "Sharlie_storehelper_12";
		break;
		
		case "Sharlie_storehelper_12":
			chrDisableReloadToLocation = false;//������� �������
			pchar.questTemp.Sharlie.Storehelper = "wait";
			DialogExit();
			pchar.quest.storehelper5.win_condition.l1 = "Timer";
			pchar.quest.storehelper5.win_condition.l1.date.hour  = sti(GetTime()+1);
			pchar.quest.storehelper5.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.storehelper5.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.storehelper5.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.storehelper5.function = "StorehelperFinal";
			AddQuestRecord("SharlieA", "5");
		break;
		
		case "Sharlie_storehelper_13":
			switch (sti(pchar.questTemp.Sharlie.Storehelper.Quality))
			{
				case 0:
					AddMoneyToCharacter(pchar, 3000);
					dialog.text = "��������� ���� �������� ������ ��� ��������, ���� ���������� �� ������, ��� ����� ������� ������. �� ������, � ��� ���� �� ���� ������ �����. ���� �������������� ���������� ��� ������ ����. ��������, ����������.";
					link.l1 = "���������! ����� �������, �����.";
					link.l1.go = "Sharlie_storehelper_14";
				break;
				
				case 1:
					AddMoneyToCharacter(pchar, 5000);
					TakeNItems(pchar, "Chest", 1);
					dialog.text = "��� ������� ����� ������������� ������� ���������! �� ���� �����, ��� ���� ������� ������. � ����� � ����� ���� �������, ������. �������� ���� ������� - ���� ����� ����. � �������� ���� ������ � ��������� �� ���� ������ ��������� �����. ";
					link.l1 = "����������, ��� ��� ������� ��������. �������� ����������. ����� �������, �����!";
					link.l1.go = "Sharlie_storehelper_14";
				break;
				
				case 2:
					AddMoneyToCharacter(pchar, 4000);
					dialog.text = "�� ����� �������� ���������. � ���� ��� �������� ��� �� ��������, � ������, �� �� ���� ������ �� ��� ����� ������. � ������� ����, ������. ���, �������� ������� - ������ ������ ����.";
			link.l1 = "���������! ����� �������, �����.";
			link.l1.go = "Sharlie_storehelper_14";
				break;
			}
		break;
		
		case "Sharlie_storehelper_14":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.Sharlie.Storehelper");
			CloseQuestHeader("SharlieA");
		break;
		
		case "Sharlie_junglejew":
			dialog.text = "� ��� ��� �������? ������������ ������... � ���� ���� ��� �� ���... ���-���... ������ ������ ����. ������ ��� ������ �� ��� ���������. ��������?";
			link.l1 = "�� �����! ���������.";
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
			AddMoneyToCharacter(pchar, 4000);
			AddQuestRecord("SharlieE", "4");
			CloseQuestHeader("SharlieE");
			DeleteAttribute(pchar, "questTemp.Sharlie.Junglejew");
		break;
		//<-- ����� ��������
	}
	UnloadSegment(NPChar.FileDialog2);
}

