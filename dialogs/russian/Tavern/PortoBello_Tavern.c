// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";			
			if (pchar.questTemp.Slavetrader == "FindRatPortobello")
            {
                link.l1 = "Послушай, не видел ли ты капера по имени Франсуа Гонтьер? Он недавно был в вашем городе.";
                link.l1.go = "Portobello_rat_1";
            }			
			// карибские нравы
			if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy" && !CheckAttribute(npchar, "quest.trial"))
            {
                link.l1 = "Послушай, не подскажешь, где найти торговца по имени Хайме Силицио? Он вроде как к вам собирался...";
                link.l1.go = "trial";
            }			
			if (CheckAttribute(pchar, "questTemp.mushkett2x2_stid") && !CheckCharacterItem(pchar, "mushkett2x2"))
			{
				link.l1 = "Слушай, Роландо, ты не знаешь, где мне найти Альберта Зиверта - капитана брига 'Стрела'?";
				if (GetQuestPastDayParam("questTemp.mushkett2x2_stid") < 21)
				{
					link.l1.go = "Mushket_stid";
				}
				else
				{
					link.l1.go = "Mushket_late";
				}
			}

			// Addon-2016 Jason ФМК-Гваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_portobello" && !CheckAttribute(npchar, "quest.FMQG"))
            {
                link.l1 = "Послушай, я ищу человека по имени Бертран Пинетт, не слыхал о таком? Он недавно прибыл в Порто-Белло. Солидный такой господин, торговец, в парике крученом. Может, заходил к тебе...";
                link.l1.go = "FMQG";
            }
		break;
		
		case "Portobello_rat_1":
			dialog.text = NPCStringReactionRepeat("Нет, не знаю. В таверну он не заходил, да и в городе я его не видел.", "Ты уже "+ GetSexPhrase("спрашивал","спрашивала") +" об этом, я тебе ответил.", "Я же говорю тебе, ты уже "+ GetSexPhrase("спрашивал","спрашивала") +" об этом Гонтьере.", "Послушай, отойди и не мешай! Совсем что ли крыша поехала?", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Ну что же, будем искать.", "Хм, ну да...", "Да, точно, "+ GetSexPhrase("спрашивал","спрашивала") +"...", "Извини, " + npchar.name + "...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;		

		case "trial":
			dialog.text = "Сеньор Хайме Силицио? О, этот досточтимый кабальеро очень известен в нашем городе, особенно в последние пару дней! Погодите минутку, я позову человека, который проводит вас к нему... сеньор Артуро! Тут по поводу Хайме Силицио!";
			link.l1 = "...";
			link.l1.go = "exit";
			npchar.quest.trial = true;
			AddDialogExitQuestFunction("Trial_TavernEnterSoldiers");
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;

		case "Mushket_stid":
			dialog.text = "Вот это да!.. Aх-ха-ха! Зачем это тебе понадобился мой лучший друг, знаменитый разбойник Алберто Зиверт?!";
			link.l1 = "Нужен... у меня к нему дело.";
			link.l1.go = "Mushket_stid_1";
			DeleteAttribute(pchar, "questTemp.Mushkett2x2_stid");
			break;
			
		case "Mushket_stid_1":
			dialog.text = "Да неужели?! Последнего, у кого было к нему 'дело', давно уже крабы доели. Он ни с кем дел не имеет - псих-одиночка, жлоб несчастный. Только контрабандисты его терпят, потому что товар регулярно поставляет. В порты он не заходит - в каждом его одноногая ждет. Даже пираты на него охотятся... А тебя, случайно не Торус по его душу послал?";
			link.l1 = "Да нет... Есть у него вещица, которая ему не принадлежит, выкупить хочу...";
			link.l1.go = "Mushket_stid_2";
		break;

		case "Mushket_stid_2":
			dialog.text = "Ха-ха! Да Зиверту даже его собственная шкура не принадлежит - Торус поклялся, что снимет, как только его поймает. Хотя нет - 'Стрела' принадлежит ему законно - строил у Скипа на свои деньги, по своим чертежам.\nСлушай, а не на кораблик ли его ты глаз положил"+ GetSexPhrase("","а") +", а? А то я все думаю - что за 'дело' у тебя к нему! Только учти - Зиверт может запросто пустить тебя на дно, прежде, чем ты спустишь шлюпку. Такие уж у него манеры - сначала стреляет, потом говорит.";
			link.l1 = "Да не нужен мне его бриг! Ты можешь просто сказать - где его найти?";
			link.l1.go = "Mushket_stid_3";
		break;		
			
		case "Mushket_stid_3":
			dialog.text = "Он пират-одиночка, прячется по бухтам, скрытно ходит от острова к острову, нападает внезапно, так что отыскать его непросто... Но не был бы я Каталонским Лисом, если бы не знал, куда он подался! Так что готовь кошель, "+ GetSexPhrase("приятель","подруга") +"!";
			link.l1 = "Та-ак, отлично! И сколько ты хочешь за эту информацию?";
			link.l1.go = "Mushket_stid_4";
		break;	
			
		case "Mushket_stid_4":
			dialog.text = "Сто тысяч золотом, приятель! Сто тысяч золотом - и прямо сейчас.";
			if(makeint(Pchar.money) >= 100000)
			{
				link.l1 = "Сколько?? Да ты что, сдурел - просить такие деньги за два слова?!";
				link.l1.go = "Mushket_stid_nopay";
				link.l2 = "Без проблем, Роландо. Держи свои песо.";
				link.l2.go = "Mushket_stid_paymoney";
			}
			link.l3 = "Послушай, но у меня нет таких денег!";
			link.l3.go = "Mushket_stid_nomoney";
		break;	
			
		case "Mushket_stid_nopay":
			dialog.text = "Не считай меня простофилей - его бриг стоит намного дороже. А свою байку про 'вещицу' будешь рассказывать гусыне на заднем дворе таверны - тебе поверит только сын панамского верфиста... Если удастся завладеть бригом - еще благодарить меня будешь. А, если не удастся - покойникам деньги ни к чему, ха-ха-ха...";
			link.l1 = "Ладно, черт с тобой. Держи.";
			link.l1.go = "Mushket_stid_paymoney";
			link.l2 = "Не каркай. Обойдёшься без золота - сам"+ GetSexPhrase("","а") +" найду.";
			link.l2.go = "Mushket_stid_goaway";
		break;	
			
		case "Mushket_stid_nomoney":
			dialog.text = "Ну что ж - видно не судьба тебе достать 'Стрелу'. Подожду, пока моим бывшим приятелем заинтересуется кто-то посолиднее. А ждать, что ты разбогатеешь, смысла нет - он сегодня в одном месте, а завтра в другом... Так что, захочешь - найдешь, если будешь смотреть в оба. А я тебе не помощник.";
			link.l1 = "Ну что, прощай, Роландо. Не напрасно тебя называют пройдохой. Мог заработать немного песо, а не заработал - зато много...";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "5");
			DeleteAttribute(pchar, "pchar.questTemp.Mushkett2x2.Shore");
		break;	
			
		case "Mushket_stid_goaway":
			dialog.text = "Как знаешь. Хозяин - барин. Удачных поисков!";
			link.l1 = "Прощай, Роландо.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "6");
			AddQuestUserData("SeekDoubleMushket", "sSex", GetSexPhrase("ся","ась"));
			DeleteAttribute(pchar, "pchar.questTemp.Mushkett2x2.Shore");
		break;	
			
		case "Mushket_stid_paymoney":
			AddMoneyToCharacter(Pchar, -100000);
			dialog.text = "О-о, у меня появил"+ GetSexPhrase("ся щедрый приятель","ась щедрая приятельница") +"! Я даже стал подумывать - не продешевил ли я! Ну, да ладно - чего не сделаешь ради бескорыстной дружбы... Теперь слушай: буквально на днях у него была сделка с контрабандистами в заливе Москитос, сейчас он скорее всего отправился на остров Флинт, где у него лежбище, островок находится в акватории Тортуги.\nДолго он там не будет - немного отдохнёт и уйдет, так что поторопись. Догнать его ты не сможешь, но перехватить по дороге долж"+ GetSexPhrase("ен","на") +". Правда, если будешь лететь быстрее ветра, хе-хе... Если нет, то придется потом искать само"+ GetSexPhrase("му","й") +". Я и рад буду тебе помочь, в знак нашей дружбы, но он мне свои маршруты не докладывает.";
			link.l1 = "Спасибо, Лис! Немедленно выдвигаюсь.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "4");
			SetMushketCapitainInWorld();
		break;
		
		case "Mushket_late":
			dialog.text = "Aх-ха-ха! Зачем это тебе понадобился мой лучший друг, знаменитый разбойник Алберто Зиверт?!";
			link.l1 = "Нужен... у меня к нему дело.";
			link.l1.go = "Mushket_late_1";
			DeleteAttribute(pchar, "questTemp.Mushkett2x2_stid");
		break;
			
		case "Mushket_late_1":
			dialog.text = "Ну что я могу сказать... Не свезло тебе, "+ GetSexPhrase("приятель","подруга") +". Приди ты ко мне немного пораньше - я бы поделился с тобой информацией, в какой бухте можно отыскать Зиверта.\nНо теперь поздно - он ушел оттуда, а куда - не ведаю. Так что ищи теперь сам"+ GetSexPhrase("","а") +"... по всему архипелагу. Он может быть где угодно.";
			link.l1 = "Вот дьявол! Ладно, раз так - прощай.";
			link.l1.go = "exit";
			AddQuestRecord("SeekDoubleMushket", "7");
			AddQuestUserData("SeekDoubleMushket", "sSex", GetSexPhrase("ся","ась"));
		break;

		// Addon-2016 Jason ФМК-Гваделупа
		case "FMQG":
			dialog.text = "Ничего не слышал об этом господине, приятель.";
			link.l1 = "Он знакомый дона Карлоса де Мильяра. Точно ничего не припомнишь?";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			dialog.text = "Нет. Так если они с доном де Мильяром друзья - иди на прием к губернатору и попроси о встрече с сеньором Карлосом. У него и справишься о своем торговце.";
			link.l1 = "Пожалуй, так и сделаю. Спасибо за совет!";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			DialogExit();
			AddQuestRecord("FMQ_Guadeloupe", "9");
			npchar.quest.FMQG = true;
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}


void SetMushketCapitainInWorld()
{
	//создаем кэпов
	int Rank = sti(pchar.rank) + 15;
	if (Rank > 30) Rank = 30;
	ref sld = GetCharacter(NPC_GenerateCharacter("MushketCap", "officer_13", "man", "man", Rank, PIRATE, -1, true, "quest"));
	sld.name = "Альберт";
	sld.lastname = "Зиверт";
	sld.model = "officer_13"; 
	sld.model.animation = "man"; 
	sld.MultiFighter = 2.0; // мультифайтер
	sld.MultiShooter = 2.0;
	sld.SuperShooter  = true;
	FantomMakeSmallSailor(sld, SHIP_BrigArrow, "Стрела", CANNON_TYPE_CULVERINE_LBS18, 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50), 50+rand(50));
	FantomMakeCoolFighter(sld, 50+rand(50), 50+rand(50), 50+rand(50), "topor_04", "pistol_06", "cartridge", 50);
	RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 3;
	sld.Ship.Mode = "pirate";	
	DeleteAttribute(sld, "SinkTenPercent");
	sld.AlwaysSandbankManeuver = true;
	sld.DontClearDead = true;
	sld.SaveItemsForDead = true;
	sld.SuperShooter = true;
	sld.DontClearDead = true;
	sld.AlwaysEnemy = true;
	sld.SuperShooter  = true;
	sld.Abordage.Enable = true;
	sld.Ship.Stopped = true; 
	DeleteAttribute(sld, "AboardToFinalDeck");
	DeleteAttribute(sld, "SinkTenPercent");
	DeleteAttribute(sld, "DontRansackCaptain");
      TakeNItems(sld, "bullet", 50);
	TakeNItems(sld, "cartridge", 50);
	TakeNItems(sld, "grapeshot", 50);
	TakeNItems(sld, "GunPowder", 100);
	sld.AlwaysSandbankManeuver = true;
	sld.equip.gun = "pistol_06";
	GiveItem2Character(sld, "spyglass3");
	EquipCharacterbyItem(sld, "spyglass3");
	sld.ship.Crew.Morale = 100;
	sld.Ship.Crew.Exp.Sailors = 100;
	sld.Ship.Crew.Exp.Cannoners = 100;
	sld.Ship.Crew.Exp.Soldiers = 100;
	LAi_SetCharacterUseBullet(sld, "cartridge");
	sld.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS18;
	SetCrewQuantityFull(sld);
	sld.DontRansackCaptain = true; //не сдаваться
	sld.WatchFort = true; //видеть форты
	sld.AnalizeShips = true;  //анализировать вражеские корабли при выборе таска
	SetCharacterPerk(sld, "FastReload");
	SetCharacterPerk(sld, "HullDamageUp");
	SetCharacterPerk(sld, "SailsDamageUp");
	SetCharacterPerk(sld, "CrewDamageUp");
	SetCharacterPerk(sld, "CriticalShoot");
	SetCharacterPerk(sld, "LongRangeShoot");
	SetCharacterPerk(sld, "CannonProfessional");
	SetCharacterPerk(sld, "BasicBattleState");
	SetCharacterPerk(sld, "AdvancedBattleState");
	SetCharacterPerk(sld, "ShipDefenseProfessional");
	SetCharacterPerk(sld, "ShipTurnRateUp");
	SetCharacterPerk(sld, "StormProfessional");
	SetCharacterPerk(sld, "SwordplayProfessional");
	SetCharacterPerk(sld, "AdvancedDefense");
	SetCharacterPerk(sld, "ProfessionalDefense");
	SetCharacterPerk(sld, "CriticalHit");
	SetCharacterPerk(sld, "MusketsShoot");
	SetCharacterPerk(sld, "Sliding");
	SetCharacterPerk(sld, "Tireless");
	SetCharacterPerk(sld, "HardHitter");
	SetCharacterPerk(sld, "Gunman");
	SetCharacterPerk(sld, "GunProfessional");
	SetCharacterPerk(sld, "Sniper");
	SetCharacterGoods(sld, GOOD_BALLS, 500);
	SetCharacterGoods(sld, GOOD_GRAPES, 500);
	SetCharacterGoods(sld, GOOD_KNIPPELS, 500);
	SetCharacterGoods(sld, GOOD_BOMBS, 500);
	SetCharacterGoods(sld, GOOD_FOOD, 300); 
	SetCharacterGoods(sld, GOOD_POWDER, 2500);
	SetCharacterGoods(sld, GOOD_WEAPON, 300);
	SetCharacterGoods(sld, GOOD_MEDICAMENT, 300);
	SetCharacterGoods(sld, GOOD_RUM, 150); 
	SetCharacterGoods(sld, GOOD_PLANKS, 50);
	SetCharacterGoods(sld, GOOD_SAILCLOTH, 50);
	SetCharacterGoods(sld, GOOD_SILVER, 500);
	SetCharacterGoods(sld, GOOD_GOLD, 250);
	UpgradeShipParameter(sld, "Capacity");
	//в морскую группу кэпа
	string sGroup = "MushketCapShip";
	Group_FindOrCreateGroup(sGroup);
	Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
	Group_LockTask(sGroup);
	Group_AddCharacter(sGroup, sld.id);
	Group_SetGroupCommander(sGroup, sld.id);
	SetRandGeraldSail(sld, sti(sld.Nation)); 
	sld.quest = "InMap"; //личный флаг искомого кэпа
	sld.city = "Shore47"; //определим колонию, из бухты которой с мушкетом выйдет
	sld.cityShore = GetIslandRandomShoreId(GetArealByCityName(sld.city));
	sld.quest.targetCity = SelectAnyColony(sld.city); //определим колонию, в бухту которой он придет
	sld.quest.targetShore = "Shore126";
	pchar.questTemp.Mushkett2x2.Shore = GetIslandRandomShoreId(GetArealByCityName(sld.quest.targetCity));
	Log_TestInfo("Кэп с мушкетом вышел из: " + sld.city + " и направился в: " + sld.quest.targetShore);
	//==> на карту
	sld.mapEnc.type = "trade";
	//выбор типа кораблика на карте
	sld.mapEnc.worldMapShip = "quest_ship";
	sld.mapEnc.Name = "Бриг 'Стрела'";
	int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sld.quest.targetCity), GetArealByCityName(sld.city))+15; //дней доехать даем с запасом
	Map_CreateTrader(sld.cityShore, sld.quest.targetShore, sld.id, daysQty);
	//заносим Id кэпа в базу нпс-кэпов
	sTemp = sld.id;
	NullCharacter.capitainBase.(sTemp).quest = "mushkett2x2"; //идентификатор квеста
	NullCharacter.capitainBase.(sTemp).questGiver = "none"; //запомним Id квестодателя для затирки в случае чего
	NullCharacter.capitainBase.(sTemp).Tilte1 = "SeekDoubleMushket"; //заголовок квестбука
	NullCharacter.capitainBase.(sTemp).Tilte2 = "SeekDoubleMushket"; //имя квеста в квестбуке
	NullCharacter.capitainBase.(sTemp).checkTime = daysQty + 5;
    NullCharacter.capitainBase.(sTemp).checkTime.control_day = GetDataDay();
    NullCharacter.capitainBase.(sTemp).checkTime.control_month = GetDataMonth();
    NullCharacter.capitainBase.(sTemp).checkTime.control_year = GetDataYear();
}


















