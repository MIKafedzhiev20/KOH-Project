#include "Item.h"

Item::Item(std::string name, int type)
	:
	name(name),
	type(type)
{
}

void Item::setName(std::string name)
{
	this->name = name;
}

std::string Item::getName()
{
	return this->name;
}

void Item::setType(int type)
{
	this->type = type;
}

int Item::getType()
{
	return this->type;
}

void Item::setAmount(int amount)
{
	this->amount = amount;
}

int Item::getAmount()
{
	return this->amount;
}

void Item::setHitbox(float x, float y)
{
	this->hitbox = { x,y,20,20 };
}

Rectangle Item::getHitbox()
{
	return this->hitbox;
}
