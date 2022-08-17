// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Говорите, я слушаю.";
			link.l1 = "Я ошиб" + GetSexPhrase("ся","лась") + ". Прощайте.";
			link.l1.go = "Exit";


			if(PChar.RaulEsperanto == "5" && PChar.RaulEsperanto.PrisonTalk.Cumana == false)
			{
				link.l2 = "Мне нужно поговорить с Раулем Эсперанто.";
				link.l2.go = "RaulEsperanto_1";
			}

			//Цена чахотки
			if (!CheckAttribute(npchar, "quest.Consumption") && CheckAttribute(pchar, "questTemp.Consumption") && pchar.questTemp.Consumption == "begin")
			{
				link.l1 = "Слышал, у вас свирепствует эпидемия?";
				link.l1.go = "Consumption";
			}

		break;
		
		
		// РАУЛЬ ЭСПЕРАНТО -->
		case "RaulEsperanto_1":
			if(NPChar.city == PChar.RaulEsperanto.Prison)
			{
	            		dialog.text = "Рауля Эсперанто здесь уже нет. Он был перевезён в Инквизицию на Сантьяго четыре дня назад.";
				link.l1 = "Постойте, а как же главный инквизитор? Он же должен был приехать сюда.";
				link.l1.go = "RaulEsperanto_2";
			}
			else
			{
				PChar.RaulEsperanto.PrisonTalk.Cumana = true;
	            		dialog.text = "Здесь таких нет.";
				link.l1 = "Прошу прощение за беспокойство, я видимо ошиб" + GetSexPhrase("ся","лась") + ".";
				link.l1.go = "RaulEsperanto_2";
			}
		break;
		
		case "RaulEsperanto_2":
            		dialog.text = "Нам сообщили, что Антониу де Соуза не сможет посетить нашу колонию, а прибудет сразу на Сантьяго и велели переправить Эсперанто туда. Больше мы ничего не знаем. Приказы не обсуждаются.";
			link.l1 = "Что же, спасибо за помощь. Придётся плыть обратно.";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("RaulEsperantoToIncquisitio");
		break;
		// РАУЛЬ ЭСПЕРАНТО <--

		//--> Цена чахотки
		case "Consumption":
			dialog.text = "Да, так что без крайней нужды в тюремные помещения не попасть, а почему вас это интересует?";
			link.l1 = "Просто любопытно... Если мои ребята надебоширят на берегу и загремят под арест, стоит запастись желтым полотном?";
			link.l1.go = "Consumption_1";
		break;
		
		case "Consumption_1":
			dialog.text = "Если это шутка, сеньор, то мне, увы, не смешно. Казематы здесь сырые и холодные, да и климат – сами видите, какой. Чахотка - частый гость в этих подземельях. Я даже вынужден приплачивать своим ребятам за то, чтобы они разносили еду в камеры. А уж стоять в карауле там внутри – считается чем-то вроде каторжных работ.";
			link.l1 = "Прошу прощения, я просто хотел узнать, насколько все серьезно?";
			link.l1.go = "Consumption_2";
		break;
		
		case "Consumption_2":
			dialog.text = "Более чем. У нас даже доктора нет – умер от этой же проклятой чахотки. Теперь, лишь фельдшер полкового гарнизона раз в неделю осматривает больных. Но кому какое дело, до этих оборванцев и преступников?\nБольшинство считает, что туда им и дорога, и с этим сложно поспорить.";
			link.l1 = "Мои познания в медицине не велики, но чахотка, хоть заразна и смертоносна, ведь не убивает людей в считанные дни, как поговаривают про вашу эпидемию в городе? Разве больной не должен 'чахнуть' месяцы, или даже годы?";
			link.l1.go = "Consumption_3";
		break;
		
		case "Consumption_3":
			dialog.text = "Как вы верно заметили, вы не медик, так что судить о протекании болезней, с вашей стороны несколько... необоснованно. Я говорю лишь то, что считал наш доктор, перед тем как эта эпидемия унесла и его, и мне непонятно ваше любопытство и цинизм. Здесь умирают люди!";
			link.l1 = "А разве не вы, еще минуту назад, называли их оборванцами и преступниками, и считали их участь заслуженной?";
			link.l1.go = "Consumption_4";
		break;
		
		case "Consumption_4":
			dialog.text = "Довольно, сеньор! Я полагаю, у вас, как и у меня, есть дела поважнее, чем состязаться в остроумии. Дверь прямо за вами – прошу.";
			link.l1 = "Что же, простите мою бестактность, я уже ухожу.";
			link.l1.go = "Consumption_5";
		break;
		
		case "Consumption_5":
			DialogExit();
			npchar.quest.Consumption = "true";
			pchar.questTemp.Consumption.Commandant = "true";
			AddQuestRecord("Consumption", "3");
			pchar.quest.Consumption.win_condition.l1 = "location";
			pchar.quest.Consumption.win_condition.l1.location = "VillaAlegria_houseF2";
			pchar.quest.Consumption.function = "Consumption_CommandantHouse";
		break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

