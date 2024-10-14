#include "List.h"
#include <iostream>

void List::addToTail(string item) {
    Node* newNode = new Node{ item, nullptr };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}


Node& List::operator[](int index) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == index) {
            return *current;
        }
        current = current->next;
        count++;
    }
}

void List::print(int index) {
    Node& node = (*this)[index];
    cout << "Item: " << node.item << endl;
}
