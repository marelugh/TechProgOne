#include "Sailboat.h"
#include <iostream>
#include <string>
using namespace std;

// ����������� �� ���������
Sailboat::Sailboat() : type(""), name(""), isMilitary(false), length(0), speed(0) {
    cout << "����������� �� ��������� Sailboat ������!\n";
}

// ����������� � �����������
Sailboat::Sailboat(string type, string name, bool isMilitary, int length, int speed, string crewMember)
    : type(type), name(name), isMilitary(isMilitary), length(length), speed(speed) {
    this->crew.addToTail(crewMember);
    cout << "����������� � ����������� Sailboat ������!\n";
}

// ����������� �����������
Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), name(other.name), isMilitary(other.isMilitary), length(other.length), speed(other.speed), crew(other.crew) {
    cout << "����������� ����������� Sailboat ������!\n";
}

// ����������
Sailboat::~Sailboat() {
    cout << "���������� Sailboat ������!\n";
}

// ������� � �������
string Sailboat::getType() const {
    return type;
}

void Sailboat::setType(const string& type) {
    this->type = type;
}

string Sailboat::getName() const {
    return name;
}

void Sailboat::setName(const string& name) {
    this->name = name;
}

bool Sailboat::getIsMilitary() const {
    return isMilitary;
}

void Sailboat::setIsMilitary(bool isMilitary) {
    this->isMilitary = isMilitary;
}

int Sailboat::getLength() const {
    return length;
}

void Sailboat::setLength(int length) {
    this->length = length;
}

int Sailboat::getSpeed() const {
    return speed;
}

void Sailboat::setSpeed(int speed) {
    this->speed = speed;
}

List Sailboat::getCrew() const {
    return crew;
}

void Sailboat::setCrew(const string& crewMember) {
    this->crew.addToTail(crewMember);
}

// ������ �������������� � �������������
void Sailboat::input() {
    cout << "������� ��� ���������: ";
    string type;
    cin >> type;
    setType(type);

    cout << "������� �������� ���������: ";
    string name;
    //cin.ignore();
    cin >> name;
    setName(name);

    cout << "��� ������� �������? (1 - ��, 0 - ���): ";
    bool isMilitary;
    cin >> isMilitary;
    setIsMilitary(isMilitary);

    cout << "������� ����� ���������: ";
    int length;
    cin >> length;
    setLength(length);

    cout << "������� �������� ���������: ";
    int speed;
    cin >> speed;
    setSpeed(speed);

    string crewMember;
    while (true) {
        cout << "������� ��� ����� ������� (��� 'q' ��� ����������): ";
        cin >> crewMember;
        if (crewMember == "q" || crewMember == "Q") {
            break;
        }
        setCrew(crewMember);
    }
}

void Sailboat::print() {
    cout << "Sailboat\n";
    cout << "���: " << getType() << endl;
    cout << "��������: " << getName() << endl;
    cout << "�������: " << (getIsMilitary() ? "��" : "���") << endl;
    cout << "�����: " << getLength() << " �" << endl;
    cout << "��������: " << getSpeed() << " �����" << endl;

    List crew = getCrew();
    Node* current = crew.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". ���� �������: " << current->item << endl;
        current = current->next;
    }
    cout << '\n';
}

void Sailboat::saveToFile(ofstream& file) {
    file << "SAILBOAT" << endl;
    file << "���:" << getType() << endl;
    file << "��������:" << getName() << endl;
    file << "�������:" << getIsMilitary() << endl;
    file << "�����:" << getLength() << endl;
    file << "��������:" << getSpeed() << endl;

    List crew = getCrew();
    Node* current = crew.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << ". ���� �������:" << current->item << endl;
        current = current->next;
    }
    file << endl;
}

void Sailboat::loadFromFile(ifstream& file) {
    string line;

    getline(file, line);  // ���������� ��������� "SAILBOAT"

    getline(file, line);
    setName(line.substr(line.find(":") + 1));

    getline(file, line);
    setType(line.substr(line.find(":") + 1));

    getline(file, line);
    setIsMilitary(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setLength(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setSpeed(stoi(line.substr(line.find(":") + 1)));

    while (getline(file, line)) {
        if (line.empty()) break;
        size_t pos = line.find("���� �������:");
        if (pos != string::npos) {
            string crewMember = line.substr(pos + 14);
            setCrew(crewMember);
        }
    }
}

void Sailboat::change() {
    int command = 0;

    while (command != 8) {
        cout << "�������� ����� �������� �� ������ ��������\n1.���\n2.��������\n3.�������(��/���)\n4.�����\n5.��������\n6.������\n7.�������� ����� �������\n8.�����";
        cin >> command;
        switch (command) {
        case 1: {
            string type;
            system("cls");
            cout << "������� ����� ���\nType:";
            cin >> type;
            setType(type);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
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
        case 3: {
            bool isMilitary;
            system("cls");
            cout << "������� ����� ��������\n(1 - �� / 0 - ���):";
            cin >> isMilitary;
            setIsMilitary(isMilitary);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
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
        case 5: {
            int speed;
            system("cls");
            cout << "������� ����� ����� ��������\nSpeed:";
            cin >> speed;
            setSpeed(speed);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 6: { // ��������� �������� ������ "crew"
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
        case 7: { // ���������� ������ �������� � ������
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
        case 8: {
            break;
        }
        }
    }
}
