#include <iostream>
#include <fstream>
#include "sortedvector.h"

using namespace std;

const int SortedVector::getCapacity() const
{
  return capacity;
} // getCapacity()

int* SortedVector::insert(const int num)
{
  int i;

  if(!(size < capacity)) // calls resize function
    resize(); 
  
  for(i = size - 1; (!(i < 0)) && array[i] > num; i--) // locate position
    array[i + 1] = array[i];

  array[i + 1] = num; // insert into position
  size++; 
  return &(array[i + 1]);
 
} // insert()

const void SortedVector::resize()
{
  int i;
  
  if(!(capacity > 0 || capacity < 0)) // capacity is zero
  {
    capacity = 1;
    array = new int[capacity]; // allocate array for one 
  } // if statement

  else // else statement
  {
    int* temp = array;
    array = new int[DOUBLE * capacity]; // double capacity
   
    for(i = 0; i < size; i++) // copy values
      array[i] = temp[i];

    delete [] temp;
    capacity = DOUBLE * capacity;
    } // else statement

} // resize()

int* SortedVector::erase(const int num)
{
  int i, j;

  for(i = 0; i < size; i++)
  {
    if(!(array[i] < num)) // determines location before greater
      break;
  } // for loop

  if(!(array[i] - num)) // check if numbers equal
  {
    j = i; 

    for(; i < size - 1; i++)  // shifts all values left
      array[i] = array[i + 1];
  
    size--;
    return &(array[j]);
  } // if statement 
      
  return NULL;
} // erase()

int* SortedVector::find(const int num)
{
  int i;

  for(i = 0; i < size; i++)
  {
    if(!(array[i] < num)) // determines location of before greater
      break;
    cout << array [i] << ' ';  // print out each value
  } // for loop
 
  if(!(array[i] - num)) // compares if equal
    return &array[i];
  
  return NULL;
  
} // find()

SortedVector::SortedVector():Container( 0 )
{
  capacity = 0;
  array = NULL;
} // sortedvector()

SortedVector::~SortedVector()
{
  delete [] array;
} // ~SortedVector()

const int& SortedVector::operator[](const int index) const
{
  int i;

  for (i = 0; i < size; i++)
  {
    if(index < 0 || (size - 1) < index) // check if index outside of size
    {
      cout << "Virtual seg fault.\n";
      return array[ 0 ]; 
    } // if statement

  } // for loop
  return array[index];

} //operator[]
