#pragma once
#include <windows.h>

#define MAP_OFFSET_X 50
#define MAP_OFFSET_Y 50

#define KEYBOARD_UP 0
#define KEYBOARD_DOWN 1
#define KEYBOARD_LEFT 2
#define KEYBOARD_RIGHT 3

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

class Point
{
public:
	Point() :x(0), y(0) {}
	Point(float X, float Y) { x = Y; y = Y; }
	void set(float a, float b) { x = a; y = b; }
	float getX() { return x; }
	float getY() { return y; }

	float x;
	float y;
};



typedef Point Vector;