#pragma once
#include <raylib.h>
#include "Laboratory.h"
#include "Outside.h"
#include "Shop.h"
#include "House.h"

class Map
{
public:
	// Operators
	Map(Map const&) = delete;
	void operator=(Map const&) = delete;

	// Public functions
	static Map& getInstance();
	void DrawMap();
	void OpenMapMenu();

	bool isOutdoor = false;
	bool isInLab = false;
	bool isInShop = false;
	bool isInHouse = false;

	bool isMapMenuOpen = false;

private:
	// Constructor
	Map();

	Laboratory laboratory;
	Outside outside;
	Shop shop;
	House house;
};

class MainMenu
{
public:
	// Operators
	MainMenu(MainMenu const&) = delete;
	void operator=(MainMenu const&) = delete;

	// Public functions
	static MainMenu& getInstance();
	void DrawMainMenu();

	bool isMenuOpen = true;
	bool isGameStarted = false;
	bool gameShouldClose = false;

	bool isExitPressed = false;

private:
	// Constructor
	MainMenu();
};

bool DrawButtonText(Vector2 pos, int width, int height, int fontSize, const char* name);

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture);