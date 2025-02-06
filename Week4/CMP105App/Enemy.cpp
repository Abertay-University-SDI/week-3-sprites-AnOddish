
#include "Enemy.h"

Enemy::Enemy() {
	window = nullptr;
	speed = sf::Vector2f(400, 400);
}

Enemy::~Enemy() {

}

void Enemy::update(float dt) {
	if (this->getPosition().x >= window->getSize().x || this->getPosition().x <= 0) {
		speed.x = speed.x * -1.0f;
	}
	if (this->getPosition().y >= window->getSize().y || this->getPosition().y <= 0) {
		speed.y = speed.y * -1.0f;
	}
	this->move(speed * dt);
}

void Enemy::setWindow(sf::RenderWindow* hwnd) {
	window = hwnd;
}