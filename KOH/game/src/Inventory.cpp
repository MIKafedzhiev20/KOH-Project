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

void Inventory::setBalance(float balance)
{
	this->balance = balance;
}

float Inventory::getBalance()
{
	return this->balance;
}

void Inventory::addItem(Item& item)
{
	if (this->filledSlots < this->slots)
	{
		items.push_back(item);
		filledSlots++;
		item.setIsPickedUp(true);
	}
	else
	{
		DrawText("Inventory Full", 100, 100, 20, RED);
	}
}

void Inventory::removeItem(const unsigned index)
{
	items.erase(items.begin() + index);
}

void Inventory::drawInventory()
{
	Player& player = Player::getInstance();

	int drawX = 275;
	int drawY = 200;

	for (auto i = 0; i < 3; i++)
	{
		DrawRectangle(player.cameraPos.x + drawX , player.cameraPos.y + drawY, 50, 50, RAYWHITE);
		drawX += 65;
	}

	drawX = 275;

	for (auto i = 0; i < filledSlots; i++)
	{
		DrawText(items[i].getName().c_str(), player.cameraPos.x + drawX + 20, player.cameraPos.y + drawY + 15, 20, RED);
		DrawText(TextFormat("%i", items[i].getAmount()), player.cameraPos.x + drawX + 40, player.cameraPos.y + drawY + 40, 5, RED);
		drawX += 65;
	}
}