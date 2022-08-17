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
			link.l1.go = "exit";

			if (pchar.questTemp.piratesLine == "Panama_toPortoBello")//пиратка, штурм Панамы
			{
				dialog.text = "";
				link.l1 = "";
				link.l1.go = "Step_S10_5";
			}

		break;

        case "Step_S10_5":
			if (GetCompanionQuantity(pchar) > 1)
			{
				dialog.text = "Капитаны будут переданы в ваше распоряжение как только вы избавитесь от лишних кораблей в составе вашей эскадры. Вы должны иметь только один ваш корабль.";
				link.l1 = "Я понял"+ GetSexPhrase("","а") +". Буду у вас позже, как только утрясу со своей эскадрой...";
				link.l1.go = "exit";
				pchar.questTemp.State = "Sp9SaveCumana_toCompOut";
			}
			else
			{
				dialog.text = "Галеоны находятся на рейде Порто Белло, а капитаны сию же минуту передаются в ваше распоряжение. Собственно, вы можете приступать к выполнению задания немедленно.";
				link.l1 = "Очень хорошо. Я каким-то образом ограничен"+ GetSexPhrase("","а") +" в сроках?";
				link.l1.go = "Step_S10_6";
			}
        break;
        case "Step_S10_6":
			dialog.text = "Нет, главное - чтобы все галеоны добрались до Каймана в целости и с тем же содержимым трюма, что и сейчас. Я имею в виду золото. Сейчас его в трюмах кораблей 5000 штук, что в мерах веса составляет 10000 центнеров.";
			link.l1 = "Я понимаю. Ну что же, я приступаю к выполнению.";
			link.l1.go = "Step_S10_7";
        break;
        case "Step_S10_7":
            pchar.questTemp.State = "Sp9SaveCumana_toCompOut";
			AddQuestRecord("Spa_Line_9_FourGolgGaleons", "2");
			AddQuestUserData("Spa_Line_9_FourGolgGaleons", "sSex", GetSexPhrase("ен","на"));
            ref sld;
            for (int i=1; i<=4; i++)
            {
                sld = GetCharacter(NPC_GenerateCharacter("Captain_"+i, "trader_"+(rand(15)+1), "man", "man", 15, SPAIN, -1, true, "quest"));
                FantomMakeCoolSailor(sld, SHIP_GALEON_L, "", CANNON_TYPE_CANNON_LBS16, 30, 15, 15);
                FantomMakeCoolFighter(sld, 15, 10, 10, BLADE_SHORT, "pistol1", "bullet", 0);
                sld.Ship.Cargo.Goods.Balls = 48;
                sld.Ship.Cargo.Goods.Grapes = 10;
                sld.Ship.Cargo.Goods.Knippels = 48;
                sld.Ship.Cargo.Goods.Bombs = 48;
                sld.Ship.Cargo.Goods.Weapon = 0;
                sld.Ship.Cargo.Goods.Powder = 80;
				sld.Ship.Cargo.Goods.Food = 300;
				sld.Ship.Cargo.Goods.Gold= 1250;
				SetCharacterRemovable(sld, false);
				sld.CompanionEnemyEnable = false; 
				sld.Abordage.Enable = false; // НЕЛЬЗЯ!
                SetCompanionIndex(pchar, -1, sti(sld.index));
                Pchar.quest.Sp9SaveCumana_toCaimanBattle.win_condition.l1 = "location";
                Pchar.quest.Sp9SaveCumana_toCaimanBattle.win_condition.l1.location = "Caiman";
                Pchar.quest.Sp9SaveCumana_toCaimanBattle.win_condition = "Sp9SaveCumana_toCaimanBattle";
            }
			DialogExit();
        break;
		//************************** Квестовые штрумы ************************

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Вы уже все забрали. Что вам еще нужно?", "Неужели осталось еще что-то, что вы не прихватили?");
            link.l1 = RandPhraseSimple("Осматриваюсь напоследок...", "Проверяю, может забыл"+ GetSexPhrase("","а") +" что забрать...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;

        //==> пиратка, штурм Панамы
        case "PQ8_MayorPortoBello":
			dialog.text = "Дьявол!!! Как быстро вы сумели взять город!";
			link.l1 = "Ха! Понимаю ваше удивление. Но это только начало...";
			link.l1.go = "Step_P1_1";
			AfterTownBattle();
        break;
        case "Step_P1_1":
			dialog.text = "Нам было известно, что готовится нападение на Панаму. Мой город вы взяли, но Панаму вам не взять никогда... Джунгли уничтожат всю вашу стаю.";
			link.l1 = "Это уже не ваша забота. Кстати, а откуда вам стало известно о походе?";
			link.l1.go = "Step_P1_2";
        break;
        case "Step_P1_2":
			dialog.text = "Мне? От генерал-губернатора. А откуда он узнал - понятия не имею.";
			link.l1 = "Ясно. Ну что же, это уже интересно...";
			link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
            Statistic_AddValue(Pchar, NationShortName(sti(NPChar.nation)) + "_TakeTown", 1);
            SetReturn_Gover_Dialog_Exit(NPChar);
            chrDisableReloadToLocation = false;
			AddDialogExitQuestFunction("PQ8_MorganInPortoBello");
        break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

