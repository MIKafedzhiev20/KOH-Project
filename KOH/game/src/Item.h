#pragma once

#include <string>
#include <vector>
#include <raylib.h>

enum item_types
{
	ELEMENT = 0,
	JUNK,
	COMBINATIONS
};

class Item
{
public:
	Item(std::string name, float buyPrice, int type, int x, int y);

	void setName(std::string name);
	std::string getName();

	void setBuyPrice(float buyPrice);
	float getBuyPrice();

	void setType(int type);
	int getType();

	void setAmount(int amount);
	int getAmount();

private:
	float buyPrice = 0.0f;

	std::string name;

	int type = 0;
	int amount = 0;

	float x = 0;
	float y = 0;
	Rectangle hitbox = {x,y,20,20};

	bool isSelected = false;

	Texture itemTexture;
};

//std::vector<Item> createItem();