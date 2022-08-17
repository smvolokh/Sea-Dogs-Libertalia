// ������� ����, ����� ����� � �������
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
	float locx, locy, locz;
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}

// ============================= ���� angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //������� ������� ������������
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //���� ����������� ������� �����. � npchar.angry.name ������� �������!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                    if (npchar.angry.name == "I_know_you_good") Dialog.CurrentNode = "AngryRepeat_2";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= ���� angry ===================================
// ============================================================================

	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_15_01.wav");
		dialog.text = "...";
		link.l1 = "� ���� �� ��� �������� � ��������� �������.";
		link.l1.go = "WAS";			
		break;

		case "WAS":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_01_02.wav");
		dialog.text = "������ � ���� �������� ��������, ��������...";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "First time";		
		break;


		case "NOCHNICHT":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� ���� ��������� ����������.";
		link.l1.go = "nw";			
		break;

		case "nw":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_01_01.wav");
		dialog.text = "...";
	                 if(CheckAttribute(pchar, "questTemp.GothicGreg") && pchar.questTemp.GothicGreg == "Greg_geld" && !CheckAttribute(npchar, "quest.Greg_geld"))
		{
		link.l1 = "�� �� ����� � �������.";
		link.l1.go = "nw_1_1";
		}
	                 if(CheckAttribute(pchar, "questTemp.GothicGreg") && pchar.questTemp.GothicGreg == "conctantino" && !CheckAttribute(npchar, "quest.conctantino"))
		{
		link.l1 = "�� ������ ������� � ����� ������, ��� �� ������� ����.";
		link.l1.go = "nw_2_1";
		}
                                         if (CheckCharacterItem(pchar, "suit5") && CheckAttribute(pchar, "questTemp.GothicGreg") && !CheckAttribute(npchar, "quest.suit5"))
		{
		link.l1 = "��� ��������� ����, ���� �� ���� ����� ������ �����������.";
		link.l1.go = "nw_3_1";
		}
                                         if (CheckCharacterItem(pchar, "VerifyPaper") && CheckAttribute(pchar, "questTemp.GothicGreg") && !CheckAttribute(npchar, "quest.VerifyPaper"))
		{
		link.l1 = "� ���� ���� ������� � �����.";
		link.l1.go = "nw_4_1";
		}
		link.l2 = "��� ���� ����.";
		link.l2.go = "Greg_hallo_10_1";	

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "PiratosGreg.Fail1" && !CheckAttribute(npchar, "quest.PiratosGreg.Fail1"))
		{
		link.l1 = "� ���� � ���� ���� ������� �����������.";
		link.l1.go = "Greg_Trinidad";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "PiratosGreg.work" && !CheckAttribute(npchar, "quest.PiratosGreg.work"))
		{
		link.l1 = "� ���� � ���� ���� ������� �����������.";
		link.l1.go = "Greg_Trinidad_work";
		}

 		break;

		case "WER":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� �� ������ �����?";
		link.l1.go = "WER_0";			
		break;

		case "WER_0":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_01_01.wav");
		dialog.text = "��� �� ��� ����.";
		link.l1 = "...";
		link.l1.go = "WER_1";			
		break;

		case "WER_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_01_02.wav");
		dialog.text = "���� �� � ����� ���� �������������, � �� �������� ��� ��� ������, �� ��� ��!";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "WER";		
		break;

		case "nw_1_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_GELD_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� �� ����� � �������.";
		link.l1.go = "nw_1_2";			
		break;

		case "nw_1_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_GELD_01_01.wav");
		dialog.text = "���� �� � ��� ��������� ����������, � ��� �� ��� � ������.";
		link.l1 = "...";
		link.l1.go = "nw_1_3";			
		break;

		case "nw_1_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ��� ��������.";
		link.l1.go = "nw_exit1";			
		break;

		case "nw_exit1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.Greg_geld = "true";
                                          pchar.questTemp.GothicGreg = "conctantino";	
		DialogExit();
		break;

		case "nw_2_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_CONSTANTINO_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� ������ ������� � ����� ������, ��� �� ������� ����.";
		link.l1.go = "nw_2_2";			
		break;

		case "nw_2_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_CONSTANTINO_01_01.wav");
		dialog.text = "���. � ��� ����� �� �������� ������� �������� � ����� ��������!";
		link.l1 = "...";
		link.l1.go = "nw_2_3";			
		break;

		case "nw_2_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ��� ��������.";
		link.l1.go = "nw_exit2";			
		break;

		case "nw_exit2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.conctantino = "true";	
		DialogExit();
		break;

		case "nw_3_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ��������� ����, ���� �� ���� ����� ������ �����������.";
		link.l1.go = "nw_3_2";			
		break;

		case "nw_3_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_01.wav");
		dialog.text = "��� ��� ��� ��, ��� ��� �����, � ����, ��� ���� �� ���� ���������� ��������.";
		link.l1 = "...";
		link.l1.go = "nw_3_3";			
		break;

		case "nw_3_3":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "suit5", -1);
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_02.wav");
		dialog.text = "���� � ���� ���� ��� ������� ����������� ������, ����� �� ����� �������� �� ���� ��������.";
		link.l1 = "...";
		link.l1.go = "nw_3_4";			
		break;

		case "nw_3_4":
		npchar.model = "Greg2";
		Characters_RefreshModel(npchar);
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_03.wav");
		dialog.text = "�������, ��� ���� �������.";
		link.l1 = "...";
		link.l1.go = "nw_3_5";			
		break;

		case "nw_3_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_15_04.wav");
		dialog.text = "...";
		link.l1 = "���, ������ 50 �����! �� �� ������ ���� ������.";
		link.l1.go = "nw_3_6";			
		break;

		case "nw_3_6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_05.wav");
		dialog.text = "������ ��� �� ����� ������ �� ����� - ���� ���. ������ ���� ��, ��� � ���� ���������.";
		link.l1 = "...";
		link.l1.go = "nw_3_7";			
		break;

		case "nw_3_7":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 50);
		Log_Info("�� �������� 50 ��������");
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_06.wav");
		dialog.text = "� ���� ���� ������������, ��� �� ����� ���������� �����.";
		link.l1 = "...";
		link.l1.go = "nw_3_8";			
		break;

		case "nw_3_8":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_07.wav");
		dialog.text = "� ��� �����, ����� ���� � ���� ����� ����������� ��������� ���� ������� �� ������, ������ ����.";
		link.l1 = "...";
		link.l1.go = "nw_exit3";			
		break;

		case "nw_exit3":
		npchar.quest.suit5 = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuestFunction("Horinisport3");
		break;

		case "nw_4_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� ���� ������� � �����.";
		link.l1.go = "nw_4_2";			
		break;

		case "nw_4_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_01_01.wav");
		dialog.text = "�-��, �� ������ �������, ��� � ������ ������ ���� �� ����������.";
		link.l1 = "...";
		link.l1.go = "nw_4_3";			
		break;

		case "nw_4_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_01_02.wav");
		dialog.text = "�������� �� ����, �������, � ��� �� ������� ���� ��������� �����.";
		link.l1 = "...";
		link.l1.go = "nw_4_4";			
		break;

		case "nw_4_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ��� ��������.";
		link.l1.go = "nw_exit4";			
		break;

		case "nw_exit4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.VerifyPaper = "true";
		DialogExit();
		break;

		case "Greg_hallo":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_00.wav");
		dialog.text = "��...��, ��, �������-�� ����...";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_1";			
		break;

		case "Greg_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_15_01.wav");
		dialog.text = "...";
		link.l1 = "� ��� ����?";
		link.l1.go = "Greg_hallo_2";			
		break;

		case "Greg_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_02.wav");
		dialog.text = "�� ���� � �����! � ���� ��� ����!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_3";			
		break;

		case "Greg_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_03.wav");
		dialog.text = "��������, �� ��������� ��������������� ������, ������, �� � ����� ������ ������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_4";			
		break;

		case "Greg_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_04.wav");
		dialog.text = "�� �� �����, � ���� ��� �� ����� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_5";			
		break;

		case "Greg_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_05.wav");
		dialog.text = "��������� �� ������ ���������� ��������� ������� �����, �� ���-��?";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6";			
		break;

		case "Greg_hallo_6":
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "�� �� ����-�� ���������!";
		link.l2.go = "Greg_hallo_7_1";
		link.l3 = "� �� ������, ��� �� � ���� �������� ������!";
		link.l3.go = "Greg_hallo_8_1";
		link.l4 = "�������� �������, ������ ���� �� ������.";
		link.l4.go = "Greg_hallo_9_1";	
		link.l5 = "��� ���� ����.";
		link.l5.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_6_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_hallo_6_2";			
		break;

		case "Greg_hallo_6_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_01.wav");
		dialog.text = "�� ������ �������� ��������������� ������� ������, � ����� � ����� ����� � �� ���� ������� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_3";			
		break;

		case "Greg_hallo_6_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_02.wav");
		dialog.text = "������� ��� �������� �� ����� ����� ��������, ��� ��������� ��������� � ���� ������ ������� ��������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_4";			
		break;

		case "Greg_hallo_6_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_03.wav");
		dialog.text = "� ��� ������ ��� ����� ������� � �����, � � �� ���� ��� ��� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_5";			
		break;

		case "Greg_hallo_6_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_04.wav");
		dialog.text = "� ������ � ���� ����������� ������ ����, ��� ������ �� �������� �������� �� �� �� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_6";			
		break;

		case "Greg_hallo_6_6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_05.wav");
		dialog.text = "�� �� �������� ��� ������ ���� ����������, ������!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_7";			
		break;

		case "Greg_hallo_6_7":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ��������.";
		link.l1.go = "nw_exit6";			
		break;

		case "nw_exit6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuestFunction("Horinisport2");
		break;

		case "Greg_hallo_7_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_15_00.wav");
		dialog.text = "...";
		link.l1 = "�� �� ����-�� ���������!";
		link.l1.go = "Greg_hallo_7_2";			
		break;

		case "Greg_hallo_7_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_01.wav");
		dialog.text = "���, ������� ���, ��� �� ������. ��� ������ �������� ������ ����� �������� ��� ��� ����� �� ���� � ����.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_7_3";			
		break;

		case "Greg_hallo_7_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_02.wav");
		dialog.text = "��, ����� ����� ��������� � ����, �� ����� ������!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_7_4";			
		break;

		case "Greg_hallo_7_4":
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "� �� ������, ��� �� � ���� �������� ������!";
		link.l2.go = "Greg_hallo_8_1";
		link.l3 = "�������� �������, ������ ���� �� ������.";
		link.l3.go = "Greg_hallo_9_1";	
		link.l4 = "��� ���� ����.";
		link.l4.go = "Greg_hallo_10_1";					
		break;


		case "Greg_hallo_8_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "� �� ������, ��� �� � ���� �������� ������.";
		link.l1.go = "Greg_hallo_8_2";			
		break;

		case "Greg_hallo_8_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_01.wav");
		dialog.text = "�� �������, � �� �������� ������� ����, � ������ ������ ��������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_3";			
		break;

		case "Greg_hallo_8_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_02.wav");
		dialog.text = "�� �� �� �� ���������� ��������� ��� ��������� �� ��������� �����, ������� � ��� �� ���� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_4";			
		break;

		case "Greg_hallo_8_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_03.wav");
		dialog.text = "��, ��� �������, � ���� �� ���� ������������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_5";			
		break;

		case "Greg_hallo_8_5":
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "�������� �������, ������ ���� �� ������.";
		link.l2.go = "Greg_hallo_9_1";	
		link.l3 = "��� ���� ����.";
		link.l3.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_9_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_15_00.wav");
		dialog.text = "...";
		link.l1 = "�������� �������, ������ ���� �� ������.";
		link.l1.go = "Greg_hallo_9_2";			
		break;

		case "Greg_hallo_9_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_01.wav");
		dialog.text = "��� ������ ��� ������ ��, ��� � ���� �����.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_3";			
		break;

		case "Greg_hallo_9_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_02.wav");
		dialog.text = "���� �������� ����� ������ ���� �� ��������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_4";			
		break;

		case "Greg_hallo_9_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_03.wav");
		dialog.text = "� ����, ��� ���� ���� � ��������� ������� ���������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_5";			
		break;

		case "Greg_hallo_9_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_04.wav");
		dialog.text = "�, ��, ��������� ���� ������� �������, �� ��������� �� ���������� ��������������.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_6";			
		break;

		case "Greg_hallo_9_6":
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "��� ���� ����.";
		link.l2.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_10_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ����.";
		link.l1.go = "Greg_hallo_10_2";			
		break;

		case "Greg_hallo_10_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_01_01.wav");
		dialog.text = "� ���, �� ������������� ��� ��������, �����. ������ � ��� �������, �� ��� ����������.";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "First time";			
		break;

//--> -----------------------------------������------------------------------------------

		case "Greg_Caiman":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ��...";
		link.l1.go = "Greg_Caiman_1";				
		break;

		case "Greg_Caiman_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_01_01.wav");
		dialog.text = "� ����, ������������ ���� ������� �����...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_2";				
		break;

		case "Greg_Caiman_2":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_01_02.wav");
		dialog.text = "���� ���������� ����� �����...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_3";				
		break;

		case "Greg_Caiman_3":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_WAY_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� �� ���� �����?";
		link.l1.go = "Greg_Caiman_4";				
		break;

		case "Greg_Caiman_4":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��� ���� �������?";
		link.l1.go = "Greg_Caiman_5";				
		break;

		case "Greg_Caiman_5":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_01.wav");
		dialog.text = "� ��������� ��������� �������, ��� ��������� ������� ���� �� ���������� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_6";				
		break;

		case "Greg_Caiman_6":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_02.wav");
		dialog.text = "��������� ��������. � ������ ������� ������� ��� ����� ����� ����������� ����������� ������ ������� '��������' ������������� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_7";				
		break;

		case "Greg_Caiman_7":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_03.wav");
		dialog.text = "�� ��� ������ ����� ����������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_8";				
		break;

		case "Greg_Caiman_8":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_15_04.wav");
		dialog.text = "...";
		link.l1 = "�� ��, ��������� ����...";
		link.l1.go = "Greg_Caiman_9";				
		break;

		case "Greg_Caiman_9":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_05.wav");
		dialog.text = "��� ������ ��� ��� �� �������� ���, � ������������ ��� �������� �� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_10";				
		break;

		case "Greg_Caiman_10":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_02.wav");
		dialog.text = "��, ����� ����� ��������� � ����, �� ����� ������!";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11";			
		break;

		case "Greg_Caiman_11":
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_Caiman_11_1";	
		link.l2 = "��� ���� ����.";
		link.l2.go = "Greg_Caiman_12_1";					
		break;

		case "Greg_Caiman_12_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ����.";
		link.l1.go = "Greg_Caiman_12_2";			
		break;

		case "Greg_Caiman_12_2":
                                          pchar.questTemp.GothicPiratosGreg = "PiratosGreg.Fail1";
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_01_01.wav");
		dialog.text = "� ���, �� ������������� ��� ��������, �����. ������ � ��� �������, �� ��� ����������.";
		link.l1 = "...";
		link.l1.go = "GregCaiman_board_6x";	
		break;

		case "Greg_Caiman_11_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ �� � ���...";
		link.l1.go = "Greg_Caiman_11_2";			
		break;

		case "Greg_Caiman_11_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_HIERGOLD_01_02.wav");
		dialog.text = "��������� �� ���� ���� ������, ��� ���� �� ��� ����, ��� � �����-�� ����� ���� ���������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_3";			
		break;

		case "Greg_Caiman_11_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_HIERGOLD_01_03.wav");
		dialog.text = "������ ��� ���� ������� ������, � ����, ��� �� �� ��� �����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_4";			
		break;

		case "Greg_Caiman_11_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVELOS_15_00.wav");
		dialog.text = "...";
		link.l1 = "����� � ���� ������.";
		link.l1.go = "Greg_Caiman_11_5";			
		break;

		case "Greg_Caiman_11_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVELOS_01_01.wav");
		dialog.text = "������ �� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_6";		
		break;

		case "Greg_Caiman_11_6":
		DialogExit();
	                  AddDialogExitQuestFunction("GothicEng_CreateGreg_1");		
		break;

		case "GregCaiman_board_6x":
                                    DialogExit();
                                    npchar = characterFromID("GREG");
                                    npchar.dialog.currentnode = "GregCaiman_board_6x";
                                    npchar.DeckDialogNode = "GregCaiman_board_6x";
	                  npchar.DontDeskTalk = true;				
		break;

		case "GregCaiman_board_6x":
                                    dialog.text = "���-�� ��� ������ �������?";
		link.l1 = "���, �������. ��� ����������� �� ���� �����.";
		link.l1.go = "GregCaiman_board_6y";
		break;
		
		case "GregCaiman_board_6y":
                                    DialogExit();
                                   npchar = characterFromID("GREG");
		npchar.DeckDialogNode = "GregCaiman_board_6x";
		break;

		case "Greg_Caiman_13":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_00.wav");
		dialog.text = "��, ��� ��������, ��� � ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_14";		
		break;

		case "Greg_Caiman_14":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_01.wav");
		dialog.text = "��� ���� �����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_15";		
		break;

		case "Greg_Caiman_15":
                                    TakeNItems(pchar, "minepick", 1);
                                    Log_Info("�� �������� �����");
                                    PlaySound("interface\important_item.wav");
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_02.wav");
		dialog.text = "� ������� ���� ���� ��� - �� ������, ����� ��������� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_16";		
		break;

		case "Greg_Caiman_16":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_03.wav");
		dialog.text = "�� � ���� �� ����, ��� ������ � ������� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_17";		
		break;

		case "Greg_Caiman_17":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_15_04.wav");
		dialog.text = "...";
		link.l1 = "� ��� �� ��?";
		link.l1.go = "Greg_Caiman_18";			
		break;

		case "Greg_Caiman_18":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_05.wav");
		dialog.text = "��� - �� �� ������ �������� ���, � ������ ��� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_19";	
		break;

		case "Greg_Caiman_19":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_03.wav");
		DialogExit();
                                    NPChar = characterFromID("GREG");
	                  NPChar.dialog.currentnode   = "Greg_Caiman_18";
                                    LAi_SetWarriorType(NPChar);
		AddDialogExitQuestFunction("GothicGreg_CaveEntrance_3");	
		break;

		case "Greg_Caiman_20":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ����� ��� ���������� ����.";
		link.l1.go = "Greg_Caiman_21";		
		break;

		case "Greg_Caiman_21":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_01_01.wav");
		dialog.text = "����� � ���� ������ ���� ����� 100 �������, ������� ����, ���������� ����� � ������. ����� �� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_22";	
		break;

		case "Greg_Caiman_22":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���� ����.";
		link.l1.go = "Greg_Caiman_23";		
		break;

		case "Greg_Caiman_23":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "purse3"))
			{
				link.l1 = "������ �� 100 ��������.";
				link.l1.go = "Greg_Caiman_Task_check_1";	
			}
			else
			{
				link.l1 = "� ���� � ����� �� ���.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "purse3", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_01.wav");
		dialog.text = "...";
		link.l1 = "������ �� 100 ��������.";
		link.l1.go = "Greg_Caiman_24";		
		break;

		case "Greg_Caiman_24":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "jewelry33"))
			{
				link.l1 = "������� ����.";
				link.l1.go = "Greg_Caiman_Task_check_2";	
			}
			else
			{
				link.l1 = "� ���� � ����� �� ���.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_2":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "jewelry33", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_03.wav");
		dialog.text = "...";
		link.l1 = "������� ����.";
		link.l1.go = "Greg_Caiman_25";		
		break;

		case "Greg_Caiman_25":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "mineral36"))
			{
				link.l1 = "���������� �����.";
				link.l1.go = "Greg_Caiman_Task_check_3";	
			}
			else
			{
				link.l1 = "� ���� � ����� �� ���.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_3":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "mineral36", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_04.wav");
		dialog.text = "...";
		link.l1 = "���������� �����.";
		link.l1.go = "Greg_Caiman_26";		
		break;

		case "Greg_Caiman_26":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "indian_5"))
			{
				link.l1 = "� ������.";
				link.l1.go = "Greg_Caiman_Task_check_4";	
			}
			else
			{
				link.l1 = "� ���� � ����� �� ���.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_4":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "indian_5", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_05.wav");
		dialog.text = "...";
		link.l1 = "� ������.";
		link.l1.go = "Greg_Caiman_27";		
		break;

		case "Greg_Caiman_27":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_01_06.wav");
		dialog.text = "����� ������, ���� � ���� ������� ��� �� ����������� ���� ��� ����.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_28";		
		break;

		case "Greg_Caiman_28":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ��� - ���.";
		link.l1.go = "Greg_Caiman_29";		
		break;

		case "Greg_Caiman_29":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_SAUBER2_01_01.wav");
		dialog.text = "������� ����� ���� �������...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_30";		
		break;

		case "Greg_Caiman_30":
                                          pchar.questTemp.GothicPiratosGreg = "PiratosGreg.work";
	                     TakeNItems(pchar, "gold_dublon", 20);
	                      Log_Info("�� �������� 20 ��������");
		 DialogExit();
	                      NextDiag.CurrentNode = NextDiag.TempNode;
		 AddDialogExitQuestFunction("GothicGreg_quest_chest5");
		 break;

		case "Greg_Caiman_31":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_02.wav");
		dialog.text = "������� � ����������, ��� �� ��� �����, �� ��� �� ������ ��� ��������, ���������, � ��� �.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_32";		
		break;

		case "Greg_Caiman_32":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicGreg_quest_chest6");
                                          sld = CharacterFromID("GHenry");//��� ���� �����
	                     sld.dialog.filename = "Gothic_Quest\Gothic_npc\Henry.c";
                                          sld.dialog.currentnode = "PiratosHenry";
		break;

		case "Greg_Caiman_33":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_02.wav");
		dialog.text = "������� � ����������, ��� �� ��� �����, �� ��� �� ������ ��� ��������, ���������, � ��� �.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_34";		
		break;

		case "Greg_Caiman_34":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Greg_Caiman_Task_fail":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_NOT_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ���� � ����� �� ���.";
		link.l1.go = "Greg_Caiman_24_1";		
		break;

		case "Greg_Caiman_24_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_NOT_01_01.wav");
		dialog.text = "����� ���������� � ������� �� ��� ���� � �������������.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_25_1";		
		break;

		case "Greg_Caiman_25_1":
                                         DialogExit();
		NextDiag.TempNode = "Greg_Caiman_22";
		break;

		case "Greg_Caiman_26_1":
	                    PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_01.wav");
                                         DialogExit();
		NextDiag.TempNode = "Greg_Caiman_25_1";
		break;


		case "Greg_Hut":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_01_00.wav");
		dialog.text = "�� ��, ��� �� ������� � ���� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_1";		
		break;

		case "Greg_Hut_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_15_01.wav");
		dialog.text = "...";
		link.l1 = "�...";
		link.l1.go = "Greg_Hut_2";		
		break;

		case "Greg_Hut_2":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_01_02.wav");
		dialog.text = "����� ������ �� ��������� ���� � ��� ��� ������ ����������, ������� ������������� � ��� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_3";		
		break;

		case "Greg_Hut_3":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_03.wav");
		dialog.text = "������ �����, ��� ����� ����������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_4";		
		break;

		case "Greg_Hut_4":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_04.wav");
		dialog.text = "�������� ��� �� ��������, ������ ������ ����� �������, � ��� ������ � ������, ��� ��������� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_5";
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorTurnToLocator(npchar, "goto", "goto6");	
		break;

		case "Greg_Hut_5":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_05.wav");
		dialog.text = "� ��� ��, ��� �� ������ �������?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_6";		
		break;

		case "Greg_Hut_6":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_06.wav");
		dialog.text = "���������� ����� � ���� ��������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_7";
	                     npchar = CharacterFromID("GFrancis");
                                         LAi_SetGuardianType(npchar);
	                    npchar.protector = true;
	                    npchar.dialog.currentnode   = "Francis_Greg_20";
                                         ChangeCharacterAddressGroup(npchar, "Trinidad_House_Jungle", "goto",  "ass4");		
		break;

		case "Greg_Hut_7":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_07.wav");
		dialog.text = "� ��, ��� �� ������?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_8";
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorTurnToLocator(npchar, "reload", "reload2");
		break;

		case "Greg_Hut_8":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_NICH_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� �� ��� �����.";
		link.l1.go = "Greg_Hut_9";		
		break;

		case "Greg_Hut_9":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_NICH_01_01.wav");
		dialog.text = "�� �����, � ���-������ ������� ���� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_10";	
		break;

		case "Greg_Hut_10":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorGoToLocator(npchar, "goto", "goto6", "GothicGothicGregHut", -1.0);
		break;

		case "Greg_Hut_11":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ���������� �������.";
		link.l1.go = "Greg_Hut_12";		
		break;

		case "Greg_Hut_12":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_01.wav");
		dialog.text = "������� ������ �� ��� �� ��������, ����� ����� ���������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_13";	
		break;

		case "Greg_Hut_13":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_02.wav");
		dialog.text = "������� �� ������ ����� ���� �����������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_14";	
		break;

		case "Greg_Hut_14":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_JOB_15_00.wav");
		dialog.text = "...";
		link.l1 = "�, ��� ��� �� ����� ������� � ������ �����!";
		link.l1.go = "Greg_Hut_15";		
		break;

		case "Greg_Hut_15":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_JOB_01_01.wav");
		dialog.text = "�������� �� �����������, ������ �������� �� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_16";	
		break;

		case "Greg_Hut_16":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ���-������ ����� ������?";
		link.l1.go = "Greg_Hut_17";		
		break;

		case "Greg_Hut_17":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_01_01.wav");
		dialog.text = "������� � ����� ���� �����.(�������� � �����).";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_18";	
		break;

		case "Greg_Hut_18":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_01_02.wav");
		dialog.text = "��� �� ����� ��������� ��� ����.";
		link.l1 = "...";
		link.l1.go = "exit";
                                          LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload2_back", true);//������� ������
		AddDialogExitQuestFunction("GothicGreg_JOB");
	                     npchar = CharacterFromID("GMorgan");
	                     npchar.dialog.currentnode = "Morgan_Francis";
	                     npchar = CharacterFromID("GBrandon");
	                     npchar.dialog.currentnode = "Brandon_Followme";	
	                     npchar = CharacterFromID("GMatt");
	                     npchar.dialog.currentnode = "Matt_Followme";	
		break;

		case "Greg_Hut_19":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_15_00.wav");
		dialog.text = "...";
		link.l1 = "������ �������?";
		link.l1.go = "Greg_Hut_20";		
		break;

		case "Greg_Hut_20":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_01_01.wav");
		dialog.text = "��, ��� ���?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_21";	
		break;

		case "Greg_Hut_21":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_RAZORSDEAD_15_00.wav");
		dialog.text = "...";
		link.l1 = "� ��������� ���� �����������...";
		link.l1.go = "Greg_Hut_22";		
		break;

		case "Greg_Hut_22":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_RAZORSDEAD_01_01.wav");
		dialog.text = "������, ������ �� ���� ���� ������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_23";	
		break;

		case "Greg_Hut_23":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_15_00.wav");
		dialog.text = "...";
		link.l1 = "���� ��� ���� ��� ������?";
		link.l1.go = "Greg_Hut_24";		
		break;

		case "Greg_Hut_24":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_01_03.wav");
		dialog.text = "� ����� ����� �� ��� ���� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_25";		
		break;

		case "Greg_Hut_25":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_01_04.wav");
		dialog.text = "������� ������ ��� ����� � ���� �����������, �� ������ �� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_26";		
		break;

		case "Greg_Hut_26":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "��� ����� ���������� �������.";
		link.l1.go = "Greg_Hut_27";		
		break;

		case "Greg_Hut_27":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_04.wav");
		dialog.text = "������� �� ��������� ������ ��� �����, ��� ���� � ��������������� ��� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_28";		
		break;

		case "Greg_Hut_28":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_05.wav");
		dialog.text = "�� ���� ����� ��� ���� ������ ������ ������� ���� �����������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_29";		
		break;

		case "Greg_Hut_29":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_06.wav");
		dialog.text = "�������� � ���� ���� ��������� ��������� �� ���� �����.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_30";		
		break;

		case "Greg_Hut_30":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_07.wav");
		dialog.text = "�������� � �������, ��� �� �� ��� ���� �����, ����� ������ � � ����������� � ������ ��������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_31";		
		break;

		case "Greg_Hut_31":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_08.wav");
		dialog.text = "� ���� ������, ������ ��� ������� ��������� � ���� ������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_32";		
		break;

		case "Greg_Hut_32":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_09.wav");
		dialog.text = "...";
		link.l1 = "����� ������� �������.";
		link.l1.go = "exit";
	                     npchar = CharacterFromID("GBones");
	                     npchar.dialog.currentnode = "Bones_Givearmor";		
		break;


		case "Greg_Hut_33":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITPLATT2_15_00.wav");
		dialog.text = "...";
		link.l1 = "������� � ����� ����������.";
		link.l1.go = "Greg_Hut_34";	
		break;

		case "Greg_Hut_34":
		LocatorReloadEnterDisable("Shore129", "boat", false);
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 500);
		Log_Info("�� �������� 500 ��������");
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITPLATT2_01_01.wav");
		dialog.text = "���������, ������� ������. ��� ���� �������.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_35";		
		break;

		case "Greg_Hut_35":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_RAVENDEAD_01_03.wav");
		dialog.text = "� �� ������, ��������� � ��� �� ����.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_35";		
		break;

		case "Greg_Trinidad":
		dialog.text = "����� �����, ���.";
		link.l1 = "...";
		link.l1.go = "exit";
		npchar.quest.PiratosGreg.Fail1 = "true";
		NextDiag.TempNode = "Greg_Hut_35";		
		break;

		case "Greg_Trinidad_work":
		dialog.text = "������.";
		link.l1 = "� �� ��������� ����� ����������� ������ '��������' ���� ������� ����� ������. ������ �� ��� ����� ��������� �� ���.";
		link.l1.go = "Greg_Trinidad_work_1";	
		break;

		case "Greg_Trinidad_work_1":
		dialog.text = "'��������' �����? �� ���� ��������. � ���� ���������, ����� ���������� �� �����, �� ���� ������� �����, ��� � ���������.";
		link.l1 = "������, ����������� �� �����.";
		link.l1.go = "exit";
		npchar.quest.PiratosGreg.work = "true";
                                          pchar.quest.GothicEng_Paladinship_fail.over = "yes"; 
		NextDiag.TempNode = "Greg_Hut_35";	
		AddDialogExitQuest("GothicEng_PortSpeinToSea");	
		break;

		case "Greg_Trinidad_work_2":
		dialog.text = "�� ��� ����� ��, ����������� ������� '��������'. ���� �� ������ �� ������, ��� � ��� � �������� �� ����������.";
		link.l1 = "� ������� ����, �� ���. ���� ��� � ��������� ������� ��� ������ ����-��-������.";
		link.l1.go = "Greg_Trinidad_work_3_1";
	                     Group_DeleteGroup("GothicEng_Paladin");
	                     LAi_group_Delete("EnemyFight");	
		break;

		case "Greg_Trinidad_work_3_1":
		dialog.text = "������? ���� � ������ �������, ���� � ����� ������������, ������� ���������.";
		link.l1 = "�� ������ ����� ������������ ���� �������� �������?";
		link.l1.go = "Greg_Trinidad_work_4";	
		break;

		case "Greg_Trinidad_work_3":
		dialog.text = "��, ������ �� � ���. �������! ���� ����� � ����������� ����� ������� � ��������� �������. ��������� �������� ����-��-������ �� ������ ������ �� ������ ���������� �����. ����� �� �������� ������ �� �����, ������� �� � �����. ��� �������?";
		link.l1 = "���, ��� ��������?";
		link.l1.go = "Greg_Trinidad_work_4";	
		break;

		case "Greg_Trinidad_work_4":
		dialog.text = "� ����� �� ��������� ������� ��� ��������, �����, � ���� ������ ��� ����� '��������' � ����� ������ ������ �����������.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_35";
	                     AddDialogExitQuestFunction("GothicEng_PortSpeinSquadronAttack");		
		break;

		case "Greg_Trinidad_work_5":
            dialog.text = "���, � ��������� ���������. ������ � ���� �������� '��������' - ���� ���������� ���� ����-��-������ � ����� ��������� ��������.";
		link.l1 = "� ����� ��������� ��������.";
		link.l1.go = "Greg_Trinidad_work_6";
		break;
		
		case "Greg_Trinidad_work_6":
            dialog.text = "'��������' ����� ������� ������� � ������ �����������, � ����� �� ���������, ������� �� ����� �� ����, ����������� � ����� ��������� � �� ������� � ���� ��� ��������. ������!";
		link.l1 = "...";
		link.l1.go = "Greg_Trinidad_work_7";
		break;
		
	case "Greg_Trinidad_work_7":
                     DialogExit();
 	NextDiag.TempNode = "Greg_Hut_35";
	npchar.DontDeskTalk = true;
	Group_FindOrCreateGroup("Greg_SeaGroup2");
	Group_SetTaskNone("Greg_SeaGroup2");
	Group_LockTask("Greg_SeaGroup2");
	sld = CharacterFromID("PortSpein Fort Commander");
	LAi_SetImmortal(sld, false);
	Ship_SetTaskAttack(SECONDARY_TASK, sti(npchar.index), sti(sld.index));
	DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
	pchar.questTemp.GothicEng.PortSpein.Fort = "true";
	break;

		case "Greg_Trinidad_work_8":
            dialog.text = RandSwear()+"������ ���� �������! ���, ������ �������, ����-��-����� ���. ������ ������ ��������������, ��-��-��! "+pchar.name+", ������ � ��������� ������������ �� ���������� � ����������� - �� ����. �������� �����\n�������� ������ ������� �������� - ������ ������� �� ������ ��� �� �����, ������� �������� ��������� � �����. ������ ����� � ������ ������ ���������������. ����� ������������ - �� ������, ��� ������, ����� �� �����.";
			link.l1 = "���! � �������������, �������!";
			link.l1.go = "Greg_Trinidad_work_9";
		break;
		
		case "Greg_Trinidad_work_9":
                                         DialogExit();
	                    sld = CharacterFromID("GBrandon");
	                   LAi_SetActorType(sld);
                                        LAi_ActorFollow(sld, pchar, "", -1);
	                   sld = CharacterFromID("Greg");
	                   LAi_SetActorType(sld);
	                   LAi_ActorFollow(sld, pchar, "", -1);

		// ��������� ����� � ������, ����������, �����
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_fort")], true);
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_town")], true);
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_townhall")], true);
		LAi_LocationDisableOfficersGen("PortSpein_townhall", true);
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1 = "locator";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.location = "PortSpein_town";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.locator_group = "reload";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.locator = "reload3_back";
		pchar.quest.GothicEng_PortSpein_townhall.function = "GothicEng_PortSpeinToResidence";
		break;

		case "Greg_Trinidad_work_10":
                                         dialog.text = "�������, ������ � ���� ������������ ���� �������� �������, ������� ���������� �� ����� � ��������?";
		link.l1 = "�� ���� �������, �� ���� ��������� � ����� �����������, ������� ����.";
		link.l1.go = "Greg_Trinidad_work_11";
		break;
		
		case "Greg_Trinidad_work_11":
                                          DialogExit();
		AddDialogExitQuestFunction("GothicEng_PortSpeinFinal");
		break;


		
		//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Greg_officer":
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
			NextDiag.TempNode = "Greg_officer";
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

		// ============== ������ ����� ���� ���, ������� ������� � ������� =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("������ ����� ���� ���! ��� ��� �� ����� ��������?! ��, ������, "+ GetSexPhrase("��������","�������") +"...", "��, �� ���� ��� ��� ���������?! �����, �������"+ GetSexPhrase("","�") +" �������� ����? ��, ����� ���� �����...", "������, �� ���� ��� �����"+ GetSexPhrase("","��") +"? �� �� ���"+ GetSexPhrase("","����") +", �����������! ��, ������, ��� �� �������"+ GetSexPhrase("","�") +", ����"+ GetSexPhrase("��","��") +"...");
			link.l1 = LinkRandPhrase("������!!", "��������!!", "�-���, ����!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("����� ���","��������") +" ������!", "��� �� ���� ����������!");
			link.l1 = "��...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ������ ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "���� �� ����� ��������� ���� �� ���� ������� �����������. ������ ��������� ����� ���� ����� ���������...";
        			link.l1 = "� �����"+ GetSexPhrase("","�") +".";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryRepeat_2":
            dialog.text = RandPhraseSimple("�� ���� ������� ������"+ GetSexPhrase("","�") +", �������� �������.", "� �� ���� � ����� ��������, ��� ��� ���� ����� ���� �� ����������.");
		link.l1 = RandPhraseSimple("�� ��� ������...", "��, �� ��� ��...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //����������� � ������ ����� 10 ����.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         		dialog.text = "�������, ������ �� �� ������ �������� ���� ������� �����������, ����� ��� �������� ���� �����. ���������, ��� ��� ����� ����� ���������.";
        		link.l1 = "����, �� ������ ���� ������ - �� ����...";
        		link.l1.go = NextDiag.TempNode;
        		CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("PuertoPrincipe_town","reload","houseS2");
		break;
		// <<<<<<<<<<<<============= ���� ��� angry =============================
		case "PuertoPrincipe_town":
            dialog.text = "������ ��������? �� �� ��� ���������, ���� �� ���������? � �����, ��������� ��� ������� ���� - � ������� �����, ����� ��� ������ ���� '�������'. ��� - ������ �������� �� ��� ������ �������.";
		if (sti(Pchar.money) >= 1000000)
			{
			link.l1 = "������, � ����� ���������.";
			link.l1.go = "PuertoPrincipe_town_pay";
			}
			link.l2 = "� �� �����. �����.";
			link.l2.go = "PuertoPrincipe_town_exit";
		break;
		
	case "PuertoPrincipe_town_exit":
	DialogExit();
                  bDisableFastReload = true;//������� �������
	pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
	pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
	pchar.quest.pirate_in_town.function = "TownPirate_battle";
	break;
		
		case "PuertoPrincipe_town_pay":
            dialog.text = "��� � ������! ������, ��� ���� ��������� �� �����������. �� ������, � �������, �� ������ �� ������ ������ ����� ���������.";
		link.l1 = "�� ����. �� ����� ������ ��� ���������. ������...";
		link.l1.go = "exit";
		AddMoneyToCharacter(pchar, -1000000);
		pchar.GenQuest.Piratekill = 0;
		break;

		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ������� ���� �������
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // �� �������� �� ������������ ���� :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // ������ ������
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
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

