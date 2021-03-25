#pragma once

#include "Node.h"
#include <iostream>

template <class T>
class List {
private:
   Node<T> *head;
   Node<T> *tail;

public:
   class iterator;
   List();
   ~List();
   void showList();
   void insert(iterator it, T x);
   bool remove(iterator it);
   iterator& begin() { return iterator(head); }
   iterator& end() { return iterator(tail); }

};

template <class T>
class List<T>::iterator {
   friend class List<T>;
private:
   Node<T>* pos;
public:
   iterator(Node<T>* p) : pos(p) {}
   iterator& operator++() { if(pos!=NULL) pos = pos->getNext(); return *this; }
   T& operator*() { return pos->getData(); }
   bool operator==(const iterator& it) { return pos == it.pos; }
   bool operator!=(const iterator& it) { return pos != it.pos;  }
};





template <class T>
void List<T>::insert(iterator it, T x)
{
   Node<T>* n = new Node<T>(x);
   it.pos->insertAfter(n);
   tail = n;
   /*
   Node<T> *fp;
   Node<T> *newfp = new Node<T>(x);

   for (iterator it = begin(); it != end(); it++)
   {
      if (getNext() == NULL)
         break;
      fp = (Node<T>*)(getNext());
      if (x <= fp->getData())
         break;
   }
   getCurrent()->insertAfter(newfp);
   */
}

template <class T>
bool List<T>::remove(iterator it)
{
   
   /*
   Node<T> *fp;

   // always stay one node behind the node you are testing
   for (resetCurrent(); getCurrent(); iterate())
   {
      if (getNext() == NULL)
         return false; // end of list and not found

                       // if f == current then we found match
      fp = (Node<T>*)(getNext());
      if (f == fp->getData())
      {
         Node<T> *doneWithNode = getCurrent()->removeAfter();
         delete doneWithNode;
         return true;   // we found, we removed, we return
      }
   }
   */
}

template <class T>
List<T>::List()
{
   // an empty list will have one "header" node at the front
   head = new Node<T>(T());
   tail = NULL;
}

template <class T>
List<T>::~List()
{
   // list nodes do not belong to the list class - they belong to the client
   // therefore we cannot delete them in the destructor.

   // but we are responsible for the header node which we created
   delete head;
}

template <class T>
void List<T>::showList()
{
   for (iterator it = begin(); it != end(); ++it)
   {
      if (it.pos != NULL)
      {
         std::cout << *it;
         std::cout << " ";
      }
      else
         break;
   }
}
/*
template <class T>
Node<T> *List<T>::getCurrent()
{
   return current;
}

template <class T>
Node<T> *List<T>::getNext()
{
   if (current == NULL)
      return NULL;  // if used correctly, never happens
   return current->getNext();
}

template <class T>
void List<T>::resetCurrent()
{
   current = head;
}

template <class T>
Node<T> *List<T>::iterate()
{
   if (current)
      current = current->getNext();
   return current;
}

template <class T>
void List<T>::insertAfterHead(Node<T> *np)
{
   head->insertAfter(np);
}

template <class T>
Node <T>* List<T>::removeAfterHead()  // ---------------
{
   return head->removeAfter();
}
*/
