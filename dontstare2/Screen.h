#pragma once
#include "Renderbox.h"

class Screen {
	vec2 size;
	std::vector<char> screen;
	std::vector<bool> changed;
	std::vector<Renderbox> boxes;
	void setCursor(vec2);
public:
	Screen(vec2);
	void addBox(Renderbox);
	void print();
	void update();
	Renderbox* getBox(int);
};
