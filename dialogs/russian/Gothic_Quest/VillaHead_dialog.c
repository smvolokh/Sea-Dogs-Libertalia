// диалог на вилле
void ProcessDialogEvent()
{
	ref NPChar, sld, location;
	aref Link, NextDiag;
	int i, iTemp;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		location = &Locations[FindLocation(pchar.location)];
		case "First time":
			if (LAi_grp_playeralarm > 0)
			{
       			dialog.text = NPCharRepPhrase(pchar, 
					LinkRandPhrase("Вы посмели явиться сюда?! Смелый шаг...", "Как эти бездельники допустили, чтобы ко мне ворвался враг?! Уму непостижимо...", "Да уж, моя охрана немногого стоит, раз "+ GetSexPhrase("какой-то бездельник","какая-то бездельница") +" бегает в тут..."), 
					LinkRandPhrase("Что тебе нужно, "+ GetSexPhrase("негодяй","мерзавка") +"?! Мои солдаты уже взяли твой след, далеко тебе не уйти"+ GetSexPhrase(", грязный пират","") +"!", "Грязн"+ GetSexPhrase("ый","ая") +" убийца, вон из моей резиденции! Стража!!", "Я не боюсь тебя, мерзав"+ GetSexPhrase("ец","ка") +"! Скоро тебя повесят, далеко тебе не уйти..."));
				link.l1 = NPCharRepPhrase(pchar,
					RandPhraseSimple("Солдатня мало чего стоит...", "Им меня ни за что не поймать."), 
					RandPhraseSimple("Заткни свою пасть, " + GetWorkTypeOfMan(npchar, "") + ", а не то вырву твой поганый язык!", "Вот что я тебе скажу, приятель: сиди тихо, и будешь жить..."));
				link.l1.go = "fight";
				break;
			}
			if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY)
			{
    			dialog.text = "Враг в резеденции! Тревога!!";
				link.l1 = "А-ать, дьявол!";
				link.l1.go = "fight"; 
				break;
			}	
			dialog.text = LinkRandPhrase(""+TimeGreeting()+", месье. Я - "+GetFullName(npchar)+", смотрящий на вилле самого шевалье Филиппа де Пуанси. Что вам тут нужно?","Здравствуйте, сударь. Что вам угодно?","Хм. Вы что-то хотели от меня, месье? Я вас слушаю.");

			link.l1 = "Я просто осматриваюсь и уже ухожу.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
								
		//замечание по обнаженному оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_SetHP(NPChar, 400, 400);
			TakeNItems(NPChar, "potion2", 3);
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_MoveCharacter(NPChar, "TempFight");
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
			ChangeCharacterNationReputation(pchar, sti(npchar.nation), -3);
		break;
	}
}
