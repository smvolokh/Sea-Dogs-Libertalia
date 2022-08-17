
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Не о чем говорить.";
			link.l1 = "Ладно...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		//отстраненные от службы испанские мушкетеры

		case "Lostpirate":
			dialog.text = "Приветствую вас, похоже вы капитан не так ли?";
			link.l1 = "Да, действительно я капитан меня зовут капитан " + GetFullName(pchar) + ".";
			link.l1.go = "OffMspa_1";
		break;
		case "OffMspa_1":
			dialog.text = "О простите, позвольте представиться я Рафаэль Идальго, рад знакомству, капитан. Чем я вам обязан?";  
 
			link.l1 = "Да так, ничем особенным... А вы по виду человек военный. Еще на службе состоите?";
			link.l1.go = "OffMspa_2";
		break;
		case "OffMspa_2":
			dialog.text = "Уже нет, уволен.";
			link.l1 = "Понятно. А кем были в армии?";
			link.l1.go = "OffMspa_3";
		break;
		case "OffMspa_3":
			dialog.text = "Мушкетером. Я и мой напарник были лучшими корабельными стрелками во флоте!";
			link.l1 = "Тогда почему же вас уволили?";
			link.l1.go = "OffMspa_4_1";
		break;

		case "OffMspa_4_1":
			dialog.text = "Ну во-первых эта долгая история, а во-вторых не уволили а сняли со службы!";
			link.l1 = "Что же так, за неуставные отношения, может расскажите у меня время есть?";
			link.l1.go = "OffMspa_4_2";
		break;

		case "OffMspa_4_2":
			dialog.text = "Э нет как раз с этим все строго, ладно слушайте. По приказу адмиралтейства нас направили для усиления торгового каравана из Гаваны в Белиз, пару дней хода по ветру и мы были бы на месте, но не тут то было, ночью нас атаковали английские корабли, завязался бой, мы потерпели поражение и не смогли отстоять свои позиции\n На рассвете от всего увиденного волосы дыбом встали, оказалось что я и мой напарник остались в  живых и дальнейшее сопротивление было бесполезным, корабль захватили  англичане и были удивлены нашим мужеством, и поэтому нас раненных положили в шлюп и отправили на все четыре стороны\n Через трое суток нас прибило к берегам мэйна и мы сошли на берег, и по джунглям через пару дней мы доползли кое как до Белиза. Первым же делом с докладом к губернатору о случившимся происшествие, губернатор пришел в ярость, кто бы мог подумать что мы сопровождали галеон набитый золотом и нас взяли под стражу для выяснения всех обстоятельств\n Дальше самое интересное, нас обвинили в трусости и измене чуть ли не приговорили к смертной казни, благодаря нашим заслугам адмиралтейство настояла на смягчении приговора, ну и сняли со службы, лишили всех наград и отправили на вольные хлеба, вот такая история.";
			link.l1 = "А заслуг то много имел?";
			link.l1.go = "OffMspa_4_3";
		break;

		case "OffMspa_4_3":
			dialog.text = "Много!";
			link.l1 = "Похоже что так, раз избежал смертной казни. А что с напарником?";
			link.l1.go = "OffMspa_4_4";
		break;

		case "OffMspa_4_4":
			dialog.text = "Мы с ним после этого случая расстались, я в Сент.-Луи а он в Вилья Алегрию!";
			link.l1 = "Значит на вольных хлебах?";
			link.l1.go = "OffMspa_4_5";
		break;

		case "OffMspa_4_5":
			dialog.text = "Так точно на вольных!";
			link.l1 = "А ко мне пойдешь, старое былое вспомнишь?";
			link.l1.go = "OffMspa_5";
		break;

		case "OffMspa_5":
			dialog.text = "Служить государству нет ни малейшего желания а вот вольному капитану я готов. Только давайте обсудим размер моего гонорара. За свою верную службу, думаю, мы с вами сойдемся на 30000 пиастров.";
			link.l1 = "А вам не кажется, что это чересчур?";
			link.l1.go = "OffMspa_trade";
			link.l1 = "Ну, хорошо, я соглас" + GetSexPhrase("ен","на") + ".";
			link.l1.go = "OffMspa_Ok";

		break;
		case "OffMspa_trade":
			dialog.text = "Нет, я стою гораздо больше.";
			link.l1 = "Ну, хорошо, я соглас" + GetSexPhrase("ен","на") + ".";
			link.l1.go = "OffMspa_Ok";
		break;
		case "OffMspa_Ok":
			Npchar.quest.OfficerPrice.add = sti(pchar.rank)*1000;
			dialog.text = "Хорошо. Но это еще не все. Я требую единовременного пособия, так сказать. Поиздержался без работы, вот и надо оплатить долги. Думаю, что " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " меня устроят.";
			link.l1 = "Чего?!!";
			link.l1.go = "OffMspa_Ok_1";
		break;
		case "OffMspa_Ok_1":
			dialog.text = "Того! И никак иначе... В общем, решайте.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "Нет у меня таких денег.";
				link.l1.go = "OffMspa_noMoney";
			}
			else
			{
				link.l1 = "Это очень дорого для меня.";
				link.l1.go = "OffMspa_noMoney";
				link.l2 = "Хорошо, я соглас" + GetSexPhrase("ен","на") + ".";
				link.l2.go = "OffMspa_Ok_3";
			}
			NextDiag.TempNode = "OffMspa_TWO";
		break;
		case "OffMspa_noMoney":
			dialog.text = "Значит, приходите, как разбогатеете. Удачи.";
			link.l1 = "Спасибо...";
			link.l1.go = "exit";
		break;
		case "OffMspa_Ok_3":
			AddMoneyToCharacter(Pchar, -30000);
			dialog.text = "Вот, теперь совсем другое дело! Я готов вам служить верой и правдой.";
			link.l1 = "Отлично. Добро пожаловать в команду.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			AddQuestRecord("TwooDoubleMushket_1", "1");
			CloseQuestHeader("TwooDoubleMushket_1");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "quest_mush_1";
			npchar.model.animation = "mushketer";
			npchar.MusketerDistance = 5;
			npchar.greeting = "Gr_questOfficer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);			
			npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();
		break;
		case "OffMspa_TWO":
			dialog.text = "Ну что, как там у вас дела с финансами? Напомню, что я хочу " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " единовременного пособия и " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " ежемесячного заработка.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "Нет, не потяну пока...";
				link.l1.go = "OffMspa_noMoney";
			}
			else
			{
				link.l1 = "Это очень дорого для меня.";
				link.l1.go = "OffMspa_noMoney";
				link.l2 = "Хорошо, я соглас" + GetSexPhrase("ен","на") + ".";
				link.l2.go = "OffMspa_Ok_3";
			}
			NextDiag.TempNode = "OffMspa_TWO";
		break;






	}
}











