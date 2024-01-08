#pragma once
#include "ItemList.hpp"
#include <vector>

class Item;

class Menu
{
public:
	//menu constructor and destructor
	Menu(string filepath);
	~Menu();
	void toString(string& filepath);

	//vector that holds all values on the menu
	vector<Item*> itemsOnList;
};

