// Малет пастух на ферме Лобарта
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
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_PERM3_15_00.wav");
		dialog.text = "...";
		link.l1 = "Смотри не перетрудись!";
		link.l1.go = "Maleth_First_time";

		rItm = ItemsFromID("fennis_grass");
		rItm.shown = true;
		rItm.startLocation = "PortPax_Farm";
		rItm.startLocator = "flower"+i;

		break;

		case "Maleth_First_time":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_PERM3_08_01.wav");
		dialog.text = "Проваливай.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "First time";
		break;

		case "Maleth":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_00.wav");
			dialog.text = "Привет чужеземец.";
			link.l1 = "...";
			link.l1.go = "Maleth_1";			
		break;

		case "Maleth_1":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_01.wav");
			dialog.text = "Я видел как ты спустился с гор.";
			link.l1 = "...";
			link.l1.go = "Maleth_2";			
		break;

		case "Maleth_2":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_02.wav");
			dialog.text = "Тебе повезло, что ты не пришёл три недели назад.";
			link.l1 = "...";
			link.l1.go = "Maleth_3";			
		break;

		case "Maleth_3":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_03.wav");
			dialog.text = "Мы бы приняли тебя за беглого каторжника, а с ними у нас разговор короткий.";
			link.l1 = "...";
			link.l1.go = "Maleth_4";			
		break;

		case "Maleth_4":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_04.wav");
			dialog.text = "Ты выглядишь абсолютно измотанным.";
			link.l1 = "...";
			link.l1.go = "Maleth_5";			
		break;

		case "Maleth_5":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_15_00.wav");
			dialog.text = "...";
			link.l1 = "На меня напали бандиты в горах.";
			link.l1.go = "Maleth_6";			
		break;

		case "Maleth_6":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_08_01.wav");
			dialog.text = "Вот мерзкие отродье, это вероятно те же ублюдки, что увели овцу прошлой ночью.";
			link.l1 = "...";
			link.l1.go = "Maleth_7";			
		break;

		case "Maleth_7":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_08_02.wav");
			dialog.text = "Тебе ещё очень повезло, редко кому удаётся уйти от них живым.";
			link.l1 = "...";
			link.l1.go = "Maleth_8";			
		break;

		case "Maleth_8":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSDEAD_15_00.wav");
			dialog.text = "...";
			link.l1 = "Эти бандиты больше не будут беспокоить вас.";
			link.l1.go = "Maleth_9";			
		break;

		case "Maleth_9":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSDEAD_08_01.wav");
			dialog.text = "Почему! Они мертвы...";
			link.l1 = "...";
			link.l1.go = "Maleth_10";			
		break;

		case "Maleth_10":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSDEAD_15_02.wav");
			dialog.text = "...";
			link.l1 = "Они не на того напали.";
			link.l1.go = "Maleth_11";			
		break;

		case "Maleth_11":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSDEAD_08_03.wav");
			dialog.text = "Слава Инносу, вот, здесь немного, но я хочу чтобы ты принял это.";
			link.l1 = "...";
			link.l1.go = "Maleth_12";			
		break;

		case "Maleth_12":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSDEAD_08_04.wav");
			dialog.text = "Я расскажу остальным об этом.";
			link.l1 = "...";
			link.l1.go = "Maleth_exit";			
		break;

		case "Maleth_exit":
                                          pchar.questTemp.GothicMaleth = "MalethBanditDead";
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                          AddMoneyToCharacter(pchar, 10000);
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		AddDialogExitQuestFunction("Gothic_Maleth_1");
		break;

		case "Maleth_00":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_00.wav");
			dialog.text = "Привет чужеземец.";
			link.l1 = "...";
			link.l1.go = "Maleth_01";			
		break;

		case "Maleth_01":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_01.wav");
			dialog.text = "Я видел как ты спустился с гор.";
			link.l1 = "...";
			link.l1.go = "Maleth_02";			
		break;

		case "Maleth_02":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_02.wav");
			dialog.text = "Тебе повезло, что ты не пришёл три недели назад.";
			link.l1 = "...";
			link.l1.go = "Maleth_03";			
		break;

		case "Maleth_03":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_03.wav");
			dialog.text = "Мы бы приняли тебя за беглого каторжника, а с ними у нас разговор короткий.";
			link.l1 = "...";
			link.l1.go = "Maleth_04";			
		break;

		case "Maleth_04":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_04.wav");
			dialog.text = "Ты выглядишь абсолютно измотанным.";
			link.l1 = "...";
			link.l1.go = "Maleth_05";			
		break;

		case "Maleth_05":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_15_00.wav");
			dialog.text = "...";
			link.l1 = "На меня напали бандиты в горах.";
			link.l1.go = "Maleth_06";			
		break;

		case "Maleth_06":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_08_01.wav");
			dialog.text = "Вот мерзкие отродье, это вероятно те же ублюдки, что увели овцу прошлой ночью.";
			link.l1 = "...";
			link.l1.go = "Maleth_07";			
		break;

		case "Maleth_07":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITS_08_02.wav");
			dialog.text = "Тебе ещё очень повезло, редко кому удаётся уйти от них живым.";
			link.l1 = "...";
			link.l1.go = "Maleth_08";			
		break;

		case "Maleth_08":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSALIVE_15_00.wav");
			dialog.text = "...";
			link.l1 = "Я знаю где прячутся эти бандиты.";
			link.l1.go = "Maleth_09";			
		break;

		case "Maleth_09":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSALIVE_08_01.wav");
			dialog.text = "Ты хочешь напасть на них, я в такие игры не играю, это слишком опасно.";
			link.l1 = "...";
			link.l1.go = "Maleth_010";			
		break;

		case "Maleth_010":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSALIVE_08_02.wav");
			dialog.text = "Кроме того мне нужно присматривать за овцами.";
			link.l1 = "...";
			link.l1.go = "Maleth_011";			
		break;

		case "Maleth_011":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_BANDITSALIVE_08_03.wav");
			dialog.text = "Ну, а если ты думаешь, что можешь избавить нас от этих падонков, все на этой ферме будут благодарны тебе.";
			link.l1 = "...";
			link.l1.go = "MALETH_EQUIPMENT";			
		break;

		case "MALETH_EQUIPMENT":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_EQUIPMENT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Мне нужно снаряжение.";
		link.l1.go = "Maleth_eqylpment_1";			
		break;

		case "Maleth_eqylpment_1":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_EQUIPMENT_08_01.wav");
		dialog.text = "Могу представить, я честно скажу тебе, у нас нет ничего чем мы могли бы поделиться.";
		link.l1 = "...";
		link.l1.go = "Maleth_eqylpment_2";			
		break;

		case "Maleth_eqylpment_2":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_EQUIPMENT_08_02.wav");
		dialog.text = "Хотя, если ты можешь заплатить Лобарт продаст тебе кое-что.";
		link.l1 = "...";
		link.l1.go = "Maleth_eqylpment_3";			
		break;

		case "Maleth_eqylpment_3":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_EQUIPMENT_08_03.wav");
		dialog.text = "Ну, или ты можешь пойти к нему и спросить нет ли у него какой работы.";
		link.l1 = "...";
		link.l1.go = "Maleth_eqylpment_4";			
		break;

		case "Maleth_eqylpment_4":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_LOBART_15_00.wav");
		dialog.text = "...";
		link.l1 = "Где мне найти Лобарта.";
		link.l1.go = "Maleth_eqylpment_5";			
		break;

		case "Maleth_eqylpment_5":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_LOBART_08_01.wav");
		dialog.text = "На ферме конечно же, это ведь его ферма.";
		link.l1 = "...";
		link.l1.go = "Maleth_eqylpment_6";			
		break;

		case "Maleth_eqylpment_6":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_LOBART_08_02.wav");
		dialog.text = "И не пытайся надуть его, он избил и вышвырнул многих бездельников.";
		link.l1 = "...";
		link.l1.go = "Maleth_exit_2";			
		break;

		case "Maleth_exit_2":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
	                     pchar.quest.GothicBandit_fromMaleth0.win_condition.l1 = "location";
	                     pchar.quest.GothicBandit_fromMaleth0.win_condition.l1.location = "Hispaniola_Jungle_08";
	                     pchar.quest.GothicBandit_fromMaleth0.function = "Gothic_Maleth_2";

		break;


		case "MALETH_HALLO":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_HALLO_08_07.wav");
		dialog.text = "Что тебе нужно здесь!";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_1";			
		break;

		case "Maleth_Hallo_1":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я иду в город.";
		link.l1.go = "Maleth_Hallo_2";			
		break;

		case "Maleth_Hallo_2":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_08_01.wav");
		dialog.text = "Учитывая то как ты выглядишь тебе придётся подкупить стражу, что б попасть в город.";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_3";			
		break;

		case "Maleth_Hallo_3":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_08_02.wav");
		dialog.text = "И ты должен знать, что они хотят услышать.";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_4";			
		break;

		case "Maleth_Hallo_4":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_08_03.wav");
		dialog.text = "Они могут впустить тебя, если ты скажешь то, что они хотят услышать.";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_5";			
		break;

		case "Maleth_Hallo_5":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_15_04.wav");
		dialog.text = "...";
		link.l1 = "И что это?";
		link.l1.go = "Maleth_Hallo_6";			
		break;

		case "Maleth_Hallo_6":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_08_05.wav");
		dialog.text = "Ну например, что ты с фермы Лобарта и идёшь к городскому кузнецу.";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_7";			
		break;

		case "Maleth_Hallo_7":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_08_06.wav");
		dialog.text = "Ну это тебе не поможет, ты не похож на фермера.";
		link.l1 = "...";
		link.l1.go = "Maleth_Hallo_8";			
		break;

		case "Maleth_Hallo_8":
 	                   PlaySound("VOICE\Russian\gotica\MALETH\DIA_MALETH_TOTHECITY_15_07.wav");
		dialog.text = "...";
		link.l1 = "Понятно.";
		link.l1.go = "exit";		
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