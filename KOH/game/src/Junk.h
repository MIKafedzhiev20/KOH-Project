#pragma once
#include "Item.h"

class Junk : public Item
{
public:
	// Constructor
	Junk(std::string name, int type, std::string contains);

	// Setters and getters
	std::string getContains();

	void setSpawnTimer(float spawnTimer);
	float getSpawnTimer();
	
	void setLifeTimer(float lifeTimer);
	float getLifetimer();

	// Public functions
	void DrawJunk();
private:
	std::string contains = "";

	float junkSpawnTimer = GetRandomValue(50, 300);

	float junkLifetime = GetRandomValue(10000, 50000);
};

std::vector<Junk> createJunk();