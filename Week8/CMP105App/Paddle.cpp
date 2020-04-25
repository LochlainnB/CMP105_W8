#include "Paddle.h"

Paddle::Paddle() {
	setSize(sf::Vector2f(20, 100));
	setFillColor(sf::Color(255, 0, 0, 255));
}

Paddle::~Paddle() {

}

void Paddle::update(float dt) {
	setPosition(getPosition() + getVelocity() * dt);
}

void Paddle::handleInput(float dt) {
	setVelocity(0, 0);
	if (input->isKeyDown(controls[0])) {
		setVelocity(0, -100);
	}
	else if (input->isKeyDown(controls[1])) {
		setVelocity(0, 100);
	}
}

void Paddle::setControls(int controls[2]) {
	this->controls[0] = controls[0];
	this->controls[1] = controls[1];
}