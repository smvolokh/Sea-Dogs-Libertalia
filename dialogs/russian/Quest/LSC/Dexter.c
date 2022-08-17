// ������� ����� - ������ �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "���� ����, ������? �� ���� �������� - � �����, �� ����� ����������.";
				link.l1 = "�� � ���� �������������-�� � ����� �����, ��� ��� ��������� ���������?";
				link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				if (CheckAttribute(npchar, "quest.map"))
				{
					link.l2 = "������, ��� ����� ������, ��� � ���� ���� ����� �������. �� ��� �� �� ��� �� �������?";
					link.l2.go = "map";
				}
				dialog.text = "�-�, "+GetFullName(pchar)+"! �� ������ ���� ������, ��� ����� ������ ���������? ���� ���������, � ��������� ��� ���� � ����� ������� ����, ��-��.";
				link.l1 = "��, �������� ����������� ���� ���. � ������ ���� - ����� � ��������.";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
			dialog.text = "��! �� ������, ��� � �������. �����... ���� ����� ������ �������, � � ������� �����, � ����� - ��� ����������� �� ���� ��������� �������. � ��������� �� ����� ����� � ��������� �������� �������������� � �������������� ����� �� ����� ����������� �����.";
			link.l1 = "�� � � - "+GetFullName(pchar)+". ����� �������!";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		// ����� ����� �� �������� N
		case "admiral":
			dialog.text = "�����, ��� ���� ��� �� ����� ��������. ������ ����. � ����� ��������� ���� �������.";
			link.l1 = "�� ����, �������� ��� ���� ��� ����� �� ����� ��������... ������ �� - �������?";
			link.l1.go = "admiral_1";
			AddQuestRecord("SharkHunt", "28");
			CloseQuestHeader("SharkHunt");
		break;
		
		case "admiral_1":
			dialog.text = "������ ���. ��� ������������ �� ������� ��������, ������ ����� - ������, �, ��� �������, ������������� ���������� ���������. � ���� ���������� ����?";
			link.l1 = "���. ������� ����������.";
			link.l1.go = "admiral_2";
		break;
		
		case "admiral_2":
			dialog.text = "��� � ������. ��� ��� �� ���� �������� ������ ��������� �� ���.";
			link.l1 = "�� ���-�� ������ ������ �������� �� ������ �������?";
			link.l1.go = "admiral_3";
		break;
		
		case "admiral_3":
			dialog.text = "�� ������ � ���� - ������� �� � ������ ��� ������ ��������? ���. ���������� ���� ����� ����������� ������ �������� ���� ��������. � ������ ��� ��� ���� �� �������������� � ��� ����. ����� ������\n� ���� ��� ����� ������� ��������� '���-��������' - ��� ���� ��� ���, �� ��������� �� ��������� �����. ����� ����, � �������� ���������� ���������� � �������. �������, ���������� �������� ������, �� � � ����� ��� �� ��� �� ������ �������, �� ����� �������� �������.";
			link.l1 = "�������. �����, ������, � �����...";
			link.l1.go = "admiral_4";
		break;
		
		// ���� �����������
		case "admiral_4":
			dialog.text = "������. ������ ����������� ���, ��� �� ������� ���-�� �������� ������, � ����� ��������� ���� �� �������?";
			link.l1 = "������ ��� � � ��������� �������.";
			link.l1.go = "admiral_5";
		break;
		
		case "admiral_5":
			dialog.text = "����� ����� ��� ��� �����. ��������� ��, �� ������� ��������� ���� ������� �����... � ����� ����. �� ���� �� ������ �� ����, �� ������ ������ �������� � �� ������� � ������\n��� ���� ����� �� ���� �� ������� ���� ������, ���� ��������� �������� �������� �������� ������ ������� ����� ������. ����� ����, ����: ������ ����� ���� ����� ������ ����� � ������������ ��������� �������, ����������� � ������������. ������, �����, ����������... � �����, �� ������� ���������� ������. �� ��������� ���� �� �����\n� ���� ����� ���� ������� �� �����-������ ������ ���� ������ ��� �������, ��� �� ������� ������� - ��� ������ �� ��������� ����� ���� � ������������ ���������� �� ���. ��� � ��� ���� �������� ������� ����, ��������, ��� �� '��������'.";
			link.l1 = "�������! ��� ������ ��, ��� �����.";
			link.l1.go = "admiral_6";
		break;
		
		case "admiral_6":
			GiveItem2Character(pchar, "LSC_navigation_map");
			dialog.text = "� ����� ������ ������������, �� ������ ��������� ������� ����� ������ ������� ���������� - ��� �� ���������, � ������ ��� ����� �� ����� ������� ����. ����� ������ �� ��������� - ������ ������� ���� ����. � ��� ���� �������� ���� ������, ��� ������ ��� ��������� ���� ��� ������, � ������ ��� �� ���� ��� ��������.";
			link.l1 = "������ �� ������������ �� ���� ����. ������� ��� ��� � �� �������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "Dexter_wait";
			AddQuestRecord("LSC", "5");
			CloseQuestHeader("SharkHunt");
			// ������� ��������� ��������
			sld = ItemsFromID("key_capper");
			sld.price = 10;
			if (CheckCharacterItem(pchar, "letter_chad")) RemoveItems(pchar, "letter_chad", 1);
		break;
		
		case "Dexter_wait":
			dialog.text = "��� ������ � ������ ������ � �������, "+pchar.name+"?";
			link.l1 = "���� �����, ������. � ������� ��� ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Dexter_wait";
		break;
		
		// ����� ����� �� �������� M
		case "admiral_7":
			dialog.text = "��� � ��, "+pchar.name+". ��� ����� ������ � ����� ��������� ��������.";
			link.l1 = "��� � �����, ����� ������ ������� �� ����� ��� �����. ������ �� - �������?";
			link.l1.go = "admiral_8";
		break;
		
		case "admiral_8":
			dialog.text = "������ ���. ��� ������� �����, � ������������� ���������� ��������� �������. � ���� ���� �����-�� ����������?";
			link.l1 = "������. ��� ����� ����������� ���� �� �����.";
			link.l1.go = "admiral_9";
		break;
		
		case "admiral_9":
			dialog.text = "����� ���, ��� �� � ����� ����� ����� ����� ����. ������ �� ���� �������� ��������� �� ���.";
			link.l1 = "�� ���-�� ������ ������ �������� �� ������ �������?";
			link.l1.go = "admiral_10";
		break;
		
		case "admiral_10":
			dialog.text = "�� ������ � ���� - ������� �� � ������ ��� ������ ��������? ���. ���������� ���� ����� ����������� ������ �������� ���� ��������. � ������ ��� ��� ���� �� �������������� � ��� ����. ����� ������\n� ���� ��� ����� ������� ��������� '���-��������' - ��� ���� ��� ���, �� ��������� �� ��������� �����. � ���� �� � ��� ������ �������� ��������� � ������� - ������� �� ������� ��������.";
			link.l1 = "�������. �� ���-�� ��� ����� ��� �������? ��� � ���� ����?";
			link.l1.go = "admiral_4";
		break;
		
		case "plan":
			PlaySound("VOICE\Russian\LSC\Layton Dexter-07");
			dialog.text = "�������, ����. ���������� ����������� ��������� ������� ����� ��������. ���, �������, �� ��������, �� ������������ � �� ����. ��������� ���� ������� ����������� �� '���������', ������������ �� ����������� �������. �� ������� ��� ������ ����������� �� ���� � ������� '����� �����'\n� ���� �� ������ ����� �������, ��������� ����� ������ �������, ������� '����������' �� ������� '���' � '������'. � ���� �������, ����� ����� ����� ������� �������� � '���-��������', ��� ������ ��������� �� ������ '����� �����' � ������� �� �������� � ���� - ����� ��� ����� ��������� ���� ������� �� ��� ������, � �� �� ����� ������, ���� ����� � ������ ������� �� '���-��������'\n������ ����� ��������, ��� ��� '���-��������' ��������� ��������� � ��������� ������� - ����� ��� ����� ��������. ������ ������ ��������� ������ ������ '����������' � '����� �����', � ��� '���-���������' ����� �������� �� �������, �, ��������, �������� ����� ���������� �����.";
			link.l1 = "";
			link.l1.go = "plan_1";
		break;
		
		case "plan_1": // ���� �����
			DialogExit();
			npchar.greeting = "dexter_1";
			sld = characterFromId("Dodson");
			sld.dialog.currentnode = "whyskey_final_3";
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
			NextDiag.CurrentNode = "plan_2";
		break;
		
		case "plan_2":
			dialog.text = "�� ���� ����������� ��������� � ��������� �������. ��� ����� �����, �� ����� ����� �������.";
			link.l1 = "��� ���!";
			link.l1.go = "exit";
			NextDiag.TempNode = "plan_2";
		break;
		
		case "map":
			dialog.text = "��, � ���� ���� �����. ������ ������? ����������. ������ �������� �� ����� - � ��� ����.";
			link.l1 = "� � ���� �� ������?";
			link.l1.go = "map_1";
		break;
		
		case "map_1":
			dialog.text = "���. ��� ����� �������. ��� ��� ���� �� ��������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 200)
			{
				link.l1 = "������. ����� ���� ������, � ��������.";
				link.l1.go = "map_2";
			}
			link.l2 = "��� � ���� ������ ������� ��������. ��������, �����...";
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "map_2":
			RemoveItems(pchar, "gold_dublon", 200);
			PlaySound("interface\important_item.wav");
			Log_Info("�� �������� ����� ������� ��������������");
			GiveItem2Character(pchar, "map_LSC");
			dialog.text = "�������� ������, ������! ����� ���� �����. � ��� �� �� ��������� - ��� � ������ ������ �� ����� ���������� �������, ���� ��������� ��. ��� ��� ��� �������� ������.";
			link.l1 = "��� ��������? ��-��. �� ��� ����� - �������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			DeleteAttribute(npchar, "quest.map");
		break;
		
		// �������� ����� �������� �� �������������� ��� �����
		case "LSC_GameOverPrison":
			dialog.text = "������, ����! ��, ����� ��� ���� - ���� ��� ����� � ���. ������� ����� ���������� ��-�� ����... ���� ���, ������, ������� ��� �����, ����� �� ��������! ��� ���� ���������� �����������!";
			link.l1 = "...";
			link.l1.go = "LSC_GameOverPrison_1";
		break;
		
		case "LSC_GameOverPrison_1":
			DialogExit();
			DoQuestReloadToLocation("TartarusPrison", "quest", "prison4", "LSC_GameOverInPrison");
		break;
		
		case "return":
			dialog.text = "������ �������� ���� ��������� ������� ������ ���� - ��� � �������, �� ��������� �� ������ ������. � ������� ����� � ���� ����� ���� - ������ ����� �������� ���� �� �� �������� �� ��������. ���� ���� �������, ��� �� ����� ������ �������� �����.";
			link.l1 = "�������, ������. �����, ��� � ��� �� ��� ������ ������.";
			link.l1.go = "return_1";
		break;
		
		case "return_A":
			dialog.text = "�, ��� ������ �������� "+GetFullName(pchar)+"! �� ���-���� ����� ������ �� ����� �������? �����, ����� ��� ���� ������. �� ����� ������ �������� �����.";
			link.l1 = "�������, ������. �����, ��� � ��� �� ��� ������ ������.";
			link.l1.go = "return_1";
		break;
		
		int iTrade = GetSquadronGoods(pchar, GOOD_FOOD)-GetCrewQuantity(pchar);
		int iMoney = 0;
		case "return_1":
			dialog.text = "����� ������. ��, �� �������� �� ����� �������� ��� ���������? � ����� ������ ��� � ���� �� ����������� ����.";
			if (iTrade > 0)
			{
				link.l1 = "��, � ���� ������� ���� ��������� ���������� ���������.";
				link.l1.go = "trade";
			}
			link.l2 = "� ���������, ������ ��� ������ ���� �������.";
			link.l2.go = "return_2";
			npchar.quest.foodqty = 0; // ������ ������� ������� = 15 000
		break;
		
		case "return_2":
			dialog.text = "����. � ��������� ��� �� ������ ��������� - � ������ ������� �� ����.";
			link.l1 = "������. ���������� �� ������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "head";
		break;
		
		case "trade":
			dialog.text = "������� ������?";
			link.l1.edit = 4;
			link.l1 = "";	
			link.l1.go = "trade_1";
		break;
		
		case "trade_1":
			iTemp = dialogEditStrings[4];
			int iMax = GetSquadronGoods(pchar, GOOD_FOOD)-GetCrewQuantity(pchar);
			if (iTemp <= 0 || iTemp > GetSquadronGoods(pchar, GOOD_FOOD))
			{
				dialog.text = "���� ������, �� �� ����, �������... ��� ��������, � ��������� �������� �����.";
				link.l1 = "��...";
				link.l1.go = "exit";
			break;
			}
			if (iTemp <= 50)
			{
				dialog.text = "���� ������ ���������� � ���� ���� ������� �� ����� �� ������. ������� ������!";
				link.l1 = "��...";
				link.l1.go = "exit";
			break;
			}
			if (iTemp > iMax)
			{
				dialog.text = "� ��� ��, �������, ����������� �������� � ���� ��� ��� �� �������? ������ ���� ���� �� "+FindRussianQtyString(GetCrewQuantity(pchar))+".";
				link.l1 = "��, ���-�� � �� �������.";
				link.l1.go = "exit";
			break;
			}
			iMoney = (50+drand(5))*iTemp;
			dialog.text = ""+FindRussianQtyString(iTemp)+"? ������. � ������� ���� �� ����� "+FindRussianMoneyString(iMoney)+". ����������?";
			link.l1 = "�������! ������� ������!";
			link.l1.go = "trade_2";
			link.l2 = "��. ���, �������, � ��������� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "head";
		break;
		
		case "trade_2":
			iTemp = dialogEditStrings[4];
			iMoney = (50+drand(5))*iTemp;
			AddMoneyToCharacter(pchar, iMoney);
			RemoveCharacterGoods(pchar, GOOD_FOOD, iTemp);
			npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			if (sti(npchar.quest.foodqty) >= 15000) // ������ �������� �� �������
			{
				SetFunctionTimerCondition("LSC_ClearFoodStorage", 0, 0, 180, false);
				dialog.text = "��� � ������! ������ ��� ������ ��������� �������. �� ��������� ������� ������������� � ������� ��������� ��������.";
				link.l1 = "������. ����� ��������� ������ � ������� ���� ����� ����� �������.";
				link.l1.go = "exit";
				AddQuestRecord("LSC", "25");
			}
			else
			{
				dialog.text = "��� � ������! ������� ���.";
				link.l1 = "�����������!";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "head";
		break;
		
		case "head": // ����������� ������ ��������-��������
			dialog.text = "�-�, "+GetFullName(pchar)+"! ��� ���� ������! �� ������ ���� ���������?";
			if (iTrade > 0 && sti(npchar.quest.foodqty) < 15000)
			{
				link.l1 = "� ���� ���������� ���� ������ � ���� ��������� ���������� ���������.";
				link.l1.go = "trade";
			}
			link.l2 = "�� ����������, �� �� ������ - ����� � ����� ������������� � ������, ��� ����.";
			link.l2.go = "exit";
			NextDiag.TempNode = "head";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}