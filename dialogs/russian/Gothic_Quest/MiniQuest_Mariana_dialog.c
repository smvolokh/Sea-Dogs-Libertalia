// ��������
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
            	dialog.text = "������ ����, ���" + GetSexPhrase("��","���") + ".";
        	link.l1 = "�����������.";
        	link.l1.go = "1";
		break;

		case "1":
            	dialog.text = "����������� ���. ��� ��� "+ GetFullName(NPchar)+". � "+NPCharSexPhrase(NPChar,"������","����������")+" ����� ����������� ������ �� �������, ���� �� � ���������, � ��� �� ���������� .";
        	        	link.l1 = "������� ���� ����! , ������ ������! , ���� ���� ����� ����! �� � ������� "+ GetFullName(Pchar)+ " �������?, � ���" + GetSexPhrase("��","��") + " �������" + GetSexPhrase("��","��") + " �����" + GetSexPhrase("","��") + " � ���� �����!. ������ �������� ���� ������� "+ GetFullName(Pchar)+", ���" + GetSexPhrase("","�") + " ���������� .";
        	link.l1.go = "2";
		break;


		case "2":
            	dialog.text = "��� ���� ����� � ����� �������! �������, ������� " + PChar.name + ", ��� �� ����� �������? �, ����������, ���� ��� ����� �������.";
        	link.l1 = "�� ���, ����, ����� � ��� �����, ������ ���������� � �������� � ����� �����, ��������� �� ����� ��-�� �� ��������?";
        	link.l1.go = "3";
		break;

		case "3":
            	dialog.text = "��� ������� ��� �� ���������, ���� ��� ����� �� ����� ��-�� �� ��������, ������� ����� �����, ������� � ���������.";
        	link.l1 = "�-��, �������, ��� ��� ���� ��������, ����� ����� ����� �� ��������� ����� �����, ������� ��� ����� ��� �������?";
        	link.l1.go = "4";
		break;

		case "4":
            	dialog.text = "�����, �� ���� �������� ���������� ����� ����� ������, �������� ������� �� �������� .";
        	link.l1 = "�������, ��� ��� ������ ������ ��������� �� ���� ���������, ����� ����� � ���� � ������� �������, ��� ���������� � ���� �����, ��� ����� ����� �� ����?";
        	link.l1.go = "5";
		break;

		case "5":
            	dialog.text = "����� ��� ����� ���� �� ���� �������, �� ���� ���� �� ���� � ��� �� ����� ������� ����� ������, ����� ��������� � ���� �����!";
        	link.l1 = "������������� �� ���������� ��������, �� ��� ����� �������!";
        	link.l1.go = "6";
		break;



		case "6":
            	dialog.text = "�� ����� ����� �� �����!";
        	link.l1 = "�� ��� ��� �������, ��� �������, � ������� �����. ��������� ���-������ � ������ ���.";
        	link.l1.go = "7";
		break;

		case "7":
            	dialog.text = "A ��� �����!";
        	link.l1 = "����� ��� ��� �����. �� ��� �� ������.";
        	link.l1.go = "7 End";
		break;

 		case "7 End":
                NextDiag.CurrentNode = "Fifth time";
		DialogExit();
		break;

	case "Fifth time":
            	dialog.text = "������������, ������� " + PChar.name + "! ��� ����?";
        	link.l1 = "���� �� ������. ��������, �� � �����.";
        	link.l1.go = "8";
		break;

		case "8":
            	dialog.text = "�������, ������� �� ���� ��� �����������.";
        	link.l1 = "";
        	link.l1.go = "7 End";
		break;

/// ******************** ������ ������ *************************
	case "Mary Toulien":
            	dialog.text = "�������� ����� ����, ����� �����. �� ������ �� ���� ����� ������ ����� �������!";
        	link.l1 = "�� ������ � ���� ���������� �����? ������� ����������� � ����� �������? �� ���� � � ����� ����������.";
        	link.l1.go = "Mary Toulien to Paul";
				NextDiag.TempNode = "Mary Toulien 1";			
		break;	
	 	case "Mary Toulien to Paul":
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			DoQuestCheckDelay("HumWeapPE PaulToulien dlgNow", 1.0);
		break;	
	case "Mary Toulien 1":
            	dialog.text = "��� � � � ��� ��� ������, ����� �����. �� �� ������ ���� �� �������! ׸���� �����, �� � ���� �� ��, ������ � ������ ������� �� ��������!";
        	link.l1 = "����, ��� � ����� ������ ���� �������? ��� �� ���� �����? ���... �����-�� ��������? �� ��������� ���� ���� ��� ���?";
        	link.l1.go = "Mary Toulien to Paul";
				NextDiag.TempNode = "8";			
		break;			



	}
}

