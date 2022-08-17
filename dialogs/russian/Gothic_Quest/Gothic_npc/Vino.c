// Вино работник на ферме Лобарта
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

		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_15_00.wav");
		dialog.text = "...";
		link.l1 = "Есть какие - нибудь интересные новости?";
		link.l1.go = "First time1";
		break;

		case "First time1":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_05_01.wav");
		dialog.text = "Я могу поклясться, что видел Орка, вон там, на краю леса, два дня назад.";
		link.l1 = "...";
		link.l1.go = "First time2";
		break;

		case "First time2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_PERM_05_02.wav");
		dialog.text = "С тех пор я сплю, хотя бы с одним открытым глазом.";
		link.l1 = "...";
		link.l1.go = "exit";

		break;

		case "Vino_hallo":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как идёт работа?";
		link.l1.go = "Vino_hallo_1";			
		break;

		case "Vino_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_05_01.wav");
		dialog.text = "Так же как и всегда, работы много, денег мало, а если нам совсем не повезёт то завтра придут Орки и сожгут нашу ферму до тла.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_2";			
		break;

		case "Vino_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_HALLO_05_02.wav");
		dialog.text = "Королевские паладины заняли весь город, но я очень сомневаюсь в том, что они поднимут свои задницы и придут сюда если Орки нападут на нас.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_3";			
		break;

		case "Vino_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_00.wav");
		dialog.text = "...";
		link.l1 = "Могу я чем - нибудь помочь, я ищу работу.";
		link.l1.go = "Vino_hallo_4";			
		break;

		case "Vino_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_01.wav");
		dialog.text = "А, ты вообще, что - нибудь знаешь о полевых работах!";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_5";			
		break;

		case "Vino_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_02.wav");
		dialog.text = "...";
		link.l1 = "А, что там такого знать - то.";
		link.l1.go = "Vino_hallo_6";			
		break;

		case "Vino_hallo_6":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_03.wav");
		dialog.text = "Аа, в таком случае мы и сами справимся, спасибо.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_7";			
		break;

		case "Vino_hallo_7":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_04.wav");
		dialog.text = "Но если ты хочешь работать на Лобарта в качестве подённого рабочего, я могу только предупредить тебя он платит людям в роде тебя сущие гроши.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_8";			
		break;

		case "Vino_hallo_8":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_15_05.wav");
		dialog.text = "...";
		link.l1 = "Он предложил купить у него чистую одежду дешевле, если я буду помогать на ферме.";
		link.l1.go = "Vino_hallo_9";			
		break;

		case "Vino_hallo_9":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_06.wav");
		dialog.text = "Хм, у меня нет для тебя никакой работы, но ты можешь принести мне и парням, что - нибудь выпить.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_10";			
		break;

		case "Vino_hallo_10":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_07.wav");
		dialog.text = "Принеси мне бутылку вина и я скажу Лобарту, что ты очень помог нам.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_exit";			
		break;

		case "Vino_hallo_11":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_SEEKWORK_05_08.wav");
		dialog.text = "Но ты не слышал этого от меня, понятно.";
		link.l1 = "...";
		link.l1.go = "Vino_hallo_exit";			
		break;

		case "Vino_hallo_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicVino_seekwork");
		break;

		case "Vino_bringwine":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Вот твоё вино.";
		link.l1.go = "Vino_bringwine_1";			
		break;

		case "Vino_bringwine_1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "Grog", -1);
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_05_01.wav");
		dialog.text = "Я пожалуй не буду спрашивать где ты взял его хорошо, кого это волнует...";
		link.l1 = "...";
		link.l1.go = "Vino_bringwine_2";			
		break;

		case "Vino_bringwine_2":
	                     PlaySound("VOICE\Russian\gotica\VINO\DIA_VINO_BRINGWINE_05_03.wav");
		dialog.text = "Лобарт услышит только хорошее о тебе.";
		link.l1 = "...";
		link.l1.go = "exit";
                                         pchar.questTemp.GothicVino = "Vino.Fail";			
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
				dialog.text = NPCharSexPhrase(NPChar, "Осторожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции	

	}
}
