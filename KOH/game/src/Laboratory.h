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
	bool isOnExtractor = false;
};