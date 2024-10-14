#include "Keeper.h"
#include <iostream>
#include <fstream>
#include "Ship.h"

void Keeper::addShip(Ship* type) {
    linkedList.add(type);
}

void Keeper::printShip() const {
    linkedList.print();
}


void Keeper::clearShip() {

    LNode* current = linkedList.getHead();
    while (current != nullptr) {
        LNode* next = current->next;
        delete current->type;
        delete current;
        current = next;
    }
    linkedList = LinkedList();
}


void Keeper::saveToFile(string filename) {
    LNode* current = linkedList.getHead();

    ofstream file(filename);

    if (file.is_open()) {
        while (current != nullptr) {
            current->type->saveToFile(file);
            current = current->next;
        }
        file.close();
        cout << "Запись в файл." << endl;
    }
    else {
        cout << "Ошибка." << endl;
    }
}


void Keeper::loadFromFile(string filename) {
    int answer = 0;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка" << endl;
        return;
    }

    cout << "Файл открыт" << endl;
    cout << "При загрузке данных из файла, текущие внесенные вами данные будут отчищены. Вы хотите продолжить?\n1 - Да\n2 - Выйти в меню" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "Неверное значение. Попробуйте снова.";
        return;
    }



    clearShip();

    string choise;

    while (file >> choise) {
        Ship* ship = nullptr;

        if (choise == "BOAT")
            ship = new Boat();
        else if (choise == "SAILBOAT")
            ship = new Sailboat();
        else if (choise == "SUBMARINE")
            ship = new Submarine();

        if (ship) {
            ship->loadFromFile(file);
            addShip(ship);
        }

    }

    file.close();
    system("cls");
    cout << "closed" << endl;
}
void Keeper::change() {
    int command = 0;
    string nameBoat, nameSubmarine, nameSailboat;
    LNode* current = linkedList.getHead();
    LNode* prev = nullptr;
    while (command != 4) {
        cout << "Выберите вариант" << endl;
        cout << "Какую лодку хотите изменить?\n1.Boat\n2.Submarine\n3.Sailboat\n4.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "Введите имя катера:";
            cin >> nameBoat;
            while (current != nullptr) {
                Boat* boat = dynamic_cast<Boat*>(current->type);
                if (boat != nullptr && boat->getName() == nameBoat) {
                    boat->change();
                    return;
                }
                prev = current;
                current = current->next;
            }
            break;
        }
        case 2: {
            cout << "Введите имя подводной лодки:";
            cin >> nameSubmarine;
            while (current != nullptr) {
                Submarine* submarine = dynamic_cast<Submarine*>(current->type);
                if (submarine != nullptr && submarine->getName() == nameSubmarine) {
                    submarine->change();
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 3: {
            cout << "Введите название парусника:";
            cin >> nameSailboat;
            while (current != nullptr) {
                Sailboat* sailboat = dynamic_cast<Sailboat*>(current->type);
                if (sailboat != nullptr && sailboat->getName() == nameSailboat) {
                    sailboat->change();
                    return;
                }
                prev = current;
                current = current->next;

            }
            break;
        }
        case 4: {
            break;
        }
        }
    }
}

void Keeper::removeShip() {
    int command = 0;
    string nameBoat, nameSubmarine, nameSailboat;
    LNode* current = linkedList.getHead();
    LNode* prev = nullptr;
    while (command != 4) {
        cout << "Выберите вариант" << endl;
        cout << "Какую лодку хотите изменить?\n1.Boat\n2.Submarine\n3.Sailboat\n4.Вернуться в меню\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "Введите имя катера:";
            cin >> nameBoat;
            while (current != nullptr) {
                Boat* boat = dynamic_cast<Boat*>(current->type);
                if (boat != nullptr && boat->getName() == nameBoat) {
                    if (prev == nullptr) {
                        linkedList.setHead(current->next);
                    }
                    else {
                        prev->next = current->next;
                    }

                    delete current->type;
                    delete current;

                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Лодка с именем " << nameBoat << " была удалена." << endl;
            break;
        }
        case 2: {
            cout << "Введите имя подводной лодки:";
            cin >> nameSubmarine;
            while (current != nullptr) {
                Submarine* submarine = dynamic_cast<Submarine*>(current->type);
                if (submarine != nullptr && submarine->getName() == nameSubmarine) {
                    if (prev == nullptr) {
                        linkedList.setHead(current->next);
                    }
                    else {
                        prev->next = current->next;
                    }

                    delete current->type;
                    delete current;

                    return;
                }
                prev = current;
                current = current->next;

            }
            cout << "Подлодка с именем " << nameBoat << " была удалена." << endl;
            break;
        }
        case 3: {
            cout << "Введите название парусника:";
            cin >> nameSailboat;
            while (current != nullptr) {
                Sailboat* sailboat = dynamic_cast<Sailboat*>(current->type);
                if (sailboat != nullptr && sailboat->getName() == nameSailboat) {
                    if (prev == nullptr) {
                        linkedList.setHead(current->next);
                    }
                    else {
                        prev->next = current->next;
                    }

                    delete current->type;
                    delete current;

                    return;
                }
                prev = current;
                current = current->next;

            }
            cout << "Парусник с именем " << nameBoat << " был удален." << endl;
            break;
        }
        case 4: {
            break;
        }
        }
    }
}
