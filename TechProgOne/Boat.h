#ifndef BOAT_H
#define BOAT_H
#include "Ship.h"
#include<iostream>

class Boat : public Ship {
private:
	char* purpose;
	char* material;
	int speed;
	int amountOfPeople;
	char** qualities;
	int amountOfQualities;
public:
	Boat();
	Boat(const char* purpose, const char* material, int speed, int amountOfPeople, const char** qualities, int amountOfQualities);
	Boat(const Boat& other);
	~Boat();

	const char* getPurpose() const;
	void setPurpose(const char* purpose);

	const char* getMaterial() const;
	void setMaterial(const char* material);

	int getSpeed() const;
	void setSpeed(int speed);

	int getAmountOfPeople() const;
	void setAmountOfPeople(int amountOfPeople);

	char** getQualities() const;
	int getAmountOfQualities() const;
	void setQualities(const char** qualities, int amountOfQualities);
};

#endif 
