//Jason ����� ������ �����
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Citizen\" + NPChar.City + "_Citizen.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
    ProcessCommonDialogRumors(NPChar, Link, NextDiag);
    int iTest, iTemp;
    iTest = FindColony(NPChar.City);
    ref rColony;
    string sTemp, sCity, sTitle;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	
	String attrLoc = Dialog.CurrentNode;
	
	if(HasSubStr(attrLoc, "RumourAboutOwners_"))
	{
		NPChar.RumourOwnerType = FindStringAfterChar(attrLoc, "_");
		Dialog.CurrentNode = "RumourAboutOwners_TakeRumour";
	}
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
            LAi_group_Attack(NPChar, Pchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");
			if (sti(NPChar.nation) == PIRATE)
			{
				if (sti(rColony.HeroOwn) == true) // ��� ���������
				{
				    dialog.text = RandPhraseSimple("����� ����, ��� �� � ���� ������"+ GetSexPhrase("��","���") +" ����� ������, "+ GetSexPhrase("���","����") +".", "����� �������� �������, ���"+ GetSexPhrase("","�") +" ����� ������ �������"+ GetSexPhrase("��","���") +" �� ��� � ��������.");
					link.l1 = RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +". �����!", "������ ���������� �����. �� ��������.");
					link.l1.go = "exit";
					link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
					link.l2.go = "quests";//(���������� � ���� ������)
					if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
		            {
		                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
		                {
							link.l3 = RandPhraseSimple("���� �������� ���������� ����.", "���������� ��������...");
							link.l3.go = "LoanForAll";//(���������� � ��������� ���������)
						}
					}
					break;
				}
				else
				{ // ������, �� ����
					if (sti(pchar.GenQuest.Piratekill) > 20)
					{
						dialog.text = RandPhraseSimple("�������! ����� ������� ���� � �������!", "� ������, � ������! ����� ������� ����!");
						link.l1 = RandPhraseSimple("�? ���?", "�, �� ���� ���?!");
						link.l1.go = "pirate_fight";
					}
					else
					{
				    dialog.text = RandPhraseSimple("���� ����? ������� ����.", "������ ������������ ������, ������.");
					link.l1 = RandPhraseSimple("������ ���? �� ������!", "������� ���� ���. �� �� ������ ������ ���!");
					link.l1.go = "pirate_fight_suka";
					link.l2 = RandPhraseSimple("���� �������� ����.", "������� ��������, ����� ���� ������.");
					link.l2.go = "quests";//(���������� � ���� ������)
					if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
		            {
		                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
		                {
							link.l3 = RandPhraseSimple("���� �������� ���������� ����.", "���������� ��������...");
							link.l3.go = "LoanForAll";//(���������� � ��������� ���������)
						}
					}
					}
				}
				break;
			}
            if(NPChar.quest.meeting == "0")
			{
				NPChar.quest.meeting = "1";
				// �������� ������� ������� � �����
				bool ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
				if (ok && sti(Pchar.Ship.Type) != SHIP_NOTUSED && CheckAttribute(npchar, "quest.passenger") && !CheckAttribute(pchar, "GenQuest.Townpassenger") && 6-sti(RealShips[sti(Pchar.Ship.Type)].Class) > 0)//���������-��������
				{
					dialog.text = "�����������, "+GetAddress_Form(NPChar)+". ����, �� ������� ������������ �������. � ����� �� ��������� ��� �� ����� ������...";
					link.l1 = "������ ���, "+GetAddress_FormToNPC(NPChar)+". � ��� ������ ����?";
					link.l1.go = "passenger";
					link.l2 = "��������, "+GetAddress_FormToNPC(NPChar)+", �� � ����� �����.";
					link.l2.go = "exit";
					npchar.quest.meeting = "1";
					DeleteAttribute(npchar, "talker"); //������� ���������
					break;
				}

                // homo 05/08/06
				dialog.Text =NPCharRepPhrase(npchar,
				LinkRandPhrase("���� ����� ", "��� ��� ", "������ �������� ���� ")
				+GetFullName(npchar)
				+LinkRandPhrase(". ���� ���� �����?", ". � ���� ������ ����� �� "
				+NPCharSexPhrase(NPChar, "�����", "������")
				+", ��� �� ���"+ GetSexPhrase("��","��") +"?", ". ��� �� � ��� ���� �� ���� ����?"),

				LinkRandPhrase("����������� ���, " + GetAddress_Form(NPChar) + ". ��� ��� " + GetFullName(npchar) + ". � ��� ����� ���?",
				 "������������, " + GetAddress_Form(NPChar) + "! � " + GetFullName(npchar) + ". ���� � ������ ���� ���?",
				 "��, " + GetAddress_Form(NPChar) + ". ��� �� ������? ������, ���� ����� " + GetFullName(npchar) + ". � ���?"));

				Link.l1 = pcharrepphrase(
				LinkRandPhrase("������� ���� ����! ", "������ ������! ", "���� ���� ����� ����! ") + "�� � ������� "+ GetFullName(Pchar)+ LinkRandPhrase(", �� ����� �� ������"+NPCharSexPhrase(NPChar,"","�")+" ��� ���"+NPCharSexPhrase(NPChar,", �������?","?"), " � "+ GetSexPhrase("����� ��������� �����","����� ��������� �������-�����") +" � ���� �����! ", " � ����������� ��� �� ���� �����, ���� ��� �� ���!"),
				LinkRandPhrase("� " + GetFullName(Pchar) + ", �������.", "���� ����� " + GetFullName(Pchar) + ".", "������ �������� ���� ������� "+GetFullName(Pchar)+"."));
				Link.l1.go = "Meeting";
			}
			else
			{
				link.l1 = PCharRepPhrase("�����"+ GetSexPhrase("","�") +" ���-��� ������ �� ���� ���������!", "�����"+ GetSexPhrase("","�") +" ������ ���-��� � ������.");
				link.l1.go = "new question";
 				link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
				if (CheckCharacterItem(pchar, "CaptainBook"))				
				{
					if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
					{
						link.l2.go = "ShipLetters_7";// ���������  "��������� ���������"
					}
					else
					{
						link.l2.go = "quests";
					}	
				}
				else
				{
					link.l2.go = "quests";//(���������� � ���� ������)
				}	
				if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
	            {
	                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
	                {
						link.l3 = RandPhraseSimple("���� �������� ���������� ����.", "���������� ��������...");
						link.l3.go = "LoanForAll";//(���������� � ��������� ���������)
					}
				}
				
				//Jason --> ��������� ����������� ���
				if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
				{
					link.l16 = "����������, ����� �� ��� ����������. � ���� ������ "+pchar.GenQuest.Device.Shipyarder.Type+", � ��� �������, ��� ��� ���� � ��� � ������ �����������. ��, ���-�� �������� �� ������. ������ �� ���� ������� �� ������?";
					link.l16.go = "Device_Citizen";
				}
				// <-- ��������� ����������� ���
				
				// ��������� ��������� ����������. ����� �2. Warship -->
				if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskPeople") && !CheckAttribute(NPChar, "GenQuest.ChurchQuest_2.AskedPeople") && NPChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_town")
	            {
					link.l5 = LinkRandPhrase("�� � �����", "�� ������", "�� ������ ���-������ � ���") + ", ��� ������� ���� ��������� ������� �������?");
					link.l5.go = "Citiz_GenQuest_Church_2_1";
				}
				// <-- ��������� ��������� ����������. ����� �2.
				
                dialog.Text = NPCharRepPhrase(npchar,
		                PCharRepPhrase(LinkRandPhrase("�, ��� �� "+GetFullName(Pchar)
                        +" "+ GetSexPhrase("- ������ ��������","- ��������� ������") +"", "��� ���� ������, "+ GetSexPhrase("�������","���������") +" "
                        + Pchar.name, "�, �� ��� �� "+ GetSexPhrase("��� �������","����") +" "
                         +GetFullName(Pchar))
						+LinkRandPhrase(". �����, ���� ��� ��� �� ���� �����!", ". �, ��������, "+ GetSexPhrase("��� ������ ����.","��� ������ ��������.") +"", ". �, ��� ����, ��� �� �������!")
						+LinkRandPhrase(" ��, ������, ���� ���� �����?", " ���� ���� �� ���� ���?", " ����� ��������� ���� �� ��������?"),
						LinkRandPhrase(TimeGreeting() + ", ������� ", "������������, "+GetAddress_Form(NPChar)+" ", "����������� ���, ������� ")+GetFullName(Pchar)
						+LinkRandPhrase(". ��� ����� ���� ����� "+ GetSexPhrase("������ ���������� ��������","����� ������ �������") +", ��� ��, �� ����?", ". ����� �� ������?", ". ��� �� ���� ��� �� ������ ������?")),
                                        
                        PCharRepPhrase(LinkRandPhrase("������������, ������� ", "�����������, �� ��� �� "+GetAddress_Form(NPChar)+" ", "�, ������� ")
						+GetFullName(Pchar)
						+LinkRandPhrase(", � �����"+NPCharSexPhrase(NPChar, " ", "� ")+"�� ������ � ���� �� ����������,",
										 ", �� �����, ��� ���"+NPCharSexPhrase(NPChar, " ", "� ")+"��� ������, ��", ", ����, �� ��� ����, ����������, �")
						+LinkRandPhrase(" ��� ��� �����?", " ����� �� ������?", " ��� ���� ���� "+NPCharSexPhrase(NPChar, "�������?", "�������?")),
						LinkRandPhrase(TimeGreeting() + ", ������� " + GetFullName(Pchar) + ". ��� ���� ������?",
						"�, �� ��� �� ���"+ GetSexPhrase("","�") +" ������� " + GetFullName(Pchar) + "! ��� �� ������ ������ �� ���� ���?",
						"������������, " + GetAddress_Form(NPChar) + " " + Pchar.lastname + ". �� ���-�� ������?"))
						);                         
	   			link.l6 = PCharRepPhrase(RandPhraseSimple("���� �����������, � �����.", "���, ������ - ������ �"+ GetSexPhrase("��","��") +" � �������."),
						RandPhraseSimple("�����, ������. �����!", "������ ���������� �����. �� ��������."));
				link.l6.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "ShipLetters_7":
			dialog.text = "����� �������?";
			link.l1 = "��� ������ �� ������� ��� � ���� �������?";
			link.l1.go = "ShipLetters_8";
		break;
		
		case "ShipLetters_8":
			dialog.text = LinkRandPhrase("��� ��� ���� �� ���������� �����, �� � ������ � �� ����. �������� � ����������, ��, �������, � ����������� ������� ������.",
			"������� �� ���� � ��� �� ��������, ������������� ��� ������� ����� ������, ������� " + GetFullName(Pchar) + ".", 
			"���� �� ���� ��� ��� ������, ������� " + GetFullName(Pchar) + ". ���������� ���������� � ����������, ����� �� �����?");
			link.l1 = "� ������������� ������������ ����� �������!";
			link.l1.go = "exit";
		break;
		
		case "Meeting":
		    dialog.Text  = NPCharRepPhrase(npchar, LinkRandPhrase("� �� �� �����, ������� " + GetFullName(Pchar)+"?",
				"� ��� � ���� " + PChar.name+"?",
				"� ������� ����, " + GetFullName(Pchar)+".")
				 + " � ������ ������, ���� ���� ����?",
				LinkRandPhrase("������� �������������, ������� " + PChar.name,
				"���"+NPCharSexPhrase(NPChar, " ", "� ")+" ������ ����������, " + GetAddress_Form(NPChar) + " " + PChar.lastname,
				 "����� �������, ������� " + PChar.name) + ". �� ���� �� �� ������ ������ ������ ��� ���, �� ��� ��?");
            link.l1 = PCharRepPhrase("�����"+ GetSexPhrase("","�") +" ���-��� ������ �� ���� ���������!", "�����"+ GetSexPhrase("","�") +" ������ ���-��� � ������.");
			link.l1.go = "new question";
            Link.l2 = RandPhraseSimple("� ���� ���� ������ � ����.", "��� ����� ����������.");
			if (CheckCharacterItem(pchar, "CaptainBook"))				
			{
				if((pchar.questTemp.different.GiveShipLetters.city == npchar.city) && CheckAttribute(pchar, "questTemp.different.GiveShipLetters"))
				{
					link.l2.go = "ShipLetters_7";// ���������  "��������� ���������"
				}
				else
				{
					Link.l2.go = "quests";
				}	
			}
			else
			{
					link.l2.go = "quests";//(���������� � ���� ������)
			}			
			if (CheckAttribute(pchar, "GenQuest.Loan.FindCitizen") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenDone") && !CheckAttribute(pchar, "GenQuest.Loan.FindCitizenFalied"))
            {
                if (Characters[sti(pchar.GenQuest.Loan.FindCitizenIdx)].id == Npchar.id)
                {
					link.l3 = RandPhraseSimple("���� �������� ���������� ����.", "���������� ��������...");
					link.l3.go = "LoanForAll";//(���������� � ��������� ���������)
				}
			}
			
			//Jason --> ��������� ����������� ���
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l16 = "����������, ����� �� ��� ����������. � ���� ������ "+pchar.GenQuest.Device.Shipyarder.Type+", � ��� �������, ��� � ��� � ������ ��� �����������. ��, ���-�� �������� �� ������. ������ �� ���� ������� �� ������?";
				link.l16.go = "Device_Citizen";
			}
			// <-- ��������� ����������� ���
			
			// ��������� ��������� ����������. ����� �2. Warship -->
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskPeople") && !CheckAttribute(NPChar, "GenQuest.ChurchQuest_2.AskedPeople") && NPChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_town")
	        {
				link.l5 = LinkRandPhrase("�� � �����", "���� ���-������ �������� � ���", "�� ������ ���-������ � ���") + ", ��� ������� ���� ��������� ������� �������?");
				link.l5.go = "Citiz_GenQuest_Church_2_1";
			}
			// <-- ��������� ��������� ����������. ����� �2.
			
			Link.l6 = PCharRepPhrase(RandPhraseSimple("���� �����������, � �����.", "���, ������ - ������ �"+ GetSexPhrase("��","��") +" � �������."),
                                        RandPhraseSimple("�����, ������. �����!", "������ ���������� �����. �� ��������."));
			Link.l6.go = "exit";
		break;
		
		case "new question":
            dialog.text = NPCharRepPhrase(npchar,
				PCharRepPhrase(LinkRandPhrase("�, �� � ���"+NPCharSexPhrase(NPChar, " ", "� ")+" ����, ��� �������, ���������, ���� ������.", "������ ���������, �������? ��� �, � ����... �������� �� ��������� ����.", "��, " + PChar.name + "?"),
				LinkRandPhrase("��, ���� ���� ���?", "����, ������� "+PChar.name+", �� ������"+ GetSexPhrase("�","��") +" ���������? ", "�������"+ GetSexPhrase("","�") +" ���������, �������, ����� �� �������"+ GetSexPhrase("","�") +" �����.")),
		        PCharRepPhrase(LinkRandPhrase("��� �� ������ ������ "+ GetAddress_Form(NPChar) + "?", "� ��� ������ �������.", "��� ����� ����, ������� ����������� ������, �������."),
                LinkRandPhrase("������ ���"+NPCharSexPhrase(NPChar, " ", "� ")+" ��������� �����������, " + GetAddress_Form(NPChar) + " " + PChar.lastname + ". ��������.",
                "��, " + GetAddress_Form(NPChar) + "?",
                "������ ���������, �������? ��� �, � ����...")));
			link.l1 = LinkRandPhrase ("����� ����� � ���� � ������� �������?","��� ���������� � ���� �����?","��� ����� ����� �� ����?");
			link.l1.go = "rumours_townman";
			link.l2 = LinkRandPhrase("�� ��������� ��� ������?", "���-�� � ����� �� ����� ������ ���-����...", "���������� ������...");
			link.l2.go = "town";  //(���������� � ���� ������)
			link.l3 = RandPhraseSimple("���� ������, ��� ��� ������� �� ����� ��������.", "�� ������, ��� ������� ��� �� ����� �������?");
			link.l3.go = "info"; //(���������� � ���� ������)
			link.l4 = RandPhraseSimple("�������� �� ������ ���-��� � ������� �������.", "�� ���������� ������� � ������� �������?");
			link.l4.go = "RumourAboutOwners";
			link.l5 = PCharRepPhrase(RandPhraseSimple("���� �����������, � �����.", "���, ������ - ������ �"+ GetSexPhrase("��","��") +" � �������."),
            RandPhraseSimple("�����, ������. �����!", "������ ���������� �����. �� ��������."));
			link.l5.go = "exit";
		break;
		
		case "RumourAboutOwners":
			Dialog.Text = "� ��� �� ������� �� ������ ������?";
			if(GetCharacterIndex(NPChar.city + "_Mayor") != -1)
			{
				link.l1 = "� �����������.";
				link.l1.go = "RumourAboutOwners_Mayor";
			}
			if(GetCharacterIndex(NPChar.city + "_TavernKeeper") != -1)
			{
				link.l2 = "� ������� ������� �������.";
				link.l2.go = "RumourAboutOwners_TavernKeeper";
			}
			if(GetCharacterIndex(NPChar.city + "_ShipYarder") != -1)
			{
				link.l3 = "� ������� �����.";
				link.l3.go = "RumourAboutOwners_ShipYarder";
			}
			if(GetCharacterIndex(NPChar.city + "_Trader") != -1)
			{
				link.l4 = "� ������� ������� ��������.";
				link.l4.go = "RumourAboutOwners_Trader";
			}
			link.l9 = "�� � ���. ������.";
			link.l9.go = "exit";
			break;
			
		case "RumourAboutOwners_TakeRumour":
			sTemp = sRumourAboutOwners_CityRumour(NPChar.City, NPChar.RumourOwnerType);
			Dialog.Text = sTemp;
			link.l1 = "�������.";
			link.l1.go = "exit";
			// ����� ����� ������ �������� �� �������, ����� ���� �����
			DeleteAttribute(PChar, "QuestTemp.RumoursAboutOwners");
		break;
		
		//Jason --> ��������� ����������� ���
		case "Device_Citizen":
           dialog.text = "��, "+pchar.GenQuest.Device.Shipyarder.Type+"? ������� �����... ���� ��� ��� �� ���� ����� - ������� ���� �� �����, ������ ��������� � ����� �� �����"+ NPCharSexPhrase(npchar, "","�") +".";
			link.l1 = "��, ��� ���������������� ����������, "+pchar.GenQuest.Device.Shipyarder.Describe+". ���-������ ����� �������� � ������, ���, �����, ����� � ����� � �� ��������?";
			link.l1.go = "Device_Citizen_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_Citizen_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) > 3 && sti(pchar.GenQuest.Device.Shipyarder.Chance1) < 6 && npchar.sex != "woman")
			{
				dialog.text = "��... ��, ����� � �������� � ������� �����, ����� �� �� ������ ��������� ����� �����. ���������� ���������.";
				link.l1 = "� ��� �������� ���� ������� � ���� �����? ��� ����� ����� ���� ����������.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "���, ������ ������ �� �����"+ NPCharSexPhrase(npchar, "","�") +". ������������� ��� � ����.";
				link.l1 = "����. ����� ����������!";
				link.l1.go = "exit";
			}
		break;
		
		//=================== ���� ������ ����������. ����� ���������� (����� �2)==================
		case "Citiz_GenQuest_Church_2_1":
			if(rand(3) != 1)
			{
				dialog.text = LinkRandPhrase("���, � ������ �� ���� �� ����.", "��� ������ �� �������� �� ����� �������.", "� ������ �� ����.");
					link.l1 = LinkRandPhrase("�����, ������.", "����, �������.", "������, ������.");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = LinkRandPhrase("� ������ �� ���� �� ����, �� �� ������ ����������� ������������ � ������� - ��� �� ����� ���-������ ��� ���������.", "� ��� ������ ������� �� ����, �������� ����� ����-������ � �������.", "��� ������ ����������� �� ��������, �� � ������, ��� �� ���� ��������� � �������.");
				link.l1 = "������� � �� ���.";
				link.l1.go = "exit";
			}
			
			NPChar.GenQuest.ChurchQuest_2.AskedPeople = true;
		break;		
		
		//-------------------------------���������-��������----------------------------------------------
		case "passenger":
			if (crand(19) > 9) SetPassengerParameter("Townpassenger", false);
			else SetPassengerParameter("Townpassenger", true);
			dialog.text = "�������, ��� ����� ��������� �� ������� " + XI_ConvertString("Colony"+pchar.GenQuest.Townpassenger.City)+", ��� �� "+XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Townpassenger.City)+"Dat")+", �� "+FindRussianDaysString(sti(pchar.GenQuest.Townpassenger.DaysQty))+". ���� ����� �������� ������� � ��������. � ����� ��������� �� ��� ����������� "+FindRussianMoneyString(sti(pchar.GenQuest.Townpassenger.Money))+". ��� �������?";
			link.l1 = "�������, � ��������. ������ ������ �� ��������.";
			link.l1.go = "passenger_1";
			link.l2 = "�������, "+GetAddress_FormToNPC(NPChar)+", �� ��� ������ � ������ �������. ����� �� ���� ������.";
			link.l2.go = "passenger_exit";
		break;
		
		case "passenger_exit":
			dialog.text = "����. �� ��� ��, ������� ������� �������. ��������!";
			link.l1 = "����� �������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "GenQuest.Townpassenger");
		break;
		
		case "passenger_1":
			dialog.text = "� ����� ���, ��� �� �����������. ������ ���������� �� �������� �� �����, �� �� ������?";
			link.l1 = "���, �� ������. ������������� �� ��� �����, "+GetAddress_FormToNPC(NPChar)+". �� ����� ����������.";
			link.l1.go = "passenger_2";
		break;
		
		case "passenger_2":
			DialogExit();
			pchar.GenQuest.Townpassenger.id = npchar.id;
			LAi_SetImmortal(npchar, true);
			DeleteAttribute(npchar, "LifeDay");
			LAi_RemoveLoginTime(npchar);
			DeleteAttribute(npchar, "CityType");//������� ������� �������, ����� - ������ ������
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 20.0);
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, false);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "1");
			AddQuestUserDataForTitle(sTitle, "sType", "����������");
			AddQuestUserDataForTitle(sTitle, "sName", GetFullName(npchar));
			sTemp = XI_ConvertString("Colony" +pchar.GenQuest.Townpassenger.City+"Gen") + ", ��� �� " + XI_ConvertString(GetIslandByCityName(pchar.GenQuest.Townpassenger.City)+"Dat")+".";
			AddQuestUserDataForTitle(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sName", GetFullName(npchar));
			AddQuestUserData(sTitle, "sCity", sTemp);
			AddQuestUserData(sTitle, "sDays", FindRussianDaysString(sti(pchar.GenQuest.Townpassenger.DaysQty)));
            AddQuestUserData(sTitle, "sMoney", FindRussianMoneyString(sti(pchar.GenQuest.Townpassenger.Money)));
			pchar.quest.Townpassenger.win_condition.l1 = "location";
			pchar.quest.Townpassenger.win_condition.l1.location = pchar.GenQuest.Townpassenger.City+"_town";
			pchar.quest.Townpassenger.function = "Townpassenger_complete";
			SetFunctionTimerCondition("Townpassenger_Over", 0, 0, sti(pchar.GenQuest.Townpassenger.DaysQty), false);
		break;
		
		case "passenger_3":
			pchar.quest.Townpassenger_Over.over = "yes"; //����� ������
			dialog.text = "�� ��������� ���� ����� ������, ������ � ������� ����. ��� ���� ������, �������, � ������� �� �������� �����������!";
			link.l1 = "�� �� �� ���, "+GetAddress_FormToNPC(NPChar)+"! ����� �������.";
			link.l1.go = "passenger_4";
		break;
		
		case "passenger_4":
			chrDisableReloadToLocation = false;//������� �������
			DialogExit();
			npchar.lifeday = 0;
			RemovePassenger(Pchar, npchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			AddMoneyToCharacter(pchar, sti(pchar.GenQuest.Townpassenger.Money));
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterComplexReputation(pchar, "fame", 1);
			OfficersReaction("good");				
			AddCharacterExpToSkill(pchar, "Sailing", 80);
			AddCharacterExpToSkill(pchar, "Leadership", 20);
			if (CheckAttribute(pchar, "GenQuest.Townpassenger.Enemycity")) AddCharacterExpToSkill(pchar, "Sneak", 50);
			sTitle = npchar.index+"Citizpassenger";
			AddQuestRecordEx(sTitle, "Citizpassenger", "3");
			CloseQuestHeader(sTitle);
			DeleteAttribute(Pchar, "GenQuest.Townpassenger");
		break;
//<-- ���������-��������
		
		//��������� �� ����������� ������
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "��������� �� ���������, "+ GetSexPhrase("��������","�������") +", ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� "+ GetSexPhrase("�������","������ ���") +" ����� ������ ���� � ������� �� ���������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����"+ GetSexPhrase("","�") +".", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;

		//��������� �� ����������� ������
		case "SoldierNotBlade":
			dialog.text = LinkRandPhrase("���� �� ������� ������������?! ���������� ������� ������!", "���������� ��� ���������� ������ ������!", "��, " + GetAddress_Form(NPChar) + ", �� ������� �����! ������� ������.");
			link.l1 = LinkRandPhrase("������, ������...", "��� "+ GetSexPhrase("�����","������") +".", "��� �������...");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("����� � ���!", "������ ���� ��� � ����!", "�����, ����� ����� �����.");
			link.l2.go = "fight";
			npchar.greeting = "soldier_common";
			NextDiag.TempNode = "First Time";
		break;

		case "pirate_fight_suka":
		dialog.text = "��� ��������!";
		link.l1 = "������, ����!";
		LAi_group_Attack(NPChar, Pchar);
		//DialogExit();
		break;

		case "pirate_fight":
			DialogExit();
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_Attack(NPChar, Pchar);
            DoQuestFunctionDelay("TownPirate_battle", 0.5);
		break;

	}
}