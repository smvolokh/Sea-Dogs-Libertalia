// Сагитта ведьма 
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
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
                                      case "First time":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_17_01.wav");
			dialog.text = "Говори, что тебе нужно от меня и уходи я занята?";
			link.l1 = "Ничего.";
			link.l1.go = "exit";

			if(CheckAttribute(pchar, "questTemp.GothicSagitta") && pchar.questTemp.GothicSagitta == "Delivery" && !CheckAttribute(npchar, "quest.Delivery"))
			{
				link.l1 = "Ты здесь совсем одна!";
				link.l1.go = "Sagitta_hallo_1";
			}
		break;
		
		
		case "Sagitta_hallo_1":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_15_00.wav");
			dialog.text = "";
			link.l1 = "Ты здесь совсем одна!";
			link.l1.go = "Sagitta_hallo_2";
		break;

		case "Sagitta_hallo_2":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WAS_17_01.wav");
			dialog.text = "Я живу здесь, столько, сколько себя помню и занимаюсь травами.";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_3";
		break;

		case "Sagitta_hallo_3":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WAS_17_02.wav");
			dialog.text = "Лес мой друг, он даёт мне то, что нужно.";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_4";
		break;

		case "Sagitta_hallo_4":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_15_00.wav");
			dialog.text = "";
			link.l1 = "Кто ты?";
			link.l1.go = "Sagitta_hallo_5";
		break;

		case "Sagitta_hallo_5":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_01.wav");
			dialog.text = "Ты, что никогда не слышал обо мне!!!";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_6";
		break;

		case "Sagitta_hallo_6":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_02.wav");
			dialog.text = "Меня называют ведьмой целительницей а ещё шаманкой!";
			link.l1 = "";
			link.l1.go = "Sagitta_hallo_7";
		break;

		case "Sagitta_hallo_7":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_HALLO_WER_17_03.wav");
			dialog.text = "Но когда им плохо, они неожиданно вспоминают старую, добрую Сагитту и её целебные травы.";
			link.l1 = "";
			link.l1.go = "Sagitta_Thekla";
		break;

		case "Sagitta_Thekla":
			dialog.text = "";
			link.l1 = "У меня для тебя посылка от Тёклы, портяжный набор.";
			link.l1.go = "Sagitta_Thekla_1";
		break;

		case "Sagitta_Thekla_1":
	                                      PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_THEKLA_17_01.wav");
			dialog.text = "Ах, да вообще - то я ожидала её ещё несколько дней назад!";
			link.l1 = "Забирай.";
			link.l1.go = "Sagitta_Thekla_2";
		break;

		case "Sagitta_Thekla_2":
			PlaySound("interface\important_item.wav");
		                   RemoveItems(PChar, "tailor_tool", 1);
			dialog.text = "Ты можешь оказать даме услугу, мне необходимо передать Бальтраму этот дневник!";
			link.l1 = "А что за Бальтрам, и где его искать.";
			link.l1.go = "Sagitta_Thekla_3";
		break;

		case "Sagitta_Thekla_3":
			dialog.text = "Да я его и сама не знаю, местные рыбаки не далеко от острова всретили старое корыто на борту которого обнаружили мертвые души\n Корыто на буксир взяли, тела придали земле а этот дневник отдали мне, так вот в дневнике указано имя Бальтрам с адресом острова и имя капитана этого суденышка, звали его Томми Толстяк царство ему небесное\nПоэтому я и хочу с вашей помощью передать весточку, а именно дневник, вдуг эти люди были родственниками, вы понимаете меня капитан.";
                                                         link.l1 = "Ну не знаю, не достоющий груз, мертвые души с коробля, что - то я как - то не очень восторге от такой услуги.";
                                                        link.l1.go = "Sagitta_Thekla_exit";
                                                         link.l2 = "Хм... Понимаю, я доставлю этот дневник в память о Томми.";
                                                        link.l2.go = "Sagitta_Thekla_4";
		break;

		case "Sagitta_Thekla_exit":
                                      chrDisableReloadToLocation = false;//открыть локацию
	                   PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_TEACHALCHEMYREQUEST_NEIN_17_01.wav");
		dialog.text = "Тогда хватит тратить моё время на всякую чепуху...";
		link.l1 = "...";
		link.l1.go = "exit";			
		npchar.quest.Delivery = "true";
		AddQuestRecord("Delivery", "2_1");
	                   AddDialogExitQuestFunction("No_StartSagitta");
		break;

		case "Sagitta_Thekla_4": 
                                      chrDisableReloadToLocation = false;//открыть локацию
	                   PlaySound("VOICE\Russian\gotica\SAGITTA\DIA_SAGITTA_TEACHALCHEMYREQUEST_WO_JA_17_01.wav");
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		TakeNItems(pchar, "PortmansBook", 1);
		Log_Info("Вы получили судовой журнал");
		PlaySound("interface\important_item.wav");	
		npchar.quest.Delivery = "true";
		AddQuestRecord("Delivery", "2");
	                   AddDialogExitQuestFunction("GothicDelivery");
		break;


		case "Smithy_SagittaAnn":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "Чего вы хотите от меня!";
			link.l1 = "Уважаемая Сагитта, вы мне обещали, время не терпит отлагательсв. Где ваш человек?";
			link.l1.go = "SagittaAnn_1";
		break;
		
		case "SagittaAnn_1":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "Да обещала, но я ему не жена, чтобы контролировать его, я не знаю!!!";
			link.l1 = "Нет слов! А ещё ведьма!!!";
			link.l1.go = "SagittaAnn_2";
		break;

		case "SagittaAnn_2":
	                    LAi_ActorTurnToCharacter(CharacterFromID("Sagitta"), CharacterFromID("AnnHooms"));
			dialog.text = "Да ведьма, обернись - курица!!!";
			link.l1 = "...";
			link.l1.go = "SagittaAnn_3";
		break;

		case "SagittaAnn_3":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuestFunction("Gothic_SagittaAnn_3");
		break;








		
		case "Sagitta_2":
			dialog.text = "Ну, давай начнем с того, что ты мне покажешь растение, о котором ведешь речь. Может, ты просто наслушался уличной болтовни, а теперь явился сюда и отвлекаешь меня от важных дел. Где твоя мангароса?";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Вот она, смотри.";
				link.l1.go = "Sagitta_3";
			}
			else
			{
				link.l1 = "Гм...";
				link.l1.go = "Sagitta_exit";
			}
		break;
		
		case "Sagitta_exit":
			dialog.text = "Ну, и что ты тут мне пытаешься показать? Нет у тебя мангаросы. Так что топай отсюда, парень, пока я не рассердилась. Разговор окончен.";
			link.l1 = "Но...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Sagitta_wait";
		break;
		
		case "Sagitta_wait":
			dialog.text = "Опять ты? Не доводи до греха, парень...";
			if (CheckCharacterItem(pchar, "cannabis7"))
			{
				link.l1 = "Не ругайся, Сагитта. В прошлый раз я просто ее где-то выронил. Вот, я принес мангаросу. Смотри.";
				link.l1.go = "Sagitta_3";
			}
			else
			{
				link.l1 = "...";
				link.l1.go = "Sagitta_exit";
			}
			NextDiag.TempNode = "Sagitta_wait";
		break;
		
		case "Sagitta_3":
			dialog.text = "Так... Похоже, ты все-таки что-то знаешь. И ты хочешь, чтобы я рассказала тебе секреты своих зелий из этого растения?";
			link.l1 = "Именно так. Ну, конечно, не бесплатно, я понимаю...";
			link.l1.go = "Sagitta_4";
		break;
		
		case "Sagitta_4":
			dialog.text = "Еще бы ты этого не понимал, соколик! На дурня ты совсем не похож. Ну что же, я не против поделиться знаниями с человеком, который сам за ними пришел, и который не переводит это редкое растение на дурманящее курево...";
			link.l1 = "Сагитта, перед тем как торговаться, просвети меня хотя бы в общих чертах - что за зелья получаются из мангаросы?";
			link.l1.go = "Sagitta_5";
		break;
		
		case "Sagitta_5":
			dialog.text = "Торговаться, парень, мы с тобой не будем. Я назначаю цену - а ты решишь, будешь ее платить, или нет. Ни на какие скидки и торг даже не рассчитывай, чай, не на рынке. Что же касается твоего вопроса: из мангаросы получаются зелья, воздействующие на физические способности. Они могут сделать тебя более сильным, выносливым и быстрым, либо оказать комплексное воздействие на твое тело.";
			link.l1 = "Очень интересно! Назови свою цену.";
			link.l1.go = "Sagitta_6";
		break;
		
		case "Sagitta_6":
			dialog.text = "Я могу научить тебя рецептам трех зелий. За каждый рецепт я прошу один стебель мангаросы и триста золотых монет.";
			link.l1 = "Расскажи об этих трех зельях подробнее - что каждое делает?";
			link.l1.go = "Sagitta_7";
		break;
		
		case "Sagitta_7":
			dialog.text = "Чтобы изготовить любое зелье, ты должен владеть основами алхимии. Действие всех зелий временное и ограничивается приблизительно двумя днями\nПервое зелье придает тебе силы и выносливости. Ты становишься крепче, можешь успешнее противостоять врагам в бою и переносить больше тяжестей\nВторое зелье дарит тебе быстроту, ловкость, неутомимость, а также остроту глаза\nТретье зелье сочетает в себе эффекты первого и второго, но вдвое слабее. Однако оно также придаст тебе обаяния, уверенности в себе и сделает более удачливым\nТакже все зелья из мангаросы положительно влияют на здоровье. Употреблять их следует только по одному, и не раньше, чем закончится действие предыдущего - в противном случае не только не будет эффекта, но напротив - получишь отравление\nНу что, соколик, ты готов оплатить свои новые знания, или тебе нужно время на размышление?";
			if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
			{
				link.l1 = "Да, я готов.";
				link.l1.go = "Sagitta_8";
			}
			link.l2 = "Я хочу немного подумать. Это непростое решение.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Sagitta_next";
		break;
		
		case "Sagitta_next":
			if (CheckAttribute(npchar, "quest.recipe_all"))
			{
				dialog.text = "А-а, это ты, соколик! Ну как, помогают тебе мои зелья?";
				link.l1 = "Даже очень, Сагитта. Спасибо тебе!";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = "А-а, это ты! Ты хочешь купить у меня рецептов зелий из мангаросы, так?";
				if (CheckCharacterItem(pchar, "cannabis7") && GetCharacterItem(pchar, "gold_dublon") >= 300)
				{
					link.l1 = "Именно. За этим я и пришел.";
					link.l1.go = "Sagitta_8";
				}
				link.l2 = "Пока нет, Сагитта. Просто заглянул проведать.";
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "Sagitta_next";
		break;
		
		case "Sagitta_8":
			dialog.text = "Очень хорошо. Какой рецепт ты хочешь приобрести?";
			if (!CheckAttribute(npchar, "quest.recipe_power"))
			{
				link.l1 = "Рецепт зелья силы и выносливости.";
				link.l1.go = "power";
			}
			if (!CheckAttribute(npchar, "quest.recipe_fast"))
			{
				link.l2 = "Рецепт зелья ловкости и неутомимости.";
				link.l2.go = "fast";
			}
			if (!CheckAttribute(npchar, "quest.recipe_total"))
			{
				link.l3 = "Рецепт комплексного зелья.";
				link.l3.go = "total";
			}
		break;
		
		case "power":
			dialog.text = "Хорошо. Я назвала его 'Удар прибоя'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Сагитта...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosapower");
			SetAlchemyRecipeKnown("mangarosapower");
			npchar.quest.recipe_power = true;
		break;
		
		case "fast":
			dialog.text = "Хорошо. Я назвала его 'Шквал'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Сагитта...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosafast");
			SetAlchemyRecipeKnown("mangarosafast");
			npchar.quest.recipe_fast = true;
		break;
		
		case "total":
			dialog.text = "Хорошо. Я назвала его 'Ласка моря'. Вот, возьми инструкцию приготовления. Следуй строго по рецепту. Не забывай о правилах применения!";
			link.l1 = "Спасибо, Сагитта...";
			link.l1.go = "recipe_exit";
			AddQuestRecordInfo("Recipe", "mangarosatotal");
			SetAlchemyRecipeKnown("mangarosatotal");
			npchar.quest.recipe_total = true;
		break;
		
		case "recipe_exit":
			DialogExit();
			NextDiag.CurrentNode = "Sagitta_next";
			RemoveItems(pchar, "gold_dublon", 300);
			RemoveItems(pchar, "cannabis7", 1);
			Log_Info("Вы отдали 300 дублонов и стебель мангаросы");
			PlaySound("interface\important_item.wav");
			if (CheckAttribute(npchar, "quest.recipe_power") && CheckAttribute(npchar, "quest.recipe_fast") && CheckAttribute(npchar, "quest.recipe_total"))
			{
				npchar.quest.recipe_all = true;
				CloseQuestHeader("mangarosa");
			}
		break;


	}
} 



