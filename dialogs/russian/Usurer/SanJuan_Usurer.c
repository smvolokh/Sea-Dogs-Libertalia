// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "М-да, позвольте угадаю... Опять ничего существенного?",
                          "Послушайте, я финансами оперирую, а не на вопросы отвечаю...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Вы угадали, простите...", "Я понимаю...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			// Отступники веры
			if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_usurer" && !CheckAttribute(npchar, "quest.APS_usurer"))

			{
			link.l1 = "Меня к Вам направил Рэндольф Кэннелл.";
			link.l1.go = "ApostatesAPS1";
			}
			break;

			// Отступники веры
			case "ApostatesAPS1":
			dialog.text = "А, это вы, милости прошу. Вы как никогда вовремя! Сегодня ночью, состоится встреча Епископа отца Винсенто с одним из наемников, которого иезуиты смогли привлечь на свою сторону, жуткий человек и по моим сведениям, располагает мощным кораблем.";
			link.l1 = "Вы можете конкретно мне сказать место и время встречи? Попытаюсь незаметно подслушать их разговор.";
			link.l1.go = "ApostatesAPS2";
			break;
				
			case "ApostatesAPS2":
			dialog.text = "Известно, что они встречаются после полуночи в церкви. Смотрите, что бы они вас не заметили, иначе вам не поздоровится, сеньор" + GetSexPhrase("","ита") + " капитан.";
			link.l1 = "Постараюсь, да, и спасибо за напутствие.";
			link.l1.go = "Exit";
			npchar.quest.APS_usurer = "true";
			AddDialogExitQuest("GothicApostates_APS_church");
			break;
					
			
		break;

	

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

