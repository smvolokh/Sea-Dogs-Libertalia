// ������ ����, ��������� ��������
void ProcessDialogEvent()
{
	ref NPChar, sld, sld1;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		

		case "First time":
		if (pchar.quest.NSmithyQ == "Smithy_SanJuan_Dvoretsky")
		{
            	dialog.text = "�, " + GetAddress_Form(NPChar) + ", ����������� ���! � ��������, ��������� ����� ����. �� ������ ���� ������� " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?";
        	link.l1 = "��, ��� �. ��� ����� ���������� � �������� ������. ���� � ������?";
        	link.l1.go = "DvorJer 1";
		}
		else
		{
			int iPhrase_Quest_Smithy = rand(1);
			switch (iPhrase_Quest_Smithy)
			{
			case 0:
            		dialog.text = "����� ���������� � ��� ����� ����. �� ���-�� ������?";
        		link.l1 = "����... ���, � ��� �����" + GetSexPhrase("","�") + "...";
        		link.l1.go = "Exit";
			break;

			case 1:
            		dialog.text = "����� �������� " + GetAddress_Form(NPChar) + ", �� ������ � ������ ���� � �������.";
        		link.l1 = "� ��� ��� �����?! ����... �����...";
        		link.l1.go = "Exit";
			break;			
			}
		}
		break;

	case "Exit":
                NextDiag.CurrentNode = "Fist time";
		DialogExit();
		break;


	case "Second Time":
            	dialog.text = "������������, " + GetAddress_Form(NPChar) + "!";
        	link.l1 = "";
        	link.l1.go = "Second Time Exit";
		break;

 	case "Second Time Exit":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;


	case "Smithy_July":
            	dialog.text = "��, ������ ����,  " + GetAddress_Form(NPChar) + " " + PChar.name + "? � ����� ���� ��� ������. ���� ����� ������ ������, ���� �� ����� ���� � ����, �� ��� �������... ������� ������� �������. ������ ����� ���� ������ ������. ��� ���� ������� �� ��� ������?";
        	link.l1 = "��, ������. ������, ������ ����� ���� ������ " + PChar.name + ".";
        	link.l1.go = "2";
		break;

		case "2":
            	dialog.text = "����� �������, " + PChar.name + ". ����, ���� � ��������� �������, �� ��� ��������� �������, ���� ��� �������� ���� �����, ����� ����� ��� �������� ����?";
        	link.l1 = "��, ��� ���� ��������� ��� �������������� ������ �, � ����� ������, �� ����� ������� ������������ ����. � ������" + GetSexPhrase("","�") + " ��� �����������, ��� ��� ������� �������� �� ������ ����. �������, �� ���� ���������.";
        	link.l1.go = "3";
		break;

		case "3":
            	dialog.text = "� ������� ���, " + PChar.name + ". � ������� �� ����. ���� ���-�� � ������� �� ���� ���� �������, ��� ��� �.";
        	link.l1 = "��������? ��? � ��-�� ����� ������?";
        	link.l1.go = "4";
		break;

		case "4":
            	dialog.text = "�� � ��� �� �� ������, " + PChar.name + ". ���� �����, ����� � ������� � ������ � ��������� ��� � �����������. ���� ������, ����� � ������� �� ���� � ����� ����� ����������� �����. � ��� ��������� ������ �����������. � ��� ���, ���� �����, ��������� ��-�� ����. � � ���������� � ��������� �� �����, � �� �� ��� �� �������� ������ �� ���������� - � ������� �� ����� ������� ����������� � ��������� ����� �����, ������, ��������, ��� � ��, ������ ���� �������� �� ���. � ����� ��������, � ����� �� ����� ����������, � �����, ��� � ��� ����, �������� ���������������, �� ��� �� ������� �� ����� ��������� - ����. ������ �� ��� ��... ���� ��� ���� �� ����� ���. �����������, ������������, �������� �������! ��� ��������� �� ���� ����� ����������� � ���... ��� ����� ���. � ���� ��������� � ��� � ��� �������, ��� � �� ������ ��������� ������� ������� � ����� �� ��... �����, " + PChar.name + ", �� ���������� �� ����. �� ��� ����� �������, �� ������ � ��� ���� ���-�� ��������. � ����� �������. ��� �� ������ ��� ��������. �� �������� ���, " + PChar.name + "?";
        	link.l1 = "�� �� ������ �� � ��� ������ ����, ������. ���� �������� �� �����, � �� ������ ��, ��� �����, ����� ������ ��. � ����� � ���� ������ ���, �� ��� ������ �� ������ �� ����?";
        	link.l1.go = "5";
		break;

		case "5":
            	dialog.text = "� ��� �������. �� ����������� �������, �������. ���-�� ����� �����. � �� ����, ��� ��� ��� ���������� ������, �� � �������, ��� ������ ��� �� ��������. ��� ��������� ���� ����� � ��� ��������� �������. ������ ����� ���������� �� ������� � ���������� ������� ����� �������� � ����������. �� � ���� ������ ����������� ���� � �������� �� ��������� �������! �� ������ ���������� ��!";
        	link.l1 = "��... ��� �� ����������� ���������� ��? �� ���� ���� �������, ��� ��� ��������� �������, � � �� �������������, ��� ����, ���� � �����, � ������ ������ ����� - ��������� �����. � ��� �� ������ ��������� � ��� ������?";
        	link.l1.go = "6";
		break;

		case "6":
            	dialog.text = "� �� ����, " + PChar.name + "! ������� � � ����� ��� ������! �� ������� ���� � ������ ���� �����, �� " + GetSexPhrase("�������","�������") + ", �� ������� �� �������, �� ��� �������� ������ �������� ��������... � �� ����! �� �� ������� ��� �������! ���� �� �������� ���, � �������, ��� ������ �������� ������� ����� ������������ ���! � ����� ����������� ���, " + PChar.name + "!";
        	link.l1 = "��� �... � ����� �� ��, ���� �� ����������� ����� ������������� ����, ������.";
        	link.l1.go = "7";
		break;

		case "7":
            	dialog.text = "��������, ��� �� ������ � ����, " + PChar.name + "?";
        	link.l1 = "���-���, ������, �� ������ � ������, ������. ��� �� ������������?";
        	link.l1.go = "8";
		break;

		case "8":
            	dialog.text = "��! ������ �� ������!";
        	link.l1 = "����� ����� �� ����, �����!";
        	link.l1.go = "Go TO Cayman";
		break;

 	case "Go TO Cayman":
    	AddQuestRecord("Gothic_Smithy", "14");
                   NextDiag.CurrentNode = "Second Time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyPuertoRico_4");
		break;








	case "9 Sea Atack":
            	dialog.text = "��� ����������," + PChar.name + "?";
        	link.l1 = "�-�, ������, ����� ���, ��������� � ���� �����. ������ ��������� �� ����������, ������ ������� �������.";
        	link.l1.go = "10";
		break;

		case "10":
            	dialog.text = "� ��� ��� �� �������, ��� �������� �� ���? ����, �������, ��� �������� ������!";
        	link.l1 = "������, �����, ��������� � ���� �����. �������, ���������, ������� ���� ������ � � �����.";
        	link.l1.go = "11";
		break;

		case "11":
            	dialog.text = "" + PChar.name + ", ��� �������! ��� ����������?!";
        	link.l1 = "�������! ����������!";
        	link.l1.go = "TO Cabin from Attack";
		break;

 	case "TO Cabin from Attack":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 16", 0.5);
		break;



	case "12 After Sea Attack":
            	dialog.text = "�, ����! �������! ��� ����� ���������?!?";
        	link.l1 = "�� ������, ������. ����� ���, �� ����������. ���... �������� ������. ��������� ��� ��������� ��� �� ����� �����.";
        	link.l1.go = "TO Cabin After Attack";
		break;

 	case "TO Cabin After Attack":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 23", 0.5);
		break;



	case "13 At My Cabin":
            	dialog.text = "" + PChar.name + ", ��� ���� ��������� �� ����? � ��... �� ������� ��-�� ����?";
        	link.l1 = "����� ������, ��������, ������ ��������� �� ���������. ��� ������� ���� ��� ����. ��, ������, �������� ��� �����, ����� � ����������...";
        	link.l1.go = "14";
		break;

		case "14":
            	dialog.text = "������� ����? � ��� ����� �� �������� �����?";
        	link.l1 = "��, �... � �� ������. � �� ������ - ��� ������� ������ �����. ������� ������ �������� �� ���.";
        	link.l1.go = "15";
		break;

		case "15":
            	dialog.text = "� ��� �� ����������, �����... ����� ��������?";
        	link.l1 = "��... ������. � ����� ����� ����������. �� ������� ���� - � ������" + GetSexPhrase("","��") + ".";
        	link.l1.go = "16";
		break;

		case "16":
            	dialog.text = "��� ������, " + PChar.name + "...";
        	link.l1 = "��... ������ ���� ����������, ���� �������. �������� ����������. ������������ �����. ��� ������, ��� ������ ������ ����, � �� ������� ����� ��� ����� �� �����. ���, ��������. �� �������� ������, ��� ����� ���������. ��� ����� �������� ���.";
        	link.l1.go = "17";
		break;

		case "17":
            	dialog.text = "���, " + PChar.name + ", ����� ���, �����... ����� ���������� �� ����.";
        	link.l1 = "��...";
        	link.l1.go = "18";
		break;

		case "18":
            	dialog.text = "" + PChar.name + ", �� �� ������ ������ �� ���� �����? ���� �� �������? ���� ������� �� �������� � ����� � �� ������� �� ����? � ��� ���� ���� ������������ ���������. �������� ���� ���� ����� ������ ��������, ����� �� ���, " + PChar.name + "?";
        	link.l1 = "��, ���... �������, ��... �������� ���� ����� �����... ���... ����� ��������...";
        	link.l1.go = "19";
		break;

		case "19":
LAi_Fade("","");
//StartQuestMovie(false, false, true);   // ��������� ������������!!!!!!!!!
// �������� Love music
            	dialog.text = "" + PChar.name + ", �������, ����� ������ ������ ��� ����� � ������?";
        	link.l1 = "��... ������ �� ��������� ���� �������. � ����������.";
        	link.l1.go = "20";
		break;

		case "20":
            	dialog.text = "��������� �� ���, ��������...";
        	link.l1 = "�� ������ ���������.";
        	link.l1.go = "21";
		break;

		case "21":
            	dialog.text = "� �� - �� ���� ���� �� ��� ������� �������?";
        	link.l1 = "������ ������.";
        	link.l1.go = "22";
		break;

		case "22":
            	dialog.text = "�� ��, � �����, ��� �� - ����� ������� ������ �������.";
        	link.l1 = "��, ������ � ���� ���� �� ����� ������� �������� ��������.";
        	link.l1.go = "22 Next Day";
		break;

 	case "22 Next Day":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 26", 1.0);
		break;

	case "23 At Cayman":
            	dialog.text = "����! ����! �����������! �� ����� �� ���� �������! ������� ������ ���������, � ��� ����� ��������� ���� ������?";
        	link.l1 = "������ �����. ��� ����� ����� ������ �����������. ���� �������� �������.";
        	link.l1.go = "23 Exit";
			Characters[GetCharacterIndex("David")].Dialog.CurrentNode = "26";
		break;

 		case "23 Exit":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
			sld=characterFromID("David");
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;


//**************** �������� �1 - �������� ����� ���� *****************
//**************** �������� �2 - �������� ������ ����� *****************
	case "24":
            	dialog.text = "";
        	link.l1 = "������...";
        	link.l1.go = "25";
		break;

		case "25":
            	dialog.text = "�... � ������� �� ��� �����, �������. � ��� �����������. ����� ���� ��������...";
        	link.l1 = "";
        	link.l1.go = "25 End Quest";
		break;

 		case "25 End Quest":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
	if (pchar.quest.NSmithyQ == "Carrol")
	{
		AddQuestRecord("Smithy", "16");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("David");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_6_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_7_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_8_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_9_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_10_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
	if (pchar.quest.NSmithyQ == "Smithy_Kill_David")
	{
		AddQuestRecord("Smithy", "17");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("Carrol");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_1_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_2_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_3_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_4_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_5_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
		break;


//**************** �������� �3 - �������� ���� *****************
	case "26":
            	dialog.text = "��, �� ��������! ��� �� ��������! �����������, ������� ��������! ���, �� ��� � ���� �� �����! ���������, ������!!!";
        	link.l1 = "���?! �� �� ������! ��! ��! ����! �������! ׸��! �� ��, ��������...";
        	link.l1.go = "26 End Quest";
		break;

 		case "26 End Quest":
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
       			GiveItem2Character(sld, "blade_5");
        		EquipCharacterByItem(sld, "blade_5");
		LAi_SetImmortal(sld, false);				
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "Quest_Smithy_July_War");
		LAi_group_FightGroups("Quest_Smithy_July_War", LAI_GROUP_PLAYER, true);
		LAi_SetFightMode(pchar, true);
		LAi_SetImmortal(sld, false);
		pchar.quest.NSmithyQ = "Smithy_Kill_All";
		Pchar.quest.Quest_Smithy_July_War.win_condition.l1 = "NPC_Death";
		Pchar.quest.Quest_Smithy_July_War.win_condition.l1.character = "July";
		Pchar.quest.Quest_Smithy_July_War.win_condition = "Smithy 31";
		DoQuestCheckDelay("Smithy 32 JulyDead", 5.0);
		break;



	case "27":
            	dialog.text = "�������... �-�-�...";
        	link.l1 = "�, ����!!! ������!!!";
        	link.l1.go = "27 End Quest";
		break;

 		case "27 End Quest":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
			LAi_KillCharacter(characterFromID("July"));
			LAi_SetPlayerType(pchar);
		sld=characterFromID("Carrol");
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "17";
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;



//************************ ��������� �������� ****************************************
		
		case "DvorJer 1":
            	dialog.text = "����� ��� ����������,  " + GetAddress_Form(NPChar) + ". ������� ����� ��� ����, �� �� ������� ���, ��� �� ��������� �����.";
        	link.l1 = "��� ���? �, ��������, �� �������� ��� ���-�� �������� ���?";
        	link.l1.go = "DvorJer 2";
		break;

		case "DvorJer 2":
            	dialog.text = "���������� �����,  " + GetAddress_Form(NPChar) + ". �� ������ ��������, ����� ��, ��� ������ ��������� �����, ���������� ����������� �� ����������� ������ ������. �� ������ ����� �������� ���, �������, '��� ��� ��������� ����� ����� ����, ��� ����������� � ��������'. �� ��������, ��� ��� ����� ����� � ����� ������, � �� ������� ���������� ��������� ����.";
        	link.l1 = "������, � �����,  ��������, � ���������� ���� ����������. ��� ���-������?";
        	link.l1.go = "DvorJer 3";
		break;

		case "DvorJer 3":
            	dialog.text = "��, ���� ��� ���� ����. ���� � ���, ��� ��� ����� ����� ���� �������, � ����� ���������� � ���. �������, ��� ����� ���������� � ����, ����� �� ���������. ��� ������� ���� ������� ������.";
        	link.l1 = "������ ������? ��� ���?";
        	link.l1.go = "DvorJer 4";
		break;

		case "DvorJer 4":
            	dialog.text = "�, " + GetAddress_Form(NPChar) + ", �� �� ������ �? ��� ���������� ���� ���� ������� ������ � ������ ����� ����. ��� ����� ����� ����� ��������� � ����� ���������� ��-�� �� ������. ������ ��������, ���, �� ��� ������, ��� ������ ��������� � ������� �����, ������ ����. ��� �������, ��� ����� ���������� � ����, ��� ��� ����� �����. ��� ������������ ����� �����, � ���� ������ ����. Ÿ ������� �� ������ �����, ����� �� ��������.";
        	link.l1 = "�������, ��������, � ��������� � �������� � ���.";
        	link.l1.go = "DvorJer To July";
		break;

 		case "DvorJer To July":
		Locations[FindLocation("SanJuan_town")].reload.l32.disable = false;
		pchar.quest.NSmithyQ = "";
		sld=characterFromID("Quest_Smithy_Dvoretsky");
		LAi_SetPlayerType(sld);
		LAi_SetCitizenType(sld);
		sld.talker = 0;
		sld=characterFromID("July");
	//	ChangeCharacterAddressGroup(sld,"house", "loc", "aloc0"); // ��������, ������� �� ������ �����
		sld.protector = true;
		sld.protector.CheckAlways = 1;
		characters[GetCharacterIndex("July")].dialog.currentnode = "1 July SanJuan";
                NextDiag.CurrentNode = "Third time";
		DialogExit();
		break;

	case "Third time":
            	dialog.text = "������ ������������," + GetAddress_Form(NPChar) + "! ������ ��� ���";
        	link.l1 = "";
        	link.l1.go = "Exit Dvor 3";
		break;

		case "Exit Dvor 3":
                NextDiag.CurrentNode = "Third time";
		DialogExit();
		break;



	}
}


