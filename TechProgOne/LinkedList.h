#pragma once
#include "Ship.h"


struct LNode {
	Ship* type;
	LNode* next;

	LNode(Ship* newType) : type(newType), next(nullptr) {}
};

class LinkedList
{
private:
	LNode* head;
	size_t size;

public:
	LinkedList() : head(nullptr), size(0) {};

	void add(Ship* type);
	void print() const;
	void printType(int type) const;
	LNode* getHead() { return head; }
	void setHead(LNode* newHead) { head = newHead; }
};