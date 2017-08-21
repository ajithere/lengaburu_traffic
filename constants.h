#ifndef _CONSTANTS_
#define _CONSTANTS_

# include <string>
using std::string;

enum WeatherEnum
{
	SUNNY = 1,
	RAINY = 2,
	WINDY = 3,
};

enum VehicleTypeEnum
{
	BIKE = 1,
	TUKTUK,
	SUPERCAR,
};

//Vehicles
const int BIKE_SPEED = 10; //in megamiles/hr
const int BIKE_CRATER_TIME = 2; //in minutes
 
const int TUKTUK_SPEED = 12; //in megamiles/hr
const int TUKTUK_CRATER_TIME = 1; //in minutes

const int SUPERCAR_SPEED = 20; //in megamiles/hr
const int SUPERCAR_CRATER_TIME = 3; //in minutes

//Orbits
const string ORBIT_START_POINT = "SilkDorb";
const string ORBIT_MID_POINT = "RKPuram";
const string ORBIT_END_POINT = "Halitharam";
const int ORBIT_1_DISTANCE = 18; //in megamiles
const int ORBIT_2_DISTANCE = 20; //in megamiles
const int ORBIT_3_DISTANCE = 30; //in megamiles
const int ORBIT_1_CRATERS = 20;
const int ORBIT_2_CRATERS = 10;
const int ORBIT_3_CRATERS = 15;

//Craters
const double TEN_PERCENT = 0.1; //10 percent
const double TWENTY_PERCENT = 0.2; //20 percent

#endif //_CONSTANTS_
