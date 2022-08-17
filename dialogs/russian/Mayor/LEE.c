// ������� �� � ������ ��������������� ���������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

// ------------------------------------------���� angry-----------------------------------------------
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
    } //<-- ���� angry
 
	switch(Dialog.CurrentNode)
	{
		case "First time":
            dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("������� � ���� ���� �� ���? ���? �� �������� � �����!","��, " + pchar.name + "! � ���� ���� �� ���? ���? ����� �� �������� ����.") +"",
                         "������ �������, � �����.", "������� � ��������� ����, �� �� ����������� ��������� ����!",
                         "��-�-��, ��� ��� ������ �� ��������, ���� �� � ������, ���� ��� �������.", "repeat", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��� �����.",
                                               "�������, ������� ��...",
                                               "������, ������� ��...",
                                               "��...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			
			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("� ���� ����� �������? ��������� ���� ��������? ��� ������ ��� �� ����, ��������, ��� ��� ����� ���� �������� ������ ���������.", "��, ��������, ������, �� ��� �����. ���� �������� ������? ������ �� �������� - ����� ���� ������ ������. ���� ������ ���������!");
				link.l1 = RandPhraseSimple("��������, � ���� ��������� ��������...", "������ ��� ������ ��� ��������...");
				link.l1.go = "SantLous_town";
				break;
			}

            // ����� ��������. �������� �� ��������� ��������� ���������.
            if (pchar.questTemp.Ascold == "SeekThreeObject" && !CheckAttribute(pchar, "questTemp.Ascold.Lee"))
            {
    			link.l2 = "������� ��, � ���� � ���� ����. ��������, �� ����������� �� ���� � �������� ������� ��������� ��������� ��������?";
    			link.l2.go = "Step_Lee_1";
            }
            if (pchar.questTemp.Ascold == "SeekThreeObject" && CheckAttribute(pchar, "questTemp.Ascold.Lee"))
            {
    			link.l2 = "������� ��, �����, �� ����������� ������ ���� ��� ��������� ���������, � ������� � ���� �������"+ GetSexPhrase("","�") +"?";
    			link.l2.go = "Step_Lee_7";
            }
            if (pchar.questTemp.Azzy == "DestrContract" || pchar.questTemp.Azzy == "2DestrContract")
            {
                if (!CheckAttribute(pchar, "questTemp.Azzy.Lee"))
                {
        			link.l2 = "������� ��, ��������, ���� � ���� ��������� ������. ��� ������� ����� ��������� ����������. ���� ���� � ���� ����������� ������� ��������� � �������� ����, ������� �� ����������.";
        			link.l2.go = "Step_Lee_9";
        		}
            }
            // ����� ��������. �������� �� ��������� ��������� ���������.
			
			//--> ����
			if(CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && !CheckAttribute(npchar, "quest.sharkbegin"))
			{
				link.l1 = "� ������� ��������� ����� �������. �������, �� ���������, ��� ����� ���. ������ ���-�� ������ ��� � ���� ����?";
				link.l1.go = "Shark";
			}
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "terrax" && CheckCharacterItem(pchar, "witches_hammer"))
			{
				link.l1 = "���� �� ��������� �������� �� ���� �������� �����, ��� �� ��� �����?";
				link.l1.go = "book";
			}
			//<-- ����
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
					link.l1 = "����������, ������� ��, � �� ������ ������ ���������.";
					link.l1.go = "CapComission3";
				}
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
				{
					link.l1 = "� �� ������ ������ ��������.";
					link.l1.go = "CapComission6";
				}
			}

	//********************������� �� ***************************

			if (CheckAttribute(PChar, "questTemp.GothicLee") && pchar.questTemp.GothicLee == "Start_Lee" && !CheckAttribute(npchar, "quest.Gothic.Lee"))
			{
 	                PlaySound("VOICE\Russian\gotica\LEE\LEE_HALLO_00.wav");
                                dialog.text = "������ ������� ���� ��������� ������� ����, ��� �� ������� �����? � ����� �� �����...";
		link.l1 = "������ ��� ���? ������� ��, ��� ��?";
				link.l1.go = "Gothic_HALLO_1";
				}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_BadResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "� ���� ����. ��� �������, "+ GetSexPhrase("�����","�����������") +"?";
                    link.l1 = "� �� ����"+ GetSexPhrase("","��") +" �������� ����� ����, � �������, ��� ��� �����...";
                    link.l1.go = "Gothic_5";
				}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_NiceResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "�������, � ���� �� ����, ��� ��� ���� �����������!";
                    link.l1 = "��� ���� �� ������, ��...";
                    link.l1.go = "Gothic_7";
                    DoQuestFunctionDelay("GothicLee_townhall", 0.1);
				}

            if (pchar.questTemp.GothicLee == "AnnaIsLife" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{
                                dialog.text = "�������, ��� ���� ����� ��������� ����������� ��������. � ���� ���� ��������� �������� �� ����� ����� �� �����. ��������� ��, ����������, ��� ������ � ���� � ���������� � �������� �������. ������� �������� ���� � �����������.";
								                    link.l1 = "� ������ ��� ����������.";
                    link.l1.go = "exit";
                    pchar.questTemp.GothicLee = "GothicLeeAnnaHant_toAnna";
                    LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
 
			}

            if (pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{
                    dialog.text = "�� ��� ������ �� ������, � ������� ������, ��� ��� ������ ����, ������� �� �� ���� �� ���������. ��� ����� �������, � ����� �� ����� ����� ���� ����� �������������.";
                    link.l1 = "�������, ������� ��...";
                    link.l1.go = "exit";
	LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
					DeleteAttribute(&locations[FindLocation("Mayak10")], "DisableEncounters"); //������� ����������
					pchar.questTemp.GothicLee = "empty";
					SaveCurrentQuestDateParam("questTemp");
					
					CloseQuestHeader("GothicLee_2_KillAnnaHanters");
					AddMoneyToCharacter(pchar, 15000);
			}

            if (pchar.questTemp.GothicLee == "SeekBible" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{

                                dialog.text = "";
                                link.l1 = "��� ��������� �� ��������� �����?";
                                link.l1.go = "Gothic_SeekBible";
 

			}

            if (pchar.questTemp.GothicLee == "SeekBible_BadResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "��������� ����� �� ���� ����������, ��� �� �� ������ ��������� ��� ���������.";
                    link.l1 = "� �����-��, ��. � ������"+ GetSexPhrase("","�") +" ���, ��� ���.";
                    link.l1.go = "Gothic_3_1";
				}

            if (pchar.questTemp.GothicLee == "SeekBible_GoodResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+ GetSexPhrase("���� ���","�������") +", ����� � ��� ������ ��������� � ����������� �������. �� ��� ������, ��� �� ������ ������� ����� ����� ������ ��� ����. ������� ���, ��� ���?";
                    link.l1 = "� ������ ��������"+ GetSexPhrase("","�") +" ��� ���� ���� ��������� �������. �����, ������� ������������ �������.";
                    link.l1.go = "Gothic_3_2";
				}

            if (pchar.questTemp.GothicLee == "RockBras_toSeekPlace" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                     dialog.text = "���, "+pchar.name+". �������� ��� � ����������� ������ �� �������� �����.";
                    link.l1 = "���� � �� �����"+ GetSexPhrase("","�") +" ����� ���, �� � �������� ������...";
                    link.l1.go = "exit";
					link.l2 = "��, � �����"+ GetSexPhrase("","�") +" ��� �������, �� ����� ��� � �� �����"+ GetSexPhrase("","�") +". � ����"+ GetSexPhrase("��","��") +" ����������, ��� ��� ����������...";
                    link.l2.go = "Gothic_5_6";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsDead" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "���, "+pchar.name+", � ���� ����. ���� �����-������ ������� � �����?";
                    link.l1 = "������� ����, ������� ��. ������, ��� �������������� - ���� ����� ��� ������ �� ��������� ����������...";
                    link.l1.go = "Gothic_5_7";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsSaved" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "����, "+pchar.name+", ��� � �������. ���� ��� ���������, ��� ��� �������� �������� � ���������� � ��� �� �������� ��� ������. � � ����������!";
                    link.l1 = "��, ��� ���� ���������� ������� ����...";
                    link.l1.go = "Gothic_5_8";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsAgony" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "���, "+pchar.name+", � ���� ����. ���� �����-������ ������� � �����?";
                    link.l1 = "������� ����, ������� ��. ������, ��� �������������� - ���������� �������� ����� �� ������. �� �������� ��� � ���� �� �����...";
                    link.l1.go = "Gothic_5_7";
				}

            if (pchar.questTemp.GothicLee == "ThreeCorsairs_backGovernor" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "��, " + GetFullName(pchar) + ", � �������� ���������� ���� � ����������� ������ �����"+ GetSexPhrase("�","����") +"! ������, ����� ����� ��� ������������� ����� �����.";
                    link.l1 = "����������, ��, � �� ����� �������, ����� �� ���? ��� �����, ��� �������� �� ��� ��������...";
                    link.l1.go = "Gothic_6_3";
				}

            if (pchar.questTemp.GothicLee == "GuardPP_GoodWork" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
					if (LAi_IsDead(characterFromId("SoleiRoyalCaptain")))
					{
						dialog.text = ""+pchar.name+", �� ������� '����� ������'!";
						link.l1 = "� ����"+ GetSexPhrase("","��") +" ����-�-����� � ������"+ GetSexPhrase("","�") +" �� ��� ��������� ������� ��������!";
						link.l1.go = "Gothic_7_4";
					}
					else
					{
						dialog.text = "�����"+ GetSexPhrase("","����") +", ��� ��� �������� � ����� ������. ��� � ���� �������? ���������, "+ GetSexPhrase("���� ���","�����������") +", ������ �����������!";
						link.l1 = "������ ������� �������� ���������, ������� ��...";
						link.l1.go = "Gothic_7_2";					
					}
				}

            if (pchar.questTemp.GothicLee == "GuardPP_SoleiRoyalSunk" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", �� ������� '����� ������'!";
                    link.l1 = "� ����"+ GetSexPhrase("","��") +" ����-�-����� � ������"+ GetSexPhrase("","�") +" �� ��� ��������� ������� ��������!";
                    link.l1.go = "Gothic_7_4";
				}

            if (pchar.questTemp.GothicLee == "GuardPP_DieHard" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", �� �� ����� �������� ����-�-�����! � ��� ����?!";
                    link.l1 = "��, ������� ������ ������� ������� ���������� ����! ��� �������� ���������...";
                    link.l1.go = "Gothic_7_6";
				}
            if (pchar.questTemp.GothicLee == "GuardPP_Late" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", �� �� ����� �������� ����-�-�����! � ��� ����?!";
                    link.l1 = "� �� �����"+ GetSexPhrase("","�") +" �������, ������� ��, ����� � �����"+ GetSexPhrase("��","��") +" � ������, �� ��� ��� ���������...";
                    link.l1.go = "Gothic_7_7";
				}


            if (pchar.questTemp.GothicLee == "OccupySD_toWeWon" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
					dialog.text = "��� �������, �����"+ GetSexPhrase("","����") +"? ��� ������ ��������?";
					if (LAi_IsDead(characterFromId("SoleiRoyalCaptain")))
					{
						link.l1 = "� ��������"+ GetSexPhrase("","�") +" �����-�������, ������ ���� ����� ����������� �������! �� �� ��� ������ ������...";
						link.l1.go = "Gothic_10_4";
					}
					else
					{
						link.l1 = "� ��������"+ GetSexPhrase("","�") +" �����-�������, ������ ���� ����� ����������� �������!";
						link.l1.go = "Gothic_10_6";
					}
				}

            if (pchar.questTemp.GothicLee == "QuestLineBreake" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "� �� ���� ���� � ������, ����������� ���� �����. ��� ������ ������ ���� �������.";
                    link.l1 = "...";
                    link.l1.go = "exit";
                    bWorldAlivePause   = true; // ����� �������
				}
            if (pchar.questTemp.GothicLee == "EndOfQuestLine" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "�������� �������������� � ��������� �������, � ������������ ���� �� �������. ����� �����������, ���� ���������� ���� �����, �����"+ GetSexPhrase("","����") +"...";
                    link.l1 = "������, ��.";
                    link.l1.go = "exit";
                    bWorldAlivePause   = true; // ����� �������
				}
		break;
		
		case "shark":
			dialog.text = "������ ������? �� ����, ������� �� ���� ��, ��� � ��������, ��������� ����� ��������� ������ ��� ��� ��������� �������, � �� ���� ��� �� �����, �� ����. ��� � ������������� - ���� �� ��������� ������ �����, ��������������� ���� ������� ��������� ���� ��� � �������� ������ ���� ��� ����������� ��������.";
			link.l1 = "� ���� ���� ��������� ��������, ��� ����� ��������� � ������ �����. �������� � ����� �� ����, ��, ��������, ��� ����� ������ ��� ���������. ��� �� ������� ��� ��� ���� ���� ���-������?";
			link.l1.go = "shark_1";
		break;
		
		case "shark_1":
			dialog.text = "��������� ������� ����� ������ ������ �� ��� � ��������� ����� �������� ������: �� ������� ��� � ����� ���� ������ '�������' ������ �� ���� � �������, ������� ��������������, �� ���� �����. ����� ��� ���� � �������� �� ��������, ��� ������ �������� � ����. ������ ����� - �� �����, �� ����� �����, �� ����� �� �����\n����� ����, ������ �������� � ������ ������, � ��, ��� ����� ������������� � ��� ��������. �� � ��� � ��� ������? ���������! ��� ���� �������� ������ �� ����� ��������. ��� ������ � ������ ������-�� ����������� �� ����� ������ ��������, �� ��� ����� ������� �������� � ������� ���� ��������\n��� ��� � ��������� ������������� ���� ������ � ��� �� ����� �� �����. � ��� �������� �������� �����, ��� ���� ��� ����� � �� ��������, � ���� ����� ����� ����� ���.";
			link.l1 = "� �� �� ��������, ��� ���� �� �� ������� �������, �� ��� �� ����� ��� �� ���� ����? � ���� �� ���� ������� ��� � ��� ��� ����� �����. ��-�����, ����� ���-�� �������, ��, ������, ���� ����� �� ��� ��� ����, ��� �� �������� � ����.";
			link.l1.go = "shark_2";
		break;
		
		case "shark_2":
			dialog.text = "��� � ���� ��� ������, ���� ���� ������� �������� �������. � ��� ������ �� �������, � ����� ��� ����������� ��� ���� - ��� ���� � ���� ��������, � ��� �� ��������� � ����� ������.";
			link.l1 = "�����, ������� ���. ��, �������, ����. �����, � ���� ������ ���������� �� ����� �����, �� �� � �����?";
			link.l1.go = "shark_3";
		break;
		
		case "shark_3":
			dialog.text = "� ��� �� ��� �����... �� ���� � ���� ���-����� �������. ����� �� ����� �����, �� ���� ���� �� ������-�����, � ������� �����. ��� ��������� ���� ����� ������, �������� ��������� ���, ��� ��������� ������� �������� ����� ������ ������������� ���������, ����, ����� ������������ ����� - ����� �������, � ��������� � �����������\n���-�� �� �������, ��� �� ������� �� ����������� � ��� �����. ������ ���, �� ������-����� �� ����, �������, ���� ����� ���������� �����, ��������� �������� ��������������. ������ ������� ��� ��������, � ��� � ���� ����� - � � ��� ����. � �� ������, ��� � ����� ��������, � ������ ��� ���� ����� ��������� �������� ����, ������� ���� ������� �� ����� ��������. �� ������ ������, ������ �������.";
			link.l1 = "� ��� �� ��� �� ����?";
			link.l1.go = "shark_4";
		break;
		
		case "shark_4":
			dialog.text = "��������� � ����. ������� ������ ������� ����������� ������ ���, ����� ���� �� ������-�����, � ������ �����-�� ����� ������������ �����, ���� � ���������, ������� �����, ���� � ������� � ������� ��������.";
			link.l1 = "����� ���������! � ��� �� ����� ��, ���� ����������?";
			link.l1.go = "shark_5";
		break;
		
		case "shark_5":
			dialog.text = "�� � ���� �����������? ����� � ����� �� ���� ����. � ���� � �������, �� ������ �� ��� ���� ��� ��� ������� � ��������� - �� ������ ��� ���������� ���� �������� ���������. ��� ��� �� ����� ����� ��-�������, ��� �����, ��� �� ��� ����� �� ���� �������� ����� �� �����\n����� ���, ������ � ��� ����� �������, ���������� ��������� �������������� �� ������� ���������, ������� ����� ����� �� ���� �������. ��� � � �����: � �� ���������� �� ������ ������ ����?";
			link.l1 = "������, ��� ������� ����� �� �����, ������� �� ��������� �� ������... �� ��. �������������� ��������.";
			link.l1.go = "shark_6";
		break;
		
		case "shark_6":
			dialog.text = "� ����� ������, ��� ��� ������� ���� ������ �� ��� �������. � ����� ���� ����� ����������� ������?";
			link.l1 = "�� � ������ �������� ����� ���������� ��� ����������� �� ���� ������ ���������� ��������. ��� � ��� ������, ���� ��������� ��������� ��������, ��� ������ ���� ���-�� ������.";
			link.l1.go = "shark_7";
		break;
		
		case "shark_7":
			dialog.text = "���! ������, �� �� ����? ��, �� ������ ������: ��� �������� ������ ������ ������ �������� ������ ���� �������.";
			link.l1 = "����. ������ ��� ������ ������: �� ������������ �� ������� ������� �� �������?";
			link.l1.go = "shark_8";
		break;
		
		case "shark_8":
			dialog.text = "������ �� ������� ��������... � ������, ��� ��� �����, ��� ����� ����������� ��������, ���� �� ����� ��� ������� � �� ��� � ��� ����. ��� � ���� ��� �������, � ���� ����� ������� �� �����. �� ������, ������� �� ����� ������� ����� � ��������? ���? � � ���� �����: ������! � ����� ����, ����� �������� �� �������� � ������\n���, ������, � ��������. ���� ����� �����, �������, ���������� '����� �����'. � ����� ���� �������� ��� �����, �� ����������� �� ���������� �����, ������ ��� ��, ��� � �������� - ���������, �������� � ��������� ��������, �� �������, ��� ��� � �� ���� ���� ������. ��������� ��� ����� - ����� ���� ����� �� �������\n�� ����, ��� ������� ���� ������� ��� ���� ����� ������ � �������, � ����� �� ����� � ��� ������, � ���� �� ���� �������� - �� �� ��������.";
			link.l1 = "������, � ��� ����. ������� �� ��, ��� ������ �����. �� �������!";
			link.l1.go = "shark_9";
		break;
		
		case "shark_9":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "after_marlow";
			npchar.quest.sharkbegin = "true";
			AddQuestRecord("SharkHunt", "2");
		break;
		
		case "book":
			dialog.text = "�����? � ��� �������, ���� ���� � '������ �����'?";
			link.l1 = "�� �������. ��� ������� ��������� �� ��� ����. ��� �� ����������, ��� �� � ������.";
			link.l1.go = "book_1";
		break;
		
		case "book_1":
			dialog.text = "���, �������, ������ �� ������ �����. ����� �� ����������... ��� ��� ��������� �� ��� ����!";
			link.l1 = "�������, ����������.";
			link.l1.go = "book_2";
		break;
		
		case "book_2":
			RemoveItems(pchar, "witches_hammer", 1); // ������� �������
			dialog.text = "�������-��! ���������, ����� ���! � �� ������� ��� � �����, ���� ��� ���� �������� �������...";
			link.l1 = "� ��� �� ����, ������� ��. ��� ��� ������ ������ ������ � ������?";
			link.l1.go = "book_3";
		break;
		
		case "book_3":
			dialog.text = "��� � ���� ��� ������� - ��� ��� �����, ��� ������ ������. ������, ������� �� ������� �� ��� ���� ����������� ���������. ��� ��� ���� ����� � ����� ����. ����� � ���, ��� ������� ������. ��� ��� �������.";
			link.l1 = "�������, ��. ��� ��������!";
			link.l1.go = "book_4";
		break;
		
		case "book_4":
			GiveItem2Character(pchar, "splinter_zm"); // ���� �������
			DialogExit();
			NextDiag.CurrentNode = "I_know_you_good";
			AddQuestRecord("BarbTemptation", "27");
			if (CheckCharacterItem(pchar, "splinter_mt") && CheckCharacterItem(pchar, "splinter_jb") && CheckCharacterItem(pchar, "splinter_zm")) Saga_GiveCalendar();
			ChangeCharacterComplexReputation(pchar, "fame", 1);
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
                                               "������, ������� ��, ������...",
                                               "��� ���� ������, �������"+ GetSexPhrase("��","���") +"!!!", npchar, Dialog.CurrentNode);
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
				link.l1 = "����������, ������� ��, � �� ������ ������ ���������.";
				link.l1.go = "CapComission3";
			}
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				link.l1 = "� �� ������ ������ ��������.";
				link.l1.go = "CapComission6";
			}
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

		//********************* ��������� ������� *********************
		case "PL_Q8_deck":
			dialog.text = "� ��� �� ������� � ���� �� ������? ���� ���� �� ����� �����!";
			link.l1 = "��, � �����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;
		case "PL_Q8_deck_1":
			dialog.text = "���� �� ����� ������ �����, �� �� ������ ���.";
			link.l1 = "��, � ����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;

		//********************* ����� �������� *********************
   		case "Step_Lee_1":
			dialog.text = "��� �� ������� ����� ��������?! �����, � ����������, � ������ � ���� �� ���� ������ ��������?";
			link.l1 = "�� �� ��������. ��� ���� � ���, ��� � ��� ��� �������� ���������� ������. ��� �������. ��� ���� - �� ���� ������������ ��� �����, ���� �������� �� ��������. � �����"+ GetSexPhrase("","�") +" ��������� ����� �� ��� ����, ���� ��� � ���� ����.";
			link.l1.go = "Step_Lee_2";
		break;
   		case "Step_Lee_2":
			dialog.text = "� ��� �� ����?";
			link.l1 = "��������� ��������� �������, �������������� ����� � �������������� ���.";
			link.l1.go = "Step_Lee_3";
		break;
   		case "Step_Lee_3":
			dialog.text = "���, ��� ��� ���� - �� ����������� ��������. � �������������� ��� ��������, ������� ������ �����, ��� ��� �������� ������ ������� ������� �����, ������ ��, ������� ����...";
			link.l1 = "� �������. � �����"+ GetSexPhrase("","�") +" ��������� ��� ���� �� ��� ��������� ����������, ������ � ���������������� ����, ��� �������... � ������, ��� ���� � ���� ����? ��� �� ����������� �������� �����?";
			link.l1.go = "Step_Lee_4";
		break;
   		case "Step_Lee_4":
			dialog.text = "��� ���� � ���� ����. �, � ��������, � ����� ���� ���� �� �������. �� ������ ��� ���� - �� ������� ��� ���������� ���������. ������� ����.";
			link.l1 = "� ������� �� ������?";
			link.l1.go = "Step_Lee_5";
		break;
   		case "Step_Lee_5":
			dialog.text = "�������.";
			link.l1 = "���?!!! �� ��������?!";
			link.l1.go = "Step_Lee_6";
		break;
   		case "Step_Lee_6":
			dialog.text = "���������. �� ��� �������, �� �����-�� ��� ����, �������� � ��� ������, � ���� ��������? ��� �� ������"+ GetSexPhrase("��","���") +", "+ GetSexPhrase("���� ���","�������") +", ������ ��, ��� ��� �� ������ ���������. �� �������� - ��� � ��������, �������� ��� ������.";
			link.l1 = "���� ������, ������� ��!";
			link.l1.go = "Step_Lee_7";
			pchar.questTemp.Ascold.Lee = 1;
		break;
   		case "Step_Lee_7":
			dialog.text = "�����, ������ �������. ������ ��� ���?";
			link.l1 = RandPhraseSimple("�� �� �� ���! �� ����� ������ � ���� ���� ����� �����!", "�� �������? �� �� ��� ��! ���, �������.");
			link.l1.go = "exit";
            if (sti(pchar.money) >= 1000000)
            {
    			link.l2 = "��, ����! � ������� ��� ��� � ���������� ��������!";
    			link.l2.go = "Step_Lee_8";
            }
            else
            {
    			link.l2 = "� �� ����"+ GetSexPhrase("","�") +", �� ����� ����� ���. �����, ����� ��������� ���...";
    			link.l2.go = "exit";
            }
		break;
   		case "Step_Lee_8":
			Log_Info("�� �������� ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = GetFullName(pchar) + ", � ����� ������� ����� ����. ������� ���� ��������� ���������! �������, ��� �������� ���� �����, ��� �� �����"+ GetSexPhrase("","�") +" ������� �� ��� ����� ������...";
			link.l1 = "� ���� �������, ������� ��.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			DeleteAttribute(pchar, "questTemp.Ascold.Lee");
			pchar.questTemp.Ascold = "SoughtThreeObject";
    		GiveItem2Character(pchar, "indian019");
    		GiveItem2Character(pchar, "indian020");
    		GiveItem2Character(pchar, "indian021");
		break;
   		case "Step_Lee_9":
			dialog.text = "���� � ���� ����� ��������. ���� ��������� - � ��� ����.";
			link.l1 = RandPhraseSimple("���� ���������?!!", "���� ���������... ������� �����!");
			link.l1.go = "exit";
            if (sti(pchar.money) >= 5000000)
            {
    			link.l2 = "������, ��� � ���� ��� ������� ������. ���� �����. ������� ������ � ����� �������� ��������!";
    			link.l2.go = "Step_Lee_10";
            }
            else
            {
    			link.l2 = "��� ��� ����� �����, �� ����� ����� � ���� ���...";
    			link.l2.go = "exit";
            }
		break;		
   		case "Step_Lee_10":
			Log_Info("�� �������� ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = GetFullName(pchar) + ", � ����� ������� ����� ����. ������� ���� ��������� ���������!";
			link.l1 = "�������, ������� ��! �� ��� ��������� ����� ����...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -5000000);
    		GiveItem2Character(pchar, "sculMa1");
    		GiveItem2Character(pchar, "sculMa2");
    		GiveItem2Character(pchar, "sculMa3");
    		GiveItem2Character(pchar, "indian022");
    		pchar.questTemp.Azzy.Lee = 1;
		break;

	//******************** ������� �� ***************************

                            case "GothicLee":
 	                PlaySound("VOICE\Russian\gotica\LEE\LEE_HALLO_00.wav");
                                dialog.text = "������ ������� ���� ��������� ������� ����, ��� �� ������� �����? � ����� �� �����...";
		link.l1 = "������ ��� ���? ������� ��, ��� ��?";
                                link.l1.go = "Gothic_HALLO_1";
                            break;

                            case "Gothic_HALLO_1":
	                PlaySound("VOICE\Russian\gotica\LEE\RICHTERBEWEISE_01.wav");
                                dialog.text = "������ � ��� ��!";
		link.l1 = "������� � ��� �� ���� �� �������, ��� ��?";
                                link.l1.go = "Gothic_HALLO_2";
                            break;

                            case "Gothic_HALLO_2":
                                dialog.text = "�� � ������ ����, ��� ����, � ������ �����!";
		link.l1 = "� ����� ���� ���� �����, ��� ���������?";
                                link.l1.go = "Gothic_HALLO_3";
                            break;

                            case "Gothic_HALLO_3":
                                dialog.text = "� �� ����, �� ����� ��� ������� � ����������� ������� � � ������������ �������!";
		link.l1 = "�� ����� ����?";
                                link.l1.go = "Gothic_HALLO_4";
                            break;

                            case "Gothic_HALLO_4":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_02.wav");
                                dialog.text = "�� ��� ���, ���� ������, ��� ��� �� �������� ������!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_5";
                            break;

                            case "Gothic_HALLO_5":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_03.wav");
                                dialog.text = "";
		link.l1 = "�� ��� ������������ ��� �!";
                                link.l1.go = "Gothic_HALLO_6";
                            break;

                            case "Gothic_HALLO_6":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_04.wav");
                                dialog.text = "�� ����� �� �� �������, ��� ������� ��� �� ������ ����� ����� �����!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_7";
                            break;

                            case "Gothic_HALLO_7":
                                dialog.text = "";
		link.l1 = "�� ������ ����?";
                                link.l1.go = "Gothic_HALLO_8";
                            break;

                            case "Gothic_HALLO_8":
	           PlaySound("VOICE\Russian\gotica\LEE\WHO_01.wav");
                                dialog.text = "�������, ������������, ������ ������ � ������� �������, �� ����� ���� ����� � ����� �������, ��� ���� � �������.";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_9";
                            break;

                            case "Gothic_HALLO_9":
	           PlaySound("VOICE\Russian\gotica\LEE\LEE_01.wav");
                                dialog.text = "�� ������� ���, ��!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_10";
                            break;

                            case "Gothic_HALLO_10":
	           PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE05.wav");
                                dialog.text = "";
	           link.l1 = "�������. � ��� �� ������?";
                                link.l1.go = "Gothic_HALLO_11";
                            break;

                            case "Gothic_HALLO_11":
                                dialog.text = "��, ����� ������ �� ���� ���� ������, ������ ���� � ����, ���� �� ����!";
		link.l1 = "��� ������� �������! � ��� �� ����� �����������!";
                                link.l1.go = "Gothic_HALLO_12";
                            break;

        case "Gothic_HALLO_12":
            dialog.text = "� ������� �� ������������� �������, ��� ���� �� ��������������� ����������, ������ ��������� ��������� � ���� ��������, ���� ������ � ��� �� ��������� ����� �� ����.";
            link.l1 = "� ��� �� �� ������, �� ��� ��, ����� ����.";
            link.l1.go = "Gothic_HALLO_13";
        break;
        case "Gothic_HALLO_13":
            dialog.text = "������, � ������ ����!";
            link.l1 = "�� � �����, ��� � ����� ��������� � ���� ���� ����� �����������, ��� ����� �����������...";
            link.l1.go = "Gothic_HALLO_14";
        break;
        case "Gothic_HALLO_14":
            dialog.text = "� ����, ��� ��� �� �����������, �� ��, ��� �� ����� � ���, ��� �� ��� �����?";
            link.l1 = "�� ������� ��������, �� ��������, �� ��� ���������, ��������� ������, �� ��� �� ��� � �� ����� � ��� ����� � ������� ����� �� ���� � ������� ������ ����������, ��� ����� ������� �� - �������� �� ����.";
            link.l1.go = "Gothic_HALLO_15";
        break;
        case "Gothic_HALLO_15":
            dialog.text = "��� ��� ����� ���� �� ����?";
            link.l1 = "��� ������.";
            link.l1.go = "Gothic_HALLO_16";
        break;
        case "Gothic_HALLO_16":
            dialog.text = "��-��-��, � �� ������� � �� �������?";
            link.l1 = "��� ������, ������ �� �����.";
            link.l1.go = "Gothic_HALLO_17";
        break;
        case "Gothic_HALLO_17":
            dialog.text = "����� ����� � ����?";
            link.l1 = "��� ���, ��� ���������, ��� ��� ���, � ���������, � ����� ��� ���� ��� ����... � ����� ��� ���.";
            link.l1.go = "Gothic_HALLO_18";
        break;
        case "Gothic_HALLO_18":
            dialog.text = "���? �� ����� ����? ������ ��, ���� ��������� �����?";
            link.l1 = "��� �� ��������� ��� ���� ������.";
            link.l1.go = "Gothic_HALLO_19";
        break;
        case "Gothic_HALLO_19":
            dialog.text = "������?";
            link.l1 = "�� �� ���������, ������.";
            link.l1.go = "Gothic_HALLO_20";
        break;
        case "Gothic_HALLO_20":
            dialog.text = "� ��� ��?";
            link.l1 = "�� ����, ���� ����, �� ���-�� �����.";
            link.l1.go = "Gothic_HALLO_21";
        break;
        case "Gothic_HALLO_21":
            dialog.text = "��� ���������� ��� �����? � ���, ��� �� �� ������ ������ �� ������������� � ������ ���������� �� ���� � ����, ���� ��� ���� �����������?";
            link.l1 = "";
             link.l1.go = "Gothic_HALLO_22";
                    CloseQuestHeader("Berglars");
	ChangeCharacterComplexReputation(pchar, "nobility", 2);
	AddCharacterExpToSkill(pchar, "Repair", 270);
	AddCharacterExpToSkill(pchar, "Sneak", 260);
	AddCharacterExpToSkill(pchar, "Cannons", 300);
	AddCharacterExpToSkill(pchar, "FencingL", 270);
	AddCharacterExpToSkill(pchar, "FencingH", 230);
	AddCharacterExpToSkill(pchar, "FencingS", 250);
        break;

                            case "Gothic_HALLO_22":
	           PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE03.wav");
                                dialog.text = "";
	           link.l1 = "��� �� ����������� �� ������ �������?";
                                link.l1.go = "GothicLee_1";
                            break;

                           case "GothicLee_1":
                                dialog.text = "� ��� ����, ������� ����������� ������, ���� ����������, �� �� � ��� ��� ������. � ���� ������� � ���� ���� ����� �������� ��� ��������...";
		link.l1 = "��, ������� ����� � ����...";
                                link.l1.go = "Gothic_1";
                            break;

        //********************** ����� ��������� ����� ���� ************************
        case "Gothic_1":
            dialog.text = "� ���� ����, ��� �� �������"+ GetSexPhrase("�� ���������","�� �����������") +", � � ����, ��� ��� ���� ����� '�����' �� ������ ����. ��������, ��� ������� ���������� ����, �� �������, ��� ������ �������... ��� ����� � ����� �����, � ���� ������, ���������� �� �� �� �� ������ ��� ��������, ��� �� "+ GetSexPhrase("������","����������� �������") +"!";
			link.l1 = "���� ������, ����� ������, ��� � ���� ������ ������, �� ����� �� ������� �������, ��� � "+ GetSexPhrase("������ � ���������","�������������") +"! � ������ ����.";
            link.l1.go = "Gothic_2";
        break;
        case "Gothic_2":
            dialog.text = "��, ��������, � �����, ��� � ����������� ��������� �� ������� ������ ��� ����� �������� ������������. ������ ����-��� - ��� ��� ��� ���������, ����� ������ �����, ������� ���� ������ ������... �� ���, �� ��� ������� ������� �����.";
			link.l1 = "���� ������ ������� �� ������ ����������?";
            link.l1.go = "Gothic_3";
        break;
        case "Gothic_3":
            dialog.text = "���� �� �� ���. ���� ����, ������� ����� ��������� �������� ������� ������ ����� �������, �� ��������� ������ �������� ��� ������� ��������� �������... ��������� �� �� �������, � ������� ��� ��������� - ����"+ GetSexPhrase(", ��������� ��������"," ������������! ��, ��� �������, ������ ������ ����") +"!";
			link.l1 = "����� ������, �� �������-�� �������� �� ����. ���� � ����"+ GetSexPhrase("��","��") +" ������?";
            link.l1.go = "Gothic_4";
        break;
        case "Gothic_4":
            dialog.text = "� ����, ��� �� ���� ����� ����������! ����, � ������� � ������, - ������� ���� ���� �������� �� �����, ���������� ������. ���� �������� ���������� � ����� � ����� ������ ������� �� ������.\n"+
						  "��� ����, ����� �� ���� ������� ��� �������, � ��� ���� ��������� �������� �������� ������ �� 60 ����, � ��� ���� ����� ��������� �������� � ��������� ����� � �������� ��������� ������. � ���������� � ���, ����� �� ����� ������� ���������� ������������� ������� ����.\n"+
				          "���, ������ ��� ������, �� ���� ����� ���� ������� �� ����� ������, ��� �� - ��� ���������� �������. � �����, ����� ���� ��������� ������� - � ����� �����.";
			link.l1 = "� �����"+ GetSexPhrase("","�") +" ����. ���������, ����������� ����, ������ ���� ���� �������... ��� ����� ������� � ������ ���� - �� ����������.";
            link.l1.go = "exit";

                                         GiveNationLicence(HOLLAND, 60);
                                        GiveItem2Character(pchar,"DOjeronRing");
                                        pchar.questTemp.GothicLee = "GothicLeeTakeAnna_toHavana";
                                        AddQuestUserData("GothicLee_TakeAnna", "sSex", GetSexPhrase("","�"));
	                        LocatorReloadEnterDisable("Havana_town", "houseS1", true);
                                        AddQuestRecord("GothicLee_TakeAnna", "1");
        break;

        case "Gothic_5":
            dialog.text = "������! � � ����������� �� ���� ����������������� � ��������. � ��� ���������?";
			link.l1 = "�� ������ ����������, ��. � ������ �� �����"+ GetSexPhrase("","�") +" � ��� ����������� - ���� ���������� �������, ���-�����...";
            link.l1.go = "Gothic_6";
        break;
        case "Gothic_6":
            dialog.text = "�-��, ��������... �� ��� ��, ��� ���� ��� ������ ������� � ���, ������� �� �� � ��� �� ��������.\n"+
				          "� ����� ���� �������� �� ��� � ����������, ��������, � ���� ����� ��� ���� ������.";
			link.l1 = "������, ������� ��...";
                   link.l1.go = "exit";
                   pchar.questTemp.GothicLee = "empty";
                   SaveCurrentQuestDateParam("questTemp");
                   SetTimerCondition("GothicLee_Lee_SeekBible", 0, 1, 0, false);
                   CloseQuestHeader("GothicLee_TakeAnna");
                   TakeItemFromCharacter(pchar, "letter_open");
                   BackItemDescribe("letter_open");
	ChangeCharacterComplexReputation(pchar, "nobility", 10);
	AddCharacterExpToSkill(pchar, "Sneak", -100);
	AddCharacterExpToSkill(pchar, "Sailing", -100);
	ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
			//�����
			AddSimpleRumour("����� �����, ��� ������� " + GetFullName(pchar) + " ��������"+ GetSexPhrase("","�") +" �����-�� ����� ������ ������� ��, ��������� � �������� ������...", FRANCE, 5, 1);
		break;
        case "Gothic_7":
			dialog.text = "��� �� �����, ������� �� ���� �������� ��������������.\n"+
				          "� ���� ������, �� �� �������� ���� ������, ��� ������ �� �� ���������������� ��������. �������� ����� ��������� �����...";
			link.l1 = "������, ��. ����������� ���� �����...";
               link.l1.go = "exit";
               pchar.questTemp.GothicLee = "empty";
               SaveCurrentQuestDateParam("questTemp");
              CloseQuestHeader("GothicLee_TakeAnna");
              TakeItemFromCharacter(pchar, "letter_open");
              BackItemDescribe("letter_open");
              AddMoneyToCharacter(pchar, 25000);
              sld = characterFromId("AnnaDeLeiva");
              RemovePassenger(pchar, sld);
               DeleteAttribute(sld, "RebirthPhantom");
               sld.LifeDay = 0; // ������ ���
               DoQuestFunctionDelay("GothicLee_townhall_room", 15.0);
               pchar.questTemp.GothicLee = "AnnaIsLife"; //�� ������� ���� �� ������ �����
               AddTitleNextRate(sti(NPChar.nation), 3);
               ChangeCharacterComplexReputation(pchar, "nobility", 5);
               ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
              AddCharacterExpToSkill(pchar, "Leadership", 150);
              AddCharacterExpToSkill(pchar, "Repair", 200);
              AddCharacterExpToSkill(pchar, "Sailing", 150);
              AddCharacterExpToSkill(pchar, "Repair", 250);

                     // ������� ��� ������� ������
                     pchar.questTemp.GothicThekla = "UneasySagitta";

			//�����
			AddSimpleRumour("����� �����, ��� ������ ������� " + GetFullName(pchar) + " �������"+ GetSexPhrase("","�") +" ������ ��������� � ������������, � �����"+ GetSexPhrase("","�") +" ��������� ���� ��������� ������ �������� �� - ����� ����...", FRANCE, 5, 1);
		break;

        //********************** ����� ����� ���� ************************

        case "GothicLeeAnnaHant_GoodWork":
                    dialog.text = "�� ��� ������ �� ������, � ������� ������, ��� ��� ������ ����, ������� �� �� ���� �� ���������. ��� ����� �������, � ����� �� ����� ����� ���� ����� �������������.";
                    link.l1 = "�������, ������� ��...";
                    link.l1.go = "exit";
	LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
	DeleteAttribute(&locations[FindLocation("Mayak10")], "DisableEncounters"); //������� ����������
	pchar.questTemp.GothicLee = "empty";
	SaveCurrentQuestDateParam("questTemp");
                     SetTimerCondition("GothicLee_SeekBible", 0, 0, 2, false);				
	CloseQuestHeader("GothicLee_2_KillAnnaHanters");
	AddMoneyToCharacter(pchar, 15000);
        break;

        //********************** �����, ������ ��������� ��� ������ ************************

        case "Gothic_SeekBible":
            PlaySound("VOICE\Russian\GOTHIC\GG_\.wav");
            dialog.text = "";
            link.l1 = "��� � ��� ���� ������?";
            link.l1.go = "Gothic_SeekBible1";
        break;

        case "Gothic_SeekBible1":
            PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE_01.wav");
            dialog.text = "��, � ��� � ����, ���� ����� ����� ������ ���!";
            link.l1 = "�.";
            link.l1.go = "Gothic_SeekBible02";
        break;

        case "Gothic_SeekBible02":
            PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_1.wav");
            dialog.text = "";
            link.l1 = "�....";
            link.l1.go = "Gothic_SeekBible2";
        break;

        case "Gothic_SeekBible2":
                                dialog.text = "� ���� � ���� ������ �������. ��� ����, ����� ������ ���������� ������, ������ ������������� � ���� ���������� ��������. ����� ����� ����������� � ���� ������ ���. ������� ��� ����������� � ������ ����-��, ����� ��� �������. � �����, ����� ��������� ���� ��� ���, �� ������ � ����� ����, ������� ���. ���������� �� � ���� ������, ��� ��� ����� �������� �� ������� � ������� �����.";
                                link.l1 = "� �����"+ GetSexPhrase("","�") +", ��. ���������� ���������� � ����.";
                                link.l1.go = "exit";
                                pchar.questTemp.GothicLee = "SeekBible_toAaron";
                                AddQuestRecord("GothicLee_3_SeekBible", "1");
	              AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("","�"));
                                SaveCurrentQuestDateParam("questTemp");
	              sld = characterFromId("Chumakeiro");
	              LAi_SetSitTypeNoGroup(sld);
                   ChangeCharacterAddressGroup(sld, "Aaron_House", "sit", "sit1");
        break;

        case "Gothic_3_1":
            dialog.text = "�� ����� ��������� ������������. � ������� ����� ��������, �� �� ���� ��������� ����������� �������. �� ��� ��, ������������ �� ��� ����� �� �������, ��������, � ����� ��������� ��� ���� ��, ��� ����� ���� �� �����.";
            link.l1 = "������, ��.";
            link.l1.go = "exit";
            CloseQuestHeader("GothicLee_3_SeekBible");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("GothicLee_Gorn", 0, 0, 14, false);
            pchar.questTemp.Waiting_time = "30";
			ChangeCharacterComplexReputation(pchar, "nobility", -2);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -260);
			AddCharacterExpToSkill(pchar, "Cannons", -300);
			AddCharacterExpToSkill(pchar, "FencingL", -270);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -250);
 			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " ����"+ GetSexPhrase("��","���") +" �� ���������� ���������� ������� - ������ ������-�� ����������� ����������� ��������. ����"+ GetSexPhrase("��","���") +", �� �� ������"+ GetSexPhrase("","�") +"...", HOLLAND, 5, 1);
		break;

        case "Gothic_3_2":
            dialog.text = "�-�-�, ��� �� ���... �� ��� ��, ���������. �������, �� ������������ ���� ������� �������?";
            link.l1 = "����� ���, ������� ��.";
            link.l1.go = "Gothic_3_3";
        break;
        case "Gothic_3_3":
            dialog.text = "�����������. �������, � ���� ���. �� ���� ��� �� �����, ������ ���������� ������ ������. � ��� ����� ���� ������ ����� ��������� �� ���, ��������� � ���� ����� ��� ���� ����� �������.";
            link.l1 = "������ � ����� �������, ��.";
            link.l1.go = "exit";
            CloseQuestHeader("GothicLee_3_SeekBible");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("GothicLee_Gorn", 0, 0, 14, false);
			ChangeCharacterComplexReputation(pchar, "nobility", 4);
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 270);
			AddCharacterExpToSkill(pchar, "Sneak", 260);
			AddCharacterExpToSkill(pchar, "Cannons", 300);
			AddCharacterExpToSkill(pchar, "FencingL", 270);
			AddCharacterExpToSkill(pchar, "FencingH", 230);
			AddCharacterExpToSkill(pchar, "FencingS", 250);

                                                           // ������ � ������ ���� ������
                                                           pchar.questTemp.GothicSmithy = "SagittaAnn";
 			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " ������ �� ���������� ���������� ������� - ������ ������-�� ����������� ����������� ��������. � �������, ��� �����.", HOLLAND, 5, 1);
        break;

        //********************** �����. ���������� �� ������ ����� ************************	
		case "Gothic_5_1":
            PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_2.wav");
            dialog.text = "";
            link.l1 = "��� ��������� �� ��������� �����?";
            link.l1.go = "Gothic_5_01";
        break;

		case "Gothic_5_01":
            dialog.text = "� �������� � ���� ����� ����. ������� ��� ����� �� ����������, ��������� �� ���������� ������� ��������. ����������, ������ ��� ����������� ����� � ���������� ��������, ��� ������� ��������, ��� �� ��������� ���������� � ��� ������. �� ��� ���� �� ����� �������.";
			link.l1 = "������ - �� �������?! � ��� �� �����?";
            link.l1.go = "Gothic_5_2";
        break;
		case "Gothic_5_2":
            dialog.text = "������ ���� ���������� ����� ����������� �����, � � ��������, ��� ���� ��������� �� ������ ��� ������...";
			link.l1 = "... �� � ��� ����, �������, ��� � �������, ����� ������ ������...";
            link.l1.go = "Gothic_5_3";
        break;
		case "Gothic_5_3":
            dialog.text = "���������� �����. ��� ��� �� ���������: ����������� ����� ��� �����������. ��� �������, ��� ����� ��������� � ��������. �� ������ ���������� ���� ��� ����� ������� � �������� ��� �� ����� ����� �����. � ����, ����� ���� ��� �����, � �� ����������� ����� � ��������.";
			link.l1 = "�� ���� �� ��������...";
            link.l1.go = "Gothic_5_4";
        break;
		case "Gothic_5_4":
            dialog.text = "����� ������� ������ �� ������, �� �� ������ � ��. � � ���� ���� ��������� ��������, ��� ���� � ������������� �� �������� ����������� �� �������� ������������� ��������� ����� ����� ��������...";
			link.l1 = "������� ���������, �� ��� ��� �� ���! � ����������� ����������.";
            link.l1.go = "Gothic_5_5";
        break;
		case "Gothic_5_5":
            dialog.text = "����� ������. � ��� - � ������ ��� ���������� ����������� �������, �� ����������� �� �������� �������. ��� ����� � ����� ��� ��� ����������� ������� ����������� ����-������� �������� ��������.";
			link.l1 = "�������� �������, ������� ��.";
            link.l1.go = "exit";
			LAi_group_Delete("PeaceGroup");
			GiveNationLicence(HOLLAND, 60);

    		pchar.questTemp.GothicLee = "RockBras_toSeekPlace";
            AddQuestRecord("GothicLee_5_RockBras", "1");
			SaveCurrentQuestDateParam("questTemp");
			//==> ����� - � ����������. 
            sld = GetCharacter(NPC_GenerateCharacter("Gorn", "Gorn", "man", "man", 30, PIRATE, -1, false, "quest"));
			FantomMakeCoolFighter(sld, 30, 90, 90, "", "", "", 80);
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_2.c";
			sld.RebirthPhantom = true;
        	sld.name 	= "����";
        	sld.lastname 	= "";
			LAi_LoginInCaptureTown(sld, true);
			LAi_NoRebirthEnable(sld);
			LAi_SetLoginTime(sld, 0.0, 24.0);
			LAi_SetGroundSitType(sld);
			LAi_group_MoveCharacter(sld, "PeaceGroup");
			ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio", "prison", "prison9");
        break;
		case "Gothic_5_6":
            dialog.text = "��, ���������� � ����� ����������, "+ GetSexPhrase("�����","�����������") +". �� �������� �� ���� ����� ����.\n"+
				          "����� ����, "+pchar.name+", ��� �� �� ����� ��������� �������, ����� ����... �������, �� ��� ������ �� �����. �� ������ ����������� �� ��� � ���������� ������������, ��������, � ��� ���� �������� ������...";
			link.l1 = "������, ��.";
            link.l1.go = "Gothic_5_exit";	
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -170);
			AddCharacterExpToSkill(pchar, "Defence", -130);
			AddCharacterExpToSkill(pchar, "Cannons", -150);
			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " �� �����"+ GetSexPhrase("","�") +" �������� ����� �� ��������� ���������. �����, �� ��� ������� ���������...", FRANCE, 5, 1);
            pchar.questTemp.Waiting_time = "35";
        break;
		case "Gothic_5_7":
            dialog.text = "�-��, ��������... �� ��� ������� �������� � ��������� ���������. ����� ����.\n"+
				          "�� ��� ��, � �������, �� ������ ��� ��������� ��� ��� ��������. ������� � ��������� ���� ���� � ���� � ���������� ����� ����� - � ����� ��� ���� ����� ����.";
			link.l1 = "������, ��, ���� ����������.";
            link.l1.go = "Gothic_5_exit";
			AddTitleNextRate(sti(NPChar.nation), 1);
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 100);
			AddCharacterExpToSkill(pchar, "Defence", 100);
			AddCharacterExpToSkill(pchar, "Cannons", 100);
			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " �� �����"+ GetSexPhrase("","�") +" �������� ����� �� ��������� ���������. �����, �� ��� ������� ���������...", FRANCE, 5, 1);
            pchar.questTemp.Waiting_time = "15";
        break;
		case "Gothic_5_exit":
                                                      pchar.questTemp.GothicLee = "empty";
                                                      SaveCurrentQuestDateParam("questTemp");
			SetTimerCondition("Gothic_Lee", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_5_RockBras");

                                                      sld = characterFromId("Gorn");
			DeleteAttribute(sld, "RebirthPhantom");
         	                                    sld.LifeDay = 0; // ������ ���
			DialogExit();
                                                      break;
		case "Gothic_5_8":
            dialog.text = "�� ����������, "+pchar.name+". �������� �� ����������� ������ �������� 30 ����� �����. ������ ��������.";
			link.l1 = "�������, ��...";
            link.l1.go = "Gothic_5_9";
        break;
		case "Gothic_5_9":
            dialog.text = "�, ��� ������, ����� ���� ����������� � ��� ���������� ����� �� �������, �������, ��� � ��������� ����� �� ������ ��� �����.";
			link.l1 = "������, ��, ����������� ���� �������� ����.";
            link.l1.go = "Gothic_5_Rock";
			AddMoneyToCharacter(pchar, 30000);
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
			SetTimerCondition("Gothic_Lee", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_5_RockBras");
	
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 200);
			AddCharacterExpToSkill(pchar, "Sneak", 300);
			AddCharacterExpToSkill(pchar, "Cannons", 250);
			AddCharacterExpToSkill(pchar, "Accuracy", 350);
			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " �������"+ GetSexPhrase("","�") +" ����� �� ��������� ���������. ��������� �����, ����� � ���, ���� ����� �������.", FRANCE, 5, 1);
        break;
		case "Gothic_5_Rock":
			sld = characterFromId("Gorn");
			RemovePassenger(PChar, sld);
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
			DialogExit();
        break;

        //********************** �����. ������� � ����� ��������� ************************
                            case "Gothic_6_1":
                                dialog.text = ""+pchar.name+", ��� ��������� ������������ ��������� ����������, ���������������, ������� � ���������� ������������� ������� � ������������ �������� ���������� ������� ������� �������, ������� ������ ��������� �� ���������. ���� ����������� � ������ ���������.";
								link.l1 = "��������� �� ������� ��. �� � ��� ����������� ��� �������?";
                                link.l1.go = "Gothic_6_2";
                            break;	
		case "Gothic_6_2":
            dialog.text = "���� ������ � ���, ����� ��� ����� ������ ������� � �������. ����������� ��� ����������, ���� �� �����, ���� ����� ������ ���������.";
			link.l1 = "��� �, ��� �� � ������. ������� �������, � �����������...";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "ThreeCorsairs_toBonrepo";
            AddQuestRecord("GothicLee_6_ThreeCorsairs", "1");
			//==> ������ �������.
            sld = GetCharacter(NPC_GenerateCharacter("Bonrepo", "off_fra_6", "man", "man", 20, FRANCE, -1, false, "quest"));
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_1.c";
        	sld.name 	= "������";
        	sld.lastname 	= "�������";
			sld.greeting = "Gr_QuestMan";
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "BasTer_townhall", "goto", "governor1");
        break;

		case "Gothic_6_3":
            dialog.text = ""+pchar.name+", �� ��� � ���� ����� ���������� ��������. ����� ��������� � �������� ���������� ����� �� ������ �� �� ����� ������.";
			link.l1 = "��, �� � ���� �������� � ���� ������� ��������� ������...";
            link.l1.go = "Gothic_6_4";
        break;
		case "Gothic_6_4":
            dialog.text = "�� �� ����, � ������� ����� ���������, ��� ����� �� ��� ������ �� ����. ��� ��� ��������� ���, ��� ����, �� � ���� ����� ������ � ���� � ���� ���, �� � ���� ���, ���� �� ������ ����� �� ������� �������� ���� - ��������, ��� ��� ��������� ���������� ����!";
			link.l1 = "������, ��. �, ��� "+ GetSexPhrase("����������� ��������, �����","����������� ��������, ���������") +", ���� � ������ � ��� � ���������� ����. ������� ��� ������� ����� ��������?";
            link.l1.go = "exit";
            pchar.questTemp.GothicLee = "empty";
			pchar.questTemp.Waiting_time = "12";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("Gothic_Lee_SOLEYRU", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_6_ThreeCorsairs");
			AddTitleNextRate(sti(NPChar.nation), 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			AddCharacterExpToSkill(pchar, "Sailing", 290);
			AddCharacterExpToSkill(pchar, "Leadership", -100);
			AddCharacterExpToSkill(pchar, "Commerce", 250);
			AddCharacterExpToSkill(pchar, "Pistol", 350);
			//�����
			AddSimpleRumour("�������, ��� �������� " + GetMainCharacterNameDat() + " ��������� ���������� ����� �����"+ GetSexPhrase("�","����") +"! ��, ����...", FRANCE, 5, 1);
        break;

        //********************** �����. ������ ��������� �� ����-�-����� ************************
                            case "Gothic_7_1":
                                dialog.text = "�����"+ GetSexPhrase("","����") +", ��� ��������� ��������� ���� ���������� ������������ ������������ �������� ������� � ������� � ��� ������������ �������� ������� '����� ������'. ���� ��������� ������ ����� �������� � ������� ��������� ������ ������� � ������ ������������� �����. ������ ������ - ������ ��������� ��������� ������� �� ����-�-�����.";
								link.l1 = "��, ������ ������� ����� ������� ���������� ����������...";
                                link.l1.go = "Gothic_7_21";
                            break;	
		case "Gothic_7_21":
            dialog.text = "��� ���, �����"+ GetSexPhrase("","����") +". ��� ��� ������ �� ��������� ���������� ��-����, ������, �� ���� ���������, ������� �� ����-�-�������.";
			link.l1 = "� �����"+ GetSexPhrase("","�") +", ��. � ���� ���������� � ���������� ������?";
            link.l1.go = "Gothic_7_11";
        break;
		case "Gothic_7_11":
            dialog.text = "� ��������, ��. ������, ��� ����� ������� �� ���� ��������� - '����� ������' ��������� ���� � �������� �������� �������.\n"+
				          "�� �� � ���� ������ �� ������ �������� ���� �������, ��� ����� �������� ������ ������. � �� �� ������� ������ �������� �� ����������� �������������.";
			link.l1 = "��, �� ��� ��, � ����� ��� ���� � ����, ����� ������������ '����� ������' �������� �� ���������.";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "GuardPP_toPortPax";
            AddQuestRecord("GothicLee_7_GuardPortPax", "1");
sld = GetCharacter(NPC_GenerateCharacter("SoleiRoyalCaptain", "off_fra_4", "man", "man", 35, FRANCE, -1, true, "soldier"));
			sld.Ship.Type = CreateBaseShip(SHIP_SOLEYRU);
			sld.Ship.Name = "����� ������";
			SetBaseShipData(sld);
			ResetShipCannonsDamages(sld);
			SetCrewQuantityFull(sld);
			sld.ship.Crew.Morale = 80;
			sld.Ship.Crew.Exp.Sailors = 90;
			sld.Ship.Crew.Exp.Cannoners = 90;
			sld.Ship.Crew.Exp.Soldiers = 90;
			Fantom_SetBalls(sld, "pirate");	
			FantomMakeCoolFighter(sld, 35, 100, 100, BLADE_LONG, "pistol5", "cartridge", 100);	
	SetSelfSkill(sld, 80, 50, 90, 70, 100);
	SetShipSkill(sld, 100, 30, 70, 70, 95, 50, 80, 55, 70);
			sld.CompanionEnemyEnable = false;
			sld.Abordage.Enable = false; // ������!
			SetCompanionIndex(pchar, -1, sti(sld.index));
			SetShipRemovable(sld, false);
			sld.SuperShooter  = true;
			sld.SaveItemsForDead  = true; 
			sld.DontClearDead = true;
			sld.DontRansackCaptain = true;
			sld.AlwaysSandbankManeuver = true;
			sld.AnalizeShips = true;
			sld.CoolBrander = true;
			sld.GenQuest.CrewMaltaMode  = true;
			sld.Ship.Mode = "Malta";
			SetCharacterPerk(sld, "Doctor1"); 
			SetCharacterPerk(sld, "Doctor2");
			SetCharacterPerk(sld, "Doctor3");
			GiveItem2Character(sld, "pistol5");
			sld.equip.gun = "pistol5";
			GiveItem2Character(sld, "blade_19");
			sld.equip.blade = "blade_19";
			GiveItem2Character(sld, "spyglass3"); 
			EquipCharacterbyItem(sld, "spyglass3");
			GiveItem2Character(sld, "cirass1"); 
			EquipCharacterbyItem(sld, "cirass1"); 
			GiveItem2Character(sld, "bussol"); 
			EquipCharacterbyItem(sld, "bussol"); 
			LAi_SetCharacterUseBullet(sld, "bullet"); 
			TakeNItems(sld, "bullet", 50); 
			AddItems(sld, "gunpowder", 50); 
			TakeNItems(sld, "potion2", 5);
			SetCharacterPerk(sld, "Energaiser"); 
			SetCharacterPerk(sld, "BasicDefense"); 
			SetCharacterPerk(sld, "AdvancedDefense"); 
			SetCharacterPerk(sld, "ProfessionalDefense"); 
			SetCharacterPerk(sld, "Tireless"); 
			SetCharacterPerk(sld, "CriticalHit"); 
			SetCharacterPerk(sld, "Sliding"); 
			SetCharacterPerk(sld, "SwordplayProfessional"); 
			SetCharacterPerk(sld, "BladeDancer"); 
			SetCharacterPerk(sld, "Gunman"); 
			SetCharacterPerk(sld, "GunProfessional"); 
			SetCharacterPerk(sld, "Sniper");
			SetCharacterPerk(sld, "IronWill"); 
			SetCharacterPerk(sld, "ShipEscape"); 
			SetCharacterPerk(sld, "Troopers"); 
			SetCharacterPerk(sld, "MusketsShoot"); 
			SetCharacterPerk(sld, "CrewDamageUp"); 
			SetCharacterPerk(sld, "BasicCommerce"); 
			SetCharacterPerk(sld, "AdvancedCommerce"); 
			SetCharacterPerk(sld, "HullDamageUp"); 
			SetCharacterPerk(sld, "SailsDamageUp"); 
			SetCharacterPerk(sld, "CriticalShoot"); 
			SetCharacterPerk(sld, "Carpenter"); 
			SetCharacterPerk(sld, "LightRepair"); 
			SetCharacterPerk(sld, "StormProfessional"); 
			SetCharacterPerk(sld, "WindCatcher"); 
			SetCharacterPerk(sld, "SailsMan"); 
			SetCharacterPerk(sld, "ShipSpeedUp"); 
			SetCharacterPerk(sld, "ShipTurnRateUp"); 
			pchar.TempPerks.QuestTroopers = true; //���� ���������� �������
			SetTimerCondition("GuardPP_Late", 0, 0, 25, false);
            Pchar.quest.GuardPP_Fight.win_condition.l1 = "location";
            Pchar.quest.GuardPP_Fight.win_condition.l1.location = "Hispaniola2";
            Pchar.quest.GuardPP_Fight.win_condition = "GuardPP_Fight";
        break;
		case "Gothic_7_2":
            dialog.text = "�����, �����"+ GetSexPhrase("","����") +", � ��������� ��������. ����������� ������������� ������������� ������������ ����� �� ������ �������� � ���������� ������� ������� - 1 ������ ��������... �������� ��������.";
			link.l1 = "����� 1 ������?! ��������, ��� ������, ��� ������!";
            link.l1.go = "Gothic_7_3";
        break;
		case "Gothic_7_3":
            dialog.text = "�����"+ GetSexPhrase("","����") +", ��� ����� ������� �� ���� ��� ����������� ���������� ���. � ����� ���� ������ �������� - ����� ��������������� �� �������. ������� ����� ���� ������� ����������� �������� ��� ��������.\n"+
				          "������ � ��� ����������� �� ���� - ������������� � ��������� ������ ���������. � ����� - �� ����� �������!";
			link.l1 = "��, �� ��� ��, ���� � ��� ���"+ GetSexPhrase("��","��") +" ������� - ��� ���� �������. ���� � ��� � ���������� ����� ����, ��� ������� � ������� ���� ����, �������. �� ��������.";
            link.l1.go = "exit";
			Log_Info("�� �������� 1000 ��������");
			TakeNItems(pchar, "gold_dublon", 1000);
			PlaySound("interface\important_item.wav");
                                                      pchar.questTemp.GothicLee = "empty";
			pchar.questTemp.Waiting_time = "18";
                                                      SaveCurrentQuestDateParam("questTemp");
                                                      SetTimerCondition("Gothic_Lee_OccupySantoDomingo", 0, 0, 5, false);
			CloseQuestHeader("GothicLee_7_GuardPortPax");
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 270);
			AddCharacterExpToSkill(pchar, "Sneak", 260);
			AddCharacterExpToSkill(pchar, "Cannons", 300);
			AddCharacterExpToSkill(pchar, "FencingL", 270);
			AddCharacterExpToSkill(pchar, "FencingH", 230);
			AddCharacterExpToSkill(pchar, "FencingS", 250);
			//�����
			AddSimpleRumour("�������, ��� ������� " + GetFullName(pchar) + " ����"+ GetSexPhrase("","��") +" ������� ����-�-����� �� ��������!", FRANCE, 5, 1);
        break;
		case "Gothic_7_4":
            dialog.text = "�� �� ������� '����� ������', "+pchar.name+", � ����� ��� ����������!";
			link.l1 = "� ������"+ GetSexPhrase("","�") +" ���, ��� ���� � ���� �����...";
            link.l1.go = "Gothic_7_5";
        break;
		case "Gothic_7_5":
            dialog.text = "�� ������ ������������! � �����, ������ ������ ������� ������� � ����, ��� ������� ������������ �� ����� �����, "+pchar.name+".";
			link.l1 = "� ��� ����� �����, ��� � ������"+ GetSexPhrase("","�") +" ��� �������?! �����, ��, ��� � ����"+ GetSexPhrase("��","�") +" ��� ��� ��� ������� �������...";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "QuestLineBreake";
			bWorldAlivePause   = true; // ����� �������
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//�����
			AddSimpleRumour("����� �����, ��� ��� ������� �� �������� ��� �� ���������� �� ��, ��� �� ���������� ������� '����� ������'. ���, �������...", FRANCE, 5, 1);
        break;
		case "Gothic_7_6":
            dialog.text = "���� ������, �� �� ������ "+ GetSexPhrase("��������� ����","��������� ��������") +"! � �� ����� ����� � ����� ������ ������. ������, �����"+ GetSexPhrase("","����") +"...";
			link.l1 = "������, ��, ��� ��������� ������ ������� �������...";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "QuestLineBreake";
			bWorldAlivePause   = true; // ����� �������
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			ChangeCharacterReputation(pchar, -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//�����
			AddSimpleRumour("����� �����, ��� ��� ������� �� �������� ��� �� ���������� �� ��, ��� �� ������� � ��� '����� ������'. ���, �������...", FRANCE, 5, 1);
        break;
		case "Gothic_7_7":
            dialog.text = "������, ��� �� ���?! ����� ������ ���� ����!! � ����� ���, � �� ����� ����� � ����� ������ ������. ������, �����"+ GetSexPhrase("","����") +"...";
			link.l1 = "������, ��, ��� ��������� ������ ������� �������...";
            link.l1.go = "exit";
			sld = characterFromId("SoleiRoyalCaptain");
			RemoveCharacterCompanion(pchar, sld);
			sld.LifeDay = 0;
			pchar.questTemp.GothicLee = "QuestLineBreake";
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			bWorldAlivePause   = true; // ����� �������
			CloseQuestHeader("GothicLee_7_GuardPortPax");
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//�����
			AddSimpleRumour("����� �����, ��� ������� �� �������� ��� �� ���������� �� ��, ��� �� �� ������ ������� ������� � ����-�-������ � ����� ��� ������� ���������. ������� ���!", FRANCE, 5, 1);
        break;

        //********************** �����. ������ �����-������� ************************	
                            case "Gothic_10_0":
                                dialog.text = "���, �����"+ GetSexPhrase("","����") +", � ��� ���� ������. �� ��� ������ �������!";
								link.l1 = "� ������ ����, ��.";
                                link.l1.go = "Gothic_10_1";
                            break;	
	
		case "Gothic_10_1":
            dialog.text = "������� ����� ���� ���������� ����� �� ������� ������� ����-�-������. �, ��� ��� �������, ������ ������� ����� ���������� ���������� ����� ������� ���������, ������ � ���������� �����������...";
			link.l1 = "������� ��, ����� ���� ������ ����� ���������.";
            link.l1.go = "Gothic_10_2";
        break;
		case "Gothic_10_2":
            dialog.text = "������, �����"+ GetSexPhrase("","����") +". ����, � ������� ���� ��������� �����-�������! ����� �������, ��� ��������� ����� ������������ ������� ����� �������, �� �� �������, � �������. ������ �������?";
			link.l1 = "�������, ��. �����, ��� ������ ������ ������ ������� ��������? � �� ���� ��������� '����� ������' � ����� ����� �� ���� ����!";
            link.l1.go = "Gothic_10_3";
        break;
		case "Gothic_10_3":
            dialog.text = "��, � �������. ������ �� ���� ����� ����� - ����� ������� �����-������� �� �������� ����� ������� ��������������.";
			link.l1 = "�� ��� ��, ��, � ���� ���. ����, � ��������� � ��������, ����� ���� � �������� ���������.";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "OccupySD_toSantoDomingo";
            AddQuestRecord("GothicLee_10_OccupySantoDomingo", "1");
			CloseQuestHeader("GothicLee_12_EndOfWar");
            DeleteAttribute(pchar, "questTemp.Waiting_time");
			characters[GetCharacterIndex("SantoDomingo_Mayor")].dialog.captureNode = "Quest_OccupySD"; //�������������� ���� ����
        break;
		case "Gothic_10_4":
            dialog.text = "�� ������� '����� ������'!!";
			link.l1 = "����� ���� ������, ������� ��, �������-�������� ������������� ����� �� ���. ��� ����� ����...";
            link.l1.go = "Gothic_10_5";
        break;
		case "Gothic_10_5":
            dialog.text = "���� ��������� ��� �� �����. ������ ������� ������� - ������� �������� ��� �������. ������� � ������ �� ���� ����� � ����� ���, ����������� ������������� ����� �� ������� ��� ������. ��������.";
			link.l1 = "��, ��� ������, ��...";
            link.l1.go = "exit";
			CloseQuestHeader("GothicLee_10_OccupySantoDomingo");
			pchar.questTemp.GothicLee = "QuestLineBreake";
			CloseQuestHeader("GothicLee_12_EndOfWar");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			bWorldAlivePause   = true; // ����� �������
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -170);
			AddCharacterExpToSkill(pchar, "Sneak", -100);
			AddCharacterExpToSkill(pchar, "FencingL", -130);
			AddCharacterExpToSkill(pchar, "FencingH", -130);
			AddCharacterExpToSkill(pchar, "FencingS", -130);
			//�����
			AddSimpleRumour("����� �����, ��� ��� ������� �� �������� ��� �� ���������� �� ��, ��� �� ���������� ������� '����� ������'. ���, �������...", FRANCE, 5, 1);
        break;
		case "Gothic_10_6":
            dialog.text = "���������, "+ GetSexPhrase("���� ���","�����������") +", ������ �����������!\n"+
				          "������ � ����, ����� ������ ��� ���� - � ��������������. � ����� ������ �� ������� �� �������������� ����� ���������� ����������� ����� - 4 ������ ������� ��������... ��� ����, �����"+ GetSexPhrase("","����") +"!";
			link.l1 = "�������, ������� ��. ��� ������� �����!";
            link.l1.go = "Gothic_10_7";
        break;
		case "Gothic_10_7":
            dialog.text = "� ����� ���, ��� �� ���������... �� ��� ��, ����������� ���� � �� ���� �����, ����� ���� �������� ����������� � ������� ����. ������� � ������� ���� ������� � ���� � ���� �������� ����� ������, �����"+ GetSexPhrase("","����") +".";
			link.l1 = "������, ������� ��, ���� � ���������� �����.";
            link.l1.go = "exit";
            Log_Info("�� �������� 4000 ��������");
           TakeNItems(pchar, "gold_dublon", 4000);
            PlaySound("interface\important_item.wav");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("Gothic_Lee_EndOfWar", 0, 0, 5, false);
			CloseQuestHeader("GothicLee_10_OccupySantoDomingo");
			AddTitleNextRate(sti(NPChar.nation), 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Pistol", 330);
			AddCharacterExpToSkill(pchar, "Fortune", 360);
			AddCharacterExpToSkill(pchar, "Accuracy", 320);
			AddCharacterExpToSkill(pchar, "Grappling", 350);
			AddCharacterExpToSkill(pchar, "Defence", 350);
			//�����
			AddSimpleRumour("�������, ��� �� ��������� �����-�������! ���������� ������, �������, ������ ������������!", FRANCE, 5, 1);
        break;

        //********************** ����� �12. ���������� ������� ************************
		case "Gothic_12_1":
            dialog.text = "��� ������������, �����! ������������� ����� � �������� ��������! ������� ������� � ��� ������� ��������� ������! �� ����� ���� ����� � ��� ������. �� ���� ����, ������ �� ��������� ����������� ������� ��� �������� � ��������� ����.\n"+
				          "���-������ ������� ������� ���� ������� �������� �� ������� � �����, ��� ��� ������ �������� ������ �������� XIV!";
			link.l1 = "� ����� � ����� ���"+ GetSexPhrase("","�") +". �����, ��, � �������� ��������� �� ������ ����� �� �������������?";
            link.l1.go = "Gothic_12_2";
        break;
		case "Gothic_12_2":
            dialog.text = "�� ���� ��� ������ �� ��������. �������, �� ������ ������ ���� ������ ������� �������. ��� ��������� ������ - ��������� �� ���-����, ��� �� ���������, � ����������� ��� � ��������. �� ������� ����.";
			link.l1 = "�������, ��! ����� ����� � �� �����... � �������� ����������.";
            link.l1.go = "Gothic_12_3";
        break;
		case "Gothic_12_3":
            dialog.text = "� ������� � ������� '����� ������', �� ������ ���� � ������ ������ ���������.";
			link.l1 = "������, ��.";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "EndWar_toBorepo";
			AddQuestRecord("GothicLee_12_EndOfWar", "1");
			//==> ������ �������.
            sld = GetCharacter(NPC_GenerateCharacter("Bonrepo", "off_fra_6", "man", "man", 20, FRANCE, -1, false, "quest"));
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_1.c";
        	sld.name 	= "������";
        	sld.lastname 	= "�������";
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "BasTer_townhall", "goto", "governor1");
        break;


		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���!!! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
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
            dialog.text = RandPhraseSimple("�� ���� ������� ������"+ GetSexPhrase("","�") +", �������� �������.", "� �� ���� � ����� ��������, ��� ��� ���� ����� ���� �� ����������.");
			link.l1 = RandPhraseSimple("�� ��� ������...", "��, �� ��� ��...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //����������� ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "�������, ������ �� �� ������ �������� ���� ������� �����������, ����� ��� �������� ���� �����. ���������, ��� ��� ����� ����� ���������.";
        			link.l1 = "������� ��, �� ������ ���� ������ - �� ����...";
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
            DoReloadCharacterToLocation("SantLous_town","reload","reload10");
		break;
		// <<<<<<<<<<<<============= ���� ��� angry =============================
		case "SantLous_town":
            dialog.text = "������ ��������? �� �� ��� ���������, ���� �� ���������? � �����, ��������� ��� ������� ���� - � ������� �����, ����� ��� ������ ���� '�������'. ��� - ������ �������� �� ��� ������ �������.";
			if (sti(Pchar.money) >= 1000000)
			{
				link.l1 = "������, � ����� ���������.";
				link.l1.go = "SantLous_town_pay";
			}
			link.l2 = "� �� �����. �����.";
			link.l2.go = "SantLous_town_exit";
		break;
		
		case "SantLous_town_exit":
			DialogExit();
            bDisableFastReload = true;//������� �������
			pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
			pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
			pchar.quest.pirate_in_town.function = "TownPirate_battle";
		break;
		
		case "SantLous_town_pay":
            dialog.text = "��� � ������! ������, ��� ���� ��������� �� �����������. �� ������, � �������, �� ������ �� ������ ������ ����� ���������.";
			link.l1 = "�� ����. �� ����� ������ ��� ���������. ������...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			pchar.GenQuest.Piratekill = 0;
		break;
	}
}


