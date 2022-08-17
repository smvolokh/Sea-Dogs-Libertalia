#define DIPLOMAT_SUM 80000
// ���� ����
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	int iSumm = 0;
	string s1;
	
	if (!CheckAttribute(npchar, "PatentPrice"))
    {
        npchar.PatentPrice = (8000 + rand(6) * 1000);
    }
    int i;
    string attrLoc;
	ref    sld;
	
    attrLoc   = Dialog.CurrentNode;
    
    if (findsubstr(attrLoc, "SetNationPatent_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.nation = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "patent_2";
 	}
 	
 	if (findsubstr(attrLoc, "SetNationLicence_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.LicenceNation = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "NationLicenceType";
 	}

 	if (findsubstr(attrLoc, "NationLicenceType_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.LicenceType = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "NationLicenceType2";
 	}
 	
 	if (findsubstr(attrLoc, "RelationTo_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
        npchar.quest.relation      = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
		// �������� �� ��� �������
		attrLoc = "RelationAgent" + GetNationNameByType(sti(npchar.quest.relation));
		if (CheckAttribute(Pchar, "GenQuest." + attrLoc) && sti(Pchar.GenQuest.(attrLoc)) == true)
		{
		    Dialog.CurrentNode = "RelationYet";
		}
		else
		{
 	    	Dialog.CurrentNode = "RelationAny_Done";
 	    	npchar.quest.relation.summ = CalculateRelationSum(sti(npchar.quest.relation));
 	    }
 	}
 	
 	if (findsubstr(attrLoc, "CityPay_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.quest.CityIdx = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "CityInfo";
 	}
 	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
			dialog.text = "��� ������ ��� �����.";
			link.l1 = "��� ����� ����� ���� ������.";
			link.l1.go = "relation";
			link.l2 = "� ��� �����.";
			link.l2.go = "exit";

			// ���������  "��������� ���������"
			if ((pchar.questTemp.different == "GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakAgent"))			
			{
				link.l4 = "���� ���������� ������."
				link.l4.go = "D_ShipLetters_1"; 
				pchar.questTemp.different.GiveShipLetters.speakAgent = true;
			}			

			if (npchar.quest.meeting == "0")
			{
				dialog.text = "��������� �������������, � ������� ��� ���������, ������� ����� ��������� �� ��� �������� ���� ��� ����� �����������. �� �����, �����������, �� ��������, ��� ������ ������ ������� ��������, � �� �� ���������, ���� �������������� ����� ���������.";
				link.l1 = "����� ���������, ���������.";
				link.l1.go = "relation";
				link.l2 = "����� ����, � ������ ���.";
				link.l2.go = "exit";
				npchar.quest.meeting = "1";
			}

		if (pchar.questTemp.GothicSmithy == "HaryHooms")
		{
            	dialog.text = "�, �������! ���, �����, �������� ��� ����. � ���� ����, ������� ��������, �� � ����� ���������� � ��� �������.\n�� �� �������� - �� ��� ����. �� ������, ��� �������� ������ ���, ������ ��� �� - ����������������� ����.\n������, ��� ���� ������� � �������� �� ������ �����, ��� ���, �����, ��� �� ��� � ������.";
        	link.l1 = "������, � ���������� ���� ����� ������. ��������.";
        	link.l1.go = "GoToSmith";
        	link.l2 = "���������-���������, ��� ��� ��� �� ������� � ��� �� �� ��� �����?";
        	link.l2.go = "1";
		}

		NextDiag.TempNode = "First time";
		break;

		case "Second time":
            	dialog.text = "� ����� ���� ������� - ������������. �� ��������� �� ����, �������. ������� ������ ��� ������ �������� �����?";
        	link.l1 = "��, ��� �������.";
        	link.l1.go = "Exit 2";

		if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "HaryHooms_Smithy" && !CheckAttribute(npchar, "quest.HaryHooms_Smithy"))
		{
			link.l1 = "��, ���� ���� ������, ������� � �� ����� ��������.";
			link.l1.go = "HaryHooms_Smithy";
		}

		break;

 		case "Exit 2":
                                         NextDiag.CurrentNode = "First time";
		DialogExit();
		break;

		//*************************** ��������� - "��������� ������� ���������" **************		
		case "D_ShipLetters_1":
			dialog.text = "��������� �������.";
			s1 = "� ����, �� ���������� �����������, �������� ��������� ��������� ����� ������� ����������, ��� �� ���������� � ������.";
			s1 = s1 + "����� �� ����� � �� ��������� �� �������, �� ������������. ������ ������-�������� ��������� �������� ��� ������...";
			link.l1 = s1;
			link.l1.go = "D_ShipLetters_2";
		break;
		case "D_ShipLetters_2":
			s1 = "�����-�� ���������! �������������, ������� ������ ������. ��� ��, ����� ��� ����������, "+ GetSexPhrase("������","��������") +"! ";
			s1 = s1 + "��� ��� ��� ����������� ������ ����� ��������, � �, � ���� ������� ��������� ��� " + sti(pchar.questTemp.different.GiveShipLetters.price5) + " ����. ��� �������?";
			dialog.text = s1;
			link.l1 = "�������� ����������� ��������! ������� �� � "+ GetSexPhrase("��������","��������") +"!";
			link.l1.go = "D_ShipLetters_3";
			link.l2 = "�������, ���.";
			link.l2.go = "exit";
		break;
		case "D_ShipLetters_3":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price5)); 
			OfficersReaction("bad"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //������� ������ 
			AddQuestRecord("GiveShipLetters", "9");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
		
		case "relation":
			dialog.text = "������� ���������, ��� � ���� ��� ������.";
            if (ChangeCharacterNationReputation(pchar, ENGLAND, 0) < 0)
			{
				link.l3 = "� ���� ���������� � �������.";
				link.l3.go = "RelationTo_0";
			}
			
			if (ChangeCharacterNationReputation(pchar, FRANCE, 0) < 0)
			{
				link.l1 = "� ���� ���������� � ��������.";
				link.l1.go = "RelationTo_1";
			}
			if (ChangeCharacterNationReputation(pchar, SPAIN, 0) < 0)
			{
				link.l2 = "� ���� ���������� � ��������.";
				link.l2.go = "RelationTo_2";
			}

			if (ChangeCharacterNationReputation(pchar, HOLLAND, 0) < 0)
			{
				link.l4 = "� ���� ���������� � ����������.";
				link.l4.go = "RelationTo_3";
			}
			if (ChangeContrabandRelation(pchar, 0) <= 5)
            {
                Link.l5 = "� ���� ���������� � ����������������.";
				Link.l5.go = "Contraband";
            }
            Link.l8 = "��� ����� ��������� ������.";
			Link.l8.go = "patent_0";
			
			Link.l9 = "���� �������� ��������?";
			Link.l9.go = "Licence";
			
			if (isHeroOwnCity(true))
			{
				Link.l10 = "� ���� ������, ��������� � ��������������� ���������.";
				Link.l10.go = "City_Buy";
			}
			
			link.l99 = "������, � �����, ��� �������� ������ ������.";
			link.l99.go = "exit";
		break;
		
		case "Licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� � ������ ������� ��� ������������, ��� ���� �������� ������� ����� ������, ������� � ����������� ������������ ������������ ���������� �� ���� ���� �������� ��������, � ������ - ������� ����������� �������� � ��������� �������� �������� ����� �����\n� ������ ��������� ������ ����� ���� �������� ����� ���������� ������������. ����� �� �������� ���������, ���� �� �����-�� ��������, ������� �����, �������� � �������� � ����������. ��� �������?";
				link.l1 = "����������. � ����� ��� � ��������.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� ����� ���� �� ������ �������� ��������?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;

		case "licence_0":
			dialog.text = "�������� ���� ����� ������������������ ����� � ����� ���� ����� �����, ��������� ������������ ���� ������ ��������� � ��������� ���� ������ �������� - ���������. ������ ���� � ��� ���� �������� � ������� � ��� ������, � ���� ������� �� �������� �������, �������� ��� �� �������. ����� ���� - � ��� �� ������ ������. ������ ���\n���� �� ����������� ��������� � ���������� ��� �������� - �� �������� ����� ������ � ���� ������� ������������� ���� - ��� ������� ��� �� �������� �������, ��������� �������� ������ � ������� � ������� ����� ���������� ������� ��������, � ������ ����� �����������\n��, ���� �� �����: �������� ����������� ��������, ������ �� �������� ������������ ������������� �������� ���������... ��, ������, ��������, ��� ���������. �� ����� ���� �� ������ �������� ��������?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
				
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			//npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*1000;
			// ������� � ���������
			npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "�����, ����������, �������� �����, �� ���������� � �� �������. � ��� ����� ���������. ��� �� ������� ���� ��� ����� ��������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "����������� ����, �� ������� �� ������ �������� - �������� ����. �� ������� ����� ��� �������� - �� ��������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "������������ ����, �� ������� �� ������ �������� - �������. �� ������� ����� ��� �������� - �� ��� �����������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "�� "+FindRussianDaysString(sti(fQty))+"? ������. ��������� ����� �������� �������� "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";
			//if (sti(pchar.money) >= sti(npchar.quest.lcc_summ))
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "��, �������, ����������.";
				link.l1.go = "licence_2";
			}
			link.l2 = "� ���������, � ���� ��� ������ � ����� ������� �����. � ����� � ��� �� ��������� �����.";
			link.l2.go = "exit";
		break;

		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			//AddMoneyToCharacter(pchar, -sti(npchar.quest.lcc_summ));
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "���, ���� ������... ������ �������� ������� � ������... ���, ������. �������� ��� ��������.";
			link.l1 = "�������! �� ��������, �����.";
			link.l1.go = "exit";
		break;
		
        case "No_money":
			dialog.text = "�������! ���������� �� ���, ����� ����� ������ �����.";
			link.l1 = "������.";
			link.l1.go = "exit";
		break;
		
        case "patent_0":
			dialog.text = "������������! ��� ����� �� ������ �������� ���� ����������� �������" + 
                          " ����������� �������. ������������� � ������ �����������" + //NationNameGenitive(sti(NPChar.nation)) +
                          " � ��������� ��� ��� �������. ����� ����� �� ������ ��� ������.";
			link.l1 = "�������, "+GetAddress_FormToNPC(NPChar) + ", � ����� ���-������ ������ ��� ������������? ";
			link.l1.go = "patent_1";
			link.l2 = "��������, "+GetAddress_FormToNPC(NPChar);
			link.l2.go = "exit";
		break;
		
		case "patent_1":
			dialog.text = "�� ������ � ���� ������ ������������ ����!? ������, ����� � ����� ��� ������ ���?";
			link.l1 = "������!";
            if (GetCharacterSkillToOld(PChar, SKILL_FORTUNE) > rand(11) || bBettaTestMode)
            {
			    link.l1.go = "patent_2_give";
			}
			else
			{
                link.l1.go = "patent_2_none";
			}
			link.l2 = "���. ����� ��������, "+GetAddress_FormToNPC(NPChar);
			link.l2.go = "exit";
		break;
		
		case "patent_2_none":
			dialog.text = "� ������ ������ � �� ���������� ������ �������, ����� ��������� ������ ����� ������� �� ����� �������� � ���������.";
                                                              link.l1 = "����. ��������, "+GetAddress_FormToNPC(NPChar);
			link.l1.go = "exit";
		break;
		
		case "patent_2_give":
			dialog.text = "������, � ����� ��� ��������. ����� ������ ��� �����?";
			if (GetPatentNation() != ENGLAND)
			{
			    link.l1 = "������";
				link.l1.go = "SetNationPatent_0";
			}
			if (GetPatentNation() != FRANCE)
			{
			    link.l2 = "�������";
				link.l2.go = "SetNationPatent_1";
			}
			if (GetPatentNation() != SPAIN)
			{
			    link.l3 = "�������";
				link.l3.go = "SetNationPatent_2";
			}
			if (GetPatentNation() != HOLLAND)
			{
			    link.l4 = "���������";
				link.l4.go = "SetNationPatent_3";
			}
			link.l9 = "������, � �����, ��� �������� ������ ������.";
			link.l9.go = "exit";
		break;
		
		case "patent_2":
                                          //pchar.PatentPrice = 8000 + (sti(NPChar.PatentPrice) * sti(pchar.rank));
		pchar.PatentPrice = 350000 - GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) * 100 + (5000 + rand(1000)) * sti(pchar.rank) * MOD_SKILL_ENEMY_RATE;
            switch (sti(NPChar.nation))
            {
			    case PIRATE :
                    dialog.text = "����� ���, ���� ������ - �������� ALexusB";
                    link.l1 = "�������� �����������. � "+ GetSexPhrase("��������","��������") +" �� ���� �������!";
                    break;
                case HOLLAND :
                    dialog.text = "��������� ����� ������ ������, � ��� ������ ����� ������ � ���� ������. � ��� ������ ��������� ��� ����� ���� � "+pchar.PatentPrice+" ����.";
                    link.l1 = "�������� �����������. � "+ GetSexPhrase("��������","��������") +" �� ���� �������!";
                    break;
                case FRANCE :
                    dialog.text = "������ � ����� ������� ������ ������. �� ������� ������ ������� ������. � ��� ������ ��������� ��� ����� ���� � "+pchar.PatentPrice+" ����.";
                    link.l1 = "�������� �����������! ��� �������, ���� �������! ������� � ���������!";
                    break;
                case SPAIN :
                    dialog.text = "� ������� ����� ������ � ��� ��� �� ������ ������! ������� - ����� ������� ������. ������ ��������� ��� ����� ���� � "+pchar.PatentPrice+" ����.";
                    link.l1 = "�� ���� ����������� ��� ���-�� �������! �������� ��� ������ ����� �� ��������� ��������� ��� � ����� ������� ������������������ ����!";
                    break;
                case ENGLAND :
                    dialog.text = "���� ������, ����� ������� �������-���������� ������ �������� ���� ������. � ��� ������ ��������� ��� ����� ���� � "+pchar.PatentPrice+" ����.";
                    link.l1 = "� "+ GetSexPhrase("��������","��������") +" ������ ��� ���� ������� ������, ������� �����"+ GetSexPhrase("","�") +" ������������ � ����������!!";
                    break;
			}

            if(makeint(Pchar.money) < makeint(pchar.PatentPrice))
            {
			Link.l1.go = "No_money";
			}
                                                               else
			{
			link.l1.go = "patent_3";
			}

			link.l2 = "���, ��� �� ��� ����!";
			link.l2.go = "exit";
		break;

		case "patent_3":
                                          pchar.PatentNation = NationShortName(sti(NPChar.nation));
		dialog.text = "� ���, ��� �� ������������. �� �����.";
		link.l1 = "��������, "+GetAddress_FormToNPC(NPChar);
		link.l1.go = "exit";
		AddDialogExitQuest("any_patent_take");
		break;

		case "Contraband":
			Pchar.questTemp.Relations.sum = makeint(0.3 * stf(Pchar.rank)/stf(Pchar.reputation.nobility)*DIPLOMAT_SUM);
			dialog.Text = "������. ��� ��������� � " + Pchar.questTemp.Relations.sum + " ����.";
			Link.l1 = "� ������"+ GetSexPhrase("��","��") +".";
			if(makeint(Pchar.money) < makeint(Pchar.questTemp.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Contraband_Agreed";
			}
			Link.l2 = "�������, � ���������"+ GetSexPhrase("","�") +".";
			Link.l2.go = "exit";
		break;
		
		case "Contraband_Agreed":
			dialog.Text = "������������, � ��� �����. ��� ����� ����� � ���� ����.";
			Link.l99 = "�������.";
			Link.l99.go = "exit";
			ChangeContrabandRelation(pchar, 25);
			AddMoneyToCharacter(pchar, -sti(Pchar.questTemp.Relations.sum));
		break;
        // boal <--
		case "RelationAny_Done":
			iSumm = sti(npchar.quest.relation.summ);
			dialog.text = "��-�... ���� �� ����, ��� �������. �, �������, ����� ��������� ���� ������� � ���������� � "+ XI_ConvertString(Nations[sti(npchar.quest.relation)].Name + "Abl") +", �� ��� ����� ��� ������ " + FindRussianMoneyString(iSumm) + ".";
			if(sti(pchar.money) >= iSumm)
			{
				link.l1 = "�����, � ���� ��� ����� ��� ������. ��� ��� ��� ���� ������.";
				link.l1.go = "relation3";
			}
			link.l2 = "���, ��� ������� ������� �����. ��������.";
			link.l2.go = "exit";
		break;

		case "relation3":
			dialog.text = "�������! � ���� ����������� ����� ����� ����. ������ ���� ��������, �� ��������� �������� 15 ���� ���� ���� ����� �������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(npchar.quest.relation.summ));
			ChangeNationRelationFromRelationAgent(npchar);
			attrLoc = "RelationAgent" + GetNationNameByType(sti(npchar.quest.relation));
            Pchar.GenQuest.(attrLoc) = true;
		break;
		
		case "RelationYet":
			dialog.Text = "�� ��� ��� ����� �����������. �����, ��� ������ ���� �� ��������.";
			Link.l99 = "�������.";
			Link.l99.go = "exit";
		break;
		
		case "City_Buy":
			dialog.Text = "�������������� ������ ��������� �� ������ ��������?";
			for (i=0; i<MAX_COLONIES; i++)
			{
				if (sti(colonies[i].HeroOwn) == true && sti(colonies[i].isBought) == false)
				{
					sld = GetFortCommander(colonies[i].id);
					attrLoc = "l" + i;
					Link.(attrLoc) = GetCityName(colonies[i].id) + " - " + XI_ConvertString(GetNationNameByType(sti(sld.Default.nation)));
					Link.(attrLoc).go = "CityPay_" + i;
				}
			}
			Link.l99 = "���. ������.";
			Link.l99.go = "exit";
		break;




		case "Smithy":
            	dialog.text = "�, �������! ���, �����, �������� ��� ����. � ���� ����, ������� ��������, �� � ����� ���������� � ��� �������.\n�� �� �������� - �� ��� ����. �� ������, ��� �������� ������ ���, ������ ��� �� - ����������������� ����.\n������, ��� ���� ������� � �������� �� ������ �����, ��� ���, �����, ��� �� ��� � ������.";
        	link.l1 = "������, � ���������� ���� ����� ������. ��������.";
        	link.l1.go = "GoToSmith";
        	link.l2 = "���������-���������, ��� ��� ��� �� ������� � ��� �� �� ��� �����?";
        	link.l2.go = "1";
		break;

		case "1":
            	dialog.text = "�� ������������ �������� ������ � �������� ���������, ��� � ������ ������ ���������� ����� �������� ������.\n�� ��������� ����� ������� ������, � � ��� ����� ���� ��� �������� �����������, �� ��� �� �����, ��� �� ��������� �������, ��� �� ��� ����� ��� ����, ����� ����� ����� �!\n� ���������, �� ����� ������, ��� ��� ����� ��������, ���� �� ����� ���� ��� ����, ��� �� �������� �� ��� ������ - � ������� ������� � ���� ��� ������ �� ���� ����� �������� � ��� ������ �������!\n����� �� ����� �������, �� ��� ���� ����������, � � ������, �� ����������, ������ ���, ����� � ������� ���, ��� �� ����� ����� ��� � ���� ������ � �������.\n� ������� �� ����, ������ �� ����� � ���! �����, ��� ���� ����� ������ ��� ������ ���������� � ���, ��� ���������, ���� ��������� �� ��������� ����� ���...\n��, � ������ � ����, � ���������� ������� ���������, ����� ������� � ������ ����, �, �������? ��� �� �������?";
        	link.l1 = "�� ����. ��� ������. � ����������� � ���� ����� ������. ����� ��������, ����.";
        	link.l1.go = "GoToSmith";
		break;

 		case "GoToSmith":
                                          NextDiag.CurrentNode = "Second time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_Tavern"); 
	                     sld = CharacterFromID("Abuyin");//��� ���� ������ 1 ������������
	                    sld.dialog.currentnode = "WEISSAGUNG_1";
	                    break;

	                  case "HaryHooms_Smithy":
            	                  dialog.text = "� ������, ��� �� ������?";
        	                  link.l1 = "������ �� ������... ��� ���������� ����� ������ ���� ������ ��� �����, ��������� ������ ������� � � ����� ��� ����� �� � ��������� �� ����. �������� ������� ������ �� ����, ������ ����� �� ������ ��� ��������������� - ��� ��.";
        	                  link.l1.go = "HaryHooms_Smithy_1";
	                  break;

	                  case "HaryHooms_Smithy_1":
            	                  dialog.text = "������, � �����?";
        	                  link.l1 = "��� � �������...";
        	                  link.l1.go = "exit_1";
	                  break;

		case "Exit_1":
                                         NextDiag.CurrentNode = "Second time";
		DialogExit();
		npchar.quest.HaryHooms_Smithy = "true";
		break;
		
		case "CityInfo":
            i = sti(NPChar.quest.CityIdx);
            sld = GetFortCommander(colonies[i].id);
            iSumm = TWN_CityCost(colonies[i].id);
			dialog.Text = "����� " + GetCityName(colonies[i].id) + ", ����������� " + XI_ConvertString(GetNationNameByType(sti(sld.Default.nation)) + "Gen") + ", ����� ������ ��� ����������� ������� ������ ��������� �������� " + FindRussianMoneyString(iSumm) + ".";
   			if(sti(pchar.money) >= iSumm)
			{
			    Link.l1 = "��, ���� ��� ������ ����������.";
				Link.l1.go = "City_Buy_End";
			}
			Link.l99 = "���, �������. �� ���������.";
			Link.l99.go = "exit";
		break;
		
		case "City_Buy_End":
            i = sti(NPChar.quest.CityIdx);
            TWN_RealeseForMoney(colonies[i].id, true);
			dialog.Text = "������, ���������� � ������ �����. ������� ������� ������ " + GetCityName(colonies[i].id) + " ������ �� �����.";
			Link.l2 = "�������. ����� ��������.";
			Link.l2.go = "exit";
			Link.l3 = "��� ���� ������.";
			Link.l3.go = "relation";
		break;
	}
}

