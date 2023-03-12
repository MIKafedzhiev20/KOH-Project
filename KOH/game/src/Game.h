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

private:
	void Update();

	void Draw();

	bool gameShouldClose = false;

	int width = 0;
	int height = 0;

	Camera2D camera = { {(float)width/2, (float)height/2}, {0,0}, 0, 2};
};

class MainMenu
{
public:
	bool isMenuOpen = true;
	bool isGameStarted = false;
	void DrawMainMenu(MainMenu& mainMenu, bool& gameShouldClose);
private:
};

Vector2 vPos(int x, int y);

bool DrawButtonText(Vector2 pos, int width, int height, int fontSize, const char* name, Font font);

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture);