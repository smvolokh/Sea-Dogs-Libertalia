#include "SticksMod\SupportTeam.c"
#include "SticksMod\Waves.c"
#include "SticksMod\Weather.c"
#include "SticksMod\ShipsFixes.c"
#include "SticksMod\Utils.c"
#include "SticksMod\SailsAutorepairing.c"
#include "SticksMod\Pusher.c"

extern void SM_SupportTeamInit();

void SticksModInit()
{
	SM_SupportTeamInit();
	SM_FixShipsData();
	SM_WeatherInit();
	SM_PusherOnLoad();
}

void SticksModOnLoad()
{
	SM_SupportTeamOnLoad();
	SM_WeatherOnLoad();
	SM_SailsAutorepairingOnLoad();
}