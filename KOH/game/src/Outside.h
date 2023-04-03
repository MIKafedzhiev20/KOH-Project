#pragma once
#include "raylib.h"
#include "Junk.h"
#include "Element.h"

class Outside
{
public:
	// Constructor / Destructor
	Outside();
	~Outside();

	// Public functions
	void DrawOutside();
	void generateJunk();
private:

	Texture2D outsideTexture;

	std::vector<Junk> types = createJunk();
};

