#pragma once
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class BouncingBall : public GameObject {
public:
	BouncingBall();
	~BouncingBall();

	void update(float dt);
	void collisionResponse(GameObject* other);
	void setWindow(sf::RenderWindow* window);
protected:
	sf::Texture texture;
	sf::RenderWindow* window;
};