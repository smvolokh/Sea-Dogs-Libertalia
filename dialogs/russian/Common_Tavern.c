#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06
#include "interface\ship.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Tavern.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06
	
	int iTest, iTemp;
	string sTemp;
    iTest = FindColony(NPChar.City); // ����� 
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	bool ok;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_" + rand(23) + ".wav");
			NextDiag.TempNode = "First time";
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,
					LinkRandPhrase("� ������ ������� �������, ���� ����� ����! �� ����� ����� � �� �� ���� ����� �������������.", "��� ��������� ������ ����� �� ������ � ������� ����. � �� ����� � ������������� � ����� �� ����!", "����, "+ GetSexPhrase("��������","�������") +", ���� ������� �� ������� �� ���� ������..."),
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��������� ������ ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����!","") +"", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ����� ����! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."),
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "���, " + GetWorkTypeOfMan(npchar, "") + ", � ��� ���� �� - ������� ������! ��� ��� � ���� �����, ��������: ���� ���� � ������ ����..."));
				link.l1.go = "exit";
				break;
			}
			if (sti(pchar.GenQuest.Piratekill) > 20 && sti(npchar.nation) == PIRATE)
			{
				dialog.text = RandPhraseSimple("�, ��� ��, ��������! �������, ���� ����� ���� ������? ��� �� �� ���! ������! � ������! ���� �����!", "������ �������, �������? �� ���! ������ ���� �������, ��� ���� ������! ������, ����� ������� ���� � �������! �������!");
				link.l1 = RandPhraseSimple("�? ���?", "�, �� ���� ���?!");
				link.l1.go = "fight";
				bDisableFastReload = true;//������� �������
				pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
				pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
				pchar.quest.pirate_in_town.function = "TownPirate_battle";
				break;
			}
			//Jason, ����� ��������
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "crew" && npchar.city == "FortFrance")
			{
				dialog.text = "�� ���-�� ������, �����?";
				Link.l1 = "��������, � �� ����� ������ ������� �� ���� �������. �� �������� � ���� �������?";
				Link.l1.go = "Sharlie_crew";
				break;
			}
			
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "skiper" && npchar.city == "FortFrance")
			{
				dialog.text = "��� �� ���� ���, �����?";
				Link.l1 = ""+npchar.name+", � �������, ��� ������ ���� ������ �����������, �� ��� �� �������� ��� ���. ��� ����� �������. ��� � ����� ��� �����?";
				Link.l1.go = "Sharlie_skiper";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
    			dialog.text = "��� ��� ������, �����?";
				Link.l1 = "� �������, �� ������� �������� �� ���� ��������.";
				Link.l1.go = "quests";
				link.l2 = "� ����� �� ����� �������.";
                link.l2.go = "room";
				break;
			}			
			//����� ��������

			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "tavern" && npchar.city == "Tortuga")
			{
				dialog.text = "��� ������ �������� �����! ��� �������? ���, ������, ����������� �����?";
				Link.l1 = "������� ��������� ������������ ���� � ���� �� �������.";
				Link.l1.go = "mtraxx_tortuga";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "room" && npchar.city == "Tortuga")
			{
				dialog.text = "�� ��� ��� ��������, �����, ������������ � ���� �������.";
				Link.l1 = "...";
				Link.l1.go = "exit";
				break;
			}

			//������������ ����� -->
			if (pchar.questTemp.MC == "toCaracas" && npchar.city == "Caracas")
			{
				dialog.text = "���� ����, �������, �������! ��� ���, ��� �������! ��� �������!";
				link.l1 = "��� �� ���������, ��� ��?";
				link.l1.go = "MCTavern";
				break;
			}
			if (pchar.questTemp.MC == "toCaracasWervolf" && npchar.city == "Caracas")
			{
				dialog.text = "�������, �� ������� ����� � ��������...";
				link.l1 = "� �����.";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.MC == "toCaracasPadre" && npchar.city == "Caracas")
			{
				dialog.text = "��, ��� �������, �������? �� ����� ���?";
				link.l1 = "���"+ GetSexPhrase("��","��") +". �� ������ �� ����� �������������, ����� ��� ��������...";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.MC == "toCaracasTavern" && npchar.city == "Caracas")
			{
				dialog.text = "�������, ��� ��� ������!";
				link.l1 = "��� ��������� � ���� ����� �����������?";
				link.l1.go = "MCCaracasAfter";
				break;
			}
			//<-- ������������ ����� 


			if(NPChar.quest.meeting == "0")

			{
				if (npchar.city == "Pirates")
				{
					dialog.Text = "��, ��� � ��� "+ GetSexPhrase("���� ����� �������","���� �������� �������") +" �� ������ ���������"+ GetSexPhrase("","�") +"! ��������������, �����"+ GetSexPhrase("�","���") +". ���� ����� ���� �����, � � ������ � ����� �������. ������� ������� ������, �� ������ ��? ������� ����?";
					Link.l1 = "��� �� ������ ���� �����? �� �������? ��� �� �� �����"+ GetSexPhrase("","�") +", ��� ����� ������� ���� ���������!";
					Link.l1.go = "Pirates_1";
					NPChar.quest.meeting = "1";
					break;
				}
				if (npchar.city == "Charles")
				{
					dialog.Text = "����� ����������, " + GetAddress_Form(NPChar) + ". ���, ������� � ����������� - ��� �� ��������� �����! ���� ����� " + GetFullName(npchar) + ". � �������� ���� �������.";
					Link.l1 = "���������� ����? � ������"+ GetSexPhrase("","�") +" � ����. ���� ������������, ��� � �������� ������� �� ����������� ������ �� ���������� ���������. ���-�� � ������ �������...";
					Link.l1.go = "Charles_1";
					NPChar.quest.meeting = "1";
					break;
				}
				if (npchar.city == "Portobello")
				{
					dialog.Text = "����� ����������, " + GetAddress_Form(NPChar) + ". ���, ������� � ����������� - ��� �� ��������� �����! ���� ����� " + GetFullName(npchar) + ", �� ����� ��������, ��� ����������� ���. � �������� ���� �������.";
					Link.l1 = "����������� ���? ������"+ GetSexPhrase("","�") +" � � ����. ���� �������, ��� �� ������� ������� ��������� �������� �� ��������� - �� �����-�� ������� �������� � ������ ��������� ������� ���� � ����� ��� ��������� ��-��� ���� � �����.";
					Link.l1.go = "Portobello_1";
					NPChar.quest.meeting = "1";
					break;
				}

				dialog.Text = GetNatPhrase(npchar, LinkRandPhrase("� ��������� � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "', ���. � ��� ������ ���.","� ����� �������, ���! � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "' ���� ����� ������.","����, �� ������� � ����, ���? �� �����������, � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "' �� ������ ������������ ����, ��� ����!"), LinkRandPhrase("����� ���, ����� �������. �� ������� �������� ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'?","�� �������� ��� ������, �����. ����� �������: � "+GetFullName(npchar)+", ������ ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'.","� ��� ������ �����, ����� �������! � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "' ������ �������� ������ �� ��� ����! � - ������ ����� ���������, "+GetFullName(npchar)+", ����� �������."), LinkRandPhrase("������ �������! ����� ���������� � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'!","�, ����� ��������� ������� ������� ������� ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'! �� ������� � ���, ������?","������������, ���������! � "+GetFullName(npchar)+", ������ ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "', ��� �������������� ��� � ����!"),LinkRandPhrase("������������, ������ �������. � ������ ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'. ������� � ���?","������ ����, ������. ����� ���������� � ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "'.","����� �������, ������ �������! ������� '" + XI_ConvertString(NPChar.City + "TavernName") + "' ������������ ���! ����, ����, ���?"));
				Link.l1 = LinkRandPhrase("� � ��� ��� �����... ��������� ������������� - "+GetFullName(pchar)+", ��� ����������.",""+GetFullName(pchar)+", ��� ����������. ��� �� ��� ����������?","��� ��� "+GetFullName(pchar)+" � � ����� ������ �������. ��� �������� �����?");
				Link.l1.go = "meeting";
				NPChar.quest.meeting = "1";
			}
			else
			{
				// ��������� ��������� ����������. ����� �1. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_1.CurPortManColony + "_tavern")
		        {
		            if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NoMoneyToBarmen"))
		            {
		            	iTemp = sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen);
		            	dialog.Text = "�� ��� ���, �� �������� ��� " + FindRussianMoneyString(iTemp) + ".";
		            	if(sti(PChar.Money) >= iTemp)
		            	{
							link.l1 = "��, ������"+ GetSexPhrase("","��") +". ��� ���...";
							link.l1.go = "Tavern_ChurchGenQuest1_Node_4_1";
						}
						else
						{
							link.l1 = "���, ��� �� ������"+ GetSexPhrase("","��") +"...";
							link.l1.go = "exit";
						}
		            }
		            else
		            {
		            	dialog.Text = "���� ��������, ��������"+ GetSexPhrase("�� ��������","�� �������") +"?";
						link.l1 = "������� ���� ����� ��������, ��� �� ��� ��������.";
						link.l1.go = "Tavern_ChurchGenQuest1_Node_1";
					}
					break;
				}
				// <-- ��������� ��������� ����������. ����� �1.
				dialog.Text = pcharrepphrase(LinkRandPhrase(LinkRandPhrase("����� �����! ��, ���, ��-��, �������� ����� ������� ��������! �� ���������������, ���� �� ��� ��� �� ���������, ��-��!","�! ��� "+GetFullName(pchar)+"! ����� �� �� ����������, �� �� ���������, ���������...","�-�, "+GetAddress_Form(NPChar)+", ����, �� �� � ����? ��������� �������� ���? ��������, ������ ���� �������..."),LinkRandPhrase("��� ������� "+GetFullName(pchar)+"! ��-��, ���! ���� ��������, ����������?! ��������, ���, ������, ��� ��������� � �����-�� �����...","�, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! ������, ������� �� ��� �� ���������...","������ ����, "+GetFullName(pchar)+", � ��� ���... ������, �����, ������� ��� ���������, ����������."),LinkRandPhrase("������������, �������. ��������������, �� ������� � � ���� ��������� ���� ��� ������� ���� ������ �������� ��������.","�-��-��! ���� � ����? ��� �� ��� "+GetFullName(pchar)+"! � �� ��� ��� ��� ������ ���������...","��-��, �� ��� �� ��� "+GetFullName(pchar)+"! �������, �� ������ �� ������ ������ ���� ������������ ���������� � ����� �����������?")),LinkRandPhrase(LinkRandPhrase(""+GetFullName(pchar)+"! ������ ����� ������ ��� ������ ��� � ����� ���������!","����� ���, �������, �����! � ��� �������������� ������ ������� �����. ��� ��� ������?","��� ����� ������ ���, "+GetFullName(pchar)+"! ��� �������� �������� � � ����? ��� ������ ��� ������ ����� � ������?"),LinkRandPhrase("������ ����, �������. ��������� ���������� ��� ������������� ���������!","������������, ������� "+GetFullName(pchar)+"! � ���, ��� �� ����� ��������� �� ���. ��� ��� ��������?","����� ��� ���, "+GetAddress_Form(NPChar)+" "+GetFullName(pchar)+"! ����, ��� ������������ ��� ���������? � ����� ��������, ����� ��� �������."),LinkRandPhrase("�������� �������! ����� ����������! � ��� �������� ������������ ��������� � ����� ������ ������ � � ������ ��� ��� ���!",""+GetFullName(pchar)+"! ��� � ��� ������ ������! ��������� ���� �����������, �������, ��� �� ��������� �� ��������? ��������, � ����� ���� ��� ������� �������� ��� ������ ������� �����!","� ��� ����� � ������ ������� "+GetFullName(pchar)+"! ��, ������������, ���������� ������ �������� �� ���� ��������� ��������!")));
				Link.l1 = pcharrepphrase(RandPhraseSimple(RandPhraseSimple("����, ���� ��� �� ��������... �� ������� ����, ������, � � ��� ���������...","��������, ��������, � ������� �� �������� ����������. ������-�� ��� ��� ������ ����..."),RandPhraseSimple("��-��... ��� ��� ��, ��� ��� �� ����?! �������, � ���������?","��, ������, �������, ���� ���� ����� ����� �����������? � �� � ���� ���� � ������������...")),RandPhraseSimple(RandPhraseSimple("������ ��� ���� ��������, �������. ��� ��� ���� � ������� ���������� �� ����� �������� �����?","��, �������, ���� ��������� ��� ����� ���� ��� ���! ������ ������� � ���� �����..."),RandPhraseSimple("�� ��������� �������� ���������? �� ��� ��, � �������, ��������.","��� ������� ������� ������� ���������... ���-�� ��� �� ���� ������?")));
				Link.l1.go = "step_node";
			}
			break;
				
			case "step_node":
				dialog.Text = LinkRandPhrase("����������� ������ ���, �������.","������� '" + XI_ConvertString(NPChar.City + "TavernName") + "' � ����� �������, �������!","������, ���! ����� ����� ������� ��� �����?");
				Link.l1 = "���� �� ������� �����, ������� ���� � ��������?";
				Link.l1.go = "crew hire";
				Link.l2 = "� �������, �� ������� �������� �� ���� ��������.";
				Link.l2.go = "int_quests";
				if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
				{
					link.l21 = "������, ��� ����� ���������� � ���������� �����.";
					link.l21.go = "LoanForAll";//(���������� � ��������� ���������)
				}
			if (CheckAttribute(pchar, "otjig_v_taverne"))
				{	
					link.l22 = "� ���� �������� ��� ����� ����� �������� �������!";
					link.l22.go = "Otjig_v_taverne_stoimost";
				}
				
				// ��������� ��������� ����������. ����� �2. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
		            	{
					link.l10 = LinkRandPhrase("�� ���-������ ������ ������� �� �������� ���������� ������?", "��� �� ������ �� �������� ���������� ������� ������?", "�� ���-������ ������ �� �������� ���������� ������� ������?");
					link.l10.go = "Tavern_GenQuest_Church_2_1";
				}
				// <-- ��������� ��������� ����������. ����� �2.
				
				//Jason --> ��������� ����������� ���
				if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_tavern" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
				{
					link.l16 = "����������, �������, �� ��� ��� ��� ������ � ���� �������. � ���� ������ "+pchar.GenQuest.Device.Shipyarder.Type+", � ��� �������, ��� � ��� � ������ ��� �����������. ��, ���-�� �������� �� ������. ������ �� ���� ������� �� ������?";
					link.l16.go = "Device_Tavern";
				}
				// <-- ��������� ����������� ���
			
				//Jason --> ��������� ����� ��� �������
				if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "continue" && NPChar.location == pchar.GenQuest.Sunplace.Trader.CityT + "_tavern")
				{
					link.l17 = "�����, � ��� � ������ ��������� �������� �� ����� "+pchar.GenQuest.Sunplace.Trader.Enemyname+". ��� ��� ��� �����?";
					link.l17.go = "Sunplace_Tavern";
				}
				// <-- ��������� ����� ��� �������
			
				// --> ����������� ������
				if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobOnMain" && NPChar.location == pchar.questTemp.HWIC.Holl.JacobCity + "_tavern")
				{
					link.l18 = "�����������, " + npchar.name + ". ��� ����� ����� ����� ��� �����, ��� ��? ���-�� � ��� � ���� � ���� �� ����...";
					link.l18.go = "HWICHollJacob_Tavern";
				}
				if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "start" && NPChar.nation == SPAIN && !CheckAttribute(npchar, "quest.HWICTalked"))
				{
					link.l18 = "�����������, " + npchar.name + ". � ��� ������ ���������, �������� �������� ��� �����. �� � ��� � ������ �� ���������?";
					link.l18.go = "HWICSelfFernando_Tavern";
				}
				// <-- ����������� ������
			
				//Jason --> ����� �� �����������
				if (CheckAttribute(pchar, "GenQuest.Racing.Go.Advantage") && NPChar.location == pchar.GenQuest.Racing.Go.StartCity + "_tavern")
				{
					link.l19 = "� ������ �� ����� ���������, ������� �������� � ����, " + npchar.name + ".";
					link.l19.go = "Race_Advantage";
				}
				// <-- ����� �� �����������
			
				//Jason --> ������ ����������
				if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "take" && NPChar.location == pchar.GenQuest.Marginpassenger.Targetcity+"_tavern")
				{
					link.l20 = "� �� ����� ��������, ��� � ���� ����� �������� �� ����� "+pchar.GenQuest.Marginpassenger.q2Name+"? �� � ��� � ������ ���������.";
					link.l20.go = "Marginpassenger";
				}
				// <-- ������ ����������
			
				link.l3 = pcharrepphrase("���� �� � ����� ���������� ��������� ������?", "��� �� � ���� ��������� �������, � �����"+ GetSexPhrase("","�") +" �� ������������ ����� �� ��������� �����.");
				link.l3.go = "room";
				link.l4 = pcharrepphrase("���� �� � ���� ���-������, ����� ��������� �����?", "� ����� �� ������. ��� � ���� ����?", "������ ����?", "������-��, ��������, ����-������ ������!");
				link.l4.go = "vipivka_bulbul";				
				Link.l78 = "���, � ��� �����, " + NPChar.name + ". �� �������.";
				Link.l78.go = "exit";
		break;
		
		case "vipivka_bulbul": // ��� ���������� �������� �������, ����������� ��������, ��� ����� ������ � ������ ����� � �������! Rigel
			dialog.text = "� ���� ���� ��� �� 2 ���� �� ������, ��� �� 4 ����, ���� �� 5 ����. ���� ��� ����� ������� ���� �� 6 ���� �� �����. ��� �������� �����, ���?";			
			if(makeint(PChar.money)>=2)
			{
				link.l1 = "����� ��� �� 2 ����.";
				link.l1.go = "vipivka_el";
			}
			if(makeint(PChar.money)>=4)
			{
				link.l2 = "����� ��� �� 4 ����.";
				link.l2.go = "vipivka_rom";	
			}
			if(makeint(PChar.money)>=5)
			{
				link.l3 = "����� ���� �� 5 ����.";
				link.l3.go = "vipivka_vino";
			}
			if(makeint(PChar.money)>=6)
			{
				link.l4 = "����� ������� ���� �� 6 ����.";
				link.l4.go = "vipivka_goodvino";
			}
			link.l5 = "� ���� ���-������ ��������������?";
			link.l5.go = "vipivka_bulbul2";
			link.l6 = "� ����� ������� �� ��� �� ��� �������?";
			link.l6.go = "vipivka_butilka";	
		break;		
		
		case "vipivka_bulbul2": // ����������� �� �������������� �������
			dialog.text = "��� ��! ���� ������������ ��������� ��� �� 1 ���� �� �����. � ����. �� ���� ��������� ������.";			
			if(makeint(PChar.money)>=1)
			{
				link.l1 = "��, ��� ��� �� ��� ����.";
				link.l1.go = "vipivka_sok";
			}
			link.l2 = "������ ��� ����.";
			link.l2.go = "vipivka_voda";
			link.l3 = "� ���������. ���� ���� ��������.";
			link.l3.go = "step_node";
		break;				
		
		case "vipivka_el": // ���
			dialog.text = "���, ����������!";			
			link.l1 = "����... ������� �����!";
			AddMoneyToCharacter(pchar, -2);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 2;
				}
				else pchar.questTemp.Rum = 2;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
			link.l1.go = "step_node";
		break;		
		
		case "vipivka_rom": // ���
			dialog.text = "���, ����������!";			
			link.l1 = "���! ��� �� ��� �����!";
			AddMoneyToCharacter(pchar, -4);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 2;
				}
				else pchar.questTemp.Rum = 2;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
			link.l1.go = "step_node";
		break;			
		
		case "vipivka_vino": // ����
			dialog.text = "���, ����������!";			
			link.l1 = "���������, �� ������.";
			AddMoneyToCharacter(pchar, -5);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
				}
				else pchar.questTemp.Rum = 1;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
			link.l1.go = "step_node";
		break;			
		
		case "vipivka_goodvino": // ������� ����
			dialog.text = "���, ����������!";			
			link.l1 = "����� ������� �������! � ����������� ��������.";
			AddMoneyToCharacter(pchar, -6);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
				}
				else pchar.questTemp.Rum = 1;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
			link.l1.go = "step_node";
		break;			
		
		case "vipivka_sok": // ���
			dialog.text = "���, ����������!";			
			link.l1 = "���. ����� �������!";
			AddMoneyToCharacter(pchar, -1);
			link.l1.go = "step_node";
		break;			
		
		case "vipivka_voda": // ����
			dialog.text = "���, ����������!";			
			link.l1 = "�������. � �� ����� ������.");
			link.l1.go = "step_node";
		break;
		
		case "vipivka_butilka": // �������???
			dialog.text = "�������, � ���� ��� ����� ��� ��������. �� � �� ������ � ���. ��� ���� � ����� ����.";			
			link.l1 = "������.";
			link.l1.go = "step_node";
		break;

		case "Otjig_v_taverne_stoimost":
			dialog.text = LinkRandPhrase("���������! ����� ��� ��������� �� ������, ��� ������� ����.",
			"���� �������� ������! ��� ������ ����������?",
			"�������! ��� ��������� ��������� �����?");
			link.l2 = "������ �� ������ ����� ��� �����.";
			link.l2.go = "exit";
			if (sti(Pchar.money) >= GetCrewQuantity(pchar)*150 && GetCrewQuantity(pchar)>0)
			{
				link.l2 = "����� ������� �������� ����. ������� �������� ����, �� �� ������� ��������.";
				link.l2.go = "go_otjig_1";
			}
			if (sti(Pchar.money) >= GetCrewQuantity(pchar)*200 && GetCrewQuantity(pchar)>0)
			{
				link.l3 = "�������� ���� � �������� ���� �� ���������! � ������� ������!";
				link.l3.go = "go_otjig_2";
			}
			if (sti(Pchar.money) >= GetCrewQuantity(pchar)*250 && GetCrewQuantity(pchar)>0)
			{
				link.l4 = "���� � ���� �� �����! � ������ �������. � ���� ������� �� ����� �������� ������!";
				link.l4.go = "go_otjig_3";
			}
	if (sti(Pchar.money) >= GetCrewQuantity(pchar)*300 && GetCrewQuantity(pchar)>0)
			{
				link.l5 = "����� ���� ������ �������! ����� ����� ������� �� ������ ��������!";
				link.l5.go = "go_otjig_4";
			}
	if (sti(Pchar.money) >= GetCrewQuantity(pchar)*350 && GetCrewQuantity(pchar)>0)
			{
				link.l6 = "������ ������ ������� � ����� �������� ���! � ����, ����� ����� ������ ������������ � ������ ��������� ������!";
				link.l6.go = "go_otjig_5";
			}

			{
				link.l7 = "�������, � ���������.";
				link.l7.go = "step_node";
			}
		break;

		case "go_otjig_1": // ��� ���������� �������� �������, ����������� ��������, ��� ����� ������ � ������ ����� � �������! Rigel
			dialog.text = LinkRandPhrase("����������, �������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 150 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*150) + ".",
			"������! � ���� ��� ��� �������� ������ ������. ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 150 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*150) + ".",
			"�������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 150 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*150) + ".");
			link.l1 = "������, �� �����!";
			link.l1.go = "PirPirPir1";
			link.l2 = "�������, � ���������.";
			link.l2.go = "step_node";
		break;
		
		case "go_otjig_2":
			dialog.text = LinkRandPhrase("��� ����� �������� ����, ���! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 200 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*200) + ".",
			"��� ���������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 200 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*200) + ".",
			"��� ��� ��� �������� ������� ����! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 200 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*200) + ".");
			link.l1 = "������, �� �����!";
			link.l1.go = "PirPirPir2";
			link.l2 = "�������, � ���������.";
			link.l2.go = "step_node";
		break;
		
		case "go_otjig_3":
			dialog.text = LinkRandPhrase("����� ����� ��� ����, �������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 250 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*250) + ".",
			"�������! ��� ���������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 250 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*250) + ".",
			"��� ������� ����� ������� � ������� ��������! ������ ���� ��� ��� �� ������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 250 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*250) + ".");
			link.l1 = "������, �� �����!";
			link.l1.go = "PirPirPir3";
			link.l2 = "�������, � ���������.";
			link.l2.go = "step_node";
		break;
		
		case "go_otjig_4":
			dialog.text = LinkRandPhrase("��� ��� ��������! � �������� �� ����� ��� ����� ������ �� ����� �������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 300 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*300) + ".",
			"��� ��� ����� ���! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 300 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*300) + ".",
			"������ ������ ��������! ��� � ���� ����� ���� �����! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 300 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*300) + ".");
			link.l1 = "������, �� �����!";
			link.l1.go = "PirPirPir4";
			link.l2 = "�������, � ���������.";
			link.l2.go = "step_node";
		break;
		
		case "go_otjig_5":
			dialog.text = LinkRandPhrase("��� ��� ��������! � �������� �� ����� ��� ����� ������ �� ����� �������! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 350 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*350) + ".",
			"��, ������������! ���������� �� ���� ��� ����� ������! ��� ����� �������� ���! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 350 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*350) + ".",
			"��� ��� ��! �� ����� ������ � ������ ��� ������������ ������� ���! ������ �� ����, ��� �� ������������ ������� ������ ������� ������� � ������� ��������� ����� 350 ����, � ��� " + FindRussianMoneyString(GetCrewQuantity(pchar)*350) + ".");
		link.l1 = "������, �� �����!";
		link.l1.go = "PirPirPir5";
		link.l2 = "�������, � ���������.";
		link.l2.go = "step_node";
		break;
		
		case "PirPirPir1":
			DialogExit();
			AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*150));
			DeleteAttribute(pchar, "otjig_v_taverne");
			DoQuestCheckDelay("QPirPirPir1", 1.0);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 30;
				}
				else pchar.questTemp.Rum = 30;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;
		
		case "PirPirPir2":
			DialogExit();
			AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*200));
			DeleteAttribute(pchar, "otjig_v_taverne");
			DoQuestCheckDelay("QPirPirPir2", 1.0);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 30;
				}
				else pchar.questTemp.Rum = 30;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;	
		
		case "PirPirPir3":
			DialogExit();
			AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*250));
			DeleteAttribute(pchar, "otjig_v_taverne");
			DoQuestCheckDelay("QPirPirPir3", 1.0);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 30;
				}
				else pchar.questTemp.Rum = 30;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;
		
		case "PirPirPir4":
			DialogExit();
			AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*300));
			DeleteAttribute(pchar, "otjig_v_taverne");
			DoQuestCheckDelay("QPirPirPir4", 1.0);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 30;
				}
				else pchar.questTemp.Rum = 30;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}			
		break;	
		
		case "PirPirPir5":
			DialogExit();
			AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*350));
			DeleteAttribute(pchar, "otjig_v_taverne");
			DoQuestCheckDelay("QPirPirPir5", 1.0);
			if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
			{
				if (CheckAttribute(pchar, "questTemp.Rum"))
				{
					pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 30;
				}
				else pchar.questTemp.Rum = 30;
			}
			else 
			{
				if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
			}				
			//<-- navy
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;	
		
		case "Meeting":
			// ��������� ��������� ����������. ����� �1. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_1.CurPortManColony + "_tavern")
	        {
	            dialog.Text = "���� ��������, ��������"+ GetSexPhrase("�� ��������","�� �������") +"?";
				link.l1 = "������� ���� ����� �������� ��� �� ��� ��������.";
				link.l1.go = "Tavern_ChurchGenQuest1_Node_1";
				break;
			}
			// <-- ��������� ��������� ����������. ����� �1.
			dialog.Text = LinkRandPhrase("����������� ������ ���, �������.","��� ��� ����������, �������?","������, ���! ����� ����� ��� �����?");
			Link.l1 = "��� ����� �������, " + NPChar.name + ".";
			Link.l1.go = "crew hire";
			Link.l2 = NPChar.name + ", ����� ���������...";
			Link.l2.go = "int_quests";
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l21 = "������, ��� ����� ���������� � ���������� �����.";
				link.l21.go = "LoanForAll";//(���������� � ��������� ���������)
			}
			// ��������� ��������� ����������. ����� �2. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	        {
				link.l10 = LinkRandPhrase("�� ���-������ ������ ������� �� �������� ���������� ������?", "��� �� ������ �� �������� ���������� ������� ������?", "�� ���-������ ������ �� �������� ���������� ������� ������?");
				link.l10.go = "Tavern_GenQuest_Church_2_1";
			}
			// <-- ��������� ��������� ����������. ����� �2.
			
			//Jason --> ��������� ����������� ���
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_tavern" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l16 = "����������, �������, �� ��� ��� ��� ������ � ���� �������. � ���� ������ "+pchar.GenQuest.Device.Shipyarder.Type+", � ��� �������, ��� � ��� � ������ ��� �����������. ��, ���-�� �������� �� ������. ������ �� ���� ������� �� ������?";
				link.l16.go = "Device_Tavern";
			}
			// <-- ��������� ����������� ���
			
			//Jason --> ��������� ����� ��� �������
			if (CheckAttribute(pchar, "GenQuest.Sunplace.Trader") && pchar.GenQuest.Sunplace.Trader == "continue" && NPChar.location == pchar.GenQuest.Sunplace.Trader.CityT + "_tavern")
			{
   				link.l17 = "�����, � ��� � ������ ��������� �������� �� ����� "+pchar.GenQuest.Sunplace.Trader.Enemyname+". ��� ��� ��� �����?";
				link.l17.go = "Sunplace_Tavern";
			}
			// <-- ��������� ����� ��� �������
			
			//--> ����������� ������
			if (CheckAttribute(pchar, "questTemp.HWIC.Holl") && pchar.questTemp.HWIC.Holl == "JacobOnMain" && NPChar.location == pchar.questTemp.HWIC.Holl.JacobCity + "_tavern")
				{
					link.l18 = "�����������, " + npchar.name + ". ��� ����� ����� ����� ��� �����, ��� ��? ���-�� � ��� � ���� � ���� �� ����...";
					link.l18.go = "HWICHollJacob_Tavern";
				}
				if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "start" && NPChar.nation == SPAIN && !CheckAttribute(npchar, "quest.HWICTalked"))
				{
					link.l18 = "�����������, " + npchar.name + ". � ��� ������ ���������, �������� �������� ��� �����. �� � ��� � ������ �� ���������?";
					link.l18.go = "HWICSelfFernando_Tavern";
				}
				//<-- ����������� ������
				
				//Jason --> ����� �� �����������
				if (CheckAttribute(pchar, "GenQuest.Racing.Go.Advantage") && NPChar.location == pchar.GenQuest.Racing.Go.StartCity + "_tavern")
				{
					link.l19 = "� ������ �� ����� ���������, ������� �������� � ����, " + npchar.name + ".";
					link.l19.go = "Race_Advantage";
				}
				// <-- ����� �� �����������
				//Jason --> ������ ����������
				if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "take" && NPChar.location == pchar.GenQuest.Marginpassenger.Targetcity+"_tavern")
				{
					link.l20 = "� �� ����� ��������, ��� � ���� ����� �������� �� ����� "+pchar.GenQuest.Marginpassenger.q2Name+"? �� � ��� � ������ ���������.";
					link.l20.go = "Marginpassenger";
				}
				// <-- ������ ����������
 
				
			link.l3 = pcharrepphrase("���� �� � ����� ���������� ��������� ������?", "��� �� � ���� ��������� �������, � �����"+ GetSexPhrase("","�") +" �� ������������ ����� �� ��������� �����.");
			link.l3.go = "room";
			Link.l4 = "�������, ������� � ���� �������.";
			Link.l4.go = "exit";
		break;
		
		case "crew hire":
PlaySound("VOICE\Russian\GOTHIC\GG_CREW\CREW_1.wav");
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			ok = sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok;
			
			if (!ok)
			{
				Dialog.text = "� �� ��� ���� �������? ���-�� �� ���� ������ ������� � �����.";
				link.l1 = RandPhraseSimple("�����... � ��� ������������"+ GetSexPhrase("","�") +" �� � ��� �����.", "�����"+ GetSexPhrase("","�") +" ����� � ����...");
				link.l1.go = "exit";
				break;
			}
			
            if (makeint(environment.time) > 22.0 || makeint(environment.time) < 7.0)
			{
				Dialog.text = "������ � ���� � ������� ����� �����, �������� ����� ���������, �� ������ ������� ������, � ��� ������ ���������� ������ �����. ����� ����, �� ������ ����� �������, � ��������� ��?";
				link.l1 = "������. � ���� ���� ��������� �������?";
				link.l1.go = "room";
				link.l2 = "���� �� ���������� ������� �� ������ ������. �� �������.";
				link.l2.go = "exit";
			}
			else
			{
                if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
                {
                    Dialog.text = "� �� �������, � ���� ���-�� ������, ����� �� � ���� �� ������? ����� �������, ��� ������ �� ����.";
					link.l1 = "�������.";
					link.l1.go = "exit";
                }
                else
                {
					if (CheckAttribute(NPChar, "CrewHired.PGGId") && GetNpcQuestPastDayParam(NPChar, "CrewHired") < 3 && GetCrewQuantity(rColony) == 0)
					{
						Dialog.text = "��������, �� ������ ��� ������. ��� ���� � �������� ����� " + GetFullName(CharacterFromID(NPChar.CrewHired.PGGId)) + ".";
						link.l1 = "��, ����!";
						link.l1.go = "exit_crew";
					}
					else
					{						
						if(bPartitionSet)
						{		
							if(GetPartitionAmount("CrewPayment") > 0)
							{
								if(IsEquipCharacterByArtefact(pchar, "totem_07"))
								{
									DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
									NextDiag.CurrentNode =  NextDiag.TempNode;
									DialogExit();
									LaunchHireCrew();							
								}
								else
								{
									dialog.text = "�������, ������������, ��� �� ���������. � ���� ��� �������� ����� � ���� �������.";
									link.l1 = "�������...";
									link.l1.go = "exit";
								}
							}
							else
							{
								DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
								NextDiag.CurrentNode =  NextDiag.TempNode;
								DialogExit();
								LaunchHireCrew();	
							}
						}	
						else
						{
							DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
							NextDiag.CurrentNode =  NextDiag.TempNode;
							DialogExit();
							LaunchHireCrew();							
						}						
					}
				}
			}
		break;
		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //�� ���� ������.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;
	////////////////////////////////////////////////////////=============================================///////////////////////////////////////////////////////	
        case "int_quests":
			dialog.text = "� ���� ��������.";
			//link.l1 = "� ��� ������. �� �������� ���?";
			//link.l1.go = "work";
			//homo 15/06/06 �����
			link.l2 = LinkRandPhrase("�������� ��� ��������� �������?","��� ���������� � ���� �����?",
                                    "��� ����� ����� �� ����?");
			link.l2.go = "rumours_tavern";
			//homo
			link.l3 = "� �� ������� ����.";
			link.l3.go = "quests";
			if(CheckAttribute(pchar,"GenQuest.EncGirl"))
			{
				if(pchar.GenQuest.EncGirl == "EncGirlFack_fighted")
				{
					link.l5 = "�� ������, ��� ��� ����� " + pchar.GenQuest.EncGirl.name +"?";
					link.l5.go = "EncGirl_1";
				}	
				if(pchar.GenQuest.EncGirl == "toParents" || pchar.GenQuest.EncGirl == "FindLover")
				{
					link.l6 = "�� ����������, ��� ��� ������ " + pchar.GenQuest.EncGirl.sLoverId + "?";
					link.l6.go = "EncGirl_3";
				}
				if(pchar.GenQuest.EncGirl == "toLoverFather" && pchar.GenQuest.EncGirl.LoverFather == "tavern_keeper" && pchar.GenQuest.EncGirl.LoverCity == npchar.city)
				{
					link.l7 = "������������, � ����"+ GetSexPhrase("��","��") +" �� ����������� ������ ����."; 
					link.l7.go = "EncGirl_4";
					pchar.quest.EncGirl_GetLoverFather.over = "yes";
				}
			}
			if(CheckAttribute(pchar,"QuestTemp.Andre_Abel_Quest_PortPax_TavernOwner_Speek"))
			{	
				link.l8 = "�� ����������, ��� ��� ������ ����� �����?";
				link.l8.go = "Andre_Abel_Quest_TavernOwner_Dialog_1";			
			}

			if(CheckAttribute(pchar,"GenQuest.CaptainComission") && NPChar.city == pchar.GenQuest.CaptainComission.City && CheckAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern"))
			{
				if(pchar.GenQuest.CaptainComission.variant == "A0")
				{												
					if(pchar.GenQuest.CaptainComission.Speak_Tavern == true)
					{
						link.l9 = "�� ���, �� ������� " + pchar.GenQuest.CaptainComission.Name + "?";
						link.l9.go = "CaptainComission_3";
					}
					else
					{
						link.l9 = "�� ����������, ��� ��� ������ " + pchar.GenQuest.CaptainComission.Name + "?";
						link.l9.go = "CaptainComission_1";
					}
				}	

				if(pchar.GenQuest.CaptainComission.variant == "A2" && pchar.GenQuest.CaptainComission == "Begin_1")
				{
					link.l9 = "�� �� ������, ��� � ���� ����� �������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc")) + " " + pchar.GenQuest.CaptainComission.Name + "?";
					link.l9.go = "CaptainComission_Tavern7";					
				}				
				if(pchar.GenQuest.CaptainComission.variant == "A3" && pchar.GenQuest.CaptainComission == "Begin_1")
				{
					if(pchar.GenQuest.CaptainComission.Speak_Tavern == true)
					{
						link.l9 = "�� ���, �� ������� " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.CanoneerName, NAME_NOM) + "?";
						link.l9.go = "CaptainComission_3";
					}
					else
					{					
						link.l9 = "�� ���-������ ������, � �������� ����������� " + GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc")) + " " + pchar.GenQuest.CaptainComission.Name + "?";
						link.l9.go = "CaptainComission_Tavern1";
						if(!CheckAttribute(pchar,"GenQuest.CaptainComission.GetRumour"))
						{
							pchar.GenQuest.CaptainComission.GetRumour = true;
							SaveCurrentQuestDateParam("GenQuest.CaptainComission.GetRumour");
						}	
					}	
				}					
			}
			if(CheckAttribute(pchar,"GenQuest.Hold_GenQuest") && NPChar.city == pchar.GenQuest.Hold_GenQuest.City && pchar.GenQuest.Hold_GenQuest.Speak_Tavern == false )
			{
				link.l10 = "�� ����������, ��� ��� ����� ��������� �� ����� " + pchar.GenQuest.Hold_GenQuest.Name + "?";
				link.l10.go = "hold_genquest1";
			}
			if (CheckCharacterItem(pchar, "CaptainBook") && CheckAttribute(pchar, "questTemp.different.GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakTavern") && (pchar.questTemp.different.GiveShipLetters.city == npchar.city))
			{
				link.l11 = "� ���������� �������� ���������� ���"+ GetSexPhrase("��","��") +" ������� ���������....";
				link.l11.go = "ShipLetters_4";			
			}

                        //���
			if(pchar.questTemp.Headhunter == "hunt_carlos" && npchar.city == pchar.questTemp.Headhunter.City)
			{	
				link.l12 = "�� ����������, ��� ��� ������ ������� �������?";
				link.l12.go = "Seek_Carlos";
				CreateCarlos();			
			}

			// Jason --> ����� ������ �� ����� ���������
			if(CheckAttribute(pchar, "GenQuest.FindFugitive") && pchar.GenQuest.FindFugitive != "Late" && sti(NPChar.nation) == PIRATE)
			{
				link.l13 = "��������, � ��� ������ ������� �����, "+pchar.GenQuest.FindFugitive.Name+" ��� �����. ���� ������ ������ ���, ��� �� ��������� ����������� ������ � ���� ���������. �� ������ ������ �� ���� ��������?";
				link.l13.go = "FindFugitiveTav";
			}
			//<-- ����� ���������

			//zagolski. ��������� ����� ������
			if(CheckAttribute(pchar, "questTemp.pirateStartQuest") && pchar.questTemp.pirateStartQuest == "1" && GetArealByCityName(npchar.city) == pchar.questTemp.pirateStartQuest.Areal && npchar.city != pchar.questTemp.pirateStartQuest.City)
			{
				if (!CheckAttribute(pchar, "questTemp.pirateStartQuest.TavernInfo"))
				{
					link.l14 = "������, �������, �� ����������, � ��� ����� ����� ������ �� ��������������?";
					link.l14.go = "pirateStartQuest_Tavern";
				}
				else
				{
					if (sti(pchar.money) >= 1000)
					{
						link.l14 = "������ � ���� 1000 ��������. ������ ��� ������.";
						link.l14.go = "pirateStartQuest_Tavern_2";
					}
				}
			}

			link.l15 = "�������, ������. �� ��������.";
			link.l15.go = "exit";
		break;

		//-------------------------------------------
		case "pirateStartQuest_Tavern":
			dialog.text = "��, �� ���"+ GetSexPhrase("��","��") +" � ���� ��������! � �������� ��������� � ������� ����� ���� �������� ����� ������.";
			link.l1 = "���"+ GetSexPhrase("","�") +"  � ���. ������ � ��� ������ ���, � ����� � �� ���� - ����� �������� ������ ���������. � ���� ������� ����� ���� ����, ����� �� � �� ����� �����.";
			link.l1.go = "pirateStartQuest_Tavern_1";
		break;
		case "pirateStartQuest_Tavern_1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_20.wav");
			dialog.text = "��, �� ��� �, ����� ���-�� � ����... �� ����������� �������� �� ����, � �������������������� �� ���������. ��� ���������� ����� 1000 ����. ����� ��� �����.";
			if (sti(pchar.money) >= 1000)
			{
				link.l1 = "������, ��� ���� 1000 ����... ������ ��� ������.";
				link.l1.go = "pirateStartQuest_Tavern_2";
			}
			else
			{
				link.l1 = "� ���� ��� ����� �����... �������, ����� ���������.";
				link.l1.go = "exit_gold";
			}
		break;

		case "exit_gold":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "� ���� �� ���������� ������...";
		link.l1 = "";
		link.l1.go = "exit";
		pchar.questTemp.pirateStartQuest.TavernInfo = "";
		break;

		case "pirateStartQuest_Tavern_2":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		AddMoneyToCharacter(pchar, -1000);
		dialog.text = "��� ��� ������...";
		link.l1 = "";
		link.l1.go = "pirateStartQuest_Tavern_02";
		break;

		case "pirateStartQuest_Tavern_02":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneyToCharacter(pchar, -1000);
		dialog.text = "��, �� ����. ���� ��� ���������, ������� ����� �������� ���� ����� �� ���������. ���������� ���� �������, ��� ������ ����� ������. ����� ��� � ��������������� �����������. �� ������ ���� ������ ����� � ����� ��������, ���� �� ��� ����� ������� ���������� �� �� ���������...";
			link.l1 = "����. � �� ������, ����� '������' ������� � ��� � ���� �� ��������?";
			link.l1.go = "pirateStartQuest_Tavern_3";
		break;

		case "pirateStartQuest_Tavern_3":
		dialog.text = "'������'? ���, ����� �� ��������. �� � �������� ��� ��� �� �������.";
		link.l1 = "";
		link.l1.go = "pirateStartQuest_Tavern_03";
		break;

		case "pirateStartQuest_Tavern_03":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_8.wav");
		dialog.text = "";
		link.l1 = "�������, ��� ������� � �����, �������. �� ��� ������� �����. �� �������.";
		link.l1.go = "exit";

		PChar.questTemp.pirateStartQuest = "2";
		pchar.questTemp.pirateStartQuest.City2 = npchar.city;
		DeleteAttribute(pchar, "questTemp.pirateStartQuest.TavernInfo");
		AddQuestRecord("pSQ", "2");
		AddQuestUserData("pSQ", "sCity2", XI_ConvertString("Colony" + pchar.questTemp.pirateStartQuest.City2 + "Gen"));
		break;

		
		case "hold_genquest1":
			switch(sti(pchar.GenQuest.Hold_GenQuest.TavernVariant))
			{
				case 0:
					dialog.text = LinkRandPhrase("��� �� ��������? " + pchar.GenQuest.Hold_GenQuest.Name + "? ��, ������� �� ������ � �����.",
						"�� ����� ������, ��� �� ������ �� ������ ���������? ������ �� �������� � ����� �� ����.",
						"� ����� ��������� ������ �������� �� ����. ������� ����� ���� - �� ������.");
					link.l1 = "� �� �������?";
					link.l1.go = "hold_genquest2";					
				break;
				
				case 1: 
					switch (drand(3))
					{
						case 0:
							pchar.GenQuest.Hold_GenQuest.foundStr = "� �������";						
							pchar.GenQuest.Hold_GenQuest.found = "church";
						break;
						case 1:
							if (npchar.city != "Panama")
							{
							pchar.GenQuest.Hold_GenQuest.foundStr = "�� �����";						
							pchar.GenQuest.Hold_GenQuest.found = "shipyard";
							}
							else
							{
								pchar.GenQuest.Hold_GenQuest.foundStr = "� �������";						
								pchar.GenQuest.Hold_GenQuest.found = "church";
							}
						break;
						case 2:
							pchar.GenQuest.Hold_GenQuest.foundStr = "� ����������";												
							pchar.GenQuest.Hold_GenQuest.found = "bank";
						break;
						case 3:
							pchar.GenQuest.Hold_GenQuest.foundStr = "� �������";						
							pchar.GenQuest.Hold_GenQuest.found = "store";
						break;
					} 
					dialog.text = "������� " + pchar.GenQuest.Hold_GenQuest.foundStr + ", �� ��� ����� ������.";
					link.l1 = "�������, ����� ����������.";
					link.l1.go = "hold_genquest3";				
				break;
				
				case 2:
					dialog.text = LinkRandPhrase(
						RandPhraseSimple("��� �� ��������? " + pchar.GenQuest.Hold_GenQuest.Name + "? ��, ������� �� ������ � �����. � �� �������, ��� �� ������ �� ������ ���������?",
						"�-��-��... ����� ���� ������� ��� �����, ��� ������ ��� ������ - �� �� �� �������, �� �� � �����������. ����� ��... ��� ������ ��� ��� �����, � �� � �� ������������, ����������, �� ��� ����� �� ���� �������..."),
						RandPhraseSimple("�� ������ �� ��� ���, �� ���� ����� ��� �����. �� ��� ����� ����� ��, �� ����� ���������... �������� ��� ��������... � ����� ������� ����� ���! � ���������, ������������, ����� ���� ������, ��� �� ������� �������! � ���� � �� - ������ ������� - � �������, ��� �����...",
						"��, ���������! �� ������ ����� ��. �� �� � ����� �������, �� �� � ������ - ������ �� ��������. ������ ������ ������� � ��������."),
						"�-�, ��� �� ���� �� " + pchar.GenQuest.Hold_GenQuest.Name + " �� �����, ��� ����� ���������� � ����� ���� ��� � ����� ��������? � ���� ���� �������, ����� � ��� � ���� ����� ��������! �� � �� ��� ���� ��� ������ �������. ��� ���� � �� - ������� ��� ������! ���, �� ������ ���� �����...");
					link.l1 = "����. ��, ������� � �� ����.";	
					link.l1.go = "hold_genquest4";
				break;
				
				case 3:
					dialog.text = "� ��� �� ��� ������, ���� �� � ��� � �������? �� ����� ��������� ���������� - ����� ������ ����� ��������, ��-��. �� ������� �������, ���� �� ��������, � �����, ���� ��� ��������.";	
					link.l1 = "�������, �����.";
					link.l1.go = "hold_genquest5";
				break;
			}
			pchar.GenQuest.Hold_GenQuest.Speak_Tavern = true;
		break;
		
		case "hold_genquest2":
			dialog.text = "��� �� �� ���� ���������-��, ���� � ���� ������� ����������, ��� ������ ����. ��� �� ������ ��� ������� �����. "+
				"� �� ���� � ������ ����� ������� - ���� ���� ����� �����, ��� ������ ��� � ������ ������ � ������ ����������, � ���� � ������ ���������� �����������. � �� ��� - '�������'!";
			link.l1 = "�� �����, ������� � �� ����...";	
			link.l1.go = "exit";
			pchar.GenQuest.Hold_GenQuest = "prisoner_escaped";
			AddQuestRecord("HoldQuest", "7");
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.CapName);
			AddDialogExitQuestFunction("Hold_GenQuest_PrisonerEscaped");
		break;
		
		case "hold_genquest3":
			Hold_GenQuest_GenerateChar();		
			AddQuestRecord("HoldQuest", "8");
			AddQuestUserData("HoldQuest", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.Hold_GenQuest.City + "Gen")); 			
			AddQuestUserData("HoldQuest", "sFoundChar", pchar.GenQuest.Hold_GenQuest.foundStr);
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.Name);
			SetFunctionTimerConditionParam("Hold_GenQuest_FindCharTimeIsOver", 0, 0, 1, MakeInt(24 - GetHour()), false);
			DialogExit();
		break;
		
		case "hold_genquest4":
			AddQuestRecord("HoldQuest", "13");
			AddQuestUserData("HoldQuest", "sName", pchar.GenQuest.Hold_GenQuest.CapName);
			AddQuestUserData("HoldQuest", "sNameChar", pchar.GenQuest.Hold_GenQuest.Name);
			AddQuestUserData("HoldQuest", "sSex", GetSexPhrase("��","��"));
			CloseQuestHeader("HoldQuest");
			DeleteAttribute(pchar,"GenQuest.Hold_GenQuest");			
			DialogExit();
		break;
		
		case "hold_genquest5":
			SetFunctionTimerConditionParam("Hold_GenQuest_GetMapTimeIsOver", 0, 0, 1, MakeInt(24 - GetHour()), false);
			DialogExit();
			AddDialogExitQuestFunction("Hold_GenQuest_GenerateMapChar");			
		break;
		
		case "CaptainComission_1":
			dialog.text = LinkRandPhrase("�� ��������� ���� �������, �� ������ ���-�� �� �����. ������������ �� ��� ����� �� �������, ���� �� ��������, � �����, ���� ��� ��������.","�� ����� ����� ������. ���� �� ������ �����, �� ��������� ��� ���������.","�������� ����� �� �������, �� ����� ����� ����������. � �������, ��� �� ��� ������.");
			link.l1 = "�������, ����� �������...";
			link.l1.go = "CaptainComission_2";
			pchar.GenQuest.CaptainComission.Speak_Tavern = true;
		break;
		
		case "CaptainComission_2":
			pchar.quest.CapComission_ExitFromTavern.win_condition.l1 = "ExitFromLocation";
			pchar.quest.CapComission_ExitFromTavern.win_condition.l1.location = pchar.location;
			pchar.quest.CapComission_ExitFromTavern.function = "CaptainComission_GenerateChar";

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "CaptainComission_3":
			dialog.text = "�������. ������ ������ ���-�� �����...";
			link.l1 = "�������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern");
		break;
		
		case "CaptainComission_Tavern1":
			pchar.GenQuest.CaptainComission.Speak_Tavern = true;
			dialog.text = "��� �� � �� �� �����? ��� ��� ������� ���� � ��������� ������ �� ���� � �������.";
			link.l1 = "������ ���������� ���������?";
			link.l1.go = "CaptainComission_Tavern2";
		break;
		
		case "CaptainComission_Tavern2":
			dialog.text = "� �����, ������� ����� �������� ������ � ������ ��� �������, ������ ����� �������� �� ����������, ����� ������� � �����... �� ���? � ������������� ��������� ����� ������ ��������, ��� �� �� ����� �������������� ����� ������ �� ��� ���������� � ��������� �����, � ����� �� ��� ����� �������\n"+
				"�� ������� � ��� � ������, ������ ���, �� ��������� ����� �����, �� ����� ��� � �� �����... �� ��� ��� ��� ����� �����������.";
			link.l1 = "���, ����� �� ������� �� ���������, ��� ������?";	
			link.l1.go = "CaptainComission_Tavern3";	
		break;
		
		case "CaptainComission_Tavern3":
			dialog.text = "�� ����!.. �� ������ � ����, ������ ���������� ��� ����� ������� ����� ������? ���� ������� " + pchar.GenQuest.CaptainComission.Name + " ��� �� ������� �����, � ��� ������� ������ - ����� ������� ����������, �� �������� ����� �����.";
			link.l1 = "� ��� ��� ������ ���������� � ����� ������ �������?";
			link.l1.go = "CaptainComission_Tavern4";
		break;
		
		case "CaptainComission_Tavern4":
			dialog.text = "��, ����� �� � �� ����, ������ �� ����... ���� ���, ���� �������, �� ����� �� ���� ��� ���� �� �����. �� ����������, ��������� ��� � " + pchar.GenQuest.CaptainComission.Name + ". ��� ����� ��� �������� � �����-�� ����� ������ ��� ��� ����� ���� ������������ ������. ������� � ��������� ����������, ��� �����, � ����� ���� ������� ������ ������ - �������� � ������� � �������� �����������, �� ����� ������, ��� ��-���� ����� ������.";
			link.l1 = "��� �� ������ � ���������?";
			link.l1.go = "CaptainComission_Tavern5";
		break;
		
		case "CaptainComission_Tavern5":
			pchar.GenQuest.CaptainComission.CanoneerName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);
			dialog.text = "��, " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.CanoneerName, NAME_NOM) + " ��� �����, ������ ���� �������, ��� �����������. ���� � ��� �����, ����� - ���� ��� ��������.";
			link.l1 = "�������, � ����� ���������.";
			link.l1.go = "CaptainComission_Tavern6";
		break;
		
		case "CaptainComission_Tavern6":
			AddQuestRecord("CaptainComission2", "39");
			AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc"))); 
			AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);
			AddQuestUserData("CaptainComission2", "sCharName", GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.CanoneerName, NAME_ABL));
			AddQuestUserData("CaptainComission2", "sShipName", pchar.GenQuest.CaptainComission.ShipTypeName);			
			SetFunctionExitFromLocationCondition("CaptainComission_GenerateCanoneer", pchar.location, false);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "CaptainComission_Tavern7":
			DeleteAttribute(pchar,"GenQuest.CaptainComission.Speak_Tavern");
			dialog.text = "��� �� �����? ���� �������. � ��� �� �� ���?";
			link.l1 = "���� � ���� � ����.";
			link.l1.go = "CaptainComission_Tavern8";
		break;
		
		case "CaptainComission_Tavern8":
			dialog.text = "�� ��, " + GetAddress_Form(pchar) + ", ������������ � ���� '�����'. " + pchar.GenQuest.CaptainComission.Name + " ������� �� ���������� � ��������� ������������, � ������ �� ����� ������� ����� �������������� ������ � ������� ��� ����������.";
			link.l1 = "������... � ��� �� ����� ��������?";
			link.l1.go = "CaptainComission_Tavern9";
		break;
		
		case "CaptainComission_Tavern9":
			dialog.text = "�� ���� ��������� ��� ������, �� �������, ��� �� ������� ����, ������� ����������� � ����������� ���� ���������� �����. ������ ��� �� ������, �� ����� ����� ������ �� �������. �� ������ � ����, ������ ���������� ��� ����� ������� ����� ������? ���� ������� " + pchar.GenQuest.CaptainComission.CapName + " ��� �� ������� �����, � ����� �� ��������, �� �������� ����� �����, " + GetAddress_Form(pchar) + ".";
			link.l1 = "��, �������, ��� �����������. ����� ��������.";
			link.l1.go = "CaptainComission_Tavern10";
		break;
		
		case "CaptainComission_Tavern10":
			if(!CheckAttribute(pchar,"GenQuest.CaptainComission.GetRumour"))
			{
				pchar.GenQuest.CaptainComission.GetRumour = true;
				SaveCurrentQuestDateParam("GenQuest.CaptainComission.GetRumour");
				SetFunctionTimerConditionParam("CaptainComission_TimeIsOver", 0, 0, 2, MakeInt(24 - GetHour()), false);
				AddQuestRecord("CaptainComission2", "19");
				AddQuestUserData("CaptainComission2", "sShipType", GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.CaptainComission.ShipType),"Name") + "Acc"))); 
				AddQuestUserData("CaptainComission2", "sName", pchar.GenQuest.CaptainComission.Name);
			}			
			DialogExit();
		break;
				
		case "EncGirl_1":
			dialog.text = "� ��� ��� ����� ������������?";
			link.l1 = "���� � ��� ����...";
			link.l1.go = "EncGirl_2";
		break;
		
		case "EncGirl_2":
			dialog.text = "� �������� ������� ������ ��������� � ��� ���� ����. ���� �� ������� � �������, �� ������� ���������� �� �� ��������� ������.";
			link.l1 = "�-��. "+ GetSexPhrase("������, � ���� � ����� ������� �������. ���� � ��� ����� ����������, �����, ����� �������� �� ����","�������") +"...";
			link.l1.go = "exit";
			pchar.quest.EncGirl_SpeakTavernKeeper.over = "yes";
			DeleteAttribute(pchar, "GenQuest.EncGirl");
		break;
		
		case "EncGirl_3":
			dialog.text = "�� ��������� ���� ������� � ������� ��������� ������, �� ������ ���-�� �� �����. ������������ �� ��� ����� �� �������, ���� �� ��������, � �����, ���� ��� ��������.";
			link.l1 = "�������, ����� �������...";
			link.l1.go = "exit";
			pchar.GenQuest.EncGirl = "FindingLover";
			pchar.quest.EncGirl_ExitTavern.win_condition.l1 = "ExitFromLocation";
			pchar.quest.EncGirl_ExitTavern.win_condition.l1.location = pchar.location;
			pchar.quest.EncGirl_ExitTavern.function = "EncGirl_GenerateLover";
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
				
		case "ShipLetters_4":
			pchar.questTemp.different.GiveShipLetters.speakTavern = true;
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 0)
			{
				dialog.text = "�����-�� ��������� ! ��... �� �� ���� - �������. �����, ��� ����� ����� � ���������� �����.";
				link.l1 = "������� �� �����.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�����-�� ���������! �! ���� �� �����, ��� ����������� ������ ����� ����������� ����������, ������ ���������� ��������. � ���� ��� �������� ��������� ���������.";
				link.l1	= "�������, ��� ...";
				link.l1.go = "exit";
				link.l2 = "���"+ GetSexPhrase("","�") +", ��� ����"+ GetSexPhrase("","��") +" ���� ��� �����"+ GetSexPhrase("��","��") +".";
				link.l2.go = "ShipLetters_end";				
			}	
		break;
		
		case "ShipLetters_end":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "3");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters"); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//zagolski. ���������
		case "work":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_DIEBESWERK\DIEBESWERK_" + rand(8) + ".wav");	
			if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
			{
				dialog.text = RandPhraseSimple("��� ��� ������� ���� ����������� - ������ �� ����� ��������������. �� ��� �������� ���� � �� �����, ��� ��� �� ����"+ GetSexPhrase("��","��") +" ��� ������ " + NationNameGenitive(sti(pchar.nation)) + ".", "� ����� ���� ������� ������ �������, �� ������������ � " + NationNameAblative(sti(pchar.nation)) + " �������� ������� �� ����.");
				link.l1 = RandPhraseSimple("��, ���� �����...", "��, ��� ������...");
				link.l1.go = "exit";
				break;
			}
			if (isBadReputation(pchar, 40))
			{
				dialog.text = RandPhraseSimple("���������� ������ �������. ������ ���� �� ����� ��� �������� ����� ����������, ����� ������� �������������� �� ����� �����. ������ ����� ����� ������� ����, � ��������� �������� �������� ��� ��������� �����.", "�� ��� ����� ���������� ��������, ������� ����� �������������. �� ������ ����� ����� �� ����� �� �����, � � ������ �� ����� ������������� ���� ������. ��� ���� ��������� ������.");
				link.l1 = RandPhraseSimple("�� �� ���� �������� ������ ��������...", "�� ��, ���� ��� �� �����������...", "��, ���������� ����� ������� �����...");
				link.l1.go = "exit";
				break;
			}
			if (sti(Pchar.Ship.Type) == SHIP_NOTUSED)
        	{
				dialog.text = "� ������� ���� ���? �� ��� - �� ����������� ����� ���������� ������ ��������?";
				link.l1 = "��, � �� �����...";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "������ ��������, ���� �� ������� ������ � ��������� ��������� ��� � ����� ��������� �����. ���-�� ���������� ����������?";
			link.l1 = "��, ��� �� �������. � �� ����"+ GetSexPhrase("��","���") +" �� ������.";
			link.l1.go = "work_1";
			link.l2 = "��������� ����? ������, ���� � ����� � ����, ���� �� ������ �������.";
			link.l2.go = "work_2";
			link.l3 = "���, ����� ������ �� �� ���. �������.";
			link.l3.go = "exit";
		break;

		case "work_1":

				dialog.text = "�� ������ ������� �� ��� �� ���������� ������. ����������� ��� � ������� ������ - ��������, �� ����������� ���� ������.";
				link.l1 = "������. ��� �������.";
                link.l1.go = "exit";
		break;


		case "work_2":
			if (!CheckAttribute(npchar, "work_date") || GetNpcQuestPastDayParam(npchar, "work_date") >= 2 || bBettaTestMode)
    		{					
				if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < 5)//��� ������ ���������� �� ����
				{
					dialog.text = "��������, �� �������� ����������� � ���� ������ � ���� � ���� ���.";
					link.l1 = "�������. ��� �������.";
					link.l1.go = "exit";
					break;
				}
		         // ��������
				if (drand(6) > 1)
				{
					dialog.Text = "��� ��� � ������� �����, �� ������� �������� ����� ���������, ����-�� ��������� �����. ���� ������, ���������� � ���.";
					link.l1 = RandPhraseSimple("� ��� �� ���? ����� ���������� �����, ��� � �������?", "� ��� �� �����? ������� � ��� �� �����?");
					Link.l1.go = "PassangerAreYouSure";
				}
				else
				{
					dialog.text = "���, ������� �� ���� �� ���������. �����, � ������ ����...";
					link.l1 = RandPhraseSimple("�� ���, ��� ���. ���� �� ���...", "��, �� ������... �� �����, ��������.");
					link.l1.go = "exit";
				}
            }
    		else
    		{
				dialog.text = "������� ��� ������ ���. �������� ����� ���� ����.";
				link.l1 = "������. ��� �������.";
                link.l1.go = "exit";
    		}
        break;

        case "ConvoyAreYouSure":
		    dialog.text = LinkRandPhrase("�� ��� � ��� �����. �� �������"+ GetSexPhrase("","�") +" - � �������.", "��, ��� �� ���� ����"+ GetSexPhrase("��","�") +" ������. � �� ��� �� �� ���� �� ���������.", "����� ���"+ GetSexPhrase("","�") +", �� ��� ������ ����������. ��� �� �������, � �� ���������� �����������.");
			Link.l1 = "�� �������, ������ �����������.";
			Link.l1.go = "exit";
			pchar.quest.destination = findTraderCity(npchar);
			pchar.ConvoyQuest.City = npchar.city;
			AddDialogExitQuest("prepare_for_convoy_quest");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
        break;

        case "PassangerAreYouSure":
		    dialog.text = LinkRandPhrase("�� ��� � ��� �����. �� �������"+ GetSexPhrase("","�") +" - � �������.", "��, ��� �� ���� ����"+ GetSexPhrase("��","�") +" ������. � �� ��� �� �� ���� �� ���������.", "����� ���"+ GetSexPhrase("","�") +", �� ��� ������ ����������. ��� �� �������, � �� ���������� �����������.");
			Link.l1 = "����, ������ ������� ��� ��� �� ���.";
			Link.l1.go = "exit";
			sGlobalTemp = findPassangerCity(npchar);
			pchar.GenQuest.GetPassenger_City = npchar.city;
			AddDialogExitQuest("prepare_for_passenger_quest");
			SaveCurrentNpcQuestDateParam(npchar, "work_date");
        break;

		 case "fight":
			DialogExit();
            NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "room":
   			if (chrDisableReloadToLocation || CheckAttribute(pchar, "questTemp.different.Church_NightGuard")) //���-�� ������ ������� � ��.
			{
				dialog.text = "������ ������� ������, " + GetAddress_Form(NPChar) + ", ����� �� ���� ������.";
				link.l1 = "����, ����� ����...";
				link.l1.go = "exit";
				break;
			}
			// ��� �� ��������
			if (CheckAttribute(pchar, "questTemp.Terrapin.Room_close") && npchar.location == "Tortuga_tavern")
			{
				dialog.text = "������� � ���� ������ ������� ����� ���� ����, � ������� �� �� ����� ������, ��� ��� ����� ������ �� ����, �������.";
				link.l1 = "����, ����� ����...";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "cave" && npchar.location == "Tortuga_tavern")
			{
				dialog.text = "������ ������� ������, " + GetAddress_Form(NPChar) + ", ����� �� ���� ������.";
				link.l1 = "����, ����� ����...";
				link.l1.go = "exit";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "shore" && npchar.location == "Baster_tavern") // 070712
			{
				dialog.text = "������ ������� ������, " + GetAddress_Form(NPChar) + ", ����� �� ���� ������.";
				link.l1 = "����, ����� ����...";
				link.l1.go = "exit";
				break;
			}
			//-->> ����� ����������
			if (pchar.questTemp.different == "FackWaitress_toRoom")
			{
				dialog.text = "�� ������ ����� �������? �� ��������. � ��� 100 ����� - � ������ ���� ������.";
				if (sti(pchar.money) >= 100)
				{
				link.l1 = "������� ���� ������, �������� �������, ��������...";
				link.l1.go = "exit";
				AddMoneyToCharacter(pchar, -100);
				LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2_back", false);
				LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2", false);
				pchar.questTemp.different = "FackWaitress_toRoomUp";
				}
				else
				{
				link.l1 = "��, �, �������, ������� �������...";
				link.l1.go = "exit";
				}
				break;
			}
			if (pchar.questTemp.different == "FackWaitress_toRoomUp")//����� ����������
			{

				dialog.text = "������� ����, ����� � ���������...";
				link.l1 = "������, ��������, �������.";
				link.l1.go = "exit";
				break;
			}
			//<<-- ����� ����������
			// --> ����� "������ � ��������"
			if(CheckAttribute(pchar,"GenQuest.EncGirl") && npchar.city == pchar.GenQuest.EncGirl.city)
			{
				if(pchar.GenQuest.EncGirl == "EncGirl_ToTavern")
				{
					dialog.text = "�� ������ ����� �������? �� ��������. � ��� 100 ����� - � ������ ���� ������.";
					if (sti(pchar.money) >= 100)
					{
						link.l1 = "������� ���� ������, �������� �������, ��������...";
						link.l1.go = "exit";
						AddMoneyToCharacter(pchar, -100);
						LocatorReloadEnterDisable(npchar.city + "_tavern", "reload2_back", false);
						pchar.GenQuest.EncGirl = "EncGirl_toRoomUp";
					}
					else
					{
						link.l1 = "��, �, �������, ������� �������...";
						link.l1.go = "exit";
					}
					break;
				}
				if (pchar.GenQuest.EncGirl == "EncGirl_toRoomUp")//�����  �� �������� ����� � ��������
				{
					dialog.text = "������� ����, ����� � ���������...";
					link.l1 = "������, ��������, �������.";
					link.l1.go = "exit";
					break;
				}
			}
			// <-- ����� "������ � ��������"
			dialog.text = "�� ����� ���� �� ���������� ������������?";
			if(!isDay())
			{
				link.l1 = "�� ����.";
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = "�� ����.";
				link.l1.go = "room_night";
				link.l2 = "�� ���������� ����.";
				link.l2.go = "room_day_next";
			}
		break;

		case "room_day":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
			dialog.text = "��� ��������� ��� � 5 ����.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "����. ��� ���� ������.";
				link.l1.go = "room_day_wait_0";
			}
			link.l2 = pcharrepphrase("�� ������ ����������� �����? ��� ��, �� ����� ���� � ����� ������ � ����� ����.",
            "���, ������, ����� �������, ��� ��� �� �������, �� ��� ����� ��������. � ��������� � ����� ����.");
			link.l2.go = "hall_day_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "�� ������. ����� ��������� � ���-������ ������.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_day_next":
 	                    PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
			dialog.text = "��� ��������� ��� � 10 ����.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "����. ��� ���� ������.";
				link.l1.go = "room_day_wait_next_0";
			}
			link.l2 = pcharrepphrase("�� ������ ����������� �����? ��� ��, �� ����� ���� � ����� ������ � ����� ����.",
            "���, ������, ����� �������, ��� ��� �� �������, �� ��� ����� ��������. � ��������� � ����� ����.");
			link.l2.go = "hall_day_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "�� ������. ����� ��������� � ���-������ ������.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_night":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_01.wav");
			dialog.text = "��� ��������� ��� � 5 ����.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "����. ��� ���� ������.";
				link.l1.go = "room_night_wait_0";
			}
			link.l2 = pcharrepphrase("�� ������ ����������� �����? ��� ��, �� ����� ���� � ����� ������ � ����� ����.",
            "���, ������, ����� �������, ��� ��� �� ������� �� ��� ����� ��������. � ��������� � ����� ����.");
			link.l2.go = "hall_night_wait";
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
			{
				link.l3 = "�� ������. ����� ��������� � ���-������ ������.";
				link.l3.go = "int_quests";
			}
		break;

		case "room_night_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_15.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "��� ���� ������!"; 
		link.l1.go = "room_night_wait";  
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_night");
		break;

		case "hall_night_wait":
                                        PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
			if (cRand(3) == 1)
            {
                Dialog.text = "��������, �������"+ GetSexPhrase("��","��") +"! ������ ��� � ����� ���� ����������� �� ���������.";
				link.l1 = "�����, �����... ��� �����.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_night");
			}
		break;

		case "room_day_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_11.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "������ - ��� ������!";
		link.l1.go = "room_day_wait";
		break;

		case "room_day_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			AddDialogExitQuest("sleep_in_tavern");
			if (CheckAttribute(pchar, "GenQuest.LigaAttack") && drand(1) == 1)
			{
				TavernWaitDate("wait_night");
				pchar.GenQuest.LigaAttack.Go = "true"; //����� ��������
			}
			else TavernWaitDate("wait_day");
		break;

		case "room_day_wait_next_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_17.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "��� - �����!";
 		link.l1.go = "room_day_wait_next";
		break;

		case "room_day_wait_next":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			if (CheckAttribute(pchar, "GenQuest.LigaAttack") && drand(1) == 1)
			{
				TavernWaitDate("wait_night");
				pchar.GenQuest.LigaAttack.Go = "true"; //����� ��������
			}
			else TavernWaitDate("wait_day");
		break;

		case "hall_day_wait":
                                       PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_16.wav");
			if (drand(1) == 1)
            {
                Dialog.text = "��������, �������"+ GetSexPhrase("��","��") +"! ������ ��� � ����� ���� ����������� �� ���������.";
				link.l1 = "�����, �����... ��� �����.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_day");
			}
		break;
		
		case "tavern_keeper":
			NextDiag.TempNode = "First time";

			dialog.text = "���������, ����� ��� ���������� ��� ���������� � ���� �������, ��� � ������ ����������!";
			link.l1 = "�����, �����, � ��� �����.";
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
		
		//******************* ���� ������ ����������. ����� ���������� (����� � 2)**********************
		case "Tavern_GenQuest_Church_2_1":
			dialog.text = "��� �� ���� ���� ��� ��������... ������ ����� ����-������ �� ������������.";
			link.l1 = "����, �������.";
			link.l1.go = "exit";
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2.AskBarmen");
		break;
			
		//******************* ���� ������ ����������. ������� �������� (����� � 1)**********************
		case "Tavern_ChurchGenQuest1_Node_1":
			dialog.text = "�� �� ����������� � ����, �����"+ GetSexPhrase("�","���") +".";
			link.l1 = "� ������"+ GetSexPhrase("","��") +" �������������� ������� �������, ��������. ��� ����� ��� �� ��������� ������ ��� �������?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_2";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_2":
			dialog.text = "��������, �����"+ GetSexPhrase("���","��") +" �������, �� ��� ���� ��������, � � �������...";
			link.l1 = "�������� �����, ��������, � ����������� ����������. ��� ������� ���� ������ ��� ���������� ����?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_3";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_3":
			iTemp = (rand(3)+1)*100;
			PChar.GenQuest.ChurchQuest_1.MoneyToBarmen = iTemp;
			if(rand(1) == 0) // "���� �� ������� � ����� �����"
			{
				dialog.text = FindRussianMoneyString(iTemp) + ", �����"+ GetSexPhrase("���","��") +" �������, � �� ������� � ����� ��������� ����� - ��� ��, ��� � ���� ���� ��� ���� �������.";
				if(sti(PChar.money) >= iTemp)
				{
					link.l1 = "����� ������ � ����� ���� �����������. �� ����������, ��� ���� �� ������� ���, � ������� ������ �����������!";
					link.l1.go = "Tavern_ChurchGenQuest1_Node_4_1";
				}
				else
				{
					link.l1 = "������� �������... ������ � ������� ���� ��� ������";
					link.l1.go = "exit";
					PChar.GenQuest.ChurchQuest_1.NoMoneyToBarmen = true;
				}
			}
			else // "���� �� �� �������"
			{
				dialog.text = FindRussianMoneyString(iTemp) + ", �����"+ GetSexPhrase("���","��") +" �������.";
				link.l1 = "� ������ ��� ���� � ������ ��, ��� �� ������� � �����.";
				link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2";
			}
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_1":
			DialogExit();
			AddMoneyToCharacter(PChar, -sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen));
			AddItems(PChar, "Bible", 1);	// ���� ��������
			items[FindItem("Bible")].Name = "itmname_ChurchGenQuest1Bible";	// ������ ���. ����� �������� �������!
			ChangeItemDescribe("Bible", "itmdescr_ChurchGenQuest1Bible"); // ������ ��������. ����� �������� �������!
			items[FindItem("Bible")].City = XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"); // ����������. ����� �������!
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen");
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "8");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"));
			AddQuestUserData(sQuestTitle, "sName", GetFullName(CharacterFromID("ChurchGenQuest1_Cap")));
			PChar.GenQuest.ChurchQuest_1.Complete = true; // ����� ��������
			SetFunctionTimerCondition("Church_GenQuest1_DeleteCapitan", 0, 0, 2, false);
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2":
			dialog.text = "���, �����"+ GetSexPhrase("�","���") +", ��� �� �����.";
			link.l1 = "��� ������ '�� �����'?! �� ���� ����������� ��� ���� - �� �������. �� ��������� ���� ������ - �� �������. ��� ���������� ����� - � �����"+ GetSexPhrase("��","���") +". ��� ��������, � ���� ������. ������ ��� '�� �����'?";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_1";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_1":
			dialog.text = "������, �����"+ GetSexPhrase("���","��") +" �������, ��� ��� �� ����� ������. � ������� ������ ���� ����� ������ ��������, � ���� �� ��������, ��� �����-������ �� ������ ������������, � ��������� ����� ��� ��������.";
			link.l1 = "��� ��� - �� ����� ������? ������, �� ����� �������� ���� �����? �� �����, �� ��� �������?!";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_2";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_2":
			dialog.text = "��� ��� �� ��� �������, �����"+ GetSexPhrase("�","���") +". ��� ��������� ��� ��� ����� �����, � �� � ����� ���� ����, ��� ���������� �� ����, ���� ��������� ������� ���� �� ���������. ����� ���������� �����������, ������ ��� � ������, � ������ �� ������ ��������� ���� ����. � ��� ��� ��� ������� ���������� ������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + " � ��������� � ����� ��������� �����. � �� ��� ��������� ������ ������������ - ����� �� ������� �������������� ������ ������ - � ����� ������� �� ������������ ����� ������ ����������� ����������.";
			link.l1 = "�������� ���, ���� ������, �� ���� ������� �����, ��� ��� ����������� ����������� ������� ����������, �� ���� ���� �� ����������, � ��������������� ��������, ����� ��������� ����������, ������� ����� �����������, � �������� � �������� ����, ��� �� ��� ��������... � �����"+ GetSexPhrase("","�") +" �� �������� �� � ���� � ��������� ��� � ������� � �����������.";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_3";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_3":
			dialog.text = "�����"+ GetSexPhrase("�","���") +"... �����"+ GetSexPhrase("���","��") +" �������... �������, � �����, � �� ����� ������� �����. ������ ��������� �������� ����� ���������, ����� �� ����������� ��� � ����� ���������� �����...";
			link.l1 = "����������, ��������, ���� ��� � ����� �������, ������ ��� ��, ���-�����, ������������ ��������, ������ �������� �� ��������������, � �� � ����� ������� - �� �����, ��� ��� ����� ����� �����. �����-�� �� ����, � ����� ����...";
			link.l1.go = "Tavern_ChurchGenQuest1_Node_4_2_4";
		break;
			
		case "Tavern_ChurchGenQuest1_Node_4_2_4":
			DialogExit();
			AddItems(PChar, "Bible", 1);	// ���� ��������
			items[FindItem("Bible")].Name = "itmname_ChurchGenQuest1Bible";	// ������ ���. ����� �������� �������!
			ChangeItemDescribe("Bible", "itmdescr_ChurchGenQuest1Bible"); // ������ ��������. ����� �������� �������!
			items[FindItem("Bible")].City = XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"); // ����������. ����� �������!
			AddMoneyToCharacter(PChar, -sti(PChar.GenQuest.ChurchQuest_1.MoneyToBarmen));
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.NeedToDialogWithBarmen");
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "9");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Acc"));
			PChar.GenQuest.ChurchQuest_1.Complete = true; // ����� ��������
			SetFunctionTimerCondition("Church_GenQuest1_DeleteCapitan", 0, 0, 2, false);
		break;

		//���
		case "Seek_Carlos":
		if (pchar.questTemp.Headhunter.Chance == 1)
		{
			dialog.text = "��! ��� �� ���-�� �����, � �������! � ��� ����� ����� ���� �����. �������, �� ������ ���� ���.";
		}
		else
		{
			dialog.text = "��... ��� �� � ���� � ��� �����. � ������ ���� - � �������, ����� ��, ���������.";
		}
		link.l1 = "�������! �� ��� ������� �����!";
		link.l1.go = "exit";
		pchar.questTemp.Headhunter = "hunt_carlos_fight";
		break;
		//���

		//*************************** ����� "������������� ������ "�����"" **********************
		case "Andre_Abel_Quest_TavernOwner_Dialog_1":
			dialog.text = "��, ������� " + GetFullName(pchar) + "! ����� ����� ���� ��� ��� �����. ������ ��������� ��� ����� � ����� � �������... ��, ��� ����! ����� �������� ��� ������� - ������, �������������, ������� ������ �� �������, � ����� �� ����������. � ���, ���� � �� - ����� ������! ��-��-��...";
			link.l1 = "���!.. ������ �������� � ����� �� ������"+ GetSexPhrase("","�") +". �������� ���� �������, �������� ����...";
			link.l1.go = "Andre_Abel_Quest_TavernOwner_Dialog_2";
		break;
			
		case "Andre_Abel_Quest_TavernOwner_Dialog_2":
			DialogExit();
			AddQuestRecord("Andre_Abel_Quest", "13");
			AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","�"));
			CloseQuestheader("Andre_Abel_Quest");
			DeleteAttribute(pchar,"QuestTemp.AndreAbelQuest");
			DeleteAttribute(PChar, "QuestTemp.Andre_Abel_Quest_PortPax_TavernOwner_Speek");
		break;
		
		//Jason --> ��������� ����������� ���
		case "Device_Tavern":
			dialog.text = "��, "+pchar.GenQuest.Device.Shipyarder.Type+"? ������� �����... ���� ��� ��� �� ���� ����� - ������� ���� �� �����, ������ ��������� � ����� �� �����.";
			link.l1 = "��, ��� ���������������� ����������, "+pchar.GenQuest.Device.Shipyarder.Describe+". ����� ������ ��������� ���� �� ���������?";
			link.l1.go = "Device_Trader_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_Trader_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) == 6)
			{
				dialog.text = "��... ��, �������� ��� ����� ���� ���� �������� ���. ������ �� �� ����� �� ������, � ������ ������� �������� �� �������. � ��� ������� - ��� ��� ��������� �� � ����.";
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
		case "Sunplace_Tavern":
			if (makeint(environment.time) > 12.0 && makeint(environment.time) < 17.0)//� ��������
			{
				dialog.text = ""+pchar.GenQuest.Sunplace.Trader.Enemyname+"? �� ������� ��� � ����, � ������ ����� ������ ���� � ������ ���������� - ������ ���������. ������� � �������, ��� �� ��� ��������� ���������.";
				link.l1 = "�������! �� ��� ������� �����!";
				link.l1.go = "Sunplace_Tavern_1";
			}
			else//���� �� �������
			{
				dialog.text = ""+pchar.GenQuest.Sunplace.Trader.Enemyname+"? �� ������� � ������� ���� ����� � ���� �� ����� ������� �� ������� ��������. ����� �� ������, �� ������ � �����-������ ����� ����� � ���������� � �������� ��������. ��� ��� ���� �� ��� ����� - ��� ������� ��� � ����, ��� ���������, ���� �������� ����� ����-������...";
				link.l1 = "�������! ����� �, �������, �� ���� - ��� ����� ��� ��������� � ����. ����� �������!";
				link.l1.go = "Sunplace_Tavern_2";
			}
		break;
		
		case "Sunplace_Tavern_1"://�������
			pchar.quest.Sunplace_Store.win_condition.l1 = "location";
			pchar.quest.Sunplace_Store.win_condition.l1.location = pchar.GenQuest.Sunplace.Trader.CityT + "_store";
			pchar.quest.Sunplace_Store.function = "Sunplace_CreateTrader";
			AddQuestRecord("Sunplace", "6");
			AddQuestUserData("Sunplace", "sName", pchar.GenQuest.Sunplace.Trader.Enemyname);
			AddQuestUserData("Sunplace", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.CityT+"Gen"));
			DialogExit();
			pchar.GenQuest.Sunplace.Trader = "hunt";
		break;
		
		case "Sunplace_Tavern_2"://�������
			pchar.GenQuest.Sunplace.Trader.IslandID = GetCharacterCurrentIslandId(npchar);
			pchar.GenQuest.Sunplace.Trader.EnemyNation = npchar.nation;
			pchar.quest.Sunplace_Sea.win_condition.l1 = "location";
			pchar.quest.Sunplace_Sea.win_condition.l1.location = pchar.GenQuest.Sunplace.Trader.IslandID;
			pchar.quest.Sunplace_Sea.function = "Sunplace_CreateTraderLugger";
			AddQuestRecord("Sunplace", "7");
			AddQuestUserData("Sunplace", "sName", pchar.GenQuest.Sunplace.Trader.Enemyname);
			AddQuestUserData("Sunplace", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Sunplace.Trader.CityT+"Gen"));
			DialogExit();
			pchar.GenQuest.Sunplace.Trader = "hunt";
		break;
		// <-- ��������� ����� ��� �������	
		
		// Jason --> ����������� ������
		case "HWICHollJacob_Tavern":
			dialog.text = "��-�-�... �� ���� ��� �����? �� ��� ����� ���� ����. ����� ������ ���� �������. ���������� ������, � �������, �� ���.";
			link.l1 = "�-�, �������. �����, �����.";
			link.l1.go = "exit";
			LocatorReloadEnterDisable(pchar.questTemp.HWIC.Holl.JacobCity+"_tavern", "reload2_back", false);
			pchar.questTemp.HWIC.Holl = "JacobInRoom";
			AddDialogExitQuestFunction("Create_JacobVanBerg");
		break;
		
		case "HWICSelfFernando_Tavern":
			if (NPChar.location == pchar.questTemp.HWIC.Self.SpainCity +"_tavern")
			{
				if (makeint(environment.time) > 10.0 && makeint(environment.time) < 18.0)//�� �����
				{
					dialog.text = "��, � ���� ����� ������������ ���������. �� ������ ���� ���-�� � ������ - � ������� �����, ��� �� �������� ���� ���� �������.";
					link.l1 = "�������! ������� �� ������!";
					link.l1.go = "Fernando_Land";
				}
				else //� ����
				{
					dialog.text = "��, �� ������ � ����� ������. ������, ������, ��� ��� - �� ����� � ���� �� ����� ����������. �����, �� ������ ���-�� ��������, � ����� ������ �������.";
					link.l1 = "�������! �� ��� ������� �����!";
					link.l1.go = "Fernando_Sea";
				}
				pchar.questTemp.HWIC.Self = "KillFernando";
			}
			else
			{
				dialog.text = "�������� ��������? ������� ����� � �����. ���, � ������ �� ���� �� ���� ��������.";
				link.l1 = "�������. ���� ������ ������...";
				link.l1.go = "exit";
			}
			npchar.quest.HWICTalked = "true";
		break;
		
		case "Fernando_Land":
			pchar.quest.HWIC_Fernando.win_condition.l1 = "location";
			pchar.quest.HWIC_Fernando.win_condition.l1.location = pchar.questTemp.HWIC.Self.SpainCity +"_town";
			pchar.quest.HWIC_Fernando.function = "CreateFernandoOnLand";
			AddQuestRecord("Holl_Gambit", "3-2");
			DialogExit();
		break;
		
		case "Fernando_Sea":
			pchar.questTemp.HWIC.Self.FernandoIslandID = GetCharacterCurrentIslandId(npchar);
			pchar.quest.HWIC_Fernando.win_condition.l1 = "location";
			pchar.quest.HWIC_Fernando.win_condition.l1.location = pchar.questTemp.HWIC.Self.FernandoIslandID;
			pchar.quest.HWIC_Fernando.function = "CreateFernandoOnSea";
			AddQuestRecord("Holl_Gambit", "3-3");
			DialogExit();
		break;
		//<-- ����������� ������
		
		//Jason --> ����� �� �����������
		case "Race_Advantage":
			dialog.text = "��, �������. � ��� � ����� � ����� ������. ���, �������� ���� ������.";
			link.l1 = "�������, " + npchar.name + ".";
			link.l1.go = "Race_Advantage_1";
		break;
		
		case "Race_Advantage_1":
			DialogExit();
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Racing.Go.Money)*2);
			AddQuestRecord("Racing", "4");
			AddQuestUserData("Racing", "sStartCity", XI_ConvertString("Colony"+pchar.GenQuest.Racing.Go.StartCity+"Gen"));
			CloseQuestHeader("Racing");
			DeleteAttribute(pchar, "GenQuest.Racing.Go");
		break;
		//<-- ����� �� �����������
		
		//Jason --> ������ ����������
		case "Marginpassenger":
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger.lose"))
			{
				dialog.text = "�-�, ������, ��� "+pchar.GenQuest.Marginpassenger.q2Name+" �� ����� ��� "+LinkRandPhrase("�����","��� ������","��� ������")+" ���� �����. "+LinkRandPhrase("������������� ��������� �� ���������","�������� �� ���������� ��������, �������, ��� ������ �����������","���������� �� �����")+". ����� ��� �����, �����, �������, ��� ����...";
				link.l1 = "��� ��� ��!.. � ��� �� ��� ������ � ���... ���, ������? �����, ������� �� ����������. �����, " + npchar.name + ".";
				link.l1.go = "Marginpassenger_1";
			}
			else
			{
				dialog.text = ""+pchar.GenQuest.Marginpassenger.q2Name+"? �� ������ ���� ���-�� � ������. ������� �� ������. ������ ������ � ����, ��� ������ ���� �� ���������� ��� �� �������� � ���������� �����������, �� � ����� ������ ���������� � ���� ����.";
				link.l1 = "�������! ����� ������...";
				link.l1.go = "Marginpassenger_2";
			}
		break;
		
		case "Marginpassenger_1":
			DialogExit();
			AddQuestRecord("Marginpassenger", "7");
			AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
			AddQuestUserData("Marginpassenger", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.City));
			pchar.GenQuest.Marginpassenger = "cabin";
		break;
		
		case "Marginpassenger_2":
			DialogExit();
			AddQuestRecord("Marginpassenger", "8");
			AddQuestUserData("Marginpassenger", "sName2", pchar.GenQuest.Marginpassenger.q2Name);
			pchar.GenQuest.Marginpassenger = "street";
		break;
		//<-- ������ ����������
		
		//Jason --> ����� ���������
		case "FindFugitiveTav":
			if (NPChar.city == pchar.GenQuest.FindFugitive.City && sti(pchar.GenQuest.FindFugitive.Chance) == 0)
			{
				dialog.text = NPCStringReactionRepeat("������, ���� ���� ������ �� ������. "+pchar.GenQuest.FindFugitive.Name+" ������������� ������� ������ � ��� �������. ��� ��� �� ������ ����, �� ����� ��������� ��� ����.", "�� ��� ��������� ���� �� ���� ��������, � � ���� ��� ���������!", "�� ���, �����������, ��� �� ����� ���� �����? ������ ��� ����������� ���� � �� ��!", "��, � ��� ������ ����� ������ ��������� ����...", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������, �������, �� ��� ����� �����!", "��, ��, ������.", "����, �� ��������. � ������ �����.", "�� �� �� ������ - ���� ���-��...", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("FindFugitiveTav_1", "exit", "", "", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = NPCStringReactionRepeat("���, ��������, ������� ����� ��� ���. ������ � ���� ���, �����, ��� � ������ ��� ������...", "�� ��� ��������� ���� �� ���� ��������, � � ���� ������: �� ����!", "�� ���, �����������, ��� �� ����� ���� �����? ������ ��� ����������� ���� � �� ��!", "��, � ��� ������ ����� ������ ��������� ����...", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("�������. ��, � �� ��� �������.", "��, ��, ������.", "����, �� ��������. � ������ �����.", "�� �� �� ������ - ���� ���-��...", npchar, Dialog.CurrentNode); 
				link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);	
			}
		break;
		
		case "FindFugitiveTav_1":
			DialogExit();
			AddQuestRecord("MayorsQuestsList", "12-1");
			sld = characterFromId("Fugitive");
			LAi_SetWarriorType(sld);
			LAi_warrior_DialogEnable(sld, true);
			sld.dialog.currentnode = "Fugitive_city";
			LAi_SetLoginTime(sld, 11.0, 18.0);
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.FindFugitive.City+"_town", "goto", "goto"+(rand(9)+1));
		break;
		//<-- ����� ���������
		
		//--> ����� ��������
		case "Sharlie_crew":
			dialog.text = "� ���������, � ������ ������ � ����� �� ���� ��� ������ - ����, ������� � ����, � ��� �� ������ ����� �� ������. �� � ��� ��� ����� - ���������� ��� � ���� �������, ������� ������ ��� ��� �� ������ ������ ��� - �� �� ������ ��������� �� ����� � ������ ����������� �����. ��������, ��� ���������� ����� �� ���� �����.";
			link.l1 = "������, � ��� � ������. �������!";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "sailor";
			//������ �������
			sld = GetCharacter(NPC_GenerateCharacter("SharlieSailor" , "citiz_31", "man", "man", 10, FRANCE, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 10, 20, 20, "blade_05","", "", 10);
			sld.Dialog.Filename = "Quest\Sharlie\OtherNPC.c";
			sld.dialog.currentnode = "Sharlie_sailor";
			sld.greeting = "town_sailor";
			LAi_SetSitType(sld);
			LAi_SetImmortal(sld, true);
			FreeSitLocator("FortFrance_tavern", "sit5");
			ChangeCharacterAddressGroup(sld, "FortFrance_tavern", "sit", "sit5");
		break;
		
		case "Sharlie_skiper":
			dialog.text = "������ ����������� �� ���� ����������, ��������. ������ � ���� � ������� �� ��������� �� ������ ����������� � ���������. �������� ������������ � ����� - �����, ���-�� �� ����� ��� � ��������� ����.";
			link.l1 = "����. �����, �����, ��������� � ������.";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "findskiper";
			//�������� ���������
			sld = GetCharacter(NPC_GenerateCharacter("SharlieSkiperTalker", "citiz_"+(rand(19)+21), "man", "man", 10, FRANCE, -1, true, "marginal"));
			FantomMakeCoolFighter(sld, 10, 20, 20, RandPhraseSimple("blade_04","blade_06"), "", "", 10);
			sld.Dialog.Filename = "Quest\Sharlie\OtherNPC.c";
			sld.dialog.currentnode = "skipertalker";
			sld.greeting = "marginal";
			LAi_SetWarriorType(sld);
			LAi_SetImmortal(sld, true);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "FortFrance_town", "patrol", "patrol"+(rand(13)+1));
			LAi_SetLoginTime(sld, 6.0, 21.99);
		break;
		//<-- ����� ��������

		case "Pirates_1":
			dialog.text = "����� ���, ������������"+ GetSexPhrase(""," � ����") +" �����, ������� ���������! ������ �� ������� ������ �������... �� �� �������, � ���� �����, ��� ����������� ������� - ��� ������. �����, �������?\n������-��, ��� ��� - ������� �'�����, ����.. ���� �� ��� ��� ��� �� ������. ����� ����� ��� ������������ ��������, ��-��. �� �� �����.";
			link.l1 = "��������... �������, ����������. �� - ��� ����� �����, ��� ���������� � ����������� ������� � ����� ���� ��� �����! ������ � ��� ����! ��� ��� �������! � � ������"+ GetSexPhrase("","�") +", ��� �������-�� ����� ���������� �������� �������� �� ��������� �� ������ ������!";
			link.l1.go = "Pirates_2";
		break;
		case "Pirates_2":
			dialog.text = "�������-�� �� ������... �����"+ GetSexPhrase("�","���") +". ��� ����� ������� � ������ ����� ����������. ���� ���������, � ��� � ������.";
			link.l1 = "��, �������, �� �����. ������� ������ ��������� � �������� � �����. ";
			link.l1.go = "meeting";
		break;
		
		case "Charles_1":
			dialog.text = "�� � ���������, ��� �� ������. ���� ����... ��, ����������� ������� ��������� �������, ������� ��������� �������, ��� � �������� ��������� ��� �� ������. �� � ������ �� ���� �����, � ����� ����, ��-��-��...";
			link.l1 = "��, ����-�� �� �� �������������... �����, �� ���� ���������������. �������� � �����.";
			link.l1.go = "meeting";
		break;
		
		case "Portobello_1":
			dialog.text = "��-��-��, ��� ��� � ����, " + GetAddress_Form(NPChar) + "! ������ ���� �������. � �������� ������������ ���� ����� ��� �� ����������!";
			link.l1 = "� ��� ��� ���������� �������, ��� �� �� � ����� � ��������. � ��� �� ����� ������� � ������ ����-�����. � ��, ��� �� ����� �� ���������, ������������ ���� ������...";
			link.l1.go = "Portobello_2";
		break;
		
		case "Portobello_2":
			dialog.text = "�-�-�... �� ����� �� ���� �������� ��� ������, "+ GetSexPhrase("��������","�������") +". ������� ��� ���... �������. ��, � ������� ���� ����� ������� �� �������, ��-��.";
			link.l1 = "�����, " + npchar.name + ", ���������, ������ �������� � �����.";
			link.l1.go = "meeting";
		break;

		// Addon 2016-1 Jason ��������� �������
		case "mtraxx_tortuga":
			sld = characterFromId("Tortuga_waitress");
            dialog.text = "��� ������, �����!.. ������ ����������� ����! � ����� � ������� ��� ������ �������. "+sld.name+"! ������ � ������ �������, ������!.. � ��� 1000 ����, �����.";
			link.l1 = "�����!..";
			link.l1.go = "mtraxx_tortuga_1";
		break;
		
		case "mtraxx_tortuga_1":
			AddMoneyToCharacter(pchar, -1000);
            DialogExit();
			pchar.questTemp.Mtraxx.Retribution = "room";
			pchar.quest.mtraxx_retribution_room.win_condition.l1 = "locator";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.location = "Tortuga_tavern";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.locator_group = "reload";
			pchar.quest.mtraxx_retribution_room.win_condition.l1.locator = "reload2_back";
			pchar.quest.mtraxx_retribution_room.function = "Mtraxx_RetributionToRoom";
		break;

		//������������ �����
		case "MCTavern":
			dialog.text = "���, ���! ��� �������, ���������, �������, �� � ������ ���������\n�������, �� "+ GetSexPhrase("������ �������","�������� �������") +", ������, �������� ���-������! ���� ���� �������� ���, � �����... � ����� �����������, ��� �����!";
			link.l1 = "� �� ����, ��� �� ��� ������ ������ � �� ��� ��, ������� �� ������. �����, �������� � ����� �����������.";
			link.l1.go = "exit";
			LAi_group_Delete("EnemyFight");
			pchar.questTemp.MC = "toCaracasWervolf";
			DeleteAttribute(&locations[reload_location_index], "reload.l2.disable");
			sld = GetCharacter(NPC_GenerateCharacter("CaracasWervolf", "trader_14", "man", "man", 10, PIRATE, -1, true, "quest"));
			sld.dialog.filename = "Gothic_Quest\MagicCity.c";
			sld.dialog.currentnode = "CaracasWervolf";  
			sld.location	= "Caracas_tavern_upstairs";
			sld.location.group = "goto";
			sld.location.locator = "goto1";
			sld.BreakTmplAndFight = true;
			sld.reactionOnFightModeOn = true;
			LAi_SetActorType(sld);
			LAi_ActorWaitDialog(sld, pchar);
			LAi_group_MoveCharacter(sld, "EnemyFight");	
		break;

		case "MCCaracasAfter":
			dialog.text = "����� ����, � ��������� �� ����! ��� �������� ������� �����, ���� ����������� �� ����� ���� ��� �������! ���� �������� ������� ���� - �������� �����...";
			link.l1 = "� ���������, ��� � �����������?";
			link.l1.go = "MCCaracasAfter_1";
		break;
		case "MCCaracasAfter_1":
			dialog.text = "�, � ���������-��? �� ������ ��� ���������, � ��� ��. �� ����� ��� �� ������ �� �����"+ GetSexPhrase("","�") +", ��� ���� �� ������ �"+ GetSexPhrase("��","��") +"? ��� ��� �� � ��������, ��������� ����...";
			link.l1 = "��, � ������ �� ������, ��� � ��������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("MC_endCaracas");
		break;

		
	}
}

string findTraderCity(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (colonies[n].id != "Panama" && colonies[n].nation != "none" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� �� ���� ������
		{
			if (nation == RELATION_ENEMY || sti(npchar.nation) == PIRATE)
			{
				storeArray[howStore] = n;
				howStore++;
			}
		}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}

string findPassangerCity(ref NPChar)
{
	int n, nation;
    int storeArray[MAX_COLONIES];
    int howStore = 0;

	for(n=0; n<MAX_COLONIES; n++)
	{
		nation = GetNationRelation(sti(npchar.nation), sti(colonies[n].nation));
		if (colonies[n].nation != "none" && colonies[n].id != "Panama" && GetIslandByCityName(npchar.city) != colonies[n].islandLable) //�� �� ���� ������
		{
			if (nation == RELATION_ENEMY || sti(npchar.nation) == PIRATE)
			{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	}
	if (howStore == 0) return "none";
	nation = storeArray[cRand(howStore-1)];
	return colonies[nation].id;
}
