#pragma once

#include "util.h"
#include "grapheAPI.h"

class Ball
{
public:
	Ball();
	~Ball() {};
	void draw(int x, int y);
	void move();

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
	void draw(int x, int y);
	void move(int key);
private:
	int locationX;
	int locationY;
	int length;

	HDC hdc;
	HWND hwnd;
	GrapheAPI *grapheAPI;
};