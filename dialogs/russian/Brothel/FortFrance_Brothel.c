// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    ref sld;   
	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, "+ GetSexPhrase("молодой человек","юная леди") +"?", "Чего ты хочешь, "+ GetSexPhrase("красавчик","красотка") +"? Задавай свои вопросы..."), "Опять вопросы?", "Хи-хи, третий раз на дню одно и то же - вопросы...",
                          ""+ GetSexPhrase("Хм, может ты выберешь какую-нибудь красотку себе? А то у меня уже складывается в отношении тебя вполне определенное мнение...","Хм, может ты выберешь какую-нибудь красотку себе? Мальчиков не держим, хи-хи...") +"", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал...", "Хм, да ничего..."), "Не могу... Нет вопросов...",
                      "Да уж, действительно в третий раз... Извини.", "Не сейчас... В другой раз...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// ==> Проверяем поле состояния квестов.
			//--> Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie.Gigolo") && pchar.questTemp.Sharlie.Gigolo == "start")
			{
				link.l1 = "Послушай, Аврора, мне нужна девочка на эту ночь. Причем не наверху в твоем заведении, а у меня дома. Ты можешь мне помочь?";
                link.l1.go = "Gigolo";
			}	
			//<-- Бремя гасконца

			//--> Гот. линейка
			if (pchar.questTemp.GothicLee == "SeekBible_toFFBrothel" && npchar.id == "FortFrance_Hostess") 
			{
				link.l1 = "Аврора, у меня к вам вопрос по существу! Ты можешь мне помочь? У вас в компании не давно завис Торус с корсарами.";
                                                               link.l1.go = "Gothic_SeekBible_1";
			}	

			//<-- Гот. линейка

			if (pchar.questTemp.Sharp == "seekSharp" && GetNpcQuestPastDayWOInit(npchar, "quest.SharpTime") > 3 && !LAi_IsDead(&characters[GetCharacterIndex("Sharp")]))
			{
				link.l1 = "Послушай, " + npchar.name + ", я ищу Шарпа. Ты не знаешь, где он?";
				link.l1.go = "SharpPearl_1";
				SaveCurrentNpcQuestDateParam(npchar, "quest.SharpTime");
			}
            // <== Проверяем поле состояния квестов.
		break;
		
		//--> Бремя гасконца
		case "Gigolo":
			dialog.text = "Конечно, дорогой. Какая девушка тебе нужна? Ты присмотрел себе кого-нибудь, или тебе всё равно?";
			link.l1 = "Мне не все равно. Мне нужна девушка по имени Люсиль.";
			link.l1.go = "Gigolo_1";
		break;
		
		case "Gigolo_1":
			dialog.text = "Ты имеешь в виду Люсиль Монтань?";
			link.l1 = "Честно говоря, я не спрашивал у нее фамилию. Я только знаю, что это молодая смазливая блондиночка с именем Люсиль.";
			link.l1.go = "Gigolo_2";
		break;
		
		case "Gigolo_2":
			dialog.text = "Хорошо... Скажи, а почему именно Люсиль? Другие девочки тебе не приглянулись?";
			link.l1 = "Хм... Она недавно у тебя, и, думаю, пока не совсем искушена в этого рода делах, поэтому не может стоить очень дорого.";
			link.l1.go = "Gigolo_2_1";
			link.l2 = "Мне очень нравятся белокожие и светловолосые девушки. Именно поэтому я хочу взять Люсиль.";
			link.l2.go = "Gigolo_2_2";
		break;
		
		case "Gigolo_2_1":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand1) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 5000;
				dialog.text = "Тут ты не прав. Она молода, красива, умеет делать все, что положено, и пользуется вниманием клиентов. Она стоит недешево. За ночь с ней тебе нужно будет заплатить пять тысяч песо, и ни сантима меньше.";
				if (sti(pchar.money) >= 5000)
				{
					link.l1 = "Хм... Дороговато будет. Но я не привык отказываться от своих желаний. Вот, держи деньги.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Хех! У меня сейчас нет таких денег. Давай вернемся к этому разговору позже.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 2500;
				dialog.text = "Ну, в общем-то, так и есть - у нее маловато опыта, клиенты ее вниманием не жалуют, поэтому я и спросила. Но если тебе нравятся скромницы - то выбор удачный. За ночь с ней тебе нужно заплатить две тысячи пятьсот песо.";
				if (sti(pchar.money) >= 2500)
				{
					link.l1 = "Без проблем. Вот, держи деньги.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Хех! У меня сейчас нет таких денег. Давай вернемся к этому разговору позже.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_2_2":
			if (sti(pchar.questTemp.Sharlie.Gigolo.Rand2) == 0)
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 4500;
				dialog.text = "Да, ты не один такой любитель, красавчик. К ней уже не раз очередь выстраивалась - она сильно отличается от темнокожих дочерей наших островов. За ночь с Люсиль тебе придется выложить четыре с половиной тысячи песо и ни сантима меньше.";
				if (sti(pchar.money) >= 4500)
				{
					link.l1 = "Хм... Дороговато будет. Но я не привык отказываться от своих желаний. Вот, держи деньги.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Хех! У меня сейчас нет таких денег. Давай вернемся к этому разговору позже.";
					link.l1.go = "exit";
				}
			}
			else
			{
				pchar.questTemp.Sharlie.Gigolo.Money = 3000;
				dialog.text = "Вот как? Наверное, тоска по Европе мучает? Мои креолки, а тем более мулатки - куда более любвеобильные девушки, нежели эта дочь парижских трущоб. Но если она тебе нравится - я только рада. С тебя три тысячи песо.";
				if (sti(pchar.money) >= 3000)
				{
					link.l1 = "Без проблем. Вот, держи деньги.";
					link.l1.go = "Gigolo_3";
				}
				else
				{
					link.l1 = "Хех! У меня сейчас нет таких денег. Давай вернемся к этому разговору позже.";
					link.l1.go = "exit";
				}
			}
		break;
		
		case "Gigolo_3":
			AddMoneyToCharacter(pchar, -sti(pchar.questTemp.Sharlie.Gigolo.Money));
			dialog.text = "Отлично, дорогой. Девушка освободится в одиннадцать часов вечера и будет ждать тебя. Назад она должна вернуться не позже семи утра. Если не заберешь Люсиль до полуночи - ей займется другой клиент, и тогда тебе придется ждать следующего вечера\nИ не вздумай устроить с ней что-нибудь... неподобающее, иначе проблемы я тебе гарантирую. Не сочти за оскорбление, я просто предупреждаю.";
			link.l1 = "Не переживай. Я беру эту девушку для любви, а не для чего-то еще. В одиннадцать вечера я ее заберу. Всего доброго!";
			link.l1.go = "Gigolo_4";
		break;
		
		case "Gigolo_4":
			DeleteAttribute(pchar, "GenQuest.CannotWait");
			DialogExit();
			AddQuestRecord("SharlieC", "2");
			pchar.questTemp.Sharlie.Gigolo = "girl";
			Sharlie_CreateGigoloGirl();
		break;

                                                //-->Гот. линейка
        case "Gothic_SeekBible_1":
            dialog.text = "Молодой человек, они отдыхают у нас в компании девушек, а не друг друга! Следите за тем, что произносите...";
            link.l1 = "Хорошо, они отдыхали в большой компании...";
            link.l1.go = "Gothic_SeekBible_2";
        break;
        case "Gothic_SeekBible_2":
            dialog.text = "Действительно в большой, народу там было много. Надолго мне запомнится этот их отдых...";
            link.l1 = "Почему, позволь тебя спросить?";
            link.l1.go = "Gothic_SeekBible_3";
        break;
        case "Gothic_SeekBible_3":
            dialog.text = "Да потому, что все мое заведение работало на них в эту ночь. Ужас был какой-то!";
            link.l1 = "Понятно... Слушай, ты не слышала вот о чем: кто-то пытался продать одну книгу, вроде Библию...";
            link.l1.go = "Gothic_SeekBible_4";
        break;
        case "Gothic_SeekBible_4":
            dialog.text = "Нет, такого я не слышала.";
            link.l1 = "А может девушки твои подскажут?";
            link.l1.go = "Gothic_SeekBible_5";
        break;
        case "Gothic_SeekBible_5":
            dialog.text = "Может и подскажут. Только мне до этого дела нет, спрашивай сам.";
            link.l1 = "А кого? Кто у них там был в эту ночь?";
            link.l1.go = "Gothic_SeekBible_6";
        break;
        case "Gothic_SeekBible_6":
            dialog.text = "Все были! Все, как одна! Всех и спрашивай. Может действительно кто и вспомнит...";
            link.l1 = "Спасибо тебе, пойду спрашивать...";
            link.l1.go = "exit";
            pchar.questTemp.GothicLee = "SeekBible_toGirl";
        break;
			//<-- Гот. линейка

		// капитан Шарп, грабеж жемчужных промыслов
		case "SharpPearl_1":
			if (drand(1) || bBettaTestMode)
			{
				if (sti(pchar.questTemp.Sharp.brothelChance) < 9)
				{	//футболим геймера в город
					pchar.questTemp.Sharp.City = GetSharpCity();
					pchar.questTemp.Sharp.City.rumour = true; //флаг дачи слуха
					dialog.text = "Насколько мне известно, капитан Шарп отправился в " + XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc") + ".";
					link.l1 = "Хех! Благодарю тебя, " + npchar.name + ". Ты мне здорово помогла!";
					link.l1.go = "exit";
					pchar.questTemp.Sharp = "toSharp_going"; //в бордели больше не заходить
					ReOpenQuestHeader("SharpPearl");
					AddQuestRecord("SharpPearl", "1");
					AddQuestUserData("SharpPearl", "sCity", XI_ConvertString("Colony" + npchar.city + "Dat"));
					AddQuestUserData("SharpPearl", "sTarget", XI_ConvertString("Colony" + pchar.questTemp.Sharp.City + "Acc"));
					if (GetIslandByCityName(pchar.questTemp.Sharp.City) != pchar.questTemp.Sharp.City)
					{
						AddQuestUserData("SharpPearl", "sAreal", ", что находится на " + XI_ConvertString(GetIslandByCityName(pchar.questTemp.Sharp.City) + "Dat"));
					}
					//запускаем энкаунтер Шарпа на карте
					group_DeleteGroup("Sharp_Group");
					sld = characterFromId("Sharp");
					string sGroup = "Sharp_Group";
					Group_FindOrCreateGroup(sGroup);
					Group_SetTaskAttackInMap(sGroup, PLAYER_GROUP);
					Group_LockTask(sGroup);
					Group_AddCharacter(sGroup, sld.id);
					Group_SetGroupCommander(sGroup, sld.id);
					sld.mapEnc.type = "trade";
					sld.mapEnc.worldMapShip = "quest_ship";
					sld.mapEnc.Name = "бриг 'Шарпоносец'";
					string sColony= SelectAnyColony(npchar.city); //колония, откуда плывет Шарп
					int daysQty = GetMaxDaysFromIsland2Island(GetArealByCityName(sColony), GetArealByCityName(pchar.questTemp.Sharp.City))+3; //дней доехать даем с запасом
					Map_CreateTrader(sColony, pchar.questTemp.Sharp.City, sld.id, daysQty);
					Log_TestInfo("Шарпоносец установлен из " + sColony + "  в " + pchar.questTemp.Sharp.City);
				}
				else
				{	//чудо, Шарп здесь, в борделе!
					dialog.text = "Знаю. Он у меня в заведении отдыхает. Могу позвать, если он тебе срочно нужен.";
					link.l1 = "Сделай, одолжение, " + npchar.name + "...";
					link.l1.go = "SharpPearl_2";
				}
			}
			else
			{
				dialog.text = "Не знаю, у меня его давно уже не было.";
				link.l1 = "Понятно... Ну что же, спасибо тебе, " + npchar.name + ".";
				link.l1.go = "exit";
			}
		break;
		case "SharpPearl_2":
			dialog.text = "Барталомью-ю-ша! Зайди ко мне, дорогой, тебя тут спрашивают!";
			link.l1 = "Хех, а Шарп у вас в почете, как я погляжу...";
			link.l1.go = "SharpPearl_3";
		break;
		case "SharpPearl_3":
			chrDisableReloadToLocation = true;
			pchar.questTemp.Sharp.count = 0; //счетчик нулим для след. раза
			pchar.questTemp.Sharp.price = 5000+rand(20)*1000; //цена за наводку
			pchar.questTemp.Sharp.price.evil = rand(1); //добрый или злой, для скидки
			sld = &characters[GetCharacterIndex("Sharp")];
			sld.dialog.currentnode = "BrothelSharp";
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER_OWN);
			ChangeCharacterAddressGroup(sld, pchar.location, "reload", "reload1");
			LAi_SetActorTypeNoGroup(sld);
			LAi_ActorDialog(sld, pchar, "", -1, 0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

