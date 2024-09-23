#include "Sailboat.h"

Sailboat::Sailboat() : type(nullptr), name(nullptr), isMilitary(false), length(0.0), speed(0.0), crew(nullptr), crewSize(0) {
	std::cout << "Констркутор по умолчанию Sailboat вызван!\n";
}
Sailboat::Sailboat(const char* type, const char* name, bool isMilitary, double length, double speed, const char** crew, int crewSize) 
    : isMilitary(isMilitary), length(length), speed(speed), crewSize(crewSize) {
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    // Копируем массив crew
    this->crew = new char* [crewSize];
    for (int i = 0; i < crewSize; ++i) {
        this->crew[i] = new char[strlen(crew[i]) + 1];
        strcpy(this->crew[i], crew[i]);
    }

    std::cout << "Конструктор с параметрами Sailboat вызван!\n";
}
Sailboat::Sailboat(const Sailboat& other)
    : isMilitary(other.isMilitary), length(other.length), speed(other.speed), crewSize(other.crewSize) {
    // Копируем строки type и name
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    // Копируем массив crew
    this->crew = new char* [crewSize];
    for (int i = 0; i < crewSize; ++i) {
        this->crew[i] = new char[strlen(other.crew[i]) + 1];
        strcpy(this->crew[i], other.crew[i]);
    }

    std::cout << "Конструктор копирования Sailboat вызван!\n";
}
Sailboat::~Sailboat() {
    delete[] type;
    delete[] name;

    for (int i = 0; i < crewSize; ++i) {
        delete[] crew[i];
    }
    delete[] crew;
    std::cout << "Деструктор Sailboat вызван!\n";
}
const char* Sailboat::getType() const {
    return type;
}

void Sailboat::setType(const char* type) {
    delete[] this->type;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

const char* Sailboat::getName() const {
    return name;
}

void Sailboat::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

bool Sailboat::getIsMilitary() const {
    return isMilitary;
}

void Sailboat::setIsMilitary(bool isMilitary) {
    this->isMilitary = isMilitary;
}

double Sailboat::getLength() const {
    return length;
}

void Sailboat::setLength(double length) {
    this->length = length;
}

double Sailboat::getSpeed() const {
    return speed;
}

void Sailboat::setSpeed(double speed) {
    this->speed = speed;
}

char** Sailboat::getCrew() const {
    return crew;
}

int Sailboat::getCrewSize() const {
    return crewSize;
}

void Sailboat::setCrew(const char** crew, int crewSize) {
    // Освобождаем старую память
    for (int i = 0; i < this->crewSize; ++i) {
        delete[] this->crew[i];
    }
    delete[] this->crew;

    // Выделяем новую память для массива crew
    this->crewSize = crewSize;
    this->crew = new char* [crewSize];
    for (int i = 0; i < crewSize; ++i) {
        this->crew[i] = new char[strlen(crew[i]) + 1];
        strcpy(this->crew[i], crew[i]);
    }
}
