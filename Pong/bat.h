#pragma once
#include <SFML/Graphics.hpp>;

using namespace sf;

class Bat 
{
private:
	//defines position of bat, holds vertical and horizontal
	Vector2f position;

	RectangleShape batShape; //bat of user

	float batSpeed = .3f;	//number of pixels per frame that bat can move at

public:
	Bat(float startX, float startY);

	FloatRect getPosition();	//4 points that define a rectangle

	RectangleShape getShape();	//helps batshape to be drawn

	void moveLeft();

	void moveRight();

	void update();

	void setPosition(float newLoc);



};
