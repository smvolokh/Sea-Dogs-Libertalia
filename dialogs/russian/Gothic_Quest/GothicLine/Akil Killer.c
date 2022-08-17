// Киллеры
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
			dialog.text = "Что вам надо?";
			link.l1 = "Ничего.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

//*************************** Aльварес **********************************
		
		case "1":
			dialog.text = "Aльварес: Ну что, Акил, долги принято отдавать. Мы дали тебе последний срок, до сегодняшнего дня и сейчас ждём своих денег.";
			link.l1 = "Акил: Я не смог принёсти их сюда, Aльварес, я...";
			link.l1.go = "2";
		break;
		
		case "2":
			dialog.text = "Aльварес: Что?! Акил, мы разве не предупреждали тебя, а?";
			link.l1 = "Акил: Но я же не такой дурак, чтобы привезти сюда, на Исла-Тесоро, тристо штук. Да здесь все готовы глотки друг другу перерезать за пару тысяч! А что бы они сделали со мной за две недели, пока я ждал вас, если бы узнали, что у меня с собой четверть миллиона.";
			link.l1.go = "3";
		break;
		
		case "3":
			dialog.text = "Aльварес: Значит, деньги ты нам не принёс, Акил?";
			link.l1 = "Акил: Я спрятал их на Эспаньоле. Вот карта. Вам остаётся лишь отправиться туда и забрать их.";
			link.l1.go = "4";
		break;
		
		case "4":
			dialog.text = "Aльварес: Акил, мы тебе говорили, не принесёшь деньги сюда и тебе конец!";
			link.l1 = "Акил: Нет! Не убивай меня, Aльварес, я же объяснил, почему я их сюда не привёз.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "Aльварес: Нас это не интересует. Мы сказали тебе, чтобы сегодня деньги были здесь. Вместо этого ты посылаешь нас на Эспаньолу в какое-то подземелье. Нет, Акил, мы хорошо знаем тебя, чтобы поверить, что ты действительно спрятал там деньги.";
			link.l1 = "Акил: Нет! Нет, Aльварес, не убивай меня! Нет, прошу...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Akil");
		break;

		case "5_1":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_15_00.wav");
			dialog.text = "";
			link.l1 = "Мне не нужны проблемы!";
			link.l1.go = "5_2";
		break;

		case "5_2":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_11_01.wav");
			dialog.text = "А мы как раз ищем проблемы, мы проделали долгий путь, что бы найти их.";
			link.l1 = "";
			link.l1.go = "5_3";
		break;

		case "5_3":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_AERGER_11_02.wav");
			dialog.text = "Да мы собираемся создать целую кучу проблем и начну я с тебя если ты сейчас же не свалишь от сюда.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Akil_1");
		break;


		case "5_4":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_HAUAB_11_00.wav");
			dialog.text = "Что бы не привело тебя сюда, тебе лучше забыть об этом и убраться по дальше.";
			link.l1 = "";
			link.l1.go = "5_5";
		break;

		case "5_5":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_15_00.wav");
			dialog.text = "";
			link.l1 = "Кто вы такие парни, пара клоунов...";
			link.l1.go = "5_6";
		break;

		case "5_6":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_11_01.wav");
			dialog.text = "Ты правильно понял и я буду продолжать смеяться когда твой труп будет лежать в дорожной пыли.";
			link.l1 = "";
			link.l1.go = "5_7";
		break;

		case "5_7":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_15_00.wav");
			dialog.text = "";
			link.l1 = "Вы парни сейчас исчезните от сюда - всё понятно?";
			link.l1.go = "5_8";
		break;

		case "5_8":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_01.wav");
			dialog.text = "Смотри - ка, новый герой нарисовался и очень глупый герой.";
			link.l1 = "";
			link.l1.go = "5_9";
		break;

		case "5_9":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_02.wav");
			dialog.text = "Ты знаешь о чём я думаю!";
			link.l1 = "";
			link.l1.go = "5_10";
		break;

		case "5_10":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_15_03.wav");
			dialog.text = "";
			link.l1 = "Да кому какое дело о чём ты думаешь...";
			link.l1.go = "5_11";
		break;

		case "5_11":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_WITZ_11_04.wav");
			dialog.text = "Я думаю, что хороший герой - это мертвый герой, так, что сделай мне одолжение - умри поскорее.";
			link.l1 = "";
			link.l1.go = "5_12";
		break;

		case "5_12":
 	PlaySound("VOICE\Russian\gotica\ALVARES\DIA_ALVARES_ATTACK_KERLE_11_02.wav");
			dialog.text = "Энгардо, давай начинать, ты берёшь на себя фермера а я разбирусь с этим клоуном.";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryAkilKill");
		break;


//*************************** Энгардо **********************************

		case "6_1":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_00.wav");
			dialog.text = "Эй мужик, ты, что заблудился? Возвращайся на своё поле и дёргай репу.";
			link.l1 = "";
			link.l1.go = "6_2";
		break;

		case "6_2":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_01.wav");
			dialog.text = "Ты оказался не в том месте, не в то время.";
			link.l1 = "";
			link.l1.go = "6_3";
		break;

		case "6_3":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_02.wav");
			dialog.text = "Так, что если хочешь жить лучше топай от сюда - понял!!!";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Alvares");
		break;

		case "6_4":
 	PlaySound("VOICE\Russian\gotica\ENGARDO\DIA_ENGARDO_HALLO_13_03.wav");
			dialog.text = "У тебя, что со слухом не всё в порядке или тебе очень хочется умереть. Ладно всё равно уже слишком поздно...";
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogKillers_Alvares_1");
		break;


		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
