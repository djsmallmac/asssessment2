#pragma once
#include <string>
using namespace std;
class Item
{
public:
	Item(string name, double price, int calories);
	virtual ~Item();

	string returnName() const;
	double returnPrice() const;
	int returnCalories() const;

private:
	string name;
	double price;
	int calories;
};

class Appetiser : public Item
{
public:
	Appetiser(string name, double price, int calories, bool shareable, bool twoForOne);
	bool returnShareable() const;
	bool returnTwoForOne() const;
private:
	bool shareable;
	bool twoForOne;
};

class Main : public Item
{
public:
	Main(string name, double price, int calories);
};

class Beverage : public Item
{
public:
	Beverage(string name, double price, int calories, double abv, int volume);
	double returnAbv() const;
	int returnVolume() const;
private:
	double abv;
	int volume;
};

