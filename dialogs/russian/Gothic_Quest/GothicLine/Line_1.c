// ���������� ���� �1 �� ���. �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
    float locx, locy, locz;
	string sTemp, attrName;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    switch (Dialog.CurrentNode)
    {
        case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
            link.l1.go = "exit";

//>>>>>>>>>>>>========= ������� �������� �� ���������� =====================

			if (npchar.id == "DeLeiva")// �����, ���� � ����� ����� ����
            {
    			dialog.text = "�� ��� ��, ��� �� � ��������� ������ �����. ����� ���������� �� ����, "+ GetSexPhrase("�����","�����������") +". ������� ����� ��� ��� ������� - ������ ��������� �����!";
				link.l1 = "��� ��� �������! � � ��� ����?!";
    			link.l1.go = "Gothic_1";
            }
			if (npchar.id == "DeLeivaBrother_1" || npchar.id == "DeLeivaBrother_2")// �����, ������ �� �����
            {
    			dialog.text = "��� ���� ����� �����?";
    			link.l1 = "";
    			link.l1.go = "Gothic_2_2";
            }

               // ����� ������, ����� ���� �������
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_toAaron")
            {
    			dialog.text = "��� ������ ���, "+ GetSexPhrase("���� ���","" + pchar.name + "") +". ����� ����������?";
    			link.l1 = "������, � ��������������"+ GetSexPhrase("","�") +" � ���� ������������ ��������� ��.";
    			link.l1.go = "Gothic_3_1";
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_toBermudes")
            {
    			dialog.text = "� ����������� ������ ������ ������� � �������.";
    			link.l1 = "� ��������� ����, ���������� �����...";
    			link.l1.go = "exit";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_DeGrafIsDead")
            {
    			dialog.text = "� ����������� ������ ������ ������� � �������.";
    			link.l1 = "������, ��� ������� ��������, ��� �������� ������� ������������ �����. ����� ����������� ����� ����� �� ����. ������, �����, ��� ��� �� �����. ����� � ������"+ GetSexPhrase("��","���") +" �� ���� � ������� ���������, �� ��� ��� � ����� ������ ��������� ��������. ��� �� ������� ������ ��� ������, ��� ����� ������ ������ � ��������. �����, ��� ��� ���, ����� ����� ������ ������ ����������.";
    			link.l1.go = "Gothic_3_12";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_DeGrafDieHard")
            {
    			dialog.text = "� ����������� ������ ������ ������� � �������.";
    			link.l1 = "������, ��� ������� ��������, ��� �������� ������� ������������ �����. ����� ����������� ����� ����� �� ����. ����� � ���"+ GetSexPhrase("��","��") +" ��� ���� ���������, �� ��� ��� � ����� ������ ��������� ��������. � �� ����"+ GetSexPhrase("","��") +" ����� ������ �� �����, ���� ���� ������� �������. ��� �������� �������� ���� ���.";
    			link.l1.go = "Gothic_3_12";
            }

            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_BadResult")
            {
    			dialog.text = "��� ����� ������ ��� �������. ������������� � ��.";
    			link.l1 = "������, ������.";
    			link.l1.go = "exit";
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_WeWon")
            {
    			dialog.text = "� ����������� ������ ������ ������� � �������.";
    			link.l1 = "��� ������ �� ������� ��������. � ��������"+ GetSexPhrase("","�") +" ��������� ������.";
    			link.l1.go = "Gothic_3_12";
    			link.l2 = "��� ���, ������, ����� ��������... �� ����� �� ���"+ GetSexPhrase("��","��") +" ����... ������ �������� ������...";
    			link.l2.go = "exit";
			}			
			if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_IHaveMap")
            {
                dialog.text = "� ����������� ������ ������ ������� � �������.";
    			link.l1 = "��� ������ �� ������� ��������. � ��������"+ GetSexPhrase("","�") +" ��������� ������.";
    			link.l1.go = "Gothic_3_12";
				if (CheckCharacterItem(pchar, "Bible"))
				{
           			link.l2 = "��� ������� ������ �����-�� �����. �� ����, �� �� ���, ��� �� �����, �� ����� �� ������� ����� ����.";
        			link.l2.go = "Gothic_3_13";
                }
                else
                {
        			link.l2 = "� ���� �� �����"+ GetSexPhrase("","�") +" ��������� �����, �� � �������� � ������. ��� ����� ���������...";
        			link.l2.go = "exit";
                }
            }
            if (npchar.id == "Chumakeiro" && pchar.questTemp.GothicLee == "SeekBible_GoodResult")
            {
    			dialog.text = "� � ��� ���� ������ ������� �� ���...";
    			link.l1 = "���, �������...";
    			link.l1.go = "exit";
            }

			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "ThreeCorsairs_toBonrepo") //�����. ������ ������� � ���-����
            {
    			dialog.text = "� ��� ���� �����?..";
    			link.l1 = "������� " + GetFullName(pchar) + ". � ������"+ GetSexPhrase("","�") +" � ��� �� ������������ �������� ��.";
    			link.l1.go = "Gothic_6_1";
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "ThreeCorsairs_toSeek") 
            {
    			dialog.text = "����, ��� ������� ������������ ���� ������?";
    			if (sti(pchar.questTemp.Count) == 3)
				{
					link.l1 = "��� ���������. ��� ���� �� ����� ����������� � ����� �� ������� ������.";
    				link.l1.go = "Gothic_6_9";
				}
				else
				{
					link.l1 = "���� ��� �� ������� ����������� �� �����, �� � ������� ��� ����.";
    				link.l1.go = "exit";
				}
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "EndWar_toBorepo")
            {
    			dialog.text = "�-�-�, �����"+ GetSexPhrase("","����") +"! ��� ��� ������. ����� ������ - � ���� ���...";
    			link.l1 = "���"+ GetSexPhrase("","�") +" ��� ������ ��� ��, ������.";
    			link.l1.go = "Gothic_12_1";
            }
			if (npchar.id == "Bonrepo" && pchar.questTemp.GothicLee == "EndOfQuestLine")
            {
    			dialog.text = "���, �����"+ GetSexPhrase("","����") +", � ��� ������ �� ����������. ��������...";
    			link.l1 = "��������, ������...";
    			link.l1.go = "exit";
            }

		break;
//<<<<<<<<<<<<===== ������� �������� �� ���������� =====================
        case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;

//********************************* ����� � ����� �� �����. **********************************
 		case "Gothic_1":
			dialog.text = "���, �� ��� ��� ��������... � ����� ��� ������� ���� ����������� "+ GetSexPhrase("�������","�����-�� ����������� �����") +", � ����� ����������: '� � ��� ����?!'\n"+
				          "�� ������� �� ���� �����"+ GetSexPhrase("�","��") +"! ��� ���� �������, � ����� � ��� ��� ������� ������ ��.";
			link.l1 = "��� ����... �� ��� ��, ������� ��� ���� ��� ����, ����� �������� ��� ������, ������� �� ��������� ��� �������.";
    		link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			dialog.text = "������ �������!";
			link.l1 = "������, �������...";
    		link.l1.go = "Gothic_3";
		break;
 		case "Gothic_3":
			LAi_LocationFightDisable(loadedLocation, false); 
			SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			LAi_SetPlayerType(pchar);
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
            DoQuestFunctionDelay("GothicLee_Havana_FightInHouse", 11.0);
		break;

//********************************* ����� � ��������. **********************************

 		case "Gothic_2_2":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_1013_BANDIT_FROMCAVALORN_01_01.wav");
			dialog.text = "��� �����?";
			link.l1 = "";
    		link.l1.go = "Gothic_2_3";
		break;
 		case "Gothic_2_3":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_10008_BANDIT_SOUP_15_00.wav");
			dialog.text = "";
			link.l1 = "�� �������?";
    		link.l1.go = "Gothic_2_4";
		break;
 		case "Gothic_2_4":
	                PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_ADDON_10008_BANDIT_SOUP_01_01.wav");
			dialog.text = "�� �� ������ ��� ����� - ��� � ���� �� ������ ������ ��� ��� ������. ����� ���� �� ����� ����?";
			link.l1 = "�� ���� �� ����, �� ���������"+ GetSexPhrase("","�") +" ��, �������� ��...";
    		link.l1.go = "Gothic_2_5";
		break;
 		case "Gothic_2_5":
			dialog.text = "��������. � ��� ���� ����� �� ���?";
			link.l1 = "�������, �� �� �� ������������ ���� ���� �������� �� �����? � ��� �����"+ GetSexPhrase("","�") +", �� ��������� ��������� �� ���� ����?";
    		link.l1.go = "Gothic_2_6";
		break;
 		case "Gothic_2_6":
			dialog.text = "���������� ������, ��� ��. ����� � ������ ���� ���� ������� ����.";
			link.l1 = "� "+ GetSexPhrase("���","��") +", ��� ��������"+ GetSexPhrase("","�") +" ���������� ���� ���� �� ��� ����. ��� � ���� ��� ���� ��, ����� �� ��������.";
    		link.l1.go = "Gothic_2_7";
		break;
 		case "Gothic_2_7":
			dialog.text = "����, ����� ������� � ����! ������� �������, ����, �������� ����� ��� ������ ����, � �� ����� ������������ �����.";
			link.l1 = "� ��� �� �?!";
    		link.l1.go = "Gothic_2_8";
		break;
 		case "Gothic_2_8":
			dialog.text = "� ���� ��� ���... ������, ����, �������� � "+ GetSexPhrase("���� ���������","���� ������") +"!";
			link.l1 = "� � ����� ���������� ����� ����� �� ������"+ GetSexPhrase("��","��") +". � ����! ��, ������� ������...";
    		link.l1.go = "Gothic_2_9";
		break;
 		case "Gothic_2_9":
			LAi_LocationDisableOfficersGen("Mayak10", false); //�������� �������
			pchar.questTemp.GothicLee = "GothicLeeAnnaHant_GoodWork";
			LAi_LocationFightDisable(&Locations[FindLocation("Mayak10")], false); 			
			LAi_group_Delete("EnemyFight");
			for (i=1; i<=2; i++)
            {				
				LAi_group_MoveCharacter(characterFromId("DeLeivaBrother_"+i), "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddQuestRecord("GothicLee_2_KillAnnaHanters", "4");
	                                          LocatorReloadEnterDisable("SantLous_townhall", "reload2", true);
		                     DoQuestCheckDelay("AnnaHant_GoodWork", 55.0);
			DialogExit();
		break;

//********************************* ������ ������. ����� �8 **********************************
        case "Gothic_3_1":
			dialog.text = "�-�-�, ��� ����� �������, ��� ������ �� ������ �������� ��� � �������. ��� ��� �������� ������ ��� � ����.";
			link.l1 = "� ����� ������� ���� ����? �� ������ ����������� �� ������...";
			link.l1.go = "Gothic_3_2";
		break;
        case "Gothic_3_2":
			dialog.text = "��� �����, "+ GetSexPhrase("���� ���","" + pchar.name + "") +"
. �� ������� �� �������.\n"+
                          "������ ������������ ������ �������, �������� �� ������ � ������� ����� �������� ��� �����, ��� ����� ������� ������. �� ��� ����� ������� ���������, � ������� ��� ������� ����� ����������� �������� �� ������������ ������ � ����� ���������� ���������� � ������� ���� ����� � ����� ������������ ��������. ���� ���� �� ��� ����� ���������.\n"+
                          "������ ��������"+ GetSexPhrase("����","���") +", ��, ��������, ������ ������ � ����� ������?";
			link.l1 = "��� � ���� �������, �� ��� �����...";
			link.l1.go = "Gothic_3_3";
		break;
        case "Gothic_3_3":
			dialog.text = "� ������ �� ��, ��� ���������� ������, �������� �� ������ �����������, �� �������� ����������������, ��� �������...";
			link.l1 = "��� ��� ��������?";
			link.l1.go = "Gothic_3_4";
		break;
        case "Gothic_3_4":
			dialog.text = "���� � ���, ��� ������ �� �������� ����� �� ����� ����������� ������. ������ ���������� ����� �������, ������ ��� �������� ������� ����������� �������������� ����� � ������������� ������������� ���������, ���� �������� ���� � ������ ������.\n"+
                          "��� �����-�� � ��������� ��������� ������� �����, ��� ���������� � �� ����� � ����� ������. ����� ���� � ������ ���������� ��� ��������, ���������, ��� ��������� ���� ����� ������������ ���� �����. ����� ��� �������� ��������� ����� �� ����� ������� ������, ��� � ����������� ������� ������������ ����, ����� �� ������� ��� ��� ���� �������� ��������.";
			link.l1 = "����� ���������. �� ����� ��� ��������� ����� � ����� �������?";
			link.l1.go = "Gothic_3_5";
		break;
        case "Gothic_3_5":
			dialog.text = "��������, "+ GetSexPhrase("���� ���","" + pchar.name + "") +", � ��� ��� ������ ����.\n"+
                          "����, ������ ���� �������� ������ � ���� ������������, ���� ��������� ��� ������� � �������, ��� �������� ��� ����� �� ���� ����� �� �������������� ���������. �� ������� ��� �������! �� ��������������� ����� �� ����� ��������� �������-����������� � ��� ������ �� ������ �������� ���������� ����������� ������ ���������!\n"+
                          "������� ���������� ����� �� ������� �����, �� ��������� ������������ ��� ��������� �� ������ ����. � ���������� ���� ���������� � ������������ ������� ������� �����, ��� ������ � ������� � ������ �� ���������� ��������� ��������� ���-�� �����, � ���������� ����������.";
			link.l1 = "� ����"+ GetSexPhrase("��","��") +" ����� ����� ��� ������?";
			link.l1.go = "Gothic_3_6";
		break;
        case "Gothic_3_6":
			dialog.text = "���, � ���� ��� �������� ������. �� ������ ����� ��������� �������.";
			link.l1 = "���� �� ����������� ����, �� ��� ����� ����������, � ���� ������ ������...";
			link.l1.go = "Gothic_3_7";
		break;
        case "Gothic_3_7":
			dialog.text = "������� ����, ������ ��� � ������� ������������� ����, ��� � �������� ��� � �������� ��.";
			link.l1 = "������ ��� �����������, �����.";
			link.l1.go = "Gothic_3_8";
		break;
        case "Gothic_3_8":
			dialog.text = "�� ���� ����� �����, ��� ���� �� ���������� ������� � ��������� � �������-����� ����������� ������� ������ ������������ �����, ���������� �� ����������� ��� �����.";
			link.l1 = "��, �� ���� ���� ����������, �� ��� �� ���������, ��� ����� ������������?";
			link.l1.go = "Gothic_3_9";
		break;
        case "Gothic_3_9":
			dialog.text = "�� ������������ �������� �� �����, "+ GetSexPhrase("���� ���","" + pchar.name + "") +".";
			link.l1 = "�������... ������, ��� ��� ����� ������?";
			link.l1.go = "Gothic_3_10";
		break;
        case "Gothic_3_10":
			dialog.text = "� �� ����.";
			link.l1 = "��� ���... �� ��� ��, �������, � ����� ������ � ��� ���, � ��� ��� ����� ������.";
			link.l1.go = "Gothic_3_11";
		break;
        case "Gothic_3_11":
			dialog.text = "� ������ � ���� ����������� �� ��� ���������. �����������, "+ GetSexPhrase("���� ���","" + pchar.name + "") +". � ������ ������ ������� ����� ����� �������.";
			link.l1 = "��� �������������� �������, ����������, ������� ��� ������. �� �������, �����, � ���������� ��������� � �������.";
			link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_toBermudes";
            AddQuestRecord("GothicLee_3_SeekBible", "2");
            QuestSetCurrentNode("Torus", "GothicLee3_quest");
		break;
        case "Gothic_3_12":
			dialog.text = "��� ����� � ����� �����... �� ��� ��, �� ��� ������ �� �����. ������������� ������� � ��.";
			link.l1 = "������, ������.";
			link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_BadResult";
            NPChar.LifeDay = 0;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
		break;
        case "Gothic_3_13":
			dialog.text = "���, ������� ���������... ��, ��� ������ ��, ��� �� ��������! �� ����� ��������� ��������� ������� ������! �������, ����� ����!!!";
			link.l1 = "����, � ������, � ������ �����. �����.";
			link.l1.go = "Gothic_3_14";
			TakeItemFromCharacter(pchar, "Bible");
		break;
        case "Gothic_3_14":
			dialog.text = GetFullName(pchar) + ", � ������ ���, ��� ������� ���� ����� ����� �������. �� ������� �� ������� ���� ������?";
			link.l1 = "��, � ���� ���� ��������� �������, � ��������"+ GetSexPhrase("","�") +" 235 ����� �� �������. ���, ��� �� ���������� ��� ����� ������ �����, � ����� �������� ��������.";
			link.l1.go = "Gothic_3_15";
		break;
        case "Gothic_3_15":
			dialog.text = "����� ����� � �������� ��� ���� �������. � ������������ �������� ����� ������ �� ��������� ����, �������, ������, ����� ������...";
			link.l1 = "���, ������� - ��� �������, ���� ����� �������! � ��� ��� �� ��� ����� ����� ����������?";
			link.l1.go = "Gothic_3_16";
		break;
        case "Gothic_3_16":
			dialog.text = "������� ������������� ������������ �� ���� ����� - �������� �����. �� ����� ��� ������ � �����, � ����, � ���� ��������...";
			link.l1 = "�� ��� ��������? ���������, ��������� ��� ��� ���������� �� ��������� ����� ������������ �����. �� �� �����... ��, �������, �������� �������� ����� ��������, � � ������� ����� ����������� ������ - ������ ����. � ����� ������ � ������� ��� ��� ������ �������� ������������� �������� ��� ����� ����� �������� �����.";
			link.l1.go = "Gothic_3_17";
		break;
        case "Gothic_3_17":
			dialog.text = "��������, � �� ������ ��� �������!";
			link.l1 = "� ��� ����� ������ ����������. ��������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 1235000);
            pchar.questTemp.GothicLee = "SeekBible_GoodResult";
            AddQuestRecord("GothicLee_3_SeekBible", "10");
			AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("","�"));
            NPChar.LifeDay = 0;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
		break;

//********************************* ������ �������. ����� **********************************
 		case "Gothic_6_1":
			dialog.text = "���, �������-��! � � ��� ����� �����������. ������� �� ������� ��� � ��� ����� ��������. � �������, ��� �� ��������� ���������� ��� � ��� �������. � ������: ���, ��� �� ����� ��������, ������� �� ������ ����� ��������� ����-����, ����� ���.";
			link.l1 = "� ������������"+ GetSexPhrase("","�") +" �� ����...";
    		link.l1.go = "Gothic_6_2";
		break;
 		case "Gothic_6_2":
			dialog.text = "�����������! ����, � ����.\n"+
				          "������ � ����������� �������� ����� ������� ���������. ��������� ��������� �������� ����� ����� ������� � ����������, � ��� ������� ������-������ ������� XIV �������� ������������� ����� � ��������.";
			link.l1 = "��������, ������... ����� �����? �������������?!";
    		link.l1.go = "Gothic_6_3";
		break;
 		case "Gothic_6_3":
			dialog.text = "��... �� ��, ������ �� ����� �������� ������.\n"+
				          "������������� ����� - ��� ����� �� �������������� ����� �� ��������� ����������. ����� ��� �������, ����������, �������� ����� �������� � ���������, ����������� ������ ��� ��������� ������������. ��� ������ ����, ��������� ��������� ��� ��� ����� ��� ��������� �������� ��� ��������� ��������, ��������� � ��������� ����.\n"+
						  "��� ��������� ������� ����� �� � ������� ������� ��������� � ������� ����������, ��� ��� ���������� �������� ��������� �������� �� �� �������. ������� ������������ ����� ���-������ �������, �������, �� ������, ��� ���...";
			link.l1 = "����� ������� � ����"+ GetSexPhrase("��","��") +" ��� �������?";
    		link.l1.go = "Gothic_6_4";
		break;
 		case "Gothic_6_4":
			dialog.text = "��������� � ��������� �������� �� ����, ���� �������-���������� ������ ��� ������ ����� �� ������� ������������. � � ���� ����� ��� ����� ������������ ������ �� ������ ��������� ��������, ������� ��� � ��������� � ��������� ��������.\n"+
				          "�����, ��� ��� �� �������� �������� �� ��� �����, ����� ����: ����� ������ �� ������, ����� - � ��������� �� ��������, ���������� ������� � �� �������. ���� ������ � ����������� � ������ �� ��� � ������� �� � ���� ������ �� �������� �� ����������� ������� � ����. ��� ���� ������ ������� - ������, ��� ��� ������� �� �������!";
			link.l1 = "� ��� �� � ����"+ GetSexPhrase("��","��") +" ����� ��� ��������?";
    		link.l1.go = "Gothic_6_5";
		break;
 		case "Gothic_6_5":
			dialog.text = "���������, �� ���� �������. ��� ������������� ���, ��� �� �������� ������ � ����������� ��������! ���� �� ��� �������� � ���� ���� - �����, ������������, ������������ �� ���� ������? �������, �� ������ ����������, ��...";
			link.l1 = "�� ��� �����?";
    		link.l1.go = "Gothic_6_6";
		break;
 		case "Gothic_6_6":
			dialog.text = "����� ��� �������� ��������� ��� � ������. �� ����, "+ GetSexPhrase("��������","�������") +", ����� ���������"+ GetSexPhrase("��","������") +" ��������������� �����! � ������ �������� ���������� ���� �� ������� �� �����������.";
			link.l1 = "������� ���� ���� ���������, � ��� �� ���-�� ������!";
    		link.l1.go = "Gothic_6_Fight";
			link.l2 = "�� ��� �, ���� ������ �� ����� �������� ��� ���� ����, ��� � ����, � ������ ���!";
    		link.l2.go = "Gothic_6_7";
		break;

 		case "Gothic_6_Fight":
			CloseQuestHeader("GothicLee_6_ThreeCorsairs");
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
            for (i=1; i<=4; i++)
            {
                sld = GetCharacter(NPC_GenerateCharacter("Guard_"+i, "Guard_fra_"+(rand(7)+1), "man", "man", 30, FRANCE, 0, true, "soldier"));
				FantomMakeCoolFighter(sld, 30, 65, 50, BLADE_LONG, "pistol3", "bullet", 40);
            	LAi_SetWarriorType(sld);
                LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
               	ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
            }
			LAi_group_AttackGroup("FRANCE_CITIZENS", LAI_GROUP_PLAYER);
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(NPChar, "reload", "reload1", "none", "", "", "CanFightCurLocation", 10.0);
			NPChar.LifeDay = 0;
			pchar.questTemp.GothicLee = "QuestLineBreake";
			AddQuestRecord("Gothic_6_ThreeCorsairs", "2");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

 		case "Gothic_6_7":
			dialog.text = "��� ���������! ������� �� � ��� �� ��������. ����, � ��� ��� � �������� ���������.";
			link.l1 = "� ��� ������, ������.";
    		link.l1.go = "exit";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "3");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("","�"));
			pchar.questTemp.GothicLee = "ThreeCorsairs_toSeek";
			SaveCurrentQuestDateParam("questTemp");
            // ==>  �������� ������� �� ������� � ���� ���� ������� � �������
         QuestSetCurrentNode("Henry Morgan", "GothicLee6_talk");
            sld = characterFromID("Henry Morgan");
            LAi_SetLoginTime(sld, 0.0, 24.0);
            // ==>  ���� ���� ������� � ������� ���������� ��������
            QuestSetCurrentNode("LeFransua_Mayor", "GothicLee6_talk");
            // ==>  ���� ���� ������� � ������� ������
            QuestSetCurrentNode("Torus", "GothicLee6_talk");
            // ==>  ��������� ������� ��������� ��������, � ����� ������ == 3
            pchar.questTemp.Count = "0";
		break;

 		case "Gothic_6_9":
			dialog.text = "������ ��������, ��� ��� ���� ���� �� ����� ��������� ��������������� ���������, ������� � ����� ����-����. ��������, ������� ��� �������� ����������� � ��������� ������, ������ �� �������� ������ � �������������. �� �������, ��� ���� ���������� ���������� ��� "+ GetSexPhrase("��������� �����","����� ���������") +"! ����� ����, ��� ��, ����� �������!";
			link.l1 = "�-�... �... "+ GetSexPhrase("��������� �����","����� ���������") +"? � ��� ���� � �������, ������� � �����"+ GetSexPhrase("","��") +"?..";
    		link.l1.go = "Gothic_6_10";
		break;
 		case "Gothic_6_10":
			dialog.text = "��, ����� ������ ��������� �������! ��-��!\n"+
				          "��������, "+ GetSexPhrase("��������","�������") +", � ��� ��� ������� ������, ��� ���������� ������! � ��� ��� ����� � �������� ������ ������! � ������ �� ���� ��� �����������, ��� ���� ������� ��. �������, � ���� ��� ��� ����� �����-�� ������ ����... ��������.";
			link.l1 = "��������, ��������� �������...";
    		link.l1.go = "Gothic_6_11";
		break;
 		case "Gothic_6_11":
            ChangeCharacterAddressGroup(&characters[GetCharacterIndex("Henry Morgan")], "PortRoyal_houseS1", "sit", "sit2");//������� �� �����
                    sld = characterFromID("Henry Morgan");
	     LAi_SetHuberType(sld);
			pchar.questTemp.GothicLee = "ThreeCorsairs_backGovernor";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "8");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("���� ����������","����� ���������"));
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex1", GetSexPhrase("��","�"));
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex2", GetSexPhrase("��","��"));
            LAi_SetActorType(npchar);
            LAi_ActorGoToLocation(NPChar, "reload", "reload1", "none", "", "", "", 6.0);
			if (PChar.sex == "woman")
			{
			pchar.name = "��������� " + pchar.name;
			}
			else
			{
			pchar.name = "����� " + pchar.name;
			}
            DialogExit();
		break;

//********************************* ����� �����. ����� **********************************
 		case "Gothic_12_1":
			dialog.text = "����, ��� �� ��� ������, ������������� ����� � �������� ���������. ������� ���������!";
			link.l1 = "��, ������, ������������ �������.";
    		link.l1.go = "Gothic_12_2";
		break;
 		case "Gothic_12_2":
			dialog.text = "���� ������� ������� �� ����������� - � ��� ������ ����� ��� �������...";
			link.l1 = "������, ������ ������, ��� �� �������� ��������� ���� ������ ���� ������ ����� ��������.";
    		link.l1.go = "Gothic_12_3";
		break;
 		case "Gothic_12_3":
			dialog.text = "��� �� ������ � ����?";
			link.l1 = "� ������ � �������� ����������� ����� ������ � ���� �����. � �� ����� ������ �����"+ GetSexPhrase("","��") +" ����� ������ �������� � ��������� � �����"+ GetSexPhrase("","�") +" �� �������� �����������.";
    		link.l1.go = "Gothic_12_4";
		break;
 		case "Gothic_12_4":
			dialog.text = "����������, �� ����� ������"+ GetSexPhrase("����","���") +", � ��� ����� ����! ��� ����� ����?!";
			link.l1 = "��� ����� ��������� - ��� ������, ��� �����. �� � � ������ ������ - � �������...";
    		link.l1.go = "Gothic_12_5";
		break;
 		case "Gothic_12_5":
			dialog.text = "�����"+ GetSexPhrase("","����") +", �� ������� �� ���� ������, � �� �� ������ � ��� ������ � ����������� � ������� �������. ��� � ���� ��� �������.";
			link.l1 = "��, ������ ����...";
    		link.l1.go = "Gothic_12_6";
		break;
 		case "Gothic_12_6":
			dialog.text = "����� ������, ��� �� ��������� ��� ������, �����"+ GetSexPhrase("","����") +". � ������ � ���� - '����� ������' ��������� �� ������� ����� �������.";
			link.l1 = "�������...";
    		link.l1.go = "Gothic_12_7";
		break;
 		case "Gothic_12_7":
			dialog.text = "����� ����� � ��������� ���� ������������ ������� � ������ ����. ��� ��� � ���������� ��� �� ��, ��� �� ��������� ��� � ���������� ����.";
			link.l1 = "������� �� �������������, ������...";
    		link.l1.go = "Gothic_12_8";
		break;
 		case "Gothic_12_8":
			dialog.text = "�� �����, �����"+ GetSexPhrase("","����") +"... �� ��� ��, �� ���� ��� ����������� �����, �� ��������.";
			link.l1 = "����� ��������, ������.";
    		link.l1.go = "exit";
			npchar.LifeDay = 0;
			pchar.questTemp.GothicLee = "EndOfQuestLine";
			AddQuestRecord("GothicLee_12_EndOfWar", "2");
			AddQuestUserData("GothicLee_12_EndOfWar", "sSex", GetSexPhrase("","�"));
			AddQuestUserData("GothicLee_12_EndOfWar", "sSex1", GetSexPhrase("��","�"));
			CloseQuestHeader("GothicLee_12_EndOfWar");
            DeleteAttribute(pchar, "questTemp.Waiting_time");
			//==> � ������� ������ ����� ������ ����� ����� ����.			
			sld = characterFromId("SoleiRoyalCaptain");
			RemoveCharacterCompanion(pchar, sld);
			SetCrewQuantityFull(sld);
			Fantom_SetBalls(sld, "pirate");
			sld.GenQuest.CrewMaltaMode  = true;
			sld.Ship.Mode = "Malta";
			Group_AddCharacter("SoleiRoyal", "SoleiRoyalCaptain");
			Group_SetGroupCommander("SoleiRoyal", "SoleiRoyalCaptain");
			Group_SetAddress("SoleiRoyal", "Guadeloupe", "Quest_ships", "quest_ship_1");
			SetTimerCondition("EndOfWar_TakeOutShip", 0, 0, 30, false);
			AddTitleNextRate(sti(NPChar.nation), 5);
			ChangeCharacterReputation(pchar, 5);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 20);
			AddCharacterExpToSkill(pchar, "Repair", 630);
			AddCharacterExpToSkill(pchar, "Sneak", 490);
			AddCharacterExpToSkill(pchar, "FencingLight", 530);
			AddCharacterExpToSkill(pchar, "FencingHeavy", 530);
			AddCharacterExpToSkill(pchar, "Fencing", 530);
			AddCharacterExpToSkill(pchar, "Pistol", 530);
			AddCharacterExpToSkill(pchar, "Fortune", 660);
			AddCharacterExpToSkill(pchar, "Accuracy", 520);
			AddCharacterExpToSkill(pchar, "Grappling", 750);
			//�����
			AddSimpleRumour("�������, ��� �� ������ �����"+ GetSexPhrase("","����") +"! �� �������� ������, �������...", sti(npchar.nation), 5, 1);
		break;



    }
}
