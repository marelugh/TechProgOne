#include "Sailboat.h"
#include <iostream>
#include <string>
using namespace std;

// Конструктор по умолчанию
Sailboat::Sailboat() : type(""), name(""), isMilitary(false), length(0), speed(0) {
    cout << "Конструктор по умолчанию Sailboat вызван!\n";
}

// Конструктор с параметрами
Sailboat::Sailboat(string type, string name, bool isMilitary, int length, int speed, string crewMember)
    : type(type), name(name), isMilitary(isMilitary), length(length), speed(speed) {
    this->crew.addToTail(crewMember);
    cout << "Конструктор с параметрами Sailboat вызван!\n";
}

// Конструктор копирования
Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), name(other.name), isMilitary(other.isMilitary), length(other.length), speed(other.speed), crew(other.crew) {
    cout << "Конструктор копирования Sailboat вызван!\n";
}

// Деструктор
Sailboat::~Sailboat() {
    cout << "Деструктор Sailboat вызван!\n";
}

// Геттеры и сеттеры
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

// Методы взаимодействия с пользователем
void Sailboat::input() {
    cout << "Введите тип парусника: ";
    string type;
    cin >> type;
    setType(type);

    cout << "Введите название парусника: ";
    string name;
    //cin.ignore();
    cin >> name;
    setName(name);

    cout << "Это военный корабль? (1 - да, 0 - нет): ";
    bool isMilitary;
    cin >> isMilitary;
    setIsMilitary(isMilitary);

    cout << "Введите длину парусника: ";
    int length;
    cin >> length;
    setLength(length);

    cout << "Введите скорость парусника: ";
    int speed;
    cin >> speed;
    setSpeed(speed);

    string crewMember;
    while (true) {
        cout << "Введите имя члена экипажа (или 'q' для завершения): ";
        cin >> crewMember;
        if (crewMember == "q" || crewMember == "Q") {
            break;
        }
        setCrew(crewMember);
    }
}

void Sailboat::print() {
    cout << "Sailboat\n";
    cout << "Тип: " << getType() << endl;
    cout << "Название: " << getName() << endl;
    cout << "Военный: " << (getIsMilitary() ? "Да" : "Нет") << endl;
    cout << "Длина: " << getLength() << " м" << endl;
    cout << "Скорость: " << getSpeed() << " узлов" << endl;

    List crew = getCrew();
    Node* current = crew.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Член экипажа: " << current->item << endl;
        current = current->next;
    }
    cout << '\n';
}

void Sailboat::saveToFile(ofstream& file) {
    file << "SAILBOAT" << endl;
    file << "Тип:" << getType() << endl;
    file << "Название:" << getName() << endl;
    file << "Военный:" << getIsMilitary() << endl;
    file << "Длина:" << getLength() << endl;
    file << "Скорость:" << getSpeed() << endl;

    List crew = getCrew();
    Node* current = crew.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << ". Член экипажа:" << current->item << endl;
        current = current->next;
    }
    file << endl;
}

void Sailboat::loadFromFile(ifstream& file) {
    string line;

    getline(file, line);  // Пропускаем заголовок "SAILBOAT"

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
        size_t pos = line.find("Член экипажа:");
        if (pos != string::npos) {
            string crewMember = line.substr(pos + 14);
            setCrew(crewMember);
        }
    }
}

void Sailboat::change() {
    int command = 0;

    while (command != 8) {
        cout << "Выберите какое значение вы хотите поменять\n1.Тип\n2.Название\n3.Военный(да/нет)\n4.Длина\n5.Скорость\n6.Экипаж\n7.Добавить челна экипажа\n8.Выход";
        cin >> command;
        switch (command) {
        case 1: {
            string type;
            system("cls");
            cout << "Введите новый тип\nType:";
            cin >> type;
            setType(type);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string name;
            system("cls");
            cout << "Введите новое имя\nName:";
            cin >> name;
            setName(name);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            bool isMilitary;
            system("cls");
            cout << "Введите новое значение\n(1 - да / 0 - нет):";
            cin >> isMilitary;
            setIsMilitary(isMilitary);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int length;
            system("cls");
            cout << "Введите новую длину\nLength:";
            cin >> length;
            setLength(length);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            int speed;
            system("cls");
            cout << "Введите новое число скорости\nSpeed:";
            cin >> speed;
            setSpeed(speed);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 6: { // Изменение элемента списка "crew"
            List crew = getCrew();
            Node* current = crew.getHead();

            if (current == nullptr) {
                cout << "Список экипажа пуст!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "Список экипажа:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "Введите номер члена экипажа, которого хотите изменить: ";
            int crewIndex;
            cin >> crewIndex;
            crewIndex--; // Приводим к индексу массива

            if (crewIndex < 0 || crewIndex >= index) {
                cout << "Неверный индекс!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "Введите новое качество: ";
            string newCrew;
            cin.ignore();
            getline(cin, newCrew);

            crew[crewIndex].item = newCrew;
            cout << "Член экипажа успешно изменен!\n";
            system("pause");
            system("cls");
            break;
        }
        case 7: { // Добавление нового качества в список
            string addCrew;
            cout << "Введите нового члена экипажа: ";
            cin.ignore();
            getline(cin, addCrew);
            crew.addToTail(addCrew);  // Добавляем новое качество в конец списка
            cout << "Новый член экипажа добавлен!\n";
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
