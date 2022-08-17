// Джулия Смит, Дворецкий Джеральд
void ProcessDialogEvent()
{
	ref NPChar, sld, sld1;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		

		case "First time":
		if (pchar.quest.NSmithyQ == "Smithy_SanJuan_Dvoretsky")
		{
            	dialog.text = "О, " + GetAddress_Form(NPChar) + ", приветствую вас! Я Джеральд, дворецкий этого дома. Вы должно быть капитан " + GetAddress_Form(NPChar) + " "+ GetFullName(Pchar)+"?";
        	link.l1 = "Да, это я. Мне нужно поговорить с мистером Смитом. Могу я пройти?";
        	link.l1.go = "DvorJer 1";
		}
		else
		{
			int iPhrase_Quest_Smithy = rand(1);
			switch (iPhrase_Quest_Smithy)
			{
			case 0:
            		dialog.text = "Добро пожаловать в дом семьи Смит. Вы что-то хотели?";
        		link.l1 = "Ээээ... Нет, я так зашел" + GetSexPhrase("","а") + "...";
        		link.l1.go = "Exit";
			break;

			case 1:
            		dialog.text = "Прошу прощения " + GetAddress_Form(NPChar) + ", но Мистер и Миссис Смит в отъезде.";
        		link.l1 = "А кто это такие?! Хотя... Ладно...";
        		link.l1.go = "Exit";
			break;			
			}
		}
		break;

	case "Exit":
                NextDiag.CurrentNode = "Fist time";
		DialogExit();
		break;


	case "Second Time":
            	dialog.text = "Здравствуйте, " + GetAddress_Form(NPChar) + "!";
        	link.l1 = "";
        	link.l1.go = "Second Time Exit";
		break;

 	case "Second Time Exit":
                NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;




	case "23 At Cayman":
            	dialog.text = "Отец! Мама! Перестаньте! Не нужно ни кого убивать! Давайте просто разойдёмся, и все будут счастливо жить дальше?";
        	link.l1 = "Джулия права. Вам обоим нужно просто успокоиться. Ваша проблема решаема.";
        	link.l1.go = "23 Exit";
			Characters[GetCharacterIndex("David")].Dialog.CurrentNode = "26";
		break;

 		case "23 Exit":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
			sld=characterFromID("David");
			LAi_SetActorType(sld);
			Lai_ActorDialogNow(sld, Pchar, "",-1);
		break;


//**************** КОНЦОВКА №1 - УБИЙСТВО КЭРОЛ СМИТ *****************
//**************** КОНЦОВКА №2 - УБИЙСТВО ДЭВИДА СМИТА *****************
	case "24":
            	dialog.text = "";
        	link.l1 = "Джулия...";
        	link.l1.go = "25";
		break;

		case "25":
            	dialog.text = "Я... Я ожидала от вас иного, капитан. Я вас переоценила. Прошу меня простить...";
        	link.l1 = "";
        	link.l1.go = "25 End Quest";
		break;

 		case "25 End Quest":
                NextDiag.CurrentNode = "First Time";
		DialogExit();
	if (pchar.quest.NSmithyQ == "Carrol")
	{
		AddQuestRecord("Smithy", "16");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("David");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_6_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_7_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_8_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_9_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_10_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
	if (pchar.quest.NSmithyQ == "Smithy_Kill_David")
	{
		AddQuestRecord("Smithy", "17");
		CloseQuestHeader("Smithy");
		sld1=characterFromID("Carrol");
			LAi_SetActorType(sld1);
			LAi_ActorRunToLocator(sld1, "reload", "sea", "Smithy 31", -1);
		sld=characterFromID("July");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_1_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_2_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_3_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_4_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
		sld=characterFromID("Quest_Smithy_Pirat_5_Sho");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, sld1, "", -1);
	}
		break;


//**************** КОНЦОВКА №3 - УБИЙСТВО ВСЕХ *****************
	case "26":
            	dialog.text = "Вы, вы чудовище! Что вы наделали! Кровожадное, мерзкое чудовище! Нет, вы так с этим не уйдёте! Получайте, монстр!!!";
        	link.l1 = "Что?! Да вы шутите! Эй! Эй! Стоп! Подожди! Чёрт! Ах ты, чертовка...";
        	link.l1.go = "26 End Quest";
		break;

 		case "26 End Quest":
                                      //NextDiag.CurrentNode = "First Time";
		DialogExit();
		DoQuestFunctionDelay("GothicSmithy_KillSmithyJuly", 3.0);
		break;



	case "27":
            	dialog.text = "Кхаргкх... А-а-а...";
        	link.l1 = "О, Боже! Джулия!!!";
        	link.l1.go = "27 End Quest";
	break;

 	case "27 End Quest":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	LAi_KillCharacter(characterFromID("July"));
	LAi_SetPlayerType(pchar);
	sld=characterFromID("Carrol");
	Characters[GetCharacterIndex("Carrol")].Dialog.CurrentNode = "17";
	LAi_SetActorType(sld);
	Lai_ActorDialogNow(sld, Pchar, "",-1);
	break;







	}
}


