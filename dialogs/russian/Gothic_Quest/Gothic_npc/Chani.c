//Чани, Кики племени Шаганумби
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i, n, iTemp;
	string sTemp;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	bool ok;
                        int iTest;
                        ref rColony;
                        string sFrom_sea = "";
	
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
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_4.wav");
			dialog.text = "Будь осторожен Буча, если ты носишь гром палку тебе здесь не рады.";
			link.l1 = "Хех, без неё ни как, бывай!";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniSettlement" && !CheckAttribute(npchar, "quest.ChaniSettlement"))
			{
				link.l1 = "";
				link.l1.go = "Chani";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "RoseauCharlotteMayakDieenemy" && !CheckAttribute(npchar, "quest.RoseauCharlotteMayakDieenemy"))
			{
				link.l1 = "";
				link.l1.go = "Chani_18";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniMayakDieenemy" && !CheckAttribute(npchar, "quest.ChaniMayakDieenemy"))
			{
				link.l1 = "";
				link.l1.go = "ChaniMayakDieenemy";
			}
			if(CheckAttribute(pchar, "questTemp.GothicTorus") && pchar.questTemp.GothicTorus == "ChaniMayak" && !CheckAttribute(npchar, "quest.ChaniMayak"))
			{
				link.l1 = "";
				link.l1.go = "ChaniMayak";
			}
		break;

		case "Chani":
			dialog.text = "";
			link.l1 = "Кто ты?";
			link.l1.go = "Chani_1";
		break;

		case "Chani_1":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_0.wav");
			dialog.text = "Дочь Чаки Бокира, Кики племяни Шаганумби, я посвящу тебя в тайны вуду, я пойду с тобой в храм земли, Ворон говорит если ему мы не поможем Гаютибо уничтожит Шаганумби, это путь пиратов, наш путь - вуду.";
			link.l1 = "Ворон? Бывший рудный барон Гамеза?";
			link.l1.go = "Chani_2";
		break;

		case "Chani_2":
			dialog.text = "Не знаю, кем он был раньше, но у него есть власть - неземная власть.";
			link.l1 = "Понятно. А кто тогда Гаютибо?";
			link.l1.go = "Chani_3";
		break;

		case "Chani_3":
			dialog.text = "Это зло, зло которое распространяется по всей земле и это надо остановить. Торус был у нас, и мой народ подозревает в убийстве женщин, но это не мы.";
			link.l1 = "Тогда кто? Помоги мне в этом разобраться!";
			link.l1.go = "Chani_4";
		break;

		case "Chani_4":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_1.wav");
			dialog.text = "Я помогу, но мы не будем наваливаться как стадо кабанов, у меня есть план.";
			link.l1 = "Что за план!";
			link.l1.go = "Chani_5";
		break;

		case "Chani_5":
			dialog.text = "Зло пробуждается под покровом ночи. Но сначало нужно убедится, ты знаешь его обитание?";
			link.l1 = "Ну, примерно да, старик Джек, что - то почувсвовал вроде как взгляд чей - то, это было в винном погребе, около двенадцати ночи.";
			link.l1.go = "Chani_6";
		break;

		case "Chani_6":
			dialog.text = "Ему повезло, задержался бы на немного, его бы не было? Значит сегодня ночью встретимся около этого погреба. Не проспи, ночью всё станет ясно.";
			link.l1 = "Хорошо, встречаемся в поселении у погреба.";
			link.l1.go = "exit_1";
		break;

		case "Exit_1":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("ChaniSettlement_0");
		break;

		case "Chani_7":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! А вот и ты буча! Я, что - то чувствую, оно где - то рядом!";
			link.l1 = "Хорошо, тогда ты иди первая, я за тобой, полюбуюсь твоей... э!";
			link.l1.go = "Chani_7_1"; 
		break;

		case "Chani_7_1":
			dialog.text = "ЧТО!";
			link.l1 = "Я имел ввиду твоей походкой!";
			link.l1.go = "Chani_7_2"; 
		break;

		case "Chani_7_2":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "Это правда или ты хочешь ко мне подмазаться!";
			link.l1 = "Ну, всё может быть, ладно пошли уже!";
			link.l1.go = "exit";
                                                         LocatorReloadEnterDisable("Roseau_town", "basement1_back", false);
		                  AddDialogExitQuestFunction("ChaniSettlement_2");
		break;

		case "Chani_8":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария!!!";
			link.l1 = "Что ты этим хочешь сказать, да брось здесь никого нет, кроме нас двоих, смотри сколько здесь всего, может по чарочке рома для начала?";
			link.l1.go = "Chani_9";
		break;

		case "Chani_9":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "Это правда или ты хочешь ко мне подмазаться!";
			link.l1 = "А почему бы и нет, давай обнимемся?";
			link.l1.go = "Chani_10";
		break;

		case "Chani_10":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_5.wav");
			dialog.text = "Я тебе руки отрублю!";
			link.l1 = "";
			link.l1.go = "Chani_11";
		break;

		case "Chani_11":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_HUI.wav");
			dialog.text = "";
			link.l1 = "Ой, ой, ой....";
			link.l1.go = "Chani_12";
		break;

		case "Chani_12":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Тихо кто - то идёт? Ничего не бойся, в случае опасности я сделаю барьер света, нас не смогут обнаружить...";
			link.l1 = "";
			link.l1.go = "exit_2";
		break;

		case "Exit_2":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("Chani_Dieenemy");
		break;

		case "Chani_15":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Теперь ты убедился, этот демон и убил женщин ваших, ему нужна была плоть, что бы обрести своё тело, это и есть Гаютибо, а по вашему Ищущий\nРасскажи об этом Торусу, мой народ в этом убийсве не причастны и пусть придёт к нам в деревню и попросит прощения\nМне пора, я потратила много сил для сдерживания.";
			link.l1 = "Вот чёрт, давай от сюда выбираться поскорей! Я провожу тебя...";
			link.l1.go = "Chani_16";
		break;

		case "Chani_16":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_3.wav");
			dialog.text = "Это правда или ты хочешь ко мне подмазаться! Только до городских ворот.";
			link.l1 = "";
			link.l1.go = "Chani_17";
		break;

		case "Chani_17":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GUD.wav");
			dialog.text = "";
			link.l1 = "Хорошо...";
			link.l1.go = "exit_3";
		break;

		case "Exit_3":
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		npchar.quest.ChaniSettlement = "true";
		AddDialogExitQuestFunction("Chani_Dieenemy_8");
		break;


		case "Chani_18":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Я помогу, я сделаю барьер света, вы сможете их одолеть, но это будет не просто.";
			link.l1 = "Хорошо.";
			link.l1.go = "exit_4";
		break;

		case "Exit_4":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_6.wav");
		DialogExit();
		npchar.quest.RoseauCharlotteMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_3");
		break;


		case "ChaniMayakDieenemy":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Я помогу, остался сам Ищущий, я его чувствую, его силы ослаблены, пойдём, нет времени.";
			link.l1 = "Всё будет в порядке.";
			link.l1.go = "exit_5";
		break;

		case "Exit_5":
	                   PlaySound("VOICE\Russian\GOTHIC\GG\GG_13.wav");
		DialogExit();
		npchar.quest.ChaniMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_20");
		break;


		case "ChaniMayak":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Мы это сделали.";
			link.l1 = "";
			link.l1.go = "ChaniMayak_1";
		break;

		case "ChaniMayak_1":
	                                      PlaySound("VOICE\Russian\GOTHIC\GG\GG_YES_6.wav");
			dialog.text = "";
			link.l1 = "Вроде бы да!";
			link.l1.go = "ChaniMayak_2";
		break;

		case "ChaniMayak_2":
	                                      PlaySound("VOICE\Russian\Chani\ChaniRisen_2_2.wav");
			dialog.text = "Тавонга, самогария! Я очень устала, хочу домой!";
			link.l1 = "Спасибо тебе Чани, без тебя, мы бы были обречены.";
			link.l1.go = "exit_6";
		break;

		case "Exit_6":
		DialogExit();
		npchar.quest.ChaniMayakDieenemy = "true";
		NextDiag.CurrentNode = NextDiag.TempNode;
		AddDialogExitQuestFunction("MayakDieenemy_27");
		break;







		



		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


	}
}