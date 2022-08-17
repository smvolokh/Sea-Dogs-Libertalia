// Мо - вышибала
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
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_AERGER_01_01.wav");
			dialog.text = "Конечно, я мастер создавать проблемы, так что защищайся " + GetSexPhrase("кретин","сучка") + "?";
			link.l1 = "Успокойся, я сегодня не в настроении.";
			link.l1.go = "Exit";
			link.l2 = "Кого ты " + GetSexPhrase("кретином","сучкой") + " назвал, кретин.";
			link.l2.go = "Moe_16";			
			NextDiag.TempNode = "First time";
		break;

		case "First time2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_KNEIPE_01_01.wav");
			dialog.text = "Понимаешь, рано или поздно все заходят в кабак, так что лучше тебе заплатить прямо сейчас и больше эта проблема не будет волновать тебя.";
			link.l1 = "Успокойся, я просто хотел" + GetSexPhrase("","а") + " выпить пиво!";
			link.l1.go = "Moe_7";
			link.l2 = "Давай спросим, что об этом думает ополчение.";
			link.l2.go = "Moe_9";
			link.l3 = "О, так это портовый трактир, а я принял" + GetSexPhrase("","а") + " его за дворец губернатора!";
			link.l3.go = "Moe_14";
			link.l4 = "Хорошо, это всё что у меня есть!";
			link.l4.go = "Moe_15";
			link.l5 = "Понимаю, что бы пройти дальше мне придется сломать тебе пару ребер...";
			link.l5.go = "Moe_22";
			NextDiag.TempNode = "First time2";
		break;


		case "Moe":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_01_01.wav");
			dialog.text = "Тебе нечего здесь делать, малыш" + GetSexPhrase("","ка") + ".";
			link.l1 = "";
			link.l1.go = "Moe_001";
		break;

		case "Moe_001":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты имеешь что то против!";
			link.l1.go = "Moe_1";
		break;

		case "Moe_1":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_01_00.wav");
			dialog.text = "Эй, я не знаю тебя, чего тебе здесь нужно! Ты идешь в кабак.";
			link.l1 = "";
			link.l1.go = "Moe_002";
		break;

		case "Moe_002":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_15_00.wav");
			dialog.text = "";
			link.l1 = "Нет, я не иду в кабак.";
			link.l1.go = "Moe_2";
		break;

		case "Moe_2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_01.wav");
			dialog.text = "Я так и подумал, но это уже не важно, мы можем перейти прямо к делу.";
			link.l1 = "";
			link.l1.go = "Moe_003";
		break;

		case "Moe_003":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_AERGER_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты пытаешся создать мне проблемы?";
			link.l1.go = "Moe_3";
		break;

		case "Moe_3":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_02.wav");
			dialog.text = "Так как ты здесь новичок, я хочу тебе зделать заманчивое предложение, ты дашь мне 50 золотых монет и можешь идти дальше.";
			link.l1 = "50 монет за вход в кабак?";
			link.l1.go = "Moe_4";
		break;

		case "Moe_4":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_GEHEN_01_03.wav");
			dialog.text = "Это плата за свободный вход в кабак.";
			link.l1 = "";
			link.l1.go = "Moe_004";
		break;

		case "Moe_004":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_KNEIPE_15_00.wav");
			dialog.text = "";
			link.l1 = "Но, я не хочу идти в кабак.";
			link.l1.go = "Exit_2";
		break;

		case "Moe_7":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_RUHIG_15_00.wav");
			dialog.text = "Успокойся я просто хотел выпить пиво!";
			link.l1 = "";
			link.l1.go = "Moe_007";
		break;

		case "Moe_007":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_RUHIG_01_01.wav");
			dialog.text = "Хорошо, но это будет стоить тебе 50 монет, это плата за вход.";
			link.l1 = "";
			link.l1.go = "Moe_008";
		break;

		case "Moe_008":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_15_00.wav");
			dialog.text = "";
			link.l1 = "Хорошо я заплачу.";
			link.l1.go = "Moe_009";
		break;

		case "Moe_009":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		                   AddMoneyToCharacter(pchar, -50);
			dialog.text = "";
			link.l1 = "Вот держи.";
			link.l1.go = "Moe_8";
		break;

		case "Moe_8":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "Хорошо, гххх.... ты можешь идти!";
			link.l1 = "";
			link.l1.go = "Exit_3";
		break;

		case "Moe_9":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_15_00.wav");
			dialog.text = "";
			link.l1 = "Давай спросим, что думает об этом ополчение!!!";
			link.l1.go = "Moe_0010";
		break;

		case "Moe_0010":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_01.wav");
			dialog.text = "Ха, ополчения здесь нет, а ты знаешь почему их здесь не бывает.";
			link.l1 = "Ну и почему же!";
			link.l1.go = "Moe_10";
		break;

		case "Moe_10":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_02.wav");
			dialog.text = "Ты находишься в портовом квартале малыш" + GetSexPhrase("","ка") + ", ни кто из ополчения не осмелится вступать здесь в драку со мной.";
			link.l1 = "";
			link.l1.go = "Moe_11";
		break;

		case "Moe_11":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_MILIZ_01_03.wav");
			dialog.text = "Они только иногда заглядывают в красный фонарь, понимаешь, здесь есть только ты и я.";
			link.l1 = "";
			link.l1.go = "Moe_0012";
		break;

		case "Moe_0012":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_15_02.wav");
			dialog.text = "";
			link.l1 = "Но у меня нет с собой столько золота?";
			link.l1.go = "Moe_12";
			link.l2 = "Хорошо я заплачу.";
			link.l2.go = "Moe_009";
		break;


		case "Moe_12":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_03.wav");
			dialog.text = "Это не важно, просто отдай мне всё, что у тебя есть.";
			link.l1 = "Ни чего ты не получишь!";
			link.l1.go = "Moe_0013";
		break;

		case "Moe_0013":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_VERGISSES_15_00.wav");
			dialog.text = "";
			link.l1 = "Забудь об этом, ты не получишь ни цента!";
			link.l1.go = "Moe_13";
		break;

		case "Moe_13":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_VERGISSES_01_01.wav");
			dialog.text = "Тогда я возьму всё, что у тебя есть, а ты будешь лежать распростерт" + GetSexPhrase("ым","ой") + " на земле перед до мной.";
			link.l1 = "";
			link.l1.go = "Moe_16";
		break;


		case "Moe_14":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_WITZ_15_00.wav");
			dialog.text = "";
			link.l1 = "Ох, так это портовый трактир, а я то принял его за дворец губернатора.";
			link.l1.go = "Moe_0014";

		break;

		case "Moe_0014":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_WITZ_01_01.wav");
			dialog.text = "Эй, держи свои шуточки при себе " + GetSexPhrase("кретин","сучка") + ", или я заставлю тебя грызть булыжники из мостовой.";
			link.l1 = "";
			link.l1.go = "Exit_2";
			NextDiag.TempNode = "First time2";
		break;


		case "Moe_15":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_15_00.wav");
			dialog.text = "";
			link.l1 = "Хорошо, это всё что у меня есть!";
			link.l1.go = "Moe_0016";
		break;

		case "Moe_0016":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "Отлично, раз ты так" + GetSexPhrase("ой","ая") + " щедр" + GetSexPhrase("ый","ая") + " ты можешь отдать всё содержимое твоего кошелька.";
			link.l1 = "";
			link.l1.go = "Moe_16";
		break;


		case "Moe_22":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_PRUEGEL_15_00.wav");
			dialog.text = "";
			link.l1 = "Понимаю, что бы пройти дальше мне придется сломать тебе пару ребер?";
			link.l1.go = "Moe_0022";
			npchar.quest.Moe_win = 0;
		break;

		case "Moe_0022":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_PRUEGEL_01_01.wav");
			dialog.text = "Можешь попробовать малыш" + GetSexPhrase("","ка") + ", покажи мне на что ты способ" + GetSexPhrase("ен","на") + "?";
			link.l1 = "";
			link.l1.go = "Moe_16";
			npchar.quest.Moe_win = 0;
		break;
		
		case "Moe_16": // махач
			LAi_SetCurHPMax(pchar); 
			LAi_GetCharacterMaxEnergy(pchar);
			LAi_SetCurHPMax(npchar); 
			LAi_GetCharacterMaxEnergy(npchar);
			LAi_SetImmortal(npchar, false);
			LAi_group_Delete("EnemyFight");
			DialogExit();
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			// ставим проверяльщики
			LAi_SetCheckMinHP(pchar, 1, true, "Moe_HeroFail");
			LAi_SetCheckMinHP(npchar, 1, true, "Moe_HeroWin");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");	
	                                      DoQuestFunctionDelay("MOE_CHEERFRIEND", 0.3);
		break;

		case "Moe_17":
	                                      PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_05.wav");
			dialog.text = "Черт, неужели сегодня мне не повезло!";
			link.l1 = "";
			link.l1.go = "Moe_17_1";
                                                          LAi_LocationDisableOfficersGen("Roseau_town", false);//офицеров запускаем
		break;

		case "Moe_17_1": // побил Мо с первого раза
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "Хорошо, гххх.... ты можешь идти!";
			link.l1 = "";
			link.l1.go = "Moe_17_2";
		break;

		case "Moe_17_2": // побил Мо с первого раза
	                                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_4.wav");
			dialog.text = "";
			link.l1 = "Убирайся с дороги! Надеюсь ты запомнишь этот урок?";
			link.l1.go = "Exit_1"; // нода на выход
		                        sld = characterFromId("Moe");
		                        LAi_SetGroundSitType(sld);
			AddComplexSelfExpToScill(50, 50, 50, 50);
			AddCharacterExpToSkill(pchar, "Leadership", 80);
		LocatorReloadEnterDisable("Roseau_town", "reload13", false);//таверну открыть
		break;
		
		case "Moe_18": // побил Мо со второго или третьего раза
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ZAHLEN_01_06.wav");
			dialog.text = "Хорошо, гххх.... ты можешь идти!";
			link.l1 = "";
			link.l1.go = "Moe_18_1";
		break;

		case "Moe_18_1": // побил Мо со второго или третьего раза
	                                                PlaySound("VOICE\Russian\GOTHIC\GG\GG_DAMALS_4.wav");
			dialog.text = "";
			link.l1 = "Прочь с моей дороги! Надеюсь ты запомнишь этот урок?";
			link.l1.go = "Exit_1"; // нода на выход
		                        sld = characterFromId("Moe");
		                        LAi_SetGroundSitType(sld);
			AddComplexSelfExpToScill(20, 20, 20, 20);
			AddCharacterExpToSkill(pchar, "Leadership", 30);
		LocatorReloadEnterDisable("Roseau_town", "reload13", false);//таверну открыть
		break;
		
		case "Moe_19": // побили первый раз
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "Отлично, этого достаточно, я сегодня великодушен.";
			link.l1 = "Ах ты червяк, да я тебя....!";
			link.l1.go = "Moe_22";
			link.l2 = "Мы ещё посмотрим!";
			link.l2.go = "Exit_2"; // нода на выход

		break;
		
		case "guide_20": // побили второй раз
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
                                                                        AddMoneyToCharacter(pchar, -50);
			dialog.text = "Отлично, этого достаточно, я сегодня великодушен. Еще разок!";
			link.l1 = "Идите сюда, сударь, и я наконец преподам тебе урок!";
			link.l1.go = "Moe_22";
			link.l2 = "Нет, с меня, пожалуй, довольно.";
			link.l2.go = "Exit_2"; // нода на выход
			
		break;
		
		case "Moe_21": // побили третий раз
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_ALLES_01_01.wav");
			dialog.text = "Отлично, этого достаточно, я сегодня великодушен. Еще разок!";
			link.l1 = "Нет, с меня достаточно?";
			link.l1.go = "Exit_4"; // нода на выход
		break;
				
		case "Exit_1":
		                  sld = characterFromId("Moe");
                                                         LAi_SetActorType(sld);
                                                         LAi_ActorAnimation(sld, "Ground_StandUp", "Moe_Exit_1", 3.5);
			DialogExit();
		break;

		case "Exit_2":
	                                                PlaySound("VOICE\Russian\gotica\Moe\DIA_MOE_HALLO_REIZEN_01_01.wav");
			NextDiag.TempNode = "First time2";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_3":
	                                                LocatorReloadEnterDisable("Roseau_town", "reload13", false);
                                                                        AddMoneyToCharacter(pchar, -50);
			NextDiag.TempNode = "First time2";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit_4":
  			RemoveAllCharacterItems(PChar, true);
			NextDiag.TempNode = "First time";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}