// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bat.h";
#include "ball.h";
#include <sstream>;
#include <cstdlib>;

#include <SFML/Graphics.hpp>;

using namespace sf; //avoid having to put sf infront of all sfml classes/functions

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;

	//create a bat
	Bat bat(windowWidth / 2, windowHeight - 20);

	//create a ball
	Ball ball(windowWidth / 2, 1);

	//create a "Text" object called "message"
	Text hud;

	//choosing a font now
	Font font;

	//get dat font 
	font.loadFromFile("ka1.ttf");

	//now dat font be our message
	hud.setFont(font);

	//make that mssg hella big
	hud.setCharacterSize(75);

	//choose a color
	hud.setFillColor(sf::Color::White);
	

	while (window.isOpen())
	{
		/******* handle player input***********/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				//someone closed da window, byee
				window.close();
		}

		//checks to see if keyboard is being pressed and which action from keyboard it is
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			//move left...
			bat.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			//move right..
			bat.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			//quit da game, byee
			window.close();
		}

		/******updating the frammee*******/

		//handle ball hitting the bottom
		if (ball.getPosition().top > windowHeight)
		{
			//reverse ball direction
			ball.hitBottom();

			//remove a life
			lives--;

			//check for zero lives
			if (lives < 1)
			{
				//reset score
				score = 0;
				//reset lives
				lives = 3;
			}
		}

		//handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			
		}

		//handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		//has ball hit bat?
		if (ball.getPosition().intersects(bat.getPosition()))
		{
			//hit detected so reverse ball and score a point
			ball.reboundBatOrTop();
			//add point to players score
			score++;
		}

		//handle if bat hits side of window
		if (bat.getPosition().left < 0)
		{
			bat.setPosition(windowWidth - 50);
		}
		if (bat.getPosition().left + 10 > windowWidth)
		{
			bat.setPosition(1);
		}

		/******displaying message**********/
		ball.update();
		bat.update();

		//update text
		std::stringstream ss;
		ss << "Score:" << score << "    Lives:" << lives;
		hud.setString(ss.str());

		/*************Draw the frame**************/

		//clear everything from last frame
		window.clear(Color::Black);

		window.draw(bat.getShape());

		window.draw(ball.getShape());

		//draw our score
		window.draw(hud);

		//show everything we just drew
		window.display();
	}//end of while loop
    return 0;
}

