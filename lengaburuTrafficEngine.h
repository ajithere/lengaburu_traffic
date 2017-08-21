#ifndef _LEN_TRAFFIC_ENGINE_
#define _LEN_TRAFFIC_ENGINE_

#include "trafficEngine.h"

class CLengaburuTrafficEngine : public CTrafficEngine
{
public:
	CLengaburuTrafficEngine(){}
	virtual ~CLengaburuTrafficEngine();

	virtual void CreateRouteOptimizer();
	virtual void CreateOrbits();
	virtual void CreateVehicles();
};

#endif //_LEN_TRAFFIC_ENGINE_

