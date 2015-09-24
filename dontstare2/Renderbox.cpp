#include "Renderbox.h"

Renderbox::Renderbox(vec2 _position, vec2 _size, bool _border, bool _visible, char fill = ' ') : position(_position), size(_size), border(_border), visible(_visible) {
	for (int i = 0; i < size.x * size.y; i++) {
		box.push_back(fill);
	}
	setBorder(getBorder());
	usesColors = false;
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

vec2 Renderbox::getColors(vec2 where) {
	if (usesColors) {
		return colors[where.y * size.x + where.x];
	}
	else {
		return vec2(7, 0);
	}
}

void Renderbox::setColors(vec2 colores, int where) {
	if (usesColors) {
		colors[where] = colores;
	}
}

void Renderbox::setColors(vec2 colores, vec2 where) {
	setColors(colores, where.y * size.y + where.x);
}

void Renderbox::writeLine(std::string line, vec2 where) {
	int x = 0;
	for (unsigned int i = where.y * size.x + where.x; i < box.size(); i++) {
		if (line[x]) {
			if (!(border && (i < size.x || i % size.x == 0 || i % size.x == size.x - 1))) {
				setChar(line[x], i);
				x++;
			}
		}
	}
}

vec2 Renderbox::getPosition() {
	return position;
}

void Renderbox::setPosition(vec2 pos) {
	position = pos;
}

vec2 Renderbox::getSize() {
	return size;
}

void Renderbox::setBorder(bool how) {
	std::vector<char> pipes;
	border = how;
	if (border) {
		pipes = { (char)186, (char)205, (char)201, (char)187, (char)200, (char)188 };
	}
	else {
		pipes = { ' ', ' ', ' ', ' ', ' ', ' ' };
	}
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			if (x == 0 || x == size.x - 1) {
				setChar(pipes[0], vec2(x, y));
			}
			if (y == 0 || y == size.y - 1) {
				setChar(pipes[1], vec2(x, y));
			}
			if (x == 0 && y == 0) {
				setChar(pipes[2], vec2(x, y));
			}
			if (x == size.x - 1 && y == 0) {
				setChar(pipes[3], vec2(x, y));
			}
			if (x == 0 && y == size.y - 1) {
				setChar(pipes[4], vec2(x, y));
			}
			if (x == size.x - 1 && y == size.y - 1) {
				setChar(pipes[5], vec2(x, y));
			}
		}
	}
}

bool Renderbox::getBorder() {
	return border;
}

void Renderbox::setVisibility(bool how) {
	visible = how;
}

bool Renderbox::getVisibility() {
	return visible;
}

void Renderbox::useColors(bool how) {
	usesColors = how;
	if (usesColors) {
		for (int i = 0; i < size.x * size.y; i++) {
			colors.push_back(vec2(7, 0));
		}
	}
	else {
		colors.empty();
	}
}

bool Renderbox::doesUseColors() {
	return usesColors;
}
