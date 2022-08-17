// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы?", "Что вам угодно, " + GetAddress_Form(NPChar) + "?"), "Совсем недавно вы пытались задать мне вопрос, " + GetAddress_Form(NPChar) + "...", "В течение этого дня вы уже третий раз говорите о каком-то вопросе...",
                          "Опять вопросы будем задавать?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я "+ GetSexPhrase("передумал","передумала") +"...", "Сейчас мне не о чем говорить"), "Хм, что-то с памятью моей стало...",
                      "Да уж, действительно в третий раз...", "Да нет, какие вопросы...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
		// Отступники веры
		if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_sailorSanAndres" && !CheckAttribute(npchar, "quest.APS_SailorSanAndres"))
		{
		link.l1 = "Послушай, дружище, не мог бы ты рассказать мне что-нибудь про того моряка, с которым я недавно сидел" + GetSexPhrase("","а") + " за одним столиком?";
		link.l1.go = "SailorSanAndres";
		}
		break;
		case "SailorSanAndres":
		dialog.text = "А-а, ты о Бальсемио Монтехо! Да что мне рассказать, господин капитан. Пьет безбожно каждый день, а как напьется до чертиков, все твердит, что скоро завяжет с пьянством и пойдёт служить в церковь. Каждый день одно и тоже!";
		if(sti(PChar.money) >= 1000)
		{
                                          PlaySound("VOICE\Russian\GOTHIC\GG_GELD\GELDBEUTEL.wav");
		AddMoneytoCharacter(PChar, -1000);
		link.l1 = "Спасибо тебе, " + NPChar.name + ", возьми ка вот 1000 песо, в наше время такие бескорыстные люди как ты - большая редкость.";
		link.l1.go = "exit";			
		}
		else
		{
		link.l1 = "Спасибо тебе, " + NPChar.name + ".";
		link.l1.go = "exit";
		}
	                     npchar.quest.APS_SailorSanAndres = "true";
	                     sld = characterFromId("ApostatesRK");
	                     sld.Dialog.CurrentNode = "second_168";	
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

