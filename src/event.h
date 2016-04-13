// class Event and derived classes

#ifndef EVENT_H
#define EVENT_H

#include "gameActor.h"

enum EventType {
	NullEvent,
	Input,
	Move,
	Collision,
	EndGame
};

struct Event {
public:
	EventType event;
	GameActor* subject;

	Event(EventType e, GameActor* a) : event(e), subject(a) {}
};

#endif
