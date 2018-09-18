
#include "linkedlist.h"


ListNode::ListNode()
{
} // ListNode()

LinkedList::~LinkedList()
{
  ListNode *ptr;

   for (ptr = head; head; ptr = head)
   {
     head = head->next;
     delete ptr;
   } // for loop

} // ~LinkedList()

ostream & operator<<(ostream &out, const LinkedList & ll)
{
  ListNode *tmp;

  for(tmp = ll.head; tmp; tmp = tmp->next)
  {
    if(tmp->offset != LinkedList::EMPTY)
      out << 'X';
    else  // empty seat
      out << '-';
  } // for loop

  return out;
} // operator<<

void LinkedList::initialize(int numSeats)
{
  ListNode *tmp;
  head = NULL;

  for(int i = 0; i < numSeats; ++i)
  {
    tmp = new ListNode;
    tmp->offset = EMPTY;
    tmp->next = head;
    head = tmp;
  } // for loop

} // operator <<

//assume seat < length of linked list
const int & LinkedList::operator[]( int seat) const
{
  int i;
  ListNode *tmp;

  for(i = 0, tmp = head; i < seat; ++i) 
  {
    tmp = tmp->next;
  } // for loop

  //tmp points to LinkedList[seat]
  return tmp->offset;
} // operator[]


int & LinkedList::operator[]( int seat)
{
  int i;
  ListNode *tmp;

  for(i = 0, tmp = head; i < seat; ++i) 
  {
    tmp = tmp->next;
  } //for loop

  //tmp points to LinkedList[seat]
  return (tmp->offset);
} // operator []
