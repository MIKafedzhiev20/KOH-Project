#pragma once
#include "Item.h"

class Element : public Item
{
public:
	// Constructor
	Element(std::string name, int type, int price);

	// Setters and getters
	void setIsUnlocked(bool isUnlocked);
	bool getIsUnlocked();

	void setPrice(int price);
	int getPrice();

	// Public functions
	static std::vector<Element>& createElement();

private:
	bool isUnlocked = true;

	int price = 0;
};


static std::vector<Element>& elements = Element::createElement();
