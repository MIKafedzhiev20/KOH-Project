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
		DrawRectangle(player.position.x - 300, player.position.y - 150, 600, 270, Color	{103,102,90,100});

		int xDraw = 10;
		int yDraw = 10;
		int element = 0;

		for (auto i = 0; i < 3; i++)
		{
			for (auto j = 0; j < 8; j++)
			{
				DrawRectangle(player.position.x - (300-xDraw), player.position.y - (150-yDraw), 50, 50, RAYWHITE);
				xDraw += 75;

				if (element < 21)
				{
					DrawText(elements[element].getName().c_str(), player.position.x - (300 - xDraw + 60.5), player.position.y - (150 - yDraw - 15), 20, RED);
					DrawText(TextFormat("%i", elements[element].getAmount()), player.position.x - (300 - xDraw + 35), player.position.y - (150 - yDraw - 40), 5, RED);
					element++;
				}
			}
			yDraw += 100;
			xDraw = 10;
		}
	}
}
