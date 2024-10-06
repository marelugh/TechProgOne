#ifndef SUBMARINE_H
#define SUBMARINE_H
#include "Ship.h"
#include <iostream>

class Submarine : public Ship {
private:
	double length;
	double width;
	char** crew;
	int crewSize;
	int underwaterTime;
	int underwaterSpeed;
	char** ammo;
	int ammoAmount;

public:
	Submarine();
	Submarine(double length, double width, const char** crew, int crewSize, int underwaterTime, int underwaterSpeed, const char** ammo, int ammoAmount);
	Submarine(const Submarine& other);
	~Submarine();

	double getLength() const;
	void setLength(double length);

	double getWidth() const;
	void setWidth(double width);

	char** getCrew() const;
	int getCrewSize() const;
	void setCrew(const char** crew, int crewSize);

	int getUnderwaterTime() const;
	void setUnderwaterTime(int underwaterTime);

	int getUnderwaterSpeed() const;
	void setUnderwaterSpeed(int underwaterSpeed);

	char** getAmmo() const;
	int getAmmoAmount() const;
	void setAmmo(const char** ammo, int ammoAmount);
};


#endif // !SUBMARINE_H

