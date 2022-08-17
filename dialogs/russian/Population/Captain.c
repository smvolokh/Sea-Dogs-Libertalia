//Jason общий диалог праздношатающихся по улицам капитанов
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			//первая встреча
			if (npchar.quest.meeting == "0")
			{
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");	
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)//проверка межнациональных отношений
				{
					dialog.text = "Хм. Ты ходишь под флагом "+NationNameGenitive(sti(pchar.nation))+", приятель. У меня нет никакого желания с тобой общаться - потом проблем не оберешься... Ступай своей дорогой!";
					link.l1 = "Ну надо же, сам - капитан, а все туда же...";
					link.l1.go = "exit";
					break;
				}
				if (CheckAttribute(npchar, "quest.march") && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && GetCompanionQuantity(pchar) < 8)//боевые генераторные квесты 2015
				{
					dialog.text = "Ха! Вы очень вовремя, капитан... У меня к вам деловое предложение. У вас есть пара свободных часов?";
					link.l1 = "Нет. Я тороплюсь, коллега. Как-нибудь в другой раз.";
					link.l1.go = "exit_quest";
					link.l2 = "Есть. Я готов вас выслушать. Куда отправимся? В таверну?";
					link.l2.go = "march";
					break;
				}
				dialog.text = "Ха, приветствую вас, коллега! Приятно видеть преуспевающего капитана!";
				link.l1 = "Рад встрече, уважаемый! Мое имя - "+GetFullName(pchar)+". Не найдется минутки поболтать?";
				link.l1.go = "question";
				npchar.quest.meeting = "1";
			}
			else
			{
				//повторные обращения
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
					dialog.text = "Я что, непонятно выражаюсь? Я не желаю, чтобы меня заподозрили в связи с "+NationNameAblative(sti(pchar.nation))+"! Проваливай, не то точно страже доложу!";
					link.l1 = "Ладно-ладно, не кипятись. Ухожу.";
					link.l1.go = "exit";
				}
				else
				{
					dialog.text = "Что вам надо?";
					link.l1 = "Ничего.";
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "First time";
		break;

		case "question":
			dialog.text = NPCStringReactionRepeat(""+GetFullName(npchar)+" к вашим услугам, милейший! Что вы хотели узнать?", 
				"Рад поболтать, капитан!", 
				"Ну, пожалуй, у меня есть еще время...",
                "К сожалению, мне пора идти. Всего доброго!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Может, расскажете что интересное?", 
				"Может, расскажете что интересное?",
                "Может, расскажете что интересное?", 
				"Да, конечно. Удачи вам!", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("rumours_landcaptain", "rumours_landcaptain", "rumours_landcaptain", "exit", npchar, Dialog.CurrentNode);
		break;
		
		//квестовая часть
			case "march":
				dialog.text = "Нет, капитан, на улице и в таверне много лишних ушей, а они нам ни к чему, уверяю вас. Дело пойдет о том, чтобы кое-кого хорошенько пощипать, так что... давайте лучше побеседуем у меня на корабле.";
				link.l1 = "Хорошо... Что у вас за судно и как называется?";
				link.l1.go = "march_1";
				link.l2 = "Что-то мне это кажется подозрительным... Нет, пожалуй, я откажусь от вашего приглашения. Прощайте, сударь!";
				link.l2.go = "exit_quest";
			break;
			
			case "march_1":
				//генерируем и запоминаем параметры в пчар, т.к. через нпчар не хочет нормально работать :(
				pchar.GenQuest.MarchCap.Startisland = Islands[GetCharacterCurrentIsland(PChar)].id;
				pchar.GenQuest.MarchCap.Parts = GetCompanionQuantity(pchar)+1;
				pchar.GenQuest.MarchCap.shiptype = SelectCaptainShipType();
				pchar.GenQuest.MarchCap.shipname = GenerateRandomNameToShip(sti(npchar.nation));
				pchar.GenQuest.MarchCap.nation = sti(npchar.Nation);
				pchar.GenQuest.MarchCap.model = npchar.model;
				pchar.GenQuest.MarchCap.rank = sti(npchar.rank);
				pchar.GenQuest.MarchCap.name = npchar.name;
				pchar.GenQuest.MarchCap.lastname = npchar.lastname;
				pchar.GenQuest.MarchCap.BaseNation = npchar.nation;
				pchar.GenQuest.MarchCap.Nation = drand(HOLLAND);
				pchar.GenQuest.MarchCap.basecity = npchar.city;
				dialog.text = "Мой корабль - "+GetStrSmallRegister(XI_ConvertString(GetBaseShipParamFromType(sti(pchar.GenQuest.MarchCap.shiptype), "Name")))+" '"+pchar.GenQuest.MarchCap.shipname+"', стоит на рейде. Не затягивайте, капитан: через шесть часов я планирую поднимать якоря!";
				link.l1 = "Понятно. Постараюсь прибыть к вам вовремя. До встречи!";
				link.l1.go = "march_2";
			break;
			
			case "march_2":
			DialogExit();
				LAi_SetActorType(npchar);
				LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "none", "", "", "", 30.0);
				npchar.lifeday = 0;
				pchar.quest.MarchCapOver.win_condition.l1 = "Timer";
				pchar.quest.MarchCapOver.win_condition.l1.date.hour  = sti(GetTime() + 6);
				pchar.quest.MarchCapOver.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
				pchar.quest.MarchCapOver.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
				pchar.quest.MarchCapOver.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
				pchar.quest.MarchCapOver.function = "MarchCap_Over";
				pchar.quest.MarchCap_Create.win_condition.l1 = "location";
				pchar.quest.MarchCap_Create.win_condition.l1.location = pchar.GenQuest.MarchCap.Startisland;
				pchar.quest.MarchCap_Create.function = "MarchCap_Create";
				log_Testinfo(pchar.GenQuest.MarchCap.Startisland);
			break;
			
		//замечание по обнаженному оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			link.l1.go = "exit";
		break;
		
		case "exit_quest":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}

int SelectCaptainShipType()
{
	int iType;
	if (sti(pchar.rank) >=  1) iType = SHIP_BOTIK;
	if (sti(pchar.rank) >=  2) iType = SHIP_GUNBOAT;
	if (sti(pchar.rank) >=  3) iType = SHIP_WAR_TARTANE;
	if (sti(pchar.rank) >=  4) iType = SHIP_CHALOUPE;
	if (sti(pchar.rank) >=  5) iType = SHIP_LIGHTSLOOP;
	if (sti(pchar.rank) >=  6) iType = SHIP_CAREERLUGGER;
	if (sti(pchar.rank) >=  7) iType = SHIP_CUTTER;
	if (sti(pchar.rank) >=  8) iType = SHIP_GAFELSLOOP;
	if (sti(pchar.rank) >=  9) iType = SHIP_KETCH;
	if (sti(pchar.rank) >=  10) iType = SHIP_LUGGER;
	if (sti(pchar.rank) >=  11) iType = SHIP_GALIOT;
	if (sti(pchar.rank) >=  12) iType = SHIP_SLOOP;
	if (sti(pchar.rank) >=  13) iType = SHIP_SNAUW;
	if (sti(pchar.rank) >=  14) iType = SHIP_WARSLOOP;
	if (sti(pchar.rank) >=  15) iType = SHIP_FASTSCHOONER;
	if (sti(pchar.rank) >=  16) iType = SHIP_LIGHTSCHOONER;
	if (sti(pchar.rank) >=  17) iType = SHIP_FASTBRIG;
	if (sti(pchar.rank) >=  18) iType = SHIP_PATROLSCHOONER;
	if (sti(pchar.rank) >=  19) iType = SHIP_GAFELSCHOONER;
	if (sti(pchar.rank) >=  20) iType = SHIP_SCHOONER_W;
	if (sti(pchar.rank) >=  21) iType = SHIP_BRIG;
	if (sti(pchar.rank) >=  22) iType = SHIP_ARMEDBRIG;
	if (sti(pchar.rank) >=  23) iType = SHIP_BATTLEBRIG;
	if (sti(pchar.rank) >=  24) iType = SHIP_LIGHTCORVETTE;
	if (sti(pchar.rank) >=  25) iType = SHIP_BRIGANTINE;
	if (sti(pchar.rank) >=  26) iType = SHIP_POLACCA;
	if (sti(pchar.rank) >=  27) iType = SHIP_WARSCHOONER;
	if (sti(pchar.rank) >=  28) iType = SHIP_BATTLEBRIGANTINE;
	if (sti(pchar.rank) >=  29) iType = SHIP_ARMEDBRIGANTINE;
	if (sti(pchar.rank) >=  30) iType = SHIP_WARBRIG;
	if (sti(pchar.rank) >=  31) iType = SHIP_SMALLGALEON;
	if (sti(pchar.rank) >=  32) iType = SHIP_CORVETTE;
	if (sti(pchar.rank) >=  33) iType = SHIP_GALEON_L;
	if (sti(pchar.rank) >=  34) iType = SHIP_WARXEBEC;
	if (sti(pchar.rank) >=  35) iType = SHIP_FASTCORVETTE;
	if (sti(pchar.rank) >=  36) iType = SHIP_XEBEKVML;
	if (sti(pchar.rank) >=  37) iType = SHIP_POLACRE;
	if (sti(pchar.rank) >=  38) iType = SHIP_BATTLEXEBEC;
	if (sti(pchar.rank) >=  39) iType = SHIP_CORSAIRCORVETTE;
	if (sti(pchar.rank) >=  40) iType = SHIP_WARCORVETTE;
	if (sti(pchar.rank) >=  41) iType = SHIP_BATTLECORVETTE;
	if (sti(pchar.rank) >=  42) iType = SHIP_HEAVYCORVETTE;
	if (sti(pchar.rank) >=  43) iType = SHIP_LIGHTFRIGATE;
	if (sti(pchar.rank) >=  44) iType = SHIP_ARMEDXEBEC;
	if (sti(pchar.rank) >=  45) iType = SHIP_RAIDER;
	if (sti(pchar.rank) >=  46) iType = SHIP_CORSAIRFRIGATE;
	if (sti(pchar.rank) >=  47) iType = SHIP_ARMEDCORVETTE;
	if (sti(pchar.rank) >=  48) iType = SHIP_PRIVATEER;
	if (sti(pchar.rank) >=  49) iType = SHIP_WARGALEON;
	if (sti(pchar.rank) >=  50) iType = SHIP_FRIGATE;
	if (sti(pchar.rank) >=  51) iType = SHIP_FRIGATE_H;
	if (sti(pchar.rank) >=  52) iType = SHIP_WARFRIGATE;
	if (sti(pchar.rank) >=  53) iType = SHIP_BATTLEFRIGATE;
	if (sti(pchar.rank) >=  54) iType = SHIP_WARSHIP;
	if (sti(pchar.rank) >=  55) iType = SHIP_BATTLESHIP;
	if (sti(pchar.rank) >=  56) iType = SHIP_LINEFRIGATE;
	if (sti(pchar.rank) >=  57) iType = SHIP_LINESHIP;
	if (sti(pchar.rank) >=  58) iType = SHIP_WARLINESHIP;
	if (sti(pchar.rank) >=  59) iType = SHIP_HEAVYLINESHIP;
	if (sti(pchar.rank) >=  60) iType = SHIP_BATTLELINESHIP;
	return iType;
}