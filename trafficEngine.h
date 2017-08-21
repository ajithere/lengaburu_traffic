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
	vector<CAbstractVehicle*> vehicleList;
protected:
	virtual void CreateRouteOptimizer() = 0;	
	virtual void CreateOrbits() = 0;
	virtual void CreateVehicles() = 0;
public:
	CTrafficEngine(){}
	virtual ~CTrafficEngine(){}

	void ConstructRouteOptimizer();
	void GetOptimizedRoutes(WeatherEnum w, const vector<int>& list){ optimizer->GetOptimizedRoutes(w, list);}
};

#endif //_TRAFFIC_ENGINE_

