#pragma once

#include "component.h"
#include "grapheAPI.h"

class Engine
{
public:
	Engine();
	void init(int winWidth, int winHeight);
	void initMap(int w, int h);
	void run();
	void drawBall(int x, int y);
	void drawBat(int x, int y);
	bool isBallDrop();
	void clearScreen();
	int parseInput();
private:
	int m_winWidth, m_winHeight;
	int batOffsetY;
	Ball m_ball;
	Bat m_bat;
	GrapheAPI * m_pGrapheAPI;
	bool isQuit;
	int m_input;
};