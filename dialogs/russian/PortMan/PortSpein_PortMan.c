// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушайте, если вы не по делам порта, то не стоит меня вопросами донимать.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Извините, но портовые дела меня сейчас не интересуют.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажите, имя 'Хуан' вам что-нибудь говорит?";
				link.l1.go = "Consumption";
			}
			if (!CheckAttribute(npchar, "quest.Guardoftruth") && CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && pchar.questTemp.Guardoftruth.Trinidad == "begin")
			{
				link.l1 = "Сеньор, в апреле 1654 года в ваш порт заходил фрегат под командованием капитана Мигеля Дичозо. Он потом исчез. Не припоминаете ничего связанного с ним? Может, Дичозо заходил к вам, отмечался...";
				link.l1.go = "guardoftruth";
			}
			//ОЗГ, Крыса
			if (pchar.questTemp.Headhunter == "Rat" && pchar.questTemp.Headhunter.countP == 0)
			{
				link.l1 = "Говорят, не так давно, по выходу из вашего порта, пропало торговое судно. Не можете рассказать об этом поподробнее?";
				link.l1.go = "Rat_portmanP";
			}
		break;
		
		//Цена чахотки
		case "Consumption":
			dialog.text = "Хуан? И все? Может вспомните фамилию, или, хотя бы, название судна? Здесь же испанские колонии, милейший – Хуанов и Карлосов тут как бананов в джунглях, и в моих учетных книгах их не меньше, так что, если вы более ничего не знаете – я вам помочь не смогу.";
			link.l1 = "Ясно. Извините за беспокойство...";
			link.l1.go = "exit";
			pchar.questTemp.Consumption.AskJuan = sti(pchar.questTemp.Consumption.AskJuan)+1;
			if(sti(pchar.questTemp.Consumption.AskJuan) == 3)
			{
				pchar.quest.Consumption2.win_condition.l1 = "location";
				pchar.quest.Consumption2.win_condition.l1.location = "PortSpein_town";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption = "true";
		break;
		
		case "guardoftruth":
			dialog.text = "Давайте посмотрим записи...так-так. Да, был такой Мигель Дичозо в апреле 1654 года, фрегат 'Санта-Квитерия'. Действительно отмечался, прибыл из колонии Сан-Андрес, Провиденсия, пункт назначения - Кадис, Европа. Отбыл 14 апреля 1654 года. больше никаких сведений у меня нет.";
			link.l1 = "Ясно. Спасибо и на этом!";
			link.l1.go = "exit";
			npchar.quest.guardoftruth = "true";
			AddQuestRecord("Guardoftruth", "39");
		break;

		//ОЗГ, Крыса
		case "Rat_portmanP":
			dialog.text = "Да, премерзкая история вышла – как сейчас помню: целый пинас, груженный красным деревом чуть не под завязку. Его капитан так радовался тогда удачной сделке – целый вечер накануне отплытия кутил в таверне и хвастался. А потом пришла весть, что он так и не добрался до порта, куда держал курс. Говорят – его перехватили какие-то пираты.";
			link.l1 = "Да уж, этих молодчиков в наших водах хоть отбавляй. Скажите, а вы не можете посмотреть, какие корабли были в вашем порту вместе с этим злополучным пинасом?";
			link.l1.go = "Rat_portmanP_1";
		break;
		
		case "Rat_portmanP_1":
			dialog.text = "Давайте посмотрим. Так-с... вот. Были корабли: шхуна 'Дженни', корвет 'Стремительный' и пинас 'Аделаида'.";
			link.l1 = "Спасибо!";
			link.l1.go = "CheckP";
			pchar.questTemp.Headhunter.count = sti(pchar.questTemp.Headhunter.count) + 1;
			pchar.questTemp.Headhunter.countP = 1;
		break;
		
		case "CheckP":
			if(pchar.questTemp.Headhunter.count == 3)
			{
				pchar.questTemp.Headhunter = "Rat_Tavern";
				pchar.questTemp.Headhunter.Ratrumcity = npchar.city;
				AddQuestRecord("Headhunt", "13");
			}
			else
			{
				AddQuestRecord("Headhunt", "12_2");
			}
			DialogExit();
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}


