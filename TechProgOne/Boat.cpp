#include "Boat.h"
#include <cstring>

// Конструкторы и деструктор
Boat::Boat() : purpose(nullptr), material(nullptr), speed(0), amountOfPeople(0), qualities(nullptr), amountOfQualities(0) {}

Boat::Boat(const char* purpose, const char* material, int speed, int amountOfPeople, const char** qualities, int amountOfQualities)
    : speed(speed), amountOfPeople(amountOfPeople), amountOfQualities(amountOfQualities) {

    // Копирование purpose
    this->purpose = new char[strlen(purpose) + 1];
    strcpy(this->purpose, purpose);

    // Копирование material
    this->material = new char[strlen(material) + 1];
    strcpy(this->material, material);

    // Копирование qualities
    this->qualities = new char* [amountOfQualities];
    for (int i = 0; i < amountOfQualities; ++i) {
        this->qualities[i] = new char[strlen(qualities[i]) + 1];
        strcpy(this->qualities[i], qualities[i]);
    }
}

Boat::Boat(const Boat& other)
    : speed(other.speed), amountOfPeople(other.amountOfPeople), amountOfQualities(other.amountOfQualities) {

    // Копирование purpose
    this->purpose = new char[strlen(other.purpose) + 1];
    strcpy(this->purpose, other.purpose);

    // Копирование material
    this->material = new char[strlen(other.material) + 1];
    strcpy(this->material, other.material);

    // Копирование qualities
    this->qualities = new char* [other.amountOfQualities];
    for (int i = 0; i < other.amountOfQualities; ++i) {
        this->qualities[i] = new char[strlen(other.qualities[i]) + 1];
        strcpy(this->qualities[i], other.qualities[i]);
    }
}

Boat::~Boat() {
    delete[] purpose;
    delete[] material;

    for (int i = 0; i < amountOfQualities; ++i) {
        delete[] qualities[i];
    }
    delete[] qualities;
}

// Геттеры и сеттеры (попарно)

// Purpose
const char* Boat::getPurpose() const {
    return purpose;
}

void Boat::setPurpose(const char* purpose) {
    delete[] this->purpose;
    this->purpose = new char[strlen(purpose) + 1];
    strcpy(this->purpose, purpose);
}

// Material
const char* Boat::getMaterial() const {
    return material;
}

void Boat::setMaterial(const char* material) {
    delete[] this->material;
    this->material = new char[strlen(material) + 1];
    strcpy(this->material, material);
}

// Speed
int Boat::getSpeed() const {
    return speed;
}

void Boat::setSpeed(int speed) {
    this->speed = speed;
}

// Amount of People
int Boat::getAmountOfPeople() const {
    return amountOfPeople;
}

void Boat::setAmountOfPeople(int amountOfPeople) {
    this->amountOfPeople = amountOfPeople;
}

// Qualities
char** Boat::getQualities() const {
    return qualities;
}

int Boat::getAmountOfQualities() const {
    return amountOfQualities;
}

void Boat::setQualities(const char** qualities, int amountOfQualities) {
    // Очистка старого массива qualities
    for (int i = 0; i < this->amountOfQualities; ++i) {
        delete[] this->qualities[i];
    }
    delete[] this->qualities;

    // Установка нового массива qualities
    this->amountOfQualities = amountOfQualities;
    this->qualities = new char* [amountOfQualities];
    for (int i = 0; i < amountOfQualities; ++i) {
        this->qualities[i] = new char[strlen(qualities[i]) + 1];
        strcpy(this->qualities[i], qualities[i]);
    }
}
