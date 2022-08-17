// Слухи - диалог по типажам

#define MAX_RUMOURS_ABOUT_OWNERS 7

void ProcessCommonDialogRumors(ref NPChar, aref Link, aref NextDiag);
{
    string strum;
    string srum;
	switch(Dialog.CurrentNode)
	{
/////////////////////////////////////////////////---слухи мещанок---////////////////////////////////////////////
		case "rumours_towngirl":
    PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");		
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("towngirl", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        string posrep1, posrep2, answ1, answ2, answ3, answ4;
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Возможно, вас это позабавит.");
            posrep2 = " А у вас, капитан, есть какие-нибудь известия для нашей колонии?";
            answ1 = RandPhraseSimple(RandSwear() + "Интересные вещи ты рассказываешь, "+GetFullName(NPChar)+".",
                                 "Тогда расскажи мне еще...");
            answ2 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще вопрос.");
            answ3 = RandPhraseSimple("Чего только не случается на свете. Мне жаль, но никаких новостей у меня нет. ","Я немного спешу, так что как-нибудь в другой раз.");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("К сожалению, больше я ничего не знаю, позвольте мне идти.","Вы утомили меня своими расспросами, прошу меня простить, но меня ждут дела."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
                                            answ2,
                                            answ3,
                                            answ4,
                                            npchar, Dialog.CurrentNode);
		link.l1.go = "new question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";
	break;

/////////////////////////////////////////////////---слухи мещан---////////////////////////////////////////////
	case "rumours_townman":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("townman", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Возможно, вас это позабавит.");
            posrep2 = " А у вас, капитан, есть какие-нибудь известия для нашей колонии?";
            answ1 = RandPhraseSimple(RandSwear() + "Интересные вещи ты рассказываешь, "+GetFullName(NPChar)+".",
"Тогда расскажи мне еще...");
            answ2 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще вопрос.");
            answ3 = RandPhraseSimple("Чего только не случается на свете. Мне жаль, но никаких новостей у меня нет. ","Я немного спешу, так что как-нибудь в другой раз.");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("К сожалению, больше я ничего не знаю, позвольте мне идти.","Вы утомили меня своими расспросами, прошу меня простить, но меня ждут дела."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "new question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";

//жемчужный генератор Шарпа
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.Sharp.City == npchar.city && sti(pchar.questTemp.Sharp.City.rumour))
		{
			pchar.questTemp.Sharp.City.rumour = false; //слух дан
			Dialog.Text = Sharp_choiceAction();
			link.l1 = "Гм, понятно... Еще что нового?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
									"Всего хорошего.");
			link.l2.go = "exit";
			
		}
	break;
	
	///////////////////////////////////---слухи темных личностей---////////////////////////////////////////////
	case "rumours_marginal":	
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2 )
        srum = SelectRumourEx("townman", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Возможно, вас это позабавит.");
            posrep2 = " А у вас, капитан, есть какие-нибудь известия для нашей колонии?";
            answ1 = RandPhraseSimple(RandSwear() + "Интересные вещи ты рассказываешь, "+GetFullName(NPChar)+".",
"Тогда расскажи мне еще...");
            answ2 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще вопрос.");
            answ3 = RandPhraseSimple("Чего только не случается на свете. Мне жаль, но никаких новостей у меня нет. ","Я немного спешу, так что как-нибудь в другой раз.");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("К сожалению, больше я ничего не знаю, позвольте мне идти.","Вы утомили меня своими расспросами, прошу меня простить, но меня ждут дела."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";
	break;
	
/////////////////////////////////////////////////---слухи дворян---////////////////////////////////////////////
	case "rumours_nobleman":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
        srum = SelectRumourEx("nobleman", NPChar);
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Так вот.");
            posrep2 = " Да, и это всё. Мне больше нечего добавить к сказанному.";
            answ1 = RandPhraseSimple("Интересные вещи вы рассказываете, сударь! Но может, позволите еще вопрос...",
"Разрешите еще вопрос...");
            answ2 = RandPhraseSimple("Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще один вопрос, пожалуйста.");
            answ3 = RandPhraseSimple("Чего только не случается на свете! Можно еще спросить...","Благодарю вас, сударь. Но может, вы еще знаете...");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("Я, кажется, понятно выразился - у меня всё.","Вы утомили меня своими расспросами, капитан. Идите, займитесь делом, наконец!"),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";
	break;
	
/////////////////////////////////////////////////---слухи дворянок---////////////////////////////////////////////
	case "rumours_noblegirl":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");		
        srum = SelectRumourEx("noblegirl", NPChar);
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Возможно, вас это позабавит.");
            posrep2 = " Да, и это всё. Мне больше нечего добавить к сказанному.";
            answ1 = RandPhraseSimple("Интересные вещи вы рассказываете, сударыня! Но может, позволите еще вопрос...", "Разрешите еще вопрос...");
            answ2 = RandPhraseSimple("Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще один вопрос, пожалуйста.");
            answ3 = RandPhraseSimple("Чего только не случается на свете! Можно еще спросить...","Благодарю вас, сударыня. Но может, вы еще знаете...");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("Я, кажется, понятно выразилась - у меня всё.","Вы утомили меня своими расспросами, капитан. Идите, займитесь делом, наконец!"),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";
	break;
	
	///////////////////////////////////////////---слухи матросов---////////////////////////////////////////////
	case "rumours_sailor":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2) srum = SelectRumourEx("sailor", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", " Возможно, вас это позабавит.");
            posrep2 = " А у вас, капитан, есть какие-нибудь известия для нашей колонии?";
            answ1 = RandPhraseSimple(RandSwear() + "Интересные вещи ты рассказываешь, "+GetFullName(NPChar)+".",
"Тогда расскажи мне еще...");
            answ2 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще вопрос.");
            answ3 = RandPhraseSimple("Чего только не случается на свете. Мне жаль, но никаких новостей у меня нет. ","Я немного спешу, так что как-нибудь в другой раз.");
            answ4 = "";
        }
        else
        {
            posrep1 = " У нас вообще редко что-либо происходит. Но если же произойдет что-то необычное, то все об этом только и говорят.";
            posrep2 = " Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажи-ка мне лучше...",RandSwear() + "Ты ничего не знаешь! Ладно, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Говоришь, не знаешь, ладно, скажи мне тогда...","Да, не сильно ты мне помог"+NPCharSexPhrase(NPChar, "","ла")+", но, может, ты знаешь что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("К сожалению, больше я ничего не знаю, позвольте мне идти.","Вы утомили меня своими расспросами, прошу меня простить, но меня ждут дела."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";
	break;
///////////////////////////////////////////---слухи ПГГ ---////////////////////////////////////////////
	case "rumours_pgg":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");	
		NextDiag.CurrentNode = "rumours";

		if (!CheckAttribute(NPChar, "quest.repeat.rumours_citizen") || NPChar.quest.repeat.rumours_citizen != 2) srum = SelectRumourEx("PGGG", NPChar);
        else srum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
        if (RumourHasInformation(srum))
        {
            posrep1 = RandPhraseSimple(" Такие вот дела...", "Возможно, вас это позабавит.");
            posrep2 = "Может Вы расскажете что-нибудь интересное, капитан?";
            answ1 = RandPhraseSimple(RandSwear() + "Интересные вещи Вы рассказываете, "+GetFullName(NPChar)+".",
"Тогда расскажите мне еще...");
            answ2 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...","Еще вопрос.");
            answ3 = RandPhraseSimple("Чего только не случается на свете. Не думаю, что могу рассказать что-то что, могло бы вас заинтересовать, капитан.","Я немного спешу, так что как-нибудь в другой раз.");
            answ4 = "";
        }
        else
        {
            posrep1 = "Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            posrep2 = "Так что новостей никаких. Но может " + GetAddress_Form(NPChar) + " капитан что-то знает?";
            answ1 = RandPhraseSimple("Тогда расскажите мне лучше...",RandSwear() + "Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
            answ2 = RandPhraseSimple("Скажите мне тогда...","Может, Вы знаете что-то еще?");
            answ3 = RandPhraseSimple("Не думаю, что знаю что-то что, могло бы вас заинтересовать.","Я с удовольствием что-нибудь расскажу, но как-нибудь в другой раз.");
            answ4 = "";
        }
		Dialog.Text = NPCStringReactionRepeat(srum,
            srum+posrep1,
            srum+posrep2,
            RandPhraseSimple("К сожалению, больше я ничего не знаю, позвольте мне отдохнуть.","Вы утомили меня своими расспросами, прошу меня простить. Давайте сменим тему."),"block", 1, npchar, Dialog.CurrentNode);
        link.l1 = HeroStringReactionRepeat(answ1,
            answ2,
            answ3,
            answ4,
            npchar, Dialog.CurrentNode);
		link.l1.go = "question";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.","Всего хорошего.");
		link.l2.go = "exit";

	//жемчужный генератор Шарпа
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.Sharp.City == npchar.city && sti(pchar.questTemp.Sharp.City.rumour))
		{
			pchar.questTemp.Sharp.City.rumour = false; //слух дан
			Dialog.Text = Sharp_choiceAction();
			link.l1 = "Гм, понятно... Еще что нового?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
									"Всего хорошего.");
			link.l2.go = "exit";
			
		}
	break;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case "rumours_habitue":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
		Dialog.Text = LinkRandPhrase("Ну... И-ик! ","Эх, какой ром! ","Н-да... ")+SelectRumourEx("habitue", NPChar);
		link.l1 = RandPhraseSimple(RandSwear() + "За это надо выпить еще кружечку...",
                                 "Хорошо. Давай еще по одной.");
		link.l1.go = "sit_3";
		link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
                                 "Эх, забористый ром. Ладно, мне уже пора, удачно посидеть.");
		link.l2.go = "exit_sit";

		if (pchar.questTemp.piratesLine == "PL5Hunter_toFirst" && npchar.location == pchar.questTemp.piratesLine.Q5.city_1 + "_tavern")
		{
			dialog.text = "Представляешь, сижу никого не трогаю, вдруг, подлетает этот Эйвори и не спросясь – хрясь мне в морду! Ты, говорит, барыге денег должен?! А потом говорит - обознался. Он обознался, а я без зуба остался! А! Каково?! И, не поверишь, неделя уж прошла, а до сих пор болит. Такая боль! Может, по кружке эля?..";
			link.l1 = "Ну, это можно...";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "3");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_1 + "Gen"));
			pchar.questTemp.piratesLine = "PL5Hunter_toFirstUsurer";
		}
		if (pchar.questTemp.piratesLine == "PL5Hunter_toSecond" && npchar.location == pchar.questTemp.piratesLine.Q5.city_2 + "_tavern")
		{
			dialog.text = "Подсел ко мне, дней пять назад, мужик, вот прям как ты сейчас. Звали его, дай бог памяти... Джон Эйвори. Рассказал, как он надул местного ростовщика, хе-хе-хе. Так ему и надо, кровососу проклятому, сидит на деньгах и пухнет, а работному человеку и закусить-то нечем...";
			link.l1 = "Да уж, эти ростовщики - народ поганый.";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "5");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_2 + "Gen"));
			pchar.questTemp.piratesLine = "PL5Hunter_toSecondUsurer";
		}
		if (pchar.questTemp.piratesLine == "PL5Hunter_toThird" && npchar.location == pchar.questTemp.piratesLine.Q5.city_3 + "_tavern")
		{
			dialog.text = "Три дня назад тут такая драка была! Джон Эйвори шулера подколол. Знатно, надо сказать, дядька железякой машет. Вжик, вжик! И нету шулера. Крик поднялся, гам. Но Джон - мужик правильный, всем в таверне выпивку поставил. Уважаю!";
			link.l1 = "О как! Круто...";
			link.l1.go = "sit_3";
			AddQuestRecord("Pir_Line_5_Hunter", "7");
			AddQuestUserData("Pir_Line_5_Hunter", "sCity", XI_ConvertString("Colony" + pchar.questTemp.piratesLine.Q5.city_3 + "Gen"));
			pchar.questTemp.piratesLine = "PPL5Hunter_toThirdUsurer";
		}

		//ОЗГ, Крыса
		if (pchar.questTemp.Headhunter == "Rat_Tavern" && npchar.location == pchar.questTemp.Headhunter.Ratrumcity + "_tavern")
        {
			dialog.text = "(поет) Летучий Голландец, Летучий Голландец, мчит по неведомым морям... Эх, моря"+ GetSexPhrase("к","чка") +", выпьем!";
            link.l1 = "Послушай, мне говорили, что тут матросы с одного судна, 'Аделаида' называется, устроили погром по пьяни...";
            link.l1.go = "Rat_Tavern_1";
        }
		//<--ОЗГ, Крыса

		//Месть корсара
		if (CheckAttribute(pchar, "questTemp.GothicRevengeCorsair") && pchar.questTemp.GothicRevengeCorsair == "RevengeCorsair_Tavern" && npchar.location == "LaVega_tavern")
        {
			dialog.text = "(поет) Летучий Голландец, Летучий Голландец, мчит по неведомым морям... Эх, моря"+ GetSexPhrase("к","чка") +", выпьем!";
            link.l1 = "Угощайся, приятель! Ну, и как там в море, что интересного видел, слышал, рассказывай а то шланги горят?";
            link.l1.go = "RevengeCorsair_Tavern_1";
        }
		//<--Месть корсара

		if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskAlcash") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	    {
			dialog.text = "Эх, " + GetAddress_Form(pchar) + " что за жизнь нынче пошла... Ничего святого в людишках не осталось!";
			link.l1 = "О чём это ты, приятель?";
			link.l1.go = "Alcogol_GenQuest_Church_2_1";
		}

		//-->работорговец
		if (pchar.questTemp.Slavetrader == "FindRatJamaica_H" && npchar.location == "FortOrange_tavern")
        {
			dialog.text = "(поет) Однажды мне встре-етился гамбургский шип. На мачтах - мокрицы и пле-есенный гриб, обшивка гнила-ая, в ракушках корма. Клопов полон ку-убрик, а камбуз - дерьма... Как жизнь, моря"+ GetSexPhrase("к","чка") +", рассказывай. Как оно там, в море?";
            link.l1 = "Да в море все так же, как и всегда - сыро и солоно. Ты вот скажи лучше, не знаешь ли, куда ушел мой приятель, который тут комнату снимал недавно? Франсуа Гонтьер его зовут.";
            link.l1.go = "Jamaica_ratH_1";
        }
		if (pchar.questTemp.Slavetrader == "EscapeSlaveVillemstad_H" && npchar.location == "Villemstad_tavern")
        {
			dialog.text = "(поет) Я бла-агода-арен виски за свой багро-овый нос, и по-о его-о совету пальто в закла-ад отнес... Эх, наливай, моря"+ GetSexPhrase("к","чка") +"! Я только вчера из рейса, поэтому еще немного не в себе.";
            link.l1 = "Угощайся, приятель! Ну, и как там в море, что интересного видел?";
            link.l1.go = "EscapeSlave_Villemstad_H1";
        }
		//<--работорговец
				
		//Голландский Гамбит, против всех
		if (CheckAttribute(pchar, "questTemp.HWIC.Self") && pchar.questTemp.HWIC.Self == "LetterToLucasSent" && npchar.location == "Villemstad_tavern")
        {
			dialog.text = "Эх, море, море... Как бы я хотел быть на вашем месте!";
            link.l1 = "Ну так в чем проблема, дружище? Айда ко мне матросом на корабль.";
            link.l1.go = "Lucas_Tavern";
        }
		//Голландский Гамбит
		
		//--> поиск дезертира
		if (CheckAttribute(pchar, "GenQuest.FindFugitive") && sti(NPChar.nation) == PIRATE && !CheckAttribute(npchar, "quest.fugitive"))
        {
			dialog.text = LinkRandPhrase("Выпей рому, посмелей, сразу будет сто друзей! Ха-ха!","Опрокинешь добрую кружку - и тюремщик покажется душкой! Ха-ха!","Ром и эль покажут рай - наливай, да выпивай! Ха-ха!");
            link.l1 = "Выпьем, выпьем, дружище... Скажи-ка мне, любезный, не появлялся ли в вашем поселке человек по имени "+pchar.GenQuest.FindFugitive.Name+"? Он - мой бывший сослуживец. Добрые люди сказали, что он направил свои стопы именно сюда...";
            link.l1.go = "FindFugitiveHb";
        }
		//<-- поиск дезертира
		
		// карибские нравы
		if (CheckAttribute(pchar, "questTemp.Trial") && pchar.questTemp.Trial == "spy" && npchar.location == "Portobello_tavern")
		{
			dialog.text = "А какие тут у нас новости? И-ик! А разве ничего не слыхал? Изловила наша стража французского шпиона. Торговцем прикидывался, шельма, но... ик! - с нашим комендантом не забалуешь!";
            link.l1 = "Да ну! И что же этот лягушатник тут высматривал?";
            link.l1.go = "trial_spy";
		}
		if(CheckAttribute(PChar, "GenQuest.ChurchQuest_2.AskAlcash") && PChar.location == PChar.GenQuest.ChurchQuest_2.QuestTown + "_tavern")
	    {
			dialog.text = "Эх, " + GetAddress_Form(pchar) + " что за жизнь нынче пошла... Ничего святого в людишках не осталось!";
			link.l1 = "О чём это ты, приятель?";
			link.l1.go = "Alcogol_GenQuest_Church_2_1";
		}
		//квест брига Черная Горгулья
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.BlueBird.City == npchar.city && pchar.questTemp.BlueBird == "returnMoney")
		{
			Dialog.Text = BlueBurd_setTradeShip();
			link.l1 = "Ага, понятно... Что еще нового в городе?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
									"Всего хорошего.");
			link.l2.go = "exit";			
		}
	break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "rumours_trader":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
            if (!CheckAttribute(NPChar, "quest.repeat.rumours_trader") || NPChar.quest.repeat.rumours_trader!= 3 )
            strum = SelectRumourEx("trader", NPChar);
            else strum = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; // fix
			Dialog.Text =  NPCStringReactionRepeat(strum, strum+" Да. Больше ничего не припомню.",
                strum+" А сейчас мне нужно вернуться к делам.",RandPhraseSimple("Я ведь уже сказал, что у меня нет времени на пустую болтовню!","Я занятой человек и мне некогда обсуждать всякие сплетни!"),"block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(pcharrepphrase(RandSwear() + "Это очень интересно! Но давай к делу","Благодарю, тогда вот еще какое дело."), pcharrepphrase(""+ GetSexPhrase("Чтоб я сдох","Разрази меня гром") +"! Складно врешь. Но у меня есть еще вопрос.","Так не будем больше терять драгоценное время и перейдем к делам."),
pcharrepphrase(RandSwear() +" Еще одно дельце, и я уйду.","Вы правы, время - деньги."),pcharrepphrase("Только и думаешь, что о своей выгоде. Ладно, не кипятись.","Прошу простить меня. Перейдем к делу."),npchar, Dialog.CurrentNode);
			link.l1.go = "business";
			link.l2 = HeroStringReactionRepeat(NPCharRepPhrase(npchar,pcharrepphrase("Пока, старый пропойца.",
"Всего доброго, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"."),pcharrepphrase("Каррамба! Никуда не уходи. Я еще зайду.","Приятно было вас видеть, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"! До свидания!")),NPCharRepPhrase(npchar,pcharrepphrase("Отдать швартовы!","До свидания, милейший."),pcharrepphrase("Эй! Ты что там прячешь? Ром? Нет!?! Ну ладно, пойду горло промочу.","Прошу меня извинить, у меня срочные дела в городе.")),NPCharRepPhrase(npchar,pcharrepphrase("Хех! Еще увидимся!","Мне надо идти. Прощайте, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!"),pcharrepphrase("И не смей мне перечить! Недосуг мне тут с тобой спорить!","Пожалуй, стоит проверить, как дела на корабле. Прощайте, "+GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),NPCharRepPhrase(npchar,pcharrepphrase("Что с тобой, старина? Это же я - " +GetFullName(pchar)+ "! Проспись, я потом зайду.","Боюсь, ваша печень прикончит вас раньше, чем я еще раз зайду сюда."),pcharrepphrase("Считай свое серебро, пройдоха! Я еще зайду.","Рад"+ GetSexPhrase("","а") +" был"+ GetSexPhrase("","а") +" вас видеть, " + GetAddress_FormToNPC(NPChar)+" " +GetFullName(npchar)+"!")),npchar, Dialog.CurrentNode);
			link.l2.go = "Exit";
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_capitan":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			Dialog.Text = SelectRumourEx("capitan", NPChar);
			Link.l1 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...",
                                     "Еще вопрос.");
			Link.l1.go = "quests";
			Link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
                                     "Всего хорошего.");
			Link.l2.go = "exit";
			NextDiag.TempNode = "quests";
            NPChar.talk_date =  lastspeakdate();
		break;
		
		 case "rumours_landcaptain":
			Dialog.Text = SelectRumourEx("landcaptain", NPChar);
			Link.l1 = RandPhraseSimple(RandSwear() + "Это очень интересно! Вот что еще хотел"+ GetSexPhrase("","а") +" спросить...",
                                     "Еще вопрос.");
			Link.l1.go = "question";
			Link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
                                     "Всего хорошего.");
			Link.l2.go = "exit";
			NextDiag.TempNode = "question";
            NPChar.talk_date =  lastspeakdate();
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "rumours_tavern":  // homo 03/08/06
	                PlaySound("VOICE\Russian\GOTHIC\GG_TAVERN\GG_TAVERN_" + rand(22) + ".wav");

                 Dialog.Text = NPCStringReactionRepeat(LinkRandPhrase("Сведения стоят денег. За скромные 1000 песо я расскажу все, что знаю.",
                "Что-то я запамятовал. Но, возможно, 1000 монет освежат мою память.",
                "Я готов рассказать все, что знаю. Но не бесплатно - 1000 песо, на меньшее я не согласен."),
                "Больше мне нечего добавить. А теперь прошу меня извинить, но дела не ждут.",
                "", "", "block", 1, npchar, Dialog.CurrentNode);
             
    			link.l1 = HeroStringReactionRepeat(RandPhraseSimple(RandSwear() + "Платить за пустую болтовню? Нет уж, поищи кого-нибудь другого.",
                                         "За такие деньги я сам"+ GetSexPhrase("","а") +" все узнаю."), "Давай поговорим о чем-нибудь другом.", "Давай поговорим о чем-нибудь другом.", "Давай поговорим о чем-нибудь другом.", npchar, Dialog.CurrentNode);
                link.l1.go = HeroStringReactionRepeat("rumours_tavern_no", "first time", "first time", "first time", npchar, Dialog.CurrentNode);//"rumours_tavern_no";
                NextDiag.CurrentNode = NextDiag.TempNode;
    			if (makeint(pchar.money) >= 1000 )
    			{
    				link.l2 = HeroStringReactionRepeat(RandPhraseSimple("Ты их получишь, если я получу действительно ценные сведения.", "Я заплачу, но только при условии, что ты мне расскажешь действительно что-то важное."),
                     "", "", "" , npchar, Dialog.CurrentNode);
    				link.l2.go = HeroStringReactionRepeat("rumours_tavern_yes", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
    			}
    			else
    			{
                    link.l2 =  HeroStringReactionRepeat("У меня нет такой суммы.", "", "", "", npchar, Dialog.CurrentNode);
    				link.l2.go = HeroStringReactionRepeat("rumours_tavern_no", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
    			}

		break;
		
		// платные слухи таверны
		case "rumours_tavern_yes":

			//------------- квестовые слухи тавернщика --------->>>>>>>>

		//квест брига Черная Горгулья
		if(CheckAttribute(NPChar, "city") && pchar.questTemp.BlueBird.City == npchar.city && pchar.questTemp.BlueBird == "returnMoney")
		{
			Dialog.Text = BlueBurd_setTradeShip();
			link.l1 = "Ага, понятно... Что еще нового в городе?";
			link.l1.go = "new question";
			link.l2 = RandPhraseSimple("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
									"Всего хорошего.");
			link.l2.go = "exit";
			//новый слух в другом городе
			//pchar.questTemp.BlueBird.City = GetSharpCity();
			break;
		}

			//пиратка, квест №3
			if (pchar.questTemp.piratesLine == "KillLoy_toCumana")
			{
				Dialog.Text =  "В последнее время стали часто пропадать корабли, причем, что странно, пропадают только курьерские люггеры и шлюпы, небольшие корабли, в общем. Не выше 5-го класса. Поговаривают о появлении в водах Куманы какого-то брига... Так что будьте осторожны!";
				link.l1 = "Не выше 5-го класса, говоришь? Очень интересно... А больше ничего примечательного не знаешь?";
				link.l1.go = "rumours_tavern";
				AddQuestRecord("Pir_Line_3_KillLoy", "14");		
				AddQuestUserData("Pir_Line_3_KillLoy", "sSex", GetSexPhrase("","а"));		
				pchar.questTemp.piratesLine = "KillLoy_toCumana_2";
				break;
			}
			//ОЗГ, Крыса на Тортуге
			if (pchar.questTemp.Headhunter == "Rat_tortuga" && npchar.location == "Tortuga_tavern")
			{
				Dialog.Text =  "Говорят, капитан и собственник пинаса 'Аделаида' заключил какую-то сделку с губернатором и отчаливает буквально на днях. Вся его команда целую неделю без продыха безобразничала в борделе и у меня в таверне. Слава Богу, уберутся наконец, быстрее бы... А сам капитан сейчас у меня отдыхает - видишь, вон сидит, за круглым столиком. Видный моряк...";
				link.l1 = "Очень интересно... А больше ничего примечательного не знаешь?";
				link.l1.go = "rumours_tavern";
				pchar.quest.Headhunter_PinasseTortugaOver.over = "yes";
				AddQuestRecord("Headhunt", "17");
				CreateRatOfficer();	
				pchar.questTemp.Headhunter = "Rat_officer";
				FreeSitLocator("Tortuga_tavern", "sit1");
				SetFunctionTimerCondition("Headhunter_RatOfficerOver", 0, 0, 3, false);//таймер
				break;
			}
			//ОЗГ, Крыса на Тортуге
			//<<<<<-------- квестовые слухи тавернщика -----------------


			if (CheckAttribute(pchar, "questTemp.Saga.BarbTemptation"))
			{
				bool bOk = (pchar.questTemp.Saga.BarbTemptation == "silk") || (pchar.questTemp.Saga.BarbTemptation == "give_silk");
				if (bOk && npchar.location == "Marigo_tavern" && !CheckAttribute(npchar, "quest.barbtemptation"))
				{
					AddMoneyToCharacter(pchar, -1000);
					Dialog.Text =  "Недавно наш патруль потопил бригантину некого французского контрабандиста Мореля, а самого его взял в плен. Теперь этот Морель сидит каземате и дожидается суда. Комендант уверен, что на корабле был не весь груз контрабанды, и пытается вызнать это. А как только узнает - тут и конец французишке...";
					link.l1 = "Очень интересно... Хорошо, ты заслужил свои деньги - держи. А больше ничего примечательного не знаешь?";
					link.l1.go = "rumours_tavern";
					Saga_CreateMorelle(); //ставим Мореля
					npchar.quest.barbtemptation = "true";
					pchar.questTemp.Saga.BarbTemptation.Prison = "true";
					break;
				}
			}
			// Addon-2016 Jason ФМК-Гваделупа
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "headhunter_portobello" && npchar.location == "portobello_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "Недавно в губернаторском дворце пышный праздник был. Вернулся дон Карлос де Мильяр, большой друг его Светлости. В морском сражении он попал в плен к французам, однако ему удалось сбежать, склонив на свою сторону французского лейтенанта. Дону Карлосу ума не занимать, как, впрочем, и щедрости: лейтенанта этого, Жана Дено, приняли на службу в должности капитана и поставили командовать судном 'Сэрио'. И вроде даже небольшую плантацию ему подарили. Теперь француза величают, не иначе как дон Хуан. Так-то!";
				link.l1 = "Очень интересно... Хорошо, ты заслужил свои деньги - держи. А больше ничего примечательного не знаешь?";
				link.l1.go = "rumours_tavern";
				pchar.questTemp.FMQG = "headhunter_juan";
				AddQuestRecord("FMQ_Guadeloupe", "10");
				pchar.quest.FMQG_Juanship.win_condition.l1 = "location";
				pchar.quest.FMQG_Juanship.win_condition.l1.location = "PortoBello";
				pchar.quest.FMQG_Juanship.function = "FMQG_CreateJuanship";
				break;
			}	
			// Addon-2016 Jason ФМК-Сент-Кристофер
			if (CheckAttribute(pchar, "questTemp.FMQN") && pchar.questTemp.FMQN == "town" && npchar.location == "Marigo_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "Наш комендант усилил патрулирование в джунглях и охрану в городе. Прошел слух, что англичане собираются проникнуть в Филипсбург и выкрасть из тюрьмы пленных офицеров.";
				link.l1 = "Да ну? Неужели англичане решатся на такое?.. А что это за офицеры - не слыхал?";
				link.l1.go = "FMQN_r";
				break;
			}

			// Addon 2016-1 Jason пиратская линейка
			if (CheckAttribute(pchar, "questTemp.Mtraxx") && pchar.questTemp.Mtraxx == "jewelry_3" && npchar.location == "Havana_tavern")
			{
				AddMoneyToCharacter(pchar, -1000);
				Dialog.Text =  "У нас тут на днях весь город взбудоражен был. Офицер с военной шхуны надрался в стельку у меня в таверне, а затем чуть было не обесчестил замужнюю горожанку, а ее мужа, защищавшего свою жену, избил и угрожал обнаженной саблей. И все это происходило при полном бездействии городской стражи! Ворон ворону глаз не выклюет - правду ведь говорят. Солдаты чинно отворачивались и смотрели в другую сторону, пока этот негодяй творил свои безобразия\nНо негодяя обезвредили - и кто бы вы думали? - Матросы с купеческого судна. Мерзавца едва не скрутили, но он сумел вырваться и скрыться на своем корабле. Комендант и алькальд хотели замять это дело, но пострадавший - уважаемый горожанин, обратился к Его светлости дону Диего де Толедо и поднял шум среди зажиточных граждан. Офицера повелели схватить\nПоговаривают, что капитану советовали быстрее уйти из порта и увезти буяна в море, а потом его перевели бы в другое место службы, но капитан шхуны, Эсберто Кабаньяс, оказался человеком чести: узнав, что натворил его офицер, он немедленно арестовал негодяя и отправил на берег. Теперь дебошир в тюрьме, где ему самое место, и проведет там еще немало времени. А потом его, глядишь, разжалуют в солдаты, чтобы другим неповадно было.";
				link.l1 = "Как ты сказал? Капитан Эсберто Кабаньяс? Хм... презанятная история!.. Хорошо, ты заслужил свои деньги - держи. А больше ничего примечательного не знаешь?";
				link.l1.go = "rumours_tavern";
				Mtraxx_CreateOfficer(); // ставим офицера-негодяя
				pchar.questTemp.Mtraxx = "jewelry_4";
				pchar.GenQuest.PrisonQuestLock = "true";
				AddQuestRecord("Roger_1", "7");
				break;
			}	
			
            string RumText = SelectRumourEx("tavern", NPChar); //fix
           
		    if(!RumourHasInformation(RumText))
            {
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)]; //fix
                link.l1 = RandPhraseSimple("Я не стану платить за пустые сплетни, прощай.", "Твои сведения не стоят и ломаного гроша - ты ничего не получишь.");

			    link.l1.go = "Exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
            }
            else
            {
                AddMoneyToCharacter(pchar, -1000);
                Dialog.Text = RumText;
    			link.l1 = RandPhraseSimple("Благодарю, вот твои деньги. А больше ничего не припомнишь?", "Хорошо, ты заслужил свои деньги - держи. Есть что-нибудь еще?");
    			link.l1.go = "rumours_tavern";
    			NextDiag.CurrentNode = NextDiag.TempNode;    
            }
		break;

		case "rumours_tavern_no":
			Dialog.Text = "Поймите меня правильно, мне нужно кормить семью.";
            link.l1 = "Давай поговорим о чем-нибудь другом.";
			link.l1.go = "first time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			link.l2 = LinkRandPhrase("Спасибо, долж"+ GetSexPhrase("ен","на") +" откланяться.",
                                     "Всего хорошего","До свидания.");
			link.l2.go = "Exit";
		break;	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_poor":
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			if (!CheckAttribute(NPChar, "quest.repeat.rumours_poor") || NPChar.quest.repeat.rumours_poor <= 1)
			{
				Dialog.Text = SelectRumourEx("poor", NPChar);
				Link.l1 = RandPhraseSimple(RandSwear() + "Да, это интересно. Имеется еще вопрос...",
										"Хм, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
				Link.l1.go = "rumours_poor_2";
				Link.l2 = RandPhraseSimple("Ну, прощай, барыга.",
										"Всего хорошего, приятель.");
				Link.l2.go = "exit";
				NPChar.quest.repeat.rumours_poor = sti(NPChar.quest.repeat.rumours_poor) + 1;
			}
			else 
			{
				Dialog.Text = RandPhraseSimple("Не о чем говорить, все уже выболтал, что знал.", 
					"Больше я ничего не слышал, извините...");
				Link.l1 = RandPhraseSimple("Понятно. Ну что же, всего хорошего.",
										"Ясно. Ну, бывай, приятель...");
				Link.l1.go = "exit";			
			}
            NPChar.talk_date = lastspeakdate();
		break;
        case "rumours_poor_2":
			if (NPChar.quest.repeat.rumours_poor <= 1)
			{
				Dialog.Text = SelectRumourEx("poor", NPChar);
				Link.l1 = RandPhraseSimple(RandSwear() + "Да, это интересно. Имеется еще вопрос...",
										"Хм, вот что еще хотел"+ GetSexPhrase("","а") +" спросить...");
				Link.l1.go = "rumours_poor";
				Link.l2 = RandPhraseSimple("Ну, прощай, барыга.",
										"Всего хорошего, приятель.");
				Link.l2.go = "exit";
				NPChar.quest.repeat.rumours_poor = sti(NPChar.quest.repeat.rumours_poor) + 1;
			}
			else 
			{
				Dialog.Text = RandPhraseSimple("Не о чем говорить, все уже выболтал, что знал.", 
					"Больше я ничего не слышал, извините...");
				Link.l1 = RandPhraseSimple("Понятно. Ну что же, всего хорошего.",
										"Ясно. Ну, бывай, приятель...");
				Link.l1.go = "exit";			
			}
			NPChar.talk_date = lastspeakdate();
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_LSC":
			if (CheckNPCQuestDate(NPChar, "quest.repeat.rumours"))
			{
				Dialog.Text = SelectRumourExSpecial("LSC", NPChar);
				Link.l1 = RandPhraseSimple("Понятно...",
										"Ясно...");
				Link.l1.go = "exit";
				SetNPCQuestDate(NPChar, "quest.repeat.rumours");
			}
			else  
			{
				Dialog.Text = NPCharSexPhrase(npchar, RandPhraseSimple("Не о чем говорить, все уже выболтал, что знал.", "Больше я ничего не слышал, прошу прощения..."), 
					RandPhraseSimple("Простите, но я вам уже все выболтала.", "Больше я ничего не слышала, извините..."));
				Link.l1 = RandPhraseSimple("Я понял"+ GetSexPhrase("","а") +".", "Ну, всего хорошего.");
				Link.l1.go = "exit";			
			}
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "rumours_LSCC":
 	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			if (CheckNPCQuestDate(NPChar, "quest.repeat.rumours"))
			{
				Dialog.Text = SelectRumourExSpecial("LSCC", NPChar);
				Link.l1 = RandPhraseSimple("Понятно...",
										"Ясно...");
				Link.l1.go = "exit";
				SetNPCQuestDate(NPChar, "quest.repeat.rumours");
			}
			else  
			{
				Dialog.Text = NPCharSexPhrase(npchar, RandPhraseSimple("Не о чем говорить, все уже выболтал, что знал.", "Больше я ничего не слышал, прошу прощения..."), 
					RandPhraseSimple("Простите, но я вам уже все выболтала.", "Больше я ничего не слышала, извините..."));
				Link.l1 = RandPhraseSimple("Я понял"+ GetSexPhrase("","а") +".", "Ну, всего хорошего.");
				Link.l1.go = "exit";			
			}
		break;
		
//Jason -------------слухи смотрителей маяков, идентичны таверне, но бесплатны, по 1 шт за день--------------------
		case "rumours_lighthouse": 
	                                PlaySound("VOICE\Russian\GOTHIC\GG_Rumours\Rumours_" + rand(25) + ".wav");
			Dialog.Text = NPCStringReactionRepeat(RandPhraseSimple("Эх капитан! Я всегда рад поболтать. Знаете, здесь одному иногда бывает так скучно...", "Я живу здесь один, гости ко мне заходят нечасто. Так что переброситься парой слов с кем-нибудь для меня всегда - радость."), "Любите поболтать, капитан? Ну, может еще что вспомню...", "Соберетесь еще ко мне - захватывайте бутылку рома. Под спиртное так хорошо вести беседы...", "К сожалению, я рассказал все, что знал. Больше мне нечего добавить.", "block", 1, npchar, Dialog.CurrentNode);
    		link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Ну, тогда поделись своей информацией. Я, знаешь ли, тоже охотник поболтать...", "Рассказывай! Кто владеет информацией - тот владеет миром, так ведь говорят?"), "Например?", "Обязательно! Ну, выкладывай, что еще слышал?", "Ну и ладно, мы и так здорово поболтали." , npchar, Dialog.CurrentNode);
    		link.l1.go = HeroStringReactionRepeat("rumours_lighthouse_yes", "rumours_lighthouse_void", "rumours_lighthouse_void", "exit", npchar, Dialog.CurrentNode);
		break;
		
		case "rumours_lighthouse_yes":
            RumText = SelectRumourEx("tavern", NPChar);
		    if(!RumourHasInformation(RumText))
            {
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)];
                link.l1 = RandPhraseSimple("Благодарю! Что-нибудь еще слышал?", "Очень интересно! Больше ничего не припомнишь?");

			    link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("Благодарю! Весьма занятно...", "Спасибо за информацию!");
			    link.l2.go = "exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
            }
            else
            {
                Dialog.Text = RumText;
    			link.l1 = RandPhraseSimple("Благодарю! Весьма занимательно... Что-нибудь еще слышал?", "Очень интересно! А больше ничего не припомнишь?");
    			link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("Благодарю! Весьма занятно...", "Спасибо за интересный рассказ!");
			    link.l2.go = "exit";
    			NextDiag.CurrentNode = NextDiag.TempNode;    
            }
		break;
		
		case "rumours_lighthouse_void":
                Dialog.Text = NO_RUMOUR_TEXT[rand(SIMPLE_RUMOUR_NUM - 1)];
                link.l1 = RandPhraseSimple("Благодарю! Что-нибудь еще слышал?", "Очень интересно! Больше ничего не припомнишь?");

			    link.l1.go = "rumours_lighthouse";
				link.l2 = RandPhraseSimple("Благодарю! Весьма занятно...", "Спасибо за интересный рассказ!");
			    link.l2.go = "exit";
			    NextDiag.CurrentNode = NextDiag.TempNode;
		break;
//Jason ------------------------------------почтовый генератор 2 уровня-------------------------------------------
		case "Postcureer_LevelUp_ForAll":
			//начинаем проверять
			if (!CheckCharacterItem(pchar, pchar.questTemp.WPU.Current.Item))
			{
				dialog.text = "Но где же пакет? У вас его нет?";
	        	link.l1 = "М-м... я должен был вам его доставить. Но у меня его попросту... буду честным - отняли. Я не смог противостоять нападавшим и отдал им пакет. ";
	        	link.l1.go = "Postcureer_LevelUp_complete_fail";
				break;
			}
			
			if (sti(pchar.questTemp.WPU.Postcureer.AgentChance) == 4)//раскрыли обман
			{
				dialog.text = "Хм. Позвольте, но этот пакет уже вскрывали! Я это совершенно точно вижу. Печать поставлена повторно...";
	        	link.l1 = "" + GetAddress_FormToNPC(NPChar) + ", я привез вам пакет в том виде, в котором получил его в портовом управлении  " +XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+ ", и не имею ни малейшего понятия...";
	        	link.l1.go = "Postcureer_LevelUp_complete_Agentfail";
				break;
			}
			
			if (pchar.questTemp.WPU.Postcureer == "late")//опоздали
			{
				int iTime = makeint(GetQuestPastDayParam("questTemp.Postcureer.Late"))+1;
				pchar.questTemp.WPU.Postcureer.Money = makeint(sti(pchar.questTemp.WPU.Postcureer.Money)/(sti(iTime)+1));//сильно снижаем оплату
				dialog.text = "Я ждал вас. Но вы опоздали на " + FindRussianDaysString(iTime)+ "! Информация, содержащаяся в этом документе, уже значительно утратила свою актуальность... Но польза от нее все-таки есть - поэтому я заплачу вам за работу, хотя, конечно, меньше - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ". Пожалуйста, получите ваши деньги и прощайте.";
	        	link.l1 = "Спасибо и на этом.";
	        	link.l1.go = "Postcureer_LevelUp_complete";
				pchar.quest.PostcureerTime_FullOver.over = "yes";//снять второй таймер
				pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-1;//опоздавший рейс не засчитываем
				AddQuestRecord("Postcureer", "8");
				AddQuestUserData("Postcureer", "sDay", FindRussianDaysString(iTime));
				AddQuestUserData("Postcureer", "sMoney", FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)));
				break;
			}
			
			if (pchar.questTemp.WPU.Postcureer == "lost")//опоздали совсем
			{
				dialog.text = "Так это вы! А я вас уже не ждал, уже и меры соответствующие в ваш адрес принял - знаете ли, охотников за важной информацией много. Давайте сюда пакет. Хотя он мне уже и не нужен - благодаря вашему опозданию, информация, содержащаяся там, мне уже вряд ли пригодится - но все-таки пусть он будет у меня\nКак вы понимаете, оплаты за доставку не будет. Единственное, что я сделаю - приму меры, чтобы восстановить ваше доброе имя.";
	        	link.l1 = "Спасибо и на этом. Простите за опоздание, мне действительно жаль, что так вышло. Всего доброго.";
	        	link.l1.go = "Postcureer_LevelUp_complete_bad";
				break;
			}
			dialog.text = "Я ждал вас. Вы прибыли вовремя - информация, которую вы привезли, будет очень кстати. Получите, пожалуйста, вашу оплату за труды - " + FindRussianMoneyString(sti(pchar.questTemp.WPU.Postcureer.Money)) + ". Благодарю за оперативность.";
        	link.l1 = "И вам спасибо. До свидания!";
        	link.l1.go = "Postcureer_LevelUp_complete";
			pchar.quest.PostcureerTime_Over.over = "yes";//снять таймер
			AddQuestRecord("Postcureer", "10");
		break;
		
		case "Postcureer_LevelUp_complete":
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddMoneyToCharacter(pchar, sti(pchar.questTemp.WPU.Postcureer.Money));
			CloseQuestHeader("Postcureer");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
			AddCharacterExpToSkill(pchar, "Sailing", 120);//навигация
			AddCharacterExpToSkill(pchar, "Sneak", 120);//скрытность
			AddCharacterExpToSkill(pchar, "Leadership", 150);//авторитет
			AddCharacterExpToSkill(pchar, "Fortune", 150);//везение
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), 2);
			Group_DeleteGroup("Fraht_Attack");
			DialogExit();
		break;
		
		case "Postcureer_LevelUp_complete_bad":
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddQuestRecord("Postcureer", "9");
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", 10);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), 33);
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
			DialogExit();
		break;
		
		case "Postcureer_LevelUp_complete_fail":
			dialog.text = "Эх, я так и знал, что всё этим кончится... надо было оплатить услуги военного курьерского судна, а не положиться на гражданских капитанов... Ладно, " + GetAddress_Form(NPChar) + ", чего уж вас винить - вы ведь все-таки не солдат. Прощайте.";
			link.l1 = "До свидания, " + GetAddress_FormToNPC(NPChar) + ".";
			link.l1.go = "exit";
			if (pchar.questTemp.WPU.Postcureer == "begin") pchar.quest.PostcureerTime_Over.over = "yes";//снять таймер
			if (pchar.questTemp.WPU.Postcureer == "late") pchar.quest.PostcureerTime_FullOver.over = "yes";//снять второй таймер
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), -2);
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-3;//скрутим счетчик
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			pchar.questTemp.WPU.Postcureer = "complete";
		break;
		
		case "Postcureer_LevelUp_complete_Agentfail":
			dialog.text = "Сударь, я лично знаю начальника порта " +XI_ConvertString("Colony"+pchar.questTemp.WPU.Postcureer.StartCity+"Gen")+ ", это честнейший человек. Да и ни к чему ему было вскрывать это послание. " + GetAddress_Form(NPChar) + ", вы - мошенник! Я не намерен ничего платить вам. Убирайтесь!";
			link.l1 = "Гхм-м...";
			link.l1.go = "Postcureer_LevelUp_complete_Agentfail_1";
		break;
		
		case "Postcureer_LevelUp_complete_Agentfail_1":
			if (pchar.questTemp.WPU.Postcureer == "begin") pchar.quest.PostcureerTime_Over.over = "yes";//снять таймер
			if (pchar.questTemp.WPU.Postcureer == "late") pchar.quest.PostcureerTime_FullOver.over = "yes";//снять второй таймер
			RemoveItems(PChar, pchar.questTemp.WPU.Current.Item, 1);
			AddQuestRecord("Postcureer", "17");
			CloseQuestHeader("Postcureer");
			ChangeCharacterComplexReputation(pchar,"nobility", -10);
			ChangeCharacterNationReputation(pchar, sti(pchar.questTemp.WPU.Postcureer.Nation), -2);
			pchar.questTemp.WPU.Postcureer.count = sti(pchar.questTemp.WPU.Postcureer.count)-3;//скрутим счетчик
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.TargetPortmanID");
			DeleteAttribute(pchar, "questTemp.WPU.Current");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.LevelUp");
			DeleteAttribute(pchar, "questTemp.WPU.Postcureer.AgentChance");
			pchar.questTemp.WPU.Postcureer = "complete";
			DialogExit();
		break;
		
// <--почтовый генератор 2 уровня

//Jason --> ---------------------------------генератор Неудачливый вор--------------------------------------------
		case "Device_Common":
			dialog.text = "На вид - оборванец-оборванцем, похоже, нищий, или бездомный. А куда пошел - сказать не могу, мне некогда было за ним ходить-следить. Ушел куда-то, а куда - Бог его знает.";
			link.l1 = "Уже какая-то информация - все лучше, чем ничего. Спасибо! Побегу его искать!";
			link.l1.go = "Device_Common_1";
		break;
		
		case "Device_Common_1":
			string sNation = pchar.GenQuest.Device.Shipyarder.Nation;
			sld = GetCharacter(NPC_GenerateCharacter("Device_poorman", "panhandler_"+(rand(5)+1), "man", "man", sti(pchar.rank)+5, sNation, 20, true, "quest"));
			SetFantomParamFromRank(sld, sti(pchar.rank)+5, true);         
			GiveItem2Character(sld, "slave_02");
			EquipCharacterbyItem(sld, "slave_02");
			LAi_SetCitizenType(sld);
			LAi_group_MoveCharacter(sld, sNation+"_CITIZENS");
			sld.Dialog.Filename = "Quest\Other_Quests_NPC.c"; 
			sld.dialog.currentnode = "Device_poorman"; 
			sld.greeting = "Gr_poorman";
			switch (sti(pchar.GenQuest.Device.Shipyarder.Chance2))
			{
				case 0://в городе
					sld = characterFromId("Device_poorman");
					GetCharacterPos(pchar, &locx, &locy, &locz);
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.City +"_town", "goto", LAi_FindFarLocator("goto", locx, locy, locz));
				break;
				case 1://за воротами
					sld = characterFromId("Device_poorman");
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.City + "_ExitTown", "goto", "goto1");
				break;
				case 2://в бухте
					sld = characterFromId("Device_poorman");
					pchar.GenQuest.Device.Shipyarder.Shore = SelectQuestShoreLocation();
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Shore, "goto", "goto1");
				break;
				case 3://в доме
					sld = characterFromId("Device_poorman");
					pchar.GenQuest.Device.Shipyarder.Location = GetDeviceLocation(npchar); //определяем локацию
					ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Location, "goto", "goto1");
					if (pchar.GenQuest.Device.Shipyarder.Location == "none" || CheckAttribute(pchar, "GenQuest.SeekSpy.Location"))//если вдруг мимо или взят поиск шпиона
					{
						pchar.GenQuest.Device.Shipyarder.Shore = SelectQuestShoreLocation();
						ChangeCharacterAddressGroup(sld, pchar.GenQuest.Device.Shipyarder.Shore, "goto", "goto1");
					}
				break;
			}
			pchar.GenQuest.Device.Shipyarder = "inSeek";
			DialogExit();
			AddQuestRecord("Device", "9");
		break;
		//<-- генератор Неудачливый вор
		
		// Addon-2016 Jason ФМК-Сент-Кристофер
		case "FMQN_r":
			Dialog.Text =  "Да не так давно у берегов Синт-Маартена захватили английский корабль, а на нем было несколько высокопоставленных военных. Их решили отправить в Виллемстад, но временно поместили в тюрьму. Поговаривают, что пленный солдат с того судна в обмен на свободу рассказал коменданту, что англичане намереваются прислать диверсионную группу и организовать побег заключенных. Даже план у них готов был. Вот и начеку наш бравый комендант. Ведь если упорхнут такие важные птицы - его, как пить дать, разжалуют в солдаты. Так-то!";
			link.l1 = "Очень интересно... Хорошо, ты заслужил свои деньги - держи. А больше ничего примечательного не знаешь?";
			link.l1.go = "rumours_tavern";
			pchar.questTemp.FMQN = "governor";
			pchar.quest.FMQN_governor.win_condition.l1 = "location";
			pchar.quest.FMQN_governor.win_condition.l1.location = "Marigo_town";
			pchar.quest.FMQN_governor.function = "FMQN_ToGovernor";
			if (Whr_IsDay()) AddDialogExitQuest("FMQN_GetRumoursDay");
			else AddDialogExitQuest("FMQN_GetRumoursNight");
		break;
		
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		Квесты мэра, проникновение во враждебный город
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "IntelligenceForAll":
            Dialog.Text = RandPhraseSimple("Ну что же, очень хорошо. У меня готов для вас пакет, который вам надлежит доставить известному лицу лично в руки. Извольте получить.\nНе подходите ко мне больше и не заговаривайте со мной, это может быть подозрительным. Соблюдайте осторожность...", 
				"Хм, прекрасно. Я вручаю вам пакет, и помните, что он должен быть доставлен названному вами лицу лично в руки.\nТеперь прощайте и не подходите ко мне более - это опасно.");
            link.l1 = RandPhraseSimple("Я понял"+ GetSexPhrase("","а") +". Прощайте...", "Прощайте и удачи.");
			link.l1.go = "exit";
			pchar.GenQuest.Intelligence = "Execute";
			GiveItem2Character(pchar, "sicretLetter");
			AddCharacterExpToSkill(pchar, "Sneak", 200);
			ref rItem = ItemsFromID("sicretLetter");
			rItem.City = XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.Intelligence.MayorId)].city+"Gen")); 
			rItem.Mayor = GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)); 
			AddQuestRecord("MayorsQuestsList", "7");
			AddQuestUserData("MayorsQuestsList", "ColonyName", XI_ConvertString("Colony"+characters[GetCharacterIndex(pchar.GenQuest.Intelligence.MayorId)].city+"Gen"));
			AddQuestUserData("MayorsQuestsList", "MayorName", GetFullName(characterFromId(pchar.GenQuest.Intelligence.MayorId)));
			AddQuestUserData("MayorsQuestsList", "sCity", XI_ConvertString("Colony"+pchar.GenQuest.Intelligence.City+"Dat"));
			AddQuestUserData("MayorsQuestsList", "sWho", GetWorkTypeOfMan(&characters[GetCharacterIndex(pchar.GenQuest.Intelligence.SpyId)], "Gen"));
			AddQuestUserData("MayorsQuestsList", "SpyName", GetFullName(&characters[GetCharacterIndex(pchar.GenQuest.Intelligence.SpyId)]));			
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		Квест Асокольда, рендомные базары
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "AscoldTrader": //рендомный хозяин магаза
            dialog.Text = "Послушай, не встречал"+ GetSexPhrase("","а") +" еще порошка мумии, который я просил тебя разыскать?";
            if (GetQuestPastDayParam("questTemp.Ascold") > 3)
			{
				Link.l1 = "Нет, пока не встречал"+ GetSexPhrase("","а") +"... Послушай, у торговцев на улицах он, кажется, есть, но что-то они темнят...";
            	Link.l1.go = "AscoldTrader_6";
			}
			else
			{
				Link.l1 = "Нет, пока не встречал"+ GetSexPhrase("","а") +"... Но я продолжу поиски.";
            	Link.l1.go = "quests";
			}
		break;
        case "AscoldTrader_WasSeek":
            dialog.Text = "Послушай, не встречал"+ GetSexPhrase("","а") +" еще порошка мумии, который я просил тебя разыскать?";
            Link.l2 = "Да, наш"+ GetSexPhrase("ел","ла") +". И сколько ты мне за него заплатишь?";
            Link.l2.go = "AscoldTrader_1";
        break;		
		case "AscoldTrader_1":
        	dialog.text = "Я - нисколько. Но я знаю, кто купит у тебя это.";
    		link.l1 = "Хм, я рассчитывал"+ GetSexPhrase("","а") +" на получение денег прямо сейчас.";
    		link.l1.go = "AscoldTrader_2";
		break;
 		case "AscoldTrader_2":
        	dialog.text = "Полагаю, ты не останешься в накладе. Слушай внимательно.\n"+
                          "На Гваделупе в городе Бас Тер живет один странный тип - Аскольд.";
            if (Characters[GetCharacterIndex("Ascold")].quest.meeting == "0")
            {
                link.l1 = "Аскольд говоришь - знаю его...";
                link.l1.go = "AscoldTrader_4";
            }
            else
            {
                link.l1 = "Знаю я его, довелось поговорить. Наглец, каких поискать...";
                link.l1.go = "AscoldTrader_3";
            }
		break;
 		case "AscoldTrader_3":
        	dialog.text = "А что случилось? Испытал"+ GetSexPhrase("","а") +" на себе его крутой нрав?";
    		link.l1 = "Да уж, он просто выставил меня за дверь, как "+ GetSexPhrase("мальчишку","девчонку") +"!";
    		link.l1.go = "AscoldTrader_4";
		break;
 		case "AscoldTrader_4":
        	dialog.text = "Аскольд немного резковат, но человек он хороший, честный. По слухам - московит, есть такой народ, который живет на севере Старого Света, где круглый год снег, а вокруг одни леса да медведи. Оттого и характер суровый, а силы в руках хватит на четверых здоровенных молодцов.\n"+
                          "Как и когда он оказался здесь, я точно не знаю, как и не знаю, чем он занимается.\n"+
                          "Но мне он доверяет, так как я имею с ним торговые дела.\n"+
                          "Так что поезжай к нему, представишься, скажешь, что от меня - и все будет в порядке. Купит он у тебя эту дрянь, так как это его заказ.";
    		link.l1 = "А тебе с этого какой доход?";
    		link.l1.go = "AscoldTrader_5";
		break;
 		case "AscoldTrader_5":
        	dialog.text = "За меня не переживай, я удержу нужную сумму комиссионных из нашей с ним текущей оборотки.";
    		link.l1 = "Понятно. Что ж, пожалуй, загляну к твоему Аскольду при случае.";
    		link.l1.go = "exit";
    	    pchar.questTemp.Ascold = "GoToAscold";
    	    QuestSetCurrentNode("Ascold", "HaveRecomendation");
            AddQuestRecord("Ascold", "2");
		break;
 		case "AscoldTrader_6":
        	dialog.text = "Небось, и Инквизицией грозятся?";
    		link.l1 = "Точно, грозятся...";
    		link.l1.go = "AscoldTrader_7";
		break;
 		case "AscoldTrader_7":
        	dialog.text = "Ну а как ты хотел"+ GetSexPhrase("","а") +"?.. Вот что я тебе скажу, "+ GetSexPhrase("приятель","подруга") +": порошок есть у них. Не у всех, конечно, но у кого-то точно он имеется. Поэтому ты будь настойчивей с ними - и в итоге добьешься своего.";
    		link.l1 = "Хех, ну что же, спасибо за помощь.";
    		link.l1.go = "quests";
			SaveCurrentQuestDateParam("questTemp.Ascold");
		break;

        //==> Общий диалог для хозяев верфи, квест Аззи.
		case "AzzyTryTalk":
			dialog.Text = NPCStringReactionRepeat("Давай посмотрим на твою жестянку. Э-э-э, нет. Ты посмотри на нее, она сплошь покрыта странными письменами, не иначе это колдовство. Советую тебе отнести эту вещь в церковь, там разберутся, что с ней делать.", "none", "none", "none", "block", 0, npchar, Dialog.CurrentNode);
  			Link.l1 = HeroStringReactionRepeat("Спасибо за добрый совет.", "none", "none", "none", npchar, Dialog.CurrentNode);
			Link.l1.go = "Exit";
		break;

		case "AggryHelp":
			dialog.Text = NPCStringReactionRepeat("Вот там на столе лежит инструмент: паяльная лампа, ножовка по металлу, ножницы для жести и прочее. Бери и открывай сам"+ GetSexPhrase("","а") +", а денег мне не надо.", "none", "none", "none", "block", 0, npchar, Dialog.CurrentNode);
			Link.l10 = HeroStringReactionRepeat("Спасибо, " + npchar.name + ".", "none", "none", "none", npchar, Dialog.CurrentNode);
			Link.l10.go = "exit";
			items[GetItemIndex("Azzy_bottle")].shown = 0; //даем возможность вскрыть лампу

		break;

		//==> Общий диалог для церкви, квест Аззи.
        case "GiveLamp":
			dialog.text = "Ты правильно поступил"+ GetSexPhrase(", сын мой","а, дочь моя") +". Неизвестно, что там внутри, но по всему видно, что завтра церковь нужно будет освящать заново.\n"+
                          "Я не хочу спрашивать, где ты это взял"+ GetSexPhrase("","а") +". Именем Спасителя прощаю тебе грехи твои! Иди с миром.";
			link.l1 = "Спасибо, Святой Отец.";
			link.l1.go = "exit";
            ChangeCharacterReputation(pchar, 100);
            TakeItemFromCharacter(pchar, "Azzy_bottle");
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		Линейка острова погибших кораблей ISS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case "ISS_deposit":
			dialog.text = NPCStringReactionRepeat("Совершенно верно. Один миллион пиастров вы можете получить через минуту после получения мной подтверждения.", 
				"Я уже говорил вам, " + GetAddress_Form(NPChar) + ", что депозит у меня. Я жду подтверждения на его выдачу.", 
				"Вам не стоит беспокоиться. Депозит находится у меня, я жду только подтверждения на его выдачу.",
				"Хм, мне кажется, вы чрезмерно обеспокоены этим депозитом. Моя репутация безупречна, поэтому я могу только повторить ранее сказанное. Депозит на ваше имя находится у меня, получить вы его сможете после подтверждения на выдачу.", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Понятно. Ну что же, прекрасно. Я узнал"+ GetSexPhrase("","а") +" то, что хотел"+ GetSexPhrase("","а") +".", 
				"Ага, понятно...",
				"Я и не беспокоюсь особо.", 
				"Понятно... Спасибо вам, " + GetAddress_Form(NPChar) + ".", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		break;
		case "ISS_takeDeposit":
			dialog.text = "Да-да, я получил разрешение провести эту финансовую операцию. Извольте получить, " + GetAddress_Form(NPChar) + ".";
			link.l1 = "Хе-хе, очень хорошо...";
			link.l1.go = "ISS_takeDeposit_1";
			AddMoneyToCharacter(pchar, 1000000);
			CloseQuestHeader("ISS_PoorsMurder");
		break;
		case "ISS_takeDeposit_1":
			dialog.text = "Быть может, вы решите пустить эти деньги в рост? Я всегда к вашим услугам, моя репутация...";
			link.l1 = "Я понял"+ GetSexPhrase("","а") +" вас, спасибо. Я подумаю.";
			link.l1.go = "exit";
			pchar.questTemp.LSCC = "over"; //конец линейки ГПК
			CloseQuestHeader("ISS_PoorsMurder");
		break;
		//механика арестовали, диалоги мужика
		case "MechanicIsPrison_man":
			dialog.text = "А-а, ну вот и вы, наконец...";
			link.l1 = "В чем дело? Почему вы еще не на воздушный шар?... А где Механик?";
			link.l1.go = "MechanicIsPrison_man_1";
		break;
		case "MechanicIsPrison_man_1":
			dialog.text = "Где он сейчас я не знаю. Когда я приш"+ NPCharSexPhrase(NPChar, "ел","ла") +" на 'Сан Габриэль', его как раз выводили милиционеры. Судя по всему, он арестован, и сделать это мог только адмирал.";
			link.l1 = "Каррамба!!! Что же теперь делать?";
			link.l1.go = "MechanicIsPrison_man_2";
		break;
		case "MechanicIsPrison_man_2":
			dialog.text = "А без Механика нам не обойтись?";
			link.l1 = "Ведекер нам нужен. На воздушный шар мы попасть сможем, а вот освободить его без Хенрика не выйдет.";
			link.l1.go = "MechanicIsPrison_man_3";
		break;
		case "MechanicIsPrison_man_3":
			dialog.text = "Тогда нужно идти в резиденцию к Капперу, выручать Механика. Я, к сожалению, пас в этом деле - адмирал наводит на меня ужас одним своим видом...";
			link.l1 = "Хех, оно и понятно... Отправляйтесь на воздушный шар, я скоро прибуду с Ведекером. Остальные члены команды, судя по всему, уже там.";
			link.l1.go = "MechanicIsPrison_man_4";
		break;
		case "MechanicIsPrison_man_4":
			dialog.text = "Как скажете, капитан.";
			link.l1 = "Не паникуйте там без меня. Все будет хорошо.";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.questTemp.LSCC = "MechanicIsArrest_toResidence";
			SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
			bDisableFastReload = true; 
			AddQuestRecord("ISS_MainLine", "64");
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1 = "location";
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1.location = "SanAugustineResidencee";
			pchar.quest.LSCC_fightEnterResidence.function = "LSCC_fightEnterResidence";
		break;
		//механика арестовали, диалоги бабы
		case "MechanicIsPrison_woman":
			dialog.text = "А-а, ну вот и вы, наконец...";
			link.l1 = "В чем дело? Почему вы еще не на воздушном шаре?... А где Механик?";
			link.l1.go = "MechanicIsPrison_man_1";
		break;
		case "MechanicIsPrison_woman_1":
			dialog.text = "Где он сейчас я не знаю. Когда я пришла на 'Сан Габриэль', его как раз выводили милиционеры. Судя по всему, он арестован, и сделать это мог только адмирал.";
			link.l1 = "Каррамба!!! Что же теперь делать?";
			link.l1.go = "MechanicIsPrison_woman_2";
		break;
		case "MechanicIsPrison_woman_2":
			dialog.text = "А без Механика нам не обойтись?";
			link.l1 = "Ведекер нам нужен. На корвет мы попасть сможем, а вот освободить его без Хенрика не выйдет.";
			link.l1.go = "MechanicIsPrison_man_3";
		break;
		case "MMechanicIsPrison_woman_3":
			dialog.text = "Тогда нужно идти в резиденцию к Капперу, выручать Механика. Я, как женщина, помочь в этом деле вам не смогу, к сожалению.";
			link.l1 = "Это точно... Отправляйтесь на воздушный шар, я скоро прибуду с Ведекером. Остальные члены команды, судя по всему, уже там.";
			link.l1.go = "MechanicIsPrison_man_4";
		break;
		case "MechanicIsPrison_woman_4":
			dialog.text = "Как скажете, капитан.";
			link.l1 = "Не паникуйте там без меня. Все будет хорошо.";
			link.l1.go = "exit";
			npchar.lifeDay = 0;
			LAi_CharacterDisableDialog(npchar);
			pchar.questTemp.LSCC = "MechanicIsArrest_toResidence";
			SetCrewQuantity(pchar, GetMinCrewQuantity(pchar));
			bDisableFastReload = true; 
			AddQuestRecord("ISS_MainLine", "64");
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1 = "location";
			pchar.quest.LSCC_fightEnterResidence.win_condition.l1.location = "SanAugustineResidencee";
			pchar.quest.LSCC_fightEnterResidence.function = "LSCC_fightEnterResidence";
		break;
		case "SeekCrew_all":
			pchar.questTemp.LSCC.crew = sti(pchar.questTemp.LSCC.crew) + 1;
			chrDisableReloadToLocation = true;
			float   locx, locy, locz;
			GetCharacterPos(pchar, &locx, &locy, &locz);
			if (sti(pchar.questTemp.LSCC.crew) >= 15)
			{
				DeleteAttribute(pchar, "questTemp.LSCC.crew");
				pchar.questTemp.LSCC = "MechanicIsArrest";
				pchar.questTemp.LSCC.lastManId = npchar.index; //сюда запишем индекс
				NextDiag.TempNode = "MechanicIsPrison_" + npchar.sex;
				AddQuestRecord("ISS_MainLine", "63");
				AddQuestUserData("ISS_MainLine", "sSex", GetSexPhrase("","а"));
				AddQuestUserData("ISS_MainLine", "sSex1", GetSexPhrase("ен","на"));
				if (npchar.location.group == "sit")
				{
					ChangeCharacterAddressGroup(npchar, npchar.location, "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
				}
				npchar.cityTape = "quest";  //чтобы не передвигался
				DeleteAttribute(npchar, "location.going"); //снять метку на перемещение
				LAi_SetActorType(npchar);
				LAi_ActorRunToLocation(NPChar, "reload", LAi_FindNearestLocator("reload", locx, locy, locz), "none", "", "", "OpenTheDoors", 10.0);
				pchar.quest.LSCC_afterArestMachanic.win_condition.l1 = "ExitFromLocation";
				pchar.quest.LSCC_afterArestMachanic.win_condition.l1.location = pchar.location;
				pchar.quest.LSCC_afterArestMachanic.function = "LSCC_afterArestMachanic";
			}
			else
			{
				AddQuestRecord("ISS_MainLine", "62");
				AddQuestUserData("ISS_MainLine", "sName", GetFullName(npchar));
				AddQuestUserData("ISS_MainLine", "Sex", NPCharSexPhrase(npchar, "согласился", "согласилась"));
				AddQuestUserData("ISS_MainLine", "iCrew", FindRussianPeoplesString(15-sti(pchar.questTemp.LSCC.crew), "Acc"));
				npchar.lifeDay = 0;
				if (npchar.location.group == "sit")
				{
					ChangeCharacterAddressGroup(npchar, npchar.location, "goto", LAi_FindNearestLocator("goto", locx, locy, locz));
				}
				LAi_SetActorType(npchar);
				LAi_ActorRunToLocation(NPChar, "reload", LAi_FindNearestLocator("reload", locx, locy, locz), "none", "", "", "OpenTheDoors", 10.0);			
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();		
		break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////		Грабеж среди бела дня, попытка залезть в сундуки
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case "Man_FackYou":
			dialog.text = LinkRandPhrase("Грабеж среди бела дня!!! Это что же такое делается?! Ну, погоди, "+ GetSexPhrase("приятель","подруга") +"...", "Эй, ты чего это там копаешься?! Никак, вздумал"+ GetSexPhrase("","а") +" ограбить меня? Ну, тогда тебе конец...", "Постой, ты куда это полез"+ GetSexPhrase("","ла") +"? Да ты вор"+ GetSexPhrase("","овка") +", оказывается! Ну, считай, что ты приплыл"+ GetSexPhrase("","а") +", родн"+ GetSexPhrase("ой","ая") +"...");
			link.l1 = LinkRandPhrase("Дьявол!!", "Каррамба!!", "А-ать, черт!");
			link.l1.go = "fight_owner";
		break;
		case "fight_owner":
			LAi_SetOwnerTypeNoGroup(NPChar);
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

string sRumourAboutOwners_CityRumour(string sCity, string sOwnerType) // Здесь идет распределение по городам
{
	string sRetRumour = "Явный баг. Сообщите о нем АТ, для Warship'а.";
	// флаг - PChar.QuestTemp.RumoursAboutOwners.(sOwner) - для проверок, какой вопрос выпал. Ножно будет юзать для квестов
	switch(sCity)
	{
		case "Tortuga":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 0;
		break;
		
		case "PortRoyal":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 1;
		break;

		case "PortAntonio":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 1;
		break;

		case "FortOrange":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 2;
		break;
		
		case "Beliz":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 3;
		break;
		
		case "PortoBello":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 4;
		break;
		
		case "Cartahena":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 5;
		break;
		
		case "Maracaibo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 6;
		break;
		
		case "Caracas":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 7;
		break;
		
		case "Cumana":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 8;
		break;
		
		case "SantaCatalina":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 9;
		break;
		
		case "SanJuan":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 10;
		break;
		
		case "Marigo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 11;
		break;
		
		case "Charles":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 12;
		break;
		
		case "SentJons":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 13;
		break;
		
		case "FortFrance":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 14;
		break;
		
		case "BasTer":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 15;
		break;
		
		case "Bridgetown":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 2);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 16;
		break;
		
		case "PortSpein":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 17;
		break;
		
		case "Havana":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 4);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 18;
		break;
		
		case "Villemstad":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 5);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 19;
		break;
		
		case "Santiago":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 6);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 20;
		break;
		
		case "PortPax":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 21;
		break;
		
		case "SantoDomingo":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 1);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 22;
		break;

		case "VillaAlegria":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 3);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 10;
		break;

	case "Leke":
			sRetRumour = sRumourAboutOwners_Init(sOwnerType, 0);
			PChar.QuestTemp.RumoursAboutOwners.(sOwnerType) = 21;
		break;
	}
	
	return sRetRumour;
}

string sRumourAboutOwners_Init(string sOwnerType, int iRumourNum) // База слухов жителей. Можно менять без новой игры
{
	PlaySound("VOICE\Russian\GOTHIC\GG_PEOPLE\GG_PEOPLE_" + rand(5) + ".wav");	
	string STR_MAYOR[MAX_RUMOURS_ABOUT_OWNERS]; // Губернаторы
	STR_MAYOR[0] = "О, господин губернатор - замечательный человек. Он умело управляет нашей колонией - с момента ее основания у нас не было ни единого крупного конфликта\nЕдинственный его недостаток - он... ммм... весьма бережлив. Хотя, возможно, это наоборот достоинство.";
	STR_MAYOR[1] = "О, господин губернатор - замечательный человек. Он умело управляет нашей колонией - с момента ее основания у нас не было ни единого крупного конфликта\nЕдинственный его недостаток - он... ммм... весьма бережлив. Хотя, возможно, это наоборот достоинство.";
	STR_MAYOR[2] = "Увы, господин губернатор у нас хороший... Но слабохарактерный. Ему бы чуточку твердости в душе - и у наших торговцев появились бы небольшие налоговые льготы... И субсидии на ремонт форта давно пора бы выделить.";
	STR_MAYOR[3] = "Хм... Он недавно стал у нас губернатором. Он довольно молод и поэтому очень инициативен - при нем наша колония процветает.";
	STR_MAYOR[4] = "Наш губернатор еще относительно молод. Говорят, он - непутевый младший сын испанского графа, отправленный от двора куда подальше, чтобы прекратил позорить свой род. Назначен он был сюда совсем недавно, и ничего запоминающегося сотворить не успел.";
	STR_MAYOR[5] = "Хм... Он недавно стал у нас губернатором. Он довольно молод и поэтому очень инициативен - при нем наша колония процветает.";
	STR_MAYOR[6] = "Э-э... Ничего... ничего плохого сказать про него не могу.";
	
	string STR_TAVERNKEEPER[MAX_RUMOURS_ABOUT_OWNERS]; // Тавернщики
	STR_TAVERNKEEPER[0] = "Хм, я бы не доверил свое имущество этому пройдохе. Не поймите меня неправильно, но мне кажется, что это самый ненадежный человек в нашем городке\nГоворят, что он путается с контрабандистами и пиратами - и в таверне у него все время всякий сброд ошивается!";
	STR_TAVERNKEEPER[1] = "Да что о нем можно сказать! Трусоват, да и умом не отличается. К тому же жаден до денег, отчего постоянно попадает в различные неприятности! Зато, правда, он всегда в курсе всех новостей.";
	STR_TAVERNKEEPER[2] = "Довольно приятный тип. У него в таверне всегда приятно посидеть, да и чувством юмора у хозяина все в порядке. А самое главное - он следит за порядком в таверне и не позволяет всякой пьяной швали задирать добропорядочных граждан.";
	STR_TAVERNKEEPER[3] = "Удивительный человек. Ему надо не таверну содержать, а осведомителем быть при тайной канцелярии. Иногда кажется, что ему известно буквально все, что происходит в нашем городе. Даже жуть пробирает.";
	STR_TAVERNKEEPER[4] = "Не знаю, чего уж вам о нем сказать. Человек как человек. Содержит таверну, соответственно, в курсе всех новостей нашего острова.";
	STR_TAVERNKEEPER[5] = "Говорят, на него можно положиться. С другой стороны, я слышал, что он не любит ненужного риска и всегда расчетливо ведет свои дела. Да и темными делишками вроде не занимается.";
	STR_TAVERNKEEPER[6] = "Таверна досталась ему от отца. Его отец содержал таверну не так далеко отсюда, на небольшом острове Хайрок в другом архипелаге. Потом отец перебрался сюда, построил здесь новую таверну, и теперь в ней заправляет его сын.";
	
	string STR_SHIPYARDER[MAX_RUMOURS_ABOUT_OWNERS]; // Верфисты
	STR_SHIPYARDER[0] = "Корабли он строит неплохие... А как о человеке, о нем трудно что-либо сказать - он живет тихо и спокойно. Наверное, неплохой человек.";
	STR_SHIPYARDER[1] = "Корабли он строит неплохие... А как о человеке, о нем трудно что-либо сказать - он живет тихо и спокойно. Наверное, неплохой человек.";
	STR_SHIPYARDER[2] = "Неплохой человек, но говорят, что он излишне суров. Постоянно отчитывает всех работников. Поэтому они часто у него меняются. Правда, не смотря на это, корабел он превосходный.";
	STR_SHIPYARDER[3] = "Он очень образованный человек. Говорят, что он учился кораблестроению в Англии, потом в Голландии. А в конце концов оказался здесь - вдали от метрополии, в захолустном архипелаге\nГоворят, что он не поладил в свое время со Святой Инквизицией, и ему пришлось бежать в колонии.";
	STR_SHIPYARDER[4] = "Да, этот старик уже никуда не годится. Он постоянно грезит о прошедших временах, и ворчит, когда ему заказывают что-нибудь, кроме каравеллы или галеона.";
	STR_SHIPYARDER[5] = "Отличный парень. Всегда готов помочь, выручить из беды. Надо сказать, что и корабли для подобного захолустья он строит очень даже неплохие.";
	STR_SHIPYARDER[6] = "Он был ссыльным в нашей колонии, пока не оказалось, что у него талант к кораблестроению. После того, как под его руководством на верфях нашей колонии были построены два великолепных брига, ему простили его прегрешения, и теперь он - полноправный член нашего общества.";
	
	string STR_TRADER[MAX_RUMOURS_ABOUT_OWNERS]; // Магазинщики
	STR_TRADER[0] = "Ничего особенно плохого о нем сказать не могу. Добропорядочный житель, усердный прихожанин нашей церкви. Никогда не слышал, чтобы кто-нибудь хулил его или был на него обижен.";
	STR_TRADER[1] = "Он главный поставщик нашего губернатора, и это дает ему неплохой доход. Но дела он свои ведет честно. Ну, или пока ни в чем позорящем его замечен не был.";
	STR_TRADER[2] = "Этот толстяк пользуется заслуженным уважением в нашем городе. Товар у него всегда отменный, и я не припомню случая, чтобы он кого-нибудь обсчитал.";
	STR_TRADER[3] = "Непутевый он малый. Торгует-торгует, а толку никакого. То одних товаров нет, то других. И сам из долгов никак не вылезет.";
	STR_TRADER[4] = "Нехороший он человек, мсье. Говорят, он был помощником Болдуина Коффье, но разорил его и потом перекупил магазин. Не знаю, как насчет качества товаров, которые он продает, но как человек он мне весьма неприятен.";
	STR_TRADER[5] = "О! Это мерзкий человек, я бы не советовал вам иметь с ним никаких дел\nОн держит половину жителей нашего города в должниках! А товары, которые продаются у него в магазине всегда низкого качества.";
	STR_TRADER[6] = "Да никто о нем ничего толком и не знает. Он недавно сюда переселился, и сразу открыл свое дело. Торгует вроде честно, контрабанды не возит.";
	
	string sTempMayor = STR_MAYOR[iRumourNum];
	string sTempTavernkeper = STR_TAVERNKEEPER[iRumourNum];
	string sTempShipyarder = STR_SHIPYARDER[iRumourNum];
	string sTempTrader = STR_TRADER[iRumourNum];
	
	if(sOwnerType == "Mayor") return sTempMayor;
	if(sOwnerType == "TavernKeeper") return sTempTavernkeper;
	if(sOwnerType == "ShipYarder") return sTempShipyarder;
	if(sOwnerType == "Trader") return sTempTrader;
}

string GetDeviceLocation(ref npchar)
{
    aref	arCommon, arRld, arRld2;
    int	i, n, Qty, Qty2;
	string LocId; 
	string	storeArray [50];
	int howStore = 0;
    makearef(arRld, Locations[FindLocation(npchar.city + "_town")].reload);
	Qty = GetAttributesNum(arRld);
    if (CheckAttribute(pchar, "questTemp.jailCanMove.Deliver.locationId") || CheckAttribute(pchar, "GenQuest.SeekSpy.Location")) //если взят квест по доставке малявы или шпиона
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId && LocId != pchar.GenQuest.SeekSpy.Location)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != pchar.questTemp.jailCanMove.Deliver.locationId && LocId != pchar.GenQuest.SeekSpy.Location && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	else
	{
		for (i=0; i<Qty; i++)
		{
    		arCommon = GetAttributeN(arRld, i);
			LocId = arCommon.go;
    		if (findsubstr(LocId, "Common" , 0) != -1)
    		{			
				storeArray[howStore] = LocId;
				howStore++; 
			}
			if (arCommon.label != "Sea")
			{	
				makearef(arRld2, Locations[FindLocation(LocId)].reload);
				Qty2 = GetAttributesNum(arRld2);
				for (n=0; n<Qty2; n++)
				{
    				arCommon = GetAttributeN(arRld2, n);
					LocId = arCommon.go;
					if (findsubstr(LocId, "Common" , 0) != -1 && LocId != "CommonPackhouse_1" && LocId != "CommonPackhouse_2")
    				{
						storeArray[howStore] = LocId;
						howStore++; 					
					}
				}
			}	
		}
	}
	if (howStore == 0) return "none";
	LocId = storeArray[dRand(howStore-1)];
	SetOpenDoorCommonLoc(npchar.city, LocId); //открываем дверь
	for(n=0; n<MAX_CHARACTERS; n++)
	{
		if (CheckAttribute(&characters[n], "locations") && characters[n].locations == LocId) 
		{			
			characters[n].lifeDay = 0;
		}
	}
	return LocId;
}