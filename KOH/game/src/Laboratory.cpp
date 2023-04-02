#include "Laboratory.h"
#include "Map.h"
#include "Player.h"
#include "Inventory.h"

Laboratory::Laboratory()
{
	laboratoryTexture = LoadTexture("../assets/DevLab.png");
}

Laboratory::~Laboratory()
{
	UnloadTexture(laboratoryTexture);
}

void Laboratory::DrawLaboratory()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();

	if (!isOnTable && !isInStorage)
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

		Rectangle inStorage = { 300, 150, 30, 30 };

		DrawRectangleRec(inStorage, PURPLE);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, inStorage) && IsKeyPressed(KEY_F))
		{
			player.isOnMap = false;
			isInStorage = true;
		}

		map.OpenMapMenu();
	}

	if (isOnTable)
	{
		if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
		{
			isOnTable = false;
			player.isOnMap = true;
		}
	}

	if (isInStorage)
	{
		if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
		{
			isInStorage = false;
			player.isOnMap = true;
		}

		inventory.DrawInStorage();
		inventory.manageInvetory();

		DrawRectangle((float)GetScreenWidth() / 3, (float)GetScreenHeight() / 3, 600, 470, Color{ 103,102,90,100 });

		int xDraw = 10;
		int yDraw = 10;
		int element = 0;

		for (auto i = 0; i < 5; i++)
		{
			for (auto j = 0; j < 8; j++)
			{
				DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, RAYWHITE);
				xDraw += 75;

				if (element < 21)
				{
					if (elements[element].getIsUnlocked())
					{
						DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 30,30,30,150 });
					}
					else
					{
						DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 70,190,70,250 });

						if(CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
						{
							inventory.addItem(elements[element]);
						}
					}

					DrawText(elements[element].getName().c_str(), (float)GetScreenWidth() / 3 -  (-xDraw + 60.5), (float)GetScreenHeight() / 3 - (-yDraw - 15), 20, RED);

					element++;
				}
			}
			yDraw += 100;
			xDraw = 10;
		}
	}
}
