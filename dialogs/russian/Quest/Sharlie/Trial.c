// ������� ��� �� ������ '��������� �����'
void ProcessDialogEvent()
{
	ref NPChar, sld, rColony;
	aref Link, NextDiag;
	int iTemp;
	bool bOk;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "��� ��� �����?";
			link.l1 = "������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ����� ������
		case "lecrua":
			pchar.quest.Trial_LineOver.over = "yes"; //����� ������
			dialog.text = "������ ����. �������, �� - "+GetFullName(pchar)+". � �� ������?";
			link.l1 = "��� �����, ����� ������. ������� "+GetFullName(pchar)+" � ����� �������. ���� ������������ ��� ����� ��������...";
			link.l1.go = "lecrua_1";
		break;
		
		case "lecrua_1":
			iTemp = FindColony("Baster");
			rColony = GetColonyByIndex(iTemp);
			bOk = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			dialog.text = "��-��, ������� ����� ����� ����� ������ ��� - � � ������ �����, ��� ��� ������ ��. �������, �������, ��� � ��� �� �������?";
			if(sti(pchar.ship.type) == SHIP_NOTUSED || !bOk)
			{
				link.l1 = "��-�... � ���� �� ������ ��� �������, �����... ��� ��������.";
				link.l1.go = "lecrua_noship";
			}
			else
			{
				link.l1 = "� ���� "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(RealShips[sti(pchar.ship.type)].basetype), "Name")))+", ���������� - '"+pchar.ship.name+"'.";
				if (5-sti(RealShips[sti(pchar.ship.type)].Class) < 0) link.l1.go = "lecrua_badship";
				else link.l1.go = "lecrua_2";
			}
		break;
		
		case "lecrua_noship":
			dialog.text = "��! �� ��� ����� �� �� �������, ���� � ��� ��� ���� �������? ��������, �����, �� � ����� ������ ������� ������ � ���� ��� ��� ���. ����� �������, ����������� ������ �����!";
			link.l1 = "��...";
			link.l1.go = "lecrua_exit";
			sTotalTemp = "� ������ ������ � ��� ��� �������";
		break;
		
		case "lecrua_badship":
			dialog.text = "��, ��� ������ ����������. ����� �� ��� �������? ��� ������ ������� �����! ���, �����, �� �� ��� �� ���������. ����� �������, ����������� ������ �����!";
			link.l1 = "��...";
			link.l1.go = "lecrua_exit";
			sTotalTemp = "��� ������� �� ������� ����� �����";
		break;
		
		case "lecrua_exit":
			DialogExit();
			npchar.lifeday = 0;
			NextDiag.CurrentNode = "lecrua_repeat";
			AddQuestRecord("Trial", "3");
			AddQuestUserData("Trial", "sText", sTotalTemp);
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
		break;
		
		case "lecrua_repeat":
			dialog.text = "�� ���� ��� ��� � ���� ��������, �����, ����� �� ���?";
			link.l1 = "��-��, ����� ������... � ��� ���.";
			link.l1.go = "exit";
			NextDiag.TempNode = "lecrua_repeat";
		break;
		
		case "lecrua_2":
			dialog.text = "�����������. � ����� ������ �� ��� ���������. �� ������ ����������� � ���� ����������?";
			link.l1 = "��, �����, �����. ��� � ������ �������?";
			link.l1.go = "lecrua_3";
		break;
		
		case "lecrua_3":
			sld = characterFromId("BasTer_trader");
			dialog.text = "�� ������ ��������� ��������� ������ ������ � ���� � ���� ����-�-������, ��� �� ����������� ���������. ��������� ��� �������� ���� ����, ��� ��� ��� �� ������� ������ ������� - � ��� � ������������ �� ����� �������� ����\n��������� "+GetFullName(sld)+" ����������� � �������� ���������� ����� �� ���� ������ �����. ������ �� ����� �������� � ���������� ����� - ���� ����� ����.";
			link.l1 = "� ��� ��� ������?..";
			link.l1.go = "lecrua_4";
		break;
		
		case "lecrua_4":
			dialog.text = "���, �������, �����. �������� ������ ��� �������� ���������, �������� �� �������� ����� � �����, �� ��������. ���� ����� - ����� ���� ����� ����� ������, ������� ��� ���������. ��� ��� �� ���������������: ���� �������� �������� - ������� ������ ����������.";
			link.l1 = "�������! � ����� ��� ����������� �����������. ��� ����� ������ ������� ���� �� ����.";
			link.l1.go = "lecrua_5";
		break;
		
		case "lecrua_5":
			dialog.text = "����� �� ����� ������ �������, �������! ������������� �� ���� ������� � ���������� � ������ � ����.";
			link.l1 = "��� ���!";
			link.l1.go = "lecrua_6";
		break;
		
		case "lecrua_6":
			DialogExit();
			NextDiag.CurrentNode = "lecrua_repeat";
			AddQuestRecord("Trial", "4");
			CoolTraderHunterOnMap();
			pchar.questTemp.Trial = "fraht";
			SetFunctionTimerCondition("Trial_FrahtFail", 0, 0, 20, false); // ������
			SetFunctionTimerCondition("Trial_LecruaHide", 0, 0, 1, false); // ������
			// ����
			SetCharacterGoods(pchar, GOOD_BOMBS, GetCargoGoods(pchar, GOOD_BOMBS)+1500);
			SetCharacterGoods(pchar, GOOD_POWDER, GetCargoGoods(pchar, GOOD_POWDER)+1500);
		break;
		
		// ������� ����
		case "florian_deck":
			pchar.quest.Trial_CannonFail.over = "yes"; //����� ������
			dialog.text = "��� ��� ������, ������?";
			link.l1 = "������ ����, �������. ��� � �������, �� - ������� ����?";
			link.l1.go = "florian_deck_1";
		break;
		
		case "florian_deck_1":
			dialog.text = "�� �� ��������. �, �, �������, �������: �� - ������ �� ����-�-������, ���?";
			link.l1 = "������! � �������� ��� ���������� ������. ����� ��� �� �������, ��� �����...";
			link.l1.go = "florian_deck_2";
		break;
		
		case "florian_deck_2":
			if (GetSquadronGoods(pchar, GOOD_CANNON_24) < 15)
			{
				dialog.text = "��. �������� � ��� �����, ������! ���-�� � �� ���� �� ����� ������ ������������ ���������� ������ ��� ����� �������.";
				link.l1 = "���� ������! �� �������� �������� � ����� ����� ��������� �� ����...";
				link.l1.go = "florian_deck_fail";
			}
			else
			{
				dialog.text = "��� ��� ������, �������?..";
				link.l1 = ""+GetFullName(pchar)+". ������� "+GetFullName(pchar)+".";
				link.l1.go = "florian_deck_3";
			}
		break;
		
		case "florian_deck_3":
			dialog.text = "������� �������������. �� ����� ������ ������� � ��������� � ���������� ������ �� ��� ������� - ���� ������, ��� ����� ����� ��������!";
			link.l1 = "��� ������ ���������. ������� - ������������� �������� �����...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Trial_TakeCannons");
		break;
		
		case "florian_deck_fail":
			dialog.text = "� ��� ������ �������� ���� �������� ������ ��������? ������������� �� ���� �������, �������, � ��������� ���-������, ��� ������ ��� ��������: ���������� ������, ��� ������ �� ���������. � ��, ����������, ��� ��� � ��� ���������. ����� �������!";
			link.l1 = "��...";
			link.l1.go = "florian_deck_fail_1";
		break;
		
		case "florian_deck_fail_1":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true; 
			RemoveCharacterGoods(pchar, GOOD_CANNON_24, GetCargoGoods(pchar, GOOD_CANNON_24));
			SetFunctionTimerCondition("Trial_RemoveFlorian", 0, 0, 1, false);
			sld = characterFromId("Lecrua");
			sld.lifeday = 0;
			AddQuestRecord("Trial", "10");
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
			ChangeCharacterNationReputation(pchar, FRANCE, -3);
		break;
		
		case "florian_deck_4":
			dialog.text = "�� ���, ���������... ��������� �� ������, �������! ������� ���� ������� - ������ ��������.";
			link.l1 = "�������!";
			link.l1.go = "florian_deck_5";
		break;
		
		case "florian_deck_5":
			TakeNItems(pchar, "gold_dublon", 200);
			Log_Info("�� �������� 200 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ��� ��� �� ���, �������. ������ ���������� ��� ������ ��������� �����?";
			link.l1 = "��! � ��� �� �� ����� ��������� ������! �� ������ ��� �� ��������� �� ��� �������...";
			link.l1.go = "florian_deck_6";
		break;
		
		case "florian_deck_6":
			dialog.text = "������ �������� �������, �� �����. ��� �� ��������� ������, � ��� ����������� ��������� ������� ������ � ������ ������. ���� ������� ��� ��������� � ���� �� �������. �� ���� ���������, �� ������ ��� ������ �� ���� � ���������� � ������ � ���� ��� �����, ������ ����� �� ���������\n����� ����, ��� ����� � ����� ����� ��� � �� ������ ��� �������� ��������� �������� � ����������� �����. � ����������, ��� ������� ��� ��������. ��� ������� ���������� � ����� ����� � ���������� ��������� ��� ����: ������ ������ �� ��� ��� ��������� � ����� � ��� ��������� � ���� �������. �� ������?";
			link.l1 = "�����, � ���� ��� ������� ���������� ��� ���� ������ ����. � � ��� ��������, � ��� ������ �� �����. ���, �� - ���.";
			link.l1.go = "florian_deck_bye";
			link.l2 = "��������� ������, �� ��� �� � ������. ������ ��� ������ �������� � ��� ���������� ������?";
			link.l2.go = "florian_deck_7";
		break;
		
		case "florian_deck_bye":
			dialog.text = "��� ��, ��� ���� �����. � ��� �������. ����� �� ��������, �������, � ��� ��� ������� �� ������!";
			link.l1 = "����� �������, ����� ����.";
			link.l1.go = "florian_deck_bye_1";
		break;
		
		case "florian_deck_bye_1":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true; 
			SetFunctionTimerCondition("Trial_RemoveFlorian", 0, 0, 1, false);
			sld = characterFromId("Lecrua");
			sld.lifeday = 0;
			AddQuestRecord("Trial", "11");
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
		break;
		
		case "florian_deck_7":
			dialog.text = "�������! ������ ����� ������� ������, �� � ����� ����� �� ������������ ��� ����� �������, ��������. ������ ����� ��� '����������'. ������� ����������� � ����� �����, ����� ������� - ������ � ����� ����� ������ ����� �������������, �� � ������������ �������� ���� ������� �� ���������� �����. ������� �� �������� � ��� �� ����� ���� �����. �����, �����!";
			link.l1 = "����� ��������, ����� ����...";
			link.l1.go = "florian_deck_8";
		break;
		
		case "florian_deck_8":
			bQuestDisableMapEnter = true;//������� �����
			pchar.GenQuest.MapClosedNoBattle = true; // �������� �������� � sailto
			DialogExit();
			npchar.DeckDialogNode = "florian_deck_repeat";
			NextDiag.CurrentNode = "florian_deck_repeat";
			pchar.questTemp.Trial = "spy";
			AddQuestRecord("Trial", "12");
			pchar.quest.trial_spy_over.win_condition.l1 = "Timer";
			pchar.quest.trial_spy_over.win_condition.l1.date.hour  = sti(GetTime() + 2);
			pchar.quest.trial_spy_over.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 2);
			pchar.quest.trial_spy_over.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 2);
			pchar.quest.trial_spy_over.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 2);
			pchar.quest.trial_spy_over.function = "Trial_SpyTimeOver";
		break;
		
		case "florian_deck_repeat":
			dialog.text = "�� ���� ��� ��� ��������, �������, ����� �� ���?";
			link.l1 = "��-��, � ��� ���...";
			link.l1.go = "exit";
			NextDiag.TempNode = "florian_deck_repeat";
		break;
		
		case "florian_failspy":
			pchar.quest.trial_spy_over.over = "yes"; //����� ����������
			dialog.text = "��� ������, �������? ��� ������� ������?";
			link.l1 = "������ ��� ������ �������������, ����� ����. ���-���� ����� �� ���� �������� - �������� ���� ����� ������. �������� ���������� �� ������ � ����. ������������, ��� ��� ������� ������ - ��� ��� �������, ������� ������, ��������� � ��������� � ������.";
			link.l1.go = "florian_failspy_1";
		break;
		
		case "florian_failspy_1":
			dialog.text = "���� ������! ��� ������ �������... ��� ������ ������ �� ������?";
			link.l1 = "������.";
			link.l1.go = "florian_failspy_2";
		break;
		
		case "florian_failspy_2":
			dialog.text = "����. ��� ����� ����� ���������� � ���. �����, �������� ������� ��� ������ ���������... �������, � ��������� ��� ���� �� ������� ������. ��������, ��� ����������� ���� ������. ��������� �����-������, ���� � ������� ���-������ �� '����������'?";
			link.l1 = "��. �������, �������! � ���� ����� �� ����� ����������������� �� ������.";
			link.l1.go = "florian_9";
			link.l2 = "���, �������. ������, �������� ���� �� ��� ����. � ����������� ��������.";
			link.l2.go = "florian_failspy_3";
		break;
		
		case "florian_failspy_3":
			dialog.text = "��� ��, ��� ���� �����. ����� �������, �������.";
			link.l1 = "��������, ����� ����.";
			link.l1.go = "florian_failspy_4";
		break;
		
		case "florian_failspy_4":
			DialogExit();
			bQuestDisableMapEnter = false;
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true; 
			SetFunctionTimerCondition("Trial_RemoveFlorian", 0, 0, 1, false);
			sld = characterFromId("Lecrua");
			sld.lifeday = 0;
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
		break;
		
		case "florian_failspy_5":
			pchar.quest.trial_spy_over.over = "yes"; //����� ����������
			dialog.text = "��� ������, �������? ��� ������� ������?";
			link.l1 = "������ ��� ������ �������������, ����� ����. ���-���� ����� �� ���� ��������. ������������, ��� ��� ������� ������ - ��� ��� �������, ������� ������, ��������� � ��������� � ������.";
			link.l1.go = "florian_failspy_1";
		break;
		
		case "florian_9":
			dialog.text = "����� ������������� �� ��� �������, � ������, �������� � ��� �� �����, ��� ������� �����, ����������� �� ��� �� ����. �����, � ���� ������� � ���-������ ��������. �� ����� �� �������, ����� � ���� �� �����!";
			link.l1 = "������. ��� � ��������.";
			link.l1.go = "florian_10";
		break;
		
		case "florian_10":
			dialog.text = "�, �������: �������� ���� ������. ���� ���-���� ���� ����� �� ���� �������� - �� ������� ����, �� �����, ��� ��������� � �������� ���������...";
			link.l1 = "...";
			link.l1.go = "florian_11";
		break;
		
		case "florian_11":
			DialogExit();
			Island_SetReloadEnableGlobal("Portobello", false);//������� ������	
			npchar.DeckDialogNode = "florian_deck_wait";
			NextDiag.CurrentNode = "florian_deck_wait";
			pchar.questTemp.Trial = "spy_wait";
			pchar.quest.Trial_spyfail_wait.win_condition.l1 = "Timer";
			pchar.quest.Trial_spyfail_wait.win_condition.l1.date.hour  = sti(GetTime()+rand(12));
			pchar.quest.Trial_spyfail_wait.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
			pchar.quest.Trial_spyfail_wait.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			pchar.quest.Trial_spyfail_wait.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
			pchar.quest.Trial_spyfail_wait.function = "Trial_Spyfail_NextStage";
			TakeNItems(pchar, "purse2", 1);
			Log_Info("�� �������� ������ � ���������");
		break;
		
		case "florian_deck_wait":
			dialog.text = "�������, ���� ������� �������� � ���� ���. ����...";
			link.l1 = "������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "florian_deck_wait";
		break;
		
		case "florian_12":
			pchar.quest.trial_spy_over.over = "yes"; //����� ����������
			dialog.text = "��� ������, �������? ��� ������� ������?";
			link.l1 = "��� ����� �������� �������� - ��� ������� ������ ����� �����������. ��� �������, ������� ������, ��������� � ��������� � ������. ��� ���������.";
			link.l1.go = "florian_13";
		break;
		
		case "florian_13":
			dialog.text = "���� ������! ��� ����� �����... ��� ������ ���-������ ������� ������?";
			link.l1 = "��. �� ��� ����� ����� � ������ � ����, �� ���������� ����� ����� ��������� ������ ��� � �����. ������ �� ���� �������� �� ��������� ���������-������ '�����' � ������ ������ ��� '����������'. ���� �� ������ ������� � �������, � ��� �������� ������.";
			link.l1.go = "florian_14";
		break;
		
		case "florian_14":
			dialog.text = "����� ���������!";
			link.l1 = "�� ���� '�����' �� ������ �� ��������� ��� ��� - �� '����������' �� ����� �� ����� � ���������� � ����.";
			link.l1.go = "florian_15";
		break;
		
		case "florian_15":
			dialog.text = "������������ ������, �������! � ����� ������� ����. ���, �������� ���� ��������������. �� ��� ������ ����������!";
			link.l1 = "���������! � ��� ���� ��� ������� ��� ����?";
			link.l1.go = "florian_16";
		break;
		
		case "florian_16":
			TakeNItems(pchar, "gold_dublon", 250);
			Log_Info("�� �������� 250 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ������� ��� �����, �������! ��, ����, ���� ������! ��� �� '����������' ������������ ������, �� � ���� �� ��������� �������� � ���� � ����� ��������� ����� �������� ������� ���, � ������� ��� ����������� ���� ������ ������ ���. ��� ������ �������� ��� ������\n��� ����� ������� ���, ����� ��� ���������, '�����', �� ����� �� ����� �����. � �� ���� ����������� �� ������� ����� ��������� - ��������� ������ ����� ������� ��� �������, � ����� � ������ ���� �� ��������� '����������'\n� �� ������ ���������� � ���� ����������. ���������-������ - ��� ���������� ��� ��������, ����� ����� ����������, ������ ���� ���������� ������� ������, ����� ��� ����� � '���������' �������� �����������. ����� ������� ����� ��������, ��� ��� �� ���� �� � ��������. ������ �� ��� ����� �������, �� ������ ��������� ����� �� ������� ������. � �������� ����� ������ � ���������, �� �� � ������. ������� '�����' � ����������: ��������, ����������� - ��� ��� �����. ���� �� ��� ������ �� ��������� �� ����� �����!\n���� �� ������� ��������� ��� ������ - ������������� �� ��������� � ����� � ������ ������ - ���� �� ������ ���, ���? �� ������ ��� ����������� �������.";
			link.l1 = "������������! ����������� �� �������� '�����'!";
			link.l1.go = "florian_19";
		break;
		
		case "florian_17":
			dialog.text = "����� ������, ��� �� ������, �������. � ��� ��� ������� ������ �������� �� ������ ��������� � � ���� ���� ��� ��� ������������� ���������.";
			link.l1 = "������ ��� �����������.";
			link.l1.go = "florian_18";
		break;
		
		case "florian_18":
			dialog.text = "'����������' ������ � ������ � ����, ������ ������� ������� ���� �������� ���������-������ '�����' �� ��������� � ������ �����������. ���� � ���, ��� �� '����������' ������������ ������, � ������� �� �������� ����������� � ����. ������ �������� ��� �� �����������, � ���� '�����' �� �������� ����� ��� ���, ������ ������� ����� �����\n�� ��� ����� �������� ������, � � ����� �������� ��� �������� ������� ���, � ������� ���� ����� ������������. ���� ������ - ����������� '�����' � ���������� ��. �� ������ ���������� � ���� ����������. ���������-������ - ��� ���������� ��� ��������, ����� ����� ����������, ������ ���� ���������� ������� ������, ����� ��� ����� � '���������' �������� �����������. ����� ������� ����� ��������, ��� ��� �� ���� �� � ��������. ������ �� ��� ����� �������, �� ������ ��������� ����� �� ������� ������. � �������� ����� ������ � ���������, �� �� � ������. ��������, ����������� � - ��� ��� �����. ���� �� ��� ������ �� ��������� �� ����� �����!\n���� �� ������� ��������� ��� ������ - ������������� �� ��������� � ����� � ������ ������ - ���� �� ������ ���, ���? �� ������ ��� ����������� �������.";
			link.l1 = "������������! ����������� �� �������� '�����'!";
			link.l1.go = "florian_19";
		break;
		
		case "florian_19":
			DialogExit();
			Island_SetReloadEnableGlobal("Portobello", true); // ������� ������
			bQuestDisableMapEnter = false;//������� �����
			DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
			LAi_CharacterDisableDialog(npchar);
			npchar.DontDeskTalk = true; 
			SetFunctionTimerCondition("Trial_RemoveFlorian", 0, 0, 1, false);
			Trial_CreatePueblaBarqueInWorld();
			pchar.questTemp.Trial = "puebla";
			AddQuestRecord("Trial", "19");
		break;
		
		// ��������� ������ � �������
		case "tavern_officer":
			dialog.text = "���, ��� ��� ��� � ���? ��������� ����������� ����? ����� ���������! �� ����� ������ ����� �������? �� ��� ��, � ����������� ���� ����� ����������� � ����� ������. ����� ���!";
			link.l1 = "�-����! ��, ����������!";
			link.l1.go = "tavern_officer_1";
		break;
		
		case "tavern_officer_1":
			DialogExit();
			chrDisableReloadToLocation = true;//������� �������
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "Trial_AfterTavernFight");
			AddDialogExitQuest("MainHeroFightModeOn");
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}