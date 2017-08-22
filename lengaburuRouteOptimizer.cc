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

//To travel from one place to another, multiple orbits can be taken. Add each orbit time to get total time taken for travel
double CLengaburuRouteOptimizer :: CalculateMultiOrbitTime(const vector<COrbit*>& orbitList, CAbstractVehicle* vehicle, 
					const vector<int>& OrbitTrafficSpeedList, WeatherEnum weather)
{
	double  totalTravelTime = 0.0;
	for(int i=0; i < orbitList.size(); ++i)
	{
		double k = CalculateOrbitTime (orbitList[i], vehicle, OrbitTrafficSpeedList[orbitList[i]->GetOrbitNumber() -1],
                                                        weather);
		totalTravelTime += k;
	}

	return totalTravelTime;
}

void CLengaburuRouteOptimizer :: GetBestTravelRoute(const vector<vector<COrbit*> >& trafficOrbitList, WeatherEnum weather, 
							const vector<int>& orbitTrafficSpeedList)
{
	//large random value taken
	double leastTime = 100000000;

	vector<COrbit*> orbList;
	CAbstractVehicle* veh;

	vector<CAbstractVehicle*> vList = vehicleList[weather];
	for(int i=0; i < trafficOrbitList.size(); ++i)
	{
		for (int j = 0; j < vList.size(); ++j)
		{
			double tempTime = CalculateMultiOrbitTime(trafficOrbitList[i], vList[j], orbitTrafficSpeedList,weather);
			if(tempTime <= leastTime)
			{
				leastTime = tempTime;
				orbList = trafficOrbitList[i];
				veh = vList[j];
			}
		}
	}
	//Presently just outputing the values. This can be returned back to the caller as well.
	cout <<"From SilkDorb covering both hallitharam and RK Puram, the best orbit to take is Orbit"<<orbList[0]->GetOrbitNumber()<<" and Orbit"<<orbList[1]->GetOrbitNumber()<<" using "<<veh->GetVehicleType()<<endl; 

}

//Given a orbit, vehicle and trafic speed, Calculate the time taken considering number of craters and time taken to cross craters
double CLengaburuRouteOptimizer :: CalculateOrbitTime(COrbit* orbit, CAbstractVehicle*  vehicle, const int& OrbitTrafficSpeed, 
							WeatherEnum weather)
{
	//Distance divided by speed gives the time taken. For getting the speed, get applicable speed 
	//based on traffic speed or vehicle speed. Also convert the time to minutes

	double timeTakenWithoutCrater = ((double)(orbit->GetOrbitDistance())/
						(double)(GetApplicableSpeed(vehicle->GetSpeed(), OrbitTrafficSpeed)))*60;

	//Time taken to cross the crater also need to be added. As craters are dependent on weather,
	//Get the actual number of craters too based on weather
	double craterTime = (double)(vehicle->GetCraterCrossingTime() * orbit->GetActualNumberOfCraters(weather));

	return (timeTakenWithoutCrater + craterTime);
}

void CLengaburuRouteOptimizer :: GetOptimizedCombination(WeatherEnum weather, const vector<int>& orbitTrafficSpeedList)
{
	//large random value taken
	double leastTime = 100000000;
	
	COrbit* orb;
	CAbstractVehicle* veh;

	vector<CAbstractVehicle*> vList = vehicleList[weather];
	for(int i=0; i < orbitList.size(); ++i)
	{
		for (int j = 0; j < vList.size(); ++j)
		{
			double tempTime = CalculateOrbitTime(orbitList[i], vList[j], orbitTrafficSpeedList[i], weather);
							
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
