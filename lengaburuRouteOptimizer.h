#ifndef _LENGABURU_ROUTE_OPTIMIZER_
#define _LENGABURU_ROUTE_OPTIMIZER_
# include <map>
#include <vector>

using std::map;
using std::vector;

#include "routeOptimizer.h"
#include "vehicle.h"
#include "orbit.h"

class CLengaburuRouteOptimizer : public CAbstractRouteOptimizer
{
public:	
	virtual void BuildOrbits(const vector<COrbit*>&);
	virtual void BuildVehicles(const vector<CAbstractVehicle*>&);
	virtual void GetOptimizedCombination(WeatherEnum, const vector<int>&);
	virtual void GetBestTravelRoute(const vector<vector<COrbit*> >&, WeatherEnum, const vector<int>&);

private:
	map <WeatherEnum, vector<CAbstractVehicle*> > vehicleList;
	vector<COrbit*> orbitList;

	int GetApplicableSpeed(int vehicleSpeed, int trafficSpeed);
	double CalculateOrbitTime(COrbit*, CAbstractVehicle*, const int&, WeatherEnum);
	double CalculateMultiOrbitTime(const vector<COrbit*>&, CAbstractVehicle*, const vector<int>&, WeatherEnum weather);
};
#endif //_LENGABURU_ROUTE_OPTIMIZER_

