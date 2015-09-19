#include <iostream>
#include <vector>
#include "Screen.h"


int main() {
	Screen mainscreen(vec2(80, 25));
	mainscreen.addBox(Renderbox(vec2(0, 1), vec2(20, 10), true, true, ' '));
	mainscreen.addBox(Renderbox(vec2(40, 1), vec2(40, 15), false, true, ' '));
	mainscreen.getBox(0)->writeLine("HALO HALO, WITAM TU $CORPIONS, PODAJEMY KOMUNIKAT, YEBAC YETI, DZIEKUJE ZA UWAGE, DOBRANOC", vec2(0, 0));
	mainscreen.getBox(1)->writeLine("Kurde bele czy to dziala czy nie dziala zaraz sie dowiemy", vec2(0, 0));
	mainscreen.addBox(Renderbox(vec2(25, 11), vec2(30, 3), true, true, ' '));
	mainscreen.getBox(2)->writeLine("Czy chcesz kontynuowac? Y/N", vec2(1, 1));
	mainscreen.print();
	char a;
	std::cin >> a;
}
