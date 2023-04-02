#pragma once

#include "Element.h"

class Inventory
{
public:
	Inventory();

	Inventory(Inventory const&) = delete;
	void operator=(Inventory const&) = delete;

	static Inventory& getInstance();

	void setBalance(float balance);
	float getBalance();

	void setSelectedSlot(unsigned slot);
	unsigned getSelectedSlot();

	void drawInventory();
	void DrawInStorage();

	void manageInvetory();

	void addItem(Item& item);
	void removeItem(const unsigned index);

private:
	std::vector<Item> items = {Item("", 0),Item("", 0),Item("", 0) };
	unsigned slots = 3;
	unsigned filledSlots = 0;
	unsigned selectedSlot = 0;


	float balance = 500.0f;
};