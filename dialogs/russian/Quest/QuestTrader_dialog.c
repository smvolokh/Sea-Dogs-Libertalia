void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
		bool ok = CheckFreeSitFront(npchar);
			if(drand(11) > 8 && ok && !CheckAttribute(pchar, "GenQuest.Racing.Go") && !CheckAttribute(npchar, "quest.race") && sti(Pchar.Ship.Type) != SHIP_NOTUSED && 6-sti(RealShips[sti(pchar.ship.type)].Class) > 0)//����� �� �����������
			{
				dialog.text = TimeGreeting() + ", "+GetAddress_Form(NPChar) + "! ���� ����� "+ GetFullName(NPChar) + ", � �������. ����, ��� �� ���� ������� �������. �������������� �� ���, ��������� �� ����������?";
				link.l1 = "������ �� � ���? �������, ������, ���������.";
				link.l1.go = "Race_prepare";
				link.l2 = "�������, �� � ���� ��� �������. � ������ ���.";
				link.l2.go = "exit";
				npchar.quest.race = "true";
			}
			else
			{
			//������ ��������� �����
				if(!CheckAttribute(pchar, "GenQuest.Escort.Trader") && !CheckAttribute(npchar, "quest.race") && sti(Pchar.Ship.Type) != SHIP_NOTUSED && !CheckAttribute(npchar, "repeat_work") && 6-sti(RealShips[sti(pchar.ship.type)].Class) > 0 && GetCompanionQuantity(pchar) < 6)
				{
					dialog.text = TimeGreeting() + ", "+GetAddress_Form(NPChar) + "! � "+ GetFullName(NPChar) + ", ��������. ����, �� ������� �������. �� ������� ������������� ���� ����� ����?";
					link.l1 = "���������� ������ �����. ������ ���� ������ �� ��� ������ ����������?";
					link.l1.go = "Escort_choice";
					link.l2 = "� ����� �� ��� ������ ��� ����� ���������� ������, �? �������� ��� ������� �������? � �� �������� ����� �������.";
					link.l2.go = "exit_distress";
					SaveCurrentNpcQuestDateParam(npchar, "repeat_work");
				}
				else
				{
					dialog.text = TimeGreeting() + ", "+GetAddress_Form(NPChar) + "! ��� ���� ����? �� ���-�� ������?";
					link.l1 = TimeGreeting() + ", " + GetAddress_FormToNPC(NPChar) + ". �� ���, ������ �� ����� - ������ ������������. ������ ��� ���������!";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "exit_distress":
			DialogExit();
			NextDiag.CurrentNode = "Trader_distress";
		break;
		
		case "Trader_distress":
			dialog.text = "�������, �� ���� ��� ��� �������� - �� ��� ��? �� �� ������ ��� � '��������' - ��� ���� �� �� �� ���� ������?";
			link.l1 = "��, ��������. �����, ����, ��� ���� ���. ��� ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Trader_distress";
		break;
		
		case "Escort_choice"://������ �������� - �������� ����� �������, ������ � �����������
			pchar.GenQuest.Escort.Trader.StartCity = GetCurrentTown();//��������� �����
			pchar.GenQuest.Escort.Trader.ShipType = TraderShipType();//��� ������� ��������
			pchar.GenQuest.Escort.Trader.Nation = npchar.nation;//����� ��������
			switch (drand(2))
			{
				case 0://����� �������������
					pchar.GenQuest.Escort.Trader.City = FindFriendCityToMC(false);//������� �����
					pchar.GenQuest.Escort.Trader.DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.Escort.Trader.StartCity), GetArealByCityName(pchar.GenQuest.Escort.Trader.City))+5;//���
					pchar.GenQuest.Escort.Trader.Money = makeint(sti(pchar.GenQuest.Escort.Trader.DaysQty)*400*ShipFactorMC()+sti(pchar.GenQuest.Escort.Trader.ShipType)*700);//������ �� ���������� � ������� �������� �� � ������
					pchar.GenQuest.Escort.Trader.Type1 = "true";//��� �������
					pchar.GenQuest.Escort.Trader.Chance = rand(1);
					pchar.GenQuest.Escort.Trader.Add = "�� "+XI_ConvertString("Colony"+pchar.GenQuest.Escort.Trader.City+"Gen")+"";
					dialog.text = "� ����� �� ��� ��������� ����������� ���� �� "+XI_ConvertString("Colony"+pchar.GenQuest.Escort.Trader.City+"Gen")+" �� "+FindRussianDaysString(sti(pchar.GenQuest.Escort.Trader.DaysQty))+". �� ��� � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money))+".";
					link.l1 = "�� ��� ��, ������ �� � ���? ������ ������ ����������, ��� �������. � ��������.";
					link.l1.go = "EscortType";
					link.l2 = "� �� � ��� ������, �� ��� ������ � ������ �������.";
					link.l2.go = "Escort_exit";
				break;
				case 1://�����
					GetEscortTraderShore();//������� �����
					while(pchar.GenQuest.Escort.Trader.City == "Terks" || pchar.GenQuest.Escort.Trader.City == "caiman" || pchar.GenQuest.Escort.Trader.City == "dominica")
					{
						GetEscortTraderShore();
					} // patch-6
					pchar.GenQuest.Escort.Trader.DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.Escort.Trader.StartCity), pchar.GenQuest.Escort.Trader.Island)+5;//���
					pchar.GenQuest.Escort.Trader.Money = makeint(sti(pchar.GenQuest.Escort.Trader.DaysQty)*400*ShipFactorMC()+sti(pchar.GenQuest.Escort.Trader.ShipType)*700);//������
					pchar.GenQuest.Escort.Trader.Type2 = "true";//��� �������
					pchar.GenQuest.Escort.Trader.Chance = rand(2);
					pchar.GenQuest.Escort.Trader.Add = "�� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Shore+"Gen")+", ��� �������� �� "+XI_ConvertString("Colony"+pchar.GenQuest.Escort.Trader.City+"Gen")+"";
					dialog.text = "� ����� �� ��� ��������� ����������� ���� �� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Shore+"Gen")+", ��� �������� �� "+XI_ConvertString("Colony"+pchar.GenQuest.Escort.Trader.City+"Gen")+", �� "+FindRussianDaysString(sti(pchar.GenQuest.Escort.Trader.DaysQty))+". �� ��� � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money))+".";
					link.l1 = "�� ��� ��, ������ �� � ���? � ��������.";
					link.l1.go = "EscortType";
					link.l2 = "� �� � ��� ������, �� ��� ������ � ������ �������.";
					link.l2.go = "Escort_exit";
				break;
				case 2://����������
					pchar.GenQuest.Escort.Trader.Island = DesIsland();//������� ������
					pchar.GenQuest.Escort.Trader.Shore = SelectQuestShoreLocationFromSea(pchar.GenQuest.Escort.Trader.Island);//� ����� �� ���
					pchar.GenQuest.Escort.Trader.DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.Escort.Trader.StartCity), pchar.GenQuest.Escort.Trader.Island)+5;//���
					pchar.GenQuest.Escort.Trader.Money = makeint(sti(pchar.GenQuest.Escort.Trader.DaysQty)*400*ShipFactorMC()+sti(pchar.GenQuest.Escort.Trader.ShipType)*700);//������
					pchar.GenQuest.Escort.Trader.Type3 = "true";//��� �������
					pchar.GenQuest.Escort.Trader.Chance = rand(2);
					pchar.GenQuest.Escort.Trader.Add = "�� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Shore+"Gen")+", ��� �� ����������� ������� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Island)+"";
					dialog.text = "� ����� �� ��� ��������� ����������� ���� �� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Shore+"Gen")+", ��� �� ������� "+XI_ConvertString(pchar.GenQuest.Escort.Trader.Island)+", �� "+FindRussianDaysString(sti(pchar.GenQuest.Escort.Trader.DaysQty))+". �� ��� � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money))+".";
					link.l1 = "�� ��� ��, ������ �� � ���? � ��������. ���� ������� �� ������ ��� �������� ��� �������� ����� �� ����������� ��������.";
					link.l1.go = "EscortType";
					link.l2 = "� �� � ��� ������, �� ��� ������ � ������ �������.";
					link.l2.go = "Escort_exit";
				break;
			}
		break;
		
		case "Escort_exit":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Escort.Trader");
		break;
		
		case "Trader_wait":
			dialog.text = "�� ������ � ������ � ����, �������? � ��� ����� ��������.";
			link.l1 = "��, �� ��� ������������. ���������� � �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Trader_wait";
		break;
		
		case "EscortType":
			dialog.text = "������������! � ���, ��� �� ������������. �������, ����������� ������� ��� ���������� �����������.";
			link.l1 = "� ���� �� ��� �������. ������������ � ����!";
			link.l1.go = "EscortType_go";
			NextDiag.CurrentNode = "Trader_wait";
		break;
		
		case "EscortType_go":
			//����� ���������
			DialogExit();
			pchar.GenQuest.Escort.Trader.id = npchar.id;
			pchar.GenQuest.Escort.Trader.model = npchar.model;
			npchar.lifeday = sti(pchar.GenQuest.Escort.Trader.DaysQty)+1; // 170712
			DeleteAttribute(npchar, "CityType");
			CreateTraderShipAndAdd();//������������ ��������
			pchar.GenQuest.Escort.Trader.ShipMaxHP = sti(npchar.ship.HP);
			ReOpenQuestHeader("TraderEscort");
			AddQuestRecord("TraderEscort", "1");
			AddQuestUserData("TraderEscort", "sDay", FindRussianDaysString(sti(pchar.GenQuest.Escort.Trader.DaysQty)));
			AddQuestUserData("TraderEscort", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money)));
			AddQuestUserData("TraderEscort", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Escort.Trader.StartCity+"Gen"));
			AddQuestUserData("TraderEscort", "sAdd", pchar.GenQuest.Escort.Trader.Add);
			pchar.GenQuest.Escort.Trader = "begin";
			//��������� ���������
			if (CheckAttribute(pchar, "GenQuest.Escort.Trader.Type1"))//� ������������� �����
			{
				pchar.GenQuest.Escort.Trader.Location = pchar.GenQuest.Escort.Trader.City+"_tavern";
			if (sti(pchar.GenQuest.Escort.Trader.Chance) == 1) CoolTraderHunterOnMap();
				else TraderHunterOnMap();//������ �� �� ��������
			}
			if (CheckAttribute(pchar, "GenQuest.Escort.Trader.Type2"))//� �����
			{
				pchar.GenQuest.Escort.Trader.Location = pchar.GenQuest.Escort.Trader.Shore;
				if (sti(pchar.GenQuest.Escort.Trader.Chance) != 2) TraderHunterOnMap();
				else
				{
					pchar.quest.EscortTrader_Attack.win_condition.l1 = "location";
					pchar.quest.EscortTrader_Attack.win_condition.l1.location = pchar.GenQuest.Escort.Trader.Island;
					pchar.quest.EscortTrader_Attack.function = "EscortTraderAttackInShore";
				}
			}
			if (CheckAttribute(pchar, "GenQuest.Escort.Trader.Type3"))//�� ����������
			{
				pchar.GenQuest.Escort.Trader.Location = pchar.GenQuest.Escort.Trader.Shore;
				if (sti(pchar.GenQuest.Escort.Trader.Chance) == 0) TraderHunterOnMap();
				if (sti(pchar.GenQuest.Escort.Trader.Chance) == 1) 
				{
					if(sti(RealShips[sti(pchar.Ship.Type)].BaseType) <= sti(pchar.GenQuest.Escort.Trader.ShipType) && sti(RealShips[sti(pchar.Ship.Type)].BaseType) != SHIP_HEAVYGALEON && GetCompanionQuantity(pchar) < 6)//�������� ���������
					{//������� ���
						pchar.quest.EscortTrader_Attack.win_condition.l1 = "location";
						pchar.quest.EscortTrader_Attack.win_condition.l1.location = pchar.GenQuest.Escort.Trader.Island;
						pchar.quest.EscortTrader_Attack.function = "DesIslandAttack";
					}
					else CoolTraderHunterOnMap();
				}
				else
				{//����� ������ + ��� �������
					pchar.quest.EscortTrader_Attack.win_condition.l1 = "location";
					pchar.quest.EscortTrader_Attack.win_condition.l1.location = pchar.GenQuest.Escort.Trader.Island;
					pchar.quest.EscortTrader_Attack.function = "DesIslandAttack";
				}
			}
			pchar.quest.EscortTrader_Complete.win_condition.l1 = "location";
			pchar.quest.EscortTrader_Complete.win_condition.l1.location = pchar.GenQuest.Escort.Trader.Location;
			pchar.quest.EscortTrader_Complete.function = "EscortTraderComplete";
			SetFunctionTimerCondition("EscortTrader_Over", 0, 0, sti(pchar.GenQuest.Escort.Trader.DaysQty), false);
			pchar.quest.EscortTrader_fail.win_condition.l1 = "NPC_Death";//���������� �� ���������� ���������������
			pchar.quest.EscortTrader_fail.win_condition.l1.character = pchar.GenQuest.Escort.Trader.id;
			pchar.quest.EscortTrader_fail.function = "EscortTrader_failed";
		break;
		
		case "EscortTrader_complete"://����� �����
			sld = characterFromId(pchar.GenQuest.Escort.Trader.id);
			if (sti(sld.ship.HP) < makeint(sti(pchar.GenQuest.Escort.Trader.ShipMaxHP)/4))//���� ������� �������� ������ 1/4 - ������ ��������
			{
				dialog.text = "�������, �� �� ����������, ����� � ����� ���? �� ������ ���������� �� ��� �������! �� ��� �� �����? �� ������! �� ��� �� ����� ��������! �� ��� ������? � ��� � �� �����, ��� ���� ����������� - �� ����, ��� � ���. � �����, ������� �� �� ��������, � �� ���������. �� �� �� ���������.";
				link.l1 = "�-���... ���� �� �� � - �� �� ������ ������ ������ ������, ����� ������. �����, ����� ������� - ���������� �� ��� ��� � ����!";
				link.l1.go = "EscortTrader_complete_1";
				break;
			}
			if (sti(sld.ship.HP) < makeint(sti(pchar.GenQuest.Escort.Trader.ShipMaxHP)/2))//���� ������� �������� ������ 1/2 - ������ ��������
			{
				pchar.GenQuest.Escort.Trader.Money = makeint(sti(pchar.GenQuest.Escort.Trader.Money))/2;
				dialog.text = "�������, �� �� ����������, ����� � ����� ���? �� ������ ���������� �� ��� �������! �� ��� �� �����? �� ������! �� ��� ������? � �����, � ������� ��� ������ �������� ������������� �����. � �� ������� �� �������������!";
				link.l1 = "�-���.. �����, � ��������. ��� ������� � ������... ������� ���������.";
				link.l1.go = "EscortTrader_complete_2";
				break;
			}
			if (CheckAttribute(pchar, "GenQuest.Escort.Trader.Type2") && sti(pchar.GenQuest.Escort.Trader.Chance) == 1)//������ ����� - �������
			{
				dialog.text = "�������, ��� ����� ����... � ���� ��� �����, ����� ��������� ��� �� ������. �� �� ����������, ����������, � ���� ��� ���������� ������, ������� ����������� ���������� ��������� ����.";
				link.l1 = "��... � ������-�� ����������� �������� ������ ������. ��, ��� ��� - � ���� ����� ���������.";
				link.l1.go = "EscortTrader_complete_4";
				break;
			}
			dialog.text = "������� ��� �������, �������. ������ � ���� � ���������� ���� ��� ������� ��������, �������� �� ��������� ���������. ���, �������� ���� ��������������.";
			link.l1 = "����������... ���� ��� - ����������� �����!";
			link.l1.go = "EscortTrader_complete_3";
		break;
		
		case "EscortTrader_complete_1":
			dialog.text = "�� ��������� ���� ��������! � ����� ������� ����� ������� �������� ��� ������ �������� ������. ��������!";
			link.l1 = "����������, ������...";
			link.l1.go = "complete_exit";
			AddQuestRecord("TraderEscort", "4");
			AddComplexSeaExpToScill(20, 20, 20, 0, 20, 0, 0);
			AddCharacterExpToSkill(pchar, "Fortune", 20);//�������
		break;
		
		case "EscortTrader_complete_2":
			dialog.text = "��, �� ����� ����� ��������� - '������� ���������'... ���, ������� "+FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money))+" � ��������.";
			link.l1 = "����� �������, " + npchar.name + ".";
			link.l1.go = "complete_exit";
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Escort.Trader.Money));
			AddQuestRecord("TraderEscort", "5");
			AddQuestUserData("TraderEscort", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money)));
			AddComplexSeaExpToScill(50, 50, 50, 0, 50, 0, 50);
			AddCharacterExpToSkill(pchar, "Fortune", 40);//�������
		break;
		
		case "EscortTrader_complete_3":
			dialog.text = "����������! ��, � ������ ��� ���� ����. �� ��������, �������!";
			link.l1 = "�����, " + npchar.name + "!";
			link.l1.go = "complete_exit";
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Escort.Trader.Money));
			AddQuestRecord("TraderEscort", "6");
			AddQuestUserData("TraderEscort", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Escort.Trader.Money)));
			AddComplexSeaExpToScill(100, 100, 100, 50, 100, 100, 150);
			AddCharacterExpToSkill(pchar, "Leadership", 80);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 80);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
		break;
		
		case "EscortTrader_complete_4":
			pchar.GenQuest.Escort.Trader.Enemyname = GenerateRandomName_Generator(sti(npchar.nation), "man");
			GetEnemyTraderGoods();
			pchar.GenQuest.Escort.Trader.EnIsland = DesIsland();
			dialog.text = "�� ���������� ���� ���� �������� - "+ pchar.GenQuest.Escort.Trader.Enemyname +". � ���� ����������� �����, �� ������� �� ��������� ������. � ���������� ����� ����, ��� �������� ����� ��� ������ �� ����� ���������� � ������� ������������ ������� "+ XI_ConvertString(pchar.GenQuest.Escort.Trader.EnIsland) +" - ��������� ������ ���� � ��������� � �������� ���������, � � ������ ��� ������ ����� ����� "+pchar.GenQuest.Escort.Trader.add+". ����� �� ����������, ��������� ��� ������� ��� ����� �� ��������\n��� ��� �� ��� ��������� � ��������, �������.";
			link.l1 = "�-��... Homo homini lupus est, ���, ���������?";
			link.l1.go = "EscortTrader_complete_5";
		break;
		
		case "EscortTrader_complete_5":
			dialog.text = "���-��� �� ������ �������? � �� �����...";
			link.l1 = "� ������ - ������� �������� - ����, ��? �� ��� ����� � ������������� '������' ������ �������... �������, ��� �� ����� ������� ���� ���, � �� ������� �������. ��������� ����������, ������!";
			link.l1.go = "EscortTrader_complete_6";
		break;
		
		case "EscortTrader_complete_6":
			DialogExit();
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			pchar.quest.EscortTrader_fail.over = "yes";
			pchar.quest.EscortTrader_Over.over = "yes";//����� ��� ����������
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			RemoveCharacterCompanion(Pchar, npchar);
			AddQuestRecord("TraderEscort", "7");
			AddQuestUserData("TraderEscort", "sIsland", XI_ConvertString(pchar.GenQuest.Escort.Trader.EnIsland));
			AddQuestUserData("TraderEscort", "sAdd", pchar.GenQuest.Escort.Trader.add);
			pchar.quest.EscortTrader_EnTrader.win_condition.l1 = "Timer";
			pchar.quest.EscortTrader_EnTrader.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.EscortTrader_EnTrader.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 12);
			pchar.quest.EscortTrader_EnTrader.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 12);
			pchar.quest.EscortTrader_EnTrader.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 12);
			pchar.quest.EscortTrader_EnTrader.win_condition.l2 = "location";
			pchar.quest.EscortTrader_EnTrader.win_condition.l2.location = pchar.GenQuest.Escort.Trader.EnIsland;
			pchar.quest.EscortTrader_EnTrader.function = "Create_EnemyTraderFleut";
			SetFunctionTimerCondition("EscortTraderEnemy_Over", 0, 0, 16, false); // ������
			AddComplexSeaExpToScill(100, 100, 100, 50, 100, 100, 150);
			AddCharacterExpToSkill(pchar, "Leadership", 80);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 80);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
		break;
		
		case "complete_exit":
			DialogExit();
			CloseQuestHeader("TraderEscort");
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			pchar.quest.EscortTrader_fail.over = "yes";
			pchar.quest.EscortTrader_Over.over = "yes";//����� ��� ����������
			pchar.quest.EscortTrader_Attack.over = "yes"; // patch-8
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			RemoveCharacterCompanion(Pchar, npchar);
			DeleteAttribute(pchar, "GenQuest.Escort.Trader");
		break;
		
		case "Race_prepare":
			NextDiag.TempNode = "Race_begin";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.friend_in_tavern = npchar.id;
			AddDialogExitQuest("alc");
		break;
		
		case "exit_sit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
		
		case "Race_begin"://����� �� �����������
			dialog.text = "��, ����� ������ �� ������ ������� ����, �������! ��� ����� ����, ��� ��������?";
			link.l1 = "�� � �� ������ ��, ��� � - ��������. �� � ����� ������ ���� ���� �������.";
			link.l1.go = "Race_begin_1";
		break;
		
		case "Race_begin_1":
			dialog.text = "� ��� �������! � ������ ����, ��� ���������� ����� � ����.";
			link.l1 = "��, ��� �����. �������� �������� ���, ������ - ��� ������� ��������� �� ���������� ����� ������. � �� �� ���� �� ��� �� ������, �� ���������� ������ - ������� ���� ���������� � ������ ����� ����� �������� ����� - ��� �� �������� ��������. ������ � ������� ���, ��� ���������� �� ������-���� ����� ������.";
			link.l1.go = "Race_begin_2";
		break;
		
		case "Race_begin_2":
			dialog.text = "��, �� ��� �����, �������. ��� �, ��������, ������ � �������� ���� - ��� ������ ������� �� �����. � ������� ���� ���� ���������� ����, �, ������� ���� ��������, ������� ���������� �� ����� �������� � ��������. ��� ��� � �������� ���� � ���� �� ������ ������.";
			link.l1 = "�� ��? ����� ��������, �� ������� � ������. � ������ ������ ������? �� �������� �������? �� ������ �������, ��� ������� ���� �� ��������� ���������� ��� �������?";
			link.l1.go = "Race_begin_3";
		break;
		
		case "Race_begin_3":
			dialog.text = "������, �������, �� ������������ � ���, ��� ��� ������� ����� ������ ������? ������. ��������� ���� ����.";
			link.l1 = "����� ����?";
			link.l1.go = "Race_begin_4";
		break;
		
		case "Race_begin_4"://��� ������������� ��� ���������
			if (!CheckAttribute(pchar, "GenQuest.Racing")) pchar.GenQuest.Racing.Count = 0;
			pchar.GenQuest.Racing.Go.Nation = npchar.nation;
			pchar.GenQuest.Racing.Go.StartCity = GetCurrentTown();
			pchar.GenQuest.Racing.Go.City = FindFriendCityToMC(false);//������� ������������� �����
			pchar.GenQuest.Racing.Go.Island = GetIslandByCityName(pchar.GenQuest.Racing.Go.City);
			pchar.GenQuest.Racing.Go.DaysQty = makeint((GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.Racing.Go.StartCity), GetArealByCityName(pchar.GenQuest.Racing.Go.City)))/1.3);//���
			pchar.GenQuest.Racing.Go.ShipName = GenerateRandomNameToShip(sti(npchar.nation));
			if (sti(pchar.GenQuest.Racing.Go.DaysQty) < 1) pchar.GenQuest.Racing.Go.DaysQty = 1; // patch-8
			dialog.text = "� ��� �����. � ������� ����������� ����� � ���� � ����������� � "+XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.City)+". � �������, ��� ���� ��� ����� "+FindRussianDaysString(pchar.GenQuest.Racing.Go.DaysQty)+". �������� �������� ���� � ������� � "+XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.City)+" ������. ������ ������� ������ ����� ������. ��������? ��� �� ��������, ��-��?";
			link.l1 = "���? � �� ������? �� �����. �� ������������� ��������� � ��� �����? �������. � �������� ���� ����. � ����� ������ �� ����� ����������?";
			link.l1.go = "Race_begin_5";
			link.l2 = "������ � ���� ������ ��� ���, ��� ���������� ����� ��-�� ������-�� ������� ����.";
			link.l2.go = "Race_exit";
		break;
		
		case "Race_exit":
			dialog.text = "��... ���������� ���������? �������, � �����. �� �� ������� - �� ���������� �� ����������������� �������� - ����� ��������� ����� ����� ������� �������... ������� ������� ���.";
			link.l1 = "�����-�����, ������ ��� ��� ������ ������, ������� �������. ������...";
			link.l1.go = "exit_sit";
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
			NextDiag.TempNode = "First time";
		break;
		
		case "Race_begin_5":
			dialog.text = "�����������, �������.";
			iTemp = 1;
			for (i=5; i>=1; i--)
			{
					sTemp = "l"+iTemp;
					link.(sTemp) = ""+FindRussianMoneyString(sti(10000*i))+"";
					link.(sTemp).go = "Racing_rate"+i;
					iTemp++;
			}
		break;
		
		case "Racing_rate5"://50 000
			if (drand(9) > 6)
			{
			dialog.text = "�������. � ��������. ������ �� �����, �������. ��� ��� ������.";
			link.l1 = "������, ������ ������ �������...";
			link.l1.go = "Racing_rate";
			pchar.GenQuest.Racing.Go.Money = 50000;
			}
			else
			{
			dialog.text = "��� �� ���������� �����������, �������? �� ����� ������ ����� ������ ����� � ��� ����� ���� �� ��������. �������� �������� �����.";
			link.l1 = "��� ���� ��� ����� � ���� �������� - �� ������� � �� ������� ��� � ����� ���������. �� ���� �� � ����������, ������, ����� ������� �� ��� ����. �����... �������� - � ������. ������� ������� - ��� ������... �������� ������ ������.";
			link.l1.go = "Race_exit";
			link.l2 = "��� ���? ��, �����. ����� ��������...";
			link.l2.go = "Race_begin_5";
			}
		break;
		
		case "Racing_rate4"://40 000
			if (drand(9) > 4)
			{
			dialog.text = "�������. � ��������. ������ �� �����, �������. ��� ��� ������.";
			link.l1 = "������, ������ ������ �������...";
			link.l1.go = "Racing_rate";
			pchar.GenQuest.Racing.Go.Money = 40000;
			}
			else
			{
			dialog.text = "��� �� ���������� �����������, �������? �� ����� ������ ����� ������ ���� � ��� ����� ���� �� ��������. �������� �������� �����.";
			link.l1 = "��� ���� ��� ����� � ���� �������� - �� ������� � �� ������� ��� � ����� ���������. �� ���� �� � ����������, ������, ����� ������� �� ��� ����. �����... �������� - � ������. ������� ������� - ��� ������... �������� ������ ������.";
			link.l1.go = "Race_exit";
			link.l2 = "��� ���? ��, �����. ����� ��������...";
			link.l2.go = "Race_begin_5";
			}
		break;
		
		case "Racing_rate3"://30 000
			if (drand(9) > 2)
			{
			dialog.text = "�������. � ��������. ������ �� �����, �������. ��� ��� ������.";
			link.l1 = "������, ������ ������ �������...";
			link.l1.go = "Racing_rate";
			pchar.GenQuest.Racing.Go.Money = 30000;
			}
			else
			{
			dialog.text = "��� �� ���������� �����������, �������? �� ����� ������ ����� ������ ���� � ��� ����� ���� �� ��������. �������� �������� �����.";
			link.l1 = "��� ���� ��� ����� � ���� �������� - �� ������� � �� ������� ��� � ����� ���������. �� ���� �� � ����������, ������, ����� ������� �� ��� ����. �����... �������� - � ������. ������� ������� - ��� ������... �������� ������ ������.";
			link.l1.go = "Race_exit";
			link.l2 = "��� ���? ��, �����. ����� ��������...";
			link.l2.go = "Race_begin_5";
			}
		break;
		
		case "Racing_rate2"://20 000
			if (drand(9) > 0)
			{
			dialog.text = "�������. � ��������. ������ �� �����, �������. ��� ��� ������.";
			link.l1 = "������, ������ ������ �������...";
			link.l1.go = "Racing_rate";
			pchar.GenQuest.Racing.Go.Money = 20000;
			}
			else
			{
			dialog.text = "��� �� ���������� �����������, �������? �� ����� ������ ����� ������ ������ � ��� ����� ���� �� ��������. �������� �������� �����.";
			link.l1 = "��� ���� ��� ����� � ���� �������� - �� ������� � �� ������� ��� � ����� ���������. �� ���� �� � ����������, ������, ����� ������� �� ��� ����. �����... �������� - � ������. ������� ������� - ��� ������... �������� ������ ������.";
			link.l1.go = "Race_exit";
			link.l2 = "��� ���? ��, �����. ����� ��������...";
			link.l2.go = "Race_begin_5";
			}
		break;
		
		case "Racing_rate1"://10 000
			dialog.text = "�������. � ��������. ������ �� �����, �������. ��� ��� ������.";
			link.l1 = "������, ������ ������ �������...";
			link.l1.go = "Racing_rate";
			pchar.GenQuest.Racing.Go.Money = 10000;
		break;
		
		case "Racing_rate":
			dialog.text = "��, �?..";
			if (sti(pchar.money) >= sti(pchar.GenQuest.Racing.Go.Money))
			{
			link.l1 = "���! ��� ������!";
			link.l1.go = "Racing_Go";
			}
			else
			{
			link.l1 = "��... �������, � ���� ��� ����� �����.";
			link.l1.go = "Racing_rate_nomoney";
			}
		break;
		
		case "Racing_rate_nomoney":
			if (sti(pchar.GenQuest.Racing.Go.Money) == 10000 || sti(pchar.Money) < 10000)
			{
			dialog.text = "��, ������, �� �� � ����������, ����� ������� �� ��� ����. ��� �� ������ �������? �, �����, ���� � ����. �� �� ������� - �� ���������� �� ����������������� �������� - ����� ��������� ����� ����� ������� �������... ������� ������� ���.";
			link.l1 = "�����-�����, ������ ��� ��� ������ ������, ������� �������. ������...";
			link.l1.go = "exit_sit";
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
			NextDiag.TempNode = "First time";
			}
			else
			{
			dialog.text = "�����, �����, ����������, ������� � ��� ����, � �������� ������ ������?";
			link.l1 = "������, ������ �������� ���������, ������� � ���� ����� �������...";
			link.l1.go = "Race_begin_5";
			link.l2 = "���, �������, �� ���� � � ����� �������. ���������.";
			link.l2.go = "Racing_exit";
			}
		break;
		
		case "Racing_exit":
			dialog.text = "����������? ��... � �����, �� ������ �������? �������, �����, ���� � ����. �� �� ������� - �� ���������� �� ����������������� �������� - ����� ��������� ����� ����� ������� �������... ������� ������� ���.";
			link.l1 = "�����-�����, ������ ��� ��� ������ ������, ������� �������. ������...";
			link.l1.go = "exit_sit";
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
			NextDiag.TempNode = "First time";
		break;
		
		case "Racing_Go":
			AddMoneyToCharacter(pchar, -sti(pchar.GenQuest.Racing.Go.Money));
			dialog.text = "�������! �������� � ��������� �������, ���� �� �� ������... ��� �� � ������� ���� ������. ���������� �������� � ������� ��� �����. �������� �� ������ - ������� �� ���������� ���������� ����� ������, ��� ��� ���������� ����� � �����, ��� �� ��� �������.";
			link.l1 = "��������. ��� ����� ������.";
			link.l1.go = "Racing_Go_1";
		break;
		
		case "Racing_Go_1":
			dialog.text = "��, � ������, �����, ��� ������� ����������� �� ���� ������� - ������ ������� ��� �����. �� ����, ��� ��, � � ������ � ����. ��, ���� ���: ��� ������� - �����, ���������� - "+pchar.GenQuest.Racing.Go.ShipName+". �����, �� ����� ��� ������� � ����� ��������, ��-��...";
			link.l1 = "�� ������� ������ �������. �� ������� � ������� "+XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.City+"Gen")+"!";
			link.l1.go = "Racing_Go_2";
		break;
		
		case "Racing_Go_2":
			DialogExit();
			npchar.lifeday = 0;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			ChangeCharacterAddressGroup(npchar, pchar.GenQuest.Racing.Go.StartCity + "_tavern", "goto", LAi_FindNearestFreeLocator("goto", locx, locy, locz));
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "exit_sit", -1);
			//�������� ��������� ������ ����� ���� :(
			sTemp = npchar.model;
			int iNation = sti(npchar.Nation);
			sld = GetCharacter(NPC_GenerateCharacter("RaceTrader", sTemp, "man", "man", sti(PChar.rank)+5, iNation, -1, true, "quest"));
			sld.name = npchar.name;
			sld.lastname = npchar.lastname;
			sld.Dialog.Filename = "Quest\QuestTrader_dialog.c";
			pchar.quest.Racing_Timer.win_condition.l1 = "Timer";
			pchar.quest.Racing_Timer.win_condition.l1.date.hour  = sti(GetTime()+rand(6));
			pchar.quest.Racing_Timer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.Racing.Go.DaysQty));
			pchar.quest.Racing_Timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.Racing.Go.DaysQty));
			pchar.quest.Racing_Timer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.Racing.Go.DaysQty));
			pchar.quest.Racing_Timer.function = "TraderRaceInTargetCity";
			pchar.quest.Racing_Finish.win_condition.l1 = "location";
			pchar.quest.Racing_Finish.win_condition.l1.location = pchar.GenQuest.Racing.Go.City + "_town";
			pchar.quest.Racing_Finish.function = "MCRaceInTargetCity";
			SetFunctionTimerCondition("RacingTimeOver", 0, 0, sti(pchar.GenQuest.Racing.Go.DaysQty)+10, false);
			ReOpenQuestHeader("Racing");
			AddQuestRecord("Racing", "1");
			AddQuestUserData("Racing", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.StartCity+"Gen"));
			AddQuestUserData("Racing", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.City+"Gen"));
			AddQuestUserData("Racing", "sDay", FindRussianDaysString(pchar.GenQuest.Racing.Go.DaysQty));
			AddQuestUserData("Racing", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Racing.Go.Money)));
		break;
		
		case "Racing_Finished":
			if (CheckAttribute(pchar, "GenQuest.Racing.Go.MCWin"))
			{
			dialog.text = "���! ������, � �������... ��� ������������, �������! �� � ������ ��������� �������. ��� ���������, �� ������ ���� �������� ������� ����, ���?";
			link.l1 = "������ ���, ������. �� ���� ��� �������, ��� ��� ���� ��������� ����� �� �� �������� ������ � ����� - ������� ��������� ��������, ���������� �� ������ �� ����� �������� ����� ������� ��� ����������.";
			link.l1.go = "Racing_Finished_1";
			}
			else
			{
			dialog.text = "�� ���, �������, ��������? ��� � ��� ��� ������� - � ��������� ���� ���� � ���������� ������� ���������� � ��������. ���������?";
			link.l1 = "����! ������ ����������! �� ������, �� ����� �����, �� ����� ����������... ����������, �������!";
			link.l1.go = "Racing_Finished_2";
			}
			//bDisableFastReload = false;
			//LocatorReloadEnterDisable(pchar.GenQuest.Racing.Go.City + "_town", "reload1_back", false);
			//LocatorReloadEnterDisable(pchar.GenQuest.Racing.Go.City + "_town", "reload2_back", false);
			//LocatorReloadEnterDisable(pchar.GenQuest.Racing.Go.City + "_town", "gate_back", false);
		break;
		
		case "Racing_Finished_1":
			dialog.text = "��� ��, �� ��������. ������ ��� ����� ��������� � ��������� "+XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.StartCity)+" � ������� � ������� ���� ������. �� �� ������������� ���������!";
			link.l1 = "������ ��� � � ��������� �������. � ������ ��������� �����������. ��� �������� ��� ������ ����������. �� ��������!";
			link.l1.go = "Racing_end";
			pchar.GenQuest.Racing.Count = sti(pchar.GenQuest.Racing.Count)+1;
			//��������� ������
			if (!CheckAttribute(pchar, "questTemp.RegataGo") && sti(pchar.GenQuest.Racing.Count) == 3)
			{
				pchar.questTemp.RegataGo = "true";
				pchar.questTemp.Regata.CureerCity = FindFriendCityToMC(true);//�����, � ������� �������� ��������
				if (pchar.questTemp.Regata.CureerCity == "PortRoyal") pchar.questTemp.Regata.CureerCity = "SentJons";
				pchar.quest.Regata_Cureer.win_condition.l1 = "location";
				pchar.quest.Regata_Cureer.win_condition.l1.location = pchar.questTemp.Regata.CureerCity+"_town";
				pchar.quest.Regata_Cureer.function = "PrepareToRegata";
				log_testinfo(pchar.questTemp.Regata.CureerCity);
			}
			pchar.GenQuest.Racing.Go.Advantage = "true";
			npchar.lifeday = 0;
			AddCharacterExpToSkill(pchar, "Sailing", 200);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
			AddCharacterExpToSkill(pchar, "Leadership", 100);//�������
			ChangeCharacterComplexReputation(pchar,"authority", 3);
			ChangeOfficersLoyality("good_all", 3);
		break;
		
		case "Racing_Finished_2":
			dialog.text = "� �� ����� ���� ������� ������� ��� - ������ ������ � ����. � ������ ��� ����� ���������� � �������� ���� � "+XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.StartCity)+", �� ����� ���������.";
			link.l1 = "�� ��� ���������. � ������ ��������� �����������. ��� �������� ��� ������ ����������. �� ��������!";
			link.l1.go = "Racing_end";
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddCharacterExpToSkill(pchar, "Leadership", 20);//�������
			ChangeCharacterComplexReputation(pchar,"authority", 1);
			AddQuestRecord("Racing", "5");
			CloseQuestHeader("Racing");
		break;
		
		case "Racing_end":
			DialogExit();
			NextDiag.currentNode = "Racing_end_repeat";
			pchar.quest.Racing_fail.over = "yes";
			Group_DeleteGroup("RacingTrader");
			sld = characterFromId("RaceTraderSkiper");
			sld.lifeday = 0;
		break;
		
		case "Racing_end_repeat":
			dialog.text = "���-�� ���, �������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Racing_end_repeat";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

float ShipFactorMC()//����������� �� ������ ������� ��
{
	float f;
	int iInvert = 6-sti(RealShips[sti(pchar.Ship.Type)].Class);
	switch (iInvert)
	{
		case 0: f = 0.5 break;
		case 1: f = 1.0 break;
		case 2: f = 1.2 break;
		case 3: f = 1.5 break;
		case 4: f = 2.2 break;
		case 5: f = 3.0 break;
		case 6: f = 4.5 break;
	}
	return f;
}

int TraderShipType()//������� ��������
{
	int iShipType;
	int iRank = sti(pchar.rank);
	if (iRank < 5) iShipType = SHIP_BARQUE + rand(makeint(SHIP_SCHOONER - SHIP_BARQUE)); 
	if (iRank >= 5 && iRank < 11) iShipType = SHIP_BARKENTINE + rand(makeint(SHIP_FLEUT - SHIP_BARKENTINE));
	if (iRank >= 11 && iRank < 18) iShipType = SHIP_FLEUT + rand(makeint(SHIP_CARAVEL - SHIP_FLEUT));
	if (iRank >= 18 && iRank < 25) iShipType = SHIP_CARAVEL + rand(makeint(SHIP_CARACCA - SHIP_CARAVEL)); 
	if (iRank >= 25) iShipType = SHIP_CARAVEL + rand(makeint(SHIP_NAVIO - SHIP_CARAVEL)); 
	return iShipType;
}

void GetEnemyTraderGoods()//������� �����
{
switch (rand(7))
	{
		case 0:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_EBONY;
			pchar.GenQuest.Escort.Trader.add = "������� ������";
			break;
		case 1:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_MAHOGANY;
			pchar.GenQuest.Escort.Trader.add = "�������� ������";
			break;
		case 2:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_TOBACCO;
			pchar.GenQuest.Escort.Trader.add = "������";
			break;
		case 3:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_COFFEE;
			pchar.GenQuest.Escort.Trader.add = "����";
			break;
		case 4:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_CINNAMON;
			pchar.GenQuest.Escort.Trader.add = "������";
			break;
		case 5:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_FOOD;
			pchar.GenQuest.Escort.Trader.add = "���������";
			break;
		case 6:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_WEAPON;
			pchar.GenQuest.Escort.Trader.add = "������";
			break;
		case 7:
			pchar.GenQuest.Escort.Trader.Goods = GOOD_CHOCOLATE;
			pchar.GenQuest.Escort.Trader.add = "�����";
			break;
	}
}

bool CheckFreeSitFront(ref _npchar)
{
 	ref rCharacter;
	int n;

	if (!CheckAttribute(_npchar, "Default.ToLocator")) return false;
	
	for (n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(rCharacter, Characters[n]);
		if (CheckAttribute(rCharacter, "location") && rCharacter.location == _npchar.location)
		{
            if (rCharacter.location.locator == _npchar.Default.ToLocator)
                return  false;
		}
    }
    return  true;
}