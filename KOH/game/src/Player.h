#pragma once
#include <raylib.h>
#include <vector>

enum direction {
	SIDE = 0,
	FRONT,
	BACK
};

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

	void checkCollision(Rectangle collision);

	// Setters and getters
	void setIsOnMap(bool isOnMap);
	bool getIsOnMap();

	void setPosition(Vector2 position);
	Vector2 getPosition();

	void setCameraPos(Vector2 cameraPos);
	Vector2 getCameraPos();

	float getSpeed();

	Rectangle fullPosition = { position.x + 5, position.y + 30, 40, 50 };
private:
	// Constructor / Destructor
	Player();
	~Player();

	// Private functions
	void DrawIdle(Texture2D Nsheet);
	void DrawWalking(Texture2D Nsheet);

	bool isOnMap = false;

	Vector2 position = { 200, 200 };

	Vector2 cameraPos = { 0, 0 };

	Texture2D backAnim;
	Texture2D backWalk;

	Texture2D frontAnim;
	Texture2D frontWalk;

	Texture2D leftAnim;
	Texture2D leftWalk;

	Texture2D rightAnim;
	Texture2D rightWalk;

	float speed = 3.0f;

	int direction = 3;
	bool isWalking = false;
};