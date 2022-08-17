
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, arRld, arDis;
	int i, Qty;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		//--------------------------------- леди в резиденции ---------------------------------
		case "ResWoman":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_W\GG_HALLO_W_" + rand(12) + ".wav");
			NextDiag.TempNode = "ResWoman";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase("Вот это да! Отпетый мерзавец - и у меня в покоях! Убирайся немедленно, не то позову стражу!", "Кошмар какой-то... И как эту пакость вообще пустили в мой дом? Прочь, негодяй! Нечего здесь шастать! Пошел вон!!", "Ну и времена настали. Всякая мерзость заглядывает ко мне прямо в спальню! Вон!!");
				link.l1 = RandPhraseSimple("Полегче...", "Аккуратней в выражениях...");
				link.l1.go = "exit";
			}
			else
			{
			if (CheckAttribute(pchar, "TorjestvaDa"))
			{
			link.l2 = RandPhraseSimple("Не гневайтесь, сударыня. Я прошу прощения за вторжение в Ваши покои, но всего я лишь хотел узнать, когда во дворце проходят торжественные приемы или светские вечера?", "Прошу меня простить за вторжение, сударыня, но я лишь хотел узнать не планируются ли сегодня во дворце светские мероприятия?");
			link.l2.go = "Torjestva_1";
			}
			dialog.text = LinkRandPhrase("Что вы тут делаете? Уходите отсюда немедленно!", "Что за бестактность! Попрошу вас немедленно покинуть помещение!", "Простите, сударь, но вас сюда не приглашали. Потрудитесь покинуть помещение!");
				link.l1 = RandPhraseSimple("Простите... Я уже ухожу.", "Извините, я ошибся дверью. Ухожу.");
				link.l1.go = "exit";
				}
			break;
		case "Woman_FackYou":
			dialog.text = "Ой, что же это делается?! А я-то, дура, хожу, ничего не замечаю... Охрана!!!";
			link.l1 = "Заткнись, дура...";
			link.l1.go = "exit_setOwner";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;
		//--------------------------------- слуга в резиденции ---------------------------------
		case "ResMan":
				PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "ResMan";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase(""+ GetSexPhrase("Пошел вон отсюда, мерзавец","Пошла вон отсюда, мерзавка") +"!", "Немедленно убирайся из дома губернатора, "+ GetSexPhrase("негодяй","негодяйка") +"!", "Мне нет дела до того, что тебе нужно в доме губернатора " + XI_ConvertString("Colony" + npchar.city + "Gen") + ". Но дам тебе совет - убирайся отсюда!");
				link.l1 = RandPhraseSimple("Полегче, родной...", "Смотри, не подавись своими словами!");
				link.l1.go = "exit";
			}
			else
			{
			if (CheckAttribute(pchar, "TorjestvaDa"))
			{
			dialog.text = LinkRandPhrase("Здравствуйте. Я - слуга губернатора. Меня зовут " + GetFullName(NPChar) + ".", "Я присматриваю здесь за порядком, " + GetAddress_Form(NPChar) + ".", "Вы знаете, " + GetAddress_Form(NPChar) + ", наш губернатор - хороший человек, и неплохо платит прислуге...");
			link.l2 = RandPhraseSimple("Здравствуйте! Разрешите представиться: капитан " + GetFullName(pchar) + ". Мне хотелось бы узнать, не запланирован ли сегодня во дворце губернатора какой-нибудь светский раут?", "Здравствуйте! Моё имя: " + GetFullName(pchar) + ". Не подскажите, уважаемый, а не планируется ли во дворце сегодня некий торжествый прием или обед?");
	link.l2.go = "Torjestva_1";
			}
			dialog.text = LinkRandPhrase("Здравствуйте. Я - слуга губернатора. Меня зовут " + GetFullName(NPChar) + ".", "Я присматриваю здесь за порядком, " + GetAddress_Form(NPChar) + ".", "Вы знаете, " + GetAddress_Form(NPChar) + ", наш губернатор - хороший человек, и неплохо платит прислуге...");
				link.l1 = RandPhraseSimple("Очень хорошо.", "Хм, прекрасно...");
				link.l1.go = "exit";
				}
		break; //--------- отправка к торжествам во дворце -----------
		
		case "Torjestva_1":
			if (drand(2) == 0)
			{
				dialog.text = "Ах да, действительно! Как раз в ближайшие часы начнется торженственный прием. Там всегда собираются самые сливки нашего общества! Но вход как известно платный - 50000 золотых. Приемы такого уровня, знаете ли весьма недешево обходятся губернатору. ";	
	Link.l1 = "Чудесно! Мне бы очень хотелось поучаствовать.";
	Link.l1.go = "Torjestva_0";
	link.l2 = "Любопытно, но это слишком дорого.";
	link.l2.go = "exit";
			}
			else
			{	
			dialog.text = "Сегодня губернатор не планировал устраивать торжеств. Но если Вам угодно, заходите время от времени, мы устраиваем приемы довольно часто.";	
				link.l2 = "Благодарю за совет. Обязательно зайду при случае.";
	SetTimerCondition("TorjestvaNet", 0, 0, 0, false);
				link.l2.go = "exit";
			}
		break;

	case "Torjestva_0":
	dialog.text = "Вы готовы оплатить вход сейчас?";
	Link.l1 = "Да, конечно!";
	Link.l1.go = "Torjestva_2";		
	Link.l2 = "Да, но наверное чуть позже.";
	Link.l2.go = "Exit";		
		break;
		
        case "Torjestva_2":
			if(makeint(Pchar.money) >= 50000)
			{
                dialog.text = "Замечательно! Это будет прекрасное мероприятие!";
			link.l1 = "Чудно! Надеюсь, что это будет восхитительно.";
			link.l1.go = "Torjestva_3";
			}
			else
			{
                dialog.text = "Извините, капитан, но у Вас нет при себе нужной суммы.";
link.l1 = "Точно, я забыл деньги на корабле! Я скоро вернусь!";
link.l1.go = "Exit";					
			}
		break;

		case "Torjestva_3":
			DialogExit();
			AddMoneyToCharacter(Pchar, -50000);
			DoQuestCheckDelay("Torjestva_dvorec", 1.0);
		SetTimerCondition("TorjestvaNet", 0, 0, 0, false);
		break;	

		case "Man_FackYou":
			dialog.text = "Да ты никак "+ GetSexPhrase("вздумал","вздумала") +" обворовать губернатора?! Охрана, держи "+ GetSexPhrase("вора","воровку") +"!!";
			link.l1 = "Закрой пасть...";
			link.l1.go = "fight";
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
		break;		
		//--------------------------------- солдат в резиденции ---------------------------------
		case "ResGuard":
			PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
			NextDiag.TempNode = "ResGuard";
			if (isBadReputation(pchar, 30))
			{
				dialog.text = LinkRandPhrase(""+ GetSexPhrase("Шел бы отсюда, приятель","Шла бы отсюда, подруга") +"...", "Проваливай отсюда!", "Ты, часом, дверью не "+ GetSexPhrase("ошибся","ошиблась") +"? Это дом губернатора " + XI_ConvertString("Colony" + npchar.city + "Gen") + ". Тебе лучше уйти!");
				link.l1 = RandPhraseSimple("Уйду, когда захочу!", "Не лезь не в свое дело...");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = LinkRandPhrase("Сегодня меня поставили в наряд к губернатору. Неплохое место...", "Я охраняю дом губернатора, " + GetAddress_Form(NPChar) + ".", "Моя задача - охранять дом губернатора.");
				link.l1 = RandPhraseSimple("Здорово.", "Хм, понятно...");
				link.l1.go = "exit";
			}
		break;
	}
}
