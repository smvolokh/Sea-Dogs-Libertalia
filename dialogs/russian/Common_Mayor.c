// boal 25/04/04 ����� ������ ����
#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref aData;
	aref Link, NextDiag, arName;

	DeleteAttribute(&Dialog,"Links");

	ref FortChref; // �������� ��������
	ref arItem;
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Mayor\" + NPChar.City + "_Mayor.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
    ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06

    FortChref = GetFortCommander(NPChar.City); // ����� ��� �������� ��� ��� ����������

    ref offref;
    int i, cn, iRank, iDay;
    int qty;
    int iSumm;
    string attrLoc, QuestName, sTemp;
	bool   bOk;
	
    if (CheckNPCQuestDate(npchar, "Card_date"))
	{
		SetNPCQuestDate(npchar, "Card_date");
		npchar.money = 5000 + (rand(10)+1) * makeint(100 * sti(PChar.rank) * (10.0 / MOD_SKILL_ENEMY_RATE));
	}
	// ��������� ��� �� ����� -->
	attrLoc   = Dialog.CurrentNode;
  	if (findsubstr(attrLoc, "GetPrisonerIdx_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	pchar.GenQuest.GetPrisonerIdx = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "sell_prisoner_2";
 	}
 	// ��������� ��� �� ����� <--
 	
	switch (Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOff");
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
		
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
            NextDiag.TempNode = "First time";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("�� ������� ������� � �����������?! ������ ���...", "��� ��� ����������� ���������, ����� �� ��� �������� ����?! ��� �����������...", "�� ��, ��� ������ ��������� �����, ��� "+ GetSexPhrase("�����-�� ����������","�����-�� �����������") +" ������ � ���� ����������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��� ������� ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����","") +"!", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ���� ����������! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� ������� � �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("�������� ���� ���� �����...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "��� ��� � ���� �����, ��������: ���� ����, � ������ ����..."));
				link.l1.go = "fight";
				break;
			} 
			if (sti(NPChar.nation) == PIRATE)
            {
				if (CheckAttribute(pchar, "GenQuest.CaptainComission") && CheckAttribute(pchar, "GenQuest.CaptainComission.PiratesCity") && NPChar.city == pchar.GenQuest.CaptainComission.PiratesCity)
				{
					dialog.text = "��� ���� �����?";
					link.l1 = "����� ���������� � ���� �� ����� ����.";
					link.l1.go = "quests";
					break;
				}
				if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "cabin" && NPChar.city == "LeFransua")
				{
					dialog.text = "��� ���� �����?";
					link.l1 = "����� ���������� � ���� �� ����� ����.";
					link.l1.go = "quests";
					break;
				}
					dialog.text = "��� �� � ��� ��������, � �����.";
					link.l1 = "�� � �����.";
					link.l1.go = "Exit";
            }
			if (sti(NPChar.nation) != PIRATE && ChangeCharacterHunterScore(Pchar, NationShortName(sti(NPChar.nation)) + "hunter", 0) > 10)
            {
				iTotalTemp = ChangeCharacterHunterScore(Pchar, NationShortName(sti(NPChar.nation)) + "hunter", 0);
                dialog.text = "�! ��� ������! ��� �� ���"+ GetSexPhrase("","�") +" " + GetFullName(pchar) + ". �� ��� ��� ������� �������� ��������� �� ��������, ����� ��� ������� ��� ����. � ������, ��� ��� ������ ��� � ����������� �����.";
                if (sti(pchar.Money) >= iTotalTemp*6000)
                {
                    link.l1 = "� ��� ��� ���� ������� ���� �����������.";
				    link.l1.go = "arestFree_1";
                }
				link.l2 = "�... �������, ��� ����.";
				link.l2.go = "arest_1";
				break;
            }
			if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
    			dialog.text = "���� � ����������! �������!!";
				link.l1 = "�-���, ������!";
				link.l1.go = "fight"; 
				break;
			}			
			//--> Jason, ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie.Citcount") && npchar.city == "FortFrance")
			{
    			dialog.text = "��� ��� ������, �����?";
				link.l1 = "������������, ���� ���������. � ���������� ������ �� �����. �� ����� �� �� ��������������� � ���� �������?";
                link.l1.go = "Sharlie";
				npchar.quest.meeting = "1"; // patch-6
				break;
			}
			
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock") && npchar.city == "FortFrance")
			{
				if (CheckAttribute(pchar, "questTemp.Sharlie.Pardon"))
				{
					dialog.text = "�, ��� ��, �����... ������, � ������ ���������� �� ��, ��� ��� ����� � ���� ��������. �� ������� � ���� ����, � �������� � ����� ������������ ������������...";
					link.l1 = "�������, ���� ���������. � ����� ������, �� �����������.";
					link.l1.go = "Sharlie_2";
				}
				else
				{
					dialog.text = "�� ���-�� ������, "+pchar.name+"?";
					link.l1 = "� ���� � ��� ���� ������...";
					link.l1.go = "quests";
					link.l2 = "�� ���, ������.";
					link.l2.go = "exit";
				}
				npchar.quest.meeting = "1"; // patch-6
				break;
			}			
			//<-- ����� ��������

			// Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria.Governor") && npchar.city == "Marigo")
			{
    			dialog.text = "��� ��� ������, �������� ����������. ��� ���� ����? �� ����-�������� �� ��� ���������.";
				link.l1 = "� ������� ���������. ���, ��� � ��� �� � �������.";
				link.l1.go = "exit";
				link.l8 = "�����, �� ������ ������� ����������� �� ������ ���? ���� ���������� �������� ����� �� �����.";
				link.l8.go = "Play_Game";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Patria.GenGovernor") && npchar.nation == FRANCE)
			{
    			dialog.text = "��� ��� ������, �������� �������-����������! � ���� ������� �� ������ ������������! ���������, � ������ ������� ������� �� ����...";
				link.l1 = "�� ����. � ������� ���������. ���, ��� � ��� �� � �������.";
				link.l1.go = "exit"; 
				link.l8 = "�����, �� ������ ������� ����������� �� ������ ���? ���� ���������� �������� ����� �� �����.";
				link.l8.go = "Play_Game";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Patria.GenGovernor"))
			{
    			dialog.text = "�, ����� � ��� �����! ����� �������-���������� ����������� �������! ���� ��������, ���� ���������? ��������������, � ������� ������ �������� ���� � �������.";
				link.l1 = "�� �������� ������������, ��� ����� ����������, � �� ���, ������� ���� �������, �� ����� � ���.";
				link.l1.go = "exit"; 
				link.l8 = "�����, �� ������ ������� ����������� �� ������ ���? ���� ���������� �������� ����� �� �����.";
				link.l8.go = "Play_Game";
				break;
			}		

			
			//--> Jason, ����������
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "MartiniqueGovernor" && npchar.city == "FortFrance")
			{
    			dialog.text = "�, ��� � ��, �������! �� ������� �� �� �������, ������ ��������.";
				link.l1 = "� ������ ��� ������ �� �����������, ���� ������������������. ��� �������� ���-�� � ���������� ����, � ���� ������� ��� ������?";
				link.l1.go = "Portugal"; 
				break;
			}			
			//<-- ����������
            
            if (npchar.quest.meeting == "0")
			{
				dialog.text = "� ������, ��� �� ����� ���������� ������� ���������. ���� ����� " + GetFullName(npchar) +
                              ". � ���������� ������ "+ GetCityName(NPChar.city) + " ���������� " + NationKingsName(npchar)+
                              ". � ������ ������������� �������� ���� ������ ������, " + GetAddress_Form(NPChar) + ".";
				link.l1 = "��� ��� " + GetFullName(pchar) + ".";
				link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}
			else
			{
               	//����� homo
				if (CheckAttribute(Colonies[FindColony(npchar.City)],"Siege"))
                {

                    makearef(aData, NullCharacter.Siege);
                    
                    if (CheckAttribute(aData, "HelpColony") && sti(aData.HelpColony) == true )
                    {
                        dialog.text = "�� ����� �� ��� ��������, �� ��� ��?";
                        link.l1 = "�� ����� - �� ����� ��� ����� �����������.";
                        link.l1.go = "exit";

                    }
                    else
                    {
                        dialog.text = "������ ��� ��������, �� � ������ ������ � ���� ��� �������, ����� ������� ���. ��� ��, ��������, ��� ������, �� ���� ������� ������ "+NationNamePeople(sti(aData.nation))+". � ��� ���������� ������������ ������� ������.";
                        link.l1 = "��� � ��� ��� �����"+ GetSexPhrase("","�") +" ���������� ���� ������ � ������� �����.";
                        link.l1.go = "siege_task";
                        link.l2 = "����� �� ����� ��� ����� �����������.";
            			link.l2.go = "exit";
                    }
                }
                else
                {//->
                    makearef(aData, NullCharacter.Siege);
                    if (CheckAttribute(aData, "PlayerHelpMayor") && sti(aData.PlayerHelpMayor) == true
                    && CheckAttribute(aData, "HelpColony") && sti(aData.HelpColony) == true )
                    {
                        AddMoneyToCharacter(Pchar,(sti(aData.iSquadronPower)*1500));
                        ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
                        ChangeCharacterComplexReputation(pchar,"nobility", 10);
                        AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 80);
                        AddCharacterExpToSkill(GetMainCharacter(), "Sailing", 100);
                        AddCharacterExpToSkill(GetMainCharacter(), "Accuracy", 100);
                        AddCharacterExpToSkill(GetMainCharacter(), "Cannons", 100);
                        //--> �����
                        SiegeRumour("������������, ��� �� ������� ��� �������� �� "+NationNameSK(sti(aData.nation))+"�� ������� - � �������� ���� �������! �� ��� ���������� ���, "+ GetAddress_Form(NPChar)+".", aData.Colony, sti(aData.conation), -1, 15, 3);
			            //<-- �����
                        DeleteAttribute(aData, "PlayerHelpMayor");
                        DeleteAttribute(aData, "HelpColony");
                        dialog.text = "��, ��� ��, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+", ��� ��� ������. ������ ����� ��� ����� ������� - �� �������� �� "+NationNameSK(sti(aData.nation))+"�� �����������. � ���� ���� � ���� �������, ��� ���� ������� "+(sti(aData.iSquadronPower)*1500)+" ����. �������� ��������.";
                        link.l1 = "�������, " + GetAddress_FormToNPC(NPChar) + ", ������� ����� � ���� ����!";
                        link.l1.go = "exit";
                    }
                    else
                    {
   						//--> ���� ������ ����� ������ � �������
						if (rand(4) == 4 && pchar.questTemp.different == "free" && GetNpcQuestPastDayWOInit(npchar, "questTakeRing") > 365 && sti(pchar.questTemp.HorseQty) > 10)
						{// Addon-2016 Jason
							if (npchar.city == "Bridgetown" || npchar.city == "Charles" || npchar.city == "FortFrance" || npchar.city == "Marigo" || npchar.city == "Panama" || npchar.city == "PortRoyal" || npchar.city == "SantoDomingo" || npchar.city == "Tortuga" || npchar.city == "Roseau")
							{
        						dialog.text = "����������, � ���� ���� � ��� ����, ��.. ��������� ���������� �������.";
								link.l1 = "������ ��� �����������.";
        						link.l1.go = "TakeRing_1";
								SaveCurrentNpcQuestDateParam(npchar, "questTakeRing");
								break;
							}
						}
						//<-- ���� ������ ����� ������ � �������    				
						dialog.text = RandPhraseSimple("�, ��� ����� ��? �� ������ ������� �� ���� ���?","����� ��������� ���� �� ��� ���������� �������? ��� ��� ������, "+GetAddress_Form(NPChar)+"?");
						if (npchar.city != "Panama") // Addon-2016 Jason
						{
							link.l1 = "� ���� ���������� � ������ �� ����� ������ "+ NationNameGenitive(sti(NPChar.nation))+".";
							link.l1.go = "work";
						}
						// Warship ����� "������ �� ����������" - ����� ������� �������
						if(CheckAttribute(PChar, "Quest.PiratesOnUninhabited_OnShore") || CheckAttribute(PChar, "Quest.PiratesOnUninhabited_ShipSink"))
						{
							link.l11 = XI_ConvertString(PChar.GenQuest.PiratesOnUninhabited.StartShore + "Dat") + " � ��������"+ GetSexPhrase("","�") +" �������. ��� " + PChar.GenQuest.PiratesOnUninhabited.PiratesCount + " ������� ������ � ���� �� �����. ���� ����� �� �������.";
							link.l11.go = "PiratesOnUninhabited_1";
						}
						
        				link.l2 = "����� ���������� � ���� �� ����� ����.";
						if(CheckAttribute(pchar,"questTemp.ReasonToFast") && !CheckAttribute(pchar,"questTemp.ReasonToFast.SpeakOther") && !CheckAttribute(pchar, "questTemp.ReasonToFast.cantSpeakOther") && (pchar.questTemp.ReasonToFast.city == NPChar.city))
						{
							link.l2.go = "ReasonToFast_Mayor1";
						}
						else
						{
							link.l2.go = "quests";   //(���������� � ���� ������)
						}	
						if(CheckAttribute(pchar,"GenQuest.CaptainComission") && (pchar.GenQuest.CaptainComission.variant == "A2") && (pchar.GenQuest.CaptainComission.City == NPChar.city))
						{
							if(pchar.GenQuest.CaptainComission == "Begin_1" && !CheckAttribute(pchar,"GenQuest.CaptainComission.SpeakMayor")) 
							{
								link.l12 = "� ��� ��������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " ������ ����� " + pchar.GenQuest.CaptainComission.Name + ", ��� � ���� � ��� ����������?";
								link.l12.go = "CapComission_Mayor1";
							}	
							if(CheckAttribute(pchar,"GenQuest.CaptainComission.PrisonFree"))
							{
								link.l12 = "������ ������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " " + pchar.GenQuest.CaptainComission.Name + " ���������� ������� ���� ������ �������.";
								link.l12.go = "CapComission_Mayor9";
							}
							if(pchar.GenQuest.CaptainComission == "GetGoodsSuccess")
							{
								link.l12 = "������ ������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " " + pchar.GenQuest.CaptainComission.Name + " ������ ��� ���� ������.";
								link.l12.go = "CapComission_Mayor13";
							}
						}
						if(CheckAttribute(pchar,"GenQuest.ShipWreck") && pchar.GenQuest.ShipWreck == "SailorsOnShore" && GetQuestPastDayParam("GenQuest.ShipWreck") < 25  && sti(npchar.nation) == sti(pchar.GenQuest.ShipWreck.Nation))
						{
							if(!CheckAttribute(pchar,"GenQuest.ShipWreck.SpeakMayor"))
							{
								iDay = GetQuestPastDayParam("GenQuest.ShipWreck");
								if(CheckAttribute(pchar, "GenQuest.ShipWreck.Mutiny"))
								{
									link.l13 = UpperFirst(XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat")) + " � ��������" + GetSexPhrase("","�") + " �������� " + pchar.GenQuest.ShipWreck.Name + " � ��� �������, ���������� �� ����� ������� " + pchar.GenQuest.ShipWreck.BadName + ". " +
										"� ���������, �������� ������� �� ��� ����� �� �������� ����� �� �� ����. �� � �������" + GetSexPhrase("","�") + " �� �������� � ������. ���� �������������� ����� �� ������ ������� �� � ������� " + (30 - iDay) + " ����, �� �� ����, ������� �� ������� �� ������.";
									link.l13.go = "ShipWreck1";
								}
								else
								{
									link.l13 = UpperFirst(XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat")) + " � ��������"+ GetSexPhrase("","�") +" ������� �� ������������ �������� ����� '" + pchar.GenQuest.ShipWreck.ShipTypeName + "' �� ����� � �� ���������. " + 
										"� ���������, �������� ������� �� ��� ����� �� ��������� ����� �� �� ����. �� � �������" + GetSexPhrase("","�") + " �� �������� � ������. ���� �������������� ����� �� ������ ������� �� � ������� " + (30 - iDay) + " ����, �� �� ����, ������� �� ������� �� ������.";
									link.l13.go = "ShipWreck1";							
								}
							}	
						}
        				if (GetPrisonerQty() > 0)
        				{
                            link.l3 = "��� ����� ����� �������� �������� �������.";
        				    link.l3.go = "sell_prisoner";
        				}
        				if (npchar.Default  == npchar.location) // ���� �� � ������
        				{
        					if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
        					{
        						link.l4 = "��� ����� ��������� � ���� ��� ���������� ��������.";
        						link.l4.go = "LoanForAll";//(���������� � ��������� ���������)
        					}
        				}
						//-->> ����� ���������� � ������� ������
						if (CheckCharacterItem(pchar, "MayorsRing"))
						{
							if (pchar.questTemp.different.TakeMayorsRing == "toBrothel")
							{
        						link.l5 = "��� ������� ����� ���� ������. ��� ���.";
        						link.l5.go = "TakeRing_S1";
							}
							else
							{
        						link.l5 = "���� ����������� ������ � ����. ��� ���������, �� �������� ��� ����� �� ���������� �����.";
        						link.l5.go = "TakeRing_S3";
							}
						}
						//<<-- ����� ���������� � ������� ������ 
						
						//--> Jason, ����� ��������� ������� 2 ������
						if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.LevelUp"))
						{
							if (pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
							{
							link.l14 = "� �������� ��� ������ �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+".";
							link.l14.go = "Postcureer_LevelUp_ForAll";
							}
						}
						//<-- ����� ��������� ������� 2 ������
						
						// Warship, 16.05.11. ����� "���������� �� �������" -->
						if(CheckAttribute(PChar, "GenQuest.JusticeOnSale.MayorWait") && CheckAttribute(PChar, "GenQuest.JusticeOnSale.CityId") && NPChar.location == PChar.GenQuest.JusticeOnSale.CityId + "_townhall")
						{
							link.l15 = UpperFirst(GetAddress_FormToNPC(NPChar)) + ", � ���������" + GetSexPhrase("", "�") + " ����� ���������������, ����� ������� ������� ������� ������. ��� ��������� ��������� ���. �� ������� '" + PChar.GenQuest.JusticeOnSale.ShipName + "' ����� " + XI_ConvertString(PChar.GenQuest.JusticeOnSale.ShoreId + "Dat") + ".";
							link.l15.go = "JusticeOnSale_1";
						}
						
						if(CheckAttribute(PChar, "GenQuest.JusticeOnSale.ShipSink") && CheckAttribute(PChar, "GenQuest.JusticeOnSale.CityId") && NPChar.location == PChar.GenQuest.JusticeOnSale.CityId + "_townhall")
						{
							link.l15 = UpperFirst(GetAddress_FormToNPC(NPChar)) + ", ����� ��������������� ���� ����������!";
							link.l15.go = "JusticeOnSale_7";
						}
						// <--���������� �� �������
						//Jason --> ������
						if (CheckAttribute(pchar, "questTemp.Regata.ToPortRoyal") && NPChar.location == "Portroyal_townhall")
						{
							link.l16 = "� ������" + GetSexPhrase("", "�") + " ��� ������� � ������. ��� �� �����������.";
							link.l16.go = "Regata";
						}
        				link.l8 = "�����, �� ������ ������� ����������� �� ������ ���? ���� ���������� �������� ����� �� �����.";
        			    link.l8.go = "Play_Game";
        				link.l10 = "����� �������� ����, �� ���� ���� ����.";
        				link.l10.go = "exit";
                    }
                }//<-
			}
		break;
		
		// Warship ����� "������ �� ����������"
		case "PiratesOnUninhabited_1":
			offref = CharacterFromID("PirateOnUninhabited_0");
			qty = makeint(sti(PChar.GenQuest.PiratesOnUninhabited.PiratesCount) * (sti(offref.rank) * (800 + GetCharacterSPECIALSimple(NPChar, SPECIAL_L) * 100) + GetCharacterSkillToOld(offref, "Leadership") * 500 + GetCharacterSkillToOld(PChar, "commerce") * 500) / 20);
			
			PChar.GenQuest.PiratesOnUninhabited.MoneyForPirates = qty;
			
			dialog.text = "����� ���������� �������. ��� ����������� �������� � ����� �������� � ���� ��������. � ���������� �������� �� ���� ������. ������ �������, ��� �� �����, ��� ����� ������ ��� ����� ��������� �� ��������. ��, � ��� ���������� �������������� " + FindRussianMoneyString(qty) + ".";
			link.l1 = "�������, ���� ���������. ������ ���"+ GetSexPhrase("","�") +" �������. ";
			link.l1.go = "PiratesOnUninhabited_2";
			link.l2 = "���. �� ������.";
			link.l2.go = "exit";
		break;
		
		case "PiratesOnUninhabited_2":
			offref = CharacterFromID("PirateOnUninhabited_0");
			
			AddMoneyToCharacter(PChar, sti(PChar.GenQuest.PiratesOnUninhabited.MoneyForPirates));
			
			RemovePassenger(PChar, offref);
			RemoveCharacterCrew(PChar, sti(PChar.GenQuest.PiratesOnUninhabited.PiratesCount) - 1);
			
			sTemp = "PiratesOnUninhabited" + PChar.GenQuest.PiratesOnUninhabited.StartShore;
			AddQuestRecordEx(sTemp, "PiratesOnUninhabited", "12");
			AddQuestUserData(sTemp, "sSex", GetSexPhrase("","�"));
			AddQuestUserData(sTemp, "mayorName", GetFullName(NPChar));
			CloseQuestHeader(sTemp);
			
			PChar.Quest.PiratesOnUninhabited_OnShore.over = "yes";
			PChar.Quest.PiratesOnUninhabited_OnMayak.over = "yes";
			
			if(CheckAttribute(PChar, "Quest.PiratesOnUninhabited_ShipSink"))
			{
				PChar.Quest.PiratesOnUninhabited_ShipSink.over = "yes";
				
				PChar.GenQuest.PiratesOnUninhabited.ClearShip = true;
				Map_ReleaseQuestEncounter("PiratesOnUninhabited_BadPirate"); // ������� � ��������
			}
			
			DeleteAttribute(PChar, "GenQuest.PiratesOnUninhabited");
			
			DialogExit();
		break;
		
		// ------------------------- ����� ��� ������ -----------------------------
		case "ReasonToFast_Mayor1":
			dialog.text = "� ����������� ������ ���, �������.";
			link.l1 = "� ���� �������� � ���������� ������� ������� ������ ��������� � �������... (�������� �������������� ����)";
			if(sti(pchar.reputation.nobility) < 41)
			{
				link.l1.go = "ReasonToFast_BMayor";			
			}
			else
			{
				link.l1.go = "ReasonToFast_GMayor";	
			}
			pchar.questTemp.ReasonToFast.SpeakOther = true;			
		break;
		
		case "ReasonToFast_GMayor":
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_1") 
			{ 
				// �����_�
				dialog.text = "��������� ���, �����"+ GetSexPhrase("�","���") +"! � ���������� ����� ������ ��������� �������\n������ �� ������� �����������, � ������������� �����, ���, �����...";
				link.l1 = "���� ���������! � �����"+ GetSexPhrase("","�") +" ��� �� ���� �����...";
				link.l1.go = "ReasonToFast_GMayor_11";				
				if(pchar.questTemp.ReasonToFast.chain == "A0") ReasonToFast_RemoveVictim();
				if(pchar.questTemp.ReasonToFast.chain == "A1") pchar.quest.ReasonToFast_ClearLakey.over = "yes";
			}			
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_2") 
			{ 
				// �������� �����
				dialog.text = "��������� ���, �����"+ GetSexPhrase("�","���") +"! � ���������� ����� ������ ��������� �������\n������ ���������! �� ������ ��������� ��� ������� ������� �� ����������� ������. ��� ������, ��� �� �����������, � �� ����� ������ �������!";
				link.l2 = "������ ��� ��������� ��������������...";
				link.l2.go = "ReasonToFast_GMayor_21";			
			}
			if(pchar.questTemp.ReasonToFast == "PatrolDied") 
			{ 
				// ������� �������
				dialog.text = "�����"+ GetSexPhrase("�","���") +"! �� ����� �����������, ��� ���� ������ � ���������� ��� ����� ������� �� ����, �� ��� �������, ��� �� ��������� �����������, ������������ � ���� ��� ����������.";
				link.l3 = "���� ���������! �� � ��������"+ GetSexPhrase("","�") +" ��� �������� ���� �����...";
				link.l3.go = "ReasonToFast_GMayor_31";
				pchar.questTemp.ReasonToFast.speakAfterPatrolDied = true;	
				pchar.quest.ReasonToFast_SpeakMayor.over = "yes";
			}			
		break;
		
		case "ReasonToFast_BMayor":
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_1") 
			{ 				
				dialog.text = "�������, �� ���� ���������, �� ��� ���������?!! �� ������ ������ �������� ������������ ��� �������! � �� ���� ����������� ������� ������� ������ ������� � ��������� " + GetName( NAMETYPE_MAIN, pchar.questTemp.ReasonToFast.p3, NAME_GEN) + " � ��� ������ �� ��� ���� ������������! �����, �� ������ ����������, ����� ������� � ������ ���������� ������� ������� ��� ����������� ���� ��������?!!";
				link.l1 = "���� ���������! �� ������������� ������ ���� �������������...";
				link.l1.go = "ReasonToFast_BMayor_1";
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_A";				
				if(pchar.questTemp.ReasonToFast.chain == "A0") ReasonToFast_RemoveVictim();
				if(pchar.questTemp.ReasonToFast.chain == "A1") pchar.quest.ReasonToFast_ClearLakey.over = "yes";
			}
			if(pchar.questTemp.ReasonToFast == "PatrolSuccess_2") 
			{ 
				// �������� �����
				dialog.text = "�����-�� ��������� �� ��� �����...\n�� ���� ���� �����������? ���� ������� ������ ���������� � ��������������?";
				link.l2 = "���� ���������! �� ������������� ������ ���� �������������...";
				link.l2.go = "ReasonToFast_BMayor_1";
				TakeItemFromCharacter(pchar, "mapQuest");				
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_B";
			}
			if(pchar.questTemp.ReasonToFast == "PatrolDied") 
			{ 
				// ������� �������
				dialog.text = "������������ ���������� ������ ������ ����������� ������. �� ��� �, �� ������� ����, ����� ����, �� �������� ��� �� ������������� ������ ������.";
				link.l3 = "���� ���������! �� ������������� ������ ���� �������������...";
				link.l3.go = "ReasonToFast_BMayor_1";			
				pchar.questTemp.ReasonToFast = "speakSuccess_chain_A";
				pchar.quest.ReasonToFast_SpeakMayor.over = "yes";
			}		
		break;
		
		case "ReasonToFast_GMayor_11":
			dialog.text = "��� �� �����, � ����, ����� ���� ����� ���� �������������. ���, �������� �����, ��������� � ����� ������� ���������� �������� ����������. ��������, ��� ���������� �������, �� ������������� ���������� ���������, ���� ��� ������ �����������...";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			AddQuestRecord("ReasonToFast", "15");
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			GiveItem2Character(pchar, "mapQuest"); 
			arItem = ItemsFromID("mapQuest");
			ReasonToFast_GenerateTreasureMap(arItem);
			pchar.questTemp.ReasonToFast.state = "chain_A"; // �����_�, ������� �� �������
			pchar.questTemp.ReasonToFast = "GetMap";			
			ReasonToFast_SetHunterCoastal();
		break;
		
		case "ReasonToFast_GMayor_21":
			dialog.text = "���������� ������. �������� ���� ������ � �������. ��� �������, ��� � ���� ��� �������! ��... � �������� ��� ����� ����. ������ - �� ���������� ����� ��������� �������� ���������.";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			AddQuestRecord("ReasonToFast", "14");
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			GiveItem2Character(pchar, pchar.questTemp.ReasonToFast.p6);
			pchar.questTemp.ReasonToFast.state = "chain_B"; // ���� �������� �����
			pchar.questTemp.ReasonToFast = "GetMap";			
			ReasonToFast_SetHunterCoastal();
		break;
		case "ReasonToFast_GMayor_31":
			dialog.text = "��, ��������, ��������... ��� ��, � ����� �������, ��� ���� ����������� ������ ����� � �� ���� ���.";
			link.l1 = "�������, �� ����� �����!";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", 1); 
			AddQuestRecord("ReasonToFast", "16");
			CloseQuestHeader("ReasonToFast");
			DeleteAttribute(pchar,"ReasonToFast");
		break;
		
		case "ReasonToFast_BMayor_1":
			dialog.text = "�� ������ ���� �������! ��� ���� �������� ��� ������ � �����������! ������, ����� "+ GetSexPhrase("����� '�������������'","��� '�����������������'") +"!";
			link.l1 = "�� �� ���!";
			link.l1.go = "fight";
		
			pchar.quest.ReasonToFast_ExitFromTown.win_condition.l1			= "EnterToSea";           	
            pchar.quest.ReasonToFast_ExitFromTown.function    				= "ReasonToFast_ExitFromTownFight";						
			pchar.questTemp.ReasonToFast.canSpeakSailor = true;
			pchar.TownEscape = true;
			Flag_PIRATE();
		break;
		
		// ------------------------- ����� ��� ������ -----------------------------
		
		// --------------------------�������� '������'-----------------------------
		case "CapComission_Mayor1":
			dialog.text = "� ������ ������ ��� ����������. �� ��� ������� � ������� ����.";
			link.l1 = "��� ���? � � ��� ��� �����������?";			
			link.l1.go = "CapComission_Mayor2";
		break;
		
		case "CapComission_Mayor2":
			dialog.text = "� ���������, ��� �� ����������, � ���������� ����. � ��� ��������� ����������, ��� ��� ����� ��������������, �� ��������� �� ���� ������� ������� - ������������� � ���������� �������� ����� ������ � ����� ������ ��. � ���� �� ������� ��� ����� �� ������ ��������� ���������� �������.";
			link.l1 = "� ��� ����������� ��������������?";
			link.l1.go = "CapComission_Mayor3";				
		break;
		
		case "CapComission_Mayor3":
			dialog.text = "���� �� ������������ ������� ���������, � ������� �������� ������� �������� � ��������� ����, �������� ������������ ����� � ���������� ��������������� ������. " +
				"��������, ��� ���������� ������ �������� �����. � ���� ���� ���������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name"))) + " �������� " + pchar.GenQuest.CaptainComission.Name + " ������������� �� ���������. ������� � ���� ������� ������� ���� �������� ��� ������ � ��������� ������, �� �� ����� �� �������� � �����.";
			link.l1 = "� ��� �� ���� ������?";
			link.l1.go = "CapComission_Mayor4";
			pchar.GenQuest.CaptainComission.SpeakMayor = true;
		break;
		
		case "CapComission_Mayor4":
			dialog.text = "� ���� �� ����� ���� ������� ��������, ������������ ������� ��������� �������, ����� ���������� ������ ��������. ��� ��� ������ ���������� ������ ����������� ������ �������� " + pchar.GenQuest.CaptainComission.Name + ". " +
				"��� ������ �� ����� ������, ������� ���������� ����� �����.\n���� �� ������� ��� ������ � ���� ����, �� ������ ������ � ��� ���� ����� ��� ������ ������������.";
			link.l1 = "������� ���. � ������� ����� ���� ��������� �����, ����� ���������� �������� �������. ��������, ��� ����.";
			link.l1.go = "CapComission_Mayor5";
			link.l2 = "�������, � �����"+ GetSexPhrase("","�") +" �����������. ������� � ���� ���� �������?";
			link.l2.go = "CapComission_Mayor6";	
		break;
		
		case "CapComission_Mayor5":
			AddQuestRecord("CaptainComission2", "49");
			AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc")));
			AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			pchar.GenQuest.CaptainComission = "MayorTalkBad";
			CaptainComission_GenerateCaptainInPrison();
			DialogExit();
		break;
		
		case "CapComission_Mayor6":
			dialog.text = "�����, ��� �� ��� ������� ������� ������ � ��� ���, ������� ������� ������������."; 
			link.l1 = "������, � ������ �� ��� ����. ������ ��� ����������� �������� � ��������� " + pchar.GenQuest.CaptainComission.Name + ". ����� ��� ���-�� ������������?";
			link.l1.go = "CapComission_Mayor7";
		break;
		
		case "CapComission_Mayor7":
			dialog.text = "�������, � ���� ������� �� �����, � ���������� ���������� ������ � ����� ������.";
			link.l1 = "�������. ��������� �����������.";
			link.l1.go = "CapComission_Mayor8";
		break;
		
		case "CapComission_Mayor8":
			AddQuestRecord("CaptainComission2", "50");
			AddQuestUserData("CaptainComission2", "sSex", GetSexPhrase("��","���"));
			AddQuestUserData("CaptainComission2", "sSex1", GetSexPhrase("","�"));
			AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")));
			AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);			
			AddQuestUserData("CaptainComission2", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			OfficersReaction("good");
			pchar.GenQuest.CaptainComission.MayorTalkGood = true;
			pchar.GenQuest.CaptainComission = "MayorTalkGood";
			pchar.quest.CaptainComission_TimeIsOver.over = "yes";
			SetFunctionTimerConditionParam("CaptainComission_GetSecretTimeIsOut", 0, 0, 2, MakeInt(24 - GetHour()), false);
			CaptainComission_GenerateCaptainInPrison();
			DialogExit();
		break;
		
		case "CapComission_Mayor9":
			dialog.text = "�����������! � ��� �� ��� ������ ��� ���������?";
			link.l1 = "���� �� ����. ������� ����� �� ��� ��� �� ������.";
			link.l1.go = "CapComission_Mayor10";
		break;
		
		case "CapComission_Mayor10":
			dialog.text = "��, ����� ����������! ��� �� ���� '��� �� ������' ������� �����...";
			link.l1 = "�� � ��� ���� �������.";
			link.l1.go = "CapComission_Mayor11";
		break;
		
		case "CapComission_Mayor11":
			dialog.text = "��� ���\n������!.. ������������� ������������ ������� � ������\n�� ������ ���� ��������, " + GetFullName(pchar) + ".";
			link.l1 = "��, �������� ����������...";
			link.l1.go = "CapComission_Mayor12";
		break;
		
		case "CapComission_Mayor12":
			sld = CharacterFromID("CapComission_1");
			sld.lifeDay = 0;
			LAi_group_MoveCharacter(sld, "EnemyFight");
			LAi_SetActorType(sld);
            LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);			
			pchar.quest.CapComission_DeletePrisonGroup.win_condition.l1 = "ExitFromLocation";
            pchar.quest.CapComission_DeletePrisonGroup.win_condition.l1.location = pchar.location;
            pchar.quest.CapComission_DeletePrisonGroup.win_condition = "CaptainComission_DeletePrisonGroup";									
			ChangeOfficersLoyality("bad_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", -4);			
			AddQuestRecord("CaptainComission2", "23");
			AddQuestUserData("CaptainComission2", "sSex", GetSexPhrase("","�"));
			CloseQuestHeader("CaptainComission2");
			DeleteAttribute(pchar, "GenQuest.CaptainComission");
			DialogExit();
		break;
		
		case "CapComission_Mayor13":
			pchar.quest.CaptainComission_SpeakMayorGoods.over = "yes";
			dialog.text = "�����������! � ��� �� ��� ������ ��� ���������?";
			link.l1 = "� " + RandPhraseSimple(RandPhraseSimple("��������","��������"),RandPhraseSimple("���������","�����")) + " ����������� " + XI_ConvertString(pchar.GenQuest.CaptainComission.ConvoyShore + "Gen") + " � �������� ����� ���� ������� ����, ���� � ������� ������� �������. ��� � ���� ������.";
			link.l1.go = "CapComission_Mayor14";
		break;
		
		case "CapComission_Mayor14":
			dialog.text = "�������� ������! � ��� ��� " + pchar.GenQuest.CaptainComission.Name + " ? ��� ��������, ��� �� ����� ��� �� �������� ��������.";
			link.l1 = "� ���������, �� ����� � ������ � ����������������.";
			link.l1.go = "CapComission_Mayor15";
		break;
		
		case "CapComission_Mayor15":
			dialog.text = "��� �����... ��� ����� �����, �����"+ GetSexPhrase("���","��") +" " + GetFullName(pchar) + ". � ����� ������� ��� ��������, � ��������� ��������� ��������. " + 
				"�� �� �����, �������� ��� �� ����� ���� �� ��������\n����, ��������� �� ��������� ���������� �����, ���������� ��������� ������������, �� ��� � �� �������� ���, � �� ���� �� ������������� ����� � ���������. ������� �������������� �� �� ��������... �� � ����� �� ������������� ��� ����� �� ����. ������� ��� ������� - ������ �������� ��� ������� �������� ����. ";
			link.l1 = "��������� ���. ������ ���"+ GetSexPhrase("","�") +" �������.";	
			link.l1.go = "CapComission_Mayor16";
		break;
		
		case "CapComission_Mayor16":
			AddQuestRecord("CaptainComission2", "30");
			AddQuestUserData("CaptainComission2", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			CloseQuestHeader("CaptainComission2");
			GiveItem2Character(pchar, pchar.GenQuest.CaptainComission.Prize);
			ChangeCharacterComplexReputation(pchar,"nobility", 4);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 10);
			OfficersReaction("good");
			DeleteAttribute(pchar,"GenQuest.CaptainComission.MayorTalkGood");
			DeleteAttribute(pchar, "GenQuest.CaptainComission");
			DialogExit();
		break;
		// --------------------------�������� '������'-----------------------------
		
		// -------------------------- ��������� "���������������" ------------
		case "ShipWreck1":
			if(iDay > 15)
			{
				dialog.text = RandPhraseSimple("��� �� ���� ��� �������������? �� ����� ����� ���� ��� ������ �������� ����� �� ����� ���������� ����!","������� " + GetFullName(pchar) + ", ���� ������������������ ���� ��������! ������ ������ ���� �������� �� ���� ������?");
				link.l1 = "���� �� ����, ��� ��� �� ��� ��������...";
				link.l1.go = "ShipWreck2";
			}
			else
			{
				dialog.text = "��� ������� �������! ���� �� ��� �� ��������� ������� " + pchar.GenQuest.ShipWreck.Name + " �����. � ���������� ��������� ������������ ����������. � �������� ��� �������� �������������� �� ���� ������������� � ������� � �� ��������.";
				link.l1 = "���������, ���� ���������. ���"+ GetSexPhrase("","�") +", ��� �����" + GetSexPhrase("","�") + " ������ ��� � ����� �����. ������" + GetSexPhrase("","�") + ", -  ���������� ������ �������.";
				link.l1.go = "ShipWreck3";	
			}
			pchar.GenQuest.ShipWreck.SpeakMayor = true;
			pchar.quest.ShipWreck_MeetInShore.over = "yes";
		break;
		
		case "ShipWreck2":
			dialog.text = "��� ������ ��� ����� ��������? ����� � ������� ������� �����! � � ����� ������ ������ �� ���������, ����� ������ ���� �����.";
			link.l1 = "���� ���������, �� � �������" + GetSexPhrase("","�") + " �� ���������� ���������. �� �������, ������ ���...";
			link.l1.go = "ShipWreck4";
		break;
		
		case "ShipWreck3":
			addMoneyToCharacter(pchar, sti(pchar.rank) * 300 + 3000 + rand(3000));
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			AddQuestRecord("ShipWrecked", "14");
			AddQuestUserData("ShipWrecked", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("ShipWrecked", "sCity", XI_ConvertString(NPChar.city + "Gen"));
			AddQuestUserData("ShipWrecked", "ShoreName", XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat"));
			CloseQuestHeader("ShipWrecked");
			DeleteAttribute(pchar, "GenQuest.ShipWreck.SpeakMayor");		
			DialogExit();
			AddDialogExitQuest("ShipWreck_RemoveSailorsFromShore");
		break;		
		
		case "ShipWreck4":
			ChangeCharacterComplexReputation(pchar,"nobility", -5);
			AddQuestRecord("ShipWrecked", "13");
			AddQuestUserData("ShipWrecked", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("ShipWrecked", "sCity", XI_ConvertString(NPChar.city + "Gen"));
			AddQuestUserData("ShipWrecked", "ShoreName", XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat"));
			CloseQuestHeader("ShipWrecked");
			DeleteAttribute(pchar, "GenQuest.ShipWreck.SpeakMayor");		
			DialogExit();
			AddDialogExitQuest("ShipWreck_RemoveSailorsFromShore");
		break;
		// -------------------------- ��������� "���������������" ------------
		
		// ---------------------- ����� ������ � ������� ----------------------------
		case "TakeRing_1":
			dialog.text = "��� ��������, ��� ��, ��� �� ��� �������... "+ GetSexPhrase("����������� ��������","������� � ��������") +". ������� � ����� � ��� ���������� �� �������\n"+
				"�� ������, ������ ����������, �� � ��� ��� �������...";
			link.l1 = "��, � ����� ����� ���������? �� � �������, �������� � ��� ����...";
			link.l1.go = "TakeRing_2";
		break;
		case "TakeRing_2":
			dialog.text = "��, �� � �� ����� �������. � ��� ����� ������� � ������� ����������� ������!..";
			link.l1 = "�-�-�, ��� ��������� ��������, ����������.";
			link.l1.go = "TakeRing_3";
		break;
		case "TakeRing_3":
			dialog.text = "��, ���������� �� ���������. ����� ������� ������. �������� �� ��������, � � ������ ������ � ���� ����� ����. � � ������ ������� - ��� �����.";
			link.l1 = "�������... � ��� ��������� �� ����� ��� ��������? �� ���-������ ������ ������� ����� ��� ����� �����?";
			link.l1.go = "TakeRing_4";
		break;
		case "TakeRing_4":
			dialog.text = "���, ���. ������ �� �����...";
			link.l1 = "����. �� ��� ��, ����� ������.";
			link.l1.go = "TakeRing_5";
			link.l2 = "�� ������, " + GetAddress_FormToNPC(NPChar) + ", �, �������, �������� �� ���� ������. ����� ���� ��������...";
			link.l2.go = "TakeRing_6";
		break;	
		case "TakeRing_5":
			dialog.text = "����� ������! �� ������� - �� �������� �� ������ ��� �����.";
			link.l1 = "� �����. ����� ���� � ���������.";
			link.l1.go = "exit";
			pchar.questTemp.different = "TakeMayorsRing";
			pchar.questTemp.different.TakeMayorsRing = "toBrothel";
			pchar.questTemp.different.TakeMayorsRing.Id = GetFullName(npchar);
			pchar.questTemp.different.TakeMayorsRing.city = npchar.city;	
			pchar.questTemp.different.TakeMayorsRing.price = sti(pchar.rank)*100+1000;
			sld = ItemsFromID("MayorsRing");
			sld.CityName = XI_ConvertString("Colony" + npchar.city + "Gen");
			//����� ������ � ����
			if (rand(3) != 2)
			{				
				switch (rand(2))
				{
					case 0: sTemp = "_Brothel_room";  break;
					case 1: sTemp = "_Brothel";  break;
					case 2: sTemp = "_SecBrRoom";  break;
				}
				sld.shown = true;
				sld.startLocation = pchar.questTemp.different.TakeMayorsRing.city + sTemp;
				sld.startLocator = "item" + (rand(4)+1);
				pchar.questTemp.different.TakeMayorsRing.item = true; //���� ������ �������� � ������
				Log_QuestInfo("������ ��������� � ������� " + sld.startLocation + ", � �������� " + sld.startLocator);
			}
			SetTimerFunction("TakeMayorsRing_null", 0, 0, 1); //����������� ���������� �� ���������� 
			ReOpenQuestHeader("SeekMayorsRing");
			AddQuestRecord("SeekMayorsRing", "1");
			AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("SeekMayorsRing", "sName", pchar.questTemp.different.TakeMayorsRing.Id);
		break;	
		case "TakeRing_6":
			dialog.text = "��� ���? ��, �� ������, �� ������... �� ��� ��, ����� ��������, �������.";
			link.l1 = "��������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
		break;

		case "TakeRing_S1":
			dialog.text = "�������, ��� ������������� ���!! �� ��� ������ ����� ������!";
			link.l1 = "�� ��� ��...";
			link.l1.go = "TakeRing_S2";
			TakeItemFromCharacter(pchar, "MayorsRing");
		break;
		case "TakeRing_S2":
			dialog.text = "��� ���� ������ �� ����������� ������. � ������, ��� � ��� ����� ����������!";
			link.l1 = "��, ���� ����� � ����...";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", 5);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 10);
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			AddCharacterExpToSkill(pchar, "Fortune", 20);
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.different.TakeMayorsRing.price));
			pchar.questTemp.different = "free";
			pchar.quest.TakeMayorsRing_null.over = "yes"; //������� ������
			AddQuestRecord("SeekMayorsRing", "7");
			AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			CloseQuestHeader("SeekMayorsRing");
			DeleteAttribute(pchar, "questTemp.different.TakeMayorsRing");
		break;
		case "TakeRing_S3":
			dialog.text = "��� ��� ��!! ���� ������ ����...";
			link.l1 = "��� �����! �� ��� ��, ��� ���� ������.";
			link.l1.go = "TakeRing_S4";
		break;
		case "TakeRing_S4":
			dialog.text = "��-��, ������� ��� ��������. � - ��� �������! ��� ���� ������ �� ����������� ������.";
			link.l1 = "������� " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "MayorsRing");
			ChangeCharacterComplexReputation(pchar,"nobility", 3);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 3);
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.different.TakeMayorsRing.price));
			pchar.questTemp.different = "free";
			pchar.quest.TakeMayorsRing_null.over = "yes"; //������� ������
			AddQuestRecord("SeekMayorsRing", "7");
			AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			CloseQuestHeader("SeekMayorsRing");
			DeleteAttribute(pchar, "questTemp.different.TakeMayorsRing");
		break;
		// ---------------------- ����� ������ � ������� ----------------------------

		case "node_1":
            //����� homo
			if (CheckAttribute(Colonies[FindColony(npchar.City)],"Siege"))
            {

                makearef(aData, NullCharacter.Siege);
                

                if (CheckAttribute(aData, "HelpColony") && sti(aData.HelpColony) == true )
                {
                    dialog.text = "�� ����� �� ��� ��������, �� ��� ��?";
                    link.l1 = "�� ����� - �� ����� ��� ����� �����������.";
                    link.l1.go = "exit";

                }
                else
                {
                    dialog.text = "������ ��� ��������, �� � ������ ������ � ���� ��� �������, ����� ������� ���. ��� ��, ��������, ��� ������, �� ���� ������� ������ "+NationNamePeople(sti(aData.nation))+". � ��� ���������� ������������ ������� ������.";
                    link.l1 = "��� � ��� ��� �����"+ GetSexPhrase("","�") +" ���������� ���� ������ � ������� �����.";
                    link.l1.go = "siege_task";
                    link.l2 = "����� �� ����� ��� ����� �����������.";
        			link.l2.go = "exit";
                }
            }
            else
            {//->
                makearef(aData, NullCharacter.Siege);
                if (CheckAttribute(aData, "PlayerHelpMayor") && sti(aData.PlayerHelpMayor) == true
                && CheckAttribute(aData, "HelpColony") && sti(aData.HelpColony) == true )
                {
                    AddMoneyToCharacter(Pchar,(sti(aData.iSquadronPower)*3000));
                    ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
                    ChangeCharacterComplexReputation(pchar,"nobility", 10);
                    AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 80);
                    AddCharacterExpToSkill(GetMainCharacter(), "Sailing", 100);
                    AddCharacterExpToSkill(GetMainCharacter(), "Accuracy", 100);
                    AddCharacterExpToSkill(GetMainCharacter(), "Cannons", 100);
                    //--> �����
                    SiegeRumour("������������, ��� �� ������� ��� �������� �� "+NationNameSK(sti(aData.nation))+"�� ������� - � �������� ���� �������! �� ��� ���������� ���, "+ GetAddress_Form(NPChar)+".", aData.Colony, sti(aData.conation), -1, 15, 3);
		            //<-- �����
                    DeleteAttribute(aData, "PlayerHelpMayor");
                    DeleteAttribute(aData, "HelpColony");
                    dialog.text = "��, ��� ��, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+", ��� ��� ������. ������ ����� ��� ����� ������� - �� �������� �� "+NationNameSK(sti(aData.nation))+"�� �����������. � ���� ���� � ���� �������, ��� ���� ������� "+(sti(aData.iSquadronPower)*1500)+" ����. �������� ��������.";
                    link.l1 = "�������, " + GetAddress_FormToNPC(NPChar) + ", ������� ����� � ���� ����!";
                    link.l1.go = "exit";
                }
                else
                {
                    if (CheckAttribute(aData, "PlayerHelpMayor")) DeleteAttribute(aData, "PlayerHelpMayor");
                    dialog.text = "��� ����� ������� ��������� ��� ������ ���� � ��������� ���� �� ������ ��������������� ���?";
					if (npchar.city != "Panama") // Addon-2016 Jason
					{
						link.l1 = "� ���� ���������� � ������ �� ����� ������ "+ NationNameGenitive(sti(NPChar.nation))+".";
						link.l1.go = "work";
					}
					// Warship ����� "������ �� ����������" - ����� ������� �������
					if(CheckAttribute(PChar, "Quest.PiratesOnUninhabited_OnShore") || CheckAttribute(PChar, "Quest.PiratesOnUninhabited_ShipSink"))
					{
						link.l11 = XI_ConvertString(PChar.GenQuest.PiratesOnUninhabited.StartShore + "Dat") + " � ��������"+ GetSexPhrase("","�") +" �������. ��� " + PChar.GenQuest.PiratesOnUninhabited.PiratesCount + " ������� ������ � ���� �� �����. ���� ����� �� �������.";
						link.l11.go = "PiratesOnUninhabited_1";
					}
					
        			link.l2 = "����� ���������� � ���� �� ����� ����.";
					if(CheckAttribute(pchar,"questTemp.ReasonToFast") && !CheckAttribute(pchar,"questTemp.ReasonToFast.SpeakOther") && !CheckAttribute(pchar, "questTemp.ReasonToFast.cantSpeakOther") && (pchar.questTemp.ReasonToFast.city == NPChar.city))
					{
						link.l2.go = "ReasonToFast_Mayor1";
					}
					else
					{					
						link.l2.go = "quests";
					}	
					if(CheckAttribute(pchar,"GenQuest.CaptainComission") && (pchar.GenQuest.CaptainComission.variant == "A2") && (pchar.GenQuest.CaptainComission.City == NPChar.city))
					{
						if(pchar.GenQuest.CaptainComission == "Begin_1" && !CheckAttribute(pchar,"GenQuest.CaptainComission.SpeakMayor")) 
						{
							link.l12 = "� ��� ��������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " ������ ����� " + pchar.GenQuest.CaptainComission.Name + ", ��� � ���� � ��� ����������?";
							link.l12.go = "CapComission_Mayor1";
						}	
						if(CheckAttribute(pchar,"GenQuest.CaptainComission.PrisonFree"))
						{
							link.l12 = "������ ������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " " + pchar.GenQuest.CaptainComission.Name + " ���������� ������� ���� ������ �������.";
							link.l12.go = "CapComission_Mayor9";
						}
						if(pchar.GenQuest.CaptainComission == "GetGoodsSuccess")
						{
							link.l12 = "������ ������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Gen")) + " " + pchar.GenQuest.CaptainComission.Name + " ������ ��� ���� ������.";
							link.l12.go = "CapComission_Mayor13";
						}
					}
					if(CheckAttribute(pchar,"GenQuest.ShipWreck") && pchar.GenQuest.ShipWreck == "SailorsOnShore" && GetQuestPastDayParam("GenQuest.ShipWreck") < 25 && sti(npchar.nation) == sti(pchar.GenQuest.ShipWreck.Nation))
					{
						if(!CheckAttribute(pchar,"GenQuest.ShipWreck.SpeakMayor"))
						{
							iDay = GetQuestPastDayParam("GenQuest.ShipWreck");
							if(CheckAttribute(pchar, "GenQuest.ShipWreck.Mutiny"))
							{
								link.l13 = UpperFirst(XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat")) + " � ��������" + GetSexPhrase("","�") + " �������� " + pchar.GenQuest.ShipWreck.Name + " � ��� �������, ���������� �� ����� ������� " + pchar.GenQuest.ShipWreck.BadName + ". " +
									"� ���������, �������� ������� �� ��� ����� �� �������� ����� �� �� ����. �� � �������" + GetSexPhrase("","�") + " �� �������� � ������. ���� �������������� ����� �� ������ ������� �� � ������� " + (30 - iDay) + " ����, �� �� ����, ������� �� ������� �� ������.";
								link.l13.go = "ShipWreck1";
							}
							else
							{
								link.l13 = UpperFirst(XI_ConvertString(pchar.GenQuest.ShipWreck.Shore + "Dat")) + " � ��������"+ GetSexPhrase("","�") +" ������� �� ������������ �������� ����� '" + pchar.GenQuest.ShipWreck.ShipTypeName + "' �� ����� � �� ���������. " + 
									"� ���������, �������� ������� �� ��� ����� �� �������� ����� �� �� ����. �� � �������" + GetSexPhrase("","�") + " �� �������� � ������. ���� �������������� ����� �� ������ ������� �� � ������� " + (30 - iDay) + " ����, �� �� ����, ������� �� ������� �� ������.";
								link.l13.go = "ShipWreck1";							
							}	
						}	
					}					
					//--> Jason, ����� ��������� ������� 2 ������
						if (CheckAttribute(PChar, "questTemp.WPU.Postcureer.LevelUp"))
						{
							if (pchar.questTemp.WPU.Postcureer.TargetPortmanID == npchar.id)
							{
							link.l14 = "� �������� ��� ������ �� ������ "+XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+".";
							link.l14.go = "Postcureer_LevelUp_ForAll";
							}
						}
					//<-- ����� ��������� ������� 2 ������
					
					// --> Warship, 16.05.11. ����� "���������� �� �������".
					if(CheckAttribute(PChar, "GenQuest.JusticeOnSale.MayorWait") && CheckAttribute(PChar, "GenQuest.JusticeOnSale.CityId") && NPChar.location == PChar.GenQuest.JusticeOnSale.CityId + "_townhall")
					{
						link.l15 = "������, � ��������� ����� ���������������, ����� ������� ������� ������� ������. ��� ��������� ��������� ���. �� ������� '" + PChar.GenQuest.JusticeOnSale.ShipName + "' ����� " + XI_ConvertString(PChar.GenQuest.JusticeOnSale.ShoreId + "Dat") + ".";
						link.l15.go = "JusticeOnSale_1";
					}
					//<-- ���������� �� �������
					
        			if (GetPrisonerQty() > 0)
        			{
                        link.l3 = "��� ����� ����� �������� �������� �������.";
        			    link.l3.go = "sell_prisoner";
        			}
					//Jason --> ������
					if (CheckAttribute(pchar, "questTemp.Regata.ToPortRoyal") && NPChar.location == "Portroyal_townhall")
					{
						link.l4 = "� ������ �� ����������� ��� ������� � ������. ��� ��� �����������.";
						link.l4.go = "Regata";
					}
        			link.l5 = "�����, �� ������ ������� ����������� �� ������ ���?";
        			link.l5.go = "Play_Game";
        			link.l10 = "��� ������ ����� ���������� � ������ �����, " + GetAddress_FormToNPC(NPChar) + ".";
        			link.l10.go = "node_2";
                }
    		}//<-
		break;
		
		case "Play_Game":
			dialog.text = "��, � ����� ���� �� �������������?";
			link.l1 = "����������� � ����� �� �������� �������?";
			link.l1.go = "Card_Game";
   			link.l2 = "�������� ������� � �����-������?";
			link.l2.go = "Dice_Game";
			link.l10 = "����� ��������, �� ���� ���� ����.";
			link.l10.go = "exit";
		break;
		
		//  ����� -->
        case "Card_Game":
            if (!CheckNPCQuestDate(npchar, "Card_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Card_date_Yet");
				if (pchar.model == "Sharle_6") dialog.text = "����� ���� ��������, ���������, �� ������ � ���� ��� �� ��� �������. ����� ����, � ������ ���."; // Jason ���
                else dialog.text = "� �� ���� ������ � �������� ���� � ������� ������������!";
    			link.l1 = "��� ��� ����� ������.";
    			link.l1.go = "exit";

			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Card_date_begin"))
				{
					dialog.text = "�������! ����� ������� �� ������ ��������... ������ ��������...";
	    			link.l1 = "������������.";
	    			link.l1.go = "Cards_begin";
	    			link.l2 = "�� ����� �������� ����?";
	    			link.l2.go = "Cards_Rule";
    			}
    			else
    			{
					dialog.text = "���, � ���� �������� �� �������. ���� ����.";
	    			link.l1 = "��� ��� ����� ������.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Cards_Rule":
   			dialog.text = CARDS_RULE;
			link.l1 = "��� �, ������� �����!";
			link.l1.go = "Cards_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Cards_begin":
			dialog.text = "������� ����������� �� �������.";
			link.l1 = "������ �� 1000 ����.";
			link.l1.go = "Cards_Node_100";
			link.l2 = "������� �� 5000 ����.";
			link.l2.go = "Cards_Node_500";
			link.l3 = "�������, ��� ����.";
			link.l3.go = "exit";
		break;

		case "Cards_Node_100":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� ��������������� ������. � �� ���� � ����� ������.";
                link.l1 = "�� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "�������� ������, " + GetAddress_Form(NPChar) + "? � ��� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "��! ����� ���������� � �������, � �� ������� � ����������� � ������� � �����...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 1000 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 1000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_Node_500":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� ��������������� ������. � �� ���� � ����� ������.";
                link.l1 = "�� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckCardsGameBigRate())
		    {
                dialog.text = "� ������, ��� �� ����� ������ �������. � �� ���� ������ � ����� �� ����� ������� �������.";
                link.l1 = "������� �� ����� ������ �������?";
			    link.l1.go = "Cards_Node_100";
				link.l2 = "��������, ��� ����.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "�������� ������, " + GetAddress_Form(npchar) + "? � ��� ��� 15000 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "���, ����� ������ �� ������� �� ����� ����� ������.";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 5000 �����.";
			link.l1 = "������!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 5000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_begin_go":
            SetNPCQuestDate(npchar, "Card_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchCardsGame();
		break;
	    // ����� <--

	    //  Dice -->
        case "Dice_Game":
            if (!CheckNPCQuestDate(npchar, "Dice_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Dice_date_Yet");
                if (pchar.model == "Sharle_6") dialog.text = "����� ���� ��������, ���������, �� ������ � ���� ��� �� ��� �������. ����� ����, � ������ ���."; // Jason ���
                else dialog.text = "� �� ���� ������ � �������� ���� � ������� ������������!";
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
			link.l1 = "��� �, ������� �����!";
			link.l1.go = "Dice_begin";
			link.l3 = "���, ��� �� ��� ����...";
			link.l3.go = "exit";
		break;

		case "Dice_begin":
			dialog.text = "������� ����������� �� �������.";
			link.l1 = "������ �� 500 ���� �� �����.";
			link.l1.go = "Dice_Node_100";
			link.l2 = "������� �� 2000 ���� �� �����.";
			link.l2.go = "Dice_Node_500";
			link.l3 = "�������, ��� ����.";
			link.l3.go = "exit";
		break;

		case "Dice_Node_100":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� ��������������� ������. � �� ���� � ����� ������.";
                link.l1 = "�� ����! �� � �� �����.";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "�������� ������, " + GetAddress_Form(NPChar) + "? � ��� ��� �����!";
                link.l1 = "������.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "��! ����� ���������� � ������, � �� ������� � ����������� � ������� � �����...";
                link.l1 = "����.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 500 �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 500;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_Node_500":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "� ���� ����� ����� ��������������� ������. � �� ���� � ����� ������.";
                link.l1 = "�� ����! �� � �� �����.";
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

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "�������� ������, " + GetAddress_Form(NPChar) + "? � ��� ��� 15000 ����!";
                link.l1 = "�����!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "���, ����� ������ �� ������� �� ����� ����� ������.";
                link.l1 = "��� ������.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "������, ������ �� 2000 ����� �� �����.";
			link.l1 = "������!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 2000;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_begin_go":
            SetNPCQuestDate(npchar, "Dice_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchDiceGame();
		break;
	    // Dice <--
		case "node_2":
			dialog.text = "� ����� ������, � ������� ��� �������� ��� ������� � ����� �� ������ ��� ��������.";
			link.l1 = "��, ��, �������, ��������, ��� ����������"+ GetSexPhrase("","�") +" ���.";
			link.l1.go = "exit";
		break;

		//---------------------------- ��������� ������� ���� -------------------------------
		case "work": 
            dialog.text = "��� ���� ���, ��������� ���� � ������� �����.";
        	link.l1 = "������, ��������!";
        	link.l1.go = "exit";

        	// boal ������ �� ��� -->
            if (CheckAttribute(pchar, "GenQuest.GhostShipDone_" + NPChar.id))
			{
				dialog.text = "���� ���������. ����� ������! ��� ���� �������.";
				link.l1 = "���"+ GetSexPhrase("","�") +" ������� ���.";
				link.l1.go = "GhostShipDone";
				break;
			}
			if (CheckAttribute(NPChar, "from_sea") && Pchar.location.from_sea == NPChar.from_sea)
            {
    			if (!CheckAttribute(pchar, "GenQuest.GhostShip.LastBattle") &&
                     CheckAttribute(pchar, "GenQuest.GhostShip.NeedCoins")  &&
                    GetNpcQuestPastDayWOInit(npchar, "GhostShipHelp") > 30  &&
                    !CheckAttribute(pchar, "GenQuest.GhostShipWorkId")      &&
                    dRand(2) == 1)
                {
                    dialog.text = "��, " + GetAddress_Form(NPChar) + RandPhraseSimple(", ������, ������ ������� ��� �����!! ����� �������� � ����� ������ � �����������. � �� ����, ��� ������!",
                                                       ", �� �������! ��� ��������, ��� � ����� ���� ���. ����� �������� ������. �������� ��� ���������� ��.");
    				link.l1 = RandPhraseSimple("������, �� �����!",
                                               "�! ��� ���� ��� ��� ��, ��� ��� �����!");
    				link.l1.go = "GhostShipHelp_1";
    				break;
                }
            }
            // boal ������ �� ��� <--


			//==> ���� �� �����-���� �����
			if (CheckAttribute(pchar, "GenQuest.questName"))
			{		 				
				//--> �����, �� �� ���
				QuestName = pchar.GenQuest.questName;
				if (pchar.GenQuest.(QuestName).MayorId != npchar.id) 
				{					
					dialog.text = RandPhraseSimple("��������� ��� ��������, �� ��� ������ ������� �� ����������� " + XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.(QuestName).MayorId)].city+"Gen") + ". ���� �� ��������� ���������� ������, ����� � ��� �� ���.", 
						"��, � �� �� �� � " + XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.(QuestName).MayorId)].city+"Dat") + " ������� �� ���������� ����� ��������� �������� �����������? ��, ������ ���! ���� �� �� ��������� ���� �������������, ������ ������ � ��� �� ������.");
					link.l1 = RandPhraseSimple("�������...", "� �����"+ GetSexPhrase("","�") +", "+ GetAddress_FormToNPC(NPChar) + ".");
					link.l1.go = "exit";					
					break;
				}
				//<--�����, �� �� ���
				//-------- ���� ����� ����������� ����� ---------->>
				if (QuestName == "DestroyGang")
				{
					switch (pchar.GenQuest.DestroyGang)
					{
						makearef(arName, pchar.GenQuest.DestroyGang);
						case "":
							dialog.text = LinkRandPhrase("������� �� ����� ������� �� ����� " + GetFullName(arName) + " ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ����� ������� �� ����� " + GetFullName(arName) + ". � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, " + GetFullName(arName) + " ������ ����� ����������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� � ����������� �������, �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - " + GetFullName(arName) + " �� ��� ��� ��� � ������! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ����������� ����� �������� �� ����� " + GetFullName(arName) + ", �����. ������, ��� �����������, ��� �������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ������ ���������� ���������� �������? " + GetFullName(arName) + " ������� ����?", "������� ��� ������ ���� - " + GetFullName(arName) + " ��� ��� ����?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� ������� ��������� ���, �� ���� ��������� ������� � ��� �������� ���������. ����� ��������, ���� ������ ��� �� �� �����.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ������ ���������� ���������� �������? " + GetFullName(arName) + " ������� ����?", "������� ��� ������ ���� - " + GetFullName(arName) + " ��� ��� ����?");
							link.l1 = "�� ����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 80);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
						break;
					}
				}
				//-------- ����������� ---------->>
				if (QuestName == "TakePostcureer")
				{
					switch (pchar.GenQuest.TakePostcureer)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ������ ����������� ����� ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ������ ����������� �����. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, ������ ��� ��������� ���� �������� � ���� �����! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� � ������ ����������� ������� �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - ���������, ������� � ����, ������ � ���� ����������! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ������� ���������� � ����������� ������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ��������� ����� ����������?", "������� ��� ������ ���� - ����� � ���������������� � ���?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� ������� ��������� �������, ������ ��������� � ��������� �� ����.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ��������� ����� ����������?", "������� ��� ������ ���� - ����� � ���������������� � ���?");
							link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". � ����� ������������ ��� ���. ��� ��.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 100);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 50);
							RemoveItems(pchar, "ContraPostLetters", 1);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
						break;
					}
				}
				//-------- ���������� - ������� ---------->>
				if (QuestName == "TakeArsenalship")
				{
					switch (pchar.GenQuest.TakeArsenalship)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ����������� �������� ���������� ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ����������� �������� ����������. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, ����� � ���������� ���� �������� � ��������� ������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� � ����������� �������� ���������� �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - ��������� ������ ������������ ����� �� ����� ����������! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ����������� ���������� �������� ���������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ���������� ��������� ������� ���������?", "������� ��� ������ ���� - ��������� ������� �� ��� ����?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� ������� ��������� ������, ������ �������� ������ ������� � �� ����.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ���������� ��������� ������� ���������?", "������� ��� ������ ���� - ��������� ������� �� ��� ����?");
							link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". ����� � ���������� �� ���������� �����.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 120);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 50);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
						break;
					}
				}
				//-------- ��� - ����� ---------->>
				if (QuestName == "TakePirateship")
				{
					switch (pchar.GenQuest.TakePirateship)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ����������� ������ ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ����������� ���������� �������. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, ������� ����� ����������� ��������� ������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� � ����������� ������ �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - ������� ����� ���������� ������� ���� �������! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ����������� ���������� ������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ���������� ��������� �������?", "������� ��� ������ ���� - ������� ����� �� ��� ����?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� ������� ��������� �������, ������ �������� ��� ������� � �� ����.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ���������� ��������� �������?", "������� ��� ������ ���� - ������� ����� �� ��� ����?");
							link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". ���� ������� ������ ������� �� ����������� ������ ���� ����� ���������.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 150);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 50);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+3;

						break;
					}
				}
					//-------- ��� - �������� ---------->>
				if (QuestName == "TakePassenger")
				{
					switch (pchar.GenQuest.TakePassenger)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ������ ����������� ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ������ �����������. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, ������� ������� �������� ������ ���� �� �������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� ������� �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - �� ������������ ������ � ����� ���������� � ������� �������� ����! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ������� ����������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ��������� ��������?", "������� ��� ������ ���� - ������� �������� � �������� � ��� � �����?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� �� ������� ��������� �������. �� ������ ������ � ��������, �� ������� ����.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ��������� ��������?", "������� ��� ������ ���� - ������� �������� � �������� � ��� � �����?");
							link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". ��������� �������� ������ � �����, � � ���������� ����� ��� �� �����.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 150);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 100);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
							sld = &Characters[sti(Pchar.GenQuest.TakePassenger.PrisonerIDX)];
							ReleasePrisoner(sld); //���������� ��������
							sld.lifeday = 0;
						break;
					}
				}
				//-------- ���������� ������� ---------->>
				if (QuestName == "CustomPatrol")
				{
					switch (pchar.GenQuest.CustomPatrol)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ������ ��������������� ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ������ ���������������. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, �������������� �������� ��������� � ������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� ��������������� �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - ��� ������������ ������� �����! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ������� ��������������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ������������ � ����������������?", "������� ��� ������ ���� - ������������� ������ �������?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� �� ������� �������� ��������.";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ������������ � ����������������?", "������� ��� ������ ���� - ������������� ������ �������?");
							link.l1 = "��, " + GetAddress_FormToNPC(NPChar) + ". � ������ �� ������� � ��������� �����, ��� ��������, ��� � ����������.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 100);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 200);
							ChangeCharacterComplexReputation(pchar,"authority", 1);
	ChangeContrabandRelation(pchar, -5);
						break;
					}
				}
				//-------- �������� ---------->>
				if (QuestName == "FindFugitive")
				{
					switch (pchar.GenQuest.FindFugitive)
					{
						case "":
							dialog.text = LinkRandPhrase("������� �� ������ ��������� ���� ��� ��������. ����������!", 
								"�� ��� ������ ������� �� ������ ���������. � ��� �����������!", 
								"���� �� ��� �������������� � ���� � ����������, ��������, ��������, ����� ��������������� �������! ���������� ���������� ����������� �� ��� ���������!");
							link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "� ��������� ����, "+ GetAddress_FormToNPC(NPChar) + ".");
							link.l1.go = "exit";		
						break;
						case "Late":
							dialog.text = RandPhraseSimple("�����, ������ ��� �� ����� ��������� �����. � ��� �� �������, ��� ��� �����������? � � ��� ����� - ��� ������� ����������� ���! �������� �����������, " + GetAddress_Form(NPChar) + ".",
								"��� �����, ��������������� ��� ��� ������� ��������� �����. ����������� ���. � ��� ����?");
							link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ���� ������� � ���������� �����, " + GetAddress_FormToNPC(NPChar) + ".";
							link.l1.go = "All_Late";		
						break;
						case "Found":
							dialog.text = RandPhraseSimple("����, ��� �������? �� ��������� ���������?", "������� ��� ������ ���� - �������� � �������� � ��� � �����?");
							link.l1 = "� ���������, ���, " + GetAddress_FormToNPC(NPChar) + ". ��� �� ������� ��������� �������. � ����� ��� ���� � ��������� "+XI_ConvertString("Colony"+pchar.GenQuest.FindFugitive.City)+", ������ ��������� �� ���� �� ����� �������� �� ������� �� ��������� ����� � ����������� �����������. �����, �� �������� � ������������ �����...";
							link.l1.go = "All_Found";		
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("���-���... ��� � ��� "+pchar.GenQuest.FindFugitive.Name+"... �������� ������, �������! ������� ���� ��������?", "�, ����� � ��� �����! ������� ���, "+pchar.GenQuest.FindFugitive.Name+"! �������� ������, �������! ����� ��� ��������� �� �������?");
							link.l1 = "��� �������, " + GetAddress_FormToNPC(NPChar) + ". ��� �� ��� �� ���� - ���� ������� � ��������.";
							link.l1.go = "All_Execute";		
							AddCharacterExpToSkill(PChar, "Leadership", 200);
							AddCharacterExpToSkill(PChar, "Fortune", 200);
							AddCharacterExpToSkill(PChar, "Sneak", 100);
							ChangeCharacterComplexReputation(pchar, "authority", 1);
							sld = &Characters[sti(Pchar.GenQuest.FindFugitive.PrisonerIDX)];
							ReleasePrisoner(sld); //���������� ��������
							LAi_SetActorType(sld);
							sld.lifeday = 0;
							pchar.quest.FindFugitive_Over.over = "yes"; //������� ������
							chrDisableReloadToLocation = false;//������� �������
						break;
					}
				}
				//------ ������������� �� ���������� ����� ------------>>
				if (QuestName == "Intelligence")
				{
					switch (pchar.GenQuest.Intelligence)
					{
						case "":
							if (GetQuestPastDayParam("GenQuest.Intelligence") > sti(pchar.GenQuest.Intelligence.Terms))
							{
								dialog.text = RandPhraseSimple("�����, ������ ��� �� �������� ������, �����. � � ��� �������, ��� ���������� � ��� ���.",
									"��� �����, ��������������� ��� ��� �������� ������, �����. ������, ��� � �������, �������� ���. � ��� ����?");
								link.l1 = "� �� �����"+ GetSexPhrase("","�") +" ��������� ������ �������, " + GetAddress_FormToNPC(NPChar) + ".";
								link.l1.go = "All_Late";	
							}
							else
							{
								dialog.text = LinkRandPhrase("������� �� �������� ��� ������ ���� ��� ��������. ����������!", 
									"�� ��� ������ ������� �� �������� ��� ������ ����� � ����. � ��� �����������, ��� ����� ��� ������ ��� ����� �������!", 
									"���� �� ��� �������������� � ���� � ����������, ������ ��� ���������� �� ��� ��� � ����, ��� ������ � ���������! ���������� ����������� � �������, ��������� ��� ������!");
								link.l1 = RandPhraseSimple("������, " + GetAddress_FormToNPC(NPChar) + ".", "������� ����� ������, "+ GetAddress_FormToNPC(NPChar) + ".");
								link.l1.go = "exit";	
							}
						break;
						case "Execute":
							dialog.text = RandPhraseSimple("�� ��������� ��������� ���� ������?", "�������� �� �������, ����� � ���?!");
							link.l1 = "��, � �� ������"+ GetSexPhrase("","�") +". ��� �� � �������������� - ������ ����� � ����.";
							if (GetQuestPastDayParam("GenQuest.Intelligence") > sti(pchar.GenQuest.Intelligence.Terms))
							{
								link.l1.go = "Intelligence_ExecuteLate";
								AddCharacterExpToSkill(PChar, "Sneak", 200);
							}
							else
							{
								link.l1.go = "All_Execute";		
								AddCharacterExpToSkill(PChar, "Leadership", 100);
								AddCharacterExpToSkill(PChar, "Sneak", 200);
							}
							TakeItemFromCharacter(pchar, "sicretLetter");
							DeleteAttribute(ItemsFromID("sicretLetter"), "City");
							DeleteAttribute(ItemsFromID("sicretLetter"), "Mayor");
						break;
					}
				}
				break;
			}
			sTemp = npchar.city;
			//����� ���
			i = CheckAvailableTaskForNPC(NPChar, PGG_TASK_WORKONMAYOR);
			if (i != -1)
			{
				dialog.text = "���, �� ������� � ���� ������� ������ ���. ��������� �������� " + GetFullName(&Characters[i])
					+ ". ������� ������, ����� ���-�� ��������.";
				link.l1 = "��, ����!!! �� ����...";
				link.l1.go = "exit";
				break;
			}
//navy <--
			if (!CheckAttribute(npchar, "work_date") || GetNpcQuestPastDayParam(npchar, "work_date") > 2 || bBettaTestMode)
    		{	
				SaveCurrentNpcQuestDateParam(npchar, "work_date");
				if (rand(5) > 4 && !bBettaTestMode && pchar.location == "Panama_townhall") // patch-5
				{
					dialog.text = LinkRandPhrase("������ � ���� ��� ������ ��� �����, ��� ��. ������� ������, ��� ��...", 
						"�������� ��������� ��� ��� � ���� ������� ���. �������� �����, ����� ����-������.", 
						"������� ������ ��� ������, ��� � ��� �� ��� ��������. ���� ��� ������ ��� � ������ ����.");
					link.l1 = "� �����"+ GetSexPhrase("","�") +", " + GetAddress_FormToNPC(NPChar) + ".";
					link.l1.go = "exit";
				}
				else 
				{
					i = dRand(7);
					switch (i)
					{					
						//========== ����� ����������� ����� ============ //Jason: ���������, ��� ��������
						case 0:
							pchar.GenQuest.DestroyGang.Terms = dRand(2) + 2; //����� ���������� �������
							pchar.GenQuest.DestroyGang.Money = ((dRand(6)+4)*250)+(sti(pchar.rank)*300+2000); //��������������
							makearef(arName, pchar.GenQuest.DestroyGang);
							arName.nation = PIRATE;
							arName.sex = "man";
							SetRandomNameToCharacter(arName); //��� ������� � ��������� ������	
							dialog.text = "������ ������ � ���� ���� ��� ��� �������. � �������� ���� " + XI_ConvertString("Colony"+npchar.city+"Gen") + " ��������� ����� ����������, � ��� ��������, ��� ������� � ��� �������� ����� " + GetFullName(arName) + ". �������� � ���������� ��� ����� �����������.";
							link.l1 = "� �����-�� ������� ���������"+ GetSexPhrase("","�") +" � ������?";
							link.l1.go = "DestroyGang";
						break;
						//========== ���������� �� ��������� ����� ============//Jason: ���������, ��� ������
						case 1:
							pchar.GenQuest.Intelligence.Terms = dRand(10) + (42 - MOD_SKILL_ENEMY_RATE); //����� ���������� �������
							pchar.GenQuest.Intelligence.Money = ((dRand(4) + 6) * 1000) + (sti(pchar.rank) * 1000 + 10000); //��������������
							pchar.GenQuest.Intelligence.City = GetSpyColony(npchar); //���������� �������
                            sTemp = ", ��� �� " + XI_ConvertString(colonies[FindColony(pchar.GenQuest.Intelligence.City)].islandLable+"Dat");                         
							dialog.text = "� ���� ���� ��� ��� �������, ���������� � ��������� ������. ��� �����, ����� �� ���������� � " + XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Acc") + sTemp + ", ����������� ��� � ��������� ��������� � ��������� ��� ��, ��� �� ��� ����.";
							link.l1 = "��, �� ������"+ GetSexPhrase("","�") +" ��, ��� � " + XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Dat") + " ����� ���� ���� ������...";
							link.l1.go = "Intelligence";
						break;
						
						//========== ����������� - �������� ����� ============
						case 2:
							dialog.text = "��, � ���� ���� ���������, ��� ���������� �������� ��� ����������� �������� �������������, � ����� ������ �������� ����� ������� ���. �� ������ �������� ����?";
							link.l1 = "���� ���������, �� ������ ����������� �������� ���� ������������ �������?";
							link.l1.go = "TakePostcureer";
						break;
						
						//========== ���������� - �������� ������� � ������������ ============
						case 3:
							dialog.text = "��, � ���� ���� ���������, ��� ���������� �������� ��� ����������� ���������� ������, � ����� ������ �������� ����� ������� ���. �� ������ �������� ����?";
							link.l1 = "���� ���������, �� ������ ����������� �������� ���� ������������ �������?";
							link.l1.go = "TakeArsenalship";
						break;
						//========== ��� - ������� �� ������ ============
						case 4:
							dialog.text = "��, � ���� ���� ��� ��� ������������� �������, ��� ���������� �������� ��� ����������� ��������� ��� ���� ������ � ������� ����. ��� ������� � ��������...";
							link.l1 = "� ��������? ����� ��������� ������, ��� ������ ��� ��������� �������?";
							link.l1.go = "TakePirateship";
						break;
						//========== ��� - ������� �� ��������� ============
						case 5:
							dialog.text = "�� �������, ������. � ���� ���� ���������� �������, �������, ��� ��� �������, � ������ ���� �������� ���. ��� ������� � ������� � �������� ������ ��������...";
							link.l1 = "������ ��������? ����� ��������� ������, ��� ������ ��� ��������� �������?";
							link.l1.go = "TakePassenger";
						break;
						//========== ������� - ���������� ============
						case 6:
							dialog.text = "�� ��� ������ �������, �������. ��� ����� ������ ������ ��������, ��������� � ������������ ������ � ���� �������. �������, ������� � ��� � ���������� ��������� � ����� � ��������?";
							link.l1 = "��� ����� ������ � ������ ����������. ������� ���� � ���� ������������ ����, ���� ���������.";
							link.l1.go = "CustomPatrol";
						break;
							//========== ����� ��������� ============
						case 7:
							dialog.text = "� ���� ���� ��� ��� �������, ��������� � ���������� ���� ��������� �� ����������. �� ������ � ���������������� �����������?";
							link.l1 = "� � ��� ���� ������ ������ ����������� � ���� ����������. ��� ��������� ��� ��������� �������?";
							link.l1.go = "FindFugitive";
						break;
					}
				}
			}
			else
			{
				dialog.text = LinkRandPhrase("������� � ��� ������ �� ���� ���������� � �������� ������.", "�� ������� ������ ��� ��� ��� ���.", "�� ������� ��� ��, ������ ���. ��� ������� �� ������ ������ - ������.");
				link.l1 = RandPhraseSimple("����...", "��, ����� ����, "+ GetAddress_FormToNPC(NPChar) + ". ");
        		link.l1.go = "exit";
			}
		//---------------------------- ��������� ������� ���� -------------------------------
		break;

		case "sell_prisoner":
            dialog.text = "���� �� ������ ��������� �� �����?";

            qty = 1;
            for(i=0; i < GetPassengersQuantity(pchar); i++)
            {
                cn = GetPassenger(pchar,i);
                if(cn != -1)
                {
                    offref = GetCharacter(cn);
                    if(CheckAttribute(offref,"prisoned"))
                    {
        	            if(sti(offref.prisoned)==true && GetRemovable(offref)) // ������ ������ ��������
        	            {
                            attrLoc = "l"+qty;
                            link.(attrLoc)    = GetFullName(offref) + " - " + NationNameMan(sti(offref.nation)) + ".";
                            link.(attrLoc).go = "GetPrisonerIdx_" + offref.index;
                            qty++;
                        }
                    }
                }
            }
			link.l99 = "������.";
			link.l99.go = "exit";
		break;
		
		case "sell_prisoner_2":
            offref = GetCharacter(sti(pchar.GenQuest.GetPrisonerIdx));
            attrLoc =  "����, ��� ������� " + GetFullName(offref) + ", " + NationNameMan(sti(offref.nation))+ ".";
            // ���� ������� �� �����������
            qty = makeint(sti(offref.rank)*(800 + GetCharacterSPECIALSimple(NPChar, SPECIAL_L)*100) + GetCharacterSkillToOld(offref, "Leadership")*500 + GetCharacterSkillToOld(pchar, "commerce")*500);
            if (sti(offref.nation) == sti(NPChar.nation))
            {
                attrLoc = attrLoc + " � ����� �������� ���������������� �� " + FindRussianMoneyString(qty) + ".";
            }
            else
            {
                if (sti(offref.nation) == PIRATE)
                {
                    qty = qty / 5;
                    attrLoc = attrLoc + " � ���� ���� �� ����� ���������� " + FindRussianMoneyString(qty) + ". � �� ����� �� ������ �������.";

                }
                else
                {
                    qty = qty / 2;
                    attrLoc = attrLoc + " �� ����� �������� � ���� ��������� �� ����� " + FindRussianMoneyString(qty) + ".";
                }
            }
			dialog.text = attrLoc;
			pchar.PrisonerSellPrice =  qty;
			link.l1 = "�� �����. �� ��������� ���, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "sell_prisoner_3";
			link.l3 = "���. �� ������.";
			link.l3.go = "exit";
		break;


		case "sell_prisoner_3":
			dialog.text = "��� � ������.";
			link.l1 = "����� ��������.";
			link.l1.go = "exit";
			OfficersReaction("bad");

			offref = GetCharacter(sti(pchar.GenQuest.GetPrisonerIdx));
			AddMoneyToCharacter(pchar, sti(pchar.PrisonerSellPrice));
			if (sti(offref.nation) == sti(NPChar.nation))
            {
                AddCharacterExpToSkill(pchar, "Commerce", 25);
            }
            else
            {
                if (sti(offref.nation) == PIRATE)
                {
                    ChangeCharacterComplexReputation(pchar,"nobility", -2);
                }
                else
                {
                    AddCharacterExpToSkill(pchar, "Commerce", 5);
                }
            }

        	offref.location = "";
        	ReleasePrisoner(offref); // ���������� ��������
		break;
		////   CAPTURE //////////
		case "CAPTURE_Main":
            NextDiag.TempNode = "CAPTURE_Main";
			AfterTownBattle();  // ���, ��� ��������
			
			// --> ��������
			if (pchar.location == "Tortuga_townhall" && CheckAttribute(pchar, "questTemp.Sharlie.Hardcore_Tortuga"))
			{
                dialog.Text = "����! ������ ����� �� ������� ���� ���������? � ����� ��� ��� ������ ������� �������?";
                Link.l1 = "�� ������� ������� ������� �� ������ ��, ��������, ������ � ����� ����������� ������� � ���������� � ������. � � - ����������� ����� ���������!";
                Link.l1.go = "levasser";
				break;
			}
			// <-- ��������
            // fix �� ������� 5 ��� �� ��� -->
            if (!CheckNPCQuestDate(npchar, "GrabbingTownDate"))
			{
                dialog.Text = "�� ��� �� �������. ��� ��� ��� �����?";
                Link.l1 = "��, �����, ����"+ GetSexPhrase("��","����") +" �������.";
                Link.l1.go = "Exit_City";

                NPChar.NoGiveMoney = true;

            	ChangeCharacterHunterScore(GetMainCharacter(), NationShortName(sti(NPChar.nation)) + "hunter", 20);
                // ������ ������ ����� ��������� � �������
                SetReturn_Gover_Dialog_Exit(NPChar);
				break;
			}
			SetNPCQuestDate(npchar, "GrabbingTownDate");
			// fix �� ������� 5 ��� �� ��� <--

            if (CheckAttribute(FortChref, "Fort.Mode") && sti(FortChref.Fort.Mode) != FORT_DEAD)
            { // � ����-�� ���, ������ � ���� ������
                dialog.Text = "����� ����������� ��������! ����� �������� ������������ �� �����, � ��� �� ������������!";
                Link.l2 = "� �� ��������� ������� ��� �� ��� �������. ������� ���, � �� ������� ���� �����.";
                Link.l2.go = "Summ";
                Pchar.HalfOfPaymentByCity = true; // ���� �������� �����
            }
            else
            {
				dialog.Text = "�� ���� ��� ���� �����, �� ������, ��� ����� �������� ���� �������, � �� ��� ������� ����� �� ���������.";
	            if (!bWorldAlivePause || bBettaTestMode)
	            {
	                int iColony = FindColony(npchar.city);
					if (!CheckAttribute(&colonies[iColony], "notCaptured")) //��������������� ������
					{
						if (CheckAttribute(FortChref, "Default.Prison"))
	    				{
	    					Link.l1 = "�������� ���! ���� ����� ������ ����������� ���, � ���� ������� � �������� �� �������� � �������� �������. ��, �����, �������� ��� ������ � �������� �� �������.";
	    				}
	    				else
	    				{
	    					Link.l1 = "���� ����� ������ ����������� ���, � ��� ��� �������� - � ���� ���"+ GetSexPhrase("","�") +". ��, �����, ������� ����� ��������.";
	    				}
	    				Link.l1.go = "City";
					}
				}
				if (!isCityHasFort(NPChar.City))
	            {
	                Link.l2 = "������ �������? ��... ������� ��� - � �� ������� ���� �����.";
				}
				else
				{
	            	Link.l2 = "�������...����.. ������� ��� - � �� ������� ���� �����.";
	            }
				Link.l2.go = "Summ";

                bOk = !bWorldAlivePause || bBettaTestMode;
	            if (isMainCharacterPatented() && bOk && !CheckAttribute(&colonies[iColony], "notCaptured")) //�� ���� ��������� �������
	            {
					// ����������� ����� �������
					PChar.nation = GetBaseHeroNation();
					
					dialog.Text = "��� ����������� ��������! ��� �� ������� ������� �� �������, ������������� " + NationNameGenitive(sti(NPChar.nation)) + "?! �� ������ ��������� �� �����, ������������ �������� ����, � �� �����, ���������� ����� �������.";
	                Link.l1 = "� ����� ������� ������� ����������� ���, � ���� ���-�� ���������� � ���� ����������, �� ���������� �������� �� ������.";
	                Link.l1.go = "City_patent";
	                Link.l2 = "� ����������� �������� " + NationNameGenitive(sti(PChar.nation)) + " � ���������� �������, ��� ������ ��� ������� ����������� " + NationKingsCrown(PChar) + "!";
	                Link.l2.go = "City_nation";
	                Link.l3 = "��� ������� �������� ������� ������. ���� �� �� ������ �������������, �� �� ��������� ��� �������� ����� � ����� �����, � ��� ������� �� ��������� �������.";
	                Link.l3.go = "Summ_patent";
	            }
            }
        break;
		
		// --> ��������
		case "levasser":
            dialog.Text = "������?! ��������� ������ ����! � ��� � ��� ���������, � ���� ������ �����, �������! � ����� ���������� � ���, ����� �� �� ����� ������ �����!";
			Link.l1 = "������ ����, ������ ����������! � ���!";
			Link.l1.go = "levasser_1";
        break;
		
		case "levasser_1":
			chrDisableReloadToLocation = true;//������� �������
            DialogExit();
			LAi_SetImmortal(npchar, false);
			ChangeCharacterAddressGroup(npchar, pchar.location, "goto", "goto6");
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "LevasserDiedResidence");
			AddDialogExitQuest("MainHeroFightModeOn");	
        break;
		// <-- ��������
        
        case "City":
            ChangeCharacterHunterScore(GetMainCharacter(), NationShortName(sti(NPChar.nation)) + "hunter", 40);
            AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 300);

            Pchar.GenQuestFort.fortCharacterIdx = FortChref.index;
            AddDialogExitQuest("Residence_Captured_Any");

            Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_TakeTown", 1);
            // ������
            RepairAllShips();
            Log_Info("��� ������� ���������������.");
            //  �� -->
			ReOpenQuestHeader("Gen_CityCapture");
	        AddQuestRecord("Gen_CityCapture", "t3");
			AddQuestUserData("Gen_CityCapture", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + NPChar.City));
			//  �� <--
            NextDiag.CurrentNode = "Prison";
			DialogExit();
        break;

        case "City_patent":
            ChangeCharacterComplexReputation(GetMainCharacter(),"nobility", -20); // ������ ��, �� � ��� ������
            dialog.Text = "�� ���� ��� ���� �����, �� ������, ����� �������� ���� �������, � �� ��� ������� ����� �� ���������.";
			Link.l1 = "�������� ���! ��� ������� ������ ����������� ���, � ���� ������� � �������� �� �������� � �������� �������. ��, �����, �������� ��� ������ � �������� �� �������.";
			Link.l1.go = "City";
        break;

        case "Exit_for_pay":
			dialog.Text = "��� ��� �� ���� ��� �����?";
            Link.l1 = "������, �� �� � ������"+ GetSexPhrase("","�") +"...";
            Link.l1.go = "exit";

            NextDiag.TempNode = "Exit_for_pay";
		break;

        case "Exit_City":
		    NextDiag.CurrentNode = "Exit_for_pay";
		    Pchar.GenQuestFort.fortCharacterIdx = FortChref.index;
		    if (sti(NPChar.NoGiveMoney) == false) // ���� �����
		    {
				// ������ ������ ����� ��������� � �������
				SetReturn_Gover_Dialog_Exit(NPChar);
				AddDialogExitQuestFunction("TWN_ExitForPay");
            }
            DialogExit();
        break;

        case "Summ":
            dialog.Text = "��� ������ ������ �� ��������, ��� ����������� �� ���� �������. ��������� ���� �������� ������ � ���������� �������� ���� ����� �������.";
            Link.l1 = "��������� �����������.";
            Link.l1.go = "Exit_City";
            NPChar.NoGiveMoney = false;

            ChangeCharacterHunterScore(GetMainCharacter(), NationShortName(sti(NPChar.nation)) + "hunter", 30);
            AddCharacterExpToSkill(GetMainCharacter(), SKILL_FORTUNE, 200);
            AddCharacterExpToSkill(GetMainCharacter(), "Commerce", 200);

            Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_GrabbingTown", 1);
            //  �� -->
			ReOpenQuestHeader("Gen_CityCapture");
	        AddQuestRecord("Gen_CityCapture", "t2");
			AddQuestUserData("Gen_CityCapture", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + NPChar.City));
			//  �� <--
        break;

        case "Summ_patent":
            dialog.Text = "������, �� ������ ��������� ���� �������...";
            Link.l1 = "��, �� ����� ����������. ��� ��� ������?";
            Link.l1.go = "Summ";
            ChangeCharacterComplexReputation(GetMainCharacter(),"nobility", -10); // �� �� ������
        break;

        case "City_nation":
			dialog.Text = "��� �, �� ������� �� ������� �����������.";
			Link.l1 = "������� ��� ��������� �������� ������� ������, ��� ����������, ��� �� ����� �������� ��������� �������� ��������. ��������.";
			Link.l1.go = "Exit_City";
			NPChar.NoGiveMoney = true;

            ChangeCharacterComplexReputation(GetMainCharacter(),"nobility", 5);
            AddCharacterExpToSkill(GetMainCharacter(), "Leadership", 500);
            AddCharacterExpToSkill(GetMainCharacter(), "Sneak", 300);
            SetNationRelationBoth(sti(PChar.nation), sti(NPChar.nation), RELATION_ENEMY);

            PChar.questTemp.DontSetNewDialogToMayor = true; // ����� ����� ������� ������ � ��������
            PChar.questTemp.DontNullDeposit = true;    // ���� �� ������ ����������
            SetCaptureTownByNation(NPChar.City, sti(PChar.nation));
            DeleteAttribute(PChar, "questTemp.DontSetNewDialogToMayor");
            AddDialogExitQuestFunction("LaunchColonyInfoScreen"); // ��������
            //  �� -->
	    	sTemp =  GetNationNameByType(sti(PChar.nation));
			ReOpenQuestHeader("Gen_CityCapture");
	        AddQuestRecord("Gen_CityCapture", "t1");
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + NPChar.City));
			AddQuestUserData("Gen_CityCapture", "sNation", XI_ConvertString(sTemp + "Gen"));
			//  �� <--
			AddTitleNextRate(sti(PChar.nation), 1);  // ������� ������
            SetCharacterRelationBoth(sti(FortChref.index), GetMainCharacterIndex(), RELATION_FRIEND);// ������ �� ����, �� �������� OtherChar - � ��� �����, �� �� � ��� ����
            UpdateRelations();

            // 22.03.05  fix ������ ������ ����� ��������� � �������
            //  ������ ������� �� ��������
            SetReturn_Gover_Dialog_Exit(NPChar);

            Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_TakeTown", 1);
	    break;
	    
	    case "Prison":
			dialog.Text = "��� ��� �� ���� ��� ����, �������"+ GetSexPhrase("","��") +"?";
            Link.l3 = "���������"+ GetSexPhrase("","�") +", ��� ���� ����������� ��������. ��, � ������ ��� ����!";
            Link.l3.go = "exit";
            NextDiag.TempNode = "Prison";
		break;
		
		case "arestFree_1":
			dialog.text = "�������? ��� �� ���� ��� �������������?";
            link.l1 = "� �����, ����� � " + iTotalTemp*6000 + " ���� ����� ���� ������?";
			link.l1.go = "arestFree_2";
			link.l2 = "�����, ��� ����. ����� �������.";
			link.l2.go = "arest_1";
		break;

		case "arestFree_2":
            if (GetCharacterSkillToOld(PChar, SKILL_FORTUNE) >= drand(7) && iTotalTemp < 21)
            {
    			dialog.text = "�������, ����� ������� ��� �������� ����� ��������. �� ��� �� ������ ����� ��� ������, ����� �������� ����� ������������.";
    		    link.l1 = "������������! � ����� ���. ���, �������� �� �������������.";
    		    link.l1.go = "Exit";
    		    AddMoneyToCharacter(pchar, -iTotalTemp*6000);
    		    ChangeCharacterHunterScore(Pchar, NationShortName(sti(NPChar.nation)) + "hunter", -iTotalTemp);
    		    AddCharacterExpToSkill(pchar, "Fortune", 100);
            }
            else
            {
    			dialog.text = "�� ����������� ��� ����? �, ���! ���� ��������� ����� �������� ������������ ��������... ������! �������� �"+ GetSexPhrase("��","�") +" � ������!";
    		    link.l1 = "��������!";
    		    link.l1.go = "arest_2";
    		    AddCharacterExpToSkill(pchar, "Fortune", 10);
            }
		break;

		case "arest_1":
			dialog.text = "������� ����, ��� ��������. ������! ����� �"+ GetSexPhrase("��","�") +"!";
		    link.l1 = "��, �� ���!";
		    link.l1.go = "fight";
		break;

		case "arest_2":
			dialog.text = "������ ���� ���� ������! ������!";
			link.l1 = "��, �� ���! ������ ��� �� ���� �� �������!";
		    link.l1.go = "fight";
		break;    
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	����������� �����
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "DestroyGang":
			dialog.text = "�����������. �� ���������� ����� ������� � ��� ��� " + FindRussianDaysString(sti(pchar.GenQuest.DestroyGang.Terms)) + ", ���� �������������� �� ����������� ������ ����� ���������� " + FindRussianMoneyString(sti(pchar.GenQuest.DestroyGang.Money)) + ".";
			link.l1 = "������, � ������ �� ��� �������.";
		    link.l1.go = "DestroyGang_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		case "DestroyGang_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.questName = "DestroyGang"; //��� ������
			pchar.GenQuest.DestroyGang.Location = GetGangLocation(npchar); //���������� �������,��� �����
			pchar.GenQuest.DestroyGang.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			if (pchar.GenQuest.DestroyGang.Location == "none") //�� ������ ������
			{
				dialog.text = "���������, � ������ ����� � ��������� �������! ���� � ���, ��� ��� ����� ��� �������� ������� ������ �������. ��� ��� � ������� �������.";
				link.l1 = "�������. �� ��� ��, ����� ����.";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "GenQuest." + pchar.GenQuest.questName);
				DeleteAttribute(pchar, "GenQuest.questName");
			}
			else
			{
				dialog.text = "�� ��� ��, �����������! ��� ��� � ���� � ���������� � ������������ ������.";
				link.l1 = "�������, ��� �� �������� ��� ����� �����, " + GetAddress_FormToNPC(NPChar) + ".";
				link.l1.go = "exit";
				pchar.quest.DestroyGang.win_condition.l1 = "location";
				pchar.quest.DestroyGang.win_condition.l1.location = pchar.GenQuest.DestroyGang.Location;
				pchar.quest.DestroyGang.win_condition = "DestroyGang_fight";
				pchar.quest.DestroyGang.again = true; //���� ���������� ������ ���� ������� �� �����
				SetTimerCondition("AllMayorsQuests_Late", 0, 0, sti(pchar.GenQuest.DestroyGang.Terms), false);
				//==> ����������� � ��������� ������� �� ����� 
				locations[FindLocation(pchar.GenQuest.DestroyGang.Location)].DisableEncounters = true;
				ReOpenQuestHeader("MayorsQuestsList");
				AddQuestRecord("MayorsQuestsList", "1");
				AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
				AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
				makearef(arName, pchar.GenQuest.DestroyGang);
				AddQuestUserData("MayorsQuestsList", "GangName", GetFullName(arName));
				AddQuestUserData("MayorsQuestsList", "sDay", FindRussianDaysString(sti(pchar.GenQuest.DestroyGang.Terms)));
				AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.DestroyGang.Money)));
			}
		break;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	�����������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "TakePostcureer":
			//��������� ����������
			pchar.GenQuest.questName = "TakePostcureer"; //��� ������
			pchar.GenQuest.TakePostcureer.Nation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.GenQuest.TakePostcureer.Nation) == PIRATE) pchar.GenQuest.TakePostcureer.Nation = GetEnemyNationToMainCharacter();
			pchar.GenQuest.TakePostcureer.City = FindEnemyCityToMC(false);
			pchar.GenQuest.TakePostcureer.Island = GetArealByCityName(pchar.GenQuest.TakePostcureer.City);
			pchar.GenQuest.TakePostcureer.Terms = GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(PChar)].id, pchar.GenQuest.TakePostcureer.Island)+5;
			pchar.GenQuest.TakePostcureer.LoginDay = sti(pchar.GenQuest.TakePostcureer.Terms)-1;
			pchar.GenQuest.TakePostcureer.ShipType = SelectCureerShipType();
			pchar.GenQuest.TakePostcureer.ShipName = GenerateRandomNameToShip(sti(pchar.GenQuest.TakePostcureer.Nation));
			pchar.GenQuest.TakePostcureer.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.TakePostcureer.ShipType));
			pchar.GenQuest.TakePostcureer.Money = ((dRand(5)+drand(6)+4)*1000)+(sti(pchar.rank)*500);
			dialog.text = "�������. ��� ���������� ����� ���������� ������� "+NationNameGenitive(sti(pchar.GenQuest.TakePostcureer.Nation))+" ��� ��������� '"+pchar.GenQuest.TakePostcureer.ShipName+"', ������������ ��� � �������� ��� ������, ������� ������ � ����������� �����. ��������� ���� ����� ����� ��������� � "+XI_ConvertString("Colony"+pchar.GenQuest.TakePostcureer.City+"Gen")+" �������� ����� "+FindRussianDaysString(pchar.GenQuest.TakePostcureer.Terms)+".";
			link.l1 = "������, � ������ �� ��� �������. � ��� �� ������ ������� ������?";
		    link.l1.go = "TakePostcureer_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "TakePostcureer_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.TakePostcureer.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "�������� ���������������. ���, ����� �������, ����� ����������� ����� ������ ��� ���� ���������. �� ��� �������� � ������� �� �����, ������ ��������� ��� ���� ����� �������. �� ��� ������ � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.TakePostcureer.Money))+"\n����, � ��� ��� � ���� � ���������� � ������������ ������.";
			link.l1 = "�������, ��� �� �������� ��� ����� �����, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			pchar.quest.TakePostcureer.win_condition.l1 = "location";
			pchar.quest.TakePostcureer.win_condition.l1.location = pchar.GenQuest.TakePostcureer.Island;
			pchar.quest.TakePostcureer.win_condition.l2 = "Timer";
			pchar.quest.TakePostcureer.win_condition.l2.date.hour  = sti(GetTime());
			pchar.quest.TakePostcureer.win_condition.l2.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.TakePostcureer.LoginDay));
			pchar.quest.TakePostcureer.win_condition.l2.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.TakePostcureer.LoginDay));
			pchar.quest.TakePostcureer.win_condition.l2.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.TakePostcureer.LoginDay));
			pchar.quest.TakePostcureer.function = "TakePostcureer_CreateShip";
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, sti(pchar.GenQuest.TakePostcureer.Terms), false);
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "3");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.TakePostcureer.City+"Gen"));
			AddQuestUserData("MayorsQuestsList", "sDay", FindRussianDaysString(sti(pchar.GenQuest.TakePostcureer.Terms)));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.TakePostcureer.Money)));
			AddQuestUserData("MayorsQuestsList", "sNation", NationNameGenitive(sti(pchar.GenQuest.TakePostcureer.Nation)));
			AddQuestUserData("MayorsQuestsList", "sShipName", pchar.GenQuest.TakePostcureer.ShipName);
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	���������� - ���������� ������� � ���������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "TakeArsenalship":
			//��������� ����������
			pchar.GenQuest.questName = "TakeArsenalship"; //��� ������
			pchar.GenQuest.TakeArsenalship.Nation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.GenQuest.TakeArsenalship.Nation) == PIRATE) pchar.GenQuest.TakeArsenalship.Nation = GetEnemyNationToMainCharacter();
			pchar.GenQuest.TakeArsenalship.City = FindEnemyCityToMC(false);
			pchar.GenQuest.TakeArsenalship.Island = GetArealByCityName(pchar.GenQuest.TakeArsenalship.City);
			pchar.GenQuest.TakeArsenalship.Terms = GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(PChar)].id, pchar.GenQuest.TakeArsenalship.Island)+5;
			pchar.GenQuest.TakeArsenalship.LoginDay = sti(pchar.GenQuest.TakeArsenalship.Terms)-1;
			pchar.GenQuest.TakeArsenalship.ShipType = SelectArsenalShipType();
			pchar.GenQuest.TakeArsenalship.ShipTypeA = SelectCureerShipType();
			pchar.GenQuest.TakeArsenalship.ShipName = GenerateRandomNameToShip(sti(pchar.GenQuest.TakeArsenalship.Nation));
			pchar.GenQuest.TakeArsenalship.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.TakeArsenalship.ShipType));
			pchar.GenQuest.TakeArsenalship.CannonA = SelectLevelCannonParameter(sti(pchar.GenQuest.TakeArsenalship.ShipTypeA)); // Addon 2016-1 Jason ��������� �������
			pchar.GenQuest.TakeArsenalship.Money = ((dRand(5)+drand(6)+4)*900)+(sti(pchar.rank)*500);
			dialog.text = "�������. ��� ����� ���������� ����� ������� ��������� "+NationNameGenitive(sti(pchar.GenQuest.TakeArsenalship.Nation))+", ����������� ����� � ����������, ����� ��� ��������� '"+pchar.GenQuest.TakeArsenalship.ShipName+"', � ���������� ���. ���� �� ������ ����� ��������� �������\n��������� ��������� ����� ���� � ������� ������� � ������� "+XI_ConvertString("Colony"+pchar.GenQuest.TakeArsenalship.City)+", � ����� ��� �������� ����� "+FindRussianDaysString(pchar.GenQuest.TakeArsenalship.Terms)+", ��� ��� ��� ������� ������������.";
			link.l1 = "������, � ������ �� ��� �������. ��� ����� �������� ��� ��������� ����� � ���������?";
		    link.l1.go = "TakeArsenalship_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "TakeArsenalship_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.TakeArsenalship.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "��� ������, ��� ���� ��� �������� �� �����. ������� - ����� ���� �� ������ �� ����������. ���� �� ���������� � ���� ����������, � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.TakeArsenalship.Money))+"... ����� �� ���������� ���, �������.";
			link.l1 = "�������, ��� �� �������� ��� ����� �����, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			pchar.quest.TakeArsenalship.win_condition.l1 = "location";
			pchar.quest.TakeArsenalship.win_condition.l1.location = pchar.GenQuest.TakeArsenalship.Island;
			pchar.quest.TakeArsenalship.win_condition.l2 = "Timer";
			pchar.quest.TakeArsenalship.win_condition.l2.date.hour  = sti(GetTime());
			pchar.quest.TakeArsenalship.win_condition.l2.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.TakeArsenalship.LoginDay));
			pchar.quest.TakeArsenalship.win_condition.l2.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.TakeArsenalship.LoginDay));
			pchar.quest.TakeArsenalship.win_condition.l2.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.TakeArsenalship.LoginDay));
			pchar.quest.TakeArsenalship.function = "TakeArsenalship_CreateShip";
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, sti(pchar.GenQuest.TakeArsenalship.Terms), false);
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "8");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.TakeArsenalship.City));
			AddQuestUserData("MayorsQuestsList", "sDay", FindRussianDaysString(sti(pchar.GenQuest.TakeArsenalship.Terms)));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.TakeArsenalship.Money)));
			AddQuestUserData("MayorsQuestsList", "sNation", NationNameGenitive(sti(pchar.GenQuest.TakeArsenalship.Nation)));
			AddQuestUserData("MayorsQuestsList", "sShipName", pchar.GenQuest.TakeArsenalship.ShipName);
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	��� - ���������� ������� �������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "TakePirateship":
			//��������� ����������
			pchar.GenQuest.questName = "TakePirateship"; //��� ������
			pchar.GenQuest.TakePirateship.City = FindEnemyCityToMC(false);
			pchar.GenQuest.TakePirateship.Island = GetArealByCityName(pchar.GenQuest.TakePirateship.City);
			pchar.GenQuest.TakePirateship.Terms = GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(PChar)].id, pchar.GenQuest.TakePirateship.Island)+5;
			pchar.GenQuest.TakePirateship.ShipType = SelectCureerShipType();
			pchar.GenQuest.TakePirateship.ShipName = GenerateRandomNameToShip(PIRATE);
			pchar.GenQuest.TakePirateship.Name = GenerateRandomName(PIRATE, "man");
			pchar.GenQuest.TakePirateship.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.TakePirateship.ShipType));
			pchar.GenQuest.TakePirateship.Money = ((dRand(5)+drand(6)+4)*1200)+(sti(pchar.rank)*500);
			dialog.text = "����������. ���� ��������� ������� �� ���� ������ ������������ ������ ���������� �������� �� ����� "+pchar.GenQuest.TakePirateship.Name+". �������� ��������� ������� ������� ����� ������, � ����� ������ �������� ����� ���������. ������ ������ ��� �������� � ���� �������� ��� ������ �������, ��������� ��� ����� �������� �����, ��� �� � ������ ����� ����������. �� ������ ����������� � ���� � ��������� � ������ ����� ������?";
			link.l1 = "����� �� �����! ��� ������ ����� ��������������?";
		    link.l1.go = "TakePirateship_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "TakePirateship_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.TakePirateship.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "� ��������� "+FindRussianDaysString(pchar.GenQuest.TakePirateship.Terms)+" ��� ������� ��� ��������� '"+pchar.GenQuest.TakePirateship.ShipName+"' ����� ������������ � ������� �������� �� "+XI_ConvertString("Colony"+pchar.GenQuest.TakePirateship.City+"Gen")+". ������� ��� � ����������. ��������� �� ���� ����� ������ � ��������, �������� �� ������� - ��� �� �����, ���� �� ���� ��������� ����� �������� ���������� ����� ����� ������������\n�� ���������� ���� ������ � ����� ��������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.TakePirateship.Money))+". �� ������� �������, �������: ������� �� ����� ����� ��� � "+XI_ConvertString("Colony"+pchar.GenQuest.TakePirateship.City+"Gen")+" �����. ��������, � �� ������� ��� ���!";
			link.l1 = "��� �������� �����, " + GetAddress_FormToNPC(NPChar) + "! ��������� �� �������� ���� ����� �����!";
			link.l1.go = "exit";
			pchar.quest.TakePirateship.win_condition.l1 = "location";
			pchar.quest.TakePirateship.win_condition.l1.location = pchar.GenQuest.TakePirateship.Island;
			pchar.quest.TakePirateship.function = "TakePirateship_CreateShip";
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, sti(pchar.GenQuest.TakePirateship.Terms), false);
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "9");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.TakePirateship.City+"Gen"));
			AddQuestUserData("MayorsQuestsList", "sDay", FindRussianDaysString(sti(pchar.GenQuest.TakePirateship.Terms)));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.TakePirateship.Money)));
			AddQuestUserData("MayorsQuestsList", "sName", pchar.GenQuest.TakePirateship.Name);
			AddQuestUserData("MayorsQuestsList", "sShipName", pchar.GenQuest.TakePirateship.ShipName);
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	��� - ��������� ���������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "TakePassenger":
			//��������� ����������
			pchar.GenQuest.questName = "TakePassenger"; //��� ������
			pchar.GenQuest.TakePassenger.City = FindEnemyCityToMC(false);
			pchar.GenQuest.TakePassenger.CityA = SelectAnyColony(pchar.GenQuest.TakePassenger.City);
			pchar.GenQuest.TakePassenger.Nation = GetEnemyNationToMainCharacter();//��������� �����
			while (sti(pchar.GenQuest.TakePassenger.Nation) == PIRATE) pchar.GenQuest.TakePassenger.Nation = GetEnemyNationToMainCharacter();
			pchar.GenQuest.TakePassenger.Terms1 = GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(PChar)].id, GetArealByCityName(pchar.GenQuest.TakePassenger.City));
			pchar.GenQuest.TakePassenger.Terms2 = GetMaxDaysFromIsland2Island(GetArealByCityName(pchar.GenQuest.TakePassenger.City), GetArealByCityName(pchar.GenQuest.TakePassenger.CityA))+1;
			pchar.GenQuest.TakePassenger.Terms = sti(pchar.GenQuest.TakePassenger.Terms1)+sti(pchar.GenQuest.TakePassenger.Terms2);
			pchar.GenQuest.TakePassenger.ShipType = SelectCureerShipType();
			pchar.GenQuest.TakePassenger.ShipName = GenerateRandomNameToShip(sti(pchar.GenQuest.TakePassenger.Nation));
			pchar.GenQuest.TakePassenger.Name = GenerateRandomName(sti(pchar.GenQuest.TakePassenger.Nation), "man");
			pchar.GenQuest.TakePassenger.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.TakePassenger.ShipType));
			pchar.GenQuest.TakePassenger.Money = ((dRand(5)+drand(6)+4)*1100)+(sti(pchar.rank)*500);
			string sText = SelectPassText();
			dialog.text = "����������. ���� ����� � �������� �� ����� "+pchar.GenQuest.TakePassenger.Name+". "+sText+" � ����� ���������� ���, �, �������, ��� ������� �������� ����������� ��������, ��� ��� ������. ��� �����, ����� �� ��������� ���� ����� ��������, ������ �����. � ���� ������������ �������� ��� �� ������� ������ ������. �� ������ ������� �� ��� ����?";
			link.l1 = "�����, " + GetAddress_FormToNPC(NPChar) + ". ��� ��� ������ ����� �������?";
		    link.l1.go = "TakePassenger_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "TakePassenger_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.TakePassenger.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "��������� ����� "+FindRussianDaysString(pchar.GenQuest.TakePassenger.Terms1)+", ��, � �������� ���������, �� ������� ��� ��������� '"+pchar.GenQuest.TakePassenger.ShipName+"', ������ �� "+XI_ConvertString("Colony"+pchar.GenQuest.TakePassenger.City+"Gen")+" � ���������� � "+XI_ConvertString("Colony"+pchar.GenQuest.TakePassenger.CityA+"Acc")+". � ��� � ������������ �� ����� "+FindRussianDaysString(pchar.GenQuest.TakePassenger.Terms)+", ����� ����� ���� ������� �� ��������� ������� ����, ����� �� ������� � ��������� ��� ���������� ��� �������� � ����. ���� �� ��������� ��� ���������, � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.TakePassenger.Money))+". ����� �����, �������!";
			link.l1 = "�� ���� ������ �������, " + GetAddress_FormToNPC(NPChar) + "! ���������� ����������� � ����.";
			link.l1.go = "exit";
			SetFunctionTimerCondition("TakePassenger_CreateShip", 0, 0, sti(pchar.GenQuest.TakePassenger.Terms1), false);
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, sti(pchar.GenQuest.TakePassenger.Terms), false);
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "10");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.TakePassenger.City+"Gen"));
			AddQuestUserData("MayorsQuestsList", "sCityA", XI_ConvertString("Colony"+pchar.GenQuest.TakePassenger.CityA+"Acc"));
			AddQuestUserData("MayorsQuestsList", "sDay1", FindRussianDaysString(sti(pchar.GenQuest.TakePassenger.Terms1)));
			AddQuestUserData("MayorsQuestsList", "sDay2", FindRussianDaysString(sti(pchar.GenQuest.TakePassenger.Terms)));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.TakePassenger.Money)));
			AddQuestUserData("MayorsQuestsList", "sName", pchar.GenQuest.TakePassenger.Name);
			AddQuestUserData("MayorsQuestsList", "sShipName", pchar.GenQuest.TakePassenger.ShipName);
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	���������� �������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "CustomPatrol":
			//��������� ����������
			pchar.GenQuest.questName = "CustomPatrol"; //��� ������
			pchar.GenQuest.CustomPatrol.Nation = sti(npchar.nation);//�����
			pchar.GenQuest.CustomPatrol.Island = Islands[GetCharacterCurrentIsland(PChar)].id;
			pchar.GenQuest.CustomPatrol.LoginDay = rand(4)+1;
			pchar.GenQuest.CustomPatrol.Loginlocator = rand(3)+4;
			pchar.GenQuest.CustomPatrol.ShipType = SelectCureerShipType();
			pchar.GenQuest.CustomPatrol.ShipTypeA = SelectCureerShipType();
			pchar.GenQuest.CustomPatrol.Cannon = SelectLevelCannonParameter(sti(pchar.GenQuest.CustomPatrol.ShipType));
			pchar.GenQuest.CustomPatrol.Money = ((dRand(5)+drand(6)+4)*700)+(sti(pchar.rank)*300);
			dialog.text = "� ������� ����������� �������� � ���, ��� ����� ������� ����������� � ������ � ���������-���������������� � ������� ������ �����. ��� ��� ������ ���� ��������, ������ ������ ���� �������� ������ � ����� ������� ��������������� ��� �����������\n�������� ����������� � ���, ��� � �� ���� �� ������� �������, �� ����, �� �����, ��� �������������� ����� �����������. �������� ���� ��, ��� ���������� ������ ����� ��������� � ������� ��������� ���� ���� �� ����� �������. ��� �����, ��� ��� ���������� ������� ������ ���� �� �������, ���� ������������� ��� ������ ����� � �� ����� ��������� ��������\n� ��������� ��� �������� ���� �������� - ��������� ��������������� � ����������� � ���� ������ ������������ ��������, ����� ������ ��������� ����. �� ������ ��������� ��� ���������?";
			link.l1 = "�����, " + GetAddress_FormToNPC(NPChar) + ". �������, �����, ���� �����-�� �������, ��������, ��� ��������, ��� ��� �������� ��� �����?";
		    link.l1.go = "CustomPatrol_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "CustomPatrol_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.CustomPatrol.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "��� �������� ������ ���� ��, ��� ������ ��������� � ����������� ���������. � ��� ��. ��� ��� ��� �������� ����������� �������� �� ����� ��������������� ���������, ������� �������� � ����� ���������. ���� �� ������� ���������� � ����, �� � ������� ��� �������������� � ������� "+FindRussianMoneyString(sti(pchar.GenQuest.CustomPatrol.Money))+"\n����� ����, �������� ����������� ��������������, � �������� ��� ������� ���� ���� ������������� ����, ������� �� ������. ������������, �������, � ��� �������, ��� �� �� ������� ������� ��� � ����� ������.";
			link.l1 = "�� ��� ��, � ��������� � �������������� ��� ����� �������, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, 6, false);
			pchar.quest.CustomPatrol.win_condition.l1 = "location";
			pchar.quest.CustomPatrol.win_condition.l1.location = pchar.GenQuest.CustomPatrol.Island;
			pchar.quest.CustomPatrol.win_condition.l2 = "Timer";
			pchar.quest.CustomPatrol.win_condition.l2.date.hour  = sti(GetTime()+rand(8));
			pchar.quest.CustomPatrol.win_condition.l2.date.day   = GetAddingDataDay(0, 0, sti(pchar.GenQuest.CustomPatrol.LoginDay));
			pchar.quest.CustomPatrol.win_condition.l2.date.month = GetAddingDataMonth(0, 0, sti(pchar.GenQuest.CustomPatrol.LoginDay));
			pchar.quest.CustomPatrol.win_condition.l2.date.year  = GetAddingDataYear(0, 0, sti(pchar.GenQuest.CustomPatrol.LoginDay));
			pchar.quest.CustomPatrol.function = "CustomPatrol_CreateShip";
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "11");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.CustomPatrol.Money)));
		break;
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	����� ���������
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "FindFugitive":
			//��������� ����������
			pchar.GenQuest.questName = "FindFugitive"; //��� ������
			pchar.GenQuest.FindFugitive.Startcity = npchar.city;
			pchar.GenQuest.FindFugitive.City = SelectFugitiveCity();
			pchar.GenQuest.FindFugitive.Chance = rand(2);
			pchar.GenQuest.FindFugitive.Name = GenerateRandomName(sti(npchar.Nation), "man");
			pchar.GenQuest.FindFugitive.Money = ((dRand(5)+drand(6)+4)*1300)+(sti(pchar.rank)*600);
			sText = SelectFugitiveText();
			log_testinfo(pchar.GenQuest.FindFugitive.City);
			log_testinfo(FindRussianDaysString(sti(pchar.GenQuest.FindFugitive.Chance)));
			dialog.text = "�������� � �������. ��������� ������ ���������� ������� - "+sText+". ������� ��� ����������� � ��������, �� �� ��� ��������� �������, ��� �������� ������� ����� ������� � ����� �� �� ���������\n� ��������� ��� �������� ��������� �����, ��������� �������, ���������� � ��������� ����: ������������ - ������ ���������, � �� ����� �������� ��� ���������. �� ������ ������� �� ��� ����?";
			link.l1 = "�����, " + GetAddress_FormToNPC(NPChar) + ". �� ������ ������� ��� ���������?";
		    link.l1.go = "FindFugitive_agree";
			link.l2 = "��... ���, �������, � ��������.";
		    link.l2.go = "All_disagree";
		break;
		
		case "FindFugitive_agree":
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
			pchar.GenQuest.FindFugitive.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
			dialog.text = "��, �������. ��� ����� "+pchar.GenQuest.FindFugitive.Name+". ����������, ��� �� ����� ���� � ���� ������� �����, ��� ��� ������������ ���������������� �� ������� ������. �� ������ � ������ ��� ���� �����, ��� ��� �����, ��� �� ��������� ����� ����� ������ ������� ����� ��� ������������. ���� �� ������� ��������� ��� ���������, � ������� ��� "+FindRussianMoneyString(sti(pchar.GenQuest.FindFugitive.Money))+".";
			link.l1 = "�� ���� ������ �������, " + GetAddress_FormToNPC(NPChar) + "! ���������� ����������� � ����.";
			link.l1.go = "exit";
			SetTimerCondition("AllMayorsQuests_Late", 0, 0, 30, false);
			ReOpenQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "12");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
			AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.FindFugitive.Money)));
			AddQuestUserData("MayorsQuestsList", "sName", pchar.GenQuest.FindFugitive.Name);
			//������� ���������
			sld = GetCharacter(NPC_GenerateCharacter("Fugitive", "citiz_"+(21+rand(9)), "man", "man", sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, sti(npchar.nation), 30, true, "soldier"));
			SetFantomParamFromRank(sld, sti(pchar.rank)+MOD_SKILL_ENEMY_RATE, true);
			sld.name = pchar.GenQuest.FindFugitive.Name;
			sld.lastname = "";
			sld.dialog.FileName = "MayorQuests_dialog.c";
			sld.greeting = "marginal";
		break;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//	������������� �� ���������� �����
		/////////////////////////////////////////////////////////////////////////////////////////////////
		case "Intelligence":
			dialog.text = "� �������. ��������, �������������� � " + FindRussianMoneyString(sti(pchar.GenQuest.Intelligence.Money)) + " ������ ��� ��� ������� ��������.";
			link.l1 = "��, ��� ������� ������... � ������ �� ��� �������.";
		    link.l1.go = "Intelligence_agree";
			link.l2 = "��... ���, �������, � �������� - ������� ������.";
		    link.l2.go = "All_disagree";
		break;
		case "Intelligence_agree":
			if (pchar.GenQuest.Intelligence.City == "none" || isBadReputation(pchar, 30)) //�� ������ ������
			{
				dialog.text = "����, � �� ���� �������, ��� ���� �������� ��� � ������ ����... �������, � �� ��� ��� ��� �������.";
				link.l1 = "�-��, ������... �� ��� ��, ����� ����.";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "GenQuest." + pchar.GenQuest.questName);
			}
			else
			{
				npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_complete";
				pchar.GenQuest.questName = "Intelligence"; //��� ������
				sTemp = pchar.GenQuest.Intelligence.City;
				switch (rand(4))
				{
					case 0:	sTemp += "_Priest";		break;
					case 1:	sTemp += "_trader";		break;
					case 2:	sTemp += "_shipyarder"; break;
					case 3:	sTemp += "_usurer";	    break;
					case 4:	sTemp += "_PortMan";	break;
				}
				pchar.GenQuest.Intelligence.SpyId = sTemp; //Id ������ ������ � ������
				dialog.text = "���������! ������ �� ����. � " + XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Dat") + " ��� ���������� ��������� �������� " + GetWorkTypeOfMan(&characters[GetCharacterIndex(sTemp)], "Gen") + 
					", ��� ����� " + GetFullName(&characters[GetCharacterIndex(sTemp)]) + ". ��� �� ������� �� ���, � �������� ����� ����������. �� �������� ����� ������ ����� ��� � ���� � ��� ��� " + FindRussianDaysString(sti(pchar.GenQuest.Intelligence.Terms)) + ". � ������ � ����, ��� �� ����� ������� ����. � ������ ������ ����������� � ������, ����� �� ����� ���������� ���� ����� � �� ����� �� �������. ��� �� ����?";
				link.l1 = "��, � �� �����"+ GetSexPhrase("","�") +", " + GetAddress_FormToNPC(NPChar) + ". ���������� ��������� � ���������� �������.";
				link.l1.go = "exit";
				pchar.GenQuest.Intelligence.MayorId  = npchar.id; //Id ����, ����� �����, ��� ��� �����
				SaveCurrentQuestDateParam("GenQuest.Intelligence"); //������ ���� ��������� ������
				ReOpenQuestHeader("MayorsQuestsList");
				AddQuestRecord("MayorsQuestsList", "6");
				AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
				AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
				AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Acc"));
				AddQuestUserData("MayorsQuestsList", "sIsland", XI_ConvertString(colonies[FindColony(pchar.GenQuest.Intelligence.City)].islandLable+"Dat"));
				AddQuestUserData("MayorsQuestsList", "sWho", GetWorkTypeOfMan(&characters[GetCharacterIndex(sTemp)], "Gen"));
				AddQuestUserData("MayorsQuestsList", "SpyName", GetFullName(&characters[GetCharacterIndex(sTemp)]));			
				AddQuestUserData("MayorsQuestsList", "sDay", FindRussianDaysString(sti(pchar.GenQuest.Intelligence.Terms)));
				AddQuestUserData("MayorsQuestsList", "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Intelligence.Money)));
				AddQuestUserData("MayorsQuestsList", "sCity2", XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Dat"));
			}
		break;
		case "Intelligence_ExecuteLate":
			QuestName = pchar.GenQuest.questName;
			pchar.GenQuest.(QuestName).Money = sti(pchar.GenQuest.(QuestName).Money) / 2);
			dialog.text = RandPhraseSimple("��� �������. ������, �� �� ��������� � ��������� �����, ������� � �������� ��������� ����� ������ ��������������. ��� ������� ������ ���������� " + FindRussianMoneyString(sti(pchar.GenQuest.(QuestName).Money)) + ". �������� ��������.", 
				"��� ������. ������ �� �� ��������� � ��������� �����, � � ���� ��� ������ ������. �� ������� ��� �����, ������� � �������� ��������� ����� ������ ��������. ����, � ��� �� ��� ������� ��� ���������� �������������� - " + FindRussianMoneyString(sti(pchar.GenQuest.(QuestName).Money))  + ". �������� ��������.");
			link.l1 = "�� ������"+ GetSexPhrase("","�") +" ��, ��� ��� ��� �������, ��, � ����� ������, ������������� ����� ������������� ���� ��������. ������� � ��������� �� ����, " + GetAddress_FormToNPC(NPChar) + ".";
		    link.l1.go = "All_Execute_1";
			//--> �����
			AddSimpleRumour(RandPhraseSimple("�� ������, ���������� " + GetFullName(npchar) + " �� ����� ������� �������������� ������� �������� " + GetMainCharacterNameGen() + ".", 
				"���������� " + GetFullName(npchar) + " �� ����� ������� ��������� " + GetMainCharacterNameDat() + ", �"+ GetSexPhrase("��","�") +" ��������"+ GetSexPhrase("","�") +" ��� ���������, �� �� �����"+ GetSexPhrase("","�") +" � ������������� �����..."), sti(npchar.nation), 5, 1);
			//<-- �����
		break;
		
		// -------------- ����� ����� ��� ���� ������� ���� ------------------
		case "All_disagree":
			dialog.text = "�� ��������������� ����!";
			link.l1 = "����� ��������, " + GetAddress_FormToNPC(NPChar) + ", �� �� ��� ���� � ������� �� ����.";
		    link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			
			if (CheckAttribute(pchar, "GenQuest.questName"))
			{
				QuestName = pchar.GenQuest.questName;
				DeleteAttribute(pchar, "GenQuest." + QuestName);
				DeleteAttribute(pchar, "GenQuest.questName");
			}
		break;
		case "All_Late":
			QuestName = pchar.GenQuest.questName;
			dialog.text = RandPhraseSimple("��, ��� � ���� ������� - ����� �����. � ����������� �� ���, � � ����� ������� �������� �����. � �����������.", 
				"�-��, ����������, � ����������� � ��� ��������... � ���� � ���������� ������ ����� ������, �������� ��������� ����� ���������, � � ������ ����� �� ���. �-��...");
			link.l1 = "��������, " + GetAddress_FormToNPC(NPChar) + ", � ������ ��, ��� ���.";
		    link.l1.go = "exit";
			//--> �����
			AddSimpleRumour(LinkRandPhrase("�� ������, ���������� " + GetFullName(npchar) + " ����� ��������� ��������� " + GetMainCharacterNameDat() + ". �������������, ��� �� ����� ��������� ��� ���������!", 
				"���������� " + GetFullName(npchar) + " ��������� �������� ���, ��� ����� ������� " + GetFullName(pchar) + " ������ �� ����, �� �� ����� ��������� ��� � ����. ��������...", 
				"� ������, ��� ���������� " + GetFullName(npchar) + " ����� ��������� ����, ������� " + GetFullName(pchar) + ", ��� ��� �� �� ������ ��������� ��� ������� � ������������� ����."), sti(npchar.nation), 5, 1);
			//<-- �����
			ChangeCharacterComplexReputation(pchar,"nobility", -4);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			DeleteAttribute(pchar, "GenQuest." + QuestName);
			DeleteAttribute(pchar, "GenQuest.questName");
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_common"; //������� �������
			SaveCurrentNpcQuestDateParam(npchar, "work_date"); //����� ��� ���� �� ����
			CloseQuestHeader("MayorsQuestsList");
		break;
		case "All_Found":
			QuestName = pchar.GenQuest.questName;
			dialog.text = RandPhraseSimple("� ������ � ����! ������ ��������� ����, �� �� ������������ � ����������� ���� � �������� ������������� - ���, ������ ��, ���� �������������. � �����������!", 
				"�-��, ����������, � ����������� � ���. ���� ����� ����, ����� ����� � ����������. � ���� � ���������� ���������� ���������� �����������, ������� ��������� ������ ���� ������. ������ � �������� � ����?..");
			link.l1 = "��������, " + GetAddress_FormToNPC(NPChar) + ", �� � �� ���� ��������� ����������� ������ ��� �����������.";
		    link.l1.go = "exit";
			//--> �����
			AddSimpleRumour(LinkRandPhrase("�� ������, ���������� " + GetFullName(npchar) + " ����� ��������� ��������� " + GetMainCharacterNameDat() + ". �������������, "+ GetSexPhrase("�� �������� ��������� ������","��� ��������� ��������� ��������") +"!", 
				"���������� " + GetFullName(npchar) + " ��������� �������� ���, ��� ����� ������� " + GetFullName(pchar) + " ����"+ GetSexPhrase("��","���") +" �� ����, �� �� �����"+ GetSexPhrase("","�") +" ��� ��������� ��-�� ����������� ���������������. ��-��, ����� �������� �����!", 
				"� ������, ��� ���������� " + GetFullName(npchar) + " ����� ��������� ����, ������� " + GetFullName(pchar) + ". �������, �� �������� ����"+ GetSexPhrase("","���") +"..."), sti(npchar.nation), 5, 1);
			//<-- �����
			ChangeCharacterComplexReputation(pchar,"nobility", -6);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			DeleteAttribute(pchar, "GenQuest." + QuestName);
			DeleteAttribute(pchar, "GenQuest.questName");
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_common"; //������� �������
			SaveCurrentNpcQuestDateParam(npchar, "work_date"); //����� ��� ���� �� ����
			CloseQuestHeader("MayorsQuestsList");
			AddQuestRecord("MayorsQuestsList", "21");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+npchar.city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(npchar));
		break;
		case "All_Execute":
			QuestName = pchar.GenQuest.questName;
			dialog.text = RandPhraseSimple("���������� �������! �� ��� ��, ���� �������� �����. ��� ������� ���������� " + FindRussianMoneyString(sti(pchar.GenQuest.(QuestName).Money)) + ". �������� ��������.", 
				"�����������! ��� ����� ����� ��� ����... ����, ��� ������� ��� ���������� �������������� - " + FindRussianMoneyString(sti(pchar.GenQuest.(QuestName).Money))  + ". �������� ��������.");
			link.l1 = "�������, " + GetAddress_FormToNPC(NPChar) + ", " + RandPhraseSimple("������� ����� � ���� ����!", "� ������� �������"+ GetSexPhrase("","�") +" ��������� ��������������.");
		    link.l1.go = "All_Execute_1";
			//--> �����
			AddSimpleRumour(LinkRandPhrase("�� ������, ���������� " + GetFullName(npchar) + " ����� ������ �� ���������������� ���"+ GetSexPhrase("���� ��������","�� �������") +" " + GetMainCharacterNameGen() + ".", 
				"���������� " + GetFullName(npchar) + " ����������� �������� " + GetMainCharacterNameGen() + ", �"+ GetSexPhrase("��","�") +" ����� ��������� ��� ��� ���������. ����������� ������� ��� �����������, � ��� �����...", 
				"� ������, ��� ���������� " + GetFullName(npchar) + " ����� ������� ����, ������� " + GetFullName(pchar) + ". �� ������������� ��� ��� ����������� � ��������������� �������. ������� ��� �������, �������..."), sti(npchar.nation), 5, 1);
			//<-- �����
		break;
		case "All_Execute_1":
			QuestName = pchar.GenQuest.questName;
			dialog.text = RandPhraseSimple("��, ��� � ������. ������ �������� �� ��� ���, ��������, � ����� ��� ��� ������.", "�� ��� ��, ���������! �������, � ���� ��� ���������� ��� ������ ��������� ����.");
			link.l1 = RandPhraseSimple("�������.", "���������.");
		    link.l1.go = "exit";
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.(QuestName).Money));
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 5);
			CloseQuestHeader("MayorsQuestsList");
			ChangeCharacterComplexReputation(pchar,"nobility", 4);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(PChar, "Leadership", 80);
			OfficersReaction("good"); // dlc
			
			DeleteAttribute(pchar, "GenQuest." + QuestName);
			DeleteAttribute(pchar, "GenQuest.questName");
			npchar.greeting = NationShortName(sti(npchar.nation)) + "_gov_common"; //������� �������
			SaveCurrentNpcQuestDateParam(npchar, "work_date"); //����� ��� ���� �� ����
			// ��������� � ���� ������� �����
			sTemp = npchar.City;
			if (!CheckAttribute(pchar, "GenQuest.MayorQuestsList." + sTemp)) pchar.GenQuest.MayorQuestsList.(sTemp) = 0;
			pchar.GenQuest.MayorQuestsList.(sTemp) = sti(pchar.GenQuest.MayorQuestsList.(sTemp)) + 1;
		break;
//<-- ����� homo
		case "siege_task":
            makearef(aData, NullCharacter.Siege);
            aData.HelpColony = true;
			dialog.text = "� ����� ������ ����� ����� ������ ����� ��� ���. �� ��������� ���� ������ - �������� ��� �������� �������, � �� ������ �������������.";
			link.l1 = "��� �� ����� �������.";
		    link.l1.go = "exit";
		break;
		
		//Jason --> ����� ��������
		case "Sharlie":
			dialog.text = "�� ����� ������ �� �����? ����� ���������... � ����� �� �� ��� �����������?";
			link.l1 = "� ��� ����. ��� ���� ����� � ���� � � ������ �������� ��� �� ����...";
			link.l1.go = "Sharlie_1";			
		break;
		
		case "Sharlie_1":
			dialog.text = "��� ���? ���-�� � �� �������� ��������� ������ ����� � ����� �� �����... ��� ���, ������: �� ��� �������� ����� ��������������, � � ��� ������� ��� ����������� ���������������. ���������! ����� ����� �������� ��� ������!";
			link.l1 = "��, ���� ���������!";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Sharlie_enterSoldiers");
		break;
		
		case "Sharlie_2":
			dialog.text = "� �� �� � ����� �� ��������� ���� ���� ����� ����. ���, �������� ��� �����, ���� �������� � ���� ����� ������ �� ���� � �������. �����, ��� ���� ��� ����������.";
			link.l1 = "���������, �����. � ������ ����, ��� ���� �������� �� �����, ��� ����� ������ ������.";
			link.l1.go = "Sharlie_3";			
		break;
		
		case "Sharlie_3":
			DialogExit();
			Log_Info("�� �������� ����������");
			PlaySound("interface\important_item.wav");
			TakeNItems(pchar, "newblade2", 1);
			TakeNItems(pchar, "pistol_01", 1);
			TakeNItems(pchar, "cirass5", 1);
			pchar.quest.Sharlie_PardonOver.over = "yes";
			DeleteAttribute(pchar, "questTemp.Sharlie.Pardon");
		break;
		//<-- ����� ��������
		
		//Jason --> ����������
		case "Portugal":
			dialog.text = "������, �������! ������ ������� � ��� � �����������.";
			link.l1 = "����� � ���� ��������.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "������� ������ ��� ����� ������� ������ ������ ������� �������� �����. �� �� ������, ��� ���� �� �������� �������, ��� ������ � ���������� �����. �� �����, ������, ��� ��� �����, �� ����� ���� ������ �������, �� � ��� ��� ��������!";
			link.l1 = "��, � ������ �����, ��� ��������, ������... �� � ��� ���� ����?";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "� ��� ��� �������� � ���, �������. ��� �������� ������� ������������ ����� ������� � ��� ��������, ��� ��� ������, ���� ��������� ������, � � �� � �� ����� ����� �������� �� ��������. ���� ����� ������ � ��, ��� � ������� ������ ��� ������� ��������, ������ ���� ������ ���������, �� ������ �����, ������ ���� ������ ���������������\n� � �� ���� �������� ��� ��� ��������... �� ������ ������, ������, ����� � ���������� ������� ������� ���������! ����� ���, �������������� �� ����� ������ � �������������� � � ���� ���, ��� ��������� ��������, �, ���� ���� ��� ������������� ��������� ������, ����� ���� ������ ������ �� �������� ������ � ������ �����!";
			link.l1 = "�����.. ����������, � ���� ���� ���� �����...";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			dialog.text = "����� ���, �������! ����� �� ���� ����, ���� �� �������� ��� ����������� �����! ��� ���� ����� �������, ����������! ����� � 10 000 ���� ��� �������?";
			link.l1 = "��-�, �� ���� ������������������, �...";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			dialog.text = "� �� ������ �, ���� ��� �������� �������� � ��� � ���� ������, � ������, ���� �� ��������� ��� �� ���! ��� �������?";
			link.l1 = "������, �, �� �����, ���������� ����������� ��� �� ��������� ����.";
			link.l1.go = "Portugal_5";
		break;
		
		case "Portugal_5":
			dialog.text = "���������, � � ��� �� ����������, ���� �������! ������� � ��� ��� � ����� �����, � ����������� ����� ����. � ������ ���� �� �������� � �������� � ����� �������������� ����������.";
			link.l1 = "� �����, ���� ������������������. ��� �������� ��������, � ����������� �� �������.";
			link.l1.go = "Portugal_6";
		break;
		
		case "Portugal_6":
			dialog.text = "��� ��� � �������� ���������, �������!";
			link.l1 = "��������� �����������.";
			link.l1.go = "Portugal_7";
		break;
		
		case "Portugal_7":
			DialogExit();
			AddQuestRecord("Portugal", "10");
			NextDiag.CurrentNode = "Portugal_8";
			LocatorReloadEnterDisable("Fortfrance_town", "reload1_back", false);
			LocatorReloadEnterDisable("Fortfrance_town", "reload2_back", false);
			LocatorReloadEnterDisable("Fortfrance_town", "gate_back", false);//������� ������ �� ������
			bDisableFastReload = true;//������� ������� �������
			pchar.GenQuest.CannotWait = true;//������ ��������
			pchar.quest.Portugal_Seapatrol.win_condition.l1 = "location";
			pchar.quest.Portugal_Seapatrol.win_condition.l1.location = "Martinique";
			pchar.quest.Portugal_Seapatrol.function = "PortugalSeapatrolGo";
			pchar.quest.Portugal_SeapatrolAvendel.win_condition.l1 = "location";
			pchar.quest.Portugal_SeapatrolAvendel.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Portugal_SeapatrolAvendel.function = "AvendelSpeach";
		break;
		
		case "Portugal_8":
			dialog.text = "�������, �� ��, �������, ������������ � ���� � ���� ���� �������������� ����� ���������� ���!";
			link.l1 = "��, �������. � �� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Portugal_8";
		break;
		
		case "Portugal_9":
			dialog.text = "�� ��� ��, �� ��������� ������� ���������. ��� ���� 10 000 ����.";
			link.l1 = "���������! ��� ������, ���� �������� �� �������������. ����� �������!";
			link.l1.go = "Portugal_10";
		break;
		
		case "Portugal_10":
			DialogExit();
			AddMoneyToCharacter(pchar, 10000);
			NextDiag.CurrentNode = "First time";
			pchar.quest.MartiniqueGovernorOver.over = "yes"; //����� ������
		break;
		//<-- ����������
		
		// Warship, 16.05.11. ����� "���������� �� �������".
		case "JusticeOnSale_1":
			dialog.text = "� " + GetAddress_Form(NPChar) + ", �� ���� �������! ������� ��� ������� ��������� ���������? ���� ���������� ��������� ������ � ��������� ���� ��������� �������!";
			link.l1 = GetSexPhrase("��� ��� ������", "���� ���� ������") + ", ��������� �����������?";
			link.l1.go = "JusticeOnSale_2";
			
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale.MayorWait");
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale.PrisonWait");
			
			DeleteQuestCondition("JusticeOnSale_MapEnter");
		break;
		
		case "JusticeOnSale_2":
			dialog.text = "�������, �������. ���, ������� �� �������� �������� ������������� �� ���� �����.";
			link.l1 = "���������.";
			link.l1.go = "JusticeOnSale_3";
		break;
		
		case "JusticeOnSale_3":
			AddQuestRecord("JusticeOnSale", "5");
			AddQuestUserData("JusticeOnSale", "sSex", GetSexPhrase("","�"));
			CloseQuestHeader("JusticeOnSale");
			
			AddMoneyToCharacter(PChar, 1000 + sti(PChar.rank) * 30 * dRand(10));
			
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale");
			
			DialogExit();
		break;
		
		case "JusticeOnSale_4":
			dialog.text = "�� �����, �������! �� �� ����� ��� ��� ��������! � ����� ��� ����������� " + XI_ConvertString(PChar.GenQuest.JusticeOnSale.ShoreId + "Acc") + ", ����� �� �������, � ����� ��� �� �����! ���� ����� �������������� � ���������� ����, �� ����������!";
			link.l1 = "��������� �����������.";
			link.l1.go = "JusticeOnSale_5";
		break;
		
		case "JusticeOnSale_5":
			dialog.text = "��������. ��������� ����, � ����������, ����� ����� �� ���� �� ����������! �����, ��� ������� ���� ����� ���������� �� �����, � ����� ��� �������� ��������.";
			link.l1 = "...";
			link.l1.go = "JusticeOnSale_6";
		break;
		
		case "JusticeOnSale_6":
			sld = GetCharacter(NPC_GenerateCharacter("JusticeOnSale_ShipPirate", "", "man", "man", sti(PChar.rank) + 5, PIRATE, -1, true, "quest"));
			sld.Ship.Type = GenerateShipExt(sti(PChar.GenQuest.JusticeOnSale.ShipType), true, sld);
			sld.Ship.Name = PChar.GenQuest.JusticeOnSale.ShipName;
			SetBaseShipData(sld);
			SetCrewQuantityFull(sld);
			Fantom_SetCannons(sld, "pirate");
			Fantom_SetBalls(sld, "pirate");
			Fantom_SetUpgrade(sld, "pirate");
			SetCaptanModelByEncType(sld, "pirate");
			SetRandGeraldSail(sld, PIRATE);
			
			Character_SetAbordageEnable(sld, false);
			
			Group_FindOrCreateGroup("JusticeOnSaleGroup");
			Group_AddCharacter("JusticeOnSaleGroup", "JusticeOnSale_ShipPirate");
			Group_SetGroupCommander("JusticeOnSaleGroup", "JusticeOnSale_ShipPirate");
			Group_SetAddress("JusticeOnSaleGroup", PChar.curislandid, "reload", Island_GetLocationReloadLocator(PChar.curislandid, PChar.GenQuest.JusticeOnSale.ShoreId));
			Group_SetTaskNone("JusticeOnSaleGroup");
			Group_LockTask("JusticeOnSaleGroup");
			
			sld.AlwaysFriend = true;
			SetCharacterRelationBoth(sti(sld.index), GetMainCharacterIndex(), RELATION_FRIEND);
			
			SetCharacterShipLocation(sld, PChar.GenQuest.JusticeOnSale.ShoreId);

			DeleteAttribute(sld, "SinkTenPercent");
			DeleteAttribute(sld, "SaveItemsForDead");
			DeleteAttribute(sld, "DontClearDead");
			DeleteAttribute(sld, "AboardToFinalDeck");
			
			sld.AlwaysSandbankManeuver = true;
			sld.AnalizeShips = true;
			sld.DontRansackCaptain = true;
			
			sld = &Locations[FindLocation(PChar.GenQuest.JusticeOnSale.ShoreId)];
			sld.DisableEncounters = true;
			
			PChar.Quest.JusticeOnSale_ShoreEnterFromMayor.win_condition.l1  = "location";
			PChar.Quest.JusticeOnSale_ShoreEnterFromMayor.win_condition.l1.location = PChar.GenQuest.JusticeOnSale.ShoreId;
			PChar.Quest.JusticeOnSale_ShoreEnterFromMayor.function = "JusticeOnSale_ShoreEnterFromMayor";
			
			PChar.Quest.JusticeOnSale_PirateShip_Sink.win_condition.l1 = "Character_sink";
			PChar.Quest.JusticeOnSale_PirateShip_Sink.win_condition.l1.character = "JusticeOnSale_ShipPirate";
			PChar.Quest.JusticeOnSale_PirateShip_Sink.function = "JusticeOnSale_PirateShip_Sink";
			
			DialogExit();
		break;
		
		case "JusticeOnSale_7":
			dialog.text = "��������� ��� �� ������. ��� �������� �������� ��, ��� �� �����������. ��������� ������� ��� �������� ������ �� ���� �����. � ������ ���� ����� �� ��������� ��� ������.";
			link.l1 = "...";
			link.l1.go = "JusticeOnSale_8";
		break;
		
		case "JusticeOnSale_8":
			AddMoneyToCharacter(PChar, sti(PChar.rank) * 300 + dRand(1000));
			DeleteAttribute(PChar, "GenQuest.JusticeOnSale");
			DialogExit();
		break;
		//<-- ���������� �� �������
		
			//--> Jason ������
		case "Regata":
			dialog.text = "�-�, ������������, ��� ��� ������, �������! �� ������ �������, ������ �������� ����� ��������� ����. �� ������ � �������� ������ � ������, ���������� ��� ��������?";
			link.l1 = "��, ���, ������.";
			link.l1.go = "Regata_1";
			RemoveItems(PChar, "letter_open", 1);//������ ������
			TakeNationLicence(HOLLAND);//������ ��������
			DeleteAttribute(pchar, "questTemp.Regata.ToPortRoyal"); // patch-5
		break;
		
		case "Regata_1":
			dialog.text = "����, �� ����������� 50 000 ���� - ����� � �������� ����?";
			if (makeint(Pchar.money) >= 50000)
			{
				link.l1 = "��, �������. ���, ������� ��� �����.";
				link.l1.go = "Regata_2";
			}
			link.l2 = "� ���� ������ ������������ �����. �� � ����������� ������� ��.";
			link.l2.go = "Regata_nomoney";
		break;
		
		case "Regata_2":
			dialog.text = "����� ������. ���� �� �������� - ���� ������ �������� � ���, ������ � ����������� �������. ������ ��� ����� ������� ������������ � ��������� ������\n��� ����������� ������� � ���� ����� ����������, �� ������ ���������� � ������� ����������. �������� � ���� - �� ��� �� ��������.";
			link.l1 = "������. � ��� � ������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -50000);
			pchar.quest.Regata_Guber.win_condition.l1 = "location";
			pchar.quest.Regata_Guber.win_condition.l1.location = "Portroyal_Roomtownhall";
			pchar.quest.Regata_Guber.function = "PrepareToRegataInPortroyal";
			pchar.questTemp.Regata.Begin = "true";
			NextDiag.TempNode = "First time";
		break;
		
		case "Regata_nomoney":
			dialog.text = "������. �� ������ �� ����������� � ����, �������. ������ ����� ����� ��� �����.";
			link.l1 = "� �������. ���� � ��� �� �����, � ��������, ��� ����� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Regata_1";
			pchar.questTemp.Regata.nomoney = "true";
		break;
		
		//������-�����
		case "Regata_Final":
			dialog.text = "�, ��� � ���������� ������! ������ ����, ������� " + GetFullName(pchar) + "! ���������� ��� � ���� ������������ ������� - ���������� ����� ������ ������ ���������� ����������� ������������� � ���������� ��������. ";
			link.l1 = "������� �� ������������, ���!";
			link.l1.go = "Regata_complete";
		break;
		
		case "Regata_complete":
			dialog.text = "������ ������� � ����� �������� ��� ��� ����� - ��������� �������. ����, �������� �������������� �� ������ ���������� 250 000 ����. �������� ��������!";
			link.l1 = "���������!";
			link.l1.go = "Regata_complete_1";
		break;
		
		case "Regata_complete_1":
			AddMoneyToCharacter(pchar, 250000);
			int iGift;
			string sItem1, sItem2, sItem3, sAdd;
			if (sti(pchar.rank) < 11) iGift = 0;
			if (sti(pchar.rank) >= 11 && sti(pchar.rank) < 25) iGift = 1;
			if (sti(pchar.rank) >= 25) iGift = 2;
			switch (iGift)
			{
				case 0:
					sItem1 = "blade_27"; //�����������
					sItem2 = "cirass7"; //�������
					sItem3 = "bussol";
					sAdd = "�����������, ������� � �������";
				break;
				
				case 1:
					sItem1 = "blade_20"; //�������
					sItem2 = "grape_mushket"; //���������
					sItem3 = "bussol";
					sAdd = "'�������', ��������� � �������";
				break;
				
				case 2:
					sItem1 = "blade_26"; //�������
					sItem2 = "cirass4"; //��������� �������
					sItem3 = "bussol";
					sAdd = "�������, ��������� ������� � �������";
				break;
			}
			GiveItem2Character(pchar, sItem1);
			GiveItem2Character(pchar, sItem2);
			GiveItem2Character(pchar, sItem3);
			dialog.text = "����� ��� ������� �������� ������ ������: "+sAdd+". ������ �� ��� - ����.";
			link.l1 = "����� ���, ���. �����, ���� �� ������.";
			link.l1.go = "Regata_complete_2";
		break;
		
		case "Regata_complete_2":
			dialog.text = "�� ���� ���� ������� ���������� ������� ��������� ��� �� ������� � ������, � ��� ��� ���������� � �������! ���� �� ������� ������ - ����� ����� ����� � ���� ����� ���������� � �������� ���� �������. ����� ��� �����, �������!";
			link.l1 = "������� �� ����� �����, ���! � ���� ������� ��������� ��� �� ��, ��� ���� ��� ����������� ����������� � ���� ������������ �����������. � ������ ��������� �����������.";
			link.l1.go = "Regata_complete_3";
		break;
		
		case "Regata_complete_3":
			DialogExit();
			NextDiag.CurrentNode = "First time";
		break;
		//<-- ������

		//*************************** ����� "������������� ������ "�����"" **********************        
        case "Andre_Abel_Quest_Hol_Gov_Node_1":
			//if (GetCityNameByIsland(Pchar.curIslandId) == "Villemstad")
			if (pchar.location == "Villemstad_townhall")
			{
			dialog.text = "� ��� ������, �������.";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" �� ����� ������� � ���������� �������� ��� ��� ��� ������...";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_2";
			TakeItemFromCharacter(PChar, "letter_1");
			Log_TestInfo("������ ������ ����������� �������.");
			PChar.Quest.Andre_Abel_Quest_Curasao_10Days_Left.over = "yes";
			}
			else
			{
			dialog.text = "��������� ���� �� ������ ��������������� ���? ��� ��� ������, " +GetAddress_Form(NPChar)+"?";
			link.l1 = "��� ������ ����� ���������� � ������ �����, "+GetAddress_FormToNPC(NPChar)".";
			link.l1.go = "exit";
			NextDiag.TempNode = "Andre_Abel_Quest_Hol_Gov_Node_1";
			}
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_2":
			dialog.text = "��... �� �������? ������... ��� �, ������� ���� ������ �� ����� �������.";
			link.l1 = "����� ���...";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_3";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_3":
			dialog.text = "���?! �������� ����������?! ��, ���������� ������! ���� �� ��� ����������, ��� �� ��� ��������� ������� ��� ��������! �������� "+ GetSexPhrase("����� ����������","��� ��������") +"!";
			link.l1 = "������! � ����� ���� "+ GetSexPhrase("���������","���������") +", � �� ���� �������� �� ���������� ������!..";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_4";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_4":
			dialog.text = "�� ������� �������, � ������ �� "+ GetSexPhrase("�����","�������") +". ����� ����������!.. � ������� "+ GetSexPhrase("���","��") +"!";
			link.l1 = "�� ��� ����� ������ �����!";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_5";
			link.l2 = "��� �, � �������� ����������� �������! �� ��������, - ��� ������� �����, � � �� ��������"+ GetSexPhrase("","�") +" � �� ��������"+ GetSexPhrase("","�") +" ������ ��������� ������, �� ��� ���� ����� ���� �� ������������!";
			link.l2.go = "Andre_Abel_Quest_Hol_Gov_Node_7";
			link.l3 = "�������� �������-����������, ����� �� ����� � ������?! � ������"+ GetSexPhrase("","�") +", ��� �� ����� �� ������� ������������...";
			link.l3.go = "Andre_Abel_Quest_Hol_Gov_Node_9";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_5":
			dialog.text = "��� �� ������, "+ GetSexPhrase("��������","��������") +"! ������ "+ GetSexPhrase("���","��") +" ����������!!!";
			link.l1 = "��, ���������, ���������!..";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_6";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_6":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_SetFightMode(PChar, true);
			Flag_PIRATE();
			LAi_SetImmortal(CharacterFromID("Andre_Abel_Quest_Officer_1"), false);
			LAi_SetActorType(CharacterFromID("Andre_Abel_Quest_Officer_1"));
			LAi_ActorAttack(CharacterFromID("Andre_Abel_Quest_Officer_1"), PChar, "");
			QuestSetCurrentNode("Henry Morgan", "Andre_Abel_Quest_Morgan_Dialog_16");
			LAi_Group_Attack(PChar, CharacterFromID("Villemstad_Mayor"));
			AddQuestRecord("Andre_Abel_Quest", "16");
			AddQuestUserData("Andre_Abel_Quest", "sText", "� �������, ���� � ��������� ��� ������ ������ ������ ���������");
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_7":
			//pchar.questTemp.OrionCity = GetCityNameByIsland(Pchar.curIslandId);
			dialog.text = "����� ���� ������� ��� ��� - ��� �� ��� �������... ������ "+ GetSexPhrase("���","��") +"!";
			link.l1 = "���������, ������ �� ������. � ���� ���� �������...";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_8";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_8":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			DoFunctionReloadToLocation("Villemstad_prison", "goto", "goto9", "Andre_Abel_Quest_In_Prison");
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_9":
			iSumm = sti(PChar.rank)*20000;
			dialog.text = "������������? ��... ��, ���� ���� ��� � �����, ������ " + iSumm + " ����, �� � ����� ���������� ������.";
			if(sti(PChar.money) >= iSumm)
			{
				link.l1 = "�������! � �� �������"+ GetSexPhrase("","�") +", ��� ��� ����� ��������.";
				link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_10";
			}
			link.l2 = "���-�?! �� �� � ���� ���?! �� ����� ������ � �� ��, ��� ���� ������!.. � ���� ������� ������, ������ � ��������� �������� � ���������� � ��������!!!";
			link.l2.go = "Andre_Abel_Quest_Hol_Gov_Node_5";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_10":
			iSumm = sti(PChar.rank)*20000;
			AddMoneyToCharacter(PChar, -iSumm);
			dialog.text = "�� ��� � �����������. ������ ����... ������ �� ��������� ��� ������ � ��������� �����������! �� ����������� �� ����������.";
			link.l1 = "�� ����������! ��������� ����������...";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_11";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_11":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			QuestSetCurrentNode("Henry Morgan", "Andre_Abel_Quest_Morgan_Dialog_16");
			AddQuestRecord("Andre_Abel_Quest", "16");
			AddQuestUserData("Andre_Abel_Quest", "sText", "� �������, ���� � ��������� ��� �������� ������");
		break;

		//  boal �� ��� -->
		case "GhostShipDone":
            SaveCurrentNpcQuestDateParam(npchar, "GhostShipHelp");
            
	AddCharacterExpToSkill(pchar, "Leadership", 200);
	AddMoneyToCharacter(pchar, 5000 + rand(10) * 1000);
	ChangeCharacterComplexReputation(pchar, "nobility", 2);
	ChangeCharacterHunterScore(Pchar, NationShortName(sti(NPChar.nation)) + "hunter", -20);
	sTemp = npchar.City;
   	if (!CheckAttribute(pchar, "GenQuest.MayorQuestsList." + sTemp)) pchar.GenQuest.MayorQuestsList.(sTemp) = 0;
	pchar.GenQuest.MayorQuestsList.(sTemp) = sti(pchar.GenQuest.MayorQuestsList.(sTemp)) + 1;

            OfficersReaction("good");
	DeleteAttribute(pchar, "GenQuest.GhostShipWorkId");
	DeleteAttribute(pchar, "GenQuest.GhostShipDone_" + NPChar.id);
			
	NextDiag.CurrentNode = NextDiag.TempNode;
	DialogExit();

	break;

		case "GhostShipHelp_1":
            SaveCurrentNpcQuestDateParam(npchar, "GhostShipHelp");
		pchar.GenQuest.GhostShipWorkId = NPChar.id;

		bDisableFastReload              = true;

		SetLocationCapturedState(NPChar.Default, true);

		Pchar.quest.GhostShipHelp.win_condition.l1          = "location";
    	    Pchar.quest.GhostShipHelp.win_condition.l1.location = NPChar.from_sea;
    	    Pchar.quest.GhostShipHelp.win_condition             = "GhostShipHelp";

		Pchar.GenQuest.Hunter2Pause            = true;

		ReOpenQuestHeader("GhostShipQuest");
		AddQuestRecord("GhostShipQuest", "help_t1");
		AddQuestUserData("GhostShipQuest", "sCity", GetCityName(npchar.City));
		LAi_LocationFightDisable(&Locations[FindLocation("Santiago_town")], false); // ��������� ���� ����� � ��������
   		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

	}
}

string GetGangLocation(ref npchar)
{
    int n;
	string island = GetArealByCityName(npchar.city);
	string LocationId, sAreal;
	int storeArray[MAX_LOCATIONS];
    int howStore = 0;

	for(n=0; n<MAX_LOCATIONS; n++)
	{				
		if (GiveArealByLocation(&locations[n]) == island)
		{			
			//==> �� ������ ������
			if (CheckAttribute(&locations[n], "DisableEncounters") && locations[n].DisableEncounters == true) continue;
			LocationId = locations[n].id;
			if (findsubstr(LocationId, "jungle" , 0) != -1 || findsubstr(LocationId, "Shore" , 0) != -1 || findsubstr(LocationId, "CaveEntrance" , 0) != -1)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	n = storeArray[dRand(howStore-1)];
	return locations[n].id;
}

string GetSpyLocation(ref npchar)
{
    aref	arCommon, arRld, arRld2;
    int	i, n, Qty, Qty2;
	string LocId; 
	string	storeArray [50];
	int howStore = 0;
    makearef(arRld, Locations[FindLocation(npchar.city + "_town")].reload);
	Qty = GetAttributesNum(arRld);
    if (CheckAttribute(pchar, "questTemp.jailCanMove.Deliver.locationId")) //���� ���� ����� �� �������� ������
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	else
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	if (howStore == 0) return "none";
	LocId = storeArray[dRand(howStore-1)];
	SetOpenDoorCommonLoc(npchar.city, LocId); //��������� �����
	for(n=0; n<MAX_CHARACTERS; n++)
	{
		if (CheckAttribute(&characters[n], "locations") && characters[n].locations == LocId) 
		{			
			characters[n].lifeDay = 0;
		}
	}
	return LocId;
}

string GetSpyColony(ref NPChar)
{
    int storeArray[MAX_COLONIES];
    int howStore = 0;
	string sChrId;

	for(int n=0; n<MAX_COLONIES; n++)
	{
		if (colonies[n].nation != "none" && sti(colonies[n].nation) != PIRATE && GetRelation2BaseNation(sti(colonies[n].nation)) == RELATION_ENEMY && colonies[n].id != "Panama" && colonies[n].id != "Minentown" && colonies[n].id != "VillaAlegria" && colonies[n].id != "SanAndres" && colonies[n].id != npchar.City)
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return "none";
	return colonies[storeArray[Rand(howStore-1)]].id;
}

int SelectCureerShipType()
{
	int iShipType;
	if(sti(pchar.rank) >= 14)
	{
		iShipType = SHIP_CORVETTE + rand(makeint(SHIP_POLACRE - SHIP_CORVETTE));
	}
	if(sti(pchar.rank) >= 6 && sti(pchar.rank) < 14)
	{
		iShipType = SHIP_BRIGANTINE + rand(makeint(SHIP_SCHOONER_W - SHIP_BRIGANTINE));
	}
	if(sti(pchar.rank) < 6)
	{
		iShipType = SHIP_CAREERLUGGER + rand(makeint(SHIP_SLOOP - SHIP_CAREERLUGGER));
	}
	return iShipType;
}

int SelectArsenalShipType()
{
	int iShipType;
	if(sti(pchar.rank) >= 18)
	{
		iShipType = SHIP_HEAVYGALEON;
	}
	if(sti(pchar.rank) >= 14 && sti(pchar.rank) < 18)
	{
		iShipType = SHIP_GALEON_L;
	}
	if(sti(pchar.rank) >= 8 && sti(pchar.rank) < 14)
	{
		iShipType = SHIP_CARAVEL + rand(makeint(SHIP_CARACCA - SHIP_CARAVEL));
	}
	if(sti(pchar.rank) >= 4 && sti(pchar.rank) < 8)
	{
		iShipType = SHIP_SCHOONER + rand(makeint(SHIP_FLEUT - SHIP_SCHOONER));
	}
	if(sti(pchar.rank) < 4)
	{
		iShipType = SHIP_BARQUE;
	}
	return iShipType;
}

string SelectPassText()
{
	string sText;
	switch (drand(5))
	{
		case 0: sText = "���� ����, ���������������� ����� ����������, ����� �� ������ ������ ��������������� ����� ���������� �������."; break;
		case 1: sText = "���� ������� ����� ���� ������ ������������, ���������� � �������� ��������, ���� ����������."; break;
		case 2: sText = "���� ������� ������� ���� ������ ����������� ���� ����� � ��� �����."; break;
		case 3: sText = "���� ��������� �������� ������ �� ����� ������ ������ ��������� ����� �����."; break;
		case 4: sText = "���� ������� ������� � ������ ����� ������� ����� �������."; break;
		case 5: sText = "���� ��������, ��������� ���� �����, ������� �������� ����� ���������� ������, ����� ��� � ������ �� �������� �����."; break;
	}
	return sText;
}

string SelectFugitiveCity()
{
	string sCity;
	switch (rand(5))
	{
		case 0: sCity = "LaVega"; break;
		case 1: sCity = "PuertoPrincipe"; break;
		case 2: sCity = "LeFransua"; break;
		case 3: sCity = "FortOrange"; break;
		case 4: sCity = "Roseau"; break;
		case 5: sCity = "Vestpunt"; break;
	}
	return sCity;
}

string SelectFugitiveText()
{
	string sText;
	switch (drand(5))
	{
		case 0: sText = "���� �� ������� �������� ������ ��������� ������ ������ � ������� �� ���������� ������� �� ����� �������."; break;
		case 1: sText = "���� �� ����� ���������� ����� ������������, ����� �� ����� ������� ������, � ������ �� ������� ���������������."; break;
		case 2: sText = "���� �� ����� ������� ��������, ��������� �� ���������� �����, �� ���������� �������� ������������, ����� ������ � �������."; break;
		case 3: sText = "���� �������� �������� �� ������������ ������� ������ ������ � ������ �� ����� ������� �� ������� �����."; break;
		case 4: sText = "���� ������ ������ ��������� ������ ���� ����, ����� � �� �����, ����� �� ������, ���������� � ����� � ������� ���� ����� �� ������������ �������."; break;
		case 5: sText = "���� ��� ������� ������, ������� ����������� �������, ������ ��� ����� ����� � ���� � ������� � ����������� ����������� �� �������� �������."; break;
	}
	return sText;
}
