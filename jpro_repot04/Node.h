#pragma once
#include <iostream>
using namespace std;

#include "Point.h"

//Node
class Node {
private:
	Point data;
	Node* next;
public:
	Node(Point p, Node* n) {
		data = p;
		next = n;
	}
	//accessor
	Node* getNext() { return next; }
	void setNext(Node* np) { next = np; }
	Point getData() { return data; }
};
