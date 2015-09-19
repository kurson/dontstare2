#include "Screen.h"
#include <Windows.h>


Screen::Screen(vec2 _size) : size(_size) {
	for (int i = 0; i < size.x * size.y; i++) {
		screen.push_back(' ');
		changed.push_back(true);
	}
}

void Screen::setCursor(vec2 position) {
	COORD p = { position.x, position.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void Screen::addBox(Renderbox box) {
	boxes.push_back(box);
}

void Screen::print() {
	for (int i = 0; i < screen.size(); i++) {
		if (changed[i]) {
			setCursor(vec2(i % size.x, i / size.x));
			changed[i] = false;
			std::cout << screen[i];
		}
	}
}

void Screen::update() {
	for (unsigned int b = 0; b < boxes.size(); b++) {
		if (boxes[b].getVisibility()) {
			vec2 bSize = boxes[b].getSize();
			vec2 bPosition = boxes[b].getPosition();
			for (int x = 0; x < bSize.x; x++) {
				for (int y = 0; y < bSize.y; y++) {
					int superposition = (size.x * bPosition.y + bPosition.x) + (size.x * y) + x;
					if (screen[superposition] != boxes[b].getChar(vec2(x, y))) {
						changed[superposition] = true;
						screen[superposition] = boxes[b].getChar(vec2(x, y));
					}
				}
			}
		}
	}
	print();
}

Renderbox* Screen::getBox(int which) {
	return &boxes[which];
}
