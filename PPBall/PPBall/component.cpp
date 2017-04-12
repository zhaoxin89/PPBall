#include "component.h"

Ball::Ball()
{
	position.set(50, 50);
	direction.set(1, 0);
	speed = 5;
	radius = 1;
}

void Ball::move()
{
	//position.x += x;
	//position.y += y;
	switch(key)
	{
	case 0:

		break;
	case 1:
		break;

	}
}

void Ball::draw(int x, int y)
{
	int l = radius * 2;
	GrapheAPI::getInstance()->drawRect(x, y, l, l);
	locationX = x;
	locationY = y;
}

Bat::Bat()
{
	locationX = MAP_OFFSET_X;
	locationY = MAP_OFFSET_Y + 30;
	length = 30;
}
void Bat::move(int key)
{
	//position.x += x;
	//position.y += y;
	
	switch (key)
	{
	case 0:
		GrapheAPI::getInstance()->drawDot(locationX, locationY - 1);
		GrapheAPI::getInstance()->drawDot(locationX + 1, locationY - 1);

		GrapheAPI::getInstance()->cleanDot(locationX, locationY + length );
		GrapheAPI::getInstance()->cleanDot(locationX + 1, locationY +length );
		break;

	case 1:

		GrapheAPI::getInstance()->cleanDot(locationX, locationY );
		GrapheAPI::getInstance()->cleanDot(locationX + 1, locationY);

		GrapheAPI::getInstance()->drawDot(locationX, locationY + length + 1);
		GrapheAPI::getInstance()->drawDot(locationX + 1, locationY + length + 1);
		break;

	}
}

void Bat::draw(int x, int y)
{

}


