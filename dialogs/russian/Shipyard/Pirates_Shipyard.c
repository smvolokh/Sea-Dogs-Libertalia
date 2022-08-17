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
		int   	cannonMax     = sti(RealShips[sti(Pchar.Ship.Type)].MaxCaliber);
		int 	iCaliber;
	}	
 
	switch (Dialog.CurrentNode)
	{		
		// -----------------------------------������ ������ - ������ �������
		case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
// �������� ��������� �������, ������ ���� ���
			if(NPChar.quest.meeting == "0")
			{
				Dialog.Text = "���... ��� �� �������� ������... ���� ����� " + GetFullName(npchar) + ", �, ������ ���� ������, � ������ ������� �� ���� ������� ����� ��������. �� ��� ������� ������ ����� ���� � ���...";
				Link.l1 = pcharrepphrase("������ ����, ������ ����������� ��������� ��� �� �������. ��� ��� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.",
					"��� �� �������, ��� ��������, ���������. ���� ����� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.");
				Link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}
			else // �����, ���� �� ������� ����� ����� ��  "First time"
			{
				dialog.text = "�, ��� ����� ��, ����� �� ������ ����������... ���... ���.";
				link.l1 = pcharrepphrase("�� �����, ��� ����� �. �� ������� ��������� � �����, ���� �� �� ������ ���� ����.",
					"� ��� ������� ������, � ������, ���� ���������, ������� �������� � ����� ���������� ��������.");
				link.l1.go = "node_3";
				link.l2 = pcharrepphrase("�� ������� ���� ����� ����������. ��������.",
					"��� ����, ��������, ��� �����������"+ GetSexPhrase("","�") +".");
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "Master_Ship";
			Dialog.CurrentNode = "Master_Ship";
		break;
		
		case "Master_Ship":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
		//Jason ----------------------------------- ��������� ������ ------------------------------------------
			if (CheckAttribute(npchar, "quest.sextant") && CheckAttribute(pchar, "questTemp.AlexClock") && pchar.location == "Pirates_shipyard" && !CheckAttribute(npchar, "quest.clock"))
			{
				dialog.text = "�-�, ������� "+GetFullName(pchar)+"! ��� ������, ��� �� �� ��� �����!";
				Link.l1 = "������, ������, � ��� ��� ����-�� �����������, �� �����. ������ �� ���� ����� �������.";
				Link.l1.go = "clock_begin";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.AlexClock") && pchar.questTemp.AlexClock == "clock" && pchar.location == "Pirates_shipyard")
			{
				dialog.text = "����, �� ��������� �� � ������� ������, �������! � ��� ����� �... �������?";
				Link.l1 = "����. � �� �������� - � ��� ����.";
				Link.l1.go = "clock_complete";
				break;
			}
		//<-- ��������� ������
			dialog.text = "�, ��� ����� ��, ����� �� ������ ����������... ���... ���.";
			link.l1 = pcharrepphrase("�� �����, ��� ����� �. �� ������� ��������� � �����, ���� �� �� ������ ���� ����.",
	            "� ��� ������� ������, � ������, ���� ���������, ������� �������� � ����� ���������� ��������.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("�� ������� ���� ����� ����������. ��������.",
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
			dialog.text = "���, ���... �� ���� ������� �����. ��� ��� ����� �� ���� �����, " + GetAddress_Form(NPChar) + "? ";
			link.l1 = pcharrepphrase("��� ���� ��������������� �������� �����.","� ���� ��������������� �������� ����� �����.");
			link.l1.go = "shipyard_dlg";
            Link.l2 = "� ���� ������.";
			Link.l2.go = "quests"; //(��������� � ���� ������)
			
			 if (cannonMax < 42 && !CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.Cannon"))	 
                    {
                        Link.l41 = "� ���� ��������� ������ ������ �� ���� �����.";
    			        Link.l41.go = "dogovor";  // if (sti(RealShips[sti(pchar.Ship.Type)].Class) >= 6) ��� ������ �� �������
    			    }
			
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
		// �������
		case "dogovor":
		if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 6)
		{
          dialog.text = "��������, �� ������� � �� ���������. �����!";
           link.l1 = "����� �������� �� ������������.";		  
		   link.l1.go = "exit";
		} 
		if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 5)
		{
          dialog.text = "������������ ���������� �����������, ����� � ���������! ���..���..";
           link.l1 = "��, ����...";		  
		   link.l1.go = "exit";
		} 
		if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 4)
		{
          dialog.text = "���������� ������� ������ �� ����� ������� ����� ������ ���� ������� ����. ������ ������.";
           link.l1 = "������������!";		  
		   link.l1.go = "oplata_4";                              // ������� �� ���� �������� � ������
		   link.l2 = "���, �� � ���� ��� ������� �����.";
		   link.l2.go = "exit";
		} 
		if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 3)
		{
          dialog.text = "���������� ������� ������ �� ����� ������� ����� ������ ��� �������� ����. ������ ������.";
           link.l1 = "������������!";		  
		   link.l1.go = "oplata_3";                              // ������� �� ���� �������� � ������
		   link.l2 = "���, �� � ���� ��� ������� �����.";
		   link.l2.go = "exit";
		}
        if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 2)
		{
          dialog.text = "���������� ������� ������ �� ����� ������� ����� ������ ��� �������� ����. ������ ������.";
           link.l1 = "������������!";		  
		   link.l1.go = "oplata_2";                              // ������� �� ���� �������� � ������
		   link.l2 = "���, �� � ���� ��� ������� �����.";
		   link.l2.go = "exit";
		} 
         if (sti(RealShips[sti(pchar.Ship.Type)].Class) == 1)
		{
          dialog.text = "���������� ������� ������ �� ����� ������� ����� ������ ������ �������� ����. ������ ������.";
           link.l1 = "������������!";		  
		   link.l1.go = "oplata_1";                              // ������� �� ���� �������� � ������
		   link.l2 = "���, �� � ���� ��� ������� �����.";
		   link.l2.go = "exit";
		} 		
		break;
		// ������ �� ���������� ������� 
		case "oplata_4":
		if (sti(Pchar.money) < 1000000)  // ���� ��� �����
			{
			   dialog.text = "��������, � ���� � ����� �� ���..��� ����� ��������, ����� � ����� ��������!";
               link.l1 = "��, ����! �������� ���� ���������..";
               link.l1.go = "exit";
               break;			   
			}
		       AddMoneyToCharacter(pchar, -1000000);
			   dialog.text = "��, ������ ����� ������ ��������, ����� � ���� ����������!";
               link.l1 = "��� � �����������!";
               link.l1.go = "ship_tunning_cannon_complite";
		break;	
        case "oplata_3":
		if (sti(Pchar.money) < 2000000)  // ���� ��� �����
			{
			   dialog.text = "��������, � ���� � ����� �� ���..��� ����� ��������, ����� � ����� ��������!";
               link.l1 = "��, ����! �������� ���� ���������..";
               link.l1.go = "exit";
               break;			   
			}
		       AddMoneyToCharacter(pchar, -2000000);
			   dialog.text = "��, ������ ����� ������ ��������, ����� � ���� ����������!";
               link.l1 = "��� � �����������!";
               link.l1.go = "ship_tunning_cannon_complite";
		break;	
        case "oplata_2":
		if (sti(Pchar.money) < 3000000)  // ���� ��� �����
			{
			   dialog.text = "��������, � ���� � ����� �� ���..��� ����� ��������, ����� � ����� ��������!";
               link.l1 = "��, ����! �������� ���� ���������..";
               link.l1.go = "exit";
               break;			   
			}
		       AddMoneyToCharacter(pchar, -3000000);
			   dialog.text = "��, ������ ����� ������ ��������, ����� � ���� ����������!";
               link.l1 = "��� � �����������!";
               link.l1.go = "ship_tunning_cannon_complite";
		break;
        case "oplata_1":
		if (sti(Pchar.money) < 4000000)  // ���� ��� �����
			{
			   dialog.text = "��������, � ���� � ����� �� ���..��� ����� ��������, ����� � ����� ��������!";
               link.l1 = "��, ����! �������� ���� ���������..";
               link.l1.go = "exit";
               break;			   
			}
		       AddMoneyToCharacter(pchar, -4000000);
			   dialog.text = "��, ������ ����� ������ ��������, ����� � ���� ����������!";
               link.l1 = "��� � �����������!";
               link.l1.go = "ship_tunning_cannon_complite";
		break;	   		
			   
		case "ship_tunning_cannon_complite":
		    AddTimeToCurrent(15, 30);
			LAi_Fade("", "");
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
			// ������� ������ ������
			iCaliber = sti(shTo.MaxCaliber);
			switch(iCaliber)
			{
				case 8:
					iCaliber = 0;
				break;
				case 12:
					iCaliber = 1;
				break;
				case 16:
					iCaliber = 2;	
				break;
				case 18:
					iCaliber = 3;
				break;
				case 20:
					iCaliber = 4;
				break;	
				case 24:
					iCaliber = 5;	
				break;
				case 32:
					iCaliber = 6;	
				break;
				case 36:
					iCaliber = 7;	
				break;
				case 42:
					iCaliber = 8;	
				break;
			}
			iCaliber = iCaliber + 1;
			if (iCaliber > 8) iCaliber = 8;
			switch(iCaliber)
			{
				case 0:
					iCaliber = 8;
				break;
				case 1:
					iCaliber = 12;
				break;
				case 2:
					iCaliber = 16;
				break;
				case 3:
					iCaliber = 18;
				break;
				case 4:
					iCaliber = 20;
				break;	
				case 5:
				    iCaliber = 24;
				break;
				case 6:
				    iCaliber = 32;
				break;
				case 7:
				    iCaliber = 36;
				break;
				case 8:
				    iCaliber = 42;
				break;
			}
			shTo.MaxCaliber = iCaliber;
			shTo.Tuning.Cannon = true;
			// finish <--
            NextDiag.TempNode = "Master_Ship";
			dialog.Text = "... ����� �� ���... ������ ������ ������ - �������� ����������.";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";
			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		case "shipyard_dlg":			
			if((shipBaseHP - shipCurHP > 0) && (shipClass < 6))
			{
				dialog.Text = "���� ���������� ������� ����������� ������ ������� ������ ������. ����� ���������� �� ����� ������� ���������� ������� - ����������� �� ���...";						
				Link.l1 = "������������! � ���� ��� ��� ���� ����� ��������, ��������� �������. ����� ���������, ��� ����� �������?";
				Link.l1.go = "ship_repair_start";		
			}
			else
			{
				dialog.Text = "�� � ���� �� �� ������? �� ���� �������...";
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
			if(RealShips[sti(Pchar.Ship.Type)].BaseType == SHIP_CURSED_FDM && !CheckAttribute(npchar, "quest.FDM_full"))
			{
					link.l50 = "� ���� ���������... ��������� �������. � �� ����� ������ � ��� ����������� ������� ���������.";
					link.l50.go = "FDM";
			}
			if(RealShips[sti(Pchar.Ship.Type)].BaseType == SHIP_CURSED_FDM && CheckAttribute(npchar, "quest.FDM_full") && npchar.quest.FDM_full == "cabin" && GetCharacterItem(pchar, "Chest") > 0)
			{
					link.l50 = "� ������ ��� �������� ��� ������������� �����.";
					link.l50.go = "FDM_cabin_pay";
			}
			link.l9 = pcharrepphrase("����, � ���� ���� ���� ���������� ���, �� ��������.", "��� ��� ����, ��������.");
			Link.l9.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_again":
			if((shipBaseHP - shipCurHP > 0) && (shipClass < 6))
			{
				dialog.Text = RandPhraseSimple("�... ��� ����� ��... ����� ������ ���� �������� ���������?",
				RandPhraseSimple("����������� ���������� �������. ���, ����� ��������� �����������?",
                                           "��... �� ������ ����� ���, �� ����� ������� ���������������.. ����� ������?"));
				Link.l1 = "��. ���� ����� ����. ����� ���������, ��� ����� �������?";
				Link.l1.go = "ship_repair_start";						   
			}
			else
			{
				dialog.Text = "�� � ��� � ���� ����� ���������? ��� ����� ��� �� ����� ...";
			}				
			link.l2 = "� ���� ������ ��������������� �������� �����.";
			link.l2.go = "shipyard";
			link.l3 = "��� ����� ������ �� �������.";
			link.l3.go = "Cannons";
			if(RealShips[sti(Pchar.Ship.Type)].BaseType != SHIP_CURSED_FDM)
			{
					link.l31 = "���� �������� ������� ��� �������.";
					link.l31.go = "SailsGerald";
			}
			if(RealShips[sti(Pchar.Ship.Type)].BaseType == SHIP_CURSED_FDM && !CheckAttribute(npchar, "quest.FDM_full"))
			{
					link.l50 = "� ���� ���������... ��������� �������. � �� ����� ������ � ��� ����������� ������� ���������.";
					link.l50.go = "FDM";
			}
			if(RealShips[sti(Pchar.Ship.Type)].BaseType == SHIP_CURSED_FDM && CheckAttribute(npchar, "quest.FDM_full") && npchar.quest.FDM_full == "cabin" && GetCharacterItem(pchar, "Chest") > 0)
			{
					link.l50 = "� ������ ��� �������� ��� ������������� �����.";
					link.l50.go = "FDM_cabin_pay";
			}
            Link.l4 = "� ���� ������.";
			Link.l4.go = "quests"; //(��������� � ���� ������)
			// -->
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l5 = "� �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ����� ����������.";
				link.l5.go = "LoanForAll";//(��������� � ���� ������)
			}
			Link.l9 = "���. ���� ���������� ��, ��� ����";
			Link.l9.go = "ship_tunning_not_now_2";
		break;
		
		case "ship_tunning_not_now_2":
			dialog.Text = "�� ��, � �������, ��� � �������! ������ �������! �������, ����� �������� � �� �������� ���� �� ��������.";
			Link.l1 = RandPhraseSimple("�������! ����� ��������.", "����, ������. ����� � ��� ��������.");
			Link.l1.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_start":
            if ( sti(Pchar.Ship.Type) == SHIP_NOTUSED || Pchar.location.from_sea != "Pirates_town")
            {
                dialog.Text = "�������-�� ���? ��� �� ��� ��� ������ ��������?!";
			    Link.l1 = "� �� ������... ��� ��� �... ���������";
			    Link.l1.go = "ship_tunning_not_now";
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
			if (!CheckAttribute(npchar, "Step_Door"))
			{
				link.l2 = "��������, � ���� ������, � ����� �������...";
				link.l2.go = "Step_Door_1";
			}

			if ((pchar.questTemp.different == "GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakAlexus"))
			{
				link.l1 = "���� ���������� ������.";
				link.l1.go = "Al_ShipLetters_1";// ���������  "��������� ���������"
				pchar.questTemp.different.GiveShipLetters.speakAlexus = true;
			}
			if(CheckAttribute(pchar, "questTemp.AlexClock") && pchar.questTemp.AlexClock == "go") // 280912
			{
				link.l1 = "� �� ������ ���������� ��� �������.";
				link.l1.go = "clock";
			}
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "��������, "+npchar.name+", �� �� ����� � ��������� ����� �� ���� ������ ������ ������?";
				link.l1.go = "tieyasal";
			}

			if (pchar.questTemp.BlueBird == "toSeekBermudes") //���� "������ ��������"
			{
				link.l1 = "����������, ��� ����� ����� ���� ���� ���������� ������ ����������...";
				link.l1.go = "BlueBird_1";
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
		
//*************************** ���� "������ ��������" ***************************
		case "BlueBird_1":
			dialog.text = "��� �� ���. ��������, � ������� ���� ������ �� ������� ���� �� �� �����.";
			link.l1 = "�-�, �� �������. ������ ���������� ����������� ��� � ���. �� �������� �� ����� ��� ���������� ������ � �����?";
			link.l1.go = "BlueBird_2";
		break;
		case "BlueBird_2":
			dialog.text = "��-��, ���, �������, ���� ���������� � ��������. �������� ����, ��� ����� ������� ���� ����, ����� �� ���� ������� ����� �� ���� ����, ����� ����� ������ ����� ������� � �������� �������� ��� �� ����.";
			link.l1 = "��, � ���� ���-�� �� �����, ����� �� ���� ������ � ������?";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "� �� �������, ��� ���� ���-�� ������ ������� ����� �� ���� ����� � �����, ����� ����� �� �������?";
			link.l1 = "��, ��, �����... ��� ������, ����� ������ �� �������� ����� ���� �����?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "���, ����� ������ �� ��������, ������ ���� �������"+ GetSexPhrase("��","��") +".";
			link.l1 = "�� ��� ��, �������� ��� �������!";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "5");
			pchar.questTemp.BlueBird = "toCavern";
			pchar.quest.BlueBird_inCavern.win_condition.l1 = "locator";
			pchar.quest.BlueBird_inCavern.win_condition.l1.location = "Bermudes_Cavern";
			pchar.quest.BlueBird_inCavern.win_condition.l1.locator_group = "quest";
			pchar.quest.BlueBird_inCavern.win_condition.l1.locator = "BlueBird";
			pchar.quest.BlueBird_inCavern.function = "BlueBird_inCavern";
			LAi_LocationDisableMonstersGen("Bermudes_Cavern", true); //�������� �� ��������
			LAi_LocationDisableOfficersGen("Bermudes_Cavern", true); //�������� �� �������
		break;	

//*************************** ���������� ����� ***************************
 		case "Step_Door_1":
			dialog.text = "��� �����. ����� ����� ������, ���� ���� ��������� ��� 20000 �����. �� ��������� - �� ������, � ���� ����� �� ��������� ����. �� � ���� ��� ������� �� ������� - �� � �����...";
			if(sti(pchar.money) >= 20000)
			{
    			link.l1 = "��� ���� ������, ��������.";
    			link.l1.go = "Step_Door_2";
            }
            else
            {
    			link.l1 = "��� � ���� ����� �����.";
    			link.l1.go = "Step_Door_3";
            }
            link.l2 = "��� ���! ������� �� �����-�� �����.";
    		link.l2.go = "exit";
		break;
		
 		case "Step_Door_2":
			npchar.Step_Door = true; // fix
			dialog.text = "�������, ����� �������. � �� ���������!";
			link.l1 = "�� ���� �� ���, ������� ����, " + npchar.name + "...";
			link.l1.go = "exit";
			LocatorReloadEnterDisable("Pirates_Shipyard", "reload2", false);
            AddMoneyToCharacter(pchar, -20000);
			pchar.quest.CloseBermudesDungeonDoor.win_condition.l1 = "MapEnter";
            pchar.quest.CloseBermudesDungeonDoor.win_condition = "CloseBermudesDungeonDoor";
		break;
		
 		case "Step_Door_3":
			dialog.text = "�� ��� ����� �����, ����� � �������. � ��� � �� ���������� - ����������...";
			link.l1 = "����, �� ���� ������ ������� ���!";
			link.l1.go = "exit";
		break;
		
	// ------------------------------------------- ��������� ������ ----------------------------------------------
		case "clock_begin":
			dialog.text = "��-��, �� ������ ����� ������ � �������... ��� ������������� ����� ���� ������, �������.";
			link.l1 = "������������, ������, ��� � ��� ��� ���������.";
			link.l1.go = "clock_begin_1";
		break;
		
		case "clock_begin_1":
			sTotalTemp = "������ ������";
			if (pchar.questTemp.Alex.Clock == "terrax") sTotalTemp = "������ ������";
			dialog.text = "��� ����� ����� ���������� ��������, "+sTotalTemp+", ������� � ���� �������, ������. � �������� ��������� ������: ������ ���������� ��������� � ��������� � ������� �������� � ��������������, ���� ������ ����������� ���������� �������. � �������, ���-���� - '������������' �������, �� ��� ���������� ��������� ������ ����� ������ ���������. ��, ��������, ������� � �����\n��� ����� ������ � ����� ��� �������� ������� � ��������� �������, ����������� ���� ��� �������, �������������� � ��������� ��������� �����, ����������� ��������� ������...";
			link.l1 = "��� ������� �� ���� ����� ��������. ��� ����������, ��� "+sTotalTemp+" ������ � ��� �� ��� ������?";
			link.l1.go = "clock_begin_2";
		break;
		
		case "clock_begin_2":
			dialog.text = "�� �-�� ������... ������ � ������ ������ ����� ������ ��� �� �������, �� ����������� ��������� ��� ���������. �� �� ������ �����, ����� ��� ��������. � ��� ��� ��������� ������ � ����������� ���������������� � ����� �� �����.";
			link.l1 = "� ��, ��������, ����������� ��� ������������ � ������� ���������� ��� �������?";
			link.l1.go = "clock_begin_3";
		break;
		
		case "clock_begin_3":
			dialog.text = "�� ��. �� �� ������� ���� ������ �����. "+sTotalTemp+" ��� �������, ��� ������ ��� ������, � ������� ���������� �������� � ���... ��� � � �������: ��� �� ��� ����, ��, ���� �����, ���������� ��� ������? � ������ � ���: �� �� ���������, � ����� � ������� ���������? ���� �������� ����� �������, "+sTotalTemp+" �� �������� �� ������.";
			link.l1 = "� ����� �������, ������, �� � ������ ����� �� ������, ��� "+sTotalTemp+". �����, ��� ���� ���������� ����� ������ ����� ��������. ��� ��� ����� �� ��������� ����-������ ���.";
			link.l1.go = "clock_exit";
			link.l2 = "��, ��� �������� ������� "+sTotalTemp+" - �� �������, �������� ������. ���-���� �� � ������ � ��� ������, � ������� ����� ��������. ������� ��� ����� ����������?";
			link.l2.go = "clock_begin_4";
		break;
		
		case "clock_exit":
			dialog.text = "����, ����� ����. � �������� �� ���. ��, ��� ���������, �� '���' - � ���� ���...";
			link.l1 = "...";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.AlexClock");
		break;
		
		case "clock_begin_4":
			dialog.text = "��� �� ������� 200 ������ �������, 250 �������� ����, 220 ������� ������������ ����� � 180 ���� ��������� �������. ��� �������, �������� ��� ��� ��� ������ �� ������? ������ � ������ �� ����� �����.";
			link.l1 = "�� ������� ���� - ���������. ��� ������ ������?";
			link.l1.go = "clock_begin_5";
		break;
		
		case "clock_begin_5":
			dialog.text = "�������� ������: ������ - 35 �������� �� �����, ����� - 12 �������� �� �������, ���� - 24 ������� �� �����, ������ - 13 �������� �� �����. � ���� �� ��� ��� ���������, �������� �������� ������� �� ����.";
			link.l1 = "�����, ���������?";
			link.l1.go = "clock_begin_6";
		break;
		
		case "clock_begin_6":
			dialog.text = "� �� ������� ���������. �� ������: ������ ��������, � ������ ����� �� �������, �� � �� ���� ����, ���. �������, ��� ��������� ������� ��������� ��� ������� � ����� ����������.";
			link.l1 = "��, �� ������ �� ��, ������! �����, ������������.";
			link.l1.go = "clock_begin_7";
		break;
		
		case "clock_begin_7":
			dialog.text = "� ����� ���. ���� ����� ��� � �����������.";
			link.l1 = "�������, ��� �� ������ ������� ����� �������...";
			link.l1.go = "clock_begin_8";
		break;
		
		case "clock_begin_8":
			DialogExit();
			pchar.questTemp.AlexClock = "go";
			npchar.quest.clock = "true";
			SetFunctionTimerCondition("AlexClock_Over", 0, 0, 122, false); // ������
			AddQuestRecord("alex_clock", "1");
			// ���������� ����������
			pchar.questTemp.AlexClock.Sandal = 200;
			pchar.questTemp.AlexClock.Oil = 250;
			pchar.questTemp.AlexClock.Shipsilk = 220;
			pchar.questTemp.AlexClock.Ropes = 180;
		break;
		
		case "clock":
			dialog.text = "����� ������! ��� �� �������� ��� �������?";
			if (GetSquadronGoods(pchar, GOOD_SANDAL) > 0 && !CheckAttribute(npchar, "quest.sandal"))
			{
				iSan = GetSquadronGoods(pchar, GOOD_SANDAL);
				link.l1 = "������, � ���������� "+FindRussianQtyString(iSan)+".";
				link.l1.go = "sandal";
			}
			if (GetSquadronGoods(pchar, GOOD_OIL) > 0 && !CheckAttribute(npchar, "quest.oil"))
			{
				iOil = GetSquadronGoods(pchar, GOOD_OIL);
				link.l2 = "�����, � ���������� "+FindRussianQtyString(iOil)+".";
				link.l2.go = "oil";
			}
			if (GetSquadronGoods(pchar, GOOD_SHIPSILK) > 0 && !CheckAttribute(npchar, "quest.shipsilk"))
			{
				iSil = GetSquadronGoods(pchar, GOOD_SHIPSILK);
				link.l3 = "����������� ����, � ���������� "+FindRussianQtyString(iSil)+".";
				link.l3.go = "shipsilk";
			}
			if (GetSquadronGoods(pchar, GOOD_ROPES) > 0 && !CheckAttribute(npchar, "quest.ropes"))
			{
				iRop = GetSquadronGoods(pchar, GOOD_ROPES);
				link.l4 = "��������� ������, � ���������� "+FindRussianQtyString(iRop)+".";
				link.l4.go = "ropes";
			}
			link.l5 = "���� ������. ������ ����� ���������, ��� ������� ��� � ����.";
			link.l5.go = "exit";
		break;
		
		case "clock_1":
			if (CheckAttribute(npchar, "quest.sandal") && CheckAttribute(npchar, "quest.oil") && CheckAttribute(npchar, "quest.shipsilk") && CheckAttribute(npchar, "quest.ropes")) // ��� ������
			{
				dialog.text = "�����������! ��� ��������� � � ������ ���������� - � ����. �������� ��� ������� �� ������, �������. ��, �����, ���� ��������.";
				link.l1 = "�� ������ ����������, ������. � ���� ������� ������ �������: � ����� �����, � ������������ �������. � ������ �������� � ��������� � ����� ������������ ������, ������� �� ��� �������.";
				link.l1.go = "clock_2";
			}
			else
			{
				dialog.text = "��� ���-������ ���� ���������, �������?";
				link.l1 = "���, ���� ��� ���. ��������.";
				link.l1.go = "exit";
				link.l2 = "��, � ���� ���� ��� ���-���...";
				link.l2.go = "clock";
			}
		break;
		
		case "sandal": // ������
			amount = sti(pchar.questTemp.AlexClock.Sandal);
			iTemp = amount-iSan;
			if (iTemp > 0) // ��� �� ��� ������
			{
				iSum = 35*iSan;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �������. �� �������� "+FindRussianQtyString(iSan)+". ������, �������� ������� "+FindRussianQtyString(iTemp)+". ����, ������ �� ���� � 35 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������! ����� ����� � ��� ���������.";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_SANDAL, iSan);
				pchar.questTemp.AlexClock.Sandal = iTemp; // ������� �������� �������
				AddQuestRecord("alex_clock", "2");
				AddQuestUserData("alex_clock", "sGood", "�������");
				AddQuestUserData("alex_clock", "sQty", FindRussianQtyString(iTemp));
			}
			else
			{
				iSum = 35*amount;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �������. �� �������� "+FindRussianQtyString(iSan)+". ������, ������ � �������� �� � ���� �������! ����, ������ �� ���� � 35 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������!";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_SANDAL, amount);
				npchar.quest.sandal = "true";
				AddQuestRecord("alex_clock", "3");
				AddQuestUserData("alex_clock", "sGood", "�������");
			}
			TakeNItems(pchar, "gold_dublon", iSum);
			Log_Info("�� �������� "+FindRussianDublonString(iSum)+"");
		break;
		
		case "oil": // �����
			amount = sti(pchar.questTemp.AlexClock.Oil);
			iTemp = amount-iOil;
			if (iTemp > 0) // ��� �� ��� ������
			{
				iSum = 12*iOil;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" ����. �� �������� "+FindRussianQtyString(iOil)+". ������, �������� ������� "+FindRussianQtyString(iTemp)+". ����, ������ �� ���� � 12 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������! ����� ����� � ��� ���������.";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_OIL, iOil);
				pchar.questTemp.AlexClock.Oil = iTemp; // ������� �������� �������
				AddQuestRecord("alex_clock", "2");
				AddQuestUserData("alex_clock", "sGood", "����");
				AddQuestUserData("alex_clock", "sQty", FindRussianQtyString(iTemp));
			}
			else
			{
				iSum = 12*amount;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" ����. �� �������� "+FindRussianQtyString(iOil)+". ������, ������ �� ������� �� � ���� �������! ����, ������ �� ���� � 12 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������!";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_OIL, amount);
				npchar.quest.oil = "true";
				AddQuestRecord("alex_clock", "3");
				AddQuestUserData("alex_clock", "sGood", "����");
			}
			TakeNItems(pchar, "gold_dublon", iSum);
			Log_Info("�� �������� "+FindRussianDublonString(iSum)+"");
		break;
		
		case "shipsilk": // ����
			amount = sti(pchar.questTemp.AlexClock.Shipsilk);
			iTemp = amount-iSil;
			if (iTemp > 0) // ��� �� ��� ������
			{
				iSum = 24*iSil;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �����. �� �������� "+FindRussianQtyString(iSil)+". ������, �������� ������� "+FindRussianQtyString(iTemp)+". ����, ������ �� ���� � 24 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������! ����� ����� � ��� ���������.";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_SHIPSILK, iSil);
				pchar.questTemp.AlexClock.Shipsilk = iTemp; // ������� �������� �������
				AddQuestRecord("alex_clock", "2");
				AddQuestUserData("alex_clock", "sGood", "�����");
				AddQuestUserData("alex_clock", "sQty", FindRussianQtyString(iTemp));
			}
			else
			{
				iSum = 24*amount;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �����. �� �������� "+FindRussianQtyString(iSil)+". ������, ������ � ������ �� � ���� �������! ����, ������ �� ���� � 24 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������!";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_SHIPSILK, amount);
				npchar.quest.shipsilk = "true";
				AddQuestRecord("alex_clock", "3");
				AddQuestUserData("alex_clock", "sGood", "�����");
			}
			TakeNItems(pchar, "gold_dublon", iSum);
			Log_Info("�� �������� "+FindRussianDublonString(iSum)+"");
		break;
		
		case "ropes": // ������
			amount = sti(pchar.questTemp.AlexClock.Ropes);
			iTemp = amount-iRop;
			if (iTemp > 0) // ��� �� ��� ������
			{
				iSum = 13*iRop;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �������. �� �������� "+FindRussianQtyString(iRop)+". ������, �������� ������� "+FindRussianQtyString(iTemp)+". ����, ������ �� ���� � 13 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������! ����� ����� � ��� ���������.";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_ROPES, iRop);
				pchar.questTemp.AlexClock.Ropes = iTemp; // ������� �������� �������
				AddQuestRecord("alex_clock", "2");
				AddQuestUserData("alex_clock", "sGood", "�������");
				AddQuestUserData("alex_clock", "sQty", FindRussianQtyString(iTemp));
			}
			else
			{
				iSum = 13*amount;
				dialog.text = "���-���. ��� ��� ���������� "+FindRussianQtyString(amount)+" �������. �� �������� "+FindRussianQtyString(iRop)+". ������, ������ � �������� �� � ���� �������! ����, ������ �� ���� � 13 �������, ���� �������������� ���������� "+FindRussianDublonString(iSum)+". �������� ��������.";
				link.l1 = "�������!";
				link.l1.go = "clock_1";
				RemoveCharacterGoods(pchar, GOOD_ROPES, amount);
				npchar.quest.ropes = "true";
				AddQuestRecord("alex_clock", "3");
				AddQuestUserData("alex_clock", "sGood", "�������");
			}
			TakeNItems(pchar, "gold_dublon", iSum);
			Log_Info("�� �������� "+FindRussianDublonString(iSum)+"");
		break;
		
		case "clock_2":
			dialog.text = "��-��... � ���� ������, �������. �-�-�...";
			link.l1 = "��� �����, ������? � ��� ����� ����������� ���. ���-�� �� ���? �����-�� ��������?";
			link.l1.go = "clock_3";
		break;
		
		case "clock_3":
			dialog.text = "������ ���. ��������. � ��������� ��� ������ �������. ���� �� ������ ���� ��������� ��������������, �������� �� �� ��� ������...";
			link.l1 = "����, ����, � ����� �������� ������ ��� �����������. �� ��� ��� - ���� ������, ��� ����� ������ ��� ����� �������� ������� �����? ��������� ��������, ��� �� �������������?";
			link.l1.go = "clock_4";
		break;
		
		case "clock_4":
			dialog.text = "��� ���, � ����� ����� - �����. ��� ����� �������� � ������ ����������. ��� ���, � ���� ����������, � ����� �� ��������, � ����� ���� ������������� ���� � ����������, ������� ���� �� ����, ����� ���� �������� ��� ����� �������� � ��� ��������� �������, � � �������� ���...";
			link.l1 = "����� �������? � ��� ��?";
			link.l1.go = "clock_5";
		break;
		
		case "clock_5":
			dialog.text = "��, ��������, �������, � ������� ������ ����������. �������� - �� �������, ������� �������. ��������... �� �������. ����� ��, ��� ��� ���� � ����� �������� ����� ������ � ������� � ����������, � �� ���� ��� ������� ���� ������� �����-�� ������ ��������. ��� �� �� �����, �� � ���� ������\n�����, ����������, ���������� � ��������. �������������, ������� ���-�� �������, ��� ����� ����� ����������. ����, �� ���, ��� ������� ������ �� �������, �� � � ���� �������� �����, ���������? � ��� ����� ����, ���...";
			link.l1 = "����. ��������� ���� ����� - �����, ������ �������� ������.";
			link.l1.go = "clock_6";
		break;
		
		case "clock_6":
			dialog.text = "��� ��� ������ - ����� ������? � ��������? ��� �� �������?";
			link.l1 = "������ ����, ������ ����, ������. ��������� ��� �����, � ��������� ������������ ���. � ����� ������� �� ������� ���� ����?";
			link.l1.go = "clock_7";
		break;
		
		case "clock_7":
			dialog.text = "����� �� �������� ���� ����� ���� ������ ���������� �����. �� ���� �� ����, � �������� �����, ����� ��������� ��������. � ������ � ���� �����, ��� ��� ������ �� ��� ���������� ������ ��������� � ���� ���� ������� ����, ���� ���� � ��������. ���, �������� ����.";
			link.l1 = "��� ������, ��� �� ��������� ����� �����������������. ����� ���� ����� � ������ �� �������.";
			link.l1.go = "clock_8";
		break;
		
		case "clock_8":
			DialogExit();
			GiveItem2Character(pchar, "key3"); 
			bDisableFastReload = true;//������� �������
			LocatorReloadEnterDisable("Pirates_Shipyard", "reload1_back", true);
			LocatorReloadEnterDisable("Pirates_Shipyard", "reload2", false);
			LAi_LocationDisableOfficersGen("Bermudes_Dungeon", true);//�������� �� �������
			pchar.quest.Alex_Chest.win_condition.l1 = "location";
			pchar.quest.Alex_Chest.win_condition.l1.location = "Bermudes_Dungeon";
			pchar.quest.Alex_Chest.function = "AlexClock_Chest";
			pchar.quest.AlexClock_Over.over = "yes"; //����� ����������
			pchar.questTemp.AlexClock = "chest";
			AddQuestRecord("alex_clock", "3");
		break;
		
		case "clock_complete":
			dialog.text = "����� ��� ����������� � ����?";
			link.l1 = "����� ���. ��� ��������� ��������� ��������. � �� ��������, ��� �� ����������� ������ ������ ����������� ��������, � ��� �� �������� � ����� ������� �������� ����������. ������ ���������� ���� ��� ������.";
			link.l1.go = "clock_complete_1";
		break;
		
		case "clock_complete_1":
			dialog.text = "��, ������������ �� �������! �����. ����� ��� ��� ����, � ������ ��� � ����� ��� ������ ������������ ������.";
			link.l1 = "����������, �������...";
			link.l1.go = "clock_complete_2";
		break;
		
		case "clock_complete_2":
			RemoveItems(pchar, "alexs_chest", 1);
			dialog.text = "�������������!.. ���, �������... ���, �������. ��� ������������ ��������� � �����������, ����� � ��� �� ������� ����� ��� � ��������� ��� ������... ��, �������� �������, ����� � �� ����. � ����� ������� - ������� ������ ���������� ��� �� ���� �����. �� �������� ����������� ���������� ���� ������ � �� ������� �������� ������������\n������� ����� �������� ����� � ������� ������������! ������ �������� ��� �� ������ � �� ���������� �������� � �����, �������� ������� - �������� ������ ������������. ������������ �� ����������� ������.";
			link.l1 = "��� ��� ����! � ����� ������ ���� �� �����! �������, ������.";
			link.l1.go = "clock_complete_3";
		break;
		
		case "clock_complete_3":
			GiveItem2Character(pchar, "clock3");
			Log_Info("�� �������� ������������ ��������� � �����������");
			SetAlchemyRecipeKnown("sextant2");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ��������. ������ �� ������ ������ ����� �����, ������� ���. � ��� ������ �� � ���� - � �� �����������, ��� ����� �� ��������.";
			link.l1 = "� ������� ���� ���� �����, ���, ������? ������� ���� �����, � �� ���� ����� ��� � ����. ������� �� �������!";
			link.l1.go = "clock_complete_4";
		break;
		
		case "clock_complete_4":
			dialog.text = "� ��� ������� �� ������, �������. ������������ �� ���, �� ��������� ������� ��������.";
			link.l1 = "��� ��������... � ����� ������� - �����������, ������ �������. �� ��������!";
			link.l1.go = "clock_complete_5";
		break;
		
		case "clock_complete_5":
			DialogExit();
			bDisableFastReload = false;
			LocatorReloadEnterDisable("Pirates_Shipyard", "reload2", true);
			LocatorReloadEnterDisable("Pirates_Shipyard", "reload1_back", false);
			LocatorReloadEnterDisable("Bermudes_Dungeon", "reload2_back", false);
			LAi_LocationDisableOfficersGen("Bermudes_Dungeon", false);
			AddQuestRecord("alex_clock", "5");
			CloseQuestHeader("alex_clock");
			DeleteAttribute(pchar, "questTemp.AlexClock");
		break;
	// <-- ��������� ������
		
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
			Log_Info("�� �������� ������� �������� �������");
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
			SetLaunchFrameFormParam("������ 5 ����..."+ NewStr() +"������ ������� �������� ������", "", 0, 5);
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
			SetLaunchFrameFormParam("������ 2 ���..."+ NewStr() +"������ ������� �������� ������", "", 0, 5);
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
