#include "Cell.h"

Cell* Cell::getCellAt(Coordinate aCoord)
{
    return Ocean1->getCells(aCoord.getX(),aCoord.getY());
}

void Cell::assignCellAt(Coordinate aCoord, Cell* aCell)
{
    Ocean1->setCells(aCoord.getX(), aCoord.getY(), aCell);
}

Cell* Cell::getNeighborWithImage(char anImage)
{
    Cell* neighbors[4];
    unsigned count = 0;
    if (north()->getImage() == anImage) neighbors[count++] = north();
    if (south()->getImage() == anImage) neighbors[count++] = south();
    if (east()->getImage() == anImage) neighbors[count++] = east();
    if (west()->getImage() == anImage) neighbors[count++] = west();
    if (count == 0)
        return this;
    else
        return neighbors[1+rand()% (count - 1)];
}

Coordinate Cell::getEmptyNeighborCoord(void)
{
    return getNeighborWithImage(DefaultImage)->getOffset();
}

Coordinate Cell::getPreyNeighborCoord()
{
    return getNeighborWithImage(DefaultPredImages)->getOffset();
}

Cell* Cell::north(void)
{
    unsigned yvalue;
    if (offset.getY() > 0)
    {
        yvalue = offset.getY() - 1;
    }
    else
    {
        yvalue = Ocean1->numCols - 1;
    }
    unsigned x = offset.getX();
    unsigned y = yvalue;
    return Ocean1->getCells(x,y);
    //xvalue = (offset.getX() > 0) ? (offset.getX() - 1) : (Ocean1->numCols - 1);
    //cout << Ocean1->size;

}

Cell* Cell::south(void)
{
    unsigned yvalue;
    if (offset.getY() < Ocean1->numCols)
    {
        yvalue = offset.getY() + 1;
    }
    else
    {
        yvalue = 0;
    }
    unsigned x = offset.getX();
    unsigned y = yvalue;
    return Ocean1->getCells(x, y);
}

Cell* Cell::east(void)
{
    unsigned xvalue;
    if (offset.getX() < Ocean1->numRows)
    {
        xvalue = offset.getX() + 1;
    }
    else
    {
        xvalue = 0;
    }
    unsigned x = xvalue;
    unsigned y = offset.getY();
    return Ocean1->getCells(x, y);
}

Cell* Cell::west(void)
{
    unsigned xvalue;
    if (offset.getX() > 0)
    {
        xvalue = offset.getX() - 1;
    }
    else
    {
        xvalue = Ocean1->numRows - 1;
    }
    unsigned x = xvalue;
    unsigned y = offset.getY();
    return Ocean1->getCells(x, y);
}

Cell* Cell::reproduce(Coordinate anOffset)
{
    Cell* temp = new Cell(anOffset);
    return temp;
}

void Cell::display(void)
{
    cout << ("%c", image);
}
