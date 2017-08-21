#include "vehicle.h"
# include "bikeVehicle.h"
# include "tuktukVehicle.h"
# include "supercarVehicle.h"

CAbstractVehicle* CAbstractVehicle::Create(int _speed, int _craterCrossingTime, VehicleTypeEnum vehicleType)
{
	//Factory method. Deallocation of the created class has to be done by the caller.
	CAbstractVehicle* vehicle;
	switch(vehicleType)
	{
		case BIKE:
			vehicle = new CBikeVehicle(_speed, _craterCrossingTime, "Bike");
			break;
		case TUKTUK:
			vehicle = new CTukTukVehicle(_speed, _craterCrossingTime, "TukTuk");
			break;
		case SUPERCAR:
			vehicle = new CSuperCarVehicle(_speed, _craterCrossingTime, "Super Car");
			break;
	}
	return vehicle;
}
