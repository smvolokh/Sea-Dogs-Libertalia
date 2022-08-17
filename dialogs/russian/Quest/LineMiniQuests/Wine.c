void ProcessDialogEvent()
{
	ref sld, NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "����� ���. �������� Jason'�, ��� � ��� ����� ��������������� ��� ��������.";
			link.l1 = "����������� ������!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "Wine_fort":
			dialog.text = "�� ���, ������ ���������?";
			if (CheckCharacterItem(pchar, "potionwine"))
			{
				link.l1 = "��, �����, ��� ��������������. ��� ��� �������� � 700 �����, ��� ��� � ���� 1000 ����.";
				link.l1.go = "Wine_fort_1";
			}
			link.l2 = "���, � ��� ���� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Wine_fort";
		break;
	
		case "Wine_fort_1":
			AddMoneyToCharacter(pchar, 1000);
			RemoveItems(PChar, "potionwine", 1);
			dialog.text = "����, ������� ����, �������! ���, ����� ���� ������, � ��� ��������� ������ ���, ��-��-��! ��������, ��� ��� ����� ���� �����, �� � ���� � ���� ����� ��� ���� �������\n�� ��� �� �� �� ��������� � ������ ��� ����, ��� ���� � ���� ���� ������, ��� �����? �� ��� ������� ������ ��������������� ��������, ��� ��� ������ � ��� �������, ��-��...";
			link.l1 = "���, �������, ������, ��� � ���� �������.";
			link.l1.go = "Wine_fort_exit";
			link.l2 = "��, ��� ���������. ������� ������� ��� ����?";
			link.l2.go = "Wine_fort_2";
		break;
	
	case "Wine_fort_exit":
			dialog.text = "��, ��� �������. ��� ����� ������� �� ������!";
			link.l1 = "�����, ��������!";
			link.l1.go = "exit";
			sld = characterFromId(pchar.questTemp.Wine.id);	
			sld.lifeday = 0;
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", -1);
			pchar.questTemp.Wine.fail = "true";
			CloseQuestHeader("Wine");
	break;
	
		case "Wine_fort_2":
			dialog.text = "��, ��� ����� ���� � ������ �� �������, ���� ���������� ������� �� ������ ���� ���������, �� �� ������. �� � ������ ������ ���� �� ������� - ���������� ���������.";
			link.l1 = "������. ����� ��� ���� ����.";
			link.l1.go = "Wine_fort_3";
		break;
	
		case "Wine_fort_3":
			dialog.text = "��� � ������! � ������� �� ���, �������. ������ ������������ �������� ���� �� �����, ��� �� ������ - ����� �� ������ � �������� �� ���������� �����, � ���� ����� �����-������ �� �����.";
			link.l1 = "�������. ���������� ���������.";
			link.l1.go = "exit";
			pchar.questTemp.Wine.bottles = "true";
			npchar.lifeday = 7;
			AddQuestRecord("Wine", "1");
			AddQuestUserData("Wine", "sCity", XI_ConvertString("Colony"+pchar.questTemp.Wine.City+"Gen"));
			AddQuestUserData("Wine", "sName", pchar.questTemp.Wine.SName);
			SetFunctionTimerCondition("Soldier_wait", 0, 0, 7, false);
			NextDiag.TempNode = "Wine_fort_check";
		break;
	
		case "Wine_fort_check":
			dialog.text = "��, �������, �� �������� ����?";
			if (sti(pchar.items.potionwine) >= 10)
			{
				link.l1 = "��, ������.";
				link.l1.go = "Wine_take";
			}
			link.l2 = "���. � ��� ���� ���������.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Wine_fort_check";
		break;
	
		case "Wine_take":
			pchar.questTemp.Wine.Qty = sti(pchar.items.potionwine);
			pchar.questTemp.Wine.Money = sti(pchar.questTemp.Wine.Qty)*1000;
			if (sti(pchar.items.potionwine) > 60)
			{
				dialog.text = "�-�, ������� ��� � ��� �������! �����������! ������, ��� � ��� ������� - ����� � ��� ������ �� ���������� - ������ ���, � ���������. ������� ���� ������, � ���������� ��������� � �������.";
				link.l1 = "���������. ������, �� � �������� ������� ���������!";
				link.l1.go = "Wine_take_1";
				pchar.questTemp.Wine.Money = 60000;
				RemoveItems(PChar, "potionwine", 60);
			}
			else
			{
				dialog.text = "���, ������� ���������... �� �������� "+sti(pchar.questTemp.Wine.Qty)+" �������. �������! � �� �������. ������ - ��� � ��������������: " + FindRussianMoneyString(sti(pchar.questTemp.Wine.Money))".";
				link.l1 = "������� ���� ����. ������, �� � �������� ������� ���������!";
				link.l1.go = "Wine_take_1";
				RemoveItems(PChar, "potionwine", sti(pchar.questTemp.Wine.Qty));
			}
		break;
	
		case "Wine_take_1":
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.Wine.Money));
			dialog.text = "��������� ��� �� ���� ����, " + GetAddress_Form(NPChar) + "! �������� ���� ������ � �������� �������������� �������������, ����� ����������� �����-������, � ��� �� �� ����� ��� ����������. � ������ ��� ���� ����. ����� �������!";
			link.l1 = "����, ��������!";
			link.l1.go = "Wine_take_2";
		break;
	
		case "Wine_take_2":
			DialogExit();
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "newblade11");
			Log_Info ("�� ������ ����");
			Log_Info ("�� �������� ������");
			pchar.quest.Soldier_wait.over = "yes";//����� ����������
			DeleteAttribute(pchar, "questTemp.Wine.City");
			sld = characterFromId(pchar.questTemp.Wine.id);
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload2", "none", "", "", "", -1);
			sld.lifeday = 0;
			CloseQuestHeader("Wine");
			AddCharacterExpToSkill(pchar, "Commerce", 150);//��������
			AddCharacterExpToSkill(pchar, "Leadership", 50);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 50);//�������
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
