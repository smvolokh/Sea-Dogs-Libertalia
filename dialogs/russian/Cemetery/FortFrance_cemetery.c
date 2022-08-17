// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вам угодно?", "Что вы хотели узнать?"), "Так скажите, что же вас интересует, " + GetAddress_Form(NPChar) + "?", "Третий раз за сегодня вы пытаетесь задать вопрос...", "Всё, вы меня утомили. Покиньте мой дом!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить"), "Ох, что-то я запамятовал. Простите...",
                      "Да уж, действительно в третий раз...", "Извиняюсь...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(pchar, "questTemp.GothicLee") && pchar.questTemp.GothicLee == "SeekBible_crypt" && !CheckAttribute(npchar, "quest.SeekBible"))
			{
				dialog.text = "Я слушаю тебя мой друг!";
				link.l1 = "Мне нужно попасть в склеп, что находится в часовни?";
				link.l1.go = "Gothic_3_1";
			}

		break;

        //********************** Гот. линейка Ли***********************

 		case "Gothic_3_1":
			dialog.text = "";
			link.l1 = "Ну, так, ты мне можешь помочь?";
			link.l1.go = "Gothic_3_2";
  		break;
 		case "Gothic_3_2":
			dialog.text = "Скажи, зачем тебе этот склеп!";
			link.l1 = "Ну как это зачем? Навестить моего покойного родственика, а вот дверь закрыта?";
			link.l1.go = "Gothic_3_3";
  		break;
 		case "Gothic_3_3":
			dialog.text = "Да, не задача, эту дверь закрыла смотрительница часовни, после прихода какого то корсара, ключ у неё и она его ни кому не даёт, весь день она находится там на службе по отпеванию усобших, а вот начью?";
			link.l1 = "Продолжай?";
			link.l1.go = "Gothic_3_4";
  		break;

		case "Gothic_3_4":
			dialog.text = "Хорошо, я помогу тебе, приходи ночью после одинадцати вечера и не позже двенадцати, а то после двенадцати ночи плохая примета шастать по кладбищу, дверцу постараюсь открыть для тебя.";
			link.l1 = "Отлично.";
			link.l1.go = "Gothic_3_5";
  		break;

 		case "Gothic_3_5":
			DialogExit();
			pchar.quest.SeekBiblehour.win_condition.l1 = "locator";
			pchar.quest.SeekBiblehour.win_condition.l1.location = "FortFrance_church IM";
			pchar.quest.SeekBiblehour.win_condition.l1.locator_group = "reload";
			pchar.quest.SeekBiblehour.win_condition.l1.locator = "reload3";

			pchar.quest.SeekBiblehour.win_condition.l2 = "HardHour";
			pchar.quest.SeekBiblehour.win_condition.l2.hour = 23.00;
			pchar.quest.SeekBiblehour.function = "SeekBible_hour";
			npchar.quest.SeekBible = "true";
  		break;

	}
	UnloadSegment(NPChar.FileDialog2); 
}


