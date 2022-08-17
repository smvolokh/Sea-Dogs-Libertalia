// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Некоторое время тому назад, находясь у меня в магазине, вы пытались задать какой-то вопрос...", "За сегодня третий вопрос. Мне торговать надо, а не пустые разговоры вести...",
                          "Опять вопросы? Может лучше торговлей займемся?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Сейчас мне не о чем говорить"), "Да, точно, пытался... Находясь в магазине...",
                      "Да уж, действительно в третий раз...", "Хм, может и поторгуем...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			if(PChar.DestinyGift == "23" && PChar.DestinyGift.FindFiveChapter.Havana == false)
			{
				Link.l1 = "Послушай тебе что-нибудь известно о Бернальдинио Торангера, капитане ''Стервятника''?";
				Link.l1.go = "DestinyGift_1";
			}

			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажи, имя 'Хуан' тебе что-нибудь говорит?";
				link.l1.go = "Consumption";
			}
		
		break;
		
		
		// ЧЁРНАЯ ОРХИДЕЯ - ПОДАРОК СУДЬБЫ -->
		case "DestinyGift_1":
			dialog.Text = "Как ты сказал? Бернальдинио Торангера?";
			Link.l1 = "Да. Мне говорили, что вы знаете его.";
			Link.l1.go = "DestinyGift_2";
		break;
		
		case "DestinyGift_2":
			dialog.Text = "Да знаю. Бернальдинио часто возил мне грузы кофе и какао. Все поставки в срок, никаких опозданий, или задержек.";
			Link.l1 = "А где сейчас Бернальдинио?";
			Link.l1.go = "DestinyGift_3";
		break;
		
		case "DestinyGift_3":
			dialog.Text = "Чёрт его знает. Давно уже не появлялся. А тебе зачем он нужен?";
			Link.l1 = "Он должен отдать мне одну вещь. Брал на время.";
			Link.l1.go = "DestinyGift_4";
		break;
		
		case "DestinyGift_4":
			PChar.DestinyGift.FindFiveChapter.Havana = true;
			dialog.Text = "Понятно. Извини, но ничем помочь не могу, не знаю я, где он.";
			Link.l1 = "Ясно. Но всё-таки спасибо.";
			Link.l1.go = "exit";
		break;
		// ЧЁРНАЯ ОРХИДЕЯ - ПОДАРОК СУДЬБЫ <--

		//Цена чахотки
		case "Consumption":
			dialog.text = "Не знаю. И не хочу знать. И вам не советую. А теперь, прошу прощения, но мне нужно возвращаться к делам. У вас, наверное, тоже есть дела? Займитесь ими.";
			link.l1 = "Ясно. Извините за беспокойство...";
			link.l1.go = "exit";
			pchar.questTemp.Consumption.AskJuan = sti(pchar.questTemp.Consumption.AskJuan)+1;
			if(sti(pchar.questTemp.Consumption.AskJuan) == 3)
			{
				pchar.quest.Consumption2.win_condition.l1 = "location";
				pchar.quest.Consumption2.win_condition.l1.location = "VillaAlegria_town2";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption = "true";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);
}

