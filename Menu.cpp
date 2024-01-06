#include "Menu.h"
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

void Menu::createVector(string& filepath)
{
    ifstream file(filepath);
    string line;
    while (getline(file, line)) {
        // Use a stringstream to parse each comma-separated value
        istringstream iss(line);
        string value;

        while (getline(iss, value, ',')) {
            // Add the string value to the vector
            itemsOnList.push_back(value);
        }
        }
    file.close();

    // Print the values in the vector
    //for (const std::string& val : itemsOnList) {
        //std::cout << val << " ";
    //}
    }

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



