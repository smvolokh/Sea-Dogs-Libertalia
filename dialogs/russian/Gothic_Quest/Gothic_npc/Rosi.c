//Рози, жена Секоба фермера
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
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "У тебя всё в порядке!";
		link.l1.go = "First time_2";
		break;

		case "First time_2":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_HALLO_17_01.wav");
		dialog.text = "Ну, боле менее, моя спина болит от постоянной тяжёлой работы, а что ты делаешь здесь, у нас не часто бывают гости.";
		link.l1 = "...";
		link.l1.go = "First time_3";
		break;

		case "First time_3":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_WAREZ_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что ты можешь предложить мне.";
		link.l1.go = "Rosi_Trade";
		break;

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "Rosi_Trade":
	                     PlaySound("VOICE\Russian\gotica\ROSI\DIA_ROSI_WAREZ_17_01.wav");
		dialog.text = "Выбирай.";
		link.l1 = "...";
		link.l1.go = "Rosi_Trade_exit";
		break;

		case "Rosi_Trade_exit":
		if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 5)
		{
		GiveItemToTrader(npchar);
		SaveCurrentNpcQuestDateParam(npchar, "trade_date");
		}
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LaunchItemsTrade(npchar, 0);
		break;




















//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках		
		case "Woman_FackYou":
	                     PlaySound("VOICE\Russian\gotica\HILDA\DIA_HILDA_PFANNETOOLATE_17_07.wav");
		dialog.text = "Прочь с глаз моих, грязный вор!";
		link.l1 = "Вот дура!";
		link.l1.go = "exit_setOwner";
		LAi_group_Attack(NPChar, Pchar);
		break;

		case "fight":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		LAi_group_Attack(NPChar, Pchar);
		if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
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
		dialog.text = NPCharSexPhrase(NPChar, "Осторожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
		link.l1 = RandPhraseSimple("Понял.", "Убираю.");
		}
		link.l1.go = "exit";
		NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции	

	}
}
