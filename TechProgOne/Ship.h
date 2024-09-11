#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <stdexcept>
#include <string>

class Ship {
protected: 
	std::string name;
public:

	Ship();
	Ship(const std::string& name);
	Ship(const Ship& other);

	std::string getName() const;
	void setName(const std::string& name);
};
#endif // SHIP_H