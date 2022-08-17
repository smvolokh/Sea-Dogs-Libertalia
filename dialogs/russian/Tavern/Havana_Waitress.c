// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Вопросы, " + GetAddress_Form(NPChar) + "?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), ""+ GetSexPhrase("Хм, уж не пристаете ли вы ко мне, " + GetAddress_Form(NPChar) + "? ","Опять со странными вопросами? Девушка, выпили бы вы рому, что ли...") +"", "В течение этого дня вы уже третий раз говорите о каком-то вопросе..."+ GetSexPhrase(" Это знаки внимания?","") +"",
                          "Опять вопросы будете задавать, " + GetAddress_Form(NPChar) + "?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить"), "Да нет, что ты, красавица...",
                      "Никак нет, дорогуша, склероз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// ==> Проверяем поле состояния квестов.

            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_toHavana")
            {
    		    dialog.text = "Я вас слушаю, сеньор"+ GetSexPhrase("","ита") +".";
    			link.l1 = "Милая девочка, если твоя душа такая же ангельская, как и внешность, то ты, конечно, не откажешься мне помочь.";
    			link.l1.go = "Gothic_1";
			}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_WaitOneDay")
            {
				if (GetQuestPastDayParam("questTemp") > 0)
				{
    				dialog.text = "Ах, вот и вы сеньор"+ GetSexPhrase("","ита") +"! Как раз вовремя.";
    				link.l1 = "Ага, вижу, что ты передала кольцо...";
    				link.l1.go = "Gothic_4";
				}
				else
				{
    				dialog.text = "Сеньор"+ GetSexPhrase("","ита") +", я еще не выполнила вашего поручения. Подождите, будте терпеливы, прошу вас...";
    				link.l1 = "Хорошо, дорогуша, жду...";
    				link.l1.go = "exit";
				}
			}
            // <== Проверяем поле состояния квестов.
		break;


//========================== квест. Увезти донну Анну ==================================
 	 	case "Gothic_1":
			dialog.text = "Ну что вы, право... "+ GetSexPhrase("Такому благородному кабальеро отказать ни в чем невозможно!","Такой видной женщине я помогу, конечно.") +"";
			link.l1 = "Мне нужно, чтобы ты отнесла это кольцо донне Анне Рамирес де Лейва, жене коменданта. Но только так, чтобы об этом не знала ни одна живая душа!";
			link.l1.go = "Gothic_2";
        break;
 	 	case "Gothic_2":
			dialog.text = "Ах, у донны Анны и так много красивых колец, зачем ей еще одно? А у бедной девушки нет ничего...";
			link.l1 = "Плутовка, я понял"+ GetSexPhrase("","а") +", на что ты намекаешь! Ну, держи 500 монет, и еще столько же получишь, когда принесешь ответ от донны Анны. На эти деньги ты купишь себе сколько угодно украшений.";
			link.l1.go = "Gothic_3";
			AddMoneyToCharacter(pchar, -500);
        break;
 	 	case "Gothic_3":
			dialog.text = "Спасибо, сеньор"+ GetSexPhrase("","ита") +"! Вам придется подождать день-другой. Я должна сдать смену и найти время для того, чтобы сходить к дому сеньоры де Лейва. Да и случай нужен подходящий - так просто к ним в дом не заявишься...";
			link.l1 = "Очень хорошо, милая. Я жду тебя...";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "DOjeronRing");
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_WaitOneDay";
			SaveCurrentQuestDateParam("questTemp");
			AddQuestRecord("GothicLee_TakeAnna", "2");
        break;
 	 	case "Gothic_4":
			dialog.text = "Да, передала.";
			link.l1 = "Хорошо. А теперь расскажи мне, что она тебе сказала...";
			link.l1.go = "Gothic_5";
        break;
 	 	case "Gothic_5":
			dialog.text = "А разве сеньор"+ GetSexPhrase("","ита") +" не хочет еще помочь бедной девушке?\n"+
				          "Ох, сеньор"+ GetSexPhrase("","ита") +", прошу вас, не сжимайте мне руку так сильно! У меня потом останутся синяки от ваших пальцев!";
			link.l1 = "Ладно... Послушай, я прошу тебя говорить быстро и по существу. Не тяни за хрен енота, милая - целее будешь...";
			link.l1.go = "Gothic_6";
        break;
 	 	case "Gothic_6":
			dialog.text = "Хорошо, сеньор"+ GetSexPhrase("","ита") +"... Я отдала ей ваш перстень. И знаете что, сеньор"+ GetSexPhrase("","ита") +"? Когда она его увидела, то побледнела, как полотно.";
			link.l1 = "И что? Что она сказала?";
			link.l1.go = "Gothic_7";
        break;
 	 	case "Gothic_7":
			dialog.text = "Ничего особенного. Приказала подождать, тут же написала записку и передала ее мне.";
			link.l1 = "Давай записку сюда!";
			link.l1.go = "Gothic_8";
        break;
 	 	case "Gothic_8":
			dialog.text = "Хорошо, сеньор"+ GetSexPhrase("","ита") +", только не делайте мне снова больно... Вот она, возьмите.";
			link.l1 = "Молодец, хорошая девочка. Не бойся, возьми вот еще денег, купи себе что-нибудь... И держи язык за зубами, красавица. Тебе понятно?";
			link.l1.go = "Gothic_9";
        break;
 	 	case "Gothic_9":
			dialog.text = "Понятно, сеньор"+ GetSexPhrase("","ита") +", чай не дурой уродилась.";
			link.l1 = "Ну вот и славно.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -500);
			AddQuestRecord("GothicLee_TakeAnna", "3");
			AddQuestUserData("GothicLee_TakeAnna", "sSex", GetSexPhrase("ел","ла"));
            ChangeItemDescribe("letter_open", "itmdescr_letter_open_FraLineQ3");
            GiveItem2Character(pchar,"letter_open");
             pchar.questTemp.GothicLee = "GothicLeeTakeAnna_WaitMidnight";
        break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

