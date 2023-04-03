#pragma once
#include "raylib.h"

class House
{
public:
	// Constructor / Destructor 
	House();
	~House();

	// Public
	void drawHouse();
private:
	Texture2D houseTexture;

	bool isOnLaptop = false;
};
