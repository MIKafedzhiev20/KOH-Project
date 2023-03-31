#pragma once
#include "Item.h"

class Element : public Item
{
public:
	Element(std::string name, float buyPrice, int type, int x, int y, std::vector<std::string> reactions);

	std::vector<std::string> getReactions();
private:
	std::vector<std::string> reactions;
};