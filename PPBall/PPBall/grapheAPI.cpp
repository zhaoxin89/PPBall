#include "grapheAPI.h"

GrapheAPI *GrapheAPI::instance = NULL;

GrapheAPI::~GrapheAPI()
{
	if (instance)
	{
		delete(instance);
		instance = NULL;
	}
}

GrapheAPI * GrapheAPI::getInstance()
{
	if (!instance)
	{
		//instance = this;
		instance = new GrapheAPI;
		return instance;
	}
	else 
		return instance;
}

void GrapheAPI::init(HWND Hwnd)
{
	hwnd = Hwnd;
	hdc = NULL;
}

void GrapheAPI::drawRect(int x, int y, int length, int width)
{
	hdc = GetDC(hwnd);
	HBRUSH newBrush;
	newBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, newBrush);
	RECT r;
	SetRect(&r, x, y, x + length, y + width);
	FrameRect(hdc, &r, newBrush);
	DeleteObject(newBrush);

	ReleaseDC(hwnd, hdc);
}

void GrapheAPI::drawFilledRect(int x, int y, int length, int width)
{
	hdc = GetDC(hwnd);

	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + width; j++)
		{
			SetPixel(hdc, i, j, RGB(255, 255, 255));
		}
	}

	ReleaseDC(hwnd, hdc);
}

void GrapheAPI::clearFilledRect(int x, int y, int length, int width)
{
	hdc = GetDC(hwnd);

	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + width; j++)
		{
			SetPixel(hdc, i, j, RGB(0, 0, 0));
		}
	}

	ReleaseDC(hwnd, hdc);
}

void GrapheAPI::drawLine(int xs, int ys, int xe, int ye)
{
	hdc = GetDC(hwnd);
	float slope = 0;
	int flag = 0;
	if (xs == xe) flag = 2;
	
	else float slope = (ye - ys) / (xe - xs);

	flag = (abs((int)slope) >= 1 ? 1 : 0);
	switch (flag)
	{
	case 0:
		for (int i = xs; i < xe; i++)
		{
			SetPixel(hdc, i, ys + i * slope, RGB(255, 255, 255));
		}
	case 1:
		for (int i = ys; i < ye; i++)
		{
			SetPixel(hdc, xs + i / slope, i, RGB(255, 255, 255));
		}
	case 2:
		for (int i = ys; i < ye; i++)
		{
			SetPixel(hdc, xs, i, RGB(255, 255, 255));
		}

	}

	ReleaseDC(hwnd, hdc);
	
}

void GrapheAPI::clearScreen(int xs, int ys, int w, int h)
{
	hdc = GetDC(hwnd);
	for (int i = xs; i < xs + w; i++)
	{
		for (int j = ys; j < ys + h; j++)
		{
			SetPixel(hdc, i, j, RGB(0, 0, 0));
		}
	}
	ReleaseDC(hwnd, hdc);
}

void GrapheAPI::drawDot(int x, int y)
{
	hdc = GetDC(hwnd);
	SetPixel(hdc, x, y, RGB(255, 255, 255));
	ReleaseDC(hwnd, hdc);
}

void GrapheAPI::cleanDot(int x, int y)
{
	hdc = GetDC(hwnd);
	SetPixel(hdc, x, y, RGB(0, 0, 0));
	ReleaseDC(hwnd, hdc);
}
