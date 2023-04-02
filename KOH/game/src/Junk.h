#pragma once
#include "Item.h"

class Junk : public Item
{
public:
	Junk(std::string name, int type, std::string contains);

	std::string getContains();

	void setSpawnTimer(float spawnTimer);
	float getSpawnTimer();
	
	void setLifeTimer(float lifeTimer);
	float getLifetimer();

	void DrawJunk();
private:
	std::string contains = "";

	float junkSpawnTimer = GetRandomValue(500, 3000);

	float junkLifetime = GetRandomValue(10000, 50000);
};

std::vector<Junk> createJunk();