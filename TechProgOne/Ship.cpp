#include "Ship.h"

Ship::Ship() : name("Unnamed") {
	std::cout << "Констркутор по умолчанию Ship вызван!\n";
}
Ship::Ship(const std::string& name) : name(name) {
	std::cout << "Констркутор с параметром Ship вызван для " << name << "\n";
}
Ship::Ship(const Ship& other) : name(other.name) {
	std::cout << "Конструктор копирования Ship вызван для " << other.name << "\n";
}
std::string Ship::getName() const {
	return name;
}
void Ship::setName(const std::string& name) {
	this->name = name;
}


