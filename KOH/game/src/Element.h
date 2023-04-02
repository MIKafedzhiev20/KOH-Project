#pragma once
#include "Item.h"

class Element : public Item
{
public:
	Element(std::string name, int type, std::vector<std::string> reactions);

	std::vector<std::string> getReactions();
private:
	std::vector<std::string> reactions;
};