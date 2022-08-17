void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{

		case "Florido_Mo":
			dialog.text = "Вход в таверну платный, плати и проходи - козявка!";
			link.l1 = "Платный вход, да ты в своем уме!";
			link.l1.go = "Florido_Mo_1";
		break;

		case "Florido_Mo_1":
			dialog.text = "А как ты хочеш, этот город образцово-показательный здесь нам нищие не нужны так что плати в размере 100 пиастров и можешь пройти.";
			link.l1 = "Ну ладно, возьмите.";
			link.l1.go = "quest3_2_1";
			link.l2 = "Да я не посмотрю что ты такой амбал, накостыляю моло не покажется и платить я ничего не буду!";
			link.l2.go = "quest3_2_2";
		break;

		case "quest3_2_1":
			dialog.text = "Отлично, теперь, проходи.";
			link.l1 = "";
			link.l1.go = "quest3_2_1_end";
		break;

		case "quest3_2_1_end":
			AddMoneyToCharacter(pchar, -100);
			LAi_Fade("MiniQuest_Mo_end", "");
			CloseQuestHeader("MiniQuest_Mo"); 			
			DialogExit();
		break;

		case "quest3_2_2":
			dialog.text = "Хамить изволите судар" + GetSexPhrase("ь","иня") + " сейчас ты у меня по другому запоешь.";
			link.l1 = "";
			link.l1.go = "quest3_2_2_next";
		break;

		case "quest3_2_2_next":
			NextDiag.CurrentNode = "quest3_2_2_1";
			DoQuestCheckDelay("MiniQuest_Mo_1", 0);
			DialogExit();
		break;

		case "quest3_2_2_1":
			dialog.text = "Погоди! Не убивай меня! Я совершил ошибку! Только не убивай меня, я больше так не буду, пожалейте ради бога и маленьких деток!";
			link.l1 = "Чёрт с тобой, не хочу об тебя руки марать, но только чтоб я тебя больше не видел" + GetSexPhrase("","а") + ". Проваливай покуда цел, козявка!";
			link.l1.go = "quest3_2_2_5_1";
                AddDialogExitQuestFunction("UneasyDeliveryStart");
		break;

		case "quest3_2_2_5_1":
			dialog.text = "Спасибо тебе! Обещаю, ты меня больше не увидишь!";
			link.l1 = "";
			link.l1.go = "quest3_2_2_5_end";
                                               
		break;

		case "quest3_2_2_5_end":
			DoQuestCheckDelay("MiniQuest_Mo_20_1", 0);			
			DialogExit();
		break;




		
	}
}