#include "Game.h"

int main()
{
	Game game(600, 600, 60, "Project");

	while (!game.GameShouldClose())
	{
		game.Tick();
	}
}