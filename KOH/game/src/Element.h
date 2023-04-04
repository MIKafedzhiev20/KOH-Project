#pragma once
#include "Item.h"

class Element : public Item
{
public:
	// Constructor
	Element(std::string name, int type, int price, std::string texture);

	// Setters and getters
	void setIsUnlocked(bool isUnlocked);
	bool getIsUnlocked();

	void setPrice(int price);
	int getPrice();

	static std::vector<Element>& createElement();
private:
	bool isUnlocked = false;

	int price = 0;

	Texture2D elementTexture;
};

extern std::vector<Element> elements;

