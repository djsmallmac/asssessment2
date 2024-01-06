#pragma once
#include "ItemList.hpp"
#include <vector>


class Menu 
{
public:
	Menu(string filepath);
	~Menu();

	void DisplayFile(string& filepath);
	void createVector(string& filepath);
	void itemSelect(int & userchoice);


vector<string> itemsOnList;
};

