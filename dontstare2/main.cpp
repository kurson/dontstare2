#include <iostream>
#include <vector>

using namespace std;

struct vec2 {
	int x = 0;
	int y = 0;
	vec2(int _x, int _y) : x(_x), y(_y) { }
};

class Renderbox {
	vec2 position;
	vec2 size;
	bool border;
	bool visible;
	vector<char> box;
public:
	Renderbox(vec2 _position, vec2 _size, bool _border, bool _visible, char fill = ' ') : position(_position), size(_size), border(_border), visible(_visible) {
		for (int i = 0; i < size.x * size.y; i++) {
			box.push_back(fill);
		}
	}
	char getChar(int where) {
		return box[where];
	}
	char getChar(vec2 where) {
		return box[where.y * size.x + where.x];
	}
	void setChar(char what, int where) {
		box[where] = what;
	}
	void setChar(char what, vec2 where) {
		box[where.y * size.x + where.x] = what;
	}
	void writeLine(string line, vec2 where) {
		int x = 0;
		for (int i = where.y * size.x + where.x; i < box.size(); i++) {
			if (line[x]) {
				setChar(line[x], i);
				x++;
			}
		}
	}
	vec2 getPosition() {
		return position;
	}
	vec2 getSize() {
		return size;
	}
	void setBorder(bool what) {
		border = what;
	}
	bool getBorderness() {
		return border;
	}
	void setVisibility(bool what) {
		visible = what;
	}
	bool getVisibility() {
		return visible;
	}
};

class Screen {
	vec2 size;
	vector<char> screen;
	vector<Renderbox> boxes;
public:
	Screen(vec2 _size) : size(_size) {
		for (int i = 0; i < size.x * size.y; i++) {
			screen.push_back(' ');
		}
	}
	void addBox(Renderbox box) {
		boxes.push_back(box);
	}
	void print() {
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
		for (int i = 0; i < screen.size(); i++) {
			cout << screen[i];
		}
	}
	Renderbox* getBox(int which) {
		return &boxes[which];
	}
};

int main() {
	Screen mainscreen(vec2(80, 25));
	mainscreen.addBox(Renderbox(vec2(20, 1), vec2(20, 24), true, true));
	mainscreen.addBox(Renderbox(vec2(40, 1), vec2(40, 15), true, true));
	mainscreen.getBox(0)->writeLine("HALO HALO, WITAM TU $CORPIONS, PODAJEMY KOMUNIKAT, YEBAC YETI, DZIEKUJE ZA UWAGE, DOBRANOC", vec2(2, 3));
	mainscreen.getBox(1)->writeLine("Kurde bele czy to dziala czy nie dziala zaraz sie dowiemy", vec2(2, 3));
	mainscreen.addBox(Renderbox(vec2(25, 11), vec2(30, 3), true, true));
	mainscreen.getBox(2)->writeLine("Czy chcesz kontynuowac? Y/N", vec2(1, 1));
	mainscreen.print();
	char a;
	cin >> a;
}