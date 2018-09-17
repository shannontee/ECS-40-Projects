#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <fstream>

using namespace std;

class Container
{
protected:
  int size;

public:
  Container(int siz);
  const int getSize() const;
  virtual ~Container();
  virtual int* insert(const int num) = 0;
  virtual int* erase(const int num) = 0;
  virtual int* find(const int num) = 0;

}; // Container

#endif // CONTAINER_H
