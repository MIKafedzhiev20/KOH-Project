#include "Element.h"
#include <csv.h>

Element::Element(std::string name, float buyPrice)
	:
	name(name),
	buyPrice(buyPrice)
{

}

std::vector<Element> createItem()
{
	std::vector<Element> elements;

	io::CSVReader<2> in("../assets/Elements.txt");
	in.read_header(io::ignore_extra_column, "name", "price");

	std::string name;
	float price;

	while (in.read_row(name, price))
	{
		elements.push_back(Element(name, price));
	}

	return elements;
}

void Element::setName(std::string name)
{
	this->name = name;
}

std::string Element::getName()
{
	return this->name;
}

void Element::setBuyPrice(float buyPrice)
{
	this->buyPrice = buyPrice;
}

float Element::getBuyPrice()
{
	return this->buyPrice;
}

void Element::setAmount(int amount)
{
	this->amount = amount;
}

int Element::getAmount()
{
	return this->amount;
}