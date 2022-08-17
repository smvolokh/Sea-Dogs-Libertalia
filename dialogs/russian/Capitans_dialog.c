// �������� � ��������� �� ������  Boal
//homo 25/06/06
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);
    //homo �����
    aref aData;
    makearef(aData, NullCharacter.Siege);
    string sCap, sGroup;
    string fort;

    if (CheckAttribute(aData, "nation"))
    {
	    sCap = NationShortName(sti(aData.nation))+"SiegeCap_";
	    sGroup = "Sea_"+sCap+"1";
	    
	   // string myships  = GetCompanionQuantity(PChar);
       // string escships = Group_GetCharactersNum(sGroup);
        
        switch(sti(aData.conation))
        {
            case 0:  fort = "���������� ������"; break;
            case 1:  fort = "����������� ������"; break;
            case 2:  fort = "��������� ������"; break;
            case 3:  fort = "����������� ������"; break;
            case 4:  fort = "��������� ������"; break;
        }
        int ifortPower = sti(colonies[FindColony(aData.colony)].FortValue);
        int fortDamage = CheckFortInjuri();
        int SquadronDamage = CheckSquadronInjuri();
        
    }

    int iMoney;
	ref sld;
    
    if (CheckNPCQuestDate(npchar, "Card_date"))
	{
		SetNPCQuestDate(npchar, "Card_date");
		npchar.money = 3000 + rand(10) * makeint(100 * sti(PChar.rank) * (10.0 / MOD_SKILL_ENEMY_RATE));
	}
	else
	{
		if(sti(npchar.money) > CAP_MAX_MONEY || sti(npchar.money) < CAP_MIN_MONEY) 	
		{
			npchar.money = CAP_MIN_MONEY + rand(CAP_NORM);
		}
	}
    //homo 26/06/06
	ProcessCommonDialogRumors(NPChar, Link, Diag);
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
		
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			PlaySound("VOICE\Russian\citizen\Kapitani Korabley_" + rand(15) + ".wav");
			if (!bDisableMapEnter)
			{
				//--> Jason ������ 2 �������
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1WM") && pchar.questTemp.WPU.Escort == "begin" && NPChar.id == "WMCaptain")
				{
					dialog.text = "������������, �������. ���� ������, �� ���� �� �������������, ��� � ��� ��� ������!";
					link.l1 = "������ ����. ��������� ������������� - " + GetFullName(PChar) + ". � ���� ��� ��� ������ � ������ �������, ��������� ������ ���� ������ � ����� ��������� ��� � ��� �������.";
					link.l1.go = "WM_Captain";
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1WM") && pchar.questTemp.WPU.Escort == "wait" && NPChar.id == "WMCaptain")
				{
					dialog.text = "�� ��������� ��������, ������� � ������?";
					if (sti(pchar.questTemp.WPU.Escort.Planks) - GetSquadronGoods(pchar, GOOD_PLANKS) <= 0 && sti(pchar.questTemp.WPU.Escort.Sailcloth) - GetSquadronGoods(pchar, GOOD_SAILCLOTH) <= 0 && sti(pchar.questTemp.WPU.Escort.Linen) - GetSquadronGoods(pchar, GOOD_COTTON) <= 0)
					{
						link.l1 = "��. ���, ��� ����� ��� ������� ������ ����� ��������� � ���� � ������.";
						link.l1.go = "WM_Captain_5";
					}
					else
					{
						link.l1 = "���, � ��� ������� ��� ����.";
						link.l1.go = "exit";
					}
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1VSP") && pchar.questTemp.WPU.Escort == "toCap" && NPChar.id == "WMCaptain")
				{
					dialog.text = "������������, " + GetAddress_Form(NPChar) + ". ���� ����� " + GetFullName(NPChar) + ", � ������� ����� �������. ���� ��� �������� ���� ������������ ��������������� �� ������ � ��� � ���� ��������� ��������� �������� - ��� ������ ������������� ��� ����� �� ���������� ��� ��� ������ ��������. �� ������ ������ ���, ���� ������!";
					link.l1 = "�� ����� �������������, " + GetAddress_FormToNPC(NPChar) + ". ��������� ������������ - " + GetFullName(PChar) + ", � ������ � ��� �� ������ �� ������� ���������� ��������� ���������� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+". �� ������� ��������� � ������������ ������ �������� � �������� ���� �� ������ ������ �����.";
					link.l1.go = "VSP_Captain";
					break;
				}
				//<-- ������ 2 �������
				
				if(CheckAttribute(NPChar, "surrendered"))
				{
					Pchar.GenQuest.MoneyForCaptureShip = makeint(Group_GetLiveCharactersNum( GetGroupIDFromCharacter(NPChar)))*(7 - sti(RealShips[sti(NPChar.Ship.Type)].Class))*(1+rand(5))*2500*1,5);
					dialog.text = "�� ������� ������ ����� ����, �������. �� ������������. � ������ ����, ���� ������� � ������ � ���� ������������. ������ �� ���� ���������� � ������������. ��� �� ������ �� �� ����?";
					//�����
					link.l1 = "������� ����� ��� �����. ����� ������ ���� �������. ����� � "+Pchar.GenQuest.MoneyForCaptureShip+" ���� ���� ������ �������, "+GetAddress_FormToNPC(NPChar)+". � ����� ����� ������ ����������� ������ �� ���� ������!";
					link.l1.go = "surrender1";
					// ������� �� �����
					link.l2 = "���� ���������������� ���������� ������ �����. � ����� ����� ������ ����������� �� ���� ������.";
					link.l2.go = "surrender2";
					break;
				}
				
				//����������� ������, ������ ����
				if (CheckAttribute(PChar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "MeetingStivesant" && NPChar.id == "Stivesant")
				{
					dialog.text = "������������, ������. ��� ��� ������. ������� �������, �������, ���������� �� ���� �����?";
					link.l1 = "������ ����, ������ ����������. ��������� ������������� - " + GetFullName(pchar) + ". ������� �� ������, ������ ��� ��� ��� �� '�������'.";
					link.l1.go = "Stivesant_1";
					pchar.quest.QuestShipsTerms_Over.over = "yes"; //����� ������
					break;
				}
				if (CheckAttribute(PChar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "FleutOnTrinidad" && NPChar.id == "Keller")
				{
					dialog.text = "������������, �������. ��� ������� ��� �� ���� ����� ������?";
					link.l1 = "������ ����, ������ ������. ��������� ������������� - " + GetFullName(pchar) + ". � ������ � ��� �� ������� � ����� ��������� ����.";
					link.l1.go = "Keller_1";
					break;
					//����������� ������
				}
                if (CheckAttribute(NPChar, "EncType")  && NPChar.EncType == "war")
                {
    			    Dialog.text = TimeGreeting() + ", "+ GetAddress_Form(NPChar)+"! � "+ GetFullName(NPChar) +" - ������� ������� ����� "+NationKingsName(NPChar)+". ��� ������� ��� �� ��� �� ����?";
    			}
    			else
                {
    			    Dialog.text = TimeGreeting() + ", "+ GetAddress_Form(NPChar)+"! � ������� "+ GetFullName(NPChar) +". ��� ������� ��� �� ���� ����� �������?";
    			}
    			link.l1 = "���� ����� " + GetFullName(Pchar) + ". � ���� ����  � ��� ����!";
    			link.l1.go = "quests";
                link.l2 = "������ ����������, ������ "+ GetSexPhrase("�����","�����") +" ���������������� ���!";
    			link.l2.go = "exit";
            }
            else
            {
                Dialog.text = "�� ��������, " + GetAddress_Form(NPChar) + ", ���� �����? ��� ������ �� �� ����������!";
    			link.l1 = "�� �����! ������� �� ���� �������.";
    			link.l1.go = "exit";
            }
			Diag.TempNode = "first time";
 		break;

        case "quests":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			PlaySound("VOICE\Russian\citizen\Kapitani Korabley_" + rand(15) + ".wav");
            if (!CheckAttribute(NPChar, "MainCaptanId")  || NPChar.MainCaptanId == pchar.GenQuest.CaptainId)
            {
                Dialog.text = "� ��� ����������� ������, " + GetAddress_Form(NPChar)+".";
                link.l1 = "� �����"+ GetSexPhrase("","�") +" �� ������ ��������� ������� ����������.";
                //homo 25/06/06
                link.l1.go = "rumours_capitan";
                //
                if (CheckAttribute(NPChar, "EncGroupName")) // ������ ��� �������� ������
                {
                    link.l2 = RandPhraseSimple("�� � �����, ��� �? �����, ����, ��� ��� ����������� ������ ����� ������� ������ �� ������ ������. ������� ����� ��� �����. ����� ������ ���� �������.",
                                               "����... � �� ����... ��� ������ ����, ����� � ����� ����� ������������ ������� ��������� ���� �����?.");
                    link.l2.go = "Talk_board";
                }
                if (CheckAttribute(NPChar, "Ship.Mode") && NPChar.Ship.Mode == "Trade")
                {
	           		link.l3 = "������ �� �����?";
	    			link.l3.go = "price_1";
	    			link.l4 = "���������?";
	    			link.l4.go = "Trade_1";
    			}
				//--> ����� ����, ������ ������
				if (CheckAttribute(pchar, "GenQuest.DestroyPirate"))
				{
	    			link.l6 = "� ���������� ��������� �������, ��������� � ������� �����. �� ������ �� ������ ���������������?";
	    			link.l6.go = "MQ_step_1";
				}
				//<-- ����� ����, ������ ������
    			link.l5 = "������� ����������?";
			    link.l5.go = "Play_Game";
                link.l9 = "�����, ��� ����!";
    			link.l9.go = "exit";
			}
			else
			{
                Dialog.text = "� �� ����������� ������ ���� � ����, ���������� � ������������ ����� �������. ��� ��� " + GetFullName(characterFromID(NPChar.MainCaptanId))+
                              ", �� ��������� �� ������� " + XI_ConvertString(RealShips[sti(characters[GetCharacterIndex(NPChar.MainCaptanId)].Ship.Type)].BaseName) + " '" + characters[GetCharacterIndex(NPChar.MainCaptanId)].Ship.Name + "'.";
                link.l1 = "�������. ��� � ��������.";
                link.l1.go = "exit";
                Diag.TempNode = "Go_away_Good";
			}
        break;
        case "Trade_1":
			dialog.text = "������ �� � ���?";
			link.l1 = "�������� �������� ������.";
			link.l1.go = "Trade_2";
			link.l2 = "� ���������"+ GetSexPhrase("","�") +".";
			link.l2.go = "exit";
		break;
		
		case "Trade_2":
			FillShipStore(NPChar);
	    	pchar.shiptrade.character = NPChar.id;
   			Diag.CurrentNode = Diag.TempNode;
		    DialogExit();
		    DeleteAttribute(pchar, "PriceList.StoreManIdx"); // �� ����� ��� �� ��������
		    LaunchStore(SHIP_STORE);
		break;
		
        case "Play_Game":
			dialog.text = "��� �� �����������?";
			link.l1 = "����������� � ����� �� �������� �������?";
			link.l1.go = "Card_Game";
   			link.l2 = "�������� ������� � �����-������?";
			link.l2.go = "Dice_Game";
			link.l10 = "����� ��������, �� ���� ���� ����.";
			link.l10.go = "exit";
		break;
        // ����� -->
        case "Card_Game":
            if (!CheckNPCQuestDate(npchar, "Card_date_Yet") || isBadReputation(pchar, 30) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(3))
            {
                SetNPCQuestDate(npchar, "Card_date_Yet");
                dialog.text = "� �� ���� ������ � �������� ���� � ������� ������������!";
    			link.l1 = "��� ��� ����� ������.";
    			link.l1.go = "exit";
			}
			else
			{
                dialog.text = "�������! ������� ��������� �� ����������� ���...";
    			link.l1 = "������������.";
    			link.l1.go = "Cards_begin";
    			link.l2 = "�� ����� �������� ������?";
    			link.l2.go = "Cards_Rule";
			}
		break;

		case "Cards_Rule":
   			dialog.text = CARDS_RULE;
			link.l1 = "��� �, ������� ������!";
			link.l1.go = "Cards_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Cards_begin":
			Dialog.text = "������� ����������� �� �������.";
			link.l1 = "������ �� 100 ����.";
			link.l1.go = "Cards_Node_100";
			link.l2 = "������� �� 500 ����.";
			link.l2.go = "Cards_Node_500";
			link.l3 = "�������, ��� ����.";
			link.l3.go = "exit";
		break;

		case "Cards_Node_100":
		    if (sti(pchar.Money) < 300)
		    {
                dialog.text = "������ ��������? � ��� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 300)
		    {
                dialog.text = "������ � ����, � �� �� ���������� ������� �� ���������...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 100 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 100;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_Node_500":
		    if (sti(pchar.Money) < 1500)
		    {
                dialog.text = "������ ��������? � ��� ��� 1500 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 1500)
		    {
                dialog.text = "���, ����� ������ �� ������� �� �����.";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 500 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 500;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_begin_go":
            Diag.CurrentNode = Diag.TempNode;
			DialogExit();
            LaunchCardsGame();
		break;
	    // ����� <--
	    //  Dice -->
        case "Dice_Game":
            if (!CheckNPCQuestDate(npchar, "Dice_date_Yet") || isBadReputation(pchar, 30) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(3))
            {
                SetNPCQuestDate(npchar, "Dice_date_Yet");
                dialog.text = "� �� ���� ������ � �������� ���� � ������� ������������!";
    			link.l1 = "��� ��� ����� ������.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Dice_date_begin"))
				{
					dialog.text = "�������! ����� ������� �� ������ ��������... ������ ��������...";
	    			link.l1 = "������������.";
	    			link.l1.go = "Dice_begin";
	    			link.l2 = "�� ����� �������� ����?";
	    			link.l2.go = "Dice_Rule";
    			}
    			else
    			{
					dialog.text = "���, � ���� �������� �� �������. ���� ����.";
	    			link.l1 = "��� ��� ����� ������.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Dice_Rule":
   			dialog.text = DICE_RULE;
			link.l1 = "��� �, ������� ������!";
			link.l1.go = "Dice_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Dice_begin":
			Dialog.text = "������� ����������� �� �������.";
			link.l1 = "������ �� 50 ���� �� �����.";
			link.l1.go = "Dice_Node_100";
			link.l2 = "������� �� 200 ���� �� �����.";
			link.l2.go = "Dice_Node_500";
			link.l3 = "�������, ��� ����.";
			link.l3.go = "exit";
		break;

		case "Dice_Node_100":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� �������������"+ GetSexPhrase("��� ������","�� ������") +". � �� ���� � ����� ������ � ����� ������.";
                link.l1 = "��� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 300)
		    {
                dialog.text = "������ ��������? � ��� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 300)
		    {
                dialog.text = "���! ����� ���������� � ������, � �� ������� � ����������� � ������ �� �����...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 50 �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 50;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_Node_500":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� �������������"+ GetSexPhrase("��� ������","�� ������") +". � �� ���� � ����� ������ � ����� ������.";
                link.l1 = "��� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckDiceGameBigRate())
		    {
                dialog.text = "� ������, ��� �� ����� ������ �������. � �� ���� ������ � ����� �� ����� ������� �������.";
                link.l1 = "������� �� ����� ������ �������?";
			    link.l1.go = "Dice_Node_100";
				link.l2 = "��������, ��� ����.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 1500)
		    {
                dialog.text = "������ ��������? � ��� ��� 1500 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 1500)
		    {
                dialog.text = "���, ����� ������ �� ������� �� �����.";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 200 ����� �� �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 200;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_begin_go":
            SetNPCQuestDate(npchar, "Dice_date_begin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
            LaunchDiceGame();
		break;
	    // Dice <--
        case "price_1":
			if (CheckNPCQuestDate(npchar, "trade_date"))
			{
                SetNPCQuestDate(npchar, "trade_date");
				iMoney = findPriceStoreMan(NPChar);
	            if (iMoney == -1)
	            {
	                Dialog.Text = "����� ��� ��� �����? ��� ��� ������ ����.";
					Link.l1 = "��� ��� ����� ������.";
					Link.l1.go = "exit";
	            }
	            else
	            {
                    sld = &Characters[iMoney];
                    pchar.PriceList.ShipStoreIdx = iMoney;
                    
					Dialog.Text = "� ��� �� ������ " + GetCityName(sld.City) + ".";
					Link.l1 = "����� ���� �� ������ � ������� ��������?";
					Link.l1.go = "price_2";
					Link.l9 = "��� ��� ����.";
					Link.l9.go = "exit";
				}
			}
			else
			{
                Dialog.Text = "� �� ��� ��� ��� ������. �� ���������� ���� �� ��������.";
				Link.l1 = "��, �� �����. ��������.";
				Link.l1.go = "exit";
            }
		break;
		
		case "price_2":
            sld = &Characters[sti(pchar.PriceList.ShipStoreIdx)];
			SetPriceListByStoreMan(&Colonies[FindColony(sld.City)]);
			Dialog.Text = "��� �����... (�� �������� ������ ��� �� ������).";
			Link.l1 = "������� �������!";
			Link.l1.go = "exit";
			PlaySound("interface\important_item.wav");
		break;
		
        case "Talk_board":
            if ((Group_GetCharactersNum(NPChar.EncGroupName) - Group_GetDeadCharactersNum(NPChar.EncGroupName)) > GetCompanionQuantity(PChar) && rand(11) > GetCharacterSkillToOld(PChar, SKILL_FORTUNE))
            {
                Dialog.text = "��-��! ������� �����. ��� �����, ��� � ���� ������ ��������. ���������� �� ���� ������� � ������ ������ � ���.";
                link.l1 = "������ - �� ������ ������...";
                link.l1.go = "Boarding";
            }
            else
            {
                if(rand(21) > (GetSummonSkillFromNameToOld(PChar, SKILL_GRAPPLING) + GetSummonSkillFromNameToOld(PChar, SKILL_LEADERSHIP)) )
                {
                    Dialog.text = "�������� �� ������� ���� ������� ����, �������, �� ����� ����� �������. � ������� ���������� � ������� ��� ��������� �� ���� ������� � ������� ������ � ���.";
                    link.l1 = "�� ��� ���������, ��� ������� ������ �� ���� ������!";
                    link.l1.go = "Boarding";
                }
                else
                {
                    Pchar.GenQuest.MoneyForCaptureShip = makeint(100 + (Group_GetCharactersNum(NPChar.EncGroupName) - Group_GetDeadCharactersNum(NPChar.EncGroupName))*(7 - sti(RealShips[sti(NPChar.Ship.Type)].Class))*(1+rand(10))*500);
                    Dialog.text = RandSwear() + "��, � �������� � ����� �����������. ���� ��-������, �� ������� " +
                                  XI_ConvertString(NationShortName(sti(NPChar.nation))+"hunter") + " �� ������� ��� �������������!";
                    link.l1 = "������������. ����� � "+Pchar.GenQuest.MoneyForCaptureShip+" ���� ���� ������ �������, "+GetAddress_FormToNPC(NPChar)+".";
                    link.l1.go = "Capture";
                    link.l2 = "��. �� �����. � �������"+ GetSexPhrase("","�") +"!";
                    link.l2.go = "exit";
                }
            }
            // ��� ����� ���� ������� ���������� ������
            Diag.TempNode = "Go_away";
			sld = characterFromId(pchar.GenQuest.CaptainId);
            sld.talk_date_Go_away =  lastspeakdate(); // boal ������������� :)
        break;
		
		case "surrender1" :
			Diag.TempNode = "surrender_goaway";
            Dialog.Text = "��������! � ������ ���������� ���!";
			Link.l1 = "������������! � ��� �� �������!";
			Link.l1.go = "exit";
			sld = characterFromId(pchar.GenQuest.CaptainId);
            sld.talk_date_Go_away = lastspeakdate();
			AddMoneyToCharacter(pchar, sti(Pchar.GenQuest.MoneyForCaptureShip));
			ChangeCharacterComplexReputation(pchar,"nobility", -2); 		
			ChangeCharacterComplexReputation(pchar,"authority", 1.0); 							
		AddCharacterExpToSkill(pchar, "Leadership", 200);
			ChangeCharacterHunterScore(pchar, NationShortName(sti(NPChar.nation)) + "hunter", 5 + rand(5));
		break;
		
		case "surrender_goaway":
			Diag.TempNode = "surrender_goaway";
			Dialog.Text = "�� ��� �� ��� �� ���� ������?";
			Link.l1 = "������.";
			Link.l1.go = "exit";
			Diag.TempNode = "surrender_goaway";
		break;
		
		case "surrender2":			
			Diag.TempNode = "surrender_goaway";
			dialog.text = "��� �� �������� ������ ������� ����� ��� ����������� ���.";
			link.l1 = "�����, �������������!";
			link.l1.go = "surrender3";				
		break;
						
		case "surrender3":
			Diag.TempNode = "surrender_goaway";
			sld = characterFromId(pchar.GenQuest.CaptainId);
            sld.talk_date_Go_away = lastspeakdate();
			DialogExit(); 
			LaunchTransferMain(pchar, sld, "Transfer");
		break;
				
        case "rumours":
			Dialog.Text = SelectRumour(); // to_do
			Link.l1 = RandPhraseSimple(RandSwear() + "��� ����� ���������. ������ ������?",
                                     "��� ���� ����.");
			Link.l1.go = "quests";
			Link.l2 = RandPhraseSimple("�������, ������ �����������.",
                                     "����� ��������.");
			Link.l2.go = "exit";
			Diag.TempNode = "quests";
		break;
		
		case "Go_away":
			Dialog.Text = "���������� � ����� �������!";
			Link.l1 = "��� �����.";
			Link.l1.go = "exit";
			Diag.TempNode = "Go_away";
		break;
		
		case "Go_away_Good":
			Dialog.Text = "��� �������� ��� �������. ������ ������ � ��� �� �����, "+GetAddress_Form(NPChar)+".";
			Link.l1 = "����. �� ������� � ����!";
			Link.l1.go = "exit";
			Diag.TempNode = "Go_away_Good";
		break;

        case "Capture":
            Diag.TempNode = "Go_away";
            Dialog.Text = "��������! � ������ ���������� ���!";
			Link.l1 = "������������!";
			Link.l1.go = "exit";
			AddMoneyToCharacter(pchar, sti(Pchar.GenQuest.MoneyForCaptureShip));
			ChangeCharacterComplexReputation(pchar,"nobility", -5);			
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			ChangeCharacterHunterScore(pchar, NationShortName(sti(NPChar.nation)) + "hunter", 7 + rand(10));
        break;

        case "Boarding":
            if (CheckAttribute(NPChar, "MainCaptanId"))
            {
                PChar.StartBattleAfterDeck = true;
                PChar.StartBattleMainCaptanId = NPChar.MainCaptanId;
                PChar.StartBattleEncGroupName = NPChar.EncGroupName;
            }
            DialogExit();
            Diag.CurrentNode = Diag.TempNode;
        break;
        
        case "QuestAboardCabinDialog":  // �������� ������, � ���� �� ��������, ��� ������ SetQuestAboardCabinDialog
			Diag.TempNode = "QuestAboardCabinDialog";
            Dialog.Text = "����, ��� � ����� �����. ��� �� ������ �� ����?";
			Link.l1 = "�����!";
			Link.l1.go = "QuestAboardCabinDialog_1";
			Link.l2 = "����� � ����.";
			Link.l2.go = "QuestAboardCabinDialog_2";
			Link.l3 = "����� ��� �����, ����� (c)";  // �������, ����� �� ���� ���  QuestAboardCabinDialog_1 ��� QuestAboardCabinDialog_2
			Link.l3.go = "QuestAboardCabinDialog_3";  // ����� �������� ��������� �������, �� ������ ��� ������� � ��...
        break;
        
        case "QuestAboardCabinDialog_1":
			Dialog.Text = "��, ��� �� ��� ���������!";
			Link.l1 = "� ��� ��� ��������?";
			Link.l1.go = "exit";
			// ��� ����� ������������ �� ���������� (NPChar) ��� �������� ������� ������ ������ ��
			LAi_SetCurHPMax(NPChar);
			AddDialogExitQuestFunction("QuestAboardCabinDialogExitWithBattle"); // ��� ������ �������
		break;
		
		case "QuestAboardCabinDialog_2":
			Dialog.Text = "������, ���� �����!";
			Link.l1 = "��� �� �����!";
			Link.l1.go = "exit";
			AddDialogExitQuestFunction("QuestAboardCabinDialogSurrender");
		break;
		
		case "QuestAboardCabinDialog_3":
			Dialog.Text = "�� �������!";
			Link.l1 = "��� � ������, ������ �������� � ����.";
			if (rand(1) == 1)  // ������!!!
			{
				Link.l1.go = "QuestAboardCabinDialog_2";
			}
			else
			{
			    Link.l1.go = "QuestAboardCabinDialog_3_1";
			}
			TakeNItems(NPChar, "Chest", -1);
			TakeNItems(pchar, "Chest", 1);
		break;
		
		case "QuestAboardCabinDialog_3_1":
			Dialog.Text = ""+ GetSexPhrase("������","������") +", ��������"+ GetSexPhrase("","�") +", ��� �����"+ GetSexPhrase("","�") +" � ��� ���� � ����? ���!";
			Link.l1 = "����� ����� ����� ������.";
			Link.l1.go = "QuestAboardCabinDialog_1";
		break;
		//eddy. ����� ����, ������ ������
		case "MQ_step_1":
			Dialog.Text = "���, �������� ��������������� �������, �������� �� ���������, � �� �����.";
			Link.l1 = "�������.";
			Link.l1.go = "exit";
		break;
		
		//homo ������� �� �����
		case "MerchantTrap_Abordage":

			Dialog.Text = "������ "+NationKingsName(NPChar)+" ��������, "+ GetSexPhrase("������ �����","������ ��������") +"! � ���� �������� ����� �� ������������� ����, ��� �� ��������, �� ��� "+NationNameSK(sti(NPChar.nation))+"�� �������, ������� �� �������"+ GetSexPhrase("","�") +".";
			Link.l1 = "��� �� �� ��� - ��� ��������.";
			Link.l1.go = "exit";
			LAi_SetCurHPMax(NPChar);
			AddDialogExitQuestFunction("QuestAboardCabinDialogExitWithBattleNoParam"); // ��� ������ �������
		break;
		
		case "Siegehelp":		
            ref rchar = Group_GetGroupCommander(sGroup);
            if (NPChar.id == rchar.id)
            {
    			
    			dialog.text = "� ��� ������, �� ������� �������� ������������ ���� ������ ������, � ��� ���� ��� � " + fort +
                          " � ��� ����� ���������� ����� ��������.";
                link.l1 = "������ ������� � �����, " + GetAddress_FormToNPC(NPChar) + ".";
                link.l1.go = "attack_fort";

                link.l2 = "� ����� ������ �� ���� ��� ������ �����������. ��������, "+ GetAddress_FormToNPC(NPChar) + ".";
                link.l2.go = "exit";
    			
            }
            else
            {
                Dialog.text = "� �� ����������� ������ ���� � ����, ���������� � ������������ ����� �������. ��� ��� " + GetFullName(rchar)+
                              ", �� ��������� �� ������� " + XI_ConvertString(RealShips[sti(rchar.Ship.Type)].BaseName) + " ''" + rchar.Ship.Name + "''.";
                link.l1 = "�������. ��� � ��������.";
                link.l1.go = "exit";
            
            }
            Diag.TempNode = "Siegehelp";
            
		break;
		
		case "attack_fort":
                dialog.text = "� � ��� �� ���� ����?";
                link.l1 = "� ���� ������ ��� ���������� ���� ������� " +GetConvertStr(aData.Colony+" Town", "LocLables.txt")+ " � ��������� �����, � ������, ���������� � ������ ������ ������, �� ������� ����� �����.";
                link.l1.go = "Siegehelp_1";
                link.l2 = "����������, ��� ���� ���� �� ����������� ������ ��������. ��������, "+ GetAddress_FormToNPC(NPChar) + ".";
                link.l2.go = "exit";
                Diag.TempNode = "Siegehelp_0";
		break;
		
		case "Siegehelp_0":
            Dialog.text = "��� ����� ��? ��� ��������, �� ��� ��� ��������?";
            link.l1 = "�� ����� - �����"+ GetSexPhrase("","�") +".";
			link.l1.go = "exit";
			NPChar.DeckDialogNode = "Siegehelp_0";
            Diag.TempNode = "Siegehelp_0";

		break;
		
		case "Siegehelp_1":
            SiegeResult("");
            if (sti(aData.win)==0)
            {
                dialog.text = "� ����� �� ����� ������ �� ������������� ��������?";
                link.l1 = "��������.";
                link.l1.go = "Big_part";
                link.l2 = "���� �����.";
                link.l2.go = "Middle_part";
                link.l3 = "��������� �����.";
                link.l3.go = "Small_part";
            }
            else
            {
                dialog.text = "��� �� ��������� ���� ������, �������! � �� �������� �� � ���� ������, ��� ��� � ����� ������ ������� ��� �������.";
                link.l1 = "������ ����� �����������, " + GetAddress_FormToNPC(NPChar) + ", ������� ����� ���������� ������.";
                link.l1.go = "attack_fort_03";
                link.l2 = "� ����� ������ �� ���� ��� ������ �����������, " + GetAddress_FormToNPC(NPChar) + ". ��������!";
                link.l2.go = "exit";
            }
			Diag.TempNode = "Siegehelp_0";

		break;
		
		case "attack_fort_03":
            if((sti(aData.iSquadronPower)*SquadronDamage - (ifortPower)*fortDamage) < 4000)
            {
                dialog.text = "� ������ �������, ��� ������� ��� ������� ��������� � ���� ��������, � ������������ ��� �� �� ��������. ���� �� �������� �� " + GetPart(4) + ", ��, � �����, �� ������ ������������.";
                link.l1 = "���� ��� ����������, " + GetAddress_FormToNPC(NPChar) + ". � ��������� ����� ���� �������, � �� �� ����� ������� ���������� ��� ����� ����������� ������.";
                link.l1.go = "attack_fort_04";
                aData.PartAttaksFort = 4;
                link.l2 = "� ���� �� ��� ������, " + GetAddress_FormToNPC(NPChar) + ". ����� ��������, ��� �������"+ GetSexPhrase("","�") +" ��� �� �������� ���. ��������.";
                link.l2.go = "exit";
            }else{
                dialog.text = "� ���� ������� ���������� ��������, ����� �������� ���� ���� � ��� � ����, ��� ������ ������ �������. � ������ ���������� �������� ��� �������, ������� ���� ������� ������!";
                link.l1 = "�� ��� �, � ����� ������, " + GetAddress_FormToNPC(NPChar) + ", ��������� �����������. ��������!";
                link.l1.go = "exit";
            }
		    Diag.TempNode = "Siegehelp_0";
		break;
		case "Big_part":
            if( (sti(aData.iSquadronPower)*SquadronDamage - (ifortPower)*fortDamage) <= -1500)
            {
                dialog.text = "������ ����� ������ ��������� ������� ���� �������, � ����� ����� �������� ����� ���������� �� � ���� ������. � �������� �� ���� ������� � �������� ���� ������.";
                link.l1 = "�������, " + GetAddress_FormToNPC(NPChar) + ", � ����� ������ �� ������� ���� �������, � �� �� ���������� ��� ����� ����������� �����.";
                link.l1.go = "attack_fort_04";
                aData.PartAttaksFort = 2;
            }
            else
            {
                dialog.text = "�� ��������� ��, �������? � ��� " + GetNumShips(GetCompanionQuantity(PChar)) +
                              ", � ���� ������� " + GetNumShips(Group_GetCharactersNum(sGroup)) + ". � ���� ��� ���������� " + GetPart(4) +
                              ". � � �����, ��� ���������.";
                aData.PartAttaksFort = 4;
                link.l1 = "� ������"+ GetSexPhrase("��","��") +", " + GetAddress_FormToNPC(NPChar) + ", � ����� ������, � ���� �� ���� ������ �����, � �� �� ���������� ��� ����� ����������� ������.";
                link.l1.go = "attack_fort_04";
                link.l2 = "� ���������, � ��� �� �����, " + GetAddress_FormToNPC(NPChar) + ". ��� ������ �� � ��� �������������. ��������.";
                link.l2.go = "exit";
            }
            Diag.TempNode = "Siegehelp_0";
        break;
        
        case "attack_fort_04":
            dialog.text = "��� ������ ���� ����� ��������, �� ���������� �������� ������� ��������� ����� �� �����, � ������ ��� ��������� ��� � ����� ������, ���, � �������, �� � ���������� � ����.";
            link.l1 = "�� ���� � �������. �� �������, " + GetAddress_FormToNPC(NPChar) + "!";
            link.l1.go = "exit";
            Diag.TempNode = "Siegehelp_0";
            PChar.quest.Union_with_Escadra = "Yes";
        break;

        case "Middle_part":
            if((sti(aData.iSquadronPower)*SquadronDamage - (ifortPower)*fortDamage) <= -600)
            {
                dialog.text = "�������, � ��������� �� ���� �������. ���������� �������� ����������� ��� ����� �� ������������� ����� ����� ��������. � ������ ��������� ���������� ���� �� �������� ���� ����� ������.";
                link.l1 = "�� ��� � ������, ��� �� ������������, " + GetAddress_FormToNPC(NPChar) + ". � ���������� ����� ������ ����� ����� ��������� ����.";
                link.l1.go = "attack_fort_04";
                aData.PartAttaksFort = 3;
            }else{
                dialog.text = "�� ��������� ��, �������? � ��� " + GetNumShips(GetCompanionQuantity(PChar)) + ", � ���� ������� " + GetNumShips(Group_GetCharactersNum(sGroup)) + ". � ���� ��� ���������� " + GetPart(4) + ". � � �����, ��� ���������.";
                link.l1 = "� "+ GetSexPhrase("��������","��������") +", " + GetAddress_FormToNPC(NPChar) + ", � ����� ������ � ���� �� ���� ����� �����, � �� ���������� ��� ����� ����������� ������.";
                link.l1.go = "attack_fort_04";
                aData.PartAttaksFort = 4;
                link.l2 = "� ���������, � ��� �� �����, " + GetAddress_FormToNPC(NPChar) + ". ��� ������ �� � ��� �������������. ��������.";
                link.l2.go = "exit";
            }
            Diag.TempNode = "Siegehelp_0";
        break;

        case "Small_part":
            dialog.text = "������� ���� ������� �������� ���������, ��� ��� ������ ���� ��� �� ��������. � �������� �� ��� ������� � �������� ���� �����������.";
            link.l1 = "� ���"+ GetSexPhrase("","�") +", ��� �� ������ ������������, " + GetAddress_FormToNPC(NPChar) + ". � ���������� ����� ������ ����� ����� �������� � ��� � ������ ����� �����.";
            link.l1.go = "attack_fort_04";
            aData.PartAttaksFort = 4;
            Diag.TempNode = "Siegehelp_0";
        break;
		
		case "Talk_Capture_City":
            AfterTownBattle();  // ���, ��� ��������
            LAi_LoginInCaptureTown(NPChar, false);
            aData.win = 1;
            EndOfTheSiege("End");
            NPChar.location = "";
            int ilt = makeint(sti(aData.loot)/sti(aData.PartAttaksFort));
            dialog.text = "������������, �������! ���� ����� � ���� ������, �� ���-���� ��� ������� ������� �������� ������������� ���������� ������. ������ ���������� " + sti(aData.loot)+
                          " ����. � �� ������ �������� �� ��������� "+ilt+
                          ". ��� ���� ������, �� ��, ����������, ���������. � ������ ����� ���� ��������, �� ���� ���� ����.";
            link.l1 = "� ����� ������ ��������� �����������, " + GetAddress_FormToNPC(NPChar) + ". ��������!";
            link.l1.go = "exit";
            //AddDialogExitQuest("End_Siege_and_Attaks_City");

            Diag.TempNode = "no_return_02";
            AddMoneyToCharacter(PChar, ilt);
            ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
            ChangeCharacterComplexReputation(PChar,"nobility", 10);
            AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 80);
            AddCharacterExpToSkill(GetMainCharacter(), "Sailing", 100);
            AddCharacterExpToSkill(GetMainCharacter(), "Defence", 100);
            AddCharacterExpToSkill(GetMainCharacter(), "Accuracy", 100);
            AddCharacterExpToSkill(GetMainCharacter(), "Cannons", 100);
            AddCharacterExpToSkill(GetMainCharacter(), "Fortune", 80);
            aData.loot = sti(aData.loot) - ilt;
            if (CheckAttribute(PChar, "quest.LeaveTown")) Pchar.quest.LeaveTown.over = "yes";
            //--> �����
            SiegeRumour("������ ����, ��� �� ������� ����� ������� ��� ������ "+NationNameSK(sti(aData.conation))+"�� ������� - "+GetConvertStr(aData.Colony+" Town", "LocLables.txt")+"! �� ��� ���������� ���, "+ GetAddress_Form(NPChar)+".", "", sti(aData.nation), -1, 30, 3);
            //<-- �����
		break;

        case "no_return_02":
            dialog.text = "����������� ���, �������! � ��� �� ��� ����?";
            link.l1 = "�������, " + GetAddress_FormToNPC(NPChar) + ". ��������!";
            link.l1.go = "exit";
            Diag.TempNode = "no_return_02";
		break;
		
		case "GoldSquadron":
            ref rch = Group_GetGroupCommander("Sea_Head_of_Gold_Squadron");
            if (NPChar.id == rch.id)
            {
    			dialog.text = "� ��� ������, �� ������� �������� ������������ ���� ������ ������, � ����� �����. �� ���� ��������� ������ ������ ���������� ���������, � � ���� �� ��� ���������� ������ ��� �������������� ������� � �������� ����, ������� ����� ������������ ��������� ������ ������.";                          
                link.l1 = "� ����� ������ �� ���� ��� ������ �����������. ��������, "+ GetAddress_FormToNPC(NPChar) + ".";
                link.l1.go = "exit";

            }
            else
            {
                Dialog.text = "� �� ����������� ������ ���� � ����, ���������� � ������������ ����� �������. ��� ��� " + GetFullName(rch)+
                              ", �� ��������� �� ������� " + XI_ConvertString(RealShips[sti(rch.Ship.Type)].BaseName) + " ''" + rch.Ship.Name + "''.";
                link.l1 = "�������. ��� � ��������.";
                link.l1.go = "exit";

            }
            Diag.TempNode = "GoldSquadron";
		break;
		
		case "WM_Captain":
			dialog.text = "������� �������������, � ���� ����� " + GetFullName(npchar) + ". ��� �� ������ ��� �� ������? �, ����� � ������� ���, ��� ��������� � ��� ������������� ����������� - ���� � ������� ������������ �������, ������� ���� �� �����, �������� ������ � �������...";
			link.l1 = "��� � ������, ��� �������� ��������� ��� � ��������, � ����� ��� � �����...";
			link.l1.go = "WM_Captain_1";
			pchar.quest.DesIsland_Over.over = "yes";//����� ����������
		break;
		
		case "WM_Captain_1":
			dialog.text = "��� �����. ��� ������� ������ ��������� � ��� - ��� ���� �������� �������� ���������� ����� ���� ���������. � ����� ������� �����... ��, ���� ���������� �� ���� �� ����. ��� ������� � ����� ���������������� ������ - �� ����� ���� � ����� ������ �� ������, � ������ ��������� ����, ����� ���� ���������\n� ��� �� �����. �� ��� ������ ����� ��� �������, �� - ���� ������: ������� �������� ���� ������ ��������� �������, ��� ������� ����� ����� - � ��� �� �����? ������ � ��������. �� ������ ����� ��������, � �� ���������� ��� � ����� ����� ������� ���������� ���������\n� ���������� � ���� � ������ ������������� - ����������� ������������. ��� � �����, �������...";
			link.l1 = "�-��... ��������� ����������. ������� ��������, ��� ����� �����������, � ��� � ���� ��� ������.";
			link.l1.go = "WM_Captain_2";
		break;
		
		case "WM_Captain_2":
			dialog.text = "��, ���� �� � ��� ���� ����� � �������� � ����������� ���������� - �� �� �� ������ ��������������� ����� - ���� �� ��� ���������\n�������, ��� �� ���������� ������ ��� �� ������� - �� ����� �� �� �� ����������� � ��������� ����, �������� ������������ ��������� ��� ������� � �������� ����? ����� �������, �������� ���� �� ������. ���������� ������� ����� ��� �� ������� - � ����������� ��� ���� ������� �� �������.";
			link.l1 = "����������. ������� � ���� ��� ����� ���������?";
			link.l1.go = "WM_Captain_3";
		break;
		
		case "WM_Captain_3":
			pchar.questTemp.WPU.Escort.Planks = 300 + drand(5)*10;
			pchar.questTemp.WPU.Escort.Sailcloth = 150 + drand(10)*10;
			pchar.questTemp.WPU.Escort.Linen = 70 + drand(7)*10;
			dialog.text = "� ��� ����� ��� ��������. � ������ ��������������, ��� ���������� "+FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Planks))+" �����, "+FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Sailcloth))+" �������� � "+FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Linen))+" ������. ���� ���� �����, �� �� � ��������� ���� ���������� � �������� � ����� � ����.";
			link.l1 = "������. � �������� ��� ����������� ���������. ����� ����, � ������� �� �����, ��� ����� ������ ����.";
			link.l1.go = "WM_Captain_4";
		break;
		
		case "WM_Captain_4":
			dialog.text = "�������� �������, �������! ���, ������ � ���� ��������. �� ����� ����� ��� � �������� � ����� ��������� �����������!";
			link.l1 = "�� �����������. ����� � ��� ����� �� ����������� ��� �������.";
			link.l1.go = "exit";
			AddQuestRecord("Escort", "27");
			AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
			AddQuestUserData("Escort", "sIsland", XI_ConvertString("Colony"+pchar.questTemp.WPU.Current.TargetIslandID));
			AddQuestUserData("Escort", "sQty1", FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Planks)));
			AddQuestUserData("Escort", "sQty2", FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Sailcloth)));
			AddQuestUserData("Escort", "sQty3", FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.Linen)));
			Diag.TempNode = "WM_Captain_again";
			SetFunctionTimerCondition("WM_Captain_Over", 0, 0, 11, false);
			pchar.questTemp.WPU.Escort = "wait";
		break;
		
		case "WM_Captain_again":
			dialog.text = "�� ����� � ����������� ������� ������ �����������, �������!";
			link.l1 = "��� �������� �����!";
			link.l1.go = "exit";
			Diag.TempNode = "WM_Captain_again";
		break;
		
		case "WM_Captain_5":
			dialog.text = "�����������! ����� �� ����� ���������� � ������� �����!";
			link.l1 = "��� ���� ��� ������� - ��� �� ������� ���������. ����� ����, � ������ ��� ����������� �� ������� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity)+", ��� ��� ��� ������� �� ��������� - ��� ����� ��� ����.";
			link.l1.go = "WM_Captain_6";
		break;
		
		case "WM_Captain_6":
			pchar.questTemp.WPU.Current.TargetIslandID.Shore = SelectQuestShoreLocationFromSea(pchar.questTemp.WPU.Current.TargetIslandID);
			dialog.text = "��, ���� � �� ����, ��� ��� ��� �����������, �������... ��������� �������� ��������� � ����� ��� ��������� " + XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID.Shore) + " - �� ��� ��� ����������� ��� �������.";
			link.l1 = "������. ���������� �� ������.";
			link.l1.go = "exit";
			AddQuestRecord("Escort", "29");
			AddQuestUserData("Escort", "sShore", XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID.Shore+"Gen"));
			pchar.quest.DisasterShip_WMC.win_condition.l1 = "location";
			pchar.quest.DisasterShip_WMC.win_condition.l1.location = pchar.questTemp.WPU.Current.TargetIslandID.Shore;
			pchar.quest.DisasterShip_WMC.function = "RepairShip_Prepare";
			Diag.TempNode = "WM_Captain_repeat";
		break;
		
		case "WM_Captain_repeat":
			dialog.text = "���������� � �������, �������? ��� ��� �� ������.";
			link.l1 = "��, �������. ��� �����������.";
			link.l1.go = "exit";
			Diag.TempNode = "WM_Captain_repeat";
		break;
		
		case "Repair_start":
			dialog.text = "�� ���, ��� ������ � ���������� ��������� �����. �����, ���� �� ���� ���������.";
			link.l1 = "��� � �������! � ����� ����� ������� ����������� ���� ������, ��� ��� ����� �� �������� �����.";
			link.l1.go = "Repair_start_1";
		break;
		
		case "Repair_start_1":
			DialogExit();
			pchar.quest.WM_Captain_Over.over = "yes";//����� ����������
			sld = characterFromId("WMCaptain");
			LAi_SetImmortal(sld, false);
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 5.0);
			RemoveCharacterGoods(pchar, GOOD_PLANKS, sti(pchar.questTemp.WPU.Escort.Planks));
			RemoveCharacterGoods(pchar, GOOD_SAILCLOTH, sti(pchar.questTemp.WPU.Escort.Sailcloth));
			RemoveCharacterGoods(pchar, GOOD_COTTON, sti(pchar.questTemp.WPU.Escort.Linen));
			DoQuestFunctionDelay("RepairShip_WithoutMasts", 5.0);
		break;
		
		case "Repair_end":
			dialog.text = "��� � ���. ������� ��������, ��� ������� ����� � ������ � ����. ����� ������������, �������?";
			link.l1 = "���� �� ������, �� ������������� ����� ������ � �� ����. ��������� �����!";
			link.l1.go = "Repair_end_1";
		break;
		
		case "Repair_end_1":
			DialogExit();
			sld = characterFromId("WMCaptain");
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 5.0);
			AddQuestRecord("Escort", "30");
			AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
			AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity));
			SetFunctionTimerCondition("DisasterShipWM_Over", 0, 0, 25, false);
			log_info("� ��� 25 ����, ����� �������������� "+pchar.questTemp.WPU.Escort.ShipBaseName+" '"+pchar.questTemp.WPU.Escort.ShipName+"' � ���� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+"");
			pchar.quest.DisasterShip_final.win_condition.l1 = "location";
			pchar.quest.DisasterShip_final.win_condition.l1.location = pchar.questTemp.WPU.Escort.StartCity +"_town";
			pchar.quest.DisasterShip_final.function = "WMShip_final";
		break;
		
		case "WMShip_final":
			pchar.quest.Escort_fail.over = "yes";
			pchar.quest.DisasterShipWM_Over.over = "yes";//������� ��� ����������
			RemoveCharacterCompanion(Pchar, characterFromID("WMCaptain"));//������� ����������
			pchar.questTemp.WPU.Escort.LevelUp_1Money = sti(pchar.questTemp.WPU.Escort.Planks)*15+sti(pchar.questTemp.WPU.Escort.Sailcloth)*9+sti(pchar.questTemp.WPU.Escort.Linen)*45;//������ �� ���������
			dialog.text = "���� ��� ��� ��� �������������, �������, �� ��, ��� �������� ���� � ��� ������� �� ���� ���������. ��� � � ������ - � ����������� ���� ������� �� ��������� ��� ������� ����� �����. ����� "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.LevelUp_1Money))+", ��������, ����������. � ��� ��� ���� ������� ����� �� ����.";
			link.l1 = "��� ��� ������ ���.";
			link.l1.go = "WMShip_final_1";
		break;
		
		case "WMShip_final_1":
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.LevelUp_1Money));
			TakeNItems(pchar, "obereg_"+(drand(10)+1), 1);
			dialog.text = "��, � ������ ��� ���� ����������, �������. �� �������� ����� � �������� ���������� - ��� ��� ��� ����. �� ��������!";
			link.l1 = "����� �������, " + npchar.name + "!";
			link.l1.go = "WMShip_final_2";
		break;
		
		case "WMShip_final_2":
			chrDisableReloadToLocation = false;
			bDisableFastReload = false;
			DialogExit();
			sld = characterFromId("WMCaptain");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", 5.0);
			if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1WM")) AddQuestRecord("Escort", "31");
			if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1VSP")) AddQuestRecord("Escort", "37");
			if (CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp_1S")) AddQuestRecord("Escort", "40");
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.LevelUp_1Money)));
			AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
			AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
		break;
		
		case "VSP_Captain":
			dialog.text = "��� ���! � � �����, ��� ��� ��� ��� ������. ��, ����� ������� �� ������� ������ ����. ����� ����, ��� ����� ������� ������� ���������� ����� ��������, �� ����� �������� � ��������������� �������. ��� ������� � ����� ���������������� ������\n�� ��������� ���� ��������, ������ �������, ������������ �����, ��� ���������� ����� � ����, ��� �� ��� ����� ������ ��� ��������������. ��������, ��� ��� ��� ����� ���� �� ������ ������� �������\n� ����� ����� ������� ����� - �� ��� ������, ��� ������� ������������ ����������� �� ��� � ���������� � �������. �� ��� ��������� ��, ����� ��������� ���� �����! ������� ��� ��� ���, �������!";
			link.l1 = "��� ��� ������, " + GetAddress_FormToNPC(NPChar) + ". ������ � ������ ����������� ��� �� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+", ���� ������� �� ���� ��������� ���. �� ������ ����������� � ���� ����������? ����� ��� ����� �� �����.";
			link.l1.go = "VSP_Captain_1";
		break;
		
		case "VSP_Captain_1":
			dialog.text = "�������! ��� ������� �� ������� ��� �����, ��� ��������� ����� ��� ������������� �������. ������������!";
			link.l1 = "�������� �� ���� ��������. � ��������� ���� ������� - ����� ��� ������ �� ��������.";
			link.l1.go = "VSP_Captain_2";
		break;
		
		case "VSP_Captain_2":
			pchar.quest.DisasterShip_GetOut.over = "yes";
			DialogExit();
			Group_DelCharacter("WMShip", "WMCaptain");//����� ����� ����
			sld = characterFromId("WMCaptain");
			LAi_SetImmortal(sld, false);
			SetCharacterRemovable(sld, false);
			sld.CompanionEnemyEnable = false; //������ ������
			SetCompanionIndex(pchar, -1, sti(sld.index));
			sld.loyality = MAX_LOYALITY;
			AddQuestRecord("Escort", "36");
			AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
			SetFunctionTimerCondition("DisasterShipWM_Over", 0, 0, 25, false);
			log_info("� ��� 25 ����, ����� �������������� "+pchar.questTemp.WPU.Escort.ShipBaseName+" '"+pchar.questTemp.WPU.Escort.ShipName+"' � ���� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+"");
			pchar.questTemp.WPU.Escort = "win";
			pchar.quest.Escort_fail.win_condition.l1 = "NPC_Death";//���������� �� ���������� ���������������
			pchar.quest.Escort_fail.win_condition.l1.character = "WMCaptain";
			pchar.quest.Escort_fail.function = "DisasterShipWM_failed";
			pchar.quest.DisasterShip_final.win_condition.l1 = "location";
			pchar.quest.DisasterShip_final.win_condition.l1.location = pchar.questTemp.WPU.Escort.StartCity +"_town";
			pchar.quest.DisasterShip_final.function = "WMShip_final";
			Diag.currentnode = "VSP_Captain_again";
			Delete_EscortStorm();//������ �����
		break;
		
		case "VSP_Captain_again":
			dialog.text = "������������ � ����, �������?";
			link.l1 = "��, �������. � ��� ����������� �� ���� �������.";
			link.l1.go = "exit";
			Diag.TempNode = "VSP_Captain_again";
		break;
		
		case "VSPShip_final":
			pchar.quest.Escort_fail.over = "yes";
			pchar.quest.DisasterShipWM_Over.over = "yes";//������� ��� ����������
			RemoveCharacterCompanion(Pchar, characterFromID("WMCaptain"));//������� ����������
			pchar.questTemp.WPU.Escort.LevelUp_1Money = 10000+sti(pchar.rank)*200;
			dialog.text = "���� ��� ��� ��� �������������, �������, �� ��, ��� �������� ���� � ��� ������� �� ���� ���������. ����� "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.LevelUp_1Money))+". �� ������� ��� ���� �������� ��� ���, ��������, ����������, � �� ��������� ������������. � ��� ��� ���� ������� ����� �� ����.";
			link.l1 = "��� ��� ������ ���!";
			link.l1.go = "WMShip_final_1";
		break;
		
		case "SShip_final":
			pchar.questTemp.WPU.Escort.LevelUp_1Money = 5000+sti(pchar.rank)*100;
			RemovePassenger(Pchar, npchar);//������� ���������
			dialog.text = "���� ��� ��� ��� �������������, �������, �� ��, ��� �������� ���� � ��� ������� �� ���� ���������. ������� �� ���� ��� ������ - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.LevelUp_1Money))+", ��� ��� ���� �������. ��� �������, �� ��� ��, ��� � ���� ������������� ��� �� ���� ��������. � ����� ��� �� ������������\n��� ������ ������� ��������� ���� - ��� �� ������� �� ������ � ���������, � ��� ������������ � ��������� ��������. ��� ��� ����� �������� � ��� �� ������. �������, �� �� �������� �������, ���������� ���� �����, � �� ��������� ������� - ������� ��� ����� � �������?";
			link.l1 = "���, �������. � � ������������� ������� �� � ����� �������. ��� ��� ������ ���!";
			link.l1.go = "WMShip_final_1";
		break;
		
		//����������� ������
		case "Stivesant_1":
			dialog.text = "���. �� ����� �������� �����������, ������, ��� ����� ����������? ������ '�������' ��������� ��� ����� �������������? � �������� ��������� ���������?";
			link.l1 = "� ���� ���� ��� ������������� ����������. ����� ����, � ���� ������ ���������� ��� ���.";
			link.l1.go = "Stivesant_2";			
		break;
		
		case "Stivesant_2":
			dialog.text = "����� � ��� ����������� ������.";
			link.l1 = "� ����������� �������� ���������. ����� ��������� ����� ����� �����������, ������ ��� ������� �� � ������ �� ��������� ���������� ���������� � ����� � ���������� ���������.";
			link.l1.go = "Stivesant_3";			
		break;
		
		case "Stivesant_3":
			dialog.text = "��... ������, �� ������������� ������������ ����. � �� ��� ����� ������� ������� �� �����������, � �� � ��� �������� � ��� �� ����������.";
			link.l1 = "���������� ���� �� �����, ������ ����������. ������� �� ��������� �������� ����� �������������� ����������, � �� ������, ��� �� �� ������� �� �������.";
			link.l1.go = "Stivesant_4";			
		break;
		
		case "Stivesant_4":
			dialog.text = "������, ���� ����� ��� �������� ��� ������ � ������. ��� �� ������ �����?";
			link.l1 = "� ������ ������� � ������ �������, �������� ������������� ������ ����������� ����������. ����� ��������� ����� ������ ������� ���������� ��� �������, � ��� � ����� ���� �� ���������. ��������� ���, ��� '�������' �� ������� �� � ��� ����������, �� ����� �� ��� ������� ��� ������� �����.";
			link.l1.go = "Stivesant_5";			
		break;
		
		case "Stivesant_5":
			dialog.text = "������ �� ������ �������, ��� �����...";
			link.l1 = "����� �������� ��� � ����� ��������� �������� ����� ������� �������� - ����� ����������� ����������. ����� ���, ��� ����� �������� � �������, ���������� ������� ����� �� �� �� ���� ������������ ������������� ������� ���������� �� ����������.";
			link.l1.go = "Stivesant_6";			
		break;
		
		case "Stivesant_6":
			dialog.text = "���� �� ����!";
			link.l1 = "� �� ������� � ����� ���� � ���������� ��������� � ���������� �������������. �����, ��� '�������', �������� ��� ������� ��������� ������������, ����� � ����������� �����������, � ������ �� � ��� ���. �������� � ���� �������, � ������� �� ���� ��� ��� ����������, � ��� ����� � ��� ��� ������.";
			link.l1.go = "Stivesant_7";			
		break;
		
		case "Stivesant_7":
			dialog.text = "��... ������ �� ������. �����, ����� ����������, �� ���� � �� ��� ����� �� � �������, �� � �������� ���������� ����� �������! ���������! ��� ������! ��� �������?!";
			link.l1 = "� �������� ��� � ����� �� �������������� ���������. ���� �������, �� �� ����� �������� ��������� ������ ����������, �� �� ������������ ���� �� ���. �� ������, ��� �� ������ � ���������� ����� �� �������� - ��������� ������� ��������� ����������� ���� ��� ��������.";
			link.l1.go = "Stivesant_8";			
		break;
		
		case "Stivesant_8":
			dialog.text = "���... ������� " + GetFullName(pchar) + ", �� ����������� �� ���� � ����������. ����������� �� '�������' ������� ����� �������. ���� ��� ��� ������, ��� �� ������� - ����� ������ ���� ���������, � �� ������� � ���� ����������. �� ���� �� ��� �������... ������� �� ����.";
			link.l1 = "��� ��� ������ ����� ���, ������. ����������� � ����!";
			link.l1.go = "Stivesant_9";			
		break;
		
		case "Stivesant_9":
			DialogExit();
			Diag.CurrentNode = "Stivesant_10";
			AddQuestRecord("Holl_Gambit", "3-52");
			pchar.questTemp.HWIC.Self = "WayWithStivesant";
			Group_DelCharacter("Stivesant_Halleon", "Stivesant");
			SetCharacterRemovable(npchar, false);
			npchar.CompanionEnemyEnable = false; //������ ������
			SetCompanionIndex(pchar, -1, sti(npchar.index));
			npchar.loyality = 40;
			DeleteAttribute(npchar, "LifeDay");
			pchar.quest.Seek_Piter.win_condition.l1 = "location";
			pchar.quest.Seek_Piter.win_condition.l1.location = "Villemstad_town";
			pchar.quest.Seek_Piter.win_condition.l2 = "Day";
			pchar.quest.Seek_Piter.function = "StivesantOnStreet";
			pchar.quest.Terms_Over.win_condition.l1 = "Timer";
			pchar.quest.Terms_Over.win_condition.l1.date.hour  = sti(GetTime());
			pchar.quest.Terms_Over.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 15);
			pchar.quest.Terms_Over.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 15);
			pchar.quest.Terms_Over.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 15);
			pchar.quest.Terms_Over.function = "QuestShipsTerms_Over";
		break;
		
		case "Stivesant_10":
			dialog.text = "�������, ������������� �� '�������'. ��� ���� � ����.";
			link.l1 = "��, �������, ������.";
			link.l1.go = "exit";
			Diag.TempNode = "Stivesant_10";
		break;
		
		case "Keller_1":
			dialog.text = "����� ���������! ��, �������������. ��� ����� - ��� ������.";
			link.l1 = "������ ������, �������, ��������� ������� ����� �� ��������� �� ���� � ���������� �����. �� ��� ���� ����� ��������� ��������. �� ��������� �� ����� ����� �������, ����� ����������� � ���������� ����.";
			link.l1.go = "Keller_2";
		break;
		
		case "Keller_2":
			dialog.text = "��, �������, � ���������� ����� ��������. ��, �����, ��������. � � ��� �� ����?";
			link.l1 = "����� ��� �������� � ���� �� ���� �������. �������� ������� ������ �����, ���� �������� - �������� � ��� ������ ��������. ��� �������� �� ������� ��������� � ���������� ����� �� ����� ���������. ��� ����� ����� ���� ������. ���������, ����������, ��� ���� ����� ����� ������� � ���� �������? ��� ����� �����.";
			link.l1.go = "Keller_3";
		break;
		
		case "Keller_3":
			dialog.text = "� �����-��? � ���� ���� ������. �� ������ ������ ������, ����� ���������� � �������. ���������, ��������� ����������� ��������. �� ��� ��� ���� ��������.";
			link.l1 = "�� ������ ������� ��������������� ����������?";
			link.l1.go = "Keller_4";
		break;
		
		case "Keller_4":
			dialog.text = "� ������ ��� ������. 12 ��. 48' �������� ������ � 64 ��. 41' �������� �������� �������. ����� � ���� ������. ������ ���������, ��, �����, �� ��� ��� ����� �������.";
			link.l1 = "�������, ������ ������! �� ��� ����� �������! �� ��������.";
			link.l1.go = "Keller_5";
		break;
		
		case "Keller_5":
			DialogExit();
			Diag.CurrentNode = "Keller_6";
			pchar.quest.Keller_fail.over = "yes";
			pchar.questTemp.HWIC_Coordinates = "true"; //������� ��������� �� ����� ������� ����� �����
			DeleteAttribute(pchar, "questTemp.HWICMC");
			AddQuestRecord("Holl_Gambit", "3-66");
		break;
		
		case "Keller_6":
			dialog.text = "�� ���-�� ��� ������ ������, �������?";
			link.l1 = "���, �������. � ��� ����������� �� ���� �������.";
			link.l1.go = "exit";
			Diag.TempNode = "Keller_6";
		break;
	}
}

string GetNumShips(int ship)
{
    string numships;
    switch(ship)
    {
       case 0: numships = "�� ������ �������"; break;
       case 1: numships = "���� �������";      break;
       case 2: numships = "��� �������";       break;
       case 3: numships = "��� �������";       break;
       case 4: numships = "������ �������";    break;
       case 5: numships = "���� ��������";     break;
       case 6: numships = "����� ��������";    break;
    }
    return numships;
}

string GetPart(int part)
{
    string numpart;
    switch(part)
    {
       case 0: numpart = ""; break;
       case 1: numpart = "��� ������"; break;
       case 2: numpart = "�������� ������"; break;
       case 3: numpart = "����� ������"; break;
       case 4: numpart = "�������� ������";      break;

    }
    return numpart;
}

int findPriceStoreMan(ref NPChar)
{
    ref ch;
	int n;
    int storeArray[40];
    int howStore = 0;

	for(n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(ch,Characters[n]);
		if (CheckAttribute(ch, "Dialog.Filename") && ch.Dialog.Filename == "Common_Store.c") // �������
		{
            //if (sti(ch.nation) !=  sti(NPChar.nation)) continue;
            if (ch.location == "none") continue; // ���� ��� �����, ��������� �� ���� ��������
            storeArray[howStore] = n;
            howStore++;
            
            // homo 05/09/06
            if ( CheckAttribute(NPChar, "FromColony") && NPChar.FromColony == ch.City ) return n;
            //
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
