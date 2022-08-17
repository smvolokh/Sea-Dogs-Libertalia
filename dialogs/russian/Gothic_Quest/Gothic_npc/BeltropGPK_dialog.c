// ��� ������ ��������
void ProcessDialogEvent()
{
	ref NPChar, sld, Ship;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "������, �������!";
			link.l1 = "������� �� �����, ���������.";
			link.l1.go = "Exit_1";
		break;

		case "Exit_1":
			dialog.text = "������ ����������!";
			link.l1 = "��, �� ����.";
			link.l1.go = "Exit";
		break;

		case "quest_other_life":
			dialog.text = "������� ����� � ��������, �������.";
			link.l1 = "�������, ���, �� ����� �����.";
			link.l1.go = "quest_other_life_exit";
		break;

        case "quest_other_life_exit":
			AddDialogExitQuest("quest_other_life_flashback_port5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode="First time";
                        DialogExit();
		break;

/// ******************** ����� �1 ****************************

	                                                case "quest_Start_Game":
			dialog.text = "�������, ������������, ��� ������?";
			link.l1 = "���, �� ��� ������� ��������� ���� �� ������� � �� ������ ������� ������� ����?";
			link.l1.go = "quest_Start_Game_1";
		                        break;

	                                                case "quest_Start_Game_1":
			dialog.text = "���� �������?";
			link.l1 = "� � ���� ������� ������� �����?";
			link.l1.go = "quest_Start_Game_1_Ext";
		                        break;
				
			case "quest_Start_Game_1_Ext":	
			AddDialogExitQuestFunction("Start_Game_Terks_1");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

	                                                case "quest_Start_Game_Sailor_2":
			dialog.text = "�������?";
			link.l1 = "� �� ��� ��������, �� ������?";
			link.l1.go = "quest_Start_Game_Sailor_3";
		                        break;
	                                                case "quest_Start_Game_Sailor_3":
			dialog.text = "�� � �����, ��� ������?";
			link.l1 = "";
			link.l1.go = "quest_Start_Game_Sailor_2_Ext";
		                        break;

			case "quest_Start_Game_Sailor_2_Ext":	
			AddDialogExitQuestFunction("Start_Game_Terks_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

/// ******************** ����� �2 ****************************

	                                                case "StartGameTerks7":
			dialog.text = "�������, ��� ��� ������� �����, �� ��������� ���� ������, � ��� ���?";
			link.l1 = "������� �����, �������� � ����. ��� ������� �� ����.";
			link.l1.go = "StartGameTerks8";
		                        break;

	                                                case "StartGameTerks8":
			dialog.text = "� �� ��� ���� �����, ���� ���� �����, ����� �������� ������ �� ���������, � ��� ������ ���� ��� �� ��������.";
			link.l1 = "������ �� �� ������ ��� �����������, ��� ���� �������.";
			link.l1.go = "StartGameTerks9";
		                        break;

	                                                case "StartGameTerks9":
			dialog.text = "�� �����, ���� �����?";
			link.l1 = "������, �� ������ ����, ���� ������ ��� � ���� ��� � ����, ��������� �� ���������.";
			link.l1.go = "Gothic_Start";
		                        break;


		case "Gothic_Start":
			dialog.text = "��� ������ � ����� �����?";
			link.l1 = "�����, ���������...";
			link.l1.go = "Gothic_Start_1";
		break;
		
		case "Gothic_Start_1":
			Log_Info("�� �������� �������� �������");
			dialog.text = "���...";
			link.l1 = "���-���... �������� ������, ������" + GetSexPhrase("��","��") + ". ���� �������� �� ��������� ���������. ������, � ������� ��. ����� �������������, ������ ������ ����.";
			link.l1.go = "Ext_1";		
		break;

		case "Ext_1":
			GiveItem2Character(pchar, ""); 
			AddDialogExitQuestFunction("Start_Game_Terks_7");				
			DialogExit();			
		break;

	                                                case "StartGameTerks10":	                                                
			dialog.text = "(�������) ������ ����������, �� ��� �������?";
			link.l1 = "���, �� �� ���������, ������ �� �� �� �������.";
			link.l1.go = "StartGameTerks11";
		                        break;

	                                                case "StartGameTerks11":
	                                                PlaySound("VOICE\Russian\gotica\DAR\DIA_DAR_PERM_03_01.wav");
			dialog.text = "(�������) ������ � �������� ������ ����������� �������� ���������� ������ ��� �������?";
			link.l1 = "��� �� �� ������ �����?";
			link.l1.go = "StartGameTerks12";
		                        break;

	                                                case "StartGameTerks12":
			dialog.text = "(�������) ����, ����, �������?";
			link.l1 = "��, � ���� ,��� -�� �����, ����� ��������, ���� �����.";
			link.l1.go = "StartGameTerks13Ext";
		                        break;

	                                                case "StartGameTerks13Ext":
	                                                PlaySound("VOICE\Russian\gotica\DAR\DIA_DAR_ORCRING_NECKEN_SCHLAGEN_03_01.wav");
			AddDialogExitQuestFunction("Vater_skel_Shore");				
			DialogExit();			
		                        break;

	                                                case "StartGameTerks14":
			dialog.text = "��� �� ���� �������� ����?";
			link.l1 = "��� ����?";
			link.l1.go = "StartGameTerks15";
		                        break;

	                                                case "StartGameTerks15":
			dialog.text = "���� ��������� �� ���� ���� ����� ��� ������?";
			link.l1 = "��, �����, ������ �� ������, ��� ���� � ����.";
			link.l1.go = "StartGameTerksExt";
		                        break;

	                                                case "StartGameTerksExt":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_1.wav");
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.QuestBeltropGPKTalk.win_condition.l1 = "location";
	                                                pchar.quest.QuestBeltropGPKTalk.win_condition.l1.location = "My_Cabin_Small";
			pchar.quest.QuestBeltropGPKTalk.function = "Quest_BeltropGPK_Talk";			
		                        break;

	                                                case "StartGameTerks16":
			dialog.text = "�������, ��, ��� �� ������� ������ ���������� �������� � ������� ������.";
			link.l1 = "������� ��� �� �����������, � ��� ������.";
			link.l1.go = "Ext2";
		                        break;

	                                                case "Ext2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();			
			LAi_SetActorType(npchar);			
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "My_Deck", "goto", "goto8", "OpenTheDoors", 1);
                                                                        DoQuestFunctionDelay("Start_Game_Terks_7_3", 3.0);
		                        break;

/// ******************** ����� �3 ****************************

		case "Caleuche_2":
			dialog.text = "������ ������� ��� ������ ��� � ������, �� ����� ������������ ������ � ������ �������� � ��� ��� �� ������� ��� ������� � ��������������, �������� ���!";
			link.l1 = "�� ����� ������� ��������, ������ ������� �� �������, �������� ����� �� �� �������� �� ������ �����?";
			link.l1.go = "Caleuche_3";
		break;

		case "Caleuche_3":
			dialog.text = "��, ����� ���� ������� ������ ���� ������ �������!";
			link.l1 = "����� � ����?";
			link.l1.go = "Caleuche_Ext";
		break;

		case "Caleuche_4":
			dialog.text = "������� � ��� ����������� �����!";
			link.l1 = "����. ����� ��� �� �������, � �� �������� �� ������� �����?";
			link.l1.go = "Caleuche_5";

		break;

		case "Caleuche_5":
			dialog.text = "������ ������� ��� �������, �������!";
			link.l1 = "�����, ����� � �������" + GetSexPhrase("","�") + "! � ����� ������ ��� �� �����.";
			link.l1.go = "Caleuche_6";
		break;

		case "Caleuche_6":
			dialog.text = "�������� �������!";
			link.l1 = "";
			link.l1.go = "Caleuche_FirstMate_Tuttuat_Ext";
			pchar.quest.CaleucheFirstMateTuttuat.win_condition.l1 = "location";
			pchar.quest.CaleucheFirstMateTuttuat.win_condition.l1.location = "Dominica";
			pchar.quest.CaleucheFirstMateTuttuat.function = "Caleuche_PrepareGhostship";
		break;
		
				
			case "Caleuche_Ext":
			DoQuestFunctionDelay("Caleuche_CreateGhostships", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

			case "Caleuche_FirstMate_Tuttuat_Ext":
			DoQuestFunctionDelay("Caleuche_FirstMateTuttuat", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

/// ******************** ����� �4  ****************************

		case "Start_GameMyCabin6":
			dialog.text = "" + PChar.name + ", ������... ����� ����������!";
			link.l1 = "���? ��� ���������? ��� ��? ���� ����������?";
			link.l1.go = "Start_GameMyCabin6_1";
		break;
		
		case "Start_GameMyCabin6_1":
			dialog.text = "�������, � ����� �� �������. ����� ������� �������!";
			link.l1 = "�������? ��� �� �������!";
			link.l1.go = "Start_GameMyCabin6_2";
		break;
		
		case "Start_GameMyCabin6_2":
			dialog.text = "�����, " + PChar.name + "! ������...";
			link.l1 = "";
			link.l1.go = "Start_GameMyCabin6_exit";
		break;

		case "Start_GameMyCabin6_exit":
			AddDialogExitQuest("Start_GameMyCabin5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Start_GameMyCabin6_Sound":
			dialog.text = "�������, �������?! ���� ������! ������ ����, ��� ���! �� ������ ������ ��!";
			link.l1 = "";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Start_GameMyCabin6_Sound";
		break;		

		
/// ******************** ����� �5  ****************************	
	case "quest_CaesarVictorious":
			dialog.text = "�������, �� �������� ��������� ����� �� ���������. �� �� �������� ���������� �����, ���������� ������� � ������.";
			link.l1 = "��� ��� �� �������?";
			link.l1.go = "quest_CaesarVictorious_1";
		break;
		case "quest_CaesarVictorious_1":
			dialog.text = "������ �� ��������� ����������, �������. ������ �������� �������������.";
			link.l1 = "������, ����� ���������... ������� �������, ����� �������� ��� ���� ������. ����������.";
			link.l1.go = "quest_CaesarVictorious_1_1";
		break;		
		case "quest_CaesarVictorious_1_1":
			dialog.text = "��� �����, �������! ��, �������, ������������� � ��� ��������...";
			link.l1 = "";
			link.l1.go = "quest_CaesarVictorious_1_1_Ext";
				NextDiag.TempNode = "quest_CaesarVictorious_2";
		break;				
			case "quest_CaesarVictorious_1_1_Ext":
				AddDialogExitQuest("quest_CaesarVictorious_3_CVdeck");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;	

	case "quest_CaesarVictorious_2":
			dialog.text = "�� �������� �� �����, �������. �� ������� �������� �����.";
			link.l1 = "�� ���� ���-�� ������� ��� �����, �����?";
			link.l1.go = "quest_CaesarVictorious_2_1";
		break;	
		case "quest_CaesarVictorious_2_1":
			dialog.text = "��, �������. ����� ����, ����� ������ ���� ����� �������� �����������. �� ������ �� ��, ����� ��� ����� �������� � ����� ��� ��� �������. � ���� �������� �� �������, ������ ��� ��� �� ������� ������ ����� �������� �����. ��������, �������, ��� ��� ����� ������� �������, ��... ������������.";
			link.l1 = "��� ��� �� ����������?";
			link.l1.go = "quest_CaesarVictorious_2_2";
		break;		
		case "quest_CaesarVictorious_2_2":
			dialog.text = "� ����� ���� ������ ����, ������� ����� ����������� � ��������� ��������� �����. � ����� ������� � ����� �������� ����� ������ ������ ������� ������.";
			link.l1 = "��� ���?.. � ��� � ����� ��������?";
			link.l1.go = "quest_CaesarVictorious_2_3";
		break;	
		case "quest_CaesarVictorious_2_3":
			dialog.text = "�� ������ ��������� ����, �������. ������, ��� ������� ������� ������, �� � ��������� ���� �� ����� ������. � �� ���� ������� ������, �������, ��� �� �������� ������� ��� �����.";
			link.l1 = "������, ������ �������. ����������� ������ �������.";
			link.l1.go = "quest_CaesarVictorious_2_3_Ext";
				NextDiag.TempNode = "quest_CaesarVictorious_3";
		break;		
			case "quest_CaesarVictorious_2_3_Ext":
				AddDialogExitQuest("quest_CaesarVictorious_3_CV_toCab");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;

	case "quest_CaesarVictorious_3":
			dialog.text = "�� ���, �������?";
			link.l1 = "�� ������. �� ����������� ����, ��� � ����, ���� �� ������ ��� ��������� ���� ���� � � ������.";
			link.l1.go = "quest_CaesarVictorious_3_1";
		break;	
		case "quest_CaesarVictorious_3_1":
			dialog.text = "������? ��� �� ����� ��� ����� ���� ����! ����� ���� �� ��������, �, �������? ����� ��� ������ �� ��� �� ����, � ���� �������� � ��������� ����� ���� ��-�� ���������, ����� ����� ������� ��� ����-������ ���.";
			link.l1 = "�����, �� ����. ��� ��� ����� �� ����. ������ �� ������.";
			link.l1.go = "quest_CaesarVictorious_3_2";
		break;	
		case "quest_CaesarVictorious_3_2":
			dialog.text = "��������� ����������� ��������, �������?";
			link.l1 = "�-�-�... ���. ׸�� � ���. � ����� ������� ������ ������. ����������� ���� ����� �� "+Pchar.Ship.Name+", ����� �������� ���� ��������.";
			link.l1.go = "quest_CaesarVictorious_3_3";
		break;	
		case "quest_CaesarVictorious_3_3":
			dialog.text = "��� �����, �������.";
			link.l1 = "";
			link.l1.go = "quest_CaesarVictorious_3_3_Ext";
		break;
			case "quest_CaesarVictorious_3_3_Ext":
	                                                                       
				AddDialogExitQuest("quest_CaesarVictorious_4");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;		

/// ******************** ����� �6  ****************************	
	case "quest_UnarmAndDanger":
			dialog.text = "�������! ��� ����� �� �����!";
			link.l1 = "��, � ���� ��� ����... ��� ��� �����?";
			link.l1.go = "quest_UnarmAndDanger_1";
		break;
		case "quest_UnarmAndDanger_1":
			dialog.text = "������ ��������� ��� �������... ������ �����!";
			link.l1 = "��� �� �����������?!..";
			link.l1.go = "quest_UnarmAndDanger_1_Ext";
		break;
			case "quest_UnarmAndDanger_1_Ext":
				AddDialogExitQuest("quest_UnarmAndDanger_9_SJ_Street");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;	

	case "quest_UnarmAndDanger_Mass7":
			dialog.text = "����, ����� ���� ��������� �����!..";
			link.l1 = "������� ����... ��� ������... ������ ��, � ����������! �� ����!";
			link.l1.go = "quest_UnarmAndDanger_Mass7_Ext";
		break;	
			case "quest_UnarmAndDanger_Mass7_Ext":
				AddDialogExitQuest("quest_UnarmAndDanger_9_SJ_StreetResid");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;			

/// ******************** ����� �8  ****************************	
	case "quest_HeadOfState":
			dialog.text = "�, �������, ������ � ����! ��������� �����.";
			link.l1 = "���������, "+NPChar.name+". ����... ��� �� ���������?";
			link.l1.go = "quest_HeadOfState_1";
		break;
		case "quest_HeadOfState_1":
			dialog.text = "�������� �� ������-��������, �������. ��������� ��������� ���� �� ��������� ����� ����.";
			link.l1 = "��� �... ��� ���������.";
			link.l1.go = "quest_HeadOfState_2";
		break;
		case "quest_HeadOfState_2":
			dialog.text = "���� ��������� ����� ����, �������? ��� �� ��������� �������� ������?";
			link.l1 = "����, ����... ��������� �������, �������!";
			link.l1.go = "quest_HeadOfState_2Ext";
		break;
			case "quest_HeadOfState_2Ext":
				DoQuestCheckDelay("quest_HeadOfState_10_EpilogEnd", 1.0);
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;			

		
		
/// ******************** ������ � ������ ���� ****************************	
		case "Smithy Nevis":
			dialog.text = "���! ����� ����, �� ����!  �� � �������� ��������� ��� ������, �� �� ����� ����� ������. �� ���� ��� ������ �������������� � ���� �����, ���, �� � ������ ��� �... ��... �������� �����, ���� ����� ����! ��������� �� ����, �, ���?";
			link.l1 = "���� ������! "+NPChar.name+"! � ���� ���" + GetSexPhrase("","�") + " ���� ������! �� ��� � ����� ������?";
			link.l1.go = "Smithy Nevis 1";
		break;

		case "Smithy Nevis 1":
			dialog.text = "�� � �������, ���! ��� ��� ���������. ��, �� ���� �� ������. ������ ������, ����� � ���, ���. ������ ����� �������� � �������, ��... �� ��� ��������� ��� ����, �� ���������� ����� ����� � ����������! � ��� ������, ���! � �� ���������� �������� ���� ������� � ����� ���� �� ���� ����-����������. ����� ��������� ���� ����� � �������, � ������ - � �����. � ��� �� ����� ���, ���!";
			link.l1 = "��� �, �������� ������, "+NPChar.name+". � ������� ����� ��������. � ������ - �� ���� ������ ����������� � ���������, ����������� ��� � �������? ����� ��� �� ���� � ������ ����� ���� �� ���-����!";
			link.l1.go = "Smithy Nevis 1 Exit";
		break;

		case "Smithy Nevis 1 Exit":
			NextDiag.CurrentNode="First time";
                        DialogExit();
		AddQuestRecord("Smithy", "13");
		sld=characterFromID("Quest_Smithy_Dvoretsky");
		Locations[FindLocation("SanJuan_town")].reload.l35.disable = false;
		pchar.quest.NSmithyQ = "Smithy_SanJuan_Dvoretsky";
			pchar.quest.Smithy_Funy.win_condition.l1 = "location";
			pchar.quest.Smithy_Funy.win_condition.l1.location = "SanJuan_houseSp5";
			pchar.quest.Smithy_Funy.win_condition = "Smithy Funy";
		DoQuestCheckDelay("Smithy 11 Off", 2.0);
		break;

		case "Smithy Sea Atack":
			dialog.text = "�������! �� ��� ������ ����� ��� �����-�� ������ ��� ����������� �������! ��������, ��� �� ������ ��������� ���������� ���������� �����! ��� ���������� �������� ������ � ���!";
			link.l1 = "���������, ��� ��������� ��� ������ �����. ������ �������. ���� �� ���������... �� ��� ��, ����������� ��, ��� �� �������� � ����� ����� �� ������. ����������.";
			link.l1.go = "Smithy Sea Atack Exit";
		sld=characterFromID("Quest_Smithy_July");
/*         switch(GetCharacterShipClass(pchar))
        {
        case 7: Ship = "Ship_deck_Low"; break;
        case 6: Ship = "Ship_deck_Low"; break;
        case 5: Ship = "Ship_deck_Low"; break;
        case 4: Ship = "Ship_deck_Medium"; break;
        case 3: Ship = "Ship_deck_Medium"; break;
        case 2: Ship = "Ship_deck_Big"; break;
        case 1: Ship = "Ship_deck_Big"; break; 
        }
		ChangeCharacterAddressGroup(sld, Ship, "reload", "reload1");
*/
		ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		DoQuestCheckDelay("Smithy 14", 1.0);
		break;

		case "Smithy Sea Atack Exit":
		LAi_SetPlayerType(pchar);
			NextDiag.CurrentNode="First time";
                        DialogExit();
		DoQuestCheckDelay("Smithy 15", 1.0);
		break;


		case "Smithy NxtMrnng":
			dialog.text = "�������, �� ������� �������� �����. ���� �� ������.";
			link.l1 = "�����������, "+NPChar.name+". ������ �����������.";
			link.l1.go = "Smithy NxtMrnng 1";
		break;

		case "Smithy NxtMrnng 1":
			dialog.text = "�������, ��� ������� ��� �� � ����� ������� ���������� �������?";
			link.l1 = "�� ������, "+NPChar.name+". � � �������� ����������. � ������ �� ������!";
			link.l1.go = "Smithy NxtMrnng Exit";
		break;

		case "Smithy NxtMrnng Exit":
		AddQuestRecord("Smithy", "15");
		ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		ChangeCharacterAddressGroup(characterFromID("Quest_Smithy_July"), "none", "", "");
// ������� ����� ���������� ����� ������
//QuestToSeaLogin_PrepareLoc("Tortuga", "Quest_ships", "Quest_ship_3", "");
		QuestToSeaLogin_Launch();
			NextDiag.CurrentNode="First time";
                        DialogExit();
		DoQuestCheckDelay("Smithy 27_1", 1.0);
		break;
	
/// ******************** ��� � ����� ****************************	
	case "Blood_TandP":
			dialog.text = "�������! ���������, �� ��� �� ��� �������! �������, ������ ��������? ��-��-��!";
			link.l1 = ""+NPChar.name+"! ׸���� �������, "+NPChar.name+", ��� ��?";
			link.l1.go = "Blood_TandP 1";
		break;
		case "Blood_TandP 1":
			dialog.text = "��� �! ��-��-��! �� � ��������� ��� ����� ���, ����� ������, ��� ��������! ��-��-��!";
			link.l1 = "��, ��� ��� �����! ��� �� ������� �� ������?";
			link.l1.go = "Blood_TandP 2";
		break;
		case "Blood_TandP 2":
			dialog.text = "�� � ���, ��� ���� �� ����� ������� ������ �� ����������, ��� �� � ������ ��� ��� �����! � �� ���������! �������, ������, ��� � ������ �������, ���, ��� ���!";
			link.l1 = "��, � ������� �� ��, �����! ��� ����� ��������! ���� �� ����� �� ��� ����!";
			link.l1.go = "Blood_TandP 2 Ext";
		break;
		case "Blood_TandP 2 Ext":
			NextDiag.CurrentNode="First time";
            DialogExit();
		SetCharacterShipLocation(Pchar, "PortRoyal_town");
		AddQuestRecord("Blood_ThiefAndPirate","19");
			ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		AddDialogExitQuest("Blood_TandP 108 PRTavern");
		break;
		
		
/// ******************** ����-������ ****************************	
// ������ ��������
	case "MiniQuest_VineUndr":
			dialog.text = "� ���� ��� � �������, �������?";
			link.l1 = "��� ���������?";
			link.l1.go = "MiniQuest_VineUndr 1";
		break;
		case "MiniQuest_VineUndr 1":
			dialog.text = "����� �� ��������� ��������� � ����������� �� ������ � ������� �����������. ������ ��� ��, ��� ��� ������ ��� ����������. � �� �� �� ����� ��������� ���.";
			link.l1 = "������ ����� ��������� ����. �����, ���� �������� ������.";
			link.l1.go = "MiniQuest_VineUndr 1 Exit";
		break;	
		case "MiniQuest_VineUndr 1 Exit":
			NextDiag.CurrentNode="First time";
            DialogExit();
		QuestToSeaLogin_PrepareLoc("Jamaica", "reload", "reload1", 0);	
		QuestToSeaLogin_Launch();
			ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		//AddDialogExitQuest("MiniQuest_VineUndr 4");
		break;

/// ******************** ����-������ ****************************



        case "quest_other_life_exit":
			AddDialogExitQuest("quest_other_life_flashback_port5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "quest_SantoDomingo_night":
			dialog.text = "�����, ������... ����� ����������!";
			link.l1 = "������? ��� ���������? ��� ��? ���� ����������?";
			link.l1.go = "quest_SantoDomingo_night1";
		break;
		
		case "quest_SantoDomingo_night1":
			dialog.text = "�������, � ����� �� �������. ����� ������� �������!";
			link.l1 = "�������? ��� ���? �������!";
			link.l1.go = "quest_SantoDomingo_night2";
		break;
		
		case "quest_SantoDomingo_night2":
			dialog.text = "�����, �����! ������...";
			link.l1 = "";
			link.l1.go = "quest_SantoDomingo_night2_exit";
		break;

		case "quest_SantoDomingo_night2_exit":
			AddDialogExitQuest("quest_SantoDomingo_SanJuan5_tavern_night3");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "quest_SantoDomingo_night_Sound":
			dialog.text = "�������, �������?! ���� ������! ������ ����, ��� �������! �� ������ ����� �!";
			link.l1 = "";
			link.l1.go = "Exit";
				NextDiag.TempNode = "quest_SantoDomingo_night_Sound";
		break;		
		



	}
}
