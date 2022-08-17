// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Некоторое время тому назад, находясь у меня в магазине, вы пытались задать какой-то вопрос...", "За сегодня третий вопрос. Мне торговать надо, а не пустые разговоры вести...",
                          "Опять вопросы? Может лучше торговлей займемся?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Сейчас мне не о чем говорить"), "Да, точно, пытался... Находясь в магазине...",
                      "Да уж, действительно в третий раз...", "Хм, может и поторгуем...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicAscold.Fisk") && pchar.questTemp.GothicAscold.Fisk == "ThreeObject" && !CheckAttribute(npchar, "quest.ThreeObject"))
			{
				link.l1 = "Фиск, хочу у тебя попросить помощи. Мне позарез нужны индейские побрякушки.";
				link.l1.go = "Gothic_FISK";
			}
			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Фиск, ничего не слышал о убийсве женщин из борделя, может, что видел?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Я уже всё рассказал Торусу, не видел, не слышал.";
		link.l1 = "Ну, может кто в трактире слухи распускает, мыслишками кто какими делится!!!";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Нет не слышал, в трактире так же все только пожимают плечами, но я думаю не человек это сделал, какой - то зверь?";
		link.l1 = "То, что зверь это ты точно подметил. Ладно я тебя понял.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;


 		case "Gothic_FISK":
        	                  dialog.text = "У меня в лавке много чего есть, а вот побрякушек нет.";
    		link.l1 = "Ты не кипятись. Все дело в том, что я ищу три предмета индейского культа. Для покупки. Все одно - вы либо выбрасываете эту дрянь, либо продаете за бесценок. Я готов заплатить щедро за эти вещи, если они у вас есть.";
    		link.l1.go = "Gothic_FISK_2";
		break;
 		case "Gothic_FISK_2":
        	                    dialog.text = "Говорите тише, я тебя прекрасно понял. Слышал, что Генерал Ли заинтерисован в этих штучках, он их коллекционирует?";
    		link.l1 = "Ну вот, уже хоть что-то.";
    		link.l1.go = "Gothic_FISK_3";
		break;
 		case "Gothic_FISK_3":
        	                    dialog.text = "Видать всё мечтает о мести королю Рабару, глупо, нам от сюда назад дороги нет, не помогут ни ему ни нам эти побрякушки, да и шаманы местные бессильные.";
    		link.l1 = "Надежда должна быть?";
    		link.l1.go = "Gothic_FISK_4";
		break;
 		case "Gothic_FISK_4":
        	                    dialog.text = "Ох, я тебя умоляю во имя Инноса и ты туда же? А между прочим здесь по ночам жуткие стоны, каких я в Харинисе не слышал.";
    		link.l1 = "Что за стоны?";
    		link.l1.go = "Gothic_FISK_5";
		break;
 		case "Gothic_FISK_5":
        	                    dialog.text = "Я и говорю, жуткие.";
    		link.l1 = "Ладно, бывай!";
    		link.l1.go = "Gothic_FISK_6";
		break;

		case "Gothic_FISK_6":
	                DialogExit();
		LocatorReloadEnterDisable("Roseau_town", "reload1_back", true);//город закрыть
		LocatorReloadEnterDisable("Roseau_town", "gate_back", true);//город закрыть
                                       DoQuestFunctionDelay("Roseau_night", 0.1);
		npchar.quest.ThreeObject = "true";
		sld = CharacterFromID("Roseau_tavernkeeper");
		sld.dialog.currentnode = "Gothic_Roseau_tavernkeeper";
 
	                pchar.quest.Roseau_Fisk.win_condition.l1 = "locator";
	                pchar.quest.Roseau_Fisk.win_condition.l1.location = "Roseau_town";		                                   pchar.quest.Roseau_Fisk.win_condition.l1.locator_group = "reload";
	                pchar.quest.Roseau_Fisk.win_condition.l1.locator = "reload6_back";
	                pchar.quest.Roseau_Fisk.function = "Roseau_night_0";
	                break;

	}
	UnloadSegment(NPChar.FileDialog2);
}

