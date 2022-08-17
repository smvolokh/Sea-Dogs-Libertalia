
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� � ��� ��������.";
			link.l1 = "�����...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Avroraaa_1":
			dialog.text = "�� ���������, ����� ��� �� ���������?";
			link.l1 = "� ���� � ����, ��� �������� ���� ��������, �� ���� ���������� ����� ��������.";
			link.l1.go = "Avroraaa_2";
		break;
		case "Avroraaa_2":
			dialog.text = "��, ��� ���, (������) ������ ����� � ������� �� ������?";   
			link.l1 = "�� �������� ������, �������� ����� � � ������ ����� ����� �� ������?";
			link.l1.go = "Avroraaa_3";
		break;
		case "Avroraaa_3":
			dialog.text = "������ �� ��� ���������! � ���������� ����, ���� ������ ��� ����� ���������.";
			link.l1 = "�������, ���� ����� " + GetFullName(pchar) + ", � �������, ������� ����� ������!";
			link.l1.go = "Avroraaa_4";
		break;
		case "Avroraaa_4":
			dialog.text = "�� � � (������), � �� �������, �������� ���� �������!";
			link.l1 = "�� ����� ���, �� ��� ������, �����-�� ���� ������ ������ ���������?";
			link.l1.go = "Avroraaa_5";
		break;

		case "Avroraaa_5":
			dialog.text = "���� ����� ������, � ������, ��������� �� ����� � � �� ��������� (������)!";
			link.l1 = "������ � ������� �� ��� �� ������, ����� ���� �� ���������?";
			link.l1.go = "Avroraaa_6";
		break;

		case "Avroraaa_6":
			dialog.text = "�������, �� �� ������������� ��� � ���� ������ �������� ������. ������� �� �����, �� ��� ��� ����� - ������.....";
			link.l1 = "�������. ����� ���������� � �������.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			CloseQuestHeader("TwooDoubleMushket_1");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "Avrora_1";
			npchar.model.animation = "Avrora";
			npchar.greeting = "Gr_Avrora";
			npchar.Dialog.Filename = "Enc_OfficerGirl.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);			
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();
		break;


	}
}




