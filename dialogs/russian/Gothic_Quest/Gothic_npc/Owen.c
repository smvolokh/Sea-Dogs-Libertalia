// Оуэн пират в команде Грега 
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
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела!";
		link.l1.go = "First time_1";		
		break;

		case "First time_1":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_WASMACHEN_13_02.wav");
		dialog.text = "Я здесь работаю как проклятый, гну спину, а они там в лагере валяются на солнышке.";
		link.l1 = "...";
		link.l1.go = "First time_2";			
		break;

		case "First time_2":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_PERM_13_01.wav");
		dialog.text = "Если бы я знал, что всё будет именно так, я бы не за что не стал пиратом.";
		link.l1 = "...";
		link.l1.go = "exit";			
		break;

		case "Owen":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела!";
		link.l1.go = "Owen_1";			
		break;

		case "Owen_1":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_01.wav");
		dialog.text = "А ты кто такой, один из бандитов!";
		link.l1 = "...";
		link.l1.go = "Owen_2";			
		break;

		case "Owen_2":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_15_02.wav");
		dialog.text = "...";
		link.l1 = "А что, похож...";
		link.l1.go = "Owen_3";			
		break;

		case "Owen_3":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_03.wav");
		dialog.text = "Одет ты так же как и мы, но я тебя не знаю.";
		link.l1 = "...";
		link.l1.go = "Owen_4";			
		break;

		case "Owen_4":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HELLO_13_04.wav");
		dialog.text = "Честно говоря, да...";
		link.l1 = "...";
		link.l1.go = "Owen_5";			
		break;

		case "Owen_5":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_WASMACHEN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что ты здесь делаешь?";
		link.l1.go = "Owen_6";			
		break;

		case "Owen_6":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_WASMACHEN_13_01.wav");
		dialog.text = "Рублю деревья для нашего лагеря.";
		link.l1 = "...";
		link.l1.go = "Owen_7";			
		break;

		case "Owen_7":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_WASMACHEN_13_02.wav");
		dialog.text = "Я здесь работаю как проклятый, гну спину, а они там в лагере валяются на солнышке.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry";			
		break;

		case "Owen_Henry":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HENRY_15_00.wav");
		dialog.text = "...";
		link.l1 = "Генри нужно дерево.";
		link.l1.go = "Owen_Henry_1";			
		break;

		case "Owen_Henry_1":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HENRY_13_01.wav");
		dialog.text = "Сначало я должен выяснить, что случилось с моим другом Малкомом.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_2";			
		break;

		case "Owen_Henry_2":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_PERM_15_00.wav");
		dialog.text = "...";
		link.l1 = "И...";
		link.l1.go = "Owen_Henry_3";			
		break;

		case "Owen_Henry_3":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMSTUNT_13_01.wav");
		dialog.text = "Мой приятель Малком пропал.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_4";			
		break;

		case "Owen_Henry_4":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMSTUNT_13_02.wav");
		dialog.text = "На нас напал один из этих луркеров.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_5";			
		break;

		case "Owen_Henry_5":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMSTUNT_13_03.wav");
		dialog.text = "Мы убежали в эту пещеру.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_6";			
		break;

		case "Owen_Henry_6":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMSTUNT_13_04.wav");
		dialog.text = "Но луркер последовал за нами.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_7";			
		break;

		case "Owen_Henry_7":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMSTUNT_13_08.wav");
		dialog.text = "Незнаю жив ли ещё Малком.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_8";			
		break;

		case "Owen_Henry_8":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\HOLDEINGOLD_2.wav");
		dialog.text = "...";
		link.l1 = "Я посмотрю, что можно сделать.";
		link.l1.go = "Owen_Henry_9";			
		break;

		case "Owen_Henry_9":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_PERM_13_01.wav");
		dialog.text = "Если бы я знал, что всё будет именно так, я бы не за что не стал пиратом.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_10";			
		break;

                     case "Owen_Henry_10":
                     NextDiag.CurrentNode = NextDiag.TempNode;
                     DialogExit();
	//Малком
	npchar = GetCharacter(NPC_GenerateCharacter("GMalcom", "citiz_50", "man", "man_A", 20, PIRATE, 1, false, "quest"));
	FantomMakeCoolFighter(npchar, 70, 50, 50, "blade_12", "pistol1", "bullet", 50);
          	npchar.name      = "Малком";
          	npchar.lastname      = "";
	LAi_SetActorType(npchar);
	LAi_ActorSetLayMode(npchar);
	ChangeCharacterAddressGroup(npchar, "Trinidad_GGrot", "goto", "goto1");

            pchar.quest.GothicMalcom.win_condition.l1 = "location";
            pchar.quest.GothicMalcom.win_condition.l1.location = "Trinidad_GGrot";
            pchar.quest.GothicMalcom.function = "GothicMalcom";
            break;

		case "Owen_Henry_Malcom":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMDEAD_15_00.wav");
		dialog.text = "...";
		link.l1 = "Твой приятель Малком мёртв.";
		link.l1.go = "Owen_Henry_Malcom_1";			
		break;

		case "Owen_Henry_Malcom_1":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMDEAD_13_01.wav");
		dialog.text = "Я так и знал, бедняга, я должен был ему помочь.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_Malcom_2";			
		break;

		case "Owen_Henry_Malcom_2":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMDEAD_13_02.wav");
		dialog.text = "А ты храбрец...";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_Malcom_3";			
		break;

		case "Owen_Henry_Malcom_3":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_MALCOMDEAD_13_03.wav");
		dialog.text = "Я бы не за что не смог спуститься в эту яму.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_Malcom_4";			
		break;

		case "Owen_Henry_Malcom_4":
	                     PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HENRY_13_02.wav");
		dialog.text = "Раслабся, получит он рано или поздно своё дерево.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_Malcom_5";			
		break;

		case "Owen_Henry_Malcom_5":
	                  PlaySound("VOICE\Russian\gotica\OWEN\DIA_ADDON_OWEN_HENRY_13_03.wav");
		dialog.text = "Так ему и передай.";
		link.l1 = "...";
		link.l1.go = "Owen_Henry_Malcom_6";			
		break;

		case "Owen_Henry_Malcom_6":
	                     npchar = CharacterFromID("GMalcom");
	                     npchar.lifeday = 0;
	                     LAi_SetActorType(npchar);
	                     LAi_ActorGoToLocation(npchar, "reload", "reload2_back", "none", "", "", "", 1.0);
	                     npchar = CharacterFromID("GHenry");
	                     npchar.dialog.currentnode = "GothicPiratosOwen_Malcom";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;
		
		//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Owen_officer":
			dialog.text = "Слушаю, тебя, кэп. Что скажешь?";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Оувен, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Owen_officer";
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
			link.l1 = "Спасибо, Оувен! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","ась") + " в тебе.";
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

		case "Exit":			
		DialogExit();
		break;



	}
}