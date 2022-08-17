// НПС офиса Шарлотт-Тауна
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

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

				dialog.text = "Здравствуйте. Что вам угодно?";
				link.l1 = "Я зашел по торговым делам. Лицензии, корабельные приборы и прочее...";
				link.l1.go = "W_officer_1";
				break;
				
		
		case "W_officer_1":
			dialog.text = "Вам к месье Раймондэ Оберто. Его стол налево от вас. Он занимается всеми делами с торговыми капитанами.";
			link.l1 = "Спасибо, милашка...";
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
			if (!CheckCharacterItem(pchar, "FraTradeLicence"))
			{
				link.l1 = "Я хочу приобрести торговую лицензию вашей Компании.";
				link.l1.go = "licence";	
			}
			if (!CheckAttribute(npchar, "quest.trade"))
			{
				link.l2 = "Я слышал, что у вас можно приобрести корабельные приборы и прочие полезные вещи. Это так?";
				link.l2.go = "trade";	
			}
			else
			{
				link.l2 = "Что у вас сегодня имеется в продаже? Покажите, пожалуйста.";
				link.l2.go = "trade_1";	
			}

			link.l9 = "Нет, пока ничего.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "W_headclerk";
		break;
		
		// торговые лицензии
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "Ну что же, пожалуйста, приобретайте. Но я считаю должным вас предупредить, что наша Компания дорожит своим именем, поэтому к лицензиатам предъявлются определенные требования на весь срок действия лицензии, а именно - никаких агрессивных действий в отношении торговых кораблей любой нации\nВ случае выявления такого факта ваша лицензия будет немедленно аннулирована. Также вы лишитесь документа, если по каким-то причинам, неважно каким, вступите в конфликт с Голландией. Это понятно?";
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
			npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
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
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}