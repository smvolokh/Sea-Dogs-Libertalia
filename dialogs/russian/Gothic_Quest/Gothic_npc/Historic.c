// boal ������ � ���������

void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
dialog.text = "�����������. ���� ����� ���� �� ������. � ��� ���� ����� �������������?";
        		link.l1 = "���� ����� " + GetFullName(pchar) + ".";
        		link.l1.go = "Step_1";
			break;
case "Step":
dialog.text = "� ������ � ��������� ����������������� � ������� �������... � � �����, ����� �� �����, ����� ����, ������� � �� ����, ��������� ����.";
        		link.l1 = "�����" + GetSexPhrase("","�") + ", ��� �����...";
        		link.l1.go = "exit_2";
if (pchar.questTemp.Ascold == "Seek_powder" && NPChar.id == "Historic")
			{
			dialog.text = "� ������ � ��������� ����������������� � ������� �������... � � �����, ����� �� �����, ����� ����, ������� � �� ����, ��������� ����.";
			link.l1 = "� ��������� ��� �������, ������� ����� �������� �� ������������. �� � ������ � ��� �� ����� ������� �������!";
			link.l1.go = "mummy";
			}
        		link.l2 = "������ ��������, ������?";
        		link.l2.go = "Step_3";
		break;

 		case "Step_1":
        	dialog.text = "��� �� � ��� �� �����������?";
    		link.l1 = "� - ������� �������.";
    		link.l1.go = "Step_2";
		break;

 		case "Step_2":
        	dialog.text = "����������, �������...";
    		link.l1 = "��?";
    		link.l1.go = "Step";
		break;

 		case "Step_3":
dialog.text = RandPhraseSimple("������� � ���� ������� ������� ����������? ��� �... ����� ��������� ����...", "������� � ���� ������� ������� ����������? ��� �... ����� ��������� ����...");
        		link.l1 = RandPhraseSimple("�� � ���� ������...", "�� � ���� ������...");
            link.l1.go = "Step_4";
		break;

 		case "Step_4":
            DoReloadCharacterToLocation("VillaAlegria_town2", "reload", "houseF5");
           NextDiag.CurrentNode = "Step";
		DialogExit();
		break;

		case "mummy":
        	dialog.text = "����������� ������ ���.";
    		link.l1 = "������ �������� ������� ���������� �����...";
    		link.l1.go = "mummy_1";
		break;

case "mummy_1":
        	dialog.text = "����� ��������� ������, � � ��� ������, ��������? �������� ��� � ��������� ������� ����� ��� ��������, ��� �� ��� ��������...";
    		link.l1 = "���, ��� �� �� ������? ����� ������ �� �����, ��� �����, �� �� �������.";
    		link.l1.go = "mummy_2";
		break;

		case "mummy_2":
        	dialog.text = "��-�� � ���... � �� ������ �����. ���������� �� ���� ������� ����������� �� ����� ����� �����. � �� �� ����� � �������. ���� � ����� �� ���� ������� ���� ������ �������?";
    		link.l1 = "�-��... � �����, ���������� ����? ����� �����. ���� ������� ����� ������, � � ��� ��� ������� ������� ����� �� ����.";
    		link.l1.go = "mummy_3";
		break;

case "mummy_3":
        	dialog.text = "�����, ��������? � �� �������������� �� ������ ��� ��������?";
    		link.l1 = "�� ���, �� ������... �������� �������� ��������� ��������. ��� ������ ��������, ��� ��������� �� ����� � ��������� ���� ������� ��� �����... ��� �����... ";
    		link.l1.go = "mummy_4";
		break;

case "mummy_4":
        	dialog.text = "������ �� ����������. � ����� � ��� �� ��������. ��� �, ������ � ��� �������. ������ �� ��������� ��������� ����-��. ������, ��� � ��� ����� �� ���� � �� �������� ���� ���������� ����.";
    		link.l1 = "��, ��� � ��� �������...";
    		link.l1.go = "mummy_5";
		break;

case "mummy_5":
        	dialog.text = "������. � ��� ������ ����.";
			if (sti(pchar.money) >= 1000)
			{
				Link.l1 = "�������, ������, �� ��� � �� ������������. ���, �������.";
    		    Link.l1.go = "mummy_6";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");			
			}
			else
			{
				link.l1 = "��� ����! � ���� � ����� ��� �������. ������ ������ � ����� � ���. �� ����������, ����������, ���� � ������ ����...";
				link.l1.go = "Exit_3";
			}
		break;

		case "mummy_1488":
        	dialog.text = "������, ���������, ��� � ��� ������ ����.";
			if (sti(pchar.money) >= 1000)
			{
				Link.l1 = "�������, ������, �� ��� � �� ������������. ���, �������.";
    		    Link.l1.go = "mummy_6";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");
	
			}
			else
			{
				link.l1 = "��� ����! � ���� � ����� ��� �������. ������ ������ � ����� � ���. �� ����������, ����������, ���� � ������ ����...";
				link.l1.go = "Exit_3";
			}
		break;

		case "mummy_6":
        	dialog.text = "���� ��� ��, �� ����� ��� �� ����� ��������� ����. �� ��������.";
    		link.l1 = "�� ��������... � ������� ���, ������ �� ������!";
    		link.l1.go = "Exit_2";
AddQuestRecord("Ascold", "1488");
		break;


		case "mummy_228":
        	dialog.text = "����������� ������ ���, ������.";
    		link.l1 = "� �� ������ ������� �����.";
    		link.l1.go = "mummy_1488";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_3":
			NextDiag.CurrentNode = "mummy_228";
			DialogExit();
		break;


		case "Exit_2":
			NextDiag.CurrentNode = "Step";
			DialogExit();
		break;

	}
}
