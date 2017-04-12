#include "engine.h"



Engine::Engine()
{
	isQuit = false;
	m_pGrapheAPI = GrapheAPI::getInstance();
}

void Engine::init(int w, int h)
{
	m_winWidth = w;
	m_winHeight = h;
}

void Engine::initMap(int w, int h)
{
	m_pGrapheAPI->drawRect(MAP_OFFSET_X, MAP_OFFSET_Y, MAP_OFFSET_X + w, MAP_OFFSET_Y + h);
	m_pGrapheAPI->drawLine(MAP_OFFSET_X + w/2, MAP_OFFSET_Y, MAP_OFFSET_X + w / 2, MAP_OFFSET_Y + h);
}

void Engine::run()
{
	parseInput();
	while (!isQuit)
	{
		//clearScreen();

		m_ball.move();
		m_bat.move(batOffsetY);
		//drawBall();
		//drawBat();
		Sleep(10);
		//if (isBallDrop()) isQuit = true;

	}
}

void Engine::drawBall(int x, int y)
{
	m_ball.draw(x, y);
}

void Engine::drawBat(int x, int y)
{
	m_bat.draw(x, y);
}

bool Engine::isBallDrop()
{
	return false;
}

void Engine::clearScreen()
{


}

int Engine::parseInput()
{
	//m_ball.move();
	//m_bat.move();
	if (KEYDOWN(VK_UP)) m_input = KEYBOARD_UP;
	else if (KEYDOWN(VK_DOWN)) m_input = KEYBOARD_DOWN;
	else if (KEYDOWN(VK_ESCAPE))
	{
		isQuit = true;
	}
}
