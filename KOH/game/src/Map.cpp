#include "Map.h"
#include "Player.h"

#include <iostream>
using namespace std;

Map::Map()
{

}

MainMenu::MainMenu()
{

}

Map& Map::getInstance()
{
	static Map map;
	return map;
}

MainMenu& MainMenu::getInstance()
{
	static MainMenu mainMenu;
	return mainMenu;
}

void Map::goOutdoors()
{
	isInShop = false;
	isInLab = false;
	isOutdoor = true;
}

void Map::goInLab()
{
	isOutdoor = false;
	isInShop = false;
	isInLab = true;
}

void Map::goOutShop()
{
	isInLab = false;
	isInShop = false;
	isOutdoor = true;
}

void Map::DrawMap()
{
	Player& player = Player::getInstance();

	if (isOutdoor)
	{
		outside.DrawOutside();
		outside.generateJunk();
	}

	if (isInShop)
	{
		shop.drawTexture();
	}

	if (isInHouse)
	{
		house.drawHouse();
	}

	if (isInLab)
	{
		laboratory.DrawLaboratory();
	}
}

void MainMenu::DrawMainMenu()
{
	if (isMenuOpen)
	{
		Player& player = Player::getInstance();
		Map& map = Map::getInstance();

		if (DrawButtonText({ 100, 200 }, 560, 100, 100, "New Game"))
		{
			isMenuOpen = false;
			isGameStarted = true;

			player.isOnMap = true;
			player.position = { 200, 200 };

			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 400 }, 456, 100, 100, "Continue"))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.isOnMap = true;
			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 600 }, 450, 100, 100, "Settings"))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.isOnMap = true;
		}

		if (DrawButtonText({ 100, 800 }, 200, 100, 100, "Exit"))
		{
			if (!isExitPressed)
			{
				gameShouldClose = true;
			}
			else
			{
				isExitPressed = false;
			}
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

bool DrawButtonText(Vector2 pos,int width, int height, int fontSize, const char* name)
{
	static Font font = LoadFont("../assets/pixantiqua.png");
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

void Map::OpenMapMenu()
{
	Player& player = Player::getInstance();

	MainMenu& mainMenu = MainMenu::getInstance();

	if (IsKeyPressed(KEY_ESCAPE))
	{
		player.isOnMap = false;
		isMapMenuOpen = true;
	}

	if (isMapMenuOpen)
	{
		DrawRectangle(0, 0, 950, 1080, GRAY);

		if (DrawButtonText({ 100, 200 }, 560, 100, 100, "Resume"))
		{
			isMapMenuOpen = false;
			player.isOnMap = true;
		}

		if (DrawButtonText({ 100, 400 }, 450, 100, 100, "Settings"))
		{

		}

		if (DrawButtonText({ 100, 600 }, 200, 100, 100, "Save"))
		{

		}

		if (DrawButtonText({ 100, 800 }, 200, 100, 100, "Exit"))
		{
			isOutdoor = false;
			isInLab = false;
			isInShop = false;

			isMapMenuOpen = false;
			player.isOnMap = false;
			mainMenu.isMenuOpen = true;

			mainMenu.isExitPressed = true;
		}
	}
}