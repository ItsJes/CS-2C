// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class T>
class Node {
   friend class List;
private:
   Node* next;
   T data;
public:
   Node();
   void insertAfter(Node *newNode);
   Node* getNext() { return next; }
};

template <class T>
class Linked

template <class T>
class List {

   

private:
   Node<T>* head;
   Node<T>* tail;
public:
   //Node* begin();

};


int main()
{
    return 0;
}

