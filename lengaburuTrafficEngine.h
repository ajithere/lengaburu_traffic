#ifndef _LEN_TRAFFIC_ENGINE_
#define _LEN_TRAFFIC_ENGINE_

#include "trafficEngine.h"

class CLengaburuTrafficEngine : public CTrafficEngine
{
protected:
	vector<vector<COrbit*> > travelOrbitsList;
public:
	CLengaburuTrafficEngine(){}
	virtual ~CLengaburuTrafficEngine();

	virtual void GetOptimizedCombination(WeatherEnum w, const vector<int>& list);
	virtual void GetBestTravelRoute(WeatherEnum weather, const vector<int>& orbitTrafficSpeedList);
	virtual void CreateRouteOptimizer();
	virtual void CreateOrbits();
	virtual void CreateVehicles();
};

#endif //_LEN_TRAFFIC_ENGINE_

