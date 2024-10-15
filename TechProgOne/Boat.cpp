#include "Boat.h"
#include <iostream>
using namespace std;

// Конструктор по умолчанию
Boat::Boat() : boatName(""), purpose(""), material(""), speed(0), amountOfPeople(0) {
    cout << "Конструктор по умолчанию Boat вызван!\n";
}

// Конструктор с параметрами
Boat::Boat(string purpose, string material, int speed, int amountOfPeople, string quality, string boatName)
    : purpose(purpose), material(material), speed(speed), amountOfPeople(amountOfPeople), boatName(boatName) {
    qualities.addToTail(quality);
    cout << "Конструктор с параметрами Boat вызван!\n";
}

// Конструктор копирования
Boat::Boat(const Boat& other)
    : purpose(other.purpose), material(other.material), speed(other.speed), amountOfPeople(other.amountOfPeople), qualities(other.qualities), boatName(other.boatName) {
    cout << "Конструктор копирования Boat вызван!\n";
}

// Деструктор
Boat::~Boat() {
    cout << "Деструктор Boat вызван!\n";
}

// Геттеры и сеттеры
string Boat::getPurpose() const {
    return purpose;
}

void Boat::setPurpose(const string& purpose) {
    this->purpose = purpose;
}

string Boat::getName() const {
    return boatName;
}

void Boat::setName(const string& name) {
    this->boatName = name;
}

string Boat::getMaterial() const {
    return material;
}

void Boat::setMaterial(const string& material) {
    this->material = material;
}

int Boat::getSpeed() const {
    return speed;
}

void Boat::setSpeed(int speed) {
    this->speed = speed;
}

int Boat::getAmountOfPeople() const {
    return amountOfPeople;
}

void Boat::setAmountOfPeople(int amountOfPeople) {
    this->amountOfPeople = amountOfPeople;
}

List Boat::getQualities() const {
    return qualities;
}

void Boat::setQualities(const string& quality) {
    qualities.addToTail(quality);
}

// Методы взаимодействия с пользователем
void Boat::input() {
    cout << "Введите название лодки: ";
    string boatName;
    cin.ignore();
    getline(cin, boatName);
    setName(boatName);

    cout << "Введите назначение лодки: ";
    string purpose;
    cin.ignore();
    getline(cin, purpose);
    setPurpose(purpose);

    cout << "Введите материал лодки: ";
    string material;
    getline(cin, material);
    setMaterial(material);

    cout << "Введите скорость лодки: ";
    int speed;
    cin >> speed;
    setSpeed(speed);

    string quality;
    while (true) {
        cout << "Введите качество лодки (или 'q' для завершения): ";
        cin >> quality;
        if (quality == "q" || quality == "Q") {
            break;
        }
        setQualities(quality);
    }

    cout << "Введите количество людей на борту: ";
    int amountOfPeople;
    cin >> amountOfPeople;
    setAmountOfPeople(amountOfPeople);
}

void Boat::print() {
    cout << "Boat\n";
    cout << "Название: " << getName() << endl;
    cout << "Назначение: " << getPurpose() << endl;
    cout << "Материал: " << getMaterial() << endl;
    cout << "Скорость: " << getSpeed() << " узлов" << endl;
    cout << "Количество людей: " << getAmountOfPeople() << endl;

    List qualities = getQualities();
    Node* current = qualities.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Качество: " << current->item << endl;
        current = current->next;
    }
    cout << '\n';
}

void Boat::saveToFile(ofstream& file) {
    file << "BOAT" << endl;
    file << "Название:" << getName() << endl;
    file << "Назначение:" << getPurpose() << endl;
    file << "Материал:" << getMaterial() << endl;
    file << "Скорость:" << getSpeed() << endl;
    file << "Количество людей:" << getAmountOfPeople() << endl;

    List qualities = getQualities();
    Node* current = qualities.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << ". Качество:" << current->item << endl;
        current = current->next;
    }
    file << endl;
}

void Boat::loadFromFile(ifstream& file) {
    string line;

    getline(file, line);  // Пропускаем заголовок "BOAT"

    getline(file, line);
    setName(line.substr(line.find(":") + 1));

    getline(file, line);
    setPurpose(line.substr(line.find(":") + 1));

    getline(file, line);
    setMaterial(line.substr(line.find(":") + 1));

    getline(file, line);
    setSpeed(stoi(line.substr(line.find(":") + 1)));

    getline(file, line);
    setAmountOfPeople(stoi(line.substr(line.find(":") + 1)));

    while (getline(file, line)) {
        if (line.empty()) break;
        size_t pos = line.find("Качество:");
        if (pos != string::npos) {
            string quality = line.substr(pos + 9);
            setQualities(quality);
        }
    }
}


void Boat::change() {
    int command = 0;

    while (command != 9) {
        cout << "Выберите, какое значение вы хотите поменять\n"
            << "1. Назначение\n2. Материал\n3. Скорость\n4. Количество экипажа\n5. Название\n6. Качества\n7. Добавить новое качество\n8.Изменить качество\n9. Выход\n";
        cin >> command;
        switch (command) {
        case 1: {
            string purpose;
            system("cls");
            cout << "Введите новое назначение лодки\nPurpose: ";
            cin >> purpose;
            setPurpose(purpose);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string material;
            system("cls");
            cout << "Введите новый материал\nMaterial: ";
            cin >> material;
            setMaterial(material);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int speed;
            system("cls");
            cout << "Введите новую скорость\nSpeed: ";
            cin >> speed;
            setSpeed(speed);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int amountOfPeople;
            system("cls");
            cout << "Введите новое число экипажа\nAmount of people: ";
            cin >> amountOfPeople;
            setAmountOfPeople(amountOfPeople);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            string boatName;
            system("cls");
            cout << "Введите новое название\nName: ";
            cin >> boatName;
            setName(boatName);
            cout << "Успешно!";
            system("pause");
            system("cls");
            break;
        }
        case 6: { // Изменение элемента списка "qualities"
            List qualities = getQualities();
            Node* current = qualities.getHead();

            if (current == nullptr) {
                cout << "Список качеств пуст!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "Список качеств:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "Введите номер качества, которое хотите изменить: ";
            int qualityIndex;
            cin >> qualityIndex;
            qualityIndex--; // Приводим к индексу массива

            if (qualityIndex < 0 || qualityIndex >= index) {
                cout << "Неверный индекс качества!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "Введите новое качество: ";
            string newQuality;
            cin.ignore();
            getline(cin, newQuality);

            qualities[qualityIndex].item = newQuality;
            cout << "Качество успешно изменено!\n";
            system("pause");
            system("cls");
            break;
        }
        case 7: { // Добавление нового качества в список
            string newQuality;
            cout << "Введите новое качество лодки: ";
            cin.ignore();
            getline(cin, newQuality);
            qualities.addToTail(newQuality);  // Добавляем новое качество в конец списка
            cout << "Новое качество успешно добавлено!\n";
            system("pause");
            system("cls");
            break;
        }
        case 8: { // Изменение элемента списка "qualities"
            List qualities = getQualities();
            Node* current = qualities.getHead();

            if (current == nullptr) {
                cout << "Список качеств пуст!\n";
                system("pause");
                system("cls");
                break;
            }

            int index = 0;
            cout << "Список качеств:\n";
            while (current != nullptr) {
                cout << index + 1 << ". " << current->item << endl;
                current = current->next;
                index++;
            }

            cout << "Введите номер качества, которое хотите изменить: ";
            int qualityIndex;
            cin >> qualityIndex;
            qualityIndex--; // Приводим к индексу массива

            if (qualityIndex < 0 || qualityIndex >= index) {
                cout << "Неверный индекс качества!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "Введите новое качество: ";
            string newQuality;
            cin.ignore();
            getline(cin, newQuality);

            qualities[qualityIndex].item = newQuality;
            cout << "Качество успешно изменено!\n";
            system("pause");
            system("cls");
            break;
        }
        case 9: {
            break;
        }
        }
    }
}

