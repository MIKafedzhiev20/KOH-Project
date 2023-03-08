#pragma once
#include <iostream>
#include <raylib.h>

#include "OtherFunctions.h"

class MainMenu
{
public:
	bool isMenuOpen = true;
	void DrawMenu(MainMenu& menu);
private:
};

Vector2 MousePos();