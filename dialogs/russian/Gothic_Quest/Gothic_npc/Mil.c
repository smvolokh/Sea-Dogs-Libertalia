

// Милиция Хориниса 
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
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_07_00.wav");
		dialog.text = "Стой.";
		link.l1 = "...";
		link.l1.go = "Mil_1";			
		break;

		case "Mil_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_15_07.wav");
		dialog.text = "...";
		link.l1 = "Что!";
		link.l1.go = "Mil_2";			
		break;

		case "Mil_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_07_10.wav");
		dialog.text = "От таких оборванцах как ты одни проблемы.";
		link.l1 = "...";
		link.l1.go = "Mil_3";			
		break;

		case "Mil_3":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_07_11.wav");
		dialog.text = "В городе и так хватает всякого сброда. Нам не нужны люди у которых нет денег.";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN";			
		break;

		case "First time_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PASSIERSCHEIN_07_04.wav");
		dialog.text = "Всё в порядке, проходи.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time_1";
		break;

		case "FIRSTWARN":
		dialog.text = "...";
                                         if (CheckCharacterItem(pchar, "VerifyPaper"))
		{
		link.l4 = "У меня есть пропуск.";
		link.l4.go = "FIRSTWARN_7_1";
		}
                                         if (CheckCharacterItem(pchar, "suit5"))
		{
		link.l5 = "Я хочу увидеться с кузнецом он должен починить кое какую утварь.";
		link.l5.go = "FIRSTWARN_8_1";
		}
                                         if (CheckCharacterItem(pchar, "cannabis1") && CheckCharacterItem(pchar , "cannabis2"))
		{
		link.l6 = "Я принёс травы для алхимика Константино.";
		link.l6.go = "FIRSTWARN_10_1";
		}
	                 if(CheckAttribute(pchar, "questTemp.GothicLodart") && pchar.questTemp.GothicHorinis == "HorinisHilda" && !CheckAttribute(npchar, "quest.HorinisHilda"))
		{
		link.l7 = "Меня послал фермер.";
		link.l7.go = "FIRSTWARN_9_1";
		}	



		link.l1 = "Мне нужно увидеть главу паладинов у меня важное сообщение для него.";
		link.l1.go = "FIRSTWARN_4_1";	
		link.l2 = "Я пришёл, что бы вступить в ополчение.";
		link.l2.go = "FIRSTWARN_5_1";
		link.l3 = "Вот 100 золотых, позволь мне пройти.";
		link.l3.go = "FIRSTWARN_6_1";				
		NextDiag.TempNode = "FIRSTWARN";
		break;

		case "FIRSTWARN_4_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно увидеть главу паладинов у меня важное сообщение для него.";
		link.l1.go = "FIRSTWARN_4_2";			
		break;

		case "FIRSTWARN_4_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_07_01.wav");
		dialog.text = "Ох, и, что это за важное сообщение!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_4_3";			
		break;

		case "FIRSTWARN_4_3":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я пришёл что бы получить Глаз Инноса.";
		link.l1.go = "FIRSTWARN_4_4";			
		break;

		case "FIRSTWARN_4_4":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_07_01.wav");
		dialog.text = "Что, никогда не слышал о нём, а что это такое!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_4_5";			
		break;

		case "FIRSTWARN_4_5":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_15_02.wav");
		dialog.text = "...";
		link.l1 = "Это очень важный артефакт.";
		link.l1.go = "FIRSTWARN_4_6";			
		break;

		case "FIRSTWARN_4_6":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_07_03.wav");
		dialog.text = "Ты не похож на важного посланника, у тебя есть какие-нибудь документы?";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_4_7";			
		break;

		case "FIRSTWARN_4_7":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_15_04.wav");
		dialog.text = "...";
		link.l1 = "Нет.";
		link.l1.go = "FIRSTWARN_4_8";			
		break;

		case "FIRSTWARN_4_8":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PALADINE_EYEINNOS_07_05.wav");
		dialog.text = "Тогда не трать моё время попусту.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "FIRSTWARN";	
		break;

		case "FIRSTWARN_5_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_MILIZWERDEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я пришёл, что бы вступить в ополчение.";
		link.l1.go = "FIRSTWARN_5_2";			
		break;

		case "FIRSTWARN_5_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_MILIZWERDEN_07_01.wav");
		dialog.text = "Да ты что, попробуй рассказать эту сказку у других ворот, может они и купятся на неё.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "FIRSTWARN";			
		break;

		case "FIRSTWARN_6_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_BRIBE_15_00.wav");
		dialog.text = "...";
		if (GetCharacterItem(pchar, "gold_dublon") >= 100)
		{
		link.l1 = "Вот 100 золотых, позволь мне пройти.";
		link.l1.go = "FIRSTWARN_6_2";
		}
		else
		{
		link.l1 = "Вот 100 золотых, позволь мне пройти.";
		link.l1.go = "FIRSTWARN_6_02";
		}			
		break;

		case "FIRSTWARN_6_2":
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 100);
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_BRIBE_07_01.wav");
		dialog.text = "100, 100 золотых это неплохо. Проходи конечно же...";
		link.l1 = "...";
		link.l1.go = "exit_7";			
		break;

		case "FIRSTWARN_6_02":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_BRIBE_07_03.wav");
		dialog.text = "Что, где, я не вижу золото...Проваливай.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "FIRSTWARN";		
		break;

		case "FIRSTWARN_7_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PASSIERSCHEIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "У меня есть пропуск.";
		link.l1.go = "FIRSTWARN_7_2";			
		break;

		case "FIRSTWARN_7_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PASSIERSCHEIN_07_01.wav");
		dialog.text = "Да, ну. И кого ты убил ради этой бумажки!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_7_3";			
		break;

		case "FIRSTWARN_7_3":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PASSIERSCHEIN_15_02.wav");
		dialog.text = "...";
		link.l1 = "Так ты позволишь мне пройти или нет!";
		link.l1.go = "FIRSTWARN_7_4";			
		break;

		case "FIRSTWARN_7_4":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_PASSIERSCHEIN_07_03.wav");
		dialog.text = "Ладно иди пока я не передумал.";
		link.l1 = "...";
		link.l1.go = "exit_7";			
		break;

		case "Exit_7":
		AddDialogExitQuestFunction("Horinisport4");
		NextDiag.TempNode = "First time_1";
		DialogExit();
		break;

		case "FIRSTWARN_8_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я хочу увидеться с кузнецом он должен починить кое какую утварь.";
		link.l1.go = "FIRSTWARN_8_2";			
		break;

		case "FIRSTWARN_8_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_07_01.wav");
		dialog.text = "Да, а почему ты сразу не сказал.";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_8_3";			
		break;

		case "FIRSTWARN_8_3":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_15_02.wav");
		dialog.text = "...";
		link.l1 = "Мне было просто интересно, как ты будешь реагировать.";
		link.l1.go = "FIRSTWARN_8_4";			
		break;

		case "FIRSTWARN_8_4":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_07_03.wav");
		dialog.text = "Что, ещё раз выкинешь такой номер и я покажу тебе как я реагирую на такие выходки, тупая деревенщина.";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_8_5";			
		break;

		case "FIRSTWARN_8_5":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_07_04.wav");
		dialog.text = "Хорошо, ты можешь проходить.";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_8_6";			
		break;

		case "FIRSTWARN_8_6":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_07_05.wav");
		dialog.text = "И если увидишь Лобарта, скажи ему, что бы лучше кормил своих овец, мы скоро зайдём к нему за ними.";
		link.l1 = "...";
		link.l1.go = "exit_7";			
		break;


		case "FIRSTWARN_9_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_15_13.wav");
		dialog.text = "...";
		link.l1 = "Меня послал фермер.";
		link.l1.go = "FIRSTWARN_9_2";			
		break;

		case "FIRSTWARN_9_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_07_15.wav");
		dialog.text = "Ты один из работников с фермы Лобарта, я никогда не видел тебя.";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_9_3";			
		break;

		case "FIRSTWARN_9_3":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_15_16.wav");
		dialog.text = "...";
		link.l1 = "Я недавно работаю на Лобарта.";
		link.l1.go = "FIRSTWARN_9_4";			
		break;

		case "FIRSTWARN_9_4":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_15_17.wav");
		dialog.text = "Что тебе нужно в городе!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_9_5";			
		break;

		case "FIRSTWARN_9_5":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_FIRSTWARN_15_18.wav");
		dialog.text = "...";
		link.l1 = "Что!";
		link.l1.go = "FIRSTWARN_9_6";			
		break;

		case "FIRSTWARN_9_6":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_MIL_310_STADTWACHE_ZUMSCHMIED_07_04.wav");
		dialog.text = "Хорошо, ты можешь проходить.";
		link.l1 = "...";
		link.l1.go = "exit_7";			
		break;

		case "FIRSTWARN_10_1":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я принёс травы для алхимика Константино.";
		link.l1.go = "FIRSTWARN_10_2";			
		break;

		case "FIRSTWARN_10_2":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_07_01.wav");
		dialog.text = "Правда. Ты же не будешь возражать если я взгляну на них, не так ли!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_10_3";			
		break;

		case "FIRSTWARN_10_3":
                                          if (GetCharacterItem(Pchar, "cannabis1") >= 10)
		{
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_07_02.wav");
		dialog.text = "Хм, выглядит неплохо, хорошо ты можешь пройти, но не создавай проблем, ты понял.";
		link.l1 = "...";
		link.l1.go = "exit_7";
		}
		else
		{
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_07_03.wav");
		dialog.text = "Что, что это такое!";
		link.l1 = "...";
		link.l1.go = "FIRSTWARN_10_04";
		}

                                          if (GetCharacterItem(Pchar, "cannabis1") >= 1 && GetCharacterItem(pchar , "cannabis2") >= 1 && GetCharacterItem(pchar , "cannabis3") >= 1 && GetCharacterItem(pchar , "cannabis4") >= 1 && GetCharacterItem(pchar , "cannabis5") >= 1 && GetCharacterItem(pchar , "cannabis6") >= 1)
		{
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_07_06.wav");
		dialog.text = "Какие травы! У тебя нет никаких трав, убирайся.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "FIRSTWARN";
		}
				
		break;

		case "FIRSTWARN_10_04":
	                     PlaySound("VOICE\Russian\gotica\MIL\DIA_ADDON_MIL_310_STADTWACHE_CONSTANTINO_07_05.wav");
		dialog.text = "В алхимии я не разбираюсь, но да же мне понятно, что этот пучок из разных травок не одному алхимику не понадобится.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "FIRSTWARN";				
		break;



















		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Alligator_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Джек, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Alligator_officer";
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
			link.l1 = "Спасибо, Джек! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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


		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit1":			
			DialogExit();
		break;



	}
}