#include "Inventory.h"
#include <raylib.h>

#include "Player.h"

#include <iostream>

Inventory::Inventory()
{

}

Inventory& Inventory::getInstance()
{
	static Inventory inventory;
	return inventory;
}

void Inventory::setBalance(int balance)
{
	this->balance = balance;
}

int Inventory::getBalance()
{
	return this->balance;
}

void Inventory::setSelectedSlot(unsigned slot)
{
	this->selectedSlot = slot;
}

unsigned Inventory::getSelectedSlot()
{
	return this->selectedSlot;
}

std::vector<Item> Inventory::getItems()
{
	return this->items;
}

void Inventory::addItem(Item& item)
{
	items[selectedSlot] = (item);
	item.setIsPickedUp(true);
}

void Inventory::removeItem()
{
	items[selectedSlot] = Item("", 0);
}

void Inventory::drawInventory()
{
	Player& player = Player::getInstance();

	int drawX = 275;
	int drawY = 200;

	for (auto i = 0; i < 3; i++)
	{
		DrawRectangle(player.cameraPos.x + drawX, player.cameraPos.y + drawY, 50, 50, WHITE);
		if (i == selectedSlot)
		{
			DrawRectangle(player.cameraPos.x + drawX, player.cameraPos.y + drawY, 50, 50, { 70,175,240,100 });
		}
		drawX += 65;
	}

	drawX = 275;

	for (auto i = 0; i < 3; i++)
	{
		DrawText(items[i].getName().c_str(), player.cameraPos.x + drawX + 20, player.cameraPos.y + drawY + 15, 20, RED);
		drawX += 65;
	}

	DrawText(TextFormat("%i", balance), player.cameraPos.x + 420, player.cameraPos.y - 260, 20, WHITE);
}

void Inventory::DrawOutzoomed()
{
	int drawX = 1700;
	int drawY = 1000;

	for (auto i = 0; i < 3; i++)
	{
		DrawRectangle(drawX, drawY, 50, 50, WHITE);
		if (i == selectedSlot)
		{
			DrawRectangle(drawX, drawY, 50, 50, { 70,175,240,100 });
		}
		drawX += 65;
	}

	drawX = 1700;

	for (auto i = 0; i < 3; i++)
	{
		DrawText(items[i].getName().c_str(), drawX + 20, drawY + 15, 20, RED);
		drawX += 65;
	}

	DrawText(TextFormat("%i", balance), 1800, 30, 40, WHITE);
}

void Inventory::manageInvetory()
{
	if (IsKeyPressed(KEY_ONE))
	{
		this->selectedSlot = 0;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		this->selectedSlot = 1;
	}
	else if (IsKeyPressed(KEY_THREE))
	{
		this->selectedSlot = 2;
	}
}
