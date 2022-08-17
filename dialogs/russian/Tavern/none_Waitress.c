
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
    // вызов диалога по городам -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Tavern\" + NPChar.City + "_Waitress.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // вызов диалога по городам <--
	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "First time":
            NextDiag.TempNode = "First time";
	PlaySound("VOICE\Russian\GOTHIC\WAITRESS\WAITRESS_" + rand(37) + ".wav");
			
		    switch (Rand(4))
			{
				case 0:
					dialog.text = "Прости, красав" + GetSexPhrase("чик","ица") + ", я занята. Хороший день для таверны - не всегда хороший день для разговора!";
					link.l1 = "...";
					link.l1.go = "exit";
				break;

				case 1:
					dialog.text = "Пожалуйста, капитан, не устраивайте дебошей! После них так трудно наводить порядок!";
					link.l1 = "Кхм... Вроде и не собирал" + GetSexPhrase("ся","ась") + ".";
					link.l1.go = "exit";
				break;

				case 2:
								dialog.text = "О, капитан! Вы хотели бы попасть в мои объятья сегодня? Я не люблю хвастаться, но ...";
					link.l1 = "Увы, сейчас я спешу! Давай в другой раз!";					link.l1.go = "exit";
				break;

				case 3:
					dialog.text = "Если вы хотите что-либо заказать - обратитесь, пожалуйста, к хозяину. Он стоит за стойкой.";
					link.l1 = "Спасибо за совет.";
					link.l1.go = "exit";
				break;

				case 4:
					dialog.text = "Если вы хотите как следует отдохнуть и поправить здоровье - снимите комнату на ночь. Ночевка в общей зале вряд ли прибавит вам сил.";
					link.l1 = "Благодарю.";
					link.l1.go = "exit";
				break;
			}			
		break;
	}
}
 
