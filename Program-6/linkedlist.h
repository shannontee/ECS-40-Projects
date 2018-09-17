#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

class ListNode
{
  int data;
  ListNode* previous;
  ListNode* next;
  ListNode (const int dat, ListNode *p, ListNode *d);

  friend class LinkedList;
  friend class SortedLinkedList;

}; // ListNode


class LinkedList: public Container
{

protected:
  ListNode* head;
  ListNode* tail;
  ListNode* curr;

public: 
  LinkedList();
  virtual ~LinkedList();
  virtual int* insert(const int num);
  virtual int* erase(const int num);
  virtual int* find(const int num);
  int* operator++();
  int* operator--();

}; // LinkedList 

#endif //LINKEDLIST_H
