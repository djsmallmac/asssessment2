#pragma once
#include <string>
using namespace std;
class Item
{
public:
	//constuctor for item
	Item(string name, double price, int calories);
	virtual ~Item();

	//initializes functions that retrieve values
	string returnName() const;
	double returnPrice() const;
	int returnCalories() const;
	virtual char foodType() const = 0;

private:
	string name;
	double price;
	int calories;
	
	
};

class Appetiser : public Item
{
public:
	//constuctor for appetiser
	Appetiser( string name, double price, int calories, bool shareable, bool twoForOne);

	//initializes functions that retrieve values
	bool returnShareable() const;
	bool returnTwoForOne() const;
	char foodType() const override { return 'a'; }
private:
	bool shareable;
	bool twoForOne;
};

class MainCourse : public Item
{
public:
	//constuctor for maincourse
	MainCourse( string name, double price, int calories);
	char foodType() const override { return 'm'; }
};

class Beverage : public Item
{
public:
	//constuctor for beverage
	Beverage( string name, double price, int calories, double abv, int volume);
	double returnAbv() const;
	int returnVolume() const;
	char foodType() const override { return 'b'; }
private:
	double abv;
	int volume;
};

