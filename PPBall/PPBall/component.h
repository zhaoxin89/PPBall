#pragma once

#include "util.h"
#include "grapheAPI.h"

class Ball
{
public:
	Ball();
	~Ball() {};
	void init();
	void move();
	void draw(int x, int y);

private:
	Point position;
	Vector direction;
	int radius;
	float speed;
	int locationX;
	int locationY;

	HDC hdc;
	HWND hwnd;
	GrapheAPI *grapheAPI;
};

class Bat
{
public:
	Bat();
	~Bat() {};
	void init();
	void draw(int x, int y);
	void move(int key, int offset);
private:
	int locationX;
	int locationY;
	int length;

	HDC hdc;
	HWND hwnd;
	GrapheAPI *grapheAPI;
};