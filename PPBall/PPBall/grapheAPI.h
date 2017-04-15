#pragma once

#include<windows.h>
#include "util.h"

class GrapheAPI
{
public:
	~GrapheAPI();
	static GrapheAPI* getInstance();
	void init(HWND Hwnd);
	void clearScreen(int xs, int ys, int width, int height);
	void drawLine(int xs, int ys, int xe, int ye);
	void drawRect(int x, int y, int length, int width);
	void drawFilledRect(int x, int y, int length, int width);

	void clearFilledRect(int x, int y, int length, int width);

	void drawDot(int x, int y);
	void cleanDot(int x, int y);

private:
	static GrapheAPI *instance;
	HWND hwnd;
	HDC hdc;
};


