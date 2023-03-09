#include "Player.h"

Player::Player()
{

}

void Player::move()
{
	if (isOnMap == true)
	{
		if (IsKeyDown(KEY_W))
		{
			position.y -= 2.0f;
		}
		if (IsKeyDown(KEY_S))
		{
			position.y += 2.0f;
		}
		if (IsKeyDown(KEY_A))
		{
			position.x -= 2.0f;
		}
		if (IsKeyDown(KEY_D))
		{
			position.x += 2.0f;
		}

		DrawRectangle(position.x, position.y, 20, 20, RED);
	}

}
