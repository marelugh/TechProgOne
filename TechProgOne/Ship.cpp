#include "Ship.h"

Ship::Ship() {
	std::cout << "����������� �� ��������� Ship ������!\n";
}
Ship::Ship(const std::string& info) : shipInfo(info) {
	std::cout << "����������� � ���������� Ship ������ �� ��������� �����������: " << info << "\n";
}
Ship::Ship(const Ship& other) : shipInfo(other.shipInfo) {
	std::cout << "����������� ����������� Ship ������ �� ��������� �����������: " << other.shipInfo << "\n";
}
Ship::~Ship() {
	std::cout << "���������� Ship ������!\n";
}
std::string Ship::getInfo() const {
	return shipInfo;
}
void Ship::setInfo(const std::string& info) {
	this->shipInfo = info;
}


