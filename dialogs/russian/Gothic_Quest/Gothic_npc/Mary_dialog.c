

void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
	case "First time":
            	dialog.text = "" + PChar.name + ", на помощь, спаси мен€...!";
        	link.l1 = "";
        	link.l1.go = "GothicTorus_fake";
		break;

		case "GothicTorus_fake":
	                   PlaySound("VOICE\Russian\gotica\HELP_woman\SVM_17_HELP.wav");
			dialog.text = "ѕќћќ√»“≈, на помощь, спасите мен€...!";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_1";
		break;

		case "GothicTorus_fake_1":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\HEYTURNAROUND02.wav");
			dialog.text = "";
			link.l1 = "Ёй ты -  ”„≈–я¬џ…, оставь девочку в покое?";
			link.l1.go = "GothicTorus_fake_exit";
		break;
		
		 case "GothicTorus_fake_exit":
			AddDialogExitQuest("GothicTorus_fake_4_win1_Mary");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "GothicTorus_fake_night":
	                   PlaySound("VOICE\Russian\Kapper05.wav");
			dialog.text = "ѕоменьше суй свой нос в чужие дела - целее будешь. ’а-ха-ха.";
			link.l1 = "";
			link.l1.go = "GothicTorus_fake_night_1";
		break;

		case "GothicTorus_fake_night_1":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_40.wav");
			dialog.text = "";
			link.l1 = "—читай, что тебе повезло если € оставлю теб€ в живых - подонок!";
			link.l1.go = "GothicTorus_fake_night_exit";
		break;
		
                                       case "GothicTorus_fake_night_exit":
		                   AddDialogExitQuest("GothicTorus_fake_4_win1_Mary4");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}





