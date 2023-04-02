#include "House.h"
#include "Player.h"
#include "Map.h"

House::House()
{
	houseTexture = LoadTexture("assets/DevHouse.png");
}

House::~House()
{
	UnloadTexture(houseTexture);
}

void House::drawHouse()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	if (isOnLaptop == false)
	{
		DrawTexture(houseTexture, 0, 0, WHITE);

		Rectangle goOutdoor = { 200, 350, 30, 30 };

		DrawRectangleRec(goOutdoor, BLUE);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, goOutdoor) && IsKeyPressed(KEY_F))
		{
			map.isInHouse = false;
			map.isOutdoor = true;
		}

		Rectangle onLaptop = { 200, 150, 30, 30 };

		DrawRectangleRec(onLaptop, YELLOW);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, onLaptop) && IsKeyPressed(KEY_F))
		{
			isOnLaptop = true;
			player.isOnMap = false;
		}
		map.OpenMapMenu();
	}
	else
	{
		if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
		{
			isOnLaptop = false;
			player.isOnMap = true;
		}
	}
}
