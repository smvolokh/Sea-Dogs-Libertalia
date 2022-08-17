
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Не о чем говорить.";
			link.l1 = "Ладно...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Avroraaa_1":
			dialog.text = "Не пугайтесь, прошу вас не пугайтесь?";
			link.l1 = "Я знаю о тебе, мне расказал один священик, ты была заложницей этого чудовища.";
			link.l1.go = "Avroraaa_2";
		break;
		case "Avroraaa_2":
			dialog.text = "Да, это так, (плачет) теперь такой я осанусь на всегда?";   
			link.l1 = "Не говорите ерунды, заклятие снято и я уверен свами будет всё хорошо?";
			link.l1.go = "Avroraaa_3";
		break;
		case "Avroraaa_3":
			dialog.text = "Значит вы мой спаситель! Я благодарна тебе, могу узнать имя моего спасителя.";
			link.l1 = "Конечно, меня зовут " + GetFullName(pchar) + ", я капитан, капитан сорви голова!";
			link.l1.go = "Avroraaa_4";
		break;
		case "Avroraaa_4":
			dialog.text = "Ну а я (плачет), я не везучая, простите меня капитан!";
			link.l1 = "Да будет вам, всё уже позади, давай-ка дыши глубже говори спокойнее?";
			link.l1.go = "Avroraaa_5";
		break;

		case "Avroraaa_5":
			dialog.text = "Меня завут Аврора, я сирота, родителей не помню и я не счасливая (плачет)!";
			link.l1 = "Слушай а пойдешь ко мне на службу, будет шанс всё поправить?";
			link.l1.go = "Avroraaa_6";
		break;

		case "Avroraaa_6":
			dialog.text = "Капитан, вы не предстовляете как я рада такуму повороту судьбы. Конечно же пойду, да что там пойду - побегу.....";
			link.l1 = "Отлично. Добро пожаловать в команду.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			CloseQuestHeader("TwooDoubleMushket_1");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "Avrora_1";
			npchar.model.animation = "Avrora";
			npchar.greeting = "Gr_Avrora";
			npchar.Dialog.Filename = "Enc_OfficerGirl.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);			
			npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();
		break;


	}
}




