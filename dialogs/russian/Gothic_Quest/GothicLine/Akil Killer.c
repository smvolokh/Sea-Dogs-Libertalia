// �������
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
			dialog.text = "��� ��� ����?";
			link.l1 = "������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

//*************************** A������� **********************************
		
		case "1":
			dialog.text = "A�������: �� ���, ����, ����� ������� ��������. �� ���� ���� ��������� ����, �� ������������ ��� � ������ ��� ����� �����.";
			link.l1 = "����: � �� ���� ������� �� ����, A�������, �...";
			link.l1.go = "2";
		break;
		
		case "2":
			dialog.text = "A�������: ���?! ����, �� ����� �� ������������� ����, �?";
			link.l1 = "����: �� � �� �� ����� �����, ����� �������� ����, �� ����-������, ������ ����. �� ����� ��� ������ ������ ���� ����� ���������� �� ���� �����! � ��� �� ��� ������� �� ���� �� ��� ������, ���� � ���� ���, ���� �� ������, ��� � ���� � ����� �������� ��������.";
			link.l1.go = "3";
		break;
		
		case "3":
			dialog.text = "A�������: ������, ������ �� ��� �� �����, ����?";
			link.l1 = "����: � ������� �� �� ���������. ��� �����. ��� ������� ���� ����������� ���� � ������� ��.";
			link.l1.go = "4";
		break;
		
		case "4":
			dialog.text = "A�������: ����, �� ���� ��������, �� �������� ������ ���� � ���� �����!";
			link.l1 = "����: ���! �� ������ ����, A�������, � �� ��������, ������ � �� ���� �� �����.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "A�������: ��� ��� �� ����������. �� ������� ����, ����� ������� ������ ���� �����. ������ ����� �� ��������� ��� �� ��������� � �����-�� ����������. ���, ����, �� ������ ����� ����, ����� ��������, ��� �� ������������� ������� ��� ������.";
			link.l1 = "����: ���! ���, A�������, �� ������ ����! ���, �����...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Akil");
		break;

		case "5_1":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_15_00.wav");
			dialog.text = "";
			link.l1 = "��� �� ����� ��������!";
			link.l1.go = "5_2";
		break;

		case "5_2":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_11_01.wav");
			dialog.text = "� �� ��� ��� ���� ��������, �� ��������� ������ ����, ��� �� ����� ��.";
			link.l1 = "";
			link.l1.go = "5_3";
		break;

		case "5_3":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_11_02.wav");
			dialog.text = "�� �� ���������� ������� ����� ���� ������� � ����� � � ���� ���� �� ������ �� �� ������� �� ����.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Akil_1");
		break;


		case "5_4":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_HAUAB_11_00.wav");
			dialog.text = "��� �� �� ������� ���� ����, ���� ����� ������ �� ���� � �������� �� ������.";
			link.l1 = "";
			link.l1.go = "5_5";
		break;

		case "5_5":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_15_00.wav");
			dialog.text = "";
			link.l1 = "��� �� ����� �����, ���� �������...";
			link.l1.go = "5_6";
		break;

		case "5_6":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_11_01.wav");
			dialog.text = "�� ��������� ����� � � ���� ���������� �������� ����� ���� ���� ����� ������ � �������� ����.";
			link.l1 = "";
			link.l1.go = "5_7";
		break;

		case "5_7":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_15_00.wav");
			dialog.text = "";
			link.l1 = "�� ����� ������ ��������� �� ���� - �� �������?";
			link.l1.go = "5_8";
		break;

		case "5_8":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_01.wav");
			dialog.text = "������ - ��, ����� ����� ����������� � ����� ������ �����.";
			link.l1 = "";
			link.l1.go = "5_9";
		break;

		case "5_9":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_02.wav");
			dialog.text = "�� ������ � ��� � �����!";
			link.l1 = "";
			link.l1.go = "5_10";
		break;

		case "5_10":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_15_03.wav");
			dialog.text = "";
			link.l1 = "�� ���� ����� ���� � ��� �� �������...";
			link.l1.go = "5_11";
		break;

		case "5_11":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_04.wav");
			dialog.text = "� �����, ��� ������� ����� - ��� ������� �����, ���, ��� ������ ��� ��������� - ���� ��������.";
			link.l1 = "";
			link.l1.go = "5_12";
		break;

		case "5_12":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_11_02.wav");
			dialog.text = "�������, ����� ��������, �� ����� �� ���� ������� � � ��������� � ���� �������.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilKill");
		break;


//*************************** ������� **********************************

		case "6_1":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_00.wav");
			dialog.text = "�� �����, ��, ��� ����������? ����������� �� ��� ���� � ����� ����.";
			link.l1 = "";
			link.l1.go = "6_2";
		break;

		case "6_2":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_01.wav");
			dialog.text = "�� �������� �� � ��� �����, �� � �� �����.";
			link.l1 = "";
			link.l1.go = "6_3";
		break;

		case "6_3":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_02.wav");
			dialog.text = "���, ��� ���� ������ ���� ����� ����� �� ���� - �����!!!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Alvares");
		break;

		case "6_4":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_03.wav");
			dialog.text = "� ����, ��� �� ������ �� �� � ������� ��� ���� ����� ������� �������. ����� �� ����� ��� ������� ������...";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Alvares_1");
		break;


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
