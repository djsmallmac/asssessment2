#pragma once
#include "ItemList.hpp"
#include <vector>

class Item;

class Menu 
{
public:
	Menu(std::string filepath);
	~Menu();

	void DisplayFile(string& filepath);
	//void createVector(string filepath);
	void itemSelect(int & userchoice);

	vector<Item*> itemsOnList;
};

