#include <iostream>
#include <fstream>
#include "sortedlinkedlist.h"

using namespace std;

int* SortedLinkedList::insert(const int num)
{
  ListNode* ptr;
  ListNode* prev = NULL;

  for(ptr = head; ptr && ptr->data < num; ptr = ptr->next)
    prev = ptr; // search where data less than num

  if(!prev) // insert front
  {
    head = new ListNode(num, NULL, ptr); // new node
    curr = head; // set curr and tail to head
    tail = head;

    if(ptr)
      ptr->previous = head; 
  } // if statement

  else // insert middle
  {
    prev->next = new ListNode(num, prev, ptr); // new node
    
    if(ptr)
      ptr->previous = prev->next;
    curr = prev->next;  // set new location to current
  } // else statement

  size++;
  return &(curr->data);

} // insert()

int* SortedLinkedList::erase(const int num)
{
  ListNode* ptr;
  ListNode* prev = NULL;

  for(ptr = head; ptr && ptr->data < num; ptr = ptr->next)
    prev = ptr; // check where data less than num

  if(ptr && !(ptr->data - num)) 
  {
    if(!prev) // erase front
    {
      head = ptr->next; // change head pointer

      if(ptr->next) 
        ptr->next->previous = NULL;
    } // if statement

    else // erase middle
    {
      prev->next = ptr->next; // change next pointer

      if(ptr->next)
        ptr->next->previous = prev;
    } // if statement

    size--;
    curr = ptr->next; // set new location to current
    delete ptr;
    return &(curr->data);
  } // if statement

  return NULL;
} // erase()

int* SortedLinkedList::find(const int num)
{
  ListNode* ptr;

  for(ptr = head; ptr && ptr->data < num; ptr = ptr->next)
    cout << ptr->data << ' '; 

  if(ptr && !(ptr->data-num)) // data equals num
  {
    curr = ptr; // set location to current
    return &(curr->data);
  } // if statement

  else // else statement
    return NULL;

} // find()

