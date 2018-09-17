#include <iostream>
#include <fstream>
#include "linkedlist.h"

using namespace std;

ListNode::ListNode(const int dat, ListNode* p, ListNode* n)
{
  data = dat;
  previous = p;
  next = n;
} // ListNode 

LinkedList::~LinkedList()
{
  ListNode *ptr;

  for(ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }  // for loop

} // ~LinkedList()


LinkedList::LinkedList():Container( 0 ) 
{
  head = NULL; // initializes all to NULL
  tail = NULL;
  curr = NULL;
} // LinkedList()


int* LinkedList::insert(const int num)
{

  if(!head) // insert at front
  {
    head = new ListNode (num, head, tail); // new node
    curr = head; // curr and tail equal head
    tail = head;
  } // if statement

  else // insert at end
  {
    tail->next = new ListNode(num, NULL, NULL); // new node
    tail->next->previous = tail; // prev pointer to tail
    tail = tail->next; 
    curr = tail; // set current to tail
   } // else statement
 
  size++; 
  return &(curr->data);
 
} // insert()


int* LinkedList::erase(const int num)
{
  ListNode* ptr;
  ListNode* prev = NULL;
 
  for(ptr = head; ptr && (ptr->data - num); ptr = ptr->next)
    prev = ptr;  // looks for where data equals num

  if(ptr)
  {
    if(!prev) // at front
    {
      head = ptr->next;

      if(ptr->next)
        ptr->next->previous = NULL;
    } // if statement

    else // at  middle
    {
      prev->next = ptr->next;
   
      if(ptr->next)
        ptr->next->previous = prev;
    } // if statement
  
    size--;
    curr = ptr->next;
    delete ptr;  
    return &(curr->data);
  } // if statement

  else // else statement
    return NULL;
} // erase()

int* LinkedList::find(const int num)
{
  ListNode* ptr;

  for(ptr = head; ptr && (ptr->data -  num); ptr = ptr->next)
    cout << ptr->data << ' ';  // search where data equal num

   if(ptr) // if equal set location to current
   {
    curr = ptr;  
    return &(curr->data);
   } // if statement

   else // else statement
    return NULL;

} // find()

int* LinkedList::operator++()
{
  if(!curr) // return NULL if curr NULL
    return NULL;

  curr = curr->next; // move curr forward
  return &(curr->data);
} // operator++

int* LinkedList::operator--()
{
  if(!curr)
    return NULL;

  curr = curr->previous; // move curr backward
  return &(curr->data);
} // operator--

