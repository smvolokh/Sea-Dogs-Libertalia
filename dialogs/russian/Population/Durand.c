// Клод Дюран - знакомый Мишеля де Монпе, канонир
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, n, iTemp;
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
			dialog.text = "Ба, аккуратней на поворотах кэп!";
			link.l1 = "Извини, дружище, что-то задумался немного. Меня зовут "+GetFullName(pchar)+", а как твоё имя?";
			link.l1.go = "Durand_1";			
		break;

		case "Durand_1":
			dialog.text = "Ничего страшного, кэп. Клод Дюран собственной персоной.";
			link.l1 = "Ха! Дюран? Наслышан, наслышан о тебе. От нашего общего друга...";
			link.l1.go = "Durand_2";			
		break;

		case "Durand_2":
			dialog.text = "Какого друга, капитан? Уж не шпик ли ты Голландской Вест-Индской Компании?";
			link.l1 = "Не горячись ты! И убери руку с эфеса клинка. Никакой я не агент. Нашего общего друга зовут Мишель де Монпе. Помнишь такого?";
			link.l1.go = "Durand_3";			
		break;

	case "Durand_3":
			dialog.text = "Старина Мишель? Конечно помню! Как же я могу забыть человека, который в своё время вытащил меня из такой переделки!";
			link.l1 = "Что за переделка? Интересно было бы послушать!";
			link.l1.go = "Durand_4";			
		break;

	case "Durand_4":
			dialog.text = "Послушать? Хм... Ну, слушай тогда. Дело было так. Купил я как-то карту сокровищ у одного проходимца в таверне. Он мне такой: ''Богатым будешь, пусть тебе улыбнётся удача!'' - ага, как бы не так! Чёрт бы побрал этого прохиндея с его сокровищами! Но да ладно, отправился я к кладу, а дело было на Терксе, захожу я в грот, а там сундук. Открываю я его, значит, а там куча драгоценных камней!";
			link.l1 = "Камней? Здорово же! Что тогда пошло не так?";
			link.l1.go = "Durand_5";			
		break;

	case "Durand_5":
			dialog.text = "Кэп, не перебивай, а слушай дальше!";
			link.l1 = "Ладно-ладно. Что было дальше?";
			link.l1.go = "Durand_6";			
		break;

	case "Durand_6":
			dialog.text = "Так, о чём это я... Ах, да! Куча драгоценных камней в том сундуке было! Не успел я достать мешок, чтобы набить его своей драгоценной добычей, как слышу сзади шорох... Поворачиваю голову, а там на меня уже направлено больше дюжины голландских мушкетонов! Выходит их офицер и мне говорит:  ''Именем Республики Соединённых Провинций! Отдавай камни или умри!'' - я, конечно, отдавать ничего не собирался, ибо слишком много денег я на эту карту потратил...";
			link.l1 = "Хм, а собственная шкура равзе не дороже?";
			link.l1.go = "Durand_7";			
		break;

	case "Durand_7":
			dialog.text = "Ты прав, "+pchar.name+"! Вот только, денег-то на карту эту я занял у ростовщика местного, а потому и выбор у меня не особо большой был... Либо меня пришили бы голландцы, либо ростовщик нанял бы охотников за головами...";
			link.l1 = "Мда, патовая ситуация...";
			link.l1.go = "Durand_8";			
		break;

	case "Durand_8":
			dialog.text = "А то! Так вот, говорит он мне: ''Именем Республики! Отдавай камни по-хорошему, а то мы тебя тут и положим!'' - я уже начал продумывать пути отхода, а тут заваливается в грот наш Мишель со своим отрядом! Голландцы растерялись, стало быть, внимание с меня на него переключили. Завязалась между ними схватка, ибо Мишель не особо намеривался перед ними речи толкать. Положили он и его ребята голландцев. Я то думал, что всё, конец! Сейчас и меня порешат, а нет! Мишель подходит ко мне и спрашивает, что я здесь делаю, как имя моё и всё такое.\nЯ и объяснил ему, что звать меня Клодом, рассказал про ситуацию с картой и ростовщиком. Мишель глянул на меня и сказал, а давай тогда честь по чести разделим сокровища! Мне, как первому нашедшему, половина и ему, как спасителю, другая. Я и согласился, ибо он и вправду спас меня, да и половина этих камней - это уже было целое состояние... На том и порешили. На выходе из бухты нас поджигал большой пинас, там я уже Мишеля выручил, всадив голландцу ядро прямо под ватерлинию первым же выстрелом! Не зря же я полжизни прослужил артиллеристом на флоте.";
			link.l1 = "Мда, занятная история... Слушай, Мишель мне рассказывал, что ты канонир толковый. А ко мне в команду пойти не желаешь? Койку, место и долю в добыче я тебе обещаю!";
		link.l1.go = "Durand_9";			
		break;

	case "Durand_9":
			dialog.text = "Мишель не соврал, "+pchar.name+", ведь я был лучшим арттилеристом в полку! Эх... Вот только неувязочка есть одна. Ты думаешь, а чего я тут стою? Денег я должен, сумму кругленькую... Вот этой свинье, которая в кресле развалилась. Покуда долг не отдам с Доминики мне выхода нет.";
			link.l1 = "Зачем занимать денег если отдать не можешь? Сколько ты должен?";
		link.l1.go = "Durand_10";		
		break;

	case "Durand_10":
			dialog.text = "Зуб даю, кэп, с этим долгом расчитаюсь и больше никогда в долг брать не буду. А должен я около сотни тысяч песо.";
			link.l1 = "Ого! Сумма приличная. Ладно, если я заплачу её, то ты пойдешь ко мне в команду?";
		link.l1.go = "Durand_11";		
		break;

	case "Durand_11":
			dialog.text = ""+pchar.name+", впрямь выплатишь мой долг? За такой поступок я не только к тебе в команду пойду, я с тобой хоть в пасть к морскому дьяволу отправлюсь!";
			link.l1 = "Чудно, но чтобы больше никаких долгов, ладно?";
		link.l1.go = "Durand_12";		
		break;

	case "Durand_12":
			if(makeint(Pchar.money) >= 100000)
			{
     		dialog.text = "Да, конечно, кэп! О чём разговор?";
			link.l1 = "Держи деньги, уладь формальности и не опаздывай к отплытию.";
			link.l1.go = "Durand_13";
			link.l2 = "Хорошо, я раздобуду нужную сумму и мы вернёмся к этому разговору.";
link.l2.go = "Exit_Durand";	
			}
			else
			{
              dialog.text = "Да, конечно, кэп! О чём разговор?";
			link.l2 = "Хорошо, я раздобуду нужную сумму и мы вернёмся к этому разговору.";
link.l2.go = "Exit_Durand";					
			}
		break;

	case "Durand_13":
		dialog.text = "К отплытию буду как штык, капитан!";
		link.l1 = "Чудно!";
		link.l1.go = "Durand_hired_1";		
	break;

	case "Exit_Durand":
		dialog.text = "Эх, буду с нетерпением ждать, кэп. Остчертело стоять тут как истукан!";
		link.l1 = "Смотри опять долгов не нахватай!";
		link.l1.go = "Exit_Durand_1";		
	break;


	case "Second time":
		if(makeint(Pchar.money) >= 100000)
		{
dialog.text = "Кэп, ты нашёл деньги для уплаты моего долга?";
link.l1 = "Да, держи деньги, уладь формальности и не опаздывай к отплытию.";
		link.l1.go = "Durand_13";
link.l2 = "Да, я почти нашёл нужную сумму. Потерпи немного.";
link.l2.go = "Exit_Durand";	
		}
		else
		{
dialog.text = "Кэп, ты нашёл деньги для уплаты моего долга?";
link.l2 = "Да, я почти нашёл нужную сумму. Потерпи немного.";
link.l2.go = "Exit_Durand";					
			}
		break;

case "Durand_hired_1"://Клода - в офицеры                                              chrDisableReloadToLocation = false;//открыть локацию
DialogExit();
DeleteAttribute(npchar, "LifeDay");
AddMoneyToCharacter(Pchar, -100000);
npchar.quest.OfficerPrice = sti(pchar.rank)*500;
npchar.OfficerWantToGo.DontGo = true;//не пытаться уйти
npchar.loyality = MAX_LOYALITY;
AddPassenger(pchar, npchar, false);
SetCharacterRemovable(npchar, true);
npchar.Payment = true;
npchar.DontClearDead = true;
LAi_SetOfficerType(npchar);
npchar.greeting = "Gr_Diego";
NextDiag.CurrentNode = "Durand_officer";
npchar.quest.meeting = true;
npchar.HoldEquip = true;
LAi_SetImmortal(npchar, false);
TakeNItems(npchar, "Rumm", 1);
LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
break;
		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Durand_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Клод, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Durand_officer";
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
			link.l1 = "Спасибо, Клод! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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


		case "Exit_Durand_1":
			NextDiag.CurrentNode = "Second time";
			DialogExit();
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