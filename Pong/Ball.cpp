#include "stdafx.h";
#include "ball.h";

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(10, 10));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update() //updates position of the ball
{
	position.y += yVelocity;
	position.x += xVelocity;

	ballShape.setPosition(position);
}