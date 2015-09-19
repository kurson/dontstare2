#pragma once
#include "Renderbox.h"

class Screen {
	vec2 size;
	std::vector<char> screen;
	std::vector<Renderbox> boxes;
public:
	Screen(vec2);
	void addBox(Renderbox);
	void print();
	Renderbox* getBox(int);
};
