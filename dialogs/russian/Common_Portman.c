#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag, arCapBase, arCapLocal;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	// ��� ������
	if (!CheckAttribute(NPChar, "Portman")) NPChar.Portman = 0;
	if (!CheckAttribute(NPChar, "PortManPrice")) NPChar.PortManPrice = (0.06 + frnd()*0.1);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\PortMan\" + NPChar.City + "_PortMan.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06

    int i, cn, iTemp;
    ref chref;
	ref rRealShip;
    string attrL, sTitle, sCapitainId, s1;
	string sColony;
    
	String sLastSpeakDate = LastSpeakDate();
	
	// Warship 25.07.09 ����� "��������� �����". ���� ������ �� - ���� �������, �� ��������� ����� ������ �� ���� �����
	if(CheckAttribute(NPChar, "Quest.BurntShip.LastQuestDate") && NPChar.Quest.BurntShip.LastQuestDate != sLastSpeakDate)
	{
		DeleteAttribute(NPChar, "Quest.BurntShip");
	}
    
    bool ok;
    int iTest = FindColony(NPChar.City); // ����� ��������
    ref rColony;
    string sFrom_sea = "";
	npchar.quest.qty = CheckCapitainsList(npchar); //��� ������ �����

	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
		sFrom_sea = rColony.from_sea;
	}
	
	attrL = Dialog.CurrentNode;
	
	if(HasSubStr(attrL, "ShipStockManBack_"))
 	{
        i = findsubstr(attrL, "_" , 0);
	 	NPChar.ShipToStoreIdx = strcut(attrL, i+1, strlen(attrL)-1); // ����� � �����
 	    Dialog.CurrentNode = "ShipStockManBack";
 	}
    
	if(HasSubStr(attrL, "BurntShip19_"))
	{
		i = findsubstr(attrL, "_" , 0);
	 	NPChar.Quest.BurntShip.ShipCompanionIndex = strcut(attrL, i + 1, strlen(attrL) - 1); // ����� � �����
 	    Dialog.CurrentNode = "BurntShip19";
	}
    
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "First time";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("� ������ ������� �������, ���� ����� ����! �� ����� ����� � �� �� ���� ����� �������������.", "��� ��������� ������ ����� �� ������ � ������� ����. � �� ����� � ������������� � ����� �� ����!", "����, "+ GetSexPhrase("��������","�������") +", ���� ������� �� ������� �� ���� ������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����","") +"!", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ����� ����! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "���, " + GetWorkTypeOfMan(npchar, "") + ", � ��� ���� �� - ������� ������! ��� ��� � ���� �����, ��������: ���� ���� � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
			//Jason, �����
			if (CheckAttribute(pchar, "questTemp.WPU"))
			{
				if (pchar.questTemp.WPU.Fraht == "fail" && pchar.questTemp.WPU.Fraht.Nation == npchar.nation)
				{
					dialog.text = "�-�, � ����, ��� ��. �� ����������� ��������� ���� � ������ ���! ������, ����!";
					Link.l1 = "�-�-��!";
					Link.l1.go = "exit";
					LAi_group_Attack(NPChar, Pchar);
					break;
				}
			}
			//�����
			//--> Jason ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				dialog.text = "��� ���� ���� �������, �����?";
				Link.l1 = "� ���� � ��� ���� ����...";
				Link.l1.go = "quests";
				Link.l2 = "����� ��������, �� ��� ���� ����.";
				Link.l2.go = "exit";
				NPChar.quest.meeting = "1"; // patch-6
				break;
			}			
			//<-- ����� ��������
			if(NPChar.quest.meeting == "0")
			{
				NPChar.quest.meeting = "1";
				dialog.text = "����������� ���, " + GetAddress_Form(NPChar) + ". ��, �������, �� �������. � "  + GetFullName(npchar)+ " - ��������� �����.";
				Link.l1 = "������������, " + GetFullName(NPChar) + ". � " + GetFullName(PChar) + ", ������� ������� '" + PChar.ship.name + "'.";
			}
			else
			{
				dialog.text = LinkRandPhrase("����������� ���, " + GetAddress_Form(NPChar) + ". �� �� ��� �� ����?",
                                    "������������, " + GetFullName(Pchar) + ". � �����, ��� ��� ������� ����� � ����, � ��� ������, ��� �� �� ��� �������.",
                                    "�, ������� " + GetFullName(Pchar) + ". ��� ������� ��� �� ���?");
				Link.l1 = "������������, " + GetFullName(NPChar) + ". � ���� � ���� ����������.";
			}
			Link.l1.go = "node_2";
		break;
		
		case "node_2":
			// ��������� ��������� 1
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.AskPortMan") && PChar.GenQuest.ChurchQuest_1.AskPortMan_InColony == NPChar.city)
			{
				dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
				if(!CheckAttribute(PChar, "GenQuest.ChurchQuest_1.CapFullInfo"))	// �������� ������ ����
				{
					if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NoMoneyToPortMan"))
					{
						dialog.text = "���, ��� ��� � ��������? �� �������� ��� ���� �� ������ ����?";
						if(sti(PChar.Money) >= 1000)
						{
							link.l1 = "��, ������"+ GetSexPhrase("","��") +". ��� ����� ������ ����. ������ ����������!";
							link.l1.go = "Church_GenQuest1_Node_FillFullInfo_3";
						}
						else
						{
							link.l1 = LinkRandPhrase("���, ��� �� ������"+ GetSexPhrase("","��") +"...", "��� ���...", "��� �� ������"+ GetSexPhrase("","��") +", �� ����� �������...");
							link.l1.go = "exit";
						}
					}
					else
					{
						link.l1 = "��������� �������� ��� ���� �������. � ��������"+ GetSexPhrase("��","���") +" �� ����� ������ ������, ��������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + ", ����� �� ��������� �����, � � ���� � ���� ������� ����. ������ ������� ��� ��������, �� �, � ���������, �� ����������"+ GetSexPhrase("","�") +", � ����� ����������� �� �����.";
						link.l1.go = "Church_GenQuest1_Node_FillFullInfo";
					}
				}
				else	// ������ ���� ��� ����
				{
					link.l1 = "�������� ��������� �����, ��� ����� ���������� � ����� '" + PChar.GenQuest.ChurchQuest_1.CapShipName + "', �������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + ".";
					if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NextColonyIsLast")) // �� �����, � ���� �������!		
						link.l1.go = "Church_GenQuest1_Node_CapOnThisColony_1";
					else // ���������� � ��������� �������
						link.l1.go = "Church_GenQuest1_Node_FillInfoOfCapColony_1";
				}				
				break;
			}		
//-------------------------------------------//Jason, �����---------------------------------------------------
				if (CheckAttribute(PChar, "questTemp.WPU.Fraht.TargetPortmanID") && CheckAttribute(PChar, "questTemp.WPU.Fraht.LevelUp") && pchar.questTemp.WPU.Fraht.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ����� ������� ���� ��� ����� �������.";
					Link.l1.go = "Fraht_completeLevelUp";
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Fraht.TargetPortmanID") && pchar.questTemp.WPU.Fraht != "lost" && pchar.questTemp.WPU.Fraht.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ����� ������� ���� ��� ����� �������.";
					Link.l1.go = "Fraht_complete";
					break;
				}
			
				if (CheckAttribute(PChar, "questTemp.WPU.Fraht.TargetPortmanID") && pchar.questTemp.WPU.Fraht == "lost" && pchar.questTemp.WPU.Fraht.Nation == npchar.nation)
				{
					if (pchar.questTemp.WPU.Fraht.TargetPortmanID == npchar.id)
					{
						dialog.text = "�, ��� �� ���-���� � �������. �����, �� �����, ��� �� ������� - �� ��� ������ ������� ������� �� ���������� ��� � ������. ��, ��� �������?";
						Link.l1 = "��� �������� �������������� ��������� ���� �������. �� � ���� ������������� �������� ������ �����. � ������ ��� ���� � ������� �� ���������� ���������.";
						Link.l1.go = "Fraht_complete_bad";
					}
					else
					{
						dialog.text = "�-�, � ����, ��� ��. �� ����������� ��������� ���� � ������ ���! ������, ����!";
						Link.l1 = "�-�-��!";
						Link.l1.go = "exit";
						LAi_group_Attack(NPChar, Pchar);
					}
				}
// <-- �����
//-------------------------------------------//Jason, �����---------------------------------------------------	
		
				if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.TargetPortmanID") && pchar.questTemp.WPU.Postcureer != "lost" && pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� �������� ����� ��� ����� �������.";
					Link.l1.go = "Postcureer_complete";
					break;
				}
			
				if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.TargetPortmanID") && pchar.questTemp.WPU.Postcureer == "lost" && pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
				{
					dialog.text = "��, �� ���-���� ���������... � ��, �����, ������, ��� ��� ��� ��� � �����... �� �� �����, � ���, ��� �� ��������� ������ ��������, � �� ���������.";
					Link.l1 = "��� �������� �������������� ��������� ����� �������. ��� ���, ��������.";
					Link.l1.go = "Postcureer_complete_bad";
					break;
				}
			
				if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.fail") && pchar.questTemp.WPU.Postcureer.StartCity == npchar.city)
				{
					dialog.text = "��� ���������? �� ��� ���� ���...";
					Link.l1 = "" + GetAddress_FormToNPC(NPChar) + ", �� ���� �����, ������������ �� ���������. ����� �� ������ �� ��������� ���������� �� ���� ������ ���� � ������... ��, � �����, ��� �������� � ���� �����.";
					Link.l1.go = "Postcureer_complete_fail";
					break;
				}
// <-- �����
//-------------------------------------------//Jason, ������---------------------------------------------------	
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_0") && pchar.questTemp.WPU.Escort.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "���� ������� ��������� ����� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen")+". � ������ ����������� ������� � ������ ������ � �����������, ������� � ��� �� �����. ��� ��� ������.";
					Link.l1.go = "Escort_LUGo_0";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUpGo_0") && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ���������� ����� � �������, ��� �� � ��������������.";
					Link.l1.go = "Escort_LUGo_complete";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1WM") && pchar.questTemp.WPU.Escort == "current" && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ��������� ����� � �������� ��� � ��� ����. �����, ��� ������� ��� ������� ��� �� ����.";
					Link.l1.go = "Escort_LU1WM_complete";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1VSP") && pchar.questTemp.WPU.Escort == "win" && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ��������� ����� � �������� ��� � ��� ����. �����, ��� ������� ��� ������� ��� �� ����.";
					Link.l1.go = "Escort_LU1VSP_complete";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1VSP") && pchar.questTemp.WPU.Escort == "sink" && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ��������� ����� � ������� ������� "+XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID)+". ��� ������� ��� �������� ��� � �������������� ������ �������. � ������ ��� ��� ��������� ������, �� ��� ������ ��������� ������: ��������� ������� �������� �������. � ������ ���� ��������� �� �� ����.";
					Link.l1.go = "Escort_LU1VSP_completeSink";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1S") && pchar.questTemp.WPU.Escort == "win" && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ����� ��������� ����� � ������� ������� "+XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID)+". ������, �� ���� �����, � ������ �������� ������� ��� ������� � ��������. ��� ��� � ������������ - ������� � ���� �� �������, � ������� � ����� ������ - ��������, �� ��� ������� � ���.";
					Link.l1.go = "Escort_LU1S_complete";
					break;
				}
				if(CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp_2") && pchar.questTemp.WPU.Escort == "win" && npchar.location == pchar.questTemp.WPU.Escort.StartCity +"_portoffice")
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� �������� ���� ���������. ��������� �������, ����������� �������� �������, ����������.";
					Link.l1.go = "Escort_LU2_complete";
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus") && pchar.questTemp.WPU.Escort.Bonus != "fail" && pchar.questTemp.WPU.Escort.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ������� ����� �������������. � �������� � ���� �������� ������� � ���� ����������.";
					Link.l1.go = "Escort_complete";
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus") && pchar.questTemp.WPU.Escort.Bonus == "fail" && pchar.questTemp.WPU.Escort.TargetPortmanID == npchar.id)
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ������� ����� �������������. � ������ ��� ��������� � ���� ��� �������� ����� � ����, ��, � ���������, ��� �������������� ������� ������� � ��� � ��������� ���������. ��� ����� ����. �� ���� � ��������.";
					Link.l1.go = "Escort_fail";
					break;
				}
				if (CheckAttribute(PChar, "questTemp.WPU.Escort.TargetPortmanID") && pchar.questTemp.WPU.Escort.TargetPortmanID == npchar.id && !CheckAttribute(PChar, "questTemp.WPU.Escort.LevelUp"))
				{
					dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
					Link.l1 = "� ������� ����� �������������. � �������� � ���� �������� ������� � ���� ����������.";
					Link.l1.go = "Escort_complete";
					break;
				}
				// <-- ������
  			  if (rand(3) <= 2)
			  {		
			    if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -20)
			    {
                dialog.text = "���-���. ������� ��, ���������, ���������� � �������. � �� ���� ������ ��������� �������. ������� � ������ ���  � ������������ � ������ ������. ������!!!";
                link.l1 = "�� ��... ������ �������!";
                link.l1.go = "exit"; // fight
                LAi_group_Attack(NPChar, Pchar);
                break;
                }
              }				
		
			dialog.text = "���������. � � ����� �������, " + GetFullName(PChar) + ".";
			Link.l2 = "����� ����� ��������� ������? ��� ��������?";
			Link.l2.go = "Work_check"; //������-�����-������
			Link.l14 = "�����, � ��� ���� ����, ��������� ��������� ������? ���� ���������� ���� ������.";
			Link.l14.go = "node_4"; //�� ����-������
			Link.l3 = "���� � �������� ���� �� ����� �������� �� �����?";
			Link.l3.go = "ShipStock_1";
			if (sti(NPChar.Portman) > 0)
			{
                Link.l4 = "� ���� ������� ���� ������� �������.";
    			Link.l4.go = "ShipStockReturn_1";
			}
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l5 = "� � ��� �� ���������� �����.";
				link.l5.go = "LoanForAll";//(���������� � ��������� ���������)	
			}
  			if (CheckAttribute(pchar, "GenQuest.Intelligence") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "") //����� ���� - �� ����� � ����� �������
			{
				link.l7 = RandPhraseSimple("� ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".", 
					GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + " ������� ���� � ���. � ����"+ GetSexPhrase("��","��") +" ���-��� �������...");
				link.l7.go = "IntelligenceForAll";
			}
			link.l6 = "���� ���������� ��������, ������� ���������� � ����� �������� ����������.";
			link.l6.go = "CapitainList";
			//���
			if (pchar.questTemp.Headhunter == "Houm" && npchar.nation == ENGLAND)
			{
			link.l12 = "�� ����������, �� �������������� �� � ��� ������� '������� ������' � ��������� ���������� ������?";
				link.l12.go = "Houm_portman_1";
			}
			
			link.l8 = "� �� ������� �������.";
			// Warship 26.07.09 ����� "��������� �����"
			if(CheckAttribute(NPChar, "Quest.BurntShip") && !CheckAttribute(NPChar, "Quest.BurntShip.LastQuestDate"))
			{
				if(CheckAttribute(NPChar, "Quest.BurntShip.TimeIsOver")) // ����������
				{
					link.l8.go = "BurntShip10";
				}
				else
				{
					if(CheckAttribute(NPChar, "Quest.BurntShip.TwoDaysWait"))
					{
						if(GetNpcQuestPastDayParam(NPChar, "Quest.BurntShip.TwoDaysWait") >= 2)
						{
							link.l8.go = "BurntShip17";
						}
						else
						{
							link.l8.go = "quests";
						}
					}
					else
					{
						link.l8.go = "BurntShip12";
					}
				}
			}
			else
			{
				link.l8.go = "quests";
			}
			if(CheckAttribute(pchar,"GenQuest.EncGirl"))
			{
				if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "portman_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
				{
					link.l9 = "������������, � ����"+ GetSexPhrase("��","��") +" �� ����������� ������ ����."; 
					link.l9.go = "EncGirl_4";
					pchar.quest.EncGirl_GetLoverFather.over = "yes";
				}	
				if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
				{
					if(pchar.GenQuest.EncGirl.Father == "portman_keeper" && npchar.city == pchar.GenQuest.EncGirl.city)
					{
						link.l9 = "� �� ������ ����� ������ ...";
						link.l9.go = "EncGirl_1";
					}
				}
			}
			if (CheckCharacterItem(pchar, "CaptainBook"))
			{
				if(pchar.questTemp.different == "free")
				{
					link.l10 = "� �� ����������� ���"+ GetSexPhrase("��","��") +" ��� ���� ����� ������� ����������.";
					link.l10.go = "ShipLetters_out1";				
				}
				else
				{
					if(pchar.questTemp.different.GiveShipLetters.city == npchar.city)
					{
						link.l10 = "� �� ����������� ���"+ GetSexPhrase("��","��") +" ��� ����, ��������� ���-�� ���������, ����� ������� ����������.";
						if(!CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakPortman"))
						{
							link.l10.go = "ShipLetters_Portman1_1";						
						}
						else
						{
							link.l10.go = "ShipLetters_Portman2";
						}
					}
				}		
			}												
			Link.l15 = "���������. �� ��������.";
			Link.l15.go = "exit";
		break;

		case "Church_GenQuest1_Node_FillFullInfo":
			dialog.text = "���� �������� ����� ���������. �� ������ ���������� � ������ ��������� ������ ���������, � �������� ��� ��������� ���������� � �������� ����� ������ �����.";
			link.l1 = "� ���������, �� �� ��� ������. ������ � ����� ����� ��� ���� ������ �������� �����... �� ����������� ����������.";
			link.l1.go = "Church_GenQuest1_Node_FillFullInfo_2";
		break;
			
		case "Church_GenQuest1_Node_FillFullInfo_2":
			dialog.text = "���. ��� ��� �������. ��� ����� ������� ������ � ������� �������, ��� ��������� �������. � � ���� ���, ��� ��������, ����� - ������...";
			if(sti(pchar.money) >= 1000)
			{
				link.l1 = "� ��� ��������� �������, �-� " + GetFullName(NPChar) + ", � �����"+ GetSexPhrase("","�") +" �������� ������� ���� �����... � �������, ������, 1000 ����.";
				link.l1.go = "Church_GenQuest1_Node_FillFullInfo_3";
			}
			else
			{
				DeleteAttribute(pchar, "GenQuest.ChurchQuest_1.CurPortManColony"); // ����� ����� ��������.
				link.l1 = "�-��... � �����-�� � ���� � ����... ������� �����...";
				link.l1.go = "exit";
			}
		break;
			
		case "Church_GenQuest1_Node_FillFullInfo_3":
			sColony = GetColonyExpect2Colonies(NPChar.city, PChar.GenQuest.ChurchQuest_1.QuestTown);
			PChar.GenQuest.ChurchQuest_1.CapGoToColony = sColony;
			if(CheckAttribute(pchar, "GenQuest.ChurchQuest_1.NoMoneyToPortMan"))
			{
				dialog.text = "�������! ������ ���������, ��� ��� � ���... ������... ���... ���, ����������. � ������� ������� �������� ��������������, � �����, ���������� ������ '" + PChar.GenQuest.ChurchQuest_1.CapShipName + "' ��� ����������� �������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + " ����������� ������� � ������� " + XI_ConvertString("Colony" + sColony + "Gen") + ".";
				DeleteAttribute(pchar, "GenQuest.ChurchQuest_1.NoMoneyToPortMan");
			}
			else
				dialog.text = "�-�-�!... �� ����, ��, �� ������� �� �����������, ��� ��� � �����, ����� ������� �������. ������... ���... ���, ����������. � ������� ������� �������� ��������������. �����, ���������� ������ '" + PChar.GenQuest.ChurchQuest_1.CapShipName + "' ��� ����������� �������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + " ������ ������� � ������� " + XI_ConvertString("Colony" + sColony + "Gen") + ".";			
				link.l1 = "��������� ���, ������, �� ������� ��� ������������� ������� ������.";
				link.l1.go = "Church_GenQuest1_Node_FillFullInfo_4";
				AddMoneyToCharacter(pchar, -1000);
		break;
			
		case "Church_GenQuest1_Node_FillFullInfo_4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "4");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","��"));
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.CapGoToColony + "Gen"));
			AddQuestUserData(sQuestTitle, "sShipName", PChar.GenQuest.ChurchQuest_1.CapShipName);	
			PChar.GenQuest.ChurchQuest_1.AskPortMan_InColony = PChar.GenQuest.ChurchQuest_1.CapGoToColony;
			PChar.GenQuest.ChurchQuest_1.CapFullInfo = true;
		break;
			
		case "Church_GenQuest1_Node_FillInfoOfCapColony_1":
			dialog.text = "��� ������ �� ������ ������?";
			link.l1 = "�������, �� �������� �� ����� ����� �������� � ��� ����?";
			link.l1.go = "Church_GenQuest1_Node_FillInfoOfCapColony_2";
		break;
						
		case "Church_GenQuest1_Node_FillInfoOfCapColony_2":
			PChar.GenQuest.ChurchQuest_1.CapGoToColony = GetColonyExpect2Colonies(NPChar.city, PChar.GenQuest.ChurchQuest_1.QuestTown);
			dialog.text = "��... ��������� ������, � ����� ����� �� ��� ������������?";
			link.l1 = "� ���� � ���� ����. ���� �� �� ��� � ����� ����� ��� �� ��...";
			link.l1.go = "Church_GenQuest1_Node_FillInfoOfCapColony_3";
		break;
			
		case "Church_GenQuest1_Node_FillInfoOfCapColony_3":
			dialog.text = "�� ���. �� - ����� ������ ��������� - �� ����� ��� ������� �����, ������� ���������� ������� ���, �������, �� ������ �������� � ���������� � " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.CapGoToColony + "Acc") + ". � ���, ����������, �������� ���� ������, ���� ��������� ����� � ��� ����.";
			link.l1 = "� ����� ������ ��������� ��� �����, � ��������� �� ������.";
			link.l1.go = "Church_GenQuest1_Node_FillInfoOfCapColony_4";
		break;
			
		case "Church_GenQuest1_Node_FillInfoOfCapColony_4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "5");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.CapGoToColony + "Dat"));
			AddQuestUserData(sQuestTitle, "sName", PChar.GenQuest.ChurchQuest_1.CapFullName);
			PChar.GenQuest.ChurchQuest_1.AskPortMan_InColony = PChar.GenQuest.ChurchQuest_1.CapGoToColony; // ���������� �������� � �������, ���� ���������� ���.
			if(rand(2) == 1) 
			{
				Log_TestInfo("��������� ������� - ���������");
				PChar.GenQuest.ChurchQuest_1.NextColonyIsLast = true; // ���� - ��������� ������� ����� ���������
			}
		break;
			
		case "Church_GenQuest1_Node_CapOnThisColony_1":
			dialog.text = "��� ������ ��� ����������, �����"+ GetSexPhrase("���","��") +" " + GetFullName(PChar) + "?";
			link.l1 = "�������, �� ������� �� � ��� ���� ���� �������?";
			link.l1.go = "Church_GenQuest1_Node_CapOnThisColony_2";
		break;
			
		case "Church_GenQuest1_Node_CapOnThisColony_2":
			dialog.text = "��, �������... ��� �����, ��� � � ����������� ������, ����� �� ������� ��� ���������������� ����.";
			link.l1 = "�� ����, ��� ����� �� ��� ��������� �����?";
			link.l1.go = "Church_GenQuest1_Node_CapOnThisColony_3";
		break;
			
		case "Church_GenQuest1_Node_CapOnThisColony_3":
			dialog.text = "��, ��������"+ GetSexPhrase("�� ��������","�� �������") +". ���� ����, �� ���������� �������� �� ����� ���������� ������, ������� � ��� ��������� ������������� �������. ����� ������ ��� ����� �� ������ ����, ��� �������� ����������� ������, � ��� ���������� ������� ����� ������������� � ������ ���������, � ����������� ��� ������ �������� ����� ��� �������� �������. �� ��� ������ ���������� � ��������� ������� ������� ��� �� ����... �� ���� ����, �� ���� ���� � ������������ �������!";
			link.l1 = "�����������, �������� " + NPChar.Name + ", � ��������� � ���, ��� ����-�� ������ ������� �������, ��� ���. �� ��� ������ ����� ��� ���������, � ��� ������ ��������� ����������� � ���� ���������... ��������� �����������.";
			link.l1.go = "Church_GenQuest1_Node_CapOnThisColony_4";
		break;
			
		case "Church_GenQuest1_Node_CapOnThisColony_4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "6");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown));
//			PChar.GenQuest.ChurchQuest_1.NeedToDialogWithSailors = true; // ���������� �������
			PChar.GenQuest.ChurchQuest_1.NeedToDialogWithCap = true; // ������� � ���������
//			SetFunctionLocationCondition("Church_GenQuest1_ChangeCapitanLocation", "Deck_Near_Ship", true);
			PChar.GenQuest.ChurchQuest_1.CurPortManColony = NPChar.city;
			Group_SetAddress("ChurchGenQuest1_CapGroup", colonies[FindColony(NPChar.City)].Island, "IslandShips1", "Ship_1"); // ������ ���� � ����� �������
			Characters[GetCharacterIndex("ChurchGenQuest1_Cap")].Nation = sti(NPChar.Nation); // ������ �����, ���� ������ �� ����
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.AskPortMan"); // ������ �� ����������
//			if(rand(1) == 0) PChar.GenQuest.ChurchQuest_1.CapWaitOnTavern = true;
			sld = CharacterFromID("ChurchGenQuest1_Cap");
			sld.DeckDialogNode = "ChurchGenQuest_1_DeckDialog_1";
		break;
						
		case "ShipLetters_out1":
			dialog.text = "�����-�� ���������! ��, � ���� ���������� ���� �������� �������� ����������������. �� ������ �����, ��� ����� ����� ��������� �� ��� � �������� ������. ��������� �����, �������!";
			link.l1 = "���������!";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "CaptainBook"); 			
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "10");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
				
		case "ShipLetters_Portman1_1":
			pchar.questTemp.different.GiveShipLetters.speakPortman = true;
			s1 = "�����-�� ���������! ��, � ���� ���������� �������� � ��� �����, � ��� ��������. ";
			s1 = s1 + "���� ��������������, �������, ������ ��� �����! ����������, ���� ����� ������ ���� �������������. ";
			dialog.text = s1 + "������, " + sti(pchar.questTemp.different.GiveShipLetters.price1) + " ���� �� ������� ��������� �������?";
			link.l1 = "���������� ���!";
			link.l1.go = "exit";
			link.l2 = "��� ��, ������ �������� �����, �� � ������ �� ������. ��, � �������� ���� �����������, "  + npchar.name +" .";
			link.l2.go = "ShipLetters_Portman1_2";
		break;
		
		case "ShipLetters_Portman1_2" :
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price1)); 			
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "5");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
		
		case "ShipLetters_Portman2":
			dialog.text = "�� �������� ������� ��� �����������?";
			link.l1 = "����������, ���!";
			link.l1.go = "exit";
			link.l2 = "�������. ���� ������"+ GetSexPhrase("","�") +", ��� ��� ������ ����� ������.";
			link.l2.go = "ShipLetters_Portman2_1";
		break;
		
		case "ShipLetters_Portman2_1":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price1)); 			
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "6");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 		
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
			dialog.text = "�� ��� �� ���������?.. � ��� ���� ���� ����? ����? ���, ����� ����� - ��������, ����� � ���������...\n��... � ������ �������������� ����, ��� � ����� - �������, ����������.";
			link.l1 = "�������. � ������� � ��������. ���-�� ��� ������������, ��� ��� �� ���� �� �����������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("EncGirl_ToLoverParentsExit");
		break;
		
		case "EncGirl_4":
			if(sti(pchar.GenQuest.EncGirl.LoverFatherAngry) == 0)
			{
				dialog.text = "�, ��� �� � ���� �"+ GetSexPhrase("�� �������, ������� �����","� �������, ������� ��������") +" ����� �������� ���� � ������� ��������?";
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
			dialog.text = "����� ����� �������?! � ����� �������� �� ��������? ��������, ����� �������, � ���� ��... �������! ������ ��� ������ ���� ������� � ����� ����� ��������, �� � ������ �����������. �������� �� ������������� ������ ������� � ����� ���������� ����� �������. �� ����� ��� ������� �������������. ��������.";
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
		
		case "node_4":
			//--> �������� ����������� ���������� �����. 
			if (npchar.quest == "PortmansJornal") //���� ����� �� ������� ������
			{
				dialog.text = "�� ������ ���� ����� �������� �� ����� " + npchar.quest.PortmansJornal.capName + " � ������� ��� ������� ������. �� ������� ���?";
				link.l1 = "���, �� ���������� ����...";
				link.l1.go = "PortmanQuest_NF";
				break;
			}
			if (npchar.quest == "PortmansSeekShip" || npchar.quest == "SeekShip_sink") //���� ����� �� ������ ����������� �������
			{
				dialog.text = "�� ����������� ��������� ���������� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.PortmansSeekShip.shipTapeName)) + " '" + npchar.quest.PortmansSeekShip.shipName + "'. ���� �� �� ��������� ��� �������, �� � ����� ������ ���������� �� ����� ���� � ����.";
				link.l1 = "� �������� ������, �����.";
				link.l1.go = "exit";
				link.l2 = "���� ���������� �� ���������� ������ ���������.";
				link.l2.go = "SeekShip_break";
				break;
			}
			if (npchar.quest == "SeekShip_success") //���������� ������� ���� �� �������
			{
				dialog.text = "�� ������� ��� ��������� ���������� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.PortmansSeekShip.shipTapeName)) + " '" + npchar.quest.PortmansSeekShip.shipName + "'. �� ������� ���?";
				bool bOk = false;
				for (i=0; i<=COMPANION_MAX; i++)
				{
					cn = GetCompanionIndex(pchar, i);
					if(cn != -1)
					{
						sld = &characters[cn];
						if (sld.ship.name == npchar.quest.PortmansSeekShip.shipName && 
							RealShips[sti(sld.ship.type)].BaseName == npchar.quest.PortmansSeekShip.shipTapeName &&
							RealShips[sti(sld.Ship.Type)].basetype == npchar.quest.PortmansSeekShip.shipTape)
						{
							if (i == 0)
							{	//���� ������ ������� - � ��
								sld.Ship.Type = GenerateShip(SHIP_TARTANE, true);
								SetBaseShipData(sld);
								SetCrewQuantityFull(sld);
							}
							else
							{
								RemoveCharacterCompanion(pchar, sld);
								AddPassenger(pchar, sld, false);
							}
							bOk = true;
						}
					}
				}				
				if (bOk)
				{
					link.l1 = "��, � ���"+ GetSexPhrase("��","��") +" ���, ����� � ����� �� �����. ������ ��������.";
					link.l1.go = "SeekShip_good";
				}
				else
				{
					link.l1 = "� �������� ������, �����.";
					link.l1.go = "exit";
				}
				link.l2 = "���� ���������� �� ���������� ������ ���������.";
				link.l2.go = "SeekShip_break";
				break;
			}
			//<-- �������� ����������� ���������� �����. 

			//--> ���� ����������� ���������� �����. 
			if (rand(2) < 2 && pchar.questTemp.different == "free" && GetNpcQuestPastDayWOInit(npchar, "quest.meeting") > 7)
			{
				dialog.text = LinkRandPhrase("��, ���� ������! � ���� ���� ��� ��� ������!", 
					"��! �� ��� ������ �������! � ���� ���� ���� ��������, ��������� ����������.", 
					"��� ��! �������, � ���� ���� ������! ��������, ������ ��, ������ ��������...");
				link.l1 = "��������� ���� ����, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "PortmanQuest";
				SaveCurrentNpcQuestDateParam(npchar, "quest.meeting");
				break;
			}
			
			// Warship 25.07.09 ����� "��������� �����"
			if(dRand(4) == 2 && !CheckAttribute(NPChar, "Quest.BurntShip"))
			{
				dialog.text = "����! ������� " + GetFullName(PChar) + ", �� ��� ������ �������! ������������ ����� ���������, ����� ���������... � ��� �� ����� ������� �����, ����������� �� ��������� ��������� ����������! �� ���������� �������� ������� �������... �� ����� ����������...\n" +
					"�������, �� ��� �� ��� ����� ���������-��? ���� ������� ��� ����� � �������...";
				link.l1 = "��, ��� �������� - ����� �������. � ��������� �������� �� ���? ��� �� ��� �� ������������, � ����� ��������? � ������ ���� �� ������� �������, ��...";
				link.l1.go = "BurntShip4";
				link.l2 = "� ������ ��������� ��� �� ������� �� ����� �����, � �� �� ���. �� ���� ������� ��� ���� ������ �����������, ���� ����� ��������. � �� �������������"+ GetSexPhrase("","����") +", ��� ��� ��������, �� �� ������...";
				link.l2.go = "BurntShip2";
				break;
			}
			//<-- ���� ����������� ���������� �����.

			dialog.text = "���������� ������ �� ������������ ������ - � ���� ������ ���� ������. �����, � ������� ����� ���� ���������������� �����, �� � ������� ������ �������� ���������.";
			Link.l1 = "��� ���� ������.";
			Link.l1.go = "node_2";
			Link.l2 = "���������. �� ��������.";
			Link.l2.go = "exit";
		break;

///Jason-----------------------����� ���������� �������������� ���� ��� ��������----------------------------
		int iTime, idaysQty, iGoods, iGoodsQty, amount;
		case "Work_check"://����-�������� - ����� �������� ��������������� �� � ����� �������
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
			{
				if (!CheckAttribute(npchar, "work_date") || GetNpcQuestPastDayParam(npchar, "work_date") >= 2)//�������� �������
				{
					if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)//�������� ��������������� ���������
					{
						dialog.text = RandPhraseSimple("����� ��� ������ ��� ���, ��� ����� ��� ������ " + NationNameGenitive(sti(pchar.nation)) + "! �������� ��� ������� ����������!", "� �� ������� ������������ � " + NationNameAblative(sti(pchar.nation)) + ". ��� ������!");
						link.l1 = RandPhraseSimple("��, ���� �����...", "��, ��� ������...");
						link.l1.go = "exit";
						break;
					}
					if (makeint(PChar.reputation.nobility) < 41) // �������� ��������� ��
					{
						dialog.text = "���� ��������� �� ������� ��� �������. � �� ������� � ���� ������������. ����� �������.";
						link.l1 = "����-�?! �� ���� �� ����.";
						link.l1.go = "exit";
						break;
					}
					if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < 5)//��� ������ ���������� �� ����
					{
						dialog.text = "�� ���� ��� �������, �������, ��... � ��������, ��� �� �� ������� ��������� ��� ��������� - � ��� ������� ���� �����. � �� ���� ��������� � ���� ��������.";
						link.l1 = "�������. ��� �������.";
						link.l1.go = "exit";
						break;
					}
					dialog.Text = "��... ��, ��� ������ ������ ���� ������ ��� ����������.";
					link.l1 = "� �� ����� ���������� ��� ������������ ��� ����� ��� ��������� ������.";
					Link.l1.go = "Fraht_begin";
					link.l2 = "��, ����� �� ���-������ ���� ����������?";
					Link.l2.go = "Check_other";
				}
				else
				{
					dialog.Text = "������� ��� ������ ���. ������� � ������ ����.";
					link.l1 = "������.";
					Link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� ����� - ��������� ���-������ ��������� ��� ���.";
				link.l1 = "������, � ��� � ������.";
				link.l1.go = "exit";
			}
		break;
	
		case "Check_other"://����� ����� �������� ��������, �������� � �����
		if(15-stf(RealShips[sti(Pchar.Ship.Type)].SpeedRate) <= 0 && drand(5) > 1) //���� ������� �������
			{
			if (pchar.questTemp.WPU.Postcureer == "begin" || pchar.questTemp.WPU.Postcureer == "late" || pchar.questTemp.WPU.Postcureer == "lost" || pchar.questTemp.WPU.Postcureer == "fail" || CheckAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp"))//���� ������
				{
				dialog.text = "� ���������, ������ ������ ��� ���������� ������� �� ����. ������� ����� ���� ����.";
				link.l1 = "������, � ��� � ������.";
				link.l1.go = "exit";
				SaveCurrentNpcQuestDateParam(npchar, "work_date");
			}
			else //���� �� ������
			{
				if (sti(pchar.questTemp.WPU.Postcureer.count) > 3 && drand(1) == 1)//���� 2 �������
					{
						dialog.text = "���-���... �� ��� ������������ � ������� ��������� ������ ��������� �������, ��� ��� ��������. �������, �������, ������� � ��������, ����� ������ ��� �� �����.";
						link.l1 = "������ ��� �����������, " + GetAddress_FormToNPC(NPChar) + ".";
						link.l1.go = "Postcureer_LevelUp";
					}
				else //������ �������
					{
						dialog.text = "� ����, � ��� ������� �������. ���� ���������� ������ � �������� ��������� ������� - ��������� ��������������� � ������� ������.";
						link.l1 = "��� ���������. �������, � ��������. ���� ����� �����������?";
						link.l1.go = "Postcureer";
						link.l2 = "�������, �� ����� ������� ��� �� �� ����.";
						link.l2.go = "exit";
					SaveCurrentNpcQuestDateParam(npchar, "work_date");
				}
			}
		break;
		}
		if (GetCompanionQuantity(pchar) < 6 && sti(RealShips[sti(pchar.Ship.Type)].BaseType) >= SHIP_BRIG && sti(RealShips[sti(pchar.Ship.Type)].BaseType) != SHIP_GALEON_L && sti(RealShips[sti(pchar.Ship.Type)].BaseType) != SHIP_PINNACE && drand(5) > 1)//���� ������� �������
		{
			if (pchar.questTemp.WPU.Escort == "begin" || pchar.questTemp.WPU.Escort == "late" || pchar.questTemp.WPU.Escort == "win" || CheckAttribute(pchar, "questTemp.WPU.Escort.LevelUp"))//���� ������
			{
				dialog.text = "� ���������, ������ ������ ��� ���������� ������� �� ����. ������� ����� ���� ����.";
				link.l1 = "������, � ��� � ������.";
				link.l1.go = "exit";
				SaveCurrentNpcQuestDateParam(npchar, "work_date");
			}
			else //���� �� ������
			{
				if (sti(pchar.questTemp.WPU.Escort.count) > 3 && drand(1) == 1)//2 �������
					{
						dialog.text = "�� ��� ������������ � ������� ��������� ������ �� ������������� �������� �����. � ���� ���� �������, ������� � ����� �� �������� ������ ���.";
						link.l1 = "������ ��� �����������.";
						link.l1.go = "Escort_LevelUp";
				}
				else //1 �������
				{
					if (sti(RealShips[sti(pchar.Ship.Type)].BaseType) == SHIP_HEAVYGALEON && 2500 - makeint(GetCharacterFreeSpace(pchar, GOOD_RUM)) < 0 && !CheckAttribute(pchar, "questTemp.WPU.Fraht.TargetPortmanID"))
					{//���� �� ��
						dialog.text = "� ���� ���� ������, ��� ��� ��� ���. � ����� ����� ����� �� ����� ��� �������� �����. ��� ����� ������ ���� ��� ����������� � ����, �� ������� ������������� �� ��� ��� ����� � ����� � ��������� ��� �� �����\n��� ������� �������� �������� ��� ������� ���� �����, ��� ��� ��� ���������� ���������� ��� �������������� ������ ����� � ����� �����. ������, ����������, ����� ������� - �� ����� � �� �������������.";
						link.l1 = "���������� �����������. ������!";
						link.l1.go = "escort_bonus";
					link.l2 = "�������, �� ����� ������� ��� �� �� ����.";
					link.l2.go = "exit";
					}
					else
					{//������ ������
						dialog.text = "� ���� ���� ������, ��� ��� ��� ���. � ����� ����� ����� �� ����� ��� �������� ����� - ��� ��������� � ������� ���������. � ��������� ��� ����������� �� ������. ����������?";
						link.l1 = "���������� �����������. ������!";
						link.l1.go = "escort";
					link.l2 = "�������, �� ����� ������� ��� �� �� ����.";
					link.l2.go = "exit";
					SaveCurrentNpcQuestDateParam(npchar, "work_date");
				}
				}
			}
		break;
		}
		//������ �� �������
		dialog.text = "� ���������, ������ ������ ��� ���������� ������� �� ����. ������� ����� ���� ����.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
		break;

///--> ------����� �� ��������� ������� ������ ����������, ������ � ���� ����� �� ������������� ������---------

		case "Fraht_begin":
			if (drand(4) < 4)
			{
				if (pchar.questTemp.WPU.Fraht == "begin" || pchar.questTemp.WPU.Fraht == "late" || pchar.questTemp.WPU.Fraht == "lost" || CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus"))//�������� �� ���������
				{
					dialog.Text = "�� ��� ��������, ��� ���� ����� ��� ������������. � �� ���� ���� ��� ����� �������. ���������� ������ �������������.";
					link.l1 = "��, �������, �� �����.";
					Link.l1.go = "exit";
					break;
				}
				if (1500 - makeint(GetCharacterFreeSpace(pchar, GOOD_RUM)) > 0)//���� ����� - �� ����
				{
					dialog.text = "� ��� ������� ���� ����� � ������. ��� ������ ��� ����� ����� ������������� �������, ��� ���. ���������� � ������� - ������� ����� ��������� �������� ��������� ��� ��������� ��������� ������ ������.";
					link.l1 = "�������. ��� �������.";
					link.l1.go = "exit";
					break;
				}
				if (pchar.questTemp.WPU.Fraht.count > 3 && rand(1) == 0)
				{
					dialog.text = "������ ������ ����������� ���. �� �� ��� ������������ � ������� ��������� ������� �� ��������� ������. � ���� ���� ������������ ������, ������� � �� ����� �������� ������ ���.";
					link.l1 = "������ ��� �����������. ��� �� ������?";
					link.l1.go = "Fraht_LevelUp";
					break;
				}
				dialog.Text = "�� ��� ��, ���� ���������� ��������� ��������� ������.";
				link.l1 = "������� ���������.";
				Link.l1.go = "Fraht_choise";
			}
			else
			{
				dialog.Text = "������� ��� ������ �� ������� ���. ������� � ������ ����.";
				link.l1 = "������.";
				Link.l1.go = "exit";
			}
		break;
	
		int iFrahtGoods1, iFrahtGoods2, iFrahtGoods3, iFrahtGoods;
		int iFrahtGoodsQty1, iFrahtGoodsQty2, iFrahtGoodsQty3;
		case "Fraht_choise":
			//�������� ������
			pchar.questTemp.WPU.Fraht.City1 = findCurrentCity1(npchar);
			pchar.questTemp.WPU.Fraht.City2 = findCurrentCity2(npchar);
			pchar.questTemp.WPU.Fraht.City3 = findCurrentCity3(npchar);
			//�������� ������
			iFrahtGoods1 = drand(GOOD_PAPRIKA);
			iFrahtGoods2 = drand(GOOD_PAPRIKA-3);
			iFrahtGoods3 = drand(GOOD_PAPRIKA-7);
			pchar.questTemp.WPU.Fraht.Goods1 = iFrahtGoods1;
			pchar.questTemp.WPU.Fraht.Goods2 = iFrahtGoods2;
			pchar.questTemp.WPU.Fraht.Goods3 = iFrahtGoods3;
			//��������� ����������
			iFrahtGoodsQty1 = makeint(GetCharacterFreeSpace(pchar, iFrahtGoods1))/(1+frand(0.5));
			iFrahtGoodsQty2 = makeint(GetCharacterFreeSpace(pchar, iFrahtGoods2))/(1+frand(0.5));
			iFrahtGoodsQty3 = makeint(GetCharacterFreeSpace(pchar, iFrahtGoods3))/(1+frand(0.5));
			if (sti(iFrahtGoodsQty1) > 10000) iFrahtGoodsQty1 = 10000 + rand(500);
			if (sti(iFrahtGoodsQty2) > 10000) iFrahtGoodsQty2 = 10000 + rand(500);
			if (sti(iFrahtGoodsQty3) > 10000) iFrahtGoodsQty3 = 10000 + rand(500);
			pchar.questTemp.WPU.Fraht.GoodsQty1 = iFrahtGoodsQty1;
			pchar.questTemp.WPU.Fraht.GoodsQty2 = iFrahtGoodsQty2;
			pchar.questTemp.WPU.Fraht.GoodsQty3 = iFrahtGoodsQty3;
			pchar.questTemp.WPU.Fraht.StartCity = npchar.city;//����� ������������
			pchar.questTemp.WPU.Fraht.Chance = rand(4);//����-�����
			//��������� ����� � ������ �������
			int daysQty1 = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Fraht.StartCity), GetArealByCityName(pchar.questTemp.WPU.Fraht.City1));
			int daysQty2 = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Fraht.StartCity), GetArealByCityName(pchar.questTemp.WPU.Fraht.City2));
			int daysQty3 = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Fraht.StartCity), GetArealByCityName(pchar.questTemp.WPU.Fraht.City3));
			pchar.questTemp.WPU.Fraht.DaysQty1 = makeint(sti(daysQty1)*(frand(1.3)+0.7));
			pchar.questTemp.WPU.Fraht.DaysQty2 = makeint(sti(daysQty2)*(frand(1.3)+0.7));
			pchar.questTemp.WPU.Fraht.DaysQty3 = makeint(sti(daysQty3)*(frand(1.3)+0.7));
			//��������� ���� ������ �� ������ �����, ��������� � ������
			pchar.questTemp.WPU.Fraht.Money1 = (makeint((sti(iFrahtGoodsQty1) * sti(Goods[iFrahtGoods1].Weight) / sti(Goods[iFrahtGoods1].Units))))*(sti(daysQty1)*2)*sti(daysQty1)/sti(pchar.questTemp.WPU.Fraht.DaysQty1);
			pchar.questTemp.WPU.Fraht.Money2 = (makeint((sti(iFrahtGoodsQty2) * sti(Goods[iFrahtGoods2].Weight) / sti(Goods[iFrahtGoods2].Units))))*(sti(daysQty2)*2)*sti(daysQty2)/sti(pchar.questTemp.WPU.Fraht.DaysQty2);
			pchar.questTemp.WPU.Fraht.Money3 = (makeint((sti(iFrahtGoodsQty3) * sti(Goods[iFrahtGoods3].Weight) / sti(Goods[iFrahtGoods3].Units))))*(sti(daysQty3)*2)*sti(daysQty3)/sti(pchar.questTemp.WPU.Fraht.DaysQty3);
			if (drand(5) < 4)//��� ��������
			{
				dialog.text = "���� ��������� �������:\n" +
					"���� " + GetGoodsNameAlt(iFrahtGoods1)+ " � ���������� " + FindRussianQtyString(iFrahtGoodsQty1) + " � ����� " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City1) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Fraht.DaysQty1) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money1)) + "\n���� " + GetGoodsNameAlt(iFrahtGoods2)+ " � ���������� " + FindRussianQtyString(iFrahtGoodsQty2) + " � ����� " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City2) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Fraht.DaysQty2) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money2)) + "\n���� " + GetGoodsNameAlt(iFrahtGoods3)+ " � ���������� " + FindRussianQtyString(iFrahtGoodsQty3) + " � ����� " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City3) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Fraht.DaysQty3) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money3)) + "\n��� ���������?";
				Link.l1 = "� ������� ������ ������� - ����� �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City1) + " � ������ " + GetGoodsNameAlt(iFrahtGoods1)+ ".";
				Link.l1.go = "Fraht_Choise_1";
				Link.l2 = "� ������� ������ ������� - ����� �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City2) + " � ������ " + GetGoodsNameAlt(iFrahtGoods2)+ ".";
				Link.l2.go = "Fraht_Choise_2";
				Link.l3 = "� ������� ������ ������� - ����� �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City3) + " � ������ " + GetGoodsNameAlt(iFrahtGoods3)+ ".";
				Link.l3.go = "Fraht_Choise_3";
			}
			else //��� ��������
			{
				dialog.text = "���� ��������� �������:\n" +
					"���� " + GetGoodsNameAlt(iFrahtGoods1)+ " � ���������� " + FindRussianQtyString(iFrahtGoodsQty1) + " � ����� " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City1) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Fraht.DaysQty1) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money1)) + "\n���� " + GetGoodsNameAlt(iFrahtGoods2)+ " � ���������� " + FindRussianQtyString(iFrahtGoodsQty2) + " � ����� " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City2) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Fraht.DaysQty2) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money2)) + "\n��� ���������?";
				Link.l1 = "� ������� ������ ������� - ����� �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City1) + " � ������ " + GetGoodsNameAlt(iFrahtGoods1)+ ".";
				Link.l1.go = "Fraht_Choise_1";
				Link.l2 = "� ������� ������ ������� - ����� �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Fraht.City2) + " � ������ " + GetGoodsNameAlt(iFrahtGoods2)+ ".";
				Link.l2.go = "Fraht_Choise_2";
			}
			Link.l4 = "� ���������, ��� ������ �� ��������.";
			Link.l4.go = "exit";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
		break;
	
		case "Fraht_Choise_1":
			dialog.text = "�� ��� ��, ������������. ������ ������� ���������. �������� ����� ��� ��������.";
			link.l1 = "��� ����� ������� � ������ ����!";
			link.l1.go = "Fraht_Forcemajor";
			AddCharacterGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods1), sti(pchar.questTemp.WPU.Fraht.GoodsQty1));
			iFrahtGoods1 = pchar.questTemp.WPU.Fraht.Goods1;
			ReOpenQuestHeader("Fraht");
			AddQuestRecord("Fraht", "1");
			AddQuestUserData("Fraht", "sGoods", GetGoodsNameAlt(iFrahtGoods1));
			AddQuestUserData("Fraht", "sGoodQty", FindRussianQtyString(sti(pchar.questTemp.WPU.Fraht.GoodsQty1)));
			AddQuestUserData("Fraht", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Fraht.DaysQty1)));
			AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money1)));
			AddQuestUserData("Fraht", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.StartCity+"Gen"));
			AddQuestUserData("Fraht", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.City1+"Gen"));
			SetFunctionTimerCondition("FrahtTime_Over", 0, 0, sti(pchar.questTemp.WPU.Fraht.DaysQty1), false);
			pchar.questTemp.WPU.Fraht.TargetPortmanID = pchar.questTemp.WPU.Fraht.City1+"_portman";
			pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iFrahtGoods1].Cost);//���� ������� ������
			pchar.questTemp.WPU.Fraht.GoodsAverigeCost = sti(Goods[iFrahtGoods1].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty1);//������� ��������� ������
			pchar.questTemp.WPU.Fraht.Goods = sti(pchar.questTemp.WPU.Fraht.Goods1);
			pchar.questTemp.WPU.Fraht.GoodsQty = sti(pchar.questTemp.WPU.Fraht.GoodsQty1);
			pchar.questTemp.WPU.Fraht.Money = sti(pchar.questTemp.WPU.Fraht.Money1);
		break;
	
		case "Fraht_Choise_2":
			dialog.text = "�� ��� ��, ������������. ������ ������� ���������. �������� ����� ��� ��������.";
			link.l1 = "��� ����� ������� � ������ ����!";
			link.l1.go = "Fraht_Forcemajor";
			AddCharacterGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods2), sti(pchar.questTemp.WPU.Fraht.GoodsQty2));
			iFrahtGoods2 = pchar.questTemp.WPU.Fraht.Goods2;
			ReOpenQuestHeader("Fraht");
			AddQuestRecord("Fraht", "1");
			AddQuestUserData("Fraht", "sGoods", GetGoodsNameAlt(iFrahtGoods2));
			AddQuestUserData("Fraht", "sGoodQty", FindRussianQtyString(sti(pchar.questTemp.WPU.Fraht.GoodsQty2)));
			AddQuestUserData("Fraht", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Fraht.DaysQty2)));
			AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money2)));
			AddQuestUserData("Fraht", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.StartCity+"Gen"));
			AddQuestUserData("Fraht", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.City2+"Gen"));
			SetFunctionTimerCondition("FrahtTime_Over", 0, 0, sti(pchar.questTemp.WPU.Fraht.DaysQty2), false);
			pchar.questTemp.WPU.Fraht.TargetPortmanID = pchar.questTemp.WPU.Fraht.City2+"_portman";
			pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iFrahtGoods2].Cost);//���� ������� ������
			pchar.questTemp.WPU.Fraht.GoodsAverigeCost = sti(Goods[iFrahtGoods2].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty2);//������� ��������� ������
			pchar.questTemp.WPU.Fraht.Goods = sti(pchar.questTemp.WPU.Fraht.Goods2);
			pchar.questTemp.WPU.Fraht.GoodsQty = sti(pchar.questTemp.WPU.Fraht.GoodsQty2);
			pchar.questTemp.WPU.Fraht.Money = sti(pchar.questTemp.WPU.Fraht.Money2);
		break;
	
		case "Fraht_Choise_3":
			dialog.text = "�� ��� ��, ������������. ������ ������� ���������. �������� ����� ��� ��������.";
			link.l1 = "��� ����� ������� � ������ ����!";
			link.l1.go = "Fraht_Forcemajor";
			AddCharacterGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods3), sti(pchar.questTemp.WPU.Fraht.GoodsQty3));
			iFrahtGoods3 = pchar.questTemp.WPU.Fraht.Goods3;
			ReOpenQuestHeader("Fraht");
			AddQuestRecord("Fraht", "1");
			AddQuestUserData("Fraht", "sGoods", GetGoodsNameAlt(iFrahtGoods3));
			AddQuestUserData("Fraht", "sGoodQty", FindRussianQtyString(sti(pchar.questTemp.WPU.Fraht.GoodsQty3)));
			AddQuestUserData("Fraht", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Fraht.DaysQty3)));
			AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money3)));
			AddQuestUserData("Fraht", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.StartCity+"Gen"));
			AddQuestUserData("Fraht", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.City3+"Gen"));
			SetFunctionTimerCondition("FrahtTime_Over", 0, 0, sti(pchar.questTemp.WPU.Fraht.DaysQty3), false);
			pchar.questTemp.WPU.Fraht.TargetPortmanID = pchar.questTemp.WPU.Fraht.City3+"_portman";
			pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iFrahtGoods3].Cost);//���� ������� ������
			pchar.questTemp.WPU.Fraht.GoodsAverigeCost = sti(Goods[iFrahtGoods3].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty3);//������� ��������� ������
			pchar.questTemp.WPU.Fraht.Goods = sti(pchar.questTemp.WPU.Fraht.Goods3);
			pchar.questTemp.WPU.Fraht.GoodsQty = sti(pchar.questTemp.WPU.Fraht.GoodsQty3);
			pchar.questTemp.WPU.Fraht.Money = sti(pchar.questTemp.WPU.Fraht.Money3);
		break;
	
		case "Fraht_Forcemajor":
			pchar.questTemp.WPU.Fraht = "begin";
			sld = characterFromId(pchar.questTemp.WPU.Fraht.TargetPortmanID);
			pchar.questTemp.WPU.Fraht.Nation = sld.nation;//����� ����������
			pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(sld);//�� �������� ������
			pchar.questTemp.WPU.Fraht.TargetCity = FindTownOnIsland(pchar.questTemp.WPU.Current.TargetIslandID);
			pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)+1;//������� ��������� ������
			if (pchar.questTemp.WPU.Fraht.Chance > 3) TraderHunterOnMap();//������ �� �� ��������
			if (pchar.questTemp.WPU.Fraht.Chance == 2) FrahtHunterOnSea();//�������� �� � ���������
			DialogExit();
		break;
	
		case "Fraht_complete":
		ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
		{
			iFrahtGoods = makeint(pchar.questTemp.WPU.Fraht.Goods);
			amount = sti(pchar.questTemp.WPU.Fraht.GoodsQty) - GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods));
			if (amount > 0)
			{
				dialog.text = "������� ���������. �� ������ ���� �������� ���� " + GetGoodsNameAlt(iFrahtGoods)+ " � ���������� " + FindRussianQtyString(pchar.questTemp.WPU.Fraht.GoodsQty) + ". �� � ����, ��� �� �������� �� ���� ���� -  �� ������� " + FindRussianQtyString(sti(amount)) + " ������.";
				link.l1 = "������ ����! ��������� ����� �������! �� ������������, " + GetAddress_FormToNPC(NPChar) + ", � ������� ����������� ���������� � ���� ���� � ������ ���������.";
				link.l1.go = "Fraht_complete_3";
				break;
			}
			dialog.text = "������� ���������. �� ������ ���� �������� ���� " + GetGoodsNameAlt(iFrahtGoods)+ " � ���������� " + FindRussianQtyString(pchar.questTemp.WPU.Fraht.GoodsQty) + ". ���?";
			link.l1 = "���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "Fraht_complete_1";
		}
		else
		{
			dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� ����� - ����� � ���������.";
			link.l1 = "������, � ��� � ������.";
			link.l1.go = "exit";
		}
		break;
	
		case "Fraht_complete_1":
			if (pchar.questTemp.WPU.Fraht == "late")//��������
			{
				iTime = makeint(GetQuestPastDayParam("questTemp.Fraht.Late"))+1;
				pchar.questTemp.WPU.Fraht.DayLate = iTime;
				pchar.questTemp.WPU.Fraht.PercentLate = iTime/0.2;
				pchar.questTemp.WPU.Fraht.Money = makeint(sti(pchar.questTemp.WPU.Fraht.Money) - sti(pchar.questTemp.WPU.Fraht.Money)*sti(pchar.questTemp.WPU.Fraht.PercentLate)/100);//������� ������ �������� ����� ���� ���������
				dialog.text = "��... �� �� �������� �� " + FindRussianDaysString(iTime)+ ". ������� � �������� ������� ������ ������ �� �����. �������� ��������, ����� ���������� 5 ��������� �� ����� �� ������ ���� ���������. ��������, ����������, ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ", � ������ ������������ ��������� ������� �������� � ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "Fraht_complete_2";
				break;
			}
			dialog.text = "������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ".";
			link.l1 = "�������!";
			link.l1.go = "Fraht_complete_2";
		break;
	
		case "Fraht_complete_2":
			if (pchar.questTemp.WPU.Fraht == "begin")
			{
				pchar.quest.FrahtTime_Over.over = "yes";
				AddQuestRecord("Fraht", "2");
			}
			else
			{
				pchar.quest.FrahtTime_FullOver.over = "yes";//����� ������ ������
				pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)-1;//���������� ���� �� �����������
				AddQuestRecord("Fraht", "4");
				AddQuestUserData("Fraht", "sDay", FindRussianDaysString(pchar.questTemp.WPU.Fraht.DayLate));
				AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)));
			}
			RemoveCharacterGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods), sti(pchar.questTemp.WPU.Fraht.GoodsQty));
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Fraht.Money));
			CloseQuestHeader("Fraht");
			DeleteAttribute(pchar, "questTemp.WPU.Fraht.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			pchar.questTemp.WPU.Fraht = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Commerce", 100);//��������
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Fraht.Nation), 2);
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
	
		case "Fraht_complete_bad":
			dialog.text = "�������� ����? �� ��� �������� ��� ����� �������� � �������� ����������. �, ������, ��� ��� �������� ��������. ���� ������ ������������ ���� ������� ��������� - �� ������ ������ �������������� ���� ������ � �������� ���������. ���� ������ �������� ����, �� ��� ��� �� �����.";
			link.l1 = "��, ����������. �������� �����.";
			link.l1.go = "Fraht_complete_bad_1";
		break;
	
		case "Fraht_complete_bad_1":
			pchar.questTemp.WPU.Fraht.GoodsAverigeCost = sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)*3;
			dialog.text = "��������� ������ � ����������� �������. ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)) + ".";
			if (sti(Pchar.money) >= sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost))
			{
				link.l1 = "��������. �� � �������, ������ ���� ������. ��� ���� ������.";
				link.l1.go = "Fraht_complete_pay";
			}
			link.l2 = "�� �� � ��� �����! ��������� ����� ���� ����� - ��� ���� ��������! ������ �� �� ���� �� ��������!";
			link.l2.go = "Fraht_complete_fail";
		break;
	
		case "Fraht_complete_pay":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost));
			dialog.text = "�� ��� ��, �������� �������. ������ � ����, ��� ���� ���� � ��������� ���������. �����, ��� �� ������ � ���� �������� � ������.";
			link.l1 = "�������. ��� ���� ����.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", 12);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Fraht.Nation), 30);
			if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus"))
			{
				AddQuestRecord("Escort", "8");
				AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)));
				CloseQuestHeader("Escort");
				pchar.questTemp.WPU.Escort = "complete";
				DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
				DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			}
			else
			{
				AddQuestRecord("Fraht", "6");
				AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)));
				CloseQuestHeader("Fraht");
				pchar.questTemp.WPU.Fraht = "complete";
				DeleteAttribute(pchar, "questTemp.WPU.Fraht.TargetPortmanID");
			}
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Commerce", 50);//��������
			AddCharacterExpToSkill(pchar, "Leadership", 70);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 70);//�������
		break;
	
		case "Fraht_complete_fail":
			dialog.text = "������, ��� ���... �� ��� ��, ����� ����� ���� �� ������ ���������� �� �� ����� �������� � �������� ���������� " + NationNameGenitive(sti(pchar.questTemp.WPU.Fraht.Nation)) + "! ����������!";
			link.l1 = "�������� ������...";
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus"))
			{
				AddQuestRecord("Escort", "9");
				AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)));
				CloseQuestHeader("Escort");
				pchar.questTemp.WPU.Escort = "complete";
				DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
				DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			}
			else
			{
				AddQuestRecord("Fraht", "7");
				CloseQuestHeader("Fraht");
				DeleteAttribute(pchar, "questTemp.WPU.Fraht.TargetPortmanID");
			}
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			pchar.questTemp.WPU.Fraht = "fail";
			ChangeCharacterComplexReputation(pchar,"nobility", -10);
		break;
	
		case "Fraht_complete_3":
			dialog.text = "������������, ���������� ��� �����, ��� ���� ����� �������, � ���������� �� ���� �����.";
			link.l1 = "����� �� ���� ������ �������!";
			link.l1.go = "exit";
		break;
	//����� <--
	
/// -------------------------------������ �������� �� �������� �����-------------------------------------

		case "Postcureer":
			pchar.questTemp.WPU.Postcureer.City = findCurrentCity2(npchar);
			pchar.questTemp.WPU.Postcureer.StartCity = npchar.city;//����� ������������
			pchar.questTemp.WPU.Postcureer.Chance = rand(4);//����-�����
			idaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Postcureer.StartCity), GetArealByCityName(pchar.questTemp.WPU.Postcureer.City));
			pchar.questTemp.WPU.Postcureer.DaysQty = makeint(sti(idaysQty)*(frand(0.3)+0.7)); 
			if (sti(pchar.questTemp.WPU.Postcureer.DaysQty) == 1) pchar.questTemp.WPU.Postcureer.DaysQty = 2;
			pchar.questTemp.WPU.Postcureer.Money = (sti(idaysQty)*1000)*sti(idaysQty)/sti(pchar.questTemp.WPU.Postcureer.DaysQty)*(1+frand(0.2));
			dialog.text = "���������� ��������� ��� ���� ����� � �������� ���������� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Postcureer.City) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Postcureer.DaysQty) + ", � ��� ����� �������. ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money))".";
			link.l1 = "� ��������!";
			link.l1.go = "Postcureer_1";
			link.l2 = "��... �� ��� ������ � ������ �������. �������� ����������.";
			link.l2.go = "exit";
		break;
	
		case "Postcureer_1":
			dialog.text = "������������! ����� �� ��� �����������. ��������, ����������, �����.";
			link.l1 = "��� ������ � ����!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "PostLetters");
			pchar.questTemp.WPU.Postcureer = "begin";
			pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_portman";//�� ��������
			sld = characterFromId(pchar.questTemp.WPU.Postcureer.TargetPortmanID);
			pchar.questTemp.WPU.Postcureer.Nation = sld.nation;//����� ����������
			pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(sld);//�� �������� ������
			pchar.questTemp.WPU.Postcureer.EnemyNation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.questTemp.WPU.Postcureer.EnemyNation) == PIRATE)
			{
				pchar.questTemp.WPU.Postcureer.EnemyNation = GetEnemyNationToMainCharacter();
			}
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)+1;//������� ��������� ��������
			//��������� ������ ��� �������� > 4
			if (!CheckAttribute(pchar, "questTemp.RegataGo") && sti(pchar.questTemp.WPU.Postcureer.count) > 4)
			{
				pchar.questTemp.RegataGo = "true";
				pchar.questTemp.Regata.CureerCity = FindFriendCityToMC(true);//�����, � ������� �������� ��������
				if (pchar.questTemp.Regata.CureerCity == "PortRoyal") pchar.questTemp.Regata.CureerCity = "SentJons";
				pchar.quest.Regata_Cureer.win_condition.l1 = "location";
				pchar.quest.Regata_Cureer.win_condition.l1.location = pchar.questTemp.Regata.CureerCity+"_town";
				pchar.quest.Regata_Cureer.function = "PrepareToRegata";
				log_testinfo(pchar.questTemp.Regata.CureerCity);
			}
			if (pchar.questTemp.WPU.Postcureer.Chance > 3) EnemyNationHunterOnMap(false);//������ ������������� �� ��������
			if (pchar.questTemp.WPU.Postcureer.Chance == 2) FrahtHunterOnSea();//�������� ������������� � ���������
			ReOpenQuestHeader("Postcureer");
			AddQuestRecord("Postcureer", "1");
			AddQuestUserData("Postcureer", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty)));
			AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)));
			AddQuestUserData("Postcureer", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen"));
			AddQuestUserData("Postcureer", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen"));
			SetFunctionTimerCondition("PostcureerTime_Over", 0, 0, sti(pchar.questTemp.WPU.Postcureer.DaysQty), false);
		break;
	
		case "Postcureer_complete":
			if (pchar.questTemp.WPU.Postcureer == "late")//��������
			{
				iTime = makeint(GetQuestPastDayParam("questTemp.Postcureer.Late"))+1;
				pchar.questTemp.WPU.Postcureer.DayLate = iTime;
				pchar.questTemp.WPU.Postcureer.PercentLate = iTime/0.1;
				pchar.questTemp.WPU.Postcureer.Money = makeint(sti(pchar.questTemp.WPU.Postcureer.Money) - sti(pchar.questTemp.WPU.Postcureer.Money)*sti(pchar.questTemp.WPU.Postcureer.PercentLate)/100);//������� ������ �������� ����� ���� ���������
				dialog.text = "��... �� �� �������� �� " + FindRussianDaysString(iTime)+ ". ������� � �������� ������� ������ ������ �� ������. �������� ��������, ����� ���������� 10 ��������� �� ����� �� ������ ���� ���������. ��������, ����������, ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ", � ������ ������������ ��������� ������� �������� � ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "Postcureer_complete_1";
				break;
			}
			dialog.text = "������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ".";
			link.l1 = "�������!";
			link.l1.go = "Postcureer_complete_1";
		break;
	
		case "Postcureer_complete_1":
			if (pchar.questTemp.WPU.Postcureer == "begin")
			{
				pchar.quest.PostcureerTime_Over.over = "yes";
				AddQuestRecord("Postcureer", "2");
			}
			else
			{
				pchar.quest.PostcureerTime_FullOver.over = "yes";//����� ������ ������
				pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-1;//���������� ���� �� �����������
				AddQuestRecord("Postcureer", "4");
				AddQuestUserData("Postcureer", "sDay", FindRussianDaysString(pchar.questTemp.WPU.Postcureer.DayLate));
				AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)));
			}
			RemoveItems(PChar, "PostLetters", 1);
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Postcureer.Money));
			CloseQuestHeader("Postcureer");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			pchar.questTemp.WPU.Postcureer = "complete";
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Sneak", 100);//����������
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), 2);
			Group_DeleteGroup("Fraht_Attack");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			DialogExit();
		break;
	
		case "Postcureer_complete_bad":
			dialog.text = "�� � ����� ��� ������ ���? ���� �� ����� ����� �����, � �� �������� ������ �������. �����, ������� �� ����, �����, �� ��� ��� � ��������. ��� �� ���������, �� � ����� ������ �� ����� ���� � ����.";
			link.l1 = "�������, �������. �������� ���� ������. ��������.";
			link.l1.go = "exit";
			RemoveItems(PChar, "PostLetters", 1);
			CloseQuestHeader("Postcureer");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			Group_DeleteGroup("Fraht_Attack");
			pchar.questTemp.WPU.Postcureer = "fail";
		break;
	
/// ---------------------------������ � �������� ������� ��� �������� ��������----------------------------

		case "escort":
			pchar.questTemp.WPU.Escort.ShipName1 = GenerateRandomNameToShip(sti(npchar.nation));//����� ��������
			pchar.questTemp.WPU.Escort.ShipName2 = GenerateRandomNameToShip(sti(npchar.nation));
			pchar.questTemp.WPU.Escort.Goods1 = rand(GOOD_PAPRIKA);
			pchar.questTemp.WPU.Escort.Goods2 = rand(GOOD_PAPRIKA);
			pchar.questTemp.WPU.Escort.City = findCurrentCity1(npchar);//������� �����
			pchar.questTemp.WPU.Escort.StartCity = npchar.city;//����� ������������
			pchar.questTemp.WPU.Escort.Chance = rand(4);//����-�����
			idaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Escort.StartCity), GetArealByCityName(pchar.questTemp.WPU.Escort.City));
			pchar.questTemp.WPU.Escort.DaysQty = makeint(sti(idaysQty)*(frand(0.5)+1)); 
			pchar.questTemp.WPU.Escort.Money = (sti(idaysQty)*2000)*sti(idaysQty)/sti(pchar.questTemp.WPU.Escort.DaysQty)*(1+frand(0.2));
			dialog.text = "����, ���������� ����������� ������� '" + pchar.questTemp.WPU.Escort.ShipName1 + "' � '" + pchar.questTemp.WPU.Escort.ShipName2 + "' �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Escort.City) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Escort.DaysQty) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money))". ��� ������� ������ ������� ������ ���������� � ������� � �����������. ������� ������� ��������� ��������� ��������� ����������, ������ �������� � ���� ��.";
			link.l1 = "������ ����. ��������� � ����������?";
			link.l1.go = "escort_1";
			link.l2 = "��... �� ��� ������ � ������ �������. �������� ����������.";
			link.l2.go = "exit";
		break;
	
		case "escort_1":
			dialog.text = "�����������. ������� ���������� ��� ���� ������������.";
			link.l1 = "����������� � ����!";
			link.l1.go = "escort_add_ships";
			pchar.questTemp.WPU.Escort = "begin";
			pchar.questTemp.WPU.Escort.ShipNation = npchar.nation;//����� �����������
			pchar.questTemp.WPU.Escort.TargetPortmanID = pchar.questTemp.WPU.Escort.City +"_portman";//�� ��������
			sld = characterFromId(pchar.questTemp.WPU.Escort.TargetPortmanID);
			pchar.questTemp.WPU.Escort.Nation = sld.nation;//����� ����������
			pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(sld);//�� �������� ������
			pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.questTemp.WPU.Postcureer.EnemyNation) == PIRATE)
			{
				pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();
			}
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)+1;//������� ��������� �������
			if (pchar.questTemp.WPU.Escort.Chance > 3) EnemyNationHunterOnMap(false);//������ ������������� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance == 3) TraderHunterOnMap();//������ �� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance < 2) FrahtHunterOnSea();//�������� ������������� � ���������
			ReOpenQuestHeader("Escort");
			AddQuestRecord("Escort", "1");
			AddQuestUserData("Escort", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Escort.DaysQty)));
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
			AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
			AddQuestUserData("Escort", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.City+"Gen"));
			SetFunctionTimerCondition("EscortTime_Over", 0, 0, sti(pchar.questTemp.WPU.Escort.DaysQty), false);
		break;
	
		case "escort_add_ships":
			int iGoods1, iGoods2, iSpace1, iSpace2, ShipType, Rank;
			int iNation = pchar.questTemp.WPU.Escort.ShipNation;
			int iLifeday = sti(pchar.questTemp.WPU.Escort.DaysQty)+10;
			string sTemp;
	        for (i=1; i<=2; i++)
	        {
				switch (rand(2))
				{
					case 0:  
						ShipType = SHIP_FLEUT;     					
						Rank = 10 + rand(5);
					break; 		
					case 1:  
						ShipType = SHIP_GALEON_L;			
						Rank = 15 + rand(5);
					break; 
					case 2: 
						ShipType = SHIP_PINNACE; 				
						Rank = 20 + rand(5);
					break;
				}
				if (i == 1) sTemp = pchar.questTemp.WPU.Escort.ShipName1;
				if (i == 2) sTemp = pchar.questTemp.WPU.Escort.ShipName2;
				if (i == 2) ShipType = SHIP_FLEUT;//���� ������ �����
	            sld = GetCharacter(NPC_GenerateCharacter("EscortCaptain_"+i, "trader_"+(rand(15)+1), "man", "man", Rank, iNation, iLifeday, true, "citizen"));
				FantomMakeSmallSailor(sld, ShipType, sTemp, CANNON_TYPE_CANNON_LBS16, 10+rand(10), 10+rand(10), 10+rand(10), 10+rand(10), 10+rand(10));
				DeleteAttribute(sld, "SaveItemsForDead");
				DeleteAttribute(sld, "DontClearDead");
				SetCharacterGoods(sld, GOOD_FOOD, 400+rand(200));
				SetCharacterGoods(sld, GOOD_MEDICAMENT, 60+rand(30));
	            iGoods1 = sti(pchar.questTemp.WPU.Escort.Goods1);
				iSpace1 = GetCharacterFreeSpace(sld, iGoods1);
				iSpace1 = makeint(iSpace1/2 + rand(iSpace1/2));
				iGoods2 = sti(pchar.questTemp.WPU.Escort.Goods2);
				iSpace2 = GetCharacterFreeSpace(sld, iGoods2);
				iSpace2 = makeint(iSpace2/2 + rand(iSpace2/2));
				if (i == 1) SetCharacterGoods(sld, iGoods1, iSpace1);
				if (i == 2) SetCharacterGoods(sld, iGoods2, iSpace2);
				sld.CompanionEnemyEnable = false; //������ ������
	            SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				SetCharacterRemovable(sld, false);
				sld.Dialog.Filename = "Common_portman.c";
				sld.dialog.currentnode = "Escort_companion";
				pchar.quest.Escort_fail.win_condition.l1 = "NPC_Death";
				pchar.quest.Escort_fail.win_condition.l1.character = "EscortCaptain_1";
				pchar.quest.Escort_fail.win_condition.l2 = "NPC_Death";
				pchar.quest.Escort_fail.win_condition.l2.character = "EscortCaptain_2";
				pchar.quest.Escort_fail.function = "Escort_failed";
	        }
			if (pchar.questTemp.WPU.Escort.Chance > 3) EnemyNationHunterOnMap(false);//������ ������������� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance == 3) TraderHunterOnMap();//������ �� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance < 2) FrahtHunterOnSea();//�������� ������������� � ���������
			DialogExit();
		break;
	
		case "Escort_complete":
		ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
		{
			//���������, ��� �� �������
			if (GetCharacterIndex("EscortCaptain_1") == -1 || GetCharacterIndex("EscortCaptain_2") == -1)
			{
				dialog.text = "��... � ����, � ��� � ������� ������� ������ ���� �������. ��� ���?";
				link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". ������ ������ � ��� � �������������� ��������.";
				if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus")) 
				{
					link.l1.go = "EscortBonus_complete_fail";
				}
				else
				{
					link.l1.go = "Escort_complete_fail";
				}
				break;
			}
			iGoods = pchar.questTemp.WPU.Escort.Goods;
			if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus")) 
			{
				//pchar.questTemp.WPU.Escort.Money = sti(pchar.questTemp.WPU.Escort.Money)+sti(pchar.questTemp.WPU.Escort.BonusMoney);
				pchar.questTemp.WPU.Escort.Money = sti(pchar.questTemp.WPU.Escort.TotalMoney);
				amount = sti(pchar.questTemp.WPU.Escort.GoodsQty) - GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods));
				if (amount > 0)
				{
					dialog.text = "���, ������������. �� ������ ���� ����������� ������� � �������� ���� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.GoodsQty)) + ". �� � ����, ��� �� �������� �� ���� ���� -  �� ������� " + FindRussianQtyString(sti(amount)) + " ������.";
					link.l1 = "������ ����! ��������� ����� �������! �� ������������, " + GetAddress_FormToNPC(NPChar) + ", � ������� ����������� ���������� � ���� ���� � ������ ���������.";
					link.l1.go = "Fraht_complete_3";
					break;
				}
			}
			if (pchar.questTemp.WPU.Escort == "late")//��������
			{
				iTime = makeint(GetQuestPastDayParam("questTemp.Escort.Late"))+1;
				pchar.questTemp.WPU.Escort.DayLate = iTime;
				pchar.questTemp.WPU.Escort.PercentLate = iTime/0.1;
				pchar.questTemp.WPU.Escort.Money = makeint(sti(pchar.questTemp.WPU.Escort.Money) - sti(pchar.questTemp.WPU.Escort.Money)*sti(pchar.questTemp.WPU.Escort.PercentLate)/100);//������� ������ �������� ����� ���� ���������
				dialog.text = "��... �� �� �������� �� " + FindRussianDaysString(iTime)+ ". ������� � �������� ������� ������ ������ �� ������. �������� ��������, ����� ���������� 10 ��������� �� ����� �� ������ ���� ���������. ��������, ����������, ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)) + ", � ������ ������������ ��������� ������� �������� � ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "Escort_complete_1";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus")) 
			{
				dialog.text = "���, ������������. �� ������ ���� ����������� ������� � �������� ���� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.GoodsQty)) + ". ������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)) + ".";
			}
			else
			{
				dialog.text = "������� �� ����������� ������. �������� ���� ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)) + ".";
			}
			link.l1 = "�������!";
			link.l1.go = "Escort_complete_1";
		}
		else
		{
			dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� ����� - ����� � ���������.";
			link.l1 = "������, � ��� � ������.";
			link.l1.go = "exit";
		}
		break;
	
		case "Escort_complete_1":
			pchar.quest.Escort_fail.over = "yes";//����� ����������
			if (pchar.questTemp.WPU.Escort == "begin")
			{
				pchar.quest.EscortTime_Over.over = "yes";//����� ������
				AddQuestRecord("Escort", "2");
			}
			else
			{
				pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)-1;//���������� ���� �� �����������
				pchar.quest.EscortTime_FullOver.over = "yes";//����� ������ ������
				if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus"))
				{
					pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)-1;//���������� ���� �� �����������
				}
				AddQuestRecord("Escort", "4");
				AddQuestUserData("Escort", "sDay", FindRussianDaysString(pchar.questTemp.WPU.Escort.DayLate));
				AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
			}
			RemoveCharacterCompanion(Pchar, characterFromID("EscortCaptain_1"));//������ �����������
			RemoveCharacterCompanion(Pchar, characterFromID("EscortCaptain_2"));
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.Money));
			if (CheckAttribute(pchar, "questTemp.WPU.Escort.Bonus")) RemoveCharacterGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods), sti(pchar.questTemp.WPU.Escort.GoodsQty));
			CloseQuestHeader("Escort");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			pchar.questTemp.WPU.Escort = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
			AddCharacterExpToSkill(pchar, "Defence", 100);//������
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), 2);
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
	
		case "escort_bonus":
			pchar.questTemp.WPU.Escort.ShipName1 = GenerateRandomNameToShip(sti(npchar.nation));//����� ��������
			pchar.questTemp.WPU.Escort.ShipName2 = GenerateRandomNameToShip(sti(npchar.nation));
			pchar.questTemp.WPU.Escort.Goods = 	drand(GOOD_PAPRIKA);//��� ��
			pchar.questTemp.WPU.Escort.Goods1 = drand(GOOD_PAPRIKA-3);
			pchar.questTemp.WPU.Escort.Goods2 = drand(GOOD_PAPRIKA-5);
			iGoods = pchar.questTemp.WPU.Escort.Goods;
			iGoodsQty = makeint(GetCharacterFreeSpace(pchar, iGoods))-(50+rand(100));//���������� �����
			pchar.questTemp.WPU.Escort.GoodsQty = iGoodsQty;
			pchar.questTemp.WPU.Escort.City = findCurrentCity1(npchar);//������� �����
			pchar.questTemp.WPU.Escort.StartCity = npchar.city;//����� ������������
			pchar.questTemp.WPU.Escort.Chance = rand(4);//����-�����
			idaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Escort.StartCity), GetArealByCityName(pchar.questTemp.WPU.Escort.City));
			pchar.questTemp.WPU.Escort.DaysQty = makeint(sti(idaysQty)*(frand(0.5)+1));//���
			pchar.questTemp.WPU.Escort.Money = (sti(idaysQty)*2000)*sti(idaysQty)/sti(pchar.questTemp.WPU.Escort.DaysQty)*(1+frand(0.2));//������ �� �������������
			pchar.questTemp.WPU.Escort.BonusMoney = (makeint((sti(iGoodsQty) * sti(Goods[iGoods].Weight) / sti(Goods[iGoods].Units))))*(sti(idaysQty)*2)*sti(idaysQty)/sti(pchar.questTemp.WPU.Escort.DaysQty);//������ �� �����
			pchar.questTemp.WPU.Escort.TotalMoney = sti(pchar.questTemp.WPU.Escort.Money)+sti(pchar.questTemp.WPU.Escort.BonusMoney); // ����� �����
			dialog.text = "����, ���������� ����������� ������� '" + pchar.questTemp.WPU.Escort.ShipName1 + "' � '" + pchar.questTemp.WPU.Escort.ShipName2 + "' �� ������ " + XI_ConvertString("Colony" + pchar.questTemp.WPU.Escort.City) + ", �� " +  FindRussianDaysString(pchar.questTemp.WPU.Escort.DaysQty) + ". ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money))+ "\n����� �� ����� ������� � �������� ���� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ". ������ �� ��� �������� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney))+".";
			link.l1 = "������ ����. ��������� � ����������?";
			link.l1.go = "escort_bonus_1";
			link.l2 = "��... �� ��� ������ � ������ �������. �������� ����������.";
			link.l2.go = "exit";
		break;
	
		case "escort_bonus_1":
			dialog.text = "����� ������! ���������� ������������ ��������.";
			link.l1 = "����������� � ����!";
			link.l1.go = "escort_add_ships";
			iGoods = pchar.questTemp.WPU.Escort.Goods;
			AddCharacterGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods), sti(pchar.questTemp.WPU.Escort.GoodsQty));
			pchar.questTemp.WPU.Escort = "begin";
			pchar.questTemp.WPU.Escort.Bonus = "true";
			pchar.questTemp.WPU.Escort.ShipNation = npchar.nation;//����� �����������
			pchar.questTemp.WPU.Escort.TargetPortmanID = pchar.questTemp.WPU.Escort.City +"_portman";//�� ��������
			sld = characterFromId(pchar.questTemp.WPU.Escort.TargetPortmanID);
			pchar.questTemp.WPU.Escort.Nation = sld.nation;//����� ����������
			pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(sld);//�� �������� ������
			pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.questTemp.WPU.Postcureer.EnemyNation) == PIRATE)
			{
				pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();
			}
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)+1;//������� ��������� �������
			pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)+1;//������� ��������� ������
			if (pchar.questTemp.WPU.Escort.Chance > 3) EnemyNationHunterOnMap(false);//������ ������������� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance == 3) TraderHunterOnMap();//������ �� �� ��������
			if (pchar.questTemp.WPU.Escort.Chance < 3) FrahtHunterOnSea();//�������� ������������� � ���������
			ReOpenQuestHeader("Escort");
			AddQuestRecord("Escort", "6");
			AddQuestUserData("Escort", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Escort.DaysQty)));
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
			AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
			AddQuestUserData("Escort", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.City+"Gen"));
			AddQuestUserData("Escort", "sGoods", GetGoodsNameAlt(iGoods));
			AddQuestUserData("Escort", "sGoodQty", FindRussianQtyString(sti(pchar.questTemp.WPU.Escort.GoodsQty)));
			AddQuestUserData("Escort", "sMoney1", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney)));
			pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost);//���� ������� ������
			pchar.questTemp.WPU.Fraht.GoodsAverigeCost = sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Escort.GoodsQty);//������� ��������� ������
			SetFunctionTimerCondition("EscortTime_Over", 0, 0, sti(pchar.questTemp.WPU.Escort.DaysQty), false);
		break;
	
		case "Escort_complete_fail":
			dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� ���� ���� �� �����. ��������.";
			link.l1 = "����� �� ��� ��������������... ����� �������.";
			link.l1.go = "exit";
			pchar.quest.Escort_fail.over = "yes";//����� ����������
			pchar.quest.EscortTime_Over.over = "yes";//����� ���������� // patch-2
			if (GetCharacterIndex("EscortCaptain_1") == -1) RemoveCharacterCompanion(pchar, characterFromID("EscortCaptain_2"));
			else RemoveCharacterCompanion(pchar, characterFromID("EscortCaptain_1"));
			AddQuestRecord("Escort", "11");
			CloseQuestHeader("Escort");
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)-1;//���� �� �����������
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			pchar.questTemp.WPU.Escort = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Defence", 150);//������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			Group_DeleteGroup("Fraht_Attack");
		break;
	
		case "EscortBonus_complete_fail":
			if (GetCharacterIndex("EscortCaptain_1") == -1) RemoveCharacterCompanion(pchar, characterFromID("EscortCaptain_2"));
			else RemoveCharacterCompanion(pchar, characterFromID("EscortCaptain_1"));//������ ����������
			pchar.quest.Escort_fail.over = "yes";//����� ����������
			amount = sti(pchar.questTemp.WPU.Escort.GoodsQty) - GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods));
			pchar.questTemp.WPU.Escort.GoodsQty = GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods));
			if (pchar.questTemp.WPU.Escort == "begin")
			{
				pchar.quest.EscortTime_Over.over = "yes";//����� ������
				pchar.questTemp.WPU.Escort.MinusMoney = makeint(sti(pchar.questTemp.WPU.Escort.BonusMoney) - sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)*sti(amount));
				if (sti(pchar.questTemp.WPU.Escort.MinusMoney) < 0) amount = 101;
				if (amount > 0 && amount <= 100)
				{
					pchar.questTemp.WPU.Escort.BonusMoney = sti(pchar.questTemp.WPU.Escort.MinusMoney);
					dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� �� ������������� ���� ���� �� �����... �� ��� � ����� � ��� ��������� - " + FindRussianQtyString(sti(amount)) + "\n� �����, � ����� ��� �������������� ������ �� �����, �� ������� ��������� ������������ ������, �� ��, ��� �� ���� ���� ��������� � ���������� ����. �������� ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney))+ " � ������ ���� ��������.";
					link.l1 = "������� � �� ����.";
					link.l1.go = "EscortBonus_complete_fail_1";
					break;
				}
				if (amount > 100)
				{
					dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� �� ������������� ���� ���� �� �����... �� ��� � ����� � ��� �������� ���������\n� ���� ��� ����������� �����, ���� �� �������� ����������� ����������. ������� ��� �������� �������������� ��������� ����� �������� � ������ ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost))+ ". ��� �� ���� �������� ����.";
					if (sti(pchar.money) >= sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost))
					{
						link.l1 = "������-������, �� ����������, ��� ���� ������.";
						link.l1.go = "EscortBonus_complete_fail_2";
					}
					link.l2 = "�� �� ��� � ��� ���������! ��� �� ����� ��������� ��������������! ������ � ��� �� ���!";
					link.l2.go = "EscortBonus_complete_fail_3";
					break;
				}
				dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� �� ������������� ���� ���� �� �����\n� �����, � ����� ��� �������������� ������ �� �����, �� ��, ��� �� ���� ���� ���������. �������� ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney))+ " � ������ ���� ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "EscortBonus_complete_fail_1";
				break;
			}
			if (pchar.questTemp.WPU.Escort == "late")
			{
				pchar.quest.EscortTime_FullOver.over = "yes";//����� ������ ������
				iTime = makeint(GetQuestPastDayParam("questTemp.Escort.Late"))+1;
				pchar.questTemp.WPU.Escort.DayLate = iTime;
				pchar.questTemp.WPU.Escort.PercentLate = iTime/0.1;
				pchar.questTemp.WPU.Escort.BonusMoney = makeint(sti(pchar.questTemp.WPU.Escort.BonusMoney) - sti(pchar.questTemp.WPU.Escort.BonusMoney)*sti(pchar.questTemp.WPU.Escort.PercentLate)/100);//������� ������ �������� ����� ���� ���������
				if (amount > 0)
				{
					dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� �� ������������� ���� ���� �� �����... ������� ��������, �������� �� " + FindRussianDaysString(iTime)+ ", �� ��� � ����� � ��� ��������� - " + FindRussianQtyString(sti(amount)) + "\n� ���� ��� ����������� �����, ���� �� �������� ����������� ����������. ������� ��� �������� �������������� ��������� ����� �������� � ������ ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost))+ ". ��� �� ���� �������� ����.";
					if (sti(pchar.money) >= sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost))
					{
						link.l1 = "������-������, �� ����������, ��� ���� ������.";
						link.l1.go = "EscortBonus_complete_fail_2";
					}
					link.l2 = "�� �� ��� � ��� ���������! ��� �� ����� ��������� ��������������! ������ � ��� �� ���!";
					link.l2.go = "EscortBonus_complete_fail_3";
					break;
				}
				dialog.text = "����������! � ����� �� ����� ����� ���� ��? ��� �� ��������� �����?! � �����, ��� �������, ��� �� � ����� �������������� �� ������������� ���� ���� �� �����... �� ��� � �������� �� " + FindRussianDaysString(iTime)+ "\n������� � �������� ������� ������ ������ �� �����. �������� ��������, ����� ���������� 10 ��������� �� ����� �� ������ ���� ���������. ��������, ����������, ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney)) + ", � ������ ���� ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "EscortBonus_complete_fail_1";
				break;
			}
		break;
	
		case "EscortBonus_complete_fail_1"://�������� �������, ����� � ���� � ����� ��� ��������
			AddQuestRecord("Escort", "12");
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.BonusMoney)));
			CloseQuestHeader("Escort");
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.BonusMoney));
			RemoveCharacterGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods), sti(pchar.questTemp.WPU.Escort.GoodsQty));
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)-1;//���� �� �����������
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			pchar.questTemp.WPU.Escort = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Defence", 150);//������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddCharacterExpToSkill(pchar, "Commerce", 100);//��������
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
	
		case "EscortBonus_complete_fail_2"://�������� ������� � ����, ����� ����� ��� ���, ���
			AddQuestRecord("Escort", "13");
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)));
			CloseQuestHeader("Escort");
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost));
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)-1;//���� �� �����������
			pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Fraht.count)-1;//���� �� �����������
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			pchar.questTemp.WPU.Escort = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Defence", 150);//������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			AddCharacterExpToSkill(pchar, "Commerce", 50);//��������
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
	
		case "EscortBonus_complete_fail_3"://�������� ������� � ����, ����� ����� ��� ���, �����
			dialog.text = "������, ��� ���... �� ��� ��, ����� ����� ���� �� ������ ���������� �� �� ����� �������� � �������� ���������� " + NationNameGenitive(sti(pchar.questTemp.WPU.Escort.Nation)) + "! ����������!";
			link.l1 = "�������� ������...";
			link.l1.go = "exit";
			AddQuestRecord("Escort", "14");
			AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigeCost)));
			CloseQuestHeader("Escort");
			pchar.questTemp.WPU.Escort.count = 0;//������� � ����
			pchar.questTemp.WPU.Escort.count = 0;//������� � ����
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			pchar.questTemp.WPU.Escort = "complete";
			pchar.questTemp.WPU.Fraht = "fail";
			ChangeCharacterComplexReputation(pchar,"nobility", -10);
			ChangeCharacterHunterScore(pchar, NationShortName(sti(pchar.questTemp.WPU.Escort.Nation)) + "hunter", 30);
			pchar.questTemp.WPU.Fraht.Nation = pchar.questTemp.WPU.Escort.Nation;
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			Group_DeleteGroup("Fraht_Attack");
		break;
	
		case "Escort_fail"://�������� 2 �������
			dialog.text = "��� ����� � ����� �����! � ��� ����, �������, ��� ����� ��������, �? ��� ������, ��� ������ ���?";
			link.l1 = "� ��� �������. ��������� ��� ����� �����, �... ��, � ���� ����� - ����-�� ��� �������... �� ����-��, ���� � ������! ������� � ��� �����������.";
			link.l1.go = "Escort_fail_complete";
		break;
	
		case "Escort_fail_complete":
			iFrahtGoods = makeint(pchar.questTemp.WPU.Escort.Goods);
			amount = sti(pchar.questTemp.WPU.Escort.GoodsQty) - GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods));
			if (amount > 0)
			{
				dialog.text = "������� ���������. �� ������ ���� �������� ���� " + GetGoodsNameAlt(iFrahtGoods)+ " � ���������� " + FindRussianQtyString(pchar.questTemp.WPU.Escort.GoodsQty) + ". �� � ����, ��� �� �������� �� ���� ���� - �� ������� " + FindRussianQtyString(sti(amount)) + " ������.";
				link.l1 = "������ ����! ��������� ����� �������! �� ������������, " + GetAddress_FormToNPC(NPChar) + ", � ������� ����������� ���������� � ���� ���� � ������ ���������.";
				link.l1.go = "Fraht_complete_3";
				break;
			}
			dialog.text = "������� ���������. �� ������ ���� �������� ���� " + GetGoodsNameAlt(iFrahtGoods)+ " � ���������� " + FindRussianQtyString(pchar.questTemp.WPU.Escort.GoodsQty) + ". ���?";
			link.l1 = "���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "Escort_fail_complete_1";
		break;
	
		case "Escort_fail_complete_1":
			DeleteAttribute(pchar, "questTemp.WPU.Escort.Bonus");
			pchar.questTemp.WPU.Escort.Money = makeint(sti(pchar.questTemp.WPU.Escort.BonusMoney)/2);
			if (pchar.questTemp.WPU.Escort == "late")//��������
			{
				iTime = makeint(GetQuestPastDayParam("questTemp.Escort.Late"))+1;
				pchar.questTemp.WPU.Escort.DayLate = iTime;
				pchar.questTemp.WPU.Escort.PercentLate = iTime/0.1;
				pchar.questTemp.WPU.Escort.Money = makeint(sti(pchar.questTemp.WPU.Escort.Money) - sti(pchar.questTemp.WPU.Escort.Money)*sti(pchar.questTemp.WPU.Escort.PercentLate)/100);//������� ������ �������� ����� ���� ���������
				dialog.text = "��... ���� ����, ��� �� �������� ��������� �������, �� ��� � �������� �� " + FindRussianDaysString(iTime)+ ". ������� � �������� ������� ������ ������ �� �����. ��� ��� �� �� ������ ��������� �������, ������ �� ����� � �������� �����, � ��� ����� �������, ��� � ���� ��� ���������\n����� ����, �������� ��������, ����� ���������� 10 ��������� �� ����� �� ������ ���� ���������. ��������, ����������, ���� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)) + ", � ������ ���� ��������.";
				link.l1 = "������� � �� ����.";
				link.l1.go = "Escort_fail_complete_2";
				break;
			}
			dialog.text = "�� ��� ��, ���� � � ���������� ���������, ��� �� �� ������ �������� ��������� �������, �� ������� ���� ���� �� ���������. ��� ��� �� �� ������ ��������� �������, ������ �� ����� � �������� �����, � ��� ����� �������, ��� � ���� ��� ���������\n�������� ���� ������ - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)) + " � ������ ���� ��������.";
			link.l1 = "������� � �� ����.";
			link.l1.go = "Escort_fail_complete_2";
		break;
	
		case "Escort_fail_complete_2":
			if (pchar.questTemp.WPU.Escort == "begin")
			{
				pchar.quest.EscortTime_Over.over = "yes";
				AddQuestRecord("Escort", "17");
				AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
			}
			else
			{
				pchar.quest.EscortTime_FullOver.over = "yes";//����� ������ ������
				AddQuestRecord("Escort", "18");
				AddQuestUserData("Escort", "sDay", FindRussianDaysString(pchar.questTemp.WPU.Escort.DayLate));
				AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
			}
			pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)-1;//�������� ���� �� �����������
			RemoveCharacterGoods(pchar, sti(pchar.questTemp.WPU.Escort.Goods), sti(pchar.questTemp.WPU.Escort.GoodsQty));
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.Money));
			CloseQuestHeader("Escort");
			DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current.TargetIslandID");
			pchar.questTemp.WPU.Escort = "complete";
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Commerce", 50);//��������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
	
//-------------------------------------������� 2 ������ ��� �������---------------------------------------------
		case "Postcureer_LevelUp":
			pchar.questTemp.WPU.Postcureer.City = findCurrentCity2(npchar);//������� �����
			pchar.questTemp.WPU.Postcureer.StartCity = npchar.city;//����� ������������
			idaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Postcureer.StartCity), GetArealByCityName(pchar.questTemp.WPU.Postcureer.City));
			pchar.questTemp.WPU.Postcureer.DaysQty = makeint(sti(idaysQty)*(frand(0.3)+0.6));//���
			pchar.questTemp.WPU.Postcureer.Money = (sti(idaysQty)*3000)*sti(idaysQty)/sti(pchar.questTemp.WPU.Postcureer.DaysQty)*(1+frand(0.2));//������
			pchar.questTemp.WPU.Postcureer.Chance = rand(4);//����-�����
			pchar.questTemp.WPU.Postcureer.StartNation = npchar.nation;//����� �����������
			pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_portman";//�� ��������
			sld = characterFromId(pchar.questTemp.WPU.Postcureer.TargetPortmanID);
			pchar.questTemp.WPU.Postcureer.Nation = sld.nation;//����� ����������
			pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(sld);//�� �������� ������
			pchar.questTemp.WPU.Postcureer.EnemyNation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.questTemp.WPU.Postcureer.EnemyNation) == PIRATE)
			{
				pchar.questTemp.WPU.Postcureer.EnemyNation = GetEnemyNationToMainCharacter();
			}

			switch (rand(3))
			{
				case 0:
					dialog.text = "���������� ������ ��������� ������ ��������������� ������ ��� ����������� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+" �� �����, ��� �� "+FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty))+". ���������� ���� ���������������� - �� ���� ������� ����� ������� �����. ������ �� �������� - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money))+".";
					link.l1 = "� ��������!";
					link.l1.go = "Postcureer_LevelUp_Go";
					link.l2 = "���, ��������, �������.";
					link.l2.go = "Postcureer_LevelDown";
					pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_Mayor";//�� ������
					pchar.questTemp.WPU.Current.Add = "������ ��� �����������";
					pchar.questTemp.WPU.Current.Item = "letter_2";//�������
					pchar.questTemp.WPU.Current.Itemdescr = "itmdescr_letter_2_PortmanLevelUp1";//��������
				break;
			
				case 1:
					dialog.text = "���������� ��������� ��� ������ ��� ������� �������� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+" �� �����, ��� �� "+FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty))+". ��� ��������� ������ ��� � ��������� ����� ���������� - ��������� ������������ ��������. ������� �������� ������������ - ���������� ������ ����� �������� �����. ������ �� �������� - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money))+".";
					link.l1 = "� ��������!";
					link.l1.go = "Postcureer_LevelUp_Go";
					link.l2 = "���, ��������, �������.";
					link.l2.go = "Postcureer_LevelDown";
					pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_trader";//�� ��������
					pchar.questTemp.WPU.Current.Add = "������ ��� ��� ������� ��������";
					pchar.questTemp.WPU.Current.Item = "letter_2";//�������
					pchar.questTemp.WPU.Current.Itemdescr = "itmdescr_letter_2_PortmanLevelUp2";//��������
				break;
			
				case 2:
					dialog.text = "���������� ��������� ���� ����� ���������� ��� ���������� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+" �� �����, ��� �� "+FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty))+". ����� ����� ������ ������� ���������� � ������ ����� � ������ �����. ������ ������ - ���� ������� ��� �������������� �����-�� ������ ��������. ������ �� �������� - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money))+".";
					link.l1 = "� ��������!";
					link.l1.go = "Postcureer_LevelUp_Go";
					link.l2 = "���, ��������, �������.";
					link.l2.go = "Postcureer_LevelDown";
					pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_usurer";//�� ����������
					pchar.questTemp.WPU.Current.Add = "����� � ������� ����������� ��� ����������";
					pchar.questTemp.WPU.Current.Item = "letter_2";//�������
					pchar.questTemp.WPU.Current.Itemdescr = "itmdescr_letter_2_PortmanLevelUp3";//��������
				break;
			
				case 3:
					dialog.text = "���������� ��������� ���� ������� ������� ����� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen")+" �� �����, ��� �� "+FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty))+". � ��� ��������� ������������ ������ ������ "+RandPhraseSimple(LinkRandPhrase("�����","�������","�������"), LinkRandPhrase("������","������","�������"))+", ���������� ���������� ����������� ����������. �����, �������, ��� ���� �������� ����� �������������� � ������... ���������������� ����, ��� ��� ������ ���. ������ �� �������� - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money))+".";
					link.l1 = "� ��������!";
					link.l1.go = "Postcureer_LevelUp_Go";
					link.l2 = "���, ��������, �������.";
					link.l2.go = "Postcureer_LevelDown";
					pchar.questTemp.WPU.Postcureer.TargetPortmanID = pchar.questTemp.WPU.Postcureer.City +"_shipyarder";//�� ��������
					pchar.questTemp.WPU.Current.Add = "������ ������ ������� ��� ������� �����";
					pchar.questTemp.WPU.Current.Item = "ShipyardsMap";//�������
					pchar.questTemp.WPU.Current.Itemdescr = "itmdescr_ShipyardsMap_PortmanLevelUp4";//��������
				break;
			}
		break;
	
		case "Postcureer_LevelUp_Go":
			dialog.text = "����� ������� ��������� � ������������� � ����. ����� ����� �... �� ������ ��� �������.";
			link.l1 = "�������!";
			link.l1.go = "Forsmajor_choose";
			pchar.questTemp.WPU.Postcureer = "begin";
			pchar.questTemp.WPU.Postcureer.LevelUp = "true";
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count) + 1;
			//��������� ������ ��� �������� > 4
			if (!CheckAttribute(pchar, "questTemp.RegataGo") && sti(pchar.questTemp.WPU.Postcureer.count) > 4)
			{
				pchar.questTemp.RegataGo = "true";
				pchar.questTemp.Regata.CureerCity = FindFriendCityToMC(true);//�����, � ������� �������� ��������
				if (pchar.questTemp.Regata.CureerCity == "PortRoyal") pchar.questTemp.Regata.CureerCity = "SentJons";
				pchar.quest.Regata_Cureer.win_condition.l1 = "location";
				pchar.quest.Regata_Cureer.win_condition.l1.location = pchar.questTemp.Regata.CureerCity+"_town";
				pchar.quest.Regata_Cureer.function = "PrepareToRegata";
				log_testinfo(pchar.questTemp.Regata.CureerCity);
			}
			GiveItem2Character(pchar, pchar.questTemp.WPU.Current.Item);
			ChangeItemDescribe(pchar.questTemp.WPU.Current.Item, pchar.questTemp.WPU.Current.Itemdescr);
			ReOpenQuestHeader("Postcureer");
			AddQuestRecord("Postcureer", "6");
			AddQuestUserData("Postcureer", "sDay", FindRussianDaysString(sti(pchar.questTemp.WPU.Postcureer.DaysQty)));
			AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)));
			AddQuestUserData("Postcureer", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen"));
			AddQuestUserData("Postcureer", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.City+"Gen"));
			AddQuestUserData("Postcureer", "sText", pchar.questTemp.WPU.Current.Add);
			SetFunctionTimerCondition("PostcureerTime_Over", 0, 0, sti(pchar.questTemp.WPU.Postcureer.DaysQty), false);
		break;
	
		case "Postcureer_LevelDown":
			dialog.text = "����, ����� ����... ������-��, ������ ������������� �� ��������������. �� ��� ���� ����, �������.";
			link.l1 = "��� ������ - ��� ����. �� ��������, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count) - 1;//�� ����� �� ����������� ������� �������
		break;
	
		case "Forsmajor_choose":
			switch (sti(pchar.questTemp.WPU.Postcureer.Chance))
			{
				case 0://�������� � ������ �������� + ��
					pchar.quest.Postcureer_Hunter.win_condition.l1 = "Location";
					pchar.quest.Postcureer_Hunter.win_condition.l1.location = pchar.questTemp.WPU.Postcureer.City + "_town";
					pchar.quest.Postcureer_Hunter.function = "PostcureerGopHuntersOnLand";
					TraderHunterOnMap();
				break;
		
				case 1://�������� ����������� ������������ �� ��������
					EnemyNationHunterOnMap(true);
				break;
		
				case 2://������ �� �� �������� � � ����� ��������
					TraderHunterOnMap();
					FrahtHunterOnSea();
				break;
		
				case 3://�������� � ��������� ������
					pchar.quest.Postcureer_Hunter.win_condition.l1 = "Location";
					pchar.quest.Postcureer_Hunter.win_condition.l1.location = pchar.questTemp.WPU.Postcureer.StartCity + "_town";
					pchar.quest.Postcureer_Hunter.function = "PostcureerProfHuntersOnLand";
				break;
		
				case 4://�����
					pchar.quest.Postcureer_Hunter.win_condition.l1 = "Location";
					pchar.quest.Postcureer_Hunter.win_condition.l1.location = pchar.questTemp.WPU.Postcureer.StartCity + "_town";
					pchar.quest.Postcureer_Hunter.function = "PostcureerAgent";
				break;
			}
			DialogExit();
		break;

		case "Postcureer_complete_fail":
			dialog.text = "���������! ������, ��� ���-���� ���������... ��, ����, �������, ��� �� �� ������ - ��� ����� ��� ��-������� �� �����... ��� ��� ���������?";
			link.l1 = "��� ������� �������� ����, � ������ ������, � ���������� �� �����, ��������� �������� � ������������...";
			link.l1.go = "Postcureer_complete_fail_1";
		break;

		case "Postcureer_complete_fail_1":
			dialog.text = "� ���������� ������ �����������, ����� ������ �����. ��, ����� �������, " + GetAddress_Form(NPChar) + ". ��������� - ����� ����, ��� �� �� ������...";
			link.l1 = "��� ���� ����� ����, " + GetAddress_FormToNPC(NPChar) + ", ��� ��� �����. �� ��������.";
			link.l1.go = "exit";
			if (pchar.questTemp.WPU.Postcureer == "begin") pchar.quest.PostcureerTime_Over.over = "yes";//����� ������
			if (pchar.questTemp.WPU.Postcureer == "late") pchar.quest.PostcureerTime_FullOver.over = "yes";//����� ������ ������
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-3;//������� �������
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.fail");
			pchar.questTemp.WPU.Postcureer = "complete";
		break;
	
//----------------------------------------������� 2 ������ �����------------------------------------------

	case "Fraht_LevelUp":
		rColony = GetColonyByIndex(FindColony(npchar.city));
		pchar.questTemp.WPU.Fraht.StartCity = npchar.city;//����� ������������
		pchar.questTemp.WPU.Fraht.Nation = npchar.nation;//����� ����������
		switch (rand(4))//��� ������
		{
			case 0:
				pchar.questTemp.WPU.Fraht.Goods = GOOD_CHOCOLATE + drand(makeint(GOOD_TOBACCO - GOOD_CHOCOLATE));
				iGoods = pchar.questTemp.WPU.Fraht.Goods;
				iGoodsQty = 3000 + sti(pchar.rank)*30*(drand(9)+1);
				pchar.questTemp.WPU.Fraht.GoodsQty = iGoodsQty;
				pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost)*2;//������� ���� ������� ������
				pchar.questTemp.WPU.Fraht.Money = sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty)*2;//������� ��������� ������
				pchar.questTemp.WPU.Current.Add = "�������";
				dialog.text = "� ����� ������� ����� ������ ����� �� ���� �����. � �������� ��� ��� �� �������. � �� ����� ��������� ��� �������� ��� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ", � ����� ��������� �� ���� ������� ���� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)) + " �� �������. � ����� ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ". ��, � ������������ ��������� �� ����� - ������ ����� � �� ����.";
				link.l1 = "������, � ������ �� ��� ����.";
				link.l1.go = "Fraht_LevelUp_Go";
				link.l2 = "��� ���� �������������� ���, �� ������ � �������� ���� �� ����.";
				link.l2.go = "Fraht_LevelDown";
				SetNull2StoreGood(rColony, sti(pchar.questTemp.WPU.Fraht.Goods));
			break;
		
			case 1:
				pchar.questTemp.WPU.Fraht.Goods = GOOD_EBONY + drand(makeint(GOOD_CINNAMON - GOOD_EBONY));
				iGoods = pchar.questTemp.WPU.Fraht.Goods;
				iGoodsQty = 1500 + sti(pchar.rank)*20*(drand(9)+1);
				pchar.questTemp.WPU.Fraht.GoodsQty = iGoodsQty;
				pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost)*2;//������� ���� ������� ������
				pchar.questTemp.WPU.Fraht.Money = sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty)*2;//������� ��������� ������
				pchar.questTemp.WPU.Current.Add = "�������";
				dialog.text = "� ����� ������� ����� ������ ����� �� ���� �����. � �������� ��� ��� �� �������. � �� ����� ��������� ��� �������� ��� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ", � ����� ��������� �� ���� ������� ���� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)) + " �� �������. � ����� ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ". ��, � ������������ ��������� �� ����� - ������ ����� � �� ����.";
				link.l1 = "������, � ������ �� ��� ����.";
				link.l1.go = "Fraht_LevelUp_Go";
				link.l2 = "��� ���� �������������� ���, �� ������ � �������� ���� �� ����.";
				link.l2.go = "Fraht_LevelDown";
				SetNull2StoreGood(rColony, sti(pchar.questTemp.WPU.Fraht.Goods));
			break;
		
			case 2:
				pchar.questTemp.WPU.Fraht.Goods = GOOD_BOMBS + drand(makeint(GOOD_POWDER - GOOD_BOMBS));
				iGoods = pchar.questTemp.WPU.Fraht.Goods;
				iGoodsQty = 15000 + sti(pchar.rank)*300*(drand(9)+1);
				pchar.questTemp.WPU.Fraht.GoodsQty = iGoodsQty;
				pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost)*3;//������� ���� ������� ������
				pchar.questTemp.WPU.Fraht.Money = makeint((sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty)*3)/20);//������� ��������� ������
				pchar.questTemp.WPU.Current.Add = "�������";
				dialog.text = "� �������� ����� ������� ��������������� �� ������� " + GetGoodsNameAlt(iGoods)+ ". � �������� ����� ������ ��� �� �������. � �� ����� ��������� ��� �������� ��� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ", � ����� ��������� ������� ���� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)) + " �� �������. � ����� ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ". ��, � ������������ ��������� �� ����� - ������ ����� � �� ����.";
				link.l1 = "������, � ������ �� ��� ����.";
				link.l1.go = "Fraht_LevelUp_Go";
				link.l2 = "��� ���� �������������� ���, �� ������ � �������� ���� �� ����.";
				link.l2.go = "Fraht_LevelDown";
				SetNull2StoreGood(rColony, sti(pchar.questTemp.WPU.Fraht.Goods));
			break;
		
			case 3:
				pchar.questTemp.WPU.Fraht.Goods = GOOD_MEDICAMENT;
				iGoods = pchar.questTemp.WPU.Fraht.Goods;
				iGoodsQty = 7000 + sti(pchar.rank)*300*(drand(9)+1);
				pchar.questTemp.WPU.Fraht.GoodsQty = iGoodsQty;
				pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost)*3;//������� ���� ������� ������
				pchar.questTemp.WPU.Fraht.Money = makeint((sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty)*3)/30);//������� ��������� ������
				pchar.questTemp.WPU.Current.Add = "�������";
				dialog.text = "����� �������� ������� �������� ��������� � ����� �������, �� ���������� ������ ���������� � ���������� - �� ��� ���� � ��������. ���������� ���������� ������������� ������. � ���� ��������� ��� �������� ��� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ", � ����� ��������� ������� ���� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)) + " �� �����. � ����� ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ". ��, � ������������ ��������� �� ����� - ������ ����� � �� ����.";
				link.l1 = "������, � ������ �� ��� ����.";
				link.l1.go = "Fraht_LevelUp_Go";
				link.l2 = "��� ���� �������������� ���, �� ������ � �������� ���� �� ����.";
				link.l2.go = "Fraht_LevelDown";
				SetNull2StoreGood(rColony, sti(pchar.questTemp.WPU.Fraht.Goods));
			break;
		
			case 4:
				pchar.questTemp.WPU.Fraht.Goods = GOOD_FOOD;
				iGoods = pchar.questTemp.WPU.Fraht.Goods;
				iGoodsQty = 15000 + sti(pchar.rank)*300*(drand(9)+1);
				pchar.questTemp.WPU.Fraht.GoodsQty = iGoodsQty;
				pchar.questTemp.WPU.Fraht.GoodsAverigePrice = sti(Goods[iGoods].Cost)*2;//������� ���� ������� ������
				pchar.questTemp.WPU.Fraht.Money = makeint((sti(Goods[iGoods].Cost)*sti(pchar.questTemp.WPU.Fraht.GoodsQty)*2)/10);//������� ��������� ������
				pchar.questTemp.WPU.Current.Add = "�������";
				dialog.text = "����� �������� ���� ������� ��������� ��������� � ��������� ��������������. �� ������ ������ ������ ��� �� ������ - ���� � �������� ���������� ��������� ������. � ���� ��������� ��� �������� ��� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(iGoodsQty) + ", � ����� ��������� ������� ���� - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.GoodsAverigePrice)) + " �� �����. � ����� ��� �������� " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)) + ". ��, � ������������ ��������� �� ����� - ������ ����� � �� ����.";
				link.l1 = "������, � ������ �� ��� ����.";
				link.l1.go = "Fraht_LevelUp_Go";
				link.l2 = "��� ���� �������������� ���, �� ������ � �������� ���� �� ����.";
				link.l2.go = "Fraht_LevelDown";
				SetNull2StoreGood(rColony, sti(pchar.questTemp.WPU.Fraht.Goods));
			break;
		}
	break;
		
	case "Fraht_LevelDown":
		DialogExit();
		pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count)-1;//������� �������
	break;
		
	case "Fraht_LevelUp_Go":
		dialog.text = "�������! � ���, ��� �� �����������. ������� ������� ��� � ������ ������� �����.";
		link.l1 = "����������, " + GetAddress_FormToNPC(NPChar) + ".";
		link.l1.go = "exit";
		pchar.questTemp.WPU.Fraht = "begin";
		pchar.questTemp.WPU.Fraht.LevelUp = "true";
		pchar.questTemp.WPU.Fraht.count = sti(pchar.questTemp.WPU.Fraht.count) + 1;
		pchar.questTemp.WPU.Fraht.TargetPortmanID = pchar.questTemp.WPU.Fraht.StartCity +"_portman";//�� ��������
		iGoods = pchar.questTemp.WPU.Fraht.Goods;
		ReOpenQuestHeader("Fraht");
		AddQuestRecord("Fraht", "8");
		AddQuestUserData("Fraht", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money)));
		AddQuestUserData("Fraht", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Fraht.StartCity+"Gen"));
		AddQuestUserData("Fraht", "sGoods", GetGoodsNameAlt(iGoods));
		AddQuestUserData("Fraht", "sGoodQty", FindRussianQtyString(sti(pchar.questTemp.WPU.Fraht.GoodsQty)));
		AddQuestUserData("Fraht", "sText", pchar.questTemp.WPU.Current.Add);
		SetFunctionTimerCondition("FrahtTimeLevelUp_Over", 0, 0, 30, false);
	break;
	
	case "Fraht_completeLevelUp":
	ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
	if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
	{
		iGoods = makeint(pchar.questTemp.WPU.Fraht.Goods);
		amount = sti(pchar.questTemp.WPU.Fraht.GoodsQty) - GetSquadronGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods));
		if (amount > 0)
		{
			dialog.text = "������ ��������? � ��� �� ��� ������������ ���������� ����������� ���� ������!";
			link.l1 = "����� ��������, �������� �����...";
			link.l1.go = "exit";
		}
		else
		{
			dialog.text = "���, �� ������ ���� �������� ���� " + GetGoodsNameAlt(iGoods)+ " � ���������� " + FindRussianQtyString(pchar.questTemp.WPU.Fraht.GoodsQty) + ". ������������! ��������� ���. �������� ���� ������ - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Fraht.Money))+".";
			link.l1 = "������� � ���� ��������, " + GetAddress_FormToNPC(NPChar) + "!";
			link.l1.go = "Fraht_completeLevelUp_1";
		}
	}
	else
	{
		dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� ����� - ����� � ���������.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
	}
	break;
	
	case "Fraht_completeLevelUp_1":
		pchar.quest.FrahtTimeLevelUp_Over.over = "yes";//����� ������
		AddQuestRecord("Fraht", "2");
		CloseQuestHeader("Fraht");
		RemoveCharacterGoods(pchar, sti(pchar.questTemp.WPU.Fraht.Goods), sti(pchar.questTemp.WPU.Fraht.GoodsQty));
		AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Fraht.Money));
		DeleteAttribute(pchar, "questTemp.WPU.Fraht.TargetPortmanID");
		DeleteAttribute(pchar, "questTemp.WPU.Current");
		DeleteAttribute(pchar, "questTemp.WPU.Fraht.LevelUp");
		pchar.questTemp.WPU.Fraht = "complete";
		AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
		AddCharacterExpToSkill(pchar, "Commerce", 200);//��������
		AddCharacterExpToSkill(pchar, "Leadership", 150);//���������
		AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		ChangeCharacterComplexReputation(pchar,"nobility", 2);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Fraht.Nation), 2);
		DialogExit();
	break;
	
//----------------------------------------������� 2 ������ ������ ------------------------------------------

	case "Escort_LevelUp":
		pchar.questTemp.WPU.Escort.LevelUp = "true";//��������� �������
		pchar.questTemp.WPU.Escort.StartCity = npchar.city;//����� ������������
		pchar.questTemp.WPU.Escort.Nation = npchar.nation;//����� ������������
		pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();//��������� �����
		while (pchar.questTemp.WPU.Escort.EnemyNation == PIRATE)
		{
			pchar.questTemp.WPU.Escort.EnemyNation = GetEnemyNationToMainCharacter();
		}
		switch (drand(2))
		{
			case 0://����������� �� ����������� ��������
				pchar.questTemp.WPU.Current.TargetIslandID = DesIsland();//����� ����������
				while (!isLocationFreeForQuests(pchar.questTemp.WPU.Current.TargetIslandID)) pchar.questTemp.WPU.Current.TargetIslandID = DesIsland();
				pchar.questTemp.WPU.Escort.ShipType = Escort_ShipType();//����� �������
				pchar.questTemp.WPU.Escort.ShipName = GenerateRandomNameToShip(sti(pchar.nation));//��� �������
				pchar.questTemp.WPU.Escort.TargetPortmanID = pchar.questTemp.WPU.Escort.StartCity +"_portman";//�� ��������
				pchar.questTemp.WPU.Escort.ShipBaseName = GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.questTemp.WPU.Escort.ShipType), "Name") + "Gen"));
				dialog.text = "��� ���� ��������� ������ ���� �����... �������� �������, �������������� � ���� �������, ��� �������� ��������. ���������� ����� ������� ������� ���������, �� ������� �������� ���� ��������� ��� ���� � �������� ���� �����. � ���������� ��� ���� ������� � ������ �����, ����� ������\n"+pchar.questTemp.WPU.Escort.ShipBaseName+" '"+pchar.questTemp.WPU.Escort.ShipName+"' ��������� ������, ��� ������ ��� � �������� �����������. ���������������� ������� ����� � ������ ������������ ������� "+XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID)+". � ����� ��� ����������� ����, ��������� ��������� ����� � �������� ��� � ��� ����. ���� �������� �������������� ��� ������. ������ ������ �������� ��������� ����� ���������� ������, �� ���� �������, ��� �� ����� ���������� �������.";
				link.l1 = "������� �� � ��������!";
				link.l1.go = "Escort_LevelUp_1";
				link.l2 = "�������, �� ��� ��� �� ��������. �������� ����������.";
				link.l2.go = "Escort_LevelUp_exit";
			break;
			case 1://�������� ������ ������ �������� ������� �� �������
				pchar.questTemp.WPU.Current.TargetIslandID = Islands[GetCharacterCurrentIsland(PChar)].id;//������� ������
				pchar.questTemp.WPU.Escort.TargetPortmanID = pchar.questTemp.WPU.Escort.StartCity +"_portman";//�� ��������
				dialog.text = "� ���� ������� ������ ��� ������� �������� �������. �� �� ����� ������� � ����� ������� ��� �������� �������� ��������. ��� ���� ����� �� �����, �������� ��������� � ���� �� ������ ������ ��� - �� ����� �� ����� ������ �������� � ���� ������. �� �������� �������, ����� ��� - ���������� � ��� ��������, �������� ������������ � ��������! �� �������� ���?";
				link.l1 = "������� ��! ��� ���� �����!";
				link.l1.go = "Escort_LevelUp_2";
				link.l2 = "�������, �� ��� ��� �� ��������. �������� ����������.";
				link.l2.go = "Escort_LevelUp_exit";
			break;
			case 2://��������� � �������
				pchar.questTemp.WPU.Escort.ShipName = GenerateRandomNameToShip(sti(pchar.nation));
				pchar.questTemp.WPU.Escort.ShipType = Escort_ShipType();
				pchar.questTemp.WPU.Escort.City = findCurrentCity1(npchar);//�����, ������ �������
				pchar.questTemp.WPU.Escort.TargetPortmanID = pchar.questTemp.WPU.Escort.City +"_portman";//�� ��������
				sld = characterFromId(pchar.questTemp.WPU.Escort.TargetPortmanID);
				pchar.questTemp.WPU.Escort.Nation = sld.nation;//����� ����������
				pchar.questTemp.WPU.Current.TargetIslandID = GetCharacterCurrentIslandId(npchar);//�� �������� ������
				pchar.questTemp.WPU.Escort.DaysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.questTemp.WPU.Escort.StartCity), GetArealByCityName(pchar.questTemp.WPU.Escort.City));//���������� � ����
				pchar.questTemp.WPU.Escort.Money = sti(pchar.questTemp.WPU.Escort.DaysQty)*2000+20000;
				pchar.questTemp.WPU.Escort.Chance = rand(1);
				dialog.text = "� ������� "+XI_ConvertString(pchar.questTemp.WPU.Escort.City)+" ������� ����� � ������� � ������������ ��� ����� �������. ����� ������������� ���� �� ���������� ����, �������� ����� ������� ����������� � ����� � ���� ������ ��� �� �����. �� �� ����� ��������� ���� ���������, ��������� ������� � ��������� � ��������\n� ��������� ��� ����������� ��� ������ �� ����� �������. ������ �� ������ ����������� � ������� "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money))+".";
				link.l1 = "������� �� � ��������!";
				link.l1.go = "Escort_LevelUp_0";
				link.l2 = "�������, �� ��� ��� �� ��������. �������� ����������.";
				link.l2.go = "Escort_LevelUp_exit";
			break;
		}
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LevelUp_exit":
		dialog.text = "����, ����� ����. � � ��� �� ��� ��������...";
		link.l1 = "��� ���� ����. �� ��������, " + GetAddress_FormToNPC(NPChar) + ".";
		link.l1.go = "exit";
		pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)-1;//������� �������
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
	break;
	
	case "Escort_LevelUp_0":
		dialog.text = "������������! � ����, ��� ���� �� ��� ������������. ������������ �� ������������� - �����, "+FindRussianDaysString(pchar.questTemp.WPU.Escort.DaysQty)+" ����� ������ ����������, ����� ��������� �� "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.City+"Gen")+". ���, �������� ��� ����������� ������� ��� ������������� ����� ��������. ��������� �����, �������!";
		link.l1 = "�������! �� ������������, � ��� �� �������.";
		link.l1.go = "Escort_LevelUp_0_go";
	break;
	
	case "Escort_LevelUp_0_go":
		ReOpenQuestHeader("Escort");
		AddQuestRecord("Escort", "19");
		AddQuestUserData("Escort", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money)));
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.City));
		AddQuestUserData("Escort", "sDay", FindRussianDaysString(pchar.questTemp.WPU.Escort.DaysQty));
		SetFunctionTimerCondition("EscortArsenalShip_Over", 0, 0, sti(pchar.questTemp.WPU.Escort.DaysQty)+1, false);
		DialogExit();
		pchar.questTemp.WPU.Escort = "begin";
		pchar.questTemp.WPU.Escort.LevelUp_0 = "true";
		pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)+1;
	break;
	
	case "Escort_LUGo_0":
	ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
	if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
	{
		pchar.quest.EscortArsenalShip_Over.over = "yes";
		dialog.text = "�� �������-��! ��� ���� ������� ��� ��� ����� ���������. ���������� ������������. ����� ���������� "+pchar.questTemp.WPU.Escort.ShipName+", ��� ������� ����� ���������� ������� � ����� ��������.";
		link.l1 = "�������. ����� ������� ���� ������� � �������� - � ������� ����������� � ���� ��� ����� �������.";
		link.l1.go = "Escort_LUGo_01";
	}
	else
	{
		dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� �����, ����� � ���������.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
	}
	break;
	
	case "Escort_LUGo_01"://��������� ����������
		int iShipType = sti(pchar.questTemp.WPU.Escort.ShipType);
		sTemp = pchar.questTemp.WPU.Escort.ShipName;
		sld = GetCharacter(NPC_GenerateCharacter("ArsenalShipCaptain", "citiz_41", "man", "man", 15, sti(pchar.nation), -1, true, "quest"));
		FantomMakeSmallSailor(sld, iShipType, sTemp, CANNON_TYPE_CANNON_LBS16, 65, 22, 24, 35, 33);
		SetFantomParamFromRank(sld, 15, true); 
		SetCaptanModelByEncType(sld, "war");
		SetCharacterGoods(sld, GOOD_FOOD, 500);
		SetCharacterGoods(sld, GOOD_BALLS, 5000);
		SetCharacterGoods(sld, GOOD_GRAPES, 3000);
		SetCharacterGoods(sld, GOOD_KNIPPELS, 3000);
		SetCharacterGoods(sld, GOOD_BOMBS, 5000);
		SetCharacterGoods(sld, GOOD_POWDER, 10000);
		SetCharacterGoods(sld, GOOD_WEAPON, 3000);
		sld.CompanionEnemyEnable = false; //������ ������
		SetCompanionIndex(pchar, -1, sti(sld.index));
		SetCharacterRemovable(sld, false);
		sld.loyality = MAX_LOYALITY;
		sld.Dialog.Filename = "Common_portman.c";
		sld.dialog.currentnode = "Escort_companion";
		DialogExit();
		AddQuestRecord("Escort", "20");
		AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
		pchar.quest.Escort_fail.win_condition.l1 = "NPC_Death";//���������� �� ���������� ���������������
		pchar.quest.Escort_fail.win_condition.l1.character = "ArsenalShipCaptain";
		pchar.quest.Escort_fail.function = "EscortArsenalShip_failed";
		SetFunctionTimerCondition("EscortArsenalShipGo_Over", 0, 0, sti(pchar.questTemp.WPU.Escort.DaysQty)+6, false);
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_0");
		pchar.questTemp.WPU.Escort.LevelUpGo_0 = "true";
		if (sti(pchar.questTemp.WPU.Escort.Chance) == 0) EnemyNationHunterOnMap(true);//���������� �����������
		else FrahtHunterOnSea();
	break;
	
	case "Escort_LUGo_complete":
	ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
	if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
	{
		pchar.quest.Escort_fail.over = "yes";
		pchar.quest.EscortArsenalShipGo_Over.over = "yes";
		dialog.text = "�������! �� ��� � ������� ��� �����������, ��� �� ��� ����� ����������. ������� �� ����������� ������. �������� ���� �������������� - "+FindRussianMoneyString(sti(pchar.questTemp.WPU.Escort.Money))+". �� ��������� ������������ �������� ���� - ������ ��� ������ ��������, ��� ��, ���� ����������� ������.";
		link.l1 = "������� ��� �������, " + GetAddress_FormToNPC(NPChar) + "! ����������, �� ����� ������������ � ������. ����� �������!";
		link.l1.go = "Escort_LUGo_complete_1";
	}
	else
	{
		dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� �����, ����� � ���������.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
	}
	break;
	
	case "Escort_LUGo_complete_1":
		RemoveCharacterCompanion(Pchar, characterFromID("ArsenalShipCaptain"));
		sld = characterFromId("ArsenalShipCaptain");
		sld.lifeday = 0;//�� ������ ������
		AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.Money));
		ChangeCharacterComplexReputation(pchar,"nobility", 2);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), 2);
		AddQuestRecord("Escort", "24");
		AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
		CloseQuestHeader("Escort");
		DialogExit();
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUpGo_0");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		AddComplexSeaExpToScill(100, 100, 100, 0, 100, 0, 0);
		AddComplexSelfExpToScill(30, 30, 30, 30);
		AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LevelUp_1":
		dialog.text = "����� � ������� ��� ����������� ����. � �� ����������� � ��������, ����� ���! ��������, ������ � ����� ����� ��������� � ����������� ������.";
		link.l1 = "� �����. ����������� � ���� ������� ��!";
		link.l1.go = "Escort_LevelUp_1_select";
	break;
	
	case "Escort_LevelUp_1_select"://������� �����������
		switch (rand(2))
		{
			case 0://���� ������� � ������� ��� �����
				pchar.quest.DisasterShip_WM.win_condition.l1 = "location";
				pchar.quest.DisasterShip_WM.win_condition.l1.location = pchar.questTemp.WPU.Current.TargetIslandID;
				pchar.quest.DisasterShip_WM.function = "CreateDisasterShip_WithoutMasts";
				pchar.questTemp.WPU.Escort.LevelUp_1WM = "true";
			break;
			case 1://����� ��� � ���������� � ������
				pchar.quest.DisasterShip_VSP.win_condition.l1 = "location";
				pchar.quest.DisasterShip_VSP.win_condition.l1.location = pchar.questTemp.WPU.Current.TargetIslandID;
				pchar.quest.DisasterShip_VSP.function = "CreateDisasterShip_VSPirate";
				for (i=0; i<MAX_ISLANDS; i++)//������� �����
				{				
					if (Islands[i].id == pchar.questTemp.WPU.Current.TargetIslandID)
					{
					Islands[i].alwaysStorm = true; 
					Islands[i].storm = true;
					Islands[i].tornado = true; 
					}
				}
				pchar.questTemp.WPU.Escort.LevelUp_1VSP = "true";
			break;
			case 2://�������
				pchar.questTemp.WPU.Current.TargetIslandID.Shore = SelectQuestShoreLocationFromSea(pchar.questTemp.WPU.Current.TargetIslandID);
				pchar.quest.DisasterShip_S.win_condition.l1 = "location";
				pchar.quest.DisasterShip_S.win_condition.l1.location = pchar.questTemp.WPU.Current.TargetIslandID.Shore;
				pchar.quest.DisasterShip_S.function = "CreateDisasterShip_Crew";
				pchar.questTemp.WPU.Escort.LevelUp_1S = "true";
			break;
		}
		ReOpenQuestHeader("Escort");
		AddQuestRecord("Escort", "25");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sIsland", XI_ConvertString(pchar.questTemp.WPU.Current.TargetIslandID));
		AddQuestUserData("Escort", "sSName", pchar.questTemp.WPU.Escort.ShipName);
		AddQuestUserData("Escort", "sTargetColony",XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.City));
		SetFunctionTimerCondition("DesIsland_Over", 0, 0, 15, false);
		DialogExit();
		pchar.questTemp.WPU.Escort = "begin";
		pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)+1;
	break;
	
	case "Escort_LU1WM_complete":
	ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
	if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
	{
		dialog.text = "��, ��� ��� ��������. ������������ ������, " + GetAddress_Form(NPChar) + "! �� ��� � ������� ��� �����������, ��� �� ��� ����� ����������. �������� ���� �������������� - 30 000 ����\n�� ��������� ������������ ����������� �� ��� - ����� ���� ��� ��, �� ����� ����� ��������� ������������, � � ���� ����������� �������� ��� ��� ������.";
		link.l1 = "������� ��� �������, " + GetAddress_FormToNPC(NPChar) + "! ����������, �� ����� ������������ � ������. ����� �������!";
		link.l1.go = "Escort_LU1WM_complete_1";
	}
	else
	{
		dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� �����, ����� � ���������.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
	}
	break;
	
	case "Escort_LU1WM_complete_1":
		sld = characterFromId("WMCaptain");
		sld.lifeday = 0;
		DialogExit();
		AddMoneyToCharacter(pchar, 30000);
		ChangeCharacterComplexReputation(pchar,"nobility", 5);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), 5);
		AddQuestRecord("Escort", "32");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sMoney", 30000);
		CloseQuestHeader("Escort");
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1WM");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		AddCharacterExpToSkill(pchar, "Sailing", 100);//���������
		AddCharacterExpToSkill(pchar, "Repair", 300);//�������
		AddCharacterExpToSkill(pchar, "Commerce", 100);//��������
		AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
		AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LU1VSP_complete":
	ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
	if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)//�������� �� ������� ������� � �����
	{
		dialog.text = "��, �� ��� ��� ��� ��������� - ��� �� ���������� �������� ��� ����� � ��� � ��������. �������� ������, " + GetAddress_Form(NPChar) + "! �� ��� � ������� ��� �����������, ��� �� ��� ����� ����������. �������� ���� �������������� - 50 000 ����\n�� ��������� ������������ ����������� �� ��� - ����� ���� ��� ��, �� ����� ����� ��������� ������������, � � ���� ����������� �������� ��� ��� ������.";
		link.l1 = "������� ��� �������, " + GetAddress_FormToNPC(NPChar) + "! ����������, �� ����� ������������ � ������. ����� �������!";
		link.l1.go = "Escort_LU1VSP_complete_1";
	}
	else
	{
		dialog.text = "���-�� � �� ���� � ����� ������ �������. �������� �� ���� � ��������� �� ��� �����, ����� � ���������.";
		link.l1 = "������, � ��� � ������.";
		link.l1.go = "exit";
	}
	break;
	
	case "Escort_LU1VSP_complete_1":
		sld = characterFromId("WMCaptain");
		sld.lifeday = 0;
		DialogExit();
		AddMoneyToCharacter(pchar, 50000);
		ChangeCharacterComplexReputation(pchar,"nobility", 10);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), 6);
		AddQuestRecord("Escort", "32");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sMoney", 50000);
		CloseQuestHeader("Escort");
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1VSP");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		AddComplexSeaExpToScill(100, 150, 150, 100, 0, 0, 0);
		AddComplexSelfExpToScill(50, 50, 50, 50);
		AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
		AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LU1VSP_completeSink":
		dialog.text = "����� ����������� �����... ������, �������, �� ����.";
		link.l1 = "� ������ ���, ��� ���� � ���� �����, " + GetAddress_FormToNPC(NPChar) + ". �������� ��������� ��, ��� ��� �������� ����� � �����.";
		link.l1.go = "Escort_LU1VSP_completeSink_1";
	break;
	
	case "Escort_LU1VSP_completeSink_1":
		dialog.text = "� ����, " + GetAddress_Form(NPChar) + ", ��� �� ����������� ��� ���������, ����� ������ ������� � ���������� �������. ���... �������� ���� �������������� - 10 000 ����, � ������� �� ������.";
		link.l1 = "�� �� ���, " + GetAddress_FormToNPC(NPChar) + ". ��� ���� ����� ����. �� ��������.";
		link.l1.go = "Escort_LU1VSP_completeSink_2";
	break;
	
	case "Escort_LU1VSP_completeSink_2":
		DialogExit();
		AddMoneyToCharacter(pchar, 10000);
		ChangeCharacterComplexReputation(pchar,"nobility", 1);
		AddQuestRecord("Escort", "32");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sMoney", 10000);
		CloseQuestHeader("Escort");
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1VSP");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		AddComplexSeaExpToScill(50, 50, 50, 50, 0, 0, 0);
		AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LU1S_complete":
		dialog.text = "��, �� ��� ��� ��� ��������� - ��� �� ���������� ��������� � ������������ ����������, � ����� � ��������� ��������. �������� ������, " + GetAddress_Form(NPChar) + "! �� ��� � ������� ��� �����������, ��� �� ��� ����� ����������\n�������� ���� �������������� - 40 000 ����. �� ��������� ������������ ����������� �� ��� - ����� ���� ��� ��, �� ����� ����� ��������� ������������, � � ���� ����������� �������� ��� ��� ������.";
		link.l1 = "������� ��� �������, " + GetAddress_FormToNPC(NPChar) + "! ����������, �� ����� ������������ � ������. ����� �������!";
		link.l1.go = "Escort_LU1S_complete_1";
	break;
	
	case "Escort_LU1S_complete_1":
		sld = characterFromId("WMCaptain");
		sld.lifeday = 0;
		DialogExit();
		AddMoneyToCharacter(pchar, 40000);
		ChangeCharacterComplexReputation(pchar,"nobility", 8);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), 3);
		AddQuestRecord("Escort", "32");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sMoney", 40000);
		CloseQuestHeader("Escort");
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_1S");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		AddComplexSeaExpToScill(100, 150, 150, 100, 0, 0, 0);
		AddComplexSelfExpToScill(100, 100, 100, 100);
		AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
		AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
	case "Escort_LevelUp_2":
		dialog.text = "� ����, ��� ���� �� ��� ������������. �����, �������! ��� ������� ������ ��� ������!";
		link.l1 = "���������� ��������� ���� �������. ������ � ����, � �� ������� ��� ���!";
		link.l1.go = "Escort_LevelUp_2_go";
	break;
	
	case "Escort_LevelUp_2_go":
		ReOpenQuestHeader("Escort");
		AddQuestRecord("Escort", "41");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		SetFunctionTimerCondition("CaravanNearIsland_Over", 0, 0, 2, false);
		pchar.questTemp.WPU.Escort.count = sti(pchar.questTemp.WPU.Escort.count)+1;
		pchar.quest.CaravanNearIsland_Start.win_condition.l1 = "location";
		pchar.quest.CaravanNearIsland_Start.win_condition.l1.location = pchar.questTemp.WPU.Current.TargetIslandID;
		pchar.quest.CaravanNearIsland_Start.function = "CreateCaravanNearIsland";
		pchar.questTemp.WPU.Escort.LevelUp_2 = "true";
		pchar.questTemp.WPU.Escort = "begin";
		DialogExit();
	break;
	
	case "Escort_LU2_complete":
		switch (sti(pchar.questTemp.WPU.Escort.LevelUp_2.Qty))
		{
			case 1:
				pchar.questTemp.WPU.Escort.LevelUp_2.Money = 10000;
				dialog.text = "��, ���� ����� �������� �� ���������. ���� ������, �������, ����� ����. �� ���� ������� �� ��� �� ������. ������� ������� � 10 000 ���� ���� ������ ���������. �������� ��� ������ � ������� ������� �� ��������� ������.";
				link.l1 = "�� �� ���... �������, ��� ��� ������ �� ������ �������, �� � ������ ���, ��� ���. �� ��������, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "Escort_LU2_complete_1";
			break;
			case 2:
				pchar.questTemp.WPU.Escort.LevelUp_2.Money = 25000;
				dialog.text = "��, ���� ����� �������� �� ���������. �� ����� �������� ���� ���. ���� ��������� �����, �������, ����� ����. �� ���� �� �� ��, ����� �� ��� ��� �� �� ���� �����. ������� ������� � 25 000 ���� ���� ��������� ���������. �������� ��� ������ � ������� ������� �� ��������� ������.";
				link.l1 = "��������� �� ������� ������ ���� ��������, �� � �� ������, ��� ������ �������� ������ - ���� ������� �������. �� ��� ��... ������ ������. �� ��������, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "Escort_LU2_complete_1";
			break;
			case 3:
				pchar.questTemp.WPU.Escort.LevelUp_2.Money = 50000;
				dialog.text = "��, ���� ����� �������� �� ���������. �� ���� �����������! ��� ���� �� ���������� ������� ������� �������! ��� ��������� �� ����� �����, ������ ��� - ������������� �������� �������� �������, � �� ������������ ��������. ����, ��� ����� �� ��� �� ����������... ���� �������������� ���������� 50 000 ���� - ��������, ����������.";
				link.l1 = "��������� �� ������� ������ ���� ��������! ������ ��� ������. � ������, " + GetAddress_FormToNPC(NPChar) + " ��������� �����������.";
				link.l1.go = "Escort_LU2_complete_1";
			break;
		}
	break;
	
	case "Escort_LU2_complete_1":
		iTemp = sti(pchar.questTemp.WPU.Escort.LevelUp_2.Qty);
		DialogExit();
		Group_DeleteGroup("CaravanShip");
		AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Escort.LevelUp_2.Money));
		ChangeCharacterComplexReputation(pchar,"nobility", iTemp*2);
		ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Escort.Nation), iTemp);
		AddQuestRecord("Escort", "32");
		AddQuestUserData("Escort", "sStartCity", XI_ConvertString("Colony"+pchar.questTemp.WPU.Escort.StartCity+"Gen"));
		AddQuestUserData("Escort", "sMoney", sti(pchar.questTemp.WPU.Escort.LevelUp_2.Money));
		CloseQuestHeader("Escort");
		AddCharacterExpToSkill(pchar, "Sailing", iTemp*35);//���������
		AddCharacterExpToSkill(pchar, "Accuracy", iTemp*50);//��������
		AddCharacterExpToSkill(pchar, "Cannons", iTemp*50);//������
		AddCharacterExpToSkill(pchar, "Grappling", iTemp*35);//�������
		AddCharacterExpToSkill(pchar, "Leadership", iTemp*40);//���������
		AddCharacterExpToSkill(pchar, "Fortune", iTemp*35);//�������
		AddCharacterExpToSkill(pchar, "FencingLight", iTemp*35);//������ ������
		AddCharacterExpToSkill(pchar, "Fencing", iTemp*35);//������� ������
		AddCharacterExpToSkill(pchar, "FencingHeavy", iTemp*35);//������� ������
		AddCharacterExpToSkill(pchar, "Pistol", iTemp*35); //�������
		pchar.questTemp.WPU.Escort = "complete";
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp_2");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.LevelUp");
		DeleteAttribute(pchar, "questTemp.WPU.Escort.TargetPortmanID");
		SaveCurrentNpcQuestDateParam(npchar, "work_date");
	break;
	
		case "PortmanQuest_NF":
			dialog.text = "��, ��� �����. � ����� ������, �� � ����� ����� ������ � ���� �� ����� ���� � ����.";
			link.l1 = "�������. ��� ��� ��� �����"+ GetSexPhrase("","�") +" �������...";
			link.l1.go = "node_2";
		break;
		
		//��������� �����
		case "BurntShip2":
			dialog.text = "����� ����, �������... ����� ����, ��� �� �� ������ ��� ������.";
			link.l1 = "��� �� � ������� ����, ���������. �� �� ���� ���������... �� ��������...";
			link.l1.go = "exit";
			NPChar.Quest.BurntShip.LastQuestDate = sLastSpeakDate;
		break;
		
		case "BurntShip4":
			dialog.text = "�� ��� ��, �������?! ��������� ����!.. ��� �����?! � ��� ���� ����� ����, ��� ������� ��� �����. � ��������� �������� ����, � ��������� ������� ������� ������ ����������, � ����� ��������� �������, ������ ���.";
			link.l1 = "���������, ��� � ��� �� ���� ��������? �� ������ ���������� �����-������, � ���������� ����, �  ��� ���������� � ���� �� ����������?";
			link.l1.go = "BurntShip5";
		break;
		
		case "BurntShip5":
			sCapitainId = GenerateRandomName(sti(NPChar.nation), "man");
			
			dialog.text = "�� �� ���� �� ����, ���� �� ����, - ������� �������, ����� �� �� ������� ��� ������. ��������� ���� ���, ��� ���� ���� ���, ����� ���� �������, ��������� ���� �����!\n" +
				"� ��� �������� � ���, ��� �����-�� �����������... ������ ������������, ���������� �� ��� ������ ��������� " + sCapitainId + ". � ��������� ��� � ������ �� ����������, � ������������� ����������������. " +
				"� ���� ������ �������� ����� �������� � ��������� ��� �� ������, ������ ������, ������ �������... ��� � ������ ��� �����? ���� � ����� ����, ��-����...";
			link.l1 = "�-�, ����, �� ������� ������. � ��� � ���� �� ��� ����, ��� � ���� �����? �� ����, ��� � ���� ��������� ���� �������� ��� ��������?";
			link.l1.go = "BurntShip6";
			
			NPChar.Quest.BurntShip.ShipOwnerName = sCapitainId;
		break;
		
		case "BurntShip6":
			BurntShipQuest_FillStartParams(NPChar);
			
			attrL = NPChar.Quest.BurntShip.ShipAttribute;
			iTest = sti(NPChar.Quest.BurntShip.ShipType);
			
			switch(attrL)
			{
				case "speedrate":
					attrL = "� ��� " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].Name + "Acc")) + " �������� �� ����� ���� ����� " + NPChar.Quest.BurntShip.ShipNeededValue + " �����. ��� ������ ��� ��������� �������� ����... �� ������ ����� ����� ���������� �������� ���� �� ���! ׸�� ����� ��� � ���� ������ ������ � ��� ��������� ��������...";
				break;
				
				case "turnrate":
					attrL = "� ��� " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].Name + "Acc")) + " ������������ ���� ����� " + NPChar.Quest.BurntShip.ShipNeededValue + " ������. ��� ��� ����� ��������� �������� ����... �� ����� ������ ���� ������������! ׸�� ��� �������� �������� � ���� ���� ��������...";
				break;
				
				case "capacity":
					attrL = "� ��� " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].Name + "Acc")) + " ������� ��� ����� " + NPChar.Quest.BurntShip.ShipNeededValue + " ������ �������������. ��� ����� ��� ��������� �������� ����... �� ���� ��� ���� ����������. ׸�� ��� ����� ������ � ���� ��� ������ ��������!";
				break;
			}
			
			dialog.text = attrL;
			link.l1 = "� ��� �� ����� �������? ������� ����� ����� ��������� ����������?";
			link.l1.go = "BurntShip7";
		break;
		
		case "BurntShip7":
			dialog.text = "����� �� ������. � �� � �� �������� ������ ����� � ��������. �������, ��� � ��������� ������ ���� �������. �� ��� ��, - � ��� ���� ������. �������� ������ �� ������ ����� ��������� ���������, ��� �� ������������. ���� �� ������ ��� ������� ���������. ����� ��� �� �������� ����� ��������� �������� �������� ��� ����. � �� ��� ����� ���������, ���������, ���� ������ �� � ��������� ���\n" +
				"� ����� �����������, � ��������� �������� �� ����������. ����-�� ������������, ���� ���������. ���� ����� � ��������� � ������ ������������ ��������� �������?";
			link.l1 = "��, ���� �� �������. � ������� � ���� ���� �������?";
			link.l1.go = "BurntShip8";
			link.l2 = "���, ��������, �� �������� � �� ���. �� � �������� ����� �� ����, ��� ����� � ��������� ���������������� ����������. �� ��������...";
			link.l2.go = "BurntShip2";
		break;
		
		case "BurntShip8":
			dialog.text = "�����, ����� ����, ����. ������ ����� � ������ � ����� �������� �� ��������.";
			link.l1 = "��� �, ������. �������� � ��� �������� �����. �� ������, ���� ������ ��������� � ���������� - ����� ��� ����� � ��� �� ������!";
			link.l1.go = "BurntShip9";
		break;
		
		case "BurntShip9":
			dialog.text = "�� ��� ��, �������? ��� �����? � �� �������, ��� ��� �� ������� �� ������ ���� ��������, ��� ����� �����������... �� ������ ��������� �����, � �� �� ������������. ������ �������...";
			link.l1 = "�������... ����� ���� � �������� �������. �� ��������.";
			link.l1.go = "BurntShip9_exit";
		break;
		
		case "BurntShip9_exit":
			attrL = "BurntShipQuest_TimeIsOver_" + NPChar.Id;
			PChar.Quest.(attrL).win_condition.l1 = "Timer";
			PChar.Quest.(attrL).win_condition.l1.date.day = GetAddingDataDay(0, 6, 0);
			PChar.Quest.(attrL).win_condition.l1.date.month = GetAddingDataMonth(0, 6, 0);
			PChar.Quest.(attrL).win_condition.l1.date.year = GetAddingDataYear(0, 6, 0);
			PChar.Quest.(attrL).function = "BurntShipQuest_TimeIsOver";
			PChar.Quest.(attrL).PortmanId = NPChar.id;
			
			attrL = NPChar.Quest.BurntShip.ShipAttribute;
			
			iTest = sti(NPChar.Quest.BurntShip.ShipType);
			
			switch(attrL)
			{
				case "speedrate":
					attrL = "��������. � " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].name + "Gen")) + " �������� �� ����� ������ ���� �� ����� " + NPChar.Quest.BurntShip.ShipNeededValue;
				break;
				
				case "turnrate":
					attrL = "������������. � " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].name + "Gen")) + " ������������ ������ ���� �� ����� " + NPChar.Quest.BurntShip.ShipNeededValue;
				break;
				
				case "capacity":
					attrL = "�����. � " + GetStrSmallRegister(XI_ConvertString(ShipsTypes[iTest].name + "Gen")) + " ���� ������ ���� �� ����� " + NPChar.Quest.BurntShip.ShipNeededValue;
				break;
			}
			
			sTitle = "BurntShipQuest" + NPChar.location;
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "BurntShipQuest", "1");
			AddQuestUserDataForTitle(sTitle, "cityName", XI_ConvertString("Colony" + NPChar.city + "Dat"));
			AddQuestUserData(sTitle, "portmanName", GetFullName(NPChar));
			AddQuestUserData(sTitle, "cityName", XI_ConvertString("Colony" + NPChar.city + "Gen"));
			AddQuestUserData(sTitle, "text", attrL);
			
			NPChar.Quest.BurntShip.LastPortmanName = GetFullName(NPChar); // ������� ���
			
			DialogExit();
		break;
		
		// �������, ����� �� ��������� � �����
		case "BurntShip10":
			dialog.text = "� ��� �� ������ ����������?";
			link.l1 = "� ��� ������� ��������� ��������� ����������, �������� " + NPChar.Quest.BurntShip.LastPortmanName + "? � ���� � ���� ����.";
			link.l1.go = "BurntShip11";
		break;
		
		case "BurntShip11":
			dialog.text = "� ��� ���... �������������? �� ��� ����� ������ ���������� ��������� � ����������� ��������� �����. ���� ������ ����������� ��� � ����, �� ��� ����� � �������� � ������� � ������. ����� ����, �?..";
			link.l1 = "��, ��� �������� ��� �������. ��������, ��� ����...";
			link.l1.go = "BurntShip11_exit";
		break;
		
		case "BurntShip11_exit":
			AddCharacterExpToSkill(pchar, "Sailing", 100);
			AddCharacterExpToSkill(pchar, "Fortune", 100);
			sTitle = "BurntShipQuest" + NPChar.location;
			AddQuestRecordEx(sTitle, "BurntShipQuest", "2");
			AddQuestUserData(sTitle, "portmanName", NPChar.Quest.BurntShip.LastPortmanName);
			CloseQuestHeader(sTitle);
			
			DeleteAttribute(NPChar, "Quest.BurntShip");
			NPChar.Quest.BurntShip.LastQuestDate = sLastSpeakDate;
			
			DialogExit();
		break;
		
		// �� ���������� - ��������� �������
		case "BurntShip12":
			dialog.text = "� ��� �� ������ ����������?";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" ��� ����� � ������������ ���������������. ��� ���������� ��������������.";
			link.l1.go = "BurntShip14";
			link.l2 = "������, " + GetFullName(NPChar) + ", ����� ��� �� ���������� ���� � ���������� ���� ���������������. ������� � �������� �� ����� ���������. ��������, ���� ������"+ GetSexPhrase("","�") +"...";
			link.l2.go = "BurntShip13";
		break;
		
		case "BurntShip13":
			dialog.text = "����� ����, �������... ����� ����, ��� �� �� ������ ��� ������.";
			link.l1 = "��� �� � ������� ����, ���������. �� �� ���� ���������... �� ��������...";
			link.l1.go = "BurntShip13_exit";
		break;
		
		case "BurntShip13_exit":
			sTitle = "BurntShipQuest" + NPChar.location;
			CloseQuestHeader(sTitle);
			
			ChangeCharacterComplexReputation(pchar,"nobility", -5);
			DeleteAttribute(NPChar, "Quest.BurntShip");
			NPChar.Quest.BurntShip.LastQuestDate = sLastSpeakDate;
			
			DialogExit();
		break;
		
		case "BurntShip14":
			dialog.text = "��� ���! � ��� �� ���������� ���� ����� �����?";
			
			sTitle = NPChar.Quest.BurntShip.ShipAttribute;
			ok = (sFrom_sea == "") || (Pchar.location.from_sea == sFrom_sea);
			
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				for(i = 1; i < COMPANION_MAX; i++)
				{
					cn = GetCompanionIndex(PChar, i);
					
					if(cn > 0)
					{
						chref = GetCharacter(cn);
						
						sld = &RealShips[sti(chref.ship.type)];
						
						if(GetRemovable(chref) && sti(sld.basetype) == sti(NPchar.Quest.BurntShip.ShipType) &&
							stf(sld.(sTitle)) >= stf(NPChar.Quest.BurntShip.ShipNeededValue))
						{
							attrL = "l" + i;
							Link.(attrL) = chref.Ship.Name;
							Link.(attrL).go = "BurntShip15";
						}
					}
				}
			}
			
			link.l99 = "��������, � ����� �����.";
			link.l99.go = "exit";
		break;
		
		case "BurntShip15":
			AddCharacterExpToSkill(pchar, "Leadership", 100);
			AddCharacterExpToSkill(pchar, "Sailing", 100);
			AddCharacterExpToSkill(pchar, "Fortune", 100);
			dialog.text = "��, �������, � ���, ��� �� ������ � ���! ���"+ GetSexPhrase("��","��") +" �� ��-���� �������, ������ ������ ���� �� ������... � ��� ����� �������, ������� �� �������� ��� ����� ���. ������������, ������ ��, � ���������� ��������� ����� ����� �������... � �� ���� ��������� ����� � �������. ��, ������ ��������, �������� ���������, �����������, ����� ��, �� ��������...";
			link.l99 = "�� �� ������, ��� � ������"+ GetSexPhrase("","�") +", ���� �������� ���������� � ��������?";
			link.l99.go = "BurntShip16";
		break;
		
		case "BurntShip16":
			dialog.text = "���-���, ���� �����! � ��� ����� ������, �� ����������. ������, ����, ��� ��������� ��� ����� ��, ��� �������, ���������� �������, � ������� ��������� ����� � ����. �� �� ������� ���� ���������...";
			link.l1 = "� ��� �����, ����� ���� ����� ������ � ��� �������. �� �������.";
			link.l1.go = "BurntShip16_exit";
		break;
		
		case "BurntShip16_exit":
			sTitle = "BurntShipQuest" + NPChar.location;
			AddQuestRecordEx(sTitle, "BurntShipQuest", "3");
			
			NPChar.Quest.BurntShip.TwoDaysWait = true;
			SaveCurrentNpcQuestDateParam(NPChar, "Quest.BurntShip.TwoDaysWait"); // �������� ����
			
			sTitle = "BurntShipQuest" + NPChar.Id;
			PChar.Quest.(sTitle).over = "yes"; // ��������� ���������� �� �����
			
			DialogExit();
		break;
		
		case "BurntShip17":
			dialog.text = "� ��� �� ������ ����������?";
			link.l1 = "� ����"+ GetSexPhrase("��","��") +" �� ���������������. ������ ��� ����� ��-�������� � ����.";
			link.l1.go = "BurntShip18";
		break;
		
		case "BurntShip18":
			dialog.text = "���������, ����������, ��� ��������. � �� � ����� ������������ ������, ������ ��, ������ �� ��������.";
			
			sTitle = NPChar.Quest.BurntShip.ShipAttribute;
			ok = (sFrom_sea == "") || (Pchar.location.from_sea == sFrom_sea);
			
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				for(i = 1; i < COMPANION_MAX; i++)
				{
					cn = GetCompanionIndex(PChar, i);
					
					if(cn > 0)
					{
						chref = GetCharacter(cn);
						
						sld = &RealShips[sti(chref.ship.type)];
						
						if(GetRemovable(chref) && sti(sld.basetype) == sti(NPchar.Quest.BurntShip.ShipType) &&
							stf(sld.(sTitle)) >= stf(NPChar.Quest.BurntShip.ShipNeededValue))
						{
							attrL = "l" + i;
							Link.(attrL) = chref.Ship.Name;
							Link.(attrL).go = "BurntShip19_" + i;
						}
					}
				}
			}
			
			link.l99 = "��������, � ����� �����.";
			link.l99.go = "exit";
		break;
		
		case "BurntShip19":
			sld = &Characters[GetCompanionIndex(PChar, sti(NPChar.Quest.BurntShip.ShipCompanionIndex))];
			cn = GetShipSellPrice(sld, CharacterFromID(NPChar.city + "_shipyarder")) * 2;
			rRealShip = GetRealShip(GetCharacterShipType(sld));
			if (sti(rRealShip.Stolen)) cn *= 3;
			
			dialog.text = "��, �����������! � ����� ������ ���� ��������������, " + FindRussianMoneyString(cn) + ". ������ ��� ��������� ������� ������� ��������� �����. ��������� ��������� ���������� ��������� - �������� ����� ���, ��������.";
			link.l1 = "� ���, ����� ����� ���� �� �������. � ������"+ GetSexPhrase("","�") +", ��� ��� ����� ����� ������� ������.";
			link.l1.go = "BurntShip21";
			link.l2 = "��� ��� ������ ������ ����. � ���"+ GetSexPhrase("","�") +", ��� ����"+ GetSexPhrase("","��") +" ��� ������. �� �������.";
			link.l2.go = "BurntShip20_exit";
			NPChar.Quest.BurntShip.Money = cn;
		break;
		
		case "BurntShip20_exit":
			TakeNItems(pchar, "chest", makeint(sti(NPChar.Quest.BurntShip.Money)/12000));
			Log_Info("�� �������� ��������� �������");
			PlaySound("interface\important_item.wav");
			sTitle = "BurntShipQuest" + NPChar.location;
			AddQuestRecordEx(sTitle, "BurntShipQuest", "4");
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("","�"));
			AddQuestUserData(sTitle, "money", NPChar.Quest.BurntShip.Money);
			CloseQuestHeader(sTitle);
			
			ChangeCharacterComplexReputation(pchar,"nobility", 3);
			
			sld = &Characters[GetCompanionIndex(PChar, sti(NPChar.Quest.BurntShip.ShipCompanionIndex))];
			RemoveCharacterCompanion(PChar, sld);
			AddPassenger(PChar, sld, false);
			
			DeleteAttribute(NPChar, "Quest.BurntShip");
			NPChar.Quest.BurntShip.LastQuestDate = sLastSpeakDate;
			
			DialogExit();
		break;
		
		case "BurntShip21":
			dialog.text = "�� ��� ��, �������?! �������� ���, � ����, ��� ������. �� ����� ������ �� ����� �� ������ ��� �������� �����!";
			link.l1 = "����� � ������� ��� ����. �� ����� ��� ��� ������������... ��������.";
			link.l1.go = "BurntShip21_exit";
		break;
		
		case "BurntShip21_exit":
			ChangeCharacterComplexReputation(pchar,"nobility", -5);
			
			sTitle = "BurntShipQuest" + NPChar.location;
			AddQuestRecordEx(sTitle, "BurntShipQuest", "5");
			AddQuestUserData(sTitle, "sSex", GetSexPhrase("","�"));
			AddQuestUserData(sTitle, "money", NPChar.Quest.BurntShip.Money);
			CloseQuestHeader(sTitle);
			
			DeleteAttribute(NPChar, "Quest.BurntShip");
			NPChar.Quest.BurntShip.LastQuestDate = sLastSpeakDate;
			
			DialogExit();
		break;
		
		//--> ���������� ��������
		case "PortmanQuest":
			if (cRand(5) == 2)
			{	//����� ������� � �������� ������� ������
				dialog.text = "� ���� ����� ������� ������ ���� �������. ��� �� ���� ���� ����� �������!.. � �����, ����� ��� ������� � ������� �������.";
				link.l1 = "��, ��� �����... �� ��� ������ � ������!";
				link.l1.go = "PortmanQuest_1";
				link.l2 = "���, �� ���� ���� ����������. ��� ��� ��������, ����������...";
				link.l2.go = "node_2";
			}
			else
			{	//����� ��������� ���������� �������
				dialog.text = "� ���� �� ������� �������� ��� ������� �������. � ����, ����� �� ��������� � ������� ��� ���.";
				link.l1 = "��, �� ��� ��, � �����"+ GetSexPhrase("","�") +" ������� �� �������.";
				link.l1.go = "SeekShip_1";
				link.l2 = "��������, �� �������� �������� � �� ���������.";
				link.l2.go = "node_2";
			}
		break;
//-------------------------------- ����� �������� �������� ������� �� ���������� ���� ---------------------
		case "PortmanQuest_1":
			dialog.text = "�������, ��� ��� ������... ��-�, ����� ���� � ���� �����! ������ �������� ������� - ����� ����������, ��������� � �� ����� ���������.";
			link.l1 = "��� �����, ���������� �����! ��, � ������ ���������� ��� ��������� �� ���� ���������� ��������.";
			link.l1.go = "PortmanQuest_2";
			pchar.questTemp.different = "PortmansJornal";
			SetTimerFunction("SmallQuests_free", 0, 0, 1); //����������� ���������� �� ����������
			SetJornalCapParam(npchar);
			GiveItem2Character(pchar, "PortmansBook");
			pchar.questTemp.PortmansJornal.gem = GenQuestPortman_GenerateGem();
		break;
		case "PortmanQuest_2":
			dialog.text = "��, �������! ��� ����� " + npchar.quest.PortmansJornal.capName + ", �� ������� " + GetStrSmallRegister(XI_ConvertString(npchar.quest.PortmansJornal.shipTapeName + "Gen")) + " � ������ '" + npchar.quest.PortmansJornal.shipName + "'. ����� �� � ���� �������, � ���������� � " + XI_ConvertString("Colony" + npchar.quest.PortmansJornal.city + "Acc") + ".";
			link.l1 = "�������. �� ��� ��, � ��� ����������� �����. ��� ���� � �������?";
			link.l1.go = "PortmanQuest_3";
		break;
		case "PortmanQuest_3":
			dialog.text = npchar.quest.PortmansJornal.capName + " ��� � ���� ������������, ��� � ��� ���������. ������ ������������ ����� ��� �������, � ��� ����� ���������.";
			link.l1 = "����. ��, � ���"+ GetSexPhrase("��","��") +"...";
			link.l1.go = "exit";
			sTitle = npchar.id + "PortmansBook_Delivery";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "PortmansBook_Delivery", "1");
			AddQuestUserDataForTitle(sTitle, "sCapName", npchar.quest.PortmansJornal.capName);
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.PortmansJornal.shipTapeName + "Gen")));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.PortmansJornal.shipName);
			AddQuestUserData(sTitle, "sCapName", npchar.quest.PortmansJornal.capName);
			AddQuestUserData(sTitle, "sCapName2", npchar.quest.PortmansJornal.capName);
			AddQuestUserData(sTitle, "sTargetCity", XI_ConvertString("Colony" + npchar.quest.PortmansJornal.city + "Acc"));
			if (GetIslandByCityName(npchar.quest.PortmansJornal.city) != npchar.quest.PortmansJornal.city)
			{
				AddQuestUserData(sTitle, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(npchar.quest.PortmansJornal.city) + "Dat"));
			}			
		break;
		// -------------------------------- ����� ������� ����������� ������� ----------------------------------
		case "SeekShip_1":
			dialog.text = "���������! �� ������, ���������� ������� ����������� �� ���������� ��������, ��� ��� �� ����� ����� ��� ����. � ������� ������� �� ������...";
			link.l1 = "�������. ���������� ���������, ��� �� �������, ��� ����� ��������������� ��� �������.";
			link.l1.go = "SeekShip_2";
			pchar.questTemp.different = "PortmansSeekShip";
			SetTimerFunction("SmallQuests_free", 0, 0, 1); //����������� ���������� �� ����������
			SetSeekShipCapParam(npchar);
		break;
		case "SeekShip_2":
			dialog.text = XI_ConvertString(npchar.quest.PortmansSeekShip.shipTapeName) + " � ������ '" + npchar.quest.PortmansSeekShip.shipName + "'. ������� ��� ����� " + FindRussianDaysString(rand(5)+10) + " �����. ��������� ����.";
			link.l1 = "��, ��� ��� ������ ����, ������, ��������. � �����, � ������� ������ �������� �� ����������...";
			link.l1.go = "SeekShip_3";
		break;
		case "SeekShip_3":
			dialog.text = "��, �����. �� � ������ ��� ����� ������ ��������� �� ����. ������� ���� � �������, �� �������� ������� � �����, � ��� �� ������ ��, ��� ��� �����.";
			link.l1 = "�������. �� ��� ��, ��������� � �������. �������, ��� �������.";
			link.l1.go = "exit";
			sTitle = npchar.id + "Portmans_SeekShip";
			ReOpenQuestHeader(sTitle);
			AddQuestRecordEx(sTitle, "Portmans_SeekShip", "1");
			AddQuestUserDataForTitle(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(sTitle, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(npchar.quest.PortmansSeekShip.shipTapeName)));
			AddQuestUserData(sTitle, "sShipName", npchar.quest.PortmansSeekShip.shipName);
		break;

		case "SeekShip_break":
			dialog.text = "��, �� ��� ��, ����� ����. ����, �� ����� ������ ���� ������������...";
			link.l1 = "��, ������� ����� ������� ������ � ������� �����.";
			link.l1.go = "SeekShip_break_1";
		break;
		case "SeekShip_break_1":
			dialog.text = "�� ��� ��, ������� �� ��������� ������, ���� ��� � �� ���������� �������.";
			link.l1 = "�� �� ���...";
			link.l1.go = "exit";
			sTemp = "SeekShip_checkAbordage" + npchar.index;
			pchar.quest.(sTemp).over = "yes"; //������� ���������� �� �������
			cn = GetCharacterIndex("SeekCap_" + npchar.index);
			//���� ���-��� ��� ��� - ������� ���
			if (cn > 0)
			{
				characters[cn].LifeDay = 0; 
				Map_ReleaseQuestEncounter(characters[cn].id);
				group_DeleteGroup("SeekCapShip_" + characters[cn].index);
			}
			sTitle = npchar.id + "Portmans_SeekShip";
			AddQuestRecordEx(sTitle, "Portmans_SeekShip", "7");
			CloseQuestHeader(sTitle);
			DeleteAttribute(npchar, "quest.PortmansSeekShip");
			npchar.quest = ""; //����������� ������ ���� ������ ��� ��������
			ChangeCharacterComplexReputation(pchar,"nobility", -7);
		break;	

		case "SeekShip_good":
			if (npchar.quest == "SeekShip_sink")
			{
				dialog.text = "�������! ������, �������, ��� ��� �� ������ ��� �������, ��� ��� �������... ����, ����������, ��� �����! � ���� ��� � ���.";
				link.l1 = "��, �������������...";
				//npchar.quest.money = makeint(sti(npchar.quest.money) / 4); //������� ������
				ChangeCharacterComplexReputation(pchar,"nobility", 5);
				ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 10);
                AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 10);
                AddCharacterExpToSkill(GetMainCharacter(), "Sailing", 10);
                AddCharacterExpToSkill(GetMainCharacter(), "Commerce", 50);
                AddCharacterExpToSkill(GetMainCharacter(), "Cannons", 20);
			}
			else
			{
				dialog.text = "�����������! �� ��� ����� �������. �����������, ��������� ��� ���� ������.";
				link.l1 = "��, �������������...";
				ChangeCharacterComplexReputation(pchar,"nobility", 10);
				ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
                AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 100);
                AddCharacterExpToSkill(GetMainCharacter(), "Sailing", 150);
                AddCharacterExpToSkill(GetMainCharacter(), "Grappling", 100);
			}
			link.l1.go = "SeekShip_good_1";
		break;
		case "SeekShip_good_1":
			dialog.text = "� ����� ��������� ��� ��������������. ��� ���������� " + FindRussianMoneyString(makeint(sti(npchar.quest.chest)*15000)) + " � ��������. ������ � ��������� �� ����, � ���������.";
			link.l1 = "�� ��� ��, ����� ���� ����������. ������� � ����� ��������.";
			link.l1.go = "exit";
			TakeNItems(pchar, "chest", sti(npchar.quest.chest));
			sTitle = npchar.id + "Portmans_SeekShip";
			AddQuestRecordEx(sTitle, "Portmans_SeekShip", "6");
			CloseQuestHeader(sTitle);
			DeleteAttribute(npchar, "quest.PortmansSeekShip");
			npchar.quest = ""; //����������� ������ ���� ������ ��� ��������
		break;

		//------------------------------> ���� �� ���� �������� �����
		//��������. � �������� ������ ��������� ������� ������ �� �������   PortmansBook_Delivery  #TEXT   5
		//� ������ �������� ������� �����, ��������� � ����� ������ �� quest_text.txt
		//������: � ����� ������  void SetCapitainFromCityToSea(string qName)
		case "CapitainList":
			if (sti(npchar.quest.qty) > 0)
			{
				dialog.text = "���� ������������ ��������. ��� ��������� ��� ����������?";
				makearef(arCapBase, npchar.quest.capitainsList); 
				for (i=0; i<sti(npchar.quest.qty); i++)
				{
    				arCapLocal = GetAttributeN(arCapBase, i);
					sCapitainId = GetAttributeName(arCapLocal);
					sld = characterFromId(sCapitainId);
					attrL = "l" + i;
					link.(attrL) = GetFullName(sld) + ", ������� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Acc")) + " '" + sld.Ship.name + "'.";
					link.(attrL).go = "CapList_"+attrL;
				}
			}
			else
			{
				dialog.text = "� ���� � ������� ��� ���������, ��������� ��� ��������������.";
				link.l1 = "�������. ������� �� ����������.";
				link.l1.go = "node_2";
			}
		break;
		case "CapList_l0":
			makearef(arCapBase, npchar.quest.capitainsList);
    		arCapLocal = GetAttributeN(arCapBase,  0);
			sCapitainId = GetAttributeName(arCapLocal);
			sld = characterFromId(sCapitainId);
			dialog.text = LinkRandPhrase("��-�-��, ������� ���������... ���, ����! ", "���-���... ���, �����! ", "������, ���. ") +
				"������� " + GetFullName(sld) + " " + arCapLocal.date + " ���� ���� �� ������ ����� � " + XI_ConvertString("Colony" + arCapLocal + "Acc") + ".";
			link.l1 = "�������. �������� �� ���������� ������ ������...";
			link.l1.go = "CapitainList";
			link.l2 = "���, �������� ���� ����� �� ����������.";
			link.l2.go = "node_2";
			//������� ������ � ��
			AddQuestRecordEx(arCapLocal.QBString1, arCapLocal.QBString2, arCapLocal.QBQty);
			AddQuestUserData(arCapLocal.QBString1, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(arCapLocal.QBString1, "sCapName", GetFullName(sld));
			AddQuestUserData(arCapLocal.QBString1, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Dat")));
			AddQuestUserData(arCapLocal.QBString1, "sShipName", sld.Ship.name);
			AddQuestUserData(arCapLocal.QBString1, "sDate", arCapLocal.date);
			AddQuestUserData(arCapLocal.QBString1, "sTargetCity", XI_ConvertString("Colony" + arCapLocal + "Acc"));
			if (GetIslandByCityName(arCapBase.(sCapitainId)) != arCapBase.(sCapitainId))
			{
				AddQuestUserData(arCapLocal.QBString1, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(arCapBase.(sCapitainId)) + "Dat"));
			}
			//������� �� ������
			DeleteAttribute(arCapBase, sCapitainId); 
		break;
		case "CapList_l1":
			makearef(arCapBase, npchar.quest.capitainsList);
    		arCapLocal = GetAttributeN(arCapBase,  1);
			sCapitainId = GetAttributeName(arCapLocal);
			sld = characterFromId(sCapitainId);
			dialog.text = LinkRandPhrase("��-�-��, ������� ���������... ���, ����! ", "���-���... ���, �����! ", "������, ���. ") +
				"������� " + GetFullName(sld) + " " + arCapLocal.date + " ���� ���� �� ������ ����� � " + XI_ConvertString("Colony" + arCapLocal + "Acc") + ".";
			link.l1 = "�������. �������� �� ���������� ������ ������...";
			link.l1.go = "CapitainList";
			link.l2 = "���, �������� ���� ����� �� ����������.";
			link.l2.go = "node_2";
			//������� ������ � ��
			AddQuestRecordEx(arCapLocal.QBString1, arCapLocal.QBString2, arCapLocal.QBQty);
			AddQuestUserData(arCapLocal.QBString1, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(arCapLocal.QBString1, "sCapName", GetFullName(sld));
			AddQuestUserData(arCapLocal.QBString1, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Dat")));
			AddQuestUserData(arCapLocal.QBString1, "sShipName", sld.Ship.name);
			AddQuestUserData(arCapLocal.QBString1, "sDate", arCapLocal.date);
			AddQuestUserData(arCapLocal.QBString1, "sTargetCity", XI_ConvertString("Colony" + arCapLocal + "Acc"));
			if (GetIslandByCityName(arCapBase.(sCapitainId)) != arCapBase.(sCapitainId))
			{
				AddQuestUserData(arCapLocal.QBString1, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(arCapBase.(sCapitainId)) + "Dat"));
			}
			//������� �� ������
			DeleteAttribute(arCapBase, sCapitainId); 
		break;
		case "CapList_l2":
			makearef(arCapBase, npchar.quest.capitainsList);
    		arCapLocal = GetAttributeN(arCapBase,  2);
			sCapitainId = GetAttributeName(arCapLocal);
			sld = characterFromId(sCapitainId);
			dialog.text = LinkRandPhrase("��-�-��, ������� ���������... ���, ����! ", "���-���... ���, �����! ", "������, ���. ") +
				"������� " + GetFullName(sld) + " " + arCapLocal.date + " ���� ���� �� ������ ����� � " + XI_ConvertString("Colony" + arCapLocal + "Acc") + ".";
			link.l1 = "�������. �������� �� ���������� ������ ������...";
			link.l1.go = "CapitainList";
			link.l2 = "���, �������� ���� ����� �� ����������.";
			link.l2.go = "node_2";
			//������� ������ � ��
			AddQuestRecordEx(arCapLocal.QBString1, arCapLocal.QBString2, arCapLocal.QBQty);
			AddQuestUserData(arCapLocal.QBString1, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(arCapLocal.QBString1, "sCapName", GetFullName(sld));
			AddQuestUserData(arCapLocal.QBString1, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Dat")));
			AddQuestUserData(arCapLocal.QBString1, "sShipName", sld.Ship.name);
			AddQuestUserData(arCapLocal.QBString1, "sDate", arCapLocal.date);
			AddQuestUserData(arCapLocal.QBString1, "sTargetCity", XI_ConvertString("Colony" + arCapLocal + "Acc"));
			if (GetIslandByCityName(arCapBase.(sCapitainId)) != arCapBase.(sCapitainId))
			{
				AddQuestUserData(arCapLocal.QBString1, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(arCapBase.(sCapitainId)) + "Dat"));
			}
			//������� �� ������
			DeleteAttribute(arCapBase, sCapitainId); 
		break;
		case "CapList_l3":
			makearef(arCapBase, npchar.quest.capitainsList);
    		arCapLocal = GetAttributeN(arCapBase,  3);
			sCapitainId = GetAttributeName(arCapLocal);
			sld = characterFromId(sCapitainId);
			dialog.text = LinkRandPhrase("��-�-��, ������� ���������... ���, ����! ", "���-���... ���, �����! ", "������, ���. ") +
				"������� " + GetFullName(sld) + " " + arCapLocal.date + " ���� ���� �� ������ ����� � " + XI_ConvertString("Colony" + arCapLocal + "Acc") + ".";
			link.l1 = "�������. �������� �� ���������� ������ ������...";
			link.l1.go = "CapitainList";
			link.l2 = "���, �������� ���� ����� �� ����������.";
			link.l2.go = "node_2";
			//������� ������ � ��
			AddQuestRecordEx(arCapLocal.QBString1, arCapLocal.QBString2, arCapLocal.QBQty);
			AddQuestUserData(arCapLocal.QBString1, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(arCapLocal.QBString1, "sCapName", GetFullName(sld));
			AddQuestUserData(arCapLocal.QBString1, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Dat")));
			AddQuestUserData(arCapLocal.QBString1, "sShipName", sld.Ship.name);
			AddQuestUserData(arCapLocal.QBString1, "sDate", arCapLocal.date);
			AddQuestUserData(arCapLocal.QBString1, "sTargetCity", XI_ConvertString("Colony" + arCapLocal + "Acc"));
			if (GetIslandByCityName(arCapBase.(sCapitainId)) != arCapBase.(sCapitainId))
			{
				AddQuestUserData(arCapLocal.QBString1, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(arCapBase.(sCapitainId)) + "Dat"));
			}
			//������� �� ������
			DeleteAttribute(arCapBase, sCapitainId); 
		break;
		case "CapList_l4":
			makearef(arCapBase, npchar.quest.capitainsList);
    		arCapLocal = GetAttributeN(arCapBase,  4);
			sCapitainId = GetAttributeName(arCapLocal);
			sld = characterFromId(sCapitainId);
			dialog.text = LinkRandPhrase("��-�-��, ������� ���������... ���, ����! ", "���-���... ���, �����! ", "������, ���. ") +
				"������� " + GetFullName(sld) + " " + arCapLocal.date + " ���� ���� �� ������ ����� � " + XI_ConvertString("Colony" + arCapLocal + "Acc") + ".";
			link.l1 = "�������. �������� �� ���������� ������ ������...";
			link.l1.go = "CapitainList";
			link.l2 = "���, �������� ���� ����� �� ����������.";
			link.l2.go = "node_2";
			//������� ������ � ��
			AddQuestRecordEx(arCapLocal.QBString1, arCapLocal.QBString2, arCapLocal.QBQty);
			AddQuestUserData(arCapLocal.QBString1, "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData(arCapLocal.QBString1, "sCapName", GetFullName(sld));
			AddQuestUserData(arCapLocal.QBString1, "sShipTypeName", GetStrSmallRegister(XI_ConvertString(RealShips[sti(sld.Ship.Type)].BaseName + "Dat")));
			AddQuestUserData(arCapLocal.QBString1, "sShipName", sld.Ship.name);
			AddQuestUserData(arCapLocal.QBString1, "sDate", arCapLocal.date);
			AddQuestUserData(arCapLocal.QBString1, "sTargetCity", XI_ConvertString("Colony" + arCapLocal + "Acc"));
			if (GetIslandByCityName(arCapBase.(sCapitainId)) != arCapBase.(sCapitainId))
			{
				AddQuestUserData(arCapLocal.QBString1, "sAreal", ", ��� ��������� �� " + XI_ConvertString(GetIslandByCityName(arCapBase.(sCapitainId)) + "Dat"));
			}
			//������� �� ������
			DeleteAttribute(arCapBase, sCapitainId); 
		break;
		//<--------------------------- ���� �� ���� �������� �����

		case "ShipStock_1":
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobTakeShip" && !CheckAttribute(npchar, "quest.HWICHoll"))
			{
			dialog.text = "������ ��� - ����� �������, �� ����� ����?";
    		Link.l1 = "� �� ������ ����������. �� ������, ��� ������� ��� ����� ������� ����� ����������.";
    		Link.l1.go = "ShipStock_HWICHoll";
			break;
			}
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng") && pchar.questTemp.HWIC.Eng == "GotoPortoffice" && !CheckAttribute(npchar, "quest.HWICEng"))
			{
			dialog.text = "������ ��� - ����� �������, �� ����� ����?";
    		Link.l1 = "� �� ������� ��������. �� ������, ��� � ���� ��������� ���� ������� �� ������� �� 10 000 ����.";
    		Link.l1.go = "ShipStock_HWICEng";
			break;
			}
            if (sti(NPChar.Portman) >= 3 || CheckAttribute(pchar, "questTemp.HWIC.TakeQuestShip"))
			{
                dialog.text = "������-��, ��. �� ������ � �� ���� ������� �������. ��� ���� � �����.";
    			Link.l1 = "����� ����.";
    			Link.l1.go = "exit";
			}
            else
            {
    			ok = (sFrom_sea == "") || (Pchar.location.from_sea == sFrom_sea);
			    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
				{
					dialog.text = "����� ������ ������� �� ������ ��������?";
	    			for(i=1; i<COMPANION_MAX; i++)
	                {
	        	        cn = GetCompanionIndex(PChar, i);
	        	        if( cn >0 )
	        	        {
	        		        chref = GetCharacter(cn);
	                        if (!GetRemovable(chref)) continue;
	
	        		        attrL = "l"+i;
	        		        Link.(attrL)    = XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " '" + chref.Ship.Name + "'.";
	        		        Link.(attrL).go = "ShipStockMan_" + i;
	        		    }
	        	    }
	    			Link.l9 = "�������, �� �����.";
	    			Link.l9.go = "exit";
    			}
    			else
    			{
					dialog.text = "��. � �� ���� ����� �������� � �����.";
	    			Link.l1 = "��, � ������ �����"+ GetSexPhrase("","�") +" ������ � ����������� �������.";
	    			Link.l1.go = "exit";
				}
			}
		break;

		case "ShipStockMan_1":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 1);
			dialog.text = "���������, ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;

		case "ShipStockMan_2":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 2);
			dialog.text = "���������, ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;

		case "ShipStockMan_3":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 3);
			dialog.text = "���������, ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;
		
		case "ShipStockMan_4":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 4);
			dialog.text = "��������� ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
			break;

case "ShipStockMan_5":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 5);
			dialog.text = "��������� ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;
		
		case "ShipStockMan_6":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 6);
			dialog.text = "��������� ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;
		
		case "ShipStockMan_7":
            NPChar.ShipToStoreIdx = GetCompanionIndex(PChar, 7);
			dialog.text = "��������� ��� ��� �� �������.";
			Link.l1 = "������.";
			Link.l1.go = "ShipStock_2";
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;

		case "ShipStock_2":
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
			NPChar.MoneyForShip = GetPortManPriceExt(NPChar, chref);
			int money = sti(NPChar.MoneyForShip) + sti(chref.Ship.Crew.Quantity);
			dialog.Text = XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " '" + chref.Ship.Name + "', ����� " + RealShips[sti(chref.Ship.Type)].Class +
                     ", ��������� ������� " + FindRussianMoneyString(money) + " � �����, ������ �� ����� ������.";
			Link.l1 = "��. ��� ���� ����������.";
			if (sti(Pchar.Money) >= money)
			{
			    Link.l1.go = "ShipStock_3";
			}
			else
			{
                Link.l1.go = "ShipStock_NoMoney";
			}
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;

		case "ShipStock_NoMoney":
			dialog.text = "���� ���� ��� �������, ���� � ��� ����� ������ �����.";
			Link.l1 = "���... ����� �����.";
			Link.l1.go = "exit";
		break;

		case "ShipStock_3":
            AddMoneyToCharacter(pchar, -money);
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
            chref.ShipInStockMan = NPChar.id;
			// Warship 22.03.09 fix �� ����������� � ��� 1.2.3
			chref.ShipInStockMan.MoneyForShip = money;
            chref.ShipInStockMan.AltDate = GetQuestBookDataDigit(); // ��� ������
            SaveCurrentNpcQuestDateParam(chref, "ShipInStockMan.Date"); // ��� �������
            //chref.Ship.Crew.Quantity  = 0;
            RemoveCharacterCompanion(pchar, chref);
            chref.location = "";
            chref.location.group = "";
            chref.location.locator = "";

            NPChar.Portman    = sti(NPChar.Portman) + 1;
            pchar.ShipInStock = sti(pchar.ShipInStock) + 1;

			dialog.text = "������. ��������, ����� ����� �����.";
			Link.l1 = "�������.";
			Link.l1.go = "exit";
		break;

		case "ShipStockReturn_1":
            ok = (sFrom_sea == "") || (Pchar.location.from_sea == sFrom_sea);
		    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				if (GetCompanionQuantity(pchar) < COMPANION_MAX)
	            {
	                dialog.text = "����� ������ ������� �� ��������?";
	                cn = 1;
	                for(i=1; i<MAX_CHARACTERS; i++)
	            	{
	            		makeref(chref, Characters[i]);
	            		if (CheckAttribute(chref, "ShipInStockMan"))
	            		{
	                        if (chref.ShipInStockMan == NPChar.id)
	        		        {
	                            attrL = "l"+cn;
	            		        Link.(attrL)    = XI_ConvertString(RealShips[sti(chref.Ship.Type)].BaseName) + " '" + chref.Ship.Name + "'.";
	            		        Link.(attrL).go = "ShipStockManBack_" + i;
	            		        cn++;
	        		        }
	            		}
	                }
	
	    			Link.l9 = "���, � ���������"+ GetSexPhrase("","�") +".";
	    			Link.l9.go = "exit";
				}
				else
				{
	                dialog.text = "��� �� � ��� ����� ��� ��� ������ �������?";
	    			Link.l1 = "��, �����. �������.";
	    			Link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��. � �� ���� ������ �������� � �����. � ������� ���� ������� �� ������ ������ �����.";
    			Link.l1 = "������, � ������� �� ���� �������.";
    			Link.l1.go = "exit";
			}
		break;

        case "ShipStockManBack":
            chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
            NPChar.MoneyForShip =  GetNpcQuestPastMonthParam(chref, "ShipInStockMan.Date") * sti(chref.ShipInStockMan.MoneyForShip);
			if (sti(NPChar.MoneyForShip) > 0)
			{
			    dialog.Text = "���������? � ��� �� �������� ��� " + FindRussianMoneyString(sti(NPChar.MoneyForShip)) + ".";
			}
			else
			{
				dialog.Text = "���������?";
			}
			if (sti(NPChar.MoneyForShip) <= sti(pchar.Money))
			{
				Link.l1 = "��.";
				Link.l1.go = "ShipStockManBack2";
			}
			Link.l2 = "���, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;
		
		case "ShipStockManBack2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            AddMoneyToCharacter(Pchar, -sti(NPChar.MoneyForShip));
			chref = GetCharacter(sti(NPChar.ShipToStoreIdx));
			DeleteAttribute(chref, "ShipInStockMan");
			SetCompanionIndex(pchar, -1, sti(NPChar.ShipToStoreIdx));
			NPChar.Portman    = sti(NPChar.Portman) - 1;
            pchar.ShipInStock = sti(pchar.ShipInStock) - 1;
		break;
		
		//--> Jason ����������� ������
		case "ShipStock_HWICHoll":
			if (GetCompanionQuantity(pchar) > 1)
			{
				dialog.text = "��-��, � � �����. �� � ���� ������� �� ���������� ������� �� ��� ������ ���� �������. ����������, ����������� �� ����� ��������, � ����� ����� ������������� �� ���.";
				link.l1 = "������, � ������� �� ������� ������ �������.";
				link.l1.go = "exit";	
			}
			else
			{
				dialog.text = "��-��, � � �����. �� ������� ������� ���������� �� ��������� �� �������� ���� ����� � ������������ ��� ��������� �������� �� ��� ����� �������. ����������, ��������� ��� ��� � ��� ���...";
				link.l1 = "������... ���, ������ ��� ������������ �������?";
				link.l1.go = "ShipStock_HWICHoll_1";	
			}
		break;
		
		case "ShipStock_HWICHoll_1":
			dialog.text = "��. � ����� ������� �� ������������ - �� � ��� �����������. ������ �������� ������������ � ������� ����������.";
			link.l1 = "���������. �� ��������.";
			link.l1.go = "exit";	
			npchar.quest.HWICHoll = "done";
			pchar.Ship.Type = SHIP_NOTUSED;//��� ���� ������
		break;
		
		case "ShipStock_HWICEng":
			if (GetCompanionQuantity(pchar) > 1)
			{
				dialog.text = "��-��, � � �����. �� � ���� ������� ������� �� ��� ������ ���� �������. ����������, ����������� �� ����� ��������, � ����� ����� ������������� �� ���.";
				link.l1 = "������, � ������� �� ������� ������ �������.";
				link.l1.go = "exit";	
			}
			else
			{
				dialog.text = "��, �������. ������ ��� ���?";
				if(makeint(Pchar.money) >= 10000)
				{
					link.l1 = "��, ��� ���. ��������.";
					link.l1.go = "ShipStock_HWICEng_1";	
				}
				else
				{
					link.l1 = "���. ������ �������.";
					link.l1.go = "exit";	
				}
			}
		break;
		
		case "ShipStock_HWICEng_1":
			dialog.text = "������. �� ����������� � ����� ����� � ��������� ��� ��������� �������� �� ����� �������.";
			link.l1 = "�������!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -10000);
			npchar.quest.HWICEng = "done";
			pchar.Ship.Type = SHIP_NOTUSED;//��� ���� ������
		break;
		//<-- ����������� ������
		case "Escort_companion":
			dialog.text = "�� ���-�� ������, ���?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Escort_companion";
		break;

		//���, ����
		case "Houm_portman_1":
			if (pchar.questTemp.Headhunter.City == npchar.city)
			{
				dialog.text = "��, ��������������. �� ������ ����� ������������� ��� �������� � ������.";
				link.l1 = "�������! �� ��� ����� �������.";
				link.l1.go = "Houm_portman_yes";
			}
			else
			{
				dialog.text = "���, ������� ����� � �����.";
				link.l1 = "��... �����, ����� ������ ������.";
				link.l1.go = "exit";
			}
		break;
		
		case "Houm_portman_yes":
			pchar.questTemp.Headhunter = "houm_tavern";
			CreateHoum();
			AddQuestRecord("Headhunt", "5");
			AddQuestUserData("Headhunt", "sCity", pchar.questTemp.Headhunter.Cityname);
			DialogExit();
		break;
		//���, ����

	}
}

float BurntShipQuest_GetMaxNeededValue(int iShipType, string _param)
{
	float NeededValue = makefloat(GetBaseShipParamFromType(iShipType, _param));
	switch (_param)
	{
		case "speedrate":
			NeededValue += ((0.72 + frandSmall(0.30)) * (NeededValue/10.0)); 
		break;
		case "turnrate":
			NeededValue += ((0.72 + frandSmall(0.30)) * (NeededValue/10.0)); 
		break;
		case "capacity":
			NeededValue += ((0.72 + frandSmall(0.30)) * (NeededValue/8.0)); 
		break;
	}
	return NeededValue;
}

// Warship 25.07.09 ����� "��������� �����". ��������� ����� ��� �������� - ��� �������������� �����, ���������� �������������� � �.�.
void BurntShipQuest_FillStartParams(ref _npchar)
{
	int rank = sti(PChar.rank);
	int shipType, temp;
	float neededValue;
	String shipAttribute;
	
	// TODO ������������ ����������� �� �����
	if(rank <= 5)
	{
		shipType = SHIP_LUGGER + rand(1);
		
		switch(shipType)
		{
			case SHIP_LUGGER:
				shipAttribute = "speedrate";
			break;
			
			case SHIP_SLOOP:
				temp = rand(2);
				
				if(temp == 2)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					if(temp == 1)
					{
						shipAttribute = "turnrate";
					}
					else
					{
						shipAttribute = "capacity";
					}
				}
			break;
		}
	}
	
	if(rank > 5 && rank <= 15)
	{
		shipType = SHIP_SCHOONER + rand(2);
		
		switch(shipType)
		{
			case SHIP_SCHOONER:
				if(rand(1) == 0)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					shipAttribute = "turnrate";
				}
			break;
			
			case SHIP_BARKENTINE:
				shipAttribute = "capacity";
			break;
			
			case SHIP_SHNYAVA:
				shipAttribute = "capacity";
			break;
		}
	}
	
	if(rank > 15 && rank <= 25)
	{
		shipType = SHIP_FLEUT + rand(3);
		
		switch(shipType)
		{
			case SHIP_FLEUT:
				shipAttribute = "turnrate";
			break;
			
			case SHIP_CARAVEL:
				if(rand(1) == 1)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					shipAttribute = "turnrate";
				}
			break;
			
			case SHIP_PINNACE:
				shipAttribute = "capacity";
			break;
			
			case SHIP_CARACCA:
				if(rand(1) == 1)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					shipAttribute = "turnrate";
				}
			break;
			
		}
	}
	
	if(rank > 25 && rank <= 35)
	{
		shipType = SHIP_SCHOONER_W + rand(2);
		
		switch(shipType)
		{
			case SHIP_SCHOONER_W:
				if(rand(1) == 1)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					shipAttribute = "turnrate";
				}
			break;
			
			case SHIP_GALEON_L:
				shipAttribute = "capacity";
			break;
			
			case SHIP_CORVETTE:
				if(rand(1) == 1)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					shipAttribute = "capacity";
				}
			break;
		}
	}
	
	if(rank > 35)
	{
		shipType = SHIP_HEAVYGALEON + rand(13);
		
		switch(shipType)
		{
			case SHIP_HEAVYGALEON:
				temp = rand(2);
				
				if(temp == 0)
				{
					shipAttribute = "speedrate";
				}
				else
				{
					if(temp == 1)
					{
						shipAttribute = "turnrate";
					}
					else
					{
						shipAttribute = "capacity";
					}
				}
			break;
			
			case SHIP_LINEFRIGATE:
				shipAttribute = "turnrate";
			break;
		}
	}
	
	neededValue = BurntShipQuest_GetMaxNeededValue(shipType, shipAttribute);
	
	Log_TestInfo("shipType == " + shipType);
	Log_TestInfo("ShipAttribute == " + shipAttribute);
	Log_TestInfo("ShipNeededValue == " + neededValue);
	
	_npchar.Quest.BurntShip.ShipType = shipType;
	_npchar.Quest.BurntShip.ShipAttribute = shipAttribute;
	
	if(shipAttribute != "capacity") // ����� ���� � ����������� �� �������
	{
		_npchar.Quest.BurntShip.ShipNeededValue = FloatToString(neededValue, 2);
	}
	else
	{
		_npchar.Quest.BurntShip.ShipNeededValue = MakeInt(neededValue);
	}
}

void SetJornalCapParam(ref npchar)
{
	//������� ����������� ����
	ref sld = GetCharacter(NPC_GenerateCharacter("PortmansCap_" + npchar.index, "", "man", "man", 20, sti(pchar.nation), -1, true, "citizen"));
	SetShipToFantom(sld, "trade", true);
	sld.Ship.Mode = "trade";
	SetCaptanModelByEncType(sld, "trade");
	sld.dialog.filename = "Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "PortmansCap";
	sld.DeckDialogNode = "PortmansCap_inDeck";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AlwaysFriend = true;
	sld.nation = pchar.nation;
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	sld.DontRansackCaptain = true; //�� ���������
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
	//� ������� ������ ����
	string sGroup = "PorpmansShip_" + sld.index;
	Group_FindOrCreateGroup(sGroup);
	Group_SetType(sGroup,"trade");
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	//���������� ������ � ��������� �������� � ����
	npchar.quest = "PortmansJornal"; //������ ���� ������ ��� ��������
	npchar.quest.PortmansJornal.capName = GetFullName(sld); //��� ����
	npchar.quest.PortmansJornal.shipName = sld.Ship.name; //��� �������
	npchar.quest.PortmansJornal.shipTapeName = RealShips[sti(sld.Ship.Type)].BaseName; //�������� �������
	npchar.quest.PortmansJornal.city = SelectNotEnemyColony(npchar); //��������� �������, ���� ���� ���
	sld.quest = "InMap"; //������ ���� ����������� ����
	sld.quest.targetCity = npchar.quest.PortmansJornal.city; //������������ �������-���� � ��������� ����
	sld.quest.firstCity = npchar.city; //�������� ����� ������ ����� � ����� ������
	sld.quest.stepsQty = 1; //���������� ������� � ����
	sld.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1) * 150) + (sti(pchar.rank)*150); //��������������
	Log_TestInfo("���������� ��� " + sld.id + " ���������� �: " + sld.quest.targetCity);
	//��������� �����, ���� ������� ���������. ����� ����� �� ��������� ����� �� � ������
	string sTemp = GetArealByCityName(npchar.city);
	sld.quest.baseShore = GetIslandRandomShoreId(sTemp);
	//�� �����
	sld.mapEnc.type = "trade";
	sld.mapEnc.worldMapShip = "ranger";
	sld.mapEnc.Name = XI_ConvertString(npchar.quest.PortmansJornal.shipTapeName) + " '" + npchar.quest.PortmansJornal.shipName + "'";
	int daysQty = GetMaxDaysFromIsland2Island(sTemp, GetArealByCityName(sld.quest.targetCity))+5; //���� ������� ���� � �������
	Map_CreateTrader(sld.quest.baseShore, sld.quest.targetCity, sld.id, daysQty);
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "jornal"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = "none"; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = npchar.id + "PortmansBook_Delivery"; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "PortmansBook_Delivery"; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}
//��������� ������ ������������ ��������� �����
int CheckCapitainsList(ref npchar)
{
	int bResult = 0;
	if (!CheckAttribute(npchar, "quest.capitainsList")) return bResult;
	aref arCapBase, arCapLocal;
    makearef(arCapBase, npchar.quest.capitainsList);
    int	Qty = GetAttributesNum(arCapBase);
	if (Qty < 1) return bResult;
	string sCapitainId; 
	for (int i=0; i<Qty; i++)
    {
    	arCapLocal = GetAttributeN(arCapBase, i);
        sCapitainId = GetAttributeName(arCapLocal);
    	if (GetCharacterIndex(sCapitainId) > 0) //���� ��� ���
    	{
			bResult++;			
    	}
		else
		{
			DeleteAttribute(arCapBase, sCapitainId);
			i--;
			Qty--;
		}
    }
	if (bResult > 5) bResult = 5;
	return bResult;
}

void SetSeekShipCapParam(ref npchar)
{
	//������� ����-����
	int Rank = sti(pchar.rank) + 5;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("SeekCap_" + npchar.index, "", "man", "man", Rank, PIRATE, -1, true, "soldier"));
	SetShipToFantom(sld, "pirate", true);
	sld.Ship.Mode = "pirate";
	SetCaptanModelByEncType(sld, "pirate");
	sld.dialog.filename = "Quest\ForAll_dialog.c";
	sld.dialog.currentnode = "SeekCap";
	sld.DeckDialogNode = "SeekCap_inDeck";
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "SaveItemsForDead");
	DeleteAttribute(sld, "DontClearDead");
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
	sld.AlwaysSandbankManeuver = true;
	sld.AnalizeShips = true;  //������������� ��������� ������� ��� ������ �����
	sld.DontRansackCaptain = true; //�� ���������
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "BasicDefense");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "GunMan");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	//� ������� ������ ����
	string sGroup = "SeekCapShip_" + sld.index;
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	//���������� ������ � ��������� �������� � ����
	npchar.quest = "PortmansSeekShip"; //������ ���� ������ ��� ��������
	npchar.quest.PortmansSeekShip.capName = GetFullName(sld); //��� ����-����
	npchar.quest.PortmansSeekShip.shipName = sld.Ship.name; //��� ����������� �������
	npchar.quest.PortmansSeekShip.shipTapeName = RealShips[sti(sld.Ship.Type)].BaseName; //�������� ����������� �������
	npchar.quest.PortmansSeekShip.shipTape = RealShips[sti(sld.Ship.Type)].basetype; //��� ����������� �������
	//npchar.quest.money = ((sti(RealShips[sti(sld.Ship.Type)].basetype)+1) * 1000) + (sti(pchar.rank)*500); //��������������
	npchar.quest.chest = 7-sti(RealShips[sti(sld.Ship.Type)].Class); //� ��������
	sld.quest = "InMap"; //������ ���� ����-����
	sld.city = SelectAnyColony(npchar.city); //��������� �������, ������ ���-��� ������
	sld.quest.targetCity = SelectAnyColony2(npchar.city, sld.city); //��������� �������, ���� �� ������
	//Log_TestInfo("���-��� " + sld.id + " ����� ��: " + sld.city + " � ���������� �: " + sld.quest.targetCity);
	sld.quest.cribCity = npchar.city; //�����, ������ ���-��� ���� �������
	//�� �����
	sld.mapEnc.type = "trade";
	sld.mapEnc.worldMapShip = "Galleon_red";
	sld.mapEnc.Name = XI_ConvertString(npchar.quest.PortmansSeekShip.shipTapeName) + " '" + npchar.quest.PortmansSeekShip.shipName + "'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+3; //���� ������� ���� � �������
	Map_CreateTrader(sld.city, sld.quest.targetCity, sld.id, daysQty);
	//���������� �� �������
	string sTemp = "SeekShip_checkAbordage" + npchar.index;
	pchar.quest.(sTemp).win_condition.l1 = "Character_Capture";
	pchar.quest.(sTemp).win_condition.l1.character = sld.id;
	pchar.quest.(sTemp).function = "SeekShip_checkAbordage";
	pchar.quest.(sTemp).CapId = sld.id;
	//���������� �� ���������� ��� ��������
	sTemp = "SeekShip_checkSink" + npchar.index;
	pchar.quest.(sTemp).win_condition.l1 = "Character_sink";
	pchar.quest.(sTemp).win_condition.l1.character = sld.id;
	pchar.quest.(sTemp).function = "SeekShip_checkSink";
	pchar.quest.(sTemp).CapId = sld.id;
	//������� Id ���� � ���� ���-�����
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "robber"; //������������� ������
	NullCharacter.capitainBase.(sTemp).questGiver = "none"; //�������� Id ������������ ��� ������� � ������ ����
	NullCharacter.capitainBase.(sTemp).Tilte1 = npchar.id + "Portmans_SeekShip"; //��������� ���������
	NullCharacter.capitainBase.(sTemp).Tilte2 = "Portmans_SeekShip"; //��� ������ � ���������
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}

string GenQuestPortman_GenerateGem() // �����
{
	string itemID;
	switch(rand(5))
	{
		case 0:
			itemID = "jewelry1";	
		break;
		case 1:
			itemID = "jewelry2"; 
		break;
		case 2:
			itemID = "jewelry3"; 
		break;
		case 3:
			itemID = "jewelry3"; 
		break;
		case 4:
			itemID = "jewelry5"; 
		break;
		case 5:
			itemID = "jewelry6"; 
		break;
	}
	return itemID;
}

string findTraderCity_PU(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (nation != RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}

string findPassangerCity_PU(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (nation != RELATION_ENEMY && colonies[n].nation != "none" && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "NewProvidence" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� ���� ������
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}

// --> Jason, ����� ����-������
string findCurrentCity1(ref NPChar)//�������� ������� ����� 1
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

string findCurrentCity2(ref NPChar)//�������� ������� ����� 2
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
	nation = storeArray[abs(dRand(howStore-1)-3)];
	return colonies[nation].id;
}

string findCurrentCity3(ref NPChar)//�������� ������� ����� 3
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
	nation = storeArray[abs(dRand(howStore-1)-7)];
	return colonies[nation].id;
}

int Escort_ShipType()
{
	int iShipType;
	switch (rand(2))
	{
		case 0: iShipType = SHIP_FLEUT; 	break;
		case 1: iShipType = SHIP_GALEON_L; 	break;
		case 2: iShipType = SHIP_PINNACE;	break;
	}
	return iShipType;
}

//<-- ����� ����-������
