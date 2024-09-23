#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <stdexcept>
#include <string>

class Ship {
protected: 
	std::string shipInfo;
public:

	Ship();
	Ship(const std::string& info);
	Ship(const Ship& other);
	~Ship();

	std::string getInfo() const;
	void setInfo(const std::string& name);

	virtual void displayInfo() const = 0;
};
#endif // SHIP_H