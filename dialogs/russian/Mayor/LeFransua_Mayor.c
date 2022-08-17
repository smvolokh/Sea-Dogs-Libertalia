// Бартоломью Роджерс, глава буканьеров и авторитетный пират, пиратская линейка
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string sLoc;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	float locx, locy, locz;
	string sTemp;
	int iTemp;
    
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
            switch (npchar.angry.kind) //сюда расписываем реакцию ангри. В npchar.angry.name пробелы удалены!!!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================
	switch(Dialog.CurrentNode)
	{
		case "First time":
            NextDiag.TempNode = "First time";
            if (CheckAttribute(npchar, "Sp5LaVegaAttackDone"))
            {

            	if (NPChar.quest.meeting == "0")
				{
					dialog.Text = TimeGreeting() + "! Я "+ GetFullName(NPChar) + ", новый наместник в этой дыре. К сожалению, призвать к порядку местный сброд довольно трудно, но угрозы от них для Испанских колоний больше не будет.";
					Link.l1 = "Рад"+ GetSexPhrase("","а") +" знакомству. Я капитан " + GetFullName(Pchar) + ". Мне уже пора.";
					Link.l1.go = "exit";
					NPChar.quest.meeting = "1";
				}
				else
				{
					dialog.Text = TimeGreeting() + ". Я занят, очень много дел, нужно контролировать настроение местных жителей, дабы пресечь угрозу колониям Испании.";
					Link.l1 = "Не буду мешать.";
					Link.l1.go = "exit";
				}
            }
            else
            {
				dialog.text = NPCStringReactionRepeat("У тебя ко мне дело? Нет? Тогда "+ GetSexPhrase("выметайся отсюда!","попрошу не отвлекать меня.") +"",
	                         "Я, кажется, ясно выразился...", "Хотя я выразился и ясно, но ты продолжаешь отвлекать меня!",
	                         "Хм, да ты не в меру "+ GetSexPhrase("хамовит, мон шер","нагла, деваха") +"...", "repeat", 30, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Уже ухожу.",
	                                               "Да, " + npchar.name + ", совершенно ясно.",
	                                               "Извини, " + npchar.name + "...",
	                                               "Ай, ай...", npchar, Dialog.CurrentNode);
				link.l1.go = "exit";
			}
					if (npchar.city == sti(pchar.HeroParam.Location))
					{
						if(!CheckAttribute(PChar, "questTemp.pirateStartQuest"))
						{
							link.l2 = "Может какая работенка для меня найдется?";
							link.l2.go = "pirateStartQuest";
						}
						else
						{
							if(pchar.questTemp.pirateStartQuest == "3" && !CheckAttribute(PChar, "questTemp.pirateStartQuest.many"))
							{
								link.l2 = "Я выш"+ GetSexPhrase("ел","ла") +" на след, но мне нужны деньги - 30 000 песо, чтобы выманить крысу из норы.";
								link.l2.go = "pirateStartQuest_many";	
							}
							if(pchar.questTemp.pirateStartQuest == "3" && GetCharacterItem(pchar, "letter_open") > 0)
							{
								link.l2 = "Посмотри, что за письмо я наш"+ GetSexPhrase("ел","ла") +" на трупе одного из контрабандистов.";
								link.l2.go = "pirateStartQuest_info_1";	
							}
							if(pchar.questTemp.pirateStartQuest == "5")
							{
								link.l2 = "Дело сделано. Норман Виго вместе со своей лоханкой отправился к морскому дьяволу.";
								link.l2.go = "pirateStartQuest_final";	
							}
						}
					}
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		//zagolski. начальный квест за пирата ===================================
		case "pirateStartQuest":
			dialog.text = "Кто ты и от куда ты взялся?";
			link.l1 = "";
			link.l1.go = "pirateStartQuest_0";
		break;

		case "pirateStartQuest_0":
	                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_SECRETLIBRARY_6.wav");
			dialog.text = "";
			link.l1 = "Я был заключенным в горнодобывающей колонии!";
			link.l1.go = "pirateStartQuest_01";
		break;

		case "pirateStartQuest_01":
	                                PlaySound("VOICE\Russian\gotica\GG\DIEBESWERK_1.wav");
			dialog.text = "Хм... понятно, работенка - говоришь? А это даже очень хорошо, что ты ко мне обратил"+ GetSexPhrase("ся","ась") +". Мне как раз нужен человек со стороны. Необходимо кое-что разузнать в соседнем поселении, а моих ребят там знают, как облупленных. Много денег не обещаю, но кое-что перепадет.";
			link.l1 = "Вот и славно. А что за дело?";
			link.l1.go = "pirateStartQuest_1";
			link.l2 = "Извини, за копейки я рисковать не буду. Прощай...";
			link.l2.go = "exit";
			pchar.questTemp.pirateStartQuest = "0";
		break;

		case "pirateStartQuest_1":
			dialog.text = "А дело в следующем - с месяц назад сговорился я с капитаном шхуны 'Грифон' о доставке 200 рабов, чтобы продать их одному плантатору из соседнего поселения. Уже и сроки поджимать стали, и заказчик нервничать, и вот вчера мне сообщают, что эту шхуну видели в акватории острова. Но!.. капитан у меня не появился. А сегодня плантатор потребовал вернуть задаток и сказал, что рабов ему предложили в другом месте - хоть и дороже, но всю партию и сразу.";
			link.l1 = "И что? Я долж"+ GetSexPhrase("ен","на") +" в считанные дни раздобыть 200 рабов, чтоб ты не потерял задаток? И все это за копейки?";
			link.l1.go = "pirateStartQuest_2";
		break;
		case "pirateStartQuest_2":
			dialog.text = "Нет, конечно. Разве я похож на идиота? Задаток я не верну в любом случае. Но мне нужны доказательства, что рабы, которых ему подсовывают - это и есть моя партия. А ты просто найдешь тех, кто предложил ему новую сделку, и получишь свои 10 000 песо. Остальное моя забота. Ну что, берешься?";
			link.l1 = "Берусь! А кто это может быть? Есть какие-то соображения?";
			link.l1.go = "pirateStartQuest_3";
			link.l2 = "Нет. Искать непонятно кого, непонятно где и всего за 10 000 - извини, не возьмусь.";
			link.l2.go = "exit";
		break;
		case "pirateStartQuest_3":
			dialog.text = "Если бы у меня был хоть намек, я обошелся бы и без твоих услуг. Они бы уже к ночи ловили кальмаров на живца. Но меня больше интересует другое - как они узнали о грузе 'Грифон' и о моем заказчике? Уж очень все быстро у них срослось. Смекаешь?";
			link.l1 = "";
			link.l1.go = "pirateStartQuest_4";

			pchar.questTemp.pirateStartQuest = "1";
			pchar.questTemp.pirateStartQuest.City = npchar.city;
			pchar.questTemp.pirateStartQuest.Areal = GetArealByCityName(pchar.questTemp.pirateStartQuest.City);
			pchar.questTemp.pirateStartQuest.Name = GetFullName(npchar);

			AddQuestRecord("pSQ", "1");
			AddQuestUserData("pSQ", "sCity", XI_ConvertString("Colony" + pchar.questTemp.pirateStartQuest.City + "Gen"));
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);
		break;

		case "pirateStartQuest_4":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_2.wav");
			dialog.text = "";
			link.l1 = "И... Явно кто-то приторговывает сведениями.";
			link.l1.go = "pirateStartQuest_04";
		break;
		case "pirateStartQuest_04":
			dialog.text = "Вот! Вот его и ищу. Поэтому тихо прирезать конкурентов и вернуть рабов - в этом деле не главное. Мне нужен информатор, а вернее - его голова на вертеле. Теперь ты понимаешь, почему никто из моих об этом задании знать не должен? Пока я не выясню, кто продает информацию - подозревать буду каждого. А мне этого очень не хочется...";
			link.l1 = "Понятно... Значит, будем действовать тихо и не поднимать волну. Отправляюсь на поиски.";
			link.l1.go = "pirateStartQuest_05";
		break;

		case "pirateStartQuest_05":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
			dialog.text = "";
			link.l1 = "Всё будет в порядке!";
			link.l1.go = "exit";
		break;

		case "pirateStartQuest_many":
			dialog.text = "Тридцать тысяч, говоришь? Это большая сумма... Могу дать только 5000 песо, больше у меня сейчас нет. Но если вздумаешь сбежать с ними - найду и повешу на ближайшем заборе! Со мной такие шутки не пройдут.";
			link.l1 = "Давай пять тысяч...";
			link.l1.go = "pirateStartQuest_many_1";
		break;
		case "pirateStartQuest_many_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
			dialog.text = "Вот, держи. Жду результаты поиска.";
			link.l1 = "Все будет в порядке.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 5000);
			pchar.questTemp.pirateStartQuest.many = "";
		break;

		//------------------------------------
		case "pirateStartQuest_info_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_22.wav");
			dialog.text = "Ха! Отличная новость! Я был уверен, что ты с этим справишься. Ко мне попала весьма любопытная информация.";
			link.l1 = "Я работу свою выполнил"+ GetSexPhrase("","а") +". Хочу получить свои десять тысяч.";
			link.l1.go = "pirateStartQuest_info_2";
			TakeItemFromCharacter(pchar, "letter_open");
		break;
		case "pirateStartQuest_info_2":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			dialog.text = "Конечно, вот обещанная награда. Но ты не спеши, я хочу поручить тебе еще одно дело\nПфайфер - это человек из команды Нормана Виго, который ходит на курьерском люггере 'Септима'. Я уверен, что Норман Виго и есть информатор, хотя он и из наших. Его недавно видели в акватории острова, твоя работа - отправить крысу к морскому дьяволу. В первый раз ты меня не подвел"+ GetSexPhrase("","а") +", поэтому и сейчас хочу поручить это дело тебе. Заплачу 15 000 песо. Соглас"+ GetSexPhrase("ен","на") +"?";
			link.l1 = "Берусь! Считай, что предатель Норман Виго уже покойник.";
			link.l1.go = "pirateStartQuest_info_3";
			link.l2 = "Знаешь что, неохота мне в это ввязываться... Да и некогда. Извини, но я пас.";
			link.l2.go = "pirateStartQuest_info_noex";
			AddMoneyToCharacter(pchar, 10000);
			pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
		break;
		case "pirateStartQuest_info_noex":
 	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_54.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
		break;
		case "pirateStartQuest_info_3":
	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_4.wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			pchar.questTemp.pirateStartQuest = "4";

			AddQuestRecord("pSQ", "7");
			AddQuestUserData("pSQ", "sName", pchar.questTemp.pirateStartQuest.Name);

			pchar.quest.zpq_seaBattle.win_condition.l1 = "location";
			pchar.quest.zpq_seaBattle.win_condition.l1.location = pchar.questTemp.pirateStartQuest.Areal;
			pchar.quest.zpq_seaBattle.function = "pirateStartQuest_seaBattle";
		break;

		case "pirateStartQuest_final":
 	                    PlaySound("VOICE\Russian\GOTHIC\GG\GG_20.wav");
			dialog.text = "";
			link.l1 = "Мы сделали всё, что можно сделать!";
			link.l1.go = "pirateStartQuest_final_1";
		break;

		case "pirateStartQuest_final_1":
	                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
			dialog.text = "Знаем-знаем. Мои люди наблюдали бой и уже доложили мне, как ты здорово управил"+ GetSexPhrase("ся","ась") +". Ну что ж, дело свое ты исправно сделал"+ GetSexPhrase("","а") +", вот обещанная награда в 15 000 песо. И спасибо тебе, здорово ты мне помог"+ GetSexPhrase("","ла") +". Да и ещё, если ты нуждаешься в работе спроси Тиракса в Ла Веге, я пошлю к нему рекомендации о твоих заслугах.";
			link.l1 = "Все в порядке, спасибо, рад"+ GetSexPhrase(" был","а была") +" помочь! Что ж при случае я загляну к нему. До встречи Барон!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 15000);
			pchar.questTemp.pirateStartQuest = "0";
			CloseQuestHeader("pSQ");
			group_DeleteGroup("pirateStartQuest_Smuggler_group");
		pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)-5;
			//pchar.questTemp.Mtraxx = "to_lavega";
			//pchar.questTemp.Saga = "pirate_line";
		break;

		//*********************линейка Ли *********************

        case "GothicLee6_talk":
            dialog.text = "Кто ты так"+ GetSexPhrase("ой","ая") +" и что тебе нужно?";
            link.l1 = "Я капитан " + GetFullName(pchar) + ". А нужен мне пустяк. К тебе наверняка прибудут гонцы от Тиракса...";
            link.l1.go = "Gothic_6_1";
        break;
        case "Gothic_6_1":
            dialog.text = "Что за гонцы? Говори прямо, не надо мне тут намекать!";
            link.l1 = "Хорошо, Бартоломью. Вопрос по сути следующий - Тиракс готовит нападение на голландцев и хочет подключить к этому делу Береговое братство.";
            link.l1.go = "Gothic_6_2";
        break;
        case "Gothic_6_2":
            dialog.text = "Ну и что?";
            link.l1 = "Мне важно, чтобы ты не участвовал в этой авантюре.";
            link.l1.go = "Gothic_6_3";
        break;
        case "Gothic_6_3":
            dialog.text = "Хех, мне не нравится идея нападать на голландцев и я, пожалуй, соглашусь на твое предложение. Но тебе придется кое-что сделать для меня.";
            link.l1 = "Что именно?";
            link.l1.go = "Gothic_6_4";
        break;
        case "Gothic_6_4":
            dialog.text = "Не знаю, знаком"+ GetSexPhrase("","а") +" ли ты с этой историей... Ну, в общем, дело в следующем: некий весельчак, капитан Йохан, устроил прогулку по морю, не разбирая, где свои, где чужие, пустил по миру пару английских купцов, а когда запахло жареным, свалил все на меня. Я тогда тоже был в походе, а у Тиракса давно руки чесались меня приструнить. В общем, в Порт Рояль мне доступа сейчас нет.";
            link.l1 = "И что ты предлагаешь?";
            link.l1.go = "Gothic_6_5";
        break;
        case "Gothic_6_5":
            dialog.text = "Понимаешь, мне все одно выгодна вся эта заварушка. Если Тиракс попросит меня об одолжении, то, почитай, обвинения с меня сняты. Ну, а если ты сумеешь раздобыть документы, доказывающие, что не я устроил тот беспредел, в котором меня обвиняют - тоже хорошо. Второй вариант мне предпочтительней, так как с голландцами я портить отношения не хочу.";
            link.l1 = "Что ж, услуга за услугу. Постараюсь добыть документ, оправдывающий тебя. Что порекомендуешь сделать?";
            link.l1.go = "Gothic_6_6";
        break;
        case "Gothic_6_6":
            dialog.text = "Порыться в документах капитана Йохана, мне нужен его судовой журнал.";
            link.l1 = "Ну что же, я все понял"+ GetSexPhrase("","а") +". Буду действовать, а ты пока ничего не предпринимай до моего возвращения.";
            link.l1.go = "Gothic_6_7";
        break;
        case "Gothic_6_7":
            dialog.text = "Поторопись...";
            link.l1 = "Всенепременно!";
            link.l1.go = "exit";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "6");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("ен","на"));
			NextDiag.TempNode = "Gothic_6_Result";
			// ==> открываем дверь таверны Порт Рояля - там кэп Йохан.
			LocatorReloadEnterDisable("PortRoyal_tavern", "reload2_back", false);
			LAi_LocationFightDisable(&Locations[FindLocation("PortRoyal_tavern_upstairs")], false);
            ref sld = GetCharacter(NPC_GenerateCharacter("CaptainGay", "mercen_12", "man", "man", 40, PIRATE, -1, true, "quest"));
			FantomMakeCoolFighter(sld, 40, 100, 90, "newblade12", "pistol4", "bullet", 150);
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_2.c";
        	sld.name 	= "Капитан";
        	sld.lastname 	= "Йохан";
			sld.items.ShipsJournal = 1;
			sld.money = 65720;
			sld.items.potion4 = 4;
			sld.items.potionrum = 1;
			sld.items.potionwine = 2;
			sld.items.sculMa2 = 1;
			sld.items.jewelry17 = 30;
			sld.items.jewelry18 = 15;
			sld.SaveItemsForDead = true; // сохранять на трупе вещи
			sld.DontClearDead = true; // не убирать труп через 200с
			LAi_NoRebirthEnable(sld);
			LAi_SetLoginTime(sld, 0.0, 24.0);
			LAi_SetStayType(sld); 
			ChangeCharacterAddressGroup(sld, "PortRoyal_tavern_upstairs", "goto", "goto1");
		break;
        case "Gothic_6_Result":
            dialog.text = "Ну, как успехи, капитан? Раздобыл"+ GetSexPhrase("","а") +" судовой журнал этого мерзавца Йохана?";
			if (CheckCharacterItem(pchar, "ShipsJournal"))
			{
				link.l1 = "Новостей две, и обе хорошие, что бывает нечасто. Йохан отправился к праотцам. А его журнал - держи, вот он.";
				link.l1.go = "Gothic_6_8";
			}
			else
			{
				link.l1 = "Нет еще... Но я работаю над этим, все будет...";
				link.l1.go = "exit";
			}
        break;
        case "Gothic_6_8":
            dialog.text = "Так-так... Да, я предполагал, что этот павлин во всех красках распишет свои подвиги. Ну что ж, эту тетрадку я переправлю с надежными людьми Тираксу, и уверен, больше он меня шантажировать не будет. А ты можешь успокоить голландцев - их я пальцем не трону!";
            link.l1 = "Отлично, Бартоломью. Ну, а теперь мне пора, прощай...";
            link.l1.go = "exit";
			pchar.questTemp.Count = makeint(pchar.questTemp.Count)+1;
			NextDiag.TempNode = "First time";
			AddQuestRecord("GothicLee_6_ThreeCorsairs", "7");
			AddQuestUserData("GothicLee_6_ThreeCorsairs", "sSex", GetSexPhrase("","а"));
            TakeItemFromCharacter(pchar, "ShipsJournal");
        break;

			//поиски супер-мушкета
		case "Mushkett":
			dialog.text = "" + GetFullName(pchar) + ", какая встреча? Зачем пожаловал к старине Бартоломью, наслышан - наслышан о твоих делах!!!";
			link.l1 = "Привет, Роджерс, тебе ни о чем не говорит слово 'стрела'? Может быть, здесь бывает пират по кличке 'Стрела', или судно пиратское с таким названием заходило к тебе в порт?";
			link.l1.go = "Mushket_01";
		break;

		case "Mushket_01":
			dialog.text = "А-а, и тебе этот придурок на хвост наступил. Это судно Альберта Зиверта - очень хороший бриг, пожалуй, лучший на архипелаге. Немудрено, что его сам Торус достать не смог. А зачем он тебе понадобился?";
			link.l1 = "Да есть одно дело... Мне бы найти этого Зиверта.";
			link.l1.go = "Mushket_1";
			DeleteAttribute(pchar, "questTemp.mushkett2x2");
		break;

		case "Mushket_1":
			dialog.text = "А как же ты его найдешь? Он сам по себе, ни на кого не работает, никому долю не платит, в пиратские порты сам не заходит - чтоб делиться не заставили, а в порты колоний его не пускают. Нет, его там, конечно, ждут, чтоб с петлей сосватать, но рисковать не будет - не такой он человек.";
			link.l1 = "Да уж... Может, посоветуешь что?";
			link.l1.go = "Mushket_2";
		break;
		case "Mushket_2":
			dialog.text = "Есть один человек, который с этим Зивертом в паре ходил. Но что-то у них не склеилось - то ли Зиверт его за бортом оставил, то ли наоборот. Оба они - одного поля ягоды, иначе, наверное, и не сошлись бы.\nЭтот малый теперь таверну в Порто Белло держит, Роландо Пицарро зовут, или просто - Лис. Он может знать места стоянок. Ну и, кроме того - ищи этот бриг в море, ты его ни с кем не спутаешь. Только будь осторож"+ GetSexPhrase("ен","на") +" - он действительно псих...";
			link.l1 = "Ясно. Ну что ж, спасибо тебе, Бартоломью.";
			link.l1.go = "exit";
			pchar.questTemp.mushkett2x2_stid = true;
			SaveCurrentQuestDateParam("questTemp.mushkett2x2_stid");
			AddQuestRecord("SeekDoubleMushket", "2_2");			
		break;



		//********************* Месть корсара *********************


 		case "Lets_go_bussines":
			dialog.text = "Ага, вот и ты снова. Каким ветром тебя занесло в Ле Француа?";
			link.l1 = "Я участвую в деле с Морганом. Не откажите ли вы в любезности присоединиться к штурму Куманы?";
			link.l1.go = "Gothic_RevengeCorsair_5";
  		break;

 		case "Gothic_RevengeCorsair_5":
            if (GetCompanionQuantity(pchar) < 8) 
            {
    			dialog.text = "Конечно не откажусь. Я готов выступать немедленно.";
    			link.l1 = "Тогда вперед!";
    			link.l1.go = "Gothic_RevengeCorsair_6";
            }
            else
            {
    			dialog.text = "Я видел на рейде восемь кораблей. Если еще и я пойду с вами, то при штурме мы будем только мешать друг другу. Так что без меня на этот раз.";
    			link.l1 = "Ну что ж, как знаешь, будь здоров.";
    			link.l1.go = "exit";
                NextDiag.TempNode = "First time";
            }
            
  		break;

 		case "Gothic_RevengeCorsair_6":
	        AddQuestRecord("RevengeCorsair", "14");
                LAi_SetActorType(NPChar);
                LAi_ActorSetStayMode(NPChar);
                ChangeCharacterAddressGroup(NPChar, "LeFransua_townhall", "goto", "goto6");
                CharacterIntoCompanionAndGoOut(pchar, npchar, "reload", "reload1", 6, false);
                Fantom_SetBalls(npchar, "pirate");
                npchar.CompanionEnemyEnable = false;  // нет отпора при обстреле
                pchar.questTemp.CompanionQuantity = makeint(sti(pchar.questTemp.CompanionQuantity) + 1);
                pchar.questTemp.CompanionQuantity.LeFransua_Mayor = true;
                NextDiag.TempNode = "Have_hot_bussines";
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;

		//Бартоломью Роджерс
		npchar = characterFromId("LeFransua_Mayor");
		FantomMakeCoolSailor(npchar, SHIP_LSHIP_SPA, "Чёрная Каракатица", CANNON_TYPE_CULVERINE_LBS36, 90, 90, 90);
	SetShipSailsFromFile(npchar, "ships/parus_sail_whole_white_pirate_6.tga");
 npchar.FaceId = 952;
SetSelfSkill(npchar, 85, 95, 95, 80, 95);
SetShipSkill(npchar, 95, 95, 95, 95, 100, 95, 100, 95, 95);
npchar.rank = 30+MOD_SKILL_ENEMY_RATE;
SetCrewQuantityFull(npchar); 
npchar.ship.Crew.Morale = 80;
npchar.Ship.Crew.Exp.Sailors = 100;
npchar.Ship.Crew.Exp.Cannoners = 100;
npchar.Ship.Crew.Exp.Soldiers = 100;
SetCharacterGoods(npchar, GOOD_BALLS, 3000);
SetCharacterGoods(npchar, GOOD_GRAPES, 2500);
SetCharacterGoods(npchar, GOOD_KNIPPELS, 2000);
SetCharacterGoods(npchar, GOOD_BOMBS, 1500);
SetCharacterGoods(npchar, GOOD_POWDER, 10000);
SetCharacterGoods(npchar, GOOD_WEAPON, 1000);
SetCharacterGoods(npchar, GOOD_FOOD, 2500);
SetCharacterGoods(npchar, GOOD_MEDICAMENT, 1000);
SetCharacterGoods(npchar, GOOD_RUM, 350);
SetCharacterGoods(npchar, GOOD_PLANKS, 100);
SetCharacterGoods(npchar, GOOD_SAILCLOTH, 100);
UpgradeShipParameter(npchar, "Capacity");
npchar.CompanionEnemyEnable = false;  // нет отпора при обстреле
		SetCharacterRemovable(npchar, false);
		npchar.Ship.Cargo.Goods.Food = 1000;
		LAi_SetImmortal(npchar, false);
                LAi_NoRebirthDisable(npchar);
		LAi_RebirthOldName(npchar);
		SetCompanionIndex(pchar, -1, sti(npchar.index));

  		break;


	 	case "Have_hot_bussines":   // Если геймеру вдруг захочется еще пообщаться, не знаю, сможет ли. Но на всякий случай.
			dialog.text = "Мы должны поторопиться, время не ждет.";
			link.l1 = "Мы все успеем.";
			link.l1.go = "exit";
            NextDiag.TempNode = "Have_hot_bussines";
  		break;

	 	case "Gold_found_in_fort":    // Нода разговора в форте Куманы
            if (CheckAttribute(pchar, "questTemp.CompanionQuantity.LeFransua_Mayor") && !IsCompanion(characterFromID("LeFransua_Mayor")))
    		{
            	dialog.text = "Проклятье, мой галеон пошел ко дну! Я потерял корабль и добрую четверть команды. Жаль хороших парней..."+
                              " Эх, все одно, для оставшихся в живых жизнь продолжается, а наградой нам будет золото Куманы. Мы нашли золото в этой комнате под досками, которыми устлан пол. Ты - настоящий корсар"+ GetSexPhrase("",", хоть и девушка") +".";
            }
            else
            {
            	dialog.text = "Долго искать не пришлось, черт возьми! Мы нашли золото в этой комнате под досками, которыми устлан пол. Ты - настоящий корсар"+ GetSexPhrase("",", хоть и девушка") +".";
            }
			link.l1 = "Спасибо. Рад"+ GetSexPhrase("","а") +" слышать это от тебя.";
			link.l1.go = "Gothic_RevengeCorsair_7";
        break;

	 	case "Gothic_RevengeCorsair_7":
			dialog.text = "Я ухожу к себе на Мартинику. Ты всегда сможешь найти меня там.";
			link.l1 = "Всего хорошего, Бартоломью. Еще встретимся!";
			link.l1.go = "Gothic_RevengeCorsair_8";
        break;
        
	 	case "Gothic_RevengeCorsair_8":
            LAi_SetActorType(npchar);
            LAi_ActorRunToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 15.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
        break;
				
 		
// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("Пошел вон","Убирайся") +" отсюда!", "Вон из моего дома!");
			link.l1 = "Ой-ой-ой...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Бартоломью через 30 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Тебе не стоит доставать меня, запомни это.";
        			link.l1 = "Я понял"+ GetSexPhrase("","а") +", Бартоломью, больше не буду.";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("LeFransua_town","reload","reload3_back");
		break;
		// <<<<<<<<<<<<============= блок нод angry =============================
	}
}

void SetMushketCapitainInWorld()
{

}


