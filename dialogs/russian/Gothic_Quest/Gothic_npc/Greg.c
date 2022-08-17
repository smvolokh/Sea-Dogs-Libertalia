// Капитан Грег, гроза морей и океанов
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
	float locx, locy, locz;
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // индекс в конце
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}

// ============================= блок angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //ловушка первого срабатывания
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
            switch (npchar.angry.kind) //сюда расписываем реакцию ангри. В npchar.angry.name пробелы удалены!
            {
                case "repeat":
                    if (npchar.angry.name == "Firsttime") Dialog.CurrentNode = "AngryRepeat_1";
                    if (npchar.angry.name == "I_know_you_good") Dialog.CurrentNode = "AngryRepeat_2";
                break;
            }
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= блок angry ===================================
// ============================================================================

	
	switch(Dialog.CurrentNode)
	{

		case "First time":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_15_01.wav");
		dialog.text = "...";
		link.l1 = "У тебя всё ещё проблемы с городской стражей.";
		link.l1.go = "WAS";			
		break;

		case "WAS":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_01_02.wav");
		dialog.text = "Сейчас у тебя начнутся проблемы, придурок...";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "First time";		
		break;


		case "NOCHNICHT":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "На счёт городских стражников.";
		link.l1.go = "nw";			
		break;

		case "nw":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_01_01.wav");
		dialog.text = "...";
	                 if(CheckAttribute(pchar, "questTemp.GothicGreg") && pchar.questTemp.GothicGreg == "Greg_geld" && !CheckAttribute(npchar, "quest.Greg_geld"))
		{
		link.l1 = "Ты не думал о подкупе.";
		link.l1.go = "nw_1_1";
		}
	                 if(CheckAttribute(pchar, "questTemp.GothicGreg") && pchar.questTemp.GothicGreg == "conctantino" && !CheckAttribute(npchar, "quest.conctantino"))
		{
		link.l1 = "Ты можешь попасть в город сказав, что ты сборщик трав.";
		link.l1.go = "nw_2_1";
		}
                                         if (CheckCharacterItem(pchar, "suit5") && CheckAttribute(pchar, "questTemp.GothicGreg") && !CheckAttribute(npchar, "quest.suit5"))
		{
		link.l1 = "Они пропустят тебя, если на тебе будет одежда крестьянина.";
		link.l1.go = "nw_3_1";
		}
                                         if (CheckCharacterItem(pchar, "VerifyPaper") && CheckAttribute(pchar, "questTemp.GothicGreg") && !CheckAttribute(npchar, "quest.VerifyPaper"))
		{
		link.l1 = "У меня есть пропуск в город.";
		link.l1.go = "nw_4_1";
		}
		link.l2 = "Мне надо идти.";
		link.l2.go = "Greg_hallo_10_1";	

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "PiratosGreg.Fail1" && !CheckAttribute(npchar, "quest.PiratosGreg.Fail1"))
		{
		link.l1 = "У меня к тебе есть деловое предложение.";
		link.l1.go = "Greg_Trinidad";
		}

	                 if(CheckAttribute(pchar, "questTemp.GothicPiratosGreg") && pchar.questTemp.GothicPiratosGreg == "PiratosGreg.work" && !CheckAttribute(npchar, "quest.PiratosGreg.work"))
		{
		link.l1 = "У меня к тебе есть деловое предложение.";
		link.l1.go = "Greg_Trinidad_work";
		}

 		break;

		case "WER":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_15_00.wav");
		dialog.text = "...";
		link.l1 = "А кто ты вообще такой?";
		link.l1.go = "WER_0";			
		break;

		case "WER_0":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_01_01.wav");
		dialog.text = "Это не твоё дело.";
		link.l1 = "...";
		link.l1.go = "WER_1";			
		break;

		case "WER_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WER_01_02.wav");
		dialog.text = "Если бы я хотел тебе представиться, я бы наверное это уже сделал, не так ли!";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "WER";		
		break;

		case "nw_1_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_GELD_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты не думал о подкупе.";
		link.l1.go = "nw_1_2";			
		break;

		case "nw_1_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_GELD_01_01.wav");
		dialog.text = "Если бы я мог подкупить стражников, я был бы уже в городе.";
		link.l1 = "...";
		link.l1.go = "nw_1_3";			
		break;

		case "nw_1_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно ещё подумать.";
		link.l1.go = "nw_exit1";			
		break;

		case "nw_exit1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.Greg_geld = "true";
                                          pchar.questTemp.GothicGreg = "conctantino";	
		DialogExit();
		break;

		case "nw_2_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_CONSTANTINO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты можешь попасть в город сказав, что ты сборщик трав.";
		link.l1.go = "nw_2_2";			
		break;

		case "nw_2_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_CONSTANTINO_01_01.wav");
		dialog.text = "Что. Я что похож на человека который собирает в лесах цветочки!";
		link.l1 = "...";
		link.l1.go = "nw_2_3";			
		break;

		case "nw_2_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно ещё подумать.";
		link.l1.go = "nw_exit2";			
		break;

		case "nw_exit2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.conctantino = "true";	
		DialogExit();
		break;

		case "nw_3_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Они пропустят тебя, если на тебе будет одежда крестьянина.";
		link.l1.go = "nw_3_2";			
		break;

		case "nw_3_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_01.wav");
		dialog.text = "Это как раз то, что мне нужно, я знал, что могу на тебя положиться приятель.";
		link.l1 = "...";
		link.l1.go = "nw_3_3";			
		break;

		case "nw_3_3":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "suit5", -1);
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_02.wav");
		dialog.text = "Если я буду одет как местный деревенский мужлан, никто не будет обращать на меня внимание.";
		link.l1 = "...";
		link.l1.go = "nw_3_4";			
		break;

		case "nw_3_4":
		npchar.model = "Greg2";
		Characters_RefreshModel(npchar);
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_03.wav");
		dialog.text = "Отлично, вот твоя награда.";
		link.l1 = "...";
		link.l1.go = "nw_3_5";			
		break;

		case "nw_3_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_15_04.wav");
		dialog.text = "...";
		link.l1 = "Что, жалкие 50 монет! Да ты должно быть шутишь.";
		link.l1.go = "nw_3_6";			
		break;

		case "nw_3_6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_05.wav");
		dialog.text = "Золото это не самое важное на свете - друг мой. Возьми пока то, что я тебе предлагаю.";
		link.l1 = "...";
		link.l1.go = "nw_3_7";			
		break;

		case "nw_3_7":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 50);
		Log_Info("Вы получили 50 дублонов");
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_06.wav");
		dialog.text = "У меня есть предчувствие, что мы скоро встретимся снова.";
		link.l1 = "...";
		link.l1.go = "nw_3_8";			
		break;

		case "nw_3_8":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_KLAMOTTEN_01_07.wav");
		dialog.text = "И кто знает, может быть у меня будет возможность отплатить тебе услугой за услугу, береги себя.";
		link.l1 = "...";
		link.l1.go = "nw_exit3";			
		break;

		case "nw_exit3":
		npchar.quest.suit5 = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuestFunction("Horinisport3");
		break;

		case "nw_4_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "У меня есть пропуск в город.";
		link.l1.go = "nw_4_2";			
		break;

		case "nw_4_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_01_01.wav");
		dialog.text = "А-га, ты хочешь сказать, что я должен выдать себя за горожанина.";
		link.l1 = "...";
		link.l1.go = "nw_4_3";			
		break;

		case "nw_4_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_SCHEIN_01_02.wav");
		dialog.text = "Посмотри на меня, мальчик, в это не поверит даже последний идиот.";
		link.l1 = "...";
		link.l1.go = "nw_4_4";			
		break;

		case "nw_4_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно ещё подумать.";
		link.l1.go = "nw_exit4";			
		break;

		case "nw_exit4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.TempNode = "NOCHNICHT";
		npchar.quest.VerifyPaper = "true";
		DialogExit();
		break;

		case "Greg_hallo":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_00.wav");
		dialog.text = "Пс...Эй, ты, подойди-ка сюда...";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_1";			
		break;

		case "Greg_hallo_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_15_01.wav");
		dialog.text = "...";
		link.l1 = "В чём дело?";
		link.l1.go = "Greg_hallo_2";			
		break;

		case "Greg_hallo_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_02.wav");
		dialog.text = "Ты идёшь в город! У тебя там дела!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_3";			
		break;

		case "Greg_hallo_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_03.wav");
		dialog.text = "Послушай, ты выглядишь сообразительным парнем, уверен, ты в жизни далеко пойдёшь.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_4";			
		break;

		case "Greg_hallo_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_04.wav");
		dialog.text = "Ты не дурак, я вижу это по твоим глазам.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_5";			
		break;

		case "Greg_hallo_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_01_05.wav");
		dialog.text = "Наверняка ты хочешь заработать пригоршню золотых монет, не так-ли?";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6";			
		break;

		case "Greg_hallo_6":
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "Ты от кого-то прячешься!";
		link.l2.go = "Greg_hallo_7_1";
		link.l3 = "И не похоже, что бы у тебя водились деньги!";
		link.l3.go = "Greg_hallo_8_1";
		link.l4 = "Довольно болтать, говори чего ты хочешь.";
		link.l4.go = "Greg_hallo_9_1";	
		link.l5 = "Мне надо идти.";
		link.l5.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_6_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_hallo_6_2";			
		break;

		case "Greg_hallo_6_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_01.wav");
		dialog.text = "Ты должен простить невежественного старого моряка, я чужой в ваших краях и не знаю местных законов.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_3";			
		break;

		case "Greg_hallo_6_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_02.wav");
		dialog.text = "Поэтому мне пришлось на своей шкуре испытать, как стражники встречают в этом городе простых путников.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_4";			
		break;

		case "Greg_hallo_6_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_03.wav");
		dialog.text = "И вот теперь мне нужно попасть в город, а я не знаю как это сделать.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_5";			
		break;

		case "Greg_hallo_6_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_04.wav");
		dialog.text = "В городе у меня чрезвычайно важное дело, мой клиент не потерпит задержки да же на день.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_6";			
		break;

		case "Greg_hallo_6_6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_01_05.wav");
		dialog.text = "Ты же поможешь мне пройти мимо стражников, правда!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_6_7";			
		break;

		case "Greg_hallo_6_7":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно подумать.";
		link.l1.go = "nw_exit6";			
		break;

		case "nw_exit6":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_STADTWACHEN_NOCHNICHT_01_01.wav");				NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuestFunction("Horinisport2");
		break;

		case "Greg_hallo_7_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты от кого-то прячешься!";
		link.l1.go = "Greg_hallo_7_2";			
		break;

		case "Greg_hallo_7_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_01.wav");
		dialog.text = "Нет, конечно нет, что за абсурд. Мне просто нравится стоять среди деревьев так мне ветер не дует в лицо.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_7_3";			
		break;

		case "Greg_hallo_7_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_02.wav");
		dialog.text = "Ну, давай лучше поговорим о тебе, ты берёшь работу!";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_7_4";			
		break;

		case "Greg_hallo_7_4":
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "И не похоже, что бы у тебя водились деньги!";
		link.l2.go = "Greg_hallo_8_1";
		link.l3 = "Довольно болтать, говори чего ты хочешь.";
		link.l3.go = "Greg_hallo_9_1";	
		link.l4 = "Мне надо идти.";
		link.l4.go = "Greg_hallo_10_1";					
		break;


		case "Greg_hallo_8_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_15_00.wav");
		dialog.text = "...";
		link.l1 = "И не похоже, что бы у тебя водились деньги.";
		link.l1.go = "Greg_hallo_8_2";			
		break;

		case "Greg_hallo_8_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_01.wav");
		dialog.text = "Ну конечно, я не вращаюсь подобно тебе, в высших кругах общества.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_3";			
		break;

		case "Greg_hallo_8_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_02.wav");
		dialog.text = "Ну ты же не откажешься увеличить своё состояние на небольшую сумму, которую я мог бы тебе дать.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_4";			
		break;

		case "Greg_hallo_8_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_VORSICHT_01_03.wav");
		dialog.text = "Ну, что скажешь, я могу на тебя рассчитывать.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_8_5";			
		break;

		case "Greg_hallo_8_5":
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "Довольно болтать, говори чего ты хочешь.";
		link.l2.go = "Greg_hallo_9_1";	
		link.l3 = "Мне надо идти.";
		link.l3.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_9_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_15_00.wav");
		dialog.text = "...";
		link.l1 = "Довольно болтать, говори чего ты хочешь.";
		link.l1.go = "Greg_hallo_9_2";			
		break;

		case "Greg_hallo_9_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_01.wav");
		dialog.text = "Вот видишь это именно то, что я имею ввиду.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_3";			
		break;

		case "Greg_hallo_9_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_02.wav");
		dialog.text = "Одни красивые слова никуда тебя не приведут.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_4";			
		break;

		case "Greg_hallo_9_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_03.wav");
		dialog.text = "Я знал, что имею дела с настоящим деловым человеком.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_5";			
		break;

		case "Greg_hallo_9_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_SCHLEIM_01_04.wav");
		dialog.text = "И, уж, наверняка этот деловой человек, не откажется от небольшого вознаграждения.";
		link.l1 = "...";
		link.l1.go = "Greg_hallo_9_6";			
		break;

		case "Greg_hallo_9_6":
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_hallo_6_1";
		link.l2 = "Мне надо идти.";
		link.l2.go = "Greg_hallo_10_1";					
		break;

		case "Greg_hallo_10_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне надо идти.";
		link.l1.go = "Greg_hallo_10_2";			
		break;

		case "Greg_hallo_10_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_01_01.wav");
		dialog.text = "И так, ты отказываешься мне помогать, верно. Хорошо я это запомню, мы ещё встретимся.";
		link.l1 = "...";
		link.l1.go = "exit";	
		NextDiag.TempNode = "First time";			
		break;

//--> -----------------------------------Кайман------------------------------------------

		case "Greg_Caiman":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_15_00.wav");
		dialog.text = "...";
		link.l1 = "Кто ты...";
		link.l1.go = "Greg_Caiman_1";				
		break;

		case "Greg_Caiman_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_01_01.wav");
		dialog.text = "Я Грег, предводитель этой ленивой своры...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_2";				
		break;

		case "Greg_Caiman_2":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_WHOAREYOU_01_02.wav");
		dialog.text = "Тебя устраивает такой ответ...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_3";				
		break;

		case "Greg_Caiman_3":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_WAY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как ты сюда попал?";
		link.l1.go = "Greg_Caiman_4";				
		break;

		case "Greg_Caiman_4":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_15_00.wav");
		dialog.text = "...";
		link.l1 = "А где твой корабль?";
		link.l1.go = "Greg_Caiman_5";				
		break;

		case "Greg_Caiman_5":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_01.wav");
		dialog.text = "Я чертовски удачлевый человек, уже несколько месяцев сюда не приплывали корабли.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_6";				
		break;

		case "Greg_Caiman_6":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_02.wav");
		dialog.text = "Несколько меясяцев. И первый корабль который мне после этого встречается оказывается боевым кораблём 'Девентер' принадлежащий королю.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_7";				
		break;

		case "Greg_Caiman_7":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_03.wav");
		dialog.text = "Он был битком набит паладинами.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_8";				
		break;

		case "Greg_Caiman_8":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_15_04.wav");
		dialog.text = "...";
		link.l1 = "Да уж, неповезло тебе...";
		link.l1.go = "Greg_Caiman_9";				
		break;

		case "Greg_Caiman_9":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_STORY_SHIP_01_05.wav");
		dialog.text = "Вот именно они тут же потопили нас, я единственный кто добрался до берега.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_10";				
		break;

		case "Greg_Caiman_10":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_HIDE_01_02.wav");
		dialog.text = "Ну, давай лучше поговорим о тебе, ты берёшь работу!";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11";			
		break;

		case "Greg_Caiman_11":
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_Caiman_11_1";	
		link.l2 = "Мне надо идти.";
		link.l2.go = "Greg_Caiman_12_1";					
		break;

		case "Greg_Caiman_12_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне надо идти.";
		link.l1.go = "Greg_Caiman_12_2";			
		break;

		case "Greg_Caiman_12_2":
                                          pchar.questTemp.GothicPiratosGreg = "PiratosGreg.Fail1";
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_WEG_01_01.wav");
		dialog.text = "И так, ты отказываешься мне помогать, верно. Хорошо я это запомню, мы ещё встретимся.";
		link.l1 = "...";
		link.l1.go = "GregCaiman_board_6x";	
		break;

		case "Greg_Caiman_11_1":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_HALLO_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "Почему бы и нет...";
		link.l1.go = "Greg_Caiman_11_2";			
		break;

		case "Greg_Caiman_11_2":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_HIERGOLD_01_02.wav");
		dialog.text = "Неподалёку от сюда есть пещера, это одно из тех мест, где я когда-то зарыл свои сокровища.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_3";			
		break;

		case "Greg_Caiman_11_3":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_WAS_HIERGOLD_01_03.wav");
		dialog.text = "Пещера для меня слишком опасна, я хочу, что бы ты мне помог.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_4";			
		break;

		case "Greg_Caiman_11_4":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVELOS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Пойдём в твою пещеру.";
		link.l1.go = "Greg_Caiman_11_5";			
		break;

		case "Greg_Caiman_11_5":
	                     PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVELOS_01_01.wav");
		dialog.text = "Следуй за мной.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_11_6";		
		break;

		case "Greg_Caiman_11_6":
		DialogExit();
	                  AddDialogExitQuestFunction("GothicEng_CreateGreg_1");		
		break;

		case "GregCaiman_board_6x":
                                    DialogExit();
                                    npchar = characterFromID("GREG");
                                    npchar.dialog.currentnode = "GregCaiman_board_6x";
                                    npchar.DeckDialogNode = "GregCaiman_board_6x";
	                  npchar.DontDeskTalk = true;				
		break;

		case "GregCaiman_board_6x":
                                    dialog.text = "Что-то еще хочешь сказать?";
		link.l1 = "Нет, пожалуй. Уже отправляюсь на свое судно.";
		link.l1.go = "GregCaiman_board_6y";
		break;
		
		case "GregCaiman_board_6y":
                                    DialogExit();
                                   npchar = characterFromID("GREG");
		npchar.DeckDialogNode = "GregCaiman_board_6x";
		break;

		case "Greg_Caiman_13":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_00.wav");
		dialog.text = "Ну, что приятель, вот и пещера.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_14";		
		break;

		case "Greg_Caiman_14":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_01.wav");
		dialog.text = "Вот тебе кирка.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_15";		
		break;

		case "Greg_Caiman_15":
                                    TakeNItems(pchar, "minepick", 1);
                                    Log_Info("Вы получили кирку");
                                    PlaySound("interface\important_item.wav");
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_02.wav");
		dialog.text = "Я закопал свои вещи где - то внутри, место отмеченно крестом.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_16";		
		break;

		case "Greg_Caiman_16":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_03.wav");
		dialog.text = "Ну и чего ты ждёшь, иди внутрь и заберай вещи.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_17";		
		break;

		case "Greg_Caiman_17":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_15_04.wav");
		dialog.text = "...";
		link.l1 = "А как же ты?";
		link.l1.go = "Greg_Caiman_18";			
		break;

		case "Greg_Caiman_18":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_05.wav");
		dialog.text = "Кто - то же должен защищать тыл, а теперь иди внутрь.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_19";	
		break;

		case "Greg_Caiman_19":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_RAKECAVETHERE_01_03.wav");
		DialogExit();
                                    NPChar = characterFromID("GREG");
	                  NPChar.dialog.currentnode   = "Greg_Caiman_18";
                                    LAi_SetWarriorType(NPChar);
		AddDialogExitQuestFunction("GothicGreg_CaveEntrance_3");	
		break;

		case "Greg_Caiman_20":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я нашёл все закопанные вещи.";
		link.l1.go = "Greg_Caiman_21";		
		break;

		case "Greg_Caiman_21":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_01_01.wav");
		dialog.text = "Тогда у тебя должно быть около 100 золотых, золотая чаша, серебряное блюдо и амулет. Давай их сюда.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_22";	
		break;

		case "Greg_Caiman_22":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_00.wav");
		dialog.text = "...";
		link.l1 = "Вот твои вещи.";
		link.l1.go = "Greg_Caiman_23";		
		break;

		case "Greg_Caiman_23":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "purse3"))
			{
				link.l1 = "Кошелёк со 100 золотыми.";
				link.l1.go = "Greg_Caiman_Task_check_1";	
			}
			else
			{
				link.l1 = "У меня с собой их нет.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_1":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "purse3", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_01.wav");
		dialog.text = "...";
		link.l1 = "Кошелёк со 100 золотыми.";
		link.l1.go = "Greg_Caiman_24";		
		break;

		case "Greg_Caiman_24":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "jewelry33"))
			{
				link.l1 = "Золотая чаша.";
				link.l1.go = "Greg_Caiman_Task_check_2";	
			}
			else
			{
				link.l1 = "У меня с собой их нет.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_2":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "jewelry33", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_03.wav");
		dialog.text = "...";
		link.l1 = "Золотая чаша.";
		link.l1.go = "Greg_Caiman_25";		
		break;

		case "Greg_Caiman_25":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "mineral36"))
			{
				link.l1 = "Серебряное блюдо.";
				link.l1.go = "Greg_Caiman_Task_check_3";	
			}
			else
			{
				link.l1 = "У меня с собой их нет.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_3":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "mineral36", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_04.wav");
		dialog.text = "...";
		link.l1 = "Серебряное блюдо.";
		link.l1.go = "Greg_Caiman_26";		
		break;

		case "Greg_Caiman_26":
			dialog.text = "...";
			if (CheckCharacterItem(pchar, "indian_5"))
			{
				link.l1 = "И амулет.";
				link.l1.go = "Greg_Caiman_Task_check_4";	
			}
			else
			{
				link.l1 = "У меня с собой их нет.";
				link.l1.go = "Greg_Caiman_Task_fail";	
			}		
		break;

		case "Greg_Caiman_Task_check_4":
		PlaySound("interface\important_item.wav");
		TakeNItems(PChar, "indian_5", -1);
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_15_05.wav");
		dialog.text = "...";
		link.l1 = "И амулет.";
		link.l1.go = "Greg_Caiman_27";		
		break;

		case "Greg_Caiman_27":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_JA_01_06.wav");
		dialog.text = "Очень хорошо, вижу у тебя хватило ума не присваивать себе мои вещи.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_28";		
		break;

		case "Greg_Caiman_28":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ещё кое - что.";
		link.l1.go = "Greg_Caiman_29";		
		break;

		case "Greg_Caiman_29":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_SAUBER2_01_01.wav");
		dialog.text = "Отлично держи свою награду...";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_30";		
		break;

		case "Greg_Caiman_30":
                                          pchar.questTemp.GothicPiratosGreg = "PiratosGreg.work";
	                     TakeNItems(pchar, "gold_dublon", 20);
	                      Log_Info("Вы получили 20 дублонов");
		 DialogExit();
	                      NextDiag.CurrentNode = NextDiag.TempNode;
		 AddDialogExitQuestFunction("GothicGreg_quest_chest5");
		 break;

		case "Greg_Caiman_31":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_02.wav");
		dialog.text = "Конечно я благодарен, что ты мне помог, но это не делает нас друзьями, понимаешь, о чём я.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_32";		
		break;

		case "Greg_Caiman_32":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("GothicGreg_quest_chest6");
                                          sld = CharacterFromID("GHenry");//Даём нуду Генри
	                     sld.dialog.filename = "Gothic_Quest\Gothic_npc\Henry.c";
                                          sld.dialog.currentnode = "PiratosHenry";
		break;

		case "Greg_Caiman_33":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_02.wav");
		dialog.text = "Конечно я благодарен, что ты мне помог, но это не делает нас друзьями, понимаешь, о чём я.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_34";		
		break;

		case "Greg_Caiman_34":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Greg_Caiman_Task_fail":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_NOT_15_00.wav");
		dialog.text = "...";
		link.l1 = "У меня с собой их нет.";
		link.l1.go = "Greg_Caiman_24_1";		
		break;

		case "Greg_Caiman_24_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_FOUNDTREASURE_NOT_01_01.wav");
		dialog.text = "Тогда поторопись и принеси их мне пока я нерассердился.";
		link.l1 = "...";
		link.l1.go = "Greg_Caiman_25_1";		
		break;

		case "Greg_Caiman_25_1":
                                         DialogExit();
		NextDiag.TempNode = "Greg_Caiman_22";
		break;

		case "Greg_Caiman_26_1":
	                    PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_NW_PERMTAVERNE_01_01.wav");
                                         DialogExit();
		NextDiag.TempNode = "Greg_Caiman_25_1";
		break;


		case "Greg_Hut":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_01_00.wav");
		dialog.text = "Эй ты, что ты делаешь в моей хижине.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_1";		
		break;

		case "Greg_Hut_1":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_15_01.wav");
		dialog.text = "...";
		link.l1 = "Я...";
		link.l1.go = "Greg_Hut_2";		
		break;

		case "Greg_Hut_2":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_HELLO_01_02.wav");
		dialog.text = "Стоит уехать на несколько дней и вот уже каждый проходимец, наровит похозяйнечать в моём жилище.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_3";		
		break;

		case "Greg_Hut_3":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_03.wav");
		dialog.text = "Кокого чёрта, что здесь происходит.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_4";		
		break;

		case "Greg_Hut_4":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_04.wav");
		dialog.text = "Частокол ещё не закончен, коньон просто кишит зверьём, а все только и делают, что слоняются вокруг.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_5";
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorTurnToLocator(npchar, "goto", "goto6");	
		break;

		case "Greg_Hut_5":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_05.wav");
		dialog.text = "И это всё, что ты зделал Френсис?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_6";		
		break;

		case "Greg_Hut_6":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_06.wav");
		dialog.text = "Немедленно слезь с моей скамейки.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_7";
	                     npchar = CharacterFromID("GFrancis");
                                         LAi_SetGuardianType(npchar);
	                    npchar.protector = true;
	                    npchar.dialog.currentnode   = "Francis_Greg_20";
                                         ChangeCharacterAddressGroup(npchar, "Trinidad_House_Jungle", "goto",  "ass4");		
		break;

		case "Greg_Hut_7":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_01_07.wav");
		dialog.text = "А ты, что ты сделал?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_8";
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorTurnToLocator(npchar, "reload", "reload2");
		break;

		case "Greg_Hut_8":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_NICH_15_00.wav");
		dialog.text = "...";
		link.l1 = "Пока не так много.";
		link.l1.go = "Greg_Hut_9";		
		break;

		case "Greg_Hut_9":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_IMNEW_NICH_01_01.wav");
		dialog.text = "Не важно, я что-нибудь подберу тебе дружище.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_10";	
		break;

		case "Greg_Hut_10":
		DialogExit();
	                     NextDiag.CurrentNode = NextDiag.TempNode;
	                     npchar = CharacterFromID("Greg");
                                         LAi_SetActorType(npchar);
                                         LAi_ActorGoToLocator(npchar, "goto", "goto6", "GothicGothicGregHut", -1.0);
		break;

		case "Greg_Hut_11":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужны бандитские доспехи.";
		link.l1.go = "Greg_Hut_12";		
		break;

		case "Greg_Hut_12":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_01.wav");
		dialog.text = "Сначало покажи на что ты способен, после этого поговорим.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_13";	
		break;

		case "Greg_Hut_13":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_02.wav");
		dialog.text = "Сначало ты должен убить всех бритвозубов.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_14";	
		break;

		case "Greg_Hut_14":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_JOB_15_00.wav");
		dialog.text = "...";
		link.l1 = "А, что это за звери которых я должен убить!";
		link.l1.go = "Greg_Hut_15";		
		break;

		case "Greg_Hut_15":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_JOB_01_01.wav");
		dialog.text = "Избавься от бритвозубов, другие существа не опасны.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_16";	
		break;

		case "Greg_Hut_16":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне кто-нибудь может помочь?";
		link.l1.go = "Greg_Hut_17";		
		break;

		case "Greg_Hut_17":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_01_01.wav");
		dialog.text = "Захвати с собой пару ребят.(Брендона и Мэтта).";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_18";	
		break;

		case "Greg_Hut_18":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_COMPADRES_01_02.wav");
		dialog.text = "Они всё равно болтаются без дела.";
		link.l1 = "...";
		link.l1.go = "exit";
                                          LocatorReloadEnterDisable("Trinidad_Jungle_03", "reload2_back", true);//закроем проход
		AddDialogExitQuestFunction("GothicGreg_JOB");
	                     npchar = CharacterFromID("GMorgan");
	                     npchar.dialog.currentnode = "Morgan_Francis";
	                     npchar = CharacterFromID("GBrandon");
	                     npchar.dialog.currentnode = "Brandon_Followme";	
	                     npchar = CharacterFromID("GMatt");
	                     npchar.dialog.currentnode = "Matt_Followme";	
		break;

		case "Greg_Hut_19":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_15_00.wav");
		dialog.text = "...";
		link.l1 = "Насчёт коньона?";
		link.l1.go = "Greg_Hut_20";		
		break;

		case "Greg_Hut_20":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_01_01.wav");
		dialog.text = "Да, что там?";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_21";	
		break;

		case "Greg_Hut_21":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_RAZORSDEAD_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я уничтожил всех бритвозубов...";
		link.l1.go = "Greg_Hut_22";		
		break;

		case "Greg_Hut_22":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_ABOUTCANYON_RAZORSDEAD_01_01.wav");
		dialog.text = "Хорошо, похоже от тебя есть польза.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_23";	
		break;

		case "Greg_Hut_23":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_15_00.wav");
		dialog.text = "...";
		link.l1 = "Есть для меня ещё работа?";
		link.l1.go = "Greg_Hut_24";		
		break;

		case "Greg_Hut_24":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_01_03.wav");
		dialog.text = "В южной башне всё ещё есть бандиты.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_25";		
		break;

		case "Greg_Hut_25":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_AUFTRAEGE2_01_04.wav");
		dialog.text = "Френсис должен был давно с ними разобраться, но ничего не сделал.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_26";		
		break;

		case "Greg_Hut_26":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужны бандитские доспехи.";
		link.l1.go = "Greg_Hut_27";		
		break;

		case "Greg_Hut_27":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_04.wav");
		dialog.text = "Следить за бандитами должен был Бонес, для него и предназначались эти доспехи.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_28";		
		break;

		case "Greg_Hut_28":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_05.wav");
		dialog.text = "Но быть может для этой работы больше подойдёт твоя кандидатура.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_29";		
		break;

		case "Greg_Hut_29":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_06.wav");
		dialog.text = "Возможно у тебя даже получится выбраться от туда живым.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_30";		
		break;

		case "Greg_Hut_30":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_07.wav");
		dialog.text = "Поговори с Бонесом, что бы он дал тебе броню, потом одевай её и отправляйся в лагерь бандитов.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_31";		
		break;

		case "Greg_Hut_31":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_01_08.wav");
		dialog.text = "Я хочу узнать, почему эти ублюдки припёрлись в нашу долину.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_32";		
		break;

		case "Greg_Hut_32":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITARMOR_15_09.wav");
		dialog.text = "...";
		link.l1 = "Будет сделано капитан.";
		link.l1.go = "exit";
	                     npchar = CharacterFromID("GBones");
	                     npchar.dialog.currentnode = "Bones_Givearmor";		
		break;


		case "Greg_Hut_33":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITPLATT2_15_00.wav");
		dialog.text = "...";
		link.l1 = "Бандиты в башне уничтожены.";
		link.l1.go = "Greg_Hut_34";	
		break;

		case "Greg_Hut_34":
		LocatorReloadEnterDisable("Shore129", "boat", false);
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		TakeNItems(pchar, "gold_dublon", 500);
		Log_Info("Вы получили 500 дублонов");
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_BANDITPLATT2_01_01.wav");
		dialog.text = "Прекрасно, хорошая работа. Вот твоя награда.";
		link.l1 = "...";
		link.l1.go = "Greg_Hut_35";		
		break;

		case "Greg_Hut_35":
	                  PlaySound("VOICE\Russian\gotica\GREG\DIA_ADDON_GREG_RAVENDEAD_01_03.wav");
		dialog.text = "А ты смелый, продолжай в том же духе.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_35";		
		break;

		case "Greg_Trinidad":
		dialog.text = "Скажу сразу, нет.";
		link.l1 = "...";
		link.l1.go = "exit";
		npchar.quest.PiratosGreg.Fail1 = "true";
		NextDiag.TempNode = "Greg_Hut_35";		
		break;

		case "Greg_Trinidad_work":
		dialog.text = "Слушаю.";
		link.l1 = "Я на горизонте ведел королевский фрегат 'Девентер' есть желание взять реванш. Вместе мы его можем отправить на дно.";
		link.l1.go = "Greg_Trinidad_work_1";	
		break;

		case "Greg_Trinidad_work_1":
		dialog.text = "'Девентер' здесь? Не могу поверить. Я хочу убедиться, давай встретимся на маяке, от туда хороший обзор, там и поговорим.";
		link.l1 = "Хорошо, встречаемся на маяке.";
		link.l1.go = "exit";
		npchar.quest.PiratosGreg.work = "true";
                                          pchar.quest.GothicEng_Paladinship_fail.over = "yes"; 
		NextDiag.TempNode = "Greg_Hut_35";	
		AddDialogExitQuest("GothicEng_PortSpeinToSea");	
		break;

		case "Greg_Trinidad_work_2":
		dialog.text = "Да это точно он, королевский корабль 'Девентер'. Чего ты хочешь за помощь, мне с ним в одиночку не справиться.";
		link.l1 = "Я помогаю тебе, ты мне. Речь идёт о совмесном участии при штурме Порт-оф-Спейна.";
		link.l1.go = "Greg_Trinidad_work_3_1";
	                     Group_DeleteGroup("GothicEng_Paladin");
	                     LAi_group_Delete("EnemyFight");	
		break;

		case "Greg_Trinidad_work_3_1":
		dialog.text = "Шутишь? Хотя с другой стороны, если я стану губернатором, пожалуй соглашусь.";
		link.l1 = "Ты хочешь стать губернатором этой чёртовой колонии?";
		link.l1.go = "Greg_Trinidad_work_4";	
		break;

		case "Greg_Trinidad_work_3":
		dialog.text = "Да, почему бы и нет. Брендон! Бери людей и отправляйся через джунгли к городским воротам. Городской гарнизон Порт-оф-Спейна не должен прийти на помощь защитникам форта. Когда мы вытесним солдат из форта, ударишь им в спину. Все понятно?";
		link.l1 = "Что, уже начинаем?";
		link.l1.go = "Greg_Trinidad_work_4";	
		break;

		case "Greg_Trinidad_work_4":
		dialog.text = "Я здесь не собираюсь торчать всю вечность, вперёд, я хочу видеть как тонет 'Девентер' и желаю занять кресло губернатора.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Greg_Hut_35";
	                     AddDialogExitQuestFunction("GothicEng_PortSpeinSquadronAttack");		
		break;

		case "Greg_Trinidad_work_5":
            dialog.text = "Так, с кораблями покончено. Теперь в дело вступает 'Яркендар' - пора превратить форт Порт-оф-Спейна в груду дымящихся развалин.";
		link.l1 = "В груду дымящихся развалин.";
		link.l1.go = "Greg_Trinidad_work_6";
		break;
		
		case "Greg_Trinidad_work_6":
            dialog.text = "'Яркендар' очень крепкий корабль с мощной артиллерией, с твоим не сравнится, поэтому на рожон не лезь, приближайся к форту аккуратно и не путайся у меня под орудиями. Вперед!";
		link.l1 = "...";
		link.l1.go = "Greg_Trinidad_work_7";
		break;
		
	case "Greg_Trinidad_work_7":
                     DialogExit();
 	NextDiag.TempNode = "Greg_Hut_35";
	npchar.DontDeskTalk = true;
	Group_FindOrCreateGroup("Greg_SeaGroup2");
	Group_SetTaskNone("Greg_SeaGroup2");
	Group_LockTask("Greg_SeaGroup2");
	sld = CharacterFromID("PortSpein Fort Commander");
	LAi_SetImmortal(sld, false);
	Ship_SetTaskAttack(SECONDARY_TASK, sti(npchar.index), sti(sld.index));
	DeleteAttribute(pchar, "GenQuest.MapClosedNoBattle");
	pchar.questTemp.GothicEng.PortSpein.Fort = "true";
	break;

		case "Greg_Trinidad_work_8":
            dialog.text = RandSwear()+"Жаркая была схватка! Все, бравые корсары, Порт-оф-Спейн наш. Больше некому сопротивляться, ха-ха-ха! "+pchar.name+", теперь с Брендоном отправляемся на переговоры к губернатору - он твой. Затребуй выкуп\nГорожане должны собрать откупные - ничего вывезти из города они не могли, команда Брендона караулили у ворот. Пускай купцы и прочие богачи раскошеливаются. Будет упорствовать - ты знаешь, что делать, учить не нужно.";
			link.l1 = "Хех! С удовольствием, капитан!";
			link.l1.go = "Greg_Trinidad_work_9";
		break;
		
		case "Greg_Trinidad_work_9":
                                         DialogExit();
	                    sld = CharacterFromID("GBrandon");
	                   LAi_SetActorType(sld);
                                        LAi_ActorFollow(sld, pchar, "", -1);
	                   sld = CharacterFromID("Greg");
	                   LAi_SetActorType(sld);
	                   LAi_ActorFollow(sld, pchar, "", -1);

		// запрещаем драки в городе, резиденции, форте
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_fort")], true);
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_town")], true);
		LAi_LocationFightDisable(&Locations[FindLocation("PortSpein_townhall")], true);
		LAi_LocationDisableOfficersGen("PortSpein_townhall", true);
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1 = "locator";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.location = "PortSpein_town";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.locator_group = "reload";
		pchar.quest.GothicEng_PortSpein_townhall.win_condition.l1.locator = "reload3_back";
		pchar.quest.GothicEng_PortSpein_townhall.function = "GothicEng_PortSpeinToResidence";
		break;

		case "Greg_Trinidad_work_10":
                                         dialog.text = "Отлично, теперь я буду губернатором этой чёртовой колонии, надеюсь возражений не будет у Виндзора?";
		link.l1 = "Не могу сказать, но пока приступай к новым обязаностям, капитан Грег.";
		link.l1.go = "Greg_Trinidad_work_11";
		break;
		
		case "Greg_Trinidad_work_11":
                                          DialogExit();
		AddDialogExitQuestFunction("GothicEng_PortSpeinFinal");
		break;


		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Greg_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Грег, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Greg_officer";
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
			dialog.text = "Ты чертовски удачлив, кэп. Я рад, что присоединился к тебе тогда, на Терксе. И проглоти меня акула, если я не поддержу тебя и в этом предприятии!";
			link.l1 = "Спасибо, Грег! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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

		// ============== Грабеж среди бела дня, попытка залезть в сундуки =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Грабеж среди бела дня! Это что же такое делается?! Ну, погоди, "+ GetSexPhrase("приятель","подруга") +"...", "Эй, ты чего это там копаешься?! Никак, вздумал"+ GetSexPhrase("","а") +" ограбить меня? Ну, тогда тебе конец...", "Постой, ты куда это полез"+ GetSexPhrase("","ла") +"? Да ты вор"+ GetSexPhrase("","овка") +", оказывается! Ну, считай, что ты приплыл"+ GetSexPhrase("","а") +", родн"+ GetSexPhrase("ой","ая") +"...");
			link.l1 = LinkRandPhrase("Дьявол!!", "Каррамба!!", "А-ать, черт!");
			link.l1.go = "PL_Q3_fight";
		break;
					
		// ======================== блок нод angry ===============>>>>>>>>>>>>>>>
		case "AngryRepeat_1":
            dialog.text = RandPhraseSimple(""+ GetSexPhrase("Пошел вон","Убирайся") +" отсюда!", "Вон из моей резеденции!");
			link.l1 = "Ай...";
		    link.l1.go = "AngryExitAgainWithOut";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Грегом через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         			dialog.text = "Тебе не стоит отвлекать меня от дела пустыми обращениями. Впредь результат может быть более плачевным...";
        			link.l1 = "Я понял"+ GetSexPhrase("","а") +".";
        			link.l1.go = NextDiag.TempNode;
        			CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryRepeat_2":
            dialog.text = RandPhraseSimple("Ты меня изрядно утомил"+ GetSexPhrase("","а") +", никакого общения.", "Я не хочу с тобой общаться, так что тебе лучше меня не беспокоить.");
		link.l1 = RandPhraseSimple("Ну как знаешь...", "Хм, ну что же...");
		    link.l1.go = "AngryExitAgain";
            if (CheckAttribute(npchar, "angry.terms")) //примиряемся с Грегом через 10 дней.
            {
                if (GetNpcQuestPastDayParam(npchar, "angry.terms") > sti(npchar.angry.terms))
                {
         		dialog.text = "Надеюсь, впредь ты не будешь утомлять меня пустыми разговорами, иначе мне придется тебя убить. Признаюсь, мне это будет очень неприятно.";
        		link.l1 = "Грег, ты можешь быть уверен - не буду...";
        		link.l1.go = NextDiag.TempNode;
        		CharacterDelAngry(npchar);
                }
            }
    	break;
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
		break;
		case "AngryExitAgainWithOut":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok");
            DoReloadCharacterToLocation("PuertoPrincipe_town","reload","houseS2");
		break;
		// <<<<<<<<<<<<============= блок нод angry =============================
		case "PuertoPrincipe_town":
            dialog.text = "Решить проблему? Да ты сам понимаешь, чего ты наворотил? В общем, принесешь мне миллион песо - я уговорю ребят, чтобы они забыли твои 'подвиги'. Нет - можешь катиться на все четыре стороны.";
		if (sti(Pchar.money) >= 1000000)
			{
			link.l1 = "Хорошо, я готов заплатить.";
			link.l1.go = "PuertoPrincipe_town_pay";
			}
			link.l2 = "Я всё понял. Ухожу.";
			link.l2.go = "PuertoPrincipe_town_exit";
		break;
		
	case "PuertoPrincipe_town_exit":
	DialogExit();
                  bDisableFastReload = true;//закрыть переход
	pchar.quest.pirate_in_town.win_condition.l1 = "ExitFromLocation";
	pchar.quest.pirate_in_town.win_condition.l1.location = pchar.location;
	pchar.quest.pirate_in_town.function = "TownPirate_battle";
	break;
		
		case "PuertoPrincipe_town_pay":
            dialog.text = "Вот и славно! Считай, что свою репутацию ты восстановил. Но впредь, я надеюсь, ты больше не будешь делать таких мерзостей.";
		link.l1 = "Не буду. Уж очень дорого они обходятся. Прощай...";
		link.l1.go = "exit";
		AddMoneyToCharacter(pchar, -1000000);
		pchar.GenQuest.Piratekill = 0;
		break;

		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ножками путь убегает
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // не работает на бессмертного мера :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // фантом солдат
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
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

