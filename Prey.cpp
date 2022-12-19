#include "Prey.h"

void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* tocell;
	--timeToReproduce;
	if (to != from)
	{
		tocell = getCellAt(to);
		delete tocell;
		setOffset(to);
		assignCellAt(to, this);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			assignCellAt(from, reproduce(from));
		}
		else
		{
			assignCellAt(from, new Cell(from, Ocean1));
		}
	}

}

Cell* Prey::reprodece(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset, Ocean1);
	Ocean1->setNumPredators(Ocean1->getNumPrey() + 1);
	return (Cell*)temp;
}

Prey::~Prey(void)
{
}
