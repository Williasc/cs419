#include "move.h"

// returns modified coordinates to implement requested move direction
Coord move( Coord s, Direction d ) {
	switch (d) {
	case Up:
		s.y -= 1;
		break;
	case Down:
		s.y += 1;
		break;
	case Left:
		s.x -= 1;
		break;
	case Right:
		s.x += 1;
		break;
	default:
		throw("Invalid Movement direction");
	}
	return s;
}
