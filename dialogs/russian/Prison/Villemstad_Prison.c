// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Говорите, я слушаю.";
			link.l1 = "Я ошибся. Прощайте.";
			link.l1.go = "Exit";
			//Португалец
			if (CheckAttribute(pchar, "questTemp.Portugal") && pchar.questTemp.Portugal == "PortugalInPrison")
            {
                link.l1 = "Офицер, у вас содержится пленник - Бартоломео Португалец...";
                link.l1.go = "Portugal";
            }
		break;
		
		//Португалец
		case "Portugal":
			dialog.text = "Содержится. А вам какое дело? К нему допускаются только представители Голландской Вест-Индской Компании, и то - только с письменного разрешения губернатора. Один из офицеров Компании как раз допрашивает этого пирата. Так что если вы явились, чтобы его увидеть - вам лучше уйти, и побыстрее.";
			link.l1 = "Я явился не для того, чтобы его увидеть.";
			link.l1.go = "Portugal_1";
		break;
		
		case "Portugal_1":
			dialog.text = "А для чего же, позвольте спросить?";
			link.l1 = "Для того, чтобы забрать его!";
			link.l1.go = "fight";
			chrDisableReloadToLocation = true;
			pchar.quest.InMarigoResidenceOver.over = "yes"; //снять таймер
			InterfaceStates.Buttons.Save.enable = false;//запретить сохраняться
		break;

//-------------------------------------------------------------------------------
//	Тюремный эскорт
//-------------------------------------------------------------------------------
		case "PrisonEscort_1":
			dialog.text = "Разумеется, можете, но я все же хотел попросить вас задержатся немного.";
			link.l1 = "Я очень спешу, прощайте.";
			link.l1.go = "Exit";
			link.l2 = "Ладно, что уж там, и так потратил уйму времени без толку, отчего же не задержатся еще на пару минут...";
			link.l2.go = "PrisonEscort_2";
			
			LAi_SetPlayerType(pchar);
			DeleteAttribute(pchar, "questTemp.PrisonEscort_quest");
			LAi_LocationDisableOfficersGen("Villemstad_prison", false);
		break;
		
		case "PrisonEscort_2":
			dialog.text = "Понимаете, дело в том, что в последнее время участились нападения на корабли, транспортирующие заключенных и рабов. Если вы спросите, почему я обратился именно к вам, я отвечу - то, что о вас говорят, делает вам весьма хорошую репутацию, по крайней мере для подобного рода просьбы, ха-ха-ха-ха, надеюсь вы меня понимаете?";
			link.l1 = "Вы хотите попросить меня, найти людей, которые этим промышляют?";
			link.l1.go = "PrisonEscort_3";
		break;
		
		case "PrisonEscort_3":
			dialog.text = "Вот именно! Губернатор снарядил и отправил экспедицию на поимку этих бродяг, но результатов это не дало. Несколько раз пытались ловить 'на живца', но безрезультатно. Обеспечить охрану каждому кораблю, который перевозит рабов и заключенных, мы не можем.";
			link.l1 = "А почему это вас так волнует? Ну, подумаешь, пропадет пара-тройка рабов или каторжников, вам-то, что с этого?";
			link.l1.go = "PrisonEscort_4";
		break;
		
		case "PrisonEscort_4":
			dialog.text = "Минхер, хочу напомнить вам, что любопытство - порок! Допустим, у меня есть финансовые интересы при успешной доставке данного 'товара'...";
			link.l1 = "Все понятно, дальше можете не продолжать. У меня остался всего один вопрос - оплата.";
			link.l1.go = "PrisonEscort_5";
		break;
		
		case "PrisonEscort_5":
			dialog.text = "Могу предложить вам 15000 песо.";
			link.l1 = "Я согласен. Как только что-либо узнаю - сразу же сообщу.";
			link.l1.go = "PrisonEscort_6";
			link.l2 = "Вынужден вам отказать. За такую ничтожную сумму я не намерен отрываться от дел насущных, прощайте.";
			link.l2.go = "Exit";
		break;
		
		case "PrisonEscort_6":
			dialog.text = "Вот и отлично! Буду ждать вас с хорошими новостями, капитан.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("PrisonEscort_SartSearch");
		break;
		
		case "PrisonEscort_6a":
			dialog.text = "Выкладывайте, что там у вас.";
			if(pchar.questTemp.PrisonEscort_quest == "sink_ship")
			{
				link.l1 = "Похоже, я разобрался с одним из участников налетов. Вот, эти записи я обнаружил в каюте одного капитана...";
				link.l1.go = "PrisonEscort_8";

			}
			else
			{
			if(pchar.questTemp.PrisonEscort_quest == "Capture_ship")
				{
					link.l1 = "Я разобрался с одним из участников налетов. Правда его корабль пошел ко дну и мне ничего больше не удалось выяснить...";
					link.l1.go = "PrisonEscort_7";
				}

			}
		break;
		
		case "PrisonEscort_7":
		dialog.text = "Жаль, очень жаль... Боюсь, что не могу вам верить на слово, так что награду, к сожалению, я вам не выплачу, всего доброго.";
		link.l1 = "Да я, в общем-то, не особо на нее и рассчитывал, до свидания.";
		link.l1.go = "Exit";			
		AddDialogExitQuest("PrisonEscort_failed");
		break;
		
		case "PrisonEscort_8":
		dialog.text = "Ну-ка, ну-ка... Мне нужно немедленно доложить об этом губернатору! Ах да, чуть не забыл, вот ваши обещанные 15000 песо, всего доброго.";
		link.l1 = "До встречи.";
		link.l1.go = "PrisonEscort_Exit";			
		break;

		case "PrisonEscort_Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();		
		AddDialogExitQuest("PrisonEscort_complette");					break;


	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
