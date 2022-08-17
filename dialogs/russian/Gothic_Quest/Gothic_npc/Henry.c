// ����� ����� � ������� ����� 
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, n, iTemp;
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

		case "First time_1":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_14_LOOKINGFORTROUBLEAGAIN.wav");
		dialog.text = "�� ���� �������?";
		link.l1 = "...";
		link.l1.go = "Henry_First time_1";			
		break;

		case "Henry_First time_1":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\MOMENT.wav");
		dialog.text = "....";
		link.l1 = "������� ����������...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1 = "locator";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.location = "Trinidad_Jungle_03";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator_group = "reload";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator = "reload3_back";
                                     PChar.quest.GothicEng_HenryFight.function = "GothicEng_HenryFight";			
		break;

		case "First time_2":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_07.wav");
		dialog.text = "��� ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "Henry_005";		
		break;

	                 case "First time":
		if (CheckAttribute(PChar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "Start_PiratosGreg" && !CheckAttribute(npchar, "quest.Gothic.PiratosGreg"))
			{
		 dialog.text = "����...";
		 link.l1 = "...";
		 link.l1.go = "GHenry";
			}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "Henry.Fail1" && !CheckAttribute(npchar, "quest.Henry.Fail1"))
		{
		dialog.text = "�� ������ ���������� �� ��������, �������������� � �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_022";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "HenryBand.Fail2" && !CheckAttribute(npchar, "quest.HenryBand.Fail2"))
		{
		dialog.text = "��� ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_x0002";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "Owen.Fail3" && !CheckAttribute(npchar, "quest.Owen.Fail3"))
		{
		dialog.text = "��� ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_HenryOwen";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "GothicPiratos_NoMoney" && !CheckAttribute(npchar, "quest.GothicPiratos_NoMoney"))
		{
		dialog.text = "��������" + GetSexPhrase("","�") + " �������?";
		link.l1 = "��, ����� ��, ��������" + GetSexPhrase("","�") + ".";
		link.l1.go = "GothicPiratosGreg_tribut_pay_500";
		}

		NextDiag.TempNode = "First time";
		break;

       		case "GHenry":
                                   LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload3_back", true);//������� ������
	                 PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_04_00.wav");
		dialog.text = "����...";
		link.l1 = "...";
		link.l1.go = "Henry_1";			
		break;

		case "Henry_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_04_01.wav");
		dialog.text = "�� ���� ��� ����?";
		link.l1 = "...";
		link.l1.go = "Henry_2";			
		break;

		case "Henry_2":
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "Henry_02";
		link.l2 = "����.";
		link.l2.go = "Henry_002";				
		break;

		case "Henry_02":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FEIND_15_00.wav");
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "Henry_03";			
		break;

		case "Henry_03":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FEIND_04_01.wav");
		dialog.text = "����� ����������� �� ���� �������, �����!";
		link.l1 = "...";
		link.l1.go = "Henry_04";			
		break;

		case "Henry_04":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_SECONDWARN_04_00.wav");
		dialog.text = "��� ���� ��� ����� � � ������� ���� ������.";
		link.l1.go = "exit";

		NextDiag.TempNode = "First time_2";

                                    PChar.quest.GothicEng_HenryFight.win_condition.l1 = "locator";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.location = "Trinidad_Jungle_03";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator_group = "reload";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator = "reload3_back";
                                     PChar.quest.GothicEng_HenryFight.function = "GothicEng_HenryFight";

		NextDiag.TempNode = "First time_2";			
		break;

		case "Henry_002":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FREUND_15_00.wav");
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "Henry_003";			
		break;

		case "Henry_003":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FREUND_04_01.wav");
		dialog.text = "��� ����� ������� �����, � ���� �� ����, ��� ���� ����� ����!";
		link.l1.go = "Henry_004";		
		break;

		case "Henry_004":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\GG_34.wav");
		dialog.text = "....";
		link.l1 = "��...";
		link.l1.go = "Henry_005";
		break;

		case "Henry_005":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_SECONDWARN_04_00.wav");
		dialog.text = "��� ���� ��� ����� � � ������� ���� ������.";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time_2";

                                    PChar.quest.GothicEng_HenryFight.win_condition.l1 = "locator";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.location = "Trinidad_Jungle_03";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator_group = "reload";
                                    PChar.quest.GothicEng_HenryFight.win_condition.l1.locator = "reload3_back";
                                     PChar.quest.GothicEng_HenryFight.function = "GothicEng_HenryFight";		
		break;

//========= ������� �������� �� ���������� =====================


	                 case "PiratosHenry":
                                   LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload3_back", true);//������� ������
	                 PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_04_00.wav");
		dialog.text = "����...";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_1";			
		break;

		case "GothicPiratosGreg_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_04_01.wav");
		dialog.text = "�� ���� ��� ����?";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_2";			
		break;

		case "GothicPiratosGreg_2":
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "GothicPiratosGreg_02";
		link.l2 = "����.";
		link.l2.go = "GothicPiratosGreg_002";				
		break;

		case "GothicPiratosGreg_02":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FEIND_15_00.wav");
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "GothicPiratosGreg_03";			
		break;

		case "GothicPiratosGreg_03":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FEIND_04_01.wav");
		dialog.text = "����� ����������� �� ���� �������, �����!";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_04";			
		break;

		case "GothicPiratosGreg_002":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FREUND_15_00.wav");
		dialog.text = "...";
		link.l1 = "����.";
		link.l1.go = "GothicPiratosGreg_003";			
		break;

		case "GothicPiratosGreg_003":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FREUND_04_01.wav");
		dialog.text = "��� ����� ������� �����, � ���� �� ����, ��� ���� ����� ����!";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_5";		
		break;

		case "GothicPiratosGreg_04":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_HELLO_FEIND_04_02.wav");
		dialog.text = "������, ��� ���� ���� ��� �������� �� ��������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_5";		
		break;

		case "GothicPiratosGreg_5":
		dialog.text = "...";
		link.l1 = "�������� ���� ������.";
		link.l1.go = "GothicPiratosGreg_tribut";
		link.l2 = "��� �� ����� �������?";
		link.l2.go = "GothicPiratosGreg_palisade";	
		link.l3 = "���� ��� ��������?";
		link.l3.go = "GothicPiratos_Greg";
		link.l4 = "��� ���� ����.";
		link.l4.go = "GothicPiratosGreg_exit";			
		break;

		case "GothicPiratos_Greg":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ��� ��������?";
		link.l1.go = "GothicPiratos_Greg_1";		
		break;

		case "GothicPiratos_Greg_1":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_04_01.wav");
		dialog.text = "��, �� ��� ���� ��, ������� ���� - ��� �������!";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_2";		
		break;

		case "GothicPiratos_Greg_2":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_04_02.wav");
		dialog.text = "��, ������� �������! ����� �� � ��� �����������, ���� ����� �� ���� �� ������� ��� ������, �� ���� �� ������� �� ���� ��������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_3";		
		break;

		case "GothicPiratos_Greg_3":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_15_03.wav");
		dialog.text = "...";
		link.l1 = "� � ��� ��� ����������.";
		link.l1.go = "GothicPiratos_Greg_4";		
		break;

		case "GothicPiratos_Greg_4":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_04_04.wav");
		dialog.text = "����� ������, ������ �� ��������� � ��� � ������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_5";		
		break;

		case "GothicPiratos_Greg_5":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ADD_04_00.wav");
		dialog.text = "���� �� ����������� � ��� �������������� ���� �� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_6";		
		break;

		case "GothicPiratos_Greg_6":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ADD_04_01.wav");
		dialog.text = "������ ��������� ���������� ������ �������, � �� ������ � ��������� �������, ���� � ���� �� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_7";		
		break;

		case "GothicPiratos_Greg_7":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ADD_04_02.wav");
		dialog.text = "�� �� ������ ���������, ��� �����������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratos_Greg_8";		
		break;

		case "GothicPiratos_Greg_8":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_TRAIN_04_06.wav");
		dialog.text = "���� ��������� �������.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosGreg_5";		
		break;

		case "GothicPiratosGreg_tribut":
	                    PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TRIBUT_15_00.wav");
		dialog.text = "...";
		link.l1 = "�������� ���� ������.";
		link.l1.go = "GothicPiratosGreg_tribut_1";		
		break;

		case "GothicPiratosGreg_tribut_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_ADD_04_00.wav");
		dialog.text = "�� -��, ���, ��� ���� �� ����� ��������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_2";		
		break;

		case "GothicPiratosGreg_tribut_2":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_ADD_04_01.wav");
		dialog.text = "������� ���� ����� ������� � ������...";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_3";		
		break;

		case "GothicPiratosGreg_tribut_3":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_EINIGEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� ����� ���-������ ������������?";
		link.l1.go = "GothicPiratosGreg_tribut_4";		
		break;

		case "GothicPiratosGreg_tribut_4":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_EINIGEN_04_01.wav");
		dialog.text = "��, ������ ��� ��������� ������� � � ������ ���� ������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_5";		
		break;

		case "GothicPiratosGreg_tribut_5":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_17.wav");
		dialog.text = "...";
		link.l1 = "� ���� ���� ���� ������, ����� ������.";
		link.l1.go = "GothicPiratosGreg_tribut_6";
		break;

		case "GothicPiratosGreg_tribut_6":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_GOLD500_04_00.wav");
		dialog.text = "������� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_pay_500";		
		break;

		case "GothicPiratosGreg_tribut_pay_500":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_11.wav");
		dialog.text = "...";
		link.l1 = "������, ��� ������.";
		link.l1.go = "GothicPiratosGreg_tribut_pay_0";
		break;

		case "GothicPiratosGreg_tribut_pay_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "...";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_8";
		break;

 		case "GothicPiratosGreg_tribut_8":                                    
            if (sti(pchar.money) >= 500)
            {
        		dialog.text = "���������, ����� ���������� � ������.";
        		link.l1 = "...";
        		link.l1.go = "GothicPiratosGreg_tribut_9x";
            }
            else
            {
        		dialog.text = "���, " + GetSexPhrase("������","���������") + ", ����� ���? ��� � �� ��� ������ ��������? �������, ����� �����.";
        		link.l1 = "��, �� ������ �� ������, ����� � ������� ������ ���...";
        		link.l1.go = "exit";
        		pchar.questTemp.GothicPiratosGreg = "GothicPiratos_NoMoney";
	ChangeCharacterComplexReputation(pchar, "nobility", -1);
               }
 		break;

		case "GothicPiratosGreg_tribut_9x":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TRIBUT_JA_04_01.wav");
		dialog.text = "���������, ����� ���������� � ������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_tribut_9";		
		break;

		case "GothicPiratosGreg_tribut_9":
                                          LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload3_back", false);//������� ������
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ADD_04_03.wav");
    		dialog.text = "������ �� �������� ������� �������������.";
    		link.l1 = "...";
    		link.l1.go = "exit";
    		AddMoneyToCharacter(pchar, -500);
		npchar.quest.GothicPiratos_NoMoney = "true";
		NextDiag.TempNode = "GothicPiratosGreg_6";
	                     npchar = CharacterFromID("GFrancis");
	                     npchar.dialog.currentnode = "Francis_Greg";
	                     npchar = CharacterFromID("GGarett");
	                     npchar.dialog.currentnode = "Garett";	
 		break;

		case "GothicPiratosGreg_6":
		dialog.text = "...";
		link.l1 = "� ���� �������������� � ������ ������.";
		link.l1.go = "GothicPiratosGreg_entercrew";	
		link.l2 = "��� ���� ����.";
		link.l2.go = "GothicPiratosGreg_exit";			
		break;

		case "GothicPiratosGreg_entercrew":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� �������������� � ������ ������.";
		link.l1.go = "GothicPiratosGreg_entercrew_1";		
		break;

		case "GothicPiratosGreg_entercrew_1":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_04_06.wav");
		dialog.text = "��, ��� �, ����� ����������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_entercrew_2";		
		break;

		case "GothicPiratosGreg_entercrew_2":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_04_07.wav");
		dialog.text = "��� ���� ���� ��� �� ��������.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosGreg_7";		
		break;

		case "GothicPiratosGreg_7":
		dialog.text = "...";
		link.l1 = "��� ���� ���� ��� �����-������ �������.";
		link.l1.go = "GothicPiratosGreg_Owen";
		link.l2 = "��� ���� ����.";
		link.l2.go = "GothicPiratosGreg_exit";			
		break;

		case "GothicPiratosGreg_palisade":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ����� �������?";
		link.l1.go = "GothicPiratosGreg_palisade_1";		
		break;

		case "GothicPiratosGreg_palisade_1":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_04_01.wav");
		dialog.text = "� ��� �� �������, � ������ ���������� �� ���, ��� �� ��� ������ ������ ��������� �������� � ����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_palisade_2";		
		break;

		case "GothicPiratosGreg_palisade_2":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_04_02.wav");
		dialog.text = "���� �� �� ����� ��������, ������� ����, ���� ��� �������� ����� ��� ���.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_palisade_3";		
		break;

		case "GothicPiratosGreg_palisade_3":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_04_03.wav");
		dialog.text = "��� �� � ����� ���������� � ������ ������ ����������� ����� ����.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosGreg_5";		
		break;

		case "GothicPiratosGreg_Owen":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_15_01.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ���� ��� �����-������ �������.";
		link.l1.go = "GothicPiratosGreg_Owen_1";		
		break;

		case "GothicPiratosGreg_Owen_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_01.wav");
		dialog.text = "�� ��� ��������� ���� ��� ����� ������ ������ ��� ���������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_2";		
		break;

		case "GothicPiratosGreg_Owen_2":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_05.wav");
		dialog.text = "��� ������ ���� ��������� ������ � �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_3";		
		break;

		case "GothicPiratosGreg_Owen_3":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_06.wav");
		dialog.text = "�� ������ �� ������ �� ����, � ������ �� ���-������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_4";		
		break;

		case "GothicPiratosGreg_Owen_4":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_07.wav");
		dialog.text = "������� ������, ��� ��������� ������ ����� ��������� �����. �� �� �������� ��.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_5";		
		break;

		case "GothicPiratosGreg_Owen_5":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_08.wav");
		dialog.text = "����� ���, ��� ��� ������� �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_6";		
		break;

		case "GothicPiratosGreg_Owen_6":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_04_09.wav");
		dialog.text = "��� �������, ����� ����� ������, ������� ������� �� ������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_7";		
		break;

		case "GothicPiratosGreg_Owen_7":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "����� ��� ����������� ��������.";
		link.l1.go = "GothicPiratosGreg_Owen_8";		
		break;

		case "GothicPiratosGreg_Owen_8":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_04_10.wav");
		dialog.text = "�� �� ����� ����� ����� ������� ��� ��������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_9";		
		break;

		case "GothicPiratosGreg_Owen_9":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_04_11.wav");
		dialog.text = "��������� �������� ���������� � ����� � ��� �� ����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_10";		
		break;

		case "GothicPiratosGreg_Owen_10":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_04_12.wav");
		dialog.text = "� ������ - ��� ��������� �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Owen_11";		
		break;

		case "GothicPiratosGreg_Owen_11":
	                     npchar = CharacterFromID("GBill");
	                     npchar.dialog.currentnode = "Bill_AngusHanc";
	                     npchar = CharacterFromID("GOwen");
	                     npchar.dialog.currentnode = "Owen";
	                     npchar = CharacterFromID("GMatt");
	                     npchar.dialog.currentnode = "Matt_JunglefortBandits";
		NextDiag.TempNode = "GothicPiratosGreg_8";
		DialogExit();
		break;

		case "GothicPiratosGreg_8":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_07.wav");
		dialog.text = "��� ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_exit";		
		break;

		case "GothicPiratosOwen_Malcom":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_07.wav");
		dialog.text = "��� ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "GothicPiratosOwen_Malcom_1";		
		break;

		case "GothicPiratosOwen_Malcom_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ ������ ��������.";
		link.l1.go = "GothicPiratosOwen_Malcom_2";		
		break;

		case "GothicPiratosOwen_Malcom_2":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_15_03.wav");
		dialog.text = "...";
		link.l1 = "����� ����� ������� ������.";
		link.l1.go = "GothicPiratosOwen_Malcom_3";		
		break;

		case "GothicPiratosOwen_Malcom_3":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_04_04.wav");
		dialog.text = "����� ������ � ����� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosOwen_Malcom_4";		
		break;

		case "GothicPiratosOwen_Malcom_4":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_04_05.wav");
		dialog.text = "��� ���� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosOwen_Malcom_5";		
		break;

		case "GothicPiratosOwen_Malcom_5":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 50);
		Log_Info("�� �������� 50 ������0�");
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_ADD_04_00.wav");
		dialog.text = "��� � ��������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosOwen_Malcom_6";		
		break;

		case "GothicPiratosOwen_Malcom_6":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_ADD_15_01.wav");
		dialog.text = "...";
		link.l1 = "�� ����.";
		link.l1.go = "GothicPiratosOwen_Malcom_7";		
		break;

		case "GothicPiratosOwen_Malcom_7":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN2_ADD_04_02.wav");
		dialog.text = "�������, ������ ����� ����������� �� ����.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosGreg_9";		
		break;

		case "GothicPiratosGreg_9":
		dialog.text = "...";
		link.l2 = "��� ���� ���� ��� �����-������ �������.";
		link.l2.go = "GothicPiratosGreg_Bandits";
		link.l3 = "��� ���� ����.";
		link.l3.go = "GothicPiratosGreg_exit";			
		break;

		case "GothicPiratosGreg_Bandits":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_OWEN_15_01.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ���� ��� �����-������ �������.";
		link.l1.go = "GothicPiratosGreg_Bandits_1";		
		break;

		case "GothicPiratosGreg_Bandits_1":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_ADD_04_02.wav");
		dialog.text = "��, � �� �������� ���� ����� ������ �� ���� ����� � �������� �������� � ����� ��������...";
		link.l1 = "���� ���...";
		link.l1.go = "GothicPiratosGreg_Bandits_2";
		link.l2 = "������ �� �������, ��� ������� ����� �� ��� �������!";
		link.l2.go = "GothicPiratosGreg_Bandits_02";		
		break;

		case "GothicPiratosGreg_Bandits_2":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_15_09.wav");
		dialog.text = "...";
		link.l1 = "���� ���...";
		link.l1.go = "GothicPiratosGreg_Bandits_3";		
		break;

		case "GothicPiratosGreg_Bandits_3":
		NextDiag.TempNode = "GothicPiratosHenry";
		DialogExit();
	                     npchar = CharacterFromID("GMatt");
	                     npchar.dialog.currentnode = "Matt_JunglefortBandits_6";
	                     npchar = CharacterFromID("GSkip");
	                     npchar.dialog.currentnode = "Skip_Bandits";	
		break;

		case "GothicPiratosGreg_Bandits_02":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_BANDITS_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ �� �������, ��� ������� ����� �� ��� �������!";
		link.l1.go = "GothicPiratosGreg_Bandits_03";		
		break;

		case "GothicPiratosGreg_Bandits_03":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_BANDITS_04_04.wav");
		dialog.text = "������, ��� ����� ���� � ��������� �����, � �� ��� �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Bandits_04";		
		break;

		case "GothicPiratosGreg_Bandits_04":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_04_02.wav");
		dialog.text = "��� ������� ������� � ������ ��� � ��������� ����� ��� ���������� ��������� ������ ������, ��� ����� � �������� ����������� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Bandits_05";		
		break;

		case "GothicPiratosGreg_Bandits_05":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_PALISADE_WHATFOR_04_03.wav");
		dialog.text = "�� ���� ��� ��������� �����, ��� ����� ������� �� ���, �� �� ��� ��������, ��� ��� �� ����� ��� �������.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Bandits_06";		
		break;

		case "GothicPiratosGreg_Bandits_06":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_ADD_04_05.wav");
		dialog.text = "�� ������ ���������� �� ��������, �������������� � �����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Bandits_07";		
		break;

		case "GothicPiratosGreg_Bandits_07":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_05.wav");
		dialog.text = "���� �� ���������� ���������� � ���� ��������������, ������ �� ����.";
		link.l1 = "...";
		link.l1.go = "GothicPiratosGreg_Bandits_08";		
		break;

		case "GothicPiratosGreg_Bandits_08":
	                  PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_ENTERCREW_ADD_04_06.wav");
                                          LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload4_back", true);//������� ������
		dialog.text = "������ ������ �� ���� ����� � ��������� � ����� ���������.";
		link.l1 = "...";
    		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosHenry";
	                     npchar = CharacterFromID("GMatt");
	                     npchar.dialog.currentnode = "Matt_JunglefortBandits_6";
	                     npchar = CharacterFromID("GSkip");
	                     npchar.dialog.currentnode = "Skip_Bandits";		
		break;

		case "GothicPiratosHenry":
		dialog.text = "...";
		link.l1 = "��� ���� ����.";
		link.l1.go = "GothicPiratosHenry_exit";			
		break;

		case "GothicPiratosHenry_exit":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\EXIT_2.wav");
		NextDiag.TempNode = "GothicPiratosHenry";
		DialogExit();	
		break;

		case "Battle_end_2":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_03.wav");
		dialog.text = "�� ���������� � ���� � ��������, ������� �������� ���� ��� ��������.";
		link.l1 = "...";
		link.l1.go = "Battle_end_3";	
		break;

		case "Battle_end_3":
	                     PlaySound("VOICE\Russian\gotica\HENRY\DIA_ADDON_HENRY_TURMBANDITEN_04_04.wav");
		dialog.text = "����� ����, �����-������, �� ���� ������� ��������� �������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "GothicPiratosHenry";	
		break;

















		case "GothicPiratosGreg_exit":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\EXIT_2.wav");
		dialog.text = "....";
		link.l1 = "��� ���� ����.";
		link.l1.go = "GothicPiratosGreg_exit_1";
		break;

		case "GothicPiratosGreg_exit_1":
		npchar.quest.Gothic.PiratosGreg = "true";
		npchar.quest.Henry.Fail1 = "true";
		NextDiag.TempNode = "GothicPiratosGreg_8";
		DialogExit();	
		break;

//---------------------------------------�������-------------------------------

		case "Junglefort_bandit":

	                  PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_06_00.wav");

                                          if (CheckCharacterItem(pchar, "suit4"))
		{
		dialog.text = "��, �� ������! �� ���� ������! ��� ���������� - ��� �������!";
		link.l1 = "...";
		link.l1.go = "Junglefort_attack_0";
		break;
		}

		if (npchar.quest.meeting == "0")
		{
		dialog.text = "��, �� ������! �� ���� ������! ��� ���������� - ��� �������!";
		link.l1 = "��. �� � ���� ������... � ����� ����� �� ��� ��� ����������?";
		link.l1.go = "Junglefort_bandit_1";
		npchar.quest.meeting = "1";
		}
		else
		{
		dialog.text = "�-�, ��� ����� ��?! ����, ��-�������� �� ���� �� �������... ������, ���!!";
		link.l1 = "...";
		link.l1.go = "Junglefort_bandit_fire";
		}
		break;
				
		case "Junglefort_bandit_1":
		dialog.text = "� � �����, ��� ����� �� ���� ������ - ������� �������������, � � ����� ���� ��� ����, ����� �� ������� ���� ������ �����������, ����� ����. ����� �������������� � ����� � �����, ����������. ���� ����� �������� �������� - ��� ��������, ��� �� ���� ������ ������ ����� ���������.";
		link.l1 = "���, �������. ��������� � ����� ����� ������. ������, � �����.";
		link.l1.go = "Junglefort_bandit_exit";
		link.l2 = "�� ��, ��������! �� ��� �� ������ ���������, �� ���� ��� ���������!";
		link.l2.go = "Junglefort_bandit_2";
		break;
		
		case "Junglefort_bandit_exit":
		DialogExit();
		LAi_SetGuardianType(npchar);
		LAi_group_MoveCharacter(npchar, "PIRATE_CITIZENS");
		chrDisableReloadToLocation = false;//������� �������
		DoQuestReloadToLocation("Trinidad_Jungle_03", "reload", "reload4_back", "");
		break;
		
		case "Junglefort_bandit_2":
		dialog.text = "��, �� ��� ����������... ������, ���!!";
		link.l1 = "...";
		link.l1.go = "Junglefort_bandit_fire";
		break;
		
		case "Junglefort_bandit_fire":
		DialogExit();
		DoQuestCheckDelay("Gothic_JunglefortBanditsFire", 1.5);
		break;

		case "Junglefort_attack_0":
		DialogExit();
		NextDiag.CurrentNode = "Junglefort_attack";
		LAi_SetActorType(pchar);
		LAi_ActorFollow(pchar, npchar, "ActorDialog_Any2Pchar", -1);
		LAi_ActorTurnToCharacter(npchar, pchar);
		SetActorDialogAny2Pchar(npchar.id, "", 0.0, 0.0);
		break;
				
		case "Junglefort_attack":
	                  PlaySound("VOICE\Russian\GOTHIC\SVM\WHATSTHISSUPPOSEDTOBE.wav");

		dialog.text = "��, ��, ��� ���� ����� �����?";
		link.l1 = "...";
		link.l1.go = "Junglefort_attack_1";
		break;
		
		case "Junglefort_attack_1":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\HALLO_KILL.wav");

		dialog.text = "...";
		link.l1 = "� ������ ����� ����.";
		link.l1.go = "Junglefort_attack_2";
		break;
		
		case "Junglefort_attack_2":
	                  PlaySound("VOICE\Russian\GOTHIC\SVM\ALARM.wav");

		DialogExit();
	                  LAi_group_Delete("EnemyFight");
	                  sld = characterFromId("GMatt");
	                  LAi_SetWarriorType(sld);
	                  LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		LAi_SetPlayerType(pchar);
		for (i=1; i<=6; i++)
		{
		sld = characterFromId("Junglefort_bandit_"+i);
		LAi_RemoveCheckMinHP(sld);
		}
		if (pchar.questTemp.Gothic.JunglefortAttack == "soldiers")
		{
		sld = characterFromId("GMatt_sold_12");
		LAi_SetActorType(sld);
		LAi_ActorTurnToLocator(sld, "soldiers", "soldier1");
		LAi_ActorAnimation(sld, "shot", "Gothic_MineBanditDie", 1.0);
		}
		else
		{
		for (i=1; i<=6; i++)
		{
		sld = characterFromId("Junglefort_bandit_"+i);
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "EnemyFight");
		}
		LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("EnemyFight", "Gothic_BanditsDestroyed");
		AddDialogExitQuest("MainHeroFightModeOn");	
		}
                                    DoQuestFunctionDelay("Gothic_GMattJunglefortexitAttack_1", 12.0);
	                  break;





		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Henry_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "�����, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Henry_officer";
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
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ����. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
			link.l1 = "�������, �����! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
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