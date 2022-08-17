// 
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;
	int iTemp, iSum; // 280912
	string s1;
	
	int iShipClass = GetCharacterShipClass(PChar);
	int iRank = sti(PChar.rank);
	int iSumm, iType;
	int iSan, iOil, iSil, iRop;
	
	ref rRealShip;
	ref shTo;
	aref refShip;
	string attr;
	float fTmp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	if ( sti(pchar.Ship.Type) != SHIP_NOTUSED)
	{
		int   	shipCurHP   = sti(RealShips[sti(pchar.Ship.Type)].HP);
		int   	shipBaseHP	= sti(RealShips[sti(pchar.Ship.Type)].BaseHP);
		int   	shipClass   = sti(RealShips[sti(pchar.Ship.Type)].Class);
	}

	int     Matherial1;
	int     Matherial2;
	int     Matherial3;
	int     Matherial4;
	int		HPPrice; 

	int Material, WorkPrice;
	int amount;
	int	iCannonDiff;
	
	// ��������� ������� �� ����� -->
	string attrLoc   = Dialog.CurrentNode;
	int i;
  	if (findsubstr(attrLoc, "SailsColorIdx_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.SailsColorIdx = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "SailsColorDone";
 	}
 	if (findsubstr(attrLoc, "SailsTypeChooseIDX_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.SailsTypeChooseIDX = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "SailsTypeChoose2";
 	}	

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		case "First time":  // �������� ��������� �������, ������ ���� ���
			if(NPChar.quest.meeting == "0")
			{
				Dialog.Text = "���... ��� �� ������... ���� ����� " + GetFullName(npchar) + ", �, ���� ���� ����, � ������ �������� �� ���� ������� ����� ��������. �� ��� ������� ������ ����� ���� � �������...";
				Link.l1 = pcharrepphrase("������ ������, ������ ����������� ��������� ��� �� �������. ��� ��� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.",
					"��� �� ������, ��� ��������, ���������. ���� ����� " + GetFullName(pchar) + ", �����, �� ��� ��� �������.");
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
			NextDiag.TempNode = "Master_Picasso";
			Dialog.CurrentNode = "Master_Picasso";
		break;

		case "Master_Picasso":

			dialog.text = "�, ��� ����� ��, ����� �� ������ ����������... ���... ���.";
			link.l1 = pcharrepphrase("�� �����, ��� ����� �. �� ������� ��������� � �����, ���� �� �� ������ ���� ����.",
	            "� ��� ������� ������, � ������, ���� ���������, ������� �������� � ����� ���������� ��������.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("�� ������� ���� ����� ����������. ��������.",
				"��� ����, ��������, ��� �����������"+ GetSexPhrase("","�") +".");
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;

		case "node_1":
			dialog.text = "�� ��������� �� ��� ������� �����. ������� ������, ������� ����, ��� ��� ��� ����?";
			link.l1 = pcharrepphrase("��� �����. �� ���� ��� ������ ����� �������� �����, � ������, ���� ����� ��� �������...",
				"���-�� ������������ ���, ��� �� ���� �� ���������� ������ ��������� � ������������. ����� �� ���?");
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.text = "����� �������� �� ������, �� ��� �������!";
			link.l1 = pcharrepphrase("�����-�����, �� �������, � �� ���� ������. �� ����, ���� ���� �������� � ������ ������� ��������� �� �������. �������-�� ����� �������� � ������.",
				"� ������ ���� ��� ��������, ������ �� �������� � ������ �������. � ������, ���� �� ��������, ����� ����� �������� � �����.");
			link.l1.go = "Picasso";
			link.l2 = pcharrepphrase("���, � ���� ������ �����������! ������!",
				"� ����, ������ ����� �� �� ������. ������.");
			link.l2.go = "exit";
		break;

		case "Picasso":
			dialog.Text = "�� � ���� �� �� ������? �� ���� ���� ...";
			link.l1 = "� ���� ��������� ������.";
			link.l1.go = "Picasso_1";
		break;

		case "Picasso_1":
			dialog.Text = "�� ������? �����?";
			link.l1 = "� ���, ����� �� �������?";
			link.l1.go = "Picasso_2";
		break;

		case "Picasso_2":
			dialog.Text = "��� ����, �� ����� ���� �������� ������!";
			link.l1 = "��, ���������, ����� � ������� ������� ������� ������� �������� � ������ ��������, ������ ��� ������� ��������, � ������ �������� � ����� � ������� �� ����, � ����� ��������. ������ �� ���������?";
			link.l1.go = "Picasso_3";
		break;

		case "Picasso_3":
			dialog.Text = "�������, ������ �� �� �������, � ��������?";
			link.l1 = "�, �� � �����?";
			link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.text = "���, ���... �� ���� ��������� �����. ��� ��� ����� �� ���� �����, " + GetAddress_Form(NPChar) + "? ";
			link.l1 = pcharrepphrase("��� ���� ��������������� ������ ��������.","� ���� ��������������� �������� ������������ �������!");
			link.l1.go = "parus";
			link.l9 = pcharrepphrase("����, � ���� ���� ���� ���������� ���, �� ��������.", "��� ��� ����, ��������.");
			link.l9.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;

		case "parus":
		if ( sti(Pchar.Ship.Type) != SHIP_NOTUSED)
		{
			dialog.text = "����� ���� ��������?";
			link.l1 = "�����.";
			link.l1.go = "white";
			link.l2 = "�����.";
			link.l2.go = "ser";
			link.l3 = "׸����.";
			link.l3.go = "black";
			link.l4 = "�������.";
			link.l4.go = "golub";
			link.l5 = "�����.";
			link.l5.go = "sin";
			link.l6 = "����������.";
			link.l6.go = "fiol";
			link.l7 = "������-������.";
			link.l7.go = "sw-zel";
			link.l8 = "Ҹ���-������.";
			link.l8.go = "Zel";
			link.l9 = "����.";
			link.l9.go = "Red";
			link.l10 = "Ƹ����.";
			link.l10.go = "zelt";
		}
		else
		{
			dialog.text = "���-�� � �� ���� ������ ������� � �����.";
			link.l1 = "����� ����� � ����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		}
		break;

		case "white":
			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "white1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;

		case "white1":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_pat.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{					
				                AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_pat.tga";
					DialogExit();
				}

			}
		break;

		case "ser":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "ser1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "ser1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_ser.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_ser.tga";
					DialogExit();
				}
			}
		break;
		
		case "black":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "black1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "black1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_black.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_black.tga";
					DialogExit();
				}
			}
		break;
		
		case "golub":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "golub1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "golub1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_golub.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_golub.tga";
					DialogExit();
				}
			}
		break;
		
		case "sin":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "sin1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "sin1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_sin.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_sin.tga";
					DialogExit();
				}
			}
		break;
		
		case "fiol":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "fiol1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "fiol1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_fiol.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_fiol.tga";
					DialogExit();
				}
			}
		break;
		
		case "sw-zel":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "sw-zel1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "sw-zel1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_sw-zel.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_sw-zel.tga";
					DialogExit();
				}
			}
		break;
		
		case "Zel":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "Zel1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "Zel1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_Zel.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_Zel.tga";
					DialogExit();
				}
			}
		break;
		
		case "Red":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "Red1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "Red1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_Red.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_Red.tga";
					DialogExit();
				}
			}
		break;
		
		case "zelt":

			if (shipClass == 6){dialog.text = "��� ����� ������ 5 000 ����."; iSum = 5000;}
			if (shipClass == 5){dialog.text = "��� ����� ������ 10 000 ����."; iSum = 10000;}
			if (shipClass == 4){dialog.text = "��� ����� ������ 15 000 ����."; iSum = 15000;}
			if (shipClass == 3){dialog.text = "��� ����� ������ 20 000 ����."; iSum = 20000;}
			if (shipClass == 2){dialog.text = "��� ����� ������ 25 000 ����."; iSum = 25000;}
			if (shipClass == 1){dialog.text = "��� ����� ������ 30 000 ����."; iSum = 30000;}
			link.l1 = "� ��������.";
			link.l1.go = "zelt1";
			link.l2 = "� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Picasso";
		break;
		
		case "zelt1":
                                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			if (sti(pchar.money) < sti(iSum))
			{
			dialog.text = "� ���� �� ������� �����.";
			link.l1 = "�����, � ����� �����.";
			link.l1.go = "exit";
			}
			else
			{
				shTo = &RealShips[sti(Pchar.Ship.Type)];
				if (shTo.EmblemedSails.normalTex == "ships\parus_zelt.tga")
				{
					dialog.text = "�� ���, �����? � ���� ��� ����� ����� ������!";
					link.l1 = "�����...";
					link.l1.go = "exit";
				}
				else
				{
					AddMoneyToCharacter(pchar, -iSum)
					DeleteAttribute(shTo, "EmblemedSails.normalTex");
					shTo.EmblemedSails.normalTex = "ships\parus_zelt.tga";
					DialogExit();
				}
			}
		break;
		




 		case "Exit":
            NextDiag.TempNode = "First time";
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

string findShipyardCity(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (sti(colonies[n].nation) != PIRATE && colonies[n].id != "Panama" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� �� ���� ������
		{
			if (GetCharacterIndex(colonies[n].id + "Picasso") != -1)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[rand(howStore-1)];
	return colonies[nation].id;
}

// �������� ����� ��� ���� ����
bool CheckSailsColor(ref chr, int col)
{
	int    st = GetCharacterShipType(chr);
	ref    shref;
	
	if (st != SHIP_NOTUSED)
	{
		shref = GetRealShip(st); 
		st = -1;
		if (!CheckAttribute(shref, "ShipSails.SailsColor"))  st = 0; // ���� - ��� �����
		if (CheckAttribute(shref, "SailsColorIdx"))  st = sti(shref.SailsColorIdx);
		if (st == col) return false;
	}
	return true;		
}

bool CheckSailsGerald(ref chr)
{
    int    st = GetCharacterShipType(chr);
	ref    shref;
	if (st != SHIP_NOTUSED)
	{
		shref = GetRealShip(st);
		if (CheckAttribute(shref, "GeraldSails"))  return true;
	}
	return false;
}

string GetSailsType(int _type)
{
	string sSail;
	
	switch (_type)
	{
	    case 1 : sSail = ""+XI_ConvertString("sails_1")+""; break;
	    case 2 : sSail = ""+XI_ConvertString("sails_2")+""; break;
	    case 3 : sSail = ""+XI_ConvertString("sails_3")+""; break;
		case 4 : sSail = ""+XI_ConvertString("sails_4")+""; break;
		case 5 : sSail = ""+XI_ConvertString("sails_5")+""; break;
		case 6 : sSail = ""+XI_ConvertString("sails_6")+""; break;
		case 7 : sSail = ""+XI_ConvertString("sails_7")+""; break;
		case 8 : sSail = ""+XI_ConvertString("sails_8")+""; break;
		case 9 : sSail = ""+XI_ConvertString("sails_9")+""; break;
		case 10 : sSail = ""+XI_ConvertString("sails_10")+""; break;
		case 11 : sSail = ""+XI_ConvertString("sails_11")+""; break;
	}
	return sSail;
}

int GetSailsTypePrice(int _asis, int _tobe, float _shipCostRate, int _price)
{
	int ret;
	ret = _tobe - _asis;
	
	if (ret < 0) ret = 0;
	
	return makeint((ret*_price*0.05 + _price*0.05)*_shipCostRate / 10) * 10;
}

void SelectFindship_ShipType()
{
	int iRank;
	if (sti(pchar.rank) == 1) iRank = 0;
	if (sti(pchar.rank) > 1 && sti(pchar.rank) <= 2) iRank = 1;
	if (sti(pchar.rank) > 2 && sti(pchar.rank) <= 4) iRank = 2;
	if (sti(pchar.rank) > 4 && sti(pchar.rank) <= 7) iRank = 3;
	if (sti(pchar.rank) > 7 && sti(pchar.rank) <= 10) iRank = 4;
	if (sti(pchar.rank) > 10 && sti(pchar.rank) <= 18) iRank = 5;
	
	switch (iRank)
	{
		case 0:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_SCHOONER + rand(makeint(SHIP_BARQUE - SHIP_SCHOONER));
		break; 		
		case 1:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_BARKENTINE + rand(makeint(SHIP_SHNYAVA- SHIP_BARKENTINE));
		break;
		case 2:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_FLEUT + rand(makeint(SHIP_CARAVEL - SHIP_FLEUT));
		break;
		case 3:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_PINNACE + rand(makeint(SHIP_CARACCA - SHIP_PINNACE));	
		break;
		case 4:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_SCHOONER_W + rand(makeint(SHIP_POLACRE - SHIP_SCHOONER_W));
		break;
		case 5:  
			pchar.GenQuest.Findship.Shipyarder.ShipType = SHIP_NAVIO + rand(makeint(SHIP_FRIGATE_H - SHIP_NAVIO));
		break;
	}
}

// �������� ���������� ���������� ��� ������������ �������
void checkMatherial(ref Pchar, ref NPChar, int good)
{
    int amount;

    amount = GetSquadronGoods(Pchar, good) - sti(NPChar.Tuning.Matherial);
    if (amount < 0)
    {
       amount = amount + sti(NPChar.Tuning.Matherial);
    }
    else
    {
        amount = sti(NPChar.Tuning.Matherial);
    }
    RemoveCharacterGoods(Pchar, good, amount);
    NPChar.Tuning.Matherial = sti(NPChar.Tuning.Matherial) - amount;
}

/*
  _chr 		- ��
  NPChar 	- �������
  MaterialNum -  ����� ��������� ��� �������� 
	 1 - �����	 
	 2 - ���� � ��������
  ������� ���������� ���-�� ��������� ������������ ��� ������� ���� ��������	  
*/

int GetMaterialQtyUpgrade( ref _chr, ref _nchar, int MaterialNum )
{
	if ( sti(_chr.Ship.Type) == SHIP_NOTUSED) return 0;
	
	float fQuestShip 	= 1.0;
		
	int   	shipClass     		= sti(RealShips[sti(_chr.Ship.Type)].Class);	
	int   	shipMinCrew   		= sti(RealShips[sti(_chr.Ship.Type)].MinCrew);	
	int 	shipPrice			= sti(RealShips[sti(_chr.Ship.Type)].Price);	
		
	if(CheckAttribute(&RealShips[sti(_chr.Ship.Type)], "QuestShip")) 	fQuestShip = 1.3;	

	int Material 	= makeint((20 * (7 - shipClass) + 15 * MOD_SKILL_ENEMY_RATE + drand(shipMinCrew)) * fQuestShip);
	int WorkPrice 	= makeint(fQuestShip * shipPrice/500.0);
		
	if(Material < 1) 		Material 	= 1;
	if(WorkPrice < 10) 		WorkPrice 	= 10;
	
	if(MaterialNum == 1) return Material;	
	if(MaterialNum == 2) return WorkPrice;
	
	return 0;
}
