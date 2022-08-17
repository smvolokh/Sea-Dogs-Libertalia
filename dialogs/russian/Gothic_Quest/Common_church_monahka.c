// boal 25/04/04 ����� ������ �������
#include "DIALOGS\russian\Rumours\Common_rumours.c"  //homo 25/06/06
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Church\" + NPChar.City + "_Churchwoman.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
	
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 16/06/06
    
    string iDay, iMonth, lastspeak_date, eggStr;
    string sTemp, sTitle;

	iDay           = environment.date.day;
	iMonth         = environment.date.month;
	lastspeak_date = iday + " " + iMonth;
	int iMoneyToCharacter;

	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	case "Exit_1":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		Log_info("������ �� ���� ��� �����... � ����� ������ � ���� ���� �������!");
		pchar.questTemp.ShipCapellan = "true"; 
		pchar.questTemp.ShipCapellan.id = pchar.id;
		pchar.questTemp.ShipCapellan.Yes = "true";
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase(""+ GetSexPhrase("��� ���","���� ���") +", � ���������, � �� ���� ���� ���� �������. ����!", "��� ��������� ������ ����� �� ������ � ������� ����, "+ GetSexPhrase("��� ���","���� ���") +". ������� ������� ��� ����������, �� � �� ���� ������������ ���� �������...", ""+ GetSexPhrase("��� ���","���� ���") +", ���� ���� ������! ����� ����, �� ����� � ����!"), 
					LinkRandPhrase("��� �� ������� � ������, ������ ����? � ������, ����� �� ������"+ GetSexPhrase("��","���") +" ����������, ���� ������� �� ��������� � �� �������� ����� �����!", "���������� ������ ����, ��������"+ GetSexPhrase("�","��") +"! � �� ���������� �� ���"+ GetSexPhrase("���","��") +", ��� ��!", "���������� ������ ���� �����, " + GetSexPhrase("������","������") + "! ��� �� ����� ����� ��������!!"));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("�� ����� ����, ������...", "�� �� ����� ��� ���� ������..."), 
					LinkRandPhrase("������, ����� �� ������� ��� ������...", "����, �� ����������...", "������, �� �������, �� �� ����, �� ����"));
				link.l1.go = "fight";
				break;
			} 
            if (npchar.quest.BadMeeting != lastspeak_date)
			{
				if(!CheckAttribute(PChar, "") && !CheckAttribute(PChar, "") && NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam != iMonth && NPChar.GenQuest.ChurchQuest_2.GiveQuestDay != lastspeak_date && NPChar.location != "Panama_church" && NPChar.location != "Minentown_church" && rand(5) == 1 && !CheckAttribute(pchar, "questTemp.Sharlie.Lock")) // 280313
				{
					dialog.text = "...����� ������ �� � ������ ��������! �� ������ ��...";
					link.l1 = RandPhraseSimple("��! �� �������"+ GetSexPhrase("","�") +", ������?", "��� ��� ����!");
					link.l1.go = "GenQuest_Church_2_Start_1";
					NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth; // ���������� ����� �� ���� ���� � �����
					break;
				}


				Dialog.Text = "����� ���������� ��� ���� ������ �������, "+ GetSexPhrase("��� ���","���� ���") +".";
				link.l1 = "������������, ������.";
				link.l1.go = "node_3";
				Link.l2 = "�� ��� �� ������, � �� ���� ��� ������ ����������.";
				Link.l2.go = "node_2";
				NPChar.GenQuest.ChurchQuest_2.GiveQuestDay = lastspeak_date;	// ���� �� ��� �������, �� ���� �� ���� ����.
			}
			else
			{
				Dialog.Text = "������ ���� �������, ����������"+ GetSexPhrase("�","��") +"! ��� � ����� �� � ��� ��������!";
				Link.l1 = "�� �����-�� � ��������.";
				Link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "node_2":
			dialog.text = "��, �� ����������"+ GetSexPhrase("�","��") +"! � �� ����� ������, ���� �� ���������� ����� ������������ ���� �����!";
			link.l1 = "�� � � ��� �� �������"+ GetSexPhrase("��","���") +" ����� �������������.";
			link.l1.go = "exit";
			ChangeCharacterComplexReputation(pchar,"nobility", -0.25);
			npchar.quest.BadMeeting = lastspeak_date;
		break;

		case "node_3":
			dialog.text = "�� ����������� ������� ��� � ���� ����... �� ������ �� ��� � �����-�� �����?";
    		link.l1 = RandPhraseSimple("� ���� ������ �������������.", "���� ������������ �� ������ ����.");
    		link.l1.go = "donation";
    		link.l2 = RandPhraseSimple("�����, ������� ����� ��������.","��� ����� ���������, "+RandPhraseSimple("������.", "������ ������."));
    		link.l2.go = "ispoved";
    		link.l3 = RandPhraseSimple("� ���� � ��� ����, " + RandPhraseSimple("������.", "������ ������."),
                                           "� ������"+ GetSexPhrase("","�") +" �� ����, " + RandPhraseSimple("������.", "������ ������."));
    		link.l3.go = "work";
			

			
			// Warship, 30.05.11. ��������� �� ��� ����� "����� ���".
			if(CheckAttribute(Pchar, "QuestTemp.AffairOfHonor.GodJudgement.CanSpeakPriest") && AffairOfHonor_GetCurQuest() == "GodJudgement" &&
				NPChar.city == PChar.QuestTemp.AffairOfHonor.GodJudgement.CityId)
			{
				link.l5 = "�������� ���� ��������, ������ ������.";
				link.l5.go = "AffairOfHonor_GodJudgement_1";
			}
			
			link.l6 = "��������, ��� ���� ����.";
			link.l6.go = "exit";
		break;

		case "AffairOfHonor_GodJudgement_1":
			dialog.text = "�� ����������, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ". ������� ������ ���� ��������� � ������� ����. ������ ���� � ����� ����� ��� ���������� ����.";
			Link.l1 = "��������� ���, ������ ������.";
			Link.l1.go = "exit";
			AddItems(PChar, "amulet_3", 15);
			DeleteAttribute(Pchar, "QuestTemp.AffairOfHonor.GodJudgement.CanSpeakPriest");
		break;
		
		
		// Church GenQuest_2 -->	
		case "GenQuest_Church_2_Start_1":
			dialog.text = "...� ������� ������! �� �������� �� ���� ���� ���������� �� �����������...";
			link.l1 = LinkRandPhrase("������ ������", "������", "��������� ������") + ", �� ������� �� �� ������������? ��� ������� � ���� ��������.";
			link.l1.go = "GenQuest_Church_2_Start_2";
			link.l2 = RandPhraseSimple("�-�... �� ���� ��� ������...", "�, �������, �� ������� - �����, �������...");
			link.l2.go = "exit";
		break;
			
		case "GenQuest_Church_2_Start_2":
			dialog.text = "�, "+ GetSexPhrase("��� ���","���� ���") +", ��������� ������� ���������, ����������� �� ������������! ��������� �������!!! �� ��� ��� �����, ��� ��������� ���� ������� ���� ����� � ������ �������!";
			link.l1 = "��, ��� ��� ���!.. � ��� �� ��� ���������?";
			link.l1.go = "GenQuest_Church_2_Start_3";
			link.l2 = LinkRandPhrase("��� ���, �������, ��������, �� �, �������, �����...", "����������, ������, �� ��� ��� ����...", "�������� �� ������� ����������� �� �������, ����� ���� ����� ������� ��������. ����� �, �������...");
			link.l2.go = "exit";
		break;
			
		case "GenQuest_Church_2_Start_3":
			dialog.text = "�����-�� �������� ��� �������� ���� ������� ���, ��� ���� ������� �������! � ���������� ���� ����������, ����������!";
			link.l1 = "�� ��, �������... ��, � �������, �� ����������� �����-�� ���� �� ������� ������?";
			link.l1.go = "GenQuest_Church_2_Start_4";
		break;
			
		case "GenQuest_Church_2_Start_4":
			dialog.text = "� ��! �������!! � ������� ����������� ���������� �� ������! � ������ ������ �� ���� �������.";
			link.l1 = "�� ����������, ��� ��� ����� ����������� ����. �� � ����"+ GetSexPhrase("","�") +" � ���� ����� ����� ����������. ������������ ������, � �������.";
			link.l1.go = "GenQuest_Church_2_Start_5";
		break;
			
		case "GenQuest_Church_2_Start_5":
			dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +", ��� ����� ������� ���������, ��������� ������ ������������� ���? ��� ������� ��������� ��� ������ ������ - ��������� � ��������  ������������, ��� ��������� �������� � ���������� � �������� �������! �������, ��� �� � ������ �����!";
			link.l1 = RandPhraseSimple("��, � ������"+ GetSexPhrase("","�") +", ��� ����� ����� ������� ���������������, ������ ��������� �� ���. �������, �� ���� ��� ������. ����� �������.", "��, �� ��� ���� ��� ���� ��� ������ ������� ����������� � �������� - �� ������ ������ � � �� �� �������"+ GetSexPhrase("��","���") +". �������, ��� ��� ����. ����� ������� � ����� ������� �����.");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("������ ������", "������", "��������� ������") + ", �� ���� � �������� ������� �� ������"+ GetSexPhrase("","�") +", � � ����������� ������ ������� ���������� ��� ���������.";
			link.l2.go = "GenQuest_Church_2_Start_5_1";
		break;
		
		case "GenQuest_Church_2_Start_5_1": //���� - ����� �� ������� ��� ������������� - �������, ������
			dialog.text = "� ���� �������� �� ����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + "! ��� � ������ ���� ���������� �� �������!";
			link.l1 = "������ �� �����������, " + RandPhraseSimple("������.", "������ ������.");
			link.l1.go = "GenQuest_Church_2_Start_6";
		break;
			
		case "GenQuest_Church_2_Start_6":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PChar.GenQuest.ChurchQuest_2.StartQuest = true;
			PChar.GenQuest.ChurchQuest_2.QuestTown = NPChar.City;	// �����, � ������� ����������
			PChar.GenQuest.ChurchQuest_2.QuestTown.PriestName = NPChar.name;
			PChar.GenQuest.ChurchQuest_2.IslandId = locations[FindLocation(NPChar.location)].islandId; // �� ����� ������� ���������� ��������
			PChar.GenQuest.ChurchQuest_2.Nation = sti(NPChar.nation);
			PChar.GenQuest.ChurchQuest_2.AskPeople = true;
			PChar.GenQuest.ChurchQuest_2.AskBarmen = true;
			PChar.GenQuest.ChurchQuest_2.AskAlcash = true;
			PChar.GenQuest.ChurchQuest_2.MoneyCount = (sti(pchar.rank)+8)*543+3210;
			PChar.GenQuest.ChurchQuest_2.MoneyToCharacter = makeint(sti(PChar.GenQuest.ChurchQuest_2.MoneyCount)/3);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			ReOpenQuestHeader(sQuestTitle);
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "1");
			AddQuestUserDataForTitle(sQuestTitle, "sCity", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
		break;
			
		case "GenQuest_Church_2_Thief_2":
			dialog.text = "��, ����� ��������� ��������� ����� ��� � ���� �� ���������� ����� �����, ���� �������� �� ����� �� ������...";
				link.l1 = "��������, �� �������, ���, ��������, ��������... ��� ��� �� ��� ����������, ������?";
				link.l1.go = "GenQuest_Church_2_Thief_3";
			break;
			
		case "GenQuest_Church_2_Thief_3":
			if(rand(1) == 0) // ��������� �������� ������������...
			{
				dialog.text = "������� ������... ������� ��, ��������... �� �����... ����������? �� �� �����?";
					link.l1 = "��� ������ ������ ���������, ������� �������� ������� ������� ����������� � ������������: �� ����, �� ������, �� ��������� ���������������� ������ �������� ������. ����� ����� �������� �� �������������� �������? � �� ��� �����, �������� �������?!..";
					link.l1.go = "GenQuest_Church_2_Thief_4_1_1";
			}
			else
			{
				dialog.text = "����� ����� �����... ��� �� ����� ����������? �� �� �����?..";
					link.l1 = "��� ������ ������ ���������, ������� �������� ������� ������� ����������� � ������������: �� ����, �� ������, �� ��������� ���������������� ������ �������� ������. ����� ����� �������� �� �������������� �������? � �� ��� �����, �������� �������?!..";
					link.l1.go = "GenQuest_Church_2_Thief_4_2_1";
			}
		break;
			
		case "GenQuest_Church_2_Thief_4_1_1":
			dialog.text = ""+ GetSexPhrase("��� ���, ������","���� ���, ��������") +"... ������� ������... ����� ������, ����� ���������... ���� �������, ����! �� ������... ����� ���� �� �������... ����������� �������� �������, �������� ��������, �������� ������� ����... ��������� ����� �, �����������, ������ ������ �� ����� ���� - ����� ���� �������� �� ����������, ������� ��� �� ����, �������� ���������...";
			link.l1 = LinkRandPhrase("������ ������", "������", "���� ������") + ", �����������. �������, ��� ��� ������ ������ �� ����������... � �� ���������. ������, ��� ����������� ������ ��� ���� ��� ���������, ������� � ��� � ������"+ GetSexPhrase("","��") +".";
			link.l1.go = "GenQuest_Church_2_Thief_4_1_2";
		break;
			
		case "GenQuest_Church_2_Thief_4_1_2":
			dialog.text = "��������� ����, ����! �������� ������� ������������ ����, ������������� ��������, ���������� � ������� � ������...";
			link.l1 = "���������� ����� ������... ������, ���� ���� ��������� ���������, � ����� ���: ������� �� ��������, � ��������� �������. ���� �� ������ ��� ���, ������ �� ����� ������ �� �����. � �� ���������� ��� ��� �� ������ �������, ��� �� ������ ���� � ����� � ��� �������...";
			link.l1.go = "GenQuest_Church_2_Thief_4_1_3";
		break;
			
		case "GenQuest_Church_2_Thief_4_1_3":
			if(rand(1) == 0) // ��������� ����� ������� �� �����
			{
				dialog.text = ""+ GetSexPhrase("��� ���","���� ���") +"... �� ������� ��������� � ������������� �������� �� ��� ����. ������� � ������������ ����� ���� �������� ����. �� ����� ������ ������������ ��� � ������ ������� ��� �������� �������������� � ������� " + FindRussianMoneyString(iMoneyToCharacter) + "... �������, ��� ������ ���� �������?";
				// �� �� ����� ������. �������� ����
				link.l1 = "��� ������, ������ " + NPChar.name + ". � � ��� �����"+ GetSexPhrase("��","��") +", � ��� ������ ����������� �� ����� ����� ��������.";
				link.l1.go = "GenQuest_Church_2_Thief_4_1_4";
				// �� ����� ������
				link.l2 = "���������, " + LinkRandPhrase("������ ������", "������", "���� ������") + ", ����� ������ ����������.";
				link.l2.go = "GenQuest_Church_2_Thief_4_1_5";
			}
			else
			{
				dialog.text = ""+ GetSexPhrase("��� ���","���� ���") +"... �� ������� ��������� � ������������� �������� �� ��� ����, ��� ���� ������ ������� � ��������. ������� � ������������ ����� ���� �������� ����. �� ����� ������ ������������ ���!";
				link.l1 = "������� �� �������������, " + LinkRandPhrase("������", "���� ������") + ".";
				link.l1.go = "GenQuest_Church_2_Thief_4_1_4";
				link.l1 = "�������������, �������, ���� ������, �� ������� �� ���������� ��� ���-�� ����� ������������, ��� ��� � ������ � �����"+ GetSexPhrase("","��") +" ������� �����...";
				link.l1.go = "GenQuest_Church_2_Thief_4_1_6";
			}
			ChurchGenQuest2_RemoveCup();
		break;
			
		case "GenQuest_Church_2_Thief_4_1_4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", 3);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_1");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("c�","���"));
			AddQuestUserData(sQuestTitle, "sCity", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_1_5":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(PChar, sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter));
			ChangeCharacterComplexReputation(PChar,"nobility", -2);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_2");
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_1_6":
			iMoneyToCharacter = sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter);
			dialog.text = "��, ���� ��, ������ ������... �������, ��� �������� ����� � ������� " + FindRussianMoneyString(iMoneyToCharacter) + " ������ ���� �������?";
			link.l1 = "��, " + LinkRandPhrase("������", "���� ������") + ", �������.";
			link.l1.go = "GenQuest_Church_2_Thief_4_1_6_1";
		break;
			
		case "GenQuest_Church_2_Thief_4_1_6_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -2);
			AddMoneyToCharacter(PChar, sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter));
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_3");
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_2_1":
			dialog.text = "� �� ������� ����� ������, "+ GetSexPhrase("��� ���","���� ���") +", � ��� ��� �� ��������?!";
			link.l1 = "� ������ � �������� �����, ������� �������� ��������� � ��������� ��������. � �� ���� ���� ��� ���������, ������� � �������"+ GetSexPhrase("","�") +" �� ����������, ����� ���������� ���� �������... �� ���-�� ������ �������?";
			link.l1.go = "GenQuest_Church_2_Thief_4_2_2";
		break;
			
		case "GenQuest_Church_2_Thief_4_2_2":
			dialog.text = "� �����, ���� ��, ��� �� ������ ������������� � ����� ��������� ������, � ��� �� ������ �� ���� ��������. � ��� ���� � ������� ����, �� ���� �� ������� ������������ � � ������ �������, ��...";
			link.l1 = "�������, ������, �� � �� ��������, ���� �� �����������.";
			link.l1.go = "GenQuest_Church_2_Thief_4_2_3";
		break;
			
		case "GenQuest_Church_2_Thief_4_2_3":
			if(rand(1) == 0) // ������ ��������� ������ �������� �������
			{
				dialog.text = "��� � ������ ��� ���������?! �� �� "+ GetSexPhrase("����� �������","����� �������") +", � ���� ������ �������� - ��, ��� ���������� ��� ���������� � ���, ��� � �� ����� ������ - ��� �� ������ ����! ������� �������� ���� ����������� �� ������ �� ���������, �� � �� ����������������!";
				link.l1 = "�������� ������� � �����! ������ �� ������, ��� ������� ��� �� ����������, �� ������� �� ���� ���������? �����, � ����"+ GetSexPhrase("","�") +" �� ������, ��� ��� ������ �������� � ����� ������� ��������?";
				link.l1.go = "GenQuest_Church_2_Thief_4_2_4_1";
			}
			else
			{
				dialog.text = "��� �� � ��� � ���� ��������, �� �� ��������� �������������, ������� ����� ����� �������, �������������� � �����, ��������� ������������� ����������, �������� ��������� �������, ������� ���������� ���������� ����� ����! � ����������� ����, ��� � �� ���� �����������, ����� ��������� ��� � ��������!";
				link.l1 = "��� �... � ����, �� �������� � ����� ���������, ��� �� ������� �������� ����. �� ���� ������ ���, ����� ������� ��� �� ���� ��� ������ ����������. �������� ���� '��������� ������' � ��������� � ���, �������� �� �� ����������� � ���, ������ " + NPChar.name + ".";
				link.l1.go = "GenQuest_Church_2_Thief_4_2_4_2_1";
				link.l2 = "�������� ��� ��������, ������ ������, ��� ������ ������������ �����, � ���� � ��������. �������� ���� � ������������ ����.";
				link.l2.go = "GenQuest_Church_2_Thief_4_2_4_2_2";
			}
		break;
			
		case "GenQuest_Church_2_Thief_4_2_4_1":
			dialog.text = "�-�-�... "+ GetSexPhrase("��� ���... ������... ��������","���� ���... ��������... �������") +" " + PChar.name + "... � ������ ����� ��� ���������... ����������� ���� �����������.... �������������� ���� �������� ������� ��� ���� �������� ������ � ������� " + FindRussianMoneyString(iMoneyToCharacter) + "... �������, � ��� ������, ���� �� �� ������� ��������� � ��� ���� �����������...";
			// ��� ���� �������� ���� �������
			link.l1 = "� ������ �� ��������� ���������. ��������� ����! � �� �������, ��� � ������ ������, ������� �� ������ �������� �� �������� ����� ��������!";
			link.l1.go = "GenQuest_Church_2_Thief_4_2_4_1_1";
			// ��� ���� - ��������
			link.l2 = "� ������ �� ��������� ���������. �������� ����! ��� ������ � ���� ���� ������, ��� ��������"+ GetSexPhrase("","�") +" �� ��� ������� ����� ������� � �����, �� ����� �� ������������ �� �������� ������������� � ���!";
			link.l2.go = "GenQuest_Church_2_Thief_4_2_4_1_2";
		break;
			
		case "GenQuest_Church_2_Thief_4_2_4_1_1":
			DialogExit();
			iMoneyToCharacter = PChar.GenQuest.ChurchQuest_2.MoneyToCharacter;
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -2);
			AddMoneyToCharacter(PChar, sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter));
			ChurchGenQuest2_RemoveCup();
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_5");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","��"));
			AddQuestUserData(sQuestTitle, "sSex1", GetSexPhrase("","�"));
			AddQuestUserData(sQuestTitle, "sSex2", GetSexPhrase("","��"));
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
			AddQuestUserData(sQuestTitle, "sMoney", FindRussianMoneyString(iMoneyToCharacter));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_2_4_1_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", 3);
			ChurchGenQuest2_RemoveCup();
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_4");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_2_4_2_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChurchGenQuest2_RemoveCup();
			ChangeCharacterComplexReputation(PChar,"nobility", 3);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_6");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","��"));
			AddQuestUserData(sQuestTitle, "sSex1", GetSexPhrase("","�"));
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Thief_4_2_4_2_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChurchGenQuest2_RemoveCup();
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_7");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sQuestTitle, "sCity", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1":
			// ������ �� �������� ����������.
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.Complete.Without_All"))
			{
				link.l1 = "�������� ��������������, " + LinkRandPhrase("������ ������", "������", "���� ������") + ": ��������� ��������� ����� ������� � �����������, ��� ��� �� ������� ������� ��������� ������...";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_1_1";
				break;
			}
			// �������� ���������� ������ ����.
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.Complete.Only_With_Cup"))
			{
				link.l1 = "�������� ��������������, " + LinkRandPhrase("������ ������", "������", "���� ������") + ": ��� ������� ������� �����������, �� ���� ������������ ������� ��������� ��� ��� ���� ��� ���������.";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_4_1";
				ChurchGenQuest2_RemoveCup();
				break;
			}
			// �������� ���������� � ������ � ����.
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.Complete.With_All"))
			{
				if(sti(PChar.money) >= sti(PChar.GenQuest.ChurchQuest_2.MoneyCount))
				{
					link.l1 = "������"+ GetSexPhrase("","�") +", ��� �������� ��� �������� - � �������� �������"+ GetSexPhrase("","�") +" ���������� � ������"+ GetSexPhrase("","�") +" � ��� ���������� ������, � ����� ��� ��� ���� ��� ���������.";
					link.l1.go = "GenQuest_Church_2_Finally_Complete_1_2_1";
				}
				// ������ ����� ��������.
				link.l2 = LinkRandPhrase("������ ������", "������", "���� ������") + ", � ������"+ GetSexPhrase("","��") +" ������ �����... ��� �������� ��������� ����� �������, ��� � �������, ����� ��������� ���������, ��, ����� � ��-���� ������"+ GetSexPhrase("��","���") +" �� ���, ���������, ��� ��� ������ ������� � ��������� ��, ����� ��� ���� ���� ��� ���������...";
				link.l2.go = "GenQuest_Church_2_Finally_Complete_1_3_1";
				ChurchGenQuest2_RemoveCup();
				break;
			}
			// ��������� - ���.
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.Complete.PriestIsThief"))
			{
				dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +", �� ��� ����� �� ���� ���������? ��� ��� ���� ����� ���������� � ������, � ��� ������ ����� - ������ �������� � ������ - ��� ����� ������ � �������� ������ ������������ ��������...";
					link.l1 = "������� ����� �� � ����� ���������� ����� ������ ���������� ���������?";
					link.l1.go = "GenQuest_Church_2_Thief_2";
				break;
			}
			// �������� ������� ����������� ������.
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.Complete.Short_With_Mon"))
			{
				if(sti(PChar.money) >= sti(PChar.GenQuest.ChurchQuest_2.MoneyCount))
				{
					link.l1 = "������"+ GetSexPhrase("","�") +", ��� �������� ��� �������� - � �������� �������"+ GetSexPhrase("","�") +" ���������� � ������"+ GetSexPhrase("","��") +" ���������� ������.";
					link.l1.go = "GenQuest_Church_2_Finally_Complete_1_2_1";
				}
				// ������ ����� ��������.
				link.l2 = LinkRandPhrase("������ ������", "������", "���� ������") + "... � ��������"+ GetSexPhrase("","�") +" ��� ��������. � �����������"+ GetSexPhrase("","�") +" ���������� �� ����� ����������, ���������"+ GetSexPhrase("","�") +" ��������� ���������� � �������, ����� �������"+ GetSexPhrase("��","���") +" � � �����-������ ������"+ GetSexPhrase("","��") +" ��, �� ���... ��� ��� ������ ��������� ��������� ������.";
				link.l2.go = "GenQuest_Church_2_Finally_Complete_1_3_1";
			}
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1": // �� ����� �������� ������...
			if(rand(1) == 0)	// ��������� ����� �� �� �� ���� �����...
			{
				if(rand(4) == 3) // ����� "������" ����� �������.
				{
					dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +". ���� ����� �������� ���� � �������� ������, �� �� � ��������, ��� �������� - �������� ����! ������� �������� �� ��� ��������� ���������, ����� �������� ���� ����.";
						link.l1 = "�����, ������ ������...";
						link.l1.go = "exit";
						sQuestTitle = NPChar.City + "ChurchGenQuest2";
						AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_9");
						AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
						CloseQuestHeader(sQuestTitle);
						ChangeCharacterComplexReputation(PChar,"nobility", -2);
						DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
						NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
				}
				else
				{
					dialog.text = ""+ GetSexPhrase("��� ���","���� ���") +", �� ��� ��������� ������� ������.";
						link.l1 = "��� ����, ����, ��, ������� ����� ������� - � ������ ������...";
						link.l1.go = "GenQuest_Church_2_Finally_Complete_1_3_1_3";
				}
			}
			else
			{
				// ��������� ���� ������ ��...
				iMoneyToCharacter = sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter);
				dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +". ���� ����� �������� ���� � �������� ������, �� �� � ��������, ��� �������� - �������� ����! ������� �������� �� ��� ��������� ���������, ����� �������� ���� ����. ������ ���� ������ � ������� ������ ���� �������������, ���� � �� �������� ������. �������� ��� ��������� ����� - " + FindRussianMoneyString(iMoneyToCharacter) + " -  � ����������� ��� ��������� ����!";
					link.l1 = "�-��!... �������, ������, � �������� ��� ������ �� ����������� ����.";
					link.l1.go = "GenQuest_Church_2_Finally_Complete_1_3_1_1";
					link.l2 = LinkRandPhrase("������ ������", "������", "���� ������") + "... �� ������� ���� � �������� ���������. � �� ���� ������� �� ��� �������������� �� ������������� ������, ����� �������� �� ��� ������ ������.";
					link.l2.go = "GenQuest_Church_2_Finally_Complete_1_3_1_2";
			}
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1_3":
			if(rand(6) == 3)
			{
				dialog.text = "������, � ���� ����, "+ GetSexPhrase("��� ���","���� ���") +". ������� ���������� ��� ���������� ���������, ����� �������� ���� ����.";
				link.l1 = "�����...";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_3_1_3_1"
				break;
			}
				dialog.text = "��������"+ GetSexPhrase("��","��") +", ������� �� �����"+ GetSexPhrase("","�") +", ��� ������"+ GetSexPhrase("��","��") +" �������� ������� ������? ���� �� �������"+ GetSexPhrase("","�") +"! �������� ����� � �����, ��� ��� ������ �� �������� ���� ������� ������!";
				link.l1 = "��� �� ���!.. ������!..";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_3_1_3_2";
			break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1_3_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "5");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			CloseQuestHeader(sQuestTitle);
			AddCharacterExpToSkill(PChar, "Sneak", 20);
			ChangeCharacterComplexReputation(PChar,"nobility", -3);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1_3_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "6");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			CloseQuestHeader(sQuestTitle);
			ChangeCharacterComplexReputation(PChar, "nobility", -6);
			AddCharacterExpToSkill(PChar, "Leadership", -50);
			AddCharacterExpToSkill(PChar, "Fortune", -70);
			AddCharacterExpToSkill(PChar, "Sneak", 20);
			DeleteAttribute(PCHar, "GenQuest.ChurchQuest_2");
			npchar.quest.BadMeeting = lastspeak_date;
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_4_1":
			if(rand(1) == 0) // �������.
			{
				dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +". ���� ����� �������� ���� � �������� ������, �� �� � ��������, ��� �������� - �������� ����! ������� �������� �� ��� ��������� ���������, ����� �������� ���� ����.";
				link.l1 = "�����, ������ ������...";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_1_2"; // ������� ����, �.�. ���� � ����.
			}
			else
			{
				dialog.text = "��, ��� �� ����� ����, ������� ������� ������ � ��������... ��... ���� �� ������ �, �� ������ �� ������� � ������? ��� ���� ������� �����, � ������� ��������� �� ����� � ��� ����� ���������... "+ GetSexPhrase("��� ���","���� ���") +", �������, ��� ��� ������� �����, ������ ����� ������ ��������� �������, �� ��� � �������������������� �� �����, ����� ����� �������!!";
				link.l1 = "���� " + NPChar.name + ", � ���� ����� �� �����"+ GetSexPhrase("��","���") +", ������� ��� ����, �����"+ GetSexPhrase("","�") +" ���������� ���, ����� �� ��������, ��� ���� �������. � ��� �� ������ � ����� �������� �� ��� �����������!";
				link.l1.go = "GenQuest_Church_2_Finally_Complete_1_4_1_2";
			}
			break;
			
		case "GenQuest_Church_2_Finally_Complete_1_4_1_2":
			dialog.text = "������ �����, �����"+ GetSexPhrase("�","���") +", � ����������� ���������, ������� �������� ���� ������ �������, ��� ���� �� ���� ������� �� ��� �� ��������� ���"+ GetSexPhrase("��","�����") +" � �������"+ GetSexPhrase("���","���") +"!";
			link.l1 = "��� �� ���?! " + LinkRandPhrase("������ ������", "������", "���� ������") + "!..";
			link.l1.go = "GenQuest_Church_2_Finally_Complete_1_4_1_2_1";
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_4_1_2_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -5);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_12");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","���"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2");
			NPChar.quest.BadMeeting = lastspeak_date;
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1_1":
			DialogExit();
			iMoneyToCharacter = PChar.GenQuest.ChurchQuest_2.MoneyToCharacter;
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -2);
			AddMoneyToCharacter(PChar, iMoneyToCharacter);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_10");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_3_1_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -1);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_11");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_1_1":
			dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +". ���� ����� �������� ���� � �������� ������, �� �� � ��������, ��� �������� - �������� ����! ������� �������� �� ��� ��������� ���������, ����� �������� ���� ����.";
			link.l1 = "�����, ������ ������...";
			link.l1.go = "GenQuest_Church_2_Finally_Complete_1_1_2";
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_1_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", -2);
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "12_8");
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_2_1":
			dialog.text = "����, ��������� ����! �� ��������� ������� �������, ���� ��! � �����, ��� ���� ��� �������� �������� ��� ������ ���� � �� ������� ����� �������! � ����������� ��������, � ���...";
			link.l1 = "������-��, � ����� ����� ������ ������ �� ������, ��� �� ������, ������. ��, ������, ��� ������������� ������� ���� �������.";
			link.l1.go = "GenQuest_Church_2_Finally_Complete_1_2_2";
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_2_2":
			dialog.text = ""+ GetSexPhrase("��� ���","���� ���") +", � ���� ������������ ��� �� �����������, ��� ��"+ GetSexPhrase(", ��� �������� ������ ������ ������ ������,","") +" ��������� ��� ���� � ������...";
			link.l1 = "������ ������, �� ������� ��������������� ��� �������� �������. �������� ��� ��������� ����� �������...";
			link.l1.go = "GenQuest_Church_2_Finally_Complete_1_2_3";
		break;
			
		case "GenQuest_Church_2_Finally_Complete_1_2_3":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterComplexReputation(PChar,"nobility", 5);
			AddMoneyToCharacter(PChar, -sti(PChar.GenQuest.ChurchQuest_2.MoneyCount));
			AddMoneyToCharacter(PChar, sti(PChar.GenQuest.ChurchQuest_2.MoneyToCharacter));
			sQuestTitle = NPChar.City + "ChurchGenQuest2";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest2", "4");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			AddQuestUserData(sQuestTitle, "sCity", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_2");
			NPChar.GenQuest.ChurchQuest_2.GiveQuestDateParam = iMonth;
		break;
		// <-- ������ ������

		case "donation":
			dialog.Text = "�������, "+ GetSexPhrase("��� ���","���� ���") +". ������� �� ������� ������������ ������ ������?";
			Link.l1 = "��������, ������ ������, �� ������������� �� �����.";
			Link.l1.go = "No donation";
			if(makeint(PChar.money)>=100)
			{
				Link.l2 = "��� ����� ����� ��������. ����� 100 ����.";
				Link.l2.go = "donation paid_100";
			}
			if(makeint(PChar.money)>=1000)
			{
				Link.l3 = "1000 ����. � �����, ����� ������.";
				Link.l3.go = "donation paid_1000";
			}
			if(makeint(PChar.money)>=5000)
			{
				Link.l4 = "��� ����� � ��������, ������� � ��������� 5000 ����.";
				Link.l4.go = "donation paid_5000";
			}
			//-->> ����� ������������� ������� �������
			if(pchar.questTemp.different == "HostessChurch_toChurch" && pchar.questTemp.different.HostessChurch.city == npchar.city && sti(pchar.money) >= sti(pchar.questTemp.different.HostessChurch.money))
			{
				Link.l5 = "������ ������, � ���� ������� ������������� �� �� ����. � ����� ��� �� ���������.";
				Link.l5.go = "HostessChurch";
			}
			//<<-- ����� ������������� ������� �������
		break;

		case "No donation":
			dialog.Text = "��... ��� ���� �������, � �� ������ ��� ��������. �� �� ���������, ��� ��� �������� ��� �� �������� ����.";
			Link.l1 = "� �� ������ ���. ������� ����� ������ ����.";
			Link.l1.go = "node_3";
			Link.l2 = "��������, ������ ������, ��� ����.";
			Link.l2.go = "exit";
		break;

		case "donation paid_100":
			AddMoneyToCharacter(pchar, -100);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 100;
			dialog.Text = "�� ���� ������ ������ ��������� ���, "+ GetSexPhrase("��� ���","���� ���") +", �� ��� ���.";
			Link.l1 = "��� ���� ���������� � ����, ������ ������.";
			Link.l1.go = "node_3";
			Link.l2 = "��������, ������ ������, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_1000":
			AddMoneyToCharacter(pchar, -1000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 1000;
			dialog.Text = "�� ���� ������ ������ ��������� ���, "+ GetSexPhrase("��� ���","���� ���") +", �� ��� ���.";
            Link.l1 = "��� ���� ���������� � ����, ������ ������.";
			Link.l1.go = "node_3";
			Link.l2 = "��������, ������ ������, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

		case "donation paid_5000":
			AddMoneyToCharacter(pchar, -5000);
			pchar.questTemp.donate = makeint(pchar.questTemp.donate) + 5000;
			dialog.Text = "�� ���� ������ ������ ��������� ���, "+ GetSexPhrase("��� ���","���� ���") +", �� ��� ���.";
            Link.l1 = "��� ���� ���������� � ����, ������ ������.";
			Link.l1.go = "node_3";
			Link.l2 = "��������, ������ ������, ��� ����.";
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;

case "ispoved":
			dialog.text = "������� ��, "+ GetSexPhrase("��� ���","���� ���") +", � ���� ������.";
			link.l1 = "� ���������"+ GetSexPhrase("","�") +". ����� ���� � ������ ���.";
			link.l1.go = "exit";
			link.l2 = "� ��� ����"+ GetSexPhrase("��","��") +", ������ ����. ����� ����������� ��� ��� �����������, �� ������ ������ ���...";
			link.l2.go = "ispoved_1";
			if (CheckAttribute(pchar, "questTemp.Inquisitor.AveMaria"))
			{   
			link.l2 = "������, ���� � ���, ��� � ��� ���� �������� �������, � �������� ���� � ����� ����� ��� ����, ����� ���������� ��� � ��������� ��������� �������� ����...";
			link.l2.go = "ispoved_11";
			}
			break;

		case "ispoved_1":
			dialog.text = "��� �� ������, ���� ��...";
			link.l1 = "��, �� �� ���� ������� ������ �������� ����� ���� ����� �������. � ������"+ GetSexPhrase("","�") +" � �����"+ GetSexPhrase("","�") +" �������...";
			link.l1.go = "ispoved_2";
		break;

	case "ispoved_11":
			dialog.text = "��� �� ������, ���� ��...";
			link.l1 = "��, �� �� ���� ������� ������ �������� ����� ���� ����� �������. � ������"+ GetSexPhrase("","�") +" � �����"+ GetSexPhrase("","�") +" �������...";
			link.l1.go = "ispoved_22";
		break;

		case "ispoved_2":
			dialog.text = "� �������, ����� ��� �� ���� �����, ��� ������ ��� ������ " + NationNameGenitive(sti(NPChar.nation)) + "?";
			link.l1 = "���, �������, ������.";
			link.l1.go = "ispoved_3";
			link.l2 = "������ ����, ������... ������.";
			link.l2.go = "ispoved_4";
		break;

	case "ispoved_22":
			dialog.text = "��� ��������������� ��� ��������� ������ � �������!";
			link.l1 = "� ����, ������, ������� � ������... �� ��� ���� �� ���� ������, � ���� �������� ����...";
			link.l1.go = "ispoved_33";
		break;


		case "ispoved_3":
			dialog.text = "����� ������� ������� ���� ��� �����. ��� ��� ��� ������, � ��������� �������� ������ ��������, �� �������� ����� ������ ��� ���������.";
			link.l1 = "�������, ������, �� ���� ����� �������... � �����.";
			link.l1.go = "exit";
		break;

	case "ispoved_33":
			dialog.text = "���� ���� ����� ��������, �� �� ���������� ����������� �������� �� ������ ��������� �� ����� ���� � ������...";
			link.l1 = "����������, ������.";
			link.l1.go = "ispoved_44";
		break;

case "ispoved_44":
int iMoney = makeint(makeint(Pchar.money)/10);
AddMoneyToCharacter(pchar, -iMoney);
		dialog.text = "����� ������� ������� ���� ��� �����. ��� ��� ��� ������, � ��������� �������� ������, �� �������� ����� � ���� ��������!";
		link.l1 = "�������, ������, �� ���� ����� �������... � �����.";
		link.l1.go = "exit_1";
		break;

		case "ispoved_4":
			dialog.text = "������� ������� �� ������� ������ �����! ������ � �����, ����� � ������! ���� ���� ������ - � ���������!";
			link.l1 = "� ��������� ������� ��������. �� � ���� �����, �� ������� ����. ��������...";
			link.l1.go = "exit";
			npchar.quest.BadMeeting = lastspeak_date;
		break;

        case "work":
        	if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.AskOwner") && NPChar.location == PChar.GenQuest.ChurchQuest_1.ToColony + "_church")
        	{
        		dialog.text = "�������, "+ GetSexPhrase("��� ���","���� ���") +", �� ������ ��� ������������ ������. � ���� ��� ��������� ��� �������� �� ������, ��� ����� �������.";
				link.l1 = "��������, " + RandPhraseSimple("������", "���� ������") + ", ��� ���� ��������� ����� ���������. ������ " + PChar.GenQuest.ChurchQuest_1.PriestName + " �� " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen") + " ������� ��������� � ���� ���������� ����������� ����� ������������ ����������, � ������ ������� ��� ������� �� ����, ���� ����� ������.";
				link.l1.go = "GenQuest_Church_1_Dialog_1";
				DeleteAttribute(PChar, "GenQuest.ChurchQuest_1.AskOwner");
				break;
        	}
			dialog.text = "����� ���� ������� ����, "+ GetSexPhrase("��� ���","���� ���") +"?";
			link.l1 = "� �����"+ GetSexPhrase("","�") +" �� ������ ��� ���� ������, ������...";
			link.l1.go = "quests"; // ������ � ���
            link.l2 = RandPhraseSimple("� ���� ���������� � ������ �� ����� ������ " + NationNameGenitive(sti(NPChar.nation)) + ".",
                                        "��� ���� ���� � �������, �� ����� �� ����� ������?");
			link.l2.go = "prihod";
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
	            link.l3 = RandPhraseSimple("������ ������", "������") + ", � �����"+ GetSexPhrase("","�") +" �� ���������� � ���� � ���������� ��������."; //(��������� � �������)
	            link.l3.go = "LoanForAll";
            }
			// -->
            if (stf(pchar.Health.HP) < 60.0)
            {
                link.l4 = "� �������� � ���������.";
                link.l4.go = "healthAdd_1";
            }
            
			//����� ���� - �� ����� � ����� �������
			if (CheckAttribute(pchar, "GenQuest.Intelligence") && pchar.GenQuest.Intelligence.SpyId == npchar.id && pchar.GenQuest.Intelligence == "")
			{
	            link.l7 = RandPhraseSimple("������ ������", "������") + ", � ����� �� ��������� ������ ��������. ��� ����� ���������� " + GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)) + ".";
	            link.l7.go = "IntelligenceForAll";
            }
			//--> Jason ��������� ������
			if (CheckAttribute(pchar, "GenQuest.Monkletter") && npchar.city == pchar.GenQuest.Monkletter.City)
			{
	            link.l10 = "������, � ������" + GetSexPhrase("","��") + " ��� ��� ������ �� ������ �� ������ "+XI_ConvertString("Colony"+pchar.GenQuest.Monkletter.StartCity)+".";
	            link.l10.go = "Monkletter";
            }
			//<-- ��������� ������
			//--> Jason �������� �������������
			if (CheckAttribute(pchar, "GenQuest.Churchbooks") && pchar.GenQuest.Churchbooks == "go" && sti(npchar.nation) == sti(pchar.GenQuest.Churchbooks.Nation) && npchar.city != pchar.GenQuest.Churchbooks.StartCity)
			{
	            link.l11 = "�����, � ������ �� ������� "+XI_ConvertString("Colony"+pchar.GenQuest.Churchbooks.StartCity)+". ������� ������ ����� ������������, � �������� ����� �������� ���� ���������� �� ���� � ���.";
	            link.l11.go = "Churchbooks";
            }
			if (CheckAttribute(pchar, "GenQuest.Churchbooks") && pchar.GenQuest.Churchbooks == "return" && npchar.city == pchar.GenQuest.Churchbooks.StartCity)
			{
	            link.l11 = "������ ������, � ������ ������������ ��� ������ �������.";
	            link.l11.go = "Churchbooks_2";
            }
			//<-- �������� �������������
			link.l99 = "� ���������"+ GetSexPhrase("","�") +", ���� ���� ����.";
			link.l99.go = "exit";
		break;

		case "prihod":
			if(!CheckAttribute(PChar, "GenQuest.ChurchQuest_1.StartQuest") && !CheckAttribute(PChar, "GenQuest.ChurchQuest_2.StartQuest") && NPChar.GenQuest.ChurchQuest_1.GiveQuestDateParam != iMonth && NPChar.GenQuest.ChurchQuest_1.GiveQuestDay != lastspeak_date && NPChar.location != "Panama_church" && rand(5) == 1)
		    {
		        dialog.text = "��� ���������. ������ � ���� ������� ���, "+ GetSexPhrase("��� ���","���� ���") +", �� ������ ��������� � ���� �������� �������� ������ ������ ����� ������.";
				link.l1 = LinkRandPhrase("������", "������ ������", "���� ������") + ", � ������� ������"+ GetSexPhrase("��","��") +" ��������"+ GetSexPhrase("��","��") +", � ��� ��������� ��������� ������-������ - ��������."+ GetSexPhrase(" ��� �� ������ � ������, ���� �� ����� ������ ������, ��� �?","") +"";
				link.l1.go = "GenQuest_Church_1_Start_1";
				NPChar.GenQuest.ChurchQuest_1.GiveQuestDateParam = iMonth; // ���������� ����� �� ���� ���� � �����
		    }
			else
			{
				NPChar.GenQuest.ChurchQuest_1.GiveQuestDay = lastspeak_date;	// ���� �� ��� �������, �� ���� �� ���� ����.
			}	
            dialog.text = "� ��� � ������� ��� ��������, "+ GetSexPhrase("��� ���","���� ���") +". ������� �� �����������.";
    		link.l2 = "��, ��� ��� ������, � ����� �� ����� �����.";
    		link.l2.go = "exit";
			DeleteAttribute(npchar, "quest.add");
			NPChar.GenQuest.ChurchQuest_1.GiveQuestDay = lastspeak_date;	// ���� �� ��� �������, �� ���� �� ���� ����.
		break;
		
		// Church GenQuest_1 -->
		case "GenQuest_Church_1_Start_1":
			dialog.text = "�� ��� �, ���� � ���� ���� ���������� ���������, ���������� �������� ��������� �� ������ ������� ��������, �� � ������� ���������, � ����� �������� ���...";
			link.l1 = LinkRandPhrase("������", "������ ������", "���� ������") + ", � ���� ��������"+ GetSexPhrase("","�") +" ������� ��� ����� ������, ���� ���� ��� ����� ��� ������� ������������� � ���� �����������! �� � ������ ���� �������.";
			link.l1.go = "GenQuest_Church_1_Start_2";
		break;
			
		case "GenQuest_Church_1_Start_2":
			PChar.GenQuest.ChurchQuest_1.QuestTown = NPChar.City;
			Church_GenQuest1_InitStartParam(NPChar);
			dialog.text = "��� ���! ��� ������... �� ���� ������ ����������... ��������� ����� ����� ���������� ������ " + PChar.GenQuest.ChurchQuest_1.ToName + " �� " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.ToColony + "Gen") + ", ��� �� " + XI_ConvertString(PChar.GenQuest.ChurchQuest_1.ToIsland + "Dat") + " �������� � ���� �� ����� ��������� ������������ ������ � ������� ��������� �� ��������� ����������. ��� ��� ������� ���� ����������� ����������� ������������ �� �������������� ��������������� ����������� ����� ������, �������� � �� ���, ���� � �����������, ��� ��������� ������� ����������� �� �������� ��� ������� �������� � ����...\n�� ����� �� �� ���������������� ���������� ���� ��������?";
			link.l1 = "�����, " + LinkRandPhrase("������ ������", "������", "���� ������") + ", ��� �� �������� ������ �������. ���� ������� ����������, � ��� ��� ������� ����� ���� �������� ����������.";
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("������", "������ ������", "���� ������") + ", ���� ��������� �� �������������� ��� �������. � ������� �� ���������� � ����.";
			link.l2.go = "GenQuest_Church_1_Start_3";
		break;
			
		case "GenQuest_Church_1_Start_3":	// ����� ����
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PChar.GenQuest.ChurchQuest_1.StartQuest = true;
			PChar.GenQuest.ChurchQuest_1.PriestName = NPChar.name;
			PChar.GenQuest.ChurchQuest_1.Nation = sti(NPChar.nation);
			PChar.GenQuest.ChurchQuest_1.AskOwner = true;
			sQuestTitle = NPChar.City + "ChurchGenQuest1";
			ReOpenQuestHeader(sQuestTitle);
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "1");
			AddQuestUserDataForTitle(sQuestTitle, "sCity", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("��","���"));
			AddQuestUserData(sQuestTitle, "sName", NPChar.name);
			AddQuestUserData(sQuestTitle, "sOwnerCity", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.ToColony + "Gen"));
		break;
			
		case "GenQuest_Church_1_Dialog_1":
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.2A_Scene"))	// ����� 2�
			{
				dialog.text = "�!.. ��... �������������, ����������... ��, "+ GetSexPhrase("��� ���","���� ���") +", ��� ��������� ����� �������, ������ �����������, ��� �������� ����������� ������ ���� ���������� � ����� �� ��������� � ������!";
				link.l1 = "������, " + LinkRandPhrase("������", "������ ������", "���� ������") + ", ���� �������� ���� " + PChar.GenQuest.ChurchQuest_1.PriestName + " ����� �� ��������� � ��������, � ��� ���� ������ �� ����� ��������� ������� �������� � ����������� � ����� ����������.";
				link.l1.go = "GenQuest_Church_1_Dialog_1_1";
			}
			else	// ����� 2�-� � 2�-�
			{
				dialog.text = "�, ��!.. �������������... "+ GetSexPhrase("��� ���","���� ���") +", ��� ��������� ����� �������, ������ �����������, ��� �������� ������� ������ ���� ����������, ��� �, � ����� ������, ��������� ���������� � �� ������������ ���������...";
				link.l1 = "������, " + RandPhraseSimple("������", "������ ������") + ", ������. ������� ������ " + PChar.GenQuest.ChurchQuest_1.PriestName + " � �������� ��� ��������� ��� ����� ����� ��� � ����.";
				link.l1.go = "GenQuest_Church_1_Dialog_1_2";
			}
		break;
			
		case "GenQuest_Church_1_Dialog_1_1": // ����� 2�
			dialog.text = "� �������, ���� ��, �� ����� �� �������� �� ����������� ������� �������: '� ������ ���, ��� �� ������� ��������� �����'? � ���� ������� " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen") + " ���������� ������ ����� ��������� �������.";
			link.l1 = "��, ������ ������, �� �����, �� � ������ ��� ������ ������ ���������� ������: '�� ��� ����� �����, ��� �� ��� ������������ ��� ������, � ����� ��� ��� ����������, � ������� ��� �������, ��� ����� ����!' � ������ " + PChar.GenQuest.ChurchQuest_1.PriestName + " ��� ����������� ������������ �������� � ����� ������������, ���� � ��� ���������"+ GetSexPhrase("","�") +", ��������� ���� ������.";
			link.l1.go = "GenQuest_Church_1_Dialog_1_1_1";
		break;
			
		case "GenQuest_Church_1_Dialog_1_1_1":
			dialog.text = "�-�-������������?! � ����� ������!.. �� ����� ��, ����� ��? � � ��� ����� ������ �������� ��� ����� ��������� ����� ����� �� ������, �� ���-�� �� �� ���������� ������� ������. �� � ����, "+ GetSexPhrase("��� ���","���� ���") +", � ������ ���������� ����� �������. ���, ������ ����� � ��������, ������� �� ���� " + PChar.GenQuest.ChurchQuest_1.PriestName + " � ������� � ����������� � ����������� ��� ����������� �������������.";
			link.l1 = "���������������� ������������, " + LinkRandPhrase("������", "������ ������", "���� ������") + ". ����������������.";
			link.l1.go = "GenQuest_Church_1_Dialog_1_1_2";
		break;
			
		case "GenQuest_Church_1_Dialog_1_1_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PChar.GenQuest.ChurchQuest_1.Complete.Short = true;
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "2");
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown));
			// ������� "��������" -->
			AddItems(PChar, "Bible", 1);	// ���� ��������
			items[FindItem("Bible")].Name = "itmname_ChurchGenQuest1Bible";	// ������ ���. ����� �������� �������!
			ChangeItemDescribe("Bible", "itmdescr_ChurchGenQuest1Bible"); // ������ ��������. ����� �������� �������!
			items[FindItem("Bible")].City = XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen"); // ����������. ����� �������!
			// <-- ������� "��������"
		break;
			
		case "GenQuest_Church_1_Dialog_1_2":	// ����� 2�-� � 2�-�
			// ������� ���� -->
			sld = GetCharacter(NPC_GenerateCharacter("ChurchGenQuest1_Cap", "mercen_" + (rand(14)+14), "man", "man", 15, NPChar.nation, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 35, 40, 35, "blade_13", "pistol3", "grapeshot", 30);
			FantomMakeCoolSailor(sld, 7 + rand(2), "", CANNON_TYPE_CANNON_LBS16, 75, 70, 65);
			sld.Abordage.Enable = false;
			sld.ShipEnemyDisable  = true; // ���� �� ��������� �� ��������
			LAi_SetImmortal(sld, true);
			sld.Dialog.FileName = "GenQuests_Dialog.c";
			sld.Dialog.CurrentNode = "ChurchGenQuest_1_DeckDialog_1";
			Group_FindOrCreateGroup("ChurchGenQuest1_CapGroup");
			Group_AddCharacter("ChurchGenQuest1_CapGroup", "ChurchGenQuest1_Cap");
			Group_SetType("ChurchGenQuest1_CapGroup", "trade");
			Group_SetGroupCommander("ChurchGenQuest1_CapGroup", "ChurchGenQuest1_Cap");
			Group_SetTaskNone("ChurchGenQuest1_CapGroup");
			Group_LockTask("ChurchGenQuest1_CapGroup");
			PChar.GenQuest.ChurchQuest_1.AskPortMan = true;
			PChar.GenQuest.ChurchQuest_1.CurPortManColony = "";
			PChar.GenQuest.ChurchQuest_1.CapFullName = GetFullname(sld);
			PChar.GenQuest.ChurchQuest_1.CapShipName = sld.Ship.Name;
			PChar.GenQuest.ChurchQuest_1.NoCapColony = NPChar.city;
			PChar.GenQuest.ChurchQuest_1.CapColony = GetColonyExpect2Colonies(NPChar.city, PChar.GenQuest.ChurchQuest_1.QuestTown);
			// <-- ������� ����
			
			if(CheckAttribute(PChar, "GenQuest.ChurchQuest_1.2BA_Scene")) // ����� 2�-�
			{
				dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +"... ���� � ���, ��� �� ������� ������ ��� �������� ����������� � ��������� ����� '" + sld.Ship.Name + "', ���� ���� �������� ��� ���������� ���������� �������. � ���� ������� ������� ������� " + GetFullName(sld) + " �������, ��� ������������ � " + XI_ConvertString("Colony" + GetColonyExpect2Colonies(NPChar.city, PChar.GenQuest.ChurchQuest_1.QuestTown)) + ". � ���� �� �� ������� �� �����, ������ ���������� ������, ������ ����, ��� � ���� " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen") + " �� ���������� �����. ������� ��, � �������������� �������, ������� ����� � ���� ������ ��������� � ������ �� ���������� ������ �������.";
				link.l1 = "��, � �� �������, ��� ����� �������� ����� ��������?.. ���������� �� �� �������� �������� ��������� ��� ������ � �������� ������������ ���������?";
				link.l1.go = "GenQuest_Church_1_Dialog_1_2_1";
			}
			else // ����� 2�-�
			{
				dialog.text = "��, "+ GetSexPhrase("��� ���","���� ���") +"! �� �������� ��������� �� ��������� �����! � ��� �������� ����� ���� " + PChar.GenQuest.ChurchQuest_1.PriestName + " � ��������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + ". ����� ���� �������������� ������� ������ �� �������� � ����������, ��� ������� ��� ����� ������������ � " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.CapColony) + ". � ���� �������� ������� �� ������� �� �����, ������ ���������� ������, ������ ����, ��� � ���� " + XI_ConvertString("Colony" + PChar.GenQuest.ChurchQuest_1.QuestTown + "Gen") + " �� ���������� �����.";
				link.l1 = LinkRandPhrase("������ ������", "������", "���� ������") + "... � �� �������, ��� ����� �������� ����� ��������?.. � ��� � �����"+ GetSexPhrase("","�") +" �� ������, ��� ���������� ��� �����.";
				link.l1.go = "GenQuest_Church_1_Dialog_1_2_2_1";
			}
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_1":	// 2�-�
			dialog.text = "� ���� �����, "+ GetSexPhrase("��� ���","���� ���") +", ���� ��� �� ������� �� ������ � �������, � � ������ ���� ����� ����� �����!";
			link.l1 = "�-��. ��� ������ ��������. �� ��� �... ������������ ����, ������ ����, � ��������� ����� � ������� ����� ��������.";
			link.l1.go = "GenQuest_Church_1_Dialog_1_2_1_1";
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_1_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PChar.GenQuest.ChurchQuest_1.AskPortMan = true;
			PChar.GenQuest.ChurchQuest_1.AskPortMan_InColony = NPChar.city;
			PChar.GenQuest.ChurchQuest_1.CapFullInfo = true; // ������ ���� � ����
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "3_1");
			AddQuestUserData(sQuestTitle, "sCapName", PChar.GenQuest.ChurchQuest_1.CapFullName);
			AddQuestUserData(sQuestTitle, "sShipName", PChar.GenQuest.ChurchQuest_1.CapShipName);
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_2_1":
			dialog.text = "����� ������ �����, "+ GetSexPhrase("��� ���","���� ���") +". � ��� ������� �, � ���������, ������ ������� �� ����.";
			link.l1 = "� �� ������ ������ �������� ��������, ���� �� ������������ ������ �������� ��� �����?!!";
			link.l1.go = "GenQuest_Church_1_Dialog_1_2_2_2";
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_2_2":
			dialog.text = "������ ��, "+ GetSexPhrase("��� ���","���� ���") +", ������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + " ����� �������������� ��...";
			link.l1 = "��� � ��� ������"+ GetSexPhrase("","�") +", " + LinkRandPhrase("������", "������ ������", "���� ������") + ".";
			link.l1.go = "GenQuest_Church_1_Dialog_1_2_2_3";
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_2_3":
			dialog.text = "��������, "+ GetSexPhrase("������� �������","�������") +"! ������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + " ����� �����������, � ��� ����� �� ��������� ��� ���������� ����� ������, ��� ����������������� �� �������� ����������� ��� ���� ��������! ������� �� �������� � ������ ��������� ���� �� ��� ��������. ���, �������� ������, ������� ���� ������ �������� ����, ��������, ���� ������� ����, ��� ������� ��� ��������� ������������� ���� � �������� ����...";
			link.l1 = "� �����"+ GetSexPhrase("","�") +", " + LinkRandPhrase("������ ������", "������", "���� ������") + ", � �����"+ GetSexPhrase("","�") +"! �������������� ������� " + PChar.GenQuest.ChurchQuest_1.CapFullName + ", ��������� ���� ������� ��������� � �������, ��������� ������ �������� ������� ������������� ��� ������?..";
			link.l1.go = "GenQuest_Church_1_Dialog_1_2_2_4";
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_2_4":
			dialog.text = "�� ����� ����������"+ GetSexPhrase("��","���") +", "+ GetSexPhrase("��� ���","���� ���") +". ������ ����� ������� � �� ����, ��, ����������, ��� ����� ����� �����������.";
			link.l1 = "��, " + RandPhraseSimple("������ ������", "������") + "... ��������� ��� �� ��. � ���������� �� ��� ������� ����...";
			link.l1.go = "GenQuest_Church_1_Dialog_1_2_2_5";
		break;
			
		case "GenQuest_Church_1_Dialog_1_2_2_5":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PChar.GenQuest.ChurchQuest_1.AskPortMan = true;
			PChar.GenQuest.ChurchQuest_1.AskPortMan_InColony = NPChar.city;
			sQuestTitle = PChar.GenQuest.ChurchQuest_1.QuestTown + "ChurchGenQuest1";
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "3_2");
			AddQuestUserData(sQuestTitle, "sCapName", PChar.GenQuest.ChurchQuest_1.CapFullName);
		break;
			
		case "GenQuest_Church_1_Complete_1":
			dialog.text = "��, ���� ��! � ������ �������, � ��� �� ����������� ��� ������ �����! �� ���� ������ � ������, "+ GetSexPhrase("��� ���","���� ���") +", ���� ���������� ���� ������� ���� � ���������� ��...";
			link.l1 = RandPhraseSimple("������ ������", "���� ������") + ", �� �������� �� ������ ������ � ����, ����� ���������, �� ���������. � �����, ����� �������� ������� ���������, ������� ����� ������ ������������ �����...";
			link.l1.go = "GenQuest_Church_1_Complete_2";
		break;
			
		case "GenQuest_Church_1_Complete_2":
			dialog.text = "��-��, "+ GetSexPhrase("��� ���","���� ���") +", ��-��. � ���������� ���� �� �����������. ���, ������ ���, � �����, ��� ��� ���������� ��� ����������, ������� ��������� ������� � ������ ������ � ����������� ������� �������!";
			link.l1 = "���������, " + LinkRandPhrase("������ ������", "������", "���� ������") + ". �������� ���� ������������ ����� � ��������, � ���������� �� ��� ������� ����... ��������";
			link.l1.go = "GenQuest_Church_1_Complete_3";
		break;
			
		case "GenQuest_Church_1_Complete_3":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			RemoveItems(PChar, "Bible", 1);
			items[FindItem("Bible")].Name = "itmname_bible";
			BackItemDescribe("Bible");
			DeleteAttribute(items[FindItem("Bible")], "City");
			ChangeCharacterComplexReputation(PChar,"nobility", 5);
			AddCharacterExpToSkill(PChar, "Leadership", 50); // ����� � ���������
			AddCharacterExpToSkill(PChar, "Fortune", 50); // ����� � �����
			TakeNItems(pchar, "chest", 3+drand(1));
			PlaySound("interface\important_item.wav");
			sQuestTitle = NPChar.City + "ChurchGenQuest1";
			characters[GetCharacterIndex("ChurchGenQuest1_Cap")].LifeDay = 0;
			Group_DeleteGroup("ChurchGenQuest1_CapGroup"); // ���� ����
			PChar.Quest.Church_GenQuest1_ChangeCapitanLocation.over = true; // ���������, ���� ����� ��������
			AddQuestRecordEx(sQuestTitle, "ChurchGenQuest1", "7");
			AddQuestUserData(sQuestTitle, "sSex", GetSexPhrase("","�"));
			AddQuestUserData(sQuestTitle, "sColony", XI_ConvertString("Colony" + NPChar.City + "Gen"));
			AddQuestUserData(sQuestTitle, "sSumm", FindRussianMoneyString(sti(PChar.GenQuest.ChurchQuest_1.AwardSumm)));
			CloseQuestHeader(sQuestTitle);
			DeleteAttribute(PChar, "GenQuest.ChurchQuest_1");
			NPChar.GenQuest.ChurchQuest_1.GiveQuestDateParam = iMonth;
			break;
		// <-- Church GenQuest_1

        case "healthAdd_1":
            if (GetHealthMaxNum(pchar) == 6) // �������
            {
                dialog.text = "�������� ���� " + GetHealthNameMaxSmall(pchar) + ", � ���� ������� ����. ����� ������ �������� ������������� � �������� ��� ��������.";
    			link.l1 = "�������, ����������. ���������� ��������� ����� �� ����������� � �����.";
    			link.l1.go = "exit";
            }
            else
            {
    			dialog.text = "�������� ���� " + GetHealthNameMaxSmall(pchar) + ", � ���� ���� ������� ����, ���� �� �������� ��� ���������.";
    			link.l1 = "��� ��� ����� �����?";
    			link.l1.go = "healthAdd_2";
			}
			link.l2 = "� ������ ������ ��� �������� ��������?";
    		link.l2.go = "healthAdd_info";
		break;

		case "healthAdd_info":
			dialog.text = "����� ������, "+ GetSexPhrase("��� ���","���� ���") +", �� ��������� ����, ����� ���� �����. ��� �� �������� ���������, �������� ���� ����������� ������ �����, � � ���������� �� ����������� ����"+ GetSexPhrase("","�") +" � ��������� ��� �� � �����.\n ������� ����, ���� �������� ������, ������ � ���� ��������. �� ���� �� ��������� ����� ���������� � ������ ������ �������� �������������. ������������� ����� � ����������� ������� ������� ���������� ������ ������ ���.";
			link.l1 = "�������, �� ���� ����������.";
			link.l1.go = "exit";
		break;

		case "healthAdd_2":
			dialog.text = "������� � ����� �� �������, "+ GetSexPhrase("��� ���","���� ���") +". ����� ������� ������ ���� ��������� �����.";
			link.l1 = "� �� �� ����� �� ��������� �� ����?";
			link.l1.go = "healthAdd_3";
			link.l2 = "�� ���� - �����? ��.. ����������, �������.";
			link.l2.go = "exit";
		break;

		case "healthAdd_3":
            if (npchar.quest.HealthMonth != iMonth)
            {
    			dialog.text = "�? �������, ��� ��������. �� ���� ��������� ������ �������� � ��� ������.";
    			link.l1 = pcharrepphrase("�������?", "� ��������! ����� ��� ������?");
    			link.l1.go = "healthAdd_4";
    			link.l2 = "� �� ���-������ ���"+ GetSexPhrase("","�") +"...";
    			link.l2.go = "exit";
			}
			else
			{
                dialog.text = ""+ GetSexPhrase("��� ���","���� ���") +", � ��� ������ � ����� ������������. ������� ������ ��� ��� ����� �� ����� ������.";
    			link.l1    = "�������, "+RandPhraseSimple("������.", "������ ������.");
    			link.l1.go = "exit";
			}
		break;

		case "healthAdd_4":
			dialog.text = "��� ����� ���� ����� ������ ����������� ������ �� ���� ���������.";
			link.l1 = pcharrepphrase("�������!!! �� �� � ���� ���?! � ������� ����� �����, ����� ��������� ���� �������.", "��� ���� ��� ������� �����. ����� ������ ������� - �������� �� ������ �� ������.");
			link.l1.go = "exit";
            if (sti(pchar.Money) >= 100000)
            {
    			link.l2 = "� ������"+ GetSexPhrase("��","��") +"!";
    			link.l2.go = "healthAdd_5";
			}
		break;

		case "healthAdd_5":
            AddMoneyToCharacter(pchar, -100000);
            AddCharacterMaxHealth(pchar, 4); // ����� �� ���������, �� ���� ������ 51
            npchar.quest.HealthMonth = iMonth;
			dialog.text = "������. ���� �������� ������� ���������. �� ���� ����� �������� ������ � ������ ����, ����� ������ ������ �� ���. ��� ����� ����� ����� �������� � �������� � ����� ������� ����.";
			link.l1 = "�������. ���� ���, � ����� ����� ����� �����.";
			link.l1.go = "exit";
		break;
		
		//����� ������������� ������� �������
		case "HostessChurch":
			dialog.text = "� ��� �� ��� ������ ����, ��� ��������?";
			link.l1 = "��... ��� ������� �������� �������.";
			link.l1.go = "HostessChurch_call";
			link.l2 = "� �� �������"+ GetSexPhrase("��","��") +" �� �������� ����. ���� ����� �� ���� ��������� �������������!";
			link.l2.go = "HostessChurch_notCall";
			pchar.questTemp.different = "HostessChurch_return"; //���� �� �����������
		break;
		
		case "HostessChurch_call":
			if (isBadReputation(pchar, 5)) 
			{
				if (rand(100) < GetCharacterSkill(pchar, "Fortune")) //������ ������ �� �����
				{
					dialog.text = "���"+ GetSexPhrase("","�") +" ������"+ GetSexPhrase("�","��") +", ��� �� �������� � �������? � ����� ���� �������"+ GetSexPhrase("","�") +" �� �����, ���� ��� �� ����� �������� ����������!";
					link.l1 = "��� �����. �������, ������� ����� �������� �� ���... ��� ��� ������ �������������?";
					link.l1.go = "HostessChurch_ok";
				}
				else
				{
					dialog.text = "�����, ������!!! ������� ���� ���������� ������ � �������� ������!";
					link.l1 = "������ ������, ��� �� ���?! �� � ��� �� ���� �����, � ��...";
					link.l1.go = "HostessChurch_bad";
				}
			}
			else
			{
				if (rand(10) < GetCharacterSPECIAL(pchar, "Charisma")) //������ ������ �� �������
				{
					dialog.text = "� ���, ��� �� ��������� ��������� ������� ���� � ������� ������. �� ��� ���� ��������� �� �������!";
					link.l1 = "��� ���� �� �������! ��� ��� ������ �������������?";
					link.l1.go = "HostessChurch_ok";
				}
				else
				{
					dialog.text = "� �� ���� ������� ������, ������� �� �����. ����� �� ���� ��������, "+ GetSexPhrase("��� ���","���� ���") +". ����� ������ ���� � ������� �� ��������.";
					link.l1 = "����� ����, ��� �� ���������� ��. ����� ����...";
					link.l1.go = "HostessChurch_bad_1";
				}
			}
		break;
		
		case "HostessChurch_notCall":
			if (rand(10) < GetCharacterSPECIAL(pchar, "Charisma"))
			{
				dialog.text = "����� ��� ������, ���� �� ����, �� ���� ���...";
				link.l1 = "��, ������, ������ ���. ������� ������������� �� ������� ������!";
				link.l1.go = "HostessChurch_ok_1";
			}
			else
			{
				dialog.text = "����� ��� ������, ���� �� ����, �� ���� ���? �� � ��� ���"+ GetSexPhrase("��","��") +"?! � �����, �� ���� ������� - �����!!";
				link.l1 = "������ ������, �� ���� ������� - �����...";
				link.l1.go = "HostessChurch_bad_2";
			}
		break;

		case "HostessChurch_ok":
			dialog.text = "� �������� ���, "+ GetSexPhrase("��� ���","���� ���") +". �����, ������ �������� ��� ��������.";
			link.l1 = "������, ������. �������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.different.HostessChurch.money));
			AddCharacterExpToSkill(pchar, "Fortune", 20);
			//���� ������� ��� ��������� ������� ����
			characters[GetCharacterIndex(pchar.questTemp.different.HostessChurch.city + "_Hostess")].questChurch = "yes";
		break;
		
		case "HostessChurch_ok_1":
			dialog.text = "� �������� ���, "+ GetSexPhrase("��� ���","���� ���") +". ������ �������� ���������.";
			link.l1 = "������, ������. �������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.different.HostessChurch.money));
			AddCharacterExpToSkill(pchar, "Fortune", 20);
			//���� ������� ��� ��������� ������� ����
			characters[GetCharacterIndex(pchar.questTemp.different.HostessChurch.city + "_Hostess")].questChurch = "yes";
		break;
		
		case "HostessChurch_bad":
			dialog.text = "��������, ������� ���!!! � �� ���� ������������ ��� �� �����!";
			link.l1 = "���, �� ������.";
			link.l1.go = "exit";
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			npchar.quest.BadMeeting = lastspeak_date;
			//���� ������� ��� ��������� ������� ����
			characters[GetCharacterIndex(pchar.questTemp.different.HostessChurch.city + "_Hostess")].questChurch = "no";
		break;
		
		case "HostessChurch_bad_1":
			dialog.text = "������ ��� �������. ��� � �����, "+ GetSexPhrase("��� ���","���� ���") +".";
			link.l1 = "��������, ������.";
			link.l1.go = "exit";
			AddCharacterExpToSkill(pchar, "Leadership", 30);
			//���� ������� ��� ��������� ������� ����
			characters[GetCharacterIndex(pchar.questTemp.different.HostessChurch.city + "_Hostess")].questChurch = "no";
		break;
		
		case "HostessChurch_bad_2":
			dialog.text = "��� �� ��� �������, ��������"+ GetSexPhrase("��","��") +"! �������� �� ����� � �� ����������� ��� �� �����!";
			link.l1 = "���? �� ����������, ����...";
			link.l1.go = "exit";
			AddCharacterExpToSkill(pchar, "Leadership", 40);
			npchar.quest.BadMeeting = lastspeak_date;
			//���� ������� ��� ��������� ������� ����
			characters[GetCharacterIndex(pchar.questTemp.different.HostessChurch.city + "_Hostess")].questChurch = "no";
		break;

		//--> Jason ��������� ������
		case "Monkletter":
			if (CheckAttribute(pchar, "GenQuest.Monkletter.Late"))
			{
				dialog.text = "� ��� ������� ������� �����-���� ������� ��� ������. ������ ���� ���� ��� ����� ������, ��� ���?";
				link.l1 = "���� ��������� �������������� ��������������, ������ ������.";
				link.l1.go = "Monkletter_1";
			}
			else
			{
				dialog.text = "� ���� ��� ������, ��� ���. ��������� ���� �� ����������� ��������. ����� �� ���� � ������� ��� ��������� ������� � ��� �������������.";
				link.l1 = "�������, ������ ������. ��� ��� ������ ������ ������!";
				link.l1.go = "Monkletter_3";
			}
		break;
		
		case "Monkletter_1":
			dialog.text = "��� �� ��� ����� �����, ��� ���... ������� ������������, � ������� �����������. ����� ��� ��� ������ � ������ � �����.";
			link.l1 = "���, ��������, ������. ����� �������!";
			link.l1.go = "Monkletter_2";
		break;
		
		case "Monkletter_2":
			DialogExit();
			RemoveItems(PChar, "letter_church", 1);//�������� �� ������
			AddQuestRecord("Monkletter", "2");
			CloseQuestHeader("Monkletter");
			ChangeCharacterComplexReputation(pchar, "nobility", -1);
			DeleteAttribute(pchar, "GenQuest.Monkletter");
		break;
		
		case "Monkletter_3":
			dialog.text = "������ � �����, ��� ���. �� ������ ���� ��������� �� ����� ����!";
			link.l1 = "�� ��������, ������ ������.";
			link.l1.go = "Monkletter_4";
		break;
		
		case "Monkletter_4":
			pchar.quest.Monkletter_Over.over = "yes"; //����� ������
			DialogExit();
			RemoveItems(PChar, "letter_church", 1);//�������� �� ������
			AddQuestRecord("Monkletter", "3");
			CloseQuestHeader("Monkletter");
			TakeNItems(pchar, "gold_dublon", 10+rand(5));
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 5);
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			DeleteAttribute(pchar, "GenQuest.Monkletter");
		break;
		//<-- ��������� ������
		
		//--> Jason ��������� ������������
		case "Churchbooks":
			dialog.text = "���� ������� ����� � ��� ������������ ��� ������ "+XI_ConvertString("Colony"+pchar.GenQuest.Churchbooks.StartCity+"Gen")+"? ������. � ���� ���� �������� � ����� ��������� �������������. ������ ��, ��� ���.";
			link.l1 = "���������, ������. �� ��������!";
			link.l1.go = "Churchbooks_1";
		break;
		
		case "Churchbooks_1":
			dialog.text = "�� ������� ���� ������� �� ����� ����! ������ � �����...";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Churchbooks", "2");
			pchar.GenQuest.Churchbooks = "return";
			GiveItem2Character(pchar, "prayer_book");//��������� �����.�������
		break;
		
		case "Churchbooks_2":
			if (CheckAttribute(pchar, "GenQuest.Churchbooks.Late"))
			{
				dialog.text = "��������� ���� �� ���� ������, ��� ���, ���� �� � ��������� � ����������.";
				link.l1 = "���� ��������� �������������� �������������� � ����, ������ ������.";
				link.l1.go = "Churchbooks_3";
			}
			else
			{
				dialog.text = "��������� ���� �� ������, ��� ���. �� ������ ��� ����� ����� �������. ������ � ������� ���� ���������� ������ - �� ������� ���� � ��� ���������.";
				link.l1 = "�������, ������ ������. ��� ��� ������ ������ ������!";
				link.l1.go = "Churchbooks_4";
			}
		break;
		
		case "Churchbooks_3":
			dialog.text = "�� ��� ���� ��������, ��� ���... ������ � �����.";
			link.l1 = "�� ��������, ������.";
			link.l1.go = "exit";
			RemoveItems(PChar, "prayer_book", 1);//�������� �� ������
			AddQuestRecord("Churchbooks", "3");
			CloseQuestHeader("Churchbooks");
			DeleteAttribute(pchar, "GenQuest.Churchbooks");
		break;
		
		case "Churchbooks_4":
			dialog.text = "������ � �����, ��� ���. �� ������� ���� ������� �� ���� ��� �� ����� �������!";
			link.l1 = "�� ��������, ������ ������.";
			link.l1.go = "Churchbooks_5";
		break;
		
		case "Churchbooks_5":
			pchar.quest.Churchbooks_Over.over = "yes"; //����� ������ patch-5
			DialogExit();
			RemoveItems(PChar, "prayer_book", 1);//�������� �� ������
			GiveItem2Character(pchar, pchar.GenQuest.Churchbooks.Item);
			Log_Info("�� �������� ������ '"+XI_ConvertString(pchar.GenQuest.Churchbooks.Item)+"'");
			AddQuestRecord("Churchbooks", "4");
			CloseQuestHeader("Churchbooks");
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterNationReputation(pchar, sti(npchar.Nation), 1);
			AddCharacterExpToSkill(pchar, "Leadership", 50);
			AddCharacterExpToSkill(pchar, "Fortune", 50);
			DeleteAttribute(pchar, "GenQuest.Churchbooks");
		break;
	}
}

void ChurchGenQuest2_RemoveCup()
{
	RemoveItems(PChar, "Bible", 1);
	ref rItem = ItemsFromID("Bible");
	DeleteAttribute(rItem, "City");
	rItem.Weight = 2;
	rItem.Name = "itmname_Bible";
	rItem.picIndex = 6;
	rItem.picTexture = "ITEMS_9";
	BackItemDescribe("Bible");
}

void Church_GenQuest1_InitStartParam(ref chr)
{
	string sColony = SelectNotEnemyColony(chr); 
	PChar.GenQuest.ChurchQuest_1.IslandId = colonies[FindColony(PChar.GenQuest.ChurchQuest_1.QuestTown)].Island;
	PChar.GenQuest.ChurchQuest_1.ToColony = sColony;
	PChar.GenQuest.ChurchQuest_1.ToIsland = colonies[FindColony(sColony)].Island;
	PChar.GenQuest.ChurchQuest_1.ToName = characters[GetCharacterIndex(sColony + "_Priest")].Name;
	
	// ���� ����� ����� �� ��������... ����� ����� ����� � ������, ���������� � ����� ������.
	int iRand = Rand(2);
	switch(iRand)
	{
		case "0":
			PChar.GenQuest.ChurchQuest_1.2A_Scene = true;
			Log_TestInfo("��������� ��������� 1: �������� ����� - 2� (������ ������� � ���������� ��������)."); 
		break;
		
		case "1":
			PChar.GenQuest.ChurchQuest_1.2BA_Scene = true;
			Log_TestInfo("��������� ��������� 1: �������� ����� - 2�-� (����� ����. � ��� ���� ������ ����).");
		break;
		
		case "2": // ���� ���� ��� �� ���������, �.�. ���� ��� ���, ��� ����, ��-������ ���� ����
			PChar.GenQuest.ChurchQuest_1.2BB_Scene = true;
			Log_TestInfo("��������� ��������� 1: �������� ����� - 2�-� (����� ����. �������� ���� ����������.)"); 
		break;
	}
}