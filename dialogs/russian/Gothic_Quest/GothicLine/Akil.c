// ���� ������ ��������
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
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_EXIT_13_02.wav");
            	dialog.text = "����, ������ ��� ������ ��� - ������.";
        	link.l1 = "";
        	link.l1.go = "exit";
		break;


	case "Exit1":
				dialog.text = "��, ��� ��, ������� "+ GetFullName(Pchar)+"? ��� ������������ ���� ���� �� ������ ����� ���������?";
				link.l1 = "��� � ������ �������, ����.";
        	link.l1.go = "Exit";
		break;

		case "1_1":
 	PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_1.wav");
			dialog.text = "";
			link.l1 = "��� ��?";
			link.l1.go = "1_2";
		break;

		case "1_2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_01.wav");
			dialog.text = "���� ����� ����, � ������ �� ���� ��������� ������ �����!";
			link.l1 = "";
			link.l1.go = "1_3";
		break;

		case "1_3":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_LIEFERUNG_15_00.wav");
			dialog.text = "";
			link.l1 = "���� ������� ��������, � ������ ������� ������� ��� ����.";
			link.l1.go = "1_4";
		break;

		case "1_4":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_LIEFERUNG_13_01.wav");
			dialog.text = "��� �� ��� ����� ���������, ������ � ��� ���������� �.";
			link.l1 = "";
			link.l1.go = "1_5";
		break;

		case "1_5":
		PlaySound("interface\important_item.wav");
		GiveItem2Character(pchar, "cask_whisky");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicDelivery_Baltram");
		break;









		
		case "1":
			dialog.text = "";
			link.l1 = "� ����" + GetSexPhrase("��","����") + " ��� ������ ����� �� ��������� � ������.";
			link.l1.go = "2";
		break;
		
		case "2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_EHRE_13_01.wav");
			dialog.text = "�� ��������� ����, �� ������ ���� ����� �� ���� ����?";
			link.l1 = "";
			link.l1.go = "3";
		break;
		
		case "3":
			TakeNItems(PChar, "BaltramNotice_0", -1);
			dialog.text = "...(������ ������)... ��� ��� ��! �������� �����, ��� �� ����� ������ ��������. �������, ������ �����.";
			link.l1 = "������ �� ���-�� ������� � ��� �� ������" + GetSexPhrase("","�") + ". ��������, ����, ���� �����, ��������� � ����? �� ���� ���� ����, � ��� ���� �������. �������, �������, �������� � ����.";
			link.l1.go = "4";
		break;
		
		case "4":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_AKILSSCHAF_13_01.wav");
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, 50);
			dialog.text = "����� ������, ��� ��������� �������, ����� ����� ���� ������� ����� ����������.";
			link.l1 = "�� �������������� � ���� �������. ����� ���� ����� �� ���������.";
			link.l1.go = "5";
		break;
		
		case "5":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 6000);
			dialog.text = "�� � ���� �� � ��� �� ��������������, ���" + GetSexPhrase("��","���") + " "+ GetFullName(Pchar)+". ��� �������� ��� ������, ������, ��� � ������� ���� �����. ���� ��� ������, �������� ���� ������ � ���������. � ���� ������ ����� ���.";
			link.l1 = "���, �� ��������� ���, ����! ���� �������������, ��� �� ��������� ��������� ��������� ���, � ��� ���������. �� ���� ��� �� ������. ���������� ������� ������ ���... ��� � �� ���� �� ������� . � �����������" + GetSexPhrase("","�") + ".";
			link.l1.go = "6";
		break;
		
		case "6":
                                                         PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\GELDBEUTEL.wav");
			AddMoneyToCharacter(PChar, 1000);
			dialog.text = "��, ������, ������, ��� ���� ������. ��������" + GetSexPhrase("��","���") + "?";
			link.l1 = "��, ������� �� ���� ���� ���, ���� �� ������� ����.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "���� �� ���-�� ��������. ����� ���������� �������� � ����, ��� �� ����� ��� �� ����� �������� �� ���� ������. ������ �� ��������������� ������� � �� ���������� ������� ����-������ �� ���� �����. �� �� ��� ���������! ������ ���������� ������. � � ���� ���� ��� ��� ������. ������ ����� ������.";
			link.l1 = "������ ���� ����������� ��� ��� ����...";
			link.l1.go = "8";
		break;
		
		case "8":
			dialog.text = "...(���������)... ���, �������, ���, ������ �������. �������� � ������� ������, � �������� �������� �������. ������?";
			link.l1 = "��� � ����, ���� ��������.";
			link.l1.go = "9";
		break;
		
		case "9":
			dialog.text = "��� � ������, ��� � ������! ���� ����� ���.";
			link.l1 = "��������� ����������.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryTimer");
		break;



		
		case "10":
 	                                      PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_HELP.wav");
			dialog.text = "��������!!!";
			link.l1 = "";
			link.l1.go = "10_1";
		break;

		case "10_1":
	                                       PlaySound("VOICE\Russian\GOTHIC\RENGARU_01.wav");
			dialog.text = "׸��, � �������� �� ����!!!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilExit");
		break;



		
		case "11":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_15_02.wav");
			dialog.text = "";
			link.l1 = "��� ��� ����?";
			link.l1.go = "2_11";
		break;

		case "2_11":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_00.wav");
			dialog.text = "����� ������, � ��� ����� ��� �����!";
			link.l1 = "";
			link.l1.go = "2_12";
		break;

		case "2_12":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_04.wav");
			dialog.text = "��� ������� � ����� �����, ��� �������, ������ � �����, ��� ������� � �������!";
			link.l1 = "";
			link.l1.go = "2_13";
		break;

		case "2_13":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_05.wav");
			dialog.text = "� ������ �������, �� �� ����?";
			link.l1 = "��, ������� ������.";
			link.l1.go = "2_14";
		break;

		case "2_14":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_13_06.wav");
			dialog.text = "��, ����� ������ �� ����� �� �����, �����, ��� � ���� ������� ��� ����?";
			link.l1 = "";
			link.l1.go = "2_15";
		break;

		case "2_15":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_NACHKAMPF_GOLD_15_00.wav");
			dialog.text = "";
			link.l1 = "��� ������ ���������� �������.";
			link.l1.go = "2_16";
		break;
		
		case "2_16":
			AddMoneyToCharacter(PChar, 5000);
			dialog.text = "����� ����! ��� ����� 5000 ���� �� ������. ���� �� �� ��, ���� �� ����� ��� �� ����.";
			link.l1 = "��� ��� � ���� �� ������, ������� �� ����� ��� ��������?";
			link.l1.go = "2_17";
		break;
		
		case "2_17":
			dialog.text = "���, ���, � ����� ��������� ��������� ����. �� ��� ��������� ��� ��������� � ������ ��������� ��� ����������. � ����, ��� �� ������ �� ���, � ���������� ����� �����, ��������� ������ �������.";
			link.l1 = "��� �� ���� �� �������� � ������ ���! ���� ������ ����� ���� �����, ��� � ��������.";
			link.l1.go = "2_18";
		break;
		
		case "2_18":
			dialog.text = "� ������ �� ���� ������� ����� � �����, "+ GetFullName(Pchar)+". � �� �������" + GetSexPhrase("��","��") + " " + GetSexPhrase("����","�������������") + ", �� ����" + GetSexPhrase("","�") + " ��������, � � ��� ������, ��� �� ������� ��������� � ���� �����. �������.";
			link.l1 = "�� �� ������" + GetSexPhrase("","�") + " � �������� ��� ���� �������� ������, ����� �� �������� ���, � �����" + GetSexPhrase("��","���") + ". � ��� ������ ������? ���� �����-�� ���� ���� ���� ���������?";
			link.l1.go = "2_19";
		break;
		
		case "2_19":
			dialog.text = "�������� ����� � ������ ������� ��������, � ��� ���� ���� ���������� �����. � ����, ��� �������� ��� ����� � ���� � ��� �����������. ��� ��� ������ ��������, ������� �� ��� ������� ��� ��������. � ����, ����� �� ��� ����" + GetSexPhrase("","�") + ". ������" + GetSexPhrase("��","��") + "?";
			link.l1 = "������� ���������?";
			link.l1.go = "2_20";
		break;
		
		case "2_20":
			dialog.text = "� ������� ��� ���� ������ 20 000 ���� � ��������� ����������� ������. �� ����� �������� � ��� � ���������. �� ���, ������" + GetSexPhrase("��","��") + "?";
			link.l1 = "�������. ��� ��� � ��� �� ����.";
			link.l1.go = "2_21";
		break;
		
		case "2_21":
			dialog.text = "��� ��� ������, �� ���� � �����������, � ����-��������, � ������� �� ������ �� ������. ��� ������ - ��� ���������� ����.";
			link.l1 = "������, � �����" + GetSexPhrase("","�") + ".";
			link.l1.go = "2_22";
		break;
		
		case "2_22":
			dialog.text = "��� � ������, ��� � ������! � ���� ����� ���� � ���� ����. ����������� ����.";
			link.l1 = "�������� ���, ����.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilBackToHouse");
		break;

		case "12":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_15_00.wav");
			dialog.text = "";
			link.l1 = "� ���� ����� - �� ��������?";
			link.l1.go = "12_1";
		break;

		case "12_1":
	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_13_01.wav");
			dialog.text = "���, ���, ���, �� � �������, ���� ����� ���� ������.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Angardo");
		break;

		case "12_2":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_15_02.wav");
			dialog.text = "";
			link.l1 = "�� � ���� ������... � ���� � ���� ���� ��������...";
			link.l1.go = "12_3";
		break;
		case "12_3":
 	PlaySound("VOICE\Russian\gotica\AKIL\DIA_AKIL_HALLO_13_03.wav");
			dialog.text = "�, ��, ��, �� � �������, � ������ �� ���� �������� � �����...";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Angardo_1");
		break;



 		case "Exit":
                NextDiag.CurrentNode = "Exit1";
		DialogExit();
		break;


	}
}
