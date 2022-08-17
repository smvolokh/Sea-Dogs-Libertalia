// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вы хотели? Спрашивайте.", "Я слушаю вас, что за вопрос?"), "Второй раз за день вы пытаетесь задать ворпос...", "В третий раз за день вы опять пытаетесь задать вопрос...",
                          "Да когда же это кончится?! У меня дел полно по управлению делами города, а ты все вопросы пытаешься задать!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Не сейчас, не место и не время..."), "Да, верно... Но не сейчас, позже...",
                      "Задам, задам... Только позже...", "Извините, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "Gothic_10_1";
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Вы уже все забрали. Что вам еще нужно?", "Неужели осталось еще что-то, что вы не прихватили?");
            link.l1 = RandPhraseSimple("Осматриваюсь напоследок...", "Проверяю, может забыл"+ GetSexPhrase("","а") +" что забрать...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;

        //********************** Гот.линейка. Квест. Захват Санто-Доминго ************************

		case "Cupture_after_1":
            dialog.text = RandPhraseSimple("За меня вам отомстят, рано радуетесь?", "Испанцы не сдаются?");
            link.l1 = RandPhraseSimple("Я не понятно выразился? Поднимай свою задницу...", "Я не повторяю два раза, освободи кресло и шевели задницей ко входу...");
            link.l1.go = "Gothic_10_2";
		break;

		case "Quest_OccupySD":
            dialog.text = "Вы победили... И что будет теперь? Выкуп?";
			link.l1 = "Нет, сеньор. Я, " + GetFullName(pchar) + ", объявляю этот город владением французской короны. Это акция является адекватным ответом на вашу попытку захвата Порт-о-Принса.";
            link.l1.go = "Gothic_10_1";
			AfterTownBattle();
        break;

		case "Gothic_10_1":
            dialog.text = "Вам не удержать город...";
			link.l1 = "Удержим, не волнуйтесь, сеньор... Ну а сейчас город ждут перемены... Да, кстати, а вы помещаетесь под арест, прошу вас освободить кресло.";
		 link.l1.go = "exit";
                                       NextDiag.TempNode = "Cupture_after_1";
                                       PChar.questTemp.DontSetNewDialogToMayor = true; // иначе может сменить диалог и сбойнуть
                                       DeleteAttribute(PChar, "questTemp.DontSetNewDialogToMayor");
                                        SetReturn_Gover_Dialog_Exit(NPChar);
                                         AddDialogExitQuestFunction("LaunchColonyInfoScreen"); // табличка 
                                        SetCaptureTownByNation(NPChar.City, sti(PChar.nation));
                                         UpdateRelations();
                                         Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_TakeTown", 1);
                                         PChar.questTemp.DontNullDeposit = true;    // чтоб не нулили ростовщика
                                          pchar.questTemp.GothicLee = "OccupySD_toWeWon";
        break;
		case "Gothic_10_2":
            dialog.text = "Похоже у меня нет выбора, что ж с вашего позволения позвольте откланится!";
			link.l1 = "Извольте, но предупреждаю бежать не куда.";
			link.l1.go = "Gothic_10_3";
        break;

		case "Gothic_10_3":
                                                         dialog.text = "Не беспокойтесь капитан, я не собираюсь этого делать.";
			link.l1 = "";
			link.l1.go = "Gothic_10_4";
        break;

		case "Gothic_10_4":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
                                       dialog.text = "";
		 link.l1 = "Хорошо.";
                                        DoQuestFunctionDelay("GothicLee_Mayor_death", 3.0);

        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

