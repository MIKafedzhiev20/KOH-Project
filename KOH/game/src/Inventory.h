#pragma once

#include "Element.h"

class Inventory
{
public:
	// Operators
	Inventory(Inventory const&) = delete;
	void operator=(Inventory const&) = delete;

	// Setters and getters
	void setBalance(int balance);
	int getBalance();

	void setSelectedSlot(unsigned slot);
	unsigned getSelectedSlot();

	void resetItems();
	std::vector<Item> getItems();

	// Public functions
	static Inventory& getInstance();
	void drawInventory();
	void DrawOutzoomed();

	void manageInvetory();

	void addItem(Item& item);
	void removeItem();

private:
	// Constructor
	Inventory();

	std::vector<Item> items = {Item("", 3),Item("", 3),Item("", 3) };
	unsigned slots = 3;
	unsigned selectedSlot = 0;

	int balance = 500;
};