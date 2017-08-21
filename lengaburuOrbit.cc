#include "lengaburuOrbit.h"

int CLengaburuOrbit :: GetActualNumberOfCraters(WeatherEnum w)
{
	int actualCraters;
	switch(w)
	{
		case SUNNY:
			//During sunny weather, Craters decrease by 10%
			actualCraters = numberOfCraters - TEN_PERCENT * numberOfCraters;	
			break;
		case RAINY:
			//During rain, Craters increase by 20%
			actualCraters = numberOfCraters + TWENTY_PERCENT * numberOfCraters;	
			break;
		case WINDY:
			//No change in craters
			actualCraters = numberOfCraters;
			break;
	}
	return actualCraters;
}
