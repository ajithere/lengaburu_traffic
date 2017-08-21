#include <sstream>
#include <iostream>
#include "Catch/include/catch.hpp"
#include "../lengaburuOrbit.h"
#include "../trafficEngine.h"
#include "../lengaburuRouteOptimizer.h"

#include <vector>

using std::vector;


SCENARIO( "Checking Optimized routes for various weather and traffic speed combination...", "[Optimized Routes]" ) {
	GIVEN("A set of orbits and a set of vehicles"){
		CTrafficEngine trafficEngine;
		CAbstractRouteOptimizer* optimizer = new CLengaburuRouteOptimizer(); 
		trafficEngine.ConstructRouteOptimizer(optimizer);

		WHEN("The weather is Sunny"){
			WeatherEnum w = WeatherEnum(1);
			AND_WHEN("And the orbit1 traffic speed is set to 12 and orbit2 to 10"){ 
				vector<int> vOrbitTrafficSpeed;
				vOrbitTrafficSpeed.push_back(12);
				vOrbitTrafficSpeed.push_back(10);
				AND_THEN("it is expected that route optimizer will suggest Orbit1 using TukTuk") {
					std::ostringstream oss;
					std::streambuf* p_cout_streambuf = std::cout.rdbuf();
					std::cout.rdbuf(oss.rdbuf());
					optimizer->GetOptimizedRoutes(w, vOrbitTrafficSpeed);
					std::cout.rdbuf(p_cout_streambuf);
					REQUIRE(oss.str() == "From SilkDorb to hallitharam, the best orbit to take is Orbit1 using TukTuk\n");
				}
			}	
		}
		WHEN("The weather is Windy"){
			WeatherEnum w = WeatherEnum(3);
			AND_WHEN("And the orbit1 traffic speed is set to 14 and orbit2 to 20"){ 
				vector<int> vOrbitTrafficSpeed;
				vOrbitTrafficSpeed.push_back(14);
				vOrbitTrafficSpeed.push_back(20);
				AND_THEN("it is expected that route optimizer will suggest Orbit2 using SuperCar\n") {
					std::ostringstream oss;
					std::streambuf* p_cout_streambuf = std::cout.rdbuf();
					std::cout.rdbuf(oss.rdbuf());
					optimizer->GetOptimizedRoutes(w, vOrbitTrafficSpeed);
					std::cout.rdbuf(p_cout_streambuf);
					REQUIRE(oss.str() == "From SilkDorb to hallitharam, the best orbit to take is Orbit2 using Super Car\n");
				}
			}	
		}
	}
}
