#pragma once
#include <raylib.h>

class Laboratory
{
public:
	Laboratory();
	~Laboratory();

	void DrawLaboratory();

	bool isOnTable = false;

private:

	Texture2D laboratoryTexture;
};
