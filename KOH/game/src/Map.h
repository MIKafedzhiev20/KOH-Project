#pragma once
#include <raylib.h>
#include "Laboratory.h"

class Map
{
public:
	Map();

	Map(Map const&) = delete;
	void operator=(Map const&) = delete;

	static Map& getInstance();

	void DrawMap();

	bool isOutdoor = false;
	bool isInLab = false;
	bool isInShop = false;
private:
	void goOutdoors();
	void goInLab();
	void goOutShop();

	Laboratory laboratory;
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