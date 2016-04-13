// This class is the base class for a focus positioner.
// 
// 

#include "Positioner.h"

Positioner::Positioner()
{
	position = 0;
	change = 0;
}

Positioner::~Positioner()
{

}

void Positioner::setPosition(long _position)
{
	position = _position;
}

long Positioner::getPosition()
{
	return position;
}

void Positioner::moveAbsolute(long _position)
{
	long change = _position - getPosition();
	moveRelative(change);
}

void Positioner::moveRelative(long _change)
{
	addChange(_change);	
}

void Positioner::increment(long _change)
{
	moveRelative(_change);
}

void Positioner::setLimitThreshold(long _limitThreshold)
{
	limitThreshold = _limitThreshold;
}

void Positioner::setLowLimit(long _lowLimit)
{
	lowLimit = _lowLimit;
}

void Positioner::setHighLimit(long _highLimit)
{
	highLimit = _highLimit;
}

long Positioner::getLowLimit()
{
	return lowLimit;
}

long Positioner::getHighLimit()
{
	return highLimit;
}

void Positioner::refresh() {

}

void Positioner::addChange(long _change) {
	Serial.print("Change: "); Serial.println(_change);
	change += _change;
	if (position + change < lowLimit) {
		change = lowLimit - position;
	} else if (position + change > highLimit) {
		change = highLimit - position;
	}
}