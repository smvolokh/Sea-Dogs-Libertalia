void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	int iTemp;
	string sTemp;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "������������! ��� �� � ���� "+ GetSexPhrase("��� �����, ��� �����","�� �������, ��� ������") +" ��������� �� ���?";
			link.l1 = "��, ��� � � ����.";
			link.l1.go = "FT_1";			
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//����������� �� � ��������
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("�� �� ���"+ GetSexPhrase("","����") +"!!! ��������� ������ ������!", "��� ��� ��! ���� � ����������, � �� ����� � ������ � �������! ��"+ GetSexPhrase("","�") +" �������"+ GetSexPhrase("","�") +" �����!", "�������! ������!!! ����� "+ GetSexPhrase("���, �� �������","��, ��� ��������") +" �����!");
			link.l1 = "�-���, ������!!!";
			link.l1.go = "fight";
		break;
		case "Woman_FackYou":
			dialog.text = "��, ���, ������, ���?! �� �������� ������ ��������?! ������ �������� � ������� ������ ����, ��� ������ ������!";
			link.l1 = "��� ����!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		//��������� �� ����������� ������
		case "LSCCNotBlade":
			dialog.text = LinkRandPhrase("������, �� �� �����"+ GetSexPhrase("","�") +" ������. � �� ���������� �������...", "������, � ��� ��� �� ������� ��������� �����������. ����� ������.", "������, ��� ��, ��� ��� ���������, ������� ���, ������ ������? ����� ������, �� � ���� ��� "+ GetSexPhrase("���������� �������","�������") +"...");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "����������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
				link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "���������� �� ���������, "+ GetSexPhrase("��������","�������") +", ����� ������ � ������� � �����. � ���� ���� � ������������...", "��� �� ��������, ����� "+ GetSexPhrase("�������","��� ������") +" ����� ������ ���� � ������� �����������. ��� ���� ������...");
				link.l1 = RandPhraseSimple("�����"+ GetSexPhrase("","�") +".", "������.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;


		case "FT_1":
			dialog.text = "������, ����� ������... ������ �����, �������� ����, "+ GetSexPhrase("��� ����������� ����","���������� ��������") +".";
			link.l1 = "���� ����� ������� " + GetFullName(pchar) + ". � ��, ��������� � ���� ������, - ������ �������, �� �������� �������.";
			link.l1.go = "FT_2";
		break;
		case "FT_2":
			dialog.text = "�����!.. � ������ �� ���� ������?";
			link.l1 = "��, ����� �� �����������, ������ �������...";
			link.l1.go = "FT_3";
		break;
		case "FT_3":
			dialog.text = "���-����, � �� ��������. ���������, � ������ ����� ��� ����� ������� � ����������� ������. '�������' - � �� �� ���� ��������� �� ��������. ������, � ����� '������'. �� ���, �� ���� �������?";
			link.l1 = "���� �� �������. � �� ����� � ������"+ GetSexPhrase("","�") +" ��� ��� ��� � ���� '������'.";
			link.l1.go = "FT_4";
		break;
		case "FT_4":
			dialog.text = "��-��, ��� ����� ������ ����� �����������? �-��, ������ �����, ��� ���������\n��, � ������ ���������� ���, ����������, ���� ���� �� ��������� ��� ������������ �������.";
			link.l1 = "��� ��� �������... ���������, � �� ����������� ���������� �����"+ GetSexPhrase("","�") +" �� ���� ������, ��������� ������ ������ ����. �� � ������ ���� �������� ������.";
			link.l1.go = "FT_5";
		break;
		case "FT_5":
			dialog.text = "������ ����? �� ����� ������?";
			link.l1 = "����������� ����� �� ��������, �� ���� �������, ��� �� ������������ �������� �� ������� �����. � ���������, ��� ����� ������ ����������� ����-������� ��������.";
			link.l1.go = "FT_6";
		break;
		case "FT_6":
			dialog.text = "����. �� ������, � ���� ��� � �������� ��� ����, �� ������� �� ���� ������ � �����.";
			link.l1 = "��?! � ��� �� �� �� ��� �������� ����� '��������'?";
			link.l1.go = "FT_7";
		break;
		case "FT_7":
			dialog.text = "�� ����� ������ �� '�������� ���������'. � ���� �� ����� �������� � ��� � ���� �� ���������, ������� ����������...";
			link.l1 = "����������?";
			link.l1.go = "FT_8";
		break;
		case "FT_8":
			dialog.text = "��... ����� �������. ��� ���, �� �������������, ����������, � � ������ ���, ����� �� ����� ������ � ��������� ����� �� ���� �������.";
			link.l1 = "���� �� � �������� �� ����, �� ������ �������� � ������ ����� �������� ��� ������. ����������� ����-������� �������� ��������, ��� � ������ ������������� �������� ���������, � �� ������ ��������� �� ����� ����� �� �������� ����. � ���� ������ ��������� ������� � ������ ��������.";
			link.l1.go = "FT_9";
		break;
		case "FT_9":
			dialog.text = "����. ������, ����� ���-���� ������� ������ ��� �������� �� �����, ���� �������� �� ������ ����� �����. ���� ������, ��� ����, ��� �� �����!";
			link.l1 = "����, �������. �� ������, ������� ������� ����� ������ �� ��������� �����, ��� � ��� �����"+ GetSexPhrase("","�") +" ������...";
			link.l1.go = "FT_10";
		break;
		case "FT_10":
			dialog.text = "��, �� ����� � ��������. �� ������, ��� ���� ����������� �������� ����� ������ ��������� ������. ��� ���� ������ ���. � ��� ������ - ��� �����...";
			link.l1 = "��������? � ������ �� ������?";
			link.l1.go = "FT_11";
		break;
		case "FT_11":
			dialog.text = "����� ������������ �������... �� �����, ���, ����� ��, �����. ������ ���������� ���, "+ GetSexPhrase("���� ���","����� �������") +", ��� �������� � ������ � ����� �� ������ �� ���.";
			link.l1 = "� ������ ����������� ������� ��� ������. �������� ������ ����� �������� ���������� ������, ���� �� ������� ��������� ������� ����� ������������ ��������. ��, � � �������� �����"+ GetSexPhrase("","�") +" � �������� � �����"+ GetSexPhrase("","�") +" ������������ � ���� ����� �����. ���, ����������, � ���...";
			link.l1.go = "FT_12";
		break;
		case "FT_12":
			dialog.text = "��� ������ ������ ������ ������ ��������� �������, ��� � ������...";
			link.l1 = "��, � �� �� ������"+ GetSexPhrase("","�") +", ��� ������. ��� ����� ���������� ���� �� ������, ���������� �������� �������. ���� ���������� ��������� � ��� ��������, ���� ��� � �� ����������� ������ ����������� ������������!";
			link.l1.go = "FT_13";
		break;
		case "FT_13":
			dialog.text = "�� ������, "+ GetSexPhrase("���� ���","�������") +", � ���������� �� ��������, ���� ��������, ��� �� ���� ������������ � ������ ��� ��� ����� ����� �������.";
			link.l1 = "��, �� ������. ������ � ���� ���� ����. � �������������� ����� - ���������� ����� '������' �� ����� '��� ��������'.";
			link.l1.go = "FT_14";
		break;
		case "FT_14":
			dialog.text = "��, '�������' ����������� � ������ � ��������, ������� �������� � ���� �����������... �� ��� ��, ��������� ��� ����� � ������ �������� ����������...";
			link.l1 = "�����! � ������ � ��������� �������� ������ ��������. ���� ��������� ���� ����������� �� ��� ���������.";
			link.l1.go = "FT_15";
		break;
		case "FT_15":
			dialog.text = "����� ������, "+ GetSexPhrase("���� ���","�������") +"! ����� ������� ���� �����, ���� ��� �� ������...";
			link.l1 = "� ��� ��� ��?";
			link.l1.go = "FT_16";
		break;
		case "FT_16":
			dialog.text = "�� ������, ������ ���� ����� ���������?";
			link.l1 = "����. �� ��������� ������ ��������� �������� ������ ����� �����. �� � ������, ��������� � ������"+ GetSexPhrase("","�") +", ���������� ���-������ ������ ��� ��� �� ��������.";
			link.l1.go = "FT_17";
		break;
		case "FT_17":
			dialog.text = "������. ��, ��������, ���������, ��� � ���� � ������ ������, ��� ����� ������ ������. � ���� ��, ������ � �� ����� �������������, � ������ ��� ��������� �����, ��� ��� ������ �������� ������ ���������� �������� ��� �����.";
			link.l1 = "��� �����?";
			link.l1.go = "FT_18";
		break;
		case "FT_18":
			dialog.text = "��. ��������� ��� ����� � ��������� ������ ��� ������� ��� �����. � ���� ������� � ��������� ��� ���� ����� ���, ���� ���� ����� �����������. � ��� ��� � ��� ����� - ����� ��������� ����� �������� ������� �����.";
			link.l1 = "��������� � ����, ������ ����� �� ��������...";
			link.l1.go = "FT_19";
		break;
		case "FT_19":
			dialog.text = "���, � �� ����! �� ������� �� ����, ��� ������ ����� � ������!";
			link.l1 = "������-������... ��� ��� �� ��� �������� ��� ������� ��� �����?";
			link.l1.go = "FT_20";
		break;
		case "FT_20":
			dialog.text = "� ��������� ��� ����, ������ ����. ��� ���, ����� �������� ����� �� ���� ��������, ������� ���������� �� ����. ��������� ������� �������� �������� � ����� �����! ���������, ��� ��� ������?";
			link.l1 = "�-��, ��������� ��� ����������... � ��� �����, ���� ����� ���������? �� ����� � �����?";
			link.l1.go = "FT_21";
		break;
		case "FT_21":
			dialog.text = "������ ���������! �� ������ �� ���, ���� ������� ������ �� �� �����. �� ������� �����, ��� ��� ���������� ������ ����� ����������� � �����, ������ ����� ������� �����.";
			link.l1 = "����������� �����-��... � ����� ��� ����������?";
			link.l1.go = "FT_22";
		break;
		case "FT_22":
			dialog.text = "�� ����. � ������, � �� ������\n� ������, ��� ����� ��������� � ����� ����.";
			link.l1 = "��... � ��� ������?";
			link.l1.go = "FT_23";
		break;
		case "FT_23":
			dialog.text = "� ���� ������ ���, ���� �� �������� ���.";
			link.l1 = "���������� �����������. ���������� ���������, ����������.";
			link.l1.go = "FT_24";
		break;
		case "FT_24":
			dialog.text = "���� � ���, ��� � ���� ���� ��������� ���. ���� ��� ����� � ������� ���������� ��������� ��� �� �������� ��������. ���� � ���� ���� ����� �����������...";
			link.l1 = "�� ��� ��������� ��� ���������� � �����-�� ��������� �����������...";
			link.l1.go = "FT_25";
		break;
		case "FT_25":
			dialog.text = "�-�, �� ��� ����������� ���������� ��� ���� � ���� �������. ���� � ���, ��� ��� ����� �������� ����������� �����, ������� ����� �� ��� � ���� ���, ��� ������. ��� � � �� ������ ������ ����������. � ���� ������, � �� ����...";
			link.l1 = "�������. ��� ��� � ����"+ GetSexPhrase("��","��") +" �������?";
			link.l1.go = "FT_26";
		break;
		case "FT_26":
			dialog.text = "������� �� ������ ������ � ���� ��������� ���. ����� ������� �� ��� ���-���, ��� ���� �� �� ������ ���������� ������ �� ������������ ��� ��������.";
			link.l1 = "������?! ��, � �� ���, �� �������������� ���� ������ � ������ ���� �����? ���� � ������ ������������� ���� ������������, ��������� � �� ����!";
			link.l1.go = "FT_27";
		break;
		case "FT_27":
			dialog.text = "��, � �� �� ���� �����, ����� �������� ����������. � ���� ��, � ����, ��� �� "+ GetSexPhrase("������� ������ � ����������","������� ������ � ����������") +", � ��� ������ �� ����� ����� ��������� ��� �������. ��� �����, ��� � ����� �� ����� �� ���-��� ������������ ���������, ����� ���� ������� �������� �� ��������� ��� � ����������� ���� ��� ���������� ��� ����.";
			link.l1 = "������� ��������?! � �� �������"+ GetSexPhrase("��","���") +"?";
			link.l1.go = "FT_28";
		break;
		case "FT_28":
			dialog.text = "���, ��� �����.";
			link.l1 = "�� � ���� ��� ����� �����!";
			link.l1.go = "FT_29";
		break;
		case "FT_29":
			dialog.text = "��, ������ ����� �� ��������, "+ GetSexPhrase("���� ���","" + pchar.name + "") +". �����, �, �������, ��� ����� ������� ������ ��� �����, ��� ��� ����� ��������� �������� ����������. � ���� ��, ����� ������ � ������� ������, �� ������ ���� � ���� �� �������� �����.";
			link.l1 = "���, ��� ���� ����� ������ ����� ���������... �������, ��� �� ������������.";
			link.l1.go = "FT_30";
		break;
		case "FT_30":
			dialog.text = "�� ���, � �� ���� ��. ����������, � ������, ���������� ��� �����... �� � ������, � ��� ��� ����������� ���������� �� ����, � ��� ����� ��� ������!";
			link.l1 = "��, �� ��� �� � �����-�� ����� �������!";
			link.l1.go = "FT_30_1";
		break;
		case "FT_30_1":
			dialog.text = "�� �� �� ���������� � '���������', ���������� � � ���� ���������... ��, ��� �� �� �������?! ��� ����� ��� �� �� ������ ��� �������� ����� ���� �����������...";
			link.l1 = "������, � ������"+ GetSexPhrase("��","��") +".";
			link.l1.go = "FT_31";
		break;
		case "FT_31":
			dialog.text = "��, ��� � �������! ��� ��� � ��������, "+ GetSexPhrase("���� ���","����") +", � ��� ������ ������ ������. ������ ��� ����� ������� � ���� �������, ���������� ���, ��� � �����������, ��� �������... ������ ������� �������! ����� �� ����� ���.";
			link.l1 = "� �����"+ GetSexPhrase("","�") +", ��� ������ ���� �� �����.";
			link.l1.go = "FT_32";
		break;
		case "FT_32":
			dialog.text = "��� ������ �� ���������, ��� � ���... � �����, ����������� ���� �� ���� ������, ��������� ��� �� ����������� '��������'. �� �����, ��� ��� ��� ��������, �� ������� ��� �����.";
			link.l1 = "�����?";
			link.l1.go = "FT_33";
		break;
		case "FT_33":
			dialog.text = "�� �� �� ��� ����� ������, ���� ��� �� �����. ������, ������ �� ���� ��������� ��� �� ���� ��������� ���������, ��� �������. � ����� ����� ����� ���� ����� ���������, �����...";
			link.l1 = "��� �����?";
			link.l1.go = "FT_34";
		break;
		case "FT_34":
			dialog.text = "����� �� ��������� ���, "+ GetSexPhrase("���� ���","�������") +". �� ����� ����� ��������, � �� ��� �������. ��� ���� ���� � '���������', � � ������ � ����������, ��� �� ��������� ������ � ���� �� ������.";
			link.l1 = "���������... � ������ �� ��������� �� �������?";
			link.l1.go = "FT_35";
		break;
		case "FT_35":
			dialog.text = "����� ����� �� ����� � ������ ������ ����������� ����� �����.";
			link.l1 = "�������... �� ��� ��, � ��� �����"+ GetSexPhrase("","�") +". ���"+ GetSexPhrase("��","��") +" ���������� ������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "CheckMillion";
			pchar.questTemp.LSCC = "fromMechanicToAdmiral";
			Npchar.quest.money = 0; //������� �����, ��������� ��������
			AddQuestRecord("ISS_MainLine", "40");
			AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("��", "���"));
			AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("", "�"));
			AddQuestUserData("ISS_MainLine", "sSex2", GetSexPhrase("��", "��"));
		break;

		//�������� ��������
		case "CheckMillion":
			dialog.text = "�� ���, ��� ��� ���� � ����� ��������?";
			if (sti(pchar.money) < 20000)
			{
				link.l1 = "���� �� ���������"+ GetSexPhrase("","�") +" ����������� ������.";
				link.l1.go = "CheckMillion_noMoney";
			}
			else
			{
				link.l1 = "���-��� �������. � �����"+ GetSexPhrase("","�") +" ������� ��� ��������� �����.";
				link.l1.go = "OffM_GiveMoney";
			}
			NextDiag.TempNode = "CheckMillion";
		break;
		case "CheckMillion_noMoney":
			dialog.text = "�� ��� ��, ����������, � �����, ��� ��� � ��� ���������.";
			link.l1 = "� ���� ��� �����.";
			link.l1.go = "exit";
		break;
		case "OffM_GiveMoney":
			dialog.text = "�������?";
			link.l1 = "";
			Link.l1.edit = 6;
			link.l1.go = "OffM_GiveMoney_1";			
		break;
		case "OffM_GiveMoney_1":
			iTemp = sti(dialogEditStrings[6]);
			if (iTemp <= 0)
			{
				dialog.text = "������ ��������?";
				link.l1 = "��, ��������, �������� �����..";
				link.l1.go = "exit";
				break;
			}
			if (iTemp > sti(pchar.money))
			{
				dialog.text = "��, ����� ����� � ��� ��� ���� ���, � ���������. ������� ��� ���������...";
				link.l1 = "��... ������.";
				link.l1.go = "exit";
				break;
			}
			Npchar.quest.money = sti(Npchar.quest.money) + iTemp;
			AddMoneyToCharacter(pchar, -iTemp);
			if (sti(Npchar.quest.money) < 1500000)
			{
				dialog.text = "�� ��� ��, �������! ������ �� ������ ��� " + FindRussianMoneyString(iTemp) + ", ����� �� �������� ��� " + FindRussianMoneyString(sti(Npchar.quest.money)) + ". ��� �������� ��������� ��� " + FindRussianMoneyString(1500000 - sti(Npchar.quest.money)) + ".";
				link.l1 = "�������� ������.";
				link.l1.go = "exit";
				AddQuestRecord("ISS_MainLine", "41");
				AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","�"));
				AddQuestUserData("ISS_MainLine", "iMoney1", sti(Npchar.quest.money));
				AddQuestUserData("ISS_MainLine", "iMoney2", 1500000 - sti(Npchar.quest.money));
			}
			else
			{
				dialog.text = "�� ��� ��, ���� �������. � ������� ��������� �����, ������ ��������� ��� ���.";
				link.l1 = "����� ������. ��� ������?";
				link.l1.go = "FreeCorvett";
			}
		break;
		//����������� ���������� ����
		case "FreeCorvett":
			dialog.text = "������ ��������� ��� ����� ����������. ���� � ���, ��� �� ��������� �� ������� ������ ������������ ����� ������� � ������� ��������� �� ���� ������.";
			link.l1 = "�� � ��� ��� �������?";
			link.l1.go = "FreeCorvett_1";
		break;
		case "FreeCorvett_1":
			dialog.text = "� ��� ��� ����������. � ���� �� ��������� ����� �������, � ��� � ��������� ������� ������ ���������� ����. ��� ��� ����� ������ �������� �������� � �������� - � �����, ��������� ��� ��������!";
			link.l1 = "������ ���������. � � ��� ������?";
			link.l1.go = "FreeCorvett_2";
		break;
		case "FreeCorvett_2":
			dialog.text = "��, ������ ������������� �������. � ������ ���������� �� ��������� ������� � ����. ��� ���������� ����� ������� �� ���.";
			link.l1 = "��-��... ���� ��� �� �������� ������, �� ��������, ��� � ��� ���� ������ ��� ������� ��� �����. � ��� ��� � ��������� ����������� ����� �� ���?";
			link.l1.go = "FreeCorvett_3";
		break;
		case "FreeCorvett_3":
			dialog.text = "��, ������ ���. � �� � ��� ����� ��� ������, �� ����� �����. ��� ��� ����������� �����!..";
			link.l1 = "� �� �� ������?";
			link.l1.go = "FreeCorvett_4";
		break;
		case "FreeCorvett_4":
			dialog.text = "�����, �, ���������� ������, ��������� �� ������... ��� ��� �������� �� ���������. � ������, ���, �������, ������ �������������, ��� ��� ������� ���������� ��� ����������� ���������.";
			link.l1 = "��, ����� ��� ����������? ������ �� ������, ��� ��� ����������?";
			link.l1.go = "FreeCorvett_5";
		break;
		case "FreeCorvett_5":
			dialog.text = "��� ��� ����� ���, ��� ������������ �� ���� �������� ������! ��� ������������ �������, �� ������� ��� ����� ����� �����.";
			link.l1 = "�������... �� ��� ��, � �����"+ GetSexPhrase("","�") +".";
			link.l1.go = "FreeCorvett_6";
		break;
		case "FreeCorvett_6":
			dialog.text = "����, ������� � ��������, ��� ������������ ��������. ������ ������������ ������ ��������, ������� �� � ������. ������� ������� �� 6 ����� ������������� ������� ��� �����. �� ��� ����� �� ������ ������ ������� �� �����������. ���� ����� �� ���������� - ��� �����. ��� �������?";
			link.l1 = "�������, ��� � ���������"+ GetSexPhrase("","�") +" �� ������� ���������� ��� �����. ��������� ���������.";
			link.l1.go = "FreeCorvett_7";
		break;
		case "FreeCorvett_7":
			dialog.text = "� ��� �������, ��� ��� ����� �������. ������ �� ������ ���� �� ���������, ������ ��������� ���, ��������� �������� �� ���� ����������. �������, �� ����������� ��� �����, ��� ��� ������. �������, ��� ����������� ����� ������ ����, � ������ �� ������������ �����. ����� ������������� ��������� ������ ���� ��, ��� �����. ����� ��� � ��������� ����!";
			link.l1 = "�������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "takeArmor";
			pchar.questTemp.LSCC.immersions = 0; //���������� ����������� ����������
			pchar.questTemp.LSCC.immersion = "true"; // ���������� ��������
			pchar.quest.LSCC_takeUnderwater.win_condition.l1 = "locator";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.location = "FenixPlatformm";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.locator_group = "item";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.locator = "armor";
			pchar.quest.LSCC_takeUnderwater.function = "LSCC_takeUnderwater"; // ������ �������

			pchar.questTemp.LSCC.immersions.pinion = false; //���� ��������� ����������

pchar.quest.LSCC_UnderwaterDolly.win_condition.l1 = "locator";
			pchar.quest.LSCC_UnderwaterDolly.win_condition.l1.location = "Underwater";
			pchar.quest.LSCC_UnderwaterDolly.win_condition.l1.locator_group = "quest";
			pchar.quest.LSCC_UnderwaterDolly.win_condition.l1.locator = "dolly";
			pchar.quest.LSC_UnderwaterDolly.function = "LSCC_FindUnderwaterDolly"; // ����� ������

			AddQuestRecord("ISS_MainLine", "42");
			pchar.Ship.Type = GenerateShipExt(SHIP_BALLOON, false, pchar);
			SetBaseShipData(pchar);
			pchar.Ship.name = "������ ������";
			pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS6;
			SetCharacterGoods(pchar, GOOD_BALLS, 0);
			SetCharacterGoods(pchar, GOOD_GRAPES, 0);
			SetCharacterGoods(pchar, GOOD_KNIPPELS, 0);
			SetCharacterGoods(pchar, GOOD_BOMBS, 0);
			SetCharacterGoods(pchar, GOOD_SAILCLOTH, 0);
			SetCharacterGoods(pchar, GOOD_PLANKS, 0);
			SetCharacterGoods(pchar, GOOD_POWDER, 0);
			SetCharacterGoods(pchar, GOOD_FOOD, 0);
			SetCharacterGoods(pchar, GOOD_WEAPON, 0);
			SetCharacterGoods(pchar, GOOD_MEDICAMENT, 0);
			SetCrewQuantity(pchar, 0);
			AddSimpleRumourCityTip("�� ������, � ������ �������� ����� �������. � �������, ��� �� ��������� ������! ���� ��...", "LostShipsCityy", 10, 1, "LSCC", "");
			AddSimpleRumourCityTip("�� ������� � ������� ��������? ��� ��� ����! �����������, ��� ������� �������� �� '��� ��������' ����� ���.", "LostShipsCityy", 10, 1, "LSCC", "");
			AddSimpleRumourCityTip("�������, ��� �����-������ ������ ������, ����� ������ �������, ����� ��������� �������.", "LostShipsCityy", 10, 1, "LSCC", "");
			AddSimpleRumourCityTip("� � �� ����, ��� ���� ������� ��� ����� ��� ������. ������� ���� ��� ����, �������� � ���...", "LostShipsCityy", 10, 1, "LSCC", "");		
			// ����� �������� � �����
			ref loc;
			int n;
			if (Pchar.SystemInfo.CabinType != "")
			{
				loc = &locations[FindLocation(Pchar.SystemInfo.CabinType)]; //"My_Cabin"

				for (n = 1; n <= 4; n++)
				{
					sTemp = "box" + n;
					DeleteAttribute(loc, sTemp + ".items");
					loc.(sTemp).items = "";
					loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
					loc.(sTemp).money = 0;
				}
			}
			loc = &locations[FindLocation("My_Deck")];
			for (n = 1; n <= 4; n++)
			{
				sTemp = "box" + n;
				DeleteAttribute(loc, sTemp + ".items");
				loc.(sTemp).items = "";
				loc.(sTemp) = Items_MakeTime(0, 0, 1, 2003);
				loc.(sTemp).money = 0;
			}	
		break;
		//
		case "takeArmor":
			dialog.text = "��, ��� � ��� ����?";
			if (CheckAttribute(pchar, "questTemp.LSCC.immersion"))
			{
				link.l1 = "��������� � ����������. ����� ������, ��� ��� ������.";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "��� ����� ��� ��� ���������� �� ���. �� �����"+ GetSexPhrase("","�") +" ������� ��� ���, ��� �����"+ GetSexPhrase("","�") +".";
				link.l1.go = "DeepAgain";			
				if (CheckCharacterItem(pchar, "Pinion"))
				{
					link.l2 = "� ���"+ GetSexPhrase("��","��") +" ����������, ��� ���!";
					link.l2.go = "FoundPinion";
				}
			}
		break;

		case "DeepAgain":
			dialog.text = "� �� ������, ������ ������ � ����� ������������. ������ �� ������ ���������� � �������� � ��� ����� 30 ����� ��������. ��� ��� ������ �� �����.";
			link.l1 = "����� ������ �����? � �� ������"+ GetSexPhrase("","��") +" ��� ������� ��������!";
			link.l1.go = "DeepAgain_1";

			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			LocatorReloadEnterDisable("SanGabrielMechanicc", "reload3", false);
	                                          LocatorReloadEnterDisable("LostShipsCityy_town", "reload73", true);
			SetFunctionTimerCondition("LSCC_ReadyUnderwater", 0, 0, 1, false);
		break;

		case "DeepAgain_1":
			dialog.text = "��� ������ - ����� �� ������ � �� ���� ����������. � �� ������ ��� ������� ������, �� �������� � ����. � ���� ��� ��� � ������. ����������� � ��� ����...";
			link.l1 = "����� �����������?";
			link.l1.go = "DeepAgain_2";
		break;
		case "DeepAgain_2":
			dialog.text = "����� ������������, �� �� ���� �� �����? � �����, ������� ����������. �������� ����� - � �� ������������ � �������� ������� �� �������. ��� ����� - ��� ����������.";
			link.l1 = "�-��, �������...";
			link.l1.go = "DeepAgain_3";
		break;
		case "DeepAgain_3":
			dialog.text = "� �� �������, �� ��� �� ���������. � ��� ��� ����������� ���������� ������� ������. ���� �� ��� ����� ����� ���������. ���� �� ���� �� �������� ����������, �� �������� ����... � �����, ����� ���� ����� ���������"+ GetSexPhrase("��","��") +" ���, �� ���.";
			link.l1 = "����...";
			link.l1.go = "exit";
			NextDiag.TempNode = "takeArmor2";
		break;

		case "takeArmor2":

			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			LocatorReloadEnterDisable("SanGabrielMechanicc", "reload3", false);
	                                          LocatorReloadEnterDisable("LostShipsCityy_town", "reload73", true);
			SetFunctionTimerCondition("LSCC_ReadyUnderwater", 0, 0, 1, false);

			dialog.text = "��, ��� ��� ����?";
			if (CheckAttribute(pchar, "questTemp.LSCC.immersion"))
			{
				link.l1 = "��������� � ������ ��� ���������� ����������.";
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = "� ���� ��� ��� ���������� �� ���.";
				link.l1.go = "DeepAgain2";			
				if (CheckCharacterItem(pchar, "Pinion"))
				{
					link.l2 = "� ���"+ GetSexPhrase("��","��") +" ����������, ��� ���!";
					link.l2.go = "FoundPinion";
				}
			}
			if (sti(pchar.questTemp.LSCC.immersions.pinion))
			{
				link.l3 = "���, � ��������"+ GetSexPhrase("","�") +" � ������������. ����� ��������� ������� ���� �� ����������.";
				link.l3.go = "endImmersion";
			}
		break;

		case "DeepAgain2":
			dialog.text = "����������� ������?";
			if (sti(pchar.money) >= 30000)
			{
				link.l1 = "��, �����"+ GetSexPhrase("","�") +" ���������.";
				link.l1.go = "DeepAgain2_1";
			}
			else
			{
				link.l1 = "��� ���... �� � �� ��������� �����������.";
				link.l1.go = "exit";
			}
		break;
		case "DeepAgain2_1":
			dialog.text = "�������! ��������� ������, � ���������� ������ � ������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -30000);
			SaveCurrentQuestDateParam("questTemp.LSCC.immersions");
			NextDiag.TempNode = "readyArmor";
		break;

		case "readyArmor":
			if (GetQuestPastDayParam("questTemp.LSCC.immersions") > 1)
			{
				dialog.text = "��� � �������, ������ �������� � ��������� ��������. � �����, ��� ������ � ����������. ����� �����.";
				link.l1 = "�������.";
				link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.LSCC.UW_ready"); 
			LocatorReloadEnterDisable("LostShipsCityy_town", "reload72", false); //��������� ���� � ������
	                                          LocatorReloadEnterDisable("LostShipsCityy_town", "reload73", true);
			pchar.questTemp.LSCC.immersion = "true"; // ���������� ��������
			pchar.quest.LSCC_takeUnderwater.win_condition.l1 = "locator";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.location = "FenixPlatformm";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.locator_group = "item";
			pchar.quest.LSCC_takeUnderwater.win_condition.l1.locator = "armor";
			pchar.quest.LSCC_takeUnderwater.function = "LSCC_takeUnderwater"; // ������ �������

				NextDiag.TempNode = "takeArmor2";
			}
			else
			{
				dialog.text = "������ �� ����� � ������. ��������� ������.";
				link.l1 = "������.";
				link.l1.go = "exit";
			}
		break;

		case "FoundPinion":
			dialog.text = "�����������! ������� �� �������...";
			link.l1 = "��, �������.";
			link.l1.go = "FoundPinion_1";
		break;
		case "FoundPinion_1":
			dialog.text = "�� ��� ��, ������ � ���� �������� ��������������� ��������� �������. �������, �� ��� ������ ��������� ����������?";
			link.l1 = "��, ���� ����� �������� ����������� ���.";
			link.l1.go = "FoundPinion_deep";
			link.l2 = "���, ��������� ������� ���� ����� �� ����������.";
			link.l2.go = "endImmersion";
			TakeItemFromCharacter(pchar, "Pinion");
			pchar.questTemp.LSCC.immersions.pinion = true; //����� ����������
			AddQuestRecord("ISS_MainLine", "44");
		break;

		case "FoundPinion_deep":
			dialog.text = "�� ��� ��, ������� �����. ��� ������� �� ������ - 30 ����� ����� �� ������ ����������. ��������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "takeArmor2";
		break;

		case "endImmersion":
			dialog.text = "�� ��� ��, ��� �������. ����� � ����������� ������.";
			link.l1 = "��� ������.";
			link.l1.go = "endImmersion_1";

			DeleteAttribute(pchar, "questTemp.LSCC.UW_end"); 
			RemoveCharacterEquip(pchar, CIRASS_ITEM_TYPE);
			RemoveItems(pchar, "underwater", 1);
			LocatorReloadEnterDisable("SanGabrielMechanicc", "reload3", false);
	                                          LocatorReloadEnterDisable("LostShipsCityy_town", "reload73", true);
			SetFunctionTimerCondition("LSCC_ReadyUnderwater", 0, 0, 1, false);

		break;

		case "endImmersion_1":
			dialog.text = "������, ����� � ���� ���� ��� �����������, � ������� ��������������� ��������� �������, ������� ��������� ��� ������. ��� ������ � ���� ������������ �����. ��� �� ���� �� ������� �������� �� ������, � ����� �������� ��� ������ ���������������� �����������.";
			link.l1 = "��� �� ������ � ����?";
			link.l1.go = "endImmersion_2";
		break;
		case "endImmersion_2":
			dialog.text = "��� ������ ���������� ��������� ��� ���� �����������. ���� ����� �����������, ��������������, ������... ��, �� ��� ��� �����. ��� ��������� ����������� �� '��� ��������', � ����������� ����� ����� �� ��������� ��� � ������� ���.";
			link.l1 = "� �����"+ GetSexPhrase("","�") +", ���������� ��� �������.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.LSCC.immersions");
			AddQuestRecord("ISS_MainLine", "45");
			pchar.questTemp.LSCC = "toSeekGoods";
			NextDiag.TempNode = "takeGoods";
		break;


		//�������������� ������� ��������
		case "takeGoods":
			NextDiag.TempNode = "takeGoods";
			dialog.text = "�����������. ��, ��� ���� � ����������� ����� �������?";
			npchar.quest.LSCC.Balls = false;
			npchar.quest.LSCC.Grapes = false;
			npchar.quest.LSCC.Knippels = false;
			npchar.quest.LSCC.Bombs = false;
			npchar.quest.LSCC.Sailcloth = false; //�������
			npchar.quest.LSCC.Planks = false; //�������
			npchar.quest.LSCC.Powder = false;
			npchar.quest.LSCC.Food = false; //�������
			npchar.quest.LSCC.Weapon = false;
			npchar.quest.LSCC.Medicament = false;
			iTemp = 0;
			npchar.quest.LSCC.s0 = "";
			npchar.quest.LSCC.s1 = "";
			if (GetCargoGoods(pchar , GOOD_BALLS) >= 100) 
			{
				npchar.quest.LSCC.Balls = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Balls;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " ����,";
			if (GetCargoGoods(pchar , GOOD_GRAPES) >= 100) 
			{
				npchar.quest.LSCC.Grapes = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Grapes;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " �������,";
			if (GetCargoGoods(pchar , GOOD_KNIPPELS) >= 100) 
			{
				npchar.quest.LSCC.Knippels = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Knippels;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " ��������,";
			if (GetCargoGoods(pchar , GOOD_BOMBS) >= 100) 
			{
				npchar.quest.LSCC.Bombs = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Bombs;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " �����,";
			if (GetCargoGoods(pchar , GOOD_SAILCLOTH) >= 50) 
			{
				npchar.quest.LSCC.Sailcloth = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Sailcloth;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " ��������,";
			if (GetCargoGoods(pchar , GOOD_PLANKS) >= 50) 
			{
				npchar.quest.LSCC.Planks = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Planks;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " �����,";
			if (GetCargoGoods(pchar , GOOD_POWDER) >= 200) 
			{
				npchar.quest.LSCC.Powder = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Powder;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " �����,";
			if (GetCargoGoods(pchar , GOOD_FOOD) >= 200) 
			{
				npchar.quest.LSCC.Food = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Food;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " ��������,";
			if (GetCargoGoods(pchar , GOOD_WEAPON) >= 50) 
			{
				npchar.quest.LSCC.Weapon = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Weapon;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " ������,";
			if (GetCargoGoods(pchar , GOOD_MEDICAMENT) >= 50) 
			{
				npchar.quest.LSCC.Medicament = true;
				iTemp++;
			}
			sTemp = "s" + npchar.quest.LSCC.Medicament;
			npchar.quest.LSCC.(sTemp) = npchar.quest.LSCC.(sTemp) + " �����������,";
			if (iTemp < 10)
			{
				if (iTemp == 0)
				{
					link.l1 = "���� ������ �� ��������"+ GetSexPhrase("","�") +", �� � ��������.";			
				}
				else
				{
					sTemp = npchar.quest.LSCC.s0;
					npchar.quest.LSCC.s0 = strcut(sTemp, 0, (strlen(sTemp)-2));
					sTemp = npchar.quest.LSCC.s1;
					npchar.quest.LSCC.s1 = strcut(sTemp, 0, (strlen(sTemp)-2));
					link.l1 = "���-��� ��� ����. ������� ������� " + npchar.quest.LSCC.s1 + ". �������� ��������� " + npchar.quest.LSCC.s0 + ".";
				}
				link.l1.go = "takeGoods_again";
			}
			else
			{
				link.l1 = "���, ��� ����� ��� ���������� ��������, � ���� � �����.";
				link.l1.go = "TakeCrew";
				DeleteAttribute(pchar, "questTemp.LSCC.Balls");
				DeleteAttribute(pchar, "questTemp.LSCC.Grapes");
				DeleteAttribute(pchar, "questTemp.LSCC.Knippels");
				DeleteAttribute(pchar, "questTemp.LSCC.Bombs");
				DeleteAttribute(pchar, "questTemp.LSCC.Sailcloth");
				DeleteAttribute(pchar, "questTemp.LSCC.Planks");
				DeleteAttribute(pchar, "questTemp.LSCC.Powder");
				DeleteAttribute(pchar, "questTemp.LSCC.Food");
				DeleteAttribute(pchar, "questTemp.LSCC.Weapon");
				DeleteAttribute(pchar, "questTemp.LSCC.Medicament");
				DeleteAttribute(pchar, "questTemp.LSCC.additional");
			}
		break;
		case "takeGoods_again":
			dialog.text = "�� ��� ��, �������. � ������������ �� ������ � ���� �����.";
			link.l1 = "��� � ���� ���������.";
			link.l1.go = "exit";
		break;
		//����� �������
		case "TakeCrew":
			dialog.text = "���������, "+ GetSexPhrase("���� ���","������� ���") +", ��� ��� ��������� � ����� ������ ���������� ����. ������ ��� ����� ������� ������� �� ������� ������. ���� ���������, ������ �� � ��������� ����� �� ���������.";
			link.l1 = "���, � ������ ������ ���� �� ���� �������? � �������"+ GetSexPhrase("","�") +" ���� ����� � ������� ������� �� ��������� ���, ������ ���"+ GetSexPhrase("","��") +" �� � ������� �������.";
			link.l1.go = "TakeCrew_1";
		break;
		case "TakeCrew_1":
			dialog.text = "��, ��-������, ���� �� �� ��� ����������� ��������. � ��-������, � �� �����-�� � ���������. �� ������ ���� ��������� ����� ��������� ������.";
			link.l1 = "��� �� ������ � ����?";
			link.l1.go = "TakeCrew_2";
		break;
		case "TakeCrew_2":
			dialog.text = "������ ��, � ������� ��� ��� ���� ��������� ��� ����, ��� �������� �����, ��� ����� � ��������� ��� �����������. �� ��� ����� � ��������� ������, ������� ���������� ����������� �������. � ��� ������ '����������'! �������������, ������ ��, �����...";
			link.l1 = "��� � ���, ��� �� �������... ���, ��� ��� ������ ���������� ������� ���?";
			link.l1.go = "TakeCrew_3";
		break;
		case "TakeCrew_3":
			dialog.text = "�-�, �� ��... ��� ���, ��� ���������� ����������, ��� �� ����� �������� �� ������ �����, � ��������� ����. ���� �� ����, ����� ���� - ������ �����������.";
			link.l1 = "����������, ��� ����� ������?";
			link.l1.go = "TakeCrew_4";
		break;
		case "TakeCrew_4":
			dialog.text = "������ ���, "+ GetSexPhrase("���� ���","" + pchar.name + "") +". � ���� ������� � ����� ������� ����� �����������, ��� ������ ����� ����� ��������. ��� ��� ������������.";
			link.l1 = "������, � ��� � ������. ������, �� ������ ���������� ��������� ���?";
			link.l1.go = "TakeCrew_5";
		break;
		case "TakeCrew_5":
			dialog.text = "��� ���, �� ��������� �������, ��� � ������ ����������. ��������������� � ������, ����� ��� ��������� ����, � � ���� ������������ �� �� ��������� ���. ��� ����� ���� �� ���������� �������, ����� �������. ��� ������ �� �������� ����������� ���������� - ����� �� ������ ����. �� ������ �������� �� '��� ��������', �� ����������� ������� � ��������� ��������� ���.";
			link.l1 = "������, � ��� �����"+ GetSexPhrase("","�") +". ����� ��������������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "TakeCrewNew";
			AddQuestRecord("ISS_MainLine", "59");
			AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("��","��"));
			pchar.questTemp.LSCC = "toSeekPeopleInCrew";
			pchar.questTemp.LSCC.crew = 0; //���������� ����������� �����.
			AddDialogExitQuestFunction("LSCC_SmallStormIsBegin");
		break;
		//����� ������ � �������
		case "TakeCrewNew":
			if (sti(pchar.questTemp.LSCC.crew) > 0)
			{
				dialog.text = "�� ��� �� ������� ������������ ���������� ����� ��� ��������. ����� �� ��� ������� " + FindRussianPeoplesString(sti(pchar.questTemp.LSCC.crew), "Acc") + ". �����������, � ����� ��� - �������...";
			}
			else
			{
				dialog.text = "�� ��� ������ �� ��������� ����� � ��� � �������. ������������!";
			}
			link.l1 = "������.";
			link.l1.go = "exit";
		break;
		//�������� � ������
		case "inPrison":
			dialog.text = "���, ��� � ��!";
			link.l1 = "�����! ����"+ GetSexPhrase("��","��") +" �� �������.";
			link.l1.go = "inPrison_1";
		break;
		case "inPrison_1":
			dialog.text = "�� ��� ��, �������, �� ������... ������ ��� ���.";
			link.l1 = "��� ������?";
			link.l1.go = "inPrison_2";
		break;
		case "inPrison_2":
			dialog.text = "� ������ � ���� ������, � ���� �������� ������ ��������. ��� ��� ��� ������ ���������� ������. ��� �� ��������� �� ���� ������.";
			link.l1 = "�������� ������ ���, � ��������"+ GetSexPhrase("��","���") +" � ���. �� �������� ����� �� �������"+ GetSexPhrase("","�") +"... � ������� � �����!";
			link.l1.go = "inPrison_3";
		break;
		case "inPrison_3":
			dialog.text = "������, "+ GetSexPhrase("���� ���","" + pchar.name + "") +". ���� �������� ����.";
			link.l1 = "� �����!";
			link.l1.go = "inPrison_4";
		break;
		case "inPrison_4":
			dialog.text = "���, ��� ���� ��. �� � �� ����� ��������� ��������� ����� � ������� �������� �����, ��� ��� ��������� �� ���. ��������, ��� ��� ����� �������...";
			link.l1 = "������, � ����� � �������� ���.";
			link.l1.go = "inPrison_5";
		break;
		case "inPrison_5":
			dialog.text = "� �����, ��� �������. �������, ��� ���������, ������, ������������ ����� ������. ������� ���� ��� ������� - ������ ������������ ������� ���������� � ����� ����� ���������.\n� ���� ��, ��������, � ��������, � ����� ������ ����� �������� ������. ����� ���������� ����� ������ ����� �����, ��� ������ � ��������.";
			link.l1 = "�� �������?";
			link.l1.go = "inPrison_6";
		break;
		case "inPrison_6":
			dialog.text = "��, � ��� �����. � ������ ��������, ��� �� ������ �������, ����� ������� �� ���� ��������� ���.";
			link.l1 = "� ������.";
			link.l1.go = "inPrison_7";
		break;
		case "inPrison_7":
			dialog.text = "������������� �� ������ ����� '������� ����������', ������ �� ������� ��� ����� ������. � ����� ������������ ������� �� ������ � �������� �������, ���������� ��������� ���. ������ �� � ��������� ���������� �� ������.\n����� �������� ����, �����, ��� ������ ��� �������� �������... ��� ������ �� '���������', �� ������ ����� ������������ ����, ���� ����������� - ������� ������. ����� � ���� ����� �� ���������. � ��� ��� �������, ��� �� ������ ��������� �� ����������� �� ������ ����� '�������� ����������'.";
			link.l1 = "� �����"+ GetSexPhrase("","�") +", ������� ���... ����� ����, ���-���� ���������� ������� ��� ������� ������?";
			link.l1.go = "inPrison_8";
		break;
		case "inPrison_8":
			dialog.text = "��������, ��� ���� ������� ����� � ���� ����. ������ ��� ������ - �� ���� ������...";
			link.l1 = "��������, ������ �������. ����� ��� ������ � ���� ������.";
			link.l1.go = "exit";
			chrDisableReloadToLocation = false;
			LAi_CharacterDisableDialog(npchar);
			AddQuestRecord("ISS_MainLine", "67");
			AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("��","���"));
			AddDialogExitQuestFunction("LSCC_BigStormIsBegin");
		break;
	}
}