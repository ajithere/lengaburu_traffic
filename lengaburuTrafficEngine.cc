#include "lengaburuTrafficEngine.h"
#include <vector>
#include "lengaburuOrbit.h"
#include "lengaburuRouteOptimizer.h"
#include "vehicle.h"

using std::vector;

void CLengaburuTrafficEngine :: CreateRouteOptimizer()
{
	optimizer = new CLengaburuRouteOptimizer();
}

void CLengaburuTrafficEngine :: GetOptimizedCombination(WeatherEnum w, const vector<int>& list)
{
	optimizer->GetOptimizedCombination(w, list);
}

void CLengaburuTrafficEngine :: GetBestTravelRoute(WeatherEnum weather, const vector<int>& orbitTrafficSpeedList)
{
	optimizer->GetBestTravelRoute(travelOrbitsList, weather, orbitTrafficSpeedList);
}

void CLengaburuTrafficEngine :: CreateOrbits()
{
	//Creating the orbits. Tomorrow if new routes are created, optimizer logic will still work as its decoupled from 
	// orbit
	//Following YAGNI principle, Not created a factory for Orbits as we have only one orbit. Can refactor and create it
	//when its really needed.
	COrbit* orbit1 = new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 1, ORBIT_1_DISTANCE, ORBIT_1_CRATERS);
	COrbit* orbit2 = new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 2, ORBIT_2_DISTANCE, ORBIT_2_CRATERS);
	COrbit* orbit3 = new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_MID_POINT, 3, ORBIT_3_DISTANCE, ORBIT_3_CRATERS);
	COrbit* orbit4 = new CLengaburuOrbit(ORBIT_END_POINT, ORBIT_MID_POINT, 4, ORBIT_4_DISTANCE, ORBIT_4_CRATERS);

	//Data structure For Problem-1
	orbitList.push_back(orbit1);
	orbitList.push_back(orbit2);

	//Create Container of Orbit lists which takes a person from one place to another
	//For travelling from Silk Dorb and to cover Hallitharam and RK Puram, the possible routes are as follows
	//Orbit1 + Orbit4
	vector<COrbit*> travelOrbits;

	travelOrbits.push_back(orbit1);
	travelOrbits.push_back(orbit4);
	travelOrbitsList.push_back(travelOrbits);
	travelOrbits.clear();

	//Orbit2 + Orbit4
	travelOrbits.push_back(orbit2);
	travelOrbits.push_back(orbit4);
	travelOrbitsList.push_back(travelOrbits);
	travelOrbits.clear();

	//Orbit3 + Orbit4
	travelOrbits.push_back(orbit3);
	travelOrbits.push_back(orbit4);
	travelOrbitsList.push_back(travelOrbits);
	travelOrbits.clear();
	
}
void CLengaburuTrafficEngine :: CreateVehicles()
{
	//Creating the vehicles. Tomorrow if new vehicles are created, optimizer logic will still work as its decoupled from 
	// vehicles

	//Create Vehicle's using Factory Method. This Route optimizer need not know the details of each vehicle.
	
	vehicleList.push_back(CAbstractVehicle::Create(BIKE_SPEED,BIKE_CRATER_TIME,BIKE)); 
	vehicleList.push_back(CAbstractVehicle::Create(TUKTUK_SPEED,TUKTUK_CRATER_TIME,TUKTUK)); 
	vehicleList.push_back(CAbstractVehicle::Create(SUPERCAR_SPEED,SUPERCAR_CRATER_TIME,SUPERCAR)); 
}

CLengaburuTrafficEngine :: ~CLengaburuTrafficEngine()
{

	delete  optimizer;
	optimizer = 0;

	for(int i=0; i<orbitList.size();++i)
		delete orbitList[i];
	for(int j=0; j<vehicleList.size();++j)
		delete vehicleList[j];

	orbitList.clear();
	vehicleList.clear();
}
