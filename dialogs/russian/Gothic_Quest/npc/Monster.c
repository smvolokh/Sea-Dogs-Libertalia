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
		case "First time_skel":

		if(CheckAttribute(pchar, "questTemp.GothicAztec") && pchar.questTemp.GothicAztec == "AztecShamanDuh_revers" && !CheckAttribute(npchar, "quest.AztecShamanDuh_revers"))
            {
            	                   dialog.text = "";
        		link.l1 = "...";
        		link.l1.go = "Duh1_revers_3";
            }

		if(CheckAttribute(pchar, "questTemp.GothicAztec") && pchar.questTemp.GothicAztec == "AztecShamanDuh2_revers2" && !CheckAttribute(npchar, "quest.AztecShamanDuh2_revers2"))
            {
            	                   dialog.text = "";
        		link.l1 = "...";
        		link.l1.go = "Duh2_revers_3";
            }

		if(CheckAttribute(pchar, "questTemp.GothicAztec") && pchar.questTemp.GothicAztec == "AztecShamanDuh3_revers3" && !CheckAttribute(npchar, "quest.AztecShamanDuh3_revers3"))
            {
            	                   dialog.text = "";
        		link.l1 = "...";
        		link.l1.go = "Duh3_revers_3";
            }

		if(CheckAttribute(pchar, "questTemp.GothicAztec") && pchar.questTemp.GothicAztec == "AztecShamanDuh4_revers4" && !CheckAttribute(npchar, "quest.AztecShamanDuh4_revers4"))
            {
            	                   dialog.text = "";
        		link.l1 = "...";
        		link.l1.go = "Duh4_revers_4";
            }


	                                                PlaySound("VOICE\Russian\gotica\SFX\SLE_AMBIENT02.wav");
			dialog.text = "Про-хо-ди... Мы знаем те-бя...";
			link.l1 = "";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time_SKEL";
		break;

		case "First time_ZOMBIE":
	                                      PlaySound("VOICE\Russian\gotica\SFX\ZOMBIE_01.wav");
			dialog.text = "Зачем ты меня пробудил...";
			link.l1 = "Не твоё дело...";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time_ZOMBIE";
		break;

		case "First time_MONKEY":
	                                                PlaySound("VOICE\Russian\gotica\SFX\MONKEY.wav");
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time_MONKEY";
		break;

		case "First time_ORC":
	                                                PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT05.wav");
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time_ORC";

		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;





	}
}
