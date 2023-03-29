#pragma once

#include <string>

class Item
{
public:
	Item(std::string name, float buyPrice, float sellPrice, int amount);

	void setName(std::string name);
	std::string getName();

	void setBuyPrice(float buyPrice);
	float getBuyPrice();

	void setSellPrice(float sellPrice);
	float getSellPrice();

	void setAmount(int amount);
	int getAmount();

private:
	float buyPrice = 0.0f;
	float sellPrice = 0.0f;

	std::string name;

	int amount = 0;
};
