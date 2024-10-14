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
        cout << "������ � ����." << endl;
    }
    else {
        cout << "������." << endl;
    }
}


void Keeper::loadFromFile(string filename) {
    int answer = 0;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "������" << endl;
        return;
    }

    cout << "���� ������" << endl;
    cout << "��� �������� ������ �� �����, ������� ��������� ���� ������ ����� ��������. �� ������ ����������?\n1 - ��\n2 - ����� � ����" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "�������� ��������. ���������� �����.";
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
        cout << "�������� �������" << endl;
        cout << "����� ����� ������ ��������?\n1.Boat\n2.Submarine\n3.Sailboat\n4.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "������� ��� ������:";
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
            cout << "������� ��� ��������� �����:";
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
            cout << "������� �������� ���������:";
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
        cout << "�������� �������" << endl;
        cout << "����� ����� ������ ��������?\n1.Boat\n2.Submarine\n3.Sailboat\n4.��������� � ����\n";
        cin >> command;
        switch (command) {
        case 1: {
            cout << "������� ��� ������:";
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
            cout << "����� � ������ " << nameBoat << " ���� �������." << endl;
            break;
        }
        case 2: {
            cout << "������� ��� ��������� �����:";
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
            cout << "�������� � ������ " << nameBoat << " ���� �������." << endl;
            break;
        }
        case 3: {
            cout << "������� �������� ���������:";
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
            cout << "�������� � ������ " << nameBoat << " ��� ������." << endl;
            break;
        }
        case 4: {
            break;
        }
        }
    }
}
