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
            	dialog.text = "� �� ����� ���� ������. ������ ��� ������� ����� ���� � �������������. � ��� ������ ��������, ��� ������ ��������� ���������.";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "23";
	break;

	case "6":
            	dialog.text = "���� ����� ������� ����� ������ ����, ������ ����������. �� ��� ������ � �� �����, ��������? ���� ���� ��������� ����, �� �� �� �����, ������ ��� �� - ������ ������ ��������� ��������� ������������ ������� ������ �������!";
        	link.l1 = "����-����-����! �� ���� - �����������, ������? �� ��� - �����������, �� ���� �� ���������, ��� ����� �� ���� - ���� ����, ������.";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "24";
	break;

	case "7":
            	dialog.text = "� ������� ���, ������ ����! ���-���-���! ������ ����� �� ����, �� ��� �����... ����� � ���� ���� ���� ������� ���������� �����. �� ������ ��� ������! ���� �� ���� ������� � �� �� ������ ���� ������ ������ ������.";
        	link.l1 = "��... � �������?";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "25";
	break;

	case "8":
            	dialog.text = "�� ������ ��� ������, " + PChar.name + "! �� ��, �������� ���! � ����� ���� ��.";
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
	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUDAREHITME.wav");
            	dialog.text = "�� ������� ����� ���! �� ������ ������������ �������! ������, �������� ������� � ��������!";
        	link.l1 = "��� �� ��� �������, �����! ���� �� ������ ����� ��������! ����!";
        	link.l1.go = "Kill Carrol";
	break;

	 	case "Kill Carrol":
                                         ResumeAllSounds();
                                          NextDiag.CurrentNode = "First Time";
		DialogExit();
		AddDialogExitQuestFunction("GothicSmithy_IslaMonaShore3");
		break;


//**************** �������� �2 - �������� ������ ����� *****************
	case "11 AftrKillDvd":
	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_WHATAREYOUDOING.wav");
            	dialog.text = "������, ��� ��� � �� ��������� �� ����! �� ������ ���������� �����, � �� ���� ��� ������! �����������! ����������! � ������ ���� ������ ���� ������.";
        	link.l1 = "����� �������� ��������, ������ ����. �������, �� ������ �� ������ ����-�����?";
        	link.l1.go = "12";
	break;

	case "12":
            	dialog.text = "��������. � ����������� ��� ���� �������� ���, ���� � �����, ��� �� �������� ���������� �����. �����, �� �������� ��� ������. � ������, ����� ��� ��������, �� �� � �������� ������� ������ ������. ������. ����� ���� ������ ����������.";
        	link.l1 = "";
        	link.l1.go = "12 Exit";
	break;

 		case "12 Exit":
	                     CloseQuestHeader("Gothic_Smithy");
                                          AddQuestRecord("Gothic_Smithy", "18");
		TakeNItems(pchar, "icollection", 1);
		Log_Info("�� �������� ���������");
		TakeNItems(pchar, "gold_dublon", 1000);
		Log_Info("�� �������� 1000 ��������");
		PlaySound("interface\important_item.wav");
                                         NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
		LAi_SetActorType(sld);
		Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "24_0";
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

//**************** �������� �3 - �������� ���� *****************
	case "13":
	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUMURDERER.wav");
            	dialog.text = "������! ����������� - ������ ����� ������������, ������ ���� ���� ������ � ��� ����� � ������ �������!";
        	link.l1 = "���������, ����������! ����� ���� ������!";
        	link.l1.go = "13 Exit";
	break;

	case "13 Exit":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	AddDialogExitQuestFunction("GothicSmithy_IslaMonaShore5");
	break;


//**************** �������� �4 - "������" ������� ��������� *****************
	case "14":
	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_STUPIDBEASTKILLED.wav");
            	dialog.text = "����� �����! � �� ��������� ������ ������ � ���� �������! �� ��� ����������� ���, � � ���� ������� ���� ���� ����������! ��� �� ����� ��� ������!";
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
            	dialog.text = "��������! �������! ��� �� ������ � ����� ���������?";
        	link.l1 = "���... ��� ������.";
        	link.l1.go = "18";
	break;

	case "18":
            	dialog.text = "�, ���! ��-�-�-�! � �� ���� � ���! �����, ��... ��... ���... ��������...";
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


	}
}


