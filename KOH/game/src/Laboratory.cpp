#include "Laboratory.h"
#include "Map.h"
#include "Player.h"
#include "Inventory.h"
#include "Reactions.h"

#include <iostream>
/**
 * .Load the laboratory texture(s)
 *
 */
Laboratory::Laboratory()
{
	laboratoryTexture = LoadTexture("../assets/lab.png");
	table = LoadTexture("../assets/table.png");
	storage = LoadTexture("../assets/storage.png");
}

/**
 * .Unload the laboratory texture(s)
 *
 */
Laboratory::~Laboratory()
{
	UnloadTexture(laboratoryTexture);
	UnloadTexture(table);
	UnloadTexture(storage);
}

/**
 * .Draws the laboratory
 *
 */
void Laboratory::DrawLaboratory()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	if (!isOnTable && !isInStorage)
	{
		DrawTexture(laboratoryTexture, 0, 0, WHITE);

		Rectangle goOutdoor = { 360, 310, 80, 20 };

		DrawRectangleRec(goOutdoor, BLACK);

		if (CheckCollisionRecs(player.fullPosition, goOutdoor) && IsKeyPressed(KEY_F))
		{
			map.isInLab = false;
			map.isOutdoor = true;

			player.setPosition({360, 380});
		}

		Rectangle onTable = { 20, 40, 220, 50 };

		if (CheckCollisionRecs(player.fullPosition, onTable) && IsKeyPressed(KEY_F))
		{
			player.setIsOnMap(false);
			isOnTable = true;
		}

		Rectangle inStorage = { 330, 50, 50, 50 };

		if (CheckCollisionRecs(player.fullPosition, inStorage) && IsKeyPressed(KEY_F))
		{
			player.setIsOnMap(false);
			isInStorage = true;
		}

		for (int i = 0; i < 4; i++)
		{
			player.checkCollision(walls[i]);
		}

		map.OpenMapMenu();
	}

	if (isOnTable)
	{
		DrawTable();
	}

	if (isInStorage)
	{
		DrawStorage();
	}

	Rectangle onExtraxtor = { 400, 50, 60, 60 };
	if (CheckCollisionRecs(player.fullPosition, onExtraxtor))
	{
		DrawExtractor();
	}
}

/**
 * .Draws the table
 *
 */
void Laboratory::DrawTable()
{
	Inventory& inventory = Inventory::getInstance();
	Player& player = Player::getInstance();

	static std::vector<Item> slots = { Item("",3),Item("",3) };
	static unsigned index = 0;

	DrawTexture(table, 0, 0, WHITE);

	if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
	{
		isOnTable = false;
		player.setIsOnMap(true);
	}

	inventory.manageInvetory();
	inventory.DrawOutzoomed();

	if (IsKeyPressed(KEY_Q) && inventory.getItems()[inventory.getSelectedSlot()].getType() == 0)
	{
		slots[index] = inventory.getItems()[inventory.getSelectedSlot()];
		inventory.removeItem();
		index++;
	}

	int taskIndex = 0;
	for (int i = 0; i < 17; i++)
	{
		if (reactions[i].getIsObtained() == true)
		{
			taskIndex++;
		}
	}

	if (taskIndex < 17)
	{
		DrawText(("Current task. Obtain: " + reactions[taskIndex].getName()).c_str(), 600, 100, 50, RED);
	}
	else
	{
		DrawText("COMPLETED!", 740, 100, 50, RED);
	}

	if (DrawButtonText({ 1650, 100 }, 240, 30, 50, "COMBINE"))
	{
		for (int i = 0; i < 17; i++)
		{
			if ((slots[0].getName() == reactions[i].getRequired1() || slots[0].getName() == reactions[i].getRequired2())
			 && (slots[1].getName() == reactions[i].getRequired2() || slots[1].getName() == reactions[i].getRequired1()))
			{
				if (reactions[i].getIsObtained() == false && taskIndex == i)
				{
					inventory.setBalance(inventory.getBalance() + reactions[i].getPrice());
				}
				reactions[i].setIsObtained(true);

				slots[0] = Item("", 3);
				slots[1] = Item("", 3);
				index = 0;
			}
		}
	}

	if (DrawButtonText({ 1650, 150 }, 240, 36, 50, "RESET"))
	{
		slots[0] = Item("", 3);
		slots[1] = Item("", 3);
		index = 0;
	}
}

/**
 * .Draws the storage UI
 *
 */
void Laboratory::DrawStorage()
{
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();
	
	DrawTexture(storage, 0, 0, WHITE);

	if (DrawButtonText({ 30, 30 }, 150, 44, 50, "BACK"))
	{
		isInStorage = false;
		player.setIsOnMap(true);
	}

	inventory.DrawOutzoomed();
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

			if (element < 22)
			{
				if (elements[element].getIsUnlocked() == false)
				{
					DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 30,30,30,150 });
				}
				else
				{
					DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 70,190,70,250 });

					if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
					{
						inventory.addItem(elements[element]);
					}
				}

				DrawTexture(elements[element].getTexture(), (float)GetScreenWidth() / 3 - (-xDraw + 60.5), (float)GetScreenHeight() / 3 - (-yDraw - 15), WHITE);

				element++;
			}
		}
		yDraw += 100;
		xDraw = 10;
	}
}

/**
 * .Draws the extractor UI
 *
 */
void Laboratory::DrawExtractor()
{
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();

	std::vector<Item> items = inventory.getItems();
	unsigned selectedSlot = inventory.getSelectedSlot();

	if (IsKeyPressed(KEY_F))
	{
		if (items[selectedSlot].getType() == 1)
		{
			if (items[selectedSlot].getName() == "AluminumCan")
			{
				inventory.addItem(elements[18]);
				elements[18].setIsUnlocked(true);
			}
			else if (items[selectedSlot].getName() == "ZinkWire")
			{
				inventory.addItem(elements[19]);
				elements[19].setIsUnlocked(true);
			}
			else if (items[selectedSlot].getName() == "IronSpring")
			{
				inventory.addItem(elements[20]);
				elements[20].setIsUnlocked(true);
			}
			else if (items[selectedSlot].getName() == "dirtyWater")
			{
				inventory.addItem(elements[21]);
				elements[21].setIsUnlocked(true);
			}
		}
	}
}
