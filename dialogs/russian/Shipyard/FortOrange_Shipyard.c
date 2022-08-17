// диалог по городам
// Это мастер тюнинга
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    string 	sTemp;
	int 	amount, iSan, iOil, iSil, iRop;
	int iTemp, iSum; // 280912
	ref 	shTo;
	string 	s1;
	
	int     Matherial1;
	int     Matherial2;
	int     Matherial3;
	int     Matherial4;
	int		HPPrice; 
	
	if ( sti(pchar.Ship.Type) != SHIP_NOTUSED)
	{
		int   	shipCurHP   = sti(RealShips[sti(pchar.Ship.Type)].HP);
		int   	shipBaseHP	= sti(RealShips[sti(pchar.Ship.Type)].BaseHP);
		int   	shipClass   = sti(RealShips[sti(pchar.Ship.Type)].Class);
	}	
 
	switch (Dialog.CurrentNode)
	{		
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
  // перехват основного диалога, только один раз
			if(NPChar.quest.meeting == "0")
			{
				Dialog.Text = "Привествую Вас! Меня зовут " + GetFullName(npchar) + ", чем могу быть полезен?";
				Link.l1 = pcharrepphrase("Мое имя " + GetFullName(pchar) + ", думаю, вы обо мне слышали.",
					"Здравствуйте, меня зовут " + GetFullName(pchar) + ", думаю, вы обо мне слышали.");
				Link.l1.go = "node_3";
				npchar.quest.meeting = "1";
			}
			else // нужно, если по квестам будет сброс на  "First time"
			{
				dialog.text = "Приветсвую Вас, капитан! Как поживаете?";
				link.l1 = pcharrepphrase("Давайте сразу перейдём к делу.",
					"Приветсвую, мастер! Жив и слава Богу. Я к Вам по делу.");
				link.l1.go = "node_3";
				link.l2 = pcharrepphrase("До встречи.",
					"Мне пора, извините, что побеспокоил"+ GetSexPhrase("","а") +".");
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "Master_Ship";
			Dialog.CurrentNode = "Master_Ship";
		break;
		
		case "Master_Ship":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");

			dialog.text = "Приветсвую Вас, капитан! Как поживаете?";
			link.l1 = pcharrepphrase("Давайте сразу перейдём к делу.",
					"Приветсвую, мастер! Жив и слава Богу. Я к Вам по делу.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("До встречи.",
					"Мне пора, извините, что побеспокоил"+ GetSexPhrase("","а") +".");
			link.l2.go = "exit";
			NextDiag.TempNode = "Master_Ship";
		break;

		case "node_1":
			dialog.text = "Молодежь-молодежь, не дождешься от вас никакого почтения. Горячие головы, крепкие руки, что вам еще надо?";
			link.l1 = pcharrepphrase("Это верно. Но рано или поздно всему приходит конец, и похоже, ваше время уже близко...",
				"Что-то подсказывает мне, что вы в свои молодые годы тоже не отличались особым почтением к возрасту. Разве не так?");
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.text = "Не перечь старшим, "+ GetSexPhrase("щенок","соплячка") +"!";
			link.l1 = pcharrepphrase("Ладно-ладно, не пыжтесь, а то удар хватит. Не хочу, чтоб меня обвинили в смерти лучшего корабела на Карибах. Давайте-ка лучше перейдем к делами.",
				"Я прощаю вам эту резкость, только из уважения к вашему возрасту. А теперь, если вы закончили, давайте лучше перейдем к делам.");
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase("Все, с меня хватит нравоучений! Прощайте!",
				"Я вижу, общего языка мы не найдем. Прощайте.");
			link.l2.go = "exit";
		break;

		case "node_3":
			dialog.text = "Чем могу служить, " + GetAddress_Form(NPChar) + "? ";
			link.l1 = pcharrepphrase("Мне надо воспользоваться услугами верфи.","Я хочу воспользоваться услугами вашей верфи.");
			link.l1.go = "shipyard_dlg";
            Link.l2 = "У меня вопрос.";
			Link.l2.go = "quests"; //(пересылка в файл города)
			// -->
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l3 = "Я хотел"+ GetSexPhrase("","а") +" бы поговорить с вами о делах финансовых.";
				link.l3.go = "LoanForAll";//(перессылка в файл города)
			}
			link.l9 = pcharrepphrase("Черт, у меня есть пара неотложных дел, до свидания.", "Мне уже пора, извините.");
			link.l9.go = "exit";
			NextDiag.TempNode = "Master_Ship";
		break;
		
		case "shipyard_dlg":			
			if((shipBaseHP - shipCurHP > 0) && (shipClass > 1))
			{
			dialog.Text = "Чем могу быть полезен?";		
				//Link.l1 = "Замечательно! У меня как раз есть такой кораблик, требующий ремонта. Может взглянете, что можно сделать?";
				//Link.l1.go = "ship_repair_start";		
			}
			else
			{
				dialog.Text = "Чем могу быть полезен?";
			}	
			link.l2 = "Я хочу просто воспользоваться услугами верфи.";
			link.l2.go = "shipyard";
			link.l3 = "Мне нужны орудия на корабль.";
			link.l3.go = "Cannons";
			if(RealShips[sti(Pchar.Ship.Type)].BaseType != SHIP_CURSED_FDM)
			{
					link.l4 = "Хочу изменить внешний вид парусов.";
					link.l4.go = "SailsGerald";
			}
			else
			{
				dialog.Text = "Чем могу служить?";
			}				
			link.l2 = "Я хочу просто воспользоваться услугами верфи.";
			link.l2.go = "shipyard";
			link.l3 = "Мне нужны орудия на корабль.";
			link.l3.go = "Cannons";
			if (CheckAttribute(pchar, "GenQuest.LoanChest.TakeChest") && sti(pchar.GenQuest.LoanChest.TargetIdx) == sti(NPChar.index))
			{
				link.l5 = "Я хотел"+ GetSexPhrase("","а") +" бы поговорить с вами о делах финансовых.";
				link.l5.go = "LoanForAll";//(пересылка в файл города)
			}
			Link.l9 = "Ничем, извините.";
			Link.l9.go = "exit";
		break;
		
		case "ship_tunning_not_now_2":
			dialog.Text = "Да ты, я погляжу, еще и думаешь! Далеко пойдешь! Приходи, когда решишься и не отвлекай меня по пустякам.";
			Link.l1 = RandPhraseSimple("Спасибо! Всего хорошего.", "Пока, мастер. Можно и без сарказма.");
			Link.l1.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_start":
            if ( sti(Pchar.Ship.Type) == SHIP_NOTUSED || Pchar.location.from_sea != "Roseau_port")
            {
                dialog.Text = "Корабль-то где? Что вы мне тут голову морочите?!";
			    Link.l1 = "И то правда... что это я... Извиняюсь";
			    Link.l1.go = "exit";
            }
            else
            {
			    if (GetHour() == 13)
			    {
					dialog.Text = "Я, конечно, трудоголик, но и у меня есть обеденное время. Приходите позже!";
			        Link.l1 = "Понятно...";
			        Link.l1.go = "ship_tunning_not_now";
			    }
			    else
			    {
                    if( makefloat(shipCurHP)/makefloat(shipBaseHP) < 0.10)
                    {
						dialog.Text = "Э-э-э... Корабль-то твой совсем разбит! Не возьмусь я за капитальный ремонт, и не проси. Если бы немного пораньше пришел...";
    			        Link.l1 = "Понятно... Очень жаль...";
    			        Link.l1.go = "ship_tunning_not_now";
    			        break;
                    }
					if( makefloat(shipCurHP)/makefloat(shipBaseHP) > 0.95)
                    {
						dialog.Text = "Не морочь мне голову. Твой корабль выглядит как новый - корпус практически целехонек, ремонтировать тут пока нечего.";
						Link.l1 = "Понятно... Ну я потом как-нибудь зайду...";
    			        Link.l1.go = "ship_tunning_not_now";
    			        break;
					}
                    s1 = "Так-так... посмотрим, что тут у нас есть... Ага, " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) + ".";
    			    if (sti(RealShips[sti(Pchar.Ship.Type)].Stolen) == true && !CheckAttribute(&RealShips[sti(Pchar.Ship.Type)], "Tuning"))
    			    {
    			        s1 = s1 + " Ба! Да корабль-то побывал не в одних руках. То-то он такой потертый. Патент корсарский у тебя есть? Ладно, шучу... к делу.";
    			    }
                    dialog.Text = s1;
					Link.l1 = "Давайте посмотрим что можно сделать.";
    			    Link.l1.go = "ship_repair_HP";		    			    
    			    Link.l2 = "Постойте! Я передумал"+ GetSexPhrase("","а") +".";
    			    Link.l2.go = "ship_tunning_not_now_2";
			    }
			}
		break;
		
		case "ship_repair_HP":
			HPPrice 	= GetMaterialQtyRepair( pchar, 0 ); 
			Matherial1	= GetMaterialQtyRepair( pchar, 1 );
			Matherial2	= GetMaterialQtyRepair( pchar, 2 );
			Matherial3	= GetMaterialQtyRepair( pchar, 3 );
			Matherial4	= GetMaterialQtyRepair( pchar, 4 );
			
			s1 = "Давайте посмотрим, что можно сделать. Корпус судна сейчас " + shipCurHP + ". Максимально возможное значение " + shipBaseHP;			
			s1 = s1 + ". Для полного ремонта мне понадобится: бакаута - "+ Matherial1 + ", смол - " + Matherial2 + ", корабельного шелка - " + Matherial3 + " канатов - " + Matherial4 + ".";
			s1 = s1 + " За работу возьму: "+ HPPrice + " дублонов на рабочие расходы... Внуки давно зовут меня назад в Европу, не хочется, знаете ли, возвращаться с пустыми руками... Вот, пожалуй и всё. Ах да - деньги вперед.";
            dialog.Text = s1;
			Link.l1 = "Годится. Я принимаю условия. Всё оговоренное будет доставлено.";
			if(CheckItemMyCabin("gold_dublon") >= HPPrice)
			{
				Link.l1.go = "ship_repair_HP_start_0";
			}
			else
			{
				Link.l1.go = "ship_repair_HP_start";
			}			
			Link.l2 = "Нет. Меня это не устраивает.";
			Link.l2.go = "ship_tunning_not_now";
		break;
		
		case "ship_repair_HP_start_0":
			dialog.Text = "Да, об оплате: можно оплатить сразу, можно отправить посыльного на корабль за необходимой суммой. Как хочешь?";
			link.l1 = "Плачу немедленно.";
			link.l1.go = "ship_repair_HP_start";
			link.l2 = "Отправлю посыльного. Вроде завалялось у меня в сундуках немного золотишка...";
			link.l2.go = "ship_repair_HP_start_1";
		break;
		
		case "ship_repair_HP_start":
		    amount = HPPrice;
		    if(GetCharacterItem(pchar,"gold_dublon") >= amount)
			{
				TakeNItems(pchar,"gold_dublon", -amount);				
			    NPChar.Repair.Money  		= amount;
			    NPChar.Repair.Matherial1 	= Matherial1; 
			    NPChar.Repair.Matherial2    = Matherial2;
				NPChar.Repair.Matherial3 	= Matherial3; 
			    NPChar.Repair.Matherial4    = Matherial4; 				 				
			    NPChar.Repair.ShipType      = Pchar.Ship.Type;
			    NPChar.Repair.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
				NPChar.Repair.Delta         = shipBaseHP - shipCurHP;
			    			
				NextDiag.TempNode = "ship_repair_HP_again";
                dialog.text = "Вот и славно. Жду материал.";
			    link.l1 = "Побежал"+ GetSexPhrase("","а") +" за ними...";
			    link.l1.go = "Exit";
			    
			    ReOpenQuestHeader("ShipRepair");
			    AddQuestRecord("ShipRepair", "t1");
				AddQuestUserData("ShipRepair", "sText",  "За свою работу по капитальному ремонту корпуса корабля " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) +
				" мастер-корабел требует: бакаута - " + NPChar.Repair.Matherial1 + ", смол - "+ NPChar.Repair.Matherial2 + ", корабельного шелка - " + NPChar.Repair.Matherial3 + " канатов - " + NPChar.Repair.Matherial4 + 
				". В качестве задатка было уплачено " + NPChar.Repair.Money + " дублонов... Говорит, что в Европу собрался - врёт, наверное, старый черт.");
			}
			else
			{
				NextDiag.TempNode = "ship_tunning_not_now";
                dialog.text = RandPhraseSimple("Не вижу задатка...","Не морочь мне голову....");
				link.l1 = "Я позже зайду.";
				link.l1.go = "Exit";								
			}
		break;
		
		case "ship_repair_HP_start_1":
			AddTimeToCurrent(0, 30);
		    amount = HPPrice;
			GetItemMyCabin("gold_dublon", amount);
		    
			NPChar.Repair.Money  		= amount;
			NPChar.Repair.Matherial1 	= Matherial1; 
			NPChar.Repair.Matherial2    = Matherial2; 
			NPChar.Repair.Matherial3 	= Matherial3; 
			NPChar.Repair.Matherial4    = Matherial4; 				 							
			NPChar.Repair.ShipType      = Pchar.Ship.Type;
			NPChar.Repair.ShipName      = RealShips[sti(Pchar.Ship.Type)].BaseName;
			NPChar.Repair.Delta         = shipBaseHP - shipCurHP;
			    			
			NextDiag.TempNode = "ship_repair_HP_again";
			dialog.text = "Вот и славно. Жду материал.";
			link.l1 = "Побежал"+ GetSexPhrase("","а") +" за ними...";
			link.l1.go = "Exit";
			
			ReOpenQuestHeader("ShipRepair");
			AddQuestRecord("ShipRepair", "t1");
			AddQuestUserData("ShipRepair", "sText",  "За свою работу по капитальному ремонту корпуса корабля " + XI_ConvertString(RealShips[sti(Pchar.Ship.Type)].BaseName) +
			" мастер-корабел требует: бакаута - " + NPChar.Repair.Matherial1 + ", смол - "+ NPChar.Repair.Matherial2 + ", корабельного шелка - " + NPChar.Repair.Matherial3 + " канатов - " + NPChar.Repair.Matherial4 +
			". В качестве задатка было уплачено " + NPChar.Repair.Money + " дублонов... Говорит, что в Европу собрался - врёт, наверное, старый черт.");
			
		break;
		
		case "ship_repair_HP_again":
		    if (sti(NPChar.Repair.ShipType) == sti(Pchar.Ship.Type) && NPChar.Repair.ShipName == RealShips[sti(Pchar.Ship.Type)].BaseName)
		    {
                NextDiag.TempNode = "ship_repair_HP_again";
				dialog.Text = "Работа ждет. Принес"+ GetSexPhrase("","ла") +", что я просил?";
			    Link.l1 = "Да. Кое-что удалось достать.";
			    Link.l1.go = "ship_repair_HP_again_2";
			    Link.l2 = "Нет. Еще добываю.";
			    Link.l2.go = "Exit";
			}
			else
			{
			    DeleteAttribute(NPChar, "Repair");
                NextDiag.TempNode = "ship_repair_again";
			    dialog.Text = "Сдается мне, судар"+ GetSexPhrase("ь","ыня") +", что вы поменяли корабль со времени нашего уговора. Придется все заново расчитывать...";
			    Link.l1 = "Было дело. Обидно, что задаток пропал...";
			    Link.l1.go = "Exit";		    
			    AddQuestRecord("ShipRepait", "Lose");
			    CloseQuestHeader("ShipRepair");
			}
		break;
		
		case "ship_repair_HP_again_2":
			checkMatherial_repair(Pchar, NPChar, GOOD_SANDAL, 	1);
			checkMatherial_repair(Pchar, NPChar, GOOD_OIL, 		2);
			checkMatherial_repair(Pchar, NPChar, GOOD_SHIPSILK, 3);
			checkMatherial_repair(Pchar, NPChar, GOOD_ROPES, 	4);
		    if(sti(NPChar.Repair.Matherial1) < 1 && 
			   sti(NPChar.Repair.Matherial2) < 1 &&
			   sti(NPChar.Repair.Matherial3) < 1 &&
			   sti(NPChar.Repair.Matherial4) < 1)
			{
                NextDiag.TempNode = "ship_repair_again";
                dialog.text = "Все привез"+ GetSexPhrase("","ла") +". Молодец! Начинаю работу...";
			    link.l1 = "Жду.";
			    link.l1.go = "ship_repair_HP_complite";
			}
			else
			{
				NextDiag.TempNode = "ship_repair_HP_again";
				dialog.Text = "Тебе осталось привезти: бакаута - "+ sti(NPChar.Repair.Matherial1) + ", смол - "+ sti(NPChar.Repair.Matherial2) + ", корабельного шелка - " + NPChar.Repair.Matherial3 + " канатов - " + NPChar.Repair.Matherial4 + ".";
				link.l1 = "Хорошо.";
				link.l1.go = "Exit";

                AddQuestRecord("ShipRepair", "t1");
				AddQuestUserData("ShipRepair", "sText", "Мне осталось довезти: бакаута - "+ NPChar.Repair.Matherial1 + ", смол - "+ NPChar.Repair.Matherial2 + ", корабельного шелка - " + NPChar.Repair.Matherial3 + " канатов - " + NPChar.Repair.Matherial4 + ".");
			}
		break;
		
		case "ship_repair_HP_complite":
		    AddTimeToCurrent(6, 30);
		    shTo = &RealShips[sti(Pchar.Ship.Type)];
			shTo.HP = sti(shTo.HP) + sti(NPChar.Repair.Delta);
		    DeleteAttribute(NPChar, "Repair");
			
			pchar.ship.hp = GetCharacterShipHP(pchar);
			DeleteAttribute(pchar, "ship.hulls");
			DeleteAttribute(pchar, "ship.blots");		
			
            NextDiag.TempNode = "node_3";
			dialog.Text = "... Вроде бы все... Гарантирую, что развалить этот кораблик теперь будет очень непросто!";
			Link.l1 = "Спасибо! Но с этим лучше не экспериментировать.";
			Link.l1.go = "Exit";
			AddQuestRecord("ShipRepair", "End");
			CloseQuestHeader("ShipRepair");
		break;		
		
		///////////////////////////////  квестовые ветки
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно?"), "Совсем недавно вы пытались задать мне вопрос...", "У себя на верфи, да и вообще в городе, я таких однообразно любознательных не видел.",
                          "Ну что за вопросы? Мое дело - корабли строить, давайте этим и займемся.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал"+ GetSexPhrase("","а") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Хм, однако...", "Давайте...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if ((pchar.questTemp.different == "GiveShipLetters") && !CheckAttribute(pchar, "questTemp.different.GiveShipLetters.speakAlexus"))
			{
				link.l1 = "Хочу предложить сделку.";
				link.l1.go = "Al_ShipLetters_1";// генератор  "Найденные документы"
				pchar.questTemp.different.GiveShipLetters.speakAlexus = true;
			}

			if (pchar.questTemp.piratesLine == "KillLoy_toAlexus")
			{
				link.l1 = "К вам Эдвард Лоу заходил?";
				link.l1.go = "PL_Q3_1";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_GoodWork")
			{
				link.l1 = "Торус подарил мне 'Морского Волка'!";
				link.l1.go = "PL_Q3_SW1";
			}
			if (pchar.questTemp.piratesLine.T1 == "KillLoy_LoyIsDied")
			{
				link.l1 = "У меня не очень хорошие новости относительно твоего корсарского брига, который Лоу увел...";
				link.l1.go = "PL_Q3_SW2";
			}
			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышал об этом, может что видел, может мысли какие - нибудь?";
				link.l1.go = "KillworkRoseauCharlotte";
			}

		break;
//*************************** Генератор - "Найденные судовые документы" **************
		
		case "Al_ShipLetters_1":
			dialog.text = "Излагайте условия.";
			s1 = "У меня, по счастливой случайности, оказался абсолютно легальный пакет судовых документов, еще не заявленных в розыск.";
			s1 = s1 + "Судно на плаву и не исключено из реестра, не беспокойтесь. Просто разиня-владелец умудрился потерять эти бумаги...";
			link.l1 = s1;
			link.l1.go = "Al_ShipLetters_2";			
		break;
		case "Al_ShipLetters_2":
			s1 = "Дайте-ка взглянуть! Действительно, отметки совсем свежие. Что же, удача Вам благоволит, судар"+ GetSexPhrase("ь","ыня") +"! ";
			s1 = s1 + "Мне как раз понадобился именно такой комплект, и я, в свою очередь предлагаю Вам " + sti(pchar.questTemp.different.GiveShipLetters.price5) + " песо. Что скажете?";
			dialog.text = s1;
			link.l1 = "Воистину королевская щедрость! Конечно же я соглас"+ GetSexPhrase("ен","на") +"!";
			link.l1.go = "Al_ShipLetters_3";
			link.l2 = "Пожалуй, нет.";
			link.l2.go = "exit";
		break;
		case "Al_ShipLetters_3":
			TakeItemFromCharacter(pchar, "CaptainBook"); 
			addMoneyToCharacter(pchar, sti(pchar.questTemp.different.GiveShipLetters.price5)); 
			ChangeCharacterComplexReputation(pchar,"nobility", -1); 
			OfficersReaction("bad"); 
			pchar.questTemp.different = "free";
			pchar.quest.GiveShipLetters_null.over = "yes"; //снимаем таймер 
			AddQuestRecord("GiveShipLetters", "9");			
			CloseQuestHeader("GiveShipLetters");
			DeleteAttribute(pchar, "questTemp.different.GiveShipLetters");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit(); 
		break;
		
				
		// город майя
		case "tieyasal":
			dialog.text = "А-а, мой старый знакомец Мигель! Как же, был, был. И снова все у меня выспрашивал, о том, о сем. Но как же я объясню ему, как устроено внутри радио, ежели он даже простого телеграфа в глаза не видел?";
			link.l1 = "Что?.. Вы это о чем сейчас, мастер?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Ох, простите, молодой человек, я что-то увлекся. Hе обращайте внимания на мою болтовню... Любознательный наш Мигель, это да... Навестил меня, удовлетворил свое любопытство - и снова исчез. Вот только как три дня назад тому мы с ним беседовали.";
			link.l1 = "А сейчас Мигель где? Не подскажете?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "А кто же его знает. Может в Шарптауне дела справляет, а может уже и отбыл с Исла Тесоро.";
			link.l1 = "Ясно. Спасибо, мастер!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			npchar.quest.tieyasal = "true";
		break;

//*************************** Пиратка, квест №3, поиски Лоу ***************************
		case "PL_Q3_1":
			dialog.text = "Заходил... А вам он зачем нужен?";
			link.l1 = "М-м, они с Морганом не сошлись во мнениях по некоторым вопросам этики. Не испытывайте мое терпение, мастер, я от самой Мартиники за ним гоняюсь.";
			link.l1.go = "PL_Q3_3";
			link.l2 = "Я его друг, давно не виделись, а тут в таверне сказали, что он заходил сюда...";
			link.l2.go = "PL_Q3_2";
		break;
		case "PL_Q3_2":
			dialog.text = "Ага. Друг, значит. Это хорошо... Это просто замечательно! Ты, вот что, иди к Торусу, скажи, что ищешь своего друга Эдварда Лоу. Торус тебе поможет\nМожет даже, твой друг еще у него. Иди, иди, там и встретитесь, соскучил"+ GetSexPhrase("ся","ась") +", поди.";
			link.l1 = "Спасибо! Уже бегу!";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "10");
			pchar.questTemp.piratesLine = "KillLoy_toJackman";
		break;
		case "PL_Q3_3":
			dialog.text = "Так вы его разыскиваете по заданию Моргана? Ну, хоть кто-то занялся этим мерзавцем! Представляете? он меня обманул! Принес письмо от Торуса, с просьбой отдать 'Морского Волка' подателю сего письма...";
			link.l1 = "'Морского Волка'?";
			link.l1.go = "PL_Q3_4";
		break;
		case "PL_Q3_4":
			dialog.text = "'Морской Волк' это корсарский бриг. Мой корсарский бриг! Самое лучшее мое творение! Всю душу в него вложил. Он прекрасен, великолепен и пленителен! Когда солнце на закате просвечивает сквозь его паруса, от него невозможно оторвать взгляд. На восходе, когда красавец поднимает паруса, он подобен распускающемуся цветку магнолии! А как он скользит по волнам...";
			link.l1 = "Гхм, мастер, давай вернемся к нашему Лоу.";
			link.l1.go = "PL_Q3_5";
		break;
		case "PL_Q3_5":
			dialog.text = "Простите? А, да. Эдвард Лоу. корсарский бриг-то я Торусу делал, достроил почти, а тут он, Лоу, с письмом. В общем, отдал я бриг, а когда пошел за деньгами к Торусу, оказалось, что письмо поддельное. Торус расстроился... Сильно... Очень сильно.\nКогда меня оттуда вы... Э-э-э...  Когда я оттуда уходил, Торус сказал: 'Я вас уважаю Мастер, но корсарский бриг надо вернуть'. Вот я тут и подумал, раз уж вы все равно этого Лоу ищете, может и мой корсарский бриг заодно найдете?";
			link.l1 = "Мастер, я вам, конечно, помогу, но только, если вы прекратите причитать и внятно мне скажете: ГДЕ ЛОУ?!";
			link.l1.go = "PL_Q3_6";
		break;
		case "PL_Q3_6":
			dialog.text = "Так спросите хозяина таверны. Тавернщики, они народ такой, все про всех знают. Наверняка знает, куда ушёл на моём корсарском бриге этот негодяй.";
			link.l1 = "Тьфу ты, столько времени убил"+ GetSexPhrase("","а") +" впустую. Ладно, бывайте, мастер.";
			link.l1.go = "exit";
			AddQuestRecord("Pir_Line_3_KillLoy", "11");
			pchar.questTemp.piratesLine = "KillLoy_toTavernAgain";
			//садим капитана Гудли в таверну
			sld = GetCharacter(NPC_GenerateCharacter("CapGoodly", "officer_9", "man", "man", 20, PIRATE, -1, true, "quest"));
			sld.name = "Капитан";
			sld.lastname = "Гудли";
			sld.rank = 20;
			sld.city = "Pirates";
			sld.dialog.filename   = "Gothic_Quest\PiratesLine_dialog.c";
			sld.dialog.currentnode   = "CapGoodly";
			sld.greeting = "Gr_EvilPirate";
			LAi_SetSitType(sld);
			LAi_group_MoveCharacter(sld, "PIRATE_CITIZENS");
            FreeSitLocator("Roseau_tavern", "sit10");
         	ChangeCharacterAddressGroup(sld, "Roseau_tavern", "sit", "sit9");
		break;

		case "PL_Q3_SW1":
			dialog.text = "Видел, видел, твое прибытие. Не удержался, бегал на пристань поглядеть.\nДостойный подарок. Поздравляю и спасибо тебе! Спас"+ GetSexPhrase("","ла") +" старика.";
			link.l1 = "Так уж и спас"+ GetSexPhrase("","ла") +"...";
			link.l1.go = "exit";
		break;
		case "PL_Q3_SW2":
			dialog.text = "Черт! Я так и знал... И что?";
			link.l1 = "Он утонул, сожалею....";
			link.l1.go = "PL_Q3_SW3";
		break;
		case "PL_Q3_SW3":
			dialog.text = "Да уж, все плохо.";
			link.l1 = "Да не переживай ты, все утрясется...";
			link.l1.go = "exit";
		break;

		//Розо или Шарлотт-Таун

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Мыслей нет ни каких по этому поводу кроме одной, как жаль этих бедняжек, найти бы этого ублюдка, я б его собственными руками!!!";
		link.l1 = "Ну, может кто на них зуб точил?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Нет, их тут все любили, если кто и точил... Нет, точно не изнаших.";
		link.l1 = "Понятно. А, что ты думаешь о деревне аборигенов?";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "Мирное племя, вождь у них человек чести, да и сами они достойные люди, мы к ним хорошо относимся, можешь к ним с такими вопросами даже и не ходить - обидишь. Торус это сделал, теперь с нами не разговаривают. Вот так!!!";
		link.l1 = "Значит ничего подозрительного не заметил?";
		link.l1.go = "KillworkRoseauCharlotte_3";
  		break;

                                      case "KillworkRoseauCharlotte_3":
		dialog.text = "Нет, ну я был с одной из них в тот вечер, как обычно она мне сделала, э-э! Вот чёрт, я не могу вот так говорить спокойно, зная, что её уже нет в живых, корче после этого я с чувством выполненого долга пошёл спать и всё!";
		link.l1 = "Спасибо, понял.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 7) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

		
		// Калеуче
		case "FDM":
			dialog.text = "А-а, 'корабль-призрак'! Вашим галеоном матери пугают непослушных детей. Нет чтобы затопить эту чертову посудину - далась она вам! Моряков в дрожь бросает, когда они видят ваше судно на горизонте... Так что вы хотите с ним сделать?";
			if (!CheckAttribute(npchar, "quest.FDM_cabin"))
			{
				link.l1 = "То, что от его внешнего вида трусливые мозгляки в штаны себе накладывают - это меня как раз устраивает. А вот внутреннее убранство каюты меня огорчает - там не убирались полвека, все покрылось плесенью и протухло. На кровати спать жутко - словно в гроб укладываешься. Хочу обстановку полностью обновить - труху и гниль выбросить, всё свежее поставить. Возьметесь, мастер?";
				link.l1.go = "FDM_cabin";
			}
			if (!CheckAttribute(npchar, "quest.FDM_sails"))
			{
				link.l2 = "Надоела эта древняя рванина, что болтается у меня вместо парусов. Ветер она ловит не хуже обычных полотнищ, но вид - просто омерзительный. Хочу нормальные белые паруса, как на всех кораблях. Сделаем, мастер?";
				link.l2.go = "FDM_sails";
			}
		break;
		
		case "FDM_cabin":
			dialog.text = "Отчего же не взяться? Возьмусь, конечно, чай, не безрукий. Галеон у вас огромный, так что могу даже перестроить его внутреннее обиталище по образу кают линейных кораблей. Или оставим стандартную каюту. Что выбираете?";
			link.l1 = "Давайте сделаем каюту, как на линейных кораблях! Чтобы все от зависти лопнули...";
			link.l1.go = "FDM_cabin_m";
			link.l2 = "Не вижу смысла в излишествах. Делаем стандартную.";
			link.l2.go = "FDM_cabin_s";
		break;
		
		case "FDM_cabin_m":
			dialog.text = "Очень хорошо. Тащите десять сундучков с дублонами - и за пять дней всё будет готово.";
			link.l1 = "Договорились.";
			link.l1.go = "FDM_cabin_m1";
			link.l2 = "Десять сундучков? Полторы тысячи дублонов? Кхм, я, пожалуй, еще подумаю, стоит ли эта каюта таких расходов...";
			link.l2.go = "exit";
		break;
		
		case "FDM_cabin_s":
			dialog.text = "Очень хорошо. Тащите семь сундучков с дублонами - и за пять дней всё будет готово.";
			link.l1 = "Договорились.";
			link.l1.go = "FDM_cabin_s1";
			link.l2 = "Семь сундучков? Больше тысячи дублонов? Кхм, я, пожалуй, еще подумаю, стоит ли эта каюта таких расходов...";
			link.l2.go = "exit";
		break;
		
		case "FDM_cabin_m1":
			iTemp = GetCharacterItem(pchar, "Chest");
			npchar.quest.FDM_cabin = 10;
			npchar.quest.FDM_cabin.type = "Cabin_Huge";
			dialog.text = "Вот и славно. Жду оплаты.";
			if (iTemp > 0)
			{
				link.l1 = "У меня есть с собой сундучки... Так, посмотрим... Вот, "+FindRussianQtyString(iTemp)+".";
				link.l1.go = "FDM_cabin_pay";
			}
			else
			{
				link.l1 = "Пойду складывать дублоны в сундучки.";
				link.l1.go = "FDM_cabin_wait";
			}
		break;
		
		case "FDM_cabin_s1":
			iTemp = GetCharacterItem(pchar, "Chest");
			npchar.quest.FDM_cabin = 7;
			npchar.quest.FDM_cabin.type = "Cabin";
			dialog.text = "Вот и славно. Жду оплаты.";
			if (iTemp > 0)
			{
				link.l1 = "У меня есть с собой сундучки... Так, посмотрим... Вот, "+FindRussianQtyString(iTemp)+".";
				link.l1.go = "FDM_cabin_pay";
			}
			else
			{
				link.l1 = "Пойду складывать дублоны в сундучки.";
				link.l1.go = "FDM_cabin_wait";
			}
		break;
		
		case "FDM_cabin_wait":
			DialogExit();
			npchar.quest.FDM_full = "cabin";
		break;
		
		case "FDM_cabin_pay":
			iTemp = GetCharacterItem(pchar, "Chest");
			amount = sti(npchar.quest.FDM_cabin)-iTemp;
			Log_Info("Вы передали мастеру Скипу сундуки");
			PlaySound("interface\important_item.wav");
			if (amount <= 0) // всё принес
			{
				RemoveItems(pchar, "chest", sti(npchar.quest.FDM_cabin));
				dialog.text = "Так, вам нужно было принести сундучков - "+FindRussianQtyString(sti(npchar.quest.FDM_cabin))+", вы принесли - "+FindRussianQtyString(iTemp)+". Итак, вопрос с оплатой мы закрыли. Теперь я приступаю к работе. А вы пока погуляйте и не беспокойтесь - всё будет сделано в лучшем виде.";
				link.l1 = "Хорошо...";
				link.l1.go = "FDM_cabin_do";
			}
			else
			{
				RemoveItems(pchar, "chest", iTemp);
				dialog.text = "Так, вам нужно было принести сундучков - "+FindRussianQtyString(sti(npchar.quest.FDM_cabin))+", вы принесли - "+FindRussianQtyString(iTemp)+". Значит, вам осталось донести еще "+FindRussianQtyString(amount)+".";
				link.l1 = "Хорошо, мастер.";
				link.l1.go = "FDM_cabin_wait";
				npchar.quest.FDM_cabin = amount;
			}
		break;
		
		case "FDM_cabin_do":
			DialogExit();
			SetLaunchFrameFormParam("Прошло 5 дней..."+ NewStr() +"Мастер Скип выполнил работу", "", 0, 5);
			WaitDate("", 0, 0, 5, 0, 10); //крутим время
			LaunchFrameForm();
			RefreshLandTime();
			RecalculateJumpTable();
			Whr_UpdateWeather();
			shTo = &RealShips[sti(Pchar.Ship.Type)];
			shTo.CabinType = npchar.quest.FDM_cabin.type;
			if (CheckAttribute(npchar, "quest.FDM_sails")) npchar.quest.FDM_full = "done";
			else DeleteAttribute(npchar, "quest.FDM_full");
		break;
		
		case "FDM_sails":
			dialog.text = "Сделаем, отчего же не сделать! Так-так... Это значит, нам надо полностью заменить все паруса - выбросить старье, поставить хлопковые, чистенькие и свеженькие. Площадь парусов у вас немаленькая, так что за материалы и за работу я попрошу сто тысяч песо. Устраивает?";
			if (sti(Pchar.money) >= 100000)
			{
				link.l1 = "Какие могут быть вопросы? Конечно, устраивает!";
				link.l1.go = "FDM_sails_do";
			}
			link.l2 = "Хм. Пожалуй, мне надо еще подумать...";
			link.l2.go = "exit";
		break;
		
		case "FDM_sails_do":
			AddMoneyToCharacter(pchar, -100000);
			dialog.text = "Вот и славно. Денежки вы заплатили - теперь я приступаю к работе. А вы пока погуляйте пару денечков и не беспокойтесь - всё будет сделано в лучшем виде.";
			link.l1 = "Хорошо...";
			link.l1.go = "FDM_sails_done";
		break;
		
		case "FDM_sails_done":
			DialogExit();
			SetLaunchFrameFormParam("Прошло 2 дня..."+ NewStr() +"Мастер Скип выполнил работу", "", 0, 5);
			WaitDate("", 0, 0, 2, 0, 10); //крутим время
			LaunchFrameForm();
			RefreshLandTime();
			RecalculateJumpTable();
			Whr_UpdateWeather();
			SetShipSailsFromFile(pchar, "ships/parus_silk.tga");
			SetSailsColor(pchar, 0);//белый хлопковый парус
			npchar.quest.FDM_sails = "true";
			if (CheckAttribute(npchar, "quest.FDM_cabin")) npchar.quest.FDM_full = "done";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

void checkMatherial_repair(ref Pchar, ref NPChar, int good, int goodType)
{
	int amount;
	string Matherial = "Matherial" + goodType;
	amount = GetSquadronGoods(Pchar, good) - sti(NPChar.Repair.(Matherial));
	
	if (amount < 0)
    {
		amount = amount + sti(NPChar.Repair.(Matherial));
    }
    else
    {
		amount = sti(NPChar.Repair.(Matherial));
    }
    RemoveCharacterGoods(Pchar, good, amount);
    NPChar.Repair.(Matherial) = sti(NPChar.Repair.(Matherial)) - amount;
}

int GetMaterialQtyRepair( ref _chr, int MaterialNum )
{
	if ( sti(_chr.Ship.Type) == SHIP_NOTUSED) return 0;
	
	int   	shipCurHP   = sti(RealShips[sti(_chr.Ship.Type)].HP);
	int   	shipBaseHP	= sti(RealShips[sti(_chr.Ship.Type)].BaseHP);	
	int   	shipClass   = sti(RealShips[sti(_chr.Ship.Type)].Class);
	int     shipWeight  = CWT2Tonnes(sti(RealShips[sti(_chr.Ship.Type)].Weight));
	int     HPPrice     = shipWeight * (1.2 - makefloat(shipCurHP)/makefloat(shipBaseHP));
	int     modifier    = (2 * MOD_SKILL_ENEMY_RATE) + sti(RealShips[sti(_chr.Ship.Type)].MinCrew)/2 + 1;	

	float   fQuest 	= 1.0;
	if(CheckAttribute(&RealShips[sti(_chr.Ship.Type)], "QuestShip")) 
	{
		fQuest  = 1.3;
		HPPrice = HPPrice * 2;
	}					
	
	int     Matherial1 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial2 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial3 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
	int     Matherial4 = makeint(fQuest * (10 + MOD_SKILL_ENEMY_RATE) * (6 - shipClass) / 2) + rand(modifier);
		
	if(MaterialNum == 0) return HPPrice;	
	if(MaterialNum == 1) return Matherial1;
	if(MaterialNum == 2) return Matherial2;
	if(MaterialNum == 3) return Matherial3;
	if(MaterialNum == 4) return Matherial4;
	
	return 0;
}

