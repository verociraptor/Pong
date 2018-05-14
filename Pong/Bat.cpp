
#include "stdafx.h";
#include "bat.h";


//constructor of the bat object, called whenever bat object created
Bat::Bat(float startX, float startY) 
{
	position.x = startX;
	position.y = startY;

	batShape.setSize(sf::Vector2f(50, 5));
	batShape.setPosition(position);
	
}

//initialized with the 4 corners of the rectangle shape
FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::moveLeft()
{
	position.x -= batSpeed;
}

void Bat::moveRight()
{
	position.x += batSpeed;
}

//will be called one per frame of game
void Bat::update()
{
	batShape.setPosition(position);
}

void Bat::setPosition(float newLoc)
{
	position.x = newLoc;
}
