#pragma once
#include "raylib.h"

class House
{
public:
	House();
	~House();

	void drawHouse();
private:
	Texture2D houseTexture;

	bool isOnLaptop = false;
};
