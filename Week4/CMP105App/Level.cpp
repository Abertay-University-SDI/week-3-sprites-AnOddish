#include "Level.h"
#include <iostream>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	window->setMouseCursorVisible(false);


	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	enemy1Texture.loadFromFile("gfx/person.png");
	enemy2Texture.loadFromFile("gfx/luigi.jpg");

	backgroundTexture.loadFromFile("gfx/Level1_1.png");
	cursorTexture.loadFromFile("gfx/icon.png");

	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(11038, 675));
	background.setPosition(0, 0);

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	player.setInput(input);
	player.setTexture(&texture);
	player.setSize(sf::Vector2f(100, 100));
	player.setPosition(200, 200);

	enemy1.setWindow(hwnd);
	enemy1.setTexture(&enemy1Texture);
	enemy1.setSize(sf::Vector2f(100, 100));
	enemy1.setPosition(400, 400);

	enemy2.setWindow(hwnd);
	enemy2.setTexture(&enemy2Texture);
	enemy2.setSize(sf::Vector2f(310, 376));
	enemy2.setPosition(700, 300);

	cursor.setTexture(&cursorTexture);
	cursor.setSize(sf::Vector2f(100, 100));
	cursor.setPosition(0, 0);
	cursor.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	view = window->getView();
	player.handleInput(dt);
	cursor.handleInput(dt);
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	if (input->isKeyDown(sf::Keyboard::A)) {;
		if (view.getCenter().x > 0) {
			view.move(sf::Vector2f(-12.5, 0));
		}
	}
	if (input->isKeyDown(sf::Keyboard::D)) {
		if (view.getCenter().x < 11038) {
			view.move(sf::Vector2f(12.5, 0));
		}
	}
	window->setView(view);

}

// Update game objects
void Level::update(float dt)
{
	enemy1.update(dt);
	enemy2.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(background);
	window->draw(testSprite);
	window->draw(player);
	window->draw(enemy1);
	window->draw(enemy2);
	window->draw(cursor);

	endDraw();
}
