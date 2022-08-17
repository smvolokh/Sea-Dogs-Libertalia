// ����� �������, ����� ���������� � ������������ ��� � �����.
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;

// ============================= ���� angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //������� ������� ������������
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //���� ����������� ������� �����. � npchar.angry.name ������� �������!!!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                    if (npchar.angry.name == "I_know_you_good") Dialog.CurrentNode = "AngryRepeat_2";
					if (npchar.angry.name == "BlueBird_1") Dialog.CurrentNode = "AngryRepeat_1";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= ���� angry ===================================
// ============================================================================

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- ������ ������ - ������ �������
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
            dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("� ���� ���� �� ���? ���? ����� �� �������� ����.","��, " + pchar.name + "! � ���� ���� �� ���? ���? ����� �� �������� ����.") +"",
                         "� ������� ���� ���������.", "���� � ��������� � ����, �� �� ����������� ��������� ����!",
                         "��-�-��, ��� ��� ������ �� ��������, ���� ��� �������.", "repeat", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� �����.",
                                               "�������, �����...",
                                               "������, �����...",
                                               "��...", npchar, Dialog.CurrentNode);
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
			//������ ����� "������ ��������"
			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "������, �����, ��� ����� ����... � �����, �� �������� �� � ���� � ����� ���� ''������ ��������''?";
				link.l1.go = "BlueBird_1";
			}
			if (pchar.questTemp.BlueBird == "weWon")
			{
				link.l1 = "�������������, � ���� �������"+ GetSexPhrase("","�") +" ���� ���� ''������ ��������''!";
				link.l1.go = "BlueBird_6";
			}
			//��������� ������� ������
			if (pchar.questTemp.piratesLine == "begin" && !CheckAttribute(pchar, "QuestTemp.AndreAbelQuest"))	
			{
				link.l1 = "�����, � ��� ������ ��� �����-������...";
				link.l1.go = "PL_Q1_1";
			}

			if (pchar.questTemp.piratesLine == "KillLoy_toJackman")
			{
				link.l1 = "� ��� ������ ����� ������� ���, ���� ������, ��� �� � ����.";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain")
			{				
				dialog.text = ""+ GetSexPhrase("��� ����?! � �� � ���������� �������� �� ���� �������!","��� ����, " + pchar.name + "? � ������ ����� �����...") +"";
				link.l1 = "�������, � ��� � ����� ���� ����� ���� - ������ ���.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork" && !CheckAttribute(npchar, "quest.PQ3"))
			{
				dialog.text = "������"+ GetSexPhrase("��","���") +"! �� �� � ������� ������!";
				link.l1 = "�����"+ GetSexPhrase("","�") +" ��������, ��� ������ ��� ���� � ������ � ������ � ����� ������ � ����.";
				link.l1.go = "PL_SEAWOLF";				
			}
			if (pchar.questTemp.piratesLine == "Panama_backToShip")
			{
				dialog.text = "�, ��� ���� ������, " + pchar.name + ". ��, ��� �������?";
				link.l1 = "�� ������ � ���, ��� ������ ������ � ������?";
				link.l1.go = "PL_Q8";				
			}
			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotte" && !CheckAttribute(npchar, "quest.RoseauCharlotte"))
			{
				link.l1 = "�������, �����! ��� ���������? � ����� ����, �� ��� ����� �� ���������� � ������ ������!";
				link.l1.go = "RoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "NoKillwork" && !CheckAttribute(npchar, "quest.NoKillwork"))
			{
				link.l1 = "�����, �� ��� ����, ����� ������ �� ����� � �� ������.";
				link.l1.go = "NoKillwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "�����, ������ � ����� �� ����. ������� ���� �������� ����� � ������ ����� ����� ������ ������, � ��� �������, ��� �� ��� ���. ����� ���, � ������� ���������� ����� � ��� � ������������ ������� ��������� ����� ������ �� �������...";
				link.l1.go = "ChaniSettlementGoTorus";
			}

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toTorus" && !CheckAttribute(npchar, "quest.RevengeCorsair_toTorus"))
			{
				link.l1 = "�����, � ������, ��� ���� ������ ����� ������������ ��� ��������� ������ ������ ������, ��� �� ������ ����� - � ������ ��� ��� ��� �������� - ��� �����, �� ���������� ���� �� ���� ����?";
				link.l1.go = "RevengeCorsair_toTorus";
			}

			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("� ���� ����� �������? ��������� ���� ��������? ��� ������ ��� �� ����, ��������, ��� ��� ����� ���� �������� ������ ���������.", "��, ��������, ������, �� ��� �����. ���� �������� ������? ������ �� �������� - ����� ���� ������ ������. ���� ������ ���������!");
				link.l1 = RandPhraseSimple("��������, � ���� ��������� ��������...", "������ ��� ������ ��� ��������...");
				link.l1.go = "Roseau_town";
				break;
			}
			//��������� �������� - �����
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && NPChar.city == pchar.GenQuest.CaptainComission.PiratesCity)
			{
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
				{
					link.l1 = "� �� ������ ������ ��������.";
					link.l1.go = "CapComission1";
					DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
				}	
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.PirateShips"))
				{
					link.l1 = "���������� �����, � �� ������ ������ ���������.";
					link.l1.go = "CapComission3";
				}
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
				{
					link.l1 = "� �� ������ ������ ��������.";
					link.l1.go = "CapComission6";
				}
			}
	
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
            dialog.text = NPCStringReactionRepeat(GetFullName(pchar) + ", ��� ���� ������! ����� ���������"+ GetSexPhrase("","�") +" �� ���� ���?",
                         "�� ��� ���� ���?", "����� ��� ����� ������������? ���� ���� ������ ������, �� �������� ������!",
                         "�� "+ GetSexPhrase("������� �����","������� �������") +", ������� ���� ����. �� �������� � ������������� � ����� � ������ �� �����.", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��, ����������, ������ ��� ��������"+ GetSexPhrase("","�") +", ���������. ������ �� ���� ���.",
                                               "������, ������ ���...",
                                               "������, �����, ������...",
                                               "��� ���� ������, �������"+ GetSexPhrase("��","���") +"!!!", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";

			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("� ���� ����� �������? ��������� ���� ��������? ��� ������ ��� �� ����, ��������, ��� ��� ����� ���� �������� ������ ���������.", "��, ��������, ������, �� ��� �����. ���� �������� ������? ������ �� �������� - ����� ���� ������ ������. ���� ������ ���������!");
				link.l1 = RandPhraseSimple("��������, � ���� ��������� ��������...", "������ ��� ������ ��� ��������...");
				link.l1.go = "Roseau_town";
				break;
			}
			//������ ����� ������ ��������
			if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "������, �����, ��� ����� ����... � �����, �� �������� �� � ���� � ����� ���� ''������ ��������''?";
				link.l1.go = "BlueBird_1";
			}
			if (pchar.questTemp.BlueBird == "weWon")
			{
				link.l1 = "�������������, � ���� �������"+ GetSexPhrase("","�") +" ���� ���� ''������ ��������''!";
				link.l1.go = "BlueBird_6";
			}
			//��������� ������� ������
			if (pchar.questTemp.piratesLine == "KillLoy_toJackman")
			{
				link.l1 = "� ��� ������ ����� ������� ���, ���� ������, ��� �� � ����.";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain")
			{				
				dialog.text = ""+ GetSexPhrase("��� ����?! � �� � ���������� �������� �� ���� �������!","��� ����, " + pchar.name + "? � ����� �����...") +"";
				link.l1 = "�������, � ��� ���� � ����� ����� ����. ������ ���.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork" && !CheckAttribute(npchar, "quest.PQ3"))
			{
				dialog.text = "������"+ GetSexPhrase("��","���") +"! �� �� � ������� ������!";
				link.l1 = "�����"+ GetSexPhrase("","�") +" ��������, ��� ������ ��� ���� � ������ � ������ � ����� ������ � ����.";
				link.l1.go = "PL_SEAWOLF";				
			}
			if (pchar.questTemp.piratesLine == "Panama_backToShip")
			{
				dialog.text = "�, ��� ���� ������, " + pchar.name + ". ��, ��� �������?";
				link.l1 = "�� ������ � ���, ��� ������ ������ � ������?";
				link.l1.go = "PL_Q8";				
			}
			// ���� ��� �������-����
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotte" && !CheckAttribute(npchar, "quest.RoseauCharlotte"))
			{
				link.l1 = "�������, �����! ��� ���������?";
				link.l1.go = "RoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "NoKillwork" && !CheckAttribute(npchar, "quest.NoKillwork"))
			{
				link.l1 = "�����, �� ��� ����, ����� ������ �� ����� � �� ������.";
				link.l1.go = "NoKillwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlementGoTorus" && !CheckAttribute(npchar, "quest.ChaniSettlementGoTorus"))
			{
				link.l1 = "�����, ������ � ����� �� ����. ������� ���� �������� ����� � ������ ����� ����� ������ ������, � ��� �������, ��� �� ��� ���. ����� ���, � ������� ���������� ����� � ��� � ������������ ������� ��������� ����� ������ �� �������...";
				link.l1.go = "ChaniSettlementGoTorus";
			}

			// ����� �������
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_toTorus" && !CheckAttribute(npchar, "quest.RevengeCorsair_toTorus"))
			{
				link.l1 = "�����, � ������, ��� ���� ������ ����� ������������ ��� ��������� ������� ������ ������, ��� �� ������ ����� - � ������ ��� ��� ��� �������� - ��� �����, �� ���������� ���� �� ���� ����?";
				link.l1.go = "RevengeCorsair_toTorus";
			}

			//��������� �������� - �����
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
			{
				link.l1 = "� �� ������ ������ ��������.";
				link.l1.go = "CapComission1";
				DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
			}
		break;
		//********************* �������, ����������� �� ����� �1 *********************
		case "PL_Q1_1":
			if(CheckAttribute(NPChar, "notQuestLine")) 
			{
				dialog.text = "������������, ��� �� � ���������� ������� � ������� ������. ������� ��������� ������ �������� ��������� �����?! �� ����� � � ����� ������������, ������� ����� ���� ��������� �� �������� � ���������� ����� ������. �� �����...";
				link.l1 = "����... �� �, ����������, ������ ��� �������"+ GetSexPhrase("","�") +". �� ������ ������...";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "� ���� ������ ���. �� ���� �� ����� �� �����"+ GetSexPhrase("","�") +", �� ����������� � �������� -  ����� ��� �������� �����. � ���� ������ ������ ���-�� ����.";
				link.l1 = "� ��� �� ������ � ���� ������?";
				link.l1.go = "PL_Q1_2";
			}	
		
		break;

//======================= ��������� ������� ===================================

		case "PL_Q1_2":
			dialog.text = "�� ����� ���. ���"+ GetSexPhrase("","�") +" � ���� ��������.";
			link.l1 = "�������...";
			link.l1.go = "exit";
			pchar.questTemp.piratesLine = "toFirstQuest";
			AddQuestRecord("Pir_Line_0_Waiting", "2");

	sld = GetCharacter(NPC_GenerateCharacter("QuestPirate1", "officer_9", "man", "man", 20, PIRATE, -1, true, "quest"));
	sld.name = "�������";
	sld.lastname = "�����";
	sld.rank = 20;
	sld.city = "PuertoPrincipe";
	sld.location	= "Vestpunt_town";
	sld.location.group = "goto";
	sld.location.locator = "goto8";
	sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
	sld.dialog.currentnode   = "PiratesMan1";
	sld.greeting = "Gr_EvilPirate";
	sld.talker = 8; //������ ������
	sld.TiedItems.itm1.model = "HandsItems\meet";
	sld.TiedItems.itm1.locator = "Saber_hand";	
	sld.TiedItems.itm2.model = "HandsItems\cup";
	sld.TiedItems.itm2.locator = "Saber_hand";
	LAi_SetLoginTime(sld, 6.0, 21.99);
	LAi_SetCitizenType(sld);
	LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");

		break;

		//********************* �������, ����� �3, ������ ��� *********************
		case "PL_Q3_1":
			dialog.text = "�����?! ��! �� ������ ���"+ GetSexPhrase("��, ��������","��") +", . ��, ������! � �� ���� �"+ GetSexPhrase("��","�") +"!!!";
			link.l1 = "�� �����"+ GetSexPhrase("","�") +"!..";
			link.l1.go = "PL_Q3_fight";
		break;
		case "PL_Q3_fight":
			LAi_LocationFightDisable(&Locations[FindLocation("Roseau_Roomtownhall")], false);
			chrDisableReloadToLocation = true; // ������� ����� �� �������.
            for (i=1; i<=3; i++)
            {
                sld = GetCharacter(NPC_GenerateCharacter("QuestPir_"+i, "pirate_"+i, "man", "man", 100, PIRATE, 0, true, "quest"));
                FantomMakeCoolFighter(sld, 100, 100, 100, "topor_02", "pistol3", "bullet", 100);
            	LAi_SetWarriorType(sld);
				LAi_SetImmortal(sld, true);
            	sld.Dialog.Filename = "Gothic_Quest\EngLineNpc_2.c";
                LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
               	ChangeCharacterAddressGroup(sld, pchar.location, "reload",  "reload1");
            }
            LAi_group_SetLookRadius("PIRATE_CITIZENS", 100);
            LAi_group_SetRelation("PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("PIRATE_CITIZENS", LAI_GROUP_PLAYER, false);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "PL_Q3_2":
			dialog.text = "���?! ����� � ���� ���� � ���?";
			link.l1 = "� ���� ��� ��� � ���. �� ���-�� ������� �������, � ��� �������� ���� �������� �������. ������ ���������, ����� � ��� ���?";
			link.l1.go = "PL_Q3_3";	
		break;
		case "PL_Q3_3":
			dialog.text = "��. �� � ������� ����� ���������? ������ �������, ��� � ���� ������ ���������. �� ���� ���������� ����� ��� ����!";
			link.l1 = "��, � ����, ������ �� ����� ��� �� ���������.";
			link.l1.go = "PL_Q3_4";
		break;
		case "PL_Q3_4":
			dialog.text = "�� ��, ��� ��� ����! � ���� ��� ����� �������� �����������! ��� � ���� ����������, ��� � ��� ������ ���� ������! �� �� ���� ���������� �� ��� ������ ���� � ��� ������ ��������! � �� ���������� �� ��������� ����! ������� ������� ��������, �� ��, ��� ��� ���� ���������.\n����� ��� ������� ���������� ����� ������������ �� �����, � ��� ��� � ������: �� �������� ''������� ����'' - ����� ������ ����� � ������ � ��� �������! ���� ����� ����� ����.";;
			link.l1 = "�� ���� �� ����� �������� ������, ������ ���������� ������...";
			link.l1.go = "PL_Q3_5";
		break;
		case "PL_Q3_5":
			dialog.text = "�� ��� � ���, �������. �� ���� � ��� �������, ����� � ������� ��� ������ ��������� �� ��������������. �� � ������ � ������ ������, ��� � ���� ������ �������! � ���� ����� �������� ��������, ����� � ��������� ��� �����.\n" +
				"������, ��������, ����� ������� ��� ������. ��� �� �����, � ���� ����� �����. � ����, ���� ��� ����, �� ��� �������... ����� �� ���� - �� ������ ������������ �� ������! � ���� ��� ��� �����! ���!!! ������� ���� ���� ���������, ����� ��� �����, ��� ������ � ���� ������ �� ����, �� �� �������, � �� ����! � ����� �� ���� ���������.";
			link.l1 = "������, ����� ������� �� ��� �������. �����, ������ ��� �� ���� ������.";
			link.l1.go = "PL_Q3_6";
		break;
		case "PL_Q3_6":
			dialog.text = "�����?";
			link.l1 = "������ �� ��� � ������� ���������? �� �� ����� ������.";
			link.l1.go = "PL_Q3_7";
		break;
		case "PL_Q3_7":
			dialog.text = "��, ������... ��� � ������, ���� �������... ��������� ��������, ����������� �����, ���������, �������, �����!  �������� �����, ������? ����� �� ��� � ������, ��������� ���� ���� ����� ���, ��� ��������� ����� ����� �����... � �� �������� ����� ��� ���������.\n" +
				"�� ���� ��� ������, ���-�� �� ��� ������ �����, �� ������� ������������, ���-�� ������� � ����� �����, ���-�� ����������� �������, �� ��������� ����� ���. � ���-��, ��� ����� ������, ��� ������, � ���� ���� �������������, � ����� ��� �� ����� �����, ������� �� ������. ��, � ������, �� �� ��������� � ��� �... ������"+ GetSexPhrase("","�") +", ��������, ���������: ''������� �������� ����''? ��� ���, ��� �� - ������ ����...\n"+"���� ������� ������ ������� �������, ��� ����-��������. �� ���� ����� �����, �������� ������ �������� ����� ������ ������ � ������� �����. ��� ����� ��� �����������, �� ����... ����, ����� �� ��������! ������ ��� ������ ���� ����� ����� ������ �������� � ������� �������... ��� ����� ���������.";
			link.l1 = "���-��, ����� �� � �� ���������"+ GetSexPhrase("","�") +". ��������, �����... ��� ������� - ��� � ����. � ���"+ GetSexPhrase("","�") +" � �������� ���"+ GetSexPhrase("���","�����") +"-���������. � ����� � ������ ������, ��� ����, ���� "+ GetSexPhrase("������� ���� ������, ����� ��� ������","���� ������ ��, ��� ���� ����") +".";
			link.l1.go = "PL_Q3_8";
		break;
		case "PL_Q3_8":
			dialog.text = "��-��-��, �� ����, ���"+ GetSexPhrase("�","����") +"-��������! � ����������� � �������!";
			link.l1 = "���, ����� ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			AddQuestRecord("Pir_Line_3_KillLoy", "12");
			pchar.questTemp.piratesLine = "KillLoy_2toTavernAgain";
		break;
		//����� ������� ���
		case "PL_SEAWOLF":
			NextDiag.TempNode = "I_know_you_good";
			npchar.quest.PQ3 = true;
	                                       int iMar = 0;
	                                       for(i = 0; i < COMPANION_MAX; i++)
	                                     {
		                    iTemp = GetCompanionIndex(pchar, i);
		                    if(iTemp > 0)
		                  {
			sld = GetCharacter(iTemp);
			if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_BRIGSW && sld.ship.name == "������� ����") iMar = 1;
		     }
	                   } // ���� �� � ��� ������� ����
	                    if (iMar == 1) // ����
	                  {
				dialog.text = "������ ���� ���� � � ����. ����, ��� ��� � ��� ���������� ���� �����"+ GetSexPhrase("","�") +" ����������! �������. �� �������"+ GetSexPhrase("","�") +", ��� �� � ���"+ GetSexPhrase("�","����") +"! ������� � ������ ������� ����� ���� ''�������� �����'', ������ �� �����! ����� �� � ����� "+ GetSexPhrase("������ �����","����� ����� ������") +", ��� ��, � ����� �������!";
				link.l1 = "� - ��������� �������, �����. �� ���� ����� - ����� ��� ����!";
				link.l1.go = "exit";
				AddQuestRecord("Pir_Line_3_KillLoy", "19");
			ChangeCharacterComplexReputation(pchar, "nobility", 3);	
			}
			else
			{
				dialog.text = "������ ���� ���� � � ����. �� ��� ��, ������� ����, "+ GetSexPhrase("��������","�������") +". � ������� �� ����� ��� ���� 20 ����� ����!";
				link.l1 = "�������, �����! ��� ������ ��� ����������.";
				link.l1.go = "exit";
				AddMoneyToCharacter(pchar, 20000);
				AddQuestRecord("Pir_Line_3_KillLoy", "20");	
				AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","�"));
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
			ChangeCharacterComplexReputation(pchar, "nobility", 3);	
			}
		break;

		//********************* �������, ����� �6. ������� *********************
		case "PL_Q6":
			dialog.text = "�-�-�, ���� � ����?! ������ �� ����!";
			link.l1 = "������ ������ � ���� �������, ��� ������� ����� �����.";
			link.l1.go = "PL_Q6_1";
		break;
		case "PL_Q6_1":
			dialog.text = "��� ���, ������... ������� �� �� ��������... � ��� ��� ���������?";
			link.l1 = "� ����"+ GetSexPhrase("","�") +" ��� � ���������� �������... ���������, ��� ������� ����� ����������. � �� ��� ��������� �����"+ GetSexPhrase("","�") +" ����� ������, � ���������, ��� ��� ���������� ���� �������.";
			link.l1.go = "PL_Q6_2";
		break;
		case "PL_Q6_2":
			dialog.text = "������ ���, ���� �����?";
			link.l1 = "���... � �����, � ����� ����� �� ����� ������ � ������� ��������� ��������, ��� ��� �� ������� ���� �� ������. ������, ��� ����� �������������� ���-��� �������, � ��� �� �������� ����������, ��� � �� �������.";
			link.l1.go = "PL_Q6_3";
		break;
		case "PL_Q6_3":
			dialog.text = "��, �� ����! � �� �� � �����, ��� �� ��� ��������"+ GetSexPhrase("","�") +" ���� ������� - ������ �� ���� �����, � ����"+ GetSexPhrase("","�") +" ��� ��������?";
			link.l1 = "�?!!";
			link.l1.go = "PL_Q6_4";
		break;
		case "PL_Q6_4":
			dialog.text = "��, ������ ����� ����� �����. ������� � ������ ������ �� ����, ��� ������ ���� �����.";
			link.l1 = "������!! ����� ��� �� �������!";
			link.l1.go = "PL_Q6_5";
		break;
		case "PL_Q6_5":
			dialog.text = "����������� � ������ ��������, ��� �������� ������. ��� � ����� �� ������� ''���������'' ����� ���� ����, � ���� ��� �������� � ��������. ��� �������, ���� ����� ����� ��������� ��� ���������...";
			link.l1 = "������, �����, ��� � ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			SetQuestHeader("Pir_Line_6_Jackman");
			AddQuestRecord("Pir_Line_6_Jackman", "2");
			AddQuestUserData("Pir_Line_6_Jackman", "sSex", GetSexPhrase("","�"));
			pchar.questTemp.piratesLine = "PL6Brother_toSantaCatalina";
			//������ ����� ����� � ����� ��������
			sld = GetCharacter(NPC_GenerateCharacter("JohnLids", "mercen_12", "man", "man", 30, sti(pchar.nation), -1, true, "soldier"));	
			FantomMakeCoolSailor(sld, SHIP_FRIGATE, "���������", CANNON_TYPE_CULVERINE_LBS18, 80, 60, 60);
			sld.name = "����";
			sld.lastname = "����";
			sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
			sld.dialog.currentnode   = "First time";	        
			sld.DeckDialogNode = "JohnLids";		
			sld.Abordage.Enable = false;
			sld.AnalizeShips = true; 
			sld.AlwaysFriend = true;
			sld.ShipEnemyDisable = true;
			sld.Ship.Mode = "Pirate";
			sld.greeting = "Gr_MiddPirate";
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			Group_AddCharacter("LidsGroup", "JohnLids");
			Group_SetGroupCommander("LidsGroup", "JohnLids");			
			Group_SetAddress("LidsGroup", "Beliz", "quest_ships", "Quest_ship_11");
			Group_SetTaskNone("LidsGroup");
		break;

		case "PL_Q6_after":
			dialog.text = "���� ��� ��������� ��� � ����� �������� � "+ GetSexPhrase("���������","''��c�������''") +". ���� ������� ������ ���-������ ����������?";
			link.l1 = "���������� �������, �� � ������. ��"+ GetSexPhrase("","�") +" ������� �������"+ GetSexPhrase("��","���") +", ������, ����"+ GetSexPhrase("��","���") +" ��������� ���-�� ������.";
			link.l1.go = "PL_Q6_after_1";
		break;
		case "PL_Q6_after_1":
			dialog.text = "��� �����. �� ����� ����� �����-�� �������, �������� �������. ���� ����� �� ����� �������, �� ����� ���� ���������� - � ����� �����! ������ ���� �� �������.";
			link.l1 = "� �������. "+ GetSexPhrase("�������","''���������''") +" ���� ���-�� ����"+ GetSexPhrase("","�") +"... ���� �������� ��������, ��� �� ���� ���� �����.";
			link.l1.go = "PL_Q6_after_2";
		break;
		case "PL_Q6_after_2":
			dialog.text = "�����. �� ��� ��, ������, ��� �� �� ��� ��������"+ GetSexPhrase("","�") +", ��������� ��������� ������ ������, ��� �������. ������ ����������� � �������, ������� ��� � ����"+ GetSexPhrase("� ��������","� ''���������''") +".";
			link.l1 = "��, ���� �� �������... �����, �����, � ��� �� �������, ����� �������, ��� � ����"+ GetSexPhrase("","�") +" �������� ���� �������?";
			link.l1.go = "PL_Q6_after_3";
		break;
		case "PL_Q6_after_3":
			dialog.text = "��, � ��� ����� ���� ����� �� �����... ���� ������ �������, ��� ���� ����� "+ GetSexPhrase("��������","''���������''") +" � ������, � "+ GetSexPhrase("��� �������","�� �����") +", ��� ����"+ GetSexPhrase("","�") +" �������, �� ���"+ GetSexPhrase("","��") +" ��������� ����� ��� �����, ��� ������"+ GetSexPhrase("��","���") +" ��.";
			link.l1 = "�������. ������ ������������� �������.";
			link.l1.go = "exit";
			SetQuestHeader("Pir_Line_6_Jackman");
			AddQuestRecord("Pir_Line_6_Jackman", "5");
			QuestSetCurrentNode("Henry Morgan", "PL_Q7_begin");
			sld = characterFromId("Henry Morgan");
			LAi_SetHuberTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "PortRoyal_houseS1", "sit", "sit2");
		break;

		//********************* ��������� ������� *********************
		case "PL_Q8_deck":
			dialog.text = "�� ��� ������� ����� � ���� �� ������. ��� ����� ������ ���� �� ����� �����!";
			link.l1 = "��, � �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;
		case "PL_Q8_deck_1":
			dialog.text = "��, ����� �� ����� �������, �� ����� � ����...";
			link.l1 = "��� � �������, �� ���������, �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;

		case "PL_Q8":
			dialog.text = "����, �������...";
			link.l1 = "��� ������� �� ����� ������?";
			link.l1.go = "PL_Q8_1";
		break;
		case "PL_Q8_1":
			dialog.text = "������ �� �����. �� � ������, ��� �� ���� ����, �� ��� ���, ����� ��� ������ ���� ����������� ��� �����! ��� ��� � ����� ������ �� ��� ������ �� ����.";
			link.l1 = "����, ��� �� ���?!";
			link.l1.go = "PL_Q8_2";
		break;
		case "PL_Q8_2":
			dialog.text = "� ��� ���! � �����, � ���� ����� ���� ������! ������ ������� �� �������������� ����� �� ����� ������.";
			link.l1 = "��, ����... � ��� ��?";
			link.l1.go = "PL_Q8_3";
		break;

		case "PL_Q8_3":
			dialog.text = "�� ����, ���� ���� - ����� �������� ����� ���.";
			link.l1 = "�������...?";
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			pchar.questTemp.piratesLine = "Panama_inEngland";
		break;


		//*************************** ��������� "��������� �������� - �����" **********************
		case "CapComission1":
			dialog.text = "��-��. �� �������, � ���� ������ ���� �������? �������, ���� ��������� ������ � ����?";
			link.l1 = pchar.GenQuest.CaptainComission.SlaveName + ". ���� �����?";
			link.l1.go = "CapComission2";
			DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
		break;

		case "CapComission2":
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.DaysLeft"))
			{
				dialog.text = "���. � ��� ������ � �������� ������ ����� ���������� � ��������� - ���������� ������, �� ������� �� ������� ������.";
				link.l1 = "��� ����...";
				link.l1.go = "CapComission2_1";
			}
			else
			{
				dialog.text = "�-�, �� �������-��. � �� ���� ��������� ������� ��� � �������� ������ ����� ���������� � ���������, �� ������ ��������� � ���� ����� ������-������... �� ����� ������"+ GetSexPhrase("","��") +"?";
				link.l1 = "������, �����, ��� ����� ����... � �����, � ���� ��� ����� �����. �� � �����"+ GetSexPhrase("","�") +" ����������.";
				link.l1.go = "CapComission2_2";
				if(makeint(pchar.money) > 150000)
				{
					link.l2 = "������, ��� �� ������. ��� ������ - 150000 ����. ��� � ���� ��� �������?"
					link.l2.go = "CapComission2_3";
				}	
			}
		break;
		
		case "CapComission2_1":
			dialog.text = "����� �� �����"+ GetSexPhrase("��","���") +"... � ������, ���� ��������� � ���� ����� �����? �, ��������, ��� ������������� ����� ��������.";
			link.l1 = "�� � �� ��������� ���� ������������� � �������"+ GetSexPhrase("","�") +".";
			link.l1.go = "CapComission2_11";
		break;
		
		case "CapComission2_11":
			dialog.text = "��, �������"+ GetSexPhrase("","�") +" �� - ��� � ���� ��������?";
			link.l1 = "������, � �� ������� ������, ���� �� ������?"; 
			link.l1.go = "CapComission2_12";
		break;
		
		case "CapComission2_12":
			dialog.text = "�-�, �� ������, �������, �� � ���� �� �����. � �� �������� ������, ��-��-��-��... ��, �����.";
			link.l1 = "���������.";
			link.l1.go = "exit";
			AddQuestRecord("CaptainComission1", "10");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			CaptainComission_GenerateManager();
		break;
		
		case "CapComission2_2":
			if(rand(1) == 0)
			{
				dialog.text = "���-���... ���� � ���� ���� ����... ���� �� ����, ��� ������... � �����, ����� ������� �� ��� ������ ������������ ������.";
				link.l1 = "� ����� ������ ������ ��� � ��������?";
				link.l1.go = "CapComission2_2_1";
			}
			else
			{
				dialog.text = "��, " + pchar.name + ", �� �� ������, ��� ��� ���� �� ��������. ������� � �������� � �������� ������ ��������, ��-��.";
				link.l1 = "�� �����, �� �������.";
				link.l1.go = "CapComission2_4";
			}
		break;

		case "CapComission2_2_1":
			dialog.text = "��, ��������� ��, ��� ��������� ���� �� ��������... ��� �� ������ ��� �����, ��� ����� ������ ����� � ������� ������� �������� ��� �� ��� ����� ������. ����, ���� �� ���������� � ���������� - � �� ��������.";
			link.l1 = "� ������ ���� �� ������� �� ��� ����� �����?";
			link.l1.go = "CapComission2_2_2";
		break;
		
		case "CapComission2_2_2":
			CaptainComission_GetRandomShore();
			pchar.GenQuest.CaptainComission.ShipName1 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.ShipName2 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.UnknownPirateName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);
			sLoc = XI_ConvertString(pchar.GenQuest.CaptainComission.Island + "Abl");
			dialog.text = "��... � ����� ����� " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.UnknownPirateName, NAME_NOM) + " ������ ����� �������, ��� � ����� ������� ���� " + XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Gen") + " ���� � �� ����. ������� ��� ������� � ����� � �� ���� ����� ''" + pchar.GenQuest.CaptainComission.ShipName1 + "'' � ''" + pchar.GenQuest.CaptainComission.ShipName2 + "'' ���� � " + sLoc + ". ��������� ������, ������ � �� ���� �������� ��� ���� ����� �����?";
			link.l1 = "�������. � ������� � ���� ���� �������?";
			link.l1.go = "CapComission2_2_3";
		break;
		
		case "CapComission2_2_3":
			dialog.text = "�����, ���� 12-15, �� ������. ��� �����, ���� ��� �� ������ ��������� �� �������, ����� ������ �� � ������ ������ �� ����� �� ����� ������. �� ����� ����� ����� ��� ����.";
			link.l1 = "������, � ������ �� ��� ����. ���������� ������.";
			link.l1.go = "CapComission2_2_4";
		break;
		
		case "CapComission2_2_4":
			AddQuestRecord("CaptainComission1", "24");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sShipName1", pchar.GenQuest.CaptainComission.ShipName1);
			AddQuestUserData("CaptainComission1", "sShipName2", pchar.GenQuest.CaptainComission.ShipName2);
			AddQuestUserData("CaptainComission1", "sShoreName", XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Abl"));
			AddQuestUserData("CaptainComission1", "sShoreType", XI_ConvertString(GetIslandByArealName(pchar.GenQuest.CaptainComission.Island) + "Dat"));
			pchar.quest.CapComission_PirateAttack.win_condition.l1 = "location";
            pchar.quest.CapComission_PirateAttack.win_condition.l1.location = pchar.GenQuest.CaptainComission.Island;
            pchar.quest.CapComission_PirateAttack.function = "CaptainComission_GeneratePirateShips"; 
			SetFunctionTimerCondition("CaptainComission_PirateShipsOver", 0, 0, 15, false);
			pchar.GenQuest.CaptainComission.PirateShips = "goaway";	
			DialogExit();
		break;
		
		case "CapComission2_3":
			dialog.text = "�� ���������. ��� ���� �������� ��� � ���� �� ����. � �� ���� ���?";
			link.l1 = "�����. � �������� ��������� ��� ������������.";
			link.l1.go = "CapComission2_31";
		break;
		
		case "CapComission2_31":
			dialog.text = "�-�, ��� ������. � �� � �� ���� �����������, ��� ����������, �������� ����� ������ ���� �� ������ ��������. ��-��-��-��... ��, �����.";
			link.l1 = "���������.";
			link.l1.go = "CapComission2_32";
		break;
		
		case "CapComission2_32":
			AddQuestRecord("CaptainComission1", "9");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City));			
			addMoneyToCharacter(pchar, -150000);
			DialogExit();
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission2_4":
			if(!CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				AddQuestRecord("CaptainComission1", "31");
				AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			}	
			pchar.GenQuest.CaptainComission.RepeatSpeak = true;		
			DialogExit();
		break;
		
		case "CapComission3":
			dialog.text = "�� ���, " + GetFullName(pchar) + ", ������"+ GetSexPhrase("","�") +" �� ��� ����� ��������?.. ��-��-��...";
			if(pchar.GenQuest.CaptainComission.PirateShips == "goaway")
			{
				link.l1 = "���. � �� �����"+ GetSexPhrase("","�") +" �� �������. � �� �������� ���� ��� ��� �� ����������.";
				link.l1.go = "CapComission4";
			}
			if(pchar.GenQuest.CaptainComission.PirateShips == "died")	
			{
				link.l1 = "��, ��� � �������������� - ��������"+ GetSexPhrase("","�") +" ������� ����.";
				link.l1.go = "CapComission5";
			}
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
		break;
		
		case "CapComission4":
			dialog.text = "׸��! ���������� - �� ����������, ����� ������ �������?.. ��, � ��� �� ���������� ������?";
			link.l1 = "�����, � ���� ���� �����-������ ��������� �������?";
			link.l1.go = "CapComission4_1";
			link.l2 = "������, �����, ������ ��� ����� �������� ���������...";
			link.l2.go = "CapComission4_2";
		break;
		
		case "CapComission4_1":
			dialog.text = "���.";
			link.l1 = "...��, ����� ��������� ����������...";
			link.l1.go = "CapComission4_3";
		break;
		
		case "CapComission4_2":
			dialog.text = "���������?!! ������ ��� ��-�� ����� ��������������� � ������� ������ �������! � ������ � ���� �������� ��� ��������! ������� �� 200000, ���� ������.";
			link.l1 = "������ ���... ������...";
			link.l1.go = "CapComission4_4";
			if(sti(pchar.money) >= 200000)
			{
				link.l2 = "� ����, ����� ���� ������.";
				link.l2.go = "CapComission4_5";
			}	
		break;
		
		case "CapComission4_3":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "27");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","��"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_DAT));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();
		break;
		
		case "CapComission4_4":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "28");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
		break;
		
		case "CapComission4_5":
			dialog.text = "������ ������� ��������...";
			link.l1 = "��������� ����������.";
			link.l1.go = "CapComission4_6";
		break;
		
		case "CapComission4_6":
			addMoneyToCharacter(pchar, -200000);
			AddQuestRecord("CaptainComission1", "29");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			pchar.GenQuest.CaptainComission.SlaveAddMoney = true;
			DialogExit();	
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission5":
			dialog.text = "��-��! ��� ��� ������! ������� ������ �������� � ����� ������"+ GetSexPhrase("","�") +".";
			link.l1 = "�������. ��������� ����������.";
			link.l1.go = "CapComission5_1";
		break;
		
		case "CapComission5_1":
			AddQuestRecord("CaptainComission1", "34");
			AddQuestUserData("CaptainComission1", "sName", pchar.GenQuest.CaptainComission.SlaveName);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission6":
			dialog.text = "�� ����� ������"+ GetSexPhrase("","��") +"? ���� � �� �����, ����� ������, ��� ������ ��� �����������.";			
			link.l1 = "������, "+ NPChar.name +", ��� ����� ����... � �����, � ���� ��� ����� �����. �� � �����"+ GetSexPhrase("","�") +" ����������.";
			link.l1.go = "CapComission2_2";
			if(makeint(pchar.money) > 150000)
			{
				link.l2 = "������, ��� �� ������. ��� ������ - 150000 ����. ��� � ���� ��� �������?"
				link.l2.go = "CapComission2_3";
			}			
		break;

		//*************************** ����� "������������� ������ "�����"" **********************
        case "Andre_Abel_Quest_Torus_Dialog_1":
			dialog.text = "��� ���� �� ���� �����, " + pchar.name + "?";
			link.l1 = "� �� ����, �����...";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_2";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_2":
			dialog.text = "����������, ��� � ���� �� ����.";
			link.l1 = "���� �� ���� ��� ������... � �����, � �����, �� ������� �������� �� ����� ����� �����?";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_3";
		break;

		case "Andre_Abel_Quest_Torus_Dialog_3":
			dialog.text = "�����?! ��-��... �� ���, �������� ���� ��������?! ����� �� ��� �����"+ GetSexPhrase("","��") +" �� ���� ��� ����?";
			link.l1 = "���, �� �����"+ GetSexPhrase("","��") +". ��������� ����� ���������, �� ������ ��������� �� ����, � ������ ���������� ��� ������������. ���� ���������� ������ �������� ����.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_4";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_4":
			dialog.text = "� ��� ��� �������� ��� ������������? ��?! �������, � �� ����, ��� �� ������ ������� � ������ ������ � ����-�-������?! �����, ��� ����� ���� ������?!\n������, ����� ���� �� �������� ��������. � �� ���������, ���� �� ������ ��, ��� ��� �����������.";
			link.l1 = "�� ��� �, ������, �������, ����."+ GetSexPhrase(" ������ �� �������, ��� ����� �������, � ���� �������...","") +"";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_5";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_5":
			dialog.text = ""+ GetSexPhrase("��� �� ������?! �� ���, ��������� ��� �������� � ���� �� ����������?!\n������, � ��-�� ���������� ����� ��������� � �������� ������ ������!","�� ������� �� ���, � ���� ���! � ���� ���, ��� ��� ��� ������� ������?") +"";
			link.l1 = ""+ GetSexPhrase("��� ��, �����? ����� ������? ������ ��������, ��� �� �� ���� ����������.","���. �����, �����.") +"";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_6";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_6":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			DoFunctionReloadToLocation("Roseau_town", "reload", "reload8_back", "Andre_Abel_Quest_After_First_Torus_Dialog");
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_7":
			dialog.text = "����� ��? ���� �� �����"+ GetSexPhrase("","��") +" ����� �� �����, �� ����� ����� �������������� �������� � �� ��� ����.";
			link.l1 = "����� �� �����"+ GetSexPhrase("","��") +", ���� �����"+ GetSexPhrase("","��") +" ������ �� �������.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_8";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_8":
			dialog.text = "��, ������ �� �������? �� ��� ����� ��� ����!";
			link.l1 = "�����...";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_9";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_9":
			dialog.text = "������! ����� ���� �����?! \n�����, ����� ���� ��������, � ���� ��������� ���� ��������.";
			link.l1 = "��� � �������.";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_10";
			TakeItemFromCharacter(PChar, "letter_1");	
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_10":
			dialog.text = "������ ������� "+ GetSexPhrase("������ ������","���") +", ��� � ���� �� ������! ��� ��� ����� �� ���������� ��� �� �����, ���� ���� �����..."+ GetSexPhrase(" � ������ ����������, ������ �� ����� ������!","") +"";
			link.l1 = "�� �������, ��� ����. "+ GetSexPhrase("��������� ����������","����, �����") +".";
			link.l1.go = "Andre_Abel_Quest_Torus_Dialog_11";
		break;
			
		case "Andre_Abel_Quest_Torus_Dialog_11":
			DialogExit();
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddQuestRecord("Andre_Abel_Quest", "22");
			AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","�"));
			PChar.QuestTemp.Andre_Abel_Quest_Complete = true;
		break;

        //********************** ������ ����� "������ ��������" ***********************
        case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("�-��, ���������� ����� ������, ��� � ��������... � ����-�� ����� ����������� ���� ����?", 
				"�� ��� �������� �� ���� �����.", 
				"����� ��� �� ��?",
                "���?! �����?! �� � ���� ������...", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�� ������ ��, ����� �� ������������ ���� ������ ���������...", 
				"��, �����, �����.",
                "��, ���� �������"+ GetSexPhrase("","�") +", ������...", 
				"��-��!..", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
  		break;
		case "BlueBird_2":
			dialog.text = "��-��, �� �� �������� ��? � �� ������ �, ��� ������� �� ��������� �� ���� ''������ ��������''.";
			link.l1 = "�������� ������������� ������������ ���� ������. ��, ������, ��� � ����"+ GetSexPhrase("��","�") +" ��������� �� ����, ��� �� �������� �����, �� �������� ���� ������. ��� ��� �� �������� ��������� �������� �� ���� �����!";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "��, ��� ���! �� �� ������, ��� �� ��� ������� �� ���������� ��������, �� ��� ����� ��� �� �������. ��� �� ����, �� ����� ��� ��� ''�����-����'' �� ��������� - ������ ���� ��� ��������� ���.";
			link.l1 = "�����, ��� �� ������, ��� ����?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "���, �������. ������ - ����� � ��������� �����, �� � ���� �� ��������.";
			link.l1 = "�����, ���������� �������������, ��� ������?";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "���, ����� ��� �� ����. �� ����� ������� ����� ����� �����, � ����� ������� ������ � �� ������� �� ���������� ��� �����, �� �� ������� ��� ��������, ���� �� ����� ���� � ���� ��������, ����� ������ � ����-������.";
			link.l1 = "�������. �� ��� �, ������� � �� ����, ��������.";
			link.l1.go = "exit";
		break;

		case "BlueBird_6":
			dialog.text = NPCStringReactionRepeat("��, ����������. ������� �����, ���� ������! �������.", 
				"���������� ��� ���.", 
				"��� � ��� ������...",
                "��, �� �� �������"+ GetSexPhrase("","����") +", "+ GetSexPhrase("��������","�������") +", ����� ������ ��� �� ������!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("�������, �����. ������ ����� � ����� �������...", 
				"��� ��� �������, �����.",
                "�, �� ��...", 
				"������� ����!", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;

		//������ �����-�������
		case "Mushket":
			dialog.text = "" + GetFullName(pchar) + " - ������ ����� ��������!!!";
			link.l1 = "����� �� ����� - ������?";
			link.l1.go = "Mushket_01";
		break;

		case "Mushket_01":
			dialog.text = "������ �� ��� ���������?";
			link.l1 = "������, �����, ���� �� � ��� �� ������� ����� ''������''? ����� ����, ������ �� ����� ������ ��� ������, ��� ����� ��������� ��� ����������?";
			link.l1.go = "Mushket_1";
		break;

		case "Mushket_1":
			dialog.text = "��, ���� ����� ����� - ����� �������� ����, �������, ������ �� ����������. ������ ����� ��� �� ��� �������, � ���� �� ����� ������� ������. ���� �� � ��� ����� �������� - �� �� ��� �� �� �������� ������� ����� ������� ��� ���� ����� ��������.";
			link.l1 = "��� ��� �� ���� �� ������? ��� ��� ����� �����.";
			link.l1.go = "Mushket_2";
			DeleteAttribute(pchar, "questTemp.mushkett2x2");
		break;
		case "Mushket_2":
			dialog.text = "����� � �� �������� - �� ��� �� ����. ������������ - ����� ������, ���� ��������� � ������. � ����� ��� ���������� � ����, �� �� ������ �� ��� ���� ���� ���������, � � �������� ��� ������. � ��, �����������, �������� �������� � �������-����.\n�� � � ������ ����� ���� - ������� �������� � ���� ����, ��� � ������� �� ����� ����� �� ������, � ���� ����� ������ �� ������ � ���������������. ��� ���, ����� �� ���� � ��� �� ��������, ���� ����� - ����� �� ����� ��������.";
			link.l1 = "�� ��... �����, ����������� ���?";
			link.l1.go = "Mushket_3";
		break;
		case "Mushket_3":
			dialog.text = "������, ����� ������ ������ � ����. ������ ����������� �� ����������� ��������� - ���� ���� �� ����� �� ����������, ��� ������ � ���������� �������� ���� ������ ����� �����...";
			link.l1 = "����. �� ��� �, ������� ����, �����.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "2");
		                sld = characterFromId("LeFransua_Mayor");
		                sld.dialog.currentnode = "Mushkett";
		break;
 
        //********************** ���. ������� ��***********************

 		case "GothicLee3_quest":
			dialog.text = "������ ����, ����� ���������"+ GetSexPhrase("","�") +" �� ���?";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" ���� �� ����, ��� ������ ������, ������� ������� ������� ��������� ������.";
			link.l1.go = "Gothic_3_1";
  		break;
 		case "Gothic_3_1":
			dialog.text = "����, ���� ���-��... ��������� �� ����... �� ���-�� ����� ���������� ������ ������, �������, ��� ������������...";
			link.l1 = "� ���?";
			link.l1.go = "Gothic_3_2";
  		break;
 		case "Gothic_3_2":
			dialog.text = "�� ������. �� �����, �������� ������� ���... �� � �� �� ������ ��� ���� - � ������� ������������, ���-�����!";
			link.l1 = "��, � � ����� �������?";
			link.l1.go = "Gothic_3_3";
  		break;
 		case "Gothic_3_3":
			dialog.text = "��� � ����-��-������.";
			link.l1 = "�������... �������, �����.";
			link.l1.go = "exit";
			AddQuestRecord("GothicLee_3_SeekBible", "3");
			pchar.questTemp.GothicLee = "SeekBible_toFFBrothel";
			NextDiag.TempNode = "First time";
  		break;

        case "GothicLee6_talk":
            dialog.text = "���� ��, ������� " + GetFullName(pchar) + " ���������"+ GetSexPhrase("","�") +"! ������ ���! ���������� � � �� ����, ��� ���� �� �������� �������� ���-�� ����������.";
            link.l1 = "� �����, ������ �������� ����������� � �� ��������. ����� ������ ���������� �� ������� � �������� ����� ����� ������� � ����������.";
            link.l1.go = "Gothic_6_1";
        break;
        case "Gothic_6_1":
            dialog.text = "�� ��, ������������� ������ �����������. ��� �����, ��� � � ��� �� ��������� ����������� � ��� ����. ��������� ������� - ��������, �� ������� ������ ������ ������ �����. ��� ��� ���� ����������� ��������� ���� ������� ������ ����.";
            link.l1 = "�� ������. �� ������� ����, � �����"+ GetSexPhrase("","�") +" � ����� ������������ �� ���� �����, � �� �� ������� ���.";
            link.l1.go = "exit";
			pchar.questTemp.Count = makeint(pchar.questTemp.Count)+1;
			NextDiag.TempNode = "I_know_you_good";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "5");
        break;

        //********************** "����" ��� "�������-����" ***********************

                                                         case "RoseauCharlotte":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_15_00.wav");
			dialog.text = "";
			link.l1 = "�� �� ������� ����? � �� ������� ������.";
			link.l1.go = "RoseauCharlotte_1";
  		                   break;

                                                         case "RoseauCharlotte_1":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_01.wav");
			dialog.text = "�� ��� ����� �� �����������, �������� �� ��� ����� �� ���� ���������� � ��� ������ ��� ������ ��������?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_2";
  		                   break;

                                                         case "RoseauCharlotte_1":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_02.wav");
			dialog.text = "��� �� ������!!!";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_2";
  		                   break;

                                                          case "RoseauCharlotte_2":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_03.wav");
			dialog.text = "����� ���� �� ��� ��� ��������� ������, � ����� ��� ��� ���� ���� ���������?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_3";
  		                   break;

                                                         case "RoseauCharlotte_3":
 	                                      PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_04.wav");
			dialog.text = "�, ���?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_4";
  		                   break;

                                                          case "RoseauCharlotte_4":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_ZEIT_12_05.wav");
			dialog.text = "��� ������� ������! ��� ������� ���� ����?";
			link.l1 = "";
			link.l1.go = "RoseauCharlotte_5";
  		                    break;

                                                         case "RoseauCharlotte_5":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_5.wav");
			dialog.text = "";
			link.l1 = "��� � ���� ����� ������?";
			link.l1.go = "RoseauCharlotte_6";
  		                   break;

                                                         case "RoseauCharlotte_6":
			dialog.text = "������ ������ ����� � �������� ����������, � ������� ������� ������, � ��������, �� ������ �������, � �� ����, ������, ����������� � �����....";
			link.l1 = "��, �� � ��� ����, �� �������� ��, ��� - ������?";
			link.l1.go = "RoseauCharlotte_7";
  		                    break;

                                                          case "RoseauCharlotte_7":
			dialog.text = "��������, �� ���� ��� ������, �� ������� � ����� ���� �������� ���������! ��, ���� ���� ����.... ������ ��� ���� �������.";
			link.l1 = "������ ��� ����, ��� �� ����!!!";
			link.l1.go = "RoseauCharlotte_8";
  		                   break;

                                                          case "RoseauCharlotte_8":
			dialog.text = "�����, ��������� � �������, � ����� ������.";
			link.l1 = "������...";
			link.l1.go = "RoseauCharlotte_9";
  		                   break;

                                                          case "RoseauCharlotte_9":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			DialogExit();
		                   AddDialogExitQuestFunction("RoseauCharlotte_toBrothel");
  		                   break;

                                                         case "RoseauCharlotte_10":
			dialog.text = "�������, ������� �����, � ����� ������ �� �����?";
			link.l1 = "� ��� ���� ����? ��� - �� ������� ������ � �� ����� ������ �� ���� �������� ���?";
			link.l1.go = "RoseauCharlotte_11";
  		                   break;

                                                         case "RoseauCharlotte_11":
			dialog.text = "������? �� �� ��� �������� � ����������� ������ �� ���������� ��������. ��� �� ���� �� �����? ������� ��������. ����� �� �������?";
			link.l1 = "�����...";
			link.l1.go = "RoseauCharlotte_12";
  		                   break;

                                                          case "RoseauCharlotte_12":
			DialogExit();
			LAi_ActorGoToLocation(npchar, "reload", "reload3", "Roseau_SecBrRoom", "goto", "goto3", "OpenRoseauBrothel", -1);
  		                   break;


                                                          case "RoseauCharlotte_Brothel":
	                                       sld = CharacterFromID("Torus");
	                                       LAi_ActorTurnToCharacter(sld, characterFromID("Roseau_Hostess"));
			dialog.text = "������, �����, ��� ��������� ��� �����?";
			link.l1 = "�����, � �� ��� ��� �� ���� ������ � ����, ����� ����, ����� ����...";
			link.l1.go = "RoseauCharlotte_Brothel_1";
  		                   break;

                                                          case "RoseauCharlotte_Brothel_1":
			dialog.text = "�����������, ������, �� ���� ���-������?";
			link.l1 = "���, �� ���� �� ������, ����� ��� �����...";
			link.l1.go = "RoseauCharlotte_Brothel_2";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_2":
			dialog.text = "������, ���� � ���?";
			link.l1 = "��.";
			link.l1.go = "RoseauCharlotte_Brothel_3";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_3":
			dialog.text = "�������� ���������� �����?";
			link.l1 = "������.";
			link.l1.go = "RoseauCharlotte_Brothel_4";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_4":
			DialogExit();
			sld = characterFromId("Roseau_Hostess");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload2", "DoubleTalkWithRoseauHostess", -1.0);
  		                   break;

                                                          case "RoseauCharlotte_Brothel_5":
			DialogExit();
                                                          PlaySound("interface\key.wav");//����!
		                   AddDialogExitQuestFunction("RoseauCharlotte_SecBrBrothel");
  		                   break;



                                                         case "RoseauCharlotte_Brothel_6":
			dialog.text = "��� �� ��� �����, ���� ��� � ��������? �� ��� �� ������� �������� � � �� �� ���� ��� �������������� � �����, ������� ��� ����� ��������, �������� ����, ����� ����.";
			link.l1 = "��...��� ��� ����?";
			link.l1.go = "RoseauCharlotte_Brothel_7";
  		                   break;

                                                         case "RoseauCharlotte_Brothel_7":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_31.wav");
			dialog.text = "��� ��� �� �������?";
			link.l1 = "";
			link.l1.go = "exit";
		                   AddDialogExitQuestFunction("RoseauCharlotte_BackDoor");
  		                   break;

                                                          case "RoseauCharlotte_BackDoor":
			dialog.text = "��, ���, ��� �� ������� �� ����?";
			link.l1 = "��, ����� �� ������ ���� �������, � ����� ������ ����� ���� ���������� ��������, ��� ���, ����� ��� � ������ ��� �� ���.";
			link.l1.go = "RoseauCharlotte_BackDoor_1";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_1":
			dialog.text = "��� � � ������ - �������, ����� ����� �������� ���, � �� ��������� ���� �� �������, ����...";
			link.l1 = "������!";
			link.l1.go = "RoseauCharlotte_BackDoor_2";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_2":
			dialog.text = "� ���� ���� �������, ����� ��������� ���� ������� � �������� �����������, �� ��� ����� ��� ������, �� � � ���� �� � ������� ����������, ���� ���� ����� ��, ������� ������, ������ ������������.";
			link.l1 = "� �� ��� ���������?";
			link.l1.go = "RoseauCharlotte_BackDoor_3";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_3":
			dialog.text = "����� ��� ������ ����� ��� ����� - � � ������. ������� ������ � �����, ������, �� ������ � �� �����.";
			link.l1 = "�����, ��� �� ������ �� ����?";
			link.l1.go = "RoseauCharlotte_BackDoor_4";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_4":
			dialog.text = "���� �� ��� �����, �������� � ��� - �� �������. ��� � � ����� � ����� ������� ��������� ����� ��� ���. ��������� ���� ����������� ����� ������, ����� ��� - ������, ��� ��������.";
			link.l1 = "�����, � ��������, ��� ����� �������?";
			link.l1.go = "RoseauCharlotte_BackDoor_5";
  		                   break;

                                                          case "RoseauCharlotte_BackDoor_5":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\HOLDEINGOLD_2.wav");
		                  DialogExit();
		                  AddDialogExitQuestFunction("RoseauCharlotte_BackDoor_03");
  		                   break;

                                                          case "NoKillwork":
			dialog.text = "���, ����� �����������, ��� �� ����������?";
			link.l1 = "��, � ������� ���� ����������� ����� ������, ������� �������� �����������, �������� ������� �� ���������, ��������� - � ����� ���� � �����, ������ �� �����, �� ������...";
			link.l1.go = "NoKillwork_1";
  		                   break;

                                                          case "NoKillwork_1":
			dialog.text = "��� ����!";
			link.l1 = "������, ������� �� ���� ������� ��������� �������� � �������� �� ��� �������. ���� ������������, ��� �� �� ���� �������� ��������� �� ���� ����� ����, ��� ���������� � ��������� �� ��� ������� ������� �� ������.";
			link.l1.go = "NoKillwork_2";
  		                   break;

                                                          case "NoKillwork_2":
			dialog.text = "�, ������ ������� ��� �� ���� ����� - ��� ��� ���� ������������!";
			link.l1 = "������ ������, � ���������� ��� ��� ���������� ��������� ��� �����������, �� ��� ������������� ��������� �������������.";
			link.l1.go = "NoKillwork_3";
  		                   break;

                                                          case "NoKillwork_3":
			dialog.text = "�, ��� �� ����������?";
			link.l1 = "��, �� �������� ������ ��������, ��� � � ����� ���������� �� ���, ��� ��, ��� ��������� ����� ���� ����������� � ��������� ������� ��������� � �� ����� ����.";
			link.l1.go = "NoKillwork_4";
  		                   break;

                                                          case "NoKillwork_4":
			dialog.text = "��, ��� ���������, �� - �� - ��, ������-��...";
			link.l1 = "� ��� ��� ��?";
			link.l1.go = "NoKillwork_5";
  		                   break;

                                                          case "NoKillwork_5":
			dialog.text = "��� ���� ����� � ����� �������.";
			link.l1 = "������.";
			link.l1.go = "NoKillwork_6";
  		                   break;

                                                          case "NoKillwork_6":
		                   DialogExit();
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_Mayor");
  		                   break;

                                                          case "NoKillwork_7":
			dialog.text = "��, �� �� ����� ��� ����, �� �� �������!";
			link.l1 = "��� �� ������ �����?";
			link.l1.go = "NoKillwork_8";
  		                   break;

                                                          case "NoKillwork_8":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_30.wav");
		                   DialogExit();
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_Mayor_4");
  		                   break;

                                                          case "NoKillwork_9":
			dialog.text = "� ������ � �������������� ��������... ��� ������ �� �������, ����������, �������������� ����� - ������������ � ����������� ��������� �����, � ����� - �� ���������� ������� ������!\n�� � ����������� �� ������, ��� ��������, � ����� ������� ����������, ������������ � ������ � ���������� ������� � ��������� �������� �����. ���� ����� ������ ���������� �� �������, ��� ������� ����� ���������� �������� � ������ ����� ������� ��������� �� ������ ������.\n��, ������ �  ��� �� ��� ������ - ������ �� �� ���!�� ��� ��������� ���� ������ �������� �� ���� ������, �� ��������� �� ���� � �� ���� ������ ���, �������� ������ ������� �����, �������� ������ ���������� �� ������� �������, �� ��� ��������� ���������.";
			link.l1 = "��� �� ����?";
			link.l1.go = "NoKillwork_10";
  		                   break;

                                                          case "NoKillwork_10":
			dialog.text = "��������� ������, ������ �������, �� �� ��� ������ �����!";
			link.l1 = "�����-�� ��������� � ���...";
			link.l1.go = "NoKillwork_11";
  		                   break;

                                                          case "NoKillwork_11":
			dialog.text = "���� �� ������ ��������, �� ����� �� ����������.";
			link.l1 = "��, ������ ��������, �� ����� ����� �� �����, �� ������ ������ ���� �� �����?";
			link.l1.go = "NoKillwork_12";
  		                   break;

                                                          case "NoKillwork_12":
			dialog.text = "���� ���. � ������� ����, �� �������, �� - ��! ����� �����! ��, ���� �������� - ���, ��� - ��.";
			link.l1 = "";
			link.l1.go = "exit";
		                   npchar.quest.NoKillwork = "true";
		                   AddDialogExitQuestFunction("NoKillwork_JACK");
  		                   break;

                                                          case "ChaniSettlementGoTorus":
			dialog.text = "�, �� ��� ���?";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_1":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_1.wav");
			dialog.text = "";
			link.l1 = "� ��� � ���� �������!!!";
			link.l1.go = "ChaniSettlementGoTorus_2";
  		                   break;

                                                          case "ChaniSettlementGoTorus_2":
			dialog.text = "�, ��� �� �����?";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_3";
  		                   break;

                                                          case "ChaniSettlementGoTorus_3":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_3.wav");
			dialog.text = "";
			link.l1 = "��� ����� ����� ��������.";
			link.l1.go = "ChaniSettlementGoTorus_4";
  		                   break;

                                                          case "ChaniSettlementGoTorus_4":
			dialog.text = "����� ��� �� �������, ��� �, ���� ������ � ��� ��������, � ��� ��� ����� �����������?";
			link.l1 = "� ��� ��� �� ���� �����, �� ���� ���� ����, ���� ������� ���������, ���� ���� ������ ���� ��� � ��� - �� �������?";
			link.l1.go = "ChaniSettlementGoTorus_5";
  		                   break;

                                                          case "ChaniSettlementGoTorus_5":
			dialog.text = "��, �������...? ������, � ���� ����.";
			link.l1 = "������ ��� �������, ��� �� �� ��������� ����� � �������, � ������� ���� �� ����� �� �������� ���� ��� ��� ���� ������, ��� � � �������!!!";
			link.l1.go = "ChaniSettlementGoTorus_6";
  		                   break;

                                                          case "ChaniSettlementGoTorus_6":
			dialog.text = "� �������, �� ��� ������ � ������ - ��� �� ����! ������ � ����� � ���.";
			link.l1 = "";
			link.l1.go = "ChaniSettlementGoTorus_7";
  		                   break;

                                                          case "ChaniSettlementGoTorus_7":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_1.wav");
			dialog.text = "";
			link.l1 = "�...��� �� ������� ������ ������?";
			link.l1.go = "ChaniSettlementGoTorus_8";
  		                   break;

                                                          case "ChaniSettlementGoTorus_8":
			dialog.text = "������� ���������, ���� ��������� � ���������� ����� ������, ������ ������ ����� � ��������� ����� �� �����...";
			link.l1 = "�� ���� �� �����, ������� ������� �� �������� ������� ���� ������ � ������ ������������ ������ �����������. �� �� � ���� ������ ���� �������� � ���� � ����� ������� ��������, ��� ���...";
			link.l1.go = "ChaniSettlementGoTorus_9";
  		                   break;

                                                          case "ChaniSettlementGoTorus_9":
			dialog.text = "��, �������������� ���, �� ��� ��� ����. � ���, ��� �������� ����, �� ��������� �� ���� ��� ���, � ������ � ���� �������?";
			link.l1 = "�����, ��...";
			link.l1.go = "ChaniSettlementGoTorus_Yes";
			link.l2 = "��, ���...";
			link.l2.go = "ChaniSettlementGoTorus_No";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_6.wav");
			dialog.text = "";
			link.l1 = "��, ���...";
			link.l1.go = "ChaniSettlementGoTorus_No1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No1":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			dialog.text = "��� ������, ���� � ����������� �� ����! �� ��� �� ����� ����� ������, ������� ����� � �������. ��� ���� � ������ ��������� ����� �����, ������ ��������.";
			link.l1 = "�������...";
			link.l1.go = "ChaniSettlementGoTorus_No2";
  		                   break;

                                                          case "ChaniSettlementGoTorus_No2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_13.wav");
			dialog.text = "";
			link.l1 = "�������...";
			link.l1.go = "exit_No";
  		                   break;

                                                          case "exit_No":
			TakeNItems(pchar, "gold_dublon", 200);
			Log_Info("�� �������� 200 ��������");
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_41.wav");
		                   DialogExit();
					pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.ChaniSettlementGoTorus = "true";
		                   AddDialogExitQuestFunction("No_ChaniSettlement");
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_7.wav");
			dialog.text = "";
			link.l1 = "�����, ��...";
			link.l1.go = "ChaniSettlementGoTorus_Yes1";
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes1":
			dialog.text = "�������, � ��� ������������ �� ����������� ������, �������� ��������������� � ������� 300 ������� ����� � ���� ��������, �������� ������� � ����� �������� ������ � � �������� ����������� ����� ����� ��� ������, �� ������, ���� �� ������� �� ������ ������, �� ���������� ���, ��� �� �� ������� ����...";
			link.l1 = "�������.";
			link.l1.go = "ChaniSettlementGoTorus_Yes2";
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-10;
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_13.wav");
			dialog.text = "";
			link.l1 = "�������...";
			link.l1.go = "ChaniSettlementGoTorus_Yes3";
  		                   break;

                                                          case "ChaniSettlementGoTorus_Yes3":
			dialog.text = "��, ��� ���� ����������� � �������, ���������� ������� ����� ������, �� �������...";
			link.l1 = "������, ��� �� ���� �� �����, � ����� ��������!!!";
			link.l1.go = "exit_Yes";
  		                   break;

                                                          case "exit_Yes":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_56.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   npchar.quest.ChaniSettlementGoTorus = "true";
		                   AddDialogExitQuestFunction("Yes_ChaniSettlement");
		                   pchar.questTemp.ChaniSettlementGoTorus = sti(pchar.questTemp.ChaniSettlementGoTorus)+1;
		                   if (sti(pchar.questTemp.ChaniSettlementGoTorus) == 2) 
		                   {
		                   AddDialogExitQuestFunction("PRESENT");
		                   }
  		                   break;




 		case "":
			dialog.text = "";
			link.l1 = "�������... �������, �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
  		break;


		//********************* ����� ������� *********************

   		case "RevengeCorsair_toTorus":
		dialog.text = "��, ������ ������ ��� � ���� ��������� ���� �����, � ���� � ���, ��� �����, �� ����� �� �� ������ �������, �����, ������ ����� �� ���� ��� ����������������.";
		link.l1 = "��� �� ���� ������ �������?";
		link.l1.go = "RevengeCorsair_toTorus_1";
		break;

   		case "RevengeCorsair_toTorus_1":
		dialog.text = "������... ���� ������, ������ ������� - ���� �� �������.";
		link.l1 = "�������, �� ���� ����� - ���� �� ����������?";
		link.l1.go = "RevengeCorsair_toTorus_2";
		break;

   		case "RevengeCorsair_toTorus_2":
		dialog.text = "� ������ ������� - ������ ��������� � ���� ������ �� ��������.";
		link.l1 = "� ���� ������� - �����.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_toTorus = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_10");
		break;


 		case "Lets_go_bussines":
			dialog.text = "��� ���� ������, " + pchar.name + ". ������ �������� �� ��������?";
			link.l1 = "� �� ����. �� � �������� ������� ������, �� ������� ������� � ����?";
			link.l1.go = "Gothic_RevengeCorsair_6";
  		break;

 		case "Gothic_RevengeCorsair_6":
            if (GetCompanionQuantity(pchar) < 8) 
            {
    			dialog.text = "� ��������! ���, ��� ������ ����� �� �����, ������� ��������������, � ������ �����.";
    			link.l1 = "����� ��������� ����������!";
    			link.l1.go = "Gothic_RevengeCorsair_7";
            }
            else
            {
    			dialog.text = "� ��� � ��� ���� ��������, ��� ��� ��� ���� �� ���� ���.";
    			link.l1 = "�� ��� �, ��� ������, ���� ������.";
    			link.l1.go = "exit";
                NextDiag.TempNode = "First time";
            }
  		break;

 		case "Gothic_RevengeCorsair_7":
	        AddQuestRecord("RevengeCorsair", "13");
                LAi_SetActorType(npchar);
                LAi_ActorSetStayMode(npchar);
                ChangeCharacterAddressGroup(npchar, "Roseau_Roomtownhall", "goto", "goto6");
                CharacterIntoCompanionAndGoOut(pchar, npchar, "reload", "reload1", 10, false);
                Fantom_SetBalls(npchar, "pirate");
                npchar.CompanionEnemyEnable = false;  // ��� ������ ��� ��������
                pchar.questTemp.CompanionQuantity = makeint(sti(pchar.questTemp.CompanionQuantity) + 1);
                pchar.questTemp.CompanionQuantity.Torus = true;
                NextDiag.TempNode = "Have_hot_bussines";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;

		//�����
		npchar = characterFromId("Torus");
		FantomMakeCoolSailor(npchar, SHIP_FRIGATE_L, "�������", CANNON_TYPE_CULVERINE_LBS36, 90, 90, 90);
	SetShipSailsFromFile(npchar, "ships/parus_sail_whole_white_pirate_9.tga");
		npchar.CompanionEnemyEnable = false;  // ��� ������ ��� ��������
		SetCharacterRemovable(npchar, false);
SetCrewQuantityFull(npchar); 
npchar.ship.Crew.Morale = 80;
npchar.Ship.Crew.Exp.Sailors = 100;
npchar.Ship.Crew.Exp.Cannoners = 100;
npchar.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(npchar, GOOD_BALLS, 3000);
SetCharacterGoods(npchar, GOOD_GRAPES, 2500);
SetCharacterGoods(npchar, GOOD_KNIPPELS, 2000);
SetCharacterGoods(npchar, GOOD_BOMBS, 1500);
SetCharacterGoods(npchar, GOOD_POWDER, 10000);
SetCharacterGoods(npchar, GOOD_WEAPON, 1000);
SetCharacterGoods(npchar, GOOD_FOOD, 2500);
SetCharacterGoods(npchar, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(npchar, GOOD_RUM, 350);
SetCharacterGoods(npchar, GOOD_PLANKS, 100);
SetCharacterGoods(npchar, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(npchar, "Capacity");
		LAi_SetImmortal(npchar, false);
                LAi_NoRebirthDisable(npchar);
		LAi_RebirthOldName(npchar);
		SetCompanionIndex(pchar, -1, sti(npchar.index));

  		break;

	 	case "Have_hot_bussines":   // ���� ������� ����� ��������� ��� ����������, �� ����, ������ ��. �� �� ������ ������.
			dialog.text = "���� ������, ����� �������� ������ ���!";
            link.l1 = "��������!";
			link.l1.go = "exit";
            NextDiag.TempNode = "Have_hot_bussines";
  		break;

	 	case "Gold_found_in_fort":    // ���� ��������� � ����� ������
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.Torus") && !IsCompanion(characterFromID("Torus")))
    		{
            	dialog.text = "�� ��� �����"+ GetSexPhrase("","�") +" - ��� ������ ��� �������� ���������� ���������! �� ��� �� ����, ������� ����� � ������ ������� ����� ����� �� ���� � �� ���������� ������� ��� �� ����."+
                              "� ������������ �� ����� ��� ����� ������. ���, ������� �������, ���������� �������� ������. �� �� ���"+ GetSexPhrase("","�") +" ����"+ GetSexPhrase("","�") +", ������ ���� �����. ��� � ������ ����� ������ ����!" +
                              "������ ���, � ���� ����. ��� �� ����� ����� �������.";
            }
            else
            {
    			dialog.text = "������� �������, ���������� �������� ������. �� �� ���"+ GetSexPhrase("","�") +" ����"+ GetSexPhrase("","�") +", ������ ���� �����. ��� � ������ ����� ������ ����!" +
                               "������ ���, � ���� ����. ��� �� ����� ����� �������.";
            }
            link.l1 = "� � ��� �� ������"+ GetSexPhrase("","�") +"!";
			link.l1.go = "Step_8";
        break;

	 	case "Step_8":
			dialog.text = "��-��... �� - ������� ������, " + pchar.name + " " + pchar.lastname + ". � ����� ���� �����, "+ GetSexPhrase("����","�������") +".\n"+
                          "��� ���������� ������ ����� ����� ������� ������. ����, ��� �� �������� ������ ���� ���� ������.";
			link.l1 = "��� ��������!";
			link.l1.go = "Step_9";
        break;

	 	case "Step_9":
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15.0);
            DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
        break;

		
		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ���� ����������!");
			link.l1 = "��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ������� ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "���� �� ����� ��������� ���� �� ���� ������� �����������. ������ ��������� ����� ���� ����� ���������...";
        			link.l1 = "� �����"+ GetSexPhrase("","�") +".";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryRepeat_2":
            dialog.text = RandPhraseSimple("�� ���� ������� ������"+ GetSexPhrase("","�") +", �������� �������.", "� �� ���� � ����� ��������, ��� ��� ���� ����� ���� �� ����������.");
			link.l1 = RandPhraseSimple("�� ��� ������...", "��, �� ��� ��...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ������� ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "�������, ������ �� �� ������ �������� ���� ������� �����������, ����� ��� �������� ���� �����. ���������, ��� ��� ����� ����� ���������.";
        			link.l1 = "�����, �� ������ ���� ������ - �� ����...";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("Roseau_town","reload","reload8_back");
		break;
		// <<<<<<<<<<<<============= ���� ��� angry =============================
		case "Roseau_town":
            dialog.text = "������ ��������? �� �� ��� ���������, ���� �� ���������? � �����, ��������� ��� ������� ���� - � ������� �����, ����� ��� ������ ���� ''�������''. ��� - ������ �������� �� ��� ������ �������.";
			if (sti(Pchar.money) >= 1000000)
			{
				link.l1 = "������, � ����� ���������.";
				link.l1.go = "Roseau_town_pay";
			}
			link.l2 = "� �� �����. �����.";
			link.l2.go = "Roseau_town_exit";
		break;
		
		case "Roseau_town_exit":
			DialogExit();
            bDisableFastReload = true;//������� �������
			pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
			pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
			pchar.quest.pirate_in_town.function = "TownPirate_battle";
		break;
		
		case "Roseau_town_pay":
            dialog.text = "��� � ������! ������, ��� ���� ��������� �� �����������. �� ������, � �������, �� ������ �� ������ ������ ����� ���������.";
			link.l1 = "�� ����. �� ����� ������ ��� ���������. ������...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			pchar.GenQuest.Piratekill = 0;
		break;

	}
}

void SetMushketCapitainInWorld()
{

}


