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
	ToggleFullscreen();
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
		BeginMode2D(camera);
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

void SaveData(ofstream& saveData)
{
	MainMenu& mainMenu = MainMenu::getInstance();
	Inventory& inventory = Inventory::getInstance();

	saveData.open("../assets/Data.txt");

	if (saveData.is_open())
	{
		saveData << mainMenu.isGameGoing << endl;

		for (int i = 0; i < 22; i++)
		{
			saveData << elements[i].getIsUnlocked() << endl;
		}

		for (int i = 0; i < 17; i++)
		{
			saveData << reactions[i].getIsObtained() << endl;
		}

		std::vector<Item> items = inventory.getItems();

		for (int i = 0; i < 3; i++)
		{
			if (items[i].getName() == "")
			{
				saveData << "NULL" << endl;
			}
			else
			{
				saveData << items[i].getName() << endl;
			}
			saveData << items[i].getType() << endl;
		}

		saveData.close();
	}
}

void LoadSavedData(ifstream& loadData)
{
	MainMenu& mainMenu = MainMenu::getInstance();
	Inventory& inventory = Inventory::getInstance(); 

	loadData.open("../assets/Data.txt");

	if (loadData.is_open())
	{
		loadData >> mainMenu.isGameGoing;

		for (int i = 0; i < 22; i++)
		{
			bool isUnlocked = false;
			loadData >> isUnlocked;
			elements[i].setIsUnlocked(isUnlocked);
		}

		for (int i = 0; i < 17; i++)
		{
			bool isObtained = false;
			loadData >> isObtained;
			reactions[i].setIsObtained(isObtained);
		}

		std::vector<Item> items = inventory.getItems();

		for (int i = 0; i < 3; i++)
		{
			string name = "";
			int type = 3;

			loadData >> name;
			loadData >> type;

			if (name == "NULL")
			{
				name = "";
			}

			items[i] = { name, type };
		}

		inventory.setItems(items[0], items[1], items[2]);

		loadData.close();
	}
}