#include "Junk.h"

Junk::Junk(std::string name, float buyPrice, int type, int x, int y, std::string contains)
	:
	contains(contains),
	Item(name, buyPrice, type, x, y)
{

}

std::string Junk::getContains()
{
	return this->contains
}
