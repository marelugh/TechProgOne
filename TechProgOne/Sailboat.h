#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"
#include "List.h"
#include <string>
#include <fstream>
using namespace std;

class Sailboat : public Ship {
private:
    string type;
    string name;
    bool isMilitary;
    int length;
    int speed;
    List crew;

public:
    Sailboat();
    Sailboat(string type, string name, bool isMilitary, int length, int speed, string crewMember);
    Sailboat(const Sailboat& other);
    ~Sailboat();

    string getType() const;
    void setType(const string& type);

    string getName() const;
    void setName(const string& name);

    bool getIsMilitary() const;
    void setIsMilitary(bool isMilitary);

    int getLength() const;
    void setLength(int length);

    int getSpeed() const;
    void setSpeed(int speed);

    List getCrew() const;
    void setCrew(const string& crewMember);

    // Методы для взаимодействия с пользователем и файлами
    void input();
    void change();
    void print();
    void saveToFile(ofstream& file);
    void loadFromFile(ifstream& file);
};

#endif // SAILBOAT_H
