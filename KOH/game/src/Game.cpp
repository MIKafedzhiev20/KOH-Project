#include "game.h"

Game::Game(int width, int height, int fps, string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
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
	player.move();
}

void Game::Draw()
{
	ClearBackground(BLACK);
	
	/*static MainMenu mainMenu;

	if (mainMenu.isMenuOpen)
	{
		Rectangle newGameB = { 100, 200, 480, 100 };
		Rectangle countinueB = { 100, 400, 440, 100 };
		Rectangle settingsB = { 100, 600, 440, 100 };
		Rectangle exitB = { 100, 800, 200, 100 };

		DrawText("New Game", 100, 200, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), newGameB))
		{
			DrawText("New Game", 100, 200, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mainMenu.isMenuOpen = false;
			}
		}

		DrawText("Continue", 100, 400, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), countinueB))
		{
			DrawText("Continue", 100, 400, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mainMenu.isMenuOpen = false;
			}
		}

		DrawText("Settings", 100, 600, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), settingsB))
		{
			DrawText("Settings", 100, 600, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mainMenu.isMenuOpen = false;
			}
		}

		DrawText("Exit", 100, 800, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), exitB))
		{
			DrawText("Exit", 100, 800, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				gameShouldClose = true;
			}
		}
	}*/
}

Vector2 MousePos()
{
	Vector2 pos;

	pos.x = GetMouseX();
	pos.y = GetMouseY();

	return pos;
}