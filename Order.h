#pragma once
#include "item.h"
#include "Menu.h"
#include <vector>;

using namespace std;

 class Order
{
public:
	Order();
	~Order();
	void addItem(string item);

	void removeItem(int choice);

	double calculateTotal();

	void createReceipt();

	vector<string> orderedItems;

};

