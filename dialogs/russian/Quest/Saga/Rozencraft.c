// ������� ���������� - ����������� �������, ��������� ���������� �������
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
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "rozencraft":
			if (pchar.questTemp.Saga.Oyster == "cantalk")
			{
				dialog.text = "��... � ��� ��������? �� ���, �� ��������� ��� �� ��� �������?";
				link.l1 = "��� �������� ���� ����� � ��������� ���������. ��� ������ �� �� ��������. � �� ����.";
				link.l1.go = "rozencraft_1";
			}
			else
			{
				dialog.text = "��� ��� ������, ������?";
				link.l1 = "� �������, ��� �� ����� ������ ������� ��� �������?";
				link.l1.go = "rozencraft_no";
			}
		break;
		
		case "rozencraft_no":
			dialog.text = "��� ��� ������ �������� ����, ������? � ������ � ������ �� ���. ��� ����� ��������� ������� ����������� ����������� �� �������������� ������� ��� - �� ����������� ������ ������. ��� ��� �������� �������� ������ ����� �����, ��, ��������, � ���-�� ���� �������.";
			link.l1 = "��.. ����. �������� �� ������������.";
			link.l1.go = "rozencraft_no_1";
		break;
		
		case "rozencraft_no_1":
			DialogExit();
			AddQuestRecord("Testament", "8");
			NextDiag.CurrentNode = "rozencraft_no_repeat";
		break;
		
		case "rozencraft_no_repeat":
			dialog.text = "�� ��� ��������, ������, ����� ���?";
			link.l1 = "��, ��. � ��� ����������� �� ���� �������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "rozencraft_no_repeat";
		break;
		
		case "rozencraft_1":
			dialog.text = "� �� ���-�� ���?";
			link.l1 = "����� ���� �������, � ��� ����� ����? � ������ ������ �� �������. ������� �� �� ���� ���������?";
			link.l1.go = "rozencraft_2";
		break;
		
		case "rozencraft_2":
			dialog.text = "�������� ������� - �� ����� ������� �� �����.";
			link.l1 = "��...";
			link.l1.go = "rozencraft_3";
		break;
		
		case "rozencraft_3":
			npchar.quest.bakaut = GetSquadronGoods(pchar, GOOD_SANDAL);
			dialog.text = "��������, �� ��� �������������� � ����������. ��� ������� ����, ���� �� �� ��������. ��� ��� �� ���� ����� ����� ����, ��� � ���������� �����. ������� � ���� �������?";
			link.l1 = ""+FindRussianQtyString(sti(npchar.quest.bakaut))+".";
			link.l1.go = "rozencraft_4";
		break;
		
		case "rozencraft_4":
			iTemp = sti(npchar.quest.bakaut);
			if(iTemp >= 90)
			{
				dialog.text = "�������. ��� ���� ������, ��� � ������. ���, ����� ������. ���� ����������� ��� �������� - ������� � ������� ����-�������� � ��������... ��� ��������� � ���. �� ������ ���� �� ����. ����, � ����� ����� ����� ����, � �������, ��� � ���� ���������� ����������.";
				link.l1 = "������. ������, ��� �� ������������.";
				link.l1.go = "rozencraft_5";
				pchar.GenQuest.Bakaut = "true"; // ��������� ����� �������
				break;
			}
			if(iTemp >= 70 && iTemp < 90)
			{
				dialog.text = "������. ���, ����� ������. ���� ����������� ��� �������� - ������� � ������� ����������� � ��������... ��� ��������� � ���. �� ������ ���� �� ����. ����, � ����� ����� ����� ����, � �� ����, ��� � ���� ���������� ����������.";
				link.l1 = "������. ������, ��� �� ������������.";
				link.l1.go = "rozencraft_5";
				pchar.GenQuest.Bakaut = "true"; // ��������� ����� �������
				break;
			}
			if(iTemp >= 40 && iTemp < 70)
			{
				dialog.text = "��... � ����������� �� �������. �����. ���, ����� ������. � ������� ���������, ����� � ��������� ��� ������ ���� �� ������ 100 ����.";
				link.l1 = "������. ����������� �������!";
				link.l1.go = "rozencraft_5";
				break;
			}
			dialog.text = "�� ���, ��������? �� �� �������������� � ����������, ��� ������ ������ ���� �� ������ ���������� ����! ����������, � �� ���������, ���� � ���� � ������ �� ����� ������� ����������.";
			link.l1 = "������-������, �� ��������.";
			link.l1.go = "rozencraft_5";
		break;
		
		case "rozencraft_5":
			DialogExit();
			npchar.DontDeskTalk = true; // ���� �� ��������, � ���������� - �������
			iTemp = sti(npchar.quest.bakaut);
			if (iTemp < 40) DeleteAttribute(npchar, "quest.bakaut");
			else 
			{
				TakeNItems(pchar, "gold_dublon", iTemp*40);
				RemoveCharacterGoods(pchar, GOOD_SANDAL, iTemp);
				// �������, ������� �� ������ ��������
				int ibak = makeint((iTemp*40-1500)/2);
				sld = characterFromId("Svenson");
				sld.quest.bakaut_sum = ibak; // ���� ���
				AddQuestRecord("Testament", "9");
				AddQuestUserData("Testament", "sSum", iTemp*40);
				AddQuestUserData("Testament", "sSum1", ibak);
				if (CheckAttribute(pchar, "GenQuest.Bakaut")) AddQuestUserData("Testament", "sText", "����� ����, ���� � ��� ������ ������ - � ����� ����� ��� ������ ��������� ������� �����������, ������������� ����� ��� �������� � ������� �����������.");
				pchar.questTemp.Saga = "removebakaut";
				// ������� ����������� ���������, � �� �� ���� ����� ������ �������� �� ���������
				pchar.quest.Saga_Rozencraft_GetOut.over = "yes"; //����� ����������
				pchar.quest.Saga_Rozencraft_AfterBattle.over = "yes"; //����� ����������
				// ������ ����� ���������� �� ���������� �����������
				pchar.quest.Bakaut_Rozencraft_Die.win_condition.l1 = "Group_Death";
				pchar.quest.Bakaut_Rozencraft_Die.win_condition.l1.group = "Rozencraft_Group";
				pchar.quest.Bakaut_Rozencraft_Die.function = "Bakaut_RozencraftDie";
				pchar.quest.Bakaut_Rozencraft_Remove.win_condition.l1 = "MapEnter";
				pchar.quest.Bakaut_Rozencraft_Remove.function = "Bakaut_RozencraftRemove";
			}
			NextDiag.CurrentNode = "rozencraft_no_repeat";
		break;
		
	// ------------------------------------��������� ����� �������-----------------------------------------------
		case "bakaut":
			dialog.text = "�, ������ ��������! ������ ������ �� �������?";
			link.l1 = "������ ���, �������. �������� ���������?";
			link.l1.go = "bakaut_0";
		break;
		
		case "bakaut_0":
			dialog.text = "������� � ���� ������? ��� ����� ������ �� ������ "+FindRussianQtyString(sti(pchar.GenQuest.Bakaut.Value))+".";
			if (GetSquadronGoods(pchar, GOOD_SANDAL) >= sti(pchar.GenQuest.Bakaut.Value))
			{
				link.l1 = "� � �����. � ���� � ������ "+FindRussianQtyString(GetSquadronGoods(pchar, GOOD_SANDAL))+" ��� ������� ���� �������.";
				link.l1.go = "bakaut_1";
			}
			else
			{
				link.l1 = "��. ������ ���������� � ����, � ���������, ������ ���.";
				link.l1.go = "bakaut_no";
			}
		break;
		
		case "bakaut_no":
			if (!CheckAttribute(npchar, "quest.bakaut_angry"))
			{
				dialog.text = "���� ������, ���� ���, �� ������������? ��� ����� ������� ���������? ��� ����� "+FindRussianQtyString(sti(pchar.GenQuest.Bakaut.Value))+", � �� �������� ������. ������� � ��������� ��� �������, ������� ���� ������ ��� �����. �������, ������ �� ���� �� �����������, � �� �������� ���������� �� ����� �����.";
				link.l1 = "������, ������, ������ � ���� ����� ����������.";
				link.l1.go = "bakaut_no_1";
			}
			else
			{
				if (sti(npchar.quest.bakaut_angry) == 1)
				{
					dialog.text = "�� ������ ��� ���� ���������. ��� ��� ����� �� ��������. ���� � ����: ��� ��� �� ��������� ������� ������ - ����� � � ����� ��� ����� �� ����.";
					link.l1 = "��������� ����� ��������� �����!.. ������ �������� �� �����, �������, � ������.";
					link.l1.go = "bakaut_no_1";
				}
				else
				{
					dialog.text = "��� ������ ��� �������� ������������� �������! � ����� �� ����� ����� � ����� ������� ���. ������ ��������� �� ��� ������ ������� � ������ ��� ����.";
					link.l1 = "�� ������...";
					link.l1.go = "bakaut_no_2";
				}
			}
			npchar.DontDeskTalk = true;
			pchar.quest.Bakaut_Rozencraft_Find.over = "yes"; //����� ����������
		break;
		
		case "bakaut_no_1":
			DialogExit();
			NextDiag.CurrentNode = "rozencraft_no_repeat";
			if (!CheckAttribute(npchar, "quest.bakaut_angry")) npchar.quest.bakaut_angry = 1;
			else npchar.quest.bakaut_angry = sti(npchar.quest.bakaut_angry)+1;
			pchar.quest.Bakaut_Rozencraft_Reset.win_condition.l1 = "MapEnter";
			pchar.quest.Bakaut_Rozencraft_Reset.function = "Bakaut_RozencraftRemove";
			AddQuestRecord("Bakaut", "3");
			CloseQuestHeader("Bakaut");
		break;
		
		case "bakaut_no_2":
			DialogExit();
			NextDiag.CurrentNode = "rozencraft_no_repeat";
			pchar.quest.Bakaut_Rozencraft_Fail.win_condition.l1 = "MapEnter";
			pchar.quest.Bakaut_Rozencraft_Fail.function = "Bakaut_RozencraftDie";
			AddQuestRecord("Bakaut", "4");
			CloseQuestHeader("Bakaut");
		break;
		
		case "bakaut_1":
			iTemp = GetSquadronGoods(pchar, GOOD_SANDAL);
			if (iTemp > sti(pchar.GenQuest.Bakaut.Value)+20)
			{ // �������
				dialog.text = "���! ��������, �� ������, �������, �� � ���� ������ � ���� ������ "+FindRussianQtyString(sti(pchar.GenQuest.Bakaut.Value)+20)+" ������ - ������ � ���� ������ ��� �����. � ����������� �� ������ � "+FindRussianQtyString(sti(pchar.GenQuest.Bakaut.Value))+", �� ����� ��������...";
				link.l1 = "������. ������� ������ "+FindRussianQtyString(sti(pchar.GenQuest.Bakaut.Value)+20)+", � ��������� ������ � ��������� ���.";
				link.l1.go = "bakaut_2";
				npchar.quest.bakaut = sti(pchar.GenQuest.Bakaut.Value)+20;
			}
			else
			{
				dialog.text = "����� ������. ���� - ��� ������, ����� �������� �� �����.";
				link.l1 = "��� ����������. ������� ���� �����.";
				link.l1.go = "bakaut_2";
				npchar.quest.bakaut = iTemp;
			}
		break;
		
		case "bakaut_2":
			LAi_Fade("", "");
			WaitDate("",0,0,0,1,10);
			dialog.text = "������� ����� � ����� ����. ������ ������� ��� ��� ������� - �� ������, ���� � � ���� ����������.";
			link.l1 = "��� ��������, ������. ���� �������������� �������� ��� �������� ������. �� �������!";
			link.l1.go = "bakaut_3";
		break;
		
		case "bakaut_3":
			DialogExit();
			iTemp = sti(npchar.quest.bakaut);
			TakeNItems(pchar, "gold_dublon", iTemp*40);
			RemoveCharacterGoods(pchar, GOOD_SANDAL, iTemp);
			npchar.DontDeskTalk = true;
			pchar.quest.Bakaut_Rozencraft_Find.over = "yes"; //����� ����������
			pchar.quest.Bakaut_Rozencraft_Reset.win_condition.l1 = "MapEnter";
			pchar.quest.Bakaut_Rozencraft_Reset.function = "Bakaut_RozencraftRemove";
			NextDiag.CurrentNode = "rozencraft_no_repeat";
			AddQuestRecord("Bakaut", "2");
			AddQuestUserData("Bakaut", "sQty", iTemp);
			AddQuestUserData("Bakaut", "sDublon", iTemp*40);
			AddQuestUserData("Bakaut", "sDublon1", iTemp*40-iTemp*30);
			CloseQuestHeader("Bakaut");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}