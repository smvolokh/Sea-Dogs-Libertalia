// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Спрашивай, чего ты хочешь?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушай, это магазин, здесь люди покупают что-то. Не отвлекай меня!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Гм, не буду...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			if (pchar.questTemp.piratesLine == "KillLoy_toSeek")
			{
				link.l1 = "Простите, у вас Эдвард Лоу, приобретал корабль?";
				link.l1.go = "PL_Q3_1";
			}
		break;

		//пиратка, квест №3, поиски Лоу
		case "PL_Q3_1":
			dialog.text = NPCStringReactionRepeat("У меня?! Вы меня с кем-то путаете, я торговец, но кораблями... Кораблями не торгую! Вам, " + GetSexPhrase("молодой человек","молодая девочка") + ", на верфь нужно обратиться, к корабелам. Да, да к ним, а ко мне за всем остальным!", 
				"Вы уже спрашивали. Нет, не приобретал.", 
				"Нет, молодой человек, нет...",
                "Ох, ну и зануда же вы!!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Да, но в вашем городишке нет верфи!", 
				"Понятно...",
                "Ага, ясно...", 
				"Хм, уже ухожу...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("PL_Q3_2", "", "", "", npchar, Dialog.CurrentNode);
		break;
		case "PL_Q3_2":
			dialog.text = "Ничем помочь не могу, по моему желанию верфь у нас не появится. Спросите у кого-нибудь еще...";
			link.l1 = "Ясно... Ну что же, спасибо и на этом.";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "3");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);
}

