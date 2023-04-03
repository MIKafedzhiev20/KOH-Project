#include "Reactions.h"
#include "csv.h"

/**
 * .Create instace of Reactions
 * 
 * \param name the name of the combination
 * \param type the type of the item
 * \param required1 the first required element to make the combination
 * \param required2 the secon required element to make the combination
 * \param price the price for obtaining the combination
 */
Reactions::Reactions(std::string name, int type, std::string required1, std::string required2, int price)
	:
	required1(required1),
	required2(required2),
	price(price),
	Item(name, type)
{

}

/**
 * .Create static instance of Reactions
 * 
 * \return static instance of Reactions
 */
std::vector<Reactions>& Reactions::createReactions()
{
	static std::vector<Reactions> reaction;

	io::CSVReader<4> in("../assets/Reaction.txt");
	in.read_header(io::ignore_extra_column, "required1", "required2", "name", "price");

	std::string required1;
	std::string required2;
	std::string name;
	int price;

	while (in.read_row(required1, required2, name, price))
	{
		reaction.push_back(Reactions(name, 2, required1, required2, price));
	}

	return reaction;
}

/**
 * .Set the first required element to a new one
 * 
 * \param required1 the new element
 */
void Reactions::setRequired1(std::string required1)
{
	this->required1 = required1;
}

/**
 * .Return the first required element
 * 
 * \return the first required element
 */
std::string Reactions::getRequired1()
{
	return this->required1;
}

/**
 * .Set the first required element to a new one
 *
 * \param required2 the new element
 */
void Reactions::setRequired2(std::string required2)
{
	this->required2 = required2;
}

/**
 * .Returns the second required element
 * 
 * \return the secon required element
 */
std::string Reactions::getRequired2()
{
	return this->required2;
}

/**
 * .Set the price to a new one
 * 
 * \param price the new price
 */
void Reactions::setPrice(int price)
{
	this->price = price;
}

/**
 * .Return the price for obtaining the reaction
 * 
 * \return the price
 */
int Reactions::getPrice()
{
	return this->price;
}

/**
 * .Sets true/false if the reaction is obtained
 * 
 * \param isObtained true/false
 */
void Reactions::setIsObtained(bool isObtained)
{
	this->isObtained = isObtained;
}

/**
 * .Returns true/false if the reaction is obtained
 * 
 * \return true/false if the reaction is obtained
 */
bool Reactions::getIsObtained()
{
	return this->isObtained;
}
