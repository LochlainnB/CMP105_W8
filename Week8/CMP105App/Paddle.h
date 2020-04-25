#pragma once
#include "Framework/Collision.h"
#include "Framework/GameObject.h"

class Paddle : public GameObject {
public:
	Paddle();
	~Paddle();

	void update(float dt);
	void handleInput(float dt) override;
	void setControls(int controls[2]);
protected:
	int controls[2];
};