#include "Order.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


//initializes the order class
Order::Order() {}
//destructor of the order class
Order::~Order() {}

//This function adds an item to the list that holds all items the user has ordered
void Order::addItem(Item* item)
{
	//this adds the item the user has selected to the end of the list
	orderedItems.push_back(item);
	//outputs to the user a message to show what is held in the order after the user has added their item
	cout << "Your order contains: " << endl;
	for (size_t i = 0; i < orderedItems.size(); ++i) {
		cout << orderedItems[i]->returnName() << " $" << orderedItems[i]->returnPrice() << endl;
	}
}


//This function removes the specified item from the ordered list 
void Order::removeItem(int choice)
{

	//This checks if the order is in the boundaries
	if (choice > 0 && choice <= orderedItems.size())
	{
		//if so it removes the item from the specified position
		orderedItems.erase(orderedItems.begin() + choice - 1);
		//outputs a message to the user showing the new values of the list
		cout << "Your order contains: " << endl;
		for (size_t i = 0; i < orderedItems.size(); ++i) {
			cout << orderedItems[i]->returnName() << endl;
		}
	}
	else
	{
		//if the number chosen by the user is out of bounds this message will be shown to the user
		cout << "invalid input item not apart of list";
	}
}

//This function is used to calculate the final total
double Order::calculateTotal()
{
	//this variable holds the total price of the order
	double totalPrice = 0.0;
	//this variable checks how many two for ones are inside of the meal
	int ifTwoForOne = 0;
	//this goes through the items on the list
	for (const auto& item : orderedItems) {
		//this adds every items price value to the total price
		totalPrice += item->returnPrice();
		//this checks if the item currently selected is an appetiser and if the value stores is a two for one
		if (item->foodType() == 'a' &&  dynamic_cast<Appetiser*>(item)->returnTwoForOne() == false)
		{
			//it adds one to the two for one counter
			ifTwoForOne++;
			//this checks if the two for one is an even value if it is so it will add the price of an item to the discount
			if (ifTwoForOne % 2 == 0)
			{
				discount += item->returnPrice();

			}
		}
	}
	//if there is more than two two for ones it will subtract the discount from the toal price
	if (ifTwoForOne >= 2)
	{
		totalPrice -= discount;
	}
	//returns the total price calculated
	return totalPrice;
}

//This function creates a recipt file
void Order::createReceipt()
{
	ofstream MyFile;
	MyFile.open("Receipt.txt");
	//this checks if the file opens if it doesnt it outputs a message
	if (MyFile.fail())
	{
		cout << "File failed to open" << endl;
	}
	//calls the toString function and closes the file
	else
	{
		MyFile << toString();

		MyFile.close();
	}

}//this function is used to reciept
string Order::toString() const
{	//this holds eveything ineed to put out in a stream
	stringstream result;
	//saves to the stream a message that needs to be outputted
	result << "Your order: " << endl;
	//variables needed to output the correct price and such
	double totalPrice = 0.0;
	double moneyOff =0.0;
	int ifTwoForOne = 0;
	//goes through every item in the vector and adds the price up factoring in discount
	for (const auto& item : orderedItems) {
		totalPrice += item->returnPrice();
		if (item->foodType() == 'a' && dynamic_cast<Appetiser*>(item)->returnTwoForOne() == false)
		{
			ifTwoForOne++;
			if (ifTwoForOne % 2 == 0)
			{
				moneyOff += item->returnPrice();

			}
		}
	}
	//if statement for if there is a discount
	if (ifTwoForOne >= 2)
	{
		//This statement outputs to the user a list of what they have ordered and the price and savings
		totalPrice -= discount;
		for (size_t i = 0; i < orderedItems.size(); ++i) 
		{
		result << orderedItems[i]->returnName() << " $" << orderedItems[i]->returnPrice() << endl;
		}
		result << "Total: $" << totalPrice << endl;
		result << "Discount: $" << discount << endl;
	}
	//if there isnt a discount it will just output the total price and a message of no savings
	else
	{
		result << "Total: $" << totalPrice << endl;
		result << "Savings = 0" << endl;
	}

	return result.str();
}


