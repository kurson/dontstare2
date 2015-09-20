#include <iostream>
#include <vector>
#include "Screen.h"
#include "Player.h"


int main() {
	Screen mainscreen(vec2(80, 24));
	mainscreen.addBox(Renderbox(vec2(0, 0), vec2(80, 24), false, true, ' '));
	
	Player bob(vec2(0, 0));

	while (true) {
		bob.changePosition(vec2(2, 1));
		std::cout << bob.getPosition().x << " "<< bob.getPosition().y << std::endl;
		//mainscreen.update();
	}
}
