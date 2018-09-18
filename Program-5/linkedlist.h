#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <fstream>
#include <iostream>

using namespace std;

class LinkedList;

class ListNode
{
private:
  ListNode *next;
  ListNode();
  friend class LinkedList;
  friend ostream & operator<<(ostream &out, const LinkedList & ll);
  int offset;
}; // ListNode

class LinkedList
{
  ListNode *head;
public:
  static const int EMPTY = -1;
  ~LinkedList();
  void initialize(int numSeats);
  const int& operator[](int i) const;
  int & operator[](int i);
  friend ostream & operator<<(ostream &out, const LinkedList & ll);
}; //LinkedList

ostream & operator<<(ostream &out, const LinkedList & ll);


#endif // LINKEDLIST_H
