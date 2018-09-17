#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H

#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

class SortedVector: public Container 
{
  static const int DOUBLE = 2;

  int capacity;

protected:
  int* array;
  const void resize();

public:
  const int getCapacity() const; 
  SortedVector();
  virtual ~SortedVector();
  virtual int* insert(const int num);
  virtual int* erase(const int num);
  virtual int* find(const int num);
  const int& operator[](const int index) const;

}; // sortedvector

#endif // SORTEDVECTOR_H 
