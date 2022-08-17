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
			dialog.text = "Приветствую, капитан " + Pchar.name + " " + Pchar.lastname + ". Нужны мои услуги?";
			if(CheckCharacterItem(PChar, "RandomChest"))  
			{
				link.l1 = "Да.";
				link.l1.go = "Unlock";
			}
			
			if(PChar.FindAndDestroy == "6")
			{
				link.l2 = "Послушай, у меня к тебе дело необычного порядка. Вот, посмотри внимательно на этот ключ. Что ты можешь о нём сказать?";
				link.l2.go = "FindAndDestroy_1";
			}
			
			link.l3 = "Зашёл тебя проведать. Извини, мне надо идти.";
			link.l3.go = "exit_q";
			
			NextDiag.TempNode = "First time";
		break;


		case "armourer":
			dialog.text = "В жопу Сэр.";
			link.l1 = "Прошу прощения, не понял" + GetSexPhrase("","а") + "?";
			link.l1.go = "1";
		                        DoQuestCheckDelay("PrisonEscort_begin", 3.0);                                                                        
                                                                        
		break;


		case "1":
			dialog.text = "Я оружейных дел мастер. Работаю только с оружием. Но если хорошо заплатят, будет время и желание творить - возьмусь за любую кузнечную работу.";
			link.l1 = "Ты не очень то и приветлив?";
			link.l1.go = "armourer_2_1";
		break;

		case "armourer_2_1":
			dialog.text = "А куда деваться, мой помощник куда-то запропастился, просто слов нет. Вы меня уж простите, я думал это он зашёл.";
			link.l1 = "А, теперь понятно, так значит ты оружейник?";
			link.l1.go = "armourer_2";
		break;

		case "armourer_2":
			dialog.text = "Да, черт возми, могу из любой ржавой кочерги сделать неплохую саблю. Правда, это будет стоить порядочно.";
			link.l1 = "Я бы не отказал" + GetSexPhrase("ся","ась") + " от услуг хорошего оружейника.";
			link.l1.go = "armourer_3";
		break;

		case "armourer_3":
			dialog.text = "Вынужден тебя огорчить. Сейчас я загружен работой по уши и не беру новые заказы. Да ещё и мой помощник куда-то запропастился. Обещал доделать заготовки и наточить сабли, а сам...чёртова молодёжь. Не хватало ещё, чтобы он влез в какую-нибудь авантюру.";
			link.l1 = "Исла-Тесоро не самое безопасное место для неокрепших умов. Как его имя?";
			link.l1.go = "armourer_4";
		break;
		
		case "armourer_4":
			dialog.text = "Его зовут Джек. С ним работа шла бы гораздо быстрее. Но он лентяй! День работает, три дня отдыхает. Когда его покойный дядя отдавал мне его в ученики, он велел с ним быть построже и не давать ему расслабляться. Но я советом пренебрёг... и теперь пожинаю плоды. А из него бы мог получиться неплохой оружейник...";
			link.l1 = "Учиться никогда не поздно! Твоя задача научить его как надо, а как не надо он сам научится.";
			link.l1.go = "armourer_5";
		break;

		case "armourer_5":
			dialog.text = "Уговорами у меня не получается.";
			link.l1 = "Если не помогает пряник, то обязательно должен помочь кнут! Как можно гулять, если вокруг столько неотложной работы?";
			link.l1.go = "armourer_6";
		break;
		
		case "armourer_6":
			dialog.text = "Ты прав" + GetSexPhrase("","а") + "! Я должен последовать совету его дяди и сделать из Джека настоящего мастера-оружейника!";
			link.l1 = "Для начала хорошо бы его найти.";
			link.l1.go = "armourer_7";
		break;

		case "armourer_7":
			dialog.text = "Я сейчас весь в работе. А ты как вижу " + GetSexPhrase("человек","девченка") + " " + GetSexPhrase("неплохой","непромах") + ", тебе можно доверять. Если хочешь, займись этим, а позже поговорим за твой заказ. Что скажешь?";
			link.l1 = "Я не пртив, Джека твоего найду и приведу его сюда.";
			link.l1.go = "armourer_7_1";
		break;

		case "armourer_7_1":
			dialog.text = "Отлично! Постараюсь к его приходу подготовить кнут.";
			link.l1 = "...";
			link.l1.go = "armourer_7_1_q";
		break;

		case "armourer_7_1_q":
			NextDiag.CurrentNode = "armourer_7_1_r";
			AddQuestRecord("armourer_quest", "1");
			DoQuestCheckDelay("armourer_Jack_1", 0);
			pchar.questTemp.armourer = "Jack_1";
			DialogExit();	
		break;

		case "armourer_7_1_r":
			dialog.text = "Наш" + GetSexPhrase("ёл","ла") + " Джека?";
			link.l1 = "Ещё нет.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "armourer_7_1_r";
		break;

		case "armourer_7_2":
			dialog.text = "Что ж, тогда приходите позже. Нет времени у меня заняться вами.";
			link.l1 = "До встречи.";
			link.l1.go = "armourer_7_2_q";
		break;

		case "armourer_7_2_q":
			NextDiag.CurrentNode = "armourer_7_2_r";
			AddQuestRecord("armourer_quest", "3");
			CloseQuestHeader("armourer_quest");
			DoQuestCheckDelay("armourer_wait_start", 0);
			DialogExit();	
		break;
		
		case "armourer_7_2_r":
			dialog.text = "Приветствую, капитан " + Pchar.name + " " + Pchar.lastname + "!";
			link.l1 = "И вам полного здравия.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "armourer_7_1_r";
		break;

		case "Jack":
			dialog.text = "Эта комната не готова принимать гостей.";
			link.l1 = "Разве ты не должен сейчас ковать оружие?";
			link.l1.go = "Jack_1";
		break;
		
		case "Jack_1":
			dialog.text = "О, чёрт! Я бы с радостью, если бы не этот ворчливый трактирщик. Понимаешь, я решил показать, что тут не хуже всех...и вот к чему всё это привело.";
			link.l1 = "Голова на плечах для того чтобы думать, а ты что ей делаешь?";
			link.l1.go = "Jack_2";
		break;
		
		case "Jack_2":
			dialog.text = "Не надо занудных лекций! Я всё понимаю и каждый день себя мысленно ругаю. Сегодня я понял, что каждый должен дорожить тем местом, которое предоставляет ему судьба...Быть рабом трактирщика - это не для меня, я уже выдохся работая тут, а ведь я только начал, конечно ковать оружие дело хорошее, но мне больше нравится ковать замки и делать ключи к замочкам и вообще я по натуре вор.";
			link.l1 = "М-да...";
			link.l1.go = "Jack_3";
		break;
		
		case "Jack_3":
			dialog.text = "Слушай, вытащи меня отсюда. Я отблагодарю и обещаю, что буду бороться со своей ленью.";
			link.l1 = "Посмотрим.";
			link.l1.go = "Jack_3_q";
		break;
		
		case "Jack_3_q":
			NextDiag.CurrentNode = "Jack_r";
			pchar.questTemp.armourer = "Jack_2";
			DialogExit();	
		break;
		
		case "Jack_r":
			dialog.text = "Чёрт побери! Жизнь проходит, а я работаю, лучше вороством промышлять.";
			link.l1 = "Видно, плохо работаешь.";
			link.l1.go = "exit_q";
			NextDiag.TempNode = "Jack_r";
		break;
		
		case "Jack_4":
			dialog.text = "Эй, как дела? То есть... я свободен?";
			link.l1 = "Тебе сегодня повезло. Трактирщик отпустил тебя.";
			link.l1.go = "Jack_5";
		break;
		
		case "Jack_5":
			dialog.text = "Спасибо! Спасибо добр" + GetSexPhrase("ый","ая") + " " + GetSexPhrase("сеньор","барышня") + "! Вот! Тебе мой подарок одежда кокого-то корсара я нашёл здесь, под кроватью, видимо кто то сильно торопился что позабыл одеться, ха. Она ваша! Спасибо ещё раз!";
			link.l1 = "Нашёл...под кроватью?";
			link.l1.go = "Jack_5_q";
		break;
		
		case "Jack_5_q":
			NextDiag.CurrentNode = "Jack_r";
			AddQuestRecord("armourer_quest", "2");
			CloseQuestHeader("armourer_quest");
			GiveItem2Character(pchar, "suit9");
			DoQuestCheckDelay("armourer_Jack_3_1", 0);
			DialogExit();	
		break;
		
		case "Jack_work":
			dialog.text = "Ну и денёк! Ни минуты покоя нет в этой кузнице, надоели железки лучше замки и ключи делать!";
			link.l1 = "Как твои дела?";
			link.l1.go = "Jack_work_1";
		break;
		
		case "Jack_work_1":
			dialog.text = "В трудах! я добро помню " + GetSexPhrase("сеньор","барышня") + ", если понадобится моя помощь, обещаю, помогу.";
			link.l1 = "Благодарю, мой юнный друг и чем ты мне поможешь?";
			link.l1.go = "Jack_work_2";
		break;
		
		case "Jack_work_2":
			dialog.text = "Как сказать... но, вы понимаете я очень хорошо разбираюсь в замках?";
			link.l1 = "Ах, да, ты же по натуре вор!";
			link.l1.go = "Jack_work_21";
		break;

		case "Jack_work_21":
			dialog.text = "Ну не надо так громко?";
			link.l1 = "Ладно, удачи!";
			link.l1.go = "First time";
		break;

		case "armourer_7_1_1":
			dialog.text = "О, ещё раз здравствуйте! Мой бездельник вернулся, благодарю вас. Кстати, как ваше имя?";
			link.l1 = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+".";
			link.l1.go = "armourer_7_1_2";
		break;
		
		case "armourer_7_1_2":
			dialog.text = "Вы капитан?";
			link.l1 = "Да, капитан судна '" + pchar.ship.name + "'.";
			link.l1.go = "armourer_7_2_2";
		break;
				
		case "armourer_7_2_2":
			dialog.text = "Я уже всё знаю. Чёртов юнец! Я знал, что он доиграется! Но ничего, ничего! Через три дня у меня с ним будет особый разговор.";
			link.l1 = "Теперь ты займёшься моим заказом?";
			link.l1.go = "armourer_7_2_3";
		break;


		case "armourer_7_2_3":
			dialog.text = "Почему бы и нет! как и договоривались.";
			link.l1 = "Здорово!";
			link.l1.go = "armourer_7_2_4";
		break;

		case "armourer_7_2_4":
			dialog.text = "Могу посоветовать именно для тебя, уникальный клинок.";
			link.l1 = "Что за клинок!";
			link.l1.go = "armourer_7_2_5";
		break;

		case "armourer_7_2_5":
			dialog.text = "Клинок японских самураев, ты о них когда нибуть слышал" + GetSexPhrase("","а") + ".";
			link.l1 = "Ну, немного наслышан" + GetSexPhrase("","а") + "!";
			link.l1.go = "armourer_7_2_6";
		break;

		case "armourer_7_2_6":
			dialog.text = "Ну и как тебе моё предложение.";
			link.l1 = "Звучит заманчего, мне нравится, и что для этого требуется!";
			link.l1.go = "armourer_7_2_7";
		break;

		case "armourer_7_2_7":
			dialog.text = "Ах, какой хват, хват делового человека, ты мне нравишся, а требуется не много, доставить не много железа, а за работу с тебя денег не возму.";
			link.l1 = "И сколько тебе надо железа!";
			link.l1.go = "armourer_7_2_8";
		break;

		case "armourer_7_2_8":
			dialog.text = "300 футов.";
			link.l1 = "Ого, не многовато!";
			link.l1.go = "armourer_7_2_9";
		break;

		case "armourer_7_2_9":
			dialog.text = "Пойми правильно, здесь железо в этой акватории долеко не лучшего качества, слишком много примисей, и чтобы изготовить достойный клинок необходимо много железа.";
			link.l1 = "Понятно!";
			link.l1.go = "armourer_7_3_0";
		break;

		case "armourer_7_3_0":
			dialog.text = "Так, как, заказ оформлять будем?";
			link.l1 = "Годится. Я принимаю условия. Железо привезу!";
			link.l1.go = "armourer_start";
			link.l2 = "Пожалуй, откажусь!";
			link.l2.go = "exit_q";
		break;

		case "armourer_start":
			dialog.text = "Ладно капитан, я пошутил, я не местный каробел?";
			link.l1 = "Фу, я то думал" + GetSexPhrase("","а") + " вы серьёзно!";
			link.l1.go = "armourer_7_3_1";
		break;

		case "armourer_7_3_1":
			dialog.text = "Ты же Джека привел" + GetSexPhrase("","а") + ", я добро помню, выбирай легкого или среднего веса клинок?";
			link.l1 = "легкого!";
			link.l1.go = "armourer_7_3_2";
			link.l2 = "среднего!";
			link.l2.go = "armourer_7_3_3";
		break;

		case "armourer_7_3_2":
			dialog.text = "Держи?";
			link.l1 = "Спасибочки, век не забуду!";
			link.l1.go = "Exit";
			GiveItem2Character(pchar, "blade37");
		break;

		case "armourer_7_3_3":
			dialog.text = "Держи?";
			link.l1 = "Спасибочки, век не забуду!";
			link.l1.go = "Exit";
			GiveItem2Character(pchar, "blade39");
		break;










		//-----------------------------------------------------------------------------------------
		// НАЙТИ И УНИЧТОЖИТЬ -->
		//-----------------------------------------------------------------------------------------
		case "FindAndDestroy_1":	
			dialog.text = "...(что-то бормочет)... М-м... Длинное лезвие... Два продолговатых зубца... Четыре треугольника... Два трапецевидных отверстия... Хм, очень интересный, а главное редкий ключ в наших краях.";
			link.l1 = "От чего он, может быть, не знаешь?";
			link.l1.go = "FindAndDestroy_2";
		break;
		
		case "FindAndDestroy_2":	
			dialog.text = "Знаю, как не знать. Этот ключ отпирает замки на старинных сундуках, которые использовались на рудниках много лет назад.";
			link.l1 = "Уверен в этом?";
			link.l1.go = "FindAndDestroy_3";
		break;
		
		case "FindAndDestroy_3":	
			dialog.text = "Я всегда безошибочно определяю принадлежность ключа, капитан. Правда сейчас, в наше время, этот ключ бесполезен. На рудниках сейчас новые сундуки с усовершенствованной защитой и новыми ключами. А вашим старым ключом можно только на заброшенных шахтах орудовать.";
			link.l1 = "Заброшенные рудники! Точно! Слушай, а ты не знаешь, где на Карибском Архипелаге есть такие рудники?";
			link.l1.go = "FindAndDestroy_4";
		break;
		
		case "FindAndDestroy_4":	
			dialog.text = "М-м... Есть один заброшенный рудник. Кажется, на Гваделупе.";
			link.l1 = "Спасибо тебе! Что я могу сделать для тебя за оказанную помощь?";
			link.l1.go = "FindAndDestroy_5";
		break;
		
		case "FindAndDestroy_5":	
			dialog.text = "Разве что отдать мне этот ключ, когда он станет, бесполезен для тебя...";
			link.l1 = "Отлично. Обязательно отдам тебе его, но не сейчас. Я спешу, прощай.";
			link.l1.go = "exit_q";
			AddDialogExitQuestFunction("FindAndDestroyFindMines");
		break;
		//-----------------------------------------------------------------------------------------
		// НАЙТИ И УНИЧТОЖИТЬ <--
		//-----------------------------------------------------------------------------------------


		case "armourer_amulet":	
			dialog.text = "О какие люди, проходи, чем могу быть полезен.";
			link.l1 = "Приветствую тебя, ты прав я по делу. Ты ведь не только мастер по оружию?";
			link.l1.go = "armourer_amulet_1";
		break;		
		case "armourer_amulet_1":	
			dialog.text = "Не толко!";
			link.l1 = "Очень хорошо, у меня для тебя есть заказ, мне нужен амулет?";
			link.l1.go = "armourer_amulet_2";
		break;		
		case "armourer_amulet_2":	
			dialog.text = "Так ты не по адрессу, амулеты можешь заказать на маяках, у них там всё поставленно на широкую ногу.";
			link.l1 = "Да нет, мне нужно изготовить амулет, вот из этих материалов?";
			link.l1.go = "armourer_amulet_3";
		break;		
		case "armourer_amulet_3":	
			dialog.text = "Тогда другое дело, надо посмотреть.";
			link.l1 = "Вот держи?";
			link.l1.go = "armourer_amulet_4";
		break;
		case "armourer_amulet_4":
	                                               TakeNItems(PChar, "MoonStone", -1);
	                                               TakeNItems(PChar, "DisappearPeople_Coin", -1);	
			dialog.text = "Проблем не вижу, сделаем.";
			link.l1 = "Когда придти за заказом и сколько будет стоить?";
			link.l1.go = "armourer_amulet_5";
		break;
		case "armourer_amulet_5":	
			dialog.text = "Приходи через дней десять, там и поговорим об оплате.";
			link.l1 = "Хорошо, до встречи.";
			link.l1.go = "Exit";
	                                                SetTimerFunction("armourer_amulet_1", 0, 0, 10);
		break;

		case "armourer_amulet_6":	
			dialog.text = "А вот и вы, ваш заказ готов, с тебя 4000 песо.";
			link.l1 = "Без проблем.";
			if (sti(pchar.money) >= 4000) link.l1.go = "amulet_1";
			else link.l1.go = "armourer_amulet_7";
		break;

		case "armourer_amulet_7":
			dialog.text = "Гм... Но где же деньги? " + GetSexPhrase("Молодой человек","Молодая девочка") + ", у вас своеобразное чувство юмора, которое я не понимаю.";
			link.l1 = "Простите. Я, видимо, забыл" + GetSexPhrase("","а") + " деньги в корабельном рундуке. Сейчас вернусь и принесу.";
			link.l1.go = "exit";
			NextDiag.TempNode = "armourer_amulet_repeat";		
		break;
		
		case "armourer_amulet_repeat":
			dialog.text = "Вы принесли деньги, " + PChar.name + "?";
			if (sti(pchar.money) >= 4000)
			{
				link.l1 = "Конечно! Надеюсь, эта сумма с лихвой покроет все издержки.";
				link.l1.go = "amulet_1";
			}
			else
			{
				link.l1 = "Пока еще нет...";
				link.l1.go = "exit";
				NextDiag.TempNode = "armourer_amulet_repeat";
			}		
		break;
		
		case "amulet_1":
			AddMoneyToCharacter(pchar, -4000);
			dialog.text = "Замечательно! " + PChar.name + "!";
			link.l1 = "Прекрасная работа?";
			link.l1.go = "armourer_amulet_8";			
		break;

		case "armourer_amulet_8":
	                                               TakeNItems(PChar, "ArtRing5", 1);	
			dialog.text = "Обращайтесь ещё?";
			link.l1 = "Неприменно";
			link.l1.go = "Exit";
	                                                sld = characterFromId("Myxir");//ноду Миксеру 
	                                                sld.dialog.currentnode = "Myxir_100";
		break;



		case "exit_q":
			DialogExit();
		break;

 		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;		

 


	}
}