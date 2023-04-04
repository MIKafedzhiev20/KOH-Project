#include "House.h"
#include "Player.h"
#include "Map.h"

/**
 * .Load the house texture(s)
 * 
 */
House::House()
{
	houseTexture = LoadTexture("../assets/house.png");
}

/**
 * .Unload the house texture(s)
 * 
 */
House::~House()
{
	UnloadTexture(houseTexture);
}

/**
 * .Draws the house insidies
 * 
 */
void House::drawHouse()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	if (isOnLaptop == false)
	{
		DrawTexture(houseTexture, 0, 0, WHITE);

		Rectangle goOutdoor = { 200, 350, 30, 30 };

		DrawRectangleRec(goOutdoor, BLUE);

		if (CheckCollisionRecs(player.fullPosition, goOutdoor) && IsKeyPressed(KEY_F))
		{
			map.isInHouse = false;
			map.isOutdoor = true;
		}

		Rectangle onLaptop = { 200, 150, 30, 30 };

		DrawRectangleRec(onLaptop, YELLOW);

		if (CheckCollisionRecs(player.fullPosition, onLaptop) && IsKeyPressed(KEY_F))
		{
			isOnLaptop = true;
			player.setIsOnMap(false);
		}

		for (int i = 0; i < 4; i++)
		{
			DrawRectangleRec(walls[i], WHITE);
			player.checkCollision(walls[i]);
		}

		map.OpenMapMenu();
	}
	else
	{
		if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
		{
			isOnLaptop = false;
			player.setIsOnMap(true);
		}
	}
}
