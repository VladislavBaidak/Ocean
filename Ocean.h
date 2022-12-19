#pragma once
#ifndef OceanDefined
#define OceanDefined
#include "Random.h"
#include "Coordinate.h"
#include "Constants.h"
#include <iostream>
using namespace std;

class Cell;

class Ocean
{
	friend class Cell;
private:
	unsigned numRows;
	unsigned numCols;
	unsigned size;// numRows * numCols
	unsigned numPrey;
	unsigned numPredators;
	unsigned numObstacles;
	Random random;
	Cell* cells[MaxRows][MaxCols];

	// ������ ������������
	void initCells(void);
	void addEmptyCells(Ocean* ocean);
	void addObstacles(void);
	void addPredators(void);
	void addPrey(void);
	Coordinate getEmptyCellCoord(void);

	//������ �����������
	void displayBorder(void);
	void displayCells(void);
	void displayStats(int iteration);

public:
	
	//������ �������
	unsigned getNumPrey(void) { return numPrey; }
	unsigned getNumPredators(void) { return numPredators; }
	void setNumPredators(unsigned aNumber) { numPredators = aNumber; }
	void setNumPrey(unsigned aNumber) { numPrey = aNumber; }

	Cell* getCells(unsigned x, unsigned y);
	void setCells(unsigned x, unsigned y, Cell* newPlace);
	unsigned getRows(void);
	unsigned getCols(void);
	//����� �������������
	void initialise(void);

	//����� ������� �������� �������������
	void run(void);
};
#endif
