// boal 08/04/06 ����� ������ �����
#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;
	string s2;
	
	int iShipClass = GetCharacterShipClass(PChar); // ���� ������� ���, ������ 7 (�����)
	int iRank = sti(PChar.rank);
	int iSumm, iType;
	
	ref rRealShip;
	ref shTo;
	aref refShip;
	string attr;
	float fTmp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Shipyard\" + NPChar.City + "_Shipyard.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 16/06/06
    bool ok;
    int iTest = FindColony(NPChar.City); // ����� ��������
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
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
	
	
 	// ��������� ������� �� ����� <--
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "ship_tunning_not_now":  // ������ ������, �� ������ ������, ����� ������������.
            LockControl("DlgDown3", false);
			LockControl("DlgUp3", false);
			DialogExit();
			NextDiag.CurrentNode = "First time";  // ����� ��� �������, ����� ��� ��-�� LoadSegment
		break;
		
		case "ship_tunning_not_now_1":  
			LockControl("DlgDown3", false);
			LockControl("DlgUp3", false);
			DialogExit();
			NextDiag.CurrentNode = "First time";  
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
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
			
//Jason ---------------------------------------����� ��������------------------------------------------------
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock") && pchar.location == "Fortfrance_shipyard")
			{
				if (CheckAttribute(pchar, "questTemp.Sharlie.Rum") || CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") || CheckAttribute(pchar, "questTemp.Sharlie.RescueDaughter"))
				{
					dialog.text = "�� ���-�� ������, �����?";
					Link.l1 = "� ������ ���������� �������, ����� � ��� ����... �� ������ � ������� ����� - ���� ���� ������������� ��������. � ��� ������� �������, ��� ������ ��������� � ���.";
					Link.l1.go = "exit";
					break;
				}
				if (pchar.questTemp.Sharlie == "ship" || pchar.questTemp.Sharlie == "ship_fast") // Addon 2016-1 Jason ��������� ������� 1
				{
					dialog.text = "�� ���-�� ������, �����?";
					Link.l1 = "����������, � �� ����� ���������� � ��� �������.";
					Link.l1.go = "Sharlie";
					break;
				}
				dialog.text = "�� ���-�� ��� ������, �����?";
				Link.l1 = "���, �������, ������.";
				Link.l1.go = "exit";
				NextDiag.TempNode = "First time";
				NPChar.quest.meeting = "1";
				break;
			}
	//<-- ����� ��������
			// Addon-2016 Jason, ����������� ���������� (���) ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQM.Oil") && pchar.location == "Fortfrance_shipyard")
			{
				if (pchar.questTemp.FMQM == "remove_oil")
				{
					dialog.text = "�� ���, �������, ���� �������. ������ ����� �������� ��� ��� ������ - ���� ����������� ������. ���� �������...";
					link.l1 = "...";
					link.l1.go = "FMQM_oil_1";
					break;
				}
				if (pchar.questTemp.FMQM == "remove_oil1")
				{
					dialog.text = "�������� ������, ��������! ��� �����-�� ������. ����� ������� ��� ���������� �� ��� ��� - �� ������ ����������, ���� �� ����������� ������ ��� �����, ����������� � �������� �������. ��� �� �����? � ��� ���� ����?";
					link.l1 = "";
					link.l1.go = "FMQM_oil_2";
					break;
				}
				if (pchar.questTemp.FMQM == "remove_oil2")
				{
					dialog.text = "�������� ������, � ��� ��� ��������: ������� ������ ��������� ������ �� ������ �����. � ����� ��� � �������� - ���, � ������������� ��� ��� ����! � ������-�������, � ��� ����� ������������ � ���� ������������!";
					link.l1 = "";
					link.l1.go = "FMQM_oil_3";
					break;
				}
				if (pchar.questTemp.FMQM == "remove_oil3")
				{
					dialog.text = "�, ����� �������! �� ���� �� �������������, ����� ��� ���� ��� ���� ��������� - ��� ��� �� ������ ������ �� ����, ����� ����, �����, ���� � ������� ���������! ��� �������� ������� ��� ��� �����, ����� ������ ����� � ����� ������� �� ������ ������...";
					link.l1 = "����������, ������. ��� � ������ �������? ����� ��������?";
					link.l1.go = "FMQM_oil_4";
					break;
				}
			}
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "silk_13" && pchar.location == "PortRoyal_shipyard")
			{
				dialog.text = "�! ��� ����� ��! ������� �������, � ��� �����. ���� ��� �� ������� ��������� ������ ��... ��������� ������� ������� ������� ��� ������ �����?";
				link.l1 = "� ��� ������� ������, ������."; 
				link.l1.go = "mtraxx_x";
				break;
			}
			 if (rand(3) <= 2)
			  {		
			    if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -20)
			    {
                dialog.text = "���-���. ������� ��, ���������, ���������� � �������. � �� ���� ������ ��������� �������. ������� � ������ ���  � ������������ � ������ ������. ������, ����! � � ���� ���� �������!";
                link.l1 = "�� ��... ������ �������!";
                link.l1.go = "exit_fight"; 
                break;
                }	
             }		
			if(NPChar.quest.meeting == "0") // ������ �������
			{
				dialog.Text = GetNatPhrase(npchar, LinkRandPhrase("��! � ��� �������� ���������� �������� ��������� ������� ����! ������� � ������� �����, �������?","����� ����������, ���! ���� �� ������ ��������� � ���� � � ��� ���� ������� � �� �� ��� ����� �� ���!","����������� ���, ���! ��� ������� � �� ����� � ������ ����������� ���������� ����������� ������ �����."), LinkRandPhrase("�����, � �� �������, �����������, ��� ���� ����� ����� ������ ��������? ���� ��, �� � �� �� ��������, ������� ��� �������� �����!","������� � ���, ����� �������? ��������, �� ����������� ����������� �� �������� ���������.","����� �������, �����! �������, ��� � �������, ����� �����, � ��� ����� �������� ����� ���� � ������? ��������, �� �� ��� ��������� ������ �� ���!"), LinkRandPhrase("������� �� �������� ��� ������, ������. ��� ������ ����������!","� ����������� ��������� ���������� �����! �� ���� �����, ���� ���? � � ������� ������ ����������� ���, ��� ������� �������������.","������������, ���������! ����������� ��� � ����� ����������!"),LinkRandPhrase("������ ����, ������. � �� �������� ��� ������, �� �� ��� �� ����?","������������, ������ �������. �� �����������, � ����� ������� ���������, ��� ��� ����� ��������� ��� ������!","����� ���, ������. � ������� ����������� ������, ����� �������."));
				Link.l1 = LinkRandPhrase("����� ��� ����������. ���� ����� "+GetFullName(pchar)+", � � ����� ������ �������. ���, ����� ��������� �� ������.","�� ���� ������ ���� ����� ����� � ��� ������� ������ ������. � - "+GetFullName(pchar)+", ������� ������� '"+pchar.ship.name+"'.","��������� ������������� - "+GetFullName(pchar)+", ������� ������� '"+pchar.ship.name+"', ��� ����������. � ��, ������, ������� � ������������ �������?");
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1";
			}
			else
			{
				dialog.Text = pcharrepphrase(LinkRandPhrase(LinkRandPhrase("�! � ��� ��������� ����� ������� ���, ������� "+GetFullName(pchar)+"! ��� ���� ���� �������?","����� � ����, "+GetAddress_Form(NPChar)+", ������� ��� �������. ����� ������ ��� ������ ������� ��������?","��, �� ��� ������� �������� "+GetFullName(pchar)+"! ��� ���������, "+GetAddress_Form(NPChar)+"? ���� �������� ���� �������?"),LinkRandPhrase("� ��� ��� ��� �����, �������? �� ������ ����� �� ���� �����������, ��� �� ���� �����...","������������, "+GetAddress_Form(NPChar)+". ������ ��������, ��� ��� ����� �������� ��� ���� ��������. ����� ���������, ��� ����� ������� ��� ������?","� ����� �� ���, "+GetAddress_Form(NPChar)+"? ��� ��, �������, ��������� ���� ����, �� ���������."),LinkRandPhrase("��� �� ���� ������� ��� �� ���, �������� "+GetFullName(pchar)+"? �������, ��� ����� ������ ����� ������� ���������� �������...","��� �������������� ������������... �, ��������, "+GetAddress_Form(NPChar)+", � ���������. � ��� ����������?","� �� ����� �������� ����� ������ ������, �������, �� � ��������, �������, �� �����. ��� ��� �����?")),LinkRandPhrase(LinkRandPhrase("����� ��� ���, �������� "+GetFullName(pchar)+"! ��� ������ ���� ��������? �� ����� �� ������ ��� �����������?","����� ����������, "+GetAddress_Form(NPChar)+"! ������� "+GetFullName(pchar)+" ������ �������� ����� � ���� ����������!","�, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! �� ����� �������� ����! �������, � ����� ��������� ��� � �������?"),LinkRandPhrase(""+GetAddress_Form(NPChar)+", ��� �� � ��� ������ ��� �����! ��� �������� ��� ���������� �������? �� ����� �� ��� ������?","�, "+GetAddress_Form(NPChar)+", ����������� ���! ��� ���� ����? �� ������� �� �����, �� ����� �� �������� �����? ��� ��� ��� ������ ������������!","������ ����, ������� "+GetFullName(pchar)+". � ���, ��� �� ����� ��������� �� ��� � ������ ����� ������ ���."),LinkRandPhrase("����� ��� ������ ������, �������! �� ����� ������� ������, "+GetAddress_Form(NPChar)+", � � ����� ��� ������� � ����������.","�-�, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! ���������� ��� ������ ������! ��� ���� ���� �������?","�������, �� ����� �������� "+XI_ConvertString("Colony"+npchar.City+"Acc")+"! ��������, �� ����� ���� ��� ������.")));
				Link.l1 = pcharrepphrase(RandPhraseSimple(RandPhraseSimple("�������� �����������, ������, �� ����������. � ������� �� � ����.","����� ���������, ��������. ��� ����� ���� ������, � �� ������ ��������."),RandPhraseSimple("� ����� � �� ���������. �����. ������?","�����, �������, ���� ���� �������� � ������ ���� ������� ������!")),RandPhraseSimple(RandPhraseSimple("� ���� ��� ��� ������, ������. ���, ������� � ���� �������, ��� ��� ������� �������� � ����.","� � ����������� ���, �������. ������ ������� �������� ����������� �������?"),RandPhraseSimple("������ ����, ��������. ����� �������� � �����. �� ������, � ��������� ��� ����������� ������ �������� � ����������.","����� ��� ���, ������. � ��� ������ ������� ���������, �� ������ ��� ����� ���� ������.")));
				Link.l1.go = "Shipyard";
				if (GetNationRelation2MainCharacter(sti(NPChar.nation)) != RELATION_ENEMY) 
				{
					link.l11 = "��� ����� ������ �� �������.";
					link.l11.go = "Cannons";					
				}	
				
				if(NPChar.city == "PortRoyal" || NPChar.city == "Havana" || NPChar.city == "Villemstad" || NPChar.city == "Charles" || NPChar.city == "PortoBello")
				{
					link.l22 = "�� �� ����� �� ��� ���������� ���-�� ���������, �� ��� ������ �� ��������� �� �� ����� �����?";
					link.l22.go = "ship_tunning";
				}
				
				link.l15 = "��� �� � ��� ����, ���������� ��������� ������?";
			    link.l15.go = "Tasks";
				//Jason --> ��������� ��������
				if (CheckAttribute(pchar, "GenQuest.Findship.Shipyarder") && NPChar.location == pchar.GenQuest.Findship.Shipyarder.City + "_shipyard")
				{
					ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
					if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
					{
						for(i = 1; i < COMPANION_MAX; i++)
						{
							int iTemp = GetCompanionIndex(PChar, i);
							if(iTemp > 0)
							{
								sld = GetCharacter(iTemp);
								if(GetRemovable(sld) && sti(RealShips[sti(sld.ship.type)].basetype) == sti(pchar.GenQuest.Findship.Shipyarder.ShipType))
								{
									pchar.GenQuest.Findship.Shipyarder.CompanionIndex = sld.Index;
									pchar.GenQuest.Findship.Shipyarder.OK = 1;
									pchar.GenQuest.Findship.Shipyarder.ShipName = sld.Ship.Name;
									pchar.GenQuest.Findship.Shipyarder.Money = makeint(GetShipSellPrice(sld, CharacterFromID(NPChar.city + "_shipyarder"))*1.5);
								}
							}
						}
					}
					if (sti(pchar.GenQuest.Findship.Shipyarder.OK) == 1)
					{
						link.l16 = "� �������� ��� "+pchar.GenQuest.Findship.Shipyarder.ShipBaseName+", ��� �� �������.";
						link.l16.go = "Findship_check";
					}// <-- ��������� ��������
				}
				//Jason --> ��������� ����������� ���
				if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && CheckCharacterItem(pchar, "Tool") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_shipyard")
				{
					link.l17 = "��� ������� ��������� ���� � ������ "+pchar.GenQuest.Device.Shipyarder.Type+".";
					link.l17.go = "Device_complete";
				}
				// <-- ��������� ����������� ���
				if(RealShips[sti(Pchar.Ship.Type)].BaseType != SHIP_CURSED_FDM)
				{
					link.l12 = "���� �������� ������� ��� �������.";
					link.l12.go = "SailsGerald";
				}
				Link.l2 = "� ������ ���� ����������.";
				Link.l2.go = "quests"; //(���������� � ���� ������)
				// -->
    			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
				{
					link.l3 = "� �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ����� ����������.";
					link.l3.go = "LoanForAll";
				}
  				if (CheckAttribute(pchar, "GenQuest.Intelligence") && CheckAttribute(pchar, "GenQuest.Intelligence.SpyId") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "") //����� ���� - �� ����� � ����� �������
				{
					link.l7 = RandPhraseSimple("� ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".", 
						GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + " ������� ���� � ���. � ����"+ GetSexPhrase("��","��") +" ���-��� �������...");
					link.l7.go = "IntelligenceForAll";
				}

				//--> ����� ����.
	    		if (CheckCharacterItem(pchar, "Azzy_bottle"))
	            {
	                link.l5 = "������, � ���� ���� ���� ����� - ��������. ��� ����� ������������� �� �������. ������� ������� ���? � �������.";
	                if (npchar.id == pchar.questTemp.Ascold.ShipyarderId)
	                {
	                    link.l5.go = "AggryHelp";
		pchar.questTemp.Azzy = "Azzy_IHaveLamp";
	                }
	                else
	                {
	                    link.l5.go = "AzzyTryTalk";
	                }
	            }
	            //<-- �� ����� ����.
				//Jason, ����� ��������� ������� 2 ������
				if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.LevelUp"))
				{
					if (pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
					{
						link.l14 = "� �������� ������ ������� �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+".";
						link.l14.go = "Postcureer_LevelUp_ForAll";
					}
				} // patch-6
				if(CheckAttribute(pchar,"GenQuest.EncGirl"))
				{
					if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "shipyard_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
					{
						link.l7 = "������������, � ����"+ GetSexPhrase("��","��") +" �� ����������� ������ ����."; 
						link.l7.go = "EncGirl_4";
						pchar.quest.EncGirl_GetLoverFather.over = "yes";
					}	
					if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
					{
						if(pchar.GenQuest.EncGirl.Father == "shipyard_keeper" && npchar.city == pchar.GenQuest.EncGirl.city)
						{
							link.l8 = "� �� ������ ����� ������...";
							link.l8.go = "EncGirl_1";
						}
					}
				}								
				Link.l9 = "��� ����� ����.";
				Link.l9.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "Meeting":
				dialog.Text = "� ��� ������� � ����� ��������. ��� ����� � ����� �������.";
				Link.l1 = "�����������, " + GetFullName(NPChar) + ". ������� ��������� ��, ��� �� ������ ��� ����������.";
				Link.l1.go = "Shipyard";
				if (GetNationRelation2MainCharacter(sti(NPChar.nation)) != RELATION_ENEMY) 
				{
					link.l13 = "��� ����� ������ �� �������.";
					link.l13.go = "Cannons";
				}									
				link.l15 = "��� �� � ��� ����, ���������� ��������� ������?";
			    link.l15.go = "Tasks";
				
				if(RealShips[sti(Pchar.Ship.Type)].BaseType != SHIP_CURSED_FDM)
				{
					link.l12 = "���� �������� ������� ��� �������.";
					link.l12.go = "SailsGerald";
				}
				Link.l2 = "� ������ ���� ����������.";		
				link.l2.go = "quests";
				// -->
    			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
				{
					link.l3 = "� �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ����� ����������.";
					link.l3.go = "LoanForAll";//(���������� � ���� ������)
				}
  				if (CheckAttribute(pchar, "GenQuest.Intelligence") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "") //����� ���� - �� ����� � ����� �������
				{
					link.l7 = RandPhraseSimple("� ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".", 
						GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + " ������� ���� � ���. � ����"+ GetSexPhrase("��","��") +" ���-��� �������...");
					link.l7.go = "IntelligenceForAll";
				}
				//Jason, ����� ��������� ������� 2 ������
				if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.LevelUp"))
				{
					if (pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
					{
						link.l14 = "� �������� ������ ������� �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+".";
						link.l14.go = "Postcureer_LevelUp_ForAll";
					}
				}

				if(CheckAttribute(pchar,"GenQuest.EncGirl"))
				{
					if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "shipyard_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
					{
						link.l8 = "������������, � ����"+ GetSexPhrase("��","��") +" �� ����������� ������ ����."; 
						link.l8.go = "EncGirl_4";
						pchar.quest.EncGirl_GetLoverFather.over = "yes";
					}	
					if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
					{
						if(pchar.GenQuest.EncGirl.Father == "shipyard_keeper" && npchar.city == pchar.GenQuest.EncGirl.city)
						{
							link.l9 = "� �� ������ ����� ������...";
							link.l9.go = "EncGirl_1";
						}
					}
				}
				if (CheckCharacterItem(pchar, "CaptainBook") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakShipyard"))
				{
					if(CheckAttribute(pchar, "questTemp.different.GiveShipLetters") && (pchar.questTemp.different.GiveShipLetters.city == npchar.city))
					{
						link.l10 = "��� �� ������ ������� � ��������� ���� ����������?";
						link.l10.go = "ShipLetters_6";// ���������  "��������� ���������"
					}		
				}	
				Link.l11 = "� ����"+ GetSexPhrase("��","��") +" ����. ��������� ���.";
				Link.l11.go = "exit";
				NextDiag.TempNode = "First time";
		break;

		case "ship_tunning":
			dialog.text = "���� ����� ���������� ���������� ��������. ��� ��� ���������, �������?";
			Link.l1 = LinkRandPhrase("������������! ����� ��������� �� ��� �����, ��� � ��� ����� �������?",
			          "����� ���������, ������! ��� �� ������� �������� � ���� �������?",
					  "��. � ������ � ������ �����, �� ���� �� ������� ���������� ���-���� ����������, ������ ��������. ��� �������?");
			Link.l1.go = "ship_tunning_start";
		break;
				
		case "ship_tunning_start" :		
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if (sti(Pchar.Ship.Type) == SHIP_NOTUSED || ok)
			{				
				if (sti(RealShips[sti(pchar.Ship.Type)].Class) >= 6)
				{
					dialog.Text = "���.. ������� � �� ���������. ������ ������� � ���������, ������� ��� ��� �� ������.";
					Link.l1 = "�������...";
					Link.l1.go = "ship_tunning_not_now_1";
					break;
				}
				if(GetHullPercent(pchar) < 100 || GetSailPercent(pchar) < 100)
				{
					dialog.Text = "����� ���������� ������� ���������� ��������� ���������������. ��� ����� ������� �� ���� �����.";
					Link.l1 = "�������...";
					Link.l1.go = "ship_tunning_not_now_1";
					break;
				}
				
				s2 = "���-���... ���������, ��� ��� � ��� ����... ��� " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) + ".";
				s2 = s2 + " ������������ �� ������ �����: ��������� ����� �������������� ������ �������� � ��������� ������, � ��������� ���� �� �����. ������� ��������� �������� ���� �����, �������.";
				if(NPChar.city == "PortRoyal")
				{
					s2 = s2 + " ���� ����� �������� ������� � �������� ����������: �� ����� ��������� ��� ������������ �������� ��� ���� ���� � �����.";
				}
				if(NPChar.city == "Havana" || NPChar.city == "PortoBello")
				{
					s2 = s2 + " �� ���� ����� ����� ��������� ���������� ��������� ������ � �������� �������� ��� ���������������� �����.";
				}
				if(NPChar.city == "Villemstad")
				{
					s2 = s2 + " ��� ������ ������ ������ ������ �����, ��� �� ����� ��������� ��������������� (������������ �����������) �������.";
				}
				if(NPChar.city == "Charles")
				{
					s2 = s2 + " �� ���� ����� ����� �������� ������������� ��� ��������� ����������� ����������� �������.";
				}	
				
				dialog.Text = s2;
				
				if(NPChar.city == "PortRoyal")
				{
					ok = (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.SpeedRate")) && 
						 (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.WindAgainst"));
					if(ok)
					{
						Link.l1 = "��������� ��������.";
						Link.l1.go = "ship_tunning_SpeedRate";
						Link.l2 = "��������� ���� ���� � �����.";
						Link.l2.go = "ship_tunning_WindAgainst";
						Link.l3 = "��������! � ���������"+ GetSexPhrase("","�") +".";
						Link.l3.go = "ship_tunning_not_now_1";											
					}	
					else
					{
						Link.l1 = LinkRandPhrase("�! ��� ����� ��� �������� �� ������� ����� �����. �������, ��� ������� ��� �����!",
						                         "�������, ������, �� � ���� ��� ���� ���������, � ��� ��� �� ������������� ����. ����� � ������� ������ � �� �����������!",
												 "���! ��� ������� ��� ������������� ������� ����������, �� �����, ��� �� ���� �����. ������� ��� �� ������, � ��� � ����� �������� �� �������� ������!");
						Link.l1.go = "ship_tunning_not_now_1";					
					}
				}
				if(NPChar.city == "Havana" || NPChar.city == "PortoBello")
				{
					ok = (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.Cannon")) && 
						 (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.Capacity"));
					if(ok)
					{	
						if(GetPossibilityCannonsUpgrade(pchar, true) > 0)
						{	
							Link.l1 = "��������� ������������ ���������� ������.";
							Link.l1.go = "ship_c_quantity";
						}	
						if(GetPossibilityCannonsUpgrade(pchar, false) > 0)
						{
							Link.l2 = "��������� �������.";
							Link.l2.go = "ship_tunning_Capacity";
						}
						Link.l3 = "��������! � ���������"+ GetSexPhrase("","�") +".";
						Link.l3.go = "ship_tunning_not_now_1";											
					}
					else
					{
						Link.l1 = LinkRandPhrase("�! ��� ����� ��� �������� �� ������� ����� �����. �������, ��� ������� ��� �����!",
						                         "�������, ������, �� � ���� ��� ���� ���������, � ��� ��� �� ������������� ����. ����� � ������� ������ � �� �����������!",
												 "���! ��� ������� ��� ������������� ������� ����������, �� �����, ��� �� ���� �����. ������� ��� �� ������, � ��� � ����� �������� �� �������� ������!");
						Link.l1.go = "ship_tunning_not_now_1";					
					}						
				}
				if(NPChar.city == "Villemstad")
				{
					ok = (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.HP")) && 
						 (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.MaxCrew"));
					if(ok)
					{
						Link.l1 = "��������� ��������� �������.";
						Link.l1.go = "ship_tunning_HP";
						Link.l2 = "��������� ����� ��� �������.";
						Link.l2.go = "ship_tunning_MaxCrew";
						Link.l3 = "��������! � ���������"+ GetSexPhrase("","�") +".";
						Link.l3.go = "ship_tunning_not_now_1";											
					}	
					else
					{
						Link.l1 = LinkRandPhrase("�! ��� ����� ��� �������� �� ������� ����� �����. �������, ��� ������� ��� �����!",
						                         "�������, ������, �� � ���� ��� ���� ���������, � ��� ��� �� ������������� ����. ����� � ������� ������ � �� �����������!",
												 "���! ��� ������� ��� ������������� ������� ����������, �� �����, ��� �� ���� �����. ������� ��� �� ������, � ��� � ����� �������� �� �������� ������!");
						Link.l1.go = "ship_tunning_not_now_1";					
					}
				}
				if(NPChar.city == "Charles")
				{
					ok = (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.TurnRate")) && 
						 (!CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning.MinCrew"));
					if(ok)
					{		
						Link.l1 = "��������� �������������.";
						Link.l1.go = "ship_tunning_TurnRate";
						if(sti(RealShips[sti(pchar.Ship.Type)].Class) < 5)
						{
							Link.l2 = "��������� ����������� ����������� �������.";
							Link.l2.go = "ship_tunning_MinCrew";
						}	
						Link.l3 = "��������! � ���������"+ GetSexPhrase("","�") +".";
						Link.l3.go = "ship_tunning_not_now_1";											
					}
					else
					{
						Link.l1 = LinkRandPhrase("�! ��� ����� ��� �������� �� ������� ����� �����. �������, ��� ������� ��� �����!",
						                         "�������, ������, �� � ���� ��� ���� ���������, � ��� ��� �� ������������� ����. ����� � ������� ������ � �� �����������!",
												 "���! ��� ������� ��� ������������� ������� ����������, �� �����, ��� �� ���� �����. ������� ��� �� ������, � ��� � ����� �������� �� �������� ������!");
						Link.l1.go = "ship_tunning_not_now_1";					
					}												
				}								
			}
			else
			{
				dialog.Text = "�������-�� ���? ��� �� ��� ��� ������ ��������?!";
			    Link.l1 = "� �� ������.. ��� ��� �... ���������";
			    Link.l1.go = "ship_tunning_not_now_1";
			}			
		break;
		
		////////////////////////////////////////// Capacity ////////////////////////////////////////////////////
		case "ship_tunning_Capacity":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar, 2 );			
			s2 = "������� ���������, ��� ����� �������. ������ ������� ������ ����� - " + sti(RealShips[sti(pchar.Ship.Type)].Capacity);			
			s2 = s2 + ". ��� ����������� ��������� ��� �����������: ������� - " + Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";			
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_Capacity_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_tunning_Capacity_start":
		    amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;			    
				NextDiag.TempNode = "ship_tunning_Capacity_again";
                dialog.text = "��� � ������. ��� ��������.";
			    link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";			    
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� �������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'"+
				" ������-������� �������: ������� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
				
		case "ship_tunning_Capacity_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_Capacity_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_tunning_Capacity_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
			    dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_Capacity_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_SANDAL);		
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_Capacity_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_Capacity_again";
				dialog.Text = "�� ���� ��������: ������� - " + sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_Capacity_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������
			if(!CheckAttribute(shTo, "Bonus_Capacity"))
			{
				shTo.Capacity        = sti(shTo.Capacity) + makeint(sti(shTo.Capacity)/5);
			}
			else
			{
				shTo.Capacity        = makeint((sti(shTo.Capacity) - sti(shTo.Bonus_Capacity)) * 1.2 + sti(shTo.Bonus_Capacity));
			}			
	        shTo.Tuning.Capacity = true;
			
			makearef(refShip, pchar.Ship);
			if(CheckAttribute(refShip,"CannonDiff")) 	iCannonDiff = sti(refShip.CannonDiff);
			else										iCannonDiff = 0;
			
			iCannonDiff += 1;
								
			for (i = 0; i < sti(shTo.cannonr); i++)
			{
				attr = "c" + i;					
				if(i >= sti(shTo.cannonr) - iCannonDiff)	
				{
					refShip.Cannons.Borts.cannonr.damages.(attr) = 2.0; 
				}
			}	
			for (i = 0; i < sti(shTo.cannonl); i++)
			{
				attr = "c" + i;
				if(i >= sti(shTo.cannonl) - iCannonDiff)	
				{
					refShip.Cannons.Borts.cannonl.damages.(attr) = 2.0; 
				}
			}	
			if(CheckAttribute(shTo,"CannonsQuantityMax")) 	shTo.Cannons = sti(shTo.CannonsQuantityMax) - iCannonDiff * 2;
			else										    shTo.Cannons = sti(shTo.CannonsQuantity) - iCannonDiff * 2;
			
			shTo.CannonsQuantity = sti(shTo.Cannons);
		
			refShip.Cannons = sti(shTo.Cannons);
			refShip.CannonDiff = iCannonDiff;

			shTo.DontTuning.Cannon = true;
			
	        // finish <--
            NextDiag.TempNode = "First time";
			dialog.Text = "...����� �� ���... ����� ��������� �� ������, �������� ������ ����������.";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		////////////////////////////////////////// SpeedRate ////////////////////////////////////////////////////
		case "ship_tunning_SpeedRate":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar,  1 );			
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar,  2 );
			s2 = "������� ���������, ��� ����� �������. ������ �������� ������ ������� " + stf(RealShips[sti(Pchar.Ship.Type)].SpeedRate);	
			s2 = s2 + " �����. ��� ����� ������� ��� �����������: ������������ ����� - "+ Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";						
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_SpeedRate_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
			
		case "ship_tunning_SpeedRate_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 			    
			    NPChar.Tuning.ShipType   	= Pchar.Ship.Type;
			    NPChar.Tuning.ShipName   	= RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_SpeedRate_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� �������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +
				" ������-������� �������: ������������ ����� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_tunning_SpeedRate_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_SpeedRate_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_tunning_SpeedRate_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";			
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_SpeedRate_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_SHIPSILK);		    
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_SpeedRate_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_SpeedRate_again";
				dialog.Text = "�� ���� ��������: ������������ ����� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText",  "��� �������� �������: ������������ ����� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_SpeedRate_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������
			if(!CheckAttribute(shTo, "Bonus_SpeedRate"))
			{
					shTo.SpeedRate        = (stf(shTo.SpeedRate) + stf(shTo.SpeedRate)/5.0);
			}
			else
			{
					shTo.SpeedRate        = (stf(shTo.SpeedRate) - stf(shTo.Bonus_SpeedRate)) * 1.2 + stf(shTo.Bonus_SpeedRate);
			}		
	        shTo.Tuning.SpeedRate = true;
			
			shTo.WindAgainstSpeed   	= stf(shTo.WindAgainstSpeed) + 0.15 * stf(shTo.WindAgainstSpeed);
			shTo.DontTuning.WindAgainst = true;
	        // finish <--
            NextDiag.TempNode = "First time";
			dialog.Text = "... ��� � ���, �������. ������ ������ ����� ������� ��������. ������ - ���������!";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		////////////////////////////////////////// TurnRate ////////////////////////////////////////////////////
		case "ship_tunning_TurnRate":
			Material  = GetMaterialQtyUpgrade(pchar, NPChar, 1 );			
			WorkPrice = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			s2 = "������� ���������, ��� ����� �������. ������ ������������� ����� ������� - " + stf(RealShips[sti(Pchar.Ship.Type)].TurnRate);			
			s2 = s2 + " ��� �������������� �������, ���� ��� �����������, ��� �����������: ������� - "+ Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";										
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_TurnRate_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_tunning_TurnRate_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
				NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_TurnRate_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");			    
			    link.l1.go = "Exit";			    
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� ������������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +
				" ������-������� �������: ������� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_tunning_TurnRate_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_TurnRate_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� ���������.";
			    Link.l1.go = "ship_tunning_TurnRate_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";	
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_TurnRate_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_ROPES);		
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_TurnRate_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_TurnRate_again";
				dialog.Text = "�� ���� ��������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_TurnRate_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������
			if(!CheckAttribute(shTo, "Bonus_TurnRate"))
			{
				shTo.TurnRate        = (stf(shTo.TurnRate) + stf(shTo.TurnRate)/5.0);
			}
			else
			{
				shTo.TurnRate        = (stf(shTo.TurnRate) - stf(shTo.Bonus_TurnRate)) * 1.2 + stf(shTo.Bonus_TurnRate);
			}	
			
			shTo.MinCrew = sti(shTo.MinCrew) + makeint(sti(shTo.MinCrew) * 0.15);
			if(sti(shTo.MinCrew) < 1) shTo.MinCrew = 1;
			shTo.DontTuning.MinCrew = true;	
	        shTo.Tuning.TurnRate = true;
            NextDiag.TempNode = "First time";
			dialog.Text = "... ����� ���... �������, ������ ������ ������� �������, �������!";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		////////////////////////////////////////// MaxCrew ////////////////////////////////////////////////////
		case "ship_tunning_MaxCrew":
			Material  = GetMaterialQtyUpgrade(pchar, NPChar, 1 );
			WorkPrice = GetMaterialQtyUpgrade(pchar, NPChar, 2 );				
			s2 = "������� ���������, ��� ����� �������. ������ ������������ ������ ������ ����� � ������ ���������  " + sti(RealShips[sti(Pchar.Ship.Type)].MaxCrew) + " �������.";			
			s2 = s2 + " ��� �����������: ������� - "+ Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";									
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_MaxCrew_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_tunning_MaxCrew_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_MaxCrew_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";			    
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� ������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +
				" ������-������� �������: ������� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_tunning_MaxCrew_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_MaxCrew_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_tunning_MaxCrew_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";				
			    Link.l1.go = "Exit";
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_MaxCrew_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_SANDAL);		    
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_MaxCrew_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_MaxCrew_again";
				dialog.Text = "�� ���� ��������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_MaxCrew_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    
	        shTo.MaxCrew        = sti(shTo.MaxCrew) + makeint(sti(shTo.MaxCrew)/5);
	        shTo.Tuning.MaxCrew = true;
			
			shTo.HP = sti(shTo.HP) - makeint(sti(shTo.HP) * 0.15);
			shTo.BaseHP = sti(shTo.HP);
			shTo.DontTuning.HP = true;	
            NextDiag.TempNode = "First time";
			dialog.Text = "... ���������, �������. ��������� ��������, ���� ����� ������.";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";
			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;

		
		////////////////////////////////////////// MinCrew ////////////////////////////////////////////////////
		case "ship_tunning_MinCrew":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );			
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar, 2 );				
			s2 = "������� ���������, ��� ����� �������. ������ ����������� ������ ������ ����� " + sti(RealShips[sti(Pchar.Ship.Type)].MinCrew) + " �������.";			
			s2 = s2 + " ��� ��������� ������������� ������� � ���������� ����������� ������� � ������ : ������� - "+ Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";									
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_MinCrew_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_tunning_MinCrew_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_MinCrew_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";			    
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� ����������� ����������� ������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +			
				" ������-������� �������: ������� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_tunning_MinCrew_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_MinCrew_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_tunning_MinCrew_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";		
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_MinCrew_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_ROPES);		    
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_MinCrew_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_MinCrew_again";
				dialog.Text = "�� ���� ��������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ������� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_MinCrew_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������
	        shTo.MinCrew        = sti(shTo.MinCrew) - makeint(sti(shTo.MinCrew)/5);
			if(sti(shTo.MinCrew) < 1) shTo.MinCrew = 1;
	        shTo.Tuning.MinCrew = true;
			
			shTo.TurnRate = (stf(shTo.TurnRate) - stf(shTo.TurnRate) * 0.15);
			shTo.DontTuning.TurnRate = true;
            NextDiag.TempNode = "First time";
			dialog.Text = "... ������, �������! ����� ����������� ������� ������ ��������, �� � ��� �� �����������.";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";
			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		////////////////////////////////////////// HP ////////////////////////////////////////////////////
		case "ship_tunning_HP":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar, 2 );			
			s2 = "������� ���������, ��� ����� �������. ������ ����� ������ " + sti(RealShips[sti(Pchar.Ship.Type)].HP);			
			s2 = s2 + ". ����� �������� �������, ��� �����������: ���� - "+ Material + ".";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";									
            dialog.Text = s2;
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_HP_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_tunning_HP_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_HP_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";
			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� ��������� ������� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +			
				" ������-������� �������: ���� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_tunning_HP_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_HP_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� �������.";
			    Link.l1.go = "ship_tunning_HP_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";	
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;
		
		case "ship_tunning_HP_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_OIL);		
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_HP_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_HP_again";
				dialog.Text = "�� ���� ��������: ���� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ���� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;
		
		case "ship_tunning_HP_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������
			if(!CheckAttribute(shTo, "Bonus_HP"))
			{
				shTo.HP        = sti(shTo.HP) + makeint(sti(shTo.HP)/5);
			}
			else
			{
				shTo.HP        = makeint((sti(shTo.HP) - sti(shTo.Bonus_HP)) * 1.2 + sti(shTo.Bonus_HP));
			}	
	        shTo.Tuning.HP = true;
			shTo.BaseHP = sti(shTo.HP);
			
	        shTo.MaxCrew = sti(shTo.MaxCrew) - makeint(sti(shTo.MaxCrew) * 0.15);
			shTo.DontTuning.MaxCrew = true;	
            NextDiag.TempNode = "First time";
			
			dialog.Text = "... ����� �� ���... ����������, ��� ��������� ���� �������� ������ ����� ����� ��������!";
			Link.l1 = "���, ���� �� �����! �������, ������.";
			Link.l1.go = "Exit";
			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		////////////////////////////////////////// WindAgainst ////////////////////////////////////////////////////
		case "ship_tunning_WindAgainst":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			fTmp = 180.0 - (stf(RealShips[sti(Pchar.Ship.Type)].WindAgainstSpeed) * 90.0);
			s2 = "������� ���������, ��� ����� �������. �������� ���� " + makeint(fTmp) + " ��������.";
			s2 = s2 + ". ����� �������� ��� ����� ���������������� ���� ����� ��� �����������: ������������ ����� - "+ Material + ",";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";									
            dialog.Text = s2;
			Link.l1 = "������ ��-���������, ����� ������ ������ ������� �� �����? �������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_tunning_WindAgainst_start";
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;

		case "ship_tunning_WindAgainst_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    		
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Tuning.Money  		= amount;
			    NPChar.Tuning.Matherial    	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );			    
			    NPChar.Tuning.ShipType      = Pchar.Ship.Type;
			    NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NextDiag.TempNode = "ship_tunning_WindAgainst_again";
                dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
			    link.l1.go = "Exit";

			    ReOpenQuestHeader("ShipTuning");
			    AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ��������� ��������� ���� �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +			
				" ������-������� �������: ������������ ����� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now_1";
                dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";
			}
		break;

		case "ship_tunning_WindAgainst_again":
		    if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_tunning_WindAgainst_again";
			    dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
			    Link.l1 = "��. ���-��� ������� ���������.";
			    Link.l1.go = "ship_tunning_WindAgainst_again_2";
			    Link.l2 = "���. ��� �������.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
			    Link.l1.go = "Exit";
			    AddQuestRecord("ShipTuning", "Lose");
			    CloseQuestHeader("ShipTuning");
			}
		break;

		case "ship_tunning_WindAgainst_again_2":
		    checkMatherial(Pchar, NPChar, GOOD_SHIPSILK);
		    if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
                NextDiag.TempNode = "First time";
                dialog.text = "������������, ������ ��� � �������. ������� ������...";
			    link.l1 = "���.";
			    link.l1.go = "ship_tunning_WindAgainst_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_WindAgainst_again";
                dialog.Text = "�� ���� ��������: ������������ ����� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
                AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ������������ ����� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}
		break;

		case "ship_tunning_WindAgainst_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
		    DeleteAttribute(NPChar, "Tuning");
		    // �������			
	        shTo.WindAgainstSpeed   = stf(shTo.WindAgainstSpeed) - 0.15 * stf(shTo.WindAgainstSpeed);			
	        shTo.Tuning.WindAgainst = true;
			
			shTo.SpeedRate = (stf(shTo.SpeedRate) - stf(shTo.SpeedRate)* 0.15);
			shTo.DontTuning.SpeedRate = true;		
	        // finish <--
            NextDiag.TempNode = "First time";
			dialog.Text = "... �������, ���! ������ ��� ����� ����� ������ �� ����� ���� ��� �����������.";
			Link.l1 = "�������! ������� �����������.";
			Link.l1.go = "Exit";

			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
						
		////////////////////////////////////////// ������ ���������� ������  ////////////////////////////////////////////////////	
		case "ship_c_quantity":
			Material 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 );			
			WorkPrice 	= GetMaterialQtyUpgrade(pchar, NPChar, 2 );			
			s2 = "������� ���������, ��� ����� �������. ������ ������ �� ����� ������� " + sti(RealShips[sti(Pchar.Ship.Type)].CannonsQuantity) + ", ����������� ��������� ���������� - " + sti(RealShips[sti(Pchar.Ship.Type)].CannonsQuantityMax) + ".";			
			s2 = s2 + " ��� ��� ���� ��������� ��������, ��� �����������: ���� - "+ Material + ",";
			s2 = s2 + " � ������ �� ���� ������ � ������: �������� " + WorkPrice + " - �� ������� �������. ����� �� ���. �� �� - ������ ������.";						
			dialog.Text = s2;		
			Link.l1 = "�������. � �������� �������. ��� ����������� ����� ����������.";
			Link.l1.go = "ship_c_quantity_start";		
			Link.l2 = "���. ���� ��� �� ����������.";
			Link.l2.go = "ship_tunning_not_now_1";
		break;
		
		case "ship_c_quantity_start":
			amount = GetMaterialQtyUpgrade(pchar, NPChar, 2 );
			if(GetCharacterItem(pchar,"gold_dublon") >= amount)		    		
			{
				TakeNItems(pchar,"gold_dublon", -amount);								
			    NPChar.Tuning.Money  		= amount;
				NPChar.Tuning.Cannon 		= true;				
				NPChar.Tuning.Matherial 	= GetMaterialQtyUpgrade(pchar, NPChar, 1 ); 				
				NPChar.Tuning.ShipType      = Pchar.Ship.Type;
				NPChar.Tuning.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;											    
				NextDiag.TempNode = "ship_c_quantity_again";
				dialog.text = "��� � ������. ��� ��������.";
				link.l1 = LinkRandPhrase("������, ����� ����� �� ��������. � ���� ������ ����� �������, ��������?",
										 "��������, ��� ��� ��� � ��� � ���������� ���, � ���� ����, ��� �����.",
										 "�� ������. ��� ������ ������ ����-������ ���������� ��������������, ��-��-��!");
				link.l1.go = "Exit";			    
				ReOpenQuestHeader("ShipTuning");
				AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "�� ���� ������ �� ���������� ���������� ������ �� " + GetStrSmallRegister(XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName + "Voc")) + " '" + pchar.ship.name + "'" +						
				" ������-������� �������: ���� - " + NPChar.Tuning.Matherial + ". � �������� ������� ���� �������� " + NPChar.Tuning.Money + " ��������.");				
			}		
			else
			{ 
				NextDiag.TempNode = "ship_tunning_not_now_1";
				dialog.text = "�� ���� �������...";
				link.l1 = "� ����� �����.";
				link.l1.go = "Exit";
			}
		break;		
		
		case "ship_c_quantity_again":	
			if (sti(NPChar.Tuning.ShipType) == sti(Pchar.Ship.Type) && NPChar.Tuning.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
			{
				NextDiag.TempNode = "ship_c_quantity_again";
				dialog.Text = "����� ����, � ����� ����. �� ��� ���������, ��� � ��������?";
				Link.l1 = "��. ���-��� ������� �������.";
				Link.l1.go = "ship_c_quantity_again_2";
				Link.l2 = "���. ��� �������.";
				Link.l2.go = "Exit";
			}		
			else
			{
				DeleteAttribute(NPChar, "Tuning");
				NextDiag.TempNode = "First time";
				dialog.Text = "�����"+ GetSexPhrase("�","���") +", �� �������� ������� �� ������� ������ �������? ��������.";
			    Link.l1 = "���, ����� ����� ��������������! ������, ��� ������� ������...";
				Link.l1.go = "Exit";
				AddQuestRecord("ShipTuning", "Lose");
				CloseQuestHeader("ShipTuning");
			}		
		break;
		
		case "ship_c_quantity_again_2":		
			checkMatherial(Pchar, NPChar, GOOD_OIL);
			if(sti(NPChar.Tuning.Matherial) < 1)
			{
				DeleteAttribute(NPChar, "Tuning");
				NextDiag.TempNode = "First time";
				dialog.text = "������������, ������ ��� � �������. ������� ������...";
				link.l1 = "���.";
				link.l1.go = "ship_c_quantity_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_c_quantity_again";
				dialog.Text = "���� �������� ��������: ���� - "+ sti(NPChar.Tuning.Matherial) + ".";
				link.l1 = "������.";
				link.l1.go = "Exit";
				AddQuestRecord("ShipTuning", "t1");
				AddQuestUserData("ShipTuning", "sText", "��� �������� �������: ���� - "+ sti(NPChar.Tuning.Matherial) + ".");
			}		
		break;
		
		case "ship_c_quantity_complite":
			AddTimeToCurrent(6, 30);
			shTo = &RealShips[sti(Pchar.Ship.Type)];
			DeleteAttribute(NPChar, "Tuning");		
			makearef(refShip, pchar.Ship);
			
			iCannonDiff = sti(refShip.CannonDiff);
			iCannonDiff -= 1;
								
			for (i = 0; i < sti(shTo.cannonr); i++)
			{
				attr = "c" + i;										
					
				if(i < (sti(shTo.cannonr) - iCannonDiff) )	
				{
					if( stf(refShip.Cannons.Borts.cannonr.damages.(attr)) > 1.0 )
					{
						refShip.Cannons.Borts.cannonr.damages.(attr) = 1.0; 
					}	
				}					
			}	
			for (i = 0; i < sti(shTo.cannonl); i++)
			{
				attr = "c" + i;
				if(i < (sti(shTo.cannonl) - iCannonDiff) )	
				{
					if( stf(refShip.Cannons.Borts.cannonl.damages.(attr)) > 1.0 )
					{
						refShip.Cannons.Borts.cannonl.damages.(attr) = 1.0; 
					}	
				}										
			}	
			
			if(CheckAttribute(shTo,"CannonsQuantityMax")) 	shTo.Cannons = sti(shTo.CannonsQuantityMax) - iCannonDiff * 2;
			else										    shTo.Cannons = sti(shTo.CannonsQuantity) - iCannonDiff * 2;
			
			shTo.CannonsQuantity = sti(shTo.Cannons);
		
			refShip.Cannons = sti(shTo.Cannons);
			refShip.CannonDiff = iCannonDiff;			

			shTo.Tuning.Cannon = true;
			
			shTo.Capacity = sti(shTo.Capacity) - makeint(sti(shTo.Capacity) * 0.15);
			shTo.DontTuning.Capacity = true;
			NextDiag.TempNode = "First time";
			dialog.Text = "... ��� � ���� �����. ������ ���������� �������������� ������. ���� ��� ����, ��-��..";
			Link.l1 = "�������!";
			Link.l1.go = "Exit";
			
			AddQuestRecord("ShipTuning", "End");
			CloseQuestHeader("ShipTuning");
		break;
		
		case "Tasks":
			//--> Jason ��������� ����� �������
			if (drand(4) == 2 && !CheckAttribute(pchar, "GenQuest.Findship.Shipyarder") && sti(pchar.rank) < 19)
			{
				if (!CheckAttribute(npchar, "Findship") || GetNpcQuestPastDayParam(npchar, "Findship") >= 60) 
				{
					SelectFindship_ShipType(); //����� ���� �������
					pchar.GenQuest.Findship.Shipyarder.ShipBaseName =  GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.Findship.Shipyarder.ShipType), "Name") + "Acc")); // new
					pchar.GenQuest.Findship.Shipyarder.City = npchar.city; //����� ������������
					dialog.text = "� ���� ���� ��������, ��������� �������. ��� �������� ����� �� ������� - "+pchar.GenQuest.Findship.Shipyarder.ShipBaseName+". ������ � ���� �� ����� ������ ������ ������� ���, ������� ��� �� ��� ������ � ���� ���� ��� �����������\n���� �� ������� ��������� ��� ����� ������� - ���� ����� ����������, � ������� �����, � ������� ���� ����������� ��� ��������� ���������.";
					link.l1 = "���������� �����������. � ��������!";
					link.l1.go = "Findship";
					link.l2 = "��� ��� �� ���������.";
					link.l2.go = "Findship_exit";
					SaveCurrentNpcQuestDateParam(npchar, "Findship");
					break;
				}
				
			}//<-- ��������� ����� �������
			//Jason --> ��������� ����������� ���
			if (drand(6) == 1 && !CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && sti(pchar.rank) < 10 && npchar.city != "Charles")
			{
				if (!CheckAttribute(npchar, "Device")) 
				{
					switch (crand(4))
					{
						case 0:  
							pchar.GenQuest.Device.Shipyarder.Type = "��������";
							pchar.GenQuest.Device.Shipyarder.Describe = "��� ������� �������, ����������� ��������, ������������ �� ������";
						break; 
						case 1:  
							pchar.GenQuest.Device.Shipyarder.Type = "�����";
							pchar.GenQuest.Device.Shipyarder.Describe = "����� �� ������� ������� ������ ������� � ������ ����������� �������";
						break; 
						case 2:  
							pchar.GenQuest.Device.Shipyarder.Type = "������";
							pchar.GenQuest.Device.Shipyarder.Describe = "��������� ����� �����, ������� �� ������������ ������";
						break; 
						case 3:  
							pchar.GenQuest.Device.Shipyarder.Type = "���������� �������";
							pchar.GenQuest.Device.Shipyarder.Describe = "��������, ��� ��� ���������� ����������� ������ �����, ����������� ����� �� �������, � ������ ������� ��������� ����������� ������ � ���������";
						break;
						case 4:  
							pchar.GenQuest.Device.Shipyarder.Type = "������";
							pchar.GenQuest.Device.Shipyarder.Describe = "����� �� ������� ���, ������ ���� � ���� ���������, ����������, � ��������� � ����� �����������";
						break; 
					}
					dialog.text = "�� ����� �������. ���� �����, �� ������� ��� ������. � ���� ��������� ����� ������ ������ ���������� - "+pchar.GenQuest.Device.Shipyarder.Type+". ������� ������ � ���� ���, � ���������� ����������� ��� - � ��������� ��� � ������ �� ������� ������. � ��� ���� � �� ���� ��������� ������� �������, ���������?\n� ��� ����� ������� - ��� ����� ������, ����� ���������, �� �����, � � � ������� ������������ �������. ���� ��� ������ �� �� ������� � ������ ��������. �����, �� ���������� ��������� ����, ������������� � ������, � ��� ������ ������� ���������� � ����� - ���� ������ �������� �� ��� ���������.";
					link.l1 = "������. � ��������. ������ ������� ���, ��� �������� ���� ���... ������.";
					link.l1.go = "Device";
					link.l2 = "��� ��� �� ���������.";
					link.l2.go = "Device_exit";
					SaveCurrentNpcQuestDateParam(npchar, "Device");
					break;
				}//<-- ��������� ����������� ���
			}
			dialog.text = "������ ������ � ���� ���.";
			link.l1 = "��� �������.";
			link.l1.go = "exit";
		break;
		
		case "Findship_exit":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Findship.Shipyarder");
		break;

		case "Exit_fight":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "Device_exit":
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
		break;
		
		//--> Jason ��������� ����� �������
		case "Findship":
			pchar.GenQuest.Findship.Shipyarder = "begin";
			pchar.GenQuest.Findship.Shipyarder.Name = GetFullName(npchar);
			pchar.GenQuest.Findship.Shipyarder.City = npchar.city;
			ReOpenQuestHeader("Findship");
			AddQuestRecord("Findship", "1");
			AddQuestUserData("Findship", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Findship.Shipyarder.City+"Gen"));
			AddQuestUserData("Findship", "sName", pchar.GenQuest.Findship.Shipyarder.Name);
			AddQuestUserData("Findship", "sShip", pchar.GenQuest.Findship.Shipyarder.ShipBaseName);
			SetFunctionTimerCondition("Findship_Over", 0, 0, 60, false);
			DialogExit();
		break;
		
		case "Findship_check":
			dialog.text = "�������! ���, ��� �� ��� ������ ����������. ��� ���� �������?";
			link.l1 = "����� ����� �� �����, ���������� '"+pchar.GenQuest.Findship.Shipyarder.ShipName+"'.";
				link.l1.go = "Findship_complete";
				break;
		
		case "Findship_complete":
			pchar.quest.Findship_Over.over = "yes";//����� ����������
			sld = GetCharacter(sti(pchar.GenQuest.Findship.Shipyarder.CompanionIndex));
			RemoveCharacterCompanion(PChar, sld);
			AddPassenger(PChar, sld, false);
			dialog.text = "��� ���� ������ - "+FindRussianMoneyString(sti(pchar.GenQuest.Findship.Shipyarder.Money))+". ������� �� ����������� ������. �� ��������� ����������� �� ���. �� ��������!";
			link.l1 = "�� ��������, " + npchar.name + ".";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Findship.Shipyarder.Money));
			AddQuestRecord("Findship", "3");
			AddQuestUserData("Findship", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Findship.Shipyarder.Money)));
			CloseQuestHeader("Findship");
			DeleteAttribute(pchar, "GenQuest.Findship.Shipyarder");
		break;
		//<-- ��������� ����� �������
		
		//Jason --> ��������� ����������� ���
		case "Device":
			pchar.GenQuest.Device.Shipyarder.Chance1 = rand(6);
			pchar.GenQuest.Device.Shipyarder.Chance2 = rand(3);
			pchar.GenQuest.Device.Shipyarder.Chance3 = rand(2);
			pchar.GenQuest.Device.Shipyarder.Chance4 = rand(4);
			pchar.GenQuest.Device.Shipyarder.Money = 12000+rand(8000);
			//���������� ��� ������� ��� ������ ������, ����� �� �������
			if (sti(pchar.rank) < 2) iType = SHIP_SCHOONER; 
			if (sti(pchar.rank) >= 2 && sti(pchar.rank) < 5) iType = SHIP_BRIGANTINE; 
			if (sti(pchar.rank) >= 5 && sti(pchar.rank) < 7) iType = SHIP_BRIG; 
			if (sti(pchar.rank) >= 7) iType = SHIP_CORVETTE + rand(makeint(SHIP_HEAVYGALEON - SHIP_CORVETTE)); 
			pchar.GenQuest.Device.Shipyarder.Bonus = iType;
			dialog.text = "��, �������, ���������� ��������� ��������. ��� "+pchar.GenQuest.Device.Shipyarder.Describe+". ���� ������ ������������ � ����� ����, ��� ��� ������ ��� ����� �����. ���� ������� ���������� - � ������ ������� ���.";
			link.l1 = "�������. ��������� � �������!";
			link.l1.go = "exit";
			pchar.GenQuest.Device.Shipyarder = "begin";
			pchar.GenQuest.Device.Shipyarder.Name = GetFullName(npchar);
			pchar.GenQuest.Device.Shipyarder.City = npchar.city;
			pchar.GenQuest.Device.Shipyarder.Nation = npchar.Nation;
			ReOpenQuestHeader("Device");
			AddQuestRecord("Device", "1");
			AddQuestUserData("Device", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Device.Shipyarder.City+"Gen"));
			AddQuestUserData("Device", "sName", pchar.GenQuest.Device.Shipyarder.Type);
			AddQuestUserData("Device", "sDesc", pchar.GenQuest.Device.Shipyarder.Describe);
			SetFunctionTimerCondition("Device_Over", 0, 0, 30, false);
		break;
		
		case "Device_complete":
			pchar.quest.Device_Over.over = "yes";//����� ����������
			dialog.text = "�� ������� ���! ��� �� � ��� ����������! � �� � ��� �������� �����-���� ������� ���� ����������.";
			link.l1 = "���, �������.";
			link.l1.go = "Device_complete_1";
		break;
		
		case "Device_complete_1":
			RemoveItems(PChar, "Tool", 1);
			dialog.text = "� ������� ��� �� ������ "+FindRussianMoneyString(sti(pchar.GenQuest.Device.Shipyarder.Money))+". �������, ��� ��������� ������� �� ���� �����.";
			link.l1 = "�������!";
			link.l1.go = "Device_complete_2";
		break;
		
		case "Device_complete_2":
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Device.Shipyarder.Money));
			ChangeCharacterComplexReputation(pchar,"nobility", 5); 
			AddCharacterExpToSkill(pchar, "Leadership", 100);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 100);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 100);//����������
			AddQuestRecord("Device", "10");
			AddQuestUserData("Device", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Device.Shipyarder.Money)));
			CloseQuestHeader("Device");
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance4) == 3)
			{
				dialog.text = "����� ����, � ���� ������� ��� �����������, � �������� �������������� �������������.";
				link.l1 = "���������! ������� ���������, � ����� �������� ��������.";
				link.l1.go = "Device_complete_3";
			}
			else
			{
			DialogExit();
			DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
			}
		break;
		
		case "Device_complete_3":
			iType = sti(pchar.GenQuest.Device.Shipyarder.Bonus);
			dialog.text = "� ������ ��� ������� �� �������� �� ���� ����� ������� - "+ GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(iType, "Name") + "Gen")) +". �� ��� ����� ��� ���� ��������� �����������, �� � ������������ ��� ����� ������ �������. ���� ��� ���������� ��� �����, � �� �������� ���� - �� ������ ��� ����������.";
			link.l1 = "���! �������, ������� ���������!";
			link.l1.go = "Device_complete_4";
			link.l2 = "�������, �� ���� ����� ��� ���������� ��� �������� ������� � ������ � ��� ���� �� �������.";
			link.l2.go = "Device_complete_5";
		break;
		
		case "Device_complete_4":
			iType = sti(pchar.GenQuest.Device.Shipyarder.Bonus);
			FillShipParamShipyard(NPChar, GenerateStoreShipExt(SHIP_TARTANE, NPChar), "ship1");
			FillShipParamShipyard(NPChar, GenerateStoreShipExt(SHIP_LUGGER, NPChar), "ship2");
			FillShipParamShipyard(NPChar, GenerateStoreShipExt(SHIP_LUGGER, NPChar), "ship3");
			FillShipParamShipyard(NPChar, GenerateStoreShipExt(iType, NPChar), "ship10");
			DialogExit();
			LaunchShipyard(npchar);
			DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
		break;
		
		case "Device_complete_5":
			dialog.text = "��, ��� ������. ��� ��� ������� � ����� �������!";
			link.l1 = "� ��� �����!";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "GenQuest.Device.Shipyarder");
		break;
		// <-- ��������� ����������� ���
		
		case "ShipLetters_6":
			pchar.questTemp.different.GiveShipLetters.speakShipyard = true;
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 0)
			{
				dialog.text = "�����-�� ��������� ! ���, ������� � ���� �� ���. �����, ��� ����� ����� � ���������� �����.";
				link.l1 = "����������....";
				link.l1.go = "exit";
			}
			else
			{
				sTemp = "�����-�� ���������, �������! ���! ��� �� ������� ��������� ����� �������� �����, ����� �������, ������ �������� �������. � ������, �� ����� ���������� ��� �������, � ���� �������� �����������.";
				sTemp = sTemp + "�����, ��� ���� ��� ���������� " + sti(pchar.questTemp.different.GiveShipLetters.price2) + " ���� �� ��� �����";
				dialog.text = sTemp;
				link.l1	= "�������, �� ����� ...";
				link.l1.go = "exit";
				link.l2 = "���������, " + GetFullName(NPChar) + "! ����������� ������ ������ �����.";
				link.l2.go = "ShipLetters_7";				
			}	
		break;

		case "ShipLetters_7":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price2)); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "4");		
			AddQuestUserData("GiveShipLetters", "sSex", GetSexPhrase("","�"));		
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
			dialog.text = "��, �������, ������� ��� �������! ��� ���? �������, �� ����������? �� ����� �����, ��� �������, ���������. ����� � � �� ������� �����? ����� ������ ��������... ����� �������, �������, � ��� ����� �� ������, ��� ���� � ���� ���� �� ����. ���! ��� ��� ��-������ ������� - ��� � ����, ���� ��...\n����, � ��� �� �� ���� �� ���������, ���� �� �� ������ � ���� ����� �� ������� � ����� �������������� ���������... �� �� ��� ����������... ��������� ������, �����... � �������.";
			link.l1 = "�������, �� ���� � ������ ���, �� � �� �� �������"+ GetSexPhrase("��","���") +" �� ��������...";
			link.l1.go = "EncGirl_3";
		break;
		
		case "EncGirl_3":
			dialog.text = "�� ��� �� ���������?.. � ��� ���� ���� ����? ����? ���, ����� ����� - ��������, ����� � ���������...\n��... � ������ �������������� ����, ��� �� ������ - ������� ����������.";
			link.l1 = "�������. � ������� �� ��������. ���-�� ��� ������������, ��� ��� �� ���� �� �����������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("EncGirl_ToLoverParentsExit");
		break;		
		
		case "EncGirl_4":
			if(sti(pchar.GenQuest.EncGirl.LoverFatherAngry) == 0)
			{
				dialog.text = "�, ��� �� � ���� "+ GetSexPhrase("��� �������, ������� ������","�� �������, ������� ��������") +", ����� �������� ���� � ������� ��������?";
				link.l1 = "��, ��� � �����"+ GetSexPhrase("","��") +" �� �������.";
				link.l1.go = "EncGirl_5";
			}
			else
			{
				dialog.text = "�-�, ����"+ GetSexPhrase("��, �����������","���, ���������������") +". ������ ������� �����?";
				link.l1 = "��, �� ��, ����� �������, �� ������������� �������� �� ������ ��.";
				link.l1.go = "EncGirl_6";			
			}
		break;
		
		case "EncGirl_5":
			dialog.text = "� ����� ��� ����������, ��� �� �������� ��� ���� � ��������������� ��������� � ������� ��� � ������ ����� �� ����� ���������� ��������. ��������� ������������� ���, ��� ����. ������� ��� �������� ����� � ������� �� ���� �����.";
			link.l1 = "��������� ���, ��� ���� ������� �������� ���� ������� �����.";
			link.l1.go = "EncGirl_5_1";
		break;
		
		case "EncGirl_6":
			dialog.text = "����� �������������?! �� ��� �������������?! ���� ����, ��� ���� ������� ��� ������� ��������� ��� ������, ��� ��� � ����������� ����� �����! �� � � ��� ���� ��� ���� ���� ������. � ��, ���, �����������! � �����������, ���, ����� �� �������, � ���� �������� �����-�� ������ ���������, ������ �������, � ������������� ������������� �����������!";
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
			dialog.text = "����� ����� �������?! � ����� �������� �� ��������? ��������, ����� �������, � ���� ��... �������! ������ ��� ������ ���� �������� � ����� ����� ��������, �� � ������ �����������. �������� �� ������������� ������ ������� � ����� ���������� ����� �������. �� ����� ��� ������� �������������. ��������.";
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
		
		case "shipyard":
            ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		    if (sti(Pchar.Ship.Type) == SHIP_NOTUSED || ok)
			{
			    NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
				LaunchShipyard(npchar);
			}
			else
			{
			    dialog.text = NPCharRepPhrase(npchar, pcharrepphrase("������ ����? � ��� �� ���� �������? � ����� ��� ���!",
				                                                     "������� ��������, ���� �� �������� ����! � ����� ��� ������ �������!"),
													  pcharrepphrase("� �� ���� ������ ������� � �����, ������� " +GetFullName(pchar)+ ". �������, ��� �� '������� ���������'?",
													                 "�������, ������� ������� ����� � �����. ������������ ������� � ���������."));
				link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"����� ������������!!! �����, ������ �������, ��� ��������!",
				                                                 "� �� �����"+ GetSexPhrase("","�") +" ��� �������� " +GetFullName(npchar)+ ", ������� �� ������ ������� �������."),
												  pcharrepphrase("���. ��� ������� ���������� Black Perl. ��� ��� �� �������? ��-��! �����!",
												                 "������� �� �����, ����������� �� ������������."));
			    link.l1.go = "exit";
			}
		break;
		
		case "Cannons":
            ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
			    NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
    			LaunchCannons(sti(rColony.StoreNum));
			}
			else
			{
			    dialog.text = NPCharRepPhrase(npchar, pcharrepphrase("������ ����? � ��� �� ���� �������? � ����� ��� ���!",
				                                                     "������� ��������, ���� �� �������� ����! � ����� ��� ������ �������!"),
													  pcharrepphrase("� �� ���� ������ ������� � �����, ������� " +GetFullName(pchar)+ ". �������, ��� �� '������� ���������'?",
													                 "�������, ������� ������� ����� � �����. ������������ ������� � ���������."));
				link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"����� ������������!!! �����, ������ �������, ��� ��������!",
				                                                 "� �� �����"+ GetSexPhrase("","�") +" ��� �������� " +GetFullName(npchar)+ ", ������� �� ������ ������� �������."),
												  pcharrepphrase("���. ��� ������� ���������� Black Perl. ��� ��� �� �������? ��-��! �����!",
												                 "������� �� �����, ����������� �� ������������."));
			    link.l1.go = "exit";
			}
		break;
		
		case "SailsGerald":
            ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
		    if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
			    dialog.text = "������� ���� ������� ����� " +
				              FindRussianMoneyString(GetSailsTuningPrice(Pchar, npchar, SAILSCOLOR_PRICE_RATE))+
							  ", ��������� ����� ���� ����� " +
							  FindRussianMoneyString(GetSailsTuningPrice(Pchar, npchar, SAILSGERALD_PRICE_RATE)) +
							  ", ������� ������ - ������� �� ����, ����� � ��� �������.";
							  
			    link.l1 = "������� ����� ����.";
			    link.l1.go = "SailsColorChoose";
			    link.l2 = "���������� ����� ����.";
			    link.l2.go = "SailsGeraldChoose";
				link.l3 = "���������� ���������� ������."; 
				link.l3.go = "SailsTypeChoose";
			    Link.l9 = "� ���������"+ GetSexPhrase("","�") +".";
				Link.l9.go = "exit";
			}
			else
			{
			    dialog.text = NPCharRepPhrase(npchar, pcharrepphrase("������ ����? � ��� �� ���� �������? � ����� ��� ���!","������� ��������, ���� �� �������� ����! � ����� ��� ������ �������!"),pcharrepphrase("� �� ���� ������ ������� � �����, ������� " +GetFullName(pchar)+ ". �������, ��� �� '������� ���������'?","�������, ������� ������� ����� � �����. ������������ ������� � ���������."));
				link.l1 = NPCharRepPhrase(npchar, pcharrepphrase("" +RandSwear()+"����� ������������!!! �����, ������ �������, ��� ��������!","� �� �����"+ GetSexPhrase("","�") +" ��� �������� " +GetFullName(npchar)+ ", ������� �� ������ ������� �������."), pcharrepphrase("���. ��� ������� ���������� Black Pearl. ��� ��� �� �������? ��-��! �����!","������� �� �����, ����������� �� ������������."));
			    link.l1.go = "exit";
			}
		break;
		
		case "SailsTypeChoose":
			dialog.text = "����� ������ ������? � ���� ������ " + GetSailsType(sti(RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails))+".";
            Link.l6 = "� ���� ��������� "+GetSailsType(6) + ".";
			Link.l6.go = "SailsTypeChooseIDX_6";
			Link.l7 = "� ���� ��������� "+GetSailsType(7)  + ".";
			Link.l7.go = "SailsTypeChooseIDX_7";
			Link.l8 = "� ���� ��������� "+GetSailsType(8)  + ".";
			Link.l8.go = "SailsTypeChooseIDX_8";
			Link.l9 = "� ���� ��������� "+GetSailsType(9)  + ".";
			Link.l9.go = "SailsTypeChooseIDX_9";
			Link.l10 = "� ���� ��������� "+GetSailsType(10)  + ".";
			Link.l10.go = "SailsTypeChooseIDX_10";
			Link.l11 = "� ���� ��������� "+GetSailsType(11)  + ".";
			Link.l11.go = "SailsTypeChooseIDX_11";
			attrLoc = "l" + sti(RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails);
			DeleteAttribute(Link, attrLoc);
		    Link.l99 = "� ���������"+ GetSexPhrase("","�") +".";
			Link.l99.go = "exit";
		break;
		
		case "SailsTypeChoose2":
            NPChar.SailsTypeMoney = GetSailsTypePrice(sti(RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails),
			                                          sti(NPChar.SailsTypeChooseIDX),
													  stf(NPChar.ShipCostRate),
													  sti(RealShips[sti(Pchar.Ship.Type)].Price));
													  
			dialog.text = "� ���� ������ "+GetSailsType(sti(RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails))+", �� ������ "+ GetSailsType(sti(NPChar.SailsTypeChooseIDX))+". ��������� ������ "+ FindRussianMoneyString(sti(NPChar.SailsTypeMoney)) +". ������?";

			if (sti(NPChar.SailsTypeMoney) <= sti(Pchar.Money))
			{
	            Link.l1 = "��.";
				Link.l1.go = "SailsTypeChooseDone";
			}
		    Link.l99 = "���.";
			Link.l99.go = "exit";
		break;
		
		case "SailsTypeChooseDone":
			AddMoneyToCharacter(Pchar, -sti(NPChar.SailsTypeMoney));
			dialog.text = "������������! ��� ������� � ������ ����.";
		    Link.l9 = "�������.";
			Link.l9.go = "exit";

			RealShips[sti(Pchar.Ship.Type)].ship.upgrades.sails = sti(NPChar.SailsTypeChooseIDX);
			WaitDate("",0,0,0, 1, 30);
		break;
		
		case "SailsColorChoose":
			if (GetSailsTuningPrice(Pchar, npchar, SAILSCOLOR_PRICE_RATE) <= sti(Pchar.Money))
			{
				dialog.text = "����� ���� ������? ���� " + FindRussianMoneyString(GetSailsTuningPrice(Pchar, npchar, SAILSCOLOR_PRICE_RATE)) + ".";
				for (i = 0; i < SAILS_COLOR_QUANTITY; i++)
				{
					if (CheckSailsColor(Pchar, i))
					{
						attrLoc = "l" + i;
						Link.(attrLoc) = SailsColors[i].name;
						Link.(attrLoc).go = "SailsColorIdx_" + i;
					}
				}
			    Link.l99 = "� ���������"+ GetSexPhrase("","�") +".";
				Link.l99.go = "exit";
			}
			else
			{
				dialog.text = "�������, ����� ������ �����.";
			    Link.l9 = "������.";
				Link.l9.go = "exit";	
			}
		break;
		
		case "SailsColorDone":
			AddMoneyToCharacter(Pchar, -GetSailsTuningPrice(Pchar, npchar, SAILSCOLOR_PRICE_RATE));
			dialog.text = "������������. ������ ������ � "+ GetStrSmallRegister(SailsColors[sti(NPChar.SailsColorIdx)].name) +" ����.";
		    Link.l9 = "�������.";
			Link.l9.go = "exit";
			
			SetSailsColor(Pchar, sti(NPChar.SailsColorIdx));
			WaitDate("",0,0,0, 1, 30);
		break;
		
		case "SailsGeraldChoose":
			if(GetSailsTuningPrice(Pchar, npchar, SAILSGERALD_PRICE_RATE) <= sti(Pchar.Money))
			{
				if(CheckSailsGerald(Pchar) && CanSetSailsGerald(PChar)) // Warship fix 04.06.09
				{
					NextDiag.CurrentNode = NextDiag.TempNode;
					DialogExit();
					LaunchSailsGeraldScreen(npchar);
				}
				else
				{
				    dialog.text = "� ���������, �� ���� ������� ������ ���������� ����.";
				    Link.l9 = "����.";
					Link.l9.go = "exit";
				}
			}
			else
			{
				dialog.text = "�������, ����� ������ �����.";
			    Link.l9 = "������.";
				Link.l9.go = "exit";	
			}
		break;

//--> -------------------------------------------����� ��������---------------------------------------------------
		case "Sharlie":
			dialog.text = "�������� ��� ��������, �����. � ���� �� ������ ������ ������ ��� �������� �� �������.";
			link.l1 = "��� ����� �������, ��� ��� ��� �������, ��� � ��� �� ����� ������ ���� ����� ��������� ����.";
			link.l1.go = "Sharlie_1";
		break;
		
		case "Sharlie_1":
			if (GetQuestPastDayParam("questTemp.Sharlie_ship") > 3)
			{
				dialog.text = "�� ��� ������ �������� ��� ��������� ����, �� ������� ���� ����� � ��� ������ ���� ������ �� �����? ��� ���� ������� ��� ������, ������ ��� �������� ��������, ������ ����� ������ ���� ���� ��������� �� �������, ��� �� ������ ����� ������ ������� �� ����\n��� ����� ������, ����� � ��� � �� ������, ������� ��������� ���� ��� ������. ��� ��� �� ����������, ������.";
				link.l1 = "��, ��� ��� ��������-�� �����... � ������� ������� � ��� ����� ���?";
				link.l1.go = "Sharlie_6";
			}
			else
			{
			dialog.text = "��. ��, �������������. ��...";
			link.l1 = "� �� ���� ������ ����� - ���� ����� ����. ������ �� �����, ������� ��� ������, �������� ��� ����� �� ���� ������� ���.";
			link.l1.go = "Sharlie_2";
			}
		break;
		
		case "Sharlie_2":
			int iDay = 3-sti(GetQuestPastDayParam("questTemp.Sharlie_ship"));
			sTemp = "� ��� �������� "+FindRussianDaysString(iDay)+"";
			if (iDay == 0) sTemp = "������� - ��������� ����";
			dialog.text = "��, ��� ����� ����, ����� ��������� ���� ������, �����. ��� �� ��������� ��������, ���� ������� �� ������� ���� ����� ����. �� ������ ��������� ������� � �������� � �������� ��� ������ ����, ������ � �����������. ��� ��� � ��� ��� ���������� ����� - � ������� ���\n������, �������� ��������, �� ������ ��������� ��� ������ �� �������, ��� ����� ������ ����� ������ ������� �� ����. "+sTemp+", ����� ���� � ���� ����� ������� ���� ������� ������� ����. ������, ���������� ��� ����, ��� ��� ��� ������� ������������.";
			if (sti(Pchar.money) >= 17000)
			{
				link.l1 = "������ ��� ���������� �� ����. � ���� ���� ������ ����� ����� ������. ���, �������.";
				link.l1.go = "Sharlie_4";
			}
			link.l2 = "������. ����� � ��� ��� ������, �����. � �� �������� ���� ����� �����.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Sharlie_3";
		break;
		
		case "Sharlie_3":
			if (CheckAttribute(pchar, "questTemp.Sharlie.Rum") || CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") || CheckAttribute(pchar, "questTemp.Sharlie.RescueDaughter"))
			{
				dialog.text = "�� ���-�� ������, �����?";
				Link.l1 = "� ������ ���������� �������, ����� � ��� ����... �� ������ � ������� ����� - ���� ���� ������������� ��������. � ��� ������� �������, ��� ������ ��������� � ���.";
				Link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.Sharlie == "ship" || pchar.questTemp.Sharlie == "ship_fast") // Addon 2016-1 Jason ��������� ������� 1
			{	
				if (GetQuestPastDayParam("questTemp.Sharlie_ship") > 3)
				{
					dialog.text = "�����, � �� ������������, ��� � ��� ����� ��� ���. ��� �������, ����� �� �� ��������, ������� ������� ����. � ������ ������� ������� ��������, ��� ��� �� ����������.";
					link.l1 = "��, ��� ��� ��������-�� �����... � ������� ������� � ��� ����� ���?";
					link.l1.go = "Sharlie_6";
				}
				else
				{
					dialog.text = "�� �������� ���������� �����, �����?";
					if (sti(Pchar.money) >= 17000)
					{
						link.l1 = "��, �������. ���, �������.";
						link.l1.go = "Sharlie_4";
					}
					else
					{
						link.l1 = "���, � ��� ������� ��� ����.";
						link.l1.go = "exit";
						NextDiag.TempNode = "Sharlie_3";
					}
				}
			}
		break;
		
		case "Sharlie_4":
			AddMoneyToCharacter(pchar, -17000);
			dialog.text = "����� ���������� ��� � ������� ��������. ������� ���. �����, �� �������� ��� ����� � �������.";
			link.l1 = "�������!";
			link.l1.go = "Sharlie_5";
		break;
		
		case "Sharlie_5":
			NextDiag.CurrentNode = "First time";
			DialogExit();
			pchar.questTemp.Sharlie.Ship = "lugger";
			pchar.questTemp.Sharlie = "crew";
			//��������� ��������
			pchar.Ship.Type = GenerateShipHand(pchar, SHIP_GAFELSLOOP, 6, 700, 25, 610, 16000, 15.2, 58.8, 1.11);
			SetBaseShipData(pchar);
			ResetShipCannonsDamages(pchar);
			SetShipCannonsDamagesNull(pchar);
			NullCharacterGoods(pchar);
			SetCrewQuantityOverMax(PChar, 0);
			AddCharacterGoods(pchar, GOOD_BALLS, 50);
			AddCharacterGoods(pchar, GOOD_GRAPES, 50);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 50);
			AddCharacterGoods(pchar, GOOD_BOMBS, 50);
			AddCharacterGoods(pchar, GOOD_POWDER, 220);
			pchar.Ship.name = "�������";
			pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
			AddQuestRecord("Sharlie", "6");
			bDisableFastReload = false;//������� �������
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			if (GetCharacterIndex("GigoloMan") != -1)
			{
				sld = characterFromId("GigoloMan");
				sld.lifeday = 0;
			}
			pchar.GenQuest.StoreGoods.StoreIdx = Fortfrance_STORE;
			pchar.GenQuest.StoreGoods.Starting = true; // ��������� �������
			bNoEatNoRats  = true; // �������� ��� � ����
		break;
		
		case "Sharlie_6":
			if (sti(Pchar.money) >= 15000)
				{
					dialog.text = "��. � �����-��, ����, �� ������ �� ����, ������� �� �� ���.";
					link.l1 = "������ ��� �� �� ��������. ��������, ��� ��� � ���?";
					link.l1.go = "Sharlie_7";
				}
				else
				{
					dialog.text = "����������, �����, �� ������� �������� �����������, � ����� � �������� �����������. �� ��������� ��� ��� ����� ������ �� �����������, �������, ��� �������?";
					link.l1 = "�������, ���� ������� ���� ����� � �� �����������. ������, � �������, ����� ����� ������.";
					link.l1.go = "exit";
					NextDiag.TempNode = "Sharlie_shipwait";
				}
		break;
		
		case "Sharlie_7":
			dialog.text = "����� ��������. ������� � �������� �� ������� ���� ����� ����. ��� ������ ��������� ��������, �� ������� ���������� ��� ������������ ��������� �� �������������� �����������. �������, ����� �����, �� ��, �� � ��������� ��������, �� � ���� ����� ������\n��� ������� �� ������ ���������� - ��� ��� ��������� ������ ���������� ��� ����� �����, ��� ��� ������ ������ ��� � ���� � ��� ���������, � ����� �� ����. �������� ���������, ������� ������� �������� - ���������� ����� ����, � ��� ������ � ���������� �����.";
			link.l1 = "� ��������. ������� - ��� ������ ����� � ����, � �� ��������� ����� ����� ������. ��� � ������ ���, ��� � ��� ��� �����������.";
			link.l1.go = "Sharlie_8";
		break;
		
		case "Sharlie_8":
			AddMoneyToCharacter(pchar, -15000);
			dialog.text = "����� ���������� � ��������. ������� ���. �����, �� ��� �������� ��� ����� � �������.";
			link.l1 = "�������!";
			link.l1.go = "Sharlie_9";
		break;
		
		case "Sharlie_9":
			NextDiag.CurrentNode = "First time";
			DialogExit();
			pchar.questTemp.Sharlie.Ship = "sloop";
			pchar.questTemp.Sharlie = "crew";
			//��������� ����
			pchar.Ship.Type = GenerateShipHand(SHIP_LIGHTSLOOP, 6, 450, 30, 450, 13000, 16.1, 64.1, 1.25);
			SetBaseShipData(pchar);
			ResetShipCannonsDamages(pchar);
			SetShipCannonsDamagesNull(pchar);
			NullCharacterGoods(pchar);
			SetCrewQuantityOverMax(PChar, 0);
			AddCharacterGoods(pchar, GOOD_BALLS, 51);
			AddCharacterGoods(pchar, GOOD_GRAPES, 39);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 54);
			AddCharacterGoods(pchar, GOOD_BOMBS, 36);
			AddCharacterGoods(pchar, GOOD_POWDER, 231);
			pchar.ship.HP = sti(pchar.ship.HP) - makeint(sti(pchar.ship.HP)/2);
			pchar.Ship.name = "������ ���";
			pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS3;
			AddQuestRecord("Sharlie", "6");
			bDisableFastReload = false;//������� �������
			DeleteAttribute(pchar, "GenQuest.CannotWait");//����� ������ �����
			if (GetCharacterIndex("GigoloMan") != -1)
			{
				sld = characterFromId("GigoloMan");
				sld.lifeday = 0;
			}
			pchar.GenQuest.StoreGoods.StoreIdx = Fortfrance_STORE;
			pchar.GenQuest.StoreGoods.Starting = true; // ��������� �������
			bNoEatNoRats  = true; // �������� ��� � ����
		break;
		
		case "Sharlie_shipwait":
			dialog.text = "��, �����, �� ���-���� ��������� � ��������?";
			if (sti(Pchar.money) >= 15000)
			{
				link.l1 = "��, �����, � ���� ���� ����������� ����� ��� ������� ���� ������-�� ���������� �������.";
				link.l1.go = "Sharlie_7";
			}
			else
			{
				link.l1 = "� ���� ��� ��� ����������� �����. ������ ����� ����������...";
				link.l1.go = "exit";
				NextDiag.TempNode = "Sharlie_shipwait";
			}
		break;
//<-- -----------------------------------------����� ��������-----------------------------------------------------
		// Addon-2016 Jason, ����������� ���������� (���) ���-���������
		case "FMQM_oil_1":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "goto", "goto5", "FMQM_Looking", -1);
			pchar.questTemp.FMQM = "remove_oil1";
		break;
		
		case "FMQM_oil_2":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FMQM_officer");
			sld.Dialog.currentnode = "officer_3";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
			pchar.questTemp.FMQM = "remove_oil2";
		break;
		
		case "FMQM_oil_3":
			DialogExit();
			LAi_SetActorType(npchar);
			sld = characterFromId("FMQM_officer");
			sld.Dialog.currentnode = "officer_5";
			LAi_SetActorType(sld);
			LAi_ActorDialogNow(sld, pchar, "", -1);
			pchar.questTemp.FMQM = "remove_oil3";
		break;
		
		case "FMQM_oil_4":
			dialog.text = "���, ���������, �� ��� �� � ���� �������� ���. ����� ������������, � � �������� ������� ����������� �����, ���� ���������� �� ������. � ������ ������ ��� ������� �������� ���������? ���������, ���-�� �� ���� ���������� ���������� � �����. �� � � ���� ��� ���������, � ���� ����� ������� - ���� ��� �� ���������!";
			link.l1 = "������, ��� ��� �������� ���� ��������...";
			link.l1.go = "FMQM_oil_5";
		break;
		
		case "FMQM_oil_5":
			dialog.text = "��� ����� ����, �������. �� ��� �� ������ ������� - ��� ������������ ������.";
			link.l1 = "����. �����, ������, ����� � �����. ����� �������!";
			link.l1.go = "FMQM_oil_6";
		break;
		
		case "FMQM_oil_6":
			DialogExit();
			AddQuestRecord("FMQ_Martinique", "12");
			pchar.questTemp.FMQM = "officer";
			pchar.quest.FMQM_advice.win_condition.l1 = "location";
			pchar.quest.FMQM_advice.win_condition.l1.location = "FortFrance_town";
			pchar.quest.FMQM_advice.function = "FMQM_GuideAdvice";
			DeleteAttribute(pchar, "questTemp.FMQM.Oil");
		break;
		
		// Addon 2016-1 Jason ��������� �������
		case "mtraxx_x":
            dialog.text = "� �� ����� ��������� � ������ ���������. � ����� ������������ ��� ����� ������� ������ �� ������ ��� ����� ������... ����� ������� ������ � ����... ���� �� ������������ ��� ������ ��������... ������ �����...";
			link.l1 = "������, �� ����� ������. � ������� ���, ��� � �� �����, � �� ������� ���������� �����. ����� ���� - � ������� � �������� ��������, � ��� ��� ��������� ��� ���-�� �� � �������. ������� ������� ���������. � ����, ��� ��� ��������� ����� ����������� ����, � ������ ������ ����� ��� ��� ����������. ���� ���������. ������ ������ � ��� ������, ���� �� �������� � ����. ��� ��� ������� ������� �������� ������, ������.";
			link.l1.go = "mtraxx_x_1";
		break;
		
		case "mtraxx_x_1":
            dialog.text = "������. ��� ��� ����� �������� ������ - ��� � ������, ���� �� ������� �����, ��� �� �������, ���� ������ �� ����� ������� ������ �����. � ����� ������� �� ���� �������, �� 25 �������� �� �����. �� ��� ��� ����� ������� ������, �� 100 ������� ��� ����� ����.";
			link.l1 = "����� ���� ���� ����������. �����, ������ ������ ���������� ������ �� ����� 100 ������� ����������.";
			link.l1.go = "mtraxx_x_2";
		break;
		
		case "mtraxx_x_2":
            dialog.text = "��� ���� �� ������ ������������! ������ ������ � ����� ������� ���� �������.";
			link.l1 = "������� �� ���������, � ��� � ��������� ����� - �����. ����� � ������� ����� � �����������. � ������ �������� ���� � �������� ��� � ���. ��� �������� ����������?";
			link.l1.go = "mtraxx_x_3";
		break;
		
		case "mtraxx_x_3":
            dialog.text = "������� ������� ���. ������ �����, ����� 10 � 15 ������, �� �����, ��� ���� ����� ����� ����� ������� � �����... ���, ����� �� ���� ������. ������, �������, �� � �������� ��������... ������ - '�������� �����'.";
			link.l1 = "�� �����, ������. �� ����� ������ ������� - � ������� � �����������, ���������� ��� ������ ������.";
			link.l1.go = "mtraxx_x_4";
		break;
		
		case "mtraxx_x_4":
            dialog.text = "�������, ���� ����� �������� � ����. ��� ��������������� �� ������� �����.";
			link.l1 = "�� ������������, ��� ����� � �������. ����� �������!";
			link.l1.go = "mtraxx_x_5";
		break;
		
		case "mtraxx_x_5":
			DialogExit();
            AddQuestRecord("Roger_2", "21");
			pchar.questTemp.Mtraxx = "silk_10"; // ���������� ������
			sld = characterFromId("Jeffry");
			sld.DeckDialogNode = "Jeffry_9";
		break;
	}
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
			if (GetCharacterIndex(colonies[n].id + "_shipyarder") != -1)
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

