#pragma once
#include "List.h"
#include <iostream>
template <class T>
class Node
{
private:
   Node *next;
   T data;
public:
   Node();
   Node(T f) : data(f) { }
   ~Node();
   void show();
   std::string toString() const;
   T& getData() { return data; }
   void insertAfter(Node *newNode);
   Node *removeAfter();
   Node *getNext();
};


template <class T>
std::string Node<T>::toString() const {
   ostringstream os;
   os.setf(ios::fixed);
   os.precision(3);
   os << "[" << data << "]";
   return os.str();
}

template <class T>
Node<T>::Node()
{
   next = NULL;
}

template <class T>
Node<T>::~Node()
{
   // nothing to delete
}

template <class T>
void Node<T>::show()
{
   std::cout << "[" << data << "]";
}

template <class T>
void Node<T>::insertAfter(Node<T> *newNode)
{
   if (!newNode)
      return;
   newNode->next = next;
   next = newNode;
}

template <class T>
Node<T> *Node<T>::removeAfter()
{
   Node<T> *temp = next;

   if (temp != NULL)
      next = temp->next;
   return temp;
}

template <class T>
Node<T> *Node<T>::getNext()
{
   return next;
}


