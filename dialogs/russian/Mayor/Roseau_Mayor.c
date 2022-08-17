// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Что вы хотели? Спрашивайте.", "Я слушаю вас, что за вопрос?"), "Второй раз за день вы пытаетесь задать ворпос...", "В третий раз за день вы опять пытаетесь задать вопрос...",
                          "Да когда же это кончится?! У меня дел полно по управлению делами города, а ты все вопросы пытаешься задать!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал" + GetSexPhrase("","а") + "...", "Не сейчас, не место и не время..."), "Да, верно... Но не сейчас, позже...",
                      "Задам, задам... Только позже...", "Извините, " + GetAddress_FormToNPC(NPChar) + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышали об этом, может что видели, может мысли какие - нибудь?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "JACKSettlement" && !CheckAttribute(npchar, "quest.JACKSettlement"))
			{
				link.l1 = "Я просто пришёл поговорить, разумеется с вашего позволения?";
				link.l1.go = "JACKSettlement";
			}			
		break;

			// Розо или Шарлотт-Таун
 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Мои мысли по поводу разбоев и убийств в этом городе изложены в писменной форме и не для этого Торуса, а для шевалье Филиппа де Пуанси!!!";
		link.l1 = "Ну, я просто хочу разабраться в этом деле?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Я всё сказал! Покиньте мой кабинет!!!";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "JACKSettlement":
        	                  dialog.text = "А, ищейка Торуса! Кроме тебя больше никто здесь не стал бы копаться в чужих делах.\nНу да ладно, я всё понимаю, это рано или поздно должно было произойти... Всё тайное рано или поздно становится явью.\nЯ не сержусь на тебя. Что ты хотел?";
		link.l1 = "Ну, я об этом и хотел поговорить!";
    		link.l1.go = "JACKSettlement_1";
		break;

 		case "JACKSettlement_1":
        	                  dialog.text = "Поговорить хотел... Знаешь, чего мне это стоило? Я ещё юношей вступил во французский легион! На африканском континенте мы уничтожали негров - людей низшей расы. Служили на благо Франции и для захвата и контроля земель, переправляли к себе на родину крепких, здоровых негров в качестве рабов. Крови пролитой было море, но я выжил, получил титулы и награды.";
		link.l1 = "Ну, ты же был солдатом и выполнял приказы!";
    		link.l1.go = "JACKSettlement_2";
		break;

 		case "JACKSettlement_2":
        	                  dialog.text = "Приказы? К черту приказы! Ты знаешь, когда находишься вдали от дома долгое время, на другом континенте, когда вдыхаешь расколённый, но свежий и чистый воздух...\nИ вот по прибытию домой, ты можешь почувствовать родные берега по запаху... По запаху лошадиного навоза, людского дерьма которое течёт по городским улицам...\nСравнивая с бытом других народов я стал понимать насколько мы грязные, вонючие завоеватели, но зато из высшей расы! Ага, конечно... Ладно бы простолюдины, но такой образ везде, в каждом европейце! Будь он француз, англичанин, испанец или голландец... Даже дворяне и короли с королевами все как один нечистоплотные и вонючие!\nМы только сеем раздоры, смерть и болезни - ради ЧЕГО!!! Ради ЧЕГО мы, планомерно уничтожаем целую цивилизацию индейцев, негров ли кого-то ещё? Ради ЧЕГО льётся столько крови, а ведь они нас во многом превосходят по быту, по медицине и у них есть чему поучиться. А ВСЁ РАДИ НАЖИВЫ! Ради денег, товаров, власти... В пекло это всё...";
		link.l1 = "Вот это да, а я и не думал об этом! Ну, а дальше?";
    		link.l1.go = "JACKSettlement_4";
		break;

 		case "JACKSettlement_4":
        	                  dialog.text = "Ну, а дальше, служба на флоте, ордена, титулы и теперь здесь в чине куратора по развитию поселения...\nСколько лет прошло! Сколько событий, а личной жизни - не было! Но здесь на Доминике я встретил женщину... Боже - какая женщина, тело её благоухает цветами, зубы кристально белые, не чета этим европейским девицам, которых доставили сюда со Старого света.\nУ-уу, моя женщина, хотя их и считают людьми низшей расы, но в моих глазах это не так - далеко не так!!!";
		link.l1 = "Понятно, так ты влюблён!";
    		link.l1.go = "JACKSettlement_5";
		break;

 		case "JACKSettlement_5":
        	                  dialog.text = "Да... Но тут такое дело... Я говорю о выборе и понимаю, что будут насмешки, но Торус своё дело знает тонко и чётко, таким палец в рот не кладут - по локать откусят.\nНо ему меня не съесть, я и из более сложных передряг выбирался.";
		link.l1 = "И что ты намерен сделать?";
    		link.l1.go = "JACKSettlement_6";
		break;

                                      case "JACKSettlement_6":
		dialog.text = "Просто, я сниму с себя все полномочия и уйду. И тем самым сохраню любовь и соскочу с крючка Торуса, а все титулы, награды, всё это чушь, никому не нужное кроме своего самолюбия.";
		link.l1 = "Хм, вот это выбор! Выбор достойного человека.";
		link.l1.go = "JACKSettlement_exit";
  		break;

                                      case "JACKSettlement_exit":
		DialogExit();
		AddDialogExitQuestFunction("JACK_SettlementOver_Mayor");
  		break;

                                      case "JACKSettlement_7":
		dialog.text = "Ох, если бы ты только знал, чего мне это стоит? Ну да ладно выбор сделан, ах, да, чуть не забыл, с тобой хочет встретится женщина - индианка, она не простая, дочь Чаки Бокира, Кики племени Шаганумби. Прощай, Торусу передай пламенный привет.";
		link.l1 = "Хм...";
		link.l1.go = "JACKSettlement_8";
  		break;

                                      case "JACKSettlement_8":
		DialogExit();
                                       sld = CharacterFromID("Roseau_Mayor");
                                       LAi_SetActorType(sld);
                                       LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "", 4.0);
		npchar.quest.JACKSettlement = "true";
		pchar.questTemp.JACKSettlement = sti(pchar.questTemp.JACKSettlement)+1;
		if (sti(pchar.questTemp.JACKSettlement) == 2) 
		{
		AddDialogExitQuestFunction("JACK_SettlementOver");
		}
  		break;
		

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

