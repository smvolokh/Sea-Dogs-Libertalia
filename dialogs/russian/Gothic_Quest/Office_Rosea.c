// НПС офиса пиратов
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	string sTemp,sTemp1, str, str1;
	int	s1,s2,s3,s4,s5,p1,iColony;
	int i;
                    string attrLoc;
                    attrLoc   = Dialog.CurrentNode;
  
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Вы что-то хотели?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";

		break;
		
		// офицер
		case "W_officer":

				dialog.text = "Ах, как скучно в нашем городишке. Может быть, такой видный капитан как вы, развеет мою скуку? Что вам угодно?";
				link.l1 = "Я зашел по торговым делам. Лицензии, корабельные приборы и прочее...";
				link.l1.go = "W_officer_1";
				link.l2 = "Безусловно! С радостью развлеку такую прекрасную даму.";
				link.l2.go = "toHostessSex";
				link.l3 = "К сожалению, мне некогда, " + npchar.name + ". Как-нибудь в другой раз...";
				link.l3.go = "W_officer_exit";
				break;

		case "exit1":
				dialog.text = "В прошлый раз, когда я ждала тебя в комнате, ты не пришел... Ты упустил свой шанс.";
				link.l1 = "Эх, жаль...";
				link.l1.go = "W_officer";
				break;				
		
		case "W_officer_1":
			dialog.text = "Это Вам к месье Раймондэ Оберто. Он за столом на втором этаже. Он занимается всеми делами с торговыми капитанами. Работает он с одиннадцати до четырёх часов по полудни.";
			link.l1 = "Спасибо, милашка, вы очень любезны...";
			link.l1.go = "W_officer_exit";
		break;
		
		case "W_officer_exit":
			DialogExit();			
			NextDiag.TempNode = "W_officer";
		break;
		

		
		// клерки
		case "W_clerk":
			if (LAi_grp_playeralarm > 0)
			{
				dialog.text = "Тревога! Враг в помещении! Солдаты!";
				link.l1 = "А-ать!";
				link.l1.go = "fight";
				break;
			}
			dialog.text = "Если вам что-то нужно - поговорите с месье Диолье.";
			link.l1 = "Хорошо, я понял" + GetSexPhrase("","а") + ".";
			link.l1.go = "exit";			
			NextDiag.TempNode = "W_clerk";
		break;
		
		// главный клерк 
		case "W_headclerk":

			dialog.text = "Вы что-то хотели, " + GetSexPhrase("сударь","мадмуазэль") + "?";
			if (!CheckCharacterItem(pchar, "PirTradeLicence"))
			{
				link.l1 = "Я хочу приобрести торговую лицензию Голландской Вест-Индской Компании.";
				link.l1.go = "licence";
				link.l2 = "Я хочу приобрести у Вас комлект корабельных флагов для торговых целей.";
				link.l2.go = "flags";		
			}
			if (!CheckAttribute(npchar, "quest.trade"))
			{
				link.l3 = "Я слышал, что у вас можно приобрести корабельные приборы и прочие полезные вещи. Это так?";
				link.l3.go = "trade";	
			}
			else
			{
				link.l3 = "Что у вас сегодня имеется в продаже? Покажите, пожалуйста.";
				link.l3.go = "trade_1";	
			}

			//линейка ГПК, поиски торгашей -->
			if (pchar.questTemp.LSCC == "toLicencer")
			{
				link.l4 = "У меня есть к вам вопрос по поводу Голландской Вест-Индской компании.";
				link.l4.go = "SeekHVIC";
			}
			if (pchar.questTemp.LSCC == "toLicencer_2")
			{
				link.l4 = "Хм, прошу прощения за свою дырявую голову. Я снова по поводу Голландской Вест-Индской компании.";
				link.l4.go = "SeekHVIC_3";
			}

			link.l9 = "Нет, пока ничего.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "W_headclerk";
		break;
		
		// торговые лицензии
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "Ну что же, пожалуйста, приобретайте. Но я считаю должным вас предупредить, что Компания дорожит своим именем, поэтому к лицензиатам предъявлются определенные требования на весь срок действия лицензии, а именно - никаких агрессивных действий в отношении торговых кораблей любой нации\nВ случае выявления такого факта ваша лицензия будет немедленно аннулирована. Также вы лишитесь документа, если по каким-то причинам, неважно каким, вступите в конфликт с Голландией. Это понятно?";
				link.l1 = "Безусловно. Я приму это к сведению.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "Ну что же, пожалуйста, приобретайте. На какой срок вы хотите получить лицензию?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;
		
		case "licence_0":
			dialog.text = "Лицензия дает право беспрепятственного входа в любой порт любой нации, поскольку подтверждает ваши мирные намерения и объясняет цель вашего прибытия - торговать. Однако если у вас есть проблемы с законом у той страны, в порт которой вы намерены явиться, лицензия вам не поможет. Более того - у вас ее просто изымут. Учтите это\nЕсли вы собираетесь торговать с враждебной вам державой - не забудьте перед входом в порт поднять дружественный флаг - это избавит вас от ненужных проблем, поскольку канониры фортов и патрули в городах имеют склонность сначала стрелять, и только потом разбираться\nДа, чуть не забыл: согласно устоявшейся традиции, оплата за лицензию производится исключительно золотыми дублонами... Ну, теперь, наверное, все прояснили. На какой срок вы хотите получить лицензию?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l2.go = "exit";
		break;
		
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			//npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*1000;
			// вариант с дублонами
			if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*3;
        else npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "Месье, пожалуйста, говорите четче, не заикайтесь и не мямлите. Я вас плохо расслышал. Так на сколько дней вам нужна лицензия?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "Минимальный срок, на который мы выдаем лицензию - двадцать дней. На сколько суток вам выписать - на двадцать, или больше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "Максимальный срок, на который мы выдаем лицензию - полгода. На сколько суток вам выписать - на сто восемьдесят, или меньше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "На "+FindRussianDaysString(sti(fQty))+"? Хорошо. Стоимость такой лицензии составит "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
			//if (sti(pchar.money) >= sti(npchar.quest.lcc_summ))
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "Да, конечно, устраивает.";
				link.l1.go = "licence_2";
			}
			link.l2 = "К сожалению, у меня нет сейчас с собой столько денег. Я зайду к вам за лицензией позже.";
			link.l2.go = "exit";
		break;
		
		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l2.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			//AddMoneyToCharacter(pchar, -sti(npchar.quest.lcc_summ));
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "Так, одну минуту... Сейчас поставим подпись и печать... Вот, готово. Получите ваш документ.";
			link.l1 = "Спасибо! До свидания, месье.";
			link.l1.go = "exit";
		break;
		
		case "trade":
			dialog.text = "Слухи вас не обманули. Здесь вы можете приобрести навигационные приборы, такие как корабельный компас, астролябия, хронометр и песочные часы для настройки хронометра по времени острова Форро. Однако в наличии они бывают не всегда, за исключением разве что песочных часов - разбирают, понимаете ли. Так что если не удалось купить, что хотели - зайдите через недельку\nТакже периодически у нас в продаже появляются карты архипелага и подзорные трубы. Желаете посмотреть ассортимент на сегодня?";
			link.l1 = "Да, будьте так любезны.";
			link.l1.go = "trade_1";
			npchar.quest.trade = "true";
		break;
		
		case "trade_1":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 7)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);			
		break;
		
		// депеша Кромвеля
		case "depeshe":
			dialog.text = "Хм, покажите...(читает) Так-так... Значит, Кромвелю мало того, что он устроил в Англии... Вот наглецы! Где вы достали эту депешу?";
			link.l1 = "Перехватил у одного английского курьера. Ну так что, будете ее покупать?";
			link.l1.go = "depeshe_1";
		break;
		
		case "depeshe_1":
			dialog.text = "Да. Питер Стайвесант будет рад ее прочесть, я уверен. Как и принять адекватные меры... Я могу заплатить золотом, или выписать вам торговую лицензию на максимальный срок - полгода. Что выбираете?";
			link.l1 = "Я выбираю золото.";
			link.l1.go = "depeshe_dublon";
			link.l2 = "Я хочу торговую лицензию.";
			link.l2.go = "depeshe_licence";
		break;
		
		case "depeshe_dublon":
			TakeNItems(pchar, "gold_dublon", 700);
			Log_Info("Вы получили 700 дублонов");
			dialog.text = "Хорошо. Вот семьсот дублонов. Больше я заплатить вам за эту депешу в любом случае не смогу.";
			link.l1 = "Пожалуйста, забирайте. Вот ваша депеша.";
			link.l1.go = "depeshe_exit";
		break;
		
		case "depeshe_licence":
			if (CheckCharacterItem(pchar, "FraTradeLicence")) TakeNationLicence(HOLLAND);
			GiveNationLicence(HOLLAND, 180);
			dialog.text = "Хорошо. Вот ваша лицензия на полгода.";
			link.l1 = "Спасибо! А вот ваша депеша.";
			link.l1.go = "depeshe_exit";
		break;
		
		case "depeshe_exit":
			RemoveItems(pchar, "Cromvel_depeshe", 1);
			pchar.quest.Terrapin_CromvelScuadron.over = "yes"; //снять прерывание
			ChangeCharacterNationReputation(pchar, HOLLAND, 15);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 2);
			dialog.text = "Благодарю. Похвально, что вы проявили сознательность и лояльность по отношению к Голландии. Я сообщу о вашем поступке Матиасу Беку и Питеру Стайвесанту.";
			link.l1 = "Вы уже и так отплатили сполна, но я не возражаю. До свидания!";
			link.l1.go = "exit";
		break;
		
		// новый босс ГВИК
		case "HWIC_Boss":
			if (!CheckAttribute(npchar, "quest.silk_info") && sti(pchar.reputation.nobility) > 60)
			{
				dialog.text = "А-а, капитан " + GetFullName(pchar) + "! Очень хорошо, что вы ко мне зашли. У меня для вас есть деловое предложение.";
				link.l1 = "Очень занятно! Внимательно вас слушаю, минхер.";
				link.l1.go = "silk_info";
				break;
			}
			dialog.text = "Здравствуйте, капитан " + GetFullName(pchar) + "! Чем могу служить?";
			if(CheckAttribute(npchar, "quest.silk")) // торговля шелком
			{
				if (GetDataDay() == 1 || GetDataDay() == 15)
				{
					link.l1 = "Я по поводу корабельного шелка...";
					link.l1.go = "trade_silk";
				}
			}
			link.l2 = "Добрый день. Нет, ничего не надо - я просто зашел поприветствовать вас.";
			link.l2.go = "exit";			
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "silk_info":
			dialog.text = "Я недавно наладил торговые связи с одним купцом из Лиона и договорился о поставках на Карибы партий корабельного шелка. Вы знаете, что это за товар? Из него изготавливают самые лучшие на свете паруса, так что вам это наверняка будет интересно.";
			link.l1 = "Согласен, это интересное предложение. Каковы условия?";
			link.l1.go = "silk_info_1";
		break;
		
		case "silk_info_1":
			dialog.text = "Поставки у меня идут регулярно, но в небольших объемах. Для вас я могу оставлять по тридцать рулонов товара каждые две недели. Стоимость одного рулона - двадцать золотых дублонов. Давайте поступим так: каждого первого и пятнадцатого числа месяца я буду придерживать для вас тридцать рулонов. Если вы не придете за ними в эти дни - я продаю другому покупателю.";
			link.l1 = "То есть никаких обязательств я не несу?";
			link.l1.go = "silk_info_2";
		break;
		
		case "silk_info_2":
			dialog.text = "Именно! Хотите - покупаете, хотите - нет. Всю партию оплачиваете полностью - шестьсот дублонов. Надеюсь, вы станете моим постоянным покупателем.";
			link.l1 = "Спасибо за предложение, минхер. Думаю, я обязательно им воспользуюсь.";
			link.l1.go = "exit";
			NextDiag.TempNode = "W_Boss";
			npchar.quest.silk_info = "true";
			npchar.quest.silk = "true";
		break;
		
		// торговля шелком
		case "trade_silk":
			dialog.text = "Конечно, капитан. Шелк вас дожидается. Готовы его оплатить?";
			if (GetCharacterItem(pchar, "gold_dublon") >= 600)
			{
				link.l1 = "Конечно! Вот, возьмите шесть сотен дублонов.";
				link.l1.go = "trade_silk_1";
			}
			else
			{
				link.l1 = "Вот незадача, забыл деньги на корабле. Сейчас принесу!";
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "trade_silk_1":
			RemoveItems(pchar, "gold_dublon", 600);
			Log_Info("Вы отдали 600 дублонов");
			PlaySound("interface\important_item.wav");
			dialog.text = "Приятно иметь с вами дело, капитан. Шелк будет доставлен баркой к вашему кораблю.";
			link.l1 = "Спасибо!";
			link.l1.go = "trade_silk_2";
		break;
		
		case "trade_silk_2":
			dialog.text = "Надеюсь увидеть вас у себя еще не один раз. Приходите, покупайте.";
			link.l1 = "Обязательно. До встречи!";
			link.l1.go = "exit";
			AddCharacterGoods(pchar, GOOD_SHIPSILK, 30);
			DeleteAttribute(npchar, "quest.silk");
			SetFunctionTimerCondition("Silk_TraderAttrReturn", 0, 0, 1, false); // таймер
			AddCharacterExpToSkill(pchar, "Commerce", 150);
			NextDiag.TempNode = "W_Boss";
		break;
		
		case "fight":
			DialogExit();
			sld = characterFromId("W_officer");
			LAi_SetGuardianTypeNoGroup(sld);
			LAi_group_Attack(sld, Pchar);
			for (i=1; i<=6; i++)
			{	
				sld = characterFromId("W_sold_"+i);
				LAi_group_Attack(sld, Pchar);
			}
		break;


		case "toHostessSex":
                                                          DoQuestFunctionDelay("SMALLTALK_1", 2.5);
			dialog.text = "Ты очень мил. Так чем ты меня развлечешь?";
			link.l1 = "Чем?! Мм... А вот чем! У меня самый большой... э-э-э... авторитет... среди пиратов. Вот.";
			link.l1.go = "toHostessSex_1";
			link.l2 = "У меня зоркий глаз и сильные руки, а еще...";
			link.l2.go = "toHostessSex_2";
			link.l3 = "Мадам, я столько пережил на на этом свете...";
			link.l3.go = "toHostessSex_3";
		break;
		case "toHostessSex_1":
			dialog.text = "Твой 'авторитет' мне не интересен. Прощай...";
			link.l1 = "Как же так?..";
			link.l1.go = "Exit_1";
		break;
		case "toHostessSex_2":
			if (rand(1))
			{
				dialog.text = "Послушай! Кроме самовосхваления, другие темы для разговора тебе известны?! Расскажи занимательную историю, в конце концов!";
				link.l1 = "О! Историю. Это можно! Значит, дело было так...";
				link.l1.go = "SpeakHistory";
			}
			else
			{
				dialog.text = "Послушай! Кроме самовосхваления, другие темы для разговора тебе известны?! Ты совершенно не знаешь, чем развлечь женщину...";
				link.l1 = "Хм, есть много интересных тем для разговора.";
				link.l1.go = "SpeakHistoryTwo";
			}
		break;
		case "toHostessSex_3":
			dialog.text = "Поплачься в жилетку какой-нибудь торговке в городе. И это называется пират?! М-да, куда подевались настоящие мужчины?..";
			link.l1 = "Я не это имел ввиду!";
			link.l1.go = "Exit_1";
		break;
		//истории
		case "SpeakHistory":
			dialog.text = "Внимательно слушаю...";
			if (rand(1))
			{
				link.l1 = "Есть у меня одна история, как меня чуть не съела акула. Хочешь послушать?";
				link.l1.go = "SpeakHistory_1";
			}
			else
			{
				link.l1 = "Как-то брали мы одного торговца, славная добыча, доложу я тебе, у него оказалась в трюме! Золото и серебро! Клянусь громом, так и было! Ха-ха! А еще у него на борту были славные курочки, такие ладные, фигуристые, мы их хорошенько пощипали...";
				link.l1.go = "SpeakHistory_2";
			}
		break;
		case "SpeakHistory_1":
			dialog.text = "О-о! На тебя нападала акула! Как же тебе удалось спастись?!";
			link.l1 = "Ну, тогда по порядку. Попали мы как-то в полный штиль, ни ветерка, и жара страшенная стоит. Решили мы искупнуться, чтоб освежиться немного. Это такое наслаждение, доложу я тебе, окунуться после изнуряющей жары в воду. И так я увлекся плаванием и нырянием, что не услышал криков вахтенного: '" + GetAddress_Form(PChar) + ", берегитесь! Акула! Акула!!!'. И тут я ее увидел! Я как раз нырнул и заметил ее силуэт под собой. Ну и громадина! В пять раз больше меня! В этот момент она разворачивается и идет прямо на меня!..";
			link.l1.go = "SpeakHistory_3";
		break;
		case "SpeakHistory_2":
			dialog.text = "Хватит! С меня довольно! Ты наглый, самовлюбленный тип! Убирайся с глаз моих!";
			link.l1 = "Хм, за что?..";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_3":
			dialog.text = "О, боже! И что же?!";
			link.l1 = "Я понимаю, что мое спасение в моих руках, разворачиваюсь и плыву, что есть мочи к шлюпке, там ребята пытаются выстрелами отогнать акулу, но такого монстра разве отгонишь... До шлюпки оставалось всего семь ярдов, а за моей спиной уже показался огромный плавник...";
			link.l1.go = "SpeakHistory_4";
		break;
		case "SpeakHistory_4":
			dialog.text = "И ты?!..";
			link.l1 = "Нет, не я. Юнга. Наш храбрый юнга. Увидел, что я не успеваю доплыть до шлюпки, и кинул мне саблю.";
			link.l1.go = "SpeakHistory_5";
		break;
		case "SpeakHistory_5":
			dialog.text = "И ты ее зарубил! Правда?! Ведь ты зарубил этого монстра?";
			link.l1 = "Ну, конечно зарубил! Два раза взмахнул моей верной саблей - и ужасный монстр повержен!";
			link.l1.go = "SpeakHistory_6";
			link.l2 = "Нет, не зарубил. Что ты, разве можно зарубить такую громадину! Я спасся по-другому...";
			link.l2.go = "SpeakHistory_7";
		break;
		case "SpeakHistory_6":
			dialog.text = "Хи-хи... Ты никудышный лгун! Зарубить в воде, монстра в пять раз больше тебя?.. Я тебе не верю, ты такой же хвастун, как и все! Ты меня не заинтересовал...";
			link.l1 = "Дьявол!! Жаль, однако...";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_7":
			dialog.text = "И как же?! Как же ты спасся?";
			link.l1 = "Я еле успел схватить саблю, и развернутся, как увидел надвигающиеся на меня огромные, полные страшных зубов, челюсти. И мне ничего не оставалось, кроме как сунуть саблю меж ними в надежде, что сталь выдержит мощный натиск челюстей! И действительно, акула мотнула мордой, и ушла на глубину, напоследок так наподдав мне хвостом, что я вылетел на поверхность! К тому времени, когда акула избавилась от сабли и вернулась поквитаться со мной, я уже был в шлюпке и ребята гребли во всю мочь к кораблю... На память о той истории, у меня осталось несколько шрамов.";
			link.l1.go = "SpeakHistory_8";
		break;
		case "SpeakHistory_8":
			dialog.text = "О-о! Шрамы!.. Покажи мне...";
			link.l1 = "Сейчас покажу! Сейчас я тебе такое покажу, такое!..";
			link.l1.go = "SpeakHistory_9";
			link.l2 = "Показать? Здесь?! Гм, я, конечно, бываю, грубоват, но разоблачаться при даме, в комнате, куда могут войти посторонние... Я же могу тебя скомпрометировать.";
			link.l2.go = "SpeakHistory_10";
		break;
		case "SpeakHistory_9":
			dialog.text = "Фу, хам! Понятия не имеешь, как вести себя с дамой! Не хочу общаться!";
			link.l1 = "Хм, погоди, ну как же?..";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistory_10":
			dialog.text = "Ах, как вы благородны! Я даже на мгновение забыла, хозяйкой какого заведения являюсь. Наверное, вы действительно немного грубоваты и... прямолинейны, но в вас есть нечто влекущее...  И потом, мне все-таки любопытно посмотреть на ваши шрамы, пойдемте в комнату отдыха, там нас никто не побеспокоит... И там, возможно, вы тоже захотите что-нибудь посмотреть...";
			link.l1 = "Хм, это как водится!..";
			link.l1.go = "Exit_1";
			pchar.questTemp.different.OfficeSex = "toRoomm";
			AddDialogExitQuestFunction("SexWithOffice_goToRoomm");
			pchar.quest.SmallQuests_free.over = "yes"; 
			SetTimerFunction("SexWithOffice_nulls", 0, 0, 1); //возврат хозяйки на место, если ГГ не прийдет в комнату
		break;

		case "Office_inSexRoomm":
			dialog.text = "Ах, вот и ты...";
			link.l1 = "Так точно, моя королева!";
			link.l1.go = "exit";
			pchar.quest.SexWithOffice_nulls.over = "yes"; //нулим таймер на не пришел
			NextDiag.TempNode = "First time";
			AddDialogExitQuestFunction("SexWithOffice_fackk");
			AddCharacterExpToSkill(pchar, "Leadership", 100);
            		AddCharacterExpToSkill(pchar, "Fencing", -50);
            		AddCharacterExpToSkill(pchar, "Pistol", -50);
            		AddCharacterHealth(pchar, 10);
		break;

		case "SpeakHistoryTwo":
			dialog.text = "Например?";
			link.l1 = "Например, это ты. Поистине, неисчерпаемая тема!";
			link.l1.go = "SpeakHistoryTwo_1";
		break;
		case "SpeakHistoryTwo_1":
			dialog.text = "Осторожно, ты ходишь по краю...";
			link.l1 = "Я люблю риск! Натиск и напор, вот мой девиз! Как только я тебя увидел, сразу понял, ты должны стать моей! Такой очаровательной фигурки я еще не встречал! Какие формы, боже мой!..";
			link.l1.go = "SpeakHistoryTwo_2";
			link.l2 = "Я буду осторожен.";
			link.l2.go = "SpeakHistoryTwo_3";
		break;
		case "SpeakHistoryTwo_2":
			dialog.text = "Боюсь, что эти формы не про тебя. Ты упустил свой шанс, напористый ты наш...";
			link.l1 = "Дьявол, как же так?!";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistoryTwo_3":
			dialog.text = "Хм, тогда я само внимание...";
			link.l1 = "Я повидал многих женщин, и только сейчас понял, что, увы, не все дамы могут одеваться, столь изыскано как ты. Я был глуп и слеп...";
			link.l1.go = "SpeakHistoryTwo_4";
		break;
		case "SpeakHistoryTwo_4":
			dialog.text = "Отчего же так самокритично?";
			link.l1 = "Мне надо было сразу бежать к тебе!";
			link.l1.go = "SpeakHistoryTwo_5";
		break;
		case "SpeakHistoryTwo_5":
			dialog.text = "Для чего же?";
			link.l1 = "Чтобы остаться с тобой наедине, моя королева!";
			link.l1.go = "SpeakHistoryTwo_6";
			link.l2 = "Мне понадобилась уйма времени, чтоб понять и увидеть эту истину. Мир без тебя скуден и беден, а при твоем появлении все оживает, звонче поют птицы, ласково шелестит прибой и в лучах утреннего солнца, блестят росой на лепестках распускающиеся цветы...";
			link.l2.go = "SpeakHistoryTwo_7";
		break;
		case "SpeakHistoryTwo_6":
			dialog.text = "Довольно! Ты слишком нагл. Ты упустил свой шанс.";
			link.l1 = "Агрх, не получилось...";
			link.l1.go = "Exit_1";
		break;
		case "SpeakHistoryTwo_7":
			dialog.text = "О-о!.. А ты романтик... и льстец!";
			link.l1 = "Льстец? Ничуть! Я говорю истину. И говорю, увы, немногословно. Но это потому, что все слова улетучились при виде пары твоих восхитительных, невероятно огромных...";
			link.l1.go = "SpeakHistoryTwo_8";
		break;
		case "SpeakHistoryTwo_8":
			dialog.text = "Что-о-о?!!";
			link.l1 = "...сияющих глаз.";
			link.l1.go = "SpeakHistoryTwo_9";
		break;
		case "SpeakHistoryTwo_9":
			dialog.text = "О! Что-то я не о том подумала. Продолжай, прошу тебя.";
			link.l1 = "По правде говоря, я тоже думал не только о твоих глазах...";
			link.l1.go = "SpeakHistoryTwo_10";
			link.l2 = "Как ты могла подумать о чем-то другом? Конечно, я имел ввиду только глаза.";
			link.l2.go = "SpeakHistoryTwo_15";
		break;
		case "SpeakHistoryTwo_10":
			dialog.text = "Да? И о чем же еще? Даже боюсь предположить.";
			link.l1 = "О твоей прелестной шейке, и о твоем немыслимом декольте, и у меня перехватывает дыхание, как только я подумаю, сколь прекрасен твой бюст!";
			link.l1.go = "SpeakHistoryTwo_11";
		break;
		case "SpeakHistoryTwo_11":
			dialog.text = "Наглец!..";
			link.l1 = "Быть может... И ты, наверное, прогонишь меня прочь, но... глядя на твое прекрасное платье, я непрестанно думаю о том, что под ним. Ой, прости, я забылся...";
			link.l1.go = "SpeakHistoryTwo_12";
		break;
		case "SpeakHistoryTwo_12":
			dialog.text = "Наглец и плут... и...";
			link.l1 = "Что?";
			link.l1.go = "SpeakHistoryTwo_13";
		break;
		case "SpeakHistoryTwo_13":
			dialog.text = "Очаровательный плут...";
			link.l1 = "Так я прощен?";
			link.l1.go = "SpeakHistoryTwo_14";
		break;
		case "SpeakHistoryTwo_14":
			dialog.text = "Быть может... Здесь слишком душно, давай пройдем в комнату отдыха, там прохладней, там и продолжим... разговор.";
			link.l1 = "С превеликим удовольствием!";
			link.l1.go = "exit";
			pchar.questTemp.different.OfficeSex = "toRoomm";
			AddDialogExitQuestFunction("SexWithOffice_goToRoomm");
			pchar.quest.SmallQuests_free.over = "yes"; 
			SetTimerFunction("SexWithOffice_nulls", 0, 0, 1); //возврат хозяйки на место, если ГГ не прийдет в комнату
		break;

		case "SpeakHistoryTwo_15":
			dialog.text = "Да? А я думала, что интересую тебя целиком, а не отдельными деталями. Только глаза! У меня что, и посмотреть больше не на что?!";
			link.l1 = "Я не то имел в виду...";
			link.l1.go = "SpeakHistoryTwo_16";
		break;
		case "SpeakHistoryTwo_16":
			dialog.text = "Знаю, что вы имели в виду! Уродина, с глазами навыкате! Вот что! Убирайтесь! Вы мне противны!";
			link.l1 = "Да ты что " + npchar.name + ", и в мыслях не было!..";
			link.l1.go = "Exit_1";
		break;

		//линейка ГПК
		case "SeekHVIC":
			dialog.text = "Хм-м, однако... Капитан, а что это вам взбрендило интересоваться этой конторой?";
			link.l1 = "Я выполняю для них один заказ, и возникли вопросы.";
			link.l1.go = "SeekHVIC_1";
		break;
		case "SeekHVIC_1":
			dialog.text = "А с чего вы взяли, что я знаю, где они находятся?";
			link.l1 = "Ладно, хватит дурака валять! Лицензии от этой компании вы откуда берете?";
			link.l1.go = "SeekHVIC_2";
		break;
		case "SeekHVIC_2":
			dialog.text = "У представителя компании здесь, в Карибском море. Кстати, как его зовут? Если вы имеете с ним дела, то должны это знать.";
			Link.l1.edit = 6;
			link.l1 = "";
			link.l1.go = "SeekHVIC_res";
		break;

		case "SeekHVIC_res":
			attrLoc = GetStrSmallRegister(dialogEditStrings[6]);
			if (findsubstr(attrLoc, "оливер" , 0) != -1 && findsubstr(attrLoc, "траст" , 0) != -1)
			{

				dialog.text = "Хм, верно... Ну ладно, вы можете найти его в Филипсбурге, в Синт-Маартен. У него там комната в двухэтажном доме. Только не говорите, что это я вас к нему отправил. Так, на всякий случай...";
				link.l1 = "Без проблем.";
				link.l1.go = "exit";
				LAi_group_Delete("EnemyFight");
				pchar.questTemp.LSCC = "toOliverTrast";
				AddQuestRecord("ISS_PoorsMurder", "10");
				LocatorReloadEnterDisable("Marigo_town", "houseH2", false);

				//ложим второе письмо
				ChangeItemName("letter_LSCC_1", "itmname_letter_LSCC_1");
				ChangeItemDescribe("letter_LSCC_1", "itmdescr_letter_LSCC_1");
				sld = ItemsFromID("letter_LSCC_1");
				sld.shown = true;
				sld.startLocation = "Marigo_houseH2";
				sld.startLocator = "item1";
			}
			else
			{
				dialog.text = "Никого вы не знаете, так что убирайтесь!";
				link.l1 = "Черт, вылетело из головы...";
				link.l1.go = "exit";
				pchar.questTemp.LSCC = "toLicencer_2";
			}
		break;

		case "SeekHVIC_3":
			dialog.text = "Ну, и что вы опять от меня хотите?";
			link.l1 = "Я вспомнил"+ GetSexPhrase("","а") +" имя представителя Голландской Вест-Индской компании!";
			link.l1.go = "SeekHVIC_4";
		break;
		case "SeekHVIC_4":
			dialog.text = "Да?! Ну, и как его зовут?";
			Link.l1.edit = 6;
			link.l1 = "";
			link.l1.go = "SeekHVIC_res";
		break;

	case "flags":
			dialog.text = "Хм, для торговых целей? Хах, знаем мы таких ушлых корсаров, которые торгашей в заблуждение вводят, подняв дружественный флаг! Чей флаг Вам необоходим?";
			link.l1 = "Англии.";
			link.l1.go = "England";
			link.l2 = "Франции.";
			link.l2.go = "France";
			link.l3 = "Голландии.";
			link.l3.go = "Holland";
			link.l4 = "Испании.";
			link.l4.go = "Spain";
			link.l5 = "Я передумал. Всего доброго!";
			link.l5.go = "exit";
		break;

case "England":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagEng"))
		{   
dialog.text = "Так, комплект английских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "Так, комплект английских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l1 = "Почему так дорого-то?";
		link.l1.go = "England_1";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";					
			}
		break;

case "England_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "Если Вас не устраивает сумма, то сами шейте или захватите судно нужной нации!";
			link.l1 = "Ладно-ладно, держите Ваши дублоны.";
			link.l1.go = "England_2";
			link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
			link.l2.go = "exit";
			}
link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
link.l2.go = "exit";
		break;

	case "England_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("Вы получили комплект флагов Англии!");
			SetCharacterPerk(pchar, "FlagEng");
			dialog.text = "Так, одну минуту... Вот комплект Ваших флагов. Получите и распишитесь.";
			link.l1 = "Спасибо! Всего доброго!";
			link.l1.go = "exit";
		break;

case "France":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagFra"))
		{   
dialog.text = "Так, комплект французских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "Так, комплект французских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l1 = "Почему так дорого-то?";
		link.l1.go = "France_1";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";					
			}
		break;

case "France_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "Если Вас не устраивает сумма, то сами шейте или захватите судно нужной нации!";
			link.l1 = "Ладно-ладно, держите Ваши дублоны.";
			link.l1.go = "France_2";
			link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
			link.l2.go = "exit";
			}
link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
link.l2.go = "exit";
		break;

	case "France_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("Вы получили комплект флагов Франции!");
			SetCharacterPerk(pchar, "FlagFra");
			dialog.text = "Так, одну минуту... Вот комплект Ваших флагов. Получите и распишитесь.";
			link.l1 = "Спасибо! Всего доброго!";
			link.l1.go = "exit";
		break;

case "Holland":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagHol"))
		{   
dialog.text = "Так, комплект голландских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "Так, комплект голландских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l1 = "Почему так дорого-то?";
		link.l1.go = "Holland_1";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";					
			}
		break;

case "Holland_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "Если Вас не устраивает сумма, то сами шейте или захватите судно нужной нации!";
			link.l1 = "Ладно-ладно, держите Ваши дублоны.";
			link.l1.go = "Holland_2";
			link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
			link.l2.go = "exit";
			}
link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
link.l2.go = "exit";
		break;

	case "Holland_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("Вы получили комплект флагов Голландии!");
			SetCharacterPerk(pchar, "FlagHol");
			dialog.text = "Так, одну минуту... Вот комплект Ваших флагов. Получите и распишитесь.";
			link.l1 = "Спасибо! Всего доброго!";
			link.l1.go = "exit";
		break;

case "Spain":
		if (IsCharacterPerkOn(pchar, "Trustworthy")) npchar.quest.lcc_summ = 500;
        	else npchar.quest.lcc_summ = 1000;
		if (CheckCharacterPerk(pchar, "FlagSpa"))
		{   
dialog.text = "Так, комплект испанских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";		
		}
		else
		{
dialog.text = "Так, комплект испанских флагов обойдётся Вам в "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";
		link.l1 = "Почему так дорого-то?";
		link.l1.go = "Spain_1";
		link.l2 = "Знаете, я передумал. Всего доброго!";
		link.l2.go = "exit";					
			}
		break;

case "Spain_1":
		if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
			dialog.text = "Если Вас не устраивает сумма, то сами шейте или захватите судно нужной нации!";
			link.l1 = "Ладно-ладно, держите Ваши дублоны.";
			link.l1.go = "Spain_2";
			link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
			link.l2.go = "exit";
			}
link.l2 = "Знаете, я наверное так и поступлю. Всего доброго!";
link.l2.go = "exit";
		break;

	case "Spain_2":
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			Log_Info("Вы получили комплект флагов Испании!");
			SetCharacterPerk(pchar, "FlagSpa");
			dialog.text = "Так, одну минуту... Вот комплект Ваших флагов. Получите и распишитесь.";
			link.l1 = "Спасибо! Всего доброго!";
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_1":
			NextDiag.CurrentNode = "W_officer";
			DialogExit();
		break;
	}
}