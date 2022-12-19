#pragma once
#ifndef ObstacleDefine
#define ObstacleDefine
#include "Predator.h"

class Obstacle: public Cell
{
public:
	Obstacle(Coordinate& aCoord) : Cell(aCoord)
	{
		image = ObstacleImage;
	}
	Obstacle(Coordinate& aCoord, Ocean* ocean) : Cell(aCoord, ocean)
	{
		image = ObstacleImage;
	}

	virtual ~Obstacle(void) {}
};
#endif

