#include "vec2.h"

vec2 vec2::operator +(const vec2& b) {
	vec2 a(x, y);
	a.x += b.x;
	a.y += b.y;
	return a;
}

vec2 vec2::operator -(const vec2& b) {
	vec2 a(x, y);
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

vec2 vec2::operator *(const vec2& b) {
	vec2 a(x, y);
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

vec2 vec2::operator /(const vec2& b) {
	vec2 a(x, y);
	a.x /= b.x;
	a.x /= b.y;
	return a;
}

bool vec2::operator ==(const vec2& b) {
	vec2 a(x, y);
	return (a.x == b.x && a.y == b.y);
}
