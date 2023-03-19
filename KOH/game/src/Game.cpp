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
	static Rectangle enemyRect = { 100,100,20,20 };
	Rectangle playerRect = { player.position.x, player.position.y, 20, 20 };

	if (player.isOnMap)
	{
		player.move();
		camera.target = player.position;

		mouse = GetScreenToWorld2D(vPos(GetMouseX(), GetMouseY()), camera);

		bool collision = CheckCollisionCircleRec(player.position, 25, enemyRect);

		if (CheckCollisionRecs(playerRect, enemyRect))
		{
			float dx = (playerRect.x + playerRect.width / 2) - (enemyRect.x + enemyRect.width / 2);
			float dy = (playerRect.y + playerRect.height / 2) - (enemyRect.y + enemyRect.height / 2);
			float width = (playerRect.width + enemyRect.width) / 2;
			float height = (playerRect.height + enemyRect.height) / 2;
			float overlapX = width - abs(dx);
			float overlapY = height - abs(dy);

			enum { None, Top, Bottom, Left, Right } side = None;

			float directionX = dx > 0 ? 1 : -1;
			float directionY = dy > 0 ? 1 : -1;

			if (overlapX > overlapY)
			{
				if (directionY > 0)
				{
					side = Top;
				}
				else
				{
					side = Bottom;
				}
			}
			else
			{
				if (directionX > 0)
				{
					side = Left;
				}
				else
				{
					side = Right;
				}
			}

			switch (side)
			{
			case Top:
				player.position.y += overlapY;
				break;
			case Bottom:
				player.position.y -= overlapY;
				break;
			case Left:
				player.position.x += overlapX;
				break;
			case Right:
				player.position.x -= overlapX;
				break;
			default:
				break;
			}
		}
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
		static Texture2D button = LoadTexture("assets/button.png");
		if (DrawButtonTexture(0, 0, 100, 100, button))
		{
			mainMenu.isMenuOpen = true;
			mainMenu.isGameStarted = false;
			player.isOnMap = false;
		}

		DrawRectangle(100, 100, 20, 20, BLUE);
	}
}

bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture)
{
	Rectangle rec = { x, y, width, height };

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
	Rectangle rec = { pos.x, pos.y, width, height };

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