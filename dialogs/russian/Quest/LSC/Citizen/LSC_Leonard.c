// ������� ������� - �������
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iPeso, iDubl;
	string sPeso, sDubl;

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
				dialog.text = "� �� ����� � ����� ��������. �� ��������� ��� ������� �� ������ �������, ������������ �� �� �����. ����� �����!";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			// --> ��� �� ���
			if (!CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && !CheckAttribute(npchar, "quest.facio"))
			{
				dialog.text = "��������, �� ��� ��� �������... � ���� � ����� ������������... �� ������ ����. ������� ����.";
				link.l1 = "��� ���? �������, �� ������ � �� ���� �����. ���-�� ���������? ���-�� ���������� ������ ���� �������.";
				link.l1.go = "facio";
				break;
			}
			// <-- ��� �� ���
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "�-�... ��! �������, ��������, ���� �� ������...";
				link.l1 = TimeGreeting()+". ������, �� ��� ������� ��������, �������.";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�, "+GetFullName(pchar)+"! ��! ��� ���� ����?";
				link.l1 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
				link.l1.go = "rumours_LSC";
				link.l2 = "� ���� ������ ���� ���� �������� �� �������.";
				link.l2.go = "int_quests"; //�������������� ����
				link.l5 = "�� ������ ����� ������ ��� � ���� ����. ��� ��������!";
				link.l5.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // ������ �������
			dialog.text = "���! ��������? ��-��! � ���� � �������, �-��! ��, ������� ������� ����, � ��� ���������!";
			link.l1 = "������ ������? ��, ���� ����� "+GetFullName(pchar)+". ����� �������.";
			link.l1.go = "meeting_1";
		break;
		
		case "meeting_1":
			dialog.text = "������� - ��� �������. �� ��� ���, ��... �������.";
			link.l1 = "�����, ����, ���� �� �� ����������. �����!";
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
			link.l2.go = "rumours_LSC";
			link.l3 = "� ���� ������ ���� ���� �������� �� �������.";
			link.l3.go = "int_quests"; //�������������� ����
			NextDiag.TempNode = "First time";
		break;
		
		// --> ��� �� ���
		case "facio":
			dialog.text = "��, �������, � ����� �����. ��� ������, ��� � ���� ���� ������ ����, ����� ������. � ��, �������, ������ ���������...";
			link.l1 = "����? ��� �� ��� �������? ����� ����������, �� ����� ��� ����� �������!";
			link.l1.go = "facio_1";
			npchar.quest.facio = "true";
		break;
		
		case "facio_1":
			dialog.text = "��������, �� ������ ������������� �����? ���������� ����, ������� ��������? � �����, ���. �� �� ������ ����� �� ���� � ���� - �� ����� �������� �� ����.";
			link.l1 = "���������� � ������ ����. ������ ��� ������� �� ����, ��� �� ����������: � �� �� ��� ���� ������������, ���� �� ������� ��������� ������.";
			link.l1.go = "facio_2";
		break;
		
		case "facio_2":
			dialog.text = "����, �������, �� ����� ������, �� ���� ������ ���������... � ������� ������ ������������ ����. �� �� ��������, � ���� � ��� ����� �����. ��� � ��� ������� - ���� �� � ��� ����������. ������ �����: ��� �� ���������� ���? ����� �� ������� ������, ������ ��� ��������� ��� ����?";
			link.l1 = "��, ����� ���. �� ����, ���-�� �� ���� �������� ���������� � �������... �� �����-������ ������� �� ���� ������ �����������, ��� ������ ��� ����� ���� �� ����� ������?";
			link.l1.go = "facio_3";
		break;
		
		case "facio_3":
			dialog.text = "� ��� ����� �������� ����, ������ �� ���� �� �����. �����. �������� ���������. ���� � ��� �� ������� ���� ������� ������� - �������� �����. ��������, ����� ���� �� �������. �������� � ��������, � �������, � ������ �������. � ����� � ���� ��������������, � ���-��� ������\n� ���� � ����� �� '��������' ���� ��� �������: � ����� �� ������ ������ ������, � �� ������ - ������� � ���������� ������. ��� ������� ���������� �� ����, ������ ������ - �� ����. ������� ������� �� ���������� � ����� �������...";
			link.l1 = "���, �������, �� ������� �������� �����? � � ���� ����������� �� ����. � �������, ��� � �� ����� �������� �� ����, ��� ��� �� � ���� ��������. ������ ������� � ������ �������� - ��� ���� ������� ���������.";
			link.l1.go = "facio_exit";
			link.l2 = "��! ���������! ���������...";
			link.l2.go = "facio_4";
		break;
		
		case "facio_exit":
			dialog.text = "���, ����� ���... ��� ����� ���� ������, ������� �� �� �����. �����, �����, ��� �� ������...";
			link.l1 = "�� ����. ������.";
			link.l1.go = "exit";
		break;
		
		case "facio_4":
			dialog.text = "� ������ '��������' � ����� ����� ��� �����. ���� �� ��� ������ �������. ��� ���, ����, ���������� ������ � ��������, ��������� ����� � ��� �����. �� �� ����, ����� ��� ����� ��������, �� ��� ����. ���������� ����� ����� ���� ����, ����� � ���������� � �����, � �������� ������. �������� ������: ��� ������� ����? ��� ��� - � ���� ���� ����\n����� ������� ���� - � ������ ������ ����� ���� �� ������, ��� ��� ���������, � ��� �������. ������ �� ������������� �������. �� ��� ���������� ����������� ��� ����� ��������, ������ � ������� �������. �� ���� ��������?";
			link.l1 = "����� �����������. ���������.";
			link.l1.go = "facio_5";
		break;
		
		case "facio_5":
			dialog.text = "����� ����� �������� � ������� � ����� � ���������� ������, ������ ��� ���� ����� �������, ��� ������� ��� �� �����. ������� �� � �������� ���� �����������: ���� �� ����, ��� ���� ��������. ���� �� ���������� ��� ��� - �� ����������� ����������\n� ��� ���-�� � ���������� ����� �������. �� ���������� � ��� ����, �� ������� ����� � �����, ��������� ��� � ��������� ���� ������ �� �������, ���� ���-�� �� ��� ������ �� ��������. ���� ���������� �� - ���� ����������, ��� � �� ����� ��� ������� ���\n������� � � ������� - ������� �� � ���� ������. ���� �� ���� �������� ������� ����� �� ��������� ����������� �����, ������ - ���� � �����. � ��� ����� ���� �����. ��� ������ �� ��������� - � ������ � ���� ���� �� '��������'\n����� �� ������� �������� � ����� �� ������� ������, � ���� �� ����� �������� - ��������� � ����� '��������', ������� ������, ������� ����������, �������, � � ����� ���� ����� �� ����� - ��� � ������. ������� ��� � �� ������, ��� ��� ��������\n������� � ������� ���� � ���� �� ����, ���� ������ - ������� ����� � ���������� � �����. � ���� ������ �� ������, ���� �� ������ �������� � ��� �������, � � ������ ���� - ������� ��������, � �� �������� ����� �������� �������\n���������� ������� ������� �������. ��� ����� �����������. �� ���, ����� �����������?";
			link.l1 = "�������� ����! �������, ����� ���������!";
			link.l1.go = "facio_6";
			link.l2 = "���, ��������. � ���. �����, �� ����� �������� ������� ����, ����� ������� ����� � �������� �� �����. ����� ���� ������� ���������, ��������.";
			link.l2.go = "facio_exit";
		break;
		
		case "facio_6":
			dialog.text = "� ���, ��� �� ������ � ����, ������. ������ ������ � ����� � ���������� � ������� � ������� �������, ����� ������. �������, �� ��������� ����� ������. ����� � �� ������� �������!";
			link.l1 = "� ����������... ����!";
			link.l1.go = "facio_7";
		break;
		
		case "facio_7":
			DialogExit();
			NextDiag.CurrentNode = "facio_wait";
			pchar.questTemp.LSC.Drink = "begin";
			pchar.questTemp.LSC.Drink.Chance = drand(100); // ���� ��������
			if (CheckAttribute(pchar, "questTemp.CanDrink")) pchar.questTemp.LSC.Drink.Chance = sti(pchar.questTemp.LSC.Drink.Chance)+50;
			SetFunctionTimerCondition("LSC_DrinkOver", 0, 0, 3, false); // 3 ���
			AddQuestRecord("LSC_Drink", "1");
		break;
		
		case "facio_wait":
			dialog.text = "��������, � ����������� �� ����. ����� ����� ��������...";
			link.l1 = "��-��...";
			link.l1.go = "exit";
			NextDiag.TempNode = "facio_wait";
		break;
		
		case "result_0":
			dialog.text = "���, ��� ������ ������ ������� �������. ���� � ����. �� �������� �������� - ������, � ���� ������ �� � ����� �����!";
			link.l1 = "��, �� �����. ����� � ��� �� �����������. ������ ����������... �� ���, ����?";
			link.l1.go = "result_win";
		break;
		
		case "result_1":
			dialog.text = "���, ��� ������ ������ ������� �������. ���� � ����. �� �������� �������� - �����-���� �������� ����� ������...";
			link.l1 = "�����, �� � ��������� ��� �� ���������. ������� ������, ������ ������... �� ���, ����?";
			link.l1.go = "result_win";
		break;
		
		case "result_2":
			dialog.text = "��, �������, ���-���� �� ������� �� ������ ����� ��������... ����. ��, �� ��� ��������� - ���� ����������...";
			link.l1 = "�-����, ���-����, �� ������ �����-��... ������-�-��� ���-���. ����, ��� ���� ���-����... ���, ���-�������! ��!..";
			link.l1.go = "result_fail";
		break;
		
		case "result_win":
			dialog.text = "��. ����! ������ �� ���� � '��������'! �� �� ��� �� ����������, ������� � �����!";
			link.l1 = "�����!";
			link.l1.go = "result_win_1";
		break;
		
		case "result_win_1":
			DialogExit();
			NextDiag.CurrentNode = "result_win_2";
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload6", "LostShipsCity_town", "reload", "reload39", "LSC_DrinkGotoCarolina", -1);
			AddQuestRecord("LSC_Drink", "3");
		break;
		
		case "result_win_2":
			pchar.quest.LSC_Drink1.over = "yes"; //����� ������
			dialog.text = "������. ����� ����. ������ ������ - ����� �� �����. ������ ������������ ���������� ���� � �����. �� ������ �������� ��� �����. ���� ����� ��� �������������� - ������� ���� � ����� ��� ����. � ���� ������ ��� ������ � ���� ����� �������� �������.";
			link.l1 = "������. ������ � ���!";
			link.l1.go = "result_win_3";
		break;
		
		case "result_win_3":
			DialogExit();
			GiveItem2Character(pchar, "key_facioQ");
			NextDiag.CurrentNode = "result_grabbing";
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "reload", "reload25", "LSC_DrinkGotoCarolina_3", -1);
		break;
		
		case "result_grabbing":
			// ������� ������ � ������� ������ �� �������
			iPeso = sti(pchar.money)-sti(pchar.questTemp.LSC.Drink.Money);
			iDubl = GetCharacterItem(pchar, "gold_dublon")-sti(pchar.questTemp.LSC.Drink.Dublon);
			if (iPeso <= 0) sPeso = "�� ������ ����";
			else sPeso = ""+FindRussianMoneyString(iPeso)+"";
			if (iDubl <= 0) sDubl = "�� ������ �������";
			else sDubl = ""+iDubl+" ��������";
			if (iPeso <= 10000 && iDubl <= 10) sTotalTemp = "��� �� ������ �����... � ���� ����� �� ���������? ��... �����, �����, ��� ����.";
			else
			{
				if (iPeso <= 50000 && iDubl <= 100) sTotalTemp = "� �����, ��� � ���� ������... ���� ���� �� �����. ��, �����, �����, ��� ����.";
				else
				{
					if (iPeso <= 100000 && iDubl <= 300) sTotalTemp = "��. �������. ���� ������ ���� ���� ������ �� ���� ��������. �����, ����� ������.";
					else 
					{
						if (iPeso <= 150000 && iDubl <= 500) sTotalTemp = "�������! �� � ����� ����� ���������, ��������! ��� ����� ���� �����! ����� ������!";
						else
						{
							sTotalTemp = "��� ��� ��! � ���� �� �����, ��� ������� ����� �������� ��� ������. �������� ������, ��������! ������ ����� ������!";
						}
					}
				}
			}
			dialog.text = "�� �������-��! ��� ���� ������� ������ �� ������� ����� ��������? ���������, � ������ �� ����������!";
			if (iPeso <= 0 && iDubl <= 0)
			{
				link.l1 = "� ���� ��� ������ ������ �� ����. ������ ��������� - ������� � ������ ������.";
				link.l1.go = "grabbing_0";
			}
			else
			{
				link.l1 = "� ���� � ������� "+sPeso+" � "+sDubl+"";
				link.l1.go = "grabbing_1";
			}
		break;
		
		case "grabbing_0":
			dialog.text = "�� ����� ����! ����������, ��� ���� ���... ��������, ���� ��� ��������� ���� ������� �� ������ ������. ��! �����, ����� ����, ������ ��� ����� �������, ���� �� �� ��������. �����, ��������...";
			link.l1 = "...";
			link.l1.go = "grabbing_exit";
			AddQuestRecord("LSC_Drink", "6");
		break;
		
		case "grabbing_1":
			dialog.text = sTotalTemp;
			link.l1 = "����� �������...";
			link.l1.go = "grabbing_part";
		break;
		
		case "grabbing_part":
			iPeso = makeint((sti(pchar.money)-sti(pchar.questTemp.LSC.Drink.Money))/2);
			iDubl = makeint((GetCharacterItem(pchar, "gold_dublon")-sti(pchar.questTemp.LSC.Drink.Dublon))/2);
			AddMoneyToCharacter(pchar, -iPeso);
			RemoveItems(pchar, "gold_dublon", iDubl);
			Log_Info("�� ������ "+iDubl+" ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "���, � ������ ����� ��� ����, ������ ��� ����� �������, ���� �� �� ��������. �����, ��������...";
			link.l1 = "�����, �������...";
			link.l1.go = "grabbing_exit";
			AddSimpleRumourCityTip("����� ���������, ��� ���-�� �������� ��� ������. �� �����, ��� ���� ������������ ������� ����������.", "LostShipsCity", 3, 1, "LSC", "");
			AddSimpleRumourCityTip("������� - �������� ����� ��������! ��� ��� �����, ����� �� ������� ������ � ������� ����� ���� � ����.", "LostShipsCity", 3, 1, "LSC", "");
			AddSimpleRumourCityTip("�� � ������� �� � ���� ������! ������ ������� ���� � �������� �� �����! ��� ���-��...", "LostShipsCity", 3, 2, "LSC", "");
			AddQuestRecord("LSC_Drink", "5");
		break;
		
		case "grabbing_exit":
			DialogExit();
			RemoveItems(pchar, "key_facioQ", 1);
			int n = Findlocation("CarolineBank");
			locations[n].private2.QuestClosed = true; // �������� ������
			LocatorReloadEnterDisable("CarolineBank", "reload1", false); // �� �������
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload38", "FleuronTavern", "goto", "goto2", "OpenTheDoors", 15.0);
			pchar.quest.LSC_Drink4.win_condition.l1 = "Timer";
			pchar.quest.LSC_Drink4.win_condition.l1.date.hour  = sti(GetTime()+5);
			pchar.quest.LSC_Drink4.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.LSC_Drink4.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.LSC_Drink4.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.LSC_Drink4.function = "LSC_DrinkDelete";
		break;
		
		case "result_fail":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "LostShipsCity_town", "goto", "goto05_2", "", 10);
			chrDisableReloadToLocation = false;//������� �������
			n = Findlocation("CarolineBank");
			locations[n].private2.QuestClosed = true; // �������� ������
			pchar.quest.LSC_Drink4.win_condition.l1 = "Timer";
			pchar.quest.LSC_Drink4.win_condition.l1.date.hour  = sti(GetTime()+5);
			pchar.quest.LSC_Drink4.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.LSC_Drink4.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.LSC_Drink4.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.LSC_Drink4.function = "LSC_DrinkDelete";
			AddQuestRecord("LSC_Drink", "4");
		break;
		// <-- ��� �� ���
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
//--------------------------------------- ���� �������� � ������� ---------------------------------------------
		case "int_quests":
			dialog.text = "�� ��� �� ����� ��������... ��! ������...";
			if (!CheckAttribute(npchar, "quest.answer_1"))
			{
				link.l1 = "��� �� ����� ����?";
				link.l1.go = "ansewer_1";
			}
			if (!CheckAttribute(npchar, "quest.answer_2"))
			{
				link.l2 = "�� ���, ��������� �����? ��� �� �� �������� ������ �� �������?";
				link.l2.go = "ansewer_2";
			}
			if (!CheckAttribute(npchar, "quest.answer_3"))
			{
				link.l3 = "��� �� ������ ������� ��� ������� �������?";
				link.l3.go = "ansewer_3";
			}
			if (!CheckAttribute(npchar, "quest.answer_4"))
			{
				link.l4 = "�� �� ����� ������ ������ �����, �� ������� �����?";
				link.l4.go = "ansewer_4";
			}
			link.l10 = "��� ��������. ��������...";
			link.l10.go = "exit";
		break;
		
		case "ansewer_1":
			dialog.text = "���! ������� - �� �����. ��-��, �� �����, ��! ����� ��� ����. ����� � ����-�� � �����-�� � ����, � �������� ���. ��!";
			link.l1 = "��... ��-��.";
			link.l1.go = "int_quests";
			npchar.quest.answer_1 = "true";
		break;
		
		case "ansewer_2":
			dialog.text = "��, � ���... ���, ���� ������, ��� ������ ��� ������ ������... �����, �������, � �������� �������. � ������� � ���� �������� ���� - ������� ����. � � ���� ����. � ������... ��-��, � �� ����� �� ��� � �� ����. �� � �������� ��� ��� ���� �� ����\n���� ��� ���� ��������, ��� ���� �����, �� ���� ���� ���������, ������� � ������� ��� � ����� ������ �����, ����� �� � ��������� �������... ��! �-��, ���, ���� - �� �����, ��-��, ���� � �� ���������...";
			link.l1 = "����...";
			link.l1.go = "int_quests";
			npchar.quest.answer_2 = "true";
		break;
		
		case "ansewer_3":
			dialog.text = "� ��� � ����, ��... ��� ��� �������? ������� ����, �� ������� ����� ��������, ���������. ���, �������� ����� - ����� ������ �������, ����� �������, �� ������ ������� ������� - � ���� ��������� ��������� ��������, �������� ��� � �������. ������, ������ ������ ���-�� �������, �� ��� ����� ������, ��!\n���, ���� �� ��, ������� ����� ��� ������ ��������, ���-��! ����� ���� ������� ����� ���������������� � ������ ���� �����, ������ �� ������, � ���� ����� ������ � ���� ���. � �� �� ������� ��� �����. ��� ���� ���, � ����...";
			link.l1 = "�������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_3 = "true";
			SaveCurrentNpcQuestDateParam(npchar, "quest_date");
		break;
		
		case "ansewer_4":
			dialog.text = "������? ��! � �����? ���, �� ����, �� �� �������, �� �� �����. ��� ����� ���� ���������� ���? ���, ��� ��� ���, ��! ������, ��� ��� ������ ������... ��������, ��� � ��� ������. � ����� ������ - �� ����������� �� �������, ����� �� ���-������ ������ ������. ����� ����-������ ������� - �����, ��!";
			link.l1 = "�������...";
			link.l1.go = "int_quests";
			npchar.quest.answer_4 = "true";
		break;
// <-- ���� �������� � �������
		
//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//��������� �� ����������� ������
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("������, �� �� ����� ������. � �� ���������� �������...", "������, � ��� ��� �� ������� ��������� �����������. ����� ������.", "������, ��� ��, ��� �'��������, ������� ���, ������ ������? ����� ������, �� � ���� ��� ���������� �������...");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "��������� �� ���������, ��������, ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� ������� ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����.", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- ����������� �������
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}