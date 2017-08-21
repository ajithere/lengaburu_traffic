#ifndef _SUPERCAR_VEHICLE_
#define _SUPERCAR_VEHICLE_

#include "constants.h"
#include "vehicle.h"

class CSuperCarVehicle : public CAbstractVehicle
{
public:	
	CSuperCarVehicle(int _speed, int _craterCrossingTime, const string& _veh):CAbstractVehicle(_speed, _craterCrossingTime, _veh){}
	virtual bool CanTravel(WeatherEnum w){ return true;}
};
#endif //_SUPERCAR_VEHICLE_


