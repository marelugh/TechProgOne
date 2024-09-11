#include "Ship.h"

Ship::Ship() : name("Unnamed") {
	std::cout << "����������� �� ��������� Ship ������!\n";
}
Ship::Ship(const std::string& name) : name(name) {
	std::cout << "����������� � ���������� Ship ������ ��� " << name << "\n";
}
Ship::Ship(const Ship& other) : name(other.name) {
	std::cout << "����������� ����������� Ship ������ ��� " << other.name << "\n";
}
std::string Ship::getName() const {
	return name;
}
void Ship::setName(const std::string& name) {
	this->name = name;
}


