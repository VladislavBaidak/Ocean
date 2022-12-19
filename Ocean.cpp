#include "Ocean.h"
#include "Obstacle.h"
#include "Cell.h"
#include "Constants.h"
#include "Predator.h"
#include "Prey.h"
#include "Random.h"
#include <cstdlib>

Cell* Ocean::getCells(unsigned x, unsigned y)
{
	return cells[y][x];
}

void Ocean::setCells(unsigned x, unsigned y, Cell* newPlace)
{
	cells[y][x] = newPlace;
}

unsigned Ocean::getCols(void)
{
	return numCols;
}

unsigned Ocean::getRows(void)
{
	return numRows;
}

void Ocean::initialise(void)
{
	numRows = MaxRows;
	numCols = MaxCols;
	size = numRows * numCols;
	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	initCells();
}

void Ocean::initCells(void)
{
	addEmptyCells(this);
	cout << "\n\nEnter number of obstancles (default = 75):";
	cout.flush();
	cin >> numObstacles;
	if (numObstacles > size) numObstacles = size;
	cout << endl << "Number obstancles accepted = " << numObstacles;
	cout.flush();

	cout << "\n\n Enter number of predators (default = 20):";
	cout.flush();
	cin >> numPredators;
	if (numPredators > (size - numObstacles))  numPredators = size - numObstacles; 
	cout << "\nNumber predators accepted = " << numPredators;
	cout.flush();

	cout << "\n\n Enter number of prey (default = 150):";
	cout.flush();
	cin >> numPrey;
	if (numPrey > (size - numObstacles - numPredators))  numPrey = size - numObstacles - numPredators;
	cout << "\nNumber prey accepted = " << numPrey;
	cout.flush();

	addObstacles();
	addPredators();
	addPrey();
	displayStats(-1);
	displayCells();
	displayBorder();
}

void Ocean::addEmptyCells(Ocean* ocean)
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++)
		{
			Coordinate r(col, row);
			cells[row][col] = new Cell(r, this);
		}
	}
}

void Ocean::addObstacles(void)
{
	Coordinate empty;
	for (unsigned count = 0; count < numObstacles; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Obstacle(empty,this);
	}
}

void Ocean::addPredators(void)
{
	Coordinate empty;
	for (unsigned count = 0; count < numPredators; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Predator(empty,this);
	}
}

void Ocean::addPrey(void)
{
	Coordinate empty;
	for (unsigned count = 0; count < numPrey; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Prey(empty,this);
	}
}

Coordinate Ocean::getEmptyCellCoord(void)
{
	unsigned x, y;
	Coordinate empty;
	do
	{
		x = rand()% (numCols - 1);
		y = rand() % (numRows - 1);
		/*x = random.nextintBetween(0, numCols - 1);
		y = random.nextintBetween(0, numRows - 1);*/
	} while (cells[y][x]->getImage() != DefaultImage);
	empty = cells[y][x]->getOffset();
	delete cells[y][x];
	return empty;
}

void Ocean::displayBorder(void)
{
	for (unsigned col = 0; col < numCols; col++)
		cout << "*";
	cout << "\n";
}

void Ocean::displayCells(void)
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++)
		{
			cells[row][col]->display();
		}
		cout << endl;
	}
}

void Ocean::displayStats(int iteration)
{
	cout << endl << endl;
	cout << "Iteration number: " << ++iteration;
	cout << "[Obstacles: " << numObstacles << "] ";
	cout << "[Predators: " << numPredators << "] ";
	cout << "[Prey: " << numPrey << "] " << "\n";
	cout.flush();
	displayBorder();
}

void Ocean::run(void)
{
	unsigned numiterations = DefaultNumIterations;
	cout << "\n\n Enter number of iterations (default max = 1000): ";
	cout.flush();
	cin >> numiterations;
	if (numiterations > 1000) numiterations = 1000;
	cout << "\nNumber iterations = " << numiterations << "\nbegin run...\n";
	cout.flush();

	for (unsigned iteration = 0; iteration < numiterations; iteration++)
	{
		if (numPredators > 0 || numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
			{
				for (unsigned col = 0; col < numCols; col++)
				{
					cells[row][col]->process();
				}
			}
			displayStats(iteration);
			displayCells();
			displayBorder();
			cout.flush();

		}
	}
	cout << "\n\nEnd of Simulation\n";
	cout.flush();
}
