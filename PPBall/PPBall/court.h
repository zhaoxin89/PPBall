#pragma once
#include "util.h"

class Court
{
public:
	Court(Point pos, int l, int w) { position = pos; length = l; width = w; }
	void draw();
private:
	Point position;
	int length;
	int width;
};
