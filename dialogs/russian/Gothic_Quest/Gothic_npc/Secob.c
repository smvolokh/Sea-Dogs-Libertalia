//Секоб фермер
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
	                     PlaySound("VOICE\Russian\gotica\SEKOB\DIA_SEKOB_HALLO_01_00.wav");
		dialog.text = "Что ты делаешь на моей земле, здесь нечего украсть, проваливай.";
		link.l1 = "...";
		link.l1.go = "Secob_1";
		break;

		case "Secob_1":
	                     PlaySound("VOICE\Russian\gotica\SEKOB\DIA_SEKOB_HALLO_15_01.wav");
		dialog.text = "...";
		link.l1 = "Неужеле в этой проклятой стране нет ни кусочка земли которой никому не пренадлежит.";
		link.l1.go = "Secob_2";
		break;

		case "Secob_2":
	                     PlaySound("VOICE\Russian\gotica\SEKOB\DIA_SEKOB_HALLO_01_02.wav");
		dialog.text = "А ты займись делом, тогда возможно когда-нибудь и ты сможешь называть кусок земли своей собственностью. Но до той поры, будь добр, бей баклуши где-нибудь в другом месте.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";
		break;
















		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Что ты там копаешься, а? Да ты вор!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой!", "По сундукам шарить вздумал?! Тебе это даром не пройдет!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "Woman_FackYou":
			dialog.text = "Ах, вот, значит, как?! По сундукам шарить вздумал?! Тебе это даром не пройдет!";
			link.l1 = "Вот дура!..";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//замечание по обнаженному оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Слушай, ты бы убрал оружие. А то нервируешь немного...", "Знаешь, у нас тут не принято сабелькой размахивать. Убери оружие.", "Слушай, что ты, как д'Артаньян, бегаешь тут, шпагой машешь? Убери оружие, не к лицу это серьезному мужчине...");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажешь...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
				link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "Острожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции	

	}
}
