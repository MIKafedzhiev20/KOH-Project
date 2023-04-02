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

	float junkSpawnTimer = GetRandomValue(300, 700);
	float junkLifetime = GetRandomValue(100, 400);
};

std::vector<Junk> createJunk();