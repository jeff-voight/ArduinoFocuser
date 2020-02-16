// This class is the base class for a focus positioner.
// 
// 

#include "Positioner.h"

Positioner::Positioner()
{
	position = 10000;
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

void Positioner::moveRelative(long _change)
{
	addChange(_change);	
}

void Positioner::increment(long _change)
{
	moveRelative(_change);
}

long Positioner::getChange()
{
	return change;
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

double Positioner::getStepSize()
{
	return stepSize;
}

void Positioner::setChange(long _change){
  change=_change;
}

void Positioner::halt() {
	change = 0;
}

void Positioner::addChange(long _change) {
	change += _change;
//	if (position + change < lowLimit) {
//		change = lowLimit - position;
//	} else if (position + change > highLimit) {
//		change = highLimit - position;
//	}
}
