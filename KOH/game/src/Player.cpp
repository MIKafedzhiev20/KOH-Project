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
