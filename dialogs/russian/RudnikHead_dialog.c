// ������ ���������� �����
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		location = &Locations[FindLocation(pchar.location)];
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("�� ������� ������� ����?! ������ ���...", "��� ��� ����������� ���������, ����� �� ��� �������� ����?! ��� �����������...", "�� ��, ��� ������ ��������� �����, ��� "+ GetSexPhrase("�����-�� ����������","�����-�� �����������") +" ������ � ���..."), 
					LinkRandPhrase("��� ���� �����, "+ GetSexPhrase("�������","��������") +"?! ��� ������� ��� ����� ���� ����, ������ ���� �� ����"+ GetSexPhrase(", ������� �����","") +"!", "�����"+ GetSexPhrase("��","��") +" ������, ��� �� ���� ����������! ������!!", "� �� ����� ����, ������"+ GetSexPhrase("��","��") +"! ����� ���� �������, ������ ���� �� ����..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("�������� ���� ���� �����...", "�� ���� �� �� ��� �� �������."), 
					RandPhraseSimple("������ ���� �����, " + GetWorkTypeOfMan(npchar, "") + ", � �� �� ����� ���� ������� ����!", "��� ��� � ���� �����, ��������: ���� ����, � ������ ����..."));
				link.l1.go = "fight";
				break;
			}
			if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
			{
    			dialog.text = "���� �� �������! �������!!";
				link.l1 = "�-���, ������!";
				link.l1.go = "fight"; 
				break;
			}	
			dialog.text = LinkRandPhrase(""+TimeGreeting()+", ������. � - "+GetFullName(npchar)+". � ��������� ����� ������� � ������� ������ �������. ��� ��� ��� �����?","������������, ������. ��� ��� ������?","��. �� ���-�� ������ �� ����, ������? � ��� ������.");
			if (!CheckAttribute(location, "quest.info"))
			{
				link.l9 = "� ����� �������, � ����� �� ������� ������ ������ �� ���� �������...";
				link.l9.go = "info";
			}
			if (GetSquadronGoods(pchar, GOOD_SLAVES) > 4)
			{
				link.l2 = "� ���� � ������ ���� �����, ������� ��� ����������. ���� ��� ������ �������. �����������?";
				if (!CheckAttribute(location, "quest.slaves")) link.l2.go = "slaves_0";
				else link.l2.go = "slaves";
			}
			link.l1 = "� ������ ����� � ���� ������������� � ��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "info":
			dialog.text = "��� ������ �������� ������ ��� "+NationKingsName(npchar)+ ". ��� ������� �� ������� ����������� �����������, � ������ ���. ����� ������, ����� ����� ����������� ���������� ��������� � ������� - ������ ���������. �������� ������� �� �� ����� - ��� ������� ������������ ��� ��������� ������� � ������ ����\n������ ������ ������� � ���������� ���������� ��������� ����������. ��� ����������� ��������� ��������� ������� ���� ��� ����� �� �������, ������� �� �������� ����� � ����� �� ���������. ��� ��� ���� � ��� ����, ��� ���������� - ����������� �� ���, ����� ��������������\n���������� ��������� � ������, �����, ��� � ��� ������ ���� ����: �� ��������� ���-���� �������, ��� ���������� ��� ��� ��� ��������, �� ���������� ����������� �� ������ � �� ��������� ��� ������ � ������ ���������.";
			link.l1 = "�������!";			
			link.l1.go = "exit";
			location.quest.info = "true";
		break;
		
		// ��������� �����-������� �����
		case "slaves_0":
			location.quest.slaves.qty = 200; // ��������� �����������
			dialog.text = "�������, ������! ������� � ��� ����� '������ ������'?";
			link.l1 = "� ���� ���� "+FindRussianQtyString(GetSquadronGoods(pchar, GOOD_SLAVES))+".";
			link.l1.go = "slaves_1";
		break;
		
		case "slaves":
			location.quest.slaves.qty = sti(location.quest.slaves.qty)+GetNpcQuestPastDayParam(location, "slave_date"); // ������ ���� ���� +1 �����������
			if (sti(location.quest.slaves.qty) > 350) location.quest.slaves.qty = 350; // �������� �����������
			if (sti(location.quest.slaves.qty) < 5)
			{
				dialog.text = "������, � ���������, �� ������ ������ � ��� ��� ����� � �����. �� �������� �������� ���������, ��� ��� ��������� �� ��� �������, ����� ��������� ������, ��, ��� � ������ ���.";
				link.l1 = "������, ������. � ��� �������: �� ����� ������ - ����������� �����.";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�������, ������! ������� � ��� ����� '������ ������'?";
				link.l1 = "� ���� ���� "+FindRussianQtyString(GetSquadronGoods(pchar, GOOD_SLAVES))+".";
				link.l1.go = "slaves_1";
			}
		break;
		
		case "slaves_1":
			dialog.text = "�� ������� ���� � ����� ������ ��� ���� ���� ������� ���������, ���� ��� ����������. ��� ���������?";
			link.l1 = "������� ���������.";
			link.l1.go = "slaves_g";
			link.l2 = "��������� ���������.";
			link.l2.go = "slaves_s";
			link.l3 = "��������, ������, �� ���-�� � ���������. � ������ ���.";
			link.l3.go = "slaves_exit";
		break;
		
		case "slaves_g":
			location.quest.slaves.type = "gold";
			dialog.text = "������. ������� ����� �� ������ ��� �������?";
			link.l1 = "";
			link.l1.edit = 6;
			link.l1.go = "slaves_trade";
		break;
		
		case "slaves_s":
			location.quest.slaves.type = "silver";
			dialog.text = "������. ������� ����� �� ������ ��� �������?";
			link.l1 = "";
			link.l1.edit = 6;
			link.l1.go = "slaves_trade";
		break;
		
		case "slaves_trade":
			iTotalTemp = sti(dialogEditStrings[6]);
			if (iTotalTemp < 1)
			{
				dialog.text = "������, � �� ���������� � ������ ������. ���������� ������������� � �������!";
				link.l1 = "��...";
				link.l1.go = "slaves_exit";
				break;
			}
			if (iTotalTemp > GetSquadronGoods(pchar, GOOD_SLAVES))
			{
				dialog.text = "������, ��� �������, ��� ����� ���������. ������, �� ����� ������, ��� ����������� �� ����� ������. ������� � �������, �������, � ����� ��������� ���� ��������.";
				link.l1 = "��...";
				link.l1.go = "slaves_exit";
				break;
			}
			if (iTotalTemp > sti(location.quest.slaves.qty))
			{
				dialog.text = "� ���������, ������, ��� � ������ ������ �� ����� ��� ����� �����. ����������� ������� �� ����������� ���� ���������� "+FindRussianQtyString(sti(location.quest.slaves.qty))+". ������ ���������?";
				link.l1 = "��, �������!";
				link.l1.go = "slaves_max";
				link.l2 = "��... ���, �������.";
				link.l2.go = "slaves_exit";
				break;
			}
			dialog.text = ""+FindRussianQtyString(iTotalTemp)+"? ������������. ��������� ��������� �� � ��������� �������, � ����� ����� �����.";
			link.l1 = "�� �������� ������������, ������. ���� ���� ����� ���������� ��� ����� ������. � ���������� ����� ������ ������������.";
			link.l1.go = "slaves_calk";
		break;
		
		case "slaves_max":
			iTotalTemp = sti(location.quest.slaves.qty);
			dialog.text = "������������. ��������� ��������� �� � ��������� �������, � ����� ����� �����.";
			link.l1 = "�� �������� ������������, ������. ���� ���� ����� ���������� ��� ����� ������. � ���������� ����� ������ ������������.";
			link.l1.go = "slaves_calk";
		break;
		
		case "slaves_calk":
			DialogExit();
			Log_Info("����� ����� �� ��������� ����������");
			PlaySound("interface\important_item.wav");
			LAi_Fade("", "");
			WaitDate("",0,0,0,5,10);
			RemoveCharacterGoods(pchar, GOOD_SLAVES, iTotalTemp);
			if (location.quest.slaves.type == "gold") TakeNItems(pchar, "jewelry5", iTotalTemp);
			else TakeNItems(pchar, "jewelry6", iTotalTemp*2);
			DeleteAttribute(location, "slave_date");
			SaveCurrentNpcQuestDateParam(location, "slave_date");
			location.quest.slaves.qty = sti(location.quest.slaves.qty)-iTotalTemp;
		break;
		
		case "slaves_exit":
			DialogExit();
			DeleteAttribute(location, "slave_date");
			SaveCurrentNpcQuestDateParam(location, "slave_date");
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		    LAi_group_Attack(NPChar, Pchar);
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
	}
}
