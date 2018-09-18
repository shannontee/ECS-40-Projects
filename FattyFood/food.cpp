#include "food.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream& operator>> (ifstream& inf, Food& foo)
{
  
  inf >> foo.calories >> foo.fiber >> foo.name;
  return inf;
}

void Food::print()
{
  cout << calories << ' ' << fiber << ' ' << name << endl;

}

Food::Food(int calories, int fiber, string name)
{
  calories = 0;
  fiber = 0;
  name = '\0';
  
}
