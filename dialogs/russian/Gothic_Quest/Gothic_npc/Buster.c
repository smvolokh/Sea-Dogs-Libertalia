// Бастер наёмник генерала Ли 
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
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_13_00.wav");
			dialog.text = "Посмотрите кто у нас здесь, я случайно тебя не знаю!";
			link.l1 = "...";
			link.l1.go = "Buster_1";			
		break;

		case "Buster_1":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_GOINGTOFARM_15_00.wav");
			dialog.text = "...";
			link.l1 = "Как скажешь, я хочу увидеть Ленд Лорда.";
			link.l1.go = "Buster_2";			
		break;

		case "Buster_2":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_GOINGTOFARM_13_01.wav");
			dialog.text = "Да, хм, ты не кажешься мне таким уж опасным!";
			link.l1 = "...";
			link.l1.go = "Buster_3";			
		break;

		case "Buster_3":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMNODANGER_15_00.wav");
			dialog.text = "...";
			link.l1 = "Тебе правильно кажется!";
			link.l1.go = "Buster_4";			
		break;

		case "Buster_4":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMNODANGER_13_01.wav");
			dialog.text = "Да за долгие годы я научился распознавать такие вещи приятель.";
			link.l1 = "...";
			link.l1.go = "Buster_5";				
		break;

		case "Buster_5":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMNODANGER_13_02.wav");
			dialog.text = "Нам постоянно приходится сражатся с орками или со стражниками из города, они такие настырные, ха-ха-ха.";
			link.l1 = "...";
			link.l1.go = "Buster_6";					
		break;

		case "Buster_6":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMPRESSIVE_15_00.wav");
			dialog.text = "...";
			link.l1 = "Потрясающе...";
			link.l1.go = "Buster_7";					
		break;

		case "Buster_7":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMPRESSIVE_13_01.wav");
			dialog.text = "Хе-хе-хе это наша работа парень, мы даже делаем свои собственное оружие и доспехи.";
			link.l1 = "...";
			link.l1.go = "Buster_8";				
		break;

		case "Buster_8":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_IMPRESSIVE_13_02.wav");
			dialog.text = "Мы каждый день ходим рука - обруку со смертью, но деревенщене вроде тебя, этого не понять.";
			link.l1 = "...";
			link.l1.go = "Buster_9";					
		break;

		case "Buster_9":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_REALORCS_15_00.wav");
			dialog.text = "...";
			link.l1 = "Ты имеешь ввиду настоящих орков - этих больших тварей...";
			link.l1.go = "Buster_10";				
		break;

		case "Buster_10":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_REALORCS_13_01.wav");
			dialog.text = "Эх, я имею ввиду... Минутку ты, что издеваешься надомной?";
			link.l1 = "...";
			link.l1.go = "Buster_11";					
		break;

		case "Buster_11":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_REALORCS_15_02.wav");
			dialog.text = "...";
			link.l1 = "Даже и не думал.";
			link.l1.go = "Buster_12";				
		break;

		case "Buster_12":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_REALORCS_13_03.wav");
			dialog.text = "Ах ты червь навозный, ты сам напрашиваешься - да!";
			link.l1 = "...";
			link.l1.go = "Buster_13";					
		break;

		case "Buster_13":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_REALORCS_13_04.wav");
			dialog.text = "Тогда давай покажи на что ты способен - герой...";
			link.l1 = "...";
			link.l1.go = "Buster_14";					
		break;

		case "Buster_14":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_JUSTJOKING_15_00.wav");
			dialog.text = "...";
			link.l1 = "Я просто шучу...";
			link.l1.go = "Buster_15";					
		break;

		case "Buster_15":
	                                   PlaySound("VOICE\Russian\gotica\BUSTER\DIA_BUSTER_HELLO_JUSTJOKING_13_01.wav");
			dialog.text = "По осторожнее с такими шутками, а теперь проваливай.";
			link.l1 = "...";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";		
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