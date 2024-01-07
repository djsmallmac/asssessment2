#include "Menu.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

Menu::Menu(std::string filepath) {

    ifstream file(filepath);
    //checks if the program can access the file, if not, throw out this error
    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filepath << endl;
        return;
    }

    
    string line = "";

    while (std::getline(file, line)) {
        char itemtype = 'O';
        std::string name = "";
        double price = 0.0;
        int calories = 0;
        bool shareable = false;
        bool twoForOne = false;
        double abv = 0.0;
        int volume = 0;

        int counter = 0;
        std::string value = "";
        for (int i = 0; i <= line.size() - 1; i++) {
            if (line[i] == ',' || i >= line.size() - 1) {
                if (counter == 0)
                {
                
                    itemtype = value[0];
                    value = "";
                }
                else if (counter == 1)
                {
                
                    name = value;
                    value = "";
                }
                else if (counter == 2)
                {
                 
                    price = atof(value.c_str());
                    value = "";
                }
                else if (counter == 3)
                {
                   
                    calories = atoi(value.c_str()); 
                    value = "";
                }
                else if (counter == 4)
                {
                    if (value == "y")
                    {
                        shareable = true;
                        value = "";
                    } 
                }
                else if (counter == 5)
                {
                    if (value == "y")
                    {

                        twoForOne = true;
                        value = "";
                    } 

                }
                else if (counter == 6)
                {
                    volume = atoi(value.c_str());
                    value = "";
                }
                else if (counter == 7)
                {
                    abv = atof(value.c_str());
                    value = "";
                }
                counter += 1;
            }
            else
            {
                value += line[i];
            }
            
        }
        

        if (itemtype == 'a')
        {
            itemsOnList.push_back(new Appetiser(name, price, calories, shareable, twoForOne));
        }
        else if (itemtype == 'm')
        {
            itemsOnList.push_back(new Main(name, price, calories));
        }
        else if (itemtype == 'b')
        {
            itemsOnList.push_back(new Beverage(name, price, calories, abv, volume));
        }

        

    }
    
}


Menu::~Menu() {}

void Menu :: DisplayFile(string& filepath)
{
    ifstream file(filepath);
    string line;
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


//void Menu::createVector(string& filepath)
//{
    //ifstream file(filepath);
    //string line;
    //while (getline(file, line)) {
        // Use a stringstream to parse each comma-separated value
        //istringstream iss(line);
        //string value;

        //while (getline(iss, value, ',')) {
            // Add the string value to the vector
            //itemsOnList.push_back(value);
        //}
        //}
    //file.close();

    // Print the values in the vector
    //for (const std::string& val : itemsOnList) {
        //std::cout << val << " ";
    //}
    //}



void Menu::itemSelect(int & userchoice)
{
    if (userchoice >= 0 && userchoice < itemsOnList.size()) {
        // Using the at() member function
        cout << "Using at(): Element at index " << userchoice << " is " << itemsOnList.at(userchoice) << endl;

    }
    else {
        cout << "item selection out of bounds" << endl;
    }
}



