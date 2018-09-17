#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

const int Container::getSize() const
{
  return size;
} // getSize()

Container::Container(int siz)
{
  size = siz;
} // Container()

Container::~Container()
{
} // ~Container()



