// ������ ������ ��� �� ���������� ����
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, �������, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;

//---------------------------------------------����� ����� ������------------------------------------

                                                          case "Torus_MayakDieenemy":
			dialog.text = "�� ��� ��� �������. ������ ������� ����, � ����� � ���������� �� �����. ������� ������ ����������, ������ �������� �� ����������!";
			link.l1 = "������, ��� �...";
			link.l1.go = "Torus_MayakDieenemy_1";
  		                   break;

                                                         case "Torus_MayakDieenemy_1":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "Torus_Mayak_Dieenemy":
			dialog.text = "� ��� �������� �����?";
			link.l1 = "������ ����� �� �� ����� �� ���� ������ ����� ���� ���...";
			link.l1.go = "Torus_Mayak_Dieenemy_1";
  		                   break;

                                                          case "Torus_Mayak_Dieenemy_1":
			dialog.text = "������, ����� ��������� ���� �����, ������� ���� ������ �����������. � �� ������� ����� � �����, ����� ���� �����, �������� ��� ��� ���������, � � ���� ������� �� ��������� �����!";
			link.l1 = "������, �������...";
			link.l1.go = "Torus_Mayak_Dieenemy_2";
  		                   break;

                                                         case "Torus_Mayak_Dieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
                                                          sld = characterFromId("Torus");
                                                          LAi_SetActorType(sld);
                                                          LAi_ActorGoToLocation(sld, "officers", "reload5_1", "Dominica_Lighthouse_02", "officers", "reload5_1", "", 50.0);

		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;

                                                          case "Torus_Mayak":
 	                                       PlaySound("VOICE\Russian\GOTHIC\GG\GG_54.wav");
			dialog.text = "";
			link.l1 = "�� ��, ���� ���, ���� �� ������� ������!";
			link.l1.go = "Torus_Mayak_1";
  		                   break;

                                                          case "Torus_Mayak_1":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_01.wav");
			dialog.text = "������ �� ���� ������� �������� ����?";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_2";
  		                   break;

                                                          case "Torus_Mayak_2":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_02.wav");
			dialog.text = "������ �� ������ ������?";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_3";
  		                   break;

                                                          case "Torus_Mayak_3":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_15_03.wav");
			dialog.text = "";
			link.l1 = "��� ���� � ������ ���������, � ���� ��������� ��������� ����!";
			link.l1.go = "Torus_Mayak_4";
  		                   break;

                                                          case "Torus_Mayak_4":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_04.wav");
			dialog.text = "��, ��, �� ��������� ���� - �� ���������, ��� ����? ���������� ���� ����!";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_5";
  		                   break;

                                                          case "Torus_Mayak_5":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_15_05.wav");
			dialog.text = "";
			link.l1 = "��� �����, ����� ���� ���� ��� �����������.";
			link.l1.go = "Torus_Mayak_6";
  		                   break;

                                                          case "Torus_Mayak_6":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_06.wav");
			dialog.text = "��� �����, � ���� �� ���� ����� ����� ����� � ����� ���������, � �� ����� �� ��� �� ������ ��������� ����!";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_7";
  		                   break;

                                                         case "Torus_Mayak_7":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   AddDialogExitQuestFunction("MayakDieenemy_25");
  		                   break;

		
//---------------------------------------------���� ����� ������------------------------------------

                                                          case "SKIP_MayakDieenemy":
			dialog.text = "�� ��� ��� �������.";
			link.l1 = "����, ������� �� ��������� ���� �����?";
			link.l1.go = "SKIP_MayakDieenemy_1";
  		                   break;

                                                          case "SKIP_MayakDieenemy_1":
			dialog.text = "� �� ����� �������, �� ��������� � ������ - ��� ������, � � ���� �� ���� ��������� �� ������. ����� ������, ��� �� �������...";
			link.l1 = "�� ��� ���, ������ ��������?";
			link.l1.go = "SKIP_MayakDieenemy_2";
  		                   break;

                                                         case "SKIP_MayakDieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy":
			dialog.text = "� ����� �� ������� ������ �����, ��� ���������� ��� ���, ������ ��� ���� ����?";
			link.l1 = "���, ���� �� ����������!";
			link.l1.go = "SKIP_Mayak_Dieenemy_1";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_1":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_ADD_08_01.wav");
			dialog.text = "����, �������� ���� ������.";
			link.l1 = "";
			link.l1.go = "SKIP_Mayak_Dieenemy_2";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_2":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_GOHOME_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ��� ������ �� �����!";
			link.l1.go = "SKIP_Mayak_Dieenemy_3";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_3":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_GOHOME_08_01.wav");
			dialog.text = "��� �, �� ������� �����������, ����, ��� �� ������ ����� ���� � ������. ������ � ���� ����� ��������, �� ������ ������ � ��������.";
			link.l1 = "";
			link.l1.go = "SKIP_Mayak_Dieenemy_4";
  		                   break;

                                                         case "SKIP_Mayak_Dieenemy_4":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;

//---------------------------------------------���� ����� ������------------------------------------

                                                          case "FISK_MayakDieenemy":
			dialog.text = "�� ��� ��� �������.";
			link.l1 = "����� ���������, ������ ������ �� ��������?";
			link.l1.go = "FISK_MayakDieenemy_1";
  		                   break;

                                                          case "FISK_MayakDieenemy_1":
			dialog.text = "���, ������ ����� ������ ������, ������ � ���������.";
			link.l1 = "���������?";
			link.l1.go = "FISK_MayakDieenemy_2";
  		                   break;

                                                         case "FISK_MayakDieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "FISK_Mayak_Dieenemy":
			dialog.text = "";
			link.l1 = "������� ���� �����, ������ ����� �� �� �����...";
			link.l1.go = "FISK_Mayak_Dieenemy_1";
  		                   break;

                                                          case "FISK_Mayak_Dieenemy_1":
 	                                       PlaySound("VOICE\Russian\gotica\FISK\DIA_ADDON_FISK_ABOUTJUAN_12_03.wav");
			dialog.text = "�� ������� ��� ����� � �����?";
			link.l1 = "���������, � ��� �� ���������� ����� ������ � �������, � �� ������ ������������ �����.";
			link.l1.go = "FISK_Mayak_Dieenemy_2";
  		                   break;

                                                          case "FISK_Mayak_Dieenemy_2":
 	                                       PlaySound("VOICE\Russian\gotica\FISK\DIA_ADDON_FISK_SIEG_12_03.wav");
			dialog.text = "� ����, ����� ������������ ����, �� ������ ��� ���� ������? �� �������� � �������� ������, ����� ���� ��������.";
			link.l1 = "";
			link.l1.go = "FISK_Mayak_Dieenemy_3";
  		                   break;

                                                         case "FISK_Mayak_Dieenemy_3":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;


//************������ � ������ ���� ****************************************

//************************ ������� ****************************************

		case "Augusta":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUDISTURBEDMYSLUMBER.wav");
            	                  dialog.text = "� ��� ����?";
        	                  link.l1 = "";
        	                  link.l1.go = "Augusta_1";
		break;

		case "Augusta_1":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_WHATDIDYOUDOINTHERE.wav");
            	                  dialog.text = "��� ���� ����� ���� - �?";
        	                  link.l1 = "";
        	                  link.l1.go = "Augusta_2";
		break;

		case "Augusta_2":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\HALLO_KILL.wav");
             	                   dialog.text = "";
        	                   link.l1 = "� ����� ����� ����?";
        	                   link.l1.go = "Augusta_3";
		break;

		case "Augusta_3":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_HELP.wav");
             	                   dialog.text = "��������...";
        	                   link.l1 = "";
        	                   link.l1.go = "Augusta_4";
		break;

		case "Augusta_4":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_KILLMURDERER.wav");
             	                   dialog.text = "���� ������.";
        	                   link.l1 = "";
        	                   link.l1.go = "Augusta Fight";
		break;

 		case "Augusta Fight":
                                      NextDiag.CurrentNode = "Fist time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_TavernAugusta");
		break;


//************������ (2��) �� ����� �������-��-��� ****************************************

		case "Pirat":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_06_00.wav");
            	                   dialog.text = "�� �� ������, ���� ����� "+ GetFullName(Pchar)+"?";
        	                   link.l1 = "";
        	                   link.l1.go = "Pirat 1";
		break;

		case "Pirat 1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_7.wav");
            	                   dialog.text = "";
        	                   link.l1 = "��, �, ���...";
        	                   link.l1.go = "Pirat Fight";
		break;

 		case "Pirat Fight":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1014_BANDIT_KILLER_06_00.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_piratFight");
		break;


// ********************* ������ (�� ���������) ******************************

		case "Sailor_coast":
                                      PlaySound("VOICE\Russian\GOTHIC\SAILOR\SAILOR_30.wav");
			dialog.text = "���! ����� ����, �� ����!  �� � �������� ��������� ��� �������, �� �� ����� ����� ������.\n� ��� ���, ��� ����� ��� �������, �� � ������� ����� ���� ������ ��� �... ��... �������� �����! ��������� �� ����, �, ���?";
			link.l1 = "���� ������! � ���� ��� ���� ������ ������! �� ��� � ����� ������?";
			link.l1.go = "Sailor_coast_1";
		break;

		case "Sailor_coast_1":
			dialog.text = "�� � �������, ���! �� ��������. ��, �� ���� �� ������. ������ ������, ����� � ���, ���. ������ ����� �������� � �������, ��...\n�� ��� ��������� ��� ����, �������, ��� ��� ��� ���� ��������� ���, �� ���������� ����� ����� � ����������! � ��� ������, ���!\n� �� ���������� �������� ���� ������� � ����� ���� �� ����� ��������.\n�� �� �������� �� � ����� ������ � ��������� ���� ����� � �������, � ������ - � ����� �� ���� ������. � ��� � ����� ���, ���! ����� ���� ��� �� ����!!!";
			link.l1 = "��� �, � ����� ������ �� ����������� ������. � ������� ����� ��������.";
			link.l1.go = "Sailor_coast_Exit";
		break;

		case "Sailor_coast_Exit":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_29.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_SmithySeaShore");
		break;
	// ********************* ���� ���� ������ ******************************

	case "Smithy_KarSec": 
                   PlaySound("VOICE\Russian\HeadPirate02.wav");
            	dialog.text = "�� �� ������ �������, �������?";
        	link.l1 = "...";
        	link.l1.go = "Smithy_KarSec_1";
		break;

	case "Smithy_KarSec_1": 
	PlaySound("VOICE\Russian\GOTHIC\GG\AUFSMAUL.wav");
            	dialog.text = "...";
        	link.l1 = "������, � ��� � ���� ���� �������, ���� ��� �������.";
        	link.l1.go = "Smithy_KarSec_2";
	break;

 	case "Smithy_KarSec_2":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_July_1");
	break;

	case "Smithy_KarSec_3": 
                    PlaySound("VOICE\Russian\HeadPirate01.wav");
            	dialog.text = "������� ��� ��� � ����� �����������, ���� ����...";
        	link.l1 = "...";
        	link.l1.go = "Smithy_KarSec_4";
	break;

	case "Smithy_KarSec_4": 
            	dialog.text = "��, ������, � ���� ����� �������� � � ��� � ���� ���������� ������ ������ ����. ������� ������ �� ������ �� ������?";
        	link.l1 = "��, ��� �� � ��� ����, ������ ����� ���.";
        	link.l1.go = "Smithy_KarSec_5";
	break;

 	case "Smithy_KarSec_5":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_KarSecExit");
	break;
// ********************* ������ ���� ******************************

	case "Smithy_July": 
                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUDISTURBEDMYSLUMBER.wav");
            	dialog.text = "� ��� ����?";
        	link.l1 = "...";
        	link.l1.go = "July_1";
		break;

	case "July_1": 
                    PlaySound("VOICE\Russian\GOTHIC\CRIME_W\CRIME_W_6.wav");
            	dialog.text = "��� ���� ����� ���� - �...";
        	link.l1 = "...";
        	link.l1.go = "July_2";
		break;

	case "July_2": 
                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_25.wav");
            	dialog.text = "...";
        	link.l1 = "����������, � ������ ���� ���������� � ����� ���������. � ���� ���� �������.";
        	link.l1.go = "July_3";
		break;

	case "July_3":
            	dialog.text = "��� � ����? �, ��� � ���� ������?";
        	link.l1 = "�� ����� ������ ���������.";
        	link.l1.go = "July_4";
		break;

	case "July_4":
            	dialog.text = "�� ���� ��� ��������. �� � ���� �� ����, ����� ��������� �������� ����, ������� ����� �������� ��� ���.";
        	link.l1 = "...";
        	link.l1.go = "July_5";
		break;

	case "July_5":
                    PlaySound("VOICE\Russian\GOTHIC\GG\MOMENT.wav");
            	dialog.text = "...";
        	link.l1 = "������� ����������.";
        	link.l1.go = "July_Exit";
		break;

 	case "July_Exit":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_10");
		break;

	case "July_6":
            	dialog.text = "����, �� ������ ����� ��������?";
        	link.l1 = "...";
        	link.l1.go = "July_6_Exit";
		break;

 	case "July_6_Exit":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_KarSec_3");
		break;


	case "July_7":
                   PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_17.wav");
            	dialog.text = "��� ���, ����� ����������. � �� ������� �� ���� ������� ���� �� ������ ������ ����� �����. ���� ����� ������ ������, ���� �� ����� ���� � ����, �� ��� �������... ������� ������� �������\n������ ����� ���� ������ ������. �����������, � ���������� �������� �� ���� �������?";
        	link.l1 = "������, ��� ���������� �����, ��� ��� ����� ����, �� ��������������� � ����������� ������. ��� ���� ��������� ��� �������������� ������ �, � ����� ������, �� ����� ������� ������������ ����. � ������" + GetSexPhrase("","�") + " ��� �����������, ��� ��� ������� �������� �� ������ ����. �������, �� ���� ���������.";
        	link.l1.go = "July_8";
		break;

	case "July_8":
            	dialog.text = "� ������� ���. � ������� �� ����. ���� ���-�� � ������� �� ���� ���� �������, ��� ��� �.";
        	link.l1 = "��������? ��? � ��-�� ����� ������?";
        	link.l1.go = "July_9";
		break;

		case "July_9":
            	dialog.text = "�� � ��� �� �� ������. ���� �����, ����� � ������� � ������ � ��������� ��� � �����������. ���� ������, ����� � ������� �� ���� � ����� ����� ����������� �����\n� ��� ��������� ������ �����������. � ��� ���, ���� �����, ��������� ��-�� ����. � � ���������� � ��������� �� �����, � �� �� ��� �� �������� ������ �� ���������� - � ������� �� ����� ������� ����������� � ��������� ����� �����, ����, ��������, ��� � ��, ������ ���� �������� �� ���\n� ����� ��������, � ����� �� ����� ����������, � ����, ��� � ��� ����, �������� ���������������, �� ��� �� ������� �� ����� ��������� - ����. ������ �� ��� ��... ���� �� �� ����� ���. ��� ���� ������������ ��� � ����� ������� �����. �����������, ������������, �������� �������\n���� ������� � ���� ���� � ��� �������, ��� � �� ������ ��������� ������� ������� � � ������ �����... �����, �� ���������� �� ����\n�� ��� ����� �������, �� ������ � ��� ���� ���-�� ��������. � ����� �������. ��� �� ������ ��� ��������. �� �������� ���, � � ���?";
        	link.l1 = "�� �� ������ �� � ��� ������ ����. ���� �������� �� �����, � �� ������ ��, ��� �����, ����� ������ ��. ������� � ����� � ���� ������ ���, �� ��� ����� ����� ��� ��� ����� ����?";
        	link.l1.go = "July_10";
		break;

		case "July_10":
            	dialog.text = "� ��� �������. �� ����������� �������, ����-���� � ����� ������. ���-�� ����� �����. � �� ����, ��� ��� ��� ���������� ������, �� � �������, ��� ������ ��� �� ��������\n��� ��������� ���� ����� � ��� ��������� �������. ������ ����� ���������� �� ������� � ���������� ������� ����� �������� � ����������. �� � ���� ������ ����������� ���� � �������� �� ��������� �������! �� ������ ���������� ��!";
        	link.l1 = "��... ��� �� ����������� ���������� ��? �� ���� ���� �������, ��� ��� ��������� �������, � � �� �������������, ��� ����, ���� � �����, � ������ ������ ����� - ��������� �����. � ��� �� ������ ��������� � ��� ������?";
        	link.l1.go = "July_11";
		break;

		case "July_11":
            	dialog.text = "� �� ����! ������� ��� � ����� ���� ������! �� ������� ���� � ������ ���� �����, �� " + GetSexPhrase("�������","�������") + ", �� ������� �� �������, �� ��� �������� ������ �������� ��������\n� �� ����! �� �� ������� ��� �������! ���� �� �������� ���, � �������, ��� ������ �������� ������� ����� ������������ ���! � ����� ����������� ��� �������!";
        	link.l1 = "��� �... � �� ������.";
        	link.l1.go = "July_12";
		break;

		case "July_12":
            	dialog.text = "��� ���������� ����� ������� � ����� ��� ��������� ���� � ����, ��� ���������� ����������� � � ��������� �� ���� �� ��� �������?";
        	link.l1 = "��� �� ������������?";
        	link.l1.go = "July_13";
		break;

		case "July_13":
                   PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_4.wav");
            	dialog.text = "����� �������! ������ �� ����-����!";
        	link.l1 = "����� ����� �� ����, ������� ����!";
        	link.l1.go = "July_14_Exit";
		break;

 	case "July_14_Exit":
                     AddQuestRecord("Gothic_Smithy", "15");
                     NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_12");
		break;

		case "July_15":
            	dialog.text = "� ������!";
        	link.l1 = "�� ����� � ����, ������� ����!";
        	link.l1.go = "July_15_Exit";
	break;

 	case "July_15_Exit":
                     NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_15");
	break;

	case "23 At Cayman":
            	dialog.text = "����! ����! �����������! �� ����� �� ���� �������! ������� ������ ���������, � ��� ����� ��������� ���� ������?";
        	link.l1 = "������ �����. ��� ����� ����� ������ �����������. ���� �������� �������.";
        	link.l1.go = "23 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "26";
	break;

 	case "23 Exit":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	sld=characterFromID("SmithyDavid");
	LAi_SetActorType(sld);
	Lai_ActorDialogNow(sld, Pchar, "",-1);
	break;

	case "27":
                    PlaySound("People Fight\Afraid_death_woman_03.wav");
            	dialog.text = "�������... �-�-�...";
        	link.l1 = "�, ����! ������!";
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

//**************** �������� �3 - �������� ���� *****************
	case "26":
            	dialog.text = "��, �� ��������! ��� �� ��������! �����������, ������� ��������! ���, �� ��� � ���� �� �����! ���������, ������!";
        	link.l1 = "���?! �� �� ������! ��! ��! ����! �������! ׸��! �� ��, ��������...";
        	link.l1.go = "26 End Quest";
		break;

 	case "26 End Quest":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	AddDialogExitQuestFunction("GothicSmithy_KillSmithyJuly");
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
	AddDialogExitQuestFunction("GothicSmithy_KillCarrol");
	break;

	case "24_0":
            	dialog.text = "";
        	link.l1 = "������...";
        	link.l1.go = "25_0";
	break;

	case "25_0":
            	dialog.text = "�... � ������� �� ��� �����, �������. � ��� �����������. ����� ���� ��������...";
        	link.l1 = "";
        	link.l1.go = "25_0 End Quest";
	break;

 	case "25_0 End Quest":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	AddDialogExitQuestFunction("GothicSmithy_KillSmithyDavid");
	break;


		// �������� ������������ �� ��������
		case "seashore_officer":
			dialog.text = "���� ����� ����������, �������!";
			link.l1 = "����������� � ����� �������� � ������� ��������� ����������. � ������ ��������� - ��������.";
			link.l1.go = "seashore_officer_1";
		break;

		case "seashore_officer_0":
			dialog.text = "���� ����� ����������, �������!";
			link.l1 = "����������� � ����� �������� � ������� ��������� ����������. � ������ ��������� - ��������.";
			link.l1.go = "seashore_officer_1";
		break;
				
		case "seashore_officer_1":
			dialog.text = "����, �������!";
			link.l1 = "������. ������!";
			link.l1.go = "seashore_officer_2";
		break;
		
		case "seashore_officer_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			locations[FindLocation("Beliz_jungle_02")].DisableEncounters = true; //��������� �������

			for(i=2; i<=4; i++)
			{
				locations[FindLocation("Beliz_Jungle_0"+i)].DisableEncounters = true; //��������� �������
			}
			LocatorReloadEnterDisable("Shore9", "boat", true);
			for(i=1; i<=iTotalTemp; i++)
			{
				sld = characterFromID("Temple_Oursoldier_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", -1);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			// �� ������� ����� ���������
			pchar.quest.Temple_seashore_officer.win_condition.l1 = "location";
			pchar.quest.Temple_seashore_officer.win_condition.l1.location = "Tenotchitlan_Jungle_02";
			pchar.quest.Temple_seashore_officer.function = "Temple_officerGoJungle";

		break;

//---------------------------------------------����� �������------------------------------------

		// ����� �������
		case "Billy":
			PlaySound("VOICE\Russian\citizen\Moryaki v Gorode-10.wav");
                                                      dialog.text = "������� ���� �����, ���� �� '������� ����' ����� ��������� �� ��������� ���... � ���� �� ������ - �����! ����� ��?";
			link.l1 = "�����������! ��� ����� � �����?";
			link.l1.go = "Billy_1";
		break;

		case "Billy_1":
                                                      dialog.text = "��� ��������� �� ��� ���?";
			link.l1 = "������ � ���� - ����� ����� ����?";
			link.l1.go = "Billy_2";
		break;

		case "Billy_2":
                                                      dialog.text = "��� �� �������, ����� ���� ��� �������?";
			link.l1 = "��, ��������� � ����� ��������? �� ���� ���� ��� �������, � ���� ���� ��� ��� ������, � ���, ��� ���� ��������, ����� � ����� - ������ ����� �� ����� ������� �� �������.";
			link.l1.go = "Billy_3";
		break;

		case "Billy_3":
                                                      dialog.text = "�����, � �� ���� � ��� ������� � ����� �������-��� ���� ������ �����.";
			link.l1 = "��� �� �������? ������� �����������?";
			link.l1.go = "Billy_4";
		break;

		case "Billy_4":
                                                      dialog.text = "�� ���� �����, ����� ���� ������... ���� ������ '������', ������ ������� ������� '������� ������'. ����� ��� ������ �� �������, �� ����� ������� �������� ������� '���������' � �������� ��� �����... �����, ��������. � ����� ��������, ������� ����� ��� ��� ������, ��� ���� ��������...";
			link.l1 = "������� �� ������� ��������? � �� �� ����� �� �������� ������� ����?";
			link.l1.go = "Billy_5";
		break;

		case "Billy_5":
                                                      dialog.text = "������ ��������� ��� ����?";
			link.l1 = "��, ���, ����� ������� �������?";
			link.l1.go = "exit";
		                 AddDialogExitQuestFunction("Gothic_RevengeCorsair_5");
		break;

//************������ (2��) � ���� ���� ����� ****************************************

		case "RevengeCorsair_Pirat":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_06_00.wav");
            	                   dialog.text = "�� �� ������, ���� ����� "+ GetFullName(Pchar)+"?";
        	                   link.l1 = "";
        	                   link.l1.go = "RevengeCorsair_Pirat_1";
		break;

		case "RevengeCorsair_Pirat_1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_7.wav");
            	                   dialog.text = "";
        	                   link.l1 = "��, �, ���...";
        	                   link.l1.go = "RevengeCorsair_Pirat_Fight";
		break;

 		case "RevengeCorsair_Pirat_Fight":
 	                  PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1014_BANDIT_KILLER_06_00.wav");
                                    NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_8");
		break;


//************������� ������� �� ���� ****************************************

		case "Terrax_abordage":
                        dialog.text = "������, �����, ������ ������� ������ �� ���������� �� �������� �������.";
			link.l1 = "��� ���������, ��� ��?";
			link.l1.go = "Terrax_abordage_2";
		break;

		case "Terrax_abordage_2":
                        dialog.text = "...";
			link.l1 = "������, ��� � ���� ��� ������ � ����� � ����� �� ���. ������...� �� ����, ��� ��������� �� ������, ��� ������?";
			link.l1.go = "Terrax_abordage_3";
		break;

		case "Terrax_abordage_3":
                        dialog.text = "�����, ���� �����, �����, ������ � ����� �� ����� ������� - �����, �� ������ ��� - �� �� ������...";
			link.l1 = "�����������, ��� ��������� � ����-�������?";
			link.l1.go = "Terrax_abordage_4";
		break;

		case "Terrax_abordage_4":
                        dialog.text = "� ����-������� �� ������ ������ � ����� �� ����, � ����� ����������� � ���� ���� ������ � ����� �����������, ����� ����� - ��������� ����� ��� ����������.";
			link.l1 = "��� ��� ��������, ������?";
			link.l1.go = "Terrax_abordage_5";
		break;

		case "Terrax_abordage_5":
                        dialog.text = "���� �������, ������ ������ � ��� ������� �������� ������� ���������, �� �� ��� ��� ������� ������� ����� ������.";
			link.l1 = "� ����� ������� �����������?";
			link.l1.go = "Terrax_abordage_6";
		break;

		case "Terrax_abordage_6":
                        dialog.text = "������ �������� ���� ����� �� �����, � � ������ ������������, ������ �������� ������� �����. ��� ��������� ��� ��� ����� ����������. �� ������ ������ ���������� �� ������������ ���� ����������� ������ ������� ���, �� �� ���������� ����. ��� � ������ ������ ������������ � ��������, � ������������ �� ���� ������, ������ �������� �� �����, ��� ��� � ���������. �� ������ ��� ����������� ����� �������, ����� ���� ������� ����� ������� �������� �� ������ �� ��� ��� ���� �� ������� �����.";
			link.l1 = "�������, �� ����� ��� �����?";
			link.l1.go = "Terrax_abordage_7";
		break;

		case "Terrax_abordage_7":
                        dialog.text = "�� �����, ��� � ����. ������ ������� �������, ������ ������, � ���������� ������ ���� ���������� ������ �� ���. ��� ����� ����, �����.";
			link.l1 = "���� ����� ������ �� �������?";
			link.l1.go = "Terrax_abordage_8";
		break;

		case "Terrax_abordage_8":
                        dialog.text = "������ ����������� ������, � ������ ����� ��� ��� ���� �������, ��� � �������� ��� ��� ������. �� �������, ������ �� ���� ����� ���������� ��������, ��� ������ ������ �����. �� �� ��, �� �����, ��� �� ���� �� ����� ����. ��� ������ ����� ������� ������ ������ ������� �� ����� �������, ������ �� �������.";
			link.l1 = "�����, ������, �������� - ��� ����...";
			link.l1.go = "Terrax_abordage_9";
		break;

		case "Terrax_abordage_9":
			DialogExit();
			sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
			Lai_SetPlayerType(pchar);
			LAi_RemoveCheckMinHP(sld);
			LAi_SetImmortal(sld, true);
			sld.ShipEnemyDisable  = true;
			pchar.quest.RevengeCorsair_AfterBattle.over = "yes";
			pchar.questTemp.RevengeCorsair.Self = "GothicRevengeCorsair";
			DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
		break;

//************������ (3��) � ���� �������-����� ****************************************

		case "RevengeCorsair_Pirat2":
 	        PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_1013_BANDIT_AMBUSH_01_01.wav");
            	                   dialog.text = "�� ����� ���������� ��� � ��� �����?";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_1";
		break;

		case "RevengeCorsair_Pirat2_1":
 	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10015_EMILIO_SENYAN_15_03.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "� ���, ����� �� ��������. ����� ������?";
        	                   link.l1.go = "RevengeCorsair_Pirat2_2";
		break;

		case "RevengeCorsair_Pirat2_2":
 	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10018_TORWACHE_EXIT_04_02.wav");
            	                   dialog.text = "������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_3";
		break;

		case "RevengeCorsair_Pirat2_3":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\AUFSMAUL.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "������, � ��� ��� � ���� ����� �������, ���� ��� �������!";
        	                   link.l1.go = "RevengeCorsair_Pirat2_4";
		break;

		case "RevengeCorsair_Pirat2_4":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10018_TORWACHE_SECONDWARN_04_00.wav");
            	                   dialog.text = "��������� ��� ��� ���� ������ ���������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_5";
		break;

		case "RevengeCorsair_Pirat2_5":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_NEVER_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "����� � ���� ������.";
        	                   link.l1.go = "RevengeCorsair_Pirat2_6";
		break;

		case "RevengeCorsair_Pirat2_6":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_NOWEAPON_06_01.wav");
            	                   dialog.text = "�����, �� ������� ��� �� �������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_7";
		break;

		case "RevengeCorsair_Pirat2_7":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\PRICEOFHELP.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "�� �� �������!";
        	                   link.l1.go = "RevengeCorsair_Pirat2_Fight";
		break;

 		case "RevengeCorsair_Pirat2_Fight":
                                          NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_15");
		break;

		// ���� ������
		case "Terrax_1":
                        dialog.text = "���� �� ������ ���� �����, ������ ��� ������.";
			link.l1 = "....";
			link.l1.go = "Terrax_2_1";
		break;

		case "Terrax_2_1":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1031_FLUECHTLING_TIP1_FREI_15_00.wav");
                                                              dialog.text = "...";
			link.l1 = "� �� ��������� ������� ����, ��� � ������ ����� - ������. ������ ����� ���������, � ������ � ���� �� ����, ��� � ���� ���� �����?";
			link.l1.go = "Terrax_2";
		break;

		case "Terrax_2":
                       dialog.text = "� ���� ���� � ��� ����� ������� ��������� ������, ���������� �������� � �������. � ������� ������, � ��� ��� ������ ������ ����, ��� �� ��� �������, � ����� ���� ���� �������, � ����, ��� �� �� ��� ����� �������� �� ��� � �������, ����� � �����, �� ������ �������, �� ���� ������.";
			link.l1 = "���������, ������, � ���� ��� ������� ���� �������. ��� �� ���� ��, ��� ��������� �� ������, � ���� �� ���� ������.";
			link.l1.go = "Terrax_3";
		break;

		case "Terrax_3":
                        dialog.text = "����� ������ ����! ���� ���� ������� � ��������! ��, ������, ��������! ���� ��, �������, ��� � �� ����� ��������� ���� �� ����� � �������� ������ ��� ����, ����� � �������� ���� ��� �����. �������� �� ����, � � ����� �� ����� � ������� ������, �� ��� � ������ �������� �������. ������, � ��� �� ��� ��������� �� ���� ����� ������ � ����� �� ����?";
			link.l1 = "�� ������� �� ����? ����������, ������, � �� ���� ����� ���� ���� ����� ����� ���� ��� �� ��������� ����.";
			link.l1.go = "Terrax_4";
		break;

		case "Terrax_4":
                        dialog.text = "������ ������, � ������ ����� �� �������, ����� ���...";
			link.l1 = "� �������� ����� ���, ���� �� ��� �������� �� ��� ������.";
			link.l1.go = "Terrax_5";
		break;

		case "Terrax_5":
                        dialog.text = "�������!";
			link.l1 = "������� �� �������� ���� �� ������� � �������?";
			link.l1.go = "Terrax_6";
		break;

		case "Terrax_6":
                        dialog.text = "��, �����, ����� ������ �� ���������, ����� ��� ����� ��� ���� � ������. � ���?";
			link.l1 = "��� ���� �������, �� ������ ��� ���� �� � ��� ���������, ������ �����, ������ �������. ���� ��� �������� � ���� ����, � ��������� ���� �� �����. ��� ��� ����� ���� ������������ ���� ����? ������ �� ��� ��� ���-�� �� ����� �����...";
			link.l1.go = "Terrax_7";
		break;

		case "Terrax_7":
                        dialog.text = "����� ���� �� ���� ��� ����� ������ �������� ������, ��� � ��������� �������!";
			link.l1 = "�������� ������, ���������...";
			link.l1.go = "Terrax_8";
		break;

		case "Terrax_8":
                        dialog.text = "� ���� �� �������, ��� ��������� � ���� � ������� ��� ��������?";
			link.l1 = "������, ��� ������, � � �����, ������� ����� ����������.";
			link.l1.go = "Terrax_9";
		break;

		case "Terrax_9":
                        dialog.text = "� ������ �� �������, ������ ���� � ����� �� ����, ��� ����� �� ����� ������, ���� � ���� ����� ������ ������, ���� ���������� �� �� ��������� - �� ���. ������ �� ����� ������� ���-�� �� ��� ������ ��� ����� �� ���� � ��� ���� �� ������ ���� ������ ����� ����� ������. ���� �� �� ����� ���?";
			link.l1 = "��� �� ����� �, ���� �� ��... �����.";
			link.l1.go = "Terrax_10";
		break;

		case "Terrax_10":
                        dialog.text = "�� ������� �������� ������?";
			link.l1 = "����� ���� � ��, � ����� � ���. ���� ��� ����� - ��� �������� �������� ��������, ������ �� �������?";
			link.l1.go = "Terrax_11";
		break;

		case "Terrax_11":
                        dialog.text = "�����... � ������ ��� ����� �� ����� � �������. �� �� ���� �� �������?";
			link.l1 = "��� ������ - �� �������, �������, ������� �� ����, ��� �� �� �� ��� �����, ������, ������, �� ���� ��� ���� �����, ��� ���� ���������� ���������. � ����� ����� ����� ��������� ��������. ������, ��������, ��� ������ ������ ���������� � ��� ����� ����� ��� �������. �������� �� �������, ������� ���� ������ ������� ���� �����.";
			link.l1.go = "Terrax_12";
		break;

		case "Terrax_12":
                        dialog.text = "�������� �� � ����. ��� ������ �����?";
			link.l1 = "����� ������ ���� � ����� ������ ��� ���������� ���������������. �������� � ������� �� ���� � ���� � ���� ���� ��� ������ ����������� ��� ����� �� ����� �������. ������ ��� ������, ��� �������� ������ ����� ����� ����� � ��������� ����. ��������, ��� ����� ���� �, �����, ���������� ���������� �������� ������ � ��� ������ ���� �� �� ��������� � ����� ��������.";
			link.l1.go = "Terrax_13";
		break;

		case "Terrax_13":
                        dialog.text = "������, �������� ���. ��� �� ����� ���������� ��������� ������� ������ ������� � ��� �������!";
			link.l1 = "��� � ������������.";
			link.l1.go = "Terrax_14";
		break;

		case "Terrax_14":
 		DialogExit();
                NextDiag.CurrentNode = "First time";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_16");
		break;


		// ��� ������
		case "Zorro_1":
                        dialog.text = "...";
			link.l1 = "�� ��� �� � �����������.";
			link.l1.go = "Zorro_2";
		break;

		case "Zorro_2":
                        dialog.text = "...";
			link.l1 = "�������� - ������������ ���������!";
			link.l1.go = "Zorro_3";
		break;

		case "Zorro_3":
                        dialog.text = "...";
			link.l1 = "���, ��� �� ��� ���? � ����� ��� �� ����� ����, �� ������� ������ - ������� ������ ��������� ��� ������ �������� �������?";
			link.l1.go = "Zorro_4";
		break;

		case "Zorro_4":
                        dialog.text = "� ���� ���������.";
			link.l1 = "���, ������ ��������, � ������ ���� ���� �� ��������.";
			link.l1.go = "Zorro_5";
			link.l2 = "�� �����. �� �� ������ �� ���� ������ - ��� ����������... � ����� ����  ����� ����, �� ������� ������ - ������� ������ ��������� - �� ��� ��? �� ���������� �����, �� ������ �������. ������ �������� - ������� ����� ��� ����, ��� �� ��� ��� ��������. ����� �����, ��� ������...";
			link.l2.go = "Zorro_6";
		break;

		case "Zorro_5":
                        dialog.text = "���� �� �������, �� ��� �������� � �������. �������� ����� �� ����� ���, ��� ���������� �������, � ��� ������ ���� � ��!";
			link.l1 = "��� � ��� ������.";
			link.l1.go = "exit";
		        AddDialogExitQuestFunction("Gothic_RevengeCorsair_25");
		break;

		case "Zorro_6":
                                          NextDiag.CurrentNode = "First time_Zorro";
		DialogExit();
		 AddDialogExitQuestFunction("Gothic_RevengeCorsair_26");
		break;

		case "First time_Zorro":
			dialog.text = "���� �� �������, �� ��� �������� � �������. �������� ����� �� ����� ���, ��� ���������� �������, � ��� ������ ���� � ��!";
			link.l1 = "����� �����, ��� ������...";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time_Zorro";
		break;





//************��������� ****************************************

		case "BillMatthew":		// ����
                                    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOODMONSTERKILL.wav");
			dialog.text = "�������, ��� ������� ���, ��� ��� ��� �� ����� ���� � ������� ������.";
			link.l1 = "����� �������� ������?";
			link.l1.go = "BillMatthew_1";		
		break;
		
		case "BillMatthew_1":
			dialog.text = "�������, ��� ����� ���������� ��� �������. � ��� ��������� � ������� ������� ������ �� ��������� ����� '��������� ������'.\n����� �������� ����� �� ��������� ������ ������� ������� ���������� �����������, ������� � ��������. ������� ���� ����� � ���, ����� ��� ������ ������� ���� ������� ������� �� �� ��������� �����. ������ ��������������, �� ����� ��������, � ������� ������ ������� � �����-�� ��������� � ��� ��������� ������� ������.\n������ ����� �� ��� ����� ����� �� �����. �� �������� ������, ���� �� ���� ����� ��������� ���, � �������� � ��������� ��������.";
			link.l1 = "��, � ��� �� ���� ������?";
			link.l1.go = "BillMatthew_2";		
		break;

		case "BillMatthew_2":
			dialog.text = "����� �����-�� ����� �������� ������ ������� ����� ��������, ������� ���� ��������� ������� �� ������ ��� ����� ��������.\n���������, ��� ���������� ����������� ��� ��������� �� ����� ���������� ������, �������� ����������, ���������� �� ������ � ������ ���� ����� � ��������� �� ��������.\n��� ������� ��� � ������, � ���������� ���� � ���� �������� ���� ���! ����� ����, ����� ������� ������������ ������ ��� ����� ��������, � ����� ����� �������� � ������� ���� ���������� �������� ��������� � ����� ��������!\n�������� ������� �� ���� �� ������������� ��� ����� - ������ � ������� - ��� ��������� ������ ������ ����! ����� �����-�� ����� ��� ������� ������, � ������ ��� ������������ - �� ����������� ����� ���� ����� ��������� �� �������� �����.\n���� ��� � ��� - ��� ������ ����� ����� � ��� ������� �������, ��� ������� �� ����������.";
			link.l1 = "�?..";
			link.l1.go = "BillMatthew_3";		
		break;

		case "BillMatthew_3":
			dialog.text = "��� �����-�� ����� ��� ���������� ��� ��� ������. ���� �� ����� ��������� ������� ��������� ������ ��� ������. �� ��������� ���� �� �� ����������� ������ �� �������, �� �������� ������ ��������.";
			link.l1 = "� ��� ���� �� ���� � ������� ��������!";
			link.l1.go = "BillMatthew_4";		
		break;

		case "BillMatthew_4":
			dialog.text = "��, ��� �� ����������?";
			link.l1 = "��� ������ ���������, ����� �������. ���������...";
			link.l1.go = "BillMatthew_5";		
		break;

		case "BillMatthew_5":
			dialog.text = "�� ����� ����, ��� ����, ������ � ��� ����� ������, �� ��� ��� ����������� ������, � �� ���� ������, ��� ����� ������ �������� ����� ��� � �����������? ������ �� �����, �� � ���� ������ � ����� � ������� � ����. ����� ��� �� �������, � � �������������� ������ �������� �������.";
			link.l1 = "��� � ������� ����������� ������ ������ ��� ��������������.";
			link.l1.go = "BillMatthew_6";		
		break;

		case "BillMatthew_6":
			dialog.text = "�� �����, ����� ʸ���, �� ����� � ���������� � ��� ������ ��� � ��� ������ ���������.";
			link.l1 = "� ���� ��� ��� - ������ ������ ���!";
			link.l1.go = "BillMatthew_7";		
		break;

		case "BillMatthew_7":
			dialog.text = "��, ���� ���� �� ����� �����������, ��� ������ ���� ��� ������ - ���� ��� ��� ����� ���� ��� ������ �� ���� ���������!";
			link.l1 = "������ �� � ��� ��� �������?";
			link.l1.go = "BillMatthew_8";		
		break;

		case "BillMatthew_8":
			TakeNItems(pchar, "Obsession_Coin", 1);
			Log_Info("�� �������� ��������� ������");
			PlaySound("interface\important_item.wav");
			dialog.text = "�� ��� ��! ���� �������� ������ ���������� ��� ��� ������� ������ �����! ������ ���, �������, ��������, ��� ������� �������� � ���� ����� � ������! ���� �� ����� ����� � ����� ��� ���� ������, ��� ����� ��������� ���.";
			link.l1 = "�� ��� �, ����� ���� ��� �������, � ���������� �����������,��� � ����.";
			link.l1.go = "exit";	
			AddDialogExitQuestFunction("GothicObsessionTakeCoin");
		break;

		case "ObsessionDevlin":		// ������
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_00.wav");
                                    dialog.text = "�� �����, ��� �� ������!";
	                  link.l1 = "������ ��� �� ����� �� �������, �� ������ ��������������.";
		link.l1.go = "ObsessionDevlin_1";
		break;

		case "ObsessionDevlin_1":
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_01.wav");
                                    dialog.text = "��� ������ ������� ������ � ������� ���� ��� � ����� �����! ��� ����� ��� �������������, ����� �� ������ ���� ������ ����� ���� �������� � ����� ��, ��� ����������� ���.";
	                  link.l1 = "�� �������� � ������!";
		link.l1.go = "ObsessionDevlin_2";
		AddDialogExitQuestFunction("GothicObsession_Devlin_2");
		break;

		case "ObsessionDevlin_2":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\GG_10.wav");
                                    dialog.text = "��.";
	                  link.l1 = "������ �� ����.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsession_Devlin_2");
		break;

		case "ObsessionDevlin_3":
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_02.wav");
                                    dialog.text = "�� ������� �����, �� ������� �� ������ ��, ��� �� ���������� � � ������ ���� �� ��� ����� � ������!";
	                  link.l1 = "...";
		link.l1.go = "ObsessionDevlin_4";
		break;

		case "ObsessionDevlin_4":
		RemoveItems(PChar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("�������� ������ ������");
  	                  PlaySound("VOICE\Russian\GOTHIC\GG\PRICEOFHELP.wav");
                                    dialog.text = "...";
	                  link.l1 = "�� �� �������!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsession_Devlin_5");
		break;


		case "Fiamatar_abordage":		// ������
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_15_00.wav");
                                    dialog.text = "...";
	                  link.l1 = "��� ��.";
		link.l1.go = "Fiamatar_abordage_2";
		break;

		case "Fiamatar_abordage_2":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_01.wav");
                                    dialog.text = "�� ��� �� ����� �������� ���� ������, ����� ������ ���� - ������, �� ������ ��� �.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_3";
		break;

		case "Fiamatar_abordage_3":
                                    dialog.text = "������ ����� � �������, �� ��� ��������, ���������� ��������. ����� ������� ����� � ���� ����� � ���� ������� � ���� �����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_4";
		break;

		case "Fiamatar_abordage_4":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_03.wav");
                                    dialog.text = "���� ���������� ��� ���� ������������ ����, ��� �� ��� �� �������� ����� ������ ���� ����� �����.";
	                  link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_5";
		break;

		case "Fiamatar_abordage_5":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_04.wav");
                                    dialog.text = "��� ������ - ����������� ����� ����.";
	                  link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_6";
		break;

		case "Fiamatar_abordage_6":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_06.wav");
                                    dialog.text = "��� �� ��� ���� ����, ����� ������ ����������� ��������� ������� �� ��������.";
	                  link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_7";
		break;

		case "Fiamatar_abordage_7":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_08.wav");
                                    dialog.text = "����� �� �� �������� ����� ������� ��������� ��� - �� �� ������ ��� �.";
	                  link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_8";
		break;

		case "Fiamatar_abordage_8":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_15_00.wav");
                                    dialog.text = "...";
		link.l1 = "��� ������� �� ����������, ��� ������ ��� ����!";
		link.l1.go = "Fiamatar_abordage_9";
		break;

		case "Fiamatar_abordage_9":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_01.wav");
                                   dialog.text = "���� ��������, ��������� ������������� �������� ��� ������ ����� ����, ����� ����� �� ������ �������������� ���.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_10";
		break;

		case "Fiamatar_abordage_10":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_02.wav");
                                    dialog.text = "��� ������� ���� ��� ����������� ���� �� ������� �������, ���� ���� ���������� � ������������ ��� ������� ���������.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_11";
		break;

		case "Fiamatar_abordage_11":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_03.wav");
                                    dialog.text = "�� �������� ��� - ����� � ����� ������� ���� �����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_12";
		break;

		case "Fiamatar_abordage_12":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_04.wav");
                                    dialog.text = "� ��� ���� �� �� ����� ��� ���������� ��� ������������� ����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_13";
		break;

		case "Fiamatar_abordage_13":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_05.wav");
                                    dialog.text = "������ ����� � �������� ���� ������������ ���� �� ����� � ���������� �� ��� �������������� ��������� ������ ����� ����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_14";
		break;

		case "Fiamatar_abordage_14":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_1_15_00.wav");
                                    dialog.text = "...";
		link.l1 = "����� ���, ��� ��������� ���� �������� �����, �� ������ ������ �� ��� ��� �� ����� ���� � ������!";
		link.l1.go = "Fiamatar_abordage_15";
		break;

		case "Fiamatar_abordage_15":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_1_20_01.wav");
                                    dialog.text = "���� ������ ���� � ���� ���� - ������ ����������� ��������� ������� �� ����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_16";
		break;

		case "Fiamatar_abordage_16":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_15_00.wav");
                                    dialog.text = "...";
		link.l1 = "������ �������, � ������ ���� ������� ��� ������ �� ��� �������� �� ����� - �������.";
		link.l1.go = "Fiamatar_abordage_17";
		break;

		case "Fiamatar_abordage_17":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_20_01.wav");
                                    dialog.text = "��-��, �� ��� �� ����� �������� ����, ����� - �� ��������� �������� ���� �� ���������� ���� ����.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_18";
		break;

		case "Fiamatar_abordage_18":
 	                 PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_20_02.wav");
                                   dialog.text = "���� ����� ������� ��� ��������� ����� ������ � ���� ���.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_19";
		break;

		case "Fiamatar_abordage_19":
		LAi_SetCurHPMax(NPChar);
		LAi_GetCharacterMaxEnergy(NPChar);			
		QuestAboardCabinDialogExitWithBattle("FiamatarToBoom"); 
		DialogExit();	
		AddDialogExitQuest("MainHeroFightModeOn");
		pchar.GenQuest.Detonation = true; // patch-4
		break;


		
		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
		
	}
}