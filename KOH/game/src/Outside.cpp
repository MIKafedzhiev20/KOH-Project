#include "Outside.h"
#include "Map.h"
#include "Player.h"

Outside::Outside()
{
	outsideTexture = LoadTexture("assets/DevOutdoor.png");
}

Outside::~Outside()
{
	UnloadTexture(outsideTexture);
}

void Outside::DrawOutside()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	Rectangle LabWarp = { 100, 100, 30, 30 };
	Rectangle shopWarp = { 400, 400, 30, 30 };
	Rectangle houseWarp = { 200, 300, 30, 30 };

	DrawTexture(outsideTexture, 0, 0, WHITE);

	DrawRectangleRec(LabWarp, BLUE);

	if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, LabWarp) && IsKeyPressed(KEY_F))
	{
		map.isInLab = true;
		map.isOutdoor = false;
	}

	DrawRectangleRec(shopWarp, GREEN);

	if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, shopWarp) && IsKeyPressed(KEY_F))
	{
		map.isOutdoor = false;
		map.isInShop = true;

		player.isOnMap = false;
	}

	DrawRectangleRec(houseWarp, YELLOW);

	if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, houseWarp) && IsKeyPressed(KEY_F))
	{
		map.isOutdoor = false;
		map.isInHouse = true;
	}

	map.OpenMapMenu();
}
