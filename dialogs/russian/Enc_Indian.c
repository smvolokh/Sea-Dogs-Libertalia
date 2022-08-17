//Jason ������ �������� � ��������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int iQty;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("�����������","����� ����") +" ����� ��������?", 
				"����� ��, "+ GetSexPhrase("�����������","����� ����") +".", 
				""+ GetSexPhrase("����������� ����� ��������. �� ����� �� ����.","����� ���� ����� ��������.") +"",
                "���� ������� �� ��� ���������"+ GetSexPhrase("��� �����","�� ������") +".", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("��.", 
				"��, ����� �.",
                "����� ��������.", 
				"� ���� ���"+ GetSexPhrase("","�") +" ���� ������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "����������, ����� ����. �� ������ �������� ������?";
				link.l1 = "�����������, ��� ��������. � ��� ���� ������, �� ��� ���� ���������� ���� ����.";
				link.l1.go = "exit";
				link.l2 = "��. � ������, � ��� ����� ������ ���������� �������. � ���� ��� ����-������ �� �������?";
				link.l2.go = "select_trade";
				npchar.quest.meeting = "1";
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "select_trade": //��������� ��������
			switch (drand(7))
			{
				case 0: // �������� ����� ���������
					dialog.text = "���� �������, ����� ����. � "+npchar.name+" ���� ����-���� ����� �� �������. ������ ����.";
					link.l1 = "��������� ���� ������...";
					link.l1.go = "torg";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 1: // �� �������
					dialog.text = "���, ����� ����. "+npchar.name+" ����� �� �������. "+npchar.name+" - ����.";
					link.l1 = "�������. �����, ������, ����������� ����.";
					link.l1.go = "exit";
				break;
				
				case 2: // ������ �������
					npchar.quest.item.qty = 25+drand(25);
					npchar.quest.item.price = 30+drand(10);
					dialog.text = "� "+npchar.name+" ���� ����� �����. ������� ����� �����, ����� ����. ����� "+FindRussianQtyString(sti(npchar.quest.item.qty))+". �� ������ �������� ��? � ������� �� "+FindRussianMoneyString(sti(npchar.quest.item.price))+" �����.";
					link.l1 = "���, ��� ��� �� ���������.";
					link.l1.go = "exit";
					link.l2 = "�������! �� ����� ���� � ����� �� ����������.";
					link.l2.go = "big_pearl";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 3: // ������ �����
					npchar.quest.item.qty = 40+drand(40);
					npchar.quest.item.price = 10+drand(5);
					dialog.text = "� "+npchar.name+" ���� ����� �����. ��������� ����� �����, ����� ����. ����� "+FindRussianQtyString(sti(npchar.quest.item.qty))+". �� ������ �������� ��? � ������� �� "+FindRussianMoneyString(sti(npchar.quest.item.price))+" �����.";
					link.l1 = "���, ��� ��� �� ���������.";
					link.l1.go = "exit";
					link.l2 = "�������! �� ����� ���� � ����� �� ����������.";
					link.l2.go = "small_pearl";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 4: //������� ���������
					npchar.quest.item.qty = 20+drand(20);
					npchar.quest.item.price = 90+drand(20);
					dialog.text = "� "+npchar.name+" ���� ������ ������, ������� ��, �����������, ������. ����� "+FindRussianQtyString(sti(npchar.quest.item.qty))+". � ������� ������, ����� �� "+FindRussianMoneyString(sti(npchar.quest.item.price))+" �����.";
					link.l1 = "���, ��� ��� �� ���������.";
					link.l1.go = "exit";
					link.l2 = "�������! �� ����� ���� � ����� �� ����������.";
					link.l2.go = "gold";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 5: // ���������� ���������
					npchar.quest.item.qty = 40+drand(40);
					npchar.quest.item.price = 40+drand(10);
					dialog.text = "� "+npchar.name+" ���� ����� ������, ������� ��, �����������, ������. ����� "+FindRussianQtyString(sti(npchar.quest.item.qty))+". � ������� ������, ����� �� "+FindRussianMoneyString(sti(npchar.quest.item.price))+" �����.";
					link.l1 = "���, ��� ��� �� ���������.";
					link.l1.go = "exit";
					link.l2 = "�������! �� ����� ���� � ����� �� ����������.";
					link.l2.go = "silver";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 6: // ������ ����� ���������
					dialog.text = "���� �������, ����� ����. � "+npchar.name+" ���� ����-���� ����� �� �������. ������ ����.";
					link.l1 = "��������� ���� ������...";
					link.l1.go = "torg";
					if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && !CheckAttribute(npchar, "quest.mangarosa"))
					{
						if (pchar.questTemp.Mangarosa == "gipsy" || pchar.questTemp.Mangarosa == "gipsy_trade")
						{
							link.l9 = "������. ������� � ���� ���� ���-��� �� �������. ��� ��������, ���������� ���������. � ������, �� ����� �������������...";
							link.l9.go = "mangarosa";
						}
					}
				break;
				
				case 7: // ������ �� �������
					dialog.text = "���, ����� ����. "+npchar.name+" ����� �� �������. "+npchar.name+" - ����.";
					link.l1 = "�������. �����, ������, ����������� ����.";
					link.l1.go = "exit";
				break;
			}
		break;
		
		case "torg":
			DialogExit();
			if (CheckNPCQuestDate(npchar, "Torg_date"))
			{
                SetNPCQuestDate(npchar, "Torg_date");
				GiveItemToTrader(npchar);
			}
			NextDiag.CurrentNode = "First time";
			LaunchItemsTrade(NPChar, 0);
			ChangeIndianRelation(0.25);
		break;
		
		// ������� ������
		case "big_pearl":
			dialog.text = "������� ���� �� ������ ������?";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "big_pearl_qty";
		break;
		
		case "big_pearl_qty":
			iQty = sti(dialogEditStrings[4]);
			npchar.quest.item.Byeqty = iQty;
			if (iQty < 1)
			{
				dialog.text = "�� ��������, �����������? ���� �� ����� ����� �����? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (iQty > sti(npchar.quest.item.qty))
			{
				dialog.text = "� �� �������, ������� � ���� ����. �� ������ ��� ������, �����������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			npchar.quest.item.Summ = iQty*sti(npchar.quest.item.price);
			dialog.text = ""+iQty+" ����? ������. � ���� " + FindRussianMoneyString(sti(npchar.quest.item.Summ))", ����� ����.";
			if (sti(Pchar.money) >= sti(npchar.quest.item.Summ))
			{
				link.l1 = "����� ���� ������, ����������� ����.";
				link.l1.go = "big_pearl_1";
			}
			link.l2 = "� ���� ������ ������������ �����. ����, �� � �� ����� ������ � ���� ������.";
			link.l2.go = "exit";
		break;
		
		case "big_pearl_1":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.item.Summ));
			TakeNItems(pchar, "jewelry52", sti(npchar.quest.item.Byeqty));
			PlaySound("interface\important_item.wav");
			dialog.text = "���, ������, ����� ����. ������ ��� ����.";
			link.l1 = "���������!";
			link.l1.go = "exit";
			ChangeIndianRelation(0.5);
		break;
		
		// ����� ������
		case "small_pearl":
			dialog.text = "������� ���� �� ������ ������?";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "small_pearl_qty";
		break;
		
		case "small_pearl_qty":
			iQty = sti(dialogEditStrings[4]);
			npchar.quest.item.Byeqty = iQty;
			if (iQty < 1)
			{
				dialog.text = "�� ��������, ����������? ���� �� ����� ����� �����? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (iQty > sti(npchar.quest.item.qty))
			{
				dialog.text = "� �� �������, ������� � ���� ����. �� ������ ��� ������, �����������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			npchar.quest.item.Summ = iQty*sti(npchar.quest.item.price);
			dialog.text = ""+iQty+" ����? ������. � ���� " + FindRussianMoneyString(sti(npchar.quest.item.Summ))", ����� ����.";
			if (sti(Pchar.money) >= sti(npchar.quest.item.Summ))
			{
				link.l1 = "����� ���� ������, ����������� ����.";
				link.l1.go = "small_pearl_1";
			}
			link.l2 = "� ���� ������ ������������ �����. ����, �� � �� ����� ������ � ���� ������.";
			link.l2.go = "exit";
		break;
		
		case "small_pearl_1":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.item.Summ));
			TakeNItems(pchar, "jewelry53", sti(npchar.quest.item.Byeqty));
			PlaySound("interface\important_item.wav");
			dialog.text = "���, ������, ����� ����. ������ ��� ����.";
			link.l1 = "���������!";
			link.l1.go = "exit";
			ChangeIndianRelation(0.5);
		break;
		
		// ������� ���������
		case "gold":
			dialog.text = "������� �� ������ ������?";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "gold_qty";
		break;
		
		case "gold_qty":
			iQty = sti(dialogEditStrings[4]);
			npchar.quest.item.Byeqty = iQty;
			if (iQty < 1)
			{
				dialog.text = "�� ��������, ����������? ���� �� ����� ���������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (iQty > sti(npchar.quest.item.qty))
			{
				dialog.text = "� �� �������, ������� � ���� ����. �� ������ ��� ������, �����������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			npchar.quest.item.Summ = iQty*sti(npchar.quest.item.price);
			dialog.text = ""+iQty+" ������? ������. � ���� " + FindRussianMoneyString(sti(npchar.quest.item.Summ))", ����� ����.";
			if (sti(Pchar.money) >= sti(npchar.quest.item.Summ))
			{
				link.l1 = "����� ���� ������, ����������� ����.";
				link.l1.go = "gold_1";
			}
			link.l2 = "� ���� ������ ������������ �����. ����, �� � �� ����� ������ � ���� ���������.";
			link.l2.go = "exit";
		break;
		
		case "gold_1":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.item.Summ));
			TakeNItems(pchar, "jewelry5", sti(npchar.quest.item.Byeqty));
			PlaySound("interface\important_item.wav");
			dialog.text = "���, ������, ����� ����. ������ ��� ����.";
			link.l1 = "���������!";
			link.l1.go = "exit";
			ChangeIndianRelation(0.5);
		break;
		
		// ���������� ���������
		case "silver":
			dialog.text = "������� �� ������ ������?";
			link.l1 = "";
			Link.l1.edit = 4;
			link.l1.go = "silver_qty";
		break;
		
		case "silver_qty":
			iQty = sti(dialogEditStrings[4]);
			npchar.quest.item.Byeqty = iQty;
			if (iQty < 1)
			{
				dialog.text = "�� ��������, ����������? ���� �� ����� ���������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			if (iQty > sti(npchar.quest.item.qty))
			{
				dialog.text = "� �� �������, ������� � ���� ����. �� ������ ��� ������, �����������? ����� ������.";
				link.l1 = "��...";
				link.l1.go = "exit";
				break;
			}
			npchar.quest.item.Summ = iQty*sti(npchar.quest.item.price);
			dialog.text = ""+iQty+" ������? ������. � ���� " + FindRussianMoneyString(sti(npchar.quest.item.Summ))", ����� ����.";
			if (sti(Pchar.money) >= sti(npchar.quest.item.Summ))
			{
				link.l1 = "����� ���� ������, ����������� ����.";
				link.l1.go = "silver_1";
			}
			link.l2 = "� ���� ������ ������������ �����. ����, �� � �� ����� ������ � ���� ���������.";
			link.l2.go = "exit";
		break;
		
		case "silver_1":
			AddMoneyToCharacter(pchar, -sti(npchar.quest.item.Summ));
			TakeNItems(pchar, "jewelry6", sti(npchar.quest.item.Byeqty));
			PlaySound("interface\important_item.wav");
			dialog.text = "���, ������, ����� ����. ������ ��� ����.";
			link.l1 = "���������!";
			link.l1.go = "exit";
			ChangeIndianRelation(0.5);
		break;
		
		// ���������
		case "mangarosa":
			dialog.text = "���������? � ������ �� ��� �������.";
			link.l1 = "����������, ������...";
			link.l1.go = "mangarosa_1";
		break;
		
		case "mangarosa_1":
			npchar.quest.mangarosa = "indian_"+(drand(10)+1);
			dialog.text = "��. ���. ���� �������� ����� ���� �� �������� - ���������. � ���� �� ���� ���� ������, ����� ������� ������, ���������� - "+XI_ConvertString(npchar.quest.mangarosa)+". ������ ��������?";
			link.l1 = "��������, ����������� ����, � �� ����� �������� ������ �� ���� ��������. ����� ��� ��� ��� �����, �� ����������?";
			link.l1.go = "mangarosa_2";
		break;
		
		case "mangarosa_2":
			dialog.text = ""+npchar.name+" �� ��������. ���� �� ������ �������� - � ���� ���� �� ��������� ������. ���� ��� - ����� � ����.";
			link.l1 = "��, �����. ����� ��������.";
			link.l1.go = "mangarosa_3";
			link.l2 = "���. � �������� ��� �������� �� ������ �� ����.";
			link.l2.go = "exit";
		break;
		
		case "mangarosa_3":
			Log_Info("�� �������� ������");
			GiveItem2Character(pchar, npchar.quest.mangarosa);
			RemoveItems(pchar, "cannabis7", 1);
			dialog.text = "����� ���� "+XI_ConvertString(npchar.quest.mangarosa)+". �� ���� ����������.";
			link.l1 = "�� ����������. ���������� ������, ����������� ����...";
			link.l1.go = "exit";
			ChangeIndianRelation(0.5);
		break;
		
		//��������� �� ����������� ������ �� ���������� ���� citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "�� �������� ������, �����������! ����� ���� �����!", "������, �, ��� ��������� ����� ������, ����� ��� �� ������ � ��� � ���������� �������.");
			link.l1 = LinkRandPhrase("������.", "�����.", "��� �������...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
