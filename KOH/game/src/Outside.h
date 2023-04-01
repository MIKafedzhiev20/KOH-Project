#pragma once
#include "raylib.h"

class Outside
{
public:
	Outside();
	~Outside();

	void DrawOutside();
private:

	Texture2D outsideTexture;
};

