#event_handler("frame", "UpdateSky");

object Sky;

float fPrevCameraAX = 0;

void WhrDeleteSkyEnvironment()
{
	if(isEntity(&Sky))
	{
		DeleteClass(&Sky);
	}
	
	DeleteAttribute(&Sky, "");
}

void WhrCreateSkyEnvironment()
{
	aref aCurWeather = GetCurrentWeather();
	aref aSky;
	makearef(aSky, aCurWeather.Sky);

	DeleteAttribute(&Sky, "")
	if(!isEntity(&Sky))
	{
		CreateEntity(&Sky, "Sky");
		LayerAddObject("sea_reflection", &Sky, 1);
	}

	FillSkyDir(&Sky);
	//Sky.Dir = Whr_GetString(aSky, "Dir");

	Sky.Color = Whr_GetColor(aSky, "Color");
	Sky.RotateSpeed = Whr_GetFloat(aSky, "Rotate"); // Warship 02.06.09 - ??????? ???? ????
	Sky.Angle = Whr_GetFloat(aSky, "Angle");
	Sky.Size = Whr_GetFloat(aSky, "Size");

	Sky.isDone = "";
}

// Warship 02.06.09 - ?????? ?????????? ???? (????????, ???????? ??????? ? ??????????? ?? ???? ?????)
void UpdateSky()
{
	float windSpeed = 5.0;
	float timeScale = 1.0 + TimeScaleCounter * 0.25; // ??????? ????????? ???????
	
	// ?????????? ???????? ??? ?????????, ???? ?? x8 ??????? ?? ?????????
	if(timeScale <= 2)
	{
		timeScale = 1;
	}
	else
	{
		timeScale /= 2;
	}
	
	if(CheckAttribute(Weather, "Wind.Speed"))
	{
		windSpeed = stf(Weather.Wind.Speed);
	}
	
	// Sky.RotateSpeed == 0.05 - ??? ??? ?????
	
	// --> [SticksMod]
	if (CheckAttribute(pchar, "CSM.WavesType"))
	{
		Sky.RotateSpeed = windSpeed / 2500 / timeScale;
	}
	else
	{
		Sky.RotateSpeed = windSpeed / 1000 / timeScale;
	}
	// <-- [SticksMod]
}

void FillSkyDir(aref aSky)
{
	int i, nStart, nDur;
	string satr;
	aref aCurWeather = GetCurrentWeather();
	string sDir;
	
	// --> [SticksMod]
	// ??? ???? ?????????? ?????? ?????????, ?? ????? ????????? ??????????, ????? ?????????????? ????????? ?????????
	if (CheckAttribute(pchar, "CSM.WavesType"))
		iBlendWeatherNum = FindBlendWeather(iCurWeatherNum);
	// <-- [SticksMod]

	DeleteAttribute(aSky,"Dir");
	if( iBlendWeatherNum < 0 )
	{
		aSky.Dir.d1 = aCurWeather.Sky.Dir;
		aSky.Dir = GetHour();
	} else {
		for (i=0;i<MAX_WEATHERS;i++)
		{
			if (!CheckAttribute(&Weathers[i], "Hour")) {continue;}
			if (CheckAttribute(&Weathers[i], "Skip") && sti(Weathers[i].Skip)==true) {continue;}
			if (CheckAttribute(&Weathers[i], "Storm")&& sti(Weathers[i].Storm)==true) {continue;}

			satr = "d" + sti(Weathers[i].Hour.Min);
			if( satr=="d24" ) {continue;}
			
//navy -->
			sDir = Weathers[i].Sky.Dir;
			if (CheckAttribute(&WeatherParams, "Rain.ThisDay") && sti(WeatherParams.Rain.ThisDay)) 
			{
				nStart = sti(WeatherParams.Rain.StartTime);
				nDur = MakeInt(sti(WeatherParams.Rain.Duration)/60 + 0.5);
				if (sti(Weathers[i].Hour.Min) >= nStart  && sti(Weathers[i].Hour.Max) <= (nStart + nDur))
				{
					sDir = "weather\skies\Storm01\";
				}
			}
//navy <--
			aSky.Dir.(satr) = sDir;
		}
		aSky.Dir = GetTime();
	}
	
	// --> [SticksMod]
	// ???? ???, ?? ?????? ?????
	if (CheckAttribute(pchar, "CSM.WavesType"))
		iBlendWeatherNum = iCurWeatherNum;
	// <-- [SticksMod]
}

void MoveSkyToLayers(string sExecuteLayer, string sRealizeLayer)
{
	LayerDelObject("execute",&Sky);
	LayerDelObject("realize",&Sky);
	LayerDelObject(SEA_EXECUTE,&Sky);
	LayerDelObject(SEA_REALIZE,&Sky);

	LayerAddObject(sExecuteLayer,&Sky,2);
	LayerAddObject(sRealizeLayer,&Sky,3);
}