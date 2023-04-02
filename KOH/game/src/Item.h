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
	Item(std::string name, int type);

	void setName(std::string name);
	std::string getName();

	void setType(int type);
	int getType();

	void setAmount(int amount);
	int getAmount();

	void setHitbox(float x, float y);
	Rectangle getHitbox();

private:
	std::string name;

	int type = 0;
	int amount = 0;

	float x = 0;
	float y = 0;
	Rectangle hitbox = { x,y,20,20 };

	bool isSelected = false;

	Texture itemTexture;
};