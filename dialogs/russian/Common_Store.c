// boal 08/04/04 ����� ������ ���������
#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06

void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	string iDay, iMonth, sTemp, sMoney, attrL;
	
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	int iMoney, iQuantityGoods, iTradeGoods, iTmp;
	
	bool  ok;

	int iTest, cn, i;
	iTest = FindColony(NPChar.City); // ����� ��������
	ref rColony, chref;
	
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	int iSeaGoods = LanguageOpenFile("ShipEatGood.txt"); // ����� �������� �� GetGoodsNameAlt(idx)

	if(!CheckAttribute(npchar, "quest.trade_date"))
	{
		npchar.quest.trade_date = "";
	}
    
	// ����� ������� �� ������� -->
	NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Store\" + NPChar.City + "_Store.c";
	if(LoadSegment(NPChar.FileDialog2))
	{
		ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
	
	// ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06
	
	string attrLoc   = Dialog.CurrentNode;
	
	if(HasSubStr(attrLoc, "TransferGoodsTo_"))
	{
		NPChar.CharToTransferGoodsID = FindStringAfterChar(attrLoc, "_");
		Dialog.CurrentNode = "TransferGoods_Start";
	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(23) + ".wav");
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("� ������ ������� �������, ���� ����� ����! �� ����� ����� � �� �� ���� ����� �������������.", "��� ��������� ������ ����� �� ������ � ������� ����. � �� ����� � ������������� � ����� �� ����!", "����, "+ GetSexPhrase("��������","�������") +", ���� ������� �� ������� �� ���� ������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","������� �����") +"!", ""+ GetSexPhrase("�������","�������") +" ������, ��� �� ����� ����! ������!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "���, " + GetWorkTypeOfMan(npchar, "") + ", � ��� ���� �� - ������� ������! ��� ��� � ���� �����, ��������: ���� ���� � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
			if (sti(pchar.GenQuest.Piratekill) > 20 && sti(npchar.nation) == PIRATE)
			{
				dialog.text = RandPhraseSimple("�, ��� ��, ��������! �������, ���� ����� ����? ��� �� �� ���! ������! � ������! ���� �����!", "������ ����-�� ������, �������? �� ���! ������ ���� �������, ��� ���� ������! ������, ����� ������� ���� � �������! �������!");
				link.l1 = RandPhraseSimple("�? ���?", "�, �� ���� ���?!");
				link.l1.go = "fight";
				bDisableFastReload = true;//������� �������
				pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
				pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
				pchar.quest.pirate_in_town.function = "TownPirate_battle";
				break;
			}
			//--> Jason ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				//Jason --> ����-����� ���������� �����
				if (CheckAttribute(pchar, "questTemp.Wine.Trader") && NPChar.location == pchar.questTemp.Wine.City + "_store" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
				{
					link.l13 = "� ���� ���������� � ��� ������ ������������ ����, ������� ���������-����������. ��� �������, ��� ��� � ��� ������� � ����������� ����������."; 
					link.l13.go = "Wine_Trader";
				}
				if (CheckAttribute(pchar, "questTemp.Wine.Repeat2") && NPChar.location == pchar.questTemp.Wine.City + "_store" && CheckCharacterItem(pchar, "letter_1") && !CheckAttribute(pchar, "questTemp.Wine.fail"))
				{
					link.l13 = "������������ ��� ���. �������� ��� ��� ������, �, ���� �����, �� ������������ ������ � ������� ����?"; 
					link.l13.go = "Wine_Repeat2";
				}
				if (CheckAttribute(pchar, "questTemp.Wine.wait") && NPChar.location == pchar.questTemp.Wine.City + "_store" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
				{
					link.l13 = "��� ����� �. ������� ��������� ���� ���������� �������� �����, � �������� ����� ��������."; 
					link.l13.go = "Wine_Price";
				}
				// <-- ����-����� ���������� �����
				dialog.text = "�� ������ ���������� ���-�� � ���� ��������, �����?";
				Link.l1 = "�������! � ��� ���� �� ��� �������� ����������? ����������� ���� ������.";
				Link.l1.go = "trade_1";
				Link.l2 = "� � ��� �� ������ �������...";
				Link.l2.go = "quests";
				Link.l3 = "����� ��������, �� ��� ���� ����.";
				Link.l3.go = "exit";
				break;
			}			
			//<-- ����� ��������
			
			// Warship, 29.05.11. ���� ����� - ��������� ������������.
			if(CheckAttribute(PChar, "QuestTemp.AffairOfHonor.CowardFencer.CanTraderTalk"))
			{
				dialog.text = "�������, ������� �� ��, ��� ������ ����.";
				Link.l1 = "�� �� ���.";
				Link.l1.go = "exit";
				DeleteAttribute(PChar, "QuestTemp.AffairOfHonor.CowardFencer.CanTraderTalk");
				break;
			}
			// ��������� �����
			if(CheckAttribute(npchar, "quest.trial_usurer"))
			{
				dialog.text = "��� � ����, �������? �� ���-�� ��������? ��� �� ��� �������� �� ����� ��������?";
				Link.l1 = "��, ����������� ���� - �������. ��� ���� ������ ����� ������? � �������� ��� ��������� �������� ����, �, ������� ���� �����, ��� �������� ������� �����������! � ������, ����� � ������� �� ����� ��������, ����������, ��� ����� ������ � ���� �������!";
				Link.l1.go = "trial";
				break;
			}
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -10 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -20)
			{
			 // if (rand(9) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 30 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 30)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 30); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 30 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 50); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 50) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 50)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 50)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                 Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -20 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -30)
			{
			 // if (rand(8) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 40 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 40)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 40); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 40 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 60); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 60) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 60)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 60)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -30 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -40)
			{
			 // if (rand(7) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 50 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 50)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 50); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 50 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 70); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 70) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 70)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 70)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -40 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -50)
			{
                   // if (rand(6) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 60 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 60)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 60); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 60 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 80); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 80) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 80)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 80)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -50 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -60)
			{
			 // if (rand(5) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 70 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 70)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 70); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 70 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 90); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 90) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 90)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 90)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -60 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -70)
			{
			 // if (rand(4) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 80 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 80)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 80); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 80 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 100); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 100) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 100)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 100)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom"; 
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -70 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -80)
			{
			  //if (rand(3) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 90 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 90)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";
				RemoveItems(pchar, "gold_dublon", 90); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 90 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 110); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 110) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 110)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 110)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
            if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <=-80 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) > -90)
			{
			 // if (rand(2) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 100 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 110)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 100); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 100 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 120); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 120) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 120)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 100)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  			
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -90)
			{
			 // if (rand(1) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 130 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 130)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";
				RemoveItems(pchar, "gold_dublon", 130); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 130 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 150); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 150) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 150)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 150)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }	
			}  
            dialog.Text = GetNatPhrase(npchar, LinkRandPhrase("��� �������������� ���, ���! ������� � ����� �����?","����� ����������, �������! ��� ������� � ����� �������, ���.","����� ���, ���, ���������! � ��� ���������� ��� ��� ������, ��� ������ ����� ������ �� ����������."), LinkRandPhrase("�, ����� �������! ������ ������ ����������� ������� � ����� � ������ � � ������ ��� ���!","����� �������� ����������, �����! ������ ������� ������ ����������� ������� � ����� �������!","�� �� ����������� ������, ����� �������? ��� ������� �� ������� ������ ������� ����������!"), LinkRandPhrase("�! ������ �������! � ��� ������ ��� � ���� ��������!","��� �������������� ����� ���������� ��������� � ������ �������� ��������� �������!","�, ����������� �������! ������ �� ��� ������� ��� � ��� �������� ������� � ����� �� ������� ���, ��� ������ ���������!"),LinkRandPhrase("������ ����, ������ �������. ��� ��� ������ ����� � ���?","������������, ������. ������� � ���? ��������, �������� ����������� ������� ������� ��� �������!","����� ���, ������ �������! ����� ������������ ������ �� ����� ������ ����� � ���� ���� �� �� ��-����������!"));
			Link.l1 = LinkRandPhrase("� ��� ���� ���. ��� ��� "+GetFullName(pchar)+" � � ����� ������ �������. ��, �����������, ��� ����� ���������?","�������� �������, � "+GetFullName(pchar)+". ������� ������� ''"+pchar.ship.name+"''.  ����, ��� ��� � ��� ���� �����������?",""+GetFullName(pchar)+", ������� ������� ''"+pchar.ship.name+"'', ��� ����������. ��� �� ��� ����������?");
			link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "second time":
			if (LAi_group_GetPlayerAlarm() > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("� ������ ������� �������, ���� ����� ����! �� ����� ����� � �� �� ���� ����� �������������.", "��� ��������� ������ ����� �� ������ � ������� ����. � �� ����� � ������������� � ����� �� ����!", "����, "+ GetSexPhrase("��������","�������") +", ���� ������� �� ������� �� ���� ������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","������� �����") +"!", ""+ GetSexPhrase("�������","�������") +" ������, ��� �� ����� ����! ������!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "���, " + GetWorkTypeOfMan(npchar, "") + ", � ��� ���� �� - ������� ������! ��� ��� � ���� �����, ��������: ���� ���� � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
            
			//--> Jason, ������������ �����������
			if (CheckAttribute(pchar, "GenQuest.Contraoffer.Trader.busy"))
			{
				dialog.text = "��������, �� ��� ������ �� �� ���.";
				link.l1 = "��, �������. � ����� �����.";
				link.l1.go = "exit";
				break;
			}
			//<-- ������������ �����������
            
			// Warship, 29.05.11. ���� ����� - ��������� ������������.
			if(CheckAttribute(PChar, "QuestTemp.AffairOfHonor.CowardFencer.CanTraderTalk"))
			{
				dialog.text = "�������, ������� �� ��, ��� ������ ����.";
				Link.l1 = "�� �� ���.";
				Link.l1.go = "exit";
				DeleteAttribute(PChar, "QuestTemp.AffairOfHonor.CowardFencer.CanTraderTalk");
				break;
			}
			// ��������� �����
			if(CheckAttribute(npchar, "quest.trial_usurer"))
			{
				dialog.text = "��� � ����, �������? �� ���-�� ��������? ��� �� ��� �������� �� ����� ��������?";
				Link.l1 = "��, ����������� ���� - �������. ��� ���� ������ ����� ������? � �������� ��� ��������� �������� ����, �, ������� ���� �����, ��� �������� ������� �����������! � ������, ����� � ������� �� ����� ��������, ����������, ��� ����� ������ � ���� �������!";
				Link.l1.go = "trial";
				break;
			}
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -10 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -20)
			{
			 // if (rand(9) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 30 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 30)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 30); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 30 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 50); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 50) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 50)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 50)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                 Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -20 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -30)
			{
			 // if (rand(8) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 40 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 40)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 40); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 40 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 60); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 60) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 60)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 60)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -30 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -40)
			{
			 // if (rand(7) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 50 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 50)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 50); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 50 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 70); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 70) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 70)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 70)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
			    link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -40 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -50)
			{
                   // if (rand(6) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 60 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 60)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 60); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 60 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 80); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 80) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 80)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 80)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -50 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -60)
			{
			 // if (rand(5) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 70 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 70)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 70); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 70 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 90); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 90) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 90)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 90)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -60 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -70)
			{
			 // if (rand(4) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 80 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 80)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 80); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 80 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 100); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 100) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 100)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 100)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom"; 
				}
				break;
			  }
				
			}  
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -70 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0)> -80)
			{
			  //if (rand(3) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 90 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 90)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";
				RemoveItems(pchar, "gold_dublon", 90); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 90 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 110); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 110) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 110)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 110)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
            if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <=-80 && ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) > -90)
			{
			 // if (rand(2) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 100 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 110)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";  
				RemoveItems(pchar, "gold_dublon", 100); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 100 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 120); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 120) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 120)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 120)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  			
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -90)
			{
			 // if (rand(1) == 1)// �������� ����� �� �� ���
			  { 
				dialog.text = "���������, � �� ����� ��� �� ��� ���� �������? �� ����� ������� ���� ������ �� 130 ��������.";
				if (GetCharacterItem(pchar, "gold_dublon") >= 130)
				{	
				Link.l1 = "��, ��, ������! �����, ���� � �����, ��� ���� �������! ��������� ������.";
				RemoveItems(pchar, "gold_dublon", 130); // ����� ������������� ������� � � �������� 
			    Log_Info("�� ������ 130 ��������!");
PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
PlaySound("_CheatSurfMenu_\Gold.wav");
AddCharacterExpToSkill(pchar, SKILL_LEADERSHIP, 150); //+ �������
AddCharacterExpToSkill(pchar, SKILL_SNEAK, 150) //+ ���������� 
AddCharacterExpToSkill(pchar, SKILL_FORTUNE, 150)//+ �������
AddCharacterExpToSkill(pchar, SKILL_COMMERCE, 150)//+ ��������
              	Link.l1.go = "node_1"; 
              	}
				else
				{	
                Link.l2 = "׸��, � ���� ��� � ����� ������� ��������!";  // ���� ��� ��������� �� ����� ������
				link.l2.go = "oblom";  
				}
				break;
			  }
				
			}  
			dialog.Text = pcharrepphrase(LinkRandPhrase(LinkRandPhrase("���� ��� � ��� �������? �������, ������-�� �� ������, ��� ��� ���������, �������, ���������...","�� ���� �������, ��� ��� ������ ���, "+GetFullName(pchar)+"... �� ����������� ���� �����.","��-��... � ����� �� ���������, �������, �� ��� ������� ���� ��� � ����� �������."),LinkRandPhrase("�, ���� � ����! ��� "+GetFullName(pchar)+"! ��������� � ���, ��� ���, ����� ��� �����? ����, ����...","�� ��, ����� � ��� ��� ������ ������, "+GetAddress_Form(NPChar)+". �� ���� �� ��� ������� � ��������, ���� �� ���...","������ �����������, ������� "+GetFullName(pchar)+"? �������, ������ ���������, � �� ������ ������� ��� ��� �� ��������� � �������, � ���� �� ����� ��������."),LinkRandPhrase("����� ���������, ������? ���������, � ����� �������, � �� ����� ��� ������... ��� �, �������, �� ���, �������!","������� ��� � ����, "+GetAddress_Form(NPChar)+", � ��, �������, �������� �������� �������, ��-��... �� �����, � ����, ��������� �����������.","���, ����� ������������: ����, ��� � ������� ���, ����� �������� ������, � ���� �������� ������� � ������ ����� �� ����. � ��� � ��������, ���������.")),LinkRandPhrase(LinkRandPhrase("� ����� � ��� �������������� ���, "+GetAddress_Form(NPChar)+"! ������ ��� �������  - � ������ ��� ������ ���.","����� ���, "+GetAddress_Form(NPChar)+", �����! � ��� �������������� ������ ������� �������. ������� ���-������ ������ ��� �������?","�, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! ��� � ��� ����� ������ ���! ������ ������ ��� ������� ���-������?"),LinkRandPhrase("��� ����������� ���� ������, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"? � ������ � ����� ������� � ��������, ���������.","������������, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+". � ���, ��� �� ����� ��������� �� ���. ������ ������� ��� ���������� �������?","��� ���, �������! � ����, ��� ���� ��������� ������ ��� �����������. ����������, ��� ���� ����������?"),LinkRandPhrase("�, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! ����� ���, ����� ������ ��� ���! � ����� ������ ������ � � ��������� ��������!","������� "+GetFullName(pchar)+", �� ����� ������������ ���� ����� �������! ��������� � ��� ��� ������!","��� ��� ������, �������? ���, ��� ������� ������ �� ���. ����� ������ ��� ��� � ������� � �����������, ��� ������� �������!")));
			Link.l1 = pcharrepphrase(RandPhraseSimple(RandPhraseSimple("��� ��� ��� �� ��� ���, �������? ��� �, � ����, ����� ������� ���� � ����... �� �� ������� �� ���, ����. �����, ������, ��� ��� � ���� ����?","���, ����. ������ ��� ���� �����, � ��� ���� ���� � �� �����. ��� ��� ����������, ��� ������? �����, �������� ��� � ��������� ������."),RandPhraseSimple("����� � ����, ������. ��� ������� ��� � ����� ������ ���������, � ������ �� �������� �������. �����-�� ����� ���������, ��� ��������� ����.","������ �� �����, ��������. ����� �������, �� � ���� ���� � ������������... ��� ��� �� ��� ���� � ��������� ������.")),RandPhraseSimple(RandPhraseSimple("������ ��� ��� ��������, �������. ��� ��� � ��� � �������� �������� ��������?","� ��� ������ ������� �����, ��������. ��� ���������� �������� ��� ������� ������, �������� �� ��������� �� ����?"),RandPhraseSimple("� ����� � � "+XI_ConvertString("Colony"+npchar.City+"Dat")+"! ���, ��� ���� ����� �� ��������. � ��� �������� �� ����� ������� ���-������ ��� ���� ��� ��� ��� ���������? ","��� �� � ��� �� �����? �� ������ ���� ���-������ �� ���������. ��, ��� � ��� ���?")));
			link.l1.go = "node_1";
			NextDiag.TempNode = "Second time";
		break;

		case "oblom":
		    dialog.text = "����� � ������� ������. ������, ����! ����� ����������!!!";
            link.l1 = "�� � ������� �� ��!";
            link.l1.go = "exit"; // fight
            LAi_group_Attack(NPChar, Pchar);
         break;			

		case "node_1":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(23) + ".wav");
			dialog.text = NPCStringReactionRepeat(NPCharRepPhrase(npchar,
			                                         pcharrepphrase(RandPhraseSimple("�������� ���� ������! ","���� � �������! ") +LinkRandPhrase("��� ����� "+ GetSexPhrase("�����������","�����������, ��, ������, ����") +" ����� � ���� ��������, ��-��?",
													                                 "����� �������� ������� ��� ������� ������� ��������! ��-��!", "����� �������� ������ ���� ������� � ��� �������?"),
            														LinkRandPhrase("������� �����!", "������ � �����!","������� ����� �� �����!")+RandPhraseSimple(" � ���� �� �������"," � ���� ��������")
																	+LinkRandPhrase(" ����� ������ ���� �� �������."," ���������� ����� �������."," ������ ������ ������� ��������.")
																	+RandPhraseSimple(" � � ����� �������"," ���, ��� ���������")+", �������!"),
													 pcharrepphrase(RandPhraseSimple("����� ������ ��� "+ GetSexPhrase("������������","������������ � ����") +" �����! ��-��! ���� �� �� �������� �������� �� ��������!",
													                                 "����� ������ ���������� � ����� � �������� ���� �����. �� ������ �� ������, �����?!"),
                 												"������� " +LinkRandPhrase("������ ������ ������ " + NationNameGenitive(sti(NPChar.nation)),"������ ��� ������� ����", "�������� �������� �����")
																	+RandPhraseSimple("? � ��������� � ����� ������������!","? ��� ������� � ����� �������!")
																	+RandPhraseSimple(" ��� ��� ������"," ��������������") +", �������!")),
				                                  NPCharRepPhrase(npchar,
												  	 pcharrepphrase("��� ���� �����, ���: �� ����� ����� �� �������. ���������� ����� �������!",
													                "� � ������� ������� ������, ��� �� "+ GetSexPhrase("������ �����","������ �����") +". " +RandPhraseSimple("�� ������ � ����, ��� �� ����� "+ GetSexPhrase("�����","�����������") +".", "�� "+ GetSexPhrase("�����","������") +", �� "
																	+RandPhraseSimple("�� � ���� ������.", "���� �� ��������."))),
													 pcharrepphrase("� ����� �������� � ��� ���� ���� � ����������� ������. ������ ������ ������ ��� �������? ��� ������ � ����!",
													                "�������� ������������ - �������� ������, ������� " + GetFullName(pchar)+", �� ��� ��?")),
												  NPCharRepPhrase(npchar,
												     RandPhraseSimple("��� ��������� ���� �� ��������� �����! ��� �������� � ������ �������! " ,
													   RandPhraseSimple("���������� ������� �� ������ ��������!","���, � ������ ���� ������� �� �����!") +" ��-��-��! � ������� ����. ")
													   +RandPhraseSimple("���� ����, ���?", "��� �� ������ ������, �������?"),
													 pcharrepphrase("� �� ������ �������������, ������� " + GetFullName(pchar)+". ��� ����������� �������, � ��������� ��� ����� �������� ����!",
													                "�� ������, ������� " + GetFullName(pchar)+", �� �������� � ��� � ����� ��� ������� �������� � ����! ��� �� ������?")),
												  NPCharRepPhrase(npchar,
												     "�������, ��� ����� ������������� � �����. "
													 +LinkRandPhrase("���� ���-��� �������� �����. �� ��� ����� ������. ","�� �����, ��� ����� ���� ������ ����� ������� �����? ",
													 pcharrepphrase("���� � ������ �����. ����������� ���� - � �� ��������.","��� ��� ���� ������ ��������� ���� � ����! � ����!!! �� ����� �� �� "+ GetSexPhrase("���� �������","����� ���������") +"...")),
													 pcharrepphrase(RandPhraseSimple("� �������, ","� ��������, ")+RandPhraseSimple("��� �� �������� ��� ������.","��� ������ ������� ��� �� �����.")
													 +RandPhraseSimple(" �������� ����� � ��� �� ���, ��� ���������� �������..."," �������� ������� �� ��������� ����� ����� ��������?!"),
													 "������� " + GetFullName(pchar)+", ���� ������� � ��������� ����������� ��� ��� ��������!"
													 +RandPhraseSimple(" ������ ������� ��������� ������� ����� ���������?", " �� ������ ������ ���-�� ���������?"))),
										"cycle", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,
			                                        pcharrepphrase("�����, ���������, ��� � ���� ����, ������ �����!",
													               "� ����� ���� ���� ���������� �� ���� ������, ��������."),
													pcharrepphrase("������� ���������, " +GetFullName(npchar)+", � �� ������� ���� ������ ���� �� ���! ���� ��������� ���� ������!",
													               "������� ��������� ���� ������, " +GetAddress_FormToNPC(NPChar)+ ".")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("��� �����! ������� �� ��������! ��, ��� � ���� � ����� ����?",
													               "��, ��������, ����� ��������� ����� �����. ����� ������ ������ ��� ����������?"),
												    pcharrepphrase("������� � �� ������� ���� ������, ��-��. ����. ����� ���� ������.",
													               "������� ������� �������� ����, " +GetAddress_FormToNPC(NPChar)+ " " +GetFullName(npchar)+ "")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("��� ��� ����? ���� ������ ���-���!",
													               "�������� ��� ������ � ������, " +GetFullName(npchar)+ ". ��� ����� ���������� ���� ������."),
												    pcharrepphrase("���� � ���� ������! ��� ����� ����� �� ���� ����! ���� ��������� ���� ������",
													               "��� ������ �������. ������� �����������.")),
											  "��������� ������, ������ ���� � ������ ����. � ���������.",
											  npchar, Dialog.CurrentNode);
			link.l1.go = "market";
			link.l2 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,
			                                        pcharrepphrase("��, ��� �� � "+ GetSexPhrase("��������","���������") +" ����-������! �����, ����� � ����.",
													               "�������� � ������ �����, ��������"),
													pcharrepphrase("��������! � ������ �� ������� ����!",
													               "��� ����� � ���� ���������� �� ����, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+".")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("� ���� � ���� ����, ������ �����!",
													               "�������� � �����, ��������!"),
													pcharrepphrase("������� ��������, ���� ���� �� ��������, ��������! � ���� ������ ����!",
													               "��������� "+ GetSexPhrase("��������","��������") +", " +GetAddress_FormToNPC(NPChar)+ " " +GetFullName(npchar)+ ", � ���� �������� � ���� ���� ����.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("��� ��������, ��������?! � ���� � ���� ����.",
													               "� "+ GetSexPhrase("������","������") +" �� ���������, ��������. � ���� ������ ����."),
													pcharrepphrase("������� ���� ���� � ������ ������, �������! � ���� ���� � ����.",
													               "������ ������ �������, " + GetAddress_FormToNPC(NPChar)+ " " +GetFullName(npchar)+ ", �� � �� ������� ����.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("�������� ����, ������ �������, � ���� ���� � ����",
													               "������ ��� �� ����, � �������. �������, � �� ��� ���� �� � ��������. �������� � ����."),
													pcharrepphrase("�� � ��� ��� ������� ���� �� �����, ��������! � ���� � ���� ����.",
													               "���� ������ ���������, � ���� � ��� ���� ����� �������")),
											   npchar, Dialog.CurrentNode);
			link.l2.go = "business";
			link.l3 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,
			                                        pcharrepphrase("������� ����, ����� �������. ���� � ���� ������ ���-���.",
													               "�� ������, ��� ����� ����������."),
													pcharrepphrase("� ����� ����! ������� �� ������� ���, ��� ��� �����.",
													               "� �������������. � ���� ������ ���-���.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("������� �� �����, ������ ������. ��� ���� ���-��� ������.",
													               "� ���� ������������ ������."),
												    pcharrepphrase("������� ��������. � ���� ������ ���-���.",
													               "��, � "+ GetSexPhrase("��������","��������") +". ���� ��� �������� ��� � ���.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("� �����, �� ������, � ��� � ���� ��������.",
													               "� �������, �� �������� ��� �� ��� ������."),
													pcharrepphrase("� ���� � ������ ���� ���-������ ����� ��������? �� ���� � � ���� ��������.",
													               "���� �� �� ����. ��� ����� ���-����� ����������.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("�� ��������, �������! � ������ ���� �������� ����.",
													               "�� ���������� ���, ��� ������ ����. �������� ��� �� ������, � � ����."),
													pcharrepphrase("�� ��� �� ���� ������ ����� - �� � ���� ���������. �� �� ���-��� ������.",
													               "� �� ������� ��� �������. ����� ���� ������.")),
											   npchar, Dialog.CurrentNode);
			link.l3.go = "quests";

			//--> eddy. �������, ����� � ��������� ���������
			if (pchar.questTemp.Ascold == "Seek_powder" && pchar.questTemp.Ascold.TraderId == npchar.id) 
			{
				link.l3.go = "quests";
			}
			if (pchar.questTemp.Ascold == "PowderWasSeek" && pchar.questTemp.Ascold.TraderId == npchar.id) 
			{
				link.l3.go = "quests";
			}
			//<-- eddy. �������, ����� � ��������� ���������

			// --> Jason, ����� ��������� ������� 2 ������
			if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.LevelUp"))
			{
				if (pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
				{
					link.l12 = "� �������� ��� ������ ��� �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+".";
					link.l12.go = "Postcureer_LevelUp_ForAll";
				}
			}
			//<--����� ��������� ������� 2 ������	
						
			//Jason --> ����-����� ���������� �����
			if (CheckAttribute(pchar, "questTemp.Wine.Trader") && NPChar.location == pchar.questTemp.Wine.City + "_store" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
				link.l13 = "� ���� ���������� � ��� ������ ������������ ����, ������� ���������-����������. ��� �������, ��� ��� � ��� ������� � ����������� ����������."; 
				link.l13.go = "Wine_Trader";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.Repeat2") && NPChar.location == pchar.questTemp.Wine.City + "_store" && CheckCharacterItem(pchar, "letter_1") && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
				link.l13 = "������������ ��� ���. �������� ��� ��� ������, �, ���� �����, �� ������������ ������ � ������� ����?"; 
				link.l13.go = "Wine_Repeat2";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.wait") && NPChar.location == pchar.questTemp.Wine.City + "_store" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
				link.l13 = "��� ����� �. ������� ��������� ���� ���������� �������� �����, � �������� ����� ��������."; 
				link.l13.go = "Wine_Price";
			}
			// <-- ����-����� ���������� �����
						
			if(CheckAttribute(pchar,"GenQuest.EncGirl"))
			{
				if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "store_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
				{
					link.l9 = "������������, � ����"+ GetSexPhrase("��","��") +" �� ����������� ������ ����."; 
					link.l9.go = "EncGirl_4";
					pchar.quest.EncGirl_GetLoverFather.over = "yes";
				}
				if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
				{
					if(pchar.GenQuest.EncGirl.Father == "store_keeper" && npchar.city == pchar.GenQuest.EncGirl.city)
					{
						link.l9 = "� �� ������ ����� ������...";
						link.l9.go = "EncGirl_1";
					}
				}				
			}			
			link.l5 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,
			                                        pcharrepphrase("����, ������ ��������.",
													               "����� �������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"."),
													pcharrepphrase("��������! ������ �� �����. � ��� �����.",
													               "������� ���� ��� ������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"! �� ��������!")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("������ ��������!",
													               "�� ��������, ��������."),
													pcharrepphrase("��! �� ��� ��� �������? ���? ���!?! �� �����, �����, ����� �������.",
													               "����� ���� ��������, � ���� ������� ���� � ������.")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("���! ��� ��������!",
													               "��� ���� ����. ��������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!"),
													pcharrepphrase("� �� ���� ��� ��������! ������� ��� ��� � ����� �������!",
													               "�������, ����� ���������, ��� ���� �� �������. ��������, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),
											   NPCharRepPhrase(npchar,
											        pcharrepphrase("��� � �����, �������? ��� �� � - " +GetFullName(pchar)+ "! ��������, � ����� �����.",
													               "�����, ���� ������ ��������� ��� ������, ��� � ��� ��� ����� ����."),
													pcharrepphrase("������ ���� ������� � �����, ��������! � ��� �����.",
													               ""+ GetSexPhrase("��� ���","���� ����") +" ��� ������, " + GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),
											  npchar, Dialog.CurrentNode);
			link.l5.go = "exit";
		break;

		case "market":
//navy -->
		//����� ���
			if (CheckFreeServiceForNPC(NPChar, "Store") != -1)	 // to_do ��� ������
			{
				dialog.text = "��������, �� � ������ �����. ������ �������! �������� ������.";
				link.l1 = "�� ��� �� ��������! �����, ����� �������.";
				link.l1.go = "exit";
				break;
			}
//navy <--
			dialog.text = RandPhraseSimple("� ���� ���� �������� ����, ��������, ���������, ������ ��������� � ������ ������! ��� ��� ����������?", "������ ������ ������ � ���������? ���, ���� �����, ���� � ������?");
			link.l1 = pcharrepphrase(LinkRandPhrase("� ���� ����� ����� ������! ������ �� ������, �� ��� ��?",
			                         "��� ����� ���������� ���� ���� �� ������ � ������ ��� ����� �������. ��-��!",
									 "�� ����������� ������� �� � ������ ���� �������! �� ��� ����� ���� ����� ��������� ������."),
									 LinkRandPhrase("���� ������� ���� � ��������� ������.",
			                         "� ���� ������ ����� �� �������.",
									 "������ ��� ����, ����� � ������ ������."));
			link.l1.go = "trade_1";

			if (CheckAttribute(pchar, "CSM.Merchants"))
			{
				if (NPChar.id == "LaVega_trader" || NPChar.id == "LeFransua_trader" || NPChar.id == "Pirates_trader" || NPChar.id == "LeKe_trader" || NPChar.id == "FortOrange_trader" || NPChar.id == "Vestpunt_trader" || NPChar.id == "SantLous_trader" || NPChar.id == "Roseau_trader" || NPChar.id == "PuertoPrincipe_trader")
				{
					link.l2 = LinkRandPhrase("������ ��� �����, ���������, � ��� ��� � ���� ��� ����?",
											 "��� �� �������� ���� ����� ����������, ���� � �������� ��������.",
											 "����������� �����, ���������� ����� - ��� ��� ���� ����������.");
					link.l2.go = "items";
				}
			}

			if(IsPCharHaveTreasurer() && CheckAttribute(PChar, "TransferGoods.Enable")) // ����������� �������
			{
				link.l5 = "��� �������� ������� ����������� �������...";
				link.l5.go = "TransferGoods";
			}
			
			link.l3 = pcharrepphrase(RandPhraseSimple("��������� ��� ��������. �����!",
			                                          "�����, ����� �������. ������ �� �����."),
									 RandPhraseSimple("���, ��� ������ �� �� �������. ��������.",
									                  "��������, � ���� ������� ����. �� ��������!"));
			link.l3.go = "exit";
		break;
		
		case "EncGirl_1":
			dialog.text = "������ ��� �����������.";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" ���� ��������.";
			link.l1.go = "EncGirl_2";
		break;
		
		case "EncGirl_2":
			dialog.text = "��, �������, ������� ��� �������! ��� ���? �������, �� ����������? �� ����� �����, ��� �������, ���������. ����� � � �� ������� �����? ����� ������ ��������... ����� �������, �������, � ��� ����� �� ������, ��� ���� � ���� ���� �� ����. ���! ��� �� ��-������ ������� - ��� � ����, ���� �\n����, � ��� �� �� ���� �� ���������, ���� �� � ������ � ��� ����� �� ������� � ����� �������������� ���������... �� �� ��� ����������... ��������� ������, �����... � �������.";
			link.l1 = "�������, �� ���� � ������ ���, �� � �� �� �������"+ GetSexPhrase("��","���") +" �� ��������...";
			link.l1.go = "EncGirl_3";
		break;
		
		case "EncGirl_3":
			dialog.text = "�� ��� �� ���������?.. � ��� ���� ���� ����? ����? ���, ����� ����� - ��������, ����� � ���������\n��... � ������ �������������� ����, ��� � ����� - ������� ����������.";
			link.l1 = "�������. � ������� � ��������. ���-�� ��� ������������, ��� ��� �� ���� �� �����������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("EncGirl_ToLoverParentsExit");
		break;
		
		case "EncGirl_4":
			if(sti(pchar.GenQuest.EncGirl.LoverFatherAngry) == 0)
			{
				dialog.text = "�, ��� �� � ���� "+ GetSexPhrase("��� �������, ������� �����","�� �������, ������� ��������") +" ����� �������� ���� � ������� ��������?";
				link.l1 = "��, ��� � �����"+ GetSexPhrase("","��") +" �� �������.";
				link.l1.go = "EncGirl_5";
			}
			else
			{
				dialog.text = "�-�, ����"+ GetSexPhrase("��, �����������","���, ���������������") +". ������ ������� ����?";
				link.l1 = "��, �� ��, ����� �������, �� ������������� �������� �� ������ ��.";
				link.l1.go = "EncGirl_6";			
			}
		break;
		
		case "EncGirl_5":
			dialog.text = "� ����� ��� ����������, ��� �� �������� �� ���� � ��������������� ��������� � ������� ��� � ������ ����� �� ����� ���������� ��������. ��������� ������������� ���, ��� ����. ������� ��� �������� ����� � ������� �� ���� �����.";
			link.l1 = "��������� ���, ��� ���� ������� �������� ���� ������� �����.";
			link.l1.go = "EncGirl_5_1";
		break;
		
		case "EncGirl_6":
			dialog.text = "����� �������������?! �� ��� �������������?! ���� ����, ��� ���� ������� ��� ������� ��������� ��� ������, ��� ��� � ����������� ����� �����! �� � � ��� ���� ��� ��� ���� ������. � ��, ���, �����������! � �����������, ���, ����� �� �������, � ���� �������� �����-�� ������ ���������, ������ �������, � ������������� ������������� �����������!";
			link.l1 = "��, ������ �� �� ������ � ��������� �������?";
			link.l1.go = "EncGirl_6_1";		
		break;
		
		case "EncGirl_5_1":
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.EncGirl.sum));
			GiveItem2Character(pchar, pchar.GenQuest.EncGirl.item);
			AddQuestRecord("JungleGirl", "18");
			CloseQuestHeader("JungleGirl");
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "EncGirl_6_1":
			dialog.text = "����� ����� �������?! � ����� �������� �� ��������? ��������, ����� �������, � ���� ��... �������! ������ ��� ������ ���� ������� � ����� ����� �������� �� � ������ �����������. �������� �� ������������� ������ ������� � ����� ���������� ����� �������. �� ����� ��� ������� �������������. ��������.";
			link.l1 = "��� �, � ��� �� �������...";
			link.l1.go = "EncGirl_6_2";
		break;
		
		case "EncGirl_6_2":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			AddQuestRecord("JungleGirl", "19");
			AddQuestUserData("JungleGirl", "sSex", GetSexPhrase("��","��"));
			AddQuestUserData("JungleGirl", "sSex1", GetSexPhrase("","�"));
			CloseQuestHeader("JungleGirl");
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();		
		break;
		
		// Warship. ����������� ������� -->
		case "TransferGoods":
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				dialog.text = LinkRandPhrase("...��� ������. ����� ������ ������������, �� ���� ������ ������� ���������� ������.",
					"��� �������� ��� ��� ������. ������� ����������� � ��������, �� ������� ����� ���������� ������.",
					"��, " + PChar.name + ", � ����. �� ��� ��� � ���� � �������. �� ����� ������� ����� ������� ������?");
					
				for(i=0; i<COMPANION_MAX; i++)
				{
					cn = GetCompanionIndex(PChar, i);
					if(cn > 0)
					{
						chref = GetCharacter(cn);
						if(!GetRemovable(chref)) continue;
						
						attrL = "l"+i;
						Link.(attrL)    = "�� " + XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " ''" + chref.Ship.Name + "''.";
						Link.(attrL).go = "TransferGoodsTo_" + chref.id;
					}
				}
				
				Link.l99    = "� ���������"+ GetSexPhrase("","�") +", ������ �� �����.";
				Link.l99.go = "exit";
			}
			else // ������� ����
			{
				dialog.text = NPCharRepPhrase(npchar, pcharrepphrase("������ ����? � ��� �� ���� �������? � ����� ��� ���!",
					"������� ��������, ���� �� �������� ����! � ����� ��� ������ �������!"),
					pcharrepphrase("� �� ���� ������ ������� � �����, ������� " +GetFullName(pchar)+ ". �������, ��� �� ''������� ���������''?",
					"�������, ������� ������� ����� � �����. ������������ ������� � ���������."));
				link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"����� ������������!!! �����, ������ �������, ��� ��������!",
					"� �� �����"+ GetSexPhrase("","�") +" ��� �������� " +GetFullName(npchar)+ ", ������� �� ������ ������� �������."),
					pcharrepphrase("���. ��� ������� ���������� Black Pearl. ��� ��� �� �������? ��-��! �����!",
					"������� �� �����, ����������� �� ������������."));
				link.l1.go = "exit";
			}
			break;
			
		case "TransferGoods_2": // ��� ��� �� ���������, ���� ������� ��� ���� (������� �������, � ������� ���� �� ����������)
			dialog.text = LinkRandPhrase("�� ��� ���, ���, �� ����� ������� ����� ������� ������?",
				"��� �� ����� ������� ����� ������ �������?",
				PChar.name + ", ��� � ���� ������ ������� ����� ����������� ��������?");
				
			for(i=0; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(PChar, i);
				if(cn > 0)
				{
					chref = GetCharacter(cn);
					if(!GetRemovable(chref)) continue; // ���� ��������� - ����������
					
					attrL = "l"+i;
					Link.(attrL)    = "�� " + XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " ''" + chref.Ship.Name + "''.";
					Link.(attrL).go = "TransferGoodsTo_" + chref.id;
				}
			}
			
			Link.l99    = "� ���������"+ GetSexPhrase("","�") +", ������ �� �����.";
			Link.l99.go = "exit";
			break;
			
		case "TransferGoods_Start":
			chref = CharacterFromID(NPChar.CharToTransferGoodsID);
			
			iQuantityGoods = TransferGoods_CalculateWeight(chref);
			
			if(GetCargoFreeSpace(chref) >= iQuantityGoods)
			{
				if(TransferGoods_StartTransfer(chref, NPChar.City) != 0)
				{
					dialog.text = LinkRandPhrase("��� ������! �� ��������� ������� �������� ��������.", 
						"�� ���, ����� ������ ��������� �� ��������� �������.",
						"���, �������� ������ � ���� ���������� ������� ��������.");
					link.l1 = "�������. � ���� ������� ����� ����.";
					link.l1.go = "exit";
					WaitDate("", 0, 0, 0, 1, 0); // ������ �����
				}
				else
				{
					dialog.text = LinkRandPhrase("�������, ���� �����, ������� �������� ��� ��������, ��� ���� �� ����� ���������� ���� �����!", 
						"���, ���� ����� ��� ������������ �� ��������� ���� �������!",
						"���, ������ ������� � ������������ �� ���������, ��� ��� ���� ����� �� ��� ��� ������������.");
					link.l1 = "��, �����.";
					link.l1.go = "exit";
					link.l2 = "�������, ����� ������� ������ �������.";
					link.l2.go = "TransferGoods_2";
				}
			}
			else
			{
				dialog.text = LinkRandPhrase("������� ���, ������� ������ �� ���� ��� ������� �� ������.", 
					"���, ������� ������ � ���� ����� ������� �� ����������!",
					"�������, ������� ������ �� ���������� � ���� ����� �������!");
				link.l1 = "��, �������. ����� ������� ������ �������.";
				link.l1.go = "TransferGoods_2";
				link.l2 = "� ��� �������"+ GetSexPhrase("","�") +"... �� ����� ������ ��������.";
				link.l2.go = "exit";
			}
			break;
		// <-- ����������� �������

		case "trade_1":
            ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
			    NextDiag.CurrentNode = NextDiag.TempNode;
			    DialogExit();
			    Pchar.PriceList.StoreManIdx = rColony.index; // boal 27.02.05
			    LaunchStore(sti(rColony.StoreNum));
			}
			else
			{
			    dialog.text = NPCharRepPhrase(npchar, pcharrepphrase("������ ����? � ��� �� ���� �������? � ����� ��� ���!",
				                                                     "������� ��������, ���� �� �������� ����! � ����� ��� ������ �������!"),
													  pcharrepphrase("� �� ���� ������ ������� � �����, ������� " +GetFullName(pchar)+ ". �������, ��� �� ''������� ���������''?",
													                 "�������, ������� ������� ����� � �����. ������������ ������� � ���������."));
				link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"����� ������������!!! �����, ������ �������, ��� ��������!",
				                                                 "� �� �����"+ GetSexPhrase("","�") +" ��� �������� " +GetFullName(npchar)+ ", ������� �� ������ ������� �������."),
												  pcharrepphrase("���. ��� ������� ���������� Black Pearl. ��� ��� �� �������? ��-��! �����!",
												                 "������� �� �����, ����������� �� ������������."));
			    link.l1.go = "exit";//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			}
		break;

		case "storage_0":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar, "Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 
			{
				dialog.text = "� ��� �� ������ ��� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + ".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
				{
					link.l1 = "������, ������ ������ ������.";
					link.l1.go = "storage_3";
				}
				else
				{
					link.l1 = "� ����� �������.";
					link.l1.go = "exit";
				}
			}		
			else
			{
				dialog.text = "���������.";
				link.l1 = "�������.";
				link.l1.go = "storage_2";
			}
			link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			link.l2.go = "exit"; 						
		break;
		
		case "storage_01":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "��, � ���� ���� ����������� ������� - ����������� 50000 �. �� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + " � ����� � ����� ���������� ����������� ����� �������. "+
				"��� �������� ������ �� ������, ������ �� ����������� � ������ � ���������. ��, ��� �������? ������ ��-�... ������ �� ����� ������� �����.";	
			link.l1 = "�������. ���� � ��� ���������? � ��� ��� ����� ������ ������?";
			link.l1.go = "storage_1";
			link.l2 = "�� ���, � ������ ��� �������"+ GetSexPhrase("","�") +". ����� ����� � �����������...";
			link.l2.go = "exit";
		break;
		
		case "storage_1":
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar); 
			dialog.text = "��� � ��� ������ - ������ �� ����� �����. � ������� ����!";
			if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))
			{
				link.l1 = "���� ��... �������������. ������� ���� ������ - � ������� ���� �����.";
				link.l1.go = "storage_11";
			}
			else
			{
				link.l1 = "���� ��... �������������. ������ ������ �������..";
				link.l1.go = "exit";
			}
		break;
		
		case "storage_11":
			AddMoneyToCharacter(pchar, -makeint(NPChar.MoneyForStorage)); 
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			NPChar.Storage.Activate = true;
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
				
		case "storage_2":			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;
		
		case "storage_3":			
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.MoneyForStorage = GetStoragePriceExt(NPChar, pchar);
			NPChar.Storage.MoneyForStorage = NPChar.MoneyForStorage;
			SaveCurrentNpcQuestDateParam(NPChar, "Storage.Date");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStorage(sti(rColony.StoreNum));			
		break;		

		case "storage_04":
			dialog.text = "������� ������������? ��-��-��, ����� ������������ �����, ����� �������� �������. ������ - ������ ����� �� ������� ��� �� ��������� �������� �����.";
			link.l1 = "� �� ������"+ GetSexPhrase("","�") +" - ����������. ��� �� ����������� ��� ������� �� �������� �������? ������ ������ ������� ����������.";
			link.l1.go = "storage_4";
			link.l2 = "����� �� ���������, ��������? �����, ������� ���� �� �����.";
			link.l2.go = "exit";
		break;
		
		case "storage_4":
			NPChar.MoneyForStorage = GetNpcQuestPastMonthParam(NPChar,"Storage.Date") * sti(NPChar.Storage.MoneyForStorage); 
			if(sti(NPChar.MoneyForStorage) > 0) 			
			{
				dialog.text = "� ��� �� ������ ��� " + FindRussianMoneyString(sti(NPChar.MoneyForStorage)) + ".";
				if(sti(pchar.money) >= sti(NPChar.MoneyForStorage))			
				{
					link.l1 = "������.";
					link.l1.go = "storage_5";
				}
			}
			else
			{
				dialog.text = "��������� ���� ����� � � ������ �����.";
				link.l1 = "������.";
				link.l1.go = "storage_6";
			}
		break;
		
		case "storage_5":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			AddMoneyToCharacter(pchar, -sti(NPChar.MoneyForStorage)); 
			NPChar.Storage.NoActivate = true;
			DeleteAttribute(NPChar,"Storage.Activate");
			DialogExit();
		break;
		
		case "storage_6":
			SetStorageGoodsToShip(&stores[sti(rColony.StoreNum)]);
			DeleteAttribute(NPChar,"Storage.Activate");
			NPChar.Storage.NoActivate = true;
			DialogExit();
		break;

	case "items":
			NPChar.Merchant = true;
			if (npchar.quest.item_date != lastspeak_date)
			{
				NPChar.Merchant.type = LinkRandPhrase("armourer", "potion", "veteran");
				NPChar.money = TRADER_MIN_MONEY + rand(TRADER_MAX_MONEY);
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar, 0);
		break;

		case "business":
			iTest = 0;	
				
//Jason --> ----------------------------------����-����� ���������� ���������------------------------------------
			if (!CheckAttribute(pchar, "questTemp.Shadowtrader") && sti(npchar.nation) != PIRATE && sti(pchar.rank) < 6 && drand(2) == 0) 
			{
				dialog.text = "�������, � ���� ��������� ��� �� ����� ������. �� �������� ���?";
				link.l1 = "��� � ���� ��� ������?"; 
				link.l1.go = "Shadowtrader_begin";
				break;
			}
			
			if (CheckAttribute(pchar, "questTemp.Shadowtrader"))
			{
				if(pchar.questTemp.Shadowtrader == "begin" && GetNpcQuestPastDayParam(npchar, "Shadowtrader_date") < 5 && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store")
				{
					dialog.text = "�������, �������, ��� ��������� ��� �������. ������, ����� "+pchar.questTemp.Shadowtrader.Guardername+" �����, � ���� ����������� ���� ���� ������� ���������.";
					link.l1 = "��... �� ������� �� ������������, �� ��� �������, ��� � ��� �����-�� ��������. �����, ���������� - � ����� � ����� ��� ������?"; 
					link.l1.go = "Shadowtrader_fort";
					break;
				}
				if(CheckAttribute(pchar, "questTemp.Shadowtrader.Trouble") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store")
				{
					dialog.text = "�� ���? �� �������� ��� ������?";
					link.l1 = "�� �������. ��������� �������� �������� ����� �� ������ - ����, ��� �������� � ����� ������ ������������, ����� ��������� ������ ����������� �����-���� ��������."; 
					link.l1.go = "Shadowtrader_trouble";
				pchar.quest.ShadowtraderTimeFort_Over.over = "yes";
					break;
				}
				if(CheckAttribute(pchar, "questTemp.Shadowtrader.End.Fort") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store" && GetQuestPastDayParam("pchar.questTemp.Shadowtrader.EndFort") > 0)
				{
					dialog.text = "� ��� ������ ������� - ������� ����� ������ ����� ���������� �������� ����� ��������������� � ���� ����������. ��������� ���� ���� ���� ���������� ��������. ������, ������ �� ����� ������ �� ������ ���������\n��������� ��������� ��� � ����� ���� � ���� ����������� - ������� ��� ��������! �� ��������� ��� ��������! ���, �������� ������� - 15 000 ����. �� ������ ������ ����! ������ � ������� ��������� ��-����������!";
					link.l1 = "�� �� �� ���. ��� ���� ��������."; 
					link.l1.go = "Shadowtrader_complete";
					break;
				}
				if(CheckAttribute(pchar, "questTemp.Shadowtrader.End.Escape") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store")
				{
					dialog.text = "��, ��� ���������� ��������, " + pchar.name + "?";
					link.l1 = "� �������� ������ ����������. ������ �� �� ����� ��� �������� - ��� �������... ������� ��� �������� ���� ������. ��� ''�������'' ��������� � ���� � ��������� ����� - ��� ������ � �������� �������, ������� ����. ������ - ������ �������, ������ - ���������� ������� ����."; 
					link.l1.go = "Shadowtrader_Escape_complete";
					break;
				}
				if(CheckAttribute(pchar, "questTemp.Shadowtrader.End.Free") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store")
				{
					dialog.text = "� ��� ������ ������� - ������� ����� ������ ���������� � ����� �� ����� ���������� �������� ����� ���������������. ��� ������� ������� ��������. ������������ ������, " + pchar.name + ", � ���������� ����! ���, �������� ������� - 15 000 ����. �� ������ ������ ����! ������ � ������� ��������� ��-����������!\n������������� ��� ����������� - �� �������... ����, ����� ���� ���� ���������?";
					link.l1 = "���. �� �� ��� ������� �� ������� ���� ��������� � ����� ������. �����, ������ �� ��� �� ���������� ���������� �������� ���� �� ����� �������."; 
					link.l1.go = "Shadowtrader_complete";
					break;
				}
				if(CheckAttribute(pchar, "questTemp.Shadowtrader.End.Kill") && NPChar.location == pchar.questTemp.Shadowtrader.City + "_store")
				{
					dialog.text = "� ��� ������ ������� - ������� ����� ������ ���������� � ����� �� ����� ���������� �������� ����� ���������������. ��� ������� ������� ��������. ������������ ������, " + pchar.name + ", � ���������� ����! ���, �������� ������� - 15 000 ����. �� ������ ������ ����! ������ � ������� ��������� ��-����������!\n������������� ��� ����������� - �� �������... ����, ����� ���� ���� ���������?";
					link.l1 = "��. �� �������� ��������� �� ������ ����������. ����� �� ��� �� �����������."; 
					link.l1.go = "Shadowtrader_complete";
					break;
				}
			}
			//<-- ����-����� ���������� ���������
	
			//Jason --> ��������� ������������ �����������
			/*if (drand(3) == 1 && !CheckAttribute(pchar, "GenQuest.Contraoffer.Trader") && !CheckAttribute(pchar, "GenQuest.Contraoffer.Slaves.Yes") && sti(npchar.nation) != PIRATE && 7-sti(RealShips[sti(pchar.ship.type)].Class) > 0) 
			{
				if (!CheckAttribute(npchar, "Contraoffer") || GetNpcQuestPastDayParam(npchar, "Contraoffer") >= 30) 
				{
					dialog.text = "�! �� ����� �������, �������. � �� ����� ��������� ��� ������� ��� ���� ������.";
					link.l1 = "������� ���������."; 
					link.l1.go = "Contraoffer";
					break;
				}
			}
		
			if (CheckAttribute(pchar, "GenQuest.Contraoffer.Trader") && NPChar.location == pchar.GenQuest.Contraoffer.Trader.City + "_store") 
			{
				dialog.text = "����������� ��� ������, �������.";
				link.l5 = "� ������ ��� �����."; 
				link.l5.go = "Contraoffer_check";
			}
			
			if (!CheckAttribute(pchar, "GenQuest.Contraoffer.Slaves") && sti(npchar.quest.Contraoffer.chance) == 2 && GetNpcQuestPastDayParam(npchar, "Contraoffer") >= 30) //��������� ������� �� ��� ����, ��� ''��������''
			{
				dialog.text = "�! �� ����� �������, �������. ��� ����� ��������� ������.";
				link.l5 = "������� ���������."; 
				link.l5.go = "Contraoffer_slaves";
				break;
			}
			
			if (CheckAttribute(pchar, "GenQuest.Contraoffer.Slaves.Yes") && NPChar.location == pchar.GenQuest.Contraoffer.Slaves.City + "_store") 
			{
				dialog.text = "����������� ��� ������, �������.";
				link.l5 = "� ������ ����� �����."; 
				link.l5.go = "Contraoffer_slaves_check";
			}*/
			// <-- ��������� ������������ �����������
	
			//Jason --> ��������� ����������� ���
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_store" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l16 = "��������, �� ��� �������� ������ ��������... ���� ����� ��� �������, ����� �� ��������� ������ "+pchar.GenQuest.Device.Shipyarder.Type+"?";
				link.l16.go = "Device_Trader";
			}
			// <-- ��������� ����������� ���
			
			//Jason --> ��������� ����� ��� �������
			if (!CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && !CheckAttribute(npchar, "quest.Sunplace") && sti(npchar.nation) != PIRATE && sti(pchar.rank) < 20 && drand(4) == 4) 
			{
				dialog.text = "�������, � ���� ��������� ��� ������� ��� ���� ������. �� �� ���������� � ������ �������.";
				link.l1 = "���������. �������������, ��� ��� � ���?"; 
				link.l1.go = "Sunplace_begin";
				break;
			}
			
			if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "complete" && npchar.location == pchar.GenQuest.Sunplace.Trader.City + "_store") 
			{
				dialog.text = "�������, ��� ��� ������. � ��� � �����, ��� �� ��������� ��� ������� ���������� "+pchar.GenQuest.Sunplace.Trader.Enemyname+".";
				link.l1 = "���! ��� ���. "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Sunplace.Trader.ShipType), "Name")))+" "+pchar.GenQuest.Sunplace.Trader.ShipName+" � ���� - " + GetGoodsNameAlt(sti(pchar.GenQuest.Sunplace.Trader.Goods))+ ", ����� ������ ���������� �� �����������."; 
				link.l1.go = "Sunplace_complete";
				break;
			}
			
			if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "complete_murder" && npchar.location == pchar.GenQuest.Sunplace.Trader.City + "_store") 
			{
				dialog.text = "�������, �������... ����� �� ��� �����? � �� ������ ����� ���� �������� ��� �����! ��������� ����, ������ �� ��� ���� �� ������ ��������� ��������...";
				link.l1 = "���! ��� �� �������������, " + npchar.name + "? ����� ������� - �� ��� ������ ������� �� �������� ���!"; 
				link.l1.go = "Sunplace_complete_murder";
				break;
			}
			// <-- ��������� ����� ��� �������
			
//navy -->
			//����� ���
			iTmp = CheckAvailableTaskForNPC(NPChar, PGG_TASK_WORKONSTORE);
			if (iTmp != -1)
			{
				dialog.text = "���� � ���� ���������, �� " + GetFullName(&Characters[iTmp]) + " ��� ������ ��������� �� ��� ����.";
				link.l1 = "�� ��� �� ��������! �����, ����� �������.";
				link.l1.go = "exit";
				break;
			}
//navy <--
			dialog.text = NPCharRepPhrase(npchar,"����?! ���������� ��� �� �������!","� ��� ������. � ����� ���� ���� ����?");
            ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
            if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
    			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
    			{
    				if (pchar.CargoQuest.TraderID == npchar.id )
    				{
    					link.l1 = RandPhraseSimple("� ����� ����� ������� ���� ��� ������ ��������.", "��� ������� ����������� ��� �������� ����� � ��� �������. ����� ��� ���������.");
    					link.l1.go = "generate_quest_2";
    				}
    				else
    				{
                        if (!CheckQuestAttribute("generate_trade_quest_progress",  "failed") && pchar.CargoQuest.GiveTraderID == npchar.id && GetNationRelation2MainCharacter(sti(characters[GetCharacterIndex(pchar.CargoQuest.TraderID)].nation)) == RELATION_ENEMY)
                        {
                            link.l1 = "� ���������, � ��������"+ GetSexPhrase("","�") +" ���������� �� ������ ������������. ������������ ���������� �� ��������� ��� ��������� ����.";
            				link.l1.go = "generate_quest_cannot_done";
                        }
                        else
                        {
                            if (rand(1) == 1)
                            {
                                link.l1 = RandPhraseSimple("� ���� ���������� ��� ������������ ��� ����� ��� ��������� �����.",
								                           "� ���� ���������� �������, � � ���� ��������� ����� ����, ���� ������ �� ���������.");
            				    link.l1.go = "generate_quest_not_closed";
        				    }
    				    }
    				}
    			}
    			else
    			{
    				link.l1 = "�� ������ ������������ �����, " +GetAddress_FormToNPC(NPChar)+ "? � ���� �������� ������� � ������� �������.";
    				link.l1.go = "generate_quest";
    			}
    			// --> �� ��������� ���������
    			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
    			{
	                link.l3 = pcharrepphrase(RandPhraseSimple("��, �������"+ GetSexPhrase("��","���") +" � ����... ��� ���, ��������, �������� ������ ����� �����.",
	                                                          "�� ���, ������ ����, ����� ������� ���� ���� ��������."),
	                                        RandPhraseSimple("� �����"+ GetSexPhrase("","�") +" �� �������� � ���� ���������� �������.",
	                                                         "������� ������� ���������� �������, ��� ���� � ��� ������������."));,
	
	                link.l3.go = "LoanForAll";
                }
				//����� ���� - �� ����� � ����� �������
  				if (CheckAttribute(pchar, "GenQuest.Intelligence") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "") 
				{
					link.l4 = RandPhraseSimple("� ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".", 
						GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + " ������� ���� � ���. � ����"+ GetSexPhrase("��","��") +" ���-��� �������...");
					link.l4.go = "IntelligenceForAll";
				}

				// ----------------- ����� ��������� ������ ��������, ����� ����� -----------------
				if (pchar.questTemp.BlueBird == "weWon" && pchar.questTemp.BlueBird.traiderId == npchar.id)
				{
					link.l1 = "���� ��� ���������, ��� ��� ������� ���������� � ����� ����������. ���� ''������ ��������'' �� ����� ����� ��������� ���������. � ������"+ GetSexPhrase("","�") +" �� ����������� ���������.";
					link.l1.go = "RBlueBirdWon";
				}
				if (pchar.questTemp.BlueBird == "DieHard" && pchar.questTemp.BlueBird.traiderId == npchar.id)
				{
					link.l1 = "����"+ GetSexPhrase("��","��") +" ��� ��������, ��� ��� �� ������� �������� ���� ''������ ��������''. � ������ ���, ��� ���...";
					link.l1.go = "RBlueBirdDieHard";
				}
				if (pchar.questTemp.BlueBird == "returnMoney" && pchar.questTemp.BlueBird.traiderId == npchar.id && sti(pchar.questTemp.BlueBird.count) > 0)
				{
					if (sti(pchar.questTemp.BlueBird.count) < 5)
					{
						link.l1 = "��� ��� ����� ��������? ��� ���������?";
						link.l1.go = "RBlueBird_retMoney_1";
					}
					else
					{
						link.l1 = "�� ��� �� ���������, �� ������� ������ ��� ��� ������ ������������ ������?";
						link.l1.go = "RBlueBird_retMoney_3";
					}
				}
				// ----------------- ����� ��������� ������ ��������, ����������� -----------------	
				
				//homo 25/06/06 �����
                link.l6 = pcharrepphrase(RandPhraseSimple("���������� ��� ��������� �������? ��� ����� ������� ��� ����� ����.",
                                                          "�� �������, ������ ��������, � ����� ��������, ��� ����� ����� �� ����?"),
                                        RandPhraseSimple("�������, ��� ������"+ GetSexPhrase("","�") +" � ���� ����� ��������. ��� ���������� � ����� �����?",
                                                         "��, ��������, ������ ��� ��������� �������? ��� ������� ���������?"));,

    		    link.l6.go = "rumours_trader";

				// ugeen --> ����� ������� ��� ��
				if(CheckAttribute(NPChar,"Storage") && Pchar.location.from_sea == "Pirates_town")
				{
					if(CheckAttribute(NPChar,"Storage.Activate"))
					{
						link.l7 = "��������� ���� � �������. � ���� ��������� �� ��������� ������ ������.";
						link.l7.go = "storage_0";
						link.l8 = "� �����"+ GetSexPhrase("","�") +" ���������� �������. �� ��� ������ ��� ����������.";
						link.l8.go = "storage_04";
					}
					else
					{
						if(!CheckAttribute(NPChar,"Storage.NoActivate"))
						{
							link.l7 = "���������� ���������, �� ��� �������� ��������� ��������� � ������ �� ������?";
							link.l7.go = "storage_01";
						}	
					}
				}				
				// <-- ugeen
				// Jason --> ����� ������ �� ����� ���������
				if(CheckAttribute(pchar, "GenQuest.FindFugitive") && sti(NPChar.nation) == PIRATE)
				{
					link.l8 = "��������, � ������� ����� ������ ����������, "+pchar.GenQuest.FindFugitive.Name+" ��� �����. � ������� ����-����� ��� �������, ��� �� ��������� ������ � ���� ���������. �� �������� ����� ��������?";
					link.l8.go = "FindFugitiveSt";
				}
				//<-- ����� ���������
				
				// <-- homo
				link.l99 = "�������, ������ �� �� ����������.";
    			link.l99.go = "no_quests";
			}
			else
			{
                link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"� �������"+ GetSexPhrase("","�") +" ������� �� ������ ������� �������. ����� �������!", "����� ���� ��������, " +GetFullName(npchar)+ ", � ����� �����. ��� ������� ��� �� ������� � �����."), pcharrepphrase("������! ��� ������� �� ��������� ������� ��� ��������! ����� �����!", "��������, � ����"+ GetSexPhrase("��","��") +" ��������� ��������� ���� ������� � �����!"));
                link.l1.go = "exit";
    			// --> �� ��������� ���������
    			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
    			{
	                link.l3 = pcharrepphrase(RandPhraseSimple("��, �������"+ GetSexPhrase("��","���") +" � ����... ��� ���, ��������, �������� ������ ����� �����.",
	                                                          "�� ���, ������ ����, ����� ������� ���� ���� ��������."),
	                                        RandPhraseSimple("� �����"+ GetSexPhrase("","�") +" �� �������� � ���� ���������� �������.",
	                                                         "������� ������� ���������� �������, ��� ���� � ��� ������������."));,
	
	                link.l3.go = "LoanForAll";
                }
				//����� ���� - �� ����� � ����� �������
  				if (CheckAttribute(pchar, "GenQuest.Intelligence") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "") 
				{
					link.l7 = RandPhraseSimple("� ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".", 
						GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + " ������� ���� � ���. � ����"+ GetSexPhrase("��","��") +" ���-��� �������...");
					link.l7.go = "IntelligenceForAll";
				}	
			}
		break;
		
		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date || bBettaTestMode)
			{
				npchar.quest.trade_date = lastspeak_date;
				//�������� ������������ ��� ������ ��������
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
					dialog.text = "���, �� �����! �� ������� ����, �� ��� ���, ���� �� ��������� � " + NationNameAblative(sti(NPChar.nation)) + ".";
					link.l1 = "� ����� ������, ��������.";
					link.l1.go = "exit";
				}
				else
				{
                    // �������� �� ���� ����������� -->
                    if (isBadReputation(pchar, 42))
                    {
                        dialog.text = RandSwear() + "�� ���� " + GetFullName(pchar)+ ", �� ��� ��? � ���� " +
                                      RandPhraseSimple("����� ������� �����","������� �� ������ �������") + ", � �� ���� ����� � ����� ����.";
						link.l1 = RandPhraseSimple("��... ����� �������� ��� ����������, � ��� ����� � ���� �������.",
						                           RandSwear()+ "��� ��, � ���� ���� ������� � ������������, "+GetFullName(npchar)+".");
						link.l1.go = "exit";
                        break;
                    }
                    // �������� �� ���� ����������� <--
                    int iTradeNation = GenerateNationTrade(sti(NPChar.nation));

					if (iTradeNation < 0)
					{
						dialog.text = NPCharRepPhrase(npchar, "��, "+GetAddress_Form(NPChar)+", �� �� ������� �������. ��������� ������.","������� ������. ��������, � ������ ��� �������� �����������.");
						link.l1 = "������, � ����� ������.";
						link.l1.go = "exit";
					}
					else
					{
                        int storeMan = findStoreMan(NPChar, iTradeNation);
                        if (storeMan > 0)
                        {
                            //��������� ������/�������
							iTradeGoods = GOOD_COFFEE + drand(sti(GOOD_PAPRIKA - GOOD_COFFEE)); //Jason
    						//��������� ��������� ����� (��� ���� ������ ��������� �� ������� ���� 100 ������ ���������� �����
    						RecalculateSquadronCargoLoad(pchar); // fix �������� �����
    						iQuantityGoods = GetSquadronFreeSpace(pchar, iTradeGoods);
							if (sti(Goods[iTradeGoods].Weight)/sti(Goods[iTradeGoods].Units)*sti(iQuantityGoods) > 1500) iQuantityGoods = makeint(1500/(sti(Goods[iTradeGoods].Weight)/sti(Goods[iTradeGoods].Units))); //Jason: ������ 1500 ����� �� ����� - ������� ������ ������ ����� ��
    						if (iQuantityGoods < 100)// ��� � ��. ������
    						{
    							dialog.text = NPCharRepPhrase(npchar, "� ���� ������ �������� �� ���������� ���� ����, ������� ������ �� �����.","� ���������, ������� "+GetFullName(pchar)+", ��� �������� ����� ��� ����� ����� ������������� �������, ��� ���.");
    							link.l1 = NPCharRepPhrase(npchar, "� ���� ��������� �������, �� � ����� ���� �����. �� ��������.","� ��� �������, ������ ������ �����. ��������.");
    							link.l1.go = "exit";
    						}
    						else
    						{
    							iQuantityGoods = iQuantityGoods - rand(makeint(iQuantityGoods/3)) - 10;
    							iMoney = makeint((iQuantityGoods * sti(Goods[iTradeGoods].Weight) / sti(Goods[iTradeGoods].Units)) * (4+rand(3) + GetSummonSkillFromNameToOld(pchar, SKILL_COMMERCE)) + 0.5);

    							pchar.CargoQuest.iTradeGoods = iTradeGoods;
    							pchar.CargoQuest.iQuantityGoods = iQuantityGoods;
    							pchar.CargoQuest.iMoney = iMoney;
    							pchar.CargoQuest.iTradeNation = iTradeNation;
    							pchar.CargoQuest.iDaysExpired = 25 + rand(5);
    							
    							pchar.CargoQuest.iTradeColony = Characters[storeMan].city;
    							pchar.CargoQuest.iTradeIsland = GetIslandByCityName(Characters[storeMan].city);
    							pchar.CargoQuest.TraderID     = Characters[storeMan].id;
    							pchar.CargoQuest.GiveTraderID = NPChar.id;
                                SaveCurrentQuestDateParam("CargoQuest");
    							string sNation = XI_ConvertString("Colony"+Characters[storeMan].city);
                                sTemp = "";
                                if (pchar.CargoQuest.iTradeIsland != Characters[storeMan].city)
								{
                                    sTemp = ", ��� �� " + XI_ConvertString(pchar.CargoQuest.iTradeIsland+"Dat");
                                }
                                dialog.text =  "�! � ��� ��� ����� ��� ��������� ��� �� �������� ��� ����� ������. ���� � ���, ��� ��� ����� ��������� ���� " +
                                               GetGoodsNameAlt(iTradeGoods)+ " � ���������� " + FindRussianQtyString(iQuantityGoods) + " � ����� " +
                                           sNation + sTemp + ", � ��� ����� �������. ���� �� ������� ������� ��� �� " +  FindRussianDaysString(makeint(pchar.CargoQuest.iDaysExpired)) +
                                           ", �� �� �������� �� ����� �������� " +
                                           FindRussianMoneyString(iMoney) + " ��������������. �� ���?";
    							link.l1 = "�����, ��� � ������"+ GetSexPhrase("��","��") +".";
    							link.l1.go = "exit_trade";
    							link.l2  = "�� �����, ��� ��� ��� ��������.";
    							link.l2.go = "exit";
    						}
                        }
                        else
                        {
                            dialog.text = "������������ ���������� � ���������� �� ��������� ��� ���������. "+
                                          XI_ConvertString(NationShortName(sti(NPChar.nation))+"hunter") + " �� ������ �� �����, � ������� ������� ������ � ����.";
    						link.l1 = "�! �������. ����� ��������";
    						link.l1.go = "exit";
                        }
					}
				}
			}
			else
			{
				dialog.text = NPCharRepPhrase(npchar, "����� ����������, ��� � ���� ������� �� ������ ���������!","� �� ��� ������� ��� �������, ��� � ���� ������ ��� ��� ���.");
				link.l1 = NPCharRepPhrase(npchar, "�� ������ ������������� ������, ��� � ����� ���� ����������!", "�, ��������.");
				link.l1.go = "exit";
			}
		break;

		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.text = RandSwear() + "�� ��������� � ���������� ��� ���� ������� ������, �� ��������? ��� �������� ���������� ����� ��������. ��������.";
				link.l1 = "�������� ����, �� � ��� ������"+ GetSexPhrase("","�") +". ��������, ���� � ������ ���� ������, ��� ����������� ��� ������� ���������?";
				link.l1.go = "generate_quest_failed";
				link.l9 = "����� ��������.";
				link.l9.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", -1);
			}
			else
			{
                iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
                iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);
                
                dialog.text = "�����! � ��� ����� ����. �� ������ ��������� ��� ���� " +
                GetGoodsNameAlt(iTradeGoods) + " � ���������� " + FindRussianQtyString(iQuantityGoods) + " � �������� �� ��� " +
                FindRussianMoneyString(sti(pchar.CargoQuest.iMoney)) + ".";
				link.l1 = "������ ���.";
				link.l1.go = "generate_quest_ready";
			}
		break;
		
		case "generate_quest_ready":
            iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
            iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);
            // ���� �������� ��� �� ����� -->
            if (rand(8) == 1 && sti(Goods[iTradeGoods].Cost) <= 44 && GetQuestPastDayParam("CargoQuest") > 5)
            {
                dialog.text = RandSwear() + "� �������� ���������� ����� ����, "+GetAddress_Form(NPChar)+
                              ". ���� � ���, ��� � " + RandPhraseSimple("� ��������������� ��������� � �� ����� �������� ���� ������"," ��� ���� ���� ���� � ������ ����� �� ����� �������� ����")+
                              ". � �������� ������ ������ ������ � ������� ��� ���� ������������ ���� ����.";
				link.l1 = RandSwear() + RandPhraseSimple("� � �����"+ GetSexPhrase("","��") +" ���� ������ ���� �� ���� ��������!!! � ��� ����� ���� ��-�� ���� ����"+ GetSexPhrase("","�") +"!",
                                                         "�� ������� ���� � ����������� ���������, � ��� �������� �����������.");
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", 2);
				AddCharacterExpToSkill(pchar, "Sailing", 60);
				AddCharacterExpToSkill(pchar, "Leadership", 20);
				AddCharacterExpToSkill(pchar, "COMMERCE", 15);

				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
                
                AddQuestRecord("DELIVERY_TRADE_QUEST", "4");
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodGen", GetGoodsNameAlt(iTradeGoods));
			    AddQuestUserData("DELIVERY_TRADE_QUEST", "sTargetColony",XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony+"Dat"));
                CloseQuestHeader("DELIVERY_TRADE_QUEST");
                break;
            }
            // ���� �������� ��� �� ����� <--
			if (GetSquadronGoods(pchar, iTradeGoods) < iQuantityGoods)
			{
                iTmp = iQuantityGoods - GetSquadronGoods(pchar, iTradeGoods);
                dialog.text = "�� �������� �� ���� �����!! �������� �������� �������� ��������� ��� "
                              + FindRussianQtyString(iTmp) + " �����.";
				link.l9 = RandPhraseSimple("��, �������������. �������� ���������� ���������. ����� ��� ���.",
                                           RandSwear() +"����������� ����� ��������� ������ ����. � �������� ��������� � ����� ��� ���.");
				link.l9.go = "exit";
                AddQuestRecord("DELIVERY_TRADE_QUEST", "8");
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sHaveNotQty", iTmp);
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodGen", GetGoodsNameAlt(iTradeGoods));
			}
			else
			{
                dialog.text = "������������! ��� ���� �������, ������� "+GetFullName(pchar)+".";
				link.l1 = "������� � ���� ��������.";
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", 3);
				AddCharacterExpToSkill(pchar, "Sailing", 100);
				AddCharacterExpToSkill(pchar, "Leadership", 30);
				AddCharacterExpToSkill(pchar, "COMMERCE", 100);

				AddMoneyToCharacter(pchar, makeint(pchar.CargoQuest.iMoney));
				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
				RemoveCharacterGoods(pchar, makeint(pchar.CargoQuest.iTradeGoods), makeint(pchar.CargoQuest.iQuantityGoods));
				
                OfficersReaction("good");
                
                AddQuestRecord("DELIVERY_TRADE_QUEST", "2");
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodGen", GetGoodsNameAlt(iTradeGoods));
			    AddQuestUserData("DELIVERY_TRADE_QUEST", "sTargetColony",XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony+"Gen"));
                CloseQuestHeader("DELIVERY_TRADE_QUEST");
			}
		break;
		
		case "generate_quest_failed":
            iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
            iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);
            iMoney =  3*makeint(iQuantityGoods * sti(Goods[iTradeGoods].Cost) / sti(Goods[iTradeGoods].Units));
			dialog.text = "������... ����� � " + FindRussianMoneyString(iMoney) + " ��� ��� ������� ��� ������ �� ��������� ���� ������ �������� ������.";
			link.l1 = "���! ��� ��! �������, � �� ���� ������ ������ ������ ��� ������� �����! � ���� �� � ��� ����������!";
			link.l1.go = "exit";
            if (sti(pchar.Money) >= iMoney)
            {
    			link.l2 = "��� ��������� �����";
    			link.l2.go = "generate_quest_failed_2";
			}
            else
            {
                AddQuestRecord("DELIVERY_TRADE_QUEST", "7");
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sMoney", FindRussianMoneyString(iMoney));
    		    AddQuestUserData("DELIVERY_TRADE_QUEST", "sTargetColony",XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony+"Gen"));
            }
		break;
		
		case "generate_quest_failed_2":
            iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
            iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);
            iMoney =  3*makeint(iQuantityGoods * sti(Goods[iTradeGoods].Cost) / sti(Goods[iTradeGoods].Units));
			dialog.text = "������������. ������ � ���� �������� ����� ��������, ��� � ���� ��� �� ����� ����� ����.";
			link.l1 = "�������! � ��������� ��� � �� �������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", 10);
			AddCharacterExpToSkill(pchar, "Sailing", -100);
			AddCharacterExpToSkill(pchar, "Leadership", -50);
			AddCharacterExpToSkill(pchar, "COMMERCE", -100);

			AddMoneyToCharacter(pchar, -iMoney);
			pchar.quest.generate_trade_quest_progress = "";
			pchar.quest.generate_trade_quest.over = "yes";

            AddQuestRecord("DELIVERY_TRADE_QUEST", "5");
            AddQuestUserData("DELIVERY_TRADE_QUEST", "sMoney", FindRussianMoneyString(iMoney));
            AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodGen", GetGoodsNameAlt(iTradeGoods));
		    AddQuestUserData("DELIVERY_TRADE_QUEST", "sTargetColony",XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony+"Gen"));
            CloseQuestHeader("DELIVERY_TRADE_QUEST");
		break;
		
		case "generate_quest_not_closed":
            iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
            iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);

            dialog.text = "��. � ������, ��� �� ��� �� ��������� ������������� �� ����������� ������, � ��� ������� �����. �� ������ ���� ��������� ���� " +
            LanguageConvertString(iSeaGoods, "seg_" + Goods[iTradeGoods].Name)+ " � " + XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony) + ".";
			link.l1 = "��, �����! �� �����!";
			link.l1.go = "exit";
		break;
		
		case "generate_quest_cannot_done":
            dialog.text = RandSwear() + GetAddress_Form(NPChar) +", �� ��������� ����!!! �����, ����������� ���-�� ������ ��� ��������?";
			link.l1 = "������. � ���������� ��������� ����.";
			link.l1.go = "exit";
			link.l2 = "���. �� �����. �������";
			link.l2.go = "generate_quest_cannot_done_2";
			
		break;
		
		case "generate_quest_cannot_done_2":
		    iTradeGoods    =  makeint(pchar.CargoQuest.iTradeGoods);
            iQuantityGoods =  makeint(pchar.CargoQuest.iQuantityGoods);
            if (GetSquadronGoods(pchar, iTradeGoods) < iQuantityGoods)
			{
				dialog.text = "���������! �� �� ������� ��� ������ ���������� ������!! ��� ��������� ��� "
                              + FindRussianQtyString(iQuantityGoods - GetSquadronGoods(pchar, iTradeGoods)) + " �����.";
				link.l9 = RandPhraseSimple("��, �������������. �������� ���������� ���������.",
                                           RandSwear() +"����������� ����� ��������� ����. � ������� ����� � ����� ��� ���.");
				link.l9.go = "exit";
			}
			else
			{
                dialog.text = "�����, � �������... �������� ����� �������.";
    			link.l1 = "�������. � ��������� ��� � �� �������!";
    			link.l1.go = "exit";
    			ChangeCharacterComplexReputation(pchar,"nobility", -3);

				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
				RemoveCharacterGoods(pchar, makeint(pchar.CargoQuest.iTradeGoods), makeint(pchar.CargoQuest.iQuantityGoods));
                
                AddQuestRecord("DELIVERY_TRADE_QUEST", "6");
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodQty", FindRussianQtyString(sti(pchar.CargoQuest.iQuantityGoods)));
                AddQuestUserData("DELIVERY_TRADE_QUEST", "sGoodGen", GetGoodsNameAlt(iTradeGoods));
    		    AddQuestUserData("DELIVERY_TRADE_QUEST", "sTargetColony",XI_ConvertString("Colony"+pchar.CargoQuest.iTradeColony+"Dat"));
                CloseQuestHeader("DELIVERY_TRADE_QUEST");
            }
		break;

		//Jason --> -------------------����-����� ���������� ���������-------------------------------------------
		case "Shadowtrader_begin":
			pchar.questTemp.Shadowtrader = "true";
			pchar.questTemp.Shadowtrader.Guardername = GenerateRandomName_Generator(sti(npchar.nation), "man");
			dialog.text = "�� ����� �� �� ������� � �������, ����� ��� �������� �� ����� "+pchar.questTemp.Shadowtrader.Guardername+" � �������, ����� �� ��������� ������ �� ���? � �� �� ������ �� ���� ���������� �� ��������, � ���� ������ ����� � �������, ������ ��� �, �������, �� ���������� ������ ���� ���, ���� ��� ��������� � ���� �� ������.";
			link.l1 = "������ ��� ������, �������. ��� �����, ��� � � ��� ��������� � ������� ���������.";
			link.l1.go = "Shadowtrader_begin_1";
			link.l2 = "�� ���, ��������? � ����� �� �������� �� ����������? ��� �� ������� ��� ����, ��� �������, �� �����������.";
			link.l2.go = "exit";
		break;
		
		case "Shadowtrader_begin_1":
			dialog.text = "�������! ������� ���, ����� ��� ���� ����������. ��, �� �� ��� �� ��� ����� ���������...";
			link.l1 = "�� �����������. ������ � ��� � ��� ��������.";
			link.l1.go = "exit";
			pchar.questTemp.Shadowtrader.City = npchar.City;
			pchar.questTemp.Shadowtrader.nation = sti(npchar.nation);
			//������� ���������
			sld = GetCharacter(NPC_GenerateCharacter("ShadowGuarder" , "officer_7", "man", "man", 10, sti(npchar.nation), 5, true, "quest"));
			FantomMakeCoolFighter(sld, 20, 50, 50, "topor_013", "pistol_03", "grapeshot", 50);
			sld.name = pchar.questTemp.Shadowtrader.Guardername;
			sld.lastname = "";
			sld.dialog.FileName = "Quest\LineMiniQuests\ShadowTrader.c";
			sld.dialog.currentnode = "ShadowGuarder";
			sld.greeting = "pirat_common";
			LAi_SetSitType(sld);
			LAi_SetImmortal(sld, true);
			FreeSitLocator(pchar.questTemp.Shadowtrader.City + "_tavern", "sit_front1");
			ChangeCharacterAddressGroup(sld, pchar.questTemp.Shadowtrader.City + "_tavern", "sit", "sit_front1");
			SaveCurrentNpcQuestDateParam(npchar, "Shadowtrader_date");
		break;
		
		case "Shadowtrader_fort":
			dialog.text = "������? ��, �������, ��� ������������� ����� ���� ������. �� ����� �� �� �� ������� ��� ��� ������ ���������� ��� ����� �������? � ������� ��� �� ��� ���������� ���� 300 ����� - ��� � ��� �������, � �� ���� ��������� �� ��������.";
			link.l1 = "�� ��� �������. ������� ���� ���� ������.";
			link.l1.go = "Shadowtrader_fort_1";
			link.l2 = "���, ���������, � ���� ������ ��� ������� �� �������� ������.";
			link.l2.go = "Shadowtrader_fort_end";
		break;
		
		case "Shadowtrader_fort_1":
			dialog.text = "���, �������. ������������ �������� ��� �� ����� ������������ ��� � ��������� ��� �����!";
			link.l1 = "�� �����������, �� ������ � ������ ����.";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "letter_1");
			ChangeItemDescribe("letter_1", "itmdescr_letter_1"); // 240912
			pchar.questTemp.Shadowtrader.Tradername = GetFullName(npchar);
			SetFunctionTimerCondition("ShadowtraderTimeFort_Over", 0, 0, 1, false);
			pchar.questTemp.Shadowtrader = "current"
			pchar.questTemp.Shadowtrader.Fort = "true";
			AddQuestRecord("Shadowtrader", "1");
			AddQuestUserData("Shadowtrader", "sCity", XI_ConvertString("Colony"+pchar.questTemp.Shadowtrader.City+"Gen"));
		break;
		
		case "Shadowtrader_fort_end":
			dialog.text = "��� ��, �������� ��������� ����-�� �������. ��������, ��� ������ ��� �� ���, �������.";
			link.l1 = "�� ������. �� ��������!";
			link.l1.go = "exit";
			pchar.questTemp.Shadowtrader = "true";
		break;
		
		case "Shadowtrader_trouble":
			dialog.text = "�� ��� � ������? �� ����� �� ��� ��� ����� ��������������?! ��� ����? �� ��� ����� �� �� ����� �������, ���� ��� ����������� � ������!..";
			link.l1 = "����, ����, " + npchar.name + ", �����������, � �� ��� � ������ �� ���������������� ����� ��������. ������� ����... ���������� ��� �������, ��� � ��� �� ������������ - �����, � ����� ��� ������?";
			link.l1.go = "Shadowtrader_trouble_1";
			DeleteAttribute(pchar, "questTemp.Shadowtrader.Trouble");
		break;
		
		case "Shadowtrader_trouble_1":
			dialog.text = "��, �������! ��, �������� ���� 300 ����, � ���� �� ����� �� ������������... � �������� ���, �������, ������, �� �������, ��� �� ������� ��� ������. ��� ������ �� ����� �����, � �� ��-�� ��������� ��������������� � ���������� ��������, ������� ��� ���������.";
			link.l1 = "��������������?";
			link.l1.go = "Shadowtrader_trouble_2";
			AddMoneyToCharacter(pchar, 300);
		break;
		
		case "Shadowtrader_trouble_2":
			dialog.text = "������! ��� ������� ���� ������ ������ ���� �� ������! �� ���� ��� ���� ��� ������ - ��� ������������� ����������� �����, ������� �� ����������, ���� ���������, ��� ��������� � ����������. �� � ��������� ������� ��� ������� ���-�� � ������ ���������� �������, � ����� ��������� ����� ������� ������� �� ���������� ������ �����!\n� �� ���� ��������� ���� ����� ������� - ��� ���� ����� ������� ������ - � ���������� ���������: ������ �� ��� ��� ����������� �� ������� �� �������� - ��� �������� � ���� �����������.";
			link.l1 = "�� �� ������ ���� � ����� ������ ���������� � �������! ��� �� ����������� - ��������� �������� ����������.";
			link.l1.go = "Shadowtrader_trouble_3";
		break;
		
		case "Shadowtrader_trouble_3":
			dialog.text = "��������� ���������� ��������� �� ������ ����. ���������� ������� �����, � ��������� �� �����, ��� �������������� ������������ ���������� �������, ��� ������ ���, ��� �� ����� - � ��� �������� � �����\n�������, ����� �� ���� ����������? � � �����: � ������, ��� �� ��� �������� �����-�� ����������, �������� �������� ���� � ��������� �� ������, � ����� �� �������� �������� ��� ������ � ����� ������� ��������.";
			link.l1 = "��... ���� ������������� �����������������. ��� ����� ������ �� �������� - ������� ������� �� ���� ������ ������... ��, ��������, ��� �, �������, �� ���� � ����.";
			link.l1.go = "Shadowtrader_trouble_4";
		break;
		
		case "Shadowtrader_trouble_4":
			dialog.text = "�� ������... � ������� �� ��� ������ �����-�� ���������, ������� ����� ������, ��� ���� � ���� � ������ ��������� ���, �� ��� ������ ��� �������\n��� � � ����� ���������. "+pchar.questTemp.Shadowtrader.Guardername+" �������� ��� ��������, �� �� ������������, � � ���� ��� ��� ������� ����������� ���� ���� ������� ���������.";
			link.l1 = "�� ��... ���������� �������. ������, �� ���� ����� - � ����� �� ���� ��� ������. �� � ������, ��� �� ���������� - �������� ������ ������� ������ ����� �� ����������. �� ��������.";
			link.l1.go = "Shadowtrader_end";
			link.l2 = "�������. ����������, � ���� ����������� ��� ������...";
			link.l2.go = "Shadowtrader_trouble_5";
		break;
		
		case "Shadowtrader_trouble_5":
			dialog.text = "�� ���-���� ������ ���������� ��� ������? �� ��� �� �����������?";
			link.l1 = "� ��������� ����� ����� ������ ''�������'' �... �������� ������� ��� �� ������ ��� ����. � ���� ������ ��� ������� ���������� - �������� �����.";
			link.l1.go = "Shadowtrader_trouble_6";
		break;
		
		case "Shadowtrader_trouble_6":
			dialog.text = "�� ��������? �� ����������� ��� ������� �� ������ ����! ���� �� �������� ���� �� ���� ������� - ������, � ����� �� �������� � ����� �������.";
			link.l1 = "�� ��� ��, ��������, ��� �� ������������. � ��������� � �������.";
			link.l1.go = "exit";
			pchar.questTemp.Shadowtrader.seeksmugglers = "true";
			AddQuestRecord("Shadowtrader", "2");
			AddQuestUserData("Shadowtrader", "sCity", XI_ConvertString("Colony"+pchar.questTemp.Shadowtrader.City+"Gen"));
		break;
		
		case "Shadowtrader_end":
			pchar.questTemp.Shadowtrader = "true";
			CloseQuestHeader("Shadowtrader");
			DialogExit();
		break;
		
		case "Shadowtrader_Escape_complete":
			dialog.text = "��� ������? ������� � ������ ����� ��������� ��������? ������� ��� ��������! ��� ���� �������������� - 15 000 ����. � ����� � �� ���� ����� ����� ����� ����� ����������. ��� ��� �������!";
			link.l1 = "�� �� �� ���. ��� ���� ��������. � �� ������� ��� - � ���� ���� ��� ���������.";
			link.l1.go = "Shadowtrader_complete";
		break;
		
		case "Shadowtrader_complete":
			dialog.text = "�������� �� ��� ������, ������� - � ������ ���� ��� ��� ������.";
			link.l1 = "�������������! � ������ ��������� ����������� - ����! ����� ������� � ������� � ��������, " + npchar.name + "!";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Shadowtrader.End");
			AddMoneyToCharacter(pchar, 15000);
			pchar.questTemp.Shadowtrader = "complete";
			AddQuestRecord("Shadowtrader", "11");
			CloseQuestHeader("Shadowtrader");
		break;
	// <-- ����-����� ���������� ���������
	
//Jason --> ����-����� ���������� �����
		case "Wine_Trader":
			dialog.text = "�� ��� �� ����� ��������! ��� ���� ����� � ����������� - � ����������� ����� �� ������ � ����� �����������. ��, ������ ������ ����-��� �������. ��� ������, �������� - ����������, ������� ������, � �� �������, � �������!";
			link.l1 = "��� ��� ��! �� ��� �� �������...";
			link.l1.go = "Wine_Trader_1";
		break;
		
		case "Wine_Trader_1":
			dialog.text = "�� ����, ��� ��� ��� �������, �� � ���������: � ���� ������������ ���� ���. ����� �� ����� ������� ��� �������� ������.";
			link.l1 = "�� ��� ��... ����� �����������!";
			link.l1.go = "exit";
			AddQuestRecord("Wine", "5");
			AddQuestUserData("Wine", "sName", pchar.questTemp.Wine.Name);
			DeleteAttribute(pchar, "questTemp.Wine.Trader");
			pchar.questTemp.Wine.Repeat1 = "true";
		break;
		
		case "Wine_Repeat2":
			RemoveItems(PChar, "letter_1", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "��� � ����� � ��������� ��������. � �� ������ - ����� ��� ������, ������� �������� ������. ��-�, ��������� � ��������?";
			link.l1 = "�������!";
			link.l1.go = "Wine_Price";
			pchar.questTemp.Wine.wait = "true";
			DeleteAttribute(pchar, "questTemp.Wine.Repeat2");
			SetFunctionTimerCondition("Wine_wait", 0, 0, 7, false);
		break;
		
		case "Wine_Price":
			dialog.text = "������� ������� ��� �����? ��������� ����� ������� - 500 ����, ����������� ������ - 20 �������.";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "Wine_Qty";
			link.l2 = "� ���� ������ ������������ �����. � ����� �����.";
			link.l2.go = "Wine_Qty_exit";
		break;
		
		case "Wine_Qty":
			int iQty = sti(dialogEditStrings[4]);
			pchar.questTemp.Wine.Qty = sti(iQty);
			if (iQty < 20)
			{
				dialog.text = "� �� ��������� ��������� ���������, �������. �������, �� �������� � ������� ������.";
				link.l1 = "����� ��������... ������� ����������� ����������.";
				link.l1.go = "Wine_Price";
				break;
			}
			if (iQty > 70)
			{
				dialog.text = "� ���������, ������ ���������� � ���� ���.";
				link.l1 = "����... ������� ����������� ����������.";
				link.l1.go = "Wine_Price";
				break;
			}
			pchar.questTemp.Wine.Summ = sti(iQty)*500;
			dialog.text = ""+sti(iQty)+" �������? ������. � ��� " + FindRussianMoneyString(sti(pchar.questTemp.Wine.Summ))".";
			if (makeint(Pchar.money) >= sti(pchar.questTemp.Wine.Summ))
			{
				link.l1 = "����������, ��������.";
				link.l1.go = "Wine_Qty_1";
			}
			link.l2 = "� ���� ������ ������������ �����. � ����� �����.";
			link.l2.go = "Wine_Qty_exit";
		break;
		
		case "Wine_Qty_exit":
			dialog.text = "������, ������ ������������. ���� ����� � ���� ����� �� ������������.";
			link.l1 = "� ����� �������!";
			link.l1.go = "exit";
		break;
		
		case "Wine_Qty_1":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Wine.Summ));
			dialog.text = "���... �� �����. ��������� ���� �������.";
			link.l1 = "�������! ����� �������.";
			link.l1.go = "Wine_Qty_2";
		break;
		
		case "Wine_Qty_2":
			pchar.quest.Wine_wait.over = "yes";//����� ����������
			DeleteAttribute(pchar, "questTemp.Wine.wait");
			TakeNItems(pchar, "potionwine", sti(pchar.questTemp.Wine.Qty));
			PlaySound("interface\important_item.wav");
			Log_Info ("�� �������� ����");
			AddQuestRecord("Wine", "8");
			DialogExit();
		break;
		// <-- ����-����� ���������� �����
		
// Jason --> -------------------------��������� ������������ �����������----------------------------------------
		int iCGood, amount;
		case "Contraoffer":
			pchar.GenQuest.Contraoffer.Trader.Goods = SelectContrabandGoods(pchar);
			while (sti(pchar.GenQuest.Contraoffer.Trader.Goods) == -1)
			{
				pchar.GenQuest.Contraoffer.Trader.Goods = SelectContrabandGoods(pchar);
			}
			iCGood = sti(pchar.GenQuest.Contraoffer.Trader.Goods);
			pchar.GenQuest.Contraoffer.Trader.Qty = makeint(15*(sti(pchar.rank)+30)/(sti(Goods[iCGood].Weight)/sti(Goods[iCGood].Units))*(7-sti(RealShips[sti(pchar.ship.type)].Class)));//����������
			pchar.GenQuest.Contraoffer.Trader.Price = sti(Goods[iCGood].Cost)/sti(Goods[iCGood].Units)*3;//���� ������� ������
			pchar.GenQuest.Contraoffer.Trader.Summ = sti(pchar.GenQuest.Contraoffer.Trader.Price)*sti(pchar.GenQuest.Contraoffer.Trader.Qty);//�����
			pchar.GenQuest.Contraoffer.Trader.Days = 30+drand(20);//����
			pchar.GenQuest.Contraoffer.Trader.Chance = rand(5);//17% �����������, ��� ������� �������
			dialog.text = "��� ��� ���������� ������� ������ �� ������� ������ ������ - " + GetGoodsNameAlt(iCGood)+ ". �������� � ���, ��� ���� ����� � ����� ������� - �����������, � �� ������� ��� � �������� ��������� ������������ �� ����������\n��� ���� ����� ���� " + FindRussianQtyString(sti(pchar.GenQuest.Contraoffer.Trader.Qty)) + " ����� ������. �� ������� �� ��� ���������� �������� ��� ���? � ������ �������, �� " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.Price)) + " �� �������, ��� � ����� �������� " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.Summ)) + ". ��, � ����� ��� ����� �� �����, ��� ����� "+FindRussianDaysString(sti(pchar.GenQuest.Contraoffer.Trader.Days))+". ��� �� �������� ���?";
			link.l1 = "��... ������ ���������. � ��������!";
			link.l1.go = "Contraoffer_1";
			link.l2 = "������ �����������? ��� ��� �� ���������.";
			link.l2.go = "exit";
			SaveCurrentNpcQuestDateParam(npchar, "Contraoffer");
		break;
		
		case "Contraoffer_1":
			dialog.text = "������������! � ���, ��� �� �����������. ��� ��� � �������.";
			link.l1 = "����� ����!";
			link.l1.go = "exit";
			rColony = GetColonyByIndex(FindColony(npchar.city));
			SetNull2StoreGood(rColony, sti(pchar.GenQuest.Contraoffer.Trader.Goods));//����� �����
			pchar.GenQuest.Contraoffer = "begin";
			pchar.GenQuest.Contraoffer.Trader = "true";
			pchar.GenQuest.Contraoffer.Trader.City = npchar.city;
			pchar.GenQuest.Contraoffer.Trader.Nation = npchar.nation;
			iCGood = pchar.GenQuest.Contraoffer.Trader.Goods;
			ReOpenQuestHeader("Contraoffer");
			AddQuestRecord("Contraoffer", "1");
			AddQuestUserData("Contraoffer", "sGoods", GetGoodsNameAlt(iCGood));
			AddQuestUserData("Contraoffer", "sGoodQty", FindRussianQtyString(sti(pchar.GenQuest.Contraoffer.Trader.Qty)));
			AddQuestUserData("Contraoffer", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.Summ)));
			AddQuestUserData("Contraoffer", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Contraoffer.Trader.City+"Gen"));
			AddQuestUserData("Contraoffer", "sDays", FindRussianDaysString(sti(pchar.GenQuest.Contraoffer.Trader.Days)));
			SetFunctionTimerCondition("Contraoffer_Over", 0, 0, sti(pchar.GenQuest.Contraoffer.Trader.Days), false);
		break;
		
		case "Contraoffer_check":
			iCGood = sti(pchar.GenQuest.Contraoffer.Trader.Goods);
			amount = sti(pchar.GenQuest.Contraoffer.Trader.Qty) - GetSquadronGoods(pchar, sti(pchar.GenQuest.Contraoffer.Trader.Goods));
			if (amount > 0)
			{
				dialog.text = "���... ������ ��������? � ��� �� ��� ������� ��� ���������� ������!";
				link.l1 = "������, �������� �����...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "������� ���������. �� ������ ���� �������� ���� " + GetGoodsNameAlt(iCGood)+ " � ���������� " + FindRussianQtyString(pchar.GenQuest.Contraoffer.Trader.Qty) + ". ���?";
				link.l1 = "������ ���, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "Contraoffer_pay";
			}
		break;
		
		case "Contraoffer_pay":
			dialog.text = "������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Trader.Summ)) + ".";
		link.l1 = "�������! ������� � ���� ����� ����.";
		link.l1.go = "Contraoffer_complete";
		break;
		
		case "Contraoffer_complete":
			pchar.quest.Contraoffer_Over.over = "yes";
			RemoveCharacterGoods(pchar, sti(pchar.GenQuest.Contraoffer.Trader.Goods), sti(pchar.GenQuest.Contraoffer.Trader.Qty));
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Contraoffer.Trader.Summ));
			SaveCurrentNpcQuestDateParam(npchar, "Contraoffer");
			npchar.quest.Contraoffer.chance = rand(2);//������ ���� �������� ��� ''��������''
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Commerce", 100);//��������
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			if (pchar.GenQuest.Contraoffer.Trader.Chance == 3)
			{
				dialog.text = "��... ��� ��� ����! �������, � ��� � ���� ��������...";
				link.l1 = "��� ��� �����?";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("Contraoffer_Patrol");
				pchar.GenQuest.Contraoffer.Trader.busy = "true";
				pchar.quest.Contraoffer_busy.win_condition.l1 = "ExitFromLocation";
				pchar.quest.Contraoffer_busy.win_condition.l1.location = pchar.location;
				pchar.quest.Contraoffer_busy.function = "Trader_free";
			}
			else
			{
				DialogExit();
				AddQuestRecord("Contraoffer", "3");
				CloseQuestHeader("Contraoffer");
				DeleteAttribute(pchar, "GenQuest.Contraoffer.Trader");
			}
		break;
		
		case "Contraoffer_slaves"://��������� ������� �� ��� ����, ��� ''��������''
			pchar.GenQuest.Contraoffer.Slaves.Name = GetFullName(npchar);
			pchar.GenQuest.Contraoffer.Slaves.Price = 300;//���� �� �����, ���� �������������, ����� ���������� �������
			pchar.GenQuest.Contraoffer.Slaves.Qty = 300+rand(50);//����������
			pchar.GenQuest.Contraoffer.Slaves.Days = 14+rand(6);//����
			pchar.GenQuest.Contraoffer.Slaves.Money = sti(pchar.GenQuest.Contraoffer.Slaves.Qty)*sti(pchar.GenQuest.Contraoffer.Slaves.Price);
			dialog.text = "��� ����� ������ ����� ������ ����� � ���������� "+sti(pchar.GenQuest.Contraoffer.Slaves.Qty)+" ����. ��������� ����� �� "+sti(pchar.GenQuest.Contraoffer.Slaves.Price)+" ����� �� �����, ��� � ����� �������� "+sti(pchar.GenQuest.Contraoffer.Slaves.Money)+" ����, ���� - "+FindRussianDaysString(sti(pchar.GenQuest.Contraoffer.Slaves.Days))+".";
			link.l1 = "�������, � ���������. ���� ���� � ���������, �� ����������.";
			link.l1.go = "Contraoffer_slaves_1";
			link.l2 = "���� ��� �� ����������.";
			link.l2.go = "exit";
			pchar.GenQuest.Contraoffer.Slaves = "begin";
		break;
		
		case "Contraoffer_slaves_1":
			dialog.text = "�� ����� ����� ��� ��������� - ����������. �� ��� ��, ����� ��� ��� � �������.";
			link.l1 = "� �� �������� ���� ����� �����. �� �������!";
			link.l1.go = "exit";
			pchar.GenQuest.Contraoffer.Slaves.Yes = "begin";
			pchar.GenQuest.Contraoffer.Slaves.City = npchar.city;
			ReOpenQuestHeader("Contraoffer");
			AddQuestRecord("Contraoffer", "4");
			AddQuestUserData("Contraoffer", "sDays", FindRussianDaysString(sti(pchar.GenQuest.Contraoffer.Slaves.Days)));
			AddQuestUserData("Contraoffer", "sGoodQty", FindRussianQtyString(sti(pchar.GenQuest.Contraoffer.Slaves.Qty)));
			AddQuestUserData("Contraoffer", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Slaves.Money)));
			AddQuestUserData("Contraoffer", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Contraoffer.Slaves.City+"Gen"));
			SetFunctionTimerCondition("Contraoffer_Over", 0, 0, sti(pchar.GenQuest.Contraoffer.Slaves.Days), false);
		break;
		
		case "Contraoffer_slaves_check":
			amount = sti(pchar.GenQuest.Contraoffer.Slaves.Qty) - GetSquadronGoods(pchar, GOOD_SLAVES);
			if (amount > 0)
			{
				dialog.text = "���... ������ ��������? � ��� �� ��� ������� ��� ���������� �����!";
				link.l1 = "������, �������� �����...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "������� ���������. �� ������ ���� �������� ����� � ���������� " + FindRussianQtyString(pchar.GenQuest.Contraoffer.Slaves.Qty) + ". ���?";
				link.l1 = "������ ���, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "Contraoffer_slaves_pay";
			}
		break;
		
		case "Contraoffer_slaves_pay":
			dialog.text = "������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.GenQuest.Contraoffer.Slaves.Money)) + ". ����� ����, �������� ��� ���� - ��� ��� ����������.";
			link.l1 = "�������! ������� � ���� ����� ����.";
			link.l1.go = "Contraoffer_slaves_complete";
		break;
		
		case "Contraoffer_slaves_complete":
			DialogExit();
			pchar.quest.Contraoffer_Over.over = "yes";
			RemoveCharacterGoods(pchar, GOOD_SLAVES, sti(pchar.GenQuest.Contraoffer.Slaves.Qty));
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Contraoffer.Slaves.Money));
			AddQuestRecord("Contraoffer", "5");
			CloseQuestHeader("Contraoffer");
			SaveCurrentNpcQuestDateParam(npchar, "Contraoffer");
			AddCharacterExpToSkill(pchar, "Sailing", 150);//���������
			AddCharacterExpToSkill(pchar, "Commerce", 200);//��������
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 150);//�������
			TakeNItems(pchar, "cirass3", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", -3);
			DeleteAttribute(pchar, "GenQuest.Contraoffer.Slaves.Yes");
		break;
		// <-- ��������� ������������ �����������
		
		//Jason --> ��������� ����������� ���
		case "Device_Trader":
			dialog.text = "��, "+pchar.GenQuest.Device.Shipyarder.Type+"? ������� �����... ���� ��� ��� �� ���� ����� - ������� ���� �� �����, ������ ��������� � ����� �� �����.";
			link.l1 = "��, ��� ���������������� ����������, "+pchar.GenQuest.Device.Shipyarder.Describe+". ����� ������ ��������� ���� �� ���������?";
			link.l1.go = "Device_Trader_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_Trader_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) == 0)
			{
				dialog.text = "��... ��, �������� ��� ����� ���� ���� �������� ���. ������ �� �� ����� �� ������, � ������ ������� ��� �������. �� ������ ����� ��� ���, ���� � ���� �� ����, ��� ���� ��� �����? ��� � �� ����� ������� �����? � �����, ������� � ���, � �� ����.";
				link.l1 = "� ��� �������� ���� ������� � ���� �����? ��� ����� ����� ���� ����������.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "���, ����� �� ��������. ��� ��� ������ ����� �� ����. ����������� ��� � ����.";
				link.l1 = "����. ����� ����������!";
				link.l1.go = "exit";
			}
		break;
		// <-- ��������� ����������� ���

		//Jason --> ��������� ����� ��� �������
		case "Sunplace_begin":
			dialog.text = "�����������... � ����� ���� ��� ��� ����� �� ��������. ������ ������� ��� � ������� ��������� � ���� ������ ������, �, �������� ���������� �������� ��������, ���������� ��������� � ����\n�� ��� ������. � �� ����: � ����� �� ��������� ��� ������ ��� ���������� �� ������ �� ����� ���� �����������. ���, ������� ��� ����� �� �����������. ���������� ������ ��������� ��� �������� ��� ������� � ������.";
			link.l1 = "��, ��, ���� �� ������ ���������, ��� ����� ��������.";
			link.l1.go = "Sunplace_1";
			link.l2 = "��� ��, � �� ������� ����������� � ���� ����������� ��������. ������ ������ ������� ��� ����� �������.";
			link.l2.go = "Sunplace_exit";
		break;
		
		case "Sunplace_exit"://���� ������� - ���� ������ ������ ������� �� ����
			npchar.quest.Sunplace = "true";
			DialogExit();
		break;
		
		case "Sunplace_1":
			GetSunplaceShore();//����� � ������
			pchar.GenQuest.Sunplace.Trader.Enemyname = GenerateRandomName_Generator(sti(npchar.nation), "man");//��� ����������
			pchar.GenQuest.Sunplace.Trader.Nation = npchar.nation;//����� ����� ��� �������� � ����������
			pchar.GenQuest.Sunplace.Trader.City = npchar.City;//����� ������������
			pchar.GenQuest.Sunplace.Trader.CityT = findSunplaceCity(NPChar);//����� ����������
			pchar.GenQuest.Sunplace.Trader.Shiptype = Sunplace_Shiptype();//��� �������
			pchar.GenQuest.Sunplace.Trader.ShipName = GenerateRandomNameToShip(sti(NPChar.nation));//��� �������
			pchar.GenQuest.Sunplace.Trader.DaysQty = 5 + drand(5);//���
			pchar.GenQuest.Sunplace.Trader.Money = sti(pchar.GenQuest.Sunplace.Trader.Shiptype)*3000;//������
			pchar.GenQuest.Sunplace.Trader.Goods = GOOD_COFFEE + drand(sti(GOOD_PAPRIKA - GOOD_COFFEE));//�����
			dialog.text = "����� ������. ����, ������ ������� ����� "+pchar.GenQuest.Sunplace.Trader.Enemyname+". ������� �� �������� "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Sunplace.Trader.ShipType), "Name") + "Acc"))+" ''"+pchar.GenQuest.Sunplace.Trader.ShipName+"'' � ������ " + GetGoodsNameAlt(sti(pchar.GenQuest.Sunplace.Trader.Goods))+ " � ��������. �� ������ � ���� ����� ������������ ����� �����, ��� ��� ������ ����� ������ �������� ������ �� ��� ��������.";
			link.l1 = "� �� �� �� ����� �������� �������, ��� ��� ������ ������ ''�����''?";
			link.l1.go = "Sunplace_2";
		break;
		
		case "Sunplace_2":
			dialog.text = "''����'' ������ � ���� ���� � "+XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.CityT+"Abl")+". �� ��� �� ����� - ��� ����� ��� �������, �������, ��� ��� ������� ������, �������� ����� "+FindRussianDaysString(sti(pchar.GenQuest.Sunplace.Trader.DaysQty))+" ����� ��������� � " + XI_ConvertString(pchar.GenQuest.Sunplace.Trader.Shore+"Gen") + ". �� ������ �������� ���, ������ ����� �� ������� - �� ����� ��������. ������� - ����� ������� � ���� ��������� ���� �������������� "+pchar.GenQuest.Sunplace.Trader.Enemyname +". � ��� ���� ��� ������ ������������ - ���, ��� ���� - ��� �����������. �� ������ � ������� ��� " + FindRussianMoneyString(sti(pchar.GenQuest.Sunplace.Trader.Money))".";
			link.l1 = "������ �����. ����������� � ����!";
			link.l1.go = "Sunplace_3";
		break;
		
		case "Sunplace_3":
			DialogExit();
			pchar.GenQuest.Sunplace.Trader = "true";
			if (sti(pchar.GenQuest.Sunplace.Chance) == 1 && sti(pchar.rank) > 9) pchar.GenQuest.Sunplace.Bonus = "true";
			ReOpenQuestHeader("Sunplace");
			AddQuestRecord("Sunplace", "1");
			AddQuestUserData("Sunplace", "sGoods", GetGoodsNameAlt(sti(pchar.GenQuest.Sunplace.Trader.Goods)));
			AddQuestUserData("Sunplace", "sDay", FindRussianDaysString(sti(pchar.GenQuest.Sunplace.Trader.DaysQty)));
			AddQuestUserData("Sunplace", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Sunplace.Trader.Money)));
			AddQuestUserData("Sunplace", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.City+"Gen"));
			AddQuestUserData("Sunplace", "sType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Sunplace.Trader.ShipType), "Name") + "Acc")));
			AddQuestUserData("Sunplace", "sSName", pchar.GenQuest.Sunplace.Trader.ShipName);
			AddQuestUserData("Sunplace", "sName", GetFullName(npchar));
			AddQuestUserData("Sunplace", "sShore", XI_ConvertString(pchar.GenQuest.Sunplace.Trader.Shore+"Gen"));
			SetFunctionTimerCondition("Sunplace_Over", 0, 0, sti(pchar.GenQuest.Sunplace.Trader.DaysQty), false);
			pchar.quest.Sunplace_Trader.win_condition.l1 = "location";
			pchar.quest.Sunplace_Trader.win_condition.l1.location = pchar.GenQuest.Sunplace.Trader.Island;
			pchar.quest.Sunplace_Trader.win_condition.l2 = "Timer";
			pchar.quest.Sunplace_Trader.win_condition.l2.date.hour  = sti(GetTime());
			pchar.quest.Sunplace_Trader.win_condition.l2.date.day   = GetAddingDataDay(0, 0, makeint(sti(pchar.GenQuest.Sunplace.Trader.DaysQty)-2));
			pchar.quest.Sunplace_Trader.win_condition.l2.date.month = GetAddingDataMonth(0, 0, makeint(sti(pchar.GenQuest.Sunplace.Trader.DaysQty)-2));
			pchar.quest.Sunplace_Trader.win_condition.l2.date.year  = GetAddingDataYear(0, 0, makeint(sti(pchar.GenQuest.Sunplace.Trader.DaysQty)-2));
			pchar.quest.Sunplace_Trader.function = "Sunplace_CreateTraderShip";
		break;
		
		case "Sunplace_complete":
			dialog.text = "������������! � ����, ��� �� ��� ����� ����������. �������, � �� ���� ����������, ��� ������ ���� � �������. � ����� ������, ��� �� ��� ����. ��, � ����� ����� ����������� ������ �������, ����� ���������� �� ������ �����, ��-��. ���, �������� ���� ������ � ��� ��� ������� �� ������� ����������� ������.";
			link.l1 = "�� �� �� ���... �� ��������, " + npchar.name + "!";
			link.l1.go = "Sunplace_complete_1";
		break;
		
		case "Sunplace_complete_1":
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Sunplace.Trader.Money));
			AddQuestRecord("Sunplace", "12");
			CloseQuestHeader("Sunplace");
			pchar.GenQuest.Sunplace.Chance = rand(2);
			AddComplexSeaExpToScill(50, 50, 50, 50, 50, 0, 0);
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			DeleteAttribute(pchar, "GenQuest.Sunplace.Trader");
			DialogExit();
		break;
		
		case "Sunplace_complete_murder":
			dialog.text = "������ "+pchar.GenQuest.Sunplace.Trader.Enemyname+", ����� ������� ������! � � �������� ������� � ��� ������... �� ������ �� ���������, �������! ����� � ������ ��� �������? � �����������, ��� ����� ����, ��� �� �������� ������, ��������� � �����, �� ����� �������� �����... �������, �������. ��...";
			link.l1 = "����������, �����������, �������, ���������. �� ������� �������� ��� �� ���������� - � ������ ���. � ������ ���� �����, ��� �� ������� ���������� - ������� ����, ����� ����� ����������� � �������, � ������ ��������� ��� ������ ������ �������.";
			link.l1.go = "Sunplace_complete_murder_1";
		break;
		
		case "Sunplace_complete_murder_1":
			dialog.text = "��! ��������! �� ����� ������ ������� ����� ������������� �����! �������� ���� �������� ������ � ������� �� ����� ��������!";
			link.l1 = "��, " + npchar.name + ", ������! � �� �� � ������ ��� ��� ������ - ����� ������ ��� ���... �����, �� �������, � ����. ��� ����, ��� ��� ����������, �� �� ���� ����� ���� � �����������. ��������.";
			link.l1.go = "Sunplace_complete_murder_2";
		break;
		
		case "Sunplace_complete_murder_2":
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Sunplace.Trader.Money));
			AddQuestRecord("Sunplace", "13");
			AddQuestUserData("Sunplace", "sName", GetFullName(npchar));
			CloseQuestHeader("Sunplace");
			npchar.quest.Sunplace = "true";//���� ������ �������� ����� ������ �� ����
			AddComplexSeaExpToScill(50, 50, 50, 50, 50, 0, 0);
			AddComplexSelfExpToScill(30, 30, 30, 30);
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			DeleteAttribute(pchar, "GenQuest.Sunplace.Trader");
			DialogExit();
		break;
		
		//Jason --> ����� ���������
		case "FindFugitiveSt":
			if (NPChar.city == pchar.GenQuest.FindFugitive.City && sti(pchar.GenQuest.FindFugitive.Chance) == 1)
			{
				dialog.text = NPCStringReactionRepeat(""+pchar.GenQuest.FindFugitive.Name+"? ��, � ��� ����, �� ������� � ���� �������� �� ���� ������. ���� �� ������� ���-�� � �������� ������, � ��� ���� ������ ����� ��� ����� ����� � �������.", "�� ��� ��������� ���� �� ���� ��������, � � ���� ��� ���������!", "�� ���, �����������, ��� �� ����� ���� �����? ������ ��� ����������� ���� � �� ��!", "��, � ��� ������ ����� ������ ��������� ����...", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������, �� ��� ����� �����!", "��, ��, ������.", "����, �� ��������. � ������ �����.", "�� �� �� ������ - ���� ���-��...", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("FindFugitiveSt_1", "exit", "", "", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = NPCStringReactionRepeat("�� ����, ��� ��� ������� � ������� ����-�����, � � ����� �������� � ������ �������� �� ��������. � ������ ����� �� �����. ������������� � �������, �����, ��� ��� ������...", "�� ��� ��������� ���� �� ���� ��������, � � ���� ������: �� ����!", "�� ���, �����������, ��� �� ����� ���� �����? ������ ��� ����������� ���� � �� ��!", "��, � ��� ������ ����� ������ ��������� ����...", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������. ��, � �� ��� �������.", "��, ��, ������.", "����, �� ��������. � ������ �����.", "�� �� �� ������ - ���� ���-��...", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);	
			}
		break;
		
		case "FindFugitiveSt_1":
			DialogExit();
			AddQuestRecord("MayorsQuestsList", "12-2");
			sld = characterFromId("Fugitive");
			LAi_SetSitType(sld);
			sld.dialog.currentnode = "Fugitive_tavern";
			LAi_SetLoginTime(sld, 20.0, 23.99);
			FreeSitLocator(pchar.GenQuest.FindFugitive.City + "_tavern", "sit_front1");
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.FindFugitive.City+"_tavern", "sit", "sit_front1");
		break;
		//<-- ����� ���������
		
		// --> ��������� ����� - ��������� ����������
		case "trial":
			dialog.text = "�������, �� ��� �� �� ��� �����������, ������� �������! ������ ����������, � ����� ������, � ��������� ���������, ����� �������� �� ��������� �����! ����� ������ ����� � ��������� � ���������� �� �������, �� ������� ���� ��������������. �����������?";
			link.l1 = "���... ����� ���� ��������, �����. � �����������...";
			link.l1.go = "trial_1";
		break;
		
		case "trial_1":
			dialog.text = "���������. ������������ ������ ������� ����������, � ��� ����� ������� �� ���� �����. ���, ��������. ����� 400 ������� ��������. �������, �� ������������� �������� ��������?";
			link.l1 = "������. ��� ��� ����� �������� ����. � ������ ��������� �����������.";
			link.l1.go = "trial_2";
		break;
		
		case "trial_2":
			TakeNItems(pchar, "gold_dublon", 400);
			Log_Info("�� �������� 400 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "����� �������, �����.";
			link.l1 = "...";
			link.l1.go = "trial_3";
		break;
		
		case "trial_3":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(pchar, "questTemp.Trial");
			DeleteAttribute(npchar, "quest.trial_usurer");
			CloseQuestHeader("Trial");
		break;
		
		/*case "trial":
			dialog.text = "�������, �� ��� �� �� ��� �����������, ������� �������! ������ ����������, � ����� ������, � ��������� ���������, ����� �������� �� ��������� �����! ����� ������ ����� � ��������� � ���������� �� �������, �� ��� ��� �� ������� ���������\n��, �� �����������, ������? ������ ���� ���������?";
			link.l1 = "���... ����� ���� ��������, �����. � �����������. ������ ��� �����������.";
			link.l1.go = "trial_1";
		break;
		
		case "trial_1":
			dialog.text = "���������. ������������ ������ ������� ����������, � ��� ����� ������� �� ���� �����. �����... ��� �������� ������� �� ����� ����� �����?";
			link.l1 = "��! ��� �� �� ����� ������ �����! �������, ���� ������� ��� ������.";
			link.l1.go = "trial_2";
			link.l2 = "������� ����� ��� ���. ��� ��?";
			link.l2.go = "trial_3";
		break;
		
		case "trial_2":
			dialog.text = "�����������. ������������� � ����. ������ �� ������������ �������� ����� ����, ��� ��� ��� �������������� �������� � ����. � ������ ��� ����������?";
			link.l1 = "��� ��� ����� ��������... ������� �� ������, �����. ����������� � ��������� ����� ����������!";
			link.l1.go = "trial_exit";
		break;
		
		case "trial_3":
			dialog.text = "��� �������� ����������� ���� �����. ����������� ��������� � �����������. ��� ��� ��� ��������� ����������� �� ����-��������� � �������� ���� �����������. ������ �������� ����� ������������ �������� ����� ����, ��� ��� ��� �������������� �������� � ����. � ������ ��� ����������?";
			link.l1 = "��� ��� ����� ��������... ������� �� ������, �����. ����������� � ��������� ����� ����������!";
			link.l1.go = "trial_exit";
		break;
		
		case "trial_exit":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(npchar, "quest.trial_usurer");
			pchar.questTemp.Trial = "usurer";
			AddQuestRecord("Trial", "22");
		break;*/
		
		case "no_quests":
			dialog.text = "� ������ ������ � �� �������� � ����� �������.";
			link.l1 = "����� ����. ����� ������� ��������� � ������.";
			link.l1.go = "node_1";
		break;
		
        case "fight":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "Exit":
			if (pchar.questTemp.Ascold == "canTakeQuest" && pchar.questTemp.Ascold.TraderId == npchar.id)//eddy. �������, ������
			{
				dialog.Text = "���� ����� ��� ����� ���, �������!";
				Link.l1 = "�������!";
				Link.l1.go = "exit";
			}
			else
			{
				Nextdiag.CurrentNode = Nextdiag.TempNode;
				DialogExit();
			}
		break;

	}
	LanguageCloseFile(iSeaGoods);
}

int findStoreMan(ref NPChar, int iTradeNation)
{
    ref ch;
	int n;
    int storeArray[30];
    int howStore = 0;

	for(n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(ch,Characters[n]);
        if (CheckAttribute(ch, "Dialog.Filename") && ch.Dialog.Filename == "Common_Store.c") // �������
		{
            if (sti(ch.nation) !=  iTradeNation) continue;
            if (NPChar.id == ch.id) continue;
            if (NPChar.id == "Panama_trader" || ch.id == "Panama_trader") continue; //������ �������
            if (ch.location == "none") continue; // ���� ��� �����, ��������� �� ���� ��������
            if (GetIslandByCityName(ch.city) == GetIslandByCityName(NPChar.city)) continue; // ���� ���, � �� ����!
            storeArray[howStore] = n;
            howStore++;
		}
    }
    if (howStore == 0)
    {
        return -1;
    }
    else
    {
        return storeArray[rand(howStore-1)];
    }
}

int Sunplace_Shiptype() // new
{
	int i;
	
	if (sti(pchar.rank) >= 1 && sti(pchar.rank) < 6) i = SHIP_SCHOONER;
	if (sti(pchar.rank) >= 6 && sti(pchar.rank) < 11) i = SHIP_FLEUT;
	if (sti(pchar.rank) >= 11 && sti(pchar.rank) < 18) i = SHIP_PINNACE;
	if (sti(pchar.rank) >= 18) i = SHIP_GALEON_L;
	
	return i;
}

string findSunplaceCity(ref NPChar) // new
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(pchar.nation), sti(colonies[n].nation));
		if (nation != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[dRand(howStore-1)];
	return colonies[nation].id;
}