#pragma once
#ifndef PredatorDefined
#define PredatorDefined
#include "Prey.h"

class Predator: public Prey
{
private:
	//������ ��������� � �����������
	virtual Cell* reproduce(Coordinate anOffset);

protected:
	unsigned timeToFeed;

public:
	Predator(Coordinate aCoord) : Prey(aCoord)
	{
		timeToFeed = TimeToFeed;
		image = DefaultPredImages;
	}
	Predator(Coordinate& now, Ocean* owner) : Prey(now, owner)
	{
		timeToFeed = TimeToFeed;
		image = DefaultPredImages;
	}
	virtual ~Predator(void) {}

	//������ ��������� � �����������
	virtual void process(void);
};
#endif

