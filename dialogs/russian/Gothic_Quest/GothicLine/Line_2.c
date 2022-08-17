// ���������� ���� �� ���. �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;
	float locx, locy, locz;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
    switch (Dialog.CurrentNode)
    {
        case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
            link.l1.go = "exit";

//>>>>>>>>>>>>========= ������� �������� �� ���������� =====================

			if (npchar.id == "AnnaDeLeiva")// �����, ����� ���� � �������
            {
    			dialog.text = "����! ��� ���������? �� ������� �� �������� ��? ��� ��� ��� �� ���?";
    			link.l1 = "��������, �� ����, ��������� ��� ��� ��� ������� ��� ���, �� � ���"+ GetSexPhrase("","�") +" ��������"+ GetSexPhrase("","�") +" ����� ������ �������. � ��� ��� ������� �� ����������� � ��������, ����� ���������� ������! ������� �� � ����-��� ���� ���.";
    			link.l1.go = "Gothic_1";
            }

			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toHavana")// �����, �����
            {
    		             dialog.text = "�������� �� ����, �� ������ ����� ������ - �?";
    			link.l1 = "";
    			link.l1.go = "Gothic_2_1";
            }
			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_SeekHoseBrothers")
            {
    			dialog.text = "������������, ������"+ GetSexPhrase("","���") +". � ������ ��� - ����� ����� ���� ����� �� �������...";
    			link.l1 = "��� ����� � �������, ��������� ����, �� ������������.";
    			link.l1.go = "exit";
            }
			if (npchar.id == "InesDeLasCierras" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork")
            {
    			dialog.text = "�� ���, �������, ����� �������?";
    			link.l1 = "��� � �������, ������� � �������������� ����� ���� ����� �� ����������...";
    			link.l1.go = "Gothic_2_4";
            }


            if (npchar.id == "LoranDeGraf")// ����� �� ����, �����
            {
    			dialog.text = "�����"+ GetSexPhrase("�","���") +", ������ �� ����� ��� ����������! ���� ���.";
    			link.l1 = "��-��, � ����...";
    			link.l1.go = "exit";
            }
			if (pchar.questTemp.GothicLee == "SeekBible_WeWon" && npchar.id == "LoranDeGraf")// ����� �� ����, ����� 
            {
    			dialog.text = "� � ������� ������� ���������� ��� �� ������, �����"+ GetSexPhrase("�","���") +". �� ��������� ��� ������ �������. ��������� �������������, ���� ����� ����� �� ����.";
    			link.l1 = "����, � ��� ��� �����"+ GetSexPhrase("","�") +" ������� � ���� ������� � �������-�����, ����� �� �������.";
    			link.l1.go = "Gothic_3_10";
            }
            if (pchar.questTemp.GothicLee == "SeekBible_IHaveMap")
            {
    			dialog.text = "��� �������, ��� ���� ������ ���������, �����"+ GetSexPhrase("�","���") +".";
    			link.l1 = "�����, ���������.";
    			link.l1.go = "exit";
            }
            if (pchar.questTemp.GothicLee == "SeekBible_SeekMoney")
            {
    			dialog.text = "�� ��� ����� ������, �����"+ GetSexPhrase("�","���") +"?";
                if (sti(pchar.money) >= 235000)
                {
                    link.l1 = "��, ���"+ GetSexPhrase("��","��") +". � �����"+ GetSexPhrase("","�") +" �� �������� ����...";
        			link.l1.go = "Gothic_3_13";
                }
                else
                {
                    link.l1 = "��� ���, � � ������...";
        			link.l1.go = "exit";
                }
            }

            if (pchar.questTemp.GothicLee == "Francisco")// �����, ����� � ���������
            {
    			dialog.text = "��� �� � ����������, ����������� ����� ������� �����?";
    			link.l1 = "���... ������ ����� ��� �� ���� ����� � ��� ��� ������� �������?";
    			link.l1.go = "Gothic_4_1";
            }

			if (npchar.id == "Gorn" && pchar.questTemp.GothicLee == "RockBras_toSeekPlace")//�����, ����� � ������. 
            {
    			dialog.text = NPCStringReactionRepeat("��� ��� ��! ��� ��� ��������� �� �����?!", "��, ����� ��������� ��� ��������. ��� ��� �� �� ���"+ GetSexPhrase("��","��") +", ����"+ GetSexPhrase("�","���") +" ������ �������?", "���������? ��� ��� �� ���"+ GetSexPhrase("��","��") +"?", "��, ����� �������� ��� ��������. ��� �� ���"+ GetSexPhrase("��","��") +"?", "block", 0, npchar, Dialog.CurrentNode);
    			if (LAi_group_GetTarget(pchar) <= 3)
				{
					link.l1 = HeroStringReactionRepeat("� �������"+ GetSexPhrase("��","���") +". ����� ���� "+GetFullName(pchar)+". � ����"+ GetSexPhrase("��","��") +", ����� �������� ���� ������.", "����� ���������... ���� ����� "+GetFullName(pchar)+", � ����"+ GetSexPhrase("��","��") +" �� �����.", "���� ����� "+GetFullName(pchar)+", � ����"+ GetSexPhrase("��","��") +" �� �����.", "����� ��������, �� ������. ���� ����� "+GetFullName(pchar)+", � ����"+ GetSexPhrase("��","��") +" �� �����.", npchar, Dialog.CurrentNode);
    				link.l1.go = "Gothic_5_1";
				}
				else
				{
					link.l1 = "������ �� ����� ��������, ���� ����������� �� ����� � ���� �����!";
    				link.l1.go = "Gothic_5_Late";
				}
				// --> ���� �������...
				if (GetQuestPastDayParam("questTemp") > 12)
				{
    				dialog.text = "��� ��?..";
    				link.l1 = "��, � � ����"+ GetSexPhrase("��","��") +" �� �����, ���� ������ ��...";
    				link.l1.go = "Gothic_5_8";
				}
				else SaveCurrentQuestDateParam("questTemp"); //����� �� �������� �� ����� ���
				// <-- ���� �������...
            }
			if (npchar.id == "Gorn" && pchar.questTemp.GothicLee == "empty")//����� , ����� � ������ � ���������� ��. 
            {
    			dialog.text = ""+pchar.name+", � ��� �� ���� ����������� ������������� ����.";
    			link.l1 = "��� � �������, �������...";
    			link.l1.go = "Gothic_5_5";
            }

			if (npchar.id == "CaptainGay")//����, ����� � ����� ����. 
            {
    			dialog.text = "�� ��� ���"+ GetSexPhrase("��","��") +"?";
    			link.l1 = "�������, ��� �. ���� ������ �� ���������� ��������. �� ����� ����� ������������� � ����� ������� ��������.";
    			link.l1.go = "Gothic_6_1";
            }			

		break;
//<<<<<<<<<<<<===== ������� �������� �� ���������� =====================
        case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;


//********************************* ��������� ����� ����. ����� �3 **********************************
 		case "Gothic_1":
			dialog.text = "���� �����... ����� �������, � ����� �� ������... �� ����� ������, ������� � ������ ���, � ����� ���� �����...";
			link.l1 = "� ����, �������, �������"+ GetSexPhrase("��","���") +"... � ����� ��� ��������� �� ����. ������ �����������, ��������...";
			link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_HavanaOut";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1 = "location";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1.location = "Cuba2";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition = "GothicLeeTakeAnna_DelivShip";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

//********************************* �������� ����� ����. ����� **********************************
 	              case "Gothic_2_1":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ADD_17_19.wav");
		dialog.text = " ������"+ GetSexPhrase("","���") +", ��� ��? � ��� ��� ����� � ���� ����?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_001";
		break;

 		case "Gothic_2_001":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_4.wav");
		dialog.text = "";
		link.l1 = "� ��������� � ��� � ������"+ GetSexPhrase("","�") +" ���� �� ��������� ����� ����, ����� �������. ��������� ��� ��������, �� ��������� �� � ����� ���������...";
    		link.l1.go = "Gothic_2_002";
		break;

 	              case "Gothic_2_002":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ADD_17_22.wav");
		dialog.text = "�� ������ ��� � �� ����?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_003";
		break;

 	              case "Gothic_2_003":
	               PlaySound("VOICE\Russian\gotica\HANNA\DIA_HANNA_ANYNEWS_17_01.wav");
		dialog.text = "��� ������-�� ������� ��� ���� �� ����� ������� �������� ������ �����?";
		link.l1 = "";
    		link.l1.go = "Gothic_2_004";
		break;

 	              case "Gothic_2_004":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_2.wav");
		dialog.text = "";
		link.l1 = "�, � �����!!!";
    		link.l1.go = "Gothic_2_005";
		break;

 		case "Gothic_2_005":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_STANDARD_16_02.wav");
		dialog.text = "� ����� �� ���� ���������� �����, �� �� �����!!! ����� ��� ����� ������������, ����� ���������� �� ����, ��� �� ����.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_006";
		break;

 		case "Gothic_2_006":
	                PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
		dialog.text = "";
		link.l1 = "������.";
    		link.l1.go = "Gothic_2_007";
		break;

 		case "Gothic_2_007":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload3", "GothicLee_InesDeLasCierras", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

 		case "Gothic_2_03":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_15_00.wav");
		dialog.text = "";
		link.l1 = "�� � ������, �� ����� ����������?";
    		link.l1.go = "Gothic_2_04";
		break;

 		case "Gothic_2_04":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_16_01.wav");
		dialog.text = "��, ����� ��� �� ����������.";
		link.l1 = "�, �� ������ ������ ����������� ���������?";
    		link.l1.go = "Gothic_2_05";
		break;

 		case "Gothic_2_05":
		dialog.text = "��, ��� ���. ������"+ GetSexPhrase("","���") +", ����� �� ����� ������ ����������� ���������! �������-���������� ������ ��� ���� �� ������� ���������� ������������� �� ����� ������ � ������� ��� �������������� ������� ����� ���� �� ���������.\n"+
				         "���, ��� �� �����, �� ������� ������������� ������� ���� ����. � ��� ���� ������� �� ����� - ������� ���������� ������������ ����. �� ������� ����� ����� ���� ������ ����������� �� ���� ����������.";
			link.l1 = "�� ��������� �� �� ���������...";
    		                     link.l1.go = "Gothic_2_06";
		break;

 		case "Gothic_2_06":
			dialog.text = "����������, ������"+ GetSexPhrase("","���") +". ���� ��� ������� ���������� ������ ���� ����. ��� �������� �� ������, � �������� ���, ��� ��������� ����������. ����� ����������� �������� �������� �����, ��� �� ������� ��� ������!";
			link.l1 = "��, ������� � �� �� ������, ���� ���� ���������� ����������� ��������. �� ����������, ��� � ���� �� �����?";
    		                     link.l1.go = "Gothic_2_07";
		break;

 		case "Gothic_2_07":
			dialog.text = "����� ��� ����������� � �������, � ������ �� ���. �� ���� ���������, ��� ���������� ��������� � ����������������, ����� ������� ���������� �� ���������.";
			link.l1 = "���� ������ ����������� �� � ��������! ���� ��� ������ ��������� � �����, ��� �������� ������� �� ���� ��������� ����������. ������� ���, ��������� ����. � ������� �� �����"+ GetSexPhrase("","�") +" � ������� ������, �� ��, �������� �������, ������� ���� � ��������.";
    		                     link.l1.go = "Gothic_2_08";
		break;

 		case "Gothic_2_08":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_SONST_16_06.wav");
			dialog.text = "�� ������ ������������ ����� ��� ��� ������!";
			link.l1 = "";
    		                   link.l1.go = "Gothic_2_Sex";
		break;

 		case "Gothic_2_Sex":
			dialog.text = "";
			link.l1 = "�����, ��!!!";
    		                   link.l1.go = "Gothic_2_YesSex";
			link.l2 = "������� �� ��� ����� ����...";
    		                   link.l2.go = "Gothic_2_NoSex";
		break;

 		case "Gothic_2_NoSex":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_WEITER_15_00.wav");
			dialog.text = "";
			link.l1 = "������� �� ��� ����� ����...";
    		                   link.l1.go = "Gothic_2_NoSex_1";
		break;

 		case "Gothic_2_NoSex_1":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_ADDON_NADJA_LUCIAINFO_WEITER_16_01.wav");
			dialog.text = "����� ����, �� ���� ����� � ������ ���.";
			link.l1 = "";
    		                   link.l1.go = "Gothic_2_NoSex_exit";
		break;

 		case "Gothic_2_NoSex_exit":
                                      PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_SeekHoseBrothers";
		AddQuestRecord("GothicLee_2_KillAnnaHanters", "3");	
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex", GetSexPhrase("","�"));
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex1", GetSexPhrase("��","��"));
		
		npchar.LifeDay = 1; // ������ ���
		SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
		locations[FindLocation("Mayak10")].DisableEncounters = true; //��������� �������
		LAi_LocationDisableOfficersGen("Mayak10", true); //�������� �� �������
		Pchar.quest.GothicLeeAnna_InShore.win_condition.l1 = "location";
			Pchar.quest.GothicLeeAnna_InShore.win_condition.l1.location = "Mayak10";
		Pchar.quest.GothicLeeAnna_InShore.win_condition = "GothicLeeAnna_InShore";
		break;



 		case "Gothic_2_YesSex":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_7.wav");
		dialog.text = "";
		link.l1 = "�����, ��!!!";
    		link.l1.go = "Gothic_2_YesSex_1";
		break;

 		case "Gothic_2_YesSex_1":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_HOCHGEHEN_16_01.wav");
		dialog.text = "������� ���� ����� ���������� ����� - �����, �����!!!";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_2";
		break;

 		case "Gothic_2_YesSex_2":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_POPPEN_16_00.wav");
		dialog.text = "��������� ���� ����� ����������� ������ ���.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_3";
		break;

 		case "Gothic_2_YesSex_3":
	               PlaySound("VOICE\Russian\gotica\NADJA\DIA_NADJA_POPPEN_16_01.wav");
		dialog.text = "����������, ������ � ������� ������������.";
		link.l1 = "";
    		link.l1.go = "Gothic_2_YesSex_4";
		break;

 		case "Gothic_2_YesSex_4":
		sld = CharacterFromID("InesDeLasCierras");
		LAi_SetActorType(sld);
		LAi_ActorTurnToCharacter(sld, pchar);
                                      pchar.GenQuest.BrothelCount = 0;
   		AddDialogExitQuest("PlaySexx_1");
		NextDiag.CurrentNode = "Gothic_2_09";
		DialogExit();
		break;

 		case "Gothic_2_09":
		dialog.text = "��...�� ����� �����������, �����...";
		link.l1 = "���, ����...";
    		link.l1.go = "exit";
		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_SeekHoseBrothers";
		AddQuestRecord("GothicLee_2_KillAnnaHanters", "3");	
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex", GetSexPhrase("","�"));
		AddQuestUserData("GothicLee_2_KillAnnaHanters", "sSex1", GetSexPhrase("��","��"));
		
		npchar.LifeDay = 1; // ������ ���
		SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
		locations[FindLocation("Mayak10")].DisableEncounters = true; //��������� �������
		LAi_LocationDisableOfficersGen("Mayak10", true); //�������� �� �������
		Pchar.quest.GothicLeeAnna_InShore.win_condition.l1 = "location";
			Pchar.quest.GothicLeeAnna_InShore.win_condition.l1.location = "Mayak10";
		Pchar.quest.GothicLeeAnna_InShore.win_condition = "GothicLeeAnna_InShore";
		break;

 		case "Gothic_2_4":
		dialog.text = "���, ��� ����� ������. ������ ����� ���� ����� ����� ��������� ��������...";
		link.l1 = "�������, ��� ��.";
    		link.l1.go = "exit";
		break;

//********************************* ����� ������. ����� **********************************

		case "Gothic_3_10":
			dialog.text = "��� �� � ��� � ���� ������?";
			link.l1 = "���� ����� " + GetFullName(pchar) + ", � �����"+ GetSexPhrase("","�") +" �� ������ � ��� �����, ������� �� ���������� � ������� � �������� ������.";
			link.l1.go = "Gothic_3_11";
    	break;
		case "Gothic_3_11":
			dialog.text = "�-�-�, ��� ���? ������, ��� ����� ��������. ����� ��������� ���������, �� � ���� ������ ����� ����������� ������� ������ � ������, ��� ����� �������� ��� ���, �� � ��� ��� ����� �� �����������\n�������� � ���, ��� ��� ����� ������� ������� � �������� ������, �������� ������ ��� �� �������, � ����� � ���������� ������ ������ � ���� ������\n��� ������ ������� ���� � ���������� ����������, �������� ���������� ������� �������� ������� ������ �� ���������, ��� ������ �� �� ������..., �� � ��������� �� ����� ������� ����� ������, ��� ��� ���� ������� ������ �����\n��� ���, ��������� ������� ������, � ������ ����� ������: �� ������� ��� 235 �����, � � ��� ���� ���� ��������� � ������� ����� ����������� ������� ������.";
			link.l1 = "� �� ������� �� ����� - 235 �����?";
			link.l1.go = "Gothic_3_12";
    	break;
		case "Gothic_3_12":
			dialog.text = "���. ���� � ���, ��� �� ���� ������������ � ��� ������ ��� ���-��� �����. ��� ��� ��� ���� �� ������ � ������, �� � �� ���� ����!";
            if (sti(pchar.money) >= 235000)
            {
                link.l1 = "��������. ��� ���� ������!";
    			link.l1.go = "Gothic_3_13";
    			AddMoneyToCharacter(pchar, -235000);
            }
            else
            {
                link.l1 = "���, ����� ����� � ���� ������ ���. �������� ��������� � ���� �����.";
    			link.l1.go = "Gothic_3_15";
            }
    	break;
		case "Gothic_3_13":
			dialog.text = "�������� �������� ���������. ��������, ��� ��� ������������ �� ����� ������� �����? ���� ��� ����, ����� ���, ����� �� ����?";
			link.l1 = "��, �������� �����������!";
			link.l1.go = "Gothic_3_14";
                                                              GiveItem2Character(pchar, "LegransMap");
    	break;
		case "Gothic_3_14":
			dialog.text = "��-��, ���������! ��� �, �������� ������ ��� ��� �����, �����.";
			link.l1 = "��� �����. � ��������"+ GetSexPhrase("��","��") +" ����, ����� �� ����. �������, ��� ��������.";
			link.l1.go = "exit";
            AddQuestRecord("GothicLee_3_SeekBible", "9");
            NPChar.LifeDay = 2;
    	    SaveCurrentNpcQuestDateParam(NPChar, "LifeTimeCreate");
            pchar.questTemp.GothicLee = "SeekBible_IHaveMap";
            pchar.questTemp.GothicLee = "SeekBible_crypt";
            pchar.GenQuestBox.FortFrance_crypt = true;
            pchar.GenQuestBox.FortFrance_crypt.box3.items.jewelry5 = 200;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry17 = 300;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.blade_32 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.q_blade_10 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.mushket5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.cirass5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potion2 = 5;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.clock2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry7 = 5;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.obereg_10 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potion2 = 10;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.potionwine = 3;
			                                                                       pchar.GenQuestBox.FortFrance_crypt.box4.items.recipe_totem_07 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry2 = 30;		
            pchar.GenQuestBox.FortFrance_crypt.box4.items.jewelry3 = 60;		
            pchar.GenQuestBox.FortFrance_crypt.box4.items.talisman2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.chest = 5;
			                                                                                    pchar.GenQuestBox.FortFrance_crypt.box4.items.icollection = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.amulet_9= 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_6 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_11 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_5 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_2 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box4.items.indian_8 = 1;
            pchar.GenQuestBox.FortFrance_crypt.box2.items.Bible = 1;
            pchar.GenQuestBox.FortFrance_crypt.box2.items.sextant3 = 1;

           DoQuestCheckDelay("SeekBible_FortFrance_Graveyard", 3.5);
        break;
		case "Gothic_3_15":
			dialog.text = "���������, �����"+ GetSexPhrase("�","���") +". �� ������� ����� ���� �� ������� � �������.";
			link.l1 = "������, ����� ���� � ����, ���.";
			link.l1.go = "exit";
			pchar.questTemp.GothicLee = "SeekBible_SeekMoney";
			              pchar.quest.SeekBible_DeGrafToTavern.win_condition.l1 = "MapEnter";
              pchar.quest.SeekBible_DeGrafToTavern.win_condition = "SeekBible_DeGrafToTavern";
    	break;

//*************************** �����, ������� � ��������� ***************************

 		case "Gothic_4_1":
			dialog.text = "� ����, ���� �������������, ������ �� �������, � ����� � ���� ����� ��������! ��-��, ��� ������ ��������, ������� ����� �� �� �������.";
			link.l1 = "���� � ���� �������� ��� �, ��� �� ��� ���� ����� ���������� �������� ����, �� ��� ��, ��� ��� ����?";
			link.l1.go = "Gothic_4_2";
		break;
 		case "Gothic_4_2":
			dialog.text = "� ��� ����� �� ����������, ��� ��� ���, ���� ����� � ���� �������, ������� ����� ���� ��� �� �����, �� ����� � ����� ������ �� ������ ������ ���� �� ����� �������.";
			link.l1 = "�� ����� �������, ������� �� � ��� �� ������� �����, ����� �� ��� ���� ������ ��������� �� ��� ��?!";
			link.l1.go = "Gothic_4_3";
		break;
 		case "Gothic_4_3":
			dialog.text = "����� �� ���� ����, ���� ��������, ��� ���������� �� ����� �� ������ ����. �� ������� ��� � ����� � ����� ������� ������ ����, ������� ��� �� ��������� ������� � ������������ �������, � � ��� ������ ������, ��� ������� �������� ����� �� ��� ���.";
			link.l1 = "����� ��� �� ������?";
			link.l1.go = "Gothic_4_4";
		break;
 		case "Gothic_4_4":
			dialog.text = "���� ��� ����� ��� ������� ���� ���������� ��������� ��������� ������� ���������, � ��� ���� ������ ����� �������, ���� ������������� ���� ��������� ������� ��� ������� ����� ������, � ����� ������� ���� ������� � �������� �� �����������.";
			link.l1 = "�...";
			link.l1.go = "Gothic_4_5";
		break;

 		case "Gothic_4_5":
			dialog.text = "�� ���� � ����� ����� ��������, ������� ������ ��� �� �����������, �� ����� ���������� ���������� �����, ��� ��� �� ���, ��� �� ��� � ��������� � ����� ������� ���������, � �������, � ������ ������, � �� ��� �� ��� ���������, � ������ ������.";
			link.l1 = "����...� ��� �� ������� ������?";
			link.l1.go = "Gothic_4_6";
		break;

 		case "Gothic_4_6":
			dialog.text = "������ �� ����.";
			link.l1 = "";
			link.l1.go = "Gothic_4_7";
		break;

 		case "Gothic_4_7": // � ���������
		chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload9", "Monkey", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "Monkey_1":
			dialog.text = "����, ����� ���� ��������, ������ �� ��� �� �� ��������, �������� ������, �� ��� ����� ��������� �������� ������, �� ��� �����. ������ ���� ������...";
			link.l1 = "";
			link.l1.go = "Gothic_4_8";
		break;

		case "Gothic_4_8": // � �������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload10", "skeleton", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "skeleton_1":
			dialog.text = "��� ��� ���� ������, �� ��� �� �������� �������� ����� ��������, ������� �� ��� ������������ ����������� ����� ����, ���� ������.";
			link.l1 = "";
			link.l1.go = "Gothic_4_9";
		break;

		case "Gothic_4_9": // � ����
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload12", "Orc", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "Orc_1":
			dialog.text = "� ��� ��� ����� ���������� ��� �� ��������, ����� �� ����������?";
			link.l1 = "";
			link.l1.go = "Orc_2";
                                                         DoQuestFunctionDelay("ORC_AMBIENT_SHORT", 0.4);
		break;

		case "Orc_2":
			dialog.text = "";
			link.l1 = "��� ���������? ��� ���, ������ �� ��� ������ ��������, ���������� �� ��� ������� ������ ����, ������ �� � ���?";
			link.l1.go = "Orc_3";
		break;

		case "Orc_3":
			dialog.text = "��� ������� �� ������ �� ������, ������ �� �� ����, ������ � ��!";
			link.l1 = "";
			link.l1.go = "Orc_4";
		break;

		case "Orc_4":
			dialog.text = "";
			link.l1 = "��, ������.... ��!";
			link.l1.go = "Gothic_4_10";
		break;

 		case "Gothic_4_10": // � ������
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(npchar, "reload", "reload30", "Francisco_gate", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;

		case "gate_1":
			dialog.text = "� �� �� �����, ������� ����, ��� ����� ����������, ����, ������, �� � �������� ��������, ������� ������ �� ����������, ��� ��� ��� �� �������� ��� ���.";
			link.l1 = "���...";
			link.l1.go = "gate_2";
		break;

		case "gate_2":
			dialog.text = "� �� �� ����? ������ ��� ����, ��� �� ���� �������, �� ���� ��� �� ���������.";
			link.l1 = "��� ��?";
			link.l1.go = "gate_3";
		break;

		case "gate_3":
			dialog.text = "� �������� ���, ��� �� ������� ���� �� ����. � ��� ������� ����, ��� � �����, � ������ ��� �� ���� ������� ��� ������� ���� ��� �� �������, �� ���� ������ ������� ��������.";
			link.l1 = "";
			link.l1.go = "Gothic_4_11";
		break;

 		case "Gothic_4_11":
		      chrDisableReloadToLocation = false;
		      pchar.questTemp.GothicLee = "Inquisition_afterFrancisco";
                                          LAi_SetActorType(npchar);
                                          LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 40.0);
                                          LAi_SetPlayerType(pchar);
                                          DoQuestCheckDelay("Berglars_Dexter1", 5.5);
     DialogExit();
	int n = Findlocation("Graveyard_church");
	Locations[n].reload.l1.name = "reload1_back";
	Locations[n].reload.l1.go = "Shore111";
	Locations[n].reload.l1.emerge = "reload1_back";
	Locations[n].reload.l1.autoreload = "1";
	locations[n].reload.l1.label = "Shore111";
	locations[n].locators_radius.reload.reload1_back = 2;
	int nn = Findlocation("Shore111");
	Locations[nn].reload.l1.name = "reload1_back";
	Locations[nn].reload.l1.go = "Graveyard_church";
	Locations[nn].reload.l1.emerge = "reload1";
	Locations[nn].reload.l1.autoreload = "1";
	Locations[nn].locators_radius.reload.reload1_back = 3.0;
		break;

//********************************* ���������� �����. ����� **********************************
 		case "Gothic_5_1":
    		if (LAi_group_GetTarget(pchar) <= 0)
			{
	           PlaySound("VOICE\Russian\gotica\GORN\GORNDJG_HALLO_01.wav");
				dialog.text = "� ��� � ��������, "+ GetSexPhrase("��������","�������") +". �� ���� � �� ����, �����, �� �������, ��� ���� ���� ��������?";
				link.l1 =  "�� ��� ����, ��� ������� ��. �������, �� ������, ��� ���... �� �����, ������ ����� ��������� ������ �� �������, ��� ���� � ����-���. �� ������ ������� ������?";
    			link.l1.go = "Gothic_5_2";
			}
			else
			{
				dialog.text = "� ����� ���...";
				link.l1 = "��������� �����, ���� ����������� ��� �� �����...";
    			link.l1.go = "Gothic_5_Late";
			}
		break;
 		case "Gothic_5_2":
    		if (LAi_group_GetTarget(pchar) <= 0)
			{
				dialog.text = "���, ���. ������� ������ ���� ���������� ��� ����...";
				link.l1 =  "��� �����... ����� ������ �� ���� �� ����� - ����� �����������.";
    			link.l1.go = "Gothic_5_3";
			}
			else
			{
				dialog.text = "���, ���...";
				link.l1 = "��������� �����, ���� ����������� �� ����� �����!";
    			link.l1.go = "Gothic_5_Late";
			}
		break;
 		case "Gothic_5_3":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNDJG_01.wav");
			dialog.text = "������, ��� �������. � ���� ����� �������...";
			link.l1 = "����� ������, ������! � �� ��������.";
    		link.l1.go = "Gothic_5_4";
		break;
 		case "Gothic_5_4":
			bDisableFastReload = false;
			AddQuestRecord("GothicLee_5_RockBras", "2");
			AddQuestUserData("GothicLee_5_RockBras", "sSex", GetSexPhrase("��","��"));
			Pchar.quest.RockBras_DelivShip.win_condition.l1 = "location";
			Pchar.quest.RockBras_DelivShip.win_condition.l1.location = "Cuba1";
			Pchar.quest.RockBras_DelivShip.win_condition = "RockBras_DelivShip";
			LAi_SetActorType(npchar);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;
 		case "Gothic_5_5":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNNW_02.wav");
			dialog.text = "��������, � ���� ���� ������������� �� �������� ���� �����. �������� ������ �� ���� - � ������ ������ �������� ����� � ����� �������.\n"+
				          "�� � ���� ���� ���� ������, ������� ������ ��� ������� ������� ������, ��� ������.";
			link.l1 = "������������ �� ����, ��� �����, ��� ��� ����� ���������...";
    		link.l1.go = "Gothic_5_6";
		break;
		case "Gothic_5_6":
	           PlaySound("VOICE\Russian\gotica\GORN\GORNNW_03.wav");
            dialog.text = "� �����, ������ ���� �����������... ��� ������� ���� �� �����, ��� �� ���������, ���� ���������� � ����. � ���� ���������� � ���� ���������� ���� ����� ������ � ������ ������ ����� �������...\n"+
				          "��� ��� - �������� �� ����, ���"+ GetSexPhrase("","�") +" �������... � �����, � ���� ���� ��, ��� �� ��� �������.";
			link.l1 = "������, ��������� �������, ����� ������... �� �� �����, �������� ���� � ���� �� ������. ������������� ����...";
            link.l1.go = "Gothic_5_7";
        break;
		case "Gothic_5_7":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 10.0);
			DeleteAttribute(npchar, "RebirthPhantom");
         	                                npchar.LifeDay = 0; // ������ ���
			pchar.GenQuestRandItem.FortFrance_Graveyard_Dungeon = true;
			pchar.GenQuestRandItem.FortFrance_Graveyard_Dungeon.randitem3 = "cirass4";
			DialogExit();
		                DoQuestCheckDelay("Gorn_tavern", 15.0);
        break;
 		case "Gothic_5_8":
			dialog.text = "�� �������"+ GetSexPhrase("","�") +"... ��� ��� ������ ��� ������ ����... ������... ���� ��� ����� �� ������... �-�-���...";
			link.l1 = "���� ������, �� ����!";
    		link.l1.go = "Gothic_5_9";
		break;
 		case "Gothic_5_9":
			bDisableFastReload = true;
			LAi_KillCharacter(npchar);
			DeleteAttribute(npchar, "RebirthPhantom");
         	                                npchar.LifeDay = 0; // ������ ���
			pchar.questTemp.GothicLee = "RockBras_RockIsAgony";
			DialogExit();
		break;
 		case "Gothic_5_Late":
			bDisableFastReload = true;
			LAi_ActorWaitDialog(npchar, pchar);
			DialogExit();
		break;

//********************************* �������� ���� ��������. ����� **********************************
        case "Gothic_6_1":
            dialog.text = "���, ���� �������� ��� �� ����� ������ �� ���� � �������� ����� �����������! �������, ���� ����, ������ ��� ������� � ��, ������ ������� ���, ��� ���� �������, ��� �������...";
            link.l1 = "������. �������� �����, �������...";
            link.l1.go = "Gothic_6_2";
        break;
 		case "Gothic_6_2":
			chrDisableReloadToLocation = true;
			LocatorReloadEnterDisable("PortRoyal_tavern", "reload2_back", true);
            LAi_group_MoveCharacter(npchar, "EnemyFight");
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "CanFightCurLocation");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;


	}
}
