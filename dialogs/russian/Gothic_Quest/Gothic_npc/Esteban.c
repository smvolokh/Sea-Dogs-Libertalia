// Естебан один из бандитов
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
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_HI_07_00.wav");
		dialog.text = "Так ты тот самый парень, что с боем пробился в лагерь?";
		link.l1 = "...";
		link.l1.go = "Esteban_1";			
		break;

		case "Esteban_1":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_HI_15_01.wav");
		dialog.text = "...";
		link.l1 = "Слухи быстро распространяются...";
		link.l1.go = "Esteban_2";			
		break;

		case "Esteban_2":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_HI_07_02.wav");
		dialog.text = "Франко был крепким орешком, никто не хотел связываться с ним, никто, кроме тебя.";
		link.l1 = "...";
		link.l1.go = "Esteban_3";			
		break;

		case "Esteban_3":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_HI_07_03.wav");
		dialog.text = "Просто, что бы сразу прояснить ситуацию, если ты затеешь то же сомной, я убью тебя.";
		link.l1 = "Я так понимаю это Ангус и Хенк, кто убил их?";
		link.l1.go = "Esteban_4";			
		break;

		case "Esteban_4":
		dialog.text = "Их убил Хуан, один из людей Франко, с ним ты можешь делать всё, что угодно, мои люди не будут препятствовать. Его ты сможешь найти в подтопленном подвале.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Esteban_5";
		AddDialogExitQuestFunction("Gothic_GMattJunglefortexitAttack_6");	
		break;

		case "Esteban_5":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_HI_07_03.wav");
		dialog.text = "Просто, что бы сразу прояснить ситуацию, если ты затеешь то же сомной, я убью тебя.";
		link.l1 = "...";
		link.l1.go = "Esteban_6";			
		break;

		case "Esteban_6":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_NOT_15_00.wav");
		dialog.text = "...";
		link.l1 = "Я подумаю об этом.";
		link.l1.go = "Esteban_7";			
		break;

		case "Esteban_7":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_FIGHT_07_03.wav");
		dialog.text = "Эй, ещё одно слово и моим охранникам придётся применить силу.";
		link.l1 = "...";
		link.l1.go = "Esteban_8";			
		break;

		case "Esteban_8":
	                     PlaySound("VOICE\Russian\gotica\ESTEBAN\DIA_ADDON_ESTEBAN_FIGHT_15_04.wav");
		dialog.text = "...";
		link.l1 = "Каким охранникам?";
		link.l1.go = "Esteban_9";			
		break;

		case "Esteban_9":
		NextDiag.TempNode = "Esteban_5";	
		DialogExit();
		AddDialogExitQuestFunction("Gothic_GMattJunglefortexitAttack_5");	
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