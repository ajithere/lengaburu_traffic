#ifndef _TUKTUK_VEHICLE_
#define _TUKTUK_VEHICLE_

#include "constants.h"
#include "vehicle.h"

class CTukTukVehicle : public CAbstractVehicle
{
public:	
	CTukTukVehicle(int _speed, int _craterCrossingTime, const string& _veh):CAbstractVehicle(_speed, _craterCrossingTime, _veh){}
	virtual inline bool CanTravel(WeatherEnum w) { return (w == WINDY) ? false : true;}
};
#endif //_TUKTUK_VEHICLE_


