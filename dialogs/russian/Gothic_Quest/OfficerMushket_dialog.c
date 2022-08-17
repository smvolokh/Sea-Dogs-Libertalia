
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

		//������������ �� ������ ��������� ���������

		case "Lostpirate":
			dialog.text = "����������� ���, ������ �� ������� �� ��� ��?";
			link.l1 = "��, ������������� � ������� ���� ����� ������� " + GetFullName(pchar) + ".";
			link.l1.go = "OffMspa_1";
		break;
		case "OffMspa_1":
			dialog.text = "� ��������, ��������� ������������� � ������� �������, ��� ����������, �������. ��� � ��� ������?";  
 
			link.l1 = "�� ���, ����� ���������... � �� �� ���� ������� �������. ��� �� ������ ��������?";
			link.l1.go = "OffMspa_2";
		break;
		case "OffMspa_2":
			dialog.text = "��� ���, ������.";
			link.l1 = "�������. � ��� ���� � �����?";
			link.l1.go = "OffMspa_3";
		break;
		case "OffMspa_3":
			dialog.text = "����������. � � ��� �������� ���� ������� ������������ ��������� �� �����!";
			link.l1 = "����� ������ �� ��� �������?";
			link.l1.go = "OffMspa_4_1";
		break;

		case "OffMspa_4_1":
			dialog.text = "�� ��-������ ��� ������ �������, � ��-������ �� ������� � ����� �� ������!";
			link.l1 = "��� �� ���, �� ���������� ���������, ����� ���������� � ���� ����� ����?";
			link.l1.go = "OffMspa_4_2";
		break;

		case "OffMspa_4_2":
			dialog.text = "� ��� ��� ��� � ���� ��� ������, ����� ��������. �� ������� �������������� ��� ��������� ��� �������� ��������� �������� �� ������ � �����, ���� ���� ���� �� ����� � �� ���� �� �� �����, �� �� ��� �� ����, ����� ��� ��������� ���������� �������, ��������� ���, �� ��������� ��������� � �� ������ �������� ���� �������\n �� �������� �� ����� ���������� ������ ����� ������, ��������� ��� � � ��� �������� �������� �  ����� � ���������� ������������� ���� �����������, ������� ���������  ��������� � ���� �������� ����� ���������, � ������� ��� �������� �������� � ���� � ��������� �� ��� ������ �������\n ����� ���� ����� ��� ������� � ������� ����� � �� ����� �� �����, � �� �������� ����� ���� ���� �� �������� ��� ��� �� ������. ������ �� ����� � �������� � ����������� � ����������� ������������, ���������� ������ � ������, ��� �� ��� �������� ��� �� ������������ ������ ������� ������� � ��� ����� ��� ������ ��� ��������� ���� �������������\n ������ ����� ����������, ��� �������� � �������� � ������ ���� �� �� ����������� � �������� �����, ��������� ����� �������� �������������� �������� �� ��������� ���������, �� � ����� �� ������, ������ ���� ������ � ��������� �� ������� �����, ��� ����� �������.";
			link.l1 = "� ������ �� ����� ����?";
			link.l1.go = "OffMspa_4_3";
		break;

		case "OffMspa_4_3":
			dialog.text = "�����!";
			link.l1 = "������ ��� ���, ��� ������� �������� �����. � ��� � ����������?";
			link.l1.go = "OffMspa_4_4";
		break;

		case "OffMspa_4_4":
			dialog.text = "�� � ��� ����� ����� ������ ����������, � � ����.-��� � �� � ����� �������!";
			link.l1 = "������ �� ������� ������?";
			link.l1.go = "OffMspa_4_5";
		break;

		case "OffMspa_4_5":
			dialog.text = "��� ����� �� �������!";
			link.l1 = "� �� ��� �������, ������ ����� ���������?";
			link.l1.go = "OffMspa_5";
		break;

		case "OffMspa_5":
			dialog.text = "������� ����������� ��� �� ��������� ������� � ��� �������� �������� � �����. ������ ������� ������� ������ ����� ��������. �� ���� ������ ������, �����, �� � ���� �������� �� 30000 ��������.";
			link.l1 = "� ��� �� �������, ��� ��� ��������?";
			link.l1.go = "OffMspa_trade";
			link.l1 = "��, ������, � ������" + GetSexPhrase("��","��") + ".";
			link.l1.go = "OffMspa_Ok";

		break;
		case "OffMspa_trade":
			dialog.text = "���, � ���� ������� ������.";
			link.l1 = "��, ������, � ������" + GetSexPhrase("��","��") + ".";
			link.l1.go = "OffMspa_Ok";
		break;
		case "OffMspa_Ok":
			Npchar.quest.OfficerPrice.add = sti(pchar.rank)*1000;
			dialog.text = "������. �� ��� ��� �� ���. � ������ ��������������� �������, ��� �������. ������������ ��� ������, ��� � ���� �������� �����. �����, ��� " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " ���� �������.";
			link.l1 = "����?!!";
			link.l1.go = "OffMspa_Ok_1";
		break;
		case "OffMspa_Ok_1":
			dialog.text = "����! � ����� �����... � �����, �������.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "��� � ���� ����� �����.";
				link.l1.go = "OffMspa_noMoney";
			}
			else
			{
				link.l1 = "��� ����� ������ ��� ����.";
				link.l1.go = "OffMspa_noMoney";
				link.l2 = "������, � ������" + GetSexPhrase("��","��") + ".";
				link.l2.go = "OffMspa_Ok_3";
			}
			NextDiag.TempNode = "OffMspa_TWO";
		break;
		case "OffMspa_noMoney":
			dialog.text = "������, ���������, ��� ������������. �����.";
			link.l1 = "�������...";
			link.l1.go = "exit";
		break;
		case "OffMspa_Ok_3":
			AddMoneyToCharacter(Pchar, -30000);
			dialog.text = "���, ������ ������ ������ ����! � ����� ��� ������� ����� � �������.";
			link.l1 = "�������. ����� ���������� � �������.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			AddQuestRecord("TwooDoubleMushket_1", "1");
			CloseQuestHeader("TwooDoubleMushket_1");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "quest_mush_1";
			npchar.model.animation = "mushketer";
			npchar.MusketerDistance = 5;
			npchar.greeting = "Gr_questOfficer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);			
			npchar.OfficerWantToGo.DontGo = true; //�� �������� ����
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();
		break;
		case "OffMspa_TWO":
			dialog.text = "�� ���, ��� ��� � ��� ���� � ���������? �������, ��� � ���� " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " ��������������� ������� � " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " ������������ ���������.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "���, �� ������ ����...";
				link.l1.go = "OffMspa_noMoney";
			}
			else
			{
				link.l1 = "��� ����� ������ ��� ����.";
				link.l1.go = "OffMspa_noMoney";
				link.l2 = "������, � ������" + GetSexPhrase("��","��") + ".";
				link.l2.go = "OffMspa_Ok_3";
			}
			NextDiag.TempNode = "OffMspa_TWO";
		break;






	}
}











