#include "Junk.h"
#include <csv.h>

Junk::Junk(std::string name, int type, std::string contains)
	:
	contains(contains),
	Item(name, type)
{

}

std::vector<Junk> createJunk()
{
	std::vector<Junk> junk;

	io::CSVReader<2> in("assets/Junk.txt");
	in.read_header(io::ignore_extra_column, "name", "contains");

	std::string name;
	std::string contains;

	while (in.read_row(name, contains))
	{
		junk.push_back(Junk(name, 1, contains));
	}

	return junk;
}

void Junk::DrawJunk()
{
	if (this->isPickedUp == false && this->junkLifetime >= 0)
	{
		DrawRectangleRec(this->getHitbox(), GRAY);
		this->junkLifetime--;
	}
}

std::string Junk::getContains()
{
	return this->contains;
}

void Junk::setIsPickedUp(bool isPickedUp)
{
	this->isPickedUp = isPickedUp;
}

bool Junk::getIsPickedUp()
{
	return this->isPickedUp;
}

void Junk::setSpawnTimer(float spawnTimer)
{
	this->junkSpawnTimer = spawnTimer;
}

float Junk::getSpawnTimer()
{
	return this->junkSpawnTimer;
}

void Junk::setLifeTimer(float lifeTimer)
{
	this->junkLifetime = lifeTimer;
}

float Junk::getLifetimer()
{
	return this->junkLifetime;
}
