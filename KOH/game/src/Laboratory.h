#pragma once
#include <raylib.h>
#include "Element.h"
#include "Inventory.h"

class Laboratory
{
public:
	// Constructor / Destructor
	Laboratory();
	~Laboratory();

	std::vector<Rectangle> walls =
	{   {0, 0, 640, 20},
		{0, 0, 20, 340},
		{0, 320, 640, 20},
		{620, 0, 20, 340}
	};

	// Public functions
	void DrawLaboratory();

private:
	// Private functions
	void DrawTable();
	void DrawStorage();
	void DrawExtractor();

	Texture2D laboratoryTexture;
	Texture2D table;

	bool isOnTable = false;
	bool isInStorage = false;
};