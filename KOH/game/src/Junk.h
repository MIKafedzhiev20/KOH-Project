#pragma once
#include "Item.h"

class Junk : public Item
{
public:
	Junk(std::string name, float buyPrice, int type, int x, int y, std::string contains);

	std::string getContains();
private:
	std::string contains;
};
