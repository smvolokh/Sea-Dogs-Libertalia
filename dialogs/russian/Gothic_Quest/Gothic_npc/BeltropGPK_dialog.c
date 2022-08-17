// Дар Первый помощник
void ProcessDialogEvent()
{
	ref NPChar, sld, Ship;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Слушаю, капитан!";
			link.l1 = "Корабль не спали, курильщик.";
			link.l1.go = "Exit_1";
		break;

		case "Exit_1":
			dialog.text = "Хочешь затянуться!";
			link.l1 = "Да, ну тебя.";
			link.l1.go = "Exit";
		break;

		case "quest_other_life":
			dialog.text = "Корабль готов к отплытию, капитан.";
			link.l1 = "Спасибо, Дар, мы скоро будем.";
			link.l1.go = "quest_other_life_exit";
		break;

        case "quest_other_life_exit":
			AddDialogExitQuest("quest_other_life_flashback_port5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode="First time";
                        DialogExit();
		break;

/// ******************** Квест №1 ****************************

	                                                case "quest_Start_Game":
			dialog.text = "Капитан, приказывайте, что делать?";
			link.l1 = "Дар, всё что найдешь съедобное тащи на корабль и не забудь набрать пресной воды?";
			link.l1.go = "quest_Start_Game_1";
		                        break;

	                                                case "quest_Start_Game_1":
			dialog.text = "Есть капитан?";
			link.l1 = "А я пока осмотрю местную фауну?";
			link.l1.go = "quest_Start_Game_1_Ext";
		                        break;
				
			case "quest_Start_Game_1_Ext":	
			AddDialogExitQuestFunction("Start_Game_Terks_1");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

	                                                case "quest_Start_Game_Sailor_2":
			dialog.text = "Капитан?";
			link.l1 = "А ты что смотришь, за РАБОТУ?";
			link.l1.go = "quest_Start_Game_Sailor_3";
		                        break;
	                                                case "quest_Start_Game_Sailor_3":
			dialog.text = "Всё я понял, уже убегаю?";
			link.l1 = "";
			link.l1.go = "quest_Start_Game_Sailor_2_Ext";
		                        break;

			case "quest_Start_Game_Sailor_2_Ext":	
			AddDialogExitQuestFunction("Start_Game_Terks_2");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

/// ******************** Квест №2 ****************************

	                                                case "StartGameTerks7":
			dialog.text = "Капитан, кое что удалось найти, на несколько дней хватит, а кто это?";
			link.l1 = "Грозный пират, просится в найм. Что думаешь об этом.";
			link.l1.go = "StartGameTerks8";
		                        break;

	                                                case "StartGameTerks8":
			dialog.text = "А по мне хоть пират, хоть черт лысый, после зеленого шторма всё фиолетого, а вот лишнии руки нам не помешают.";
			link.l1 = "Значит ты не против его кандидатуры, где Джим Хопкинс.";
			link.l1.go = "StartGameTerks9";
		                        break;

	                                                case "StartGameTerks9":
			dialog.text = "На посту, несёт вахту?";
			link.l1 = "Хорошо, ты можешь идти, хотя постой что у тебя там в руке, показывай не стесняйся.";
			link.l1.go = "Gothic_Start";
		                        break;


		case "Gothic_Start":
			dialog.text = "Эту вещицу я здесь нашёл?";
			link.l1 = "Давай, показывай...";
			link.l1.go = "Gothic_Start_1";
		break;
		
		case "Gothic_Start_1":
			Log_Info("Вы получили странный предмет");
			dialog.text = "Вот...";
			link.l1 = "Так-так... Занятная вещица, соглас" + GetSexPhrase("ен","на") + ". Явно вывезена из индейских поселений. Хорошо, я забираю ее. Прими благодарность, теперь можешь идти.";
			link.l1.go = "Ext_1";		
		break;

		case "Ext_1":
			GiveItem2Character(pchar, ""); 
			AddDialogExitQuestFunction("Start_Game_Terks_7");				
			DialogExit();			
		break;

	                                                case "StartGameTerks10":	                                                
			dialog.text = "(Шопотом) Хочешь затянуться, ты это слышишь?";
			link.l1 = "Дар, да ты обкурился, почему ты не на корабле.";
			link.l1.go = "StartGameTerks11";
		                        break;

	                                                case "StartGameTerks11":
	                                                PlaySound("VOICE\Russian\gotica\DAR\DIA_DAR_PERM_03_01.wav");
			dialog.text = "(Шопотом) Иногда я позволяю всяким мстительным болотным наркоманам задать мне взбучку?";
			link.l1 = "Так ты бы больше курил?";
			link.l1.go = "StartGameTerks12";
		                        break;

	                                                case "StartGameTerks12":
			dialog.text = "(Шопотом) Тихо, тихо, капитан?";
			link.l1 = "Да, я тоже ,что -то слышу, пойду посмотрю, стой здесь.";
			link.l1.go = "StartGameTerks13Ext";
		                        break;

	                                                case "StartGameTerks13Ext":
	                                                PlaySound("VOICE\Russian\gotica\DAR\DIA_DAR_ORCRING_NECKEN_SCHLAGEN_03_01.wav");
			AddDialogExitQuestFunction("Vater_skel_Shore");				
			DialogExit();			
		                        break;

	                                                case "StartGameTerks14":
			dialog.text = "Как ни есть призраки моря?";
			link.l1 = "Вот черт?";
			link.l1.go = "StartGameTerks15";
		                        break;

	                                                case "StartGameTerks15":
			dialog.text = "Надо сваливать от сюда пока ветер без сучков?";
			link.l1 = "Да, пошли, только по тихому, без шума и пыли.";
			link.l1.go = "StartGameTerksExt";
		                        break;

	                                                case "StartGameTerksExt":
	                                                PlaySound("VOICE\Russian\gotica\DeviDjons\DeviDjons_1.wav");
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.QuestBeltropGPKTalk.win_condition.l1 = "location";
	                                                pchar.quest.QuestBeltropGPKTalk.win_condition.l1.location = "My_Cabin_Small";
			pchar.quest.QuestBeltropGPKTalk.function = "Quest_BeltropGPK_Talk";			
		                        break;

	                                                case "StartGameTerks16":
			dialog.text = "Капитан, то, что мы сегодня видили необходимо записать в судовой журнал.";
			link.l1 = "Спасибо Дар за напоминание, я это сделаю.";
			link.l1.go = "Ext2";
		                        break;

	                                                case "Ext2":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();			
			LAi_SetActorType(npchar);			
			LAi_ActorGoToLocation(npchar, "reload", "reload1", "My_Deck", "goto", "goto8", "OpenTheDoors", 1);
                                                                        DoQuestFunctionDelay("Start_Game_Terks_7_3", 3.0);
		                        break;

/// ******************** Квест №3 ****************************

		case "Caleuche_2":
			dialog.text = "Похоже капитан тот камень что с Теркса, им очень интерисуются ребята с гнилой посудины и они уже на подходе вся команда в замешательстве, капитана нет!";
			link.l1 = "Не дрефь старший помощник, пойдем надерем им задницу, заклятие снято мы их отправим на вечный покой?";
			link.l1.go = "Caleuche_3";
		break;

		case "Caleuche_3":
			dialog.text = "Ха, давно руки чешутся набить кому нибуть хлебало!";
			link.l1 = "Тогда в перёд?";
			link.l1.go = "Caleuche_Ext";
		break;

		case "Caleuche_4":
			dialog.text = "Капитан с юга надвигается шторм!";
			link.l1 = "Черт. Этого ещё не хватало, а он случайно не зелёного цвета?";
			link.l1.go = "Caleuche_5";

		break;

		case "Caleuche_5":
			dialog.text = "Грешно смеятся над убогими, капитан!";
			link.l1 = "Ладно, ладно я пошутил" + GetSexPhrase("","а") + "! В таком случае нам на север.";
			link.l1.go = "Caleuche_6";
		break;

		case "Caleuche_6":
			dialog.text = "Слушаюсь капитан!";
			link.l1 = "";
			link.l1.go = "Caleuche_FirstMate_Tuttuat_Ext";
			pchar.quest.CaleucheFirstMateTuttuat.win_condition.l1 = "location";
			pchar.quest.CaleucheFirstMateTuttuat.win_condition.l1.location = "Dominica";
			pchar.quest.CaleucheFirstMateTuttuat.function = "Caleuche_PrepareGhostship";
		break;
		
				
			case "Caleuche_Ext":
			DoQuestFunctionDelay("Caleuche_CreateGhostships", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

			case "Caleuche_FirstMate_Tuttuat_Ext":
			DoQuestFunctionDelay("Caleuche_FirstMateTuttuat", 1.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			break;

/// ******************** Квест №4  ****************************

		case "Start_GameMyCabin6":
			dialog.text = "" + PChar.name + ", скорее... Нужно торопиться!";
			link.l1 = "Дар? Что случилось? Где мы? Куда торопиться?";
			link.l1.go = "Start_GameMyCabin6_1";
		break;
		
		case "Start_GameMyCabin6_1":
			dialog.text = "Капитан, я позже всё объясню. Нужно спасать девушку!";
			link.l1 = "Девушку? что за девушка!";
			link.l1.go = "Start_GameMyCabin6_2";
		break;
		
		case "Start_GameMyCabin6_2":
			dialog.text = "Бежим, " + PChar.name + "! Скорее...";
			link.l1 = "";
			link.l1.go = "Start_GameMyCabin6_exit";
		break;

		case "Start_GameMyCabin6_exit":
			AddDialogExitQuest("Start_GameMyCabin5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Start_GameMyCabin6_Sound":
			dialog.text = "Слышите, капитан?! Звук сабель! Должно быть, это она! Мы должны помочь ей!";
			link.l1 = "";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Start_GameMyCabin6_Sound";
		break;		

		
/// ******************** Квест №5  ****************************	
	case "quest_CaesarVictorious":
			dialog.text = "Капитан, мы заметили небольшое судно на горизонте. На нём вывешены сигнальные флаги, означающие просьбу о помощи.";
			link.l1 = "Что это за лоханка?";
			link.l1.go = "quest_CaesarVictorious_1";
		break;
		case "quest_CaesarVictorious_1":
			dialog.text = "Похоже на небольшую бригантину, капитан. Внешне выглядит неповреждённой.";
			link.l1 = "Хорошо, давай посмотрим... подойдём поближе, затем спустите для меня шлюпку. Выполняйте.";
			link.l1.go = "quest_CaesarVictorious_1_1";
		break;		
		case "quest_CaesarVictorious_1_1":
			dialog.text = "Так точно, капитан! Эй, рулевой, подтягиваемся к той посудине...";
			link.l1 = "";
			link.l1.go = "quest_CaesarVictorious_1_1_Ext";
				NextDiag.TempNode = "quest_CaesarVictorious_2";
		break;				
			case "quest_CaesarVictorious_1_1_Ext":
				AddDialogExitQuest("quest_CaesarVictorious_3_CVdeck");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;	

	case "quest_CaesarVictorious_2":
			dialog.text = "Мы обыскали всё судно, капитан. Ни единого признака жизни.";
			link.l1 = "Но ведь кто-то вывесил эти флаги, верно?";
			link.l1.go = "quest_CaesarVictorious_2_1";
		break;	
		case "quest_CaesarVictorious_2_1":
			dialog.text = "Да, капитан. Более того, очень многие вещи здесь остались нетронутыми. Не похоже на то, чтобы это судно попадало в шторм или под обстрел. Я даже исключил бы абордаж, потому что нет ни единого явного следа кровавой драки. Возможно, конечно, это был очень изящный абордаж, но... маловероятно.";
			link.l1 = "Что ещё вы обнаружили?";
			link.l1.go = "quest_CaesarVictorious_2_2";
		break;		
		case "quest_CaesarVictorious_2_2":
			dialog.text = "В трюме есть запасы рома, имеются также медикаменты и небольшой оружейный склад. И самое главное – почти половина трюма забита грузом чёрного дерева.";
			link.l1 = "Вот как?.. А что в каюте капитана?";
			link.l1.go = "quest_CaesarVictorious_2_3";
		break;	
		case "quest_CaesarVictorious_2_3":
			dialog.text = "Мы только заглянули туда, капитан. Похоже, там остался судовой журнал, да и остальные вещи на своих местах. Я не стал изучать журнал, подумал, что вы захотите сделать это лично.";
			link.l1 = "Хорошо, сейчас взгляну. Продолжайте осмотр корабля.";
			link.l1.go = "quest_CaesarVictorious_2_3_Ext";
				NextDiag.TempNode = "quest_CaesarVictorious_3";
		break;		
			case "quest_CaesarVictorious_2_3_Ext":
				AddDialogExitQuest("quest_CaesarVictorious_3_CV_toCab");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;

	case "quest_CaesarVictorious_3":
			dialog.text = "Ну что, капитан?";
			link.l1 = "Да ничего. За исключением того, что я знаю, куда он должен был доставить этот груз – в Мариго.";
			link.l1.go = "quest_CaesarVictorious_3_1";
		break;	
		case "quest_CaesarVictorious_3_1":
			dialog.text = "Мариго? Так мы будем там через пару дней! Можно было бы закинуть, а, капитан? Стоит это дерево не так уж мало, а если заказчик и откажется брать груз из-за просрочки, можно будет продать его кому-нибудь ещё.";
			link.l1 = "Думаю, ты прав. Нам все равно по пути. Ничего не теряем.";
			link.l1.go = "quest_CaesarVictorious_3_2";
		break;	
		case "quest_CaesarVictorious_3_2":
			dialog.text = "Прикажете буксировать ‘Цезаря’, капитан?";
			link.l1 = "М-м-м... нет. Чёрт с ним. У этого корабля плохая судьба. Перегрузите весь товар на "+Pchar.Ship.Name+", затем затопите этот ‘призрак’.";
			link.l1.go = "quest_CaesarVictorious_3_3";
		break;	
		case "quest_CaesarVictorious_3_3":
			dialog.text = "Так точно, капитан.";
			link.l1 = "";
			link.l1.go = "quest_CaesarVictorious_3_3_Ext";
		break;
			case "quest_CaesarVictorious_3_3_Ext":
	                                                                       
				AddDialogExitQuest("quest_CaesarVictorious_4");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;		

/// ******************** Квест №6  ****************************	
	case "quest_UnarmAndDanger":
			dialog.text = "Капитан! Там огонь на земле!";
			link.l1 = "Да, я тоже это вижу... что это горит?";
			link.l1.go = "quest_UnarmAndDanger_1";
		break;
		case "quest_UnarmAndDanger_1":
			dialog.text = "Сейчас откроется вид получше... Матерь Божья!";
			link.l1 = "Что за дьявольщина?!..";
			link.l1.go = "quest_UnarmAndDanger_1_Ext";
		break;
			case "quest_UnarmAndDanger_1_Ext":
				AddDialogExitQuest("quest_UnarmAndDanger_9_SJ_Street");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;	

	case "quest_UnarmAndDanger_Mass7":
			dialog.text = "Боже, здесь была настоящая бойня!..";
			link.l1 = "Господи Боже... дон Алонсо... скорее же, в резиденцию! За мной!";
			link.l1.go = "quest_UnarmAndDanger_Mass7_Ext";
		break;	
			case "quest_UnarmAndDanger_Mass7_Ext":
				AddDialogExitQuest("quest_UnarmAndDanger_9_SJ_StreetResid");
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;			

/// ******************** Квест №8  ****************************	
	case "quest_HeadOfState":
			dialog.text = "А, капитан, пришли в себя! Выглядите бодро.";
			link.l1 = "Благодарю, "+NPChar.name+". Итак... где мы находимся?";
			link.l1.go = "quest_HeadOfState_1";
		break;
		case "quest_HeadOfState_1":
			dialog.text = "Недалеко от Пуэрто-Принсипе, капитан. Небольшой пиратский порт на восточном конце Кубы.";
			link.l1 = "Что ж... это интересно.";
			link.l1.go = "quest_HeadOfState_2";
		break;
		case "quest_HeadOfState_2":
			dialog.text = "Куда прикажете взять курс, капитан? Или же прикажете готовить шлюпку?";
			link.l1 = "Куда, куда... навстречу свободе, Найджел!";
			link.l1.go = "quest_HeadOfState_2Ext";
		break;
			case "quest_HeadOfState_2Ext":
				DoQuestCheckDelay("quest_HeadOfState_10_EpilogEnd", 1.0);
				NextDiag.CurrentNode = NextDiag.TempNode;
				DialogExit();
			break;			

		
		
/// ******************** Мистер и Миссис Смит ****************************	
		case "Smithy Nevis":
			dialog.text = "Кэп! Слава Богу, вы живы!  Мы с ребятами прочесали пол берега, но не нашли ваших следов. Мы рады так быстро воссоединиться с вами вновь, кэп, да и видеть вас в... эм... отличной форме, тоже очень рады! Пройдемте на борт, а, кэп?";
			link.l1 = "Боже правый! "+NPChar.name+"! Я тоже рад" + GetSexPhrase("","а") + " тебя видеть! Но что с нашим судном?";
			link.l1.go = "Smithy Nevis 1";
		break;

		case "Smithy Nevis 1":
			dialog.text = "Всё в порядке, кэп! Они нас отпустили. Те, на кого мы напали. Крутые ребята, скажу я вам, кэп. Многих наших порубили в капусту, эх... Ну они разрешили нам уйти, мы быстренько сняли крюки и отцепились! И они уплыли, кэп! А мы быстренько залатали пару дырочек и взяли курс на порт Сент-Кристофера. Потом отправили один отряд в джунгли, а другой - в город. И вот мы нашли вас, кэп!";
			link.l1 = "Что ж, отличная работа, "+NPChar.name+". Я горжусь своей командой. А теперь - вы ведь хотите поквитаться с ублюдками, оставившими нас в дураках? Тогда все на борт и полным ходом курс на Сан-Хуан!";
			link.l1.go = "Smithy Nevis 1 Exit";
		break;

		case "Smithy Nevis 1 Exit":
			NextDiag.CurrentNode="First time";
                        DialogExit();
		AddQuestRecord("Smithy", "13");
		sld=characterFromID("Quest_Smithy_Dvoretsky");
		Locations[FindLocation("SanJuan_town")].reload.l35.disable = false;
		pchar.quest.NSmithyQ = "Smithy_SanJuan_Dvoretsky";
			pchar.quest.Smithy_Funy.win_condition.l1 = "location";
			pchar.quest.Smithy_Funy.win_condition.l1.location = "SanJuan_houseSp5";
			pchar.quest.Smithy_Funy.win_condition = "Smithy Funy";
		DoQuestCheckDelay("Smithy 11 Off", 2.0);
		break;

		case "Smithy Sea Atack":
			dialog.text = "Капитан! На нас полным ходом идёт какой-то корвет под английскими флагами! Сигналит, что вы должны приказать немедленно остановить судно! Они собираются спустить шлюпку к нам!";
			link.l1 = "Проклятье, они повернули нас против ветра. Хитрые ублюдки. Уйти не получится... ну что же, отсигнальте им, что мы согласны и будем ждать их шлюпку. Выполняйте.";
			link.l1.go = "Smithy Sea Atack Exit";
		sld=characterFromID("Quest_Smithy_July");
/*         switch(GetCharacterShipClass(pchar))
        {
        case 7: Ship = "Ship_deck_Low"; break;
        case 6: Ship = "Ship_deck_Low"; break;
        case 5: Ship = "Ship_deck_Low"; break;
        case 4: Ship = "Ship_deck_Medium"; break;
        case 3: Ship = "Ship_deck_Medium"; break;
        case 2: Ship = "Ship_deck_Big"; break;
        case 1: Ship = "Ship_deck_Big"; break; 
        }
		ChangeCharacterAddressGroup(sld, Ship, "reload", "reload1");
*/
		ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
		DoQuestCheckDelay("Smithy 14", 1.0);
		break;

		case "Smithy Sea Atack Exit":
		LAi_SetPlayerType(pchar);
			NextDiag.CurrentNode="First time";
                        DialogExit();
		DoQuestCheckDelay("Smithy 15", 1.0);
		break;


		case "Smithy NxtMrnng":
			dialog.text = "Капитан, мы поймали попутный ветер. Курс на Кайман.";
			link.l1 = "Великолепно, "+NPChar.name+". Просто великолепно.";
			link.l1.go = "Smithy NxtMrnng 1";
		break;

		case "Smithy NxtMrnng 1":
			dialog.text = "Капитан, мне кажется или вы в очень хорошем настроении сегодня?";
			link.l1 = "Не угадал, "+NPChar.name+". Я в отличном настроении. А теперь за работу!";
			link.l1.go = "Smithy NxtMrnng Exit";
		break;

		case "Smithy NxtMrnng Exit":
		AddQuestRecord("Smithy", "15");
		ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		ChangeCharacterAddressGroup(characterFromID("Quest_Smithy_July"), "none", "", "");
// Надеюсь будет достаточно одной строки
//QuestToSeaLogin_PrepareLoc("Tortuga", "Quest_ships", "Quest_ship_3", "");
		QuestToSeaLogin_Launch();
			NextDiag.CurrentNode="First time";
                        DialogExit();
		DoQuestCheckDelay("Smithy 27_1", 1.0);
		break;
	
/// ******************** Вор и Пират ****************************	
	case "Blood_TandP":
			dialog.text = "Капитан! Проклятье, да это же наш капитан! Капитан, какими судьбами? Ха-ха-ха!";
			link.l1 = ""+NPChar.name+"! Чёртов ублюдок, "+NPChar.name+", это ты?";
			link.l1.go = "Blood_TandP 1";
		break;
		case "Blood_TandP 1":
			dialog.text = "Это я! Ха-ха-ха! Мы в очередной раз нашли вас, когда думали, что потеряли! Ха-ха-ха!";
			link.l1 = "Да, вот это удача! Что вы делаете на Ямайке?";
			link.l1.go = "Blood_TandP 2";
		break;
		case "Blood_TandP 2":
			dialog.text = "Ну а что, это один из самых больших портов на архипелаге, вот мы и решили вас тут ждать! И не прогадали! Корабль, кстати, уже в полном порядке, кэп, ждёт вас!";
			link.l1 = "Ну, и молодцы же вы, парни! Это нужно отметить! Всем по чарке за мой счёт!";
			link.l1.go = "Blood_TandP 2 Ext";
		break;
		case "Blood_TandP 2 Ext":
			NextDiag.CurrentNode="First time";
            DialogExit();
		SetCharacterShipLocation(Pchar, "PortRoyal_town");
		AddQuestRecord("Blood_ThiefAndPirate","19");
			ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		AddDialogExitQuest("Blood_TandP 108 PRTavern");
		break;
		
		
/// ******************** Мини-квесты ****************************	
// Винный погребок
	case "MiniQuest_VineUndr":
			dialog.text = "С вами все в порядке, капитан?";
			link.l1 = "Что произошло?";
			link.l1.go = "MiniQuest_VineUndr 1";
		break;
		case "MiniQuest_VineUndr 1":
			dialog.text = "Вчера вы перебрали спиртного и отправились по городу в поисках развлечений. Хорошо еще то, что наш боцман был неподалеку. А то бы вы вчера натворили дел.";
			link.l1 = "Смутно помню вчерашний день. Ладно, пора заняться делами.";
			link.l1.go = "MiniQuest_VineUndr 1 Exit";
		break;	
		case "MiniQuest_VineUndr 1 Exit":
			NextDiag.CurrentNode="First time";
            DialogExit();
		QuestToSeaLogin_PrepareLoc("Jamaica", "reload", "reload1", 0);	
		QuestToSeaLogin_Launch();
			ChangeCharacterAddressGroup(characterFromID("QuestPcharFirstMate"), "none", "", "");
		//AddDialogExitQuest("MiniQuest_VineUndr 4");
		break;

/// ******************** Мини-квесты ****************************



        case "quest_other_life_exit":
			AddDialogExitQuest("quest_other_life_flashback_port5");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "quest_SantoDomingo_night":
			dialog.text = "Питер, скорее... Нужно торопиться!";
			link.l1 = "Джефри? Что случилось? Где мы? Куда торопиться?";
			link.l1.go = "quest_SantoDomingo_night1";
		break;
		
		case "quest_SantoDomingo_night1":
			dialog.text = "Капитан, я позже всё объясню. Нужно спасать Беатрис!";
			link.l1 = "Беатрис? Где она? БЕАТРИС!";
			link.l1.go = "quest_SantoDomingo_night2";
		break;
		
		case "quest_SantoDomingo_night2":
			dialog.text = "Бежим, Питер! Скорее...";
			link.l1 = "";
			link.l1.go = "quest_SantoDomingo_night2_exit";
		break;

		case "quest_SantoDomingo_night2_exit":
			AddDialogExitQuest("quest_SantoDomingo_SanJuan5_tavern_night3");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "quest_SantoDomingo_night_Sound":
			dialog.text = "Слышите, капитан?! Звук сабель! Должно быть, это Беатрис! Мы должны найти её!";
			link.l1 = "";
			link.l1.go = "Exit";
				NextDiag.TempNode = "quest_SantoDomingo_night_Sound";
		break;		
		



	}
}
