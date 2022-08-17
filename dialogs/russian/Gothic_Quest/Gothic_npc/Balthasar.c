Бальтазар пастух на ферме Секоба
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
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела?";
		link.l1.go = "Balthasar_1";
		break;

		case "Balthasar_1":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_01.wav");
		dialog.text = "А, новое лицо на ферме, неужеле этот старый скряга наконец подарил мне ученика.";
		link.l1 = "...";
		link.l1.go = "Balthasar_2";
		break;

		case "Balthasar_2":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "Я не ученик...";
		link.l1.go = "Balthasar_3";
		break;

		case "Balthasar_3":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_03.wav");
		dialog.text = "А, понятно, но я ведь уже не так молод, как раньше, понимаешь, и я уже много лет жду себе замену.";
		link.l1 = "...";
		link.l1.go = "Balthasar_4";
		break;

		case "Balthasar_4":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_HALLO_05_04.wav");
		dialog.text = "Ты же здесь не потому, что тебя послали разгневанные соседи, правда!";
		link.l1 = "...";
		link.l1.go = "Balthasar_5";
		break;

		case "Balthasar_5":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_15_00.wav");
		dialog.text = "...";
		link.l1 = "А, что за проблемы с соседями?";
		link.l1.go = "Balthasar_6";
		break;

		case "Balthasar_6":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_01.wav");
		dialog.text = "Трава в этой части большого поля чахлое и подухлое и поэтому я часто пасу овец на других пастбищах других ферм.";
		link.l1 = "...";
		link.l1.go = "Balthasar_7";
		break;

		case "Balthasar_7":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_02.wav");
		dialog.text = "Ленд Лорд не возражает, но Бенгард фермер владеющий высокогорными пастбищами каждый раз орёт как резанный когда видет моих овец там.";
		link.l1 = "...";
		link.l1.go = "Balthasar_8";
		break;

		case "Balthasar_8":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_03.wav");
		dialog.text = "Он говорит, что Секоб должен платить если хочет пасти овец на его пастбищах.";
		link.l1 = "...";
		link.l1.go = "Balthasar_9";
		break;

		case "Balthasar_9":
	                     PlaySound("VOICE\Russian\gotica\BALTHASAR\DIA_BALTHASAR_AERGERMITNACHBARN_05_04.wav");
		dialog.text = "Но Секоб скорее удавится чем потратит хоть цент на это, поэтому я больше не хожу на плато.";
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
