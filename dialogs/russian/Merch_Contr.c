void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	int iTrade
	int iMoney
	
	int iTradeSandal
	int iMoneySandal
	int iTradeOill
	int iMoneyOill	
	int iTradeRope
	int iMoneyRope

////////------------->>��� ������
	int iTempRope
	int iTempOill
	int iTempSandal
	int iTempShipShilk
	int iTempPoison

	int iTotalTempSandal



	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
		if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) dialog.text = "����� �� ���, ������ � ����� � ������� � ������. � ��������� ������  � �������� �������. � ��� � ���� ���� ���������� �������, ����� ���������������� ��������.";
			else dialog.text = "�����������, �������. � ��������� ������...����������� ������, ������� ������� ������ �������������. ���� � ��� ���� �����, ������, �������� ��� ���� � � �������� ��� �����. � ��� � ���� ���� ���������� �������, ����� ���������������� ��������.";
				NextDiag.TempNode = "Merch_block";
				if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) 
				{
					link.l1 = "���? ������ �� ���� ������? ��� ����� � ���� �����?";
					link.l1.go = "History_Mihail_1";
				}
				else
				{	link.l1 = "���? �����������? �����, ��� ������ �� � ����� �������� �������� ��� � ����������?";
					link.l1.go = "History_merch1";
				}
				
		break;

////------------------------>>���� ������� � ���� ������.
	case "History_merch1":
			dialog.text = "�� ��� ��, ����� �����������? � ���� ��������� ������ ������� ������ ��� ���� �����.";
			link.l1 = "�� ��� ��? � ��� ����� ���� � �������� ��� ���� �������-�����������?";
			link.l1.go = "History_merch2":
	break;

	case "History_merch2":
			if (CheckAttribute(pchar, "questTemp.full_complete_end"))dialog.text = "����, �� ������ �� ������ ���. �� � ��������� ��������� ����� � � ���� ��...��� �� ������ ����? ����� ���������...";
			else dialog.text = "����, �� ������ �� ������ ���. �� � ��������� ��������� ����� � � ���� ��...� ���� ��� ��� � ������. �������� �� ����� ������ ������� ����. � �������� �������� � �������";
			link.l1 = "��, ��� ��� ��, �������� � ����� ������ �������. ��� ��� ����� � ������� �� ��� �������?";
			link.l1.go = "History_merch3":
	break;
	
	case "History_merch3":
			dialog.text = "��� � �������, ��� ����� ����� ������ �������� ������. �������, ����������� ����, ����� � ������. ������������� ����� �� ��� ��������� �� ������ ���� �����������.";
			link.l1 = "���-��, ����� ������������.";
			link.l1.go = "Merch_block":
			link.l2 = "�� ������������� ������� ������������ ����� � �����������. ��������� ����������!";
			link.l2.go = "attak":
	break;
//////------------>������� �������
	case "History_Mihail_1":
			dialog.text = "��� �������� ������, �������� � ����� ��������� ��������. ��� ����� ���� ������. ����� ��� ��� ����.";
			link.l1 = "�� ���� ��� �� � ��� �� ��� ������, �� ����� ������ ��� ���� �����...";
			link.l1.go = "History_Mihail_2":
	break;
		
	case "History_Mihail_2":
			dialog.text = "��,�� �������. ����� ���� �� ������� �� ������� � ���� ���� � ������� �� ��������� ������� ������. � ����-�� � �� ��������� �� � ��� ������������, �� � ���� �������� ���� � ����� ��������. ���� ��� �� ������� ���� ��� ������� ���� �������� ������� �� ������� �����.";
			link.l1 = "��������? ��� �����? ������ ���������� ��� �� ����� ��� ���...��� ��� ��� �� ��������? � ��� �������?";
			link.l1.go = "History_Mihail_3":
	break;
		
	case "History_Mihail_3":
			dialog.text = "�������, ����������� ����, ����� � ������. ����� ����� ��������� �� �� ��� �� � �������� �������? ��� � ����� �� �������� �� �������. ���-��� ������� ��� ���� � �� ������� � ��� �����...�� ������ ������������?";
			link.l1 = "���-��, ����� ������������. �������� � ������ �� ����� ����� ��� ��.";
			link.l1.go = "Merch_block":
			link.l2 = "� �� ����, ��� �� �� �� ����� ����� ������, �������� �� ���������� ���. �������� � ������...";
			link.l2.go = "NoatackPlease":
	break;
	
//----------------�������� ���������� �� �� ���-->>>
	case "NoatackPlease":
			dialog.text = "�? ���������� '���'? �� ����� ����������, ����� ������������� � ������ ������!";
			link.l1 = "� ������ ������ ��� � �����������? ������ ��� ���� ���� ������� �� ������� ����.";
			link.l1.go = "NoatackPlease_2":
			link.l2 = "�� ���� �� ���������, ������. ���������!";
			link.l2.go = "attakGodMisheleYes":
	break;
	
	case "NoatackPlease_2":
			dialog.text = "������ ���. ������ �� ������ ����� ������. ������ ��� ������ ������ �� ���� ���� ����� �������������. � ���� ��������� ����...����� ������������.";
			link.l1 = "���. ��������� �����!";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "������. ������������.";
			link.l2.go = "Merch_block":
			link.l3 = "����� ��� ������� ����? ���� � ��� � ������ �� ����.";
			link.l3.go = "NoatackPlease_3":
	break;
	case "NoatackPlease_3":
			dialog.text = " (���������) "+pchar.name+" � ����� ��� ������� � �����. �� ������ ������ ����� ���? ����������� ����� ������ ��� "+ GetSexPhrase("����","��") +" ��� ��� �����.";
			link.l1 = "�� �������. ��������� �����!";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "��� ��� �� �������� �� ������, ������������";
			link.l2.go = "Merch_block":
			link.l3 = "� �������.";
			link.l3.go = "Exit":
			NextDiag.TempNode = "God_1";
	break;
	
	
	case "God_1":
			dialog.text = " (��������� � ��������) ����, ����� ���� ����� � ����� �����������!";
			link.l1 = "�� ����.";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "� ������� ���"+ GetSexPhrase("�","��") +". ��� �������� ��� ��, � ����� �� ��������������.";
			link.l2.go = "God_2":
	break;	
	
	case "God_2":
			dialog.text = "(���������) �������, ������ ��� ���� ��� ������� � �� ������� ������������. ��� ����� � �� �����������. �...���, ���, ���? �-������!";
			link.l1 = "...";
			link.l1.go = "exit":
			link.l2 = "� �� ������� � �� ���� ����� � ����� ���.";
			link.l2.go = "God_3":
			NextDiag.TempNode = "Merch_block";
	break;
	
	case "God_3":
			dialog.text = "(���������) ���� � ��������� ����� ��� � ����� �����������. �� ��� �� ������� ������.";
			link.l1 = "...";
			link.l1.go = "exit":
			pchar.quest.ship_No ="true";
			sld = CharacterFromID("MerchCotraband");
			RemovePassenger(pchar, sld);
            LAi_type_warrior_SetWateState(sld); // ������ ��� ����
            sld.lifeday = 0;
			// NextDiag.TempNode = "Exit";
			LAi_CharacterDisableDialog(npchar);
	break;
//----------------------
	case "attakGodMisheleYes":
			DialogExit();
			LAi_SetImmortal(npchar, false); // ������ ����������, ���� ����
			
			float plocx, plocy, plocz;
			GetCharacterPos(pchar, &plocx, &plocy, &plocz); // �������� xyz ��
			TeleportCharacterToPos(npchar, plocx - 0.1, plocy, plocz - 0.1); // ������� ���� ������� � ��������� ����� ��
			
			LAi_SetWarriorType(npchar); // ��� ���������� ������ ���� ������
			LAi_group_MoveCharacter(npchar, "EnemyFight"); // ���������� � ������ �����
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // ��������� ������
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // ������ �����
			
			npchar.rank = sti(pchar.rank);
			LAi_SetHP(npchar, 1000 + sti(pchar.rank) * 10, 1000 + sti(pchar.rank) * 10);	//	1000�� +10 ���� �� *10 ������� ���������
			
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			EquipCharacterbyItem(npchar, npchar.equip.blade);
			GiveItem2Character(npchar, "pistol7");
			EquipCharacterbyItem(npchar, "pistol7");
			LAi_SetCharacterUseBullet(npchar, "grapeshot");
			TakeNItems(npchar, "grapeshot", 50);
			AddItems(npchar, "gunpowder", 50);
			
			TakeNItems(npchar, "GunCap_colt", 10));
			TakeNItems(npchar, "shotgun_cartridge", 10));
			
			TakeNItems(npchar, "potion2", 25);
			pchar.quest.ship_No ="true";
			
	break;
	
	case "attak":
			DialogExit();
			LAi_SetImmortal(npchar, false); // ������ ����������, ���� ����
			
			float plocAtackX, plocAtackY, plocAtackZ;
			GetCharacterPos(pchar, &plocAtackX, &plocAtackY, &plocAtackZ); // �������� xyz ��
			TeleportCharacterToPos(npchar, plocAtackX - 0.2, plocAtackY, plocAtackZ - 0.2); // ������� ���� ������� � ��������� ����� ��
			
			LAi_SetWarriorType(npchar); // ��� ���������� ������ ���� ������
			LAi_group_MoveCharacter(npchar, "EnemyFight"); // ���������� � ������ �����
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // ��������� ������
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // ������ �����
			
			npchar.rank = sti(pchar.rank);
			LAi_SetHP(npchar, 100 + sti(pchar.rank) * 10, 100 + sti(pchar.rank) * 10);	//	1000�� +10 ���� �� *10 ������� ���������

			SetSelfSkill(npchar, 90, 90, 90, 90, 90);
			SetShipSkill(npchar, 50, 20, 25, 25, 50, 20, 20, 50, 15);
			SetSPECIAL(npchar, 8, 9, 6, 5, 10, 7, 5);
			
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			EquipCharacterbyItem(npchar, npchar.equip.blade);
			GiveItem2Character(npchar, "pistol2");
			EquipCharacterbyItem(npchar, "pistol2");
			LAi_SetCharacterUseBullet(npchar, "grapeshot");
			TakeNItems(npchar, "grapeshot", 50);
			AddItems(npchar, "gunpowder", 50);
			
			TakeNItems(npchar, "potion2", 25);
			pchar.quest.ship_No ="true";
			
	break;
	
//////////---------------->���� ��������
	case "Merch_block":
		 if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria.Governor == "true" || pchar.questTemp.Patria.GenGovernor == "true") 
			 
			{ 
				if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end") {dialog.text = "�����������, ������� ��������� ������ ������� �������...��� ��� ������ � �������? ����������� �� ������. ��� �� ��� ������?";}
				else {dialog.text = "�� �����������...�� ���� � ������ �� ���-�������? ���� ������� ������� �� ��� �������, ��� ������� ������ �����? ��� �� ������ ���? ��� �����";}
			}
				else { 
						if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end") {dialog.text = "��� �����-����� ������� �� ������� � ����� �� ���� ����...��� ��������� � �����������? ����� ��� ���������? ��������� ��� � ���� ���� �� ������";} 
							else {dialog.text = "��� ������ ����� ������ ���������. �� ���-������ ������? ����� ���� ����� �� ������� ����.";} }
	
	if (!CheckAttribute(pchar, "quest.merch_ship")	&&	pchar.questTemp.LongHappy == "end"	&&	pchar.questTemp.Saga.Helena_officer == "true")
			{
				link.l1 = "�� �������� � ��� ���� �����? � ���� ������� ���� �����, � ����� ��. ����� �������� �������� � �������.";
				link.l1.go = "merch_ship";
			}
				link.l2 = "� ���� ���� ����� ���� �� �������."	
				link.l2.go = "merch_oil";
				link.l3 = "� ����� ������� ��������� ���� ������.";
				link.l3.go = "merch_persian";
				link.l4 = "��� ���� ����� �������.";
				link.l4.go = "merch_bekaut";	
				link.l5 = "� ���� ���� ������� ����� �� �������.";
				link.l5.go = "merch_shelk";	
				link.l10 = "� ���� ������ ��������� ������.";
				link.l10.go = "goods";
	if (CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "end")
			{
				link.l6 = "� ���� ���� ������� ��� ��������� ������?";
				link.l6.go = "merch_koltPatrons";
			}
	if (CheckAttribute(pchar, "questTemp.Mtraxx"))
			{
				link.l7 = "�� �������� �� �������� �����?";
				link.l7.go = "merch_poison";
			}
				link.l9 = "�� ��������";
				link.l9.go = "Exit";
	break;
////-------------------------

		case "goods":
			dialog.text = "���, ����� ����� ��� �����������?";
			link.l1 = "��������";
			link.l1.go = "trade_prov";
			link.l2 = "� ���������, ������ �� �����.";
			link.l2.go = "exit";
		break;
		
		case "goods_again":
			dialog.text = "������ ������ ���-�� ���?";
			link.l1 = "��������";
			link.l1.go = "trade_prov";
			link.l2 = "������ ������.";
			link.l2.go = "exit";
		break;
		
		case "trade_prov":
			dialog.text = "������� ��������� �� ������ ������?";
			link.l1.edit = 4;
			link.l1 = "";	
			link.l1.go = "trade_prov_1";
		break;
		
		case "trade_prov_1":
			int iTempProv;
			iTempProv = sti(dialogEditStrings[4]);
		//	int iMax = GetSquadronGoods(pchar, GOOD_SANDAL);
			if (iTempProv <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ��������� ��� ������������.";
				link.l1 = "���, ������, �������� �����...";
				link.l1.go = "trade_prov";
			}
			iMoney = (15)*iTempProv;
			else
			{
			dialog.text = ""+FindRussianQtyString(iTempProv)+"? ������. � ������ ���� ��������� �� "+FindRussianMoneyString(iMoney)+". ����������?";
			link.l1 = "�� �����!";
			link.l1.go = "trade_prov_2";
			link.l2 = "� ���������" + GetSexPhrase("", "�") + ".";
			link.l2.go = "exit";
			}
		//	NextDiag.TempNode = "Merch_block";
		break;
		
		case "trade_prov_2":
		
			iTempProv = dialogEditStrings[4];
			iMoney = (15)*iTempProv;
			
			if (pchar.money < iMoney){
				dialog.text = "��� � ���� �������-�� �� �������, ����� ������������, ����� � �������.";
				link.l1 = "��.. � �����" +GetSexPhrase("", "�") + " ������ � �����. ����� �������!";
				link.l1.go = "exit";
			}
			else{
			
			AddMoneyToCharacter(pchar, -iMoney);
		//AddCharacterGoods(pchar, GOOD_FOOD, iTempProv);
			SetCharacterGoods(pchar, GOOD_FOOD, sti(pchar.Ship.Cargo.Goods.food) + sti(iTempProv));
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			PlaySound("interface\important_item.wav");
			dialog.text = "������� �� ������!";
			link.l1 = "�������!";
			link.l1.go = "goods_again";
			//DialogExit();
			}
		break;
		
		case "merch_ship":
			dialog.text = "���, �� ������ �����...�� ������ ������ ������� ������ ��������������� ������� ������ ��������. �� ������ ������ ������� �������� ��� �� � ���� ���?";
			if (makeint(Pchar.money) >= 50000	||	GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
			link.l1 = "�������������. ���� ���� ��� ������ �� �����. �������";
			link.l1.go = "serve_7";		
			link.l2 = "�����.";
			link.l2.go = "exit";
			}
			else
			{
			dialog.text = "�������, � ��� ��� �����.";
			link.l1 = "��������, ����� ����� �� ��������.";
			link.l1.go = "Exit";
			}
		break;
	
		case "serve_7":
//---------������� ������------>
			if (makeint(Pchar.money) >= 50000	&&	GetCharacterItem(pchar, "gold_dublon") <= 500)
			{
				AddMoneyToCharacter(Pchar, -50000);	
				CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
			
			if (GetCharacterItem(pchar, "gold_dublon") >= 500 	&& 	makeint(Pchar.money) < 50000)
			{
				RemoveItems(PChar, "gold_dublon", 500);
				CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
			
			if (makeint(Pchar.money) >= 50000	&&	GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				AddMoneyToCharacter(Pchar, -50000);	
			     CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
//--------------------<<-------�����			
		break;		
///////////////////////////////////////------����------////////////////////////////////////
		case "merch_shelk":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_SHIPSILK);
            dialog.text = "� ������� ���� �� 16 �������� �� ����� ����� ��� �� �� ��������� � ����";
			link.l1 = "� ���� "+FindRussianQtyString(iTotalTemp)+" �����.";
			if (iTotalTemp > 0) link.l1.go = "option_money";
			else link.l1.go = "merch_shelk_No";
		break;
		
		case "merch_shelk_No":
            dialog.text = "�� �����������?.";
			link.l1 = "��������!";
			link.l1.go = "Exit";
		break;
	
////////------------������� � ���������-->>>	����������� ����	20 ��������
		case "Shilk_Price":		
			dialog.text = "������� ����� �� ������ �������?";
			link.l1.edit = 1;
			link.l1 = "";	// iTradeShipshilk ���
			Link.l1.go = "result_shipshilk";
		break;
		
		case "result_shipshilk":
		    int iTradeShipshilk;
			iTradeShipshilk = sti(dialogEditStrings[1]); // ������� �������� �����
			npchar.questTemp.Gold_Dublon = sti(iTradeShipshilk)*25; // ���������� �������� ��� ���������.
			npchar.questTemp.Ship_shilk = sti(iTradeShipshilk)*1; // ���������� ������
			dialog.text = "������. ���� "+sti(npchar.questTemp.Ship_shilk)+" ����� �� "+sti(npchar.questTemp.Gold_Dublon)+" ��������.";
			if (iTradeShipshilk <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ����� ��� ������������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "Shilk_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "shilk_bay";
				Link.l2 = "� ���������..";
				Link.l2.go = "exit";
		//	}
        
		break;
		case "shilk_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_SHIPSILK, sti(npchar.questTemp.Ship_shilk));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("�� �������� "+npchar.questTemp.Gold_Dublon+" ��������");
		break;

		case "option_money":
			dialog.text = "��� �������? ���� ��� �������.";
			link.l1 = "������� ��� �� �� ������.";
			link.l1.go = "Shilk_Price";
			Link.l2 = "������ ��� �� ��������.";
			Link.l2.go = "trade_shipshilk";
		break;
//////////////////////-------------����� ������ �� �������----------<<<--

//////////////////------����� �� ������---->	����������� ����
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_SHIPSILK);
		// int iMoney = 0;

		case "trade_shipshilk":
			dialog.text = "������� ����� �� ������ �������?";
			link.l1.edit = 2;
			link.l1 = "";	
			link.l1.go = "trade_shipshilk_1";
		break;
		
		case "trade_shipshilk_1":
			iTempShipShilk = dialogEditStrings[2];
		//	int iMax = GetSquadronGoods(pchar, GOOD_SHIPSILK);
			if (iTempShipShilk <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ����� ��� ������������.";
				link.l1 = "���, ������, �������� �����...";
				link.l1.go = "trade_shipshilk";
			}
			else
			{
				iMoney = (2500)*iTempShipShilk;
				dialog.text = ""+FindRussianQtyString(iTempShipShilk)+"? ������. � ������� ���� �� ���� "+FindRussianMoneyString(iMoney)+". ����������?";
				link.l1 = "�� �����!";
				link.l1.go = "trade_shipshilk_2";
				link.l2 = "� ���������.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_shipshilk_2":
			iTempShipShilk = dialogEditStrings[2];
			iMoney = (2500)*iTempShipShilk;
			AddMoneyToCharacter(pchar, iMoney);
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, iTempShipShilk);
			npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTempShipShilk;
			DialogExit();
		break;

/////////////////////------����� �� ������----<<<

////////////////////////////////////////////////////////////////////////��������<<<------------///////////
		case "merch_bekaut":
			iTotalTempSandal = GetSquadronGoods(pchar, GOOD_SANDAL);
            dialog.text = "� ������� ���� �� 16 �������� �� ����� ������� ��� �� �� ��������� � ����";
			link.l1 = "� ���� "+FindRussianQtyString(iTotalTempSandal)+" �������.";
			if (iTotalTempSandal > 0) link.l1.go = "option_money_sandal";
			else link.l1.go = "merch_bekaut_No";
		break;
		
		case "merch_bekaut_No":
            dialog.text = "�� �����������?.";
			link.l1 = "��������!";
			link.l1.go = "Exit";
		break;
	
////////------------������� � ���������-->>>	������-��������		30 ��������
		case "Sandal_Price":		
			dialog.text = "������� ������� �� ������ �������?";
			link.l1.edit = 3;
			link.l1 = "";	// SanMerch ���
			Link.l1.go = "result_sandal";
		break;
		
		case "result_sandal":
		    int SanMerch;
			SanMerch = sti(dialogEditStrings[3]); // ������� �������� �������
			npchar.questTemp.Gold_Dublon = sti(SanMerch)*40; // ���������� �������� ��� ���������.
			npchar.questTemp.Sandal = sti(SanMerch)*1; // ���������� ������
			dialog.text = "������. ���� "+sti(npchar.questTemp.Sandal)+" ������� �� "+sti(npchar.questTemp.Gold_Dublon)+" ��������.";
			if (SanMerch <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ������� ��� ������������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "Sandal_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "sandal_bay";
				Link.l2 = "� ���������..";
				Link.l2.go = "exit";
		//	}
        
		break;
		case "sandal_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_SANDAL, sti(npchar.questTemp.Sandal));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("�� �������� "+npchar.questTemp.Gold_Dublon+" ��������");
		break;

		case "option_money_sandal":
			dialog.text = "��� �������? ���� ��� �������.";
			link.l1 = "������� ��� �� �� ������.";
			link.l1.go = "Sandal_Price";
			Link.l2 = "������ ��� �� ��������.";
			Link.l2.go = "trade_sandal";
		break;
//////////////////////-------------����� ������ �� �������----------<<<--

//////////////////------����� �� ������---->		������ ��������	

		// int iTrade = GetSquadronGoods(pchar, GOOD_SANDAL);
		// int iMoney = 0;

		case "trade_sandal":
			dialog.text = "������� ������� �� ������ �������?";
			link.l1.edit = 4;
			link.l1 = "";	
			link.l1.go = "trade_sandall_1";
		break;
		
		case "trade_sandall_1":
			iTempSandal = dialogEditStrings[4];
		//	int iMax = GetSquadronGoods(pchar, GOOD_SANDAL);
			if (iTempSandal <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ������� ��� ������������.";
				link.l1 = "���, ������, �������� �����...";
				link.l1.go = "trade_sandal";
			}
			iMoney = (4000)*iTempSandal;
			else
			{
			dialog.text = ""+FindRussianQtyString(iTempSandal)+"? ������. � ������� ���� �� ������ "+FindRussianMoneyString(iMoney)+". ����������?";
			link.l1 = "�� �����!";
			link.l1.go = "trade_sandall_2";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			}
		//	NextDiag.TempNode = "Merch_block";
		break;
		
		case "trade_sandall_2":
			iTempSandal = dialogEditStrings[4];
			iMoney = (4000)*iTempSandal;
			AddMoneyToCharacter(pchar, iMoney);
			RemoveCharacterGoods(pchar, GOOD_SANDAL, iTempSandal);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			DialogExit();
		break;

/////////////////////------����� �� ������----<<<

////////////////////////////////////////////-----------�����------------->>		������ 10 �������� �� �����
		case "merch_oil":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_OIL);
            dialog.text = "� ������� ����� �� 15 �������� �� ����� ��� �� �� ��������� � ����";
			link.l1 = "� ���� "+FindRussianQtyString(iTotalTemp)+" �����.";
			if (iTotalTemp > 0) link.l1.go = "option_moneyOil";
			else link.l1.go = "merch_oil_No";
		break;
		
		case "merch_oil_No":
            dialog.text = "�� �����������?.";
			link.l1 = "��������!";
			link.l1.go = "Exit";
		break;
	
////////------------������� � ���������-->>>	�����	10 ��������
		case "Oil_Price":		
			dialog.text = "������� ���� �� ������ �������?";
			link.l1.edit = 5;
			link.l1 = "";	// OilMerch ���
			Link.l1.go = "result_oil";
		break;
		
		case "result_oil":
		    int OilMerch;
			OilMerch = sti(dialogEditStrings[5]); // ������� �������� ����
			npchar.questTemp.Gold_Dublon = sti(OilMerch)*15; // ���������� �������� ��� ���������.
			npchar.questTemp.Oil = sti(OilMerch)*1; // ���������� ������
			dialog.text = "������. ���� "+sti(npchar.questTemp.Oil)+" ����� ����� �� "+sti(npchar.questTemp.Gold_Dublon)+" ��������.";
			if (OilMerch <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ����� ���� ��� ������������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "Oil_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "oil_bay";
				Link.l2 = "� ���������..";
				Link.l2.go = "exit";
			//}
        
		break;
		case "oil_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_OIL, sti(npchar.questTemp.Oil));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("�� �������� "+npchar.questTemp.Gold_Dublon+" ��������");
		break;

		case "option_moneyOil":
			dialog.text = "��� �������? ���� ��� �������.";
			link.l1 = "������� ��� �� �� ������.";
			link.l1.go = "Oil_Price";
			Link.l2 = "������ ��� �� ��������.";
			Link.l2.go = "trade_Oil";
		break;
//////////////////////-------------����� ������ �� �������----------<<<--

//////////////////------����� �� ������---->	�����
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_OIL);
		// int iMoney = 0;

		case "trade_Oil":
			dialog.text = "������� ���� �� ������ �������?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "trade_Oil_1";
		break;
		
		case "trade_Oil_1":
			iTempOill = dialogEditStrings[6];
		//	int iMax = GetSquadronGoods(pchar, GOOD_OIL);
			if (iTempOill <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ���� ��� ������������.";
				link.l1 = "���, ��������, �������� �����...";
				link.l1.go = "trade_Oil";
			}
			iMoneyOill = (1500)*iTempOill;
			else
			{
				dialog.text = ""+FindRussianQtyString(iTempOill)+"? ������. � ������� ���� "+FindRussianMoneyString(iMoneyOill)+". �� ��� �����.";
				link.l1 = "�� �����!";
				link.l1.go = "trade_Oil_2";
				link.l2 = "� ���������.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_Oil_2":
			iTempOill = dialogEditStrings[6];
			iMoneyOill = (1500)*iTempOill;
			AddMoneyToCharacter(pchar, iMoneyOill);
			RemoveCharacterGoods(pchar, GOOD_OIL, iTempOill);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTempOill;
			DialogExit();
		break;

/////////////////////------����� �� ������----<<<

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////-----------------------������------------->>		
		case "merch_persian":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_ROPES);
          dialog.text = "� ������� ������ �� 15 �������� �� ����� ������ ��� �� �� ��������� � ����";
			link.l1 = "� ���� "+FindRussianQtyString(iTotalTemp)+" ������.";
			if (iTotalTemp > 0) link.l1.go = "option_moneyRope";
			else link.l1.go = "merch_rope_No";
		break;
		
		case "merch_rope_No":
            dialog.text = "�� �����������?.";
			link.l1 = "��������!";
			link.l1.go = "Exit";
		break;
	
////////------------������� � ���������-->>>	������	10 ��������
		case "Rope_Price":		
			dialog.text = "������� ���� �� ������ �������?";
			link.l1.edit = 7;
			link.l1 = "";	// RopeMerch ���
			Link.l1.go = "result_rope";
		break;
		
		case "result_rope":
		    int RopeMerch;
			RopeMerch = sti(dialogEditStrings[7]); // ������� �������� ���� ������
			npchar.questTemp.Gold_Dublon = sti(RopeMerch)*15; // ���������� �������� ��� ���������.
			npchar.questTemp.Rope = sti(RopeMerch)*1; // ���������� ������
			dialog.text = "������. ���� "+sti(npchar.questTemp.Rope)+" ������ �� "+sti(npchar.questTemp.Gold_Dublon)+" ��������.";
			if (RopeMerch <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ���� ������ ��� ������������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "Rope_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "rope_bay";
				Link.l2 = "� ���������..";
				Link.l2.go = "exit";
			//}
        
		break;
		case "rope_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_ROPES, sti(npchar.questTemp.Rope));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("�� �������� "+npchar.questTemp.Gold_Dublon+" ��������");
		break;

		case "option_moneyRope":
			dialog.text = "��� �������? ���� ��� �������.";
			link.l1 = "������� ��� �� �� ������.";
			link.l1.go = "Rope_Price";
			Link.l2 = "������ ��� �� ��������.";
			Link.l2.go = "trade_Rope";
		break;
//////////////////////-------------����� ������ �� �������----------<<<--

//////////////////------����� �� ������---->	������
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_ROPES);
		// int iMoney = 0;

		case "trade_Rope":
			dialog.text = "������� ���� ������� �� �������?";
			link.l1.edit = 8;
			link.l1 = "";	
			link.l1.go = "trade_Rope_1";
		break;
		
		case "trade_Rope_1":
			iTempRope = dialogEditStrings[8];
		//	int iMax = GetSquadronGoods(pchar, GOOD_ROPES);
			if (iTempRope <= 0)
			{
				dialog.text = "�������, � ������ �� �������. ��� �������� ������� ���� ������ ��� ������������.";
				link.l1 = "���, ������, �������� �����...";
				link.l1.go = "trade_Rope";
			}
			else
			{
				iMoneyRope = (1500)*iTempRope;
				dialog.text = ""+FindRussianQtyString(iTempRope)+"? ������. � ������� ���� �� ������ "+FindRussianMoneyString(iMoneyRope)+". ����������?";
				link.l1 = "�� �����!";
				link.l1.go = "trade_Rope_2";
				link.l2 = "� ���������.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_Rope_2":
			iTempRope = dialogEditStrings[8];
			iMoneyRope = (1500)*iTempRope;
			AddMoneyToCharacter(pchar, iMoneyRope);
			RemoveCharacterGoods(pchar, GOOD_ROPES, iTempRope);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			DialogExit();
		break;

/////////////////////////////////////////////////////////////////////////////////////////
////----->�������� �������������� � ����
		case "merch_koltPatrons":
            dialog.text = "� ���� ������� ���. � ������� � ���. �� ��� ����� ������ ������";
			link.l1 = "������ �� ��������, ������� ������ �������.";
			link.l1.go = "pula_Price";
		break;


		case "pula_Price":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")	
			{
				dialog.text = "����, ����� ����� ������. ���� �������� ����� 10 ��������, ��� ��������� ����������� ����� ������. ������� �� ������ ������ ����������?";
			}
			else 
			{
				dialog.text = "���, ��������� ��� ���������� ��� ����������?. ���� �������� ����� 10 ��������, ��� ��������� ����������� ����� ������. ������� �� ������ ������ ����������?";
			}
			link.l1.edit = 9;
			link.l1 = "";	// bk ���
			Link.l1.go = "result_boekomplekt";
		break;
		
		case "result_boekomplekt":
		    int bk;
			bk = sti(dialogEditStrings[9]); // ������� ���� ��������
			npchar.questTemp.boe_kom.Qty = sti(bk); // ���������� �������� ��� ������.
			npchar.questTemp.boe_kom.summ = sti(bk)*10; // ����� �� ������� 
			dialog.text = "������. � ���� "+sti(npchar.questTemp.boe_kom.summ)+" ��������, ���. �� ��������� �����.";
			if (bk <= 0)
			{
				dialog.text = "���, ������ �������? ��� ����� ������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "pula_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.boe_kom.summ)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "boekomplekt_bay";
				Link.l2 = "��� ��, ��������.";
				Link.l2.go = "exit";
		//	}
		break;
   
		case "boekomplekt_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveItems(pchar, "gold_dublon", sti(npchar.questTemp.boe_kom.summ));
			TakeNItems(pchar, "GunCap_colt", sti(npchar.questTemp.boe_kom.Qty));
			TakeNItems(pchar, "shotgun_cartridge", sti(npchar.questTemp.boe_kom.Qty));
			Log_Info("�� ������ "+npchar.questTemp.boe_kom.Qty+" �����������(-'�',-'��') ��� ������");
		break;

//---------------------------------------��
		case "merch_poison":
            dialog.text = "� ���� ������� ���. � ������� � ���. �� ��� ����� ������ ������";
			link.l1 = "������ �� ��������, ������� ������ �������.";
			link.l1.go = "poison_Price2";
		break;


		case "poison_Price2":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")	
			{
				dialog.text = "����, ����� ����� ������. ���� �� ����� 10 ��������, ��� ��������� ����������� ����� ������. ������� �� ������ ������?";
			}
			else 
			{
				dialog.text = "���, ��������� ��� ���������� ��� ����������?. ���� �� ����� 10 ��������, ��� ��������� ����������� ����� ������. ������� �� ������ ������?";
			}
			link.l1.edit = 9;
			link.l1 = "";	// bk ���
			Link.l1.go = "result_poison";
		break;
		
		case "result_poison":
		    int poison;
			poison = sti(dialogEditStrings[9]); // ������� ���� ��������
			npchar.questTemp.boe_kom.poisonTaito = sti(poison); // ���������� �������� ��� ������.
			npchar.questTemp.boe_kom.summ2 = sti(poison)*10; // ����� �� �� 
			dialog.text = "������. � ���� "+sti(npchar.questTemp.boe_kom.summ2)+" ��������, ���. �� ��������� �����.";
			if (poison <= 0)
			{
				dialog.text = "���, ������ �������? ��� ����� ������.";
				link.l1 = "��, ������, �������� �����...";
				link.l1.go = "exit";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.boe_kom.summ)) 
		//	{				
				Link.l1 = "�� �����!";
				Link.l1.go = "poison_bay";
				Link.l2 = "��� ��, ��������.";
				Link.l2.go = "exit";
		//	}
		break;
   
		case "poison_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveItems(pchar, "gold_dublon", sti(npchar.questTemp.boe_kom.summ2));
			TakeNItems(pchar, "indian_poison", sti(npchar.questTemp.boe_kom.poisonTaito));
			Log_Info("�� ������ "+npchar.questTemp.boe_kom.poisonTaito+" ��� �����");
		break;

/////////////////////////////////////////////////////////////////////////////////////////
/*
	/*
		case "serve_7":
			AddMoneyToCharacter(Pchar, -50000);
			DialogExit();
	//-------������ ����� ����.------->>>		
			sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
	        SetFantomParamFromRank(sld, 10, true);
	        FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "����� �������", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
	        SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
	        SetSelfSkill(sld, 20, 22, 18, 25, 30);
	        sld.dialog.FileName = "Enc_Officer_dialog.c";
            sld.dialog.currentnode = "Enc_Officer_dialog";
			sld.greeting = "patrol";
			SetCharacterPerk(sld, "BasicDefense");
			SetCharacterPerk(sld, "AdvancedDefense");
			SetCharacterPerk(sld, "Gunman");
			SetCharacterPerk(sld, "LongRangeGrappling");
			SetCharacterPerk(sld, "HullDamageUp");
			SetCharacterPerk(sld, "SailsDamageUp");
			SetCharacterPerk(sld, "CrewDamageUp");
			SetCharacterPerk(sld, "BasicBattleState");
			SetCharacterPerk(sld, "ShipSpeedUp");
			SetCharacterPerk(sld, "ShipTurnRateUp");
			SetCharacterPerk(sld, "StormProfessional");
			SetCharacterPerk(sld, "Doctor1");
			sld = characterFromId("RadugaOfficer");
			SetCharacterRemovable(sld, true);
			SetCompanionIndex(pchar, -1, sti(sld.index));
			sld.loyality = MAX_LOYALITY;
	//<<-------------����� ����� ����		
	////--->�������
			sld.ship.Crew.Morale = 100;
			sld.Ship.Crew.Exp.Sailors = 100;
			sld.Ship.Crew.Exp.Cannoners = 100;
			sld.Ship.Crew.Exp.Soldiers = 100;
			AddCharacterGoods(sld, GOOD_BALLS, 700);
			AddCharacterGoods(sld, GOOD_GRAPES, 700);
			AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
			AddCharacterGoods(sld, GOOD_BOMBS, 700);
			AddCharacterGoods(sld, GOOD_POWDER, 1000);
			AddCharacterGoods(sld, GOOD_FOOD, 1000);
			AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
			AddCharacterGoods(sld, GOOD_RUM, 200);
			AddCharacterGoods(sld, GOOD_PLANKS, 50);
			AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
			RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;	//	������������ ������
			RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;	//	���������� �����
			RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;	//	����������� ������
			RealShips[sti(sld.Ship.Type)].Capacity = 5000;	//	����������� �����
			RealShips[sti(sld.Ship.Type)].MaxCrew = 800;	//	�������� �������
			RealShips[sti(sld.Ship.Type)].MinCrew = 200;	//	����������� �������
			RealShips[sti(sld.Ship.Type)].OptCrew = 500;	//	����������� �������
			RealShips[sti(sld.Ship.Type)].SpeedRate = 99.99;	//	��������
			RealShips[sti(sld.Ship.Type)].TurnRate = 99.99;	//	�������������
			RealShips[sti(sld.Ship.Type)].HP = 1450;	// ��������� �������
			RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;	//
			RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
		//	SetSailsColor(sld, 8);//������ �����
			UpgradeShipParameter(sld, "SpeedRate");//���������� ��������
			UpgradeShipParameter(sld, "TurnRate");//�������������
			UpgradeShipParameter(sld, "WindAgainstSpeed");//����
			UpgradeShipParameter(sld, "Capacity");//������� �����			
			UpgradeShipParameter(sld, "HP");//HP
			UpgradeShipParameter(sld, "MaxCrew");//������� �������
			SetCrewQuantityFull(sld);	// ������������ ������� ��� ������� �������
		//<-------����� �������	
			NextDiag.CurrentNode = "Merch_block";
			pchar.quest.merch_ship ="true";
		break;



														��� �����
			
	void CreateRaduga() // �����
{
		sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
		SetFantomParamFromRank(sld, 10, true);
		FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "����� �������", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
		SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
		SetSelfSkill(sld, 20, 22, 18, 25, 30);
	//	sld.dialog.FileName = "Enc_Officer_dialog.c";
	//	sld.dialog.currentnode = "Enc_Officer_dialog";
		sld.greeting = "patrol";
	//	NullCharacterGoods(sld);
		sld.greeting = "patrol";
		SetCharacterPerk(sld, "BasicDefense");
		SetCharacterPerk(sld, "AdvancedDefense");
		SetCharacterPerk(sld, "Gunman");
		SetCharacterPerk(sld, "LongRangeGrappling");
		SetCharacterPerk(sld, "HullDamageUp");
		SetCharacterPerk(sld, "SailsDamageUp");
		SetCharacterPerk(sld, "CrewDamageUp");
		SetCharacterPerk(sld, "BasicBattleState");
		SetCharacterPerk(sld, "ShipSpeedUp");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "StormProfessional");
		SetCharacterPerk(sld, "Doctor1");
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		SetCrewQuantityFull(sld);
		AddCharacterGoods(sld, GOOD_BALLS, 700);
		AddCharacterGoods(sld, GOOD_GRAPES, 700);
		AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
		AddCharacterGoods(sld, GOOD_BOMBS, 700);
		AddCharacterGoods(sld, GOOD_POWDER, 1000);
		AddCharacterGoods(sld, GOOD_FOOD, 1000);
		AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
		AddCharacterGoods(sld, GOOD_RUM, 200);
		AddCharacterGoods(sld, GOOD_PLANKS, 50);
		AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
		RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;
		RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;
		RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;
		RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
		RealShips[sti(sld.Ship.Type)].MinCrew = 200;
		RealShips[sti(sld.Ship.Type)].OptCrew = 500;
		RealShips[sti(sld.Ship.Type)].SpeedRate = 99.99;
		RealShips[sti(sld.Ship.Type)].TurnRate = 99.99;
		RealShips[sti(sld.Ship.Type)].HP = 1450;
		RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;
	//	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
	//	SetSailsColor(sld, 8);//������ �����
		UpgradeShipParameter(sld, "SpeedRate");//���������� ��������
		UpgradeShipParameter(sld, "TurnRate");//�������������
		UpgradeShipParameter(sld, "WindAgainstSpeed");//����
		SetCrewQuantityFull(sld);

;
////////////////////////////////////////////////////////////////////////////////////////////////////	
*/
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}

}


		
	void CreateRaduga() // �����
{	 	
		ref sld;
//	-------------���� �������-->
		sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
		SetFantomParamFromRank(sld, 10, true);
		FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "����� �������", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
		SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
		SetSelfSkill(sld, 20, 22, 18, 25, 30);
	//	sld.dialog.FileName = "Enc_Officer_dialog.c";
		sld.dialog.FileName = "Enc_Officer_dialog.c";
	//	sld.dialog.currentnode = "Enc_Officer_dialog";
		sld.greeting = "patrol";
	//	NullCharacterGoods(sld);
		sld.greeting = "patrol";
		SetCharacterPerk(sld, "BasicDefense");
		SetCharacterPerk(sld, "AdvancedDefense");
		SetCharacterPerk(sld, "Gunman");
		SetCharacterPerk(sld, "LongRangeGrappling");
		SetCharacterPerk(sld, "HullDamageUp");
		SetCharacterPerk(sld, "SailsDamageUp");
		SetCharacterPerk(sld, "CrewDamageUp");
		SetCharacterPerk(sld, "BasicBattleState");
		SetCharacterPerk(sld, "ShipSpeedUp");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "StormProfessional");
		SetCharacterPerk(sld, "Doctor1");
		
		///////////////---------���� �������-->
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		SetCrewQuantityFull(sld);
		AddCharacterGoods(sld, GOOD_BALLS, 700);
		AddCharacterGoods(sld, GOOD_GRAPES, 700);
		AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
		AddCharacterGoods(sld, GOOD_BOMBS, 700);
		AddCharacterGoods(sld, GOOD_POWDER, 1000);
		
		AddCharacterGoods(sld, GOOD_FOOD, 1000);
		AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
		AddCharacterGoods(sld, GOOD_RUM, 200);
		
		AddCharacterGoods(sld, GOOD_PLANKS, 50);
		AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
		
		RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;	//	������������ ������
		RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;	//	���������� �����
		RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;	//	����������� ������
		RealShips[sti(sld.Ship.Type)].Capacity = 5000;	//	����������� �����
		RealShips[sti(sld.Ship.Type)].MaxCrew = 122;	//	�������� �������
		RealShips[sti(sld.Ship.Type)].MinCrew = 18;	//	����������� �������
		RealShips[sti(sld.Ship.Type)].OptCrew = 96;	//	����������� �������
		RealShips[sti(sld.Ship.Type)].SpeedRate = 15.0;	//	��������
		RealShips[sti(sld.Ship.Type)].TurnRate = 50.0;	//	�������������
		RealShips[sti(sld.Ship.Type)].HP = 1450;	// ��������� �������
		RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;
		RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
	//	SetSailsColor(sld, 8);//������ �����
		UpgradeShipParameter(sld, "SpeedRate");//���������� ��������
		UpgradeShipParameter(sld, "TurnRate");//�������������
		UpgradeShipParameter(sld, "WindAgainstSpeed");//����
		UpgradeShipParameter(sld, "Capacity");//������� �����			
		UpgradeShipParameter(sld, "HP");//HP
		UpgradeShipParameter(sld, "MaxCrew");//������� �������
		SetCrewQuantityFull(sld);	// ������������ ������� ��� ������� �������
	}
