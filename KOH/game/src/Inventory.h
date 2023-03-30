#pragma once

#include "Element.h"

class Inventory
{
public:
	Inventory();

	Inventory(Inventory const&) = delete;
	void operator=(Inventory const&) = delete;

	static Inventory& getInstance();

	void setElement(std::vector<Element> elements);
	std::vector<Element> getElement();

	void setBalance(float balance);
	float getBalance();

	void drawInventory();
private:
	std::vector<Element> elements = createItem();

	float balance = 500.0f;
};