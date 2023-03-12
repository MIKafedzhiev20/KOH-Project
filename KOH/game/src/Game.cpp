#include "game.h"

Player& player = Player::getInstance();

Vector2 mouse = { 0,0 };

Game::Game(int widthIn, int heightIn, int fps, string title)
	:
	width(widthIn),
	height(heightIn)
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
	if (player.isOnMap)
	{
		BeginMode2D(camera);
	}

	Update();

	Draw();

	EndMode2D();
	EndDrawing();
}

void Game::Update()
{
	if (player.isOnMap)
	{
		player.move();
		camera.target = player.position;

		mouse = GetScreenToWorld2D(MousePos(), camera);
	}
}

void Game::Draw()
{
	ClearBackground(BLACK);

	if (player.isOnMap)
	{
		player.drawPlayer();
	}

	static MainMenu mainMenu;
	mainMenu.DrawMainMenu(mainMenu, gameShouldClose);
}

Vector2 MousePos()
{
	Vector2 pos;

	pos.x = GetMouseX();
	pos.y = GetMouseY();

	return pos;
}

void MainMenu::DrawMainMenu(MainMenu& mainMenu, bool& gameShouldClose)
{
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
				mainMenu.isGameStarted = true;
				player.isOnMap = true;
			}
		}

		DrawText("Continue", 100, 400, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), countinueB))
		{
			DrawText("Continue", 100, 400, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mainMenu.isMenuOpen = false;
				mainMenu.isGameStarted = true;
				player.isOnMap = true;
			}
		}

		DrawText("Settings", 100, 600, 100, WHITE);
		if (CheckCollisionPointRec(MousePos(), settingsB))
		{
			DrawText("Settings", 100, 600, 100, YELLOW);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mainMenu.isMenuOpen = false;
				player.isOnMap = true;
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
	}
	else
	{
		StartGame(mainMenu);
	}
}

void StartGame(MainMenu& mainMenu)
{
	Rectangle backB = { 0, 0, 100, 100 };

	DrawRectangleRec(backB, WHITE);
	if (CheckCollisionPointRec(mouse, backB))
	{
		DrawRectangleRec(backB, YELLOW);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			mainMenu.isMenuOpen = true;
			mainMenu.isGameStarted = false;
			player.isOnMap = false;
		}
	}
}