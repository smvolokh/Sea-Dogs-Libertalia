void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp, iQty;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ��� � ����. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
		break;
		
		//�������� �� ������
		case "MarchCap":
			pchar.quest.MarchCapOver.over = "yes"; //����� ����������
			dialog.text = "��� � ��, �������. ������ ��������� � ���������� ������������ ����� �����������. �� ����� �������, ������ � �� ������� �� ���� �������� � ������ �����.";
			link.l1 = "������� ���, ������, �� ������. � ��� ����������� ������.";
			link.l1.go = "MarchCap_1";
		break;
		
		case "MarchCap_1":
			pchar.GenQuest.MarchCap.Goods = SelectMarchCapGoods1();//������� �����
			switch (rand(2))
			{
				case 0: //������ � �������, ��������� ����������
					pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
					while(pchar.GenQuest.MarchCap.Island == pchar.GenQuest.MarchCap.Startisland)
					{
						pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
					}
					pchar.GenQuest.MarchCap.Island.Shore = GetIslandRandomShoreId(pchar.GenQuest.MarchCap.Island);
					while(pchar.GenQuest.MarchCap.Island.Shore == "")
					{
						pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
						pchar.GenQuest.MarchCap.Island.Shore = GetIslandRandomShoreId(pchar.GenQuest.MarchCap.Island);
						if (!isLocationFreeForQuests(pchar.GenQuest.MarchCap.Island) || !isLocationFreeForQuests(pchar.GenQuest.MarchCap.Island.Shore)) pchar.GenQuest.MarchCap.Island.Shore = "";
					}
					pchar.GenQuest.MarchCap.DaysQty = GetMaxDaysFromIsland2Island(pchar.GenQuest.MarchCap.Startisland, pchar.GenQuest.MarchCap.Island)+3;
					dialog.text = "��� ������� ���������, ��� ����� "+FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty))+" ��������� �������� ������ ��� ������ "+NationNameGenitive(sti(pchar.GenQuest.MarchCap.Nation))+", ��� ���������� ����� � ������� ���������, ����� ��������� � "+XI_ConvertString(pchar.GenQuest.MarchCap.Island.Shore+"Gen")+", ��� � "+XI_ConvertString(pchar.GenQuest.MarchCap.Island+"Gen")+". � ������ ������ ����� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+". ���� �� ����� �� ��������������� ���� �����������, �������\n������ �� ����� ����������� � ��������������, � ���������� ������ �������� ������ �����. �� ���, �� �������� ����������� �� ���� � ���� �����?";
					link.l1 = "������ ���������. �������, � ��������!";
					link.l1.go = "MarchCap_1_1";
					link.l2 = "��-�� ������-�� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+" ������� ��������� � "+NationNameAblative(sti(pchar.GenQuest.MarchCap.Nation))+"? ���, � �� ����� �� ���������! ��������, ������, � ���� �� ��������� ���� �����������!";
					link.l2.go = "MarchCap_exit";
				break;
				
				case 1: //��������� �� ��������, ��������� ����������
					pchar.GenQuest.MarchCap.Startcity = SelectAnyColony(pchar.GenQuest.MarchCap.basecity);
					pchar.GenQuest.MarchCap.Finishcity = SelectAnyColony2(pchar.GenQuest.MarchCap.basecity, pchar.GenQuest.MarchCap.Startcity);
					pchar.GenQuest.MarchCap.DaysQty = 5+drand(5);
					dialog.text = "��� ������� ���������, ��� ����� "+FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty))+" ��������� �������� ������ ��� ������ "+NationNameGenitive(sti(pchar.GenQuest.MarchCap.Nation))+", ��� ���������� ����� � ������� ���������, ������ �� "+XI_ConvertString("Colony"+pchar.GenQuest.MarchCap.Startcity+"Gen")+" � ���������� � "+XI_ConvertString("Colony"+pchar.GenQuest.MarchCap.Finishcity+"Acc")+". � ������ ������ ����� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+". ���� �� ����� �� ��������������� ���� �����������, �������\n������ �� ����� ����������� � ��������������, � ���������� ������ �������� ������ �����. �������� ��������� - �������� �� � ���� ����� ����� ����� ��������... �� ���, �� �������� ����������� �� ���� � ���� �����?";
					link.l1 = "������ ���������. �������, � ��������!";
					link.l1.go = "MarchCap_2_1";
					link.l2 = "��-�� ������-�� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+" ������� ��������� � "+NationNameAblative(sti(pchar.GenQuest.MarchCap.Nation))+"? ���, � �� ����� �� ���������! ��������, ������, � ���� �� ��������� ���� �����������!";
					link.l2.go = "MarchCap_exit";
				break;
				
				case 2: //��������� ��������� ��������� � �����, ��������� ����������
					pchar.GenQuest.MarchCap.Goods = GOOD_GOLD + drand(makeint(GOOD_SILVER - GOOD_GOLD));
					pchar.GenQuest.MarchCap.GoodsQty = sti(pchar.rank)*50+170+rand(30);
					if (sti(pchar.GenQuest.MarchCap.GoodsQty) > 1600) pchar.GenQuest.MarchCap.GoodsQty = 1500+rand(100);
					pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
					while(pchar.GenQuest.MarchCap.Island == pchar.GenQuest.MarchCap.Startisland)
					{
						pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
					}
					pchar.GenQuest.MarchCap.Island.Shore = GetIslandRandomShoreId(pchar.GenQuest.MarchCap.Island);
					while(pchar.GenQuest.MarchCap.Island.Shore == "")
					{
						pchar.GenQuest.MarchCap.Island = GetRandomIslandId();
						pchar.GenQuest.MarchCap.Island.Shore = GetIslandRandomShoreId(pchar.GenQuest.MarchCap.Island);
						if (!isLocationFreeForQuests(pchar.GenQuest.MarchCap.Island) || !isLocationFreeForQuests(pchar.GenQuest.MarchCap.Island.Shore)) pchar.GenQuest.MarchCap.Island.Shore = "";
					}
					pchar.GenQuest.MarchCap.DaysQty = GetMaxDaysFromIsland2Island(pchar.GenQuest.MarchCap.Startisland, pchar.GenQuest.MarchCap.Island)+1;
					pchar.GenQuest.MarchCap.PirateName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);//�����
					pchar.GenQuest.MarchCap.ShipType = SelectPirateShipType();
					pchar.GenQuest.MarchCap.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.MarchCap.ShipType));
					dialog.text = "� ������� ����������� �������� �� ����� ������ �� ������ "+GetName( NAMETYPE_ORIG, pchar.GenQuest.MarchCap.PirateName, NAME_NOM)+". ��� ���, ���� ��������� ������� ���������� ������� "+RandPhraseSimple(RandPhraseSimple("��������","���������"), RandPhraseSimple("��������","����������"))+" � �������� ���� ������ ���� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+". �� ��� ���� ��������: � ��� ��� "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.MarchCap.ShipType), "Name")+"Acc"))+" ��� ������ ���������, ��� �� �� ���� ���� ������ ��� �������� ������ �� ������\n������ �� ��������� � "+XI_ConvertString(pchar.GenQuest.MarchCap.Island.Shore+"Gen")+", ��� � "+XI_ConvertString(pchar.GenQuest.MarchCap.Island+"Gen")+", ������������� ����� ����� � ������ �������� � �������. �� ���� ��������, � ���� �� ��� ����� �� ������, ��� "+FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty))+". ���� ����������� - �� ������ ������ � ���� �� ��������, � ����� ���� ���� "+GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods))+" ������ �����\n���������� � �������� � ���� ������� ��� �� ��� ���� - �� ������ ������� � ������� �������� ���, �� ������ �� ������ ����������� � ���, �������� �� ���� ��� ����. �� ���, �� �������� ����������� �� ���� � ���� �����?";
					link.l1 = "������ ���������. �������, � ��������!";
					link.l1.go = "MarchCap_3_1";
					link.l2 = "��. ������� ���, ��� ��� ������ �� ������ ��� � ��������, �� � ��� ������ �� �� �����. ���, � �� ����� �� ���������. ��������, ������, � ���� �� ��������� ���� �����������!";
					link.l2.go = "MarchCap_exit";
				break;
			}
		break;
		
		case "MarchCap_1_1":
			dialog.text = "� ����, ��� �� ��� ����� ������������! ����� �� ����� ������ �� ������. ������������� �� ��� ������� � ����������� �������. ������� � ����!";
			link.l1 = "������������ ��������� �����, �������! �� ������������ ����������.";
			link.l1.go = "MarchCap_1_2";
		break;
		
		case "MarchCap_1_2":
			DialogExit();
			NextDiag.CurrentNode = "MarchCap_repeat";
			Group_DelCharacter("MarchGroup", "MarchCap");
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.nation = pchar.nation;
			Ship_FlagRefresh(npchar); //���� �� ����
			npchar.loyality = MAX_LOYALITY;
			SetCharacterRemovable(npchar, false);
			pchar.quest.MarchCap1_1.win_condition.l1 = "Timer";
			pchar.quest.MarchCap1_1.win_condition.l1.date.hour  = sti(GetTime()+rand(10));
			pchar.quest.MarchCap1_1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.win_condition.l2 = "location";
			pchar.quest.MarchCap1_1.win_condition.l2.location = pchar.GenQuest.MarchCap.Island;
			pchar.quest.MarchCap1_1.function = "MarchCap1_CreateConvoy";
			SetFunctionTimerCondition("MarchCap_Attack_Over", 0, 0, sti(pchar.GenQuest.MarchCap.DaysQty)+2, false); //������ �� ����������
			pchar.quest.MarchCap1_fail.win_condition.l1 = "NPC_Death";
			pchar.quest.MarchCap1_fail.win_condition.l1.character = "MarchCap";
			pchar.quest.MarchCap1_fail.function = "MarchCap_fail";
			ReOpenQuestHeader("MarchCap");
			AddQuestRecord("MarchCap", "1");
			AddQuestUserData("MarchCap", "sShore", XI_ConvertString(pchar.GenQuest.MarchCap.Island.Shore+"Gen"));
			AddQuestUserData("MarchCap", "sIsland", XI_ConvertString(pchar.GenQuest.MarchCap.Island+"Gen"));
			AddQuestUserData("MarchCap", "sDays", FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty)));
			AddQuestUserData("MarchCap", "sGoods", GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods)));
			AddQuestUserData("MarchCap", "sName", GetFullName(npchar));
		break;
		
		case "MarchCap_TimeOver":
			dialog.text = "� ����� � ������ � ���� ��������, �� ����������, �, �������? ��-�� ��� �� �������� ����� ������� ������! ����� �� � ����� ����...";
			link.l1 = "��-�� ����? �� �� �� ���� � ���� ������� ����������! ��� �� ������� ��� ������ ����? �������, ��� ���� �� ������? � ������ � �����, ��� ����, ���� �� �����������! ��������!";
			link.l1.go = "MarchCap_Talk_exit";
			pchar.GenQuest.MarchCap = "late";
		break;
		
		case "MarchCap_Talk_exit":
			pchar.quest.MarchCap1_fail2.over = "yes"; //����� ����������
			pchar.quest.MarchCap1_fail1.over = "yes"; //����� ����������
			pchar.quest.MarchCap1_fail.over = "yes"; //����� ����������
			DialogExit();
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			DeleteAttribute(npchar, "AlwaysFriend");
			npchar.DontDeskTalk = true;
			if (CheckAttribute(pchar, "GenQuest.MarchCap.Deck"))
			{
				PChar.quest.Munity = "Deads";
				LAi_LocationFightDisable(&Locations[FindLocation("Ship_deck")], false);
			}
			else
			{
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
				chrDisableReloadToLocation = false;
			}
			RemoveCharacterCompanion(pchar, npchar);
			if (pchar.GenQuest.MarchCap == "late") AddQuestRecord("MarchCap", "2");
			if (pchar.GenQuest.MarchCap == "bad") AddQuestRecord("MarchCap", "5");
			if (pchar.GenQuest.MarchCap == "poor" || pchar.GenQuest.MarchCap == "good" || pchar.GenQuest.MarchCap == "exellent")
			{
				iQty = makeint(GetSquadronGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods))-sti(pchar.GenQuest.MarchCap.StartGoodsQty));
				iTemp = iQty-sti(pchar.GenQuest.MarchCap.CapPart);
				RemoveCharacterGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods), iQty);
				AddCharacterGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods), iTemp);
				if (pchar.GenQuest.MarchCap == "poor") AddQuestRecord("MarchCap", "6");
				if (pchar.GenQuest.MarchCap == "good") AddQuestRecord("MarchCap", "7");
				if (pchar.GenQuest.MarchCap == "exellent") AddQuestRecord("MarchCap", "8");
			}
			AddQuestUserData("MarchCap", "sName", GetFullName(npchar));
			CloseQuestHeader("MarchCap");
			DeleteAttribute(pchar, "GenQuest.MarchCap");
		break;
		
		case "MarchCap_AfterBattle":
			iTemp = makeint(GetSquadronGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods))-sti(pchar.GenQuest.MarchCap.StartGoodsQty))*sti(Goods[sti(pchar.GenQuest.MarchCap.Goods)].Weight);
			iQty = makeint(GetSquadronGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods))-sti(pchar.GenQuest.MarchCap.StartGoodsQty));
			pchar.GenQuest.MarchCap.CapPart = iQty/sti(pchar.GenQuest.MarchCap.Parts);
			if (iTemp < 50)
			{
				dialog.text = "����� �� �� �������, �������! �� ������ �� ���������, ������, ��-��-��!! � ��� ��-�� ���! ��� �� �� ���� ��������, ������� ��� ����!";
				link.l1 = "��-�� ����? �� �� ���� ����������! �� ����� ��� �� ������� � ���, �����! � ������ ��� �������� �����, ���������� � ����... ���������� � ����� �������!";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "bad";
				break;
			}
			if (iTemp > 50 && iTemp < 500)
			{
				dialog.text = "�� ��, ��������� ����� ����. ��������� �����-�� ������ �����... �����, ���, ����� ��, ��� ����, � ���������� � ������ �������.";
				link.l1 = "���� �� �� ��� ��������, ��� �������, � �� �������� � ���� �������, ���� ��� �� �������... ��������� ���� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+", � ������������!";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "poor";
				break;
			}
			if (iTemp > 500 && iTemp < 1500)
			{
				dialog.text = "������� ���������, �������! ��� � ��� � ������� - �� ��� ����� ��������� ����� ���� ��������, ��-��... ������, ��� � ����, ��������� "+FindRussianQtyString(iQty)+" ������. ��� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+".";
				link.l1 = "�� ��� ����� ����������, "+npchar.name+". � ���� ��� ����������. ������ ��� ��������. ��������, ��� �����-������ ���������� � ����...";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "good";
				break;
			}
			dialog.text = "�������� ������, �������! ��� � ��� � ������� - �� ��� ����� ��������� ����� ���� ��������, ��-��... ������ ��������� ��� ��� �������� �, ��� � ����, ��������� "+FindRussianQtyString(iQty)+" ������. ��� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+".";
			link.l1 = "�� ��� ����� ����������, "+npchar.name+". � ���� ��� ����������. ������ ��� ��������. �����, ��� ���-������ ������ � ���������� ����, �? �� ��� �������� ������ ���������� �����������.";
			link.l1.go = "MarchCap_Deck_continue";
			pchar.GenQuest.MarchCap = "exellent";
		break;
		
		//���� ����� ����� - ����� ������� ��� ������ ����� � ���������� �� ��� ����������� ������
		case "MarchCap_Deck_continue":
			dialog.text = "��� ��������, �������. ���� ����������� �������� ������, � ������� � �� ����� ���������� ��� - � ���������� ����� ���. �� ��� ���� �������� �������� ������ ���������.";
			link.l1 = "��� � ������! ��, � ������ - ��������, �������. �����!";
			link.l1.go = "MarchCap_Talk_exit";
		break;
		
		case "MarchCap_2_1":
			dialog.text = "� ����, ��� �� ��� ����� ������������! ����� �� ����� ������ �� ������. ������������� �� ��� ������� � ����������� �������. ������� � ���� � ������� � ���!";
			link.l1 = "������������ ��������� �����, �������! �� ������������ ����������.";
			link.l1.go = "MarchCap_2_2";
		break;
		
		case "MarchCap_2_2":
			DialogExit();
			NextDiag.CurrentNode = "MarchCap_repeat";
			Group_DelCharacter("MarchGroup", "MarchCap");
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.loyality = MAX_LOYALITY;
			SetCharacterRemovable(npchar, false);
			pchar.quest.MarchCap1_1.win_condition.l1 = "Timer";
			pchar.quest.MarchCap1_1.win_condition.l1.date.hour  = sti(GetTime()+rand(10));
			pchar.quest.MarchCap1_1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.MarchCap.DaysQty));
			pchar.quest.MarchCap1_1.function = "MarchCap2_CreateConvoy";
			pchar.GenQuest.MarchCap.WdmEnc = "true";
			pchar.quest.MarchCap1_fail.win_condition.l1 = "NPC_Death";
			pchar.quest.MarchCap1_fail.win_condition.l1.character = "MarchCap";
			pchar.quest.MarchCap1_fail.function = "MarchCap_fail";
			ReOpenQuestHeader("MarchCap");
			AddQuestRecord("MarchCap", "10");
			AddQuestUserData("MarchCap", "sCity1", XI_ConvertString("Colony"+pchar.GenQuest.MarchCap.Startcity+"Gen"));
			AddQuestUserData("MarchCap", "sCity2", XI_ConvertString("Colony"+pchar.GenQuest.MarchCap.Finishcity+"Acc"));
			AddQuestUserData("MarchCap", "sDays", FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty)));
			AddQuestUserData("MarchCap", "sGoods", GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods)));
			AddQuestUserData("MarchCap", "sName", GetFullName(npchar));
		break;
		
		case "MarchCap_3_1":
			dialog.text = "� ����, ��� �� ��� ����� ������������! ����� �� ����� ������ �� ������ - � ��� ���� ������� �������, ����� ������. ������������� �� ��� ������� � ����������� �������. ������� � ����!";
			link.l1 = "������������ ��������� �����, �������! �� ������������ ����������.";
			link.l1.go = "MarchCap_3_2";
		break;
		
		case "MarchCap_3_2":
			DialogExit();
			NextDiag.CurrentNode = "MarchCap_repeat";
			Group_DelCharacter("MarchGroup", "MarchCap");
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.loyality = MAX_LOYALITY;
			SetCharacterRemovable(npchar, false);
			pchar.quest.MarchCap1_1.win_condition.l1 = "location";
			pchar.quest.MarchCap1_1.win_condition.l1.location = pchar.GenQuest.MarchCap.Island;
			pchar.quest.MarchCap1_1.function = "MarchCap3_CreatePirate";
			SetFunctionTimerCondition("MarchCap_Attack_Over", 0, 0, sti(pchar.GenQuest.MarchCap.DaysQty), false); //������
			pchar.quest.MarchCap1_fail.win_condition.l1 = "NPC_Death";
			pchar.quest.MarchCap1_fail.win_condition.l1.character = "MarchCap";
			pchar.quest.MarchCap1_fail.function = "MarchCap_fail";
			pchar.GenQuest.MarchCap.Pirate = "true";
			ReOpenQuestHeader("MarchCap");
			AddQuestRecord("MarchCap", "11");
			AddQuestUserData("MarchCap", "sShore", XI_ConvertString(pchar.GenQuest.MarchCap.Island.Shore+"Gen"));
			AddQuestUserData("MarchCap", "sIsland", XI_ConvertString(pchar.GenQuest.MarchCap.Island+"Gen"));
			AddQuestUserData("MarchCap", "sDays", FindRussianDaysString(sti(pchar.GenQuest.MarchCap.DaysQty)));
			AddQuestUserData("MarchCap", "sGoods", GetGoodsNameAlt(sti(pchar.GenQuest.MarchCap.Goods)));
			AddQuestUserData("MarchCap", "sName", GetFullName(npchar));
			AddQuestUserData("MarchCap", "sName1", GetName(NAMETYPE_ORIG, pchar.GenQuest.MarchCap.PirateName, NAME_NOM));
		break;
		
		case "MarchCap_DieHard":
			dialog.text = "�� ��������, ���� �� ��� ������! �� �������� ������� � ���� ���!";
			link.l1 = "� ���, ��-������, � ������ ��� ���� ����� ������ �������� ��� �����? ��� ��, ����� ���� ����� ������, ��� ������� �������!";
			link.l1.go = "MarchCap_DieHard_1";
		break;
		
		case "MarchCap_DieHard_1":
			dialog.text = "� ����� � ������ �������� � ����? ���� ���� �������� ����-������ �������, � ���� �� ������ ������� ��� ���� ���������� ������!";
			link.l1 = "����� ������ ������� � ������ �����, ������! �� ���� ���� �� �������, � �� ��� ����������� �������������������! ��� ������� ��������, ��������� ��� �����! � ������ ������� ��� �������� ��� ������� - � ����������� �� ������.";
			link.l1.go = "MarchCap_Talk_exit";
		break;
		
		case "MarchCap_AfterBattleGold":
			iTemp = makeint(GetSquadronGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods))-sti(pchar.GenQuest.MarchCap.StartGoodsQty))*sti(Goods[sti(pchar.GenQuest.MarchCap.Goods)].Weight);
			iQty = makeint(GetSquadronGoods(pchar, sti(pchar.GenQuest.MarchCap.Goods))-sti(pchar.GenQuest.MarchCap.StartGoodsQty));
			pchar.GenQuest.MarchCap.CapPart = iQty/sti(pchar.GenQuest.MarchCap.Parts);
			if (iTemp < 10)
			{
				dialog.text = "����� �� �� �������, �������! �� ������ �� ���������, ������, ��-��-��!! � ��� ��-�� ���! ��� �� �� ���� ��������, ������� ��� ����!";
				link.l1 = "��-�� ����? �� �� ���� ����������! �� ����� ��� �� ������� � ���, �����! � ������ ��� �������� �����, ���������� � ����... ���������� � ����� �������!";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "bad";
				break;
			}
			if (iTemp > 10 && iTemp < 100)
			{
				dialog.text = "�� ��, ��������� ����� ����. ��������� �����-�� ������ �����... �����, ���, ����� ��, ��� ����, � ���������� � ������ �������.";
				link.l1 = "���� �� �� ��� ��������, ��� �������, � �� �������� � ���� �������, ���� ��� �� �������... ��������� ���� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+", � ������������!";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "poor";
				break;
			}
			if (iTemp > 100 && iTemp < 500)
			{
				dialog.text = "������� ���������, �������! ��� � ��� � ������� - ������ �� ��������� � ���� �������! ������, ��� � ����, ��������� "+FindRussianQtyString(iQty)+" ������. ��� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+".";
				link.l1 = "�� ��� ����� ����������, "+npchar.name+". � ���� ��� ����������. ������ ��� ��������. ��������, ��� �����-������ ���������� � ����...";
				link.l1.go = "MarchCap_Talk_exit";
				pchar.GenQuest.MarchCap = "good";
				break;
			}
			dialog.text = "�������� ������, �������! ��� � ��� � ������� - ������ �� ��������� � ���� �������! ������ ��������� ��� ��� �������� �, ��� � ����, ��������� "+FindRussianQtyString(iQty)+" ������. ��� ���� - "+FindRussianQtyString(sti(pchar.GenQuest.MarchCap.CapPart))+".";
			link.l1 = "�� ��� ����� ����������, "+npchar.name+". � ���� ��� ����������. ������ ��� ��������. �����, ��� ���-������ ������ � ���������� ����, �? �� ��� �������� ������ ���������� �����������.";
			link.l1.go = "MarchCap_Deck_continue";
			pchar.GenQuest.MarchCap = "exellent";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "MarchCap_repeat":
			dialog.text = ""+GetAddress_Form(NPChar)+", �������� �� ���� �������. � ��� ���������� ��� ������� �� ���������. � ����!";
			link.l1 = "��-��, �������, �� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "MarchCap_repeat";
		break;
		
		case "MarchCap_exit":
			dialog.text = "��... �� � �� ���������. ������������ �� ���� ������! � ��� ��� ���������!";
			link.l1 = "��-��, ����������� ����...";
			link.l1.go = "MarchCap_DeckExit";
		break;
		
		case "MarchCap_DeckExit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
			DeleteAttribute(npchar, "AlwaysFriend");
			npchar.DontDeskTalk = true;
			DeleteAttribute(pchar, "GenQuest.MarchCap");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

int SelectMarchCapGoods1()
{
	int iGoods;
	switch (drand(17))
	{
		case 0: iGoods = GOOD_EBONY; break;
		case 1: iGoods = GOOD_MAHOGANY; break;
		case 2: iGoods = GOOD_CINNAMON; break;
		case 3: iGoods = GOOD_COFFEE; break;
		case 4: iGoods = GOOD_CHOCOLATE; break;
		case 5: iGoods = GOOD_TOBACCO; break;
		case 6: iGoods = GOOD_COTTON; break;
		case 7: iGoods = GOOD_COPRA; break;
		case 8: iGoods = GOOD_TEA; break;
		case 9: iGoods = GOOD_SALT; break;
		case 10: iGoods = GOOD_PAPRIKA; break;
		case 11: iGoods = GOOD_IRON; break;
		case 12: iGoods = GOOD_COPPER; break;
		case 13: iGoods = GOOD_IVORY; break;
		case 14: iGoods = GOOD_DYES; break;
		case 15: iGoods = GOOD_SILK; break;
		case 16: iGoods = GOOD_GOLD; break;
		case 17: iGoods = GOOD_SILVER; break;
	}
	return iGoods;
}

int SelectPirateShipType()
{
	int iShip;
	
	if(sti(pchar.rank) >= 19) iShip = SHIP_LINESHIP;	
	if(sti(pchar.rank) >= 13 && sti(pchar.rank) < 18) iShip = SHIP_HEAVYGALEON;	
	if(sti(pchar.rank) >= 8 && sti(pchar.rank) < 12) iShip = SHIP_CORVETTE;
	if(sti(pchar.rank) >= 5 && sti(pchar.rank) < 8) iShip = SHIP_SCHOONER_W;	
	if(sti(pchar.rank) < 5) iShip = SHIP_LUGGER + drand(makeint(SHIP_BRIG - SHIP_LUGGER));
	
	return iShip;
}