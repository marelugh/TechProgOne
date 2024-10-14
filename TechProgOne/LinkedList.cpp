#include "LinkedList.h"
#include <iostream>
#include "Submarine.h"
#include "Sailboat.h"
#include "Boat.h"

using namespace std;



void LinkedList::add(Ship* type) {
    LNode* newNode = new LNode{ type };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        LNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void LinkedList::print() const {
    LNode* current = head;
    while (current != nullptr) {
        current->type->print();
        current = current->next;
    }
}


void LinkedList::printType(int type) const {
    LNode* current = head;
    while (current != nullptr) {

        if (dynamic_cast<Submarine*>(current->type) && type == 1) {

            current->type->print();

        }
        else if (dynamic_cast<Sailboat*>(current->type) && type == 2) {

            current->type->print();

        }
        else if (dynamic_cast<Boat*>(current->type) && type == 3) {

            current->type->print();

        }
        current = current->next;
    }
}