#include "game.h"

Game::Game(int width, int height, int fps, string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	//ToggleFullscreen();
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return gameShouldClose || WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();

	Update();

	Draw();

	EndDrawing();
}

void Game::Update()
{

}

void Game::Draw()
{

}
