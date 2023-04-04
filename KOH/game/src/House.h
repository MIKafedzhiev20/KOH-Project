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

	std::vector<Rectangle> walls = 
	{   {0, 0, 650, 40},
		{0, 0, 20, 350},
		{0, 340, 630, 20},
		{630, 0, 20, 330},
		{200, 20, 20, 180},
		{380, 20, 20, 180},
		{0, 200, 120, 20},
		{200, 200, 80, 20}
	};
private:
	Texture2D houseTexture;
};