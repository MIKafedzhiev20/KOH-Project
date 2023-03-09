#pragma once
#include <raylib.h>

class Player
{
public:
	Player();

	void move();

	bool isOnMap = true;
private:

	Vector2 position = { 0,0 };

	float speed = 1.0f;
};
