#pragma once
#include <string>
using namespace std;

struct Node {
	string item;
	Node* next;
};

class List
{
private:
	Node* head;
public:

	List() : head(nullptr) {}

	void addToTail(string item);
	Node& operator[](int index);
	void print(int index);
	Node* getHead() { return head; }
	void setHead(Node* newHead) { head = newHead; }
};