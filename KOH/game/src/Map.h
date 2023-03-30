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
	void OpenMapMenu();

	bool isOutdoor = false;
	bool isInLab = false;
	bool isInShop = false;
	bool isInHouse = false;

	bool isMapMenuOpen = false;

	bool isOnLaptop = false;

private:
	void goOutdoors();
	void goInLab();
	void goOutShop();

	Laboratory laboratory;
};

class MainMenu
{
public:
	MainMenu();

	void DrawMainMenu();

	MainMenu(MainMenu const&) = delete;
	void operator=(MainMenu const&) = delete;

	static MainMenu& getInstance();

	bool isMenuOpen = true;
	bool isGameStarted = false;
	bool gameShouldClose = false;

	bool isExitPressed = false;
};

bool DrawButtonText(Vector2 pos, int width, int height, int fontSize, const char* name);

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture);