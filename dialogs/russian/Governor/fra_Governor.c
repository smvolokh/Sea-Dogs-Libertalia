// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
	switch (Dialog.CurrentNode)
	{
		case "quests":
            dialog.text = RandPhraseSimple("����� �������?", "��� ��� ������?");
			link.l1 = RandPhraseSimple("� ���������...", "������ ��� �� � ��� ��������");
		    link.l1.go = "exit";
		break;
		
		//******************** ����������� ������� ***************************
		case "work_1":  // ������ �� ����� ������ - ������� �����
			if (CheckAttribute(npchar, "notQuestLine"))
			{
                dialog.text = "� ���������, � �� ���� ������������ ��� ������. �� �� ��� �������, ���� � ����� �� �������� ���� ����. �� ��������.";
                link.l1 = "��� ��� ��...";
                link.l1.go = "exit";
				break;
			}            
		break;		 		            
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}
