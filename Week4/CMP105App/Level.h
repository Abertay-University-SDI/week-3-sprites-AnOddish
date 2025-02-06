#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Cursor.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

private:
	// Level objects
	GameObject testSprite;

	sf::Texture texture;
	sf::Texture enemy1Texture;
	sf::Texture enemy2Texture;

	sf::Texture backgroundTexture;
	sf::Texture cursorTexture;

	sf::View view;

	Player player;
	Enemy enemy1;
	Enemy enemy2;
	Background background;

	Cursor cursor;
};