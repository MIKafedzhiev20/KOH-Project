#include "Inventory.h"
#include <raylib.h>

#include "Player.h"

Inventory::Inventory()
{

}

Inventory& Inventory::getInstance()
{
	static Inventory inventory;
	return inventory;
}

void Inventory::setElement(std::vector<Element> elements)
{
	this->elements = elements;
}

std::vector<Element> Inventory::getElement()
{
	return this->elements;
}

void Inventory::setBalance(float balance)
{
	this->balance = balance;
}

float Inventory::getBalance()
{
	return this->balance;
}

void Inventory::drawInventory()
{
	Player& player = Player::getInstance();

	if (IsKeyDown(KEY_TAB))
	{
		int drawSpace = 40;
		int element = 0;

		for (auto i = 0; i < 3; i++)
		{
			DrawRectangle(player.position.x + 420, player.position.y + drawSpace, 50, 50, RAYWHITE);
			drawSpace += 75;

			if (element < 3)
			{
				DrawText(elements[element].getName().c_str(), player.position.x + 432, player.position.y + drawSpace - 60, 20, RED);
				DrawText(TextFormat("%i", elements[element].getAmount()), player.position.x + 460, player.position.y + drawSpace - 38, 5, RED);
				element++;
			}
		}
	}
}
