#pragma once
#include "Item.h"

class Element : public Item
{
public:
	Element(std::string name, int type, int price);

	void setIsUnlocked(bool isUnlocked);
	bool getIsUnlocked();

	void setPrice(int price);
	int getPrice();

	static std::vector<Element>& createElement();

private:
	bool isUnlocked = false;

	int price = 0;
};


static std::vector<Element>& elements = Element::createElement();
