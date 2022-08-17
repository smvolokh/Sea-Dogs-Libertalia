
#define LAI_TYPE_MINING		"mining"


//Инициализация
void LAi_type_mining_Init(aref chr)
{
	DeleteAttribute(chr, "location.follower");
	bool isNew = false;
                   string actionMining;	
	if(CheckAttribute(chr, "chr_ai.type") == false)
	{
		isNew = true;
	}else{
		if(chr.chr_ai.type != LAI_TYPE_MINING) isNew = true;
	}
	if(isNew == true)
	{
	else
	{
		chr.chr_ai.tmpl.animation = actionMining;
	}
	//Установим шаблон работы шахтёра
	DeleteAttribute(chr, "chr_ai.type");
	chr.chr_ai.type = LAI_TYPE_MINING;
	chr.chr_ai.type.stay = "0";
	chr.chr_ai.type.index = "";
	chr.chr_ai.type.dialog = "1"; 
	chr.chr_ai.type.bottle = rand(10)+2;
	chr.chr_ai.type.checkTarget = 0;
	LAi_tmpl_stay_InitTemplate(chr);
	//Установим анимацию персонажу
	chr.chr_ai.type.state = "Mining";
                  chr.TiedItems.itm1.model = "HandsItems\topor_015";
	chr.TiedItems.itm1.locator = "Saber_hand";	
	BeginChangeCharacterActions(chr);
	chr.actions.idle.i1 = "ore_go_1";
	EndChangeCharacterActions(chr);
	LAi_NPC_Mining(chr);
	GiveItem2Character(chr, "topor_015");
	EquipCharacterbyItem(chr, "topor_015");
	string sMining = "minepick";
	if (chr.model == "man") sMining = "minepick";
	GiveItem2Character(chr, sMining);
	EquipCharacterbyItem(chr, sMining);
	chr.isMining = true;
	}else{
	if(!CheckAttribute(chr, "chr_ai.type.stay")) chr.chr_ai.type.stay = "0";
	if(!CheckAttribute(chr, "chr_ai.type.index")) chr.chr_ai.type.index = "";
	if(!CheckAttribute(chr, "chr_ai.type.dialog")) chr.chr_ai.type.dialog = "1";

	//if(actionMining == "ore_go_1") SendMessage(chr, "lslss", MSG_CHARACTER_EX_MSG, "TiedItem", 10, "HandsItems\topor_015", "Saber_hand");
           }
	LAi_SetDefaultMiningAnimation(chr);
	SendMessage(&chr, "lsl", MSG_CHARACTER_EX_MSG, "SetFightWOWeapon", false);

}

//Процессирование типа персонажа
void LAi_type_Mining_CharacterUpdate(aref chr, float dltTime)
{
	string snd = "male-citizen";
	if(CheckAttribute(chr,"sex") && chr.sex=="woman") snd = "female-citizen";
	if(CheckAttribute(chr,"worklocator"))
	{
		//if(HasSubStr(chr.worklocator,"wheel")) snd = "OBJECTS\wheel.wav";
		if(HasSubStr(chr.worklocator,"cannon"))
		{
			switch(Rand(2))
			{
			//case 0: snd = "AMBIENT\TOWN\knife.wav"; break;
			//case 1: snd = "AMBIENT\TAVERN\drop"+sti(Rand(3)+3)+".wav"; break;
			//case 2: snd = "PEOPLE\step_iron.wav"; break;
			}
			if(FindNearCharacters(chr, 2.5, -1.0, 30.0, 0.1, false, false)>0) LAi_CharacterPlaySound(chr, snd);
		}
		CharacterTurnByLoc(chr, chr.worklocator.group, chr.worklocator);
	}
	if(rand(300)==123) { LAi_CharacterPlaySound(chr, snd); }
	else
	{
		if(FindNearCharacters(chr, 2.5, -1.0, 30.0, 0.1, false, false)>0)
		{
			if(rand(100)==10) { LAi_CharacterPlaySound(chr, snd); }
		}
	}
}

//Загрузка персонажа в локацию
bool LAi_type_Mining_CharacterLogin(aref chr)
{
	return true;
}

//Выгрузка персонажа из локацию
bool LAi_type_Mining_CharacterLogoff(aref chr)
{
	return true;
}

//Завершение работы темплейта
void LAi_type_Mining_TemplateComplite(aref chr, string tmpl)
{
	LAi_tmpl_player_InitTemplate(chr);
}

//Сообщить о желании завести диалог
void LAi_type_Mining_NeedDialog(aref chr, aref by)
{
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_type_Mining_CanDialog(aref chr, aref by)
{
	//Если уже говорим, то откажем
	if(chr.chr_ai.tmpl == LAI_TMPL_DIALOG) return false;
	//Согласимся на диалог
	return true;
}

//Начать диалог
void LAi_type_Mining_StartDialog(aref chr, aref by)
{
	//Если мы пасивны, запускаем шаблон без времени завершения
	LAi_tmpl_stay_InitTemplate(chr);
	LAi_tmpl_SetActivatedDialog(chr, by);
	LAi_tmpl_dialog_NoAni(chr);
}

//Закончить диалог
void LAi_type_Mining_EndDialog(aref chr, aref by)
{
	LAi_tmpl_stay_InitTemplate(chr);
}

//Персонаж атаковал другого персонажа
void LAi_type_Mining_Attack(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//Персонаж атоковал заблокировавшегося персонажа
void LAi_type_Mining_Block(aref attack, aref enemy, float attackDmg, float hitDmg)
{
}

//Персонаж выстрелил
void LAi_type_Mining_Fire(aref attack, aref enemy, float kDist, bool isFindedEnemy)
{
}


//Персонаж атакован
void LAi_type_Mining_Attacked(aref chr, aref by)
{
	
}

