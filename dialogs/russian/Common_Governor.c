// boal 25/04/04 ����� ������ Governor
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Governor\" + NationShortName(sti(NPChar.nation)) + "_Governor.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
    
    ref offref, sld;
    int i, cn;
    int qty;
    int iSumm;
    string attrLoc;

    /// ����� �������
    ref CaptGovenor, FortColony;
    int f, colony_money;

    int k = 1000;
    if (CheckAttribute(Nations[sti(NPChar.nation)], "Fort"))
    {
        k = (300 - sti(Nations[sti(NPChar.nation)].Fort)*10);
    }
	bool ok;
	
	attrLoc = Dialog.CurrentNode;
	if (findsubstr(attrLoc, "CityGive_" , 0) != -1)
 	{
        i = findsubstr(attrLoc, "_" , 0);
	 	NPChar.quest.CityIdx = strcut(attrLoc, i+1, strlen(attrLoc)-1); // ����� � �����
 	    Dialog.CurrentNode = "ColonyGive";
 	}
 	
	switch (Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOff");
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
					LinkRandPhrase("�� ������� ������� � �������-�����������?! ������ ���...", "��� ��� ����������� ���������, ����� �� ��� �������� ����?! ��� �����������...", "�� ��, ��� ������ ��������� �����, ��� "+ GetSexPhrase("�����-�� ����������","�����-�� �����������") +" ������ � ���� ����������..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","���������") +"?! ��� ������� ��� ����� ���� ����, ������ ���� �� ����, "+ GetSexPhrase("������� �����","��������") +"!", ""+ GetSexPhrase("�������","�������") +" ������, ��� �� ���� ����������! ������!!", "� �� ����� ����, "+ GetSexPhrase("��������","��������") +"! ����� ���� ������� � �����, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("�������� ���� ���� �����...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, ��������, � �� �� ����� ���� ������� ����!", "��� ��� � ���� �����, ��������: ���� ����, � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "� ������, ��� �� ����� ���������� ������� ���������. ���� ����� " + GetFullName(npchar) +
                              ". � �������-���������� ������� " + NationNameGenitive(sti(NPChar.nation))+ ", ��������� ������ " + NationKingsName(npchar)+
                              " � ���� �����. � ������ ������������� �������� ���� ������ ������, " + GetAddress_Form(NPChar) + ".";
				link.l1 = "��� ��� " + GetFullName(pchar) + ".";
				link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = RandPhraseSimple("�, ��� ����� ��? �� ������ ������� ��� ����������� �������-���������� " + NationNameGenitive(sti(NPChar.nation))+ " �� ���� ���?",
                              "����� ��������� ���� �� ������ ��������������� ���? ��� ��� ������, " +GetAddress_Form(NPChar)+"?");
				link.l1 = "� ���� ���������� � ������ �� ����� ������ " + NationNameGenitive(sti(NPChar.nation));
				link.l1.go = "work";
				link.l2 = "����� ���������� � ���� �� ����� ����.";
				link.l2.go = "quests"; // ���� �����
				//Jason --> ������
				if (CheckAttribute(pchar, "questTemp.Regata.ToPortRoyal") && NPChar.location == "Portroyal_townhall")
				{
					link.l3 = "� ������ �� ����������� ��� ������� � ������. ��� ��� �����������.";
					link.l3.go = "Regata";
				}
				//<-- ������
				link.l10 = "����� ��������, �� ���� ���� ����.";
				link.l10.go = "exit";
			}
		break;
		
		case "node_1":
			dialog.text = "��� ����� ������� ��������� ��� ������ ���� � ��������� ���� �� ������ ��������������� ���?";
			link.l1 = "� ���� ���������� � ������ �� ����� ������ " + NationNameGenitive(sti(NPChar.nation));
			link.l1.go = "work";
			link.l2 = "����� ���������� � ���� �� ����� ����.";
			link.l2.go = "quests";
			//Jason --> ������
			if (CheckAttribute(pchar, "questTemp.Regata.ToPortRoyal") && NPChar.location == "Portroyal_townhall")
			{
				link.l3 = "� ������ �� ����������� ��� ������� � ������. ��� ��� �����������.";
				link.l3.go = "Regata";
			}
			//<-- ������
			link.l10 = "��� ������ ����� ���������� � ������ �����, "+GetAddress_FormToNPC(NPChar);
			link.l10.go = "node_2";
		break;

		case "node_2":
			dialog.text = "� ����� ������, � ������� ��� �������� ��� ������� � �� ������ ��� ��������.";
			link.l1 = "��, ��, �������, ��������, ��� ����������"+ GetSexPhrase("","�") +" ���.";
			link.l1.go = "exit";
		break;
		
		case "work":
            dialog.text = "�� ������ ������ ����������� � ������������ �������. �� ��������� ��������� ��������� � �������� ��������.";
			link.l1 = "����� � ��������. �������.";
			link.l1.go = "exit";
		break;
		
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
			dialog.text = "����� ������. ���� �� �������� - ���� ������ �������� � ���, ������ � ����������� �������. ������ ��� ����� ������� ������������ � ��������� ������\n��� ����������� ������� � ���� ����� ����������, �� ������ ���������� � ������� ����������. �������� � ���� - �� ��� ��� ��������.";
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
			link.l1 = "� �������. ���� � ��� �� ������, � ��������, ��� ����� ������.";
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
			dialog.text = "������ �������� � ����� �������� ��� ��� ����� - ��������� �������. ����, �������� �������������� �� ������ ���������� 250 000 ����. �������� ��������!";
			link.l1 = "���������!";
			link.l1.go = "Regata_complete_1";
		break;
		
		case "Regata_complete_1":
			AddMoneyToCharacter(pchar, 250000);
			int iGift;
			string sItem1, sItem2, sItem3, sAdd;
			if (sti(pchar.rank) < 6) iGift = 0;
			if (sti(pchar.rank) >= 6 && sti(pchar.rank) < 13) iGift = 1;
			if (sti(pchar.rank) >= 13 && sti(pchar.rank) < 20) iGift = 2;
			if (sti(pchar.rank) > 20) iGift = 3;
			switch (iGift)
			{
				case 0:
					sItem1 = "blade_10";//����
					sItem2 = "cirass6";
					sItem3 = "bussol";
					sAdd = "����, ����� ������� � �������";
				break;
				
				case 1:
					sItem1 = "blade_15";//��������
					sItem2 = "cirass2";//���������� �������
					sItem3 = "bussol";
					sAdd = "��������, ���������� ������� � �������";
				break;
				
				case 2:
					sItem1 = "blade_17";//������
					sItem2 = "cirass7";//��������
					sItem3 = "bussol";
					sAdd = "������, �������� � �������";
				break;
				
				case 3://
					sItem1 = "blade_20";//�������
					sItem2 = "cirass2";//���������� ������
					sItem3 = "bussol";
					sAdd = "'�������', ���������� ������ � �������";
				break;
			}
			GiveItem2Character(pchar, sItem1);
			GiveItem2Character(pchar, sItem2);
			GiveItem2Character(pchar, sItem3);
			dialog.text = "����� ��� ������� �������� ������ ������: "+sAdd+". ������ ��� ��� - ����.";
			link.l1 = "����� ���, ���. �����, ���� �� ������.";
			link.l1.go = "Regata_complete_2";
		break;
		
		case "Regata_complete_2":
			dialog.text = "�� ���� ���� ������� ���������� ������� ��������� ��� �� ������� � ������, � ��� ��� ���������� � �������! ���� �� ������� ������ - ����� ����� ����� � ���� ����� ���������� � �������� ���� �������, ���� �� ����� ��� �� �������. ����� ��� �����, �������!";
			link.l1 = "������� �� ������ �����, ���! � ���� ������� ��������� ��� �� ��, ��� ���� ��� ����������� ����������� � ���� ������������ �����������. � ������ ��������� �����������.";
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
			dialog.text = "���?! �������� ���� �����?! ��, ���������� ������! ���� �� ���� �����, ��� �� ���� ������ ��� ��������! �������� "+ GetSexPhrase("����� ����������","��� ��������") +"!";
			link.l1 = "������! � ����� ���� "+ GetSexPhrase("���������","���������") +", � �� ���� �������� �� ���������� ������!..";
			link.l1.go = "Andre_Abel_Quest_Hol_Gov_Node_4";
		break;
			
		case "Andre_Abel_Quest_Hol_Gov_Node_4":
			dialog.text = "�� ������� �������, � ������ �� "+ GetSexPhrase("�����","�������") +". ����� ����������!.. � ������� "+ GetSexPhrase("���","��") +"!";
			link.l1 = "�� ��� ����� ������ �����!!!";
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
			dialog.text = "������������? ��... ��, ���� ���� ��� � �����, ������ " + iSumm + " ��������, �� � ����� ���������� ������.";
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

	}
}