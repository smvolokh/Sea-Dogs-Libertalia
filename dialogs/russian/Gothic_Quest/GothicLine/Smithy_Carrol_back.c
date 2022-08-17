// Кэррол Смит и шушара всякая
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		

		case "First time":
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
		break;

 		case "Exit":
                                    NextDiag.CurrentNode = "First time";
		DialogExit();
		break;


		case "MartiniqueAbord":
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_IGETYOUSTILL.wav");
            	dialog.text = "Я всё - таки достала тебя...";
        	link.l1 = "...";
        	link.l1.go = "2";
	break;

		case "2":
 	PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_18.wav");
            	dialog.text = "";
        	link.l1 = "К чему весь этот фарс, работа есть работа?";
        	link.l1.go = "3";
	break;

		case "3":
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_KILLENEMY.wav");
            	dialog.text = "Умри подонок.";
        	link.l1 = "...";
        	link.l1.go = "Gun Attack";
	break;

 	case "Gun Attack":
                   NextDiag.CurrentNode = "First time";
	DialogExit();
	sld=characterFromID("KarSec");
	LAi_SetActorType(sld);
            	LAi_ActorTurnToCharacter(sld, pchar);
	LAi_ActorAnimation(sld, "Shot", "GothicSmithy_Ghostship_Gun", 1.5);
	break;

	case "MartiniqueAbord_Gun":
                   if(sti(pchar.money) >= 1)
	{
            	dialog.text = "Спасибо за золото - герой...";
	link.l1 = "...";
	link.l1.go = "ITOOKYOURGOLD";
	}
	else
	{
            	dialog.text = "Ах ты сосунок у тебя даже золота нет...";
	link.l1 = "...";
	link.l1.go = "NO_ITOOKYOURGOLD";
	}

                   LAi_SetCurHP(pchar, 5);						
	LAi_SetActorType(pchar);
	LAi_ActorAnimation(pchar, "death_3", "", -1);
	break;


 	 case "ITOOKYOURGOLD":
 	 PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_ITOOKYOURGOLD.wav");
            	 dialog.text = "Спасибо за золото - герой...";
        	  link.l1 = "";
        	  link.l1.go = "MartiniqueAbord_Gun_Exit";
	  pchar.money = 0;
	  break;

 	 case "NO_ITOOKYOURGOLD":
 	 PlaySound("VOICE\Russian\GOTHIC\CRIME_W\CRIME_W_2.wav");
            	 dialog.text = "Ах ты сосунок у тебя даже злолота нет...";
        	 link.l1 = "";
        	 link.l1.go = "MartiniqueAbord_Gun_Exit";
	  break;


 	case "MartiniqueAbord_Gun_Exit":
                   NextDiag.CurrentNode = "First time";
	DialogExit();
	AddQuestRecord("Gothic_Smithy", "12");
	AddDialogExitQuest("GothicSmithy_GhostshipGetOut");
	break;



	case "3 At Cayman":
            	dialog.text = "Заткнись, червяк! Я давно задаюсь вопросом - как ты ещё самостоятельно ходишь? Тебе ведь уже давно нужны костыли, ты, соломенное пугало! Дорогуша, прикончи этого червяка, и ты станешь моим самым обеспеченным фаворитом! Ты будешь захлебываться в золоте!";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "21";
		break;

 		case "3 Exit":
                                    NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("SmithyDavid");
		LAi_SetActorType(sld);
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "4":
            	dialog.text = "Ха-ха-ха, ты-то деловой человек? Да ты старик никчемный, ты не можешь контролировать не своих людей, не свои суда, не свои капиталы! Ничего абсолютно! Ты - ничтожество! Неудачник! Старый маразматик!";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "22";
		break;

	case "5":
            	dialog.text = "Я не крала твой флейт. Просто его капитан знает толк в работодателях. Я ему больше нравлюсь, чем старый полоумный толстосум.";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "23";
		break;

	case "6":
            	dialog.text = "Труп здесь сегодня будет только твой, старый маразматик. Ты так ничего и не понял, глупышка? Твои люди ненавидят тебя, ты им не нужен, потому что ты - глупый старый никчёмный полоумный ненормальный ТОЛСТЫЙ ЖАДНЫЙ УБЛЮДОК!!! И твой "+ GetFullName(Pchar)+" тоже работает на меня! Он верит мне! Он умрет ради меня! ОН УБЬЁТ ТЕБЯ РАДИ МЕНЯ!";
        	link.l1 = "Стоп-стоп-стоп! Вы двое - успокойтесь, хорошо? Вы оба - сумасшедшие, вы даже не замечаете, что здесь со мной - ваша дочь, Джулия.";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "24";
		break;

	case "7":
            	dialog.text = "В поисках вас, мистер Смит! Бла-бла-бла! Ты отправился туда, потому что я приказала тебе, дорогуша! Потому что я приказала тебе убить эту свинью!";
        	link.l1 = "Ну... в том числе и поэтому.";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "25";
		break;

	case "8":
            	dialog.text = "Не слушай эту свинью, " + PChar.name + "! Ну же, прикончи его! Я верю в тебя, дорогуша.";
        	link.l1 = "";
        	link.l1.go = "8 Exit";
	Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "23 At Cayman";
		break;

	 	case "8 Exit":
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
		LAi_SetActorType(sld);
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

	case "9":
            	dialog.text = "Кто кого разгромит - это мы ещё посмотрим! Джулия - убирайся отсюда! Здесь не место сопливым девчонкам, идущим против своих матерей плюс ко всему! " + PChar.name + " - убей же ублюдка, наконец!";
        	link.l1 = "Миссис Смит, я...";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "27";
		break;


//**************** КОНЦОВКА №1 - УБИЙСТВО КЭРОЛ СМИТ *****************
	case "10":
            	dialog.text = "ЧЁРТОВ ПРЕДАТЕЛЬ!!! Ты выбрал неправильную сторону, дорогуша! Ребята, кончайте крысу и толстяка!";
        	link.l1 = "Это за тот выстрел, Кэрол! Тебе не стоило тогда стрелять! Умри!";
        	link.l1.go = "Kill Carrol";
		break;

	 	case "Kill Carrol":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("Carrol");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_1_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_2_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_3_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_4_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_5_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");

		sld=characterFromID("SmithyDavid");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_6_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("GothicSmithy_Pirat_7_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_8_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_9_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
		sld=characterFromID("GothicSmithy_Pirat_10_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);	
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", LAI_GROUP_PLAYER, true);
		//	LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", "GothicSmithy_Pirat_David_War", true);
		pchar.quest.GothicSmithy = "GothicSmithy_Kill_Carrol";
		LAi_group_SetCheck("GothicSmithy_Pirat_Karrol_War", "Smithy 30");
		break;


//**************** КОНЦОВКА №2 - УБИЙСТВО ДЭВИДА СМИТА *****************
	case "11 AftrKillDvd":
            	dialog.text = "Великолепно, дорогуша! Ты сделал правильный выбор, и ты убил эту свинью! Великолепно! Потрясающе! Я очень горжусь тобой.";
        	link.l1 = "Я весьма польщён, миссис Смит. Надеюсь, награда не заставит себя ждать?";
        	link.l1.go = "12";
		break;

		case "12":
            	dialog.text = "Не заставит, дорогуша. Я приготовила для тебя солидный куш, ведь я знала, что ты сделаешь правильный выбор. Держи, ты заслужил это золото. А теперь, прошу нас простить, но мы с девочкой Джулией уплываем отсюда. Прощай, дорогуша. Всего тебе самого наилучшего.";
        	link.l1 = "";
        	link.l1.go = "12 Exit";
		break;

 		case "12 Exit":
		AddMoneyToCharacter(pchar, +60000);
                                      NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("July");
		LAi_SetActorType(sld);
		Characters[GetCharacterIndex("July")].Dialog.CurrentNode = "24";
		Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;

//**************** КОНЦОВКА №3 - УБИЙСТВО ВСЕХ *****************
	case "13":
            	dialog.text = "" + PChar.name + ", ты чёртов предатель! Джентльмены - убейте всех этих свиней и эту тварь в первую очередь!";
        	link.l1 = "Подходите, толстосумы! Стали всем хватит!";
        	link.l1.go = "13 Exit";
		break;

	 	case "13 Exit":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
		sld=characterFromID("Carrol");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("SmithyDavid");
			LAi_SetImmortal(sld, false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Smithy_Pirat_1_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_2_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_3_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_4_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");
		sld=characterFromID("GothicSmithy_Pirat_5_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_Karrol_War");

		sld=characterFromID("GothicSmithy_Pirat_6_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_7_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_8_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_9_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
		sld=characterFromID("GothicSmithy_Pirat_10_Sho");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "GothicSmithy_Pirat_David_War");
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", "GothicSmithy_Pirat_David_War", true);
			LAi_group_FightGroups("GothicSmithy_Pirat_David_War", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups("GothicSmithy_Pirat_Karrol_War", LAI_GROUP_PLAYER, true);
		pchar.quest.GothicSmithy = 0;
		LAi_group_SetCheck("GothicSmithy_Pirat_Karrol_War", "Smithy 33");
		LAi_group_SetCheck("GothicSmithy_Pirat_David_War", "Smithy 33");
		break;


//**************** КОНЦОВКА №4 - "МИРНОЕ" РЕШЕНИЕ КОНФЛИКТА *****************
	case "14":
            	dialog.text = "Нет, "+ GetFullName(Pchar)+"! Я не собираюсь ничего делить с этой свиньей! Всё это принадлежит мне, и я буду владеть всем этим единолично! Мне не нужна эта свинья!";
        	link.l1 = "Кэрол, подумайте. Вы ведь любите свою дочь? Ваша вражда может погубить её. Вы ведь не хотите этого? Она ни в чём не виновата. А может стать жертвой вашей жадности.";
        	link.l1.go = "15";
		break;

		case "15":
            	dialog.text = "Я... Я не люблю её! Она - мерзкая избалованная девчонка, испорченная отцовским воспитанием, точнее его полным отсутствием. Но... пожалуй ты в чём-то прав, "+ GetFullName(Pchar)+". Я перестану мешать делам Дэвида, если он перестанет мешать мне. Если мы поделим всё поровну, это будет честно! Ведь мы жили вместе и вместе это наживали и у нас равные права на всё это золото и его будущее.";
        	link.l1 = "Всё верно, миссис Смит! Мистер Смит, что скажете?";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "31";
		break;

	case "16":
            	dialog.text = "Прислушайся к своему наёмнику, Дэвид. Он говорит всё верно. И предлагает дельные вещи.";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "32";
		break;

	case "17":
            	dialog.text = "Психопат!!! Ублюдок!!! Что ты сделал с нашей доченькой?!?";
        	link.l1 = "Она... она умерла.";
        	link.l1.go = "18";
		break;

		case "18":
            	dialog.text = "О, НЕТ!!! НЕ-Е-Е-Т!!! Я НЕ ВЕРЮ В ЭТО!!! ДЭВИД, ТЫ... ты... нет... доченька...";
        	link.l1 = "";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "33";
		break;

	case "19":
            	dialog.text = "Нет! " + PChar.name + "! Стой! Не нужно! Не нужно больше ни чьей смерти! Достаточно на сегодня и на век вперёд! " + PChar.name + "... оставь нас. Тебе лучше уйти. Ты хотел как лучше, я знаю и ты... спасибо. Теперь уйди.";
        	link.l1 = "Я...";
        	link.l1.go = "3 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "34";
		break;










































//************************ Федерик Туванье (нападение в море) ****************************************

		case "FrdAttckAtSea":
            	dialog.text = "Так-так. "+ GetFullName(Pchar)+", не так ли?";
        	link.l1 = "Какого чёрта вам нужно на моём корабле?";
        	link.l1.go = "FrdAttckAtSea 1";
		break;

		case "FrdAttckAtSea 1":
            	dialog.text = "Федерик Туванье. Флейт «Тристан», бухта Сент-Кристофера. Не припоминаете, " + PChar.name + "? Вы потопили меня.";
        	link.l1 = "Такое случается. Вы, как я вижу, выжили.";
        	link.l1.go = "FrdAttckAtSea 2";
		break;

		case "FrdAttckAtSea 2":
            	dialog.text = "Именно, " + PChar.name + ". Но я лишился судна, команды и большей части своих капиталов.";
        	link.l1 = "Вы хотите, чтобы я попросил" + GetSexPhrase("","а") + " прощения? Или станцевал" + GetSexPhrase("","а") + " перед вами?";
        	link.l1.go = "FrdAttckAtSea 3";
		break;

		case "FrdAttckAtSea 3":
            	dialog.text = "Вы остря" + GetSexPhrase("к","чка") + ", " + PChar.name + ", но это не делает вас сильнее, чем вы есть на самом деле, так что очнитесь. Мне нужна Джулия Говард.";
        	link.l1 = "Что? О чём это вы?";
        	link.l1.go = "FrdAttckAtSea 4";
		break;

		case "FrdAttckAtSea 4":
            	dialog.text = "Не прикидывайтесь, " + PChar.name + ", я знаю, что она у вас на борту и, вероятно, сейчас прячется в вашей или своей каюте. Отдайте мне девушку, и я отпущу ваше судно.";
        	link.l1 = "Зачем она вам?";
        	link.l1.go = "FrdAttckAtSea 5";
		break;

		case "FrdAttckAtSea 5":
            	dialog.text = "Я собираюсь обменять её на новое судно и полное возмещение моих убытков со стороны её матери, миссис Кэрол Говард. Ну и приятная компания в дальнем плавании никогда не помешает.";
        	link.l1 = "Что же, боюсь, что я не позволю вам даже взглянуть на неё.";
        	link.l1.go = "FrdAttckAtSea 6";
		break;

		case "FrdAttckAtSea 6":
            	dialog.text = "В таком случае, мне придётся позволить себе взглянуть на неё без вашего разрешения.";
        	link.l1 = "Вы рискнёте?";
        	link.l1.go = "FrdAttckAtSea 7";
		break;

		case "FrdAttckAtSea 7":
            	dialog.text = "Непременно. Господа - вырезать всё живое на этом корабле, кроме юной девушки!";
        	link.l1 = "Надеюсь, что вы успели заказать себе место в аду!";
        	link.l1.go = "FrdAttckAtSea Fight";
		break;

 		case "FrdAttckAtSea Fight":
                NextDiag.CurrentNode = "Fist time";
		DialogExit();
		sld=characterFromID("Quest_Smithy_Feder");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_1_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_2_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_3_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_4_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_5_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_6_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
		sld=characterFromID("Quest_Smithy_Pirat_7_Ab");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "Smithy_Pirat_War_Sea");
// наши
		sld=characterFromID("QuestPcharFirstMate");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter1");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter2");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter3");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter4");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		sld=characterFromID("QuestPcharMassovkaFighter5");
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
		LAi_group_FightGroups("Smithy_Pirat_War_Sea", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("Smithy_Pirat_War_Sea", "Smithy 20");
		Pchar.GenQuest.HunterScore2Pause =  true;
		break;

	}
}


