extern void InitColonies();
extern void InitIslands();
extern void CreateCharacters();
extern void InitItems();
extern void wdmInitWorldMap();

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    ref chr, sld, rShip, rItm, rItem;
    float  fTemp;
    bool bOk;
	int i, iTemp;
	string sAttr, sGun, sBullet, attrL;
	aref rType;
    
	// ��������� ��� �� ����� -->
	sAttr = Dialog.CurrentNode;
  	if (findsubstr(sAttr, "CabinCompanionTalk_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	PChar.GenQuest.CabinCompanionNum = strcut(sAttr, i+1, strlen(sAttr)-1); // ������ � �����
 	    Dialog.CurrentNode = "Cabin_Companion_Talk";
 	}
	
// ����� ���������� by xxxZohanxxx -->	
  	if (findsubstr(sAttr, "CabinPassengerTalk_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
		PChar.GenQuest.CabinPassengerNum = strcut(sAttr, i+1, strlen(sAttr)-1); // ������ � �����
 	    Dialog.CurrentNode = "Cabin_Passenger_Talk";
 	}
// <-- ����� ���������� by xxxZohanxxx	

	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	PChar.GenQuest.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
 	// ��������� ��� �� ����� <--

	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
		break;
		
		case "First time":
	      	NextDiag.TempNode = "First time";

	        Dialog.Text = "���� �� ������� ��� ������, ������, ���-�� ����� ��� � ����";
			Link.l1 = "�����";
			Link.l1.go = "exit";
			//--> ����������� ������
			if (CheckAttribute(pchar, "questTemp.HWIC_FindIsland"))
    		{
    		    dialog.text = "����, ��� �� � ����� ��� ����� �� �����. ������ ���. ����� ������������ �� ������.";
    			link.l1 = "...";
    			link.l1.go = "exit";
				AddDialogExitQuestFunction("SearchingForIslandOnMap");
    		}
			if (CheckAttribute(pchar, "questTemp.HWICMC") && pchar.questTemp.HWICMC == "Fleetwood")
    		{
    		    dialog.text = "���-���, ��� �� � �� �����. ���� �������� ������� � ������ �����, � ���� ������ ������ ����� ������� � ������������ �������� �������.";
    			link.l1 = "...";
    			link.l1.go = "exit";
				pchar.quest.Fleetwood_repeatShore.win_condition.l1 = "ExitFromLocation";
				pchar.quest.Fleetwood_repeatShore.win_condition.l1.location = pchar.location;
				pchar.quest.Fleetwood_repeatShore.function = "Fleetwood_repeatShore";
    		}
			//<-- ����������� ������
			
			//--> ������ ����
			if(CheckAttribute(pchar, "questTemp.FalseTrace") && pchar.questTemp.FalseTrace == "TalkCabinWoman" && PChar.location == Get_My_Cabin()) 
	        {
				dialog.text = "��... ������ ����� ���������� - ���� �������������, ���� ��� ������� ������ �� ������. ���� �����, �� ���� ��� �� �� ����. ��, �������, ���������-�� � � ��� ��������... ������! �������� ��� ����������� � ���� �������!";
    			link.l1 = "����, �������!";
	    		Link.l1.go = "exit";
				chr = characterFromId("FalseTraceWife");
				chr.dialog.currentnode = "FalseTrace_wife_6";
				pchar.questTemp.FalseTrace.CharID = "FalseTraceWife";
				AddDialogExitQuest("SetFalseTraceCharToCabin");
	    	}
			//<-- ������ ����
			
			//--> ����������
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "DigGems")
    		{
    		    dialog.text = "�������, ��� ��� �����. ��� ������������ �������� ������ � ������. �������, ������ ���� ������ �����.";
    			link.l1 = "(�������� ����)";
    			link.l1.go = "exit";
				AddDialogExitQuest("FindPortugalGems");
    		}
			//<-- ����������
			// ����
			if (CheckAttribute(pchar, "questTemp.Saga.JessSoul"))
    		{
    		    dialog.text = "��� ���? ��� �?! ��� �� �������� �����?";
    			link.l1 = "...";
    			link.l1.go = "exit";
				AddDialogExitQuest("Saga_JessikaSoul_2");
    		}
            //--> ������� �� ������ � ����� ����������, LSC
			if (CheckAttribute(pchar, "questTemp.LSC.DiffIndoor"))
    		{
    		    dialog.text = "��� �����, ������� �� ���������� ��������� �������. �������... ���� ������ ���� ���. ��� ��� ������� ���? ���� ��������� �������� ������.";
    			link.l1 = "��������� ��� ����.";
    			link.l1.go = "knock_2";
				link.l2 = "��������� ��� ����.";
    			link.l2.go = "knock_3";
				link.l3 = "��������� ���� ���, �����, ��� ����.";
    			link.l3.go = "knock_1_3";
				link.l4 = "��������� ��� ����, �����, ��� ����.";
    			link.l4.go = "knock_2_2";
				link.l5 = "��������� ��� ����, �����, ���� ���.";
    			link.l5.go = "knock_3_1";
    		}
			//<-- ������� �� ������ � ����� ����������, LSC
			
			//--> �������� ���������� ��������, ��� �������� � ����� ����
			if (pchar.model == "protocusto")
    		{
    		    dialog.text = "��! �� � ������� �� ��� ���������!";
    			link.l1 = "";
    			link.l1.go = "exit";
    		}
			//<-- ���������� ��������
			// ����� �� ������������
			if (IsCharacterInLocator(pchar, "item", "dolly1") || IsCharacterInLocator(pchar, "item", "dolly2") || IsCharacterInLocator(pchar, "item", "dolly3"))
    		{
    		    dialog.text = "���-���-���! ���� � �� �������! ���� ��� ������� �������!..";
    			link.l1 = "...";
    			link.l1.go = "exit";
    		}
			if (CheckAttribute(pchar, "questTemp.Terrapin") && pchar.questTemp.Terrapin == "roof")
    		{
    		    dialog.text = "���� ������� - �������� �����. ��� ��������� �����, ��� � �����... �� ���-�� �� �� ���. ���� ���� ���� �� ������������ � ��������! ��� ������, ��� ���� ����� ������ ����, ���� ������ ������ ������\n�� ���� �� ��� ������� ���� ��� ����? ���������, �� ��� ������ � ������. ���� ���-�� ������, ���� � ���� ������� ������� �� ��� ���...";
    			link.l1 = "";
    			link.l1.go = "terrapin";
    		}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "think")
    		{
    		    dialog.text = "���������, ���������... ��������� �����... � �� ���� � �������� ����������, ���� ������... ����� �� ������, ��� � ������������ ������� ����� ������ ������ �������� ���� ��� ����������� ������. �����, �� ����� ����������� � ���, ����� ������� ��� ������\n� ���� �����, �� ��� � ��� � ������� - �� ������ ��� �� ������� ������������, ��� ������ ���������� � ���� �� ������. ��� ������. �� � ������, ��� ��������� ������, ������� ������ ''��� �� ������'', � ������ ������ ������ - ���� � �� ��. ������� ����� �������� ��������� ������ ��������� � ����������� ������� �� ''���������'' ������ � �� ������\n������ ����������, ��� ������ ���-���, �� �� �����, � ������ ���-���, �� �� �����... �������! � ��� �� ����� ����������� ���������? �� �� ���� �� ��� ������ ���������� ��� ������� ����, �? �����, ��� ������ �� ����\n�������������, ���� ��� ����� ��� ������, �� � ���� ���� ������: � ����� �������� ������� � ��������� �����, �... ��-��, ������ ��� ������ �� ��������. �� � ������ �� ����� ����������� ���� ������? ������, �������� ������ ����������� � ���������\n��� ����� ������� �������� - � ��� � ������ �� ����������, � ��� ������ ���� ��������, ����������, �������� ���� ������... ��� ���� ��������. ������ ������ ������ �� ���������� ��������������, ���� ����� ������ � �� �������� �������� ��������\n������, ������... ���-�� � ��� ������ ��� ���... ��� ���? �����, ���� � ���. ����� � �������, �������� ������ �������, � ����������� � ��������.";
    			link.l1 = "";
    			link.l1.go = "exit";
    		}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "shore")
    		{
    		    dialog.text = "������ ����������� �� �������, �� ������ ����� �������� �� ����������, � ���� ������ ������, ������ ����, ����� �������� � �������� ����, ���� � �������� � ����, ���� �� �������. � ����� �� ������� ������������ ��� ������������: ����� ������, ��� � ���� � ���������... ����������-�� � ������ � ����� ����� ������� � ��������, ��� ������ ��� ������� �����...";
    			link.l1 = "";
    			link.l1.go = "exit";
    		}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "galeon")
    		{
    		    dialog.text = "������ �� ������� ������ �������, � ��� ���, ��� ���� - ������ � ����� �����. �����, � ����� �������� �� ���� �� ������, ���� �������� ����� �� ����� � ������ �������� �� �������...";
    			link.l1 = "";
    			link.l1.go = "exit";
    		}
			if (CheckAttribute(pchar, "questTemp.Guardoftruth_room"))
    		{
    		    dialog.text = "���������� ������ ��� � ������ ��������� �� ������ �����, � ����� �� ��������� � ������������� ��������... ������ ������� ������. ���� ������� � ���� � ������ �� �������� �����, �� � ��� ����� �������� � ������� ����. � ������ ��� ���� �����, ����� ����� �� �������...";
    			link.l1 = "";
    			link.l1.go = "exit";
				AddDialogExitQuest("GuardOT_FindWayToRoom");
    		}
			// ������ ���������
			if (CheckAttribute(pchar, "questTemp.Ksochitam_Dolly") && pchar.questTemp.Ksochitam_Dolly == "half_pearl")
    		{
    		    dialog.text = "���-���! ��� � � ����� �����, ��������� ''�����������'': ��� ��������� �������! ����� � ��� ������� ������� ������ ���� ��������� �������� � ��������� ������ ���� � �� �� �����������, ��� �� �������. ������� - ��������� ����� - ��������� �������. ������ ���� �������� �����������, ���� ��������� ������ ����, �� �����, � ����� ������������ �� ��������.";
    			link.l1 = "";
    			link.l1.go = "exit";
				AddDialogExitQuest("Ksochitam_FindFirstWay");
    		}
			if (CheckAttribute(pchar, "questTemp.Ksochitam_Dolly") && pchar.questTemp.Ksochitam_Dolly == "half_dominica")
    		{
    		    dialog.text = "���-���! ��� � � ����� �����, ��������� ''�����������'': ��� ��������� �������! ����� � ��� ������� ������� ������ ���� ��������� �������� � ��������� ������ � ���� � �� �� �������, ��� �� �������. ������� - ��������� ����� - ��������� �������. ������ ���� �������� �����������, ���� ��������� ������ ����, �� �����, � ����� ������������ �� ����.";
    			link.l1 = "";
    			link.l1.go = "exit";
				AddDialogExitQuest("Ksochitam_FindSecondWay");
    		}
			if (CheckAttribute(pchar, "questTemp.Ksochitam_Dolly") && pchar.questTemp.Ksochitam_Dolly == "full")
    		{
    		    dialog.text = "��� ���������� �������! ������ ����� �������� ������ ����������� �� �����. ����������� ���� ����������� � ������ ��� ��������������� ������� ��������.";
    			link.l1 = "";
    			link.l1.go = "exit";
				AddDialogExitQuest("Ksochitam_FindFullWay");
    		}
			// ����������� �� ��������
			if (CheckAttribute(pchar, "questTemp.Tieyasal_CabinTalk"))
    		{
				if (pchar.questTemp.Tieyasal_CabinTalk == "calendar")
				{
					dialog.text = "������ �� ���������� ������, ��� ���� �����-�� ���� � �������� � ������ ����������� ������. ������, ����� �������� ������ � ����� ������ � �������� ������. ������ � ���� �� ���� �� ������ ����� ����� � ���, ��� ���������������� ������ ���������� ��������������� ��� ������� � �������� ��������� ����� � ��������\n�� � ����� ������� ������� ���� �������, ��� �������� �� ������ ������ ���������� ''���������'' � ���� �����. �� ������ �� ����� ������� ��� ������� ��������? ��. ����� ����, �� ����� ���� ��������� ����� ������� ����������, ������������� ������� � �������� �������, ���� �����-�� ����������� � ���� �����\n��� �� ��� ����� �������? ��� ���� ���������� �����? ��� �����-�� �������������� �������� ��������? �������, ���� ����������� � ������� � ������������ �� ���� ������. ���� �� �������� ���� ������ � ����� �� ������ �����, ������� � ��������. ��������, ��� ����� ���� ���� � ����� �� ���� �� ������-�������� �����.";
					link.l1 = "";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "������ �� ���������� ������, ��� ���� �����-�� ���� � �������� � ������ ����������� ������. ������, ����� �������� ������ � ����� ������ � �������� ������. ��������, ������ ��� ����� ����� ���� ���� � ����� �� ���� �� ������-�������� �����.";
					link.l1 = "";
					link.l1.go = "exit";
				}
				AddDialogExitQuest("Tieyasal_AfterCabinTalk");
    		}
			// ������ - ����� ��� ������� 010912
			if (CheckAttribute(pchar, "questTemp.Tieyasal_final"))
    		{
				dialog.text = "��� � ����� �������� ����. � ����� ��� � ���� �����������, ��� ���������� ������ ����� ���������� ������, � ��� ����� ��������� � ����������� ������� � ���? ��� � �������� ��� ������ ���� ���? ����� ����, ��� ������\n����� ����� ���� �� ������ �� �������. ������ ����� ������������ �����, � ������. ��... ��� ������ ���� �� � �����?";
				link.l1 = "��, � ����������� � ������.";
				link.l1.go = "final_1";
				link.l2 = "���, � ������� �����, �� �������.";
				link.l2.go = "final_2";
    		}
			// �������� ����� 040912
			if (CheckAttribute(pchar, "questTemp.Europe"))
    		{
				PlaySound("VOICE\Russian\military02.wav");
				dialog.text = "�� �������, ��� ������ ���������? ����� �������� ���������! �������� ���� ���, ����������� �� � �������� ����, ��� ��� ���������! ������!!";
				link.l1 = "...";
				link.l1.go = "exit";
				AddDialogExitQuest("Europe_SharlieFinal_2");
    		}
			// Addon-2016 Jason, ����������� ���������� (���) ���������
			if (CheckAttribute(pchar, "questTemp.FMQG.Info") && pchar.location == "Bridgetown_Plantation")
    		{
    		    dialog.text = "��� ����� ������ ����� ��� ������. ����� ���� ������ � ��������� �������.";
    			link.l1 = "...";
    			link.l1.go = "exit";
				AddDialogExitQuest("FMQG_KidnappingInfo");
    		}
			// Addon-2016 Jason, ����������� ���������� (���) ����-���������
			if (CheckAttribute(pchar, "questTemp.FMQN.Choose") && pchar.location == "shore40")
    		{
				dialog.text = "��. ��� ��� ������� ����� ������. ������� ���, ��� �������� ������� �� ����-������ ����� � �� ������������. ���� ��������� ��������� ���� � ���� ������� ��������. �� ���-�� ��� �����? � �� ���� � �����������... ��� �� ��� ������? ���� ������ �� ����� �������� � ������ �� ���� ������ ��������, ��� ��������?";
				link.l1 = "�������� ��������.";
				link.l1.go = "FMQN_1";
				link.l2 = "��������.";
				link.l2.go = "FMQN_2";
    		}
			// Addon 2016-1 Jason ��������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Chest") && pchar.location == "shore37")
    		{
    		    dialog.text = "����, ������ �����������. ���� ���������� � ���� ������ ��� ����� ���� ������. ����� � ������ � ������ ���������� ������� �� �������� �� �������, � ������� � ������� �������� �������� ������� �� �����������: �������� - 30, �������� - 2. � ������� ������� ����� ���� �� 1 �����, � � ������� - 20, ����� �� ��� �� ����� �����. �������� ����� ���������� ��������, �� ����� 3 ���� �� �������� �� ����� ������. ��������� � �����!";
    			link.l1 = "*��� �������� ������� �� ��������� ����� �������� ����������� ''����� �����''*";
    			link.l1.go = "exit";
				AddDialogExitQuest("Mtraxx_PlantChestReadyExit");
    		}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Boats") && pchar.location == "Maracaibo_river")
    		{
    		    dialog.text = "����, ����� ��������� ����� �����. ��� ����� ���� ����� ����������� 20 ������ ����������� ����� � 10 ����� ����. ���������� ������� �� �������. ���������� �������� ������ �������, ������������� � ���������� ���� � ������� ��������.";
    			link.l1 = "*��� ������ ������� � ��������� ����� ����������� ''����� �����''*";
    			link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Mtraxx.Boats");
				AddQuestRecord("Roger_5", "11");
    		}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution.Powder") && pchar.location == "shore10")
    		{
    		    dialog.text = "����, � ������-�������� ������ ���� ����� �� ������ ��������. ��� ����� ��� ����������� 300 �������� ������, ����� ���������, � ����� ���� �� ������ ����� � ����� ������ - ������� ������.";
    			link.l1 = "*��� ������ ������� � �������� ������ � ������ ����������� ''����� �����''*";
    			link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Mtraxx.Retribution.Powder");
				pchar.questTemp.Mtraxx.Retribution = "powder";
				chrDisableReloadToLocation = false;
    		}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution.ExitClosed") && pchar.location == "Judgement_dungeon_01")
    		{
    		    dialog.text = RandSwear()+"����� ������!! ����� �� ��������� - ������ �� �������� ������� ���-�� �������!.. "+RandSwear()+"\n�-�-�... ��� ���?..";
    			link.l1 = "";
    			link.l1.go = "mtraxx_dungeon";
				DeleteAttribute(pchar, "questTemp.Mtraxx.Retribution.ExitClosed");
    		}
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Retribution.Bead") && pchar.location == "Judgement_church")
    		{
    		    dialog.text = "�� ��� � ���... �����. ������ ���� ������\n������, ��� ������ ��� ����: �� ���� ���������� �� ���������. ��������� ���� �������, ����� � ����� ����� �� ���� � ''�����������'', ����� ����� ������ ����� � ���������� � �����, �� ������... � ��� ������� ���� ������� - ������� � ��� ���� �� ���� ������ ��������? ������, ����? ��� �� ��� ���� � �����, ������ � �����\n� ��� �����, ������, �����-�� ���� �������. ����� ���������� ����� ��� ����, ����� ����������. ������ � ���� �����, ������� �����... ��������, � ����� ���� �����: � ������ �����, ��� ������� �� �����, � ���� �� ����� �����������. �����, �������, � �� �������� ������...";
    			link.l1 = "";
    			link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.Mtraxx.Retribution.Bead");
				AddDialogExitQuestFunction("Mtraxx_RetributionBead");
    		}


			// ==> ����� ��������, ����������� ����� � ������ � ��������
			if (pchar.questTemp.Ascold == "Ascold_NotEnterFoundGrave")
			{
	        PlaySound("VOICE\Russian\gotica\GG\UNDEADDRAGONDEAD_01.wav");
				dialog.text = "���, ����� ���� ���� ����-��. �� �� ������ ������. ����� �� �������.";
				link.l1 = "";
				link.l1.go = "exit";
			}
			//===> ����� ��������, ������� ������� �����.
			if (pchar.questTemp.Azzy == "Azzy_IHaveLamp" && locations[reload_location_index].type == "shipyard")
			{
	        PlaySound("VOICE\Russian\gotica\GG\PERM_01.wav");
				dialog.text = "���, ��� � ��, ��� ��� �����: �������� �����, ���������, ������� ��� �����... ����� ���������� � ��������...";
				Link.l1 = "��������� �����������.";
    			Link.l1.go = "FreedomAzzy";
			}
			// ����� �������� �������� � ���������
		if (CheckAttribute(pchar, "questTemp.Ascold.Xsardas"))
    		{
    		    dialog.text = "��� ���? ��� �?! ��� �� �������� �����?";
    			link.l1 = "...";
    			link.l1.go = "exit";
                                                      DeleteAttribute(pchar, "questTemp.Ascold.Xsardas");
			AddDialogExitQuest("Ascold_Xsardas_2");
    		}

			// ����� ����������� ���
		if (CheckAttribute(pchar, "questTemp.GothicTorus_fake.Xsardas"))
    		{
	                       PlaySound("VOICE\Russian\GOTHIC\GG\WISP.wav");
    		    dialog.text = "��� ���? ��� �?! ��� �� �������� �����?";
    		    link.l1 = "...";
    		    link.l1.go = "exit";
                                        DeleteAttribute(pchar, "questTemp.GothicTorus_fake.Xsardas");
		    AddDialogExitQuest("GothicTorus_fake_01");
    		}

		if (CheckAttribute(pchar, "questTemp.GothicTorus_RoseauCharlotte.fake"))
    		{
    		    dialog.text = "����� �������� ���?";
    		    link.l1 = "...";
    		    link.l1.go = "exit";
                                        DeleteAttribute(pchar, "questTemp.GothicTorus_RoseauCharlotte.fake");
		    AddDialogExitQuest("GothicTorus_fake_tavern_morning1");
    		}

			// "����" ��� "�������-����"
	               if (CheckAttribute(pchar, "questTemp.GothicTorus_RoseauCharlotte.Killwork"))
    		{
	                       PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_2.wav");
    		    dialog.text = "�, ��, � �����? ��� �� ��, ��� � �����������?";
    		    link.l1 = "...";
    		    link.l1.go = "exit";
                                        DeleteAttribute(pchar, "questTemp.GothicTorus_RoseauCharlotte.Killwork");
		    AddDialogExitQuest("GothicTorus_RoseauCharlotte_01");
    		}

			// "������ � ������ ����"
	               if (CheckAttribute(pchar, "questTemp.Gothic_Smithy_Augusta.Death"))
    		{
 	                       PlaySound("VOICE\Russian\gotica\SFX\GAMESTART.wav");
	                       PlaySound("VOICE\Russian\GOTHIC\GG\KNOWWHEREENEMY.wav");
    		    dialog.text = "� ��� ������ � ��� ��� ������� ����� ������, ����� ��� �� ������� ����� ��� ����. ׸��... �� � ������� �� ��� ������...";
    		    link.l1 = "";
    		    link.l1.go = "exit";
                                        DeleteAttribute(pchar, "questTemp.Gothic_Smithy_Augusta.Death");
		    AddDialogExitQuest("Gothic_Smithy_Augusta_End");
    		}

		if (CheckAttribute(pchar, "questTemp.Gothic_Smithy.Senyan"))
    		{ 
 	               PlaySound("VOICE\Russian\gotica\SVM_1\SVM_15_PICKLOCKMISSING.wav");
                                 dialog.text = "����� �� ����������� �������.";
    	               link.l1 = "";
    	               link.l1.go = "exit";
                                 DeleteAttribute(pchar, "questTemp.Gothic_Smithy.Senyan");
	               AddDialogExitQuest("Gothic_SmithyPuertoRico_Senyan");
    		}

			//===> ���� ������ ��������
			if (pchar.questTemp.BlueBird == "seenCarriers")
			{
	                                PlaySound("VOICE\Russian\GOTHIC\GG\WISP.wav");
		              dialog.text = "��-�-��, ����� �����-�� ���. ������ �����, ��������, ��� ����� ������...";
			Link.l1 = "...";
    			Link.l1.go = "exit";
			AddDialogExitQuestFunction("BlueBird_endCaveDialog");
			}

			//���
			if (pchar.questTemp.Headhunter == "halen_room")
    		{
    		    dialog.text = "��, ���� ����� � ���������. ���� ���������� ���������...";
    			link.l1 = "...";
    			link.l1.go = "exit";
			AddDialogExitQuestFunction("RatHunters_Sleep");
    		}
			//���������� ����
			if (CheckAttribute(pchar, "questTemp.GothicAPS_FindIsland"))
				{
				dialog.text = "����, ��� �� � ����� ��� ����� �� �����. ������ ���. ����� ������������ �� ������.";
				link.l1 = "...";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("GothicAPSSearchingForIslandOnMap");
				}
			//����� ���������� �������
	if (CheckAttribute(pchar, "questTemp.GothicSmithyBeliz_FindIsland"))
    	{
    	dialog.text = "����, ��� �� � ����� ��� ����� �� �����. ������ ���. ����� ������������ �� ������.";
    	link.l1 = "...";
    	link.l1.go = "exit";
	AddDialogExitQuestFunction("GothicSmithyBelizSearchingForIslandOnMap");
    	}

		break;
		
		// boal -->
		case "TalkSelf_Main":
	   		NextDiag.TempNode = "First time";
//navy --> after duel in tavern
			if (CheckAttribute(pchar, "questTemp.LocationClone"))
			{
			PlaySound("VOICE\Russian\gotica\GG\HALLO_1.wav");
				Dialog.Text = RandPhraseSimple("������ ���� �������... ������ ����� ������� ������������� ������.", "��! ��� ���� ������. � ��� ���������� ����� �����������!");
				link.l1 = "...";
				link.l1.go = "exit";
				DeleteAttribute(pchar, "questTemp.LocationClone");
				break;
			}
//navy <--
	        Dialog.Text = RandPhraseSimple("��... ��� �� ��� ������ �������� �������?", "��� �� ��������?");
	        if (!bDisableMapEnter && pchar.location == Get_My_Cabin())
	        {
				/*//navy --> 13.02.08
				if (!bDisableMapEnter && GetCompanionQuantity(PChar) > 1)
				{
    				link.l3 = "������� ����������.";
    				link.l3.go = "Cabin_CompanionSelect";			
				}
				//navy <--*/
// ����� ���������� by xxxZohanxxx -->					
				link.l3 = "������� �� ���...";
    			link.l3.go = "Cabin_PersonSelect";
// <-- ����� ���������� by xxxZohanxxx	
			}
			else 
			{   //���.�������, ����� �6, ����������� ������������ � ���������� �������
				if (CheckAttribute(pchar, "questTemp.State.Open") && pchar.location == "Tortuga_tavern_upstairs")
				{
					if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
	    			{
	    				link.l1 = "�������� �� ����.";
	    				link.l1.go = "TalkSelf_room_day";
	    			}
	    			else
	    			{
	    				link.l1 = "�������� �� ����.";
	    				link.l1.go = "TalkSelf_room_night";
	    				link.l2 = "�������� �� ���������� ����.";
						link.l2.go = "TalkSelf_room_day";
	    			}
				}
			}
	        if (!bDisableMapEnter)//��� � ���� ���
	        {
	            if (GetCargoGoods(pchar, GOOD_SLAVES) > 0)
	            {
	                Link.l5 = "��������� ����� � �������";
	        		Link.l5.go = "TalkSelf_SlavesToCrew";
	    		}
	        }
	        // ������ ������
	        if (GetCharIDXForTownAttack(pchar.location) != -1 && !CheckAttribute(Pchar, "GenQuestFort.StartAttack") && !CheckAttribute(Pchar, "questTemp.Sharlie.DefendSP"))
	        {
	            Link.l6 = "������ ������ ���������� ������.";
	    		Link.l6.go = "TalkSelf_TownAttack";
	        }
	        if (!bDisableMapEnter && PChar.location != "Deck_Near_Ship" && pchar.location != Get_My_Cabin() && !CheckAttribute(pchar, "DisableChangeFlagMode") && !CheckAttribute(pchar, "GenQuest.CannotWait") && !CheckAttribute(pchar, "GenQuest.MapClosedNoBattle") && CheckSaveGameEnabled() == true)
			{
				Link.l7 = "������ ������ �� ����� �����.";
				Link.l7.go = "TalkSelf_ChangeFlag";
			}
			bool bSeaBattle = (bDisableMapEnter) && (bSeaActive) && (!CheckAttribute(pchar, "GenQuest.MapClosedNoBattle"));
	        if(!bSeaBattle && PChar.location != "Deck_Near_Ship" && findsubstr(PChar.location, "_shipyard" , 0) == -1 && PChar.location != "CommonPackhouse_2" && !CheckAttribute(pchar, "GenQuest.CannotWait")) 
	        {
	        	Link.l88 = "��� �� ������ �� ���������...";
	    		Link.l88.go = "TalkSelf_StartWait";
	    	}
			// ���������� ����
			if(CheckAttribute(pchar, "questTemp.GothicAPS_Coordinates") && PChar.location == Get_My_Cabin()) 
			{
				Link.l9 = "�������� ����������� ������� �� ����������� �� �����.";
				Link.l9.go = "Seek_GothicAPSIsland";
			}
			if(CheckAttribute(pchar, "questTemp.GothicSmithyBeliz_Coordinates") && PChar.location == Get_My_Cabin()) 
	    {
	    Link.l9 = "�������� ����������� ������� �� ����������� �� �����.";
	    Link.l9.go = "Seek_GothicSmithyBelizIsland";
	    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///									����������													&& (!CheckAttribute(pchar, "Komanda_gulaet")))
															///
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|///////////////////////////
			if (!bDisableMapEnter && PChar.location == Get_My_Cabin() && CheckAttribute(pchar, "Komanda_netrenit") ) //��� � ���� ���
			{
				if ( GetCharacterShipType(pchar)!=SHIP_NOTUSED )
				{
					Link.l99 = "������ �� ������������� ���� �������...";
					Link.l99.go = "Trening_crew";
				}
	    	}			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///									���� - ����� ��������� ��������																							///
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////|///////////////////////////
			//if (!bDisableMapEnter && PChar.location == Get_My_Cabin()) //��� � ���� ���
			//{
			//	if ( GetCharacterShipType(pchar)!=SHIP_NOTUSED )
			//	{
			//		Link.l201 = "���� �������. ������, ������� ����� ��� ��������, �������!";
			//		Link.l201.go = "Vualyaaa";
			//	}
	    	//}
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///									������������� �������																									///
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (!bDisableMapEnter && PChar.location == Get_My_Cabin() && CheckAttribute(pchar, "RazborkiNaKorable") )  //��� � ���� ���
			{
				if ( GetCharacterShipType(pchar)!=SHIP_NOTUSED )
				{
					Link.l300 = "����� ����� ���-�� ����������� �������?";
					Link.l300.go = "Motivaziya_komandi";
				}
	    	}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			///									�������������� �������																									///
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			if ((pchar.location.from_sea == GetCurrentTown() + "_town") && (!CheckAttribute(pchar, "Komanda_otdohnula")) && (!CheckAttribute(pchar, "Komanda_gulaet")))
			{
				if (GetCharacterShipType(pchar)!=SHIP_NOTUSED)  // tavern
				{
					Link.l353 = "����� ��������� �������� � ��������������?";
					Link.l353.go = "Uvolnits";
				}
	    	}
			
			if ((pchar.location.from_sea == GetCurrentTown() + "_town") && (CheckAttribute(pchar, "Komanda_otdohnula")) && (CheckAttribute(pchar, "Komanda_gulaet")))
			{
				if (GetCharacterShipType(pchar)!=SHIP_NOTUSED) 
				{
					Link.l353 = "���� �������� ������� � ��������!";
					Link.l353.go = "Sbori_go_1";
				}
	    	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			sGun = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				if(CheckAttribute(pchar, "chr_ai.bulletNum") && sti(pchar.chr_ai.bulletNum) > 1)
				{
					Link.l8 = "���� ������� ��� ���������� ��� �������������� ������.";
					Link.l8.go = "SetGunBullets";
				}	
			}
			
			Link.l14 = "���� ������� ��� ��������� ����� ��� ����������� ������������.";
			Link.l14.go = "ChoosePotion";
			
			//--> ����������� ������
			if(CheckAttribute(pchar, "questTemp.HWIC_Coordinates") && PChar.location == Get_My_Cabin()) 
	        {
	        	Link.l9 = "�������� ����������� ������� �� ����������� �� �����.";
	    		Link.l9.go = "Seek_AbyIsland";
	    	}
			//<-- ����������� ������
			
			//--> ������ ����
			if(CheckAttribute(pchar, "questTemp.FalseTrace") && pchar.questTemp.FalseTrace == "TalkCabin" && PChar.location == Get_My_Cabin()) 
	        {
	        	Link.l11 = "������� ����� �������.";
	    		Link.l11.go = "FalseTrace_Cabin";
	    	}
			if(CheckAttribute(pchar, "questTemp.FalseTrace") && pchar.questTemp.FalseTrace == "CatchAdam" && PChar.location == Get_My_Cabin()) 
	        {
	        	Link.l11 = "���������� ����� �������.";
	    		Link.l11.go = "FalseTrace_Cabin";
	    	}
			//<-- ������ ����
			// Addon 2016-1 Jason ��������� �������
			if(CheckAttribute(pchar, "questTemp.Mtraxx.Ammo") && PChar.location == "Shore37") // ������ 3
	        {
	        	Link.l15 = "����������� ���������� ������� � ������� ������� �� ��������� ����� �������� ��� ���� ������.";
	    		Link.l15.go = "mtraxx_ammo";
	    	}
			if(CheckAttribute(pchar, "questTemp.Mtraxx.Mutiny") && pchar.location == "Maracaibo_Plantation" && stf(environment.time) >= 3.00 && stf(environment.time) < 4.00) 
	        {
	        	Link.l15 = "������ ������ �� ����� �� ��������� ���������.";
	    		Link.l15.go = "mtraxx_mutiny";
	    	}
			if(CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "merida_boats" && pchar.location == "Maracaibo_river") 
	        {
	        	Link.l15 = "������ ������ � ��������� �����.";
	    		Link.l15.go = "mtraxx_boats";
	    	}
			if(CheckAttribute(pchar, "questTemp.Mtraxx.Retribution") && pchar.questTemp.Mtraxx.Retribution == "powder" && pchar.location == "shore10") 
	        {
	        	Link.l15 = "������ ������ � �������� ������ � ������.";
	    		Link.l15.go = "mtraxx_powder";
	    	}
			// Jason ����� � ���������
			if(CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "letter") 
	        {
	        	Link.l16 = "�������� �������.";
	    		Link.l16.go = "LH_marry";
	    	}
			if(CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "marry_offer" && LongHappy_CheckShore()) // 28-03-20
	        {
	        	Link.l16 = "������� ����������� ���� � ������.";
	    		Link.l16.go = "LH_marry_3";
	    	}
			if(CheckAttribute(pchar, "questTemp.LongHappy") && pchar.questTemp.LongHappy == "toIslaTesoro" && pchar.location == "Pirates_town") 
	        {
	        	Link.l16 = "����������� ��������.";
	    		Link.l16.go = "LH_marry_4";
	    	}
			// -->����������			
			if(Pchar.Location == Pchar.location.from_sea && CheckOfficersPerk(pchar, "SelfRepair") && CheckSelfRepairConditions()) 
			{
				Link.l12 = "������ ������ ��������";
				Link.l12.go = "StartSelfRepair";
			}			
			// <--����������
			//--> ���������� ����
			if(CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) // patch-9
	        {
	        	Link.l13 = "��������� ���� �� ������� � ����������� � ������.";
	    		Link.l13.go = "final_1";
	    	}
			//<-- ���������� ����
			
			/*
			if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd"))
			{
				link.l100 = "������ ����� ���� � ���� ����������.";
				
				//SharlieNpcInit();
				//Sharlie_onLand();
				/*
				sld = GetCharacter(NPC_GenerateCharacter("Mishelle", "Migel_1", "man", "man", 60, FRANCE, -1, false, "quest"));
				sld.name = "������";
				sld.lastname = "�� �����";
				sld.greeting = "Mishelle_1";
				sld.Dialog.Filename = "Quest\Sharlie\Mishelle.c";
				sld.dialog.currentnode = "First time";
				sld.rank = 60;
				SetSelfSkill(sld, 100, 100, 100, 100, 100);
				SetShipSkill(sld, 100, 100, 100, 100, 100, 100, 100, 100, 100);
				LAi_SetHP(sld, 700, 700);
				sld.PoisonResistent = true; // Addon 2016-1 Jason ��������� �������
				GiveItem2Character(sld, "unarmed");
				sld.equip.blade = "unarmed";
				sld.equip.gun = "";
				LAi_SetImmortal(sld, true);
				LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
				ChangeCharacterAddressGroup(sld, "FortFrance_Dungeon", "quest", "quest1");
				link.l100.go = "new";
				//link.l100.go="exit";
			}
			*/
			
			
			
			
			/*
			if (!CheckAttribute(pchar, "quest.barb")){
				link.l999 = "����������� ���������� � ������� ���������";
				sld = characterFromId("JanDavid");
				ChangeCharacterAddressGroup(sld, "LeFransua_townhallRoom", "sit", "sit2");
				pchar.quest.barb = "set";
				link.l999.go = "Exit";
			}
			*/
			
			
			
			
			if (!CheckAttribute(pchar, "quest.merch"))
			{	
				link.l904 = "test_apostates_begin";
				link.l904.go = "test_apostates"; 
				/*
				link.l905 = "characters";
				link.l905.go = "characters";
				link.l906 = "test_apostates_characters";
				link.l906.go = "test_apostates_characters";
				link.l907 = "locations_create";
				link.l907.go = "locations_create";
				link.l908 = "teleport_myxir";
				link.l908.go = "teleport_myxir";
				link.l909 = "init_items";
				link.l909.go = "init_items";
				link.l910 = "init_islands";
				link.l910.go = "init_islands";
				link.l911 = "init_colonies";
				link.l911.go = "init_colonies";
				link.l912 = "visible_providence";
				link.l912.go = "visible_providence";
				link.l913 = "init_worldmap";
				link.l913.go = "worldmap";
				// sld = characterFromId("FortOrange_usurer");
				// ChangeCharacterAddressGroup(sld, "FortOrange_Bank", "barmen", "stay");
				// LAi_SetOwnerType(sld);
				*/
			}
			
			
			

			// Sticks� --> [SticksMod] ������� 5
			//supportTeamType - 0, 1, 2 ... n ������� �������� ������������ ��������� ����� ���������
			if (CheckAttribute(pchar, "supportTeamType"))
			{
				// ���� ��� ������������ �������� "supportTeamType", ������ ���� �� ������� ������
				Link.l20 = RandPhraseSimple("������ ����� ���������� ���������� �����.", "����������� � ������ ����� ���, ������� �����.");
				Link.l20.go = "TalkSelf_RemoveSupportTeam";
			}
			else
			{	
				if (isShipInside(pchar.location)) // ���� �� �������
				{
					Link.l20 = RandPhraseSimple("������� ����� � ����� ������ �����...", "���, ���� � ���������, �� �������� ���� ������...");
					Link.l20.go = "TalkSelf_AddSupportTeam";
				}
			}
			// Sticks� <--
			Link.l10 = RandPhraseSimple("�� ������. ��� �������.", "�������. ���� ����.");
			Link.l10.go = "exit";
		break;
		/*
		case "visible_providence":
			dialog.text = "Ok."
			link.l1 = "...";
			link.l1.go = "exit";
			Islands[FindIsland("Providence")].visible = true;
			Islands[FindIsland("Providence")].reload_enable = true;
		break;
		*/
		case "test_apostates":
			dialog.text = "Ok."
			link.l1 = "...";
			link.l1.go = "exit";
			DoQuestCheckDelay("GothicApostates_of_the_faith", 0.5);
		break;
		/*
		case "worldmap":
			dialog.text = "Ok."
			link.l1 = "...";
			link.l1.go = "exit";
			if(LoadSegment("worldmap\worldmap_init.c"))
			{
				wdmInitWorldMap();
				UnloadSegment("worldmap\worldmap_init.c");
			}
		break;

		case "test_apostates_characters":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			BerglarsInit();
		break;
		
		case "locations_create":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			LocationInit();
		break;
		
		case "characters":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			CreateCharacters();
		break;
		
		case "teleport_myxir":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			sld = characterFromId("Myxir");
			ChangeCharacterAddressGroup(sld, "Temple_Trinidad_Inside_2", "reload", "reload7");
		break;
		
		case "init_items":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			if(LoadSegment("items\initItems.c"))
			{
				InitItems();
				UnloadSegment("items\initItems.c");
			}
		break;
		*/
		//--> ����� ���������� �������
		case "Seek_GothicSmithyBelizIsland":
		bOk = CheckCharacterItem(pchar, "bussol") && CheckCharacterItem(pchar, "clock2");
		bOk1 = CheckCharacterItem(pchar, "sextant2");
		bOk2 = CheckCharacterItem(pchar, "sextant3");
		if (bOk || bOk1 || bOk2)
		{
		DialogExit();
		DeleteAttribute(pchar, "questTemp.GothicSmithyBeliz_Coordinates");
		pchar.questTemp.GothicSmithyBeliz_FindIsland = "true";
		AddDialogExitQuestFunction("GothicSmithyBelizPrepareSearchingFor");
		}
		else
		{
		dialog.text = "��, � ���� ��� ����������� ������������� �������� ��� ����������� ������ � �������. ����. ������ ������� �������� ��������.";
		link.l1 = "";
		link.l1.go = "exit_bussol";
		}
		break;
		//<-- ����� ���������� �������
		
		case "init_islands":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			if(LoadSegment("islands\islands_init.c"))
			{
				InitIslands();
				UnloadSegment("islands\islands_init.c");
			}
		break;
		
		case "init_colonies":
			dialog.text = "Ok.";
			link.l1 = "...";
			link.l1.go = "exit";
			if(LoadSegment("Colonies\Colonies_init.c"))
			{
				InitColonies();
				UnloadSegment("Colonies\Colonies_init.c");
			}
		break;
		
		case "new":
				//Main();
				//Main_InitGame();
				//NewGame();
				NewGame_continue();
				link.l1.go = "exit";
		break;
		
		// ����� ���������� by xxxZohanxxx -->
		case "Cabin_PersonSelect":
				Dialog.Text = "���� ������?";
				if (!bDisableMapEnter && GetCompanionQuantity(PChar) > 1)
				{
    				link.l1 = "����������.";
    				link.l1.go = "Cabin_CompanionSelect";
				}	
				if (!bDisableMapEnter)
				{
					if (sti(pchar.Fellows.Passengers.navigator) != -1 || sti(pchar.Fellows.Passengers.boatswain) != -1 || sti(pchar.Fellows.Passengers.cannoner) != -1 || sti(pchar.Fellows.Passengers.doctor) != -1 || sti(pchar.Fellows.Passengers.treasurer) != -1 || sti(pchar.Fellows.Passengers.carpenter) != -1)
					{
					link.l2 = "�������.";
    				link.l2.go = "Cabin_OfficerSelect";	
					}					
				}
				if (!bDisableMapEnter && GetPassengersQuantity(PChar) > 1)
				{				
					link.l3 = "���������.";
    				link.l3.go = "Cabin_PassengerSelect";	
				}	
			link.l4 = "� ������ ���.";
			link.l4.go = "exit";				
		break;
		// <-- ����� ���������� by xxxZohanxxx	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////����������� ���������� /////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		case "Vualyaaa":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			DoQuestReloadToLocation(pchar.location + "", "rld", "loc1", "Ei_detka_privet");
		break;		
		
		case "Trening_crew":
			Dialog.Text = "����� ������������� ���� ������� � ��� ����� ������������������ � ������ � ��� ��� ���� �������. ���������� ������, ��� ���� ����������� �������� �� ���� ������ ��� �������� � ��������� ������, ������ ������� � ������ �� ������.";
			Link.l1 = "����� ���������� ������� �������! (����������� ������ ��������, �� ��� ���� ��������� ������. �� ���������� � ������������� ������� ���� ����� 8 �����)";
			Link.l1.go = "Trening_crew_SEA";
			Link.l2 = "����� �������������� ������ �������� ���! ��� ������� ������� � ��������� �������� ������� � ������� ������� ��� ����� ����������! (����������� ������ ������, �� ��� ���� ��������� ������. �� ���������� � ������������� ������� ���� ����� 8 �����)";
			Link.l2.go = "Trening_crew_WAR";
			Link.l3 = "����� ������ ������ ��������,  ��������� � �������� ������! � ������� ��� ���� ������ � ������� ��������� ������� ����� ������ ����� ��������! (����������� ������ ���������, �� ��� ���� ��������� ������. �� ���������� � ������������� ������� ���� ����� 8 �����)";
			Link.l3.go = "Trening_crew_CAN";			
			Link.l4 = "����, ������ � ��� �� ���� ��������� �����������.";
			Link.l4.go = "exit";
		break;
		
		case "Trening_crew_SEA":
		AddCharacterExpToSkill(PChar, "Leadership", 200); 
		AddCharacterExpToSkill(PChar, "Sailing", 1000); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			ChangeCrewExp(pchar, "Sailors", 10 + rand(5));
			AddCrewMorale(pchar, -30);
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			PChar.GenQuest.VideoAVI = "Tr_crew";
			PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
			DoQuestCheckDelay("PostVideo_Start", 0.2);
			WaitDate("", 0, 0, 0, 7 + rand(3), 0); //������ �����
			Log_info("������ ��������� �����... ���� ������� ������.");
	SetTimerCondition("Komanda_trenit", 0, 0, 0, false);
		break;
		
		case "Trening_crew_CAN":
		AddCharacterExpToSkill(PChar, "Leadership", 200); 
		AddCharacterExpToSkill(PChar, "Accuracy", 500); 
		AddCharacterExpToSkill(PChar, "Cannons", 500); 
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			ChangeCrewExp(pchar, "Cannoners", 10 + rand(5));
			AddCrewMorale(pchar, -30);
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			PChar.GenQuest.VideoAVI = "Tr_crew";
			PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
			DoQuestCheckDelay("PostVideo_Start", 0.2);
			WaitDate("", 0, 0, 0, 7 + rand(3), 0); //������ �����
			Log_info("������ ��������� �����... ���� ������� ����� ������.");
	SetTimerCondition("Komanda_trenit", 0, 0, 0, false);
		break;
		
		case "Trening_crew_WAR":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			ChangeCrewExp(pchar, "Soldiers", 10 + rand(5));
		AddCharacterExpToSkill(PChar, "Leadership", 200); 
		AddCharacterExpToSkill(PChar, "Grappling", 500); 
		AddCharacterExpToSkill(PChar, "Defence", 500); 
			AddCrewMorale(pchar, -30);
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			PChar.GenQuest.VideoAVI = "Tr_crew";
			PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
			DoQuestCheckDelay("PostVideo_Start", 0.2);
			WaitDate("", 0, 0, 0, 7 + rand(3), 0); //������ �����
			Log_info("������ ��������� �����... ���� ������� ������ ������.");
SetTimerCondition("Komanda_trenit", 0, 0, 0, false);
		break;
		
		case "Motivaziya_komandi":
			Dialog.Text = "��� �� �����������?";
			Link.l1 = "����� ��������� � �����, �������� ������� ���������, ����� ���� � ��������� ����� � ������� �����, � ����� ����� ������� � ������� ����� (��������� ������ � ���������). �� ��� ����� ��� ����� ���� ����������� ������������. (��� ������ ��������� ������ ����������� ����� �������)";
			Link.l1.go = "Motivaziya_komandi_rech";
			Link.l2 = "����� �������� ������� ������� ��� ������� (��������� ������ � ���������). ��� ����� ����������� ��������� ���� �������� ��������.";
			Link.l2.go = "Motivaziya_komandi_eda";
			Link.l3 = "����������� �� ���� ������� ����� ������ �������. ����� ����� ����������� � ���-������ �� ��������, ��� ������� �������� ���������� � �������, � ����� ��������� �� ��� ����� ����������. �������, ������� ������ ����� ���������� � ������������������. � �� ������ ������������.";
			Link.l3.go = "Motivaziya_komandi_boi";
			Link.l5 = "�������, �� ������, ��� ��� ������� � ������ ������.";
			Link.l5.go = "exit";
		break;
		
		case "Uvolnits":
			Dialog.Text = "���� � ������ ��������, �� ����� ����� ����� � ���� �� ������ ��� ����� �����...";
			Link.l1 = "�����, ��� ��� ����� ������ ������, ��� ����� � ������ �� ���������.";
			Link.l1.go = "Uvolnits_go_1";			
			// Link.l2 = "�� ���� �����. ����� �� ������ �������, ����� ����������.";
			// Link.l2.go = "Uvolnits_go_2";
			// Link.l3 = "�� ���� �����. ����� ����������� � ������ ��������� ������.";
			// Link.l3.go = "Uvolnits_go_3";
			Link.l4 = "����, ����� � ��� �� �������. �� ����� ��������� �� � �������.";
			Link.l4.go = "exit";
		break;
		
		case "Uvolnits_go_1":
			Log_info("������� ���������� � ��������������...");
			SetTimerCondition("Otgul_matrosov", 0, 0, 1, false);
			LocatorReloadEnterDisable(GetCurrentTown() + "_town", "reload1_back", true);
			pchar.Komanda_gulaet = true;
			PlaySound("interface\Goods.wav");
			DialogExit_Self();
			ChangeCharacterComplexReputation(pchar, "authority", 10);
			AddCrewMorale(pchar, 5);
		ChangeCrewExp(pchar, "Cannoners", -2 - rand(3));
			ChangeCrewExp(pchar, "Soldiers", -2 - rand(3));
			ChangeCrewExp(pchar, "Sailors", -2 - rand(3));
		break;
		
		case "Sbori_go_1":
			Log_info("������� ������������ �� �������.");
			LocatorReloadEnterDisable(GetCurrentTown() + "_town", "reload1_back", false);
		DeleteAttribute(pchar, "Komanda_otdohnula");
		DeleteAttribute(pchar, "Komanda_gulaet");
		pchar.quest.Otgul_matrosov_poka_na_susche.over = "yes";
		pchar.quest.Otgul_matrosov.over = "yes";
		DialogExit_Self();
		break;
/*		
		case "Uvolnits_go_2":
			Log_info("������� ���������� � �������������� �� 2 ���.");
			SetTimerCondition("Otgul_matrosov", 0, 0, 2, false);
			LocatorReloadEnterDisable(pchar.location, "reload1_back", true);
			DeleteAttribute(pchar, "Komanda_v_otgule")
			PlaySound("interface\abordage_wining.wav");
			DialogExit_Self();
			ChangeCharacterComplexReputation(pchar, "authority", 30);
			AddCrewMorale(pchar, 10);
		break;
		
		case "Uvolnits_go_3":
			Log_info("������� ���������� � �������������� �� 3 ���.");
			SetTimerCondition("Otgul_matrosov", 0, 0, 3, false);
			LocatorReloadEnterDisable(pchar.location, "reload1_back", true);
			DeleteAttribute(pchar, "Komanda_v_otgule")
			PlaySound("interface\abordage_wining.wav");
			DialogExit_Self();
			ChangeCharacterComplexReputation(pchar, "authority", 35);
			AddCrewMorale(pchar, 15);
		break;
*/		
		case "Motivaziya_komandi_rech":
			int iCumShot;
			iCumShot = (((((GetSummonSkillFromName(pchar, SKILL_LEADERSHIP)))+(GetSummonSkillFromName(pchar, SKILL_FORTUNE))) / ((GetCrewQuantity(pchar))+1 )) +2);
			if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) > (drand(100) + 10 ) ) // ������� ������
			{
	NextDiag.CurrentNode = NextDiag.TempNode;
	DialogExit_Self();
	DoQuestCheckDelay("Motivaziya_komandi_rech_UDACHNO", 1.0);
	WaitDate("", 0, 0, 0, 1 + rand(1), 0); //������ �����
	Log_info("��� ������� ����������� �������!");
	ChangeOfficersLoyality("good_all", 2);
	AddCrewMorale(pchar, 30);
	AddCharacterExpToSkill(PChar, "Leadership", 1200); 
	ChangeCharacterComplexReputation(pchar, "authority", 20);	
	DeleteAttribute(pchar, "RazborkiNaKorable");
	pchar.RazborkiNaKorable = false;
	SetTimerCondition("NETRazborkiNaKorable", 0, 0, 0, false);
			}
			else
			{
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit_Self();
DoQuestCheckDelay("Motivaziya_komandi_rech_NE_UDACHNO", 1.0);
WaitDate("", 0, 0, 0, 1 + rand(1), 0); //������ �����
Log_info("������ ��� �� ������� ����������� �������...");
ChangeOfficersLoyality("bad_all", 2)
AddCrewMorale(pchar, -30);
AddCharacterExpToSkill(PChar, "Leadership", 500); 
ChangeCharacterComplexReputation(pchar, "authority", -20);	
DeleteAttribute(pchar, "RazborkiNaKorable");
pchar.RazborkiNaKorable = false;
SetTimerCondition("NETRazborkiNaKorable", 0, 0, 0, false);
			}
		break;
		
		case "Motivaziya_komandi_eda":
			Dialog.Text = "��� �� �������� ��� �� ������� ��� �����������: ����� (1 ������� �� 3 ������� �������), ���� (1 ������� �� 3 ������� �������), ���� (1 ������� �� 10 ������� �������), ��� (1 ������� �� 10 ������� �������), ����� (1 ������� �� 15 ������� �������), ������ (1 ������� �� 20 ������� �������).";
			Link.l2 = "������� ������� ����� ������� �������� ������� �� ���� �����������.";
			Link.l2.go = "exit";			
			if (GetCargoGoods(pchar, GOOD_VEGETABLES ) > (GetCrewQuantity(pchar) / 3) && GetCargoGoods(pchar, GOOD_FISH) > (GetCrewQuantity(pchar) / 3) && GetCargoGoods(pchar, GOOD_WINE) > (GetCrewQuantity(pchar) / 10) && GetCargoGoods(pchar, GOOD_ALE) > (GetCrewQuantity(pchar) / 10) && GetCargoGoods(pchar, GOOD_TOBACCO) > (GetCrewQuantity(pchar) / 15) && GetCargoGoods(pchar, GOOD_FRUITS) > (GetCrewQuantity(pchar) / 20) )
			{
				Link.l1 = "��� ����� �������� ���!";
				Link.l1.go = "Motivaziya_komandi_PRAZDNIK";
			}
		break;		
		
		case "Motivaziya_komandi_PRAZDNIK":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			DoQuestCheckDelay("Motivaziya_komandi_PRAZDNIK_go", 1.0);
			WaitDate("", 0, 0, 0, 5 + rand(3), 0); //������ �����
	Log_info("������, ��� ������� ������� �� �����!");
			ChangeOfficersLoyality("good_all", 10);
			AddCrewMorale(pchar, (drand(15)+5));
			ChangeCharacterComplexReputation(pchar, "authority", 30);		
			AddCharacterExpToSkill(PChar, "Leadership", 900); // ������� ���������� 	
			RemoveCharacterGoods(pchar, GOOD_VEGETABLES, (GetCrewQuantity(pchar) / 3) )
			RemoveCharacterGoods(pchar, GOOD_FISH, (GetCrewQuantity(pchar) / 3) )
			RemoveCharacterGoods(pchar, GOOD_WINE, (GetCrewQuantity(pchar) / 10) )
			RemoveCharacterGoods(pchar, GOOD_ALE, (GetCrewQuantity(pchar) / 10) )
			RemoveCharacterGoods(pchar, GOOD_TOBACCO, (GetCrewQuantity(pchar) / 15) )
			RemoveCharacterGoods(pchar, GOOD_FRUITS, (GetCrewQuantity(pchar) / 20) )		
			DeleteAttribute(pchar, "RazborkiNaKorable");
			pchar.RazborkiNaKorable = false;
	SetTimerCondition("NETRazborkiNaKorable", 0, 0, 0, false);
	SetTimerCondition("Netotjig_v_taverne_2", 0, 0, 0, false);
		break;			
		

		case "Motivaziya_komandi_boi":
			// NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			pchar.GenQuest.Boismatrosom = "true"; ////////////////////// �����!!!
	DoQuestCheckDelay("Motivaziya_komandi_boi_go", 1.0);
	WaitDate("", 0, 0, 0, 1 + rand(2), 0); //������ �����
		break;
		
		
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		// Sticks� --> [SticksMod] ������� 6
		case "TalkSelf_AddSupportTeam":
			Dialog.Text = "���� ������.";
			if (GetCharacterShipClass(pchar) == 6)
			{
				Link.l1 = "�� ����� ������ ����� ����� �� �������, �������� ��������.";
				Link.l1.go = "SupportTeamCansel";
			}
			else
			{
				if (GetCrewQuantity(pchar) > 3)
				{
					Link.l1 = "������� ���������������� ������ �� 3 �������.";
					Link.l1.go = "AddSupportTeam_3x";
				}
				
				if (GetCrewQuantity(pchar) > 6)
				{
					Link.l2 = "������� �������������� ����� �� 6 �������.";
					Link.l2.go = "AddSupportTeam_6x";
				}
				
				if (GetCrewQuantity(pchar) > 9)
				{
					Link.l3 = "������� ����������� ����� �� 9 �������.";
					Link.l3.go = "AddSupportTeam_9x";
				}
				
				if (GetCrewQuantity(pchar) > 5)
				{
					Link.l4 = "������� ����� �� 5 ��������.";
					Link.l4.go = "AddSupportTeam_5x";
				}
				
				Link.l5 = "���������!";
				Link.l5.go = "SupportTeamCansel";
			}

		break;
		case "TalkSelf_RemoveSupportTeam":
			DeleteAttribute(pchar, "supportTeamType"); // ��� �� �������, � ��������� 0
			SM_RemoveSupportTeam();
			DialogExit_Self();
		break;
		case "AddSupportTeam_3x":
			pchar.supportTeamType = 1;
			SM_AddSupportTeam(2, 1);
			DialogExit_Self();
		break;
		case "AddSupportTeam_6x":
			pchar.supportTeamType = 2;
			SM_AddSupportTeam(4, 2);
			DialogExit_Self();
		break;
		case "AddSupportTeam_9x":
			pchar.supportTeamType = 3;
			SM_AddSupportTeam(6, 3);
			DialogExit_Self();
		break;
		case "AddSupportTeam_5x":
			pchar.supportTeamType = 4;
			SM_AddSupportTeam(0, 5);
			DialogExit_Self();
		break;
		case "SupportTeamCansel":
			DialogExit_Self();
		break;

		// Sticks� <--
		
		case "StartSelfRepair":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			LaunchRepair(pchar);
		break;
		
		case "SetGunBullets":
			Dialog.Text = "����� ���� ���������� :";
			sGun = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(pchar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;
		
		case "SetGunBullets2":
			i = sti(PChar.GenQuest.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(pchar, sBullet);
			LAi_GunSetUnload(pchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(pchar,"GenQuest.SetGunBullets");
			DialogExit_Self();
		break;
		
		//--> ���������� ����
		case "Seek_GothicAPSIsland":
		bOk = CheckCharacterItem(pchar, "bussol") && CheckCharacterItem(pchar, "clock2");
		bOk1 = CheckCharacterItem(pchar, "sextant2");
		bOk2 = CheckCharacterItem(pchar, "sextant3");
		if (bOk || bOk1 || bOk2)
		{
		DialogExit();
		DeleteAttribute(pchar, "questTemp.GothicAPS_Coordinates");
		pchar.questTemp.GothicAPS_FindIsland = "true";
		AddDialogExitQuestFunction("GothicAPSPrepareSearchingFor");
		}
		else
		{
		dialog.text = "��, � ���� ��� ����������� ������������� �������� ��� ����������� ������ � �������. ����. ������ ������� �������� ��������.";
		link.l1 = "";
		link.l1.go = "exit_bussol";
		}
		break;
		
		case "GothicApostates_spSolddialog":
			 PlaySound("VOICE\Russian\Chaos.wav");
			 dialog.text = "����� ����� �������������� � ��� ������ �� ������ ������ ���������, ���� ��������������...";
			 link.l1 = "...";
			 link.l1.go = "GothicApostates_spSolddialog1";
		break;

		case "GothicApostates_spSolddialog1":
			 dialog.text = "� ��� ��� ���� ������, ���������� ������������� � ����� �����������...";
			 link.l1 = "...";
			 link.l1.go = "Exit";
			 AddDialogExitQuest("GothicApostates_APS_Burn");
		break;

		case "GothicApostates_dialog":
			PlaySound("VOICE\Russian\Serve_senior.wav");
			dialog.text = "��� ���� ������� ������, ������ ��������������� �������, ���� ��������������...";
			link.l1 = "...";
			link.l1.go = "GothicApostates_dialog1";
		break;
			
		case "GothicApostates_dialog1":
			dialog.text = "" + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ", �� ����� ���������, ��� �������� �������� ��������� ������������ �� ����������! � ���� �� �������� ����������� �������, �������� ����������� �������. \n� ��� ������ ���� � ������ ��������� ��������� ��������� �� ��������� � ������� � ������� ��������. �������, ��� �� ������������ ���������� ��� �����, ��� ���������� ������ �������.";
			link.l1 = "...";
			link.l1.go = "GothicApostates_dialog2";
		break;
			
		case "GothicApostates_dialog2":
			dialog.text = "� ���, ����� ���� ������ ������ �� ���������? ���� �������� ������� '����������' ���� �����!";
			link.l1 = "...";
			link.l1.go = "GothicApostates_dialog3";
		break;
			
		case "GothicApostates_dialog3":
			dialog.text = "��� ������������ ������� �����, ��� ��������� ���� �� ���� ��������, ������� ��� � ����� ������ ���� ���������� �����. �� ���� � ���� ������������� � ��� �������������������, ������������. \n�� ���� ���������, �������, ������� ����������� ��� ��������, ����� �������� ������� � ��������� ��� ��� ������ � ������ ����� �����. ���� ������, ��� ����������� ���������� ���� � �������� �������� ���������� � ���.";
			link.l1 = "...";
			link.l1.go = "GothicApostates_dialog4";
		break;
			
		case "GothicApostates_dialog4":
			dialog.text = "���������� �����������, ���� ��������������������.";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("GothicApostates_APSChurch_8");
		break;
			
		case "GothicApostates_APS_dialogNI":
			dialog.text = "� ������ 2 000 ����, ��� �� � ��������������. ������ � ���� �������� � ���� ���������� � ��������e ��������.";
			link.l1 = "��� �������, ������! � �����, ��� ���������� �� �������� �� ������ ��� � ����� ���������...";
			link.l1.go = "Exit";
			AddDialogExitQuest("GothicApostates_APS_NIdialog2");
		break;
		
		//<-- ���������� ����
		
		case "ChoosePotion":
			Dialog.Text = "";
	    	Link.l1 = "�������� ��������.";
	    	Link.l1.go = "ChoosePotion1";
			Link.l2 = "�������.";
	    	Link.l2.go = "ChoosePotion2";
			Link.l3 = "��������.";
	    	Link.l3.go = "ChoosePotion3";
			Link.l4 = "�������� ������.";
	    	Link.l4.go = "ChoosePotion4";
			Link.l5 = "���.";
	    	Link.l5.go = "ChoosePotion5";
			Link.l6 = "����.";
	    	Link.l6.go = "ChoosePotion6";
			if (CheckAttribute(pchar, "GenQuest.Potion_choice"))
			{
				Link.l7 = "���� �������� �������������.";
				Link.l7.go = "ChoosePotion7";
			}
			Link.l8 = "����, � ���������.";
	    	Link.l8.go = "ChoosePotion8";
		break;
		
		case "ChoosePotion1":
			log_info("�� ��������� ����� �������������� ����� ''�������� ��������''");
			pchar.GenQuest.Potion_choice = "potion1";
			DialogExit_Self();
		break;
		
		case "ChoosePotion2":
			log_info("�� ��������� ����� �������������� ����� ''�������''");
			pchar.GenQuest.Potion_choice = "potion2";
			DialogExit_Self();
		break;
		
		case "ChoosePotion3":
			log_info("�� ��������� ����� �������������� ����� ''��������''");
			pchar.GenQuest.Potion_choice = "potion4";
			DialogExit_Self();
		break;
		
		case "ChoosePotion4":
			log_info("�� ��������� ����� �������������� ����� ''�������� ������''");
			pchar.GenQuest.Potion_choice = "potion5";
			DialogExit_Self();
		break;
		
		case "ChoosePotion5":
			log_info("�� ��������� ����� �������������� ����� ''���''");
			pchar.GenQuest.Potion_choice = "potionrum";
			DialogExit_Self();
		break;
		
		case "ChoosePotion6":
			log_info("�� ��������� ����� �������������� ����� ''����''");
			pchar.GenQuest.Potion_choice = "potionwine";
			DialogExit_Self();
		break;
		
		case "ChoosePotion7":
			log_info("�������� ����� ����� ���������� �������������");
			DeleteAttribute(pchar, "GenQuest.Potion_choice");
			DialogExit_Self();
		break;
		
		case "ChoosePotion8":
PlaySound("VOICE\Russian\gotica\GG\KNOWWHEREENEMY_NO.wav");
			DialogExit_Self();
		break;
		
		case "TalkSelf_StartWait":
	PlaySound("VOICE\Russian\gotica\GG\SCHLAFEN_00.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			PChar.GenQuest.CallFunctionParam = "LaunchTavernWaitScreen";
			DoQuestCheckDelay("CallFunctionParam", 0.1); // ����� � ���������, ����� - �� �������� ���������
		break;
		
		case "TalkSelf_room_night":
			NextDiag.CurrentNode = NextDiag.TempNode;
			//AddDialogExitQuestFunction("TavernWaitDate_Night");
			TavernWaitDate("wait_night");
			DialogExit_Self();
		break;

		case "TalkSelf_room_day":
			NextDiag.CurrentNode = NextDiag.TempNode;
			//AddDialogExitQuestFunction("TavernWaitDate_Day");
			TavernWaitDate("wait_day");
			DialogExit_Self();
		break;
		//  ������ ������
		case "TalkSelf_TownAttack":
            bOk = (GetPartyCrewQuantity(Pchar, true) >= 500) || bBettaTestMode;
			if (sti(Pchar.Ship.Type) != SHIP_NOTUSED && bOk)
	        {
	            chr = GetCharacter(GetCharIDXForTownAttack(pchar.location));
	            if (chr.from_sea == Pchar.location.from_sea)
	            {
					Dialog.Text = "������ ������, �������, �����, �� ��� ������ ������� ��� ������� ����� ����� �� �����������. � ������ �������� �� ������.";
	    			Link.l1 = "...";
	    			Link.l1.go = "exit";
	            }
	            else
	            {
	                if (pchar.location == "Panama_ExitTown" || pchar.location == "Tortuga_ExitTown") // patch-5
					{
						Dialog.Text = "��-�-��, � �� �����������. ����� ���� ����� � ���� ����������...";
	    				Link.l1 = "...";
	    				Link.l1.go = "exit";
					}
					else
					{
						if (pchar.location == "Minentown_ExitTown")
						{
							Dialog.Text = "��� ������ ��������� ���� ������ ��� ����������� �������� � ��������� �� ��� ������ � �������. ������ �������� ����� ������ ��� ��� �������...";
							Link.l1 = "...";
							Link.l1.go = "exit";
						}
						else
						{
							Dialog.Text = "������� �� ����� " + GetCityName(chr.City) + ".";
							if (CheckAttribute(pchar, "questTemp.Patria.SanJoseAttack") && pchar.location == "PortSpein_ExitTown") // Jason ���
							{
								Link.l1 = "������ ���������� ����������! ���������!";
								Link.l1.go = "exit";
								break;
							}
							if (CheckAttribute(pchar, "questTemp.Patria")) // Jason ���
							{
								if (pchar.questTemp.Patria != "fail" || pchar.questTemp.Patria != "complete")
								{
									if (pchar.location == "Marigo_ExitTown" || pchar.location == "Villemstad_ExitTown")
									{
										Link.l1 = "������ ���������� ����������! ���������!";
										Link.l1.go = "exit";
										break;
									}
								}
							}
							Link.l1 = "� ������!";
							Link.l1.go = "TalkSelf_TownAttack_Start";
							Link.l2 = "���������!";
							Link.l2.go = "exit";
						}
	    		}
	        }
	        }
	        else
	        {
				if(!CheckAttribute(Pchar, "GenQuestFort.StartAttack"))
				{
					Dialog.Text = "��! ������� ��������, ����� ���� �� 500 �������.";
					Link.l1 = "...";
					Link.l1.go = "exit";
				}
				else
				{
					Dialog.Text = "�� ������������! ���������� �����!";
					Link.l2 = "...";
					Link.l2.go = "exit";				
				}			
			}
	    break;

		case "TalkSelf_TownAttack_Start":
	        NextDiag.CurrentNode = NextDiag.TempNode;

			Pchar.GenQuestFort.StartAttack = true;
		    Pchar.GenQuestFort.fortCharacterIdx = GetCharIDXForTownAttack(pchar.location);
		    DeleteQuestAttribute("Union_with_Escadra");
	        chr = GetCharacter(sti(Pchar.GenQuestFort.fortCharacterIdx));
			if (isCityHasFort(chr.City))
			{
	        	SetLocationCapturedState(chr.from_sea, true);
	        }
	        else
	        {
	            SetLocationCapturedState(chr.Default, true); // ��� ����������
	        }
	        AddDialogExitQuest("Capture_Forts");
	        Ship_NationAgressive(chr, chr);
	        DialogExit_Self();
	    break;
	    // ��������� ����� � �������  -->
		case "TalkSelf_SlavesToCrew":
	        if (GetCurCrewEscadr() >= GetMaxCrewAble())
	        {
	            Dialog.Text = "����� �� ����� �� ����� ���� � �������.";
	            Link.l1 = "�� � �� �����!";
	    		Link.l1.go = "exit";
	        }
	        else
	        {
	            if (GetCrewQuantity(pchar) >= GetMaxCrewQuantity(pchar))
	            {
	                Dialog.Text = "�� ������� ��� ����� ��� ����� ��������.";
	                Link.l1 = "��! ����� ����������� ����� ������� �� ������ �������.";
	        		Link.l1.go = "exit";
	            }
	            else
	            {
	                if (GetFreeCrewQuantity(pchar) <= GetCargoGoods(pchar, GOOD_SLAVES))
	                {
	                    pchar.GenQuest.SlavesToCrew = GetFreeCrewQuantity(pchar);
	                }
	                else
	                {
	                    pchar.GenQuest.SlavesToCrew = GetCargoGoods(pchar, GOOD_SLAVES);
	                }
	                Dialog.Text = "� ������� ������ ����� " + pchar.GenQuest.SlavesToCrew+ " �����. ����� ��?";
	                Link.l1 = "��";
	        		Link.l1.go = "TalkSelf_SlavesToCrew_1";
	        		Link.l2 = "���";
	        		Link.l2.go = "exit";
	    		}
			}
		break;

		case "TalkSelf_SlavesToCrew_1":
	        if (CheckOfficersPerk(pchar, "IronWill"))
	        {
	            AddCrewMorale(pchar, -makeint(sti(pchar.GenQuest.SlavesToCrew) / 5.0))
	        }
	        else
	        {
	            AddCrewMorale(pchar, -makeint(sti(pchar.GenQuest.SlavesToCrew) / 3.0))
	        }
			ChangeCharacterComplexReputation(pchar,"authority", -0.5);
	        // ������� ����� -->
	        fTemp =  stf(GetCrewQuantity(pchar) + sti(pchar.GenQuest.SlavesToCrew));
	        pchar.Ship.Crew.Exp.Sailors   = (stf(pchar.Ship.Crew.Exp.Sailors)*GetCrewQuantity(pchar) + 
			                                        stf(pchar.Ship.Crew.Exp.Sailors)*0.3*sti(pchar.GenQuest.SlavesToCrew)) / fTemp;
			pchar.Ship.Crew.Exp.Cannoners   = (stf(pchar.Ship.Crew.Exp.Cannoners)*GetCrewQuantity(pchar) + 
			                                        stf(pchar.Ship.Crew.Exp.Cannoners)*0.3*sti(pchar.GenQuest.SlavesToCrew)) / fTemp;
			pchar.Ship.Crew.Exp.Soldiers   = (stf(pchar.Ship.Crew.Exp.Soldiers)*GetCrewQuantity(pchar) + 
			                                        stf(pchar.Ship.Crew.Exp.Soldiers)*0.3*sti(pchar.GenQuest.SlavesToCrew)) / fTemp;
			// ������� ����� <-- 
			pchar.Ship.Crew.Quantity = sti(pchar.Ship.Crew.Quantity) + sti(pchar.GenQuest.SlavesToCrew); 
	        RemoveCharacterGoodsSelf(pchar, GOOD_SLAVES, sti(pchar.GenQuest.SlavesToCrew));       
			                            
	        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
		break;
		// ��������� ����� � �������  <--
		// boal <--

//navy CONTRABAND METRO -->
		case "GenTravel_Main":
			NextDiag.TempNode = "First time";
			dialog.Text = "������ ���� �������� ������� ���, � � ����� �������! ����, �������� �������� ��� �������.";
			Link.l1 = "���� �� �����...";
			Link.l1.go = "exit";

			chr = CharacterFromID("Abracham_Gray");
			chr.location = "none";
			SeaExchangeCharactersShips(PChar, chr, false, false);
			SetCrewQuantity(PChar, 0);

			//������ �� ���� �����...
			SetAnyReloadToLocation(pchar.GenQuest.contraTravel.destination.loc, pchar.GenQuest.contraTravel.destination.group, pchar.GenQuest.contraTravel.destination.locator, "", 0, 0, 0, 0);
			AddDialogExitQuest("AnyReloadToLocation");
            chrDisableReloadToLocation = false;
            
			CloseQuestHeader("Gen_ContrabandTravel");
			setCharacterShipLocation(PChar, pchar.GenQuest.contraTravel.destination.loc);
			setWDMPointXZ(pchar.GenQuest.contraTravel.destination.loc);

			//���� ���������
			DeleteAttribute(PChar, "GenQuest.contraTravel");
			break;
//navy CONTRABAND METRO <--

//navy --> 13.02.08
		case "Cabin_CompanionSelect":
			Dialog.Text = "���� �� ����������� �������?";
			for (i = 1; i < GetCompanionQuantity(PChar); i++)
			{
				chr = GetCharacter(GetCompanionIndex(PChar, i));
				if (!CheckAttribute(chr, "Tasks.Clone") && sti(chr.Payment) == true)
				{
					sAttr = "l" + i;
					rShip = GetRealShip(sti(chr.Ship.Type));
					link.(sAttr) = GetFullName(chr) + " - " + xiStr(rShip.BaseName) + " ''" + chr.Ship.Name + "''.";
					link.(sAttr).go = "CabinCompanionTalk_" + i;
				}
			}
			link.l9 = "� ������ ���.";
			link.l9.go = "exit";
			break;

	// ����� ���������� by xxxZohanxxx -->			
		case "Cabin_OfficerSelect":
			Dialog.Text = "���� �� �������� �������?";
			if (sti(pchar.Fellows.Passengers.navigator) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
				if (chr.location != Get_My_Cabin())
				{	
				link.l1 = "������� " + GetFullName(chr) + ".";
				link.l1.go = "Cabin_navigator_Talk";
				}
			}
			if (sti(pchar.Fellows.Passengers.boatswain) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
				if (chr.location != Get_My_Cabin())
				{
				link.l2 = "������ " + GetFullName(chr) + ".";
				link.l2.go = "Cabin_boatswain_Talk";
				}
			}
			if (sti(pchar.Fellows.Passengers.cannoner) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
				if (chr.location != Get_My_Cabin())
				{				
				link.l3 = "������� " + GetFullName(chr) + ".";
				link.l3.go = "Cabin_cannoner_Talk";
				}
			}
			if (sti(pchar.Fellows.Passengers.doctor) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
				if (chr.location != Get_My_Cabin())
				{				
				link.l4 = "���� " + GetFullName(chr) + ".";
				link.l4.go = "Cabin_doctor_Talk";
				}
			}
			if (sti(pchar.Fellows.Passengers.treasurer) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
				if (chr.location != Get_My_Cabin())
				{				
				link.l5 = "�������� " + GetFullName(chr) + ".";
				link.l5.go = "Cabin_treasurer_Talk";
				}
			}
			if (sti(pchar.Fellows.Passengers.carpenter) != -1)
			{
				chr = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
				if (chr.location != Get_My_Cabin())
				{				
				link.l6 = "������� " + GetFullName(chr) + ".";
				link.l6.go = "Cabin_carpenter_Talk";
				}
			}			
			link.l7 = "� ������ ���.";
			link.l7.go = "exit";
			break;				
			
		case "Cabin_PassengerSelect":
			Dialog.Text = "���� �� ���������� �������?";
			for (i = 1; i < GetPassengersQuantity(PChar); i++)
			{
				chr = GetCharacter(GetPassenger(PChar,i));	
					if (!CheckAttribute(chr,"prisoned") && !IsOfficer(chr) && GetRemovable(chr) && chr.location != Get_My_Cabin() && !CheckAttribute(chr, "isfree")) // ����� � ������ �� �������� ���������, ������� � ��������
					{
						sAttr = "l" + i;
						link.(sAttr) = GetFullName(chr) + ".";
						link.(sAttr).go = "CabinPassengerTalk_" + i;
					}
			}
			link.l99 = "� ������ ���.";
			link.l99.go = "exit";
			break;	

		case "Cabin_navigator_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.navigator));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;
		case "Cabin_boatswain_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.boatswain));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;			
		case "Cabin_cannoner_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.cannoner));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;				
		case "Cabin_doctor_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.doctor));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;			
		case "Cabin_treasurer_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.treasurer));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;		
		case "Cabin_carpenter_Talk":
			chr = GetCharacter(sti(pchar.Fellows.Passengers.carpenter));
			PlaceCharacter(chr, "rld", PChar.location);
			DialogExit_Self();
		break;	
		
		case "Cabin_Passenger_Talk":
			i = sti(PChar.GenQuest.CabinPassengerNum);
			chr = GetCharacter(GetPassenger(PChar,i));
			PlaceCharacter(chr, "rld", PChar.location);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
		break;
// <-- ����� ���������� by xxxZohanxxx	

		case "Cabin_Companion_Talk":
			i = sti(PChar.GenQuest.CabinCompanionNum);
			PlaceCompanionCloneNearMChr(i, false);

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
			break;
//navy <--

		//--> ����������� ������
		case "Seek_AbyIsland":
			bOk = CheckCharacterItem(pchar, "bussol") && CheckCharacterItem(pchar, "clock2");
			bool bOk1 = CheckCharacterItem(pchar, "sextant2");
			bool bOk2 = CheckCharacterItem(pchar, "sextant3");
			if (bOk || bOk1 || bOk2)
			{
				DialogExit();
				DeleteAttribute(pchar, "questTemp.HWIC_Coordinates");
				pchar.questTemp.HWIC_FindIsland = "true";
				AddDialogExitQuestFunction("PrepareSearchingFor");
			}
			else
			{
				dialog.text = "��, � ���� ��� ����������� ������������� �������� ��� ����������� ������ � �������. ����. ������ ������� �������� ��������.";
				link.l1 = "";
				link.l1.go = "exit";
			}
		break;
		//<-- ����������� ������
		
		//--> ������ ����
		case "FalseTrace_Cabin":
			dialog.text = "������! ���������� ��������� �� ��� ����� �������!";
			link.l1 = "����, �������!";
			link.l1.go = "exit";
			chr = characterFromId("Mugger");
			if (pchar.questTemp.FalseTrace == "CatchAdam") chr.dialog.currentnode = "FalseTrace_17";
			else chr.dialog.currentnode = "FalseTrace_7";
			pchar.questTemp.FalseTrace.CharID = "Mugger";
			AddDialogExitQuest("SetFalseTraceCharToCabin");
		break;
		
		case "FalseTrace_Woman":
			DialogExit();
			chr = characterFromId("FalseTraceWife");
			chr.dialog.currentnode = "FalseTrace_wife_6";
			pchar.questTemp.FalseTrace.CharID = "FalseTraceWife";
			AddDialogExitQuest("SetFalseTraceCharToCabin");
		break;
		//<-- ������ ����
		
		//--> LSC, ������� �� ������ � �����
		case "knock_2":
			PlaySound("interface\knock_2.wav");
			dialog.text = "���������, ������ �������� ������...";
			link.l1 = "(�����)";
			link.l1.go = "knock_wrong";
		break;
		
		case "knock_3":
			PlaySound("interface\knock.wav");
			dialog.text = "���������, ������ �������� ������...";
			link.l1 = "(�����)";
			link.l1.go = "knock_wrong";
		break;
		
		case "knock_3_1":
			PlaySound("interface\knock_3_1.wav");
			dialog.text = "���������, ������ �������� ������...";
			link.l1 = "(�����)";
			link.l1.go = "knock_wrong";
		break;
		
		case "knock_1_3":
			PlaySound("interface\knock_1_3.wav");
			dialog.text = "���������, ������ �������� ������...";
			link.l1 = "(�����)";
			link.l1.go = "knock_wrong";
		break;
		
		case "knock_2_2":
			PlaySound("interface\knock_2_2.wav");
			dialog.text = "���������, ������ �������� ������...";
			link.l1 = "(�����)";
			link.l1.go = "knock_right";
		break;
		
		case "knock_wrong":
			dialog.text = "�� ���������... ������, ������� ���� ���� �� ���. ��� ��, ����� ������ � �������� ��� ��� - ������� ��� ��� ��������� �� �������.";
			link.l1 = "(����)";
			link.l1.go = "exit";
		break;
		
		case "knock_right":
			PlaySound("interface\key.wav");
			PlaySound("voice\russian\YouFace.wav");
			dialog.text = "�! ���������! � ����� �����! ����� �������...";
			link.l1 = "(�����)";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.LSC.DiffIndoor");
			LocatorReloadEnterDisable("LostShipsCity_town", "reload74", false);
		sld = characterFromId("Nathaniel");
		sld.dialog.currentnode = "diffindoor";
		sld.greeting = "Nathaniel_ill"; 
		sld.location = "FernandaDiffIndoor";
		sld.location.group = "goto";
		sld.location.locator = "goto1";
		LAi_SetGroundSitTypeNoGroup(sld);
		break;
		//<-- LSC, ������� �� ������ � �����
		
		// ��� �� ��������
		case "terrapin":
			PlaySound("Interface\Door_Kick.wav");
			PlaySound("voice\russian\EvilPirates02.wav");
			dialog.text = "�������! ��� � ���������! ������ ���������� ������� ���������... ����� ����� �� �����. �� ��� ��, �������� ������ �� ���� - ����� ����. ���� ������ �� ����-�� ���� ��������!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Terrapin_GoWindow");
		break;
		
		// ������ ���� �� ������
		case "SP_defend":
			PlaySound("VOICE\Russian\military02.wav");
			dialog.text = "����, ����� ���� ���������� ������ - ������ ����� ��������� ���������� �� ��������� ���� �� �����. ���� ��������, ��� ���� �� ������ ������. � ����� ��������� ���� �� ����� ������������� ������ ��������� �������, ������� ������� - �������� �������. ��������� ������� ���������� - � ����� ������ �������, ����� ����, ��������� � ������ �� �������� ��� �������� ������ �� ������\n������� ���� ���� ������� ������� ������ ����� ������� � ��������� ��������� � ���� ����� ��������� ������. ������� ����� � ���� �� �����������, �������� ��������. �������� ��������� �����, ��� ������ ������� ����� ��������\n��� ��������� ���������, � � ����� ������������ ��������� ����� ������ ��������� ��� ����� ���� �� ��� �������. �������, ��� ������� ���� ��������� � ����������� �����. ������!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("DefendSP_GoJungle");
		break;
		
		// ����� ����
		case "final_1": // Jason ���
			if (CheckAttribute(pchar, "questTemp.Patria.GenGovernor")) // �������-���������� ������ �� �����
			{
				dialog.text = "����, ���� ��� � ��������? � �� ���� �������� ���� �������-����������� ��� ���������� �� ������! ����� �� ������� ���� ����� ����������� ����� ����� �� ����������� ���������� ��������� �������. ������, � ���� ������� �� ����...";
				link.l1 = "";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "����� �� ����� ������ �������! � ��� ���������� �� �������� ������! ��������� ������!";
				link.l1 = "";
				link.l1.go = "exit";
				AddDialogExitQuest("Final_ReturnToEurope");
			}
		break;
		
		case "final_2":
			dialog.text = "� � �����, ��� ���������� �������! ��� � ��� �����, � ���� ��������-������, ����� ����� � ����� ������ ����? � ��������� � ������ � ������ �����!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Final_StayInCarribean"); // 010912
			DeleteAttribute(pchar, "questTemp.Tieyasal_final");
		break;
		
		// Addon-2016 Jason, ����������� ���������� (���) ����-���������
		case "FMQN_1":
			dialog.text = "� ��� ����� ������ �������. ����������� �� ������� � ���������� �������� ������.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_ChooseExit");
		break;
		
		case "FMQN_2":
			dialog.text = "��� ��, ���-���� ��������. �� ����� � ��� � ���� ������ � ����� � ���� ������ - ����������� �� �������, ����� � ���� ����������� � �������� ����������. � �� ������� ����������� ������ ������� � ����� �� ���������� ������� �����������.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("FMQN_ChooseContinue");
		break;
		
		// Addon 2016-1 Jason ��������� �������
		case "mtraxx_ammo":
			Mtraxx_PlantCheckShoreBox(); // ����������� ���������� �������
			if (CheckAttribute(pchar, "questTemp.Mtraxx.Weapon.Blade") && !CheckAttribute(pchar, "questTemp.Mtraxx.Weapon.NoBlade")) // ������� 30 ������
			{
				dialog.text = "�������� ������ ��������� ������ � �������! ����� ���������, ���� ������� ��� ��������, ����, �����?..";
				link.l1 = "���� ������ � �������� ��������!";
				link.l1.go = "mtraxx_ammo_1";
				link.l2 = "���, ���� ��������� ������ ������.";
				link.l2.go = "exit";
			}
			else
			{
				dialog.text = "�������� ������ ��������� ������ ��� �� �������! ���� ���������� ������.";
				link.l1 = "";
				link.l1.go = "exit";
			}
		break;
		
		case "mtraxx_ammo_1":
            dialog.text = "������ �������� � ������������� ���� �� ��� �������� �������� �� ���������.";
			link.l1 = "";
			link.l1.go = "exit";
		Mtraxx_PlantMakeMaxRocurClone_1();
			AddDialogExitQuestFunction("Mtraxx_PlantShoreBoxComplete");
		break;
		
		case "mtraxx_mutiny":
            dialog.text = "������, � �����! ���!!";
			link.l1 = "";
			link.l1.go = "exit";
			Mtraxx_PlantSetMaxRocur();
			AddDialogExitQuestFunction("Mtraxx_PlantMutiny");
		break;
		
		case "mtraxx_boats":
            if (GetSquadronGoods(pchar, GOOD_PLANKS) >= 20 && GetSquadronGoods(pchar, GOOD_LEATHER) >= 10) // ������� ����������
			{
				if (Mtraxx_MeridaCheckCarpenter()) // ������� ��������
				{
					dialog.text = "��� ��������� ������������, ���������� � ��������� �����!";
					link.l1 = "";
					link.l1.go = "exit";
					AddDialogExitQuestFunction("Mtraxx_MeridaBuildBoats");
				}
				else
				{
					dialog.text = "��� ���������� �������� ��������, ��������� ����� ����������� ���������� �����. ���� ��������� ������ �������.";
					link.l1 = "";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "������������ ����������, ����� �� ����� 20 ������ ����� � 10 ����� ����.";
				link.l1 = "";
				link.l1.go = "exit";
			}
		break;
		
		case "mtraxx_powder":
            if (GetSquadronGoods(pchar, GOOD_POWDER) >= 300) // ������� ������
			{
				if (GetCrewQuantity(pchar) >= 20) // ������� �������
				{
					dialog.text = "��� �������� ������ ��� ������ - ������� ������� � ������!";
					link.l1 = "";
					link.l1.go = "exit";
					AddDialogExitQuestFunction("Mtraxx_RetributionBarrels");
				}
				else
				{
					dialog.text = "��� ������������ ���������� ����� ��� ��������� ��������, ���� �� ������ 20 ������� � �������.";
					link.l1 = "";
					link.l1.go = "exit";
				}
			}
			else
			{
				dialog.text = "������������ ������, ����� �� ������ 300 ��������.";
				link.l1 = "";
				link.l1.go = "exit";
			}
		break;
		
		case "mtraxx_dungeon":
			PlaySound("ambient\jail\jail_door2.wav");
            dialog.text = "�������, ���-�� ��������� � �������� �����...";
			link.l1 = "";
			link.l1.go = "mtraxx_dungeon_1";
		break;
		
		case "mtraxx_dungeon_1":
			PlaySound("ambient\jail\jail_door1.wav");
            dialog.text = "�����!.. ���-�� ��������� ����... ���?..";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Mtraxx_RetributionRunToEnrico");
		break;
		// ����� ��������, ������� � ���������.
		case "FreedomAzzy":
                                                       PlaySound("VOICE\Russian\gotica\SFX\OPENPORTAL.wav");	
			DoQuestCheckDelay("Ascold_XsardasIsFree", 10.0);
			//pchar.questTemp.Azzy = "Azzy_Freedom";
			DialogExit();
		break;	

// ����� ������
	case "TalkSelf_ChangeFlag":
			Dialog.Text = "����� ���� ��� ��������� �� ������ ������? ��� ����� ����� 1 ���.";
			if (IsCharacterPerkOn(pchar,"FlagPir") && sti(pchar.nation) != 4) {Link.l1 = "������� ��������� ����."; Link.l1.go = "TalkSelf_ChangeFlagPir";}
			if (IsCharacterPerkOn(pchar,"FlagEng") && sti(pchar.nation) != 0) {Link.l2 = "������� ���������� ����."; Link.l2.go = "TalkSelf_ChangeFlagEng";}
			if (IsCharacterPerkOn(pchar,"FlagFra") && sti(pchar.nation) != 1) {Link.l3 = "������� ����������� ����."; Link.l3.go = "TalkSelf_ChangeFlagFra";}
			if (IsCharacterPerkOn(pchar,"FlagSpa") && sti(pchar.nation) != 2) {Link.l4 = "������� ��������� ����."; Link.l4.go = "TalkSelf_ChangeFlagSpa";}
			if (IsCharacterPerkOn(pchar,"FlagHol") && sti(pchar.nation) != 3) {Link.l5 = "������� ����������� ����."; Link.l5.go = "TalkSelf_ChangeFlagHol";}
			Link.l6 = RandPhraseSimple("�� ������. ��� �������.", "�������. ���� ����.");
			Link.l6.go = "exit";
		break;
		
	case "TalkSelf_ChangeFlagPir":
	Log_Info("������ ��������� ����!");
	Flag_PIRATE();
	WaitDate("", 0, 0, 0, 0, 60); //������ �����
    	PChar.GenQuest.VideoAVI = "Pirate";
	PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
	DoQuestCheckDelay("PostVideo_Start", 1.5);
	DialogExit_Self();
	RecalculateJumpTable();
	Whr_UpdateWeather();
	RefreshLandTime();
	DoReloadCharacterToLocation(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto")); //������� ����, ���� ����� ������������
	break;
	
	// ���������� ����
	case "GothicApostates_start":
	        dialog.text = "��...����� � ������� � �����! M���� �������?";
            link.l1 = "�� ����� �����������, ��� ������� - �����.";
            link.l1.go = "GothicApostates_NoHelp";
            link.l2 = "�� ���� �� ��� �����, ����� - �� ���������� ���������� � ������, ����� ������ ���������.";
            link.l2.go = "GothicApostates_HelpMan";
    break;

	case "GothicApostates_NoHelp":
			AddDialogExitQuest("GothicApostates_PuertoPrincipe_NoHelp");
			DialogExit();
	break;
	
	case "GothicApostates_HelpMan":
			AddDialogExitQuest("GothicApostates_PuertoPrincipe_HelpMan");
			DialogExit();
	break;
	
	
	
	case "TalkSelf_ChangeFlagEng":
	Log_Info("������ ���������� ����!");
	Flag_ENGLAND();
	WaitDate("", 0, 0, 0, 0, 60); //������ �����
    	PChar.GenQuest.VideoAVI = "England";
	PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
	DoQuestCheckDelay("PostVideo_Start", 1.5);
	DialogExit_Self();
	RecalculateJumpTable();
	Whr_UpdateWeather();
	RefreshLandTime();
	DoReloadCharacterToLocation(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto")); //������� ����, ���� ����� ������������
	break;
		
	case "TalkSelf_ChangeFlagFra":
	Log_Info("������ ����������� ����!");
	Flag_FRANCE();
	WaitDate("", 0, 0, 0, 0, 60); //������ �����
    	PChar.GenQuest.VideoAVI = "France";
	PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
	DoQuestCheckDelay("PostVideo_Start", 1.5);
	DialogExit_Self();
	RecalculateJumpTable();
	Whr_UpdateWeather();
	RefreshLandTime();
	DoReloadCharacterToLocation(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto")); //������� ����, ���� ����� ������������
	break;
		
	case "TalkSelf_ChangeFlagSpa":
	Log_Info("������ ��������� ����!");
	Flag_SPAIN();
	WaitDate("", 0, 0, 0, 0, 60); //������ �����
    	PChar.GenQuest.VideoAVI = "Spain";
	PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
	DoQuestCheckDelay("PostVideo_Start", 1.5);
	DialogExit_Self();
	RecalculateJumpTable();
	Whr_UpdateWeather();
	RefreshLandTime();
	DoReloadCharacterToLocation(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto")); //������� ����, ���� ����� ������������
	break;
		
	case "TalkSelf_ChangeFlagHol":
	Log_Info("������ ����������� ����!");
	Flag_HOLLAND();
	WaitDate("", 0, 0, 0, 0, 60); //������ �����
    	PChar.GenQuest.VideoAVI = "Holland";
	PChar.GenQuest.VideoAfterQuest = "Unifersal_end_video";
	DoQuestCheckDelay("PostVideo_Start", 1.5);
	DialogExit_Self();
	RecalculateJumpTable();
	Whr_UpdateWeather();
	RefreshLandTime();
	DoReloadCharacterToLocation(pchar.location, "goto", LAi_FindNearestFreeLocator2Pchar("goto")); //������� ����, ���� ����� ������������
	break;

		// Jason ����� � ���������
		case "LH_marry":
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) sld = characterFromId("Helena");
			else sld = characterFromId("Mary");
			string sTemp = sld.name;
			dialog.text = "�� � "+sTemp+" ����� ������, � ���� ��� ������ ����� ��������� �����, �� � ����, ����� ���� ������ ���������� ��� �����. ������� - ���� ������ ��� ��� ����� � ��� ����������:";
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer"))
			{
				link.l1 = "���� ������ - ���� ������ ����� ������ � ����� �������. �������, ����� ����� �� �����: ����� ����-������ - ������������� �� ������!";
				link.l1.go = "LH_marry_1_1";
			}
			link.l2 = "������� - ������ ������� ������ �������, � ��� � ����� �� ������ ����� ������� ����� ������ ���������!";
			link.l2.go = "LH_marry_1_2";
			if (CheckAttribute(pchar, "questTemp.LSC.Mary_officer"))
			{
				link.l3 = "������ - � ��� ������� ����� �������! � ���������� ��������� � ����� �������� - ��� ��, ��� � ����������� ���� ��� �� �����.";
				link.l3.go = "LH_marry_1_3";
			}
		break;
		
		case "LH_marry_1_1":
			pchar.questTemp.LongHappy.Shore = "Shore_ship1";
			AddQuestRecord("LongHappy", "2_1");
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) sld = characterFromId("Helena");
			else sld = characterFromId("Mary");
			sTemp = sld.name;
			AddQuestUserData("LongHappy", "sName", sTemp);
			dialog.text = "��, ��� ��������� � ������ �� �������� - ��� ������ ���� �� ���� �������, ����� ���� �������� ������� ��� �����. ������ - ��� ����������� ���������, � � �� ���� � ���� ��������� ������, ����� ������ �����. �� ������ ���� ���� � � ���� �������� ��� ����������� � ����� �����. �����, �� ���������� ������� ��� ����� �����.";
			link.l1 = "";
			link.l1.go = "LH_marry_2";
		break;
		
		case "LH_marry_1_2":
			pchar.questTemp.LongHappy.Shore = "Mayak6";
			AddQuestRecord("LongHappy", "2_2");
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) sld = characterFromId("Helena");
			else sld = characterFromId("Mary");
			sTemp = sld.name;
			AddQuestUserData("LongHappy", "sName", sTemp);
			dialog.text = "��, ��� ��������� � ������ �� �������� - ��� ������ ���� �� ���� �������, ����� ���� �������� ������� ��� �����. ������ - ��� ����������� ���������, � � �� ���� � ���� ��������� ������, ����� ������ �����. �� ������ ���� ���� � � ���� �������� ��� ����������� � ����� �����. �����, �� ���������� ������� ��� ����� �����.";
			link.l1 = "";
			link.l1.go = "LH_marry_2";
		break;
		
		case "LH_marry_1_3":
			pchar.questTemp.LongHappy.Shore = "Shore36";
			AddQuestRecord("LongHappy", "2_3");
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) sld = characterFromId("Helena");
			else sld = characterFromId("Mary");
			sTemp = sld.name;
			AddQuestUserData("LongHappy", "sName", sTemp);
			dialog.text = "��, ��� ��������� � ������ �� �������� - ��� ������ ���� �� ���� �������, ����� ���� �������� ������� ��� �����. ������ - ��� ����������� ���������, � � �� ���� � ���� ��������� ������, ����� ������ �����. �� ������ ���� ���� � � ���� �������� ��� ����������� � ����� �����. �����, �� ���������� ������� ��� ����� �����.";
			link.l1 = "";
			link.l1.go = "LH_marry_2";
		break;
		
		case "LH_marry_2":
			AddQuestRecord("LongHappy", "3");
			if (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) sld = characterFromId("Helena");
			else sld = characterFromId("Mary");
			sTemp = sld.name;
			AddQuestUserData("LongHappy", "sName", sTemp);
			dialog.text = "�� � ���� ��� ��������� ��������. ������� - ��� � �� ��������� �������� � "+sTemp+" ���� �����.";
			link.l1 = "";
			link.l1.go = "exit";
			pchar.questTemp.LongHappy = "choose";
		break;
		
		case "LH_marry_3":
			dialog.text = "�� ��� ��, � �����!";
			link.l1 = "";
			link.l1.go = "exit";
			LongHappy_MarryOffer();
		break;
		
		case "LH_marry_4":
			if (LongHappy_CheckGoods())
			{
				dialog.text = "��� ������������!";
				link.l1 = "";
				link.l1.go = "exit";
				LongHappy_OnIslaTesoro();
			}
			else
			{
				dialog.text = "��� �� ������� ��� ����������� ������ � ������!";
				link.l1 = "";
				link.l1.go = "exit";
			}
		break;
	}
}

void  DialogExit_Self()
{
    DialogExit();
	locCameraSleep(false); //boal
}