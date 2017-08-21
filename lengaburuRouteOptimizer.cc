#include <iostream>
#include "lengaburuRouteOptimizer.h"
#include "lengaburuOrbit.h"

using std::cout;
using std::endl;

void CLengaburuRouteOptimizer :: BuildOrbits(const vector<COrbit*>& orbList)
{
	//Create Orbit List. Dependency injected from outside
	orbitList = orbList;
}

void CLengaburuRouteOptimizer :: BuildVehicles(const vector<CAbstractVehicle*>& vehList)
{
	//Create Vehicle list based on weathers. Dependency injected from outside. 
	//Create a collection upfront on which vehicles can be used during which weather
	vector<CAbstractVehicle*> v;
	for (int i = SUNNY; i <= WINDY; i++)
	{
		WeatherEnum w = WeatherEnum(i); 
		for (int j = 0; j < vehList.size();++j)
		{
			if(vehList[j]->CanTravel(w))
				v.push_back(vehList[j]);
		}
		vehicleList[w] = v;
		v.clear();
	}
}

void CLengaburuRouteOptimizer :: GetOptimizedRoutes(WeatherEnum weather, const vector<int>& orbitTrafficSpeedList)
{
	//large random value taken
	int leastTime = 100000000;
	
	COrbit* orb;
	CAbstractVehicle* veh;

	vector<CAbstractVehicle*> vList = vehicleList[weather];
	for(int i=0; i < orbitList.size(); ++i)
	{
		for (int j = 0; j < vList.size();++j)
		{
			int tempTime = 
				//Distance divided by speed gives the time taken. For getting the speed, get applicable speed 
				//based on traffic speed or vehicle speed. Also convert the time to minutes
				(orbitList[i]->GetOrbitDistance()/GetApplicableSpeed(vList[j]->GetSpeed(), orbitTrafficSpeedList[i]))*60
				//Time taken to cross the crater also need to be added. As craters are dependent on weather,
				//Get the actual number of craters too based on weather
				+ ((vList[j]->GetCraterCrossingTime()) * orbitList[i]->GetActualNumberOfCraters(weather));
			if(tempTime < leastTime)
			{
				leastTime = tempTime;
				orb = orbitList[i];
				veh = vList[j];
			}
		}
				
	}

	//Presently just outputing the values. This can be returned back to the caller as well.
	cout <<"From SilkDorb to hallitharam, the best orbit to take is Orbit"<<orb->GetOrbitNumber()<<" using "<<veh->GetVehicleType()<<endl; 

}

int CLengaburuRouteOptimizer :: GetApplicableSpeed(int vehicleSpeed, int trafficSpeed)
{
	//applicable speed is vehicle speed or traffic speed based on whichever is lesser
	return ((vehicleSpeed > trafficSpeed) ? trafficSpeed: vehicleSpeed);
}
