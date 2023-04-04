#pragma once

#include <string>
#include <vector>
#include <raylib.h>

class Item
{
public:
	// Constructor
	Item(std::string name, int type);

	// Setters and getters
	void setName(std::string name);
	std::string getName();

	void setType(int type);
	int getType();

	void setIsPickedUp(bool isPickedUp);
	bool getIsPickedUp();

	void setHitbox(float x, float y);
	Rectangle getHitbox();

private:
	std::string name;

	int type = 0;

	float x = 0;
	float y = 0;
	Rectangle hitbox = { x,y,20,20 };

	bool isSelected = false;

	bool isPickedUp = false;

	Texture itemTexture;
};