void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	int iTrade
	int iMoney
	
	int iTradeSandal
	int iMoneySandal
	int iTradeOill
	int iMoneyOill	
	int iTradeRope
	int iMoneyRope

////////------------->>Для золота
	int iTempRope
	int iTempOill
	int iTempSandal
	int iTempShipShilk
	int iTempPoison

	int iTotalTempSandal



	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
		if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) dialog.text = "Шарль де Мор, слышал о брате и случаем с Пуанси. Я занимаюсь скупой  и продажей многого. А ещё у меня есть прекрасный корабль, шхуна укомплектованная экипажем.";
			else dialog.text = "Приветствую, француз. Я занимаюсь скупой...дефицитного товара, который здешние власти недолюбливают. Если у вас есть смолы, канаты, баккаунт или шелк я с радостью его куплю. А ещё у меня есть прекрасный корабль, шхуна укомплектованная экипажем.";
				NextDiag.TempNode = "Merch_block";
				if (CheckAttribute(pchar, "questTemp.Tieyasal_WinEnd")) 
				{
					link.l1 = "Что? Откуда вы меня знаете? Тем более о моем брате?";
					link.l1.go = "History_Mihail_1";
				}
				else
				{	link.l1 = "Что? Контрабанда? Мисье, как можете вы о таком говорить находясь тут в резиденции?";
					link.l1.go = "History_merch1";
				}
				
		break;

////------------------------>>Блок истории и лист продаж.
	case "History_merch1":
			dialog.text = "Ну что вы, какая контрабанда? Я лишь занимаюсь сбором редкого товара для нужд армии.";
			link.l1 = "Да что вы? А что будет если я расскажу обо всем генерал-губернатору?";
			link.l1.go = "History_merch2":
	break;

	case "History_merch2":
			if (CheckAttribute(pchar, "questTemp.full_complete_end"))dialog.text = "Мьсе, вы можете не верить мне. Но я занимаюсь легальным делом и к тому же...вам ли судить меня? Принц Картахены...";
			else dialog.text = "Мьсе, вы можете не верить мне. Но я занимаюсь легальным делом и к тому же...Я знаю кое что о Пуанси. Возможно вы когда нибудь узнаете сами. Я отличный торговец и корабел";
			link.l1 = "Ну, раз так то, возможно я смогу помочь державе. Что вам нужно и сколько вы там платите?";
			link.l1.go = "History_merch3":
	break;
	
	case "History_merch3":
			dialog.text = "Как я говорил, мне нужны любые товары высокого спроса. Бакаунт, корабельный шелк, смолы и канаты. Действительно часть из них запрещена но такова цена спокойствия.";
			link.l1 = "Что-же, будем сотрудничать.";
			link.l1.go = "Merch_block":
			link.l2 = "Вы контрабандист который прикрывается ложью о губернаторе. Защищайся преступник!";
			link.l2.go = "attak":
	break;
//////------------>история Макаэле
	case "History_Mihail_1":
			dialog.text = "Мне известно многое, особенно о неком индейском божестве. Это часть моей работы. Знать все обо всем.";
			link.l1 = "Не знаю кто ты и что ты там знаешь, но лучше забудь обо всем иначе...";
			link.l1.go = "History_Mihail_2":
	break;
		
	case "History_Mihail_2":
			dialog.text = "Ну,ну полегче. Убить меня ты всёравно не сможешь а даже если и сможешь то совершишь большую ошибку. К тому-же я не собираюсь ни о чем рассказывать, да и тебе выгоднее меня в живых оставить. Ведь где ты найдешь того кто продаст тебе редкости которых не найдешь нигде.";
			link.l1 = "Редкости? Это какие? Всякие побрякушки мне не нужны так что...хмм так чем вы торгуете? И чем платите?";
			link.l1.go = "History_Mihail_3":
	break;
		
	case "History_Mihail_3":
			dialog.text = "Бакаунт, корабельный шелк, смолы и канаты. Часть этого запрещена но не нам ли о запретах спорить? Кто я такой вы всеравно не узнаете. Так-что закроем эту тему и не вернёмся к ней более...вы будите сотрудничать?";
			link.l1 = "Что-же, будем сотрудничать. Возможно и правда не стоит знать кто вы.";
			link.l1.go = "Merch_block":
			link.l2 = "Я не знаю, кто ты но ты очень много знаешь, возможно ты порождение зла. Готовься к смерти...";
			link.l2.go = "NoatackPlease":
	break;
	
//----------------пытаемся отговорить гг от боя-->>>
	case "NoatackPlease":
			dialog.text = "Я? Порождение 'зла'? Вы очень ошибаетесь, прошу прислушайтесь к голосу разума!";
			link.l1 = "К голосу разума или к чародейству? Назови мне хоть одну причину не убивать тебя.";
			link.l1.go = "NoatackPlease_2":
			link.l2 = "Ты меня не зачаруешь, колдун. Защищайся!";
			link.l2.go = "attakGodMisheleYes":
	break;
	
	case "NoatackPlease_2":
			dialog.text = "Назову две. Первая ты скорее всего умрешь. Вторая Моя смерть ничего не даст тебе кроме разочарования. У тебя последний шанс...давай сотрудничать.";
			link.l1 = "Нет. Защищайся демон!";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "Хорошо. Сотрудничаем.";
			link.l2.go = "Merch_block":
			link.l3 = "Зачем мне слушать тебя? Того о ком я ничего не знаю.";
			link.l3.go = "NoatackPlease_3":
	break;
	case "NoatackPlease_3":
			dialog.text = " (Создатель) "+pchar.name+" и игрок что втыкает в моник. ты правда хочешь убить его? Последствия будут суровы для "+ GetSexPhrase("него","неё") +" для вас обоих.";
			link.l1 = "Вы сгинете. Защищайся демон!";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "Мне это не нравится но хорошо, сотрудничаем";
			link.l2.go = "Merch_block":
			link.l3 = "Я подумаю.";
			link.l3.go = "Exit":
			NextDiag.TempNode = "God_1";
	break;
	
	
	case "God_1":
			dialog.text = " (Создатель и торговец) Итак, делай свой выбор и ощути последствия!";
			link.l1 = "Он труп.";
			link.l1.go = "attakGodMisheleYes":
			link.l2 = "Я слишком сла"+ GetSexPhrase("б","ба") +". Мне всеравно кто он, я пойду на сотрудничество.";
			link.l2.go = "God_2":
	break;	
	
	case "God_2":
			dialog.text = "(Создатель) Молодец, сейчас наш друг все забудет и вы начнете сотрудничать. Или уходи и не возвращайся. И...раз, два, три? И-начали!";
			link.l1 = "...";
			link.l1.go = "exit":
			link.l2 = "Я не вернусь и не хочу иметь с тобой дел.";
			link.l2.go = "God_3":
			NextDiag.TempNode = "Merch_block";
	break;
	
	case "God_3":
			dialog.text = "(Создатель) Живи в созданном тобой аду и прими последствия. Ты нас не увидишь больше.";
			link.l1 = "...";
			link.l1.go = "exit":
			pchar.quest.ship_No ="true";
			sld = CharacterFromID("MerchCotraband");
			RemovePassenger(pchar, sld);
            LAi_type_warrior_SetWateState(sld); // гулять без дела
            sld.lifeday = 0;
			// NextDiag.TempNode = "Exit";
			LAi_CharacterDisableDialog(npchar);
	break;
//----------------------
	case "attakGodMisheleYes":
			DialogExit();
			LAi_SetImmortal(npchar, false); // убрать бессмертие, если было
			
			float plocx, plocy, plocz;
			GetCharacterPos(pchar, &plocx, &plocy, &plocz); // получаем xyz ГГ
			TeleportCharacterToPos(npchar, plocx - 0.1, plocy, plocz - 0.1); // вылезти изза стульев и появиться возле ГГ
			
			LAi_SetWarriorType(npchar); // это заставляет непись быть военом
			LAi_group_MoveCharacter(npchar, "EnemyFight"); // установить в группу вргов
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // отношение сторон
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // начать драку
			
			npchar.rank = sti(pchar.rank);
			LAi_SetHP(npchar, 1000 + sti(pchar.rank) * 10, 1000 + sti(pchar.rank) * 10);	//	1000хп +10 ранг гг *10 кратное умножение
			
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			EquipCharacterbyItem(npchar, npchar.equip.blade);
			GiveItem2Character(npchar, "pistol7");
			EquipCharacterbyItem(npchar, "pistol7");
			LAi_SetCharacterUseBullet(npchar, "grapeshot");
			TakeNItems(npchar, "grapeshot", 50);
			AddItems(npchar, "gunpowder", 50);
			
			TakeNItems(npchar, "GunCap_colt", 10));
			TakeNItems(npchar, "shotgun_cartridge", 10));
			
			TakeNItems(npchar, "potion2", 25);
			pchar.quest.ship_No ="true";
			
	break;
	
	case "attak":
			DialogExit();
			LAi_SetImmortal(npchar, false); // убрать бессмертие, если было
			
			float plocAtackX, plocAtackY, plocAtackZ;
			GetCharacterPos(pchar, &plocAtackX, &plocAtackY, &plocAtackZ); // получаем xyz ГГ
			TeleportCharacterToPos(npchar, plocAtackX - 0.2, plocAtackY, plocAtackZ - 0.2); // вылезти изза стульев и появиться возле ГГ
			
			LAi_SetWarriorType(npchar); // это заставляет непись быть военом
			LAi_group_MoveCharacter(npchar, "EnemyFight"); // установить в группу вргов
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY); // отношение сторон
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true); // начать драку
			
			npchar.rank = sti(pchar.rank);
			LAi_SetHP(npchar, 100 + sti(pchar.rank) * 10, 100 + sti(pchar.rank) * 10);	//	1000хп +10 ранг гг *10 кратное умножение

			SetSelfSkill(npchar, 90, 90, 90, 90, 90);
			SetShipSkill(npchar, 50, 20, 25, 25, 50, 20, 20, 50, 15);
			SetSPECIAL(npchar, 8, 9, 6, 5, 10, 7, 5);
			
			GiveItem2Character(npchar, "blade_12");
			npchar.equip.blade = "blade_12";
			EquipCharacterbyItem(npchar, npchar.equip.blade);
			GiveItem2Character(npchar, "pistol2");
			EquipCharacterbyItem(npchar, "pistol2");
			LAi_SetCharacterUseBullet(npchar, "grapeshot");
			TakeNItems(npchar, "grapeshot", 50);
			AddItems(npchar, "gunpowder", 50);
			
			TakeNItems(npchar, "potion2", 25);
			pchar.quest.ship_No ="true";
			
	break;
	
//////////---------------->Блок торговли
	case "Merch_block":
		 if (CheckAttribute(pchar, "questTemp.Patria") && pchar.questTemp.Patria.Governor == "true" || pchar.questTemp.Patria.GenGovernor == "true") 
			 
			{ 
				if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end") {dialog.text = "Приветствую, сначала Картахена теперь солевые рудники...как там Пуанси и Терракс? Передавайте им привет. Что ты мне привез?";}
				else {dialog.text = "Ну здраствуйте...вы были в шахтах на Сан-Мартине? Быть пиратом Тиракса не так выгодно, как служить короне верно? Что ты привез мне? мой Герой";}
			}
				else { 
						if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end") {dialog.text = "Сам Чарли-принц восстал из мертвых и ведет со мной дела...Как Картахена и пещерыМаски? Нашли своё сокровище? Показывай что у тебя есть из товара";} 
							else {dialog.text = "Рад видеть моего нового помощника. Ты что-нибудь привез? Куплю весь товар по хорошей цене.";} }
	
	if (!CheckAttribute(pchar, "quest.merch_ship")	&&	pchar.questTemp.LongHappy == "end"	&&	pchar.questTemp.Saga.Helena_officer == "true")
			{
				link.l1 = "Вы говорили у вас есть шхуна? У моей любимой была шхуна, я куплю ее. Будет отличным подарком к свадьбе.";
				link.l1.go = "merch_ship";
			}
				link.l2 = "У меня есть бочки смол на продажу."	
				link.l2.go = "merch_oil";
				link.l3 = "Я готов продать несколько бухт каната.";
				link.l3.go = "merch_persian";
				link.l4 = "Мой трюм полон бакаута.";
				link.l4.go = "merch_bekaut";	
				link.l5 = "У меня есть немного шёлка на продажу.";
				link.l5.go = "merch_shelk";	
				link.l10 = "Я хочу купить некоторые товары.";
				link.l10.go = "goods";
	if (CheckAttribute(pchar, "questTemp.Saga") && pchar.questTemp.Saga == "end")
			{
				link.l6 = "У тебя есть патроны для пистолета Кольта?";
				link.l6.go = "merch_koltPatrons";
			}
	if (CheckAttribute(pchar, "questTemp.Mtraxx"))
			{
				link.l7 = "Ты продаешь яд индейцев Таито?";
				link.l7.go = "merch_poison";
			}
				link.l9 = "До свидания";
				link.l9.go = "Exit";
	break;
////-------------------------

		case "goods":
			dialog.text = "Так, какой товар вам понадобился?";
			link.l1 = "Провиант";
			link.l1.go = "trade_prov";
			link.l2 = "Я передумал, ничего не нужно.";
			link.l2.go = "exit";
		break;
		
		case "goods_again":
			dialog.text = "Хочешь купить что-то ещё?";
			link.l1 = "Провиант";
			link.l1.go = "trade_prov";
			link.l2 = "Больше ничего.";
			link.l2.go = "exit";
		break;
		
		case "trade_prov":
			dialog.text = "Сколько провианта ты хочешь купить?";
			link.l1.edit = 4;
			link.l1 = "";	
			link.l1.go = "trade_prov_1";
		break;
		
		case "trade_prov_1":
			int iTempProv;
			iTempProv = sti(dialogEditStrings[4]);
		//	int iMax = GetSquadronGoods(pchar, GOOD_SANDAL);
			if (iTempProv <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько провианта или проваливайте.";
				link.l1 = "ГХм, извини, ошибочка вышла...";
				link.l1.go = "trade_prov";
			}
			iMoney = (15)*iTempProv;
			else
			{
			dialog.text = ""+FindRussianQtyString(iTempProv)+"? Хорошо. Я продам тебе провианта на "+FindRussianMoneyString(iMoney)+". Устраивает?";
			link.l1 = "По рукам!";
			link.l1.go = "trade_prov_2";
			link.l2 = "Я передумал" + GetSexPhrase("", "а") + ".";
			link.l2.go = "exit";
			}
		//	NextDiag.TempNode = "Merch_block";
		break;
		
		case "trade_prov_2":
		
			iTempProv = dialogEditStrings[4];
			iMoney = (15)*iTempProv;
			
			if (pchar.money < iMoney){
				dialog.text = "Так у тебя деньжат-то не хватает, когда разбогатеешь, тогда и приходи.";
				link.l1 = "Ой.. я забыл" +GetSexPhrase("", "а") + " деньги в каюте. Скоро вернусь!";
				link.l1.go = "exit";
			}
			else{
			
			AddMoneyToCharacter(pchar, -iMoney);
		//AddCharacterGoods(pchar, GOOD_FOOD, iTempProv);
			SetCharacterGoods(pchar, GOOD_FOOD, sti(pchar.Ship.Cargo.Goods.food) + sti(iTempProv));
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			PlaySound("interface\important_item.wav");
			dialog.text = "Спасибо за сделку!";
			link.l1 = "Спасибо!";
			link.l1.go = "goods_again";
			//DialogExit();
			}
		break;
		
		case "merch_ship":
			dialog.text = "Так, вы женаты мисье...по такому случаю подарок должен соответствовать желанию второй половины. Вы готовы купить корабль которого ещё ни у кого нет?";
			if (makeint(Pchar.money) >= 50000	||	GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
			link.l1 = "Заинтриговали. Ради Элен мне ничего не жалко. Покупаю";
			link.l1.go = "serve_7";		
			link.l2 = "Позже.";
			link.l2.go = "exit";
			}
			else
			{
			dialog.text = "Капитан, у вас нет денег.";
			link.l1 = "Извините, пойду схожу за деньгами.";
			link.l1.go = "Exit";
			}
		break;
	
		case "serve_7":
//---------снимаем деньги------>
			if (makeint(Pchar.money) >= 50000	&&	GetCharacterItem(pchar, "gold_dublon") <= 500)
			{
				AddMoneyToCharacter(Pchar, -50000);	
				CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
			
			if (GetCharacterItem(pchar, "gold_dublon") >= 500 	&& 	makeint(Pchar.money) < 50000)
			{
				RemoveItems(PChar, "gold_dublon", 500);
				CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
			
			if (makeint(Pchar.money) >= 50000	&&	GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				AddMoneyToCharacter(Pchar, -50000);	
			     CreateRaduga();
				sld = characterFromId("RadugaOfficer");
				SetCharacterRemovable(sld, true);
				SetCompanionIndex(pchar, -1, sti(sld.index));
				sld.loyality = MAX_LOYALITY;
				NextDiag.CurrentNode = "Merch_block";
				pchar.quest.merch_ship ="true";
				DialogExit();
			}
//--------------------<<-------сняли			
		break;		
///////////////////////////////////////------ШЕЛК------////////////////////////////////////
		case "merch_shelk":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_SHIPSILK);
            dialog.text = "Я покупаю шёлк по 16 дублонов за рулон шелка или ту же стоимость в песо";
			link.l1 = "У меня "+FindRussianQtyString(iTotalTemp)+" шёлка.";
			if (iTotalTemp > 0) link.l1.go = "option_money";
			else link.l1.go = "merch_shelk_No";
		break;
		
		case "merch_shelk_No":
            dialog.text = "Ты издеваешься?.";
			link.l1 = "Простите!";
			link.l1.go = "Exit";
		break;
	
////////------------вариант с дублонами-->>>	корабельный шёлк	20 ДУБЛОНОВ
		case "Shilk_Price":		
			dialog.text = "Сколько шелка ты хочешь продать?";
			link.l1.edit = 1;
			link.l1 = "";	// iTradeShipshilk тут
			Link.l1.go = "result_shipshilk";
		break;
		
		case "result_shipshilk":
		    int iTradeShipshilk;
			iTradeShipshilk = sti(dialogEditStrings[1]); // сколько продаешь шелка
			npchar.questTemp.Gold_Dublon = sti(iTradeShipshilk)*25; // количество дублонов при получении.
			npchar.questTemp.Ship_shilk = sti(iTradeShipshilk)*1; // количество товара
			dialog.text = "Хорошо. Беру "+sti(npchar.questTemp.Ship_shilk)+" шёлка за "+sti(npchar.questTemp.Gold_Dublon)+" дублонов.";
			if (iTradeShipshilk <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько шелка или проваливайте.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "Shilk_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "shilk_bay";
				Link.l2 = "Я передумал..";
				Link.l2.go = "exit";
		//	}
        
		break;
		case "shilk_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_SHIPSILK, sti(npchar.questTemp.Ship_shilk));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("Вы получили "+npchar.questTemp.Gold_Dublon+" дублонов");
		break;

		case "option_money":
			dialog.text = "Чем платить? Песо или дублоны.";
			link.l1 = "Дублоны мне не по мешают.";
			link.l1.go = "Shilk_Price";
			Link.l2 = "Деньги мне не помешают.";
			Link.l2.go = "trade_shipshilk";
		break;
//////////////////////-------------Конец обмена на дублоны----------<<<--

//////////////////------обмен на деньги---->	корабельный шёлк
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_SHIPSILK);
		// int iMoney = 0;

		case "trade_shipshilk":
			dialog.text = "Сколько шелка ты хочешь продать?";
			link.l1.edit = 2;
			link.l1 = "";	
			link.l1.go = "trade_shipshilk_1";
		break;
		
		case "trade_shipshilk_1":
			iTempShipShilk = dialogEditStrings[2];
		//	int iMax = GetSquadronGoods(pchar, GOOD_SHIPSILK);
			if (iTempShipShilk <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько шелка или проваливайте.";
				link.l1 = "ГХм, извини, ошибочка вышла...";
				link.l1.go = "trade_shipshilk";
			}
			else
			{
				iMoney = (2500)*iTempShipShilk;
				dialog.text = ""+FindRussianQtyString(iTempShipShilk)+"? Хорошо. Я заплачу тебе за шелк "+FindRussianMoneyString(iMoney)+". Устраивает?";
				link.l1 = "По рукам!";
				link.l1.go = "trade_shipshilk_2";
				link.l2 = "Я передумал.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_shipshilk_2":
			iTempShipShilk = dialogEditStrings[2];
			iMoney = (2500)*iTempShipShilk;
			AddMoneyToCharacter(pchar, iMoney);
			RemoveCharacterGoods(pchar, GOOD_SHIPSILK, iTempShipShilk);
			npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTempShipShilk;
			DialogExit();
		break;

/////////////////////------Обмен на деньги----<<<

////////////////////////////////////////////////////////////////////////БАККАУНТ<<<------------///////////
		case "merch_bekaut":
			iTotalTempSandal = GetSquadronGoods(pchar, GOOD_SANDAL);
            dialog.text = "Я покупаю шёлк по 16 дублонов за доску бакаута или ту же стоимость в песо";
			link.l1 = "У меня "+FindRussianQtyString(iTotalTempSandal)+" сандала.";
			if (iTotalTempSandal > 0) link.l1.go = "option_money_sandal";
			else link.l1.go = "merch_bekaut_No";
		break;
		
		case "merch_bekaut_No":
            dialog.text = "Ты издеваешься?.";
			link.l1 = "Простите!";
			link.l1.go = "Exit";
		break;
	
////////------------вариант с дублонами-->>>	сандал-баккаунт		30 ДУБЛОНОВ
		case "Sandal_Price":		
			dialog.text = "Сколько сандала ты хочешь продать?";
			link.l1.edit = 3;
			link.l1 = "";	// SanMerch тут
			Link.l1.go = "result_sandal";
		break;
		
		case "result_sandal":
		    int SanMerch;
			SanMerch = sti(dialogEditStrings[3]); // сколько продаешь Сандала
			npchar.questTemp.Gold_Dublon = sti(SanMerch)*40; // количество дублонов при получении.
			npchar.questTemp.Sandal = sti(SanMerch)*1; // количество товара
			dialog.text = "Хорошо. Беру "+sti(npchar.questTemp.Sandal)+" сандала за "+sti(npchar.questTemp.Gold_Dublon)+" дублонов.";
			if (SanMerch <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько бакаута или проваливайте.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "Sandal_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "sandal_bay";
				Link.l2 = "Я передумал..";
				Link.l2.go = "exit";
		//	}
        
		break;
		case "sandal_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_SANDAL, sti(npchar.questTemp.Sandal));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("Вы получили "+npchar.questTemp.Gold_Dublon+" дублонов");
		break;

		case "option_money_sandal":
			dialog.text = "Чем платить? Песо или дублоны.";
			link.l1 = "Дублоны мне не по мешают.";
			link.l1.go = "Sandal_Price";
			Link.l2 = "Деньги мне не помешают.";
			Link.l2.go = "trade_sandal";
		break;
//////////////////////-------------Конец обмена на дублоны----------<<<--

//////////////////------обмен на деньги---->		сандал баккаунт	

		// int iTrade = GetSquadronGoods(pchar, GOOD_SANDAL);
		// int iMoney = 0;

		case "trade_sandal":
			dialog.text = "Сколько сандала ты хочешь продать?";
			link.l1.edit = 4;
			link.l1 = "";	
			link.l1.go = "trade_sandall_1";
		break;
		
		case "trade_sandall_1":
			iTempSandal = dialogEditStrings[4];
		//	int iMax = GetSquadronGoods(pchar, GOOD_SANDAL);
			if (iTempSandal <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько сандала или проваливайте.";
				link.l1 = "ГХм, извини, ошибочка вышла...";
				link.l1.go = "trade_sandal";
			}
			iMoney = (4000)*iTempSandal;
			else
			{
			dialog.text = ""+FindRussianQtyString(iTempSandal)+"? Хорошо. Я заплачу тебе за сандал "+FindRussianMoneyString(iMoney)+". Устраивает?";
			link.l1 = "По рукам!";
			link.l1.go = "trade_sandall_2";
			link.l2 = "Я передумал.";
			link.l2.go = "exit";
			}
		//	NextDiag.TempNode = "Merch_block";
		break;
		
		case "trade_sandall_2":
			iTempSandal = dialogEditStrings[4];
			iMoney = (4000)*iTempSandal;
			AddMoneyToCharacter(pchar, iMoney);
			RemoveCharacterGoods(pchar, GOOD_SANDAL, iTempSandal);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			DialogExit();
		break;

/////////////////////------Обмен на деньги----<<<

////////////////////////////////////////////-----------СМОЛЫ------------->>		больше 10 дублонов за бочку
		case "merch_oil":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_OIL);
            dialog.text = "Я покупаю смолу по 15 дублонов за бочку или ту же стоимость в песо";
			link.l1 = "У меня "+FindRussianQtyString(iTotalTemp)+" бочек.";
			if (iTotalTemp > 0) link.l1.go = "option_moneyOil";
			else link.l1.go = "merch_oil_No";
		break;
		
		case "merch_oil_No":
            dialog.text = "Ты издеваешься?.";
			link.l1 = "Простите!";
			link.l1.go = "Exit";
		break;
	
////////------------вариант с дублонами-->>>	смолы	10 ДУБЛОНОВ
		case "Oil_Price":		
			dialog.text = "Сколько смол ты хочешь продать?";
			link.l1.edit = 5;
			link.l1 = "";	// OilMerch тут
			Link.l1.go = "result_oil";
		break;
		
		case "result_oil":
		    int OilMerch;
			OilMerch = sti(dialogEditStrings[5]); // сколько продаешь смол
			npchar.questTemp.Gold_Dublon = sti(OilMerch)*15; // количество дублонов при получении.
			npchar.questTemp.Oil = sti(OilMerch)*1; // количество товара
			dialog.text = "Хорошо. Беру "+sti(npchar.questTemp.Oil)+" бочек смолы за "+sti(npchar.questTemp.Gold_Dublon)+" дублонов.";
			if (OilMerch <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько бочек смол или проваливайте.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "Oil_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "oil_bay";
				Link.l2 = "Я передумал..";
				Link.l2.go = "exit";
			//}
        
		break;
		case "oil_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_OIL, sti(npchar.questTemp.Oil));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("Вы получили "+npchar.questTemp.Gold_Dublon+" дублонов");
		break;

		case "option_moneyOil":
			dialog.text = "Чем платить? Песо или дублоны.";
			link.l1 = "Дублоны мне не по мешают.";
			link.l1.go = "Oil_Price";
			Link.l2 = "Деньги мне не помешают.";
			Link.l2.go = "trade_Oil";
		break;
//////////////////////-------------Конец обмена на дублоны----------<<<--

//////////////////------обмен на деньги---->	смолы
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_OIL);
		// int iMoney = 0;

		case "trade_Oil":
			dialog.text = "Сколько смол ты хочешь продать?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "trade_Oil_1";
		break;
		
		case "trade_Oil_1":
			iTempOill = dialogEditStrings[6];
		//	int iMax = GetSquadronGoods(pchar, GOOD_OIL);
			if (iTempOill <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько смол или проваливайте.";
				link.l1 = "ГХм, извините, ошибочка вышла...";
				link.l1.go = "trade_Oil";
			}
			iMoneyOill = (1500)*iTempOill;
			else
			{
				dialog.text = ""+FindRussianQtyString(iTempOill)+"? Хорошо. Я заплачу тебе "+FindRussianMoneyString(iMoneyOill)+". За всю смолу.";
				link.l1 = "По рукам!";
				link.l1.go = "trade_Oil_2";
				link.l2 = "Я передумал.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_Oil_2":
			iTempOill = dialogEditStrings[6];
			iMoneyOill = (1500)*iTempOill;
			AddMoneyToCharacter(pchar, iMoneyOill);
			RemoveCharacterGoods(pchar, GOOD_OIL, iTempOill);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTempOill;
			DialogExit();
		break;

/////////////////////------Обмен на деньги----<<<

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////-----------------------КАНАТЫ------------->>		
		case "merch_persian":
			iTotalTemp = GetSquadronGoods(pchar, GOOD_ROPES);
          dialog.text = "Я покупаю канаты по 15 дублонов за бухту каната или ту же стоимость в песо";
			link.l1 = "У меня "+FindRussianQtyString(iTotalTemp)+" каната.";
			if (iTotalTemp > 0) link.l1.go = "option_moneyRope";
			else link.l1.go = "merch_rope_No";
		break;
		
		case "merch_rope_No":
            dialog.text = "Ты издеваешься?.";
			link.l1 = "Простите!";
			link.l1.go = "Exit";
		break;
	
////////------------вариант с дублонами-->>>	канаты	10 ДУБЛОНОВ
		case "Rope_Price":		
			dialog.text = "Сколько бухт ты хочешь продать?";
			link.l1.edit = 7;
			link.l1 = "";	// RopeMerch тут
			Link.l1.go = "result_rope";
		break;
		
		case "result_rope":
		    int RopeMerch;
			RopeMerch = sti(dialogEditStrings[7]); // сколько продаешь бухт каната
			npchar.questTemp.Gold_Dublon = sti(RopeMerch)*15; // количество дублонов при получении.
			npchar.questTemp.Rope = sti(RopeMerch)*1; // количество товара
			dialog.text = "Хорошо. Беру "+sti(npchar.questTemp.Rope)+" каната за "+sti(npchar.questTemp.Gold_Dublon)+" дублонов.";
			if (RopeMerch <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько бухт каната или проваливайте.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "Rope_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.Gold_Dublon)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "rope_bay";
				Link.l2 = "Я передумал..";
				Link.l2.go = "exit";
			//}
        
		break;
		case "rope_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveCharacterGoods(pchar, GOOD_ROPES, sti(npchar.questTemp.Rope));
			TakeNItems(pchar, "gold_dublon", sti(npchar.questTemp.Gold_Dublon));
			Log_Info("Вы получили "+npchar.questTemp.Gold_Dublon+" дублонов");
		break;

		case "option_moneyRope":
			dialog.text = "Чем платить? Песо или дублоны.";
			link.l1 = "Дублоны мне не по мешают.";
			link.l1.go = "Rope_Price";
			Link.l2 = "Деньги мне не помешают.";
			Link.l2.go = "trade_Rope";
		break;
//////////////////////-------------Конец обмена на дублоны----------<<<--

//////////////////------обмен на деньги---->	канаты
	
		// int iTrade = GetSquadronGoods(pchar, GOOD_ROPES);
		// int iMoney = 0;

		case "trade_Rope":
			dialog.text = "Сколько бухт канатов ты продашь?";
			link.l1.edit = 8;
			link.l1 = "";	
			link.l1.go = "trade_Rope_1";
		break;
		
		case "trade_Rope_1":
			iTempRope = dialogEditStrings[8];
		//	int iMax = GetSquadronGoods(pchar, GOOD_ROPES);
			if (iTempRope <= 0)
			{
				dialog.text = "Капитан, я шутить не намерен. Или говорите сколько бухт каната или проваливайте.";
				link.l1 = "ГХм, извини, ошибочка вышла...";
				link.l1.go = "trade_Rope";
			}
			else
			{
				iMoneyRope = (1500)*iTempRope;
				dialog.text = ""+FindRussianQtyString(iTempRope)+"? Хорошо. Я заплачу тебе за канаты "+FindRussianMoneyString(iMoneyRope)+". Устраивает?";
				link.l1 = "По рукам!";
				link.l1.go = "trade_Rope_2";
				link.l2 = "Я передумал.";
				link.l2.go = "exit";
				NextDiag.TempNode = "Merch_block";
			}
		break;
		
		case "trade_Rope_2":
			iTempRope = dialogEditStrings[8];
			iMoneyRope = (1500)*iTempRope;
			AddMoneyToCharacter(pchar, iMoneyRope);
			RemoveCharacterGoods(pchar, GOOD_ROPES, iTempRope);
		//	npchar.quest.foodqty = sti(npchar.quest.foodqty)+iTemp;
			DialogExit();
		break;

/////////////////////////////////////////////////////////////////////////////////////////
////----->торговля боекомплектами и ядом
		case "merch_koltPatrons":
            dialog.text = "Я могу продать все. И патроны и яды. Но это будет дорого стоить";
			link.l1 = "Деньги не проблема, главное врагов убивать.";
			link.l1.go = "pula_Price";
		break;


		case "pula_Price":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")	
			{
				dialog.text = "Хаха, узнаю Чарли принца. Один комплект стоит 10 дублонов, как понимаешь ингредиенты очень редкие. Сколько ты хочешь купить комплектов?";
			}
			else 
			{
				dialog.text = "Хмм, интересно это жестокость или милосердие?. Один комплект стоит 10 дублонов, как понимаешь ингредиенты очень редкие. Сколько ты хочешь купить комплектов?";
			}
			link.l1.edit = 9;
			link.l1 = "";	// bk тут
			Link.l1.go = "result_boekomplekt";
		break;
		
		case "result_boekomplekt":
		    int bk;
			bk = sti(dialogEditStrings[9]); // сколько надо патронов
			npchar.questTemp.boe_kom.Qty = sti(bk); // количество патронов для выдачи.
			npchar.questTemp.boe_kom.summ = sti(bk)*10; // сумма за патроны 
			dialog.text = "Хорошо. С тебя "+sti(npchar.questTemp.boe_kom.summ)+" дублонов, кэп. Не увлекайся шибко.";
			if (bk <= 0)
			{
				dialog.text = "Кэп, говори сколько? Или уходи отсюда.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "pula_Price";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.boe_kom.summ)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "boekomplekt_bay";
				Link.l2 = "Нет уж, обойдусь.";
				Link.l2.go = "exit";
		//	}
		break;
   
		case "boekomplekt_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveItems(pchar, "gold_dublon", sti(npchar.questTemp.boe_kom.summ));
			TakeNItems(pchar, "GunCap_colt", sti(npchar.questTemp.boe_kom.Qty));
			TakeNItems(pchar, "shotgun_cartridge", sti(npchar.questTemp.boe_kom.Qty));
			Log_Info("Вы купили "+npchar.questTemp.boe_kom.Qty+" боекомплект(-'а',-'ов') для кольта");
		break;

//---------------------------------------ЯД
		case "merch_poison":
            dialog.text = "Я могу продать все. И патроны и яды. Но это будет дорого стоить";
			link.l1 = "Деньги не проблема, главное врагов убивать.";
			link.l1.go = "poison_Price2";
		break;


		case "poison_Price2":
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "full_complete_end")	
			{
				dialog.text = "Хаха, узнаю Чарли принца. Один яд стоит 10 дублонов, как понимаешь ингредиенты очень редкие. Сколько ты хочешь купить?";
			}
			else 
			{
				dialog.text = "Хмм, интересно это жестокость или милосердие?. Один яд стоит 10 дублонов, как понимаешь ингредиенты очень редкие. Сколько ты хочешь купить?";
			}
			link.l1.edit = 9;
			link.l1 = "";	// bk тут
			Link.l1.go = "result_poison";
		break;
		
		case "result_poison":
		    int poison;
			poison = sti(dialogEditStrings[9]); // сколько надо патронов
			npchar.questTemp.boe_kom.poisonTaito = sti(poison); // количество патронов для выдачи.
			npchar.questTemp.boe_kom.summ2 = sti(poison)*10; // сумма за яд 
			dialog.text = "Хорошо. С тебя "+sti(npchar.questTemp.boe_kom.summ2)+" дублонов, кэп. Не увлекайся шибко.";
			if (poison <= 0)
			{
				dialog.text = "Кэп, говори сколько? Или уходи отсюда.";
				link.l1 = "Хм, извини, ошибочка вышла...";
				link.l1.go = "exit";
				break;
			}		
		//	if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.questTemp.boe_kom.summ)) 
		//	{				
				Link.l1 = "По рукам!";
				Link.l1.go = "poison_bay";
				Link.l2 = "Нет уж, обойдусь.";
				Link.l2.go = "exit";
		//	}
		break;
   
		case "poison_bay":
		    DialogExit();
		    PlaySound("interface\important_item.wav");
		    RemoveItems(pchar, "gold_dublon", sti(npchar.questTemp.boe_kom.summ2));
			TakeNItems(pchar, "indian_poison", sti(npchar.questTemp.boe_kom.poisonTaito));
			Log_Info("Вы купили "+npchar.questTemp.boe_kom.poisonTaito+" Яда Таито");
		break;

/////////////////////////////////////////////////////////////////////////////////////////
/*
	/*
		case "serve_7":
			AddMoneyToCharacter(Pchar, -50000);
			DialogExit();
	//-------Начало блака оффа.------->>>		
			sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
	        SetFantomParamFromRank(sld, 10, true);
	        FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "Новый корабль", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
	        SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
	        SetSelfSkill(sld, 20, 22, 18, 25, 30);
	        sld.dialog.FileName = "Enc_Officer_dialog.c";
            sld.dialog.currentnode = "Enc_Officer_dialog";
			sld.greeting = "patrol";
			SetCharacterPerk(sld, "BasicDefense");
			SetCharacterPerk(sld, "AdvancedDefense");
			SetCharacterPerk(sld, "Gunman");
			SetCharacterPerk(sld, "LongRangeGrappling");
			SetCharacterPerk(sld, "HullDamageUp");
			SetCharacterPerk(sld, "SailsDamageUp");
			SetCharacterPerk(sld, "CrewDamageUp");
			SetCharacterPerk(sld, "BasicBattleState");
			SetCharacterPerk(sld, "ShipSpeedUp");
			SetCharacterPerk(sld, "ShipTurnRateUp");
			SetCharacterPerk(sld, "StormProfessional");
			SetCharacterPerk(sld, "Doctor1");
			sld = characterFromId("RadugaOfficer");
			SetCharacterRemovable(sld, true);
			SetCompanionIndex(pchar, -1, sti(sld.index));
			sld.loyality = MAX_LOYALITY;
	//<<-------------Конец блока оффа		
	////--->корабль
			sld.ship.Crew.Morale = 100;
			sld.Ship.Crew.Exp.Sailors = 100;
			sld.Ship.Crew.Exp.Cannoners = 100;
			sld.Ship.Crew.Exp.Soldiers = 100;
			AddCharacterGoods(sld, GOOD_BALLS, 700);
			AddCharacterGoods(sld, GOOD_GRAPES, 700);
			AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
			AddCharacterGoods(sld, GOOD_BOMBS, 700);
			AddCharacterGoods(sld, GOOD_POWDER, 1000);
			AddCharacterGoods(sld, GOOD_FOOD, 1000);
			AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
			AddCharacterGoods(sld, GOOD_RUM, 200);
			AddCharacterGoods(sld, GOOD_PLANKS, 50);
			AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
			RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;	//	максимальный калибр
			RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;	//	количество пушек
			RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;	//	минимальный калибр
			RealShips[sti(sld.Ship.Type)].Capacity = 5000;	//	Вместимость трюма
			RealShips[sti(sld.Ship.Type)].MaxCrew = 800;	//	максимум команды
			RealShips[sti(sld.Ship.Type)].MinCrew = 200;	//	минимальная команда
			RealShips[sti(sld.Ship.Type)].OptCrew = 500;	//	оптимальная команда
			RealShips[sti(sld.Ship.Type)].SpeedRate = 99.99;	//	Скорость
			RealShips[sti(sld.Ship.Type)].TurnRate = 99.99;	//	Маневренность
			RealShips[sti(sld.Ship.Type)].HP = 1450;	// прочность корабля
			RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;	//
			RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
		//	SetSailsColor(sld, 8);//черный парус
			UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
			UpgradeShipParameter(sld, "TurnRate");//маневренность
			UpgradeShipParameter(sld, "WindAgainstSpeed");//бейд
			UpgradeShipParameter(sld, "Capacity");//Абгрейд трюма			
			UpgradeShipParameter(sld, "HP");//HP
			UpgradeShipParameter(sld, "MaxCrew");//Абгрейд команды
			SetCrewQuantityFull(sld);	// максимальная коменда при покупке корабля
		//<-------конец корабля	
			NextDiag.CurrentNode = "Merch_block";
			pchar.quest.merch_ship ="true";
		break;



														моя шхуна
			
	void CreateRaduga() // Шхуна
{
		sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
		SetFantomParamFromRank(sld, 10, true);
		FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "Новый корабль", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
		SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
		SetSelfSkill(sld, 20, 22, 18, 25, 30);
	//	sld.dialog.FileName = "Enc_Officer_dialog.c";
	//	sld.dialog.currentnode = "Enc_Officer_dialog";
		sld.greeting = "patrol";
	//	NullCharacterGoods(sld);
		sld.greeting = "patrol";
		SetCharacterPerk(sld, "BasicDefense");
		SetCharacterPerk(sld, "AdvancedDefense");
		SetCharacterPerk(sld, "Gunman");
		SetCharacterPerk(sld, "LongRangeGrappling");
		SetCharacterPerk(sld, "HullDamageUp");
		SetCharacterPerk(sld, "SailsDamageUp");
		SetCharacterPerk(sld, "CrewDamageUp");
		SetCharacterPerk(sld, "BasicBattleState");
		SetCharacterPerk(sld, "ShipSpeedUp");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "StormProfessional");
		SetCharacterPerk(sld, "Doctor1");
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		SetCrewQuantityFull(sld);
		AddCharacterGoods(sld, GOOD_BALLS, 700);
		AddCharacterGoods(sld, GOOD_GRAPES, 700);
		AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
		AddCharacterGoods(sld, GOOD_BOMBS, 700);
		AddCharacterGoods(sld, GOOD_POWDER, 1000);
		AddCharacterGoods(sld, GOOD_FOOD, 1000);
		AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
		AddCharacterGoods(sld, GOOD_RUM, 200);
		AddCharacterGoods(sld, GOOD_PLANKS, 50);
		AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
		RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;
		RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;
		RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;
		RealShips[sti(sld.Ship.Type)].MaxCrew = 800;
		RealShips[sti(sld.Ship.Type)].MinCrew = 200;
		RealShips[sti(sld.Ship.Type)].OptCrew = 500;
		RealShips[sti(sld.Ship.Type)].SpeedRate = 99.99;
		RealShips[sti(sld.Ship.Type)].TurnRate = 99.99;
		RealShips[sti(sld.Ship.Type)].HP = 1450;
		RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;
	//	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
	//	SetSailsColor(sld, 8);//черный парус
		UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
		UpgradeShipParameter(sld, "TurnRate");//маневренность
		UpgradeShipParameter(sld, "WindAgainstSpeed");//бейд
		SetCrewQuantityFull(sld);

;
////////////////////////////////////////////////////////////////////////////////////////////////////	
*/
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}

}


		
	void CreateRaduga() // Шхуна
{	 	
		ref sld;
//	-------------блок офицера-->
		sld = GetCharacter(NPC_GenerateCharacter("RadugaOfficer","off_eng_4", "man", "man", 10, ENGLAND, -1, true, "soldier"));
		SetFantomParamFromRank(sld, 10, true);
		FantomMakeSmallSailor(sld, SHIP_SCHOONER_W, "Новый корабль", CANNON_TYPE_CANNON_LBS16, 30, 30, 30, 30, 30);
		SetShipSkill(sld, 30, 40, 50, 50, 65, 40, 45, 48, 20);
		SetSelfSkill(sld, 20, 22, 18, 25, 30);
	//	sld.dialog.FileName = "Enc_Officer_dialog.c";
		sld.dialog.FileName = "Enc_Officer_dialog.c";
	//	sld.dialog.currentnode = "Enc_Officer_dialog";
		sld.greeting = "patrol";
	//	NullCharacterGoods(sld);
		sld.greeting = "patrol";
		SetCharacterPerk(sld, "BasicDefense");
		SetCharacterPerk(sld, "AdvancedDefense");
		SetCharacterPerk(sld, "Gunman");
		SetCharacterPerk(sld, "LongRangeGrappling");
		SetCharacterPerk(sld, "HullDamageUp");
		SetCharacterPerk(sld, "SailsDamageUp");
		SetCharacterPerk(sld, "CrewDamageUp");
		SetCharacterPerk(sld, "BasicBattleState");
		SetCharacterPerk(sld, "ShipSpeedUp");
		SetCharacterPerk(sld, "ShipTurnRateUp");
		SetCharacterPerk(sld, "StormProfessional");
		SetCharacterPerk(sld, "Doctor1");
		
		///////////////---------блок корабля-->
		sld.ship.Crew.Morale = 100;
		sld.Ship.Crew.Exp.Sailors = 100;
		sld.Ship.Crew.Exp.Cannoners = 100;
		sld.Ship.Crew.Exp.Soldiers = 100;
		SetCrewQuantityFull(sld);
		AddCharacterGoods(sld, GOOD_BALLS, 700);
		AddCharacterGoods(sld, GOOD_GRAPES, 700);
		AddCharacterGoods(sld, GOOD_KNIPPELS, 700);
		AddCharacterGoods(sld, GOOD_BOMBS, 700);
		AddCharacterGoods(sld, GOOD_POWDER, 1000);
		
		AddCharacterGoods(sld, GOOD_FOOD, 1000);
		AddCharacterGoods(sld, GOOD_MEDICAMENT, 300);
		AddCharacterGoods(sld, GOOD_RUM, 200);
		
		AddCharacterGoods(sld, GOOD_PLANKS, 50);
		AddCharacterGoods(sld, GOOD_SAILCLOTH, 50);
		
		RealShips[sti(sld.Ship.Type)].MaxCaliber = 36;	//	максимальный калибр
		RealShips[sti(sld.Ship.Type)].CannonsQuantity = 18;	//	количество пушек
		RealShips[sti(sld.Ship.Type)].CannonsQuantityMin = 16;	//	минимальный калибр
		RealShips[sti(sld.Ship.Type)].Capacity = 5000;	//	Вместимость трюма
		RealShips[sti(sld.Ship.Type)].MaxCrew = 122;	//	максимум команды
		RealShips[sti(sld.Ship.Type)].MinCrew = 18;	//	минимальная команда
		RealShips[sti(sld.Ship.Type)].OptCrew = 96;	//	оптимальная команда
		RealShips[sti(sld.Ship.Type)].SpeedRate = 15.0;	//	Скорость
		RealShips[sti(sld.Ship.Type)].TurnRate = 50.0;	//	Маневренность
		RealShips[sti(sld.Ship.Type)].HP = 1450;	// прочность корабля
		RealShips[sti(sld.Ship.Type)].WindAgainstSpeed = 1.60;
		RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;
	//	SetSailsColor(sld, 8);//черный парус
		UpgradeShipParameter(sld, "SpeedRate");//апгрейдить скорость
		UpgradeShipParameter(sld, "TurnRate");//маневренность
		UpgradeShipParameter(sld, "WindAgainstSpeed");//бейд
		UpgradeShipParameter(sld, "Capacity");//Абгрейд трюма			
		UpgradeShipParameter(sld, "HP");//HP
		UpgradeShipParameter(sld, "MaxCrew");//Абгрейд команды
		SetCrewQuantityFull(sld);	// максимальная коменда при покупке корабля
	}
