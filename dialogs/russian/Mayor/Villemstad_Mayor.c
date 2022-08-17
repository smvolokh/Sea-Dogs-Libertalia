// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вы хотели? Спрашивайте.", "Я слушаю вас, что за вопрос?"), "Второй раз за день вы пытаетесь задать ворпос...", "В третий раз за день вы опять пытаетесь задать вопрос...",
                          "Да когда же это кончится?! У меня дел полно по управлению делами города, а ты все вопросы пытаешься задать!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Не сейчас, не место и не время..."), "Да, верно... Но не сейчас, позже...",
                      "Задам, задам... Только позже...", "Извините, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal.Villemstad"))
			{
				link.l1 = "Я знаю, что Голландская Вест-Индская торговая Компания назначила хорошую цену за голову одного пирата, а именно - Бартоломео Португальца. Мне удалось схватить его. Сейчас он находится в трюме моего корабля и я готов выдать его властям.";
                link.l1.go = "Portugeze";
			}

			if (pchar.questTemp.LSCC == "toTalkStuvesant")
			{
				link.l1 = "Я хочу спросить об одном человеке. Не откажите в любезности ответить мне.";
				link.l1.go = "TizerFind";
			}
		break;

		case "Cupture_after":
            dialog.text = RandPhraseSimple("Вы уже все забрали. Что вам еще нужно?", "Неужели осталось еще что-то, что вы не прихватили?");
            link.l1 = RandPhraseSimple("Осматриваюсь напоследок...", "Проверяю, может забыл"+ GetSexPhrase("","а") +" что забрать...");
            link.l1.go = "exit";
            NextDiag.TempNode = "Cupture_after";
		break;
		
		//Португалец
		case "Portugeze":
			dialog.text = "Барт Португалец?! Он у вас? Живой?";
			link.l1 = "Я в курсе, что мертвым он вам не нужен. Живой. И мне пришлось приложить немало усилий, черт побери, чтобы он дожил до этого дня!";
			link.l1.go = "Portugeze_1";
		break;
		
		case "Portugeze_1":
			dialog.text = "Великолепно! Теперь он всё расскажет... Минхер, распорядитесь подготовить пленника к перевозке на берег. Мы немедленно подадим военную барку к борту вашего судна.";
			link.l1 = "Я бы хотел сначала обсудить вопрос моей награды, минхер... Если вы не возражаете.";
			link.l1.go = "Portugeze_2";
		break;
		
		case "Portugeze_2":
			dialog.text = "Сударь, вы можете не сомневаться - награду вы получите. За голову Бартоломео Португальца мы установили награду - полторы тысячи золотых дублонов. Лейтенант! Принести господину капитану его вознаграждение!";
			link.l1 = "Хм... Значит, Хьюго соврал мне о двух тысячах дублонов... Ладно, полторы - значит, полторы.";
			link.l1.go = "Portugeze_3";
		break;
		
		case "Portugeze_3":
			TakeNItems(pchar, "gold_dublon", 1500);
			Log_Info("Вы получили 1500 дублонов");
			PlaySound("interface\important_item.wav");
			dialog.text = "А теперь будьте так любезны, капитан, передать Компании Португальца. Нам просто не терпится начать с ним беседу.";
			link.l1 = "Конечно, минхер. Отправляйте барку с солдатами к моему кораблю.";
			link.l1.go = "Portugeze_4";
		break;
		
		case "Portugeze_4":
			DialogExit();
			DoQuestReloadToLocation("Villemstad_town", "reload", "reload1", "Portugal_Final");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+20;
			DeleteAttribute(pchar, "questTemp.Portugal.Villemstad");
		break;

		// --------------------- линейка ГПК, вопрос о Тизере ---------------------
		case "TizerFind":
			dialog.text = "Если я знаю этого человека, то, без сомнения, отвечу вам, капитан.";
			link.l1 = "Меня интересует Тизер Дэн, минхер.";
			link.l1.go = "TizerFind_1";
		break;
		case "TizerFind_1":
			dialog.text = "Очень странно, что вас интересует нищий бродяга, каторжник и бывший раб!";
			link.l1 = "Каторжник?";
			link.l1.go = "TizerFind_2";
		break;
		case "TizerFind_2":
			dialog.text = "Именно так! За участие в смуте он был лишен прав гражданства Нидерландов и сослан на каторгу. Однако, корабль, на котором его перевозили, был захвачен пиратами, а сам этот Тизер был продан ими в рабство...";
			link.l1 = "Черт возьми, какая интересная судьба!";
			link.l1.go = "TizerFind_3";
		break;
		case "TizerFind_3":
			dialog.text = "Не вижу ничего интересного! И почему это вы интересуетесь преступниками?";
			link.l1 = "Минхер, дело все в том, что... В общем, я тут озаботил"+ GetSexPhrase("ся","ась") +" собирательством образцов народного творчества. Хочу, знаете ли, по возвращении в Старый Свет написать книгу о своих приключениях в Новом. Вот так-с... А Тизер - очень колоритная фигура!";
			link.l1.go = "TizerFind_4";
		break;
		case "TizerFind_4":
			dialog.text = "Вы что, серьезно об этом говорите?";
			link.l1 = "Абсолютно. Мне довелось узнать от жителей вашего города о тех байках, которые Тизер рассказывал прилюдно. Очень интересно, знаете ли... Я, конечно, понимаю, что все это враки, но какие занимательные! Идеальный материал для книги.";
			link.l1.go = "TizerFind_5";
		break;
		case "TizerFind_5":
			dialog.text = "Хм, я поощряю сочинительство. Это новые земли, новые герои, новые горизонты бескрайнего мирового океана... М-да, очень интересно. Но от вас, капитан, я никак не ожидал таких наклонностей!";
			link.l1 = "Минхер, вы еще многого обо мне не знаете.";
			link.l1.go = "TizerFind_6";
		break;
		case "TizerFind_6":
			dialog.text = "Понятно. Ну что ж, я был бы рад вам помочь относительно Тизера Дэна, но я не знаю где он. И не имею ни малейшего представления. Дело в том, что этот бродяга не раз нарушал общественный порядок, и я вынужден был применять к нему репрессивные меры. Полагаю, что он убыл с острова.";
			link.l1 = "Печально... И я так понял"+ GetSexPhrase("","а") +", что вы не знаете куда.";
			link.l1.go = "TizerFind_7";
		break;
		case "TizerFind_7":
			dialog.text = "Я уже сказал, что не имею ни малейшего понятия. Я предлагаю вам описать Кюрасао как есть, без идиотских бредней бывшего раба. Поверьте мне, от этого ваше сочинение только выиграет.";
			link.l1 = "Ну что же, я поищу материал на вашем острове. Спасибо вам!";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "toLicencer";
			AddQuestRecord("ISS_PoorsMurder", "9");
			AddQuestUserData("ISS_PoorsMurder", "sSex", GetSexPhrase("ся","ась"));
			AddQuestUserData("ISS_PoorsMurder", "sSex1", GetSexPhrase("","а"));

				sld = GetCharacter(NPC_GenerateCharacter("PoorKillSponsor", "smuggler_boss", "man", "man", 30, PIRATE, -1, true, "quest"));
				sld.name = "Оливер";
				sld.lastname = "Траст";
				FantomMakeCoolFighter(sld, 70, 90, 90, "blade43", "pistol5", "bullet", 12);
				sld.SaveItemsForDead = true;
				sld.Dialog.Filename = "Gothic_Quest\ForAll_dialog.c";
				sld.dialog.currentnode = "Begin_PoorKill";
				sld.nation = HOLLAND;
				sld.city = "Marigo_town";
				sld.location = "Marigo_houseH2";
				sld.location.group = "sit";
				sld.location.locator = "sit1";
				sld.dialog.currentnode = "PKInMarigo";
	                                                          LAi_SetCharacterUseBullet(sld, "cartridge");
                                                                             TakeNItems(sld, "grapeshot", 16);
	                                                          TakeNItems(sld, "bullet", 14);
	                                                          TakeNItems(sld, "cartridge", 21);
	                                                          TakeNItems(sld, "GunPowder", 18);
				LAi_CharacterEnableDialog(sld);
				LAi_RemoveLoginTime(sld);
				sld.standUp = true; //вставать и нападать на врага
				LAi_SetHuberType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}