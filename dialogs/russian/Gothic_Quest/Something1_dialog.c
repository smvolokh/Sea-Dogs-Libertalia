void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
//---------------------------------------------------------------------------------------------------------------------------
//	Джейн Квин
//---------------------------------------------------------------------------------------------------------------------------
		
		// Анри
		case "Anri_1":
			dialog.text = "Эй, " + GetSexPhrase("парень","красавица") + ", я вижу, ты лих" + GetSexPhrase("ой","ая") + " мал" + GetSexPhrase("ый","ая") + ". Хочу предложить тебе одно дельце, что скажешь?";
			link.l1 = "Сначала предложи, а потом, может, что и скажу.";
			link.l1.go = "Anri_2";
		break;
		
        case "Anri_2":
            dialog.text = "Хе, вот в чем дело: я разузнал, что Губернатор острова планирует кое-что перевезти в свою загородную виллу, смекаешь?";
            link.l1 = "Ты что же, хочешь, чтобы я напал" + GetSexPhrase("","а") + " на людей губернатора Гваделупы?! Ну, уж нет, без меня.";
            link.l2 = "Пожалуй, звучит интересно. Продолжай.";
            link.l1.go = "Anri_3";
            link.l2.go = "Anri_4";
        break;

        case "Anri_3":
            dialog.text = "Черт! Ты что, думаешь, теперь я тебя так и отпущу?!";
            link.l1 = "...";
            link.l1.go = "Exit";
            AddDialogExitQuest("AnriDeKozen_First_meet");
            NextDiag.TempNode = "arest_1";
        break;

        case "arest_1":
            dialog.text = "Врешь, каналья! Он хотел меня ограбить! Я защищался.";
            link.l1 = "Что?! Да у тебя и грабить нечего! И так все пропил, иначе не предлагал бы мне это гнусное дело!";
            link.l1.go = "Exit";
            NextDiag.TempNode = "arest_2";
        break;
        
        case "arest_2":
            dialog.text = "" + GetSexPhrase("Шакал","Шлюха") + "! Заткни свою глотку!!!";
            link.l1 = "...";
            link.l1.go = "Exit";
            NextDiag.TempNode = "arest_3";
        break;
        
        case "arest_3":
            dialog.text = "Проклятье! Гореть тебе в аду! Ты меня сдал" + GetSexPhrase("","а") + "!!! Но я еще доберусь до тебя, попомни мои слова!";
            link.l1 = "...";
            link.l1.go = "Exit";
        break;
		// Соглашаемся
        case "Anri_4":
            dialog.text = "А кое-что имеет большую ценность, хе хе... Вобщем, жду тебя за городскими воротами, я все точно разузнал, охрана никакая.";
            link.l1 = "Понял" + GetSexPhrase("","а") + ", скоро и я буду там.";
            link.l1.go = "Exit";
            NextDiag.TempNode = "Anri_work_1";
			AddDialogExitQuest("Anri_accept_first_propose");
        break;
        
        case "Anri_work_1":
            dialog.text = "А, это ты. Давай шевелись.";
            link.l1 = "Я готов" + GetSexPhrase("","а") + ". Пойдем.";
            link.l1.go = "Exit";
            AddDialogExitQuest("Anri_razboi_2");
        break;
        
        case "Anri_wounded":
            dialog.text = "Проклятье! Этот мешок с трухой успел смыться! Вот дьявол! Я ранен! Помоги мне подняться, этот жид сейчас позовет подмогу.";
            link.l1 = "Ну, уж нет. Так они нас обоих отделают. Мне не остается ничего другого, так что прощай. Не поминай лихом.";
            link.l1.go = "Anri_wounded_1";
        break;
        
        case "Anri_wounded_1":
            dialog.text = "Гореть тебе в аду! Но я еще доберусь до тебя, попомни мои слова!";
            link.l1 = "...";
            link.l1.go = "Exit";
            AddDialogExitQuest("Anri_razboi_6");
        break;
		
		// Встреча в будущем
        case "In_House_1":
               dialog.text = "Дьявол! " + pchar.name + ", это вы?! Что вы здесь делаете?! Как вы сюда попали?!";
               link.l1 = "Да, Анри, это именно я. Я вижу тебе удалось выкарабкаться из той переделки... Что ж, видимо придется закончить то, что начали французы.";
               link.l1.go = "In_House_2";
        break;
        
        case "In_House_2":
               dialog.text = "Хм... " + pchar.name + ", а ты не подумал" + GetSexPhrase("","а") + " о том, что с тобой будет если ты убьешь секретаря губернатора Тортуги? Да ты и шага ступить не сможешь, тебя повесят!";
               link.l1 = "А мне плевать!!! Я и не из таких ситуаций выпутывал" + GetSexPhrase("ся","ась") + ". Уж как-нибудь разберусь.";
               link.l1.go = "In_House_3";
        break;
        
        case "In_House_3":
               dialog.text = "Мда, похоже ты настроен" + GetSexPhrase("","а") + " решительно... Я предлагаю тебе сделку - ты мне жизнь, а я сделаю так, чтобы французские власти сняли с тебя все обвинения. Сам" + GetSexPhrase("","а") + " подумай, если ты меня убьешь, тебе ни за что не отмыться, да еще и моя смерть будет за тобой числиться. Что скажешь?";
               link.l1 = "А твои слова не лишены смысла. И как ты решишь мою проблему с властями?";
               link.l1.go = "In_House_4";
        break;
        
        case "In_House_4":
               dialog.text = "Я напишу тебе письмо, предъявив которое губернатору любой французской колонии, с тебя снимут все обвинения. Но прежде чем я его тебе отдам, ты долж" + GetSexPhrase("ен","на") + " привезти ко мне человека, который все это время проворачивал контрабандные дела от твоего имени.";
               link.l1 = "И каково настоящее имя этого человека? Где я могу его найти?";
               link.l1.go = "In_house_5";
        break;
        
        case "In_house_5":
               dialog.text = "Зовут его Марко Эдо. По моему поручению он сейчас каперствует между Барбадосом и Мартиникой.";
               link.l1 = "Хорошо, я найду этого человека. Только не вздумай выкинуть какой-нибудь фокус! В следующий раз я не стану с тобой вступать в переговоры, а пристрелю на месте.";
               link.l1.go = "Exit";
               AddDialogExitQuest("J_Jozeph_Clain");
               NextDiag.TempNode = "Jozeph";
        break;
        
        case "Jozeph":
               dialog.text = "Марко все еще не у тебя, " +pchar.name+ "?";
               link.l1 = "Нет, пока я его не нашел" + GetSexPhrase("","а") + "...";
               link.l1.go = "Exit";
               NextDiag.TempNode = "Jozeph";
        break;

        case "Jozeph_1":
               dialog.text = "Приветствую тебя, " + pchar.name + ". Твои люди уже привели ко мне Марко. Но, как видишь, ситуация в корне изменилась - у меня в руках твоя знакомая. Так что теперь я собираюсь сдать тебя местному губернатору, как преступни" + GetSexPhrase("ка","цу") + " и контрабандист" + GetSexPhrase("а","ку") + ", а твою подругу, как тво" + GetSexPhrase("его","ю") + " соучастни" + GetSexPhrase("ка","цу") + "! Думаю губернатору будет приятно отправить на виселицу участницу налета на Порт-о-Пренс.";
               link.l1 = "Дьявол! Зря я не прикончил" + GetSexPhrase("","а") + " тебя сразу!!!";
               link.l1.go = "Jozeph_2";
        break;
        
        case "Jozeph_2":
               dialog.text = pchar.name + ", не надо громких слов - 'если бы', 'да я'... У тебя был шанс, ты его упустил" + GetSexPhrase("","а") + ", у меня есть шанс - я его не упущу!";
               link.l1 = "...";
               link.l1.go = "Exit";
               AddDialogExitQuest("J_Final_in_room_1_2");
        break;

		// Солдат в таверне
		case "AnriSld":
			dialog.text = "Так-так, что это здесь происходит?! Отвечать по-порядку!";
			link.l1 = "Этот мерзавец на меня напал!";
			link.l1.go = "Exit";
			NextDiag.TempNode = "AnriSld2";
		break;
		
		case "AnriSld2":
		    dialog.text = "Так, а вот с этого места поподробнее!";
		    link.l1 = "...";
		    link.l1.go = "Exit";
		    NextDiag.TempNode = "AnriSld3";
        break;
            
        case "AnriSld3":
            dialog.text = "Взять этого негодяя. А вы ответите мне на несколько вопросов. О каком деле вы говорили?";
            link.l1 = "Этот человек - заговорщик. Он замышлял против губернатора, а точнее - хотел присвоить себе губернаторскую казну по дороге в его загородную виллу.";
            link.l1.go = "Exit";
            NextDiag.TempNode = "AnriSld4";
        break;
            
        case "AnriSld4":
            dialog.text = "Благодарю за содействие в поимке преступника. Вот ваша награда. Прощайте.";
            link.l1 = "...";
			link.l1.go = "Exit";
            AddMoneyToCharacter(pchar, 500);
			ChangeCharacterReputation(pchar, 1);
            SetQuestHeader("AnriDeKozen");
			AddQuestRecord("AnriDeKozen", "arest");
			CloseQuestHeader("AnriDeKozen");
        break;
		
		// Казначей губернатора
		case "Anri_bariga":
			dialog.text = "О Боже! Что это за люди? Немедленно разберитесь с этими проходимцами!!! Я позову подмогу.";
			link.l1 = "Нда, похоже сейчас будет жарко!";
			link.l1.go = "Exit";
		break;
		
//-------------------------------------------------------------------------------------------------------------------------------------------------------------		
		
		case "AlvaroPinto":
			dialog.text = "Тысяча чертей! Что тебе от меня надо?!";
			link.l1 = "Я привез тебе выкуп за Эрнандеса, сына торговца.";
			link.l1.go = "AlvaroPinto_1";
		break;
		
		case "AlvaroPinto_1":
		        dialog.text = "Ты от толстосума-торгаша? Привез мне мои 15 000 монет?";
		        link.l1 = "Черт возьми! А ты поразительно догадлив! Неужели до тебя наконец дошло?! Могу я видеть парня?";
		        link.l1.go = "AlvaroPinto_2";
		break;
		
		case "AlvaroPinto_2":
		        dialog.text = "Хы, ну и нудный ты, приятель. Эй, там! Приведите сюда парня!";
		        link.l1 = "...";
		        link.l1.go = "Exit";
		        NextDiag.TempNode = "AlvaroPinto_3";
		        AddDialogExitQuest("SaveErnandes_ErnandesWait");
		break;
		
		case "AlvaroPinto_3":
		        dialog.text = "Вот сын торговца. Могу я видеть свои пиастры?";
                        if(sti(pchar.money)>=15000)
                        {
                            link.l1 = "Парни, поднимайте сундук на борт!";
		            link.l1.go = "AlvaroPinto_4";
                        }
                        link.l2 = "Не так быстро! Сначала я выпущу тебе кишки. К оружию!";
                        link.l2.go = "Exit";
		break;
		
		case "AlvaroPinto_4":
                        if(rand(100)+sti(pchar.skill.sneak)/10 > 50)
                        {
                            dialog.text = "Так, золото вижу. Ты нас не обманул, забирай щенка.";
		            link.l1 = "...";
		            link.l1.go = "Exit";
		            AddDialogExitQuest("SaveErnandes_ErnandesWelcomeABoard");
                        }
                        else
                        {
                            dialog.text = "";
                            link.l1 = "";
                            link.l1.go = "";
                        }
		break;

// Боцман у Альваро Пинто
                case "AlvaroPinto_Bocman":
                        dialog.text = "А ты чего здесь забыл, приятель?";
                        link.l1 = "Скажи-ка мне вот что, ты случаем ничего не слышал о парне по имени Альваро Пинто?";
                        link.l1.go = "AlvaroPinto_Bocman1";
                break;
                
                case "AlvaroPinto_Bocman1":
                        dialog.text = "А что мне о нем слышать? Я боцман на его шлюпе 'Бонавентура', вон она болтается на якоре в бухте. Мы тут торчим уже больше месяца. Я с парнями был в городе, улаживал кое-какие дела в таверне, теперь жду, когда за нами придет шлюпка с корабля.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "";
                        AddDialogExitQuest("SaveErnandes_Self_Dialog_ToTheShip");
                break;
                
                case "AlvaroPinto_Sailor":
                        dialog.text = ""+GetCharacterFullName("AlvaroPinto_Bocman")+" ответит на все твои вопросы - он у нас главный.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "AlvaroPinto_Sailor";
                break;

// Моряк на корабле Альваро Пинто -->
                case "AlvaroPinto_Sailor1":
                        dialog.text = "Какого дьявола вы забыли на нашем корабле?";
                        link.l1 = "Я хочу переговорить с твоим капитаном.";
                        link.l1.go = "AlvaroPinto_Sailor2";
                break;
                
                case "AlvaroPinto_Sailor2":
                        dialog.text = "Зачем он вам понадобился?";
                        link.l1 = "Для моряка ты слишком много задаешь вопросов, будь ты у меня в команде, уже давно бы болтался на рее! Я привез капитану важное сообщение и не намерен тратить время на разговоры с салагами!";
                        link.l1.go = "AlvaroPinto_Sailor3";
                break;
                
                case "AlvaroPinto_Sailor3":
                        dialog.text = "Эй! Свит! Позови капитана. Тут какой-то мистер хочет с ним говорить.";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        AddDialogExitQuest("SaveErnandes_WaitAlvaro");
                break;
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Магис Фукс -->
                case "Magis_Fuks":
                        dialog.text = "Простите, вы случайно не ступили на берег с палубы шлюпа 'Буревестник', который бросил якорь в порту?";
                        link.l1 = "Мне жаль, но вы ошиблись, милейший. Кроме того, признаться, я даже и не припомню, чтоб в порту была подобная посудина.";
                        link.l1.go = "Magis_Fuks_1";
                break;
                
                case "Magis_Fuks_1":
                        dialog.text = "Вот беда. Скорее всего, вы правы, капитан. Прямо и в толк не возьму, куда эта калоша запропастилась? Придется видно поднабраться терпения и надеяться, что через пару дней это корыто все же войдет в порт...";
                        link.l1 = "Что ж желаю удачи и терпения.";
                        link.l2 = "Хм, раздери акуле брюхо! Позвольте полюбопытствовать, а на что вообще вам сдалась эта лоханка? Ведь в порту полно судов и посолиднее.";
                        
                        link.l1.go = "Magis_Fuks_Exit_Noquest";
                        link.l2.go = "Magis_Fuks_2";
                break;
                
                case "Magis_Fuks_Exit_Noquest":
                        AddDialogExitQuest("Magis_Fuks_Quest_Decline");
                        NextDiag.CurrentNode = "Magis_Fuks_NoQuest_NextTime";
                        DialogExit();
                break;
                
                case "Magis_Fuks_NoQuest_NextTime":
                        dialog.text = "Очень жаль, что такой капитан как вы отказали мне в помощи...";
                        link.l1 = "Ничего, думаю ты найдешь нужного тебе человека.";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_NoQuest_NextTime";
                break;
                
                case "Magis_Fuks_2":
                        dialog.text = "В том то и дело, что от своей непомерной жадности я страдаю уже вторую неделю. Вот ведь и дернуло меня заключить контракт на перевозку, сэкономив на найме судна. Дела мои последнее время идут не то чтобы очень, а тут неплохое дельце наклюнулось. Подыскал я покупателя, договорился о сроках поставки ему сахара, нашел продавца, а сам подрядился в посредники. И вот на тебе - все планы коту под хвост.";
                        link.l1 = "Так в чем же собственно дело? А понимаю, похоже, судно, зафрахтованное вами под доставку груза, исчезло со всем товаром?";
                        link.l1.go = "Magis_Fuks_3";
                break;

                case "Magis_Fuks_3":
                        dialog.text = "Я вижу, вас это веселит? А мне признаться не до смеха. Честное слово хоть на поиски кого посылай. Послушайте капитан, а ведь это неплохая мысль. Не согласитесь ли вы выяснить для меня судьбу этой злополучной посудины и поторопить ее капитана в порт назначения?";
                        link.l1 = "Хм, а вы хоть понимаете, чего это вам будет стоить, милейший?";
                        link.l1.go = "Magis_Fuks_4";
                break;
                
                case "Magis_Fuks_4":
                        dialog.text = "Безусловно, и уверяю, что за ваши услуги смогу щедро вас отблагодарить. Как насчет 5 000 золотом?";
                        link.l1 = "Да, проблемы... Оно и понятно - коммерция дело тонкое. Однако в данный момент ваше предложение и озвученная сумма вознаграждения не вписываются в мои планы, и я не могу вам помочь. Желаю удачи и хороших прибылей.";
                        link.l1.go = "Magis_Fuks_Exit_Noquest";
                        link.l2 = "Что же, за 5 000 я согласен ударить по рукам и взяться за поиски пропавшего судна.";
                        link.l2.go = "Magis_Fuks_5";
                break;
                
                case "Magis_Fuks_5":
                        dialog.text = "Вот и отлично, я рад, что мы смогли договориться о цене. А сейчас о деле. Итак, Клодт Виан выручив деньги с продажи товара должен был загрузиться в порту Форт де Франс и оттуда направиться прямо сюда. Возможно по пути обратно он попал в шторм или, не приведи Господь, на него напали пираты...";
                        link.l1 = "А почему вы так уверены, что Клодт Виан не решил обвести вас вокруг пальца и скрыться с грузом или деньгами?";
                        link.l1.go = "Magis_Fuks_6";
                break;
                
                case "Magis_Fuks_6":
                        dialog.text = "Совершенно исключено, он честный и уважаемый капитан, у которого в этих местах доброе имя. К тому же здесь живет его семья, которая также очень волнуется о главе семейства. Если с ним, с его кораблем, с грузом все в порядке, и вы сможете разыскать его - передайте ему, что я требую от адресата немедленного возвращения, а также выплатить вам с вырученных денег обещанную сумму вознаграждения. Прощайте, и желаю удачи!";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_AcceptQuest_NextTime";
                        AddDialogExitQuest("Magis_Fuks_AcceptQuest");
                break;
                
                case "Magis_Fuks_AcceptQuest_NextTime":
                        dialog.text = "Вам удалось разыскать Клодта Виана? Что с ним? Где мои деньги и мой товар?";
                        link.l1 = "Нет, к сожалению мне пока не удалось ничего узнать...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Magis_Fuks_AcceptQuest_NextTime";
                break;

// Клодт Виан -->
				case "Klodt_Vian":
					dialog.text = "Клодт, ик, Виан, к вашим услугам.";
					link.l1 = "Ну наконец-то!";
					link.l1.go = "Exit";
					NextDiag.TempNode = "Klodt_Vian_0";
					AddDialogExitQuest("Magis_Fuks_alc");
				break;
				
                case "Klodt_Vian_0":
                    dialog.text = "С-с-скаж-ж-ж-жите ка, ик, капи-и-и-итану Кло... Кло... Короче, мне - к-к-как там погодка, ик, снаруж-ж-жи, не штормит?";
                    link.l1 = "Я вижу, тебя штормит и вероятно не первый день. Позволь-ка полюбопытствовать, когда ты собираешься выполнить условия договора и доставить груз на Тортугу?  Кстати замечу, что  твоя семя также заждалась отца - того гляди начнут оплакивать кормильца, а вдова найдет ему замену.";
                    link.l1.go = "Klodt_Vian_1";
                break;

                case "Klodt_Vian_1":
                        dialog.text = "Акульи потроха! Ик, о ка-а-акой замене ты т-т-олкуешь, а? Уж, не о толстом ли, ик, Бэнджамине? И во-о-о-обще что тебе от меня, ик, нужно и отк-к-куда ты знаешь о грузе?";
                        link.l1 = "Меня прислал человек по имени Магис Фукс. Он, видишь ли, заждался в порту Тортуги. Да, что с тбой тут разговаривать?! Вот от него записка. Я надеюсь, ты еще в силах буквы-то прочесть?";
                        link.l1.go = "Klodt_Vian_2";
                break;
                
                case "Klodt_Vian_2":
                        dialog.text = "Письмо... Письмо... Какое, ик, письмо, что? Ах, да... Письмо... Ик, ну-ка, ну-ка, так-так... Эх... Подвел я, ик,  хо-о-о-рошего человека...";
                        link.l1 = "Ну?! Я жду!";
                        link.l1.go = "Klodt_Vian_3";
                break;

                case "Klodt_Vian_3":
                        dialog.text = "Ч-ч-ч-чего? Ах да, ик... С-с-секунду... Я пьян, ик, но я честный человек и привык, ик, признавать свои ошибки... Вот, на, твои деньги, ик. Благод-д-д-дарю, что нашел меня, ик.";
                        link.l1 = "Давай, не болей.";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Klodt_Vian_4";
                        AddDialogExitQuest("Magis_Fuks_exit_sit");
                break;
                
                case "Klodt_Vian_4":
                        dialog.text = "Еще одна круж-ж-жечка, ик, и я снимаюсь с якоря!";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "Klodt_Vian_4";
                break;
                
// Сэмюэль Картос -->
                case "Semuel_Kartos":
                    dialog.text = "У меня нет, ик, настроения ра-а-азговаривать.";
                    link.l1 = "Зато у меня есть. Имя "+GetFullName(CharacterFromID("Pirates_tavernkeeper"))+" тебе не о чем не говорит? Ты задолжал этому парню 3000 пиастров...";
                    link.l1.go = "Semuel_Kartos_1";
                break;
                
                case "Semuel_Kartos_1":
                    dialog.text = "А-а-а, этот, ик, скряга... И что? Ик, ты хо-о-очешь, чтоб-б-бы я отдал деньги?! У меня их, ик, нет!";
                    link.l1 = "Очень жаль, приятель, в таком случае мне прийдется перерезать тебе глотку.";
                    link.l2 = "Может ты все таки еще раз, хорошенько подумаешь? Хозяин таверны, скажу я тебе, настроен весьма решительно, по-поводу твоей персоны.";
                        
                    link.l1.go = "Semuel_Kartos_Kill";
                    link.l2.go = "Semuel_Kartos_2";
                break;
                
                case "Semuel_Kartos_2":
                    dialog.text = "Посмотри на меня, ик, па-а-арень... Откуда у меня, ик, деньги? Тем более 3000? А ведь я когда-то был, ик, боцманом на бригантине 'Северный ветер', а-а-а, ик, чтоб ее... На нас напали пираты, ик, в живых остались только я и несколько матросов. Потом нас продали испанцам на рудники, ик... Потом я, ик, сбежал... Потом я тут... Потом я, ик, а потом я... Ничего не помню...";
                    link.l1 = "Да уж, история... Ладно, пойду скажу тавренщику, чтобы кто-то другой лишал тебя жизни - я на такое дело подписываться не буду.";
                    link.l1.go = "Semuel_Kartos_No_Kill";
                break;
                
                case "Semuel_Kartos_No_Kill":
                    AddDialogExitQuest("Debt_Qust_No_Kill");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Payment":
                    dialog.text = "А-а-а, ик, опять ты...";
                    link.l1 = "Я заплатил за тебя долг, теперь ты ничего не должен.";
                    link.l1.go = "Semuel_Kartos_Payment_1";
                break;
                
                case "Semuel_Kartos_Payment_1":
                    dialog.text = "Ты, что?! Ты?!! Ты заплатил мой долг?!! Даже и не знаю, ик, что сказать... Я могу, ик, отработать у тебя...";
                    link.l1 = "Мне не нужны алкаши. Больше так не попадай. Удачи.";
                    link.l1.go = "Semuel_Kartos_Exit_No";
                    if (FindFreeRandomOfficer() > 0)
					{
						link.l2 = "Хм... Пожалуй я возьму тебя, только вот давай-ка тебе переоденем во что-то более свежее.";
						link.l2.go = "Semuel_Kartos_Exit_Yes";
					}
                break;
                
                case "Semuel_Kartos_Exit_No":
                    AddDialogExitQuest("DebtQuest_NoKill_NO");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Exit_Yes":
                    AddDialogExitQuest("DebtQuest_NoKill_YES");
                    dialogExit();
                break;
                
                case "Semuel_Kartos_Kill":
                    AddDialogExitQuest("DebtQuest_Kill");
                    dialogExit();
                break;
				
//////////////////////////////////////
//	тюремный эскорт
//////////////////////////////////////
		case "PrisonEscort_Officer":
			dialog.text = "Немедленно сдайте оружие! Пройдёмте с нами!";
			link.l1 = "Что случилось?!";
			link.l1.go = "PrisonEscort_Officer_1";
		break;
		
		case "PrisonEscort_Officer_1":
			dialog.text = "Оставить разговоры! Сдать оружие и следовать за мной! Иначе, я прикажу расстрелять тебя на месте!";
			link.l1 = "...";
			link.l1.go = "PrisonEscort_Officer_2";
		break;

		case "PrisonEscort_Officer_2":
			dialog.text = "Оставить разговоры! Сдать оружие и следовать за мной! Иначе, я прикажу расстрелять тебя на месте!";
			link.l1 = "...";
			link.l1.go = "Exit";
			DoQuestCheckDelay("PrisonEscort_ToPrison", 1.0);
		break;

// Тюремный эскорт (Эмилио Мово)		
		case "PrisonEscort_EmilioMovo":
	                                                PlaySound("VOICE\Russian\gotica\MATTEO\DIA_MATTEO_HALLO_09_00.wav");
			dialog.text = "Чем могу помочь!";
			link.l1 = "Тебе известно что-либо о нападениях на голландские корабли, перевозящие рабов и заключенных?";
			link.l1.go = "PrisonEscort_EmilioMovo_1";
		break;
		
		case "PrisonEscort_EmilioMovo_1":
			dialog.text = "Интересный вопрос... А что если и знаю?";
			link.l1 = "Что ты хочешь за свои услуги.";
			link.l1.go = "PrisonEscort_EmilioMovo_2";
		break;
		
		case "PrisonEscort_EmilioMovo_2":
	                                                PlaySound("VOICE\Russian\gotica\MATTEO\DIA_MATTEO_PRICEOFHELP_09_01.wav");
			dialog.text = "100 золотых монет!";
			link.l1 = "Идет! Выкладывай все что знаешь.";
			link.l1.go = "PrisonEscort_EmilioMovo_3";
		break;
		
		case "PrisonEscort_EmilioMovo_3":
			dialog.text = "Я работаю на заготовке провианта, а иногда приходится участвовать в его погрузке.\nТак вот, недавно в нашу бухту заходила шебека 'Вояджер' и пополнял запасы провианта и пресной воды.\nБоцман с шебеки заплатил мне и остальным по 10 песо за то, чтобы мы перевезли груз со склада на берег.\nМы выполнили то, что от нас требовалось, но он предложил нам еще по 5 песо, за то чтобы мы помогли морякам погрузить груз на шлюпки.\nВо время погрузки я слышал обрывки разговора между матросами - они обсуждали недавнюю добычу и, судя по всему, их добычей были рабы и заключенные.";
			link.l1 = "А как зовут капитана этой шебеки и куда они направились, не знаешь?";
			link.l1.go = "PrisonEscort_EmilioMovo_4";
		break;
		
		case "PrisonEscort_EmilioMovo_4":
			dialog.text = "Как зовут капитана - не знаю, а курс взяли на север. Теперь я бы хотел получить обещаные 100 дублонов.";
			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "Ты мне здорово помог. Держи свою награду.";
				link.l1.go = "Exit";
			}
			link.l2 = "Извини, но у меня сейчас определенные финансовые трудности и я не могу тебе дать обещанные деньги.";
			link.l2.go = "PrisonEscort_EmilioMovo_5";
			
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_7";
			AddDialogExitQuest("PrisonEscort_ToSea");
		break;
		
		case "PrisonEscort_EmilioMovo_5":
			ChangeCharacterComplexReputation(pchar, "nobility", -5);
			NextDiag.CurrentNode = "PrisonEscort_EmilioMovo_6";
			pchar.questTemp.PrisonEscort_quest = "Emilio_Movo_No_Money";
pchar.GenQuest.Piratekill = sti(pchar.GenQuest.Piratekill)+5;
			DialogExit();
		break;
		
		case "PrisonEscort_EmilioMovo_6":
			dialog.text = "Я не хочу говорить с таким человеком, как вы.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_6";
		break;
		
		case "PrisonEscort_EmilioMovo_7":
			dialog.text = "Я рассказал вам все что знал. Кстати, спасибо за награду.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "PrisonEscort_EmilioMovo_7";
		break;
		
		case "PrisonEscort_EmilioMovo_8":
			dialog.text = "Ребята, вот этот человек! Он обещал мне 100 дублонов и не заплатил!";
			link.l1 = "Е-моё...";
			link.l1.go = "PrisonEscort_EmilioMovo_9";
		break;

		case "PrisonEscort_EmilioMovo_9":
	                                                PlaySound("VOICE\Russian\gotica\DIRTYPIRATE_man\SVM_7_ADDON_DIRTYPIRATE.wav");
			dialog.text = "Умри презренный пират!!!";
			link.l1 = "";
			link.l1.go = "Exit";
		break;
/*                
// Контрабандист в квесте "Эксклюзивное вино" -->
                case "ExclusiveVineQuest_Smuggler":
                    dialog.text = "Тебе чего здесь надо, приятель?";
                    link.l1 = "Ой, извините, ошибся дверью.";
                    link.l1.go = "Exit";
                    link.l2 = "Я от парня по имени "+GetCharacterFullName("Bridgetown_tavernkeeper")+", ни чего не говорит вам это имя?";
                    link.l2.go = "ExclusiveVineQuest_Smuggler_1";
                        NextDiag.TempNode = "ExclusiveVineQuest_Smuggler";
                break;
                
                case "ExclusiveVineQuest_Smuggler_1":
                    dialog.text = "Отчего же, говорит. Я догадываюсь зачем ты здесь, но даю тебе шанс не делать глупостей. Проваливай, пока цел!";
                    link.l1 = "Я уйду, но сначала я выпущу тебе и твоим дружкам кишки!";
                    link.l1.go = "ExclusiveVineQuest_Smuggler_fight";
                    link.l2 = "А что, я пожалуй воспользуюсь твоим советом. Ладно, пора мне.";
                    link.l2.go = "Exit";
                        NextDiag.TempNode = "ExclusiveVineQuest_Smuggler";
                break;
                
                case "ExclusiveVineQuest_Smuggler_fight":
                        AddDialogExitQuest("ExclusiveVineQuest_fight_vs_smuggler");
                    dialogExit();
                break;
                
                case "ExclusiveVineQuest_Smuggler_2":
                    dialog.text = "Капитан, подождиите! Я отдам это проклятое вино! А если вы сохраните мне жизнь, то заплачу вам сверху 1000 пиастров. Пожалуйста, не убивайте!";
                    link.l1 = "1000 пиастров говоришь? Идет - твоя никчемная жизнь в обмен на 1000 звонких монет!";
                    link.l1.go = "ExclusiveVineQuest_Exit_NoKill";
                    link.l2 = "Ну уж нет, таким уродам как ты нельзя топтать нашу грешную землю!";
                    link.l2.go = "ExclusiveVineQuest_Exit_Kill";
                break;
                
                case "ExclusiveVineQuest_Exit_NoKill":
                        NextDiag.CurrentNode = "ExclusiveVineQuest_NoKill";
                        AddDialogExitQuest("ExclusiveVineQuest_go_away_1");
                    dialogExit();
                break;
                
                case "ExclusiveVineQuest_NoKill":
                    dialog.text = "Благодарю вас, капитан, что оставили меня в живых!";
                    link.l1 = "...";
                    link.l1.go = "Exit";
                        NextDiag.CurrentNode = "ExclusiveVineQuest_NoKill";
                break;
                
                case "ExclusiveVineQuest_Exit_Kill":
                        AddDialogExitQuest("ExclusiveVineQuest_go_away_2");
                    dialogExit();
                break;
                
// Портной -->
                case "TailorQuest_HugoGreen":
                    dialog.text = "А вы тоже, я вижу, собираетесь на сегодняшний прием?";
                    link.l1 = "Не понимаю вас, какой еще прием?";
                    link.l1.go = "TailorQuest_HugoGreen_1";
                break;
                
                case "TailorQuest_HugoGreen_1":
                    dialog.text = "Как же какой?! Конечно же на тот, который сегодня вечером изволит устраивать губернатор в честь совершеннолетия своего внука. ";
                    link.l1 = "Меня пока не пригласили.";
                    link.l1.go = "TailorQuest_HugoGreen_2";
                break;
                
                case "TailorQuest_HugoGreen_2":
                    dialog.text = "Быть может, губернатор просто еще не успел пригласить вас.";
                    link.l1 = "Возможно. А чем вы так озабочены, уважаемый?";
                    link.l1.go = "TailorQuest_HugoGreen_3";
                break;
                
                case "TailorQuest_HugoGreen_3":
                    dialog.text = "Дело в том, что моя супруга решила приобрести в честь этого приема новое платье...";
                    link.l1 = "Похвально, а в чем же собственно дело?";
                    link.l1.go = "TailorQuest_HugoGreen_4";
                break;
                
                case "TailorQuest_HugoGreen_4":
                    dialog.text = "А дело в том, что в нашем городе несколько великолепных портных. Так вот, моя супруга и вбила себе в голову - купить платье у лучшего из них. А вот как выбрать лучшего и убедить ее в том, что выбор верный? Загадка. Кроме того, из-за дел, которые на меня навалились в связи с предстоящим праздником, у меня нет времени бегать и узнавать кто лучше. Придется покупать на авось. Ох и чую - быть скандалу.";
                    link.l1 = "Что ж желаю удачи, дружище. Это приятные хлопоты. Прощай.";
                    link.l1.go = "Exit_TailorQuest_HugoGreen";
                    link.l2 = "Пожалуй, я бы мог вам помочь с этим, если вы конечно не возражаете.";
                    link.l2.go = "TailorQuest_HugoGreen_5";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                break;
                
                case "TailorQuest_HugoGreen_5":
                    dialog.text = "О, благодарю вас, вы очень добры! Признаться, я не смел и надеется...  Как только что-либо выясните - сообщите, пожалуйста. Я буду ждать вас здесь.";
                    link.l1 = "До встречи";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_start");
                break;
                
                case "TailorQuest_HugoGreen_SeconTime":
                    dialog.text = "С этими приготовлениями к празднику - одни хлопоты!";
                    link.l1 = "Не буду вас отвлекать.";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                break;
                
                case "TailorQuest_HugoGreen_Finish":
                    dialog.text = "А я вас уже заждался. Ну, как вам удалось выбрать лучшего мастера?";
                    link.l1 = "Хм. Ну, в принципе, да. Это Берг.";
                    link.l2 = "Хм. Ну, в принципе, да. Это Гэрри.";
                    link.l3 = "Хм. Ну, в принципе, да. Это Смитт.";
                    link.l4 = "Хм. Ну, в принципе, да. Это Рабинович.";
                        
                    link.l1.go = "TailorQuest_HugoGreen_6";
                    link.l2.go = "TailorQuest_HugoGreen_6";
                    link.l3.go = "TailorQuest_HugoGreen_6";
                    link.l4.go = "TailorQuest_HugoGreen_7";
                break;
                
                case "TailorQuest_HugoGreen_6":
                    dialog.text = "Думаете? Пожалуй, вы правы, а почему бы и нет? Что ж, благодарю вас за услугу и буду вспоминать вас добрым словом. Прощайте.";
                    link.l1 = "...";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_Finish_1");
                break;
                
                case "TailorQuest_HugoGreen_7":
                    dialog.text = "Ха, а почему именно он?";
                    link.l1 = "Ну, дело в том, что Рабинович лучший портной в этом городе, а поскольку все остальные тоже неплохи, но не претендуют на лавры лучшего именно здесь - то сами понимаете...";
                    link.l1.go = "TailorQuest_HugoGreen_8";
                break;
                
                case "TailorQuest_HugoGreen_8":
                    dialog.text = "А ведь вы правы и почему я раньше об этом не подумал?! Действительно, чаще всего мы ходим к Рабиновичу! Кто бы мог подумать  - а Рабинович то лучший! Благодарю, благодарю вас сердечно. Вот вам небольшой сувенир на память. Прощайте капитан, быть может, еще увидимся.";
                    link.l1 = "Всего хорошего.";
                    link.l1.go = "Exit";
                        NextDiag.TempNode = "TailorQuest_HugoGreen_SeconTime";
                        AddDialogExitQuest("TailorQuest_Finish_2");
                break;
                
                case "Exit_TailorQuest_HugoGreen":
                        AddDialogExitQuest("TailorQuest_END");
                        NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
                break;


//////////////////////////////		
// Офицер Винсент Венто		
//////////////////////////////

// Винсент Венто
		case "OfficerVinsentVento_Vento":
			dialog.text = "Вы что-то хотели?";
			link.l1 = "Чего нового у вас здесь в городе происходило в последнее время?";
			link.l1.go = "OfficerVinsentVento_Vento_1";
		break;
		
		case "OfficerVinsentVento_Vento_1":
			dialog.text = "Оставьте меня в покое, прошу вас.";
			link.l1 = "Как скажете, офицер.";
			link.l1.go = "Exit";
			link.l2 = "О каком покое вы говорите, офицер? Я уже давно заметил, как вы ходите кругами вокруг резиденции...";
			link.l2.go = "OfficerVinsentVento_Vento_2";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_1";
		break;
		
		case "OfficerVinsentVento_Vento_2":
			// if(GetReputationFromNation2Character(pchar, HOLLAND) < 60)
			// {
				// dialog.text = "Я непонятным языком выражаюсь?! ОСТАВЬТЕ МЕНЯ В ПОКОЕ!!!";
				// link.l1 = "...";
				// link.l1.go = "Exit";
				// NextDiag.TempNode = "OfficerVinsentVento_Vento_1";
			// }
			// else
			// {
				// dialog.text = "Неужели вы думаете, что я просто так, от нечего делать, хожу кругами?! Я потерял кое-что и никак не могу найти...";
				// link.l1 = "Вот как? И что же вы такого потеряли?";
				// link.l1.go = "OfficerVinsentVento_Vento_3";
			// }
		break;
		
		case "OfficerVinsentVento_Vento_3":
			dialog.text = "Пакет с очень важными документами.";
			link.l1 = "Я, конечно, дико извиняюсь, но пакет с документами - это не дамская брошка. Вы что, не видите? Вокруг нет ничего и приблизительно похожего на пакет с документами!";
			link.l1.go = "OfficerVinsentVento_Vento_4";
		break;
		
		case "OfficerVinsentVento_Vento_4":
			dialog.text = "Да вижу я! Но, черт возьми, они же БЫЛИ!";
			link.l1 = "Что же, желаю вам удачных поисков.";
			link.l1.go = "OfficerVinsentVento_Vento_ExitNoQuest";
			link.l2 = "Если вы расскажете, что за пакет и как он выглядел, я помогу вам - вдвоем-то все же легче искать.";
			link.l2.go = "OfficerVinsentVento_Vento_5";
		break;
		
		case "OfficerVinsentVento_Vento_5":
			dialog.text = "Помочь? Черт возьми, похоже, мне ничего другого не остается... Понимаете, у нас планируется усиление форта. Для этого, специально из Европы, привезли инженера. Он долго работал над чертежами новых построек форта, и вот, когда он уплыл, мне приказали нести чертежи, утвержденные нашими инженерами, на подпись к губернатору.";
			link.l1 = "...";
			link.l1.go = "OfficerVinsentVento_Vento_6";
		break;
		
		case "OfficerVinsentVento_Vento_6":
			dialog.text = "Вышел я из форта и направился в резиденцию. Жара на улице дикая, ну я и решил заглянуть в таверну, пропустить пару стаканчиков, а то вообще от жары язык к горлу присох. Ну, значит, вышел я из таверны и направился в резиденцию. Перед самым входом решил проверить, чтобы все документы были в порядке, открыл сумку и обомлел - пакета с документами НЕТ!!!";
			link.l1 = "Мда... Может ты забыл взять пакет?";
			link.l1.go = "OfficerVinsentVento_Vento_7";
		break;
		
		case "OfficerVinsentVento_Vento_7":
			dialog.text = "Да нет же! Я точно помню, как положил его в сумку, клянусь вам! Теперь меня на плантации продадут или повесят! Что делать?!";
			link.l1 = "Похоже, у вас их просто-напросто украли. Нечего было сидеть в таверне с такими важными документами!";
			link.l1.go = "OfficerVinsentVento_Vento_ExitNoQuest";
			link.l2 = "Держите себя в руках, ведь вы голландский офицер! Ладно, так уж и быть, попробую выяснить что-нибудь.";
			link.l2.go = "OfficerVinsentVento_Vento_ExitYesQuest";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_8";
		break;
		
		case "OfficerVinsentVento_Vento_8":
			dialog.text = "Вы узнали хоть что-нибудь о пропавших документах?";
			
			link.l1 = "Пока нет, но я работаю над этим вопросом.";
			link.l1.go = "Exit";
			
			if(pchar.OfficerVinsentVento_quest == "Bill")
			{
				link.l2 = "Да. Некто Бил вышел следом за вами из таверны.";
				link.l2.go = "OfficerVinsentVento_Vento_9";
			}
			if(CheckCharacterItem(pchar, "OfficerVinsentVento_Documents") || CheckCharacterItem(pchar, "OfficerVinsentVento_DocumentsCopy"))
			{
				link.l2 = "Да, мне удалось найти вашу пропажу. Их украл у вас один парень, но, уверяю вас, он уже получил свое.";
				link.l2.go = "OfficerVinsentVento_Vento_14";
			}
			
			NextDiag.TempNode = "OfficerVinsentVento_Vento_8";
		break;
		
		case "OfficerVinsentVento_Vento_9":
			dialog.text = "Кто такой этот Бил? И причем тут он?";
			link.l1 = "Бил - это боцман французского корсара Тревора д’Версера, он снял дом рядом с местным банком, ну? Вы все еще не сообразили, что к чему?!";
			link.l1.go = "OfficerVinsentVento_Vento_10";
		break;
		
		case "OfficerVinsentVento_Vento_10":
			dialog.text = "Черт возьми, да! Они теперь знают план форта! Надо их арестовать, немедленно!";
			link.l1 = "Возьмите солдат и идемте, навестим Била в его доме.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_11";
			AddDialogExitQuest("OfficerVinsentVento_ToBillHouseVsOfficer");
		break;
				
		case "OfficerVinsentVento_Vento_11":
			dialog.text = "Вы обвиняетесь в краже секретных документов!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_12";
		break;
		
		case "OfficerVinsentVento_Vento_12":
			dialog.text = "Обыскать дом!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_13";
		break;
		
		case "OfficerVinsentVento_Vento_13":
			dialog.text = "Да это же чертежи форта! Собака! Ты еще мне что-то мямлил! Под стражу его!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Vento_14";
		break;
		
		case "OfficerVinsentVento_Vento_14":
			dialog.text = "Капитан, вы оказали мне неоценимую услугу. Я не могу отблагодарить вас деньгами, но возьмите мой пистолет, хоть он и не из дорогих, но довольно надежный.";
			link.l1 = "Спасибо, но я не могу принять от вас этот подарок, да и дело-то было пустяковое.";
			link.l1.go = "OfficerVinsentVento_Vento_15";
			link.l2 = "Спасибо за подарок, и прошу вас, в следующий раз будьте внимательнее с секретными-то документами.";
			link.l2.go = "OfficerVinsentVento_Vento_16";
			AddDialogExitQuest("OfficerVinsentVento_Complette1");
		break;
		
		case "OfficerVinsentVento_Vento_15":
			pchar.OfficerVinsentVento_quest = "no_gun";
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_16":
		                 pchar.OfficerVinsentVento_quest = "gun";
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_ExitYesQuest":
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("OfficerVinsentVento_Start");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Vento_ExitNoQuest":
			AddDialogExitQuest("OfficerVinsentVento_NoQuest");
			DialogExit();
		break;

// Бил
		case "OfficerVinsentVento_Bill":
			dialog.text = "Чего тебе здесь надо?";
			link.l1 = "Извини, ошибся домом.";
			link.l1.go = "Exit";
			link.l2 = "Если я не ошибаюсь, Бил?";
			link.l2.go = "OfficerVinsentVento_Bill1_1";
			NextDiag.TempNode = "OfficerVinsentVento_Bill";
		break;
		
		case "OfficerVinsentVento_Bill1_1":
			dialog.text = "Допустим, и что тебе от меня надо?";
			link.l1 = "Ничего не слышал о пропаже чертежей форта?";
			link.l1.go = "OfficerVinsentVento_Bill1_2";
		break;
		
		case "OfficerVinsentVento_Bill1_2":
			dialog.text = "Какие чертежи? Ты кто такой?";
			link.l1 = "Я капитан "+GetCharacterFullName(pchar.id)+"! И если ты не отдашь мне чертежи по-хорошему, мне придется забрать их силой.";
			link.l1.go = "OfficerVinsentVento_Bill1_3";
		break;
		
		case "OfficerVinsentVento_Bill1_3":
			dialog.text = "Убирайся отсюда, пока цел!";
			link.l1 = "Убивать я тебя не стану, не охота портить себе репутацию, но ты еще пожалеешь о том, что не захотел отдать бумаги по-хорошему.";
			link.l1.go = "OfficerVinsentVento_Bill_ExitNoDocuments";
			link.l2 = "Что? Ты мне угрожаешь?! Ха! Много людей мне угрожали и ничем хорошим это для них не закончилось!";
			link.l2.go = "OfficerVinsentVento_Bill_FightVsBill";
		break;
		
		case "OfficerVinsentVento_Bill_ExitNoDocuments":
			NextDiag.CurrentNode = "OfficerVinsentVento_Bill1_4";
			AddDialogExitQuest("OfficerVinsentVento_FormBillWithoutDocuments");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Bill_FightVsBill":
			NextDiag.CurrentNode = "OfficerVinsentVento_Bill1_5";
			AddDialogExitQuest("OfficerVinsentVento_FightVsBill");
			DialogExit();
		break;
		
		case "OfficerVinsentVento_Bill1_5":
			dialog.text = "Дьявол, ты меня ранил! Держи эти проклятые чертежи, жить хочу!";
			link.l1 = "Ну вот, так бы и сразу, чего саблей-то махать было?";
			link.l1.go = "Exit";
		break;
		
		case "OfficerVinsentVento_Bill1_4":
			dialog.text = "Тебе здорово повезло, капитан, что ты еще жив!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill1_4";
		break;
		
		case "OfficerVinsentVento_Bill2":
			dialog.text = "Тысяча чертей! Что вы забыли у меня в доме?";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill2_1";
		break;

		case "OfficerVinsentVento_Bill2_1":
			dialog.text = "Каких документов? Я ничего не знаю! Я никуда не хожу! Нет у меня никаких документов!!!";
			link.l1 = "Тебя видели в местной таверне. Ты вышел сразу за офицером, после этого у него пропали бумаги. Надеюсь, ты не станешь утверждать, что это просто случайность?";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_Bill2_2";
		break;
		
		case "OfficerVinsentVento_Bill2_2":
			dialog.text = "Что вы себе позволяете?!";
			link.l1 = "Лучше сам все рассказывай как есть. Хоть голландцы и миролюбивы, но для таких пиратов как ты, у них всегда есть свободная виселица!";
			link.l1.go = "OfficerVinsentVento_Bill2_3";
		break;
		
		case "OfficerVinsentVento_Bill2_3":
			dialog.text = "Виселица?! Я французский корсар! Плаваю с Тревором д’Версером, это же прямой конфликт с Францией! Вы отв...";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// Солдат
		case "OfficerVinsentVento_Soldier":
			dialog.text = "Офицер, посмотрите, какие-то бумаги...";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// Карлос Веласкес
		case "OfficerVinsentVento_KarlosVelaskes":
			dialog.text = "Вы хотите заказать у меня портрет?";
			link.l1 = "Не совсем, мне нужно, чтобы вы сделали копии одних бумаг, а точнее чертежей.";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_1";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_1":
			dialog.text = "Ну-ка, ну-ка, что тут у нас... Хм, занятные бумажонки, уж больно это похоже на чертежи каких-то укреплений...";
			link.l1 = "А ты меньше вникай, перерисуй и все, остальное тебя не должно касаться. И поверь, тебе же от этого лучше будет.";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_2";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_2":
			dialog.text = "Ладно-ладно, не дурак, понимаю все, но и вы меня поймите - печати, подписи, чертежи, все это пахнет государственной изменой. Нарисовать-то я нарисую, но стоить это будет вам немало.";
			link.l1 = "И сколько ты хочешь?";
			link.l1.go = "OfficerVinsentVento_KarlosVelaskes_3";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_3":
			dialog.text = "1000 пиастров за каждый лист, итого 4000 пиастров.";
			if(sti(pchar.money) >= 5000)
			{
				link.l1 = "Я заплачу тебе сверху еще 1000 пиастров за твое молчание и за срочность.";
				link.l1.go = "OfficerVinsentVento_KarlosVelaskes_5";
			}
			link.l2 = "Хм, думаю, они не стоят этого, прощай и забудь про наш разговор, если узнаю, что ты проболтался кому-то - из-под земли достану!";
			link.l2.go = "OfficerVinsentVento_KarlosVelaskes_Exit";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_Exit":
			NextDiag.CurrentNode = "OfficerVinsentVento_KarlosVelaskes_4";
			DialogExit();
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes_NO");
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_4":
			dialog.text = "Капитан, давайте я все-таки нарисую ваш портрет.";
			link.l1 = "Нет, не сейчас.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_4";
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_5":
			dialog.text = "Что же, с вами приятно иметь дело, как оказалось. Через 24 часа копия будет готова. Могу поспорить на свой гонорар, что вы не отличите ее от оригинала!";
			link.l1 = "Посмотрим... До завтра.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_6";
			AddDialogExitQuest("OfficerVinsentVento_KarlosVelaskes_YES");
		break;
		
		case "OfficerVinsentVento_KarlosVelaskes_6":
			dialog.text = "Вот копия и оригиналы.";
			link.l1 = "Силы небесные! Да их и правда не отличить!!! Спасибо тебе, и помни - никому ни слова.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "OfficerVinsentVento_KarlosVelaskes_4";
		break;
/////////////////////////////////////////
// Поиски кораблей для торговца Кюрасао
/////////////////////////////////////////		
		
// Пират в таверне Тортуги
		case "FindShipCuracaoTrader_pirate":
			dialog.text = "Если у тебя ко мне дело - говори, если нет - проваливай, не мешай мне отдыхать.";
			link.l1 = "Я от человека по имени "+GetCharacterFullName("LaVega_Hovernor")+". Он посоветовал обратиться к тебе, сказал, что ты знаешь где достать товар, который мне нужен позарез.";
			link.l1.go = "FindShipCuracaoTrader_pirate_1";
		break;
		
		case "FindShipCuracaoTrader_pirate_1":
			dialog.text = "Это меняет суть... Давай поднимемся наверх, поговорим в более уютной обстановке.";
			link.l1 = "Идем.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "FindShipCuracaoTrader_pirate_2";
			AddDialogExitQuest("FindShipCuracaoTrader_ToTortugaTavernRoom");
		break;
		
		case "FindShipCuracaoTrader_pirate_2":
			dialog.text = "Давай, выкладывай, что там у тебя.";
			link.l1 = "Мне нужно черное дерево, как можно больше и как можно дешевле.";
			link.l1.go = "FindShipCuracaoTrader_pirate_3";
		break;
		
		case "FindShipCuracaoTrader_pirate_3":
			dialog.text = "Ха-ха-ха-ха, парень, да ты прям точно по адресу! Наконец-то наш капитан сбагрит это чертово дерево и у нас в карманах зазвенит монета! Через две недели будь на Тортуге и мы доставим тебе товар.";
			link.l1 = "А могу я встретиться с вашим капитаном лично? Столько времени тратить в пустую, а мне позарез нужно это дерево...";
			link.l1.go = "FindShipCuracaoTrader_pirate_4";
		break;
		
		case "FindShipCuracaoTrader_pirate_4":
			dialog.text = "Нет, у нас есть приказ, и мы его выполним.";
			link.l1 = "Может, все-таки, договоримся? Как я понял у вас с деньгами туго...";
			link.l1.go = "FindShipCuracaoTrader_pirate_5";
		break;
		
		case "FindShipCuracaoTrader_pirate_5":
			dialog.text = "Парень, как там тебя, что-то ты мне не нравишься. Тебе предлагают так нужный для тебя товар, да еще и по дешевке, а ты начинаешь что-то бузить! Я не понял, тебе товар нужен или наш капитан?!";
			link.l1 = "Ой, как страшно! Ха-ха-ха-ха!!! Фабло, давай укажем этому недомерку дорогу к предкам!";
			link.l1.go = "Exit";
			AddDialogExitQuest("FindShipCuracaoTrader_FightInTavernRoom");
		break;
		
// Эрнесто де Сильва
		case "FindShipCuracaoTrader_Ernesto":
			dialog.text = "Присаживайся, выпей со мной, я угощаю!";
			link.l1 = "Я бы с удовольствием, но у меня к тебе есть один деликатный вопрос.";
			link.l1.go = "FindShipCuracaoTrader_Ernesto1";
		break;
		
		case "FindShipCuracaoTrader_Ernesto1":
			dialog.text = "Я весь превратился в слух, ха-ха-ха-ха.";
			link.l1 = "Мое имя, "+GetCharacterFullName(pchar.id)+". Меня нанял "+GetCharacterFullName("Curacao_trader")+" - владелец флейта 'Гертруда', чтобы я убил тебя. Но перед тем, как ты сдохнешь, я хочу знать, где корабль!";
			link.l1.go = "FindShipCuracaoTrader_Ernesto2";
		break;
		
		case "FindShipCuracaoTrader_Ernesto2":
			dialog.text = "Не видать тебе корабля, как своей жизни!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("FindShipCuracaoTrader_PrepareFightVsErnesto");
		break;

///////////////////////////////
// Измена Марко ван Клеве
///////////////////////////////
		case "DesertirMarko_PiratInTavern":
			dialog.text = "Уйди с дороги, собака!";
			link.l1 = "Полегче, приятель!";
			link.l1.go = "DesertirMarko_PiratInTavern1";
		break;
		
		case "DesertirMarko_PiratInTavern1":
			dialog.text = "Вот ублюдок!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_FightInTavern");
		break;

// Солдат в таверне
		case "DesertirMarko_SoldierInTavern":
			dialog.text = "Кто звал патруль? Та-а-ак, что тут у нас, труп? Вы арестованы, пройдемте с нами.";
			link.l1 = "Дьявол!";
			link.l1.go = "Exit";
		break;

// Дезертировавший матрос
		case "DesertirMarko_DeserteerSailor":
			dialog.text = "Минхер, дайте пару пиастров, я два дня ничего не ел.";
			link.l1 = "Что-то ты не похож на нищего...";
			link.l1.go = "DesertirMarko_DeserteerSailor_1";
		break;
		
		case "DesertirMarko_DeserteerSailor_1":
			dialog.text = "Вы правы, я матрос со шхуны 'Сова'. Наш капитан служил губернатору Мариго, но потом предал его. Многим из команды такая выходка капитана пришлась не по душе и мы дезертировали, когда наш корабль бросил якорь здесь, в Ла-Вега.";
			link.l1 = "Случаем не Марко ван Клеве был твоим капитаном?";
			link.l1.go = "DesertirMarko_DeserteerSailor_2";
		break;
		
		case "DesertirMarko_DeserteerSailor_2":
			dialog.text = "Да, именно он, а откуда вам известно его имя?";
			link.l1 = "Ха, парень, тебе и остальным дезертирам несказанно повезло! Клянусь дьяволом, когда я найду вашего бывшего капитана, его и всех кто рядом с ним ждет виселица! Скажи мне, куда дальше собирался Марко ван Клеве?";
			link.l1.go = "DesertirMarko_DeserteerSailor_3";
		break;
		
		case "DesertirMarko_DeserteerSailor_3":
			dialog.text = "Я слышал, он хотел отправиться на Тортугу.";
			link.l1 = "Что же, спасибо тебе. Держи 5 пиастров и радуйся жизни.";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_ToTortuga");
			NextDiag.TempNode = "DesertirMarko_DeserteerSailor_4";
		break;
		
		case "DesertirMarko_DeserteerSailor_4":
			dialog.text = "Я безумно благодарен вам, капитан.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "DesertirMarko_DeserteerSailor_4";
		break;

// Офицер на палубе
		case "DesertirMarko_PirateOfficer":
			dialog.text = "Капитан, чем обязаны вашему визиту?";
			link.l1 = "Мое имя "+GetCharacterFullName(pchar.id)+", а вы, если не ошибаюсь, капитан ван Клеве?";
			link.l1.go = "DesertirMarko_PirateOfficer_1";
		break;
		
		case "DesertirMarko_PirateOfficer_1":
			dialog.text = "Нет, гер "+pchar.name+", к сожалению вы ошибаетесь. Меня зовут "+GetCharacterFullName(NPChar.id)+", я первый помощник капитана.";
			link.l1 = "В таком случае позови своего капитана, у меня к нему разговор есть.";
			link.l1.go = "DesertirMarko_PirateOfficer_2";
		break;
		
		case "DesertirMarko_PirateOfficer_2":
			dialog.text = "Сожалею, но вашей, надеюсь просьбы, я выполнить не могу. Капитан уже давно уплыл на втором корабле, каравелле 'Удача'. Он приказал ждать его здесь, вот мы и болтаемся тут уже больше месяца.";
			link.l1 = "А куда отправился ваш капитан?";
			link.l1.go = "DesertirMarko_PirateOfficer_3";
		break;
		
		case "DesertirMarko_PirateOfficer_3":
			dialog.text = "А вот это уже не ваше дело. На все вопросы, на которые я счел нужным ответить - я ответил, а теперь извольте покинуть корабль. Мои люди и так на грани срыва, а вид ваших вооруженных до зубов людей не вызывает у них оптимизма.";
			link.l1 = "Так, мне надоело сюсюкаться с тобой! Ты, твой капитан и все, кто находится на этом корабле - предатели. У меня поручение - доставить твоего капитана живым в Мариго. Ни про тебя, ни про эти жалкие остатки, трясущейся от страха, команды речи не шло. Эй, ребята! НА АБОРДАЖ!!!";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_BoardingShooner");
		break;

// Марко ван Клеве
		case "DesertirMarko_MarkoVanKleve":
			dialog.text = "Что тебе здесь надо? Убирайся, это моя комната.";
			link.l1 = "Я капитан "+GetCharacterFullName(pchar.id)+", меня послал за вами "+GetCharacterFullName("StMartin_prisonkeeper")+". Я должен доставить тебя в тюрьму Мариго.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_1";
		break;
		
		case "DesertirMarko_MarkoVanKleve_1":
			dialog.text = "И ты решил, что я сейчас вот так вот возьму и пойду с тобой?";
			link.l1 = "А у тебя нет выбора, если ты не подчинишься мне, то отправишься вслед за своей командой и первым помощником.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_2";
		break;
		
		case "DesertirMarko_MarkoVanKleve_2":
			dialog.text = "Ха! Они далеко отсюда и тебе их просто так не найти!";
			link.l1 = "Я и мои люди уже их нашли. Кстати, могу дать тебе минуту, чтобы ты смог почтить их память молчанием, ха-ха-ха-ха. Так что не надо фокусов, сдавай оружие и следуй за мной.";
			link.l1.go = "DesertirMarko_MarkoVanKleve_3";
		break;
		
		case "DesertirMarko_MarkoVanKleve_3":
			dialog.text = "Я убью тебя!!!";
			link.l1 = "А вот это вряд ли...";
			link.l1.go = "Exit";
			AddDialogExitQuest("DesertirMarko_FightVsMarko");
		break;

// Тавернщик Мартиники
		case "DesertirMarko_TavernOvner":
			dialog.text = "Что здесь за шум?! О боже!!! Вы убили этого человека!!!";
			link.l1 = "Да не ори ты, сам вижу!";
			link.l1.go = "DesertirMarko_TavernOvner_1";
		break;
		
		case "DesertirMarko_TavernOvner_1":
			dialog.text = "Умоляю вас, пощадите меня, не убивайте! Я никому ни слова не скажу, клянусь!";
			link.l1 = "Успокойся, не буду я тебя трогать, а скажешь ты кому-то или нет, мне плевать. Лучше подумай, как ты будешь выносить труп из тавер... Постой-ка... Что это? Да он же жив!!!";
			link.l1.go = "DesertirMarko_TavernOvner_2";
		break;
		
		case "DesertirMarko_TavernOvner_2":
			dialog.text = "Точно, дышит...";
			link.l1 = "Так, следи, чтобы никто не зашел в комнату, а я через час вернусь со своими людьми и заберу его отсюда.";
			link.l1.go = "DesertirMarko_TavernOvner_3";
		break;
		
		case "DesertirMarko_TavernOvner_3":
			dialog.text = "Да-да, конечно, месье.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// Маонах на Бермудах
		case "AntiChurch_MIB":
			dialog.text = "Вот и прекрасно, оно у меня. А ты, загляни на досуге в таверну Порт-Рояла и спроси Конора Морриса. Может и для тебя найдется дельце.";
			link.l1 = "Эй, постой!";
			link.l1.go = "Exit";
			NextDiag.TempNode = "AntiChurch_MIB_PortRoyal";
		break;
		
		case "AntiChurch_MIB_PortRoyal":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
// Монахи в таверне на Бермудах
		case "Monk_in_Bermudes_tavern":
			dialog.text = "Так это ты, вероотступник, помог этим еретикам завладеть ценным письмом?!";
			link.l1 = "Да, это я, а будешь много разговаривать - отправишься вслед за ним!";
			link.l1.go = "Monk_in_Bermudes_tavern_fight";
			link.l2 = "Я? С какой стати?! Я здесь не причем! И вообще, я здесь случайно...";
			link.l2.go = "Monk_in_Bermudes_tavern_1";
		break;
		
		case "Monk_in_Bermudes_tavern_fight":
			AddDialogExitQuest("ChurchQuest_ENDGAME_in_BermudesTavern");
			DialogExit();
		break;
		
		case "Monk_in_Bermudes_tavern_1":
			dialog.text = "Случайно говоришь? Пообщаемся предметно в нашей обители правды. У тебя там будет возможность раскаяться в своих грехах!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_to_Santiago");
		break;

// Монах в тюрьме Сантьяго 		
		case "Monk_in_Santiago":
			dialog.text = "Ну что, заблудшая овца, продолжаешь упорствовать в своих грехах или раскаешься? Обещаю, без мучений предстанешь пред Господом нашим.";
			link.l1 = "Я не понимаю, о чем вы? Это какая-то роковая ошибка! Прошу меня выпустить отсюда, я законопослушный гражданин!";
			link.l1.go = "Monk_in_Santiago_1";
		break;
		
		case "Monk_in_Santiago_1":
			dialog.text = "Я вижу, что мои слова не доходят до тебя. Я бы с удовольствием уже сейчас приступил бы к процедуре допроса, да только тебе повезло. С тобой хочет лично побеседовать его святейшество - Епископ Буотти, а он сейчас в отъезде.";
			link.l1 = "Я не знаю никакого епископа Буотти.";
			link.l1.go = "Monk_in_Santiago_2";
		break;
		
		case "Monk_in_Santiago_2":
			dialog.text = "Ты не знаешь Епископа Филлипо Буотти... Ха-ха-ха-ха! Ничего, у тебя будет возможность с ним познакомиться, и даже подружиться, когда он лично оденет тебе 'испанский сапог'.";
			link.l1 = "Помилуйте, да за что мне такое?!";
			link.l1.go = "Monk_in_Santiago_3";
		break;
		
		case "Monk_in_Santiago_3":
			dialog.text = "Ничего- ничего,  посиди немного, неделька другая без воды и пищи придадут тебе силы, нечестивец.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

// Сатанист в тюрьме Сантьяго
		case "Man_in_SantiagoPrison":
			dialog.text = "Да, не сложно было догадаться, что именно здесь тебя и будут держать.";
			link.l1 = "А кто вы такие и что вам от меня нужно?";
			link.l1.go = "Man_in_SantiagoPrison_1";
		break;
		
		case "Man_in_SantiagoPrison_1":
			dialog.text = "Да ничего нам не нужно от тебя. Мастер сказал, что тебя арестовали, и сказал где тебя искать.";
			link.l1 = "Что за мастер? Не знаю никакого мастера.";
			link.l1.go = "Man_in_SantiagoPrison_2";
		break;
		
		case "Man_in_SantiagoPrison_2":
			dialog.text = "Зато он тебя знает. Ты ему услугу оказал, а он не забывает добра. Ладно, собирайся, будем выбираться из этого мрачного логова.";
			link.l1 = "Каким образом? У меня нет ни оружия, ни корабля...";
			link.l1.go = "Man_in_SantiagoPrison_3";
		break;
		
		case "Man_in_SantiagoPrison_3":
			dialog.text = "Вот твои вещи, беги сразу за город, там получишь инструкции.";
			link.l1 = "Понял, спасибо.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Man_in_SantiagoPrison_4";
		break;
		
		case "Man_in_SantiagoPrison_4":
			dialog.text = "Ну что, друг, все получилось.";
			link.l1 = "Да, спасибо, смог выбраться, думал каюк мне там настанет.";
			link.l1.go = "Man_in_SantiagoPrison_5";
		break;
		
		case "Man_in_SantiagoPrison_5":
			dialog.text = "Видно не судьба тебе окончить свое бренное существование в застенках инквизиции.";
			link.l1 = "Да, видно не судьба, а ты кто, если не секрет?";
			link.l1.go = "Man_in_SantiagoPrison_6";
		break;
		
		case "Man_in_SantiagoPrison_6":
			dialog.text = "Не секрет, да вот время нет объяснять. Помнишь, что мастер сказал? Вот и дуй к нему в Порт-Рояль, там в таверне переговори с барменом, он тебе скажет где его искать. \nПравда, прежде чем показываться к нему на глаза, ты должен сделать еще одно дело.";
			link.l1 = "Конечно, что от меня требуется?";
			link.l1.go = "Man_in_SantiagoPrison_7";
		break;
		
		case "Man_in_SantiagoPrison_7":
			dialog.text = "Тебе надо пробраться на Санто-Доминго. Там, в одном из домов, тебя будет ждать некий Сезар Кармин.";
			link.l1 = "Что это за человек?";
			link.l1.go = "Man_in_SantiagoPrison_8";
		break;
		
		case "Man_in_SantiagoPrison_8":
			dialog.text = "О, это кровавая история. Он долгое время ходил старшим помощником капитана на одном из испанских торговых судов. \nВернувшись из очередного рейса, обнаружил у себя в доме погром. Пропала его любимая жена Катрин. В случившемся, он подозревает происки Испанской инквизиции. \nИ вот, продав все, что у него было, прослышав про нашу борьбу с этими испанскими 'святошами', он, горя желанием отомстить, прибыл в Новый свет и ищет встречи с Мастером.";
			link.l1 = "Хорошо, я заберу его с Санто-Доминго, хотя еще сам не представляю, как буду отсюда выбраться...";
			link.l1.go = "Man_in_SantiagoPrison_9";
		break;
		
		case "Man_in_SantiagoPrison_9":
			dialog.text = "Об этом мы позаботились. В бухте мыса Камагуэй, увидишь свой корабль в целости и сохранности, благо команда у тебя смышленая - сумели пригнать его без капитана.";
			link.l1 = "Вот это да, никак не ожидал.";
			link.l1.go = "Man_in_SantiagoPrison_10";
		break;
		
		case "Man_in_SantiagoPrison_10":
			dialog.text = "Чего не ожидал? Что у нас штурман  найдется твою посудину перегнать? Хе-хе. Удачи тебе, капитан.";
			link.l1 = "До встречи и спасибо за помощь.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_Santiago_shore");
		break;

// Офицер в доме Сан-Хуана		
		case "ChurchQuest_SpOfficerInStJuan":
			dialog.text = "Именем губернатора Сан-Хуан, вы арестованы, сеньор. Во избежание применения грубой физической силы, я вам предлагаю немедленно проследовать за мной.";
			link.l1 = "Без проблем, я не в чем не виноват, приказывайте куда идти.";
			link.l1.go = "ChurchQuest_SpOfficerInStJuan_END_GAME";
			link.l2 = "Я сейчас буду вынужден сам применить грубую физическую силу, если вы не оставите меня в покое, сеньор офицер. Думаю, моя личность известна на архипелаге...";
			link.l2.go = "ChurchQuest_SpOfficerInStJuan_1";
		break;
		
		case "ChurchQuest_SpOfficerInStJuan_END_GAME":
			AddDialogExitQuest("ChurchQuest_MIB_in_SanJuanHouse_ENDGAME");
			DialogExit();
		break;
		
		case "ChurchQuest_SpOfficerInStJuan_1":
			dialog.text = "Да уж, наслышан. Ну что ж, из города вам все равно не уйти, живым!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_in_SanJuanHouse_man");
		break;
		
// Сэзар Кармин
		case "ChurchQuest_SezarCarmin":
			dialog.text = "Кто вы такой, и что вам от меня надо? Я простой мирный житель и у меня нет ничего ценного.";
			link.l1 = "Не переживай ты так. Я не собираюсь тебя грабить, мне нужен Сэзар Кармин.";
			link.l1.go = "ChurchQuest_SezarCarmin_1";
		break;
		
		case "ChurchQuest_SezarCarmin_1":
			dialog.text = "Да это именно я, но я вас не знаю, сеньор, кто вы?";
			link.l1 = "Тебе и не надо меня знать, я выполняю поручение Мастера, этого человека, я надеюсь, ты знаешь.";
			link.l1.go = "ChurchQuest_SezarCarmin_2";
		break;
		
		case "ChurchQuest_SezarCarmin_2":
			dialog.text = "О, наконец-то! Я уже и надежду всякую потерял выбраться отсюда. Скорее, прошу вас, доставьте меня к нему!";
			link.l1 = "Давай, держись ближе ко мне, надеюсь пробьемся. Ты умеешь обращаться со шпагой?";
			link.l1.go = "ChurchQuest_SezarCarmin_3";
		break;
		
		case "ChurchQuest_SezarCarmin_3":
			dialog.text = "Шпагой? Владею, сеньор капитан, и весьма умело.";
			link.l1 = "Тогда вперед, будем пробиваться за город.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_from_StJuan");
		break;
		
		case "ChurchQuest_SezarCarmin_4":
			dialog.text = "Напрасно, капитан, я понадеялся на вашу порядочность.";
			link.l1 = "А в чем, собственно говоря, проблема?";
			link.l1.go = "ChurchQuest_SezarCarmin_5";
		break;
		
		case "ChurchQuest_SezarCarmin_5":
			dialog.text = "Ваши личные амбиции перевесили интересы дела, теперь, благодаря вам, мне будет очень сложно разыскать Мастера. Прощай, неудачник.";
			link.l1 = "Тоже мне, подумаешь.";
			link.l1.go = "Exit";
		break;
		
		case "ChurchQuest_SezarCarmin_6":
			dialog.text = "О, Мастер! Наконец-то я смог найти Вас!!!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_7";
		break;
		
		case "ChurchQuest_SezarCarmin_7":
			dialog.text = "Буду с Вами откровенен, Мастер. Прослышав про Вашу борьбу против испанской инквизиции, хочу быть полезен Вам в этом деле. Готов выполнить любое Ваше поручение, какое бы мне не доверили. \nПорукой моего лояльного отношения к Вашему движению будет то, что случилось с моей женой Катрин. Я наверняка уверен, что тут не обошлось без руки инквизиции.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_8";
		break;
		
		case "ChurchQuest_SezarCarmin_8":
			dialog.text = "Спасибо, Мастер.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "ChurchQuest_SezarCarmin_9";
		break;

// Флоридо Элькано		
		case "Florido_Elkano":
			dialog.text = "...";
			link.l1 = "Так вот кто собирает сведения о Квинтусе Апиусе... Сейчас ты отправишься со мной, с тобой хотят поговорить серьезные люди.";
			link.l1.go = "Florido_Elkano_1";
		break;
		
		case "Florido_Elkano_1":
			dialog.text = "Скорее ты у меня отправишься к праотцам! Я узнал тебя!!! Это ты шпионил за нами с Епископом в Сан-Хуане.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Florido_Elkano_2";
		break;
		
		case "Florido_Elkano_2":
			dialog.text = "Все, я сдаюсь, твоя взяла, чего ты хочешь?";
			link.l1 = "Мне лично от тебя ничего не надо, а вот люди, под которых ты здесь копаешь, очень желают с тобой поговорить.";
			link.l1.go = "Exit";
		break;
		
		case "Florido_Elkano_3":
			dialog.text = "Не думал, что ты такой настырный, капитан.";
			link.l1 = "Да и я не думал тебя встретить в добром здравии, наемник.";
			link.l1.go = "Florido_Elkano_4";
		break;
		
		case "Florido_Elkano_4":
			dialog.text = "Пришло время закончить наше общение, надеюсь, ты помолился перед смертью?";
			link.l1 = "За меня не переживай, лучше за свою шкуру побеспокойся, думаю с этого острова тебе уже не уйти.";
			link.l1.go = "Florido_Elkano_5";
		break;
		
		case "Florido_Elkano_5":
			dialog.text = "Да, один из нас точно уже отсюда не уйдет.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// Сектант в банке белиза
		case "Animist_in_Beliz_bank":
			dialog.text = "О, капитан, мы, кажется, прибыли вовремя!";
			link.l1 = "Да, брат, как никогда вовремя! Был бы я чуть послабее, меня бы здесь уже успели проткнуть не один раз. Пока вас дождешься...";
			link.l1.go = "Animist_in_Beliz_bank_1";
		break;
		
		case "Animist_in_Beliz_bank_1":
			dialog.text = "Извини, капитан, но мы прибыли, сразу, как только к нам поступила информация.";
			link.l1 = "Ладно. Что делать с этим фруктом будем?";
			link.l1.go = "Animist_in_Beliz_bank_2";
		break;
		
		case "Animist_in_Beliz_bank_2":
			dialog.text = "Капитан, по указанию Мастера, мы его забираем к себе, тебе же надо срочно прибыть к Мастеру.";
			link.l1 = "Хорошо, навещу его как можно скорее.";
			link.l1.go = "Exit";
			AddDialogExitQuest("ChurchQuest_MIB_in_Beliz_bank_night_dialog_all_go_away");
		break;
		
//--------------------------------------------------------------------------------------------------------------------		
// Джошуа Бин
		case "JoueBean_Joue_1":
			// dialog.text = "О боже, вы все-таки нашли меня! Живим, я вам не дамся. Хотя какая разница, вы все равно меня повесите...";
			// link.l1 = "Что?! "+FindRussianGreeting(pchar, 0, false)+", что с вами случилось?";
			// link.l1.go = "JoueBean_Joue_2";
		break;

		case "JoueBean_Joue_2":
			dialog.text = "Не надо лишних слов, я все понял. Да, я знаю... В кандалы меня!!!";
			link.l1 = "Парень, ты часом не сдурел? О чем ты говоришь? Я тебя не знаю, и знать не желаю.";
			link.l1.go = "JoueBean_Joue_3";
		break;
		
		case "JoueBean_Joue_3":
			dialog.text = "Так вы не за мной?! Вам не было приказано найти человека по имени Джошуа Бин, и любыми доступными средствами доставить его в резиденцию Бриджтауна?";
			link.l1 = "Э-э-э... Как раз это и было приказано. И...";
			link.l2 = "Нет, никто мне ничего не приказывал. Я вольный капитан, и подчиняюсь только своим приказам...";
			link.l1.go = "JoueBean_Joue_Exit1";
			link.l2.go = "JoueBean_Joue_4";
		break;
		
		case "JoueBean_Joue_Exit1":
			AddDialogExitQuest("JoeBean_RunAway");
			DialogExit();
		break;
		
		case "JoueBean_Joue_4":
			dialog.text = "О! Радость какая! Слава Богу, а я уже перепугался. Так вы капитан, да? А как же вы попали в пещеру?";
			link.l1 = "М-м-м... Я забыл здесь свои вещи... А теперь объясни, кто ты такой, и почему решил, что я пришел по чьему-то приказу?";
			link.l1.go = "JoueBean_Joue_5";
		break;
		
		case "JoueBean_Joue_5":
			dialog.text = "Меня зовут Джошуа Бин. Меня считают преступником, но это не так! Власти города, решили, что я выкрал казну. Но как я это смог сделать?! У меня даже собственного дома нет...";
			link.l1 = "Понятно, Джошуа. И что же ты тут сидишь? Ты думаешь, это тебя спасет?";
			link.l1.go = "JoueBean_Joue_6";
		break;
		
		case "JoueBean_Joue_6":
			dialog.text = "Я бежал из города, и спарятся в пещере. Здесь намного лучше, чем в джунглях. Там бродят английские патрули. Мне лучше бежать с острова, в другие колонии. К англичанам мне теперь нельзя, меня там сразу поймают. \nТак, вы же капитан?! Помогите мне убраться отсюда, умоляю вас!!!";
			link.l1 = "А знаешь что, лучше я тебя сдам губернатору. Ты мошенник, и тебя надо засадить в тюрьму. Следуй за мной, собака, если тебе дорога жизнь!";
			link.l1.go = "JoueBean_Joue_Exit2";
			link.l2 = "Да, я помогу тебе. И не таких перевозил. Слушай меня внимательно и следуй моим инструкциям, тогда все будет хорошо.";
			link.l2.go = "JoueBean_Joue_7";
		break;
		
		case "JoueBean_Joue_Exit2":
			AddDialogExitQuest("JoeBean_toHovernor");
			DialogExit();
		break;
		
		case "JoueBean_Joue_7":
			dialog.text = "Хорошо. Сделаю что угодно, только лишь убраться отсюда!";
			link.l1 = "Тогда слушай сюда. Я пойду в город, и пригоню его в ближайшую бухту. Потом я приду сюда за тобой. Мы вместе пойдем к кораблю. Все понял? Сиди здесь, никуда не выходи и жди меня. Я перегоняю корабль прихожу за тобой и мы убираемся с острова.";
			link.l1.go = "JoueBean_Joue_8";
		break;
		
		case "JoueBean_Joue_8":
			dialog.text = "Я жду, вы приходите, мы бежим... Я жду, вы приходите, мы бежим...";
			link.l1 = "Отлично, жди.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "JoueBean_Joue_9";
			AddDialogExitQuest("JoeBean_help");
		break;
		
		case "JoueBean_Joue_9":
			if(pchar.location.from_sea == "Bridgetown_Shore2")
			{
				dialog.text = "Кто здесь? А, это Вы, капитан.";
				link.l1 = "Готов? Мы сейчас же уходим на корабль.";
				link.l1.go = "Exit";
				AddDialogExitQuest("JoeBean_help_go");
			}
			else
			{
				dialog.text = "Я жду, вы приходите, мы бежим... Я жду, вы приходите, мы бежим...";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "JoueBean_Joue_9";
			}
		break;
		
		case "JoueBean_Joue_10":
			dialog.text = "...";
			link.l1 = "Ну как ты, Джо? Все хорошо?";
			link.l1.go = "JoueBean_Joue_11";
		break;
		
		case "JoueBean_Joue_11":
			dialog.text = "А? Что? Джо?";
			link.l1 = "Ты не против, если я буду называть тебя Джо?";
			link.l1.go = "JoueBean_Joue_12";
		break;
		
		case "JoueBean_Joue_12":
			dialog.text = "А? Нет, не против. Я думал еще немного, и нам конец. А вы лихой капитан...";
			link.l1 = "Есть немного. Так куда ты хочешь направиться? К англичанам тебе нельзя...";
			link.l1.go = "JoueBean_Joue_13";
		break;
		
		case "JoueBean_Joue_13":
			dialog.text = "Это верно. Думаю, можно причалить к одной из испанских колоний. Там англичане меня точно не достанут. К тому же, мой дядя жил в Порто-Белло, но он умер, оставив мне небольшое наследство. Если бы я оказался там...";
			link.l1 = "У нас мало времени. С минуты на минуту, могут появиться еще патрули, на корабль!";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_to_ship");
		break;
		
		case "JoueBean_Joue_14":
			dialog.text = "Что бы я без вас делал! Вы помогли мне сбежать от англичан, которые хотели меня повесить! Сейчас мне надо отправиться к священнику, дядя ведь оставил завещание, и мне осталось только забрать его.";
			link.l1 = "А как насчет награды? Ты ведь не думал, что я просто так рисковал жизнью? Ты почти богат и в состоянии заплатить мне за мои услуги.";
			link.l1.go = "JoueBean_Joue_15";
		break;
		
		case "JoueBean_Joue_15":
			dialog.text = "Конечно, капитан! Вы столько сделали для меня. Приходите завтра в таверну, посидим, выпьем.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "JoueBean_Joue_16";
		break;
				
		case "JoueBean_Joue_16":
			dialog.text = "Эх, капитан! А жизнь-то налаживается! Садитесь, выпьем. Вы мне так помогли, так помогли. Я получил дом, скоро найду работу. На всю жизнь-то наследства не хватит!";
			link.l1 = "Смотри не пропей все. Так что там насчет награды?";
			link.l1.go = "JoueBean_Joue_17";
		break;
				
		case "JoueBean_Joue_17":
			dialog.text = "Могу дать только 500 пиастров. На данный момент я не могу дать вам больше.";
			link.l1 = "Эх... Давай сюда. Маловато конечно, но хоть что-то.";
			link.l1.go = "JoueBean_Joue_18";
		break;
				
		case "JoueBean_Joue_18":
			dialog.text = "А вот и пришел покупатель. Простите, но мне надо поговорить вон с тем парнем. Это по делу.";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_in_PortoBello_tavern2");
		break;
				
		case "":
			dialog.text = "";
			link.l1 = "";
			link.l1.go = "";
		break;
		
		
		
//--------------------------------------------------------------------------------------------------------------------		
// Офицер в джунглях
		case "JoueBean_EngOff_1":
			dialog.text = "Стоять! Мы разыскиваем одного человека. Скажите, Вы не замечали ничего подозрительного?";
			link.l1 = "Нет, ничего такого. Все на удивление спокойно.";
			link.l1.go = "JoueBean_EngOff_2";
		break;
		
		case "JoueBean_EngOff_2":
			dialog.text = "А это кто? Вот, рядом с вами? Очень напоминает...";
			link.l1 = "Э, это мой... Ммм... Слуга, Марго.";
			link.l1.go = "JoueBean_EngOff_3_1";
			link.l2 = "Тысяча чертей! Готовьтесь умереть!!!";
			link.l2.go = "JoueBean_EngOff_3_2";
			if(sti(pchar.money)>=4000)
			{
				link.l3 = "Вот вам 1000 пиастров, за храбрость, и мы остаемся друзьями.";
				link.l3.go = "JoueBean_EngOff_3_3";
			}
		break;
		
		case "JoueBean_EngOff_3_1":
			dialog.text = "Марго? Слуга? А, ладно, и не таких видывали. Спасибо, Вы нам очень помогли.";
			link.l1 = "Не за что, офицер.";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_patrol_away");
		break;
		
		case "JoueBean_EngOff_3_2":
			AddDialogExitQuest("JoeBean_Barbados_patrol_fight");
			DialogExit();
		break;
		
		case "JoueBean_EngOff_3_3":
			dialog.text = "Тысяча на каждого, сэр.";
			link.l1 = "На каждого? Вы смеетесь?! А, ладно, уговорили, вот ваши деньги, а теперь, прощайте.";
			link.l1.go = "Exit";
			AddDialogExitQuest("JoeBean_Barbados_patrol_away");
			AddMoneyToCharacter(pchar, -4000);
		break;
		
//--------------------------------------------------------------------------------------------------------------------		

//--------------------------------------------------------------------------------------------------------------------
// Человек в таверне Порто-Белло

		case "JoeBean_straight_man":
			dialog.text = "Ты кто такой? Что ты тут забыл?!";
			link.l1 = "Ты убил Джо? За что?!";
			link.l1.go = "JoeBean_straight_man_1";
		break;
		
		case "JoeBean_straight_man_1":
			dialog.text = "Кто ты? Отвечай не медленно, или я вспорю тебе брюхо!";
			link.l1 = "Я капитан "+pchar.lastname+". Я помог несчастному Джошуа добраться сюда...";
			link.l1.go = "JoeBean_straight_man_2";
		break;
		
		case "JoeBean_straight_man_2":
			dialog.text = "Ты назвал его Джошуа?!";
			link.l1 = "Да, Джошуа Бин. Англичане хотели его повесить. Они обвинили его в том, что он не совершал - в краже казны...";
			link.l1.go = "JoeBean_straight_man_3";
		break;
		
		case "JoeBean_straight_man_3":
			dialog.text = "Ха-ха-ха-ха! Начнем по порядку. Этот, как ты его назвал, мистер Бин, на самом деле не тот, за кого себя выдает. Его настоящие имя Хайме Мартина Монрой. \nОн испанский шпион, который много лет шпионил в Бриджтауне. Его обвинили вовсе не в краже казны, а кое в чем другом, похлеще! Могу сказать лишь одно - это величайший аферист в истории и мне было приказано убить его. \nА теперь мне надо идти и не советую тебе, с кем бы то ни было, говорить об этом, по крайней мере, здесь. Надеюсь, ты понимаешь, о чем я?";
			link.l1 = "Понимаю, но-о-о.. Ты не уйдешь отсюда живым!!!";
			link.l1.go = "JoeBean_straight_man_fight";
			link.l2 = "Да, я все понял.";
			link.l2.go = "JoeBean_straight_man_nofight";
		break;
		
		case "JoeBean_straight_man_fight":
			AddDialogExitQuest("JoeBean_in_PortoBello_in_tavern_room_fight");
			DialogExit();
		break;
		
		case "JoeBean_straight_man_nofight":
			dialog.text = "Вот и славненько. А теперь, мне надо идти.";
			link.l1 = "...";
			link.l1.go = "JoeBean_straight_man_nofight_exit"
		break;
		
		case "JoeBean_straight_man_nofight_exit":
			AddDialogExitQuest("JoeBean_in_PortoBello_in_tavern_room_nofight");
			DialogExit();
		break;

// Бартоломье де мишор
		case "Bartolomie_first_meet":
			if(sti(pchar.rank)<5)
			{
				dialog.text = "Мне нужна компания на бутыль вина, но ты, парень, мне явно не подходишь!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Bartolomie_first_meet";
			}
			else
			{
				dialog.text = "Как поживаете, мсье? Не желаете выпить стаканчик вина?";
				link.l1 = "С удовольствием, в горле так пересохло, что я готов выпить бочку чего угодно!";
				link.l1.go = "Bartolomie_drink";
				link.l2 = "Нет, некогда мне.";
				link.l2.go = "Exit";
				NextDiag.TempNode = "Bartolomie_first_meet";
			}
		break;
		
		case "Bartolomie_drink":
			AddDialogExitQuest("TwoBrothers_Bartolomie_Start");
			NextDiag.CurrentNode = "Bartolomie_after_drink";
			DialogExit();
		break;
		
		case "Bartolomie_after_drink":
			dialog.text = "... Короче, славно мы тогда покутили. А ты, я смотрю, неплохой парень, выпить любишь, да и бабы, думаю, тебе не чужды, ха-ха-ха-ха! \nСлушай, а как ты смотришь на то, чтобы заработать пару-тройку пиастров?";
			link.l1 = "Заманчиво, но всё зависит от того, сколько людей надо грохнуть при этом, ха-ха-ха-ха! Да расслабься ты, шучу я. Давай, выкладывай, что у тебя там за дело, а там видно будет.";
			link.l1.go = "Bartolomie_after_drink_2";
		break;
		
		case "Bartolomie_after_drink_2":
			dialog.text = "Да дело-то нехитрое! Мой папаша недавно копыта откинул и оставил в наследство особнячок, и не где-нибудь, а в Форт-де-Франсе!";
			link.l1 = "Да, славный городишко, но жить я с тобой не собираюсь, как ты верно заметил - я больше по женщинам ходок, ха-ха-ха-ха!";
			link.l1.go = "Bartolomie_after_drink_3";
		break;
		
		case "Bartolomie_after_drink_3":
			dialog.text = "Да ну тебя! Дослушай сначала, а потом умничай! Не могу я въехать в своё новое гнездышко, да и домяра этот мне к дьяволу морскому не нужен! Продать я его хочу, да вот есть одна проблема...";
			link.l1 = "Э-э-э, брат, да ты не по адресу, я недвижимостью не занимаюсь, ха-ха-ха-ха!";
			link.l1.go = "Bartolomie_after_drink_4";
		break;
		
		case "Bartolomie_after_drink_4":
			dialog.text = "Святая Мария! Какого дьявола я грузил тебе полные кружки, видать на жаре тебя вино совсем разморило! \nЯ и без тебя его очень выгодно загоню, уже и покупатель есть, но дело в том, что есть у меня младший брат, Гастон, который, по завещанию покойного папаши, является владельцем этого дома не больше и не меньше чем я. \nТак вот, собственно, всё что от тебя требуется - это найти его и привезти ко мне, чтобы мы могли утрясти все формальности. \nЗа его успешные поиски я заплачу тебе 3000 пиастров. Ну, что скажешь?";
			link.l1 = "Не, ты не по адресу, я не занимаюсь поисками пропавших родственников. Спасибо за выпивку, мне пора, удачи!";
			link.l1.go = "Bartolomie_after_drink_exit";			
			link.l2 = "Сколько ты говоришь, 3000 пиастров? Ну что ж, попробую отыскать твоего братца.";
			link.l2.go = "Bartolomie_after_drink_take_quest";
			link.l3 = "Что-то 3000 маловато, давай 5000 и я отправлюсь на поиски немедленно!";
			link.l3.go = "Bartolomie_after_drink_more_money";
			
		break;
		
		case "Bartolomie_after_drink_exit":
			LAi_SetPlayerType(pchar);
			NextDiag.CurrentNode = "Bartolomie_after_drink2";
			DialogExit();
		break;
		
		case "Bartolomie_after_drink2":
			dialog.text = "Нам с тобой больше не о чем разговаривать.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_after_drink2";
		break;
		
		case "Bartolomie_after_drink_more_money":
			dialog.text = "Да пошел ты! За 5000 я могу нанять целую поисковую экспедицию! Эх, зря только вино на тебя потратил, проваливай, да поскорее!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_after_drink2";
			LAi_SetPlayerType(pchar);
		break;
		
		case "Bartolomie_after_drink_take_quest":
			dialog.text = "Вот и славно. Правда я понятия не имею, где он может ошиваться, но, зная характер своего братика, это наверняка какое-нибудь захолустье.";
			link.l1 = "Ладно, что-нибудь придумаю.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_start_find");
			NextDiag.TempNode = "Bartolomie_second_meet";
		break;
		
		case "Bartolomie_second_meet":
			dialog.text = "Ну, уважаемый, как успехи? Почему я не вижу с тобой Гастона?";
			link.l1 = "Я пока не нашел его...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_second_meet";
		break;
		
		case "Bartolomie_second_meet_real":
			dialog.text = "Ну, уважаемый, как успехи? Почему я не вижу с тобой Гастона?";
			link.l1 = "Я нашел его, но он, оказывается, ничего не знал о смерти вашего отца. Эта новость была для него, как гром среди ясного неба. Я сообщил о твоих планах относительно дома, но он наотрез отказался даже слушать о подобной перспективе.";
			link.l1.go = "Bartolomie_second_meet_real_1";
		break;
		
		case "Bartolomie_second_meet_real_1":
			dialog.text = "Я так и знал, что этот сопляк раскиснет, как барышня при виде трупа. У меня назад дороги нет, с людьми уже всё обговорено, дом уже почти их, осталось только получить согласие этого недомерка - и деньги у меня в руках. Где он сейчас?";
			link.l1 = "Я нашел его на Доминике, но после последнего нашего разговора он отправился на Мартинику.";
			link.l1.go = "Bartolomie_second_meet_real_2";
		break;
		
		case "Bartolomie_second_meet_real_2":
			dialog.text = "Ладно, в таком случае я сам отправлюсь к нему. Отвези меня и моих людей на Мартинику и там получишь свои 3000 пиастров, плюс 2000 сверху, за путешествие.";
			link.l1 = "Каких еще 'твоих людей'?";
			link.l1.go = "Bartolomie_second_meet_real_3";
		break;
		
		case "Bartolomie_second_meet_real_3":
			dialog.text = "Да я тут держу одну сапожную мастерскую, а парни - мои подмастерья. Одних их оставлять нельзя, того и гляди в тюрьму загремят, а мне новых стажеров набирать не с руки. \nДа, собственно, тебе какая разница? Я плачу - ты везешь, всё предельно просто.";
			link.l1 = "Ладно, но свои деньги я хочу получить как только мы причалим к Мартинике.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_Martinique");
			NextDiag.TempNode = "Bartolomie_second_meet_real_4";
		break;
		
		case "Bartolomie_second_meet_real_4":
			dialog.text = "Капитан, как только я допью эту кружку рома, сразу отправляюсь на корабль!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_second_meet_real_4";
		break;
		
		case "Bartolomie_in_Martinique_tavern":
			dialog.text = "А, это ты. Я тут поспрашивал местное население, Гастон целыми днями протирает колени на полу церкви, молясь за упокой нашего папаши. Если ты не против, давай наведаемся в церковь.";
			link.l1 = "Меня уже немного утомили ваши разборки с братом. Я хочу получить свои деньги, а ты уже сам разбирайся с ним.";
			link.l1.go = "Bartolomie_in_Martinique_tavern_1";
		break;
		
		case "Bartolomie_in_Martinique_tavern_1":
			dialog.text = "Да не суетись ты так, получишь ты свои деньги. Давай, идем, не отставай!";
			link.l1 = "Эй, постой...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_in_Martinique_church";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_Martinique_church");
		break;
		
		case "Bartolomie_in_Martinique_church":
			dialog.text = "Не, ну ты видел этого сумасшедшего?! Он в этом доме даже и жить не собирается, а продавать не хочет. Тысяча чертей! Как же мне его уговорить?";
			link.l1 = "Не знаю, это твои проблемы. Давай мне мои деньги здесь и сейчас, а со своим братом разбирайся сам.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "Хм... Быть может, есть способ продать дом без его согласия?";
			link.l2.go = "Bartolomie_in_Martinique_church_1";
		break;
		
		case "Bartolomie_in_Martinique_church_closequest":
			dialog.text = "Да что ты заладил, деньги-деньги... Нет у меня денег, продам дом - отдам, клянусь всеми святыми, а сейчас прощай, увидимся.";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_church_closequest");
		break;
		
		case "Bartolomie_in_Martinique_church_1":
			dialog.text = "Конечно есть! Если братишка отправится вслед за отцом, проблема снимается в два счета! Если ты устроишь ему свидание с родителями, я к твоим 5000 доплачу еще 10000 пиастров за неразумную голову своего брата.";
			link.l1 = "Деньги неплохие, но я в этом деле пас. Заплати мне мои 5000 пиастров и проваливай.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "Этот парень будет не первый, которого я отправлю на тот свет, так что - по рукам, но я хочу аванса в виде 5000 пиастров, которые ты мне и так должен.";
			link.l2.go = "Bartolomie_in_Martinique_church_3";
		break;
		
		case "Bartolomie_in_Martinique_church_3":
			dialog.text = "Сейчас таких денег у меня нет, но как только вопрос с братом будет улажен, я продам дом, - покупатели уже в городе, и сразу заплачу тебе, клянусь всеми святыми! Если ты согласишься, я готов заплатить даже вдвое больше, чем обещал! Подумай, это ни много ни мало, а 30000 пиастров! \nУверен, Гастон сейчас в нашем доме. Слуг там нет, он там один - это отличный шанс! Наш дом находится недалеко от магазина, удачи тебе.";
			link.l1 = "Без аванса я за это дело не возьмусь.";
			link.l1.go = "Bartolomie_in_Martinique_church_closequest";
			link.l2 = "Ладно, деньги неплохие, но если не рассчитаешься со мной, пеняй на себя!";
			link.l2.go = "Bartolomie_in_Martinique_church_4";
		break;
		
		case "Bartolomie_in_Martinique_church_4":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_to_house");
			DialogExit();
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead":
			dialog.text = "Ха! А ты парень не промах! Я в тебе не ошибся. Сегодня я улажу окончательно все дела с домом, завтра приходи в таверну, я с тобой рассчитаюсь.";
			link.l1 = "Отлично, до завтра.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie_in_Martinique_after_gastondead_nextday";
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead_nextday":
			dialog.text = "А, это ты, уважаемый. Рад видеть, рад.";
			link.l1 = "Я могу наконец получить свои деньги?";
			link.l1.go = "Bartolomie_in_Martinique_after_gastondead_nextday_fight";
		break;
		
		case "Bartolomie_in_Martinique_after_gastondead_nextday_fight":
			DoQuestCheckDelay("TwoBrothers_Bartolomie_in_Martinique_jungle_band", 0.1);
			dialog.text = "Я всегда любил выпить, а когда умерла моя мамаша, я начал любить МНОГО выпить. Папаша всегда больше возился с этим недомерком Гастоном, а до меня ему не было никакого дела. Карты - это второй мой порок после рома, ха-ха-ха-ха! \nТы представить себе не можешь, сколько денег я проиграл! Папаше пришлось хорошенько раскошелиться, чтобы кредиторы не выпустили кишки мне, а заодно и моему братцу. Но его денег хватило ненадолго и я опять залез в долги. Чтобы отработать свои, мне пришлось выбивать чужие и, скажу тебе честно, не всегда это заканчивалось мирно. \nЯ бы мог поручить своим людям сделать то, что сделал ты, но им пришлось бы платить, а вот тебе - нет, ха-ха-ха-ха! Это ж каким надо быть идиотом, чтобы поверить в то, что Бартоломье де Мишор возьмет и просто так отдаст 30 кусков какому-то проходимцу. Ребята, кончаем его!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_jungle_band_fight");
		break;
		
		case "Bartolomie_in_Martinique_fight":
			dialog.text = "Я всегда любил выпить, а когда умерла моя мамаша, я начал любить МНОГО выпить. Папаша всегда больше возился с этим недомерком Гастоном, а до меня ему не было никакого дела. Карты - это второй мой порок после рома, ха-ха-ха-ха! \nТы представить себе не можешь, сколько денег я проиграл! Папаше пришлось хорошенько раскошелиться, чтобы кредиторы не выпустили кишки мне, а заодно и моему братцу. Но его денег хватило ненадолго и я опять залез в долги. Чтобы отработать свои, мне пришлось выбивать чужие и, скажу тебе честно, не всегда это заканчивалось мирно. \nКак думаешь, тебе сойдет с рук долг, который теперь ты мне должен? Можешь долго не думать, я отвечу тебе - нет. С моим братом теперь уже разберутся мои люди. Жаль что ты не оправдал моих надежд. Ребята, кончаем его!";
			link.l1 = "...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_house_band_fight");
		break;
		
		case "Bartolomie2_first_meet":
			dialog.text = "Не мешай мне напиваться!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie2_first_meet";
		break;
		
		case "Bartolomie2_first_meet_after_church":
			dialog.text = "Садись, приятель, выпей со стариной Бартоломье!";
			link.l1 = "Бартоломье? Уж не де Мишор ли?";
			link.l1.go = "Bartolomie2_first_meet_after_church_1";
		break;
		
		case "Bartolomie2_first_meet_after_church_1":
			dialog.text = "Ха! Удивил... Да меня тут каждая собака знает!";
			link.l1 = "Рад за тебя, но я искал тебя по другому поводу. Твой брат, Гастон, разыскивает тебя.";
			link.l1.go = "Bartolomie2_first_meet_after_church_2";
		break;
		
		case "Bartolomie2_first_meet_after_church_2":
			dialog.text = "Гастон, говоришь? Интересно, что понадобилось этому сопляку, и почему он не обратился за помощью к своему папаше?";
			link.l1 = "Ты, неверное, не в курсе, но ваш отец умер...";
			link.l1.go = "Bartolomie2_first_meet_after_church_3";
		break;
		
		case "Bartolomie2_first_meet_after_church_3":
			dialog.text = "Умер?! Ха-ха-ха-ха, вот это новость! Наконец я смогу продать его дом и расплатиться с долгами! Ради такого события грех не повидаться с братом! Ладно, встречусь с ним. \nСпасибо  за новость, но пить с тобой я уже передумал, так что проваливай.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Bartolomie2_meet_in_church";
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie");
		break;
		
		case "Bartolomie2_meet_in_church":
			dialog.text = "Не, ну ты видел этого сумасшедшего?! Он в этом доме даже и жить не собирается, а продавать не хочет. Тысяча чертей! Как же мне его уговорить?";
			link.l1 = "Не знаю, это твои проблемы, со своим братом разбирайся сам.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "Хм... Быть может, есть способ продать дом без его согласия?";
			link.l2.go = "Bartolomie2_meet_in_church_2";
		break;
		
		case "Bartolomie2_meet_in_church_2":
			dialog.text = "Конечно есть! Если братишка отправится вслед за отцом, проблема снимается в два счета! Если ты устроишь ему свидание с родителями, я заплачу тебе 15000 за неразумную голову своего брата.";
			link.l1 = "Деньги неплохие, но я в этом деле пас.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "Этот парень будет не первый, которого я отправлю на тот свет, так что - по рукам, но я хочу аванса в виде 5000 пиастров.";
			link.l2.go = "Bartolomie2_meet_in_church_3";
		break;
		
		case "Bartolomie2_meet_in_church_3":
			dialog.text = "Сейчас таких денег у меня нет, но как только вопрос с братом будет улажен, я продам дом, - покупатели уже в городе, и сразу заплачу тебе, клянусь всеми святыми! \nЕсли ты согласишься, я готов заплатить даже вдвое больше, чем обещал! Подумай, это ни много ни мало, а 30000 пиастров! Уверен, Гастон сейчас в нашем доме. Слуг там нет, он там один - это отличный шанс!";
			link.l1 = "Без аванса я за это дело не возьмусь.";
			link.l1.go = "Bartolomie2_meet_in_church_exit_noquest";
			link.l2 = "Ладно, деньги неплохие, пойду проведаю твоего брата...";
			link.l2.go = "Bartolomie2_meet_in_church_exit_quest";
		break;
		
		case "Bartolomie2_meet_in_church_exit_quest":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_curch_quest");
			NextDiag.CurrentNode = "Bartolomie2_meet_in_house";
			DialogExit();
		break;
		
		case "Bartolomie2_meet_in_church_exit_noquest":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_curch_close_quest");
			DialogExit();
		break;
		
		case "Bartolomie2_meet_in_house":
			dialog.text = "Ха! А ты парень не промах! Я в тебе не ошибся.";
			link.l1 = "Я могу получить свои деньги?";
			link.l1.go = "Bartolomie2_meet_in_house_2";
		break;
		
		case "Bartolomie2_meet_in_house_2":
			dialog.text = "Я всегда любил выпить, а когда умерла моя мамаша, я начал любить МНОГО выпить. Папаша всегда больше возился с этим недомерком Гастоном, а до меня ему не было никакого дела. \nКарты - это второй мой порок после рома, ха-ха-ха-ха! Ты представить себе не можешь, сколько денег я проиграл! Папаше пришлось хорошенько раскошелиться, чтобы кредиторы не выпустили кишки мне, а заодно и моему братцу. \nНо его денег хватило ненадолго и я опять залез в долги. Чтобы отработать свои, мне пришлось выбивать чужие и, скажу тебе честно, не всегда это заканчивалось мирно. \nЯ бы мог поручить своим людям сделать то, что сделал ты, но им пришлось бы платить, а вот тебе - нет, ха-ха-ха-ха! Это ж каким надо быть идиотом, чтобы поверить в то, что Бартоломье де Мишор возьмет и просто так отдаст 30 кусков какому-то проходимцу. Ребята, кончаем его!";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
		case "Bartolomie2_meet_in_house_3":
			dialog.text = "Я всегда любил выпить, а когда умерла моя мамаша, я начал любить МНОГО выпить. Папаша всегда больше возился с этим недомерком Гастоном, а до меня ему не было никакого дела. \nКарты - это второй мой порок после рома, ха-ха-ха-ха! Ты представить себе не можешь, сколько денег я проиграл! Папаше пришлось хорошенько раскошелиться, чтобы кредиторы не выпустили кишки мне, а заодно и моему братцу. Но его денег хватило ненадолго и я опять залез в долги. Чтобы отработать свои, мне пришлось выбивать чужие и, скажу тебе честно, не всегда это заканчивалось мирно. \nКак думаешь, тебе сойдет с рук долг, который теперь ты мне должен? Можешь долго не думать, я отвечу тебе - нет. С моим братом теперь уже разберутся мои люди. Жаль что ты не оправдал моих надежд. Ребята, кончаем его!";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
// Гастон де Мишор
		case "Gaston_first_meet":
			if(sti(pchar.rank)<5)
			{
				dialog.text = "Я без ума от этого городка - тишина, спокойствие, знали бы вы, как долго я искал подобное местечко!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Gaston_first_meet";
			}
			else
			{
				dialog.text = "Я не очень рад новым лицам в городе, меня устраивает то, что здесь так мало людей, но тенденция к появлению новых поселенцев меня беспокоит!";
				link.l1 = "...";
				link.l1.go = "Exit";
				NextDiag.TempNode = "Gaston2_2_meet";
			}
		break;
		
		// Диалог после встречи со старшим братом
		case "Gaston_first_meet_after_meet_with_Bartolomie":
			dialog.text = "Да, мсье, вы что-то хотели?";
			link.l1 = "Я здесь по поручению твоего старшего брата, Бартоломье...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_1";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_1":
			dialog.text = "О! В таком случае я искренне рад вас видеть, мсье! Знаете, я так давно не видел своего брата, что безумно по нему соскучился. Но я понятия не имею где он находится, хотел уже отправиться на поиски, а тут появились вы и говорите, что прибыли по его поручению... Это же великолепно! \nКак дела у Бартоломье, все так же пьет, гуляет и играет в карты? Хотя можете не отвечать, я и так знаю, своего брата-баламута, не пойму, как отец с ним справляется... \nОй... Что-то я заговорился совсем, так вы говорите, что братишка мой хочет мне что-то передать?";
			link.l1 = "Твой брат хочет обсудить с тобой продажу дома вашего покойного отца...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_2";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_2":
			dialog.text = "Что?! Как, покойного?!! Какой ужас!!! Как давно это случилось? Отчего он умер? Умоляю вас, не молчите!";
			link.l1 = "Судя по всему, умер он не вчера, но подробностей последних дней его жизни я не знаю, так что на эти вопросы ответить тебе не смогу...";
			link.l1.go = "Gaston_first_meet_after_meet_with_Bartolomie_3";
		break;
		
		case "Gaston_first_meet_after_meet_with_Bartolomie_3":
			dialog.text = "Какой кошмар! Какой кошмар!!! Отец, любимый отец ушел из жизни, а я даже не попрощался с ним! Я никогда себе этого не прощу! \nИзвините, я сейчас не в силах разговаривать, давайте встретимся завтра и продолжим разговор, а сейчас мне надо побыть наедине со своим горем...";
			link.l1 = "Да, но...";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_wait_one_day");
			NextDiag.TempNode = "Gaston_after_bad_news";
		break;
		
		case "Gaston_after_bad_news":
			dialog.text = "Извините, но мне сейчас не до вас...";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston_after_bad_news";
		break;
		
		case "Gaston_tomorrow":
			dialog.text = "А, это вы месье. Я еле справляюсь с болью утраты, которая глубоко проникла мне в душу. Вчера вы что-то говорили о Бартоломье...";
			link.l1 = "Да, он попросил найти тебя и привезти к нему в Порт-о-Пренс, чтобы вы могли обсудить детали продажи вашего дома на Мартинике.";
			link.l1.go = "Gaston_tomorrow_1";
		break;
		
		case "Gaston_tomorrow_1":
			dialog.text = "Продажи дома, где всё напоминает о нашем покойном отце?! Никогда в жизни! Об этом не может быть и речи!!! Так ему и передайте! А я немедленно отправляюсь домой. Если бы вы знали, как я хочу узнать о подробностях последних дней жизни покойного папеньки.";
			link.l1 = "Что ж, всего хорошего.";
			link.l1.go = "Exit";
			AddDialogExitQuest("TwoBrothers_Bartolomie_to_PortPrince");
			NextDiag.TempNode = "Gaston_second_meet_after_meet_with_Bartolomie";
		break;
		
		case "Gaston_second_meet_after_meet_with_Bartolomie":
			dialog.text = "А, это вы... По вашему лицу я догадываюсь, зачем вы здесь. Сколько бы вам не обещал мой брат за мою голову, я хочу чтобы вы знали - Бартоломье не тот человек, который платит по счетам. Денег у него нет, и никогда не было. Я не дам согласия на продажу дома, но если вы меня отпустите, я заплачу вам 5000 пиастров прямо сейчас.";
			link.l1 = "Это у него сейчас нет денег, а продаст дом - появятся, так что давай-ка, молись.";
			link.l1.go = "Gaston_second_meet_kill";
			link.l2 = "Странный ты человек! Может, я чего-то и не понимаю... В общем, давай сюда деньги и проваливай, к чертям собачьим!";
			link.l2.go = "Gaston_second_meet_nokill";
		break;
		
		case "Gaston_second_meet_kill":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_kill_Gaston");
			DialogExit();
		break;
		
		case "Gaston_second_meet_nokill":
			AddDialogExitQuest("TwoBrothers_Bartolomie_in_Martinique_house_not_kill");
			DialogExit();
		break;
		
		case "Gaston2_2_meet":
			dialog.text = "Знали бы вы, уважаемый, как поначалу здесь было тихо и спокойно! Как вы говорите вас зовут?";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_3_meet";
		break;
		
		case "Gaston2_3_meet":
			dialog.text = "А, это вы, мсье "+pchar.name+". Рад вас видеть!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_4_meet";
		break;
		
		case "Gaston2_4_meet":
			dialog.text = "Что-то последнее время у меня на душе неспокойно, какое-то дурное предчувствие не дает мне покоя!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_5_meet";
		break;
		
		case "Gaston2_5_meet":
			dialog.text = "О! мсье"+pchar.name+", снова вы! Какая удача! Я как раз ищу капитана. У меня есть брат - Бартоломье, я его давно не видел, а последнее время меня беспокоит какое-то непонятное ощущение, как будто что-то случилось с моими родными. \nВот я и решил наведаться к отцу, проведать его, да и брата повидать, хотя не уверен, что он дома, его постоянно где-то нелегкая носит. Если вы доставите меня в Форт-де-Франс, я заплачу вам 3000 пиастров.";
			link.l1 = "С удовольствием помог бы тебе, но у меня дел много, так что извини.";
			link.l1.go = "Exit";
			link.l2 = "А почему бы и нет? Добро пожаловать на борт!";
			link.l2.go = "Gaston2_exit_accept_quest";
			NextDiag.TempNode = "Gaston2_5_meet";
		break;
		
		case "Gaston2_exit_accept_quest":
			NextDiag.CurrentNode = "Gaston2_second_meet";
			AddDialogExitQuest("TwoBrothers_Gaston_begin");
			DialogExit();
		break;
		
		case "Gaston2_second_meet":
			dialog.text = "Я так рад, что вы согласились мне помочь!";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_second_meet";
		break;
		
		case "Gaston2_second_meet_Martinique":
			dialog.text = "Мсье "+pchar.name+", вы не представляете, какое горе пронзило моё сердце! Мои предчувствия меня не обманули! Отец, мой любимый отец отошел в мир иной, а я даже не успел с ним попрощаться! Я никогда себе этого не прощу, никогда!";
			link.l1 = "Прими мои соболезнования.";
			link.l1.go = "Gaston2_second_meet_Martinique_1";
		break;
		
		case "Gaston2_second_meet_Martinique_1":
			AddMoneyToCharacter(pchar, 3000);
			AddPartyExp(pchar, 100);
			
			dialog.text = "Ах да, чуть не забыл, вот ваша оплата. Вы уж извините, но с этой новостью у меня все напрочь из головы вылетело! Теперь у меня остался только брат. Помогите мне отыскать его, умоляю вас, и я заплачу вам еще 3000!";
			link.l1 = "Нет, у меня своих дел хватает. Извини.";
			link.l1.go = "Gaston2_second_meet_Martinique_no_quest";
			link.l2 = "Я помогу тебе. Где он может быть?";
			link.l2.go = "Gaston2_second_meet_Martinique_2";
		break;
		
		case "Gaston2_second_meet_Martinique_no_quest":
			NextDiag.CurrentNode = "Gaston2_third_meet_Martinique_no_quest";
			AdddialogExitQuest("TwoBrothers_Gaston_on_Martinique_no_quest");
			DialogExit();
		break;
		
		case "Gaston2_third_meet_Martinique_no_quest":
			dialog.text = "Оставьте меня на едине с моим горем...";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_third_meet_Martinique_no_quest";
		break;
		
		case "Gaston2_second_meet_Martinique_2":
			dialog.text = "Понятия не имею, но, зная характер своего брата, могу с уверенностью сказать, что он сейчас, впрочем как и всегда, пьет и проигрывает деньги, которых у него нет.";
			link.l1 = "Негусто... Что ж, попробую его отыскать.";
			link.l1.go = "Gaston2_second_meet_Martinique_3";
		break;
		
		case "Gaston2_second_meet_Martinique_3":
			dialog.text = "Удачи вам, капитан, а я пойду в церковь, помолюсь за упокой души отца.";
			link.l1 = "...";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_meet_Martinique_church";
			AddDialogExitQuest("TwoBrothers_Gaston_to_PortPrenc");
		break;
		
		case "Gaston2_meet_Martinique_church":
			dialog.text = "А, это вы, капитан, вот ваша награда, спасибо, что разыскали брата. Мне пора, всего доброго.";
			link.l1 = "Да, в общем-то, не за что.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_after_meet_Martinique_church";
		break;
		
		case "Gaston2_after_meet_Martinique_church":
			dialog.text = "А, это вы... По вашему лицу я догадываюсь, зачем вы здесь. Сколько бы вам не обещал мой брат за мою голову, я хочу чтобы вы знали - Бартоломье не тот человек, который платит по счетам. Денег у него нет, и никогда не было. \nЯ не дам согласия на продажу дома, но если вы меня отпустите, я заплачу вам 5000 пиастров прямо сейчас.";
			link.l1 = "Это у него сейчас нет денег, а продаст дом - появятся, так что давай-ка, молись.";
			link.l1.go = "Gaston2_after_meet_Martinique_church_kill";
			link.l2 = "Странный ты человек! Может, я чего-то и не понимаю... В общем, давай сюда деньги и проваливай, к чертям собачьим!";
			link.l2.go = "Gaston2_after_meet_Martinique_church_no_kill";
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill":
			NextDiag.CurrentNode = "Gaston2_after_meet_Martinique_church_no_kill_1";
			AddDialogExitQuest("TwoBrothers_Gaston_in_Martinique_no_kill_Gaston");
			DialogExit();
		break;
		
		case "Gaston2_after_meet_Martinique_church_kill":
			AddDialogExitQuest("TwoBrothers_Gaston_after_meet_with_Bartolomie_in_house");
			DialogExit();
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill_1":
			dialog.text = "Я весьма сожалею, что вам пришлось принять участие во всем этом, но я рад, что вы подарили мне жизнь. Эх, Бартоломье, Бартоломье... Я знал, что он плохо кончит, но я и подумать не мог, что в городе, где мы вместе выросли, его прибьют, как бешеную собаку...";
			link.l1 = "Да, нехорошо как-то получилось. Ну, как бы там ни было, а мне пора. Надеюсь, что после произошедшего, ты все же сможешь обрести душевный покой.";
			link.l1.go = "Gaston2_after_meet_Martinique_church_no_kill_2";
		break;
		
		case "Gaston2_after_meet_Martinique_church_no_kill_2":
			dialog.text = "Да уж, хотелось бы... Но, слава Богу, мне не придется никому ничего объяснять. Оказывается личность моего брата небезызвестна французским властям. Мсье "+pchar.lastname+" я всегда буду рад видеть вас у себя в гостях. Если вам когда-нибудь понадобится крыша над головой - не стесняйтесь, заходите.";
			link.l1 = "Что ж, это хорошая новость, спасибо, но я постараюсь не злоупотреблять вашим гостеприимством.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "Gaston2_sleep";
		break;
		
		case "Gaston2_sleep":
			dialog.text = "О! Мсье "+pchar.lastname+"! Чем обязан вашему визиту?";
			link.l1 = "Я бы хотел остановиться у тебя на некоторое время.";
			link.l1.go = "Gaston2_sleep_1";
			link.l2 = "Да просто шел мимо, думаю - дай зайду.";
			link.l2.go = "Exit";
			NextDiag.TempNode = "Gaston2_sleep";
		break;
		
		case "Gaston2_sleep_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			dialogExit();
			//LaunchSleep();
		break;
		
		// Человек Бартоломье
		case "two_brothers_man":
			dialog.text = "Слышал, ты интересуешься нашим боссом? Так вот, он ждет тебя за городом. Иди в сторону порта, перед выходом в порт поварачивай направо, за городскими воротами мсье Бартоломье ждет тебя.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;
		
//	-----------------------------------------------------------------------------------------------------------------------
//	трусливый Томас
		case "TohmasPetit_1":
			dialog.text = "Здравствуйте, уважаемый. Я вижу вы при оружии, да и выглядите как бывалый воин...";
			link.l1 = "Да, ты не ошибся, я многое повидал на своем веку.";
			link.l1.go = "TohmasPetit_2";
		break;
		
		case "TohmasPetit_2":
			dialog.text = "Мне срочно нужна помощь такого человека, как вы!";
			link.l1 = "Что случилось, приятель?";
			link.l1.go = "TohmasPetit_3";
		break;
		
		case "TohmasPetit_3":
			dialog.text = "Я с девушкой гулял у городских ворот, но вдруг на нас напали бандиты! Я еле ноги унес, а она осталась там с ними. Помогите, умоляю вас! У меня очень богатые родители, я как следует отблагодарю, не сомневайтесь.";
			link.l1 = "Хорошо, идём и покажем этим недоноскам!";
			link.l1.go = "TohmasPetit_4";
			link.l2 = "Оставить девушку одну в беде? Да я даже стоять рядом с тобой не хочу, пошёл вон.";
			link.l2.go = "TohmasPetit_5";
		break;
		
		case "TohmasPetit_5":
			NextDiag.CurrentNode = "TohmasPetit_6";
			AddDialogExitQuest("TomasQuest_no");
			DialogExit();
		break;
		
		case "TohmasPetit_6":
			dialog.text = "А, это ты, мне некогда!";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "TohmasPetit_6";
		break;
		
		case "TohmasPetit_4":
			NextDiag.CurrentNode = "TohmasPetit_7";
			AddDialogExitQuest("TomasQuest_yes");
			DialogExit();
		break;
		
		//	Бандиты
		case "TohmasPetitBandit_1":
			dialog.text = "А это что за пижон тут у нас?";
			link.l1 = "Отпустите девушку и, возможно, вы останетесь в живых.";
			link.l1.go = "TohmasPetitBandit_2";
		break;
		
		case "TohmasPetitBandit_2":
			dialog.text = "Смотрите, этот щенок нам угрожает. Давайте немного развлечемся и просто убьём его.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			AddDialogExitQuest("TomasQuest_fight");
		break;
		
		//	Девка
		case "TohmasPetitGirl_1":
			dialog.text	= "Спасибо вам, добрый человек...";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			NextDiag.TempNode = "TohmasPetitGirl_2";
		break;
		
		case "TohmasPetitGirl_2":
			dialog.text = "Этот человек угрожал мне и хотел меня похитить, когда мы встретили этих людей, я попросила у них помощи, но он всех их убил.";
			link.l1 = "Какого дьявола?! Ты, что, с ума сошла?! Да если бы не я то...";
			link.l1.go = "Exit";
		break;
		
		//	Солдат
		case "TohmasPetitSoldier_1":
			dialog.text = "Так, что здесь происходит?";
			link.l1 = "Да вот, эти четверо...";
			link.l1.go = "Exit":
			
			NextDiag.TempNode = "TohmasPetitSoldier_2";
		break;
		
		case "TohmasPetitSoldier_2":
			dialog.text = "Заткнись и следуй за нами, а там разберемся.";
			link.l1 = "Ага, это уже не я там, в тюрьме гнию? Ну-ка, парни, давайте-ка посмотрим, из какого теста вы сделаны!";
			link.l1.go = "TohmasPetitSoldier_fight";
			link.l2 = "Ладно, ладно, идем.";
			link.l2.go = "TohmasPetitSoldier_prison";
		break;
		
		case "TohmasPetitSoldier_fight":
			DialogExit();
			AddDialogExitQuest("TomasQuest_soldiers_fight");
		break;
		
		case "TohmasPetitSoldier_prison":
			DialogExit();
			AddDialogExitQuest("TohmasPetitSoldier_go_prison");
		break;
		
		//	Офицер
		case "TohmasPetitOfficer_1":
			dialog.text = "Капитан, ты сейчас в таком щекотливом положении, что я на твоем месте начал бы исповедоваться еще до прихода священника.";
			link.l1 = "Что, все так плохо?";
			link.l1.go = "TohmasPetitOfficer_2";
		break;
		
		case "TohmasPetitOfficer_2":
			dialog.text = "На тебе, парень, висит убийство четырех человек, и попытка похищения девушки, но я могу 'замять' это дело. Надеюсь, ты понимаешь, о чем я?";
			link.l1 = "О какой сумме идет речь?";
			link.l1.go = "TohmasPetitOfficer_3";
		break;
		
		case "TohmasPetitOfficer_3":
			dialog.text = "Ну, скажем, 10000 пиастров.";
			if(sti(pchar.money)>=10000)
			{
				link.l1 = "Похоже, выбора у меня нет. Я готов заплатить.";
				link.l1.go = "TohmasPetitOfficer_money";
			}
			link.l2 = "У меня нет таких денег.";
			link.l2.go = "TohmasPetitOfficer_executon";
			
		break;
		
		case "TohmasPetitOfficer_money":
			DialogExit();
			AddDialogExitQuest("TohmasPetitSoldier_free");
		break;
		
		case "TohmasPetitOfficer_executon":
			dialog.text = "Ну, как знаешь. Сегодня вечером придет священник, а завтра на рассвете тебя расстреляют.";
			link.l1 = "...";
			link.l1.go = "Exit";
			
			AddDialogExitQuest("TohmasPetitSoldier_execution");
		break;
*/		
		case "Exit":
			if (CheckAttribute(NextDiag,"TempNode")) NextDiag.CurrentNode = NextDiag.TempNode; //[ds] changed
			DialogExit();
		break;
	}
}