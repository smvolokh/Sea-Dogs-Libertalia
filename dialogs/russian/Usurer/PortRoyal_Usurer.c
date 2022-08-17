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

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Usurer" && !CheckAttribute(npchar, "quest.RevengeCorsair_Usurer"))
			{
				link.l1 = "Я слышал, что ваш банк был ограблен? Я могу помочь вам и найти тех кто это сделал, если вы мне расскажите об этом проишествии подробно.";
				link.l1.go = "RevengeCorsair_Usurer";
			}

		break;


		//********************* Месть корсара *********************

   		case "RevengeCorsair_Usurer":
			dialog.text = "А чего тут рассказывать, чисто сработано, профессионально. Ключ от сейфа у меня один сделаный по заказу в Лондоне, лучшим мастером, этот ключ всегда при мне, я его никогда и ни кому не давал. И куда только стража смотрит, прямо под носом Моргана, а ещё адмирал пиратов...";
			link.l1 = "Понятно, и сколько было похищено!";
			link.l1.go = "RevengeCorsair_Usurer_1";
		break;

   		case "RevengeCorsair_Usurer_1":
			dialog.text = "Тридцать миллионов песо, три тысячи дублонов, куртка замшевая - три, золотой портсигар...";
			link.l1 = "Три!";
			link.l1.go = "RevengeCorsair_Usurer_2";
		break;

   		case "RevengeCorsair_Usurer_2":
			dialog.text = "Как вы догадались, вы такой проницательный...";
			link.l1 = "...";
			link.l1.go = "RevengeCorsair_Usurer_3";
		break;

   		case "RevengeCorsair_Usurer_3":
 	                                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_2.wav");
			dialog.text = "...";
			link.l1 = "Э, ну, я думаю!";
			link.l1.go = "RevengeCorsair_Usurer_4";
		break;

   		case "RevengeCorsair_Usurer_4":
			dialog.text = "Так вот, верно три, ещё взяли золотой светильник...";
			link.l1 = "Стоп, стоп, я всё понял, мне пора!";
			link.l1.go = "RevengeCorsair_Usurer_5";
		break;

   		case "RevengeCorsair_Usurer_5":
 	                 PlaySound("VOICE\Russian\GOTHIC\GG\HOLDEINGOLD_2.wav");
		dialog.text = "Эх, удачи вам...Найдите этих подонков!";
		link.l1 = "Я посмотрю, что можно сделать.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Usurer = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_4");
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

