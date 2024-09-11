#include "menu.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper keeper;  // Создаем объект Keeper
    displayMenu(keeper);  // Отображаем меню и обрабатываем пользовательский ввод
    return 0;
}
