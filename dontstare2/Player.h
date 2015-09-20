#pragma once
#include "vec2.h"

class Player {
	vec2 position;
public:
	Player(vec2);
	vec2 getPosition();
	void changePosition(vec2);
};