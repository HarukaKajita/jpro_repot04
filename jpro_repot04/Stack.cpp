#pragma once

#include "Stack.h"

void Stack::push(Point s) {
	Node* newHead = new Node(s, head);
	head = newHead;
}

Point Stack::pop() {
	if (head == NULL) {
		cerr << "StackError : error can't pop " << endl;
		exit(EXIT_FAILURE);
	}
	Point ret = head->getData();
	Node* ptr = head->getNext();
	delete head;
	head = ptr;
	return ret;
}