#pragma once
#include <raylib.h>

class Shop
{
public:
	Shop();
	~Shop();

	void drawTexture();
private:
	Texture2D shopTexture;

	bool isOnCheckout = false;
};
