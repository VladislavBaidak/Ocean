#include "Predator.h"

Cell* Predator::reproduce(Coordinate anOffset)
{
    Predator* temp = new Predator(anOffset);
    Ocean1->setNumPredators(Ocean1->getNumPredators());
    return(Cell*)temp;
}

void Predator::process(void)
{
    Coordinate toCoord;
    if (--timeToFeed <= 0) //DIE
    {
        assignCellAt(offset, new Cell(offset));
        Ocean1->setNumPredators(Ocean1->getNumPredators() - 1);
        delete this;
    }
    else //time to eat
    {
        toCoord = getPreyNeighborCoord();
        if (toCoord != offset)
        {
            Ocean1->setNumPrey(Ocean1->getNumPrey() - 1);
            timeToFeed = TimeToFeed;
            moveFrom(offset, toCoord);
        }
        else
        {
            Prey::process();
        }
    }
}
