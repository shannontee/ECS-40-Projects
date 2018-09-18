#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Food
{

protected:
  char Food_type;
  int calories;
  int fiber;
  string name;


 // friend ifstream& operator>> (ifstream& inf, Food& foo);

public:
  Food(int calories, int fiber, string name);
  virtual void print();
  friend ifstream& operator>> (ifstream& inf, Food& foo);
};

#endif 
