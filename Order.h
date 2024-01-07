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
	void addItem(Item* item);

	void removeItem(int choice);

	double calculateTotal();

	void createReceipt();

	vector<Item*> orderedItems;

};

