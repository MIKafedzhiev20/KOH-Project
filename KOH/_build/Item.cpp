#include "Item.h"

Item::Item(std::string name, float buyPrice, float sellPrice, int amount)
	:
	name(name),
	buyPrice(buyPrice),
	sellPrice(sellPrice),
	amount(amount)
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

void Item::setBuyPrice(float buyPrice)
{
	this->buyPrice = buyPrice;
}

float Item::getBuyPrice()
{
	return this->buyPrice;
}

void Item::setSellPrice(float sellPrice)
{
	this->sellPrice = buyPrice;
}

float Item::getSellPrice()
{
	return this->sellPrice;
}

void Item::setAmount(int amount)
{
	this->amount = amount;
}

int Item::getAmount()
{
	return this->amount;
}
