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
			dialog.text = "Что вы хотели?";
			link.l1 = "Ничего.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "shipowner":
	                                PlaySound("VOICE\Russian\GOTHIC\SAILOR\SAILOR_" + rand(58) + ".wav");
		PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			dialog.text = "Не мешайте работать, капитан! По всем вопросам обратитесь к мастеру Скипу.";
			link.l1 = "Понял, извини что отвлек.";
			link.l1.go = "exit";
			NextDiag.TempNode = "shipowner";
		break;


		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
