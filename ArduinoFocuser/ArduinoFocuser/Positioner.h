// Positioner.h

#ifndef _POSITIONER_h
#define _POSITIONER_h


class Positioner {
public:
	Positioner();
	~Positioner();
	void setPosition(long _position);
	long getPosition();
	void moveAbsolute(long _position);
	void moveRelative(long _change);
	virtual void increment(long _change);
	virtual long getChange();
  virtual void setChange(long _change);
	void setLimitThreshold(long _limitThreshold);
	void setLowLimit(long _lowLimit);
	void setHighLimit(long _highLimit);
	long getLowLimit();
	long getHighLimit();
	double getStepSize();
	virtual void halt();

protected:
	volatile long position, change;
	bool absolute = false;
	virtual void addChange(long _change);
	double maxTravelTurns = 5.75;
	long stepsPerRevolution = 5400; 
	double travelDistancePerTurn = 23.82;
	double stepSize = travelDistancePerTurn / stepsPerRevolution;
	long lowLimit = -1 * (stepsPerRevolution*maxTravelTurns / 2), // 5 turns of a 200*27 step motor
		highLimit = stepsPerRevolution*maxTravelTurns / 2;
	long limitThreshold = .5*stepsPerRevolution;
};

#endif
