// Тахана - полукровка-офицер
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
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
			dialog.text = "Вы что-то хотели моя хижина?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "Mirabella":
			dialog.text = "Что ты хотеть, бледнолицый? У Таханы нет для тебя слов.";
			link.l1 = "Тебя зовут Тахана? Хм. Послушай, женщина, я приш" + GetSexPhrase("ел","ла") + " не для того, чтобы пялить на тебя глаза, а чтобы спросить: зачем ты полез" + GetSexPhrase("","ла") + " в дом к этому толстяку?";
			link.l1.go = "Tahana_1";
		break;
		
		
		case "Tahana_1":
			dialog.text = "Тахана не рабыня, бел" + GetSexPhrase("ый","ая") + " госпо" + GetSexPhrase("дин","жа") + ". Ханна - свободная индеанка. Тахана хотеть служить у тебя. Индеанка уметь сражаться, любой пес умереть, прежде чем подойти к госпо" + GetSexPhrase("дин","жа") + ". Тахана уметь чистить и заряжать мушкет. Тахана уметь стрелять из мушкет.";
			link.l1 = "Хотя... Ты знаешь, Тахана, это неплохая идея. Мне нужны верные люди, а ты мне кажешься неплохим человеком. И из мушкета стрелять умеешь. Да и что ты будешь делать одна? Опять попадешься на краже, тогда уж точно повесят... Хорошо, оставайся. Но учти: спокойной жизни со мной не будет.";
			link.l1.go = "Tahana_13";
			link.l2 = "Так, довольно. Ступай с миром, краснокожая сестра. Да хранят тебя твои боги!";
			link.l2.go = "Tahana_exit";
		break;
		
		case "Tahana_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.Sharlie.Tichingitu");
		break;
		
		case "Tahana_13":
			dialog.text = "Тахана не бояться ничего, бел" + GetSexPhrase("ый","ая") + " госпо" + GetSexPhrase("дин","жа") + ". Тахана будет рада служить тебе. Тахана будет верен капитан до последний вздох.";
			link.l1 = "Хорошо. Добро пожаловать в команду, Тахана!";
			link.l1.go = "Tahana_hire";
		break;
		
		case "Tahana_hire":
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			LAi_SetImmortal(npchar, false);
			npchar.quest.OfficerPrice = sti(pchar.rank)*20;
			npchar.OfficerWantToGo.DontGo = true;
			npchar.CompanionDisable = true;
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			npchar.CanTakeMushket = true;
			LAi_SetOfficerType(npchar);
			NextDiag.CurrentNode = "Tahana_officer";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			DeleteAttribute(pchar, "questTemp.Sharlie.Tahana");
		break;
		
	//--> ----------------------------------- офицерский блок ------------------------------------------
		case "Tahana_officer":
			dialog.text = "Тахана слушать вас, капитан "+pchar.name+"!";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "Тахана, я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты... пойдешь со мной?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "Слушай мой приказ!";
                                                                        Link.l1.go = "stay_follow";
			link.l2 = "Пока ничего. Вольно!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Tahana_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "Какие быть приказания?";
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l4 = "Я хочу, чтобы ты держалась на определенном расстоянии от цели.";
				Link.l4.go = "TargetDistance";
			}
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
            dialog.Text = "Есть изменить дислокация!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "Есть изменить дислокация!";
            Link.l1 = "Вольно.";
            Link.l1.go = "Exit";
        break;
		
		//--> задать дистанцию стрельбы
		case "TargetDistance":
			dialog.text = "На какой именно, капитан? Указать Тахане в ярдах, но не больше, чем двадцать.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "Капитан, простить Тахану, но я вас не понимать.";
				link.l1 = "Извини, ошибочка вышла...";
				link.l1.go = "exit";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "Тахана быть стоять на месте, никуда не двигаться. Вы это хотеть, капитан?";
				link.l1 = "Да, именно это от тебя и требуется.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "Тахана не может встать от цель больше двадцать ярдов. Тогда она промахнуться.";
				link.l1 = "Хорошо, тогда держись на расстоянии в двадцать ярдов.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "Тахана все понять. Тахана занимать позиция на указанный расстояние.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit";
			npchar.MusketerDistance = iTemp;
		break;
		//<-- задать дистанцию стрельбы
	//<-- ----------------------------------- офицерский блок ----------------------------------------
	
	// на Тайясаль
		case "tieyasal":
			dialog.text = "Жизнь Тахана давно стать жизнью моего капитан. Индеанка не забывать, что капитан сделать для Тахана. Мирабелла идти за ним, куда сказать капитан, без упрек и колебаний.";
			link.l1 = "Спасибо, друг Тахана! Я рад" + GetSexPhrase("","а") + ", что не ошиб" + GetSexPhrase("ся","лась") + " в тебе.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "Когда мы отправляться?";
			link.l1 = "Немного позже. А пока мы подготовимся к походу.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21");
			npchar.quest.Tieyasal = "teleport";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}