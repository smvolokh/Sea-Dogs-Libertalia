void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
		case "First time":
			
			dialog.text = "������ �������� ����� �������.";
			if(CheckAttribute(CharacterRef, "Dialog.Filename"))
			{
				dialog.text = "�� ������� ������� ���� ������� " + CharacterRef.Dialog.Filename + ", ����������� ����� ���������.";
			}
			link.l1 = "ok";
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
