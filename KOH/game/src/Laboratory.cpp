#include "Laboratory.h"

Laboratory::Laboratory()
{
	//laboratoryTexture = LoadTexture("assets/");
}

Laboratory::~Laboratory()
{
	UnloadTexture(laboratoryTexture);
}

void Laboratory::DrawLaboratory()
{
	DrawTexture(laboratoryTexture, 0, 0, WHITE);
}
