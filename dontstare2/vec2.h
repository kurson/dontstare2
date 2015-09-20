#pragma once

struct vec2 {
	int x = 0;
	int y = 0;
	vec2(int _x, int _y) : x(_x), y(_y) { }
	vec2 operator +(const vec2&);
};
