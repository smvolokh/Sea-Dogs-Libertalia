#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ProcessCommonDialogRumors(NPChar, Link, NextDiag);//homo 25/06/06

	switch(Dialog.CurrentNode)
	{
		case "First time":
			// --> калеуче
			if (CheckAttribute(pchar, "questTemp.Caleuche.SeekAmulet") && drand(1) == 0 && sti(Pchar.money) >= 2000) 
			{
				dialog.text = "Послушайте, господин, не желаете приобрести одну занятную вещицу? Недорого возьму, всего каких-то пару тысяч песо...";
				link.l1 = "Хм. Небось, стащил эту 'вещицу', а теперь пытаешься мне сбагрить?";
				link.l1.go = "caleuche";
				break;
			}
			// <-- калеуче
			if (npchar.quest.meeting == "0")
			{
				dialog.text = LinkRandPhrase("Здравствуйте. Меня зовут " + GetFullName(npchar) + ". Не думаю, что вам было бы приятно со мной познакомиться, но, возможно, вы запомните мое имя...", 
					"Приветствую вас, " + GetAddress_Form(NPChar) +  ". Меня зовут " + GetFullName(npchar) + ".", 
					"Мое имя - " + GetFullName(npchar) + ", " + GetAddress_Form(NPChar) + ". Рад с вами познакомиться.");
				link.l1 = RandPhraseSimple("Приветствую.", "Здравствуйте.");
				link.l1.go = "First time";
				// карибские нравы
				if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy_drink" && pchar.location == "portobello_town")
				{
					link.l2 = "Послушай, не хочешь ли вместо жалкой милостыни заработать пару-тройку тысяч песо, а?";
					link.l2.go = "trial";
				}
				npchar.quest.meeting = "1";
			}			
			else
			{
				dialog.text = NPCStringReactionRepeat("Эх, вот видишь, до чего докатился...", 
					"Жить подаянием непросто...", 
					"Хотелось бы мне вырваться из нищеты!",
					"Опять ты?..", "block", 1, npchar, Dialog.CurrentNode);

				link.l1 = HeroStringReactionRepeat("Вижу. Ну, ничего страшного.", 
					"Оно и понятно. На эти деньги не разгуляешься, поди...",
					"Тогда тебе нужно не протирать здесь штаны, а что-то делать для этого.", 
					"Ага. Неужели "+ GetSexPhrase("надоел","надоела") +"?", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("exit", "exit", "exit", "pester", npchar, Dialog.CurrentNode);
				link.l2 = RandPhraseSimple("Что тебе нужно?", "Чего ты хочешь?");
				link.l2.go = "Whants";
				// карибские нравы
				if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy_drink" && pchar.location == "portobello_town")
				{
					link.l2 = "Послушай, не хочешь ли вместо жалкой милостыни заработать пару-тройку тысяч песо, а?";
					link.l2.go = "trial";
				}
				link.l3 = LinkRandPhrase("Что-нибудь интересное мне расскажешь?", 
					"Что нового в городе?", "Эх, с удовольствием "+ GetSexPhrase("послушал","послушала") +" бы последние сплетни...");
				link.l3.go = "rumours_poor";

				// --------------- линейка ГПК ---------------
				if (pchar.questTemp.LSCC == "SignOnPoorMurder" || pchar.questTemp.LSCC == "PoorIsGood")
				{
						link.l4 = "Знаешь, у меня к тебе есть один вопрос. Очень странный, на первый взгляд...";
						link.l4.go = "GoodTalk_1"; 
				}

				//нашел письмо в сундуке Виллемстада
				if (pchar.questTemp.LSCC == "CanFoundStuvesantKey" && !CheckAttribute(npchar, "quest.CanFoundStuvesantKey"))
				{
					link.l5 = "Послушай, мне кажется, что я "+ GetSexPhrase("нашел","нашла") +" в резиденции Бека нечто весьма интересное!";
					link.l5.go = "FoundLetter";
				}

				//базар о том, что нашел причину заказа на нищих
				if (pchar.questTemp.LSCC == "readyGoLSCC" && !CheckAttribute(npchar, "quest.readyGoLSCC"))
				{
					link.l5 = "Ты знаешь, мне удалось распутать этот клубок!";
					link.l5.go = "GoLSCC";
				}

			}
			NextDiag.TempNode = "First time";
		break;

		case "pester":
			dialog.text = RandPhraseSimple("Да нет, почему сразу "+ GetSexPhrase("надоел","надоела") +"? Я не особо занят, как ты "+ GetSexPhrase("сам","сама") +" видишь...", 
				"Не "+ GetSexPhrase("надоел","надоела") +", но порядком "+ GetSexPhrase("утомил","утомила") +". Я хоть и нищий, но тоже человек.");
			link.l1 = "Хех, ясно...";
			link.l1.go = "exit";
		break;
		//выходы
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//милостыня
		case "Whants":
			if (!CheckAttribute(npchar, "wants_date") || GetNpcQuestPastDayParam(npchar, "wants_date") >= 1 || bBettaTestMode)
    		{
				dialog.text = PCharRepPhrase("Хм, " + GetAddress_Form(NPChar) +  ", о вас ходят нехорошие слухи. Но я верю в людей, даже в таких, как вы. Я прошу дать мне денег на еду и питье, сжальтесь.",
					"Прошу вас, " + GetAddress_Form(NPChar) +  "! Не обойдите вниманием несчастного человека, подайте на пропитание...");
				link.l1 = RandPhraseSimple("Ничего тебе не дам.", "Обойдешься.");
				link.l1.go = "exit";
				Link.l2 = "Хорошо. И сколько тебе нужно денег?";
				Link.l2.go = "Whants_1";
			}
			else
			{
				dialog.text = PCharRepPhrase("От тебя? Ничего.", "Ничего не нужно, " + GetAddress_Form(NPChar) + ", спасибо.");
				link.l1 = RandPhraseSimple("Хм, ну ладно.", "Знать хорошо живется тебе, приятель.");
				link.l1.go = "exit";
			}
		break;
		case "Whants_1":
			dialog.text = "И от гроша ломаного не откажусь, " + GetAddress_Form(NPChar) + ". Сколько вам позволят ваши кошелек и милосердие...";
			Link.l1.edit = 2;			
			link.l1 = "";
			link.l1.go = "Whants_2";
		break;
		case "Whants_2":
			SaveCurrentNpcQuestDateParam(npchar, "wants_date");
			int iTemp = sti(dialogEditStrings[2]);
			if (iTemp <= 0 || sti(pchar.money) < iTemp)
			{
				dialog.text = "Грешно смеяться надо больными людьми...";
				link.l1 = "Ха-ха-ха, а ты что думал, юродивый, я тебе денег дам?!";
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", -2);
				break;
			}
			if (iTemp > 0 && iTemp <= 100)
			{
				dialog.text = "Спасибо за " + FindRussianMoneyString(iTemp) + ", " + GetAddress_Form(NPChar) + ". Я куплю хлеба на эти деньги...";
				link.l1 = "Давай, иди подкрепись, бродяга.";
				link.l1.go = "exit";
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 100 && iTemp <= 500)
			{
				dialog.text = "Спасибо вам, " + GetAddress_Form(NPChar) + ". Этих денег мне хватит на неделю!";
				link.l1 = ""+ GetSexPhrase("Рад был","Рада была") +" помочь.";
				link.l1.go = "exit";
				OfficersReaction("good");
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 500 && iTemp <= 1000)
			{
				dialog.text = "Благодарю вас, " + GetAddress_Form(NPChar) + ". Я всем расскажу о вашей доброте!";
				link.l1 = "Ну, это не обязательно...";
				link.l1.go = "exit";
				ChangeCharacterComplexReputation(pchar,"nobility", sti(iTemp/2000+0.5));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 1000 && iTemp <= 5000)
			{
				dialog.text = "Спасибо вам, досточтим"+ GetSexPhrase("ый","ая") +" " + GetAddress_Form(NPChar) + ". Да хранит вас Господь...";
				link.l1 = "Да, покровительство Господа мне не помешает уж точно!";
				link.l1.go = "exit";
				ChangeCharacterNationReputation(pchar, sti(NPChar.nation), sti(iTemp/10000+0.5));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 5000 && iTemp <= 10000)
			{
				dialog.text = "Спасибо вам, "+ GetSexPhrase("досточтимый","досточтимая") +" " + GetAddress_Form(NPChar) + ". Желаю вам удачи!";
				link.l1 = "Спасибо, приятель.";
				link.l1.go = "exit";
				AddCharacterExpToSkill(pchar, "Leadership", sti(iTemp/5000));
				AddCharacterExpToSkill(pchar, "Fortune", sti(iTemp/5000));
				pchar.money = sti(pchar.money) - iTemp;
			}
			if (iTemp > 10000)
			{
				dialog.text = "Послушайте, " + GetAddress_Form(NPChar) + ", вы в своем уме? Вы отдаете мне " + FindRussianMoneyString(iTemp) + "! Я не возьму такие деньги, чувствую, здесь какой-то подвох... Уходите!";
				link.l1 = "Ну, как знаешь...";
				link.l1.go = "exit";
			}
		break;
		
		case "trial":
			dialog.text = "Спрашиваете, сеньор! Конечно, хочу. А что для этого надо будет сделать? Вы же не просто так дадите мне деньги.";
			link.l1 = "Конечно, не просто так. Слушай внимательно. Я выполняю поручение самого губернатора. Его светлость считает, что кто-то на верфи намеренно задерживает выход его галеона, 'Алакантары', из доков. Особенно его подозрения укрепились после недавней поимки французского шпиона...";
			link.l1.go = "trial_1";
		break;
		
		case "trial_1":
			dialog.text = "";
			link.l1 = "Объяснения корабела его светлость уже слышал, однако сомневается в их достоверности. Нужно узнать, кто и почему саботирует работу. Отправляйся в доки, походи, поспрашивай у рабочих - какого черта 'Алакантара' до сих пор не готова к выходу в море...";
			link.l1.go = "trial_2";
		break;
		
		case "trial_2":
			dialog.text = "";
			link.l1 = "Тебя никто ни в чем не заподозрит, может, еще и табачком разживешься, а мне точно никто ничего не скажет - сразу поймут, на кого я работаю. Если узнаешь что-нибудь достойное внимания - получишь три тысячи песо. Месяц на свою 'работу' сможешь не выходить.";
			link.l1.go = "trial_3";
		break;
		
		case "trial_3":
			dialog.text = "Три тысячи песо? Досточтимый господин...";
			link.l1 = "Ты что, торгуешься? Если узнаешь имя того, по чьей вине работяги тянут кота за хвост - получишь еще две тысячи. Понял?";
			link.l1.go = "trial_4";
		break;
		
		case "trial_4":
			dialog.text = "Хорошо, сеньор. Задача, чай, не сложная - у меня есть старинные знакомые, которые стучат топорами на нашей верфи. Эх, а ведь когда-то я тоже был моряком. Вот помню, с десяток лет назад...";
			link.l1 = "Расскажешь свою историю потом. Встречаемся сегодня вечером после одиннадцати на пирсе. Теперь ступай.";
			link.l1.go = "trial_5";
		break;
		
		case "trial_5":
			chrDisableReloadToLocation = true;//закрыть локацию
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload5_back", "none", "", "", "OpenTheDoors", 10.0);
			LAi_RemoveLoginTime(npchar);
			pchar.questTemp.Trial = "spy_poorman";
			pchar.quest.trial_spy_poorman.win_condition.l1 = "Timer";
			pchar.quest.trial_spy_poorman.win_condition.l1.date.hour  = 23.00;
			pchar.quest.trial_spy_poorman.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.trial_spy_poorman.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.trial_spy_poorman.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.trial_spy_poorman.function = "Trial_SetPoormanInPort";
			SetTimerCondition("Trial_ReturnPoormanNorm", 0, 0, 1, false);
			AddQuestRecord("Trial", "15");
		break;
		
		case "trial_6":
			dialog.text = "Добрый вечер, господин...";
			link.l1 = "Ну как, узнал что-нибудь?";
			link.l1.go = "trial_7";
		break;
		
		case "trial_7":
			dialog.text = "Узнал, сеньор, узнал. Правда, не совсем понимаю, как это вяжется с вашими словами... Вы деньги принесли? Пять тысяч песо?";
			if (sti(pchar.money) >= 5000)
			{
				link.l1 = "Не переживай. Вот твои монеты. Рассказывай.";
				link.l1.go = "trial_8";
			}
			else
			{
				link.l1 = "Сначала информация, потом деньги. Давай, не тяни время!";
				link.l1.go = "trial_fail";
			}
		break;
		
		case "trial_fail":
			dialog.text = "Вы пытаетесь меня надуть, сеньор! Не хотите платить деньги - узнавайте все сами. И даже не смейте хвататься за свою железяку - стражу позову!";
			link.l1 = "...";
			link.l1.go = "trial_fail_1";
		break;
		
		case "trial_fail_1":
			chrDisableReloadToLocation = true;//закрыть локацию
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 10.0);
			pchar.questTemp.Trial = "spy_fail";
			AddQuestRecord("Trial", "16");
			sld = characterFromId("Florian");
			sld.DeckDialogNode = "florian_failspy_5";
		break;
		
		case "trial_8":
			AddMoneyToCharacter(pchar, -5000);
			dialog.text = "Дело обстоит так. 'Алакантара' к выходу в море уже давно готова, но ее намеренно не ставят под погрузку, причем по приказу самого губернатора. Ну, это мне так сказали. А плотники сейчас делают всякую мелкую работу, которая на выход судна в море никак не влияет\nВсе ждут прихода какого-то каравеллы-латины из Картахены. Дело в том, что на 'Алакантаре' недостаточный, по мнению капитана, запас пороха. Вот и ждут, пока 'Нинья' привезет порох для 'Алакантары'\nНо всем это ожидание уже порядком надоело, так что если 'Нинья' не прибудет через три дня - 'Алакантара' отправится в путь и так...";
			link.l1 = "Да ну? И кто же тебе такое сказал? Имя?";
			link.l1.go = "trial_9";
		break;
		
		case "trial_9":
			dialog.text = "Да один из матросов 'Алакантары', Фелипе Дабиньо... Но никто из этого секрета не делал, да и сам господин губернатор приказал...";
			link.l1 = "Все ясно. Этого я и ожидал. Распустили языки, как бабы базарные! В городе орудуют французские шпионы, а каждый встречный-поперечный может узнать обо всех планах его светлости! Ох, и получит же этот Фелипе Дабиньо! И боцман 'Алакантары', за то, что распустил дисциплину на судне!";
			link.l1.go = "trial_10";
		break;
		
		case "trial_10":
			dialog.text = "А?.. Так вы что, все знали? Но зачем тогда?.. Я ни в чем не виноват! Вы сами попросили меня!";
			link.l1 = "Да ты-то можешь не переживать. Теперь мы знаем, что экипаж 'Алакантары' способен выболтать врагу любую информацию, даже секретную! Все, ты можешь идти. Благодарю за помощь! Ступай, трать свои деньги.";
			link.l1.go = "trial_11";
		break;
		
		case "trial_11":
			chrDisableReloadToLocation = true;//закрыть локацию
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload4_back", "none", "", "", "OpenTheDoors", 10.0);
			pchar.questTemp.Trial = "spy_win";
			AddQuestRecord("Trial", "17");
			sld = characterFromId("Florian");
			sld.DeckDialogNode = "florian_12";
		break;
		
		// --> калеуче
		case "Caleuche":
			dialog.text = "Помилуйте, добрый господин... Я ее выиграл намедни в кости у какого-то проезжего, думал - заговоренный целебный амулет, да прогадал: и хвори она не исцеляет, и рыночным барышникам неинтересна. А вот вы - моряк, капитан, человек ученый - глядишь, вам она и пригодилась бы\nДа для вас эти пара тысяч - сущий пустяк, а мне - кусок хлеба и глоток рому на месяц. Взгляните, господин...";
			link.l1 = "Ладно, показывай...";
			link.l1.go = "Caleuche_1";
		break;
		
		case "Caleuche_1":
			Log_Info("Вы получили странный амулет");
			PlaySound("interface\important_item.wav");
			dialog.text = "Вот...";
			link.l1 = "Так-так... Занятная вещица, согласен. Явно вывезена из индейских поселений. Хорошо, я забираю ее. Вот твоё серебро.";
			link.l1.go = "Caleuche_2";
		break;
		
		case "Caleuche_2":
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = "Спасибо, милостивый господин! Надеюсь, эта вещь принесет вам удачу! Да хранит вас Господь!";
			link.l1 = "И тебе счастливо, приятель. Не спусти только все деньги за один раз в кабаке.";
			link.l1.go = "Caleuche_3";
		break;
		
		case "Caleuche_3":
			DialogExit();
			GiveItem2Character(pchar, "kaleuche_amulet1"); 
		break;
		// <-- калеуче


		//линейка ГПК, разговоры по душам с нищими после заказа

		case "GoodTalk_1":
			dialog.text = "К-хе, к-хе... Чего?!!";
			link.l1 = "Ну-у-у, как тебе сказать... В общем, есть тут люди, которым вы как кость в горле.";
			link.l1.go = "GoodTalk_1_1";
		break;
		case "GoodTalk_1_1":
			dialog.text = "Я даже не знаю, что и сказать... "+ GetSexPhrase("Сам","Сама") +", наверное, понимаешь, что мы люди бездомные, отношение к нам пренебрежительное.";
			link.l1 = "Настолько, чтобы желать вашей смерти?";
			link.l1.go = "GoodTalk_1_2";
		break;
		case "GoodTalk_1_2":
			dialog.text = "Смерти?! Не-е-ет, это вряд ли. Послушай, что за странные речи ты ведешь? Меня это пугает.";
			link.l1 = "Хех, и правильно делает, что пугает. В общем, ты не знаешь, кто могут быть ваши доброжелатели, я так понимаю.";
			link.l1.go = "GoodTalk_1_3";
		break;
		case "GoodTalk_1_3":
			dialog.text = "Не знаю, конечно! Ты же с ними "+ GetSexPhrase("общался","общалась") +".";
			link.l1 = ""+ GetSexPhrase("Общался","Общалась") +" я через представителя, так сказать. Меня интересует, кто за этим стоит... Ну ладно, будь осторожен, друг.";
			link.l1.go = "GoodTalk_1_4";
		break;
		case "GoodTalk_1_4":
			dialog.text = "Погоди немного.";
			link.l1 = "Да. Я слушаю тебя.";
			link.l1.go = "PoorHeadMan_1";
		break; 
		//основной бродяга
		case "PoorHeadMan_1":
			dialog.text = "Ну что же, это хорошо. Насколько я смог понять, ты пытаешься узнать о людях, которым мы здорово досадили. Причем настолько сильно, что они готовы нас убивать. Все правильно?";
			link.l1 = "Ну да. Добавлю только, что не убивать, а нанять убийцу.";
			link.l1.go = "PoorHeadMan_2";
		break;
		case "PoorHeadMan_2":
			dialog.text = "Хм, это существенный фактор... А как звали того человека, что говорил с тобой об этом?";
			link.l1 = "Оливер Траст.";
			link.l1.go = "PoorHeadMan_3";
		break;
		case "PoorHeadMan_3":
			dialog.text = "Это имя мне незнакомо... В общем, есть у меня одно соображение.";
			link.l1 = "Излагай.";
			link.l1.go = "PoorHeadMan_4";
		break;
		case "PoorHeadMan_4":
			dialog.text = "Была одна история в Виллемстаде, на Кюрасао, которая, по моему мнению, имеет некоторое сходство с тем, что произошло с тобой. В общем, у нас был один товарищ по несчастию, который решил обосноваться у голландцев, на Кюрасао. Звали его Тизер Дэн.\n"+
				"Так вот, прожил он там около месяца, а по прошествии этого времени попался на глаза губернатору Матиасу Беку. С тех пор начались у Тизера проблемы то с солдатами в городе, то с комендантом... В итоге выгнали его из Виллемстада, и больше о нем ничего не известно.";
			link.l1 = "Хм, и какое это отношение имеет к моему делу?";
			link.l1.go = "PoorHeadMan_5";
		break;
		case "PoorHeadMan_5":
			dialog.text = "Слушай дальше. Начали мы узнавать, что к чему с Тизером, куда он пропал, и выяснили кое-что о Беке. Об этом мало кто знает, но Бек - самый крупный поставщик рабов в Новый свет из Африки!\n"+
				"Он работает в тесном сотрудничестве с Голландской Вест-Индской компанией, и они такие дела крутят - закачаешься.";
			link.l1 = "Ну и что?";
			link.l1.go = "PoorHeadMan_6";
		break;
		case "PoorHeadMan_6":
			dialog.text = "А то, что почти все наши - бывшие рабы. Ты думаешь, мы бездельники и лентяи? Ничего подобного, просто по стечению обстоятельств нам довелось пройти через этот ад и потерять здоровье. Белым здесь часто дают свободу, так как нужны колонисты\n"+
				"Но далеко не каждый бывший раб может пахать землю и корчевать пни после месяцев, проведенных в трюме галеона по дороге сюда. А Матиас, судя по всему, очень не любит бывших рабов, которые так и не занялись ничем полезным.";
			link.l1 = "Хм, звучит все это несколько надуманно...";
			link.l1.go = "PoorHeadMan_7";
		break;
		case "PoorHeadMan_7":
			dialog.text = "Возможно, но это все, что я знаю и могу предположить. Других ненавистников нищих, столь же богатых и влиятельных, я не знаю. Так что если ты хочешь что-то узнать об этом деле, то, мне кажется, искать нужно в резиденции Виллемстада.";
			link.l1 = "И что я долж"+ GetSexPhrase("ен","на") +" там искать по твоему мнению?";
			link.l1.go = "PoorHeadMan_8";
		break;
		case "PoorHeadMan_8":
			dialog.text = "Бумаги, "+ GetSexPhrase("друг мой","миледи") +", деловую переписку. Все, что я тебе тут наговорил, действительно надумано. Мне кажется, что за предложением этого Траста стоит что-то гораздо более весомое, нежели обычная неприязнь кого бы то ни было.";
			link.l1 = "Хм, я тоже так думаю. Что-то здесь серьезное, учитывая размах замысла и сумму гонорара.";
			link.l1.go = "PoorHeadMan_9";
		break;
		case "PoorHeadMan_9":
			dialog.text = "Ну, я сказал все, что хотел. Спасибо за то, что "+ GetSexPhrase("выслушал","выслушала") +". Если найдешь что-нибудь стоящее внимания - сразу обращайся ко мне, будем думать... И спасибо за то, что не "+ GetSexPhrase("причинил","причинила") +" нам вреда.";
			link.l1 = "Да не за что. Тебе спасибо за информацию.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toVillemstadResidence";
			AddQuestRecord("ISS_PoorsMurder", "4");
			//сработает прерывание, чтобы показать геймеру, где нужный сундук
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1 = "locator";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.location = "Villemstad_TownhallRoom";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.locator_group = "box";
			pchar.quest.LSCC_enterStuvesantBox.win_condition.l1.locator = "private2";
			pchar.quest.LSCC_enterStuvesantBox.function = "LSCC_enterStuvesantBox";
		break;
		//базар с основным после нахождения письма
		case "FoundLetter":
			dialog.text = "Ну, давай, посмотрим, что там у тебя...";
			link.l1 = "Вот письмо, которое я раздобыл"+ GetSexPhrase("","а") +" в резиденции Бека. Это переписка между ним и Голландской Вест-Индской компанией. Из него явно следует, что затеяла уничтожение нищих именно данная торговая компания.";
			link.l1.go = "FoundLetter_1";
		break;
		case "FoundLetter_1":
			dialog.text = "Угу, вижу...";
			link.l1 = "Там какой-то остров упоминается. И предметы роскоши. И все это почему-то на бродягах зациклено. Расскажи-ка мне, приятель, в чем тут дело.";
			link.l1.go = "FoundLetter_2";
			TakeItemFromCharacter(pchar, "letter_LSCC");
		break;
		case "FoundLetter_2":
			dialog.text = "Хм, даже не знаю, как сказать... Полагаю, что упоминаемый остров - это мифический Остров Справедливости, столь популярный среди нищих.";
			link.l1 = "Чего?";
			link.l1.go = "FoundLetter_3";
		break;
		case "FoundLetter_3":
			dialog.text = "Ну, бродяги, понимаешь сам, люди обездоленные - разбитые судьбы, поломанные жизни. И хоть нет ни здоровья, ни жилья, ни денег, но хочется верить во что-то хорошее в будущем. Большинство наших верят в существование так называемого Острова Справедливости, зачастую эта вера спасает им жизнь.";
			link.l1 = "Расскажи подробней об этом Острове. Все, что знаешь и о чем говорят у вас.";
			link.l1.go = "FoundLetter_4";
		break;
		case "FoundLetter_4":
			dialog.text = "Говорят, что где-то в округе есть Остров, но не природного происхождения. Так вот, на этом острове царит закон и справедливость, жизнь там благоприятствует хорошему человеку. Сам-то я в это мало верю, на земле нет справедливости...";
			link.l1 = "Хм, а ведь в письме указано, что этот Остров существует! Сам читай: 'Выясняется, что слухи об острове имеют под собой реальную почву...'";
			link.l1.go = "FoundLetter_5";
		break;
		case "FoundLetter_5":
			dialog.text = "Ну, не знаю...";
			link.l1 = "А с чего вообще слухи-то пошли? С чего все началось?";
			link.l1.go = "FoundLetter_6";
		break;
		case "FoundLetter_6":
			dialog.text = "Так с Тизера Дэна и началось. Он немного не в себе был - пережил несколько кораблекрушений. Ему все наши говорили - не лезь в Кюрасао, а он все одно решил там жить... В общем, он утверждал, что жил на этом Острове насколько месяцев, вот и наболтал сказок.";
			link.l1 = "Хм, а Голландская Вест-Индская компания полагает, что не таких уж и сказок... А где сейчас этот Тизер, говоришь?";
			link.l1.go = "FoundLetter_7";
		break;
		case "FoundLetter_7":
			dialog.text = "Пропал. Мы его разыскать не сумели. Исчез без следа.";
			link.l1 = "Ты, помнится, говорил, что в Виллемстаде у него проблемы начались. Из города его выгоняли, вроде бы...";
			link.l1.go = "FoundLetter_8";
		break;
		case "FoundLetter_8":
			dialog.text = "Да-да, именно так. После того, как он попался на глаза Беку.";
			link.l1 = "Судя по всему, мне опять надо брать курс на Кюрасао...";
			link.l1.go = "FoundLetter_9";
		break;
		case "FoundLetter_9":
			dialog.text = "Ну что же, удачи тебе в этом деле! Спасибо за помощь, "+ GetSexPhrase("дружище","" + pchar.name + "") +".";
			link.l1 = "Будь здоров, приятель.";
			link.l1.go = "exit";
		                   npchar.quest.CanFoundStuvesantKey = "true";
			pchar.questTemp.LSCC = "toTalkStuvesant";
			pchar.questTemp.LSCC.poorName = GetFullName(npchar));
			AddQuestRecord("ISS_PoorsMurder", "7");
			AddQuestUserData("ISS_PoorsMurder", "sName", pchar.questTemp.LSCC.poorName);

		break;
		//базар с основным после завала Оливера Траста
		case "GoLSCC":
			dialog.text = NPCStringReactionRepeat("Отлично! Ну, расскажи, в чем все дело?", 
				"Мы уже говорили на эту тему.", 
				"Хм, пообщались уже...",
                "Послушай, долгие расставания - это для женщин.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, ты "+ GetSexPhrase("оказался прав","оказалась права") +" в предположении, которое "+ GetSexPhrase("высказал","высказала") +" в самом начале нашего общения. Все дело действительно в Тизере Дэне и его Острове.", 
				"Да, верно.",
                "Точно!", 
				"Хм, ты прав...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("GoLSCC_1", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "GoLSCC_1":
			dialog.text = "Поясни, пожалуйста!";
			link.l1 = "Я пока не могу много говорить. Но скажу, что Остров Тизера, о котором он так много рассказывал - не выдумка. Это правда, и я намерен отправиться туда!";
			link.l1.go = "GoLSCC_2";
		break;
		case "GoLSCC_2":
			dialog.text = "Поверить не могу!..";
			link.l1 = "Есть и очень плохая новость - Тизер Дэн мертв.";
			link.l1.go = "GoLSCC_3";
		break;
		case "GoLSCC_3":
			dialog.text = "А-а, черт! Жаль...";
			link.l1 = "Я хоть никогда и не видел"+ GetSexPhrase("","а") +" Тизера раньше, но мне стало понятно, что это был за человек. Действительно жаль.";
			link.l1.go = "GoLSCC_4";
		break;
		case "GoLSCC_4":
			dialog.text = "Значит, ты попытаешься найти этот Остров? Тогда я отдаю тебе ключ Тизера.";
			link.l1 = "Что за ключ?";
			link.l1.go = "GoLSCC_5";
		break;
		case "GoLSCC_5":
			dialog.text = "Точно я не знаю. Тизер отдал мне его на хранение до того, как отправился на Кюрасао. Говорил, что ключ Диффиндура, а что это означает - понятия не имею.";
			link.l1 = "Загадочный ключ! Интересно...";
			link.l1.go = "GoLSCC_6";
		break;
		case "GoLSCC_6":
			dialog.text = "По его наказу я должен отдать этот ключ тому, кто захочет найти Остров. Еще Тизер говорил, что этот ключ должен решить проблемы нового гражданина Острова. Что это означает - понятия не имею, но с удовольствием выполняю просьбу.";
	link.l1 = "Спасибо, дружище. И прощай.";
	link.l1.go = "exit";
                   npchar.quest.readyGoLSCC = "true";
	ChangeItemName("keyQuestLSCC", "itmname_keyQuestLSCC_Tizer");
	ChangeItemDescribe("keyQuestLSCC", "itmdescr_keyQuestLSCC_Tizer");
	sld = ItemsFromID("keyQuestLSCC");
	DeleteAttribute(sld, "shown");
	GiveItem2Character(pchar, "keyQuestLSCC");
                   CloseQuestHeader("ISS_PoorsMurder");

	sld = CharacterFromID("Abuyin");//Даём нуду Абуину 1 предсказание
	sld.dialog.currentnode = "WEISSAGUNG_2";
		
		break;
	}
}