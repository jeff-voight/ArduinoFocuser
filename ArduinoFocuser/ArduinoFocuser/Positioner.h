// Positioner.h

#ifndef _POSITIONER_h
#define _POSITIONER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Positioner {
public:
	Positioner();
	virtual ~Positioner();
	void setPosition(long _position);
	long getPosition();
	void moveAbsolute(long _position);
	void moveRelative(long _change);
	virtual void increment(long _change);
	void setLimitThreshold(long _limitThreshold);
	void setLowLimit(long _lowLimit);
	void setHighLimit(long _highLimit);
	long getLowLimit();
	long getHighLimit();

protected:
	long position, change;
	boolean absolute = false;
	virtual void addChange(long _change);
	long lowLimit = -2147483648, highLimit= 2147483647;
	long limitThreshold = 100;
};

#endif

