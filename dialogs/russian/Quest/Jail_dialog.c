void ProcessDialogEvent()
{
	ref NPChar;
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
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "Jail_officer_take":
		//--> ������������ �����������
		if (CheckAttribute(pchar, "GenQuest.Contraoffer.Jail"))
		{
			dialog.text = "�� ��������� � �������� ��� ������� �������� � ����� �����������. ��������� �� ����� ��������� ���������, � �������� ���� ��������� � ��������, �� ��������� � ������ ����� ���� "+FindRussianDaysString(sti(pchar.questTemp.JailTemp2))+". ����� ����, ��� ������ �� ������ � ������������� ������� - "+FindRussianMoneyString(sti(pchar.questTemp.JailTemp1))+" ��������� � ��������� � ��������� �����. ��������� ����������������, �������! ��-��!";
			link.l1 = "";
			link.l1.go = "Jail_officer_take_1";
			DeleteAttribute(pchar, "GenQuest.Contraoffer.Jail");
			NextDiag.currentnode = "Jail_officer_free";
			break;
		}
		//<-- ������������ �����������
			dialog.text = "�� ��������� �� ���������� ������������ � ��������� � ������ "+FindRussianDaysString(sti(pchar.questTemp.JailTemp2))+". ����� ����, �� ������ ����������� �� "+FindRussianMoneyString(sti(pchar.questTemp.JailTemp1))+". ��������� ����������������, ��-��!";
			link.l1 = "";
			link.l1.go = "Jail_officer_take_1";
			NextDiag.currentnode = "Jail_officer_free";
		break;
		
		case "Jail_officer_take_1":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 10);
			DialogExit();
			DoQuestFunctionDelay("InPrison", 10.0);
		break;
		
		case "Jail_officer_free":
			dialog.text = "�� ��� ��, ���� ������ ���������� �����. �������, ��� �������� ��� ������. �� ��������. ���� ���� �������� � ������� �� ����� � ���������. � �� ����������� ������!";
			link.l1 = "";
			link.l1.go = "Jail_officer_free_1";
		break;
		
		case "Jail_officer_free_1":
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", 5);
			DialogExit();
			DoQuestFunctionDelay("GoFromPrison", 5.0);
		break;
	}
} 
