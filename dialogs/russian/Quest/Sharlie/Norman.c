// ������� ������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "norman_us":
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				dialog.text = LinkRandPhrase("��� ����, ������? ��� ����� �������, ��������� ������-���������, � �� ���� �������.","������-������, �������. �������? ��� � ����� ���� ������, � ������� �� ������� ��������. �� ���� ������, ������� �������� �����.","����������, ��������. ������ ���������? �� ��� ���� ��������: � �� � ���������� �������������. ��� ��� ����� ���� ������� �����������. ����� � �������, ���� �����...");
				link.l1 = "��������, �������, �� �� �������� ������� �� ���� ������ �������� �� ����� ������ ������? �� ��� ����� ��������� �����.";
				link.l1.go = "tieyasal";
				break;
			}
			dialog.text = NPCStringReactionRepeat(LinkRandPhrase("��� ����, ������? ��� ����� �������, ��������� ������-���������, � �� ���� �������.","������-������, �������. �������? ��� � ����� ���� ������, � ������� �� ������� ��������. �� ���� ������, ������� �������� �����.","����������, ��������. ������ ���������? �� ��� ���� ��������: � �� � ���������� �������������. ��� ��� ����� ���� ������� �����������. ����� � �������, ���� �����..."), LinkRandPhrase("�������, �� ���� �����������? � ����� ���� ��������.","������, ��� ��������. � ��, ������, ������� ���������.","�������, �� ��� - �������? � �� ����� �������� ��� ��������."), "��������, �� ������ �� �����. � ������� ���������� ���� �� ����� ���� ���������, ��� ����� ������, ����� ������ - ��� �������.", "�� ���, �� ���� ������. ������ ��� �������� ���� ������ �����, ��� ���� �� ���� ���. ������ - ������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������, ��������. �� ���� ���� ������.", "��-��, � �����. ������ �������� ���...", "��, �� ��, ������ - ����� �����! �����, �����.", "���?!", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "fight", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "norman_us";
		break;
		
		case "norman_fes":
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				dialog.text = LinkRandPhrase("��� ����, ������? ��� ����� �������, ��������� ������-���������, � �� ���� �������.","������-������, �������. �������? ��� � ����� ���� ������, � ������� �� ������� ��������. �� ���� ������, ������� �������� �����.","����������, ��������. ������ ���������? �� ��� ���� ��������: � �� � ���������� �������������. ��� ��� ����� ���� ������� �����������. ����� � �������, ���� �����...");
				link.l1 = "��������, �������, �� �� �������� ������� �� ���� ������ �������� �� ����� ������ ������? �� ��� ����� ��������� �����.";
				link.l1.go = "tieyasal";
				break;
			}
			switch (drand(5))
			{
				case 0:
					dialog.text = "������! � ���������� ����� �������. �� ���, �� ������ ���?!";
					link.l1 = "������� ����! ��� �� �� ����� ����������� ����-������...";
					link.l1.go = "norman_fes0_fight";
					link.l2 = "��, �� ��� ��������� ��������, ��� ����� ����� ������!";
					link.l2.go = "norman_fes0_peace";
				break;
				
				case 1:
					dialog.text = "���� �� ����! ����� ����� ������� ���������! �� ���, �� ����� ��� ���������� �����?";
					link.l1 = "�������, �������� �������! ������ ���� ������������.";
					link.l1.go = "norman_fes1_peace";
					link.l2 = "����� � ���� �������. ����, ������ ���������.";
					link.l2.go = "norman_fes1_fight";
				break;
				
				case 2:
					dialog.text = "�, ������ ��, ����� � ��������, ��� �������� �� �������� �����. ����� �� ���������� ��� ����������� ���������. � �������� �������� ������� ���.";
					link.l1 = "�������, ���� ����������. ����� �� ������, ��� ���� II �������� � ����-�����.";
					link.l1.go = "norman_fes2_fight";
					link.l2 = "�� � � ����� - ������� ���� ���������� X.";
					link.l2.go = "norman_fes2_peace";
				break;
				
				case 3:
					dialog.text = "���� �� ������, �����? � ��� ���� ������ ����. �� ������ ����� ������ ���� ��������!";
					link.l1 = "�� �� ����, ����! ��� �� �����.";
					link.l1.go = "norman_fes3_peace";
					link.l2 = "�� ����������, ���������. ���� ����� "+GetFullName(pchar)+".";
					link.l2.go = "norman_fes3_fight";
				break;
				
				case 4:
					dialog.text = "�-�-�... � ���� �����. �����, �� ������� ������?";
					link.l1 = "�������, ������ �����, �������� � ��������.";
					link.l1.go = "norman_fes4_fight";
					link.l2 = "��� ������� �� ������, � ����� �� ��������.";
					link.l2.go = "norman_fes4_peace";
				break;
				
				case 5:
					dialog.text = "� ����� ����� ��������� ���������. �� ������ ��� ������ ���������� ����� '����, ��� �� ����?!'";
					link.l1 = "���, � ��� ������������ ������! ������� �� ��� � ������ ����� �������...";
					link.l1.go = "norman_fes5_fight";
					link.l2 = "������� '����', �� � �� ��������, ����� � ������� �������� ������!";
					link.l2.go = "norman_fes5_peace";
				break;
			}
		break;
		
		case "norman_fes0_fight":
			dialog.text = "����� � ������� '������'?! �� �� ��� ��� ��������� �������! �������, � ����� ���� ���� ������ ���������� ������-������. �������� ������� ���� ���������...";
			link.l1 = "�! �� �� ����?!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes0_peace":
			dialog.text = "�� ����, ������. �� ����� ���� � ������� ���������, �� ��� ������ ����� ����. �������� � ������, ����� ���������. ��� ���� ����������.";
			link.l1 = "�������� ����������!";
			link.l1.go = "norman_fes0_exit";
		break;
		
		case "norman_fes0_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 12)
			{
				GiveItem2Character(pchar, "pistol2");
				Log_Info("�� �������� ������������� ��������");
			}
			else
			{
				if (GetDataDay() == 23 && GetDataMonth() == 2)
				{
					GiveItem2Character(pchar, "mushket1");
					Log_Info("�� �������� ��������� ������");
				}
				else
				{
					GiveItem2Character(pchar, "cartridge");
					Log_Info("�� �������� �������� ������");
				}
			}
		break;
		
		case "norman_fes1_fight":
			dialog.text = "������ ���������, ��� �� ��� �����. ���������!";
			link.l1 = "�� ���, ��������?!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes1_peace":
			dialog.text = "��-�� ��! �� ���, ����� �� ��� ��������.";
			link.l1 = "����, �������!";
			link.l1.go = "norman_fes1_exit";
		break;
		
		case "norman_fes1_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 13)
			{
				GiveItem2Character(pchar, "gold_dublon");
				Log_Info("�� �������� ������� ������");
			}
			else
			{
				if (GetDataDay() == 1 && GetDataMonth() == 4)
				{
					GiveItem2Character(pchar, "chest");
					Log_Info("�� �������� �������� � ���������");
				}
				else
				{
					AddMoneyToCharacter(pchar, 5);
				}
			}
		break;
		
		case "norman_fes2_fight":
			dialog.text = "� �� ������ �� ���������� ��� ���! ������ �������� ������ ����, ��� �������� ���������...";
			link.l1 = "������ ����� ��� �� �������!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes2_peace":
			dialog.text = "��������, ���� ��������������! �� ������� � ��� � ���� �������. ������������� ������� �������� ��� �� ��������� ��������.";
			link.l1 = "������ �������...";
			link.l1.go = "norman_fes2_exit";
		break;
		
		case "norman_fes2_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 14)
			{
				GiveItem2Character(pchar, "amulet_10");
				Log_Info("�� �������� ������ '����������'");
			}
			else
			{
				if (GetDataDay() == 25 && GetDataMonth() == 12)
				{
					GiveItem2Character(pchar, "totem_04");
					Log_Info("�� �������� �������� '�������'");
				}
				else
				{
					GiveItem2Character(pchar, "Mineral3");
					Log_Info("�� �������� �������� �����");
				}
			}
		break;
		
		case "norman_fes3_fight":
			dialog.text = "��� �� ���! � ������ ���������, �������� �� ����� ����! ��� ��������� �������� �����, ����� ������ ��� ������ ����!";
			link.l1 = "������ �� ����, ��������!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes3_peace":
			dialog.text = "�� ����� � ����� ���������, �����. ��-�� ���, ���������.";
			link.l1 = "�������!";
			link.l1.go = "norman_fes3_exit";
		break;
		
		case "norman_fes3_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 15)
			{
				GiveItem2Character(pchar, "potion4");
				Log_Info("�� �������� ��������");
			}
			else
			{
				if (GetDataDay() == 19 && GetDataMonth() == 6)
				{
					GiveItem2Character(pchar, "talisman8");
					Log_Info("�� �������� ������ '��������'");
				}
				else
				{
					GiveItem2Character(pchar, "potion1");
					Log_Info("�� �������� �������� ��������")
				}
			}
		break;
		
		case "norman_fes4_fight":
			dialog.text = "�� �� ���� �������, ������. ������, ������� ������ �� �������...";
			link.l1 = "� ��, ������, �� ������!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes4_peace":
			dialog.text = "����� ����, �� �������. � ��� � ����. ��� ���� �� ���������!";
			link.l1 = "�������� �� ������, ������...";
			link.l1.go = "norman_fes4_exit";
		break;
		
		case "norman_fes4_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 17)
			{
				GiveItem2Character(pchar, "cirass6");
				Log_Info("�� �������� ����� �������");
			}
			else
			{
				if (GetDataDay() == 1 && GetDataMonth() == 1)
				{
					GiveItem2Character(pchar, "cirass3");
					Log_Info("�� �������� �������� ������");
				}
				else
				{
					GiveItem2Character(pchar, "Mineral18");
					Log_Info("�� �������� �����");
				}
			}
		break;
		
		case "norman_fes5_fight":
			dialog.text = "�������� �� ����, ������, ���� �����, ���� ������ ��������� �����?";
			link.l1 = "�������! � �����-�� � ���� ������ �� �����������!";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "norman_fes5_peace":
			dialog.text = "�� ��! ��� � ���� ������� ����������! ��� ���� �� ��������!";
			link.l1 = "���� ���, ���������.";
			link.l1.go = "norman_fes5_exit";
		break;
		
		case "norman_fes5_exit":
			DialogExit();
			NextDiag.CurrentNode = "norman_fes_again";
			PlaySound("interface\important_item.wav");
			PlaySound("interface\important_item.wav");
			if (GetDataDay() == 16)
			{
				GiveItem2Character(pchar, "potionrum");
				Log_Info("�� �������� ������� ����");
			}
			else
			{
				if (GetDataDay() == 28 && GetDataMonth() == 11)
				{
					GiveItem2Character(pchar, "totem_01");
					Log_Info("�� �������� ����� '������� ������'");
				}
				else
				{
					GiveItem2Character(pchar, "Mineral17");
					Log_Info("�� �������� ���������� ������");
				}
			}
		break;
		
		case "norman_fight_again":
			dialog.text = "�-�, � ���� �����! ��-��!";
			link.l1 = "�����...";
			link.l1.go = "fight";
		break;
		
		case "norman_fes_again":
			dialog.text = "���-���, ��������, ����������-����������, � �����. ����� ���� ������.";
			link.l1 = "��� �������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "norman_fes_again";
		break;
		
		case "tieyasal":
			dialog.text = "������? � ����� �� ���� �� �����������, �?";
			link.l1 = "�� ����� �� ���. ������ ����� �������. ��� �� ����� ���?";
			link.l1.go = "tieyasal_1";
			link.l2 = "��� - �����? ������ - ��� ��������� ��������, ����� ������� - ����. �� ������...";
			link.l2.go = "tieyasal_2";
			link.l3 = "����, ����� �� �������� ��� ����� ��������, ��� ������ �����-�� ��� ����� �������.";
			link.l3.go = "tieyasal_3";
			if (CheckAttribute(pchar, "questTemp.Ksochitam.SQCapBookRead")) // ������ ������ �����-��������
			{
				link.l4 = "������ ������ ���� ������ ��������. ������� � � ���������� ���.";
				link.l4.go = "tieyasal_4";
			}
			npchar.quest.Tieyasal = "true";
		break;
		
		case "tieyasal_1":
			dialog.text = "������ �����... ������-������ �����! ������ ������ - � ������ �����! ���, �� ����� � ���. ����� �� �����. ����� �� ������ ����, ��������.";
			link.l1 = "��... �����, ����.";
			link.l1.go = "exit";
		break;
		
		case "tieyasal_2":
			dialog.text = "����, ������, ��������... ���-�� ��� ������ ������ �������� ���������. ������ ����� ������ ������...";
			link.l1 = "�, ������, �� ����?";
			link.l1.go = "fight";
			NextDiag.TempNode = "norman_fight_again";
		break;
		
		case "tieyasal_3":
			dialog.text = "��, �� ����� ���� ������ ������, ��� �� ������. �� � �� ����, ��� ��. ��� - �� �����. ��� ��� ������ � ��������, ��������, �� �������� ���� �������� �������.";
			link.l1 = "��... ������� �� �����, ��������.";
			link.l1.go = "exit";
		break;
		
		case "tieyasal_4":
			dialog.text = "� ���� �� ��������� ������, ��� �� ������� ��� ��������, �, �������?";
			link.l1 = "";
			Link.l1.edit = 8;
			link.l1.go = "tieyasal_5";
		break;
		
		case "tieyasal_4_1":
			dialog.text = "� ������ - ������ ������ ����� �� ����? ������, ������ ��, �����.";
			link.l1 = "";
			Link.l1.edit = 8;
			link.l1.go = "tieyasal_5";
		break;
		
		case "tieyasal_5":
			sTemp = GetStrSmallRegister(dialogEditStrings[8]);
			if (sTemp == "����� ����" || sTemp == "������ �����")
			{
				dialog.text = "��-�-�...(������������) ��� �� ���� ��������, ��� ������ ����� ���� ������?";
				link.l1 = "�� ��. � ���� ���� �� �� �� ������ ����������, � ��������������. ������ � ������� �������...";
				link.l1.go = "tieyasal_6";
				break;
			}
			if (sTemp == "����" || sTemp == "�����")
			{
				dialog.text = "C ����� ����� �����������, ��������...";
				link.l1 = "� ������ - �����������?";
				link.l1.go = "tieyasal_4_1";
				break;
			}
			dialog.text = "�-�... �� ���� � ����. � ��� ��� ������ ������� ������� �����������? �� ������ ������ ���������! ��, ��������, �� ����� � ������ ��� �����. ����� �� ������.";
			link.l1 = "����...";
			link.l1.go = "exit";
		break;
		
		case "tieyasal_6":
			dialog.text = "������ ����, ��������. ��� ��� ���� �����, �? ����������� � ���-��...";
			link.l1 = "������� "+GetFullName(pchar)+".";
			link.l1.go = "tieyasal_7";
		break;
		
		case "tieyasal_7":
			dialog.text = "��� ���, ������� "+pchar.name+". ������ ������ ���� ������� ������. � ��� ����� ���, ��-��. �� ��� ����� �� �������. ���������, ���� ��� ��� ������� ��������. �����, �� - ��������. � ���� �����-�� � ��� ������ ������������ � ������� ������ �������� �����! ��, ��� ���� �������! �� ����� � ������� ���� �����, ������ � �����, � ��� ������ �� �����\n���, � ��� ��� �? �� ��! ��� ������, ��� ��� ������ �����, �� ��� �� ���. ���-���. ��� ��� ������ ���, �������� �������, �� ��� ������ ��� ���������\n�� ��������� ������ ��� � �������, ����� ��� ������ ������ � ���� �������� ������, '�������'. ��� �� ������� ��� �����, � � ����� ��������. � � �����, ��� ������ �������� ����� ���� �� ������ ���� ���������� �����, � ��� ������ ������� ������� ���� � ����. � � �����, ��� ������ ����� �����, � � ������� ��� ������� ������ �����\n��� �� ��������, ���-���. ������ ��� ������ �� ���� �� ������� � ��� ����, � ����� - ���. � ��� ��� �����. � ������ ���, ����� ���! ������ ����� �� ���� �� ����. ����������� ����� ������ � �������� �������...";
			link.l1 = "�� �� ������, ��� ������ ������ '�������������'. ������? ��� ������?";
			link.l1.go = "tieyasal_8";
		break;
		
		case "tieyasal_8":
			dialog.text = "�� ���, �������, �� ������ ����������? '������' � ����� �������� - '����������'. ����������� ������, ������ �����������, ��� ��� ��� ����������.";
			link.l1 = "������ �����������?.. ��. ���-�� ��� ��� ����������. ��� ������ �� ���� ������ - ���. ����� �������� ���������...";
			link.l1.go = "tieyasal_9";
		break;
		
		case "tieyasal_9":
			dialog.text = "�� ���� �� � ������, � �� �����, ��� �� - �������. ���-���, �� �������. ���� � �����.";
			link.l1 = "� ��� �� ��? ����������, �������?";
			link.l1.go = "tieyasal_10";
		break;
		
		case "tieyasal_10":
			dialog.text = "� �� �� ����, ��������... ��, ������ - �������. ��, ��-���������� ������ ������ ������, �� ���� ����. � ��-�������� ����. ������ � ��� ����� ����� ��������� �����. � ����� ����� ������� � ����� �����. ��� ���� �� �����, �� �� ����������. � ���� ����� ������.";
			link.l1 = "� ��-�������� �� �� �������?";
			link.l1.go = "tieyasal_11";
		break;
		
		case "tieyasal_11":
			dialog.text = "� ��� ��� ��������. �����, � �������. ���� - �����, �������! �� ��������� ���������� ����� �� ���������� �����, � ����� ��� ���� ������� ������ ��� � �������� ����. ���, ��������, ������ ���-�� �����: ������ ���� ���! � ����� ������� ����� � ������� �� �������� ����������. ��� ��� ��� �� ����� ���������: ��� �����, ��� �����! �� ��� ����� ���� �������, �� � �� ����� �����.";
			link.l1 = "��� �� ��������� ����. ��� ������. ������... ������?! ���� ������!!";
			link.l1.go = "tieyasal_12";
		break;
		
		case "tieyasal_12":
			dialog.text = "�� ���� ��������, ������? ���� �����? ����� ���� �������? ��� ���?";
			link.l1 = "�� ��� �� � �����-�� �� ���������! ��� ������ �� �����������! ������! ������... ������ �����������!!";
			link.l1.go = "tieyasal_13";
		break;
		
		case "tieyasal_13":
			dialog.text = "��������, �������, ������ - ���� �������. ��� � �����, ��������... ������ - �������?";
			link.l1 = "� ����, ��� ���� ������ ������ �� ����� ����. �� ������������� �� �������. �� �������! �� ��� �� � ��� ����!";
			link.l1.go = "tieyasal_14";
		break;
		
		case "tieyasal_14":
			dialog.text = "��-�, ��������, �� �� �������. � ���� ������ - ����������. ��� ����� ������� ��������� ����������, �� �������� ��� �������, �� ������� ��� ���� ���, � �� ��� � �������� �� ���� ����� ������ ������. �� ����� �� ������, � � ����. � ���� � ������ ��������...";
			link.l1 = "������� ������ � ��� �������������. ��� ��, �������?! �� ��� ���?!";
			link.l1.go = "tieyasal_15";
		break;
		
		case "tieyasal_15":
			dialog.text = "��-�... ��, �� ��� ���. �� �� ����. ��� ������ ��� �� ���� ������.";
			link.l1 = "����� �� ���� ��������? ����� � ���� �������?";
			link.l1.go = "tieyasal_16";
		break;
		
		case "tieyasal_16":
			dialog.text = "������� � ���� - ������. ������� ������� ������. � ����� �� ��� ���... �����, ��������� ���-��, ������������. �� � ��������� ��� ���������, ��-��! �� ����� ������-�� "+GetFullName(pchar)+"!. ��, ��� ��� � ������� - "+GetFullName(pchar)+"!. ����, ��� ��� �� �� - "+GetFullName(pchar)+"! ��� �� ���� �����, ��������.";
			link.l1 = "� �� �� ������, �����?";
			link.l1.go = "tieyasal_17";
		break;
		
		case "tieyasal_17":
			dialog.text = "�� �� ����� �� ��� ����, ����� ������ � ����� ����. �� ����� �������� �������� ����. ��-��, ��������! �� � ���������, �������!";
			link.l1 = "�� ����������...";
			link.l1.go = "tieyasal_18";
		break;
		
		case "tieyasal_18":
			dialog.text = "� ��? ����� �� ��� �����? �, �������, �������: ����� ����� ���! ���� ���, ���� ��������! ������� �� ������ �����! ����� ��� �������� ������. � ����� ��� ��� �������� - ���� � ��������.";
			link.l1 = "���� ���������� ������?";
			link.l1.go = "tieyasal_19";
		break;
		
		case "tieyasal_19":
			dialog.text = "�� ��������� � ��������. ������, ��� "+GetFullName(pchar)+"! ������� ������ ��� ��������� � ������� �������. �� �� ������� ����� ����� �����... ����, ���� ���� ��� ��������!";
			link.l1 = "��� �������?";
			link.l1.go = "tieyasal_20";
		break;
		
		case "tieyasal_20":
			dialog.text = "���� ������. �� �������� ��������� ���� �����. �, � ����, ����! ���� ����������, �������: � ����� ���� ������ ����� �������, � ����� ��� �� ���� ����. ������� �� ����� �����. �� ��� ���� ��������.";
			link.l1 = "� ����������...";
			link.l1.go = "tieyasal_21";
		break;
		
		case "tieyasal_21":
			dialog.text = "� ���: ���, ������ ��� �����. ����-����, ��� ���� �����������. ��� ������ ������ �������� ���������, ��-��. �������� ������. ������ �� ����������. �� ���������, ����. ����� ���� ������ ���� �������!";
			link.l1 = "��, �������, �������.";
			link.l1.go = "tieyasal_22";
		break;
		
		case "tieyasal_22":
			RemoveCharacterEquip(npchar, BLADE_ITEM_TYPE);
			RemoveItems(npchar, "blade_29", 1);
			sTemp = GetBestGeneratedItem("blade_29");
			GiveItem2Character(pchar, sTemp);
			sld = ItemsFromID(sTemp);
			sld.Balance = 1.0;
			GiveItem2Character(npchar, "blade_19"); 
			EquipCharacterbyItem(npchar, "blade_19");
			Log_Info("�� �������� ������ ���������");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ������ ���. ���, ��� �� ����� ������. ����� ����� ���. ��� ������. �������. �� ���� ���������!";
			link.l1 = "�������, �������. �� ���� �� �������������, ��� ��� �����. �����!";
			link.l1.go = "tieyasal_23";
		break;
		
		case "tieyasal_23":
			DialogExit();
			pchar.questTemp.Tieyasal.MigelKnow = "true";
			AddQuestRecord("Tieyasal", "4");
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
			pchar.questTemp.Tieyasal = "islatesoro";
		break;
		
		case "fight":
			iTemp = 20-sti(GetCharacterItem(npchar, "potion2"));
			TakeNItems(npchar, "potion2", iTemp);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}