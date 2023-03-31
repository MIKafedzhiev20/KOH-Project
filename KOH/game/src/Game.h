#pragma once
#include <iostream>
#include <raylib.h>
#include <assert.h>
#include <cmath>

#include "Player.h"
#include "Map.h"
#include "Inventory.h"

using namespace std;

class Game
{
public:
	// Creates the game window
	Game(int width, int height, int fps);

	// Closes the game window
	~Game() noexcept;

	// Checks if the window should close
	bool GameShouldClose() const;

	void Tick();
private:
	void Update();

	void Draw();

	int width = 0;
	int height = 0;

	Camera2D camera = { {(float)width / 2, (float)height / 2}, {200, 200}, 0, 2 };

	Vector2 mouse = { 0,0 };

	Player& player = Player::getInstance();

	Map& map = Map::getInstance();

	MainMenu& mainMenu = MainMenu::getInstance();

	Inventory& inventory = Inventory::getInstance();
};