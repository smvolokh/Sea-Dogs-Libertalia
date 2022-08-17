// Дэвид Смит и шушара всякая
void ProcessDialogEvent()
{
	ref NPChar, sld, sld1;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		

	case "First time":
		if (pchar.questTemp.GothicSmithy == "Smithy_DavidSmith")
		{
	Locations[FindLocation("FortOrange_tavern")].reload.l2.disable = true;
            	dialog.text = "А, " + GetAddress_Form(NPChar) + " " + PChar.name + ", наконец-то. Честно говоря, я вас заждался.";
        	link.l1 = "Ну что же, прошу меня простить. Теперь давайте к делу.";
        	link.l1.go = "2";
        	link.l2 = "Рад, наконец, познакомиться с вами по ближе, Мистер Смит. Я о вас наслышан.";
        	link.l2.go = "3";
			sld.talker = 0;
		}
		else
		{
			int iPhrase_GothicSmithy = rand(1);
			switch (iPhrase_GothicSmithy)
			{
			case 0:
            		dialog.text = "Кредиты, депозиты, ценные бумаги, облигации... Это все так интересно.";
        		link.l1 = "Никогда бы не подумал.";
        		link.l1.go = "Exit";
			break;

			case 1:
            		dialog.text = "Заниамться банковским делом - это выгодно! Задумайтесь об этом...";
        		link.l1 = "Как будет свободное время...";
        		link.l1.go = "Exit";
			break;			
			}
		}
		break;

 		case "Exit":
                                          NextDiag.CurrentNode = "Fist time";
		DialogExit();
		break;

	case "2":
            	dialog.text = "Хм, " + GetAddress_Form(NPChar) + " " + PChar.name + ", у вас деловая хватка. Собственно поэтому вы и здесь. Два деловых человека вместе могут вершить великие дела, это совершенно точно. А мне-то нужно гораздо менее громкое свершение - просто решить проблему одного человека. Навсегда решить.";
        	link.l1 = "Так чем же я могу вам помочь, мистер Смит?";
        	link.l1.go = "4";
	break;

	case "3":
            	dialog.text = "О, " + GetAddress_Form(NPChar) + " " + PChar.name + ", я весьма польщён. Уверен, вы не пожалеете о нашей встрече. Дэвид Смит и "+ GetFullName(Pchar)+" - у нашего тандема великолепное будущее.";
        	link.l1 = "Так чем же я могу вам помочь, мистер Смит?";
        	link.l1.go = "4";
	break;

	case "4":
            	dialog.text = "Всё очень просто,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Я плачу вам фантастические деньги, скажем, 1 000 000 песо, а вы выслеживаете и ликвидируете даму по имени Крошимер Говард. Поиски следует начать на Кюрасао, возможно они там же и окончатся. Возьмётесь,  " + GetAddress_Form(NPChar) + " " + PChar.name + "?";
        	link.l1 = "Сколько - сколько? Один миллион? Похоже на действительно выгодное предложение. Я берусь.";
        	link.l1.go = "5";
        	link.l2 = "Мне нужно знать больше о цели, мистер Смит, чтобы решить.";
        	link.l2.go = "6";
        	link.l3 = "Боюсь дальше наши пути расходятся. Простите, мистер Смит, но я не убийца. Ищите другого палача. Прощайте.";
        	link.l3.go = "Smithy End";
	break;

 		case "Smithy End":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_44.wav");
		if (pchar.questTemp.GothicSmithy == "Smithy_DavidSmith")
		{
    		AddQuestRecord("Gothic_Smithy", "3");
		CloseQuestHeader("Smithy");
		PChar.quest.Smithy_David_End.win_condition.l1 = "ExitFromLocation";
		PChar.quest.Smithy_David_End.win_condition.l1.location = PChar.location;
		PChar.quest.Smithy_David_End.win_condition = "Gothic_Smithy_End";
		}
                                      NextDiag.CurrentNode = "End time";
		DialogExit();
		break;

	case "End time":
            	dialog.text = "Нам больше не о чем говорить,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Прошу вас покинуть мою комнату.";
        	link.l1 = "Уже ухожу.";
        	link.l1.go = "Smithy End";
		break;

		case "5":
            	dialog.text = "Великолепно,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Отправляйтесь на Кюрасао и наведите справки. Затем выполните работу, если это будет возможно и возвращайтесь. Если же цели не окажется на острове, то продолжайте поиски. Меня не интересуют поиски, меня интересует только устранение цели. Как только она будет устранена - с вами свяжутся. В качестве аванса даю вам 300 000 тысяч песо.";
        	link.l1 = "Всё будет в порядке, мистер Смит. Я отправляюсь.";
        	link.l1.go = "Smithy_G";
		break;

		case "6":
            	dialog.text = "Нет,  " + GetAddress_Form(NPChar) + " " + PChar.name + ", так дело не пойдёт. Я - заказчик, вы - исполнитель. Всё, что вам нужно знать, вам было сказано. Выбор за вами.";
        	link.l1 = "Хорошо, мистер Смит, я всё понял. Последние указания?";
        	link.l1.go = "5";
        	link.l2 = "Что ж, тогда прощайте. Ищите другого палача.";
        	link.l2.go = "Smithy End";
		break;


 		case "Smithy_G":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "...";
        	                   link.l1.go = "Go To Curacao"; 
		break;

 		case "Go To Curacao":
                                        PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
    	                   AddQuestRecord("Gothic_Smithy", "4");
	                   ChangeCharacterComplexReputation(pchar, "nobility", -20); 
                                        AddMoneyToCharacter(pchar, 300000);
	                   log_info("получен аванс 300 000");   

		PChar.quest.Smithy_David_Start.win_condition.l1 = "ExitFromLocation";
		PChar.quest.Smithy_David_Start.win_condition.l1.location = PChar.location;
		PChar.quest.Smithy_David_Start.win_condition = "Gothic_Smithy_Start";
                                       NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;

	                  case "Second Time":
            	                  dialog.text = "Вы всё ещё здесь,  " + GetAddress_Form(NPChar) + " " + PChar.name + "? Может вам лучше начать поиски Крошимер?";
        	                   link.l1 = "Я уже работаю над этим.";
        	                   link.l1.go = "Second Time Exit";
	                   break;

 		case "Second Time Exit":
                                          NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;


// в таверне Сент-Луи

	case "SmithyDavid_SantLous":
            	dialog.text = "А,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Полагаю, возникли некоторые трудности, не так ли?";
        	link.l1 = "Да, мистер Смит. И у меня накопилось несколько вопросов к вам.";
        	link.l1.go = "8";
        	link.l2 = "Крошимер Говард мертва. Я хотел бы получить мои деньги.";
        	link.l2.go = "10";
	break;

	case "8":
            	dialog.text = "Боюсь, я не планировал отвечать вам на них сейчас,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Вы узнаете, всё, что нужно вам, когда это будет нужно мне.";
        	link.l1 = "Я не совсем точно представляю, кого я убил. А ещё меня пытались убить в Саванне-ла-Мар. Возможно, вы соизволите объяснить мне эти две простые ситуации?";
        	link.l1.go = "9";
	break;

	case "9":
            	dialog.text = "Ну что же, пусть будет так. Вы убили Августу, родную сестру моей жены. В Саванне-ла-Мар, на вас, вероятно, напали люди моей жены.";
        	link.l1 = "Вашей жены?";
        	link.l1.go = "11";
	break;

	case "10":
            	dialog.text = "Боюсь, вы не заслужили ваши деньги,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Пока не заслужили. Вы убили не Крошимер Говард, а Августу Говард, родную сестру моей жены.\nВ Саванне-ла-Мар на вас, как я понимаю, напали - это также были люди моей жены.";
        	link.l1 = "Вашей жены?";
        	link.l1.go = "11";
	break;

	case "11":
            	dialog.text = "Да, моей жены, Кэрол. Её полное имя Кэрол Крошимер Смит. Говарды, это семья её сестры и заодно подставная фамилия для мокрой части бизнеса Кэрол.";
        	link.l1 = "Так, подождите, я не понимаю - кого я должен был убить?";
        	link.l1.go = "12";
	break;

	case "12":
            	dialog.text = "Мистер " + PChar.name + ", не нервничайте, прошу вас. Всё очень просто. Вы убили Августу,  это было что-то вроде последней проверки ваших способностей, а плюс к тому, я неплохо разозлил Кэрол.\nТеперь же вы должны убить её саму, мою жену - Кэрол.";
        	link.l1 = "Но зачем вам убивать вашу жену? И почему её люди напали на меня?";
        	link.l1.go = "13";
	break;

	case "13":
            	dialog.text = "Ну, почему они напали на вас - по-моему, это довольно очевидно. Вы убили сестру Кэрол.\nТеперь она жаждет кровной мести и вашей смерти соответственно. К сожалению, она знает, что вы, в свою очередь, желаете её кончины - это несколько осложняет дело, но я уверен, что вы справитесь.";
        	link.l1 = "Подождите-подождите, я не хотел и не хочу ни чьей смерти! Вы наняли меня, чтобы я убил женщину по имени Крошимер Говард и я это сделал!";
        	link.l1.go = "14";
	break;

	case "14":
            	dialog.text = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+", вы будто меня не слушаете. Вы убили Августу, а не Крошимер, теперь вам нужно убить Крошимер, она же - Кэрол.\nПо сути ничего не изменилось, я нанял вас, чтобы убить даму, и вам всё ещё нужно убить даму. Я нахожу это романтичным.";
        	link.l1 = "А я нет. Я хочу мои деньги прямо здесь и сейчас и на этом мы закончим наше сотрудничество! Я выполнил то, о чём вы просили меня.";
        	link.l1.go = "15";
	break;

	case "15":
            	dialog.text = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+", послушайте, я не советую вам ссориться со мной. Хорошо, я объясню вам некоторые вещи.\nМы с Кэрол были владельцами крупной банковой сети здесь, на Карибах. Проценты, кредиты, взносы... золото текло реками. Его можно было собирать вёдрами.\nМы были одними из самых богатых предпринимателей на Карибах, возможно самыми богатыми, а возможно, и одними из богатейших во всём мире.\nНо... некоторое время назад произошёл раскол. Кэрол начала тянуть одеяло на себя. Она хотела больше половины, которую она получала.\nОна хотела, чтобы всем владела она, а я лишь довольствовался процентами. Но меня это не устроило! Мы поссорились. И мы, как бы вам сказать... серьёзно поссорились.\nДело не в личных отношениях, она шикарная женщина и ей не было равных в постели, уж поверьте мне, " + GetAddress_Form(NPChar) + " " + PChar.name + ", я-то знаю, что такое настоящие женщины.\nДело в деньгах. Это большой и серьёзный бизнес и я не хочу терять своих позиций в нём из-за её прихотей. Она всё тоже прекрасно понимает, просто она хочет ещё больше золота, она хочет купаться в нём.\nЛюди называют нас ростовщиками, но на деле они нам завидуют, ведь банкиры - одни из самых богатых людей на архипелаге. В общем, " + GetAddress_Form(NPChar) + " " + PChar.name + ", всё сложно и всё серьёзно - но вас это не должно заботить.\nВедь для вас условия простые. Убейте Кэрол и сделайте меня самым богатым человеком на архипелаге - тогда я сделаю вас самым богатым капитаном в истории судоходства.";
        	link.l1 = "А если я откажусь?";
        	link.l1.go = "16";
	break;

	case "16":
            	dialog.text = "Вы поступите довольно глупо, ведь, вы уже в игре, и выйти из неё вам теперь будет достаточно сложно.\nКэрол охотится на вас, а если я разочаруюсь в вас, кто знает, вдруг и мне придёт в голову такая странная идея?\nВы ведь не думаете, что сможете противостоять двум могущественным банкам, " + GetAddress_Form(NPChar) + " " + PChar.name + "?\nЯ знаю, вы умны, поэтому вы согласитесь.";
        	link.l1 = "Что ж, пожалуй, вы правы, у меня теперь нет выбора. Я убью вашу жену, но как только я сделаю это и получу свои деньги, надеюсь, вы больше никогда не напомните мне о себе. Знакомство с вами не будет приятным воспоминанием для меня.";
        	link.l1.go = "17";
	break;

	case "17":
            	dialog.text = "Я мог бы сочти это за оскорбление, " + GetAddress_Form(NPChar) + " " + PChar.name + ", поэтому советую вам несколько утихомирить свой язык, ведь я ещё раз напоминаю вам - вы работаете на серьёзного человека.\nНо, тем не менее, вы правы - выполните свою часть сделки - я выполню свою.";
        	link.l1 = "Где мне теперь искать Кэрол?";
        	link.l1.go = "18";
	break;

	case "18":
            	dialog.text = "Хороший вопрос, " + GetAddress_Form(NPChar) + " " + PChar.name + ". Я мог бы послать вас вновь самому всё вынюхивать и расследовать, но я ведь деловой человек, да и вы тоже - пока вы отсутствовали - я обновил свои источники и знаю, где сейчас находится Кэрол.\nОна скрывается в доме в Ле Француа, на Мартинике. Отправляйтесь туда немедленно и решите проблему Кэрол навсегда.";
        	link.l1 = "Я понял вас, мистер Смит. Я отправляюсь. Кстати вам имя Ворон ни о чём не говорит...";
        	link.l1.go = "19";
	break;

	case "19":
            	dialog.text = "Ворон, да я слышал о нём, помоему сестра Кэрол, Августа была любовницей этого Ворона.";
        	link.l1 = "Вот как, понятно...";
        	link.l1.go = "20";
	break;

	case "20":
            	dialog.text = "Да, " + GetAddress_Form(NPChar) + " " + PChar.name + ", и ещё одно. Если у вас будет такая возможность, перед тем как убить её, пожалуйста, передайте ей, что я любил её.";
        	link.l1 = "Эмм... Хорошо, я вас понял. До свидания.";
        	link.l1.go = "Go To Antigua";
	break;

 	case "Go To Antigua":
	pchar.questTemp.GothicSmithy = "Smithy_LeFransuaTavern";
    	AddQuestRecord("Gothic_Smithy", "9");
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	break;

	case "Third Time":
            	dialog.text = "Берите курс на Мартинику, " + GetAddress_Form(NPChar) + " " + PChar.name + ", хватит прохлаждаться. Работа ждёт.";
        	link.l1 = "Уже отплываю.";
        	link.l1.go = "Third Time Exit";
	break;

 	case "Third Time Exit":
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	break;

	case "IslaMonaShore":
            	dialog.text = "А, " + GetAddress_Form(NPChar) + " " + PChar.name + "! Вы очень вовремя! Ваша цель у вас слева. Прикончите эту грязную старую змею!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "3 At Cayman";
	break;

 	case "20 Exit":
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	sld=characterFromID("Carrol");
	LAi_SetActorType(sld);
	Lai_ActorDialogNow(sld, Pchar, "",-1);
	break;

	case "21":
            	dialog.text = "Не слушайте эту полоумную старуху, " + GetAddress_Form(NPChar) + " " + PChar.name + ". Мы ведь с вами деловые люди.  Я первым нанял вас, и вы работаете на меня! Выполните свой долг, и я щедро вознагражу вас!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "4";
	break;

	case "22":
            	dialog.text = "Ты - тупая старая карга! Воровка, ты украла мои деньги! Ты украла мой 'Тристан'! Одно из лучших моих судов!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "5";
	break;

	case "23":
            	dialog.text = "Довольно, воровка! Мне надоел этот разговор! Тебе бы руки отрубить за твоё постоянное воровство, да язык - за постоянную ложь. Но всё это можно взять с твоего трупа - так будет легче и надёжнее. " + GetAddress_Form(NPChar) + " " + PChar.name + " - кончайте её!";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "6";
	break;

	case "24":
            	dialog.text = "Что?! А ты что здесь делаешь, Джулия, дорогая? Какого чёрта здесь происходит?!";
        	link.l1 = "Я отправился в  Белиз, в поисках вас, мистер Смит, но вместо вас нашёл там вашу дочь. Она рассказала мне подробности вашей истории и попросила помочь вам. И вот я здесь.";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "7";
	break;

	case "25":
            	dialog.text = "Всё, хватит! Просто расправьтесь с ней, "+ GetFullName(Pchar)+"! И я сделаю вас самым богатым человеком в мире! После меня, конечно.";
        	link.l1 = "";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "8";
	break;

	case "26":
            	dialog.text = "Помолчи, Джулия! Не лезь в дела родителей, ладно? Это война, и идёт она уже давно, и сегодня она должна закончиться! Кровавым разгромом твоей полоумной матери.";
        	link.l1 = "Мистер Смит...";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "9";
	break;

	case "27":
            	dialog.text = "" + PChar.name + ", чёртов ты ублюдок! Решайся же, наконец! Я не хочу больше ждать! Я хочу, чтобы эта женщина умерла - здесь и сейчас! На моих глазах!";
        	link.l1 = "Хорошо, мистер Смит. Я выполню своё обещание. Кэрол - умри!";
        	link.l1.go = "Kill Carrol";
        	link.l2 = "Нет, мистер Смит. Так дело не пойдёт. Мне надоело быть игрушкой в ваших руках. С этой минуты я работаю на Кэрол.";
        	link.l2.go = "Kill David";
        	link.l4 = "Подумайте о Джулии, вы, два бездушных монстра. Вы нужны ей. Нужны живыми.";
        	link.l4.go = "Alive";
		break;

//**************** КОНЦОВКА №1 - УБИЙСТВО КЭРОЛ СМИТ *****************
 	case "Kill Carrol":
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	sld=characterFromID("Carrol");
	LAi_SetActorType(sld);
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "10";
	Lai_ActorDialogNow(sld, Pchar, "",-1);
	break;

	case "28 AftrKillCrrl":
            	dialog.text = "Браво, браво, " + GetAddress_Form(NPChar) + " " + PChar.name + "! Вы всё-таки сделали это! Вы были великолепны! Всё-таки я нашёл идеального человека, не так ли," + GetAddress_Form(NPChar) + " " + PChar.name + "? И хоть история и затянулась - всё хорошо, что хорошо кончается! Наконец-то эта карга мертва.";
        	link.l1 = "Вы тоже хорошо сражались, мистер Смит. Я выполнил" + GetSexPhrase("","а") + " ваше поручение. Могу я получить свою награду?";
        	link.l1.go = "29";
		break;

		case "29":
            	dialog.text = "Конечно, конечно, " + GetAddress_Form(NPChar) + " " + PChar.name + "! Я специально приготовил для вас эти деньги! Вот они - держите. Вы заслужили их. Ещё раз спасибо вам, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Вы сделали меня самым счастливым человеком на этой планете. А теперь, простите нас, но мы с Джулией уходим отсюда. Прощайте, " + GetAddress_Form(NPChar) + " " + PChar.name + ". И удачи вам.";
        	link.l1 = "";
        	link.l1.go = "29 Exit";
	break;

 	case "29 Exit":
	CloseQuestHeader("Gothic_Smithy");
                     AddQuestRecord("Gothic_Smithy", "17");
	AddMoneyToCharacter(pchar, 700000);
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	sld=characterFromID("July");
	LAi_SetActorType(sld);
	Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "24";
	Lai_ActorDialogNow(sld, Pchar, "",-1);
		pchar.questTemp.smithy_end = "really_end";
	break;

//**************** КОНЦОВКА №2 - УБИЙСТВО ДЭВИДА СМИТА *****************
 	case "Kill David":
            	dialog.text = "Вот как? Я весьма разочарован вами,  " + GetAddress_Form(NPChar) + " " + PChar.name + ". Я думал вы - профессионал. А вы всего лишь жалкий дамский угодник. Жалкий крысеныш. Но это уже не столь важно. Господа, пожалуйста, убейте " + GetAddress_Form(NPChar) + " " + PChar.name + " и миссис Смит. Про её горилл тоже не забудьте.";
        	link.l1 = "У вас острый язык, Дэвид Смит. Я такие вырезаю с особенным энтузиазмом.";
        	link.l1.go = "30 Kill David";
		break;

 		case "30 Kill David":
                                         ResumeAllSounds();
                                         NextDiag.CurrentNode = "Third Time";
		DialogExit();
		AddDialogExitQuestFunction("GothicSmithy_IslaMonaShore4");
		pchar.questTemp.smithy_end = "really_end";
		break;

//**************** КОНЦОВКА №3 - УБИЙСТВО ВСЕХ *****************
 	case "Kill All":
            	dialog.text = "Что-что? " + GetAddress_Form(NPChar) + " " + PChar.name + ", вам, похоже, деньги в голову ударили! Вы, что, смеетесь надо мной?! Вы, что, решили, что можете убить нас обоих и забрать всё наше золото себе?! Господа, убейте это
го предателя! А затем и миссис Смит!";
        	link.l1 = "Ты больной человек, Дэвид. Зачем мне твоё золото? Я просто хочу избавить мир от вашего конфликта самым простым и надёжным путём.";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "13";
		pchar.questTemp.smithy_end = "really_end";
	break;

//**************** КОНЦОВКА №4 - "МИРНОЕ" РЕШЕНИЕ КОНФЛИКТА *****************
 	case "Alive":
            	dialog.text = "И что вы предлагаете, " + GetAddress_Form(NPChar) + " " + PChar.name + " ? Вы что, действительно думаете, что мы, сейчас, здесь, можем просто разойтись? Просто всё бросить и уйти? Вы вообще подумали о том, какие деньги были вложены мной в поиски Кэрол? Ведь я спонсировал эти поиски! Я нанял вас, чёрт вас подери! И что, вы, теперь, хотите выступить здесь дипломатом? Я вас нанял, как убийцу, " + GetAddress_Form(NPChar) + " " + PChar.name + " ! Мне не нужен дипломат!";
        	link.l1 = "Мистер Смит, вы умный человек. Вы должны понять, что мирное решение более, чем реально. Оно на поверхности. У вас ведь и так достаточно денег, вы и так богаче всех на архипелаге. Никакой катастрофы не произойдёт, если вы разделите ваше дело с вашей женой.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "14";
		break;

 	case "31":
            	dialog.text = "Нет, я категорически против! Это всё моё! Я это нажил, она здесь не причем! А вы," + GetAddress_Form(NPChar) + " " + PChar.name + ", просто жалкий предатель! И по-хорошему, сейчас я хочу вашей смерти не меньше, чем смерти этой карги! Да вы просто предаёте меня! Вы изменяете нашему договору!";
        	link.l1 = "Ну же, мистер Смит. Я не хочу, чтобы здесь проливалась чья-либо кровь. Будьте благоразумны. У Кэрол такие же права, как и у вас. Просто разделите всё поровну и дальше самостоятельно развивайте каждый свою сеть! Вы оба останетесь в выигрыше.";
        	link.l1.go = "20 Exit";
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "16";
		break;

 	case "32":
            	dialog.text = "Нет! Ты просто жалкий трусливый предатель, " + PChar.name + " ! Ты боишься настоящего возмездия! Никакой ты не профессионал! И мне это всё надоело! Дьявол тебя раздери," + PChar.name + " , чёртов ты ублюдок, да я лично тебя застрелю!";
        	link.l1 = "";
        	link.l1.go = "32 Kill July";
	break;

 	case "32 Kill July":
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
	sld=characterFromID("SmithyDavid");
	LAi_SetActorType(sld);
	LAi_ActorAnimation(sld, "Shot", "Smithy 34", 1.5);
	break;

 	case "33":
            	dialog.text = "Я... я... я не... как...";
        	link.l1 = "Вы - безумный кровожадный полоумный старик и сейчас вы ответите за всё!";
        	link.l1.go = "20 Exit";
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "19";
	break;

 	case "34":
            	dialog.text = "" + PChar.name + " ... Кэрол права. Спасибо тебе. Я... я понял. Я не знаю, важно это для тебя или нет, но... мы найдём решение. Войны больше не будет. Моя невинная дочь погибла... всё из-за меня...";
        	link.l1 = "Мне действительно лучше уйти... не воюйте больше... прощайте...";
        	link.l1.go = "35";
	break;

 	case "35":
            	dialog.text = "" + PChar.name + " ... навестите меня через месяц в моей резиденции  в Санто-Доминго... мне нужно будет сказать вам ещё кое-что...";
        	link.l1 = "Хорошо, мистер Смит... я лучше пойду...";
        	link.l1.go = "35 End Cayman Story";
	break;

 	case "35 End Cayman Story":
	SetFunctionTimerCondition("GothicSmithy_SmithyDavid_SantoDomingo_Bank", 0, 0, 30, false);
                     AddQuestRecord("Gothic_Smithy", "20");
                     NextDiag.CurrentNode = "Third Time";
	DialogExit();
                     LAi_SetPlayerType(pchar);
	AddDialogExitQuest("Smithy 35");
	break;

 	case "36":
            	dialog.text = "А," + PChar.name + " . Рад видеть вас вновь. Спасибо, что пришли. Дело в том, что у меня остался перед вами последний долг. Ведь я обещал вам деньги за вашу работу. Возьмите то, что я обещал и немного сверх того.";
        	link.l1 = "Простите, Дэвид, но я не могу взять их после того, что случилось. Я чувствую себя также виновным в смерти бедной Джулии. Я не уберег её... я подставил её под этот выстрел.";
        	link.l1.go = "37";
	break;

 	case "37":
	Log_Info("Вы получили 900000 песо");
                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                     AddMoneyToCharacter(pchar, 900000);
            	dialog.text = "Нет-нет, " + PChar.name + " . Я не знаю, мне сложно тут что-то говорить... Если совсем прямо, то... это ведь я, лично, выстрелил в свою дочь. И убил её. А хотел убить вас. А убил её. А вы хотели помирить нас и помирили. Но Джулия погибла. Она ведь хотела этого? Это ведь она попросила вас. Простите, " + PChar.name + " , я сейчас... я не могу... просто возьмите деньги, прошу вас, вы обязаны взять их и... уходите. Спасибо вам ещё раз, вы... хороший человек. Просто... просто всё было слишком сложно.";
        	link.l1 = "Хорошо, если вы настаиваете. Я возьму их. Нам, действительно, больше нечего друг другу сказать. Прощайте, Дэвид. Живите в мире.";
        	link.l1.go = "37 End";
	break;

 	case "37 End":
                     NextDiag.CurrentNode = "End Quest Time";
	DialogExit();
	sld.protector = false;
	CloseQuestHeader("Gothic_Smithy");
	pchar.questTemp.smithy_end = "really_end";
	break;

 	case "End Quest Time":
            	dialog.text = "Без Джулии, моей дочурки, мир как-то потускнел, он стал уже не тот...";
        	link.l1 = "Мда-а-а... Что верно, то верно...";
        	link.l1.go = "End Quest Time Exit";
	break;

 	case "End Quest Time Exit":
                     NextDiag.CurrentNode = "End Quest Time";
	DialogExit();
	break;

	}
}


