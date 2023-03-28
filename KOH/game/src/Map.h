#pragma once
#include <raylib.h>

class Map
{
public:
	static Map& getInstance();
	void DrawMap();

	bool isOutdoor = false;
	bool isInLab = false;
	bool isInShop = false;
private:
	void goOutdoors();
	void goInLab();
	void goOutShop();
};

class MainMenu
{
public:
	void DrawMainMenu();

	bool isMenuOpen = true;
	bool isGameStarted = false;
	bool gameShouldClose = false;
};

bool DrawButtonText(Vector2 pos, int width, int height, int fontSize, const char* name, Font font);

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture);