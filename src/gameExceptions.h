#ifndef GAME_EXCEPTIONS_H
#define GAME_EXCEPTIONS_H

#include <exception>

class invalidCoordException : public std::exception {
private:
	const char* excMessage;
public:
	invalidCoordException(const char* message) {
		excMessage = message;
	}
	const char* what();
};

class unableToSpawnException : public std::exception {
private:
	const char* excMessage;
public:
	unableToSpawnException(const char* message) {
		excMessage = message;
	}
	const char* what();
};


#endif
