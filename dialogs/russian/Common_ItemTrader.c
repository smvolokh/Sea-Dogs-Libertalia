#include "DIALOGS\russian\Rumours\Common_rumours.c" //Jason
void ProcessDialogEvent()
{
 	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\ItemTrader\" + NPChar.City + "_ItemTrader.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
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
			if (npchar.angry.name == "AscoldMerchant") Dialog.CurrentNode = "AngryQuest_AscoldMerchant";
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================	   
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
  		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

  		case "First time":

			//зачарованный город -->
			if (pchar.questTemp.MC == "toCaracas" && npchar.city == "Caracas")
			{
				dialog.text = LinkRandPhrase("Я торгую себе здесь и знать не хочу никаких склок. Это не мое дело.", 
					"Да-а, волнения в городе, однако...", 
					"Не думаю, что эти волнения повредят моей торговле. Это хозяину таверны надо беспокоиться.");
				link.l1 = "Ясно.";
				link.l1.go = "exit";
				break;
			}
			if (pchar.questTemp.MC == "toCaracasPadre" || pchar.questTemp.MC == "toCaracasTavern")
			{
				dialog.text = "Говорят, что вы пошли в таверну к этому оборотню! Ну и как там?";
				link.l1 = "Никак...";
				link.l1.go = "exit";
				break;
			}
			//<-- зачарованный город 

			dialog.text = NPCharSexPhrase(npchar, "Хотите прикупить снаряжение для себя или своих офицеров, капитан? Тогда вы обратились по адресу!", "Ой, капитан, я так и знала, что вы подойдете именно ко мне!.. Могу предложить снаряжение для вас и ваших офицеров, а также множество других необходимых вещей.");
			link.l1 = "Покажи, что там у тебя есть.";
			link.l1.go = "Trade_exit";
			
   			link.l2 = "Я по другому делу.";
			link.l2.go = "quests";
			if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "find" && npchar.Merchant.type == "potion" && !CheckAttribute(npchar, "quest.mangarosa"))
			{
				link.l4 = "Послушай, я тут нашел одно интересное растение. Не подскажешь, употребляется ли оно для приготовления каких-нибудь зелий, или отваров? Уж больно интересное. Можешь взглянуть?";
				link.l4.go = "mangarosa";
			}

			//--> eddy. Аскольд, перехват на рендомного перца
			if (pchar.questTemp.Ascold == "Seek_powder")
			{
   				link.l4 = LinkRandPhrase("Тебе не встречалась такая вещь - порошок мумии?", "У тебя в продаже есть порошок мумии?", "Послушай, ты не знаешь, где можно достать порошок мумии?");
				link.l4.go = "AscoldMerchant";
			}
			//<-- eddy. Аскольд, перехват на рендомного перца

			link.l3 = "Спасибо, не интересует.";
			link.l3.go = "exit";

			//Jason --> мини-квест Дефицитный товар
			if (CheckAttribute(pchar, "questTemp.Wine.bottle") && NPChar.location == pchar.questTemp.Wine.City + "_town" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "Скажи, у тебя можно приобрести бутылочку хорошего европейского вина?";
				link.l4.go = "Wine_ItemTrader";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.bottles") && NPChar.location == pchar.questTemp.Wine.City + "_town" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "Послушай, я знаю, что вы торгуете европейским вином. Мне нужно приобрести шестьдесят бутылок.";
				link.l4.go = "Wine_Bottles";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.Repeat1") && NPChar.location == pchar.questTemp.Wine.City + "_town" && npchar.id == pchar.questTemp.Wine.ItemTraderID && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "Это опять я. Как всё это понимать, а?";
				link.l4.go = "Wine_Repeat1";
			}
			// <-- мини-квест Дефицитный товар
			
			//Jason --> генератор Неудачливый вор
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l5 = "Послушай, ты вот торгуешь всякой всячиной... Тебе вчера или сегодня, никто не предлагал купить "+pchar.GenQuest.Device.Shipyarder.Type+"?";
				link.l5.go = "Device_ItemTrader";
			}
			//<-- генератор Неудачливый вор

			NextDiag.TempNode = "First time";
		break;

		case "Trade_exit":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_TRADE\TRADE_" + rand(20) + ".wav");	
            if (CheckNPCQuestDate(npchar, "Item_date"))
			{
				SetNPCQuestDate(npchar, "Item_date");
				GiveItemToTrader(npchar);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(npchar, 0);
		break;
		
		//Jason --> мини-квест Дефицитный товар
		case "Wine_ItemTrader":
			dialog.text = "Есть. Семьсот песо за бутылку.";
			if (makeint(Pchar.money) >= 700)
			{
				link.l1 = "Отлично. Давай ее сюда.";
				link.l1.go = "Wine_ItemTrader_1";
			}
			link.l2 = "Очень хорошо! Как надумаю прикупить - вернусь.";
			link.l2.go = "exit";
		break;
		
		case "Wine_ItemTrader_1":
			dialog.text = "Пожалуйста, получите.";
			link.l1 = "Благодарствую!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -700);
			TakeNItems(pchar, "potionwine", 1);
			PlaySound("interface\important_item.wav");
			DeleteAttribute(pchar, "questTemp.Wine.bottle");
		break;
		
		case "Wine_Bottles":
			dialog.text = "Эка хватил! У меня здесь не оптовая база, а розничный лоток! Я столько бутылок полгода продавать буду - знаешь ли, товар редкий и дорогой, не каждому по карману. Нет у меня такого количества.";
			link.l1 = "Ладно, нет так нет. Но ты-то откуда его берешь? Может, назовешь своего поставщика - я у него и купил бы. Или ты сам"+ NPCharSexPhrase(npchar, "","а") +" из Европы возишь?";
			link.l1.go = "Wine_Bottles_1";
		break;
		
		case "Wine_Bottles_1":
			dialog.text = "Нет, сам"+ NPCharSexPhrase(npchar, "","а") +" не вожу. Беру здесь. Но просто так я тебе своего поставщика не назову. А вот за тысчонку песо... пожалуй, скажу.";
			if (makeint(Pchar.money) >= 1000)
            {
				link.l1 = "Хорошо. Держи свою тысячу и говори, у кого затариваешься.";
				link.l1.go = "Wine_Bottles_2";
			}
			link.l2 = "Ну совсем торгаш"+ NPCharSexPhrase(npchar, "и","ки") +" обнаглели! А жирно тебе не будет? Обойдусь и без твоего поставщика.";
			link.l2.go = "Wine_Bottles_fail";
		break;
		
		case "Wine_Bottles_2":
    		AddMoneyToCharacter(pchar, -1000);
			pchar.questTemp.Wine.TraderID = pchar.questTemp.Wine.City +"_trader";
			sld = characterFromId(pchar.questTemp.Wine.TraderID);
			pchar.questTemp.Wine.Name = GetFullName(sld);
			pchar.questTemp.Wine.ItemTraderID = npchar.id;
			dialog.text = "Моего поставщика вина зовут "+pchar.questTemp.Wine.Name+", он хозяин местного магазина.";
			link.l1 = "Все понял. Спасибо!";
			link.l1.go = "exit";
			pchar.questTemp.Wine.Trader = "true";
			DeleteAttribute(pchar, "questTemp.Wine.bottles");
			AddQuestRecord("Wine", "3");
			AddQuestUserData("Wine", "sName", pchar.questTemp.Wine.Name);
		break;
		
		case "Wine_Bottles_fail":
			dialog.text = "Как знаете, капитан. Всего доброго.";
			link.l1 = "Бывай.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Wine.bottles");
			AddQuestRecord("Wine", "4");
		break;
		
		case "Wine_Repeat1":
			DeleteAttribute(pchar, "questTemp.Wine.Repeat1");
			dialog.text = "Что понимать? Объясните внятно, пожалуйста.";
			link.l1 = "Ты обманул"+ NPCharSexPhrase(npchar, "","а") +" меня, проклят"+ NPCharSexPhrase(npchar, "ый","ая") +" мерзав"+ NPCharSexPhrase(npchar, "ец","ка") +"! Я только что был в магазине, "+pchar.questTemp.Wine.Name+" никогда вином не торговал - он сам мне это сказал! Гони назад мои деньги!";
			link.l1.go = "Wine_Repeat1_fail";
			link.l2 = "Тут ерунда какая-то вышла... Прихожу я в магазин, а "+pchar.questTemp.Wine.Name+" заявляет, что никогда вином не торговал. Как вы объясните это?";
			link.l2.go = "Wine_Repeat1_1";
		break;
		
		case "Wine_Repeat1_1":
			dialog.text = "Хех! Он торгует вином, уверяю вас. Вот только каждому встречному он это вино, как и некоторые другие товары, не продает. И причины на это имеются... Если хотите, чтобы он продал вам вино - я могу написать записку - меня он знает, мой почерк тоже, так что прочитав ее, продаст вам вина, как вы и хотите. Конечно, эта услуга с моей стороны тоже не бесплатная.";
			link.l1 = "Вот так номер! Но вы же только что взяли с меня тысячу!";
			link.l1.go = "Wine_Repeat1_2";
		break;
		
		case "Wine_Repeat1_2":
			dialog.text = "Тысячу я с вас взял"+ NPCharSexPhrase(npchar, "","а") +" за информацию. А за письмо вам надо заплатить отдельно - две тысячи песо, и никак не меньше.";
			if (makeint(Pchar.money) >= 2000)
			{
				link.l1 = "Ох... Ну до чего же вы, торгаш"+ NPCharSexPhrase(npchar, "и","ки") +", жадные. Недаром вас, барыг, не любят. Держите ваши деньги и пишите записку.";
				link.l1.go = "Wine_Bottles_3";
			}
			link.l2 = "Ну это уже ни в какие ворота не лезет. Да я лучше брошу всем этим заниматься, но не стану обогощать так"+ NPCharSexPhrase(npchar, "ого","ую") +" хитр"+ NPCharSexPhrase(npchar, "ого","ую") +" скрягу. Я имею в виду вас. Прощайте.";
			link.l2.go = "Wine_Repeat1_goaway";
		break;
		
		case "Wine_Bottles_3":
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = "Вы странный человек, капитан! Я конечно, понимаю, что всеми финансами у вас на корабле ведает казначей, но вы могли бы и сами думать иногда. Вы сейчас пойдете и купите приличную партию вина без моей торговой наценки, по оптовой цене, и получите немалый барыш. Так что давайте не будем мешать зарабатывать друг другу - ибо жадным сейчас выглядите именно вы\nТак...(пишет)... Вот, возьмите это письмо - теперь "+pchar.questTemp.Wine.Name+" продаст вам вино без всяких лишних вопросов.";
			link.l1 = "Буду на это надеятся... Если что - я вернусь! До свидания!";
			link.l1.go = "Wine_Bottles_4";
		break;
		
		case "Wine_Bottles_4":
			pchar.questTemp.Wine.Repeat2 = "true";
			TakeNItems(pchar, "letter_1", 1);
			ChangeItemDescribe("letter_1", "itmdescr_letter_1");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Wine", "6");
			DialogExit();
		break;
		
		case "Wine_Repeat1_goaway":
			dialog.text = "Как знаете, капитан. Прощайте.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Wine", "4");
		break;
		
		case "Wine_Repeat1_fail":
			dialog.text = "Ах, вы хамить и угрожать мне тут вздумали? Я сейчас стражу позову! Стра-ажа!! Сюда!";
			link.l1 = "Да заткнись ты! Ладно, я ухожу! Будь ты проклят"+ NPCharSexPhrase(npchar, "","а") +", сквалыга, чтоб тебе по миру пойти!";
			link.l1.go = "exit";
			AddQuestRecord("Wine", "7");
		break;
		// <-- мини-квест Дефицитный товар
		
		//Jason --> генератор Неудачливый вор
		case "Device_ItemTrader":
			dialog.text = "Гм, "+pchar.GenQuest.Device.Shipyarder.Type+"? Впервые слышу... Хоть что это за вещь такая - сколько живу на свете, ничего подобного в глаза не видел"+ NPCharSexPhrase(npchar, "","а") +".";
			link.l1 = "Ну, это судостроительный инструмент, "+pchar.GenQuest.Device.Shipyarder.Describe+". Никто ничего подобного тебе не предлагал?";
			link.l1.go = "Device_ItemTrader_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_ItemTrader_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) > 0 && sti(pchar.GenQuest.Device.Shipyarder.Chance1) < 4 && npchar.location.group == "merchant" && npchar.location.locator == "merchant"+sti(pchar.GenQuest.Device.Shipyarder.Chance1))
			{
				dialog.text = "Хм... Да, приносил мне такую вещь один странный тип. Только он ее никак не назвал, а просто пытался мне продать. Да только зачем она мне, если я даже не знаю, для чего она нужна? Как я ее потом продать сумею? В общем, отказал"+ NPCharSexPhrase(npchar, "","а") +" я ему, и он ушел.";
				link.l1 = "А как выглядел этот человек и куда пошел? Мне очень нужен этот инструмент.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "Нет, никто не приносил. Так что помочь ничем не могу. Поспрашивай еще у кого.";
				link.l1 = "Ясно. Пойду спрашивать!";
				link.l1.go = "exit";
			}
		break;
		// <-- генератор Неудачливый вор
		
		// Мангароса
		case "mangarosa":
			// тут работает везение
			if (sti(pchar.questTemp.Mangarosa.m_count) == 5 || GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 10+drand(30)+drand(40))
			{
				dialog.text = "Покажите... Да, растение интересное. И, что главное - очень, очень редкое. Его называют мангароса. Для чего его используют - я не знаю, но с ним связан один любопытный факт...";
				link.l1 = "Что ты имеешь в виду?";
				link.l1.go = "mangarosa_1";
			}
			else
			{
				dialog.text = LinkRandPhrase("Покажите... Да, растение интересное. Но подсказать вам ничего определенного не могу. Область его применения, если таковая и есть, мне неведома.","Давайте посмотрим... Хм. Похоже на лекарственное, но оно мне незнакомо. Так что ничем не могу помочь.","Где оно? Так-так... нет, не встречалось мне такое никогда. На вид очень занятное, но для чего его можно использовать - не представляю...");
				link.l1 = "Ясно. Буду спрашивать еще. Извини...";
				link.l1.go = "mangarosa_exit";
			}
		break;
		
		case "mangarosa_exit":
			DialogExit();
			pchar.questTemp.Mangarosa.m_count = sti(pchar.questTemp.Mangarosa.m_count)+1;
			npchar.quest.mangarosa = "true";
		break;
		
		case "mangarosa_1":
			dialog.text = "Этим растением интересуются бродячие цыганки и дикари. Мне доводилось видеть, как цыганка отсыпала целую пригоршню золотых всего за один вот такой стебель. Зачем оно им нужно - я не знаю.";
			link.l1 = "Так-так... Ну, уже что-то! По крайней мере, я знаю, у кого дальше выспрашивать. Спасибо огромное!";
			link.l1.go = "mangarosa_2";
		break;
		
		case "mangarosa_2":
			DialogExit();
			npchar.quest.mangarosa = "true";
			DeleteAttribute(pchar, "questTemp.Mangarosa.m_count");
			pchar.questTemp.Mangarosa = "gipsy";
			AddQuestRecord("Mangarosa", "2");
		break;

		//Квест Аскольда. Базары с уличными торговцами
		case "AscoldMerchant": 
			if(npchar.city == pchar.questTemp.Ascold.MerchantColony && npchar.location.locator == "merchant1")
			{
				dialog.text = "Порошок мумии? Я не знаю, что такое мумия.";
				link.l1 = "Это бальзамированное тело усопшего много тысячелетий назад египтянина.";
				link.l1.go = "AscoldMerchant_2";
			}
			else
			{
				dialog.text = NPCStringReactionRepeat(LinkRandPhrase("Порошок мумии? Я не знаю, что такое мумия.", "Порошок чего? Мумии? Что это такое?", "Порошок мумии? Что за вещица такая?"),
                     LinkRandPhrase("Опять ты спрашиваешь меня об этом?", "Снова ты начинаешь разговор о том же...", "И опять об этом порошке?"),
                     LinkRandPhrase(NPCharSexPhrase(npchar, "Я же ответил тебе на этот вопрос! Чего ты еще хочешь?", "Я же ответила тебе на этот вопрос! Чего ты еще хочешь?"),
                                    NPCharSexPhrase(npchar, "Я уже сказал тебе все, что считаю нужным. Опять эти странные вопросы?", "Я уже сказала тебе все, что считаю нужным. Опять эти странные вопросы?"),
                                    "Опять эти странные вопросы? Мне нечего добавить к сказанному ранее!"),
                     LinkRandPhrase("Опять?!! Опять?!!", "Слов просто нет!!! Опять?!", "Снова ты об этом проклятом порошке?!"), "quest", 10, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Это бальзамированное тело усопшего много тысячелетий назад египтянина.",
                                               "Ага, спрашиваю. Может, вспомнилось что-нибудь?",
                                               "Еще раз спрашиваю, может, изменилось что...",
                                               "Ага, снова спрашиваю.", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("AscoldMerchant_2", "AscoldMerchant_3", "AscoldMerchant_4", "", npchar, Dialog.CurrentNode);
			}
		break;
		
		case "AscoldMerchant_2":
			dialog.text = LinkRandPhrase("Не-е-ет, такого добра нам не надо. Не доводилось встречать. И вообще, ты перв"+ GetSexPhrase("ый","ая") +", кто спрашивает такой странный товар. Не думаю, что торговля такими предметами понравится Святой Церкви. Это, знаешь ли, не шутки...",
                     NPCharSexPhrase(npchar, "Нет, не было такого товара. Даже если бы встретился, то не взял бы. Я регулярно посещаю церковь, не думаю, что Инквизиции понравится торговля такими вещами.", "Нет, не было такого товара. Даже если бы встретился, то не взяла бы. Я исправная прихожанка, не думаю, что Инквизиции понравится торговля такими вещами."),
                     NPCharSexPhrase(npchar, "Не встречал ничего подобного. И, полагаю, это к лучшему. Если моя жена узнает, то сразу же побежит к инквизиторам...", "Не встречала ничего подобного. И, полагаю, это к лучшему. Мой муж не будет в восторге от такой моей торговли..."));
			Link.l1 = "Да? Ну ладно, нет - так нет...";
			Link.l1.go = "exit";

		break;
		
		case "AscoldMerchant_3":
			dialog.text = LinkRandPhrase(NPCharSexPhrase(npchar, "Ничего я не запамятовал. Не знаю я ничего ни о каких мумиях и знать не желаю. И тебе не рекомендую этим промышлять. А то часом обвинят в колдовстве, от церкви отлучат...", "Ничего я не запамятовала. Не знаю я ничего ни о каких мумиях и знать не желаю. И тебе не рекомендую этим промышлять. А то часом обвинят в колдовстве, от церкви отлучат..."),
                                    "Все я прекрасно помню. Но о мумиях говорить не хочу. Святой Инквизиции бы этим делом заняться...",
                                    NPCharSexPhrase(npchar, "Все я помню хорошо. М-да, знала бы моя жена о таких предложениях - давно бы Святая Инквизиция занималась этим...", "Я все помню хорошо. И думаю, что надо бы мужа позвать..."));
			Link.l1 = "Агарх!! Странные вещи говоришь. Ну да ладно...";
			Link.l1.go = "exit";
		break;
		
		case "AscoldMerchant_4":
			dialog.text = LinkRandPhrase(NPCharSexPhrase(npchar, "Ничего не изменилось, ровным счетом ничего!!! Не видел я египетских покойников ни в целом, ни в истолченном виде!", "Ничего не изменилось, ровным счетом ничего!!! Не видела я египетских покойников ни в целом, ни в истолченном виде!"),
                                    NPCharSexPhrase(npchar, "Абсолютно ничего не изменилось - никаких истолченных трупов я не видел и, надеюсь, не увижу.", "Абсолютно ничего не изменилось - никаких истолченных трупов я не видела и, надеюсь, не увижу. А будешь приставать с идиотскими вопросам - мужа позову..."),
                                    NPCharSexPhrase(npchar, "Изменилось?!! Послушай, я же ясно выразился! Неужели не понятно, что с покойниками, истолченными или целыми, я не связываюсь?!!", "Изменилось?!! Послушайте, я же все совершенно ясно сказала! Неужели не понятно, что с покойниками, истолченными или целыми, я не связываюсь?!!"));
			Link.l1 = NPCharSexPhrase(npchar, "Да ты не нервничай так. Успокойся, не видел - так не видел...", "Да ты не нервничай так. Успокойся, не видела - так не видела...");
			Link.l1.go = "exit";
		break;

		case "AscoldMerchant_5":
			dialog.text = "То-то и оно... И не скажет никто. Инквизиция за куда меньшие пригрешения со свету сжить может. А уж за такое и подавно. Кому ж охота за свой длинный язык жизнью платить?";
			link.l1 = "Н-да... а может, подскажешь чего? Очень нужно. Один человек заказ сделал, а я вот уже сколько времени найти не могу.";
			link.l1.go = "AscoldMerchant_6";
		break;
		
		case "AscoldMerchant_6":
			dialog.text = "Заказ, говоришь? А не инквизиторская ли ищейка твой заказчик?";
			link.l1 = "Да нет, не похоже... Солидный продавец солидного магазина. Зачем бы ему это?!";
			link.l1.go = "AscoldMerchant_7";
		break;
		
		case "AscoldMerchant_7":
			dialog.text = "Действительно не похоже... Что ж, продам я тебе порошок. Только не вздумай сболтнуть кому. Учти, что я тебя знать не знаю и на страшном суде отпираться буду.";
			link.l1 = "Ну, это и так понятно...";
			link.l1.go = "AscoldMerchant_8";
		break;
		
		case "AscoldMerchant_8":
			dialog.text = "С тебя тысяча песо.";
			if (sti(pchar.money) >= 1000)
			{
				Link.l1 = "Недёшево, однако, но тут и не поторгуешься. Вот, держи.";
    		    Link.l1.go = "exit";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");			
			}
			else
			{
				link.l1 = "Вот чёрт! у меня с собой нет столько. Сейчас соберу и сразу к тебе. Смотри, не продай, пока я бегать буду...";
				link.l1.go = "exit";
			}
		break;
		
// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryQuest_AscoldMerchant":
            Dialog.text = RandPhraseSimple("Я не хочу с тобой больше иметь дело.", "Больше я тебе ничего продавать не буду.");
			Link.l1 = RandPhraseSimple("Ну, как знаешь. По всему видать, деньги тебе не нужны.", "Невелика потеря...");
		    Link.l1.go = "AngryExitAgain";
		    //===>> квест Аскольда, розыск порошка мумии.
            if (pchar.questTemp.Ascold == "Seek_powder" && npchar.city == pchar.questTemp.Ascold.MerchantColony && npchar.location.locator == "merchant128")
            {
                Dialog.text =  "Ты очень настойчив"+ GetSexPhrase("","а") +", видимо этот порошок тебе действительно нужен.";
    			Link.l1 = "Именно так. А теперь я хочу знать, есть ли он у тебя на самом деле. И не бойся, все останется между нами.";
    		    Link.l1.go = "AngStep_1";
            }
            if (CheckAttribute(npchar, "angry.terms")) //мирилка по квесту Аскольда через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms) && pchar.questTemp.Ascold != "Seek_powder")
                {
         			Dialog.text = NPCharSexPhrase(npchar, "Очень рассчитываю на то, что ты не будешь меня утомлять странными просьбами. Пожалуй, я готов вести дела с тобой.", "Очень надеюсь на то, что ты не будешь приставать ко мне с этими ужасными трупными покупками. Пожалуй, я готова торговать с тобой.");
        			Link.l1 = RandPhraseSimple("Здорово!", "Превосходно!");
        			Link.l1.go = "First time";
        			CharacterDelAngry(npchar);
                }
            }
    	break;
////////////////////////////////////////////////////////////////////////////////////////////////
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok")
		break;

		case "AngStep_1":
            Dialog.text = "Есть, но не для всех, сам"+ GetSexPhrase("","а") +" понимаешь. Но тебе продам. Тысяча монет, и он твой.";
            if (sti(pchar.money) >= 1000)
            {
    			Link.l1 = "Хорошо, вот твои деньги.";
    		    Link.l1.go = "AngryExitAgain";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    CharacterDelAngry(npchar);
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");
            }
            else
            {
    			Link.l1 = "Сейчас у меня с собой нет такой суммы. Как только соберу - сразу же навещу тебя.";
    		    Link.l1.go = "AngryExitAgain";
            }
    	break;
// <<<<<<<<<<<<============= блок нод angry =============================
	}
}
