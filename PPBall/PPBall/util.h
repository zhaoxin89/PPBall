#pragma once
#include <windows.h>

#define MAP_OFFSET_X 50
#define MAP_OFFSET_Y 50

#define MAP_WIDTH 500
#define MAP_HEIGHT 300

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
	Point(int X, int Y) { x = Y; y = Y; }
	void set(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }

	int x;
	int y;
};



typedef Point Vector;