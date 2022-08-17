// ��� ���� ������
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
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                  dialog.text = "��� � ���� ���������� ��������� ������������� ������������?";
        	                  link.l1 = "��� ����� ���������!"; 
        	                  link.l1.go = "Myxir_1";		
		break;

		case "Myxir_1":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_TALKEDTOGHOST_12_02.wav");
            	                  dialog.text = "����������, ���� �� ������ � ������ ��������� ��� ������?";
        	                  link.l1 = "..."; 
	                  link.l1.go = "exit";	
		
		if(CheckAttribute(pchar, "questTemp.GothicMonbar") && pchar.questTemp.GothicMonbar == "MonbarLineMyxir" && !CheckAttribute(npchar, "quest.MonbarLineMyxir"))
                                   {
                                    dialog.text = "��� ��!";
            	                  link.l1 = "� �������� ����� ����.";
                                    link.l1.go = "MonbarLineMyxir";
       	                  }

		if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "MyxirTakeCoin" && !CheckAttribute(npchar, "quest.MyxirTakeCoin"))
                                   {
                                    dialog.text = "...";
            	                  link.l1 = "� ���������� ����� �������.";
                                    link.l1.go = "MyxirTakeCoin";
       	                  }

		if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "Myxir_architects_table" && !CheckAttribute(npchar, "quest.Myxir_architects_table"))
                                   {
                                    dialog.text = "����������, ���� �� ������ � ������ ��������� ��� ������?";
            	                  link.l1 = "��� ������� ����� ������� �������� ������, ��� ��������.";
                                    link.l1.go = "Myxir_architects_table";
       	                  }
		if(CheckAttribute(pchar, "questTemp.APSH") && pchar.questTemp.APSH == "APSH_Myxir" && !CheckAttribute(npchar, "quest.architects_table_7"))
                                   {
                                    dialog.text = "����������, ���� �� ������ � ������ ��������� ��� ������?";
            	                  link.l1 = "� ���� ���, ��� ���� ��� ����, ��� ��������.";
                                       link.l1.go = "APSH_Myxir_table";
       	                  }
		if(CheckAttribute(pchar, "questTemp.Quarhodron") && pchar.questTemp.Quarhodron == "Quarhodron_Myxir" && !CheckAttribute(npchar, "quest.architects_table_Quarhodron"))
                                   {
                                       dialog.text = "...";
            	                  link.l1 = "���� ����� �������!";
                                       link.l1.go = "Myxir_Quarhodron";
       	                  }

		break;
		
		case "APSH_Myxir_table":
            	dialog.text = "������, ����� ���������.";
        	 link.l1 = "...";
        	 link.l1.go = "APSH_Myxir_table_1";
                      break;

		case "APSH_Myxir_table_1":
		RemoveItems(PChar, "architects_table_7", 1);
		PlaySound("interface\important_item.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                     npchar.quest.architects_table_7 = "true";
						 DoQuestFunctionDelay("GothicAPSH_architects", 0.01);
                                          //DoQuestFunctionDelay("GothicAPSH_architects", 1.0);
		break;

                                       case "APSH_Myxir_table_2":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_HALLO_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "�� � �������!";
        	                   link.l1.go = "APSH_Myxir_table_3";
	                   break;

	                  case "APSH_Myxir_table_3":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_10.wav");
            	                   dialog.text = "����� ��������, ��� ��� ��� ����� � �������� - ����� ������� ����.";
        	                   link.l1 = "������� ����! ��� ���������, ���� �� � �����������? ��� ��� ��� ����� ����� ������ ���� ����� ��������.";
        	                   link.l1.go = "APSH_Myxir_table_4";
	                   break;

		 case "APSH_Myxir_table_4":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_11.wav");
            	                       dialog.text = "��.";
        	                       link.l1 = "�� ������� ��� ���������!";
        	                       link.l1.go = "APSH_Myxir_table_5";
		  break;

		 case "APSH_Myxir_table_5":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                      dialog.text = "��� � ���� ���������� ��������� ������������� ������������?";
        	                       link.l1 = "...";
        	                       link.l1.go = "APSH_Myxir_table_6";
		   break;

		 case "APSH_Myxir_table_6":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_13.wav");
            	                       dialog.text = "��������, ������ �������� ������������ �������� �������.";
        	                       link.l1 = "...";
        	                       link.l1.go = "APSH_Myxir_table_7";
		  break;

		 case "APSH_Myxir_table_7":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_14.wav");
            	                      dialog.text = "�� ������ ���� ������� - � ����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "APSH_Myxir_table_8";
		 break;

		 case "APSH_Myxir_table_8":
	                     PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_15_00.wav");
            	                     dialog.text = "...";
        	                     link.l1 = "� ��� �� ��� ����� �������, ��� �� ������� ����� ����!";
        	                     link.l1.go = "APSH_Myxir_table_9";
		 break;

		 case "APSH_Myxir_table_9":
	                      PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_02.wav");
            	                      dialog.text = "���� ������� ����� ��� ������ ���������� ������ �������, ��� � ������� ���.";
        	                     link.l1 = "�������.";
        	                     link.l1.go = "APSH_Myxir_table_10";
	                    break;

		 case "APSH_Myxir_table_10":
		 TakeNItems(pchar, "APSHMyxirNotice", 1);
		 PlaySound("interface\important_item.wav");
		 Log_Info("�� �������� ���������� ������ �������");
            	                      dialog.text = "��� ��, ��� �� ���� ���������� ������� ����� ��� ������ ����.";
        	                      link.l1 = "����� ��� ��������. ��� � ��������, ������� ���� ����� �����.";
        	                      link.l1.go = "APSH_Myxir_table_11";
		 break;

	case "APSH_Myxir_table_11":
	AddQuestRecord("APSH", "10");
	NextDiag.CurrentNode = NextDiag.TempNode;
	DialogExit();
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1 = "locator";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.location = "Shore127";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.locator_group = "reload";
	PChar.quest.GothicApostatesAPSH_8.win_condition.l1.locator = "reload2";
	PChar.quest.GothicApostatesAPSH_8.function = "APSH_Iroquois";
	break;
	case "Myxir_Quarhodron":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "���� ����� �������!";
        	                      link.l1.go = "Myxir_Quarhodron_1";
		 break;

		 case "Myxir_Quarhodron_1":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_01.wav");
            	                      dialog.text = "������ ������ �������� ����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_2";
		 break;

		 case "Myxir_Quarhodron_2":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_02.wav");
            	                      dialog.text = "����, ��� ��� ��� ������ ��� � �� ����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_3";
		 break;

		 case "Myxir_Quarhodron_3":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_03.wav");
            	                      dialog.text = "���� �� �������������� ������� � ���� ������� �� ������ ������ ��.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_4";
		 break;

		 case "Myxir_Quarhodron_4":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_04.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "���� �������!";
        	                      link.l1.go = "Myxir_Quarhodron_5";
		 break;

		 case "Myxir_Quarhodron_5":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_05.wav");
            	                      dialog.text = "������ ���� � ������ ������ � ����� �����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_6";
		 break;

		 case "Myxir_Quarhodron_6":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_06.wav");
            	                      dialog.text = "���� � ��������� ����� ��� ������, ��� �� ������ ������������ � ���� ���������� �������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_7";
		 break;

		 case "Myxir_Quarhodron_7":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_07.wav");
            	                      dialog.text = "��� ��������� ��������� ������� ����������� �����, ���� ������ �� ������ � �������� ������� �����������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_8";
		 break;

		 case "Myxir_Quarhodron_8":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "�� ������, ��� ��� ���������� ��������� ���� �� ����� - �� �������������.";
        	                      link.l1.go = "Myxir_Quarhodron_9";
		 break;

		 case "Myxir_Quarhodron_9":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_01.wav");
            	                      dialog.text = "�� ������ ��������� �� ������� ��������� �������� ����� ��� ����� ��� �������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_10";
		 break;

		 case "Myxir_Quarhodron_10":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_02.wav");
            	                      dialog.text = "�� ��������� �������� ����� ������� ������, ������ � ����������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_11";
		 break;

		 case "Myxir_Quarhodron_11":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_03.wav");
            	                      dialog.text = "� �� ����������, ��� ��� �� ����� ���� ������������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_12";
		 break;

		 case "Myxir_Quarhodron_12":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_15_00.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "��� �������� ��� �������?";
        	                      link.l1.go = "Myxir_Quarhodron_13";
		 break;

		 case "Myxir_Quarhodron_13":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_01.wav");
            	                      dialog.text = "������� ������ ���� �������� ������ ���������� ������� �������������� ��� ������������� �����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_14";
		 break;

		 case "Myxir_Quarhodron_14":
		RemoveItems(PChar, "architects_table_8", 1);
		PlaySound("interface\important_item.wav");
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_01.wav");
            	                      dialog.text = "...";
        	                      link.l1 = "����� ������ � ���� � ������ ��� ����� �� ������.";
        	                      link.l1.go = "Myxir_Quarhodron_15";
		 break;

		 case "Myxir_Quarhodron_15":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_03.wav");
            	                      dialog.text = "�, �������...";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_16";
		 break;

		 case "Myxir_Quarhodron_16":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_04.wav");
            	                      dialog.text = "������ ����, ��� �� ������ ��� ������� ������ �� ������� ���������� ����� ���������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_17";
		 break;

		 case "Myxir_Quarhodron_17":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_05.wav");
            	                      dialog.text = "���� �� �������, ��� �������� ���� � ������� ��� ���������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_18";
		 break;

		 case "Myxir_Quarhodron_18":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_06.wav");
            	                      dialog.text = "�� ������ ��������� ��� ��.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_19";
		 break;

		 case "Myxir_Quarhodron_19":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_07.wav");
            	                      dialog.text = "�� ��������� ���� ��� ������� �� �������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_20";
		 break;

		 case "Myxir_Quarhodron_20":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_08.wav");
            	                      dialog.text = "�� ������ ������ (������� �����������) ��������� �������� ����������� ������������ ������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_21";
		 break;

		 case "Myxir_Quarhodron_21":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_09.wav");
            	                      dialog.text = "�� ������ �������� � � ��������� �����������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_22";
		 break;

		 case "Myxir_Quarhodron_22":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTPERM_12_01.wav");
            	                      dialog.text = "����� ��� �������� � �������� ���������� ������ ������.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_23";
		 break;

		 case "Myxir_Quarhodron_23":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTPERM_12_02.wav");
            	                      dialog.text = "� ������� �����, �� ������ ������ ��������� �� � ����.";
        	                      link.l1 = "...";
        	                      link.l1.go = "Myxir_Quarhodron_24";
		 break;

		 case "Myxir_Quarhodron_24":
		 TakeNItems(pchar, "QuarhodronMyxirNotice", 1);
		 PlaySound("interface\important_item.wav");
		 Log_Info("�� �������� ���������� ������ �������");
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_03.wav");
            	                      dialog.text = "��� �� ������ ���� ����� �������� ��������.";
        	                      link.l1 = "�������!";
        	                      link.l1.go = "Myxir_Quarhodron_25";
		 break;

		case "Myxir_Quarhodron_25":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                     npchar.quest.architects_table_Quarhodron = "true";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_Quarhodron_Myxir_1");
		break;


		//--> ----------------------------------- ������ ���������� ------------------------------------------

		 case "MyxirTakeCoin":
            	                   dialog.text = "� ������.";
        	                   link.l1 = "� ���� ���� ��������� ������, ������� �� �������, ������ �������� ��� ������ �� ������������, �� ������ �� ���������� ���������� ����, ��������� � ������ ����� ������� � � ����������, ��� �� ���� ����� ������ �����, ������� ������� �����, ��� ����� �������� ���� � ��� ����� ����� ��� ������. ��� �������, ��� �� ��� ������ ������.";
        	                   link.l1.go = "MyxirTakeCoin_1";
		 break;

		case "MyxirTakeCoin_1":
            	                  dialog.text = "� ��� �� � ���� ������?";
        	                  link.l1 = "��� ���������� ����� ��� ���������� �����, � ���� � ��� ����������.";
        	                  link.l1.go = "MyxirTakeCoin_2";
		break;

		case "MyxirTakeCoin_2":
            	                  dialog.text = "������ ����������� ���������, ������ ���?";
        	                  link.l1 = "��.";
        	                  link.l1.go = "MyxirTakeCoin_3";
		break;

		case "MyxirTakeCoin_3":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "� ��� �� ����� �����������.";
        	                  link.l1.go = "MyxirTakeCoin_4";
		break;

		case "MyxirTakeCoin_4":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_01.wav");
            	                  dialog.text = "� ������ ���� ������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_5";
		break;

		case "MyxirTakeCoin_5":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_02.wav");
            	                  dialog.text = "���� ��� ���� � ����, ��� �� ������ ���� �����.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_6";
		break;

		case "MyxirTakeCoin_6":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_03.wav");
            	                  dialog.text = "������ �� ��� ������ ������� ���� ����, ����� ���������� ���������� ���� �����������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_7";
		break;

		case "MyxirTakeCoin_7":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_WASMACHSTDU_12_04.wav");
            	                  dialog.text = "������ �������� ���� ������ �� �������� ��������� � ��������� ������ �� ��� ���� ������� ��� ��������.";
        	                  link.l1 = "�, ��� ��� �� ����������!";
        	                  link.l1.go = "MyxirTakeCoin_8";
		break;

		case "MyxirTakeCoin_8":
            	                  dialog.text = "� �� ���� ���� ����� �������.";
        	                  link.l1 = "������, �����,";
        	                  link.l1.go = "MyxirTakeCoin_9";
		break;

		case "MyxirTakeCoin_9":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "��� �������� ��� �������.";
        	                  link.l1.go = "MyxirTakeCoin_10";
		break;

		case "MyxirTakeCoin_10":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_01.wav");
            	                  dialog.text = "������� ������� ���� �������� ������ ���������� ������� �������������� ��� ������������� �����.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_11";
		break;

		case "MyxirTakeCoin_11":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_02.wav");
            	                  dialog.text = "����, ��� ��� ��� ������ ��� � �� ����.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_12";
		break;

		case "MyxirTakeCoin_12":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_03.wav");
            	                  dialog.text = "���� �� ������������� ������� � ���� ������� �� ����� ������ ��.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_13";
		break;

		case "MyxirTakeCoin_13":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_15_04.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "���� �������?";
        	                  link.l1.go = "MyxirTakeCoin_14";
		break;

		case "MyxirTakeCoin_14":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_05.wav");
            	                  dialog.text = "������ ���� � ������ ������ � ����� �����.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_15";
		break;

		case "MyxirTakeCoin_15":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_06.wav");
            	                  dialog.text = "���� � ��������� ����� ��� ������, ��� �� ������ ������������ ���������� �������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_16";
		break;

		case "MyxirTakeCoin_16":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_12_07.wav");
            	                  dialog.text = "��� ��������� ��������� ������� ����������� �����, ���� ������ ������ � �������� ������� �����������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_17";
		break;

		case "MyxirTakeCoin_17":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WIE_12_02.wav");
            	                  dialog.text = "������� �������� ������� � ����� ������ ������� ����� ���� ��������, ����� ����� ��� ������ ����� ������ ����� �� ������������ ���� ������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_18";
		break;

		case "MyxirTakeCoin_18":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "�� ������, ��� ��� ���������� ��������� ���� �� ����� - �� �������������.";
        	                  link.l1.go = "MyxirTakeCoin_19";
		break;

		case "MyxirTakeCoin_19":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_01.wav");
            	                  dialog.text = "�� ������ ��������� ���������, ��������� �������� ����� ��� ����� ��� �������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_20";
		break;

		case "MyxirTakeCoin_20":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_02.wav");
            	                  dialog.text = "�� ��������� �������� �����, ������� ������, ������ � ����������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_21";
		break;

		case "MyxirTakeCoin_21":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_ADWHELLO_WATT_12_03.wav");
            	                  dialog.text = "� �� ����������, ��� ��� �� ����� ���� ������������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_22";
		break;

		case "MyxirTakeCoin_22":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_15_00.wav");
            	                  dialog.text = "...";
        	                  link.l1 = "��� �� ����� ������ �� ���� ��������.";
        	                  link.l1.go = "MyxirTakeCoin_23";
		break;

		case "MyxirTakeCoin_23":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_12_01.wav");
            	                  dialog.text = "�� ��� �������� ������ �������� ������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_24";
		break;

		case "MyxirTakeCoin_24":
	                 PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_STEINTAFELN_12_03.wav");
            	                  dialog.text = "��� ��� ��� �������� �� �������� ��� �������� ��������� ����������.";
        	                  link.l1 = "...";
        	                  link.l1.go = "MyxirTakeCoin_25";
		break;

		case "MyxirTakeCoin_25":
            	                  dialog.text = "�� � ��������� � ���� ������������ ���������� ��� ������ �������, � ���������� �������� ����������, ������ ���� ����.";
        	                  link.l1 = "������, ���� � ����� ����� ��������, �� ������� � ���������, ��� ���� ��� �� ������� ���� ���, �� ��� ���� �� ������ ����� �������� ����� �������� � ����� ����� ����� ������ � ��������.";
        	                  link.l1.go = "MyxirTakeCoin_26";
		break;

		case "MyxirTakeCoin_26":
            	                  dialog.text = "�����, ��, ������ ����� ��� ������, ��� �� ���������� �� ���. ������ ��� ��� ������.";
        	                  link.l1 = "���, ������.";
        	                  link.l1.go = "MyxirTakeCoin_27";
		break;

		case "MyxirTakeCoin_27":
		RemoveItems(PChar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("�� ������ ������");
            	                  dialog.text = "�������� �����, ��� �� ������. ������� �� ������ ����������, ��� � ���� ���������, ��� ����� ����� ��� - ��� ���������.";
        	                  link.l1 = "������, ����� � ������� �������� �������� ������, � �� �������� ���������� �� ������.";
        	                  link.l1.go = "MyxirTakeCoin_28";
		break;

		case "MyxirTakeCoin_28":
		TakeNItems(pchar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("�� �������� ��������� ������");
            	                  dialog.text = "������������. �� �������� ������� � ���� ����, ���� ������� ����� ������� ������ �����.";
        	                  link.l1 = "������� �� ���������. ��������, � �� ��������.";
        	                  link.l1.go = "MyxirTakeCoin_29";
		break;

		case "MyxirTakeCoin_29":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.MyxirTakeCoin = "true";
                                    DoQuestFunctionDelay("GothicObsession_MyxirTakeCoin", 2.0);
		break;

		//--> ----------------------------------- ������ ���������� ------------------------------------------

		 case "Myxir_architects_table":
            	                   dialog.text = "�������, ��� ��� �, � ���������� ��������, �������� ��� ������.";
        	                   link.l1 = "��� �������.";
        	                   link.l1.go = "Myxir_architects_table_1";
		 break;

		case "Myxir_architects_table_1":
	                 PlaySound("VOICE\Russian\GOTHIC\GG\GG_60.wav");
		RemoveItems(PChar, "architects_table", 1);
		PlaySound("interface\important_item.wav");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.Myxir_architects_table = "true";
                                    DoQuestFunctionDelay("GothicObsession_table_Myxir", 1.0);
		break;

		 case "Myxir_architects_table_2":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_HALLO_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "�� � �������!";
        	                   link.l1.go = "Myxir_architects_table_3";
		 break;

		 case "Myxir_architects_table_3":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_10.wav");
            	                   dialog.text = "����� ��������, ��� ��� ��� ����� � ������� - ����� ������� ����.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_4";
		 break;

		 case "Myxir_architects_table_4":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_15_11.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "�� ������� ��� ���������!";
        	                   link.l1.go = "Myxir_architects_table_5";
		 break;

		 case "Myxir_architects_table_5":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_12.wav");
            	                   dialog.text = "��� � ���� ���������� ��������� ������������� ������������?";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_6";
		 break;

		 case "Myxir_architects_table_6":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_13.wav");
            	                   dialog.text = "��������, ������ �������� ������������ �������� �������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_7";
		 break;

		 case "Myxir_architects_table_7":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_12_14.wav");
            	                   dialog.text = "�� ������ ���� ������� - � ����.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_8";
		 break;

		 case "Myxir_architects_table_8":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "������� ������� �������������� �� ���� ���� ����, ������ �� ����� ���� �����������.";
        	                   link.l1.go = "Myxir_architects_table_9";
		 break;

		 case "Myxir_architects_table_9":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_01.wav");
            	                   dialog.text = "�� �� � ��� ��� �������� ���������� ����������� � �� �����������, � �� ����� ������� ��� ������������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_10";
		 break;

		 case "Myxir_architects_table_10":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_02.wav");
            	                   dialog.text = "���� ������ �������� ���� �������� � �� �������, �� ����� ��� ��������� �������� ������ ������� ��� ������ ��� ���������.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_11";
		 break;

		 case "Myxir_architects_table_11":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_PSI_12_03.wav");
            	                   dialog.text = "� ����� �� ���� �������� ������� ��������� � �������� ���������, ��� �������� ���� � ����������� ��� ����.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_12";
		 break;

		 case "Myxir_architects_table_12":
	                  PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "� ��� �� ��� ����� �������, ��� �� ������� ����� ����!";
        	                   link.l1.go = "Myxir_architects_table_13";
		 break;

		 case "Myxir_architects_table_13":
	                   PlaySound("VOICE\Russian\gotica\Myxir\DIA_ADDON_MYXIR_GEISTTAFEL_WIE_12_02.wav");
            	                   dialog.text = "���� ������� ����� ��� ������ ���������� ������ �������, ��� � ������� ���.";
        	                   link.l1 = "...";
        	                   link.l1.go = "Myxir_architects_table_14";
		 break;

		 case "Myxir_architects_table_14":
		TakeNItems(pchar, "MyxirNotice", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("�� �������� ���������� ������ �������");
            	                   dialog.text = "��� ��.";
        	                   link.l1 = "������� �������, ��� ������ �����!";
        	                   link.l1.go = "Myxir_architects_table_15";
		 break;

		 case "Myxir_architects_table_15":
            	                   dialog.text = "��� ������, ��� �� ����� ��������, �������� ����� �����, �� ������ �� ������ ����� - �� � ��������� ������ ���������, ������ � ������ �� ���� �������� �� ����� �������.";
        	                   link.l1 = "��, ������� � �� ����!";
        	                   link.l1.go = "Myxir_architects_table_16";
		 break;

		case "Myxir_architects_table_16":
	                  AddQuestRecord("Obsession", "7");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                  npchar.quest.Myxir_architects_table = "true";
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