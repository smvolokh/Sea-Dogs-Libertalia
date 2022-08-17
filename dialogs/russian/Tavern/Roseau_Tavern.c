// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Все сплетни города "+ GetCityName(npchar.city) +" к вашим услугам. Что бы вы хотели узнать?",
                          "Мы только что поднимали это тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Что ты заладил как попугай одно и то же...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, забыл" + GetSexPhrase("","а") + " что-то...",
                      "Да уж, действительно в третий раз...", "Да уж...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// ==> Проверяем поле состояния квестов.
            if (pchar.questTemp.GothicLee == "SeekBible_toBermudes") 
			{				
                link.l1 = HeroStringReactionRepeat("Послушай, я ищу пирата, который продавал здесь Библию какую-то странную. Не слышал об этом деле?",
                "Я про Библию "+ GetSexPhrase("хотел","хотела") +" спросить... уже выяснили, извини.", "Да уж, верно...", "А-а-а, разобрались уже, извини...", npchar, Dialog.CurrentNode);
                link.l1.go = DialogGoNodeRepeat("Gothic_3_1", "", "", "", npchar, Dialog.CurrentNode);
                                                             }

			if (pchar.questTemp.piratesLine == "KillLoy_toBermudes")
			{
				link.l1 = "Здесь, случайно, не появлялся Эдвард Лоу?";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine == "KillLoy_toTavernAgain" || pchar.questTemp.piratesLine == "KillLoy_2toTavernAgain")
			{
				link.l1 = "Я ищу Эдварда Лоу.";
				link.l1.go = "PL_Q3_2";
			}
			if (pchar.questTemp.piratesLine == "PL5Hunter_toBermudes")
			{
				link.l1 = "К тебе в таверну, Джон Эйвори не забегал?";
				link.l1.go = "StepPL5Berm_1";
			}

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышал об этом, может, что видел, может мысли какие - нибудь?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

			if(CheckAttribute(pchar, "questTemp.GothicAscold.Fisk") && pchar.questTemp.GothicAscold.Fisk == "ThreeObject" && !CheckAttribute(npchar, "quest.ThreeObject"))
			{
				link.l1 = "Кардиф мне нужна информация на индейские побрякушки. Спрашиваю у тебя так как вы живёте по соседству с индейцами, возможно кто - нибудь и торгует с ними?";
				link.l1.go = "GothicKardif_ThreeObject";
			}

			// Месть корсара
			if(CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Dominica" && !CheckAttribute(npchar, "quest.RevengeCorsair_Dominica"))
			{
				link.l1 = "Кардиф, я слышал, что вас почтил своим присутствием сам Маркус Тиракс, не подскажешь где он остановился?";
				link.l1.go = "RevengeCorsair_Dominica";
			}

			                    // Одержимые -->
			/*
			if(CheckAttribute(pchar, "questTemp.GothicRumoursObsession") && pchar.questTemp.GothicRumoursObsession == "Obsession" && !CheckAttribute(npchar, "quest.Obsession"))
			                   {
			dialog.text = "Если ты хочешь чего - нибудь выпить - заказывай?";
			Link.l1 = "Бутылку отличного французского вина.";
			Link.l1.go = "Obsession";
				break;
			                  }
			*/
			                    //<-- Одержимые

            // <== Проверяем поле состояния квестов.

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Слышал, только одно, что их зверски убили, тел так и не нашли, кто - то или что - то тут завёлся ты уж мне поверь! Эх, какие были женщины, просто огонь, одна только Розита чего стоила!!!";
		link.l1 = "Значит одну звали Розита, а вторую?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Её подругу? То же штучка та ещё была - звали её Шарлотта.";
		link.l1 = "Понятно. Значит по существу не видел, не слышал? Если, что услышишь - дай знать!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "Непременно. Любой из нас готов отомстить за них.";
		link.l1 = "Хорошо.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "NoKillwork":
        	                  dialog.text = "...";
		link.l1 = "Кардиф мне нужна комната.";
    		link.l1.go = "NoKillwork_1";
		break;

 		case "NoKillwork_1":
        	                  dialog.text = "Комната свободна, проходите.";
		link.l1 = "Благодарю?";
    		link.l1.go = "NoKillwork_2";
		break;

		case "NoKillwork_2":
		                   DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
	                                      LocatorReloadEnterDisable("Roseau_tavern", "reload2_back", false);
		break;

		//Пиратка, квест №3, поиски Лоу
		case "PL_Q3_1":
			dialog.text = "Появлялся. Все ходил, чего-то вынюхивал. То к одному подсядет, то к другому... Кажется, он интересовался нашей верфью.";
			link.l1 = "Благодарю.";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "9");
			pchar.questTemp.piratesLine = "KillLoy_toAlexus";			
		break;

		case "PL_Q3_2":
			dialog.text = "Так вы уже про него спрашивали.";
			link.l1 = "Может, ты чего вспомнил?";
			link.l1.go = "PL_Q3_3";
		break;
		case "PL_Q3_3":
			dialog.text = "Да, чего тут вспоминать, он все про верфь выспрашивал, к людям разным подсаживался. Вон, кстати, Капитан Гудли сидит, он с Лоу разговаривал.";
			link.l1 = "Капитан Гудли?! Спасибо, уже кое-что.";
			link.l1.go = "exit";
			pchar.questTemp.piratesLine = "KillLoy_toGoogly";
		break;
		//Пиратка, квест №5, ОЗГ
		case "StepPL5Berm_1":
			dialog.text = "Да вот, только что и забегал. Спросил, где живет Орри Брюс, и ушел. ";
			link.l1 = "И где же этот Орри Брюс обитает?";
			link.l1.go = "StepPL5Berm_2";
		break;
		case "StepPL5Berm_2":
			dialog.text = "Так, в двухэтажном доме с каменной кладкой он живет. Как выйдешь из таверны, налево первый дом. Там и обитает...";
			link.l1 = "Спасибо, ты мне здорово помог!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_5_Hunter", "10");
			pchar.questTemp.piratesLine = "PL5Hunter_toOrryHouse";
		break;

		//гот. линейка, квест
 		case "Gothic_3_1":
    		dialog.text = "Нет, не слышал.";
    		link.l1 = "Вроде история известная, мне в Сент-Луи ее рассказали.";
    		link.l1.go = "Gothic_3_2";
 		break;
 		case "Gothic_3_2":
    		dialog.text = "Ничего об этом не знаю, у меня в таверне такого не было.";
    		link.l1 = "Спасибо за помощь.";
    		link.l1.go = "exit";
 		break;


		//Аскольд, квест поис 3 побрякушек

 		case "GothicKardif_ThreeObject":
        	                  dialog.text = "А что нужно?";
    		link.l1 = "Нужна статуэтка Тлалока, церемониальный сосуд и церемониальных нож.";
    		link.l1.go = "GothicKardif_ThreeObject_1";
		break;
 		case "GothicKardif_ThreeObject_1":
        	                    dialog.text = "Хм, знаешь, что спроси у Фиска? Он торговец и с индейцами не брезгует торговать...";
    		link.l1 = "Понял, спасибо...";
    		link.l1.go = "GothicKardif_ThreeObject_exit";
		break;
		case "GothicKardif_ThreeObject_exit":
	                   DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ThreeObject = "true";
	                   break;



 		case "Gothic_Roseau_tavernkeeper":
    		dialog.text =  "Все сплетни города "+ GetCityName(npchar.city) +" к вашим услугам. Что бы вы хотели узнать?";
    		link.l1 = "Кардиф мне нужна комната до ночи.";
    		link.l1.go = "Gothic_Roseau_tavernkeeper_1";
 		break;

 		case "Gothic_Roseau_tavernkeeper_1":
 	                               PlaySound("VOICE\Russian\gotica\GG\ROOM_01.wav");
			dialog.text = "Это обойдется вам в 5 песо.";
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = "Идет. Вот твои деньги.";
				link.l1.go = "room_night_wait";
			}
			link.l2 = pcharrepphrase("Ты сдаешь королевские покои? Нет уж, за такую цену я лучше посижу в общей зале.",
            "Увы, видимо, такая роскошь, как сон на кровати, не для моего кошелька. Я переночую в общей зале.");
			link.l2.go = "hall_night_wait";
 		break;

		case "room_night_wait":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddMoneyToCharacter(pchar, -5);
		AddDialogExitQuest("sleep_in_tavern");
		TavernWaitDate("wait_night");
		break;

		case "hall_night_wait":
                                        PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
			if (cRand(3) == 1)
            {
                Dialog.text = "Убирайся, оборван"+ GetSexPhrase("ец","ка") +"! Нечего тут в общей зале просиживать за бесплатно.";
				link.l1 = "Ладно, ладно... уже ухожу.";
				link.l1.go = "exit";
            }
            else
            {
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;
				TavernWaitDate("wait_night");
			}
		break;

		//********************* Месть корсара *********************

   		case "RevengeCorsair_Dominica":
			dialog.text = "Это так, Барон Маркус Тиракс был у нас несколько дней назад, вмете с Торусом организовали такую попойку, жаль тебя не было, но он два дня назад отбыл - куда не могу сказать. Поговори с Торусом.";
			link.l1 = "Понятно, спасибо.";
			link.l1.go = "RevengeCorsair_Dominica_1";
		break;

   		case "RevengeCorsair_Dominica_1":
		dialog.text = "Я таких кораблей как у него не видел...";
		link.l1 = "Да корабль у него, что надо, мне пора.";
		link.l1.go = "exit";
		npchar.quest.RevengeCorsair_Dominica = "true";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_9");
		break;

		//********************* Одержимые *********************
		case "Obsession":
                                    PlaySound("VOICE\Russian\gotica\KARDIF\DIA_KARDIF_HI_14_01.wav");
		dialog.text = "Если ты хочешь чего - нибудь выпить - заказывай?";
		link.l1 = "...";
                                    link.l1.go = "Obsession_1";
		break;

		case "Obsession_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_2.wav");
		dialog.text = "...";
		link.l1 = "Что произошло за последнее время!";
                                    link.l1.go = "Obsession_2";
		break;

		case "Obsession_2":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_19.wav");
		dialog.text = "...";
		link.l1 = "Давай выкладывай!";
                                    link.l1.go = "Obsession_3";
		break;

		case "Obsession_3":
		dialog.text = "Из соседнего поселения индейцев племени Шагонумби, ловцы жемчуга выловили человека в море, после того как привели его в чувство, на его лице был страх и ужас, думали это у него лихорадка, он кричал, бился в сударогах.\nИндейцы провели ритуал над ним, он стал приходить в себя и рассказал, что с ним случилось.\nКак оказалось он моряк, ходил вместе с капитаном Делвином Блейзом на бриге 'Удачливый Джокер'. Не долеко от Доминики на корабле стали происходить страшные вещи, команда при лунном свете стали выглядить живыми мертвецами, напоминающих зомби, от увиденного всего этого он решил сойти с корабля и пробыл в море десять дней.\nЕсли бы не ловцы жемчуга, точно им бы питались крабы!";
		 link.l1 = "А сам, что думаешь по этому...";
                                     link.l1.go = "Obsession_4";
		 break;

		case "Obsession_4":
		dialog.text = "У меня промелькнула одна мысль, которая настораживала здесь некоторое время назад с Розой и Шарллотой, с тем демоном которого вы одолели с Торусом, возможно это звенья одной цепи!";
		 link.l1 = "Ищущий...Да нет с ним всё покончено.";
                                     link.l1.go = "Obsession_5";
		 break;

		case "Obsession_5":
		dialog.text = "События примерно были в одно и тоже время, маяк, бриг. С телом вы разобрались но, что с духом?";
		 link.l1 = "Это всего лишь доводы, сколько он пробыл в воде, десять дней, без воды и пищи, на солнцепеке? Тут любой с ума сойдёт, всякие мысли в голову полезут, это не новости, очередные бредни. Возможно этот моряк бунтарь, вот и отправил Блейз его на корм акулам. Ладно, счастливо...";
                                     link.l1.go = "exit";
		npchar.quest.Obsession = "true";
                                    AddDialogExitQuestFunction("GothicObsessioninStart");
		 break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
