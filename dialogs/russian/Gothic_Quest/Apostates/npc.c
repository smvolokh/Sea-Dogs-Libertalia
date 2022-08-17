
// ���������� ���� � ������ ������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, iTemp, amount;
	string sTemp;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	   bool ok;
                        int iTest;
                        ref rColony;
                        string sFrom_sea = "";
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_10.wav");
		dialog.text = "...";
		link.l1 = "�� � �������!";
		link.l1.go = "First time_1";			
		break;

		case "First time_1":
	                     PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_HELLO_10_01.wav");
		dialog.text = "�, �������, ���������, ��� ������ ���������� ������ �������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;

		case "First time2":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����!";
		link.l1.go = "First time2_1";			
		break;

		case "First time2_1":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_01.wav");
		dialog.text = "� �� ��� �����, ���� �� ��������!";
		link.l1 = "...";
		link.l1.go = "First time2_2";			
		break;

		case "First time2_2":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "� ���, �����...";
		link.l1.go = "First time2_3";			
		break;

		case "First time2_3":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_03.wav");
		dialog.text = "���� �� ��� �� ��� � ��, �� � ���� �� ����.";
		link.l1 = "...";
		link.l1.go = "First time2_4";			
		break;

		case "First time2_4":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_04.wav");
		dialog.text = "������ ������, ��...";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time2";
		break;

		case "First time3":
	                     PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_10.wav");
		dialog.text = "...";
		link.l1 = "�� � �������!";
		link.l1.go = "First time3_1";

		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_LaMar" && GetPassengerNumber(pchar, GetCharacterIndex("ApostatesFB")) != -1)
		{
		link.l1 = "��� ����� ���������� � �������� � �������� �������� � ������� �����, �� � ��� ����� ����� �� ���������?";
		link.l1.go = "Apostates_man_1";
		}
			
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_DN" && !CheckAttribute(npchar, "quest.APS_DN"))
		{
		link.l1 = "��� ����� ���������� � ����� ����� ��������...";
		link.l1.go = "Apostates_man_4";
		}
			
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "fromBeliz_toPortRoyal")
		{
		link.l1 = "� ������" + GetSexPhrase("","�") + " � �������, �� ��� �������.";
		link.l1.go = "Apostates_man_5";
		}
			
		break;

		case "First time3_1":
	                     PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_HELLO_10_01.wav");
		dialog.text = "�, �������, ���������, ��� ������ ���������� ������ �������.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time3";
		break;


/// ******************** �������� ����� ***********************************

		case "Frederic":
	                     PlaySound("VOICE\Russian\Apostates_01.wav");
		dialog.text = "������ ���� ������. ���������... ������ � ����... � �� ������� �� ������ � ���������� ������� �� ��� � ������ ��������� ��������. ����� � ��� ���� �������� ������.";
		link.l1 = "��, ������!";
		link.l1.go = "Frederic_exit";
		NextDiag.TempNode = "GothicApostates";
		break;
		
		case "Frederic_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS");
		break;

/// ******************** ������ ***********************************

		case "Monah":
		dialog.text = "����� ���� �������, �� �� �������� �� ������. " + GetSexPhrase("����","������") + " ��" + GetSexPhrase("�","�") + ", ������ ��� ������, ������� ��� ������������ �������� ���� ��������, �� ������������� ����. ��������� ����� �� ����� ��...";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_PuertoPrincipe_Port_MonkDead");
		NextDiag.TempNode = "Monah";
		break;

		case "Monk_PuertoPrincipe_tavern":
		dialog.text = "��� ��� ��, ������������" + GetSexPhrase("�","��") + ", �����" + GetSexPhrase("","��") + " ���� �������� ��������� ������ �������?!";
		link.l1 = "��, ��� �, � ������ ����� ������������� - ����������� ����� �� ���!";
		link.l1.go = "Monk_PuertoPrincipe_fight";
		link.l2 = "�? � ����� �����?! � ����� �� ������! � ������, � ����� ��������...";
		link.l2.go = "Monk_PuertoPrincipe_tavern_1";
		break;
		
		case "Monk_PuertoPrincipe_fight":
		AddDialogExitQuest("GothicApostates_ENDGAME");
		DialogExit();
		break;
		
		case "Monk_PuertoPrincipe_tavern_1":
		dialog.text = "�������� ��������? ���������� ��������� � ����� ������� ������. � ���� ��� ����� ����������� ���������� � ����� ������!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_Santiago");
		break;

		case "Monk_in_Santiago":
		dialog.text = "�� ���, ��������� ����, ����������� ������������ � ����� ������ ��� ����������? ������, ��� ������� ����������� ���� �������� �����.";
		link.l1 = "� �� �������, � ��� ��? ��� �����-�� ������� ��������! ����� ���� ��������� ������, � �������������" + GetSexPhrase("��","��") + " " + GetSexPhrase("���������","���������") + "!";
		link.l1.go = "Monk_in_Santiago_1";
		break;
		
		case "Monk_in_Santiago_1":
		dialog.text = "� ����, ��� ��� ����� �� ������� �� ����. � �� � ������������� ��� ������ ��������� �� � ��������� �������, �� ������ ���� �������. � ����� ����� ����� ������������ ��� ������������ - ������� ���� ��������, � �� ������ � ������� �� ���������.";
		link.l1 = "� �� ���� �������� �������� ��������.";
		link.l1.go = "Monk_in_Santiago_2";
		break;
		
		case "Monk_in_Santiago_2":
		dialog.text = "�� �� ������ �������� ���� ��������... ��! ������, � ���� ����� ����������� � ��� �������������, � ���� �����������, ����� �� ����� �������� �� ���� '��������� �����'.";
		link.l1 = "���������, �� �� ��� ��� �����?";
		link.l1.go = "Monk_in_Santiago_3";
		break;
		
		case "Monk_in_Santiago_3":
		dialog.text = "������- ������,  ������ �������, �������� ������ ��� ���� � ���� �������� ���� ����, ��������" + GetSexPhrase("��","��") + ".";
		link.l1 = "...";
		link.l1.go = "Monk3_exit";
		break;

		case "Monk3_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS_in_Santiago_continue3");
		break;

/// ******************** ������ ***********************************

		case "Man_in_SantiagoPrison":
	                     PlaySound("VOICE\Russian\Apostates_08.wav");
		dialog.text = "��� ������� ������ �����. ��, �� ������ ���� ����������, ��� ������ ����� ���� � ����� ���������.";
		link.l1 = "� ��� �� ����� � ��� ��� �� ���� �����?";
		link.l1.go = "Man_in_SantiagoPrison_1";
		break;
		
		case "Man_in_SantiagoPrison_1":
	                     PlaySound("VOICE\Russian\Apostates_09.wav");
		dialog.text = "��� ������� �������, ��� �� ��� ����. ������ ��� �� ����� �� ����. ������� ������, ��� ���� ����������, � ������ ��� ���� ������.";
		link.l1 = "��� �� �������? �� ���� �������� ��������.";
		link.l1.go = "Man_in_SantiagoPrison_2";
		break;
		
		case "Man_in_SantiagoPrison_2":
		dialog.text = "���� �� ���� ����� �� ��������� ������. �� ��� ������ ������" + GetSexPhrase("","�") + " � ����� ������ ��������, � �� �� �������� �����. �����, ���������, ����� ���������� �� ����� ������.";
		link.l1 = "����� �������? � ���� ��� �� ������, �� �������...";
		link.l1.go = "Man_in_SantiagoPrison_3";
		break;
		
		case "Man_in_SantiagoPrison_3":
		dialog.text = "��������� ���� ���� � ����� �� �������� ����� �������� �����, �� ������������ �����, ����� ������� �������, ������� ���� ���� � ���� ����� �� �����, ��� �������� ����������.";
		link.l1 = "�����" + GetSexPhrase("","�") + ", �������.";
		link.l1.go = "Man_exit";
		break;

		case "Man_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS_Santiago_prison_break");
		break;
		
		case "Man_in_SantiagoPrison_4":
	                     PlaySound("VOICE\Russian\Apostates_01.wav");
		dialog.text = "�� ���, " + GetSexPhrase("����","�������") + ", ��� ����������.";
		link.l1 = "��, �������, ����" + GetSexPhrase("","��") + " ���������, �����" + GetSexPhrase("","�") + " ���� ��� ��� ��������.";
		link.l1.go = "Man_in_SantiagoPrison_5";
		break;
		
		case "Man_in_SantiagoPrison_5":
		dialog.text = "����� �� ������ ���� �������� ���� ������� ������������� � ��������� ����������.";
		link.l1 = "��, ����� �� ������, � �� ���, ���� �� ������?";
		link.l1.go = "Man_in_SantiagoPrison_6";
		break;
		
		case "Man_in_SantiagoPrison_6":
		dialog.text = "�� ������, �� ��� ����� ��� ���������. �������, ��� �������� ����� ������? ��� � ����� � ���� � ������� �� ���, ��� � ���������� ����� ����������� ������� �����, ��� ��� ������� �� ��������� ����\n������, ������ ��� ������������ � ���� �� �����, �� ����" + GetSexPhrase("��","��") + " ������� ��� ���� ����, ��� �� ����, ������ �������.";
		link.l1 = "�������, ��� ���������?";
		link.l1.go = "Man_in_SantiagoPrison_7";
		break;
		
		case "Man_in_SantiagoPrison_7":
		dialog.text = "���� ���� ��������� �� �������� � ������. ����� �������� �� ����� ����� ������, �� ������ ���� � ����� �� ����� � ������, �� ���� ��������� �����, ������� ���������� � �������� ��� ��� � ���� ��� ������.";
		link.l1 = "�, ��� ��� �� �������, �����?";
		link.l1.go = "Man_in_SantiagoPrison_8";
		break;
		
		case "Man_in_SantiagoPrison_8":
		dialog.text = "�, ��� �������� �������. �� ������ ����� ����� ������� ���������� �������� �� ����� �� ��������� �������� �����. \n���������� �� ���������� �����, ��������� � ���� � ���� ������. ������� ��� ������� ���� �����. � �����������, �� ����������� ������� ��������� ����������. \n� ���, ������ ���, ��� � ���� ����, ��������� ��� ���� ������ � ����� ���������� '���������', ��, ���� �������� ���������, ������ � ����� ���� � ���� ������� � ���������.";
		link.l1 = "������, � �����, ����� ���, ���� ��� ���" + GetSexPhrase("","�") + " �� �����������, ��� ���� ������ ���������...";
		link.l1.go = "Man_in_SantiagoPrison_9";
		break;
		
		case "Man_in_SantiagoPrison_9":
		dialog.text = "�� ���� �� ������������. � ����� ���� ��������, ������� ���� ������� � ������� � �����������, ����� ������� � ���� ��������� - ������ �������� ��� ��� ��������.";
		link.l1 = "�������, ����� �� ������" + GetSexPhrase("","�") + ".";
		link.l1.go = "Man_in_SantiagoPrison_10";
		break;
		
		case "Man_in_SantiagoPrison_10":
		dialog.text = "���� �� ������" + GetSexPhrase("","�") + "? ��� � ��� �������  �������� ���� �������� ���������? ��-��. ����� ����, �������.";
		link.l1 = "�� ������� � ������� �� ������.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_Santiago_shore");
		break;

/// ********************����� ������***********************************

		case "Apostates_FB":
	                     PlaySound("VOICE\Russian\worker.wav");
		dialog.text = "� ������� �������, � ������ �� ����. ��� �� ���" + GetSexPhrase("��","��") + ", � ��� ��� �� ���� ����?";
		link.l1 = "����� ������ ���� � �� ��������?";
		link.l1.go = "Apostates_FB_1";
		break;
		
		case "Apostates_FB_1":
		dialog.text = "�� ��� ������ �, �� � ��� �� ����, ������" + GetSexPhrase("","���") + ", ��� ��?";
		link.l1 = "���� � �� ���� ���� �����, � �������� ��������� �� ��������, ����� ��������, � �������, �� ������.";
		link.l1.go = "Apostates_FB_2";
		break;
		
		case "Apostates_FB_2":
		dialog.text = "�, �������-��! � ��� � ������� ������ ������� ��������� ������. ������, ����� ���, ��������� ���� � ����!";
		link.l1 = "�����, ������� ����� �� ���, ������� ���������. �� ������ ���������� �� ������?";
		link.l1.go = "Apostates_FB_3";
		break;
		
		
		case "Apostates_FB_3":
		dialog.text = "������? ������, ������" + GetSexPhrase("","���") + " �������, � ������ �����.";
		link.l1 = "����� ������, ����� ����������� �� �������.";
		link.l1.go = "Exit";
		Flag_PIRATE();
		EnemyNationHunterOnMap(true);//������ �������������
		AddDialogExitQuest("GothicApostates_APS_from");
		break;
		
				
		case "Apostates_FB_6":
	                     PlaySound("VOICE\Russian\officer03.wav");
		dialog.text = "��� ������ �������� ��������� �� ������ � ����������� ��������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Apostates_FB_7";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog2");
		break;
		
		case "Apostates_FB_7":
		dialog.text = "���� � ���� ����������, �������. ��������� ��� ���� ������ ������ ��������� ����������, ���� ���� ������� ��� � ���� ����. ����� ��������� ����� ���� ���������, ����� �� ��� �� ��������. \n������� ����� ��������� ��������� � ������ �������� ����� ��, ��� ��������� � ���� ����� ������. � ��������� ������, ��� ��� �� �������� ��� ���� ����������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Apostates_FB_8";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog6");
		break;
		
		case "Apostates_FB_8":
		dialog.text = "�������, �������.";
		link.l1 = "...";
		link.l1.go = "Exit";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog9");
		break;

		case "Apostates_FB_Shore":
	                     PlaySound("VOICE\Russian\worker.wav");
		dialog.text = "...";
		link.l1 = "������ �� �������� ��� �� ��������� �� ����� �����, ���� �����, ���� ���� �����. ������ ������� �� �����, ����� ���� ������ � ������������, ���������� �� ������ ������������� ���.";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_Jamaica_5");
		break;

/// ********************��������� ������ ***********************************

		case "Apostates_SpOfficerInStJuan":
	                     PlaySound("VOICE\Russian\z_arest_01.wav");
		dialog.text = "������ ����������� ����-��-������, �� ����������, ������" + GetSexPhrase("","���") + ". �� ��������� ���������� ������ ���������� ����, � ��� ��������� ���������� ������������ �� ����.";
		link.l1 = "�, ���������� � ��� ����? � �� � ��� �� �������" + GetSexPhrase("","�") + ", ������, ������������ ���� ����.";
		link.l1.go = "Apostates_SpOfficerInStJuan_END_GAME";
		link.l2 = "� ������ ���� ��������" + GetSexPhrase("","�") + " ���" + GetSexPhrase("","�") + " ��������� ������ ���������� ����, ���� �� �� �������� ���� � �����, ������ ���������. ��������, ������ ���������, � ���� ������� ������ ����������...";
		link.l2.go = "Apostates_SpOfficerInStJuan_1";
		break;
		
		case "Apostates_SpOfficerInStJuan_END_GAME":
		AddDialogExitQuest("GothicApostates_APS_END");
		DialogExit();
		break;
		
		case "Apostates_SpOfficerInStJuan_1":
		dialog.text = "������ ����? ����� ��� � ���� ����������, ����� ������� ���� ������. �� ��� �, �� ������ ��� ��� ����� �� ����, ���" + GetSexPhrase("��","��") + ". ���� ��� ������� ������� �������!";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostates_APS_Trinidad_man");
		break;

//********************* ������� �����*****************************

		case "Apostates_man_1":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "�������-��, ��� ��� ����, �������. ������� � �������, ��� �������� ������ ���������� � ���, � � ���������, ��� �� ��� ����� �� �����. ���� �������, ������ ������ �����.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSbank");
		break;

		case "Apostates_man_2":
		dialog.text = "��, ������ ���������.";
		link.l1 = "������� �������.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_bank");
		break;

		case "Apostates_man_3":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "�������-��, �������. �� �������.";
		link.l1 = "��, � ��� ����� ������� ��������. �� � ����!";
		link.l1.go = "Apostates_man_4";
		break;
		
		case "Apostates_man_4":
		dialog.text = "����������, "+GetAddress_Form(npchar)+", �� � ���� � ����������. �� ���� ���...";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostatesAPSbank4");
		break;

		case "Apostates_man_8":
		dialog.text = "��, ������ ���������.";
		link.l1 = "�������, �� ��������� ����. �� ������� ����, � ����� �������.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_message");
		break;

		case "Apostates_man_PortoBellofrom":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "...";
		link.l1 = "������� � ����!";
		link.l1.go = "Apostates_man_PortoBellofrom_1";
		break;
		
		case "Apostates_man_PortoBellofrom_1":
		dialog.text = "��...";
		link.l1 = "��� �� �� �����? ����� �������� ����� � ���� ���� �������.";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostates_APS_dialogEnd1");
		break;

		case "Apostates_man_PortoBellofrom_2":
		dialog.text = "��� ����������. ��, ������ ���������.";
		link.l1 = "��...�������.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_dialogEnd5");
		break;

		case "Apostates_man_APSH":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "�� ��� ������ �������.";
		link.l1 = "���������. ������� � ����!";
		link.l1.go = "Apostates_man_APSH_1";
		break;
		
		case "Apostates_man_APSH_1":
		dialog.text = "��...";
		link.l1 = "������, ���� ���� ������ �����.";
		link.l1.go = "Exit";
		AddDialogExitQuest("APSH_Ruins1");
		break;

		case "Apostates_man_APSH_2":
		dialog.text = "��� � ��� ������� �������, ������ ���������.";
		link.l1 = "��... ������� ���...";
		link.l1.go = "exit";
		AddDialogExitQuest("APSH_Ruins5");
		break;













		
		case "Apostates_man_10":
		dialog.text = "�������� ������ �� ������� ���, ��, ��� �� �����, ��� ��� ���� ���� ���������.";
		link.l1 = "� � ��� ����������� ��� ���������?";
		link.l1.go = "Apostates_man_11";
		break;
		
		case "Apostates_man_11":
		dialog.text = "������� ��������� ���������� ����������, ��� ��������� ����� �������.";
		link.l1 = "�� ���� ��� ��������� �� ����� ����� ������...";
		link.l1.go = "Apostates_man_12";
		break;
		
		case "Apostates_man_12":
		dialog.text = "�� ������ ���, �������. ������ �� ������� ������������ ���������� � ����� 50 000 ���� ������ ������� � ���� � ������ �������� �� ���.";
		link.l1 = "�������, ���� � ���� � ����" + GetSexPhrase("��","��") + " ��������?";
		link.l1.go = "Apostates_man_13";
		break;
		
		case "Apostates_man_13":
		dialog.text = "���, �������� ��������� �������� ������� � ��������� 500 ������ ������� � 2000 ���� ����� �� ������ ���������. � ��������� ���������, � �������, � ��� ������� �����, ��� �� ����� ����������� ��� � ��������������� �����.";
		link.l1 = "����. � ���-�� ���������" + GetSexPhrase("","�") + " � ������?";
		link.l1.go = "Apostates_man_14";
		break;
		
		case "Apostates_man_14":
		dialog.text = "���, �������, � ������ �� �� ����������, ��, ��� ��, �� ����������� ���� �������.";
		link.l1 = "��� ����, ��������� �������, ��� ���� ����� ��������� � ���������� �����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
		AddDialogExitQuest("GothicApostates_APS_trade");
		break;

//********************* �������� �������*****************************

		case "Second life":
	                     PlaySound("VOICE\Russian\QuestMan03.wav");
		dialog.text = "��, ��� ��������, ��� �� ���� �����. ����� �� � ���� �����������?";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_1";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog4");
		break;
		
		case "second_1":
		dialog.text = "���������� ������ ����.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_2";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog8");
		break;
		
		case "second_2":
		dialog.text = "��� ������ � �������, ������ ���� ���������� ��� ���� � �������, �� �� ���� �� ���������� � ����� ������, ���� ������� ������������� � ��� ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_3";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog11");
		break;
		
		case "second_3":
	                     PlaySound("VOICE\Russian\QuestMan05.wav");
		dialog.text = "����������� ����. ���� ����� �������� �������, �� ������� ��� ���� ������������ �������� ���� �������. ���� ������������ �� �����, ���� �������� ������� ���� �� ����.";
		link.l1 = "�������, ��������, �� �������� ����� � �� ��, ��� ������� ���� �� ����� '������', ����� �� � ��� �� ��������" + GetSexPhrase("","�") + " - ��� ����.";
		link.l1.go = "second_4";
		break;
		
		case "second_4":
		dialog.text = "��, ����, � �� ����� ������ ��� �����������, ������������ ���� �����, ��� � �� ����� ������� � �����.";
		link.l1 = "� �� �� ����� ���������" + GetSexPhrase("","�") + ", �� ����������� �����, �� �� ���� � ������� ��� � ������ �����������...";
		link.l1.go = "second_5";
		break;
		
		case "second_5":
		dialog.text = "�����, �������� ���� ��������� ������ � ����� �����. ��������� ���� �������������� � ������ ��������. ���� ������" + GetSexPhrase("��","��") + ", �� ��� ���� ������������� � ����������� ���������.";
		link.l1 = "� �� � �������������, �� ��� ������� ���� ��������� ������� ����� ����... ��� ��� �� ����������, �� ����� ������ ������?";
		link.l1.go = "second_6";
		break;
		
		case "second_6":
		dialog.text = "���, " + GetSexPhrase("�������","�������") + ", ��� ��� �������� ������ ������������ ����������, ������� ������� ���� ������� ��� ����������� ������������� ����������\n���� ������� ������ ������ ������� � �������� �������, ������ �������� ��������� �� ������� ���������� � ������� ���������� XIII ����, �� ��������� ����� ������� ��������� � 16 ����.";
		link.l1 = "��� �� �������?";
		link.l1.go = "second_7";
		break;
		
		case "second_7":
		dialog.text = "��, �� ��������� ������. � ��� �������� ���� �� �������� ������� ���������� ����� ���������� ��� ����!";
		link.l1 = "� �����" + GetSexPhrase("","�") + ", ��� �� ��� ��������������� ���� ��������, ����� ���� ��������� ���������.";
		link.l1.go = "second_8";
		break;
		
		case "second_8":
		dialog.text = "��, ������� �� ����. � ��� ��� ��� ��� ������ �� ��������: ����������������, ���������, ����������. ������, �� ����� ��, ��� � ��� ���������� ���� - ����� � ��������� � ��� ������ �� ������!";
		link.l1 = "� � ���� � �� ����������, �� ������ ������, �� ������� ����� �� ��������.";
		link.l1.go = "second_9";
		break;
		
		case "second_9":
		dialog.text = "������ ���. � ��� ��� ���� ���������� ����������� ����� ��������� �� ����� ��������������� ����. �� - �����, ������� ��������� ������ �� ����� ������ � ������ ������� � ����� �����. \n���, ��� ���� ������ �������������� � ���, ������� ������. ��� ����" + GetSexPhrase("��","�") + " " + GetSexPhrase("�����","��������") + " ������ �������� ����-������ ������������� ���������.";
		link.l1 = "���, �������, � ���� ����� ��� �� �����, ��� ��� ������ �� ��� ���� ���-������.";
		link.l1.go = "second_10";
		link.l2 = "�������, � � ����, ������ ���� ���� ��������, �, ���-����, ������� �������, � ��� ����� ���������� � ������������ ����� �������.";
		link.l2.go = "second_12";
		break;
		
		case "second_10":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 20000);
                                          Log_Info("�� �������� 20000 ����");
		dialog.text = "�� ��� �, � ���� ������� � �������, ��� ��� �� �� �������. ����� ����. ������, ������ ����������� �� ���� ���������, � �� ��, ��� �������� �� ��� ����� ��������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		AddDialogExitQuest("GothicApostates_APS_END");
		break;
		
		case "second_11":
		dialog.text = "�� �������� � ����� ����, " + GetSexPhrase("����","������") + " ��" + GetSexPhrase("�","�") + ".";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		break;
		
		case "second_12":
		dialog.text = "�, �� ���� ���� �� ������! ������ ��� ��������� ����� ����� ��������. ���� � ���� ����� ��� ����������� ������������ ������ ���������, �� � ����� ���������� ��� ���������� ����� ������� ����. \n������, ������ ��������� ����������� �� ���� ���������, � �� ��, ��� �������� �� ��� ����� �������.";
		link.l1 = "...";
		link.l1.go = "second_13";
		break;
		
		case "second_13":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 40000);
	                     ChangeCharacterComplexReputation(pchar, "nobility", 10);
		dialog.text = "��� ���� ������ ������� - ����������� � ���������� � ���-����. � ���� ���� ����� ������ ���������� ��� ���.";
		link.l1 = "��� �������, ������, ��� � ��� � ����, ������, �� ��� �� �������� �����, ��� �� ���-���� ���� � ��� ����������� ������?";
		link.l1.go = "second_14";
		break;
		
		case "second_14":
		dialog.text = "��� �������� �������� � �������� ���� �������� � ���, ��� ���� �������� ��������� ������ � ����� �����. \n��, � ���������, ���� � ����� �� ������, ��� ��� �� ������ � ��� ���� ������������. �������� ��� ����� �������� ��� ���� �����, ��� ��� ������ ���� ����������� ������ ���� ������ �������.";
		link.l1 = "�� ��������, � �����, ��� ��������� � ���.";
		link.l1.go = "second_15";
		break;
		
		case "second_15":
		dialog.text = "����� � ��� �� �������� ��������. ��� ��� ���� - �������� ��� ���������� ����... �����, �������, ����������� �� ���. ���� ����� ���� �����. ��� ������� � ��������� - ������ ���� � �������� ������ �� ����� � �����.";
		link.l1 = "��� ��" + GetSexPhrase("��","��") + ", ��������� ����, �������. ������, ������ ����� �������� � ����?";
		link.l1.go = "second_16";
		break;
		
		case "second_16":
		GiveItem2Character(pchar, "Mason");
		PlaySound("interface\important_item.wav");
		dialog.text = "��� �� ��������, ��� ������, ������� ����� ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		AddDialogExitQuest("GothicApostates_APS_usurer");
		break;

		case "second_20":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "������� - ��...";
		link.l1 = "����������, �������. ��� ������� �������� ������ ��� ���� ����������.";
		link.l1.go = "second_21";
		break;
		
		case "second_21":
		dialog.text = "�����������, �� �����!";
		link.l1 = "��-������,  ������� ������� ������ � ��������� ����������� ������ �������� �� ��� �������, � ��-������, ��� ���� ���� ������� ������������ ��������. �� � � ������������ �������� ������� �������� ������� '����������'.";
		link.l1.go = "second_22";
		break;
		
		case "second_22":
		dialog.text = "� �����������, ��� ���� ������ �����-������ ��������... ��� ��� ����������� ������� ��������?";
		link.l1 = "��� ��� ��������� �������� �������� � ����� �� ���������, �������� ���� �������� ������� ���������� ��������� � ����� ����� � �������� ���������� � ����.";
		link.l1.go = "second_23";
		break;
		
		case "second_23":
		dialog.text = "� ����� ������, ���� ���� ������������ � ����� ����� � ���������� ��� ��� �����������, ���� �� ��� ����� ����� ��� ��������, ��� �� ����� �� ������� � ���� �������, ������� ����� ���� � �� �������� ��������, ��� ����� � ��� ����\n� ������ ������, ��������� ������� ���� �����. �� ��� ��� ��� � ���� ����� ������ ����, ����� �� ��� ��������.";
		link.l1 = "��� �����" + GetSexPhrase("","�") + ", �������, ���������� ����������.";
		link.l1.go = "second_24";
		break;
		
		case "second_24":
		dialog.text = "� ����������, ��� ��� �������, �������, ��� �� ����, �������� � ���� 15000 ���� �� ������� �������.";
		link.l1 = "��� � ����, �������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_26";
		AddDialogExitQuest("GothicApostates_APS_PortoBello");
		break;

		case "second_26":
		dialog.text = "����� ���, "+pchar.name+" �� �������!";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_26";
		break;

		case "second_27":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "�, "+pchar.name+"...";
		link.l1 = "����������� ����, �������. � ��������" + GetSexPhrase("","�") + " ���� ���������.";
		link.l1.go = "second_28";
		break;
		
		case "second_28":
		dialog.text = "������� ����, �������, �� ��������, ��� ��� ��������.";
		link.l1 = "��� ���������? ��� �� ��������� �����?";
		link.l1.go = "second_29";
		break;
		
		case "second_29":
		dialog.text = "���� � ���, ��� ������� ��������� �� ������ ������� � ��������� �������� ��� ������ ���������! �� �������� �� ������, �� �����.";
		link.l1 = "������ ����� ����������? ����� ��� �����-�� ���������� ������.";
		link.l1.go = "second_30";
		break;
		
		case "second_30":
		dialog.text = "���, ������ ����� ���� �� �����! � ������� �������� �� �������� �������� ������� ��� ����.";
		link.l1 = "��� �� ��� ������, ��� ���� �������, ���� �� ���� ����� ������ �����������...";
		link.l1.go = "second_31";
		break;
		
		case "second_31":
		dialog.text = "��� ����������� �������� ������. ������� ���� ��������, �������� �� ��������" + GetSexPhrase("","�") + " �� ��� �� ��������� � ������?";
		link.l1 = "��� �� �������, �����, �������.";
		link.l1.go = "second_32";
		break;
		
		case "second_32":
		dialog.text = "��� ���, ��� �������� ����� ����������� ������. ��� �������, �������� � ������� ���������� ���� �������.";
		link.l1 = "��� ��� ������ ��� ������� � ����-��-������ ���� ����������� ����, �����������, ��� ��� �� ������� ���������������� ��������.";
		link.l1.go = "second_33";
		break;
		
		case "second_33":
		dialog.text = "�� ��, ���� ������� � ���� �� ����� ������� ���������� ����� ��������, �������� �� ��������� ��� �������.";
		link.l1 = "���� �� ��� �����, ����" + GetSexPhrase("","�") + " �� '�����' ��� � ����-��-������. ������ � ����� �� ���������, �� ��� �� ������� �������!";
		link.l1.go = "second_34";
		break;
		
		case "second_34":
		dialog.text = "���������� ������� ���������� ��� ���� ������. ��� ��������, ������ � ����, �� ���������� �������� �� ������ ��������� ������, ��� ��� ����� ����� ��������.";
		link.l1 = "��... ��� ���������, �������, � ������� ���� �����������, �� ������ ���������. �� ������ ���� ���������� ���� ��������, ����� ��������� ����.";
		link.l1.go = "second_35";
		break;
		
		case "second_35":
		dialog.text = "��������� � ���� ���� ��������. ����� ������� �� ��� �������? � ��� ������� ������ ���� �������\n����, ���� �� ������������� ����������, ��� �� �����-������� ������� ������� ������� ��� ������� ���������\n������������, ��� ���� ������ ������� �� ����� ��������, ��� ����� ���������� ������ ����� ��������� �� ����� �������� �������, ��������� �� ������� ����� � ������ �������.";
		link.l1 = "�� ����� ������ �� � �� ���������.";
		link.l1.go = "second_36";
		break;
		
		case "second_36":
		dialog.text = "���� ���� ������� ��� ��������, ������ ������ �� �����, �� ��� ���������� �������. ������� ���� ����� �������� ������� � ���� �������, ����� ������� �� � �������� ����� ������� �� ������������ ��������\n��� ����� ����� �������� ������� �� ������� ������ �� ������. ���� ���� � ������ ��� �������?";
		link.l1 = "���, ��" + GetSexPhrase("��","��") + " ���������, � ��� ������ � ���� ������ �������� �����. ������� ���������� ���������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_37";
		AddDialogExitQuestFunction("GothicApostatesAPSGoldShip");
		break;
		
		case "second_37":
		dialog.text = "���� ��, ��� �� ��������, ������� - ��� ����� �� ������ ����!";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_37";
		break;

		case "second_38":
	                     PlaySound("VOICE\Russian\QuestMan06.wav");
		dialog.text = "...";
		link.l1 = "�������. � ���� ��� ��� ���� �������.";
		link.l1.go = "APSGoldConvoy_Check";
		break;

		case "APSGoldConvoy_Check"://�������� ���������
		int iHal = 0;
		for(i = 0; i < COMPANION_MAX; i++)
		{
		iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
		sld = GetCharacter(iTemp);					                                                   pchar.questTemp.APS.Spa.CompanionIndex = sld.Index;
		if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MANOWARV ) iHal++;
			}
		}
		if (iHal > 0)//������� ������� �� � �����������
		{
		amount = sti(pchar.questTemp.APS.Spa.GldQty) - GetSquadronGoods(pchar, GOOD_GOLD);
		if (amount <= 0)
		{
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��, ������ �� ����� - ����� �������� ������ ����� � ����� ��� �� ��� ����������... �� ������� ���������� � ����������, �������\n �����������! ��� ������ �����������, ����� �������� �������� �������, ������ ����������, �������, ��� ������� �����������, ����� ��������!";
		link.l1 = "�������! ������� ������� ������� ������ ����� ��������. ������� ������������� ������������.";
		link.l1.go = "APSGoldConvoy_complete";
		}
		else
		{
		dialog.text = "��, ������ �� ����� - ����� �������� ������ ����� � ����� ��� �� ��� ����������... �������, �� �������� �� ���� ����! � ���������� ����, ������� ������ ������ ���� ����\n��� ������� ���� �� ������ ��������� ����� ������ �������, �� � ����� ���������. ��������� �� �������� �� �� ������. � �� ����� ����� � ���� ��� - �������� ��� ����������!";
		link.l1 = "�� � �����, ���� ������!";
		link.l1.go = "APSGoldConvoy_fail";
		}
		}
		else
		{
		dialog.text = "���-�� � �� ���� � ��� � ������� ���������� ��������� �������. � ���� ������� ���, ��� ��� ���� ����������� �������� ������. �� ��� �������?";
		link.l1 = "��... �� ����� �������� �������� �������? �������, ���� ��� ������ � ������.";
		link.l1.go = "APSGoldConvoy_noShip";
		}
		break;

		case "APSGoldConvoy_noShip":
		dialog.text = "� ��������� �����, ��� � ������, � ���� - ���. �� �������� ������� ������ ��������, � � ����� �� ����� ����� � ���� ��� - ����������� ����� �� �����. �������� ��� ���������� ����������!";
		link.l1 = "�� � ���� � �����!";
		link.l1.go = "APSGoldConvoy_fail";
		break;

		case "APSGoldConvoy_fail":
                                          LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);//������� ����
		DialogExit();
	                     AddQuestRecord("APS", "20");
	                     CloseQuestHeader("APS");
	                     DeleteAttribute(pchar, "APS");
		break;

		case "APSGoldConvoy_complete":
		dialog.text = "������� �� ��� ������. ��� ����� �������� � ���, ����� ���������� ������, ��������� ��� ���. � �� ����������� ���������, ������� - �� �� ������ �� � �������� �� ���� �����. �� �������!";
		link.l1 = "������, �������. � ����� � ��� ������.";
		link.l1.go = "exit";
                                         SetFunctionTimerCondition("GothicApostatesAPS_Work", 0, 0, 1, false);
		AddDialogExitQuestFunction("APSGoldConvoy_Remove");
		AddSimpleRumourCity("�������, ��� �� �������� ������� ������. ����! �� ��������� � ������ �����, �������!", "FortOrange", 10, 3, "");
		break;

		case "second_40":
	                     PlaySound("VOICE\Russian\QuestMan05.wav");
		dialog.text = "��� � ��... ��� ��� ������ �������. � ��� � ������������ ������� ������ ����� ����������� ��� �����, ��� ��������� 774000 ����, �������� ��������\n��������� ������ ������ �� �������������� ������ �������, � ������� ����������� ���� �������� ��� ����� � ������� �� ����������� ��������.";
		link.l1 = "�������. ��� ��� �������.";
		link.l1.go = "second_41";
		break;

		case "second_41":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 774000);
		dialog.text = "�� � �� ���� �����, ������� ���� �������� �������. ������� �� ������ ��� � ��� ����������.";
		link.l1 = "��, ��...";
		link.l1.go = "second_42";
		break;

		case "second_42":
		GiveItem2Character(pchar, "sextant2");
		Log_Info("��� �������� ��������");
		PlaySound("interface\important_item.wav");
		dialog.text = "...";
		link.l1 = "�������, �� ������... ����� ����� ���������� ���� ���������� ��������!";
		link.l1.go = "second_43";
		break;

		case "second_43":
		dialog.text = "������ ��� � ��� �������, ����� �������������� ������ ����, ������, � ������ ������� ��� ����� ����� ������� ���������� ����������.";
		link.l1 = "���� � ������, ��� ��������� ��� ���.";
		link.l1.go = "second_44";
		break;

		case "second_44":
		dialog.text = "������� "+pchar.name+", ���� � � ��������� � ��� ������������� ���������, �� �� ���������, ��� �� ��������� ��� � ����� ��������� ����� ������ ������, ���� ��� ����. � ��� �� �����, �� �������� � ����� ����� �� ����� ������� ���������.";
		link.l1 = "��... �������.";
		link.l1.go = "second_45";
		break;

		case "second_45":
		dialog.text = "�� ������������, �� �������������� ���� ����� �������, ���� ��������� �������������, ������� ���������� � ����� ����� ������� ����� ����\n�� ����� � ���� ��� ������� ������������ ��� � ���� ������ � ���� �������� �������. �������� �� ������� ��������� ���, � ���� ���������� ��� ����� ������...";
		link.l1 = "� ������.";
		link.l1.go = "second_46";
		break;

		case "second_46":
		dialog.text = "�� ����� ��� ����� �������� ������, �� �������� �� ����� ���� � � ������ ������� �� ��, ��� ��������� �����������, �������, ������ ������, ���������� � ������ � ��� ������ ������\n������, �� ������������� ���������� �� ��� ���������� ����������� �����\n������� ������������ ����������� �����, ��� �� �������� � �� ����� �������� ��� �������� �� ����� ����.";
		link.l1 = "������� ������� ����� � ����.";
		link.l1.go = "second_47";
		break;

		case "second_47":
		dialog.text = "������. ��, ��������, �������, ��� �� ���� �������, ����� ���� ���� �����, ��������� ����� � ����� ��� ������ ��������� ����� - ����� ����\n�� ������ ��� ��������� � �������� ������ ��� ���, ������� ��������� �������� ��� ���, ��� ����� ���������� ��������� ���������\n��� ���, ����������� ���� - ���� ����� ������� �� ������... ���������� ������������ �������... � � ��� �� ���� ���� ����� ���� �� ������� ����������� ���� ����� � ��������� ����� ��������� ��������. �������� ����������, �� ������ ��?";
		link.l1 = "��, � ����� ��� �� ��������� �� ������ ���� �����������, ����� ���� ���� ��...";
		link.l1.go = "second_48";
		break;

		case "second_48":
		dialog.text = ""+pchar.name+" �����, �� �� ����� ������ ����� � ����� � � ����� ��������� � ���������, ����������� �� ����������� ��� ���� ��������� ������� ����������� ������� ������������ ������ ������ ���������. �� ������ ���� ���� � ������������� � � �������� � �����.";
		link.l1 = "����� ��������, ������� �� �����. � ��� �� ������, ��� �� � �������� � ���� ������������ ����� �����?";
		link.l1.go = "second_49";
		break;

		case "second_49":
		dialog.text = "�� �����, ��� ���, � ��� ���� ������ �� �������� ������ ���� ����� - ����� ����, ������� �������� ��������. �� ���������, ��� �� ���� ����� ����� ������!";
		link.l1 = "���������? ������ ������� ����� ��� � ���������� � ���?";
		link.l1.go = "second_50";
		break;

		case "second_50":
		dialog.text = "��� ���� ��... �� ������� ���� ��������� ������� ����� � ���� ����. �������� ����� � �������������� ������. ���������� � �� ����������� � ���� �����, �� ��������� ������������� ���������, �������� ����� � ���� ������� � ������ �����!";
		link.l1 = "�������. �������, � �� �����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_51";
	                     AddQuestRecord("APSH", "1");
                                          pchar.questTemp.APS = "APS_ChurchVayne";
		break;
		
		case "second_51":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_51";
		break;

		case "second_55":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ��� �������, ���� ���-������ �� ����� �����.";
		link.l1 = "����������� ����, �������. ���-��� �������.";
		link.l1.go = "second_56";
		break;

		case "second_56":
		dialog.text = "� ��� ����������� ������.";
		link.l1 = "��, �� ������������ ������� �������, � ����� ������ ���� �����...";
		link.l1.go = "second_57";
		break;

		case "second_57":
		dialog.text = "������, � ������.";
		link.l1 = "����� ���� ���� ������� �������� ��������, �� ������� �� ���� ������� ���������� � ���� ������� �����, ������ �� ���, ������ � ������ ������. �� ������ ����� ��� ������� �������� ����� �� � ��� ���������� � ����� �� ������ �������� �� ������� ����-�������. � ���� ����� ����� ����� � ���������� ���-������ �� ������� ����-����� � ������� ��������� ����� � ����� ���������...";
		link.l1.go = "second_58";
		break;

		case "second_58":
		dialog.text = "����� �� � ����, ����� � ���� �� ���� ���� ������ ������. �� ��� ��� � ���� �������?";
		link.l1 = "��, �������, � ��� ���, ���������� ������ ������������� � �������������, ����� ��������, ������ ����������� ������ � ������� � �������������.";
		link.l1.go = "second_59";
		break;

		case "second_59":
		dialog.text = "�� ������� � ��������, ��� � ����?";
		link.l1 = "�� �������� � ����, ������ ���� ���������, ��� ��� ������ ������������������� �� ����.";
		link.l1.go = "second_060";
		break;

		case "second_060":
		RemoveItems(PChar, "architects_table_7", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "����������?";
		link.l1 = "��� �����, �������.";
		link.l1.go = "second_061";
		break;

		case "second_061":
		dialog.text = "���� �������� ��������� ����� ���, �������������� ����� ��������� ������ � ����� ������ �������. ��� ���, ��� ���� ������� ������, ��� ����� ���������� ���� ������ � �������� ��������� ������ �� ����� ���������. �� �������.";
		link.l1 = "�������, ��� ���������. ������, ��� �������, ������ ��� ������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_61";
                                         SetFunctionTimerCondition("APSH_Ruins6", 0, 0, 1, false);
		break;

		case "second_61":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_61";
		break;

		case "second_62":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "�� ��������, ��� �������� ���� ����� �������� ����� �����, ������� ������� ��������� ��������. ��� ����� ���������� ����, ��� ��� � �� ������� ��� ������. �� � ���� �� ���-�� ������������, ������ ���� ����� ���� ������������� � ����.";
		link.l1 = "��� �� ����?";
		link.l1.go = "second_63";
		break;

		case "second_63":
		GiveItem2Character(pchar, "architects_table_7");
		Log_Info("�� �������� �������� ��������");
		PlaySound("interface\important_item.wav");
		dialog.text = "�� ��� �� ������� �� ���. ������ ��������, ����� �������� �� ����� ������. �� ������ ������� �������� ������� �������, �� ����� ����� �� ������� ��������� � ������ � ������ �����, ��� ��� ���������� ������� ��������, ����� �������. ����� ��� �������� ��, ���� �������� ��� ��� ������� ��������, ��� ��� ����-����.";
		link.l1 = "�����, ��� ������...";
		link.l1.go = "second_64";
		break;

		case "second_64":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 70000);
		dialog.text = "� ����� � �� �������...��� �� ����� ����...";
		link.l1 = "�������. ����� ��� ����...";
		link.l1.go = "second_65";
		break;

		case "second_65":
		dialog.text = "����� ���� �������...";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_66";
		AddDialogExitQuest("APSH_Ruins7");
		break;

		case "second_66":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_66";
		break;

		case "GothicApostatesAPS_quests_ship":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "�������, � ������� �������? ������ � ��������� ���� �������. ����� ������������� ����� ������� �������� �� ����� � ���� ���� ����������, ��� �� � ��� �� ����. �� ������ ��� ��� �������� ��������.";
		link.l1 = "�������, � ��� ����� ����� ������ � ���������� � ��������� ���, ������ ��� �������� �������, � ��� ���������� ����� ��������.";
		link.l1.go = "GothicApostatesAPS_quests_ship_1";
		break;

		case "GothicApostatesAPS_quests_ship_1":
		dialog.text = "���, �����, ������� � ��� ������� � ����, ��� �� �� � �����, ��� ��� �� ������� ������� � ���������, ����, �� ��� ����� ������ ��������, ����� ���������� � ����� ����, �� �� ����� ���� ���� �� ���� �� ��� � ��� ���������\n������� ��� ������� ��� � ����. �� ���� ����������� ������ ������, ��� ���� �������. ���, ��� ��� � ���� ����� � ������� ����, ���������� � ��� ��������. ��� ������� � ��������� �� ������� �� ������ ������� ���� �� ������, �������������.";
		link.l1 = "������������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "GothicApostatesAPS_quests_ship_2";
	                     AddDialogExitQuestFunction("CheckIslandAPS_Coordinates");
		break;

		case "GothicApostatesAPS_quests_ship_2":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "GothicApostatesAPS_quests_ship_2";
		break;

		case "second_70":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� �������. ��� ���� ���� ���������!";
		link.l1 = "��... ����� ���� �� � �� ����� ���������?";
		link.l1.go = "second_71";
	                     //AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres");
		break;

		case "second_71":
		dialog.text = "�����, �� �� ��� ����� ��������! ��, ��� �� ���� ������ ������� ������ �� ���� ����, ���� � ���� �����, �� ��� �� ����� ���� ������ � ����� ������������. ��������� ����� ��������� � ������, �������� ��������� ������� �� ��������� �� ������ � � ���� �� ������� ���������.";
		link.l1 = "�������. �� ��� ����� ����� �������� ������? ������ �������, ������� �����, ������� ������ ��������� ���� ����, ��� �� ���������� �����!";
		link.l1.go = "second_72";
		break;

		case "second_72":
		dialog.text = "���������� ���, �������� ����� ���������� � ������� ���������. ����� ������ ���������� ���� ���� ���������� �� ������ �������� �� � ������� ��������, ���� ����� ������ ������� ������ � ������, ������ ����� ����������� ���������\n� ��� �� ������� ���������� ������������� �����������. ������ �� ��� ����� �������� ������, �� � ��������� ��� ��� ��������� � ������ ������ �����\n������ ���� �� �������� ���������� ����� ������� ������ � ���������� ���� � ������ �������� �� ���������� ��������, ������ ��������� � ������, �� � � ���������� ����. ��������� ����� ����� ����� ����� � ����������� �������, ������ �� ��� ����� ������ � �������, ����� ������� ���� � ��� ����� ������� � ����������� ����, ������� ������ ������� ������� ����� �� ������� ��������� � ������.";
		link.l1 = "� ��� ����� ��� ���������!";
		link.l1.go = "second_73";
		break;

		case "second_73":
		dialog.text = "���������� ����� � ��������� ��������. ��������� ���� � ������� ��������� �����. �� �������� �������� ������� � ���� �������� ������ �� ��� ����, �� ����� ����� ������ ������ � �������������� � ������� ������� ��������� ����� ��������, ��������� ����������.";
		link.l1 = "�� � ���� � ��� ������������� ����� � ������ ���� ����� �����.";
		link.l1.go = "second_74";
		break;

		case "second_74":
		dialog.text = "� � ���� ��� ����������?";
		link.l1 = "��, �������, �� ��� ��� �������� ��������.";
		link.l1.go = "second_75";
		break;

		case "second_75":
		dialog.text = "������ �� ���, ���� ������������� ������� ������� ��� ��� ������������� ���. ����� ���� ������� � �����?";
		link.l1 = "��, ���������� ������� � ��� ��� ������� ��.";
		link.l1.go = "second_76";
		break;

		case "second_76":
		dialog.text = "���� �� �����?";
		link.l1 = "����� ���� ������, ��������� ���� ��� ����� �����.";
		link.l1.go = "second_77";
		break;

		case "second_77":
		dialog.text = "������, ����������, �� ��� � ��� � �����.";
		link.l1 = "� ��� �� � �� ������?";
		link.l1.go = "second_78";
		break;

		case "second_78":
		dialog.text = "�� ���������. ��������� �������� ��� �� ����� �� ��������� �����������, ���� ��� �� ����� �����.";
		link.l1 = "���, ��� ��� �������?";
		link.l1.go = "second_79";
		break;

		case "second_79":
		dialog.text = "������ ����� ������ ������, ��� �� � ���� ����� �������� �����, �������� �� �� ����� ���������.";
		link.l1 = "���� �� ������� � ���. ���� ��� ���������!";
		link.l1.go = "second_80";
		break;

		case "second_80":
		dialog.text = "���������� �� �� ���� �����, � ����� �����. ��� ����� ����������� �� ������� � �� ���� �� ���. ����������...";
		link.l1 = "������ � ���� �� �����, ��� ������ �� ��� ����� ��� ���������.";
		link.l1.go = "second_81";
		break;

		case "second_81":
		dialog.text = "��� ��� �����, ��� ���������� ��������������... ����� �� ��� ������, �������� � ����� ����� ����� �������.";
		link.l1 = "������������. �� ������. ������ �� ����.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_1");
		NextDiag.TempNode = "second_82";
		break;
		
		case "second_82":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_82";
		break;

		case "second_90":
		dialog.text = "...";
		link.l1 = "����������� ���� �������, �� ���, ���� ��� - ������!";
		link.l1.go = "second_91";
		break;

		case "second_91":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���� ���������. ��, ���� �������������� ���� ������� ��������� � ������������� �� ������� � � ��������������. �� ��������� �������� ������� ���������, ����� ������� �������� �������� � ����, �� ��� ���� ��� ����� � ����, ������ ��� � ���� ���������, �� ������, ����� � ���������.\n������� ������� ������ ��� ���, �� ���� ��������� � ���� � ���������, ��� � ��� ���������.\n��� ��������� �� �����, ����� ������ � ��������� �������� ������� �� ����� '��������� ������'. �� �� ������� ����� ����������� �������� ����, ������� ��� ������ ����� ����� ��������� ������ ����������, ������������ ����� ��� ��������, �� ���������� ����� ����� �� � ����� ����� � ������� ��������� �� ����, ������ � ���� ����� ������ ����. � �������������� �� ���� ������� � ���-��� ������� ������ � ����������. ������� �� ����� �����... �� ����� ���������.";
		link.l1 = "�, ��� �� ������!";
		link.l1.go = "second_92";
		break;

		case "second_92":
		dialog.text = "� ������ ��������, �� �������� �������� ����������� ������, � ������� �� ���� ����� �������������, ��� ����� ������� ����� �� ����� ���������, ������ �� ��� ������� ����� �������� ����, ����� ��� ������� � �� ����� � ��������� ������� ������ ��� ��� ������� �� �����\n�� �� ���� ���������� � ������ �����, ������� ���� �����, ��������, �� ����������� � ��� ���������� ���������� �� ������� �� ����� ������ ����, �� ��� ����� ���������� �� ��������� ����� � ��� �� ��� ������� ���������� ������ ���� �� ����������. ��� ������� ������ ����� ����, � ���� ��� ��������.";
		link.l1 = "����, � ��� �� ������ ���� �� ���� �� ��������!";
		link.l1.go = "second_93";
		break;

		case "second_93":
		dialog.text = "���������, � ��� �� � ����� ����.";
		link.l1 = "�� ��������� ��� �����, ������ ������� ���.";
		link.l1.go = "second_94";
		break;

		case "second_94":
		dialog.text = "�����... �� � � ���� ������� ��������� ����� �������, �������� ���-������ �������� ���.";
		link.l1 = "������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_3");
		NextDiag.TempNode = "second_95";
		break;

		case "second_95":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_95";
		break;

		case "second_96":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, �� ���, �������� ���� �� ���������.";
		link.l1 = "��, �� � ��������, ���������� �������� �������� ��������� ��������� �������, ������� ���� � ����� ����� ������� �������� �������� ������. ��� ������� � ������� �� �������� �� ������, ��� ��� � ����. ����������� ��� � ������ ���� ������, ����� �� ���, ���������� ���� ����� ����� ������ �� �������, �� ��� ������� ���� ��� �����, ���������� �������� ��������� ���� ���� � ��������� ���.";
		link.l1.go = "second_97";
		break;

		case "second_97":
		dialog.text = "�, ������ ������� � ����, ����� ����������.";
		link.l1 = "� ��������� ���.";
		link.l1.go = "second_98";
		break;

		case "second_98":
		dialog.text = "...";
		link.l1 = "������ ���� � ���� � �����, � ���������� ������� ����� �������� �� ������ �������, � ����� �������, ��� � �����, ����, ��� ���������� �� ���� ���� �� ����� ������ �� ������ �����. � ����� ��������� ��� �� ��� ��� ���, ������������ �� ������� ��������, ��� � � ������� ���� ������.";
		link.l1.go = "second_99";
		break;

		case "second_99":
		dialog.text = "��� ���, ���, �������!";
		link.l1 = "��... ������� ������, ��� �� ������, ������ ������, ������ ������ ����� �� ����.";
		link.l1.go = "second_100";
		break;

		case "second_100":
		dialog.text = "���, �������. ������ ��������� ����� �� ����� � ������, ������ ���� ���� ������ ������. �������� ��� �������� ��� ������.";
		link.l1 = "�������, ������� �����, �������� ������������.";
		link.l1.go = "second_101";
		break;

		case "second_101":
		dialog.text = "��� ���������. �� � ��� �� �� ����� ����� ��� � ����� ������� ������� �� ����� '��������� ������', ��� ����� ���������� ������� �������� ��� ��� ��������.";
		link.l1 = "�� ����� ����, ����� ���� ��� ��������, � ���� ������ � ����� �������� ��������� ��� �� � �.";
		link.l1.go = "second_102";
		break;

		case "second_102":
		dialog.text = "������, �������� � ���� �� �����. �� ����� ������������, ��� ��� ������ �������� ����� ��������. ������ ������ � ������� ���������, ������ ���� � ����� �� ������, �� � ������ ������ � ����. � ��� � ��� � ����������. ���� ����������.";
		link.l1 = "�����������, ��� �� ����. �� �������� �� ���, ��� � ��������� ����� ��� ������ ����� ��������� ����, ��� ������������� ��� ����� ���������.";
		link.l1.go = "second_103";
		break;

		case "second_103":
		dialog.text = "�� �����, ��� � �����, �� �������� ����, ���� ��� ����� ����� ����� �� �����, �� ��� ������ ����� ������ �� �������� ��� ������ ��� ������ �������� ���� � �� �� ���� ����...";
		link.l1 = "�� ��, ������� �� ��������.";
		link.l1.go = "second_104";
		break;

		case "second_104":
		dialog.text = "���, ��� � �������, ���� ���� ������� ������� ��� ����� �����, �������� ���� ������� ������� � ��� ������ � �������� ������ � ���� ��� ������.";
		link.l1 = "��, �� �������� ���� ������ ��������� ������ ���� ��� � ��������������� � ������ ��� ���� ��� �������.";
		link.l1.go = "second_105";
		break;

		case "second_105":
		dialog.text = "����� - �������, ��� ������ ����, ������� ������� ��� ����� ����� � �������.";
		link.l1 = "��, ����� �����������...";
		link.l1.go = "second_106";
		break;

		case "second_106":
		dialog.text = "��� �� ����� ����� - �� �� �����... ����� �����������, ����� �� �������������� �������� � �������, �� �� � ������� ������. �������� ����� � ��� ��� �������� ������ ������ � ������� ��� ������.";
		link.l1 = "��� �������, ��� �� ����� ���� ������.";
		link.l1.go = "second_107";
		break;

		case "second_107":
		dialog.text = "�� ����� ��������, �������� ��������, ��� ������� � ����� ��� ������ ������ �� ������. ����� ��������, �������� ����� ����� � ������ �������� �� �����, ��� � ��� ����� �� ����� ����, �����, ��� ��� � ��������.";
		link.l1 = "������, ��������.";
		
	                     AddDialogExitQuestFunction("GothicObsession_MyxirTakeCoin");
		link.l1.go = "second_108";
		break;

		case "second_108":
		dialog.text = "������ ��� ������ ��� ��������� ����� �� �����, ��� ��� ��������� �� ���������, ��� ���� �� �� ����� ����������. �� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_108";
		break;

		case "second_110":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, ���� ������� �� ������.";
		link.l1 = "��, ���� ������, � ������ ���, ���� ���������.";
		link.l1.go = "second_111";
		break;

		case "second_111":
		dialog.text = "�������.";
		link.l1 = "� ���� ��� ���� ��� - ��� �������, ��������.";
		link.l1.go = "second_112";
		break;

		case "second_112":
		if (CheckCharacterItem(pchar, "Obsession_Coins"))
		{
		dialog.text = "�������! ����������...";
		link.l1 = "�������!";
		link.l1.go = "Obsession_complete";	
		}
		else
		{
		dialog.text = "��... �������, �� ����� ������ �� ���� ������.";
		link.l1 = "�������, ��������, � � ��� �� �������...";
		link.l1.go = "Obsession_nics";
		}
		break;

		case "Obsession_complete":
		RemoveItems(PChar, "Obsession_Coins", 1);
		PlaySound("interface\important_item.wav");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 1500000);
		dialog.text = "��� ������ ���������� ����� ������� ���������. ���, ���, ��� ����� ����� ��� ����, ��� �� �� �������, � ����� �� ������ �������� �������\n����� ���������� �����, ����� ��� ������, � ������� ���� �����, ��� �������� ������� �������� ����, ������� �� ����� ����������. �� ������ ���� ���� ����, ��������� � ��������� �������.";
		link.l1 = "��� ��������, ������, ����� ��� ������ ���� �����.";
		link.l1.go = "Exit";	
	                     SetTimerCondition("GothicApostatesAPS_Providence", 0, 0, 60, false);
		NextDiag.TempNode = "second_114";
		break;

		case "second_114":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_114";
		break;

		case "Obsession_nics":
		dialog.text = "� ����� ������ �� �������, � ���, ��� ���� ����� ���� � ����� ��������. �� ������ ���� ���� ����, ��������� � ��������� �������. ����������� ����� ���� �������.";
		link.l1 = "������ �� ����. ����� �������...";
		link.l1.go = "Exit";
	                     SetTimerCondition("GothicApostatesAPS_Providence", 0, 0, 60, false);
		NextDiag.TempNode = "second_113";
		break;
		
		case "second_113":
		dialog.text = ""+pchar.name+" ��������� �����, � �����!";
		link.l1 = "����� ��������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_113";
		break;

		case "second_120":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, ��� ���� ��� �����!";
		link.l1 = "�����������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_4");
		NextDiag.TempNode = "second_121";
		break;

		case "second_121":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_121";
		break;

		case "second_122":
		dialog.text = "������� ������ � ������ ������� �������� ��� ����� ����, ��� ��� �� ��������� �������, �� ������ ����� ����� � �������, �������, ��� ��� �� �� ������, ��������� ���� ���������!";
		link.l1 = "�������� ������! ����, ��� - ������ � ����� ���� �����?";
		link.l1.go = "second_123";
		break;

		case "second_123":
		dialog.text = "��, ����... ������ �� �� ����� - ������ � ���������� ����� ������!";
		link.l1 = "��� �������, �� ������, �������� ��� �� ����.";
		link.l1.go = "second_124";
		break;

		case "second_124":
		dialog.text = "� ������� ������� ��� ������������ �� ����� ����������, � �� ���� ��� ��������, �� ���������� ������ � ��� ������ ��������, ������� �������� �� �������� ���������, ����� �� ����. ��� ����� ���������� ������������� ���� �������, ������� ����� ��������� ������� ������.";
		link.l1 = "�� ������� ��� ����� ���� �����, �� ���� ����������.";
		link.l1.go = "second_125";
		break;

		case "second_125":
		dialog.text = "�����, ��� ��, �� �� ������ ���������. ��� ������ ������, ��������� �� ����������� ��� �����������, �� ��������� ������ ���� ������� ����� - �� ��� ����� ����� ���������, ��������� ����������, �� �� ���� ��������, �� �� ���, ��� - �� ��������, ��� �� ����� �������� ��������� ������, ��� ���������� ����� ������ �����.";
		link.l1 = "������, ����� � ������ ����� ���������� ������ ������!";
		link.l1.go = "second_126";
		break;

		case "second_126":
		dialog.text = "��, ���� �� �������� ������� �� ��� ����, ��� ����� �����, ��� �� ��������������, �������� ��� - ������ �����.";
		link.l1 = "� �� ������, ������ �������, ������ �� ����, ����� � ���� �����.";
		link.l1.go = "second_127";
		break;

		case "second_127":
		dialog.text = "������� ������.";
		link.l1 = "������������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_5");
		NextDiag.TempNode = "second_128";
		break;

		case "second_128":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_128";
		break;

		case "second_130":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� � �� ���������. ����, ���� �������� ����� �� ������� ������-����, ����� �������� ���, ��� ��, ��� � ������, ������ ������ ���������, ��� ���������� ����� ������ ���������� �� ��� ����.";
		link.l1 = "������, ����������� �� ������.";
		link.l1.go = "second_131";
		break;

		case "second_131":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects");
		NextDiag.TempNode = "second_132";
		break;

		case "second_132":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_132";
		break;

		case "second_133":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���������, ����� ��������?";
		link.l1 = "��, ��� ������ ������������.";
		link.l1.go = "second_134";
		break;

		case "second_134":
		RemoveItems(PChar, "architects_table_2", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "�������...";
		link.l1 = "��� �� ���� ������, ��� � ������, �� ��� ����� ����������!";
		link.l1.go = "second_135";
		break;

		case "second_135":
		dialog.text = "��. ������ ������� �� ������� ��������...";
		link.l1 = "�����, ���������� �� ������ ������ ��������.";
		link.l1.go = "second_136";
		break;

		case "second_136":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_2");
		NextDiag.TempNode = "second_137";
		break;

		case "second_137":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_137";
		break;

		case "second_138":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���������, ����� ��������?";
		link.l1 = "��, ��� ������ ���������� � �� �� ���������.";
		link.l1.go = "second_139";
		break;

		case "second_139":
		RemoveItems(PChar, "architects_table_3", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "�������...";
		link.l1 = "��� �� ���� �������, ��� � ������.";
		link.l1.go = "second_140";
		break;

		case "second_140":
		dialog.text = "������ � ������� �� ������� ����-�������...";
		link.l1 = "�����, ���������� �� ������ ������� ��������.";
		link.l1.go = "second_141";
		break;

		case "second_141":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_3");
		NextDiag.TempNode = "second_142";
		break;

		case "second_142":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_142";
		break;

		case "second_143":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���������, ����� ��������?";
		link.l1 = "��, ��� ������ ������������.";
		link.l1.go = "second_144";
		break;

		case "second_144":
		RemoveItems(PChar, "architects_table_4", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "�������...";
		link.l1 = "��� �� ���� ��������, ��� ��� � �����?";
		link.l1.go = "second_145";
		break;

		case "second_145":
		dialog.text = "������ � ������� �� ������� �������...";
		link.l1 = "�������, ������, ���������� �� ������ �������� ��������.";
		link.l1.go = "second_146";
		break;

		case "second_146":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_4");
		NextDiag.TempNode = "second_147";
		break;

		case "second_147":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_147";
		break;

		case "second_148":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���������, ����� ��������?";
		link.l1 = "��, ��� �� � ������ ����.";
		link.l1.go = "second_149";
		break;

		case "second_149":
		RemoveItems(PChar, "architects_table_5", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "�������...";
		link.l1 = "� ���, ��� �� ���� �����, ��� � ������.";
		link.l1.go = "second_150";
		break;

		case "second_150":
		dialog.text = "������ � ������� �� ����� ����� ���������...";
		link.l1 = "�������, ��� � ���������� �� ������ ����� ��������.";
		link.l1.go = "second_151";
		break;

		case "second_151":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_5");
		NextDiag.TempNode = "second_152";
		break;

		case "second_152":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_152";
		break;

		case "second_153":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "��� ������ ���������, ����� ��������?";
		link.l1 = "��, ��� ������ ������������.";
		link.l1.go = "second_154";
		break;

		case "second_154":
		RemoveItems(PChar, "architects_table_6", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "��� ������� � ����� ��� ���� �������� � �������� ����� �� ��������, ���� ���, ��� �������� ��� � ����-��, �� �� �����, ��� ����� �� 5 ��������, ��� � ��� �������...\n�������� ���� �� �����, �������� ��� �������� ��������� � �������� �������. � ����� �� ��� ���� �����, ����������� ����� ��� ����� � ��� ��������, ������� �������� ������� � ���� ����. �� ������ ���� ���� ����, ��������� � ��������� �������.";
		link.l1 = "������ �� ����. ����� �������... ����� ����� ��� ������.";
		link.l1.go = "second_155";
		break;

		case "second_155":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 1250000);
		dialog.text = "�����. ���������. ������, � ������, ��� � ��������� ��������� ����-��� ������� �������, Ҹ���, ���� �������� ��� ������.";
		link.l1 = "�������. �� ����������� ����� � ��� � �����, ��� �� ������ ��� ����������.";
		link.l1.go = "Exit";
                                         // ������ � ������ ���� ������
                                          pchar.questTemp.GothicSmithy = "SagittaAnn";
	                     AddQuestRecord("Architects", "6");
                                          CloseQuestHeader("Architects");
	                     SetTimerCondition("GothicApostatesAPS_Providence_2", 0, 0, 50, false);
		NextDiag.TempNode = "second_156";
		break;

		case "second_156":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_156";
		break;

		case "second_160":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, ��� ���� ��� �����!";
		link.l1 = "����������, ��� ����� ����� ����, ��� ������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_7");
		NextDiag.TempNode = "second_161";
		break;

		case "second_161":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_161";
		break;

		case "second_162":
		dialog.text = "��� � � �������, ������� ��������� � ���������� ����� ������� ����������� �� ����������, ����� �������� ������� �������...";
		link.l1 = "��, ����� �������������� ������ �������������, �������, �������� ������!";
		link.l1.go = "second_163_b";
		break;
		
		case "second_163_b":
		dialog.text = "...";
		link.l1 = "�������, ��� ����� ����...";
		link.l1.go = "second_163";
		break;

		case "second_163":
		if (CheckCharacterItem(pchar, "architects_table_8"))
		{
		dialog.text = "� ������.";
		link.l1 = "� ����� ��� �������� ��������, ����� ���� ��� ������������. �� ��� �������� � ������ ���� � � ����� - �� ���� � ���������.";
		link.l1.go = "Quarhodron_complete";	
		}
		else
		{
		dialog.text = "� ������.";
		link.l1 = "�������, ��������, � �� ���� �� ���� ��������...";
		link.l1.go = "second_nics";
		}
		break;

		case "second_nics":
		dialog.text = "��, ���� ���...";
		link.l1 = "��������� � ��������� ���, ����� ���������� �� ������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_8");
		NextDiag.TempNode = "second_164";
		break;

		case "second_164":
		dialog.text = "��������� ��������� �����, ������ ���� ���� ����, ��������� � ��������� �������.";
		link.l1 = "�����. ������ �� ����. ����� �������...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_164";
		break;

		case "Quarhodron_complete":
		dialog.text = "������ ��� �� ��� ��� � �����, �������� ����������� �� ��������, �� � ������ �������, ���, ��� �������� ������ � ���� ������� ��� ������ � � ��������������, �������� �� ������������...";
		link.l1 = "�� ������� ��� ��������, ����� � ��� �����, �� ��� ��� �� ����� �������� �� �����...";
		link.l1.go = "Quarhodron_complete_1";
		break;

		case "Quarhodron_complete_1":
		dialog.text = "����� � ���� �� ���� ����� ������, ��������� ������������ ���������� � ����, ��� ����� �������...";
		link.l1 = "�������, �� ����� �����, ����� ���������� �� ������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_164";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_Quarhodron_Myxir");
		break;

		case "second_165":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "������� ������ � ������ ������� ���������� ��� ����� ����, ������� ����������. ��� ������ ���� ���������.";
		link.l1 = "����������� �������, �� �� ���� ��� ����� ������� ��� ������ �������. ���� ������ ��� ���� ��� �������� ������ ����.";
		link.l1.go = "second_166";
		break;

		case "second_166":
		dialog.text = "���� ������ ���, �� �� ������ ������������ � ����� �������, ���� ��� ������, ��� ���������� ���� ��� ������ ���� ������, ��� �� ���������� � ���� ��������. �������� ����� ����� ����� �����, �������� ���� � ������� ����� ���������� ����, � ������ ���� ���� ������� � �����������.";
		link.l1 = "�������, ������������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_10");
		NextDiag.TempNode = "second_167";
		break;

		case "second_167":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_167";
		break;

		case "second_168":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "...";
		link.l1 = "�������, � ������� ��������� �������� � ����� ���������, �������, ��� ������� ������ � ��������� ������.";
		link.l1.go = "second_169";
		break;

		case "second_169":
		dialog.text = "��� �� �����!";
		link.l1 = "� ���������� �� ����� - �� �� ��������. ������ ���� ����� �������� ���� ����� ����� ��� �������. ��� �� ��� ������� �����, ������ ����� �����, ������ ���� ���������.";
		link.l1.go = "second_170";
		break;

		case "second_170":
		RemoveItems(PChar, "map_part1", 1);
		dialog.text = "��������� ������ �������, ������, ����� ���������, ����� � ��� � �����. ���� ��� ��������,��� ��� ����������. ���� ������ �� �� ������� ������� � ��!";
		link.l1 = "��� ����� ������!";
		link.l1.go = "second_171";
		break;

		case "second_171":
		dialog.text = "� ���� ��� �����, �� ��������� � ���� ������ ������ � �������� � ������������� �����!";
		link.l1 = "������.";
		link.l1.go = "second_172";
		break;

		case "second_172":
		LAi_Fade("", "");
		dialog.text = "...";
		link.l1 = "�������, ��� ������ �������, ������!";
		link.l1.go = "second_173";
		break;

		case "second_173":
		dialog.text = "���������, ������������� ������ ������, �� ��� ������������� �������� ������, ������ �����, ��� ����� ��������, ��� �� ��� ��� �� ���� ��� ������ �� ���������. ���, ���, ��� ����� ����� �������, ����� ������ �������� �����. ���� ���� �����. ��� ������ ������ ��������, �������. ����� � ����� ������ ������� ����� �������, � ���� ��������� � ������� � ���� ���� �� �� ������.";
		link.l1 = "�� ������. �������� ����� ������ ����� ��������� �����������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_13");
		NextDiag.TempNode = "second_174";
		break;

		case "second_174":
		dialog.text = "�� �������� � ����� ����, ���������. ���� ��� ��������,��� ��� ����������. ���� ������ �� �� ������� ������� � ��.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_174";
		break;

		case "second_175":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "...";
		link.l1 = "������ ����� ����� �������, ��� ������ ������� �������!";
		link.l1.go = "second_176";
		break;

		case "second_176":
		dialog.text = "�������, ����� ���������.";
		link.l1 = "�����.";
		link.l1.go = "second_177";
		break;

		case "second_177":
		RemoveItems(PChar, "map_part2", 1);
		dialog.text = "�������, ����� �������. �������...";
		link.l1 = "...";
		link.l1.go = "second_178";
		break;

		case "second_178":
		LAi_Fade("", "");
		dialog.text = "...";
		link.l1 = "��, ��� �������, �������, ��� ������ �������, ������!";
		link.l1.go = "second_179";
		break;

		case "second_179":
		dialog.text = "��, �� ������ ���� ������������, ����� ���������.";
		link.l1 = "��� ���, ������ � ������ ���! � ��� ��� �������� ��������.";
		link.l1.go = "second_200";
		break;

		case "second_200":
		dialog.text = "������ ����, �� ��� ��� ��������� ��� �����, ������ ��� ���������������, ��� �� ������� ����������� �� ������� ����.";
		link.l1 = "��������, ������ � ����������� ���.";
		link.l1.go = "second_201";
		break;

		case "second_201":
		dialog.text = "...";
		link.l1 = "��������� �������, ������� �������. ��� - ������ ��� ������� �������?";
		link.l1.go = "second_202";
		break;

		case "second_202":
		dialog.text = "��, ���������, ������ ���������� ������, ��� �������� ������ ������� ��� ������ �������, ������������� � ������, ���� ���� ���������� �������.";
		link.l1 = "��� ��� ������ ������ �� ��� ��� �� ���� �����. ��� ��� �� ������!";
		link.l1.go = "second_203";
		break;

		case "second_203":
		dialog.text = "�� �������� ���� ������ ������ � ����� ���������� ���� ����� � �����, ��������� ���������, ���� � ����� ������� ����� - ������. ������� ������� ���������, �����, �������, ������� ���� � ����� �������... � ����� ������ ������ ������ � ������. �� ������� ����������� � ������ ������� ��� ������� ������� �� �����, ���������.";
		link.l1 = "��� �, �������, ���������� ����� ������, �� �� �� ������ � ����� ����.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_19");
		NextDiag.TempNode = "second_204";
		break;

		case "second_204":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_204";
		break;


		case "second_205":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������. ����� ������� �� ���� ���.";
		link.l1 = "�������, � ���� ��� ����������, ������� ��� ��� ������ ������������. ������ ������� � ����!";
		link.l1.go = "second_206";
		link.l2 = "�������, �������� ������� � ������������ ���, �� ��� ������� � ��������� ������ ������� ������������ � ������ �����, �������� ����� �� �������� � ���������� �����. ���� ������� ��������� �� ���� ��� ���������!";
		link.l2.go = "second_0206";
		break;

		case "second_206":
		dialog.text = "�������, ������ �� ������ ��������, ��������...";
		link.l1 = "��, �������, ��� ��� � ����, � ���� �������, �������� �����, �������� � ��������, ������� ���������� �� ��� � �������� ����������. ���� ����� ������ ��������� ������� ��� ��� ����� ���� ������� �����. �� ��������� ����������, ������ ��������� ���������� � ������ - ��� �� ���, ���� ���� �� ������� ������ � ������ �������� ��������� ��� ����� ������, �� ����� ������ ������������ - ������ � �����������, � ����� ������� ����� ��-�� ������� ���������� - ��������� ���������� ������� ������� �����. ���� ������ ��������� ���������� ������, � ��������� ����� ������� �� ���� ��������.";
		link.l1.go = "second_207";
		break;

		case "second_207":
		dialog.text = "��� ���������.";
		link.l1 = "��, ��, �� �� �����, ������� ��� ����� ���� ����� �������, ����� ������ �� �������� ���������.";
		link.l1.go = "second_208";
		break;

		case "second_208":
		dialog.text = "�������, ����� ���������!";
	                      if(sti(pchar.money) >= 9090900)
		{
		link.l1 = "����� �������� �� ����� �����.";
		link.l1.go = "second_money";
		}
		link.l2 = "׸�� � ���� �� ���������� ����, ����� ����� �� ��������� �������, ��� ����� �������� ������ ����� �� ���� � � ����� �� � ���.";
		link.l2.go = "second_money_1";
		break;

       	                   case "second_money_1":
		dialog.text = "�� �������� ���������, � �������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_208";
		break;

		case "second_money":
		LAi_Fade("", "");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneyToCharacter(pchar, -9090900);
		dialog.text = "���...�������� ������� � ������������. �� � ������, ���� �� ���� �� �������� ������ ����. �����, ����� ���� ������� ������������� ����� ��������� ���������.";
		link.l1 = "�� ���� ������. ����� ��� ������, �������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_30");
		NextDiag.TempNode = "second_209";
		break;

		case "second_209":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_209";
		break;

		case "second_0206":
		dialog.text = "��...�������. ������ ���������, ����� ����� ���.";
		link.l1 = "���� ������ ��� ����.";
		link.l1.go = "second_0207";
		break;

		case "second_0207":
		dialog.text = "������ ���� ���.";
		link.l1 = "����, ��, ����� � �����.";
		link.l1.go = "second_0208";
		break;

		case "second_0208":
		dialog.text = "�����, ����������, �������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_030");
		NextDiag.TempNode = "second_0209";
		break;

		case "second_0209":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_0209";
		break;

		case "second_210":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, ��� ���� ��� �����! ���� ������, ������������ ���� �������.";
		link.l1 = "�������, ��� ������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_31");
		NextDiag.TempNode = "second_211";
		break;

		case "second_211":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_211";
		break;
		
		case "second_212":
		dialog.text = "��� � � ������, ������� �� ����� ������� ������, ������� �� ��������, ������������, ����� ����� ����� �� ��������� ��� �� ��� �����, ��� � ����-�����, �������, ������� ���������� ����...";
		link.l1 = "��, ���� � ��� ��� �����, ��� � ���� �������, �������...";
		link.l1.go = "second_213";
		break;
		
		case "second_213":
		dialog.text = "� ���������, ������ ��� ���� ���� ���, �� �� ��������� ����� �� �������, ����� ����, ���-�� �� ��������.";
		link.l1 = "����, ��� ������ ������ ���. ����� �� �������, �������.";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_After3_Building");
		NextDiag.TempNode = "second_229";
		break;
		/*
		case "second_212":
		dialog.text = "��� � � ������, ������� �� ����� ������� ������, ������� �� ��������, ������������, ����� ����� ����� �� ��������� ��� �� ��� �����, ��� � ����-�����, �������, ������� ���������� ����... �� �� �� ���� ����� ����.";
		link.l1 = "��, ���� � ��� ��� �����, ��� � ���� �������, �������... �, ���, � ��� ����� ����, �������.";
		link.l1.go = "second_213";
		break;
		*/
		/*
		case "second_213":
		dialog.text = "� ������� ������ �� �������.";
		link.l1 = "�� ���� ������, ������� ����� � ������.";
		link.l1.go = "second_214";
		break;
		*/

		case "second_214":
		dialog.text = "��, �� ����. �� � ����� ������ ��� �������� ������!";
		link.l1 = "���, �� �����������.";
		link.l1.go = "second_215";
		break;

		case "second_215":
		dialog.text = "�� �������� ������� ������, ����� ������� �� ���� ������� �� �������, �������� � ������������� ��� ��� ����� �� �����, ��� ��� ��� � ���� �����, �� �������� ���������� �� ������ �� ���������� �� � �� ���������, �������, ���������� ��������� ������ � ���� �������, ��� �� ��������, ��� ����� �������� ����� �������� ��� �������!";
		link.l1 = "�������, ��� �� ������� ��� �������?";
		link.l1.go = "second_216";
		break;

		case "second_216":
		dialog.text = "���� ����� � ������� � ���������. � ��� �� ������ ���� � ���� ����� � �������, ��� ��������� ���������� �� ������ �������, �� �� ������������� � ��������.";
		link.l1 = "��... ������, � ������.";
		link.l1.go = "second_217";
		break;

		case "second_217":
		dialog.text = "�, ��� � ����. ������� �������� � �������� ��������. ������� �������� � ������ ��������, ����� ��������� �� ������������� ��������� ������\n� ��� 1861 ���� ��������� ������ ����� ����� ����������� ������ �� ���� ������ ������� ��������� ����� ������������ �� ����� ���������� �������� '��������'\n�� ������� ������ ������������ ���������� � ������ ����. � ������ ����� �������� ��������� ����� '��������' ������� ����������� �������\n��������� ������� ������� ���������� '��������' �� ����, ������� ��������� �������� ��� ����� ���� � ������� �����. �������� ����� �������� �����������, ����� ������������ ���\n����� � ����, �������� ���������� � ������ ��������, �������� ��� �� ���. ��������� ���� ��� ���������� ��������� � �������������, �������� ����� ����������� ��������� � ����-������ �� ������������ ����\n����� �������� ����� '��������' ���� �� ���� ������ ������� ���� ������, �������� ���������, ��� ����� ���������� ������� ���� ������� � �������� ��� ����������� ��� ��������. ���� ��� ����������� � ����������, ������������ ���� ������ ���� � ���������.";
		link.l1 = "�� � ���, ��� ������, �������� ��������, �� �� ��������� ������ ��������� ���������.";
		link.l1.go = "second_218";
		break;

		case "second_218":
		dialog.text = "�� � ���� ����. ���������� '��������' ���������� �� ��� � ����, ���� � 1872 ���� �� ��������� ����������� �������. ����� �������� ������ ������ � ��������� ���������������� �� 84 ����. ���������� ���������� ������������ � ����� �������. ������ ��� ������������ ������ � ����� ������ ���������� '��������' ������������� � '���� �������' ��� � ���������� ������� � ������� ������� � ����� �������� ��������� ��������� ����� ������������ ������.";
		link.l1 = "��� ��������� � ��� �� ������ � �� �����.";
		link.l1.go = "second_219";
		break;

		case "second_219":
		dialog.text = "������ ����������� ����������� ����������� ������ '���� �������' �������� 7 ������ 1872 ����. �� ����� �������� ���� ������� ��������� �����, 38-������ ������� ���� ������������� ����� �� ����� �����������\n�� ��� ����� �� ������� ����������� �����, �������, �� ��������� �������. ��� ���� ���� � ���������� ������� ���� ������������ ��� � ���� ��������. ������ ����� �������� ��������� ����������� ����� ���� ����������� � ���� ������� �������� � ��������� ����������, ����� �� ������� � ����\n������� �������� �� ���� ������������ � �������� �������, ������� ����� �������� ���� � ����������. ����� ���������� 1700 ������� � ������������ ��������� � ���� �����, ������. ��� � ��� ���������� �������� ��������� ����� ��� ������� ������, �� ������ ���� �������� � �� ��������������\n����� ���-�� ��������� ����� 25 ������ 1872 ����, ����� ���� ������� ��������� ������ � �������. ������ ���� ������ ���������� '���� �������' ���� ������� ���������� � 378 ����� � ������� �� ������� �����-����� ��� ������ ���� �� �����...";
		link.l1 = "...";
		link.l1.go = "second_220";
		break;

		case "second_220":
		dialog.text = "���������� '���� �������' ���� ���������. ��� ��������� �� ��, ��� ������� �������� ����� � ������. ��������� �����, �������, ������������� ������� �������, �� ����� � ����������� ������, ������������� �������, ���� ��������� ������� �����\n������ ���� ������, ��� ����� ���������, ����� �����������. ��� ������, ������� � ����, ���� �������, � ��� ����� � ����������� �����������. ����, ��������� �� �����, ��� �� ����� � ���� � ������� ���������\n����� �� ��������� �� ���������� ����.
��������� ����� ��� ������������ �������, �� ��� �� �������� ��� �������� ����������� �������� �����, ������ ������ ����, ������� � ������� � ��������� � ��������� ������ ����� �������� ����....";
		link.l1 = "������������� �������.";
		link.l1.go = "second_221";
		break;

		case "second_221":
		dialog.text = "����� ���� �������� ����� ���� �����...����� �� � ��� ���� ������ ������� � ������ ��������� ����� '���� ���� ������'. �������� ��������� ���������� '���� �������' ���� ������� ������� �������� �� � ������ ���������. ����� ���������� ������� ��� ��������� � ����������� �����, ������� ��������� ����� �� �������������� �� ��������� ���������.";
		link.l1 = "�������, ��������� �������, �����������, ��� ��������� � ������ ����� ��������.";
		link.l1.go = "second_222";
		break;

		case "second_222":
		dialog.text = "����� ���� ��������� ��������. ��������� �������������� ����� ���� ������� ������� � �������� ���������. �� ��� �������, ��� �������� ������������ ������� ���� ������������\n�� �������� ������ � ���, ��� ������� ��������� �������� � � ��������� ������������ ��������� ����� �������� � ��� �����\n� ����� ������, ��� ������ ��� ��������� � ���� ���������� � �������� � ��� �������. �������� �� ��� ��� ��������� ����� 1700 ��������, ��� ��������� ������ �������� ����������� �������������� �� ����� �������. �� ������ ��������� ������� ���, �� ����� �������� �������.";
		link.l1 = "�� � ����, �������� � �������.";
		link.l1.go = "second_223";
		break;

		case "second_223":
		dialog.text = "����������� ���������� ��� �������� ����� '���� �������' �������� ���������� ������, �� ������� ����� ������� ���������� ������ ������� � ���������� ��������� � ����������\n
� ����� ������, ����� ������������ � �������� ���������, � ��������� ���� ������ ����� ��������� �������. � ����� 1884 ���� ������������ ���������� �������� ���������� '���� �������' �� ���������� ������ ����, � ���������� ��� ��� �������� �� ������� � ������ ����, �����, ��������� � ������� ���������� �������� � ���� �� ������ �����\n��� � ���� ��������� ������������ ���������. �������� ���� ������� ���������� '���� �������' ������������ ������������� ����������� ������������ �� ����� � 25000 �������� ����� ������� ���������� �������������\n
����� �������� ������� ������ ������� �����, ������ ����� ������. �� ���� ��� ������� �����. ������� �������� �������� ���������� '���� �������' �� ���� �� ����. ��� ������ ����� ���� �� ���� ������� ������ �������� ������� ������ �����. ����� ������ ��������� �� �����, ��� ����� ���� �������. ���������� ��������, ��� ��� ���� ��������� �����\n
������ ��������� ����� '���� �������' ���� ������� ����������� ������ �������� �������. ������� ����������� ������ ���������, ��� ���������� ����� ���� ����������. ������ ������� ���� ��������� �����, � ������ � �������� ���������� ������� ������� ��������\n����� ��� ����� ������ � ������� ����������. ������� � ���������������� ���� �������� � ������ �������, � ������ � ���������� ���������� ����� ����� - � ������������, �� ������� �  ������������� � �������� �����. �� �������� ��������������� �������� ���� �������������� � ��� ������ ��������������\n������ ���������������� �������� ���� ���� � ���������� �����, � ��� ��������� ���� ��������� � �������� � �� ��� ����������. �� ����� ��������� ������� ������� � ������� �������� ������������� ������, � ����������� �������������, ��� ����� ��������� �������-�������� '���� �������' ������������ ��� ����� ����, ��� �� ���������� ���� ����� � ������� �����.";
		link.l1 = "��, �, � ���� ���� ������� �������.";
		link.l1.go = "second_224";
		break;

		case "second_224":
		dialog.text = "������, ��� �� ���������, ��� ������� � ������� �� ����� ������, ������ �� ��������� ������� � ��������� � ����� ������� � ��������� ��������, ��� ���������� � ���� �������, ��� ������� �� ����� ������.";
		link.l1 = "�� ���� ������ �������, �� ����� ����������� ����� ���� ����� � ��������, ��� �� ����� ���� ���������.";
		link.l1.go = "second_225";
		break;

		case "second_225":
		dialog.text = "��������� �������, ������ ������� � ��������� ���������� ���� ���������� ���������� �����������, ���� �� ��� ���� � ������� ���������� ��� ����������������, �� ����� ���������� ���\n���� ���� ������� ����� ������ �� ������ �������, ��� �������� ��� ��������, ������� ��������� �����, ��� ��� ���� ���� �����, ������� �� �� ���, � �������� ���������� � ���� ����� ������������� ����� � ����� ��������, ��� ��� � ��� ��������� �� �����.";
		link.l1 = "������, �� �� ������, ���� ������, ����� � �������� �� � ��� �������.";
		link.l1.go = "second_226";
		break;

		case "second_226":
		dialog.text = "�����. ���������.";
		link.l1 = "�������.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste");
		NextDiag.TempNode = "second_227";
		break;

		case "second_227":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_227";
		break;

		case "second_228":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "����������� ���� ���������, � �� ������, �� �������, ��� ��� ������� �� ����� ����.";
		link.l1 = "�� ��������� �������, ��� �����, ���� �������� ���������� �����.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_6");
		NextDiag.TempNode = "second_229";
		break;
		
		
			
		case "second_229":
		dialog.text = "�� �������� � ����� ����, ���������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_229";
		break;





























































//********************* ����� �����*****************************

                        case "First time4":
                        dialog.text = "������ � �����, � ����� ��������� �����, " + GetSexPhrase("���","����") + " ��" + GetSexPhrase("�","�") + ".";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "First time4";
                        break;

	case "APS_Benua":
	dialog.text = "� ��� ��� �� ����� ����� �������?";
	link.l1 = "�, ���� ��������������. ������� � �� �������, ��� �� ������ ��� �������� ����������!";
	link.l1.go = "APS_Benua_1";
	break;
				
	case "APS_Benua_1":
	dialog.text = "����� ��" + GetSexPhrase("���","�") + " ��������" + GetSexPhrase("��","��") + ". �������� ������� ����� ���" + GetSexPhrase("��","�") + " ���������" + GetSexPhrase("�","�") + "!";
	link.l1 = "...";
	link.l1.go = "Exit";
	NextDiag.TempNode = "First time4";
	break;


//********************* ������ �������*****************************

	case "ApostatesNI":
	dialog.text = "...";
	link.l1 = "��� ��� ��� �������� �������� � ��������e ��������... ������ �� ����������� �� ����, � ����� ����� ���������� ��������� ����.";
	link.l1.go = "ApostatesNI_1";
	break;
		
                     case "ApostatesNI_1":
	dialog.text = "������ �� � ���� ����������� � ��������! � ����� ����! ��� �� �������" + GetSexPhrase("","�") + " �� ���� � ��������� � ���-�����.";
	link.l1 = "...";
	link.l1.go = "Exit";
	NextDiag.TempNode = "ApostatesNI_2";
	break;
		
	case "ApostatesNI_2":
	dialog.text = "���, � ������, ���� �����, ���� �� ������?";
	link.l1 = "��� ����� �� ���� ������ �� ����, � ��� ����, ��� ������� �� ����� �������, ����� ������ � ����� ����������.";
	link.l1.go = "Exit";
	break;
		
	case "ApostatesNI_3":
	dialog.text = "�� �����, ��� �� ���" + GetSexPhrase("��","��") + " �������" + GetSexPhrase("��","��") + ", �������.";
	link.l1 = "�� � � �� �����" + GetSexPhrase("","�") + " ���� ��������� � ������ �������, �������.";
	link.l1.go = "ApostatesNI_4";
	break;
		
	case "ApostatesNI_4":
	dialog.text = "������ ����� ��������� ���� �������, �������, �� �������" + GetSexPhrase("��","���") + " ����� �������?";
	link.l1 = "�� ���� �� ���������, ����� �� ���� ����� ������������, ����� � ����� ������� ���� ��� �� ����.";
	link.l1.go = "ApostatesNI_5";
	break;
		
	case "ApostatesNI_5":
	dialog.text = "��, ���� �� ��� ����� ��� ������ �� �����.";
	link.l1 = "...";
	link.l1.go = "Exit";
	break;

//********************* ���� ������ �������*****************************

	case "Mason":
	dialog.text = "�, �������, ��, �������, ������� �������!";
	link.l1 = "��, ����, ��� ������� �������! ���" + GetSexPhrase("","�") + " �� � ���� ��������, ���� �� ����� ��� ������ ��������� �� ���� ���. ���� ��� ���������...";
	link.l1.go = "Mason_1";
	break;
		
	case "Mason_1":
	dialog.text = "������, �������, �� �� �������, �����, ��� ������ � ��� ��������� ����������.";
	link.l1 = "�����. ��� ������ � ���� ������� �����?";
	link.l1.go = "Mason_2";
	break;
		
	case "Mason_2":
	dialog.text = "�������, �� �������� ��������, �� ��� �������� � ����, ���� �� ���� ������ ������� � ��������.";
	link.l1 = "������, ������ ��� ��� ����� ������.";
	link.l1.go = "Exit";
	AddDialogExitQuest("GothicApostates_APS_dialog7");
	break;







//*********************������*****************************

		case "usurerSavLaMar":
		dialog.text = "...";
		link.l1 = "� ���� ������������, � ����� �������� ����� �����!";
		link.l1.go = "usurerSavLaMar_1";
		break;

		case "usurerSavLaMar_1":
		dialog.text = "�� ���� ��������, ��� �� ���������� ���� ���������, ������ � ��������� ������ ������� � �� � ��� �� �������.";
		link.l1 = "����� ���������� �� ���� ����� ����� �� ������ �� ���, ������ ����?";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostatesAPS_BankSavLaMar");
		break;


//********************* ����� ����� ����*****************************

//********************* ���� ����*****************************

		case "GregSnow":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_7.wav");
		dialog.text = "����, �������! �� ������ �� �������� ������ ������� �������?";
		link.l1 = "�������... ����������! ��� ������ �����, �� ���������!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneTalkWithSnow");
		break;
		
		case "GregSnow_1":
		dialog.text = "��, �������, ����� ��� ��� ������� ����� � ���� ���������, � ������� ����������� �� ����� �����... ������� �����, �� ������� ���� ������� ����� - � ����, ��� �� ���-�� ������ ���������.";
		link.l1 = "��������" + GetSexPhrase("","�") + ". ��, �������, ����� � ��� �������. �������� ����� ���� �� ������� ���� �����������.";
		link.l1.go = "GregSnow_2";
		break;
		
		case "GregSnow_2":
		dialog.text = "���... ������, �� �������� � ����� �����. ���� ����� ������ � ������� �� ����!";
		link.l1 = "�����, �������� - �� ���������� �� ���� ������� � ���-������ �� ���, ��� ���� ����� ��� �����?";
		link.l1.go = "GregSnow_3";
		break;
		
		case "GregSnow_3":
		dialog.text = "�������, ��� ����� ��� ������.";
		link.l1 = "����������, ��� ��� ������ �����!";
		link.l1.go = "GregSnow_4";
		break;
		
		case "GregSnow_4":
		LAi_Fade("", "");
		dialog.text = "��� ���� ��� ���������, �������. �� ������������ ��� ����� �������� ���� ����� �� ��������...";
		link.l1 = "��� ��� �����, ��� ���� �������� ��������� ����� ����!";
		link.l1.go = "GregSnow_5";
		break;
		
		case "GregSnow_5":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_11.wav");
		dialog.text = "������-�� � ���� ����, �������. ��� � ����, � �������� ���� ���-���. ���� ��� ��������, ������ �����, ������ ����� ��� �� ����, ��� �� ��������� ����� � ������ ������. �������, ��� ���, ��� � ���� ���� ����������.";
		link.l1 = "�� ��� ��� ����� ���?";
		link.l1.go = "GregSnow_6";
		break;
		
		case "GregSnow_6":
		dialog.text = "��-��. �� �����, �� ��� �� � ������ � ���� ������! � ������, ��� �� ����� �� ����� '������', ������� �� �� ���������� ���...";
		link.l1 = "�������, �������. � �������� ��� �����������.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneTalkWithSnowEnd");
		break;

//*********************������ �'�����*****************************
		
		case "GarrisOMayli":
		dialog.text = "����������� ���. ��� ����� ��������� ��� ��������� ������ ��������� ��������, ��� �?";
		link.l1 = "���� �� ���� � ���� ������... � ����" + GetSexPhrase("��","��") + " ���������� � ���� � ����� �����... �� ������, ��� �� ��� ������, �� ������� ��� ����, ������ - ��, ��� �� ���� ��������, ������������ ������� ������� ����� � ��������. ����� ����������� �������� ���������� � ���������� �������� �������� ������� ������. �� ������ ������ ��������, �������, � ���������, �������� � �����, ��� ��������� �������� ����� ������.";
		link.l1.go = "GarrisOMayli_1";	
		break;
		
		case "GarrisOMayli_1":
		dialog.text = "�, ���� ���, � ����, ��� ���� ����� ���������!";
		link.l1 = "�� ���-�� ������! ����� ���, ���������� ��� ��. ���� ���� � ������ �����!";
		link.l1.go = "GarrisOMayli_2";
		break;
		
		case "GarrisOMayli_2":
		dialog.text = "��, � �������� ��� ��, ��� ��� ��������. �� ���� ��������� ������, ������ �'����� - ��� ������� ���, �� �����-�� � ����� ��� - � �� ������� ����� �� ��� �������� �� ���.";
		link.l1 = "�������� ��, ���� ����� �������!";
		link.l1.go = "GarrisOMayli_3";
		break;
		
		case "GarrisOMayli_3":
		dialog.text = "��� ������� �� ��� ��� ������ ����. �� ������, ����� ������� ��������� ��� �������� ������� ��� ��� ����� ������ �������������, ������ ��������� �������� � ����� ��� ����. ������, ��� ��������� � � ����� ������. � �� ������� ������ � ������������, �� ��, ��� � ������� �� �����\n� ��, ��� �� ��� ������ ����������. ����� ��������� ���, ��� ��� ����� ������������ ������� ���� ������� - �� ��������� ������ �����, ����������� ��������� ��� �� ����. �� ����� �� ��� �� ����� ���������� - �� ��� �� ��������� �� ��� �� �������, �� � ��� � �� ���� ��� ������.";
		link.l1 = "��� ��� �� ����������� ���?";
		link.l1.go = "GarrisOMayli_4";
		break;
		
		case "GarrisOMayli_4":
		dialog.text = "����� ������� ���, ��� ����� �� �������� ���������� ��� ������� � �������, � ������� ��� ����� �����������. ��� ����������� ���������, ���� �� ���, ����������� ������������� � '���'...";
		link.l1 = "� ��� �� ��������?";
		link.l1.go = "GarrisOMayli_5";
		break;
		
		case "GarrisOMayli_5":
		dialog.text = "� �� ���� ����������� ��� �����. ��� ���� ��� - ������� ���. ���� ��� ����� ������� ��� ������ ���� �� ����� ����, ������, ��� ������� �� �� ��� - ������� ������� � '���'. ��� �����-�� ������������! ���� ������� ��� � �����-�� ������� �������� �������� ������� ����� � ����� �� �������� ����������, ����� ���� � ����� ��������� ������� ������� � ������ ��� ������ � �����������. �� ����� ��� ���� ��������...";
		link.l1 = "������, ��� �� ���� ������?";
		link.l1.go = "GarrisOMayli_6";
		break;
		
		case "GarrisOMayli_6":
		dialog.text = "������... ������ ����� �������� �����, �� ������� ��������� ��� ���������� ����������. �� �������� ����� ������ ����, �� ������� ������ ��� '��' � �������� �������������� �� ��� ����������. ����� ������� �����, ��� ����� ��� ����� ��� ������, �� ��� �������� � ��� ���� �� �����-�� �����, ����� ��������� �� ����� �����-�� ����, � ����� �� ������ ����� �����������. � ������� �����, ��� ��� ����� ���� ������ �������, �� �� ��� �� ��� ��������������.";
		link.l1 = "������������� �� ������, ����� ���!";
		link.l1.go = "GarrisOMayli_7";
		break;
		
		case "GarrisOMayli_7":
		dialog.text = "����� � ��������� ������ ��������� �������� ��������� - �� ���� ����������. ��� ����� - � �� ��� ��� �� ���� ������ ���� ������ - ��� ��� ������ �� �����������. � ������� �� ������ �� �������, � ������� ����������� ���� ����� ����� ���� � �������� ������� ��� �������� - �� ���� ������ ���-�� ����������\n� ��������� �������� ��� �������. ���� �������� ����� �������� �������������� ������� - �� �������� ������. ��� ���������� ���� ������� ������� � ������. ����� ���� ����� ����������� � ����� ����. ������ � ��� �� �����. �������� �������� � �� ��� ��� ����� � ����.";
		link.l1 = "������ � �������, � ��� ��� ��������� �����������. ���� ������� �� ����������� ��� � ���, ��� �� �������� ���������� ��� �����?";
		link.l1.go = "GarrisOMayli_8";
		break;
		
		case "GarrisOMayli_8":
		dialog.text = "���, �� ���� ��� ������ �� ��������.";
		link.l1 = "� ����� ������, � ����� ��� ������ ��� ��� ��������. � �����" + GetSexPhrase("��","��") + " ��������, ��� ������ � ��� ������� ��� ������� ���������� �������� ����� �����, ������...";
		link.l1.go = "GarrisOMayli_9";
		break;
		
		case "GarrisOMayli_9":
		GiveItem2Character(pchar, "architects_table_7");
		Log_Info("�� �������� �������� ��������");
		PlaySound("interface\important_item.wav");
		dialog.text = "� �������, � ��� �� ������ �������. ������� - �� �������� � ���� �������!";
		link.l1 = "��������.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneFindRobertBlake");
		break;

//*********************������ �����*****************************

		case "RobertBlake":
	                     PlaySound("VOICE\Russian\pirat_common_3.wav");
		dialog.text = "����! ������ ����� �� ��������� ��� �������?";
		link.l1 = "��������. � � ����� ������ ����� ����������, �� �� ����� ������ ������ �� ����� �������.";
		link.l1.go = "RobertBlake_1";			
		break;
		
		case "RobertBlake_1":
		dialog.text = "��� ����, ��� � � ��������, ������ ���� �� ������, ��� �� � ����� ����� ����� �� ������...";
		link.l1 = "���������...��� ����� ������ ���, ��� � ��, �� ���� ����� ��������� ��� ��� ������������� ����� ����� �� ��� ��?";
		link.l1.go = "RobertBlake_2";			
		break;
		
		case "RobertBlake_2":
		dialog.text = "����� ����... ���� ����. �� ����� ���� ���������� ����������? �������, ��� ���� ���� �� �������� ������ �������� - ��� ��������� ������! ����������� ���������� ����������.";
		link.l1 = "� ���� � ��� ������. ����� ���, ���� �� � ����� �����-�� ���� ������� �����, ������� �� ����� �������, �� ���� ��� �� ������ �������.";
		link.l1.go = "RobertBlake_3";			
		break;

		case "RobertBlake_3":
		dialog.text = "��, " + GetSexPhrase("������","��������") + "! �� ���, ������" + GetSexPhrase("��","���") + " �������� ������������������?! �����, ��� �� ����� �� �� ��� �������. ��� ������� �������� ����� ����� ������ �� ��� �������, � ��� ����� � � - ���� �� �� ������� ��� ���-������, ����� �������� � ������ �����.";
		link.l1 = "������� ��������, �� ��������?";
		link.l1.go = "RobertBlake_4";			
		break;

		case "RobertBlake_4":
		dialog.text = "��, ���� � ���� ���� �������� - �� ����, ��� ��� ��� ��� ������������ - ��� ������ ������ ����. �� ���, ��� ����� ����������� �� �����, ��� �������� ��� �����.";
		link.l1 = "��� ����� �����, ��� ��� �� �����.";
		link.l1.go = "RobertBlake_5";			
		break;

		case "RobertBlake_5":
		dialog.text = "��� ����� ����� ����� ��������� ����� ����-�������� ��� ��� ���� ������ ����������� �������, �� ������ ������� ���� ��� ������� �����-�� �����, ��� ��� ���� � ����������� �� ����, ��������� ��� ��� �����, � ����� ��� ����� ����� ����� ������� ������� �������, ����� ���� � ������� ����� � �����. �����, ���� �������!";
		link.l1 = "������ � �� ��������� ��� ������ � ����, � ��������� ��� ����� �������� � �������� �� �����.";
		link.l1.go = "RobertBlake_6";			
		break;
		
	case "RobertBlake_6":
	DialogExit();
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	pchar.GenQuest.QuestAboardCaptanSurrender = true;
	LAi_SetImmortal(sld, true);
	sld.ShipEnemyDisable  = true;
	pchar.quest.APSHRobertBlake_AfterBattle.over = "yes";
	pchar.quest.APSHRobertBlakeOnMapOver.over = "yes";
	AddQuestRecord("APSH", "5");
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
	AddComplexSeaExpToScill(50, 50, 50, 100, 50, 50, 0);
	AddComplexSelfExpToScill(30, 30, 30, 30);
	pchar.quest.GothicApostatesAPS_6.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_6.win_condition.l1.location = "church IM2";
                     pchar.quest.GothicApostatesAPS_6.win_condition.l1.locator_group = "reload";
	pchar.quest.GothicApostatesAPS_6.win_condition.l1.locator = "reload1_back";
	pchar.quest.GothicApostatesAPS_6.win_condition = "APSH_Ruins";		
                     break;

//*********************����� ����*****************************

		case "SharliVein":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_1.wav");
		dialog.text = "���� ��-���� ������� ����� ���� � ����� ���� ������ �������.";
		link.l1 = "...";
		link.l1.go = "SharliVein_1";			
		break;

		case "SharliVein_1":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_2.wav");
		dialog.text = "...";
		link.l1 = "�� �����, �� ���, ��� �� �� ��� ����������.";
		link.l1.go = "SharliVein_2";			
		break;

		case "SharliVein_2":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_3.wav");
		dialog.text = "��, ��, ��, ��� �� ������ � ���� ����������.";
		link.l1 = "...";
		link.l1.go = "SharliVein_3";			
		break;

		case "SharliVein_3":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_4.wav");
		dialog.text = "����� � �� �������� ����� � ��� �����������, ����� ������, ��� �� �� ��� �������� ��.";
		link.l1 = "...";
		link.l1.go = "SharliVein_4";			
		break;

		case "SharliVein_4":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_5.wav");
		dialog.text = "��� �� �� �� �������������, �� �� ������ ��������� �� ���� ����.";
		link.l1 = "...";
		link.l1.go = "SharliVein_5";			
		break;

		case "SharliVein_5":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_ATTACK_1.wav");
		dialog.text = "...";
		link.l1 = "������ �������, � ������ ���� ������� ��� ������ �� �������� �� ����� - ������.";
		link.l1.go = "SharliVein_6";			
		break;

		case "SharliVein_6":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_ATTACK_2.wav");
		dialog.text = "���� ����� ������� ��� ��������� ����� ������ � ���� ���.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("APSH_SharliVein_ATTACK");		
		break;


//************���������  ���� �����****************************************

		case "BillMatthew":
                                    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOODMONSTERKILL.wav");
		dialog.text = "�������, ��� ������� ���, ��� ��� ��� �� ����� ���� � ������� ������.";
		link.l1 = "����� �������� ������?";
		link.l1.go = "BillMatthew_1";		
		break;
		
		case "BillMatthew_1":
		dialog.text = "��� �� ������� ������. �������, ��� ����� ���������� ��� �������. � ��� ��������� � ������� ������� ������ �� ��������� ����� '��������� ������'.\n����� �������� ����� �� ��������� ������ ������� ������� ���������� �����������, ������� � ��������. ������� ���� ����� � ���, ����� ��� ������ ������� ���� ������� ������� �� �� ��������� �����. ������ ��������������, �� ����� ��������, � ������� ������ ������� � �����-�� ��������� � ��� ��������� ������� ������.\n������ ����� �� ��� ����� ����� �� �����. �� �������� ������, ���� �� ���� ����� ��������� ���, � �������� � ��������� ��������.";
		link.l1 = "��, � ��� �� ���� ������?";
		link.l1.go = "BillMatthew_2";		
		break;

		case "BillMatthew_2":
		dialog.text = "����� �����-�� ����� �������� ������ ������� ����� ��������, ������� ���� ��������� ������� �� ������ ��� ����� ��������.\n���������, ��� ���������� ����������� ��� ��������� �� ����� ���������� ������, �������� ����������, ���������� �� ������ � ������ ���� ����� � ��������� �� ��������.\n��� ������� ��� � ������, � ���������� ���� � ���� �������� ���� ���! ����� ����, ����� ������� ������������ ������ ��� ����� ��������, � ����� ����� �������� � ������� ���� ���������� �������� ��������� � ����� ��������!\n�������� ������� �� ���� �� ������������� ��� ���� - ������ � ������� - ��� ��������� ������ ������ ����! ����� �����-�� ����� ��� ������� �������, � ������ ��� ������������, �� ����������� ����� ���� ����� ��������� �� �������� �����.\n���� ��� � ��� - ��� ������ ����� ����� � ��� ������� �������, ��� ������� �� ����������.";
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
		dialog.text = "��, ���� ���� �� ����� �����������, ��� ������ ���� ��� ������, ���� ��� ��� ����� ���� ��� ������ �� ���� ���������!";
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

//************���������  ������ ����� (����������)****************************************

		case "ObsessionDevlin":
	                     PlaySound("VOICE\Russian\Chaos.wav");
		dialog.text = "����� ����� �������������� � ��� ������ �� ������ ������ ���������. �������, �� ����� ����� ��������!";
		link.l1 = "������ �� �����������, ��� ��?";
		link.l1.go = "ObsessionDevlin_1";		
		break;

		case "ObsessionDevlin_1":
		dialog.text = "��� �� ����� ��� �, ����� ��, ��� � ���� �� ������.";
		link.l1 = "���...";
		link.l1.go = "exit";
	                     LAi_SetActorType(pchar);
		AddDialogExitQuest("GothicObsession_cemeteryman_4");	
		break;

		case "ObsessionDevlin_2":
 	                    PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_00.wav");
		dialog.text = "�� �����, ��� �� ������!";
		link.l1 = "...";
		link.l1.go = "ObsessionDevlin_3";		
		break;

		case "ObsessionDevlin_3":
 	                    PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_01.wav");
		dialog.text = "��� ������ ������� ������ � ������� ���� ��� � ����� �����.";
		link.l1 = "...";
		link.l1.go = "ObsessionDevlin_4";		
		break;

		case "ObsessionDevlin_4":
		npchar.model = "BSUnd";
		Characters_RefreshModel(npchar);
	                     npchar.name = "��������";
	                     npchar.lastname = "";
 	                     PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_02.wav");
		dialog.text = "�� ������� �����, �� ������� �� ������ ��, ��� �� ���������� � � ������ ���� �� ��� ����� � ������!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsessionDevlin2");		
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
                                         dialog.text = "���� �������, ��������� �������������� �������� ��� ������ ����� ����, ����� ����� �� ������ �������������� ���.";
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
		link.l1 = "������ �������, � ������ ���� ������� ��� ������ �� ��� �������� �� ����� - ������.";
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
                                         dialog.text = "���� ����� �� ����� ��� ��������� ����� ������ � ���� ���.";
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

//************���������  ���������� ��������****************************************

		case "CemeterymanTakeCoin":
		dialog.text = "�����, ������� - �� �� ��������.";
		link.l1 = "׸��, ��� �, ��� ���������...";
		link.l1.go = "CemeterymanTakeCoin_1";
		break;

		case "CemeterymanTakeCoin_1":
		dialog.text = "�����, �� � ������� �� � ���� ����. ��� � ����� ��� ��������, ����� ��������� �� ���������.";
		link.l1 = "������ �������������. ׸�� ������� ������ ������, �� � �������� �� �����?";
		link.l1.go = "CemeterymanTakeCoin_2";
		break;

		case "CemeterymanTakeCoin_2":
		dialog.text = "���.";
		link.l1 = "�� ��������, ��� ������, ����������, ����� ��� �� � �������!";
		link.l1.go = "CemeterymanTakeCoin_3";
		break;

		case "CemeterymanTakeCoin_3":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneyToCharacter(pchar, -1000);
		dialog.text = "� �� ����� �� ������ �����.";
		link.l1 = "�����, ������� ���� �� ������, ��� ��� ��������� �����.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicObsession_cemeteryman_8");	
		break;


//************��������� �������****************************************

		case "Balsemio":
		dialog.text = "�, ������, ����-�������! �� ������ �� ���� ������� ������?";
		link.l1 = "�������, �������, � � ���" + GetSexPhrase("","�") + " �� ������ ������! ����������, ����!";
		link.l1.go = "exit";	
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_11");
		break;

		case "Balsemio_1":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_15.wav");
		dialog.text = "��������� ����, �������! � ������ ��� ���������� ������� - ���� � ���� ������� �������� ������� ����� ���� �����, � � �������� � ���� ��������.";
		link.l1 = "��� ����� � ���� �������! ��� � ����� ���������, �������?";
		link.l1.go = "Balsemio_2";
		break;
		
		case "Balsemio_2":
		dialog.text = "�-�, �� ���������, �������! ��� �������� �������. ����� ����� ������!";
		link.l1 = "����������, ��� ��� ������ ����!";
		link.l1.go = "Balsemio_3";
		break;
		
		case "Balsemio_3":
		LAi_Fade("", "");
		dialog.text = "�� ������� " + GetSexPhrase("������","��������") + "! �����-�� � � ��� �����, �� ����� ��� ����������� ���, ��� ������ � ����� �� ���� �� ����� - ���� ���������� �������� ���! ���� ������... ������ � ���� � ������ ��������...";
		link.l1 = "�������� �� ���� ����� �����, ����� - �����, ��������� �� ����.";
		link.l1.go = "Balsemio_4";
		break;
		
		case "Balsemio_4":
		dialog.text = "�� ������, ��� ��� ���" + GetSexPhrase("","�") + " �����. �����-�� � ������ �� ������� '���������� �����' � �������� ��������� �������\n������� �� ��������� � ����� ����� �� �����. ������� ����� ��� � ������ - ��� ��� ���� ������, � ���� ������ - ������� ��� �������� �� ������� �����! ��, �� �������� ������� ������ � �����, �� �������\n���������, � �������� ������ ���. �������� ��� �����, ��� � ��� ���. �� ��������, ��� �� ����� � ������ ����� ����\n����� � ����, � ����� ����� ��������! �������� �����, ����� ��������� - � ������ � ����� �� �����! ������� ��� � ����� ��������, � �� �������� �������� ������ ������� - ��������� ������� �� �����\n���� �� ��������� ���������, ��� ����� ����� ����� � ����������� �����, �������� ���� �������, � ������ �� ����� �����\n��, �� � ��������� �� � ����� �� ������ ������. ����� �� ��������� �� ��� ����� - ������ ������� ������� � ����� ��������� ����.";
		link.l1 = "��� �� �� �������� ������?";
		link.l1.go = "Balsemio_5";
		break;
		
		case "Balsemio_5":
		dialog.text = "������ �� �������� ��� ������, ��� � ��� ����, �������� ��� �����. ����� �� ��� ����� - �� ����� ����� �������� ������ ������� ��������� ����������, ���������, ���� �������� - �������� ����\n� �����, ������� �� ������ � ����� ������ ���� - ����� ����, ����� ��� �������� �������, �� � ���������� ���-����� �� ����� �� �����������\n��� ����� ��� �������, �������... �������� � �����, � ���� �������� �� ����. ��� � ����� ���� ������ � ����.";
		link.l1 = "��� ��� �������! � ����� �� ���?";
		link.l1.go = "Balsemio_6";
		break;
		
		case "Balsemio_6":
		TakeNItems(PChar, "map_part1", 1);
	                     dialog.text = "�� ��, �������!";
		link.l1 = "� ��� ���������?";
		link.l1.go = "Balsemio_7";
		break;
		
		case "Balsemio_7":
		dialog.text = "�� ���, � ����������� ����, ���� ��� ��� ����. ������. �������, �����������" + GetSexPhrase("","�") + " �� ����, �� ���� ������������.";
		link.l1 = "��, ��������� ����, �����!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_12");
		break;

//************���������� ���������****************************************

		case "Kristobal":
	                     PlaySound("VOICE\Russian\pirat_quest_2.wav");
		dialog.text = "��������, �������, � ���� � ��� ������� ��������.";
		link.l1 = "� ���� ����������� ������.";
		link.l1.go = "Kristobal_1";	
		break;
		
		case "Kristobal_1":
		dialog.text = "�������� ����� ������ � ������ ��� �� � ����. � ��� ��� � ������� �������.";
		link.l1 = "� �������, �������, ��� �, ��� ���������.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_15");
		break;
		
		case "Kristobal_2":
	                     PlaySound("VOICE\Russian\pirat_quest_3.wav");
		dialog.text = "���� � ���, ��� �� �������� ����� ����������� ��������, ������� ����������� ��� �� �����. � ����� ��� ������ ��� ���.";
		link.l1 = "� ����� ��� ����� �� ��������? ������ ����� ����� ������� ��� ��������� �������, � �� �� ������ � ����� �������� ���������!";
		link.l1.go = "Kristobal_3";	
		break;
		
		case "Kristobal_3":
		dialog.text = "���� � ���, ������ �������, ��� � ����, � ������� �� ���, �������� ������� � ��� ����������, �� �� ��������� ������� ������������ � �������, � ������� �� ������ �� ��������� �������.";
		link.l1 = "��������� ������� ������� ��� ���� �������, � � ��������� �� ����� ����������� � ���� ����.";
		link.l1.go = "Kristobal_4";
		break;

		case "Kristobal_4":
		dialog.text = "��������� ������� ��� ������ � ��� ���� � ���������� �������� ������� � �����. ���� ������� ���������, ��� �� ���������. ������� ������ ��� ��� ����� ����� � �������� ��� ������.";
		link.l1 = "����� � ���! � �� �� ��� �����, ��� ��������������� �� ��� ����! ��������-�� �����, ��� ���� �������� �� ���� �������!";
		link.l1.go = "Kristobal_5";
		break;

		case "Kristobal_5":
		dialog.text = "� ������� - �� ��������, ��� ��������� �� ����� ����. �������� ��� ������� ���� ����� ����� � ������ �������� ����!";
		link.l1 = "�� ������� ���� ����� ������ ��, ��� �������� ���� ������, ���� ����� �� ����� �������������! ���������!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_16");
		break;

		case "Kristobal_6":
	                     PlaySound("VOICE\Russian\EvilPirates07.wav");
		dialog.text = "������ ��� ������! ������ �� ������� �������� ������!";
		link.l1 = "���� ���� ��������� ��������, ��� �� ��������, � ��������� ���� ���������� ���� ������. ����, ���������� ���, ��� ������!";
		link.l1.go = "Kristobal_7";	
		break;

		case "Kristobal_7":
		dialog.text = "������� ���, � � ��� ��������� � ���� �����!";
		link.l1 = "����� ����� �������, � � ��� ��������� � ����� �����!";
		link.l1.go = "Kristobal_8";	
		break;

		case "Kristobal_8":
		dialog.text = "�������, ���� ���� ����. ������, ������ �������, � �������� ���� �������. �������� �����������, ������ �� ������� ����� �����������.";
		link.l1 = "� ������ ����!";
		link.l1.go = "Kristobal_9";
		break;

		case "Kristobal_9":
		dialog.text = "�� � ��������� � ������� '���������� �����' ��������� ������� ��������� ������. ������ �� ��� �������. ��������� ������� ������� ����, ��� ������ �������� �����, ��������� � ����� ���������, ������� '���������� �����' ���� �������� �� ������\n� ����� ����� ����� ��� �������. ������ ��������� ������� � ��� ���� '������ �� �� ������'. � ��������� �������� ������� �� ����� � ������ ������� ����� - ������ ���� �������\n������� ��������� ������� ������, ��� ��� ���� ����� �� ������ ��������� � ������ �� �����������, � ����� �� ������ - �������� ������ ������. \n ��� ����� ���� ������� ������ �����-�� ����, � ����� ���������� '���������' ��� ����� �������. ��� �� �� ������ ��������� �� ������� � ��������� ���\n�����, �������, ����� ��� ����� ��������� ���������. �������� �������, ���� ������! ����� �� ����� �� ����� � ��������� �����, �������� � ���� �������\n��� ������� �� ��������� � ����� �����, �� ������� ��� ������� ���� � �����. � ���������� ��������� �� ���, �� ���� ������� �������� ��� ������, �������� ������������ �����. \n � �����������, ����� � �����, ��� ��������� �������� '���������� �����' �������� �� ������, � �������� �� �����������, ����� ��������� ������ ����������� �����, ��� ���-�� �� ���� � ���������\n��� �������� ���� ������ ���������� ��������� ��������� �������� - ����� �������. �� ������ ���������� ���������� ��������� �� ���������. ��������, �� � �������� ����������� ������ ����� �����.";
		link.l1 = "��, �� ����� ����������� ��� ���������. ��� �, ���� ����� ����� � ��� ����, �� � ������ �� ��������� �� ������.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_17");
		NextDiag.TempNode = "Kristobal_10";
		break;

		case "Kristobal_10":
		dialog.text = "�������, ����� �����������.";
		link.l1 = "� ����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Kristobal_10";
		break;

		case "Kristobal_11":
		dialog.text = "��-��-��... �������, �� ��������� �� ����� �������, ������ � ���� ���� �������������.";
		link.l1 = "� ��� ��� ��?";
		link.l1.go = "Kristobal_12";	
		break;

		case "Kristobal_12":
		dialog.text = "�� ����� �� �����, ��� � ����� ������ � ����� �������. ������� ������� � � ���� ��, ������ �������.";
		link.l1 = "�� ��� �� � ���. ��� ������� ��� ������ ��������... �������� ������ �������...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_29");	
		break;

//************����� ������****************************************

		case "DiegoMarkes":
	                     PlaySound("VOICE\Russian\Fisher02.wav");
		dialog.text = "���� ����, �������� �� ����� ����.";
		link.l1 = "��, ����� ������!";
		link.l1.go = "DiegoMarkes_1";	
		break;

		case "DiegoMarkes_1":
		dialog.text = "������ �� ���, ���� ���� ���������.";
		link.l1 = "��...�� ���������� � �����������, ��� ���������� ���������� � �����.";
		link.l1.go = "DiegoMarkes_2";	
		break;

		case "DiegoMarkes_2":
		dialog.text = "������, � ��� �� ������ ����������.";
		link.l1 = "� ����� ������� �� ��������� � ��������� �������.";
		link.l1.go = "DiegoMarkes_3";	
		break;

		case "DiegoMarkes_3":
		dialog.text = "��������� �������... �� ��� ���!";
		link.l1 = "��, ���� � ������ ���-�������, ��������� ���� �����������, ������ ���� � ���� ��������. �� ����� ����� ��������� ���� ��� � ���� ��� �������.";
		link.l1.go = "DiegoMarkes_4";	
		break;

		case "DiegoMarkes_4":
		TakeNItems(PChar, "map_part2", 1);
		dialog.text = "������� �������. � ����������� � ���, ��� �� ��������, � �������� ������� ���������� �� ���� �����, ����� ��� ����� ����, ������� ���, ��� ��� �� � ����.";
		link.l1 = "������, �����. ����� ���� �����.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_18");	
		NextDiag.TempNode = "DiegoMarkes_5";
		break;

		case "DiegoMarkes_5":
		dialog.text = "�����������, ������� ���������, ��� ���� �������.";
		link.l1 = "�������, ��� ������� ��������� ����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "DiegoMarkes_5";
		break;

//************������� ������****************************************

		case "FlorensioCap":
	                     PlaySound("VOICE\Russian\pirat_common_1.wav");
		dialog.text = "���� ���� ����, ���������� � �� � ���������� ���������.";
		link.l1 = "��, ������� ��������� �������!";
		link.l1.go = "FlorensioCap_1";	
		break;

		case "FlorensioCap_1":
		dialog.text = "����... ��������� �������. ����������.";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_20");	
		break;

//*********************��������� �������*****************************

		case "Florensio":
		dialog.text = "��, ����� �������, ������� ������! ��� �� �� �����, ��� �� ����� ��������.";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Florensio");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Kristobal"));
		AddDialogExitQuest("GothicApostatesAPSdialog1");
		break;
		
		case "Florensio_1":
		dialog.text = "�� ������� ����, ������� �������!";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Kristobal");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
		AddDialogExitQuest("GothicApostatesAPSdialog3");
		break;
		
		case "Florensio_2":
		dialog.text = "���, ��� ���� �������� � �������� ������� ���� ����� �� ������. �������, � ����� ������ - � ����������� ����, � ������ �� ��� �� �����. ������, ��� ��� � �����? ���� ����� ���������?";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Kristobal");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
		AddDialogExitQuest("GothicApostatesAPSdialog5");
		break;
		
		case "Florensio_3":
		dialog.text = "������ ����� ����� ������ � ������ ����. ���������, �������� �������!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSdialogEnd");
		break;

//************���������****************************************

		case "iroquois":
		dialog.text = "� ���� ������ � ����������� ������ ��������. ��� ���� ������� ����� �� ������� ������, �� ����� ��� ���� ������.";
		link.l1 = "��� ��!";
		link.l1.go = "iroquois_1";	
		break;

		case "iroquois_1":
		dialog.text = "�� ��� ���������, � ���������� �� ������� �������. ��� ������ �� ��������� �������� ��� ������, �� � ���� ����� ����� �� ������� �������� ����������� � ������. ����� ���� ���� ������ ��������� ����� ���� ��� ������� �����\n�� ��������� ����������� �� ����� ����� ���� ��������� ���������� � ������ - ��� �� ���, ���� ���� �� ������� ������ � ������ �������� ��������� ��� ����� ������, �� ����� ������ ������������ - ������ � �����������, � ����� ������� ����� ��-�� ������� ���������� - ��������� ���������� ������� ������� �����. ���� ������ ��������� ���������� ������, � ��������� ����� ������� �� ���� ��������. � - ��� ������ �������.";
		link.l1 = "�������, �� �� ������, � ����� ��� ����, ��� �� ������� ��� ������ � ��� �������� � ����� ������� ������� �������� ���� ������, �� ��� ��� �����, ��� ����� ������ ������� � ����� ��������, ����� � �� ����!";
		link.l1.go = "iroquois_2";	
		break;

		case "iroquois_2":
		dialog.text = "�� ���� �� ����� � ��������. �� ���� ����� ���� ������������.";
		link.l1 = "��... � ���� ���� ��������� � ������� � �� ������� � ����� ��������.";
		link.l1.go = "iroquois_3";	
		break;

		case "iroquois_3":
		dialog.text = "����� �� ������ �����, ��� ������ ������� ��� ����������� �������� �������� � ������� ��� �� ���������. ��� ��� ���������� ����� ������� � ������.";
		link.l1 = "�������, ��� �� �������� ������...";
		link.l1.go = "iroquois_4";	
		break;

		case "iroquois_4":
		dialog.text = "��������� ������ ��������, ��� ����������� ���������� �� ������ �������, ������� ������������ � ������ ��������� ��� ��� �������� � ������ ����� - ��� �� ����������. ������ ������� ��� � ������������ ���������� � ������ ������, �� �� ����� ��������� ������� �� ���� ���������, ������ ��������� � ���� � �������� � ������ ���������.";
		link.l1 = "����� �� ������ ��� ������� ��� ������� ��� ����������, ���� ������ ��������� �� ������ ������ - � �� ������ ��������...";
		link.l1.go = "iroquois_5";	
		break;

		case "iroquois_5":
		dialog.text = "������ ����, ��� ���������� �� ������� �������� ��� ���������� � �� ��� ��� �������� ���� �������. ������ ����� ����.";
		link.l1 = "������ ���������...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSBrachyura");
		break;

//************���� �����****************************************

		case "SofiBrics":
		dialog.text = "...";
		link.l1 = "���� ����� ����...";
		link.l1.go = "SofiBrics_1";	
		break;

		case "SofiBrics_1":
		dialog.text = "...";
		link.l1 = "�������, � ������� ��� � ���� ����, �� ��� "+GetFullName(Pchar)+", � ���� ���� ������...";
		link.l1.go = "SofiBrics_2";	
		break;

		case "SofiBrics_2":
		dialog.text = "...";
		link.l1 = "��� �������� � ������� '��������' � ���� ���� ��� ��������� ����� �������, ��� �� ��� �������� � � ����� ���� � � ����.";
		link.l1.go = "SofiBrics_3";	
		break;

		case "SofiBrics_3":
		dialog.text = "...";
		link.l1 = "��� ��� ��������, ��� �� �� �� ����� �������...";
		link.l1.go = "SofiBrics_4";	
		break;

		case "SofiBrics_4":
	                     PlaySound("VOICE\Russian\Alvilda3.wav");
		dialog.text = "��, �� ���������, �� �� ����, � � ��� �������� �� ���� ������ �� ��������, ���������� ������� ��� �� �� ����� �� ����.";
		link.l1 = "������ ���, � ���� ���� ����� ���������� ����, �� �������� � ��������. ��, ����� ������ ���. � ��� � ����� ���, ��� ����, ��� �� ���� ��������� ��� ������...";
		link.l1.go = "SofiBrics_5";	
		break;

		case "SofiBrics_5":
		dialog.text = "�� ����� ����������, ����� ��� �� � ������ ����. � �������� ����� � ���� � ������ ��������, ���� ���������� ��������.";
		link.l1 = "� ��� �� ��� �� ��������, �� �� ������...";
		link.l1.go = "SofiBrics_6";	
		break;

		case "SofiBrics_6":
		dialog.text = "�����, ��� ����� ������� ���� ����, ���� �� �� ����������.";
		link.l1 = "����������, � ���� ����� ��� � ������.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_3");	
		NextDiag.TempNode = "SofiBrics_7";
		break;

		case "SofiBrics_7":
	                     PlaySound("VOICE\Russian\Alvilda3.wav");
		dialog.text = "� ����� ���� ������, �������� ������� ������� ���� ���� � ��...";
		link.l1 = "������, ���.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "SofiBrics_7";
		break;


























		// ������� ����� 
		case "W_headclerk":

			dialog.text = "�� ���-�� ������, " + GetSexPhrase("������","����������") + "?";
			if (!CheckCharacterItem(pchar, "PirTradeLicence") && CheckCharacterItem(pchar, "Mason"))
			{
				link.l1 = "� ���� ���������� �������� �������� ����� ��������.";
				link.l1.go = "licence";	
			}
			if (!CheckAttribute(npchar, "quest.trade") && CheckCharacterItem(pchar, "Mason"))
			{
				link.l2 = "� ������, ��� � ��� ����� ���������� ����������� ������� � ������ �������� ����. ��� ���?";
				link.l2.go = "trade";	
			}
			else
			{
				link.l2 = "��� � ��� ������� ������� � �������? ��������, ����������.";
				link.l2.go = "trade_1";	
			}

			link.l9 = "���, ���� ������.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "W_headclerk";
		break;
		
		// �������� ��������
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� � ������ ������� ��� ������������, ��� ���� �������� ������� ����� ������, ������� � ����������� ������������� ������������ ���������� �� ���� ���� �������� ��������, � ������ - ������� ����������� �������� � ��������� �������� �������� ����� �����\n� ������ ��������� ������ ����� ���� �������� ����� ���������� ������������. ����� �� �������� ���������, ���� �� �����-�� ��������, ������� �����, �������� � �������� � ����������. ��� �������?";
				link.l1 = "����������. � ����� ��� � ��������.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "�� ��� ��, ����������, ������������. �� ����� ���� �� ������ �������� ��������?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;
		
		case "licence_0":
			dialog.text = "�������� ���� ����� ������������������ ����� � ����� ���� ����� �����, ��������� ������������ ���� ������ ��������� � ��������� ���� ������ �������� - ���������. ������ ���� � ��� ���� �������� � ������� � ��� ������, � ���� ������� �� �������� �������, �������� ��� �� �������. ����� ���� - � ��� �� ������ ������. ������ ���\n���� �� ����������� ��������� � ���������� ��� �������� - �� �������� ����� ������ � ���� ������� ������������� ���� - ��� ������� ��� �� �������� �������, ��������� �������� ������ � ������� � ������� ����� ���������� ������� ��������, � ������ ����� �����������\n��, ���� �� �����: �������� ����������� ��������, ������ �� �������� ������������ ������������� �������� ���������... ��, ������, ��������, ��� ���������. �� ����� ���� �� ������ �������� ��������?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
		
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			// ������� � ���������
			npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "�����, ����������, �������� �����, �� ���������� � �� �������. � ��� ����� ���������. ��� �� ������� ���� ��� ����� ��������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "����������� ����, �� ������� �� ������ �������� - �������� ����. �� ������� ����� ��� �������� - �� ��������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "������������ ����, �� ������� �� ������ �������� - �������. �� ������� ����� ��� �������� - �� ��� �����������, ��� ������?";
				link.l1 = "������ �������...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "�� "+FindRussianDaysString(sti(fQty))+"? ������. ��������� ����� �������� �������� "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". ��� ����������?";			
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "��, �������, ����������.";
				link.l1.go = "licence_2";
			}
			link.l2 = "� ���������, � ���� ��� ������ � ����� ������� �����. � ����� � ��� �� ��������� �����.";
			link.l2.go = "exit";
		break;
		
		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "��������, �� ��� ��� ���� �������� ���� ������. � ������� �����.";	
			link.l2.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "���, ���� ������... ������ �������� ������� � ������... ���, ������. �������� ��� ��������.";
			link.l1 = "�������! �� ��������, �����.";
			link.l1.go = "exit";
		break;
		
		case "trade":
			dialog.text = "����� ��� �� ��������. ����� �� ������ ���������� ������������� �������, ����� ��� ����������� ������, ����������, ��������� � �������� ���� ��� ��������� ���������� �� ������� ������� �����. ������ � ������� ��� ������ �� ������, �� ����������� ����� ��� �������� ����� - ���������, ��������� ��. ��� ��� ���� �� ������� ������, ��� ������ - ������� ����� ��������\n����� ������������ � ��� � ������� ���������� ����� ���������� � ��������� �����. ������� ���������� ����������� �� �������?";
			link.l1 = "��, ������ ��� �������.";
			link.l1.go = "trade_1";
			npchar.quest.trade = "true";
		break;
		
		case "trade_1":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 7)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);			
		break;

		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Ronald_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "�������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Ronald_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ����������?";
            Link.l1 = "���� �����!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "������ �� ���� � �� ��������!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "����� �������� ��� ���������� ��� ������ �������������� ������.";
					Link.l3.go = "SetGunBullets";
				}	
			}


		break;

		
		case "SetGunBullets":
			Dialog.Text = "����� ���� ����������:";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
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
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
        case "Boal_Stay":
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
        break;
	//<-- ----------------------------------- ���������� ���� ----------------------------------------
	
	// �� ��������
		case "tieyasal":
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, �� ��������. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
			link.l1 = "�������, �������! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ����� ������������?";
			link.l1 = "������� �����. � ���� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21_1");
			npchar.quest.Tieyasal = "teleport";
		break;


		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit1":			
			DialogExit();
		break;

	}
}