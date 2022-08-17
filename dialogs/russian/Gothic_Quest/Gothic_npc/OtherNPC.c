// диалог прочих НПС по готической саге
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Ты что-то хотел?";
			link.l1 = "Да нет, пожалуй, ничего.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;

//---------------------------------------------Торус перед Маяком------------------------------------

                                                          case "Torus_MayakDieenemy":
			dialog.text = "Ты как раз вовремя. Должна подойти Чани, в месте и выдвинемся на охоту. Женщины всегда опаздывают, похоже индианки не исключение!";
			link.l1 = "Хорошо, ждём её...";
			link.l1.go = "Torus_MayakDieenemy_1";
  		                   break;

                                                         case "Torus_MayakDieenemy_1":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "Torus_Mayak_Dieenemy":
			dialog.text = "А где основной демон?";
			link.l1 = "Скорее всего он на маяке от туда хорошо видно поле боя...";
			link.l1.go = "Torus_Mayak_Dieenemy_1";
  		                   break;

                                                          case "Torus_Mayak_Dieenemy_1":
			dialog.text = "Хорошо, пойду покараулю вход маяка, вспомню свои старые обязанности. А ты передай Скипу и Фиску, пусть идут домой, отдыхать они это заслужили, а с этим демоном мы справимся вдвоём!";
			link.l1 = "Хорошо, передам...";
			link.l1.go = "Torus_Mayak_Dieenemy_2";
  		                   break;

                                                         case "Torus_Mayak_Dieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
                                                          sld = characterFromId("Torus");
                                                          LAi_SetActorType(sld);
                                                          LAi_ActorGoToLocation(sld, "officers", "reload5_1", "Dominica_Lighthouse_02", "officers", "reload5_1", "", 50.0);

		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;

                                                          case "Torus_Mayak":
 	                                       PlaySound("VOICE\Russian\GOTHIC\GG\GG_54.wav");
			dialog.text = "";
			link.l1 = "Ну да, либо это, либо ты станешь трупом!";
			link.l1.go = "Torus_Mayak_1";
  		                   break;

                                                          case "Torus_Mayak_1":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_01.wav");
			dialog.text = "Значит ты нанёс Белиару неплохой удар?";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_2";
  		                   break;

                                                          case "Torus_Mayak_2":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_02.wav");
			dialog.text = "Теперь ты пойдёшь дальше?";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_3";
  		                   break;

                                                          case "Torus_Mayak_3":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_15_03.wav");
			dialog.text = "";
			link.l1 = "Мои дела в далине закончены, я могу отдохнуть несколько дней!";
			link.l1.go = "Torus_Mayak_4";
  		                   break;

                                                          case "Torus_Mayak_4":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_04.wav");
			dialog.text = "Ха, да, ты постоянно куда - то движешься, так ведь? Счасливого тебе пути!";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_5";
  		                   break;

                                                          case "Torus_Mayak_5":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_15_05.wav");
			dialog.text = "";
			link.l1 = "Кто знает, может наши пути ещё пересекутся.";
			link.l1.go = "Torus_Mayak_6";
  		                   break;

                                                          case "Torus_Mayak_6":
 	                                       PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10014_THORUS_RAVENTOT_12_06.wav");
			dialog.text = "Кто знает, у тебя на пути будет много ворот и много переходов, и на одном из них ты можешь встретить меня!";
			link.l1 = "";
			link.l1.go = "Torus_Mayak_7";
  		                   break;

                                                         case "Torus_Mayak_7":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   AddDialogExitQuestFunction("MayakDieenemy_25");
  		                   break;

		
//---------------------------------------------Скип перед Маяком------------------------------------

                                                          case "SKIP_MayakDieenemy":
			dialog.text = "Ты как раз вовремя.";
			link.l1 = "Скип, надеюсь ты понимаешь куда идешь?";
			link.l1.go = "SKIP_MayakDieenemy_1";
  		                   break;

                                                          case "SKIP_MayakDieenemy_1":
			dialog.text = "Я не боюсь демонов, по сравнению с орками - это забава, и к тому же хочу отомстить за Розиту. Торус сказал, там их немного...";
			link.l1 = "Да это так, легкая прогулка?";
			link.l1.go = "SKIP_MayakDieenemy_2";
  		                   break;

                                                         case "SKIP_MayakDieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy":
			dialog.text = "Я думал их гораздо меньше будет, мне показалось или нет, похоже там были орки?";
			link.l1 = "Нет, тебе не показалось!";
			link.l1.go = "SKIP_Mayak_Dieenemy_1";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_1":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_ADD_08_01.wav");
			dialog.text = "Орки, ненавижу этих тварей.";
			link.l1 = "";
			link.l1.go = "SKIP_Mayak_Dieenemy_2";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_2":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_GOHOME_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты мне больше не нужен!";
			link.l1.go = "SKIP_Mayak_Dieenemy_3";
  		                   break;

                                                          case "SKIP_Mayak_Dieenemy_3":
 	                                       PlaySound("VOICE\Russian\gotica\SKIP\DIA_ADDON_SKIP_GOHOME_08_01.wav");
			dialog.text = "Что ж, мы неплохо прогулялись, если, что ты можешь найти меня в лагере. Теперь я могу спать спокойно, за смерть Розиты я отомстил.";
			link.l1 = "";
			link.l1.go = "SKIP_Mayak_Dieenemy_4";
  		                   break;

                                                         case "SKIP_Mayak_Dieenemy_4":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;

//---------------------------------------------Фиск перед Маяком------------------------------------

                                                          case "FISK_MayakDieenemy":
			dialog.text = "Ты как раз вовремя.";
			link.l1 = "Решил вспомнить, старый лагерь за барьером?";
			link.l1.go = "FISK_MayakDieenemy_1";
  		                   break;

                                                          case "FISK_MayakDieenemy_1":
			dialog.text = "Нет, просто решил помочь Торусу, заодно и размяться.";
			link.l1 = "Похвально?";
			link.l1.go = "FISK_MayakDieenemy_2";
  		                   break;

                                                         case "FISK_MayakDieenemy_2":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.RoseauCharlotteMayakDieenemy = sti(pchar.questTemp.RoseauCharlotteMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.RoseauCharlotteMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_1");
		                   }
  		                   break;

                                                          case "FISK_Mayak_Dieenemy":
			dialog.text = "";
			link.l1 = "Остался один демон, скорее всего он на маяке...";
			link.l1.go = "FISK_Mayak_Dieenemy_1";
  		                   break;

                                                          case "FISK_Mayak_Dieenemy_1":
 	                                       PlaySound("VOICE\Russian\gotica\FISK\DIA_ADDON_FISK_ABOUTJUAN_12_03.wav");
			dialog.text = "Ты оставил эту тварь в живых?";
			link.l1 = "Успокойся, с ним мы разберемся позже вместе с Торусом, а ты можешь возвращаться домой.";
			link.l1.go = "FISK_Mayak_Dieenemy_2";
  		                   break;

                                                          case "FISK_Mayak_Dieenemy_2":
 	                                       PlaySound("VOICE\Russian\gotica\FISK\DIA_ADDON_FISK_SIEG_12_03.wav");
			dialog.text = "А если, вдруг понадобиться чего, ты знаешь где меня искать? За Шарлотту я отомстил сполна, пусть спит спокойно.";
			link.l1 = "";
			link.l1.go = "FISK_Mayak_Dieenemy_3";
  		                   break;

                                                         case "FISK_Mayak_Dieenemy_3":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   pchar.questTemp.ChaniMayakDieenemy = sti(pchar.questTemp.ChaniMayakDieenemy)+1;
		                   if (sti(pchar.questTemp.ChaniMayakDieenemy) == 3) 
		                   {
		                   AddDialogExitQuestFunction("MayakDieenemy_18");
		                   }
  		                   break;


//************Мистер и Миссис Смит ****************************************

//************************ Августа ****************************************

		case "Augusta":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUDISTURBEDMYSLUMBER.wav");
            	                  dialog.text = "В чём дело?";
        	                  link.l1 = "";
        	                  link.l1.go = "Augusta_1";
		break;

		case "Augusta_1":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_WHATDIDYOUDOINTHERE.wav");
            	                  dialog.text = "Что тебе здесь надо - а?";
        	                  link.l1 = "";
        	                  link.l1.go = "Augusta_2";
		break;

		case "Augusta_2":
 	                   PlaySound("VOICE\Russian\GOTHIC\GG\HALLO_KILL.wav");
             	                   dialog.text = "";
        	                   link.l1 = "Я пршёл убить тебя?";
        	                   link.l1.go = "Augusta_3";
		break;

		case "Augusta_3":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_HELP.wav");
             	                   dialog.text = "Помогите...";
        	                   link.l1 = "";
        	                   link.l1.go = "Augusta_4";
		break;

		case "Augusta_4":
 	                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_KILLMURDERER.wav");
             	                   dialog.text = "Умри убийца.";
        	                   link.l1 = "";
        	                   link.l1.go = "Augusta Fight";
		break;

 		case "Augusta Fight":
                                      NextDiag.CurrentNode = "Fist time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_TavernAugusta");
		break;


//************Пираты (2шт) на пирсе Саванна-ла-Мар ****************************************

		case "Pirat":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_06_00.wav");
            	                   dialog.text = "Эй ты стоять, тебя зовут "+ GetFullName(Pchar)+"?";
        	                   link.l1 = "";
        	                   link.l1.go = "Pirat 1";
		break;

		case "Pirat 1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_7.wav");
            	                   dialog.text = "";
        	                   link.l1 = "Ха, я, нет...";
        	                   link.l1.go = "Pirat Fight";
		break;

 		case "Pirat Fight":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1014_BANDIT_KILLER_06_00.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Smithy_piratFight");
		break;


// ********************* Матрос (на Мартинике) ******************************

		case "Sailor_coast":
                                      PlaySound("VOICE\Russian\GOTHIC\SAILOR\SAILOR_30.wav");
			dialog.text = "Кэп! Слава Богу, вы живы!  Мы с ребятами прочесали пол острова, но не нашли ваших следов.\nЯ так рад, что нашёл вас капитан, да и команда будет рада видеть вас в... эм... отличной форме! Пройдемте на борт, а, кэп?";
			link.l1 = "Боже правый! Я тоже рад тебя видеть матрос! Но что с нашим судном?";
			link.l1.go = "Sailor_coast_1";
		break;

		case "Sailor_coast_1":
			dialog.text = "Всё в порядке, кэп! Мы отбились. Те, на кого мы напали. Крутые ребята, скажу я вам, кэп. Многих наших порубили в капусту, эх...\nНу они позволили нам уйти, сказали, что кэп ваш мёртв отпустили нас, мы быстренько сняли крюки и отцепились! И они уплыли, кэп!\nА мы быстренько залатали пару дырочек и взяли курс до пляжа Ламантен.\nМы не поверили им о вашей гибели и отправили один отряд в джунгли, а другой - в город на ваши поиски. И вот я нашёл вас, кэп! Слава Богу кэп вы живы!!!";
			link.l1 = "Что ж, в конце концов всё закончилось хорошо. Я горжусь своей командой.";
			link.l1.go = "Sailor_coast_Exit";
		break;

		case "Sailor_coast_Exit":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_29.wav");
                                      NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_SmithySeaShore");
		break;
	// ********************* Эшли друг Смитов ******************************

	case "Smithy_KarSec": 
                   PlaySound("VOICE\Russian\HeadPirate02.wav");
            	dialog.text = "Ты не ошибся адресом, капитан?";
        	link.l1 = "...";
        	link.l1.go = "Smithy_KarSec_1";
		break;

	case "Smithy_KarSec_1": 
	PlaySound("VOICE\Russian\GOTHIC\GG\AUFSMAUL.wav");
            	dialog.text = "...";
        	link.l1 = "Слушай, а что у тебя пред головой, лицо или задница.";
        	link.l1.go = "Smithy_KarSec_2";
	break;

 	case "Smithy_KarSec_2":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_July_1");
	break;

	case "Smithy_KarSec_3": 
                    PlaySound("VOICE\Russian\HeadPirate01.wav");
            	dialog.text = "Некогда мне тут с тобой распинаться, дела ждут...";
        	link.l1 = "...";
        	link.l1.go = "Smithy_KarSec_4";
	break;

	case "Smithy_KarSec_4": 
            	dialog.text = "Да, Джулия, я знаю этого человека и с ним я хочу продолжить беседу этажом ниже. Надеюсь сударь вы будите не против?";
        	link.l1 = "Ну, что вы о чём речь, сударь после вас.";
        	link.l1.go = "Smithy_KarSec_5";
	break;

 	case "Smithy_KarSec_5":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_KarSecExit");
	break;
// ********************* Джулия Смит ******************************

	case "Smithy_July": 
                   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_YOUDISTURBEDMYSLUMBER.wav");
            	dialog.text = "В чём дело?";
        	link.l1 = "...";
        	link.l1.go = "July_1";
		break;

	case "July_1": 
                    PlaySound("VOICE\Russian\GOTHIC\CRIME_W\CRIME_W_6.wav");
            	dialog.text = "Что тебе здесь надо - а...";
        	link.l1 = "...";
        	link.l1.go = "July_2";
		break;

	case "July_2": 
                    PlaySound("VOICE\Russian\GOTHIC\GG_RUMOURS\Rumours_25.wav");
            	dialog.text = "...";
        	link.l1 = "Расслабься, я просто хочу поговорить о твоих родителях. У меня есть новости.";
        	link.l1.go = "July_3";
		break;

	case "July_3":
            	dialog.text = "Что с ними? И, чем я могу помочь?";
        	link.l1 = "Им обоим грозит опасность.";
        	link.l1.go = "July_4";
		break;

	case "July_4":
            	dialog.text = "Об этом мне известно. Но я тебя не знаю, чтобы обсуждать семейные дела, поэтому прошу покинуть мой дом.";
        	link.l1 = "...";
        	link.l1.go = "July_5";
		break;

	case "July_5":
                    PlaySound("VOICE\Russian\GOTHIC\GG\MOMENT.wav");
            	dialog.text = "...";
        	link.l1 = "Подожди секундочку.";
        	link.l1.go = "July_Exit";
		break;

 	case "July_Exit":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_10");
		break;

	case "July_6":
            	dialog.text = "Эшли, ты знаешь этого человека?";
        	link.l1 = "...";
        	link.l1.go = "July_6_Exit";
		break;

 	case "July_6_Exit":
                    NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_KarSec_3");
		break;


	case "July_7":
                   PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_17.wav");
            	dialog.text = "Бог мой, какая жестокость. Я всё слышала не надо громких слов по поводу гибели моего друга. Меня зовут Джулия Говард, хотя на самом деле я Смит, но это неважно... слишком длинная история\nМожете звать меня просто Джулия. Спрашивайте, я постараюсь ответить на твои вопросы?";
        	link.l1 = "Хорошо, мне необходимо знать, где они могут быть, их местонахождение и постараться помочь. Ваш отец предложил мне фантастические деньги и, в самом начале, не давал никаких подробностей дела. Я принял" + GetSexPhrase("","а") + " его предложение, так как получаю подобные не каждый день. Надеюсь, вы меня понимаете.";
        	link.l1.go = "July_8";
		break;

	case "July_8":
            	dialog.text = "Я понимаю вас. А главное не виню. Если кто-то и виноват во всей этой истории, так это я.";
        	link.l1 = "Простите? Вы? А вы-то здесь причем?";
        	link.l1.go = "July_9";
		break;

		case "July_9":
            	dialog.text = "Ну а как же вы думали. Отец хотел, чтобы я поехала в Европу и поступила там в университет. Мама хотела, чтобы я приняла их дело и стала новой управляющей сетью\nИ ещё множество других разногласий. И все они, чаще всего, возникали из-за меня. А в результате я оскорбила их обоих, я не то что не пыталась помочь им помириться - я назвала их обоих старыми психопатами и попросила моего друга, Эшли, капитана, как и вы, увезти меня подальше от них\nЯ люблю рисовать, я могла бы стать художницей, а Эшли, как и мой отец, отличный предприниматель, он мог бы сделать из моего увлечения - дело. Точнее он был им... пока вы не убили его. Моя мама использовала его в своих грязных целях. Сумасшедшая, ненормальная, безумная старуха\nМеня заперли в этом доме и она сказала, что я не должна принимать никаких решений в её тайных делах... Ладно, мы отвлеклись от темы\nВсё это очень грустно, но сейчас я ещё могу что-то изменить. С вашей помощью. Или же станет ещё грустнее. Вы поможете мне, а я вам?";
        	link.l1 = "Вы не должны ни в чём винить себя. Ваши родители не правы, а вы делали всё, что могли, чтобы помочь им. Поэтому я готов и хочу помочь вам, но мне нужно знать где они могут быть?";
        	link.l1.go = "July_10";
		break;

		case "July_10":
            	dialog.text = "У них встреча. На необитаемом острове, Исла-Мона в бухте Вьекес. Что-то вроде дуэли. Я не знаю, что они там собираются делать, но я уверена, что добром это не кончится\nОни ненавидят друг друга и они абсолютно безумны. Каждый хочет избавиться от другого и единолично владеть всеми доходами и капиталами. Мы с вами должны отправиться туда и помешать им совершить безумие! Мы должны остановить их!";
        	link.l1 = "Но... как вы собираетесь остановить их? Вы ведь сами сказали, что они абсолютно безумны, а с их возможностями, это была, есть и будет, в прямом смысле слова - настоящая война. И как вы хотите закончить её без потерь?";
        	link.l1.go = "July_11";
		break;

		case "July_11":
            	dialog.text = "Я не знаю! Поэтому мне и нужна ваша помощь! Вы опытнее меня в такого рода делах, вы " + GetSexPhrase("мужчина","женщина") + ", вы человек со стороны, но уже довольно хорошо понявший ситуацию\nЯ не знаю! Но мы обязаны это сделать! Если вы поможете мне, я уверена, что каждый участник истории щедро отблагодарит вас! Я щедро отблагодарю вас капитан!";
        	link.l1 = "Что ж... я не против.";
        	link.l1.go = "July_12";
		break;

		case "July_12":
            	dialog.text = "Вот координаты этого острова и прошу вас подождите меня в низу, мне необходимо переодеться и я проследую за вами на ваш корабль?";
        	link.l1 = "Так мы отправляемся?";
        	link.l1.go = "July_13";
		break;

		case "July_13":
                   PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_4.wav");
            	dialog.text = "Умный мальчик! Скорее на Исла-Мону!";
        	link.l1 = "Тогда прошу на борт, молодая леди!";
        	link.l1.go = "July_14_Exit";
		break;

 	case "July_14_Exit":
                     AddQuestRecord("Gothic_Smithy", "15");
                     NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_12");
		break;

		case "July_15":
            	dialog.text = "Я готова!";
        	link.l1 = "Ну тогда в перёд, молодая леди!";
        	link.l1.go = "July_15_Exit";
	break;

 	case "July_15_Exit":
                     NextDiag.CurrentNode = "First time";
	DialogExit();
	AddDialogExitQuestFunction("Gothic_SmithyBeliz_15");
	break;

	case "23 At Cayman":
            	dialog.text = "Отец! Мама! Перестаньте! Не нужно ни кого убивать! Давайте просто разойдёмся, и все будут счастливо жить дальше?";
        	link.l1 = "Джулия права. Вам обоим нужно просто успокоиться. Ваша проблема решаема.";
        	link.l1.go = "23 Exit";
	Characters[GetCharacterIndex("SmithyDavid")].Dialog.CurrentNode = "26";
	break;

 	case "23 Exit":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	sld=characterFromID("SmithyDavid");
	LAi_SetActorType(sld);
	Lai_ActorDialogNow(sld, Pchar, "",-1);
	break;

	case "27":
                    PlaySound("People Fight\Afraid_death_woman_03.wav");
            	dialog.text = "Кхаргкх... А-а-а...";
        	link.l1 = "О, Боже! Джулия!";
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

//**************** КОНЦОВКА №3 - УБИЙСТВО ВСЕХ *****************
	case "26":
            	dialog.text = "Вы, вы чудовище! Что вы наделали! Кровожадное, мерзкое чудовище! Нет, вы так с этим не уйдёте! Получайте, монстр!";
        	link.l1 = "Что?! Да вы шутите! Эй! Эй! Стоп! Подожди! Чёрт! Ах ты, чертовка...";
        	link.l1.go = "26 End Quest";
		break;

 	case "26 End Quest":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	AddDialogExitQuestFunction("GothicSmithy_KillSmithyJuly");
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
	AddDialogExitQuestFunction("GothicSmithy_KillCarrol");
	break;

	case "24_0":
            	dialog.text = "";
        	link.l1 = "Джулия...";
        	link.l1.go = "25_0";
	break;

	case "25_0":
            	dialog.text = "Я... Я ожидала от вас иного, капитан. Я вас переоценила. Прошу меня простить...";
        	link.l1 = "";
        	link.l1.go = "25_0 End Quest";
	break;

 	case "25_0 End Quest":
                     NextDiag.CurrentNode = "First Time";
	DialogExit();
	AddDialogExitQuestFunction("GothicSmithy_KillSmithyDavid");
	break;


		// командир абордажников по Аскольду
		case "seashore_officer":
			dialog.text = "Ждем ваших приказаний, капитан!";
			link.l1 = "Выдвигаемся в глубь джунглей в поисках испанской экспедиции. В случае опасности - атакуете.";
			link.l1.go = "seashore_officer_1";
		break;

		case "seashore_officer_0":
			dialog.text = "Ждем ваших приказаний, капитан!";
			link.l1 = "Выдвигаемся в глубь джунглей в поисках испанской экспедиции. В случае опасности - атакуете.";
			link.l1.go = "seashore_officer_1";
		break;
				
		case "seashore_officer_1":
			dialog.text = "Есть, капитан!";
			link.l1 = "Хорошо. Вперед!";
			link.l1.go = "seashore_officer_2";
		break;
		
		case "seashore_officer_2":
			DialogExit();
			chrDisableReloadToLocation = false;
			locations[FindLocation("Beliz_jungle_02")].DisableEncounters = true; //энкаутеры закрыть

			for(i=2; i<=4; i++)
			{
				locations[FindLocation("Beliz_Jungle_0"+i)].DisableEncounters = true; //энкаутеры закрыть
			}
			LocatorReloadEnterDisable("Shore9", "boat", true);
			for(i=1; i<=iTotalTemp; i++)
			{
				sld = characterFromID("Temple_Oursoldier_"+i);
				LAi_SetActorType(sld);
				LAi_ActorFollowEverywhere(sld, "", -1);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			// на локацию перед пирамидой
			pchar.quest.Temple_seashore_officer.win_condition.l1 = "location";
			pchar.quest.Temple_seashore_officer.win_condition.l1.location = "Tenotchitlan_Jungle_02";
			pchar.quest.Temple_seashore_officer.function = "Temple_officerGoJungle";

		break;

//---------------------------------------------Месть корсара------------------------------------

		// Билли Сипатый
		case "Billy":
			PlaySound("VOICE\Russian\citizen\Moryaki v Gorode-10.wav");
                                                      dialog.text = "Поглоти меня акула, если на 'Летучей рыбе' такое случалось за последний год... у меня на палубе - гость! Опять ты?";
			link.l1 = "Приветствую! Это снова я Билли?";
			link.l1.go = "Billy_1";
		break;

		case "Billy_1":
                                                      dialog.text = "Что случилось на сей раз?";
			link.l1 = "Слышал в Порт - Рояле взяли банк?";
			link.l1.go = "Billy_2";
		break;

		case "Billy_2":
                                                      dialog.text = "Это не мудрено, давно пора это сделать?";
			link.l1 = "Да, полностью с тобой согласен? На этот банк мне плевать, я даже знаю кто это сделал, я вот, что хочу спросить, может в какой - нибудь бухты ты видел корабль на приколе.";
			link.l1.go = "Billy_3";
		break;

		case "Billy_3":
                                                      dialog.text = "Видел, и не один а два корабля у бухты Аннотто-Бей пару недель назад.";
			link.l1 = "Что за корабли? Удалось рассмотреть?";
			link.l1.go = "Billy_4";
		break;

		case "Billy_4":
                                                      dialog.text = "Да чёрт возми, укуси меня селёдка... Один корвет 'Грифон', другой военный корабль 'Красный дракон'. Долго они стояли на приколе, но потом подошёл линейный корабль 'Ужасающий' и началось там такое... Крики, выстрелы. А когда рассвело, корвета среди них уже небыло, как пить потопили...";
			link.l1 = "Спасибо за рассказ приятель? А ты не думал из баркасов сделать флот?";
			link.l1.go = "Billy_5";
		break;

		case "Billy_5":
                                                      dialog.text = "Хочешь подогнать ещё один?";
			link.l1 = "Ээ, нет, ладно удачной рыбалки?";
			link.l1.go = "exit";
		                 AddDialogExitQuestFunction("Gothic_RevengeCorsair_5");
		break;

//************Пираты (2шт) в доме Порт Рояла ****************************************

		case "RevengeCorsair_Pirat":
 	                   PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_06_00.wav");
            	                   dialog.text = "Эй ты стоять, тебя зовут "+ GetFullName(Pchar)+"?";
        	                   link.l1 = "";
        	                   link.l1.go = "RevengeCorsair_Pirat_1";
		break;

		case "RevengeCorsair_Pirat_1":
                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_7.wav");
            	                   dialog.text = "";
        	                   link.l1 = "Ха, я, нет...";
        	                   link.l1.go = "RevengeCorsair_Pirat_Fight";
		break;

 		case "RevengeCorsair_Pirat_Fight":
 	                  PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1014_BANDIT_KILLER_06_00.wav");
                                    NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_8");
		break;


//************Капитан Тиракса на море ****************************************

		case "Terrax_abordage":
                        dialog.text = "Извини, Барон, приказ Тиракса никого не подпускать на пушечный выстрел.";
			link.l1 = "Что случилось, где он?";
			link.l1.go = "Terrax_abordage_2";
		break;

		case "Terrax_abordage_2":
                        dialog.text = "...";
			link.l1 = "Говори, или я пущу это корыто в месте с тобой на дно. ГОВОРИ...Я всё знаю, что произошло на Ямайке, где Тиракс?";
			link.l1.go = "Terrax_abordage_3";
		break;

		case "Terrax_abordage_3":
                        dialog.text = "Ладно, тебе скажу, Барон, Тиракс в одном из домов Шарлотт - тауна, не убивай его - он не причём...";
			link.l1 = "Рассказывай, что произошло в Порт-Антонио?";
			link.l1.go = "Terrax_abordage_4";
		break;

		case "Terrax_abordage_4":
                        dialog.text = "В порт-Антонио мы делили добычу с налёта на банк, я лично учавствовал в этом деле вместе с Жаном Красавчиком, скажу прямо - сработали чисто без свидетелей.";
			link.l1 = "Это мне известно, дальше?";
			link.l1.go = "Terrax_abordage_5";
		break;

		case "Terrax_abordage_5":
                        dialog.text = "Пока считали, делили добычу к нам подошёл линейный корабль Ужасающий, на нём был сам адмирал пиратов Генри Морган.";
			link.l1 = "С этого момента поподробнее?";
			link.l1.go = "Terrax_abordage_6";
		break;

		case "Terrax_abordage_6":
                        dialog.text = "Морган приказал всем сойти на берег, а в случае неподчинения, Морган грозился открыть огонь. Сам понимаешь чем это могло закончится. На берегу Морган потребовал всё награбленное нами непосильным трудом вернуть ему, всё до последнего песо. Жан и Тиракс решили договориться с Морганом, и договорились на свою голову, Морган назначил им дуэль, вот тут и понеслось. По началу они противились этому приказу, тогда люди Моргана стали убивать матросов по одному до тех пор пока не начнётся дуэль.";
			link.l1 = "Понятно, на дуэли Жан погиб?";
			link.l1.go = "Terrax_abordage_7";
		break;

		case "Terrax_abordage_7":
                        dialog.text = "Да Барон, так и было. Морган Тиракса пощадил, добычу забрал, а напоследок корвет Жана Красавчика пустил на дно. Вот такие дела, Барон.";
			link.l1 = "Чего хочет Морган от Тиракса?";
			link.l1.go = "Terrax_abordage_8";
		break;

		case "Terrax_abordage_8":
                        dialog.text = "Тиракс независимая фигура, а Морган хочет его под себя подмять, вот и придумал всю эту лабуду. По кодексу, Тиракс же убил члена берегового братства, ему грозит чёрная метка. Но мы то, всё знаем, как всё было на самом деле. Вот теперь хотим собрать голоса других баронов по этому вопросу, Тиракс не виновен.";
			link.l1 = "Понял, хорошо, действуй - мне пора...";
			link.l1.go = "Terrax_abordage_9";
		break;

		case "Terrax_abordage_9":
			DialogExit();
			sld = &Characters[sti(pchar.GenQuest.QuestAboardCabinDialogIdx)];
			Lai_SetPlayerType(pchar);
			LAi_RemoveCheckMinHP(sld);
			LAi_SetImmortal(sld, true);
			sld.ShipEnemyDisable  = true;
			pchar.quest.RevengeCorsair_AfterBattle.over = "yes";
			pchar.questTemp.RevengeCorsair.Self = "GothicRevengeCorsair";
			DoQuestCheckDelay("LAi_ReloadBoarding", 1.0);
		break;

//************Пираты (3шт) в доме Шарлотт-тауна ****************************************

		case "RevengeCorsair_Pirat2":
 	        PlaySound("VOICE\Russian\gotica\BANDIT_AMBUSH\DIA_1013_BANDIT_AMBUSH_01_01.wav");
            	                   dialog.text = "Эй парни посмотрите кто у нас здесь?";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_1";
		break;

		case "RevengeCorsair_Pirat2_1":
 	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10015_EMILIO_SENYAN_15_03.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "А что, какие то проблемы. Здесь Тиракс?";
        	                   link.l1.go = "RevengeCorsair_Pirat2_2";
		break;

		case "RevengeCorsair_Pirat2_2":
 	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10018_TORWACHE_EXIT_04_02.wav");
            	                   dialog.text = "Отвали.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_3";
		break;

		case "RevengeCorsair_Pirat2_3":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\AUFSMAUL.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Слушай, а что это у тебя перед головой, лицо или задница!";
        	                   link.l1.go = "RevengeCorsair_Pirat2_4";
		break;

		case "RevengeCorsair_Pirat2_4":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_ADDON_BDT_10018_TORWACHE_SECONDWARN_04_00.wav");
            	                   dialog.text = "Следующий шаг для тебя станет последним.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_5";
		break;

		case "RevengeCorsair_Pirat2_5":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_NEVER_15_00.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Прочь с моей дороги.";
        	                   link.l1.go = "RevengeCorsair_Pirat2_6";
		break;

		case "RevengeCorsair_Pirat2_6":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1020_WEGELAGERER_FIRSTWARN_NOWEAPON_06_01.wav");
            	                   dialog.text = "Ладно, по плохому так по плохому.";
        	                   link.l1 = "...";
        	                   link.l1.go = "RevengeCorsair_Pirat2_7";
		break;

		case "RevengeCorsair_Pirat2_7":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\PRICEOFHELP.wav");
            	                   dialog.text = "...";
        	                   link.l1 = "Ах ты шельмец!";
        	                   link.l1.go = "RevengeCorsair_Pirat2_Fight";
		break;

 		case "RevengeCorsair_Pirat2_Fight":
                                          NextDiag.CurrentNode = "First time";
		DialogExit();
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_15");
		break;

		// клон Тиракс
		case "Terrax_1":
                        dialog.text = "Если ты пришёл меня убить, сделай это быстро.";
			link.l1 = "....";
			link.l1.go = "Terrax_2_1";
		break;

		case "Terrax_2_1":
  	        PlaySound("VOICE\Russian\gotica\BDT\DIA_BDT_1031_FLUECHTLING_TIP1_FREI_15_00.wav");
                                                              dialog.text = "...";
			link.l1 = "Я не собираюсь убивать тебя, это я всегда успею - поверь. Однако давай поговорим, и вообще с чего ты взял, что я хочу тебя убить?";
			link.l1.go = "Terrax_2";
		break;

		case "Terrax_2":
                       dialog.text = "Я убил Жана и тем самым нарушил пиратский кодекс, хранителем которого я являюсь. Я достоин смерти, а тут ещё Морган пустил слух, что ты его человек, и после всей этой истории, я счёл, что ты всё это время втирался ко мне в доверие, чтобы в итоге, по указке Моргана, ты меня пришил.";
			link.l1 = "Успокойся, Маркус, у меня нет желания тебя убивать. Так же знаю всё, что произошло на Ямайке, у тебя не было выбора.";
			link.l1.go = "Terrax_3";
		break;

		case "Terrax_3":
                        dialog.text = "Выбор всегда есть! Надо было драться с Морганом! Ах, Морган, мерзавец! Знал же, сволочь, что я не смогу наступить себе на горло и нарушить кодекс для того, чтобы в открытую дать ему отпор. Подловил он меня, а в итоге всё равно я нарушил кодекс, да ещё и своего человека потерял. Кстати, а как ты мне объяснишь от кого узнал Морган о налёте на банк?";
			link.l1 = "Ты думаешь от меня? Ошибаешься, Маркус, я об этом узнал пару дней назад после того как вы грабанули банк.";
			link.l1.go = "Terrax_4";
		break;

		case "Terrax_4":
                        dialog.text = "Тысяча чертей, я ничего тогда не понимаю, тогда кто...";
			link.l1 = "Я возможно скажу кто, если ты мне ответишь на мой вопрос.";
			link.l1.go = "Terrax_5";
		break;

		case "Terrax_5":
                        dialog.text = "Задавай!";
			link.l1 = "Помнишь ты отправил меня на Тортугу к Жанетте?";
			link.l1.go = "Terrax_6";
		break;

		case "Terrax_6":
                        dialog.text = "Да, помню, после похода на Картахену, хотел как лучше для тебя и других. И что?";
			link.l1 = "Это была ловушка, не только для меня но и для Лепрекона, Тесака Пелли, Лысого Джеффри. Всех нас заманили в одну нору, и натравили друг на друга. Кто мог знать куда направляются твои люди? Только ты сам или кто-то из твоих людей...";
			link.l1.go = "Terrax_7";
		break;

		case "Terrax_7":
                        dialog.text = "Кроме меня об этом мог знать только Паскуаль Вуазье, ему я полностью доверяю!";
			link.l1 = "Паскуаль Вуазье, интересно...";
			link.l1.go = "Terrax_8";
		break;

		case "Terrax_8":
                        dialog.text = "К чему ты клонишь, что произошло в норе в которую вас заманили?";
			link.l1 = "Ничего, они мертвы, а я выжил, надеюсь этого достаточно.";
			link.l1.go = "Terrax_9";
		break;

		case "Terrax_9":
                        dialog.text = "Я ничего не понимаю, Морган знал о налёте на банк, Жан мертв от моего клинка, тебя и моих людей хотели убрать, цель достигнута но не полностью - ты жив. Теперь до этого момента кто-то из нас должен был выйти из игры и при этом мы должны были убрать друга своим руками. Если не ты тогда кто?";
			link.l1 = "Так же думаю я, если не ты... Тогда.";
			link.l1.go = "Terrax_10";
		break;

		case "Terrax_10":
                        dialog.text = "Ты думаешь Паскуаль Вуазье?";
			link.l1 = "Может быть и он, а может и нет. тебе имя Зорро - это испаский народный мститель, ничего не говорит?";
			link.l1.go = "Terrax_11";
		break;

		case "Terrax_11":
                        dialog.text = "Зорро... Я слышал эту байку по пьяне в таверне. Но ты ведь не всерьёз?";
			link.l1 = "Нет Маркус - всё всерьёз, ловушка, наводка на банк, кем бы он не был Зорро, Вуазье, Морган, да хоть сам чёрт лысый, это дело необходимо закончить. Я лично видел этого народного мстителя. Кстати, возможно, что Вуазье продал информацию о нас этому Зорро или Моргану. Паскуале же сволочь, которая мать родную продаст ради денег.";
			link.l1.go = "Terrax_12";
		break;

		case "Terrax_12":
                        dialog.text = "Возможно ты и прав. Что делать будем?";
			link.l1 = "Давай пустим слух о твоей гибели при загадочных обстоятельствах. Поговори с Торусом об этом и сиди в этом доме под чутким наблюдением его людей до моего прихода. Больше чем уверен, что кукловод должен будет выйти сцену и закончить игру. Очевидно, что целью буду я, после, возможного устранения Паскуаля Вуазье в том случае если он не причастен к нашей трагедии.";
			link.l1.go = "Terrax_13";
		break;

		case "Terrax_13":
                        dialog.text = "Хорошо, поступим так. Мне всё равно необходима поддержка баронов против Моргана и его выходок!";
			link.l1 = "Вот и договорились.";
			link.l1.go = "Terrax_14";
		break;

		case "Terrax_14":
 		DialogExit();
                NextDiag.CurrentNode = "First time";
		AddDialogExitQuestFunction("Gothic_RevengeCorsair_16");
		break;


		// дон Энрико
		case "Zorro_1":
                        dialog.text = "...";
			link.l1 = "Ну вот мы и встретились.";
			link.l1.go = "Zorro_2";
		break;

		case "Zorro_2":
                        dialog.text = "...";
			link.l1 = "Воистину - справедливое возмездие!";
			link.l1.go = "Zorro_3";
		break;

		case "Zorro_3":
                        dialog.text = "...";
			link.l1 = "Так, что ты там пел? Я легко мог бы убить тебя, но быстрая смерть - слишком мягкое наказание для такого отпетого негодяя?";
			link.l1.go = "Zorro_4";
		break;

		case "Zorro_4":
                        dialog.text = "Я могу повторить.";
			link.l1 = "Нет, клинок доставай, я резать тебя буду по кусочкам.";
			link.l1.go = "Zorro_5";
			link.l2 = "Не стоит. Да не дергай ты свое оружие - это бесполезно... Я легко могу  убить тебя, но быстрая смерть - слишком мягкое наказание - не так ли? Ты останешься здесь, на свежем воздухе. Сундук мертвеца - хорошее место для того, что бы обо всём подумать. Желаю удачи, дон Энрико...";
			link.l2.go = "Zorro_6";
		break;

		case "Zorro_5":
                        dialog.text = "Будь ты проклят, за все убийства и насилия. Мертвецы висят на твоей шее, как мельничные жернова, и они утянут тебя в ад!";
			link.l1 = "Это я уже слышал.";
			link.l1.go = "exit";
		        AddDialogExitQuestFunction("Gothic_RevengeCorsair_25");
		break;

		case "Zorro_6":
                                          NextDiag.CurrentNode = "First time_Zorro";
		DialogExit();
		 AddDialogExitQuestFunction("Gothic_RevengeCorsair_26");
		break;

		case "First time_Zorro":
			dialog.text = "Будь ты проклят, за все убийства и насилия. Мертвецы висят на твоей шее, как мельничные жернова, и они утянут тебя в ад!";
			link.l1 = "Желаю удачи, дон Энрико...";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time_Zorro";
		break;





//************Одержимые ****************************************

		case "BillMatthew":		// Билл
                                    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOODMONSTERKILL.wav");
			dialog.text = "Спасибо, что помогли мне, без вас они бы убили меня и забрали монету.";
			link.l1 = "Зачем скелетам деньги?";
			link.l1.go = "BillMatthew_1";		
		break;
		
		case "BillMatthew_1":
			dialog.text = "Пожалуй, мне стоит рассказать вам историю. Я был штурманом в команде Делвина Блейза на пиратском бриге 'Удачливый Джокер'.\nПосле удачного рейда на испанский галеон забитый всякими индейскими украшениями, золотом и серебром. Удачный налёт скажу я вам, тогда при дележе средств всей команде хватило бы на безбедную жизнь. Помимо драгоценностей, мы нашли шкатулку, в которой лежали пузырек с какой-то жидкостью и три старинные золотые монеты.\nРаньше никто из нас таких монет не видел. Мы поделили монеты, одна из этих монет досталась мне, а шкатулка с жидкостью капитану.";
			link.l1 = "Хм, и что же было дальше?";
			link.l1.go = "BillMatthew_2";		
		break;

		case "BillMatthew_2":
			dialog.text = "Через какое-то время капитану Блейзу удалось найти человека, который смог прочитать надпись на крышке той самой шкатулки.\nОказалось, что обладатель содержимого мог связаться со злыми индейскими духами, прочитав заклинание, написанное на крышке и смешав свою кровь с жидкостью из пузырька.\nНаш капитан так и сделал, в результате чего в него вселился злой дух! Более того, Блейз получил необъяснимую власть над своей командой, а часть своих матросов с помощью этой колдовской жидкости превратил в живых скелетов!\nСтранным образом на меня не подействовали его магия - теперь я понимаю - эта старинная монета спасла меня! Через какое-то время мне удалось бежать, я сменил род деятельности - по ходатайству тестя меня взяли штурманом на торговое судно.\nБеда вот в чём - чем больше людей Блейз и его команда убивают, тем сильнее он становится.";
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
			link.l1 = "Его спасли аборегены, ловцы жемчуга. Продолжай...";
			link.l1.go = "BillMatthew_5";		
		break;

		case "BillMatthew_5":
			dialog.text = "Не может быть, вот чёрт, гореть в аду этому Блейзу, на его шее красовалась монета, и он всех убедил, что Абрам первый помощник отдал ему её добровольно? Значит всё верно, он у него забрал с силой и сбросил в море. Чутьё нас не подвело, я и квартирмейстер решили покинуть корабль.";
			link.l1 = "Как я понимаю обладателем второй монеты был квартирмейстер.";
			link.l1.go = "BillMatthew_6";		
		break;

		case "BillMatthew_6":
			dialog.text = "Всё верно, Юмбер Кёруа, он живет в Чарлстоуне и ему похоже как и мне грозит опасность.";
			link.l1 = "Я могу ещё чем - нибудь помочь вам!";
			link.l1.go = "BillMatthew_7";		
		break;

		case "BillMatthew_7":
			dialog.text = "Да, если быть до конца откровенным, эта монета жжет мне карман - ведь они все равно рано или поздно до меня доберутся!";
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

		case "ObsessionDevlin":		// Делвин
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_00.wav");
                                    dialog.text = "Мы знали, что ты придёшь!";
	                  link.l1 = "Делвин ещё не позно всё вернуть, ты должен сопротивляться.";
		link.l1.go = "ObsessionDevlin_1";
		break;

		case "ObsessionDevlin_1":
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_01.wav");
                                    dialog.text = "Мой хозяин одержит победу и склонит весь мир к своим ногам! Нет нужды для сопротивления, лучше ты склони свои колени перед моим хозяином и отдай то, что принадлежит мне.";
	                  link.l1 = "Ты говоришь о монете!";
		link.l1.go = "ObsessionDevlin_2";
		AddDialogExitQuestFunction("GothicObsession_Devlin_2");
		break;

		case "ObsessionDevlin_2":
 	                  PlaySound("VOICE\Russian\GOTHIC\GG\GG_10.wav");
                                    dialog.text = "Да.";
	                  link.l1 = "Забудь об этом.";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsession_Devlin_2");
		break;

		case "ObsessionDevlin_3":
 	                  PlaySound("VOICE\Russian\gotica\BRIDGEDEMENTOR\DIA_BRIDGEDEMENTOR_19_02.wav");
                                    dialog.text = "Ты наивный идиот, ты понятия не имеешь на, что ты замахнулся и я накажу тебя за это здесь и сейчас!";
	                  link.l1 = "...";
		link.l1.go = "ObsessionDevlin_4";
		break;

		case "ObsessionDevlin_4":
		RemoveItems(PChar, "Obsession_Coin", 1);
		PlaySound("interface\important_item.wav");
		Log_Info("Фиамотар забрал монету");
  	                  PlaySound("VOICE\Russian\GOTHIC\GG\PRICEOFHELP.wav");
                                    dialog.text = "...";
	                  link.l1 = "Ах ты шельмец!";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicObsession_Devlin_5");
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
                                    dialog.text = "Делвин Блейз в прошлом, моё имя Фиамотар, дорованный драконом. Кровь дракона течет в моих венах и сила дракона в моих жилах.";
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
                                   dialog.text = "Наше будующее, настоящее контролируеся хозяином при помощи слова силы, скоро никто не сможет сопротивляться ему.";
		link.l1 = "...";
		link.l1.go = "Fiamatar_abordage_10";
		break;

		case "Fiamatar_abordage_10":
 	                  PlaySound("VOICE\Russian\gotica\DRAGON\DIA_DRAGONTALK_MAIN_2_20_02.wav");
                                    dialog.text = "Его длинная рука уже протинулась сюда из царства мертвых, духи ночи собираются в предвкушении его скорого появления.";
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
		link.l1 = "Хватит болтать, я загоню тебя обратно под камень из под которого ты вылез - монстор.";
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
                                   dialog.text = "Твои кости помугут мне выпустить ветра смерти в этот мир.";
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


		
		case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
		
	}
}