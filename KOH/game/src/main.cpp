#include "Game.h"

int main()
{
	int width = 1920;
	int height = 1080;

	InitWindow(width, height, "KOH");

	Game game(width, height, 60);

	while (!game.GameShouldClose())
	{
		game.Tick();
	}
}