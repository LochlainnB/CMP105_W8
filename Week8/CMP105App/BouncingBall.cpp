#include "BouncingBall.h"

BouncingBall::BouncingBall() {
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(148, 148));
}

BouncingBall::~BouncingBall() {

}

void BouncingBall::update(float dt) {
	//update position
	sf::Vector2f target = getPosition() + getVelocity() * dt;
	//bounce
	if (target.x < 0) {
		target.x = abs(target.x);
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	else if (target.x + getSize().x > window->getSize().x) {
		target.x = 2 * (window->getSize().x - getSize().x) - target.x;
		setVelocity(getVelocity().x * -1, getVelocity().y);
	}
	if (target.y < 0) {
		target.y = abs(target.y);
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}
	else if (target.y + getSize().y > window->getSize().y) {
		target.y = 2 * (window->getSize().y - getSize().y) - target.y;
		setVelocity(getVelocity().x, getVelocity().y * -1);
	}
	setPosition(target);
}

void BouncingBall::collisionResponse(GameObject* other) {
	//change position from collision to contact. Assumes other object does likewise
	float desiredDistance = (getSize().x + other->getSize().x)/2;
	sf::Vector2f displacement = sf::Vector2f((other->getPosition().x + other->getSize().x / 2) - (getPosition().x + getSize().x / 2), (other->getPosition().y + other->getSize().y / 2) - (getPosition().y + getSize().y / 2));
	setPosition(getPosition() + Vector::normalise(displacement) * 0.5f * (Vector::magnitude(displacement) - desiredDistance));
	setVelocity(Vector::normalise(displacement) * -1.0f * Vector::magnitude(getVelocity()));
}

void BouncingBall::setWindow(sf::RenderWindow* window) {
	this->window = window;
}