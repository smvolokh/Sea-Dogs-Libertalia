// Джулия Смит, Дворецкий Джеральд
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
		if (pchar.quest.NSmithyQ == "Smithy_SanJuan_Dvoretsky")
		{
            	dialog.text = "О, " + GetAddress_Form(NPChar) + ", приветствую вас! Я Джеральд, дворецкий этого дома. Вы должно быть капитан " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?";
        	link.l1 = "Да, это я. Мне нужно поговорить с мистером Смитом. Могу я пройти?";
        	link.l1.go = "DvorJer 1";
		}
		else
		{
			int iPhrase_Quest_Smithy = rand(1);
			switch (iPhrase_Quest_Smithy)
			{
			case 0:
            		dialog.text = "Добро пожаловать в дом семьи Смит. Вы что-то хотели?";
        		link.l1 = "Ээээ... Нет, я так зашел" + GetSexPhrase("","а") + "...";
        		link.l1.go = "Exit";
			break;

			case 1:
            		dialog.text = "Прошу прощения " + GetAddress_Form(NPChar) + ", но Мистер и Миссис Смит в отъезде.";
        		link.l1 = "А кто это такие?! Хотя... Ладно...";
        		link.l1.go = "Exit";
			break;			
			}
		}
		break;

	case "Exit":
                NextDiag.CurrentNode = "Fist time";
		DialogExit();
		break;


	case "Second Time":
            	dialog.text = "Здравствуйте, " + GetAddress_Form(NPChar) + "!";
        	link.l1 = "";
        	link.l1.go = "Second Time Exit";
		break;

 	case "Second Time Exit":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;


	case "Smithy_July":
            	dialog.text = "Вы, должно быть,  " + GetAddress_Form(NPChar) + " " + PChar.name + "? Я очень рада вас видеть. Меня зовут Джулия Говард, хотя на самом деле я Смит, но это неважно... слишком длинная история. Можете звать меня просто Джулия. Вас ведь прислал ко мне Джерри?";
        	link.l1 = "Да, Джулия. Кстати, можете звать меня просто " + PChar.name + ".";
        	link.l1.go = "2";
		break;

		case "2":
            	dialog.text = "Очень приятно, " + PChar.name + ". Итак, если я правильно понимаю, вы тот свободный капитан, кого мой безумный отец нанял, чтобы убить мою безумную мать?";
        	link.l1 = "Да, ваш отец предложил мне фантастические деньги и, в самом начале, не давал никаких подробностей дела. Я принял" + GetSexPhrase("","а") + " его предложение, так как получаю подобные не каждый день. Надеюсь, вы меня понимаете.";
        	link.l1.go = "3";
		break;

		case "3":
            	dialog.text = "Я понимаю вас, " + PChar.name + ". А главное не виню. Если кто-то и виноват во всей этой истории, так это я.";
        	link.l1 = "Простите? Вы? А вы-то здесь причем?";
        	link.l1.go = "4";
		break;

		case "4":
            	dialog.text = "Ну а как же вы думали, " + PChar.name + ". Отец хотел, чтобы я поехала в Европу и поступила там в университет. Мама хотела, чтобы я приняла их дело и стала новой управляющей сетью. И ещё множество других разногласий. И все они, чаще всего, возникали из-за меня. А в результате я оскорбила их обоих, я не то что не пыталась помочь им помириться - я назвала их обоих старыми психопатами и попросила моего друга, Фрэнка, капитана, как и вы, увезти меня подальше от них. Я люблю рисовать, я могла бы стать художницей, а Фрэнк, как и мой отец, отличный предприниматель, он мог бы сделать из моего увлечения - дело. Точнее он был им... пока моя мама не убила его. Сумасшедшая, ненормальная, безумная старуха! Она натравила на него своих головорезов и они... они убили его. А меня доставили к ней и она сказала, что я не должна принимать никаких решений в тайне от неё... Ладно, " + PChar.name + ", мы отвлеклись от темы. Всё это очень грустно, но сейчас я ещё могу что-то изменить. С вашей помощью. Или же станет ещё грустнее. Вы поможете мне, " + PChar.name + "?";
        	link.l1 = "Вы не должны ни в чём винить себя, Джулия. Ваши родители не правы, а вы делали всё, что могли, чтобы помочь им. Я готов и хочу помочь вам, но что именно вы хотите от меня?";
        	link.l1.go = "5";
		break;

		case "5":
            	dialog.text = "У них встреча. На необитаемом острове, Каймане. Что-то вроде дуэли. Я не знаю, что они там собираются делать, но я уверена, что добром это не кончится. Они ненавидят друг друга и они абсолютно безумны. Каждый хочет избавиться от другого и единолично владеть всеми доходами и капиталами. Мы с вами должны отправиться туда и помешать им совершить безумие! Мы должны остановить их!";
        	link.l1 = "Но... как вы собираетесь остановить их? Вы ведь сами сказали, что они абсолютно безумны, а с их возможностями, это была, есть и будет, в прямом смысле слова - настоящая война. И как вы хотите закончить её без потерь?";
        	link.l1.go = "6";
		break;

		case "6":
            	dialog.text = "Я не знаю, " + PChar.name + "! Поэтому я и прошу вас помочь! Вы опытнее меня в такого рода делах, вы " + GetSexPhrase("мужщина","женщина") + ", вы человек со стороны, но уже довольно хорошо понявший ситуацию... Я не знаю! Но мы обязаны это сделать! Если вы поможете мне, я уверена, что каждый участник истории щедро отблагодарит вас! Я щедро отблагодарю вас, " + PChar.name + "!";
        	link.l1 = "Что ж... я готов на всё, если вы собираетесь лично отблагодарить меня, Джулия.";
        	link.l1.go = "7";
		break;

		case "7":
            	dialog.text = "Простите, что вы имеете в виду, " + PChar.name + "?";
        	link.l1 = "Нет-нет, ничего, не берите в голову, Джулия. Так мы отправляемся?";
        	link.l1.go = "8";
		break;

		case "8":
            	dialog.text = "Да! Скорее на Кайман!";
        	link.l1 = "Тогда прошу на борт, мисис!";
        	link.l1.go = "Go TO Cayman";
		break;

 	case "Go TO Cayman":
    	AddQuestRecord("Gothic_Smithy", "14");
                   NextDiag.CurrentNode = "Second Time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyPuertoRico_4");
		break;








	case "9 Sea Atack":
            	dialog.text = "Что происходит," + PChar.name + "?";
        	link.l1 = "Э-э, Джулия, прошу вас, вернитесь в свою каюту. Ничего страшного не происходит, просто рабочие моменты.";
        	link.l1.go = "10";
		break;

		case "10":
            	dialog.text = "А что это за корабль, что движется на нас? Боже, кажется, они спускают шлюпки!";
        	link.l1 = "Джулия, прошу, вернитесь в свою каюту. Найджел, проклятье, проводи мисс Говард в её каюту.";
        	link.l1.go = "11";
		break;

		case "11":
            	dialog.text = "" + PChar.name + ", мне страшно! Что происходит?!";
        	link.l1 = "Найджел! Выполняйте!";
        	link.l1.go = "TO Cabin from Attack";
		break;

 	case "TO Cabin from Attack":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 16", 0.5);
		break;



	case "12 After Sea Attack":
            	dialog.text = "О, Боже! Господи! Что здесь произошло?!?";
        	link.l1 = "Всё хорошо, Джулия. Прошу вас, не волнуйтесь. Это... плановые учения. Позвольте мне проводить вас до вашей каюты.";
        	link.l1.go = "TO Cabin After Attack";
		break;

 	case "TO Cabin After Attack":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 23", 0.5);
		break;



	case "13 At My Cabin":
            	dialog.text = "" + PChar.name + ", они ведь приходили за мной? И вы... вы дрались из-за меня?";
        	link.l1 = "Милая Джулия, поверьте, ничего страшного не произошло. Это обычное дело для меня. Ну, знаете, защищать своё судно, людей и пассажиров...";
        	link.l1.go = "14";
		break;

		case "14":
            	dialog.text = "Обычное дело? И как часто вы убиваете людей?";
        	link.l1 = "Ну, я... я не убийца. Я же сказал - это оборона своего судна. Капитан обязан отвечать за это.";
        	link.l1.go = "15";
		break;

		case "15":
            	dialog.text = "И что вы чувствуете, когда... когда убиваете?";
        	link.l1 = "Ну... ничего. К этому можно привыкнуть. По крайней мере - я привык" + GetSexPhrase("","ла") + ".";
        	link.l1.go = "16";
		break;

		case "16":
            	dialog.text = "Это ужасно, " + PChar.name + "...";
        	link.l1 = "Ну... такова наша реальность, наша природа. Выживает сильнейший. Естественный отбор. Бей первым, или первым ударят тебя, и до второго удара уже может не дойти. Так, довольно. Вы пережили стресс, вам нужно отдохнуть. Мне лучше оставить вас.";
        	link.l1.go = "17";
		break;

		case "17":
            	dialog.text = "Нет, " + PChar.name + ", прошу вас, лучше... лучше останьтесь со мной.";
        	link.l1 = "Но...";
        	link.l1.go = "18";
		break;

		case "18":
            	dialog.text = "" + PChar.name + ", вы же можете побыть со мной здесь? Хотя бы немного? Ведь корабль не собьётся с курса и не налетит на рифы? У вас ведь есть великолепные помощники. Капитану ведь тоже нужно иногда отдыхать, разве не так, " + PChar.name + "?";
        	link.l1 = "Ну, эээ... пожалуй, да... капитану тоже нужен отдых... эээ... нужно отдыхать...";
        	link.l1.go = "19";
		break;

		case "19":
LAi_Fade("","");
//StartQuestMovie(false, false, true);   // проверить срабатывание!!!!!!!!!
// включить Love music
            	dialog.text = "" + PChar.name + ", скажите, разве моряки всегда так грубы и суровы?";
        	link.l1 = "Ну... иногда мы стараемся быть помягче. С некоторыми.";
        	link.l1.go = "20";
		break;

		case "20":
            	dialog.text = "Некоторые из вас, наверное...";
        	link.l1 = "Но только некоторые.";
        	link.l1.go = "21";
		break;

		case "21":
            	dialog.text = "А вы - вы ведь один из тех суровых моряков?";
        	link.l1 = "Только иногда.";
        	link.l1.go = "22";
		break;

		case "22":
            	dialog.text = "Всё же, я думаю, что вы - очень хороший плохой человек.";
        	link.l1 = "Ну, иногда я даже тяну на очень плохого хорошего человека.";
        	link.l1.go = "22 Next Day";
		break;

 	case "22 Next Day":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		DoQuestCheckDelay("Smithy 26", 1.0);
		break;

	case "23 At Cayman":
            	dialog.text = "Отец! Мама! Перестаньте! Не нужно ни кого убивать! Давайте просто разойдёмся, и все будут счастливо жить дальше?";
        	link.l1 = "Джулия права. Вам обоим нужно просто успокоиться. Ваша проблема решаема.";
        	link.l1.go = "23 Exit";
			Characters[GetCharacterIndex("David")].Dialog.CurrentNode = "26";
		break;

 		case "23 Exit":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
			sld=characterFromID("David");
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;


//**************** КОНЦОВКА №1 - УБИЙСТВО КЭРОЛ СМИТ *****************
//**************** КОНЦОВКА №2 - УБИЙСТВО ДЭВИДА СМИТА *****************
	case "24":
            	dialog.text = "";
        	link.l1 = "Джулия...";
        	link.l1.go = "25";
		break;

		case "25":
            	dialog.text = "Я... Я ожидала от вас иного, капитан. Я вас переоценила. Прошу меня простить...";
        	link.l1 = "";
        	link.l1.go = "25 End Quest";
		break;

 		case "25 End Quest":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
	if (pchar.quest.NSmithyQ == "Carrol")
	{
		AddQuestRecord("Smithy", "16");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("David");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_6_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_7_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_8_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_9_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_10_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
	if (pchar.quest.NSmithyQ == "Smithy_Kill_David")
	{
		AddQuestRecord("Smithy", "17");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("Carrol");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_1_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_2_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_3_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_4_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_5_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
		break;


//**************** КОНЦОВКА №3 - УБИЙСТВО ВСЕХ *****************
	case "26":
            	dialog.text = "Вы, вы чудовище! Что вы наделали! Кровожадное, мерзкое чудовище! Нет, вы так с этим не уйдёте! Получайте, монстр!!!";
        	link.l1 = "Что?! Да вы шутите! Эй! Эй! Стоп! Подожди! Чёрт! Ах ты, чертовка...";
        	link.l1.go = "26 End Quest";
		break;

 		case "26 End Quest":
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
       			GiveItem2Character(sld, "blade_5");
        		EquipCharacterByItem(sld, "blade_5");
		LAi_SetImmortal(sld, false);				
		LAi_SetWarriorType(sld);
		LAi_group_MoveCharacter(sld, "Quest_Smithy_July_War");
		LAi_group_FightGroups("Quest_Smithy_July_War", LAI_GROUP_PLAYER, true);
		LAi_SetFightMode(pchar, true);
		LAi_SetImmortal(sld, false);
		pchar.quest.NSmithyQ = "Smithy_Kill_All";
		Pchar.quest.Quest_Smithy_July_War.win_condition.l1 = "NPC_Death";
		Pchar.quest.Quest_Smithy_July_War.win_condition.l1.character = "July";
		Pchar.quest.Quest_Smithy_July_War.win_condition = "Smithy 31";
		DoQuestCheckDelay("Smithy 32 JulyDead", 5.0);
		break;



	case "27":
            	dialog.text = "Кхаргкх... А-а-а...";
        	link.l1 = "О, Боже!!! Джулия!!!";
        	link.l1.go = "27 End Quest";
		break;

 		case "27 End Quest":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
			LAi_KillCharacter(characterFromID("July"));
			LAi_SetPlayerType(pchar);
		sld=characterFromID("Carrol");
			Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "17";
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;



//************************ Дворецкий Джеральд ****************************************
		
		case "DvorJer 1":
            	dialog.text = "Боюсь это невозможно,  " + GetAddress_Form(NPChar) + ". Мистера Смита нет дома, но он говорил мне, что вы появитесь здесь.";
        	link.l1 = "Вот как? И, вероятно, он попросил вас что-то передать мне?";
        	link.l1.go = "DvorJer 2";
		break;

		case "DvorJer 2":
            	dialog.text = "Совершенно верно,  " + GetAddress_Form(NPChar) + ". Он просил передать, чтобы вы, как только появитесь здесь, немедленно отправились на незаселённый остров Кайман. Он просил также сообщить вам, цитирую, 'что это важнейшая часть всего дела, его кульминация и развязка'. Он объяснил, что это очень важно и очень срочно, и вы обязаны немедленно поспешить туда.";
        	link.l1 = "Хорошо, я понял,  Джеральд, я отправлюсь туда немедленно. Ещё что-нибудь?";
        	link.l1.go = "DvorJer 3";
		break;

		case "DvorJer 3":
            	dialog.text = "Да, есть ещё одна вещь. Дело в том, что час назад здесь была девушка, и также спрашивала о вас. Сказала, что хочет поговорить с вами, когда вы появитесь. Эта девушка была Джулией Говард.";
        	link.l1 = "Джулия Говард? Кто это?";
        	link.l1.go = "DvorJer 4";
		break;

		case "DvorJer 4":
            	dialog.text = "О, " + GetAddress_Form(NPChar) + ", вы не знаете её? Это прекрасная юная дочь мистера Дэвида и миссис Кэрол Смит. Она очень любит своих родителей и очень переживает из-за их вражды. Должен заметить, что, на мой взгляд, она больше привязана к мистеру Смиту, своему отцу. Она сказала, что хочет поговорить с вами, что это очень важно. Она остановилась прямо здесь, в доме своего отца. Её комната на втором этаже, вверх по лестнице.";
        	link.l1 = "Спасибо, Джеральд, я поднимусь и поговорю с ней.";
        	link.l1.go = "DvorJer To July";
		break;

 		case "DvorJer To July":
		Locations[FindLocation("SanJuan_town")].reload.l32.disable = false;
		pchar.quest.NSmithyQ = "";
		sld=characterFromID("Quest_Smithy_Dvoretsky");
		LAi_SetPlayerType(sld);
		LAi_SetCitizenType(sld);
		sld.talker = 0;
		sld=characterFromID("July");
	//	ChangeCharacterAddressGroup(sld,"house", "loc", "aloc0"); // Уточнить, комната на втором этаже
		sld.protector = true;
		sld.protector.CheckAlways = 1;
		characters[GetCharacterIndex("July")].dialog.currentnode = "1 July SanJuan";
                NextDiag.CurrentNode = "Third time";
		DialogExit();
		break;

	case "Third time":
            	dialog.text = "Скорее поднимайтесь," + GetAddress_Form(NPChar) + "! Джулия ждёт вас";
        	link.l1 = "";
        	link.l1.go = "Exit Dvor 3";
		break;

		case "Exit Dvor 3":
                NextDiag.CurrentNode = "Third time";
		DialogExit();
		break;



	}
}


