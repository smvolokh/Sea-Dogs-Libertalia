// boal Диалог с историком

void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
dialog.text = "Приветствую. Меня зовут Хосе де Акосто. С кем имею честь разговаривать?";
        		link.l1 = "Меня зовут " + GetFullName(pchar) + ".";
        		link.l1.go = "Step_1";
			break;
case "Step":
dialog.text = "Я учёный и занимаюсь исследовательской и научной работой... И я очень, очень не люблю, когда люди, которых я не знаю, беспокоят меня.";
        		link.l1 = "Понял" + GetSexPhrase("","а") + ", уже ухожу...";
        		link.l1.go = "exit_2";
if (pchar.questTemp.Ascold == "Seek_powder" && NPChar.id == "Historic")
			{
			dialog.text = "Я учёный и занимаюсь исследовательской и научной работой... И я очень, очень не люблю, когда люди, которых я не знаю, беспокоят меня.";
			link.l1 = "Я прекрасно Вас понимаю, поэтому прошу прощения за беспокойство. Но я пришёл к Вам по очень важному вопросу!";
			link.l1.go = "mummy";
			}
        		link.l2 = "Хамить изволите, сударь?";
        		link.l2.go = "Step_3";
		break;

 		case "Step_1":
        	dialog.text = "Кто Вы и чем Вы занимаетесь?";
    		link.l1 = "Я - вольный капитан.";
    		link.l1.go = "Step_2";
		break;

 		case "Step_2":
        	dialog.text = "Послушайте, капитан...";
    		link.l1 = "Да?";
    		link.l1.go = "Step";
		break;

 		case "Step_3":
dialog.text = RandPhraseSimple("Грозный и злой капитан изволит хулиганить? Что ж... Будем принимать меры...", "Грозный и злой капитан изволит хулиганить? Что ж... Будем принимать меры...");
        		link.l1 = RandPhraseSimple("Да я тебя сейчас...", "Да я тебя сейчас...");
            link.l1.go = "Step_4";
		break;

 		case "Step_4":
            DoReloadCharacterToLocation("VillaAlegria_town2", "reload", "houseF5");
           NextDiag.CurrentNode = "Step";
		DialogExit();
		break;

		case "mummy":
        	dialog.text = "Внимательно слушаю Вас.";
    		link.l1 = "Вопрос касается порошка египетской мумии...";
    		link.l1.go = "mummy_1";
		break;

case "mummy_1":
        	dialog.text = "Очень интресный вопрос, а я тут причём, простите? Наверное Вам к индейским шаманам нужно или колдунам, как их там называют...";
    		link.l1 = "Так, где же их найдёшь? Никто ничего не знает, или знает, да не говорит.";
    		link.l1.go = "mummy_2";
		break;

		case "mummy_2":
        	dialog.text = "То-то и оно... И не скажет никто. Инквизиция за куда меньшие пригрешения со свету сжить может. А уж за такое и подавно. Кому ж охота за свой длинный язык жизнью платить?";
    		link.l1 = "Н-да... а может, подскажите чего? Очень нужно. Один человек заказ сделал, а я вот уже сколько времени найти не могу.";
    		link.l1.go = "mummy_3";
		break;

case "mummy_3":
        	dialog.text = "Заказ, говорите? А не инквизиторская ли ищейка Ваш заказчик?";
    		link.l1 = "Да нет, не похоже... Солидный продавец солидного магазина. Это хозяин магазина, что находится на Мэйне в поселении близ рудника Лос Текес... Его зовут... ";
    		link.l1.go = "mummy_4";
		break;

case "mummy_4":
        	dialog.text = "Можете не продолжать. Я понял о ком Вы говорите. Что ж, продам я Вам порошок. Только не вздумайте сболтнуть кому-то. Учтите, что я Вас знать не знаю и на страшном суде отпираться буду.";
    		link.l1 = "Ну, это и так понятно...";
    		link.l1.go = "mummy_5";
		break;

case "mummy_5":
        	dialog.text = "Хорошо. С Вас тысяча песо.";
			if (sti(pchar.money) >= 1000)
			{
				Link.l1 = "Недёшево, однако, но тут и не поторгуешься. Вот, держите.";
    		    Link.l1.go = "mummy_6";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");			
			}
			else
			{
				link.l1 = "Вот чёрт! у меня с собой нет столько. Сейчас соберу и сразу к Вам. Не продавайте, пожалуйста, пока я бегать буду...";
				link.l1.go = "Exit_3";
			}
		break;

		case "mummy_1488":
        	dialog.text = "Хорошо, напоминаю, что с Вас тысяча песо.";
			if (sti(pchar.money) >= 1000)
			{
				Link.l1 = "Недёшево, однако, но тут и не поторгуешься. Вот, держите.";
    		    Link.l1.go = "mummy_6";
    		    pchar.questTemp.Ascold = "PowderWasSeek";
    		    AddMoneyToCharacter(pchar, -1000);
    		    GiveItem2Character(Pchar,"Powder_mummie");
	
			}
			else
			{
				link.l1 = "Вот чёрт! у меня с собой нет столько. Сейчас соберу и сразу к Вам. Не продавайте, пожалуйста, пока я бегать буду...";
				link.l1.go = "Exit_3";
			}
		break;

		case "mummy_6":
        	dialog.text = "Если это всё, то прошу Вас не более отвлекать меня. До свидания.";
    		link.l1 = "До свидания... И спасибо Вам, сеньор де Акоста!";
    		link.l1.go = "Exit_2";
AddQuestRecord("Ascold", "1488");
		break;


		case "mummy_228":
        	dialog.text = "Внимательно слушаю Вас, сударь.";
    		link.l1 = "Я по поводу порошка мумии.";
    		link.l1.go = "mummy_1488";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_3":
			NextDiag.CurrentNode = "mummy_228";
			DialogExit();
		break;


		case "Exit_2":
			NextDiag.CurrentNode = "Step";
			DialogExit();
		break;

	}
}
