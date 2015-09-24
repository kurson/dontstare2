#include <iostream>
#include <vector>
#include "Screen.h"
#include "Player.h"

std::string makePixels(std::string line) {
	for (int i = 0; i < line.length(); i++) {
		switch (line[i]) {
		case '0':
			line[i] = ' ';
			break;
		case '1':
			line[i] = 220;
			break;
		case '2':
			line[i] = 219;
			break;
		case '3':
			line[i] = 223;
			break;
		default:
			break;
		}
	}
	return line;
}


int main() {
	Screen mainscreen(vec2(16, 8));
	mainscreen.addBox(Renderbox(vec2(0, 0), vec2(16, 8), false, true, 220));

	std::string line;

	/*line = "0000001111100222";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 0));
	line = "0000022222232222";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 1));
	line = "0000222222222222";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 2));
	line = "0000332222222230";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 3));
	line = "0122222222222001";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 4));
	line = "2223322222222112";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 5));
	line = "0312122222222222";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 6));
	line = "0233222233300000";
	mainscreen.getBox(0)->writeLine(makePixels(line), vec2(0, 7));*/
	//line = "00000011111002220000022222232222000022222222222200003322222222300122222222222001222332222222211203121222222222220233222233300000";
	line = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	Renderbox* box = mainscreen.getBox(0);
	box->writeLine(makePixels(line), vec2(0, 0));
	box->useColors(true);

	std::vector<vec2> colors = {
		vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(12, 15), vec2(12, 15), vec2(12, 15), vec2(12, 15), vec2(12, 15), vec2(15, 15), vec2(15, 15), vec2(6, 6), vec2(6, 6), vec2(6, 6),
		vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(0, 12), vec2(0, 12), vec2(0, 12), vec2(6, 12), vec2(6, 12), vec2(0, 12), vec2(6, 12), vec2(15, 12), vec2(8, 12), vec2(8, 6), vec2(8, 6),
		vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(0, 0), vec2(6, 6), vec2(0, 0), vec2(0, 6), vec2(6, 6), vec2(6, 6), vec2(6, 0), vec2(0, 6), vec2(6, 6), vec2(6, 6), vec2(6, 8), vec2(8, 8),
		vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 0), vec2(15, 0), vec2(6, 6), vec2(6, 6), vec2(6, 6), vec2(6, 6), vec2(6, 0), vec2(6, 0), vec2(6, 0), vec2(8, 0), vec2(15, 8), vec2(15, 15),
		vec2(15, 15), vec2(8, 15), vec2(8, 8), vec2(8, 8), vec2(8, 8), vec2(8, 8), vec2(8, 8), vec2(8, 12), vec2(12, 8), vec2(8, 8), vec2(8, 8), vec2(8, 12), vec2(12, 8), vec2(15, 15), vec2(15, 15), vec2(8, 15),
		vec2(6, 6), vec2(6, 6), vec2(6, 8), vec2(15, 8), vec2(15, 8), vec2(12, 8), vec2(8, 8), vec2(12, 8), vec2(12, 12), vec2(12, 12), vec2(6, 12), vec2(12, 12), vec2(6, 12), vec2(12, 15), vec2(8, 15), vec2(8, 8),
		vec2(15, 15), vec2(15, 6), vec2(8, 15), vec2(8, 8), vec2(8, 15), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(8, 8), vec2(8, 8),
		vec2(15, 15), vec2(8, 8), vec2(15, 8), vec2(15, 8), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(12, 12), vec2(15, 12), vec2(15, 12), vec2(15, 12), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15), vec2(15, 15),
	};

	for (int i = 0; i < colors.size(); i++) {
		box->setColors(colors[i], i);
	}
	//box->setColors(vec2(12, 0), vec2(0, 0));

	
	while (true) {
		mainscreen.update();
	}
}
