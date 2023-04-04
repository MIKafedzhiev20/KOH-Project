#include "Outside.h"
#include "Map.h"
#include "Player.h"
#include "Inventory.h"

/**
 * .Load the map texture(s)
 * 
 */
Outside::Outside()
{
	outsideTexture = LoadTexture("../assets/Map.png");
}

/**
 * .Unload the map texture(s)
 * 
 */
Outside::~Outside()
{
	UnloadTexture(outsideTexture);
}

/**
 * .Draws the map
 * 
 */
void Outside::DrawOutside()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();

	Rectangle LabWarp = { 360, 360, 80, 20 };
	Rectangle shopWarp = { 32, 700, 80, 30 };
	Rectangle houseWarp = { 1260,240, 20, 90 };

	Rectangle trashBin = { 200, 500, 30, 30 };

	DrawTexture(outsideTexture, 0, 0, WHITE);

	DrawRectangleRec(LabWarp, BLUE);

	if (CheckCollisionRecs(player.fullPosition, LabWarp) && IsKeyPressed(KEY_F))
	{
		map.isInLab = true;
		map.isOutdoor = false;
	}

	DrawRectangleRec(shopWarp, GREEN);

	if (CheckCollisionRecs(player.fullPosition, shopWarp) && IsKeyPressed(KEY_F))
	{
		map.isOutdoor = false;
		map.isInShop = true;
	}

	DrawRectangleRec(houseWarp, YELLOW);

	if (CheckCollisionRecs(player.fullPosition, houseWarp) && IsKeyPressed(KEY_F))
	{
		map.isOutdoor = false;
		map.isInHouse = true;
	}

	DrawRectangleRec(trashBin, ORANGE);

	if (CheckCollisionRecs(player.fullPosition, trashBin) && IsKeyPressed(KEY_Q))
	{
		inventory.removeItem();
	}

	map.OpenMapMenu();
}

/**
 * .Generate junk aroundd the map
 * 
 */
void Outside::generateJunk()
{
	static std::vector<Junk> junk;
	Player& player = Player::getInstance();
	Inventory& inventory = Inventory::getInstance();

	int junkType = GetRandomValue(0, 3);

	Junk NewJunk = types[junkType];

	float DrawX = GetRandomValue(960, 1820);
	float DrawY = GetRandomValue(340, 820);

	NewJunk.setHitbox(DrawX, DrawY);

	if (junk.size() < 4)
	{
		junk.push_back(NewJunk);
	}

	for (auto i = 0; i < junk.size(); i++)
	{
		junk[i].setSpawnTimer(junk[i].getSpawnTimer() - 1);

		if (CheckCollisionRecs(player.fullPosition, junk[i].getHitbox()) && IsKeyPressed(KEY_F))
		{
			inventory.addItem(junk[i]);
		}

		if (junk[i].getSpawnTimer() <= 0)
		{
			junk[i].DrawJunk();
		}

		if (junk[i].getLifetimer() <= 0 || junk[i].getIsPickedUp() == true)
		{
			junk.erase(junk.begin() + i);
		}
	}
}