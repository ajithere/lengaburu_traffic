#define CATCH_CONFIG_MAIN 
#include "Catch/include/catch.hpp"

#include "../lengaburuOrbit.h"

SCENARIO( "Test Route Orbit for Craters", "[Orbit Craters]" ) {

	GIVEN("An orbit in Bangalore"){
		COrbit* orb = new CLengaburuOrbit(ORBIT_START_POINT, ORBIT_END_POINT, 1, ORBIT_1_DISTANCE, 10);
		WHEN("its Rainy"){
			WeatherEnum w = WeatherEnum(2);
			THEN("Number of craters increase by 20% ") {
				REQUIRE(orb->GetActualNumberOfCraters(w) == 12);
			}
		}
		AND_WHEN("Its Sunny"){
			WeatherEnum w = WeatherEnum(1);
			AND_THEN("Number of craters decrease by 10% ") {
				REQUIRE(orb->GetActualNumberOfCraters(w) == 9);
			}
			
		}
		AND_WHEN("Its Windy"){
			WeatherEnum w = WeatherEnum(3);
			AND_THEN("Number of craters remain the same") {
				REQUIRE(orb->GetActualNumberOfCraters(w) == 10);
			}
			
		}

	}
}
