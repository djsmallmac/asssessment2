#include "Order.h"
#include <iostream>
#include <fstream>

using namespace std;



Order::Order(){}

Order::~Order() {}

void Order::addItem(string item)
{
	orderedItems.push_back(item);
	cout << "Your order contains: " << endl;
	for (string value : orderedItems) {
		cout << value << " " << endl;
	}
}



void Order::removeItem(int choice)
{


	if (choice > 0 && choice <= orderedItems.size())
	{
		orderedItems.erase(orderedItems.begin() + choice - 1);
	}
	else
	{
		cout << "invalid input item not apart of list";
	}
}

double Order::calculateTotal()
{
	double totalPrice = 0.0;
	//for (const auto& items : orderedItems) {
		//totalPrice += myItem.returnPrice();
	//}

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


