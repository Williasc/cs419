#ifndef COORD_H
#define COORD_H

#include <exception>

// basic 2D int vector

struct Coord {
	int x, y;

	Coord()
	{
		x = 0;
		y = 0;
	}
	Coord( int x, int y )
	{
		this->x = x;
		this->y = y;
	}
	void set( int x, int y )
	{
		this->x = x;
		this->y = y;
	}
};

enum Direction {
	Up,
	Down,
	Left,
	Right
};

#endif
