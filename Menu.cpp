#include "Menu.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

Menu::Menu(string filepath) {

    ifstream file(filepath);
    //checks if the the file is opened if not outputs an error
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filepath << endl;
        return;
    }

    //sets an empty variable
    string line = "";

    while (getline(file, line)) 
    {
        //sets a bunch of variables to be overidden
        char itemtype = 'O';
        string name = "";
        double price = 0.0;
        int calories = 0;
        bool shareable = false;
        bool notTwoForOne = false;
        double abv = 0.0;
        int volume = 0;

        int counter = 0;
        string value = "";
        for (int i = 0; i <= line.size() - 1; i++) {
            //if a comma is detected it proceeds wit hthe following code
            if (line[i] == ',' || i >= line.size() - 1) {
                //if the counter is zero it overwrittes the pre defined itemtype value
                if (counter == 0)
                {
                
                    itemtype = value[0];
                    //resets the value of value
                    value = "";
                }
                //if the counter is one it overwrittes the pre defined name value 
                else if (counter == 1)
                {
                
                    name = value;
                    value = "";
                }
                //if the counter is two it overwrittes the pre defined price value
                else if (counter == 2)
                {
                 
                    price = atof(value.c_str());
                    value = "";
                }
                //if the counter is three it overwrittes the pre defined calories value
                else if (counter == 3)
                {
                   
                    calories = atoi(value.c_str()); 
                    value = "";
                }
                //if the counter is four it overwrittes the pre defined shareable value
                else if (counter == 4)
                {
                    if (value == "y")
                    {
                        shareable = true;
                        value = "";
                    } 
                }
                //if the counter is five it overwrittes the pre defined two for one value
                else if (counter == 5)
                {
                    if (value == "n")
                    {
                        notTwoForOne = true;
                        value = "";
                    }
                }
                //if the counter is six it overwrittes the pre defined volume value
                else if (counter == 6)
                {
                    volume = atoi(value.c_str());
                    value = "";
                }
                //if the counter is seven it overwrittes the pre defined alcohol value
                else if (counter == 7)
                {
                    abv = atof(value.c_str());
                    value = "";
                }
                //updates the counter
                counter += 1;
            }
            else
            {
                //adds to the line
                value += line[i];
            }
            
        }
        
        //if the item is an appetiser it initializes a new appetiser class with the inputted variables
        if (itemtype == 'a')
        {
            itemsOnList.push_back(new Appetiser(name, price, calories, shareable, notTwoForOne));
        }
        //if the item is an main course it initializes a new main course class with the inputted variables
        else if (itemtype == 'm')
        {
            itemsOnList.push_back(new MainCourse(name, price, calories));
        }
        //if the item is an beverage it initializes a new beverage class with the inputted variables
        else if (itemtype == 'b')
        {
            itemsOnList.push_back(new Beverage(name, price, calories, abv, volume));
        }

        

    }
    
}


Menu::~Menu() {}

//This outputs the menu to the terminal
void Menu :: toString(string& filepath)
{
    ifstream file(filepath);
    string line;
    cout << "This is the menu: " << endl;
    cout << "type,   name,price,  calories, shareable, 2-4-1,    volume, abv" << endl;
    //goes through the file and outputs it to the terminal
    while (getline(file, line)) {
        istringstream ss(line);
        string field;

        while (getline(ss, field, ',')) {
           cout << field << "\t";
        }

       cout << endl;
    }

    file.close();
}




