void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sTemp;
	
	DeleteAttribute(&Dialog,"Links");
	
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if(NPChar.id == "Andre_Abel_Quest_Officer_1") // Офицер в резиденции Кюрасао. Сопровождение флейта "Орион"
			{
				dialog.text = LinkRandPhrase("Будьте вежливы с господином генерал-губернатором.", "Не смей отвлекать меня!", "Учти, у генерал-губернатора очень мало времени!");
				link.l1 = "Да знаю я, знаю...";
				link.l1.go = "exit";
			}
			
			if(NPChar.id == "Jack_V")	// Диего
			{
				dialog.text = GetSexPhrase("Вот значит, каков из себя ''вестовой Моргана''...","А-а... Так это ты принесла...") + "Ну что ж, добро пожаловать в наши хоромы.";
				//	link.l1 = "Да иди ты к черту!";
				//	link.l1.go = "Andre_Abel_Quest_In_Prison_Wrong_Way_1";
				link.l2 = "Быстро же у вас информация распространяется... За гостеприимство спасибо, но я здесь ненадолго.";
				link.l2.go = "Andre_Abel_Quest_In_Prison_1";
			}
			break;
			
		// Диего. Квест "Сопровождение флейта 'Орион'" -->
		case "Andre_Abel_Quest_In_Prison_Wrong_Way_1":
			dialog.text = "Напрасно ты так... Но, это твое право... Уже завтра днем наши безжизненные тела будут посмешищем публике...";
			link.l1 = "Меня скоро выпустят... Вот увидишь...";
			link.l1.go = "Andre_Abel_Quest_In_Prison_Wrong_Way_2";
			link.l2 = "Да... Если будет так, как ты говоришь, то нужно скорее выбираться отсюда...";
			link.l2.go = "Andre_Abel_Quest_In_Prison_2";
			break;
			
		case "Andre_Abel_Quest_In_Prison_Wrong_Way_2":
			dialog.text = "Надеюсь на это...";
			link.l1 = "Я тоже.";
			link.l1.go = "Andre_Abel_Quest_In_Prison_Wrong_Way_3";
			break;
			
		case "Andre_Abel_Quest_In_Prison_Wrong_Way_3":
			DialogExit();
			SetLaunchFrameFormParam("Прошло два дня...", "", 5, 3);
			LaunchFrameForm();
			break;

		case "Andre_Abel_Quest_In_Prison_1":
			dialog.text = "Верно, ненадолго... Я слышал разговор охранников, из него, кстати, и про ''вестового'' узнал... Они говорили, что тебя завтра повесят.";
			link.l1 = "Вот дьявол! Слишком скор на руку этот Бек. Совсем не оставил времени на размышления...";
			link.l1.go = "Andre_Abel_Quest_In_Prison_2";
			break;
			
		case "Andre_Abel_Quest_In_Prison_2":
			dialog.text = "А чего здесь размышлять? Раз вешать собираются завтра - значит бежать нужно сегодня.";
			link.l1 = "Хо! А ты ему, случайно, не родственник? Так же скор в принятии решений. Как звать-то тебя, приятель?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_3";
			break;
			
		case "Andre_Abel_Quest_In_Prison_3":
			dialog.text = "Зовут меня Капитан Джек Воробей, смекаешь?";
			link.l1 = "Джек Воробей? Знакомое имя... Где-то я его уже слышал..."; 
			link.l1.go = "Andre_Abel_Quest_In_Prison_4";
			break;
			
		case "Andre_Abel_Quest_In_Prison_4":
		PlaySound("interface\Jack_1.wav");
			dialog.text = "Вообще-то капитан Джек Воробей, мой друг!";
			link.l1 = "Хм, Капитан? А где же Ваш корабль, капитан?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_5";
			break;
			
		case "Andre_Abel_Quest_In_Prison_5":
			dialog.text = "Корабль? Присматриваю... Вернее присматривал... Его тут...";
			link.l1 = "Хех, дай угадаю: ты пытался украсть корабль, но потерпел фиаско и теперь оказался за решеткой?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_6";
			break;

		case "Andre_Abel_Quest_In_Prison_6":
			dialog.text = "Пытался не украсть, а реквизировать. Реквизировать - морской термин. Здесь, в гавани Виллемстада, стоял отличный бриг, вот его я и хотел реквизировать, собственно. Но не вышло. Почитай год здесь обретаюсь, всё никак не вздернут... Забыли видать про меня.\nА вообще я был капитаном! Целых три года я был вольным капитаном, но потом... Потом команда во главе с проклятым Барбоссой подняла бунт и высадила меня на необитаемом острове с бутылкой рома, пистолетом и одной пулей.";

			link.l1 = "Раз команда подняла бунт, то значит ты плохой капитан, приятель.";
			link.l1.go = "Andre_Abel_Quest_In_Prison_7";
			break;

		case "Andre_Abel_Quest_In_Prison_7":
			dialog.text = "Но всё-же капитан!";
			link.l1 = "Возможно ты и прав. А как ты умудрился спастись с острова?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_8";
			break;

		 case "Andre_Abel_Quest_In_Prison_8":
			dialog.text = "На морских черепахах, дружище.";
			link.l1 = "Что? Как? На черепахах?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_9";
			break;

		 case "Andre_Abel_Quest_In_Prison_9":
			dialog.text = "Когда меня высадили на необитаемом острове, я лежал на отмели три дня и три ночи, чтобы морская живность ко мне немного привыкла, и на чётвертый день мимо меня проплывали две здоровенных черепахи. Я их схватил, заарканил и добрался на них до Ямайки.";
			link.l1 = "Здорово... Двух черепах заарканил... А где ты взял верёвку?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_10";
			break;

		case "Andre_Abel_Quest_In_Prison_10":
			dialog.text = "Сплёл... Сплёл из шерсти... Со спины.";
			link.l1 = "Мда...Ты меня за дурака держишь?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_11";
			break;

		case "Andre_Abel_Quest_In_Prison_11":
			dialog.text = "Не кипятись. На самом деле на том острове у контрабандистов был тайник с ромом и припасами. И я три дня кутил на всю катушку в полном одиночестве. Через три дня приплыли контрабандисты и в обмен на кое-что решили взять меня с собой.";

			link.l1 = "Так бы сразу. Кстати, а каким кораблём ты командовал?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_12";
			break;

		case "Andre_Abel_Quest_In_Prison_12":
			dialog.text = "''Чёрной Жемчужиной''!";
			link.l1 = "Ага. Так я тебе и поверил.";
			link.l1.go = "Andre_Abel_Quest_In_Prison_13";
			break;

		case "Andre_Abel_Quest_In_Prison_13":
			dialog.text = "Но это чистая правда! Этот корабль беспоподобен и горд, он чуть ли не огромен и при этом он чуть ли не летит по ветру... Эх, ''Жемчужина''... Некогда, когда я  работал на благо Английской Ост-Индийской Торговой Компании и на заре моей пиратской карьеры у ''Жемчужины'' было другое название...";
			link.l1 = "Какое?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_14";
			break;

		case "Andre_Abel_Quest_In_Prison_14":
			dialog.text = "''Распутная Девка''. Но после одного случая, я решил изменить название корабля на 'Чёрная Жемчужина'...";
			link.l1 = "''Распутная Девка'', говоришь... Джек Воробей, ''Распутная Девка''... Погоди-ка, а не ты ли случаем утопил одного испанского адмирала, который отправил на тот свет тысячи пиратов? Слыхал я одну байку, что некий испанский адмирал объявил войну пиратам, которые однажды жестоким образом убили всю его семью. Рассказывают, что он был жесток и бепощаден, он не ведал горечи поражений, а все благодаря своему гению военного моряка...";

			link.l1.go = "Andre_Abel_Quest_In_Prison_115";
			break;

case "Andre_Abel_Quest_In_Prison_115":
			dialog.text = "...";
			link.l1 = "Другие же приписывают его исключительную удачу загадочному артефакту ''Черная Орхидея'', которым он якобы владел, что сказки, конечно... Однако, говорят, что своими действиями он поставил под угрозу само существование пиратства в Карибском Море... И поговаривают, что к Морскому Дьяволу его отправил некий Воробей, который командовал судном под названием ''Распутная Девка''...";
			link.l1.go = "Andre_Abel_Quest_In_Prison_15";
			break;


		case "Andre_Abel_Quest_In_Prison_15":
			dialog.text = "Да, было дело. Знавал я одного испанца, звали его как-то по испански... Сала... Самовар... Саламандр... Чёрт, из головы вылетело!";
			link.l1 = "А не Салазар ли?";
			link.l1.go = "Andre_Abel_Quest_In_Prison_16";
			break;

		case "Andre_Abel_Quest_In_Prison_16":
			dialog.text = "Да, точно! Армандо Салазар - гроза пиратов. Однажды, после того как мы разграбили Санта - Каталину, мы возвращались на Тортугу и где-то между Кайманом и Кубой, около Северных Рифов мы нарвались на корабль этого Салазара - ''Немую Марию''.";
			link.l1 = "...";
			link.l1.go = "exit";
			pchar.questTemp.LSC.Natanstory = "History_1";
			AddDialogExitQuest("Video_story");
			NextDiag.TempNode = "Andre_Abel_Quest_In_Prison_17";
		break;

		case "Andre_Abel_Quest_In_Prison_17":
			dialog.text = "Казалось, что дело проиграно и я было решил, что пора последовать благороднейшей из пиратских традиций - спасатся бегством, но... Возник у меня один план. В юности я ходил под началом самого Бучера и знал Северные Рифы как свои пять пальцев, ибо у Бучера там был схрон и мы частенько туда захаживали... Я решил воспользоваться преимуществом ''Жемчужины'' в оснастке и маневренности и не прогадал. Салазар погнался за мной, что было вполне ожидаемо, а я в свою очередь неожиданно совершил резкий разворот и мощная, но неповоротливая ''Немая Мария'' налетела на рифы и взлетела вскоре на воздух. Вряд ли кто выжил.\nВо всяком случае про славного адмирала Армандо Салазара никто более не слышал. Собственно, после этого я и решил переменовать корабль в ''Чёрную Жемчужину''. Нам дико повезло в тот день. Жаль, что удача с тех пор покинула меня. После этой воистину героической победы я набрал много ребят на Тортуге, большую и, как тогда казалось, славную команду и отправился на поиски золота самого Кортеса, а потом случился бунт, необитаемый остров...\nЭх... ''Жемчужина''... ''Черная Жемчужина'' - это не просто киль, паруса, оснастка, хоть без них и нельзя... ''Черная Жемчужина'' - это свобода... Эх... Хотя, возможно мне и повезло. Говорят, что корабль и команда подвеглись какому-то страшному проклятью. Поделом им, мятежникам.\nКто-то говорит, что ''Жемчужину'' утопил Чёрная Борода и заточил в бутылку, кто его знает... Что мы всё обо мне, да обо мне. Как тебя-то звать, ''вестовой Моргана''? Чем по жизни занимаешься?";
			link.l1 = "Меня зовут " + GetFullName(pchar) + "... Я вольный капитан, да что теперь с этого, всё равно завтра повесят... "; 
			link.l1.go = "Andre_Abel_Quest_In_Prison_18";
			break;

		case "Andre_Abel_Quest_In_Prison_18":
			dialog.text = "Не печалься, приятель. Я же уже тут как год ошиваюсь, вот я уже и отмычки, и клинки приготовил. Только в одиночку через охрану не пробиться - вот и жду попутчика. А ты парень крепкий и фехтом владеешь, судя по манере держаться... Да и бежать тебе сам Бог велел. Так что лучшего попутчика и не сыскать. Хе-хе...";
			link.l1 = "Да уж, с сокамерником мне определённо повезло. А отмычки не подведут?"; 
			link.l1.go = "Andre_Abel_Quest_In_Prison_19";
			break;

		case "Andre_Abel_Quest_In_Prison_19":
			dialog.text = "Шутишь? Я дверь в камеру почти каждую ночь отпираю, петли маслом мажу. Первое время даже по коридорам прогуливался, но это опасно слишком... Так что здесь у меня всё в порядке.";
			link.l1 = "Ну, раз так, то вперёд? Где наша не пропадала!";
			link.l1.go = "Andre_Abel_Quest_In_Prison_20";
			break;
			
		case "Andre_Abel_Quest_In_Prison_20":
			dialog.text = "Свечку за упокой поставь, если живым не выберусь, а то не с руки как-то без причастия...\nНу, держи клинок... Обмотай черен платком, видишь - лезвие без рукояти.";
			link.l1 = "Эх-ех, не фламберг конечно, но уж чего есть, с тем на рожон и полезем... Ну, с Богом.";
			link.l1.go = "Andre_Abel_Quest_In_Prison_21";
			break;

		case "Andre_Abel_Quest_In_Prison_21":
			dialog.text = "Погоди, возьми эти бутылки. Там  винцо, хорошее винцо, тебе три бутылки и мне три бутылки, всё честно. Я их у солдат тырил потихоньку, уверен они нам пригодятся.";
			link.l1 = "Да, пригодятся точно. Бульк-бульк...";
			link.l1.go = "Andre_Abel_Quest_In_Prison_22";
			break;

		case "Andre_Abel_Quest_In_Prison_22":
			dialog.text = "Да не пей ты! Они для дела! Всё, вперёд! С Богом! ";
			link.l1 = "Ну, удачи нам! С Богом!";
			link.l1.go = "Andre_Abel_Quest_In_Prison_23";
			break;

		case "Andre_Abel_Quest_In_Prison_23":
			DialogExit();
			NextDiag.CurrentNode = "Andre_Abel_Quest_In_Prison_24";
			LAi_SetCitizenType(NPChar);
			PChar.items.topor_020 = 1;
			PChar.items.potionwine = 3;
			PChar.equip.blade = "topor_020";
			NPChar.items.topor_020 = 1;
			NPChar.equip.blade = "topor_020";
			NPChar.items.pistol1 = 1;
			NPChar.items.compass1 = 1;
			NPChar.items.bullet = 1;
			NPChar.items.potionwine = 3;

	SetFunctionLocationCondition("Andre_Abel_Quest_Liberty", "Villemstad_ExitTown", false);
			SetFunctionNPCDeathCondition("Andre_Abel_Quest_Martin_Bleker_Is_Dead", "Jack_V", false);
			ChangeCharacterAddressGroup(NPChar, "Villemstad_prison", "goto", "goto12");
			DoFunctionReloadToLocation("Villemstad_prison", "goto", "goto23", "Andre_Abel_Quest_Runaway_From_Prison");
			break;
			
		case "Andre_Abel_Quest_In_Prison_24":
			dialog.text = RandPhraseSimple("Нам бы поторапливаться нужно.", "Скорее, пока охрана тревогу не подняла.");
			link.l1 = "Не суетись. Ещё не из таких передряг выбирались...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Andre_Abel_Quest_In_Prison_24";
			break;
			
		case "Andre_Abel_Quest_In_Liberty_1":
			dialog.text = "Больше года я ждал этого момента! Спасибо тебе, приятель.";
			link.l1 = "Это тебе спасибо. Не знаю, как бы я выбирался, если бы не твои отмычки да клинки.";
			link.l1.go = "Andre_Abel_Quest_In_Liberty_2";
			chrDisableReloadToLocation = false;
			break;
			
		case "Andre_Abel_Quest_In_Liberty_2":
			dialog.text = "Ну что? Разбежались? Прощай, удачи тебе.";
			link.l1 = "Прощай...";
			link.l1.go = "Andre_Abel_Quest_In_Liberty_3";
			link.l2 = "Постой. А ты - малый не промах, не хочешь поступить ко мне в команду офицером?";
			link.l2.go = "Andre_Abel_Quest_In_Liberty_4";
			break;
			
		case "Andre_Abel_Quest_In_Liberty_3":
			DialogExit();
			NPChar.LifeDay = 0;
			LAi_ActorRunToLocation(NPChar, "reload", "reload1_back", "none", "", "", "", -1);
			break;
			
		case "Andre_Abel_Quest_In_Liberty_4":
			if (GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) > 10 && GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 15)
			{
				dialog.text = "Офицером? Хм, почему бы и нет, если в цене сойдемся.";
				link.l1 = "На этот счёт не волнуйся. В деньгах не обижу.";
				link.l1.go = "Andre_Abel_Quest_In_Liberty_5";
			}
			else
			{
				dialog.text = "Нет, капитан... не обессудь, но я человек несколько другой профессии. Служба - это не для меня.";
				link.l1 = "Ладно, нет так нет. Удачи тебе.";
				link.l1.go = "Andre_Abel_Quest_In_Liberty_3";
			}
			break;
			
		case "Andre_Abel_Quest_In_Liberty_5":
			dialog.text = "Тогда я согласен!";
			link.l1 = "Вот и отлично. Добро пожаловать в команду!";
			link.l1.go = "Andre_Abel_Quest_In_Liberty_6";
			break;
			
		case "Andre_Abel_Quest_In_Liberty_6":
			dialog.text = "Спасибо тебе, капитан. Буду стараться.";
			link.l1 = "В этом я не сомневаюсь.";
			link.l1.go = "Andre_Abel_Quest_In_Liberty_7";
			break;
			
		case "Andre_Abel_Quest_In_Liberty_7":
			DialogExit();
			NPChar.Dialog.FileName = "Enc_Officer_dialog.c";
			NPChar.Dialog.CurrentNode = "hired";
			LAi_SetStayType(NPChar);
			NPChar.Greeting = "Jack_2";
			NPChar.Money   = 0;
			NPChar.Payment = true;
			NPChar.DontClearDead = true;
			AddPassenger(PChar, NPChar, false);
			NPChar.OfficerWantToGo.DontGo = true;
			NPChar.loyality = MAX_LOYALITY;
			AddQuestRecord("Andre_Abel_Quest", "19");
			AddQuestUserData("Andre_Abel_Quest", "sSex", GetSexPhrase("","а"));
			SetFunctionExitFromLocationCondition("Andre_Abel_Quest_Delete_Martin", PChar.location, false);
			break;
        	// <-- Джек. Квест "Сопровождение флейта 'Орион'"
        
		//--> работорговец, пинас
		case "TakeShoreCap":
    		dialog.text = "Ах ты каналья! Не ожидал?";
    		link.l1 = "Не ожидал чего?";
    		link.l1.go = "Node_1";
		break;
		
		case "Node_1":
			dialog.text = "Ха-ха! Рабов здесь нет! Ты ведь за ними явил"+ GetSexPhrase("ся","ась") +"?";
			link.l1 = "Ах ты... А я и думаю, откуда на торговом пинасе солдаты, да еще так много... Ловушка!!";
			link.l1.go = "Node_2";
		break;
		
 		case "Node_2":
			dialog.text = "Да, мерзав"+ GetSexPhrase("ец","ка") +", это ловушка. А я не торговец, а боевой офицер! И хотя бой ты выиграл, тебе все равно не уйти от правосудия.";
			link.l1 = "Это почему же? Сейчас покончу с тобой, пущу твое корыто на дно - и никто ничего не узнает.";
			link.l1.go = "Node_3";
		break;
		
 		case "Node_3":
			dialog.text = "Ошибаешься. Ваши темные делишки с местным ростовщиком раскрыты. Скоро об этом узнает генерал-губернатор, и вам не отвертеться от виселицы. Ну а я уж постараюсь, чтобы ты до нее не дожил.";
			link.l1 = "Попробуй, ищейка губернаторская!";
			link.l1.go = "Node_4";
		break;
		
 		case "Node_4":
 		    pchar.questTemp.Slavetrader = "TakeShoreCap_end"; //это состояние квеста для проверки у квестодателя
            AddQuestRecord("Slavetrader", "13");
			AddQuestUserData("Slavetrader", "sShipName", pchar.questTemp.Slavetrader.ShipName);
            pchar.quest.Slavetrader_DieHard.over = "yes";
			pchar.quest.Slavetrader_AfterBattle.over = "yes";
			pchar.quest.Slavetrader_ShoreShipsOver.over = "yes";
            Island_SetReloadEnableGlobal(pchar.questTemp.Slavetrader.Island, true);
		    LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Slave_arest":
			dialog.text = "" + GetFullName(pchar) + ", именем закона вы арестованы! Немедленно сдайте оружие и следуйте за нами!";
			link.l1 = "Что это значит, офицер? На каком основании?";
			link.l1.go = "Slave_arest_1";
		break;
		
		case "Slave_arest_1":
			dialog.text = "Не прикидывайтесь овечкой, капитан! Ваши грязные делишки раскрыты. А за резню, что вы учинили, и за потопленный корабль " + NationNameGenitive(sti(npchar.nation)) + ", вы будете болтаться на нок-рее!";
			link.l1 = "Ну раз так... то мне терять уже нечего, не так ли? Держитесь, псы!";
			link.l1.go = "Slave_arest_2";
		break;
		
		case "Slave_arest_2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			LAi_SetWarriorTypeNoGroup(npchar);
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
            LAi_group_SetCheck("EnemyFight", "OpenTheDoors");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//<--работорговец пинас
		
		//--> работорговец, крыса в доме
		case "Rat_bandos":
			dialog.text = "Эй! Что ты тут забыл? Давай, вали отсюда!";
    		link.l1 = "Что-то ты не очень любезен, милейший. Не здесь ли прячется эта крыса Гонтьер, а?";
    		link.l1.go = "Node_rat_1";
		break;
			
		case "Node_rat_1":
			dialog.text = "Нет здесь никакого Гонтьера! Если это все, что ты хотел"+ GetSexPhrase("","а") +" узнать - убирайся!";
			link.l1 = "Сдается мне, что ты лжешь. Сейчас мы обыщем дом и посмотрим...";
			link.l1.go = "Node_rat_2";
		break;
		
 		case "Node_rat_2":
			dialog.text = "А-ать! Франсуа! Беги! Ребята, ко мне, на помощь!";
			link.l1 = "Ах ты пес!";
			link.l1.go = "Node_rat_3";
		break;
		
		case "Node_rat_3":
            LAi_SetPlayerType(pchar);
            LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "EnemyFight");
            LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Slavetrader_findTortugaRat1");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Rat_lover":
			dialog.text = "Ай! Не трогайте меня!";
    		link.l1 = "Где Франсуа Гонтьер? Отвечай, маленькая дрянь, или последуешь за своими дружками!";
    		link.l1.go = "Rat_lover_1";
		break;
			
		case "Rat_lover_1":
			dialog.text = "Нет, нет, я все скажу! Он выпрыгнул в окно и убежал, видимо, на свой корабль.";
    		link.l1 = "Какой корабль? В порту нет его корабля, я это знаю. Не лги мне, милочка, хуже будет...";
    		link.l1.go = "Rat_lover_2";
		break;
			
		case "Rat_lover_2":
			dialog.text = "Я не лгу, клянусь! Он говорил, что пришвартовался у маленького островка, на котором маяк, а до города добрался на шлюпке... Он там! Не трогайте меня!";
    		link.l1 = "Ладно, похоже ты не врешь. Сиди тихо и не дергайся. А вообще, знакомых надо с умом выбирать. Хотя, какой у тебя ум - по глазам вижу, дура-дурой.";
    		link.l1.go = "Rat_lover_3";
			pchar.quest.Slavetrader_RatAttack.win_condition.l1 = "location";
            pchar.quest.Slavetrader_RatAttack.win_condition.l1.location = "Tortuga";//отправляем в локацию
            pchar.quest.Slavetrader_RatAttack.function = "Slavetrader_RatCorvette";//создание корвета
			SetFunctionTimerCondition("Slavetrader_RatCorvetteOver", 0, 0, 1, false);
		break;
			
		case "Rat_lover_3":
 		    LAi_SetPlayerType(pchar);
            SetCharacterRemovable(npchar, false);
            LAi_SetActorType(npchar);
			npchar.lifeday = 0;
			AddQuestRecord("Slavetrader", "21_9");
            DialogExit();
		break;
		//<--работорговец крыса в доме
		
		//--> работорговец, беглые рабы
		case "Slave_woman":
			dialog.text = "Пощадите! Пощадите! Мы сдаемся!";
    		link.l1 = "Вот как? А ну, все живо марш на корабль в трюмы! Кто сделает неловкое движение - пристрелю на месте!";
    		link.l1.go = "exit";
			AddDialogExitQuestFunction("Slavetrader_Slavewoman");
		break;
		//<--работорговец беглые рабы
			
		//ОЗГ, Карлос Кассир
		case "Carlos":
            dialog.text = "Убирайся, кто бы ты ни был – видишь, я занят.";
            link.l1 = "Возможно мне и впрямь следует зайти попозже... здесь сейчас слишком воняет. Право не знал, что в такие заведения пускают свиней.";
            link.l1.go = "Carlos_7";
        break;
        
       	case "Carlos_3":
			Dialog.Text = "Нет, вы только гляньте! Смотри, не пожалей об этом, капитанишка, никто не назовет Карлоса Кассира трусом безнаказанно! Встретимся за городскими воротами через час, и продолжим нашу беседу, чтобы не портить полы сего заведения твоими кишками\nНадеюсь, твоя храбрость тебя не оставит, а твои слова я запихну тебе в...";
			link.l1 = "Довольно, уважаемый. Прибереги пыл для подтверждения своих слов. Я буду на месте через час, а если не найду там тебя, то будь уверен - слава о трусости кондотьера Кассира найдет тебя везде, в какую бы щель ты не забился.";
			link.l1.go = "Carlos_4";
			pchar.questTemp.Headhunter = "hunt_carlos_fight";
        break;
		
		case "Carlos_4":
			LAi_LocationDisableOfficersGen(pchar.questTemp.Headhunter.City + "_ExitTown", true);//офицеров не пускать
			locations[FindLocation(pchar.questTemp.Headhunter.City + "_ExitTown")].DisableEncounters = true; //энкаутеры закроем
			AddQuestRecord("Headhunt", "2_1");
			pchar.quest.HeadhunterTimer.win_condition.l1 = "Timer";
			pchar.quest.HeadhunterTimer.win_condition.l1.date.hour  = sti(GetTime() + 1);
			pchar.quest.HeadhunterTimer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.HeadhunterTimer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.HeadhunterTimer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.HeadhunterTimer.function = "CarlosDuel";
			SetFunctionTimerCondition("CarlosDuelOver", 0, 0, 2, false);
			NextDiag.CurrentNode = "Carlos_5";
			DialogExit();
		break;

		case "Carlos_5":
			Dialog.Text = "Ну, чего тебе еще?";
			link.l1 = "Просто решил напомнить тебе о нашей встрече.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Carlos_5";
        break;

		case "talk_off_town_Carlos":
			Dialog.Text = "Ну вот и свиделись, болтливый щенок! Сейчас ты пожалеешь, что родился на свет!";
			link.l1 = "Я гляжу, ты привел с собой компанию, пес? Тем лучше – вам не будет одиноко в аду. К делу!";
			link.l1.go = "Carlos_6";
		break;

		case "Carlos_6":
			LAi_SetPlayerType(pchar);
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("EnemyFight", "CarlosDie");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
	
		case "Carlos_7":
			dialog.text = "Подожди-ка парень... мне не нравится твой тон. Ты хоть представляешь, с кем разговариваешь, герой?";
			link.l1 = "Я говорю с пьяной свиньей, которая заняла заведение, где я собирался провести вечер. И теперь здесь все безнадежно провоняло, словно в хлеву – какая досада, правда?";
			link.l1.go = "Carlos_8";
		break;
    
		case "Carlos_8":
			dialog.text = "Ты смелый щенок, как я погляжу... Я Карлос Кассир – мое имя знает каждый в этом городе и во многих других – и моя шпага сочла уже полсотни кичливых болтунов. Мой тебе совет – выметайся отсюда, пока я не подрезал тебе язык. Не хочу портить хороший вечер. ";
			link.l1 = "Для свиньи ты удивительно вежлив. Либо, что вероятнее – это трусость... право даже жаль.";
			link.l1.go = "Carlos_3";
			int n = FindLocation(pchar.questTemp.Headhunter.City + "_Brothel");
			locations[n].reload.l2.disable = true;
		break;
		//ОЗГ, Карлос Кассир
		
		//ОЗГ, Ганнибал Хоум
		case "Houm":
            dialog.text = "Уйди, человек с моря. Ты стоишь на пути черного льва.";
        	link.l1 = "Вежливость удел людей, но не животных – вижу, тебе она не знакома.";
            link.l1.go = "Houm_1";
        break;
		
		case "Houm_1":
            dialog.text = "Корабельная мышь пытается разозлить льва? Смело, но глупо – лев не замечает тех, кто под его ногами копошится в земле.";
        	link.l1 = "Может быть ты заметишь мою шпагу, сударь ''лев''? ";
            link.l1.go = "Houm_2";
        break;
		
		case "Houm_2":
            dialog.text = "Храбрая маленькая мышь... Тебе ведь заплатили голландские шакалы так? Они хотят чужими руками добыть льва, нанесшего им рану\nИ сулят золото тому, кто не струсит. Я знаю - только золото заставляет вас, белых людей, забывать страх. Вспомни его, пока лев не рассердился всерьез.";
        	link.l1 = "Довольно рассуждений, черная образина. Давай оставим эту дипломатию и поговорим открыто.";
            link.l1.go = "Houm_3";
        break;
		
		case "Houm_3":
            dialog.text = "Черный лев выслушает, но будь краток, голландский наемник.";
        	link.l1 = "Я не работаю на власти, черный пес. На голландском корабле, который ты утопил, был мой брат. И я хочу, чтобы ты ответил за его смерть.";
            link.l1.go = "Houm_4";
        break;
		
		case "Houm_4":
            dialog.text = "Ха, лев удивлен. Перед ним не мышь, за голландские монеты возомнившая себя охотником, но волк, желающий отомстить за собрата? Достойно\nЛев принимает твой вызов. Не стоит тревожить покой этого города – лев будет ждать волка в море. Сражайся, как подобает, и умри как воин, а лев съест твое сердце, и храбрость волка продолжит жить после его смерти.";
        	link.l1 = "Отправляйся на свой корабль, мразь, и готовься утонуть вместе с ним!";
            link.l1.go = "Houm_5";
			AddQuestRecord("Headhunt", "6");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
			pchar.quest.Headhunter_HoumAttack.win_condition.l1 = "location";
            pchar.quest.Headhunter_HoumAttack.win_condition.l1.location = pchar.questTemp.Headhunter.Island;//отправляем в локацию
            pchar.quest.Headhunter_HoumAttack.function = "Headhunter_CreateHoumShips";//создание кораблей
        break;
		
		case "Houm_5":
			if (findsubstr(PChar.location, "_tavern" , 0) != -1)
			{
				DialogExit();
				NextDiag.CurrentNode = "Houm_6";
			}
			else
			{
				LAi_SetActorType(npchar);
				LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15.0);
			}
			DialogExit();
        break;
		
		case "Houm_6":
			Dialog.Text = "Ну, чего тебе еще?";
			link.l1 = "Просто решил напомнить тебе о нашей встрече.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Houm_6";
        break;
		
		case "RatOfficer":
			int iGoods1 = 100 - GetSquadronGoods(Pchar, GOOD_EBONY);
			int iGoods2 = 100 - GetSquadronGoods(Pchar, GOOD_MAHOGANY);
			//int iGoods3 = 200 - GetSquadronGoods(Pchar, GOOD_SANDAL);
			if(pchar.questTemp.Headhunter == "Rat_officer" && GetCompanionQuantity(pchar) == 1 && 2-sti(RealShips[sti(pchar.ship.type)].Class) <= 0)
			{
				
				if(iGoods1 < 1 || iGoods2 < 1)
				{
					dialog.text = "Ну, чего тебе? Проваливай, я не в настроении болтать.";
					link.l1 = "Я только из рейса... Хочу выпить, а не с кем. Составишь компанию? Я угощаю!";
					link.l1.go = "RatOfficer_1";
				}
				else
				{
					dialog.text = "Ну, чего тебе? Проваливай, я не в настроении болтать.";
					link.l1 = "Да я и не собирался с тобой трепаться. Счастливо отдохнуть.";
					link.l1.go = "exit";
					NextDiag.TempNode = "RatOfficer";
				}
				break;
			}
			dialog.text = "Чего тебе надо? Проваливай, я не в настроении болтать.";
			link.l1 = "Да я и не собирался с тобой трепаться. Счастливо отдохнуть.";
			link.l1.go = "exit";
			NextDiag.TempNode = "RatOfficer";
		break;
		
		case "RatOfficer_1":
			dialog.text = "А-а, ну тогда другое дело. Присаживайся.";
			link.l1 = "Вот! Ты настоящий моряк!";
			link.l1.go = "RatOfficer_1_sit";
		break;
		
		case "RatOfficer_1_sit":
			NextDiag.CurrentNode = "RatOfficer_2";
			LAi_SetActorType(npchar);
			LAi_ActorSetSitMode(npchar);
			LAi_ActorDialogDelay(npchar, pchar, "", 1.5);
			DoQuestReloadToLocation("Tortuga_tavern", "sit", "sit1", "");
			LAi_SetSitType(Pchar);
			DialogExit();
		break;
		
		case "RatOfficer_2":
			dialog.text = "Наливай, парень! Смотрю, ты не меньше, как капитан! Откуда путь держишь?";
			link.l1 = "Аргх, какой ром! Что? А, с Мартиники прибыли мы, с Мартиники. Торгуем, потихоньку.";
			link.l1.go = "RatOfficer_3";
		break;
		
		case "RatOfficer_3":
			dialog.text = "Торгуете? Ну, это дело хорошее. Мы вот тоже торговцы - видел пинас в порту?";
			link.l1 = "Да, торговля - дело хорошее, только пираты, проклятые, совсем житья не дают... Даже на караваны нападают, не то, что на одиночные корабли. А мой хозяин, будь он неладен, закупил полный трюм ценной древесины...ик!";
			link.l1.go = "RatOfficer_4";
		break;
		
		case "RatOfficer_4":
			dialog.text = "Богатый, наверное, твой хозяин?";
			link.l1 = "Да уж не бедный. Жадный только сильно. Говорил я ему - снаряди эскорт, найми судно охранения, ну, поищи попутчика, в крайнем случае... так нет же - денег ему жалко! Придется до самого Белиза в одиночку идти.";
			link.l1.go = "RatOfficer_5";
		break;
		
		case "RatOfficer_5":
			dialog.text = "Да, в море нынче небезопасно. А все проклятые буканьеры...ик! Охотники! Да какие они охотники! На торговцев честных, таких как мы с тобой, они охотники...";
			link.l1 = "Да, ты прав, черт возьми! Все из-за них, богоотступников. Эх, и как это одному от Тортуги до Белиза добраться? А ведь еще по пути в залив Гибели зайти надо - хозяин велел с индейцами тамошними сделку провести - камушков драгоценных у них за бесценок прикупить, да и запасы воды пресной пополнить... Слушай, а ты часом не в том направлении курс держишь? Может...";
			link.l1.go = "RatOfficer_6";
		break;
		
		case "RatOfficer_6":
			dialog.text = "Нет, мы совсем...ик! Совсем в другую сторону собираемся.";
			link.l1 = "Эх, жаль. Ну, будем молится Всевышнему, чтобы он охранил нас в пути... На пушки надежды мало - в трюме все место товар занимает, для ядер и пороха места-то почти и не осталось... Вот она, жадность людская!";
			link.l1.go = "RatOfficer_7";
		break;
		
		case "RatOfficer_7":
			dialog.text = "Жадность... Жадность - это... ик, плохо. Считают каждый песо, из-за золотой монеты удавиться готовы. За своей мошной и света Божьего не видят и другим жить не дают. Я прав, капитан?";
			link.l1 = "Ты сто раз прав, дружище! Вот нападут пираты - а мне даже и отбиваться нечем. Зарядов в орудиях на два залпа, и команды абордажной три калеки и два салаги... Эх, доля наша, доля...";
			link.l1.go = "RatOfficer_8";
		break;
		
		case "RatOfficer_8":
			dialog.text = "Да не переживай ты так! Что в первый раз, что ли? Давай лучше выпьем, а то мне уже пора на свою посудину возвращаться.";
			link.l1 = "Ну, давай еще по одной, и я тоже отчаливаю... Все семде-е-сят пять не вернулись до-о-мой, они потону-у-ли в пучине морской... Прощай, дружище...";
			link.l1.go = "RatOfficer_9";
			pchar.quest.Headhunter_Ratgulf.win_condition.l1 = "location";
            pchar.quest.Headhunter_Ratgulf.win_condition.l1.location = "Shore_ship2";//отправляем в локацию
            pchar.quest.Headhunter_Ratgulf.function = "Headhunter_Ratgulf";
			SetFunctionTimerCondition("Headhunter_RatgulfOver", 0, 0, 20, false);//таймер
		break;
		
		case "RatOfficer_9":
			pchar.quest.Headhunter_RatOfficerOver.over = "yes";
			LAI_SetPlayerType(pchar); 
			LAI_SetSitType(npchar);
            DoQuestReloadToLocation("Tortuga_tavern", "goto", "goto2", "");
			AddQuestRecord("Headhunt", "18"); 
			pchar.questTemp.Headhunter = "Rat_gulf";
			NextDiag.CurrentNode = "RatOfficer_10";
			npchar.lifeDay = 0;
			DialogExit();
		break;
		
		case "RatOfficer_10":
			dialog.text = "Пя-ятна-адца-ать человек, на сундук мертвеца... ик!";
			link.l1 = "Понятно.";
			link.l1.go = "exit";
			NextDiag.TempNode = "RatOfficer_10";
		break;
		
		//ОЗГ, кэп-Крыса
		case "Rat_talk":
			dialog.text = "Аргх! Так ты - не торговец?";
			link.l1 = "Нет, Крыса. На этот раз ты оплошал. Вместо ценного дерева тебя ждет холодная сталь и горячий свинец. Твои похождения закончатся здесь, в этой бухте.";
			link.l1.go = "Rat_talk_1";
		break;
		
		case "Rat_talk_1":
			dialog.text = "Так просто я не сдамся, хотя абордаж уже проигран. Ты еще узнаешь, что значит связаться с Крысой! Черная борода отомстит за меня!";
			link.l1 = "Сейчас ты будешь рассказывать свои басни чертям в аду. К бою, мерзавец!";
			link.l1.go = "Rat_talk_exit";
		break;
		
		case "Rat_talk_exit":
 		    pchar.questTemp.Headhunter = "hunt_rat_yes1"; 
            AddQuestRecord("Headhunt", "23");
			AddQuestUserData("Headhunt", "sSex", GetSexPhrase("","а"));
            pchar.quest.Headhunter_DieHard.over = "yes";
			pchar.quest.Headhunter_AfterBattle.over = "yes";
            Island_SetReloadEnableGlobal("Beliz", true);
		    LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "RatHunters":
			//dialog.text = "...";
			link.l1 = "А?! Что? Что вы здесь делаете, черт побери? Кто вас сюда впустил?";
			link.l1.go = "RatHunters_1";
		break;
		
		case "RatHunters_1":
			dialog.text = "Чёрная Борода передает тебе привет...";
			link.l1 = "Что? А-ать, дьявол!!";
			link.l1.go = "RatHunters_2";
		break;
		
		case "RatHunters_2":
			LAi_SetFightMode(pchar, true);
			LAi_LockFightMode(pchar, false);
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "RatHunters_Dead");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Halen":
			dialog.text = "Вы меня толкнули, любезный! В этом есть некий смысл, или это недоразумение?";
			link.l1 = "Вы - Мартин ван Хален?";
			link.l1.go = "Halen_1";
		break;
		
		case "Halen_1":
			dialog.text = "Да, это мое имя, но вы так и не назвали мне свое? Потрудитесь объяснить, что вам угодно, или проваливайте прочь. Не стоит испытывать мое терпение - у меня нет ни малейшего желания тратить свое время на болтовню с чернью.";
			link.l1 = "Да уж... И впрямь - банальный, обласканный властями хлыщ. От избытка вежливости вы не умрете. А вот от избытка спеси - вполне возможно. Вам не говорили, что высокомерные тупицы не задерживаются на этом свете, даже если их привечают высокопоставленные особы?";
			link.l1.go = "Halen_2";
			link.l2 = "Хм... Просто хотел познакомиться со знаменитым голландским корсаром.";
			link.l2.go = "Halen_3";
		break;
		
		case "Halen_2":
			dialog.text = "Аргх! Подобной дерзости я еще ни от кого не слышал! Не трудись отвечать – вижу, речь дается тебе с трудом. Оскорбить тебя, полагаю, мне не удастся – все эпитеты будут лишь лестью в твой адрес! Обнажи свою шпагу, червяк, если знаешь, с какого конца ее держать! Я хочу получить удовлетворение немедленно. Иначе я просто заколю тебя, как свинью!";
			link.l1 = "Держись, мерзавец!";
			link.l1.go = "Halen_fight";
		break;
		
		case "Halen_fight":
            LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "HOLLAND_CITIZENS");
			LAi_group_Attack(NPChar, Pchar);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			
		break;
		
		case "Halen_3":
			dialog.text = "Удовлетворен знакомством? А теперь – убирайся к дьяволу и прекрати мозолить глаза, деревенщина!";
			link.l1 = "Гхм...";
			link.l1.go = "exit_halen";
		break;
		
		case "Halen_4":
			dialog.text = "Опять ты? Окажи любезность – отправляйся уже в таверну, под стол к объедкам и прочим отбросам. Там тебе самое место.";
			link.l1 = "Кхм...";
			link.l1.go = "exit_halen";
			link.l2 = "Пожалуй, я поучу тебя вежливости, спесивая голландская свинья!";
			link.l2.go = "Halen_2";
			NextDiag.CurrentNode = "Halen_4";
		break;
		
		case "exit_halen":
			LAi_SetActorType(npchar);
            LAi_ActorGoToLocation(npchar, "reload", "reload2_back", "none", "", "", "Headhunter_HalenOut", -1);
            LAi_Actor2WaitDialog(npchar, pchar);
			NextDiag.CurrentNode = "Halen_4";
            DialogExit();
		break;
		
		case "Miko":
			dialog.text = "Что тебе от меня нужно?";
			link.l1 = "Так-так... Ты и есть Мико Пистольеро?";
			link.l1.go = "Miko_1";
		break;
		
		case "Miko_1":
			dialog.text = "Да, это я. Чем обязан?";
			link.l1 = "Мне нужно поговорить с тобой о Чёрной Бороде. Мне очень хочется с ним встретится.";
			link.l1.go = "Miko_2";
		break;
		
		case "Miko_2":
			dialog.text = "Ага... Ясно. Вот и свиделись. Так ты и есть тот парень, которого мы разыскиваем... Сам пришел... Ну что же, это значительно облегчает мою задачу. Не думаю, что ты так просто отсюда уйдешь.";
			link.l1 = "Да, это я. Говори, где Тич, и будешь жить.";
			link.l1.go = "Miko_3";
		break;
		
		case "Miko_3":
			dialog.text = "Ты угрожаешь мне, приятель? Напрасно. Ты здесь чужой, и мы всем поселком разорвем тебя в клочья\nЧто касается моего патрона, то он сейчас совсем недалеко. Гораздо ближе, чем ты думаешь. Но тебе никогда не найти Чёрную Бороду - потому что ты нашел меня, ха-ха-ха!!";
			link.l1 = "Ну, мерзавец, ты сам выбрал свою судьбу...";
			link.l1.go = "Miko_fight";
			pchar.questTemp.Headhunter = "miko_mustdie";
			pchar.quest.Headhunter_Miko_mustdie.win_condition.l1 = "NPC_Death";
			pchar.quest.Headhunter_Miko_mustdie.win_condition.l1.character = "Miko";
			pchar.quest.Headhunter_Miko_mustdie.function = "Miko_die";
		break;
		
		case "Miko_fight":
			chrDisableReloadToLocation = true;
            LAi_SetWarriorType(npchar);
            LAi_group_MoveCharacter(npchar, "Pearlgroup_2");
			LAi_group_Attack(NPChar, Pchar);
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
			AddQuestRecord("Headhunt", "34");
		break;
		
		case "JaHunters_0":
			dialog.text = "А вот и наш друг!";
			link.l1 = "Господи... Опять!";
			link.l1.go = "JaHunters_1";
		break;
		
		case "JaHunters_1":
			dialog.text = "Чёрная Борода просил передать тебе привет...";
			link.l1 = "А-а-ть!!";
			link.l1.go = "JaHunters_2";
		break;
		
		case "JaHunters_2":
			LAi_SetImmortal(npchar, false);
			pchar.quest.Headhunter_Find_Ja.win_condition.l1 = "location";
			pchar.quest.Headhunter_Find_Ja.win_condition.l1.location = "Curacao";
			pchar.quest.Headhunter_Find_Ja.function = "Create_Ja";
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
                                                                        LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
                                                                        LAi_group_SetCheck("EnemyFight", "FindJa");
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Ja_talk":
			dialog.text = "Ну вот и встретились, наконец... Ну что, будем убивать друг друга, или, может, поговорим?";
			link.l1 = "Рад тебя видеть. А то все приветы да приветы... Поднимай свой клинок, чёрт бородатый, я хочу покончить с тобой раз и навсегда.";
			link.l1.go = "Ja_talk_1";
			link.l2 = "Давай побеседуем, раз предлагаешь. Отсюда ты уже не сбежишь... Вот только о чем разговор, интересно?";
			link.l2.go = "Ja_talk_3";
		break;
		
		case "Ja_talk_1":
			dialog.text = "Ну что же... Тогда продолжим!";
			link.l1 = "Аргх! Держись!";
			link.l1.go = "Ja_talk_exit";
		break;
		
		case "Ja_talk_exit":
 		                         pchar.questTemp.Headhunter = "hunt_ja_yes"; 
                                                                         bQuestDisableMapEnter = false;
		                         LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle(""); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "Ja_talk_3":
			dialog.text = "Какого черта ты охотишься на меня? Зачем убил всех моих людей?";
			link.l1 = "Аргх! По-моему, это ты охотишься на меня! Что касается твоего вопроса - уж очень сильно твоя шайка отравляла жизнь людям в Ле Франсуа. Вот и порешили от вас избавиться...";
			link.l1.go = "Ja_talk_4";
		break;
		
		case "Ja_talk_4":
			dialog.text = "Вот дьявол! Роджерс всё-таки пронюхал, что мы затеваем... Надо было быть осторожнее.";
			link.l1 = "Теперь уже поздно, Эдвард. Пора заканчивать наш разговор - думаю, ты узнал всё, что хотел. Больше мне сказать тебе нечего.";
			link.l1.go = "Ja_talk_5";
		break;
		
		case "Ja_talk_5":
			dialog.text = "Подожди... Послушай, я предложу тебе другое. Ты отчаянный и толковый корсар, а я... я проиграл свою игру. У меня нет больше людей, и уже нет корабля - ты выиграл абордаж. Даже если мне удасться тебя сейчас убить, конец все равно один.\nМожет, лучше объединим силы? Я предлагаю сменить вражду на мир и готов работать с тобой, под твоим началом.";
			link.l1 = "Нет, Эдвард. Я тебе не верю. Сегодня - ты мой офицер, а завтра - воткнешь кинжал в спину? Пора завершить наше противостояние!";
			link.l1.go = "Ja_talk_1";
			link.l2 = "Ха! Вот это интересно! А ты знаешь, Эдвард - я согласен. Такого офицера, как ты, еще поискать надо. Но смотри - надумашь шутки шутить - мигом за борт отправлю!";
			link.l2.go = "Ja_talk_6";
		break;
		
		case "Ja_talk_6":
			dialog.text = "Предупреждение излишне, капитан. Для меня теперь самое безопасное место на архипелаге - твоя посудина. Можешь во мне не сомневаться. Я рад, что мы договорились.";
			link.l1 = "Добро пожаловать в команду, корсар!";
			link.l1.go = "Ja_hired";
			pchar.quest.Headhunter_AfterBattleJa.over = "yes";
		break;
		
		case "Ja_hired"://Черную бороду в офицеры
			bQuestDisableMapEnter = false;
			AddQuestRecord("Headhunt", "38");
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-20;
			characters[GetCharacterIndex("Jafarry")].lifeDay = 0;
			CloseQuestHeader("Headhunt");
			pchar.questTemp.Headhunter = "end_quest_full";                       

			sld = GetCharacter(NPC_GenerateCharacter("Tich", "Tich", "man", "man", 24, PIRATE, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 80, 80, 80, "blade51", "pistol11", "bullet", 28);
			sld.name = "Эдвард";
			sld.lastname = "Тич";
			sld.greeting = "Gr_Officer";
			sld.rank = 25;
			sld.HeroModel = "Tich,Tich_1,Tich_2,Tich_3,Tich_4,protocusto,Tich_6,Tich_8";
			sld.Dialog.Filename = "Enc_Officer_dialog.c";
			sld.quest.meeting = true;
			sld.HoldEquip = true;
			SetSelfSkill(sld, 80, 80, 80, 80, 80);
			SetShipSkill(sld, 90, 75, 70, 70, 85, 70, 70, 60, 50);
			SetSPECIAL(sld, 9, 9, 10, 10, 8, 10, 10);
			SetCharacterPerk(sld, "Energaiser"); // скрытый перк дает 1.5 к приросту энергии, дается ГГ и боссам уровней
	                                      SetCharacterPerk(sld, "Energaiser");
	                                      SetCharacterPerk(sld, "BasicDefense");
			SetCharacterPerk(sld, "AdvancedDefense");
			SetCharacterPerk(sld, "ByWorker");
			SetCharacterPerk(sld, "Ciras");
			SetCharacterPerk(sld, "Gunman");
			SetCharacterPerk(sld, "Sliding");
			SetCharacterPerk(sld, "CriticalHit");
	          SetCharacterPerk(sld, "HardHitter");
	          SetCharacterPerk(sld, "Sliding");
			SetCharacterPerk(sld, "ProfessionalDefense");
			SetCharacterPerk(sld, "IronWill");
			SetCharacterPerk(sld, "BladeDancer");
			SetCharacterPerk(sld, "GunProfessional");
			SetCharacterPerk(sld, "Sniper");
			SetCharacterPerk(sld, "FastReload");
			SetCharacterPerk(sld, "HullDamageUp");
			SetCharacterPerk(sld, "SailsDamageUp");
			SetCharacterPerk(sld, "CrewDamageUp");
			SetCharacterPerk(sld, "MusketsShoot");
			SetCharacterPerk(sld, "AdvancedBattleState");
			SetCharacterPerk(sld, "ShipDefenseProfessional");
			SetCharacterPerk(sld, "LongRangeShoot");
			SetCharacterPerk(sld, "SwordplayProfessional");
			SetCharacterPerk(sld, "ShipTurnRateUp");
			SetCharacterPerk(sld, "ShipSpeedUp");
	                                      SetCharacterPerk(sld, "Brander");
	                                      SetCharacterPerk(sld, "Troopers");
	                                      SetCharacterPerk(sld, "LongRangeGrappling");
	                                      SetCharacterPerk(sld, "Doctor1");
			SetCharacterPerk(sld, "Medic");
			sld.quest.OfficerPrice = sti(pchar.rank)*500;
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(sld.id);
			sld.OfficerWantToGo.DontGo = true; //не пытаться уйти
			sld.loyality = MAX_LOYALITY;
			sld.CanTakeMushket = true;
	                                      LAi_SetCharacterUseBullet(sld, "grapeshot");
                                                         TakeNItems(sld, "grapeshot", 34);
	                                      TakeNItems(sld, "bullet", 32);
	                                      TakeNItems(sld, "cartridge", 36);
	                                      TakeNItems(sld, "GunPowder", 33);

			QuestAboardCabinDialogNotBattle(); 
                                                          DialogExit();
		break;	
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
