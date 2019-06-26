#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#include "Node.cpp"

class Stack{
private:
  Node* head;
	
public:
  Stack(){head = NULL;}
  ~Stack(){while(!isEmpty())pop();}
  void push(string);
  string pop();
  bool isEmpty(){return head == NULL;}	
};

void Stack::push(string s){
  Node* newHead = new Node(s, head);
  head = newHead;
}

Point Stack::pop(){
  if(head == NULL){
    cerr << "StackError : error can't pop " << endl;
	exit(EXIT_FAILURE);
  }
  Point ret = head->getData();
  Node* ptr = head->getNext();
  delete head;
  head = ptr;
  return ret;
}