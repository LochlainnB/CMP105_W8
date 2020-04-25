#include "Ball.h"

Ball::Ball() {
	texture.loadFromFile("gfx/Beach_Ball.png");
	setTexture(&texture);
	setSize(sf::Vector2f(148, 148));
}

Ball::~Ball() {

}

void Ball::update(float dt) {
	//update position
	sf::Vector2f target = getPosition() + getVelocity() * dt;
	//bounce
	if (target.x < 0) {
		target = initialPosition;
	}
	else if (target.x + getSize().x > window->getSize().x) {
		target = initialPosition;
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

void Ball::collisionResponse(GameObject* other) {
	//find closest point
	sf::Vector2f closest;
	closest = getPosition() + getSize() / 2.0f;

	if (other->getPosition().x + other->getSize().x < closest.x) {
		closest.x = other->getPosition().x + other->getSize().x;
	}
	else if (other->getPosition().x > closest.x) {
		closest.x = other->getPosition().x;
	}
	if (other->getPosition().y + other->getSize().y < closest.y) {
		closest.y = other->getPosition().y + other->getSize().y;
	}
	else if (other->getPosition().y > closest.y) {
		closest.y = other->getPosition().y;
	}
	//change position from collision to contact.
	float desiredDistance = getSize().x / 2;
	sf::Vector2f displacement = sf::Vector2f(closest.x - (getPosition().x + getSize().x / 2), closest.y - (getPosition().y + getSize().y / 2));
	setPosition(getPosition() + Vector::normalise(displacement) * 0.5f * (Vector::magnitude(displacement) - desiredDistance));
	//bounce
	setVelocity(-1.0f * getVelocity());
}

void Ball::setWindow(sf::RenderWindow* window) {
	this->window = window;
}

void Ball::setInitialPosition(sf::Vector2f pos) {
	initialPosition = pos;
	setPosition(initialPosition);
}

void Ball::setInitialPosition(float posX, float posY) {
	initialPosition = sf::Vector2f(posX, posY);
	setPosition(initialPosition);
}