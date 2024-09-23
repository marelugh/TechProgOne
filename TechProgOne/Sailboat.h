#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"
#include <iostream>

class Sailboat : public Ship {
private:
	char* type;
	char* name;
	bool isMilitary;
	double length;
	double speed;
	char** crew;
	int crewSize;

public:

	Sailboat();
	Sailboat(const char* type, const char* name, bool isMilitary, double length, double speed, const char** crew, int crewSize);
	Sailboat(const Sailboat& other);
	~Sailboat();

	const char* getType() const;
	void setType(const char* type);

	const char* getName() const;
	void setName(const char* name);

	bool getIsMilitary() const;
	void setIsMilitary(bool isMilitary);

	double getLength() const;
	void setLength(double length);

	double getSpeed() const;
	void setSpeed(double speed);

	char** getCrew() const;
	int getCrewSize() const;
	void setCrew(const char** crew, int crewSize);
};

#endif // SAILBOAT_H