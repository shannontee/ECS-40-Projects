#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <fstream>
#include "sortedvector.h"
#include "container.h"

using namespace std;

class Vector: public SortedVector
{
public:
  int* insert(const int num);
  int* erase(const int num);
  int* find(const int num);
  int& operator[](const int index);

}; // vector

#endif // VECTOR_H 
