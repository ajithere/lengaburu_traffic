#ifndef _LENGABURU_ORBIT_
#define _LENGABURU_ORBIT_
# include <string>
using std::string;

#include "orbit.h"
#include "constants.h"

class CLengaburuOrbit : public COrbit
{
public:	
	CLengaburuOrbit(const string& start, const string& end, int num, int distance, int craterNum)
		:COrbit(start, end, num, distance, craterNum){ }
	~CLengaburuOrbit(){}

	virtual int GetActualNumberOfCraters(WeatherEnum);

};
#endif //_LENGABURU_ORBIT_


