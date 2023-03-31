#pragma once
#include <raylib.h>
#include <vector>

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

	Vector2 position = {200, 200};

	Vector2 cameraPos = {0, 0};

	float speed = 2.0f;
};