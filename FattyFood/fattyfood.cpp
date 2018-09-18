#include <iostream>
#include <fstream>
#include "fattyfood.h"

using namespace std;

FattyFood::FattyFood()
{

}

ifstream& operator>> (ifstream& inf, FattyFood& fatfoo)
{
  
  inf >> fatfoo.calories >> fatfoo.fiber >> fatfoo.Saturated_Fat >> fatfoo.name;
  return inf;
}

void FattyFood::print()
{
  cout << calories << ' ' << fiber << ' ' << Saturated_Fat << ' ' << name << endl;
}

