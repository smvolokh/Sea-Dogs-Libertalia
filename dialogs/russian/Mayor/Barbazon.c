// ��� �������� � �� �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc, sTemp;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

//--> -----------------------------------------------���� angry-------------------------------------------------
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
                break;
            }
        }
    }
//<-- -------------------------------------------���� angry------------------------------------------------------

	switch(Dialog.CurrentNode)
	{
	// ----------------------------------- ������ ������ - ������ �������---------------------------------------
		case "First time":
            dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("� ���� ���� �� ���? ���? ����� ���� ������!","��, " + pchar.name + "! � ���� ���� �� ���? ���? ����� �� �������� ����.") +"",
                         "� ������� ���� ���������.", "���� � ��������� � ����, �� �� ����������� ��������� ����!",
                         "��-�-��, ��� ��� ������ �� ��������, ���� ��� �������.", "repeat", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� �����.",
                                               "�������, ���...",
                                               "������, ���...",
                                               "��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			
			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("� ���� ����� �������? ��������� ���� ��������? ��� ������ ��� �� ����, ��������, ��� ��� ����� ���� �������� ������ ���������.", "��, ��������, ������, �� ��� �����. ���� �������� ������? ������ �� �������� - ����� ���� ������ ������. ���� ������ ���������!");
				link.l1 = RandPhraseSimple("��������, � ���� ��������� ��������...", "������ ��� ������ ��� ��������...");
				link.l1.go = "pirate_town";
				break;
			}
			
		//----------------------------------���� - ��������� ���������---------------------------------------
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "begin")
			{
				link.l1 = "� ���� � ���� ������ ��������, ���... ��� ����������.";
				link.l1.go = "Temptation";
			}
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "give_silk" && GetSquadronGoods(pchar, GOOD_SHIPSILK) >= 60)
			{
				link.l1 = "� ������-������ � ����-��������, ���...";
				link.l1.go = "Temptation_6";
			}
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "terrax")
			{
				link.l1 = "�� ����� �� �� ������� ����������� ������� � ������� ������������� ���������, � ���? �� ������ ���� �������, ��?";
				link.l1.go = "terrax";
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
					link.l1 = "����������, ���, � �� ������ ������ ���������.";
					link.l1.go = "CapComission3";
				}
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
				{
					link.l1 = "� �� ������ ������ ��������.";
					link.l1.go = "CapComission6";
				}
			}	
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "cabin")
			{
				link.l1 = "� ������, ��� �� ����������� ��������, ��������� � ����������...";
				link.l1.go = "Marginpassenger";
			}
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
            dialog.text = NPCStringReactionRepeat(GetFullName(pchar) + "! ����� ��������� �� ���� ���?",
                         "�� ���-�� ����� ��� �������? � ������.", "����� ��� ����� ������������? ���� ���� ������ ������, �� �������� ������!",
                         "�� ������ ���� ���� ��������. �� � ������ � � ���� ������ �� ���������!", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��, ����������, ������ ��� ��������"+ GetSexPhrase("","�") +", ���������. ������ �� ���� ���.",
                                               "������, ������ ���...",
                                               "������...",
                                               "�� ����. ������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";

			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("� ���� ����� �������? ��������� ���� ��������? ��� ������ ��� �� ����, ��������, ��� ��� ����� ���� �������� ������ ���������.", "��, ��������, ������, �� ��� �����. ���� �������� ������? ������ �� �������� - ����� ���� ������ ������. ���� ������ ���������!");
				link.l1 = RandPhraseSimple("��������, � ���� ��������� ��������...", "������ ��� ������ ��� ��������...");
				link.l1.go = "pirate_town";
				break;
			}

			//��������� �������� - �����
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
			{
				link.l1 = "� �� ������ ������ ��������.";
				link.l1.go = "CapComission1";
				DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
			}	
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.PirateShips"))
			{
				link.l1 = "����������, ���, � �� ������ ������ ���������.";
				link.l1.go = "CapComission3";
			}
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				link.l1 = "� �� ������ ������ ��������.";
				link.l1.go = "CapComission6";
			}
			if (CheckAttribute(pchar, "GenQuest.Marginpassenger") && pchar.GenQuest.Marginpassenger == "cabin")
			{
				link.l1 = "� ������, ��� �� ����������� ��������, ��������� � ����������...";
				link.l1.go = "Marginpassenger";
			}
		break;

//--> -----------------------------------���� - ��������� ���������---------------------------------------------
		case "Temptation":
			dialog.text = "�� ������, ��������, �� ��� �� �������� ���������� ����������... �����, ������ ���� �����������.";
			link.l1 = "� �������� ������� �����. ���� ������� ������, � � �� ����. ������ ���� �������, ��� �� ������ �� ������ ������� � ������ ������, ��� ����� ������ ��������� ���.";
			link.l1.go = "Temptation_1";
		break;
		
		case "Temptation_1":
			dialog.text = "�-�, ��� �������! � ��� ������ ��� ���, ��� ��� �����. ��� ��������� � ��������, � ������ � �������. ������ ��� �����, ���� �� � �������� ����?";
			link.l1 = "������� ���� � ����. �������, �� �� ���������!";
			link.l1.go = "Temptation_2";
		break;
		
		case "Temptation_2":
			dialog.text = "��... �� ��� ��, ��, ��������, ��� ������ �� '������ �����', ��� ������ � ����, ��� �������� ���� ��������. ������� �� ���� ���� ������ ��� ������� ������� �������������. ���� � ���� ���� ��������� ���������. ���� ���������� - ����� ���� ���������� ��������.";
			link.l1 = "�� ����������, � ����� �� ������ ����������, � ��� �� ����...";
			link.l1.go = "Temptation_3";
		break;
		
		case "Temptation_3":
			dialog.text = "�������� � ������, ��� � ���� ������. ���� ������ ����� ����� � ����-��������� ����������� ������� ������ ������ ����� ���������. ��� ��� ��� ���� ����������� �������� ����. ��� ������� �������� � ����� �����, ��������� ������� ��� ������� �������� ������������� ��� ���� �������� ����� ��������\n��� ���, ��� ������� ������ ����� ����� ����� �����, � ����� ������ �� ���������� '������� ���' ������ ��� ��� ��� ���������, �� �������� ��������� �� ����������� �������. � �����, � �� ��������. ��� � ���� �� ���� �������� ������, ������� ����� ������������, ��� ������ ����� ��� � �����������\n������� ������ ������, ������� �� ��� ��������, ��� ������������. �� ���� �������, ��� ������, ����� �� ������, ������� ���� ���� ������ � ���� ������. �������, ������? ���� ���� ����� ����. ����� �� ��� �������� �����, ��� ����� ������ ������� �� ������ �� �������.";
			link.l1 = "�������������, ���-�� ����� �� ��������.";
			link.l1.go = "Temptation_4";
		break;
		
		case "Temptation_4":
			dialog.text = "��� ����� ����. � ��������� ���� ���� � ����������, �� ��� ����� ����� ����� ��� �������. �� �� ������, ���� �����. ���� ������ ��������� �����, ��� ������ ������� ����. ��� � ������ 21 ��. 10' �������� ������ � 61 ��. 30' �������� ������� - ��� ���� ������� � ������� �������\n��������� ���������� ���� ���� �� ������� �� ������, ��� ��� ��-�� ����� ���� �� ������ ���� �������� � ������� �� ����������� �� ��� ����. ��� ������ ���� ����� �����. ����������� �������, ����� ������.";
			link.l1 = "��� � ����!";
			link.l1.go = "Temptation_5";
		break;
		
		case "Temptation_5":
			DialogExit();
			SetFunctionTimerCondition("Saga_BarbTemptationOver", 0, 0, 10, false); // ������
			pchar.quest.BarbTemptation.win_condition.l1 = "location";
			pchar.quest.BarbTemptation.win_condition.l1.location = "SentMartin";
			pchar.quest.BarbTemptation.function = "Saga_BarbTemptationBarkas";
			pchar.questTemp.Saga.BarbTemptation = "silk";
			AddQuestRecord("BarbTemptation", "2");
		break;
		
		case "Temptation_6":
			dialog.text = "���������. �� ���, ����� ��� ����?";
			link.l1 = "��, ��� ����� �����, ��� �� � �������.";
			link.l1.go = "temptation_wrong";
			if (GetSquadronGoods(pchar, GOOD_SHIPSILK) >= 90)
			{
				link.l2 = "��. ������ ����� ��������� ������, ��� �� �������, � ������ - ������. � �������� ���� ���, �� �� ��� ���������, ��� ����� ����� ����������.";
				link.l2.go = "temptation_right";
			}
		break;
		
		case "temptation_wrong":
			dialog.text = "��� ������������ �����. ����� ������ ���� ���� ������. � ���� �� ����� ����� �� ���, �� ������ ��� ����� � ���������. ��� ��� �� ���� �����, ���� ������ � ����������. �� ������ ��� ��� ���� ����� � ��� ��� � �������� ��������� ����������� �� ������� ������.";
			if (GetSquadronGoods(pchar, GOOD_SHIPSILK) >= 120)
			{
				link.l1 = "�� �� � ������! ���� �� �������. ����� ���� ���� � ������� � ���� ����������.";
				link.l1.go = "temptation_wrong_1";
			}
			link.l2 = "���� �������, ��� ����� ���� ����� � �� ����� ������. � ����� ���� ���, � ��� �������, ��� �� ��� ��� �������. ������ � ���� ��� ����� ���.";
			link.l2.go = "temptation_wrong_2";
		break;
		
		case "temptation_wrong_1":
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, 120);
			dialog.text = "������. �������, �������� ������ �� ����������, ��� ��� � ������� �������� ���� ������ ����. ������� ����� �� ������ ����������?";
			link.l1 = "������ ����� �� ������, �� ���� ������ �������� �� ��������� ����� ����.";
			link.l1.go = "junior";
		break;
		
		case "temptation_wrong_2":
			dialog.text = "�� ��� ��� �� ������! ��, ��� ���� ����� �� �������. � ���� ����� ������������ - �� ������� ���� ������! ������! ����� � ����������!";
			link.l1 = "�-���!";
			link.l1.go = "temptation_wrong_fight";
		break;
		
		case "temptation_wrong_fight":
			chrDisableReloadToLocation = true;//������� �������
			DialogExit();
			LAi_SetWarriorType(npchar);
			ChangeCharacterAddressGroup(npchar, "LeFransua_townhall", "goto", "goto1");
			LAi_SetImmortal(npchar, true);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i = 1; i <= 3; i++)
			{
				sld = GetCharacter(NPC_GenerateCharacter("BarbGuard_"+i, "citiz_4"+(i+6), "man", "man", 80, PIRATE, 1, true, "quest"));
				FantomMakeCoolFighter(sld, 80, 100, 100, "blade_21", "pistol4", "bullet", 3000);
				ChangeCharacterAddressGroup(sld, "LeFransua_townhall", "reload", "reload1");
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "temptation_right":
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, 80);
			dialog.text = "������� ������. � �������� ���� �� ��������, � �� ������ ��������. ����� � ������ ���� ���� ������. ���� �� ��� ��������� ����. ��, � ������ �� ����� ���������� �������. ������� ����� �� ������ ����������?";
			link.l1 = "������ ����� �� ������, �� ���� ������ �������� �� ��������� ����� ����.";
			link.l1.go = "junior";
		break;
		
		case "junior":
			dialog.text = "� ���� ���� ����������� ���������� ���� ������. ���� ��������� ������� ������ ���� ��������� ��������� ����� ����� ���� ��� ������ ����������� � �������� ����. ���� ������� ����� ����� � ������ ������������� ���� �� �����������, ���� �� ��� �� ���������.";
			link.l1 = "� �����.";
			link.l1.go = "junior_1";
		break;
		
		case "junior_1":
			dialog.text = "������ �����������. �� ������ ����������� � ��� ���������� ����� �� ������ �����. �� ������� ������� '������', ������ � � ��� ������ �� ����. �� ������� ��� � �����������. ������ - '����� ��� ��������'. �� ���� �� �������, ��� ������ ������. ��� �� ������ �� ������. � ������ ����� ���� ������. ���� ����� �� ���������� �� ����, �� ��� ����������.";
			link.l1 = "������� �� �������. ����������� ����������!";
			link.l1.go = "junior_2";
		break;
		
		case "junior_2":
			DialogExit();
			AddQuestRecord("BarbTemptation", "7");
			Saga_SetJuniorInCharles(); // ������ ������
			pchar.questTemp.Saga.BarbTemptation = "valet";
		break;
		
		case "terrax":
			dialog.text = "���?! �� � ����� � ����...";
			link.l1 = "������ �� �� �������, ��������. ������� �����! � ������� �� ��� ��������. � ������� ���������, ������� �� ������� ������ � ���������. ��� ��� ��������: � ��� �� ��������, � ������ ���� ���� ����. ������� � ��� ������ ����� ������ - ���� �������� �������������, � ������ �������� ���� �������� �����, ����� ���� ������ �����. ";
			link.l1.go = "terrax_1";
		break;
		
		case "terrax_1":
			dialog.text = "���� ������! ������ ��� ������� ����� �� �������! �� � ���...";
			link.l1 = "�� ����� ���������, ���. � ��������� ����, ��� �������� ����� ���������, ������� ������ ���� ����������������. ����� � ����... ���� ������ �������� ����� �����������. ��� ����� ������������� � �������, � � ����� ����� ��������� ������. ������ �������� �����? ��� �������!";
			link.l1.go = "terrax_2";
		break;
		
		case "terrax_2":
			dialog.text = "���� ������! ���� �� ������?";
			link.l1 = "�� �� ��������, ��������... ����! � ���� ����. ������ ������� � �� ������ � �� ����� ������� � ����� ������� � �������� ������ ����. �������, ���� �� ������� ��� ���������...";
			link.l1.go = "terrax_3";
		break;
		
		case "terrax_3":
			dialog.text = "���� �� ������ ������? �����? �������?";
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie")) // ����� ���
			{
				link.l1 = "� ���, ������ ��� ��������� ��� ����� ������ �� ������ ����������. ��� ����� ���-��� ������. � ������ - ���� ����� �� ������ � ������ ������� �������.";
			}
			else
			{
				link.l1 = "� ���, ������ ��� ��������� ��� ����� ������ �� ������ ����������. ��� ����� ���-��� ������. � ������ - ���� ����� �� ������ � ������ ������� �������.";
			}
			link.l1.go = "terrax_4";
		break;
		
		case "terrax_4":
			if (!CheckAttribute(pchar, "questTemp.Saga.DodsonDie")) sTemp = "� ������ ������ �� ����� �������. ";
			else sTemp = "";
			dialog.text = "��� ���? ���-�� ��������... � ���� � ��������?";
			link.l1 = "����� �� ���������� ����, ���. ������ ����. ������ ���� ������ ������ �������, ������ � ����. "+sTemp+"� ����� ���� ������ �� ������ ������, ������ ��������. �� � ����� ����� �������... ��� �� �������, ������� ������� ����� ����� �� ��������� �� ����� ������ �����?";
			link.l1.go = "terrax_5";
		break;
		
		case "terrax_5":
			dialog.text = "����? �� ���?";
			link.l1 = "���. � ������� ��� �� �������, � ������� ��� ������ �������. ��� ��� ���� ����� - ��� ������� ����, ���� ��� � ����. �� � ���� �� ������ �� ���������, ��������.";
			link.l1.go = "terrax_6";
		break;
		
		case "terrax_6":
			dialog.text = "�� �� ���� ��� �������! ���� �� ���� ������! �� ������ ���� � ����!";
			link.l1 = "��������. ���� ����� � ������ �� ����, ���� � ������ - � ��� ���� ������ ������ ������ �� ���������. � �� ������, ���: � ���� ����. � ����� ��� ��� �� ��������� ������ ���� ���� �������, �� �� ������ �����.";
			link.l1.go = "terrax_7";
		break;
		
		case "terrax_7":
			GiveItem2Character(pchar, "splinter_jb"); // ���� �������
			dialog.text = "������. � ��������. ��� �����. ���, ����� ��� �������� ������� - ���� ���� ����� ���?";
			link.l1 = "�����. � ���, ��� �� ������������, ���. ������ ���� �� ������ ������ ������. ����, ����� ����� - �� ��� ��� ������� � ����� ����. �� ��� ��� �� ���...";
			link.l1.go = "terrax_8";
		break;
		
		case "terrax_8":
			RemoveItems(pchar, "letter_chad", 1);
			dialog.text = "�� ���?! ��� ��� ���� �� ���� �����?";
			link.l1 = "���� �������� �� ���� ��� ����������� ��������, ���. ���� �� �� ��� � ����� ��� ��������, � �����. �� �������, ��� �� ���� - ��� ��������� ������, ������� �������� ����� ��������. � ������ - �����, ��������...";
			link.l1.go = "terrax_9";
		break;
		
		case "terrax_9":
			DialogExit();
			NextDiag.CurrentNode = "I_know_you_good";
			AddQuestRecord("BarbTemptation", "26");
			if (CheckCharacterItem(pchar, "splinter_mt") && CheckCharacterItem(pchar, "splinter_jb") && CheckCharacterItem(pchar, "splinter_zm")) Saga_GiveCalendar();
			pchar.quest.Saga_storming_group1.win_condition.l1 = "location";
			pchar.quest.Saga_storming_group1.win_condition.l1.location = "LeFransua_town";
			pchar.quest.Saga_storming_group1.function = "Saga_DeleteStormingGroup";
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;

//-----------------------------------��������� �������� - �����-------------------------------------------------
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
				link.l1 = "������, ��� ����� ����... � �����, � ���� ��� ����� �����. �� � �����"+ GetSexPhrase("","�") +" ����������.";
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
			dialog.text = "��... � ����� ����� " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.UnknownPirateName, NAME_NOM) + " ������ ����� �������, ��� � ����� ������� ���� " + XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Gen") + " ���� � �� ����. ������� ��� ������� � ����� � �� ���� ����� '" + pchar.GenQuest.CaptainComission.ShipName1 + "' � '" + pchar.GenQuest.CaptainComission.ShipName2 + "' ���� � " + sLoc + ". ��������� ������, ������ � �� ���� �������� ��� ���� ����� �����?";
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
			link.l2 = "������, "+ NPChar.name +", ������ ��� ����� �������� ���������...";
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
		
//--------------------------------------------����������------------------------------------------------------
		case "Marginpassenger":
			dialog.text = "� ����-�� ����� ���� �� ����, ��� � ���������, � ��� ���? ������ ���, ��� �� �� ���...";
			link.l1 = "����, �� ��������. � ������ � ���� �� ����, ������ ������ �� ����� ����.";
			link.l1.go = "Marginpassenger_1";
		break;
		
		case "Marginpassenger_1":
			dialog.text = "�-�, �� �����. �� ���� �� ������ �����?";
			link.l1 = "������. � ���� ������ �� ��� ����, ����� ��������, � ��� ����, ����� ���������� ���� ������ ������ ����� ��������. ��, � �� ����� c������ �������� �� ���� �����.";
			link.l1.go = "Marginpassenger_2";
		break;
		
		case "Marginpassenger_2":
			dialog.text = "��. � ����� ���� ������������ ��� ��������������? ���� ��� �� ������ �������� ������� ��������?";
			link.l1 = "��� ���� � ������ ������ ��� ������. ����� ���� �������� � ��������.";
			link.l1.go = "Marginpassenger_3";
		break;
		
		case "Marginpassenger_3":
			dialog.text = "���... ��, ������. ��� ��, ���� �������?";
			link.l1 = "��� "+pchar.GenQuest.Marginpassenger.Text+" "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.City+"Gen")+".";
			link.l1.go = "Marginpassenger_4";
		break;
		
		case "Marginpassenger_4":
			int iTemp = makeint(sti(pchar.GenQuest.Marginpassenger.Dublon)*2*stf(pchar.GenQuest.Marginpassenger.Chance))*100;
			dialog.text = "���-���... ���� �� �� �����, �� ��� ����� ��������� ���������� �������. �������, � ����� ��������� �� ����� �������� "+iTemp+" ����, ���, ���� ������, ���� ���������� �������� �����������. ��� ���� ������ ��������.";
			link.l1 = "����� ����� ����. � ��� ������� �������� � ���� �����, ���� ��� �������...";
			link.l1.go = "Marginpassenger_money";
			link.l2 = "��! ����� �������� ���-������ ��������. ������, ������ �� ��� �� ����������.";
			link.l2.go = "Marginpassenger_offer";
		break;
		
		case "Marginpassenger_money":
			dialog.text = "������ - ��� ������. ���, �����. ������ ��� ������ �� ���� ������. ��������� �������� ����� ����.";
			link.l1 = "�� ������ ���� ��� ����� ��������� �����. �������! �� ���� �������.";
			link.l1.go = "Marginpassenger_money_1";
		break;
		
		case "Marginpassenger_money_1":
			iTemp = makeint(sti(pchar.GenQuest.Marginpassenger.Dublon)*2*stf(pchar.GenQuest.Marginpassenger.Chance))*100;
			dialog.text = "�� ������ ����������, ������� ���... �����!";
			link.l1 = "� ���� ����� �������...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, iTemp);
			sld = characterFromId("MarginPass");
			RemovePassenger(Pchar, sld);
			sld.lifeday = 0;
			AddQuestRecord("Marginpassenger", "12");
			AddQuestUserData("Marginpassenger", "sSum", iTemp);
			CloseQuestHeader("Marginpassenger");
			DeleteAttribute(Pchar, "GenQuest.Marginpassenger");
		break;
		
		case "Marginpassenger_offer":
			pchar.GenQuest.Marginpassenger.Goods = GOOD_EBONY + rand(makeint(GOOD_MAHOGANY - GOOD_EBONY));
			pchar.GenQuest.Marginpassenger.GoodsQty = 200+rand(10)*10;
			switch (drand(1))
			{
				case 0: //����� �� ����� �����
					SelectSouthshore();
					while (!isLocationFreeForQuests(pchar.GenQuest.Marginpassenger.Shore)) SelectSouthshore();
					dialog.text = "������� ����� ���� �� ��������� ���������, ������! ������ ������: ����� ��������� ���� � " + XI_ConvertString(pchar.GenQuest.Marginpassenger.Shore+"Dat") + " �������� ��������� ���������� �� �����, � �������� ������ ���������, � ����� ����� �������, ������� ������ ������ � ������� ����. ���� �� ������ �� ������� ���� ��������� - � ���� ����� ���� ������� ���� ����� ����\n�� ����� ����� � �� ��� ����� � ����� ��������. � ��������� ��������� �������� ����.";
					link.l1 = "���������! ��������� �������� ������� ������������ �� ��� ���������! � ��� �������� ��� ������ ���� ���-�� � ��������� �����. ��� � ���� ��������.";
					link.l1.go = "Marginpassenger_offer_1";
				break;
				
				case 1: //������ ��������
					SelectSouthcity();
					pchar.GenQuest.Marginpassenger.ShipName1 = GenerateRandomNameToShip(SPAIN);
					dialog.text = "������� ����� ���� �� ��������� ���������, ������! ������ ������: �������������� ����� ������ �� "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Southcity+"Gen")+" ������ ��������� ���������� '"+pchar.GenQuest.Marginpassenger.ShipName1+"' � ������ ������ ��������� � ���������� � ���� "+XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Southcity1+"Gen")+". ���� �� ������ ������, �� �������� ����������� ��\n�� ��� �����? �� ����� ����� � �� ��� ����� � ����� ��������. � ��������� ��������� �������� ����.";
					link.l1 = "���������! ��������� �������� ������� ������������ �� ��� ���������! � ��� �������� ��� ������ ���� ���-�� � ��������� �����. ��� � ���� ��������.";
					link.l1.go = "Marginpassenger_offer_2";
				break;
			}
			sld = characterFromId("MarginPass");
			RemovePassenger(Pchar, sld);
			sld.lifeday = 0;
			pchar.GenQuest.Marginpassenger = "final";
		break;
		
		case "Marginpassenger_offer_1":
			DialogExit();
			AddQuestRecord("Marginpassenger", "13");
			AddQuestUserData("Marginpassenger", "sShore", XI_ConvertString(pchar.GenQuest.Marginpassenger.Shore+"Dat"));
			SetFunctionTimerCondition("Marginpassenger_SouthshoreOver", 0, 0, 7, false);
			pchar.quest.Marginpassenger.win_condition.l1 = "location";
			pchar.quest.Marginpassenger.win_condition.l1.location = pchar.GenQuest.Marginpassenger.Shore;
			pchar.quest.Marginpassenger.function = "Marginpassenger_Southshore";
		break;
		
		case "Marginpassenger_offer_2":
			DialogExit();
			AddQuestRecord("Marginpassenger", "16");
			AddQuestUserData("Marginpassenger", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Southcity+"Gen"));
			AddQuestUserData("Marginpassenger", "sCity1", XI_ConvertString("Colony"+pchar.GenQuest.Marginpassenger.Southcity1+"Gen"));
			AddQuestUserData("Marginpassenger", "sShipName", pchar.GenQuest.Marginpassenger.ShipName1);
			SetFunctionTimerCondition("Marginpassenger_SouthshipInWorld", 0, 0, 5+rand(2), false);
		break;
		
//---------------------------------------������� ������� � ������� --------------------------------------------
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
					
// ----------------------------------------------���� ��� angry--------------------------------------------------
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ����� ����!");
			link.l1 = "��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� ����� 10 ����.
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
            dialog.text = RandPhraseSimple("���, �������� �������.", "� �� ���� � ����� ��������, ��� ��� ���� ����� ���� �� ����������.");
			link.l1 = RandPhraseSimple("�� ��� ������...", "��, �� ��� ��...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //����������� ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "�������, �� ���� ������ ��������� �������� � ��� �����, � �� ������� ����� ������?";
        			link.l1 = "���, �� ������ ���� ������ - �� ����...";
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
            DoReloadCharacterToLocation("LeFransua_town","reload","reload3_back");
		break;
		
		case "pirate_town":
            dialog.text = "������ ��������? �� �� ��� ���������, ���� �� ���������? � �����, ��������� ��� ������� ���� - � ������� �����, ����� ��� ������ ���� '�������'. ��� - ������ �������� �� ��� ������ �������.";
			if (sti(Pchar.money) >= 1000000)
			{
				link.l1 = "������, � ����� ���������.";
				link.l1.go = "pirate_town_pay";
			}
			link.l2 = "� �� �����. �����.";
			link.l2.go = "pirate_town_exit";
		break;
		
		case "pirate_town_exit":
			DialogExit();
            bDisableFastReload = true;//������� �������
			pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
			pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
			pchar.quest.pirate_in_town.function = "TownPirate_battle";
		break;
		
		case "pirate_town_pay":
            dialog.text = "��� � ������! ������, ��� ���� ��������� �� �����������. �� ������, � �������, �� ������ �� ������ ������ ����� ���������.";
			link.l1 = "�� ����. �� ����� ������ ��� ���������. ������...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			pchar.GenQuest.Piratekill = 0;
		break;
	}
}

void SelectSouthshore()
{
	switch (rand(6))
	{
		case 0: pchar.GenQuest.Marginpassenger.Shore = "shore37"; break;
		case 1: pchar.GenQuest.Marginpassenger.Shore = "shore47"; break;
		case 2: pchar.GenQuest.Marginpassenger.Shore = "shore48"; break;
		case 3: pchar.GenQuest.Marginpassenger.Shore = "shore25"; break;
		case 4: pchar.GenQuest.Marginpassenger.Shore = "shore21"; break;
		case 5: pchar.GenQuest.Marginpassenger.Shore = "shore20"; break;
		case 6: pchar.GenQuest.Marginpassenger.Shore = "shore19"; break;
	}
}

void SelectSouthcity()
{
	switch (drand(2))
	{
		case 0: 
			pchar.GenQuest.Marginpassenger.Southcity = "Maracaibo";
			pchar.GenQuest.Marginpassenger.Southcity1 = "Havana"; 
		break;
		
		case 1:
			pchar.GenQuest.Marginpassenger.Southcity = "Cartahena";
			pchar.GenQuest.Marginpassenger.Southcity1 = "Santiago"; 
		break;
		
		case 2:
			pchar.GenQuest.Marginpassenger.Southcity = "Portobello";
			pchar.GenQuest.Marginpassenger.Southcity1 = "Santodomingo"; 
		break;
	}
}
