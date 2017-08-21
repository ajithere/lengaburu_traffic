#ifndef _AB_ROUTE_OPTIMIZER_
#define _AB_ROUTE_OPTIMIZER_

# include "constants.h"
# include "orbit.h"
# include "vehicle.h"

#include <vector>
using std::vector;

class CAbstractRouteOptimizer
{
public:
	virtual void BuildOrbits(const vector<COrbit*>&) = 0;
	virtual void BuildVehicles(const vector<CAbstractVehicle*>&) = 0;

	virtual void GetOptimizedRoutes(WeatherEnum, const vector<int>&) = 0;
};

#endif //_AB_ROUTE_OPTIMIZER_
