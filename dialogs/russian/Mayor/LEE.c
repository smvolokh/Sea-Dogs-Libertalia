// Генерал Ли в Логове Контрабандистов Гваделупы
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

// ------------------------------------------блок angry-----------------------------------------------
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
                    if (npchar.angry.name == "I_know_you_good") Dialog.CurrentNode = "AngryRepeat_2";
                break;
            }
        }
    } //<-- блок angry
 
	switch(Dialog.CurrentNode)
	{
		case "First time":
            dialog.text = NPCStringReactionRepeat(""+ GetSexPhrase("Дружище у тебя дело ко мне? Нет? Не отвлекай я занят!","Ха, " + pchar.name + "! У тебя дело ко мне? Нет? Тогда не отвлекай меня.") +"",
                         "Извени дружище, я занят.", "Дружище я выразился ясно, но ты продолжаешь отвлекать меня!",
                         "Та-а-ак, это уже похоже на грубость, хоть мы и друзья, меня это утомило.", "repeat", 3, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Уже ухожу.",
                                               "Конечно, Генерал Ли...",
                                               "Извини, Генерал Ли...",
                                               "Ой...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			
			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("У тебя крыша поехала? Вообразил себя мясником? Все пираты злы на тебя, приятель, так что лучше тебе убраться отсюда побыстрее.", "Ты, приятель, похоже, из ума выжил. Руки чесались сильно? Теперь не обессудь - здесь тебе делать нечего. Вали отсюда побыстрее!");
				link.l1 = RandPhraseSimple("Послушай, я хочу исправить ситуацию...", "Помоги мне решить эту проблему...");
				link.l1.go = "SantLous_town";
				break;
			}

            // квест Аскольда. Пасхалка на получение индейских предметов.
            if (pchar.questTemp.Ascold == "SeekThreeObject" && !CheckAttribute(pchar, "questTemp.Ascold.Lee"))
            {
    			link.l2 = "Генерал Ли, у меня к тебе дело. Послушай, не встречались ли тебе в призовых набегах различные индейские предметы?";
    			link.l2.go = "Step_Lee_1";
            }
            if (pchar.questTemp.Ascold == "SeekThreeObject" && CheckAttribute(pchar, "questTemp.Ascold.Lee"))
            {
    			link.l2 = "Генерал Ли, может, ты передумаешь насчет цены тех индейских предметов, о которых я тебе говорил"+ GetSexPhrase("","а") +"?";
    			link.l2.go = "Step_Lee_7";
            }
            if (pchar.questTemp.Azzy == "DestrContract" || pchar.questTemp.Azzy == "2DestrContract")
            {
                if (!CheckAttribute(pchar, "questTemp.Azzy.Lee"))
                {
        			link.l2 = "Генерал Ли, послушай, хочу у тебя попросить помощи. Мне позарез нужны индейские побрякушки. Речь идет о трех хрустальных черепах тольтеков и странной вещи, похожей на погремушку.";
        			link.l2.go = "Step_Lee_9";
        		}
            }
            // квест Аскольда. Пасхалка на получение индейских предметов.
			
			//--> Сага
			if(CheckAttribute(pchar, "questTemp.Saga.SharkHunt") && !CheckAttribute(npchar, "quest.sharkbegin"))
			{
				link.l1 = "Я пытаюсь разыскать Акулу Додсона. Говорят, ты последний, кто видел его. Можешь как-то помочь мне в этом деле?";
				link.l1.go = "Shark";
			}
			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation") && pchar.questTemp.Saga.BarbTemptation == "terrax" && CheckCharacterItem(pchar, "witches_hammer"))
			{
				link.l1 = "Тебе не интересно получить от меня заветную книгу, что ты так резок?";
				link.l1.go = "book";
			}
			//<-- Сага
			//поручение капитана - выкуп
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && NPChar.city == pchar.GenQuest.CaptainComission.PiratesCity)
			{
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
				{
					link.l1 = "Я по поводу твоего пленника.";
					link.l1.go = "CapComission1";
					DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
				}	
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.PirateShips"))
				{
					link.l1 = "Здравствуй, Генерал Ли, я по поводу твоего поручения.";
					link.l1.go = "CapComission3";
				}
				if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
				{
					link.l1 = "Я по поводу твоего пленника.";
					link.l1.go = "CapComission6";
				}
			}

	//********************линейка Ли ***************************

			if (CheckAttribute(PChar, "questTemp.GothicLee") && pchar.questTemp.GothicLee == "Start_Lee" && !CheckAttribute(npchar, "quest.Gothic.Lee"))
			{
 	                PlaySound("VOICE\Russian\gotica\LEE\LEE_HALLO_00.wav");
                                dialog.text = "Какого дьявола тебя позволили пустить сюда, что ты делаешь сдесь? Я думал ты мертв...";
		link.l1 = "Правда или сон? Генерал Ли, это ты?";
				link.l1.go = "Gothic_HALLO_1";
				}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_BadResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Я ждал тебя. Что скажете, "+ GetSexPhrase("месье","мадемуазель") +"?";
                    link.l1 = "Я не смог"+ GetSexPhrase("","ла") +" привести донну Анну, я сожалею, что так вышло...";
                    link.l1.go = "Gothic_5";
				}
            if (pchar.questTemp.GothicLee == "GothicLeeTakeAnna_NiceResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Дружище, я даже не знаю, как мне тебя благодарить!";
                    link.l1 = "Это было не сложно, Ли...";
                    link.l1.go = "Gothic_7";
                    DoQuestFunctionDelay("GothicLee_townhall", 0.1);
				}

            if (pchar.questTemp.GothicLee == "AnnaIsLife" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{
                                dialog.text = "Дружище, для тебя снова поручение деликатного свойства. У меня есть серьезные опасения за жизнь донны де Лейва. Навестити ее, пожалуйста, она сейчас у меня в резиденции в соседней комнате. Сеньора посвятит тебя в подробности.";
								                    link.l1 = "Я сделаю это немедленно.";
                    link.l1.go = "exit";
                    pchar.questTemp.GothicLee = "GothicLeeAnnaHant_toAnna";
                    LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
 
			}

            if (pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{
                    dialog.text = "Ты как всегда на высоте, я начинаю думать, что нет такого дела, которое ты не смог бы выполнить. Вот возми награду, и донна де Лейва хочет тебя лично поблагодарить.";
                    link.l1 = "Спасибо, Генерал Ли...";
                    link.l1.go = "exit";
	LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
					DeleteAttribute(&locations[FindLocation("Mayak10")], "DisableEncounters"); //откроем энканутеры
					pchar.questTemp.GothicLee = "empty";
					SaveCurrentQuestDateParam("questTemp");
					
					CloseQuestHeader("GothicLee_2_KillAnnaHanters");
					AddMoneyToCharacter(pchar, 15000);
			}

            if (pchar.questTemp.GothicLee == "SeekBible" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
				{

                                dialog.text = "";
                                link.l1 = "Что произошло за последнее время?";
                                link.l1.go = "Gothic_SeekBible";
 

			}

            if (pchar.questTemp.GothicLee == "SeekBible_BadResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Чумакейро довел до меня информацию, что вы не сумели выполнить его поручение.";
                    link.l1 = "В общем-то, да. Я сделал"+ GetSexPhrase("","а") +" все, что мог.";
                    link.l1.go = "Gothic_3_1";
				}

            if (pchar.questTemp.GothicLee == "SeekBible_GoodResult" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+ GetSexPhrase("Друг мой","Госпожа") +", Аарон и его община находятся в религиозном экстазе. Он мне сказал, что вы сумели сделать нечто очень важное для него. Скажите мне, что это?";
                    link.l1 = "Я просто разыскал"+ GetSexPhrase("","а") +" для него один утерянный предмет. Книгу, древний христианский трактат.";
                    link.l1.go = "Gothic_3_2";
				}

            if (pchar.questTemp.GothicLee == "RockBras_toSeekPlace" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                     dialog.text = "Так, "+pchar.name+". Расскажи мне о результатах миссии по спасению Горна.";
                    link.l1 = "Пока я не сумел"+ GetSexPhrase("","а") +" найти его, но я продолжу поиски...";
                    link.l1.go = "exit";
					link.l2 = "Ли, я искал"+ GetSexPhrase("","а") +" его повсюду, но найти так и не сумел"+ GetSexPhrase("","а") +". Я долж"+ GetSexPhrase("ен","на") +" признаться, что все бесполезно...";
                    link.l2.go = "Gothic_5_6";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsDead" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Так, "+pchar.name+", я ждал тебя. Есть какие-нибудь новости о Горне?";
                    link.l1 = "Новости есть, Генерал Ли. Однако, они неутешительные - Горн погиб при побеге из застенков Инквизиции...";
                    link.l1.go = "Gothic_5_7";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsSaved" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Вижу, "+pchar.name+", все в порядке. Горн уже рассказал, что ему довелось пережить в Инквизиции и как вы вытащили его оттуда. Я в восхищении!";
                    link.l1 = "Ли, это было совершенно обычное дело...";
                    link.l1.go = "Gothic_5_8";
				}
            if (pchar.questTemp.GothicLee == "RockBras_RockIsAgony" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Так, "+pchar.name+", я ждал тебя. Есть какие-нибудь новости о Горне?";
                    link.l1 = "Новости есть, Генерал Ли. Однако, они неутешительные - Инквизиция замучила Горна до смерти. Он испустил дух у меня на руках...";
                    link.l1.go = "Gothic_5_7";
				}

            if (pchar.questTemp.GothicLee == "ThreeCorsairs_backGovernor" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Ха, " + GetFullName(pchar) + ", я счастлив поздравить тебя с присвоением титула барон"+ GetSexPhrase("а","ессы") +"! Поверь, здесь редко кто удостаивается такой чести.";
                    link.l1 = "Признаться, Ли, я не очень понимаю, зачем он мне? Тем более, что достался он мне недешево...";
                    link.l1.go = "Gothic_6_3";
				}

            if (pchar.questTemp.GothicLee == "GuardPP_GoodWork" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
					if (LAi_IsDead(characterFromId("SoleiRoyalCaptain")))
					{
						dialog.text = ""+pchar.name+", ты потерял 'Солей Руаяль'!";
						link.l1 = "Я спас"+ GetSexPhrase("","ла") +" Порт-о-Принс и пустил"+ GetSexPhrase("","а") +" на дно мощнейшую эскадру испанцев!";
						link.l1.go = "Gothic_7_4";
					}
					else
					{
						dialog.text = "Барон"+ GetSexPhrase("","есса") +", мне уже известно о вашей победе. Что я могу сказать? Прекрасно, "+ GetSexPhrase("друг мой","мадемуазель") +", просто великолепно!";
						link.l1 = "Первая военная операция выполнена, Генерал Ли...";
						link.l1.go = "Gothic_7_2";					
					}
				}

            if (pchar.questTemp.GothicLee == "GuardPP_SoleiRoyalSunk" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", ты потерял 'Солей Руаяль'!";
                    link.l1 = "Я спас"+ GetSexPhrase("","ла") +" Порт-о-Принс и пустил"+ GetSexPhrase("","а") +" на дно мощнейшую эскадру испанцев!";
                    link.l1.go = "Gothic_7_4";
				}

            if (pchar.questTemp.GothicLee == "GuardPP_DieHard" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", ты не сумел защитить Порт-о-Принс! В чем дело?!";
                    link.l1 = "Ли, испанцы сумели собрать эскадру невиданной силы! Мне пришлось отступить...";
                    link.l1.go = "Gothic_7_6";
				}
            if (pchar.questTemp.GothicLee == "GuardPP_Late" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = ""+pchar.name+", ты не сумел защитить Порт-о-Принс! В чем дело?!";
                    link.l1 = "Я не успел"+ GetSexPhrase("","а") +" вовремя, Генерал Ли, когда я подош"+ GetSexPhrase("ел","ла") +" к городу, он уже был испанским...";
                    link.l1.go = "Gothic_7_7";
				}


            if (pchar.questTemp.GothicLee == "OccupySD_toWeWon" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
					dialog.text = "Что скажете, барон"+ GetSexPhrase("","есса") +"? Как прошла операция?";
					if (LAi_IsDead(characterFromId("SoleiRoyalCaptain")))
					{
						link.l1 = "Я захватил"+ GetSexPhrase("","а") +" Санто-Доминго, теперь этот город принадлежит Франции! Но не все прошло гладко...";
						link.l1.go = "Gothic_10_4";
					}
					else
					{
						link.l1 = "Я захватил"+ GetSexPhrase("","а") +" Санто-Доминго, теперь этот город принадлежит Франции!";
						link.l1.go = "Gothic_10_6";
					}
				}

            if (pchar.questTemp.GothicLee == "QuestLineBreake" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Я не имею дело с людьми, нарушающими свое слово. Мне больше нечего тебе сказать.";
                    link.l1 = "...";
                    link.l1.go = "exit";
                    bWorldAlivePause   = true; // Конец линейки
				}
            if (pchar.questTemp.GothicLee == "EndOfQuestLine" && !CheckAttribute(pchar, "questTemp.Gothic.Lee"))
			{
                    dialog.text = "Действуй самостоятельно в интересах Франции, о флибустьерах тоже не забывай. Война закончилась, пора обустроить свою жизнь, барон"+ GetSexPhrase("","есса") +"...";
                    link.l1 = "Хорошо, Ли.";
                    link.l1.go = "exit";
                    bWorldAlivePause   = true; // Конец линейки
				}
		break;
		
		case "shark":
			dialog.text = "Стивен Додсон? Не знаю, поможет ли тебе то, что я расскажу, поскольку Акула бесследно сгинул уже как несколько месяцев, и от него нет ни слуху, ни духу. Что и неудивительно - ведь он прикончил Блейза Шарпа, дискредитировав этим нелепым поступком свое имя и настроив против себя ряд влиятельных корсаров.";
			link.l1 = "У меня есть основания полагать, что Акула невиновен в гибели Шарпа. Доказать я этого не могу, но, возможно, сам Акула сможет это прояснить. Так ты скажешь мне про него хоть что-нибудь?";
			link.l1.go = "shark_1";
		break;
		
		case "shark_1":
			dialog.text = "Несколько месяцев назад Стивен явился ко мне и предложил очень странную сделку: он оставил мне в залог свой фрегат 'Фортуна' взамен на бриг с трюмами, полными продовольствия, на один месяц. Потом или бриг с деньгами за провиант, или фрегат остается у меня. Прошел месяц - ни Акулы, ни моего брига, ни денег за товар\nКроме того, пришло известие о смерти Блейза, и то, что Акула подозревается в его убийстве. Ну и что я мог решить? Правильно! Что Стив попросту слинял от греха подальше. Его фрегат я продал какому-то англичанину по имени Вильям Патерсон, он был очень доволен покупкой и отвалил кучу дублонов\nТак что я полностью компенсировал свои потери и зла на Стива не держу. А что касается убийства Шарпа, так меня это особо и не касается, у меня своих забот полон рот.";
			link.l1 = "А ты не считаешь, что если бы он задумал слинять, то ему не нужен был бы твой бриг? У него же свой корабль был в сто раз лучше брига. По-моему, Акула что-то задумал, но, видимо, дела пошли не так как надо, раз не вернулся в срок.";
			link.l1.go = "shark_2";
		break;
		
		case "shark_2":
			dialog.text = "Как я тебе уже сказал, меня мало волнуют проблемы Додсона. Я все сделал по уговору, а зачем ему понадобился мой бриг - это надо у него спросить, я его не принуждал к этому обмену.";
			link.l1 = "Ладно, оставим это. Ты, конечно, прав. Скажи, а куда Стивен направился на твоем бриге, ты не в курсе?";
			link.l1.go = "shark_3";
		break;
		
		case "shark_3":
			dialog.text = "А кто же его знает... Но есть у меня кое-какие догадки. Отбыв из нашей бухты, он взял курс на северо-запад, в сторону Мэйна. Там находится либо залив Гибели, печально известный тем, что окрестные джунгли бувально кишат дикими воинственными индейцами, либо, через Мексиканский залив - Новая Испания, с папистами и инквизицией\nЧто-то не верится, что он решился бы отправиться в эти места. Однако там, на северо-запад от Кубы, говорят, есть некое загадочное место, именуемое островом Справедливости. Многие считают это выдумкой, а вот я тебе скажу - я в это верю. И не потому, что я такой романтик, а потому что есть самые настоящие реальные люди, которые туда плавают на своих баркасах. Во всяком случае, раньше плавали.";
			link.l1 = "И что же это за люди?";
			link.l1.go = "shark_4";
		break;
		
		case "shark_4":
			dialog.text = "Буканьеры с Кубы. Грузили полные баркасы разделанных бычьих туш, брали курс на северо-запад, а спустя какое-то время возвращались назад, либо с карманами, полными денег, либо с редкими и ценными товарами.";
			link.l1 = "Очень интересно! И где же найти их, этих буканьеров?";
			link.l1.go = "shark_5";
		break;
		
		case "shark_5":
			dialog.text = "Ты у меня спрашиваешь? Поищи в лесах по всей Кубе. А если и найдешь, то навряд ли они тебе вот так возьмут и расскажут - не станут они раскрывать свой источник заработка. Так что не трать время по-пустому, тем более, что их уже давно за этим занятием никто не видел\nКроме них, слыхал я про некие заметки, написанные испанским мореплавателем по фамилии Альворадо, который лично бывал на этом острове. Вот я и думаю: а не направился ли Стивен именно туда?";
			link.l1 = "Остров, про который никто не знает, который не обозначен на картах... Да уж. Неутешительные сведения.";
			link.l1.go = "shark_6";
		break;
		
		case "shark_6":
			dialog.text = "Я сразу сказал, что мой рассказ тебе навряд ли чем поможет. А зачем тебе вдруг понадобился Додсон?";
			link.l1 = "Мы с Лесным Дьяволом хотим предложить его кандидатуру на пост лидера Берегового братства. Как я уже сказал, есть серьезные основания полагать, что Блейза убил кто-то другой.";
			link.l1.go = "shark_7";
		break;
		
		case "shark_7":
			dialog.text = "Хех! Значит, Ян за него? Ну, ты знаешь законы: для избрания лидера Додсон должен получить голоса всех баронов.";
			link.l1 = "Знаю. Отсюда мой второй вопрос: ты проголосуешь за Стивена Додсона на выборах?";
			link.l1.go = "shark_8";
		break;
		
		case "shark_8":
			dialog.text = "Пускай он сначала вернется... А вообще, мне все равно, кто будет возглавлять Братство, лишь бы делал это толково и не лез в мои дела. Как я тебе уже говорил, у меня своих проблем по горло. Ты знаешь, сколько на нашем острове ведьм и колдунов? Нет? А я тебе скажу: легион! И кроме того, полно папистов из Сантьяго и Гаваны\nВот, кстати, о колдунах. Есть такая книга, трактат, называется 'Молот ведьм'. Я очень хочу получить эту книгу, но обязательно на английском языке, потому что то, что я встречал - латинский, немецкий и испанский переводы, не годятся, так как я не знаю этих языков. Привезешь мне книгу - отдам свой голос за Додсона\nНо учти, что достать этот трактат для меня также взялся и Джекман, в обмен на голос в его пользу, и если он тебя опередит - то не обессудь.";
			link.l1 = "Хорошо, я это учту. Спасибо за то, что уделил время. До встречи!";
			link.l1.go = "shark_9";
		break;
		
		case "shark_9":
			DialogExit();
			pchar.questTemp.Saga.SharkHunt = "after_marlow";
			npchar.quest.sharkbegin = "true";
			AddQuestRecord("SharkHunt", "2");
		break;
		
		case "book":
			dialog.text = "Книгу? Я так понимаю, речь идет о 'Молоте ведьм'?";
			link.l1 = "Ну конечно. Мне удалось разыскать ее для тебя. Она на английском, как ты и просил.";
			link.l1.go = "book_1";
		break;
		
		case "book_1":
			dialog.text = "Хех, дружище, извини за грубый прием. Более не повторится... Дай мне взглянуть на это чудо!";
			link.l1 = "Конечно, пожалуйста.";
			link.l1.go = "book_2";
		break;
		
		case "book_2":
			RemoveItems(pchar, "witches_hammer", 1); // удалить трактат
			dialog.text = "Наконец-то! Трепещите, слуги ада! Я не оставлю вас в покое, пока эта рука способна держать...";
			link.l1 = "Я рад за тебя, Генерал Ли. Так что насчет твоего голоса в Совете?";
			link.l1.go = "book_3";
		break;
		
		case "book_3":
			dialog.text = "Как я тебе уже говорил - мне все равно, кто станет главой. Уверен, Свенсон не выберет на эту роль никудышного кандидата. Так что свой голос я отдаю тебе. Делай с ним, что сочтешь нужным. Вот мой осколок.";
			link.l1 = "Спасибо, Ли. Еще увидимся!";
			link.l1.go = "book_4";
		break;
		
		case "book_4":
			GiveItem2Character(pchar, "splinter_zm"); // дать осколок
			DialogExit();
			NextDiag.CurrentNode = "I_know_you_good";
			AddQuestRecord("BarbTemptation", "27");
			if (CheckCharacterItem(pchar, "splinter_mt") && CheckCharacterItem(pchar, "splinter_jb") && CheckCharacterItem(pchar, "splinter_zm")) Saga_GiveCalendar();
			ChangeCharacterComplexReputation(pchar, "fame", 1);
		break;

 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "I_know_you_good":
            dialog.text = NPCStringReactionRepeat(GetFullName(pchar) + ", рад тебя видеть! Зачем пожаловал"+ GetSexPhrase("","а") +" на этот раз?",
                         "Ну что тебе еще?", "Долго это будет продолжаться? Если тебе делать нечего, не отвлекай других!",
                         "Ты "+ GetSexPhrase("хороший капер","хорошая девушка") +", поэтому живи пока. Но общаться и разговаривать с тобой я больше не желаю.", "repeat", 10, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Да, собственно, просто так заглянул"+ GetSexPhrase("","а") +", проведать. Ничего по делу нет.",
                                               "Ничего, просто так...",
                                               "Хорошо, Генерал Ли, извини...",
                                               "Вот черт возьми, доиграл"+ GetSexPhrase("ся","ась") +"!!!", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			NextDiag.TempNode = "I_know_you_good";
			
			if (sti(pchar.GenQuest.Piratekill) > 20)
			{
				dialog.text = RandPhraseSimple("У тебя крыша поехала? Вообразил себя мясником? Все пираты злы на тебя, приятель, так что лучше тебе убраться отсюда побыстрее.", "Ты, приятель, похоже, из ума выжил. Руки чесались сильно? Теперь не обессудь - здесь тебе делать нечего. Вали отсюда побыстрее!");
				link.l1 = RandPhraseSimple("Послушай, я хочу исправить ситуацию...", "Помоги мне решить эту проблему...");
				link.l1.go = "pirate_town";
				break;
			}
			//поручение капитана - выкуп
			if (CheckAttribute(pchar, "GenQuest.CaptainComission") && CheckAttribute(pchar,"GenQuest.CaptainComission.toMayor"))
			{
				link.l1 = "Я по поводу твоего пленника.";
				link.l1.go = "CapComission1";
				DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
			}		
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.PirateShips"))
			{
				link.l1 = "Здравствуй, Генерал Ли, я по поводу твоего поручения.";
				link.l1.go = "CapComission3";
			}
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				link.l1 = "Я по поводу твоего пленника.";
				link.l1.go = "CapComission6";
			}
		break;
		
	//-----------------------------------Поручение капитана - Выкуп-------------------------------------------------
		case "CapComission1":
			dialog.text = "Хо-хо. Ты думаешь, у меня только одни пленник? Называй, кого конкретно имеешь в виду?";
			link.l1 = pchar.GenQuest.CaptainComission.SlaveName + ". Есть такой?";
			link.l1.go = "CapComission2";
			DeleteAttribute(pchar,"GenQuest.CaptainComission.toMayor");
		break;

		case "CapComission2":
			if(CheckAttribute(pchar,"GenQuest.CaptainComission.DaysLeft"))
			{
				dialog.text = "Был. Я его продал к чёртовой матери этому плантатору с Барбадоса - полковнику Бишопу, он заезжал на прошлой неделе.";
				link.l1 = "Вот чёрт...";
				link.l1.go = "CapComission2_1";
			}
			else
			{
				dialog.text = "А-а, ну наконец-то. Я уж было подумывал продать его к чёртовой матери этому плантатору с Барбадоса, он должен появиться у меня через неделю-другую... Ты выкуп привез"+ GetSexPhrase("","ла") +"?";
				link.l1 = "Слушай, тут такое дело... В общем, у меня нет таких денег. Но я готов"+ GetSexPhrase("","а") +" отработать.";
				link.l1.go = "CapComission2_2";
				if(makeint(pchar.money) > 150000)
				{
					link.l2 = "Хорошо, что не продал. Вот деньги - 150000 песо. Где я могу его забрать?"
					link.l2.go = "CapComission2_3";
				}	
			}
		break;
		
		case "CapComission2_1":
			dialog.text = "Долго ты телил"+ GetSexPhrase("ся","ась") +"... А кстати, этот невольник к тебе каким боком? Я, помнится, его родственникам выкуп назначал.";
			link.l1 = "Да я по поручению этих родственников и приехал"+ GetSexPhrase("","а") +".";
			link.l1.go = "CapComission2_11";
		break;
		
		case "CapComission2_11":
			dialog.text = "Ну, опоздал"+ GetSexPhrase("","а") +" ты - что я могу поделать?";
			link.l1 = "Слушай, а за сколько продал, если не секрет?"; 
			link.l1.go = "CapComission2_12";
		break;
		
		case "CapComission2_12":
			dialog.text = "Э-э, не секрет, конечно, но я тебе не скажу. А то смеяться будешь, ха-ха-ха-ха... Ну, бывай.";
			link.l1 = "Счастливо.";
			link.l1.go = "exit";
			AddQuestRecord("CaptainComission1", "10");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			CaptainComission_GenerateManager();
		break;
		
		case "CapComission2_2":
			if(rand(1) == 0)
			{
				dialog.text = "Гхм-гхм... Есть у меня одно дело... Даже не знаю, как начать... В общем, нужно пустить ко дну одного зарвавшегося пирата.";
				link.l1 = "А разве нельзя убрать его в джунглях?";
				link.l1.go = "CapComission2_2_1";
			}
			else
			{
				dialog.text = "Ну, " + pchar.name + ", ты же знаешь, что так дела не делаются. Приходи с деньгами и получишь своего заморыша, хе-хе.";
				link.l1 = "Ну ладно, до встречи.";
				link.l1.go = "CapComission2_4";
			}
		break;

		case "CapComission2_2_1":
			dialog.text = "Ну, понимаешь ли, так серьёзные дела не делаются... Мне не смерть его нужна, мне нужно отбить охоту у слишком ретивых разевать рот на мою часть добычи. Хотя, если он отправится к осьминогам - я не огорчусь.";
			link.l1 = "А почему тебе не послать за ним своих людей?";
			link.l1.go = "CapComission2_2_2";
		break;
		
		case "CapComission2_2_2":
			CaptainComission_GetRandomShore();
			pchar.GenQuest.CaptainComission.ShipName1 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.ShipName2 = GenerateRandomNameToShip(sti(NPChar.nation));
			pchar.GenQuest.CaptainComission.UnknownPirateName = "l" + rand(GetNamesCount(NAMETYPE_ORIG) - 1);
			sLoc = XI_ConvertString(pchar.GenQuest.CaptainComission.Island + "Abl");
			dialog.text = "Хм... В общем некий " + GetName( NAMETYPE_ORIG, pchar.GenQuest.CaptainComission.UnknownPirateName, NAME_NOM) + " убедил часть пиратов, что в нашем тайнике близ " + XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Gen") + " есть и их доля. Недавно они снялись с якоря и на двух судах '" + pchar.GenQuest.CaptainComission.ShipName1 + "' и '" + pchar.GenQuest.CaptainComission.ShipName2 + "' ушли к " + sLoc + ". Понимаешь теперь, почему я не могу поручить это дело своим людям?";
			link.l1 = "Понятно. И сколько у меня есть времени?";
			link.l1.go = "CapComission2_2_3";
		break;
		
		case "CapComission2_2_3":
			dialog.text = "Думаю, дней 12-15, не больше. Мне важно, чтоб они не успели добраться до тайника, иначе топить их с ценным грузом на борту не будет смысла. Уж лучше пусть везут его сюда.";
			link.l1 = "Хорошо, я берусь за это дело. Постараюсь успеть.";
			link.l1.go = "CapComission2_2_4";
		break;
		
		case "CapComission2_2_4":
			AddQuestRecord("CaptainComission1", "24");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sShipName1", pchar.GenQuest.CaptainComission.ShipName1);
			AddQuestUserData("CaptainComission1", "sShipName2", pchar.GenQuest.CaptainComission.ShipName2);
			AddQuestUserData("CaptainComission1", "sShoreName", XI_ConvertString(pchar.GenQuest.CaptainComission.Island.Shore + "Abl"));
			AddQuestUserData("CaptainComission1", "sShoreType", XI_ConvertString(GetIslandByArealName(pchar.GenQuest.CaptainComission.Island) + "Dat"));
			pchar.quest.CapComission_PirateAttack.win_condition.l1 = "location";
            pchar.quest.CapComission_PirateAttack.win_condition.l1.location = pchar.GenQuest.CaptainComission.Island;
            pchar.quest.CapComission_PirateAttack.function = "CaptainComission_GeneratePirateShips"; 
			SetFunctionTimerCondition("CaptainComission_PirateShipsOver", 0, 0, 15, false);
			pchar.GenQuest.CaptainComission.PirateShips = "goaway";	
			DialogExit();
		break;
		
		case "CapComission2_3":
			dialog.text = "Не переживай. Мои люди доставят его к тебе на борт. А он тебе кто?";
			link.l1 = "Никто. Я выполняю поручение его родственника.";
			link.l1.go = "CapComission2_31";
		break;
		
		case "CapComission2_31":
			dialog.text = "А-а, это хорошо. А то я уж было расстроился, что продешевил, назначив такую низкую цену за твоего человека. Ха-ха-ха-ха... Ну, бывай.";
			link.l1 = "Счастливо.";
			link.l1.go = "CapComission2_32";
		break;
		
		case "CapComission2_32":
			AddQuestRecord("CaptainComission1", "9");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City));			
			addMoneyToCharacter(pchar, -150000);
			DialogExit();
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission2_4":
			if(!CheckAttribute(pchar,"GenQuest.CaptainComission.RepeatSpeak"))
			{
				AddQuestRecord("CaptainComission1", "31");
				AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			}	
			pchar.GenQuest.CaptainComission.RepeatSpeak = true;		
			DialogExit();
		break;
		
		case "CapComission3":
			dialog.text = "Ну что, " + GetFullName(pchar) + ", пустил"+ GetSexPhrase("","а") +" на дно моего приятеля?.. хе-хе-хе...";
			if(pchar.GenQuest.CaptainComission.PirateShips == "goaway")
			{
				link.l1 = "Нет. Я не успел"+ GetSexPhrase("","а") +" их догнать. И на обратном пути они мне не попадались.";
				link.l1.go = "CapComission4";
			}
			if(pchar.GenQuest.CaptainComission.PirateShips == "died")	
			{
				link.l1 = "Да, как и договаривались - отправил"+ GetSexPhrase("","а") +" кормить акул.";
				link.l1.go = "CapComission5";
			}
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
		break;
		
		case "CapComission4":
			dialog.text = "Чёрт! Попадались - не попадались, какая теперь разница?.. Ну, и что ты предложишь дальше?";
			link.l1 = "Может, у тебя есть какое-нибудь поручение попроще?";
			link.l1.go = "CapComission4_1";
			link.l2 = "Слушай, "+ NPChar.name +", уступи мне этого пленника подешевле...";
			link.l2.go = "CapComission4_2";
		break;
		
		case "CapComission4_1":
			dialog.text = "Нет.";
			link.l1 = "...Ну, тогда счастливо оставаться...";
			link.l1.go = "CapComission4_3";
		break;
		
		case "CapComission4_2":
			dialog.text = "Подешевле?!! Только что из-за твоей нерасторопности я лишился своего тайника! И теперь я могу уступить его подороже! Забирай за 200000, если хочешь.";
			link.l1 = "Дорого это... Прощай...";
			link.l1.go = "CapComission4_4";
			if(sti(pchar.money) >= 200000)
			{
				link.l2 = "А чёрт, держи свои деньги.";
				link.l2.go = "CapComission4_5";
			}	
		break;
		
		case "CapComission4_3":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "27");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","ла"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_DAT));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();
		break;
		
		case "CapComission4_4":
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("CaptainComission1", "28");
			AddQuestUserData("CaptainComission1", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
		break;
		
		case "CapComission4_5":
			dialog.text = "Можешь забрать заморыша...";
			link.l1 = "Счастливо оставаться.";
			link.l1.go = "CapComission4_6";
		break;
		
		case "CapComission4_6":
			addMoneyToCharacter(pchar, -200000);
			AddQuestRecord("CaptainComission1", "29");
			AddQuestUserData("CaptainComission1", "sName", ChangeNameCase(NAMETYPE_MAIN, pchar.GenQuest.CaptainComission.PirateName, NAME_NOM));
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			pchar.GenQuest.CaptainComission.SlaveAddMoney = true;
			DialogExit();	
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission5":
			dialog.text = "Хо-хо! Вот это работа! Забирай своего заморыша и бывай здоров"+ GetSexPhrase("","а") +".";
			link.l1 = "Спасибо. Счастливо оставаться.";
			link.l1.go = "CapComission5_1";
		break;
		
		case "CapComission5_1":
			AddQuestRecord("CaptainComission1", "34");
			AddQuestUserData("CaptainComission1", "sName", pchar.GenQuest.CaptainComission.SlaveName);
			AddQuestUserData("CaptainComission1", "sCity", XI_ConvertString("Colony" + pchar.GenQuest.CaptainComission.City + "Gen"));
			AddQuestUserData("CaptainComission1", "sCharName", pchar.GenQuest.CaptainComission.Name);
			DeleteAttribute(pchar,"GenQuest.CaptainComission.PirateShips");
			DialogExit();		
			AddDialogExitQuestFunction("CaptainComission_GeneratePassengerSlave");	
		break;
		
		case "CapComission6":
			dialog.text = "Ты выкуп привез"+ GetSexPhrase("","ла") +"? Ведь я не шутил, когда сказал, что продам его плантаторам.";			
			link.l1 = "Слушай, "+ NPChar.name +", тут такое дело... В общем, у меня нет таких денег. Но я готов"+ GetSexPhrase("","а") +" отработать.";
			link.l1.go = "CapComission2_2";
			if(makeint(pchar.money) > 150000)
			{
				link.l2 = "Хорошо, что не продал. Вот деньги - 150000 песо. Где я могу его забрать?"
				link.l2.go = "CapComission2_3";
			}			
		break;

		//********************* Пиратская линейка *********************
		case "PL_Q8_deck":
			dialog.text = "И что ты делаешь у меня на палубе? Ведь идем на Порто Белло!";
			link.l1 = "Да, я помню...";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;
		case "PL_Q8_deck_1":
			dialog.text = "Тебе не стоит терять время, ты уж поверь мне.";
			link.l1 = "Да, я знаю.";
			link.l1.go = "exit";
			NextDiag.TempNode = "PL_Q8_deck_1";
		break;

		//********************* Квест Асокльда *********************
   		case "Step_Lee_1":
			dialog.text = "Что за вопросы такие странные?! Может, и доводилось, а почему я тебе об этом должен говорить?";
			link.l1 = "Ты не кипятись. Все дело в том, что я ищу три предмета индейского культа. Для покупки. Все одно - вы либо выбрасываете эту дрянь, либо продаете за бесценок. Я готов"+ GetSexPhrase("","а") +" заплатить щедро за эти вещи, если они у тебя есть.";
			link.l1.go = "Step_Lee_2";
		break;
   		case "Step_Lee_2":
			dialog.text = "А что за вещи?";
			link.l1 = "Индейская статуэтка Тлалока, церемониальный сосуд и церемониальный нож.";
			link.l1.go = "Step_Lee_3";
		break;
   		case "Step_Lee_3":
			dialog.text = "Хех, все эти вещи - из драгоценных металлов. Я коллекционирую эти предметы, местные шаманы верят, что они обладают магией поэтому большой спрос, знаешь ли, хорошие цены...";
			link.l1 = "Я понимаю. Я готов"+ GetSexPhrase("","а") +" заплатить две цены за эти индейские побрякушки, только в непереплавленном виде, так сказать... А вообще, эти вещи у тебя есть? Или мы бестолковый разговор ведем?";
			link.l1.go = "Step_Lee_4";
		break;
   		case "Step_Lee_4":
			dialog.text = "Эти вещи у меня есть. И, в принципе, я готов буду тебе их продать. Но только две цены - не предмет для серьезного разговора. Слишком мало.";
			link.l1 = "И сколько ты хочешь?";
			link.l1.go = "Step_Lee_5";
		break;
   		case "Step_Lee_5":
			dialog.text = "Миллион.";
			link.l1 = "Что?!!! Ты рехнулся?!";
			link.l1.go = "Step_Lee_6";
		break;
   		case "Step_Lee_6":
			dialog.text = "Нисколько. Ты что думаешь, за какие-то две цены, размером в три тысячи, я буду мараться? Это ты рехнул"+ GetSexPhrase("ся","ась") +", "+ GetSexPhrase("друг мой","подруга") +", знаешь ли, они мне не дешево достались. Не нравится - иди в магазины, попробуй там купить.";
			link.l1 = "Черт возьми, Генерал Ли!";
			link.l1.go = "Step_Lee_7";
			pchar.questTemp.Ascold.Lee = 1;
		break;
   		case "Step_Lee_7":
			dialog.text = "Ладно, хватит болтать. Берешь или нет?";
			link.l1 = RandPhraseSimple("Да ни за что! За такие деньги я весь Порт Рояль куплю!", "За миллион? Да ну что ты! Нет, конечно.");
			link.l1.go = "exit";
            if (sti(pchar.money) >= 1000000)
            {
    			link.l2 = "Эх, беру! И заверни мне это в подарочную упаковку!";
    			link.l2.go = "Step_Lee_8";
            }
            else
            {
    			link.l2 = "Я бы взял"+ GetSexPhrase("","а") +", да таких денег нет. Пойду, может заработаю еще...";
    			link.l2.go = "exit";
            }
		break;
   		case "Step_Lee_8":
			Log_Info("Вы получили статуэтки");
			PlaySound("interface\important_item.wav");
			dialog.text = GetFullName(pchar) + ", с тобой приятно иметь дело. Получай свои бесценные артефакты! Надеюсь, они принесут тебе удачу, раз ты готов"+ GetSexPhrase("","а") +" платить на них такие деньги...";
			link.l1 = "Я тоже надеюсь, Генерал Ли.";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			DeleteAttribute(pchar, "questTemp.Ascold.Lee");
			pchar.questTemp.Ascold = "SoughtThreeObject";
    		GiveItem2Character(pchar, "indian019");
    		GiveItem2Character(pchar, "indian020");
    		GiveItem2Character(pchar, "indian021");
		break;
   		case "Step_Lee_9":
			dialog.text = "Есть у меня такие предметы. Пять миллионов - и они твои.";
			link.l1 = RandPhraseSimple("Пять миллионов?!!", "Пять миллионов... Хорошая сумма!");
			link.l1.go = "exit";
            if (sti(pchar.money) >= 5000000)
            {
    			link.l2 = "Похоже, что у меня нет другого выхода. Надо брать. Забирай деньги и давай поскорей предметы!";
    			link.l2.go = "Step_Lee_10";
            }
            else
            {
    			link.l2 = "Они мне очень нужны, но таких денег у меня нет...";
    			link.l2.go = "exit";
            }
		break;		
   		case "Step_Lee_10":
			Log_Info("Вы получили артефакты");
			PlaySound("interface\important_item.wav");
			dialog.text = GetFullName(pchar) + ", с тобой приятно иметь дело. Получай свои бесценные артефакты!";
			link.l1 = "Спасибо, Генерал Ли! Ты мне буквально жизнь спас...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -5000000);
    		GiveItem2Character(pchar, "sculMa1");
    		GiveItem2Character(pchar, "sculMa2");
    		GiveItem2Character(pchar, "sculMa3");
    		GiveItem2Character(pchar, "indian022");
    		pchar.questTemp.Azzy.Lee = 1;
		break;

	//******************** линейка Ли ***************************

                            case "GothicLee":
 	                PlaySound("VOICE\Russian\gotica\LEE\LEE_HALLO_00.wav");
                                dialog.text = "Какого дьявола тебя позволили пустить сюда, что ты делаешь здесь? Я думал ты мертв...";
		link.l1 = "Правда или сон? Генерал Ли, это ты?";
                                link.l1.go = "Gothic_HALLO_1";
                            break;

                            case "Gothic_HALLO_1":
	                PlaySound("VOICE\Russian\gotica\LEE\RICHTERBEWEISE_01.wav");
                                dialog.text = "Правда и что же!";
		link.l1 = "Объясни я тут ни чего не понимаю, где мы?";
                                link.l1.go = "Gothic_HALLO_2";
                            break;

                            case "Gothic_HALLO_2":
                                dialog.text = "Мы в другом мире, мой друг, в другой эпохе!";
		link.l1 = "В какой мать твою эпохе, что произошло?";
                                link.l1.go = "Gothic_HALLO_3";
                            break;

                            case "Gothic_HALLO_3":
                                dialog.text = "Я не знаю, но думаю это связано с разрушением барьера и с уничтожением Спящего!";
		link.l1 = "Не может быть?";
                                link.l1.go = "Gothic_HALLO_4";
                            break;

                            case "Gothic_HALLO_4":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_02.wav");
                                dialog.text = "Но это так, Горн сказал, что это ты разрушил барьер!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_5";
                            break;

                            case "Gothic_HALLO_5":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_03.wav");
                                dialog.text = "";
		link.l1 = "Да это дейсвительно был я!";
                                link.l1.go = "Gothic_HALLO_6";
                            break;

                            case "Gothic_HALLO_6":
	                PlaySound("VOICE\Russian\gotica\LEE\HALLO_04.wav");
                                dialog.text = "Ни когда бы не подумал, что человек мог бы выжить после всего этого!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_7";
                            break;

                            case "Gothic_HALLO_7":
                                dialog.text = "";
		link.l1 = "Ты сказал Горн?";
                                link.l1.go = "Gothic_HALLO_8";
                            break;

                            case "Gothic_HALLO_8":
	           PlaySound("VOICE\Russian\gotica\LEE\WHO_01.wav");
                                dialog.text = "Большой, черноволосый, плохой парень с большим топором, он отбил нашу шахту с твоей помощью, это было в колонии.";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_9";
                            break;

                            case "Gothic_HALLO_9":
	           PlaySound("VOICE\Russian\gotica\LEE\LEE_01.wav");
                                dialog.text = "Ты помнишь его, да!";
		link.l1 = "";
                                link.l1.go = "Gothic_HALLO_10";
                            break;

                            case "Gothic_HALLO_10":
	           PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE05.wav");
                                dialog.text = "";
	           link.l1 = "Конечно. А где он сейчас?";
                                link.l1.go = "Gothic_HALLO_11";
                            break;

                            case "Gothic_HALLO_11":
                                dialog.text = "Он, решил узнать об этом мире больше, собрал вещи и ушел, куда не знаю!";
		link.l1 = "Это хорошая новость! А чем ты здесь занимаешься!";
                                link.l1.go = "Gothic_HALLO_12";
                            break;

        case "Gothic_HALLO_12":
            dialog.text = "Я работаю на правительство Франции, это долг за предоставленную территорию, разные секретные поручения и тому подобное, если хочешь я мог бы замолвить слово за тебя.";
            link.l1 = "Я был бы не против, но тут Ли, такое дело.";
            link.l1.go = "Gothic_HALLO_13";
        break;
        case "Gothic_HALLO_13":
            dialog.text = "Говори, я слушаю тебя!";
            link.l1 = "Ты в курсе, что о нашем появлении в этом мире знают инквизиторы, это такая организация...";
            link.l1.go = "Gothic_HALLO_14";
        break;
        case "Gothic_HALLO_14":
            dialog.text = "Я знаю, что это за организация, но то, что бы знали о нас, как ты это узнал?";
            link.l1 = "Ты помнишь Декстора, за барьером, он был призраком, человеком Гамеза, он так же как и мы попал в эту эпоху и устроил охоту за мной с помощью святой инквизиции, тем самым обманув их - натравил на меня.";
            link.l1.go = "Gothic_HALLO_15";
        break;
        case "Gothic_HALLO_15":
            dialog.text = "Что ему нужно было от тебя?";
            link.l1 = "Мою голову.";
            link.l1.go = "Gothic_HALLO_16";
        break;
        case "Gothic_HALLO_16":
            dialog.text = "Ха-ха-ха, и он конечно её не получил?";
            link.l1 = "Как видишь, голова на месте.";
            link.l1.go = "Gothic_HALLO_17";
        break;
        case "Gothic_HALLO_17":
            dialog.text = "Давай ближе к сути?";
            link.l1 = "Так вот, при разговоре, как там его, а Франциско, я узнал что нашь мир того... В общем нет его.";
            link.l1.go = "Gothic_HALLO_18";
        break;
        case "Gothic_HALLO_18":
            dialog.text = "Как? Не может быть? Откуда он, этот Франциско узнал?";
            link.l1 = "Ему всё рассказал маг воды Ватрас.";
            link.l1.go = "Gothic_HALLO_19";
        break;
        case "Gothic_HALLO_19":
            dialog.text = "Ватрас?";
            link.l1 = "Ты не ослышался, Ватрас.";
            link.l1.go = "Gothic_HALLO_20";
        break;
        case "Gothic_HALLO_20":
            dialog.text = "И где он?";
            link.l1 = "Не знаю, знаю одно, он где-то здесь.";
            link.l1.go = "Gothic_HALLO_21";
        break;
        case "Gothic_HALLO_21":
            dialog.text = "Нам необходимо его найти? И так, раз ты не против работы на правительство я должен посмотреть на тебя в деле, есть для тебя предложение?";
            link.l1 = "";
             link.l1.go = "Gothic_HALLO_22";
                    CloseQuestHeader("Berglars");
	ChangeCharacterComplexReputation(pchar, "nobility", 2);
	AddCharacterExpToSkill(pchar, "Repair", 270);
	AddCharacterExpToSkill(pchar, "Sneak", 260);
	AddCharacterExpToSkill(pchar, "Cannons", 300);
	AddCharacterExpToSkill(pchar, "FencingL", 270);
	AddCharacterExpToSkill(pchar, "FencingH", 230);
	AddCharacterExpToSkill(pchar, "FencingS", 250);
        break;

                            case "Gothic_HALLO_22":
	           PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE03.wav");
                                dialog.text = "";
	           link.l1 = "Что за предложение ты хочешь сделать?";
                                link.l1.go = "GothicLee_1";
                            break;

                           case "GothicLee_1":
                                dialog.text = "В том мире, столько симпатичных женщин, одно заглядение, да ты и сам это видишь. Я хочу вверить в твои руки честь дорогого мне человека...";
		link.l1 = "Ли, давайте ближе к делу...";
                                link.l1.go = "Gothic_1";
                            break;

        //********************** Квест похищение донны Анны ************************
        case "Gothic_1":
            dialog.text = "Я знаю тебя, что ты отчаянн"+ GetSexPhrase("ый головорез","ая сорвиголова") +", и я знаю, что для тебя слово 'честь' не пустой звук. Сознаюсь, мне нелегко довериться тебе, но полагаю, это лучший вариант... Моя жизнь в твоих руках, и тебе решать, разменяешь ли ты ее на золото или докажешь, что ты "+ GetSexPhrase("рыцарь","благородная женщина") +"!";
			link.l1 = "Черт возьми, любой скажет, что я умею резать глотки, но никто не посмеет сказать, что я "+ GetSexPhrase("подлец и предатель","предательница") +"! Я слушаю тебя.";
            link.l1.go = "Gothic_2";
        break;
        case "Gothic_2":
            dialog.text = "Ты, наверное, в курсе, что я договорился доставить из Франции подруг для наших отважных флибустьеров. Теперь Сент-Луи - рай для нас наемников, всюду флюиды любви, женский смех кружит голову... Но увы, не все вкушают райские плоды.";
			link.l1 = "Амур избрал мишенью не только буканьеров?";
            link.l1.go = "Gothic_3";
        break;
        case "Gothic_3":
            dialog.text = "Дело не во мне. Есть дама, которая будет счастлива вдохнуть вольный воздух нашей колонии, но вынуждена сидеть взаперти под властью жестокого супруга... Вызволить ее из темницы, в которой она пребывает - дело"+ GetSexPhrase(", достойное кавалера"," справедливое! Вы, как женщина, должны понять меня") +"!";
			link.l1 = "Слава Иннасу, ты наконец-то добрался до сути. Кого я долж"+ GetSexPhrase("ен","на") +" спасти?";
            link.l1.go = "Gothic_4";
        break;
        case "Gothic_4":
            dialog.text = "Я знал, что на тебя можно положиться! Дама, о которой я говорю, - супруга дона Хосе Рамиреса де Лейва, коменданта Гаваны. Тебе надлежит проникнуть в город и найти способ вывести ее оттуда.\n"+
						  "Для того, чтобы ты смог сделать это успешно, я дам тебе Голанскую торговую лицензию сроком на 60 дней, с ней тебе будет разрешено заходить в испанские порты и посещать испанские города. И позаботься о том, чтобы на твоем корабле развевался дружественный Испании флаг.\n"+
				          "Вот, возьми это кольцо, по нему донна Анна Рамирес де Лейва узнает, что ты - мой доверенный человек. И помни, честь этой достойной женщины - в твоих руках.";
			link.l1 = "Я понял"+ GetSexPhrase("","а") +" тебя. Признаюсь, непривычное дело, однако ценю твое доверие... Все будет сделано в лучшем виде - не сомневайся.";
            link.l1.go = "exit";

                                         GiveNationLicence(HOLLAND, 60);
                                        GiveItem2Character(pchar,"DOjeronRing");
                                        pchar.questTemp.GothicLee = "GothicLeeTakeAnna_toHavana";
                                        AddQuestUserData("GothicLee_TakeAnna", "sSex", GetSexPhrase("","а"));
	                        LocatorReloadEnterDisable("Havana_town", "houseS1", true);
                                        AddQuestRecord("GothicLee_TakeAnna", "1");
        break;

        case "Gothic_5":
            dialog.text = "Дьявол! А я рассчитывал на вашу сообразительность и сноровку. А что случилось?";
			link.l1 = "Да ничего особенного, Ли. Я просто не сумел"+ GetSexPhrase("","а") +" к ней подобраться - жена коменданта столицы, как-никак...";
            link.l1.go = "Gothic_6";
        break;
        case "Gothic_6":
            dialog.text = "М-да, печально... Ну что же, это была моя личная просьба к вам, поэтому вы ни в чем не виноваты.\n"+
				          "Я прошу тебя заходить ко мне в дальнейшем, возможно, у меня будет для тебя дельце.";
			link.l1 = "Хорошо, генерал ЛИ...";
                   link.l1.go = "exit";
                   pchar.questTemp.GothicLee = "empty";
                   SaveCurrentQuestDateParam("questTemp");
                   SetTimerCondition("GothicLee_Lee_SeekBible", 0, 1, 0, false);
                   CloseQuestHeader("GothicLee_TakeAnna");
                   TakeItemFromCharacter(pchar, "letter_open");
                   BackItemDescribe("letter_open");
	ChangeCharacterComplexReputation(pchar, "nobility", 10);
	AddCharacterExpToSkill(pchar, "Sneak", -100);
	AddCharacterExpToSkill(pchar, "Sailing", -100);
	ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
                   PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
			//слухи
			AddSimpleRumour("Ходят слухи, что капитан " + GetFullName(pchar) + " провалил"+ GetSexPhrase("","а") +" какое-то очень важное задание Ли, связанное с амурными делами...", FRANCE, 5, 1);
		break;
        case "Gothic_7":
			dialog.text = "Тем не менее, примите от меня скромное вознаграждение.\n"+
				          "И черт возьми, вы уж оставьте меня одного, мне сейчас не до административных вопросов. Заходите через некоторое время...";
			link.l1 = "Хорошо, Ли. Обязательно буду позже...";
               link.l1.go = "exit";
               pchar.questTemp.GothicLee = "empty";
               SaveCurrentQuestDateParam("questTemp");
              CloseQuestHeader("GothicLee_TakeAnna");
              TakeItemFromCharacter(pchar, "letter_open");
              BackItemDescribe("letter_open");
              AddMoneyToCharacter(pchar, 25000);
              sld = characterFromId("AnnaDeLeiva");
              RemovePassenger(pchar, sld);
               DeleteAttribute(sld, "RebirthPhantom");
               sld.LifeDay = 0; // уберем нпс
               DoQuestFunctionDelay("GothicLee_townhall_room", 15.0);
               pchar.questTemp.GothicLee = "AnnaIsLife"; //но оставим флаг на второй квест
               AddTitleNextRate(sti(NPChar.nation), 3);
               ChangeCharacterComplexReputation(pchar, "nobility", 5);
               ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
              AddCharacterExpToSkill(pchar, "Leadership", 150);
              AddCharacterExpToSkill(pchar, "Repair", 200);
              AddCharacterExpToSkill(pchar, "Sailing", 150);
              AddCharacterExpToSkill(pchar, "Repair", 250);

                     // Посылка для Сагитты начало
                     pchar.questTemp.GothicThekla = "UneasySagitta";

			//слухи
			AddSimpleRumour("Ходят слухи, что именно капитан " + GetFullName(pchar) + " проявил"+ GetSexPhrase("","а") +" чудеса храбрости и находчивости, и сумел"+ GetSexPhrase("","а") +" доставить сюда испанскую пассию Генерала Ли - донну Анну...", FRANCE, 5, 1);
		break;

        //********************** Квест донны Анны ************************

        case "GothicLeeAnnaHant_GoodWork":
                    dialog.text = "Ты как всегда на высоте, я начинаю думать, что нет такого дела, которое ты не смог бы выполнить. Вот возми награду, и донна де Лейва хочет тебя лично поблагодарить.";
                    link.l1 = "Спасибо, Генерал Ли...";
                    link.l1.go = "exit";
	LocatorReloadEnterDisable("SantLous_townhall", "reload2", false);
	DeleteAttribute(&locations[FindLocation("Mayak10")], "DisableEncounters"); //откроем энканутеры
	pchar.questTemp.GothicLee = "empty";
	SaveCurrentQuestDateParam("questTemp");
                     SetTimerCondition("GothicLee_SeekBible", 0, 0, 2, false);				
	CloseQuestHeader("GothicLee_2_KillAnnaHanters");
	AddMoneyToCharacter(pchar, 15000);
        break;

        //********************** Квест, Поиски Евангелие для Аарона ************************

        case "Gothic_SeekBible":
            PlaySound("VOICE\Russian\GOTHIC\GG_\.wav");
            dialog.text = "";
            link.l1 = "Чем я еще могу помочь?";
            link.l1.go = "Gothic_SeekBible1";
        break;

        case "Gothic_SeekBible1":
            PlaySound("VOICE\Russian\gotica\LEE\DIA_LEE_01.wav");
            dialog.text = "Ха, я так и знал, тебе всюду нужно сунуть нос!";
            link.l1 = "И.";
            link.l1.go = "Gothic_SeekBible02";
        break;

        case "Gothic_SeekBible02":
            PlaySound("VOICE\Russian\GOTHIC\GG\GG_I_1.wav");
            dialog.text = "";
            link.l1 = "И....";
            link.l1.go = "Gothic_SeekBible2";
        break;

        case "Gothic_SeekBible2":
                                dialog.text = "У меня к тебе личная просьба. Мой друг, глава общины янсенистов Ямайки, просит командировать к нему сметливого человека. Лучше твоей кандидатуры у меня никого нет. Просьба его заключается в поиске чего-то, очень ему нужного. В общем, Аарон расскажет тебе все сам, он сейчас в своем доме, навести его. Обретается он в Форт Оранже, его дом между недалеко от таверны и местной верфи.";
                                link.l1 = "Я понял"+ GetSexPhrase("","а") +", Ли. Немедленно отправлюсь к нему.";
                                link.l1.go = "exit";
                                pchar.questTemp.GothicLee = "SeekBible_toAaron";
                                AddQuestRecord("GothicLee_3_SeekBible", "1");
	              AddQuestUserData("GothicLee_3_SeekBible", "sSex", GetSexPhrase("","а"));
                                SaveCurrentQuestDateParam("questTemp");
	              sld = characterFromId("Chumakeiro");
	              LAi_SetSitTypeNoGroup(sld);
                   ChangeCharacterAddressGroup(sld, "Aaron_House", "sit", "sit1");
        break;

        case "Gothic_3_1":
            dialog.text = "Но этого оказалось недостаточно. Я поражен твоим провалом, ты не смог выполнить простейшего задания. Ну что же, заглядывайте ко мне время от времени, возможно, я смогу подобрать для тебя то, что будет тебе по силам.";
            link.l1 = "Хорошо, Ли.";
            link.l1.go = "exit";
            CloseQuestHeader("GothicLee_3_SeekBible");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("GothicLee_Gorn", 0, 0, 14, false);
            pchar.questTemp.Waiting_time = "30";
			ChangeCharacterComplexReputation(pchar, "nobility", -2);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -260);
			AddCharacterExpToSkill(pchar, "Cannons", -300);
			AddCharacterExpToSkill(pchar, "FencingL", -270);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -250);
 			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " взял"+ GetSexPhrase("ся","ась") +" за выполнения необычного задания - поиски какого-то загадочного библейского трактата. Взял"+ GetSexPhrase("ся","ась") +", но не сделал"+ GetSexPhrase("","а") +"...", HOLLAND, 5, 1);
		break;

        case "Gothic_3_2":
            dialog.text = "А-а-а, вот он что... Ну что же, прекрасно. Надеюсь, он отблагодарил тебя должным образом?";
            link.l1 = "Более чем, Генерал Ли.";
            link.l1.go = "Gothic_3_3";
        break;
        case "Gothic_3_3":
            dialog.text = "Великолепно. Пожалуй, с этим все. Ты пока мне не нужен, можете заниматься своими делами. А вот через пару недель прошу заглянуть ко мне, наверняка у меня будет для тебя новое задание.";
            link.l1 = "Всегда к вашим услугам, Ли.";
            link.l1.go = "exit";
            CloseQuestHeader("GothicLee_3_SeekBible");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("GothicLee_Gorn", 0, 0, 14, false);
			ChangeCharacterComplexReputation(pchar, "nobility", 4);
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 270);
			AddCharacterExpToSkill(pchar, "Sneak", 260);
			AddCharacterExpToSkill(pchar, "Cannons", 300);
			AddCharacterExpToSkill(pchar, "FencingL", 270);
			AddCharacterExpToSkill(pchar, "FencingH", 230);
			AddCharacterExpToSkill(pchar, "FencingS", 250);

                                                           // Мистер и Миссис Смит начало
                                                           pchar.questTemp.GothicSmithy = "SagittaAnn";
 			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " взялся за выполнения необычного задания - поиски какого-то загадочного библейского трактата. И говорят, что нашел.", HOLLAND, 5, 1);
        break;

        //********************** Квест. Вызволение из тюрьмы Горна ************************	
		case "Gothic_5_1":
            PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_2.wav");
            dialog.text = "";
            link.l1 = "Что произошло за последнее время?";
            link.l1.go = "Gothic_5_01";
        break;

		case "Gothic_5_01":
            dialog.text = "К испанцам в лапы попал Горн. Милости ему ждать не приходится, поскольку он преизрядно пощипал испанцев. Разумеется, прежде чем познакомить Горна с конопляной тетушкой, они захотят выяснить, где он припрятал отобранное у них золото. Но это даже не самое главное.";
			link.l1 = "Золото - не главное?! А что же тогда?";
            link.l1.go = "Gothic_5_2";
        break;
		case "Gothic_5_2":
            dialog.text = "Святые отцы инквизиции умеют развязывать языки, и я опасаюсь, что Горн расскажет не только про золото...";
			link.l1 = "... но и про дела, которые, как я полагаю, делаю твоими силами...";
            link.l1.go = "Gothic_5_3";
        break;
		case "Gothic_5_3":
            dialog.text = "Совершенно верно. Так что вы понимаете: действовать нужно без промедления. Мне донесли, что Горна отправили в Сантьяго. Вы должны пробраться туда как можно быстрее и вытащить его из плена любой ценой. Я хочу, чтобы Горн был здесь, и по возможности живой и здоровый.";
			link.l1 = "Но если он погибнет...";
            link.l1.go = "Gothic_5_4";
        break;
		case "Gothic_5_4":
            dialog.text = "Тогда испанцы ничего не узнают, но не узнаем и мы. А у меня есть основания полагать, что Горн в благодарность за спасение предоставит во владение правительству некоторую часть своих сокровищ...";
			link.l1 = "Задание непростое, но как раз по мне! Я отправляюсь немедленно.";
            link.l1.go = "Gothic_5_5";
        break;
		case "Gothic_5_5":
            dialog.text = "Очень хорошо. И еще - в городе вам необходимо действовать скрытно, по возможности не поднимая тревоги. Для этого я вновь даю вам верительную грамоту Голландской Вест-Индской торговой компании.";
			link.l1 = "Огромное спасибо, Генерал Ли.";
            link.l1.go = "exit";
			LAi_group_Delete("PeaceGroup");
			GiveNationLicence(HOLLAND, 60);

    		pchar.questTemp.GothicLee = "RockBras_toSeekPlace";
            AddQuestRecord("GothicLee_5_RockBras", "1");
			SaveCurrentQuestDateParam("questTemp");
			//==> Горна - в инквизицию. 
            sld = GetCharacter(NPC_GenerateCharacter("Gorn", "Gorn", "man", "man", 30, PIRATE, -1, false, "quest"));
			FantomMakeCoolFighter(sld, 30, 90, 90, "", "", "", 80);
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_2.c";
			sld.RebirthPhantom = true;
        	sld.name 	= "Горн";
        	sld.lastname 	= "";
			LAi_LoginInCaptureTown(sld, true);
			LAi_NoRebirthEnable(sld);
			LAi_SetLoginTime(sld, 0.0, 24.0);
			LAi_SetGroundSitType(sld);
			LAi_group_MoveCharacter(sld, "PeaceGroup");
			ChangeCharacterAddressGroup(sld, "Santiago_Incquisitio", "prison", "prison9");
        break;
		case "Gothic_5_6":
            dialog.text = "Хм, бесполезно в вашем исполнении, "+ GetSexPhrase("месье","мадемуазель") +". Не говорите за весь Новый Свет.\n"+
				          "Очень жаль, "+pchar.name+", что ты не сумел выполнить задания, очень жаль... Пожалуй, ты мне больше не нужен. Ты можешь заглядывать ко мне в резиденцию периодически, возможно, и для тебя найдется работа...";
			link.l1 = "Хорошо, Ли.";
            link.l1.go = "Gothic_5_exit";	
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -170);
			AddCharacterExpToSkill(pchar, "Defence", -130);
			AddCharacterExpToSkill(pchar, "Cannons", -150);
			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " не сумел"+ GetSexPhrase("","а") +" вытащить Горна из испанских застенков. Плохо, он был хорошим человеком...", FRANCE, 5, 1);
            pchar.questTemp.Waiting_time = "35";
        break;
		case "Gothic_5_7":
            dialog.text = "М-да, печально... Он был хорошим наёмником и настоящим человеком. Очень жаль.\n"+
				          "Ну что же, я полагаю, ты сделал все возможное для его спасения. Поэтому я приглашаю тебя быть у меня в резиденции через месяц - я найду для тебя новое дело.";
			link.l1 = "Хорошо, Ли, буду непременно.";
            link.l1.go = "Gothic_5_exit";
			AddTitleNextRate(sti(NPChar.nation), 1);
			ChangeCharacterComplexReputation(pchar, "nobility", 1);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 100);
			AddCharacterExpToSkill(pchar, "Defence", 100);
			AddCharacterExpToSkill(pchar, "Cannons", 100);
			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " не сумел"+ GetSexPhrase("","а") +" вытащить Горна из испанских застенков. Плохо, он был хорошим человеком...", FRANCE, 5, 1);
            pchar.questTemp.Waiting_time = "15";
        break;
		case "Gothic_5_exit":
                                                      pchar.questTemp.GothicLee = "empty";
                                                      SaveCurrentQuestDateParam("questTemp");
			SetTimerCondition("Gothic_Lee", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_5_RockBras");

                                                      sld = characterFromId("Gorn");
			DeleteAttribute(sld, "RebirthPhantom");
         	                                    sld.LifeDay = 0; // уберем нпс
			DialogExit();
                                                      break;
		case "Gothic_5_8":
            dialog.text = "Не скромничай, "+pchar.name+". Наградой за выполненную работу является 30 тысяч монет. Изволь получить.";
			link.l1 = "Спасибо, Ли...";
            link.l1.go = "Gothic_5_9";
        break;
		case "Gothic_5_9":
            dialog.text = "Я, как всегда, прошу тебя заглядывать в мою резиденцию время от времени, полагаю, что в ближайшее время ты будешь мне нужен.";
			link.l1 = "Хорошо, Ли, обязательно буду навещать тебя.";
            link.l1.go = "Gothic_5_Rock";
			AddMoneyToCharacter(pchar, 30000);
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
			SetTimerCondition("Gothic_Lee", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_5_RockBras");
	
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 200);
			AddCharacterExpToSkill(pchar, "Sneak", 300);
			AddCharacterExpToSkill(pchar, "Cannons", 250);
			AddCharacterExpToSkill(pchar, "Accuracy", 350);
			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " вытащил"+ GetSexPhrase("","а") +" Горна из испанских застенков. Радостная весть, скажу я вам, Горн здесь уважают.", FRANCE, 5, 1);
        break;
		case "Gothic_5_Rock":
			sld = characterFromId("Gorn");
			RemovePassenger(PChar, sld);
			LAi_SetActorType(sld);
			LAi_CharacterEnableDialog(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
			DialogExit();
        break;

        //********************** Квест. Встреча с тремя корсарами ************************
                            case "Gothic_6_1":
                                dialog.text = ""+pchar.name+", мне поступило распоряжение направить сметливого, исполнительного, верного и достаточно авторитетного наёмника в распоряжение морского интенданта Франции маркиза Бонрепо, который сейчас находится на Гваделупе. Твою кандидатуру я считаю достойной.";
								link.l1 = "Благодарю за доверие Ли. Но в чем заключается мое задание?";
                                link.l1.go = "Gothic_6_2";
                            break;	
		case "Gothic_6_2":
            dialog.text = "Пока только в том, чтобы как можно скорее явиться к маркизу. Подробности мне неизвестны, судя по всему, дело будет весьма секретным.";
			link.l1 = "Что ж, мне не в первой. Никаких проблем, я отправляюсь...";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "ThreeCorsairs_toBonrepo";
            AddQuestRecord("GothicLee_6_ThreeCorsairs", "1");
			//==> маркиз Бонрепо.
            sld = GetCharacter(NPC_GenerateCharacter("Bonrepo", "off_fra_6", "man", "man", 20, FRANCE, -1, false, "quest"));
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_1.c";
        	sld.name 	= "Маркиз";
        	sld.lastname 	= "Бонрепо";
			sld.greeting = "Gr_QuestMan";
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "BasTer_townhall", "goto", "governor1");
        break;

		case "Gothic_6_3":
            dialog.text = ""+pchar.name+", не все в этой жизни измеряется деньгами. Честь дворянина и уважение окружающих здесь не купить ни за какие деньги.";
			link.l1 = "Да, но я себя чувствую с этим титулом призраком Гамеза...";
            link.l1.go = "Gothic_6_4";
        break;
		case "Gothic_6_4":
            dialog.text = "Ну ты даёшь, с Гомезом давно покончено, тем более мы так далеко от дома. Так что пользуйся тем, что есть, ну а пока новых просьб к тебе у меня нет, но я буду рад, если ты будешь время от времени навещать меня - возможно, нам еще предстоят совместные дела!";
			link.l1 = "Хорошо, Ли. Я, как "+ GetSexPhrase("французский дворянин, барон","французская дворянка, баронесса") +", буду у бывать у вас в резиденции чаще. Помоему так говорят здесь вельможи?";
            link.l1.go = "exit";
            pchar.questTemp.GothicLee = "empty";
			pchar.questTemp.Waiting_time = "12";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("Gothic_Lee_SOLEYRU", 0, 1, 0, false);
			CloseQuestHeader("GothicLee_6_ThreeCorsairs");
			AddTitleNextRate(sti(NPChar.nation), 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			AddCharacterExpToSkill(pchar, "Sailing", 290);
			AddCharacterExpToSkill(pchar, "Leadership", -100);
			AddCharacterExpToSkill(pchar, "Commerce", 250);
			AddCharacterExpToSkill(pchar, "Pistol", 350);
			//слухи
			AddSimpleRumour("Говорят, что капитану " + GetMainCharacterNameDat() + " пожалован дворянский титул барон"+ GetSexPhrase("а","ессы") +"! Ну, дела...", FRANCE, 5, 1);
        break;

        //********************** Квест. Отбить нападение на Порт-о-Принс ************************
                            case "Gothic_7_1":
                                dialog.text = "Барон"+ GetSexPhrase("","есса") +", мне приказано назначить тебя командиром специального карательного морского корпуса и придать в твоё распоряжение линейный корабль 'Солей Руаяль'. Ваши следующие задачи будут состоять в военных действиях против Испании в рамках деволюционной войны. Первая задача - отбить нападение испанской эскадры на Порт-о-Принс.";
								link.l1 = "Хм, видимо испанцы хотят владеть Эспаньолой единолично...";
                                link.l1.go = "Gothic_7_21";
                            break;	
		case "Gothic_7_21":
            dialog.text = "Это так, барон"+ GetSexPhrase("","есса") +". Они уже напали на поселение буканьеров Ла-Вега, теперь, по всей видимости, очередь за Порт-о-Принсом.";
			link.l1 = "Я понял"+ GetSexPhrase("","а") +", Ли. Я могу приступать к выполнению задачи?";
            link.l1.go = "Gothic_7_11";
        break;
		case "Gothic_7_11":
            dialog.text = "В принципе, да. Однако, мне нужно довести до тебя следующее - 'Солей Руаяль' придается тебе в качестве усиления эскадры.\n"+
				          "Ты ни в коем случае не должен потерять этот корабль, это будет означать провал миссии. И ты не сможешь больше работать на французское правительство.";
			link.l1 = "Хм, ну что же, я приму все меры к тому, чтобы великолепный 'Солей Руаяль' серьезно не пострадал.";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "GuardPP_toPortPax";
            AddQuestRecord("GothicLee_7_GuardPortPax", "1");
sld = GetCharacter(NPC_GenerateCharacter("SoleiRoyalCaptain", "off_fra_4", "man", "man", 35, FRANCE, -1, true, "soldier"));
			sld.Ship.Type = CreateBaseShip(SHIP_SOLEYRU);
			sld.Ship.Name = "Солей Руаяль";
			SetBaseShipData(sld);
			ResetShipCannonsDamages(sld);
			SetCrewQuantityFull(sld);
			sld.ship.Crew.Morale = 80;
			sld.Ship.Crew.Exp.Sailors = 90;
			sld.Ship.Crew.Exp.Cannoners = 90;
			sld.Ship.Crew.Exp.Soldiers = 90;
			Fantom_SetBalls(sld, "pirate");	
			FantomMakeCoolFighter(sld, 35, 100, 100, BLADE_LONG, "pistol5", "cartridge", 100);	
	SetSelfSkill(sld, 80, 50, 90, 70, 100);
	SetShipSkill(sld, 100, 30, 70, 70, 95, 50, 80, 55, 70);
			sld.CompanionEnemyEnable = false;
			sld.Abordage.Enable = false; // НЕЛЬЗЯ!
			SetCompanionIndex(pchar, -1, sti(sld.index));
			SetShipRemovable(sld, false);
			sld.SuperShooter  = true;
			sld.SaveItemsForDead  = true; 
			sld.DontClearDead = true;
			sld.DontRansackCaptain = true;
			sld.AlwaysSandbankManeuver = true;
			sld.AnalizeShips = true;
			sld.CoolBrander = true;
			sld.GenQuest.CrewMaltaMode  = true;
			sld.Ship.Mode = "Malta";
			SetCharacterPerk(sld, "Doctor1"); 
			SetCharacterPerk(sld, "Doctor2");
			SetCharacterPerk(sld, "Doctor3");
			GiveItem2Character(sld, "pistol5");
			sld.equip.gun = "pistol5";
			GiveItem2Character(sld, "blade_19");
			sld.equip.blade = "blade_19";
			GiveItem2Character(sld, "spyglass3"); 
			EquipCharacterbyItem(sld, "spyglass3");
			GiveItem2Character(sld, "cirass1"); 
			EquipCharacterbyItem(sld, "cirass1"); 
			GiveItem2Character(sld, "bussol"); 
			EquipCharacterbyItem(sld, "bussol"); 
			LAi_SetCharacterUseBullet(sld, "bullet"); 
			TakeNItems(sld, "bullet", 50); 
			AddItems(sld, "gunpowder", 50); 
			TakeNItems(sld, "potion2", 5);
			SetCharacterPerk(sld, "Energaiser"); 
			SetCharacterPerk(sld, "BasicDefense"); 
			SetCharacterPerk(sld, "AdvancedDefense"); 
			SetCharacterPerk(sld, "ProfessionalDefense"); 
			SetCharacterPerk(sld, "Tireless"); 
			SetCharacterPerk(sld, "CriticalHit"); 
			SetCharacterPerk(sld, "Sliding"); 
			SetCharacterPerk(sld, "SwordplayProfessional"); 
			SetCharacterPerk(sld, "BladeDancer"); 
			SetCharacterPerk(sld, "Gunman"); 
			SetCharacterPerk(sld, "GunProfessional"); 
			SetCharacterPerk(sld, "Sniper");
			SetCharacterPerk(sld, "IronWill"); 
			SetCharacterPerk(sld, "ShipEscape"); 
			SetCharacterPerk(sld, "Troopers"); 
			SetCharacterPerk(sld, "MusketsShoot"); 
			SetCharacterPerk(sld, "CrewDamageUp"); 
			SetCharacterPerk(sld, "BasicCommerce"); 
			SetCharacterPerk(sld, "AdvancedCommerce"); 
			SetCharacterPerk(sld, "HullDamageUp"); 
			SetCharacterPerk(sld, "SailsDamageUp"); 
			SetCharacterPerk(sld, "CriticalShoot"); 
			SetCharacterPerk(sld, "Carpenter"); 
			SetCharacterPerk(sld, "LightRepair"); 
			SetCharacterPerk(sld, "StormProfessional"); 
			SetCharacterPerk(sld, "WindCatcher"); 
			SetCharacterPerk(sld, "SailsMan"); 
			SetCharacterPerk(sld, "ShipSpeedUp"); 
			SetCharacterPerk(sld, "ShipTurnRateUp"); 
			pchar.TempPerks.QuestTroopers = true; //перк квестового десанта
			SetTimerCondition("GuardPP_Late", 0, 0, 25, false);
            Pchar.quest.GuardPP_Fight.win_condition.l1 = "location";
            Pchar.quest.GuardPP_Fight.win_condition.l1.location = "Hispaniola2";
            Pchar.quest.GuardPP_Fight.win_condition = "GuardPP_Fight";
        break;
		case "Gothic_7_2":
            dialog.text = "Верно, барон"+ GetSexPhrase("","есса") +", и выполнена блестяще. Французское правительство предусмотрело определенную сумму на ремонт кораблей и пополнение личного состава - 1 тысячу дублонов... Извольте получить.";
			link.l1 = "Всего 1 тысячу?! Каррамба, это меньше, чем ничего!";
            link.l1.go = "Gothic_7_3";
        break;
		case "Gothic_7_3":
            dialog.text = "Барон"+ GetSexPhrase("","есса") +", эта война требует от всех нас максимально напряжения сил. Я прошу тебя понять ситуацию - денег катастрофически не хватает. Поэтому прошу тебя принять сложившуюся ситуацию как данность.\n"+
				          "Сейчас я вас задерживать не смею - подготовьтесь к очередным боевым действиям. И помни - ты нужен Франции!";
			link.l1 = "Гм, ну что же, если я так нуж"+ GetSexPhrase("ен","на") +" Франции - она меня получит. Буду у вас в резиденции после того, как приведу в порядок свои дела, генерал. До свидания.";
            link.l1.go = "exit";
			Log_Info("Вы получили 1000 дублонов");
			TakeNItems(pchar, "gold_dublon", 1000);
			PlaySound("interface\important_item.wav");
                                                      pchar.questTemp.GothicLee = "empty";
			pchar.questTemp.Waiting_time = "18";
                                                      SaveCurrentQuestDateParam("questTemp");
                                                      SetTimerCondition("Gothic_Lee_OccupySantoDomingo", 0, 0, 5, false);
			CloseQuestHeader("GothicLee_7_GuardPortPax");
			AddTitleNextRate(sti(NPChar.nation), 2);
			ChangeCharacterComplexReputation(pchar, "nobility", 7);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Repair", 270);
			AddCharacterExpToSkill(pchar, "Sneak", 260);
			AddCharacterExpToSkill(pchar, "Cannons", 300);
			AddCharacterExpToSkill(pchar, "FencingL", 270);
			AddCharacterExpToSkill(pchar, "FencingH", 230);
			AddCharacterExpToSkill(pchar, "FencingS", 250);
			//слухи
			AddSimpleRumour("Говорят, что капитан " + GetFullName(pchar) + " спас"+ GetSexPhrase("","ла") +" жителей Порт-о-Принс от испанцев!", FRANCE, 5, 1);
        break;
		case "Gothic_7_4":
            dialog.text = "Но ты потерял 'Солей Руаяль', "+pchar.name+", и этому нет оправдания!";
			link.l1 = "Я сделал"+ GetSexPhrase("","а") +" все, что было в моих силах...";
            link.l1.go = "Gothic_7_5";
        break;
		case "Gothic_7_5":
            dialog.text = "Ты сделал недостаточно! В общем, потеря такого корабля привела к тому, что Франция отказывается от ваших услуг, "+pchar.name+".";
			link.l1 = "И это после всего, что я сделал"+ GetSexPhrase("","а") +" для Франции?! Бывай, Ли, мне и само"+ GetSexPhrase("му","й") +" все это уже изрядно надоело...";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "QuestLineBreake";
			bWorldAlivePause   = true; // Конец линейки
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//слухи
			AddSimpleRumour("Ходят слухи, что наш Генерал Ли выставил вас из резиденции за то, что вы умудрились утопить 'Солей Руаяль'. Хех, поделом...", FRANCE, 5, 1);
        break;
		case "Gothic_7_6":
            dialog.text = "Черт возьми, да вы просто "+ GetSexPhrase("форменный трус","трусливая девчонка") +"! Я не желаю иметь с тобой ничего общего. Прощай, барон"+ GetSexPhrase("","есса") +"...";
			link.l1 = "Прощай, Ли, мой пламенный привет маркизу Бонрепо...";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "QuestLineBreake";
			bWorldAlivePause   = true; // Конец линейки
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			ChangeCharacterReputation(pchar, -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//слухи
			AddSimpleRumour("Ходят слухи, что наш Генерал Ли выставил вас из резиденции за то, что вы бросили в бою 'Солей Руаяль'. Хех, поделом...", FRANCE, 5, 1);
        break;
		case "Gothic_7_7":
            dialog.text = "Дьявол, как же так?! Здесь десять дней ходу!! В общем так, я не желаю иметь с тобой ничего общего. Прощай, барон"+ GetSexPhrase("","есса") +"...";
			link.l1 = "Прощай, Ли, мой пламенный привет маркизу Бонрепо...";
            link.l1.go = "exit";
			sld = characterFromId("SoleiRoyalCaptain");
			RemoveCharacterCompanion(pchar, sld);
			sld.LifeDay = 0;
			pchar.questTemp.GothicLee = "QuestLineBreake";
			CloseQuestHeader("GothicLee_7_GuardPortPax");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			bWorldAlivePause   = true; // Конец линейки
			CloseQuestHeader("GothicLee_7_GuardPortPax");
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -2);
			AddCharacterExpToSkill(pchar, "Repair", -270);
			AddCharacterExpToSkill(pchar, "Sneak", -200);
			AddCharacterExpToSkill(pchar, "FencingL", -230);
			AddCharacterExpToSkill(pchar, "FencingH", -230);
			AddCharacterExpToSkill(pchar, "FencingS", -230);
			//слухи
			AddSimpleRumour("Ходят слухи, что Генерал Ли выставил вас из резиденции за то, что вы не сумели вовремя прибыть к Порт-о-Принсу и город был разорен испанцами. Поделом вам!", FRANCE, 5, 1);
        break;

        //********************** Квест. Захват Санто-Доминго ************************	
                            case "Gothic_10_0":
                                dialog.text = "Так, барон"+ GetSexPhrase("","есса") +", я рад тебя видеть. Вы как нельзя вовремя!";
								link.l1 = "Я слушаю тебя, Ли.";
                                link.l1.go = "Gothic_10_1";
                            break;	
	
		case "Gothic_10_1":
            dialog.text = "Настало время дать адекватный ответ на попытку захвата Порт-о-Принса. И, как мне кажется, лучшим ответом будет воплощение испанского плана захвата Эспаньолы, только в зеркальном отображении...";
			link.l1 = "Генерал Ли, прошу тебя говори менее витиевато.";
            link.l1.go = "Gothic_10_2";
        break;
		case "Gothic_10_2":
            dialog.text = "Хорошо, барон"+ GetSexPhrase("","есса") +". Итак, я поручаю тебе захватить Санто-Доминго! Таким образом, вся Эспаньола будет принадлежать целиком одной державе, но не Испании, а Франции. Теперь понятно?";
			link.l1 = "Понятно, Ли. Скажи, как насчет оплаты данной военной операции? Я не могу содержать 'Солей Руаяль' и вести войну за свой счет!";
            link.l1.go = "Gothic_10_3";
        break;
		case "Gothic_10_3":
            dialog.text = "Да, я понимаю. Вопрос по сути своей решен - после захвата Санто-Доминго ты получишь очень весомое вознаграждение.";
			link.l1 = "Ну что же, Ли, я верю вам. Итак, я приступаю к операции, ждите меня с хорошими новостями.";
            link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "OccupySD_toSantoDomingo";
            AddQuestRecord("GothicLee_10_OccupySantoDomingo", "1");
			CloseQuestHeader("GothicLee_12_EndOfWar");
            DeleteAttribute(pchar, "questTemp.Waiting_time");
			characters[GetCharacterIndex("SantoDomingo_Mayor")].dialog.captureNode = "Quest_OccupySD"; //капитулянтская нода мэра
        break;
		case "Gothic_10_4":
            dialog.text = "Ты потерял 'Солей Руаяль'!!";
			link.l1 = "Битва была жаркой, Генерал Ли, корабль-красавец действительно пошел на дно. Мне очень жаль...";
            link.l1.go = "Gothic_10_5";
        break;
		case "Gothic_10_5":
            dialog.text = "Твои сожаления мне не нужны. Потеря данного корабля - ужасная трагедия для Франции. Поэтому я больше не хочу иметь с тобой дел, французское правительство более не поручит вам ничего. Прощайте.";
			link.l1 = "Хм, как знаешь, Ли...";
            link.l1.go = "exit";
			CloseQuestHeader("GothicLee_10_OccupySantoDomingo");
			pchar.questTemp.GothicLee = "QuestLineBreake";
			CloseQuestHeader("GothicLee_12_EndOfWar");
                                                DeleteAttribute(pchar, "questTemp.Waiting_time");
			bWorldAlivePause   = true; // Конец линейки
			ChangeCharacterComplexReputation(pchar, "nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), -1);
			AddCharacterExpToSkill(pchar, "Repair", -170);
			AddCharacterExpToSkill(pchar, "Sneak", -100);
			AddCharacterExpToSkill(pchar, "FencingL", -130);
			AddCharacterExpToSkill(pchar, "FencingH", -130);
			AddCharacterExpToSkill(pchar, "FencingS", -130);
			//слухи
			AddSimpleRumour("Ходят слухи, что наш Генерал Ли выставил вас из резиденции за то, что вы умудрились утопить 'Солей Руаяль'. Хех, поделом...", FRANCE, 5, 1);
        break;
		case "Gothic_10_6":
            dialog.text = "Прекрасно, "+ GetSexPhrase("друг мой","мадемуазель") +", просто великолепно!\n"+
				          "Теперь о теме, очень важной для тебя - о вознаграждении. Я сумел выбить из бюджета на финансирование вашей экспедиции неслыханную сумму - 4 тысячи золотых дублонов... Они ваши, барон"+ GetSexPhrase("","есса") +"!";
			link.l1 = "Отлично, Генерал Ли. Уже гораздо лучше!";
            link.l1.go = "Gothic_10_7";
        break;
		case "Gothic_10_7":
            dialog.text = "Я очень рад, что ты довольный... Ну что же, задерживать тебя я не смею более, прошу тебя заняться подготовкой к другому делу. Приведи в порядок свою эскадру и будь у меня примерно через неделю, барон"+ GetSexPhrase("","есса") +".";
			link.l1 = "Хорошо, Генерал Ли, буду в означенные сроки.";
            link.l1.go = "exit";
            Log_Info("Вы получили 4000 дублонов");
           TakeNItems(pchar, "gold_dublon", 4000);
            PlaySound("interface\important_item.wav");
            pchar.questTemp.GothicLee = "empty";
            SaveCurrentQuestDateParam("questTemp");
            SetTimerCondition("Gothic_Lee_EndOfWar", 0, 0, 5, false);
			CloseQuestHeader("GothicLee_10_OccupySantoDomingo");
			AddTitleNextRate(sti(NPChar.nation), 3);
			ChangeCharacterComplexReputation(pchar, "nobility", 10);
			ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 1);
			AddCharacterExpToSkill(pchar, "Pistol", 330);
			AddCharacterExpToSkill(pchar, "Fortune", 360);
			AddCharacterExpToSkill(pchar, "Accuracy", 320);
			AddCharacterExpToSkill(pchar, "Grappling", 350);
			AddCharacterExpToSkill(pchar, "Defence", 350);
			//слухи
			AddSimpleRumour("Говорят, что вы захватили Санто-Доминго! Прекрасная работа, капитан, просто великолепная!", FRANCE, 5, 1);
        break;

        //********************** Квест №12. Завершение линейки ************************
		case "Gothic_12_1":
            dialog.text = "Мои поздравления, барон! Деволюционная война с Испанией окончена! Людовик Великий и вся Франция празднуют побнду! Ты также внес вклад в эту победу. По сути дела, именно ты обеспечил решительный разгром сил испанцев в Карибском море.\n"+
				          "Жан-Барист Кольбер отметил твои удачные действия на докладе в Лувре, твоё имя теперь известно самому Людовику XIV!";
			link.l1 = "Я очень и очень рад"+ GetSexPhrase("","а") +". Скажи, Ли, а денежных поощрений по итогам войны не предусмотрено?";
            link.l1.go = "Gothic_12_2";
        break;
		case "Gothic_12_2":
            dialog.text = "Об этом мне ничего не известно. Впрочем, ты можешь задать этот вопрос маркизу Бонрепо. Твоё следующее задние - добраться до Бас-Тера, что на Гваделупе, и встретиться там с маркизом. Он ожидает тебя.";
			link.l1 = "Отлично, Ли! Этого шанса я не упущу... Я выступаю немедленно.";
            link.l1.go = "Gothic_12_3";
        break;
		case "Gothic_12_3":
            dialog.text = "И приведи в порядок 'Солей Руаяль', он должен быть в полной боевой готовости.";
			link.l1 = "Хорошо, Ли.";
            link.l1.go = "exit";
			pchar.questTemp.GothicLee = "EndWar_toBorepo";
			AddQuestRecord("GothicLee_12_EndOfWar", "1");
			//==> маркиз Бонрепо.
            sld = GetCharacter(NPC_GenerateCharacter("Bonrepo", "off_fra_6", "man", "man", 20, FRANCE, -1, false, "quest"));
            sld.Dialog.Filename    = "Gothic_Quest\GothicLine\Line_1.c";
        	sld.name 	= "Маркиз";
        	sld.lastname 	= "Бонрепо";
			LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			ChangeCharacterAddressGroup(sld, "BasTer_townhall", "goto", "governor1");
        break;


		// ============== Грабеж среди бела дня, попытка залезть в сундуки =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Грабеж среди бела дня!!! Это что же такое делается?! Ну, погоди, "+ GetSexPhrase("приятель","подруга") +"...", "Эй, ты чего это там копаешься?! Никак, вздумал"+ GetSexPhrase("","а") +" ограбить меня? Ну, тогда тебе конец...", "Постой, ты куда это полез"+ GetSexPhrase("","ла") +"? Да ты вор"+ GetSexPhrase("","овка") +", оказывается! Ну, считай, что ты приплыл"+ GetSexPhrase("","а") +", родн"+ GetSexPhrase("ой","ая") +"...");
			link.l1 = LinkRandPhrase("Дьявол!!", "Каррамба!!", "А-ать, черт!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("Пошел вон","Убирайся") +" отсюда!", "Вон из моего дома!");
			link.l1 = "Ай...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Тебе не стоит отвлекать меня от дела пустыми обращениями. Впредь результат может быть более плачевным...";
        			link.l1 = "Я понял"+ GetSexPhrase("","а") +".";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		
		case "AngryRepeat_2":
            dialog.text = RandPhraseSimple("Ты меня изрядно утомил"+ GetSexPhrase("","а") +", никакого общения.", "Я не хочу с тобой общаться, так что тебе лучше меня не беспокоить.");
			link.l1 = RandPhraseSimple("Ну как знаешь...", "Хм, ну что же...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Надеюсь, впредь ты не будешь утомлять меня пустыми разговорами, иначе мне придется тебя убить. Признаюсь, мне это будет очень неприятно.";
        			link.l1 = "Генерал Ли, ты можешь быть уверен - не буду...";
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
            DoReloadCharacterToLocation("SantLous_town","reload","reload10");
		break;
		// <<<<<<<<<<<<============= блок нод angry =============================
		case "SantLous_town":
            dialog.text = "Решить проблему? Да ты сам понимаешь, чего ты наворотил? В общем, принесешь мне миллион песо - я уговорю ребят, чтобы они забыли твои 'подвиги'. Нет - можешь катиться на все четыре стороны.";
			if (sti(Pchar.money) >= 1000000)
			{
				link.l1 = "Хорошо, я готов заплатить.";
				link.l1.go = "SantLous_town_pay";
			}
			link.l2 = "Я всё понял. Ухожу.";
			link.l2.go = "SantLous_town_exit";
		break;
		
		case "SantLous_town_exit":
			DialogExit();
            bDisableFastReload = true;//закрыть переход
			pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
			pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
			pchar.quest.pirate_in_town.function = "TownPirate_battle";
		break;
		
		case "SantLous_town_pay":
            dialog.text = "Вот и славно! Считай, что свою репутацию ты восстановил. Но впредь, я надеюсь, ты больше не будешь делать таких мерзостей.";
			link.l1 = "Не буду. Уж очень дорого они обходятся. Прощай...";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -1000000);
			pchar.GenQuest.Piratekill = 0;
		break;
	}
}


