// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	bool bOk;
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("���������, ���� �� ������?",
                          "�� ������ ��� ��������� ��� ����. ��, ��������, ������������...", "������� �� ��� ������ ��� �������� � �����-�� �������...",
                          "��������, ��� �������, ����� ���� �������� ���-��. �� �������� ����!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, " + NPChar.name + ", ���-������ � ��������� ���.", "�����, "+ GetSexPhrase("�����","������") +" ���-��...",
                      "�� ��, ������������� � ������ ���...", "��, �� ����...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "��������, "+npchar.name+", �� �� ����� � ��������� ����� �� ���� ������ ������ ������?";
				link.l1.go = "tieyasal";
			}

			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "���������, � ��� ���� ��������� �������, ���� '������ ��������'. ������ � ��� �� �������? �� ����� ���������� � ��� � "+ GetSexPhrase("�����","������") +" ���������...";
				link.l1.go = "BlueBird_1";
			}
			bOk = pchar.questTemp.Headhunter == "end_quest_full" || pchar.questTemp.BlueBird == "weWon" || pchar.questTemp.BlueBird == "returnMoney" || pchar.questTemp.BlueBird == "over"; 
			if (bOk && !CheckAttribute(pchar,"questTemp.BlueBird.speakWon"))
			{
				link.l1 = "������� � ���� ���� �������, ���� '������ ��������' �� ���� �������� �� �����, ��� ���� ����� �������?";
				link.l1.go = "BlueBird_3";
			}

			// Addon 2016-1 Jason ��������� �������
			if(CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "pasq_start")
			{
				link.l1 = ""+npchar.name+", � ������ �� ������� �������. �� ������, ��� ��� ����� ������� ��� ������.";
				link.l1.go = "mtraxx";
			}
			if(CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "pasq_win")
			{
				link.l1 = ""+npchar.name+", '�������' ������ � ��������. ��������� � �������� ������ � �������?";
				link.l1.go = "mtraxx_5";
			}

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toBermudes" && !CheckAttribute(npchar, "quest.RevengeCorsair_toBermudes"))
			{
				link.l1 = "��������� ������� �� ������� �� ���� ���������� ������ ����������� � ������?";
				link.l1.go = "RevengeCorsair_Store";
			}

		break;
				
		// ����� ����
		case "tieyasal":
			dialog.text = "�����. �� ������� ������� �� ���� ������� � ����. ������, ������ �������. �� ��������� �� ��������� ���� �����������. ������, ���� �����, �� ��� ���-�� � �������. �, ������ ��, �� ������ �� ������. ����������� ���, ������� - �������� ���� ���.";
			link.l1 = "�������. ������� �� ��������!";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			DialogExit();
			npchar.quest.tieyasal = "true";
		break;

		case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("� ������ �� ���� �� ���� �������. ���� ��� ���, ��� �� ������, �� �������.", 
				"�����? � ��� ��� ������.", 
				"���, ����� ��� �� ��?",
                "�� ����� �� ��� ��������?! ����� ���, �� ���������� ���� �� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("���-�� �� ����� �� �������, ��������!", 
				"��-��, � �����...",
                "���.", 
				"������, ������...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
		break;
		case "BlueBird_2":
			dialog.text = "� ��� �� ��������, ��� �������� � ��� ������� � ���� �������� �� ���� ������������.";
			link.l1 = "� ���! �� � ������ "+ GetSexPhrase("�������","��������") +". �� �����, ������� � �� ����...";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "2");
			AddQuestUserData("Xebeca_BlueBird", "sSex", GetSexPhrase("��","���"));
		break;

		case "BlueBird_3":
				dialog.text = "����� �����, ����� ���, � ��� � ����� ����������!";
				link.l1 = "�� �����, �� ��� �� ��������� � �������� ��������� ������, � �� ��� ����� ������� ���������� �� ���� ������� ��������.";
				link.l1.go = "exit_BlueBird";
		break;

		case "exit_BlueBird":
			DialogExit();
			pchar.questTemp.BlueBird.speakWon = true;
		break;

		// Addon 2016-1 Jason ��������� �������
		case "mtraxx":
			pchar.quest.Mtraxx_PasqualeLate.over = "yes";
            dialog.text = "������ ���! ����� ������, �� ������� �������. ������ ������� ���� ����...";
			link.l1 = "����������� ��� ������.";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
			string sTemp = GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.questTemp.Mtraxx.Crdn.Ship), "Name")));
            dialog.text = "� ������ ������ � ����� ����� ������������ ����������� ������� �� ����������� - "+sTemp+" ��� ��������� '�������' � ������, ������ ������� ������, � ������������� ������ ������� ���������. ����� ��������� �� ���� - ����� ����-������� ��� ����� ��������� - ��� ��������, �� � ����� ���� ���� � ���������� �����, ��� ���� ������� ���������� � ������� ����������� ��������, � ��� ��� ������� ������ �������� �� �����, � ������\n���� ������ - ����� ���������� � ��������� ���� �����, ������ '�������', ��������� ���� ��� ���� � ��������� ���. � ���� ������������ ����� �� ����� �������� ������.";
			link.l1 = "������ ����. ����� � ����?";
			link.l1.go = "mtraxx_2";
		break;
		
		case "mtraxx_2":
			int i = sti(pchar.questTemp.Mtraxx.Crdn.minN2)-10;
			int n = sti(pchar.questTemp.Mtraxx.Crdn.minW2)-10;
            dialog.text = "������� ���������� ��������� � ��������� �����: "+sti(pchar.questTemp.Mtraxx.Crdn.degN)+" �������� "+i+" ����� �������� ������, "+sti(pchar.questTemp.Mtraxx.Crdn.degW)+" �������� "+n+" ����� �������� �������. ��� ���-�� �� �� ��� ���-����� �� ����-������, � � ���� ����� ���������, �� ����� - �����������. ���� - ����� 5 ����, �� ������ �����������.";
			link.l1 = "������ ��� �������... �������. ��, ����� �� ����� ������ �������!";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "�����, �������. ��� ��� � �������.";
			link.l1 = "...";
			link.l1.go = "mtraxx_4";
		break;
		
		case "mtraxx_4":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_convoy";
		   i = sti(pchar.questTemp.Mtraxx.Crdn.minN2)-10;
           n = sti(pchar.questTemp.Mtraxx.Crdn.minW2)-10;
		   AddQuestRecord("Roger_4", "3");
		   AddQuestUserData("Roger_4", "sShip", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.questTemp.Mtraxx.Crdn.Ship), "Name")+ "Gen")));
		   AddQuestUserData("Roger_4", "sdegN", sti(pchar.questTemp.Mtraxx.Crdn.degN));
		   AddQuestUserData("Roger_4", "sminN", i);
		   AddQuestUserData("Roger_4", "sdegW", sti(pchar.questTemp.Mtraxx.Crdn.degW));
		   AddQuestUserData("Roger_4", "sminW", n);
		   SetFunctionTimerCondition("Mtraxx_PasqualeTimeConvoy", 0, 0, 6, false);
		   SetFunctionTimerCondition("Mtraxx_PasqualeConvoyOver", 0, 0, 7, false);
		break;
		
		case "mtraxx_5":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_EBONY);
			if (iTotalTemp < 1)
			{
				dialog.text = "�� �����������, ������� �������? � ����� ������ ��� �� ������ �������� ������� ������! �� ���� ����� ������! ��� ��� ����� �� ������� - � ��������� ������� �������! ���������� ���!!";
				link.l1 = "��...";
				link.l1.go = "mtraxx_6";
				break;
			}
			if (iTotalTemp < makeint(sti(pchar.questTemp.Mtraxx.Crdn.Ebony)/4))
			{
				dialog.text = "�� �����������, ������� �������? � ����� ������ ������ ����� �� ���� ���������� ������� ������, ��� ���� �� '�������'! �� ���� ����� ������! ��� ��� ����� �� ������� - � ��������� ������� �������! ���������� ���!!";
				link.l1 = "��...";
				link.l1.go = "mtraxx_6";
				break;
			}
			if (iTotalTemp < sti(pchar.questTemp.Mtraxx.Crdn.Ebony)-20)
			{
				dialog.text = "�� '�������' ������ ���� ���� �� ������ "+FindRussianQtyString(sti(pchar.questTemp.Mtraxx.Crdn.Ebony))+" ������� ������. ������ �� �������� ������?";
				link.l1 = "��� ��� - ����� ����� �������� ������� � ���. � ��� ����� �������, ���������...";
				link.l1.go = "mtraxx_7";
				break;
			}
            dialog.text = "����� ������. ������� � ��� ������? "+FindRussianQtyString(iTotalTemp)+"? �������! � ������� ��� �� 150 ���� �� ������� ������.";
			link.l1 = "�� 150 ����? �� ��� �������, ��� ��� ������ ����� ������� ������...";
			link.l1.go = "mtraxx_10";
		break;
		
		case "mtraxx_6":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_angry";
		   DoQuestReloadToLocation("Pirates_town", "reload", "reload6", "");
		   AddQuestRecord("Roger_4", "8");
		   CloseQuestHeader("Roger_4");
		   QuestSetCurrentNode("Terrax", "mtraxx_34");
		break;
		
		case "mtraxx_7":
            dialog.text = "�����? ��-��... �������, �����. � ������� ��� �� 100 ���� �� ������� ������ � ������ ���� ��������.";
			link.l1 = "����� �� 100 ����? �� ��� �� ������!";
			link.l1.go = "mtraxx_8";
		break;
		
		case "mtraxx_8":
			AddMoneyToCharacter(pchar, iTotalTemp*100);
			RemoveCharacterGoods(pchar, GOOD_EBONY, iTotalTemp);
            dialog.text = "������ - ��� �� ����� �����, �������, � � ������ ��������. ������ ���� ������ � ��������� ��� ����� - �� � ��� �������� �� ���, ���� ���-�� ����� ����� ������...";
			link.l1 = "�� � ���� � ����!";
			link.l1.go = "mtraxx_9";
		break;
		
		case "mtraxx_9":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_fail";
		   AddQuestRecord("Roger_4", "8");
		   CloseQuestHeader("Roger_4");
		   QuestSetCurrentNode("Terrax", "mtraxx_34");
		break;
		
		case "mtraxx_10":
            dialog.text = "��� ��������� �������, �������, �� ��-������, ���������� ������� ������ ������������ ����� - � ��������, ������� ��� �� ���� ��������. ����, ������������ ���, ����� ������. ��-������, ��� ���� ������� �� �� ������� �� ����� ���� �������, � ���, ����� ������, ���� ��������� ���-�� ���, ��, �������� - � �� ������ �� ��� ����� ������. �-�������, � ������� ��� ����� �������� ��������, � ��� - �������� - �������� �����. �� � �-���������, ������ �� ������ �������� �� ���-�� ����.";
			link.l1 = "��! ��� ������ ����� ���������� � ��������, "+npchar.name+". ��������� � �������.";
			link.l1.go = "mtraxx_11";
		break;
		
		case "mtraxx_11":
			AddMoneyToCharacter(pchar, iTotalTemp*150);
			RemoveCharacterGoods(pchar, GOOD_EBONY, iTotalTemp);
            dialog.text = "��� � ������. �������� ���� ������. ���� ������� � ���� ��������. ������������, �� ���������. ����� � ����!";
			link.l1 = "� ��� ������� � ��������...";
			link.l1.go = "mtraxx_12";
		break;
		
		case "mtraxx_12":
           DialogExit();
		   pchar.questTemp.Mtraxx = "pasq_complete";
		   AddQuestRecord("Roger_4", "9");
		   pchar.quest.mtr_pasq_fin.win_condition.l1 = "location";
		   pchar.quest.mtr_pasq_fin.win_condition.l1.location = "Pirates_town";
		   pchar.quest.mtr_pasq_fin.function = "Mtraxx_PasqualeJeffry";
		   bDisableFastReload = true;
		break;

		//********************* ����� ������� *********************

   		case "RevengeCorsair_Store":
		dialog.text = "������, ��������� ������, �, ��, �� ��������� �� ������.";
		link.l1 = "��...������ ��������, � ����, ��� ���� � ���� ����� ������������, ��������� � �����.";
		link.l1.go = "RevengeCorsair_Store_1";
		break;

 		case "RevengeCorsair_Store_1":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_GOLD);
			if (iTotalTemp < 500)
			{
					dialog.text = "������ ��������... �������, ����� ���� �� ����� ������� ������ ���!";
					link.l1 = "׸��, ��� ���-��!";
					link.l1.go = "sale_gold_fail";
					break;
					}
					dialog.text = "���� �����, ������� ����� ������?";
					link.l1 = "����� ������� ��, �� ����� �������� �� ����!";
					link.l1.go = "sale_gold_all";		
					break;

   		case "sale_gold_all":
		dialog.text = "���������!";
		link.l1 = "�...";
		link.l1.go = "sale_gold_all_1";
		break;

	 	case "sale_gold_all_1":
            if (GetCargoMaxSpace(pchar) >= RecalculateCargoLoad(pchar))
            {
		dialog.text = "���� ������ ������ - " + pchar.Ship.Cargo.Goods.gold + " ��������. ������ �� 1000 ���� �� ������� ����, ��� �������!";
           }     
		link.l1 = "������������, ������� ���������, �������. ��� ��������. ��, ������ ������� � ����� ���� �� ���� ������, ��� ���� �� ������...";
		link.l1.go = "RevengeCorsair_Store_2";
		break;		

   		case "RevengeCorsair_Store_2":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "�����, �����, �������� ������, �� ���� ������ ����� �� ������ - ������� ��� ��������!";
		link.l1 = "��, ������� ��� ������. ������ � �����, ����� �� ���� ���� - ������� �������!";
		link.l1.go = "RevengeCorsair_Store_3";
   		RemoveCharacterGoods(Pchar, GOOD_GOLD, sti(pchar.questTemp.CumanaGoldQty));
		AddMoneyToCharacter(pchar, makeint(sti(pchar.questTemp.CumanaGoldQty)*1000));
		break;

   		case "RevengeCorsair_Store_3":
		dialog.text = "������� ��� ����, ������ ���� ��������� �� ���������� �����!";
		link.l1 = "��� ������, ���� �� �����������.";
		link.l1.go = "exit";
                                         DeleteAttribute(pchar, "questTemp.CumanaGoldQty");
		npchar.quest.RevengeCorsair_toBermudes = "true";
	                     AddDialogExitQuestFunction("Gothic_RevengeCorsair_19");
		break;

		case "sale_gold_fail":
		DialogExit();
		AddQuestRecord("RevengeCorsair", "18_1");
		CloseQuestHeader("RevengeCorsair");				                                            npchar.quest.RevengeCorsair_toBermudes = "true";
	                     AddDialogExitQuestFunction("Gothic_RevengeCorsair_18_1");
		break;			


	}
	UnloadSegment(NPChar.FileDialog2);
}