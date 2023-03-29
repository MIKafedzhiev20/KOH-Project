#pragma once

#include <string>
#include <vector>

class Element
{
public:
	Element(std::string name, float buyPrice);

	void setName(std::string name);
	std::string getName();

	void setBuyPrice(float buyPrice);
	float getBuyPrice();

	void setAmount(int amount);
	int getAmount();

private:
	float buyPrice = 0.0f;

	std::string name;

	int amount = 0;

	bool isSelected = false;
};

std::vector<Element> createItem();