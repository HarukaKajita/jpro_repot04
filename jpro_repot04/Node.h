#pragma once
#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int _x = -1, int _y = -1) {
		x = _x;
		y = _y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}

};

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