// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушайте, если вы не по делам порта, то не стоит меня вопросами донимать.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Извините, но портовые дела меня сейчас не интересуют.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption.AskJuan"))
			{
				link.l1 = "Скажите, имя 'Хуан' вам что-нибудь говорит?";
				link.l1.go = "Consumption";
			}
			if(PChar.SpanishGenerosity == "6")
			{
				link.l2 = "Мне нужно узнать, в какой порт держит курс военный корабль ''Андромеда''.";
				link.l2.go = "SpanishGenerosity_1";
			}
			
			if(PChar.SpanishGenerosity == "7")
			{
				link.l3 = "Я по поводу ''Андромеды''...";
				link.l3.go = "SpanishGenerosity_5";
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
				pchar.quest.Consumption2.win_condition.l1.location = "VillaAlegria_town2";
				pchar.quest.Consumption2.function = "Consumption_CreateSergio";
			}
			npchar.quest.Consumption = "true";
		break;

	
	        // ИСПАНСКАЯ ЩЕДРОСТЬ -->
		case "SpanishGenerosity_1":
			dialog.text = "Извините, капитан, но я не имею права разглашать военную тайну.";
			link.l1 = "Сколько я могу предложить вам, чтобы приоткрыть завесу этой тайны?";
			link.l1.go = "SpanishGenerosity_2";
		break;
		
		case "SpanishGenerosity_2":
			dialog.text = "50 000 пиастров, капитан, и вы всё узнаете.";
			
			if(sti(PChar.money) >= 50000)
			{
				link.l1 = "Вот деньги, рассказывай.";
				link.l1.go = "SpanishGenerosity_3";
			}
			else
			{
				link.l1 = "Э-э... Я пожалуй, попозже подойду.";
				link.l1.go = "SpanishGenerosity_4";
			}
			
			link.l2 = "Чего?! А миллион тебе не дать?!";
			link.l2.go = "SpanishGenerosity_4";
		break;
		
		case "SpanishGenerosity_3":
			AddMoneyToCharacter(PChar, -50000);
			dialog.text = "''Андромеда'' держит курс в бухту Сан Хуан дель Норте.";
			link.l1 = "Покорнейше благодар" + GetSexPhrase("ен","на") + " вам.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("SpanishGenerosityAlborettoInShore");
		break;
		
		case "SpanishGenerosity_4":
			PChar.SpanishGenerosity = "7";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "SpanishGenerosity_5":
			dialog.text = "Опять вы? Цена не изменилась - 50 000 пиастров.";
			
			if(sti(PChar.money) >= 50000)
			{
				link.l1 = "Вот деньги, рассказывай.";
				link.l1.go = "SpanishGenerosity_3";
			}
			else
			{
				link.l1 = "На данный момент я не располагаю такой суммой.";
				link.l1.go = "SpanishGenerosity_4";
			}
			
			link.l2 = "Я, пожалуй, передумал" + GetSexPhrase("","а") + ".";
			link.l2.go = "SpanishGenerosity_4";
		break;
	        // <-- ИСПАНСКАЯ ЩЕДРОСТЬ

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

