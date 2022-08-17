
/*
	CheatSurfMenu by Cheatsurfer от 07.01.2018 для ККС 1.6.0 (18.12.17)
	Горячие клавиши
*/

int iSNDc = 0;

// Поправить здоровье, восполнить HP и энергию, вылечить отравление, перезарядить оружие для ГГ и его абордажников
void CSMHotKeyF4()
{
	ref sld;
	int io, ion;
	ClearAllLogStrings();
	if (stf(pchar.health.Hp) < stf(pchar.health.MaxHp))
	{
		pchar.health.Hp = stf(pchar.health.MaxHp);
		Log_info("Здоровье максимально улучшено!");
	}
	else
	{
		Log_info("Состояние здоровья в полном порядке!");
	}
	if ((stf(pchar.chr_ai.hp) < stf(pchar.chr_ai.hp_max)) || (stf(pchar.chr_ai.energy) < stf(pchar.chr_ai.energyMax)))
	{
		LAi_SetCurHPMax(pchar);
		Log_info("HP и энергия восполнены!");
	}
	else
	{
		Log_info("HP и энергия в норме!");
	}
	if (CheckAttribute(pchar, "chr_ai.poison"))
	{
		DeleteAttribute(pchar, "chr_ai.poison");
		Log_info("Отравление вылечено!");
	}
	else
	{
		Log_info("Отравлений нет!");
	}
	if (GetCharacterEquipByGroup(pchar, GUN_ITEM_TYPE) != "")
	{
		if(stf(pchar.chr_ai.charge) < stf(pchar.chr_ai.charge_max))
		{
			pchar.chr_ai.charge = stf(pchar.chr_ai.charge_max);
			Log_info("Огнестрельное оружие перезаряжено!");
		}
		else
		{
			Log_info("Перезарядка огнестрельного оружия не требуется.");
		}
	}
	else
	{
		Log_info("Огнестрельное оружие не экипированно.");
	}
	for (io = 1; io <= 3; io++)
	{
		ion = GetOfficersIndex(pchar, io);
		if (ion < 0) continue;
		sld = GetCharacter(ion);
		LAi_SetCurHPMax(sld);
		if (GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE) != "")
		{
			sld.chr_ai.charge = stf(sld.chr_ai.charge_max);
		}
	}
	if (iSNDc != 0)
	{
		StopSound(iSNDc, 0);
	}
	iSNDc = PlaySound("_CheatSurfMenu_\Ahha.wav");
	Statistic_AddValue(PChar, "Cheats.F4", 1);
}

// Убить ближайщего неквестового врага
void CSMHotKeyF5()
{
	ClearAllLogStrings();
	if (!IsEntity(loadedLocation))
	{
		Log_info("Здесь это не работает!");
		return;
	}
	ref rXep;
	int i, iXep;
	int iXeps = FindNearCharacters(pchar, 50, -1.0, -1.0, 0.001, false, true);
	string sXep;
	bool bTarget = false;
	for (i = 0; i < iXeps; i++)
	{
		if (!CheckAttribute(chrFindNearCharacters[i], "index"))
		{
			break;
		}
		iXep = sti(chrFindNearCharacters[i].index);
		rXep = GetCharacter(iXep);
		if (LAi_IsImmortal(rXep) || !LAi_group_IsEnemy(pchar, rXep) || CheckAttribute(rXep, "chr_ai.hpchecker") || GetCharacterEquipByGroup(rXep, BLADE_ITEM_TYPE) == "" || rXep.chr_ai.type == LAI_TYPE_CARRY)
		{
			continue;
		}
		sXep = GetFullName(rXep);
		LAi_KillCharacter(rXep);
		bTarget = true;
		Log_Info("" + sXep + " " + NPCharSexPhrase(rXep, "был убит!", "была убита!"));
		if (iSNDc != 0)
		{
			StopSound(iSNDc, 0);
		}
		iSNDc = PlaySound("_CheatSurfMenu_\ReputationBad.wav");
		break;
	}
	if (!bTarget)
	{
		Log_info("Не могу найти подходящую жертву!");
		if (iSNDc != 0)
		{
			StopSound(iSNDc, 0);
		}
		iSNDc = PlaySound("_CheatSurfMenu_\WTF.wav");
	}
	Statistic_AddValue(PChar, "Cheats.F5", 1);
}

// Убрать / показать HUD
void CSMHotKeyF7()
{
	ClearAllLogStrings();
	ChangeShowIntarface();
	Statistic_AddValue(PChar, "Cheats.F7", 1);
}
