#include "Cursor.h"

Cursor::Cursor() {

}

Cursor::~Cursor() {

}

void Cursor::handleInput(float dt) {
	int x = input->getMouseX();
	int y = input->getMouseY();
	this->setPosition(x, y);
}