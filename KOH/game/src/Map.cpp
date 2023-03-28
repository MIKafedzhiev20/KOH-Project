#include "Map.h"
#include "Player.h"

Map::Map()
{

}

Map& Map::getInstance()
{
	static Map map;
	return map;
}

void Map::goOutdoors()
{
	isOutdoor = true;
	isInLab = false;
	isInShop = false;
}

void Map::goInLab()
{
	isOutdoor = false;
	isInLab = true;
	isInShop = false;
}

void Map::goOutShop()
{
	isOutdoor = true;
	isInLab = false;
	isInShop = false;
}

void Map::DrawMap()
{
	Player& player = Player::getInstance();

	if (isOutdoor == true)
	{
		Rectangle LabWarp = { 100, 100, 30, 30 };
		Rectangle shopWarp = { 400, 400, 30, 30 };

		DrawRectangleRec(LabWarp, BLUE);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, LabWarp))
		{
			isOutdoor = false;
			isInLab = true;
		}

		DrawRectangleRec(shopWarp, BLUE);

		if (CheckCollisionRecs({ player.position.x, player.position.y, 20, 20 }, shopWarp))
		{
			isOutdoor = false;
			isInShop = true;
		}
	}

	if (isInShop)
	{
	}

	if (isInLab == true)
	{
		//laboratory.DrawLaboratory();
	}
}

void MainMenu::DrawMainMenu()
{
	Player& player = Player::getInstance();
	Map& map = Map::getInstance();

	if (isMenuOpen)
	{
		static Font font = LoadFont("assets/pixantiqua.png");

		if (DrawButtonText({ 100, 200 }, 560, 100, 100, "New Game", font))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.isOnMap = true;
			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 400 }, 456, 100, 100, "Continue", font))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.isOnMap = true;
			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 600 }, 450, 100, 100, "Settings", font))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.isOnMap = true;
		}

		if (DrawButtonText({ 100, 800 }, 200, 100, 100, "Exit", font))
		{
			gameShouldClose = true;
		}
	}
}

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture)
{
	Rectangle rec = { x, y, width, height };

	DrawTexture(texture, rec.x, rec.y, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		DrawTexture(texture, rec.x, rec.y, DARKGRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}

	return 0;
}

bool DrawButtonText(Vector2 pos,int width, int height, int fontSize, const char* name, Font font)
{
	Rectangle rec = { pos.x, pos.y, width, height };

	DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, WHITE);
	if (CheckCollisionPointRec({ (float)GetMouseX(), (float)GetMouseY() }, rec))
	{
		DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, YELLOW);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
	return 0;
}

