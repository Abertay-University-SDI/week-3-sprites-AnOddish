#pragma once
#include "Framework/GameObject.h"
#include <SFML/Graphics.hpp>
class Enemy : public GameObject
{
private:
	sf::RenderWindow* window;

	sf::Vector2f speed;

public:
	Enemy();
	~Enemy();

	void update(float dt) override;
	void setWindow(sf::RenderWindow* hwnd);
};
