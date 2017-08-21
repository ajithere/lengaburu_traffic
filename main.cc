# include <iostream>
# include "trafficEngine.h"
# include "lengaburuRouteOptimizer.h"
# include "constants.h"
 
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
	CTrafficEngine trafficEngine;
	CAbstractRouteOptimizer* optimizer = new CLengaburuRouteOptimizer(); 
	trafficEngine.ConstructRouteOptimizer(optimizer);
	WeatherEnum w = WeatherEnum(wther);

	//Getting the optimized route.
	vector<int> vOrbitTrafficSpeed;
	vOrbitTrafficSpeed.push_back(orbit1TrafficSpeed);
	vOrbitTrafficSpeed.push_back(orbit2TrafficSpeed);
	optimizer->GetOptimizedRoutes(w, vOrbitTrafficSpeed);

	return 0;
}
