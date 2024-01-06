#include "item.h"
using namespace std;

Item::Item(std::string name, double price, int calories) : name(name), price(price), calories(calories) {}
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

Appetiser::Appetiser(string name, double price, int calories, bool shareable, bool twoForOne) : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

bool Appetiser::returnShareable() const
{
    return shareable;
}
bool Appetiser::returnTwoForOne() const
{
    return twoForOne;
}

Main::Main(string name, double price, int calories) : Item(name, price, calories) {}

Beverage::Beverage(string name, double price, int calories, double abv, int volume) : Item(name, price, calories), abv(abv), volume(volume) {}
double Beverage::returnAbv() const
{
    return abv;
}

int Beverage::returnVolume() const
{
    return volume;
}