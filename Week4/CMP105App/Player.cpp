#include "Player.h"
#include <iostream>

Player::Player() {

}

Player::~Player() {

}

void Player::handleInput(float dt) {
	//movement guff
	if (input->isPressed(sf::Keyboard::Up)) {
		this->move(sf::Vector2f(0, -200 * dt));
	}
	if (input->isPressed(sf::Keyboard::Down)) {
		this->move(sf::Vector2f(0, 200 * dt));
	}
	if (input->isPressed(sf::Keyboard::Left)) {
		this->move(sf::Vector2f(-200 * dt, 0));
	}
	if (input->isPressed(sf::Keyboard::Right)) {
		this->move(sf::Vector2f(200 * dt, 0));
	}
}