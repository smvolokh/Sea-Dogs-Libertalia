// ������ ���� � ������ ������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		

		case "First time":
			int iPhrase_GothicSmithy = rand(1);
			switch (iPhrase_GothicSmithy)
			{
			case 0:
            		dialog.text = "�������, ��������, ������ ������, ���������... ��� ��� ��� ���������.";
        		link.l1 = "������� �� �� �������.";
        		link.l1.go = "Exit";
			break;

			case 1:
            		dialog.text = "���������� ���������� ����� - ��� �������! ����������� �� ����...";
        		link.l1 = "��� ����� ��������� �����...";
        		link.l1.go = "Exit";
			break;			
			}
		break;

 		case "Exit":
                                    NextDiag.CurrentNode = "First time";
		DialogExit();
		break;


		case "MartiniqueAbord":
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_IGETYOUSTILL.wav");
            	dialog.text = "� �� - ���� ������� ����...";
        	link.l1 = "...";
        	link.l1.go = "2";
	break;

		case "2":
 	PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_18.wav");
            	dialog.text = "";
        	link.l1 = "� ���� ���� ���� ����, ������ ���� ������?";
        	link.l1.go = "3";
	break;

		case "3":
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_KILLENEMY.wav");
            	dialog.text = "���� �������.";
        	link.l1 = "...";
        	link.l1.go = "Gun Attack";
	break;

 	case "Gun Attack":
                   NextDiag.CurrentNode = "First time";
	DialogExit();
	sld=characterFromID("KarSec");
	LAi_SetActorType(sld);
            	LAi_ActorTurnToCharacter(sld, pchar);
	LAi_ActorAnimation(sld, "Shot", "GothicSmithy_Ghostship_Gun", 1.5);
	break;

	case "MartiniqueAbord_Gun":
                   if(sti(pchar.money) >= 1)
	{
            	dialog.text = "������� �� ������ - �����...";
	link.l1 = "...";
	link.l1.go = "ITOOKYOURGOLD";
	}
	else
	{
            	dialog.text = "�� �� ������� � ���� ���� ������ ���...";
	link.l1 = "...";
	link.l1.go = "NO_ITOOKYOURGOLD";
	}

                   LAi_SetCurHP(pchar, 5);						
	LAi_SetActorType(pchar);
	LAi_ActorAnimation(pchar, "death_3", "", -1);
	break;


 	 case "ITOOKYOURGOLD":
 	 PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_ITOOKYOURGOLD.wav");
            	 dialog.text = "������� �� ������ - �����...";
        	  link.l1 = "";
        	  link.l1.go = "MartiniqueAbord_Gun_Exit";
	  pchar.money = 0;
	  break;

 	 case "NO_ITOOKYOURGOLD":
 	 PlaySound("VOICE\Russian\GOTHIC\CRIME_W\CRIME_W_2.wav");
            	 dialog.text = "�� �� ������� � ���� ���� ������� ���...";
        	 link.l1 = "";
        	 link.l1.go = "MartiniqueAbord_Gun_Exit";
	  break;


 	case "MartiniqueAbord_Gun_Exit":
                   NextDiag.CurrentNode = "First time";
	DialogExit();
	AddQuestRecord("Gothic_Smithy", "12");
	AddDialogExitQuest("GothicSmithy_GhostshipGetOut");
	break;



	case "3 At Cayman":
            	dialog.text = "��������, ������! � ����� ������� �������� - ��� �� ��� �������������� ������? ���� ���� ��� ����� ����� �������, ��, ���������� ������! ��������, �������� ����� �������, � �� ������� ���� ����� ������������ ���������! �� ������ ������������� � ������!";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "21";
		break;

 		case "3 Exit":
                                    NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("SmithyDavid");
		LAi_SetActorType(sld);
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "4":
            	dialog.text = "��-��-��, ��-�� ������� �������? �� �� ������ ���������, �� �� ������ �������������� �� ����� �����, �� ���� ����, �� ���� ��������! ������ ���������! �� - �����������! ���������! ������ ����������!";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "22";
		break;

	case "5":
            	dialog.text = "� �� ����� ���� �����. ������ ��� ������� ����� ���� � �������������. � ��� ������ ��������, ��� ������ ��������� ���������.";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "23";
		break;

	case "6":
            	dialog.text = "���� ����� ������� ����� ������ ����, ������ ����������. �� ��� ������ � �� �����, ��������? ���� ���� ��������� ����, �� �� �� �����, ������ ��� �� - ������ ������ ��������� ��������� ������������ ������� ������ �������!!! � ���� "+ GetFullName(Pchar)+" ���� �������� �� ����! �� ����� ���! �� ����� ���� ����! �� ��ܨ� ���� ���� ����!";
        	link.l1 = "����-����-����! �� ���� - �����������, ������? �� ��� - �����������, �� ���� �� ���������, ��� ����� �� ���� - ���� ����, ������.";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "24";
		break;

	case "7":
            	dialog.text = "� ������� ���, ������ ����! ���-���-���! �� ���������� ����, ������ ��� � ��������� ����, ��������! ������ ��� � ��������� ���� ����� ��� ������!";
        	link.l1 = "��... � ��� ����� � �������.";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "25";
		break;

	case "8":
            	dialog.text = "�� ������ ��� ������, " + PChar.name + "! �� ��, �������� ���! � ���� � ����, ��������.";
        	link.l1 = "";
        	link.l1.go = "8 Exit";
	Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "23 At Cayman";
		break;

	 	case "8 Exit":
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
		LAi_SetActorType(sld);
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "9":
            	dialog.text = "��� ���� ��������� - ��� �� ��� ���������! ������ - �������� ������! ����� �� ����� �������� ���������, ������ ������ ����� ������� ���� �� �����! " + PChar.name + " - ���� �� �������, �������!";
        	link.l1 = "������ ����, �...";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "27";
		break;


//**************** �������� �1 - �������� ����� ���� *****************
	case "10":
            	dialog.text = "ר���� ���������!!! �� ������ ������������ �������, ��������! ������, �������� ����� � ��������!";
        	link.l1 = "��� �� ��� �������, �����! ���� �� ������ ����� ��������! ����!";
        	link.l1.go = "Kill Carrol";
		break;

	 	case "Kill Carrol":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("Carrol");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_1_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_2_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_3_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_4_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_5_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");

		sld=characterFromID("SmithyDavid");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_6_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("GothicSmithy_Pirat_7_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_8_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_9_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_10_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", LAI_GROUP_PLAYER, true);
		//	LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", "GothicSmithy_Pirat_David_War", true);
		pchar.quest.GothicSmithy = "GothicSmithy_Kill_Carrol";
		LAi_group_SetCheck("GothicSmithy_Pirat_Karrol_War", "Smithy 30");
		break;


//**************** �������� �2 - �������� ������ ����� *****************
	case "11 AftrKillDvd":
            	dialog.text = "�����������, ��������! �� ������ ���������� �����, � �� ���� ��� ������! �����������! ����������! � ����� ������� �����.";
        	link.l1 = "� ������ �������, ������ ����. �������, ������� �� �������� ���� �����?";
        	link.l1.go = "12";
		break;

		case "12":
            	dialog.text = "�� ��������, ��������. � ����������� ��� ���� �������� ���, ���� � �����, ��� �� �������� ���������� �����. �����, �� �������� ��� ������. � ������, ����� ��� ��������, �� �� � �������� ������� �������� ������. ������, ��������. ����� ���� ������ ����������.";
        	link.l1 = "";
        	link.l1.go = "12 Exit";
		break;

 		case "12 Exit":
		AddMoneyToCharacter(pchar, +60000);
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
		LAi_SetActorType(sld);
		Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "24";
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

//**************** �������� �3 - �������� ���� *****************
	case "13":
            	dialog.text = "" + PChar.name + ", �� ������ ���������! ����������� - ������ ���� ���� ������ � ��� ����� � ������ �������!";
        	link.l1 = "���������, ����������! ����� ���� ������!";
        	link.l1.go = "13 Exit";
		break;

	 	case "13 Exit":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("Carrol");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("SmithyDavid");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Smithy_Pirat_1_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_2_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_3_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_4_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_5_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");

		sld=characterFromID("GothicSmithy_Pirat_6_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_7_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_8_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_9_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_10_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", "GothicSmithy_Pirat_David_War", true);
			LAi_group_FightGroups("GothicSmithy_Pirat_David_War", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", LAI_GROUP_PLAYER, true);
		pchar.quest.GothicSmithy = 0;
		LAi_group_SetCheck("GothicSmithy_Pirat_Karrol_War", "Smithy 33");
		LAi_group_SetCheck("GothicSmithy_Pirat_David_War", "Smithy 33");
		break;


//**************** �������� �4 - "������" ������� ��������� *****************
	case "14":
            	dialog.text = "���, "+ GetFullName(Pchar)+"! � �� ��������� ������ ������ � ���� �������! �� ��� ����������� ���, � � ���� ������� ���� ���� ����������! ��� �� ����� ��� ������!";
        	link.l1 = "�����, ���������. �� ���� ������ ���� ����? ���� ������ ����� �������� �. �� ���� �� ������ �����? ��� �� � ��� �� ��������. � ����� ����� ������� ����� ��������.";
        	link.l1.go = "15";
		break;

		case "15":
            	dialog.text = "�... � �� ����� �! ��� - ������� ������������ ��������, ����������� ��������� �����������, ������ ��� ������ �����������. ��... ������� �� � ���-�� ����, "+ GetFullName(Pchar)+". � ��������� ������ ����� ������, ���� �� ���������� ������ ���. ���� �� ������� �� �������, ��� ����� ������! ���� �� ���� ������ � ������ ��� �������� � � ��� ������ ����� �� �� ��� ������ � ��� �������.";
        	link.l1 = "�� �����, ������ ����! ������ ����, ��� �������?";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "31";
		break;

	case "16":
            	dialog.text = "����������� � ������ �������, �����. �� ������� �� �����. � ���������� ������� ����.";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "32";
		break;

	case "17":
            	dialog.text = "��������!!! �������!!! ��� �� ������ � ����� ���������?!?";
        	link.l1 = "���... ��� ������.";
        	link.l1.go = "18";
		break;

		case "18":
            	dialog.text = "�, ���!!! ��-�-�-�!!! � �� ���� � ���!!! �����, ��... ��... ���... ��������...";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "33";
		break;

	case "19":
            	dialog.text = "���! " + PChar.name + "! ����! �� �����! �� ����� ������ �� ���� ������! ���������� �� ������� � �� ��� �����! " + PChar.name + "... ������ ���. ���� ����� ����. �� ����� ��� �����, � ���� � ��... �������. ������ ����.";
        	link.l1 = "�...";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "34";
		break;










































//************************ ������� ������� (��������� � ����) ****************************************

		case "FrdAttckAtSea":
            	dialog.text = "���-���. "+ GetFullName(Pchar)+", �� ��� ��?";
        	link.l1 = "������ ����� ��� ����� �� ��� �������?";
        	link.l1.go = "FrdAttckAtSea 1";
		break;

		case "FrdAttckAtSea 1":
            	dialog.text = "������� �������. ����� ��������, ����� ����-����������. �� ������������, " + PChar.name + "? �� �������� ����.";
        	link.l1 = "����� ���������. ��, ��� � ����, ������.";
        	link.l1.go = "FrdAttckAtSea 2";
		break;

		case "FrdAttckAtSea 2":
            	dialog.text = "������, " + PChar.name + ". �� � ������� �����, ������� � ������� ����� ����� ���������.";
        	link.l1 = "�� ������, ����� � ��������" + GetSexPhrase("","�") + " ��������? ��� ���������" + GetSexPhrase("","�") + " ����� ����?";
        	link.l1.go = "FrdAttckAtSea 3";
		break;

		case "FrdAttckAtSea 3":
            	dialog.text = "�� �����" + GetSexPhrase("�","���") + ", " + PChar.name + ", �� ��� �� ������ ��� �������, ��� �� ���� �� ����� ����, ��� ��� ��������. ��� ����� ������ ������.";
        	link.l1 = "���? � ��� ��� ��?";
        	link.l1.go = "FrdAttckAtSea 4";
		break;

		case "FrdAttckAtSea 4":
            	dialog.text = "�� ��������������, " + PChar.name + ", � ����, ��� ��� � ��� �� ����� �, ��������, ������ �������� � ����� ��� ����� �����. ������� ��� �������, � � ������ ���� �����.";
        	link.l1 = "����� ��� ���?";
        	link.l1.go = "FrdAttckAtSea 5";
		break;

		case "FrdAttckAtSea 5":
            	dialog.text = "� ��������� �������� � �� ����� ����� � ������ ���������� ���� ������� �� ������� � ������, ������ ����� ������. �� � �������� �������� � ������� �������� ������� �� ��������.";
        	link.l1 = "��� ��, �����, ��� � �� ������� ��� ���� ��������� �� ��.";
        	link.l1.go = "FrdAttckAtSea 6";
		break;

		case "FrdAttckAtSea 6":
            	dialog.text = "� ����� ������, ��� ������� ��������� ���� ��������� �� �� ��� ������ ����������.";
        	link.l1 = "�� �������?";
        	link.l1.go = "FrdAttckAtSea 7";
		break;

		case "FrdAttckAtSea 7":
            	dialog.text = "����������. ������� - �������� �� ����� �� ���� �������, ����� ���� �������!";
        	link.l1 = "�������, ��� �� ������ �������� ���� ����� � ���!";
        	link.l1.go = "FrdAttckAtSea Fight";
		break;

 		case "FrdAttckAtSea Fight":
                NextDiag.CurrentNode = "Fist time";
		DialogExit();
		sld=characterFromID("Quest_Smithy_Feder");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_1_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_2_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_3_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_4_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_5_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_6_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_7_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
// ����
		sld=characterFromID("QuestPcharFirstMate");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter1");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter2");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter3");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter4");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter5");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		LAi_group_FightGroups("Smithy_Pirat_War_Sea", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("Smithy_Pirat_War_Sea", "Smithy 20");
		Pchar.GenQuest.HunterScore2Pause =  true;
		break;

	}
}


