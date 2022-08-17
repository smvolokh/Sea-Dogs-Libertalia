// ����� ������� ��������
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
 	                                   PlaySound("VOICE\Russian\citizen\Indeyci-05.wav");
			dialog.text = "����� - �� ��� �� ���� �����, � ����� ��������� ��?";
			link.l1 = "�� � ���!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "1":
 	                                   PlaySound("VOICE\Russian\citizen\Indeyci-08.wav");
			dialog.text = "������� ����? ������ �������� ����.";
			Link.l1.edit = 1;
			Link.l1 = "";
			Link.l1.go = "2";
			NextDiag.TempNode = "1";
		break;
		
		case "2":
			string sString = GetStrSmallRegister(dialogEditStrings[1]);
			if(sString == "��� � ������, ��� � ������" || sString == "��� � ������ ��� � ������")
			{
				AddMoneyToCharacter(PChar, 25000);
				dialog.text = "��� ���� ������.";
				link.l1 = "������, �����, � � ��� ���� ���������� ����� ������ ������, ��� ����� ��������. ��� ����� ������� �����, ����� ����������� � ���� ������ �����. ��� ��� �����?";
				link.l1.go = "3";
			}
			else
			{
				dialog.text = "�������� ���� �������. ����� ������ �� ����� ���� � " + GetSexPhrase("����� ����","����� ������") + ".";
				link.l1 = "����!..";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("GothicLine_DeliveryDialogWithCharlyFailed");
			}
		break;
		
		case "3":
			dialog.text = "����� �� �����, ��� ���� ����. ����� ������ ������ ������. ����� ������ ������ �� ������.";
			link.l1 = "�����, ���� ���� �� ����� ������������? �� �����? ������ ���, ��� ����, � � ���� �� �� �����.";
			link.l1.go = "4";
		break;
		
		case "4":
			dialog.text = "����� �� ���������, � ��� �������� " + GetSexPhrase("����� ����","����� ������") + ". ����� �� ��������.";
			link.l1 = "�� �� ����������. ������� ��� ���. �� ��������, ��� ���� - ���� ������������, ����� �����. ��������, ��� ���� - ��� �������������, ����� ������.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "����� ������ �� �����, ����� ������ ������ ���� ����, �������� ������.";
			link.l1 = "������ ������������, �����. ������, � ������ ����...";
			link.l1.go = "6";
		break;
		
		case "6":
			dialog.text = "���! ���! ����� �������, ����� �������! ����� ������ � ������� ���� - ������, � ������� ���� - ������, ����� ���, ����� ����� �����.";
			link.l1 = "�������.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "" + GetSexPhrase("����� ����","����� ������") + "! �� ���� �������� �����, ��� ����� ��� ��� �������, �� ���� �������� �����, ����� ������ �� ������ �����.";
			link.l1 = "������, �� �����.";
			link.l1.go = "8";
		break;
		
		case "8":
			dialog.text = "����� �� �������, ����� �� ������ �����. �� �� ������ �����?";
			link.l1 = "�� �����. ��, ������ �� ����.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithCharlyGood");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
