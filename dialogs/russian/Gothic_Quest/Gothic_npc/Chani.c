//����, ���� ������� ���������
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
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_4.wav");
			dialog.text = "���� ��������� ����, ���� �� ������ ���� ����� ���� ����� �� ����.";
			link.l1 = "���, ��� �� �� ���, �����!";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlement" && !CheckAttribute(npchar, "quest.ChaniSettlement"))
			{
				link.l1 = "";
				link.l1.go = "Chani";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotteMayakDieenemy" && !CheckAttribute(npchar, "quest.RoseauCharlotteMayakDieenemy"))
			{
				link.l1 = "";
				link.l1.go = "Chani_18";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniMayakDieenemy" && !CheckAttribute(npchar, "quest.ChaniMayakDieenemy"))
			{
				link.l1 = "";
				link.l1.go = "ChaniMayakDieenemy";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniMayak" && !CheckAttribute(npchar, "quest.ChaniMayak"))
			{
				link.l1 = "";
				link.l1.go = "ChaniMayak";
			}
		break;

		case "Chani":
			dialog.text = "";
			link.l1 = "��� ��?";
			link.l1.go = "Chani_1";
		break;

		case "Chani_1":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_0.wav");
			dialog.text = "���� ���� ������, ���� ������� ���������, � ������� ���� � ����� ����, � ����� � ����� � ���� �����, ����� ������� ���� ��� �� �� ������� ������� ��������� ���������, ��� ���� �������, ��� ���� - ����.";
			link.l1 = "�����? ������ ������ ����� ������?";
			link.l1.go = "Chani_2";
		break;

		case "Chani_2":
			dialog.text = "�� ����, ��� �� ��� ������, �� � ���� ���� ������ - �������� ������.";
			link.l1 = "�������. � ��� ����� �������?";
			link.l1.go = "Chani_3";
		break;

		case "Chani_3":
			dialog.text = "��� ���, ��� ������� ���������������� �� ���� ����� � ��� ���� ����������. ����� ��� � ���, � ��� ����� ����������� � �������� ������, �� ��� �� ��.";
			link.l1 = "����� ���? ������ ��� � ���� �����������!";
			link.l1.go = "Chani_4";
		break;

		case "Chani_4":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_1.wav");
			dialog.text = "� ������, �� �� �� ����� ������������ ��� ����� �������, � ���� ���� ����.";
			link.l1 = "��� �� ����!";
			link.l1.go = "Chani_5";
		break;

		case "Chani_5":
			dialog.text = "��� ������������ ��� �������� ����. �� ������� ����� ��������, �� ������ ��� ��������?";
			link.l1 = "��, �������� ��, ������ ����, ��� - �� ����������� ����� ��� ������ ��� - ��, ��� ���� � ������ �������, ����� ���������� ����.";
			link.l1.go = "Chani_6";
		break;

		case "Chani_6":
			dialog.text = "��� �������, ���������� �� �� �������, ��� �� �� ����? ������ ������� ����� ���������� ����� ����� �������. �� ������, ����� �� ������ ����.";
			link.l1 = "������, ����������� � ��������� � �������.";
			link.l1.go = "exit_1";
		break;

		case "Exit_1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("ChaniSettlement_0");
		break;

		case "Chani_7":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! � ��� � �� ����! �, ��� - �� ��������, ��� ��� - �� �����!";
			link.l1 = "������, ����� �� ��� ������, � �� �����, ��������� �����... �!";
			link.l1.go = "Chani_7_1"; 
		break;

		case "Chani_7_1":
			dialog.text = "���!";
			link.l1 = "� ���� ����� ����� ��������!";
			link.l1.go = "Chani_7_2"; 
		break;

		case "Chani_7_2":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "��� ������ ��� �� ������ �� ��� �����������!";
			link.l1 = "��, �� ����� ����, ����� ����� ���!";
			link.l1.go = "exit";
                                                         LocatorReloadEnterDisable("Roseau_town", "basement1_back", false);
		                  AddDialogExitQuestFunction("ChaniSettlement_2");
		break;

		case "Chani_8":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������!!!";
			link.l1 = "��� �� ���� ������ �������, �� ����� ����� ������ ���, ����� ��� �����, ������ ������� ����� �����, ����� �� ������� ���� ��� ������?";
			link.l1.go = "Chani_9";
		break;

		case "Chani_9":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "��� ������ ��� �� ������ �� ��� �����������!";
			link.l1 = "� ������ �� � ���, ����� ���������?";
			link.l1.go = "Chani_10";
		break;

		case "Chani_10":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_5.wav");
			dialog.text = "� ���� ���� �������!";
			link.l1 = "";
			link.l1.go = "Chani_11";
		break;

		case "Chani_11":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_HUI.wav");
			dialog.text = "";
			link.l1 = "��, ��, ��....";
			link.l1.go = "Chani_12";
		break;

		case "Chani_12":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! ���� ��� - �� ���? ������ �� �����, � ������ ��������� � ������ ������ �����, ��� �� ������ ����������...";
			link.l1 = "";
			link.l1.go = "exit_2";
		break;

		case "Exit_2":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("Chani_Dieenemy");
		break;

		case "Chani_15":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! ������ �� ��������, ���� ����� � ���� ������ �����, ��� ����� ���� �����, ��� �� ������� ��� ����, ��� � ���� �������, � �� ������ ������\n�������� �� ���� ������, ��� ����� � ���� ������� �� ��������� � ����� ����� � ��� � ������� � �������� ��������\n��� ����, � ��������� ����� ��� ��� �����������.";
			link.l1 = "��� ����, ����� �� ���� ���������� ��������! � ������� ����...";
			link.l1.go = "Chani_16";
		break;

		case "Chani_16":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "��� ������ ��� �� ������ �� ��� �����������! ������ �� ��������� �����.";
			link.l1 = "";
			link.l1.go = "Chani_17";
		break;

		case "Chani_17":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "������...";
			link.l1.go = "exit_3";
		break;

		case "Exit_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("Chani_Dieenemy_8");
		break;


		case "Chani_18":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! � ������, � ������ ������ �����, �� ������� �� �������, �� ��� ����� �� ������.";
			link.l1 = "������.";
			link.l1.go = "exit_4";
		break;

		case "Exit_4":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_6.wav");
		DialogExit();
		npchar.quest.RoseauCharlotteMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_3");
		break;


		case "ChaniMayakDieenemy":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! � ������, ������� ��� ������, � ��� ��������, ��� ���� ���������, �����, ��� �������.";
			link.l1 = "�� ����� � �������.";
			link.l1.go = "exit_5";
		break;

		case "Exit_5":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
		DialogExit();
		npchar.quest.ChaniMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_20");
		break;


		case "ChaniMayak":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! �� ��� �������.";
			link.l1 = "";
			link.l1.go = "ChaniMayak_1";
		break;

		case "ChaniMayak_1":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_6.wav");
			dialog.text = "";
			link.l1 = "����� �� ��!";
			link.l1.go = "ChaniMayak_2";
		break;

		case "ChaniMayak_2":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "�������, ���������! � ����� ������, ���� �����!";
			link.l1 = "������� ���� ����, ��� ����, �� �� ���� ��������.";
			link.l1.go = "exit_6";
		break;

		case "Exit_6":
		DialogExit();
		npchar.quest.ChaniMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_27");
		break;







		



		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


	}
}