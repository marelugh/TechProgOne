#include "Submarine.h"
#include <cstring>

// Конструкторы и деструктор
Submarine::Submarine() : length(0), width(0), crew(nullptr), crewSize(0), underwaterTime(0), underwaterSpeed(0), ammo(nullptr), ammoAmount(0) {}

Submarine::Submarine(double length, double width, const char** crew, int crewSize, int underwaterTime, int underwaterSpeed, const char** ammo, int ammoAmount)
    : length(length), width(width), crewSize(crewSize), underwaterTime(underwaterTime), underwaterSpeed(underwaterSpeed), ammoAmount(ammoAmount) {

    // Копирование crew
    this->crew = new char* [crewSize];
    for (int i = 0; i < crewSize; ++i) {
        this->crew[i] = new char[strlen(crew[i]) + 1];
        strcpy(this->crew[i], crew[i]);
    }

    // Копирование ammo
    this->ammo = new char* [ammoAmount];
    for (int i = 0; i < ammoAmount; ++i) {
        this->ammo[i] = new char[strlen(ammo[i]) + 1];
        strcpy(this->ammo[i], ammo[i]);
    }
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crewSize(other.crewSize), underwaterTime(other.underwaterTime), underwaterSpeed(other.underwaterSpeed), ammoAmount(other.ammoAmount) {

    // Копирование crew
    this->crew = new char* [other.crewSize];
    for (int i = 0; i < other.crewSize; ++i) {
        this->crew[i] = new char[strlen(other.crew[i]) + 1];
        strcpy(this->crew[i], other.crew[i]);
    }

    // Копирование ammo
    this->ammo = new char* [other.ammoAmount];
    for (int i = 0; i < other.ammoAmount; ++i) {
        this->ammo[i] = new char[strlen(other.ammo[i]) + 1];
        strcpy(this->ammo[i], other.ammo[i]);
    }
}

Submarine::~Submarine() {
    for (int i = 0; i < crewSize; ++i) {
        delete[] crew[i];
    }
    delete[] crew;

    for (int i = 0; i < ammoAmount; ++i) {
        delete[] ammo[i];
    }
    delete[] ammo;
}

// Геттеры и сеттеры

double Submarine::getLength() const {
    return length;
}

void Submarine::setLength(double length) {
    this->length = length;
}

double Submarine::getWidth() const {
    return width;
}

void Submarine::setWidth(double width) {
    this->width = width;
}

char** Submarine::getCrew() const {
    return crew;
}

int Submarine::getCrewSize() const {
    return crewSize;
}

void Submarine::setCrew(const char** crew, int crewSize) {
    for (int i = 0; i < this->crewSize; ++i) {
        delete[] this->crew[i];
    }
    delete[] this->crew;

    this->crewSize = crewSize;
    this->crew = new char* [crewSize];
    for (int i = 0; i < crewSize; ++i) {
        this->crew[i] = new char[strlen(crew[i]) + 1];
        strcpy(this->crew[i], crew[i]);
    }
}

int Submarine::getUnderwaterTime() const {
    return underwaterTime;
}

void Submarine::setUnderwaterTime(int underwaterTime) {
    this->underwaterTime = underwaterTime;
}

int Submarine::getUnderwaterSpeed() const {
    return underwaterSpeed;
}

void Submarine::setUnderwaterSpeed(int underwaterSpeed) {
    this->underwaterSpeed = underwaterSpeed;
}

char** Submarine::getAmmo() const {
    return ammo;
}

int Submarine::getAmmoAmount() const {
    return ammoAmount;
}

void Submarine::setAmmo(const char** ammo, int ammoAmount) {
    for (int i = 0; i < this->ammoAmount; ++i) {
        delete[] this->ammo[i];
    }
    delete[] this->ammo;

    this->ammoAmount = ammoAmount;
    this->ammo = new char* [ammoAmount];
    for (int i = 0; i < ammoAmount; ++i) {
        this->ammo[i] = new char[strlen(ammo[i]) + 1];
        strcpy(this->ammo[i], ammo[i]);
    }
}
