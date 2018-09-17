#include <iostream>
#include <fstream>
#include "vector.h"

using namespace std;

int* Vector::insert(const int num)
{
  if(!(size < getCapacity())) // calls resize function
    resize();

  array[size] = num; // insert at end of array
  size++;
  return &(array[size - 1]);

} // insert()

int* Vector::erase(int num)
{ 
  int i, j;
  
  for(i = 0; i < size; i++)
  { 
    if(!(array[i] - num)) // check if array is same as num
    { 
      j = i;

      for(; i < size - 1; i++) // shifts all values to the left
        array[i] = array[i + 1];
    
      size--;
      return &(array[j]);
    } // if statement 
  } // for loop
      
  return NULL;
} // erase()

int* Vector::find(const int num)
{
  int i;

  for(i = 0; i < size; i++)
  {
    if (!(array[i] - num)) // checks if arry is the same as num
      return &array[i];   
 
    cout << array [i] << ' '; // print out each value
  } // for loop

  return NULL;

} // find()

int& Vector::operator[](const int index)
{
  int i;

  for(i = 0; i < size; i++)
  {
    if(index < 0 || (size - 1) < index) // check if index beyond size
    {
      cout << "Virtual seg fault.\n";
      return array[ 0 ];
    } // if statement

  } // for loop
  return array[index];

} //operator[]
