#pragma once
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball : public GameObject {
public:
	Ball();
	~Ball();

	void update(float dt);
	void collisionResponse(GameObject* other);
	void setWindow(sf::RenderWindow* window);
	void setInitialPosition(sf::Vector2f pos);
	void setInitialPosition(float posX, float posY);
protected:
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::Vector2f initialPosition;
};