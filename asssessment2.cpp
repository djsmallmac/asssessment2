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
				//this outputs the menu 
				menu.toString(filepath);
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
			//This function is used to remove items from the list
			else if (user_input == 3)
			{
				//outputs the order to the user so they can see which item is to be removed
				for (size_t i = 0; i < order.orderedItems.size(); ++i) {
					cout << (i+1) << "." << order.orderedItems[i]->returnName() << endl;
				}
				int removeChoice;
				cout << "enter which item from the order you want to remove: ";
				cin >> removeChoice;
				//calls the function which removes the item from the order
				order.removeItem(removeChoice);
			}

			else if (user_input == 4)
			{
				//outputs the order and the total cost
				cout << "Your order contains: " << endl;
				for (size_t i = 0; i < order.orderedItems.size(); ++i) {
					cout << order.orderedItems[i]->returnName() << "$" << order.orderedItems[i]->returnPrice() << endl;
				}
				cout << "Your total price is: " << order.calculateTotal() << endl;
				cout << "Your total savings is: $" << order.discount << endl;
				string userChoice;
				//asks the user if they want to checkout their order
				cout << "Would you like to pay for your order? yes or no " << endl;
				cin >> userChoice;
				if (userChoice == "yes")
				{
					cout << "Thank you for dining with us today!" << endl;
					//calls the function which creates a reciept
					order.createReceipt();
					return 0;
				}
				
			}
			//this outputs a help menu to the terminal
			else if (user_input == 5)
			{
				cout << "Help menu \n";
				cout << "Option one in the menu provides to the user a view of the menu " << endl;
				cout << "Option two in the menu allows the user to add an item to the menu using the corresponding index inside of the menu" << endl;
				cout << "Option three in the menu allows the user to remove an item from the selected items using the correponding index number \ninside of the ordered items" << endl;
				cout << "Option four provides the user their order total and discount if applicable and asks the user if they want to checkout" << endl;
				cout << "Option five displays the user this ... did you really need to know that" << endl;
				cout << "Option six exits the program" << endl;
				break;
			}
			//this exits the program
			else if (user_input == 6)
			{
				cout << "Exiting the program \n";
				return 0;
			}
			//error catch
			else
			{
				cout << "Invalid input, try again \n";
			}
		}
	}

	return 0;
}


