// ���������-�������� ������ �������� �����
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp;
	string sTemp;
	float locx, locy, locz;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "������������-������������... ������� �� �������? ���� ���� ��� ���������. ��������� ������������� - �������� �����, ���������� �� ������� ���������� ���� ������� �� ���� ������ ���� ����� ����.";
				link.l1 = TimeGreeting()+". ��� ��� - "+GetFullName(pchar)+". �� �����, � ������������� ����� �������. �������� �� �����������, � ����� ����� �������� �� �������?";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "�, ��� ����� ��, ������� "+pchar.name+"! ��� ������� ��� � ��� �������� ������?";
				if (CheckAttribute(pchar, "GenQuest.NarvalConflict") || CheckAttribute(pchar, "GenQuest.RivadosConflict") || CheckAttribute(pchar, "GenQuest.SharkConflict"))
				{
					link.l10 = "�����, � ���� ������ ��������� �������� � ����� �� ������. ��� ����� ���-�� ������ ��� ��������.";
					link.l10.go = "conflict";
				}
				// --> ��������� �����
				if (CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && pchar.questTemp.Saga.SharkHunt == "search_mush_3")
				{
					link.l4 = "��������, � ���������� �������� �� ����� ������ ������. ��� �������, ��� �� ������� � ��� ���������� �� ������� ��� � �������...";
					link.l4.go = "adolf";
				}
				if (CheckAttribute(pchar, "questTemp.LSC.Drink") && pchar.questTemp.LSC.Drink == "begin")
				{
					link.l5 = "��������, ��� ��� ��� ����� ����������� �����. �������, ��� ������� ��� �� ����� ������� ��� � ���.";
					link.l5.go = "drink";
				}
				if (CheckAttribute(pchar, "questTemp.LSC.Drink") && GetCharacterItem(pchar, "gold_dublon") >= 100 && pchar.questTemp.LSC.Drink == "wait")
				{
					link.l5 = "� ����� ������� � ���� ����. ��� ��� ������.";
					link.l5.go = "drink_4";
				}
				// <-- ��������� �����
				if (CheckAttribute(npchar, "quest.parol"))
				{
					link.l1 = "� ���� ������ ������� ������ ������ ��� ������� �� �� ����������.";
					link.l1.go = "parol_choice";
				}
				link.l2 = LinkRandPhrase("���-������ ���������� ��� ����������?", "��� ������ ��������� �� ������� � ��������� �����?", "�� ���������� �� ��������� �������?");
				link.l2.go = "rumours_LSC";
				link.l3 = "������ ����������, ��������. � ������ ����� ������������� � ����.";
				link.l3.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "������, ��� �������, ������. ��������, � �������� ��������� � ������� ����� ������� � ���������. ��� ��� ������ ���� ��������, �������, ������� � ������� �������� ����� �����. � ����������� �������������� ������������ ����� ���� �� ���������� ��������\n����� ����, ����� �������� � ���� ����������� ������� ��� ������� �������������� ��������� �������������� ������. �� ��� ���� ��������� ����� ���� ������������. ��� ��� ���� � ��� ����� �������� ��������� � ��������� ��� ������� - ����������� �� ���, ��������� ������.";
			link.l1 = "������. � ����� ��� � ��������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		// ������
		case "parol_choice":
			dialog.text = "������ ������ ����� ��� ����������?";
			link.l1 = "��������.";
			link.l1.go = "parol_nrv";
			link.l2 = "�������.";
			link.l2.go = "parol_rvd";
		break;
		
		case "parol_nrv":
			dialog.text = "������ ��������� � �������� �������, � ����?";
			link.l1 = "�����. ��� �� ������ ������� ������ ��������?";
			link.l1.go = "parol";
			pchar.questTemp.LSC.parol = "��������";
			sTotalTemp = sNrvParol;
		break;
		
		case "parol_rvd":
			dialog.text = "������������� � ����� � ������� ����, � ������?";
			link.l1 = "����� ����. ��� �� ������ ������� ������ �������?";
			link.l1.go = "parol";
			pchar.questTemp.LSC.parol = "�������";
			sTotalTemp = sRvdParol;
		break;
		
		case "parol":
			if (!CheckAttribute(npchar, "quest.parolrules"))
			{
				dialog.text = "� ��� ��! �� ������� ��������� ������ ������� ���������. ������ ������ ������������ ����� ���� ������������ ����� � �������� ������ ���� � �����, �� ���� ����������� �����������. ����� ������� ���������� ������� ��������, ��������������, �������� ������� � �������� �������� �����\n��� ��� ������� �� ������� �����, ����� �� ������� �������. �� �, ��� �� ���������, ������ � ��� ����������� �� ���������. ��������� ����� ������ - ��������� ��������. �� ������ � ���� ������ �������, ������ ��� � ����.";
				link.l1 = "��������� ��������? ��� �� ����� ���� �����!";
				link.l1.go = "parol_1";
			}
			else
			{
				dialog.text = "�������, ��� �������. ���� �� ������. � ��� ���� � ����� ��������� ��������?";
				if (GetCharacterItem(pchar, "gold_dublon") >= 50)
				{
					link.l1 = "��. ���, ������� ���� ������.";
					link.l1.go = "parol_pay";
				}
				link.l2 = "� ���������, � ���� ��� ������������ ���������� �����. ��������, �����...";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "parol_1":
			dialog.text = "��-��, ��� �������, �� ����� ��� ����������. �� ����������, ��������: � ������� ���� ���� ����� ����������. ���� �� �� ������� "+pchar.questTemp.LSC.parol+" �� �� �������� ���������, �����? �����. ������, ������ ���� ���� ������ � ����, ��� ��� �������� ���������� � ��������� ������ �����... ��� �� ������ ��������� ��������� ��������?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 50)
			{
				link.l1 = "��. ���, ������� ���� ������.";
				link.l1.go = "parol_pay";
			}
			link.l2 = "� ���������, � ���� ��� ������������ ���������� �����. ��������, �����...";
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
			npchar.quest.parolrules = "true";
		break;
		
		case "parol_pay":
			RemoveItems(pchar, "gold_dublon", 50);
			dialog.text = "�������! ������� ����� � ���� ����. ������� ������ "+pchar.questTemp.LSC.parol+": '"+sTotalTemp+"'. ��������� ����������, � �� ���������, ����� ������ ��������, � ��������� ������ � �� ��� �� ���� ����� � ������� �����.";
			link.l1 = "�� ���� �, ����... ������� �� ����������!";
			link.l1.go = "exit";
			AddQuestRecord("LSC", "parol");
			AddQuestUserData("LSC", "sText", pchar.questTemp.LSC.parol);
			AddQuestUserData("LSC", "sParol", sTotalTemp);
			if (pchar.questTemp.LSC.parol == "�������") pchar.questTemp.LSC.RParol_bye = "true";
			else pchar.questTemp.LSC.NParol_bye = "true";
		break;
		
		case "adolf":
			dialog.text = "��, �� ��� ��, ��� �������� �������! �������, � ��������� � ���. ���������, ��� �������, ����� � ��������� ����������� ���� �����, ������� � ��� � �� ���� �������! ������� ������� � ���� ������� ����� � ���� ��� ����� ������ ����-�������, � �� ����� �� ��� �������\n� ��� � �� �������� �������� �� ������� � ��������� � ������� ������� ������ ������������ ������ �����. � ��� ����������� ������� �������� ��� ��� ������! ��, �����������, �������� �������� ��������, � �� ������ ������� � ���� ���� ������, �� � �������� � ����� ����� ������ �� ����� �� ������� ����� '����� ����������'!\n�������, ��� ������� �������, ��� � ������ � ��������������� �����\n��� ��� ��� ������� ������� ��� ������� � ��� ����� ����, � � - ��� ����� ��������. � ��� �� ��� ���� � ��� �� ������, ��� �����, ��� �� ������?";
			link.l1 = "��, �� �������! ������� �������, ��� �� ������ ���� ������. ��� �����, ��� ��������... �������, ��������, �� ��� ����� �������. ������ � ���� ����, ��� ��� ������ �������.";
			link.l1.go = "adolf_1";
		break;
		
		case "adolf_1":
			dialog.text = "������ ����������, ��� �������. �� �� ����� ������� � ���� � ����� ������ ������ - �� �����, ����� �������, ��� ��, ��� ������ � ������ �� �����... ��, � �� �������� �� ��� ������, ��� ���������!";
			link.l1 = "����� ���� ����� - ����������� �������� ��� �� ���������... ����� ������� � �� �������!";
			link.l1.go = "adolf_2";
		break;
		
		case "adolf_2":
			DialogExit();
			LSC_CreateAdolfClone(); // �������� ������� ������
			pchar.questTemp.Saga.SharkHunt = "search_mush_4"; //���� �� ������� � �����
			AddQuestRecord("SharkHunt", "14");
		break;
		
		case "whiskey":
			switch (sti(npchar.quest.poisonnode))
			{
				case 1: // � ����
					dialog.text = "�? ��� �� ���������� �� ���, ������ ����� �����? ��� �� ���� ����������?";
					link.l1 = "������ � ������� ���� ��� �������... ����������!";
					link.l1.go = "whiskey_1";
				break;
				
				case 2: // �� ���
					dialog.text = "������! �������, ��� ��������� ����! ��� ���������� ��� �������� ��...";
					link.l1 = "�������. � ��� ��� �����. ��� ��������� ������� �� �� ��������? ��� �������� ������?!";
					link.l1.go = "whiskey_3";
					SetFunctionTimerCondition("LSC_FacioReturn", 0, 0, 1, false); // ������� �� ����� ����� ����� �����
				break;
				
				case 3: // � �����
					dialog.text = "�������, ��� ��������� ����! � ��� ��� ��������� ��������! � �� ��� �� ��������������, ��� ��...";
					link.l1 = "�������. � ��� ��� �����. ��� ��������� ������� �� �� ��������? ��� �������� ������?!";
					link.l1.go = "whiskey_3";
					SetFunctionTimerCondition("LSC_FacioReturn", 0, 0, 1, false); // ������� �� ����� ����� ����� �����
				break;
			}
		break;
		
		case "whiskey_1":
			dialog.text = "���... ��� �� ������?";
			link.l1 = "� ��� ����, �������. �� ���������� ������ � ����� ��������. �� ������ ������� � ����������� ����� ��������. ������ ������, �����������...";
			link.l1.go = "whiskey_2";
		break;
		
		case "whiskey_2":
			dialog.text = "����! ����������! ������! �������, ��� ��������� ����! ��� ���������� ��� �������� ��...";
			link.l1 = "�������. ��� �������. ��� ��������� ������� �� �� ��������? ��� �������� ������?!";
			link.l1.go = "whiskey_3";
		break;
		
		case "whiskey_3":
			dialog.text = "�... �... � �� ����!";
			link.l1 = "�����, ������� ����� ������! � ��� ����. ��� ������?";
			if (pchar.questTemp.LSC.Mary == "die") link.l1.go = "whiskey_10"; // ���� �� ������
			else link.l1.go = "whiskey_4";
		break;
		
		case "whiskey_4":
			dialog.text = "��... �� ������� �� ������� �����-�� ������ � ����. � �� ����, ��� ��!";
			link.l1 = "����� �����. �� ��� ������. �� �����, ���������� �����, ������ ����� � ������ �� ������� ����. �� ���� �� �� �������, ��� �������� - � ������� ����, ��� ����, ����� ������! ��� �������� ������� ���?";
			link.l1.go = "whiskey_5";
		break;
		
		case "whiskey_5":
			dialog.text = "�� �������� ��� �����... ������� ����.";
			link.l1 = "���?! ������ ����������, ����� ������� �� ��������� ��� �������? � ��� � ����� �� '����� �����' �� �������, � ��� ������� ��� �����! ��� �� ���������� ����� ��?!";
			link.l1.go = "whiskey_6";
		break;
		
		case "whiskey_6":
			dialog.text = "�� ������� ����� ����� '����� �����', � ����� ������, ����������, ����� ��� ���������. ����� ��������� �� ����� ��� ����� �� ������� - ��� �����, ������� ����, �������. ����� ���� ��������� ������������ ���� � ������ ����� � ����� ����\n������ ��� ����� ����� ������ ���������, ���� ������� ���������� � ���� ������, ��� ������ - � ���, ���� �������. ��� ��� ������ ���. �������, � ������ ������ �� ����!";
			link.l1 = "����� ����������. ����� �� ����? �����, � ���������, ������ ���� �� '����� �����'?";
			link.l1.go = "whiskey_7";
		break;
		
		case "whiskey_7":
			dialog.text = "�� ��� ��������� � ������... ��� ���������� � ����...";
			link.l1 = "���������!! ������ ������ ������� � �� �����! ������ ������ �������� ��� ������� �� �� �������! ������, � ���� ������� - � ��� ����� �������� � �����, �� ����� ���� ����� �����!";
			link.l1.go = "whiskey_8";
		break;
		
		case "whiskey_8":
			dialog.text = "'"+sNrvParol+"'...";
			link.l1 = "� ��������. � ������ ������, ����� ������� �������� ����!";
			link.l1.go = "whiskey_9";
		break;
		
		case "whiskey_9":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			NextDiag.CurrentNode = "whiskey_repeat";
			pchar.quest.LSC_RescueMary.win_condition.l1 = "location";
			pchar.quest.LSC_RescueMary.win_condition.l1.location = "LostShipsCity_town";
			pchar.quest.LSC_RescueMary.function = "LSC_RescueMary";
			AddQuestRecord("SharkHunt", "46");
			AddQuestUserData("SharkHunt", "sParol", sNrvParol);
			pchar.questTemp.LSC.NParol_bye = "true";
		break;
		
		case "whiskey_repeat":
			dialog.text = "� ��� ��� ������, ��� ����! �������!";
			link.l1 = "...";
			link.l1.go = "exit";
			NextDiag.TempNode = "whiskey_repeat";
		break;
		
		case "whiskey_10":
			dialog.text = "��... � ��������� ���-�� �� ��������� '������'. ��� ������ ��� ��������� ��� � ����� ��� ���������� ��������.";
			link.l1 = "�������. �� ������ ���, ���� ������...";
			link.l1.go = "whiskey_11";
		break;
		
		case "whiskey_11":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			pchar.quest.LSC_FindCyclop.win_condition.l1 = "location";
			pchar.quest.LSC_FindCyclop.win_condition.l1.location = "FleuronTavern";
			pchar.quest.LSC_FindCyclop.function = "LSC_SetCyclop_Fl";
			NextDiag.CurrentNode = "whiskey_repeat";
			AddQuestRecord("SharkHunt", "51");
			
		break;
		
		// --> ���������
		case "conflict":
			dialog.text = "��� ���? �� ��� ��, ��� �������, � ����� ������ � ���� ������������?";
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				link.l1 = "C ���������.";
				link.l1.go = "narval";
				npchar.quest.clan = "narval";
			}
			if (CheckAttribute(pchar, "GenQuest.RivadosConflict"))
			{
				link.l2 = "� �������.";
				link.l2.go = "rivados";
				npchar.quest.clan = "rivados";
			}
			if (CheckAttribute(pchar, "GenQuest.SharkConflict"))
			{
				link.l3 = "� �������� ��������.";
				link.l3.go = "shark";
				npchar.quest.clan = "shark";
			}
			link.l4 = "�� � �����. � �������, ��������, � ���� ��� � �������.";
			link.l4.go = "exit";
		break;
		
		case "narval":
			npchar.quest.price = sti(pchar.GenQuest.NarvalConflict)*50;
			if (sti(pchar.GenQuest.NarvalConflict) < 3) dialog.text = "��, ��� ��� �� �������� - ���, ��������� �������������, ��-��. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
			else
			{
				if (sti(pchar.GenQuest.NarvalConflict) >= 3 && sti(pchar.GenQuest.NarvalConflict) < 10) dialog.text = "��� ��, ��� ��, ��������. ����� �� ������� �������, ��� �������. �� ����� ����. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
				else dialog.text = "��� ���� ������ ����� � �����, ������� �� �������. ������ ����� ��� ������, �� �������� �� �����������. "+sti(npchar.quest.price)+" �������� - � � �������� ������ ���� ��������.";
			}
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.price))
			{
				link.l1 = "���, ������� ���� ������ � ������� ��� �����������.";
				link.l1.go = "pay";
			}
			link.l2 = "� ���������, � ���� ��� ������ ������ ���������� ��������. �� � ����������� �������, � �� �������� � ������ ���������.";
			link.l2.go = "exit";
		break;
		
		case "rivados":
			npchar.quest.price = sti(pchar.GenQuest.RivadosConflict)*50;
			if (sti(pchar.GenQuest.RivadosConflict) < 3) dialog.text = "��, ��� ��� �� �������� - ���, ��������� �������������, ��-��. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
			else
			{
				if (sti(pchar.GenQuest.RivadosConflict) >= 3 && sti(pchar.GenQuest.RivadosConflict) < 10) dialog.text = "��� ��, ��� ��, ��������. ����� �� ������� �������, ��� �������. �� ����� ����. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
				else dialog.text = "��� ���� ������ ����� � �����, ������� �� �������. ������ ����� ��� ������, �� �������� �� �����������. "+sti(npchar.quest.price)+" �������� - � � �������� ������ ���� ��������.";
			}
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.price))
			{
				link.l1 = "���, ������� ���� ������ � ������� ��� �����������.";
				link.l1.go = "pay";
			}
			link.l2 = "� ���������, � ���� ��� ������ ������ ���������� ��������. �� � ����������� �������, � �� �������� � ������ ���������.";
			link.l2.go = "exit";
		break;
		
		case "shark":
			npchar.quest.price = sti(pchar.GenQuest.SharkConflict)*50;
			if (sti(pchar.GenQuest.SharkConflict) < 3) dialog.text = "��, ��� ��� �� �������� - ���, ��������� �������������, ��-��. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
			else
			{
				if (sti(pchar.GenQuest.SharkConflict) >= 3 && sti(pchar.GenQuest.SharkConflict) < 10) dialog.text = "��� ��, ��� ��, ��������. ����� �� ������� �������, ��� �������. �� ����� ����. "+sti(npchar.quest.price)+" �������� - � ���� �������� ����� ������ ����� �����.";
				else dialog.text = "��� ���� ������ ����� � �����, ������� �� �������. ������ ����� ��� ������, �� �������� �� �����������. "+sti(npchar.quest.price)+" �������� - � � �������� ������ ���� ��������.";
			}
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.price))
			{
				link.l1 = "���, ������� ���� ������ � ������� ��� �����������.";
				link.l1.go = "pay";
			}
			link.l2 = "� ���������, � ���� ��� ������ ������ ���������� ��������. �� � ����������� �������, � �� �������� � ������ ���������.";
			link.l2.go = "exit";
		break;
		
		case "pay":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.price));
			PlaySound("interface\important_item.wav");
			Log_Info("�� ������ "+sti(npchar.quest.price)+" ��������");
			dialog.text = "������������! ������ ��������������, ���������. �� ��� ���, ���� � �� ����� ��� �������, ��� ����� ������ � ���� �����. � �� �� ��� ���, ����� ��� ���������, �����������.";
			link.l1 = "������...";
			link.l1.go = "peace";
		break;
		
		case "peace":
			DialogExit();
			GetCharacterPos(pchar, &locx, &locy, &locz);
			pchar.locx = locx;
			pchar.locy = locy;
			pchar.locz = locz;
			SetLaunchFrameFormParam("������ �����..."+ NewStr() +"����� ������������ ��� ��������", "Reload_To_Location", 0.1, 5.0);
			SetLaunchFrameReloadLocationParam(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto"), "LocTeleport");
			WaitDate("", 0, 0, 1, 3, 10); //������ �����
			LaunchFrameForm();
			RefreshLandTime();
			RecalculateJumpTable();
			Whr_UpdateWeather();
			switch (npchar.quest.clan)
			{
				case "narval":
					DeleteAttribute(pchar, "GenQuest.NarvalConflict"); // �����
					if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend") || !CheckAttribute(pchar, "questTemp.LSC.rvd_friend")) LocatorReloadEnterDisable("LostShipsCity_town", "reload48", false);//������� ���� � ��������
					LAi_group_SetRelation("LSC_NARVAL", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
				break;
				
				case "rivados":
					DeleteAttribute(pchar, "GenQuest.RivadosConflict"); // �����
					if (CheckAttribute(pchar, "questTemp.LSC.rvd_friend") || !CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) LocatorReloadEnterDisable("LostShipsCity_town", "reload33", false);//������� ���� � ����
					LAi_group_SetRelation("LSC_RIVADOS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
				break;
				
				case "shark":
					DeleteAttribute(pchar, "GenQuest.SharkConflict"); // �����
					LSC_OpenSanAvgustinDoors(); // ������� ���-��������
					LSC_OpenTartarusDoors(); // ������� ��������
					LAi_group_SetRelation("LSC_SHARK", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);
				break;
			}
			DeleteAttribute(npchar, "quest.clan");
			DeleteAttribute(npchar, "quest.price");
		break;
		
		// --> ��� �� ���
		case "drink":
			dialog.text = "�� ��� ��, ��� �������! ����, �� ����, ��-��. ������ � ���� ������ ������, ��� � �����������, �� � ����� �� �������, ��� � ��, � ���� ������ �� ����. ���� �� ��� �� ������� ��������� - ��� �� ��� ����� ���, �? �� �� ������������ ��� ����, ��� ��������������?";
			link.l1 = "�� �����. ��������, � ������ ����� �� ���� �� �� �����...";
			link.l1.go = "drink_1";
		break;
		
		case "drink_1":
			dialog.text = "� ������ ������� �� ���� � ���� �������� ����? ��� ���������� - '��� �� ���', ��-��! ������, �� ��� ������� �� ����. ���� ���?";
			link.l1 = "��, �������� �� ���� ������... ������ � �� �� ������ '������ � ����', ��� ���� ����.";
			link.l1.go = "drink_2";
		break;
		
		case "drink_2":
			dialog.text = "��-��-��, ��� ����� �������, �������� �������, ������ �� �������! ������ � ����! ���� ���������... ��� �������, ��� ���? �� ��� ��������?";
			link.l1 = "�� �����?";
			link.l1.go = "drink_3";
		break;
		
		case "drink_3":
			dialog.text = "��, � ����������� ���������� ��� �������. ��������?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "��, ��������. ��� ��� ������.";
				link.l1.go = "drink_4";
			}
			link.l2 = "��. � ���� ��� ������� ��������.";
			link.l2.go = "drink_wait";
		break;
		
		case "drink_wait":
			dialog.text = "��, ����� ��� ��������� - ����������� ���������, �������, ��������!";
			link.l1 = "������...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Drink = "wait";
		break;
		
		case "drink_4":
			RemoveItems(pchar, "gold_dublon", 100);
			Log_Info("�� ������ 100 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�������, ��� ��������������! ����� ����������� � ������ ������ � ������� � ��������� ����� � �������! ��, ���� �� ����� �����������, ��� ���� ������ ��� �������� ���������� ���� - �� ���� ������ ��������� � ����, ��� ���� �� ������. �� �� ���� �������, ���, ��� �������?";
			link.l1 = "�����������, ��������. ���������� � �������� �� ��������!";
			link.l1.go = "drink_5";
		break;
		
		case "drink_5":
			dialog.text = "� �� ����, ��������������! ������ � ����! �� ���� ��, ��-��!";
			link.l1 = "�� ������� � ������ ����� � �������!";
			link.l1.go = "drink_6";
		break;
		
		case "drink_6":
			DialogExit();
			pchar.questTemp.LSC.Drink = "start";
			pchar.quest.LSC_DrinkOver.over = "yes"; //����� ������
			pchar.quest.LSC_Drink.win_condition.l1 = "Timer";
			pchar.quest.LSC_Drink.win_condition.l1.date.hour  = 21.0;
			pchar.quest.LSC_Drink.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.LSC_Drink.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.LSC_Drink.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.LSC_Drink.function = "LSC_DrinkPrepare";
			pchar.quest.LSC_Drink_Over.win_condition.l1 = "Timer";
			pchar.quest.LSC_Drink_Over.win_condition.l1.date.hour  = 23.0;
			pchar.quest.LSC_Drink_Over.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.LSC_Drink_Over.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.LSC_Drink_Over.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.LSC_Drink_Over.function = "LSC_DrinkDelete";
			AddQuestRecord("LSC_Drink", "2");
		break;
		
		case "drink_8":
			dialog.text = "�� ���, �����������, ������ � ������� �� ������, ��-��? ��� ��� ����������� ����� ��� ������. ������� �� ���� ��������? ��� ����� ������: ���� �� ����� ������� ������ �� ������� �� ���, ���� ���-�� �� ��� �� ����������\n��, ������������� ��� � ����, ��������, �� �����������, �������� - ��������������! ��� �� ���� ��� ������������ - ��������� � ������� ���������! ��, � ���� ��� ������� �������� - �� ���� ���� �������� � �����. ��������?";
			link.l1 = "�������, ��. ���������, ��������!";
			link.l1.go = "drink_9";
		break;
		
		case "drink_9":
			DialogExit();
			pchar.questTemp.LSC.Drink = "go";
			pchar.quest.LSC_Drink_Over.over = "yes"; //����� ������
			ChangeCharacterAddressGroup(pchar, "FleuronTavern", "quest", "sit1");
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(npchar, "FleuronTavern", "quest", "sit2");
			LAi_SetActorType(npchar);
			LAi_ActorSetSitMode(npchar);
			DoQuestFunctionDelay("LSC_DrinkGo", 0.6);
		break;
		
		case "drunk":
			dialog.text = "��-�����-���� ��-����-��, �� ������... ��! ���!.. ��-��-���... � �... �������...";
			link.l1 = "����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "drunk";
		break;
		// <-- ��� �� ���
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}