#include "item.h"
using namespace std;

//initializes the item with attributes
Item::Item( string name, double price, int calories) : name(name), price(price), calories(calories) {}
//makes functions to get attributes
string Item::returnName() const
{
    return name;
}

double Item::returnPrice() const
{
    return price;
}

int Item::returnCalories() const
{
    return calories;
}

Item::~Item() {}

//initializes the appetiser with the attributes
Appetiser::Appetiser(string name, double price, int calories, bool shareable, bool twoForOne) : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}
//makes functions to get attributes
bool Appetiser::returnShareable() const
{
    return shareable;
}
bool Appetiser::returnTwoForOne() const
{
    return twoForOne;
}

//initialzes the main course item with the required attributes
MainCourse::MainCourse( string name, double price, int calories) : Item(name, price, calories) {}

//initializes beverage item with the required attributes
Beverage::Beverage(string name, double price, int calories, double abv, int volume) : Item(name, price, calories), abv(abv), volume(volume) {}
//makes functions to get attributes
double Beverage::returnAbv() const
{
    return abv;
}

int Beverage::returnVolume() const
{
    return volume;
}