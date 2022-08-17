// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "��������, � ������.";
			link.l1 = "� "+ GetSexPhrase("������","��������") +". ��������.";
			link.l1.go = "Exit";
			// �������
			if (CheckAttribute(pchar, "questTemp.Caleuche.Bandos") && pchar.questTemp.Caleuche.Bandos == "start")
			{
				link.l1 = "� ������, ��� � ������������ ������ ��������� ����� ����� � �����������. � ��� ��� ����� ���������� � ����� ������.";
				link.l1.go = "caleuche";
			}
			if (CheckAttribute(pchar, "questTemp.Caleuche.Bandos") && pchar.questTemp.Caleuche.Bandos == "know" && CheckAttribute(pchar, "questTemp.Caleuche.belizbandos") && GetQuestPastDayParam("questTemp.Caleuche.belizbandos") < 3)
			{
				link.l1 = "� ���� �������� ��� ���-��� � �����.";
				link.l1.go = "caleuche_3";
			}
			if (CheckAttribute(pchar, "questTemp.Caleuche.BelizRegard"))
			{
				link.l1 = "����� ������� � �����? �� ����� �� � ������?";
				link.l1.go = "caleuche_7";
			}
		break;
		
		// �������
		case "caleuche":
			dialog.text = "���� ����� ��� �� �������. ��� ������� ����� ����� ��������� �������� �����. �� ������ ���-�� �������� � ���?";
			link.l1 = "����� ����, ��� ��� ������ ������ ��� ���� ���� - ������. � ��������, ��� �� ��� ���������� ��� ��� ���-������. ��������, ��� ���-�� �� �� ����� ������ � ����� ���� ���������...";
			link.l1.go = "caleuche_1";
		break;
		
		case "caleuche_1":
			dialog.text = "� ��� ���������, �������. � ��� ��� � ��� ������� �������� ����� ����, ��� ��� �������� ���-�� � ��������, � � ������ � ��� ���� ���������. ��� � ��, ��� ��� ��������. ���� ������� ������ - ���������� ��� �������.";
			link.l1 = "������, ������. � ����������� ��� � ������.";
			link.l1.go = "caleuche_2";
		break;
		
		case "caleuche_2":
			DialogExit();
			AddQuestRecord("Caleuche", "10");
			pchar.questTemp.Caleuche.Bandos = "seek";
		break;
		
		case "caleuche_3":
			string sTime;
			if (GetQuestPastDayParam("questTemp.Caleuche.belizbandos") == 0) sTime = "����� ��� ���";
			if (GetQuestPastDayParam("questTemp.Caleuche.belizbandos") == 1) sTime = "�����������";
			if (GetQuestPastDayParam("questTemp.Caleuche.belizbandos") == 2) sTime = "������";
			dialog.text = "�� ��������, �������? ������������, � ����������� ������.";
			link.l1 = "� ����� ������ �� �� ������������� � ������. �� ���� ��� ������� ������, ��� �� ����� ��������� ������� �� �����, ������� ����� ������� � ����� ��������. ���� �������� �������� "+sTime+" ����� � ������, ��� �������� �� ������, ���� � �������� �� �������� ����� �����.";
			link.l1.go = "caleuche_4";
		break;
		
		case "caleuche_4":
			dialog.text = "� ������? �������� �����. � ���������� ����� ������ ����������� �� ��������� ������. ���� �� �� ��������, ��� ��� ������������ �� ������, � �� ������� ��������, � ���� ��������������� �� ��� ����� ������������ � �������.";
			link.l1 = "�������! � ������� � ��� ������ ����� ��� - ��� ��� �� ��� ����������.";
			link.l1.go = "caleuche_5";
		break;
		
		case "caleuche_5":
			dialog.text = "������. ��������.";
			link.l1 = "�� �������, ������.";
			link.l1.go = "caleuche_6";
		break;
		
		case "caleuche_6":
			DialogExit();
			AddQuestRecord("Caleuche", "15");
			pchar.questTemp.Caleuche.Bandos = "comendant";
			pchar.questTemp.Caleuche.BelizChance = drand(3);
			SetFunctionTimerCondition("Caleuche_BelizRegard", 0, 0, 3, false); // ������
		break;
		
		case "caleuche_7":
			if (sti(pchar.questTemp.Caleuche.BelizChance) < 3)
			{
				dialog.text = "�� �������� ��������� ������ �����, ��-��-��! ������� ����� � ������ �������, ������ � ��������! �� �� ������ �� ���������� ����! ��� ���������� ������� �������������, �� ���� ���������� ��������� ����� � ������� ����� ������ ������.";
				link.l1 = "�������� �������, ������! ������ �������� ������ ����� ����� ��������.";
				link.l1.go = "caleuche_12";
			}
			else
			{
				dialog.text = "��. ��� ������� �������� ��� ���� � ������, � ����� ��� � �� ��������. ������� ��� ������ � ������. ������, ��� �� ��� �� �������� �� �����.";
				link.l1 = "���� ������! �� ����� ����! � ����� ������ ���� ������? ��� �� ���!";
				link.l1.go = "caleuche_8";
			}
		break;
		
		case "caleuche_8":
			dialog.text = "� ����� �� �������, � ��� � ��������. �� �������� � �������� �������...";
			link.l1 = "������!! �� �������� - ��-��-��! � �� �������!";
			link.l1.go = "caleuche_9";
		break;
		
		case "caleuche_9":
			dialog.text = "�� � �� ����� �����, ��� �� ������� - �������!";
			link.l1 = "� ������ - ������. �� �������� ����� �� ����������� �� ������!";
			link.l1.go = "caleuche_10";
		break;
		
		case "caleuche_10":
			AddQuestRecord("Caleuche", "16");
			dialog.text = "������, �� ������� ���� ��� ���, � �� ��������. � ���� �� ������ ��� � �������, � �...";
			link.l1 = "� �� ����� � ���� �������, ������. � �������� ����� ������. ��������.";
			link.l1.go = "caleuche_11";
		break;
		
		case "caleuche_11":
			DialogExit();
			DeleteAttribute(pchar, "questTemp.Caleuche.BelizChance");
			DeleteAttribute(pchar, "questTemp.Caleuche.BelizRegard");
		break;
		
		case "caleuche_12":
			dialog.text = "� ������� ����������� � ����� ���� � ����������� ��������. �� ������ ������ ��� ����� � ����������� ���� ������ ��� �������: �������� ������ � ��������� �����. �������� ��������!";
			link.l1 = "�������!";
			link.l1.go = "caleuche_13";
		break;
		
		case "caleuche_13":
			Log_Info("�� �������� ������ � ���������");
			Log_Info("�� �������� ����������");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Caleuche", "17");
			GiveItem2Character(pchar, "chest"); 
			GiveItem2Character(pchar, "Mushket_8"); 
			dialog.text = "��������� �� ������, �������! ���� �� ��� �������� ���� ������ �� ��������������� � �������������, ��� ��, �� �� ��� ����� ���������� ������������. ����� �������!";
			link.l1 = "�� ��������, ������. ����� � ����� ������!";
			link.l1.go = "caleuche_11";
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			ChangeCharacterComplexReputation(pchar, "fame", 3);
			OfficersReaction("good");
			ChangeCharacterNationReputation(pchar, ENGLAND, 8);
			AddCharacterExpToSkill(pchar, "Leadership", 300);//���������
			AddCharacterExpToSkill(pchar, "Fortune", 200);//�������
			AddCharacterExpToSkill(pchar, "Sneak", 200);//����������
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
