// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
                                          dialog.text = RandPhraseSimple("Какие вопросы?", "Что вас угодно?");
		link.l1 = RandPhraseSimple("Я передумал...", "Сейчас мне не о чем говорить");
		link.l1.go = "exit";

	                     // Отступники веры Мэри Селеста
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_MaryCelesteChurch" && !CheckAttribute(npchar, "quest.APS_MaryCelesteChurch"))
		{
		link.l1 = "Падре, я бы хотел узнать о судьбе капитана Бенджамина Брикс и его супруги Сары Брикс, знаю они упокоины на вашем кладбище возле церкви. Что произошло с этими людьми!";
		link.l1.go = "MaryCelesteChurch";
		}
		break;

		case "MaryCelesteChurch":
		dialog.text = "Почему вы интересуетесь этими людьми.";
		link.l1 = "Я капитан и я много путешествую, просто я знаком с человеком по имени Льюис Брикс, вот я, и собственно интересуюсь, может это родственники.";
		link.l1.go = "MaryCelesteChurch_1";
		break;

		case "MaryCelesteChurch_1":
		dialog.text = "Рассказывать особо тут не о чём. Бенджамин, Сара и малютка Софи Брикс, они появились здесь год назад, в тот день, как я помню шёл сильный ливень, они выглядели промокшими и беспомощными. Как настоятель этой часовни и христианин, я проявил заботу для этой семьи, предоставив своё скромное жилище. Мне было приятно общаться с ними, это были вежливые и добрые люди.";
		link.l1 = "Понятно, но как они умерли, что произошло!";
		link.l1.go = "MaryCelesteChurch_2";
		break;

		case "MaryCelesteChurch_2":
		dialog.text = "Состарились и умерли.";
		link.l1 = "Ничего не понимаю, как состарились, сколько им было лет?";
		link.l1.go = "MaryCelesteChurch_3";
		break;

		case "MaryCelesteChurch_3":
		dialog.text = "Неизвестная болезнь, когда я первый раз их увидел им было около 40 лет не более, а их дочке 2 года. В течении года они старели прямо на моих глазах, молитвы и причастия не помогли, видно так угодно Богу.";
		link.l1 = "А дочь их жива?";
		link.l1.go = "MaryCelesteChurch_4";
		break;

		case "MaryCelesteChurch_4":
		dialog.text = "Да, но её ждёт та же участь, как и её родителей. За один год она стала выглядеть как 25 летняя девушка, пройдёт ещё год она будет выглядеть уже под 60 лет, а через пол года её не будет. Молитвы и медицина тут бесполезны, как бы я хотел помочь этим людям, но увы, не в моих силах, я сделал всё, что мог.";
		link.l1 = "Может у меня получится, я знаю одного целителя, я к тому, если у вас ничего не получилось, тогда возможно получится её исцелить у моего знакомого целителя?";
		link.l1.go = "MaryCelesteChurch_5";
		break;

		case "MaryCelesteChurch_5":
		dialog.text = "Даже не знаю, могу ли я вам доверить. Хотя и у меня выбора нет. Если ты говоришь правду и этот целитель, это было бы чудесно, знать что с миловидной девочкой всё обошлось с наилучшим образом. Как я хочу ей помочь...";
		link.l1 = "Решайтесь, падре...";
		link.l1.go = "MaryCelesteChurch_6";
		break;

		case "MaryCelesteChurch_6":
		dialog.text = "Хорошо, согласен, она сейчас находится в склепе, омывает покойника, вы можете пройти и поговорить с ней.";
		link.l1 = "Спасибо, падре.";
		link.l1.go = "MaryCelesteChurch_7";
		break;

		case "MaryCelesteChurch_7":
		dialog.text = "Да поможет тебе Господь - сын мой.";
		link.l1 = "...";
		link.l1.go = "exit";
	                     npchar.quest.APS_MaryCelesteChurch = "true";
		AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_2");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

