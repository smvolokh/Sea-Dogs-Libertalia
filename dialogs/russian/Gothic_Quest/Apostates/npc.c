
// Отступники веры и всякая шушара
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, iTemp, amount;
	string sTemp;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	   bool ok;
                        int iTest;
                        ref rColony;
                        string sFrom_sea = "";
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // индекс в конце
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_10.wav");
		dialog.text = "...";
		link.l1 = "Всё в порядке!";
		link.l1.go = "First time_1";			
		break;

		case "First time_1":
	                     PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_HELLO_10_01.wav");
		dialog.text = "А, новичок, прекрасно, нам сейчас пригодится каждый человек.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;

		case "First time2":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела!";
		link.l1.go = "First time2_1";			
		break;

		case "First time2_1":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_01.wav");
		dialog.text = "А ты кто такой, один из бандитов!";
		link.l1 = "...";
		link.l1.go = "First time2_2";			
		break;

		case "First time2_2":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "А что, похож...";
		link.l1.go = "First time2_3";			
		break;

		case "First time2_3":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_03.wav");
		dialog.text = "Одет ты так же как и мы, но я тебя не знаю.";
		link.l1 = "...";
		link.l1.go = "First time2_4";			
		break;

		case "First time2_4":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_04.wav");
		dialog.text = "Честно говоря, да...";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time2";
		break;

		case "First time3":
	                     PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_10.wav");
		dialog.text = "...";
		link.l1 = "Всё в порядке!";
		link.l1.go = "First time3_1";

		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_LaMar" && GetPassengerNumber(pchar, GetCharacterIndex("ApostatesFB")) != -1)
		{
		link.l1 = "Мне нужна информация о человеке в солидных доспехах и богатой шляпе, он у вас здесь часом не появлялся?";
		link.l1.go = "Apostates_man_1";
		}
			
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_DN" && !CheckAttribute(npchar, "quest.APS_DN"))
		{
		link.l1 = "Мне нужно встретится с нашим общим знакомым...";
		link.l1.go = "Apostates_man_4";
		}
			
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "fromBeliz_toPortRoyal")
		{
		link.l1 = "Я прибыл" + GetSexPhrase("","а") + " к мастеру, по его просьбе.";
		link.l1.go = "Apostates_man_5";
		}
			
		break;

		case "First time3_1":
	                     PlaySound("VOICE\Russian\gotica\MATT\DIA_ADDON_MATT_HELLO_10_01.wav");
		dialog.text = "А, новичок, прекрасно, нам сейчас пригодится каждый человек.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time3";
		break;


/// ******************** Фредерик Бамер ***********************************

		case "Frederic":
	                     PlaySound("VOICE\Russian\Apostates_01.wav");
		dialog.text = "Слушай сюда парень. Благодарю... Письмо у меня... А ты загляни на досуге к ростовщику Саванны ла Мар и спроси Рэндольфа Кэннелла. Может и для тебя найдется дельце.";
		link.l1 = "Эй, постой!";
		link.l1.go = "Frederic_exit";
		NextDiag.TempNode = "GothicApostates";
		break;
		
		case "Frederic_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS");
		break;

/// ******************** Монахи ***********************************

		case "Monah":
		dialog.text = "Слава Тебе Господи, он не добрался до письма. " + GetSexPhrase("Брат","Сестра") + " мо" + GetSexPhrase("й","я") + ", возьми это письмо, передай Его Святейшеству Епископу отцу Винсенто, он возблагодарит тебя. Ближайший месяц он будет на...";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_PuertoPrincipe_Port_MonkDead");
		NextDiag.TempNode = "Monah";
		break;

		case "Monk_PuertoPrincipe_tavern":
		dialog.text = "Так это ты, вероотступни" + GetSexPhrase("к","ца") + ", помог" + GetSexPhrase("","ла") + " этим еретикам завладеть ценным письмом?!";
		link.l1 = "Да, это я, а будешь много разговаривать - отправишься вслед за ним!";
		link.l1.go = "Monk_PuertoPrincipe_fight";
		link.l2 = "Я? С какой стати?! Я здесь не причем! И вообще, я здесь случайно...";
		link.l2.go = "Monk_PuertoPrincipe_tavern_1";
		break;
		
		case "Monk_PuertoPrincipe_fight":
		AddDialogExitQuest("GothicApostates_ENDGAME");
		DialogExit();
		break;
		
		case "Monk_PuertoPrincipe_tavern_1":
		dialog.text = "Случайно говоришь? Пообщаемся предметно в нашей обители правды. У тебя там будет возможность раскаяться в своих грехах!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_Santiago");
		break;

		case "Monk_in_Santiago":
		dialog.text = "Ну что, заблудшая овца, продолжаешь упорствовать в своих грехах или раскаешься? Обещаю, без мучений предстанешь пред Господом нашим.";
		link.l1 = "Я не понимаю, о чем вы? Это какая-то роковая ошибочка! Прошу меня выпустить отсюда, я законопослушн" + GetSexPhrase("ый","ая") + " " + GetSexPhrase("гражданин","гражданка") + "!";
		link.l1.go = "Monk_in_Santiago_1";
		break;
		
		case "Monk_in_Santiago_1":
		dialog.text = "Я вижу, что мои слова не доходят до тебя. Я бы с удовольствием уже сейчас приступил бы к процедуре допроса, да только тебе повезло. С тобой хочет лично побеседовать его святейшество - Епископ отец Винсенто, а он сейчас в отъезде на Мартинике.";
		link.l1 = "Я не знаю никакого епископа Винсенто.";
		link.l1.go = "Monk_in_Santiago_2";
		break;
		
		case "Monk_in_Santiago_2":
		dialog.text = "Ты не знаешь Епископа отца Винсенто... Хм! Ничего, у тебя будет возможность с ним познакомиться, и даже подружиться, когда он лично примерит на тебя 'испанский сапог'.";
		link.l1 = "Помилуйте, да за что мне такое?";
		link.l1.go = "Monk_in_Santiago_3";
		break;
		
		case "Monk_in_Santiago_3":
		dialog.text = "Ничего- ничего,  посиди немного, неделька другая без воды и пищи придадут тебе силы, нечестив" + GetSexPhrase("ец","ая") + ".";
		link.l1 = "...";
		link.l1.go = "Monk3_exit";
		break;

		case "Monk3_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS_in_Santiago_continue3");
		break;

/// ******************** Фраера ***********************************

		case "Man_in_SantiagoPrison":
	                     PlaySound("VOICE\Russian\Apostates_08.wav");
		dialog.text = "Эти испанцы просто звери. Да, не сложно было догадаться, что именно здесь тебя и будут содержать.";
		link.l1 = "А кто вы такие и что вам от меня нужно?";
		link.l1.go = "Man_in_SantiagoPrison_1";
		break;
		
		case "Man_in_SantiagoPrison_1":
	                     PlaySound("VOICE\Russian\Apostates_09.wav");
		dialog.text = "Вам здорово повезло, что вы ещё живы. Ничего нам не нужно от тебя. Магистр сказал, что тебя арестовали, и сказал где тебя искать.";
		link.l1 = "Что за магистр? Не знаю никакого магистра.";
		link.l1.go = "Man_in_SantiagoPrison_2";
		break;
		
		case "Man_in_SantiagoPrison_2":
		dialog.text = "Зато он тебя знает от Фредерика Бамера. Ты ему услугу оказал" + GetSexPhrase("","а") + " в порту Пуэрто Принсипе, а он не забывает добра. Ладно, собирайся, будем выбираться из этого логова.";
		link.l1 = "Каким образом? У меня нет ни оружия, ни корабля...";
		link.l1.go = "Man_in_SantiagoPrison_3";
		break;
		
		case "Man_in_SantiagoPrison_3":
		dialog.text = "Наверняка твои вещи в одном из сундуков этого мрачного места, не задерживайся здесь, скоро набегут солдаты, забирай свои вещи и беги сразу за город, там получишь инструкции.";
		link.l1 = "Понял" + GetSexPhrase("","а") + ", спасибо.";
		link.l1.go = "Man_exit";
		break;

		case "Man_exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuest("GothicApostates_APS_Santiago_prison_break");
		break;
		
		case "Man_in_SantiagoPrison_4":
	                     PlaySound("VOICE\Russian\Apostates_01.wav");
		dialog.text = "Ну что, " + GetSexPhrase("друг","подруга") + ", все получилось.";
		link.l1 = "Да, спасибо, смог" + GetSexPhrase("","ла") + " выбраться, думал" + GetSexPhrase("","а") + " каюк мне там настанет.";
		link.l1.go = "Man_in_SantiagoPrison_5";
		break;
		
		case "Man_in_SantiagoPrison_5":
		dialog.text = "Видно не судьба тебе окончить свое бренное существование в застенках инквизиции.";
		link.l1 = "Да, видно не судьба, а ты кто, если не секрет?";
		link.l1.go = "Man_in_SantiagoPrison_6";
		break;
		
		case "Man_in_SantiagoPrison_6":
		dialog.text = "Не секрет, да вот время нет объяснять. Помнишь, что Фредерик Бамер сказал? Вот и сходи к нему в Саванну ла Мар, там у ростовщика стоит наблюдатель Джейкоб Невил, это наш человек он пропустит тебя\nПравда, прежде чем показываться к нему на глаза, ты долж" + GetSexPhrase("ен","на") + " сделать еще одно дело, это от меня, личная просьба.";
		link.l1 = "Конечно, что требуется?";
		link.l1.go = "Man_in_SantiagoPrison_7";
		break;
		
		case "Man_in_SantiagoPrison_7":
		dialog.text = "Тебе надо добраться на Тринидад и Тобаго. Найди человека по имени Филип Бличер, он должен быть в одном из домов в городе, он ведёт уединённый образ, поэтому спрашивать в трактире или ещё у кого нет смысла.";
		link.l1 = "И, что это за человек, такой?";
		link.l1.go = "Man_in_SantiagoPrison_8";
		break;
		
		case "Man_in_SantiagoPrison_8":
		dialog.text = "О, это кровавая история. Он долгое время ходил старшим помощником капитана на одном из испанских торговых судов. \nВернувшись из очередного рейса, обнаружил у себя в доме погром. Пропала его любимая жена Агата. В случившемся, он подозревает происки Испанской инквизиции. \nИ вот, продав все, что у него было, прослышав про нашу борьбу с этими испанскими 'святошами', он, горя желанием отомстить, прибыл в Новый свет и ищет встречи с Магистром.";
		link.l1 = "Хорошо, я понял, найду его, хотя еще сам" + GetSexPhrase("","а") + " не представляю, как буду отсюда выбраться...";
		link.l1.go = "Man_in_SantiagoPrison_9";
		break;
		
		case "Man_in_SantiagoPrison_9":
		dialog.text = "Об этом мы позаботились. В бухте мыса Камагуэй, увидишь свой корабль в целости и сохранности, благо команда у тебя смышленая - сумели пригнать его без капитана.";
		link.l1 = "Отлично, никак не ожидал" + GetSexPhrase("","а") + ".";
		link.l1.go = "Man_in_SantiagoPrison_10";
		break;
		
		case "Man_in_SantiagoPrison_10":
		dialog.text = "Чего не ожидал" + GetSexPhrase("","а") + "? Что у нас штурман  найдется твою посудину перегнать? Хе-хе. Удачи тебе, капитан.";
		link.l1 = "До встречи и спасибо за помощь.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_Santiago_shore");
		break;

/// ********************Филип Бличер***********************************

		case "Apostates_FB":
	                     PlaySound("VOICE\Russian\worker.wav");
		dialog.text = "Я простой рабочий, я ничего не знаю. Кто вы так" + GetSexPhrase("ой","ая") + ", и что вам от меня надо?";
		link.l1 = "Филип Бличер если я не ошибаюсь?";
		link.l1.go = "Apostates_FB_1";
		break;
		
		case "Apostates_FB_1":
		dialog.text = "Да это именно я, но я вас не знаю, сеньор" + GetSexPhrase("","ита") + ", кто вы?";
		link.l1 = "Тебе и не надо меня знать, я выполняю поручение от Магистра, этого человека, я надеюсь, ты знаешь.";
		link.l1.go = "Apostates_FB_2";
		break;
		
		case "Apostates_FB_2":
		dialog.text = "О, наконец-то! Я уже и надежду всякую потерял выбраться отсюда. Скорее, прошу вас, доставьте меня к нему!";
		link.l1 = "Давай, держись ближе ко мне, надеюсь пробьемся. Ты умеешь обращаться со шпагой?";
		link.l1.go = "Apostates_FB_3";
		break;
		
		
		case "Apostates_FB_3":
		dialog.text = "Шпагой? Владею, сеньор" + GetSexPhrase("","ита") + " капитан, и весьма умело.";
		link.l1 = "Тогда вперед, будем пробиваться на корабль.";
		link.l1.go = "Exit";
		Flag_PIRATE();
		EnemyNationHunterOnMap(true);//запуск перехватчиков
		AddDialogExitQuest("GothicApostates_APS_from");
		break;
		
				
		case "Apostates_FB_6":
	                     PlaySound("VOICE\Russian\officer03.wav");
		dialog.text = "Мне всегда хотелось поступить на службу к порядочному человеку.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Apostates_FB_7";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog2");
		break;
		
		case "Apostates_FB_7":
		dialog.text = "Буду с Вами откровенен, Магистр. Прослышав про Вашу борьбу против испанской инквизиции, хочу быть полезен Вам в этом деле. Готов выполнить любое Ваше поручение, какое бы мне не доверили. \nПорукой моего лояльного отношения к Вашему движению будет то, что случилось с моей женой Агатой. Я наверняка уверен, что тут не обошлось без руки инквизиции.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Apostates_FB_8";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog6");
		break;
		
		case "Apostates_FB_8":
		dialog.text = "Спасибо, Магистр.";
		link.l1 = "...";
		link.l1.go = "Exit";
	                     sld = CharacterFromID("ApostatesFB");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesRK"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog9");
		break;

		case "Apostates_FB_Shore":
	                     PlaySound("VOICE\Russian\worker.wav");
		dialog.text = "...";
		link.l1 = "Можешь не говорить как ты докатился до такой жизни, твоя жизнь, один лишь обман. Пощады просить не стоит, прими хоть смерть с достоинством, нечестивец со своими приспешниками ада.";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_Jamaica_5");
		break;

/// ********************испанский офицер ***********************************

		case "Apostates_SpOfficerInStJuan":
	                     PlaySound("VOICE\Russian\z_arest_01.wav");
		dialog.text = "Именем губернатора Порт-оф-Спейна, вы арестованы, сеньор" + GetSexPhrase("","ита") + ". Во избежание применения грубой физической силы, я вам предлагаю немедленно проследовать за мной.";
		link.l1 = "А, собственно в чём дело? Я не в чем не виноват" + GetSexPhrase("","а") + ", хорошо, приказывайте куда идти.";
		link.l1.go = "Apostates_SpOfficerInStJuan_END_GAME";
		link.l2 = "Я сейчас буду вынужден" + GetSexPhrase("","а") + " сам" + GetSexPhrase("","а") + " применить грубую физическую силу, если вы не оставите меня в покое, сеньор комендант. Поверьте, сеньор комендант, у меня сегодня плохое настроение...";
		link.l2.go = "Apostates_SpOfficerInStJuan_1";
		break;
		
		case "Apostates_SpOfficerInStJuan_END_GAME":
		AddDialogExitQuest("GothicApostates_APS_END");
		DialogExit();
		break;
		
		case "Apostates_SpOfficerInStJuan_1":
		dialog.text = "Верить тебе? Думаю оно у тебя поднимется, когда увидишь моих бойцов. Ну что ж, из города вам все равно не уйти, жив" + GetSexPhrase("ым","ой") + ". Этот дом окружен лучшими бойцами!";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostates_APS_Trinidad_man");
		break;

//********************* Джейкоб Невил*****************************

		case "Apostates_man_1":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "Наконец-то, вас уже ждут, капитан. Зайдете в комнату, там спокойно можете пообщаться с ним, а я покараулю, что бы вам никто не мешал. Одну минутку, сейчас открою дверь.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSbank");
		break;

		case "Apostates_man_2":
		dialog.text = "Всё, можете проходить.";
		link.l1 = "Спасибо дружище.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_bank");
		break;

		case "Apostates_man_3":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "Наконец-то, капитан. Вы вовремя.";
		link.l1 = "Да, и мне нужно увидеть Магистра. Он у себя!";
		link.l1.go = "Apostates_man_4";
		break;
		
		case "Apostates_man_4":
		dialog.text = "Разумеется, "+GetAddress_Form(npchar)+", он у себя в резиденции. Он ждал Вас...";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostatesAPSbank4");
		break;

		case "Apostates_man_8":
		dialog.text = "Всё, можете проходить.";
		link.l1 = "Спасибо, ты настоящий друг. Не потеряй ключ, я очень обижусь.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_message");
		break;

		case "Apostates_man_PortoBellofrom":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "...";
		link.l1 = "Магистр у себя!";
		link.l1.go = "Apostates_man_PortoBellofrom_1";
		break;
		
		case "Apostates_man_PortoBellofrom_1":
		dialog.text = "Да...";
		link.l1 = "Что ты не весел? Давай открывай двери у меня мало времени.";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostates_APS_dialogEnd1");
		break;

		case "Apostates_man_PortoBellofrom_2":
		dialog.text = "Вам показалось. Всё, можете проходить.";
		link.l1 = "Мм...Спасибо.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostates_APS_dialogEnd5");
		break;

		case "Apostates_man_APSH":
	                     PlaySound("VOICE\Russian\officer_common_3.wav");
		dialog.text = "Моё под чтение капитан.";
		link.l1 = "Благодарю. Магистр у себя!";
		link.l1.go = "Apostates_man_APSH_1";
		break;
		
		case "Apostates_man_APSH_1":
		dialog.text = "Да...";
		link.l1 = "Хорошо, будь добр открой дверь.";
		link.l1.go = "Exit";
		AddDialogExitQuest("APSH_Ruins1");
		break;

		case "Apostates_man_APSH_2":
		dialog.text = "Как я Вам завидую капитан, можете проходить.";
		link.l1 = "Ну... Каждому Своё...";
		link.l1.go = "exit";
		AddDialogExitQuest("APSH_Ruins5");
		break;













		
		case "Apostates_man_10":
		dialog.text = "Магистра сейчас на острове нет, но, тем не менее, для вас есть одно поручение.";
		link.l1 = "И в чем заключается мое поручение?";
		link.l1.go = "Apostates_man_11";
		break;
		
		case "Apostates_man_11":
		dialog.text = "Собрать некоторое количество материалов, для постройки новой колонии.";
		link.l1 = "То есть мне предстоит на время стать купцом...";
		link.l1.go = "Apostates_man_12";
		break;
		
		case "Apostates_man_12":
		dialog.text = "Не совсем так, капитан. Деньги на покупку строительных материалов в сумме 50 000 песо мастер оставил у меня и просил передать их вам.";
		link.l1 = "Сколько, чего и куда я долж" + GetSexPhrase("ен","на") + " привезти?";
		link.l1.go = "Apostates_man_13";
		break;
		
		case "Apostates_man_13":
		dialog.text = "Вам, надлежит снарядить торговый караван и доставить 500 единиц сандала и 2000 штук досок на остров Эспаньола. В пиратском поселении, в таверне, у вас заберут товар, что бы потом переправить его в соответствующее место.";
		link.l1 = "Ясно. Я как-то ограничен" + GetSexPhrase("","а") + " в сроках?";
		link.l1.go = "Apostates_man_14";
		break;
		
		case "Apostates_man_14":
		dialog.text = "Нет, капитан, в сроках вы не ограничены, но, все же, не затягивайте этот процесс.";
		link.l1 = "Все ясно, передайте мастеру, что груз будет доставлен в кратчайшие сроки.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
		AddDialogExitQuest("GothicApostates_APS_trade");
		break;

//********************* Рэндольф Кэннелл*****************************

		case "Second life":
	                     PlaySound("VOICE\Russian\QuestMan03.wav");
		dialog.text = "Да, мне говорили, что ты меня ищешь. Зачем же я тебе понадобился?";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_1";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog4");
		break;
		
		case "second_1":
		dialog.text = "Сочувствую твоему горю.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_2";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog8");
		break;
		
		case "second_2":
		dialog.text = "Иди сейчас в магазин, оттуда тебя переправят мои люди в убежище, мы ни кому не отказываем в своей помощи, если человек действительно в ней нуждается.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_3";
	                     sld = CharacterFromID("ApostatesRK");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("ApostatesFB"));
		AddDialogExitQuest("GothicApostates_APS_bank_dialog11");
		break;
		
		case "second_3":
	                     PlaySound("VOICE\Russian\QuestMan05.wav");
		dialog.text = "Приветствую тебя. Меня зовут Рэндольф Кэннелл, но близкие мне люди предпочитают называть меня Магистр. Тебе рекомендации не нужны, твои поступки говорят сами за себя.";
		link.l1 = "Спасибо, Рэндольф, за радушный прием и за то, что вытащил меня из места 'истины', долго бы я там не протянул" + GetSexPhrase("","а") + " - это факт.";
		link.l1.go = "second_4";
		break;
		
		case "second_4":
		dialog.text = "Да, знаю, и не таких бойцов там раскалывали, рассказывают даже такое, что и не знали никогда в жизни.";
		link.l1 = "Я бы уж точно рассказал" + GetSexPhrase("","а") + ", не перевариваю пыток, то ли дело в честном бою с врагом встретиться...";
		link.l1.go = "second_5";
		break;
		
		case "second_5":
		dialog.text = "Ладно, проехали этот печальный эпизод в твоей жизни. Предлагаю тебе присоединиться к нашему движению. Если соглас" + GetSexPhrase("ен","на") + ", то дам тебе ответственное и рискованное поручение.";
		link.l1 = "Я бы с удовольствием, да вот смущает меня моральная сторона этого дела... Это что же получается, вы идете против Церкви?";
		link.l1.go = "second_6";
		break;
		
		case "second_6":
		dialog.text = "Нет, " + GetSexPhrase("дружище","дорогая") + ", так это трактуют только католические священники, которые избрали себе орудием для истребления инакомыслящих инквизицию\nНаша история уходит своими корнями в глубокое прошлое, начало которого выводится от орденов тамплиеров и гильдий каменщиков XIII века, но последнее яркое событие произошло в 16 веке.";
		link.l1 = "Что за событие?";
		link.l1.go = "second_7";
		break;
		
		case "second_7":
		dialog.text = "Да, ты наверняка знаешь. О той кровавой ночи на праздник Святого Варфоломея будут вспоминать еще века!";
		link.l1 = "Я понял" + GetSexPhrase("","а") + ", это ты про Варфоломеевскую ночь говоришь, когда всех гугенотов истребили.";
		link.l1.go = "second_8";
		break;
		
		case "second_8":
		dialog.text = "Ну, положим не всех. С тех пор нас кем только не называют: вероотступниками, еретиками, сектантами. Поверь, мы такие же, как и все нормальные люди - верим в Спасителя и зла никому не желаем!";
		link.l1 = "Я в этом и не сомневаюсь, во всяком случае, на кострах людей не сжигаете.";
		link.l1.go = "second_9";
		break;
		
		case "second_9":
		dialog.text = "Именно так. С тех пор идет постоянное истребление наших собратьев по всему цивилизованному миру. Мы - изгои, которые вынуждены бежать со своих земель и искать убежища в Новом Свете. \nТак, что если хочешь присоединиться к нам, милости просим. Для тако" + GetSexPhrase("го","й") + " " + GetSexPhrase("парня","девчонки") + " всегда найдется пара-тройка ответственных поручений.";
		link.l1 = "Нет, спасибо, у меня своих дел по горло, так что дальше Вы без меня как-нибудь.";
		link.l1.go = "second_10";
		link.l2 = "Конечно, я в деле, только есть одна проблема, я, все-таки, капитан корабля, и мне нужно заботиться о благополучии своей команды.";
		link.l2.go = "second_12";
		break;
		
		case "second_10":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 20000);
                                          Log_Info("Вы получили 20000 песо");
		dialog.text = "Ну что ж, я тебе доверяю и надеюсь, что нас ты не предашь. Удачи тебе. Кстати, возьми компенсацию за твои мытарства, и за то, что доставил ко мне этого бедолагу.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		AddDialogExitQuest("GothicApostates_APS_END");
		break;
		
		case "second_11":
		dialog.text = "Да прибудут с тобой силы, " + GetSexPhrase("друг","сестра") + " мо" + GetSexPhrase("й","я") + ".";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		break;
		
		case "second_12":
		dialog.text = "О, за этим дело не станет! Каждое мое поручение будет щедро оплачено. Пока в этих водах нас существенно поддерживает только Голландия, но и этого достаточно для реализации нашей великой цели. \nКстати, возьми небольшую компенсацию за твои мытарства, и за то, что доставил ко мне этого беднягу.";
		link.l1 = "...";
		link.l1.go = "second_13";
		break;
		
		case "second_13":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 40000);
	                     ChangeCharacterComplexReputation(pchar, "nobility", 10);
		dialog.text = "Вот твое первое задание - отправляйся к ростовщику в Сан-Хуан. У него есть очень важная информация для нас.";
		link.l1 = "Без проблем, считай, что я уже в пути, кстати, ты мне не откроешь тайну, что же все-таки было в том злополучном письме?";
		link.l1.go = "second_14";
		break;
		
		case "second_14":
		dialog.text = "Это послание иезуитов к Епископу отцу Винсенто о том, что наше братство планирует осесть в Новом Свете. \nНо, к сожалению, шило в мешке не утаишь, так как не только у нас есть осведомители. Епископу уже давно известны все наши планы, так что смерть того несчастного монаха была лишней жертвой.";
		link.l1 = "Не особенно, я думаю, они печалятся о нем.";
		link.l1.go = "second_15";
		break;
		
		case "second_15":
		dialog.text = "Этого у них не заложено природой. Для них люди - материал для достижения цели... Давай, капитан, заболтались мы уже. Буду ждать тебя здесь. Как придешь с новостями - спроси меня у Джейкоба Невила он будет в курсе.";
		link.l1 = "Уже уш" + GetSexPhrase("ел","ла") + ", счастливо тебе, Магистр. Кстати, откуда такое прозвище у тебя?";
		link.l1.go = "second_16";
		break;
		
		case "second_16":
		GiveItem2Character(pchar, "Mason");
		PlaySound("interface\important_item.wav");
		dialog.text = "Это не прозвище, это звание, которое нужно заслужить.";
		link.l1 = "Понятно.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_11";
		AddDialogExitQuest("GothicApostates_APS_usurer");
		break;

		case "second_20":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Наконец - то...";
		link.l1 = "Здравствуй, Магистр. Мне удалось выяснить важную для тебя информацию.";
		link.l1.go = "second_21";
		break;
		
		case "second_21":
		dialog.text = "Рассказывай, не медли!";
		link.l1 = "Во-первых,  Иезуиты готовят полное и тотальное уничтожение вашего братства во всём регионе, а во-вторых, для этой цели активно привлекаются наемники. Ну и в распоряжении Иезуитов имеется линейный корабль 'Инквизитор'.";
		link.l1.go = "second_22";
		break;
		
		case "second_22":
		dialog.text = "Я предполагал, что этот момент когда-нибудь настанет... Что еще интересного удалось выяснить?";
		link.l1 = "При мне состоялся разговор Епископа с одним из наемников, которому было поручено задание немедленно следовать в Порто Белло и выяснить информацию о тебе.";
		link.l1.go = "second_23";
		break;
		
		case "second_23":
		dialog.text = "В таком случае, тебе надо отправляться в Порто Белло и попытаться его там перехватить, учти он нам нужен живым как заложник, что бы пошли на контакт с нами Иезуиты, сделать нужно тихо и не поднимая волнения, там будут и мои люди\nВ случае успеха, заложника передай моим людям. На все про все у тебя около десяти дней, иначе ты его упустишь.";
		link.l1 = "Все понял" + GetSexPhrase("","а") + ", Магистр, немедленно выдвигаюсь.";
		link.l1.go = "second_24";
		break;
		
		case "second_24":
		dialog.text = "У ростовщика, это наш человек, скажешь, что от меня, возьмешь у него 15000 песо на текущие расходы.";
		link.l1 = "Уже в пути, Магистр.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_26";
		AddDialogExitQuest("GothicApostates_APS_PortoBello");
		break;

		case "second_26":
		dialog.text = "Прошу вас, "+pchar.name+" не медлите!";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_26";
		break;

		case "second_27":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "А, "+pchar.name+"...";
		link.l1 = "Приветствую тебя, Магистр. Я выполнил" + GetSexPhrase("","а") + " твое поручение.";
		link.l1.go = "second_28";
		break;
		
		case "second_28":
		dialog.text = "Спасибо тебе, капитан, но чувствую, что все напрасно.";
		link.l1 = "Что случилось? Что за пессимизм такой?";
		link.l1.go = "second_29";
		break;
		
		case "second_29":
		dialog.text = "Дело в том, что Иезуиты добрались до нашего убежища и полностью вырезали все мирное население! Не пощадили ни женщин, ни детей.";
		link.l1 = "Откуда такая информация? Может это какая-то чудовищная ошибка.";
		link.l1.go = "second_30";
		break;
		
		case "second_30":
		dialog.text = "Нет, ошибки здесь быть не может! Я получил известия от человека которому доверяю как себе.";
		link.l1 = "Как же они узнали, про ваше убежище, ведь об этом знали только посвященные...";
		link.l1.go = "second_31";
		break;
		
		case "second_31":
		dialog.text = "Все оказывается банально просто. Помнишь того человека, которого ты доставил" + GetSexPhrase("","а") + " ко мне из Тринидада и Тобаго?";
		link.l1 = "Как не помнить, помню, конечно.";
		link.l1.go = "second_32";
		break;
		
		case "second_32":
		dialog.text = "Так вот, это оказался шпион иезуитского ордена. Все вынюхал, разузнал и передал информацию куда следует.";
		link.l1 = "Так вот почему нам солдаты в Порт-оф-Спейне дали возможность уйти, оказывается, все шло по заранее запланированному сценарию.";
		link.l1.go = "second_33";
		break;
		
		case "second_33":
		dialog.text = "Да уж, этот негодяй к тому же помог сбежать плененному тобой наемнику, которого мы содержали под арестом.";
		link.l1 = "Знал бы про такое, убил" + GetSexPhrase("","а") + " бы 'крысу' еще в Порт-оф-Спейне. Значит и здесь не безопасно, вы так не думаете Магистр!";
		link.l1.go = "second_34";
		break;
		
		case "second_34":
		dialog.text = "Невозможно заранее просчитать все шаги врагов. Это очевидно, придут и сюда, мы расставили дозорных на случай нежданных гостей, так что спать можно спокойно.";
		link.l1 = "Мм... Это правильно, Магистр, я понимаю твое негодование, но нельзя раскисать. Мы должны дать адекватный удар Иезуитам, чтобы неповадно было.";
		link.l1.go = "second_35";
		break;
		
		case "second_35":
		dialog.text = "Оптимизма у тебя хоть отбавляй. Каким образом мы это сделаем? У нас остался только один корабль\nХотя, есть не подтверждённая информация, что из Санто-Доминго отходит золотой караван для колонии Картахены\nПоговаривают, что этот конвой состоит из новых кораблей, что самое интересное золото будет погружено на новый линейный корабль, прибывший из Старого Света с верфей Испании.";
		link.l1 = "Ну тогда почему бы её не проверить.";
		link.l1.go = "second_36";
		break;
		
		case "second_36":
		dialog.text = "Если тебе удастся эта авантюра, золото лишним не будет, но нам необходимы корабли. Приведи этот новый линейный корабль с этим золотом, таким образом мы с экономим массу времени на приобретения кораблей\nТем более такой линейный корабль на местных верфях не купить. Тебе дать в помощь наш корабль?";
		link.l1 = "Нет, од" + GetSexPhrase("ин","на") + " справлюсь, а для золота у меня всегда найдется место. Корабль постараюсь захватить.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_37";
		AddDialogExitQuestFunction("GothicApostatesAPSGoldShip");
		break;
		
		case "second_37":
		dialog.text = "Если то, что мы задумали, удастся - это будет во истину чудо!";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_37";
		break;

		case "second_38":
	                     PlaySound("VOICE\Russian\QuestMan06.wav");
		dialog.text = "...";
		link.l1 = "Магистр. У меня для вас есть новости.";
		link.l1.go = "APSGoldConvoy_Check";
		break;

		case "APSGoldConvoy_Check"://начинаем проверять
		int iHal = 0;
		for(i = 0; i < COMPANION_MAX; i++)
		{
		iTemp = GetCompanionIndex(PChar, i);
		if(iTemp > 0)
		{
		sld = GetCharacter(iTemp);					                                                   pchar.questTemp.APS.Spa.CompanionIndex = sld.Index;
		if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MANOWARV ) iHal++;
			}
		}
		if (iHal > 0)//признак наличия ТГ в компаньонах
		{
		amount = sti(pchar.questTemp.APS.Spa.GldQty) - GetSquadronGoods(pchar, GOOD_GOLD);
		if (amount <= 0)
		{
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Ну, отчета не нужно - после досмотра вашего судна в порту мне всё уже рассказали... Вы отлично справились с поручением, капитан\n Великолепно! Это просто великолепно, какой красивый линейный корабль, просто невероятно, капитан, мои чувства переполнены, прошу прощения!";
		link.l1 = "Спасибо! Приятно слышать лестную оценку своих действий. Корабль действительно превосходный.";
		link.l1.go = "APSGoldConvoy_complete";
		}
		else
		{
		dialog.text = "Ну, отчета не нужно - после досмотра вашего судна в порту мне всё уже рассказали... Капитан, вы привезли не весь груз! Я достоверно знал, сколько золота должно было быть\nЭто задание было не только проверкой ваших боевых качеств, но и вашей честности. Испытания на жадность вы не прошли. Я не желаю иметь с вами дел - покиньте мою резиденцию!";
		link.l1 = "Ну и ладно, будь здоров!";
		link.l1.go = "APSGoldConvoy_fail";
		}
		}
		else
		{
		dialog.text = "Что-то я не вижу у вас в эскадре испанского линейного корабля. Я ведь говорил вам, что его надо обязательно привести призом. Вы его продали?";
		link.l1 = "Гм... вы разве говорили привести корабль? Кажется, речь шла только о золоте.";
		link.l1.go = "APSGoldConvoy_noShip";
		}
		break;

		case "APSGoldConvoy_noShip":
		dialog.text = "Я прекрасно помню, что я говорю, а чего - нет. Вы нарушили условия нашего договора, и я более не желаю иметь с вами дел - проходимцам здесь не место. Покиньте мою резиденцию немедленно!";
		link.l1 = "Ну и черт с тобой!";
		link.l1.go = "APSGoldConvoy_fail";
		break;

		case "APSGoldConvoy_fail":
                                          LocatorReloadEnterDisable("PortAntonio_bank", "reload2", true);//закроем банк
		DialogExit();
	                     AddQuestRecord("APS", "20");
	                     CloseQuestHeader("APS");
	                     DeleteAttribute(pchar, "APS");
		break;

		case "APSGoldConvoy_complete":
		dialog.text = "Зайдите ко мне завтра. Мне нужно подумать о том, какую предложить работу, достойную для вас. А за выполненное поручение, награда - вы ее завтра же и получите от меня лично. До встречи!";
		link.l1 = "Хорошо, магистр. Я приду к вам завтра.";
		link.l1.go = "exit";
                                         SetFunctionTimerCondition("GothicApostatesAPS_Work", 0, 0, 1, false);
		AddDialogExitQuestFunction("APSGoldConvoy_Remove");
		AddSimpleRumourCity("Говорят, что вы ограбили золотой конвой. Лихо! Вы отчаянный и бравый моряк, капитан!", "FortOrange", 10, 3, "");
		break;

		case "second_40":
	                     PlaySound("VOICE\Russian\QuestMan05.wav");
		dialog.text = "Вот и Вы... Рад Вас видеть капитан. И так с захваченного корабля призом часть принадлежит Вам лично, что составило 774000 песо, извольте получить\nОстальные деньги пойдут на восстановление нашего убежища, а корабль захваченный Вами послужит нам верой и правдой от агрессивных Иезуитов.";
		link.l1 = "Отлично. Рад это слышать.";
		link.l1.go = "second_41";
		break;

		case "second_41":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 774000);
		dialog.text = "Ну и от меня лично, примите этот скромный подарок. Надеюсь вы знаете как с ним обращаться.";
		link.l1 = "Ух, ты...";
		link.l1.go = "second_42";
		break;

		case "second_42":
		GiveItem2Character(pchar, "sextant2");
		Log_Info("Вам подарили секстант");
		PlaySound("interface\important_item.wav");
		dialog.text = "...";
		link.l1 = "Спасибо, не ожидал... Какие будут дальнейшие наши совместные действия!";
		link.l1.go = "second_43";
		break;

		case "second_43":
		dialog.text = "Дальше как я уже говорил, будет восстановление нашего дома, уверен, в скором времени это место будет центром финансовых инвестиций.";
		link.l1 = "Могу я узнать, где находится наш дом.";
		link.l1.go = "second_44";
		break;

		case "second_44":
		dialog.text = "Капитан "+pchar.name+", хоть я и испытываю к Вам доверительные отношения, но не настолько, что бы посвящать Вас в более секретные планы нашего Ордена, пока ёщё рано. И тем не менее, Вы состоите в наших рядах на самом высоком положении.";
		link.l1 = "Мм... Понятно.";
		link.l1.go = "second_45";
		break;

		case "second_45":
		dialog.text = "Не отчаивайтесь, на восстановление уйдёт много времени, сами понимаете строительство, закупка материалов и много всего включая живую силу\nПо этому у меня нет желания использовать Вас и Ваши навыки в этой рутинной области. Несмотря на сложное положение дел, я хочу предложить Вам нечто другое...";
		link.l1 = "Я слушаю.";
		link.l1.go = "second_46";
		break;

		case "second_46":
		dialog.text = "Не даром наш Орден называют тайным, мы собираем по всему миру и в разные времена всё то, что считается мракобесием, изучаем, делаем выводы, записываем в архивы и эти знания храним\nиногда, по необходимости используем их для достижения определённых целей\nРимская католическая организация знают, чем мы обладаем и за этими знаниями они охотятся по всему миру.";
		link.l1 = "Магистр давайте ближе к делу.";
		link.l1.go = "second_47";
		break;

		case "second_47":
		dialog.text = "Хорошо. Вы, наверное, слышали, что на этом острове, более года тому назад, публичной казни в цепях был предан известный пират - Чарли Вейн\nОн должен был болтаться в железной клетке еще год, являясь наглядным примером для тех, кто решил заниматься пиратским промыслом\nТак вот, представьте себе - тело Вейна исчезло из клетки... Совершенно непостижимым образом... И в тот же день были убиты один из местных священников Порт Рояля и несколько самых прилежных прихожан. Странное совпадение, не правда ли?";
		link.l1 = "Ну, а разве нам не наплевать на смерть этих священников, пусть хоть всех их...";
		link.l1.go = "second_48";
		break;

		case "second_48":
		dialog.text = ""+pchar.name+" пойми, мы не воюем против плоти и крови и к людям относимся с почтением, большинство из священников это люди обманутые учением организации которая прикрывается именем Христа Спасителя. Мы должны быть выше и благоразумнее и в помыслах и делах.";
		link.l1 = "Прошу прощения, Магистр Вы правы. И так вы хотите, что бы я разузнал о этом исчезновении Чарли Вейна?";
		link.l1.go = "second_49";
		break;

		case "second_49":
		dialog.text = "Всё верно, так вот, в тот день одному из прихожан церкви Порт Рояля - Джону Флаю, удалось спастись бегством. Он утверждал, что на него напал живой скелет!";
		link.l1 = "Утверждал? Значит придётся найти его и поговорить с ним?";
		link.l1.go = "second_50";
		break;

		case "second_50":
		dialog.text = "Это вряд ли... Он накинул себе пеньковый галстук прямо у себя дома. Говорить нужно с представителем церкви. Действуйте и не затягивайте с этим делом, по окончании расследования приходите, возможно будут к тому времени и другие тайны!";
		link.l1 = "Отлично. Спасибо, я всё понял.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_51";
	                     AddQuestRecord("APSH", "1");
                                          pchar.questTemp.APS = "APS_ChurchVayne";
		break;
		
		case "second_51":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_51";
		break;

		case "second_55":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую Вас капитан, есть что-нибудь по Чарли Вейну.";
		link.l1 = "Приветствую тебя, Магистр. Кое-что имеется.";
		link.l1.go = "second_56";
		break;

		case "second_56":
		dialog.text = "Я Вас внимательно слушаю.";
		link.l1 = "Ну, всё рассказывать история длинная, в общих чертах если можно...";
		link.l1.go = "second_57";
		break;

		case "second_57":
		dialog.text = "Хорошо, я слушаю.";
		link.l1 = "Чарли Вейн имел древнюю каменную табличку, от которой со слов бывшего священника у него поехала крыша, демоны во сне, чудики и всякая чепуха. Моё мнение крышу ему сорвало убийства людей не в чём неповинных в одной из старых деревень на острове Синт-Маартен. А тело Вейна сняли ночью и захоронили где-нибудь не подалёку Порт-Рояля и раздули очередную байку о живых мертвецах...";
		link.l1.go = "second_58";
		break;

		case "second_58":
		dialog.text = "Может ты и прав, лично у меня на этот счёт другие мнения. Ты там был в этой деревне?";
		link.l1 = "Да, Магистр, я там был, осмотрелся ничего существенного и таинственного, кроме развалин, старой разваленной церкви и склепов с захоронениями.";
		link.l1.go = "second_59";
		break;

		case "second_59":
		dialog.text = "Ты говорил о табличке, она у тебя?";
		link.l1 = "Да табличка у меня, можете сами убедиться, что она ничего сверхъестественного не несёт.";
		link.l1.go = "second_060";
		break;

		case "second_060":
		RemoveItems(PChar, "architects_table_7", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Невероятно?";
		link.l1 = "Что такое, Магистр.";
		link.l1.go = "second_061";
		break;

		case "second_061":
		dialog.text = "Этой табличке несколько тысяч лет, принадлежность этого артефакта уходит в очень далёкие времена. Вот что, мой друг приходи завтра, мне нужно посмотреть свои архивы и сравнить некоторые данные по этому артефакту. Ты молодец.";
		link.l1 = "Магистр, рад стараться. Хорошо, как скажите, завтра так завтра.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_61";
                                         SetFunctionTimerCondition("APSH_Ruins6", 0, 0, 1, false);
		break;

		case "second_61":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_61";
		break;

		case "second_62":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Всё сходится, эту табличку тебе нужно показать одним людям, которые владеют глубокими знаниями. Это очень интересные люди, они как и мы закрыты для многих. Но с ними мы как-то пересекались, теперь тебе выпал шанс познакомиться с ними.";
		link.l1 = "Что за люди?";
		link.l1.go = "second_63";
		break;

		case "second_63":
		GiveItem2Character(pchar, "architects_table_7");
		Log_Info("Вы получили каменную табличку");
		PlaySound("interface\important_item.wav");
		dialog.text = "Ты сам всё узнаешь от них. Забери табличку, найди человека по имени Миксер. Их группа изучают культуру древних народов, их можно найти на острове Тринидада и Тобаго в заливе Маяро, там они обнаружили древнюю пирамиду, очень древнюю. Отдай эту табличку им, этот артефакт для них горазда полезнее, чем для кого-либо.";
		link.l1 = "Понял, что насчёт...";
		link.l1.go = "second_64";
		break;

		case "second_64":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 70000);
		dialog.text = "Я понял и не забываю...Вот за труды твои...";
		link.l1 = "Отлично. Тогда мне пора...";
		link.l1.go = "second_65";
		break;

		case "second_65":
		dialog.text = "Удачи тебе капитан...";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_66";
		AddDialogExitQuest("APSH_Ruins7");
		break;

		case "second_66":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_66";
		break;

		case "GothicApostatesAPS_quests_ship":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Надеюсь, я подошёл вовремя? Теперь я полностью тебе доверяю. После предательства Филип Бличера которого ты привёз у меня были подозрения, что ты с ним за одно. Но теперь все мои сомнения развеяны.";
		link.l1 = "Магистр, я это понял когда пришёл к ростовщику в последний раз, кстати его зарезали Иезуиты, я был свидетелем этого убийства.";
		link.l1.go = "GothicApostatesAPS_quests_ship_1";
		break;

		case "GothicApostatesAPS_quests_ship_1":
		dialog.text = "Вот, черти, говорил я ему уходить с нами, так он не в какую, мол его не посмеют тронуть в поселении, жаль, но нам нужно многое обсудить, давай встретимся в нашем доме, за то время пока тебя не было мы кое в чём преуспели\nНадеюсь мой подарок ещё у тебя. По этим координатам найдёшь остров, там наше убежище. Так, что иди в свою каюту и проложи курс, встретимся в моём кабинете. При подходе к поселению на острове не забудь сменить флаг на чёрный, дружественный.";
		link.l1 = "Договорились.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "GothicApostatesAPS_quests_ship_2";
	                     AddDialogExitQuestFunction("CheckIslandAPS_Coordinates");
		break;

		case "GothicApostatesAPS_quests_ship_2":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "GothicApostatesAPS_quests_ship_2";
		break;

		case "second_70":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя капитан. Как тебе наше поселение!";
		link.l1 = "Ну... Можно было бы и по лучше построить?";
		link.l1.go = "second_71";
	                     //AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres");
		break;

		case "second_71":
		dialog.text = "Можно, но на это нужны средства! То, что ты взял призом хватило только на этот порт, форт и пару домов, но тем не менее весь остров в нашем распоряжении. Поселение будем развивать и дальше, построим достойную колонию не зависимую от держав и с нами им придётся считаться.";
		link.l1 = "Отлично. Но где взять такие огромные деньги? Топить корабли, убивать людей, грабить другие поселения ради того, что бы процветать самим!";
		link.l1.go = "second_72";
		break;

		case "second_72":
		dialog.text = "Разумеется нет, средства можно заработать и другими способами. Среди нашего сообщества есть люди обладающие не только знаниями но и разными умениями, одни могут видеть намного глубже и дальше, другие могут чувствовать утончённо\nЯ так же обладаю некоторыми способностями ясновидения. Многие из нас имеют огромные деньги, но к сожалению все они находятся в разных концах света\nОракул один из немногих богатейших людей покинул Европу и перебрался жить в Россию подальше от назойливых Иезуитов, другие находятся в Африке, ну а я перебрался сюда. Остальные ведут тихий образ жизни в европейских странах, многие из них имеют доступ к Королям, имеют высокие чины и они очень богатые и влиятельные люди, которые готовы платить большие суммы за древние артефакты и знания.";
		link.l1 = "И где взять эти артефакты!";
		link.l1.go = "second_73";
		break;

		case "second_73":
		dialog.text = "Разумеется здесь в Карибском бассейне. Хранители тайн и загадок индейских племён. Их культура довольно древняя и свои традиции хранят по сей день, из этого можно делать выводы и соприкоснуться с тайнами которые европейцы давно утратили, благодаря инквизиции.";
		link.l1 = "Да с этим я уже соприкоснулся когда я вызвал духа Чарли Вейна.";
		link.l1.go = "second_74";
		break;

		case "second_74":
		dialog.text = "И у тебя это получилось?";
		link.l1 = "Да, Магистр, до сих пор поджилки трясутся.";
		link.l1.go = "second_75";
		break;

		case "second_75":
		dialog.text = "Значит ты тот, кому предназначено судьбой вершить суд над приспешниками ада. Чарли Вейн говорил с тобой?";
		link.l1 = "Да, правильнее сказать с тем кто овладел им.";
		link.l1.go = "second_76";
		break;

		case "second_76":
		dialog.text = "Чего он хотел?";
		link.l1 = "Хотел моей смерти, завладеть мною для своих целей.";
		link.l1.go = "second_77";
		break;

		case "second_77":
		dialog.text = "Значит, несомненно, ты тот о ком я думаю.";
		link.l1 = "И кто же я по твоему?";
		link.l1.go = "second_78";
		break;

		case "second_78":
		dialog.text = "Ты Хранитель. Хранители родились ещё за долго до Шумерской цивилизации, твой дух не знает покоя.";
		link.l1 = "Ого, вот так новость?";
		link.l1.go = "second_79";
		break;

		case "second_79":
		dialog.text = "Демоны будут искать способ, что бы в мире живых овладеть тобой, наверное ты им очень нравишься.";
		link.l1 = "Чего не скажешь о них. Есть ещё Хранители!";
		link.l1.go = "second_80";
		break;

		case "second_80":
		dialog.text = "Разумеется ты не один такой, с таким даром. Вас можно пересчитать на пальцах и ты один из них. Невероятно...";
		link.l1 = "Хорошо с чего мы начнём, где искать мы эти будем эти артефакты.";
		link.l1.go = "second_81";
		break;

		case "second_81":
		dialog.text = "Дай мне время, мне необходимо сосредоточится... Зайди ко мне завтра, возможно я увижу более яркую картину.";
		link.l1 = "Договорились. До завтра. Мешать не буду.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_1");
		NextDiag.TempNode = "second_82";
		break;
		
		case "second_82":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_82";
		break;

		case "second_90":
		dialog.text = "...";
		link.l1 = "Приветствую тебя Магистр, ну как, есть что - нибудь!";
		link.l1.go = "second_91";
		break;

		case "second_91":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Рад видеть тебя Хранитель. Да, меня заинтересовала одна история связанная с реинкарнацией на которой я и сосредоточился. Из поселения индейцев племени Шаганумби, ловцы жемчуга выловили человека в море, на его лице был страх и ужас, думали это у него лихорадка, он кричал, бился в судорогах.\nИндейцы провели ритуал над ним, он стал приходить в себя и рассказал, что с ним случилось.\nКак оказалось он моряк, ходил вместе с капитаном Делвином Блейзом на бриге 'Удачливый Джокер'. На их корабле стали происходить страшные вещи, команда при лунном свете стали выглядеть живыми мертвецами, напоминающих зомби или скелетов, от увиденного всего этого он и решил сойти с корабля выпрыгнув за борт, пробыл в море около десяти дней. Я сосредоточился на этой истории и кое-что удалось понять и разглядеть. Картина не очень ясная... Но стоит проверить.";
		link.l1 = "И, что ты увидел!";
		link.l1.go = "second_92";
		break;

		case "second_92":
		dialog.text = "Я увидел человека, на которого охотятся приспешники демона, с которым ты имел честь разговаривать, это очень древний демон со времён Аннунаков, раньше он был ангелом среди престола Бога, после его гордыни и не любви к человекам которых создал Бог его изгнали на землю\nОн же суть воплощения в разные формы, включая тела людей, животных, он могуществен и его уничтожить невозможно до прихода на землю самого Бога, но его можно остановить на некоторое время и что бы это сделать необходимо понять чего он добивается. Эти события звенья одной цепи, в этом нет сомнения.";
		link.l1 = "Ясно, и где же искать того на кого он охотится!";
		link.l1.go = "second_93";
		break;

		case "second_93":
		dialog.text = "Эспаньола, а так же я видел маяк.";
		link.l1 = "На Эспаньоле два маяка, хорошо проверю оба.";
		link.l1.go = "second_94";
		break;

		case "second_94":
		dialog.text = "Удачи... Ну а я пока займусь изучением этого вопроса, возможно что-нибудь раскопаю ещё.";
		link.l1 = "Хорошо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_3");
		NextDiag.TempNode = "second_95";
		break;

		case "second_95":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_95";
		break;

		case "second_96":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, ну как, проверил маяк на Эспаньоле.";
		link.l1 = "Да, всё в точности, нападавшие мертвецы пытались завладеть старинной монетой, которая была у Билла Метью бывшего штурмана капитана Блейза. Тот рассказ о котором вы говорили всё правда, так оно и было. Вселившийся дух в Блейза ищет монеты, всего их три, обладатели этих монет имеют защиту от демонов, но при наличии всех трёх монет, обладатель способен увеличить свои силы в несколько раз.";
		link.l1.go = "second_97";
		break;

		case "second_97":
		dialog.text = "И, монета надеюсь у тебя, можно посмотреть.";
		link.l1 = "К сожалению нет.";
		link.l1.go = "second_98";
		break;

		case "second_98":
		dialog.text = "...";
		link.l1 = "Монета была у меня в руках, я предпринял попытку найти человека со второй монетой, в итоге человек, что я искал, мёртв, его похоронили за пару дней до моего визита на остров Невис. Я решил проверить так ли оно или нет, отправившись на местное кладбище, где я и потерял свою монету.";
		link.l1.go = "second_99";
		break;

		case "second_99":
		dialog.text = "Это как, так, потерял!";
		link.l1 = "Ну... Подошёл парень, дал по голове, забрал монету, больше ничего брать не стал.";
		link.l1.go = "second_100";
		break;

		case "second_100":
		dialog.text = "Так, понятно. Значит воровство можно не брать в расчёт, похоже цель была только монета. Запомнил как выглядел тот парень.";
		link.l1 = "Блондин, голубые глаза, среднего телосложения.";
		link.l1.go = "second_101";
		break;

		case "second_101":
		dialog.text = "Как интересно. Но я так же не терял время зря и решил навести справки по бригу 'Удачливый Джокер', что самое интересное капитан подходит под твоё описание.";
		link.l1 = "Не может быть, Чарли Вейн был скелетом, а этот парень в полне выглядел нормально как ты и я.";
		link.l1.go = "second_102";
		break;

		case "second_102":
		dialog.text = "Хорошо, забегать в перёд не стоит. Но можно предположить, что дух Блейза завладел тремя монетами. Первую забрал у первого помощника, вторую снял с трупа на Невисе, ну а третью забрал у тебя. С чем я вас и поздравляю. Цель достигнута.";
		link.l1 = "Предположим, что ты прав. Не означает ли это, что в ближайшее время дух Блейза будет настолько силён, что противостоять ему будет нереально.";
		link.l1.go = "second_103";
		break;

		case "second_103":
		dialog.text = "Всё верно, так и будет, не удивлюсь тому, если при жизни Блейз ходил на бриге, то дух Блейза будет ходить на мановаре или летать как дракон пепелить всех и всё на своём пути...";
		link.l1 = "Да уж, картина не радужная.";
		link.l1.go = "second_104";
		break;

		case "second_104":
		dialog.text = "Вот, что я подумал, если тебе удалось вызвать дух Чарли Вейна, возможно тебе удастся вызвать и дух Блейза и рискнуть отнять у него эти монеты.";
		link.l1 = "Да, но заклятие духа стражи действуют только один раз и непосредственно в местах где этот дух обитает.";
		link.l1.go = "second_105";
		break;

		case "second_105":
		dialog.text = "Блейз - капитан, его стихия море, поэтому вызвать его можно будет с корабля.";
		link.l1 = "Ну, можно попробовать...";
		link.l1.go = "second_106";
		break;

		case "second_106":
		dialog.text = "Тем не менее выбор - то не велик... Нужно действовать, сходи до исследователей пирамиды к Миксеру, но не с пустыми руками. Попробуй взять у них это заклятие стражи мёртвых и одолеть дух Блейза.";
		link.l1 = "Как думаешь, что им может быть нужным.";
		link.l1.go = "second_107";
		break;

		case "second_107":
		dialog.text = "Им нужны скрижали, каменные таблички, при наличии я думаю они охотно пойдут на сделку. Такие таблички, скрижали можно найти у старой пирамиды на Мэйне, там в своё время их полно было, может, что ещё и осталось.";
		link.l1 = "Хорошо, попробую.";
		
	                     AddDialogExitQuestFunction("GothicObsession_MyxirTakeCoin");
		link.l1.go = "second_108";
		break;

		case "second_108":
		dialog.text = "Миксер уже должен был вернуться домой из храма, его дом находится на Мартинике, там чуть ли не целая библиотека. Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_108";
		break;

		case "second_110":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, есть новости по Блейзу.";
		link.l1 = "Да, чёрт побери, я сделал это, враг уничтожен.";
		link.l1.go = "second_111";
		break;

		case "second_111":
		dialog.text = "Отлично.";
		link.l1 = "У меня для тебя кое - что имеется, посмотри.";
		link.l1.go = "second_112";
		break;

		case "second_112":
		if (CheckCharacterItem(pchar, "Obsession_Coins"))
		{
		dialog.text = "Молодец! Невероятно...";
		link.l1 = "Спасибо!";
		link.l1.go = "Obsession_complete";	
		}
		else
		{
		dialog.text = "Хм... Капитан, не стоит делать из меня идиота.";
		link.l1 = "Магистр, простите, я и сам не понимаю...";
		link.l1.go = "Obsession_nics";
		}
		break;

		case "Obsession_complete":
		RemoveItems(PChar, "Obsession_Coins", 1);
		PlaySound("interface\important_item.wav");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 1500000);
		dialog.text = "Эти монеты определённо имеют высокую стоимость. Вот, что, мне нужно время для того, что бы их продать, я думаю за каждую выручить миллион\nДавай встретимся здесь, через два месяца, я заплачу тебе вперёд, что составит полтора миллиона песо, надеюсь не будет возражений. Но сейчас меня ждут дела, связанные с развитием колонии.";
		link.l1 = "Мне нравится, хорошо, через два месяца буду здесь.";
		link.l1.go = "Exit";	
	                     SetTimerCondition("GothicApostatesAPS_Providence", 0, 0, 60, false);
		NextDiag.TempNode = "second_114";
		break;

		case "second_114":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_114";
		break;

		case "Obsession_nics":
		dialog.text = "В любом случае ты молодец, я рад, что имею честь быть с тобой знакомым. Но сейчас меня ждут дела, связанные с развитием колонии. Возвращайся через пару месяцев.";
		link.l1 = "Мешать не буду. Всего доброго...";
		link.l1.go = "Exit";
	                     SetTimerCondition("GothicApostatesAPS_Providence", 0, 0, 60, false);
		NextDiag.TempNode = "second_113";
		break;
		
		case "second_113":
		dialog.text = ""+pchar.name+" поговорим позже, я занят!";
		link.l1 = "Прошу прощения.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_113";
		break;

		case "second_120":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, как тебе наш город!";
		link.l1 = "Превосходно.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_4");
		NextDiag.TempNode = "second_121";
		break;

		case "second_121":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_121";
		break;

		case "second_122":
		dialog.text = "Сколько хлопот и трудов вложить пришлось для общей цели, это ещё не полностью сделано, но вскоре здесь будет и часовня, бордель, так что мы на высоте, благодаря тебе Хранитель!";
		link.l1 = "Отличная работа! Есть, что - нибудь в плане моих услуг?";
		link.l1.go = "second_123";
		break;

		case "second_123":
		dialog.text = "Да, есть... Слышал ли ты когда - нибудь о библиотеке Замка учёных!";
		link.l1 = "Нет Магистр, не слышал, расскажи мне об этом.";
		link.l1.go = "second_124";
		break;

		case "second_124":
		dialog.text = "В древнее времена был предводитель по имени Куарходрон, о нём мало что известно, но существуют записи о тех давних событиях, которые записаны на каменных табличках, всего их пять. Вот этими табличками заинтересован один человек, который готов заплатить большие деньги.";
		link.l1 = "Ты думаешь они могут быть здесь, на этом архипелаге.";
		link.l1.go = "second_125";
		break;

		case "second_125":
		dialog.text = "Думаю, что да, но не уверен полностью. Эти знания скрыты, проверить их подлинность нет возможности, по некоторым данным этот бассейн когда - то был одним целым материком, произошла катастрофа, то ли упал метеорит, то ли ещё, что - не известно, тем не менее заказчик полностью уверен, что библиотеку нужно искать здесь.";
		link.l1 = "Хорошо, тогда с какого места необходимо начать поиски!";
		link.l1.go = "second_126";
		break;

		case "second_126":
		dialog.text = "Ну, если ты согласен взяться за это дело, мне нужно время, что бы сосредоточится, возможно что - нибудь увижу.";
		link.l1 = "Я не против, хорошо Магистр, мешать не буду, когда к тебе зайти.";
		link.l1.go = "second_127";
		break;

		case "second_127":
		dialog.text = "Приходи завтра.";
		link.l1 = "Договорились.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_5");
		NextDiag.TempNode = "second_128";
		break;

		case "second_128":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_128";
		break;

		case "second_130":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Вот и ты Хранитель. Итак, есть скрытное место на острове Пуэрто-Рико, нужно смотреть там, это всё, что я увидел, теперь уверен полностью, что библиотека Замка учёных существует по сей день.";
		link.l1 = "Хорошо, отправляюсь на поиски.";
		link.l1.go = "second_131";
		break;

		case "second_131":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects");
		NextDiag.TempNode = "second_132";
		break;

		case "second_132":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_132";
		break;

		case "second_133":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Как успехи Хранитель, нашли табличку?";
		link.l1 = "Да, вот можете полюбоваться.";
		link.l1.go = "second_134";
		break;

		case "second_134":
		RemoveItems(PChar, "architects_table_2", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Отлично...";
		link.l1 = "Что на счёт второй, где её искать, вы это место определили!";
		link.l1.go = "second_135";
		break;

		case "second_135":
		dialog.text = "Да. Искать следует на острове Тринидад...";
		link.l1 = "Понял, выдвигаюсь на поиски второй таблички.";
		link.l1.go = "second_136";
		break;

		case "second_136":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_2");
		NextDiag.TempNode = "second_137";
		break;

		case "second_137":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_137";
		break;

		case "second_138":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Как успехи Хранитель, нашли табличку?";
		link.l1 = "Да, вот можете посмотреть и да же подержать.";
		link.l1.go = "second_139";
		break;

		case "second_139":
		RemoveItems(PChar, "architects_table_3", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Отлично...";
		link.l1 = "Что на счёт третьей, где её искать.";
		link.l1.go = "second_140";
		break;

		case "second_140":
		dialog.text = "Искать её следует на острове Синт-Маартен...";
		link.l1 = "Понял, выдвигаюсь на поиски третьей таблички.";
		link.l1.go = "second_141";
		break;

		case "second_141":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_3");
		NextDiag.TempNode = "second_142";
		break;

		case "second_142":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_142";
		break;

		case "second_143":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Как успехи Хранитель, нашли табличку?";
		link.l1 = "Да, вот можете полюбоваться.";
		link.l1.go = "second_144";
		break;

		case "second_144":
		RemoveItems(PChar, "architects_table_4", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Отлично...";
		link.l1 = "Что на счёт четвёртой, где мне её найти?";
		link.l1.go = "second_145";
		break;

		case "second_145":
		dialog.text = "Искать её следует на острове Тортуга...";
		link.l1 = "Тортуга, хорошо, выдвигаюсь на поиски четвёртой таблички.";
		link.l1.go = "second_146";
		break;

		case "second_146":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_4");
		NextDiag.TempNode = "second_147";
		break;

		case "second_147":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_147";
		break;

		case "second_148":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Как успехи Хранитель, нашли табличку?";
		link.l1 = "Да, вот всё в лучшем виде.";
		link.l1.go = "second_149";
		break;

		case "second_149":
		RemoveItems(PChar, "architects_table_5", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Отлично...";
		link.l1 = "И так, что на счёт пятой, где её искать.";
		link.l1.go = "second_150";
		break;

		case "second_150":
		dialog.text = "Искать её следует на Мэйне возле Картахены...";
		link.l1 = "Понятно, что ж выдвигаюсь на поиски пятой таблички.";
		link.l1.go = "second_151";
		break;

		case "second_151":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_architects_5");
		NextDiag.TempNode = "second_152";
		break;

		case "second_152":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_152";
		break;

		case "second_153":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Как успехи Хранитель, нашли табличку?";
		link.l1 = "Да, вот можете полюбоваться.";
		link.l1.go = "second_154";
		break;

		case "second_154":
		RemoveItems(PChar, "architects_table_6", 1);
		PlaySound("interface\important_item.wav");
		dialog.text = "Как странно я видел ещё одну табличку в точности какие ты приносил, мест нет, это означает она у кого-то, ну да ладно, был заказ на 5 табличек, они у нас имеются...\nОсталось дело за малым, передать эти таблички заказчику и получить гонорар. Я думаю на это уйдёт месяц, встречаемся через два месяц в моём кабинете, процент получишь сегодня в виде песо. Но сейчас меня ждут дела, связанные с развитием колонии.";
		link.l1 = "Мешать не буду. Всего доброго... Здесь через два месяца.";
		link.l1.go = "second_155";
		break;

		case "second_155":
                                         PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
	                     AddMoneyToCharacter(pchar, 1250000);
		dialog.text = "Удачи. Хранитель. Кстати, я слышал, что в пиратском поселении Сент-Луи хозяйка таверны, Тёкла, ищет человека для работы.";
		link.l1 = "Спасибо. По возможности зайду к ней и узнаю, что за работу она предлагает.";
		link.l1.go = "Exit";
                                         // Мистер и Миссис Смит начало
                                          pchar.questTemp.GothicSmithy = "SagittaAnn";
	                     AddQuestRecord("Architects", "6");
                                          CloseQuestHeader("Architects");
	                     SetTimerCondition("GothicApostatesAPS_Providence_2", 0, 0, 50, false);
		NextDiag.TempNode = "second_156";
		break;

		case "second_156":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_156";
		break;

		case "second_160":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, как тебе наш город!";
		link.l1 = "Невероятно, как такое может быть, это шедевр.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_7");
		NextDiag.TempNode = "second_161";
		break;

		case "second_161":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_161";
		break;

		case "second_162":
		dialog.text = "Как я и говорил, часовня построена в готическом стиле лучшими строителями на архипелаге, скоро рыночную площадь сделаем...";
		link.l1 = "Да, город вырисовывается просто фантастически, молодцы, отличная работа!";
		link.l1.go = "second_163_b";
		break;
		
		case "second_163_b":
		dialog.text = "...";
		link.l1 = "Магистр, тут такое дело...";
		link.l1.go = "second_163";
		break;

		case "second_163":
		if (CheckCharacterItem(pchar, "architects_table_8"))
		{
		dialog.text = "Я слушаю.";
		link.l1 = "Я нашёл ещё каменную табличку, может тебя она заинтересует. На ней написано о Совете Пяти и о каком - то мече с ловушками.";
		link.l1.go = "Quarhodron_complete";	
		}
		else
		{
		dialog.text = "Я слушаю.";
		link.l1 = "Магистр, простите, я не буду об этом говорить...";
		link.l1.go = "second_nics";
		}
		break;

		case "second_nics":
		dialog.text = "Ну, дело твоё...";
		link.l1 = "Поговорим в следующий раз, пойду прогуляюсь по городу.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_8");
		NextDiag.TempNode = "second_164";
		break;

		case "second_164":
		dialog.text = "Хранитель поговорим позже, сейчас меня ждут дела, связанные с развитием колонии.";
		link.l1 = "Понял. Мешать не буду. Всего доброго...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_164";
		break;

		case "Quarhodron_complete":
		dialog.text = "Теперь это не так уже и важно, заказчик рассчитался за таблички, всё в полном порядке, так, что табличку можешь у себя хранить или отнеси её к исследователям, возможно их заинтересует...";
		link.l1 = "Не скажешь кто заказчик, может я ему отдам, ну раз она ни какой ценности не имеет...";
		link.l1.go = "Quarhodron_complete_1";
		break;

		case "Quarhodron_complete_1":
		dialog.text = "Здесь я тебе не могу ничем помочь, заказчики предпочитают оставаться в тени, без всего лишнего...";
		link.l1 = "Понятно, ну тогда ладно, пойду прогуляюсь по городу.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_164";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_Quarhodron_Myxir");
		break;

		case "second_165":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Сколько хлопот и трудов вложить приходится для общей цели, колония процветает. Рад видеть тебя Хранитель.";
		link.l1 = "Приветствую Магистр, за то есть где якорь бросить под флагом роджера. Есть работа для меня для развития нашего дома.";
		link.l1.go = "second_166";
		break;

		case "second_166":
		dialog.text = "Пока работы нет, но ты можешь поспрашивать в нашей таверне, люди как узнали, что процветает порт так многие сюда рвутся, что бы заработать и жить достойно. Приезжих новых людей очень много, возможно тебе и удастся найти подходящее дело, в случае чего меня поставь в известность.";
		link.l1 = "Понятно, договорились.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_10");
		NextDiag.TempNode = "second_167";
		break;

		case "second_167":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_167";
		break;

		case "second_168":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "...";
		link.l1 = "Магистр, в таверне состоялся разговор с одним человеком, моряком, его рассказ связан с очередной тайной.";
		link.l1.go = "second_169";
		break;

		case "second_169":
		dialog.text = "Что за тайна!";
		link.l1 = "О сокровищах на каком - то из островов. Теперь этот моряк заливает свой страх после тех событий. Ещё он мне передал карту, точнее часть карты, можете сами взглянуть.";
		link.l1.go = "second_170";
		break;

		case "second_170":
		RemoveItems(PChar, "map_part1", 1);
		dialog.text = "Очередные пьяные сплетни, хорошо, давай посмотрим, может я что и увижу. Могу вас заверить,что рай существует. Ведь сейчас мы не умолимо катимся в ад!";
		link.l1 = "Мне зайти завтра!";
		link.l1.go = "second_171";
		break;

		case "second_171":
		dialog.text = "В этом нет нужды, по предметам я могу быстро понять о человеке и происхождении вещей!";
		link.l1 = "Хорошо.";
		link.l1.go = "second_172";
		break;

		case "second_172":
		LAi_Fade("", "");
		dialog.text = "...";
		link.l1 = "Удалось, что нибудь увидеть, понять!";
		link.l1.go = "second_173";
		break;

		case "second_173":
		dialog.text = "Интересно, существование золота правда, но его происхождение довольно старое, золото инков, это может означать, что до сих пор ни кому это золото не досталось. Вот, что, для более ясной картины, нужна вторая половина карты. Дело того стоит. Как найдёшь вторую половину, приходи. Тогда я более чёткую картину смогу увидеть, а этот экземпляр я оставлю у себя если ты не против.";
		link.l1 = "Не против. Попробую найти вторую часть очередной головоломки.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_13");
		NextDiag.TempNode = "second_174";
		break;

		case "second_174":
		dialog.text = "Да прибудут с тобой силы, Хранитель. Могу вас заверить,что рай существует. Ведь сейчас мы не умолимо катимся в ад.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_174";
		break;

		case "second_175":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "...";
		link.l1 = "Вторая часть карты найдена, что можешь сказать Магистр!";
		link.l1.go = "second_176";
		break;

		case "second_176":
		dialog.text = "Отлично, давай посмотрим.";
		link.l1 = "Держи.";
		link.l1.go = "second_177";
		break;

		case "second_177":
		RemoveItems(PChar, "map_part2", 1);
		dialog.text = "Странно, очень странно. Подожди...";
		link.l1 = "...";
		link.l1.go = "second_178";
		break;

		case "second_178":
		LAi_Fade("", "");
		dialog.text = "...";
		link.l1 = "Ну, что Магистр, удалось, что нибудь увидеть, понять!";
		link.l1.go = "second_179";
		break;

		case "second_179":
		dialog.text = "Да, но должен тебя разочаровать, карта фальшивка.";
		link.l1 = "Как так, значит и золота нет! И все мои движения напрасны.";
		link.l1.go = "second_200";
		break;

		case "second_200":
		dialog.text = "Золото есть, но тот кто нарисовал эту карту, сделал это целенаправленно, что бы пустить конкурентов по ложному пути.";
		link.l1 = "Грамотно, похоже я догадываюсь кто.";
		link.l1.go = "second_201";
		break;

		case "second_201":
		dialog.text = "...";
		link.l1 = "Флоренсио Алегрия, капитан фрегата. Что - нибудь ещё увидели Магистр?";
		link.l1.go = "second_202";
		break;

		case "second_202":
		dialog.text = "Да, Хранитель, золото охраняется духами, без предмета такого амулета как амулет Тлалока, прикоснувшись к золоту, того духи наказывают смертью.";
		link.l1 = "Так вот почему золото ни кто ещё не смог взять. Что это за амулет!";
		link.l1.go = "second_203";
		break;

		case "second_203":
		dialog.text = "По приданию этот амулет создан в честь ацтекского бога дождя и грома, сельского хозяйства, огня и южной стороны света - Тлалок. Являясь молодым божеством, может, резвясь, наслать град и удары молнией... Я думаю найдёшь фрегат найдёшь и золото. Но запомни прикасаться к золоту ацтеков без амулета Тлолака не стоит, погибнешь.";
		link.l1 = "Что ж, понятно, постараюсь найти фрегат, всё же не иголка в стоге сена.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_19");
		NextDiag.TempNode = "second_204";
		break;

		case "second_204":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_204";
		break;


		case "second_205":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель. Какие новости на этот раз.";
		link.l1 = "Магистр, я могу Вас порадовать, новости для Вас просто великолепные. Золото ацтеков у меня!";
		link.l1.go = "second_206";
		link.l2 = "Магистр, новостей хороших и утешительных нет, всё это сплетни и очередные пьяные истории рассказанные в пьяном бреду, бредовых людей по верившие в выдуманные тайны. Ваши видения оказались на этот раз неверными!";
		link.l2.go = "second_0206";
		break;

		case "second_206":
		dialog.text = "Отлично, значит ты обошёл заклятие, расскажи...";
		link.l1 = "Да, Магистр, так оно и было, в этой истории, алчность людей, жадности и хитрости, индейцы предвидели всё это с приходом европейцев. Ради этого золота европейцы пустили под нож почти весь древний народ. До появления европейцев, ацтеки правильно относились к золоту - ели на нем, пили воду из золотых кубков и делали красивые украшения для своих женщин, но когда пришли конкистадоры - жадные и беспощадные, и стали убивать людей из-за золотых побрякушек - индейские старейшины собрали большой совет. Было решено схоронить оставшееся золото, а верховный шаман наложил на него заклятие.";
		link.l1.go = "second_207";
		break;

		case "second_207":
		dialog.text = "Как интересно.";
		link.l1 = "Да, ну, мы не такие, поэтому для общей цели прошу принять, часть вклада на развитие поселения.";
		link.l1.go = "second_208";
		break;

		case "second_208":
		dialog.text = "Отлично, давай посмотрим!";
	                      if(sti(pchar.money) >= 9090900)
		{
		link.l1 = "Здесь половина от всего клада.";
		link.l1.go = "second_money";
		}
		link.l2 = "Чёрт у меня не достаточно песо, скоро будут не переживай Магистр, мне нужно обменять золото инков на песо и я сразу же к вам.";
		link.l2.go = "second_money_1";
		break;

       	                   case "second_money_1":
		dialog.text = "Не проблема Хранитель, я подожду.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_208";
		break;

		case "second_money":
		LAi_Fade("", "");
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneyToCharacter(pchar, -9090900);
		dialog.text = "Ого...Отличные новости и своевременны. Ну а теперь, дело за нами по развитию нашего дома. Думаю, через пару месяцев строительство будет полностью завершено.";
		link.l1 = "Не буду мешать. Через два месяца, загляну.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_30");
		NextDiag.TempNode = "second_209";
		break;

		case "second_209":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_209";
		break;

		case "second_0206":
		dialog.text = "Мх...Странно. Хорошо Хранитель, пусть будет так.";
		link.l1 = "Есть работа для меня.";
		link.l1.go = "second_0207";
		break;

		case "second_0207":
		dialog.text = "Работы пока нет.";
		link.l1 = "Жаль, ну, тогда я пойду.";
		link.l1.go = "second_0208";
		break;

		case "second_0208":
		dialog.text = "Всего, наилучшего, Капитан.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_030");
		NextDiag.TempNode = "second_0209";
		break;

		case "second_0209":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_0209";
		break;

		case "second_210":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, как тебе наш город! Чего стоишь, присаживайся есть новости.";
		link.l1 = "Новости, это хорошо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_31");
		NextDiag.TempNode = "second_211";
		break;

		case "second_211":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_211";
		break;
		
		case "second_212":
		dialog.text = "Как я и обещал, бордель на самом высоком уровне, девочки из Ирландии, чистоплотные, будет время зайди не пожалеешь это не тот товар, что в Порт-Рояле, грязные, вонючие английские дамы...";
		link.l1 = "Да, дела у вас тут кипят, что я могу сказать, молодцы...";
		link.l1.go = "second_213";
		break;
		
		case "second_213":
		dialog.text = "К сожалению, работы для тебя пока нет, но ты захаживай время от времени, может быть, что-то да появится.";
		link.l1 = "Жаль, что сейчас ничего нет. Тогда до встречи, Магистр.";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_After3_Building");
		NextDiag.TempNode = "second_229";
		break;
		/*
		case "second_212":
		dialog.text = "Как я и обещал, бордель на самом высоком уровне, девочки из Ирландии, чистоплотные, будет время зайди не пожалеешь это не тот товар, что в Порт-Рояле, грязные, вонючие английские дамы... Но не об этом пойдёт речь.";
		link.l1 = "Да, дела у вас тут кипят, что я могу сказать, молодцы... И, так, о чём пойдёт речь, Магистр.";
		link.l1.go = "second_213";
		break;
		*/
		/*
		case "second_213":
		dialog.text = "Я получил письмо от Оракула.";
		link.l1 = "От того самого, который уехал в Россию.";
		link.l1.go = "second_214";
		break;
		*/

		case "second_214":
		dialog.text = "Да, от него. Ты в курсе почему его называют Оракул!";
		link.l1 = "Нет, но догадываюсь.";
		link.l1.go = "second_215";
		break;

		case "second_215":
		dialog.text = "Он обладает многими дарами, самый сильный из всех живущих на планете, провидец и предсказатель его имя никто не знает, так как имён у него много, он вынужден скрываться не только от инквизиции но и от политиков, королей, придворных жаждующих знаний о своём будущем, они не понимают, что такие познания могут изменить ход истории!";
		link.l1 = "Понятно, что он написал вам Магистр?";
		link.l1.go = "second_216";
		break;

		case "second_216":
		dialog.text = "Речь пойдёт о будущем и настоящем. И это не пустой звук в виде байки в таверне, это подробное содержание от самого Оракула, он всё предсказывает в точности.";
		link.l1 = "Мм... Хорошо, я слушаю.";
		link.l1.go = "second_217";
		break;

		case "second_217":
		dialog.text = "И, так к делу. История будущего о зловещей трагедии. Событие началось в городе Галифакс, Новая Шотландия на Атлантическом побережье Канады\nВ мае 1861 года небольшая группа людей стала свидетелями спуска на воду самого первого парусного судна построенного на верфи получившее название 'Амазонка'\nНо неудачи начали преследовать бригантину с первых дней. В первом рейсе капитана парусного судна 'Амазонка' свалила смертельная болезнь\nСледующий капитан посадил бригантину 'Амазонка' на мель, которая оказалась забродой для ловли рыбы у берегов Мэйна. Парусное судно пришлось перевернуть, чтобы восстановить дно\nВыйдя в море, парусник столкнулся с другим кораблем, отправив его на дно. Следующие пять лет бригантина прозябала в неизвестности, курсируя между британскими островами и Вест-Индией по Средиземному морю\nЗатем парусное судно 'Амазонка' село на мель вблизи острова Гейт Уотсон, Северная Шотландия, где после небольшого ремонта было продано с аукциона как непригодное для плавания. Всех кто приближался к бригантине, сопровождали одни только беды и несчастья.";
		link.l1 = "Ну и что, тут такого, неумелые капитаны, им бы баркасами сперва научиться управлять.";
		link.l1.go = "second_218";
		break;

		case "second_218":
		dialog.text = "Не в этом суть. Бригантина 'Амазонка' переходила из рук в руки, пока в 1872 году ее подвергли тщательному ремонту. Судну добавили вторую палубу и увеличили грузоподъемность до 84 тонн. Фактически бригантина превратилась в новый корабль. Теперь под американским флагом и новым именем бригантину 'Амазонка' переименовали в 'Мэри Селеста' где и собиралась попасть в морскую историю и стать печально известной благодаря своей таинственной судьбе.";
		link.l1 = "Как интересно и что за судьба у неё такая.";
		link.l1.go = "second_219";
		break;

		case "second_219":
		dialog.text = "Первое путешествие практически построенной заново 'Мэри Селеста' началось 7 ноября 1872 года. Ее новым хозяином стал капитан Бенджамин Брикс, 38-летний морской волк потомственный моряк из штата Массачусетс\nОн был родом из крепкой религиозной семьи, строгий, но уважаемый капитан. Его жена Сара и двухлетняя малютка Софи сопровождали его в этом плавании. Миссис Брикс снабдила крошечную капитанскую каюту всем необходимым и даже швейной машинкой и маленьким мелодионом, чтобы не скучать в пути\nКоманда состояла из семи американских и немецких моряков, которые имели огромный опыт и мастерство. Судно перевозило 1700 бутылок с алкогольными напитками в порт Генуи, Италия. Как и все прекрасные капитаны Бенджамин Брикс вел судовой журнал, но записи были краткими и не информативными\nЗатем что-то произошло утром 25 ноября 1872 года, когда была сделана последняя запись в журнале. Девять дней спустя бригантина 'Мэри Селеста' была найдена дрейфующей в 378 милях к востоку от острова Санта-Мария без единой души на борту...";
		link.l1 = "...";
		link.l1.go = "second_220";
		break;

		case "second_220":
		dialog.text = "Бригантина 'Мэри Селеста' была заброшена. Все указывало на то, что команда покидала судно в спешке. Подзорная труба, секстан, навигационные таблицы исчезли, но плащи и курительные трубки, принадлежащие морякам, были аккуратно сложены внизу\nПосуда была вымыта, все койки застелены, кроме капитанской. Две крышки, ведущие в трюм, были открыты, в том числе и капитанский иллюминатор. Груз, состоящий из бочек, был на месте и даже в хорошем состоянии\nНичто не указывало на применение силы.
Бенджамин Брикс был превосходным моряком, но что же вынудило его покинуть собственное парусное судно, рискуя жизнью жены, ребенка и команды и пересесть в маленькую шлюпку среди бушующих волн....";
		link.l1 = "Действительно странно.";
		link.l1.go = "second_221";
		break;

		case "second_221":
		dialog.text = "Судно было найденым неким Отто Девуа...Когда он и его люди гребли обратно к своему парусному судну 'Тина дель Грация'. Учитывая состояние бригантины 'Мэри Селеста' было принято решение отогнать ее в пролив Гибралтар. Когда призрачный корабль был доставлен в назначенное место, капитан предъявил права на вознаграждение за спасенное имущество.";
		link.l1 = "Молодец, правильно сделали, представляю, что творилось в голове этого капитана.";
		link.l1.go = "second_222";
		break;

		case "second_222":
		dialog.text = "Судом были назначены слушания. Необычные обстоятельства этого дела вызвали интерес у местного прокурора. Он был убежден, что причиной исчезновения команды было преступление\nОн следовал версии о том, что команда завладела спиртным и в состоянии алкогольного опьянения убила капитана и его семью\nВ конце концов, суд отверг это обвинение и снял подозрения с капитана и его экипажа. Несмотря на это ему выплатили всего 1700 дублонов, что оказалось меньше половины положенного вознаграждения за такую находку. По поводу пропавшей команды суд, не вынес никакого решения.";
		link.l1 = "Ну и дела, творятся в будущем.";
		link.l1.go = "second_223";
		break;

		case "second_223":
		dialog.text = "Последующие двенадцать лет парусное судно 'Мэри Селеста' поменяло нескольких хозяев, но большую часть времени бригантина стояла забытой и потихоньку приходила в негодность\n
В конце концов, судно превратилось в плавучую развалину, и встретило свою гибель самым постыдным образом. В конце 1884 года американский консорциум приобрел бригантину 'Мэри Селеста' по невероятно низкой цене, и подготовил его для отправки из Бостона с грузом пива, масла, ботинками и другими различными товарами в один из портов Гаити\nЭто и было последним путешествием парусника. Наполнив трюм товаром бригантину 'Мэри Селеста' руководители американского консорциума застраховали на сумму в 25000 дублонов пятью разными страховыми организациями\n
Когда парусный корабль достиг острова Гаити, стояла ясная погода. На море был мертвый штиль. Капитан приказал посадить бригантину 'Мэри Селеста' на мель на рифе. Как только судно село на мель капитан Паркер приказал команде рубить мачты. Затем Паркер избавился от всего, что можно было продать. Совершенно очевидно, что это была страховая афера\n
Гибель парусного судна 'Мэри Селеста' было заранее продуманным планом капитана Паркера. Судовой следователь вскоре обнаружил, что декларация груза была фальшивкой. Пивные бутылки были наполнены водой, в ящиках с серебром находились дешевые собачьи ошейники\nСразу был отдан приказ и Паркера арестовали. Капитан и грузоотправители были обвинены в тайном сговоре, а Паркер в умышленном причинении вреда судну - в преступлении, за которое в  приговаривали к смертной казни. Но судебное разбирательство принесло мало удовлетворения и еще меньше справедливости\nВскоре грузоотправители признали свою вину и возместили долги, а суд присяжных снял обвинения с капитана и он был освобожден. Но через несколько месяцев капитан и старший помощник скоропостижно умерли, а фрахтовщики обанкротились, как будто проклятие корабля-призрака 'Мэри Селеста' продолжалось уже после того, как ее деревянные мощи гнили у берегов Гаити.";
		link.l1 = "Ну, и, к чему этот рассказ Магистр.";
		link.l1.go = "second_224";
		break;

		case "second_224":
		dialog.text = "Оракул, так же придвидел, что команда и капитан со своей семьёй, попали во временную ловушку и оказались в нашем времени в карибском бассейне, вот собственно и весь рассказ, что думаешь по этому поводу.";
		link.l1 = "Ну если верить Оракулу, то можно попробовать найти этих людей и спросить, что на самом деле произошло.";
		link.l1.go = "second_225";
		break;

		case "second_225":
		dialog.text = "Правильно думаешь, искать следует в свободных поселениях куда инквизиция захаживать побаиваются, если бы они были в городах несомненно ими заинтересовались, но такой информации нет\nЕсли тебе удастся найти одного из членов экипажа, имя капитана нам известно, капитан Бенджамин Брикс, имя его жены Сара Брикс, приведи их ко мне, я попробую поговорить с ними через гипнотический сеанс и более выяснить, что там у них произошло на борту.";
		link.l1 = "Хорошо, но не обещаю, если повезёт, тогда и доставлю их к вам Магистр.";
		link.l1.go = "second_226";
		break;

		case "second_226":
		dialog.text = "Удачи. Хранитель.";
		link.l1 = "Спасибо.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste");
		NextDiag.TempNode = "second_227";
		break;

		case "second_227":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_227";
		break;

		case "second_228":
	                     PlaySound("VOICE\Russian\QuestMan01.wav");
		dialog.text = "Приветствую тебя Хранитель, я не уверен, но пологаю, что эта девушка по имени Софи.";
		link.l1 = "Всё правильно Магистр, она самая, дочь капитана Бенджамина Брикс.";
		link.l1.go = "Exit";
	                     AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_6");
		NextDiag.TempNode = "second_229";
		break;
		
		
			
		case "second_229":
		dialog.text = "Да прибудут с тобой силы, Хранитель.";
		link.l1 = "...";
		link.l1.go = "Exit";
		NextDiag.TempNode = "second_229";
		break;





























































//********************* аббат Бенуа*****************************

                        case "First time4":
                        dialog.text = "Сейчас я занят, о делах поговорим позже, " + GetSexPhrase("сын","дочь") + " мо" + GetSexPhrase("й","я") + ".";
                        link.l1 = "...";
                        link.l1.go = "Exit";
                        NextDiag.TempNode = "First time4";
                        break;

	case "APS_Benua":
	dialog.text = "А это что за птица здесь шастает?";
	link.l1 = "О, Ваше преосвященство. Никогда б не подумал, что вы можете так изыскано выражаться!";
	link.l1.go = "APS_Benua_1";
	break;
				
	case "APS_Benua_1":
	dialog.text = "Взять эт" + GetSexPhrase("ого","у") + " соглядат" + GetSexPhrase("ая","ую") + ". Помогите обрести покой это" + GetSexPhrase("му","й") + " нечестивц" + GetSexPhrase("у","е") + "!";
	link.l1 = "...";
	link.l1.go = "Exit";
	NextDiag.TempNode = "First time4";
	break;


//********************* Норман Эддисон*****************************

	case "ApostatesNI":
	dialog.text = "...";
	link.l1 = "Так вот кто собирает сведения о Рэндольфe Кэннелле... Сейчас ты отправишься со мной, с тобой хотят поговорить серьезные люди.";
	link.l1.go = "ApostatesNI_1";
	break;
		
                     case "ApostatesNI_1":
	dialog.text = "Скорее ты у меня отправишься к праотцам! Я узнал тебя! Это ты шпионил" + GetSexPhrase("","а") + " за нами с Епископом в Сан-Хуане.";
	link.l1 = "...";
	link.l1.go = "Exit";
	NextDiag.TempNode = "ApostatesNI_2";
	break;
		
	case "ApostatesNI_2":
	dialog.text = "Все, я сдаюсь, твоя взяла, чего ты хочешь?";
	link.l1 = "Мне лично от тебя ничего не надо, а вот люди, под которых ты здесь копаешь, очень желают с тобой поговорить.";
	link.l1.go = "Exit";
	break;
		
	case "ApostatesNI_3":
	dialog.text = "Не думал, что ты так" + GetSexPhrase("ой","ая") + " настырн" + GetSexPhrase("ый","ая") + ", капитан.";
	link.l1 = "Да и я не думал" + GetSexPhrase("","а") + " тебя встретить в добром здравии, наемник.";
	link.l1.go = "ApostatesNI_4";
	break;
		
	case "ApostatesNI_4":
	dialog.text = "Пришло время закончить наше общение, надеюсь, ты помолил" + GetSexPhrase("ся","ась") + " перед смертью?";
	link.l1 = "За меня не переживай, лучше за свою шкуру побеспокойся, думаю с этого острова тебе уже не уйти.";
	link.l1.go = "ApostatesNI_5";
	break;
		
	case "ApostatesNI_5":
	dialog.text = "Да, один из нас точно уже отсюда не уйдет.";
	link.l1 = "...";
	link.l1.go = "Exit";
	break;

//********************* Член ордена масонов*****************************

	case "Mason":
	dialog.text = "О, капитан, мы, кажется, прибыли вовремя!";
	link.l1 = "Да, брат, как никогда вовремя! Был" + GetSexPhrase("","а") + " бы я чуть послабее, меня бы здесь уже успели проткнуть не один раз. Пока вас дождешься...";
	link.l1.go = "Mason_1";
	break;
		
	case "Mason_1":
	dialog.text = "Извини, капитан, но мы прибыли, сразу, как только к нам поступила информация.";
	link.l1 = "Ладно. Что делать с этим фруктом будем?";
	link.l1.go = "Mason_2";
	break;
		
	case "Mason_2":
	dialog.text = "Капитан, по указанию Магистра, мы его забираем к себе, тебе же надо срочно прибыть к Магистру.";
	link.l1 = "Хорошо, навещу его как можно скорее.";
	link.l1.go = "Exit";
	AddDialogExitQuest("GothicApostates_APS_dialog7");
	break;







//*********************Банкир*****************************

		case "usurerSavLaMar":
		dialog.text = "...";
		link.l1 = "Я тебя предупреждал, с этими ребятами шутки плохи!";
		link.l1.go = "usurerSavLaMar_1";
		break;

		case "usurerSavLaMar_1":
		dialog.text = "Не могу поверить, что бы священники были садистами, значит я правильно выбрал сторону и ни о чём не сожалею.";
		link.l1 = "Давай выбираться от сюда скоро здесь всё сгорит до тла, можешь идти?";
		link.l1.go = "Exit";
		AddDialogExitQuest("GothicApostatesAPS_BankSavLaMar");
		break;


//********************* квест Чарли Вейн*****************************

//********************* Грэг Сноу*****************************

		case "GregSnow":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_7.wav");
		dialog.text = "Ахой, капитан! Не хотите ли угостить грогом старого пьяницу?";
		link.l1 = "Пожалуй... Трактирщик! Две кружки грога, да погорячее!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneTalkWithSnow");
		break;
		
		case "GregSnow_1":
		dialog.text = "Эх, капитан, перед тем как бросить якорь в этом городишке, я всякого насмотрелся на белом свете... Выпейте грогу, он развеет ваши мрачные мысли - я вижу, что вы чем-то сильно озабочены.";
		link.l1 = "Озабочен" + GetSexPhrase("","а") + ". Да, пожалуй, можно и так сказать. Ненавижу иметь дело со всякого рода чертовщиной.";
		link.l1.go = "GregSnow_2";
		break;
		
		case "GregSnow_2":
		dialog.text = "Эге... Похоже, вы говорите о Чарли Вейне. Весь город только и говорит об этом!";
		link.l1 = "Скажи, приятель - не доводилось ли тебе знаться с кем-нибудь из тех, кто знал Чарли при жизни?";
		link.l1.go = "GregSnow_3";
		break;
		
		case "GregSnow_3":
		dialog.text = "Пожалуй, нам стоит еще выпить.";
		link.l1 = "Трактирщик, еще две кружки грога!";
		link.l1.go = "GregSnow_4";
		break;
		
		case "GregSnow_4":
		LAi_Fade("", "");
		dialog.text = "Мне есть что вспомнить, капитан. Но воспоминания эти могут привести меня прямо на виселицу...";
		link.l1 = "Даю вам слово, что этот разговор останется между нами!";
		link.l1.go = "GregSnow_5";
		break;
		
		case "GregSnow_5":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_11.wav");
		dialog.text = "Почему-то я верю тебе, капитан. Так и быть, я расскажу тебе кое-что. Один мой знакомый, Роберт Блэйк, знавал Вейна еще до того, как он станцевал джигу с Джеком Кетчем. Пожалуй, это все, что я могу тебе рассказать.";
		link.l1 = "Но как мне найти его?";
		link.l1.go = "GregSnow_6";
		break;
		
		case "GregSnow_6":
		dialog.text = "Ха-ха. Не бойся, он еще не в гостях у Дэви Джонса! Я слышал, что он ходит на шхуне 'Лебедь', захочет ли он раскрывать рот...";
		link.l1 = "Спасибо, дружище. Я попробую его разговорить.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneTalkWithSnowEnd");
		break;

//*********************Гаррис О'Мэйли*****************************
		
		case "GarrisOMayli":
		dialog.text = "Приветствую вас. Что могло заставить вас навестить такого одинокого человека, как я?";
		link.l1 = "Даже не знаю с чего начать... Я приш" + GetSexPhrase("ел","ла") + " поговорить с вами о Чарли Вейне... Вы знаете, что он был казнен, но недавно его тело, точнее - то, что от него осталось, непостижимым образом исчезло прямо с виселицы. Затем последовало убийство священника и нескольких усердных прихожан местной церкви. По словам одного очевидца, который, к сожалению, покончил с собой, эти злодеяния совершил живой скелет.";
		link.l1.go = "GarrisOMayli_1";	
		break;
		
		case "GarrisOMayli_1":
		dialog.text = "О, Боже мой, я знал, что этим может кончиться!";
		link.l1 = "Вы что-то знаете! Прошу вас, расскажите мне всё. Речь идет о жизнях людей!";
		link.l1.go = "GarrisOMayli_2";
		break;
		
		case "GarrisOMayli_2":
		dialog.text = "Да, я расскажу вам всё, что мне известно. Вы ведь наверняка знаете, Гаррис О'Мейли - мое мирское имя, но когда-то я носил сан - в те времена Чарли не раз приходил ко мне.";
		link.l1 = "Говорите же, ради всего Святого!";
		link.l1.go = "GarrisOMayli_3";
		break;
		
		case "GarrisOMayli_3":
		dialog.text = "Эта история до сих пор мучает меня. Вы знаете, когда человек превышает все мыслимые пределы зла при своем земном существовании, демоны стараются прибрать к рукам его душу. Видимо, так произошло и с Чарли Вейном. Я не склонен верить в реинкарнацию, но то, что я услышал от Чарли\nИ то, что вы мне сейчас рассказали. Чарли жаловался мне, что его стали преследовать разного рода видения - он постоянно слышал голос, призывающий слушаться его во всем. Он никак не мог от этого избавиться - не раз он обращался ко мне за помощью, но я так и не смог ему помочь.";
		link.l1 = "Что еще он рассказывал вам?";
		link.l1.go = "GarrisOMayli_4";
		break;
		
		case "GarrisOMayli_4":
		dialog.text = "Чарли говорил мне, что голос со временем становится все сильнее и сильнее, а видения все более явственными. Ему практически постоянно, даже во сне, приходилось разговаривать с 'ним'...";
		link.l1 = "О ком вы говорите?";
		link.l1.go = "GarrisOMayli_5";
		break;
		
		case "GarrisOMayli_5":
		dialog.text = "Я не хочу произносить его имени. Это злой дух - исчадие ада. Один раз Чарли показал мне свежую рану на своем теле, уверяя, что получил ее во сне - пытаясь спорить с 'ним'. Это какое-то сумасшествие! Вейн говорил мне о какой-то древней каменной табличке которую нашли в одной из деревень архипелага, после чего и стали приходить видения которые с каждым днём только и усиливались. Он отдал мне этот артефакт...";
		link.l1 = "Дальше, что же было дальше?";
		link.l1.go = "GarrisOMayli_6";
		break;
		
		case "GarrisOMayli_6":
		dialog.text = "Дальше... Дальше Чарли совершил обряд, на котором настаивал его навязчивый собеседник. Он наполнил своей кровью чашу, на которую указал ему 'он' и прочитал продиктованное на ухо заклинание. Демон говорил Чарли, что через год после его смерти, он сам вселится в его тело на какое-то время, чтобы совершить во плоти какие-то дела, а потом он обещал Чарли воскрешение. Я говорил Вейну, что это всего лишь уловки дьявола, но он уже не мог сопротивляться.";
		link.l1 = "Рассказывайте же дальше, прошу вас!";
		link.l1.go = "GarrisOMayli_7";
		break;
		
		case "GarrisOMayli_7":
		dialog.text = "Далее с капитаном Вейном произошли заметные изменения - он стал неузнаваем. Его глаза - я до сих пор не могу забыть этот взгляд - это был взгляд из преисподней. В церковь он больше не заходил, а однажды подкараулил меня возле моего дома и попросил вернуть ему артефакт - но меня словно что-то остановило\nЯ отважился ответить ему отказом. Лицо капитана Вейна исказила нечеловеческая гримаса - он выхватил оружие. Мне оставалось лишь просить Господа о помощи. Потом Вейн резко развернулся и молча ушел. Больше я его не видел. Каменную табличку я до сих пор храню у себя.";
		link.l1 = "Теперь я понимаю, с чем мне предстоит столкнуться. Вейн никогда не рассказывал вам о том, где он совершил навязанный ему обряд?";
		link.l1.go = "GarrisOMayli_8";
		break;
		
		case "GarrisOMayli_8":
		dialog.text = "Нет, об этом мне ничего не известно.";
		link.l1 = "В любом случае, я прошу вас отдать мне его артефакт. Я склон" + GetSexPhrase("ен","на") + " полагать, что только с его помощью мне удастся остановить капитана Чарли Вейна, точнее...";
		link.l1.go = "GarrisOMayli_9";
		break;
		
		case "GarrisOMayli_9":
		GiveItem2Character(pchar, "architects_table_7");
		Log_Info("Вы получили каменную табличку");
		PlaySound("interface\important_item.wav");
		dialog.text = "Я понимаю, о ком вы хотите сказать. Держите - да пребудет с вами Господь!";
		link.l1 = "Прощайте.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("CharlieVayneFindRobertBlake");
		break;

//*********************Роберт Блэйк*****************************

		case "RobertBlake":
	                     PlaySound("VOICE\Russian\pirat_common_3.wav");
		dialog.text = "Аргх! Какого черта вы атаковали мой корабль?";
		link.l1 = "Заткнись. Я с тобой просто хотел поговорить, но ты начал первый палить по моему кораблю.";
		link.l1.go = "RobertBlake_1";			
		break;
		
		case "RobertBlake_1":
		dialog.text = "Вот чёрт, это я с перепугу, теперь чего ты хочешь, что бы я перед тобой встал на колени...";
		link.l1 = "Успокойся...Мне нужно узнать кое, что и всё, ты ведь ходил несколько лет под командованием Чарли Вейна не так ли?";
		link.l1.go = "RobertBlake_2";			
		break;
		
		case "RobertBlake_2":
		dialog.text = "Чарли Вейн... Было дело. Но какой прок вспоминать покойников? Бедняга, ему ведь даже не достался сундук мертвеца - его вздернули живьем! Милосердное английское правосудие.";
		link.l1 = "Я знаю о его судьбе. Скажи мне, было ли у Чарли какое-то свое любимое место, которое он часто навещал, не знаю как по точнее сказать.";
		link.l1.go = "RobertBlake_3";			
		break;

		case "RobertBlake_3":
		dialog.text = "Эй, " + GetSexPhrase("парень","девчушка") + "! Ты что, собрал" + GetSexPhrase("ся","ась") + " заняться кладоискательством?! Боюсь, что ты идешь не по той дорожке. Про любимое местечко Вейна знали многие из его команды, в том числе и я - вряд ли ты найдешь там что-нибудь, кроме скелетов и ржавых лопат.";
		link.l1 = "Любимое местечко, ты говоришь?";
		link.l1.go = "RobertBlake_4";			
		break;

		case "RobertBlake_4":
		dialog.text = "Да, было у него одно местечко - не знаю, чем оно так ему приглянулось - его словно тянуло туда. По мне, так лучше прогуляться по доске, чем посетить это место.";
		link.l1 = "Мне нужно знать, что это за место.";
		link.l1.go = "RobertBlake_5";			
		break;

		case "RobertBlake_5":
		dialog.text = "Это место залив Крейт находится около Синт-Маартена там ещё есть старая заброшенная деревня, не плохое укрытие было для пиратов какое-то время, вот там Вейн и покуралесил от души, нравилось ему это место, в итоге его банда много крови пролили местных жителей, после чего и поехала крыша у Вейна. Удачи, тебе капитан!";
		link.l1 = "Прощай и не попадайся мне больше в море, в следующий раз такой дерзости и наглости не прощу.";
		link.l1.go = "RobertBlake_6";			
		break;
		
	case "RobertBlake_6":
	DialogExit();
	sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
	Lai_SetPlayerType(pchar);
	LAi_RemoveCheckMinHP(sld);
	pchar.GenQuest.QuestAboardCaptanSurrender = true;
	LAi_SetImmortal(sld, true);
	sld.ShipEnemyDisable  = true;
	pchar.quest.APSHRobertBlake_AfterBattle.over = "yes";
	pchar.quest.APSHRobertBlakeOnMapOver.over = "yes";
	AddQuestRecord("APSH", "5");
	DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
	AddComplexSeaExpToScill(50, 50, 50, 100, 50, 50, 0);
	AddComplexSelfExpToScill(30, 30, 30, 30);
	pchar.quest.GothicApostatesAPS_6.win_condition.l1 = "location";
	pchar.quest.GothicApostatesAPS_6.win_condition.l1.location = "church IM2";
                     pchar.quest.GothicApostatesAPS_6.win_condition.l1.locator_group = "reload";
	pchar.quest.GothicApostatesAPS_6.win_condition.l1.locator = "reload1_back";
	pchar.quest.GothicApostatesAPS_6.win_condition = "APSH_Ruins";		
                     break;

//*********************Чарли Вейн*****************************

		case "SharliVein":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_1.wav");
		dialog.text = "Тебе всё-таки удалось найти меня я долго ждал твоего прихода.";
		link.l1 = "...";
		link.l1.go = "SharliVein_1";			
		break;

		case "SharliVein_1":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_2.wav");
		dialog.text = "...";
		link.l1 = "Да ладно, не ври, что ты всё это планировал.";
		link.l1.go = "SharliVein_2";			
		break;

		case "SharliVein_2":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_3.wav");
		dialog.text = "Ах, ха, ха, что ты знаешь о моих намерениях.";
		link.l1 = "...";
		link.l1.go = "SharliVein_3";			
		break;

		case "SharliVein_3":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_4.wav");
		dialog.text = "Разве я не оставлял знаки о моём присутствии, столь явными, что ты не мог заметить их.";
		link.l1 = "...";
		link.l1.go = "SharliVein_4";			
		break;

		case "SharliVein_4":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_5.wav");
		dialog.text = "Как бы ты не изворачивался, ты не можешь поспорить со всем этим.";
		link.l1 = "...";
		link.l1.go = "SharliVein_5";			
		break;

		case "SharliVein_5":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_ATTACK_1.wav");
		dialog.text = "...";
		link.l1 = "Хватит болтать, я загоню тебя обратно под камень из которого ты вылез - монстр.";
		link.l1.go = "SharliVein_6";			
		break;

		case "SharliVein_6":
	                     PlaySound("VOICE\Russian\SharliVein\HELLO_ATTACK_2.wav");
		dialog.text = "Твои кости помогут мне выпустить ветра смерти в этот мир.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("APSH_SharliVein_ATTACK");		
		break;


//************Одержимые  Билл Метью****************************************

		case "BillMatthew":
                                    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOODMONSTERKILL.wav");
		dialog.text = "Спасибо, что помогли мне, без вас они бы убили меня и забрали монету.";
		link.l1 = "Зачем скелетам деньги?";
		link.l1.go = "BillMatthew_1";		
		break;
		
		case "BillMatthew_1":
		dialog.text = "Это не простая монета. Пожалуй, мне стоит рассказать вам историю. Я был штурманом в команде Делвина Блейза на пиратском бриге 'Удачливый Джокер'.\nПосле удачного рейда на испанский галеон забитый всякими индейскими украшениями, золотом и серебром. Удачный налёт скажу я вам, тогда при дележе средств всей команде хватило бы на безбедную жизнь. Помимо драгоценностей, мы нашли шкатулку, в которой лежали пузырек с какой-то жидкостью и три старинные золотые монеты.\nРаньше никто из нас таких монет не видел. Мы поделили монеты, одна из этих монет досталась мне, а шкатулка с жидкостью капитану.";
		link.l1 = "Хм, и что же было дальше?";
		link.l1.go = "BillMatthew_2";		
		break;

		case "BillMatthew_2":
		dialog.text = "Через какое-то время капитану Блейзу удалось найти человека, который смог прочитать надпись на крышке той самой шкатулки.\nОказалось, что обладатель содержимого мог связаться со злыми индейскими духами, прочитав заклинание, написанное на крышке и смешав свою кровь с жидкостью из пузырька.\nНаш капитан так и сделал, в результате чего в него вселился злой дух! Более того, Блейз получил необъяснимую власть над своей командой, а часть своих матросов с помощью этой колдовской жидкости превратил в живых скелетов!\nСтранным образом на меня не подействовали его чары - теперь я понимаю - эта старинная монета спасла меня! Через какое-то время мне удалось сбежать, я сменил род деятельности, по ходатайству тестя меня взяли штурманом на торговое судно.\nБеда вот в чём - чем больше людей Блейз и его команда убивают, тем сильнее он становится.";
		link.l1 = "И?..";
		link.l1.go = "BillMatthew_3";		
		break;

		case "BillMatthew_3":
		dialog.text = "Для каких-то целей ему необходимы все три монеты. Одна из монет досталась первому помощнику Блейза при дележе. На следующий день мы не досчитались одного из команды, им оказался первый помощник.";
		link.l1 = "В тот день вы были у берегов Доминики!";
		link.l1.go = "BillMatthew_4";		
		break;

		case "BillMatthew_4":
		dialog.text = "Да, как вы догадались?";
		link.l1 = "Его спасли аборигены, ловцы жемчуга. Продолжай...";
		link.l1.go = "BillMatthew_5";		
		break;

		case "BillMatthew_5":
		dialog.text = "Не может быть, вот чёрт, гореть в аду этому Блейзу, на его шее красовалась монета, и он всех убедил, что Абрам первый помощник отдал ему её добровольно? Значит всё верно, он у него забрал с силой и сбросил в море. Чутьё нас не подвело, я и квартирмейстер решили покинуть корабль.";
		link.l1 = "Как я понимаю обладателем второй монеты был квартирмейстер.";
		link.l1.go = "BillMatthew_6";		
		break;

		case "BillMatthew_6":
		dialog.text = "Всё верно, Юмбер Кёруа, он живет в Чарлстауне и ему похоже как и мне грозит опасность.";
		link.l1 = "Я могу ещё чем - нибудь помочь вам!";
		link.l1.go = "BillMatthew_7";		
		break;

		case "BillMatthew_7":
		dialog.text = "Да, если быть до конца откровенным, эта монета жжет мне карман, ведь они все равно рано или поздно до меня доберутся!";
		link.l1 = "Почему вы в это так уверены?";
		link.l1.go = "BillMatthew_8";		
		break;

		case "BillMatthew_8":
		TakeNItems(pchar, "Obsession_Coin", 1);
		Log_Info("Вы получили старинную монету");
		PlaySound("interface\important_item.wav");
		dialog.text = "Ну как же! Ведь капитану Блейзу необходимы все три золотые монеты Инков! Знаете что, капитан, возможно, вам удастся победить в этой войне с духами! Меня же точно убьют и тогда все люди узнают, что такое настоящее зло.";
		link.l1 = "Ну что ж, давай сюда эту монетку, я постараюсь разобраться,что к чему.";
		link.l1.go = "exit";	
		AddDialogExitQuestFunction("GothicObsessionTakeCoin");
		break;

//************Одержимые  Делвин Блейз (незнакомец)****************************************

		case "ObsessionDevlin":
	                     PlaySound("VOICE\Russian\Chaos.wav");
		dialog.text = "Жизнь полна неожиданностей и они далеко не всегда бывают приятными. Капитан, вы знали этого человека!";
		link.l1 = "Почему ты спрашиваешь, кто ты?";
		link.l1.go = "ObsessionDevlin_1";		
		break;

		case "ObsessionDevlin_1":
		dialog.text = "Это не важно кто я, важно то, кто у тебя за спиной.";
		link.l1 = "Где...";
		link.l1.go = "exit";
	                     LAi_SetActorType(pchar);
		AddDialogExitQuest("GothicObsession_cemeteryman_4");	
		break;

		case "ObsessionDevlin_2":
 	                    PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_00.wav");
		dialog.text = "Мы знали, что ты придёшь!";
		link.l1 = "...";
		link.l1.go = "ObsessionDevlin_3";		
		break;

		case "ObsessionDevlin_3":
 	                    PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_01.wav");
		dialog.text = "Мой хозяин одержит победу и склонит весь мир к своим ногам.";
		link.l1 = "...";
		link.l1.go = "ObsessionDevlin_4";		
		break;

		case "ObsessionDevlin_4":
		npchar.model = "BSUnd";
		Characters_RefreshModel(npchar);
	                     npchar.name = "Фиамотар";
	                     npchar.lastname = "";
 	                     PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_02.wav");
		dialog.text = "Ты наивный идиот, ты понятия не имеешь на, что ты замахнулся и я накажу тебя за это здесь и сейчас!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsessionDevlin2");		
		break;

		case "Fiamatar_abordage":		// Делвин
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_15_00.wav");
                                          dialog.text = "...";
	                     link.l1 = "Кто ты.";
		link.l1.go = "Fiamatar_abordage_2";
		break;

		case "Fiamatar_abordage_2":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_01.wav");
                                        dialog.text = "Ты ещё не устал задавать этот вопрос, поищи внутри себя - глупец, ты поймёшь кто я.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_3";
		break;

		case "Fiamatar_abordage_3":
                                         dialog.text = "Делвин Блейз в прошлом, моё имя Фиамотар, дарованный драконом. Кровь дракона течет в моих венах и сила дракона в моих жилах.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_4";
		break;

		case "Fiamatar_abordage_4":
 	                    PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_03.wav");
                                          dialog.text = "Моим создателем мне дана божественная сила, так же как ты владеешь силой данным тебе твоим Богом.";
	                     link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_5";
		break;

		case "Fiamatar_abordage_5":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_04.wav");
                                          dialog.text = "Моя судьба - уничтожение этого мира.";
	                     link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_6";
		break;

		case "Fiamatar_abordage_6":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_06.wav");
                                         dialog.text = "Так же как твоя рука, несет смерть определённым созданиям охотник на драконов.";
	                     link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_7";
		break;

		case "Fiamatar_abordage_7":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_WER_20_08.wav");
                                         dialog.text = "Разве ты не ощущаешь связь которая соединяет нас - да ты знаешь кто я.";
	                     link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_8";
		break;

		case "Fiamatar_abordage_8":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_15_00.wav");
                                         dialog.text = "...";
		link.l1 = "Чьи приказы вы выполняете, кто послал вас сюда!";
		link.l1.go = "Fiamatar_abordage_9";
		break;

		case "Fiamatar_abordage_9":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_01.wav");
                                         dialog.text = "Наше будущее, настоящее контролируется хозяином при помощи слова силы, скоро никто не сможет сопротивляться ему.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_10";
		break;

		case "Fiamatar_abordage_10":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_02.wav");
                                          dialog.text = "Его длинная рука уже протянулась сюда из царства мертвых, духи ночи собираются в предвкушении его скорого появления.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_11";
		break;

		case "Fiamatar_abordage_11":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_03.wav");
                                         dialog.text = "Он раздавит вас - людей и будет править этим миром.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_12";
		break;

		case "Fiamatar_abordage_12":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_04.wav");
                                         dialog.text = "В его тени мы не более чем инструмент его созидательной силы.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_13";
		break;

		case "Fiamatar_abordage_13":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_05.wav");
                                         dialog.text = "Хозяин придёт и поднимет ваши безжизненные тела из пепла и использует их для окончательного изменения облика этого мира.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_14";
		break;

		case "Fiamatar_abordage_14":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_1_15_00.wav");
                                          dialog.text = "...";
		link.l1 = "Слуга зла, что заставило тебя появится здесь, ты пришел только за тем что бы сеять ужас и панику!";
		link.l1.go = "Fiamatar_abordage_15";
		break;

		case "Fiamatar_abordage_15":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_1_20_01.wav");
                                         dialog.text = "Наша высшая цель в этом мире - жалкий человечишка останется скрытой от тебя.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_16";
		break;

		case "Fiamatar_abordage_16":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_15_00.wav");
                                         dialog.text = "...";
		link.l1 = "Хватит болтать, я загоню тебя обратно под камень из под которого ты вылез - монстр.";
		link.l1.go = "Fiamatar_abordage_17";
		break;

		case "Fiamatar_abordage_17":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_20_01.wav");
                                         dialog.text = "Ха-ха, ты ещё не готов победить меня, какое - то мгновение отделяет меня от достижения моей цели.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_18";
		break;

		case "Fiamatar_abordage_18":
 	                     PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGON_UNDEAD_HELLO_ATTACK_20_02.wav");
                                         dialog.text = "Твои кости по мугут мне выпустить ветра смерти в этот мир.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_19";
		break;

		case "Fiamatar_abordage_19":
		LAi_SetCurHPMax(NPChar);
		LAi_GetCharacterMaxEnergy(NPChar);			
		QuestAboardCabinDialogExitWithBattle("FiamatarToBoom"); 
		DialogExit();	
		AddDialogExitQuest("MainHeroFightModeOn");
		pchar.GenQuest.Detonation = true; // patch-4
		break;

//************Одержимые  Смотритель кладбища****************************************

		case "CemeterymanTakeCoin":
		dialog.text = "Месье, наконец - то вы очнулись.";
		link.l1 = "Чёрт, где я, что произошло...";
		link.l1.go = "CemeterymanTakeCoin_1";
		break;

		case "CemeterymanTakeCoin_1":
		dialog.text = "Месье, всё в порядке вы у меня дома. Вас я нашёл без сознания, такое случается на кладбищах.";
		link.l1 = "Голова раскалывается. Чёрт пропала старая монета, ты её случайно не видел?";
		link.l1.go = "CemeterymanTakeCoin_2";
		break;

		case "CemeterymanTakeCoin_2":
		dialog.text = "Нет.";
		link.l1 = "Всё вспомнил, тот парень, незнакомец, точно это он её похитил!";
		link.l1.go = "CemeterymanTakeCoin_3";
		break;

		case "CemeterymanTakeCoin_3":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneyToCharacter(pchar, -1000);
		dialog.text = "Я не видел ни какого парня.";
		link.l1 = "Ладно, спасибо тебе за помощь, вот тут несколько монет.";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicObsession_cemeteryman_8");	
		break;


//************Бальсемио Монтехо****************************************

		case "Balsemio":
		dialog.text = "А, садись, душа-человек! Не купишь ли рома старому моряку?";
		link.l1 = "Конечно, старина, я и сам" + GetSexPhrase("","а") + " не против выпить! Трактирщик, рома!";
		link.l1.go = "exit";	
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_11");
		break;

		case "Balsemio_1":
	                     PlaySound("VOICE\Russian\Gr_Tavern_Mate_15.wav");
		dialog.text = "Благодарю тебя, капитан! Я всегда рад бесплатной выпивке - ведь в этой таверне проходит большая часть моей жизни, а с деньгами у меня туговато.";
		link.l1 = "Вся жизнь в этой таверне! Что с тобой случилось, дружище?";
		link.l1.go = "Balsemio_2";
		break;
		
		case "Balsemio_2":
		dialog.text = "А-а, не спрашивай, капитан! Это страшная история. Давай лучше выпьем!";
		link.l1 = "Трактирщик, ещё две кружки рома!";
		link.l1.go = "Balsemio_3";
		break;
		
		case "Balsemio_3":
		LAi_Fade("", "");
		dialog.text = "Ты славный " + GetSexPhrase("парень","девчёнка") + "! Когда-то и я был таким, но жизнь моя повернулась так, что сейчас я почти не сплю по ночам - меня преследуют страшные сны! Черт возьми... Только в роме я нахожу утешение...";
		link.l1 = "Поделись со мной своей бедою, моряк - может, полегчает на душе.";
		link.l1.go = "Balsemio_4";
		break;
		
		case "Balsemio_4":
		dialog.text = "Ну слушай, раз так сам" + GetSexPhrase("","а") + " решил. Когда-то я плавал на фрегате 'Сантиссима Мадре' у капитана Флоренсио Алегрия\nОднажды мы причалили к одной бухте на Мэйне. Капитан повел нас в пещеру - вот это была пещера, я тебе доложу - сундуки там ломились от всякого добра! Ну, мы нахапали сколько смогли и назад, на корабль\nХватились, а капитана нашего нет. Поискали его везде, нет и все тут. Мы подумали, что он погиб и решили плыть сами\nВышли в море, и вдруг такое началось! Страшный шторм, ветер ураганный - я такого в жизни не видел! Корабль наш в щепки разнесло, а из матросов спаслось только четверо - выбросило волнами на берег\nОдин из спасшихся рассказал, что перед бурей зашел в капитанскую каюту, поискать себе выпивку, и увидел на столе карту\nНу, он и прихватил ее с собой на всякий случай. Карту мы разделили на две части - решили собрать команду и снова вернуться сюда.";
		link.l1 = "Как же ты выбрался оттуда?";
		link.l1.go = "Balsemio_5";
		break;
		
		case "Balsemio_5":
		dialog.text = "Решили мы оставить все золото, что у нас было, положили все назад. Страх на нас напал - по ночам стала являться всякая нечисть индейской наружности, грозились, ужас нагоняли - страшное дело\nВ общем, вернули мы золото и стали делать ялик - слава богу, среди нас оказался плотник, да и инструмент кое-какой на берег по выбрасывало\nВот такая моя история, капитан... Вернулся я домой, а жить спокойно не могу. Вот и топлю свои страхи в роме.";
		link.l1 = "Вот так история! А карта та где?";
		link.l1.go = "Balsemio_6";
		break;
		
		case "Balsemio_6":
		TakeNItems(PChar, "map_part1", 1);
	                     dialog.text = "Да на, забирай!";
		link.l1 = "А где остальное?";
		link.l1.go = "Balsemio_7";
		break;
		
		case "Balsemio_7":
		dialog.text = "Ну где, у подельников моих, если они еще живы. Ступай. Капитан, растревожил" + GetSexPhrase("","а") + " ты меня, аж душу выворачивает.";
		link.l1 = "Ну, счастливо тебе, моряк!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_12");
		break;

//************Кристобаль Эскаланте****************************************

		case "Kristobal":
	                     PlaySound("VOICE\Russian\pirat_quest_2.wav");
		dialog.text = "Постойте, капитан, у меня к вам срочный разговор.";
		link.l1 = "Я тебя внимательно слушаю.";
		link.l1.go = "Kristobal_1";	
		break;
		
		case "Kristobal_1":
		dialog.text = "Разговор очень важный и лишние уши ни к чему. Я жду вас в местном подвале.";
		link.l1 = "В подвале, знакомо, что ж, как пожелаешь.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_15");
		break;
		
		case "Kristobal_2":
	                     PlaySound("VOICE\Russian\pirat_quest_3.wav");
		dialog.text = "Дело в том, что вы случайно стали обладателем предмета, который принадлежит мне по праву. Я прошу вас отдать его мне.";
		link.l1 = "О каком еще праве ты говоришь? Первую часть карты подарил мне Бальсемио Монтехо, и ты не имеешь к этому никакого отношения!";
		link.l1.go = "Kristobal_3";	
		break;
		
		case "Kristobal_3":
		dialog.text = "Дело в том, сеньор капитан, что я тоже, в отличии от вас, принимал участие в той экспедиции, вы же случайным образом прикоснулись к истории, о которой не имеете ни малейшего понятия.";
		link.l1 = "Бальсемио Монтехо поведал мне свою историю, и я собираюсь до конца разобраться в этом деле.";
		link.l1.go = "Kristobal_4";
		break;

		case "Kristobal_4":
		dialog.text = "Бальсемио Монтехо был пешкой в той игре и совершенно случайно остался в живых. Дело намного серьезнее, чем вы полагаете. Советую отдать мне все части карты и поскорее все забыть.";
		link.l1 = "Черта с два! Я не из тех людей, кто останавливается на пол пути! Расскажи-ка лучше, что тебе известно об этой истории!";
		link.l1.go = "Kristobal_5";
		break;

		case "Kristobal_5":
		dialog.text = "Я полагал - вы разумнее, чем оказалось на самом деле. Придется мне забрать этот кусок карты с вашего мертвого тела!";
		link.l1 = "Ты лишаешь меня шанса узнать то, что известно тебе одному, ведь трупы не умеют разговаривать! Защищайся!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_16");
		break;

		case "Kristobal_6":
	                     PlaySound("VOICE\Russian\EvilPirates07.wav");
		dialog.text = "Дьявол вас подери! Сеньор вы отлично владеете шпагой!";
		link.l1 = "Если дело настолько серьёзно, как ты говоришь, я предлагаю тебе объединить наши усилия. Итак, выкладывай все, что знаешь!";
		link.l1.go = "Kristobal_7";	
		break;

		case "Kristobal_7":
		dialog.text = "Пожалуй нет, я и сам справлюсь с этим делом!";
		link.l1 = "Тогда всего доброго, я и сам справлюсь с вашим делом!";
		link.l1.go = "Kristobal_8";	
		break;

		case "Kristobal_8":
		dialog.text = "Подожди, чёрт тебя дери. Хорошо, сеньор капитан, я принимаю ваши условия. Слушайте внимательно, сейчас вы узнаете много интересного.";
		link.l1 = "Я слушаю тебя!";
		link.l1.go = "Kristobal_9";
		break;

		case "Kristobal_9":
		dialog.text = "Мы с капитаном с фрегата 'Сантиссима Мадре' Флоренсио Алегрия заключили сделку. Сейчас вы все поймете. Флоренсио Алегрия заранее знал, что нельзя покинуть бухту, прихватив с собой сокровища, команда 'Сантиссима Мадре' была обречена на гибель\nК бухте вышли сразу два корабля. Фрегат Флоренсио Алегрия и мой бриг 'Анхэль де ля Гуарда'. Я незаметно поставил корабль на якорь с другой стороны бухты - таковы были условия\nКапитан Флоренсио Алегрия сказал, что без него никто не сможет вернуться в сельву за сокровищами, а взять их сейчас - означает верную гибель. \n Ему нужно было забрать оттуда какую-то вещь, а потом официально 'погибнуть' для своей команды. Мне же он обещал вернуться за золотом в следующий раз\nТогда, дескать, будет уже можно потрогать золотишко. Сплошные загадки, черт возьми! Когда мы сошли на берег в ближайшем порту, капитана и след простыл\nПри бегстве он прихватил с собой карту, по которой мой штурман плыл к бухте. Я попробовал погнаться за ним, но этот негодяй испортил мне компас, пришлось возвращаться назад. \n В последствии, когда я узнал, что несколько матросов 'Сантиссима Мадре' спаслись от гибели, я принялся их разыскивать, чтобы завладеть первым экземпляром карты, вот тут-то вы меня и опередили\nМне известна лишь судьба четвертого участника чудесного спасения - Диего Маркеса. Он сейчас занимается рыболовным промыслом на Эспаньоле. Возможно, он и является обладателем второй части карты.";
		link.l1 = "Да, ты много интересного мне рассказал. Что ж, одна часть карты у нас есть, ну а теперь на Эспаньолу за второй.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_17");
		NextDiag.TempNode = "Kristobal_10";
		break;

		case "Kristobal_10":
		dialog.text = "Капитан, нужно действовать.";
		link.l1 = "Я знаю.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Kristobal_10";
		break;

		case "Kristobal_11":
		dialog.text = "ЗО-ЛО-ТО... Капитан, ты справился со своей задачей, теперь я хочу тебя отблагодарить.";
		link.l1 = "О чём это ты?";
		link.l1.go = "Kristobal_12";	
		break;

		case "Kristobal_12":
		dialog.text = "Не ужеле ты думал, что я стану делить с тобой золотом. Наивный капитан и к тому же, глупый капитан.";
		link.l1 = "Ах вот ты о чём. Как говорил мой старый знакомый... Жадность фраера сгубила...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_29");	
		break;

//************Диего Маркес****************************************

		case "DiegoMarkes":
	                     PlaySound("VOICE\Russian\Fisher02.wav");
		dialog.text = "Чего надо, убирайся из моего дома.";
		link.l1 = "Ты, Диего Маркес!";
		link.l1.go = "DiegoMarkes_1";	
		break;

		case "DiegoMarkes_1":
		dialog.text = "Всегда им был, чего надо молокосос.";
		link.l1 = "Ээ...По аккуратнее с выражениями, мне необходимо поговорить с тобой.";
		link.l1.go = "DiegoMarkes_2";	
		break;

		case "DiegoMarkes_2":
		dialog.text = "Хорошо, о чём вы хотите поговорить.";
		link.l1 = "О карте которую вы разделили с Бальсемио Монтехо.";
		link.l1.go = "DiegoMarkes_3";	
		break;

		case "DiegoMarkes_3":
		dialog.text = "Бальсемио Монтехо... Он ещё жив!";
		link.l1 = "Да, живёт в городе Сан-Андреас, чувствует себя превосходно, каждый день у него праздник. За карту готов заплатить если она у тебя ещё имеется.";
		link.l1.go = "DiegoMarkes_4";	
		break;

		case "DiegoMarkes_4":
		TakeNItems(PChar, "map_part2", 1);
		dialog.text = "Хорошая новость. Я догадываюсь о том, что вы задумали, и искренне советую отказаться от этой затеи, часть той карты есть, забирай так, мне она не к чему.";
		link.l1 = "Прощай, Диего. Желаю тебе удачи.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_18");	
		NextDiag.TempNode = "DiegoMarkes_5";
		break;

		case "DiegoMarkes_5":
		dialog.text = "Приветствую, старого знакомого, как дела дружище.";
		link.l1 = "Спасибо, вот надумал навестить тебя.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "DiegoMarkes_5";
		break;

//************Галиндо Ольмос****************************************

		case "FlorensioCap":
	                     PlaySound("VOICE\Russian\pirat_common_1.wav");
		dialog.text = "Чего тебе надо, проваливай я не в настроении трепаться.";
		link.l1 = "Ты, капитан Флоренсио Алегрия!";
		link.l1.go = "FlorensioCap_1";	
		break;

		case "FlorensioCap_1":
		dialog.text = "Чего... Флоренсио Алегрия. Проваливай.";
		link.l1 = "...";
		link.l1.go = "Exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_SanAndres_20");	
		break;

//*********************Флоренсио Алегрия*****************************

		case "Florensio":
		dialog.text = "Ба, какая встреча, капитан Жофруа! Вот уж не думал, что мы вновь свидимся.";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Florensio");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Kristobal"));
		AddDialogExitQuest("GothicApostatesAPSdialog1");
		break;
		
		case "Florensio_1":
		dialog.text = "Ты обманул меня, грязная скотина!";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Kristobal");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
		AddDialogExitQuest("GothicApostatesAPSdialog3");
		break;
		
		case "Florensio_2":
		dialog.text = "Нет, это твоя жадность и алчность закрыли тебе глаза на правду. Впрочем, в любом случае - я использовал тебя, и теперь ты мне не нужен. Кстати, кто это с тобой? Твой новый компаньон?";
		link.l1 = "...";
		link.l1.go = "exit";
	                     sld = CharacterFromID("Kristobal");
	                     LAi_SetActorType(sld);
                                          LAi_ActorTurnToCharacter(sld, characterFromID("Florensio"));
		AddDialogExitQuest("GothicApostatesAPSdialog5");
		break;
		
		case "Florensio_3":
		dialog.text = "Сейчас кровь смоет улыбку с твоего лица. Защищайся, коварный ублюдок!";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSdialogEnd");
		break;

//************Венсенгуг****************************************

		case "iroquois":
		dialog.text = "Я вижу живого и невредимого белого человека. Как тебе удалось выйти из золотой пещеры, по моему вас было больше.";
		link.l1 = "Кто ты!";
		link.l1.go = "iroquois_1";	
		break;

		case "iroquois_1":
		dialog.text = "Моё имя Венсенгуг, я смотритель за золотой пещерой. Ещё никому не удавалось покинуть эту пещеру, но я вижу перед собой не алчного человека тяготеющему к золоту. Белые люди ради золота истребили почти весь наш древний народ\nДо появления бледнолицых на нашей земле люди правильно относились к золоту - ели на нем, пили воду из золотых кубков и делали красивые украшения для своих женщин, но когда пришли конкистадоры - жадные и беспощадные, и стали убивать людей из-за золотых побрякушек - индейские старейшины собрали большой совет. Было решено схоронить оставшееся золото, а верховный шаман наложил на него заклятие. Я - его прямой потомок.";
		link.l1 = "Понятно, но ты ошибся, я здесь для того, что бы забрать это золото и мне известно о вашем закляти которое наложили ваши шаманы, всё что мне нужно, это найти амулет Тлолака и снять заклятие, разве я не прав!";
		link.l1.go = "iroquois_2";	
		break;

		case "iroquois_2":
		dialog.text = "От куда ты узнал о заклятии. Об этом знают лишь просвящённые.";
		link.l1 = "Хе... У меня свои источники о которых я не намерен с тобой делиться.";
		link.l1.go = "iroquois_3";	
		break;

		case "iroquois_3":
		dialog.text = "Тогда ты должен знать, что амулет Тлолака был пожертвован древнему божеству и достать его не получится. Рад был знакомству белый человек и прощай.";
		link.l1 = "Подожди, что за божество этокое...";
		link.l1.go = "iroquois_4";	
		break;

		case "iroquois_4":
		dialog.text = "Глубинный монстр Бракхаур, ему поклоняются отшельники из народа Карибов, которые превратились в жутких канибалов ему они приносят в жертву людей - это их порождение. Амулет Тлолака был в единственном экземпляре у нашего шамана, но во время нападения Карибов на наше поселение, шамана захватили в плен и принесли в жертву Бракхауре.";
		link.l1 = "Тогда ты обязан мне сказать где обитают эти отшельники, если хочешь возмездия за своего шамана - я на многое способен...";
		link.l1.go = "iroquois_5";	
		break;

		case "iroquois_5":
		dialog.text = "Охотно верю, они скрываются на острове красивых вод Калуакаэра и до сих пор проводят свои ритуалы. Прощай белый воин.";
		link.l1 = "Прощай Венсенгуг...";
		link.l1.go = "exit";
		AddDialogExitQuest("GothicApostatesAPSBrachyura");
		break;

//************Софи Брикс****************************************

		case "SofiBrics":
		dialog.text = "...";
		link.l1 = "Тебя зовут Софи...";
		link.l1.go = "SofiBrics_1";	
		break;

		case "SofiBrics_1":
		dialog.text = "...";
		link.l1 = "Небойся, я капитан как и твой отец, моё имя "+GetFullName(Pchar)+", я хочу тебе помочь...";
		link.l1.go = "SofiBrics_2";	
		break;

		case "SofiBrics_2":
		dialog.text = "...";
		link.l1 = "Мне известно о корабле 'Амазонка' и твой отец был капитаном этого корабля, так же мне известно и о твоей маме и о тебе.";
		link.l1.go = "SofiBrics_3";	
		break;

		case "SofiBrics_3":
		dialog.text = "...";
		link.l1 = "Ещё мне известно, что вы не из этого времени...";
		link.l1.go = "SofiBrics_4";	
		break;

		case "SofiBrics_4":
	                     PlaySound("VOICE\Russian\Alvilda3.wav");
		dialog.text = "Да, всё правильно, но от куда, я и мои родители об этом никому не говорили, настоятель часовни так же не знает об этом.";
		link.l1 = "Скажем так, у меня есть очень таланливый друг, он провидец и целитель. Он, хочет помочь вам. И вот я нашёл вас, мне жаль, что не смог разыскать вас раньше...";
		link.l1.go = "SofiBrics_5";	
		break;

		case "SofiBrics_5":
		dialog.text = "Не стоит переживать, видно так всё и должно быть. Я согласна пойти с вами к вашему целителю, если настоятель отпустит.";
		link.l1 = "С ним мы уже всё обсудили, он не против...";
		link.l1.go = "SofiBrics_6";	
		break;

		case "SofiBrics_6":
		dialog.text = "Тогда, мне нужно собрать свои вещи, если вы не возражаете.";
		link.l1 = "Безусловно, я буду ждать вас в городе.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicApostatesAPS_MaryCeleste_3");	
		NextDiag.TempNode = "SofiBrics_7";
		break;

		case "SofiBrics_7":
	                     PlaySound("VOICE\Russian\Alvilda3.wav");
		dialog.text = "Я скоро буду готова, осталось немного собрать свои вещи и всё...";
		link.l1 = "Хорошо, жду.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "SofiBrics_7";
		break;


























		// главный клерк 
		case "W_headclerk":

			dialog.text = "Вы что-то хотели, " + GetSexPhrase("сударь","мадмуазель") + "?";
			if (!CheckCharacterItem(pchar, "PirTradeLicence") && CheckCharacterItem(pchar, "Mason"))
			{
				link.l1 = "Я хочу приобрести торговую лицензию вашей Компании.";
				link.l1.go = "licence";	
			}
			if (!CheckAttribute(npchar, "quest.trade") && CheckCharacterItem(pchar, "Mason"))
			{
				link.l2 = "Я слышал, что у вас можно приобрести корабельные приборы и прочие полезные вещи. Это так?";
				link.l2.go = "trade";	
			}
			else
			{
				link.l2 = "Что у вас сегодня имеется в продаже? Покажите, пожалуйста.";
				link.l2.go = "trade_1";	
			}

			link.l9 = "Нет, пока ничего.";
			link.l9.go = "exit";			
			NextDiag.TempNode = "W_headclerk";
		break;
		
		// торговые лицензии
		case "licence":
			if (!CheckAttribute(npchar, "quest.licence"))
			{
				dialog.text = "Ну что же, пожалуйста, приобретайте. Но я считаю должным вас предупредить, что наша Компания дорожит своим именем, поэтому к лицензиатам предъявляются определенные требования на весь срок действия лицензии, а именно - никаких агрессивных действий в отношении торговых кораблей любой нации\nВ случае выявления такого факта ваша лицензия будет немедленно аннулирована. Также вы лишитесь документа, если по каким-то причинам, неважно каким, вступите в конфликт с Голландией. Это понятно?";
				link.l1 = "Безусловно. Я приму это к сведению.";
				link.l1.go = "licence_0";
				npchar.quest.licence = true;
			}
			else
			{
				dialog.text = "Ну что же, пожалуйста, приобретайте. На какой срок вы хотите получить лицензию?";
				link.l1.edit = 6;
				link.l1 = "";	
				link.l1.go = "licence_1";
			}
		break;
		
		case "licence_0":
			dialog.text = "Лицензия дает право беспрепятственного входа в любой порт любой нации, поскольку подтверждает ваши мирные намерения и объясняет цель вашего прибытия - торговать. Однако если у вас есть проблемы с законом у той страны, в порт которой вы намерены явиться, лицензия вам не поможет. Более того - у вас ее просто изымут. Учтите это\nЕсли вы собираетесь торговать с враждебной вам державой - не забудьте перед входом в порт поднять дружественный флаг - это избавит вас от ненужных проблем, поскольку канониры фортов и патрули в городах имеют склонность сначала стрелять, и только потом разбираться\nДа, чуть не забыл: согласно устоявшейся традиции, оплата за лицензию производится исключительно золотыми дублонами... Ну, теперь, наверное, все прояснили. На какой срок вы хотите получить лицензию?";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l2.go = "exit";
		break;
		
		case "licence_1":
			float fQty = stf(dialogEditStrings[6]);
			// вариант с дублонами
			npchar.quest.lcc_summ = makeint(sqrt(fQty)*10)*7;
			if (fQty < 1)
			{
				dialog.text = "Месье, пожалуйста, говорите четче, не заикайтесь и не мямлите. Я вас плохо расслышал. Так на сколько дней вам нужна лицензия?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 0 && fQty < 20)
			{
				dialog.text = "Минимальный срок, на который мы выдаем лицензию - двадцать дней. На сколько суток вам выписать - на двадцать, или больше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			if (fQty > 180)
			{
				dialog.text = "Максимальный срок, на который мы выдаем лицензию - полгода. На сколько суток вам выписать - на сто восемьдесят, или меньше?";
				link.l1 = "Сейчас подумаю...";
				link.l1.go = "licence_r";
				break;
			}
			dialog.text = "На "+FindRussianDaysString(sti(fQty))+"? Хорошо. Стоимость такой лицензии составит "+FindRussianDublonString(sti(npchar.quest.lcc_summ))+". Вас устраивает?";			
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(npchar.quest.lcc_summ))
			{
				link.l1 = "Да, конечно, устраивает.";
				link.l1.go = "licence_2";
			}
			link.l2 = "К сожалению, у меня нет сейчас с собой столько денег. Я зайду к вам за лицензией позже.";
			link.l2.go = "exit";
		break;
		
		case "licence_r":
			dialog.text = "";
			link.l1.edit = 6;
			link.l1 = "";	
			link.l1.go = "licence_1";
			link.l2 = "Извините, но мне еще надо обдумать этот вопрос. Я загляну позже.";	
			link.l2.go = "exit";
		break;
		
		case "licence_2":
			int iQty = sti(dialogEditStrings[6]);
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.lcc_summ));
			GiveNationLicence(HOLLAND, iQty);
			dialog.text = "Так, одну минуту... Сейчас поставим подпись и печать... Вот, готово. Получите ваш документ.";
			link.l1 = "Спасибо! До свидания, месье.";
			link.l1.go = "exit";
		break;
		
		case "trade":
			dialog.text = "Слухи вас не обманули. Здесь вы можете приобрести навигационные приборы, такие как корабельный компас, астролябия, хронометр и песочные часы для настройки хронометра по времени острова Форро. Однако в наличии они бывают не всегда, за исключением разве что песочных часов - разбирают, понимаете ли. Так что если не удалось купить, что хотели - зайдите через недельку\nТакже периодически у нас в продаже появляются карты архипелага и подзорные трубы. Желаете посмотреть ассортимент на сегодня?";
			link.l1 = "Да, будьте так любезны.";
			link.l1.go = "trade_1";
			npchar.quest.trade = "true";
		break;
		
		case "trade_1":
			DialogExit();
			if (!CheckAttribute(npchar, "trade_date") || GetNpcQuestPastDayParam(npchar, "trade_date") >= 7)
			{
				GiveItemToTrader(npchar);
				SaveCurrentNpcQuestDateParam(npchar, "trade_date");
			}
			LaunchItemsTrade(npchar, 0);			
		break;

		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Ronald_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Рональд, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Ronald_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "Какие приказания?";
            Link.l1 = "Стой здесь!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "Следуй за мной и не отставай!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "Нужно изменить тип боеприпаса для твоего огнестрельного оружия.";
					Link.l3.go = "SetGunBullets";
				}	
			}


		break;

		
		case "SetGunBullets":
			Dialog.Text = "Выбор типа боеприпаса:";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");;
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
        case "Boal_Stay":
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
            dialog.Text = "Есть изменить дислокацию!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "Есть изменить дислокацию!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
        break;
	//<-- ----------------------------------- офицерский блок ----------------------------------------
	
	// на Тайясаль
		case "tieyasal":
			dialog.text = "Ты чертовски удачлив, кэп. Я рад, что присоединился к тебе тогда, на Доминике. И проглоти меня акула, если я не поддержу тебя и в этом предприятии!";
			link.l1 = "Спасибо, Рональд! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Когда мы будем отправляться?";
			link.l1 = "Немного позже. А пока подготовимся к походу.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21_1");
			npchar.quest.Tieyasal = "teleport";
		break;


		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit1":			
			DialogExit();
		break;

	}
}