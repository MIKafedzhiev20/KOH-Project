#include "Item.h"

/**
 * .Create instance of the item
 * 
 * \param name the name of the item
 * \param type the item's type
 */
Item::Item(std::string name, int type)
	:
	name(name),
	type(type)
{
}

/**
 * .Sets the item's name to a give one
 * 
 * \param name the new item name
 */
void Item::setName(std::string name)
{
	this->name = name;
}

/**
 * .Retruns the item's name
 * 
 * \return the item's name
 */
std::string Item::getName()
{
	return this->name;
}

/**
 * .Sets the items type to a given one
 * 
 * \param type the new item type
 */
void Item::setType(int type)
{
	this->type = type;
}

/**
 * .Returns the item's name
 * 
 * \return the item's name
 */
int Item::getType()
{
	return this->type;
}

/**
 * .Set the isPicked up status to true/false
 * 
 * \param isPickedUp true/false
 */
void Item::setIsPickedUp(bool isPickedUp)
{
	this->isPickedUp = isPickedUp;
}

/**
 * .Returns whether the items is picked up or not
 * 
 * \return true/false
 */
bool Item::getIsPickedUp()
{
	return this->isPickedUp;
}

/**
 * .Set the item's hitbox
 * 
 * \param x the x coordinate of the item
 * \param y the y coordinate of the item
 */
void Item::setHitbox(float x, float y)
{
	this->hitbox = { x,y,20,20 };
}

/**
 * .Return the item's hitbox
 * 
 * \return 
 */
Rectangle Item::getHitbox()
{
	return this->hitbox;
}
