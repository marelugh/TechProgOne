#include "Submarine.h"
#include "Boat.h"
#include "Sailboat.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "Keeper.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Keeper keeper;
    int choice = 0;

    while (choice != 10) {
        cout << "----------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Добавить Подводную Лодку\n2 - Добавить Лодку\n3 - Добавить Парусную Лодку\n";
        cout << "4 - Удалить корабль.\n";
        cout << "5 - Сохранить в файл\n";
        cout << "6 - Загрузить из файла\n";
        cout << "7 - Изменить корабль по имени\n";
        cout << "8 - Вывод всех кораблей\n";
        cout << "9 - Выход\n";
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            getchar(); // Очистка буфера
            Submarine* submarine = new Submarine();
            submarine->input(); // Ввод данных подводной лодки
            keeper.addShip(submarine); // Добавление подводной лодки в список
            system("cls");
            break;
        }
        case 2: {
            system("cls");
            Boat* boat = new Boat();
            boat->input(); // Ввод данных лодки
            keeper.addShip(boat); // Добавление лодки в список
            system("cls");
            break;
        }
        case 3: {
            system("cls");
            Sailboat* sailboat = new Sailboat();
            sailboat->input(); // Ввод данных парусной лодки
            keeper.addShip(sailboat); // Добавление парусной лодки в список
            system("cls");
            break;
        }
        case 4: {
            // Удаление последнего корабля
            system("cls");
            keeper.removeShip();
            system("pause");
            system("cls");
            break;
        }
        case 5: {
            // Сохранение текущего списка кораблей в файл
            system("cls");
            string filename;
            cout << "Введите желаемое название файла: ";
            cin >> filename;
            system("cls");
            keeper.saveToFile(filename); // Вызов функции сохранения в Keeper
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            // Загрузка списка кораблей из файла
            system("cls");
            string filename;
            cout << "Введите название файла: ";
            cin >> filename;
            system("cls");
            keeper.loadFromFile(filename); // Вызов функции загрузки в Keeper
            system("pause");
            system("cls");
            break;
        }
        case 7: {
            system("cls");
            keeper.change();
            system("pause");
            system("cls");
            break;
        }
        case 8: {
            system("cls");
            keeper.printShip();
            system("pause");
            system("cls");
            break;
        }
        case 9:
            // Завершение программы
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    }

    keeper.clearShip(); // Очистка списка перед завершением программы

    return 0;
}
