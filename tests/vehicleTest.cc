#include "Catch/include/catch.hpp"
#include "../bikeVehicle.h"
#include "../tuktukVehicle.h"
#include "../supercarVehicle.h"
#include "../vehicle.h"

#include <string>

using std::string;

SCENARIO( "Checking whether it can travel in the given weather...", "[Travel Weather]" ) {

	GIVEN("A bike vehicle"){
		CAbstractVehicle* v = CAbstractVehicle::Create(BIKE_SPEED,BIKE_CRATER_TIME,BIKE);
		REQUIRE(v != 0);
		WHEN("its Rainy"){
			WeatherEnum w = WeatherEnum(2);
			THEN("it cannot be used") {
				REQUIRE(v->CanTravel(w) == false);
			}
		}
		AND_WHEN("its Sunny"){
			WeatherEnum w = WeatherEnum(1);
			AND_THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
			
		}
		AND_WHEN("its Windy"){
			WeatherEnum w = WeatherEnum(3);
			AND_THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
		}
		delete v;
	}
	GIVEN("A tuktuk vehicle"){
		CAbstractVehicle* v = CAbstractVehicle::Create(TUKTUK_SPEED,TUKTUK_CRATER_TIME,TUKTUK);
		REQUIRE(v != 0);
		WHEN("its Rainy"){
			WeatherEnum w = WeatherEnum(2);
			THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
		}
		AND_WHEN("its Sunny"){
			WeatherEnum w = WeatherEnum(1);
			AND_THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
			
		}
		AND_WHEN("its Windy"){
			WeatherEnum w = WeatherEnum(3);
			AND_THEN("it cannot be used") {
				REQUIRE(v->CanTravel(w) == false);
			}
		}
		delete v;
	}
	GIVEN("A supercar vehicle"){
		CAbstractVehicle* v = CAbstractVehicle::Create(SUPERCAR_SPEED,SUPERCAR_CRATER_TIME,SUPERCAR);
		REQUIRE(v != 0);
		WHEN("its Rainy"){
			WeatherEnum w = WeatherEnum(2);
			THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
		}
		AND_WHEN("its Sunny"){
			WeatherEnum w = WeatherEnum(1);
			AND_THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
			
		}
		AND_WHEN("its Windy"){
			WeatherEnum w = WeatherEnum(3);
			AND_THEN("it can be used") {
				REQUIRE(v->CanTravel(w) == true);
			}
		}
		delete v;
	}
}
