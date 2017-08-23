#ifndef _TRAFFIC_ENGINE_
#define _TRAFFIC_ENGINE_

#include "routeOptimizer.h"
#include "orbit.h"
#include "vehicle.h"

class CTrafficEngine
{
protected:
	CAbstractRouteOptimizer* optimizer;
	vector<COrbit*> orbitList;
	vector<COrbit*> masterOrbitList;
	vector<CAbstractVehicle*> vehicleList;
protected:
	virtual void CreateRouteOptimizer() = 0;	
	virtual void CreateOrbits() = 0;
	virtual void CreateVehicles() = 0;

public:
	CTrafficEngine(){}
	virtual ~CTrafficEngine(){}
	virtual void GetOptimizedCombination(WeatherEnum w, const vector<int>& list){}
	virtual void GetBestTravelRoute(WeatherEnum weather, const vector<int>& orbitTrafficSpeedList){}

	void ConstructRouteOptimizer();
};

#endif //_TRAFFIC_ENGINE_

