#include "Level.h"
#include <iostream>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1.setPosition(50, 300);
	ball2.setPosition(650, 350);
	ball1.setVelocity(200, 0);
	ball2.setVelocity(-200, 0);
	ball1.setWindow(window);
	ball2.setWindow(window);

	player1.setPosition(50, 282);
	player2.setPosition(1130, 282);
	player1.setInput(input);
	player2.setInput(input);
	int player1Controls[2];
	int player2Controls[2];
	player1Controls[0] = 22;
	player1Controls[1] = 18;
	player2Controls[0] = 14;
	player2Controls[1] = 11;
	player1.setControls(player1Controls);
	player2.setControls(player2Controls);

	ball.setInitialPosition(526, 263);
	ball.setVelocity(200, -50);
	ball.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player1.handleInput(dt);
	player2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	ball.update(dt);
	player1.update(dt);
	player2.update(dt);

	if (Collision::checkBoundingCircle(&ball1, &ball2)) {
		ball1.collisionResponse(&ball2);
		ball2.collisionResponse(&ball1);
	}
	if (Collision::checkCircleBox(&player1, &ball)) {
		ball.collisionResponse(&player1);
		std::cout << "collided1" << std::endl;
	}
	else if (Collision::checkCircleBox(&player2, &ball)) {
		ball.collisionResponse(&player2);
		std::cout << "collided2" << std::endl;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(ball1);
	//window->draw(ball2);
	window->draw(player1);
	window->draw(player2);
	window->draw(ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}