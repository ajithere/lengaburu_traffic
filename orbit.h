#ifndef _ORBIT_
#define _ORBIT_
# include <string>
using std::string;

#include "constants.h"

class COrbit
{
public:	
	COrbit(const string& start, const string& end, int num, int distance, int craterNum)
		:strOrbitStart(start),strOrbitEnd(end), orbitNumber(num), orbitDistance(distance), numberOfCraters(craterNum){}
	virtual ~COrbit(){}

	int GetOrbitDistance() const { return orbitDistance;}
	int GetOrbitNumber() const { return orbitNumber;}

	//Either we can inject Crater strategy class(which is dependent on weather) as a Dependency Injection into the method
	//or we pass the weather and let the function instantiate the strategy class inside through a factory. Both are ok.
	//Both have its plus and minus :)

	virtual int GetActualNumberOfCraters(WeatherEnum) = 0;
protected:
	string strOrbitStart;
	string strOrbitEnd;
	int orbitNumber;
	int orbitDistance;
	int numberOfCraters;

};
#endif //_ORBIT_

