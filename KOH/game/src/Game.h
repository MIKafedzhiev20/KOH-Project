#pragma once
#include <iostream>
#include <raylib.h>
#include <assert.h>

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
};

class MainMenu
{
public:
	bool isMenuOpen = true;
private:
};

Vector2 MousePos();