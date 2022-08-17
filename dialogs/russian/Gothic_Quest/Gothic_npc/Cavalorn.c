// �������� ������ ����������� � ���������� ������.
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
		case "First time":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_08_01.wav");
		dialog.text = "׸��, � �� ���� ��� ��� ��� ��������, �������� ������ � ������ ��� ��� ������������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";			
		break;

		case "CAVALORN_HALLO":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "��������...";
		link.l1.go = "CAVALORN_HALLO_1";
                                          DoQuestFunctionDelay("Gothic_SetMusic", 1.5);		
		break;

		case "CAVALORN_HALLO_1":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_08_01.wav");
		dialog.text = "׸��, � �� ���� ��� ��� ��� ��������, �������� ������ � ������ ��� ��� ������������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_2";		
		break;

		case "CAVALORN_HALLO_2":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_08_02.wav");
		dialog.text = "������ �������, � ���� ����, �� ��� ������, ��� ��������� ������� � ���� ������ � ������ ��������.";
		link.l1 = "���� ����� ��������, �����...";
		link.l1.go = "CAVALORN_HALLO_3";
		link.l2 = "���-�� �� ����������.";
		link.l2.go = "CAVALORN_HALLO_3_0";			
		break;

		case "CAVALORN_HALLO_3_0":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_WEISSNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "���-�� �� ����������.";
		link.l1.go = "CAVALORN_HALLO_3_1";		
		break;

		case "CAVALORN_HALLO_3_1":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_WEISSNICHT_08_01.wav");
		dialog.text = "�� ��� ��, ��� � ���� ������ ����� ������� ������, � ���� ���� ��� �������� �� ���� � �� ������� �������������, ������ �����������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_3_2";		
		break;

		case "CAVALORN_HALLO_3_2":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_2.wav");
		dialog.text = "...";
		link.l1 = "���.";
		link.l1.go = "CAVALORN_HALLO_5";		
		break;

		case "CAVALORN_HALLO_3":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ����� ��������, �����...";
		link.l1.go = "CAVALORN_HALLO_4";		
		break;

		case "CAVALORN_HALLO_4":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_JA_08_01.wav");
		dialog.text = "�-��, � ���� �� ��-���� �� ����� ���� ����� �����, �����, ��� �� ������ � ���� ������ �������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_5";		
		break;

		case "CAVALORN_HALLO_5":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_JA_08_02.wav");
		dialog.text = "���� �� �������������!";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_6";		
		break;

		case "CAVALORN_HALLO_6":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_KEINZIEL_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� ��� ����������� ����.";
		link.l1.go = "CAVALORN_HALLO_7";		
		break;

		case "CAVALORN_HALLO_7":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HALLO_KEINZIEL_08_01.wav");
		dialog.text = "�� ������ ��� ��������, ��, ��, �����...";
		link.l1 = "...";
		link.l1.go = "Cavalorn_exit";		
		break;

		case "Cavalorn_exit":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_Bandit");
		break;


		case "CAVALORN_JUNGS":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_JUNGS_15_00.wav");
		dialog.text = "...";
		link.l1 = "���������� � ���� �������, �� ������ �� ������������ � �����.";
		link.l1.go = "CAVALORN_JUNGS_1";
                                         DoQuestFunctionDelay("Gothic_SetMusic", 1.5);			
		break;

		case "CAVALORN_JUNGS_1":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_JUNGS_08_01.wav");
		dialog.text = "����! ��� �� ���������� � ��� ���, ��� ��� ������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_2";		
		break;

		case "CAVALORN_JUNGS_2":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_JUNGS_08_02.wav");
		dialog.text = "����� �� ����� ������� ���� �� ������ ��������, ������� ���� ���������� � ����.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_3";		
		break;

		case "CAVALORN_JUNGS_3":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_JUNGS_08_03.wav");
		dialog.text = "������ � ������� �� ����� ����, � ���������� � ������ ����.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_4";		
		break;

		case "CAVALORN_JUNGS_4":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_KDWTASK_15_00.wav");
		dialog.text = "...";
		link.l1 = "�, ��� ���������� ������ ���� ����?";
		link.l1.go = "CAVALORN_JUNGS_5";		
		break;

		case "CAVALORN_JUNGS_5":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_KDWTASK_08_01.wav");
		dialog.text = "��� ������� ���-��� ���������, ��� �������� ����������� ������� �� �������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_6";		
		break;

		case "CAVALORN_JUNGS_6":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_KDWTASK_15_02.wav");
		dialog.text = "...";
		link.l1 = "����������� �������, ��� �� ��� ����� ����!";
		link.l1.go = "CAVALORN_JUNGS_7";		
		break;

		case "CAVALORN_JUNGS_7":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_KDWTASK_08_03.wav");
		dialog.text = "� �� ���� ���� �������, �������� � �������� � ��������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_8";		
		break;

		case "CAVALORN_JUNGS_8":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_RING_15_00.wav");
		dialog.text = "...";
		link.l1 = "�������� ��� � ������ ����.";
		link.l1.go = "CAVALORN_JUNGS_9";		
		break;

		case "CAVALORN_JUNGS_9":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_RING_08_01.wav");
		dialog.text = "��� �� ����� ���� ������ �������� ��� ����.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_10";		
		break;

		case "CAVALORN_JUNGS_10":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_RING_08_02.wav");
		dialog.text = "��, ��� � ���� �������, ��� �������� ���� � �������, �� ������������� ����� ���� � ��������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_11";		
		break;

		case "CAVALORN_JUNGS_11":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_RING_08_03.wav");
		dialog.text = "����� ���� ���������� � ���, �����, ��� � ���� ������������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_JUNGS_12";		
		break;

		case "CAVALORN_JUNGS_12":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_RING_08_04.wav");
		dialog.text = "����� ���� �� ���� ������ � ���� ����, ��� ������ ���������� ����.";
		link.l1 = "...";
		link.l1.go = "Cavalorn_exit_0";		
		break;

		case "Cavalorn_exit_0":
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_0");
		break;

		case "CAVALORN_HALLO_8":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_WASMACHSTDU_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ����� �������?";
		link.l1.go = "CAVALORN_HALLO_9";
                                         DoQuestFunctionDelay("Gothic_SetMusic", 1.5);			
		break;

		case "CAVALORN_HALLO_9":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_WASMACHSTDU_08_01.wav");
		dialog.text = "���� �� �����, ���� �� �� ���, ������� �������, ���� �� ����� �� ����.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_10";		
		break;

		case "CAVALORN_HALLO_10":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_ARTEFAKT_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� �������� ����������!";
		link.l1.go = "CAVALORN_HALLO_11";		
		break;

		case "CAVALORN_HALLO_11":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_ARTEFAKT_08_01.wav");
		dialog.text = "��...��� ��������� ���� � ������� �� ������� ��������...";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_12";		
		break;

		case "CAVALORN_HALLO_12":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_ARTEFAKT_08_02.wav");
		dialog.text = "��� ���� ����� ������ ��� ���� ����, ������ � ��� ������, ��� ������ ���������� ������� ��.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_13";		
		break;

		case "CAVALORN_HALLO_13":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_ARTEFAKT_08_03.wav");
		dialog.text = "�� ��� ���������� ������� ��� �� ���� ��������, � �� ������� ����. ��� ��������� �����...";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_14";		
		break;

		case "CAVALORN_HALLO_14":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� � ���� ������ � ���������?";
		link.l1.go = "CAVALORN_HALLO_15";		
		break;

		case "CAVALORN_HALLO_15":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_08_01.wav");
		dialog.text = "��������, �� �� ��������� ����� �����, �� ��������� �� ������ ���� ��������� ������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_16";		
		break;

		case "CAVALORN_HALLO_16":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_08_02.wav");
		dialog.text = "��...� ���� ��� ������. ���, ��� � �������� ��� �����������. � ���� ���� �������...";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_17";		
		break;

		case "CAVALORN_HALLO_17":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_08_03.wav");
		dialog.text = "���, ������. � ��� �� ���� ������ ������������� ���� �� ��� ������� ���, ��� �������� �������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_18";		
		break;

		case "CAVALORN_HALLO_18":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_08_04.wav");
		dialog.text = "������ �� ������, ��� ��� ����� ���� � ��������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_19";		
		break;

		case "CAVALORN_HALLO_19":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_HELFEN_08_05.wav");
		dialog.text = "����� ����� ������ ����� � �� ������� ������������.";
		link.l1 = "...";
		link.l1.go = "Cavalorn_exit_1";		
		break;

		case "Cavalorn_exit_1":
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_1");
		break;

		case "CAVALORN_HALLO_20":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ���������� �������.";
		link.l1.go = "CAVALORN_HALLO_21";
                                         DoQuestFunctionDelay("Gothic_SetMusic", 1.5);			
		break;

		case "CAVALORN_HALLO_21":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_08_01.wav");
		dialog.text = "��� ������ �� �������� ��� ����� ������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_22";		
		break;

		case "CAVALORN_HALLO_22":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_08_02.wav");
		dialog.text = "� ���� ���� ���� ������ ���, ����� ���� ������!";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_23";		
		break;

		case "CAVALORN_HALLO_23":
		TakeNItems(pchar, "blade45", 1);
		Log_Info("�� �������� ������ ���");
		PlaySound("interface\important_item.wav");
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_15_03.wav");
		dialog.text = "...";
		link.l1 = "�� ��������� ��� �����!";
		link.l1.go = "CAVALORN_HALLO_24";		
		break;

		case "CAVALORN_HALLO_24":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_15_04.wav");
		dialog.text = "...";
		link.l1 = "�, ��� �� ������ �������?";
		link.l1.go = "CAVALORN_HALLO_25";		
		break;

		case "CAVALORN_HALLO_25":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_08_05.wav");
		dialog.text = "� ���� ���� ��� ��� �������� ����� - �����!";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_26";		
		break;

		case "CAVALORN_HALLO_26":
		TakeNItems(pchar, "potion2", 2);
		Log_Info("�� �������� ��� �������� �����");
		PlaySound("interface\important_item.wav");
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_AUSRUESTUNG_15_06.wav");
		dialog.text = "...";
		link.l1 = "�������, ����� ����...";
		link.l1.go = "Cavalorn_exit_2";		
		break;

		case "Cavalorn_exit_2":
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_2");
		break;

		case "CAVALORN_HALLO_27":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_LETSKILLBANDITS_15_00.wav");
		dialog.text = "...";
		link.l1 = "�����, ���������� � ����� ��������...";
		link.l1.go = "CAVALORN_HALLO_28";		
		break;

		case "CAVALORN_HALLO_28":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_LETSKILLBANDITS_08_01.wav");
		dialog.text = "�������, ����� ��� �� �� ��� �� ��������� � ����. �����...";
		link.l1 = "...";
		link.l1.go = "CAVALORN_HALLO_29";		
		break;

		case "CAVALORN_HALLO_29":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_LETSKILLBANDITS_08_02.wav");
		dialog.text = "������ �� ��� ���������� �������.";
		link.l1 = "�����!";
		link.l1.go = "Cavalorn_exit_3";		
		break;

		case "Cavalorn_exit_3":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\ANHEUERN.wav");
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_3");
                                          NextDiag.CurrentNode = "CAVALORN_1";
		break;

		case "CAVALORN_1":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_LETSKILLBANDITS_08_02.wav");
		dialog.text = "������ �� ��� ���������� �������.";
		link.l1 = "�����!";
		link.l1.go = "CAVALORN_2";
		break;

		case "CAVALORN_2":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\ANHEUERN.wav");
		DialogExit();
		LAi_SetActorType(npchar);
		LAi_ActorFollowEverywhere(npchar, "", -1);
		LocatorReloadEnterDisable("Hispaniola_CaveEntrance_2", "reload1_back", false);
		AddComplexSelfExpToScill(20, 20, 20, 20);
		pchar.quest.GothicburialvaultDaughter2.win_condition.l1 = "location";
			pchar.quest.GothicburialvaultDaughter2.win_condition.l1.location = "Hispaniola_Cave_2";
		pchar.quest.GothicburialvaultDaughter2.function = "Gothicburialvault_Cavalorn_5";
		NextDiag.CurrentNode = "CAVALORN_3";
		break;

		case "CAVALORN_3":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_PCKILLEDBRAGO_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��������� ���������...";
		link.l1.go = "CAVALORN_4";
                                         DoQuestFunctionDelay("Gothic_SetMusic", 1.5);			
		break;

		case "CAVALORN_4":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_00.wav");
		dialog.text = "�, � ������� ����� ��������� ��� �������, � � ��� ������� ������� ����� �������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_5";		
		break;

		case "CAVALORN_5":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_15_01.wav");
		dialog.text = "...";
		link.l1 = "��� ��� �� �������!";
		link.l1.go = "CAVALORN_6";		
		break;

		case "CAVALORN_6":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_02.wav");
		dialog.text = "��, ��, ���� ������� ��� ��� ����� ������� � ����� � �����...";
		link.l1 = "...";
		link.l1.go = "CAVALORN_7";		
		break;

		case "CAVALORN_7":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_03.wav");
		dialog.text = "��, �� ���� ��� ��� ��� ������� �������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_8";		
		break;

		case "CAVALORN_8":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_15_04.wav");
		dialog.text = "...";
		link.l1 = "� ��� �� ���� ����!";
		link.l1.go = "CAVALORN_9";		
		break;

		case "CAVALORN_9":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_05.wav");
		dialog.text = "��, � ������ �� � ���, �� ������ ��������� ������ � �����.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_10";		
		break;

		case "CAVALORN_10":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_06.wav");
		dialog.text = "����� � ���� ����� ������ ������ �������, ��� ��  ������������ � ����� ����������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_11";		
		break;

		case "CAVALORN_11":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_07.wav");
		dialog.text = "������ ������ ���� � ������ �� �������� � �������.";
		link.l1 = "...";
		link.l1.go = "Cavalorn_exit_4";		
		break;

		case "Cavalorn_exit_4":
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_6");
		break;

		case "CAVALORN_12":
		dialog.text = "������ �����?";
		if (CheckCharacterItem(pchar, "VatrasNotice"))
		{
		link.l1 = "��, � ����� ������.";
		link.l1.go = "CAVALORN_13";	
		}
		else
		{
		link.l1 = "���� ��� ���.";
		link.l1.go = "CAVALORN_fail";	
		}	
		break;

		case "CAVALORN_fail":
		dialog.text = "������ ������ ���� �����, � ������� � ������ �� ���.";
		link.l1 = "������, � ���.";
		link.l1.go = "exit_fail";
		break;

		case "exit_fail":
		DialogExit();
                                          NextDiag.CurrentNode = "CAVALORN_12";
		break;

		case "CAVALORN_13":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_08.wav");
		dialog.text = "������ ��� � ������� ���� ���� � ����� �� ������ ��� � ����� �������, �� ����������� ��� ���� ����.";
		link.l1 = "��� �� �����!";
		link.l1.go = "CAVALORN_14";		
		break;

		case "CAVALORN_14":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_09.wav");
		dialog.text = "����� ���, ��� ��� �� �������! ����� ��������� �� ������� ������-����, ���������� �������, �� ��� �� ���� ��������.";
		link.l1 = "...";
		link.l1.go = "CAVALORN_15";		
		break;

		case "CAVALORN_15":
	                     PlaySound("VOICE\Russian\gotica\CAVALORN\DIA_ADDON_CAVALORN_VATRASBRIEF_08_10.wav");
		dialog.text = "� ���� �� ������� ��� �, ������ ����� ���, ��� � ��� �� ���� � ����� �������. �����...";
		link.l1 = "...";
		link.l1.go = "Cavalorn_exit_5";		
		break;

		case "Cavalorn_exit_5":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_8.wav");
		DialogExit();
		AddDialogExitQuestFunction("Gothicburialvault_Cavalorn_7");
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
		dialog.text = "�� ��������� �������, ���. � ���, ��� ������������� � ���� �����, �� ������. � �������� ���� �����, ���� � �� �������� ���� � � ���� �����������!";
		link.l1 = "�������, ����! � ���" + GetSexPhrase("","�") + ", ��� �� ����" + GetSexPhrase("��","���") + " � ����.";
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