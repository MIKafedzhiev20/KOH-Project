#pragma once
#include <raylib.h>
#include <assert.h>
#include <iostream>

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
