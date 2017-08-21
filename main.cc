# include <iostream>
# include "lengaburuRouteOptimizer.h"
# include "constants.h"
# include "lengaburuOrbit.h"
# include "vehicle.h"
 
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int wther;
	int orbit1TrafficSpeed = 0;
	int orbit2TrafficSpeed = 0;

	cout <<"Please enter the weather. 1 for Sunny, 2 for Rainy and 3 for Windy"<<endl;
	cin >>wther;
	if(wther < 1 || wther > 3)
	{
		cout <<"Invalid entries...Expected values are 1,2 or 3. Exiting..."<<endl;;
		return 1;
	}
	cout << "Please enter the current traffic speed in Orbit1" <<endl;
	cin >> orbit1TrafficSpeed;
	cout << "Please enter the current traffic speed in Orbit2" <<endl;
	cin >> orbit2TrafficSpeed;

	//Traffic Engine can be the client who utilizes Route Optimizer. It constructs the route optimizer per city once and
	//then can utilize it across to get Optimized routes multiple times.

	//Creating the Route Optimizer. Uses Builder design pattern. 
	//Creating the orbits. Tomorrow if new routes are created, optimizer logic will still work as its decoupled from 
	// orbit
	//Following YAGNI principle, Not created a factory for Orbits as we have only one orbit. Can refactor and create it
	//when its really needed.
	CAbstractRouteOptimizer* optimizer = new CLengaburuRouteOptimizer(); 

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

	WeatherEnum w = WeatherEnum(wther);

	//Getting the optimized route.
	vector<int> vOrbitTrafficSpeed;
	vOrbitTrafficSpeed.push_back(orbit1TrafficSpeed);
	vOrbitTrafficSpeed.push_back(orbit2TrafficSpeed);
	optimizer->GetOptimizedRoutes(w, vOrbitTrafficSpeed);

	return 0;
}
