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
				dialog.text = TimeGreeting() + "! Добро пожаловать, " + GetAddress_Form(NPChar) + " в таверну нашей маленькой деревушки Сент-Луи. Еда, выпивка и... девочки - все по умеренным ценам, они такие красивые! Меня зовут "+GetFullName(npchar)+" и я всегда к вашим услугам.";
				Link.l1 = "Посмотрим... Я " + GetFullName(pchar) + ". Рад с вами познакомиться, "+npchar.name+".";
				Link.l1.go = "meeting";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "А-а, это же мой старый знакомый, капитан "+GetFullName(pchar)+"! Рада вас видеть! Пришёл за порцией еды?";
				link.l1 = "Я ищу работу?";
				link.l1.go = "THEKLA_ARBEIT";

				link.l2 = "Я бы хотел отдохнуть. У тебя есть свободная комната?";
				link.l2.go = "room";
				link.l3 = LinkRandPhrase("Расскажи мне последние новости?","Что новенького в этих краях?","Как течет жизнь на суше?");
				link.l3.go = "rumours_tavern";
			                     Link.l4 = "Мне нужна команда, " + NPChar.name + ".";
			                     Link.l4.go = "crew hire";
			}
			if(CheckAttribute(pchar, "questTemp.BlueBird") && pchar.questTemp.BlueBird == "SantLous_toTavern" && !CheckAttribute(npchar, "quest.SantLous_toTavern"))
			{
				link.l5 = "Тёкла, не знаешь, когда у местного торговца кораблик в море выходить собирается?";
				link.l5.go = "BlueBird_ret";
			}
				link.l6 = "Нет, ничего не надо, "+npchar.name+". Я просто зашел поздороваться с тобой.";
				link.l6.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_15_00.wav");
		dialog.text = "";
		link.l1 = "Как у тебя здесь вкусно пахнет?";
		link.l1.go = "meeting_1";
		break;

		case "meeting_1":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_17_01.wav");
		dialog.text = "Не подлизывайся, знаю я таких как ты - как облупленных - вон их сколько вокруг бродит?";
		link.l1 = "";
		link.l1.go = "meeting_2";
		break;

		case "meeting_2":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_LECKER_17_02.wav");
			dialog.text = "Сначала вы пытаетесь подхалимничать а затем когда от вас что - то нужно, то ни кого не найдёшь?";
			link.l1 = "Я здесь впервые, и хотел бы немного больше узнать об этом поселении.";
			link.l1.go = "info";
		break;
		
		case "info":
			dialog.text = "А о чем тут узнавать-то? У нас изо дня в день одно и то же: скука, палящее солнце и пыль. Население сплошь состоит из солдат которые постоянно находятся на ферме Онара редко кто сюда заглядывает. Также у нас всегда можно найти пару-тройку искателей приключений и прочих авантюристов и проходимцев, которых сюда привлекают золотые копи\nЗаходят сюда и джентльмены, капитаны кораблей, вроде вас: продать рабов за золотые слитки или купить драгоценные металлы\nОднако самое лучшее место в деревне - это моя таверна. Только здесь можно отдохнуть душой и телом от этого знойного ада!";
			link.l1 = "А кто тут всем заправляет!";			
			link.l1.go = "info_1";
		break;

		case "info_1":
			dialog.text = "Сначала был Онар, позже он назначил наемников во главе Генерала Ли!";
			link.l1 = "Генерала Ли!";			
			link.l1.go = "info_2";
		break;

		case "info_2":
			dialog.text = "Да, его и его парней. А ты, что хочешь сказать, что знаешь его!";
			link.l1 = "Всё может быть, а где он сейчас!";			
			link.l1.go = "info_3";
		break;

		case "info_3":
			dialog.text = "Откуда мне знать! Он же генерал...";
			link.l1 = "Ясно. А ты бы не могла мне дать поесть!";			
			link.l1.go = "info_4";
		break;

		case "info_4":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_15_00.wav");
			dialog.text = "";
			link.l1 = "Я голоден!";
			link.l1.go = "info_5";
		break;

		case "info_5":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_01.wav");
			dialog.text = "Я не кормлю бродяг, я кормлю только тех кто работает!";
			link.l1 = "...";
			link.l1.go = "info_6";
		break;

		case "info_6":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_02.wav");
			dialog.text = "И этот сброд наёмников - конечно.";
			link.l1 = "...";
			link.l1.go = "info_7";
		break;

		case "info_7":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_03.wav");
			dialog.text = "Вот твоя еда.";
			link.l1 = "...";
			link.l1.go = "info_8_1";
			if (AddSPECIALValue(pchar, SPECIAL_C, 0) == SPECIAL_MAX)
			{
			    AddSPECIALValue(pchar, SPECIAL_C, 1);
			}
		break;

		case "info_8_1":
			PlaySound("interface\important_item.wav");
			link.l1.go = "info_8_2";
		break;

		case "info_8_2":
			PlaySound("Ambient\Tavern\glotok_001.wav");
			dialog.text = "...";
			link.l1 = "Как вкусно!";
			link.l1.go = "exit";
			AddDialogExitQuest("Gothic_PlusSkill_Charisma");
		break;

		case "info_8":
			dialog.text = "Опять ты, что ты делаешь на моей кухне?";
			link.l1 = "...";
			link.l1.go = "info_8_0";
		break;

		case "info_8_0":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_00.wav");
			dialog.text = "...";
			link.l1 = "Ты мне не дашь ещё своей похлебки?";
			link.l1.go = "info_9";
		break;

		case "info_9":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_01.wav");
			dialog.text = "Она закончилась!";
			link.l1 = "...";
			link.l1.go = "info_10";
		break;

		case "info_10":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_02.wav");
			dialog.text = "...";
			link.l1 = "Не осталось даже маленькой миски?";
			link.l1.go = "info_11";
		break;

		case "info_11":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_03.wav");
			dialog.text = "Нет...";
			link.l1 = "...";
			link.l1.go = "info_12";
		break;

		case "info_12":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_15_04.wav");
			dialog.text = "...";
			link.l1 = "А могу я облизать горшок - а!";
			link.l1.go = "info_13";
		break;

		case "info_13":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_05.wav");
			dialog.text = "Прекрати!";
			link.l1 = "...";
			link.l1.go = "info_14";
		break;

		case "info_14":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_PERM_17_06.wav");
			dialog.text = "Если тебе так понравилась похлёбка, тебе придется сделать кое что, что бы получить её.";
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "THEKLA_ARBEIT":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_ARBEIT_17_01.wav");
			dialog.text = "Ты хочешь работать здесь на ферме!";
			link.l1 = "Ну ты сама говорила....";
			link.l1.go = "THEKLA_ARBEIT_1";
		break;

		case "THEKLA_ARBEIT_1":
			dialog.text = "...";
			link.l1 = "...";
			link.l1.go = "exit";

			// Посылка для Сагитты
			if(CheckAttribute(pchar, "questTemp.GothicThekla") && pchar.questTemp.GothicThekla == "UneasySagitta" && !CheckAttribute(npchar, "quest.UneasySagitta"))
			{
				link.l1 = "У тебя есть работа для меня?";
				link.l1.go = "UneasySagitta";
			}
			if(CheckAttribute(pchar, "questTemp.GothicThekla") && pchar.questTemp.GothicThekla == "SoupThekla" && !CheckAttribute(npchar, "quest.SoupThekla"))
			{
				link.l1 = "Я доставил посылку для Сагитты и проголодался - хочу есть!";
				link.l1.go = "SoupThekla";
			}
			// Мистер и Миссис Смит
			if(CheckAttribute(pchar, "questTemp.GothicSmithy") && pchar.questTemp.GothicSmithy == "SagittaAnn" && !CheckAttribute(npchar, "quest.SagittaAnn"))
			{
				link.l1 = "У тебя есть работа для меня?";
				link.l1.go = "SagittaAnn";
			}

		break;

		case "THEKLA_PERM":
			if (CheckAttribute(pchar, "questTemp.Rum") && sti(pchar.questTemp.Rum) > 3)
			{
				dialog.text = "Капитан, по-моему, вам следует остановиться. Не дай Бог беды пьяным натворите. У нас здесь с этим строго - не поможет даже ваш авторитет.";
				link.l1 = "Хм... Пожалуй, ты права - я уже достаточно выпил. Спасибо за заботу!";			
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
				
				dialog.text = "Пожалуйста, капитан. Всего за пять песо - лучшая похлёбка на карибах!";
				link.l1 = RandPhraseSimple(LinkRandPhrase("Ну, за твое здоровье и процветание твоего заведения, дорогая!","Ну, за тех, кто в море!","Ну, за приумножение благосостояния вашего города!"), LinkRandPhrase("Ну, за ветер добычи, за ветер удачи, чтоб зажили все мы веселей и богаче!","Ну, за то, чтобы ветер всегда был попутным во всех делах!","Ну, за счастье, удачу, радости и... женщин!"));	
				link.l1.go = "THEKLA_PERM_1";
			}
		break;
		
		case "THEKLA_PERM_1":
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

		
		case "room":
			if (CheckAttribute(pchar, "GenQuest.SantLousSex"))
			{
				dialog.text = "Месье, вы ведь уже оплатили и комнату, и девочку. Ступайте наверх, она вас уже заждалась.";
				link.l1 = "Хорошо.";
				link.l1.go = "exit";
				break;
			}
			dialog.text = "Есть. На какой срок вы планируете остановиться?";
			if(!isDay())
			{
				link.l1 = "До утра.";
				link.l1.go = "room_day";
			}
			else
			{
				link.l1 = "До ночи.";
				link.l1.go = "room_night";
				link.l2 = "До следующего утра.";
				link.l2.go = "room_day_next";
			}
		break;

		case "room_day":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
			dialog.text = "Это обойдется вам в десять песо. Не желаете ли девочку заодно к комнате? Всего тысячу песо за свидание.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "Нет, девочки мне не надо. Вот, возьми деньги за комнату.";
				link.l1.go = "room_day_wait_0";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "Хорошо. Давай и комнату, и девочку. Вот твои деньги.";
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "Извини, у меня нет денег.";
			link.l3.go = "room_exit_1";
		break;

		case "room_day_next":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_00.wav");
			dialog.text = "Это обойдется вам в десять песо. Не желаете ли девочку заодно к комнате? Всего тысячу песо за свидание.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "Нет, девочки мне не надо. Вот, возьми деньги за комнату.";
				link.l1.go = "room_day_wait_next";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "Хорошо. Давай и комнату, и девочку. Вот твои деньги.";
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_day";
				}
			}
			link.l3 = "Я не дам тебе ни цента.";
			link.l3.go = "room_exit_2";
		break;

		case "room_night":
 	                     PlaySound("VOICE\Russian\gotica\GG\ROOM_01.wav");
			dialog.text = "Это обойдется вам в десять песо. Не желаете ли девочку заодно к комнате? Всего тысячу песо за свидание.";
			if (makeint(pchar.money) >= 10)
			{
				link.l1 = "Нет, девочки мне не надо. Вот, возьми деньги за комнату.";
				link.l1.go = "room_night_wait_0";
			}
			if (makeint(pchar.money) >= 1010)
			{
				if (IsOfficer(characterFromId("Mary")) || !bLock || !bLock1)
				{
					link.l2 = "Хорошо. Давай и комнату, и девочку. Вот твои деньги.";
					link.l2.go = "room_girl_0";
					sTotalTemp = "wait_night";
				}
			}
			link.l3 = "Я не могу позволить себе такие расходы.";
			link.l3.go = "room_exit_3";
		break;

		case "room_exit_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_14.wav");
                                    Dialog.text = "";
		link.l1 = "Извини, у меня нет денег!"; 
		link.l1.go = "exit";  
		break;

		case "room_exit_2":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_16.wav");
                                    Dialog.text = "";
		link.l1 = "Я не дам тебе ни цента!"; 
		link.l1.go = "exit";  
		break;

		case "room_exit_3":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_19.wav");
                                    Dialog.text = "";
		link.l1 = "Я не могу позволить себе такие расходы!"; 
		link.l1.go = "exit";  
		break;

		case "room_night_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_15.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "Вот твои деньги!"; 
		link.l1.go = "room_night_wait";  
		break;

		case "room_night_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_11.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "Хорошо - вот деньги!";
		link.l1.go = "room_day_wait";
		break;

		case "room_day_wait":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -10);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_day");
		break;

		case "room_day_wait_next":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddMoneyToCharacter(pchar, -20);
			AddDialogExitQuest("sleep_in_tavern");
			TavernWaitDate("wait_day");
		break;

		case "room_girl_0":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_1.wav");
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
                                    Dialog.text = "";
		link.l1 = "Вот твоё золото!";
		link.l1.go = "room_girl";
		break;
		
		case "room_girl":
			AddMoneyToCharacter(pchar, -1010);
			dialog.text = "Поднимайтесь по лестнице наверх, месье. Девочка будет ждать вас. Приятного отдыха!";
			link.l1 = "Черт побери, как дорого - то...";
			link.l1.go = "room_girl_1";
		break;
		
		case "room_girl_1":
                                    PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELD_23.wav");
			DialogExit();
			pchar.GenQuest.CannotWait = true;
			pchar.GenQuest.SantLousSex = "true";
			LocatorReloadEnterDisable("SantLous_tavern", "reload1_back", true); //закрыть таверну
			LocatorReloadEnterDisable("SantLous_tavern", "reload2_back", false); //открыть комнату
			bDisableFastReload = true;//закрыть переход
			sld = GetCharacter(NPC_GenerateCharacter("MineFuckGirl" , "Womens_"+(rand(7)+1), "woman", "towngirl", 1, FRANCE, 1, true, "quest"));));
			sld.dialog.FileName = "Tavern\SantLous_Tavern.c";
			sld.dialog.currentnode = "MineFuckGirl";
			//sld.greeting = "";
			sld.sex = "woman";
			sld.lastname = "";
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld, "SantLous_tavern_upstairs", "goto", "goto1");
		break;
		
		case "MineFuckGirl":
                                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_15.wav");
			dialog.text = "";
			link.l1 = "Как ты зарабатываешь на жизнь?";
			link.l1.go = "MineFuckGirl_1";		
		break;

		case "MineFuckGirl_1":
                                   PlaySound("VOICE\Russian\gotica\LUCIA\DIA_ADDON_LUCIA_PALADINE_KILL_16_02.wav");
			dialog.text = "Давай прекратим говорить о таких  серьёзных вещах!";
			link.l1 = "";
			link.l1.go = "MineFuckGirl_2";		
		break;

		case "MineFuckGirl_2":
                                 PlaySound("VOICE\Russian\gotica\LUCIA\DIA_ADDON_LUCIA_PALADINE_KILL_16_03.wav");
			dialog.text = "Лучше выпьем и будем наслаждаться каждым моментом жизни данным нам Богами!";
			link.l1 = "Ну что же, малышка, давай посмотрим на что ты способна...";
			link.l1.go = "MineFuckGirl_3";		
		break;

		case "MineFuckGirl_3":
                                   PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "Хорошо. Ну что же, малышка, давай посмотрим на что ты способна...";
			link.l1.go = "MineFuckGirl_sex";		
		break;
		
		case "MineFuckGirl_sex":
			DialogExit();
			DoQuestCheckDelay("PlaySex_1", 0.1);
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

 		case "BlueBird_ret":
        	                  dialog.text = "Ха, давно пора прищучить этого торгаша, торговый флейт у него ''Золотой век'', а выходит он как раз сегодня.";
    		link.l1 = "Спасибо дорогая, мне пора.";
    		link.l1.go = "BlueBird_ret_1";
		break;

		case "BlueBird_ret_1":
		DialogExit();
		npchar.quest.SantLous_toTavern = "true";
	     DoQuestFunctionDelay("BlueBird_loginFleut", 3.0);
		AddQuestRecord("Xebeca_BlueBird", "10");
		break;

		
		case "exit_crew" :
			DeleteAttribute(NPChar, "CrewHired"); //на всяк случай.
			NextDiag.CurrentNode =  NextDiag.TempNode;
			DialogExit();
			LaunchHireCrew();
		break;

		// Посылка для Сагитты
		case "UneasySagitta":
                                       PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_1.wav");
		    dialog.text = "";
		    link.l1 = "У тебя есть работа для меня?";
                                          link.l1.go = "UneasySagitta_1";
		break;

		case "UneasySagitta_1":
		    dialog.text = "Ходят слухи, что именно капитан " + GetFullName(pchar) + " проявил"+ GetSexPhrase("","а") +" чудеса храбрости и находчивости, и сумел"+ GetSexPhrase("","а") +" доставить сюда испанскую пассию Генералу Ли - донну Анну...\nМне нужна помощь смелого капитана как ты, и ты как раз вовремя, мне необходимо передать портняжный инструмент для Сагитты которую многие боятся.";
		    link.l1 = "Боятся! И что за Сагитта, и где её искать?";
                                          link.l1.go = "UneasySagitta_2";
		break;
		
		case "UneasySagitta_2":
		    dialog.text = "Сагитта - травница, но многие думают, что она ведьма, живёт она в одной из пещер Гваделупы.";
            link.l1 = "Ведьма!!!, Что-то я как-то не очень восторге от такай услуги.";
            link.l2 = "Хм... Хорошо, я доставлю этот портняжный инструмент для Сагитты, но только ради тебя.";
            link.l1.go = "Exit1";
            link.l2.go = "UneasySagitta_3";
		break;
		
		case "Exit1":
                                                        PlaySound("VOICE\Russian\gotica\SFX\MFX_SHRINK_CAST.wav");
			dialog.text = "Ну, как знаете. Мое дело предложить...";
			link.l1 = "...";
			link.l1.go = "exit";			
			npchar.quest.UneasySagitta = "true";
		break;
		
		case "UneasySagitta_3":
		    dialog.text = "Очень хорошо, хоть от кого - то есть толк.";
                                           link.l1 = "Давай портняжный инструмент.";
                                           link.l1.go = "Exit2";
		     TakeNItems(pchar, "tailor_tool", 1);
		      Log_Info("Вы получили портняжный инструмент");
		      PlaySound("interface\important_item.wav");	
	                  break;

		case "Exit2":
		Nextdiag.CurrentNode = Nextdiag.TempNode;
		DialogExit();
                                       AddDialogExitQuestFunction("GothicSagitta_Start");
		AddQuestRecord("Delivery", "1");
		npchar.quest.UneasySagitta = "true";
		break;

		case "SoupThekla":
	                  PlaySound("VOICE\Russian\gotica\THEKLA\DIA_THEKLA_HUNGER_17_03.wav");
		dialog.text = "Вот твоя еда.";
		link.l1 = "";
		link.l1.go = "SoupThekla_1";
		if (AddSPECIALValue(pchar, SPECIAL_I, 0) == SPECIAL_MAX)
		{
		AddSPECIALValue(pchar, SPECIAL_I, 1);
		}
		break;

		case "SoupThekla_1":
		PlaySound("interface\important_item.wav");
		link.l1.go = "SoupThekla_2";
		break;

		case "SoupThekla_2":
		PlaySound("Ambient\Tavern\glotok_001.wav");
		dialog.text = "";
		link.l1 = "Как вкусно!";
		link.l1.go = "exit";
		npchar.quest.SoupThekla = "true";
		AddDialogExitQuest("Gothic_PlusSkill_Intellect");
		break;

		// Посылка для Сагитты <--

		// Мистер и Миссис Смит
		case "SagittaAnn":
                                       PlaySound("VOICE\Russian\GOTHIC\GG_WORK\WORK_1.wav");
		    dialog.text = "";
		    link.l1 = "У тебя есть работа для меня?";
                                          link.l1.go = "SagittaAnn_1";
		break;

		case "SagittaAnn_1":
		    dialog.text = "Говорят, ты взялся за выполнения необычного задания - поиски какого-то загадочного библейского трактата. И говорят, что ты его нашел... Но на ферме работы нет, ты можешь поинтересоваться у Сагитты, она спрашивала о тебе на днях? Её пещера находится на Гваделупе, если не забыл" + GetSexPhrase("", "а");;
		    link.l1 = "Хорошо я загляну к ней.";
                                          link.l1.go = "SagittaAnn_2";
		break;

		case "SagittaAnn_2":
		Nextdiag.CurrentNode = Nextdiag.TempNode;
		DialogExit();
                                    AddDialogExitQuestFunction("Gothic_SagittaAnn");		
		npchar.quest.SagittaAnn = "true";
		break;



		// ============== Грабеж среди бела дня, попытка залезть в сундуки =========================
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Грабеж среди бела дня!!! Это что же такое делается?! Ну, погоди, "+ GetSexPhrase("приятель","подруга") +"...", "Эй, ты чего это там копаешься?! Никак, вздумал"+ GetSexPhrase("","а") +" ограбить меня? Ну, тогда тебе конец...", "Постой, ты куда это полез"+ GetSexPhrase("","ла") +"? Да ты вор"+ GetSexPhrase("","овка") +", оказывается! Ну, считай, что ты приплыл"+ GetSexPhrase("","а") +", родн"+ GetSexPhrase("ой","ая") +"...");
			link.l1 = LinkRandPhrase("Дьявол!!", "Каррамба!!", "А-ать, черт!");
			link.l1.go = "PL_Q3_fight";
		break;
		
		case "fight":
            Pchar.quest.ArestInResidenceEnd.win_condition.l1          = "ExitFromLocation";
		    Pchar.quest.ArestInResidenceEnd.win_condition.l1.location = Pchar.location;
		    Pchar.quest.ArestInResidenceEnd.win_condition             = "ArestInResidenceEnd";
		    Pchar.quest.ArestInResidenceEnd.ResidenceLocation = Pchar.location;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			LAi_LockFightMode(Pchar, true); // ножками путь убегает
		    LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		    LAi_group_Attack(NPChar, Pchar); // не работает на бессмертного мера :(
			i = GetCharIDXByParam("CityType", "location", Pchar.location); // фантом солдат
			if (i != -1)
			{
			    LAi_group_Attack(&Characters[i], Pchar);
			}
		break;
	}
}
