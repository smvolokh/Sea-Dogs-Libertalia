// ������ �� �������
// ��� ������ �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    string 	sTemp;
	int 	amount, iSan, iOil, iSil, iRop;
	int iTemp, iSum; // 280912
	ref 	shTo;
	string 	s1;
	
	int     Matherial1;
	int     Matherial2;
	int     Matherial3;
	int     Matherial4;
	int		HPPrice; 
	
	if ( sti(pchar.Ship.Type) != SHIP_NOTUSED)
	{
		int   	shipCurHP   = sti(RealShips[sti(pchar.Ship.Type)].HP);
		int   	shipBaseHP	= sti(RealShips[sti(pchar.Ship.Type)].BaseHP);
		int   	shipClass   = sti(RealShips[sti(pchar.Ship.Type)].Class);
	}	
 
	switch (Dialog.CurrentNode)
	{		
		// -----------------------------------������ ������ - ������ �������
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
  // �������� ��������� �������, ������ ���� ���
			if(NPChar.quest.meeting == "0")
			{
				Dialog.Text = "���������� ���! ���� ����� " + GetFullName(npchar) + ", ��� ���� ���� �������?";
				Link.l1 = pcharrepphrase("��� ��� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.",
					"������������, ���� ����� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.");
				Link.l1.go = "node_3";
				npchar.quest.meeting = "1";
			}
			else // �����, ���� �� ������� ����� ����� ��  "First time"
			{
				dialog.text = "���������� ���, �������! ��� ���������?";
				link.l1 = pcharrepphrase("������� ����� ������� � ����.",
					"����������, ������! ��� � ����� ����. � � ��� �� ����.");
				link.l1.go = "node_3";
				link.l2 = pcharrepphrase("�� �������.",
					"��� ����, ��������, ��� �����������"+ GetSexPhrase("","�") +".");
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "Master_Ship";
			Dialog.CurrentNode = "Master_Ship";
		break;
		
		case "Master_Ship":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");

			dialog.text = "���������� ���, �������! ��� ���������?";
			link.l1 = pcharrepphrase("������� ����� ������� � ����.",
					"����������, ������! ��� � ����� ����. � � ��� �� ����.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("�� �������.",
					"��� ����, ��������, ��� �����������"+ GetSexPhrase("","�") +".");
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Ship";
		break;

		case "node_1":
			dialog.text = "��������-��������, �� ��������� �� ��� �������� ��������. ������� ������, ������� ����, ��� ��� ��� ����?";
			link.l1 = pcharrepphrase("��� �����. �� ���� ��� ������ ����� �������� �����, � ������, ���� ����� ��� ������...",
				"���-�� ������������ ���, ��� �� � ���� ������� ���� ���� �� ���������� ������ ��������� � ��������. ����� �� ���?");
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.text = "�� ������ �������, "+ GetSexPhrase("�����","��������") +"!";
			link.l1 = pcharrepphrase("�����-�����, �� �������, � �� ���� ������. �� ����, ���� ���� �������� � ������ ������� �������� �� �������. �������-�� ����� �������� � ������.",
				"� ������ ��� ��� ��������, ������ �� �������� � ������ ��������. � ������, ���� �� ���������, ������� ����� �������� � �����.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("���, � ���� ������ �����������! ��������!",
				"� ����, ������ ����� �� �� ������. ��������.");
			link.l2.go = "exit";
		break;

		case "node_3":
			dialog.text = "��� ���� �������, " + GetAddress_Form(NPChar) + "? ";
			link.l1 = pcharrepphrase("��� ���� ��������������� �������� �����.","� ���� ��������������� �������� ����� �����.");
			link.l1.go = "shipyard_dlg";
            Link.l2 = "� ���� ������.";
			Link.l2.go = "quests"; //(��������� � ���� ������)
			// -->
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l3 = "� �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ����� ����������.";
				link.l3.go = "LoanForAll";//(���������� � ���� ������)
			}
			link.l9 = pcharrepphrase("����, � ���� ���� ���� ���������� ���, �� ��������.", "��� ��� ����, ��������.");
			link.l9.go = "exit";
			NextDiag.TempNode = "Master_Ship";
		break;
		
		case "shipyard_dlg":			
			if((shipBaseHP - shipCurHP > 0) && (shipClass > 1))
			{
			dialog.Text = "��� ���� ���� �������?";		
				//Link.l1 = "������������! � ���� ��� ��� ���� ����� ��������, ��������� �������. ����� ���������, ��� ����� �������?";
				//Link.l1.go = "ship_repair_start";		
			}
			else
			{
				dialog.Text = "��� ���� ���� �������?";
			}	
			link.l2 = "� ���� ������ ��������������� �������� �����.";
			link.l2.go = "shipyard";
			link.l3 = "��� ����� ������ �� �������.";
			link.l3.go = "Cannons";
			if(RealShips[sti(Pchar.Ship.Type)].BaseType != SHIP_CURSED_FDM)
			{
					link.l4 = "���� �������� ������� ��� �������.";
					link.l4.go = "SailsGerald";
			}
			else
			{
				dialog.Text = "��� ���� �������?";
			}				
			link.l2 = "� ���� ������ ��������������� �������� �����.";
			link.l2.go = "shipyard";
			link.l3 = "��� ����� ������ �� �������.";
			link.l3.go = "Cannons";
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l5 = "� �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ����� ����������.";
				link.l5.go = "LoanForAll";//(��������� � ���� ������)
			}
			Link.l9 = "�����, ��������.";
			Link.l9.go = "exit";
		break;
		
		case "ship_tunning_not_now_2":
			dialog.Text = "�� ��, � �������, ��� � �������! ������ �������! �������, ����� �������� � �� �������� ���� �� ��������.";
			Link.l1 = RandPhraseSimple("�������! ����� ��������.", "����, ������. ����� � ��� ��������.");
			Link.l1.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_start":
            if ( sti(Pchar.Ship.Type) == SHIP_NOTUSED || Pchar.location.from_sea != "Roseau_port")
            {
                dialog.Text = "�������-�� ���? ��� �� ��� ��� ������ ��������?!";
			    Link.l1 = "� �� ������... ��� ��� �... ���������";
			    Link.l1.go = "exit";
            }
            else
            {
			    if (GetHour() == 13)
			    {
					dialog.Text = "�, �������, ����������, �� � � ���� ���� ��������� �����. ��������� �����!";
			        Link.l1 = "�������...";
			        Link.l1.go = "ship_tunning_not_now";
			    }
			    else
			    {
                    if( makefloat(shipCurHP)/makefloat(shipBaseHP) < 0.10)
                    {
						dialog.Text = "�-�-�... �������-�� ���� ������ ������! �� �������� � �� ����������� ������, � �� �����. ���� �� ������� �������� ������...";
    			        Link.l1 = "�������... ����� ����...";
    			        Link.l1.go = "ship_tunning_not_now";
    			        break;
                    }
					if( makefloat(shipCurHP)/makefloat(shipBaseHP) > 0.95)
                    {
						dialog.Text = "�� ������ ��� ������. ���� ������� �������� ��� ����� - ������ ����������� ���������, ������������� ��� ���� ������.";
						Link.l1 = "�������... �� � ����� ���-������ �����...";
    			        Link.l1.go = "ship_tunning_not_now";
    			        break;
					}
                    s1 = "���-���... ���������, ��� ��� � ��� ����... ���, " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) + ".";
    			    if (sti(RealShips[sti(Pchar.Ship.Type)].Stolen) == true && !CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning"))
    			    {
    			        s1 = s1 + " ��! �� �������-�� ������� �� � ����� �����. ��-�� �� ����� ��������. ������ ���������� � ���� ����? �����, ����... � ����.";
    			    }
                    dialog.Text = s1;
					Link.l1 = "������� ��������� ��� ����� �������.";
    			    Link.l1.go = "ship_repair_HP";		    			    
    			    Link.l2 = "��������! � ���������"+ GetSexPhrase("","�") +".";
    			    Link.l2.go = "ship_tunning_not_now_2";
			    }
			}
		break;
		
		case "ship_repair_HP":
			HPPrice 	= GetMaterialQtyRepair( pchar, 0 ); 
			Matherial1	= GetMaterialQtyRepair( pchar, 1 );
			Matherial2	= GetMaterialQtyRepair( pchar, 2 );
			Matherial3	= GetMaterialQtyRepair( pchar, 3 );
			Matherial4	= GetMaterialQtyRepair( pchar, 4 );
			
			s1 = "������� ���������, ��� ����� �������. ������ ����� ������ " + shipCurHP + ". ����������� ��������� �������� " + shipBaseHP;			
			s1 = s1 + ". ��� ������� ������� ��� �����������: ������� - "+ Matherial1 + ", ���� - " + Matherial2 + ", ������������ ����� - " + Matherial3 + " ������� - " + Matherial4 + ".";
			s1 = s1 + " �� ������ ������: "+ HPPrice + " �������� �� ������� �������... ����� ����� ����� ���� ����� � ������, �� �������, ������ ��, ������������ � ������� ������... ���, ������� � ��. �� �� - ������ ������.";
            dialog.Text = s1;
			Link.l1 = "�������. � �������� �������. �� ����������� ����� ����������.";
			if(CheckItemMyCabin("gold_dublon") >= HPPrice)
			{
				Link.l1.go = "ship_repair_HP_start_0";
			}
			else
			{
				Link.l1.go = "ship_repair_HP_start";
			}			
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_HP_start_0":
			dialog.Text = "��, �� ������: ����� �������� �����, ����� ��������� ���������� �� ������� �� ����������� ������. ��� ������?";
			link.l1 = "����� ����������.";
			link.l1.go = "ship_repair_HP_start";
			link.l2 = "�������� ����������. ����� ���������� � ���� � �������� ������� ���������...";
			link.l2.go = "ship_repair_HP_start_1";
		break;
		
		case "ship_repair_HP_start":
		    amount = HPPrice;
		    if(GetCharacterItem(pchar,"gold_dublon") >= amount)
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Repair.Money  		= amount;
			    NPChar.Repair.Matherial1 	= Matherial1; 
			    NPChar.Repair.Matherial2    = Matherial2;
				NPChar.Repair.Matherial3 	= Matherial3; 
			    NPChar.Repair.Matherial4    = Matherial4; 				 				
			    NPChar.Repair.ShipType      = Pchar.Ship.Type;
			    NPChar.Repair.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NPChar.Repair.Delta         = shipBaseHP - shipCurHP;
			    			
				NextDiag.TempNode = "ship_repair_HP_again";
                dialog.text = "��� � ������. ��� ��������.";
			    link.l1 = "�������"+ GetSexPhrase("","�") +" �� ����...";
			    link.l1.go = "Exit";
			    
			    ReOpenQuestHeader("ShipRepair");
			    AddQuestRecord("ShipRepair", "t1");
				AddQuestUserData("ShipRepair", "sText",  "�� ���� ������ �� ������������ ������� ������� ������� " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) +
				" ������-������� �������: ������� - " + NPChar.Repair.Matherial1 + ", ���� - "+ NPChar.Repair.Matherial2 + ", ������������ ����� - " + NPChar.Repair.Matherial3 + " ������� - " + NPChar.Repair.Matherial4 + 
				". � �������� ������� ���� �������� " + NPChar.Repair.Money + " ��������... �������, ��� � ������ �������� - ���, ��������, ������ ����.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now";
                dialog.text = RandPhraseSimple("�� ���� �������...","�� ������ ��� ������....");
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_repair_HP_start_1":
			AddTimeToCurrent(0, 30);
		    amount = HPPrice;
			GetItemMyCabin("gold_dublon", amount);
		    
			NPChar.Repair.Money  		= amount;
			NPChar.Repair.Matherial1 	= Matherial1; 
			NPChar.Repair.Matherial2    = Matherial2; 
			NPChar.Repair.Matherial3 	= Matherial3; 
			NPChar.Repair.Matherial4    = Matherial4; 				 							
			NPChar.Repair.ShipType      = Pchar.Ship.Type;
			NPChar.Repair.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
			NPChar.Repair.Delta         = shipBaseHP - shipCurHP;
			    			
			NextDiag.TempNode = "ship_repair_HP_again";
			dialog.text = "��� � ������. ��� ��������.";
			link.l1 = "�������"+ GetSexPhrase("","�") +" �� ����...";
			link.l1.go = "Exit";
			
			ReOpenQuestHeader("ShipRepair");
			AddQuestRecord("ShipRepair", "t1");
			AddQuestUserData("ShipRepair", "sText",  "�� ���� ������ �� ������������ ������� ������� ������� " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) +
			" ������-������� �������: ������� - " + NPChar.Repair.Matherial1 + ", ���� - "+ NPChar.Repair.Matherial2 + ", ������������ ����� - " + NPChar.Repair.Matherial3 + " ������� - " + NPChar.Repair.Matherial4 +
			". � �������� ������� ���� �������� " + NPChar.Repair.Money + " ��������... �������, ��� � ������ �������� - ���, ��������, ������ ����.");
			
		break;
		
		case "ship_repair_HP_again":
		    if (sti(NPChar.Repair.ShipType) == sti(Pchar.Ship.Type) && NPChar.Repair.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_repair_HP_again";
				dialog.Text = "������ ����. ������"+ GetSexPhrase("","��") +", ��� � ������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_repair_HP_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Repair");
                NextDiag.TempNode = "ship_repair_again";
			    dialog.Text = "������� ���, �����"+ GetSexPhrase("�","���") +", ��� �� �������� ������� �� ������� ������ �������. �������� ��� ������ �����������...";
			    Link.l1 = "���� ����. ������, ��� ������� ������...";
			    Link.l1.go = "Exit";		    
			    AddQuestRecord("ShipRepait", "Lose");
			    CloseQuestHeader("ShipRepair");
			}
		break;
		
		case "ship_repair_HP_again_2":
			checkMatherial_repair(Pchar, NPChar, GOOD_SANDAL, 	1);
			checkMatherial_repair(Pchar, NPChar, GOOD_OIL, 		2);
			checkMatherial_repair(Pchar, NPChar, GOOD_SHIPSILK, 3);
			checkMatherial_repair(Pchar, NPChar, GOOD_ROPES, 	4);
		    if(sti(NPChar.Repair.Matherial1) < 1 && 
			   sti(NPChar.Repair.Matherial2) < 1 &&
			   sti(NPChar.Repair.Matherial3) < 1 &&
			   sti(NPChar.Repair.Matherial4) < 1)
			{
                NextDiag.TempNode = "ship_repair_again";
                dialog.text = "��� ������"+ GetSexPhrase("","��") +". �������! ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_repair_HP_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_repair_HP_again";
				dialog.Text = "���� �������� ��������: ������� - "+ sti(NPChar.Repair.Matherial1) + ", ���� - "+ sti(NPChar.Repair.Matherial2) + ", ������������ ����� - " + NPChar.Repair.Matherial3 + " ������� - " + NPChar.Repair.Matherial4 + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";

                AddQuestRecord("ShipRepair", "t1");
				AddQuestUserData("ShipRepair", "sText", "��� �������� �������: ������� - "+ NPChar.Repair.Matherial1 + ", ���� - "+ NPChar.Repair.Matherial2 + ", ������������ ����� - " + NPChar.Repair.Matherial3 + " ������� - " + NPChar.Repair.Matherial4 + ".");
			}
		break;
		
		case "ship_repair_HP_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
			shTo.HP = sti(shTo.HP) + sti(NPChar.Repair.Delta);
		    DeleteAttribute(NPChar, "Repair");
			
			pchar.ship.hp = GetCharacterShipHP(pchar);
			DeleteAttribute(pchar, "ship.hulls");
			DeleteAttribute(pchar, "ship.blots");		
			
            NextDiag.TempNode = "node_3";
			dialog.Text = "... ����� �� ���... ����������, ��� ��������� ���� �������� ������ ����� ����� ��������!";
			Link.l1 = "�������! �� � ���� ����� �� ������������������.";
			Link.l1.go = "Exit";
			AddQuestRecord("ShipRepair", "End");
			CloseQuestHeader("ShipRepair");
		break;		
		
		///////////////////////////////  ��������� �����
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "� ���� �� �����, �� � ������ � ������, � ����� ����������� �������������� �� �����.",
                          "�� ��� �� �������? ��� ���� - ������� �������, ������� ���� � ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "��, ������...", "�������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if ((pchar.questTemp.different == "GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakAlexus"))
			{
				link.l1 = "���� ���������� ������.";
				link.l1.go = "Al_ShipLetters_1";// ���������  "��������� ���������"
				pchar.questTemp.different.GiveShipLetters.speakAlexus = true;
			}

			if (pchar.questTemp.piratesLine == "KillLoy_toAlexus")
			{
				link.l1 = "� ��� ������ ��� �������?";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork")
			{
				link.l1 = "����� ������� ��� '�������� �����'!";
				link.l1.go = "PL_Q3_SW1";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_LoyIsDied")
			{
				link.l1 = "� ���� �� ����� ������� ������� ������������ ������ ����������� �����, ������� ��� ����...";
				link.l1.go = "PL_Q3_SW2";
			}
			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "� �� ��������� ������ ��������� �������� � �������, ������ �� ������ �� ����, ����� ��� �����, ����� ����� ����� - ������?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

		break;
//*************************** ��������� - "��������� ������� ���������" **************
		
		case "Al_ShipLetters_1":
			dialog.text = "��������� �������.";
			s1 = "� ����, �� ���������� �����������, �������� ��������� ��������� ����� ������� ����������, ��� �� ���������� � ������.";
			s1 = s1 + "����� �� ����� � �� ��������� �� �������, �� ������������. ������ ������-�������� ��������� �������� ��� ������...";
			link.l1 = s1;
			link.l1.go = "Al_ShipLetters_2";			
		break;
		case "Al_ShipLetters_2":
			s1 = "�����-�� ���������! �������������, ������� ������ ������. ��� ��, ����� ��� ����������, �����"+ GetSexPhrase("�","���") +"! ";
			s1 = s1 + "��� ��� ��� ����������� ������ ����� ��������, � �, � ���� ������� ��������� ��� " + sti(pchar.questTemp.different.GiveShipLetters.price5) + " ����. ��� �������?";
			dialog.text = s1;
			link.l1 = "�������� ����������� ��������! ������� �� � ������"+ GetSexPhrase("��","��") +"!";
			link.l1.go = "Al_ShipLetters_3";
			link.l2 = "�������, ���.";
			link.l2.go = "exit";
		break;
		case "Al_ShipLetters_3":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price5)); 
			ChangeCharacterComplexReputation(pchar,"nobility", -1); 
			OfficersReaction("bad"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "9");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
		
				
		// ����� ����
		case "tieyasal":
			dialog.text = "�-�, ��� ������ �������� ������! ��� ��, ���, ���. � ����� ��� � ���� �����������, � ���, � ���. �� ��� �� � ������� ���, ��� �������� ������ �����, ����� �� ���� �������� ��������� � ����� �� �����?";
			link.l1 = "���?.. �� ��� � ��� ������, ������?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "��, ��������, ������� �������, � ���-�� �������. H� ��������� �������� �� ��� ��������... �������������� ��� ������, ��� ��... �������� ����, ������������ ���� ����������� - � ����� �����. ��� ������ ��� ��� ��� ����� ���� �� � ��� ����������.";
			link.l1 = "� ������ ������ ���? �� ����������?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "� ��� �� ��� �����. ����� � ��������� ���� ���������, � ����� ��� � ����� � ���� ������.";
			link.l1 = "����. �������, ������!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			npchar.quest.tieyasal = "true";
		break;

//*************************** �������, ����� �3, ������ ��� ***************************
		case "PL_Q3_1":
			dialog.text = "�������... � ��� �� ����� �����?";
			link.l1 = "�-�, ��� � �������� �� ������� �� ������� �� ��������� �������� �����. �� ����������� ��� ��������, ������, � �� ����� ��������� �� ��� �������.";
			link.l1.go = "PL_Q3_3";
			link.l2 = "� ��� ����, ����� �� ��������, � ��� � ������� �������, ��� �� ������� ����...";
			link.l2.go = "PL_Q3_2";
		break;
		case "PL_Q3_2":
			dialog.text = "���. ����, ������. ��� ������... ��� ������ ������������! ��, ��� ���, ��� � ������, �����, ��� ����� ������ ����� ������� ���. ����� ���� �������\n����� ����, ���� ���� ��� � ����. ���, ���, ��� � �����������, ��������"+ GetSexPhrase("��","���") +", ����.";
			link.l1 = "�������! ��� ����!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "10");
			pchar.questTemp.piratesLine = "KillLoy_toJackman";
		break;
		case "PL_Q3_3":
			dialog.text = "��� �� ��� ������������ �� ������� �������? ��, ���� ���-�� ������� ���� ���������! �������������? �� ���� �������! ������ ������ �� ������, � �������� ������ '�������� �����' �������� ���� ������...";
			link.l1 = "'�������� �����'?";
			link.l1.go = "PL_Q3_4";
		break;
		case "PL_Q3_4":
			dialog.text = "'������� ����' ��� ���������� ����. ��� ���������� ����! ����� ������ ��� ��������! ��� ���� � ���� ������. �� ���������, ����������� � ����������! ����� ������ �� ������ ������������ ������ ��� ������, �� ���� ���������� �������� ������. �� �������, ����� �������� ��������� ������, �� ������� ��������������� ������ ��������! � ��� �� �������� �� ������...";
			link.l1 = "���, ������, ����� �������� � ������ ���.";
			link.l1.go = "PL_Q3_5";
		break;
		case "PL_Q3_5":
			dialog.text = "��������? �, ��. ������ ���. ���������� ����-�� � ������ �����, �������� �����, � ��� ��, ���, � �������. � �����, ����� � ����, � ����� ����� �� �������� � ������, ���������, ��� ������ ����������. ����� �����������... ������... ����� ������.\n����� ���� ������ ��... �-�-�...  ����� � ������ ������, ����� ������: '� ��� ������ ������, �� ���������� ���� ���� �������'. ��� � ��� � �������, ��� �� �� ��� ����� ����� ��� �����, ����� � ��� ���������� ���� ������ �������?";
			link.l1 = "������, � ���, �������, ������, �� ������, ���� �� ���������� ��������� � ������ ��� �������: ��� ���?!";
			link.l1.go = "PL_Q3_6";
		break;
		case "PL_Q3_6":
			dialog.text = "��� �������� ������� �������. ����������, ��� ����� �����, ��� ��� ���� �����. ��������� �����, ���� ���� �� ��� ���������� ����� ���� �������.";
			link.l1 = "���� ��, ������� ������� ����"+ GetSexPhrase("","�") +" �������. �����, �������, ������.";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "11");
			pchar.questTemp.piratesLine = "KillLoy_toTavernAgain";
			//����� �������� ����� � �������
			sld = GetCharacter(NPC_GenerateCharacter("CapGoodly", "officer_9", "man", "man", 20, PIRATE, -1, true, "quest"));
			sld.name = "�������";
			sld.lastname = "�����";
			sld.rank = 20;
			sld.city = "Pirates";
			sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
			sld.dialog.currentnode   = "CapGoodly";
			sld.greeting = "Gr_EvilPirate";
			LAi_SetSitType(sld);
			LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
            FreeSitLocator("Roseau_tavern", "sit10");
         	ChangeCharacterAddressGroup(sld, "Roseau_tavern", "sit", "sit9");
		break;

		case "PL_Q3_SW1":
			dialog.text = "�����, �����, ���� ��������. �� ���������, ����� �� �������� ���������.\n��������� �������. ���������� � ������� ����! ����"+ GetSexPhrase("","��") +" �������.";
			link.l1 = "��� �� � ����"+ GetSexPhrase("","��") +"...";
			link.l1.go = "exit";
		break;
		case "PL_Q3_SW2":
			dialog.text = "����! � ��� � ����... � ���?";
			link.l1 = "�� ������, �������....";
			link.l1.go = "PL_Q3_SW3";
		break;
		case "PL_Q3_SW3":
			dialog.text = "�� ��, ��� �����.";
			link.l1 = "�� �� ��������� ��, ��� ���������...";
			link.l1.go = "exit";
		break;

		//���� ��� �������-����

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "������ ��� �� ����� �� ����� ������ ����� �����, ��� ���� ���� ��������, ����� �� ����� �������, � � ��� ������������ ������!!!";
		link.l1 = "��, ����� ��� �� ��� ��� �����?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "���, �� ��� ��� ������, ���� ��� � �����... ���, ����� �� �������.";
		link.l1 = "�������. �, ��� �� ������� � ������� ����������?";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "������ �����, ����� � ��� ������� �����, �� � ���� ��� ��������� ����, �� � ��� ������ ���������, ������ � ��� � ������ ��������� ���� � �� ������ - �������. ����� ��� ������, ������ � ���� �� �������������. ��� ���!!!";
		link.l1 = "������ ������ ��������������� �� �������?";
		link.l1.go = "KillworkRoseauCharlotte_3";
  		break;

                                      case "KillworkRoseauCharlotte_3":
		dialog.text = "���, �� � ��� � ����� �� ��� � ��� �����, ��� ������ ��� ��� �������, �-�! ��� ����, � �� ���� ��� ��� �������� ��������, ����, ��� � ��� ��� � �����, ����� ����� ����� � � �������� ����������� ����� ����� ����� � ��!";
		link.l1 = "�������, �����.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 7) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

		
		// �������
		case "FDM":
			dialog.text = "�-�, '�������-�������'! ����� �������� ������ ������ ����������� �����. ��� ����� �������� ��� ������� �������� - ������ ��� ���! ������� � ����� �������, ����� ��� ����� ���� ����� �� ���������... ��� ��� �� ������ � ��� �������?";
			if (!CheckAttribute(npchar, "quest.FDM_cabin"))
			{
				link.l1 = "��, ��� �� ��� �������� ���� ��������� �������� � ����� ���� ����������� - ��� ���� ��� ��� ����������. � ��� ���������� ��������� ����� ���� �������� - ��� �� ��������� �������, ��� ��������� �������� � ��������. �� ������� ����� ����� - ������ � ���� �������������. ���� ���������� ��������� �������� - ����� � ����� ���������, �� ������ ���������. ����������, ������?";
				link.l1.go = "FDM_cabin";
			}
			if (!CheckAttribute(npchar, "quest.FDM_sails"))
			{
				link.l2 = "������� ��� ������� �������, ��� ��������� � ���� ������ �������. ����� ��� ����� �� ���� ������� ��������, �� ��� - ������ �������������. ���� ���������� ����� ������, ��� �� ���� ��������. �������, ������?";
				link.l2.go = "FDM_sails";
			}
		break;
		
		case "FDM_cabin":
			dialog.text = "������ �� �� �������? ��������, �������, ���, �� ��������. ������ � ��� ��������, ��� ��� ���� ���� ����������� ��� ���������� ��������� �� ������ ���� �������� ��������. ��� ������� ����������� �����. ��� ���������?";
			link.l1 = "������� ������� �����, ��� �� �������� ��������! ����� ��� �� ������� �������...";
			link.l1.go = "FDM_cabin_m";
			link.l2 = "�� ���� ������ � �����������. ������ �����������.";
			link.l2.go = "FDM_cabin_s";
		break;
		
		case "FDM_cabin_m":
			dialog.text = "����� ������. ������ ������ ��������� � ��������� - � �� ���� ���� �� ����� ������.";
			link.l1 = "������������.";
			link.l1.go = "FDM_cabin_m1";
			link.l2 = "������ ���������? ������� ������ ��������? ���, �, �������, ��� �������, ����� �� ��� ����� ����� ��������...";
			link.l2.go = "exit";
		break;
		
		case "FDM_cabin_s":
			dialog.text = "����� ������. ������ ���� ��������� � ��������� - � �� ���� ���� �� ����� ������.";
			link.l1 = "������������.";
			link.l1.go = "FDM_cabin_s1";
			link.l2 = "���� ���������? ������ ������ ��������? ���, �, �������, ��� �������, ����� �� ��� ����� ����� ��������...";
			link.l2.go = "exit";
		break;
		
		case "FDM_cabin_m1":
			iTemp = GetCharacterItem(pchar, "Chest");
			npchar.quest.FDM_cabin = 10;
			npchar.quest.FDM_cabin.type = "Cabin_Huge";
			dialog.text = "��� � ������. ��� ������.";
			if (iTemp > 0)
			{
				link.l1 = "� ���� ���� � ����� ��������... ���, ���������... ���, "+FindRussianQtyString(iTemp)+".";
				link.l1.go = "FDM_cabin_pay";
			}
			else
			{
				link.l1 = "����� ���������� ������� � ��������.";
				link.l1.go = "FDM_cabin_wait";
			}
		break;
		
		case "FDM_cabin_s1":
			iTemp = GetCharacterItem(pchar, "Chest");
			npchar.quest.FDM_cabin = 7;
			npchar.quest.FDM_cabin.type = "Cabin";
			dialog.text = "��� � ������. ��� ������.";
			if (iTemp > 0)
			{
				link.l1 = "� ���� ���� � ����� ��������... ���, ���������... ���, "+FindRussianQtyString(iTemp)+".";
				link.l1.go = "FDM_cabin_pay";
			}
			else
			{
				link.l1 = "����� ���������� ������� � ��������.";
				link.l1.go = "FDM_cabin_wait";
			}
		break;
		
		case "FDM_cabin_wait":
			DialogExit();
			npchar.quest.FDM_full = "cabin";
		break;
		
		case "FDM_cabin_pay":
			iTemp = GetCharacterItem(pchar, "Chest");
			amount = sti(npchar.quest.FDM_cabin)-iTemp;
			Log_Info("�� �������� ������� ����� �������");
			PlaySound("interface\important_item.wav");
			if (amount <= 0) // �� ������
			{
				RemoveItems(pchar, "chest", sti(npchar.quest.FDM_cabin));
				dialog.text = "���, ��� ����� ���� �������� ��������� - "+FindRussianQtyString(sti(npchar.quest.FDM_cabin))+", �� �������� - "+FindRussianQtyString(iTemp)+". ����, ������ � ������� �� �������. ������ � ��������� � ������. � �� ���� ��������� � �� ������������ - �� ����� ������� � ������ ����.";
				link.l1 = "������...";
				link.l1.go = "FDM_cabin_do";
			}
			else
			{
				RemoveItems(pchar, "chest", iTemp);
				dialog.text = "���, ��� ����� ���� �������� ��������� - "+FindRussianQtyString(sti(npchar.quest.FDM_cabin))+", �� �������� - "+FindRussianQtyString(iTemp)+". ������, ��� �������� ������� ��� "+FindRussianQtyString(amount)+".";
				link.l1 = "������, ������.";
				link.l1.go = "FDM_cabin_wait";
				npchar.quest.FDM_cabin = amount;
			}
		break;
		
		case "FDM_cabin_do":
			DialogExit();
			SetLaunchFrameFormParam("������ 5 ����..."+ NewStr() +"������ ���� �������� ������", "", 0, 5);
			WaitDate("", 0, 0, 5, 0, 10); //������ �����
			LaunchFrameForm();
			RefreshLandTime();
			RecalculateJumpTable();
			Whr_UpdateWeather();
			shTo = &RealShips[sti(Pchar.Ship.Type)];
			shTo.CabinType = npchar.quest.FDM_cabin.type;
			if (CheckAttribute(npchar, "quest.FDM_sails")) npchar.quest.FDM_full = "done";
			else DeleteAttribute(npchar, "quest.FDM_full");
		break;
		
		case "FDM_sails":
			dialog.text = "�������, ������ �� �� �������! ���-���... ��� ������, ��� ���� ��������� �������� ��� ������ - ��������� ������, ��������� ���������, ���������� � ����������. ������� ������� � ��� �����������, ��� ��� �� ��������� � �� ������ � ������� ��� ����� ����. ����������?";
			if (sti(Pchar.money) >= 100000)
			{
				link.l1 = "����� ����� ���� �������? �������, ����������!";
				link.l1.go = "FDM_sails_do";
			}
			link.l2 = "��. �������, ��� ���� ��� ��������...";
			link.l2.go = "exit";
		break;
		
		case "FDM_sails_do":
			AddMoneyToCharacter(pchar, -100000);
			dialog.text = "��� � ������. ������� �� ��������� - ������ � ��������� � ������. � �� ���� ��������� ���� �������� � �� ������������ - �� ����� ������� � ������ ����.";
			link.l1 = "������...";
			link.l1.go = "FDM_sails_done";
		break;
		
		case "FDM_sails_done":
			DialogExit();
			SetLaunchFrameFormParam("������ 2 ���..."+ NewStr() +"������ ���� �������� ������", "", 0, 5);
			WaitDate("", 0, 0, 2, 0, 10); //������ �����
			LaunchFrameForm();
			RefreshLandTime();
			RecalculateJumpTable();
			Whr_UpdateWeather();
			SetShipSailsFromFile(pchar, "ships/parus_silk.tga");
			SetSailsColor(pchar, 0);//����� ��������� �����
			npchar.quest.FDM_sails = "true";
			if (CheckAttribute(npchar, "quest.FDM_cabin")) npchar.quest.FDM_full = "done";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

void checkMatherial_repair(ref Pchar, ref NPChar, int good, int goodType)
{
	int amount;
	string Matherial = "Matherial" + goodType;
	amount = GetSquadronGoods(Pchar, good) - sti(NPChar.Repair.(Matherial));
	
	if (amount < 0)
    {
		amount = amount + sti(NPChar.Repair.(Matherial));
    }
    else
    {
		amount = sti(NPChar.Repair.(Matherial));
    }
    RemoveCharacterGoods(Pchar, good, amount);
    NPChar.Repair.(Matherial) = sti(NPChar.Repair.(Matherial)) - amount;
}

int GetMaterialQtyRepair( ref _chr, int MaterialNum )
{
	if ( sti(_chr.Ship.Type) == SHIP_NOTUSED) return 0;
	
	int   	shipCurHP   = sti(RealShips[sti(_chr.Ship.Type)].HP);
	int   	shipBaseHP	= sti(RealShips[sti(_chr.Ship.Type)].BaseHP);	
	int   	shipClass   = sti(RealShips[sti(_chr.Ship.Type)].Class);
	int     shipWeight  = CWT2Tonnes(sti(RealShips[sti(_chr.Ship.Type)].Weight));
	int     HPPrice     = shipWeight * (1.2 - makefloat(shipCurHP)/makefloat(shipBaseHP));
	int     modifier    = (2 * MOD_SKILL_ENEMY_RATE) + sti(RealShips[sti(_chr.Ship.Type)].MinCrew)/2 + 1;	

	float   fQuest 	= 1.0;
	if(CheckAttribute(&RealShips[sti(_chr.Ship.Type)], "QuestShip")) 
	{
		fQuest  = 1.3;
		HPPrice = HPPrice * 2;
	}					
	
	int     Matherial1 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial2 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial3 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial4 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
		
	if(MaterialNum == 0) return HPPrice;	
	if(MaterialNum == 1) return Matherial1;
	if(MaterialNum == 2) return Matherial2;
	if(MaterialNum == 3) return Matherial3;
	if(MaterialNum == 4) return Matherial4;
	
	return 0;
}

