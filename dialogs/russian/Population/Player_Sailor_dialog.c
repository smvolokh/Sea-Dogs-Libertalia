void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	ref PChar = GetMainCharacter();
	string sName = PChar.name + " " + PChar.lastname; 
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "��� �� ������?";
			link.l1 = "������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Sailor":
			dialog.text = "������ ���, �������!";
			link.l1 = "�������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Sailor";
		break;

		case "Canoneer":
			dialog.text = "������ ���, �������!";
			link.l1 = "�������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Canoneer";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
