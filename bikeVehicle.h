#ifndef _BIKE_VEHICLE_
#define _BIKE_VEHICLE_

#include "constants.h"
#include "vehicle.h"

class CBikeVehicle : public CAbstractVehicle
{
public:	
	CBikeVehicle(int _speed, int _craterCrossingTime, const string& _veh):CAbstractVehicle(_speed, _craterCrossingTime, _veh){}
	virtual inline bool CanTravel(WeatherEnum w) { return (w == RAINY) ? false : true;}
};
#endif //_BIKE_VEHICLE_


