#pragma once
#include <raylib.h>
#include <vector>

class Shop
{
public:
	// Constructor / Desturctor
	Shop();
	~Shop();

	std::vector<Rectangle> walls =
	{   {0, 0, 640, 20},
		{0, 0, 20, 340},
		{0, 320, 640, 20},
		{620, 0, 20, 340}
	};

	// Public functions
	void drawTexture();
private:
	Texture2D shopTexture;

	bool isOnCheckout = false;
};
