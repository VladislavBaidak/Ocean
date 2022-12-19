#pragma once
#ifndef CoordinateDefined
#define CoordinateDefine

class Coordinate
{
private:
	unsigned x;
	unsigned y;

public:
	Coordinate(unsigned aX, unsigned aY) : x(aX), y(aY) {}
	Coordinate(void) { x = 0; y = 0; }
	Coordinate(Coordinate& aCoord)
	{
		x = aCoord.x;
		y = aCoord.y;
	}
	
	~Coordinate(void){}

	//Методи доступа
	unsigned getX(void) { return x; }
	unsigned getY(void) { return y; }
	void setX(unsigned aX) { x = aX; }
	void setY(unsigned aY) { y = aY; }

	//Методы присвоения и сравнения
	void operator = (const Coordinate& aCoord)
	{
		x = aCoord.x;
		y = aCoord.y;
	}

	int operator == (const Coordinate& c)
	{
		return (x == c.x && y == c.y);
	}

	int operator != (const Coordinate& c)
	{
		return (x != c.x || y != c.y);
	}
};
#endif

