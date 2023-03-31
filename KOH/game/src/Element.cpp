#include "Element.h"

Element::Element(std::string name, float buyPrice, int type, int x, int y, std::vector<std::string> reactions) 
	: 
	reactions(reactions),
	Item(name, buyPrice, type, x, y)
{

}

std::vector<std::string> Element::getReactions()
{
	return this->reactions;
}
