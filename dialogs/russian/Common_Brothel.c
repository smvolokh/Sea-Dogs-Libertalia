void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	string sTemp,sTemp1, str, str1;
	int	s1,s2,s3,s4,s5,p1, iColony, crewWhoreCost, charWhoreCost = 0;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
		
    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Brothel\" + NPChar.City + "_Brothel.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	crewWhoreCost = 50 + 7 * MOD_SKILL_ENEMY_RATE - drand(40);
	charWhoreCost = 2460 + sti(pchar.rank) * 40;
	
	switch(Dialog.CurrentNode)
	{
		// ============= ������� ������� =============
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase(""+ GetSexPhrase("�����-�������, ����� �������?! �� ����� �������� ��������� �������, � �� � ������� ���������!","��� �� �� ������... �� ����� �������� ��������� �������!") +"", "��� ��������� ������ ����� �� ������ � ������� ����. � �� �������, ��������� ���� � ����� ������...", "������� ��������� �� ����� ���������, ���� ����� ������ ������!"), 
					LinkRandPhrase(""+ GetSexPhrase("�������� ������ ����������� �� ���� ������� - � � ���� ������ ����� �����!","�������� ������, ��������!") +"", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ����� ���������! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("��������� �� �����, ����...", "��������, �� �� ���� �����..."));
				link.l1.go = "exit";
				break;
			}
			//Jason --> ���������� ����������
			if (!CheckAttribute(pchar, "GenQuest.Badboy") && !CheckAttribute(npchar, "quest.Badboy") && makeint(environment.time) > 15.0 && makeint(environment.time) < 21.0 && sti(pchar.questTemp.HorseQty) > 4)
			{
				dialog.text = "�� ����� ������ �������. �, ����� �����, ��������� ���� ��������. � �� ������ ��������� ��� ������� ����� ��������� ������.";
				link.l5 = "��... �� �����, � �������. � ��� ��� ��������� ��� ������?";
				link.l5.go = "Badboy";
				link.l8 = "������, �� � ������ �����.";
				link.l8.go = "exit";
				npchar.quest.Badboy = "true";
				break;
			}
			
			if (CheckAttribute(pchar, "GenQuest.Badboy.Complete") || CheckAttribute(pchar, "GenQuest.Badboy.Continue"))
			{
				if (npchar.City == pchar.GenQuest.Badboy.Brothel.City)
				{
					dialog.text = "�, �� ��� ���������! �� ���, ��� ������� �������� ����, ����� "+pchar.GenQuest.Badboy.Brothel.Name+" ������� ���� ������� � �����?";
					link.l5 = "��. ����� �� ���� �� ������.";
					link.l5.go = "Badboy_complete";
				break;
				}
			}
			// <-- ���������� ����������
			
			//--> Jason ����������
			if (CheckAttribute(pchar, "questTemp.HWIC.Detector"))
			{
				bool bOk = (pchar.questTemp.HWIC.Detector == "holl_win") || (pchar.questTemp.HWIC.Detector == "eng_win") || (pchar.questTemp.HWIC.Detector == "self_win");
				if (!CheckAttribute(pchar, "questTemp.Portugal") && bOk && !CheckAttribute(npchar, "quest.Portugal") && npchar.location == "Marigo_SecBrRoom" && makeint(environment.time) > 6.0 && makeint(environment.time) < 22.0)
				{
					dialog.text = "�������, ���� � ��������� ��� �� ����� ���������?";
					link.l5 = "��� ���, �����, ��� ��� ������... � � ����� �������!";
					link.l5.go = "Portugal";
					link.l8 = "������, �� � ������ �����.";
					link.l8.go = "exit";
					npchar.quest.Portugal = "true";
					break;
				}
			}
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "HostressMoney" && npchar.location == "Marigo_SecBrRoom")
			{
				dialog.text = "�� �������� � �����, ������ �������?";
				if (sti(pchar.money) >= 10000)
				{
					link.l1 = "����� ����, ����� � ��� ���� ������. ��� ����������� ����� �������������...";
					link.l1.go = "Portugal_3";
				}
				else
				{
					link.l1 = "��, � ������� ���� �������.";
					link.l1.go = "Portugal_exit";
				}
				break;
			}
			//<--����������

			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "brothel" && npchar.location == "Tortuga_SecBrRoom")
			{
				dialog.text = "�, ��� � ��� ���������! ���������� ������ ����� "+pchar.name+" ����������� ��������!";
				link.l1 = RandSwear()+"������, �������. � ����� �� ������� �� ������� �������.";
				link.l1.go = "mtraxx_R";
				break;
			}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "brothel_repeat" && npchar.location == "Tortuga_SecBrRoom")
			{
				dialog.text = "�� ��� ����� � ������������� ������, �������� ������?";
				if (sti(pchar.money) >= 31000)
				{
					link.l1 = "�������! ����� "+pchar.name+" ���� �� ����� �� �������, � ������� �� ����-���� �������� ����� ����, ��-��-��!";
					link.l1.go = "mtraxx_R2";
				}
				else
				{
					link.l1 = "�����... ��� ����������, ��� � ������ � ���� ���� ���������... ������ ������� � ��������!";
					link.l1.go = "exit";
				}
				break;
			}
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = RandPhraseSimple(TimeGreeting() + ". ����� ���������� � ��� ����������. ���� ����� " + npchar.name + ", � ����� ������� ����. "+ GetSexPhrase("��� ���� ���� �������, " + GetAddress_Form(NPChar) + "?","���������, ������� �������� ������ ��� �����, " + GetAddress_Form(NPChar) + ", �� ���� ��������: �� ��������� ������ �� ������ ��������.") +"",
				TimeGreeting() + ". ����������� ���, "+ GetSexPhrase("����������","�������") +", � ���� �������� ���������. ��������� ������������, � "+ NPChar.Name + " - ��������� ����� ������ ��������� ������ ������. "+ GetSexPhrase("��� � ���� ���� ��� �������?","���� ��� ������ � ��� ���� ���-��� ����...") +"");
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = RandPhraseSimple(TimeGreeting() + ". ��� � ���� ��� ������, " + GetAddress_Form(NPChar) + "?",
				TimeGreeting() + ". ��� � ���� ��� ��� �������, " + GetAddress_Form(NPChar) + "?");
			}
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Gigolo"))//�� ���� ����� �������
			{
				if (!CheckAttribute(pchar, "GenQuest.BrothelLock"))// ��� ������� �� ���� 280313
				{
					link.l2 = npchar.name + ", � ���� �������� ����� � ����� �� ����� �������.";
					link.l2.go = "Hostess_1";
				}
			}
			if (!CheckAttribute(pchar, "questTemp.Sharlie.Lock")) // �� ���� ����� �����
			{
				link.l3 = "����� � �� �������"+ GetSexPhrase("","�") +" ����� ������. ����� ������� ������� ����� �� �������?";
				link.l3.go = "ForCrew";
			}
			link.l4 = "� ���� ���� ������.";
			if (CheckCharacterItem(pchar, "CaptainBook") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakBrothelMadam"))
			{
				if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
				{
					link.l4.go = "ShipLetters_1";// ���������  "��������� ���������"
				}
				else
				{
					link.l4.go = "quests";
				}	
			}
			else
			{
				link.l4.go = "quests";//(���������� � ���� ������)
			}	
			//-->> ����� ������ ������ ����
			if (pchar.questTemp.different == "TakeMayorsRing" && pchar.questTemp.different.TakeMayorsRing.city == npchar.city && GetNpcQuestPastDayWOInit(npchar, "TakeMayorsRing") > 7)
			{
				link.l5 = "��������, " + npchar.name + ", � ��� ������ �����������. �� ��� ����� � ���� �������, � ������� ���.";
				link.l5.go = "TakeMayorsRing_H1";
				SaveCurrentNpcQuestDateParam(npchar, "TakeMayorsRing");
			}
			//<<-- ����� ������ ������ ����
			link.l9 = "�����. � ��� �����.";
			link.l9.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "ShipLetters_1":
				pchar.questTemp.different.GiveShipLetters.speakBrothelMadam = true;
				dialog.text = RandPhraseSimple("���� �� ������, ���������?","������ ��� �����������, �������.");
				link.l1 = "��������, " + npchar.name + ", � ���������"+ GetSexPhrase("","�") +" ��� ������ � ��������� ���� ������ ���������...";
				link.l1.go = "ShipLetters_2";				
		break;
		
		case "ShipLetters_2":
			if(sti(pchar.questTemp.different.GiveShipLetters.variant) == 0)
			{
				dialog.text = "�����-�� ���������! ��... �����-�� ����������� ������� ������� ���������? � �����, ����� ������� ����� �������� ���������� �����.";
				link.l1 = "��������, �������� ...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�����-�� ���������! �! ���� �� �����, ��� ����������� ����� ���������� ������� � ���������� ���������� ������ ������. � ���� ���� �������� ���������";
				link.l1	= "�������, ��� ...";
				link.l1.go = "exit";
				link.l2 = "������������! ������ ���"+ GetSexPhrase("","�") +" ������ ���������� �������� � ���������� ���������.";
				link.l2.go = "ShipLetters_3";										
			}	
		break;
		
		case "ShipLetters_3":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "2");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters"); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
        case "Hostess_1":
			if (!CheckAttribute(npchar, "quest.selected"))
			{
				if (CheckNPCQuestDate(npchar, "quest.date"))
				{
					dialog.text = ""+ GetSexPhrase("�� ������ ���� �������. ����� ���, �������, �� ��� ���������� ����-�� ��� ���� ��� �����?","�� ��� ��, ��� ������� ������ ������ ����... ������. �� ����������� ����-������, ��� ���� ��� �����?") +"";
					Link.l1 = ""+ GetSexPhrase("���, ��� ����� ����� � ����������, � ��� ��� ����� - ���������. � ���� ��� ��� �����������...","�� �����, ���� �� ���� ���� �����...") +"";
					Link.l1.go = "Hostess_NotChoice";	
					Link.l2 = "��, ���� ����, "+ GetSexPhrase("��� ��� ������������...","� ��� ���� �� ��������...") +"";
					Link.l2.go = "Hostess_Choice";
				}
				else
				{
					dialog.text = "������� � ��� �� ���� ���� ���� �������, ����� ���� � ���� ��� ���� �������. ������� ������, �������� ��� �������!";
					Link.l1 = "��, ����"+ GetSexPhrase(", � ������ ����� �� ����","") +"... �� �� �����.";
					Link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "��, �� ��� �������"+ GetSexPhrase("","�") +" �������. ��� ��� ������� �� ��������, ��� �������, � �� �������� ���� �� ��������.";
				Link.l1 = "������, ��� ���.";
				Link.l1.go = "exit";	
			}
		break;

        case "Hostess_NotChoice":
			sld = GetFreeHorseRef(npchar.city);
			location = &locations[FindLocation(npchar.city + "_Brothel")];
			if (sld.id == "none" || GetNpcQuestPastDayParam(location, "Brothel_date") > 98)
			{
				dialog.text = "������ � ���� ��� ��������� �������, ���� ����� ����� ����� ���� ����� ���� ����.";
				Link.l1 = "������, ��� �������.";
				Link.l1.go = "exit";	
			}
			else
			{
				dialog.text = ""+ GetSexPhrase("�� ���, �������, �����������!","� ���� ��� ��� ������, ������ �� �����������.") +" ���� ���������� ���������� ������� �� ����� " + GetFullName(sld) + ", ��� ������ ��������. ������ ��� ������������ ����� " + FindRussianMoneyString(sti(sld.quest.price) + charWhoreCost) + ". ������"+ GetSexPhrase("��","��") +"?";
				Link.l1 = "���, �������, ��������. ����������...";
				Link.l1.go = "exit";
				if (sti(pchar.money) >= (sti(sld.quest.price) + charWhoreCost))
				{
					Link.l2 = "�������, ������"+ GetSexPhrase("��","��") +", ����� ����� ���� �������?!";
					Link.l2.go = "Hostess_NotChoice_agree";	
					npchar.quest.choiceIdx = sld.index;
				}
				else
				{
					Link.l1 = "����, ��� � ���� ������ ����� �����...";
					Link.l1.go = "exit";
				}
			}
		break;
		
        case "Hostess_NotChoice_agree":
			sld = &characters[sti(npchar.quest.choiceIdx)];
			if (sti(pchar.money) >= (sti(sld.quest.price) + charWhoreCost))
			{
				dialog.text = "�������, �����"+ GetSexPhrase("��","���") +". " + sld.name + " ����� ����� ���� � ������� ��� ��������� �� ������ �����.";
				Link.l1 = ""+ GetSexPhrase("���, �� � �����","��, � ��������") +"...";
				Link.l1.go = "exit";
				AddMoneyToCharacter(pchar, -(sti(sld.quest.price) + charWhoreCost));
				sld.dialog.currentnode = "Horse_ReadyFack";			
				//--> ������ �� �������, ����� �� ����� �����
				str = npchar.city;
				pchar.quest.(str).win_condition.l1            = "Timer";
				pchar.quest.(str).win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
				pchar.quest.(str).win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
				pchar.quest.(str).win_condition.l1.date.year  = GetAddingDataYear(0, 0, 1);
				pchar.quest.(str).win_condition               = "Brothel_checkVisitTime";	
				pchar.quest.(str).HorseId = sld.id;
				pchar.quest.(str).locator = sld.location.locator;
				//<-- ������ �� �������, ����� �� ����� �����
				ChangeCharacterAddressGroup(sld, npchar.city + "_Brothel_room", "goto", "goto"+(rand(2)+1));
				LocatorReloadEnterDisable(npchar.city + "_Brothel", "reload2_back", false); //��������� �������
				npchar.quest.selected = true; //���� ���� ����� � �������
				SetNPCQuestDate(npchar, "quest.date"); //���� ������ �������
				for(int n=0; n<MAX_CHARACTERS; n++)
				{
					makeref(sld, Characters[n]);
					if (sld.location == npchar.city+"_Brothel" && CheckAttribute(sld, "CityType") && sld.CityType == "horse")
					{
						sld.dialog.currentnode = "Horse_4";
					}
				}
				
				// ��������� ��������� �����
				if ((rand(4) == 1) && (pchar.questTemp.different == "free") && (!CheckCharacterItem(pchar, "CaptainBook")) && GetNpcQuestPastDayWOInit(npchar, "questShipLetters") > 10) 
				{					
					pchar.questTemp.different = "GiveShipLetters";
					pchar.questTemp.different.GiveShipLetters = "toBrothel";
					pchar.questTemp.different.GiveShipLetters.Id = GetFullName(npchar);
					pchar.questTemp.different.GiveShipLetters.city = npchar.city;	
					pchar.questTemp.different.GiveShipLetters.variant = rand(2);
					p1 = rand(20 - MOD_SKILL_ENEMY_RATE) + 1; // ���� ���� �� ���� ����
					s1 = rand(80 - pchar.rank - p1) * 50 + rand(100);
					s2 = s1 * 2;
					s3 = s1 * rand(GetCharacterSPECIAL(pchar, "Luck")) + s1;
					s4 = s2 + s3;
					s5 = s4 * GetCharacterSPECIAL(pchar, "Charisma");
					pchar.questTemp.different.GiveShipLetters.price1 = s1;
					pchar.questTemp.different.GiveShipLetters.price2 = s2;
					pchar.questTemp.different.GiveShipLetters.price3 = s3;
					pchar.questTemp.different.GiveShipLetters.price4 = s4;
					pchar.questTemp.different.GiveShipLetters.price5 = s5;
										
					sld = ItemsFromID("CaptainBook");
					sld.CityName = XI_ConvertString("Colony" + npchar.city + "Gen");
					//����� ������ � ����								
					sTemp = "_Brothel_room";	
					sTemp1 = "_town";					
					sld.shown = true;
					sld.startLocation = pchar.questTemp.different.GiveShipLetters.city + sTemp;
					sld.startLocator = "item" + (rand(4)+1);
					sld.endLocation = pchar.questTemp.different.GiveShipLetters.city + sTemp1;
					pchar.questTemp.different.GiveShipLetters.item = true; //���� -  ������ �������� � ������
					Log_QuestInfo("������ ��������� � ������� " + sld.startLocation + ", � �������� " + sld.startLocator + " p1 : " + p1);
					
					pchar.quest.CheckShipLetters.win_condition.l1 = "location";
					pchar.quest.CheckShipLetters.win_condition.l1.location = sld.endLocation;
					pchar.quest.CheckShipLetters.function = "CheckShipLetters";
					
					SetTimerFunction("GiveShipLetters_null", 0, 0, p1); //����������� ���������� �� ���������� 
					SaveCurrentNpcQuestDateParam(npchar, "questShipLetters");					
				}
				// ��������� - "����� ��� ������"
				if((rand(5) == 2) && !CheckAttribute(pchar, "questTemp.ReasonToFast") && GetNpcQuestPastDayWOInit(npchar, "questReasonToFast") > 20 && !CheckAttribute(pchar, "questTemp.Sharlie.Lock")) // Addon-2016
				{
					iColony = FindColony(npchar.city);	
					if( sti(Colonies[iColony].HeroOwn) == false && npchar.city != "Panama" && npchar.city != "Charles")
					{
						pchar.questTemp.ReasonToFast = "Begin";
						pchar.questTemp.ReasonToFast.city = npchar.city;
						sTemp1 = "_town";					
						pchar.quest.CheckReasonToFast.win_condition.l1 = "location";
						pchar.quest.CheckReasonToFast.win_condition.l1.location = npchar.city + sTemp1;
						pchar.quest.CheckReasonToFast.function = "ReasonToFast_CheckHorse";
						SaveCurrentNpcQuestDateParam(npchar, "questReasonToFast");	
					}	
				}				
			}
			else
			{
				dialog.text = "��� �� ���� ������, �� ���� � ���, ��� " + sld.name + " - ������� ���������, ����� " + FindRussianMoneyString(sti(sld.quest.price) + charWhoreCost) + ". � � ����, ��������� � ����, ����� ����� ���. ������� ��� ������������"+ GetSexPhrase(", ������","") +"...";
				Link.l1 = "��, ��� ��� ������...";
				Link.l1.go = "exit";
			}
		break;

        case "Hostess_Choice":
			dialog.text = "� ������ ����, ����� ����� ��������� � ��������� ��������� ������ �������... ������ ��� �� ���.";
			Link.l1.edit = 9;
			Link.l1 = "";
			Link.l1.go = "Hostess_Choice_1";	
		break;
		
        case "Hostess_Choice_1":
			sld = CheckHorsesName(npchar.city, 9);
			if (sld.id == "none")
			{
				dialog.text = "��, �� ����������, � ���� ��� ����� ������� � ���������. ��������, �� ������� ��������� �� ���.";
				Link.l1 = "��, �� � ������ ��� � ��� ������������"+ GetSexPhrase("","�") +".";
				Link.l1.go = "Hostess_Choice_2";				
				Link.l2 = "�������, ��� ����� �������� �� ���. � ����� ���������� � ����� �� ��� ����.";
				Link.l2.go = "exit";	
			}
			else
			{
				dialog.text = GetFullName(sld) + ", �� � ��� ��������?";
				Link.l1 = "���, ������ � ���.";
				Link.l1.go = "Hostess_NotChoice_agree";				
				Link.l2 = "���, �� � ���.";
				Link.l2.go = "Hostess_Choice_2";
				npchar.quest.choiceIdx = sld.index;
			}
		break;
		
        case "Hostess_Choice_2":
			dialog.text = "����� ���� ����� ������� �� ��� ��� ���, �������� � �����, � ��� ���� ����.";
			Link.l1.edit = 9;
			Link.l1 = "";
			Link.l1.go = "Hostess_Choice_1";
			Link.l2 = "�������, ��� ����� �������� �� ���. � ����� ���������� � ����� �� ��� ����.";
			Link.l2.go = "exit";	
		break;
		//==> �������
		case "ForCrew":
			dialog.text = "���... ������ ������� '�������� ���'? � ���� �������� ��������� � ������ �������. ������ � ����, ��� �����, �������� '������', ��������� �������� ��� ��������� �� ����� �������. � ���� " + FindRussianMoneyString(GetCrewQuantity(pchar)*crewWhoreCost) + ".";			
			link.l1 = "������, � ������"+ GetSexPhrase("��","��") +" ��������� ��� ������.";
			link.l1.go = "ForCrew_1";
			link.l2 = "�����, ��� ��������� ���-������...";
			link.l2.go = "exit";
		break;
		
		case "ForCrew_1":
		    if (sti(Pchar.money) >= GetCrewQuantity(pchar)*crewWhoreCost && GetCrewQuantity(pchar)>0)
		    {
		        AddMoneyToCharacter(Pchar, -makeint(GetCrewQuantity(pchar)*crewWhoreCost));
	            AddCrewMorale(Pchar, 15);
				ChangeCharacterComplexReputation(pchar,"authority", 15);
			ChangeOfficersLoyality("good_all", 3);
	            LAi_Fade("", "");
                AddTimeToCurrent(5 + rand(1), rand(30));
			    DialogExit();
		    }
		    else
		    {
		        dialog.text = "���, �������, �� ��� ����, �� ��� �������, ��� ���� ������� ����� ���������� �� �������, � ����� ������ � �� ������.";
			    link.l1 = "�������, ��...";
			    link.l1.go = "exit";
		    }
		break;
		
		case "Woman_FackYou":
			dialog.text = "���"+ GetSexPhrase("��","��") +", �� ���� ��� �����"+ GetSexPhrase("","��") +"?! ���� ��, � ������� ��������"+ GetSexPhrase("�� ���������","�� ��������") +".\n�� � ������ ��� ������ ���� �� ����, ������"+ GetSexPhrase("���","���") +". �������� ���� ��������...";
			link.l1 = "��������, ����...";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;
		
		//������ ������ �����������
		case "TakeMayorsRing_H1":
			dialog.text = "�������� ������ � �� ��������.";
			link.l1 = "� ������� ����?";
			link.l1.go = "TakeMayorsRing_H2";
		break;
		
		case "TakeMayorsRing_H2":
			dialog.text = "������� ����. ���� ������ ���-�� �������� ��� ������, �� ��� ��� �������� ��� �����������. ����� ������ ����������� ��� �� ��������.";
			link.l1 = "�������... � ����� ���-�� ���-���� ����� ��� ����������?";
			link.l1.go = "TakeMayorsRing_H3";
		break;
		
		case "TakeMayorsRing_H3":
			dialog.text = "��� ���� ��. �������� ����������� ��������� ���� ������� ��������, � ������.";
			link.l1 = "�������... ������� ����, " + npchar.name + ".";
			link.l1.go = "exit";
		break;
		
		case "Hostess_inSexRoom":
			dialog.text = "��, ��� � ��...";
			link.l1 = "��� �����, ��� ��������!";
			link.l1.go = "exit";
			pchar.quest.SexWithHostess_null.over = "yes"; //����� ������ �� �� ������
			NextDiag.TempNode = "First time";
			AddDialogExitQuestFunction("SexWithHostess_fack");
			AddCharacterExpToSkill(pchar, "Leadership", 100);
            AddCharacterHealth(pchar, 5);
		break;
		
		// ================================== ������� ������ =======================================
        case "Horse_talk":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("��� ����� ���� �� ���������!", "��� ��������� ������ ����� �� ������! ��� ����� ����...", "������������ - � � ���?! ��� ��, � ������ ���..."), 
					LinkRandPhrase("��������!!", "�����"+ GetSexPhrase("��","��") +" ������, ��� ������! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� ������� � ����� �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("���, ������� ��� ���� �� ��������...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("���, �� � ���� �� ��...", "��������, �� �� ���� �����..."));
				link.l1.go = "exit";
				break;
			}
			dialog.text = NPCStringReactionRepeat("������������, " + GetAddress_Form(NPChar) + ""+ GetSexPhrase("",", ��-��-��..") +". ��� ����� ���������� � ������� ���������, ��� ������ �������� ����� ���.", 
				"��, ��� ����� ��. ��������, �� ��� ����� ������� ������� ��� ������� � ��������. ����� ��� ������ � ���.", 
				"����������, " + GetAddress_Form(NPChar) + ""+ GetSexPhrase(", � ����� �������, ��� �� ��� �� ������ � � ������ �����, � �� ������ � ����������... ���","� ���") +" ��� ����� ��� ������ � ������� ���������.", 
				"��, " + GetAddress_Form(NPChar) + ""+ GetSexPhrase(", ����� �� ��... �����������!",", ��-��-��... ��, ������, ���������.") +" ��� ����� ������ � ������� ��������� ��� ���������� ������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, "+ GetSexPhrase("���������, ","") +"� �����"+ GetSexPhrase("","�") +".", "�-�, ��, �������...",
                      ""+ GetSexPhrase("������ �� �����������, ���������, � ����� � �����, ��� ���!","��-��...") +"", ""+ GetSexPhrase("��� ������, ���-�� �������... ������, �����.","������, ������.") +"", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			Link.l2 = "� ��� ��� ���������?";
			Link.l2.go = "Horse_1";
			Link.l3 = LinkRandPhrase(""+ GetSexPhrase("����, ���������, � ����� ������ ����� �������...","�� ��������� ������ ������������, �������!") +"", ""+ GetSexPhrase("������, � ����� �� ����� ����� �������� �������!","������, � ��������� �� ��������� ����� ����������!") +"", ""+ GetSexPhrase("��, �����, �� ���������� ���������.","��, ������� ��� ��� ���������� �������... � �� ������ ��������!") +"");
			if (!CheckAttribute(npchar, "quest.choice"))
			{
				Link.l3.go = "Horse_2";
			}
			else
			{
				Link.l3.go = "HorseChoice_" + npchar.quest.choice;
			}
			//-->> ����� ������ ������ ����
			if (pchar.questTemp.different == "TakeMayorsRing" && pchar.questTemp.different.TakeMayorsRing.city == npchar.city && GetNpcQuestPastDayWOInit(npchar, "TakeMayorsRing") > 7)
			{
				link.l5 = LinkRandPhrase("������, "+ GetSexPhrase("���������","�������") +", �� �� �������� ����� ������������ ������? ������� ��� ��� ���� �������...", 
					"��������, ��, �������, �� �������� � ����� ��������� ������������ ������?", 
					"��������, "+ GetSexPhrase("���� ���","�������") +", ������� �� ���������� ���� ���, �����������?");
				link.l5.go = "TakeMayorsRing_S1";
				SaveCurrentNpcQuestDateParam(npchar, "TakeMayorsRing");
			}
			//<<-- ����� ������ ������ ����

            //--> ���. �������, �����. ����� � ������� � �������.
 
		if (pchar.questTemp.GothicLee == "SeekBible_toGirl")
                                             {
    			if (npchar.id == "HorseGen_"+FindLocation("FortFrance_Brothel")+"_1")
				{
					if (!CheckAttribute(npchar, "quest.HolLineTalk"))
					{
						dialog.text = "���, ��� �������� ���"+ GetSexPhrase("�� �������� �����","�� ������ �������") +", ����� ���������...";
    					link.l4 = "��������, ��������� ����� ����� � ��� ��� ����� � ��������� ������������...";
    					link.l4.go = "Gothic_3_1";
					}
					else
					{
						dialog.text = "��������"+ GetSexPhrase("","�") +" ������?";
						link.l4 = "��� ���� ������, ������ ���������� ���, ��� ������.";
    					link.l4.go = "Gothic_3_5";
						AddMoneyToCharacter(pchar, -1000);
					}
				}
            }
			//<-- ���. �������, �����. ����� � ������� � �������.

			// Addon 2016-1 Jason ��������� �������
			if (pchar.location == "santodomingo_brothel" && CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_1" && npchar.id == "HorseGen_"+reload_location_index+"_2")
			{
				link.l6 = "������, ��������. � �� ������� �������, ���� �������� ���� �������� ��������...";
				link.l6.go = "mtraxx";
			}
			NextDiag.TempNode = "Horse_talk";
		break;
		
        case "Horse_1":
			dialog.text = "��� � ����� ��������, �� ������ ������ � ��� ������ ����� �����, ��������������� ������ �� �����, ���� ����� ����� � ������ ������� ����. �� ����� " + characters[GetCharacterIndex(npchar.city + "_Hostess")].name + ".";
			Link.l1 = "�������, "+ GetSexPhrase("�����","��������") +", �������.";
			Link.l1.go = "exit";			
		break;
		
        case "Horse_2":
			if (rand(1))
			{
				dialog.text = LinkRandPhrase("��, ���� ���, �� ���� ������� ������� �����! ������, � ������ ��������, ��� ��� ���� �� �������� ����, �� �� ���������...", "�� ������������� ��� ��������? ��� ����� � ����� �������... ��������, � ������ ��������, ��� ��� �� ������ ������� ����."+ GetSexPhrase(" � ������ ���� ���� ����� � ����� �����...","") +"", ""+ GetSexPhrase("��� ���?! ��, �� �����, � ��������, �� ����� ���������� ������� � ���� ����� ����� �����...","��, �������... ��� ���� ������� ��� ������...") +" ������, � �� ������ � ������ ������, ��� ��� � ��������� ���� ������� ����. ������, ��� �� ���������� �����"+ GetSexPhrase("��","���") +"...");
				link.l1 = "���, ������ ���� � �������!";
				Link.l1.go = "Horse_3";		
				Link.l2 = ""+ GetSexPhrase("��-�-��, ��� ��� ������ ���������� ���������� ����","��� ��� ������ ����������") +".";
				Link.l2.go = "exit";
				npchar.quest.choice = 0; //��� �����, �� �� ����� ���������
			}
			else
			{
				dialog.text = LinkRandPhrase(""+ GetSexPhrase("������ ��� � ���� �����, ����� ���? �� ����� ��� ������ ����������. ������� �����!","�� ��� ������ ����� ��� �� ������� - ������������ �� ������!") +"", ""+ GetSexPhrase("�� ���� �����������, ��� ��� ������� ����� �����? ��, ��� ����� ���... ���� ������ ���� - ����� ������� ���������, � �������� ��� �� �����.","�������, �� ��������������� �� ������ �����. ������ ��� - �������...") +"", ""+ GetSexPhrase("��� ���� �������� �������������... ����� - � � ���� �����, �� ������ ��� ����� ������� �����!","�� ����, ��������? ������ ������������ - �����, � �� ��������� ���������!") +"");
				link.l1 = "���, ����� ������!";
				Link.l1.go = "exit";
				npchar.quest.choice = 2; //�� �������
			}
		break;
		
        case "Horse_3":
			dialog.text = characters[GetCharacterIndex(npchar.city + "_Hostess")].name + " ��� ��������� � ����� ��������. ��� � ���"+ GetSexPhrase(", ��� �����,","") +" � ������ ��� ��� - " + npchar.name + ". � ���� ���� �����...";
			Link.l1 = "�������, �����, ����� ����...";
			Link.l1.go = "exit";
			npchar.quest.choice = 1; //��� ���������
			SetNPCQuestDate(npchar, "quest.choice");
		break;
		
        case "Horse_4": 
			dialog.text = NPCStringReactionRepeat("�� ��� �������"+ GetSexPhrase("","�") +" �������, ��� ���� ����, ���������� ������.", 
				"� �� ���� ������� - ���������� � ���.", 
				"������ �����������, ��� ��� �������� - ���������� � ���...", 
				"���������� ��������, �� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��, � ����.", "� �����.",
                      "������ �� ���������, � ��� � �����.", "��, � ��� ��� ��?..", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "Horse_4";
		break;
		
		//===>> ������� �� ������� ������������, ���� ����� ��� ���
        case "HorseChoice_0": 
			if (!CheckAttribute(npchar, "quest.sexHappend"))
			{
				dialog.text = NPCStringReactionRepeat("���-�� � ���� �� �����."+ GetSexPhrase(" �� ����������� �������, �� ����� �� �������� �����. �������� ���...","") +"", 
					"����� �� ����� �������������? ��, ��� � �������, � ��� ��� �����.", 
					"��, � �� ������� ����? ������� �� - ��� � ������� ���������.", 
					"��� ������ ����� ���������� ��������, �� �� �����������, ���"+ GetSexPhrase("��","��") +"...", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��� �����, ������ ��...", "������, � ��� � ������.",
						"��-��, � �����"+ GetSexPhrase("","�") +"...", "��, ������, ��������.", npchar, Dialog.CurrentNode);
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "������� �� ����������. ���� �� ������ ����� ����, �� ��� � ������� ���������. ��� ��� ������...";
				Link.l1 = "�������.";
				Link.l1.go = "exit";
			}
		break;
		
        case "HorseChoice_1": 
			if (!CheckAttribute(npchar, "quest.sexHappend"))
			{
				if (!CheckNPCQuestDate(npchar, "quest.choice"))
				{
					dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("�����, �� ��� ���������. ","") +"�� ��������� ���� ����� �����...", 
						""+ GetSexPhrase("��, ��������, �����, ���","���") +" ����� ������� ��� ���� �����, �� ���� ��� � �� ���� �������...", 
						"��������, ����� �� ���-���� ������� ��� � ��������?..", 
						"��, ���� �� ����, ��� � �������...", "block", 1, npchar, Dialog.CurrentNode);
					link.l1 = HeroStringReactionRepeat("�� �� �� ��� �� �����!", "�����������!",
							"��, �������!", "����, ���� � �������...", npchar, Dialog.CurrentNode);
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "� ���� �����, � �� ��� � �� ����"+ GetSexPhrase("","�") +" ����! �� ���� �������, ��� � � �������� �� �����...";
					Link.l1 = "��, ��� ����������...";
					Link.l1.go = "exit";
					npchar.quest.choice = 0; //��� �����, �� �� ����� ���������
				}
			}
			else
			{
				dialog.text = "��-�, ��� ����� ��, ��"+ GetSexPhrase("� ������� ������","� ������� �������") +"! ���� ���� ����� ����� �, �� ��� � ������� - �� ���������..."+ GetSexPhrase(" ������, � ���� ������, �������, ������ �� ��������� ���������� �� ���� �������� ����������, �� �� ������...","") +"";
				Link.l1 = "������� ���� ������ ����-����, "+ GetSexPhrase("���������","�������") +", � �� ����� � ����� ���������.";
				Link.l1.go = "exit";
				Link.l2 = "��� ����� �������, ��� �� ���� ���������, �� ������ �������� � ����� ���� �, ���������, �� ����.";
				Link.l2.go = "HorseChoice_1_Add";
			}
		break;
		
        case "HorseChoice_2": 
			if (!CheckAttribute(npchar, "quest.sexHappend"))
			{
				dialog.text = NPCStringReactionRepeat("��� ���,"+ GetSexPhrase(" ����� ����,","") +" �������-�� ����� �����. ��� �������� �����, ��� ������ ������.", 
					""+ GetSexPhrase("��, �������� ��,","�� ��� ��") +" ��������� ���� � ����...", 
					"��������, ����� ������ ���?!", 
					"��, �� ���� ��, ������ ������"+ GetSexPhrase(", ����� ������ ������� ���������. ������ �� ���� ��������� - ��� � ������� ���������, ��������!","...") +"", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��, ������"+ GetSexPhrase("","�") +"...", "��, ��� ��� ��� � �������...",
						"��, ����� ������, � ����� � ���...", "���������� � ����������"+ GetSexPhrase(", ����","") +"...", npchar, Dialog.CurrentNode);
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�-�-�, ��� ����� ��! "+ GetSexPhrase("� ����� � ������� ���������� ������, ������ �� �������� � ���� ����... �","���������, �") +"��� ������ "+ GetSexPhrase("���������","������������") +" �� ���� - ����� ������� ���������, � ����� ���� ��� �����������...";
				Link.l1 = "���, ��� �� ����������...";
				Link.l1.go = "exit";
			}
		break;
		
        case "HorseChoice_1_Add":
			dialog.text = "��, �� �����, ��� ���� ��� ����������... ����� ����.";
			Link.l1 = "������...";
			Link.l1.go = "exit";
			npchar.quest.choice = 0;
		break;
		
		//===>> ����
        case "Horse_ReadyFack":
			// Addon 2016-1 Jason ��������� �������
			if (pchar.location == "SantoDomingo_Brothel_room" && CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_2" && npchar.name == "��������")
			{
				dialog.text = "� ��� � ��! ����� ������. ����� ����� �� ���������, ��� ��� ����������...";
				Link.l1 = "��� ��� ���� ������� ������� ������� ������?";
				Link.l1.go = "mtraxx_2";
				break;
			}
			if (!CheckAttribute(npchar, "quest.choice")) npchar.quest.choice = 0;
			switch(npchar.quest.choice)
			{
				case "0":
					dialog.text = RandPhraseSimple("����� ���� ������ ���� � ������� ���������. "+ GetSexPhrase("� ��� �� ������ ��������?","�� ��� ��, ����� ������������?") +"", "�������, �� ���������"+ GetSexPhrase(", �������� ���� ��� ���� �� ��������� ��� ����.",". � ����� ����... ��������, �� ���������.") +"");
					Link.l1 = RandPhraseSimple("������� �� �����, �������...", ""+ GetSexPhrase("����� �����������, �����!","�� ����� ������ �������!") +"");
				break;
				case "1":
					dialog.text = "��, ��� � ��, ��"+ GetSexPhrase("� ������� ������! � ���-��� ������� ���� � ������ �������� ���� �����","� ������� �������! ��������� ��� ���� �� �� �������� �������") +"...";
					Link.l1 = "��, ��� ��������� ������...";	
				break;
				case "2":
					dialog.text = "�-�-�, ����"+ GetSexPhrase("��","��") +", �������-��. ��, �� ����� ������ �������!";
					Link.l1 = ""+ GetSexPhrase("�� �����, �����...","��, ������ ���, ��� �� ������...") +"";
				break;
			}
			Link.l1.go = "exit";
			//--> ���-�� ���������
			if (!CheckAttribute(npchar, "quest.sexHappend")) npchar.quest.sexHappend = 1;
			else npchar.quest.sexHappend = sti(npchar.quest.sexHappend) + 1;
			pchar.GenQuest.BrothelCount = sti(pchar.GenQuest.BrothelCount) + 1; // ��� �����
			//<-- ���-�� ���������
			str = npchar.city;
			pchar.quest.(str).win_condition.l1 = "ExitFromLocation";
			pchar.quest.(str).win_condition.l1.location = pchar.location;
			pchar.quest.(str).win_condition = "Brothel_checkVisitTime";
			pchar.questTemp.HorseQty = sti(pchar.questTemp.HorseQty) + 1; //�������
			NextDiag.TempNode = "Horse_AfterSex";
			AddDialogExitQuest("PlaySex_1");
			// ��� �� �������
			if (CheckNPCQuestDate(pchar, "BrothelSex"))
			{
				if(IsEquipCharacterByArtefact(pchar, "totem_03")) 	AddCharacterHealth(pchar, 10);
				else 												AddCharacterHealth(pchar, 5);
				SetNPCQuestDate(pchar, "BrothelSex");
			}
			// ��������� ��������
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
			AddCharacterExpToSkill(pchar, "FencingS", -15);
			AddCharacterExpToSkill(pchar, "Pistol", -15);
		break;

        case "Horse_AfterSex":
			if (CheckAttribute(pchar, "questTemp.ReasonToFast") && pchar.questTemp.ReasonToFast == "Begin")
			{
				dialog.text = "�������, � ���� �� ���"+ GetSexPhrase("��","��") +" �� �����������"+ GetSexPhrase("��","��") +"?";
				link.l1 = LinkRandPhrase("�� ���"+ GetSexPhrase("��","��") +" ����.", "� �������� ��� ���������.", RandPhraseSimple("� ���� �� �� ��������� �����.", "���� ��, "+ GetSexPhrase("��������","�������") +", ����� �������� ����������."));
				link.l1.go = "exit";
				link.l2 = ""+ GetSexPhrase("�� ���� ��� ������, ��� � ������ �� ��������! � ������ ������� ��������� ������� ������� � ������������","��-�, ������ �� ���-���� ��������� ������������ �������... � ���������.") +".";
				link.l2.go = "Horse_ReasonToFast_1";
			}
			else
			{
				switch(npchar.quest.choice)
				{
					case "0":
						dialog.text = LinkRandPhrase("���� �����������?", "��, ��� �������? ��� � �������?", "��� ����,"+ GetSexPhrase(" ������, ���"," ���") +" ���������?");
						Link.l1 = RandPhraseSimple(""+ GetSexPhrase("�������, ��� � �������","� �� � ������... ������") +".", ""+ GetSexPhrase("��� � �����, ������","�� ������, � ������ ��������") +".");
						Link.l1.go = "exit";
					break;
					case "1":
						dialog.text = LinkRandPhrase("�� ���, � ��������� ��������?", "��, ���"+ GetSexPhrase(" � ����, �����������",", ���� �����������") +"?", "� �������, "+ GetSexPhrase("�� �������, ������ ��� � �-�-����� ��������","�� ��������. � ���������") +"...");
						Link.l1 = RandPhraseSimple("��, ��� ��� ����� �����������.", ""+ GetSexPhrase("������� �������������, �� ���� �� ������!","��� ���� ������ ������������!") +"");	
						Link.l1.go = "exit";
					break;
					
					case "2":
						dialog.text = RandPhraseSimple("�� ���, ���� ����.", "����� �����,"+ GetSexPhrase(" ������,","") +" ���� ���� �� �����.");
						Link.l1 = RandPhraseSimple("���, ����...", "�� �������� � ������� ����...");
						Link.l1.go = "exit";
					break;
				}
				NextDiag.TempNode = "Horse_AfterSex_2";
			}	
		break;
		
        case "Horse_AfterSex_2":
			if(CheckAttribute(pchar,"GenQuest.EncGirl") && pchar.GenQuest.EncGirl == "Bag_BrothelRoom" && !CheckCharacterItem(pchar, "leather_bag"))
			{
				dialog.text = "��, ��� ��� � ��� �����������?";
				link.l1 = "������, ��������, � �� ������ �� �� ���-�� ����� �������?";
				link.l1.go = "EncGirl_GetBag";
			}
			else
			{
				dialog.text = LinkRandPhrase("������ � ��� ��� ���-������...", "�� �������� � �� ����� ������...", "����� ���� ������ ���� � ��� ���...");
				Link.l1 = "�����...";
				Link.l1.go = "exit";
				NextDiag.TempNode = "Horse_AfterSex_2";
			}	
		break;
		
		case "EncGirl_GetBag":
			dialog.text = "��� ����� ���������� �������� � ������?";
			link.l1 = "��, ���-�� ��������...";
			link.l1.go = "EncGirl_GetBag1";	
		break;
		
		case "EncGirl_GetBag1":
			dialog.text = "��������� ������� � ����� �������� �� �������, �� ����� ������� ��� � ���� � ������.";
			link.l1 = "�������, �����. �� ��������.";
			link.l1.go = "exit";
			pchar.GenQuest.EncGirl = "Bag_BrothelHostess";
			NextDiag.TempNode = "Horse_AfterSex_2";
		break;
		
		// --> ��������� - "����� ��� ������"
		case "Horse_ReasonToFast_1":
			dialog.text = "����� ������ ���, � ������ ���� ���� ����... �� ���"+ GetSexPhrase("�� �����, �� �� ��� ������","�� �����, �� ��, ��� ��� ������") +" - �� ��������, �� �� ��������, �� ��� ������� �������...";
			link.l1 = "� ��� ��� ��?..";
			link.l1.go = "Horse_ReasonToFast_2";
		break;
		
		case "Horse_ReasonToFast_2":
			pchar.questTemp.ReasonToFast.speakHorse = true;
			dialog.text = "�� ��� ����� ����� ���������� ��������. �� ������-�� � ��� �� �����, � ��� �������� ��������. ��� � ���� ������... �������-�������, ����� ������� ���� �������� � ����������� � ����� �����-��. ��� ������ ������, ���� ���� ������ �� �������, ��-��-��...";
			link.l1 = "���� �� �� �����, "+ GetSexPhrase("���������","�������") +", ����� ������ ������? ���� ������, ��� � ������� �����, ��������� - ��� � ���� ���������, � ��� - � �����, �� ��������������. "+ GetSexPhrase("��-��-��-��!..","��-��-��!") +"";
			link.l1.go = "Horse_ReasonToFast_3";
		break;
		
		case "Horse_ReasonToFast_3":
			NextDiag.TempNode = "Horse_AfterSex_2";			
			ReOpenQuestHeader("ReasonToFast");
			AddQuestRecord("ReasonToFast", "1");
			pchar.questTemp.ReasonToFast = "SpeakHorse";
			pchar.questTemp.ReasonToFast.GuardNation = npchar.nation;
			pchar.questTemp.ReasonToFast.cantSpeakOther = true;
			ReasonToFast_InitVariables();
			string TargetLocation = SelectQuestShoreLocation();
			if(TargetLocation != "")
			{ 
				Locations[FindLocation(TargetLocation)].DisableEncounters = true; 
				pchar.quest.ReasonToFast_MeetPatrol.win_condition.l1 = "location";
				pchar.quest.ReasonToFast_MeetPatrol.win_condition.l1.location = TargetLocation;
				pchar.quest.ReasonToFast_MeetPatrol.function = "ReasonToFast_MeetPatrolShore";
				pchar.questTemp.ReasonToFast.PatrolLocation = TargetLocation;
			}	
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();		
		break;
		// <-- ��������� "����� ��� ������"
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//������ ������ ����
		case "TakeMayorsRing_S1":
			if (CheckAttribute(pchar, "questTemp.different.TakeMayorsRing.item")) //���� �������� � ������
			{
				dialog.text = LinkRandPhrase("���, �������, �� ����������, � ���������. ���� �� ������, �� �� ����...", 
					"���, "+ GetSexPhrase("���������","�������") +", ������ �� ������...", 
					"� ���������, ���. �������� ������ �� ������.");
				link.l1 = "����... �� ��� ��, ������� ����.";
				link.l1.go = "exit";
			}
			else
			{
				if (npchar.id == "HorseGen_"+reload_location_index+"_1")
				{
					dialog.text = "�� �� ������ �� ����������� �� ������ �����?";
					link.l1 = "������, ������!";
					link.l1.go = "TakeMayorsRing_S2";
				}
				else
				{
					dialog.text = LinkRandPhrase("���, �������, �� ����������, � ���������. ���� �� ������, �� �� ����...", 
						"���, "+ GetSexPhrase("���������","�������") +", ������ �� ������...", 
						"� ���������, ���. �������� ������ �� ������.");
					link.l1 = "����... �� ��� ��, ������� ����.";
					link.l1.go = "exit";
				}
			}
		break;

		case "TakeMayorsRing_S2":
			dialog.text = "������, �� ������ ��� ��������! ��� ��� ���������� ��� � �� �������.";
			link.l1 = "��������?! ���?";
			link.l1.go = "TakeMayorsRing_S3";
		break;
		
		case "TakeMayorsRing_S3":
			dialog.text = "����� ������������, �������!";
			link.l1 = "��� �� ��� ������ ��������, ����� ������. �� ������ ������ �� ������.";
			link.l1.go = "TakeMayorsRing_S4";
		break;
		
		case "TakeMayorsRing_S4":
			dialog.text = "�� � � �� ����� ��� ���? ���� �� ��� �� ��� �� � ����, �� ��� ��� ��������!";
			link.l1 = "��������, ��������, ��� �� ����������. �� ����� ���� � ��� ���������? ������ ���� �����������, ���� ���������... �����, �� ����� ���� ������� ��-�� ����� ������.";
			link.l1.go = "TakeMayorsRing_S5";
		break;
		
		case "TakeMayorsRing_S5":
			if (rand(1) && sti(pchar.money)>5000)
			{
				dialog.text = "������ �����, ������ �� ��������� ��� ���� ����� ����.";
				link.l1 = "������, ������� ���� ������ � ���� ������.";
				link.l1.go = "TakeMayorsRing_S6";
			}
			else
			{
				dialog.text = "��, �� �����. ����� ��������!..";
				link.l1 = "�������������, ��������!";
				link.l1.go = "exit";
				GiveItem2Character(pchar, "MayorsRing");
				pchar.questTemp.different.TakeMayorsRing = "HorseTakenRing";
				AddQuestRecord("SeekMayorsRing", "3");
				AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
				AddQuestUserData("SeekMayorsRing", "sName", GetFullName(npchar));
			}
		break;
		
		case "TakeMayorsRing_S6":
			dialog.text = "����������...";
			link.l1 = "��, �������. ������� �� ������, ��������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -5000);
			GiveItem2Character(pchar, "MayorsRing");
			pchar.questTemp.different.TakeMayorsRing = "HorseTakenRingMoney";
			AddQuestRecord("SeekMayorsRing", "2");
			AddQuestUserData("SeekMayorsRing", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("SeekMayorsRing", "sName", GetFullName(npchar));
		break;
		
		//Jason --> ���������� ����������
		case "Badboy":
			pchar.GenQuest.Badboy.Brothel.City = npchar.city; //����� ������������
			//log_info(pchar.GenQuest.Badboy.Brothel.City); // patch-6
			pchar.GenQuest.Badboy.Brothel.nation = npchar.nation;
			pchar.GenQuest.Badboy.Brothel.Name = GenerateRandomName_Generator(sti(npchar.nation), "man");
			dialog.text = "���������, ��� ����� ������ ��������� ���� ������ - "+pchar.GenQuest.Badboy.Brothel.Name+". �� ���������� � ������� �� ��������� ���������, ����� �������� ����, ������� ������� � ���������. ����� ���������� - ��� �� ������������ ������������� � �����-�� ������� ����������� ������ �����������, ��� ��� ��� ������� ����� ������ ��������� �������. �� ����� �� �� ��������� ����� �������� ������... ���, ����� �� ����� ������ � ��� ���������?";
			link.l1 = "����������� �����������? ��... �������, �� ����� ������� ��������� � �������. ��, �� �� ���������. ��� ��� ������.";
			link.l1.go = "exit";
			link.l2 = "��� ����� ��������. ��� ��� ����� ����� ������?";
			link.l2.go = "Badboy_1";
		break;
		
		case "Badboy_1":
			dialog.text = "� ����� ����� �� ������ ��������� � �������. ������������ �����, � ����� ��� ���� ����.";
			link.l1 = "�������. �����, ������� ��� ���.";
			link.l1.go = "exit";
			//������� ��������
			int iRank, iType, b;
			string sBlade, sPistol;
			if (sti(pchar.rank) < 6) iType = 0;
			if (sti(pchar.rank) >= 6 && sti(pchar.rank) < 16) iType = 1;
			if (sti(pchar.rank) >= 16) iType = 2;
			switch (iType)
			{
				case 0:
					iRank = 6;
					sBlade = "blade_12";
					sPistol = "pistol1";
					b = 25;
				break;
				case 1:
					iRank = sti(pchar.rank)+10;
					sBlade = "blade_09";
					sPistol = "pistol1";
					b = 65;
				break;
				case 2:
					iRank = sti(pchar.rank)+5;
					sBlade = "blade_14";
					sPistol = "pistol1";
					b = 40;
				break;
			}
			sld = GetCharacter(NPC_GenerateCharacter("Badboy", "citiz_"+(7+rand(1)), "man", "man", iRank, HOLLAND, -1, true, "citizen"));
			FantomMakeCoolFighter(sld, iRank, b, b, sBlade, sPistol, "bullet", makeint(iRank*5));
			sld.name = pchar.GenQuest.Badboy.Brothel.Name;
			sld.lastname = "";
			sld.dialog.FileName = "Quest\Other_quests_NPC.c";
			sld.dialog.currentnode = "Badboy";
			sld.greeting = "noble_male"; // patch-6
			LAi_SetLoginTime(sld, 15, 22);
			LAi_SetSitType(sld);
			FreeSitLocator(pchar.GenQuest.Badboy.Brothel.City + "_tavern", "sit1");
			ChangeCharacterAddressGroup(sld, pchar.GenQuest.Badboy.Brothel.City + "_tavern", "sit", "sit1");
			pchar.GenQuest.Badboy.Brothel.Type = iType; //�������� ���
			pchar.GenQuest.Badboy.Brothel = "true";
		break;
		
		case "Badboy_complete":
			dialog.text = "��, �� ��������� �������. � �����, ��� ���� �� ��� ����������.";
			link.l1 = "������ ����� ������ ����� ���������� ���� � ��... ����������.";
			link.l1.go = "Badboy_complete_1";
		break;
		
		case "Badboy_complete_1":
			dialog.text = "�� �� ������ ������, �� ��� � ����� ��������. � �� ������ ������������� ��� ��-����������. ���, ��� ����� ������� ������ �������. � ���, ��� �� �� �������� ����� �������. ������������ � �������, �������� �����...";
			link.l1 = "...";
			link.l1.go = "Badboy_complete_2";
		break;
		
		case "Badboy_complete_2":
			pchar.questTemp.different.HostessSex.city = pchar.GenQuest.Badboy.Brothel.City;
			AddDialogExitQuestFunction("SexWithHostess_goToRoom");
			SetTimerFunction("SexWithHostess_null", 0, 0, 1); 
			DialogExit();
			if (sti(pchar.GenQuest.Badboy.Brothel.Type) != 2)
			{
				DeleteAttribute(pchar, "GenQuest.Badboy");
			}
			else
			{
				pchar.quest.Badboy_Brothel.win_condition.l1 = "location";
				pchar.quest.Badboy_Brothel.win_condition.l1.location = pchar.GenQuest.Badboy.Brothel.City +"_town";
				pchar.quest.Badboy_Brothel.function = "Badboy_friends";
				DeleteAttribute(pchar, "GenQuest.Badboy.Continue"); // patch-6
			}
			SaveCurrentQuestDateParam("questTemp.Badboy");
		break;
		// <-- ���������� ����������
		
		//����������
		case "Portugal":
			dialog.text = "���� ���� �������, �� �������� ���, �� �, �����, �� ����, ��� ��� �������...";
			link.l1 = "�� ����� ����! � ����� ��� � �������� ��� �� ���������� ����, �� ���� ���� ������ ����� ��������� ����! �������� ��� ��� � ������!";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "���-���, �� ���� ����������� ������, �������! ���� �������... �� ������� ��� ������ �������. ������ ��������� ��� � �����. ��� ����� ����� �������, �, � �������, �� ������� ��� ���, ��� ������ ����� ������� �������. ������ ���� ����, �� ���������� � ���� ����!\n������ �������... ���������, ��� �� ������ ���������. � �� ���� ���������� � ������, �� � ���� ���� �������� �������, ��� ��� ��������� ��� � � ���, � ��� ���� ���� � ���� ���������, �� ������� ����������� ���, � ��������� ���� ������� ����. ������ ��������� ��� � ��� ��������.";
			link.l1 = "���� ����� � ����� ��� ����, �����. � � ������������� ������� ���� �������.";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			DialogExit();
			//������� �����
			sld = GetCharacter(NPC_GenerateCharacter("Avendel", "Hugh", "man", "man", 10, HOLLAND, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 20, 50, 50, "blade_04", "pistol1", "bullet", 50);
			sld.name = "�����";
			sld.lastname = "�������";
			sld.dialog.FileName = "Quest\Portugal_dialog.c";
			sld.dialog.currentnode = "Avendel_tavern";
			sld.greeting = "avendel_1";
			sld.rank = 12;
			LAi_SetHP(sld, 80, 80);
			SetSelfSkill(sld, 10, 12, 10, 10, 70);
			SetShipSkill(sld, 50, 75, 15, 15, 25, 55, 10, 15, 30);
			SetSPECIAL(sld, 3, 8, 3, 10, 10, 3, 6);
			SetCharacterPerk(sld, "BasicCommerce");
			SetCharacterPerk(sld, "AdvancedCommerce");
			SetCharacterPerk(sld, "BasicBattleState");
			SetCharacterPerk(sld, "AdvancedBattleState");
			SetCharacterPerk(sld, "BasicDefense");
			SetCharacterPerk(sld, "Gunman");
			GiveItem2Character(sld, "blade_12");
			sld.equip.blade = "blade_12";
			GiveItem2Character(sld, "pistol1");
			EquipCharacterbyItem(sld, "pistol1");
			TakeNItems(sld, "bullet", 10);
			AddItems(sld, "gunpowder", 10);
			LAi_SetCharacterUseBullet(sld, "bullet");
			LAi_group_MoveCharacter(sld, "HOLLAND_CITIZENS");
			LAi_SetImmortal(sld, true);
			LAi_SetSitType(sld);
			FreeSitLocator("Marigo_tavern", "sit_front1");
			ChangeCharacterAddressGroup(sld, "Marigo_tavern", "sit", "sit_front1");
			SetFunctionTimerCondition("Portugal_BeginOver", 0, 0, 2, false);
			pchar.questTemp.Portugal = "begin";
		break;
		
		case "Portugal_exit":
			dialog.text = "������� ���, �������. �������, ��� �� ������� ������� ������������.";
			link.l1 = "� ������ � ����, �����. �� ���� ��������� �����������.";
			link.l1.go = "exit";
			sld = characterFromId("Avendel");
			sld.lifeday = 0;
			pchar.questTemp.Portugal = "end";
		break;
		
		case "Portugal_3":
			AddMoneyToCharacter(pchar, -10000);
			dialog.text = "�, ���! �������, �� ������ � ��� ��... � ���� �� ��� �����, � ����� �����! �� ������ ������� � ����� �������, � �� ������� �� ����� � ������! ������ ������ ��� ����������, �����������, ���� �� ������������ �� ������ � ����� ������!";
			link.l1 = "���, � ��� �� ����� � ��� ���� ������. � �� ����� �� ������������ � �� � ������ ������� �����, ���� �����������.";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			dialog.text = "��, �������, �� �� ���������! �� ���� ��� ����� ��... ��, ������, �� �������� �������� �� �������� � ��������, ������������� ������� � �����������. ������, �� ��� �� ����� ���������, ����� �� ������� �����\n�� ��� �����, �� ������������ ��������� � ������� ������� � �������, �, � ��� ���, ������� �� ��� ����� ������ ���� �� ����. �, �� ������ ������, �������� ��� ������ ��������� ����. �� ���... ��� ����� ������. � �����-�� ��� ������ ��������� � ����� ��������� �� ��������� ��-�����\n� ����, �� �������� ��� ���-������, � �� ��������� �� ������ �������! � ����� ��� ��� ������, ������ �� ������� ��� ������ �������, ������, �������!";
			link.l1 = "������-������, � ����� ���, �����. �� ����� ���������� ������ � ��� ����, � � �� ������ ������ ������ �����. � ������, ��������� ����������� � ���� ���� ����. ��� ��� ������ ����� ���������� ����.";
			link.l1.go = "Portugal_5";
		break;
		
		case "Portugal_5":
			DialogExit();
			sld = characterFromId("Avendel");
			sld.dialog.currentnode = "Avendel_tavern_7";
			pchar.questTemp.Portugal = "AvendelTavern";
		break;

		// Addon 2016-1 Jason ��������� �������
		case "mtraxx":
            dialog.text = "���� ��, �� ��� ���... ��� � ����� ������, � ���� �� ���� ��������. � ������� �������, ��� ��� ������ ����, � ����������. � �� ��� ��� - �� ����� ������!.. ��, �������, �� �� ������ � ������� �������, ������ ��� ���� �������� ������ ������, ��-��-��...";
			link.l1 = "��� ���, �������...";
			link.l1.go = "mtraxx_1";
		break;
		
		case "mtraxx_1":
           DialogExit();
		   pchar.questTemp.Mtraxx = "jewelry_2";
		break;
		
		case "mtraxx_2":
			pchar.quest.Mtraxx_JewelrySDMOver.over = "yes"; //����� ������
            dialog.text = "���, �� ���. ���� �� �� ������ ���� ����������, � ��� �������� �� �������.";
			link.l1 = "� ���� ��������!";
			link.l1.go = "mtraxx_3";
		break;
		
		case "mtraxx_3":
            dialog.text = "����� ������. ������ ����� � �����-������� ������ ������� �������. �� ��� �������� �� �� � ������, �� �� � ���, ������ ��� ����� ���� �� ������, ������� ����������������� � �����, � ������� ��������� ���������� � ����� ���������. ��� ��� ������ �� ����� � ��������� � ����� ����� �������. ��� ��-�� �� � ������� �������, � �� ����. ��� ���� ���� ������������ - ������ ��������� ��������� ���� ������� ��������\n�� ������ ���� � �� ����� �������� �������� �������, � ��� � ����� ����������, ��� ��� �� �����. � ����� �������� ������� � ���, ��� �������, ������ � ������� ������, ���������, ��� ����� ����� ������ �������� ������ � ������ ��������� ���� �� �� ��� �����, �� �������, � ����� ������� �������� �������...";
			link.l1 = "";
			link.l1.go = "mtraxx_4";
		break;
		
		case "mtraxx_4":
            dialog.text = "� � ���������� ������� �������� ��� ������� ���������� ���, ��� ��� ������ ���� ������ ��������, � �������, � � ���� ��������� ����� �����. ������� ���������� ������� ���� �����-������ �����������, �� ��� ������� ����������. ������, ����� �����������, ��� �� ����� ����� ����� ��� ���� � �������� � ������ ����, � �� ��������\n�� �����, ��� �� ����� ������� ������, �� ���� ����������� ������ �� ��� - ������. ������������ ������ �� ����� ��������� � ���, ��� � ������, ��� ��� ����� ���������������, �� ������������ � ������ � ��� ����� ��������� ������� ���, ����� ��� �� ������ ��������� � �������� � ������ ��� ����������� - �������-�� �� ���, � ��������.";
			link.l1 = "������, �� ������ � ������?";
			link.l1.go = "mtraxx_5";
		break;
		
		case "mtraxx_5":
            dialog.text = "�� ������� ��������� �� ��������, ��� ��� ��� ������, �������� �� ���� ��� ��� - �� �� ����� ��� ����� �����.";
			link.l1 = "��� ��������, �������� � ��� ����� ������� �������?";
			link.l1.go = "mtraxx_6";
		break;
		
		case "mtraxx_6":
            dialog.text = "�� ���� �� ������� �������? �������. ������� �������� ��� �����, � ������� - '��������'. � ��� - ����� ������ ��� ������ ��������.";
			link.l1 = "��� ���, ��� �� ������?";
			link.l1.go = "mtraxx_7";
		break;
		
		case "mtraxx_7":
            dialog.text = "���� ����? ���� ������������, �� ��������� ������� ��� ������� � ������. � �� ����: �� �����, ��� ��� ����������� ����� �������, ����� ����������� � ���� � ����� �������, � ����� - ���-�����. �������, �� ��� ���� ������ ����������� - ������-�� ��������.";
			link.l1 = "��������, �������, ��� ���� � ���� �������� ���� �� �������...";
			link.l1.go = "exit";
			sTotalTemp = npchar.id;
			pchar.GenQuest.BrothelCount = sti(pchar.GenQuest.BrothelCount) + 1; // ��� �����
			//<-- ���-�� ���������
			str = npchar.city;
			pchar.quest.(str).win_condition.l1 = "ExitFromLocation";
			pchar.quest.(str).win_condition.l1.location = pchar.location;
			pchar.quest.(str).win_condition = "Brothel_checkVisitTime";
			pchar.questTemp.HorseQty = sti(pchar.questTemp.HorseQty) + 1; //�������
			AddDialogExitQuest("PlaySex_1");
			// ��� �� �������
			if (CheckNPCQuestDate(pchar, "BrothelSex"))
			{
				if(IsEquipCharacterByArtefact(pchar, "totem_03")) 	AddCharacterHealth(pchar, 10);
				else 												AddCharacterHealth(pchar, 5);
				SetNPCQuestDate(pchar, "BrothelSex");
			}
			// ��������� ��������
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
			AddCharacterExpToSkill(pchar, "FencingS", -15);
			AddCharacterExpToSkill(pchar, "Pistol", -15);
		break;
		
		case "mtraxx_R":
            dialog.text = "�� �������? �-�... ��� ������������. � �-�� ������ - �� �������� ���� �������. ��� ������� ������� �� ������ ��������. ��, ������, ��� ��� �� ����?..";
			link.l1 = "������ ������� ��� ��� ��� ������ � ����� ��������� �� ��� �������, ������ ��� ����� ������ ��������� ���� � ��������� ���� ����� �������. ����� ����� ����������?";
			link.l1.go = "mtraxx_R1";
		break;
		
		case "mtraxx_R1":
            dialog.text = "��, ����� "+pchar.name+", ���� ���� ��� �� �����, ��� � ���� �����! � ��� ���� ������������... �������! � ��� �����, �� �����! ������������� ���� � ������ �������!";
			if (sti(pchar.money) >= 31000)
			{
				link.l1 = "���� ���� ����� ������ - ����� �������� � ����������! ��-��-��!..";
				link.l1.go = "mtraxx_R2";
			}
			else
			{
				link.l1 = "������� ���� �����, ������� - � ������ �� ���� ������� �� �������� ��� ���� � ����� ������. ����� ����!";
				link.l1.go = "exit";
				pchar.questTemp.Mtraxx.Retribution = "brothel_repeat";
				chrDisableReloadToLocation = false;
			}
		break;
		
		case "mtraxx_R2":
			AddMoneyToCharacter(pchar, -30000);
            dialog.text = "���� �� ��� ������� ���� ������ ������, ������������ � �������, ��� ��... ��� ����� �� ������. ��-������-�!..";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionInBrothel");
		break;


//********************************* ������� ����� �� ������� �� **********************************
			//--> ���. �������
  		case "Gothic_3_1":
			dialog.text = "� ���?";
			link.l1 = "������ �, ���� �� ������� ����� �����-�� ��������� � �������, ���� ������...";
			link.l1.go = "Gothic_3_2";
		break;
  		case "Gothic_3_2":
			dialog.text = "���� �����, �����... ��������, ���������, ����� ���������� ������ � � ������ �� ��� ���� �������. ���� ��� ����� ������ ����� 1000 ����...";
			link.l1 = "�� ������ ���� ���-������ ������� ���������?";
			link.l1.go = "Gothic_3_3";
		break;
  		case "Gothic_3_3":
			dialog.text = "��-��-��... ���� ����� ���������� - ��� ����� ������. ������, ���� ���� �� ������ ����������, �� � ���-��� ���, ���� ���������� ������... � ���� ����. ������ ��� ����� ������, ��-��...";
			link.l1 = "� ���� ��� ������� �� ��������.";
			link.l1.go = "Gothic_3_4";
		break;
  		case "Gothic_3_4":
			dialog.text = "��, ������� ������� ����� ���������!!!";
            if (sti(pchar.money) >= 1000)
            {
    			link.l1 = "��� ���� ������, �� ������ ��� ������ ����� � ������.";
    			link.l1.go = "Gothic_3_5";
                AddMoneyToCharacter(pchar, -1000);
            }
            else
            {
    			link.l1 = "������ � �� ���������, ����� ������ ���...";
    			link.l1.go = "exit";
			npchar.quest.GothicLeeTalk = true;
            }
			NextDiag.TempNode = "Horse_talk";
		break;
		case "Gothic_3_5":
			dialog.text = "����� �� ���� ������� �����, ��� ����� ������� ���������� �����, ����� �� ������.";
			link.l1 = "��, � ���?";
			link.l1.go = "Gothic_3_6";
		break;
		case "Gothic_3_6":
			dialog.text = "��������� ��� �� � �����. �� ������� �������� ������, � ��� ���������� � ������, ��� �� �����. �������� ��� �� ���������� �����, ����� �� ���� ���� �������� �������, ��� �� ��������.";
			link.l1 = "��, ��� ��� ���������, �� � ����� �� �� ����������. ��� � ���� ����� ����� �������?";
			link.l1.go = "Gothic_3_7";
    	break;
		case "Gothic_3_7":
			dialog.text = "��� �������� �� �������, ��� � �������. ��� � ��� �������, ����� ��� ����� �� ����, �� ��������� ����������, ���������.";
			link.l1 = "�������, ���������� ����.";
			link.l1.go = "Gothic_3_8";
    	break;
		case "Gothic_3_8":
			dialog.text = "������, � ���, ������������� ��� ����� ����� �����?";
			link.l1 = "������ �������, �������� ����. � ��� �� ���� �������? ��� �����, ��� ����� � �����?";
			link.l1.go = "Gothic_3_9";
    	break;
		case "Gothic_3_9":
			dialog.text = "�� ������ ����������, ��� � �� ������ ����� ������. �� �� ���� ����, �� �� ������ �� �����...";
			link.l1 = "����. ������� ����, ����� ������ �� �����.";
			link.l1.go = "exit";
			AddQuestRecord("GothicLee_3_SeekBible", "4");
			pchar.questTemp.GothicLee = "SeekBible_toTavern";
			NextDiag.TempNode = "Horse_talk";
    	break;
			//<-- ���. �������

	}
}

ref GetFreeHorseRef(string City)
{
	ref rCharacter;
    int storeArray[8];
	int howStore = 0;
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(rCharacter, Characters[n]);
		if (rCharacter.location == City+"_Brothel" && CheckAttribute(rCharacter, "CityType") && rCharacter.CityType == "horse")
		{
			storeArray[howStore] = n;
			howStore++;
		}
	}
	if (howStore == 0) return &NullCharacter;
	return &characters[storeArray[rand(howStore-1)]];
}

ref CheckHorsesName(string City, int num)
{
	ref rCharacter;
	string sTemp, sSeeked;
	sSeeked = GetStrSmallRegister(dialogEditStrings[num]);
	for(int n=0; n<MAX_CHARACTERS; n++)
	{
		makeref(rCharacter, Characters[n]);
		if (rCharacter.location == City+"_Brothel" && CheckAttribute(rCharacter, "CityType") && rCharacter.CityType == "horse")
		{
			sTemp = GetStrSmallRegister(rCharacter.lastname + " " + rCharacter.name);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
				return rCharacter;			
			sTemp = GetStrSmallRegister(rCharacter.lastname);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
				return rCharacter;
			sTemp = GetStrSmallRegister(rCharacter.name);
			if (findsubstr(sSeeked, sTemp , 0) != -1)
				return rCharacter;
		}
	}
	return &NullCharacter;
}