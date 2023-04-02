#include "Element.h"
#include <csv.h>

#include <iostream>

Element::Element(std::string name, int type) 
	: 
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

std::vector<Element> createElement()
{
	std::vector<Element> element;

	io::CSVReader<1> in("assets/Element.txt");
	in.read_header(io::ignore_extra_column, "name");

	std::string name;

	while (in.read_row(name))
	{
		element.push_back(Element(name, 1));
	}

	return element;
}
