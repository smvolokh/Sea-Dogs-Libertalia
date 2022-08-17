// Марианна
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
            	dialog.text = "Добрый день, мис" + GetSexPhrase("ье","сис") + ".";
        	link.l1 = "Приветствую.";
        	link.l1.go = "1";
		break;

		case "1":
            	dialog.text = "Приветствую вас. Мое имя "+ GetFullName(NPchar)+". Я "+NPCharSexPhrase(NPChar,"житель","жительница")+" этого прекрасного города Ле Француа, хотя он и пиратский, и все же прекрасный .";
        	        	link.l1 = "Разрази меня гром! , Тысяча чертей! , Чтоб тебе пусто было! Да я капитан "+ GetFullName(Pchar)+ " каналья?, и сам" + GetSexPhrase("ый","ая") + " известн" + GetSexPhrase("ый","ая") + " пират" + GetSexPhrase("","ка") + " в этих водах!. Можешь называть меня капитан "+ GetFullName(Pchar)+", рад" + GetSexPhrase("","а") + " знакомству .";
        	link.l1.go = "2";
		break;


		case "2":
            	dialog.text = "Мне тоже очень и очень приятно! Скажите, капитан " + PChar.name + ", что вы здесь делаете? Я, признаться, вижу вас здесь впервые.";
        	link.l1 = "Да так, хожу, брожу а тут такое, просто невероятно в джунглях и такой город, интересно на какие ши-ши он построен?";
        	link.l1.go = "3";
		break;

		case "3":
            	dialog.text = "Мне капитан это не интересно, даже все ровно на какие ши-ши он построен, главное здесь чисто, красиво и прекрасно.";
        	link.l1 = "М-да, понимаю, мне тут тоже нравится, тогда скажи можно ли прикупить здесь жилье, квадрат или крышу над головой?";
        	link.l1.go = "4";
		break;

		case "4":
            	dialog.text = "Можно, но этим вопросом занимается лично глова города, командор Фрэнсис де Левинжуа .";
        	link.l1 = "Понятно, еще что нибуть можешь расказать об этом городишке, какие байки в ходу в здешней таверне, что новенького в этих краях, как течет жизнь на суше?";
        	link.l1.go = "5";
		break;

		case "5":
            	dialog.text = "Жизнь как жизнь хоть за хрен держись, на счет баек не знаю а вот Мо возле таверны народ пугает, будте осторожны с этим типом!";
        	link.l1 = "Благодарствую за информацию сударыня, вы мне очень помогли!";
        	link.l1.go = "6";
		break;



		case "6":
            	dialog.text = "За спрос денег не берут!";
        	link.l1 = "Ну это как сказать, как сказать, я пожалуй пойду. Поговорим как-нибудь в другой раз.";
        	link.l1.go = "7";
		break;

		case "7":
            	dialog.text = "A что берут!";
        	link.l1 = "Берут еще как берут. Ну все не скучай.";
        	link.l1.go = "7 End";
		break;

 		case "7 End":
                NextDiag.CurrentNode = "Fifth time";
		DialogExit();
		break;

	case "Fifth time":
            	dialog.text = "Здравствуйте, капитан " + PChar.name + "! Как дела?";
        	link.l1 = "Пока не родила. Простите, но я спешу.";
        	link.l1.go = "8";
		break;

		case "8":
            	dialog.text = "Конечно, конечно не смею вас задерживать.";
        	link.l1 = "";
        	link.l1.go = "7 End";
		break;

/// ******************** Марион Тульен *************************
	case "Mary Toulien":
            	dialog.text = "Простите моего мужа, мосье Блейк. Он совсем не свой после уроков этого колдуна!";
        	link.l1 = "Вы имеете в виду Кристофера Бейна? Недавно приехавшего в город учёного? Об этом я и хотел поговорить.";
        	link.l1.go = "Mary Toulien to Paul";
				NextDiag.TempNode = "Mary Toulien 1";			
		break;	
	 	case "Mary Toulien to Paul":
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			DoQuestCheckDelay("HumWeapPE PaulToulien dlgNow", 1.0);
		break;	
	case "Mary Toulien 1":
            	dialog.text = "Вот и я о чём ему говорю, мосье Блейк. Но он совсем меня не слушает! Чёртов дурак, ну и влип же ты, теперь и родную старуху не признаёшь!";
        	link.l1 = "Поль, что с тобой сделал этот человек? Что он тебе давал? Это... какой-то препарат? Он заставлял тебя пить или что?";
        	link.l1.go = "Mary Toulien to Paul";
				NextDiag.TempNode = "8";			
		break;			



	}
}

