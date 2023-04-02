#include "Shop.h"
#include "Player.h"
#include "Map.h"

Shop::Shop()
{
	shopTexture = LoadTexture("../assets/DevShop.png");
}

Shop::~Shop()
{
	UnloadTexture(shopTexture);
}

void Shop::drawTexture()
{
	Map& map = Map::getInstance();
	Player& player = Player::getInstance();

	DrawTexture(shopTexture, 0, 0, WHITE);

	if (DrawButtonText({ 0, 0 }, 150, 44, 50, "BACK"))
	{
		map.isOutdoor = true;
		map.isInShop = false;
		player.isOnMap = true;
	}
}