// ���������� �������, ����� ���������� � ������������ �����, ��������� �������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sLoc;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;
    
// ============================================================================
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
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= ���� angry ===================================
// ============================================================================
	switch(Dialog.CurrentNode)
	{
		case "First time":
            NextDiag.TempNode = "First time";
            if (CheckAttribute(npchar, "Sp5LaVegaAttackDone"))
            {

            	if (NPChar.quest.meeting == "0")
				{
					dialog.Text = TimeGreeting() + "! � "+ GetFullName(NPChar) + ", ����� ��������� � ���� ����. � ���������, �������� � ������� ������� ����� �������� ������, �� ������ �� ��� ��� ��������� ������� ������ �� �����.";
					Link.l1 = "���"+ GetSexPhrase("","�") +" ����������. � ������� " + GetFullName(Pchar) + ". ��� ��� ����.";
					Link.l1.go = "exit";
					NPChar.quest.meeting = "1";
				}
				else
				{
					dialog.Text = TimeGreeting() + ". � �����, ����� ����� ���, ����� �������������� ���������� ������� �������, ���� ������� ������ �������� �������.";
					Link.l1 = "�� ���� ������.";
					Link.l1.go = "exit";
				}
            }
            else
            {
				dialog.text = NPCStringReactionRepeat("� ���� �� ��� ����? ���? ����� "+ GetSexPhrase("��������� ������!","������� �� ��������� ����.") +"",
	                         "�, �������, ���� ���������...", "���� � ��������� � ����, �� �� ����������� ��������� ����!",
	                         "��, �� �� �� � ���� "+ GetSexPhrase("�������, ��� ���","�����, ������") +"...", "repeat", 30, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("��� �����.",
	                                               "��, " + npchar.name + ", ���������� ����.",
	                                               "������, " + npchar.name + "...",
	                                               "��, ��...", npchar, Dialog.CurrentNode);
				link.l1.go = "exit";
			}
					if (npchar.city == sti(pchar.HeroParam.Location))
					{
						if(!CheckAttribute(PChar, "questTemp.pirateStartQuest"))
						{
							link.l2 = "����� ����� ��������� ��� ���� ��������?";
							link.l2.go = "pirateStartQuest";
						}
						else
						{
							if(pchar.questTemp.pirateStartQuest == "3" && !CheckAttribute(PChar, "questTemp.pirateStartQuest.many"))
							{
								link.l2 = "� ���"+ GetSexPhrase("��","��") +" �� ����, �� ��� ����� ������ - 30 000 ����, ����� �������� ����� �� ����.";
								link.l2.go = "pirateStartQuest_many";	
							}
							if(pchar.questTemp.pirateStartQuest == "3" && GetCharacterItem(pchar, "letter_open") > 0)
							{
								link.l2 = "��������, ��� �� ������ � ���"+ GetSexPhrase("��","��") +" �� ����� ������ �� ���������������.";
								link.l2.go = "pirateStartQuest_info_1";	
							}
							if(pchar.questTemp.pirateStartQuest == "5")
							{
								link.l2 = "���� �������. ������ ���� ������ �� ����� �������� ���������� � �������� �������.";
								link.l2.go = "pirateStartQuest_final";	
							}
						}
					}
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		//zagolski. ��������� ����� �� ������ ===================================
		case "pirateStartQuest":
			dialog.text = "��� �� � �� ���� �� ������?";
			link.l1 = "";
			link.l1.go = "pirateStartQuest_0";
		break;

		case "pirateStartQuest_0":
	                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_6.wav");
			dialog.text = "";
			link.l1 = "� ��� ����������� � ��������������� �������!";
			link.l1.go = "pirateStartQuest_01";
		break;

		case "pirateStartQuest_01":
	                                PlaySound("VOICE\Russian\gotica\GG\DIEBESWERK_1.wav");
			dialog.text = "��... �������, ��������� - ��������? � ��� ���� ����� ������, ��� �� �� ��� �������"+ GetSexPhrase("��","���") +". ��� ��� ��� ����� ������� �� �������. ���������� ���-��� ��������� � �������� ���������, � ���� ����� ��� �����, ��� �����������. ����� ����� �� ������, �� ���-��� ���������.";
			link.l1 = "��� � ������. � ��� �� ����?";
			link.l1.go = "pirateStartQuest_1";
			link.l2 = "������, �� ������� � ��������� �� ����. ������...";
			link.l2.go = "exit";
			pchar.questTemp.pirateStartQuest = "0";
		break;

		case "pirateStartQuest_1":
			dialog.text = "� ���� � ��������� - � ����� ����� ���������� � � ��������� ����� '������' � �������� 200 �����, ����� ������� �� ������ ���������� �� ��������� ���������. ��� � ����� ��������� �����, � �������� ����������, � ��� ����� ��� ��������, ��� ��� ����� ������ � ��������� �������. ��!.. ������� � ���� �� ��������. � ������� ��������� ���������� ������� ������� � ������, ��� ����� ��� ���������� � ������ ����� - ���� � ������, �� ��� ������ � �����.";
			link.l1 = "� ���? � ����"+ GetSexPhrase("��","��") +" � ��������� ��� ��������� 200 �����, ���� �� �� ������� �������? � ��� ��� �� �������?";
			link.l1.go = "pirateStartQuest_2";
		break;
		case "pirateStartQuest_2":
			dialog.text = "���, �������. ����� � ����� �� ������? ������� � �� ����� � ����� ������. �� ��� ����� ��������������, ��� ����, ������� ��� ����������� - ��� � ���� ��� ������. � �� ������ ������� ���, ��� ��������� ��� ����� ������, � �������� ���� 10 000 ����. ��������� ��� ������. �� ���, ��������?";
			link.l1 = "������! � ��� ��� ����� ����? ���� �����-�� �����������?";
			link.l1.go = "pirateStartQuest_3";
			link.l2 = "���. ������ ��������� ����, ��������� ��� � ����� �� 10 000 - ������, �� ��������.";
			link.l2.go = "exit";
		break;
		case "pirateStartQuest_3":
			dialog.text = "���� �� � ���� ��� ���� �����, � �������� �� � ��� ����� �����. ��� �� ��� � ���� ������ ��������� �� �����. �� ���� ������ ���������� ������ - ��� ��� ������ � ����� '������' � � ���� ���������? �� ����� ��� ������ � ��� ��������. ��������?";
			link.l1 = "";
			link.l1.go = "pirateStartQuest_4";

			pchar.questTemp.pirateStartQuest = "1";
			pchar.questTemp.pirateStartQuest.City = npchar.city;
			pchar.questTemp.pirateStartQuest.Areal = GetArealByCityName(pchar.questTemp.pirateStartQuest.City);
			pchar.questTemp.pirateStartQuest.Name = GetFullName(npchar);

			AddQuestRecord("pSQ", "1");
			AddQuestUserData("pSQ", "sCity", XI_ConvertString("Colony" + pchar.questTemp.pirateStartQuest.City + "Gen"));
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);
		break;

		case "pirateStartQuest_4":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_2.wav");
			dialog.text = "";
			link.l1 = "�... ���� ���-�� �������������� ����������.";
			link.l1.go = "pirateStartQuest_04";
		break;
		case "pirateStartQuest_04":
			dialog.text = "���! ��� ��� � ���. ������� ���� ��������� ����������� � ������� ����� - � ���� ���� �� �������. ��� ����� ����������, � ������ - ��� ������ �� �������. ������ �� ���������, ������ ����� �� ���� �� ���� ������� ����� �� ������? ���� � �� ������, ��� ������� ���������� - ����������� ���� �������. � ��� ����� ����� �� �������...";
			link.l1 = "�������... ������, ����� ����������� ���� � �� ��������� �����. ����������� �� ������.";
			link.l1.go = "pirateStartQuest_05";
		break;

		case "pirateStartQuest_05":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
			dialog.text = "";
			link.l1 = "�� ����� � �������!";
			link.l1.go = "exit";
		break;

		case "pirateStartQuest_many":
			dialog.text = "�������� �����, ��������? ��� ������� �����... ���� ���� ������ 5000 ����, ������ � ���� ������ ���. �� ���� ��������� ������� � ���� - ����� � ������ �� ��������� ������! �� ���� ����� ����� �� �������.";
			link.l1 = "����� ���� �����...";
			link.l1.go = "pirateStartQuest_many_1";
		break;
		case "pirateStartQuest_many_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
			dialog.text = "���, �����. ��� ���������� ������.";
			link.l1 = "��� ����� � �������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 5000);
			pchar.questTemp.pirateStartQuest.many = "";
		break;

		//------------------------------------
		case "pirateStartQuest_info_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_22.wav");
			dialog.text = "��! �������� �������! � ��� ������, ��� �� � ���� ����������. �� ��� ������ ������ ���������� ����������.";
			link.l1 = "� ������ ���� ��������"+ GetSexPhrase("","�") +". ���� �������� ���� ������ �����.";
			link.l1.go = "pirateStartQuest_info_2";
			TakeItemFromCharacter(pchar, "letter_open");
		break;
		case "pirateStartQuest_info_2":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			dialog.text = "�������, ��� ��������� �������. �� �� �� �����, � ���� �������� ���� ��� ���� ����\n������� - ��� ������� �� ������� ������� ����, ������� ����� �� ���������� ������� '�������'. � ������, ��� ������ ���� � ���� ����������, ���� �� � �� �����. ��� ������� ������ � ��������� �������, ���� ������ - ��������� ����� � �������� �������. � ������ ��� �� ���� �� ������"+ GetSexPhrase("","�") +", ������� � ������ ���� �������� ��� ���� ����. ������� 15 000 ����. ������"+ GetSexPhrase("��","��") +"?";
			link.l1 = "������! ������, ��� ��������� ������ ���� ��� ��������.";
			link.l1.go = "pirateStartQuest_info_3";
			link.l2 = "������ ���, ������� ��� � ��� �����������... �� � �������. ������, �� � ���.";
			link.l2.go = "pirateStartQuest_info_noex";
			AddMoneyToCharacter(pchar, 10000);
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
		break;
		case "pirateStartQuest_info_noex":
 	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_54.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
		break;
		case "pirateStartQuest_info_3":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_4.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "4";

			AddQuestRecord("pSQ", "7");
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);

			pchar.quest.zpq_seaBattle.win_condition.l1 = "location";
			pchar.quest.zpq_seaBattle.win_condition.l1.location = pchar.questTemp.pirateStartQuest.Areal;
			pchar.quest.zpq_seaBattle.function = "pirateStartQuest_seaBattle";
		break;

		case "pirateStartQuest_final":
 	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_20.wav");
			dialog.text = "";
			link.l1 = "�� ������� ��, ��� ����� �������!";
			link.l1.go = "pirateStartQuest_final_1";
		break;

		case "pirateStartQuest_final_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			dialog.text = "�����-�����. ��� ���� ��������� ��� � ��� �������� ���, ��� �� ������� �������"+ GetSexPhrase("��","���") +". �� ��� �, ���� ���� �� �������� ������"+ GetSexPhrase("","�") +", ��� ��������� ������� � 15 000 ����. � ������� ����, ������� �� ��� �����"+ GetSexPhrase("","��") +". �� � ���, ���� �� ���������� � ������ ������ ������� � �� ����, � ����� � ���� ������������ � ����� ��������.";
			link.l1 = "��� � �������, �������, ���"+ GetSexPhrase(" ���","� ����") +" ������! ��� � ��� ������ � ������� � ����. �� ������� �����!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 15000);
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
			group_DeleteGroup("pirateStartQuest_Smuggler_group");
		pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
			//pchar.questTemp.Mtraxx = "to_lavega";
			//pchar.questTemp.Saga = "pirate_line";
		break;

		//*********************������� �� *********************

        case "GothicLee6_talk":
            dialog.text = "��� �� ���"+ GetSexPhrase("��","��") +" � ��� ���� �����?";
            link.l1 = "� ������� " + GetFullName(pchar) + ". � ����� ��� ������. � ���� ��������� �������� ����� �� �������...";
            link.l1.go = "Gothic_6_1";
        break;
        case "Gothic_6_1":
            dialog.text = "��� �� �����? ������ �����, �� ���� ��� ��� ��������!";
            link.l1 = "������, ����������. ������ �� ���� ��������� - ������ ������� ��������� �� ���������� � ����� ���������� � ����� ���� ��������� ��������.";
            link.l1.go = "Gothic_6_2";
        break;
        case "Gothic_6_2":
            dialog.text = "�� � ���?";
            link.l1 = "��� �����, ����� �� �� ���������� � ���� ��������.";
            link.l1.go = "Gothic_6_3";
        break;
        case "Gothic_6_3":
            dialog.text = "���, ��� �� �������� ���� �������� �� ���������� � �, �������, ��������� �� ���� �����������. �� ���� �������� ���-��� ������� ��� ����.";
            link.l1 = "��� ������?";
            link.l1.go = "Gothic_6_4";
        break;
        case "Gothic_6_4":
            dialog.text = "�� ����, ������"+ GetSexPhrase("","�") +" �� �� � ���� ��������... ��, � �����, ���� � ���������: ����� ���������, ������� �����, ������� �������� �� ����, �� ��������, ��� ����, ��� �����, ������ �� ���� ���� ���������� ������, � ����� ������� �������, ������ ��� �� ����. � ����� ���� ��� � ������, � � ������� ����� ���� �������� ���� �����������. � �����, � ���� ����� ��� ������� ������ ���.";
            link.l1 = "� ��� �� �����������?";
            link.l1.go = "Gothic_6_5";
        break;
        case "Gothic_6_5":
            dialog.text = "���������, ��� ��� ���� ������� ��� ��� ���������. ���� ������ �������� ���� �� ���������, ��, �������, ��������� � ���� �����. ��, � ���� �� ������� ��������� ���������, ������������, ��� �� � ������� ��� ���������, � ������� ���� �������� - ���� ������. ������ ������� ��� ����������������, ��� ��� � ����������� � ������� ��������� �� ����.";
            link.l1 = "��� �, ������ �� ������. ���������� ������ ��������, ������������� ����. ��� �������������� �������?";
            link.l1.go = "Gothic_6_6";
        break;
        case "Gothic_6_6":
            dialog.text = "�������� � ���������� �������� ������, ��� ����� ��� ������� ������.";
            link.l1 = "�� ��� ��, � ��� �����"+ GetSexPhrase("","�") +". ���� �����������, � �� ���� ������ �� ������������ �� ����� �����������.";
            link.l1.go = "Gothic_6_7";
        break;
        case "Gothic_6_7":
            dialog.text = "����������...";
            link.l1 = "�������������!";
            link.l1.go = "exit";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "6");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("��","��"));
			NextDiag.TempNode = "Gothic_6_Result";
			// ==> ��������� ����� ������� ���� ����� - ��� ��� �����.
			LocatorReloadEnterDisable("PortRoyal_tavern", "reload2_back", false);
			LAi_LocationFightDisable(&Locations[FindLocation("PortRoyal_tavern_upstairs")], false);
            ref sld = GetCharacter(NPC_GenerateCharacter("CaptainGay", "mercen_12", "man", "man", 40, PIRATE, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 40, 100, 90, "newblade12", "pistol4", "bullet", 150);
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_2.c";
        	sld.name 	= "�������";
        	sld.lastname 	= "�����";
			sld.items.ShipsJournal = 1;
			sld.money = 65720;
			sld.items.potion4 = 4;
			sld.items.potionrum = 1;
			sld.items.potionwine = 2;
			sld.items.sculMa2 = 1;
			sld.items.jewelry17 = 30;
			sld.items.jewelry18 = 15;
			sld.SaveItemsForDead = true; // ��������� �� ����� ����
			sld.DontClearDead = true; // �� ������� ���� ����� 200�
			LAi_NoRebirthEnable(sld);
			LAi_SetLoginTime(sld, 0.0, 24.0);
			LAi_SetStayType(sld); 
			ChangeCharacterAddressGroup(sld, "PortRoyal_tavern_upstairs", "goto", "goto1");
		break;
        case "Gothic_6_Result":
            dialog.text = "��, ��� ������, �������? ��������"+ GetSexPhrase("","�") +" ������� ������ ����� �������� ������?";
			if (CheckCharacterItem(pchar, "ShipsJournal"))
			{
				link.l1 = "�������� ���, � ��� �������, ��� ������ �������. ����� ���������� � ��������. � ��� ������ - �����, ��� ��.";
				link.l1.go = "Gothic_6_8";
			}
			else
			{
				link.l1 = "��� ���... �� � ������� ��� ����, ��� �����...";
				link.l1.go = "exit";
			}
        break;
        case "Gothic_6_8":
            dialog.text = "���-���... ��, � �����������, ��� ���� ������ �� ���� ������� �������� ���� �������. �� ��� �, ��� �������� � ���������� � ��������� ������ �������, � ������, ������ �� ���� ������������� �� �����. � �� ������ ��������� ���������� - �� � ������� �� �����!";
            link.l1 = "�������, ����������. ��, � ������ ��� ����, ������...";
            link.l1.go = "exit";
			pchar.questTemp.Count = makeint(pchar.questTemp.Count)+1;
			NextDiag.TempNode = "First time";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "7");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("","�"));
            TakeItemFromCharacter(pchar, "ShipsJournal");
        break;

			//������ �����-�������
		case "Mushkett":
			dialog.text = "" + GetFullName(pchar) + ", ����� �������? ����� ��������� � ������� ����������, �������� - �������� � ����� �����!!!";
			link.l1 = "������, �������, ���� �� � ��� �� ������� ����� '������'? ����� ����, ����� ������ ����� �� ������ '������', ��� ����� ��������� � ����� ��������� �������� � ���� � ����?";
			link.l1.go = "Mushket_01";
		break;

		case "Mushket_01":
			dialog.text = "�-�, � ���� ���� �������� �� ����� ��������. ��� ����� �������� ������� - ����� ������� ����, �������, ������ �� ����������. ���������, ��� ��� ��� ����� ������� �� ����. � ����� �� ���� �����������?";
			link.l1 = "�� ���� ���� ����... ��� �� ����� ����� �������.";
			link.l1.go = "Mushket_1";
			DeleteAttribute(pchar, "questTemp.mushkett2x2");
		break;

		case "Mushket_1":
			dialog.text = "� ��� �� �� ��� �������? �� ��� �� ����, �� �� ���� �� ��������, ������ ���� �� ������, � ��������� ����� ��� �� ������� - ���� �������� �� ���������, � � ����� ������� ��� �� �������. ���, ��� ���, �������, ����, ���� � ������ ���������, �� ��������� �� ����� - �� ����� �� �������.";
			link.l1 = "�� ��... �����, ����������� ���?";
			link.l1.go = "Mushket_2";
		break;
		case "Mushket_2":
			dialog.text = "���� ���� �������, ������� � ���� �������� � ���� �����. �� ���-�� � ��� �� ��������� - �� �� ������ ��� �� ������ �������, �� �� ��������. ��� ��� - ������ ���� �����, �����, ��������, � �� ������� ��.\n���� ����� ������ ������� � ����� ����� ������, ������� ������� �����, ��� ������ - ���. �� ����� ����� ����� �������. �� �, ����� ���� - ��� ���� ���� � ����, �� ��� �� � ��� �� ��������. ������ ���� �������"+ GetSexPhrase("��","��") +" - �� ������������� ����...";
			link.l1 = "����. �� ��� �, ������� ����, ����������.";
			link.l1.go = "exit";
			pchar.questTemp.mushkett2x2_stid = true;
			SaveCurrentQuestDateParam("questTemp.mushkett2x2_stid");
			AddQuestRecord("SeekDoubleMushket", "2_2");			
		break;



		//********************* ����� ������� *********************


 		case "Lets_go_bussines":
			dialog.text = "���, ��� � �� �����. ����� ������ ���� ������� � �� �������?";
			link.l1 = "� �������� � ���� � ��������. �� �������� �� �� � ���������� �������������� � ������ ������?";
			link.l1.go = "Gothic_RevengeCorsair_5";
  		break;

 		case "Gothic_RevengeCorsair_5":
            if (GetCompanionQuantity(pchar) < 8) 
            {
    			dialog.text = "������� �� ��������. � ����� ��������� ����������.";
    			link.l1 = "����� ������!";
    			link.l1.go = "Gothic_RevengeCorsair_6";
            }
            else
            {
    			dialog.text = "� ����� �� ����� ������ ��������. ���� ��� � � ����� � ����, �� ��� ������ �� ����� ������ ������ ���� �����. ��� ��� ��� ���� �� ���� ���.";
    			link.l1 = "�� ��� �, ��� ������, ���� ������.";
    			link.l1.go = "exit";
                NextDiag.TempNode = "First time";
            }
            
  		break;

 		case "Gothic_RevengeCorsair_6":
	        AddQuestRecord("RevengeCorsair", "14");
                LAi_SetActorType(NPChar);
                LAi_ActorSetStayMode(NPChar);
                ChangeCharacterAddressGroup(NPChar, "LeFransua_townhall", "goto", "goto6");
                CharacterIntoCompanionAndGoOut(pchar, npchar, "reload", "reload1", 6, false);
                Fantom_SetBalls(npchar, "pirate");
                npchar.CompanionEnemyEnable = false;  // ��� ������ ��� ��������
                pchar.questTemp.CompanionQuantity = makeint(sti(pchar.questTemp.CompanionQuantity) + 1);
                pchar.questTemp.CompanionQuantity.LeFransua_Mayor = true;
                NextDiag.TempNode = "Have_hot_bussines";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;

		//���������� �������
		npchar = characterFromId("LeFransua_Mayor");
		FantomMakeCoolSailor(npchar, SHIP_LSHIP_SPA, "׸���� ����������", CANNON_TYPE_CULVERINE_LBS36, 90, 90, 90);
	SetShipSailsFromFile(npchar, "ships/parus_sail_whole_white_pirate_6.tga");
 npchar.FaceId = 952;
SetSelfSkill(npchar, 85, 95, 95, 80, 95);
SetShipSkill(npchar, 95, 95, 95, 95, 100, 95, 100, 95, 95);
npchar.rank = 30+MOD_SKILL_ENEMY_RATE;
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
npchar.CompanionEnemyEnable = false;  // ��� ������ ��� ��������
		SetCharacterRemovable(npchar, false);
		npchar.Ship.Cargo.Goods.Food = 1000;
		LAi_SetImmortal(npchar, false);
                LAi_NoRebirthDisable(npchar);
		LAi_RebirthOldName(npchar);
		SetCompanionIndex(pchar, -1, sti(npchar.index));

  		break;


	 	case "Have_hot_bussines":   // ���� ������� ����� ��������� ��� ����������, �� ����, ������ ��. �� �� ������ ������.
			dialog.text = "�� ������ ������������, ����� �� ����.";
			link.l1 = "�� ��� ������.";
			link.l1.go = "exit";
            NextDiag.TempNode = "Have_hot_bussines";
  		break;

	 	case "Gold_found_in_fort":    // ���� ��������� � ����� ������
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.LeFransua_Mayor") && !IsCompanion(characterFromID("LeFransua_Mayor")))
    		{
            	dialog.text = "���������, ��� ������ ����� �� ���! � ������� ������� � ������ �������� �������. ���� ������� ������..."+
                              " ��, ��� ����, ��� ���������� � ����� ����� ������������, � �������� ��� ����� ������ ������. �� ����� ������ � ���� ������� ��� �������, �������� ������ ���. �� - ��������� ������"+ GetSexPhrase("",", ���� � �������") +".";
            }
            else
            {
            	dialog.text = "����� ������ �� ��������, ���� ������! �� ����� ������ � ���� ������� ��� �������, �������� ������ ���. �� - ��������� ������"+ GetSexPhrase("",", ���� � �������") +".";
            }
			link.l1 = "�������. ���"+ GetSexPhrase("","�") +" ������� ��� �� ����.";
			link.l1.go = "Gothic_RevengeCorsair_7";
        break;

	 	case "Gothic_RevengeCorsair_7":
			dialog.text = "� ����� � ���� �� ���������. �� ������ ������� ����� ���� ���.";
			link.l1 = "����� ��������, ����������. ��� ����������!";
			link.l1.go = "Gothic_RevengeCorsair_8";
        break;
        
	 	case "Gothic_RevengeCorsair_8":
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
        break;
				
 		
// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ����� ����!");
			link.l1 = "��-��-��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ���������� ����� 30 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "���� �� ����� ��������� ����, ������� ���.";
        			link.l1 = "� �����"+ GetSexPhrase("","�") +", ����������, ������ �� ����.";
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
		// <<<<<<<<<<<<============= ���� ��� angry =============================
	}
}

void SetMushketCapitainInWorld()
{

}


