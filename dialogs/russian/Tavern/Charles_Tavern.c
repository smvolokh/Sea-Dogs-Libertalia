// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Сага
			if(CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "valet")
			{
				link.l1 = "Я ищу человека по кличке Валет. Не знаешь такого?";
				link.l1.go = "valet_1";
				link.l2 = "Я разыскиваю капитана полакра 'Марлин'. Не подскажешь, где его найти?";
				link.l2.go = "valet_2";
			}
                                                          // Зачарованный город
			if (pchar.questTemp.MC == "toSeekSister")
			{
				link.l1 = "Дружище, я ищу юную леди по имени Элизабет Шеппард. Ты о такой не слышал?";
				link.l1.go = "MCLiz";
			}

			                    // Одержимые -->

			if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "ObsessionTakeCoin" && !CheckAttribute(npchar, "quest.ObsessionTakeCoin"))
			                   {
			Link.l1 = "Я разыскиваю квартирмейстера Юмбера Кёруа.";
			Link.l1.go = "ObsessionTakeCoin";
				break;
			                     }
			                    //<-- Одержимые
		break;
		
		case "valet_1":
			dialog.text = NPCStringReactionRepeat("Нет, не знаю, приятель. Так что ничем помочь не могу.", "Я тебе уже сказал - не знаю!", "Ты пьян, или издеваешься?", "Отстань!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Понятно. Очень жаль...", "Жаль. Я думал, ты вспомнишь...", "Да трезвый я! Просто настойчивый...", "Гм...", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;
		
		case "valet_2":
			dialog.text = NPCStringReactionRepeat("А, это же мистер Давид Факман! Он снимает дом недалеко от верфи. Поищите его там.", "Я только что тебе ответил. Чем ты слушаешь?", "Ты пьян, или издеваешься?", "Отстань!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Спасибо!", "Да-да, извини.", "Да трезвый я! Просто непонятливый...", "Гм...", npchar, Dialog.CurrentNode); 
			link.l1.go = DialogGoNodeRepeat("exit", "", "", "", npchar, Dialog.CurrentNode);
		break;

                                                          // Зачарованный город

		case "MCLiz":
			dialog.text = "Мадмуазэль Лиз Шеппард - жительница нашего города. А что вам нужно от нее?";
			link.l1 = "Понимаешь, она кое-что забыла в заливе Маракайбо...";
			link.l1.go = "MCLiz_1";
		break;
		case "MCLiz_1":
			dialog.text = "Да, Лиз в последнее время что-то часто стала путешествовать. В городе ее и не застать.";
			link.l1 = "А сейчас она где?";
			link.l1.go = "MCLiz_2";
		break;
		case "MCLiz_2":
			dialog.text = "Сейчас у себя в доме.";
			link.l1 = "У нее собственный дом?";
			link.l1.go = "MCLiz_3";
		break;
		case "MCLiz_3":
			dialog.text = "Да, дом ее отца.";
			link.l1 = "А кто ее отец?";
			link.l1.go = "MCLiz_4";
		break;
		case "MCLiz_4":
			dialog.text = "Ну, об этом особо распространяться не принято, но вам я расскажу.\n"+
				"Слышали вы о капитане Барбоссе? Нет? Хо-хо, тогда знайте, что капитан Барбосса, который был одним из самых грозных флибустьеров, и есть отец Лиз. В свое время, когда он был еще жив, капитан много сделал для развития города, так что жители Сент-Кристофера ему обязаны.";
			link.l1 = "Элизабет имеет фамилию Шеппард.";
			link.l1.go = "MCLiz_5";
		break;
		case "MCLiz_5":
			dialog.text = "Это капитан так решил. Когда он поселился с семьей в городе, то взял другую фамилию. Вроде как девичью фамилию своей матери. Так, на всякий случай...";
			link.l1 = "И Лиз теперь живет одна?";
			link.l1.go = "MCLiz_6";
		break;
		case "MCLiz_6":
			dialog.text = "Да, ее мать похоронена здесь же, на острове. Однажды какие-то пираты совершили налёт на наш город и её убило шальным ядром. Вроде как сам Чёрная Борода тогда атаковал нас... А капитан Барбосса исчез куда-то вскоре после её смерти. Говорят, что опять в пираты пошёл, а ещё слухи ходят, что он мстить Тичу пошёл... Вот такие дела... А Аврора, дочка ещё одна, не появлялась дома уже года два.";
			link.l1 = "Аврора?";
			link.l1.go = "MCLiz_7";
		break;
		case "MCLiz_7":
			dialog.text = "Старшая сестра Лиз.";
			link.l1 = "Понятно. Ну что же, спасибо тебе, приятель.";
			link.l1.go = "MCLiz_8";
		break;
		case "MCLiz_8":
			dialog.text = "Не за что. Надеюсь, вы принесли Лиз хорошие новости. Она хорошая девушка, капитан...";
			link.l1 = "Во всяком случае, ничего плохого. Это уж точно.";
			link.l1.go = "exit";
			pchar.questTemp.MC = "toSeekSisterAT";
		break;

		//********************* Одержимые *********************

		

		//********************* Одержимые *********************

		case "ObsessionTakeCoin":
		dialog.text = "Юмбера Кёруа похоронили два дня назад. А кем вы ему приходитесь!";
		 link.l1 = "Это мой кузен, но что произошло, как так?";
                                           link.l1.go = "ObsessionTakeCoin_1";
		 break;

		case "ObsessionTakeCoin_1":
                                          TakeNItems(pchar, "Grog", 1);
                                          Log_Info("Вы получили бутылку грога");
                                          PlaySound("interface\important_item.wav");
		dialog.text = "Вот так, был человек и не стало. Убили вашего кузена, теперь он покоится на кладбище, там вы его и сможете навестить. Вот возьми, выпей за упокой, такого хорошего человека.";
		 link.l1 = "Благодарю, приятель.";
                                           link.l1.go = "exit";
		 npchar.quest.ObsessionTakeCoin = "true";
		 AddDialogExitQuest("GothicObsession_cemeteryman");
		 break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

