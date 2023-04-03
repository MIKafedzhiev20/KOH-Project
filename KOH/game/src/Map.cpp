#include "Map.h"
#include "Player.h"

/**
 * .Create instance of Map
 * 
 */
Map::Map()
{

}

/**
 * .Create instance of MainMenu
 * 
 */
MainMenu::MainMenu()
{

}

/**
 * .Create static instance of Map
 * 
 * \return static instance of Map
 */
Map& Map::getInstance()
{
	static Map map;
	return map;
}

/**
 * .Create static instance of MainMenu
 *
 * \return static instance of MainMenu
 */
MainMenu& MainMenu::getInstance()
{
	static MainMenu mainMenu;
	return mainMenu;
}

/**
 * .Draw the coresponding fragment of the map
 * 
 */
void Map::DrawMap()
{
	Player& player = Player::getInstance();

	if (isOutdoor)
	{
		outside.DrawOutside();
		outside.generateJunk();
	}

	if (isInShop)
	{
		shop.drawTexture();
	}

	if (isInHouse)
	{
		house.drawHouse();
	}

	if (isInLab)
	{
		laboratory.DrawLaboratory();
	}
}

/**
 * .Draws the main menu 
 */
void MainMenu::DrawMainMenu()
{
	if (isMenuOpen)
	{
		Player& player = Player::getInstance();
		Map& map = Map::getInstance();

		if (DrawButtonText({ 100, 200 }, 560, 100, 100, "New Game"))
		{
			isMenuOpen = false;
			isGameStarted = true;

			player.setIsOnMap(true);
			player.setPosition({ 200, 200 });

			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 400 }, 456, 100, 100, "Continue"))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.setIsOnMap(true);
			map.isOutdoor = true;
		}

		if (DrawButtonText({ 100, 600 }, 450, 100, 100, "Settings"))
		{
			isMenuOpen = false;
			isGameStarted = true;
			player.setIsOnMap(true);
		}

		if (DrawButtonText({ 100, 800 }, 200, 100, 100, "Exit"))
		{
			if (!isExitPressed)
			{
				gameShouldClose = true;
			}
			else
			{
				isExitPressed = false;
			}
		}
	}
}

/**
 * .Draw texture which acts as a button
 * 
 * \param x the x coordinate of the texture
 * \param y the y coordinate of the texture
 * \param width the width of the texture
 * \param height the height of the texture
 * \param texture the texture file
 * \return true/false if the texture is clicked
 */
bool DrawButtonTexture(int x, int y, int width, int height, Texture2D texture)
{
	Rectangle rec = { x, y, width, height };

	DrawTexture(texture, rec.x, rec.y, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		DrawTexture(texture, rec.x, rec.y, DARKGRAY);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}

	return 0;
}

/**
 * .Draw text which acts as a button
 * 
 * \param pos the position of the text
 * \param width the with of the text
 * \param height the height of the text
 * \param fontSize the font size
 * \param name the displayed text
 * \return true/false if the text is clicked
 */
bool DrawButtonText(Vector2 pos,int width, int height, int fontSize, const char* name)
{
	static Font font = LoadFont("../assets/pixantiqua.png");
	Rectangle rec = { pos.x, pos.y, width, height };

	DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, WHITE);
	if (CheckCollisionPointRec({ (float)GetMouseX(), (float)GetMouseY() }, rec))
	{
		DrawTextEx(font, name, pos, fontSize, fontSize / 5 - fontSize / 20, YELLOW);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			return 1;
		}
	}
	return 0;
}

/**
 * .Open the ingame menu
 * 
 */
void Map::OpenMapMenu()
{
	Player& player = Player::getInstance();

	MainMenu& mainMenu = MainMenu::getInstance();

	if (IsKeyPressed(KEY_ESCAPE))
	{
		player.setIsOnMap(false);
		isMapMenuOpen = true;
	}

	if (isMapMenuOpen)
	{
		DrawRectangle(0, 0, 950, 1080, GRAY);

		if (DrawButtonText({ 100, 200 }, 560, 100, 100, "Resume"))
		{
			isMapMenuOpen = false;
			player.setIsOnMap(true);
		}

		if (DrawButtonText({ 100, 400 }, 450, 100, 100, "Settings"))
		{

		}

		if (DrawButtonText({ 100, 600 }, 200, 100, 100, "Save"))
		{

		}

		if (DrawButtonText({ 100, 800 }, 200, 100, 100, "Exit"))
		{
			isOutdoor = false;
			isInLab = false;
			isInShop = false;

			isMapMenuOpen = false;
			player.setIsOnMap(false);
			mainMenu.isMenuOpen = true;

			mainMenu.isExitPressed = true;
		}
	}
}