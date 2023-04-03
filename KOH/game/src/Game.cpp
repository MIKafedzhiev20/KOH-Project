#include "game.h"

/**
 * .Create instance of game
 * 
 * \param widthIn the window's width
 * \param heightIn the window's height
 * \param fps the game's fps
 */
Game::Game(int widthIn, int heightIn, int fps)
	:
	width(widthIn),
	height(heightIn)
{
	SetTargetFPS(fps);
	SetExitKey(KEY_BACKSPACE);
	//ToggleFullscreen();
}

/**
 * .Closes the game
 */
Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

/**
 * .Checks if the window should close
 * 
 * \return true/false depending on if the winodow should close or not
 */
bool Game::GameShouldClose() const
{
	return mainMenu.gameShouldClose || WindowShouldClose();
}

/**
 * .Controls the game loop
 */
void Game::Tick()
{
	BeginDrawing();

	if (player.getIsOnMap())
	{
		//BeginMode2D(camera);
	}

	Update();

	Draw();

	if (!player.getIsOnMap())
	{
		EndMode2D();
	}

	EndDrawing();
}

/**
 * .Updates the game logic
 * 
 */
void Game::Update()
{

	if (player.getIsOnMap())
	{
		mouse = GetScreenToWorld2D(GetMousePosition(), camera);
		player.setCameraPos({ camera.target.x , camera.target.y });
		player.move();
		camera.target = player.getPosition();

		inventory.manageInvetory();
	}
	else
	{
		mouse = GetMousePosition();
	}

	Rectangle playerRect = { player.getPosition().x, player.getPosition().y, 20, 20};
}

/**
 * .Draws the elements of the game
 * 
 */
void Game::Draw()
{
	ClearBackground(BLACK);

	if (mainMenu.isGameStarted)
	{
		if (!mainMenu.isMenuOpen)
		{
			map.DrawMap();
		}

		if (player.getIsOnMap())
		{
			player.drawPlayer();
			inventory.drawInventory();
		}
	}
	mainMenu.DrawMainMenu();
}