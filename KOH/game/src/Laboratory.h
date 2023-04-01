#pragma once
#include <raylib.h>

class Laboratory
{
public:
	Laboratory();
	~Laboratory();

	void DrawLaboratory();
private:
	Texture2D laboratoryTexture;

	bool isOnTable = false;
};
