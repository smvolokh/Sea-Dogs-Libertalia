// ����� ���������� - ������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "GenQuest.CitizenConflict") && sti(pchar.GenQuest.CitizenConflict) > 3)
			{
				dialog.text = "� �� ����� � ����� ��������. �� ��������� ��� ������� �� ������ �������, ������������ �� �� �����. ����� ����� �� ���� �������!";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = ""+pchar.name+"! ��� �� � ��� ���� ������! � ����, � ����, ��� ��� ����� - ������! ���� ������, �� ��� ���� ���������� ������!";
				link.l1 = "�� �����, ������, �������! � ���� ��������� ��� ������ ����.";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				break;
			}
			// ��� �� ���
			if (CheckAttribute(npchar, "quest.drink") && npchar.quest.drink == "fail")
			{
				dialog.text = ""+pchar.name+", � ������� � ����� ���������. ����� �������� ����� ���� ��������� ��������. ������ ������ �����?";
				link.l1 = "��, ��, �������, ��� � ���� �������. � ���� ������ �� �������... �������?";
				link.l1.go = "drunk_fail";
				break;
			}
			if (CheckAttribute(npchar, "quest.drink") && npchar.quest.drink == "win")
			{
				dialog.text = "��, �� ��� ���� ����� �������� �����, "+pchar.name+"! �, �����, ������� - ���� ���� ��������� �������� ���. � �������� ��� ����� ������. ���, ����� ���� ������ ��������.";
				link.l1 = "������� �� ������ �����, �������!";
				link.l1.go = "drunk_win";
				break;
			}
			// �������� �����
			if (CheckAttribute(npchar, "quest.drink") && npchar.quest.crab == "begin")
			{
				dialog.text = ""+pchar.name+"? ��� ������ ������, ��� �� ��������� �� ��� � ���������� ������� �������� ��������. ��� ������, ���, ��� ������, ������� �������?";
				link.l1 = "����� �� ����, �������. � ������������� ��������� ��� ����.";
				link.l1.go = "crab";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "����������� ������ �������� � ���� �������! ����� ����������! � ���� �� ������ ������� ��� ������ - �����, ��� ������ ������� ����� - � ��� ������ �������� - ��� ��� �������, ��-��... ����. ���� ����� ����� ����������, � � ������ ���� �������.";
				link.l1 = TimeGreeting()+", �����. ���� ����� "+GetFullName(pchar)+". ������� �������������.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�, ��� ���� "+pchar.name+"! ��� ��� ������ � ���� �������, ��� ������! ������� ������?";
				// ��������� �����
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_1" && !CheckAttribute(npchar, "quest.mushket"))
				{
					link.l6 = "��������, �����, �� �� ������, � ���� ����� ������� ������� ������? �� ������� ���������� �����, � ���-������ ��� ���������� ��������, ������ � ������������?";
					link.l6.go = "mushket";
				}
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_2")
				{
					link.l6 = "��������, �����, � ���� � ���� ��������� ��������. � ��� �������� �� ����� ������ ������. �������, ��� �� � ���� ��������� ����������...";
					link.l6.go = "adolf";
				}
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "barmen_whiskey")
				{
					link.l6 = "��������, �����, �������, � ���� ��������� ��� ������ �� ������ ������� �������...";
					link.l6.go = "whiskey";
				}
				if (CheckCharacterItem(pchar, "talisman1") && CheckAttribute(npchar, "quest.rat"))
				{
					link.l7 = "�����, ������, � ���� ���-��� ������? �� ��� �� ����� ������� ���� �� ��� ������� ����������?";
					link.l7.go = "rat";
				}
				if (makeint(pchar.money) >= 25)
				{
					link.l1 = "����� ��� ����, �����.";
					link.l1.go = "drink";
				}
				if (makeint(pchar.money) >= 20)
				{
					link.l2 = "��� ����� ������������.";
					link.l2.go = "room";
				}
				if (stf(environment.time) >= 6.0 && stf(environment.time) <= 18.0 && makeint(pchar.money) >= 300)
				{
					link.l9 = "���������... �����, � ���� �������� � ���� � ������� �� ������ � ���������� �������� ����. ��� � ����� ��������...";
					link.l9.go = "drink_sit";
				}
				link.l3 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
				link.l3.go = "rumours_LSC";
				if (CheckAttribute(npchar, "quest.crab") && npchar.quest.crab == "current" && CheckCharacterItem(pchar, "crab_pincers"))
				{
					link.l10 = "�����, � ���� ������� ���� �������� ������.";
					link.l10.go = "crab_trade";
				}
				link.l4 = "�����, � ���� ������ ���� ���� �������� �� �������.";
				link.l4.go = "int_quests"; //�������������� ����
				link.l5 = "���, ��������. � ������ ����� ��������� ����.";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "��� ����. �������, � ���� ������ ��� � ���� ���� �� ������ �����, �� ���� �� ����� ����, ��-��! � �������� ��� ������� ���������� ���� �������.";
			if (makeint(pchar.money) >= 25)
			{
				link.l1 = "����� ��� ����, �����.";
				link.l1.go = "drink";
			}
			if (makeint(pchar.money) >= 20)
			{
				link.l2 = "��� ����� ������������.";
				link.l2.go = "room";
			}
			link.l3 = "�����, � ���� ������ ���� ���� �������� �� �������.";
			link.l3.go = "int_quests"; //�������������� ����
			link.l4 = "��� ��������, �����!";
			link.l4.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "mushket":
			dialog.text = "���, �������, �� ��������. ������ ��, � ���������� �� ������ ������� � ������ ��������, �� ����� �� �� ��������, ��-��! ������ � ��������, ��� � ������, � ����� � ������� ������������ ���������� �������� ������� ������. �����, ��� � ��������� ����.";
			link.l1 = "������� �� �����!";
			link.l1.go = "exit";
			npchar.quest.mushket = "true";
		break;
		
		case "adolf":
			dialog.text = "������? ��, ������ �� � ����, ������, ��������� ��� ���-�� �� �������. ��� ������� �� ����� �������� � ��������� ��������, ��� � ������ ����� �����.";
			link.l1 = "��������? �� �� � �������� ����� ��?";
			link.l1.go = "adolf_1";
		break;
		
		case "adolf_1":
			dialog.text = "��, �������, � ��� �� ������� ���� ��������, ������� ���. ��, ������ � ���. ��� ������ ��������� �����, ���� ���, ��������� �������������, � ����� ����.";
			link.l1 = "���������?";
			link.l1.go = "adolf_2";
		break;
		
		case "adolf_2":
			dialog.text = "������. ���� ���� ��� ������ ������. ��������, ���� ����� ������� � ����� � ����� �� '��������' � ����������� ��� ������ �� �������.";
			link.l1 = "������, ��� � ��������.";
			link.l1.go = "adolf_3";
		break;
		
		case "adolf_3":
			dialog.text = "��� ��? �� �������, ��� � ���� ��������� ��������...";
			link.l1 = "��. ����� ���, ��� ����� ������� ���� � ������ ��������?";
			link.l1.go = "adolf_4";
		break;
		
		case "adolf_4":
			dialog.text = "������� ���� - ���� �� ��������. ������� �������� �������, �� � ���������� ����� ����������, ��... �� ������ � ���������� ����������� �� ���� ������ ������. ���� ��������� ����� ������, ������� ����� ����� ������, ���� ���� ������� �� ���������\n������ ���������� �� ������ ������ �����, ����� �� ������ �� ������������, � ������ ���� �� ������ ���� � ���� ����������. ����� � ���� � ����� �� '����� �����', ���� ����� � ���������� �����... �� ������, ��������-�������� � �������� - ����-�� ���� ������\n��� �������� ��������, ��� ������ ������� �� �����, ��� ��� ����� ��� ��������� ���� ���. �������������� ���. �������, ��� � ������� �� ��� ����������� ������, ������� ���� � ��� � ������� � ������ ��������, �� ����� �� ������� ��� ���� � �������\n���� ��������� ���� �������, ������, ����� ��� �� ���. �������, ��� �������������, �������� ��� ������ ������ � ���������� ���� �������� �������.";
			link.l1 = "�������. ������� �������, �����, �� ��� ����� �����!";
			link.l1.go = "adolf_5";
		break;
		
		case "adolf_5":
			dialog.text = "�� �� �� ���, �������, ������ ���, ��������� �� ��������� ���...";
			link.l1 = "�����������!";
			link.l1.go = "adolf_6";
		break;
		
		case "adolf_6":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "search_mush_3"; //���� �� ��������
			AddQuestRecord("SharkHunt", "13");
		break;
		
		// ����� ��� �����
		case "whiskey":
			dialog.text = "������? ���. �� � ��������� ����� ���� �� ������� �� ���. �� ������� ������� � ���� ��������� �������� ���� ����� ����� �������� ������ - ��� ���� �������� �����. ��� � ��� �������... ����� �� ��� ���, ���������.";
			link.l1 = "�������� ������?!";
			link.l1.go = "whiskey_1";
		break;
		
		case "whiskey_1":
			dialog.text = "�� ��. � �� ������ � ���� ���-�� ��������?";
			link.l1 = "���, �� ���! ������ � ��� ������� ���� ��� ���, � ���, �����������, �� � ���� �������. �� �������, ���� �� ����������?";
			link.l1.go = "whiskey_2";
		break;
		
		case "whiskey_2":
			dialog.text = "�� ������ ������ � �������� ������, ��� ����� �� '�����-����������'. ��������, � ���� � �����.";
			link.l1 = "�������!";
			link.l1.go = "whiskey_3";
		break;
		
		case "whiskey_3":
			dialog.text = "���� ���� ����� ������ - ���� ������� ������� �� ��� ������� ��������.";
			link.l1 = "������. �������� � ����� ��������� �����, �����. �����!";
			link.l1.go = "whiskey_4";
		break;
		
		case "whiskey_4":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "whiskey_poison"; // ���� - ����� ������
			AddQuestRecord("SharkHunt", "37");
			sld = CharacterFromID("LSC_Adolf");
			LAi_SetActorType(sld);
			ChangeCharacterAddressGroup(sld, "SantaFlorentinaShipInside4", "goto", "goto2");
			sld = CharacterFromID("Dodson");
			sld.dialog.currentnode = "whiskey"; // ���� �����
			// ������ ������! �� ����������� ��������� ������� ������� ���������
			pchar.quest.LSC_Whiskeypoison_SF.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_SF.win_condition.l1.location = "SantaFlorentinaShipInside4";
			pchar.quest.LSC_Whiskeypoison_SF.function = "LSC_WhiskeyPoison_SF"; // ���������� �� �����-����������
			pchar.quest.LSC_Whiskeypoison_AE.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_AE.win_condition.l1.location = "AvaShipInside3";
			pchar.quest.LSC_Whiskeypoison_AE.function = "LSC_WhiskeyPoison_AE"; // ���������� �� ���
			pchar.quest.LSC_Whiskeypoison_exit.win_condition.l1 = "location";
			pchar.quest.LSC_Whiskeypoison_exit.win_condition.l1.location = "LostShipsCity_town";
			pchar.quest.LSC_Whiskeypoison_exit.function = "LSC_Whiskeypoison_exit"; // ���������� �� ����� �� �������
			// ��������� ���� � �����
			LocatorReloadEnterDisable("LostShipsCity_town", "reload20", true);
			LocatorReloadEnterDisable("LostShipsCity_town", "reload24", true);
		break;
		
		// ��� �� ���
		case "drunk_fail":
			dialog.text = "�� ��� � �����, ��������! ������ �� ��� �� ������. �� � ��� �������� ���� ������ �� ����� ��������. ��� �� ����� �� ������ � �����...";
			if (sti(pchar.money) >= 500)
			{
				link.l1 = "���-���, �����! �������, ���, ������ ������� ����. �������� �� ������� �� ����� � ������. �� ���� ���� ������.";
				AddMoneyToCharacter(pchar, -500);
			}
			else link.l1 = "��, �������, �����. ��, ��� ���� - �� ����.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "quest.drink");
		break;
		
		case "drunk_win":
			DialogExit();
			TakeNItems(pchar, "gold_dublon", 200);
			Log_Info("�� �������� 200 ��������");
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "quest.drink");
		break;
		
		// �������� �����
		case "crab":
			dialog.text = "��... ����� � ���� � ���� ����� �����������. �� �� �������� �� ��� ���������� ������?";
			link.l1 = "�������� �� � ������? �� �� ��� ����� ����! � ��� �� �����������?";
			link.l1.go = "crab_1";
		break;
		
		case "crab_1":
			dialog.text = "���� ���� ����� �������� �������� � ������ � ������� � �� ������ ���, �� ������ �������� � ���� ������ � �������� ���. � ����� ������ ������� �� ���. ���� ������� ���� �� ����, � ��������� - �� ���� ����� �� �����. ������ ���� ������� �� ��������, ������. ���, � �� �������� ���� ��������� �� ������, �� �� �������, �� ���� ����� ���������...";
			link.l1 = "� ������ ������ ������? ������ ����� ����� ����������? � ��� �� � ���� �������?";
			link.l1.go = "crab_2";
		break;
		
		case "crab_2":
			dialog.text = "������ ������? �� ������ ��� �� ��� ��������� ������ ����� ����. �� ����� � ������ ���� ����� ���, � ���� ������� ������� ��������. ���� �� �� � �����, � ��� �������� ���� - ���������, ��������� ��� ����� ������� � �����������\n� � ��� ���� ������ �� ���� ����� �����, ������� �� ������ ������� ����� �� �������, ��� ��� � �������� �� �������� ���������� �� ���� � �� �����. ������� � � ����� ������� �� ���� �������� �� �����.";
			link.l1 = "������. ���� ����� � ����.";
			link.l1.go = "crab_3";
		break;
		
		case "crab_3":
			DialogExit();
			npchar.quest.crab = "current";
		break;
		
		case "crab_trade":
			iTotalTemp = GetCharacterItem(pchar, "crab_pincers")
			dialog.text = "�������! ������� � ���� ����?";
			link.l1 = ""+FindRussianQtyString(iTotalTemp)+".";
			link.l1.go = "crab_trade_1";
		break;
		
		case "crab_trade_1":
			dialog.text = "�������. ���, ����� ���� ������� - "+FindRussianQtyString(iTotalTemp*5)+". �������, ��������, ���� �������� ��� ������� - ����������� �������!";
			link.l1 = "������, �������.";
			link.l1.go = "crab_trade_2";
		break;
		
		case "crab_trade_2":
			DialogExit();
			RemoveItems(pchar, "crab_pincers", iTotalTemp);
			TakeNItems(pchar, "gold_dublon", iTotalTemp*5);
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� "+iTotalTemp*5+" ��������");
		break;
		
		// ����
		case "rat":
			dialog.text = "���?! � ��, ������ ��� �������! ��� �����������!";
			link.l1 = "����������.";
			link.l1.go = "rat_1";
		break;
		
		case "rat_1":
			PlaySound("interface\important_item.wav");
			dialog.text = "���... ����� - ���! ������� ����� ��� � ��������� �����, �������������� � ���! �������, �� ���� �� ������ ��� ������ �� ���, ������? ��� �� �� ��� ������? �������?";
			link.l1 = "�� �������, �� ������ ���. ��� � ����? �� ����. � ��� �� �����������? ��������, �� ������ ������������ ��-������...";
			link.l1.go = "rat_2";
			link.l2 = "������, ��������, �� � �� �� ������. ��� ����� ��� ������. ������ � ����� ���������, ��� ��� ������������� ��� ����� ������.";
			link.l2.go = "rat_exit";
		break;
		
		case "rat_exit":
			PlaySound("interface\important_item.wav");
			dialog.text = "��, ����� �������... ��, ������, ������ �����, ��� � ���� ��� ����� ��������. ��������! ������ ���� ����� �� ������� ����. � � ��� ��� � ���� ������� �� ��������...";
			link.l1 = "������, �����, ��� ���������� ����. ������ � ��� ������� ��� ������ �� ����� � ����� ���� ������������. ������.";
			link.l1.go = "exit";
			DeleteAttribute(npchar, "quest.rat");
		break;
		
		case "rat_2":
			dialog.text = ""+pchar.name+", � ����� ���� �� ��� ����� ������ � ������� �������, ������� � ���� ����. ��� �� ����� �� � ����, � ������� �����, ����� ����, ����� �������� ������� ����� �������. ������ �������\n���, ��������: ����������, ������������ ��������� ������ ������� ������! ������� �������� � ���, ����������� �� ��������� ��������, ������, �������. ����� �� ������� ���� � ����� �� �������, �� � � ������ ��������\n� ����� ���� ������ � ����������� ����� ������ ���������� �������� ������� ��������� ��� ����� � ������ ���������� ��� ������ ������, ����� �������� �� ���-�� ������. �, ������, ���� ������ ��������. ���� ���� ��� ������ ������ �� ��������� ����!";
			link.l1 = "��... �������� ������! �����, ����� ����� ���� ����������. � ������� � ���-������ ���������, � ��� ������ ����� ������ � ������ �� �����. � ����� ������� ����. �������������, ���������� ������.";
			link.l1.go = "rat_3";
		break;
		
		case "rat_3":
			dialog.text = "� ���, ��� �� ����������, �������. ������� ���� �� ��, ��� �� ����� ��� ��� ��������! ����� ������, � ����� ��� ������ ���� �������� ������� � ���.";
			link.l1 = "����� � �� ���� ������ - ������, ��� ���� � ����� ������� ��������� ������ ���!";
			link.l1.go = "rat_4";
		break;
		
		case "rat_4":
			DialogExit();
			GiveItem2Character(pchar, "cirass4");
			RemoveItems(pchar, "talisman1", 1);
			Log_Info("�� ������ ������ '�������� ���'");
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "quest.rat");
		break;
		
		//--> �������������� ����
		case "int_quests":
			dialog.text = "����������� ���� ������.";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "��� ��� �� ����� �����? ������ ����������� ����������?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "��� ����� ������ ������ �� ���������?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "��� ��� ������� ����� �� �������?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "� ��� ���� ������-�� ���? ��� ���� �������?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "��� ��������. ������...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "�����? ��, ��� �������� �������� ��������������, �������� �������� ��������, �� �� ��� ����� ������ ������. ������� �� ������� �������� ��������, ������� �� ���������� ����� �����. ����������� ����� ������� ������������� ��� ����� ���������, � ������� ������ - ����������. ����� � ������� ����� ��� ��� ������ ��� ���.";
			link.l1 = "�������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "��������� ����� ��� ����. �� ���������� ��� ����� ��� ����: �� ������� ������� - ���������� ���� �������. ������� ����� ����� �������� � ����� ������, � ������ ������ ����� ������ �����. � ���� ��, ������ ������� ������� �������, ������� ��������� ���� ����� �������, ��� ��� ���� �������� ������� �����������, ���� �� ������, ���� ����������� ���\n� �������� ��� � ���� �� ������ - ��������� �� ���. � ���������� �� ������ �� �������, ������ ��� ���� ��������, ��� �������� ������ �� ������ ����� ����������� ������������. � ��������� ������� �������, ������� ������ ������ ������ ������� � ������� ����� ������� - ������ � ����� ��������, �������� �� ������ ����������� �������\n� ���� ��, ���� ��� ����� ������� ����������� ������� �� ������� �������� ������ � �������� ����� ����, � ��� ������, ����� ���� ����� - ������������. ��� ��� ����� �������� � ����� � ���\n����� �� �������: ���, ��� ����� ����� ���� �� ���-������ ����, ��������� ��� ���� ������� � �������� �����, � �� ������, ��� ���������, � ������, ��� ����� ������ �� ����, � ��� ����������� - �����, ��� �� ������� �����. ����������� � ����� - ��� ����� ���� ���, ��� ����� �������� ������.";
			link.l1 = "����...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "� ������ ������� �� ������ ������� � ���, ��� �� ��� ����� �� ������� �������� ��� ���������� ���������. �� ������� ����� ��� �����������, ��� ����� - ������� � �������, ��� ��� ���� ���� ��������. ����� ������� �������� ����� ����� � ��������� �������� ���� ����������, �� ������ �������. ���� �� ���������� �������� � ��� ��� ���������� - ��� ���� �������� �����\n����� ������ � ��� �� �������, �� ������ ����� ������� ������. �� ������ �� ��������� ����, ��� �� ��������� � ��� �� ���������� �� ������ - ����� ���������� ������ ����� ����-�����, �� ������� ������ �������������, ��� ������ ���� �� �������. ��, � ���� �� ���-���� �������� - �� ����� �� ����.";
			link.l1 = "����� � ��������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
		break;
		
		case "ansewer_4":
			dialog.text = "�� ������, �������, ���������. �� ����, ��� � ����� �� ������, ��� ��� ������������ ���� ������� � ���� � ��������: ������� �������, ��� � ������, ����������� � ���������, ���������, ����� �� �������. � ����� ����� ���� - ��� ������� ������� ��� ������ � ����� ������� - ����� ������� ������������ �������\n��� ��� ������ ��������, �� � ������ ������ �������. ���� ��� � ����������� ����� �����������, ���, �� ������� ���� - �� ������, ����� � ��� ������������ �� �����������. �� ������� � ���� ������ ���������� - �� � ����� ����������, �� � ������... � �����, ��� ������ �����, ������� ���� � ���� � �����. � ��� ���� ������\n������������, ��� ���� �������� - ��� �����. ������ ��������, ���������, ����� �� ��� ���. ������, ������ ��� �������� � ������. ����� ����������� �� �� ����.";
			link.l1 = "�����? ��, ��� ��� ��� ����...";
			link.l1.go = "ansewer_4_1";
		break;
		
		case "ansewer_4_1":
			dialog.text = "���, �� ��� '�����' ������ ������. ���� �� ������ �������� ���� ��������� ����������, � � �������� ������ ����� �� ������ ��� - �� ����, ��� �� ��������� �� ������� - �� � ���� ���� ��������� �������� ��������� �������. ��, ������������ ��� ������, ��� �� ������� ����������� ������ ������\n'�������� ���' ����������. ����� ��� ����� � ���� ����� ������� ����. �������, ��� ��� ������� ����� �������� ����� ����������� ��� �������. ������, ������ ���-�� ������ ����� ������ - �� ������� � ����������� ���� ����, ��� ���� ������� �� ������� ������\n������ �� ��� ��� ����� ������ - ������� �����, ������������ �� ��-������!";
			link.l1 = "���������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
			npchar.quest.rat = "true";
		break;
		//<-- �������������� ����
		
		//--> �������
		case "drink":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 4)
			{
				dialog.text = ""+pchar.name+", ��-�����, ���� ������� ������������. �� ��� ��� ���� ������ ���������, ��� �������� ���� �� ����, ��� ��������� �� ���� ������ � ������... � ��� ������ ������� ���������� ������, � ��� �� ������ �������� ����� � ������ ������ �������.";
				link.l1 = "��... �������, �� ����, ����� - � ��� ���������� �����. ������� �� ������!";			
				link.l1.go = "exit";
			}
			else
			{
				AddMoneyToCharacter(pchar, -25);
				if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
				{
					if (CheckAttribute(pchar, "questTemp.Rum"))
					{
						pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
					}
					else pchar.questTemp.Rum = 1;
				}
				else 
				{
					if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
				}				
				WaitDate("",0,0,0, 0, 30);
				
				dialog.text = "����������, ��������. ����� �� �������� ���� ���� - ����� ����� ������� ����!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("��, �� ���� �������� � ����������� ������ ���������, �������!","��, �� ���, ��� � ����!","��, �� �������� ������� ������ �������!"), LinkRandPhrase("��, �� ��, ����� ���� ������ ����� �����!","��, �� ��, ����� ����� ������ ��� �������� �� ���� �����!","��, �� �������, �����, ������� �... ������!"));		
				link.l1.go = "drink_1";
			}
		break;
		
		case "drink_1":
			DialogExit();
			LAi_Fade("", "");
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
			}
		break;
		
		case "drink_sit":
			if (chrDisableReloadToLocation || pchar.questTemp.Saga.SharkHunt == "barmen_whiskey" || pchar.questTemp.Saga.SharkHunt == "whiskey_poison") //���� �����
			{
				dialog.text = "� �����, ��� ���� �� ����� ������ ��������. ������ ���...";
				link.l1 = "�����.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.MaryBye") || CheckAttribute(pchar, "questTemp.LSC.MaryWait")) // ���������� � ����
			{
				dialog.text = "���, �� �� ����� �����, �����... ����� ���� �� � ��� ��������� ����� �� �������? �������, �� ���� ����� ���� ������ �������, ���� ������, ��� � �������� ���� ��� ����������� � �������� � ����������. ��������� ������� ������ � ����������, ���� �� ������ ����.";
				link.l1 = "�����...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�� �� ������, �������. �� �����-�� ��� ����� ���� �� �������� ������� ��������� "+LinkRandPhrase("����������","������������","������������")+" ����, � ������������, ������� ���� ������.";
				link.l1 = "�������!";
				link.l1.go = "drink_sit_1";
			}
		break;
		
		case "drink_sit_1":
			DialogExit();
			sld = ItemsFromID("potionrum");
			sld.shown = true;
			sld.startLocation = "FleuronTavern";
			sld.startLocator = "bottle";
			DoQuestReloadToLocation("FleuronTavern", "quest", "sit2", "LSC_DrinkSit");
		break;
		//<-- �������
		
		//--> ��� � �������
		case "room":
   			if (chrDisableReloadToLocation || pchar.questTemp.Saga.SharkHunt == "barmen_whiskey" || pchar.questTemp.Saga.SharkHunt == "whiskey_poison") //���� �����
			{
				dialog.text = "� �����, ��� ���� �� ����� ������ �����. ������ ���...";
				link.l1 = "�����.";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.LSC.MaryBye") || CheckAttribute(pchar, "questTemp.LSC.MaryWait")) // ���������� � ����
			{
				if(!isDay())
				{
					dialog.text = "������ ������ � ��� �� ��������. ��� ���� �� '����� �����' ������������� �������, � �� � ������� �������� ��������. ���� �� �����, ��� � ���� ������� � ���� �����. ���� ����� ���� �� ����� ������.";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "������ ��������� � ���� ������� �� ������. �� �������� ����� � ���� �� ������� - ���� ���� ����� �� ����� ������. �� �� ������...";
					link.l1 = "������. � ������� � ���� �� ������.";
					link.l1.go = "hall_night_wait";
					link.l2 = "�����... ����� � �������� ��� ���.";
					link.l2.go = "exit";
				}
				break;
			}
			dialog.text = "�� ������ ��������� �� �������, ��� ��������� �� ������� �����, ����� �� �������� ����. ����� ���� ���������?";
			if(!isDay())
			{
				link.l1 = "�����.";
				link.l1.go = "hall_day_wait";
			}
			else
			{
				link.l1 = "� ����.";
				link.l1.go = "hall_night_wait";
				link.l2 = "��������� �����.";
				link.l2.go = "hall_day_wait";
			}
			link.l3 = "���������"+ GetSexPhrase("","�") +". �������� ��� ���.";
			link.l3.go = "exit";
		break;
		
		case "hall_night_wait":
			AddMoneyToCharacter(pchar, -20);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate_LSC("wait_night");
		break;
		
		case "hall_day_wait":
			AddMoneyToCharacter(pchar, -20);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			TavernWaitDate_LSC("wait_day");
		break;
		//<-- ��� � �������
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}