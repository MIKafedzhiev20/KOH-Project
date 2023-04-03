#pragma once
#include "Item.h"

class Reactions : public Item
{
public:
	// Constructor
	Reactions(std::string name, int type, std::string required1, std::string required2, int price);

	// Public functions
	static std::vector<Reactions>& createReactions();

	// Setters and getters
	void setRequired1(std::string required1);
	std::string getRequired1();

	void setRequired2(std::string required2);
	std::string getRequired2();

	void setPrice(int price);
	int getPrice();

	void setIsObtained(bool isObtained);
	bool getIsObtained();
private:
	std::string required1 = "";
	std::string required2 = "";
	std::string name = "";

	int price = 0;
	bool isObtained = false;
};

static std::vector<Reactions>& reactions = Reactions::createReactions();