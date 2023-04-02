#pragma once
#include "raylib.h"
#include "Junk.h"

class Outside
{
public:
	Outside();
	~Outside();

	void DrawOutside();

	void generateJunk();
private:

	Texture2D outsideTexture;

	std::vector<Junk> types = createJunk();
};

