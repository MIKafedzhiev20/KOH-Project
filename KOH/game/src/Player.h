#pragma once
#include <raylib.h>

class Player
{
public:
	Player();

	Player(Player const&) = delete;
	void operator=(Player const&) = delete;

	static Player& getInstance();

	void move();
	void drawPlayer();

	bool isOnMap = false;

	Vector2 position = { 0,0 };

private:

	float speed = 1.0f;
};
