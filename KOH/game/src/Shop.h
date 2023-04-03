#pragma once
#include <raylib.h>

class Shop
{
public:
	// Constructor / Desturctor
	Shop();
	~Shop();

	// Public functions
	void drawTexture();
private:
	Texture2D shopTexture;

	bool isOnCheckout = false;
};
