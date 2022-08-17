// Рене Труэн_дюген
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sLoc;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;
    
// ============================================================================
// ============================= блок angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //ловушка первого срабатывания
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //сюда расписываем реакцию ангри. В npchar.angry.name пробелы удалены!!!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================
	switch(Dialog.CurrentNode)
	{
		case "First time":
            NextDiag.TempNode = "First time";
            dialog.text = NPCStringReactionRepeat("У тебя ко мне дело? Нет? Тогда "+ GetSexPhrase("выметайся отсюда!","попрошу не отвлекать меня.") +"",
	                         "Я, кажется, ясно выразился...", "Хотя я выразился и ясно, но ты продолжаешь отвлекать меня!",
	                         "Хм, да ты не в меру "+ GetSexPhrase("хамовит, мон шер","нагла, деваха") +"...", "repeat", 30, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Уже ухожу.",
	                                               "Да, " + npchar.name + ", совершенно ясно.",
	                                               "Извини, " + npchar.name + "...",
	                                               "Ай, ай...", npchar, Dialog.CurrentNode);
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

//********************* капитан Шарп *********************
	case "SharpPearl":
			dialog.text = "Чего тебе надобно здесь?";
			link.l1 = "Послушай, ходят слухи о промысле ловцов жемчуга в Карибском море. Ты ничего не слышал об этом?";
			link.l1.go = "SharpPearl_1";
		break;

		case "SharpPearl_1":
			dialog.text = "Слышал, только ничего об этом толком не знаю. Специализируется на этих промыслах наш всеми любимый и уважаемый капитан Шарп! Это он у нас большой любитель жемчуга, ха-ха-ха!";
			link.l1 = "А где его можно разыскать, этого Шарпа?";
			link.l1.go = "SharpPearl_2";
			pchar.questTemp.Sharp = "seekSharp";
		break;
		case "SharpPearl_2":
			dialog.text = "Не знаю. Капитан Шарп - это неуловимый Джо. Хотя тебе же он понадобился.\nА вообще искать его нужно в борделях.";
			link.l1 = "Спасибо, Рене.";
			AddQuestRecordInfo("Tutorial_Sharp", "1");
			link.l1.go = "exit";
		break;
// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("Пошел вон","Убирайся") +" отсюда!", "Вон из моего дома!");
			link.l1 = "Ой-ой-ой...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Робером через 30 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Тебе не стоит доставать меня, запомни это.";
        			link.l1 = "Я понял"+ GetSexPhrase("","а") +", Робер, больше не буду.";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("LeKe_town","reload","reload3_back");
		break;
		// <<<<<<<<<<<<============= блок нод angry =============================
	}
}

