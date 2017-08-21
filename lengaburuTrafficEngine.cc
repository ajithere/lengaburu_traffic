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
void CLengaburuTrafficEngine :: CreateOrbits()
{
	//Creating the orbits. Tomorrow if new routes are created, optimizer logic will still work as its decoupled from 
	// orbit
	//Following YAGNI principle, Not created a factory for Orbits as we have only one orbit. Can refactor and create it
	//when its really needed.
	orbitList.push_back(new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 1, ORBIT_1_DISTANCE, ORBIT_1_CRATERS));
	orbitList.push_back(new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 2, ORBIT_2_DISTANCE, ORBIT_2_CRATERS));
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
