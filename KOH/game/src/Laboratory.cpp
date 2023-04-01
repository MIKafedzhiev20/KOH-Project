#include "Laboratory.h"
#include "Map.h"
#include "Player.h"

Laboratory::Laboratory()
{
	laboratoryTexture = LoadTexture("assets/DevLab.png");
}

Laboratory::~Laboratory()
{
	UnloadTexture(laboratoryTexture);
}

void Laboratory::DrawLaboratory()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	if (isOnTable == false)
	{
		DrawTexture(laboratoryTexture, 0, 0, WHITE);

		Rectangle goOutdoor = { 100, 150, 30, 30 };

		DrawRectangleRec(goOutdoor, BLUE);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, goOutdoor) && IsKeyPressed(KEY_F))
		{
			map.isInLab = false;
			map.isOutdoor = true;
		}

		Rectangle onTable = { 200, 150, 30, 30 };

		DrawRectangleRec(onTable, YELLOW);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, onTable) && IsKeyPressed(KEY_F))
		{
			player.isOnMap = false;
			isOnTable = true;
		}

		map.OpenMapMenu();
	}
	else
	{
		if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
		{
			isOnTable = false;
			player.isOnMap = true;
		}
	}
}
