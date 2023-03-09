#pragma once
#include <iostream>
#include <raylib.h>
#include <assert.h>

#include "Player.h"

using namespace std;


class Game
{
public:
	// Creates the game window
	Game(int width, int height, int fps, string title);

	// Closes the game window
	~Game() noexcept;

	// Checks if the window should close
	bool GameShouldClose() const;

	void Tick();

	Player player;

private:
	void Update();

	void Draw();

	bool gameShouldClose = false;
};

class MainMenu
{
public:
	bool isMenuOpen = true;
	bool isGameStarted = false;
	void DrawMainMenu(MainMenu& mainMenu, bool& gameShouldClose);
private:
};

Vector2 MousePos();

void StartGame(MainMenu& mainMenu);