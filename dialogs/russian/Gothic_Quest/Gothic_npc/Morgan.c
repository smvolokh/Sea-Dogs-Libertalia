// Морган пират в команде Грега 
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
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Эй, ты!";
		link.l1.go = "Morgan_1";			
		break;

		case "Morgan_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_01.wav");
		dialog.text = "А, а, что тебе нужно.";
		link.l1 = "...";
		link.l1.go = "Morgan_2";			
		break;

		case "Morgan_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_02.wav");
		dialog.text = "Аллигатор Джек уже вернулся?";
		link.l1 = "...";
		link.l1.go = "Morgan_3";			
		break;

		case "Morgan_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_HELLO_07_03.wav");
		dialog.text = "А, нет, ну значит скоро вернётся. Приятных снов...";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "First time";		
		break;

		case "Morgan_Francis":
		dialog.text = "...";
		link.l1 = "Что ты думаешь о Френсисе?";
		link.l1.go = "Morgan_Francis_0";
		link.l2 = "Насчёт Хенка и Ангуса.";
		link.l2.go = "Morgan_Foundthem_0";
		link.l3 = "Мне надо идти.";
		link.l3.go = "GothicPiratosMorgan_exit";			
		break;

		case "GothicPiratosMorgan_exit":
	                     PlaySound("VOICE\Russian\GOTHIC\GG\EXIT_2.wav");
		dialog.text = "....";
		link.l1 = "Мне надо идти.";
		link.l1.go = "GothicPiratosMorgan_exit_1";
		break;

		case "GothicPiratosMorgan_exit_1":
		NextDiag.TempNode = "Morgan_Francis";
		DialogExit();	
		break;

		case "Morgan_Foundthem_0":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_00.wav");
		dialog.text = "...";
		link.l1 = "Насчёт Хенка и Ангуса.";
		link.l1.go = "Morgan_Foundthem_1";			
		break;

		case "Morgan_Foundthem_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_01.wav");
		dialog.text = "Не напомянай мне о них.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_2";			
		break;

		case "Morgan_Foundthem_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_02.wav");
		dialog.text = "Наверняка они попали в руки бандитов.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_3";			
		break;

		case "Morgan_Foundthem_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_03.wav");
		dialog.text = "А у Ангуса было моё кольцо.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_4";			
		break;

		case "Morgan_Foundthem_4":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_04.wav");
		dialog.text = "Нет, конечно же это было его кольцо, он выиграл у меня в кости.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_5";			
		break;

		case "Morgan_Foundthem_5":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_05.wav");
		dialog.text = "Ну я бы обязательно отыгрался, а теперь оно пропало навсегда.";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_6";			
		break;

		case "Morgan_Foundthem_6":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_06.wav");
		dialog.text = "Если найдёшь моё кольцо, принеси его мне, я тебе достойно заплачу.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_Francis";		
		break;

		case "Morgan_Francis_0":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что ты думаешь о Френсисе?";
		link.l1.go = "Morgan_Francis_1";			
		break;

		case "Morgan_Francis_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_01.wav");
		dialog.text = "Я не чего не имею против него, пока он ко мне не лезет.";
		link.l1 = "...";
		link.l1.go = "Morgan_Francis_2";			
		break;

		case "Morgan_Francis_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_15_02.wav");
		dialog.text = "...";
		link.l1 = "Он здесь начальник?";
		link.l1.go = "Morgan_Francis_3";			
		break;

		case "Morgan_Francis_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_03.wav");
		dialog.text = "Ха - ха - ха, он думает, что он главный...";
		link.l1 = "...";
		link.l1.go = "Morgan_Francis_4";			
		break;

		case "Morgan_Francis_4":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FRANCIS_07_04.wav");
		dialog.text = "Но когда вернётся Грег, Френсис снова займётся обычной работой - пилением досок...";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_Francis";		
		break;

		case "Morgan_Foundthem_end":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_00.wav");
		dialog.text = "...";
		link.l1 = "Насчёт Хенка и Ангуса.";
		link.l1.go = "Morgan_Foundthem_end_1";			
		break;

		case "Morgan_Foundthem_end_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_07.wav");
		dialog.text = "Ну, говори, что с ними?";
		link.l1 = "...";
		link.l1.go = "Morgan_Foundthem_end_2";		
		break;

		case "Morgan_Foundthem_end_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_01.wav");
		dialog.text = "...";
		link.l1 = "Я нашёл их.";
		link.l1.go = "Morgan_Foundthem_end_3";		
		break;

		case "Morgan_Foundthem_end_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_15_03.wav");
		dialog.text = "...";
		link.l1 = "Они мертвы.";
		link.l1.go = "Morgan_noring";		
		break;

		case "Morgan_noring":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_07_08.wav");
		dialog.text = "А, кольцо? Что с кольцом?";
		if (CheckCharacterItem(pchar, "jewelry28"))
		{
		link.l1 = "Вот оно.";
		link.l1.go = "Morgan_noring_1";	
		}
		else
		{
		link.l1 = "У них его небыло.";
		link.l1.go = "Morgan_noring_fail";	
		}
		break;

		case "Morgan_noring_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_15_00.wav");
		dialog.text = "...";
		link.l1 = "Вот оно.";
		link.l1.go = "Morgan_noring_2";		
		break;

		case "Morgan_noring_2":
		RemoveItems(PChar, "jewelry28", 1);
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_07_01.wav");
		dialog.text = "Да, это оно. Спасибо тебе...";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_3";		
		break;

		case "Morgan_noring_3":
                                          TakeNItems(pchar, "architects_table_12", 1);
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_GIVERING_07_02.wav");
		dialog.text = "Вот, возьми эту каменную табличку, возможно она на первый взгляд бесполезная, но Гаретт за неё хорошо заплатит.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";		
		break;

		case "Morgan_noring_fail":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_15_00.wav");
		dialog.text = "...";
		link.l1 = "У них его небыло.";
		link.l1.go = "Morgan_noring_fail_1";		
		break;

		case "Morgan_noring_fail_1":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_01.wav");
		dialog.text = "Ты должен его найти, должен.";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_fail_2";		
		break;

		case "Morgan_noring_fail_2":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_02.wav");
		dialog.text = "Это небольшое кольцо, украшенное сложными узорами.";
		link.l1 = "...";
		link.l1.go = "Morgan_noring_fail_3";		
		break;

		case "Morgan_noring_fail_3":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_FOUNDTHEM_NORING_07_03.wav");
		dialog.text = "Ты должен его найти, должен.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";		
		break;

		case "Morgan_01":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_15_00.wav");
		dialog.text = "...";
		link.l1 = "Для меня есть ещё какая-нибудь работа?";
		link.l1.go = "Morgan_02";		
		break;

		case "Morgan_02":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_07_01.wav");
		dialog.text = "Пока нет.";
		link.l1 = "...";
		link.l1.go = "Morgan_03";		
		break;

		case "Morgan_03":
	                     PlaySound("VOICE\Russian\gotica\MORGAN\DIA_ADDON_MORGAN_AUFTRAG2_07_02.wav");
		dialog.text = "Отдохни, полежи, выпей рома.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Morgan_01";			
		break;
		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Morgan_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Морган, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Morgan_officer";
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
			link.l1 = "Спасибо, Морган! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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