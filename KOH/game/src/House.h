#pragma once
#include "raylib.h"
#include <vector>

class House
{
public:
	// Constructor / Destructor 
	House();
	~House();

	// Public
	void drawHouse();

	std::vector<Rectangle> walls = { {0, 0, 650, 20},
									{0, 0, 20, 350},
									{10, 345, 650, 20},
									{610, 20, 20, 350} };
private:
	Texture2D houseTexture;

	bool isOnLaptop = false;
};