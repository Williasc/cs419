#include "gameExceptions.h"

const char* invalidCoordException::what() {
		return excMessage;
	}

const char* unableToSpawnException::what() {
		return excMessage;
	}
