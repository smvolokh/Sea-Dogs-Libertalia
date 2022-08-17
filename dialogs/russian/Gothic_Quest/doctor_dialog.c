string disease ="";
string disease1 ="";			

string MiscDisease(string s1,string s2,string s3);
{
	string s;
	
	switch(s3)
	{
		case "3":
			s = "Да у вас сразу ";
			switch(s1)
			{
				case "Chesotka":
					s += "чесотка и ";
				break;
				case "Lihoradka":
					s += "лихорадка и ";
				break;
				case "YellowLihoradka":
					s += "желтая лихорадка и ";
				break;
				case "Dirty":
					s += "грязная болезнь и ";
				break;
				case "Chill":
					s += "простуда и ";
				break;
				case "Plague":
					s += "чума и ";
				break;
				case "Fester":
					s += "рана и ";
				break;
			}
			switch(s2)
			{
				case "Chesotka":
					s += "чесотка.";
				break;
				case "Lihoradka":
					s += "лихорадка.";
				break;
				case "YellowLihoradka":
					s += "желтая лихорадка.";
				break;
				case "Dirty":
					s += "грязная болезнь.";
				break;
				case "Chill":
					s += "простуда.";
				break;
				case "Plague":
					s += "чума.";
				break;
				case "Fester":
					s += "рана.";
				break;
			}
			s += " С чего начнём?";
			return s;
		break;
		case "1":
			switch(s1)
			{
				case "Chesotka":
					s = "С чесотки.";
				break;
				case "Lihoradka":
					s = "С лихорадки.";
				break;
				case "YellowLihoradka":
					s = "С желтой лихорадки.";
				break;
				case "Dirty":
					s = "С грязной болезни.";
				break;
				case "Chill":
					s = "С простуды.";
				break;
				case "Plague":
					s = "С чумы.";
				break;
				case "Fester":
					s = "С раны.";
				break;
			}
			return s;
		break;
		case "1go":
			switch(s1)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
		case "2":
			switch(s2)
			{
				case "Chesotka":
					s = "С чесотки.";
				break;
				case "Lihoradka":
					s = "С лихорадки.";
				break;
				case "YellowLihoradka":
					s = "С желтой лихорадки.";
				break;
				case "Dirty":
					s = "С грязной болезни.";
				break;
				case "Chill":
					s = "С простуды.";
				break;
				case "Plague":
					s = "С чумы.";
				break;
				case "Fester":
					s = "С раны.";
				break;
			}
			return s;
		break;
		case "2go":
			switch(s2)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
	}

	switch(s3)
	{
		case "4":
			switch(s1)
			{
				case "Chesotka":
					s = "Вы что-то говорили ещё о чесотке.";
				break;
				case "Lihoradka":
					s = "Вы что-то говорили ещё о лихорадке.";
				break;
				case "YellowLihoradka":
					s = "Вы что-то говорили ещё о жёлтой лихорадке.";
				break;
				case "Dirty":
					s = "Вы что-то говорили ещё о грязной болезни.";
				break;
				case "Chill":
					s = "Вы что-то говорили ещё о простуде.";
				break;
				case "Plague":
					s = "Вы что-то говорили ещё о чуме.";
				break;
				case "Fester":
					s = "Вы что-то говорили ещё о гнойной ране.";
				break;
			}
			return s;
		break;
		case "4go":
			switch(s1)
			{
				case "Chesotka":
					s = "Disease_Chesotka_1";
				break;
				case "Lihoradka":
					s = "Disease_Lihoradka_2";
				break;
				case "YellowLihoradka":
					s = "Disease_YellowLihoradka_2";
				break;
				case "Dirty":
					s = "Disease_Dirty_1";
				break;
				case "Chill":
					s = "Disease_Chill";
				break;
				case "Plague":
					s = "Disease_Plague_2";
				break;
				case "Fester":
					s = "Disease_Fester";
				break;
			}
			return s;
		break;
	}
}

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
		case "First time":

			if(!CheckAttribute(npchar, "dialog2.Year"))
			{
		dialog.text = NPCharSexPhrase(npchar, "Доброго времени "+NPChar.name+" "+NPChar.lastname+", эм... Что-то я не припоминаю вас.", "С кем имею честь разговаривать?", "Доброго времени "+NPChar.name+" "+NPChar.lastname+", эм... Что-то я не припоминаю вас.", "С кем имею честь разговаривать?");
				link.l1 = "" + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Я капитан.";
				link.l1.go = "Dialog_1";
			}else{
				if((GetDataYear() > npchar.dialog2.Year) || (GetDataMonth() > npchar.dialog2.Month) || (GetDataDay() > npchar.dialog2.Day))
				{

		dialog.text = NPCharSexPhrase(npchar, "Какие люди! Заходите, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Давненько вас не видел. Какими судьбами?", "Ой, капитан, я так и знала, что вы зайдете, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Давненько вас не видел" + GetSexPhrase("","а") + ". Какими судьбами?");
			link.l1 = "Расскажи мне немного о болезнях.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "Покажи, что у тебя есть в продаже.";
			link.l2.go = "Dialog_trade";

					if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
					{
						link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
						link.l3.go = "Dialog_disease";
					}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
						link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
						link.l3.go = "Dialog_disease";
					}}

					link.l4 = "До встречи "+NPChar.name+". Мне пора идти.";
					link.l4.go = "Dialog_exit";

				}else{

		dialog.text = NPCharSexPhrase(npchar, "Какие люди! Заходите, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Давненько вас не видел. Какими судьбами?", "Ой, капитан, я так и знала, что вы зайдете, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+". Давненько вас не видел" + GetSexPhrase("","а") + ". Какими судьбами?");
					link.l1 = "Расскажи мне немного о болезнях.";
					link.l1.go = "Dialog_disease_info";
					link.l2 = "Покажи, что у тебя есть в продаже.";
					link.l2.go = "Dialog_trade";
					link.l3 = "До встречи "+NPChar.name+". Мне пора идти.";
					link.l3.go = "Dialog_exit";

				}
			}

			// Розо или Шарлотт-Таун
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "KillworkRoseauCharlotte" && !CheckAttribute(npchar, "quest.KillworkRoseauCharlotte"))
			{
				link.l1 = "Я по поручению Торуса расследую убийство в борделе, ничего не слышал об этом, может, что видел, может мысли какие - нибудь? Где вы были в тот день, что делали?";
				link.l1.go = "KillworkRoseauCharlotte";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "Killwork" && !CheckAttribute(npchar, "quest.Killwork"))
			{
				link.l1 = "Константино, вы утвеждали, что были целый день дома и варили зелья?";
				link.l1.go = "Killwork";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlottePRESENT" && !CheckAttribute(npchar, "quest.RoseauCharlottePRESENT"))
			{
				link.l1 = "Я от Торуса и...";
				link.l1.go = "RoseauCharlottePRESENT";
			}

		break;

 		case "KillworkRoseauCharlotte":
        	                  dialog.text = "Об этом все и говорят, не могу добавить ничего нового.";
		link.l1 = "Действительно столько народу и никто ничего не видел?";
    		link.l1.go = "KillworkRoseauCharlotte_1";
		break;

                                      case "KillworkRoseauCharlotte_1":
		dialog.text = "Прошу прощения у меня много дел.";
		link.l1 = "Дела подождут, вот например где вы были и, что делали в тот день!";
		link.l1.go = "KillworkRoseauCharlotte_2";
  		break;

                                      case "KillworkRoseauCharlotte_2":
		dialog.text = "Как обычно был здесь, варил зелья.";
		link.l1 = "Понятно.";
		link.l1.go = "exit";
		npchar.quest.KillworkRoseauCharlotte = "true";
		pchar.questTemp.KillworkRoseauCharlotte = sti(pchar.questTemp.KillworkRoseauCharlotte)+1;
		if (sti(pchar.questTemp.KillworkRoseauCharlotte) == 8) 
		{
		AddDialogExitQuestFunction("KillworkRoseaugirl");
		}
  		break;

 		case "Killwork":
        	                  dialog.text = "Да это так.";
		link.l1 = "Но вас видели в тот день утром, как вы входили из сельвы в город, вы можете рассказать с этого момента поподробнее?";
    		link.l1.go = "Killwork_1";
		break;

                                      case "Killwork_1":
		dialog.text = "Ранним утром я всегда собираю индигриенты за городскими воротами.";
		link.l1 = "И ничего подозрительного не заметили!";
		link.l1.go = "Killwork_2";
  		break;

                                      case "Killwork_2":
		dialog.text = "Да нет, всё как обычно, собираю растения, здороваюсь с куратор Аршамбо де Ансильоном.";
		link.l1 = "С кем, с куратором? Я не ослышался?";
		link.l1.go = "Killwork_3";
  		break;

                                      case "Killwork_3":
		dialog.text = "Не ослышались, всё верно.";
		link.l1 = "А он, что делает там по утрам, случаем не зарядку.";
		link.l1.go = "Killwork_4";
  		break;

                                      case "Killwork_4":
		dialog.text = "Не знаю, я в сельву а он из сельвы, там мы и встречаемся иногда, здороваемся и всё.";
		link.l1 = "Как интересно, ладно пока вопросов нет.";
		link.l1.go = "Killwork_5";
		AddDialogExitQuestFunction("Killwork_huber");
  		break;

                                      case "Killwork_5":
		DialogExit();
		pchar.quest.Killworkhour.win_condition.l1 = "locator";
		pchar.quest.Killworkhour.win_condition.l1.location = "Roseau_Town";
		pchar.quest.Killworkhour.win_condition.l1.locator_group = "reload";
		pchar.quest.Killworkhour.win_condition.l1.locator = "reload13";

		pchar.quest.Killworkhour.win_condition.l2 = "HardHour";
		pchar.quest.Killworkhour.win_condition.l2.start.hour = 0;
		pchar.quest.Killworkhour.win_condition.l2.finish.hour = 5;
		pchar.quest.Killworkhour.function = "Killwork_huber_hour";
		npchar.quest.Killwork = "true";
  		break;

                                      case "RoseauCharlottePRESENT":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_15_00.wav");
		dialog.text = "";
		link.l1 = "Мне нужно лечение....";
		link.l1.go = "PRESENT_1";
  		break;

                                      case "PRESENT_1":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_10_01.wav");
		dialog.text = "Зачем, ты ранен?";
		link.l1 = "";
		link.l1.go = "PRESENT_2";
  		break;

                                      case "PRESENT_2":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_NEIN_15_00.wav");
		dialog.text = "";
		link.l1 = "В общем - то нет!!!";
		link.l1.go = "PRESENT_3";
  		break;

                                      case "PRESENT_3":
 	                   PlaySound("VOICE\Russian\gotica\CONSTANTINO\DIA_CONSTANTINO_HEILUNG_NEIN_10_01.wav");
		dialog.text = "Тогда проваливай, а то тебе действительно потребуется медицинская помощь!";
		link.l1 = "";
		link.l1.go = "PRESENT_4";
  		break;

                                      case "PRESENT_4":
		dialog.text = "";
		link.l1 = "Ты не так понял, я от Торуса и мне нужны зелья...";
		link.l1.go = "PRESENT_5";
  		break;

                                      case "PRESENT_5":
		dialog.text = "Ах, да я и забыл об этом, у меня есть удар прибоя, ласка моря и шквал...";
		link.l1 = "";
		link.l1.go = "PRESENT_6";
  		break;

                                      case "PRESENT_6":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\FELL.wav");
		dialog.text = "";
		link.l1 = "Отдай мне всё, что у тебя есть.";
		link.l1.go = "PRESENT_7";
  		break;

                                       case "PRESENT_7":
		 TakeNItems(pchar, "mangarosafast", 2);
		 Log_Info("Вы получили шквал");
		 TakeNItems(pchar, "mangarosatotal", 2);
		 Log_Info("Вы получили ласку моря");
		 TakeNItems(pchar, "mangarosapower", 2);
		 Log_Info("Вы получили удар прибоя");
                                       PlaySound("Ambient\Tavern\naliv_003.wav");
		 DialogExit();
		 NextDiag.CurrentNode = NextDiag.TempNode;
		 npchar.quest.RoseauCharlottePRESENT = "true";
  		 break;

		
		case "Dialog_1":
			dialog.text = "Меня зовут "+NPChar.name+" "+NPChar.lastname+". По профессии я врач. Моя обязанность - слежение за состоянием здоровья и лечение людей в колонии. Для этого у меня имеются все необходимые медикаменты, доступные в свободной продаже.";
			link.l1 = "Расскажи мне немного о болезнях.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "Покажи, что у тебя есть в продаже.";
			link.l2.go = "Dialog_trade";

			if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
			{
				link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
				link.l3.go = "Dialog_disease";
			}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
				link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
				link.l3.go = "Dialog_disease";
			}}
		
			link.l4 = "Было приятно познакомиться. До встречи "+NPChar.name+".";
			link.l4.go = "Dialog_exit";
		break;


		case "Dialog_disease_info":
			dialog.text = "На Карибском архипелаге распространены такие болезни как чесотка, жёлтая и обыкновенная лихорадки, простуда, чума и заболевание личного характера, именуемое грязной болезнью, а также не стоит забывать и про раны.";
			link.l1 = "Расскажи про чесотку.";
			link.l1.go = "Dialog_info_Chesotka";
			link.l2 = "Поведай мне о лихорадке.";
			link.l2.go = "Dialog_info_Lihoradka";
			link.l3 = "Расскажи про жёлтую лихорадку.";
			link.l3.go = "Dialog_info_YellowLihoradka";
			link.l4 = "Что такое грязная болезнь?";
			link.l4.go = "Dialog_info_Dirty";
			link.l5 = "Расскажи мне про простуду.";
			link.l5.go = "Dialog_info_Chill";
			link.l6 = "Я хочу узнать немного больше о чуме.";
			link.l6.go = "Dialog_info_Plague";
			link.l7 = "А что насчет ран?";
			link.l7.go = "Dialog_info_Fester";
			link.l8 = "Мне пора идти. Извините, что прерываю вас.";
			link.l8.go = "Dialog_exit";
		break;


		case "Dialog_info_Chesotka":
			dialog.text = "Чесотка - чрезвычайно распространенная болезнь, характер возникновения которой пока не известен. При данном заболевании у больного чешется всё тело, зуд усиливается ближе к ночи, не давая больному покоя. При чесотке характерны пузырьковые высыпания, но пока их характер не определен...";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Chesotka_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Chesotka_1":
			dialog.text = "Единственным действенным лечением, на данный момент, является мазь на основе серы. Её необходимо втирать в кожу один раз на ночь, как правило, уже через несколько дней болезнь идет на убыль, а через неделю больной выздоравливает полностью.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Lihoradka":
			dialog.text = "Лихорадка - чрезвычайно распространённая болезнь, подхватить её в этом жарком тропическом климате, проще простого. Больного бросает то в жар, то в холод и без надлежащего ухода это оканчивается смертью спустя пять-семь дней после первых приступов.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Lihoradka_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Lihoradka_1":
			dialog.text = "Наиболее эффективным способом лечения, является приём внутрь мелко истолченной коры хинного дерева.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_YellowLihoradka":
			dialog.text = "Жёлтая лихорадка - чрезвычайно опасное заболевание. Больного беспокоит жар, боли во всем теле, кровотечения и рвоты. Часто организм не выдерживает и прекращает борьбу, тогда следует смерть больного.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_YellowLihoradka_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_YellowLihoradka_1":
			dialog.text = "Действенных методов лечения пока не найдено, но уход за больным, компрессы и молитвы дают довольно хороший результат.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Dirty":
			dialog.text = "Грязная болезнь - настоящий бич завсегдатаев борделей и девушек лёгкого поведения. Скорей всего болезнь передаётся в момент близости мужчины и женщины. Проявляется у больного, как правило, болями и выделениями гноя из причинного места. Часто болезнь проходит сама собой, иногда она резко обостряется, переходя в лихорадку и тогда если не принять срочные меры, всё оканчивается смертью.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Dirty_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Dirty_1":
			dialog.text = "Только покаяние перед богом и молитвы смогут очистить вашу душу и тело. Ускорить эффект поможет использование специальных мазей, которые обладают заживляющим и рассасывающим гной действиями.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Chill":
			dialog.text = "Простуда - чрезвычайно распространена во всем известном мире. Подхватить её проще простого: посидите на сквозняке или походите в мокрой одежде. С развитием болезни, больной жалуется на сильный кашель, жар и выделения из носа.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Chill_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Chill_1":
			dialog.text = "Как правило, за восемь-десять дней недуг проходит сам. Однако травяные настойки и горячее питьё, существенно ускоряют процесс выздоровления.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Plague":
			dialog.text = "Чума - чрезвычайно опасное заболевание человека и животных. Периодически эпидемии чумы охватывали многие страны мира. Первая эпидемия возникла в 6 веке в Восточной Римской империи и охватила многие страны. За 50 лет погибло около 100 миллионов человек. Вторая эпидемия началась в 14 веке. Основными распространителями чумы считаются крысы и мелкая живность. Распространение инфекции происходит по воздуху или через блох и  редко контактным путём.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Plague_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Plague_1":
			dialog.text = "Чума характеризуется острым началом: ознобом, сильной головной болью, возбуждением, помрачением сознания, жаром, возможно воспалением лёгких. Как правило, через неделю следует смерть. Конкретного лекарства против неё нет. В победе над чумой человеку могут помочь некоторые настои и молитва. Чистая душа и вера в помощь Господа Бога - является единственным ключом к спасению.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_exit";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;

		case "Dialog_info_Fester":
			dialog.text = "Каждый человек не застрахован от порезов. Если рану вовремя не обработать, как правило, идёт нагноение и воспаление. Больные жалуются на большие боли в том месте, потерю сознания, бред и лихорадку.";
			link.l1 = "Продолжайте.";
			link.l1.go = "Dialog_info_Fester_1";
			link.l2 = "Я уже всё понял" + GetSexPhrase("","а") + ". Давайте поговорим о чём-нибудь другом.";
			link.l2.go = "Dialog_other";
			link.l3 = "Мне пора идти. Извините, что прерываю вас.";
			link.l3.go = "Dialog_exit";
		break;
		case "Dialog_info_Fester_1":
			dialog.text = "Следует как можно быстрее обработать рану заживляющей мазью, которая снимает нагноение. Если промедлить, то возможна лихорадка, которая оканчивается смертью.";
			link.l1 = "Давайте поговорим о чём-нибудь другом.";
			link.l1.go = "Dialog_other";
			link.l2 = "Мне пора идти. Спасибо за подробный рассказ.";
			link.l2.go = "Dialog_exit";
		break;


		case "Dialog_other":
			dialog.text = "Что же вы хотите узнать?";
			link.l1 = "Расскажи мне немного о болезнях.";
			link.l1.go = "Dialog_disease_info";
			link.l2 = "Покажи, что у тебя есть в продаже.";
			link.l2.go = "Dialog_trade";

			if(CheckAttribute(pchar, "disease.One") && pchar.disease.One != "-1")
			{
				link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
				link.l3.go = "Dialog_disease";
			}else{if(CheckAttribute(pchar, "disease.Two") && pchar.disease.Two != "-1"){
				link.l3 = "Доктор, вы можете посмотреть, что со мной? Я себя неважно чувствую.";
				link.l3.go = "Dialog_disease";
			}}
		
			link.l4 = "Было приятно познакомиться. До встречи "+NPChar.name+".";
			link.l4.go = "Dialog_exit";
		break;


		case "Dialog_disease":
			dialog.text = LinkRandPhrase("Интересно. Расстегните камзол и рубашку. Мне необходимо сперва вас осмотреть и прослушать.", "Будем надеяться, что ничего серьёзного. Давайте присядем. Мне нужно вас осмотреть.", "Вы уже третий обратившийся за этот день. Надеюсь, что это всего лишь совпадение и опасности для эпидемии нет. Давайте присядем.");
			link.l1 = "Как скажете.";
			link.l1.go = "Dialog_disease_1";
		break;
		case "Dialog_disease_1":
			LAI_Fade("","");
			AddTimeToCurrent(0, 15);

			if(CheckAttribute(pchar, "disease.One") && (pchar.disease.One != "-1"))
			{
				disease = pchar.disease.One;
			}

			if(CheckAttribute(pchar, "disease.Two") && (pchar.disease.Two != "-1"))
			{
				disease1 = pchar.disease.Two;
			}

			if((disease != "") && (disease1 != ""))
			{
				dialog.text = MiscDisease(disease,disease1,"3");
				link.l1 = MiscDisease(disease,disease1,"1");
				link.l1.go = MiscDisease(disease,disease1,"1go");
				link.l2 = MiscDisease(disease,disease1,"2");
				link.l2.go = MiscDisease(disease,disease1,"2go");		
			}else{

			if(disease == ""){disease = disease1;}
			switch (disease)
			{
				case "Chesotka":
					dialog.text = LinkRandPhrase("Голубчик, у вас чесотка.", "Всё ясно. Вы больны чесоткой.", "Всё понятно. Судя по симптомам, вы больны чесоткой.");
					link.l1 = "Это не опасно?";
					link.l1.go = "Disease_Chesotka";
				break;
				case "Lihoradka":
					dialog.text = "Скажите, вас знобит?";
					link.l1 = "Да и лёгкое головокружение присутствует.";
					link.l1.go = "Disease_Lihoradka";
				break;
				case "YellowLihoradka":
					dialog.text = "Скажите, вас знобит?";
					link.l1 = "Да, кроме этого ещё лёгкое головокружение с рвотой.";
					link.l1.go = "Disease_YellowLihoradka";
				break;
				case "Dirty":
					dialog.text = "По запаху уже можно определить, что за болезнь. Осмотрев вас, всё только подтвердилось. В народе это называют грязной болезнью.";
					link.l1 = "Грязной?";
					link.l1.go = "Disease_Dirty";
				break;
				case "Chill":
					dialog.text = LinkRandPhrase("Смею вас заверить - жить будете.", "Сущие пустяки. Ничего опасного.", "Частые ветра и сырость дают о себе знать. Эта болезнь пустяковая.");
					link.l1 = "А что у меня?";
					link.l1.go = "Disease_Chill";
				break;
				case "Plague":
					dialog.text = LinkRandPhrase("Бог мой! У меня плохие новости.", "Нет. Я надеялся, что мы избавились от неё...", "У меня для вас плохие новости.");
					link.l1 = "В чём дело?";
					link.l1.go = "Disease_Plague";
				break;
				case "Fester":
					dialog.text = LinkRandPhrase("Капитан, за собой нужно следить! У вас режущие ранения в руку и в бок. Похоже, в последней драке вы были неосторожны.", "Я вижу колотую рану... причина ваших недомоганий только в ней.", "Всё ясно. Пару боевых ран и ссадин.");
					link.l1 = "А конкретнее можно?";
					link.l1.go = "Disease_Fester";
				break;
			}}
		break;


		case "Disease_Chesotka":
			dialog.text = "Нет. Вовсе нет. Чесотка достаточно распространённая болезнь и от неё никто пока не умирал.";
			link.l1 = "Вы умеете утешать.";
			link.l1.go = "Disease_Chesotka_1";
		break;
		case "Disease_Chesotka_1":
			dialog.text = "А вы, "+GetAddress_Form(NPChar)+" Блейк, испугались? Напрасно. В лечении вам поможет серная мазь. Купить её сможете у меня и после применения, не сразу конечно, но через пару дней, вы забудете о своём недуге. Я вас уверяю.";
			link.l1 = "Спасибо за помощь. Конечно, я куплю её у вас.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Chesotka"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Спасибо вам, "+NPChar.name+" "+NPChar.lastname+", за помощь, но мне сейчас не до покупок.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_Lihoradka":
			dialog.text = "Рвота есть?";
			link.l1 = "Нет.";
			link.l1.go = "Disease_Lihoradka_1";
		break;
		case "Disease_Lihoradka_1":
			dialog.text = "Хм... Я думаю, что вы больны лихорадкой. По крайней мере, все симптомы указывают именно на это.";
			link.l1 = "Что вы мне можете посоветовать, доктор?";
			link.l1.go = "Disease_Lihoradka_2";
		break;
		case "Disease_Lihoradka_2":
			dialog.text = "Вам следует купить кору хинного дерева. Из неё сделайте порошок и принимайте во внутрь, запивая большим количеством воды. Болезнь оставит вас через пару дней.";
			link.l1 = "Спасибо за помощь. Конечно, я куплю её у вас.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Lihoradka"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Спасибо вам, "+NPChar.name+" "+NPChar.lastname+", за помощь, но мне сейчас не до покупок.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_YellowLihoradka":
			dialog.text = "Дело плохо, голуб" + GetSexPhrase("чик","ушка") + ". Боюсь, что вы заражены жёлтой лихорадкой.";
			link.l1 = "Это так серьёзно?";
			link.l1.go = "Disease_YellowLihoradka_1";
		break;
		case "Disease_YellowLihoradka_1":
			dialog.text = "Более чем. Если не принять срочные меры, то для вас это всё может закончиться весьма плачевно.";
			link.l1 = "Я готов" + GetSexPhrase("","а") + " на всё доктор... Я долж" + GetSexPhrase("ен","на") + " выжить, чёрт меня побери!";
			link.l1.go = "Disease_YellowLihoradka_2";
		break;
		case "Disease_YellowLihoradka_2":
			dialog.text = "Успокойтесь. Вам нужна срочная госпитализация. Строгий постельный режим и молитва - вот, что может спасти вас. Обращение к Господу нашему, искренность молитв может спасти вас, но уход потребует некоторых затрат...";
			link.l1 = "Сколько?";
			link.l1.go = "Disease_YellowLihoradka_3";
		break;










		case "Disease_YellowLihoradka_3_1":
			dialog.text = "Вы принесли плату за лечение?";
			link.l1 = "Вот деньги.";
			link.l1.go = "Disease_YellowLihoradka_4"; 
		break;










		case "Disease_YellowLihoradka_4_0":
		dialog.text = NPCharSexPhrase(npchar, "Вот и закончилась ваша госпитализация, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?", "Вот и закончилась ваша госпитализация, " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?");
			link.l1 = "Намного лучше. Спасибо за лечение. Если бы не вы, то возможно всё закончилось для меня куда печальнее.";
			link.l1.go = "Disease_YellowLihoradka_4_1";			
		break;
		case "Disease_YellowLihoradka_4_1":
			dialog.text = "Не стоит. Это ведь моя работа. Желаю вам здоровья, более не болейте.";
			link.l1 = "Надеюсь на это. Прощайте.";
			link.l1.go = "Disease_YellowLihoradka_exit";
		break;

		case "Disease_YellowLihoradka_exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();

			npchar.dialog2.Year = GetAddingDataYear(0, 0, 2);
			npchar.dialog2.Month = GetAddingDataMonth(0, 0, 2);
			npchar.dialog2.Day = GetAddingDataDay(0, 0, 2);

			Lai_Fade("ExitFromChurch1","");
		break;

		case "Disease_YellowLihoradka_5":
			dialog.text = "У вас нет нужной суммы.";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "YellowLihoradka"){disease = disease1;}
				link.l1 = MiscDisease(disease,disease1,"4");
				link.l1.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l2 = "Не беспокойтесь. Я найду деньги.";
			link.l2.go = "Dialog_exit";
		break;

		case "Disease_Dirty":
			dialog.text = "Именно. Бордель никогда не имел хорошей репутации в народе. Этого стоило ожидать.";
			link.l1 = "Что же мне делать?";
			link.l1.go = "Disease_Dirty_1";
		break;
		case "Disease_Dirty_1":
			dialog.text = "У меня имеется жидкая мазь, которая может ослабить действие этой болезни.";
			link.l1 = "Ослабить, но не вылечить?";
			link.l1.go = "Disease_Dirty_2";
		break;
		case "Disease_Dirty_2":
			dialog.text = "Именно так и есть, ибо грех разрушает вашу плоть. Грех - причина всего. Очищение души и обращение к Господу Богу - вот, что действительно может спасти вас. Медицина здесь бессильна.";
			link.l1 = "Спасибо за помощь. Я хочу купить у вас эту мазь.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Dirty"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Спасибо "+NPChar.name+" "+NPChar.lastname+". Я подумаю над этим. Прощайте.";
			link.l3.go = "Dialog_exit";
		break;


		case "Disease_Chill":
			dialog.text = "Это обычная простуда. Если будете избегать сквозняков и всегда переодеваться в сухую одежду, то она пройдёт сама. Не сразу конечно, но через недельку вам станет легче.";
			link.l1 = "Целую неделю... А есть ли какой более быстрый способ поправиться?";
			link.l1.go = "Disease_Chill_1";
		break;
		case "Disease_Chill_1":
			dialog.text = "Безусловно. Вам поможет моя травяная настойка. С её помощью дня через два вы уже будете здоровы.";
			link.l1 = "Очень хорошо. Я непременно куплю её у вас.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Chill"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Благодарю за обследование. Вы хороший врач, но мне пора идти. Прощайте.";
			link.l3.go = "Dialog_exit";
		break;

		case "Disease_Plague":
			dialog.text = "Вы... вы заражены чумой - самой страшной болезнью, которую мне когда-либо доводилось видеть.";
			link.l1 = "Ведь... я же не умру? Скажите, доктор, есть же шанс?";
			link.l1.go = "Disease_Plague_1";
		break;
		case "Disease_Plague_1":
			dialog.text = "Не знаю. С чумой невозможно что-либо прогнозировать, но шанс у вас есть.";
			link.l1 = "Какой? Что мне следует предпринять?";
			link.l1.go = "Disease_Plague_2";
		break;
		case "Disease_Plague_2":
			dialog.text = "Я веду исследования в лечении данной болезни. Известные мне медицинские методы не дают гарантии на полное выздоровление...";
			link.l1 = "Не томите душу.";
			link.l1.go = "Disease_Plague_3";
		break;
		case "Disease_Plague_3":
			dialog.text = "Хорошо, хорошо. У меня есть эликсир под названием чумная настойка. Он может ослабить воздействие чумы на организм, но полного излечения я не гарантирую. Остаётся уповать только на церковь. Очищение души и покаяние перед Богом, возможно, принесут вам излечение, но я вам это не гарантирую.";
			link.l1 = "Я хочу купить эту настойку.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Plague"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Я понял" + GetSexPhrase("","а") + ", благодарю вас. Прощайте.";
			link.l3.go = "Dialog_exit";
		break;



		case "Disease_Fester":
			dialog.text = "А конкретно -  у вас нагноение. Разве вы не знаете, что любые порезы нужно всегда обрабатывать? Тем более боевые раны от шпаги противника... ещё неизвестно в каком она была состоянии.";
			link.l1 = "Вы же поможете мне, доктор?";
			link.l1.go = "Disease_Fester_1";
		break;
		case "Disease_Fester_1":
			dialog.text = "Конечно - это моя работа. Для излечения хорошо подойдёт жидкая мазь, применяемая при обработке ран. Промойте порез холодной водой и смажьте его мазью. Если вы будете следить за собой, то дня через два ранение начнёт заживать.";
			link.l1 = "Я хочу купить эту мазь.";
			link.l1.go = "Dialog_trade";
			if((disease != "") && (disease1 != ""))
			{
				if(disease == "Fester"){disease = disease1;}
				link.l2 = MiscDisease(disease,disease1,"4");
				link.l2.go = MiscDisease(disease,disease1,"4go");
			}			
			link.l3 = "Я понял" + GetSexPhrase("","а") + ", благодарю вас. Прощайте.";
			link.l3.go = "Dialog_exit";
		break;











		case "Dialog_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Dialog_trade":									
            if (CheckNPCQuestDate(npchar, "Item_date"))
			{
				SetNPCQuestDate(npchar, "Item_date");
				GiveItemToTrader(npchar);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(npchar, 0);
		break;




		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
