// Чарли большая пиписька
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
 	                                   PlaySound("VOICE\Russian\citizen\Indeyci-05.wav");
			dialog.text = "Когда - то это всё было нашим, а потом приходили вы?";
			link.l1 = "Ну и что!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "1":
 	                                   PlaySound("VOICE\Russian\citizen\Indeyci-08.wav");
			dialog.text = "Слушаем тебя? Назови ключевой фраз.";
			Link.l1.edit = 1;
			Link.l1 = "";
			Link.l1.go = "2";
			NextDiag.TempNode = "1";
		break;
		
		case "2":
			string sString = GetStrSmallRegister(dialogEditStrings[1]);
			if(sString == "вот и славно, вот и хорошо" || sString == "вот и славно вот и хорошо")
			{
				AddMoneyToCharacter(PChar, 25000);
				dialog.text = "Вот твоя деньга.";
				link.l1 = "Слушай, Чарли, я и мои люди недовольны своим куском пирога, они хотят большего. Мне нужно увидеть Акила, чтобы потребовать с него больше денег. Где его найти?";
				link.l1.go = "3";
			}
			else
			{
				dialog.text = "Ключевой фраз неверно. Чарли больше не иметь дело с " + GetSexPhrase("Белый Брат","Белай Сестра") + ".";
				link.l1 = "Аргх!..";
				link.l1.go = "exit";
				AddDialogExitQuestFunction("GothicLine_DeliveryDialogWithCharlyFailed");
			}
		break;
		
		case "3":
			dialog.text = "Чарли не знать, где есть Акил. Чарли только отдать деньга. Чарли ничего больше не делать.";
			link.l1 = "Чарли, тебе ведь не нужны неприятности? Не нужны? Ответь мне, где Акил, и у тебя их не будет.";
			link.l1.go = "4";
		break;
		
		case "4":
			dialog.text = "Чарли не вкуривать, о чём говорить " + GetSexPhrase("Белый Брат","Белай Сестра") + ". Чарли не понимать.";
			link.l1 = "Всё ты вкуриваешь. Повторю ещё раз. Не говоришь, где Акил - есть неприятности, Чарли плохо. Говоришь, где Акил - нет неприятностей, Чарли хорошо.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "Чарли ничего не знать, Чарли только делать свою делу, отдавать деньга.";
			link.l1 = "Значит неприятности, Чарли. Хорошо, я устрою тебе...";
			link.l1.go = "6";
		break;
		
		case "6":
			dialog.text = "Нет! Нет! Чарли сказать, Чарли сказать! Акиля искать в острове Исла - Тесоро, в острове Исла - Тесоро, Акиля там, Чарли точно знать.";
			link.l1 = "Спасибо.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "" + GetSexPhrase("Белый Брат","Белай Сестра") + "! Не надо говорить Акиль, что Чарли тут вам сказать, не надо выдавать Чарли, Чарли просто не хотеть плохо.";
			link.l1 = "Хорошо, не скажу.";
			link.l1.go = "8";
		break;
		
		case "8":
			dialog.text = "Чарли не виноват, Чарли не хотеть плохо. Ты не выдать Чарли?";
			link.l1 = "Не выдам. Всё, отвали от меня.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithCharlyGood");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
