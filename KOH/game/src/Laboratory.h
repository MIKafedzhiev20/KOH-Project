#pragma once
#include <raylib.h>
#include "Element.h"
#include "Inventory.h"

class Laboratory
{
public:
	Laboratory();
	~Laboratory();

	void DrawLaboratory();
private:
	Texture2D laboratoryTexture;

	bool isOnTable = false;
	bool isInStorage = false;
};
