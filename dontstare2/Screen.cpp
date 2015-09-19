#include "Screen.h"

Screen::Screen(vec2 _size) : size(_size) {
	for (int i = 0; i < size.x * size.y; i++) {
		screen.push_back(' ');
	}
}

void Screen::addBox(Renderbox box) {
	boxes.push_back(box);
}

void Screen::print() {
	for (unsigned int b = 0; b < boxes.size(); b++) {
		if (boxes[b].getVisibility()) {
			vec2 bSize = boxes[b].getSize();
			vec2 bPosition = boxes[b].getPosition();
			if (boxes[b].getBorderness()) {
				for (int x = 0; x < bSize.x; x++) {
					for (int y = 0; y < bSize.y; y++) {
						if (x == 0 || x == bSize.x - 1) {
							boxes[b].setChar(186, vec2(x, y));
						}
						if (y == 0 || y == bSize.y - 1) {
							boxes[b].setChar(205, vec2(x, y));
						}
						if (x == 0 && y == 0) {
							boxes[b].setChar(201, vec2(x, y));
						}
						if (x == bSize.x - 1 && y == 0) {
							boxes[b].setChar(187, vec2(x, y));
						}
						if (x == 0 && y == bSize.y - 1) {
							boxes[b].setChar(200, vec2(x, y));
						}
						if (x == bSize.x - 1 && y == bSize.y - 1) {
							boxes[b].setChar(188, vec2(x, y));
						}
					}
				}
			}
			for (int x = 0; x < bSize.x; x++) {
				for (int y = 0; y < bSize.y; y++) {
					screen[(size.x * bPosition.y + bPosition.x) + (size.x * y) + x] = boxes[b].getChar(vec2(x, y));
				}
			}
		}
	}
	for (unsigned int i = 0; i < screen.size(); i++) {
		std::cout << screen[i];
	}
}

Renderbox* Screen::getBox(int which) {
	return &boxes[which];
}
