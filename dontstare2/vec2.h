#pragma once

struct vec2 {
	int x = 0;
	int y = 0;
	vec2(int _x, int _y) : x(_x), y(_y) { }
	vec2 operator +(const vec2&);
	vec2 operator -(const vec2&);
	vec2 operator *(const vec2&);
	vec2 operator /(const vec2&);
	bool operator == (const vec2&);
};
