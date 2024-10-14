#pragma once
#pragma once
#include "Ship.h"
#include "LinkedList.h"
#include <iostream>
#include "Submarine.h"
#include "Boat.h"
#include "Sailboat.h"
using namespace std;


class Keeper
{
private:

	LinkedList linkedList;

public:
	Keeper() {};
	~Keeper() { clearShip(); };

	void addShip(Ship* ship);
	void removeShip();
	void change();
	void printShip() const;
	void clearShip();

	void saveToFile(string filename);
	void loadFromFile(string filename);
};