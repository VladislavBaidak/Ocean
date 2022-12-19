#pragma once
#ifndef PrayDefined
#define PreyDefined
#include "Cell.h"

class Prey : public Cell
{
protected:
	int timeToReproduce;
	//������ ��������� � �����������
	void moveFrom(Coordinate from, Coordinate to);
	virtual Cell* reprodece(Coordinate anOffset);

public:
	Prey(Coordinate& aCoord) : Cell(aCoord)
	{
		timeToReproduce = TimeToReproduce;
		image = DefaultPreyImage;
	}
	Prey(Coordinate& now, Ocean* owner): Cell(now, owner)
	{
		timeToReproduce = TimeToReproduce;
		image = DefaultPreyImage;
	}
	virtual ~Prey(void);
	//������ ��������� � �����������
	virtual void process(void)
	{
		Coordinate toCoord;
		toCoord = getEmptyNeighborCoord();
		moveFrom(offset, toCoord);
	}
};
#endif

