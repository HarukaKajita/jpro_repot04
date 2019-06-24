#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

class Node{
private:
  string str;
  Node* next;
public:
  Node(string s, Node* n){
    str = s;
    next = n;
  }
  friend class Stack;
};

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

string Stack::pop(){
  if(head == NULL){
    cerr << "StackError : error can't pop " << endl;
	exit(EXIT_FAILURE);
  }
  string ret = head->str;
  Node* ptr = head->next;
  delete head;
  head = ptr;
  return ret;
}