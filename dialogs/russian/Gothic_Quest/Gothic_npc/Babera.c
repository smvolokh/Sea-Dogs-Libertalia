Бабера крестьянка на ферме Секоба
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
	                     PlaySound("VOICE\Russian\gotica\BABERA\DIA_BABERA_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Привет красавица.";
		link.l1.go = "Babera_1";
		break;

		case "Babera_1":
	                     PlaySound("VOICE\Russian\gotica\BABERA\DIA_BABERA_HALLO_16_01.wav");
		dialog.text = "Хватит клеиться ко мне, скажи сразу что тебе нужно, я занята.";
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
