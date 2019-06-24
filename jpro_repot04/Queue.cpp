#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//#define _DEBUG

//Point
class Point{
private:
  int x, y;
public:
  Point(int _x = -1, int _y = -1){
    x = _x;
    y = _y;
  }
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
  
};

ostream& operator<<(ostream& stream, Point p){
  stream << "(" << p.getX() << ", " << p.getY() << ")";
  return stream;
}

//Node
class Node{
private:
  Point data;
  Node* next;
public:
  Node(Point p, Node* n){
    data = p;
    next = n;
  }
  //accessor
  Node* getNext(){return next;}
  void setNext(Node* np){next = np;}
  Point getData(){return data;}
};

class Queue{
private:
  Node* front;
  Node* rear;

public:
  Queue(){front = rear = NULL;}
  ~Queue();
  void enqueue(Point);
  Point dequeue();
  bool isEmpty();
};
//destructor
//member functions

void Queue::enqueue(Point p){
  //新しいノードを作成
  //リアに追加し、リアを更新
  Node* newNode = new Node(p, NULL);
  bool emptyFlag = isEmpty();
  if(emptyFlag)front = newNode;
  if(!emptyFlag)rear->setNext(newNode);
  rear = newNode;
  #ifdef _DEBUG
  cout << "enqueue : " << newNode << " next : " << newNode->getNext() << endl;
  #endif
}

Point Queue::dequeue(){
  //先頭からデータを吐き出し
  //ノードを削除
  //先頭を更新
  if(isEmpty()){
    cerr << "Error : front is NULL. can't dequeu" << endl;
    exit(EXIT_FAILURE);
  }
  Point data = front->getData();
  Node* tmp = front;
  front = front->getNext();
  #ifdef _DEBUG
  cout << "dequeue : " << tmp << endl;
  cout << "front   : " << front << endl;
  #endif
  delete tmp;
  return data;
}

bool Queue::isEmpty(){
  return front == NULL;
}

Queue::~Queue(){
  while(!isEmpty())
    dequeue();
}