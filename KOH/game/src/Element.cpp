#include "Element.h"

Element::Element(std::string name, int type, std::vector<std::string> reactions) 
	: 
	reactions(reactions),
	Item(name,type)
{

}

std::vector<std::string> Element::getReactions()
{
	return this->reactions;
}
