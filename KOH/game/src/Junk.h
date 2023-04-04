#pragma once
#include "Item.h"

class Junk : public Item
{
public:
	// Constructor
	Junk(std::string name, int type, std::string texture);

	// Setters and getters
	void setSpawnTimer(float spawnTimer);
	float getSpawnTimer();
	
	void setLifeTimer(float lifeTimer);
	float getLifetimer();

	void setPosition(Vector2 position);
	Vector2 getPosition();

	// Public functions
	void DrawJunk(Vector2 position);
private:

	float junkSpawnTimer = GetRandomValue(50, 300);

	float junkLifetime = GetRandomValue(10000, 30000);

	Vector2 position;

	Texture2D junkTexture;
};

std::vector<Junk> createJunk();