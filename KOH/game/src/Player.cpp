#include "Player.h"

Player::Player()
{

}

Player& Player::getInstance()
{
	static Player player;
	return player;
}

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

void Player::drawPlayer()
{
	DrawRectangle(position.x, position.y, 20, 20, RED);
}
