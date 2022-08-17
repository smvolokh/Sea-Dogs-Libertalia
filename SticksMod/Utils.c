// велосипеды

// метод форсит убирание сабли
void SM_HideWeapon(string qName)
{
	LAi_SetFightMode(pchar, false);
	LAi_LockFightMode(pchar, true);
}

// узнать расстояние между двумя персами на локации (в ярдах кажется)
float SM_GetCharactersDistance(ref ch1, ref ch2)
{
	float dst;
	GetCharacterDistByChr(ch1, ch2, &dst);
	return dst;
}

// прикинуть время, требующееся неписи, чтоб добежать до заданного перса
float SM_GetRunTime(ref ch1, ref ch2)
{
	return SM_GetCharactersDistance(ch1, ch2) / 5; // на 20 ярдов около 4 сек в среднем :)
}

// конвертор часов в интенсивность освещения (2 часа ночи - самый черный час, интенсивность 0; 14 часов - самый яркий час, интенсивность 1)
float SM_HourToLightIntencity(float hour)
{
	return abs(abs((hour - 14) / 12) - 1);
}

// тоже самое, только для текущего часа
float SM_CurrentHourToLightIntencity()
{
	return SM_HourToLightIntencity(GetHour());
}