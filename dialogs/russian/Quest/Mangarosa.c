// ������� ���������� �� ������ ���������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
        case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			dialog.text = "��� ��� ����?";
			link.l1 = "������.";
			link.l1.go = "exit";
		break;
		
		// ������ - ��������-�������
		case "amelia":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			dialog.text = "��� ���� ����� � ���� ����?";
			if (CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "amelia")
			{
				link.l1 = "���� ����� ������, �����? � ������ � ���� � ��������, ���������� ������ ��������. ���������.";
				link.l1.go = "amelia_1";
			}
			else
			{
				link.l1 = "����, ��������, ��� ������ ���� �������. �� � ��� �������...";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "amelia";
		break;
		
		case "amelia_1":
			dialog.text = "����� ���������! � ��� �� ���� ��� ��� ���������������, �, �������?";
			link.l1 = "�� ���� �� �����. �������, ��� �� ������ ������� ����� �������� � ������ ������� �������� �� ���� �����-�� ��������� �����...";
			link.l1.go = "amelia_2";
		break;
		
		case "amelia_2":
			dialog.text = "��, ����� ������ � ����, ��� �� ��� �������� ��������, � ������� ������ ����. �����, �� ������ ���������� ������� ��������, � ������ ������ ���� � ���������� ���� �� ������ ���. ��� ���� ���������?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "��� ���, ������.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "��...";
				link.l1.go = "amelia_exit";
			}
		break;
		
		case "amelia_exit":
			dialog.text = "��, � ��� �� ��� ��� ��������� ��������? ��� � ���� ���������. ��� ��� ����� ������, ������, ���� � �� ������������. �������� �������.";
			link.l1 = "��...";
			link.l1.go = "exit";
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_wait":
			dialog.text = "����� ��? �� ������ �� �����, ������...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "�� �������, ������. � ������� ��� � ������ �� ���-�� �������. ���, � ������ ���������. ������.";
				link.l1.go = "amelia_3";
			}
			else
			{
				link.l1 = "...";
				link.l1.go = "amelia_exit";
			}
			NextDiag.TempNode = "amelia_wait";
		break;
		
		case "amelia_3":
			dialog.text = "���... ������, �� ���-���� ���-�� ������. � �� ������, ����� � ���������� ���� ������� ����� ����� �� ����� ��������?";
			link.l1 = "������ ���. ��, �������, �� ���������, � �������...";
			link.l1.go = "amelia_4";
		break;
		
		case "amelia_4":
			dialog.text = "��� �� �� ����� �� �������, �������! �� ����� �� ������ �� �����. �� ��� ��, � �� ������ ���������� �������� � ���������, ������� ��� �� ���� ������, � ������� �� ��������� ��� ������ �������� �� ���������� ������...";
			link.l1 = "������, ����� ��� ��� �����������, �������� ���� ���� �� � ����� ������ - ��� �� ����� ���������� �� ���������?";
			link.l1.go = "amelia_5";
		break;
		
		case "amelia_5":
			dialog.text = "�����������, ������, �� � ����� �� �����. � �������� ���� - � �� ������, ������ �� �������, ��� ���. �� �� ����� ������ � ���� ���� �� �����������, ���, �� �� �����. ��� �� �������� ������ �������: �� ��������� ���������� �����, �������������� �� ���������� �����������. ��� ����� ������� ���� ����� �������, ���������� � �������, ���� ������� ����������� ����������� �� ���� ����.";
			link.l1 = "����� ���������! ������ ���� ����.";
			link.l1.go = "amelia_6";
		break;
		
		case "amelia_6":
			dialog.text = "� ���� ������� ���� �������� ���� �����. �� ������ ������ � ����� ���� ������� ��������� � ������ ������� �����.";
			link.l1 = "�������� �� ���� ���� ������ ��������� - ��� ������ ������?";
			link.l1.go = "amelia_7";
		break;
		
		case "amelia_7":
			dialog.text = "����� ���������� ����� �����, �� ������ ������� �������� �������. �������� ���� ����� ��������� � �������������� �������������� ����� �����\n������ ����� ������� ���� ���� � ������������. �� ����������� ������, ������ �������� ������������� ������ � ��� � ���������� ������ ��������\n������ ����� ����� ���� ��������, ��������, ������������, � ����� ������� �����\n������ ����� �������� � ���� ������� ������� � �������, �� ����� ������. ������ ��� ����� ������� ���� �������, ����������� � ���� � ������� ����� ���������\n����� ��� ����� �� ��������� ������������ ������ �� ��������. ����������� �� ������� ������ �� ������, � �� ������, ��� ���������� �������� ����������� - � ��������� ������ �� ������ �� ����� �������, �� �������� - �������� ����������\n�� ���, �������, �� ����� �������� ���� ����� ������, ��� ���� ����� ����� �� �����������?";
			if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
			{
				link.l1 = "��, � �����.";
				link.l1.go = "amelia_8";
			}
			link.l2 = "� ���� ������� ��������. ��� ��������� �������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_next":
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "�-�, ��� ��, �������! �� ���, �������� ���� ��� �����?";
				link.l1 = "���� �����, ������. ������� ����!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "�-�, ��� ��, �������! �� ������ ������ � ���� �������� ����� �� ���������, ���?";
				if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
				{
					link.l1 = "������. �� ���� � � ������.";
					link.l1.go = "amelia_8";
				}
				link.l2 = "���� ���, ������. ������ �������� ���������.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "amelia_next";
		break;
		
		case "amelia_8":
			dialog.text = "����� ������. ����� ������ �� ������ ����������?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "������ ����� ���� � ������������.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "������ ����� �������� � ������������.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "������ ������������ �����.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "������. � ������� ��� '���� ������'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, ������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "������. � ������� ��� '�����'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, ������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "������. � ������� ��� '����� ����'. ���, ������ ���������� �������������. ������ ������ �� �������. �� ������� � �������� ����������!";
			link.l1 = "�������, ������...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "amelia_next";
			RemoveItems(pchar, "gold_dublon", 300);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("�� ������ 300 �������� � ������� ���������");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;
	}
} 
