// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Все сплетни города "+ GetCityName(npchar.city) +" к вашим услугам. Что бы вы хотели узнать?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Что ты "+ GetSexPhrase("заладил","заладила") +" как попугай одно и то же...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, забыл что-то...",
                      "Да уж, действительно в третий раз...", "Да уж...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "Ты не знаешь, где я могу найти Франсуа Гонтьера?";
                link.l1.go = "Jamaica_ratP_1";
            }
			// Страж Истины
			if (CheckAttribute(pchar, "questTemp.Guardoftruth") && pchar.questTemp.Guardoftruth == "merdok" && !CheckAttribute(npchar, "quest.jino"))
			{
				link.l1 = "Послушай, не появлялся ли у вас в городе ученый-алхимик, лекарь? Он итальянец, лет тридцати, зовут Джино Гвинейли. Не слыхал о таком?";
				link.l1.go = "guardoftruth";
			}

            // ==> квест гот.линейки, отговорить трех корсаров
            if (pchar.questTemp.GothicLee == "ThreeCorsairs_toSeek")
			{
                link.l1 = "Где я могу найти капитана Йохана? У меня к нему важное дело.";
                link.l1.go = "Gothic_6_1";
			}

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Oliver" && !CheckAttribute(npchar, "quest.RevengeCorsair_Oliver"))
			{
				link.l1 = "Не слышал ничего про ограбление банка?";
				link.l1.go = "RevengeCorsair_Oliver";
			}
		break;

		case "Jamaica_ratP_1":
			dialog.text = NPCStringReactionRepeat("Без малейшего понятия. Я вообще впервые слышу это имя.", "Ты уже "+ GetSexPhrase("спрашивал","спрашивала") +" об этом, я тебе ответил.", "Я же говорю тебе, ты уже "+ GetSexPhrase("спрашивал","спрашивала") +" об этом Гонтьере.", "Послушай, отойди и не мешай! Совсем что ли крыша поехала?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Ну что же, будем искать.", "Хм, ну да...", "Да, точно, "+ GetSexPhrase("спрашивал","спрашивала") +"...", "Извини, " + npchar.name + "...", npchar, Dialog.CurrentNode);
		break;
		
		case "guardoftruth":
			dialog.text = LinkRandPhrase("Нет, не слыхал. Есть у нас травники, и лекари - но ни одного с таким именем.","Впервые такое чудное имя слышу. Нет, таких у нас отродясь не водилось.","Да у нас и вовсе никаких алхимиков нет. Лекари есть, но ни одного с таким чудным именем.");
			link.l1 = "Ясно. Жаль. Буду искать дальше!";
			link.l1.go = "exit";
			npchar.quest.jino = "true";
		break;

		//********************* Месть корсара *********************

   		case "RevengeCorsair_Oliver":
			dialog.text = "А чего тут говорить, чисто сработано, профессионально.";
			link.l1 = "Понятно, но может, что необычное было в тот день?";
			link.l1.go = "RevengeCorsair_Oliver_1";
		break;

   		case "RevengeCorsair_Oliver_1":
		dialog.text = "Да нет всё как обычно - спокойно...";
		link.l1 = "Спасибо, мне пора.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Oliver = "true";
		pchar.questTemp.RevengeCorsair_Oliver = sti(pchar.questTemp.RevengeCorsair_Oliver)+1;
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_3");
		break;

		//**********************линейка Ли **********************
        case "Gothic_6_1":
			dialog.text = NPCStringReactionRepeat("Капитана Йохана? Нет ничего проще. Он снимает у меня комнату, и сегодня еще не выходил, так что вы его там обязательно увидите.", 
				          "Я уже все сказал...", "Не о чем говорить...", ""+ GetSexPhrase("Сэр","Мисс") +", дайте мне возможность заниматься своими делами!", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Спасибо, дружище...", ""+ GetSexPhrase("Понял","Поняла") +", извини...", "Хм, ну да...", "Да, да, извини, приятель...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

