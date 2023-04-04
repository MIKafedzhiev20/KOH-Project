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

	DrawTexture(houseTexture, 0, 0, WHITE);

	Rectangle goOutdoor = { 10, 260, 20, 50 };

	DrawRectangleRec(goOutdoor, BLUE);

	if (CheckCollisionRecs(player.fullPosition, goOutdoor) && IsKeyPressed(KEY_F))
	{
		map.isInHouse = false;
		map.isOutdoor = true;

		player.setPosition({ 1200, 200 });
	}


	for (int i = 0; i < 8; i++)
	{
		player.checkCollision(walls[i]);
	}

	map.OpenMapMenu();
}
