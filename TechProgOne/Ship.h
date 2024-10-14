#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <fstream>

using namespace std;

class Ship {
public:
	virtual void print() = 0;
	virtual void input() = 0;
	virtual void saveToFile(ofstream& file);
	virtual void loadFromFile(ifstream& file);
	virtual void change();
};
#endif // SHIP_H