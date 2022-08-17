object SM_WeathersBackup[MAX_WEATHERS];

// тут делаем бакап, чтоб восстановиться при отключении мода
void SM_WeatherInit()
{
	object whr;
	int i;
	
	for (i = 0; i < MAX_WEATHERS; i++)
	{
		SM_WeathersBackup[i] = &Weathers[i];
	}
}

// модифицируем конфиги
void SM_ModifyWeather()
{	
	SM_ReplaceSomeWeatherData();
}

// от сейва
void SM_WeatherOnLoad()
{
	if (!CheckAttribute(pchar, "CSM.WavesType"))
		return;
	
	SM_ReplaceSomeWeatherData();
}

// а тут отменяем измеения и возвращаем все как было
void SM_ResetWeatherToDefault()
{
	int i;
	for (i = 0; i < MAX_WEATHERS; i++)
	{
		Weathers[i] = &SM_WeathersBackup[i];
	}
}

// Туманы подогнаны к скайбоксам от тов. Sergg!
void SM_ReplaceSomeWeatherData()
{
	Weathers[0].Fog.Color = argb(0, 3, 4, 8); // 0 Hours
	Weathers[0].Fog.Height = 80;

	Weathers[1].Fog.Color = argb(0, 3, 4, 8); // 1 hour
	Weathers[1].Fog.Height = 70;

	Weathers[2].Fog.Color = argb(0, 3, 4, 8); // 2 hour
	Weathers[2].Fog.Height = 60;

	Weathers[3].Fog.Color = argb(0, 3, 4, 8); // 3 hour
	Weathers[3].Fog.Height = 50;

	Weathers[4].Fog.Color = argb(0, 3, 4, 8); // 4 hour
	Weathers[4].Fog.Height = 90;

	Weathers[5].Fog.Color = argb(0, 3, 4, 8); // 5 hour
	Weathers[5].Fog.Height = 110;

	Weathers[6].Fog.Color = argb(0, 40, 60, 80); // 6 hour
	Weathers[6].Fog.Height = 120;

	Weathers[7].Fog.Color = argb(0, 40, 60, 80); // 7 hour
	Weathers[7].Fog.Height = 140;

	Weathers[8].Fog.Color = argb(0, 40, 60, 80); // 8 hour
	Weathers[8].Fog.Height = 160;
	
	Weathers[9].Fog.Color = argb(0, 40, 60, 80); // 10 hour
	Weathers[9].Fog.Height = 170;

	Weathers[10].Fog.Color = argb(0, 60, 90, 120);// 11 hour
	Weathers[10].Fog.Height = 180;

	Weathers[11].Fog.Color = argb(0, 60, 90, 120);// 11 hour
	Weathers[11].Fog.Height = 210;

	Weathers[12].Fog.Color = argb(0, 60, 90, 120);// 12 hour
	Weathers[12].Fog.Height = 240;

	Weathers[13].Fog.Color = argb(0, 60, 90, 120); // 13 hour
	Weathers[13].Fog.Height = 260;

	Weathers[14].Fog.Color = argb(0, 60, 90, 120); // 14 hour
	Weathers[14].Fog.Height = 280;

	Weathers[15].Fog.Color = argb(0, 60, 90, 120);// 15 hour
	Weathers[15].Fog.Height = 270;

	Weathers[16].Fog.Color = argb(0, 60, 90, 120); // 16 hour
	Weathers[16].Fog.Height = 260;

	Weathers[17].Fog.Color = argb(0, 60, 90, 120); // 17 hour
	Weathers[17].Fog.Height = 250;

	Weathers[18].Fog.Color = argb(0, 55, 70, 85); // 18 hour
	Weathers[18].Fog.Height = 240;

	Weathers[19].Fog.Color = argb(0, 55, 70, 85); // 19 hour
	Weathers[19].Fog.Height = 230;

	Weathers[20].Fog.Color = argb(0, 55, 70, 85); // 20 hour
	Weathers[20].Fog.Height = 220;

	Weathers[21].Fog.Color = argb(0, 55, 70, 85); // 21 hour
	Weathers[21].Fog.Height = 210;

	Weathers[22].Fog.Color = argb(0, 55, 70, 85); // 22 hour
	Weathers[22].Fog.Height = 200;

	Weathers[23].Fog.Color = argb(0, 55, 70, 85); // 23 hour
	Weathers[23].Fog.Height = 190;
	
	// ====================== Storm ======================
	
	Weathers[24].Fog.Color = argb(0, 50, 60, 65); // Storm01 (с 6 до 9)
	Weathers[24].Fog.Height = 1000;

	Weathers[25].Fog.Color = argb(0, 90, 95, 85); // Storm02 (с 10 до 17)
	Weathers[25].Fog.Height = 1000;

	Weathers[26].Fog.Color = argb(0, 45, 50, 50); // Storm03 (с 18 до 21)
	Weathers[26].Fog.Height = 1000;

	Weathers[27].Fog.Color = argb(0, 40, 40, 35); // Storm04 (с 22 до 5)
	Weathers[27].Fog.Height = 1000;
	
}

