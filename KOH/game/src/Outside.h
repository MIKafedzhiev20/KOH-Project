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

	std::vector<Rectangle> walls =
	{	{0, 0, 1920, 40},
		{0, 0, 40, 1080},
		{0, 1040, 1920, 40},
		{1880, 0, 40, 1080}
		
	};
private:

	Texture2D outsideTexture;

	std::vector<Junk> types = createJunk();
};

