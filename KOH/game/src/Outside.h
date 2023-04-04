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
		{1880, 0, 40, 1080},
		{0, 350, 650, 20},
		{620, 0, 20, 340},
		{1280, 0, 20, 350},
		{1280, 340, 600, 20},
		{0, 720, 620, 20},
		{620, 720, 20, 340},
		
	};
private:

	Texture2D outsideTexture;

	std::vector<Junk> types = createJunk();
};

