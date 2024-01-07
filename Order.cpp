#include "Order.h"
#include <iostream>
#include <fstream>

using namespace std;



Order::Order(){}

Order::~Order() {}

void Order::addItem(Item* item)
{
	orderedItems.push_back(item);
	for (size_t i = 0; i < orderedItems.size(); ++i) {
		cout << "Your order contains: " << orderedItems[i]->returnName() << "£" << orderedItems[i]->returnPrice() << endl;
	}
}



void Order::removeItem(int choice)
{


	if (choice > 0 && choice <= orderedItems.size())
	{
		orderedItems.erase(orderedItems.begin() + choice - 1);
		for (size_t i = 0; i < orderedItems.size(); ++i) {
			cout << "Your order contains: " << orderedItems[i]->returnName() << endl;
		}
	}
	else
	{
		cout << "invalid input item not apart of list";
	}
}

double Order::calculateTotal()
{
	double totalPrice = 0.0;
	for (const auto& item : orderedItems) {
		totalPrice += item->returnPrice();
	}

	return totalPrice;
}

void Order::createReceipt()
{
	ofstream MyFile;
	MyFile.open("Receipt.txt");
	if (MyFile.fail())
	{
		cout << "File failed to open" << endl;
	}
	for (auto element : orderedItems)
	{
		MyFile << element << endl;
	}
	MyFile << "total: " << calculateTotal();

	MyFile.close();
}


