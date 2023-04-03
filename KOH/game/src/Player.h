#pragma once
#include <raylib.h>
#include <vector>

class Player
{
public:
	// Operators
	Player(Player const&) = delete;
	void operator=(Player const&) = delete;

	// Public functions
	static Player& getInstance();
	void move();
	void drawPlayer();

	// Setters and getters
	void setIsOnMap(bool isOnMap);
	bool getIsOnMap();

	void setPosition(Vector2 position);
	Vector2 getPosition();

	void setCameraPos(Vector2 cameraPos);
	Vector2 getCameraPos();

private:
	// Constructor
	Player();

	bool isOnMap = false;

	Vector2 position = { 200, 200 };

	Vector2 cameraPos = { 0, 0 };

	float speed = 3.0f;
};