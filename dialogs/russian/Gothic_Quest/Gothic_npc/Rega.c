Рега крестьянка на ферме Секоба
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
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела?";
		link.l1.go = "Rega_1";
		break;

		case "Rega_1":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_01.wav");
		dialog.text = "Ты из города, да...";
		link.l1 = "...";
		link.l1.go = "Rega_2";
		break;

		case "Rega_2":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_05.wav");
		dialog.text = "На твоём месте я бы убиралась от сюда побыстрее.";
		link.l1 = "...";
		link.l1.go = "Rega_3";
		break;

		case "Rega_3":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_08.wav");
		dialog.text = "Но в последнее время жизнь здесь стала просто невыносимо.";
		link.l1 = "...";
		link.l1.go = "Rega_4";
		break;

		case "Rega_4":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_HALLO_17_09.wav");
		dialog.text = "Бандиты по всюду, полевые хищники уничтожают наш урожай, а ленд Лорд совсем озверел.";
		link.l1 = "...";
		link.l1.go = "Rega_5";
		break;

		case "Rega_5":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты боишся ленд Лорда!";
		link.l1.go = "Rega_6";
		break;

		case "Rega_6":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_17_01.wav");
		dialog.text = "Конечно, если ленд Лорду кто-то не понравится, он посылает своих наёмников и больше этого человека никто не видет.";
		link.l1 = "...";
		link.l1.go = "Rega_7";
		break;

		case "Rega_7":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_ONAR_17_02.wav");
		dialog.text = "Так что, мы предпочитаем помалкивать.";
		link.l1 = "...";
		link.l1.go = "Rega_8";
		break;

		case "Rega_8":
	                     PlaySound("VOICE\Russian\gotica\REGA\DIA_REGA_PERMKAP1_15_00.wav");
		dialog.text = "...";
		link.l1 = "Выше нос...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";
		break;
















		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
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
