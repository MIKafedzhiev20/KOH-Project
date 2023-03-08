#include "Game.h"

int main()
{
	Game game(1920, 1080, 60, "Project");

	while (!game.GameShouldClose())
	{
		game.Tick();
	}
}