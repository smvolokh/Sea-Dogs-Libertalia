
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	int i, iTemp;
                    float locx, locy, locz;
	string sTemp,sTemp1, str, str1;
	int	s1,s2,s3,s4,s5,p1,iColony;
	string attrName;
                    string attrLoc;
                    attrLoc   = Dialog.CurrentNode;
  
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
	                                PlaySound("VOICE\Russian\Isabella04.wav");
			dialog.text = "Я тронута вашим вниманием?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";

			
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toAnna")// квест, донна Анна в резиденции
            {
    			dialog.text = "Вас прислал Генерал Ли?";
    			link.l1 = "Да, мадам. Чем могу быть полез"+ GetSexPhrase("ен","на") +"?";
    			link.l1.go = "Gothic_2_1";
            }

			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_toHavana")
            {
    			dialog.text = "Рассказывайте, сеньор"+ GetSexPhrase("","ита") +", что вы узнали?";
    			link.l1 = "Пока ничего. Но я занимаюсь этим делом, не беспокойтесь, мадам...";
    			link.l1.go = "exit";
            }
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_SeekHoseBrothers")
            {
    			dialog.text = "Рассказывайте, сеньор"+ GetSexPhrase("","ита") +", что вы узнали?";
    			link.l1 = "Пока ничего. Но я занимаюсь этим делом, не беспокойтесь, мадам...";
    			link.l1.go = "exit";
            }

			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "GothicLeeAnnaHant_GoodWork")// квест, донна Анна после выполнения задачи
            {
				dialog.text = NPCStringReactionRepeat("Сеньор"+ GetSexPhrase("","ита") +", вы уже второй раз спасаете мою жизнь. Знайте, что в моем лице вы обрели верного друга.",
					         "Здравствуйте снова, капитан. Рада вас видеть.", "И еще раз здравствуйте капитан...", "Который раз на дню: здравствуйте, капитан...", "block", 0, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Сеньора, совершенно случайно близ Гаваны мне встретились два кастильских дворянина, и знали бы вы, как они о вас выражались... По всему видать, донна Анна, что память о вас бережно хранится в Кастилии.", 
					      "И я вас рад"+ GetSexPhrase("","а") +" видеть так же.", "И еще раз я рад"+ GetSexPhrase("","а") +" вас видеть...", "Здравствуйте, сеньора...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("Gothic_2_8", "none", "none", "none", npchar, Dialog.CurrentNode);

            }
			if (npchar.id == "AnnaDeLeiva" && pchar.questTemp.GothicLee == "empty")// квест, донна Анна после выполнения задачи
            {
				dialog.text = NPCStringReactionRepeat("Сеньор"+ GetSexPhrase("","ита") +", вы уже второй раз спасаете мою жизнь. Знайте, что в моем лице вы обрели верного друга.",
					         "Здравствуйте снова, капитан. Рада вас видеть.", "И еще раз здравствуйте капитан...", "Который раз на дню: здравствуйте, капитан...", "block", 0, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("Сеньора, совершенно случайно близ Гаваны мне встретились два кастильских дворянина, и знали бы вы, как они о вас выражались... По всему видать, донна Анна, что память о вас бережно хранится в Кастилии.", 
					      "И я вас рад"+ GetSexPhrase("","а") +" видеть так же.", "И еще раз я рад"+ GetSexPhrase("","а") +" вас видеть...", "Здравствуйте, сеньора...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("Gothic_2_8", "none", "none", "none", npchar, Dialog.CurrentNode);
            }

		break;
		
		case "AnnaDeLeiva":
	                                               PlaySound("VOICE\Russian\Isabella02.wav");
				dialog.text = "Есть некоторые вопросы, которые мне бы хотелось с вами обсудить. Я даже не знаю как вас отблагодарить?";
				link.l1 = "Ну, ты бы могла быть по ласковее со мной, как женщина?";
				link.l1.go = "AnnaDeLeivaSex";
				link.l2 = "Правда, не стоит, я просто помог своему старому другу...";
				link.l2.go = "exit1";
				break;

		case "exit1":
				dialog.text = "Вы такой благородный?";
				link.l1 = "О, да...";
				link.l1.go = "exit";
				break;				
								
		case "AnnaDeLeivaSex":
 	                                PlaySound("VOICE\Russian\gotica\GG\YES_00.wav");
			dialog.text = "Ну ты и хам, и это всё...? Хорошо давай только по тихому, чтоб Ли не слышал?";
			link.l1 = "Да...! Ну иди же ко мне моя королева.";
			link.l1.go = "AnnaDeLeivaSex_Yes";
		break;

        case "AnnaDeLeivaSex_Yes":
			sld = CharacterFromID("AnnaDeLeiva");
			LAi_SetActorType(sld);
			LAi_ActorTurnToCharacter(sld, pchar);
            pchar.GenQuest.BrothelCount = 0;
            AddCharacterExpToSkill(pchar, "Leadership", 100);
            AddCharacterExpToSkill(pchar, "Fencing", -50);// утрахала
            AddCharacterExpToSkill(pchar, "Pistol", -50);
            AddCharacterHealth(pchar, 10);
            ChangeCharacterComplexReputation(pchar, "nobility", 1);

   			AddDialogExitQuest("PlaySex_1");
			NextDiag.CurrentNode = "AnnaDeLeivaLife_afterSex";
			DialogExit();
        break;


        case "AnnaDeLeivaLife_afterSex":
			dialog.text = "О...о да, какой, м.... теперь мы в расчете?";
			link.l1 = "Согласен?";
			link.l1.go = "exit";
        break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

//********************************* Похищение донны Анны. Квест №3 **********************************

 		case "AnnaDeLeiva_TakeAnna":
    			dialog.text = "Боже! Что случилось? Вы прибыли от Генерала Ли? Что это был за шум?";
    			link.l1 = "Сударыня, не знаю, печальные это для вас новости или нет, но я вынужден"+ GetSexPhrase("","а") +" был"+ GetSexPhrase("","а") +" убить вашего супруга. У нас нет времени на переживания и обмороки, нужно немедленно бежать! Генерал Ли в Сент-Луи ждет вас.";
    			link.l1.go = "Gothic_1";
		break;

 		case "Gothic_1":
			dialog.text = "Хосе мертв... Видит Господь, я этого не хотела... Он нашел письмо, которое я писала ему, и запер меня здесь...";
			link.l1 = "Я знаю, сеньора, догадал"+ GetSexPhrase("ся","ась") +"... Я прошу вас следовать за мной. Будьте внимательны, сударыня...";
			link.l1.go = "Gothic_2";
		break;
 		case "Gothic_2":
			pchar.questTemp.GothicLee = "GothicLeeTakeAnna_HavanaOut";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1 = "location";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition.l1.location = "Cuba2";
			Pchar.quest.GothicLeeTakeAnna_DelivShip.win_condition = "GothicLeeTakeAnna_DelivShip";
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			DialogExit();
		break;

 		case "Gothic_2_1":
			dialog.text = "Я получила письмо из Гаваны от моей подруги Инес де лас Сьеррас. Генерал-губернатор Гаваны предпринял расследование смерти моего мужа и убежден, что в этом повинна я. Ах, так оно и есть! Но мои соотечественники замыслили месть, мне грозит гибель или похищение, и я не знаю, что страшнее.\n"+
				          "Судар"+ GetSexPhrase("ь","ыня") +", я прошу вас отправиться в Гавану и выяснить, насколько это серьезно.";
			link.l1 = "Мадам, вы можете рассчитывать на меня.";
    		link.l1.go = "exit";
    		pchar.questTemp.GothicLee = "GothicLeeAnnaHant_toHavana";
			AddQuestRecord("GothicLee_2_KillAnnaHanters", "2");			
			sld = GetCharacter(NPC_GenerateCharacter("InesDeLasCierras", "Womens_8", "woman", "woman", 10, SPAIN, -1, false, "soldier"));
			sld.Dialog.Filename = "Gothic_Quest\GothicLine\Line_2.c";
			sld.name = "Инес";
			sld.lastname = "де Лас Сьеррас";
			sld.greeting = "";
			LAi_SetCitizenType(sld);
		                     LocatorReloadEnterDisable("Havana_houseSp2", "reload3", true);
			ChangeCharacterAddressGroup(sld, "Havana_houseSp2", "goto","goto2");
		break;

 		case "Gothic_2_8":
			dialog.text = "От такого рода почитания я бы с удовольствием отказалась.";
			link.l1 = "Вам ничего более не грозит, поверьте мне. Я сумел"+ GetSexPhrase("","а") +" переубедить этих храбрых кастильцев...";
    		link.l1.go = "Gothic_2_9";
		break;
 		case "Gothic_2_9":
			dialog.text = "Ах, сеньор"+ GetSexPhrase("","ита") +" " + pchar.name + ", как я могу отблагодарить вас?";
			link.l1 = "Донна Анна, я прошу вас заботиться о Генерале Ли, он того заслуживает.";
    		link.l1.go = "Gothic_2_10";
			link.l2 = "Донна Анна, вы такая очеровательная, может продолжем по тихому.";
    		link.l2.go = "AnnaDeLeivaSex_2";
		break;
 		case "Gothic_2_10":
			dialog.text = "Непременно исполню вашу просьбу, о душевном здоровье Ли вы можете более не переживать.";
			link.l1 = "Мадам, вы оказали всем флибустьерам огромную услугу. Полагаю, мы в расчете.";
    		link.l1.go = "exit";
		//npchar.LifeDay = 0;
		break;

		case "AnnaDeLeivaSex_2":
 	                     PlaySound("VOICE\Russian\gotica\GG\YES_00.wav");
		dialog.text = "И от куда вы все взялись на мою голову...? Хорошо, в последний раз и чтоб Ли не слышал?";
			link.l1 = "Ну, разумеется, иди же ко мне на ручки.";
			link.l1.go = "AnnaDeLeivaSex_Yes";
		break;


	}
}