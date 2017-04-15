#include "engine.h"



Engine::Engine()
{
	isQuit = false;
	batOffsetY = 1;
	m_input = 2;
	m_pGrapheAPI = GrapheAPI::getInstance();
}

void Engine::init(int w, int h, HWND &hwnd)
{
	m_winWidth = w;
	m_winHeight = h;
	m_hwnd = hwnd;
}

void Engine::initMap(int w, int h)
{
	m_pGrapheAPI->drawRect(MAP_OFFSET_X, MAP_OFFSET_Y, w, h);
	m_pGrapheAPI->drawLine(MAP_OFFSET_X + w/2, MAP_OFFSET_Y, MAP_OFFSET_X + w / 2, MAP_OFFSET_Y + h);
	m_bat.init();
	m_ball.init();
	//m_pGrapheAPI->drawRect(50, 50, 550, 350);
	//m_pGrapheAPI->drawLine(300, 50, 300, 350);
}

void Engine::run()
{
	while (!isQuit)
	{
		parseInput();
		//clearScreen();

		//m_ball.move();
		m_bat.move(m_input, batOffsetY);
		m_ball.move();
		//m_pGrapheAPI->drawLine(MAP_OFFSET_X + w / 2, MAP_OFFSET_Y, MAP_OFFSET_X + w / 2, MAP_OFFSET_Y + h);
		m_input = 2;
		//drawBall();
		//drawBat();
		Sleep(20);
		//if (isBallDrop()) isQuit = true;

	}
	return;
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

void Engine::parseInput()
{
	//m_ball.move();
	//m_bat.move();
	if (KEYDOWN(VK_UP)) m_input = KEYBOARD_UP;
	else if (KEYDOWN(VK_DOWN)) m_input = KEYBOARD_DOWN;
	else if (KEYDOWN(VK_ESCAPE))
	{
		isQuit = true;
		SendMessage(m_hwnd, WM_CLOSE, 0, 0);
	}
}
