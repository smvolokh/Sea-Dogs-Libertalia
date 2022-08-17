// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("Какие вопросы, "+ GetSexPhrase("сын мой","дочь моя") +"?", "Спрашивай, я слушаю тебя..."), "Я слушаю тебя, говори, "+ GetSexPhrase("сын мой","дочь моя") +"...", "И в третий раз говорю тебе, "+ GetSexPhrase("сын мой","дочь моя") +": задавай свой вопрос.",
                          "Столько обязанностей у церковнослужителя, а тут еще и ты донимаешь, "+ GetSexPhrase("сын мой","дочь моя") +"...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("Я передумал...", "Не сейчас, падре..."), "Да, пока особо и нечего сказать...",
                      "Задам, задам... Только позже...", "Простите, святой отец...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

		// Отступники веры Чарли Вейн -->
	if(CheckAttribute(pchar, "questTemp.APS") && pchar.questTemp.APS == "APS_ChurchVayne" && !CheckAttribute(npchar, "quest.APS_ChurchVayne"))
	{
		link.l1 = "Святой Отец, я хочу поговорить с Вами о капитане Вейне. Я чту церковные законы и прекрасно понимаю, что такое тайна исповеди - но недавние убийства заставляют мня задать вам этот вопрос: Не приходилось ли вам когда-либо общаться с Чарли Вейном?";
		link.l1.go = "CharlieVayne_1";
	}
	if (pchar.questTemp.State == "MorrisWillams_ArrestedSeekInfo" || pchar.questTemp.State == "MorrisWillams_ArrestedSeekInfoFather")
            {
                link.l1 = "Святой отец, скажите мне, местный ростовщик ваш прихожанин?";
                link.l1.go = "Step_E6_1";
            }

		break;

		// Чарли Вейн -->
		case "CharlieVayne_1":
		dialog.text = "Даже самые отъявленные негодяи иногда ищут совета в церкви. Нет, мне никогда не доводилось встречаться с тем, о ком ты говоришь. Однако, мне есть, что тебе рассказать\nКапитан, вам стоит поговорить с неким Гариссом О'Мэйли - сейчас он фермер живет и работает на плантациях Гваделупы. Теперь уже он снял с себя церковный сан - но когда-то он был священником, а я был его духовником\nОн рассказывал мне о том, что ему доводилось беседовать с Вейном. Вы понимаете, капитан, что я не могу передать вам содержание наших бесед. Но сам Гаррис может это сделать, если сочтет  нужным. По крайней мере, попытайтесь с ним поговорить.";
		link.l1 = "Спасибо. До свидания, святой отец.";
		link.l1.go = "exit";
	                     AddQuestRecord("APSH", "2");
	                     npchar.quest.APS_ChurchVayne = "true";
		AddDialogExitQuestFunction("CharlieVayneStart");
		break;
		// <-- Чарли Вейн

                                     case "Step_E6_1":
		dialog.text = "Да, он посещает церковь, но очень редко.";
		link.l1 = "Что он за человек?";
		link.l1.go = "Step_E6_2";
		break;

                                    case "Step_E6_2":
		dialog.text = "Мне сложно говорить о людях плохо.\n"+
                          "Я бы посоветовал тебе обратиться к одной нашей прихожанке Джиллиан Эттербери. Мне известно, что у нее серьезные проблемы как раз с этим человеком. Возможно, вы сможете ей даже в чем-то помочь.\n"+
                          "Джиллиан хорошая прихожанка, как правило она бывает в церкви часов с одиннадцати утра ежедневно и молится в течение двух-трех часов.\n"+
                          "А вообще ее в городе можно встретить.";
		link.l1 = "Спасибо, святой отец.";
		link.l1.go = "exit";
		pchar.questTemp.State = "MorrisWillams_ArrestedSeekInfoWomen";
		AddQuestRecord("Eng_Line_6_MorrisWillams", "19");
		AddQuestUserData("Eng_Line_6_MorrisWillams", "sSex", GetSexPhrase("","а"));
            ref sld = GetCharacter(NPC_GenerateCharacter("Gillian Atterbury", "Womenstown_8", "woman", "towngirl2", 5, ENGLAND, 100, false, "quest"));
        	sld.name 	= "Джиллиан";
        	sld.lastname = "Эттербери";
        	LAi_SetCitizenType(sld);
            sld.Dialog.Filename = "Gothic_Quest\EngLineNpc_2.c";
            LAi_group_MoveCharacter(sld, "ENGLAND_CITIZENS");
           	ChangeCharacterAddressGroup(sld, "PortRoyal_town", "goto", "goto1");
	LAi_SetFanatic(sld, "PortRoyal_church", "sit", "sit1", 11.0, 14.0);
	break;

	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}

