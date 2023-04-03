#include "Player.h"

/**
 * .Create instance of Player
 * 
 */
Player::Player()
{

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
	if (isOnMap == true)
	{
		if (IsKeyDown(KEY_W))
		{
			position.y -= speed;
		}
		if (IsKeyDown(KEY_S))
		{
			position.y += speed;
		}
		if (IsKeyDown(KEY_A))
		{
			position.x -= speed;
		}
		if (IsKeyDown(KEY_D))
		{
			position.x += speed;
		}
	}
}

/**
 * .Draws the player
 * 
 */
void Player::drawPlayer()
{
	DrawRectangle(position.x, position.y, 20, 20, RED);
}

