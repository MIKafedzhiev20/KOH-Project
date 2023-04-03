#include "Element.h"
#include <csv.h>

#include <iostream>

/**
 * .Create an instance of Element
 * 
 * \param name the name of the element
 * \param type the type of the item
 * \param price the price of the element
 */
Element::Element(std::string name, int type, int price) 
	:
	price(price),
	Item(name,type)
{

}

/**
 * .Sets the isUnlocked to true/false
 * 
 * \param isUnlocked Inputed true/false
 */
void Element::setIsUnlocked(bool isUnlocked)
{
	this->isUnlocked = isUnlocked;
}

/**
 * .Returns the isUnlocked value
 * 
 * \return isUnlocked
 */
bool Element::getIsUnlocked()
{
	return this->isUnlocked;
}

/**
 * .Sets tge price to a give one
 * 
 * \param price Inputed price
 */
void Element::setPrice(int price)
{
	this->price = price;
}

/**
 * .Returns the price
 * 
 * \return price
 */
int Element::getPrice()
{
	return this->price;
}

/**
 * .Creates vector of elements from file
 * 
 * \return vector of elements
 */
std::vector<Element>& Element::createElement()
{
	static std::vector<Element> element;

	io::CSVReader<2> in("../assets/Element.txt");
	in.read_header(io::ignore_extra_column, "name", "price");

	std::string name;
	int price;

	while (in.read_row(name, price))
	{
		element.push_back(Element(name, 0, price));
	}

	return element;
}
