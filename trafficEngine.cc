#include "trafficEngine.h"

void CTrafficEngine :: ConstructRouteOptimizer()
{
	//Allows the Engine to create the various parts of the optimizer.

	//Create appropriate type of Optimizer. Factory Methods. Based on Traffic engine instantiated,
	//the route optimiser, orbits and vehicles will be created
	CreateRouteOptimizer();	
	CreateOrbits();
	CreateVehicles();
	optimizer->BuildOrbits(orbitList);
	optimizer->BuildVehicles(vehicleList);
}
