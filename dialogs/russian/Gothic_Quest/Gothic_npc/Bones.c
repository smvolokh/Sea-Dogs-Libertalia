// Бонес пират в команде Грега 
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
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_HELLO_15_00.wav");
		dialog.text = "...";
		link.l1 = "Как дела!";
		link.l1.go = "Bones_1";			
		break;

		case "Bones_1":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_HELLO_01_01.wav");
		dialog.text = "Грех жаловаться, немного скучновато, но за то работать не приходится.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bones_work";
		break;

		case "Bones_work":
		dialog.text = "...";
		link.l1 = "Что ты скажешь о Френсисе?";
		link.l1.go = "Bones_Francis";
		link.l2 = "Ты можешь меня чему-нибудь научить?";
		link.l2.go = "Bones_Train";				
		break;

		case "Bones_Train":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_TRAIN_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты можешь меня чему-нибудь научить?";
		link.l1.go = "Bones_Train_1";			
		break;

		case "Bones_Train_1":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_TRAIN_01_01.wav");
		dialog.text = "Извени, у меня сейчас совсем нет времени.";
		link.l1 = "...";
		link.l1.go = "Bones_Train_2";			
		break;

		case "Bones_Train_2":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_TRAIN_01_02.wav");
		dialog.text = "Мне нужно тренироваться.";
		link.l1 = "...";
		link.l1.go = "Bones_Train_3";			
		break;

		case "Bones_Train_3":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_WORK_01_01.wav");
		dialog.text = "Я готовлюсь к новому заданию которое дал мне Грег.";
		link.l1 = "...";
		link.l1.go = "Bones_Train_4";			
		break;

		case "Bones_Train_4":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_WORK_15_02.wav");
		dialog.text = "...";
		link.l1 = "Что это за задание?";
		link.l1.go = "Bones_Train_5";			
		break;

		case "Bones_Train_5":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_WORK_01_03.wav");
		dialog.text = "Я не могу тебе сказать.";
		link.l1 = "...";
		link.l1.go = "Bones_Train_6";			
		break;

		case "Bones_Train_6":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_WORK_01_04.wav");
		dialog.text = "Не обижайся приятель, но я тяжело трудился, что бы получить это задание и не хочу снова его потерять.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bones_work";			
		break;

		case "Bones_Francis":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_FRANCIS_15_00.wav");
		dialog.text = "...";
		link.l1 = "Что ты скажешь о Френсисе?";
		link.l1.go = "Bones_Francis_1";			
		break;

		case "Bones_Francis_1":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_FRANCIS_01_03.wav");
		dialog.text = "Посмотри вокруг, работает только Генри и его люди.";
		link.l1 = "...";
		link.l1.go = "Bones_Francis_2";			
		break;

		case "Bones_Francis_2":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_FRANCIS_01_04.wav");
		dialog.text = "Морган целыми днями либо спит, либо пьёт самогон.";
		link.l1 = "...";
		link.l1.go = "Bones_Francis_3";			
		break;

		case "Bones_Francis_3":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_FRANCIS_01_05.wav");
		dialog.text = "При Греге токого не бывает, если ты бездельничаешь ты получаешь по шее, вот и всё.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bones_work";		
		break;

		case "Bones_Givearmor":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_15_00.wav");
		dialog.text = "...";
		link.l1 = "Ты должен отдать мне доспехи бандитов, приказ Грега.";
		link.l1.go = "Bones_Givearmor_1";			
		break;

		case "Bones_Givearmor_1":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_01_01.wav");
		dialog.text = "Приказ Грега? Хо... а я то думал, мне действительно придётся идти на это задание.";
		link.l1 = "...";
		link.l1.go = "Bones_Givearmor_2";			
		break;

		case "Bones_Givearmor_2":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_01_02.wav");
		dialog.text = "Разведка в лагере бандитов, это просто самоубийство.";
		link.l1 = "...";
		link.l1.go = "Bones_Givearmor_3";			
		break;

		case "Bones_Givearmor_3":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_01_03.wav");
		dialog.text = "Пусть уж лучше Грег взвалит на меня, какую нибудь скучную работу.";
		link.l1 = "...";
		link.l1.go = "Bones_Givearmor_4";			
		break;

		case "Bones_Givearmor_4":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_15_04.wav");
		dialog.text = "...";
		link.l1 = "Доспехи...";
		link.l1.go = "Bones_Givearmor_5";			
		break;

		case "Bones_Givearmor_5":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_01_05.wav");
		dialog.text = "Да, конечно, вот они.";
		link.l1 = "...";
		link.l1.go = "Bones_Givearmor_6";			
		break;

		case "Bones_Givearmor_6":
	                     PlaySound("VOICE\Russian\gotica\BONES\DIA_ADDON_BONES_GIVEARMOR_01_06.wav");
		dialog.text = "Будь осторожнее с этими бандитами шутки плохи.";
		link.l1 = "...";
		link.l1.go = "exit";			
		NextDiag.TempNode = "Bones_work";
		GiveItem2Character(pchar, "suit4");
		EquipCharacterbyItem(pchar, "suit4");
		Log_Info("Вы получили бандитские доспехи");

		pchar.quest.Gothic_Henry.win_condition.l1 = "location";
		pchar.quest.Gothic_Henry.win_condition.l1.location = "Trinidad_Jungle_03";
		pchar.quest.Gothic_Henry.function = "Gothic_HenryTail";		
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