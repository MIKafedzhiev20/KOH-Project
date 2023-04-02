#pragma once
#include "Item.h"

class Element : public Item
{
public:
	Element(std::string name, int type);

	void setIsUnlocked(bool isUnlocked);
	bool getIsUnlocked();
private:
	bool isUnlocked = false;
};

std::vector<Element> createElement();
static std::vector<Element> elements = createElement();
