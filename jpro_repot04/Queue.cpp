#pragma once

#include "Queue.h"

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