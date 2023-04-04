#include "Player.h"

#include <iostream>
/**
 * .Create instance of Player
 *
 */
Player::Player()
{
	backAnim = LoadTexture("../assets/playerTextures/back.png");
	frontAnim = LoadTexture("../assets/playerTextures/front.png");
	backWalk = LoadTexture("../assets/playerTextures/moveDown.png");
	frontWalk = LoadTexture("../assets/playerTextures/moveUp.png");
	sideAnim = LoadTexture("../assets/playerTextures/side.png");
	sideWalk = LoadTexture("../assets/playerTextures/moveSide.png");
}

Player::~Player()
{
	UnloadTexture(backAnim);
	UnloadTexture(frontAnim);
	UnloadTexture(backWalk);
	UnloadTexture(frontWalk);
	UnloadTexture(sideAnim);
	UnloadTexture(sideWalk);
}

/**
 * .Create static instance of Player
 *
 * \return static instance of Player
 */
Player& Player::getInstance()
{
	static Player player;
	return player;
}

/**
 * .Set if the player is on the map
 *
 * \param isOnMap true/false if the player is on the map
 */
void Player::setIsOnMap(bool isOnMap)
{
	this->isOnMap = isOnMap;
}

/**
 * .Returns if the player is on the map
 *
 * \return true/false if the player is on the map
 */
bool Player::getIsOnMap()
{
	return this->isOnMap;
}

/**
 * .Set the player's position to a new one
 *
 * \param position the new position
 */
void Player::setPosition(Vector2 position)
{
	this->position = position;
}

/**
 * .Returns the player's position
 *
 * \return the player's position
 */
Vector2 Player::getPosition()
{
	return this->position;
}

/**
 * .Set the camera position to a new one
 *
 * \param cameraPos the new camera's position
 */
void Player::setCameraPos(Vector2 cameraPos)
{
	this->cameraPos = cameraPos;
}

/**
 * .Return the camera position
 *
 * \return the camera position
 */
Vector2 Player::getCameraPos()
{
	return this->cameraPos;
}

/**
 * .Move the player base on user input
 *
 */
void Player::move()
{
	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		speed = 2.7f;
	}
	else
	{
		speed = 2.0f;
	}

	if (isOnMap == true)
	{
		if (true)
		{
			isWalking = false;
		}
		if (IsKeyDown(KEY_W))
		{
			position.y -= speed;
			direction = 2;
			isWalking = true;
		}
		if (IsKeyDown(KEY_S))
		{
			position.y += speed;
			direction = 3;
			isWalking = true;
		}
		if (IsKeyDown(KEY_A))
		{
			position.x -= speed;
			direction = 0;
			isWalking = true;
		}
		if (IsKeyDown(KEY_D))
		{
			position.x += speed;
			direction = 1;
			isWalking = true;
		}
	}
}

/**
 * .Draws the player
 *
 */
void Player::drawPlayer()
{
	if (direction == 0)
	{
		if (isWalking == true)
		{
			DrawWalking(sideWalk);
		}
		else
		{
			DrawIdle(sideAnim);
		}
	}
	if (direction == 1)
	{
		if (isWalking == true)
		{
			DrawWalking(sideWalk);
		}
		else
		{
			DrawIdle(sideAnim);
		}
	}
	if (direction == 3)
	{
		if (isWalking == true)
		{
			DrawWalking(backWalk);
		}
		else
		{
			DrawIdle(frontAnim);
		}
	}
	if (direction == 2)
	{
		if (isWalking == true)
		{
			DrawWalking(frontWalk);
		}
		else
		{
			DrawIdle(backAnim);
		}
	}

	//DrawRectangle(position.x+20, position.y+40, 20, 20, RED);
}

void Player::DrawIdle(Texture2D Nsheet)
{
	if (direction == 0)
	{
		Nsheet.width *= -1;
	}

	static Rectangle frameRec = { 0.0f, 0.0f, (float)Nsheet.width / 2.1f, (float)Nsheet.height };
	static int currentFrame = 0;
	static int framesCounter = 0;

	framesCounter++;

	if (framesCounter >= (60 / 1))
	{
		framesCounter = 0;
		currentFrame++;

		if (currentFrame > 1)
		{
			currentFrame = 0;
		}

		frameRec.x = (float)currentFrame * (float)Nsheet.width / 2.1;
	}

	DrawTextureRec(Nsheet, frameRec, position, WHITE);
}

void Player::DrawWalking(Texture2D Nsheet)
{
	if (direction == 1)
	{
		Nsheet.width *= -1;
	}

	static Rectangle frameRec = { 0.0f, 0.0f, (float)Nsheet.width / 9.1f, (float)Nsheet.height };
	static int currentFrame = 0;
	static int framesCounter = 0;

	framesCounter++;

	if (framesCounter >= (60 / 8))
	{
		framesCounter = 0;
		currentFrame++;

		if (currentFrame > 8)
		{
			currentFrame = 0;
		}

		frameRec.x = (float)currentFrame * (float)Nsheet.width / 9.1;
	}

	DrawTextureRec(Nsheet, frameRec, position, WHITE);
}
