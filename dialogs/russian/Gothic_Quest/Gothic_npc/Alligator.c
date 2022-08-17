// ��������� ����
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, n, iTemp, amount;
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

	//---------------------------------------- ������ �������------------------------------------------------
		case "First time":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_15_00.wav");
            	dialog.text = "";
        	link.l1 = "��� �� �����?";
        	link.l1.go = "Alligator_1";
		break;

		case "Alligator_1":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_12_01.wav");
            	dialog.text = "������ �� ��� ��� ������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_2";
		break;

		case "Alligator_2":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_12_02.wav");
            	dialog.text = "� ��������� ����.";
        	link.l1 = "";
        	link.l1.go = "Alligator_3";
		break;

		case "Alligator_3":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_12_03.wav");
            	dialog.text = "���� ������ ������ ���� ������, � ���� �� ����� ������� ������� � ���� �����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_4";
		break;

		case "Alligator_4":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_12_04.wav");
            	dialog.text = "� ����� � ��������� ������ �� �������� ������� ���������� �������� ��� � ���� ���������.";
        	link.l1 = "";
        	link.l1.go = "Alligator_5";
		break;

		case "Alligator_5":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_WERBISTDU_12_05.wav");
            	dialog.text = "���, ��� ������ �� �������������� � ����� ��������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_6";
		break;

		case "Alligator_6":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_15_00.wav");
            	dialog.text = "";
        	link.l1 = "�������� ��� ������ � �������!";
        	link.l1.go = "Alligator_7";
		break;

		case "Alligator_7":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_THEHUNT_RUNNING_12_01.wav");
            	dialog.text = "������������. ������������ � ����� ������, ���������.";
        	link.l1 = "";
        	link.l1.go = "Alligator_8_exit";
		break;

		case "Alligator_8_exit":
		DialogExit();
		LAi_SetActorType(pchar);
		LAi_ActorGoToLocator(pchar, "goto", "goto3", "Gothic_Alligator", -1);
	                   DoQuestFunctionDelay("Gothic_Alligator", 1.0);
		break;

		case "Alligator_9":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_12_02.wav");
            	dialog.text = "���� ��� ������ ����� ������ ���� � ������ �������� �� �������� ��������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_10";
		break;

		case "Alligator_10":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_12_03.wav");
            	dialog.text = "�� �� ������� ������, ��� ��������� ������ ��� �� ����������� ������� � �������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_11";
		break;

		case "Alligator_11":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_12_04.wav");
            	dialog.text = "������� ���� � �������� ����� ���������� �� ������ ��������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_12";
		break;

		case "Alligator_12":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_12_05.wav");
            	dialog.text = "� ��������� ������ ����� � ������ � ���� ����� �� ��������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_13";
		break;

		case "Alligator_13":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_PIRATES_12_06.wav");
            	dialog.text = "������� �� ������� �������� ���!";
        	link.l1 = "";
        	link.l1.go = "Alligator_14";
		break;

		case "Alligator_14":
            	dialog.text = "";
        	link.l1 = "� ��� �� ��������� � ������� �����!";
        	link.l1.go = "Alligator_15";
		break;

		case "Alligator_15":
            	dialog.text = "� ������! ��� ��������.";
        	link.l1 = "";
        	link.l1.go = "Alligator_16_exit";
		break;

		case "Alligator_16_exit":
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Alligator_7");
		break;

		case "Alligator_16":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
            	dialog.text = "";
        	link.l1 = "������...";
        	link.l1.go = "Alligator_17";
		break;

		case "Alligator_17":
	PlaySound("interface\_GTTown2.wav");
            	dialog.text = "��� �� �����!";
        	link.l1 = "�������, ���������.";
        	link.l1.go = "Alligator_18";
		break;

		case "Alligator_18":
	PlaySound("interface\_GTBoard2.wav");
            	dialog.text = "������� �� �����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_19";
		break;

		case "Alligator_19":
	PlaySound("interface\_GTBoard0.wav");
            	dialog.text = "����� � �����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_20";
		break;

		case "Alligator_20":
	PlaySound("interface\_EvEnemy0.wav");
            	dialog.text = "�������� ���� �� ����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_21";
		break;

		case "Alligator_21":
	PlaySound("interface\_EvLand1.wav");
            	dialog.text = "�����!";
        	link.l1 = "����������, �� �����.";
        	link.l1.go = "Alligator_22";
		break;

		case "Alligator_22":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HELLO_12_04.wav");
            	dialog.text = "�������� ����� � ����� ������� ����������� ����� � ��������?";
        	link.l1 = "";
        	link.l1.go = "Alligator_23";
		break;

		case "Alligator_23":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HELLO_12_00.wav");
            	dialog.text = "��� ���� ����� �� �����, �� �� ����� �� ���������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_24";
		break;

		case "Alligator_24":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HELLO_12_03.wav");
            	dialog.text = "�� ���� �� �� �������� - ���!";
        	link.l1 = "";
        	link.l1.go = "Alligator_25";
		break;

		case "Alligator_25":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HELLO_15_01.wav");
            	dialog.text = "";
        	link.l1 = "����� ��� ���������?";
        	link.l1.go = "Alligator_26";
		break;

		case "Alligator_26":
            	dialog.text = "���, ���?";
        	link.l1 = "";
        	link.l1.go = "Alligator_27_exit";
		break;

		case "Alligator_27_exit":
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Alligator_8");
		break;

		case "Alligator_30":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_6.wav");
            	dialog.text = "";
        	link.l1 = "��, ���?";
        	link.l1.go = "Alligator_31";
		break;

		case "Alligator_31":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_LETSGOHUNTING_12_01.wav");
            	dialog.text = "�������, ����� �� � �������� � ���� ���������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_32";
		break;

		case "Alligator_32":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_LETSGOHUNTING_12_02.wav");
            	dialog.text = "�� �����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_33";
		break;

		case "Alligator_33":
 	PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_3.wav");
            	dialog.text = "";
        	link.l1 = "���, ��� ����� ������!";
        	link.l1.go = "Alligator_34";
		break;

		case "Alligator_34":
		GiveItem2Character(pchar, "blade49");
		PlaySound("interface\important_item.wav");
		Log_Info("�� �������� ������ '����� ����������'");
		LAi_SetImmortal(pchar, true);
		sld = ItemsFromID("blade49");
		sld.Weight = 1.7;
		sld.price = 10000;
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_THEHUNT_12_05.wav");
            	dialog.text = "���� ���� ������ ����� �� ������ �� ����. ���� ������� � ���� ���� ���� ������.";
        	link.l1 = "�������. ������, �� ���� ������.";
        	link.l1.go = "Alligator_35";
		break;

		case "Alligator_35":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\GG_WHERE_YES_1.wav");
        	                  link.l1 = "�������. ������, �� ���� ������.";
        	                  link.l1.go = "Alligator_36_exit";
		break;

		case "Alligator_36_exit":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_LETSGOHUNTING_YES_12_01.wav");
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Alligator_12");
		break;



	case "killVaterSkel":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_TEACH_FUR_12_00.wav");
                    if(sti(pchar.quest.VaterSkel_Dead) >= 1)
	{
            	dialog.text = "������ ����� ������ �� ������, ����� �� ��������� �����...";
        	link.l1 = "...";
	link.l1.go = "Alligator_35";
	}
	else
	{
            	dialog.text = "������ ����� ������ �� ������, ����� �� ��������� �����...";
        	link.l1 = "...";
	link.l1.go = "Alligator_killVaterSkel";
	}
	break;

		case "Alligator_35":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_01.wav");
            	dialog.text = "�� �� ���� �� ����� �������� �����!!!";
        	link.l1 = "";
        	link.l1.go = "Alligator_36";
		break;

		case "Alligator_36":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_02.wav");
            	dialog.text = "�� �����, �������� �� ���� � ������ ����� - ������ ����!";
        	link.l1 = "";
        	link.l1.go = "Alligator_37";
		break;

		case "Alligator_37":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_18.wav");
            	dialog.text = "";
        	link.l1 = "��, � �������...";
        	link.l1.go = "Alligator_38";
		break;

		case "Alligator_killVaterSkel":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_03.wav");
            	dialog.text = "�������, ����� ������� ��� �� ����� ��� �����������!!!";
        	link.l1 = "...";
        	link.l1.go = "Alligator_killVaterSkel_1";
		break;

		case "Alligator_killVaterSkel_1":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_04.wav");
            	dialog.text = "�� ������ �� ����� �� ����� ������ �����, ����� ������!";
        	link.l1 = "...";
        	link.l1.go = "Alligator_killVaterSkel_2";
		break;

		case "Alligator_killVaterSkel_2":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_05.wav");
            	dialog.text = "� �� ������� �������!";
        	link.l1 = "...";
        	link.l1.go = "Alligator_killVaterSkel_3";
		break;

		case "Alligator_killVaterSkel_3":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_HUNTEND_12_06.wav");
            	dialog.text = "����, ���� �� � ������ ������ ��� ��������, ���������� ��� � ����� �������� � ������!";
        	link.l1 = "...";
        	link.l1.go = "Alligator_killVaterSkel_4";
		break;

		case "Alligator_killVaterSkel_4":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_KOMMMIT_15_00.wav");
            	dialog.text = "...";
        	link.l1 = "������������� �� ���...";
        	link.l1.go = "Alligator_hired_00";
                   TakeNItems(pchar, "Rumm", 2);
                   Log_Info("�� �������� ��� ��������� ����");
                   PlaySound("interface\important_item.wav");
		break;


		case "Alligator_38":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_BESSER_12_00.wav");
            	dialog.text = "�����, � ���� � ���� ���� ������ �����������!";
        	link.l1 = "";
        	link.l1.go = "Alligator_39";
		break;

		case "Alligator_39":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_30.wav");
            	dialog.text = "";
        	link.l1 = "��� �� ������ � ����?";
        	link.l1.go = "Alligator_40";
		break;

		case "Alligator_40":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_BESSER_12_01.wav");
            	dialog.text = "������������� � ���...";
        	link.l1 = "";
        	link.l1.go = "Alligator_hired";
                   TakeNItems(pchar, "Rumm", 1);
                   Log_Info("�� �������� ��������� ����");
                   PlaySound("interface\important_item.wav");
		break;
				
		case "Alligator_hired":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_BESSER_12_03.wav");
			dialog.text = "� ����� �� ���������� ��� ���, � ���� ���������� ������� �� �����.";
			link.l1 = "������ �� �����!";
			link.l1.go = "Alligator_hired_0";
			chrDisableReloadToLocation = false;
		break;

		case "Alligator_hired_0":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\WANNAJOIN.wav");
			dialog.text = "";
			link.l1 = "� ���� �������������� � ���...";
        	                                      link.l1.go = "Alligator_hired_1";
			EndQuestMovie();
			InterfaceStates.Buttons.Save.enable = true;
			LAi_LockFightMode(Pchar, false);

		break;

		case "Alligator_hired_00":
 	PlaySound("VOICE\Russian\gotica\Alligator\DIA_ADDON_ALLIGATORJACK_BESSER_12_03.wav");
			dialog.text = "� ����� �� ���������� ��� ���, � ���� ���������� ������� �� �����.";
			link.l1 = "������ �� �����!";
        	                                      link.l1.go = "Alligator_hired_1";
			EndQuestMovie();
			InterfaceStates.Buttons.Save.enable = true;
			LAi_LockFightMode(Pchar, false);

		break;
		
		case "Alligator_hired_1"://���������� - � �������
                        chrDisableReloadToLocation = false;//������� �������
			DialogExit();
		        AddDialogExitQuest("Gothic_SeaShore");
			DeleteAttribute(npchar, "LifeDay");
			npchar.quest.OfficerPrice = sti(pchar.rank)*500;
			npchar.OfficerWantToGo.DontGo = true;//�� �������� ����
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			npchar.CanTakeMushket = true;
	                npchar.DontClearDead = true;
			LAi_SetOfficerType(npchar);
			npchar.greeting = "Gr_Alligator";
			NextDiag.CurrentNode = "Alligator_officer";
			npchar.quest.meeting = true;
			npchar.HoldEquip = true;
			LAi_SetImmortal(npchar, false);
			LAi_SetImmortal(pchar, false);
	                TakeNItems(npchar, "Rumm", 1);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			AddCharacterExpToSkill(pchar, "Leadership", 100);
		break;
		
		case "Alligator_hired_1":
			dialog.text = "���������, ������� � ������ � ������������.";
			link.l1 = "���������, ���������� �� ����!";
			link.l1.go = "Alligator_exit_1";
		break;
		
		case "Alligator_exit_1":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "Alligator_hired_1";
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
			AddCharacterExpToSkill(pchar, "Leadership", 100);					DialogExit();
		break;

		case "Alligator_Terks":
            	dialog.text = "��, ��� �� ������" + GetSexPhrase("","�") + ", ��� ������ ������. � ����� � ���� ���� ������� ���, �� ��������, ��� ��� ������ ���� �����?";
        	link.l1 = "�� ����, ����� �� �������.";
        	link.l1.go = "Alligator_Terks1";
		break;
		case "Alligator_Terks1":
	 sld = characterFromId("Alligator");
	 LAi_SetActorType(sld);
                         LAi_ActorGoToLocation(sld, "goto", "goto1", "none", "", "", "", -1);
	 NextDiag.CurrentNode = NextDiag.TempNode;
	 DialogExit();	
		break;


		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Alligator_officer":
			dialog.text = "������, ����, ���. ��� �������?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "����, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
                                                Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Alligator_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ���� ����������?";
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l4 = "� ����, ����� �� ��������� �� ������������ ���������� �� ����.";
				Link.l4.go = "TargetDistance";
			}
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
		
		//--> ������ ��������� ��������
		case "TargetDistance":
			dialog.text = "�� ����� ������, �������? ������� ������ � �����, �� �� ������, ��� ��������.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "�������, ��� �� ������ ���!";
				link.l1 = "������, �������� �����...";
				link.l1.go = "exit";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "� ���� ������ �� �����, ������ �� ��������. ��� ��� ����������, �������?";
				link.l1 = "��, ������ ��� �� ���� � ���������.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "� ������� �������, ��� ����� 20 ������ �� ���� ��� ��������� ������.";
				link.l1 = "������, ����� ������� �� ���������� � �������� �����.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "������ �����, �������� � ��������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			npchar.MusketerDistance = iTemp;
		break;
		//<-- ������ ��������� ��������
	//<-- ----------------------------------- ���������� ���� ----------------------------------------
	
	// �� ��������
		case "tieyasal":
			dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, �� ������. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
			link.l1 = "�������, ����! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ������������?";
			link.l1 = "������� �����. � ���� �� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21");
			npchar.quest.Tieyasal = "teleport";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}