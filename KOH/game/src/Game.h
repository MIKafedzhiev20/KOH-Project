#pragma once
#include <iostream>
#include <raylib.h>
#include <assert.h>
#include <cmath>

#include "Player.h"
#include "Map.h"
#include "Inventory.h"
#include <fstream>
#include "Reactions.h"
#include "Element.h"

using namespace std;

class Game
{
public:
	// Constructor / Destructor 
	Game(int width, int height, int fps);
	~Game() noexcept;

	// Public functions
	bool GameShouldClose() const;
	void Tick();
private:
	
	// Private functions
	void Update();
	void Draw();

	int width = 0;
	int height = 0;

	Camera2D camera = { {(float)width / 2, (float)height / 2}, {200, 200}, 0, 2 };

	Vector2 mouse = { 0,0 };

	Player& player = Player::getInstance();

	Map& map = Map::getInstance();

	MainMenu& mainMenu = MainMenu::getInstance();

	Inventory& inventory = Inventory::getInstance();


};

void LoadSavedData(ifstream& loadData);
void SaveData(ofstream& saveData);