#include "Shop.h"
#include "Player.h"
#include "Element.h"
#include "Map.h"

/**
 * .Loads the shop texture(s)
 * 
 */
Shop::Shop()
{
	shopTexture = LoadTexture("../assets/shop.png");
	storage = LoadTexture("../assets/storage.png");
}

/**
 * .Unloads the shop texture(s)
 * 
 */
Shop::~Shop()
{
	UnloadTexture(shopTexture);
}

/**
 * .Draws the shop
 * 
 */
void Shop::drawTexture()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();

	if (!isOnCheckout)
	{

		DrawTexture(shopTexture, 0, 0, WHITE);

		Rectangle goOutdoor = { 20, 30, 80, 30 };

		DrawRectangleRec(goOutdoor, BLACK);

		if (CheckCollisionRecs(player.fullPosition, goOutdoor) && IsKeyPressed(KEY_F))
		{
			map.isInShop = false;
			map.isOutdoor = true;

			player.setPosition({ 60, 560 });
		}

		Rectangle onCheckout = { 520, 200, 80, 30 };


		if (CheckCollisionRecs(player.fullPosition, onCheckout) && IsKeyPressed(KEY_F))
		{
			isOnCheckout = true;
			player.setIsOnMap(false);
		}

		for (int i = 0; i < 4; i++)
		{
			player.checkCollision(walls[i]);
		}
	}
	else
	{
		DrawTexture(storage, 0, 0, WHITE);

		if (DrawButtonText({ 30, 30 }, 150, 44, 50, "BACK"))
		{
			isOnCheckout = false;
			player.setIsOnMap(true);
		}

		inventory.DrawOutzoomed();
		inventory.manageInvetory();

		int xDraw = 10;
		int yDraw = 10;
		int element = 0;

		for (auto i = 0; i < 2; i++)
		{
			for (auto j = 0; j < 8; j++)
			{		
				if (elements[element].getPrice() != 0)
				{
					DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, RAYWHITE);
					xDraw += 75;

					if (element < 22)
					{
						if (elements[element].getIsUnlocked() == false)
						{
							DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 70,190,70,250 });
							if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
							{
								if (inventory.getBalance() >= elements[element].getPrice())
								{
									inventory.addItem(elements[element]);
									inventory.setBalance(inventory.getBalance() - elements[element].getPrice());
									elements[element].setIsUnlocked(true);
								}
							}
						}
						else
						{
							DrawRectangle((float)GetScreenWidth() / 3 - (-xDraw + 75), (float)GetScreenHeight() / 3 - (-yDraw), 50, 50, { 30,30,30,150 });
						}

						DrawText(elements[element].getName().c_str(), (float)GetScreenWidth() / 3 - (-xDraw + 60.5), (float)GetScreenHeight() / 3 - (-yDraw - 5), 20, RED);
						DrawText(TextFormat("%i", elements[element].getPrice()), (float)GetScreenWidth() / 3 - (-xDraw + 60.5), (float)GetScreenHeight() / 3 - (-yDraw - 30), 20, RED);

						element++;
					}
				}
				else
				{
					element++;
					j--;
				}
			}
			yDraw += 100;
			xDraw = 10;
		}
	}
	map.OpenMapMenu();
}