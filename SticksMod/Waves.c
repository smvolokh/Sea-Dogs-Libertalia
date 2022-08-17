int SM_WaveType = 0;
int SM_TotalWaves = 5;

int SM_COLOR;
float SM_CMULTIPLER = 1.00;


// Waves ON
void SM_WavesEnable()
{
	SM_ModifyWeather();
	SM_ModifyWaves();
}


// Waves OFF
void SM_WavesDisable()
{
//	SM_ResetWeatherToDefault();
//	SM_UpdateSeaEnvironment();
	WeatherInit();
	Whr_UpdateWeather();
}


// Обновляем вонлы исходя из текущей скорости ветра
void SM_ModifyWaves()
{	
	float windSpeed = Whr_GetWindSpeed();
	int type;
	
	if (pchar.CSM.WavesType == -1) // by wind
	{
		type = SM_GetWaveTypeByWindSpeed(windSpeed);
	}
	else
	{
		if (pchar.CSM.WavesType == 0) // randomly
			type = SM_GetWaveTypeByWindSpeed(-1);
		else
		{
			type = pchar.CSM.WavesType; // current
			type--;
		}
	}
	
	// Если находимся в шторме, временно ставим 5й тип, атрибут не меняем
	if (bWeatherIsStorm)
	{
		type = 5;
	}
	
	SM_WaveType = type;
	
	//Log_info("WavesType : " + type + ";    wind speed : " + windSpeed);
	
	SM_ModifyWavesByType(type);
}


// Общее обновление окружения
void SM_UpdateSeaEnvironment()
{
	SM_ModifySeaFog();
	SM_ModifyLightness();
}


// Усиливаем фог по ветру - чем больше ветер, тем больше волны, чем больше волны - тем больше ляпы вдали, прячем в тумане.
void SM_ModifySeaFog()
{	
	float additionalNightFog = 0.0000;
	float currentHour = GetHour();
	
	if (currentHour >= 0 && currentHour <= 6)
	{
		additionalNightFog = 0.002;
	}
	
	aref weather = GetCurrentWeather();
	
	weather.Fog.Start = 25;
	weather.Fog.IslandDensity = 0.0002 + 0.00002 * pow(SM_WaveType, 3) + additionalNightFog;
	weather.Fog.SeaDensity = 0.00125 + 0.00005 * pow(SM_WaveType, 3) + additionalNightFog;
	weather.Fog.Density = 0.00125 + 0.00005 * pow(SM_WaveType, 3) + additionalNightFog;
	//weather.Fog.Color = SM_COLOR;
	
	Sea.Fog.Start = weather.Fog.Start;
	Sea.Fog.Density = weather.Fog.Density;
	Sea.Fog.SeaDensity = weather.Fog.SeaDensity;
	Island.FogDensity = weather.Fog.IslandDensity;
}


// подсветку делаем динамической, где 2 часа ночи - мин, 2 часа дня - макс. +обновляем блик под новую текстуру отражения
void SM_ModifyLightness()
{
	float lightIntencity = SM_CurrentHourToLightIntencity();
	int r, g, b;
	
	r = 255;
	g = 255;
	b = 255;
	
	r = makeint(r * lightIntencity);
	g = makeint(g * lightIntencity);
	b = makeint(b * lightIntencity);
	
	aref weather = GetCurrentWeather();
	
	weather.Sky.Color = argb(0, r, g, b);
	Weather.Sky.Color = weather.Sky.Color;
	
	weather.Sun.Reflection.Size = 1000 + 3000 * lightIntencity;
}


// Определение индекса волнения
int SM_GetWaveTypeByWindSpeed(float speed)
{
	if (speed < 4.0)
		return 0;
	
	if (speed >= 4.0 && speed < 8.0)
		return 1;
	
	if (speed >= 8.0 && speed < 12.0)
		return 2;
	
	if (speed >= 12.0 && speed < 16.0)
		return 3;
	
	if (speed >= 16.0)
		return 4;
}


// Ставим гармоники, амплитуды, размеры и скорость волн
void SM_ModifyWavesByType(int type)
{
	
	int r, g, b; // для каждого типа волн свои цвета, + нек рандомные вариации
	float lightIntencity = SM_CurrentHourToLightIntencity();
	
	// const
	Sea.Sea2.SkyColor = argb(0, 125, 125, 125);
	Sea.Sea2.FoamEnable = true;
	
	// подбор отражения, прозрачности, углового затемнения и углового затухания
	Sea.Sea2.Reflection = 1.25;
	Sea.Sea2.Transparency = 0.25;
	Sea.Sea2.Frenel = 0.4;
	Sea.Sea2.Attenuation = 0.2 + type * 0.05;
	
	// сетка, бамп и лоды
	Sea.Sea2.BumpScale = 0.1;
	Sea.Sea2.PosShift = 1.75;
	Sea.Sea2.LodScale = 0.5;
	Sea.Sea2.GridStep = 0.05;
	
	// гармоники взяты от патча 1.5.0
	Sea.Harmonics.h0 = "0.00, 10.0, 1.2, 80.87, -68.00";
	Sea.Harmonics.h1 = "1.57, 10.0, 2.1, 82.28,  88.00";
	Sea.Harmonics.h2 = "0.47,  7.0, 2.2, 82.28,  68.00";
	Sea.Harmonics.h3 = "0.27, 47.0, 0.5, 82.28, 288.00";
	Sea.Harmonics.h4 = "1.27, 57.0, 0.7, 82.28, 188.00";
	Sea.Harmonics.h5 = "2.27, 57.0, 0.3, 82.28,  88.00";
	Sea.Harmonics.h6 = "2.27, 37.0, 1.2, 82.28, 188.00";
	Sea.Harmonics.h7 = "2.77, 17.0, 0.5, 82.28, 288.00";
	Sea.Harmonics.h8 = "1.77, 17.0, 0.1, 82.28, 188.00";
	Sea.Harmonics.h9 = "1.0, 14.0, 0.5, 82.28,  28.00";
	
	// подбор амплитуд, скоростей и размеров волн
	switch(type)
	{	
		case 0: // штиль
		Sea.Sea2.Amp1 = 2.0;				
		Sea.Sea2.AnimSpeed1 = 1.0;			
		Sea.Sea2.Scale1 = 1.25;				
		Sea.Sea2.MoveSpeed1 = "1.5, 0.0, 1.5";	

		Sea.Sea2.Amp2 = 1.25;					
		Sea.Sea2.AnimSpeed2 = 1.25;				
		Sea.Sea2.Scale2 = 2.0;					
		Sea.Sea2.MoveSpeed2 = "-1.5, 0.0, -1.5";
		break;
		case 1: // мелкие волны
		Sea.Sea2.Amp1 = 4.0;
		Sea.Sea2.AnimSpeed1 = 1.25;
		Sea.Sea2.Scale1 = 0.6;
		Sea.Sea2.MoveSpeed1 = "0.0, 0.0, 2.0";

		Sea.Sea2.Amp2 = 2.0;
		Sea.Sea2.AnimSpeed2 = 2.0;
		Sea.Sea2.Scale2 = 1.5;
		Sea.Sea2.MoveSpeed2 = "-2.0, 0.0, 0.0";
		break;
		case 2: // средние волны
		Sea.Sea2.Amp1 = 8.0;
		Sea.Sea2.AnimSpeed1 = 1.5;
		Sea.Sea2.Scale1 = 0.35;
		Sea.Sea2.MoveSpeed1 = "0.0, 0.0, 3.0";

		Sea.Sea2.Amp2 = 3.0;
		Sea.Sea2.AnimSpeed2 = 3.0;
		Sea.Sea2.Scale2 = 1.25;
		Sea.Sea2.MoveSpeed2 = "1.0, 0.0, 1.0";
		break;
		case 3: // большие волны
		Sea.Sea2.Amp1 = 16.0;
		Sea.Sea2.AnimSpeed1 = 1.75;
		Sea.Sea2.Scale1 = 0.20;
		Sea.Sea2.MoveSpeed1 = "0.0, 0.0, 5.0";

		Sea.Sea2.Amp2 = 4.0;
		Sea.Sea2.AnimSpeed2 = 4.0;
		Sea.Sea2.Scale2 = 1.0;
		Sea.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";
		break;
		case 4: // шторм
		Sea.Sea2.Amp1 = 32.0;
		Sea.Sea2.AnimSpeed1 = 2.0;
		Sea.Sea2.Scale1 = 0.125;
		Sea.Sea2.MoveSpeed1 = "8.0, 0.0, 0.0";

		Sea.Sea2.Amp2 = 6.0;
		Sea.Sea2.AnimSpeed2 = 6.0;
		Sea.Sea2.Scale2 = 0.75;
		Sea.Sea2.MoveSpeed2 = "0.0, 0.0, -1.0";
		break;
		case 5: // шторм с молниями (настоящий)
		Sea.Sea2.Amp1 = 64.0;
		Sea.Sea2.AnimSpeed1 = 2.25;
		Sea.Sea2.Scale1 = 0.075;
		Sea.Sea2.MoveSpeed1 = "12.0, 0.0, 0.0";

		Sea.Sea2.Amp2 = 9.0;
		Sea.Sea2.AnimSpeed2 = 8.0;
		Sea.Sea2.Scale2 = 0.5;
		Sea.Sea2.MoveSpeed2 = "0.0, 0.0, 4.0";
		break;
	}
	
	// динамические барашки
	Sea.Sea2.FoamK = 0.025 + 0.025 * (5 - type) * lightIntencity;
	Sea.Sea2.FoamV = pow(2, type);
	Sea.Sea2.FoamUV = 1 - type * 0.2;
	Sea.Sea2.FoamTexDisturb = 0.1;
	
	// динамические RGB
	r = 0; g = 115; b = 115;
	
	r = makeint(r * lightIntencity);
	g = makeint(g * lightIntencity);
	b = makeint(b * lightIntencity);
	
	Sea.Sea2.WaterColor = argb(0, r, g, b);
	// Log_info("color : " + r + ", " + g + ", " + b);
}

// ======================== FOR TEST =========================
void SM_AddLightness()
{
	int r, g, b;
	SM_CMULTIPLER = SM_CMULTIPLER + 0.05;
	
	r = 150;
	g = 150;
	b = 250;
	
	r = makeint(r * SM_CMULTIPLER);
	g = makeint(g * SM_CMULTIPLER);
	b = makeint(b * SM_CMULTIPLER);
	
	Log_info("color : " + r + ", " + g + ", " + b);
	
	SM_COLOR = argb(0, r, g, b);
	
	Log_info("rgb : " + SM_COLOR);
	
	SM_ModifySeaFog();
	Whr_UpdateWeather();
}

void SM_SubLightness()
{
	int r, g, b;
	SM_CMULTIPLER = SM_CMULTIPLER - 0.05;
	
	r = 150;
	g = 150;
	b = 250;
	
	r = makeint(r * SM_CMULTIPLER);
	g = makeint(g * SM_CMULTIPLER);
	b = makeint(b * SM_CMULTIPLER);
	
	Log_info("color : " + r + ", " + g + ", " + b);
	
	SM_COLOR = argb(0, r, g, b);
	
	Log_info("rgb : " + SM_COLOR);
	
	SM_ModifySeaFog();
	Whr_UpdateWeather();
}
// ========================================================