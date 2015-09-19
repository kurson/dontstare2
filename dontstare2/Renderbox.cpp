#include "Renderbox.h"

Renderbox::Renderbox(vec2 _position, vec2 _size, bool _border, bool _visible, char fill = ' ') : position(_position), size(_size), border(_border), visible(_visible) {
	for (int i = 0; i < size.x * size.y; i++) {
		box.push_back(fill);
	}
}

char Renderbox::getChar(int where) {
	return box[where];
}

char Renderbox::getChar(vec2 where) {
	return box[where.y * size.x + where.x];
}

void Renderbox::setChar(char what, int where) {
	box[where] = what;
}

void Renderbox::setChar(char what, vec2 where) {
	box[where.y * size.x + where.x] = what;
}

void Renderbox::writeLine(std::string line, vec2 where) {
	int x = 0;
	for (unsigned int i = where.y * size.x + where.x; i < box.size(); i++) {
		if (line[x]) {
			setChar(line[x], i);
			x++;
		}
	}
}

vec2 Renderbox::getPosition() {
	return position;
}

vec2 Renderbox::getSize() {
	return size;
}

void Renderbox::setBorder(bool how) {
	border = how;
}

bool Renderbox::getBorderness() {
	return border;
}

void Renderbox::setVisibility(bool how) {
	visible = how;
}

bool Renderbox::getVisibility() {
	return visible;
}
