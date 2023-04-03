#include "Element.h"
#include <csv.h>

#include <iostream>

Element::Element(std::string name, int type, int price) 
	:
	price(price),
	Item(name,type)
{

}

void Element::setIsUnlocked(bool isUnlocked)
{
	this->isUnlocked = isUnlocked;
}

bool Element::getIsUnlocked()
{
	return this->isUnlocked;
}

void Element::setPrice(int price)
{
	this->price = price;
}

int Element::getPrice()
{
	return this->price;
}

std::vector<Element>& Element::createElement()
{
	static std::vector<Element> element;

	io::CSVReader<2> in("../assets/Element.txt");
	in.read_header(io::ignore_extra_column, "name", "price");

	std::string name;
	int price;

	while (in.read_row(name, price))
	{
		element.push_back(Element(name, 1, price));
	}

	return element;
}
