// диалог коменданта форта
void ProcessDialogEvent()
{
	int amount, iGunQty, iGunGoods, iGunPrice, iTemp;
	int iTest;
	ref NPChar, sld, location;
	ref arItem;
	ref rColony;
	aref Link, NextDiag;
	string sTemp;
	float locx, locy, locz;
	bool  ok;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // вызов диалога по городам -->
   /*NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Prison\" + NPChar.City + "_Prison.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}*/
    // вызов диалога по городам <--

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "NoMoreTalkExit":
			LAi_CharacterDisableDialog(npchar);
			DialogExit();
		break;
		
		case "First time":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			location = &Locations[FindLocation(pchar.location)];
			if (rand(4) == 4 && GetNpcQuestPastDayParam(location, "gun_date") > 365 && !CheckAttribute(pchar, "questTemp.PrisonGun"))
			{
				dialog.text = RandPhraseSimple(RandPhraseSimple("Послушайте, у меня к вам есть одно важное дело. Надеюсь, сумеете помочь...","Капитан, а не заинтересует ли вас некоторое весьма прибыльное предложение?"), RandPhraseSimple("Я тут подумал, что вы могли бы нам помочь в одном весьма важном вопросе.","Капитан, у меня к вам есть одно деликатное предложение, которое может быть выгодным для нас обоих."));					
				link.l1 = "Излагайте, попробуем решить...";
				link.l1.go = "GiveTaskGun";
				location.quest.PrisonGun = "Target"; 
				SaveCurrentNpcQuestDateParam(location, "gun_date");
				break;
			}
		
			dialog.text = RandPhraseSimple("Я комендант форта. Что вам нужно здесь?", "Что вам нужно? Зачем вы явились в форт?");
			link.l1 = "Да ничего особенного, осматриваю город, знаете ли. Вот и забрел сюда по случаю.";
			link.l1.go = "exit";
			//Jason --> мини-квест Дефицитный товар
			if (CheckAttribute(pchar, "questTemp.Wine.bottle") && NPChar.location == pchar.questTemp.Wine.City + "_ammo" && GetQuestPastDayParam("questTemp.Wine_bottle") < 5)
			{
				link.l11 = "У меня к вам дело, офицер. Думаю, вас это заинтересует. Один из ваших солдат, "+pchar.questTemp.Wine.SName+" пытался через мое посредничество купить вина в городе. Зная ваши порядки...";
				link.l11.go = "Wine_prison";
			}
			// <-- мини-квест Дефицитный товар
			// Карибские нравы
			if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "fraht" && NPChar.location == "portpax_ammo")
			{
				link.l11 = "Здравствуйте, офицер. Я прибыл из колонии Бас-Тер, от человека по имени Жерар Лекруа. В трюме моего корабля груз пороха и бомб для вас...";
				link.l11.go = "trial";
			}
			NextDiag.TempNode = "First time";
		break;

		// --> Орудия для форта
		case "GiveTaskGun":
			dialog.Text = LinkRandPhrase("Дело в том, что орудия нашего форта изрядно изношены. Казна, правда, выделила деньги на их замену, но где приобрести новые - я просто в замешательстве: в нашей колонии невозможно приобрести нужное мне количество. Вот я и подумал, что корабельные орудия с абордированных вами призов могли быть здесь очень кстати.","Мне нужно заменить орудийную батарею форта. Деньги на это выделены, но, знаете ли... в нашей колонии невозможно приобрести необходимое количество.","Мне пришло предписание заменить изношенные орудия форта, но с ними такая беда - нигде не могу собрать достаточного количества.");
			Link.l1 = "Хм, а можно подробнее - калибр, количество... цена, наконец.";
			Link.l1.go = "GiveTaskGun_1";
			pchar.questTemp.PrisonGun = true;
			SaveCurrentQuestDateParam("pchar.questTemp.PrisonGun");
		break;
			
		case "GiveTaskGun_1":
			GetGunType();
			pchar.questTemp.PrisonGun.Sum = makeint(sti(pchar.questTemp.PrisonGun.Price)*sti(pchar.questTemp.PrisonGun.Qty));
			pchar.questTemp.PrisonGun.Luck = rand(4);
			pchar.questTemp.PrisonGun.Id = npchar.location;
			dialog.Text = "Мне необходимы "+ pchar.questTemp.PrisonGun.Text +", в количестве ровно " + sti(pchar.questTemp.PrisonGun.Qty) + " штук. Заплатить готов золотыми дублонами, по "+ sti(pchar.questTemp.PrisonGun.Price) +" за штуку. Всего это выйдет " + FindRussianDublonString(sti(pchar.questTemp.PrisonGun.Sum)) + ". Что скажете?.. Да, ещё одно - всю партию приму сразу, но не ранее, чем через месяц - деньги ещё в пути.";
			Link.l1 = RandPhraseSimple("Нет, офицер, не заинтересовало меня ваше предложение... Извините.","Заманчиво, конечно, но я не возьмусь. Позвольте не объяснять своего решения...");
			Link.l1.go = "exit_gun";
			Link.l2 = RandPhraseSimple("Не скрою, предложение интересное. Считайте, что мы уже договорились.","Пожалуй, возьмусь. Мне это не сложно, а выгода очевидна.");
			Link.l2.go = "GiveTaskGun_2";
		break;
			
		case "exit_gun":
			dialog.Text = "Очень жаль... очень жаль, капитан, я на вас рассчитывал. И-и... надеюсь, этот разговор не выйдет за пределы форта?";
			Link.l1 = "Это напоминание было излишним. Всего доброго.";
			Link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
			
		case "GiveTaskGun_2":
			dialog.Text = "Вот и по рукам. В сроках я вас не ограничиваю, но, все же, постарайтесь не растягивать на полгода. И надеюсь, вы понимаете, что дело конфиденциальное?";
			Link.l1 = "Понимаю. До встречи.";
			Link.l1.go = "exit";	
			ReOpenQuestHeader("PrisonGun");
			AddQuestRecord("PrisonGun", "1");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("ся","ась"));
			AddQuestUserData("PrisonGun", "sName", GetFullName(npchar));
			AddQuestUserData("PrisonGun", "sCity", XI_ConvertString("Colony" + npchar.city + "Gen"));
			AddQuestUserData("PrisonGun", "sQty", makeint(pchar.questTemp.PrisonGun.Qty));
			AddQuestUserData("PrisonGun", "sSum", makeint(pchar.questTemp.PrisonGun.Sum));
			AddQuestUserData("PrisonGun", "sText", pchar.questTemp.PrisonGun.Text);
			NextDiag.TempNode = "First time";
		break;	
		
		case "CheckGun":
			if (GetQuestPastDayParam("pchar.questTemp.PrisonGun") < 30)
			{
				dialog.Text = "Я же говорил вам явиться не раньше, чем через месяц!";
				Link.l1 = "Вот черт! Так закрутил"+ GetSexPhrase("ся","ась") +", что потерял"+ GetSexPhrase("","а") +" счет времени... Извините, приду позже, как и договаривались.";
				Link.l1.go = "exit";
				NextDiag.TempNode = "First time";
				break;
			}
			if (GetQuestPastDayParam("pchar.questTemp.PrisonGun") > 180)
			{
				dialog.Text = "Гм... Знаете, с момента заключения нашего 'договора' прошло больше, чем полгода. Я уже приобрел орудия. Или вы думали, что я буду ждать вас вечно?";
				Link.l1 = "Вот черт! Что же прикажете теперь с ними делать?";
				Link.l1.go = "TakeGun_late";
				break;
			}
			iGunGoods = pchar.questTemp.PrisonGun.Goods;
			amount = GetSquadronGoods(Pchar, iGunGoods) - sti(pchar.questTemp.PrisonGun.Qty);
			sTemp = sti(pchar.questTemp.PrisonGun.Qty);
			iTest = FindColony(NPChar.City); // город
			
			if (iTest != -1)
			{
				rColony = GetColonyByIndex(iTest);
			}
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				dialog.Text = "Да, вы готовы меня обрадовать?";
				if (amount < 0)
				{
					Link.l1 = "Нет, пока занимаюсь. Просто хотел убедиться, что наш уговор ещё в силе.";
					Link.l1.go = "exit";
				}
				else
				{
					Link.l1 = "Готов. Вся партия в трюме - "+ sTemp +" штук, как и договаривались.";
					Link.l1.go = "TakeGun";
				}
			}
			else 
			{
				dialog.text = "Что-то я не вижу в порту вашего корабля. Или вы предлагаете тащить пушки через джунгли? Пришвартуйтесь в нашей гавани и возвращайтесь.";
				link.l1 = "Мой корабль на другой стороне острова. Сейчас приведу его в порт.";
				link.l1.go = "exit";
			}
		break;
		
		case "TakeGun":
			if (pchar.questTemp.PrisonGun.Luck == 4)
			{
				dialog.Text = RandPhraseSimple("Мне право неловко, но я вынужден аннулировать наш уговор.  Нагрянула финансовая проверка, а вы же знаете, как они щепетильны в этих вопросах. Увы, но никак не получится, извините.","Капитан, тут такое дело... в общем, нам прислали орудия из метрополии, и я, естественно, был вынужден их выкупить. Цены конечно грабительские, но... Извините, что подвёл вас, но я сам весьма огорчён.");
				Link.l1 = "Вот черт! Что же прикажете теперь делать?";
				Link.l1.go = "TakeGun_no";
			}
			else
			{
				dialog.Text = RandPhraseSimple("Отлично. Я сейчас же пришлю для выгрузки гарнизонный наряд.","Великолепно. Солдаты помогут вашим людям с выгрузкой.");
				Link.l1 = "Вы оплату подготовили?";
				Link.l1.go = "TakeGun_1";
			}
		break;
		
		case "TakeGun_no":
			dialog.Text = "Не знаю. Продайте на верфи, оснастите какое-нибудь торговое судно, утопите... Право же не знаю. И я очень прошу вас, не распространяйтесь об этом деле.";
			Link.l1 = "Это же надо! У меня просто нет слов!";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "3");
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		
		case "TakeGun_late":
			dialog.Text = "Не знаю. Это ваши трудности. Продайте, выбросите, утопите - мне все равно.";
			Link.l1 = "Эх, зря только время тратил...";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "4");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("ся","ась"));
			AddQuestUserData("PrisonGun", "sName", GetFullName(npchar));
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		
		case "TakeGun_1":
			iGunGoods = pchar.questTemp.PrisonGun.Goods;
			amount = sti(pchar.questTemp.PrisonGun.Qty);
			iTemp = sti(pchar.questTemp.PrisonGun.Sum);
			dialog.Text = "Конечно! Вот ваше золото. Пожалуйста, получите.";
			Link.l1 = "Благодарствую! С вами приятно иметь дело!";
            Link.l1.go = "TakeGun_2";
			TakeNItems(pchar, "gold_dublon", iTemp);
			Log_Info("Вы получили "+FindRussianDublonString(sti(pchar.questTemp.WPU.Escort.Money))+"");
			PlaySound("interface\important_item.wav");
			RemoveCharacterGoods(Pchar, iGunGoods, amount);
		break;
		
		case "TakeGun_2":
			dialog.Text = "Взаимно. Вы мне очень помогли. И, прошу вас, пусть эта сделка останется между нами.";
			Link.l1 = "Ну, это само собой разумеется. Всего хорошего.";
            Link.l1.go = "exit";
			AddQuestRecord("PrisonGun", "2");
			AddQuestUserData("PrisonGun", "sSex", GetSexPhrase("","а"));
			CloseQuestHeader("PrisonGun");
			DeleteAttribute(pchar, "questTemp.PrisonGun");
			NextDiag.TempNode = "First time";
		break;
		// <-- орудия для форта

		//Jason --> мини-квест Дефицитный товар
		case "Wine_prison":
			dialog.text = "Что?! Я строжайше запретил выпивку на территории форта! Ну что же, он поплатится за это. Я вычту из его жалования 1000 песо, которые сейчас передам вам как вознаграждение за вашу бдительность, и отправлю на три дня на гаупвахту.";
			link.l1 = "Благодарю, " + GetAddress_FormToNPC(NPChar) + ". Пресекать подобные нарушения - наш общий долг.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 1000);
			ChangeCharacterComplexReputation(pchar,"nobility", -1); 
			DeleteAttribute(pchar, "questTemp.Wine.bottle");
			pchar.quest.Wine_Exchange.over = "yes";//снять прерывание
			sld = characterFromId(pchar.questTemp.Wine.id);
			sld.lifeday = 0;
			CloseQuestHeader("Wine");
			NextDiag.TempNode = "First time";
		break;
		// <-- мини-квест Дефицитный товар
		
		// Карибские нравы
		case "trial":
			iTest = FindColony(NPChar.City); // город
			if (iTest != -1)
			{
				rColony = GetColonyByIndex(iTest);
			}
			ok = (rColony.from_sea == "") || (Pchar.location.from_sea == rColony.from_sea);
			if(sti(Pchar.Ship.Type) != SHIP_NOTUSED && ok)
			{
				if (GetSquadronGoods(pchar, GOOD_BOMBS) < 1500 || GetSquadronGoods(pchar, GOOD_POWDER) < 1500)
				{
					dialog.text = "Хм. Но у вас же не весь груз! Как такое получилось?";
					link.l1 = "Черт побери! Прошу меня извинить - это мой недосмотр. Я немедленно докуплю нужное количество и сдам вам всю партию, как положено.";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "Так, значит, это вы - наш курьер? Хорошо. Давайте сначала разберемся с грузом, а потом уже получите дальнейшие указания.";
					link.l1 = "Давайте.";
					link.l1.go = "trial_1";
				}
			}
			else
			{
				dialog.text = "Что-то я не вижу в порту вашего корабля. Или вы предлагаете тащить груз через джунгли? Пришвартуйтесь в нашей гавани и возвращайтесь.";
				link.l1 = "Мой корабль на другой стороне острова. Сейчас приведу его в порт.";
				link.l1.go = "exit";
			}
		break;
		
		case "trial_1":
			pchar.quest.Trial_FrahtFail.over = "yes"; //снять таймер
			dialog.text = "Так, груз бомб и пороха в количестве 1500 штук каждого... Хорошо. Солдаты произведут выгрузку сами, ваши люди могут спокойно отдыхать. Получите оплату за фрахт - пять тысяч песо.";
			link.l1 = "Спасибо! Каковы мои дальнейшие действия? Месье Лекруа сказал...";
			link.l1.go = "trial_2";
		break;
		
		case "trial_2":
			AddMoneyToCharacter(pchar, 5000);
			RemoveCharacterGoods(pchar, GOOD_BOMBS, 1500);
			RemoveCharacterGoods(pchar, GOOD_POWDER, 1500);
			dialog.text = "Да-да, сейчас вы получите инструкции. Готовы меня выслушать внимательно?";
			link.l1 = "Безусловно, офицер.";
			link.l1.go = "trial_3";
		break;
		
		case "trial_3":
			dialog.text = "Значит, так. У Южного Мэйна, а точнее - у берегов испанской колонии Порто Белло, крейсирует наш военный корабль, фрегат 'Воинственный', под командованием капитана Флориана Шоке. Он подстерегает испанский тяжелый галеон, который должен выйти из Порто Белло через две недели\nПроблема заключается в том, что на нашем фрегате у полутора десятков орудий обнаружился дефект отливки, делающий пушки практически непригодными для ведения боя - они взорвутся после второго-третьего залпа. Испанский галеон, в итоге, превосходит 'Воинственный' и по числу абордажной команды, и по огневой мощи\nБез замены орудий Флориан Шоке будет вынужден отказаться от нападения и уйти ни с чем, а это крайне нежелательно. Ваша задача - спасти операцию, доставив на 'Воинственный' пятнадцать орудий, и не позднее, чем через тридцать суток.";
			link.l1 = "То есть, я должен принять на борт полтора десятка орудий, отправиться к Порто Белло, отыскать там фрегат 'Воинственный' и передать пушки капитану Флориану Шоке?";
			link.l1.go = "trial_4";
		break;
		
		case "trial_4":
			dialog.text = "Так точно. Вы все правильно поняли. Вы готовы взяться за это дело?";
			link.l1 = "Что насчет оплаты?";
			link.l1.go = "trial_5";
			link.l2 = "Мне жаль, офицер, но я не хочу в это ввязываться. Прошу меня извинить.";
			link.l2.go = "trial_exit";
		break;
		
		case "trial_exit":
			dialog.text = "Это ваше право, хотя я рассчитывал на ваше согласие. Придется искать другого курьера, а времени практически не осталось... Я вас более не задерживаю, капитан.";
			link.l1 = "Всего доброго.";
			link.l1.go = "trial_exit_1";
		break;
		
		case "trial_exit_1":
			DialogExit();
			AddQuestRecord("Trial", "6");
			CloseQuestHeader("Trial");
			DeleteAttribute(pchar, "questTemp.Trial");
		break;
		
		case "trial_5":
			dialog.text = "Насчет этого не переживайте. Флориан Шоке выплатит вам из корабельной казны двести золотых дублонов. Кроме того, я уверен, что он задействует вас и ваше судно для своих целей. С вашего согласия, конечно.";
			link.l1 = "Хорошо. Я берусь за это поручение! Где орудия?";
			link.l1.go = "trial_6";
		break;
		
		case "trial_6":
			dialog.text = "Я распоряжусь, чтобы солдаты немедленно погрузили их на ваш корабль. Поскорее отправляйтесь в путь, месье. Желаю удачи!";
			link.l1 = "Благодарю. Она мне точно не помешает, как и попутный ветер...";
			link.l1.go = "trial_7";
		break;
		
		case "trial_7":
			DialogExit();
			AddQuestRecord("Trial", "7");
			pchar.questTemp.Trial = "cannon";
			SetFunctionTimerCondition("Trial_CannonFail", 0, 0, 30, false); // таймер
			SetCharacterGoods(pchar, GOOD_CANNON_24, GetCargoGoods(pchar, GOOD_CANNON_24)+15);
			EnemyNationHunterOnMap(true);//запуск перехватчиков
			pchar.quest.Trial_cannon.win_condition.l1 = "location";
			pchar.quest.Trial_cannon.win_condition.l1.location = "Portobello";
			pchar.quest.Trial_cannon.function = "Trial_CreateFlorianFrigate";
		break;
	}
}

void GetGunType()
{
	int iGunType;
	if(makeint(pchar.rank) < 6) iGunType = rand(1);	//18&&24
	if(makeint(pchar.rank) >= 6 && makeint(pchar.rank) < 15) iGunType = rand(2); //24&&32	
	if(makeint(pchar.rank) >= 15 && makeint(pchar.rank) < 24) iGunType = rand(2)+2; //32&&36&&42
	if(makeint(pchar.rank) >= 24) iGunType = 5-rand(1); //36clv&&42
	int iAdd = makeint(GetSummonSkillFromName(pchar, SKILL_COMMERCE)/20);
	
	switch (iGunType)
	{
		case 0:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_24;     					
			pchar.questTemp.PrisonGun.Price = 28 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*5+25+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "пушки 24-го калибра";
		break; 
		case 1:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CULVERINE_18;     					
			pchar.questTemp.PrisonGun.Price = 25 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*5+25+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "кулеврины";
		break; 
		case 2:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_32;     					
			pchar.questTemp.PrisonGun.Price = 32 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*3+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "пушки 32-го калибра";
		break; 
		case 3:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_36;     					
			pchar.questTemp.PrisonGun.Price = 36 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)*3+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "пушки 36-го калибра";
		break;
		case 4:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CULVERINE_36;     					
			pchar.questTemp.PrisonGun.Price = 49 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)+15+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "полные кулеврины";
		break; 
		case 5:  
			pchar.questTemp.PrisonGun.Goods = GOOD_CANNON_42;     					
			pchar.questTemp.PrisonGun.Price = 40 + iAdd;
			pchar.questTemp.PrisonGun.Qty = sti(pchar.rank)+20+rand(sti(pchar.rank));
			pchar.questTemp.PrisonGun.Text = "пушки 42 калибра";
		break; 
	}
}