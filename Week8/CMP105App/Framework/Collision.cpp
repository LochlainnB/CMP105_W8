#include "Collision.h"
#include <iostream>

// Check AABB for collision. Returns true if collision occurs.
bool Collision::checkBoundingBox(GameObject* s1, GameObject* s2)
{
	if (s1->getCollisionBox().left + s1->getCollisionBox().width < s2->getCollisionBox().left)
		return false;
	if (s1->getCollisionBox().left > s2->getCollisionBox().left + s2->getCollisionBox().width)
		return false;
	if (s1->getCollisionBox().top + s1->getCollisionBox().height < s2->getCollisionBox().top)
		return false;
	if (s1->getCollisionBox().top > s2->getCollisionBox().top + s2->getCollisionBox().height)
		return false;

	return true;
}

// Check for bounding box collision with a point/vector2 rather than two boxes.
bool Collision::checkBoundingBox(GameObject* s1, sf::Vector2i s2)
{
	if (s1->getCollisionBox().left + s1->getCollisionBox().width < s2.x)
		return false;
	if (s1->getCollisionBox().left > s2.x)
		return false;
	if (s1->getCollisionBox().top + s1->getCollisionBox().height < s2.y)
		return false;
	if (s1->getCollisionBox().top > s2.y)
		return false;

	return true;
}

// Check AABB v Circle collision. Returns true if collision occurs.
bool Collision::checkCircleBox(GameObject* box, GameObject* circle) {
	sf::Vector2f closest;
	closest = circle->getPosition() + circle->getSize() / 2.0f;

	if (box->getPosition().x + box->getSize().x < closest.x) {
		closest.x = box->getPosition().x + box->getSize().x;
	}
	else if (box->getPosition().x > closest.x) {
		closest.x = box->getPosition().x;
	}
	if (box->getPosition().y + box->getSize().y < closest.y) {
		closest.y = box->getPosition().y + box->getSize().y;
	}
	else if (box->getPosition().y > closest.y) {
		closest.y = box->getPosition().y;
	}
	
	std::cout << pow(circle->getPosition().x - closest.x, 2) + pow(circle->getPosition().y - closest.y, 2) << ", " << pow(circle->getSize().x / 2, 2) << std::endl;
	return pow(circle->getPosition().x + circle->getSize().x / 2 - closest.x, 2) + pow(circle->getPosition().y + circle->getSize().y / 2 - closest.y, 2) < pow(circle->getSize().x / 2, 2);
}

// Check bounding circle collision. Returns true if collision occurs.
bool Collision::checkBoundingCircle(GameObject* s1, GameObject* s2)
{
	// Get radius and centre of sprites.
	float radius1 = s1->getSize().x / 2;
	float radius2 = s2->getSize().x / 2;
	float xpos1 = s1->getPosition().x + radius1;
	float xpos2 = s2->getPosition().x + radius2;
	float ypos1 = s1->getPosition().y + radius1;
	float ypos2 = s2->getPosition().y + radius2;

	if (pow(xpos2 - xpos1, 2) + pow(ypos2 - ypos1, 2) < pow(radius1 + radius2, 2))
	{
		return true;
	}
	return false;
}

