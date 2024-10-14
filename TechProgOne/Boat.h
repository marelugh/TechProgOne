#ifndef BOAT_H
#define BOAT_H
#include "Ship.h"
#include "List.h"
#include <string>
#include <fstream>

class Boat : public Ship {
private:
    string boatName;
    string purpose;
    string material;
    int speed;
    int amountOfPeople;
    List qualities;

public:
    Boat();
    Boat(string purpose, string material, int speed, int amountOfPeople, string quality, string boatName);
    Boat(const Boat& other);
    ~Boat();

    string getPurpose() const;
    void setPurpose(const string& name);

    string getName() const;
    void setName(const string& name);

    string getMaterial() const;
    void setMaterial(const string& material);

    int getSpeed() const;
    void setSpeed(int speed);

    int getAmountOfPeople() const;
    void setAmountOfPeople(int amountOfPeople);

    List getQualities() const;
    void setQualities(const string& quality);

    // Методы взаимодействия с пользователем и файлами
    void input();
    void print();
    void change();
    void saveToFile(ofstream& file);
    void loadFromFile(ifstream& file);
};

#endif // BOAT_H
