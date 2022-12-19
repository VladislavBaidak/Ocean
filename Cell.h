#pragma once
#ifndef CellDefinder
#define CellDefinder

#include "Ocean.h"

class Cell
{
protected:
	
	Ocean* Ocean1;
	Coordinate offset;
	char image;
	//Методы поиска соседей

	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	Cell* getNeighborWithImage(char anImage);
	Coordinate getEmptyNeighborCoord(void);
	Coordinate getPreyNeighborCoord(void);
	Cell* north(void);
	Cell* south(void);
	Cell* east(void);
	Cell* west(void);

	//Методы обработки и отображения
	virtual Cell* reproduce(Coordinate anOffset);

public:
	Cell(Coordinate& aCoord, Ocean* ocean) : offset(aCoord), Ocean1(ocean) { image = DefaultImage; }
	Cell(Coordinate& aCoord) : offset(aCoord) { image = DefaultImage; }
	Cell() {}
	virtual ~Cell(void) {}
	void setOcean(Ocean* ocean) { Ocean1 = ocean; }
	//Методи доступа
	Coordinate& getOffset(void) { return offset; }
	void setOffset(Coordinate& anOffset) { offset = anOffset; }
	char getImage(void) { return image; }

	//Методи обработки и отображения
	void display(void);
	virtual void process(void){} // Не делает ничего
};
#endif
