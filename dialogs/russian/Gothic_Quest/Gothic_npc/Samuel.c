#include "DIALOGS\russian\Rumours\Common_rumours.c"
#include "interface\ship.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sLoc;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	bool bLock = (CheckAttribute(pchar, "GenQuest.BrothelLock")) && (GetCharacterIndex("Mary") != -1);
	bool bLock1 = (CheckAttribute(pchar, "questTemp.Saga.Helena_officer")) && (IsOfficer(characterFromId("Helena")));

	int iTest, iTemp;
	string sTemp;
    iTest = FindColony(NPChar.City); // город 
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	bool ok;

	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar,
					LinkRandPhrase("В городе поднята тревога, тебя всюду ищут! На твоем месте я бы не стал здесь задерживаться.", "Вся городская стража рыщет по городу в поисках тебя. Я не идиот и разговаривать с тобой не буду!", "Беги, "+ GetSexPhrase("приятель","подруга") +", пока солдаты не сделали из тебя решето..."),
					LinkRandPhrase("Что тебе нужно, "+ GetSexPhrase("негодяй","мерзавка") +"?! Городская стража уже взяла твой след, далеко тебе не уйти"+ GetSexPhrase(", грязный пират!","") +"", "Грязн"+ GetSexPhrase("ый","ая") +" убийца, вон из моего дома! Стража!!", "Я не боюсь тебя, мерзав"+ GetSexPhrase("ец","ка") +"! Скоро тебя повесят, далеко тебе не уйти..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("Хех, тревога для меня не проблема...", "Им меня ни за что не поймать."),
					RandPhraseSimple("Заткни свою пасть, " + GetWorkTypeOfMan(npchar, "") + ", а не то вырву твой поганый язык!", "Хех, " + GetWorkTypeOfMan(npchar, "") + ", а все туда же - пиратов ловить! Вот что я тебе скажу, приятель: сиди тихо и будешь жить..."));
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				dialog.text = TimeGreeting() + "! Добро пожаловать, " + GetAddress_Form(NPChar) + "! Меня зовут "+GetFullName(npchar)+" и я всегда к вашим услугам.";
				Link.l1 = "Посмотрим... Я " + GetFullName(pchar) + ". Рад с вами познакомиться, "+npchar.name+".";
				Link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "А-а, это же мой старый знакомый, капитан "+GetFullName(pchar)+"! Рад вас видеть, старина! Рому, местных деревенских девочек?";
				if (makeint(pchar.money) >= 5)
				{
				link.l1 = "Дай мне рома, "+npchar.name+".";
				link.l1.go = "drink_RUM";
				}
				if (makeint(pchar.money) >= 35)
				{
				link.l2 = "Я хочу чего нибудь по крепче?";
				link.l2.go = "drink_STRONGER";
				}
				link.l3 = LinkRandPhrase("Расскажи мне последние новости?","Что новенького в этих краях?","Как течет жизнь на суше?");
				link.l3.go = "rumours_tavern";
			                     Link.l4 = "Мне нужна команда, " + NPChar.name + ".";
			                     Link.l4.go = "crew hire";
				  link.l5 = "Нет, ничего не надо, "+npchar.name+". Я просто зашел поздороваться с тобой.";
				link.l5.go = "exit";

		}

	if (CheckAttribute(npchar, "quest.SAMUEL_100"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 100)
		{
		link.l2 = "Вот твоё золото.";
		link.l2.go = "drink_Grog_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_150"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 150)
		{
		link.l2 = "Вот твоё золото.";
		link.l2.go = "drink_Rumm_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_250"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 250)
		{
		link.l2 = "Вот твоё золото.";
		link.l2.go = "drink_LOUSHAMMER_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_500"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 500)
		{
		link.l2 = "Вот твоё золото.";
		link.l2.go = "drink_SCHNELLERHERING_7";
		}	
                       }
	if (CheckAttribute(npchar, "quest.SAMUEL_700"))
	{
		if (GetCharacterItem(pchar, "gold_dublon") >= 700)
		{
		link.l2 = "Вот твоё золото.";
		link.l2.go = "drink_LOUSDOUBLEHAMMER_7";
		}	
                       }


			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_HELLO_14_00.wav");
			dialog.text = "А, новичок!!!";
			link.l1 = "";
			link.l1.go = "meeting_1";
		break;

		case "meeting_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_HELLO_14_01.wav");
			dialog.text = "И так, чего ты хочешь - рому или чего по крепче?";
			link.l1 = "Я здесь впервые, и хотел бы немного больше узнать об этом поселении.";
			link.l1.go = "info";
		break;
		
		case "info":
			dialog.text = "А о чем тут узнавать-то? У нас изо дня в день одно и то же: скука, палящее солнце и пыль. Население сплошь состоит из загорелых ребят. Также у нас всегда можно найти пару-тройку искателей приключений и прочих авантюристов и проходимцев, которых сюда привлекают золотые копи\nЗаходят сюда и джентльмены, капитаны кораблей, вроде вас: продать рабов за золотые слитки или купить драгоценные металлы!";
			link.l1 = "А кто тут всем заправляет!";			
			link.l1.go = "info_1";
		break;

		case "info_1":
			dialog.text = "Камондор Бартоломью Роджерс!";
			link.l1 = "Бартоломью Роджерс!";			
			link.l1.go = "info_2";
		break;

		case "info_2":
			dialog.text = "Да, удачливый капитан и лидер - будущий адмирал. Эх, не хватает капитана Грега!";
			link.l1 = "Грега? Может ты из его команды?";			
			link.l1.go = "info_3";
		break;

		case "info_3":
			dialog.text = "Тише, тише, здесь не принято об этом говорить. А я тебя парень сразу узнал? Ты ведь тот который всех доставал вопросами?";
			link.l1 = "Да, это я. Я тоже тебя узнал - Самуил! Ты попрежнему занимаешься горячительными напитками? Есть что - нибудь выпить?";			
			link.l1.go = "info_STRONGER_00";
		break;

		case "info_STRONGER_00":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_00.wav");
		dialog.text = "";
		link.l1 = "Я хочу чего - нибудь по крепче?";
		link.l1.go = "drink_STRONGER_01";
		break;

		case "drink_STRONGER_01":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_01.wav");
		dialog.text = "Я вижу родственную душу! Я и сам люблю экспериментировать?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_02";
		break;

		case "drink_STRONGER_02":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_02.wav");
		dialog.text = "Хорошая выпивка должна быть чистой, крепкой, а глодку продирать как жидкий огонь!";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_03";
		break;

		case "drink_STRONGER_03":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_03.wav");
		dialog.text = "Такое не часто встречается, но я слишком много балтаю а ты хочешь выпить?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_04";
		break;

		case "drink_STRONGER_04":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_04.wav");
	                   dialog.text = "Вот мой собственный рецепт - тебе понравится! Я называю этот напиток - быстрая селедка.";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_05";
		break;

		case "drink_STRONGER_05":
		PlaySound("interface\important_item.wav");
		dialog.text = "";
		link.l1 = "Вздрогнули?";
		link.l1.go = "drink_STRONGER_06";
		break;

		case "drink_STRONGER_06":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
		dialog.text = "";
		link.l1 = "Вот, чёрт!!!";
		link.l1.go = "drink_STRONGER_07";
		break;

		case "drink_STRONGER_07":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_05.wav");
	                   dialog.text = "";
		link.l1 = "Впечатляет!!!";
		link.l1.go = "drink_STRONGER_08";
		break;

		case "drink_STRONGER_08":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_06.wav");
	                   dialog.text = "Ха, ха - это точно!!!";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_09";
		break;

		case "drink_STRONGER_09":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_07.wav");
	                   dialog.text = "А тебе не встречались рецепты напитков, если встретятся - обязательно расскажи мне.";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_010";
		break;

		case "drink_STRONGER_010":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_08.wav");
	                   dialog.text = "Хочешь ещё?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_011";
		break;

		case "drink_STRONGER_011":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_09.wav");
	                   dialog.text = "Что тебе ещё приготовить?";
		link.l1 = "";
		link.l1.go = "exit";
		break;




		case "drink_RUM":
	                  PlaySound("VOICE\Russian\GOTHIC\GG\RUM_1.wav");
		dialog.text = "";
		link.l1 = "Дай мне рома!!!";
		link.l1.go = "drink_RUM_1";
		break;

		case "drink_RUM_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_01.wav");
		dialog.text = "А, ром для моряка - всё равно, что молоко матери - вот бери.";
		link.l1 = "";
		link.l1.go = "drink_RUM_2";
		break;

		case "drink_RUM_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_02.wav");
		dialog.text = "У рома может быть небольшой привкус рыбы, у меня остались только бочки из под селедки, но ром остается ромом - твоё здоровье!";
		link.l1 = "";
		link.l1.go = "drink_RUM_3";
		break;

		case "drink_RUM_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_03.wav");
		dialog.text = "Вот бери...";
		link.l1 = "";
		link.l1.go = "drink_RUM_4";
		break;
		
		case "drink_RUM_4":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 3)
			{
				dialog.text = "Капитан, по-моему, вам следует остановиться. Не дай Бог беды пьяным натворите. У нас здесь с этим строго - не поможет даже ваш авторитет.";
				link.l1 = "Хм... Пожалуй, ты прав - я уже достаточно выпил. Спасибо за заботу!";			
				link.l1.go = "exit";
			}
			else
			{
				AddMoneyToCharacter(pchar, -5);
				if(!IsEquipCharacterByArtefact(pchar, "totem_01"))
				{
					if (CheckAttribute(pchar, "questTemp.Rum"))
					{
						pchar.questTemp.Rum = sti(pchar.questTemp.Rum) + 1;
					}
					else pchar.questTemp.Rum = 1;
				}
				else 
				{
					if(CheckAttribute(pchar, "questTemp.Rum")) DeleteAttribute(pchar, "questTemp.Rum");
				}				
				WaitDate("",0,0,0, 0, 30);
				
				dialog.text = "Пожалуйста, капитан. Всего за пять песо - пинта моего лучшего черного ямайского рома!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("Ну, за твое здоровье и процветание твоего заведения, дружище!","Ну, за тех, кто в море!","Ну, за приумножение благосостояния вашего города!"), LinkRandPhrase("Ну, за ветер добычи, за ветер удачи, чтоб зажили мы веселей и богаче!","Ну, за то, чтобы ветер всегда был попутным во всех делах!","Ну, за счастье, удачу, радости и... женщин!"));	
				link.l1.go = "drink_RUM_5";
			}
		break;

		case "drink_RUM_5":
                                     PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		dialog.text = "";
		link.l1 = "Вздрогнули?";
		link.l1.go = "drink_RUM_6";
		break;
		
		case "drink_RUM_6":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_COUGH.wav");
			DialogExit();
			LAi_Fade("", "");
			if (CheckAttribute(pchar, "questTemp.Rum"))
			{
				DeleteAttribute(pchar, "chr_ai.drunk");
				if (sti(pchar.questTemp.Rum) < 3) LAi_AlcoholSetDrunk(pchar, 51, 5600);
				else
				{
					LAi_AlcoholSetDrunk(pchar, 71, sti(pchar.questTemp.Rum)*2800);
					Pchar.GenQuest.CamShuttle = makeint(sti(pchar.questTemp.Rum)/2); // Jason
				}
			}
		break;

		case "drink_STRONGER":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_15_00.wav");
		dialog.text = "";
		link.l1 = "Я хочу чего ни будь по крепче!!!";
		link.l1.go = "drink_STRONGER_0";
		break;

		case "drink_STRONGER_0":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_14_09.wav");
	                   dialog.text = "Что тебе ещё приготовить?";
		link.l1 = "";
		link.l1.go = "drink_STRONGER_TRADE";
		break;

		case "drink_STRONGER_TRADE":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_TRADE_15_00.wav");
	                   dialog.text = "";
		link.l1 = "Я пришёл за своей порцией грога!";
		link.l1.go = "drink_Grog_1";
		link.l2 = "Дай мне рома!";
		link.l2.go = "drink_Rumm_1";
		link.l3 = "Молоток Лу!";
		link.l3.go = "drink_LOUSHAMMER_1";
		link.l4 = "Дай мне быструю селедку!";
		link.l4.go = "drink_SCHNELLERHERING_1";
		link.l5 = "Сделай мне двойной молот!";
		link.l5.go = "drink_LOUSDOUBLEHAMMER_1";
		link.l6 = "Я передумал, нет желания!";
		link.l6.go = "exit";
		break;

		case "drink_Grog_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_15_00.wav");
		dialog.text = "";
		link.l1 = "Я пришёл за своей порцией грога!";
		link.l1.go = "drink_Grog_2";
		break;

		case "drink_Grog_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_01.wav");
		dialog.text = "Да, без грога вы палец о палец ударить не можете, вот забирай...";
		link.l1 = "";
		link.l1.go = "drink_Grog_2";
		break;

		case "drink_Grog_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_02.wav");
		dialog.text = "Надеюсь пить его можно, у меня кончилась пресная вода но немного морской воды ещё никому не повредило - верно!!!";
		link.l1 = "";
		link.l1.go = "drink_Grog_3";
		break;

		case "drink_Grog_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_03.wav");
		dialog.text = "Ты можешь получить столько грога - сколько захочешь.";
		link.l1 = "";
		link.l1.go = "drink_Grog_4";
		break;

		case "drink_Grog_4":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_GROG_14_04.wav");
		dialog.text = "Продаю я грог дёшево но не бесплатно, раздобудь немного золото приятель.";
		link.l1 = "";
		link.l1.go = "drink_Grog_5";
		break;

		case "drink_Grog_5":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_13.wav");
		dialog.text = "";
		link.l1 = "Сколько ты хочешь...";
		link.l1.go = "drink_Grog_6";
		break;

		case "drink_Grog_6":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_100.wav");
		dialog.text = "1оо золотых монет.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 100)
			{
				link.l1 = "Вот твоё золото...";
				link.l1.go = "drink_Grog_7";
			}
			else
			{
				link.l1 = "У меня не достаточно золота...";
				link.l1.go = "exit_gold_Grog";
			}
		break;

		case "exit_gold_Grog":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_3.wav");
		dialog.text = "";
		link.l1 = "У меня не достаточно золота...";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_100;
		break;

		case "drink_Grog_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "drink_Grog_8";
		break;

		case "drink_Grog_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 100);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_Grog_9";
		break;

		                   case "drink_Grog_9":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Grog", 3);
		                   Log_Info("Вы получили 3 бутылочки грога");
		                   PlaySound("interface\important_item.wav");
		                   break;



		case "drink_Rumm_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_15_00.wav");
		dialog.text = "";
		link.l1 = "Дай мне рома!";
		link.l1.go = "drink_Rumm_2";
		break;

		case "drink_Rumm_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_01.wav");
		dialog.text = "A, ром для моряка всё ровно, что молоко матери - вот бери...";
		link.l1 = "";
		link.l1.go = "drink_Rumm_3";
		break;

		case "drink_Rumm_3":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_02.wav");
		dialog.text = "У рома может быть небольшой привкус рыбы, у меня остались только бочки из под селедки, но ром остается ромом - твоё здоровье!";
		link.l1 = "";
		link.l1.go = "drink_Rumm_4";
		break;

		case "drink_Rumm_4":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_03.wav");
		dialog.text = "Вот бери...";
		link.l1 = "";
		link.l1.go = "drink_Rumm_5";
		break;

		case "drink_Rumm_5":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "Сколько...";
		link.l1.go = "drink_Rumm_6";
		break;

		case "drink_Rumm_6":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_150.wav");
		dialog.text = "15о золотых монет.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 150)
			{
				link.l1 = "Вот твоё золото...";
				link.l1.go = "drink_Rumm_7";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_Rumm";
			}
		break;

		case "exit_gold_Rumm":
 	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_04.wav");
		dialog.text = "У тебя недостаточно золота приятель, как насчёт грога?";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_150;
		break;

		case "drink_Rumm_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "drink_Rumm_8";
		break;

		case "drink_Rumm_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 150);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_Rumm_9";
		break;

		                   case "drink_Rumm_9":
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Rumm", 3);
		                   Log_Info("Вы получили 3 бутылочки рома");
		                   PlaySound("interface\important_item.wav");
		                   break;


		case "drink_LOUSHAMMER_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_15_00.wav");
		dialog.text = "";
		link.l1 = "Я хочу молоток Лу!";
		link.l1.go = "drink_LOUSHAMMER_2";
		break;

		case "drink_LOUSHAMMER_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_TRADE_14_01.wav");
		dialog.text = "Я могу продать тебе всё нужно пирату для жизни!!!";
		link.l1 = "";
		link.l1.go = "drink_LOUSHAMMER_3";
		break;

		case "drink_LOUSHAMMER_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "Сколько...";
		link.l1.go = "drink_LOUSHAMMER_4";
		break;

		case "drink_LOUSHAMMER_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_250.wav");
		dialog.text = "25о золотых монет.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 250)
			{
				link.l1 = "Вот твоё золото...";
				link.l1.go = "drink_LOUSHAMMER_7";
			}
			else
			{
				link.l1 = "У меня нет таких денег... Вернусь, когда раздобуду.";
				link.l1.go = "exit_gold_LOUSHAMMER";
			}
		break;

		case "exit_gold_LOUSHAMMER":
 	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_RUM_14_04.wav");
		dialog.text = "У тебя недостаточно золота приятель, как насчёт грога?";
		link.l1 = "";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_250;
		break;

		case "drink_LOUSHAMMER_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "drink_LOUSHAMMER_8";
		break;

		case "drink_LOUSHAMMER_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 250);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_LOUSHAMMER_9";
		break;

		                   case "drink_LOUSHAMMER_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_14_01.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Loushammer", 3);
		                   Log_Info("Вы получили 3 бутылочки молотка Лу");
		                   PlaySound("interface\important_item.wav");
		                   break;


		case "drink_SCHNELLERHERING_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_SCHNELLERHERING_15_00.wav");
		dialog.text = "";
		link.l1 = "Дай мне быструю селедку!";
		link.l1.go = "drink_SCHNELLERHERING_2";
		break;

		case "drink_SCHNELLERHERING_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_SCHNELLERHERING_14_01.wav");
		dialog.text = "Злой напиток, но эфективный!!!";
		link.l1 = "";
		link.l1.go = "drink_SCHNELLERHERING_3";
		break;

		case "drink_SCHNELLERHERING_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "Сколько...";
		link.l1.go = "drink_SCHNELLERHERING_4";
		break;

		case "drink_SCHNELLERHERING_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_500.wav");
		dialog.text = "500 золотых монет.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 500)
			{
				link.l1 = "Вот твоё золото...";
				link.l1.go = "drink_SCHNELLERHERING_7";
			}
			else
			{
				link.l1 = "Чёрт побери, как дорого - то!";
				link.l1.go = "exit_gold_SCHNELLERHERING";
			}
		break;

		case "exit_gold_SCHNELLERHERING":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
		dialog.text = "";
		link.l1 = "Чёрт побери, как дорого - то!";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_500;
		break;

		case "drink_SCHNELLERHERING_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "drink_SCHNELLERHERING_8";
		break;

		case "drink_SCHNELLERHERING_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 500);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_SCHNELLERHERING_9";
		break;

		                   case "drink_SCHNELLERHERING_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSHAMMER_14_01.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Schnellerhering", 3);
		                   Log_Info("Вы получили 3 бутылочки быстрой селедки");
		                   PlaySound("interface\important_item.wav");
		                   break;



		case "drink_LOUSDOUBLEHAMMER_1":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_15_00.wav");
		dialog.text = "";
		link.l1 = "Сделай мне двойной молот!";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_2";
		break;

		case "drink_LOUSDOUBLEHAMMER_2":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_14_01.wav");
		dialog.text = "Не делай глупости сынок? Будем надеятся, что это берешь не для себя?";
		link.l1 = "";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_3";
		break;

		case "drink_LOUSDOUBLEHAMMER_3":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_2.wav");
		dialog.text = "";
		link.l1 = "Сколько...";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_4";
		break;

		case "drink_LOUSDOUBLEHAMMER_4":
	                  PlaySound("VOICE\Russian\gotica\SVM_1\SVM_7_GOLD_700.wav");
		dialog.text = "700 золотых монет.";

			if (GetCharacterItem(pchar, "gold_dublon") >= 700)
			{
				link.l1 = "Вот твоё золото...";
				link.l1.go = "drink_LOUSDOUBLEHAMMER_7";
			}
			else
			{
				link.l1 = "Чёрт побери, как дорого - то!";
				link.l1.go = "exit_gold_LOUSDOUBLEHAMMER";
			}
		break;

		case "exit_gold_LOUSDOUBLEHAMMER":
	                  PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
		dialog.text = "";
		link.l1 = "Чёрт побери, как дорого - то!";
		link.l1.go = "exit";
		npchar.quest.SAMUEL_700;
		break;

		case "drink_LOUSDOUBLEHAMMER_7":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
		dialog.text = "";
		link.l1 = "Вот твоё золото...";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_8";
		break;

		case "drink_LOUSDOUBLEHAMMER_8":
                                      PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		RemoveItems(PChar, "gold_dublon", 700);
		dialog.text = "";
		link.l1 = "";
		link.l1.go = "drink_LOUSDOUBLEHAMMER_9";
		break;

		                   case "drink_LOUSDOUBLEHAMMER_9":
	                  PlaySound("VOICE\Russian\gotica\SAMUEL\DIA_ADDON_SAMUEL_STRONGER_LOUSDOUBLEHAMMER_14_02.wav");
		                   DialogExit();
		                   NextDiag.CurrentNode = NextDiag.TempNode;
		                   TakeNItems(pchar, "Lousdoublehammer", 3);
		                   Log_Info("Вы получили 3 бутылочки двойного молотка Лу");
		                   PlaySound("interface\important_item.wav");
		                   break;


		
 		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


		case "crew hire":
			ok = (rColony.from_sea == "Shore31") || (Pchar.location.from_sea == rColony.from_sea);

						
            if (makeint(environment.time) > 22.0 || makeint(environment.time) < 7.0)
			{
				Dialog.text = "Обычно у меня в таверне полно людей, желающих стать матросами, но сейчас слишком поздно, и они начнут появляться только утром. Может быть, вы хотите снять комнату, и подождать их?";
				link.l1 = "Хорошо. У тебя есть свободные комнаты?";
				link.l1.go = "room";
				link.l2 = "Меня не интересует комната на данный момент. До встречи.";
				link.l2.go = "exit";
			}
			else
			{
                if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
                {
                    Dialog.text = "А ты думаешь, к тебе кто-то пойдет, когда ты с нами во вражде? Скажи спасибо, что стражу не зову.";
					link.l1 = "Спасибо.";
					link.l1.go = "exit";
                }
                else
                {
					if (CheckAttribute(NPChar, "CrewHired.PGGId") && GetNpcQuestPastDayParam(NPChar, "CrewHired") < 3 && GetCrewQuantity(rColony) == 0)
					{
						Dialog.text = "Извините, но сейчас нет никого. Все ушли с отважным кэпом " + GetFullName(CharacterFromID(NPChar.CrewHired.PGGId)) + ".";
						link.l1 = "Эх, жаль!";
						link.l1.go = "exit_crew";
					}
					else
					{						
						if(bPartitionSet)
						{		
							if(GetPartitionAmount("CrewPayment") > 0)
							{
								if(IsEquipCharacterByArtefact(pchar, "totem_07"))
								{
									DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
									NextDiag.CurrentNode =  NextDiag.TempNode;
									DialogExit();
									LaunchHireCrew();							
								}
								else
								{
									dialog.text = "Капитан, поговаривают, что вы скуповаты. У меня нет желающих пойти в вашу команду.";
									link.l1 = "Понятно...";
									link.l1.go = "exit";
								}
							}
							else
							{
								DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
								NextDiag.CurrentNode =  NextDiag.TempNode;
								DialogExit();
								LaunchHireCrew();	
							}
						}	
						else
						{
							DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
							NextDiag.CurrentNode =  NextDiag.TempNode;
							DialogExit();
							LaunchHireCrew();							
						}						
					}
				}
			}
		break;

		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;



		// ============== Грабеж среди бела дня, попытка залезть в сундуки =========================
		case "Man_FackYou"://реакция на попытку залезть в сундук
			dialog.text = LinkRandPhrase("Да ты "+ GetSexPhrase("вор, милейший! Стража, держи его","воровка! Стража, держи ее") +"!!!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой! Держи "+ GetSexPhrase("вора","воровку") +"!!!", "Стража! Грабят!!! Держи "+ GetSexPhrase("вора","воровку") +"!!!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "exit_setOwner":
			LAi_SetOwnerTypeNoGroup(npchar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}
