#ifndef _VEHICLE_
#define _VEHICLE_
# include <string>

using std::string;
#include "constants.h"

class CAbstractVehicle
{
public:	
	CAbstractVehicle(int _speed, int _craterCrossingTime, const string& _veh)
		:speed(_speed),craterCrossingTime(_craterCrossingTime), vehicleType(_veh){}
	int GetSpeed() const {return speed;}
	int GetCraterCrossingTime()const {return craterCrossingTime;}
	const string& GetVehicleType() const { return vehicleType;}

	virtual bool CanTravel(WeatherEnum) = 0;

	static CAbstractVehicle* Create(int _speed, int _craterCrossingTime, VehicleTypeEnum vehicleType);
private:
	int speed;
	int craterCrossingTime;
	string vehicleType;
};
#endif //_VEHICLE_

