// Юрген Шмидт - оружейник
#include "DIALOGS\russian\Rumours\Common_rumours.c"
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int iTemp, iRem;
	DeleteAttribute(&Dialog,"Links");
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
	
	string NodeName = Dialog.CurrentNode;
	string NodePrevName = "";
	if (CheckAttribute(NextDiag, "PrevNode")) NodePrevName = NextDiag.PrevNode;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "GenQuest.NarvalConflict"))
			{
				dialog.text = "Послушайте, уважаемый, вы зачем руки так распустили, а? Пока вы с нами в ссоре - вам нечего делать в моей мастерской. Уходите!";
				link.l1 = "Гм...";
				link.l1.go = "exit";
				break;
			}
			if (npchar.quest.meeting == "0")
			{
				if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) // стал другом нарвалов
				{
					dialog.text = "А, "+GetFullName(pchar)+"! Наслышан, наслышан о ваших делах. Приятно, что вы стали другом Дональда и нашим сторонником. Нарвалы умеют ценить дружбу, это я вам говорю точно.";
					link.l1 = "Надеюсь, что это так. Я могу рассчитывать на ваши услуги?";
					link.l1.go = "friend";
				}
				else
				{
					dialog.text = "Ну? Чего тебе надо?";
					link.l1 = TimeGreeting()+". Меня зовут "+GetFullName(pchar)+". Я просто знакомлюсь с людьми. Я вас отрываю от дел?";
				link.l1.go = "meeting";
				}
				npchar.quest.meeting = "1";
			}
			else
			{
				if (CheckAttribute(pchar, "questTemp.LSC.nrv_friend")) // стал другом нарвалов
				{
					dialog.text = "А, "+GetFullName(pchar)+"! Наслышан, наслышан о ваших делах. Приятно, что вы стали другом Дональда и нашим сторонником. Нарвалы умеют ценить дружбу, это я вам говорю точно.";
					link.l1 = "Надеюсь, что это так. Теперь я могу рассчитывать на ваши услуги?";
					link.l1.go = "friend";
				}
				else
				{
					dialog.text = "А, "+GetFullName(pchar)+"! Опять поболтать захотелось? Ну, так я вас разочарую - нет у меня на это ни времени, ни желания.";
					link.l1 = "Хорошо, не буду вас отвлекать.";
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "First time";
		break;
		
		case "meeting": // первая встреча
			dialog.text = "Точно! Вы меня отрываете от дел, сударь. Я Юрген Шмидт, кузнец и оружейник нарвалов, и обеспечиваю наш клан оружием. Но чтобы сделать хороший клинок, или починить механизм башенного мушкетона, или сделать новый замок и ключ - нужно время, терпение и внимательность. Поэтому я не люблю, когда меня отвлекают от работы.";
			link.l1 = "Вы делаете оружие? А заказать у вас что-нибудь можно?";
			link.l1.go = "meeting_1";
		break;
		
		case "meeting_1":
			dialog.text = "Нет. Я делаю оружие только для членов клана нарвал. Это мой принцип, и я от него не отступлю ни на шаг. Так что не рассчитывайте, сударь. Вступите в клан нарвал, или, как минимум, станенете нашим союзником - тогда и приходите, поговорим.";
			link.l1 = "Ладно. Тогда я пойду. Извините, что побеспокоил!";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;
		
		case "friend":
			dialog.text = "Можете. Друг нарвалов - мой друг, так что можете высказывать свои пожелания.";
			link.l1 = "Я бы хотел изготовить клинок под заказ.";
			link.l1.go = "blade";
			if (CheckAttribute(npchar, "quest.narval_blade") && pchar.questTemp.LSC.Mary == "alive")
			{
				link.l2 = "Я слышал, вы изготовили для покойного Алана Милроу особый клинок. Я видел этот палаш - великолепное оружие. Я мог бы у вас заказать себе такой же?";
				link.l2.go = "narval";
			}
			link.l3 = "Пока никаких пожеланий нет, ничего в голову не приходит. Подумаю - и обязательно вернусь!.";
			link.l3.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		
		case "Jurgen":
			if (pchar.questTemp.LSC == "return" && !CheckAttribute(npchar, "quest.return_isl"))
			{
				dialog.text = "Ха, "+GetFullName(pchar)+"! Так ты не утонул? Вот это да! Ты точно не мертвец?";
				link.l1 = "Не беспокойся, Юрген. Живой! Я тонуть и не собирался - это вы тут напридумывали невесть чего...";
				link.l1.go = "exit";
				npchar.quest.return_isl = "true";
				NextDiag.TempNode = "Jurgen";
				break;
			}
			dialog.text = "А, "+GetFullName(pchar)+"! По какому делу пожаловали?";
			if (CheckAttribute(npchar, "quest.narval_blade") && npchar.quest.narval_blade == "ferrum")
			{
				if (GetCharacterItem(pchar, "jewelry11") >= 3)
				{
					link.l4 = "Я принес три куска особого железа, как вы и просили. Гляньте - это оно?";
					link.l4.go = "narval_7";
				}
				if (CheckCharacterItem(pchar, "meteorite"))
				{
					link.l5 = "Гляньте сюда, Юрген. Я нашел интересный слиток железа на дне, но он весит гораздо больше, чем вы говорили - в нем не меньше пяти фунтов.";
					link.l5.go = "narval_7_1";
				}
			}
			if (CheckAttribute(pchar, "quest.narval_dla_charla") && !CheckAttribute(pchar, "quest.bestnarval") && !CheckAttribute(npchar, "quest.klinok_best_narval") && !CheckAttribute(npchar, "quest.narval_zakaz_gotov"))
			{
			link.l10 = "Юрген, я всё же хочу вернуться к разговору про 'Нарвал'. Я перейду сразу к делу. Скажем 7000 дублонов будет достаточно, чтобы вы забыли про свои причуды? ";
			link.l10.go = "blade_best_narval";
			}
			if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && CheckAttribute(npchar, "quest.klinok_best") && !CheckAttribute(npchar, "quest.klinok_best_next"))
			{
             	link.l1 = "Я хочу снова заказать клинок за 5000 дублонов.";
				link.l1.go = "blade_bext";
            }
            if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && CheckAttribute(npchar, "quest.klinok_best_next_two") && !CheckAttribute(npchar, "quest.klinok_best_next"))		
            {
             	link.l1 = "Я хочу снова заказать клинок за 5000 дублонов.";
				link.l1.go = "blade_bext";
            }			
			if (!CheckAttribute(npchar, "quest.blade_done") && !CheckAttribute(npchar, "quest.klinok_best")) // чтобы не повторялся
			{
				link.l1 = "Я бы хотел изготовить клинок под заказ.";
				if (!CheckAttribute(npchar, "quest.blade_rules") && !CheckAttribute(npchar, "quest.blade_ruless")) link.l1.go = "blade";
				else link.l1.go = "blade_4";
			}
			/*if (CheckAttribute(npchar, "quest.klinok_pervii_zakaz") && !CheckAttribute(npchar, "quest.blade_done"))
			{
            link.l1 = "Я бы хотел изготовить клинок за 1000 дублонов.";	
             link.l1.go = "blade_4";
			}	*/		 
			if (CheckAttribute(npchar, "quest.blade_payseekss"))
			{	
			    link.l1 = "Я принес еще дублонов в счет оплаты за отличный клинок.";
				link.l1.go = "blade_30";
	        }
             if (CheckAttribute(npchar, "quest.blade_payseekssnarval"))//&& CheckAttribute(npchar, "quest.narval_zakaz_gotov")) //хз
			{	
			    link.l1 = "Я принес еще дублонов в счет оплаты за 'Нарвал'.";   
				link.l1.go = "blade_300";
	        }			
			if (CheckAttribute(npchar, "quest.blade_payseek"))
			{
				link.l1 = "Я принес еще дублонов в счет оплаты за клинок.";
				link.l1.go = "blade_3";
			}
			if (CheckAttribute(npchar, "quest.narval_blade") && pchar.questTemp.LSC.Mary == "alive" && npchar.quest.narval_blade == "begin" && pchar.questTemp.LSC != "return") // patch-9
			{
				link.l2 = "Я слышал, вы изготовили для покойного Алана Милроу особый клинок. Я видел этот палаш - великолепное оружие. Я мог бы у вас заказать себе такой же?";
				link.l2.go = "narval";
			}
			if (CheckAttribute(npchar, "blade_date") && GetNpcQuestPastDayParam(npchar, "blade_date") >= 5)
			{
				link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
				link.l1.go = "blade_done_2";
			}
			if (CheckAttribute(npchar, "palash_date_1") && GetNpcQuestPastDayParam(npchar, "palash_date_1") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "P_1";	
            }
             if (CheckAttribute(npchar, "palash_date_2") && GetNpcQuestPastDayParam(npchar, "palash_date_2") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "P_2";	
            }
              if (CheckAttribute(npchar, "palash_date_3") && GetNpcQuestPastDayParam(npchar, "palash_date_3") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "P_3";	
            }
              if (CheckAttribute(npchar, "palash_date_4") && GetNpcQuestPastDayParam(npchar, "palash_date_4") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "P_4";	
            }
            if (CheckAttribute(npchar, "sabla_date_1") && GetNpcQuestPastDayParam(npchar, "sabla_date_1") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_1";	
            }
             if (CheckAttribute(npchar, "sabla_date_2") && GetNpcQuestPastDayParam(npchar, "sabla_date_2") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_2";	
            }
             if (CheckAttribute(npchar, "sabla_date_3") && GetNpcQuestPastDayParam(npchar, "sabla_date_3") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_3";	
            }
             if (CheckAttribute(npchar, "sabla_date_4") && GetNpcQuestPastDayParam(npchar, "sabla_date_4") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_4";	
            }
             if (CheckAttribute(npchar, "sabla_date_5") && GetNpcQuestPastDayParam(npchar, "sabla_date_5") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_5";	
            }
             if (CheckAttribute(npchar, "sabla_date_6") && GetNpcQuestPastDayParam(npchar, "sabla_date_6") >= 2)
			{
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "S_6";	
            }
             if (CheckAttribute(npchar, "rapira_date_1") && GetNpcQuestPastDayParam(npchar, "rapira_date_1") >=2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_1";	
            }
            if (CheckAttribute(npchar, "rapira_date_2") && GetNpcQuestPastDayParam(npchar, "rapira_date_2") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_2";	
            }
            if (CheckAttribute(npchar, "rapira_date_3") && GetNpcQuestPastDayParam(npchar, "rapira_date_3") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_3";	
            }
             if (CheckAttribute(npchar, "rapira_date_4") && GetNpcQuestPastDayParam(npchar, "rapira_date_4") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_4";	
            }
             if (CheckAttribute(npchar, "rapira_date_5") && GetNpcQuestPastDayParam(npchar, "rapira_date_5") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_5";	
            }
			if (CheckAttribute(npchar, "rapira_date_6") && GetNpcQuestPastDayParam(npchar, "rapira_date_6") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_6";	
            }
			if (CheckAttribute(npchar, "rapira_date_7") && GetNpcQuestPastDayParam(npchar, "rapira_date_7") >= 2)
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_7";	
            }
			if (CheckAttribute(npchar, "rapira_date_8") && GetNpcQuestPastDayParam(npchar, "rapira_date_8") >= 2) // менять 
            {
                link.l1 = "Я пришел за своим заказом. Он уже должен быть готов, как я понимаю?";
			    link.l1.go = "R_8";	//менять
            }
            if (CheckAttribute(npchar, "narval_best_date_1") && GetNpcQuestPastDayParam(npchar, "narval_best_date_1") >= 3)
            {
               link.l1 = "Я пришел за своим 'Нарвалом'. Он уже должен быть готов, как я понимаю?";
			   link.l1.go = "N_1";		
            }
             if (CheckAttribute(npchar, "narval_best_date_2") && GetNpcQuestPastDayParam(npchar, "narval_best_date_2") >= 3)
            {
               link.l1 = "Я пришел за своим 'Нарвалом'. Он уже должен быть готов, как я понимаю?";
			   link.l1.go = "N_2";
            }
             if (CheckAttribute(npchar, "narval_best_date_3") && GetNpcQuestPastDayParam(npchar, "narval_best_date_3") >= 3)
            {
               link.l1 = "Я пришел за своим 'Нарвалом'. Он уже должен быть готов, как я понимаю?";
			   link.l1.go = "N_3";
            }						
			link.l3 = "Да нет, ничего, просто зашел поздороваться.";
			link.l3.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_300":
			dialog.text = "Тогда жду оплаты за 'Нарвал'!";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "Вот, пожалуйста. У меня есть с собой "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pays_narval";
			}
			link.l2 = "Хм. У меня сейчас их с собой нет, к сожалению. Но я обязательно принесу, и мы вернемся к этому разговору.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
			npchar.quest.blade_payseekssnarval = "true";
		break;
		case "blade_best_narval":
		dialog.text = "Вы сказали... 7000 дублонов??! Уважаемый, за такие деньги я готов забыть все свои принципы! Уверяю вас, это будет самый лучший 'Нарвал'! Я даже сам сплаваю на дно за куском донного железа для него, ибо всем хорошо известно какой есть костюм у Механика. Да за 7000 дублонов я даже крабов не боюсь уже! Значит, Вы согласны? ";
		link.l1 = "Да, я согласен!";
		link.l1.go = "blade_300";
		NextDiag.TempNode = "Jurgen";	
		npchar.quest.blade_dublon = 7000;
		npchar.quest.narval_zakaz_gotov = "true";	// чтобы не было возврата к началу разговора про нарвал.
			
		break;
		case "blade_pays_narval": // оплата
			 npchar.quest.klinok_best_narval = "true"; // чтобюы не было возврата к началу разговора про нарвал 
          
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // полная сумма
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // запоминаем остаток
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("Вы отдали "+sti(npchar.quest.blade_pay)+" дублонов");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "Отлично. Теперь, когда вы оплатили мою работу и материалы, я могу приступить к делу.";
				link.l1 = "Я могу делать заказ?";
				link.l1.go = "narval_za_7000";
			}
			else
			{
				dialog.text = "Хорошо. Я принимаю у вас дублоны. Вам осталось принести еще "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "Как только соберу еще дублонов - немедленно принесу вам.";
				link.l1.go = "exit";
                npchar.quest.blade_payseekssnarval = "true";				
			}
		break;
		case "N_1":
		    dialog.text = "Да. Ваш 'Нарвал' готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него 7000 дублонов!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 2.0;
			sld.Weight = 3.5;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_1");
			pchar.quest.bestnarval = "true";
			Log_Info("Вы получили от Юргена 'Нарвал'!");
		break;
		case "N_2":
		    dialog.text = "Да. Ваш 'Нарвал' готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него 7000 дублонов!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 1.9;
			sld.Weight = 3.4;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_2");
			pchar.quest.bestnarval = "true";
			Log_Info("Вы получили от Юргена 'Нарвал'!");
		break;
		case "N_3":
		    dialog.text = "Да. Ваш 'Нарвал' готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него 7000 дублонов!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "blade_31");
			sld = ItemsFromID("blade_31"); 
			sld.Balance = 1.8;
			sld.Weight = 3.3;
			sld.Attack = 120.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "narval_best_date_3");
			pchar.quest.bestnarval = "true";
			Log_Info("Вы получили от Юргена 'Нарвал'!");
		break;
		case "R_1":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;
			sld.Weight = 2.4;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next"); //npchar.quest.klinok_best_next = "true";
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_2": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // характеристики
			sld.Weight = 2.0;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_2");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_3": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.5;  // характеристики
			sld.Weight = 2.2;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_3");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_4": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // характеристики
			sld.Weight = 2.3;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_4");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_5": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;  // характеристики
			sld.Weight = 2.1;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_5");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_6": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.5;  // характеристики
			sld.Weight = 2.5;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_6");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_7": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.3;  // характеристики
			sld.Weight = 2.6;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_7");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "R_8": //менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_18");
			sld = ItemsFromID("q_blade_18"); 
			sld.Balance = 0.4;  // характеристики
			sld.Weight = 2.7;
			sld.Attack = 70.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "rapira_date_8");//менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_1":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.3;
			sld.Weight = 3.3;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_2":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.6;
			sld.Weight = 3.0;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_2");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_3":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.4;
			sld.Weight = 3.2;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_3");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_4":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.5;
			sld.Weight = 3.1;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_4");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_5":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.1;
			sld.Weight = 3.0;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_5");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "S_6":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_19");
			sld = ItemsFromID("q_blade_19"); 
			sld.Balance = 1.5;
			sld.Weight = 3.4;
			sld.Attack = 90.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "sabla_date_6");
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "P_1":
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от всей души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.5;
			sld.Weight = 4.0;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_1");
			DeleteAttribute(npchar, "quest.klinok_best_next");  // временной интервал . при получении клинка - удаление . ставить везде ,кроме нарвала
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "P_2":                                                 // менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 2.0;                                     //харки
			sld.Weight = 3.5;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_2"); 
            DeleteAttribute(npchar, "quest.klinok_best_next");			//интервал
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "P_3":                                                 // менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.8;                                     //харки 110/3.7/1.8
			sld.Weight = 3.7;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_3");            //менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "P_4":                                                 // менять
		    dialog.text = "Да. Ваш клинок готов. Пожалуйста, получите и владейте на здоровье. Как только вы возьмете его в руки, сразу поймете, что он стоит затраченных на него денег!";
			link.l1 = "Юрген, от души благодарю!";
			link.l1.go = "exit";
			GiveItem2Character(pchar, "q_blade_21");
			sld = ItemsFromID("q_blade_21"); 
			sld.Balance = 1.7;                                     //харки 
			sld.Weight = 3.8;
			sld.Attack = 110.0;
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "palash_date_4");            //менять
			DeleteAttribute(npchar, "quest.klinok_best_next");
			Log_Info("Вы получили от Юргена свой клинок!");
		break;
		case "narval_za_7000":
		DeleteAttribute(npchar, "quest.blade_payseekssnarval");  // удаление диалога - я принес оплату за нарвал.
		dialog.text = "Итак, какие желаете для 'Нарвала' атаку, вес и баланс?";
         link.l1 = "Я хочу 'Нарвал' с характеристиками 120 / 3.5 / 2.0";
         link.l1.go = "best_narval_1";
         link.l2 = "Я хочу 'Нарвал' с характеристиками 120 / 3.4 / 1.9";
         link.l2.go = "best_narval_2";
         link.l3 = "Я хочу 'Нарвал' с характеристиками 120 / 3.3 / 1.8 ";
         link.l3.go = "best_narval_3";
        break;	
        
        case "best_narval_1":
	    	Log_Info("Вы заказали 'Нарвал' у Юргена за 7000 дублонов");
		    dialog.text = "Как скажете. За заказом приходите через пару дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "best_narval_2":
	    	Log_Info("Вы заказали 'Нарвал' у Юргена за 7000 дублонов");
		    dialog.text = "Как скажете. За заказом приходите через пару дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "best_narval_3":
	    	Log_Info("Вы заказали 'Нарвал' у Юргена за 7000 дублонов");
		    dialog.text = "Как скажете. За заказом приходите через пару дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "narval_best_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
       		
		// --> заказ клинков
		case "blade":
			dialog.text = "Хорошо. Но у меня есть определенные требования к заказу, так что выслушайте сначала, а потом решайте - заказывать, или нет.";
			link.l1 = "Я вас внимательно слушаю.";
			link.l1.go = "blade_1";
		break;
		
		case "blade_1":
			dialog.text = "Я могу вам выковать хороший клинок за 1000 дублонов. Какие будут характеристики клинка, зависит от материала. Но сразу скажу - за 1000 так себе будут.  Но есть ещё улучшенные, отличные, клинки с характеристиками на выбор. Стоят 5000 дублонов. И такой можно будет заказать неоднократно, а сколько захотите, но по очереди. Деньги Вперед. Что выбираешь?";
			link.l1 = "Тогда выберу клинок за 1000 дублонов.";
			link.l1.go = "blade_2";
			link.l3 = "Я хочу заказать отличный клинок за 5000 дублонов!";
			link.l3.go = "blade_bext";
			npchar.quest.klinok_pervii_zakaz = "true";
			
		break;
		case "blade_bext":
		dialog.text = "Очень хорошо. оплатить можно частями. срок изготовления через один день. Вы согласны?";
		link.l1 = "Да, я согласен!";
		link.l1.go = "blade_30";
		NextDiag.TempNode = "Jurgen";	
		npchar.quest.blade_dublon = 5000;
			
		break;
		
			
			
		case "blade_2":
			dialog.text = "Договорились, сделаю вам клинок за 1000 дублонов. Особого качества, конечно, не ожидайте. Но клинок будет хороший!";
			link.l1 = "Тогда я сделаю заказ.";
			link.l1.go = "blade_3";
			link.l2 = "Хм. Пожалуй, мне стоит хорошенько подумать, прежде чем решиться на заказ. Вернемся к этому разговору позже!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
			npchar.quest.blade_rules = "true";
			npchar.quest.blade_dublon = 1000;
			AddQuestRecord("LSC", "17");
		break;
		
		case "blade_3":
			dialog.text = "Очень хорошо. Тогда давайте ваши дублоны.";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "Вот, пожалуйста. У меня есть с собой "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pay";
			}
			link.l2 = "Хм. У меня сейчас их с собой нет, к сожалению. Но я обязательно принесу, и мы вернемся к этому разговору.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_30":
			dialog.text = "Очень хорошо. Тогда давайте ваши дублоны.";
			if (CheckCharacterItem(pchar, "gold_dublon"))
			{
				npchar.quest.blade_pay = GetCharacterItem(pchar, "gold_dublon");
				link.l1 = "Вот, пожалуйста. У меня есть с собой "+FindRussianQtyString(sti(npchar.quest.blade_pay))+".";
				link.l1.go = "blade_pays";
			}
			link.l2 = "Хм. У меня сейчас их с собой нет, к сожалению. Но я обязательно принесу, и мы вернемся к этому разговору.";
			link.l2.go = "exit";
			NextDiag.TempNode = "Jurgen";
		break;
		case "blade_4":
			dialog.text = "Вы все-таки сделали свой выбор? Хорошо подумали?";
			link.l1 = "Да. Я полностью определился.";
			link.l1.go = "blade_3";
		break;
		case "blade_pays": // оплата
		     npchar.quest.klinok_best = "true"; // чтобы не повторял вступление что я могу то то и то т о 
			 npchar.quest.klinok_best_next = "true"; // для интервала между заказами за 5000к 
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // полная сумма
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // запоминаем остаток
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("Вы отдали "+sti(npchar.quest.blade_pay)+" дублонов");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "Отлично. Теперь, когда вы оплатили мою работу и материалы, я могу приступить к делу.";
				link.l1 = "Я могу делать заказ?";
				link.l1.go = "blade_dones";
			}
			else
			{
				dialog.text = "Хорошо. Я принимаю у вас дублоны. Вам осталось принести еще "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "Как только соберу еще дублонов - немедленно принесу вам.";
				link.l1.go = "exit";
				npchar.quest.blade_payseekss = "true";
				
			}
		break;
		
		case "blade_dones":
		DeleteAttribute(npchar, "quest.blade_payseekss");
		dialog.text = "Итак, какой клинок выбираете? палаш, саблю, или рапиру?";
		link.l1 = "Выбираю палаш, люблю рубить головы врагов пополам!";
		link.l1.go = "best_palash";
		link.l2 = "Выбираю саблю, буду отсекать руки да ноги вражинам!";
		link.l2.go = "best_sabla";
		link.l3 = "Выбираю рапиру, проколоть дырку в пузе врага самое то!";
		link.l3.go = "best_rapira";
		
		break;
		case "best_palash":
		dialog.text = "Какие характеристики палаша выбираете? атака / вес / баланс ? ";
		link.l1 = "Выбираю палаш с характеристиками  110 / 4.0 / 1.5";
		link.l1.go = "palash_1";
		link.l2 = "Выбираю палаш с характеристиками  110 / 3.5 / 2.0";
		link.l2.go = "palash_2";
		link.l3 = "Выбираю палаш с характеристиками  110 / 3.7 / 1.8";
		link.l3.go = "palash_3";
		link.l4 = "Выбираю палаш с характеристиками  110 / 3.8 / 1.7";
		link.l4.go = "palash_4";
		
		break;
		case "best_rapira":
		dialog.text = "Какие характеристики рапиры выбираете? атака / вес / баланс ? ";
		link.l1 = "Выбираю рапиру с характеристиками  70 / 2.4 / 0.4";
		link.l1.go = "rapira_1";
		link.l2 = "Выбираю рапиру с характеристиками  70 / 2.0 / 0.3";
		link.l2.go = "rapira_2";
		link.l3 = "Выбираю рапиру с характеристиками  70 / 2.2 / 0.5";
		link.l3.go = "rapira_3";
		link.l4 = "Выбираю рапиру с характеристиками  70 / 2.3 / 0.3";
		link.l4.go = "rapira_4";
		link.l5 = "Выбираю рапиру с характеристиками  70 / 2.1 / 0.4";
		link.l5.go = "rapira_5";
		link.l6 = "Выбираю рапиру с характеристиками  70 / 2.5 / 0.5";
		link.l6.go = "rapira_6";
		link.l7 = "Выбираю рапиру с характеристиками  70 / 2.6 / 0.3";
		link.l7.go = "rapira_7";
		link.l8 = "Выбираю рапиру с характеристиками  70 / 2.7 / 0.4";
		link.l8.go = "rapira_8";
         		
         		
		break;
		
		case "best_sabla":
		dialog.text = "Какие характеристики сабли выбираете? атака / вес / баланс ? ";
		link.l1 = "Выбираю саблю с характеристиками  90 / 3.3 / 1.3";
		link.l1.go = "sabla_1";
		link.l2 = "Выбираю саблю с характеристиками  90 / 3.0 / 1.6";
		link.l2.go = "sabla_2";
		link.l3 = "Выбираю саблю с характеристиками  90 / 3.2 / 1.4";
		link.l3.go = "sabla_3";
		link.l4 = "Выбираю саблю с характеристиками  90 / 3.1 / 1.5";
		link.l4.go = "sabla_4";
        link.l5 = "Выбираю саблю с характеристиками  90 / 3.0 / 1.1";
		link.l5.go = "sabla_5";
        link.l6 = "Выбираю саблю с характеристиками  90 / 3.4 / 1.5";
		link.l6.go = "sabla_6";			
			
		break;
		case "rapira_1":
		Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_2":
		Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_3":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_4":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_4");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_5":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_5");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_6":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_6");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_7":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_7");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "rapira_8":  //менять
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "rapira_date_8");//менять
			NextDiag.CurrentNode = "Jurgen";
		break;
		
		case "sabla_1":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_2":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_2");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_3":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_3");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_4":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_4");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_5":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_5");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "sabla_6":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "sabla_date_6");
			NextDiag.CurrentNode = "Jurgen";
		break;
		
		
		case "palash_1":
		    Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_1");
			NextDiag.CurrentNode = "Jurgen";
		break;
		case "palash_2":
			Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_2");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		case "palash_3":
			Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_3");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		case "palash_4":
			Log_Info("Вы заказали клинок у Юргена за 5000 дублонов!");
		    dialog.text = "Как скажете. За заказом приходите через один день, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			SaveCurrentNpcQuestDateParam(npchar, "palash_date_4");
			NextDiag.CurrentNode = "Jurgen";	
		break;
		
		
		case "blade_pay": // оплата
		    npchar.quest.klinok_best_next_two = "true";
			if (sti(npchar.quest.blade_dublon) < sti(npchar.quest.blade_pay)) // полная сумма
			{
				npchar.quest.blade_pay = sti(npchar.quest.blade_dublon);
				iTemp = 0;
			}
			else iTemp = sti(npchar.quest.blade_dublon)-sti(npchar.quest.blade_pay);
			npchar.quest.blade_dublon = iTemp; // запоминаем остаток
			RemoveItems(pchar, "gold_dublon", sti(npchar.quest.blade_pay));
			Log_Info("Вы отдали "+sti(npchar.quest.blade_pay)+" дублонов");
			PlaySound("interface\important_item.wav");
			if (iTemp == 0)
			{
				dialog.text = "Отлично. Теперь, когда вы оплатили мою работу и материалы, я могу приступить к делу.";
				link.l1 = "Я могу делать заказ?";
				link.l1.go = "blade_done";
			}
			else
			{
				dialog.text = "Хорошо. Я принимаю у вас дублоны. Вам осталось принести еще "+FindRussianQtyString(sti(npchar.quest.blade_dublon))+".";
				link.l1 = "Как только соберу еще дублонов - немедленно принесу вам.";
				link.l1.go = "exit";
				npchar.quest.blade_payseek = "true";
			}
		break;
		
		case "blade_done":
			DeleteAttribute(npchar, "quest.blade_payseek");
			dialog.text = "Конечно! Какая группа вам по душе - рапиры, сабли или палаши?";
			link.l1 = "Рапиры. Люблю изящное легкое оружие.";
			link.l1.go = "rapier";
			link.l2 = "Сабли. Это оптимальный вариант с моей точки зрения.";
			link.l2.go = "sabre";
			link.l3 = "Конечно же, палаши! Рубить так рубить, как говорится!";
			link.l3.go = "palash";
		break;
		
		case "rapier":
			npchar.quest.blade_done = SelectJurgenBladeDone("rapier");
			dialog.text = "Как скажете. За заказом приходите через пять дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			link.l1.go = "blade_done_1";
		break;
		
		case "sabre":
			npchar.quest.blade_done = SelectJurgenBladeDone("sabre");
			dialog.text = "Как скажете. За заказом приходите через пять дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			link.l1.go = "blade_done_1";
		break;
		
		case "palash":
			npchar.quest.blade_done = SelectJurgenBladeDone("palash");
			dialog.text = "Как скажете. За заказом приходите через пять дней, не раньше.";
			link.l1 = "Спасибо! Буду в указанное время. До свидания, Юрген.";
			link.l1.go = "blade_done_1";
		break;
		
		case "blade_done_1":
			DialogExit();
			SaveCurrentNpcQuestDateParam(npchar, "blade_date");
			NextDiag.CurrentNode = "Jurgen";
			AddQuestRecord("LSC", "18");
		break;
		
		case "blade_done_2":
			dialog.text = "Да. Ваш клинок готов. Заранее извиняюсь если что не так. Пьяный был я просто. Но в общем что то получилось...Сразу говорю, особо не старался за 1000 дублонов..мде.";
			link.l1 = "Эх...ну что ж поделать. Ладно, спасибо и на том, Юрген.";
			link.l1.go = "blade_done_3";
		break;
		
		case "blade_done_3":
			DialogExit();
			NextDiag.CurrentNode = "Jurgen";
			GiveItem2Character(pchar, npchar.quest.blade_done);
			PlaySound("interface\important_item.wav");
			DeleteAttribute(npchar, "blade_date");
		break;
		
		// заказ палаша Нарвал для Мэри
		case "narval":
			dialog.text = "Увы, дружище, но тут я вам вынужден отказать по двум причинам. Во-первых, такой палаш я возьмусь делать только для члена клана нарвал, и то - не для каждого. А во-вторых, у меня нет материала для его изготовления.";
			link.l1 = "А что за особое железо для него нужно? Я слышал, что его доставали со дна...";
			link.l1.go = "narval_1";
		break;
		
		case "narval_1":
			dialog.text = "Именно так. Куски этого железа разбросаны на нашем мелководье. Откуда они тут взялись - мне неведомо. Но железо действительно уникальное - не ржавеет вообще, а клинки из него не тупятся. Так что если бы вы каким-то образом достали это железо - можно было бы решить вопрос. Но опять же проблема - вы не нарвал...";
			link.l1 = "Хм. А то, что я не нарвал - это имеет настолько принципиальное значение?";
			link.l1.go = "narval_2";
		break;
		
		case "narval_2":
			dialog.text = "Да. Воспринимайте это как мою причуду, если хотите, но такой палаш я буду делать только для нарвала.";
			link.l1 = "Так... Ладно, приму, как неизбежность. Но у меня возникла другая мысль. А могу ли я заказать этот клинок в подарок для члена клана нарвал?";
			link.l1.go = "narval_3";
		break;
		
		case "narval_3":
			dialog.text = "Гм. Ну, если вы принесете мне железо для изготовления, то наверное, да. Это никак не будет противоречить принципу... А для кого вы хотите сделать этот палаш?";
			link.l1 = "Для Красной Мэри. Она из клана нарвал, и вполне заслуживает право владеть таким замечательным оружием.";
			link.l1.go = "narval_4";
		break;
		
		case "narval_4":
			dialog.text = "Ха! Я мог бы догадаться и сам. Старею... Ну что же, я согласен. Мэри будет просто в восторге от такого подарка, я уверен... Несите железо - и я сделаю палаш. За работу я возьму... а, впрочем, ничего не надо. Пусть это будет подарок не только от вас, но и от меня.";
			link.l1 = "Спасибо! Сколько вам нужно железа для его изготовления?";
			link.l1.go = "narval_5";
		break;
		
		case "narval_5":
			dialog.text = "Куски, которые находили на дне, были все примерно одинакового размера - по фунту с небольшим. Мне нужно три куска.";
			link.l1 = "Хорошо. Я постараюсь добыть их. Тогда и вернемся к нашему разговору.";
			link.l1.go = "narval_6";
		break;
		
		case "narval_6":
			DialogExit();
			npchar.quest.narval_blade = "ferrum";
			NextDiag.CurrentNode = "Jurgen";
			// кладем гигантский кусок метеорита на дно
			sld = ItemsFromID("meteorite");
			sld.shown = true;
			sld.startLocation = "underwater";
			sld.startLocator = "item"+(rand(7)+1);
			Log_TestInfo("Метеорит в локаторе" + sld.startLocator);
			pchar.quest.LSC_narval_ferrum.win_condition.l1 = "item";
			pchar.quest.LSC_narval_ferrum.win_condition.l1.item = "meteorite";
			pchar.quest.LSC_narval_ferrum.function = "LSC_NarvalFerrum";
			AddQuestRecord("LSC", "19");
		break;
		
		case "narval_7":
			RemoveItems(pchar, "jewelry11", 3);
			PlaySound("interface\important_item.wav");
			dialog.text = "Ну-ка, покажите... Да, точно - оно! Это было трудно - отыскать такие небольшие куски на дне?";
			link.l1 = "Ну, как сказать... Но ради Мэри ведь можно было постараться, не так ли?";
			link.l1.go = "narval_8";
			pchar.quest.LSC_narval_ferrum.over = "yes"; //снять прерывание
		break;
		
		case "narval_7_1":
			RemoveItems(pchar, "meteorite", 1);
			PlaySound("interface\important_item.wav");
			dialog.text = "Ну-ка, покажите... Ого! Да, это то самое донное железо, но таких огромных кусков я еще не видал. Его одного с лихвой хватит для изготовления палаша. Это было, наверное, трудно - найти его?";
			link.l1 = "Ну, как сказать... Но ради Мэри ведь можно было постараться, не так ли?";
			link.l1.go = "narval_8";
		break;
		
		case "narval_8":
			dialog.text = "Вы нравитесь мне все больше и больше, "+pchar.name+"... Ну что же, отлично. Теперь пришло время и мне постараться для нашей прекрасной амазонки. Работа займет два дня - я оставлю все прочие заказы и займусь палашом\nПриходите послезавтра ко мне вдвоем с Мэри. Только не говорите ей ничего заранее - сделаем сюрприз. Она будет радоваться, как ребенок.";
			link.l1 = "Хорошо, Юрген. Договорились. Тогда - до послезавтра!";
			link.l1.go = "narval_9";
		break;
		
		case "narval_9":
			DialogExit();
			npchar.quest.narval_blade = "work";
			NextDiag.CurrentNode = "narval_10";
			SetFunctionTimerCondition("LSC_NarvalBladeForMary", 0, 0, 2, false); // таймер
			AddQuestRecord("LSC", "21");
		break;
		
		case "narval_10":
			dialog.text = ""+pchar.name+", не отвлекайте меня. Вы же хотите, чтобы палаш был готов вовремя?";
			link.l1 = "Да, конечно. Я уже ухожу...";
			link.l1.go = "exit";
			NextDiag.TempNode = "narval_10";
		break;
		
//----------------------------------------- специальные реакции -----------------------------------------------
		//обнаружение ГГ в сундуках
		case "Man_FackYou":
			dialog.text = LinkRandPhrase("Что ты там копаешься, а? Да ты вор!", "Вот это да! Чуть я загляделся, а ты сразу в сундук с головой!", "По сундукам шарить вздумал?! Тебе это даром не пройдет!");
			link.l1 = "А-ать, дьявол!!!";
			link.l1.go = "fight";
		break;
		
		case "fight":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LAi_SetOwnerTypeNoGroup(npchar);
			LAi_group_Attack(NPChar, Pchar);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		//замечание по обнаженному оружию
		case "LSCNotBlade":
			dialog.text = LinkRandPhrase("Слушай, ты бы убрал оружие. А то нервируешь немного...", "Знаешь, у нас тут не принято сабелькой размахивать. Убери оружие.", "Слушай, что ты, как д'Артаньян, бегаешь тут, шпагой машешь? Убери оружие, не к лицу это серьезному мужчине...");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажешь...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;	
		
		case "CitizenNotBlade":
			if (loadedLocation.type == "town")
			{
				dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнаженным клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнаженным клинком.");
				link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			}
			else
			{
				dialog.text = NPCharSexPhrase(NPChar, "Острожней на поворотах, приятель, когда бежишь с оружием в руках. Я ведь могу и занервничать...", "Мне не нравится, когда мужчины ходят передо мной с оружием на изготовку. Это меня пугает...");
				link.l1 = RandPhraseSimple("Понял.", "Убираю.");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "First Time";
		break;
// <-- специальные реакции
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
string SelectJurgenBladeDone(string _sType)
{
	string sBlade;
	switch (_sType)
	{
		case "rapier":			
			if (sti(pchar.rank) > 21) sBlade = "q_blade_16"; 
			else sBlade = "q_blade_16";
		   
		break;
		
		case "sabre":
			if (sti(pchar.rank) > 21) sBlade = "q_blade_10"; 
			else sBlade = "q_blade_10";
		break;
		
		case "palash":
			if (sti(pchar.rank) > 21) sBlade = "q_blade_13"; 
			else sBlade = "q_blade_13";			
		break;
	}
	return sBlade;
}