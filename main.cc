# include <iostream>
# include "constants.h"
# include "lengaburuTrafficEngine.h"
 
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{

	if(argc != 2){
		cout <<"Please enter an input parameter and input only 1 or 2 as the input parameter to the executable"<<endl;
		return 1;
	}

	string str(argv[1]);
	if(str != "1" && str!= "2")
	{
		cout <<"Please enter ./lengaburu 1 for Problem1 and ./lengaburu 2 for problem 2"<<endl;
		return 1;
	}

	int wther;
	int orbit1TrafficSpeed = 0;
	int orbit2TrafficSpeed = 0;
	int orbit3TrafficSpeed = 0;
	int orbit4TrafficSpeed = 0;

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



	if ((argc == 2) && (str == "2"))
	{
		cout << "Please enter the current traffic speed in Orbit3" <<endl;
		cin >> orbit3TrafficSpeed;
		cout << "Please enter the current traffic speed in Orbit4" <<endl;
		cin >> orbit4TrafficSpeed;
	}

	CTrafficEngine* engine = new CLengaburuTrafficEngine();
	engine->ConstructRouteOptimizer();

	WeatherEnum w = WeatherEnum(wther);

	if ((argc == 2) && (str == "1"))
	{
		//Getting the optimized route As per Problem -1.
		vector<int> vOrbitTrafficSpeed;
		vOrbitTrafficSpeed.push_back(orbit1TrafficSpeed);
		vOrbitTrafficSpeed.push_back(orbit2TrafficSpeed);

		engine->GetOptimizedCombination(w, vOrbitTrafficSpeed);
	}
	
	if ((argc == 2) && (str == "2"))
	{
		//Getting the optimized route As per Problem -2.
		vector<int> vTrafficOrbitList;
		vTrafficOrbitList.push_back(orbit1TrafficSpeed);
		vTrafficOrbitList.push_back(orbit2TrafficSpeed);
		vTrafficOrbitList.push_back(orbit3TrafficSpeed);
		vTrafficOrbitList.push_back(orbit4TrafficSpeed);

		engine->GetBestTravelRoute(w, vTrafficOrbitList);
	}

	delete engine;
	return 0;
}
