// ����� ���� � ������ ������
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
		if (pchar.questTemp.GothicSmithy == "Smithy_DavidSmith")
		{
	Locations[FindLocation("FortOrange_tavern")].reload.l2.disable = true;
            	dialog.text = "�, " + GetAddress_Form(NPChar) + " " + PChar.name + ", �������-��. ������ ������, � ��� ��������.";
        	link.l1 = "�� ��� ��, ����� ���� ��������. ������ ������� � ����.";
        	link.l1.go = "2";
        	link.l2 = "���, �������, ������������� � ���� �� �����, ������ ����. � � ��� ��������.";
        	link.l2.go = "3";
			sld.talker = 0;
		}
		else
		{
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
		}
		break;

 		case "Exit":
                                      NextDiag.CurrentNode = "Fist time";
		DialogExit();
		break;


		case "2":
            	dialog.text = "��, " + GetAddress_Form(NPChar) + " " + PChar.name + ", � ��� ������� ������. ���������� ������� �� � �����. ��� ������� �������� ������ ����� ������� ������� ����, ��� ���������� �����. � ���-�� ����� ������� ����� ������� ��������� - ������ ������ �������� ������ ��������. �������� ������.";
        	link.l1 = "��� ��� �� � ���� ��� ������, ������ ����?";
        	link.l1.go = "4";
		break;

		case "3":
            	dialog.text = "�, " + GetAddress_Form(NPChar) + " " + PChar.name + ", � ������ �������. ������, �� �� ��������� � ����� �������. ����� ���� � "+ GetFullName(Pchar)+" - � ������ ������� ������������ �������.";
        	link.l1 = "��� ��� �� � ���� ��� ������, ������ ����?";
        	link.l1.go = "4";
		break;

		case "4":
            	dialog.text = "�� ����� ������,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". � ����� ��� �������������� ������, ������, 1 000 000 ����, � �� ������������ � ������������ ���� �� ����� �������� ������. ������ ������� ������ �� �������, �������� ��� ��� �� � ���������. ���������,  " + GetAddress_Form(NPChar) + " " + PChar.name + "?";
        	link.l1 = "������� - �������? ���� �������? ������ �� ������������� �������� �����������. � ������.";
        	link.l1.go = "5";
        	link.l2 = "��� ����� ����� ������ � ����, ������ ����, ����� ������.";
        	link.l2.go = "6";
        	link.l3 = "����� ������ ���� ���� ����������. ��������, ������ ����, �� � �� ������. ����� ������� ������. ��������.";
        	link.l3.go = "Smithy End";
		break;

 		case "Smithy End":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_44.wav");
		if (pchar.questTemp.GothicSmithy == "Smithy_DavidSmith")
		{
    		AddQuestRecord("Gothic_Smithy", "3");
		CloseQuestHeader("Smithy");
		PChar.quest.Smithy_David_End.win_condition.l1 = "ExitFromLocation";
		PChar.quest.Smithy_David_End.win_condition.l1.location = PChar.location;
		PChar.quest.Smithy_David_End.win_condition = "Gothic_Smithy_End";
		}
                                      NextDiag.CurrentNode = "End time";
		DialogExit();
		break;

	case "End time":
            	dialog.text = "��� ������ �� � ��� ��������,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". ����� ��� �������� ��� �������.";
        	link.l1 = "��� �����.";
        	link.l1.go = "Smithy End";
		break;

		case "5":
            	dialog.text = "�����������,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". ������������� �� ������� � �������� �������. ����� ��������� ������, ���� ��� ����� �������� � �������������. ���� �� ���� �� �������� �� �������, �� ����������� ������. ���� �� ���������� ������, ���� ���������� ������ ���������� ����. ��� ������ ��� ����� ��������� - � ���� ��������. � �������� ������ ��� ��� 300 000 ����� ����.";
        	link.l1 = "�� ����� � �������, ������ ����. � �����������.";
        	link.l1.go = "Smithy_G";
		break;

		case "6":
            	dialog.text = "���,  " + GetAddress_Form(NPChar) + " " + PChar.name + ", ��� ���� �� �����. � - ��������, �� - �����������. ��, ��� ��� ����� �����, ��� ���� �������. ����� �� ����.";
        	link.l1 = "������, ������ ����, � �� �����. ��������� ��������?";
        	link.l1.go = "5";
        	link.l2 = "��� �, ����� ��������. ����� ������� ������.";
        	link.l2.go = "Smithy End";
		break;


 		case "Smithy_G":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "...";
        	                   link.l1.go = "Go To Curacao"; 
		break;

 		case "Go To Curacao":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
    		AddQuestRecord("Gothic_Smithy", "4");
	                   ChangeCharacterComplexReputation(pchar, "nobility", -20); 
                                      AddMoneyToCharacter(pchar, 300000);
	                   log_info("������� ����� 300 000");   

		PChar.quest.Smithy_David_Start.win_condition.l1 = "ExitFromLocation";
		PChar.quest.Smithy_David_Start.win_condition.l1.location = PChar.location;
		PChar.quest.Smithy_David_Start.win_condition = "Gothic_Smithy_Start";
                                       NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;

	                  case "Second Time":
            	                  dialog.text = "�� �� ��� �����,  " + GetAddress_Form(NPChar) + " " + PChar.name + "? ����� ��� ����� ������ ������ ��������?";
        	                   link.l1 = "� ��� ������� ��� ����.";
        	                   link.l1.go = "Second Time Exit";
		break;

 		case "Second Time Exit":
                                      NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;


// � ������� ���� - ���

		case "SmithyDavid_SantLous":
            	dialog.text = "�,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". �������, �������� ��������� ���������, �� ��� ��?";
        	link.l1 = "��, ������ ����. � � ���� ���������� ��������� �������� � ���.";
        	link.l1.go = "8";
        	link.l2 = "�������� ������ ������. � ����� �� �������� ��� ������.";
        	link.l2.go = "10";
		break;

		case "8":
            	dialog.text = "�����, � �� ���������� �������� ��� �� ��� ������,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". �� �������, ��, ��� ����� ���, ����� ��� ����� ����� ���.";
        	link.l1 = "� �� ������ ����� �����������, ���� � ����. � ��� ���� �������� ����� � �������-��-���. ��������, �� ���������� ��������� ��� ��� ��� ������� ��������?";
        	link.l1.go = "9";
		break;

		case "9":
            	dialog.text = "�� ��� ��, ����� ����� ���. �� ����� �������, ������ ������ ���� ����. � �������-��-���, �� ���, ��������, ������ ���� ���� ����.";
        	link.l1 = "����� ����?";
        	link.l1.go = "11";
		break;

		case "10":
            	dialog.text = "�����, �� �� ��������� ���� ������,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". ���� �� ���������. �� ����� �� �������� ������, � ������� ������, ������ ������ ���� ����.\n� �������-��-��� �� ���, ��� � �������, ������ - ��� ����� ���� ���� ���� ����.";
        	link.l1 = "����� ����?";
        	link.l1.go = "11";
		break;

		case "11":
            	dialog.text = "��, ���� ����, �����. Ÿ ������ ��� ����� �������� ����. �������, ��� ����� � ������ � ������ ���������� ������� ��� ������ ����� ������� �����.";
        	link.l1 = "���, ���������, � �� ������� - ���� � ������ ��� �����?";
        	link.l1.go = "12";
		break;

		case "12":
            	dialog.text = "������ " + PChar.name + ", �� �����������, ����� ���. �� ����� ������. �� ����� �������,  ��� ���� ���-�� ����� ��������� �������� ����� ������������, � ���� � ����, � ������� �������� �����.\n������ �� �� ������ ����� � ����, ��� ���� - �����.";
        	link.l1 = "�� ����� ��� ������� ���� ����? � ������ � ���� ������ �� ����?";
        	link.l1.go = "13";
		break;

		case "13":
            	dialog.text = "��, ������ ��� ������ �� ��� - ��-�����, ��� �������� ��������. �� ����� ������ �����.\n������ ��� ������ ������� ����� � ����� ������ ��������������. � ���������, ��� �����, ��� ��, � ���� �������, ������� � ������� - ��� ��������� ��������� ����, �� � ������, ��� �� ����������.";
        	link.l1 = "���������-���������, � �� ����� � �� ���� �� ���� ������! �� ������ ����, ����� � ���� ������� �� ����� �������� ������ � � ��� ������!";
        	link.l1.go = "14";
		break;

		case "14":
            	dialog.text = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+", �� ����� ���� �� ��������. �� ����� �������, � �� ��������, ������ ��� ����� ����� ��������, ��� �� - �����.\n�� ���� ������ �� ����������, � ����� ���, ����� ����� ����, � ��� �� ��� ����� ����� ����. � ������ ��� �����������.";
        	link.l1 = "� � ���. � ���� ��� ������ ����� ����� � ������ � �� ���� �� �������� ���� ��������������! � �������� ��, � ��� �� ������� ����.";
        	link.l1.go = "15";
		break;

		case "15":
            	dialog.text = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+", ����������, � �� ������� ��� ��������� �� ����. ������, � ������� ��� ��������� ����.\n�� � ����� ���� ����������� ������� �������� ���� �����, �� �������. ��������, �������, ������... ������ ����� ������. ��� ����� ���� �������� ������.\n�� ���� ������ �� ����� ������� ���������������� �� �������, �������� ������ ��������, � ��������, � ������ �� ���������� �� ��� ����.\n��... ��������� ����� ����� ��������� ������. ����� ������ ������ ������ �� ����. ��� ������ ������ ��������, ������� ��� ��������.\n��� ������, ����� ���� ������� ���, � � ���� ��������������� ����������. �� ���� ��� �� ��������! �� �����������. � ��, ��� �� ��� �������... �������� �����������.\n���� �� � ������ ����������, ��� �������� ������� � �� �� ���� ������ � �������, �� �������� ���, " + GetAddress_Form(NPChar) + " " + PChar.name + ", �-�� ����, ��� ����� ��������� �������.\n���� � �������. ��� ������� � ��������� ������ � � �� ���� ������ ����� ������� � �� ��-�� � ��������. ��� �� ���� ��������� ��������, ������ ��� ����� ��� ������ ������, ��� ����� �������� � ��.\n���� �������� ��� ������������, �� �� ���� ��� ��� ��������, ���� ������� - ���� �� ����� ������� ����� �� ����������. � �����, " + GetAddress_Form(NPChar) + " " + PChar.name + ", �� ������ � �� �������� - �� ��� ��� �� ������ ��������.\n���� ��� ��� ������� �������. ������ ����� � �������� ���� ����� ������� ��������� �� ���������� - ����� � ������ ��� ����� ������� ��������� � ������� �����������.";
        	link.l1 = "� ���� � ��������?";
        	link.l1.go = "16";
		break;

		case "16":
            	dialog.text = "�� ��������� �������� �����, ����, �� ��� � ����, � ����� �� �� ��� ������ ����� ���������� ������.\n����� �������� �� ���, � ���� � ����������� � ���, ��� �����, ����� � ��� ����� � ������ ����� �������� ����?\n�� ���� �� �������, ��� ������� ������������� ���� �������������� ������, " + GetAddress_Form(NPChar) + " " + PChar.name + "?\n� ����, �� ����, ������� �� �����������.";
        	link.l1 = "��� �, �������, �� �����, � ���� ������ ��� ������. � ���� ���� ����, �� ��� ������ � ������ ��� � ������ ���� ������, �������, �� ������ ������� �� ��������� ��� � ����. ���������� � ���� �� ����� �������� ������������� ��� ����.";
        	link.l1.go = "17";
		break;

		case "17":
            	dialog.text = "� ��� �� ����� ��� �� �����������, " + GetAddress_Form(NPChar) + " " + PChar.name + ", ������� ������� ��� ��������� ����������� ���� ����, ���� � ��� ��� ��������� ��� - �� ��������� �� ���������� ��������.\n��, ��� �� �����, �� ����� - ��������� ���� ����� ������ - � ������� ����.";
        	link.l1 = "��� ��� ������ ������ �����?";
        	link.l1.go = "18";
		break;

		case "18":
            	dialog.text = "������� ������, " + GetAddress_Form(NPChar) + " " + PChar.name + ". � ��� �� ������� ��� ����� ������ �� ���������� � ������������, �� � ���� ������� �������, �� � �� ���� - ���� �� ������������� - � ������� ���� ��������� � ����, ��� ������ ��������� �����.\n��� ���������� � ���� � �� �������, �� ���������. ������������� ���� ���������� � ������ �������� ����� ��������.";
        	link.l1 = "� ����� ���, ������ ����. � �����������. ������ ��� ��� ����� �� � ��� �� �������...";
        	link.l1.go = "19";
		break;

		case "19":
            	dialog.text = "�����, �� � ������ � ��, ������� ������ �����, ������� ���� ���������� ����� ������.";
        	link.l1 = "��� ���, �������...";
        	link.l1.go = "20";
		break;

		case "20":
            	dialog.text = "��, " + GetAddress_Form(NPChar) + " " + PChar.name + ", � ��� ����. ���� � ��� ����� ����� �����������, ����� ��� ��� ����� �, ����������, ��������� ��, ��� � ����� �.";
        	link.l1 = "���... ������, � ��� �����. �� ��������.";
        	link.l1.go = "Go To Antigua";
		break;

 		case "Go To Antigua":
	                   pchar.questTemp.GothicSmithy = "Smithy_LeFransuaTavern";
    		AddQuestRecord("Gothic_Smithy", "9");
                                      NextDiag.CurrentNode = "Third Time";
		DialogExit();
		break;

	case "Third Time":
            	dialog.text = "������ ���� �� ���������, " + GetAddress_Form(NPChar) + " " + PChar.name + ", ������ �������������. ������ ���.";
        	link.l1 = "��� ��������.";
        	link.l1.go = "Third Time Exit";
		break;

 		case "Third Time Exit":
                                      NextDiag.CurrentNode = "Third Time";
		DialogExit();
		break;









	case "20 At Cayman":
            	dialog.text = "�, " + GetAddress_Form(NPChar) + " " + PChar.name + "! �� ����� �������! ���� ���� � ��� �����. ���������� ��� ������� ������ ����!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "3 At Cayman";
		break;

 		case "20 Exit":
                NextDiag.CurrentNode = "Third Time";
		DialogExit();
			sld=characterFromID("Carrol");
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "21":
            	dialog.text = "�� �������� ��� ��������� �������, " + GetAddress_Form(NPChar) + " " + PChar.name + ". �� ���� � ���� ������� ����.  � ������ ����� ���, � �� ��������� �� ����! ��������� ���� ����, � � ����� ���������� ���!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "4";
		break;

	case "22":
            	dialog.text = "�� - ����� ������ �����! �������, �� ������ ��� ������! �� ������ ��� '�������'! ���� �� ������ ���� �����!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "5";
		break;

	case "23":
            	dialog.text = "��������, �������! ��� ������ ���� ��������! ���� �� ���� �������� �� ��� ���������� ���������, �� ���� - �� ���������� ����. �� �� ��� ����� ����� � ������ ����� - ��� ����� ����� � �������. " + GetAddress_Form(NPChar) + " " + PChar.name + " - �������� �!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "6";
		break;

	case "24":
            	dialog.text = "���?! � �� ��� ����� �������, ������, �������? ������ ����� ����� ����������?!";
        	link.l1 = "� ���������� � ���� ���������� � ���-�����, � ������� ���, ������ ����, �� ������ ��� ����� ��� ���� ����. ��� ���������� ��� ����������� ����� ������� � ��������� ������ ���. � ��� � �����.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "7";
		break;

	case "25":
            	dialog.text = "��, ������! ������ ������������ � ���, "+ GetFullName(Pchar)+"! � � ������ ��� ����� ������� ��������� � ����! ����� ����, �������.";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "8";
		break;

	case "26":
            	dialog.text = "�������, ������! �� ���� � ���� ���������, �����? ��� �����, � ��� ��� ��� �����, � ������� ��� ������ �����������! �������� ��������� ����� ��������� ������.";
        	link.l1 = "������ ����...";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "9";
		break;

	case "27":
            	dialog.text = "" + PChar.name + ", ������ �� �������! ������� ��, �������! � �� ���� ������ �����! � ����, ����� ��� ������� ������ - ����� � ������! �� ���� ������!";
        	link.l1 = "������, ������ ����. � ������� ��� ��������. ����� - ����!";
        	link.l1.go = "Kill Carrol";
        	link.l2 = "���, ������ ����. ��� ���� �� �����. ��� ������� ���� �������� � ����� �����. � ���� ������ � ������� �� �����.";
        	link.l2.go = "Kill David";
        	link.l3 = "�� ��� ������� ���, ��� �������� ������ �������! �����, � ������ ��� ����, ���� ������� ��� �� ��� �����. ���� ��� ������������� - �� ����� � ���������, �����?";
        	link.l3.go = "Kill All";
        	link.l4 = "��������� � ������, ��, ��� ��������� �������. �� ����� ��. ����� ������.";
        	link.l4.go = "Alive";
		break;




//**************** �������� �1 - �������� ����� ���� *****************
 	case "Kill Carrol":
                NextDiag.CurrentNode = "Third Time";
		DialogExit();
		sld=characterFromID("Carrol");
			LAi_SetActorType(sld);
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "10";
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "28 AftrKillCrrl":
            	dialog.text = "�����, �����, " + GetAddress_Form(NPChar) + " " + PChar.name + "! �� ��-���� ������� ���! �� ���� �����������! ��-���� � ����� ���������� ��������, �� ��� ��," + GetAddress_Form(NPChar) + " " + PChar.name + "? � ���� ������� � ���������� - �� ������, ��� ������ ���������! �������-�� ��� ����� ������.";
        	link.l1 = "�� ���� ������ ���������, ������ ����. � ��������" + GetSexPhrase("","�") + " ���� ���������. ���� � �������� ���� �������?";
        	link.l1.go = "29";
		break;

		case "29":
            	dialog.text = "�������, �������, " + GetAddress_Form(NPChar) + " " + PChar.name + "! � ���������� ���������� ��� ��� ��� ������! ��� ��� - �������. �� ��������� ��. ��� ��� ������� ���, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". �� ������� ���� ����� ���������� ��������� �� ���� �������. � ������, �������� ���, �� �� � ������� �������� ������. ��������, " + GetAddress_Form(NPChar) + " " + PChar.name + ". � ����� ���.";
        	link.l1 = "";
        	link.l1.go = "29 Exit";
		break;

 		case "29 Exit":
		AddMoneyToCharacter(pchar, 700000);
                                      NextDiag.CurrentNode = "Third Time";
		DialogExit();
			sld=characterFromID("July");
			LAi_SetActorType(sld);
			Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "24";
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;



//**************** �������� �2 - �������� ������ ����� *****************
 	case "Kill David":
            	dialog.text = "��� ���? � ������ ����������� ����,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". � ����� �� - ������������. � �� ����� ���� ������ ������� �������. ������ ��������. �� ��� ��� �� ����� �����. �������, ����������, ������ " + GetAddress_Form(NPChar) + " " + PChar.name + " � ������ ����. ��� � ������ ���� �� ��������.";
        	link.l1 = "� ��� ������ ����, ����� ����. � ����� ������� � ��������� �����������.";
        	link.l1.go = "30 Kill David";
		break;

 		case "30 Kill David":
                NextDiag.CurrentNode = "Third Time";
		DialogExit();
		sld=characterFromID("SmithyDavid");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");
		sld=characterFromID("Quest_Smithy_Pirat_6_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");
		sld=characterFromID("Quest_Smithy_Pirat_7_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");
		sld=characterFromID("Quest_Smithy_Pirat_8_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");
		sld=characterFromID("Quest_Smithy_Pirat_9_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");
		sld=characterFromID("Quest_Smithy_Pirat_10_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_David_War");

		sld=characterFromID("Carrol");
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
			LAi_SetWarriorType(sld);
		sld=characterFromID("Quest_Smithy_Pirat_1_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("Quest_Smithy_Pirat_2_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("Quest_Smithy_Pirat_3_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("Quest_Smithy_Pirat_4_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("Quest_Smithy_Pirat_5_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
			LAi_group_FightGroups("Smithy_Pirat_David_War", LAI_GROUP_PLAYER, true);
			//LAi_group_FightGroups("Smithy_Pirat_Karrol_War", "Smithy_Pirat_David_War", true);
		pchar.quest.NSmithyQ = "Smithy_Kill_David";
		LAi_group_SetCheck("Smithy_Pirat_David_War", "Smithy 30");
		break;



//**************** �������� �3 - �������� ���� *****************
 	case "Kill All":
            	dialog.text = "���-���? " + GetAddress_Form(NPChar) + " " + PChar.name + ", ���, ������, ������ � ������ �������! ��, ���, �������� ���� ����?! ��, ���, ������, ��� ������ ����� ��� ����� � ������� �� ���� ������ ����?! �������, ������ ���
�� ���������! � ����� � ������ ����!";
        	link.l1 = "�� ������� �������, �����. ����� ��� ��� ������? � ������ ���� �������� ��� �� ������ ��������� ����� ������� � ������� ����.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "13";
		break;



//**************** �������� �4 - "������" ������� ��������� *****************
 	case "Alive":
            	dialog.text = "� ��� �� �����������, " + GetAddress_Form(NPChar) + " " + PChar.name + " ? �� ���, ������������� �������, ��� ��, ������, �����, ����� ������ ���������? ������ �� ������� � ����? �� ������ �������� � ���, ����� ������ ���� ������� ���� � ������ �����? ���� � ����������� ��� ������! � ����� ���, ���� ��� ������! � ���, ��, ������, ������ ��������� ����� ����������? � ��� �����, ��� ������, " + GetAddress_Form(NPChar) + " " + PChar.name + " ! ��� �� ����� ��������!";
        	link.l1 = "������ ����, �� ����� �������. �� ������ ������, ��� ������ ������� �����, ��� �������. ��� �� �����������. � ��� ���� � ��� ���������� �����, �� � ��� ������ ���� �� ����������. ������� ���������� �� ���������, ���� �� ��������� ���� ���� � ����� �����.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "14";
		break;

 	case "31":
            	dialog.text = "���, � ������������� ������! ��� �� ��! � ��� �����, ��� ����� �� ������! � ��," + GetAddress_Form(NPChar) + " " + PChar.name + ", ������ ������ ���������! � ��-��������, ������ � ���� ����� ������ �� ������, ��� ������ ���� �����! �� �� ������ ������� ����! �� ��������� ������ ��������!";
        	link.l1 = "�� ��, ������ ����. � �� ����, ����� ����� ����������� ���-���� �����. ������ ������������. � ����� ����� �� �����, ��� � � ���. ������ ��������� �� ������� � ������ �������������� ���������� ������ ���� ����! �� ��� ���������� � ��������.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "16";
		break;

 	case "32":
            	dialog.text = "���!!! �� ������ ������ ��������� ���������, " + PChar.name + " ! �� ������� ���������� ���������! ������� �� �� ������������! � ��� ��� �� �������! ������ ���� �������," + PChar.name + " , ������ �� �������, �� � ����� ���� ��������!!!";
        	link.l1 = "";
        	link.l1.go = "32 Kill July";
		break;

 		case "32 Kill July":
                NextDiag.CurrentNode = "Third Time";
		DialogExit();
			sld1=characterFromID("SmithyDavid");
		LAi_SetActorType(sld1);
		LAi_ActorAnimation(sld1, "Shot", "Smithy 34", 1.5);
		break;

 	case "33":
            	dialog.text = "�... �... � ��... ���...";
        	link.l1 = "�� - �������� ����������� ��������� ������ � ������ �� �������� �� ��!";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "19";
		break;

 	case "34":
            	dialog.text = "" + PChar.name + " ... ����� �����. ������� ����. �... � �����. � �� ����, ����� ��� ��� ���� ��� ���, ��... �� ����� �������. ����� ������ �� �����. ��� �������� ���� �������... �� ��-�� ����...";
        	link.l1 = "��� ������������� ����� ����... �� ������ ������... ��������...";
        	link.l1.go = "35";
		break;

 		case "35":
            	dialog.text = "" + PChar.name + " ... ��������� ���� ����� ����� � ���� ���������� �� ������-���� � ���-�����... ��� ����� ����� ������� ��� ��� ���-���...";
        	link.l1 = "������, ������ ����... � ����� �����...";
        	link.l1.go = "35 End Cayman Story";
		break;

 		case "35 End Cayman Story":
                NextDiag.CurrentNode = "Third Time";
		DialogExit();
    		AddQuestRecord("Smithy", "19");
			Lai_setActorType(pchar);
			LAi_ActorGoToLocator(pchar, "reload", "sea", "Smithy 35", -1);
		break;

 	case "36":
            	dialog.text = "�," + PChar.name + " . ��� ������ ��� �����. �������, ��� ������. ���� � ���, ��� � ���� ������� ����� ���� ��������� ����. ���� � ������ ��� ������ �� ���� ������. �������� ��, ��� � ������ � ������� ����� ����.";
        	link.l1 = "��������, �����, �� � �� ���� ����� �� ����� ����, ��� ���������. � �������� ���� ����� �������� � ������ ������ ������. � �� ������ �... � ��������� � ��� ���� �������.";
        	link.l1.go = "37";
		break;

 		case "37":
            	dialog.text = "���-���, " + PChar.name + " . � �� ����, ��� ������ ��� ���-�� ��������... ���� ������ �����, ��... ��� ���� �, �����, ��������� � ���� ����. � ���� �. � ����� ����� ���. � ���� �. � �� ������ �������� ��� � ��������. �� ������ �������. ��� ���� ������ �����? ��� ���� ��� ��������� ���. ��������, " + PChar.name + " , � ������... � �� ����... ������ �������� ������, ����� ���, �� ������� ����� �� �... �������. ������� ��� ��� ���, ��... ������� �������. ������... ������ �� ���� ������� ������.";
        	link.l1 = "������, ���� �� �����������. � ������ ��. ���, �������������, ������ ������ ���� ����� �������. ��������, �����. ������ � ����.";
        	link.l1.go = "37 End";
		break;

 		case "37 End":
                NextDiag.CurrentNode = "End Quest Time";
		DialogExit();
		sld.protector = false;
    		AddQuestRecord("Smithy", "20");
		CloseQuestHeader("Smithy");
		AddMoneyToCharacter(pchar, 700000);
		Log_SetStringToLog("700 000 �����");
// �������� ��� � ������� �������� �� ������
	Locations[FindLocation("SanJuan_Town")].reload.l32.disable = true;
	Locations[FindLocation("SanJuan_Town")].reload.l35.disable = true;	
		break;

 	case "End Quest Time":
            	dialog.text = "��� ������, ���� �������, ��� ���-�� ���������, �� ���� ��� �� ���...";
        	link.l1 = "���-�-�... ��� �����, �� �����...";
        	link.l1.go = "End Quest Time Exit";
		break;

 		case "End Quest Time Exit":
                                      NextDiag.CurrentNode = "End Quest Time";
		DialogExit();
		break;





	}
}


