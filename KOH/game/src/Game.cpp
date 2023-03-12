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
		player.move();
		camera.target = player.position;

		mouse = GetScreenToWorld2D(vPos(GetMouseX(), GetMouseY()), camera);
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

Vector2 vPos(int x, int y)
{
	Vector2 pos;

	pos.x = x;
	pos.y = y;

	return pos;
}

void MainMenu::DrawMainMenu(MainMenu& mainMenu, bool& gameShouldClose)
{
	if (mainMenu.isMenuOpen)
	{
		static Font font = LoadFont("../assets/pixantiqua.png");

		if (DrawButtonText(vPos(100, 200), 560, 100, 100, "New Game", font))
		{
			mainMenu.isMenuOpen = false;
			mainMenu.isGameStarted = true;
			player.isOnMap = true;
		}

		if (DrawButtonText(vPos(100, 400), 456, 100, 100, "Continue", font))
		{
			mainMenu.isMenuOpen = false;
			mainMenu.isGameStarted = true;
			player.isOnMap = true;
		}

		if (DrawButtonText(vPos(100, 600), 450, 100, 100, "Settings", font))
		{
			mainMenu.isMenuOpen = false;
			mainMenu.isGameStarted = true;
			player.isOnMap = true;
		}

		if (DrawButtonText(vPos(100, 800), 200, 100, 100, "Exit", font))
		{
			gameShouldClose = true;
		}
	}
	else
	{
		static Texture2D button = LoadTexture("../assets/button.png");
		if (DrawButtonTexture(0, 0, 100, 100, button))
		{
			mainMenu.isMenuOpen = true;
			mainMenu.isGameStarted = false;
			player.isOnMap = false;
		}
	}
}

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture)
{
	Rectangle rec = { x, y, width, height};

	DrawTexture(texture, rec.x, rec.y, WHITE);
	if (CheckCollisionPointRec(mouse, rec))
	{
		DrawTexture(texture, rec.x, rec.y, DARKGRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
		
	return 0;
}

bool DrawButtonText(Vector2 pos, int width, int height, int fontSize, const char* name, Font font)
{
	Rectangle rec = { pos.x, pos.y, width, height};

	DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, WHITE);
	if (CheckCollisionPointRec(vPos(GetMouseX(), GetMouseY()), rec))
	{
		DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, YELLOW);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
	return 0;
}