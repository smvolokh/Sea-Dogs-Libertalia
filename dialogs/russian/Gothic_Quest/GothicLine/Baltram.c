// �������� ��������
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
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_01.wav");
		dialog.text = "�����, ��� ��� ������� ������������ ����, � ��������� ������ � ����, ��� ���� ����������.";
		link.l1 = "";
		link.l1.go = "First time_exit";
		break;

		case "First time_exit":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_04.wav");
			dialog.text = "� �� ������ ������� ������ � ��� - ��������, �� ��� ���� ��������.";
			link.l1 = "��, ����� �� �������...";
			link.l1.go = "exit";

		NextDiag.TempNode = "First time";
		break;

			

		case "Baltram_hallo":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_00.wav");
			dialog.text = "����� ���������� ���������, ���� ����� �������, �� ������ ��������� ���������������?";
			link.l1 = "������ ��� ���� ������.";
			link.l1.go = "Baltram_hallo_1";
		break;

		case "Baltram_hallo_1":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_WAREZ_15_00.wav");
			dialog.text = "";
			link.l1 = "������ ��� ���� ������.";
			link.l1.go = "Baltram_hallo_2";
		break;		

		case "Baltram_hallo_2":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_01.wav");
			dialog.text = "�����, ��� ��� ������� ������������ ����, � ��������� ������ � ����, ��� ���� ����������.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_3";
		break;

		case "Baltram_hallo_3":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_02.wav");
			dialog.text = "�� ����� � ��� ����� ��������.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_4";
		break;

		case "Baltram_hallo_4":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_03.wav");
			dialog.text = "���� �� ������ ������ � ���� �������� �������, �� ������ ��������.";
			link.l1 = "";
			link.l1.go = "Baltram_hallo_5";
		break;

		case "Baltram_hallo_5":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_LARESABLOESE_15_06.wav");
			dialog.text = "";
			link.l1 = "�������, ����� ��� ��������!";
			link.l1.go = "exit";
		break;								






		case "1":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_15_00.wav");
			dialog.text = "";
			link.l1 = "������ �� �������� � ��������?";
			link.l1.go = "1_7";
		break;

		case "1_7":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_01_03.wav");
			dialog.text = "��� �� ��� ���� ������, ������� ������ ������� ������ ������������� ��� �����.";
			link.l1 = "�� ����, ������� �������?";
			link.l1.go = "1_8";
		break;

		case "1_8":
			dialog.text = "";
			link.l1 = "� ��������" + GetSexPhrase("","�") + " ���� ������� �������� ����� �������� � ����� � ��� ������ � ������� ���������, ������� ��� ��������.";
			link.l1.go = "1_9";
		break;
		
		case "1_9":
			dialog.text = "���, �� ���. �����������!";
			link.l1 = "����� ��� �� ��������, �� ��� ���������, ��� � ��������" + GetSexPhrase("","�") + " ��� ���������. � �����" + GetSexPhrase("","�") + " �� ��������, ��� �� ������ ���� ��������� ��� ���� ����� � ��� ����������� ����" + GetSexPhrase("","�") + " ���� �� ���������.";
			link.l1.go = "1_10";
		                   PlaySound("interface\important_item.wav");
			TakeNItems(PChar, "PortmansBook", -1);
		break;
		
		case "1_10":
			dialog.text = "����� ����������, �������. � �������� ������� ����� �� ��������� ������, ����.";
			link.l1 = "����, ����?";
			link.l1.go = "1_11";
		break;

		case "1_11":
			dialog.text = "������!";
			link.l1 = "";
			link.l1.go = "1_12";
		break;
		
		case "1_12":
			dialog.text = "�������! ������ ��� �������. � ������, ����� � ����, � ����� ��������� ��� �� ������� 750 ����.";
			link.l1 = "750 ����? ������ - �� �...";
			link.l1.go = "1_13";
		break;
		
		case "1_13":
			dialog.text = "� �������, �� �� ��, ����, ��� - ��.";
			link.l1 = "������, ������� ���� ������.";
			link.l1.go = "1_14";
		break;
				
		case "1_14":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 750);
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "1_15";
		break;

		case "1_15":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_JOB_15_00.wav");
			dialog.text = "";
			link.l1 = "� ���� ���� ������ ��� ����?";
			link.l1.go = "1_16";
		break;

		case "1_16":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_00.wav");
			dialog.text = "�� ����� ������?";
			link.l1 = "";
			link.l1.go = "1_17";
		break;

		case "1_17":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_02.wav");
			dialog.text = "��� ������� �� ���������� �� �������� � � ��� �������� �� ������� �����!!!";
			link.l1 = "";
			link.l1.go = "1_18";
		break;

		case "1_18":
 	 PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_01.wav");
			dialog.text = "";
			link.l1 = "�������, � ��� �����!";
			link.l1.go = "1_19";
		break;

		case "1_19":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_03.wav");
			dialog.text = "";
			link.l1 = "� �� ������� �� ���������� ��� ������?";
			link.l1.go = "1_20";
		break;

		case "1_20":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_01_04.wav");
			dialog.text = "� ��� ���� 50 ������� �����!";
			link.l1 = "";
			link.l1.go = "1_21";
		break;

		case "1_21":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_TRICK_15_05.wav");
			dialog.text = "";
			link.l1 = "������� � ��������, ��� ��� �����.";
			link.l1.go = "1_22";
		break;

		case "1_22":
			dialog.text = "�� ��������� � ����� ����� ����� �������, ��������� ����� � ��������� �����.";
			link.l1 = "";
			link.l1.go = "1_23";
		break;

		case "1_23":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("Gothic_Akil");
		break;

		case "1_24":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LIEFERUNG_15_00.wav");
		                   PlaySound("interface\important_item.wav");
		                   RemoveItems(PChar, "cask_whisky", 1);
			dialog.text = "";
			link.l1 = "� ������ ����� �� �����!";
			link.l1.go = "1_25";
		break;

		case "1_25":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LIEFERUNG_01_01.wav");
			dialog.text = "�����������, ������ � ����� ����� ��������� ������� ����������, ��� ���� 50 ������� �����.";
			link.l1 = "";
			link.l1.go = "1_26";
		break;

		case "1_26":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			TakeNItems(pchar, "gold_dublon", 50);
			Log_Info("�� �������� 50 ��������");
			PlaySound("interface\important_item.wav");

			dialog.text = "";
			link.l1 = "";
			link.l1.go = "1_27";
		break;

		case "1_27":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_LETUSTRADE_15_00.wav");
			dialog.text = "";
			link.l1 = "����� ��� ����� ���������� � �����?";
			link.l1.go = "1_28";
		break;

		case "1_28":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HALLO_01_04.wav");
			dialog.text = "� �� ������ ������� ������ � ��� - ��������, �� ��� ���� ��������, �� � ����� �� �����������, ������� �����. ������� ����� ���� ����, �������� ��� - ������ � �����!";
			link.l1 = "";
			link.l1.go = "1_29";
		break;

		case "1_29":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDelivery_taimer");
		break;


		
		case "2_1":
			dialog.text = "�� ��� ��� �������.\n���������� ��������� ��������� ������ ������������ ����� ����� � ����-�-�����, �� ��� ��� ������, ������ �� �� ������, � �������� �������������, ��� ��� - ��.\n�� ������ �������� ����� �������� ������.\n���������, � ������� �� ����������, � �������� �� ���� 7000 ����. ��, ��� ��������? ������� �� ������������.";
			link.l1 = "� ������" + GetSexPhrase("��","��") + ".";
			link.l1.go = "2_2";
			link.l2 = "���, � �����������.";
			link.l2.go = "2_5";
		break;
		
		case "2_2":
			dialog.text = "�������. �� ��������� ���� � ������ �������� ���, ����� ������, ������ ���� ������, ���������� � ������. ������ ������� ����.";
			link.l1 = "������, � �� �����" + GetSexPhrase("","�") + ".";
			link.l1.go = "2_3";
		break;

		case "2_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDeliverySilk");
		break;
		
		case "2_4":
			dialog.text = "� ���, ��� ������ ������� �����. ��� ��. ��������� �����, ������� "+ GetFullName(Pchar)+"!";
			link.l1 = "�������� ���.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAgree");
		break;

		case "2_5":
			dialog.text = "��������� �����, ������� "+ GetFullName(Pchar)+"!";
			link.l1 = "�������� ���.";
			link.l1.go = "exit_1";
		                   AddDialogExitQuestFunction("No_Baltram");
		break;
		
 		case "exit_1":
                                       NextDiag.CurrentNode = "Exit2";
		DialogExit();
		AddDialogExitQuestFunction("GothicDeliveryCancel");
		break;


		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner2":
			AddMoneyToCharacter(PChar, -sti(PChar.StealItemsMoney));
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner3":
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;



		case "BaltramCaleuche":// ����� �������
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_PIRAT_01_04.wav");
		dialog.text = "������ � ������, ��� ������� ��� ����. ��, ��� ��, ������� "+ GetFullName(Pchar)+"?";
		link.l1 = "��� �� ����� �������, ��� �� ����� ��������� ����� ��������?";
		link.l1.go = "BaltramCaleuche_1";
		break;

		case "BaltramCaleuche_1":
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_PIRAT_01_02.wav");
		dialog.text = "��������� � ���� ������� ���� ����� ������ �� �������?";
		link.l1 = "��� ����?";
		link.l1.go = "BaltramCaleuche_2_1";
		break;

		case "BaltramCaleuche_2_1":
	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_WAS_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� �� �� ��������? ����� ����������?";
		link.l1.go = "BaltramCaleuche_2";
		break;
		
		case "BaltramCaleuche_2":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_ADDON_BALTRAM_SKIP_WAS_01_01.wav");
		dialog.text = "� �������� � �������� �� ���, � ���� � ����-����� ������� ��� ���������. ������� ����� � ��������� ��� ������, � ������� �� ���� ������� ��������: ����� �������� � ����-����� ����� ��������, � ���������� ������ ��������� �������� ������������, ������������ ���� ������ ����������, � ����������� �������� ������\n� � ������ ������, ���������� �������� ����� ��������� �������, ��������� ���������� �� �������� ����, � ����� ������������� ���������� ������ �� ������� � ������ ����������.";
		link.l1 = "��, �� � ����. �� � ��?";
		link.l1.go = "BaltramCaleuche_3";
		break;

		case "BaltramCaleuche_3":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_WAREZ_01_02.wav");
		dialog.text = "���-�� �������� ����������� ������ ���� ���������. � � �����, ����� ��� �����. ��� � ��� ���������� ������ ��������� ����������, ���� �� ������ ����� ������� �� ����� �������, �������� ������ �� ����� ��������. ���, � �� ����� � ����-���� ������.";
		link.l1 = "������, ����� � � ���� �����, ��� ��������� ������?";
		link.l1.go = "BaltramCaleuche_4";
		break;

		case "BaltramCaleuche_4":
 	        PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_HAVEYOURWAREZ_01_05.wav");
		dialog.text = "������ ����� �� ������ ��� ����� ����?";
		link.l1 = "";
		link.l1.go = "BaltramCaleuche_5_1";
		break;

		case "BaltramCaleuche_5_1":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_13.wav");
		dialog.text = "";
		link.l1 = "������� �� ������?";
		link.l1.go = "BaltramCaleuche_5";
		break;

		case "BaltramCaleuche_5":
 	        PlaySound("VOICE\Russian\gotica\SVM_1\SVM_4_GOLD_300.wav");
		dialog.text = "300 ������� �����.";
		link.l1 = "";
		link.l1.go = "BaltramCaleuche_6";
		break;

		case "BaltramCaleuche_6":
		if (GetCharacterItem(pchar, "gold_dublon") >= 300)
		{
		link.l1 = "���, ��� ������.";
		link.l1.go = "BaltramCaleuche_7";
		}
		link.l2 = "������ � ���� ��� �����.";
		link.l2.go = "BaltramCaleuche_10";
		break;

		case "BaltramCaleuche_7":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		RemoveItems(pchar, "gold_dublon", 300);
		Log_Info("�� ������ 300 ��������");
                dialog.text = "������������! �����, ������ ���� - ����� ����!";
		link.l1 = "�������, ��� ��������?";
		link.l1.go = "BaltramCaleuche_8";
		break;

		case "BaltramCaleuche_8":
	        Log_Info("�� �������� �������� ��������� ����������");
		PlaySound("interface\important_item.wav");
                DialogExit();
                NextDiag.TempNode = "First time";
                NextDiag.CurrentNode = NextDiag.TempNode;
		GiveItem2Character(pchar, "kaleuche_amulet1");
		GiveItem2Character(pchar, "indian_3");
		GiveItem2Character(pchar, "amulet_4");
		GiveItem2Character(pchar, "obereg_5");
		break;

		case "BaltramCaleuche_9":
                dialog.text = "���� ������?";
		if (GetCharacterItem(pchar, "gold_dublon") >= 300)
		{
			link.l1 = "��, ��� ��� ����� ��������.";
			link.l1.go = "BaltramCaleuche_7";
		}
		link.l2 = "���� ���, � ��� ������� ��� ����.";
		link.l2.go = "BaltramCaleuche_10";
		break;
		
		case "BaltramCaleuche_10":
                PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
                DialogExit();
		npchar.dialog.currentnode = "BaltramCaleuche_9";
		break;


		case "Baltramrocur":// Addon 2016-1 Jason ��������� �������

		dialog.text = "��, ��� ��, ������� "+ GetFullName(Pchar)+"! ���������� ���!";
		link.l1 = "������ ����. ��� �� ����� �������, ����� ��������?";
		link.l1.go = "Baltramrocur_1";
		break;

		case "Baltramrocur_1":
		dialog.text = "�����������, ���������� � ������, ������ �����.";
		link.l1 = "� ��� �� �������?";
		link.l1.go = "Baltramrocur_2";
		break;
		
		case "Baltramrocur_2":
		dialog.text = "������ � �������� ���������, ������, �������� ����� �����. ������� ����� �� ����� ���� �����. � ������� ����, ������, ���� � ������� ��� � ������, ������� ������� ���������. ����, �� ������ ���� � �������� �������.";
		link.l1 = "����� �����! ��� ��� ��� ���������� ������!";
		link.l1.go = "Baltramrocur_3";
		break;

		case "Baltramrocur_3":
 	PlaySound("VOICE\Russian\gotica\BALTRAM\DIA_BALTRAM_SPERRE_01_00.wav");
		dialog.text = "������ ������� � ��� �� ������! ��� ����� ������ �� �������� ���� �� ���������.";
		link.l1 = "������� �������. ��� ����� ��� ������� �������� ��������, �� ������ � ���. ����� ���������� �������� �����. ��� ����� ���������. �� � ������� �������� � ����� ��������� ������� �� ������. � ��� ������� ����� �����, ���� ��������?";
		link.l1.go = "Baltramrocur_4";
		break;

		case "Baltramrocur_4":
		dialog.text = "��, �� ������������ ���� � �������. �� ������ � ������ ����� �� ���� ���� ��������� �������: ����, ����� � ������. ��� �������?";
		link.l1 = "�������?";
		link.l1.go = "Baltramrocur_5";
		break;

		case "Baltramrocur_5":
 		dialog.text = "���� ����� ��������.";
		link.l1 = "�� �����.";
		link.l1.go = "Baltramrocur_6";
		break;

		case "Baltramrocur_6":
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l1 = "���, �������.";
		link.l1.go = "Baltramrocur_7";
		}
		link.l2 = "��������� �������. � �����.";
		link.l2.go = "Baltram_10";
		break;

		case "Baltramrocur_7":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                                      PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
		RemoveItems(pchar, "gold_dublon", 500);
		Log_Info("�� ������ 500 ��������");
                                     	dialog.text = "������������! ������ ���� - ����� ����!";
		link.l1 = "�������, ��� ��������!";
		link.l1.go = "Baltramrocur_8";
		break;

		case "Baltramrocur_8":
		PlaySound("interface\important_item.wav");
                                      DialogExit();
                                      NextDiag.TempNode = "First time";
                                      NextDiag.CurrentNode = NextDiag.TempNode;
		TakeNItems(pchar, "pistol1", 30);
		TakeNItems(pchar, "mushket1", 2);
		TakeNItems(pchar, "potion1", 90);
		TakeNItems(pchar, "bullet", 100);
		TakeNItems(pchar, "GunPowder", 100);
RemoveCharacterGoods(sld, GOOD_COFFEE, 100);
SetCharacterGoods(pchar, GOOD_COFFEE, 100);
RemoveCharacterGoods(sld, GOOD_CINNAMON, 100);
SetCharacterGoods(pchar, GOOD_CINNAMON, 100);
RemoveCharacterGoods(sld, GOOD_COPRA, 100);
SetCharacterGoods(pchar, GOOD_COPRA, 100);
	RemoveCharacterGoods(sld, GOOD_TEA, 100);
	SetCharacterGoods(pchar, GOOD_TEA, 100);
		break;

		case "Baltramrocur_9":
            dialog.text = "�������� ������?";
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l1 = "��, ��� ���� ����� ��������.";
		link.l1.go = "Baltramrocur_7";
		}
		link.l2 = "���� ���.";
		link.l2.go = "Baltram_10";
		break;
		
		case "Baltram_10":
           DialogExit();
		npchar.dialog.currentnode = "Baltramrocur_9";
		break;



//----------------------------------------- ����������� ������� -----------------------------------------------
		//����������� �� � ��������
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("��� �� ��� ���������, �? �� �� ���!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������!", "�� �������� ������ �������?! ���� ��� ����� �� �������!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ �������?! ���� ��� ����� �� �������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}