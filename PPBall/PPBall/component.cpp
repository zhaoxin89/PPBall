#include "component.h"

//BALL/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Ball::Ball()
{
	position.set(50, 50);
	direction.set(1, 0);
	speed = 5;
	radius = 2;
}

void Ball::move()
{
	int l = radius * 2;
	//clear current ball
	if(!(locationX == (MAP_OFFSET_X + MAP_WIDTH/2)))
	GrapheAPI::getInstance()->clearFilledRect(locationX, locationY, l, l);
	if (locationX <= MAP_OFFSET_X + 1)
	{
		direction.x = -direction.x;
	}
	if (locationX + l + 1 >= MAP_OFFSET_X+MAP_WIDTH)
	{
		direction.x = -direction.x;
	}
	if (locationY <= MAP_OFFSET_Y + 1)
	{
		direction.y = -direction.y;
	}
	if (locationY + l + 1>= MAP_OFFSET_Y + MAP_HEIGHT)
	{
		direction.y = -direction.y;
	}
	//calculate new position

	locationX += direction.x;
	locationY += direction.y;
	GrapheAPI::getInstance()->drawFilledRect(locationX, locationY, l, l);
	//draw a new ball
	
}

void Ball::draw(int x, int y)
{
}

void Ball::init()
{
	int l = radius * 2;
	locationX = MAP_OFFSET_X + 5;
	locationY = MAP_OFFSET_Y + (int)(MAP_HEIGHT / 2);
	GrapheAPI::getInstance()->drawFilledRect(locationX, locationY, l, l);
	direction.set(1, 1);
	
}

//BAT/////////////////////////////////////////////////////////////////////////////////////////////////////
Bat::Bat()
{
	locationX = MAP_OFFSET_X + 1;
	locationY = MAP_OFFSET_Y + 100;
	length = 100;
	
}

void Bat::init()
{
	GrapheAPI::getInstance()->drawFilledRect(locationX, locationY, 4, length);
	//GrapheAPI::getInstance()->drawRect(60, 60, 200, 200);
}

void Bat::draw(int x, int y)
{
}

void Bat::move(int key, int offset)
{
	//position.x += x;
	//position.y += y;

	switch (key)
	{
	case 0:

		if (locationY == (MAP_OFFSET_Y + 1)) return;

		GrapheAPI::getInstance()->drawDot(locationX, --locationY);
		GrapheAPI::getInstance()->drawDot(locationX + 1, locationY);
		GrapheAPI::getInstance()->drawDot(locationX + 2, locationY);
		GrapheAPI::getInstance()->drawDot(locationX + 3, locationY);

		GrapheAPI::getInstance()->cleanDot(locationX, locationY + length + 1 );
		GrapheAPI::getInstance()->cleanDot(locationX + 1, locationY +length + 1 );
		GrapheAPI::getInstance()->cleanDot(locationX + 2, locationY + length + 1);
		GrapheAPI::getInstance()->cleanDot(locationX + 3, locationY + length + 1);
		break;

	case 1:

		if (locationY + length == (MAP_OFFSET_Y + MAP_HEIGHT - 1)) return;

		GrapheAPI::getInstance()->cleanDot(locationX, locationY );
		GrapheAPI::getInstance()->cleanDot(locationX + 1, locationY);
		GrapheAPI::getInstance()->cleanDot(locationX + 2, locationY);
		GrapheAPI::getInstance()->cleanDot(locationX + 3, locationY);

		GrapheAPI::getInstance()->drawDot(locationX, ++locationY + length);
		GrapheAPI::getInstance()->drawDot(locationX + 1, locationY + length);
		GrapheAPI::getInstance()->drawDot(locationX + 2, locationY + length);
		GrapheAPI::getInstance()->drawDot(locationX + 3, locationY + length);
		break;

	}
}



