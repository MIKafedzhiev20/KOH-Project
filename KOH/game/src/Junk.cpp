#include "Junk.h"
#include <csv.h>

/**
 * .Create instance of Junk
 *
 * \param name the name of the junk
 * \param type the item's type
 * \param contains the element the junk contains
 */
Junk::Junk(std::string name, int type, std::string texture)
	:
	Item(name, type)
{
	junkTexture = LoadTexture(texture.c_str());
	setTexture(junkTexture);
}

/**
 * .Create vector of junk from a file
 *
 * \return vector of junk
 */
std::vector<Junk> createJunk()
{
	std::vector<Junk> junk;

	io::CSVReader<2> in("../assets/Junk.txt");
	in.read_header(io::ignore_extra_column, "name", "textureName");

	std::string name;
	std::string texture;

	while (in.read_row(name, texture))
	{
		junk.push_back(Junk(name, 1, texture));
	}

	return junk;
}

/**
 * .Draw the junk
 *
 */
void Junk::DrawJunk(Vector2 position)
{
	if (this->getIsPickedUp() == false && this->junkLifetime >= 0)
	{
		DrawTexture(this->junkTexture, this->position.x, this->position.y, WHITE);

		this->junkLifetime--;
	}
}

/**
 * .Set the spawn the spawn timer to a given one
 *
 * \param spawnTimer the spwan timer
 */
void Junk::setSpawnTimer(float spawnTimer)
{
	this->junkSpawnTimer = spawnTimer;
}

/**
 * .Return the spwan timer of the junk
 *
 * \return the spwan timer
 */
float Junk::getSpawnTimer()
{
	return this->junkSpawnTimer;
}

/**
 * .Sets the life timer to a new value
 *
 * \param lifeTimer the new life timer
 */
void Junk::setLifeTimer(float lifeTimer)
{
	this->junkLifetime = lifeTimer;
}

/**
 * .Return the life timer
 *
 * \return the life timer
 */
float Junk::getLifetimer()
{
	return this->junkLifetime;
}

void Junk::setPosition(Vector2 position)
{
	this->position = position;
}

Vector2 Junk::getPosition()
{
	return this->position;
}
