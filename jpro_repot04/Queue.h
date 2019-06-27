#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

#include "Node.h"

class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() { front = rear = NULL; }
	~Queue();
	void enqueue(Point);
	Point dequeue();
	bool isEmpty();
};
