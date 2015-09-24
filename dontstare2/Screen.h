#pragma once
#include "Renderbox.h"

class Screen {
	vec2 size;
	std::vector<char> screen;
	std::vector<bool> changed;
	std::vector<Renderbox> boxes;
	std::vector<vec2> colors;
	void setCursor(vec2);
	void setTextColor(vec2);
public:
	Screen(vec2);
	void addBox(Renderbox);
	void print();
	void update();
	Renderbox* getBox(int);
};
