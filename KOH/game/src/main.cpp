#include "Game.h"

int main()
{
	int width = 1920;
	int height = 1080;

	InitWindow(width, height, "KOH");

	elements = Element::createElement();

	Game game(width, height, 60);

	ifstream loadData;
	LoadSavedData(loadData);

	while (!game.GameShouldClose())
	{
		game.Tick();
	}
}
