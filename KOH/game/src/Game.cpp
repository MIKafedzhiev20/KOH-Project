#include "game.h"

Game::Game(int widthIn, int heightIn, int fps)
	:
	width(widthIn),
	height(heightIn)
{
	SetTargetFPS(fps);
	SetExitKey(KEY_BACKSPACE);
	ToggleFullscreen();
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return mainMenu.gameShouldClose || WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();

	if (player.isOnMap)
	{
		BeginMode2D(camera);
	}

	Update();

	Draw();

	if (!player.isOnMap)
	{
		EndMode2D();
	}

	EndDrawing();
}

void Game::Update()
{
	if (player.isOnMap)
	{
		mouse = GetScreenToWorld2D(GetMousePosition(), camera);

		player.cameraPos.x = camera.target.x;
		player.cameraPos.y = camera.target.y;
		player.move();
		camera.target = player.position;

		inventory.manageInvetory();
	}
	else
	{
		mouse = GetMousePosition();
	}

	Rectangle playerRect = { player.position.x, player.position.y, 20, 20 };
}

void Game::Draw()
{
	ClearBackground(BLACK);

	if (mainMenu.isGameStarted)
	{
		if (!mainMenu.isMenuOpen)
		{
			map.DrawMap();
		}

		if (player.isOnMap)
		{
			player.drawPlayer();
			inventory.drawInventory();
		}
	}
	mainMenu.DrawMainMenu();
}