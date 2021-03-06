#pragma once
#include <iostream>
#include <vector>
#include "vec2.h"

class Renderbox {
	vec2 position;
	vec2 size;
	bool border;
	bool visible;
	std::vector<char> box;
	bool usesColors;
	std::vector<vec2> colors;
public:
	Renderbox(vec2, vec2, bool, bool, char);
	char getChar(int);
	char getChar(vec2);
	void setChar(char, int);
	void setChar(char, vec2);
	vec2 getColors(vec2);
	void setColors(vec2, int);
	void setColors(vec2, vec2);
	void writeLine(std::string, vec2);
	vec2 getPosition();
	void setPosition(vec2);
	vec2 getSize();
	void setBorder(bool);
	bool getBorder();
	void setVisibility(bool);
	bool getVisibility();
	void useColors(bool);
	bool doesUseColors();
};
