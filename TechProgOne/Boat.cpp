#include "Boat.h"
#include <iostream>
using namespace std;

// ����������� �� ���������
Boat::Boat() : boatName(""), purpose(""), material(""), speed(0), amountOfPeople(0) {
    cout << "����������� �� ��������� Boat ������!\n";
}

// ����������� � �����������
Boat::Boat(string purpose, string material, int speed, int amountOfPeople, string quality, string boatName)
    : purpose(purpose), material(material), speed(speed), amountOfPeople(amountOfPeople), boatName(boatName) {
    qualities.addToTail(quality);
    cout << "����������� � ����������� Boat ������!\n";
}

// ����������� �����������
Boat::Boat(const Boat& other)
    : purpose(other.purpose), material(other.material), speed(other.speed), amountOfPeople(other.amountOfPeople), qualities(other.qualities), boatName(other.boatName) {
    cout << "����������� ����������� Boat ������!\n";
}

// ����������
Boat::~Boat() {
    cout << "���������� Boat ������!\n";
}

// ������� � �������
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

// ������ �������������� � �������������
void Boat::input() {
    cout << "������� �������� �����: ";
    string boatName;
    cin.ignore();
    getline(cin, boatName);
    setName(boatName);

    cout << "������� ���������� �����: ";
    string purpose;
    cin.ignore();
    getline(cin, purpose);
    setPurpose(purpose);

    cout << "������� �������� �����: ";
    string material;
    getline(cin, material);
    setMaterial(material);

    cout << "������� �������� �����: ";
    int speed;
    cin >> speed;
    setSpeed(speed);

    string quality;
    while (true) {
        cout << "������� �������� ����� (��� 'q' ��� ����������): ";
        cin >> quality;
        if (quality == "q" || quality == "Q") {
            break;
        }
        setQualities(quality);
    }

    cout << "������� ���������� ����� �� �����: ";
    int amountOfPeople;
    cin >> amountOfPeople;
    setAmountOfPeople(amountOfPeople);
}

void Boat::print() {
    cout << "Boat\n";
    cout << "��������: " << getName() << endl;
    cout << "����������: " << getPurpose() << endl;
    cout << "��������: " << getMaterial() << endl;
    cout << "��������: " << getSpeed() << " �����" << endl;
    cout << "���������� �����: " << getAmountOfPeople() << endl;

    List qualities = getQualities();
    Node* current = qualities.getHead();
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". ��������: " << current->item << endl;
        current = current->next;
    }
    cout << '\n';
}

void Boat::saveToFile(ofstream& file) {
    file << "BOAT" << endl;
    file << "��������:" << getName() << endl;
    file << "����������:" << getPurpose() << endl;
    file << "��������:" << getMaterial() << endl;
    file << "��������:" << getSpeed() << endl;
    file << "���������� �����:" << getAmountOfPeople() << endl;

    List qualities = getQualities();
    Node* current = qualities.getHead();
    int i = 1;
    while (current != nullptr) {
        file << i++ << ". ��������:" << current->item << endl;
        current = current->next;
    }
    file << endl;
}

void Boat::loadFromFile(ifstream& file) {
    string line;

    getline(file, line);  // ���������� ��������� "BOAT"

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
        size_t pos = line.find("��������:");
        if (pos != string::npos) {
            string quality = line.substr(pos + 9);
            setQualities(quality);
        }
    }
}


void Boat::change() {
    int command = 0;

    while (command != 9) {
        cout << "��������, ����� �������� �� ������ ��������\n"
            << "1. ����������\n2. ��������\n3. ��������\n4. ���������� �������\n5. ��������\n6. ��������\n7. �������� ����� ��������\n8.�������� ��������\n9. �����\n";
        cin >> command;
        switch (command) {
        case 1: {
            string purpose;
            system("cls");
            cout << "������� ����� ���������� �����\nPurpose: ";
            cin >> purpose;
            setPurpose(purpose);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 2: {
            string material;
            system("cls");
            cout << "������� ����� ��������\nMaterial: ";
            cin >> material;
            setMaterial(material);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            int speed;
            system("cls");
            cout << "������� ����� ��������\nSpeed: ";
            cin >> speed;
            setSpeed(speed);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            int amountOfPeople;
            system("cls");
            cout << "������� ����� ����� �������\nAmount of people: ";
            cin >> amountOfPeople;
            setAmountOfPeople(amountOfPeople);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            string boatName;
            system("cls");
            cout << "������� ����� ��������\nName: ";
            cin >> boatName;
            setName(boatName);
            cout << "�������!";
            system("pause");
            system("cls");
            break;
        }
        case 6: { // ��������� �������� ������ "qualities"
            List qualities = getQualities();
            Node* current = qualities.getHead();

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

            cout << "������� ����� ��������, ������� ������ ��������: ";
            int qualityIndex;
            cin >> qualityIndex;
            qualityIndex--; // �������� � ������� �������

            if (qualityIndex < 0 || qualityIndex >= index) {
                cout << "�������� ������ ��������!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "������� ����� ��������: ";
            string newQuality;
            cin.ignore();
            getline(cin, newQuality);

            qualities[qualityIndex].item = newQuality;
            cout << "�������� ������� ��������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 7: { // ���������� ������ �������� � ������
            string newQuality;
            cout << "������� ����� �������� �����: ";
            cin.ignore();
            getline(cin, newQuality);
            qualities.addToTail(newQuality);  // ��������� ����� �������� � ����� ������
            cout << "����� �������� ������� ���������!\n";
            system("pause");
            system("cls");
            break;
        }
        case 8: { // ��������� �������� ������ "qualities"
            List qualities = getQualities();
            Node* current = qualities.getHead();

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

            cout << "������� ����� ��������, ������� ������ ��������: ";
            int qualityIndex;
            cin >> qualityIndex;
            qualityIndex--; // �������� � ������� �������

            if (qualityIndex < 0 || qualityIndex >= index) {
                cout << "�������� ������ ��������!\n";
                system("pause");
                system("cls");
                break;
            }

            cout << "������� ����� ��������: ";
            string newQuality;
            cin.ignore();
            getline(cin, newQuality);

            qualities[qualityIndex].item = newQuality;
            cout << "�������� ������� ��������!\n";
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

