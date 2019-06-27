#pragma once
#include "Node.h"

class Stack {
private:
	Node* head;

public:
	Stack() { head = NULL; }
	~Stack() { while (!isEmpty())pop(); }
	void push(Point);
	Point pop();
	bool isEmpty() { return head == NULL; }
};