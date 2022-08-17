void GothicDQuestComplete(string sQuestName, string qname)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
////   Задержки звуковых диалогов
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//зачарованный город, штурм фрегата с Данькой
void ZOM_ATTACK(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_00", 8.5);
}
void ZOM_ATTACK_00(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK01.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_01", 0.3);
}
void ZOM_ATTACK_01(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK02.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_02", 0.3);
}
void ZOM_ATTACK_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN02.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_03", 0.3);
}
void ZOM_ATTACK_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN01.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_04", 1.8);
}
void ZOM_ATTACK_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_ATTACK02.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_05", 1.3);
}
void ZOM_ATTACK_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_HURT01.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_06", 1.5);
}
void ZOM_ATTACK_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_WARN02.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_07", 1.5);
}
void ZOM_ATTACK_07(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_HURT03.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_08", 1.5);
}
void ZOM_ATTACK_08(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ZOM_HURT03.wav");
   DoQuestFunctionDelay("ZOM_ATTACK_09", 1.5);
}
void ZOM_ATTACK_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\AMBIENTSCREAM_1.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ищущие
void DIEENEMY(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_19_DIEENEMY.wav");
}
void RUNCOWARD(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_19_RUNCOWARD.wav");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Магия
void MAGIC_DEEP(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\MAGIC_DEEP02.wav");
            DoQuestFunctionDelay("MAGIC_DEEP_1", 8.0);
}
void MAGIC_DEEP_1(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\MAGIC_DEEP02.wav");
            DoQuestFunctionDelay("MAGIC_DEEP_2", 8.0);
}
void MAGIC_DEEP_2(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\MAGIC_DEEP02.wav");
            DoQuestFunctionDelay("MAGIC_DEEP_3", 8.0);
}
void MAGIC_DEEP_3(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\MAGIC_DEEP02.wav");
            DoQuestFunctionDelay("MAGIC_DEEP_4", 8.0);
}
void MAGIC_DEEP_4(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\MAGIC_DEEP02.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Огонь
void FIRE_SMALL(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
            DoQuestFunctionDelay("FIRE_SMALL_1", 3.0);
}

void FIRE_SMALL_1(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
            DoQuestFunctionDelay("FIRE_SMALL_2", 3.0);
}

void FIRE_SMALL_2(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
            DoQuestFunctionDelay("FIRE_SMALL_3", 3.0);
}

void FIRE_SMALL_3(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
            DoQuestFunctionDelay("FIRE_SMALL_4", 3.0);
}

void FIRE_SMALL_4(string qName)
{
            PlaySound("VOICE\Russian\gotica\SFX\FIRE_SMALL01.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Орк
void ORC_AMBIENT_SHORT(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT01.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_02", 2.5);
}
void ORC_AMBIENT_SHORT_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT02.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_03", 1.2);
}
void ORC_AMBIENT_SHORT_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT03.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_04", 1.2);
}
void ORC_AMBIENT_SHORT_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT04.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_05", 2.2);
}
void ORC_AMBIENT_SHORT_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ANGRY01.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_06", 3.2);
}
void ORC_AMBIENT_SHORT_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_HAPPY01.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_07", 3.2);
}
void ORC_AMBIENT_SHORT_07(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT04.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_08", 2.2);
}
void ORC_AMBIENT_SHORT_08(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ANGRY01.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_09", 3.2);
}
void ORC_AMBIENT_SHORT_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_HAPPY01.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_010", 3.2);
}
void ORC_AMBIENT_SHORT_010(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT03.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_011", 1.2);
}
void ORC_AMBIENT_SHORT_011(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT04.wav");
   DoQuestFunctionDelay("ORC_AMBIENT_SHORT_012", 2.2);
}
void ORC_AMBIENT_SHORT_012(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_HAPPY01.wav");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Орк атака
void ORC_ATTACK(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ATTACK01.wav");
   DoQuestFunctionDelay("ORC_ATTACK_01", 2.0);
}
void ORC_ATTACK_01(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ATTACK02.wav");
   DoQuestFunctionDelay("ORC_ATTACK_02", 2.0);
}
void ORC_ATTACK_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_AMBIENT_SHORT02.wav");
   DoQuestFunctionDelay("ORC_ATTACK_03", 2.0);
}
void ORC_ATTACK_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ANGRY01.wav");
   DoQuestFunctionDelay("ORC_ATTACK_04", 2.0);
}
void ORC_ATTACK_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_FRIGHTENED01.wav");
   DoQuestFunctionDelay("ORC_ATTACK_05", 3.0);
}
void ORC_ATTACK_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_WARN01.wav");
   DoQuestFunctionDelay("ORC_ATTACK_06", 2.0);
}
void ORC_ATTACK_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SFX\ORC_ATTACK02.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Звук при водных скелетов
void DEMENTHORTALK(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_01", 6.0);
}
void DEMENTHORTALK_01(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_02", 6.0);
}
void DEMENTHORTALK_02(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_03", 6.0);
}
void DEMENTHORTALK_03(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_04", 6.0);
}
void DEMENTHORTALK_04(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_05", 6.0);
}
void DEMENTHORTALK_05(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_06", 6.0);
}
void DEMENTHORTALK_06(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_07", 6.0);
}
void DEMENTHORTALK_07(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_08", 6.0);
}
void DEMENTHORTALK_08(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_09", 6.0);
}
void DEMENTHORTALK_09(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_10", 6.0);
}
void DEMENTHORTALK_10(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_11", 6.0);
}
void DEMENTHORTALK_11(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
   DoQuestFunctionDelay("DEMENTHORTALK_12", 6.0);
}
void DEMENTHORTALK_12(string qName)
{
    PlaySound("VOICE\Russian\gotica\SFX\DEMENTHORTALK.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//При махаче с Мо
void MOE_CHEERFRIEND(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_01", 2.5);
}
void MOE_CHEERFRIEND_01(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_02", 1.9);
}
void MOE_CHEERFRIEND_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND03.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_03", 0.8);
}
void MOE_CHEERFRIEND_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_GUARDS.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_04", 1.7);
}
void MOE_CHEERFRIEND_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODHESDOWN.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_05", 2.5);
}
void MOE_CHEERFRIEND_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_14_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_06", 3.8);
}
void MOE_CHEERFRIEND_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_14_OHMYGODHESDOWN.wav");
  DoQuestFunctionDelay("MOE_CHEERFRIEND_07", 2.8);
}
void MOE_CHEERFRIEND_07(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND02.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_08", 3.8);
}
void MOE_CHEERFRIEND_08(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_THERESAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_09", 3.2);
}
void MOE_CHEERFRIEND_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_10", 2.5);
}
void MOE_CHEERFRIEND_10(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_11", 3.5);
}
void MOE_CHEERFRIEND_11(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_12", 1.9);
}
void MOE_CHEERFRIEND_12(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_12_OHMYGODHESDOWN.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_13", 2.9);
}
void MOE_CHEERFRIEND_13()
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_12_NOTBAD.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_14", 5.9);
}
void MOE_CHEERFRIEND_14(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_15", 2.9);
}
void MOE_CHEERFRIEND_15(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_16", 2.5);
}
void MOE_CHEERFRIEND_16(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_17", 1.9);
}
void MOE_CHEERFRIEND_17(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND03.wav");
   DoQuestFunctionDelay("MOE_CHEERFRIEND_18", 0.8);
}
void MOE_CHEERFRIEND_18(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_GUARDS.wav");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//По квесту Португалец
void CHEERFRIEND(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("CHEERFRIEND_01", 2.5);
}
void CHEERFRIEND_01(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_02", 1.9);
}
void CHEERFRIEND_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND03.wav");
   DoQuestFunctionDelay("CHEERFRIEND_03", 0.8);
}
void CHEERFRIEND_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_GUARDS.wav");
   DoQuestFunctionDelay("CHEERFRIEND_04", 1.7);
}
void CHEERFRIEND_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODHESDOWN.wav");
   DoQuestFunctionDelay("CHEERFRIEND_05", 2.5);
}
void CHEERFRIEND_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_14_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_06", 3.8);
}
void CHEERFRIEND_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_14_OHMYGODHESDOWN.wav");
  DoQuestFunctionDelay("CHEERFRIEND_07", 2.8);
}
void CHEERFRIEND_07(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND02.wav");
   DoQuestFunctionDelay("CHEERFRIEND_08", 3.8);
}
void CHEERFRIEND_08(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_THERESAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_09", 3.2);
}
void CHEERFRIEND_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_13_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_10", 2.5);
}
void CHEERFRIEND_10(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("CHEERFRIEND_11", 3.5);
}
void CHEERFRIEND_11(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_12", 1.9);
}
void CHEERFRIEND_12(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_12_OHMYGODHESDOWN.wav");
   DoQuestFunctionDelay("CHEERFRIEND_13", 2.9);
}
void CHEERFRIEND_13()
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_12_NOTBAD.wav");
   DoQuestFunctionDelay("CHEERFRIEND_14", 5.9);
}
void CHEERFRIEND_14(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_15", 2.9);
}
void CHEERFRIEND_15(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("CHEERFRIEND_16", 2.5);
}
void CHEERFRIEND_16(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_17", 1.9);
}
void CHEERFRIEND_17(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_CHEERFRIEND03.wav");
   DoQuestFunctionDelay("CHEERFRIEND_18", 0.8);
}
void CHEERFRIEND_18(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_GUARDS.wav");
}


//По квесту Португалец
void CHEERFRIEND_1_01(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_02", 2.5);
}
void CHEERFRIEND_1_02(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_CHEERFRIEND01.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_03", 3.5);
}
void CHEERFRIEND_1_03(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_ALARM.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_04", 3.5);
}
void CHEERFRIEND_1_04(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_GOODKILL.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_05", 3.5);
}
void CHEERFRIEND_1_05(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_GUARDS.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_06", 3.5);
}
void CHEERFRIEND_1_06(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_KILLENEMY.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_07", 3.5);
}
void CHEERFRIEND_1_07(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_MONSTERKILLED.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_08", 1.5);
}
void CHEERFRIEND_1_08(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_NOTBAD.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_09", 3.5);
}
void CHEERFRIEND_1_09(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_OHMYGODHESDOWN.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_010", 3.5);
}
void CHEERFRIEND_1_010(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_OHMYGODITSAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_011", 3.5);
}
void CHEERFRIEND_1_011(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_OOH02.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_012", 2.5);
}
void CHEERFRIEND_1_012(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_OOH03.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_013", 3.5);
}
void CHEERFRIEND_1_013(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SHEEPKILLER.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_014", 3.5);
}
void CHEERFRIEND_1_014(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_THERESAFIGHT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_015", 3.5);
}
void CHEERFRIEND_1_015(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_YOUASKEDFORIT.wav");
   DoQuestFunctionDelay("CHEERFRIEND_1_016", 3.5);
}
void CHEERFRIEND_1_016(string qName)
{
   PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_YOUMURDERER.wav");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Тихий базар по квесту Розо или Шарлртт - Таун
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void SMALLTALK_RoseauCharlotte(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_SMALLTALK23.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_02", 3.5);
}

void SMALLTALK_RoseauCharlotte_02(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK24.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_03", 3.5);
}

void SMALLTALK_RoseauCharlotte_03(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_SMALLTALK22.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_04", 3.5);
}

void SMALLTALK_RoseauCharlotte_04(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK23.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_05", 3.5);
}

void SMALLTALK_RoseauCharlotte_05(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK22.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_06", 3.5);
}

void SMALLTALK_RoseauCharlotte_06(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_SMALLTALK07.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_07", 3.5);
}

void SMALLTALK_RoseauCharlotte_07(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK18.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_08", 3.5);
}

void SMALLTALK_RoseauCharlotte_08(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK14.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_09", 3.5);
}

void SMALLTALK_RoseauCharlotte_09(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_11_SMALLTALK01.wav");
    DoQuestFunctionDelay("SMALLTALK_RoseauCharlotte_010", 3.5);
}

void SMALLTALK_RoseauCharlotte_010(string qName)
if (pchar.location == "Shore26")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_SMALLTALK11.wav");
    DoQuestFunctionDelay("Killwork_huber_hour_04", 3.5);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Звуковые слухи в Шарлотт - Тауне
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void SMALLTALK(string qName)
{
	string sLoc = "Roseau_town";
	pchar.quest.SMALLTALK.win_condition.l1 = "location";
	pchar.quest.SMALLTALK.win_condition.l1.location = sLoc;
	pchar.quest.SMALLTALK.win_condition.l2 = "HardHour";
	pchar.quest.SMALLTALK.win_condition.l2.start.hour = 11.00;
	pchar.quest.SMALLTALK.win_condition.l2.finish.hour = 21.00;
	pchar.quest.SMALLTALK.function = "SMALLTALK_Roseau_town_01";
}

void SMALLTALK_Roseau_town_01(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK01.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_02", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
}

void SMALLTALK_Roseau_town_02(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK02.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_03", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_03(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK03.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_04", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_04(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK04.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_05", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_05(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK05.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_06", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_06(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK06.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_07", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_07(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK07.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_08", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_08(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK08.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_09", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_09(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK09.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_10", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_10(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK10.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_11", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_11(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK11.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_12", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_12(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK12.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_13", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_13(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK13.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_14", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_14(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK14.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_15", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_15(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK15.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_16", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_16(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK16.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_17", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_17(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK17.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_18", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_18(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK18.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_19", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_19(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK19.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_20", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_20(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK20.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_21", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_21(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK21.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_22", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_22(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK22.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_23", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_23(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK23.wav");
    DoQuestFunctionDelay("SMALLTALK_Roseau_town_24", 2.5);
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

void SMALLTALK_Roseau_town_24(string qName)
if (pchar.location == "Roseau_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_16_SMALLTALK24.wav");
    //DoQuestFunctionDelay("SMALLTALK", 120.0);
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void SMALLTALK_1(string qName)
{
	string sLoc = "Roseau_port";
	pchar.quest.SMALLTALK_1.win_condition.l1 = "location";
	pchar.quest.SMALLTALK_1.win_condition.l1.location = sLoc;
	pchar.quest.SMALLTALK_1.win_condition.l2 = "HardHour";
	pchar.quest.SMALLTALK_1.win_condition.l2.start.hour = 7.00;
	pchar.quest.SMALLTALK_1.win_condition.l2.finish.hour = 20.00;
	pchar.quest.SMALLTALK_1.function = "SMALLTALK_1_Roseau_town_01";
}

void SMALLTALK_1_Roseau_town_01(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK01.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_02", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_Roseau_town_02(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK02.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_03", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_03(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK03.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_04", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_04(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK04.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_05", 2.5);
    DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_05(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK05.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_06", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_06(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK06.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_07", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_07(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK07.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_08", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_08(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK08.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_09", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_09(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK09.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_10", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_10(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK10.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_11", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_11(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK11.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_12", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_12(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK12.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_13", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_13(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK13.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_14", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_14(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK14.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_15", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_15(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK15.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_16", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_16(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK16.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_17", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_17(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK17.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_18", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_18(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK18.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_19", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_19(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK19.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_20", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_20(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK20.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_21", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_21(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK21.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_22", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_22(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK22.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_23", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_23(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK23.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_24", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_24(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK24.wav");
    DoQuestFunctionDelay("void SMALLTALK_1_Roseau_town_25", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_25(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK25.wav");
    DoQuestFunctionDelay("void SMALLTALK_1_Roseau_town_26", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_26(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK26.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_27", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_27(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK27.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_28", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_28(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK28.wav");
    DoQuestFunctionDelay("SMALLTALK_1_Roseau_town_29", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_29(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK29.wav");
    DoQuestFunctionDelay("SMALLTALK_1", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

void SMALLTALK_1_Roseau_town_30(string qName)
if (pchar.location == "Roseau_port")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_1_SMALLTALK30.wav");
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Звуковые слухи в Ле Француа
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void SMALLTALK_L(string qName)
{
	string sLoc = "LeFransua_town";
	pchar.quest.SMALLTALK_L.win_condition.l1 = "location";
	pchar.quest.SMALLTALK_L.win_condition.l1.location = sLoc;
	pchar.quest.SMALLTALK_L.win_condition.l2 = "HardHour";
	pchar.quest.SMALLTALK_L.win_condition.l2.start.hour = 7.00;
	pchar.quest.SMALLTALK_L.win_condition.l2.finish.hour = 20.00;
	pchar.quest.SMALLTALK_L.function = "SMALLTALK_1_LeFransua_town_01";
}

void SMALLTALK_1_LeFransua_town_01(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK01.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_02", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_02(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK02.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_03", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_03(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK03.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_04", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_04(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK04.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_05", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_05(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK05.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_06", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_06(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK06.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_07", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_07(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK07.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_08", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_08(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK08.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_09", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_09(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK09.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_10", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_10(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK10.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_11", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_11(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK11.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_12", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_12(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK12.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_13", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_13(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK13.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_14", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_14(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK14.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_15", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_15(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK15.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_16", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_16(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK16.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_17", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_17(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK17.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_18", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_18(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK18.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_19", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_19(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK19.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_20", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_20(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK20.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_21", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_21(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK21.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_22", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_22(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK22.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_23", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_23(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK23.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_24", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_25(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK25.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_26", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_26(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK26.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_27", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_27(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK27.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_28", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_28(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK28.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_29", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_29(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK29.wav");
    DoQuestFunctionDelay("SMALLTALK_1_LeFransua_town_30", 2.5);
    //DoQuestFunctionDelay("SMALLTALK_1", 120.0);
}

void SMALLTALK_1_LeFransua_town_30(string qName)
if (pchar.location == "LeFransua_town")
{
    PlaySound("VOICE\Russian\gotica\SVM_1\SVM_3_SMALLTALK30.wav");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
///------------------------------------- "Мистер и Миссис Смит" абордаж----------------------------------------

void GothicSmithyBattle(string qName)
{
   PlaySound("Sea Battles\mushketn_zalp_001.wav");
   PlaySound("Interface\_GTBoard0.wav");
   DoQuestFunctionDelay("GothicSmithyBattle_1", 2.0);
}

void GothicSmithyBattle_1(string qName)
{
   PlaySound("Sea Battles\vzriv_pogreb_001.wav");
   PlaySound("Sea Battles_01\Ship_Burn_01.wav");
   PlaySound("Sea Battles_01\Swish_balls_06.wav");
   PlaySound("Interface\abordage2.wav");
    DoQuestFunctionDelay("GothicSmithyBattle_2", 7.0);
}

void GothicSmithyBattle_2(string qName)
{
    PlaySound("Interface\abordage2.wav");
   PlaySound("Interface\_Damage1.wav");
    DoQuestFunctionDelay("GothicSmithyBattle_3", 3.0);
}

void GothicSmithyBattle_3(string qName)
{
   PlaySound("Sea Battles\mushketn_zalp_001.wav");
    PlaySound("Interface\abordage2.wav");
    DoQuestFunctionDelay("GothicSmithyBattle_4", 4.0);
}
void GothicSmithyBattle_4(string qName)
{
   PlaySound("Interface\MusketFire3.wav");
   PlaySound("Interface\_musketshot.wav");
   DoQuestFunctionDelay("GothicSmithy_GhostshipBoardingGo", 2.0);
}


///------------------------------ "Мистер и Миссис Смит" в доме у Давида----------------------------------------

void Gothic_SmithyPuertoRico_4(string qName)
{
                   PlaySound("Interface\Door_Kick.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_5", 7.0);
}

void Gothic_SmithyPuertoRico_5(string qName)
{
 	PlaySound("VOICE\Russian\gotica\SVM_1\SVM_17_WHATWASTHAT.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_6", 3.0);
}

void Gothic_SmithyPuertoRico_6(string qName)
{
 	PlaySound("VOICE\Russian\GOTHIC\GG\FLUECHTLING.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_7", 4.0);
}

void Gothic_SmithyPuertoRico_7(string qName)
{
 	PlaySound("Ambient\SHOP\noise1.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_8", 2.0);
}
void Gothic_SmithyPuertoRico_8(string qName)
{
 	PlaySound("Ambient\SHOP\sigh2.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_9", 3.0);
}
void Gothic_SmithyPuertoRico_9(string qName)
{
 	PlaySound("Interface\key.wav");
                   DoQuestFunctionDelay("Gothic_SmithyPuertoRico_10", 2.0);
}


/////////////////////////////////////////////////////////////////////////////////////////////////







