#include "Submarine.h"
#include <iostream>
#include <fstream>
using namespace std;

// Конструктор по умолчанию
Submarine::Submarine()
    : length(0), width(0), underwaterTime(0), underwaterSpeed(0), name("") {
    cout << "Конструктор по умолчанию Submarine вызван" << endl;
}

// Конструктор с параметрами
Submarine::Submarine(int length, int width, string crewMember, int underwaterTime, int underwaterSpeed, string ammoItem, string name)
    : length(length), width(width), underwaterTime(underwaterTime), underwaterSpeed(underwaterSpeed), name(name) {
    crew.addToTail(crewMember);
    ammo.addToTail(ammoItem);
    cout << "Конструктор с параметрами Submarine вызван" << endl;
}

// Конструктор копирования
Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew), underwaterTime(other.underwaterTime), underwaterSpeed(other.underwaterSpeed), ammo(other.ammo), name(other.name) {
    cout << "Конструктор копирования Submarine вызван" << endl;
}

// Деструктор
Submarine::~Submarine() {
    cout << "Деструктор Submarine вызван" << endl;
}

// Геттеры и сеттеры
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

// Метод для ввода данных
void Submarine::input() {
    cout << "Введите название подлодки: ";
    string name;
    //cin.ignore();
    cin >> name;
    setName(name);

    cout << "Введите длину подлодки: ";
    cin >> length;
    setLength(length);

    cout << "Введите ширину подлодки: ";
    cin >> width;
    setWidth(width);

    cout << "Введите время под водой (в часах): ";
    cin >> underwaterTime;
    setUnderwaterTime(underwaterTime);

    cout << "Введите подводную скорость (в узлах): ";
    cin >> underwaterSpeed;
    setUnderwaterSpeed(underwaterSpeed);

    string crewMember;
    cout << "Введите имя члена экипажа (или 'q' для завершения): ";
    while (cin >> crewMember && crewMember != "q") {
        setCrew(crewMember);
        cout << "Введите имя члена экипажа (или 'q' для завершения): ";
    }

    string ammoItem;
    cout << "Введите боеприпасы (или 'q' для завершения): ";
    while (cin >> ammoItem && ammoItem != "q") {
        setAmmo(ammoItem);
        cout << "Введите боеприпасы (или 'q' для завершения): ";
    }
}

// Метод для вывода данных
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

// Метод для сохранения в файл
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

// Метод для загрузки из файла
void Submarine::loadFromFile(ifstream& file) {
    string line;
    getline(file, line); // Пропускаем "SUBMARINE"

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

    // Чтение экипажа
    getline(file, line);
    size_t pos = 0;
    while ((pos = line.find(",")) != string::npos) {
        string crewMember = line.substr(0, pos);
        setCrew(crewMember);
        line.erase(0, pos + 1);
    }

    // Чтение боеприпасов
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
        cout << "Выберите какое значение вы хотите поменять\n1.Длина\n2.Ширина\n3.Время нахождения под водой\n4.Скорость под водой\n5.Название\n6.Экипаж\n7.Вооружение\n8.Добавление члена экипажа\n9.Добавление вооружения\n10.Выход";
        cin >> command;
        switch (command) {
        case 1: {
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
        case 2: {
            int width;
            system("cls");
            cout << "Введите новую ширину\nWidth:";
            cin >> width;
            setWidth(width);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int underwaterTime;
            system("cls");
            cout << "Введите новое время нахождения под водой\nUnderwater Time:";
            cin >> underwaterTime;
            setUnderwaterTime(underwaterTime);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int underwaterSpeed;
            system("cls");
            cout << "Введите новую скорость под водой\nUnderwater Speed:";
            cin >> underwaterSpeed;
            setUnderwaterSpeed(underwaterSpeed);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
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
        case 6: { // Изменение элемента списка "qualities"
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
        case 7: { // Изменение элемента списка "qualities"
            List ammo = getAmmo();
            Node* current = ammo.getHead();

            if (current == nullptr) {
                cout << "Список вооружения пуст!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "Список вооужения:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "Введите номер вооружения, которое хотите изменить: ";
            int ammoIndex;
            cin >> ammoIndex;
            ammoIndex--; // Приводим к индексу массива

            if (ammoIndex < 0 || ammoIndex >= index) {
                cout << "Неверный индекс!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "Введите новое вооружение: ";
            string newAmmo;
            cin.ignore();
            getline(cin, newAmmo);

            ammo[ammoIndex].item = newAmmo;
            cout << "Вооружение успешно изменено!\n";
            system("pause");
            system("cls");
            break;
        }
        case 8: { // Добавление нового качества в список
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
        case 9: { // Добавление нового качества в список
            string addAmmo;
            cout << "Введите нового вооружения: ";
            cin.ignore();
            getline(cin, addAmmo);
            ammo.addToTail(addAmmo);  // Добавляем новое качество в конец списка
            cout << "Новое вооружение добавлено!\n";
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
