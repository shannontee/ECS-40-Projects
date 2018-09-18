#ifndef FATTYFOOD_H
#define FATTYFOOD_H

#include "food.h"

using namespace std;

class FattyFood: public Food
{
  float Saturated_Fat;

public:
  FattyFood();
  void print();
  friend ifstream& operator>> (ifstream& inf, FattyFood& fatfoo);
};

#endif
