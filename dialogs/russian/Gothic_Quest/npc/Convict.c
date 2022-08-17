// ������ ����������� � �����
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	bool bOk;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = NPCStringReactionRepeat("������, ����� ����� ��� ��� �����, ���� �� �� ����� � ���� �������������. ���� ����� ������, � ��� �������� ����.", "� ��� ��� ��� ������, ������. ��� �� ������, ����� � ��-�� ��� ������� ������?", "� ��� �� ������...", "�����-�� ����-���, �����-�� �����...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("������� ��� � ��� �������...", "���, �� ����, �������.", "�� ��!", "��...", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
			
		case "CitizenNotBlade":
			dialog.text = "�������, ��� �� ��������! ������� ������, ���� ��� �� ��������!";
			link.l1 = LinkRandPhrase("������.", "�����.", "�� ���������, ��� ������...");
			link.l1.go = "exit";
		break;  
	}
}
