#pragma once
#include <SFML/Graphics.hpp>;

using namespace sf;

class Ball
{
private:
	Vector2f position;	//just a point in 2d

	//creates ball shape
	RectangleShape ballShape;

	float xVelocity = .2f;
	float yVelocity = .2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void hitBottom();

	void update();
};
