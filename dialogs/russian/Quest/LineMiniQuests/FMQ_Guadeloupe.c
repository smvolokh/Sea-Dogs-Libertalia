// Addon-2016 Jason, ����������� ���������� (���) ���������
void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;
	int i;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		// ������������
		case "citizen":
			dialog.text = "�����������, �������! � ���� � ��� ������� �����������, ������� ������ ��� ��������������.";
			link.l1 = "����������� ��� ������, �����.";
			link.l1.go = "citizen_1";
		break;
		
		case "citizen_1":
			dialog.text = "� ���� ������������ ���� ����� ��� �������� � ��������� �� ��������� ����.";
			link.l1 = "��� ����� ��������� �� ��������� ���� ��� ���������?";
			link.l1.go = "citizen_2";
			link.l2 = "��������� ����? �������. �� � ��������� ���-�� �� ������ ������. �����, ��� ������� �������� ������ �����.";
			link.l2.go = "citizen_no";
		break;
		
		case "citizen_no":
			dialog.text = "��� �������, �������, ���� ���� � ���� ����������� ��� �������. ����� �������!";
			link.l1 = "�� ��������.";
			link.l1.go = "citizen_exit";
			SetFunctionTimerCondition("FMQN_Activation", 0, 0, 5, false);
		break;
		
		case "citizen_no_1":
			dialog.text = "��� ������, �������. ����� �������!";
			link.l1 = "�� ��������.";
			link.l1.go = "citizen_exit";
		break;
		
		case "citizen_exit":
			DialogExit();
			chrDisableReloadToLocation = false;
			npchar.lifeday = 0;
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 20.0);
			SetFunctionTimerCondition("FMQN_Activation", 0, 0, 5, false);
		break;
		
		case "citizen_2":
			dialog.text = "�� ������ ���, �����. �������� - ����, ��������� �� �������� ������ ��������, � � ���� ������������, �� ���� - ������ ���, ���� ������� � ���� ����� ��� �������� ���� � ���� ���� ������ � ������. ������, �����������, ����� ������.";
			link.l1 = "� ������? ��� ���? �������� �������?";
			link.l1.go = "citizen_3";
		break;
		
		case "citizen_3":
			dialog.text = "������, �������. ���, �������. ��� ����� ���� ���� ����� �������� ��� � ������ ��������, ��� �������� �� �����-�����, � �� �� ������ �� ���� ���������, ���, �� ������ ��� � �������� ������.";
			link.l1 = "����� ������ ������?";
			link.l1.go = "citizen_4";
		break;
		
		case "citizen_4":
			dialog.text = "��� �������� � ���������. ��� ����� ����. ���� - �������, ����� �� ���������� �� ����, ������ - �� �������� �� �����.";
			link.l1 = "��� ������� ���� �� ����� ������� ������. ��� �� ����� �������, �, ��������?";
			link.l1.go = "citizen_5";
		break;
		
		case "citizen_5":
			dialog.text = "�������, ����� - ������, � � ���� � ���� ������ ��� ���. ��� ����� ������ ����������, ������� �� �������, � ������� �� ����� �� �������, ��� �� ������ ����. ��� ������ �������. ����, �� ��������?";
			link.l1 = "�� �����!";
			link.l1.go = "citizen_6";
			link.l2 = "��������, �����, �� ���� ����������� �������� �����-�� �������������� � ���� �� ����������. �������� ���� ������ �����.";
			link.l2.go = "citizen_no_1";
		break;
		
		case "citizen_6":
			dialog.text = "�������. ��� ������ ������ ��������� � ��������, � ������ �� � ����� ��������, �� ������ �� ���� �������, ��� �� ��� � ��������. �����, �� ��������� �� ��������� ������� � ������, ����� � ������. �� �����������, �������!";
			link.l1 = "������. ������� � ������ ������ �� ����� �������.";
			link.l1.go = "citizen_7";
		break;
		
		case "citizen_7":
			dialog.text = "�������, �������, �� ���� �� ������������� ���� �����. ��� ��� - ������� ������. � ��...";
			link.l1 = "������� "+GetFullName(pchar)+". �� �������, ����� ������.";
			link.l1.go = "citizen_8";
		break;
		
		case "citizen_8":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "gate_back", "none", "", "", "OpenTheDoors", 20.0);
			AddQuestRecord("FMQ_Guadeloupe", "1");
			pchar.quest.FMQG_Capster.win_condition.l1 = "Hour";
			pchar.quest.FMQG_Capster.win_condition.l1.start.hour = 22.00;
			pchar.quest.FMQG_Capster.win_condition.l1.finish.hour = 23.99;
			pchar.quest.FMQG_Capster.win_condition.l2 = "Ship_location";
			pchar.quest.FMQG_Capster.win_condition.l2.location = "Shore29";
			pchar.quest.FMQG_Capster.win_condition.l3 = "location";
			pchar.quest.FMQG_Capster.win_condition.l3.location = "Shore29";
			pchar.quest.FMQG_Capster.function = "FMQG_CapsterBeach";
			SetFunctionTimerCondition("FMQG_StartLate", 0, 0, 1, false);
			pchar.questTemp.FMQG = "begin";
			pchar.GenQuest.SmugglersBlock = "baster_tavern";
	                                      SetTimerFunction("FMQN_Activation", 0, 0, 10);
		break;
		
		case "citizen_9":
			dialog.text = "��� � ��, ������� "+GetFullName(pchar)+". �� � �������� ����� �������� � ������?";
			link.l1 = "��. ����� ���������� �� ����.";
			link.l1.go = "citizen_10";
		break;
		
		case "citizen_10":
			dialog.text = "����� ������. ������� ��� ����� - �������� � ���������. � ������� - ��� ���� ��������� �� ����� �� ������ ����, �� �����!";
			link.l1 = "� �����. �� ����������, �������� � ����. ��������� ����� � ������.";
			link.l1.go = "citizen_11";
		break;
		
		case "citizen_11":
			DialogExit();
			GiveItem2Character(pchar, "chest");
			log_info("�� �������� ������ � ���������");
			PlaySound("interface\important_item.wav");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "rld", "loc0", "none", "", "", "FMQG_OnBoard", 85.0);

			sld = characterFromId("FMQG_pass_2");
			LAi_SetActorType(sld);
                                                          LAi_ActorAnimation(sld, "Ground_StandUp", "FMQG_pass_none", 3.5);


			sld = characterFromId("FMQG_pass_3");
			LAi_SetActorType(sld);
                                                          LAi_ActorAnimation(sld, "Ground_StandUp", "FMQG_pass_none", 3.5);


			pchar.quest.FMQG_SailStart.win_condition.l1 = "location";
			pchar.quest.FMQG_SailStart.win_condition.l1.location = "Guadeloupe";
			pchar.quest.FMQG_SailStart.function = "FMQG_SailingStart";
			SetFunctionTimerCondition("FMQG_SailingLate", 0, 0, 10, false);
			SetFunctionTimerCondition("FMQG_MutiniActivate", 0, 0, 20, false);
			pchar.questTemp.FMQG = "sail";
			DeleteAttribute(pchar, "GenQuest.SmugglersBlock");
		break;
		
		case "citizen_12":
			dialog.text = "����, �������, �� ��������� ��������� ���� �������������. ������� ������ ����� ������ � ���� �������������.";
			link.l1 = "������� ���� ����� � ���� ����, �����.";
			link.l1.go = "citizen_13";
		break;
		
		case "citizen_13":
			GiveItem2Character(pchar, "chest");
			log_info("�� �������� ������ � ���������");
			PlaySound("interface\important_item.wav");
			AddCharacterExpToSkill(pchar, "Sailing", 200);//���������
			AddCharacterExpToSkill(pchar, "Leadership", 200);//���������
			AddCharacterExpToSkill(pchar, "Sneak", 100);//����������
			dialog.text = "��� � ���� ����. ����� �������, ������� "+GetFullName(pchar)+".";
			link.l1 = "�� ��������!";
			link.l1.go = "citizen_14";
		break;
		
		case "citizen_14":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 20.0);
			for (i=2; i<=3; i++)
			{
				sld = characterFromId("FMQG_pass_"+i);
				LAi_ActorRunToLocation(sld, "reload", "reload1_back", "none", "", "", "", 10.0);
				sld.lifeday = 0;
			}
			AddQuestRecord("FMQ_Guadeloupe", "6");
			CloseQuestHeader("FMQ_Guadeloupe");
			pchar.questTemp.FMQG = "pause";
			pchar.quest.FMQG_Continue.win_condition.l1 = "Ship_location";
			pchar.quest.FMQG_Continue.win_condition.l1.location = "Baster_town";
			pchar.quest.FMQG_Continue.win_condition.l2 = "location";
			pchar.quest.FMQG_Continue.win_condition.l2.location = "Baster_town";
			pchar.quest.FMQG_Continue.function = "FMQG_BasterContinue";
			pchar.quest.FMQG_Block1.win_condition.l1 = "Rank";
			pchar.quest.FMQG_Block1.win_condition.l1.value = 13;
			pchar.quest.FMQG_Block1.win_condition.l1.operation = ">=";
			pchar.quest.FMQG_Block1.function = "FMQG_Block";
			SetFunctionTimerCondition("FMQG_Block", 0, 0, 90, false);
		break;
		
		case "citizen_12a":
			dialog.text = "����, �������, �� �� �����. �� �� ��������� ������ �������� ����� ������������ - �� ��������� ����������� �����. ������� �� ���� �������� ����� �������� ����� ������������ �� ������ � ����������� ��� ���������� ���� �������. �������, ��� ���������� � ����� ������� �� ��������� - ���� �� �������� ��� �������.";
			link.l1 = "�� ���� �������, ��� � � ��������, �� �������: �� �����. �� ���� � ����������.";
			link.l1.go = "citizen_13a";
		break;
		
		case "citizen_13a":
			AddCharacterExpToSkill(pchar, "Sailing", 50);//���������
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Sneak", 50);//����������
			dialog.text = "� ��� ����� ������� �� ��������� ������, ������� "+GetFullName(pchar)+". ����� �������!";
			link.l1 = "�� ��������.";
			link.l1.go = "citizen_14";
		break;
		
		case "citizen_15":
			dialog.text = "�! ����� ����������� �������! "+TimeGreeting()+", "+GetFullName(pchar)+"! ������ ��������?";
			link.l1 = TimeGreeting()+", ����� ������. � ��� � ��� ������, ��� �������.";
			link.l1.go = "citizen_16";
		break;
		
		case "citizen_16":
			sld = characterFromId("Baster_usurer");
			dialog.text = "� � ��� �� ������� ����� ������, �������?";
			link.l1 = "���, ��������, ������ ������ ������ ����� "+GetFullName(sld)+". � �������, �� ���������, ����� � ������.";
			link.l1.go = "citizen_17";
		break;
		
		case "citizen_17":
			sld = characterFromId("Baster_usurer");
			dialog.text = "�������, �������, �� � ��, ��������� �������, ������ ��� �� ��������, ��� � ���������� �� ����� ������� ����� "+GetFullName(sld)+", ��� �� ���� ������. ������� �� ����� � ����� ���� �������� �� ��������? � ������ � ��� �� ����.";
			link.l1 = "���, �� ��� ���, ���� � � �� ��� �����. � ���� �������������� ��������� �������, � �������� ����� "+GetFullName(sld)+", ������� ��� �����, ������ ���� � ������: ��� ��, ������� ������, �� ���������, ��� � ��� ��� ���������� � ����� �������� � ������� ���� ������� �� �������. ��� ��� ���� ��� ������� - �����, ��������� �� �����.";
			link.l1.go = "citizen_18";
		break;
		
		case "citizen_18":
			sld = characterFromId("Baster_usurer");
			dialog.text = "��, ����� �� ���-���� �������, ���� ����� "+GetFullName(sld)+"! ��� ��������� ������������� �����!.. ����, �������, � ��� �� �� �������� �������?";
			link.l1 = "� �� ��� �������? �������, ��� �������� ����������� �� ���� � ���-���.";
			link.l1.go = "citizen_19";
			link.l2 = "� �� ��������, � ���� ���� �����-�� �����?";
			link.l2.go = "citizen_25";
		break;
		
		case "citizen_19":
			dialog.text = "��, � �������� ��� ��������, ����� �������. � ���� ��� �� ��������� ������� ����������� �� ���� ������ ����������� �����. ����� �� ������ �� ��������� - ������ ������, � � ������ ���������� �������� � ����� �������, � ����� �������. ��, �������, ������ ���������� ��������� ���� ����� ������, ������ ������-���������� ��� ���� ����� �� � ���� - ����� � ���� �� ����������. ��� ��� ����� �������� ��������� � ����� ������� ����� ������ �������� ���� ��� � �������� ���� � �����. � �� ���� ��������� ��� � ��� ��� �������� ����.";
			link.l1 = "� �� ��������, ��� � ������ ������ ���������� � ���� ����� �����, ��� ���������? �� ������ ���� � ��� �������, ��������, � ���� �� ������������!!";
			link.l1.go = "citizen_20";
			link.l2 = "�������, �� �����. ����� ���, �������, ���� �� �������, �� ������������� � ���� ��� ������, � ������� �� ���������. �� �� �� �������, ��� � ��� ��� �������. � ������ �� ������ � ����, ����������� � ���-��� � �������� ����������, ��� �� ���������. � �� ��� ������� �� ���� ����� � ������ �������� � ����������� �� �����.";
			link.l2.go = "citizen_21";
		break;
		
		case "citizen_20":
			dialog.text = "�-�! �������! �� ������! �������!!";
			link.l1 = "...";
			link.l1.go = "citizen_fight";
		break;
		
		case "citizen_21":
			dialog.text = "��-��, ��������, � �� �������� �������� ������ �������, ����� ��� ���� � ������ ������������ � ������� - �������� � ��� ������. ����� �������, �������.";
			link.l1 = "...";
			link.l1.go = "citizen_22";
		break;
		
		case "citizen_22":
			DialogExit();
			LAi_SetActorType(npchar);
			AddQuestRecord("FMQ_Guadeloupe", "19");
			pchar.quest.FMQG_Mayak.win_condition.l1 = "location";
			pchar.quest.FMQG_Mayak.win_condition.l1.location = "Mayak2";
			pchar.quest.FMQG_Mayak.function = "FMQG_Lighthouse";
		break;
		
		case "citizen_23":
			dialog.text = "����! � ������! ������!";
			link.l1 = "��-�� ��! � ������ ����� ������ � ���� ���� �� �������!";
			link.l1.go = "citizen_24";
		break;
		
		case "citizen_24":
			DialogExit();
			chrDisableReloadToLocation = false;
			RemoveAllCharacterItems(npchar, true);
			DoQuestReloadToLocation("Mayak2", "goto", "goto1", "FMQG_OnLighthouse");
		break;
		
		case "citizen_25":
			dialog.text = "����� ���� ������, �������. � ��� �����, ��� �� ���� ��� ������ �� ������� ����������, �� �� �� ����� ���� �����������?";
			link.l1 = "������.";
			link.l1.go = "citizen_26";
		break;
		
		case "citizen_26":
			dialog.text = "�������. ����� � ��������� ��� ����������� ������ �������� ��� ���. ������ ������� ���� ��������, � �� �������� ��� ������ '������������' � ���������� �� ������, ��� ���� �� �������� �������, �� ���������� ��������� ������, ��� ������� ������� � ���������� ������������� ����� '��������', � ���������� ������� ��� ����� ������ ���������� ������ '������', ������������ ������� ������ �������� �������.";
			link.l1 = "���. �������, � ��� �����, ����� ������.";
			link.l1.go = "citizen_27";
		break;
		
		case "citizen_27":
			dialog.text = "���, ��� �� ����� ���������������, ����� �������. ���� ������� �� ���� ����� ������� ������ ����� ������� ��������� � ��������� �������, ���� ������ ��� ������ � ��������� '������'. � ������, ������� � ��� ������ ������, ����� ��������������, ������� ������ ������ ����������. �������� �������, � ������ ���� � ������.";
			link.l1 = "������...";
			link.l1.go = "citizen_28";
		break;
		
		case "citizen_28":
			LAi_Fade("", "");
			GiveItem2Character(pchar, "letter_baker");
			ChangeItemDescribe("letter_baker", "itmdescr_letter_pinett");
			dialog.text = "(�����) ���, �������. ����� � �������� ��� ���������� ����������. ���� ������� ����������, ����� ����������, � ������ ������� � �������� �����.";
			link.l1 = "���������� �����������?";
			link.l1.go = "citizen_29";
		break;
		
		case "citizen_29":
			sld = characterFromId("Baster_usurer");
			dialog.text = "������� ���. ������ �������� - �������� ��� ���������, ����� "+GetFullName(sld)+" �������� �� ��� ��������. ��, � ���, �������: ��� �� ������ ���� ���������... ��� ��� ����� ���� �� ��������� �������, � ���� �� ���������� ���, ��� ����� �� ������� ���� �������� ������ ��� �����, � �������� ��� ��� ��� ��������� �����, ������� � �� ����� ������� � ��� �� ������.";
			link.l1 = "���� ���� ������ ������� ����� � ���������� �������� ��� - �� ������, ��� ������ � ����� �������������.";
			link.l1.go = "citizen_30";
		break;
		
		case "citizen_30":
			dialog.text = "������������. ������� ���������� � ������ ��������� ����� ������. ��� ����� ��� ��������� ������������ �� ������������ ������. ��������� �����, �������.";
			link.l1 = "����� �������, ����� ������.";
			link.l1.go = "citizen_31";
		break;
		
		case "citizen_31":
			DialogExit();
			pchar.questTemp.FMQG = "letter";
			AddQuestRecord("FMQ_Guadeloupe", "24");
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 1;
		break;
		
		case "citizen_fight":
			chrDisableReloadToLocation = true;
			LAi_group_Delete("EnemyFight");
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
			AddDialogExitQuest("MainHeroFightModeOn");
			DoQuestFunctionDelay("FMQG_PlantationGuards", 3.0);
			pchar.questTemp.FMQG = "fail";
			AddQuestRecord("FMQ_Guadeloupe", "18");
			CloseQuestHeader("FMQ_Guadeloupe");
		break;
		
		// �������� � ����������
		case "cureer":
			dialog.text = "������������, �����! ���� ��� �� - ������� "+GetFullName(pchar)+"?";
			link.l1 = "��, ��� �. ��� ������?";
			link.l1.go = "cureer_1";
		break;
		
		case "cureer_1":
			sld = characterFromId("BasTer_usurer");
			dialog.text = "����� "+GetFullName(sld)+", �������� ����� ���-���, ����� ������ ��� ������� ��� �����, � ��� ����� ������. �� ���������� �������� ���� ��������� ����������� � �������� ���������� � �������� ������ �����, � ����� - �������� ��� ��� �����������.";
			link.l1 = "����� ��������� - � ����� �� � ��� �����������?";
			link.l1.go = "cureer_2";
		break;
		
		case "cureer_2":
			dialog.text = "�� ���� ��� ��������� ����� ����� "+GetFullName(sld)+" ��� �������. �������, �� �� �������� ��� � ���� ����������.";
			link.l1 = "��... ������. ���������� - ����� �����������, � �� �������� ���������� �� ������. � ���������� � ���� �� ����������� ������.";
			link.l1.go = "cureer_3";
		break;
		
		case "cureer_3":
			dialog.text = "��������� ���, �������. �� ��������!";
			link.l1 = "����� �������.";
			link.l1.go = "cureer_4";
		break;
		
		case "cureer_4":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 10.0);
			chrDisableReloadToLocation = false;
			LocatorReloadEnterDisable("Baster_town", "reload1_back", true);
			LocatorReloadEnterDisable("Baster_town", "reload2_back", true);
			LocatorReloadEnterDisable("Baster_town", "gate_back", true);//������� ������ �� ������
			pchar.questTemp.FMQG = "continue";
			pchar.quest.FMQG_Block.over = "yes";
			pchar.quest.FMQG_Block1.over = "yes";
		break;
		
		// ��� ����
		case "Juan":
			dialog.text = "����! � ����� ����, �������! �� ������, ��� ��� ��������� �������...";
			link.l1 = "�����, ���... ������ - ��� ����. � ���� ��������. � ������ ����� ���������� � ����. ����� ����, ��� �� ������ ��������, �� � ����� ����������.";
			link.l1.go = "Juan_1";			
		break;
		
		case "Juan_1":
			DialogExit();
			Lai_SetPlayerType(pchar);
			DeleteAttribute(npchar, "DontRansackCaptain");
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 3.0);
			pchar.questTemp.FMQG.Prisoner = GetFullName(npchar);
			pchar.GenQuest.LastQuestPrisonerIdx = SetCharToPrisoner(npchar);
			AddQuestRecord("FMQ_Guadeloupe", "14");
			pchar.questTemp.FMQG = "juan_capture";
			DoQuestCheckDelay("LAi_ReloadBoarding", 3.5);
		break;
		
		case "Juan_2":
			dialog.text = "";
			link.l1 = "� �������� ���� ����� ������. ������ ���� �������. ����������, � ����� � ���, ��� ���� ��������, ���� ��������� �������.";
			link.l1.go = "Juan_3";
		break;
		
		case "Juan_3":
			dialog.text = "�� ������� �������� ������� �� ���������, � ������ - �� ������� ���������. �� ��������� ���������� ���� ������ ������ ���. ���������� ��������� - ��� ������.";
			link.l1 = "������ ���� '������' ���������� ������?";
			link.l1.go = "Juan_4";
		break;
		
		case "Juan_4":
			dialog.text = "�� ��� ��� ��, ��� � �� ���������. ������������� ��������, ����� � �������� ���������� �������, ������ ����� ��� �����. �����, ��� ������ �� �������� ������������� � �������� ������ - ����� � ���� �� ��� ������� �� ���������?";
			link.l1 = "�������. � ���� ���� ����������� ����� ���������� �������?";
			link.l1.go = "Juan_5";
		break;
		
		case "Juan_5":
			dialog.text = "��������. ��� ����� ��� ���. � ���� ������� ����������.";
			link.l1 = "��� ��� ������ ������� � ���?";
			link.l1.go = "Juan_6";
		break;
		
		case "Juan_6":
			dialog.text = "� ��� ��� �������? ������ � ������ ���, ����� ���� �����, ������ ������ ������ � ������. � �� ��� ����� � ��� ������ ���.";
			link.l1 = "����. �����, ����� ��� ���� � ���������. ������, ��� ����, �� �� ������� ������� �������� �������, ��� � � ���� �� ������. ���� �� ����� �������� �� ��������� - ����� �� ����. �����.";
			link.l1.go = "Juan_7";
		break;
		
		case "Juan_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			pchar.questTemp.FMQG = "headhunter_pinett";
			AddQuestRecord("FMQ_Guadeloupe", "17");
			// ������� - � ���������
			sld = characterFromId("FMQG_pass_1");
			ChangeCharacterAddressGroup(sld, "Plantation_F2", "goto", "goto1");
			sld.Dialog.currentnode = "citizen_15";
			LAi_SetStayType(sld);
		break;
		
		case "killer":
			dialog.text = "��������, �� ������ - ������ �������. ���� ���� ���� � ���, ��� �� ������� ����� ������...";
			link.l1 = "...";
			link.l1.go = "killer_1";
		break;
		
		case "killer_1":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); // ������ ������
			LAi_group_Delete("EnemyFight");
			int n = 2;
			if (MOD_SKILL_ENEMY_RATE > 6) n = 3;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("FMQG_killer_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "FMQG_KillersDestroy");
			//AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
