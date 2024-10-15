#include "Submarine.h"
#include <iostream>
#include <fstream>
using namespace std;

// ����������� �� ���������
Submarine::Submarine()
    : length(0), width(0), underwaterTime(0), underwaterSpeed(0), name("") {
    cout << "����������� �� ��������� Submarine ������" << endl;
}

// ����������� � �����������
Submarine::Submarine(int length, int width, string crewMember, int underwaterTime, int underwaterSpeed, string ammoItem, string name)
    : length(length), width(width), underwaterTime(underwaterTime), underwaterSpeed(underwaterSpeed), name(name) {
    crew.addToTail(crewMember);
    ammo.addToTail(ammoItem);
    cout << "����������� � ����������� Submarine ������" << endl;
}

// ����������� �����������
Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew), underwaterTime(other.underwaterTime), underwaterSpeed(other.underwaterSpeed), ammo(other.ammo), name(other.name) {
    cout << "����������� ����������� Submarine ������" << endl;
}

// ����������
Submarine::~Submarine() {
    cout << "���������� Submarine ������" << endl;
}

// ������� � �������
int Submarine::getLength() const {
    return length;
}

void Submarine::setLength(int length) {
    this->length = length;
}

string Submarine::getName() const {
    return name;
}

void Submarine::setName(const string& name) {
    this->name = name;
}

int Submarine::getWidth() const {
    return width;
}

void Submarine::setWidth(int width) {
    this->width = width;
}

List Submarine::getCrew() const {
    return crew;
}

void Submarine::setCrew(const string& crewMember) {
    crew.addToTail(crewMember);
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

List Submarine::getAmmo() const {
    return ammo;
}

void Submarine::setAmmo(const string& ammoItem) {
    ammo.addToTail(ammoItem);
}

// ����� ��� ����� ������
void Submarine::input() {
    cout << "������� �������� ��������: ";
    string name;
    //cin.ignore();
    cin >> name;
    setName(name);

    cout << "������� ����� ��������: ";
    cin >> length;
    setLength(length);

    cout << "������� ������ ��������: ";
    cin >> width;
    setWidth(width);

    cout << "������� ����� ��� ����� (� �����): ";
    cin >> underwaterTime;
    setUnderwaterTime(underwaterTime);

    cout << "������� ��������� �������� (� �����): ";
    cin >> underwaterSpeed;
    setUnderwaterSpeed(underwaterSpeed);

    string crewMember;
    cout << "������� ��� ����� ������� (��� 'q' ��� ����������): ";
    while (cin >> crewMember && crewMember != "q") {
        setCrew(crewMember);
        cout << "������� ��� ����� ������� (��� 'q' ��� ����������): ";
    }

    string ammoItem;
    cout << "������� ���������� (��� 'q' ��� ����������): ";
    while (cin >> ammoItem && ammoItem != "q") {
        setAmmo(ammoItem);
        cout << "������� ���������� (��� 'q' ��� ����������): ";
    }
}

// ����� ��� ������ ������
void Submarine::print() {
    cout << "Submarine" << endl;
    cout << "Name: " << name << endl;
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Underwater Time: " << underwaterTime << " hours" << endl;
    cout << "Underwater Speed: " << underwaterSpeed << " knots" << endl;

    cout << "Crew: ";
    Node* currentCrew = crew.getHead();
    int i = 1;
    while (currentCrew != nullptr) {
        cout << i++ << ". " << currentCrew->item << ", ";
        currentCrew = currentCrew->next;
    }
    cout << endl;

    cout << "Ammo: ";
    Node* currentAmmo = ammo.getHead();
    i = 1;
    while (currentAmmo != nullptr) {
        cout << i++ << ". " << currentAmmo->item << ", ";
        currentAmmo = currentAmmo->next;
    }
    cout << endl;
    cout << '\n';
}

// ����� ��� ���������� � ����
void Submarine::saveToFile(ofstream& file) {
    file << "SUBMARINE" << endl;
    file << "Name: " << name << endl;
    file << "Length: " << length << endl;
    file << "Width: " << width << endl;
    file << "Underwater Time: " << underwaterTime << endl;
    file << "Underwater Speed: " << underwaterSpeed << endl;

    Node* currentCrew = crew.getHead();
    file << "Crew: ";
    while (currentCrew != nullptr) {
        file << currentCrew->item << ", ";
        currentCrew = currentCrew->next;
    }
    file << endl;

    Node* currentAmmo = ammo.getHead();
    file << "Ammo: ";
    while (currentAmmo != nullptr) {
        file << currentAmmo->item << ", ";
        currentAmmo = currentAmmo->next;
    }
    file << endl;
    file << '\n';
}

// ����� ��� �������� �� �����
void Submarine::loadFromFile(ifstream& file) {
    string line;
    getline(file, line); // ���������� "SUBMARINE"

    getline(file, line);
    setName(line.substr(line.find(":") + 1));

    getline(file, line);
    setLength(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setWidth(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setUnderwaterTime(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setUnderwaterSpeed(stoi(line.substr(line.find(":") + 1)));

    // ������ �������
    getline(file, line);
    size_t pos = 0;
    while ((pos = line.find(",")) != string::npos) {
        string crewMember = line.substr(0, pos);
        setCrew(crewMember);
        line.erase(0, pos + 1);
    }

    // ������ �����������
    getline(file, line);
    pos = 0;
    while ((pos = line.find(",")) != string::npos) {
        string ammoItem = line.substr(0, pos);
        setAmmo(ammoItem);
        line.erase(0, pos + 1);
    }
}

void Submarine::change() {
    int command = 0;

    while (command != 10) {
        cout << "�������� ����� �������� �� ������ ��������\n1.�����\n2.������\n3.����� ���������� ��� �����\n4.�������� ��� �����\n5.��������\n6.������\n7.����������\n8.���������� ����� �������\n9.���������� ����������\n10.�����";
        cin >> command;
        switch (command) {
        case 1: {
            int length;
            system("cls");
            cout << "������� ����� �����\nLength:";
            cin >> length;
            setLength(length);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            int width;
            system("cls");
            cout << "������� ����� ������\nWidth:";
            cin >> width;
            setWidth(width);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int underwaterTime;
            system("cls");
            cout << "������� ����� ����� ���������� ��� �����\nUnderwater Time:";
            cin >> underwaterTime;
            setUnderwaterTime(underwaterTime);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int underwaterSpeed;
            system("cls");
            cout << "������� ����� �������� ��� �����\nUnderwater Speed:";
            cin >> underwaterSpeed;
            setUnderwaterSpeed(underwaterSpeed);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            string name;
            system("cls");
            cout << "������� ����� ���\nName:";
            cin >> name;
            setName(name);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 6: { // ��������� �������� ������ "qualities"
            List crew = getCrew();
            Node* current = crew.getHead();

            if (current == nullptr) {
                cout << "������ ������� ����!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "������ �������:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "������� ����� ����� �������, �������� ������ ��������: ";
            int crewIndex;
            cin >> crewIndex;
            crewIndex--; // �������� � ������� �������

            if (crewIndex < 0 || crewIndex >= index) {
                cout << "�������� ������!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "������� ����� ��������: ";
            string newCrew;
            cin.ignore();
            getline(cin, newCrew);

            crew[crewIndex].item = newCrew;
            cout << "���� ������� ������� �������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 7: { // ��������� �������� ������ "qualities"
            List ammo = getAmmo();
            Node* current = ammo.getHead();

            if (current == nullptr) {
                cout << "������ ���������� ����!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "������ ���������:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "������� ����� ����������, ������� ������ ��������: ";
            int ammoIndex;
            cin >> ammoIndex;
            ammoIndex--; // �������� � ������� �������

            if (ammoIndex < 0 || ammoIndex >= index) {
                cout << "�������� ������!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "������� ����� ����������: ";
            string newAmmo;
            cin.ignore();
            getline(cin, newAmmo);

            ammo[ammoIndex].item = newAmmo;
            cout << "���������� ������� ��������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 8: { // ���������� ������ �������� � ������
            string addCrew;
            cout << "������� ������ ����� �������: ";
            cin.ignore();
            getline(cin, addCrew);
            crew.addToTail(addCrew);  // ��������� ����� �������� � ����� ������
            cout << "����� ���� ������� ��������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 9: { // ���������� ������ �������� � ������
            string addAmmo;
            cout << "������� ������ ����������: ";
            cin.ignore();
            getline(cin, addAmmo);
            ammo.addToTail(addAmmo);  // ��������� ����� �������� � ����� ������
            cout << "����� ���������� ���������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 10: {
            break;
        }
        }
    }
}
