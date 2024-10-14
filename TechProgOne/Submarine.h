#ifndef SUBMARINE_H
#define SUBMARINE_H
#include "Ship.h"
#include "List.h"
#include <string>
#include <fstream>
using namespace std;

class Submarine : public Ship {
private:
    string name;
    int length;
    int width;
    List crew;            // Список экипажа
    int underwaterTime;
    int underwaterSpeed;
    List ammo;            // Список боеприпасов

public:
    Submarine();
    Submarine(int length, int width, string crew, int underwaterTime, int underwaterSpeed, string ammo, string name);
    Submarine(const Submarine& other);
    ~Submarine();

    int getLength() const;
    void setLength(int length);

    int getWidth() const;
    void setWidth(int width);

    string getName() const;
    void setName(const string& name);

    List getCrew() const;
    void setCrew(const string& crewMember);

    int getUnderwaterTime() const;
    void setUnderwaterTime(int underwaterTime);

    int getUnderwaterSpeed() const;
    void setUnderwaterSpeed(int underwaterSpeed);

    List getAmmo() const;
    void setAmmo(const string& ammoItem);

    // Новые методы
    void input();
    void print();
    void change();
    void saveToFile(ofstream& file);
    void loadFromFile(ifstream& file);
};

#endif // SUBMARINE_H
