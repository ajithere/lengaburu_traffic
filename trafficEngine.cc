#include "trafficEngine.h"
#include <iostream>
#include <vector>
#include "lengaburuOrbit.h"
#include "vehicle.h"


using std::cout;
using std::endl;
using std::vector;

void CTrafficEngine :: ConstructRouteOptimizer(CAbstractRouteOptimizer* optimizer)
{
	//Allows the Engine to create the various parts of the optimizer.
	
	//Creating the orbits. Tomorrow if new routes are created, optimizer logic will still work as its decoupled from 
	// orbit
	//Following YAGNI principle, Not created a factory for Orbits as we have only one orbit. Can refactor and create it
	//when its really needed.
	vector<COrbit*> orbitList;
	orbitList.push_back(new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 1, ORBIT_1_DISTANCE, ORBIT_1_CRATERS));
	orbitList.push_back(new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 2, ORBIT_2_DISTANCE, ORBIT_2_CRATERS));
	optimizer->BuildOrbits(orbitList);

	//Creating the vehicles. Tomorrow if new vehicles are created, optimizer logic will still work as its decoupled from 
	// vehicles

	//Create Vehicle's using Factory Method. This Route optimizer need not know the details of each vehicle.
	
	vector<CAbstractVehicle*> vehicleList;

	vehicleList.push_back(CAbstractVehicle::Create(BIKE_SPEED,BIKE_CRATER_TIME,BIKE)); 
	vehicleList.push_back(CAbstractVehicle::Create(TUKTUK_SPEED,TUKTUK_CRATER_TIME,TUKTUK)); 
	vehicleList.push_back(CAbstractVehicle::Create(SUPERCAR_SPEED,SUPERCAR_CRATER_TIME,SUPERCAR)); 
	optimizer->BuildVehicles(vehicleList);
}
