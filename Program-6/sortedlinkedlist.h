#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <iostream>
#include <fstream>
#include "container.h"
#include "linkedlist.h"

using namespace std;

class SortedLinkedList: public LinkedList
{
public:
  int* insert(const int num);
  int* erase(const int num);
  int* find(const int num);

}; // SortedLinkedList 

#endif //SORTEDLINKEDLIST_H
