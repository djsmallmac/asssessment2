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
		//outputting to the user the options
		cout << "1. Display menu \n";
		cout << "2. Add item to your order \n";
		cout << "3. Remove item from your order \n";
		cout << "4. Checkout your order \n";
		cout << "5. Display a help menu \n";
		cout << "6. Exit program \n";

		int user_input;
		string filepath = "C:\\Users\\riosm\\Downloads\\menu.csv";
		menu.createVector(filepath);

		while (true)
		{
			cout << "Choose an option from the list: ";
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
					cout << userChoice << " is " << menu.itemsOnList.at(userChoice) << endl;
					//this sets the chosen item variable to the value from the menu vector
					string chosenItem = menu.itemsOnList.at(userChoice);
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
				order.createReceipt();
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


