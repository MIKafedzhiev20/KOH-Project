#include "Item.h"
#include <csv.h>

Item::Item(std::string name, float buyPrice, int type, int x, int y)
	:
	name(name),
	buyPrice(buyPrice),
	type(type),
	x(x),
	y(y)
{

}

//std::list<Item> createItem()
//{
//	std::list<Item> elements;
//
//	io::CSVReader<2> in("assets/Elements.txt");
//	in.read_header(io::ignore_extra_column, "name", "price");
//
//	std::string name;
//	float price;
//		
//	while (in.read_row(name, price))
//	{
//		elements.push_back(Item(name, price, 0));
//	}
//
//	return elements;
//}

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