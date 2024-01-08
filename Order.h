#pragma once
#include "item.h"
#include "Menu.h"
#include <vector>;

using namespace std;

 class Order
{
public:
	//constructor and destructor order
	Order(); 
	~Order();
	//function which adds an item to an item to the order
	void addItem(Item* item);
	//this function removes an item from order
	void removeItem(int choice);
	//this function calculates the total value
	double calculateTotal();
	//this function creates a receipt
	void createReceipt();
	//this is a to string function to output the values
	string toString() const;
	//this holds the value of the discount
	double discount;

	//this vector stores all items that have been ordered
	vector<Item*> orderedItems;

};

