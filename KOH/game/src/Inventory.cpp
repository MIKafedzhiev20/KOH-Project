#include "Inventory.h"
#include <raylib.h>

#include "Player.h"

/**
 * .Create instance of the inventory
 * 
 */
Inventory::Inventory()
{

}

/**
 * .Create static instance of the inventory
 * 
 * \return static instance of Inventory
 */
Inventory& Inventory::getInstance()
{
	static Inventory inventory;
	return inventory;
}

/**
 * .Sets the balance to a new one
 * 
 * \param balance the new balance
 */
void Inventory::setBalance(int balance)
{
	this->balance = balance;
}

/**
 * .Return the balance
 * 
 * \return balance
 */
int Inventory::getBalance()
{
	return this->balance;
}

/**
 * .Sets the selected slot to a new one
 * 
 * \param slot the new selected slot
 */
void Inventory::setSelectedSlot(unsigned slot)
{
	this->selectedSlot = slot;
}

/**
 * .Returns the selected slot
 * 
 * \return selected slot 
 */
unsigned Inventory::getSelectedSlot()
{
	return this->selectedSlot;
}

/**
 * .Return the items which are in the inventory
 * 
 * \return items vector
 */
std::vector<Item> Inventory::getItems()
{
	return this->items;
}

/**
 * .Add item to the inventory
 * 
 * \param item Item which is being added to the inventory
 */
void Inventory::addItem(Item& item)
{
	items[selectedSlot] = (item);
	item.setIsPickedUp(true);
}

/**
 * .Remove item from the inventory
 * 
 */
void Inventory::removeItem()
{
	items[selectedSlot] = Item("", 0);
}

/**
 * .Draws the inventory in zoomed state
 * 
 */
void Inventory::drawInventory()
{
	Player& player = Player::getInstance();

	int drawX = 275;
	int drawY = 200;

	for (auto i = 0; i < 3; i++)
	{
		DrawRectangle(player.getCameraPos().x + drawX, player.getCameraPos().y + drawY, 50, 50, WHITE);
		if (i == selectedSlot)
		{
			DrawRectangle(player.getCameraPos().x + drawX, player.getCameraPos().y + drawY, 50, 50, { 70,175,240,100 });
		}
		drawX += 65;
	}

	drawX = 275;

	for (auto i = 0; i < 3; i++)
	{
		DrawText(items[i].getName().c_str(), player.getCameraPos().x + drawX + 20, player.getCameraPos().y + drawY + 15, 20, RED);
		drawX += 65;
	}

	DrawText(TextFormat("%i", balance), player.getCameraPos().x + 420, player.getCameraPos().y - 260, 20, WHITE);
}

/**
 * .Draws the inventory in zoomed out state
 * 
 */
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

/**
 * .Manage the inventory slots
 * 
 */
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
