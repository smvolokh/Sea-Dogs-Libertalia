
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if(PChar.Gothic_Delivery.CancelMoneyForBobMcCain == true)
			{
				dialog.text = "Ну, что?";			
				if(sti(PChar.money) >= 5000)
				{
					link.l1 = "Вот твои деньги";
					link.l1.go = "8";
				}
				else
				{
					link.l1 = "У меня пока нет нужной суммы.";
					link.l1.go = "11";
				}
				
				link.l2 = "Пока ничего.";
				link.l2.go = "11";
				break;
			}
		
			dialog.text = "Кэп, садись, выпей со мной!";
			link.l1 = "Нет желания. Да и занят я.";
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "1":
 	                                      PlaySound("VOICE\Russian\Gr_Tavern_Mate_3.wav");
			dialog.text = "Эй, кэп, выпить не хочешь?";
			link.l1 = "";
			link.l1.go = "1_2";
		break;

		case "1_2":
 	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_NO_6.wav");
			dialog.text = "";
			link.l1 = "Хмм, нет.";
			link.l1.go = "1_3";
		break;
		
		case "1_3":
 	                                      PlaySound("VOICE\Russian\Gr_Tavern_Mate_15.wav");
			dialog.text = "Выпьем за тех кто в море. А я бы на твоём месте выпил. Глядишь, информацией полезной разжил" + GetSexPhrase("ся","ась") + ". Ну что, может, присядешь?";
			link.l1 = "";
			link.l1.go = "1_4";
		break;

		case "1_4":
  	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "Хорошо...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithMcCain");
		break;
		
		case "4":
			dialog.text = "Вот, другое дело!";
			link.l1 = "Ну, хорошо, выкладывай, что там у тебя.";
			link.l1.go = "5";
		break;
		
		case "5":
			dialog.text = "Не торопись, кэп, давай-ка сначала кое-что обсудим. Информация не бесплатная, сам" + GetSexPhrase("","а") + " понимаешь, так что придётся платить. Пять тысяч звонких песо, и я скажу тебе, где искать Акила.";
			link.l1 = "Откуда тебе известно, что я его ищу?";
			link.l1.go = "6";
		break;
		
		case "6":
			dialog.text = "Слышал, как ты трепал" + GetSexPhrase("ся","ась") + " о Акиле с тавернщиком.";
			link.l1 = "Давай сделаем так, я тебе заплачу, но только если твоя информация будет полезна.";
			link.l1.go = "7";
		break;
		
		case "7":
			dialog.text = "Нет, кэп, так дела не делают. Сначала ты отсыплешь в мои карман пять тысяч, и только потом я тебе всё скажу. Иначе, нет денег, нет информации.";
			
			if(sti(PChar.money) >= 5000)
			{
				link.l1 = "Ну хорошо, вот деньги. Теперь говори, где Акил!!!";
				link.l1.go = "8";
			}
			else
			{
				link.l1 = "Я вернусь, когда у меня будут деньги.";
				link.l1.go = "11";
			}
			
			link.l2 = "Если надумаю, обращусь к тебе за помощью.";
			link.l2.go = "11";
		break;
		
		case "8":
			AddMoneyToCharacter(PChar, -5000);
			PChar.Gothic_Delivery.CancelMoneyForBobMcCain = false;
			dialog.text = "Значит так, кэп, слушай внимательно, второй раз повторять не люблю. Сидел я сегодня как обычно за кружечкой рома и слышал разговор трёх человек. Один из них и был тот Акил, которого ты ищешь. \n Так вот эти двое, что разговаривали с Акилом, назначили ему встречу сегодня в бухте Бенурес.";
			link.l1 = "А откуда ты знаешь, что один из них был Акил.";
			link.l1.go = "9";
		break;
		
		case "9":
			dialog.text = "Те двое обращались к нему не иначе, как Акил. Так, что будь уверен" + GetSexPhrase("","а") + ", что это тот кого ты ищешь.";
			link.l1 = "Ладно, верю. Но если ты мне солгал, и сегодня там никого не будет, найду и...";
			link.l1.go = "10";
		break;
		
		case "10":
			dialog.text = "За информацию ручаюсь, кэп. Будь уверен" + GetSexPhrase("","а") + ", она точная.";
			link.l1 = "Ну смотри, если одурачил меня, найду и закопаю.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("GothicDeliveryDialogWithMcCainEnd");
		break;
		
		case "11":
			ChangeCharacterAddressGroup(PChar, "Pirates_tavern", "goto", "goto2");
			LAi_SetPlayerType(PChar);
			LAi_SetSitType(CharacterFromID("Bob McCain"));
			PChar.Gothic_Delivery.CancelMoneyForBobMcCain = true;
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
