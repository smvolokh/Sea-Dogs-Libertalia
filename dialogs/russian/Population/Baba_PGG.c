//Пират Либерталии 
//Сей диалог предназначен для славных вольных капитанов, которые просиживают свои штанишки в тавернах и с которыми можно всяческими способами взамодействовать. 
#include "DIALOGS\russian\Rumours\Common_rumours.c"
#include "DIALOGS\russian\Common_Duel.c"

#define MAX_PGG_STORIES 		9
#define MAX_PGG_QUEST_STORIES 	3
#define MAX_PGG_MEET_REP 		5

string PGG_Stories[MAX_PGG_STORIES] = {
"...И вот мы уже подходим к тому острову которого нет на картах ГВИК. Меня переполняли нетерпение и страх. Как вдруг я ощутила поток ледяной воды в лицо и слышу голос трактирщика: опять спишь на ступеньках! Вставай, пьяная свинья!\n",
"Знавала я пирата, звали его Роджер. Как-то раз напился он рому и всю ночь орал во всё горло флагу: 'Самозванец! Роджер может быть только один!'. Мы с ребятками дружно решили, что он прав и наутро выбросили парня за борт.\n",
"... однажды в море, будучи немного пьяным, он предложил: 'Давайте здесь сейчас устроим себе сами ад и посмотрим, кто дольше выдержит'.\n",
"... А вот презабавная история, которая случилась с моим давним приятелем в Портобэлло. Идём как-то мы вечерними улицами от порта к горячему кварталу. Я на фоке, а спутник мой уже и грот-марсель взял на риф, тут навстречу нам пара бригантин. Что регели, что транец – всё при них. И как только мы поравнялись бортами, мой приятель как даст из двух бортов! Ха-ха-ха-ха...\n",
"... Нет, джентльмены, это всё анекдоты... А вот история, которой я собственнолично была не только свидетельницей, а в некотором роде и участницей. Направляюсь я как-то в таверну Капстервиля прямёхонько из дока, где наблюдала кренгование своего старого 'Кондора', а навстречу мне из двери таверны вываливается сам капитан Шарп! Штормит его нещадно, бизань уже сорвало напрочь, и только блиндом он пытается маневрировать по ступеням. Не успела я предложить ему услуги лоцмана, как перила под ним–хрясть!!! Хо-хо-хо-хо...\n",
"... Ничего не могу сказать о 'Летучем Голландце'. Ни мне, ни кому-либо из моих матросов видеть его, слава Богу, не доводилось... Но был случай не менее загадочный. К востоку от Исла Тесоро встретилась нам бригантина под всеми парусами, но шла она странным курсом – эдакими зигзагами. Я ничего такого не замышляла, но шлюпку выслала. Каково же было наше удивление, когда на борту не оказалось ни единой души!.. А в трюме – 1700 баррелей отличного вина!.. Вот что я называю удачей! И без единого выстрела! Ха-ха-ха..\n",
"... Всё же я склонна думать, джентльмены, что все эти россказни о 'Летучем Голландце' не более чем досужие выдумки трусливых торгашей, которые в каждом парусе на горизонте готовы видеть кровожадного капера с пьяным чудовищем на капитанском мостике, а в каждом встреченном люггере – предвестника несчастий...\n",
"... Может быть кто помнит тот случай южнее Ки-Уэста, когда меня бимсом контузило?.. Хотя видимых повреждений и не было, – провалялялась я месяца два. И тогдашний мой благоверный уговорил меня исповедаться. Мол, с Божьей помощью дело на лад пойдёт... Ну, пошла я, а священник и спрашивает: 'А много ли ты людей погубила, дочь моя? А много ли кораблей потопила?' – 'Мно-ого', – отвечаю. А он не унимается: 'А много ли ты прелюбодействовала, дочь моя?'. Тут я и говорю: 'Падре, я же сюда не хвастаться пришла!'. Ха-ха-ха-ха...\n",
"... Ха-ха-ха!.. А вот в Сантакрузе был случай во время швартовки. С криком 'Полундра!' кидает мой матрос выбраску и попадает местному зеваке прямёхонько в лоб! Тот – брык! – и падает без чувств. Матрос испугался, не дожидаясь трапа прыгает на пирс и давай отливать бедолагу водой из ендовы. Наконец тот приходит в себя и говорит матросу: - Когда бросаешь полундру, кричать нужно 'Па-берегись!'. Ах-ха-ха ..." 
};

string PGG_QuestStories[MAX_PGG_QUEST_STORIES] = {
"...Как-то застряли мы во Флориде - пережидали штиль. Когда на корабле закончились запасы рома, угораздило нас завалиться в таверну. И будучи под рифом, я, видать, сболтнула одному из событыльников про золотишко, что припрятала на черный день. Так представьте - когда через месяц я наведалась в свой тайник, он был пуст, как голова с похмелья! Укуси меня сардина, если этот мерзавец не выболтал о моей заначке первому же проходимцу. Так что веры мужикам у меня ни на пол песо нет!..\nА вот к нашему столу пожаловал бывалый повеса. Укуси меня сардина, ха-ха-ха!..",
"...Клад мы разделили после чего она отошла от дел и поселилась на Доминике. Видела я её однажды, каждый вечер у ростовщика сидит, видать деньги делает. А глаза до сих пор горят, не прочь тряхнуть стариной, да пару торговцев взять на абордаж. Эх, мисс Джейнс... Хороша как внешне так и в бою!",
"...а он так с издёвкой ей и говорит: 'Пойдём, мол, наверх. Прежде, чем принимать в команду, надо бы проверить что ты умеешь, как офицер'. А девка эта выхватила тесак чуть не с неё размером и говорит: 'Сначала проверим, годитесь ли вы мне в капитаны!' Ха-ха-ха... Она гоняла его, как акула треску по всей таверне, и было бы это очень смешно, джентльмены, не прикончи она того бедолагу прямо посреди зала на глазах у всех. Упокой Господь его душу, кобелина... Вот баба молодец, смогла за себя постоять!\nХо, поприветствуем достойного капитана!"
}

string PGG_Meet_GoodRep[MAX_PGG_MEET_REP] = {
"Редко встретишь порядочного капитана в этих водах.",
"Благородство не в моде в наше время.",
"А вот и честный капитан, не чета вам, головорезы! Хе-хе!",
"Джентльмены, у нашего столика достойный капитан, который бывал ещё не в таких переделках. О чём поведаете, уважаемый?",
"А вот и ещё один славный корсар, который не привык искать лёгких путей...", 
};

string PGG_Meet_BadRep[MAX_PGG_MEET_REP] = {
"А вот и еще один пират!",
"Джентльмены, у нашего стола джентльмен удачи, как я полагаю.",
"Запахло порохом и кровью, флибустьер справа по борту!",
"О-о джентльмены, а вот и бывалый корсар, у которого наверняка есть что порассказать в дружной компании за кружкой рома...",
"Чувствую, запахло порохом... Джентльмены, к нам присоединился ещё один славный корсар, которому уж наверняка будет что порассказать на исповеди. Ха-ха-ха!",
};

void ProcessDialogEvent()
{
	ref NPChar, sld;
	string sTmp, sLoc;
	aref Link, NextDiag;

	ref    	rItm, rItem;
	string 	attr, attrLoc, sGun, sBullet, attrL, sAttr;
	int    	iTemp, iTax, iFortValue, i;
	aref 	rType;

	int iHour;
	int iRnd = -1;
	int iAns;
	string sLocation;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);

	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // индекс в конце
 	    Dialog.CurrentNode = "SetGunBullets2";
	}
    if (CheckNPCQuestDate(npchar, "Card_date"))
	{
		SetNPCQuestDate(npchar, "Card_date");
		npchar.money = 5000 + (rand(10)+1) * makeint(100 * 	sti(PChar.rank) * (10.0 / MOD_SKILL_ENEMY_RATE));
	}
	switch(Dialog.CurrentNode)
	{

case "First time":
PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(15) + ".wav");
//--> Jason если идет первая часть квеста
			if (CheckAttribute(pchar, "questTemp.Sharlie.Lock"))
            {
				dialog.text = "Чем могу быть полезна, сударь?";
				link.l1 = "Ничем, к сожалению. Просто хотел поприветствовать Вас! Удачи!";
				link.l1.go = "exit";
				break;
			}
			//<-- идет первая часть квеста
//		Dialog.Text = "Добрый день, меня зовут " + GetFullName(NPChar) + ", а вас?";
		if(rand(10) == 3)
		{
			iRnd = rand(MAX_PGG_QUEST_STORIES - 1);
			Dialog.Text = PGG_QuestStories[iRnd];
		}
		else
		{
			iRnd = rand(MAX_PGG_STORIES - 1);
			iAns = rand(MAX_PGG_MEET_REP - 1);
			Dialog.Text = PGG_Stories[iRnd] + PCharRepPhrase(PGG_Meet_GoodRep[iAns], PGG_Meet_BadRep[iAns]);
		}		 
//		link.l1 = "Не имею чести быть вам представленн"+ GetSexPhrase("ым","ой") +". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Мое имя " + GetFullName(pchar) + "."));
link.l1.go = "dialog_pgg";
		break;

//  Общавочка -->

		case "dialog_pgg":
			//первая встреча
			if (npchar.quest.meeting == "0")
			{
	                                PlaySound("VOICE\Russian\GOTHIC\GG_HALLO_M\GG_HALLO_M_" + rand(18) + ".wav");	
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)//проверка межнациональных отношений
				{
sld = GetRealShip(sti(NPChar.Ship.Type));
Dialog.Text = "Приветствую Вас, коллега! Приятно, знаете ли, видеть преуспевающего и достойного капитана! Позвольте представиться - " + GetFullName(NPChar) + ". Я капитан " + xiStr(sld.BaseName + "PGG") + " '" + NPChar.Ship.Name + "', под флагом " + NationNameGenitive(sti(NPChar.nation)) + ". Чем могу быть полезна?";
link.l1 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". У меня к Вам деловое предложение!";
					link.l1.go = "march";
					link.l2 = "О, приветствую Вас! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я очень рад нашей встрече. Слыхал я, что Вы не только невороятная женщина, но и опытный моряк, не желаете пойти офицером ко мне на корабль? В деньгах не обижу.";
			link.l2.go = "officer";
		link.l3 = "Приветствую, коллега! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я много слышал о Вас... Судя по слухам, Вы настоящая гроза всего архипелага! Думаю, что если бы мы объединили наши усилия, то вместе мы смогли бы гораздо больше... Что скажите, сударыня?";
					link.l3.go = "companion";
link.l4 = "Здравствуйте, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете что-нибудь купить или продать?";
link.l4.go = "Trade_1";
			link.l5 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете ли скоротать время за игрой?";
			link.l5.go = "Play_Game";
		link.l6 = "Опа! Какая встреча! Ну, здравствуй, родная. Давненько мы с тобой не виделись. Мое имя - "+GetFullName(pchar)+", помнишь меня, каналья? ";
					link.l6.go = "duel";
		link.l7 = "Привет, подруга! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я просто решил поздороваться. Бывай!";
					link.l7.go = "exit";
					npchar.quest.meeting = "1";
				}
				if (CheckAttribute(npchar, "quest.march") && !CheckAttribute(pchar, "questTemp.Sharlie.Lock") && GetCompanionQuantity(pchar) < 8)//боевые генераторные квесты 2015
				{
sld = GetRealShip(sti(NPChar.Ship.Type));
Dialog.Text = "Приветствую Вас, коллега! Приятно, знаете ли, видеть преуспевающего и достойного капитана! Позвольте представиться - " + GetFullName(NPChar) + ". Я капитан " + xiStr(sld.BaseName + "PGG") + " '" + NPChar.Ship.Name + "', под флагом " + NationNameGenitive(sti(NPChar.nation)) + ". Чем могу быть полезна?";
link.l1 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". У меня к Вам деловое предложение!";
					link.l1.go = "march";
					link.l2 = "О, приветствую Вас! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я очень рад нашей встрече. Слыхал я, что Вы не только невороятная женщина, но и опытный моряк, не желаете пойти офицером ко мне на корабль? В деньгах не обижу.";
			link.l2.go = "officer";
		link.l3 = "Приветствую, коллега! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я много слышал о Вас... Судя по слухам, Вы настоящая гроза всего архипелага! Думаю, что если бы мы объединили наши усилия, то вместе мы смогли бы гораздо больше... Что скажите, сударыня?";
					link.l3.go = "companion";
link.l4 = "Здравствуйте, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете что-нибудь купить или продать?";
link.l4.go = "Trade_1";
			link.l5 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете ли скоротать время за игрой?";
			link.l5.go = "Play_Game";
		link.l6 = "Опа! Какая встреча! Ну, здравствуй, родная. Давненько мы с тобой не виделись. Мое имя - "+GetFullName(pchar)+", помнишь меня, каналья? ";
					link.l6.go = "duel";
		link.l7 = "Привет, подруга! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я просто решил поздороваться. Бывай!";
					link.l7.go = "exit";
					npchar.quest.meeting = "1";

				}
sld = GetRealShip(sti(NPChar.Ship.Type));
Dialog.Text = "Приветствую Вас, коллега! Приятно, знаете ли, видеть преуспевающего и достойного капитана! Позвольте представиться - " + GetFullName(NPChar) + ". Я капитан " + xiStr(sld.BaseName + "PGG") + " '" + NPChar.Ship.Name + "', под флагом " + NationNameGenitive(sti(NPChar.nation)) + ". Чем могу быть полезна?";
link.l1 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". У меня к Вам деловое предложение!";
					link.l1.go = "march";
					link.l2 = "О, приветствую Вас! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я очень рад нашей встрече. Слыхал я, что Вы не только невороятная женщина, но и опытный моряк, не желаете пойти офицером ко мне на корабль? В деньгах не обижу.";
			link.l2.go = "officer";
		link.l3 = "Приветствую, коллега! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я много слышал о Вас... Судя по слухам, Вы настоящая гроза всего архипелага! Думаю, что если бы мы объединили наши усилия, то вместе мы смогли бы гораздо больше... Что скажите, сударыня?";
					link.l3.go = "companion";
link.l4 = "Здравствуйте, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете что-нибудь купить или продать?";
link.l4.go = "Trade_1";
			link.l5 = "Приветствую, миледи! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Не желаете ли скоротать время за игрой?";
			link.l5.go = "Play_Game";
		link.l6 = "Опа! Какая встреча! Ну, здравствуй, родная. Давненько мы с тобой не виделись. Мое имя - "+GetFullName(pchar)+", помнишь меня, каналья? ";
					link.l6.go = "duel";
		link.l7 = "Привет, подруга! Мое имя - "+GetFullName(pchar)+". Я капитан корабля '" + PChar.Ship.Name + "' под флагом " + NationNameGenitive(sti(PChar.nation)) + ". Я просто решил поздороваться. Бывай!";
					link.l7.go = "exit";
					npchar.quest.meeting = "1";
			}
			else
			{
				//повторные обращения
				if (sti(NPChar.nation) != PIRATE && GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
				{
					dialog.text = "О, рада видеть Вас снова в добром здравии, капитан "+GetFullName(pchar)+"! Чем могу быть полезна?";
					link.l1 = "У меня к Вам деловое предложение, миледи!";
					link.l1.go = "march";
					link.l2 = "Слыхал я, что Вы не только невороятная женщина, но и опытный моряк, не желаете пойти офицером ко мне на корабль? В деньгах не обижу.";
			link.l2.go = "officer";
		link.l3 = "Я тут подумал"+ GetSexPhrase("","а") +", не хотите ко мне присоединиться? Вместе мы сможем хорошие дела провернуть.";
					link.l3.go = "companion";
link.l4 = "Поторгуем, капитан?";
link.l4.go = "Trade_1";
			link.l5 = "Не желаете ли партейку, сударыня?";
			link.l5.go = "Play_Game";
		link.l6 = "Да, дорогуша, это снова я. Не желаешь ли пару лишних дырок в груди?";
					link.l6.go = "duel";
		link.l7 = "Я просто решил снова поприветствовать Вас!Удачи!";
					link.l7.go = "exit";
				}
				else
				{
					dialog.text = "О, рад видеть Вас снова в добром здравии, капитан "+GetFullName(pchar)+"! Чем могу быть полезна?";
					link.l1 = "У меня к Вам деловое предложение, миледи!";
					link.l1.go = "march";
					link.l2 = "Слыхал я, что Вы не только невороятная женщина, но и опытный моряк, не желаете пойти офицером ко мне на корабль? В деньгах не обижу.";
			link.l2.go = "officer";
		link.l3 = "Я тут подумал"+ GetSexPhrase("","а") +", не хотите ко мне присоединиться? Вместе мы сможем хорошие дела провернуть.";
					link.l3.go = "companion";
link.l4 = "Поторгуем, капитан?";
link.l4.go = "Trade_1";
			link.l5 = "Не желаете ли партейку, сударыня?";
			link.l5.go = "Play_Game";
		link.l6 = "Да, дорогуша, это снова я. Не желаешь ли пару лишних дырок в груди?";
					link.l6.go = "duel";
		link.l7 = "Я просто решил снова поприветствовать Вас!Удачи!";
					link.l7.go = "exit";
				}
			}
			NextDiag.TempNode = "First time";
		break;

// Общавочка <--

		 case "question":
			dialog.text = NPCStringReactionRepeat(""+GetFullName(npchar)+" к вашим услугам, милейший! Что вы хотели узнать?", 
				"Рада поболтать, капитан!", 
				"Ну, пожалуй, я ещё могу кое-что рассказать...",
                "К сожалению, но Вы утомили меня своми расспросами, капитан. Давайте сменим тему.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Может, расскажете что интересное?", 
				"Может, расскажете что интересное?",
                "Может, расскажете что интересное?", 
				"Понимаю. Как Вам будет угодно.", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("rumours_pgg", "rumours_pgg", "rumours_pgg", "rumours_pgg",  "rumours_pgg", "rumours_pgg", "rumours_pgg",   "rumours_pgg",  "rumours_pgg", "rumours_pgg", "exit", npchar, Dialog.CurrentNode);
		break;

		//  Квест -->

		case "march":
Dialog.Text = "Если вы читаете это, значит, вы поймали баг ;) Сообщите об этом Navy, подробно, как вы его поймали :)";
		link.l1 = "Обязательно!!!!";
		link.l1.go = "exit";
		//раз в день.
		if (CheckAttribute(NPChar, "Companion_Talk") && GetNpcQuestPastDayParam(NPChar, "Companion_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("Я Вам уже все сказала на сегодня!", "Мне казалось, что мы все обсудили.");
			link.l1 = RandPhraseSimple("Как я мог"+ GetSexPhrase("","ла") +" забыть?!", "И правда. Удачи!");
			link.l1.go = "exit";
			break;
		}
		//корабль где?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("Какие дела?.. Ик... Не видишь мы с друзьями отдыхаем!.. Ик...", "Э... Никаких дел сегодня!");
			link.l1 = RandPhraseSimple("Понятно...", "Что ж, счастливо оставаться.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//разница в рангах... нефиг халявить
		if (sti(NPChar.rank) > sti(Pchar.rank)+10)
		{
			Dialog.Text = RandPhraseSimple("Какие дела?.. Ик... Не видишь мы с друзьями отдыхаем!.. Ик...", "Э... Никаких дел сегодня!");
			link.l1 = RandPhraseSimple("Понятно...", "Что ж, счастливо оставаться.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//есть ли место для компаньона
		if (GetCompanionQuantity(pchar) > 7)
		{
			Dialog.Text = RandPhraseSimple("Какие дела?.. Ик... Не видишь мы с друзьями отдыхаем!.. Ик...", "Э... Никаких дел сегодня!");
			link.l1 = RandPhraseSimple("Понятно...", "Что ж, счастливо оставаться.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
		break;
		}
		iRnd = rand(3);
		PChar.GenQuest.PGG_Quest.Template = rand(1);
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest.QstNumber.Template"))
		{
			PChar.GenQuest.PGG_Quest.Template = NPChar.PGGAi.ActiveQuest.QstNumber.Template;
		}
		PChar.GenQuest.PGG_Quest.Parts = GetCompanionQuantity(PChar)+1;
		PChar.GenQuest.PGG_Quest.Nation = iRnd;
		PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
		while(PChar.GenQuest.PGG_Quest.Island == Islands[GetCharacterCurrentIsland(pchar)].id)
		{
			PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
		}
		PChar.GenQuest.PGG_Quest.Island.Shore = GetIslandRandomShoreId(PChar.GenQuest.PGG_Quest.Island);
		while(PChar.GenQuest.PGG_Quest.Island.Shore == "")
		{
			PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
			PChar.GenQuest.PGG_Quest.Island.Shore = GetIslandRandomShoreId(PChar.GenQuest.PGG_Quest.Island);
			if (sti(PChar.GenQuest.PGG_Quest.Template)) 
			{
				if (!isLocationFreeForQuests(PChar.GenQuest.PGG_Quest.Island)) PChar.GenQuest.PGG_Quest.Island.Shore = "";
			}
			else
			{
				if (!isLocationFreeForQuests(PChar.GenQuest.PGG_Quest.Island.Shore)) PChar.GenQuest.PGG_Quest.Island.Shore = "";
			}
		}
		PChar.GenQuest.PGG_Quest.Island.Town = FindTownOnIsland(PChar.GenQuest.PGG_Quest.Island);
		PChar.GenQuest.PGG_Quest.Days = 20 + GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(pchar)].id, PChar.GenQuest.PGG_Quest.Island);
		PChar.GenQuest.PGG_Quest.Goods = GOOD_SHIPSILK + rand(11);
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "Дело у меня к тебе, "+ GetSexPhrase("приятель","подруга") +". Знаю, можно тебе довериться, но в таверне обсуждать не возьмусь, ушей много лишних. Жду тебя у меня на борту. Помнишь, моя посудина зовется '" + NPChar.Ship.Name + "'.";
//			link.l1 = "Выкладывай сейчас, дорогая, некогда мне по гостям расхаживать.";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("У меня есть остренькое дельце для Вас и ваших головорезов.", 
								"Объединим силы и  мы сможем взять отличный куш! Ну, конечно, придется кое-кого убить. Хе-хе."), 
							RandPhraseSimple("У меня есть к вам деловое предложение, капитан.", 
							"Капитан, ваша репутация хорошо известна и, поэтому, я хочу вам предложить участие в одном заманчивом деле. ")) + 
						RandPhraseSimple("Только между нами. Давайте-ка, обсудим все у меня в кают-компании на '" + NPChar.Ship.Name + "' за бочонком отличного эля. Сегодня.", "Здесь говорить об этом не резон, потолкуем у меня на судне '" + NPChar.Ship.Name + "' в тишине да в спокойствии. Не затягивайте.");
			link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("К черту проволочки! Хорошее хочу знать быстро, а плохое еще быстрее!", 
								"Незачем откладывать! В таверне есть комната, там и обсудим!"), 
							RandPhraseSimple("Почему бы не обсудить ваше предложение прямо сейчас, в комнате таверны?", 
								"Боюсь, у меня нет желания посещать ваше судно. Если вам что-то нужно, выкладывайте здесь!"));
		}
		else
		{
			PChar.GenQuest.PGG_Quest.Nation = FindEnemyNation2NationWithoutPirates(sti(PChar.Nation));
			Dialog.Text = "Тс-с-с... В таверне обсуждать дела не стоит, ушей много лишних. Жду тебя на моем корабле '" + NPChar.Ship.Name + "'. Там и поговорим.";
			link.l1 = "Некогда мне, да и бегать я не люблю.";
		}
		link.l1.go = "Quest_1_Work_1";
		link.l2 = PCharRepPhrase(RandPhraseSimple("Я приду! Но, если ты попусту потратишь мое время, я вырву тебе язык!", 
					RandSwear() + "Жди, надеюсь, дело стоящее. И не вздумай шутить со мной!"), 
				RandPhraseSimple("Я с удовольствием принимаю ваше приглашение, капитан.", 
					"Вы меня заинтриговали. Разумеется, я приду."));
		link.l2.go = "Exit_Quest_1_AfterTavernTalk";
		Group_DeleteGroup("PGGQuest");
		break;

	case "Quest_1_Work_1":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("Да тебя, небось, от качки тошнит! Иди, найди себе мамашу с соской!!!", 
					"Что, "+ GetSexPhrase("приятель","подруга") +", в штаны наложил"+ GetSexPhrase("","а") +" от страха?!! Вали! Ты мне не пара."), 
				RandPhraseSimple("Нет - так нет. Неволить не буду, значит, неинтересно тебе золото.", 
					"Или так, или никак. Тебе решать. На золото много охотников."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("Ха! А ты с перчиком! И не боишься... Приду!", 
					"Умеешь настоять на своем, подруга. Жди."), 
				RandPhraseSimple("Хорошо, я соглас"+ GetSexPhrase("ен","на") +".", 
					"Вы очень убедительны. Я готов"+ GetSexPhrase("","а") +" обсудить дела на вашем судне."));
		link.l1.go = "Exit_Quest_1_AfterTavernTalk";
		link.l2 = PCharRepPhrase(RandPhraseSimple("Ха! Думал заманить меня на свой корабль и убить? Не выйдет!", 
					"Слова твои не стоят и пенни! Ни к чему мне с тобой дела иметь!"), 
				RandPhraseSimple("Сомнительное предложение. Я вынужден"+ GetSexPhrase("","а") +" отказаться.", 
					"Приятно было познакомиться, капитан " + GetFullName(NPChar) + ". Прощайте."));
		link.l2.go = "Quest_1_NotWork";
		break;

	case "Quest_1_NotWork":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("Рому мне! А ты убирайся с глаз моих!", 
					"Мы уже все обсудили, не так ли?"), 
				RandPhraseSimple("Идите своей дорогой, я занята.", 
					"Полагаю, у нас с вами нет общих тем."));
		link.l1 = RandSwear();
		link.l1.go = "exit";
		break;

	case "Quest_1_Work_2":
		Dialog.Text = "Я же сказала, что жду вас на корабле!";
		link.l1 = "А... конечно...";
		link.l1.go = "exit_1488";
		NextDiag.TempNode = "Quest_1_Work_2";
		break;

	case "Exit_Quest_1_AfterTavernTalk":
		PChar.GenQuest.PGG_Quest = 1;
		PChar.GenQuest.PGG_Quest.Stage = 0;
		PChar.GenQuest.PGG_Quest.PGGid = NPChar.id;

		Group_AddCharacter("PGGQuest", NPChar.id);
		Group_SetGroupCommander("PGGQuest", NPChar.id);
		Group_SetAddress("PGGQuest", Islands[GetCharacterCurrentIsland(PChar)].id, "Quest_Ships", "Quest_Ship_1");
		Group_SetTaskNone("PGGQuest");

		NPChar.DeckDialogNode = "Quest_1_Ship";
		NPChar.Nation.Bak = NPChar.Nation;
		NPChar.Nation = GetCityNation(GetCurrentTown());
		NPChar.AlwaysFriend = true;
		NPChar.Abordage.Enable = true; //нельзя брать на абордаж

				SetCharacterRelationBoth(sti(PChar.index), sti(NPChar.index), RELATION_FRIEND);

		ReOpenQuestHeader("Gen_PGGQuest1");
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Tavern");
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Tavern_1");
			AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("","а"));
		}
		AddQuestUserData("Gen_PGGQuest1", "sShipName", NPChar.Ship.Name);

		NextDiag.CurrentNode = "Quest_1_Work_2";
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;

	case "Quest_1_Ship":
		if (GetCompanionQuantity(PChar) == COMPANION_MAX)
		{
			Dialog.Text = RandPhraseSimple("Э, нет... Так дело не пойдет... Не много ли тебе кораблей, "+ GetSexPhrase("приятель","подруга") +"?", 
					"Ха! В такой большой компании секрета не удержишь! Проваливай.");
			link.l1 = RandPhraseSimple("Ну, как хочешь!", 
					"Что ж, не очень-то и хотелось.");
			link.l1.go = "exit_uvol";
			PChar.Quest.PGGQuest1_RemoveEnd.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_RemoveEnd.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_RemoveEnd.function = "PGG_Q1RemoveShip";
			break;
		}
		PChar.GenQuest.PGG_Quest.Stage = 1;
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "Ну, вот и славно, теперь я уверена - лишних ушей нет, мои матросы уже в курсе. Предложение такое - взять немного бесхозного добра!";
//			link.l1 = "А что тут сложного? И почему ты делишься этим со мной?";
			Dialog.Text = RandPhraseSimple("Добро пожаловать на борт, капитан!", 
					"Ну, вот и славно, теперь я уверен - лишних ушей нет, мои матросы уже в курсе.") + 
					"Предложение такое – взять немного бесхозного добра.";
			link.l1 = RandPhraseSimple("А что тут сложного? И почему ты делишься этим со мной?", 
					"- Бесхозного? Да ты, приятель, шутишь!");
		}
		else
		{
			Dialog.Text = "Ну, вот и славно, теперь я уверена - лишних ушей нет, рассказывай!";
			link.l1 = "Предложение такое - взять немного бесхозного добра.";
		}
		link.l1.go = "Quest_1_Ship_1";
		break;

	case "Quest_1_Ship_1":
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			Dialog.Text = RandPhraseSimple("Ну, есть люди, которые считают его своим, а нужно убедить их в обратном.", 
					"Ну конечно, придется кое-кого убить. Но ведь за этим дело не станет?!");
			link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("Ближе к делу!", 
					"Это уже пахнет хорошей резней! Где они?"), 
				RandPhraseSimple("Хотелось бы узнать подробности вашего предложения.", 
					"Что конкретно вы хотите мне предложить?"));
			link.l1.go = "Quest_1_Ship_Detail";
			link.l2 = PCharRepPhrase(RandPhraseSimple("Что-то ты темнишь. Не хочу я с тобой в это ввязываться!", 
					"Выглядит просто, да я тебе не верю! Хочешь чужими руками жар загребать? Я не соглас"+ GetSexPhrase("ен","на") +"!"), 
				RandPhraseSimple("Предложение заманчивое, но вынужден"+ GetSexPhrase("","а") +" отказаться.", 
					"Нет, чужое я с детства не беру, предпочитаю, что бы дарили. Я пас."));
			link.l2.go = "Quest_1_Ship_Refuse";
		}
		else
		{
			Dialog.Text = "А что тут сложного? И почему ты делишься этим со мной?";
			link.l1 = "Ну, есть люди, которые считают его своим, а нужно убедить их в обратном.";
			link.l1.go = "Quest_1_Ship_Detail";
		}
		break;

	case "Quest_1_Ship_Detail":
		sTmp = "Караван, принадлежащий " + NationNameGenitive(sti(PChar.GenQuest.PGG_Quest.Nation)) + ", перевозящий ";
		if (sti(PChar.GenQuest.PGG_Quest.Goods) == GOOD_SLAVES)
		{
			sTmp += "Рабов";
			PChar.GenQuest.PGG_Quest.Goods.Text = "Рабов";
		}
		else
		{
			sTmp += XI_ConvertString(Goods[sti(PChar.GenQuest.PGG_Quest.Goods)].Name);
			PChar.GenQuest.PGG_Quest.Goods.Text = XI_ConvertString(Goods[sti(PChar.GenQuest.PGG_Quest.Goods)].Name);
		}

		if (PChar.GenQuest.PGG_Quest.Island.Town == "" || PChar.GenQuest.PGG_Quest.Island.Town == "Caiman" ||
			PChar.GenQuest.PGG_Quest.Island.Town == "Terks" || PChar.GenQuest.PGG_Quest.Island.Town == "Dominica")
		{
			sLoc = GetConvertStr(PChar.GenQuest.PGG_Quest.Island, "LocLables.txt") + "");
		}
		else
		{
			sLoc = XI_ConvertString("Colony" + PChar.GenQuest.PGG_Quest.Island.Town + "Gen");
		}
		
		if (sti(PChar.GenQuest.PGG_Quest.Template)) 
		{
			sTmp +=	", остановился недалеко от " + sLoc + " у бухты " + GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt") + " для пополнения припасов.";
		}
		else
		{
			sTmp += ", попал в шторм недалеко от " + sLoc + " и пошел на дно. Но они успели спасти часть груза и высадились в бухте " + GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt") + 
				". Сейчас они ждут прихода своей эскадры.";
		}
		
		Dialog.Text = sTmp;
		link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("Не тяни, выкладывай все поживее!", 
					"Я в тебе не ошиб"+ GetSexPhrase("ся","лась") +", что ты еще знаешь?"), 
				RandPhraseSimple("Очень интересно, продолжайте!", 
					"Я в"+ GetSexPhrase("есь","ся") +" внимание!"));
		link.l1.go = "Quest_1_Ship_Detail_1";

		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			link.l2 = PCharRepPhrase(RandPhraseSimple("Дельце неплохое, но откажусь. Не резон мне с " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + " ссорится.", 
					"Караван? Бесхозное? Да там тысяча солдат при нем! Не годится. Я ухожу."), 
				RandPhraseSimple("Нет, с " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + " я не воюю, не интересно.", 
					"Мой ответ – нет! Я не собираюсь портить отношения с " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + "!"));
			link.l2.go = NPCharRepPhrase(NPChar, "Quest_1_Ship_BadWay", "Quest_1_Ship_Refuse");
		}
		else
		{
			Dialog.Text = "Хм... Это уже пахнет хорошей резней. Детали?";
			link.l1 = sTmp;
		}
		if (sti(PChar.GenQuest.PGG_Quest.Template)) 
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Detail_A");
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Detail_B");
		}
		AddQuestUserData("Gen_PGGQuest1", "sNation", NationNameGenitive(sti(PChar.GenQuest.PGG_Quest.Nation)));
		AddQuestUserData("Gen_PGGQuest1", "sGoods", PChar.GenQuest.PGG_Quest.Goods.Text));
		AddQuestUserData("Gen_PGGQuest1", "sColony", sLoc);
		AddQuestUserData("Gen_PGGQuest1", "sShore", GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt"));
		break;

	case "Quest_1_Ship_Detail_1":
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "У нас есть только " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " для того, чтобы перехватить их.";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("Через " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " караван уйдет и нам их уже не догнать.", 
						"У нас есть ровно " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " дней, чтобы успеть их вырезать и забрать добычу!"), 
					RandPhraseSimple("В нашем распоряжении " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " дней на всю операцию.", 
						"Нам стоит поторопиться, " + PChar.Name + ". У нас в запасе всего " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + "."));
			link.l1 = RandPhraseSimple("Мы успеем! Отплываем сегодня же.", "Не будем медлить. Прикажите отплывать сегодня же.");
			link.l1.go = "Exit_Quest_1_Accept";
			AddQuestRecord("Gen_PGGQuest1", "q1_Accept");
		}
		else
		{
			Dialog.Text = "Очень интересно, продолжай.";
			link.l1 = "У нас есть только " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " для того, чтобы перехватить их.";
			link.l1.go = "Quest_1_Ship_Accept";
			AddQuestRecord("Gen_PGGQuest1", "q1_Accept_1");
		}
		AddQuestUserData("Gen_PGGQuest1", "nDays", FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)));
		break;

	case "Quest_1_Ship_Accept":
		Dialog.Text = "Не будем медлить! В путь!";
		link.l1 = "В путь!";
		link.l1.go = "Exit_Quest_1_Accept";
		break;

	case "Exit_Quest_1_Accept":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) < 2)
		{
			PChar.GenQuest.PGG_Quest.Stage = 2;
			PGG_Q1RemoveShip("");

			if (sti(PChar.GenQuest.PGG_Quest.Template)) 
			{
				PGG_Q1PlaceShipsNearIsland();
			}
			else
			{
				Locations[FindLocation(PChar.GenQuest.PGG_Quest.Island.Shore)].DisableEncounters = true;

				PChar.Quest.PGGQuest1_CheckStartState.win_condition.l1 = "Location";
				PChar.Quest.PGGQuest1_CheckStartState.win_condition.l1.Location = PChar.GenQuest.PGG_Quest.Island.Shore;
				PChar.Quest.PGGQuest1_CheckStartState.function = "PGG_Q1CheckStartState";
			}
			PChar.Quest.PGGQuest1_PGGDead.win_condition.l1 = "NPC_Death";
			PChar.Quest.PGGQuest1_PGGDead.win_condition.l1.Character = PChar.GenQuest.PGG_Quest.PGGid;
			PChar.Quest.PGGQuest1_PGGDead.function = "PGG_Q1PGGDead";

			SetTimerCondition("PGGQuest1_Time2Late", 0, 0, sti(PChar.GenQuest.PGG_Quest.Days), false);
			PChar.Quest.PGGQuest1_Time2Late.function = "PGG_Q1Time2Late";

			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			DeleteAttribute(NPChar, "AlwaysFriend");

			SetCompanionIndex(PChar, -1, sti(NPChar.index));
			SetCharacterRemovable(NPChar, false);
			
			SetBaseShipData(NPChar);
            DeleteAttribute(NPChar,"ship.sails");
			DeleteAttribute(NPChar,"ship.masts");
			DeleteAttribute(NPChar,"ship.blots");
			DeleteAttribute(NPChar,"ship.hulls");
			
			Fantom_SetCannons(NPChar, "pirate");
			Fantom_SetBalls(NPChar, "pirate");
		}
		NextDiag.CurrentNode = "Quest_1_Ship_Accept";
		DialogExit();
		break;

	case "Quest_1_Ship_Refuse":
		Dialog.Text = RandSwear() + "Вы меня разочаровали, капитан. А вы думали, что я вас приглашу на "+ RandPhraseSimple("воскресную мессу?!!", "детский утренник!??"));
		link.l1 = PCharRepPhrase(RandPhraseSimple("Это твое дело. А решать мое.", 
					"Не хочу сушиться на солнышке из-за пары песо."), 
				RandPhraseSimple("Мое решение окончательное, капитан.", 
					"Нам не о чем больше говорить."));
		link.l1.go = "Exit_Quest_1_Refuse";
		break;

	case "Exit_Quest_1_Refuse":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_RemoveShip.function = "PGG_Q1RemoveShip";

			AddQuestRecord("Gen_PGGQuest1", "q1_Close");
			AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("ся","ась"));
			CloseQuestHeader("Gen_PGGQuest1");
			DeleteAttribute(NPChar, "AlwaysFriend");
		}
		NPChar.Dialog.CurrentNode = "Quest_1_Ship_Refuse";
		NPChar.DeckDialogNode = "Quest_1_Ship_Refuse";
		DialogExit();
		break;

	case "Quest_1_Ship_BadWay":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("Да брось, все пройдет как по маслу и никто не узнает. Мы всех зарежем.", 
					"Узнал"+ GetSexPhrase("","а") +" все и сам"+ GetSexPhrase("","а") +" хочешь дельце провернуть? Не выйдет!"), 
				RandPhraseSimple("Куда это вы заторопились, капитан? Уж не к властям ли?", 
					"Весьма неумно влезть в логово тигра и думать, что сможешь запросто выбраться оттуда."));
		link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("Убирайся к морскому дьяволу! Я капитан " + GetFullName(PChar) + " и ты мне не указ! Я ухожу!", 
					"Клянусь дьяволом, ты меня выводишь из себя!"), 
				RandPhraseSimple("Ваше предложение мне неинтересно, и говорить нам более не о чем. Прощайте.", 
					"Полагаю, нам не о чем более говорить. Меня ждут дела."));
		link.l1.go = "Quest_1_Ship_BadWay_1";
		break;

	case "Quest_1_Ship_BadWay_1":
		Dialog.Text = RandSwear() + PCharRepPhrase(RandPhraseSimple("Схватить е"+ GetSexPhrase("го","е") +"! Привяжите е"+ GetSexPhrase("го","е") +" к пушке! Посмотрим, какого цвета у не"+ GetSexPhrase("го","е") +" кишки!!!", 
					"Эй, Джонни! Хендерсон! Хватайте мерзав"+ GetSexPhrase("ца","ку") +"! Не пускайте е"+ GetSexPhrase("го","е") +" к шлюпке!!!"), 
				RandPhraseSimple("Жаль, капитан! Надеюсь, в нашем трюме тебе будет уютно. Ну, а потом решим, что с тобой делать.", 
					"Белые рабы долго не живут, капитан, так что решайте: или Хендс прострелит вам голову из мушкета, или вы остаток жизни проведете в каменоломнях."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("Я заставлю тебя жрать твои поганые внутренности, " + GetFullName(NPChar) + "!!!", 
					"А ну прочь с дороги! Мерзавцы! Раскрою башку, как гнилую тыкву!"), 
				RandPhraseSimple("Ваше предложение неприемлемо... И весьма неблагоразумно!!!", 
					"А вы не очень гостеприимны... С дороги!!!"));
		link.l1.go = "Exit_Quest_1_DeckFight";
		break;

	case "Exit_Quest_1_DeckFight":
        GetCharacterPos(NPChar, &locx, &locy, &locz);
		DeleteAttribute(NPChar, "AlwaysFriend");
        sTmp = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
		LAi_SetImmortal(NPChar, true);
		LAi_SetActorType(NPChar);
		LAi_ActorRunToLocation(NPChar, "reload", sTmp, "none", "", "", "", 5.0);

		LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		//группа может быть занята, а проверок по группам у нас нет... :(
		if (!CheckAttribute(pchar, "questTemp.PGGContra.Know"))
		{
			sTmp = "PGGTmp";
		}
		else
		{
			sTmp = "PGGQst";
		}
		PChar.GenQuest.PGG_Quest.GrpID = sTmp;

		for (i=1; i<5; i++)
		{
			sld = CharacterFromID("saylor_0" + i);
			LAi_group_MoveCharacter(sld, sTmp);
		}
		LAi_group_FightGroups(LAI_GROUP_PLAYER, sTmp, true);
		LAi_group_SetCheck(sTmp, "PGG_Q1AfterDeckFight");
		chrDisableReloadToLocation = true;

		PGG_ChangeRelation2MainCharacter(NPChar, -20);
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LAi_SetFightMode(pchar, true);
		break;

	case "Quest_1_Time2Late":
		chrDisableReloadToLocation = false;

		//перенес сюда.. х.з. вроде будет лучше (Баг Изгоя.)
		PChar.Quest.PGGQuest1_PGGDead.Over = "Yes";
		PChar.Quest.PGGQuest1_GroupDead.Over = "Yes";
		PChar.Quest.PGGQuest1_CheckStartState.Over = "Yes";

//		Dialog.Text = "Так, " + GetFullName(PChar) + ", что-то зря я с тобой связалась, добыча утекла сквозь пальцы как вода. Прощай!";
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("Гром и молния! Мы опоздали! А все из-за вас, ленивые олухи! Нечего нам с тобой теперь делить, " + GetFullName(PChar) + ". Поднять стаксель! Травить марс помалу! ", 
					"Так, " + GetFullName(PChar) + ", что-то зря я с тобой связалась, добыча утекла сквозь пальцы как вода. Прощай!"), 
				RandPhraseSimple("Они исчезли! Виной всему ваша нерасторопность! Нам с вами не по пути " + GetFullName(PChar) + ".", 
					"Караван мы не догоним, можно сушить весла. Зря я с вами связалась! Прощайте."))
		link.l1 = PCharRepPhrase(RandPhraseSimple("Да и черт с этим караваном! Ловцы жемчуга ничуть не хуже, а риска никакого!", 
					"Удача с нами, еще не вечер! Море изобилует жалкими торгашами, ждущими, пока мы отнимем их денежки!"), 
				RandPhraseSimple("Действительно, жаль, что такая блестящая операция закончилась полным фиаско! Прощайте!", 
					"Человек предполагает, а Бог располагает... Прощайте!"));
		link.l1.go = "Exit_Quest_1_2Late";

		AddQuestRecord("Gen_PGGQuest1", "q1_Time2Late");
		CloseQuestHeader("Gen_PGGQuest1");
		break;

	case "Exit_Quest_1_2Late":
        LAi_SetPlayerType(PChar);
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			RemoveCharacterCompanion(pchar, NPChar);

			NPChar.PGGAi.IsPGG = true;
			NPChar.RebirthPhantom = true;

			LAi_SetWarriorTypeNoGroup(NPChar);
			LAi_group_MoveCharacter(NPChar, "GroupDeck");

			PChar.Quest.PGGQuest1_Clear.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_Clear.win_condition.l1.Location = PChar.location;
			if (PChar.location == "Ship_deck")
			{
/*				PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1 = "ExitFromSea";
				PChar.Quest.PGGQuest1_RemoveShip.function = "PGG_Q1RemoveShip";
				PChar.Quest.PGGQuest1_Clear.win_condition.l1 = "ExitFromSea";
*/				PChar.quest.Munity = "Deads";
			}
			PChar.Quest.PGGQuest1_Clear.function = "PGG_Q1EndClear";
		}
		NextDiag.CurrentNode = "Quest_1_Failed";
		DialogExit();
		break;

	case "Quest_1_CheckResult":
		if (PChar.location == PChar.GenQuest.PGG_Quest.Island.Shore)
		{
			Locations[FindLocation(PChar.GenQuest.PGG_Quest.Island.Shore)].DisableEncounters = false;
		}
		else
		{
			PChar.quest.Munity = "Deads";
		}
		chrDisableReloadToLocation = false;

		//не взяли груз...
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			PChar.GenQuest.PGG_Quest.FailedPaySum = sti(PChar.GenQuest.PGG_Quest.Days)*10000;
//			Dialog.Text = "Н-да, связалась я с тобой. Все погубил. Ты теперь мне должен неустойку в размере " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + ".";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("Кровожадн"+ GetSexPhrase("ый ублюдок","ая дрянь") +"! Все ушло на дно к морскому дьяволу! " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " песо на бочку, и я видеть тебя больше не желаю!", 
						"Ты себя адмиралом Нельсоном вообразил"+ GetSexPhrase("","а") +"? Потопил"+ GetSexPhrase("","а") +" всю добычу, "+ GetSexPhrase("идиот","дура") +"! Отсыпь мне " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " песо и проваливай!"), 
					RandPhraseSimple("Вы здесь войну решили устроить! Это совершенно никуда не годится! Полагаю, мы все забудем, если вы уплатите нам " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " песо ", 
						"Ваши методы недопустимы в такого рода делах! Вы провалили все дело! Немедленно уплатите нашу долю в размере " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " песо и отправляйтесь на все четыре стороны! "));
			link.l1 = PCharRepPhrase(RandPhraseSimple("Если бы не я, ты бы сейчас крабов кормила, жадная образина!", 
						"Лучше было позволить флагману взять на абордаж твое корыто, тогда бы ты уже болталась на рее и не отравляла воздух! "), 
					RandPhraseSimple("Ваши требования неуместны, а намеки оскорбительны!", 
						"Договора о неустойке не было, стало быть, и платить я не буду!"));
			link.l1.go = "Quest_1_NotPay";
			if (sti(pchar.money) >= sti(PChar.GenQuest.PGG_Quest.FailedPaySum))
			{
				link.l2 = PCharRepPhrase(RandPhraseSimple("Я не могу тебе дать сейчас бой, и ты это знаешь! Подавись своими песо! Вот!", 
								"Песо!!! Что же, фортуна сейчас не на моей стороне. Я соглас"+ GetSexPhrase("ен","на") +"."), 
							RandPhraseSimple("Ваши требования возмутительны, но выбора у меня, похоже, нет.", 
								"Ваши аппетиты чрезмерны, но я вынужден"+ GetSexPhrase("","а") +" согласиться!"));
				link.l2.go = "Exit_Quest_1_Failed";
			}
		}
		else
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			Dialog.Text = "Н-да, связалась я с тобой. Все погубил"+ GetSexPhrase("","а") +". Не умеешь -  не берись, и других не втягивай.";
			link.l1 = "Да ну! Сама же видела, не получалось.";
			link.l1.go = "Exit_Quest_1_Failed";
		}

		//минимум треть если взял, то гуд!
		if (sti(PChar.GenQuest.PGG_Quest.Goods.Taken) > MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Qty)/3))
		{
			PChar.GenQuest.PGG_Quest.Ok = 1;
//			Dialog.Text = "Итак, добыча составила " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ". Давай делить. ";
			Dialog.Text = PCharRepPhrase("Жаркое дельце! Добыча составила " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".", 
					"Отлично сработали, капитан! Добыча составила " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".");
			i = sti(PChar.GenQuest.PGG_Quest.Parts);
			PChar.GenQuest.PGG_Quest.Goods.Part = MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Taken) / i);
			if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
			{
				Dialog.Text = Dialog.Text + PCharRepPhrase(" Моя доля ", " Доля, приходящаяся на мое судно - ");
			}
			else
			{
				Dialog.Text = Dialog.Text + " Твоя доля ";
			}
			Dialog.Text = Dialog.Text + PChar.GenQuest.PGG_Quest.Goods.Part + ".";
			link.l1 = PCharRepPhrase(RandPhraseSimple("Справедливо! Уже грузят шлюпки!", "Да, все точно... Уговор дороже денег."), 
					RandPhraseSimple("Ваши расчеты правильны. Я соглас"+ GetSexPhrase("ен","на") +".", "В дележе вы безупречны."));
			link.l1.go = "Exit_Quest_1_End";
			link.l2 = PCharRepPhrase(RandPhraseSimple("И ты еще требуешь свою долю? Да тебя надо вздернуть на рее и не мешкать!", 
						"Долю? Здесь каждый сам за себя, и если тебе ничего не досталось, то это твои проблемы!"), 
					RandPhraseSimple("Не думаю, что вы на что-то можете рассчитывать.", 
						"Мой ответ – нет! Я не собираюсь делиться с разными проходимцами!"));
			link.l2.go = "Quest_1_NotPay";
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Fail");
		}
		break;

	case "Quest_1_NotPay":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("Нет, так нет! Спорить не буду! Прощай!", 
					"Не будем проливать кровь и усугублять неудачу! В другой раз повезет больше!"), 
				RandPhraseSimple("Что же, прощайте, капитан, я не в том положении, чтобы настаивать...", 
					"Повреждения моего корабля и потери не позволяют мне настаивать на справедливом решении вопроса. Оставлю это на вашей совести, капитан!"));
		link.l1 = PCharRepPhrase(RandPhraseSimple("Попутного ветра!", "Семь футов под килем!"), 
				RandPhraseSimple("Прощайте! Полагаю, свежий морской воздух пойдет вам на пользу!", 
					"Чудно. Прощайте!"));
		link.l1.go = "Exit_Quest_1_Failed";
		PChar.GenQuest.PGG_Quest.Stage = -1;

		bOk = makeint(NPChar.reputation) < 41 && PGG_ChangeRelation2MainCharacter(NPChar, 0) < 75;
		if (bOk || CheckAttribute(PChar, "GenQuest.PGG_Quest.Ok"))
		{
			PChar.GenQuest.PGG_Quest.Stage = 4;
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("Ты не понял"+ GetSexPhrase("","а") +"! Этим ты мог"+ GetSexPhrase("","ла") +" бы купить себе жизнь! Схватить "+ GetSexPhrase("ублюдка","мерзавку") +"!", 
						"Ты, наверное, думаешь, что с тобой шутят? Пропустим тебя под килем, и сразу станешь сговорчивей!"), 
					RandPhraseSimple("Придется подсократить вашу жизнь, капитан! Не хотите по-хорошему, то мигом отправитесь на тот свет!", 
						"Вы не оставляете мне выбора, " + GetFullName(PChar) + "! Я возьму свое, хотите вы того или нет!"));
			link.l1 = PCharRepPhrase(RandPhraseSimple("Клянусь дьяволом, ты за это заплатишь!", 
						"Йхо-хо! Рискни убить меня, капитана " + GetFullName(PChar) + "! "), 
					RandPhraseSimple("Ничего личного - это деловой подход.", 
						"Кто сильнее, тот и прав. Ничего личного, сударыня."));
			link.l1.go = "duel_sea_pgg";
		}
		break;

	case "Exit_Quest_1_Failed":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			AddMoneyToCharacter(PChar, -(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)));
			AddQuestRecord("Gen_PGGQuest1", "q1_FailPay");
		AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("","а"));
		AddQuestUserData("Gen_PGGQuest1", "sSex1", GetSexPhrase("ен","на"));
		NPChar.lifeday = 0;
		LAi_CharacterDisableDialog(NPChar);
		NPChar.DontDeskTalk = true;
		}
		CloseQuestHeader("Gen_PGGQuest1");
		NPChar.lifeday = 0;
		LAi_CharacterDisableDialog(NPChar);
		NPChar.DontDeskTalk = true;
		RemoveCharacterCompanion(pchar, NPChar);

		if (PChar.Location == "Ship_deck")
		{
			PChar.Quest.PGGQuest1_FailedExitSea.win_condition.l1 = "ExitFromSea";
			PChar.Quest.PGGQuest1_FailedExitSea.function = "PGG_Q1EndClear";
		}
		else
		{
			PChar.Quest.PGGQuest1_FailedExitLoc.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_FailedExitLoc.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_FailedExitLoc.function = "PGG_Q1EndClear";
		}
		PGG_ChangeRelation2MainCharacter(NPChar, -5);

		LAi_SetImmortal(NPChar, true);
		//что б не били сопровождение.
		for (i = 1; i < sti(PChar.GenQuest.PGG_Quest.GrpID.Qty); i++)
		{
			sld = CharacterFromID("pirate_" + i);
			LAi_SetImmortal(sld, true);
		}

		NextDiag.CurrentNode = "Quest_1_Failed";
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;

	case "Quest_1_Failed":
		Dialog.Text = "Не хочу больше иметь с тобой дел!";
		link.l1 = "Да и не нужно.";
		link.l1.go = "exit_uvol";
		NextDiag.TempNode = "Quest_1_Failed";
		break;

	case "Quest_1_End":
		Dialog.Text = "Приятно иметь с Вами дело! Удачи.";
		link.l1 = "И Вам!";
		link.l1.go = "exit_uvol";
		break;

	case "Exit_Quest_1_FailedFight":
		RemoveCharacterCompanion(pchar, NPChar);

		LAi_LockFightMode(pchar, false);
		LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
		LAi_group_SetRelation("PGGTmp", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);	
		LAi_group_FightGroups(LAI_GROUP_PLAYER, "PGGTmp", true);	
		Group_AddCharacter("PGGQuest", NPChar.id);
		Group_SetGroupCommander("PGGQuest", NPChar.id);
		Group_SetTaskNone("PGGQuest");

		PGG_ChangeRelation2MainCharacter(NPChar, -15);

		GetCharacterPos(NPChar, &locx, &locy, &locz);
        sTmp = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
		NextDiag.CurrentNode = "First time";
		DialogExit();

		Log_TestInfo("go to loc " + sTmp + " " + NPChar.location);
		NPChar.location = PChar.location;
		if (PChar.location != "Ship_Deck") sTmp = "reload1_back";

AddQuestRecord("Gen_PGGQuest1", "q1_OkNotShare");
CloseQuestHeader("Gen_PGGQuest1");

		PChar.questTemp.Chr2Remove = NPChar.id;
		LAi_ActorRunToLocator(NPChar, "reload", sTmp, "RemoveCharacterFromLocation", 5.0);

		LAi_SetImmortal(NPChar, true);
		LAi_SetFightMode(pchar, true);
		break;

	case "Exit_Quest_1_End":
		RemoveCharacterCompanion(PChar, NPChar);

		i = sti(PChar.GenQuest.PGG_Quest.Goods.Part);
/*		i *= (sti(PChar.GenQuest.PGG_Quest.Parts)-1);
		i += sti(PChar.GenQuest.PGG_Quest.StartGoods);
		n = GetCompanionQuantity(PChar);
		SetCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), i);
		for (i = 1; i < n; i++)
		{
			iRnd = GetCompanionIndex(PChar, i);
			if (iRnd != -1)
			{
				sld = GetCharacter(iRnd);
				if (GetRemovable(sld))
				{
					Log_TestInfo("" + sld.id);
					SetCharacterGoods(sld, sti(PChar.GenQuest.PGG_Quest.Goods), 0);
				}
			}
		}
*/
		RemoveCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), i);
/*		if (PChar.Location == "Ship_deck")
		{
			PChar.Quest.PGGQuest1_EndExitSea.win_condition.l1 = "ExitFromSea";
			PChar.Quest.PGGQuest1_EndExitSea.function = "PGG_Q1EndClear";
		}
		else
		{*/
			PChar.Quest.PGGQuest1_EndExitLoc.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_EndExitLoc.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_EndExitLoc.function = "PGG_Q1EndClear";
		//}
		AddQuestRecord("Gen_PGGQuest1", "q1_OkShare");
		CloseQuestHeader("Gen_PGGQuest1");

		//что б не били сопровождение.
		for (i = 1; i < sti(PChar.GenQuest.PGG_Quest.GrpID.Qty); i++)
		{
			sld = CharacterFromID("pirate_" + i);
			LAi_SetImmortal(sld, true);
		}

		LAi_SetImmortal(NPChar, true);
		NextDiag.CurrentNode = "Quest_1_End";
		DialogExit();
  		LAi_SetWarriorType(NPChar); // сброс группы ГГ
		LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
		break;

	case "Quest_1_SharePrise":
		chrDisableReloadToLocation = false;
		Dialog.Text = PCharRepPhrase("Настоящее побоище! Добыча составила " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".", "Неплохо, капитан! Добыча составила " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".");

		i = sti(PChar.GenQuest.PGG_Quest.Parts);
		PChar.GenQuest.PGG_Quest.Goods.Part = MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Taken) / i);
        SetCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), sti(PChar.GenQuest.PGG_Quest.Goods.Taken) + GetCargoGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods)));
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			Dialog.Text = Dialog.Text + " Моя доля ";
		}
		else
		{
			Dialog.Text = Dialog.Text + " Твоя доля ";
		}
		Dialog.Text = Dialog.Text + PChar.GenQuest.PGG_Quest.Goods.Part + ".";
		link.l1 = PCharRepPhrase(RandPhraseSimple("Справедливо, разрази меня гром!", "Да, все точно, разрази меня гром!"), 
			RandPhraseSimple("Ваши расчеты правильны. Я соглас"+ GetSexPhrase("ен","на") +".", "В дележе вы безупречны."));
		link.l1.go = "Exit_Quest_1_End";
		link.l2 = PCharRepPhrase(RandPhraseSimple("Ты еще требуешь свою долю? Да пропади ты пропадом!", 
						"Долю? Здесь каждый сам за себя, и если тебе ничего не досталось, то это твои проблемы!"), 
					RandPhraseSimple("Не думаю, что вы на что-то можете рассчитывать.", 
						"Я не собираюсь делиться с разными проходимцами!"));
		link.l2.go = "Quest_1_NotPay";
		break;

	// Квест <--

//  игры  -->
case "Play_Game":
			dialog.text = "Давайте! Отдых никогда не вредил здоровью... только кошельку... Какие игры вы предпочитаете?";
			link.l1 = "Перекинемся в карты на солидный интерес?";
			link.l1.go = "Cards_begin";
   			link.l2 = "Погремим костями в покер-джокер?";
			link.l2.go = "Dice_begin";
			link.l10 = "Прошу простить меня, но меня ждут дела.";
			link.l10.go = "exit";
		break;

	//  карты -->
        case "Card_Game":
            if (!CheckNPCQuestDate(npchar, "Card_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Card_date_Yet");
                dialog.text = "Я не буду играть в азартные игры с разными проходимцами!";
    			link.l1 = "Как вам будет угодно.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Card_date_begin"))
				{
					dialog.text = "Давайте! Отдых никогда не вредил здоровью... только кошельку...";
	    			link.l1 = "Замечательно.";
	    			link.l1.go = "Cards_begin";
	    			link.l2 = "По каким правилам игра?";
	    			link.l2.go = "Cards_Rule";
    			}
    			else
    			{
					dialog.text = "Нет, с меня довольно игр на сегодня.";
	    			link.l1 = "Как вам будет угодно.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Cards_Rule":
   			dialog.text = CARDS_RULE;
			link.l1 = "Что ж, давайте начнем!";
			link.l1.go = "Cards_begin";
			link.l3 = "Нет, это не для меня...";
			link.l3.go = "exit";
		break;

		case "Cards_begin":
			dialog.text = "Отлично! Давайте теперь определимся со ставкой.";
			link.l1 = "Играем по 1000 песо.";
			link.l1.go = "Cards_Node_100";
			link.l2 = "Давайте по 5000 песо.";
			link.l2.go = "Cards_Node_500";
	    		link.l3 = "Погодите! По каким правилам игра?";
	    		link.l3.go = "Cards_Rule";
			link.l4 = "Пожалуй, мне пора.";
			link.l4.go = "exit";
		break;

		case "Cards_Node_100":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "О Вас ходит слава непревзойдённого шулера. Я не буду с вами играть.";
                link.l1 = "Все врут! Ну и не нужно.";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "Изволите шутить, " + GetAddress_Form(NPChar) + "? У вас нет денег!";
                link.l1 = "Бывает.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "Все! Нужно завязывать с картами, а то окончательно сяду на мель...";
                link.l1 = "Жаль.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 1000 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 1000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_Node_500":
            if (!CheckCardsGameSmallRate())
		    {
                dialog.text = "О Вас ходит слава непревзойдённого шулера. Я не буду с вами играть.";
                link.l1 = "Все врут! Ну и не нужно.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckCardsGameBigRate())
		    {
                dialog.text = "Я слышал, что Вы очень хорошо играете. Я не буду играть с Вами по таким большим ставкам.";
                link.l1 = "Давайте по более низким ставкам?";
			    link.l1.go = "Cards_Node_100";
				link.l2 = "Извините, мне пора.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "Изволите шутить, " + GetAddress_Form(npchar) + "? У вас нет 15000 песо!";
                link.l1 = "Будут!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "Прошу меня простить, но нет. Такие ставки не доведут до добра мой кошелёк.";
                link.l1 = "Как угодно.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 5000 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Cards_begin_go";
			pchar.GenQuest.Cards.npcharIdx = npchar.index;
            pchar.GenQuest.Cards.iRate     = 5000;
            pchar.GenQuest.Cards.SitType   = false;
		break;

		case "Cards_begin_go":
            SetNPCQuestDate(npchar, "Card_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchCardsGame();
		break;
	    // карты <--

	    //  кости -->
        case "Dice_Game":
            if (!CheckNPCQuestDate(npchar, "Dice_date_Yet") || sti(PChar.rank) < 4 || isBadReputation(pchar, 50) || GetCharacterSkillToOld(pchar, SKILL_LEADERSHIP) < rand(5))
            {
                SetNPCQuestDate(npchar, "Dice_date_Yet");
                dialog.text = "Я не буду играть в азартные игры с разными проходимцами!";
    			link.l1 = "Как вам будет угодно.";
    			link.l1.go = "exit";
			}
			else
			{
				if (CheckNPCQuestDate(npchar, "Dice_date_begin"))
				{
					dialog.text = "Давайте! Отдых никогда не вредил здоровью... только кошельку...";
	    			link.l1 = "Замечательно.";
	    			link.l1.go = "Dice_begin";
	    			link.l2 = "По каким правилам игра?";
	    			link.l2.go = "Dice_Rule";
    			}
    			else
    			{
					dialog.text = "Нет, с меня довольно игр на сегодня.";
	    			link.l1 = "Как вам будет угодно.";
	    			link.l1.go = "exit";
				}
			}
		break;

		case "Dice_Rule":
   			dialog.text = DICE_RULE;
			link.l1 = "Что ж, давайте начнем!";
			link.l1.go = "Dice_begin";
			link.l3 = "Нет, это не для меня...";
			link.l3.go = "exit";
		break;

		case "Dice_begin":
			dialog.text = "Замечательно! Давайте определимся со ставкой.";
			link.l1 = "Играем по 500 песо за кубик.";
			link.l1.go = "Dice_Node_100";
			link.l2 = "Давайте по 2000 песо за кубик.";
			link.l2.go = "Dice_Node_500";
			link.l3 = "Погодите! По каким правилам игра?";
	    		link.l3.go = "Dice_Rule";
			link.l4 = "Пожалуй, мне пора.";
			link.l4.go = "exit";
		break;

		case "Dice_Node_100":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "О Вас ходит слава непревзойдённого шулера. Я не буду с Вами играть.";
                link.l1 = "Все врут! Ну и не нужно.";
			    link.l1.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 3000)
		    {
                dialog.text = "Изволите шутить, " + GetAddress_Form(NPChar) + "? У вас нет денег!";
                link.l1 = "Бывает.";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 3000)
		    {
                dialog.text = "Все! Нужно завязывать с играми, а то окончательно сяду на мель...";
                link.l1 = "Жаль.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 500 монет.";
			link.l1 = "Начали!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 500;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_Node_500":
            if (!CheckDiceGameSmallRate())
		    {
                dialog.text = "О Вас ходит слава непревзойдённого шулера. Я не буду с Вами играть.";
                link.l1 = "Все врут! Ну и не нужно.";
			    link.l1.go = "exit";
			    break;
		    }
			if (!CheckDiceGameBigRate())
		    {
                dialog.text = "Я слышал, что Вы очень хорошо играете. Я не буду играть с Вами по таким большим ставкам.";
                link.l1 = "Давайте по более низким ставкам?";
			    link.l1.go = "Dice_Node_100";
				link.l2 = "Извините, мне пора.";
			    link.l2.go = "exit";
			    break;
		    }

			if (sti(pchar.Money) < 15000)
		    {
                dialog.text = "Изволите шутить, " + GetAddress_Form(NPChar) + "? У вас нет 15000 песо!";
                link.l1 = "Будут!";
			    link.l1.go = "exit";
			    break;
		    }
		    if (sti(npchar.Money) < 15000)
		    {
                dialog.text = "Прошу меня простить, но нет. Такие ставки не доведут до добра мой кошелёк.";
                link.l1 = "Как угодно.";
			    link.l1.go = "exit";
			    break;
		    }
   			dialog.text = "Хорошо, играем по 2000 монет за кубик.";
			link.l1 = "Начали!";
			link.l1.go = "Dice_begin_go";
			pchar.GenQuest.Dice.npcharIdx = npchar.index;
            pchar.GenQuest.Dice.iRate     = 2000;
            pchar.GenQuest.Dice.SitType   = false;
		break;

		case "Dice_begin_go":
            SetNPCQuestDate(npchar, "Dice_date_begin");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
            LaunchDiceGame();
		break;
	    // кости <--

	// игры <--

//  Торговля -->
case "Trade_1":
		//корабль где?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("А где Ваш корабль, капитан? Он у Вас вообще есть?", "Сначала кораблем обзаведитесь, а потом только что-то предлагайте...");
link.l1 = RandPhraseSimple("Не извольте беспокоиться, миледи, скоро у меня будет корабль!", "Ой, это временное недоразумение... Не волнуйтесь.");
			link.l1.go = "exit";
			break;
			}
			dialog.text = "Почему бы и нет, уважаемый. Честная торговля еще никого не разоряла.";
			link.l1 = "Пойдёмте смотреть товары.";
			link.l1.go = "Trade_2";
			link.l2 = "Прошу прощения, но я передумал"+ GetSexPhrase("","а") +".";
			link.l2.go = "exit";
		break;
		
		case "Trade_2":
			FillShipStore(NPChar);
	    	pchar.shiptrade.character = NPChar.id;
   			NextDiag.TempNode = "First time";
		    DialogExit();
		    DeleteAttribute(pchar, "PriceList.StoreManIdx"); // не вести лог по кораблям
		    LaunchStore(SHIP_STORE);
		break;

// Торговля <--

//  Бухач -->
			case "buhach":
			DialogExit();
			pchar.questTemp.friend_in_tavern = npchar.id;
			LAi_SetSitType(PChar);
			LAi_ActorSetSitMode(NPChar);
			LAi_ActorDialogDelay(npchar, pchar, "", 1.5);
			NextDiag.CurrentNode = "Andre_Abel_In_Tavern_1"; 
FreeSitLocator("Havana_tavern", "sit_front2");
			FreeSitLocator("Havana_tavern", "sit_base2");
			ChangeCharacterAddressGroup(NPChar, "Havana_tavern", "sit", "sit_front2");
			DoFunctionReloadToLocation("Havana_tavern", "sit", "sit_base2", "Buhach_Havana");
		break;
			
		case "Andre_Abel_In_Tavern_1":
		dialog.text = "Выпить? Отчего ж не выпить в хорошей-то кампании? Присаживайтесь, сударь, опрокинем по кружечке доброго ямайского рому. Это здоровью никогда не повредит. Ну, вздрогнем!";
link.l1 = "Вздрогнем!";
link.l1.go = "buhalovo_1";
break;
			case "buhalovo_1":
			dialog.text = "За архипелаг!";
			link.l1 = "За архипелаг!";
			link.l1.go = "buhalovo_2";
			break;

			case "buhalovo_2":
			Statistic_AddValue(pchar, "TavernDrink", 1);
			AddMoneyToCharacter(pchar, -2);
			//navy --> Alcohol - rum count;
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
			//<-- navy
			WaitDate("",0,0,0, 0, 30);
			
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
			
			
			dialog.text = LinkRandPhrase("Ик! А ты славный малый, кэп! Давай за знакомство!",
										 "Ик! Какой ром! Ну... вздрогнем!",
										 "За море и свободу!");
			link.l1 = "Эх, забористый ром. Ладно, мне уже пора, удачно посидеть.";
			link.l1.go = "exit_sit";
			if (makeint(pchar.money) >=2)
			{
				link.l2 = "Давайте еще по одной кружечке.";
				link.l2.go = "buhalovo_1";

			}
			link.l4 = LinkRandPhrase("Кажется, что провел"+ GetSexPhrase("","а") +" в море целую вечность. Рассскажите что-нибудь интересное, капитан?",
									"Расскажите мне, сударь, о Ваших похождениях... Если Вас не затруднит, конечно... Ик!",
									"Вы бывалый морской волк, сударь, и наверняка у Вас в запасе есть много интересных историй...");
			link.l4.go = "rumours_pggg";
		break;

// Бухач <--

//  Офицерство -->
case "officer":
		//Проверка на ПИРАТЕС, не было! :) //navy 04.04.07
		if (FindFreeRandomOfficer() < 1)
		{
			Dialog.Text = RandPhraseSimple("Хм... Пожалуй, нет...", "Нет, я капитан, и не хочу быть офицером.");
			link.l1 = RandPhraseSimple("Жаль...", "Значит не судьба.");
			link.l1.go = "exit";
			break;
		}
		if (!CheckAttribute(NPChar, "Quest.Officer.Price"))
		{
			NPChar.Quest.Officer.Price = 10000 + sti(NPChar.rank)*500*MOD_SKILL_ENEMY_RATE - MakeInt(GetSummonSkillFromNameToOld(pchar, SKILL_LEADERSHIP)*1000);
		}
		Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
				RandPhraseSimple("Это - то, что нужно! Наши клинки напьются вражеской крови! Одна проблемка, мне нужно " + NPChar.Quest.Officer.Price + " песо, чтобы расплатиться с долгами.", 
								"Ты выглядишь настоящ"+ GetSexPhrase("им морским волком","ей морской волчицей") +". И если ты готов"+ GetSexPhrase("","а") +" заплатить " + NPChar.Quest.Officer.Price + " песо, то, пожалуй, мы сработаемся."), 
				LinkRandPhrase("Слухи не врут, капитан и Ваше предложение весьма лестно для меня. Я согласна за весьма умеренную плату в размере " + NPChar.Quest.Officer.Price + " песо присоединиться к Вам.", 
							"Хм... Люди правду молвят. Вы выглядите бывал"+ GetSexPhrase("ым","ой") +" моря"+ GetSexPhrase("ком","чкой") +". Возможно, мне стоит принять Ваше предложение, капитан, если вы согласны заплатить мне " + NPChar.Quest.Officer.Price + " песо.", 
							"У Вас достоверная информация, капитан. Мне довелось побывать во множестве всяких передряг. Я думаю, что с Вами сработаемся. Всего " + NPChar.Quest.Officer.Price + " песо и мы ударим по рукам."));

		MakeRandomLinkOrderTwo(link, PCharRepPhrase(RandSwear() + RandPhraseSimple("Меня это устраивает. Но, надеюсь, Вы не будете каждый день требовать столько.", "Это чертовски дорого, но, думаю, Вы того стоите."), 
				LinkRandPhrase("Я соглас"+ GetSexPhrase("ен","на") +". Считайте себя зачисленным в команду.", "Хм... Пожалуй, я готов"+ GetSexPhrase("","а") +" расстаться с этой суммой.", "Похоже, Вы стоите этих денег. По рукам!")), "officer_hired",
									PCharRepPhrase(RandSwear() + RandPhraseSimple("Вы не стоите столько. Удачи...", "Это чертовски дорого, я не готов"+ GetSexPhrase("","а") +" выкидывать столько денег."), 
				LinkRandPhrase("Мда... Жадность не порок...", "Вы смеётесь надо мной? За такие деньги я могу купить десяток таких, как Вы.", "Это грабеж... Где я возьму Вам такую сумму?")), "exit");
		link.l3 = "Хм... А что Вы представляете из себя?";
		link.l3.go = "Exit_ShowParam";
		break;

	case "officer_hired":
		if (sti(pchar.money) < sti(NPChar.Quest.Officer.Price))
		{
			Dialog.Text = "Похоже, у Вас проблемы с наличностью, капитан.";
			link.l1 = "Ах... действительно.";
			link.l1.go = "exit";
			break;
		}
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
		AddDialogExitQuestFunction("PGG_BecomeHiredOfficer_1");
		
		DeleteAttribute(NPChar, "Quest.Officer");
		DeleteAttribute(NPChar, "PGGAi.Task");
		DeleteAttribute(NPChar, "PGGAi.LockService");

		Dialog.Text = RandPhraseSimple("Вот и отлично!", "Я не сомневалась в Вас, капитан.");
		link.l1 = "Не опаздывайте к отплытию.";
		link.l1.go = "exit";
		break;
// Офицерство <--

//  Эскадра -->

case "companion":
		Dialog.Text = "Если вы читаете это, значит, вы поймали баг ;) Сообщите об этом Navy, подробно, как вы его поймали :)";
		link.l1 = "Обязательно!!!!";
		link.l1.go = "exit";
		//раз в день.
		if (CheckAttribute(NPChar, "Companion_Talk") && GetNpcQuestPastDayParam(NPChar, "Companion_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("Я уже высказала Вам своё мнение на этот счёт, уважаемый.", "Мне казалось, что мы все обсудили.");
			link.l1 = RandPhraseSimple("Как я мог"+ GetSexPhrase("","ла") +" забыть?!", "И правда. Удачи!");
			link.l1.go = "exit";
			break;
		}
		//корабль где?
		if (pchar.Ship.Type == SHIP_NOTUSED)
		{
			Dialog.Text = RandPhraseSimple("А где Ваш корабль, капитан? Он у Вас вообще есть?", "Сначала кораблем обзаведитесь, а потом только что-то предлагайте...");
link.l1 = RandPhraseSimple("Не извольте беспокоиться, миледи, скоро у меня будет корабль!", "Ой, это временное недоразумение... Не волнуйтесь.");
			link.l1.go = "exit";
			break;
		}
		//разница в рангах... нефиг халявить
		if (sti(NPChar.rank) > sti(Pchar.rank)+10)
		{
			Dialog.Text = RandPhraseSimple("Плавать с Вами? Вам бы подрасти сначала, уважаемый.", "Не думаю, что мне это интересно.");
link.l1 = RandPhraseSimple("Ну, как хотите...", "Что ж, счастливо оставаться.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//есть ли место для компаньона
		if (GetCompanionQuantity(pchar) > 7)
		{
			Dialog.Text = RandPhraseSimple("Похоже, что Вам уже достаточно компаньонов.", "У Вас и так много кораблей. Зачем Вам еще один?");
			link.l1 = "Да... Может Вы и правы.";
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
break;
		}
		if (SetCompanionIndex(pchar, -1, sti(NPChar.index)) != -1)
		{
			Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
					RandPhraseSimple("Вы мне нравитесь! По рукам! Я уже слышу звон песо в наших карманах!", "А Вы, "+ GetSexPhrase("капитан","капитан") +", не промах... Думаю, мы сработаемся!"), 
					LinkRandPhrase("Ваше предложение мне нравится. Я согласен.", 
					"Это интересно. Я тоже думаю, что вместе мы сможем больше!", "Пожалуй, это будет занятно. По рукам!"));
			link.l1 = RandPhraseSimple("Отлично, жду Вас в море!", "По рукам! Мы будем отличной командой.");
			link.l1.go = "exit_company";
			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
            	NPChar.Payment = true;
                
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			SetCharacterRemovable(NPChar, true);
			SaveCurrentNpcQuestDateParam(NPChar, "Companion.CheckRelation");
		}
		else
		{
			Dialog.Text = RandPhraseSimple("Похоже, тебе уже достаточно компаньонов.", "У тебя и так много кораблей. Зачем тебе еще один?");
			link.l1 = "Да... Может ты и прав.";
			link.l1.go = "exit";
		}
		break;
// Эскадра <--

//  Дуэлька -->
case "duel":
Dialog.Text = "Что? Как Вы смеете? Вы разговариваете с дамой! Немедленно возьмите свои слова назад!";
		link.l1 = "Я не намерен выбирать выражения, разговаривая с отребьем!";
		link.l1.go = "duel_1";		
		link.l2 = "Произошла ошибка. Я обознался. Прошу прощения...";
		link.l2.go = "peace";
		break;

case "duel_1":
Dialog.Text = "Я советую Вам остановиться, сударь, и я надеюсь, что Вы немедленно принесете свои извинения, или я за себя не ручаюсь!";
		link.l1 = "За меня будет говорить мой клинок.";
		link.l1.go = "duel_2";		
		link.l2 = "Ах! Кажется, мой корабль уже отплывает...";
		link.l2.go = "peace_1";
		break;

case "duel_2":
Dialog.Text = "Ах, так! Пути назад нет. Вы задели мою честь, милейший, за это Вам придётся заплатить! Я вызываю вас на дуэль!";
		link.l1 = "Я всегда к вашим услугам, сударыня!";
		link.l1.go = "duel_vibor";
		break;

case "duel_vibor":
Dialog.Text = "Отлично! Я, пожалуй, проявлю благодродство и позволю Вам выбрать как именнно и где Вы умрёте! Избирайте сами свою участь, милейший!";
		link.l1 = "Будем биться на шпагах и пистолетах! Здесь и сейчас! Доставайте свой клинок!";
		link.l1.go = "duel_land";
		link.l2 = "Будём биться на море! Мой корабль пустит ко дну Ваше старое корыто!";
		link.l2.go = "duel_sea";
		break;

case "duel_sea":
		Dialog.Text = "Ну, нет. Не уйдёшь, каналья! Я тебя собственными руками прибью!";
		link.l1 = "Если Вы так торопитесь умереть, то я к Вашим услугам!";
		link.l1.go = "duel_otskok";
		if (pchar.location.from_sea == GetCurrentTown() + "_town")
		{
			Dialog.Text = "Что ж, жду Вас на рейде...";
			link.l1 = "С нетерпением жду нашей встречи.";
			link.l1.go = "duel_smert";
			pchar.questTemp.Duel.enemy = NPChar.id;
			pchar.questTemp.Duel.Sea_Location = Islands[GetCharacterCurrentIsland(PChar)].id;
	AddDialogExitQuestFunction("Duel_Sea_Prepare");
		}
		break;

case "duel_sea_pgg":
Dialog.Text = "Клянусь, ты заплатишь за это своей жизнью, мерзацец!";
link.l1 = "Ну-ну...";
link.l1.go = "Exit_Quest_1_FailedFight";
pchar.questTemp.Duel.enemy = NPChar.id;
pchar.questTemp.Duel.Sea_Location = Islands[GetCharacterCurrentIsland(PChar)].id;
AddDialogExitQuestFunction("Duel_Sea_Prepare");
break;

case "duel_otskok":
Dialog.Text = "Мерзавец! Доставай свой клинок, и мы посмотрим, какого цвета твоя кровь!";
		link.l1 = "Ну, если ты так хочешь умереть...";
		link.l1.go = "fight_right_now";
		break;

case "duel_smert":
Dialog.Text = "Искренне надеюсь, что Вы сегодня умрёте!";
		link.l1 = "Взаимно...";
		link.l1.go = "exit_duel";
		break;

case "duel_land":
Dialog.Text = "Отлично! Я рад, что прикончу тебя своими руками, мерзавец! Защищайся!";
		link.l1 = "Я помогу тебе отправиться в ад!";
		link.l1.go = "fight_right_now";
		break;

	//дуэли быть!
	case "fight_right_now":
		PChar.questTemp.duel.enemy = NPChar.id;
		AddDialogExitQuestFunction("Duel_Prepare_Fight");
		NextDiag.CurrentNode = NextDiag.TempNode;
		ChangeCharacterComplexReputation(pchar, "nobility", -3);
		DialogExit();
		break;

case "peace":
Dialog.Text = "В таком случае, не смею Вас больше задерживать!";
		link.l1 = "Ещё раз прошу прощения...";
		link.l1.go = "exit";		
		break;

case "peace_1":
Dialog.Text = "Тогда Вам лучше уйти, пока я не передумала.";
		link.l1 = "Уже ухожу...";
		link.l1.go = "exit";		
		break;

// Дуэлька <--

		//замечание по обнаженному оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			link.l1.go = "exit";
		break;


//  Приказы для компаньона -->			
			case "Companion_Tasks":
			dialog.Text = "Внимательно слушаю.";
			Link.l1 = "Это касается абордажа.";
			Link.l1.go = "Companion_TaskBoarding";
			Link.l2 = "Это касается твоего корабля.";
			Link.l2.go = "Companion_TaskChange";
			Link.l3 = "Пока ничего.";
			Link.l3.go = "exit_company";
			break;

		case "Companion_TaskBoarding":
			dialog.Text = "Что же вы желаете?";
			Link.l1 = "Я хочу чтобы ты не брала корабли на абордаж. Побереги себя и свою команду.";
			Link.l1.go = "Companion_TaskBoardingNo";
			Link.l2 = "Мне нужно чтобы ты брала вражеские корабли на абордаж.";
			Link.l2.go = "Companion_TaskBoardingYes";
		break;
		
		case "Companion_TaskChange":
			dialog.Text = "Что же вы желаете?";
			Link.l1 = "Я хочу чтобы ты не меняла свой корабль после абордажа. Он слишком ценен.";
			Link.l1.go = "Companion_TaskChangeNo";
			Link.l2 = "Когда будешь брать врагов на абордаж, посмотри, вдруг кораблик приличный будет, тогда бери себе.";
			Link.l2.go = "Companion_TaskChangeYes";
		break;
		
		case "Companion_TaskBoardingNo":
			dialog.Text = "Так точно.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = false;
		break;
		
		case "Companion_TaskBoardingYes":
			dialog.Text = "Будет исполнено.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanBoarding = true;
		break;
		
		case "Companion_TaskChangeNo":
			dialog.Text = "Так точно.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = false;
		break;
		
		case "Companion_TaskChangeYes":
			dialog.Text = "Будет исполнено.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NPChar.Tasks.CanChangeShipAfterBoarding = true;
		break;
// Приказы для компаньона  <--

//  Приказы -->	

case "exit_2":
dialog.Text = "К Вашим услугам, капитан!";
Link.l1 = "Слушай мою команду!";
Link.l1.go = "prikaz";
if (CheckAttribute(NPChar, "IsCompanionClone"))
			{
	dialog.text = "Что вы хотите, капитан?";
	Link.l1 = "У меня есть для тебя несколько приказов.";
	Link.l1.go = "Companion_Tasks";
			}
	if (IsCompanion(NPChar))
			{
	dialog.Text = "Скоро мы снова мыйдем в море!";
	Link.l1 = "Да, я тоже рад.";
	Link.l1.go = "exit_company";
			}
		break;

case "prikaz":
dialog.Text = "Чем могу быть полезна, капитан?";
if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l1 = ""+npchar.name+", я собираюсь отправиться в старый индейский город Тайясаль. Не буду скрывать: это крайне опасное путешествие, и более того - необычное: через телепортационный истукан. Ты готов последовать за своим капитаном?";
				Link.l1.go = "tieyasal";
			}
			
			if (isOfficer(Npchar)) // проверка для кампуса, где слотовые офы
			{
				Link.l2 = "Слушай мой приказ!";
				Link.l2.go = "stay_follow";
				Link.l4 = RandPhraseSimple("Девушка-телохранитель - это, конечно, хорошо, но может мы попытаемся сталь ближе?",
	                                           "Как насчет неуставных услуг?");
	              Link.l4.go = "Love_Sex";
			}

           		// boal отчет о корабле
			if(CheckAttribute(NPChar, "treasurer") && NPChar.treasurer == 1)
			{
			    Link.l3 = "Дай мне полный отчет о корабле, " + GetStrSmallRegister(XI_ConvertString("treasurer")) + ".";
			    Link.l3.go = "QMASTER_1";
			        
			    // Warship. Автозакупка товара
			    if(!CheckAttribute(PChar, "TransferGoods.Enable"))
			    {
				    Link.l11 = "Я хочу, чтобы, во время стоянки в колонии, ты закупала товары.";
				    Link.l11.go = "TransferGoodsEnable";
			    }
			    else
			    {
				    Link.l11 = "Знаешь, закупать товары в колониях не нужно.";
				    Link.l11.go = "TransferGoodsDisable";
			    }
			}
			
			if (pchar.location != "My_Campus") // patch-5
			{
			Link.l5 = "Офицер, я более не нуждаюсь в ваших услугах.";
			Link.l5.go = "AsYouWish";
			}
			
			
			// по тек локации определим можно ли тут приказать  -->
			if(IsEntity(loadedLocation))
			{
				if(CheckAttribute(loadedLocation, "fastreload"))
				{
					iTemp = FindColony(loadedLocation.fastreload);
					if(iTemp != -1)
					{
						sld = GetColonyByIndex(iTemp);
						if(sti(sld.HeroOwn) == true && !CheckAttribute(sld, "OfficerIdx"))
						{
							NPChar.ColonyIdx = iTemp;
							Link.l6 = "Я назначаю тебя наместником этого города!";
							Link.l6.go = "Gover_Hire";
						}
					}
				}
			}
			
			Link.l7 = "Ничего. Вольно.";
			Link.l7.go = "exit_company";
		break;
		
		// Тайясаль
		case "tieyasal":
			dialog.text = LinkRandPhrase("Простите, кэп, но на такое я не подписывалась. Не сочтите за трусость, но идти на верную смерть я не собираюсь. Знаете ли, еще пожить охота. Можете меня уволить.","Капитан, прошу меня простить, но - нет. Море, абордаж, вражеские города - все что угодно, но с индейской нечистью я связываться не желаю. Если вас мой ответ огорчил - давайте расторгнем наш контракт.","Вы просите невозможного, капитан, и сами это знаете. Из этого похода никто не вернется. Думаю, что даже вы. Так что я - пас. Если считаете, что я отказом нарушаю условия контракта - списывайте меня на берег.");
			link.l1 = LinkRandPhrase("У меня нет к тебе претензий, офицер. Я все понимаю.","Жаль, конечно, но я все понимаю. Поэтому и предупредил.","Я надеялся на тебя... Но возражения принимаются, офицер.");
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			DialogExit();
			npchar.quest.Tieyasal = "true";
		break;
		
		case "TransferGoodsEnable":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
	        {
				dialog.text = "Капитан, какие товары?! Нужно сначала корабль где-нибудь раздобыть!";
				Link.l1 = "Да, ты права.";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
	        }
	        	
			PChar.TransferGoods.Enable = true;
		//	PChar.TransferGoods.TreasurerID = NPChar.id;
			Dialog.text = "Будет исполнено, "+ GetSexPhrase("господин","госпожа") +" капитан!";
			Link.l1 = "Вольно.";
			Link.l1.go = "TransferGoodsEnable_2";
        break;
        	
		case "TransferGoodsEnable_2":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
			LaunchTransferGoodsScreen(); // Интерфейс автозакупки товаров
		break;
		
		case "TransferGoodsDisable":
			DeleteAttribute(PChar, "TransferGoods.Enable");
			Dialog.text = "Будет исполнено, "+ GetSexPhrase("господин","госпожа") +" капитан.";
			Link.l1 = "Вольно.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;


case "QMASTER_1":
			if(sti(PChar.Ship.Type) == SHIP_NOTUSED)
			{
				dialog.text = "Капитан, но у нас ведь нет корабля!";
				Link.l1 = "Спасибо, напомнила...";
				Link.l1.go = "exit_company";
				NextDiag.CurrentNode = "exit_2";
				break;
			}
			
			dialog.text = "Максимальная активность крыс в рейсе " +
			FloatToString(50.0 / (2.0+GetSummonSkillFromNameToOld(PChar, SKILL_REPAIR) + GetSummonSkillFromNameToOld(PChar,SKILL_SNEAK)), 1) +
			"% от количества груза. На "+GetCrewQuantity(PChar) + " матросов нужно " + makeint((GetCrewQuantity(PChar)+6) / 10) + " провианта в день. Это без учета перевозимых рабов.";
			Link.l1 = "Спасибо.";
			Link.l1.go = "exit_company";
			NextDiag.CurrentNode = "exit_2";
		break;
        
        // boal 05.09.03 offecer need to go to abordage -->
        case "stay_follow":
            dialog.text = "Какие будут приказания?";
            Link.l1 = "Стой здесь!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "Следуй за мной и не отставай!";
            Link.l2.go = "Boal_Follow";
            // boal 05.09.03 offecer need to go to abordage <--
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l3 = "Я хочу, чтобы ты держалась на определенном расстоянии от цели.";
				Link.l3.go = "TargetDistance";
			}
			
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l4 = "Нужно изменить тип боеприпаса для твоего огнестрельного оружия.";
					Link.l4.go = "SetGunBullets";
				}	
			}						
		break;

		case "SetGunBullets":
			Dialog.Text = "Выбор типа боеприпаса :";
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
			NextDiag.CurrentNode = "exit_2";
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
		case "TargetDistance":
			dialog.text = "На каком именно, капитан? Укажите в метрах, но не более 20-ти.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "Капитан, что за дурной тон!";
				link.l1 = "Извини, ошибочка вышла...";
				link.l1.go = "exit_company";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "Я буду стоять на месте, никуда не двигаясь. Вас это устраивает, капитан?";
				link.l1 = "Да, именно это от тебя и требуется.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "Я кажется говорила, что более 20 метров от цели мне держаться нельзя.";
				link.l1 = "Хорошо, держись на расстоянии в 20 метров.";
				link.l1.go = "exit_company";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "Задачу поняла, принимаю к сведению.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit_company";
			npchar.MusketerDistance = iTemp;
		break;

		case "AsYouWish":
			// проверка на море -->
			if (bSeaActive)
			{
				attr = Sea_FindNearColony();
				if (attr == "none")
				{
					dialog.text = "Капитан, хоть мне и непонятна причина такого заявления - давайте вернёмся к этому вопросу на берегу. Или вы решили просто выбросить меня за борт?";
					Link.l1 = "Хм... нет, я не это имел"+ GetSexPhrase("","а") +" в виду. Оставайся, пока не придём в порт.";
					Link.l1.go = "exit_company";	
					break;	
				}
			}
			// проверка на море <--
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) < 41) //герой против злодея
			{
				dialog.text = RandPhraseSimple(LinkRandPhrase("Вот это новость!","С какой это радости?!","С чего это вдруг?!"), RandPhraseSimple("Капитан, вы в своём уме? Сообщать такие новости ни с того, ни с сего!","Ого! И чем это я вам не угодила?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Я решил"+ GetSexPhrase("","а") +" навести порядок в эскадре. И, поскольку мне не нравятся твои взаимоотношения с коллегами,","Твои достоинства оказались не так хороши, как расписывалось при найме, поэтому","Головорезов и проходимцев в моей команде не будет! Поэтому"), LinkRandPhrase("Мне стало известно, что ты тайком таскаешь ром и спаиваешь команду, тем самым ослабляя её боевой дух. Поэтому","Мне чертовски надоели твои разбойничьи замашки, я не намерен"+ GetSexPhrase("","а") +" терпеть их бесконечно. Так что,","Ты постоянно проводишь время в кают-компании за игрой в карты или кости, отвлекая других офицеров от несения службы. Это не может продолжаться бесконечно, поэтому")) + " собирайся и покинь судно.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A1_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A1_strife";
				}
				break;	
			}
			if (makeint(PChar.reputation.nobility) >= 41 && makeint(NPChar.reputation) >= 41) // герой против героя
			{
				dialog.text = RandPhraseSimple(RandPhraseSimple("Могу я узнать причины такого решения?","Наверняка такое решение имеет веские причины?"), RandPhraseSimple("Прошу объясниться, капитан","Весьма неожиданно. Но хотелось бы знать основания."));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Меня категорически не устраивает твоё отношение к своим обязанностям.","К сожалению, из тебя не вышло толкового офицера, и наверное уже не выйдет...","Ты хороший офицер, и исправно несла службу, но здесь наши пути расходятся. И не спрашивай меня почему."), LinkRandPhrase("Я предупреждал"+ GetSexPhrase("","а") +", что страсть к рому тебя погубит. Как я могу довериться в бою человеку, который саблей в ножны попасть не может?","Моряка из тебя, скажем прямо, не вышло... Думаю, на берегу ты добьешься большего.","Меня давно не устраивает твоя квалификация, но сейчас я наконец-то наш"+ GetSexPhrase("ел","ла") +" достойную замену."));
				Link.l1.go = "Get_out_A2";
				break;	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) >= 41) // злодей против героя 
			{		
				dialog.text = RandPhraseSimple(RandPhraseSimple("Хм. Могу я узнать причины?","Это серьёзное заявление. Могу я узнать, что конкретно вас не устраивает?"), RandPhraseSimple("Прошу объясниться, капитан.","Надеюсь, у такого заявления имеются веские основания?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Меня совершенно не устраивает твоя квалификация, поэтому","К сожалению, из тебя не вышло толкового офицера. Так что,","Мне чертовски надоели твои благородные порывы. Я не намерен"+ GetSexPhrase("","а") +" терпеть их бесконечно, так что,"), LinkRandPhrase("До меня дошли слухи, что именно ты подбиваешь команду к неповиновению. Беспорядков на моём судне не будет! И не нужно благодарить, что я раньше не вышвырнул"+ GetSexPhrase("","а") +" тебя за борт... Так что,","Твои благородные принципы делают тебе честь, но они идут вразрез с разбойной жизнью вольного капера. Так что,","Меня категорически не устраивает твоё отношение к своим обязанностям. Поэтому")) + " собирайся и покинь судно.";
				if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
				{
					Link.l1.go = "Get_out_A3_peace";
				}
				else
				{
					Link.l1.go = "Get_out_A3_strife";
				}	
				break;
	
			}
			if (makeint(PChar.reputation.nobility) < 41 && makeint(NPChar.reputation) < 41) // злодей против злодея
			{	
				dialog.text = RandPhraseSimple(LinkRandPhrase("Капитан, я никак не ожидал такого поворота! Может объясните, что произошло?","Капитан, что за муха вас укусила?!","Как прикажете это понимать, капитан?!"), RandPhraseSimple("Как же так, капитан?! Ещё утром всё было нормально, а тут - на тебе...","Ого! Думаю, вы найдёте пару слов для объяснения?"));
				Link.l1 = RandPhraseSimple(LinkRandPhrase("Ты редкостная дура - тебе бы дома сидеть и вышивать. Я и так слишком долго терпел"+ GetSexPhrase("","а") +". Так что,","Ты давно меня не устраиваешь, но сейчас я наконец-то наш"+ GetSexPhrase("ел","ла") +" достойную замену. Так что,","Мне стало известно, что ты тайком таскаешь ром и спаиваешь команду, тем самым ослабляя её боевой дух. Поэтому"), LinkRandPhrase("При найме ты распиналась, что лучшего офицера не найти на всём флоте, а на поверку оказалась обыкновенной дурой, так что","Я предупреждал"+ GetSexPhrase("","а") +", что твоё пьянство плохо кончится. Почему я долж"+ GetSexPhrase("ен","на") +" всё за тебя делать сам"+ GetSexPhrase("","а") +"? Так что,","Вместо несения службы, ты постоянно торчишь в кают-компании за игрой в карты или кости. Надеюсь, ты не думала, что так может продолжаться бесконечно? Так что,")) + " собирайся и проваливай.";
				Link.l1.go = "Get_out_A4";
				break;
			}
		break;
	
		case "Get_out_A1_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Вот значит как! Ну ладно, воля ваша. Но учтите: к вам я больше не вернусь. Ещё просить будете...","Признаться, ваши игры в благородство мне тоже как-то не по душе. Так что - прощайте...", "Ну и чёрт с вами! Оставайтесь со своими лизоблюдами. Тоже мне - 'герой'!"), LinkRandPhrase("Да мне у вас никогда и не нравилось, не судно, а грузовая баржа. Развели благородный пансион...","Да меня самого с души воротит от таких сослуживцев. В кают-компанию хоть не заходи, как на подбор - одни маменькины сынки...","Хорошо, капитан, будь по-вашему. Но, видит Бог, у меня за кормой чисто..."));
			Link.l1 = "Стой. Сейчас я не могу оставить судно без офицера. Но позднее мы ещё вернемся к этому разговору.";
			Link.l1.go = "exit_bad";
			Link.l2 = "Вот и ступай с Богом.";
			Link.l2.go = "Exit_Fire_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Не кипятись. Я приготовил"+ GetSexPhrase("","а") +" тебе выходное пособие "+sti(NPChar.rank)*500+" песо. Надеюсь, это снимет все вопросы.";
				Link.l3.go = "Get_out_А1_ForMoney";
			}
		break;

		case "Get_out_A1_strife":
			dialog.text = LinkRandPhrase("Позвольте! Что значит 'покинь судно'?! Не для того я свою голову под картечь подставляла, чтоб вы могли меня вышвырнуть, когда вздумается!", "Ха! 'покинь судно'! Вы думаете, я позволю вышвырнуть себя, как котёнка?!", "Полегче, капитан, в серьёзной компании так дела не решаются. Я не позволю обращаться с собой, как с салагой.");
			Link.l1 = "Хорошо, оставайся. Но лишь пока я не найду достойную замену." ;
			Link.l1.go = "exit_bad";
			Link.l2 = "Я повторяю - твоя служба закончена. Можешь собирать вещи.";
			Link.l2.go = "Get_out_A1_strife_1";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Не кипятись. Я приготовил"+ GetSexPhrase("","а") +" тебе выходное пособие "+sti(NPChar.rank)*500+" песо. Надеюсь, это снимет все вопросы.";
				Link.l3.go = "Get_out_А1_ForMoney";
			}
		break;

		case "Get_out_A1_strife_1":
			dialog.text = RandPhraseSimple("Да я и не горю желанием у вас задерживаться. Только без компенсации покидать судно не собираюсь!", "Да я теперь и сама не останусь на вашем корыте. Только извольте сначала выплатить компенсацию!") + " "+sti(NPChar.rank)*1000+" песо, и мы забудем друг о друге.";
			Link.l1 = "Я погорячил"+ GetSexPhrase("ся","ась") +"... Прими мои извинения, и возвращайся на пост.";
			Link.l1.go = "exit_bad1";
			Link.l2 = "О каких деньгах может идти речь, если ты регулярно получал свою долю? Всё это изрядно смахивает на вымогательство!";
			Link.l2.go = "Get_out_А1_strife_battle";
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l3 = "Ладно. Сдай экипировку и получишь то, о чём просишь.";
				Link.l3.go = "Get_out_А1_chang";
			}
		break;

		case "Get_out_А1_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "Ну, это совсем другое дело. Прощайте!";
			Link.l1 = "Надеюсь, наши дороги больше не пересекутся.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_А1_strife_battle":
			dialog.text = LinkRandPhrase("Считайте это компенсацией моральных издержек. Я никому не позволю так с собой обращаться! А кто посмеет, тот очень пожалеет об этом!", "Это не вымогательство, а компенсация бездарно потраченного времени! И я её получу, чего бы мне это ни стоило!", "Я потратила слишком много времени на службу у так"+ GetSexPhrase("ого чистоплюя","ую чистоплюйку") +" как вы. За это время можно было озолотиться грабежом торговцев. Теперь хочу компенсировать упущенную выгоду.");
			if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
			{
				Link.l1 = "Ладно. Вот твои деньги... А теперь убирайся отсюда!";
				Link.l1.go = "Get_out_А1_ForMoney_angry";
			}
			Link.l2 = "Ты забываешься! Я не позволю всяким дурам повышать на себя голос!";
			Link.l2.go = "Get_out_А1_strife_death";
		break;

		case "Get_out_А1_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("good");
			dialog.text = "Давай-давай, капитан! Покажи, каков"+ GetSexPhrase("","а") +" ты против серьёзного соперника!";
			Link.l1 = "Видит Бог, я этого не хотел"+ GetSexPhrase("","а") +"!";
			Link.l1.go = "Get_out_fight";
		break;
	
		case "Get_out_А1_ForMoney_angry":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			OfficersReaction("bad");
			dialog.text = "Ну, это совсем другое дело. Прощайте!";
			Link.l1 = "Надеюсь, наши дороги больше не пересекутся.";
			Link.l1.go = "Exit_Fire_1";
		break;

		case "Get_out_A2":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Ну что ж, значит не судьба. Прощайте, капитан, не поминайте лихом...","Очень жаль, капитан. Но, видит Бог, я старалась. Прощайте.","Ну, капитан, вам не угодишь!.. Счастливо оставаться."), LinkRandPhrase("Жаль, капитан. Мне очень нравилось служить у вас.","Вот ведь как бывает... Но я зла не держу, прощайте.","Вы несправедливы ко мне, капитан. Но я уважаю ваше решение. Прощайте."));
			Link.l1 = "Стой, я передумал"+ GetSexPhrase("","а") +". Давай вернём к этому разговору позже.";
			Link.l1.go = "exit_good";
			Link.l2 = "Не огорчайся. Удачи тебе...";
			Link.l2.go = "exit_fire_2";
			Link.l3 = "Постой... Я тебя неплохо экипировал"+ GetSexPhrase("","а") +". Нужно бы вернуть вещички - мне вон какую ораву снаряжать нужно...";
			Link.l3.go = "Return_items_A2";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l4 = "Постой... Не хочу отпускать тебя с пустыми руками. Вот держи "+sti(NPChar.rank)*500+" песо, пригодятся, пока будешь искать новую работу.";
			}
			Link.l4.go = "Im_kind_A2";
		break;

		case "Return_items_A2":
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "Да о чём речь, конечно забирайте...";
			Link.l1 = "Я знал"+ GetSexPhrase("","а") +", что ты меня правильно поймёшь...";
			Link.l1.go = "Get_out_А2_chang";
		break;

		case "Im_kind_A2":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeOfficersLoyality("good_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			dialog.text = "Спасибо вам, капитан! Какая неожиданная щедрость. У меня тут осталось кое-что из ваших вещей, может желаете их вернуть?";
			Link.l1 = "Да пожалуй... Сейчас найти хороший клинок ой как непросто...";
			Link.l1.go = "Get_out_А2_chang";
			Link.l2 = "Не нужно. Оставь себе в память о службе под моим началом...";
			Link.l2.go = "exit_fire_2";
		break;

		case "Get_out_A3_peace":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Ну что ж, воля ваша. Но учтите: к вам я больше не вернусь, даже если придётся помирать с голоду.","Признаться, ваши бандитские замашки мне тоже не по душе. Так что, это рано или поздно должно было случиться... И не нужно выдумывать никаких причин.","Ну и оставайтесь со своими головорезами. На вашем судне приличному человеку в кают-компанию зайти стыдно. Развели бордель, прости меня Господи!"), LinkRandPhrase("Признаться, у меня тоже душа не лежит к такой службе. Набрали в команду одних проходимцев - не с кем добрым словом обмолвиться.","Да, если вы будете так относиться к личному составу - от вас все сами разбегутся. Никаких причин выдумывать не придётся.","Меня утешает то, что наша неприязнь взаимна. Счастливо оставаться."));
			Link.l1 = "Стой. Сейчас не самый удачный момент тебя списывать. Но все претензии остаются в силе.";
			Link.l1.go = "exit_bad";
			Link.l2 = "Иди-иди. Обойдусь без твоих нравоучений.";
			Link.l2.go = "exit_fire_3";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Подожди. Дам тебе на дорогу "+sti(NPChar.rank)*500+" песо. А то помрёшь под забором, а мне потом перед Богом отвечать.";
				Link.l3.go = "Get_out_А3_ForMoney";
			}
		break;

		case "Get_out_А3_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("И на том спасибо. Прощайте...", "Благодарю за понимание. Счастливо оставаться.", "Вот теперь мы в расчёте. Всего хорошего...");
			Link.l1 = "Я знал"+ GetSexPhrase("","а") +", что ты меня правильно поймёшь...";
			Link.l1.go = "exit_fire_3";
		break;
	
		case "Get_out_A3_strife":
			dialog.text = LinkRandPhrase("Но, капитан, при таком раскладе я остаюсь совсем на мели. Вы же не хотите отправить меня с корабля прямо на паперть?", "Вы несправедливы ко мне, капитан. Но я готов забыть обиду, если получу достойную компенсацию.", "И это ваша благодарность за все мои боевые ранения? Думаю, без денежной компенсации тут не обойтись.");
			Link.l1 = "Ладно, я передумал"+ GetSexPhrase("","а") +". Пока оставайся, но мы ещё вернёмся к этому разговору.";
			Link.l1.go = "exit_bad";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l2 = "Ну, об этом можешь не переживать. Держи "+sti(NPChar.rank)*500+" песо. Думаю, на первое время хватит.";
				Link.l2.go = "Get_out_А3_ForMoney";
				Link.l3 = "Я дам тебе денег. Но, благодаря мне, ты неплохо экипирована - вещички нужно бы вернуть.";
				Link.l3.go = "Return_items_A3";
			}
			Link.l4 = "Ого! А как же регулярно получаемая тобой доля?! Я так и знал"+ GetSexPhrase("","а") +", что всё закончится нытьём и выпрашиванием подачки.";
			Link.l4.go = "Get_out_A3_strife_1";
		break;

		case "Return_items_A3":
			dialog.text = "Я знал, что вы это скажете, но экипировку сможете забрать только, когда я получу "+sti(NPChar.rank)*1000+" песо. Или вам придётся снимать её с трупа.";
			Link.l1 = "Хорошо, держи свои деньги.";
			Link.l1.go = "Get_out_А3_chang";
			Link.l2 = "Да в своём ли ты уме?! Требовать такую сумму за то, что я дал тебе бесплатно! Похоже, такое низкое качество, как жадность, всё-таки одержало верх над твоей напускной благодетелью.";
			Link.l2.go = "Get_out_A3_strife_1";
		break;

		case "Get_out_A3_strife_1":
			dialog.text = "Вы не смеете меня оскорблять! И заставлю уважать себя, даже так"+ GetSexPhrase("ого","ую") +" невежу как вы!";
			Link.l1 = "Если тебе ещё не ясно, то повторю - можешь не клянчить, всё равно ничего не получишь.";
			Link.l1.go = "Get_out_А3_strife_death";
		break;

		case "Get_out_А3_strife_death":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			OfficersReaction("bad");
			dialog.text = "Ну, уж удовлетворение-то я получу в любом случае!!";
			Link.l1 = "Да это вызов! Ну, что ж, как пожелаешь...";
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_A4":
			dialog.text = RandPhraseSimple(LinkRandPhrase("Вот так всегда! Всю душу на службе отдаёшь, а тебе - бац, и без выходного пособия!","Да что ж это за напасть такая?! Не успеешь наняться, как тебя тут же коленкой под зад. Уж и не знаю, кому свечку ставить...","Вот те на! Уже третье увольнение за год - и всё по понедельникам. Этим капитанам хоть на глаза с похмелья не показывайся!"), LinkRandPhrase("Ну ладно, пусть так. Только не приведи Господь нам больше встретиться.","Ну что ж, воля ваша. Но учтите: лучшего офицера вам всё равно не найти.","Хорошо, капитан, будь по-вашему. Но, видит Бог - у меня за кормой чисто..."));
			Link.l1 = "Стой. Сейчас не самый удачный момент тебя списывать. Но все претензии остаются в силе.";
			Link.l1.go = "exit_good";
			Link.l2 = RandPhraseSimple("Топай-топай. И благодари Бога, что я сегодня в хорошем настроении.", "Давай-давай. Всё равно из тебя офицер, как из дерьма пуля.");
			Link.l2.go = "exit_fire_4";
			if (sti(Pchar.money) >= sti(NPChar.rank)*500)
			{
				Link.l3 = "Подожди. Дам тебе на дорогу "+sti(NPChar.rank)*500+" песо. А то помрёшь под забором, а мне потом перед Богом отвечать.";
				Link.l3.go = "Get_out_А4_ForMoney";
			}
			Link.l4 = "Постой... Я тебя неплохо экипировал"+ GetSexPhrase("","а") +" - вещички нужно бы вернуть.";
			Link.l4.go = "Return_items_A4";
		break;

		case "Get_out_А4_ForMoney":
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*500)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			ChangeOfficersLoyality("good_all", 1);
			dialog.text = LinkRandPhrase("Вот спасибо, капитан! Вот так уважили...", "Благодарю за понимание. Счастливо оставаться.", "Вот теперь мы в расчёте. Всего хорошего...");
			Link.l1 = "Счастливо. Только не оставь их все в ближайшей таверне.";
			Link.l1.go = "exit_fire_4";
		break;

		case "Return_items_A4":
			if (makeint(Pchar.Rank) > makeint(NPchar.Rank))
			{
				dialog.text = LinkRandPhrase("Вот теперь ещё и экипировку забираете! Да пропади оно всё пропадом! Ей-богу в содержанки подамся...", "Вижу, вы меня дочиста раздеть решили. Что ж, забирайте. Одна теперь дорога - на паперть...", "Благодарю покорно! Теперь ещё и обчистить решили. Эх, судьбина!.. Забирайте, будь оно всё неладно...");
				Link.l1 = "Давай-давай. Всё равно из тебя офицер, как из дерьма пуля.";
				Link.l1.go = "Get_out_А4_chang_1";
			}
			else	
			{
				dialog.text = RandPhraseSimple("Будь по-вашему, капитан, только сначала выдайте мне "+sti(NPChar.rank)*1000+" песо. Будем считать это компенсацией моральных издержек.", "Хорошо. Только за это я хочу получить "+sti(NPChar.rank)*1000+" песо в качестве компенсации за нелёгкую службу.");
				if (sti(Pchar.money) >= sti(NPChar.rank)*1000)
				{
					Link.l1 = "Вот пройдоха! Ладно, держи свои деньги.";
					Link.l1.go = "Get_out_А4_chang";
				}
				Link.l2 = "Да ты никак рехнулась?! Смеешь просить столько денег за то, что я сам"+ GetSexPhrase("","а") +" же тебе дал"+ GetSexPhrase("","а") +"!";
				Link.l2.go = "Get_out_A4_strife";
				Link.l3 = "Ах-ха! Да я пошутил"+ GetSexPhrase("","а") +"! Разве я могу вышвырнуть старую подругу, как дырявый картуз!";
				Link.l3.go = "exit_bad1";
			}
		break;

		case "Get_out_A4_strife":
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			ChangeOfficersLoyality("bad_all", 1);
			dialog.text = "Ну, тогда ничего и не получите! Я с места не двинусь, пока не услышу, как звенят мои деньги!";
			Link.l1 = RandPhraseSimple("Сейчас ты услышишь, как звенит мой клинок!", "Значит, тебя унесут вперёд ногами!");
			Link.l1.go = "Get_out_fight";
		break;

		case "Get_out_fight":
			CheckForReleaseOfficer(GetCharacterIndex(Npchar.id));
			RemovePassenger(Pchar, Npchar);
			LAi_CharacterDisableDialog(NPChar);
			LAi_SetWarriorType(Npchar);
			LAi_group_MoveCharacter(Npchar, "TmpEnemy");
			LAi_group_SetHearRadius("TmpEnemy", 100.0);
			LAi_group_FightGroupsEx("TmpEnemy", LAI_GROUP_PLAYER, true, Pchar, -1, false, false);
			if (PChar.location == Get_My_Cabin() || findsubstr(PChar.location, "_tavern" , 0) != -1 || findsubstr(PChar.location, "_store" , 0) != -1)
            {
				LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
				LAi_group_SetCheck("TmpEnemy", "CannotFightCurLocation");
				LAi_group_SetCheck("TmpEnemy", "MainHeroFightModeOff");
            }
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

	    case "Get_out_А1_chang": // интерфейс обмена
			NextDiag.CurrentNode =  "Exit_228";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А2_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_2";
			LAi_CharacterDisableDialog(NPChar);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А3_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_3";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А4_chang_1": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

		case "Get_out_А4_chang": // интерфейс обмена
			NextDiag.CurrentNode = "Fired_4";
			LAi_CharacterDisableDialog(NPChar);
			AddMoneyToCharacter(Pchar, -(makeint(sti(NPChar.rank)*1000)));
			ChangeCharacterComplexReputation(pchar,"nobility", 1);
			ChangeCharacterComplexReputation(pchar,"authority", 0.5);
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			NPChar.rank = 0;	
			DialogExit();
			LaunchCharacterItemChange(npchar);
			RemovePassenger(Pchar, npchar);
		break;

	    case "exit_bad":
			Npchar.loyality = makeint(Npchar.loyality) - 3;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_bad1":
			Npchar.loyality = makeint(Npchar.loyality) - 2;
			ChangeOfficersLoyality("bad_all", 1);
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			ChangeCharacterComplexReputation(pchar,"authority", -1);
			NextDiag.CurrentNode = "exit_2";
		
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_good":
			Npchar.loyality = makeint(Npchar.loyality) - 1;
			NextDiag.CurrentNode = "exit_2";
			NPChar.quest.meeting = true;
			DialogExit();
		break;

		case "exit_fire_1":	//navy -->			
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_1";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = "exit_228";
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_2":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_2";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_3":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_3";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_4":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");	
				DialogExit();
				break;
			}	//navy <--		
			NextDiag.CurrentNode = "Fired_4";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "exit_fire_5":	//navy -->		
			if (CheckAttribute(NPChar, "PGGAi"))
			{				
				pchar.questTemp.FiringOfficerIDX = NPChar.index;
				AddDialogExitQuestFunction("PGG_FireOfficer");
				DialogExit();
				break;
			}	//navy <--	
			NextDiag.CurrentNode = "Fired_1";
			OfficersReaction("good");
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex(Npchar.id);
			AddDialogExitQuestFunction("LandEnc_OfficerFired");			
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();	
		break;

		case "Fired_1":
			NextDiag.CurrentNode = "Fired_1";      
			dialog.text = "Ну чего ещё? Мы, кажется, уже всё решили! Ноги моей больше на вашем судне не будет.";
			Link.l1 = RandPhraseSimple("Ступай-ступай. Невелика потеря.", "Иди-иди. Удерживать не стану.");	
			Link.l1.go = "Exit_228";
		break;

		case "Fired_2":
			NextDiag.CurrentNode = "Fired_2"; 
			dialog.text = "Что-то ещё, капитан? Мне казалось, что мы уже всё решили...";
			Link.l1 = "Нет, ничего. Просто попрощаться хотел"+ GetSexPhrase("","а") +"...";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_3":
			NextDiag.CurrentNode = "Fired_3"; 
			dialog.text = "Капитан, все вопросы решены, претензии высказаны. Не хотите же вы после всего этого сказать, что передумали.";
			Link.l1 = "Иди-иди. Невелика потеря.";	 
			Link.l1.go = "Exit_228";
		break;

		case "Fired_4":
			NextDiag.CurrentNode = "Fired_4"; 
			dialog.text = "Капитан, ну какие ещё могут быть вопросы? Я, сказать по совести, очень на вас обижена, и никакого желания возвращаться не имею...";
			Link.l1 = "Иди-иди. Нужен ты мне больно, только палубу пачкала.";	 
			Link.l1.go = "Exit_228";
		break;
		
		// boal 05.09.03 offecer need to go to abordage -->
	    case "Boal_Stay":           //SetCharacterTask_Stay(Characters[Npchar.index]); // it's a mistic but here doesn't work :(
            //Log_SetStringToLog(Npchar.id +" "+Npchar.index);
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "Есть изменить дислокацию!";
		    Link.l1 = "Вольно.";
		    Link.l1.go = "exit_company";
		    Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
	    break;
		
	    case "Boal_Follow":
		    SetCharacterTask_FollowCharacter(Npchar, PChar); // it works here!!!
		    NextDiag.CurrentNode = "exit_2";
		    dialog.text = "Есть изменить дислокацию!";
		    Link.l1 = "Вольно.";
		    Link.l1.go = "exit_company";
	    break;
        // boal 05.09.03 offecer need to go to abordage <--

//////////////////////////////    офицер-наместник -->
		case "Gover_Hire":
            dialog.Text = "Почту за честь!";
            Link.l1 = "Следи за порядком и процветанием города, я буду иногда приплывать за собранной пошлиной.";
			Link.l1.go = "Exit_Gover_Hire";
            Link.l2 = "Я передумал"+ GetSexPhrase("","а") +".";
            Link.l2.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
        break;

        case "Exit_Gover_Hire":
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            attr = sld.id + "_townhall";

            // снимем пассажира -->
			CheckForReleaseOfficer(sti(NPChar.index));
			RemovePassenger(pchar, NPChar);
			// снимем пассажира <--
		    sld.OfficerIdx = sti(NPChar.index);
			ChangeCharacterAddressGroup(NPChar, attr, "sit", "sit1");
			LAi_SetHuberTypeNoGroup(NPChar);
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
            LAi_LoginInCaptureTown(NPChar, true);
			//  СЖ -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_1");
			AddQuestUserData("Gen_CityCapture", "sSex", GetSexPhrase("","а"));
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  СЖ <--
			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Main":
            iTemp = GetNpcQuestPastDayParam(NPChar, "GoverTalkDate");
            if (iTemp > 0)
            {
				dialog.Text = "Какие будут приказания? Последний ваш визит был " + FindRussianDaysString(iTemp) + " назад.";
			}
			else
			{
			    dialog.Text = "Какие будут приказания?";
			}

            Link.l1 = "Какую сумму налогов ты " + NPCharSexPhrase(NPChar, "собрал", "собрала") + " на данный момент?";
        	Link.l1.go = "Gover_Tax";
            Link.l8 = "Ты " + NPCharSexPhrase(NPChar, "нужен", "нужна") + " мне на корабле, я снимаю тебя с городской службы.";
            Link.l8.go = "Gover_Fire";
			Link.l9 = "Всего хорошего.";
            Link.l9.go = "exit_huber";
            NextDiag.CurrentNode = "Gover_Main";
            SaveCurrentNpcQuestDateParam(NPChar, "GoverTalkDate");
        break;

        case "Gover_Tax":
            iTemp = GetNpcQuestPastDayParam(NPChar, "StartTaxDate");
            iTax  = makeint((GetCharacterSkillSimple(NPChar, SKILL_COMMERCE) + GetCharacterSkillSimple(NPChar, SKILL_LEADERSHIP)) / 2);
            sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
			if (CheckAttribute(sld, "FortValue"))
			{
			    iFortValue = sti(sld.FortValue);
			}
			else
			{
			    iFortValue = 20;
			}
			NPChar.Gover_Tax_Sum = iFortValue*iTax*iTemp;
			dialog.Text = "Мои навыки позволяют мне собирать " + FindRussianMoneyString(iFortValue*iTax) + " в день. За " + FindRussianDaysString(iTemp) + " я " + NPCharSexPhrase(NPChar, "собрал", "собрала") + " " + FindRussianMoneyString(sti(NPChar.Gover_Tax_Sum)) + ".";
			if (sti(NPChar.Gover_Tax_Sum) > 0)
			{
			    Link.l1 = "Я хочу забрать всю сумму налогов.";
            	Link.l1.go = "Gover_Tax_Get";
			}
			Link.l2 = "Благодарю за службу!";
            Link.l2.go = "exit_huber";
        break;

        case "Gover_Tax_Get":
            SaveCurrentNpcQuestDateParam(NPChar, "StartTaxDate");
            AddMoneyToCharacter(Pchar, sti(NPChar.Gover_Tax_Sum));

			NextDiag.CurrentNode = "Gover_Main";
            DialogExit();
        break;

        case "Gover_Fire":
            dialog.Text = "Замечательно! Быть сухопутной крысой не мой удел.";
            Link.l8 = "Вот и славно.";
            Link.l8.go = "exit_company";
            NextDiag.CurrentNode = "exit_2";
		sld = GetColonyByIndex(sti(NPChar.ColonyIdx));
            DeleteAttribute(sld, "OfficerIdx");
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
		AddDialogExitQuestFunction("PGG_BecomeHiredOfficer_1");
		
		DeleteAttribute(NPChar, "Quest.Officer");
		DeleteAttribute(NPChar, "PGGAi.Task");
		DeleteAttribute(NPChar, "PGGAi.LockService");	
		DeleteAttribute(NPChar, "OfficerIdx");
            //  СЖ -->
			ReOpenQuestHeader("Gen_CityCapture");
            AddQuestRecord("Gen_CityCapture", "t3_2");
			AddQuestUserData("Gen_CityCapture", "sCity", XI_ConvertString("colony" + sld.id));
			AddQuestUserData("Gen_CityCapture", "sName", GetFullName(NPChar));
			//  СЖ <--
        break;
        //////////////////////////////    офицер-наместник <--

// Приказы <--
      
//  Выходы -->	
	
		case "exit_quest":
			Dialog.Text = "Я же сказала, что жду Вас на своём корабле, уважаемый!";
			link.l1 = "Да-да. Я помню...";
			link.l1.go = "exit_1488";
		break;

		case "exit_1488":
		NextDiag.CurrentNode = "exit_quest";
		DialogExit();
		break;
		
		case "Exit_ShowParam":
			NextDiag.CurrentNode = "First time";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;

	case "Exit_ShowParam_1488":
			NextDiag.CurrentNode = "Quest_1_End";
	//		NPChar.quest.meeting = true;
			DialogExit();

			PChar.SystemInfo.OnlyShowCharacter = true;
			LaunchCharacter(NPChar);
			break;


			case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "exit_duel":
			NextDiag.CurrentNode = "exit_1";
			DialogExit();
		break;

		case "exit_1":	
			Dialog.Text = "До встречи в море, мерзавец.";
			link.l1 = "Говори-говори, да не заговаривайся."; 
			link.l1.go = "exit_duel";
		break;	

		case "exit_sit":			
			NextDiag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;

		case "exit_company":
			NextDiag.CurrentNode = "exit_2";
			DialogExit();
		break;

	case "exit_huber":
			NextDiag.CurrentNode = "Gover_Main";
			DialogExit();
		break;

case "exit_228":	
Dialog.Text = "Что-то ещё, капитан?";
link.l1 = "Да нет, ничего."; 
link.l1.go = "exit_uvol";
break;
	
case "exit_uvol":
NextDiag.CurrentNode = "exit_228";
DialogExit();
break;
	
case "exit_148":
NextDiag.CurrentNode = "Quest_1_End";
DialogExit();
break;

// Выходы <--

//  Офицерство -->
case "officer_1488":
		//Проверка на ПИРАТЕС, не было! :) //navy 04.04.07
		if (FindFreeRandomOfficer() < 1)
		{
			Dialog.Text = RandPhraseSimple("Хм... Пожалуй, нет...", "Нет, я капитан, и не хочу быть офицером.");
			link.l1 = RandPhraseSimple("Жаль...", "Значит не судьба.");
			link.l1.go = "exit_148";
			break;
		}
		if (!CheckAttribute(NPChar, "Quest.Officer.Price"))
		{
			NPChar.Quest.Officer.Price = 10000 + sti(NPChar.rank)*500*MOD_SKILL_ENEMY_RATE - MakeInt(GetSummonSkillFromNameToOld(pchar, SKILL_LEADERSHIP)*1000);
		}
		Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
				RandPhraseSimple("Это - то, что нужно! Наши клинки напьются вражеской крови! Одна проблемка, мне нужно " + NPChar.Quest.Officer.Price + " песо, чтобы расплатиться с долгами.", 
								"Ты выглядишь настоящ"+ GetSexPhrase("им морским волком","ей морской волчицей") +". И если ты готов"+ GetSexPhrase("","а") +" заплатить " + NPChar.Quest.Officer.Price + " песо, то, пожалуй, мы сработаемся."), 
				LinkRandPhrase("Слухи не врут, капитан и Ваше предложение весьма лестно для меня. Я согласен за весьма умеренную плату в размере " + NPChar.Quest.Officer.Price + " песо присоединиться к Вам.", 
							"Хм... Люди правду молвят. Вы выглядите бывал"+ GetSexPhrase("ым","ой") +" моря"+ GetSexPhrase("ком","чкой") +". Возможно, мне стоит принять Ваше предложение, капитан, если вы согласны заплатить мне " + NPChar.Quest.Officer.Price + " песо.", 
							"У Вас достоверная информация, капитан. Мне довелось побывать во множестве всяких передряг. Я думаю, что с Вами сработаемся. Всего " + NPChar.Quest.Officer.Price + " песо и мы ударим по рукам."));

		MakeRandomLinkOrderTwo(link, PCharRepPhrase(RandSwear() + RandPhraseSimple("Меня это устраивает. Но, надеюсь, Вы не будете каждый день требовать столько.", "Это чертовски дорого, но, думаю, Вы того стоите."), 
				LinkRandPhrase("Я соглас"+ GetSexPhrase("ен","на") +". Считайте себя зачисленным в команду.", "Хм... Пожалуй, я готов"+ GetSexPhrase("","а") +" расстаться с этой суммой.", "Похоже, Вы стоите этих денег. По рукам!")), "officer_hired",
									PCharRepPhrase(RandSwear() + RandPhraseSimple("Вы не стоите столько. Удачи...", "Это чертовски дорого, я не готов"+ GetSexPhrase("","а") +" выкидывать столько денег."), 
				LinkRandPhrase("Мда... Жадность не порок...", "Вы смеётесь надо мной? За такие деньги я могу купить десяток таких, как Вы.", "Это грабеж... Где я возьму Вам такую сумму?")), "exit_148");
		link.l3 = "Хм... А что Вы представляете из себя?";
		link.l3.go = "Exit_ShowParam_1488";
		break;

	case "officer_hired":
		if (sti(pchar.money) < sti(NPChar.Quest.Officer.Price))
		{
			Dialog.Text = "Похоже, у Вас проблемы с наличностью, капитан.";
			link.l1 = "Ах... действительно.";
			link.l1.go = "exit_148";
			break;
		}
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
            	NPChar.Payment = true;
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			SetCharacterRemovable(NPChar, true);
			SaveCurrentNpcQuestDateParam(NPChar, "Companion.CheckRelation");
		Dialog.Text = RandPhraseSimple("Вот и отлично!", "Я не сомневался в Вас, капитан.");
		link.l1 = "Не опаздывайте к отплытию.";
		link.l1.go = "exit_company";
		break;
// Офицерство <--
case "Love_Sex":
		    dialog.text = RandPhraseSimple("Что!!!?? Капитан, ты давно не сходил на берег и не был в борделе?", "Не понимаю, о чем это ты?");
            link.l1 = RandPhraseSimple("Ну сама подумай.. ты такая красавица, да еще и в моем подчинении.", "Ну не идти же мне в бордель, когда под боком есть ты!");
			link.l1.go = "Love_Sex_2";							
			link.l2 = RandPhraseSimple("Извини меня, крошка, очень трудно было удержаться, чтоб не предложить..", "Эх.. ладно, проехали...");
			link.l2.go = "exit_company";	
        break;
        
        case "Love_Sex_2":
		    dialog.text = RandPhraseSimple("Капитан! Держите себя в руках, если не можете в своих, позовите матросов", "То, что я офицер и номинально подчиняюсь Вам, капитан, еще ничего не значит!");
            link.l1 = RandPhraseSimple("Детка, не протився. Я уже не могу себя сдерживать. Пойдем..", "Я - твой капитан! И я приказываю тебе!");
			link.l1.go = "Love_Sex_3";							
			link.l2 = RandPhraseSimple("Извини меня, крошка, очень трудно было удержаться, чтоб не предложить..", "Эх.. ладно, проехали...");
			link.l2.go = "exit_company";	
        break;
        
        case "Love_Sex_3":
         		    dialog.text = RandPhraseSimple("Ну все! Ты ответишь за это! И прямо сейчас!", "Покувыркаться с тобой? Чтож сейчас поглядим, кто на что способен. Иди сюда!");
            link.l1 = "Э.. ты о чем?";
			link.l1.go = "Love_Sex_Yes_2";					        break;

		case "Love_Sex_Yes":
		    dialog.text = RandPhraseSimple("Пожалуй, такому ловеласу можно и уступить.",
                                           "Хорошо, все лучше, чем транжирить деньги на уличных девок.");
            link.l1 = RandPhraseSimple("Oh, Yes!", "Умничка, не идти же мне в бордель, когда под боком есть такая лапа как ты!");
			link.l1.go = "Love_Sex_Yes_2";
        break;
        
        case "Love_Sex_Yes_2":
            pchar.GenQuest.BrothelCount = 0;
            AddCharacterExpToSkill(pchar, "Leadership", 100);
            AddCharacterExpToSkill(pchar, "Fencing", -50);// утрахала
            AddCharacterExpToSkill(pchar, "Pistol", -50);
            AddCharacterHealth(pchar, 10);
            ChangeCharacterComplexReputation(pchar, "nobility", 1);

   			AddDialogExitQuest("PlaySex_1");
			NextDiag.CurrentNode = "After_sex";
			DialogExit();
        break;
        
        case "After_sex":
		    dialog.text = RandPhraseSimple("Хм.. странно, я думала ты способен на большее...",
                                           "Капитан, теперь вы снова можете соображать головой, а не... ? Вернемся к нашим делам.");
            link.l1 = RandPhraseSimple("Но-но! Как ты разговариваешь со старшим по званию!", "Я могу многое, если соберусь с мыслями.");
			link.l1.go = "exit_company";
        break;
// Секас <--

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