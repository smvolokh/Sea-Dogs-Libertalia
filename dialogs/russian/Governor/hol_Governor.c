// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    int i, tempQty, chComp, iShip, iBaseType;
    string tempStr;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			//����������
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad") && pchar.location == "villemstad_townhall")
			{
				dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
				link.l1 = "� ����, ��� ����������� ����-������� �������� �������� ��������� ������� ���� �� ������ ������ ������, � ������ - ���������� �����������. ��� ������� �������� ���. ������ �� ��������� � ����� ����� ������� � � ����� ������ ��� �������.";
				link.l1.go = "Portugal";
				break;
			}
            dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������");
		    link.l1.go = "exit";
		break;
		
		case "work_1":  // ������ �� ����� ������ - ������� �����
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "� ���������, � �� ���� ������������ ��� ������. �� �� ��� �������, ���� � ����� �� �������� ���� ����. �� ��������.";
                link.l1 = "��� ��� ��...";
                link.l1.go = "exit";
				break;
			}                   
		break;
		
		//����������
		case "Portugal":
			dialog.text = "���� ����������?! �� � ���? �����?";
			link.l1 = "� � �����, ��� ������� �� ��� �� �����. �����. � ��� �������� ��������� ������ ������, ���� ������, ����� �� ����� �� ����� ���!";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "�����������! ������ �� �� ���������... ������, ������������� ����������� �������� � ��������� �� �����. �� ���������� ������� ������� ����� � ����� ������ �����.";
			link.l1 = "� �� ����� ������� �������� ������ ���� �������, ������... ���� �� �� ����������.";
			link.l1.go = "Portugal_2";
		break;
		
		case "Portugal_2":
			dialog.text = "������, �� ������ �� ����������� - ������� �� ��������. �� ������ ���������� ����������� �� ���������� ������� - ������� ������ ������� ��������. ���������! �������� ��������� �������� ��� ��������������!";
			link.l1 = "��... ������, ����� ������ ��� � ���� ������� ��������... �����, ������� - ������, �������.";
			link.l1.go = "Portugal_3";
		break;
		
		case "Portugal_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("�� �������� 1500 ��������");
			PlaySound("interface\important_item.wav");
			dialog.text = "� ������ ������ ��� �������, �������, �������� �������� �����������. ��� ������ �� �������� ������ � ��� ������.";
			link.l1 = "�������, ������. ����������� ����� � ��������� � ����� �������.";
			link.l1.go = "Portugal_4";
		break;
		
		case "Portugal_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
