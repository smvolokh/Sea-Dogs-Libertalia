// диалог протекторов, солдат и мушкетеров кланов LSC
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	string sTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Вы что-то хотели?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
//------------------------------------- фразы гардов нарвалов --------------------------------------------
		case "Narval_warning":

		dialog.text = LinkRandPhrase("Ребята, осторожно, здесь тот самый больной псих! К оружию!","Враг на территории! К бою!","Ах ты, мерзавец! Сейчас мы тебе зададим хорошую взбучку!");
		link.l1 = "А-ать!";
		link.l1.go = "check_fight";
		break;

		case "check_fight":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			LAi_group_MoveCharacter(NPChar, "PearlGroup_1");
			LAi_group_Attack(NPChar, Pchar);
		break;

				
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}