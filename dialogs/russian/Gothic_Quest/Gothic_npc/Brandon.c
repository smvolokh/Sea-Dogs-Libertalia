// Брендон пират в команде Грега
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
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_HELLO_04_00.wav");
		dialog.text = "Вы только посмотрите, новичок!";
		link.l1 = "...";
		link.l1.go = "Brandon_1";			
		break;

		case "Brandon_1":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_HELLO_04_01.wav");
		dialog.text = "И к тому же сухопутная крыса.";
		link.l1 = "...";
		link.l1.go = "Brandon_2";			
		break;

		case "Brandon_2":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_HELLO_04_02.wav");
		dialog.text = "До настоящего пирата тебе ещё далеко.";
		link.l1 = "...";
		link.l1.go = "Brandon_3";			
		break;

		case "Brandon_3":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANYNEWS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Есть, что-нибудь новое?";
		link.l1.go = "Brandon_4";			
		break;

		case "Brandon_4":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANYNEWS_04_06.wav");
		dialog.text = "Погоди секунду.";
		link.l1 = "...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Brandon_5";
		AddDialogExitQuestFunction("GothicGreg_Brandon");			break;

		case "Brandon_5":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANYNEWS_04_07.wav");
		dialog.text = "Ха-ха-ха, насколько я вижу нет - всё по старому.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Brandon_3";
		AddDialogExitQuestFunction("GothicGreg_Brandon_4");
		break;

		case "Brandon_Followme":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_FOLLOWME_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты должен мне помочь.";
		link.l1.go = "Brandon_Followme_1";			
		break;

		case "Brandon_Followme_1":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANHEUERN_04_01.wav");
		dialog.text = "Это для меня новость и кто так решил.";
		link.l1 = "...";
		link.l1.go = "Brandon_Followme_2";			
		break;

		case "Brandon_Followme_2":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_FOLLOWME_15_02.wav");
		dialog.text = "...";
		link.l1 = "Так решил Грег, мы должны истребить бритвозубов в коньоне.";
		link.l1.go = "Brandon_Followme_3";			
		break;

		case "Brandon_Followme_3":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANHEUERN_04_03.wav");
		dialog.text = "Мм... Наконец-то здесь хоть что-нибудь происходит.";
		link.l1 = "...";
		link.l1.go = "Brandon_Followme_4";
		pchar.questTemp.Followme = sti(pchar.questTemp.Followme)+1;
	                     if (sti(pchar.questTemp.Followme) == 2) 
	                     {
                                          DoQuestFunctionDelay("FollowmeJOB", 1.1);
	                      }			
		break;

		case "Brandon_Followme_4":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_ANHEUERN_04_04.wav");
		dialog.text = "Что ж, пойдём, чем скорее мы разделаемся с ними, тем скорее можно будет вернуться.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicGreg_Brandon_5");	
		break;

		case "Brandon_Followme_5":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_TOOFAR_04_00.wav");
		dialog.text = "Достаточно, ты что, хочешь истребить всех зверей на острове?";
		link.l1 = "...";
		link.l1.go = "Brandon_Followme_6";			
		break;

		case "Brandon_Followme_6":
	                     PlaySound("VOICE\Russian\gotica\BRANDON\DIA_ADDON_BRANDON_TOOFAR_04_02.wav");
		dialog.text = "Я возвращаюсь в лагерь.";
		link.l1 = "...";
		link.l1.go = "exit";
		AddDialogExitQuestFunction("GothicGreg_Brandon_End");

	                     npchar = CharacterFromID("Greg");
	                     npchar.dialog.currentnode = "Greg_Hut_19";				break;

		case "Brandon_Followme_7":
            dialog.text = "Отыскал трех птичек, "+pchar.name+". Прятались в шкафах и под кроватью. Хороши милашки, как считаешь? Ха-ха-ха?!";
		link.l1 = "Недурны, весьма недурны, а главное - ухожены... и наверняка небезразличны его светлости дону Упрямцу.";
		link.l1.go = "Brandon_Followme_8";
		break;
		
		case "Brandon_Followme_8":
                                         DialogExit();
		sld = CharacterFromID("PortSpein_Mayor");
		sld.dialog.currentnode = "PortSpeinMayor_8";
		LAi_SetActorType(sld);
		LAi_ActorDialog(sld, pchar, "", -1, 0);
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