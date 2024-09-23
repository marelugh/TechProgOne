#include "Ship.h"

Ship::Ship() {
	std::cout << "Констркутор по умолчанию Ship вызван!\n";
}
Ship::Ship(const std::string& info) : shipInfo(info) {
	std::cout << "Констркутор с параметром Ship вызван со следующей информацией: " << info << "\n";
}
Ship::Ship(const Ship& other) : shipInfo(other.shipInfo) {
	std::cout << "Конструктор копирования Ship вызван со следующей информацией: " << other.shipInfo << "\n";
}
Ship::~Ship() {
	std::cout << "Деструктор Ship вызван!\n";
}
std::string Ship::getInfo() const {
	return shipInfo;
}
void Ship::setInfo(const std::string& info) {
	this->shipInfo = info;
}


