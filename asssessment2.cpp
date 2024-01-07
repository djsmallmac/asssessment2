// asssessment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"
#include "Order.h"
using namespace std;

int main()
{
	Menu menu("C:\\Users\\riosm\\Downloads\\menu.csv");
	Order order;

	while (true)
	{


		int user_input;
		string filepath = "C:\\Users\\riosm\\Downloads\\menu.csv";
		

		while (true)
		{
			cout << "Choose an option from the list: \n";
			//outputting to the user the options
			cout << "1. Display menu \n";
			cout << "2. Add item to your order \n";
			cout << "3. Remove item from your order \n";
			cout << "4. Checkout your order \n";
			cout << "5. Display a help menu \n";
			cout << "6. Exit program \n";
			cin >> user_input;

			if (user_input == 1)
			{
				menu.DisplayFile(filepath);
			}

			else if (user_input == 2)
			{
				int userChoice;
				cout << "what is the value of the item you would like to add" << endl;
				cin >> userChoice;
				if (userChoice >= 0 && userChoice < menu.itemsOnList.size()) {
					// Using the at() member function to retrieve the value from the vector
				cout << userChoice << " is " << menu.itemsOnList[userChoice - 1]->returnName() << endl;
					//this sets the chosen item variable to the value from the menu vector
					Item* chosenItem = menu.itemsOnList.at(userChoice - 1);
					//this then adds it to the ordered items vector
					order.addItem(chosenItem);
				}
				else {
					cout << "item selection out of bounds" << endl;
				}
				
			}

			else if (user_input == 3)
			{
				int removeChoice;
				cout << "enter which item from the order you want to remove: ";
				cin >> removeChoice;
				
				order.removeItem(removeChoice);
			}

			else if (user_input == 4)
			{
				for (size_t i = 0; i < order.orderedItems.size(); ++i) {
					cout << "Your order contains: " << order.orderedItems[i]->returnName() << "£" << order.orderedItems[i]->returnPrice() << endl;
				}
				cout << "Your total price is: " << order.calculateTotal() << endl;
				string userChoice;
				cout << "Would you like to pay for your order? yes or no " << endl;
				cin >> userChoice;
				if (userChoice == "yes")
				{
					cout << "Thank you for dining with us today!" << endl;
					order.createReceipt();
					return 0;
				}
				
			}
			else if (user_input == 5)
			{
				cout << "Help menu \n";
				cout << "Menu help - the index number of the item is used to display which item is which. To add an item to your order you will have to use this index number to specify which item this is.\n ";
				break;
			}
			else if (user_input == 6)
			{
				cout << "Exiting the program \n";
				return 0;
			}
			else
			{
				cout << "Invalid input, try again \n";
			}
		}
	}

	return 0;
}


